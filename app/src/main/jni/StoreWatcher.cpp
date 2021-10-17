//
// Created by max on 2/27/18.
//

#include <string.h>
#include "StoreWatcher.h"
#include "store_support.h"
#include <unistd.h>

void startWatcher(JNIEnv* pEnv, StoreWatcher* pWatcher, Store* pStore, jobject pStoreFront) {
    // Очистить структуру StoreWatcher.
    memset(pWatcher, 0, sizeof(StoreWatcher));
    pWatcher->mState = STATE_OK;
    pWatcher->mStore = pStore;
    // Сохранить в кэше ссылки на VM.
    if (pEnv->GetJavaVM(&pWatcher->mJavaVM) != JNI_OK) {
        stopWatcher(pEnv, pWatcher);
        return;
    }
    // Сохранить в кэше объекты.
    pWatcher->mLock = pEnv->NewGlobalRef(pStoreFront);
    if (pWatcher->mLock == NULL) {
        stopWatcher(pEnv, pWatcher);
        return;
    }
    // Инициализировать и запустить низкоуровневый поток выполнения.
    // Для простоты появление ошибок не проверяется (но в действующих
    // приложениях такая проверка обязательно должна выполняться...).
    pthread_attr_t lAttributes;
    int lError = pthread_attr_init(&lAttributes);
    if (lError) {
        stopWatcher(pEnv, pWatcher);
        return;
    }
    lError = pthread_create(&pWatcher->mThread, &lAttributes, runWatcher, pWatcher);
    if (lError) {
        stopWatcher(pEnv, pWatcher);
        return;
    }
    // Сохранить ссылки на классы.
    pWatcher->ClassStore = pEnv->FindClass("com/mdgd/storeapp/model/storage/Store");
    makeGlobalRef(pEnv, (jobject *) &pWatcher->ClassStore);
    if (pWatcher->ClassStore == NULL) {
        stopWatcher(pEnv, pWatcher);
        return;
    }
    pWatcher->ClassColor = pEnv->FindClass("com/mdgd/storeapp/model/storage/Color");
    makeGlobalRef(pEnv, (jobject *) &pWatcher->ClassColor);
    if (pWatcher->ClassColor == NULL) {
        stopWatcher(pEnv, pWatcher);
        return;
    }
    // Сохранить ссылки на Java-методы.
    pWatcher->MethodOnAlertInt = &(*pEnv->GetMethodID(pWatcher->ClassStore, "onAlert", "(I)V"));
    if (pWatcher->MethodOnAlertInt == NULL) {
        stopWatcher(pEnv, pWatcher);
        return;
    }
    pWatcher->MethodOnAlertString = &(*pEnv->GetMethodID(pWatcher->ClassStore, "onAlert",
                                                         "(Ljava/lang/String;)V"));
    if (pWatcher->MethodOnAlertString == NULL) {
        stopWatcher(pEnv, pWatcher);
        return;
    }
    pWatcher->MethodOnAlertColor = &(*pEnv->GetMethodID(pWatcher->ClassStore, "onAlert",
                                                        "(Lcom/mdgd/storeapp/model/storage/Color;)V"));
    if (pWatcher->MethodOnAlertColor == NULL) {
        stopWatcher(pEnv, pWatcher);
        return;
    }
    pWatcher->MethodColorEquals = &(*pEnv->GetMethodID(pWatcher->ClassColor, "equals",
                                                       "(Ljava/lang/Object;)Z"));
    if (pWatcher->MethodColorEquals == NULL) {
        stopWatcher(pEnv, pWatcher);
        return;
    }
    const jmethodID ConstructorColor = &(*pEnv->GetMethodID(pWatcher->ClassColor, "<init>",
                                                            "(Ljava/lang/String;)V"));
    if (ConstructorColor == NULL) {
        stopWatcher(pEnv, pWatcher);
        return;
    }
    // Создать новый объект, описывающий белый цвет, и сохранить глобальную ссылку.
    jstring lColor = &(*pEnv->NewStringUTF("white"));
    if (lColor == NULL) {
        stopWatcher(pEnv, pWatcher);
        return;
    }
    pWatcher->mColor = &(*pEnv->NewObject(pWatcher->ClassColor, ConstructorColor, lColor));
    makeGlobalRef(pEnv, &pWatcher->mColor);
    if (pWatcher->mColor == NULL) {
        stopWatcher(pEnv, pWatcher);
        return;
    }
}

JNIEnv* getJNIEnv(JavaVM* pJavaVM) {
    JavaVMAttachArgs lJavaVMAttachArgs;
    lJavaVMAttachArgs.version = JNI_VERSION_1_6;
    lJavaVMAttachArgs.name = "NativeThread";
    lJavaVMAttachArgs.group = NULL;
    JNIEnv* lEnv;
    if (pJavaVM->AttachCurrentThread(&lEnv, &lJavaVMAttachArgs) != JNI_OK) {
        lEnv = NULL;
    }
    return lEnv;
}

void* runWatcher(void* pArgs) {
    StoreWatcher *lWatcher = (StoreWatcher *) pArgs;
    JavaVM *lJavaVM = lWatcher->mJavaVM;
    JNIEnv *lEnv = getJNIEnv(lJavaVM);
    if (lEnv == NULL) {
        lJavaVM->DetachCurrentThread();
        pthread_exit(NULL);
    }
    int32_t lRunning = 1;
    while (lRunning) {
        usleep(SLEEP_DURATION * 1000000); // microseconds
        StoreEntry *lEntry = lWatcher->mStore->mEntries;
        const StoreEntry *lEntryEnd = lEntry + lWatcher->mStore->mLength;
        int32_t lScanning = 1;
        while (lScanning) {
            // Начало критической секции может выполняться только в одном потоке.
            // Здесь записи не могут добавляться или изменяться.
            lEnv->MonitorEnter(lWatcher->mLock);
            lRunning = (lWatcher->mState == STATE_OK);
            lScanning = (lEntry < lEntryEnd);
            if (lRunning && lScanning) {
                processEntry(lEnv, lWatcher, lEntry);
            }
            // Конец критической секции.
            lEnv->MonitorExit(lWatcher->mLock);
            // Перейти к следующей записи.
            lEntry++;
        }
    }
    lJavaVM->DetachCurrentThread();
    pthread_exit(NULL);
}

void processEntry(JNIEnv* pEnv, StoreWatcher* pWatcher, StoreEntry* pEntry) {
    switch (pEntry->mType) {
        case StoreType_Integer: {
            processEntryInt(pEnv, pWatcher, pEntry);
        }
            break;

        case StoreType_String: {
            processEntryString(pEnv, pWatcher, pEntry);
        }
            break;

        case StoreType_Color: {
            processEntryColor(pEnv, pWatcher, pEntry);
        }break;
    }
}

void processEntryInt(JNIEnv* pEnv, StoreWatcher* pWatcher, StoreEntry* pEntry) {
    if (strcmp(pEntry->mKey, "watcherCounter") == 0) {
        ++pEntry->mValue.mInteger;
    } else if ((pEntry->mValue.mInteger > 1000) || (pEntry->mValue.mInteger < -1000)) {
        pEnv->CallVoidMethod(
                pWatcher->mLock, pWatcher->MethodOnAlertInt, (jint) pEntry->mValue.mInteger
        );
    }
}

void processEntryString(JNIEnv* pEnv, StoreWatcher* pWatcher, StoreEntry* pEntry) {
    if (strcmp(pEntry->mValue.mString, "apple") == 0) {
        jstring lValue = pEnv->NewStringUTF(pEntry->mValue.mString);
        pEnv->CallVoidMethod(pWatcher->mLock, pWatcher->MethodOnAlertString, lValue);
        pEnv->DeleteLocalRef(lValue);
    }
}

void processEntryColor(JNIEnv* pEnv, StoreWatcher* pWatcher, StoreEntry* pEntry) {
    jboolean lResult = pEnv->CallBooleanMethod(
            pWatcher->mColor, pWatcher->MethodColorEquals, pEntry->mValue.mColor
    );
    if (lResult) {
        pEnv->CallVoidMethod(
                pWatcher->mLock, pWatcher->MethodOnAlertColor, pEntry->mValue.mColor
        );
    }
}

void deleteGlobalRef(JNIEnv* pEnv, jobject* pRef) {
    if (*pRef != NULL) {
        pEnv->DeleteGlobalRef(*pRef);
        *pRef = NULL;
    }
}

void stopWatcher(JNIEnv* pEnv, StoreWatcher* pWatcher) {
    if (pWatcher->mState == STATE_OK) {
        // Ждать завершения фонового потока выполнения.
        pEnv->MonitorEnter(pWatcher->mLock);
        pWatcher->mState = STATE_KO;
        pEnv->MonitorExit(pWatcher->mLock);
        pthread_join(pWatcher->mThread, NULL);
        deleteGlobalRef(pEnv, &pWatcher->mLock);
        deleteGlobalRef(pEnv, &pWatcher->mColor);
        deleteGlobalRef(pEnv, (jobject *) &pWatcher->ClassStore);
        deleteGlobalRef(pEnv, (jobject *) &pWatcher->ClassColor);
    }
}

void makeGlobalRef(JNIEnv* pEnv, jobject* pRef) {
    if (*pRef != NULL) {
        jobject lGlobalRef = pEnv->NewGlobalRef(*pRef);
        // Локальная ссылка больше не нужна.
        pEnv->DeleteLocalRef(*pRef);
        // Здесь lGlobalRef может иметь значение NULL.
        *pRef = lGlobalRef;
    }
}

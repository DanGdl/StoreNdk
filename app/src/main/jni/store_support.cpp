#include "store_support.h"
#include <cstring>

int32_t isEntryValid(JNIEnv* pEnv, const StoreEntry* pEntry, const StoreType pType) {
    if (pEntry == nullptr) {
        throwNotExistingKeyException(pEnv);
        return 0;
    } else if (pEntry->mType != pType) {
        throwInvalidTypeException(pEnv);
        return 0;
    }
    return 1;
}

StoreEntry* findEntry(JNIEnv* pEnv, const Store* pStore, const jstring pKey) {
    auto *entry = (StoreEntry *) pStore->mEntries;
    const StoreEntry *lEntryEnd = entry + pStore->mLength;
    const char *lKeyTmp = pEnv->GetStringUTFChars(pKey, nullptr);
    if (lKeyTmp == nullptr) {
        return nullptr;
    }
    while ((entry < lEntryEnd) && (strcmp(entry->mKey, lKeyTmp) != 0)) {
        ++entry;
    }
    pEnv->ReleaseStringUTFChars(pKey, lKeyTmp);
    return (entry == lEntryEnd) ? nullptr : entry;
}

StoreEntry* allocateEntry(JNIEnv* pEnv, Store* pStore, const jstring pKey) {
    StoreEntry *lEntry = findEntry(pEnv, pStore, pKey);
    if (lEntry == nullptr) {
        if (pStore->mLength >= STORE_MAX_CAPACITY) {
            throwStoreFullException(pEnv);
            return nullptr;
        }
        lEntry = pStore->mEntries + pStore->mLength;
        const char *lKeyTmp = pEnv->GetStringUTFChars(pKey, nullptr);
        if (lKeyTmp == nullptr) {
            return nullptr;
        }
        lEntry->mKey = new char[(strlen(lKeyTmp))];
        strcpy(lEntry->mKey, lKeyTmp);
        pEnv->ReleaseStringUTFChars(pKey, lKeyTmp);
        ++pStore->mLength;
    } else {
        releaseEntryValue(pEnv, lEntry);
    }
    return lEntry;
}

void releaseEntryValue(JNIEnv* pEnv, const StoreEntry* pEntry) {
    int32_t i;
    switch (pEntry->mType) {
        case StoreType_Integer:
            break;
        case StoreType_Bool:
            break;
        case StoreType_Byte:
            break;
        case StoreType_Char:
            break;
        case StoreType_Double:
            break;
        case StoreType_Float:
            break;
        case StoreType_Long:
            break;
        case StoreType_Short:
            break;

        case StoreType_String: {
            delete[] (pEntry->mValue.mString);
        }break;

        case StoreType_Color: {
            pEnv->DeleteGlobalRef(pEntry->mValue.mColor);
        }break;

        case StoreType_IntArray:{
            delete[] (pEntry->mValue.mIntArray);
        }break;

        case StoreType_StringArray: {
            for (i = 0; i < pEntry->mLength; ++i) {
                delete pEntry->mValue.mStringArray[i];
            }
            delete[] (pEntry->mValue.mStringArray);
        }break;

        case StoreType_BoolArray:{
            delete[] (pEntry->mValue.mBoolArray);
        }break;

        case StoreType_ByteArray:{
            delete[] (pEntry->mValue.mByteArray);
        }break;

        case StoreType_CharArray:{
            delete[] (pEntry->mValue.mCharArray);
        }break;

        case StoreType_DoubleArray:{
            delete[] (pEntry->mValue.mDoubleArray);
        }break;

        case StoreType_FloatArray:{
            delete[] (pEntry->mValue.mFloatArray);
        }break;

        case StoreType_LongArray:{
            delete[] (pEntry->mValue.mLongArray);
        }break;

        case StoreType_ShortArray: {
            delete[] (pEntry->mValue.mShortArray);
        }
            break;

        case StoreType_ColorArray: {
            for (i = 0; i < pEntry->mLength; ++i) {
                pEnv->DeleteGlobalRef(pEntry->mValue.mColorArray[i]);
            }
            delete[] (pEntry->mValue.mColorArray);
        }
            break;
    }
}

//    jthrowable exception = pEnv -> ExceptionOccurred();
//    if (exception) {
//    // Выполнить какие-либо операции...
//    pEnv -> ExceptionDescribe();
//    pEnv -> ExceptionClear();
//    pEnv -> DeleteLocalRef(exception);
//    }

void throwNotExistingKeyException(JNIEnv *pEnv) {
    jclass lClass = pEnv->FindClass(
            "com/mdgd/storeapp/model/storage/exception/NotExistingKeyException");
    if (lClass != nullptr) {
        pEnv->ThrowNew(lClass, "Key does not exist.");
    }
    pEnv->DeleteLocalRef(lClass);
}

void throwInvalidTypeException(JNIEnv* pEnv) {
    jclass lClass = pEnv->FindClass(
            "com/mdgd/storeapp/model/storage/exception/InvalidTypeException");
    if (lClass != nullptr) {
        pEnv->ThrowNew(lClass, "Wrong type.");
    }
    pEnv->DeleteLocalRef(lClass);
}

void throwStoreFullException(JNIEnv* pEnv) {
    jclass lClass = pEnv->FindClass("com/mdgd/storeapp/model/storage/exception/StoreFullException");
    if (lClass != nullptr) {
        pEnv->ThrowNew(lClass, "Store is full.");
    }
    pEnv->DeleteLocalRef(lClass);
}

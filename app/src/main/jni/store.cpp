//
// Created by max on 2/21/18.
//

#ifndef STORE_COM_PACKTUB_STORE_H
#define STORE_COM_PACKTUB_STORE_H

#include "store_support.h"
#include "StoreWatcher.h"
#include <cstring>
#include <cstdint>

static Store mStore;
static StoreWatcher mStoreWatcher;
//static jmethodID MethodOnSuccessInt;
//static jmethodID MethodOnSuccessString;
//static jmethodID MethodOnSuccessColor;
static jclass StringClass;
static jclass ColorClass;
static jobject gLock;


namespace com_mdgd_storeapp_model_storage_Store {

    static jint getCount(JNIEnv *pEnv, jobject pThis) {
        return mStore.mLength;
    }

    static jint getInteger(JNIEnv *pEnv, jobject pThis, jstring pKey) {
        const StoreEntry *lEntry = findEntry(pEnv, &mStore, pKey);
        if (isEntryValid(pEnv, lEntry, StoreType_Integer)) {
            return lEntry->mValue.mInteger;
        } else {
            return 0;
        }
    }

    static void setInteger(JNIEnv *pEnv, jobject pThis, jstring pKey, jint pInteger) {
        StoreEntry *lEntry = allocateEntry(pEnv, &mStore, pKey);
        if (lEntry != nullptr) {
            lEntry->mType = StoreType_Integer;
            lEntry->mValue.mInteger = pInteger;
            // pEnv -> CallVoidMethod(pThis, MethodOnSuccessInt, (jint) lEntry -> mValue.mInteger);
        }
    }

    static jstring getString(JNIEnv *pEnv, jobject pThis, jstring pKey) {
        const StoreEntry *lEntry = findEntry(pEnv, &mStore, pKey);
        if (isEntryValid(pEnv, lEntry, StoreType_String)) {
            return pEnv->NewStringUTF(lEntry->mValue.mString);
        } else {
            return nullptr;
        }
    }

    static void setString(JNIEnv *pEnv, jobject pThis, jstring pKey, jstring pString) {
        const char *lStringTmp = pEnv->GetStringUTFChars(pString, nullptr);
        if (lStringTmp == nullptr) {
            return;
        }
        StoreEntry *lEntry = allocateEntry(pEnv, &mStore, pKey);
        if (lEntry != nullptr) {
            lEntry->mType = StoreType_String;
            jsize lStringLength = pEnv->GetStringUTFLength(pString);
            lEntry->mValue.mString = new char[(sizeof(char) * (lStringLength + 1))];
            strcpy(lEntry->mValue.mString, lStringTmp);
        }
        pEnv->ReleaseStringUTFChars(pString, lStringTmp);
    }

    static jboolean getBoolean(JNIEnv *pEnv, jobject pThis, jstring pKey) {
        const StoreEntry *lEntry = findEntry(pEnv, &mStore, pKey);
        if (isEntryValid(pEnv, lEntry, StoreType_Bool)) {
            return lEntry->mValue.mBool;
        } else {
            return 0;
        }
    }

    static void setBoolean(JNIEnv *pEnv, jobject pThis, jstring pKey, jboolean pBool) {
        StoreEntry *lEntry = allocateEntry(pEnv, &mStore, pKey);
        if (lEntry != nullptr) {
            lEntry->mType = StoreType_Bool;
            lEntry->mValue.mBool = pBool;
        }
    }

    static jbyte getByte(JNIEnv *pEnv, jobject pThis, jstring pKey) {
        const StoreEntry *lEntry = findEntry(pEnv, &mStore, pKey);
        if (isEntryValid(pEnv, lEntry, StoreType_Byte)) {
            return lEntry->mValue.mByte;
        } else {
            return 0;
        }
    }

    static void setByte(JNIEnv *pEnv, jobject pThis, jstring pKey, jbyte pByte) {
        StoreEntry *lEntry = allocateEntry(pEnv, &mStore, pKey);
        if (lEntry != nullptr) {
            lEntry->mType = StoreType_Byte;
            lEntry->mValue.mByte = pByte;
        }
    }

    static jchar getChar(JNIEnv *pEnv, jobject pThis, jstring pKey) {
        const StoreEntry *lEntry = findEntry(pEnv, &mStore, pKey);
        if (isEntryValid(pEnv, lEntry, StoreType_Char)) {
            return lEntry->mValue.mChar;
        } else {
            return 0;
        }
    }

    static void setChar(JNIEnv *pEnv, jobject pThis, jstring pKey, jchar pChar) {
        StoreEntry *lEntry = allocateEntry(pEnv, &mStore, pKey);
        if (lEntry != nullptr) {
            lEntry->mType = StoreType_Char;
            lEntry->mValue.mChar = pChar;
        }
    }

    static jdouble getDouble(JNIEnv *pEnv, jobject pThis, jstring pKey) {
        const StoreEntry *lEntry = findEntry(pEnv, &mStore, pKey);
        if (isEntryValid(pEnv, lEntry, StoreType_Double)) {
            return lEntry->mValue.mDouble;
        } else {
            return 0;
        }
    }

    static void setDouble(JNIEnv *pEnv, jobject pThis, jstring pKey, jdouble pDouble) {
        StoreEntry *lEntry = allocateEntry(pEnv, &mStore, pKey);
        if (lEntry != nullptr) {
            lEntry->mType = StoreType_Double;
            lEntry->mValue.mDouble = pDouble;
        }
    }

    static jfloat getFloat(JNIEnv *pEnv, jobject pThis, jstring pKey) {
        const StoreEntry *lEntry = findEntry(pEnv, &mStore, pKey);
        if (isEntryValid(pEnv, lEntry, StoreType_Float)) {
            return lEntry->mValue.mFloat;
        } else {
            return 0;
        }
    }

    static void setFloat(JNIEnv *pEnv, jobject pThis, jstring pKey, jfloat pFloat) {
        StoreEntry *lEntry = allocateEntry(pEnv, &mStore, pKey);
        if (lEntry != nullptr) {
            lEntry->mType = StoreType_Float;
            lEntry->mValue.mFloat = pFloat;
        }
    }

    static jlong getLong(JNIEnv *pEnv, jobject pThis, jstring pKey) {
        const StoreEntry *lEntry = findEntry(pEnv, &mStore, pKey);
        if (isEntryValid(pEnv, lEntry, StoreType_Long)) {
            return lEntry->mValue.mLong;
        } else {
            return 0;
        }
    }

    static void setLong(JNIEnv *pEnv, jobject pThis, jstring pKey, jlong pLong) {
        StoreEntry *lEntry = allocateEntry(pEnv, &mStore, pKey);
        if (lEntry != nullptr) {
            lEntry->mType = StoreType_Long;
            lEntry->mValue.mLong = pLong;
        }
    }

    static jshort getShort(JNIEnv *pEnv, jobject pThis, jstring pKey) {
        const StoreEntry *lEntry = findEntry(pEnv, &mStore, pKey);
        if (isEntryValid(pEnv, lEntry, StoreType_Short)) {
            return lEntry->mValue.mShort;
        } else {
            return 0;
        }
    }

    static void setShort(JNIEnv *pEnv, jobject pThis, jstring pKey, jshort pShort) {
        StoreEntry *lEntry = allocateEntry(pEnv, &mStore, pKey);
        if (lEntry != nullptr) {
            lEntry->mType = StoreType_Short;
            lEntry->mValue.mShort = pShort;
        }
    }

    static jobject getColor(JNIEnv *pEnv, jobject pThis, jstring pKey) {
        const StoreEntry *lEntry = findEntry(pEnv, &mStore, pKey);
        if (isEntryValid(pEnv, lEntry, StoreType_Color)) {
            return lEntry->mValue.mColor;
        } else {
            return nullptr;
        }
    }

    static void setColor(JNIEnv *pEnv, jobject pThis, jstring pKey, jobject pColor) {
        jobject lColor = pEnv->NewGlobalRef(pColor);
        if (lColor == nullptr) {
            return;
        }
        StoreEntry *lEntry = allocateEntry(pEnv, &mStore, pKey);
        if (lEntry == nullptr) {
            pEnv->DeleteGlobalRef(lColor);
        } else {
            lEntry->mType = StoreType_Color;
            lEntry->mValue.mColor = lColor;
        }
    }

    static jintArray getIntArray(JNIEnv *pEnv, jobject pThis, jstring pKey) {
        const StoreEntry *lEntry = findEntry(pEnv, &mStore, pKey);
        if (isEntryValid(pEnv, lEntry, StoreType_IntArray)) {
            jintArray lJavaArray = pEnv->NewIntArray(lEntry->mLength);
            if (lJavaArray == nullptr) {
                return nullptr;
            }
            pEnv->SetIntArrayRegion(lJavaArray, 0, lEntry->mLength, lEntry->mValue.mIntArray);
            return lJavaArray;
        }
        return nullptr;
    }

    static void setIntArray(JNIEnv *pEnv, jobject pThis, jstring pKey, jintArray pIntArray) {
        const jsize lLength = pEnv->GetArrayLength(pIntArray);
        auto *lArray = new int32_t[lLength * sizeof(int32_t)];
        pEnv->GetIntArrayRegion(pIntArray, 0, lLength, lArray);
        if (pEnv->ExceptionCheck()) {
            delete[] lArray;
            return;
        }
        StoreEntry *lEntry = allocateEntry(pEnv, &mStore, pKey);
        if (lEntry == nullptr) {
            delete[] lArray;
        } else {
            lEntry->mType = StoreType_IntArray;
            lEntry->mLength = lLength;
            lEntry->mValue.mIntArray = lArray;
        }
    }

    static jobjectArray getColorArray(JNIEnv *pEnv, jobject pThis, jstring pKey) {
        const StoreEntry *lEntry = findEntry(pEnv, &mStore, pKey);
        if (isEntryValid(pEnv, lEntry, StoreType_ColorArray)) {
            if (ColorClass == nullptr) {
                return nullptr;
            }
            jobjectArray lJavaArray = pEnv->NewObjectArray(lEntry->mLength, ColorClass, nullptr);
            pEnv->DeleteLocalRef(ColorClass);
            if (lJavaArray == nullptr) {
                return nullptr;
            }
            int32_t i;
            for (i = 0; i < lEntry->mLength; ++i) {
                pEnv->SetObjectArrayElement(lJavaArray, i, lEntry->mValue.mColorArray[i]);
                if (pEnv->ExceptionCheck()) {
                    return nullptr;
                }
            }
            return lJavaArray;
        } else {
            return nullptr;
        }
    }

    static void setColorArray(JNIEnv *pEnv, jobject pThis, jstring pKey, jobjectArray pColorArray) {
        const jsize lLength = pEnv->GetArrayLength(pColorArray);
        auto *lArray = new jobject[lLength * sizeof(jobject)];
        int32_t i, j;
        for (i = 0; i < lLength; ++i) {
            jobject lLocalColor = pEnv->GetObjectArrayElement(pColorArray, i);
            if (lLocalColor == nullptr) {
                for (j = 0; j < i; ++j) {
                    pEnv->DeleteGlobalRef(lArray[j]);
                }
                delete[] lArray;
                return;
            }
            lArray[i] = pEnv->NewGlobalRef(lLocalColor);
            if (lArray[i] == nullptr) {
                for (j = 0; j < i; ++j) {
                    pEnv->DeleteGlobalRef(lArray[j]);
                }
                delete[] lArray;
                return;
            }
            pEnv->DeleteLocalRef(lLocalColor);
        }
        StoreEntry *lEntry = allocateEntry(pEnv, &mStore, pKey);
        if (lEntry == nullptr) {
            for (j = 0; j < i; ++j) {
                pEnv->DeleteGlobalRef(lArray[j]);
            }
            delete[] lArray;
        } else {
            lEntry->mType = StoreType_ColorArray;
            lEntry->mLength = lLength;
            lEntry->mValue.mColorArray = lArray;
        }
    }

    static void setBoolArray(JNIEnv *pEnv, jobject pThis, jstring pKey, jbooleanArray pBoolArray) {
        const jsize lLength = pEnv->GetArrayLength(pBoolArray);
        auto *lArray = new uint8_t[lLength * sizeof(uint8_t)];
        pEnv->GetBooleanArrayRegion(pBoolArray, 0, lLength, lArray);
        if (pEnv->ExceptionCheck()) {
            delete[] lArray;
            return;
        }
        StoreEntry *lEntry = allocateEntry(pEnv, &mStore, pKey);
        if (lEntry == nullptr) {
            delete[] lArray;
        } else {
            lEntry->mType = StoreType_BoolArray;
            lEntry->mLength = lLength;
            lEntry->mValue.mBoolArray = lArray;
        }
    }

    static jbooleanArray getBoolArray(JNIEnv *pEnv, jobject pThis, jstring pKey) {
        const StoreEntry *lEntry = findEntry(pEnv, &mStore, pKey);
        if (isEntryValid(pEnv, lEntry, StoreType_BoolArray)) {
            jbooleanArray lJavaArray = pEnv->NewBooleanArray(lEntry->mLength);
            if (lJavaArray == nullptr) {
                return nullptr;
            }
            pEnv->SetBooleanArrayRegion(lJavaArray, 0, lEntry->mLength, lEntry->mValue.mBoolArray);
            return lJavaArray;
        }
        return nullptr;
    }

    static void setByteArray(JNIEnv *pEnv, jobject pThis, jstring pKey, jbyteArray pByteArray) {
        const jsize lLength = pEnv->GetArrayLength(pByteArray);
        auto *lArray = new int8_t[lLength * sizeof(int8_t)];
        pEnv->GetByteArrayRegion(pByteArray, 0, lLength, lArray);
        if (pEnv->ExceptionCheck()) {
            delete[] lArray;
            return;
        }
        StoreEntry *lEntry = allocateEntry(pEnv, &mStore, pKey);
        if (lEntry == nullptr) {
            delete[] lArray;
        } else {
            lEntry->mType = StoreType_ByteArray;
            lEntry->mLength = lLength;
            lEntry->mValue.mByteArray = lArray;
        }
    }

    static jbyteArray getByteArray(JNIEnv *pEnv, jobject pThis, jstring pKey) {
        const StoreEntry *lEntry = findEntry(pEnv, &mStore, pKey);
        if (isEntryValid(pEnv, lEntry, StoreType_ByteArray)) {
            jbyteArray lJavaArray = pEnv->NewByteArray(lEntry->mLength);
            if (lJavaArray == nullptr) {
                return nullptr;
            }
            pEnv->SetByteArrayRegion(lJavaArray, 0, lEntry->mLength, lEntry->mValue.mByteArray);
            return lJavaArray;
        }
        return nullptr;
    }

    static void setCharArray(JNIEnv *pEnv, jobject pThis, jstring pKey, jcharArray pCharArray) {
        const jsize lLength = pEnv->GetArrayLength(pCharArray);
        auto *lArray = new uint16_t[lLength * sizeof(uint16_t)];
        pEnv->GetCharArrayRegion(pCharArray, 0, lLength, lArray);
        if (pEnv->ExceptionCheck()) {
            delete[] lArray;
            return;
        }
        StoreEntry *lEntry = allocateEntry(pEnv, &mStore, pKey);
        if (lEntry == nullptr) {
            delete[] lArray;
        } else {
            lEntry->mType = StoreType_CharArray;
            lEntry->mLength = lLength;
            lEntry->mValue.mCharArray = lArray;
        }
    }

    static jcharArray getCharArray(JNIEnv *pEnv, jobject pThis, jstring pKey) {
        const StoreEntry *lEntry = findEntry(pEnv, &mStore, pKey);
        if (isEntryValid(pEnv, lEntry, StoreType_CharArray)) {
            jcharArray lJavaArray = pEnv->NewCharArray(lEntry->mLength);
            if (lJavaArray == nullptr) {
                return nullptr;
            }
            pEnv->SetCharArrayRegion(lJavaArray, 0, lEntry->mLength, lEntry->mValue.mCharArray);
            return lJavaArray;
        }
        return nullptr;
    }

    static void
    setDoubleArray(JNIEnv *pEnv, jobject pThis, jstring pKey, jdoubleArray pDoubleArray) {
        const jsize lLength = pEnv->GetArrayLength(pDoubleArray);
        auto *lArray = new double[lLength * sizeof(double)];
        pEnv->GetDoubleArrayRegion(pDoubleArray, 0, lLength, lArray);
        if (pEnv->ExceptionCheck()) {
            delete[] lArray;
            return;
        }
        StoreEntry *lEntry = allocateEntry(pEnv, &mStore, pKey);
        if (lEntry == nullptr) {
            delete[] lArray;
        } else {
            lEntry->mType = StoreType_DoubleArray;
            lEntry->mLength = lLength;
            lEntry->mValue.mDoubleArray = lArray;
        }
    }

    static jdoubleArray getDoubleArray(JNIEnv *pEnv, jobject pThis, jstring pKey) {
        const StoreEntry *lEntry = findEntry(pEnv, &mStore, pKey);
        if (isEntryValid(pEnv, lEntry, StoreType_DoubleArray)) {
            jdoubleArray lJavaArray = pEnv->NewDoubleArray(lEntry->mLength);
            if (lJavaArray == nullptr) {
                return nullptr;
            }
            pEnv->SetDoubleArrayRegion(lJavaArray, 0, lEntry->mLength, lEntry->mValue.mDoubleArray);
            return lJavaArray;
        }
        return nullptr;
    }

    static void setFloatArray(JNIEnv *pEnv, jobject pThis, jstring pKey, jfloatArray pFloatArray) {
        const jsize lLength = pEnv->GetArrayLength(pFloatArray);
        auto *lArray = new float[lLength * sizeof(float)];
        pEnv->GetFloatArrayRegion(pFloatArray, 0, lLength, lArray);
        if (pEnv->ExceptionCheck()) {
            delete[] lArray;
            return;
        }
        StoreEntry *lEntry = allocateEntry(pEnv, &mStore, pKey);
        if (lEntry == nullptr) {
            delete[] lArray;
        } else {
            lEntry->mType = StoreType_FloatArray;
            lEntry->mLength = lLength;
            lEntry->mValue.mFloatArray = lArray;
        }
    }

    static jfloatArray getFloatArray(JNIEnv *pEnv, jobject pThis, jstring pKey) {
        const StoreEntry *lEntry = findEntry(pEnv, &mStore, pKey);
        if (isEntryValid(pEnv, lEntry, StoreType_FloatArray)) {
            jfloatArray lJavaArray = pEnv->NewFloatArray(lEntry->mLength);
            if (lJavaArray == nullptr) {
                return nullptr;
            }
            pEnv->SetFloatArrayRegion(lJavaArray, 0, lEntry->mLength, lEntry->mValue.mFloatArray);
            return lJavaArray;
        }
        return nullptr;
    }

    static void setLongArray(JNIEnv *pEnv, jobject pThis, jstring pKey, jlongArray pLongArray) {
        const jsize lLength = pEnv->GetArrayLength(pLongArray);
        auto *lArray = new int64_t[lLength * sizeof(int64_t)];
        pEnv->GetLongArrayRegion(pLongArray, 0, lLength, lArray);
        if (pEnv->ExceptionCheck()) {
            delete[] lArray;
            return;
        }
        StoreEntry *lEntry = allocateEntry(pEnv, &mStore, pKey);
        if (lEntry == nullptr) {
            delete[] lArray;
        } else {
            lEntry->mType = StoreType_LongArray;
            lEntry->mLength = lLength;
            lEntry->mValue.mLongArray = lArray;
        }
    }

    static jlongArray getLongArray(JNIEnv *pEnv, jobject pThis, jstring pKey) {
        const StoreEntry *lEntry = findEntry(pEnv, &mStore, pKey);
        if (isEntryValid(pEnv, lEntry, StoreType_LongArray)) {
            jlongArray lJavaArray = pEnv->NewLongArray(lEntry->mLength);
            if (lJavaArray == nullptr) {
                return nullptr;
            }
            pEnv->SetLongArrayRegion(lJavaArray, 0, lEntry->mLength, lEntry->mValue.mLongArray);
            return lJavaArray;
        }
        return nullptr;
    }

    static void setShortArray(JNIEnv *pEnv, jobject pThis, jstring pKey, jshortArray pShortArray) {
        const jsize lLength = pEnv->GetArrayLength(pShortArray);
        auto *lArray = new int16_t[lLength * sizeof(int16_t)];
        pEnv->GetShortArrayRegion(pShortArray, 0, lLength, lArray);
        if (pEnv->ExceptionCheck()) {
            delete[] lArray;
            return;
        }
        StoreEntry *lEntry = allocateEntry(pEnv, &mStore, pKey);
        if (lEntry == nullptr) {
            delete[] lArray;
        } else {
            lEntry->mType = StoreType_ShortArray;
            lEntry->mLength = lLength;
            lEntry->mValue.mShortArray = lArray;
        }
    }

    static jshortArray getShortArray(JNIEnv *pEnv, jobject pThis, jstring pKey) {
        const StoreEntry *lEntry = findEntry(pEnv, &mStore, pKey);
        if (isEntryValid(pEnv, lEntry, StoreType_ShortArray)) {
            jshortArray lJavaArray = pEnv->NewShortArray(lEntry->mLength);
            if (lJavaArray == nullptr) {
                return nullptr;
            }
            pEnv->SetShortArrayRegion(lJavaArray, 0, lEntry->mLength, lEntry->mValue.mShortArray);
            return lJavaArray;
        }
        return nullptr;
    }

    static void
    setStringArray(JNIEnv *pEnv, jobject pThis, jstring pKey, jobjectArray pStringArray) {
        const jsize lLength = pEnv->GetArrayLength(pStringArray);
        char **lArray = new char *[lLength * sizeof(char *)];
        int32_t i, j;
        for (i = 0; i < lLength; ++i) {
            auto obj = (jstring) pEnv->GetObjectArrayElement(pStringArray, i);
            if (obj == nullptr) {
                for (j = 0; j < i; ++j) {
                    delete[] lArray[j];
                }
                delete[] lArray;
                return;
            }
            const char *lStringTmp = pEnv->GetStringUTFChars(obj, nullptr);
            const jsize lStringLength = pEnv->GetStringUTFLength(obj);
            char *lLocalStr = new char[(sizeof(char) * (lStringLength + 1))];
            strcpy(lLocalStr, lStringTmp);
            lArray[i] = lLocalStr;
            if (lArray[i] == nullptr) {
                for (j = 0; j < i; ++j) {
                    delete[] lArray[j];
                }
                delete[] lArray;
                return;
            }
            pEnv->ReleaseStringUTFChars(obj, lStringTmp);
        }
        StoreEntry *lEntry = allocateEntry(pEnv, &mStore, pKey);
        if (lEntry == nullptr) {
            for (j = 0; j < i; ++j) {
                delete[] lArray[j];
            }
            delete[] lArray;
        } else {
            lEntry->mType = StoreType_StringArray;
            lEntry->mLength = lLength;
            lEntry->mValue.mStringArray = lArray;
        }
    }

    static jobjectArray getStringArray(JNIEnv *pEnv, jobject pThis, jstring pKey) {
        const StoreEntry *lEntry = findEntry(pEnv, &mStore, pKey);
        if (isEntryValid(pEnv, lEntry, StoreType_StringArray)) {
            if (StringClass == nullptr) {
                return nullptr;
            }
            jobjectArray lJavaArray = pEnv->NewObjectArray(lEntry->mLength, StringClass, nullptr);
            pEnv->DeleteLocalRef(StringClass);
            if (lJavaArray == nullptr) {
                return nullptr;
            }
            int32_t i;
            for (i = 0; i < lEntry->mLength; ++i) {
                jstring str = pEnv->NewStringUTF(lEntry->mValue.mStringArray[i]);
                pEnv->SetObjectArrayElement(lJavaArray, i, str);
                if (pEnv->ExceptionCheck()) {
                    return nullptr;
                }
            }
            return lJavaArray;
        } else {
            return nullptr;
        }
    }

    static jlong initializeStore(JNIEnv *env, jobject pThis) {
        mStore.mLength = 0;
        startWatcher(env, &mStoreWatcher, &mStore, pThis);
        return (jlong) &mStoreWatcher;
    }

    static void finalizeStore(JNIEnv *env, jobject pThis, jlong watcher) {
        // stopWatcher(env, &mStoreWatcher);
        stopWatcher(env, (StoreWatcher *) watcher);
        StoreEntry *entry = mStore.mEntries;
        const StoreEntry *lEntryEnd = entry + mStore.mLength;
        while (entry < lEntryEnd) {
            if (entry != nullptr) {
                delete[] entry->mKey;
                releaseEntryValue(env, entry);
            }
            entry++;
        }
        mStore.mLength = 0;
    }

    static jstring getArchitecture(JNIEnv *pEnv, jobject thiz) {
#if defined(__arm__)
#if defined(__ARM_ARCH_7A__)
#if defined(__ARM_NEON__)
#if defined(__ARM_PCS_VFP)
#define ABI "armeabi-v7a/NEON (hard-float)"
#else
#define ABI "armeabi-v7a/NEON"
#endif
#else
#if defined(__ARM_PCS_VFP)
#define ABI "armeabi-v7a (hard-float)"
#else
#define ABI "armeabi-v7a"
#endif
#endif
#else
#define ABI "armeabi"
#endif
#elif defined(__i386__)
#define ABI "x86"
#elif defined(__x86_64__)
#define ABI "x86_64"
#elif defined(__mips64)  /* mips64el-* toolchain defines __mips__ too */
#define ABI "mips64"
#elif defined(__mips__)
#define ABI "mips"
#elif defined(__aarch64__)
#define ABI "arm64-v8a"
#else
#define ABI "unknown"
#endif
        return (pEnv)->NewStringUTF(ABI);
    }


    static JNINativeMethod table_methods[] = {
            {"getCount",        "()I",                                                           (jint *) getCount},

            {"getInteger",      "(Ljava/lang/String;)I",                                         (jint *) getInteger},
            {"setInteger",      "(Ljava/lang/String;I)V",                                        (void *) setInteger},

            {"getString",       "(Ljava/lang/String;)Ljava/lang/String;",                        (jstring) getString},
            {"setString",       "(Ljava/lang/String;Ljava/lang/String;)V",                       (void *) setString},

            {"getBoolean",      "(Ljava/lang/String;)Z",                                         (jboolean *) getBoolean},
            {"setBoolean",      "(Ljava/lang/String;Z)V",                                        (void *) setBoolean},

            {"getByte",         "(Ljava/lang/String;)B",                                         (jbyte *) getByte},
            {"setByte",         "(Ljava/lang/String;B)V",                                        (void *) setByte},

            {"getChar",         "(Ljava/lang/String;)C",                                         (jchar *) getChar},
            {"setChar",         "(Ljava/lang/String;C)V",                                        (void *) setChar},

            {"getDouble",       "(Ljava/lang/String;)D",                                         (jdouble *) getDouble},
            {"setDouble",       "(Ljava/lang/String;D)V",                                        (void *) setDouble},

            {"getFloat",        "(Ljava/lang/String;)F",                                         (jfloat *) getFloat},
            {"setFloat",        "(Ljava/lang/String;F)V",                                        (void *) setFloat},

            {"getLong",         "(Ljava/lang/String;)J",                                         (jlong *) getLong},
            {"setLong",         "(Ljava/lang/String;J)V",                                        (void *) setLong},

            {"getShort",        "(Ljava/lang/String;)S",                                         (jshort *) getShort},
            {"setShort",        "(Ljava/lang/String;S)V",                                        (void *) setShort},

            {"getColor",        "(Ljava/lang/String;)Lcom/mdgd/storeapp/model/storage/Color;",   (jobject) getColor},
            {"setColor",        "(Ljava/lang/String;Lcom/mdgd/storeapp/model/storage/Color;)V",  (void *) setColor},

            {"getIntArray",     "(Ljava/lang/String;)[I",                                        (jintArray) getIntArray},
            {"setIntArray",     "(Ljava/lang/String;[I)V",                                       (void *) setIntArray},

            {"getColorArray",   "(Ljava/lang/String;)[Lcom/mdgd/storeapp/model/storage/Color;",  (jobjectArray) getColorArray},
            {"setColorArray",   "(Ljava/lang/String;[Lcom/mdgd/storeapp/model/storage/Color;)V", (void *) setColorArray},

            {"getBoolArray",    "(Ljava/lang/String;)[Z",                                        (jbooleanArray) getBoolArray},
            {"setBoolArray",    "(Ljava/lang/String;[Z)V",                                       (void *) setBoolArray},

            {"getByteArray",    "(Ljava/lang/String;)[B",                                        (jbyteArray) getByteArray},
            {"setByteArray",    "(Ljava/lang/String;[B)V",                                       (void *) setByteArray},

            {"getCharArray",    "(Ljava/lang/String;)[C",                                        (jcharArray) getCharArray},
            {"setCharArray",    "(Ljava/lang/String;[C)V",                                       (void *) setCharArray},

            {"getDoubleArray",  "(Ljava/lang/String;)[D",                                        (jdoubleArray) getDoubleArray},
            {"setDoubleArray",  "(Ljava/lang/String;[D)V",                                       (void *) setDoubleArray},

            {"getFloatArray",   "(Ljava/lang/String;)[F",                                        (jfloatArray) getFloatArray},
            {"setFloatArray",   "(Ljava/lang/String;[F)V",                                       (void *) setFloatArray},

            {"getLongArray",    "(Ljava/lang/String;)[J",                                        (jlongArray) getLongArray},
            {"setLongArray",    "(Ljava/lang/String;[J)V",                                       (void *) setLongArray},

            {"getShortArray",   "(Ljava/lang/String;)[S",                                        (jshortArray) getShortArray},
            {"setShortArray",   "(Ljava/lang/String;[S)V",                                       (void *) setShortArray},

            {"getStringArray",  "(Ljava/lang/String;)[Ljava/lang/String;",                       (jobjectArray) getStringArray},
            {"setStringArray",  "(Ljava/lang/String;[Ljava/lang/String;)V",                      (void *) setStringArray},

            {"initializeStore", "()J",                                                           (jlong *) initializeStore},
            {"finalizeStore",   "(J)V",                                                          (void *) finalizeStore},
            {"getArchitecture", "()Ljava/lang/String;",                                          (jstring) getArchitecture}
    };


    extern "C" {

    JNIEXPORT jint JNICALL
    JNI_OnLoad(JavaVM *pVM, void *reserved) {
        JNIEnv *env;
        if (pVM->GetEnv((void **) &env, JNI_VERSION_1_6) != JNI_OK) {
            return -1;
        }
        jclass StringClassTmp = env->FindClass("java/lang/String");
        if (StringClassTmp == nullptr) {
            return -1;
        }
        StringClass = (jclass) env->NewGlobalRef(StringClassTmp);
        env->DeleteLocalRef(StringClassTmp);
        jclass ColorClassTmp = env->FindClass("com/mdgd/storeapp/model/storage/Color");
        if (ColorClassTmp == nullptr) {
            return -1;
        }
        ColorClass = (jclass) env->NewGlobalRef(ColorClassTmp);
        env->DeleteLocalRef(ColorClassTmp);

        // Кэшировать методы.
        jclass StoreClass = env->FindClass("com/mdgd/storeapp/model/storage/Store");
        if (StoreClass == nullptr) {
            return -1;
        }
        // MethodOnSuccessInt = env -> GetMethodID(StoreClass, "onAlert", "(I)V");
        // if (MethodOnSuccessInt == NULL) {
        //     return -1;
        // }
        // MethodOnSuccessString = env -> GetMethodID(StoreClass, "onAlert", "(Ljava/lang/String;)V");
        // if (MethodOnSuccessString == NULL) {
        //     return -1;
        // }
        // MethodOnSuccessColor = env -> GetMethodID(StoreClass, "onAlert", "(Lcom/mdgd/storeapp/dto/Color;)V");
        // if (MethodOnSuccessColor == NULL) {
        //     return -1;
        // }
        //env -> DeleteLocalRef(StoreClass);

        jclass ObjectClass = env->FindClass("java/lang/Object");
        if (ObjectClass == nullptr) {
            return -1;
        }
        jmethodID ObjectConstructor = env->GetMethodID(ObjectClass, "<init>", "()V");
        if (ObjectConstructor == nullptr) {
            return -1;
        }
        jobject lockTmp = env->NewObject(ObjectClass, ObjectConstructor);
        env->DeleteLocalRef(ObjectClass);
        gLock = env->NewGlobalRef(lockTmp);
        env->DeleteLocalRef(lockTmp);

        jclass StoreThreadSafeClass = env->FindClass(
                "com/mdgd/storeapp/model/storage/StoreThreadSafe"
        );
        if (StoreThreadSafeClass == nullptr) {
            return -1;
        }
        jfieldID lockField = env->GetStaticFieldID(
                StoreThreadSafeClass, "LOCK", "Ljava/lang/Object;"
        );
        if (lockField == nullptr) {
            return -1;
        }

        env->RegisterNatives(
                StoreClass, table_methods, sizeof(table_methods) / sizeof(table_methods[0])
        );

        env->SetStaticObjectField(StoreThreadSafeClass, lockField, gLock);
        env->DeleteLocalRef(StoreThreadSafeClass);

        mStore.mLength = 0;

        return JNI_VERSION_1_6;
    }
    }
}

#endif

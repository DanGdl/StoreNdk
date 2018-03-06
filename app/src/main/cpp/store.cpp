//
// Created by max on 2/21/18.
//

#ifndef STORE_COM_PACKTUB_STORE_H
#define STORE_COM_PACKTUB_STORE_H

#include "store_support.h"
#include "StoreWatcher.h"
#include <string.h>
#include <stdint.h>

static Store mStore = { {}, 0 };
static StoreWatcher mStoreWatcher;
extern "C" {
    JNIEXPORT jint JNICALL
    Java_com_packtub_Store_getInteger(JNIEnv *pEnv, jobject pThis, jstring pKey) {
        StoreEntry *lEntry = findEntry(pEnv, &mStore, pKey);
        if (isEntryValid(pEnv, lEntry, StoreType_Integer)) {
            return lEntry->mValue.mInteger;
        }
        else {
            return 0;
        }
    }

    JNIEXPORT void JNICALL
    Java_com_packtub_Store_setInteger(JNIEnv *pEnv, jobject pThis, jstring pKey, jint pInteger) {
        StoreEntry *lEntry = allocateEntry(pEnv, &mStore, pKey);
        if (lEntry != NULL) {
            lEntry->mType = StoreType_Integer;
            lEntry->mValue.mInteger = pInteger;
        }
    }

    JNIEXPORT jstring JNICALL
    Java_com_packtub_Store_getString(JNIEnv *pEnv, jobject pThis, jstring pKey) {
        StoreEntry *lEntry = findEntry(pEnv, &mStore, pKey);
        if (isEntryValid(pEnv, lEntry, StoreType_String)) {
            return pEnv->NewStringUTF(lEntry->mValue.mString);
        }
        else {
            return NULL;
        }
    }

    JNIEXPORT void JNICALL
    Java_com_packtub_Store_setString(JNIEnv *pEnv, jobject pThis, jstring pKey, jstring pString) {
        const char* lStringTmp = pEnv->GetStringUTFChars(pString, NULL);
        if (lStringTmp == NULL) {
            return;
        }
        StoreEntry *lEntry = allocateEntry(pEnv, &mStore, pKey);
        if (lEntry != NULL) {
            lEntry->mType = StoreType_String;
            jsize lStringLength = pEnv->GetStringUTFLength(pString);
            lEntry->mValue.mString = new char[(sizeof(char) * (lStringLength + 1))];
            strcpy(lEntry->mValue.mString, lStringTmp);
        }
        pEnv->ReleaseStringUTFChars(pString, lStringTmp);
    }

    JNIEXPORT jboolean JNICALL
    Java_com_packtub_Store_getBoolean(JNIEnv *pEnv, jobject pThis, jstring pKey) {
        StoreEntry *lEntry = findEntry(pEnv, &mStore, pKey);
        if (isEntryValid(pEnv, lEntry, StoreType_Bool)) {
            return lEntry->mValue.mBool;
        }
        else {
            return 0;
        }
    }

    JNIEXPORT void JNICALL
    Java_com_packtub_Store_setBoolean(JNIEnv *pEnv, jobject pThis, jstring pKey, jboolean pBool) {
        StoreEntry *lEntry = allocateEntry(pEnv, &mStore, pKey);
        if (lEntry != NULL) {
            lEntry->mType = StoreType_Bool;
            lEntry->mValue.mBool = pBool;
        }
    }

    JNIEXPORT jbyte JNICALL
    Java_com_packtub_Store_getByte(JNIEnv *pEnv, jobject pThis, jstring pKey) {
        StoreEntry *lEntry = findEntry(pEnv, &mStore, pKey);
        if (isEntryValid(pEnv, lEntry, StoreType_Byte)) {
            return lEntry->mValue.mByte;
        }
        else {
            return 0;
        }
    }

    JNIEXPORT void JNICALL
    Java_com_packtub_Store_setByte(JNIEnv *pEnv, jobject pThis, jstring pKey, jbyte pByte) {
        StoreEntry *lEntry = allocateEntry(pEnv, &mStore, pKey);
        if (lEntry != NULL) {
            lEntry->mType = StoreType_Byte;
            lEntry->mValue.mByte = pByte;
        }
    }

    JNIEXPORT jchar JNICALL
    Java_com_packtub_Store_getChar(JNIEnv *pEnv, jobject pThis, jstring pKey) {
        StoreEntry *lEntry = findEntry(pEnv, &mStore, pKey);
        if (isEntryValid(pEnv, lEntry, StoreType_Char)) {
            return lEntry->mValue.mChar;
        }
        else {
            return 0;
        }
    }

    JNIEXPORT void JNICALL
    Java_com_packtub_Store_setChar(JNIEnv *pEnv, jobject pThis, jstring pKey, jchar pChar) {
        StoreEntry *lEntry = allocateEntry(pEnv, &mStore, pKey);
        if (lEntry != NULL) {
            lEntry->mType = StoreType_Char;
            lEntry->mValue.mChar = pChar;
        }
    }

    JNIEXPORT jdouble JNICALL
    Java_com_packtub_Store_getDouble(JNIEnv *pEnv, jobject pThis, jstring pKey) {
        StoreEntry *lEntry = findEntry(pEnv, &mStore, pKey);
        if (isEntryValid(pEnv, lEntry, StoreType_Double)) {
            return lEntry->mValue.mDouble;
        }
        else {
            return 0;
        }
    }

    JNIEXPORT void JNICALL
    Java_com_packtub_Store_setDouble(JNIEnv *pEnv, jobject pThis, jstring pKey, jdouble pDouble) {
        StoreEntry *lEntry = allocateEntry(pEnv, &mStore, pKey);
        if (lEntry != NULL) {
            lEntry->mType = StoreType_Double;
            lEntry->mValue.mDouble = pDouble;
        }
    }

    JNIEXPORT jfloat JNICALL
    Java_com_packtub_Store_getFloat(JNIEnv *pEnv, jobject pThis, jstring pKey) {
        StoreEntry *lEntry = findEntry(pEnv, &mStore, pKey);
        if (isEntryValid(pEnv, lEntry, StoreType_Float)) {
            return lEntry->mValue.mFloat;
        }
        else {
            return 0;
        }
    }

    JNIEXPORT void JNICALL
    Java_com_packtub_Store_setFloat(JNIEnv *pEnv, jobject pThis, jstring pKey, jfloat pFloat) {
        StoreEntry *lEntry = allocateEntry(pEnv, &mStore, pKey);
        if (lEntry != NULL) {
            lEntry->mType = StoreType_Float;
            lEntry->mValue.mFloat = pFloat;
        }
    }

    JNIEXPORT jlong JNICALL
    Java_com_packtub_Store_getLong(JNIEnv *pEnv, jobject pThis, jstring pKey) {
        StoreEntry *lEntry = findEntry(pEnv, &mStore, pKey);
        if (isEntryValid(pEnv, lEntry, StoreType_Long)) {
            return lEntry->mValue.mLong;
        }
        else {
            return 0;
        }
    }

    JNIEXPORT void JNICALL
    Java_com_packtub_Store_setLong(JNIEnv *pEnv, jobject pThis, jstring pKey, jlong pLong) {
        StoreEntry *lEntry = allocateEntry(pEnv, &mStore, pKey);
        if (lEntry != NULL) {
            lEntry->mType = StoreType_Long;
            lEntry->mValue.mLong = pLong;
        }
    }

    JNIEXPORT jshort JNICALL
    Java_com_packtub_Store_getShort(JNIEnv *pEnv, jobject pThis, jstring pKey) {
        StoreEntry *lEntry = findEntry(pEnv, &mStore, pKey);
        if (isEntryValid(pEnv, lEntry, StoreType_Short)) {
            return lEntry->mValue.mShort;
        }
        else {
            return 0;
        }
    }

    JNIEXPORT void JNICALL
    Java_com_packtub_Store_setShort(JNIEnv *pEnv, jobject pThis, jstring pKey, jshort pShort) {
        StoreEntry *lEntry = allocateEntry(pEnv, &mStore, pKey);
        if (lEntry != NULL) {
            lEntry->mType = StoreType_Short;
            lEntry->mValue.mShort = pShort;
        }
    }

    JNIEXPORT jobject JNICALL
    Java_com_packtub_Store_getColor(JNIEnv *pEnv, jobject pThis, jstring pKey) {
        StoreEntry *lEntry = findEntry(pEnv, &mStore, pKey);
        if (isEntryValid(pEnv, lEntry, StoreType_Color)) {
            return lEntry->mValue.mColor;
        }
        else {
            return NULL;
        }
    }

    JNIEXPORT void JNICALL
    Java_com_packtub_Store_setColor(JNIEnv *pEnv, jobject pThis, jstring pKey, jobject pColor) {
        jobject lColor = pEnv->NewGlobalRef(pColor);
        if (lColor == NULL) {
            return;
        }
        StoreEntry *lEntry = allocateEntry(pEnv, &mStore, pKey);
        if (lEntry == NULL) {
            pEnv->DeleteGlobalRef(lColor);
        }
        else {
            lEntry->mType = StoreType_Color;
            lEntry->mValue.mColor = lColor;
        }
    }

    JNIEXPORT jintArray JNICALL
    Java_com_packtub_Store_getIntArray(JNIEnv *pEnv, jobject pThis, jstring pKey) {
        StoreEntry* lEntry = findEntry(pEnv, &mStore, pKey);
        if(isEntryValid(pEnv, lEntry, StoreType_IntArray)){
            jintArray lJavaArray = pEnv->NewIntArray(lEntry->mLength);
            if (lJavaArray == NULL) {
                return NULL;
            }
            pEnv->SetIntArrayRegion(lJavaArray, 0, lEntry->mLength, lEntry->mValue.mIntArray);
            return lJavaArray;
        }
        return NULL;
    }

    JNIEXPORT void JNICALL
    Java_com_packtub_Store_setIntArray(JNIEnv *pEnv, jobject pThis, jstring pKey, jintArray pIntArray) {
        jsize lLength = pEnv->GetArrayLength(pIntArray);
        int32_t* lArray = new int32_t[lLength * sizeof(int32_t)];
        pEnv->GetIntArrayRegion(pIntArray, 0, lLength, lArray);
        if (pEnv->ExceptionCheck()) {
            delete[] lArray;
            return;
        }
        StoreEntry* lEntry = allocateEntry(pEnv, &mStore, pKey);
        if (lEntry != NULL) {
            lEntry->mType = StoreType_IntArray;
            lEntry->mLength = lLength;
            lEntry->mValue.mIntArray = lArray;
        }
        else {
            delete[] lArray;
            return;
        }
    }

    JNIEXPORT jobjectArray JNICALL
    Java_com_packtub_Store_getColorArray(JNIEnv *pEnv, jobject pThis, jstring pKey) {
        StoreEntry* lEntry = findEntry(pEnv, &mStore, pKey);
        if (isEntryValid(pEnv, lEntry, StoreType_ColorArray)) {
            jclass lColorClass = pEnv->FindClass("com/packtpub/Color");
            if (lColorClass == NULL) {
                return NULL;
            }
            jobjectArray lJavaArray = pEnv->NewObjectArray(lEntry->mLength, lColorClass, NULL);
            pEnv->DeleteLocalRef(lColorClass);
            if (lJavaArray == NULL) {
                return NULL;
            }
            int32_t i;
            for (i = 0; i < lEntry->mLength; ++i) {
                pEnv->SetObjectArrayElement(lJavaArray, i, lEntry->mValue.mColorArray[i]);
                if (pEnv->ExceptionCheck()) {
                    return NULL;
                }
            }
            return lJavaArray;
        }
        else {
            return NULL;
        }
    }

    JNIEXPORT void JNICALL
    Java_com_packtub_Store_setColorArray(JNIEnv *pEnv, jobject pThis, jstring pKey, jobjectArray pColorArray) {
        jsize lLength = pEnv->GetArrayLength(pColorArray);
        jobject* lArray = new jobject[lLength * sizeof(jobject)];
        int32_t i, j;
        for (i = 0; i < lLength; ++i) {
            jobject lLocalColor = pEnv->GetObjectArrayElement(pColorArray, i);
            if (lLocalColor == NULL) {
                for (j = 0; j < i; ++j) {
                    pEnv->DeleteGlobalRef(lArray[j]);
                }
                delete[] lArray;
                return;
            }
            lArray[i] = pEnv->NewGlobalRef(lLocalColor);
            if (lArray[i] == NULL) {
                for (j = 0; j < i; ++j) {
                    pEnv->DeleteGlobalRef(lArray[j]);
                }
                delete[] lArray;
                return;
            }
            pEnv->DeleteLocalRef(lLocalColor);
        }
        StoreEntry* lEntry = allocateEntry(pEnv, &mStore, pKey);
        if (lEntry != NULL) {
            lEntry->mType = StoreType_ColorArray;
            lEntry->mLength = lLength;
            lEntry->mValue.mColorArray = lArray;
        }
        else {
            for (j = 0; j < i; ++j) {
                pEnv->DeleteGlobalRef(lArray[j]);
            }
            delete[] lArray;
            return;
        }
    }

    JNIEXPORT void JNICALL
    Java_com_packtub_Store_setBoolArray(JNIEnv *pEnv, jobject pThis, jstring pKey, jbooleanArray pBoolArray) {
        jsize lLength = pEnv->GetArrayLength(pBoolArray);
        uint8_t* lArray = new uint8_t[lLength * sizeof(uint8_t)];
        pEnv->GetBooleanArrayRegion(pBoolArray, 0, lLength, lArray);
        if (pEnv->ExceptionCheck()) {
            delete[] lArray;
            return;
        }
        StoreEntry* lEntry = allocateEntry(pEnv, &mStore, pKey);
        if (lEntry != NULL) {
            lEntry->mType = StoreType_BoolArray;
            lEntry->mLength = lLength;
            lEntry->mValue.mBoolArray = lArray;
        }
        else {
            delete[] lArray;
            return;
        }
    }

    JNIEXPORT jbooleanArray JNICALL
    Java_com_packtub_Store_getBoolArray(JNIEnv *pEnv, jobject pThis, jstring pKey) {
        StoreEntry* lEntry = findEntry(pEnv, &mStore, pKey);
        if(isEntryValid(pEnv, lEntry, StoreType_BoolArray)){
            jbooleanArray lJavaArray = pEnv->NewBooleanArray(lEntry->mLength);
            if (lJavaArray == NULL) {
                return NULL;
            }
            pEnv->SetBooleanArrayRegion(lJavaArray, 0, lEntry->mLength, lEntry->mValue.mBoolArray);
            return lJavaArray;
        }
        return NULL;
    }

    JNIEXPORT void JNICALL
    Java_com_packtub_Store_setByteArray(JNIEnv *pEnv, jobject pThis, jstring pKey, jbyteArray pByteArray) {
        jsize lLength = pEnv->GetArrayLength(pByteArray);
        int8_t* lArray = new int8_t[lLength * sizeof(int8_t)];
        pEnv->GetByteArrayRegion(pByteArray, 0, lLength, lArray);
        if (pEnv->ExceptionCheck()) {
            delete[] lArray;
            return;
        }
        StoreEntry* lEntry = allocateEntry(pEnv, &mStore, pKey);
        if (lEntry != NULL) {
            lEntry->mType = StoreType_ByteArray;
            lEntry->mLength = lLength;
            lEntry->mValue.mByteArray = lArray;
        }
        else {
            delete[] lArray;
            return;
        }
    }

    JNIEXPORT jbyteArray JNICALL
    Java_com_packtub_Store_getByteArray(JNIEnv *pEnv, jobject pThis, jstring pKey) {
        StoreEntry* lEntry = findEntry(pEnv, &mStore, pKey);
        if(isEntryValid(pEnv, lEntry, StoreType_ByteArray)){
            jbyteArray lJavaArray = pEnv->NewByteArray(lEntry->mLength);
            if (lJavaArray == NULL) {
                return NULL;
            }
            pEnv->SetByteArrayRegion(lJavaArray, 0, lEntry->mLength, lEntry->mValue.mByteArray);
            return lJavaArray;
        }
        return NULL;
    }

    JNIEXPORT void JNICALL
    Java_com_packtub_Store_setCharArray(JNIEnv *pEnv, jobject pThis, jstring pKey, jcharArray pCharArray) {
        jsize lLength = pEnv->GetArrayLength(pCharArray);
        uint16_t* lArray = new uint16_t[lLength * sizeof(uint16_t)];
        pEnv->GetCharArrayRegion(pCharArray, 0, lLength, lArray);
        if (pEnv->ExceptionCheck()) {
            delete[] lArray;
            return;
        }
        StoreEntry* lEntry = allocateEntry(pEnv, &mStore, pKey);
        if (lEntry != NULL) {
            lEntry->mType = StoreType_CharArray;
            lEntry->mLength = lLength;
            lEntry->mValue.mCharArray = lArray;
        }
        else {
            delete[] lArray;
            return;
        }
    }

    JNIEXPORT jcharArray JNICALL
    Java_com_packtub_Store_getCharArray(JNIEnv *pEnv, jobject pThis, jstring pKey) {
        StoreEntry* lEntry = findEntry(pEnv, &mStore, pKey);
        if(isEntryValid(pEnv, lEntry, StoreType_CharArray)){
            jcharArray lJavaArray = pEnv->NewCharArray(lEntry->mLength);
            if (lJavaArray == NULL) {
                return NULL;
            }
            pEnv->SetCharArrayRegion(lJavaArray, 0, lEntry->mLength, lEntry->mValue.mCharArray);
            return lJavaArray;
        }
        return NULL;
    }

    JNIEXPORT void JNICALL
    Java_com_packtub_Store_setDoubleArray(JNIEnv *pEnv, jobject pThis, jstring pKey, jdoubleArray pDoubleArray) {
        jsize lLength = pEnv->GetArrayLength(pDoubleArray);
        double* lArray = new double[lLength * sizeof(double)];
        pEnv->GetDoubleArrayRegion(pDoubleArray, 0, lLength, lArray);
        if (pEnv->ExceptionCheck()) {
            delete[] lArray;
            return;
        }
        StoreEntry* lEntry = allocateEntry(pEnv, &mStore, pKey);
        if (lEntry != NULL) {
            lEntry->mType = StoreType_DoubleArray;
            lEntry->mLength = lLength;
            lEntry->mValue.mDoubleArray = lArray;
        }
        else {
            delete[] lArray;
            return;
        }
    }

    JNIEXPORT jdoubleArray JNICALL
    Java_com_packtub_Store_getDoubleArray(JNIEnv *pEnv, jobject pThis, jstring pKey) {
        StoreEntry* lEntry = findEntry(pEnv, &mStore, pKey);
        if(isEntryValid(pEnv, lEntry, StoreType_DoubleArray)){
            jdoubleArray lJavaArray = pEnv->NewDoubleArray(lEntry->mLength);
            if (lJavaArray == NULL) {
                return NULL;
            }
            pEnv->SetDoubleArrayRegion(lJavaArray, 0, lEntry->mLength, lEntry->mValue.mDoubleArray);
            return lJavaArray;
        }
        return NULL;
    }

    JNIEXPORT void JNICALL
    Java_com_packtub_Store_setFloatArray(JNIEnv *pEnv, jobject pThis, jstring pKey, jfloatArray pFloatArray) {
        jsize lLength = pEnv->GetArrayLength(pFloatArray);
        float* lArray = new float[lLength * sizeof(float)];
        pEnv->GetFloatArrayRegion(pFloatArray, 0, lLength, lArray);
        if (pEnv->ExceptionCheck()) {
            delete[] lArray;
            return;
        }
        StoreEntry* lEntry = allocateEntry(pEnv, &mStore, pKey);
        if (lEntry != NULL) {
            lEntry->mType = StoreType_FloatArray;
            lEntry->mLength = lLength;
            lEntry->mValue.mFloatArray = lArray;
        }
        else {
            delete[] lArray;
            return;
        }
    }

    JNIEXPORT jfloatArray JNICALL
    Java_com_packtub_Store_getFloatArray(JNIEnv *pEnv, jobject pThis, jstring pKey) {
        StoreEntry* lEntry = findEntry(pEnv, &mStore, pKey);
        if(isEntryValid(pEnv, lEntry, StoreType_FloatArray)){
            jfloatArray lJavaArray = pEnv->NewFloatArray(lEntry->mLength);
            if (lJavaArray == NULL) {
                return NULL;
            }
            pEnv->SetFloatArrayRegion(lJavaArray, 0, lEntry->mLength, lEntry->mValue.mFloatArray);
            return lJavaArray;
        }
        return NULL;
    }

    JNIEXPORT void JNICALL
    Java_com_packtub_Store_setLongArray(JNIEnv *pEnv, jobject pThis, jstring pKey, jlongArray pLongArray) {
        jsize lLength = pEnv->GetArrayLength(pLongArray);
        int64_t* lArray = new int64_t[lLength * sizeof(int64_t)];
        pEnv->GetLongArrayRegion(pLongArray, 0, lLength, lArray);
        if (pEnv->ExceptionCheck()) {
            delete[] lArray;
            return;
        }
        StoreEntry* lEntry = allocateEntry(pEnv, &mStore, pKey);
        if (lEntry != NULL) {
            lEntry->mType = StoreType_LongArray;
            lEntry->mLength = lLength;
            lEntry->mValue.mLongArray = lArray;
        }
        else {
            delete[] lArray;
            return;
        }
    }

    JNIEXPORT jlongArray JNICALL
    Java_com_packtub_Store_getLongArray(JNIEnv *pEnv, jobject pThis, jstring pKey) {
        StoreEntry* lEntry = findEntry(pEnv, &mStore, pKey);
        if(isEntryValid(pEnv, lEntry, StoreType_LongArray)){
            jlongArray lJavaArray = pEnv->NewLongArray(lEntry->mLength);
            if (lJavaArray == NULL) {
                return NULL;
            }
            pEnv->SetLongArrayRegion(lJavaArray, 0, lEntry->mLength, lEntry->mValue.mLongArray);
            return lJavaArray;
        }
        return NULL;
    }

    JNIEXPORT void JNICALL
    Java_com_packtub_Store_setShortArray(JNIEnv *pEnv, jobject pThis, jstring pKey, jshortArray pShortArray) {
        jsize lLength = pEnv->GetArrayLength(pShortArray);
        int16_t* lArray = new int16_t[lLength * sizeof(int16_t)];
        pEnv->GetShortArrayRegion(pShortArray, 0, lLength, lArray);
        if (pEnv->ExceptionCheck()) {
            delete[] lArray;
            return;
        }
        StoreEntry* lEntry = allocateEntry(pEnv, &mStore, pKey);
        if (lEntry != NULL) {
            lEntry->mType = StoreType_ShortArray;
            lEntry->mLength = lLength;
            lEntry->mValue.mShortArray = lArray;
        }
        else {
            delete[] lArray;
            return;
        }
    }

    JNIEXPORT jshortArray JNICALL
    Java_com_packtub_Store_getShortArray(JNIEnv *pEnv, jobject pThis, jstring pKey) {
        StoreEntry* lEntry = findEntry(pEnv, &mStore, pKey);
        if(isEntryValid(pEnv, lEntry, StoreType_ShortArray)){
            jshortArray lJavaArray = pEnv->NewShortArray(lEntry->mLength);
            if (lJavaArray == NULL) {
                return NULL;
            }
            pEnv->SetShortArrayRegion(lJavaArray, 0, lEntry->mLength, lEntry->mValue.mShortArray);
            return lJavaArray;
        }
        return NULL;
    }

    JNIEXPORT void JNICALL
    Java_com_packtub_Store_setStringArray(JNIEnv *pEnv, jobject pThis, jstring pKey, jobjectArray pStringArray) {
        jsize lLength = pEnv->GetArrayLength(pStringArray);
        char** lArray = new char*[lLength * sizeof(char*)];
        int32_t i, j;
        for (i = 0; i < lLength; ++i) {
            jstring obj = (jstring)pEnv->GetObjectArrayElement(pStringArray, i);
            if (obj == NULL) {
                for (j = 0; j < i; ++j) {
                    delete[] lArray[j];
                }
                delete[] lArray;
                return;
            }
            const char* lStringTmp = pEnv->GetStringUTFChars(obj, NULL);
            jsize lStringLength = pEnv->GetStringUTFLength(obj);
            char* lLocalStr = new char[(sizeof(char) * (lStringLength + 1))];
            strcpy(lLocalStr, lStringTmp);
            lArray[i] = lLocalStr;
            if (lArray[i] == NULL) {
                for (j = 0; j < i; ++j) {
                    delete[] lArray[j];
                }
                delete[] lArray;
                return;
            }
            pEnv->ReleaseStringUTFChars(obj, lStringTmp);
        }
        StoreEntry* lEntry = allocateEntry(pEnv, &mStore, pKey);
        if (lEntry != NULL) {
            lEntry->mType = StoreType_StringArray;
            lEntry->mLength = lLength;
            lEntry->mValue.mStringArray = lArray;
        }
        else {
            for (j = 0; j < i; ++j) {
                delete[] lArray[j];
            }
            delete[] lArray;
            return;
        }
    }

    JNIEXPORT jobjectArray JNICALL
    Java_com_packtub_Store_getStringArray(JNIEnv *pEnv, jobject pThis, jstring pKey) {
        StoreEntry* lEntry = findEntry(pEnv, &mStore, pKey);
        if (isEntryValid(pEnv, lEntry, StoreType_StringArray)) {
            jclass lColorClass = pEnv->FindClass("java/lang/String");
            if (lColorClass == NULL) {
                return NULL;
            }
            jobjectArray lJavaArray = pEnv->NewObjectArray(lEntry->mLength, lColorClass, NULL);
            pEnv->DeleteLocalRef(lColorClass);
            if (lJavaArray == NULL) {
                return NULL;
            }
            int32_t i;
            for (i = 0; i < lEntry->mLength; ++i) {
                jstring str = pEnv->NewStringUTF(lEntry->mValue.mStringArray[i]);
                pEnv->SetObjectArrayElement(lJavaArray, i, str);
                if (pEnv->ExceptionCheck()) {
                    return NULL;
                }
            }
            return lJavaArray;
        }
        else {
            return NULL;
        }
    }

    JNIEXPORT void JNICALL
    Java_com_packtub_Store_initializeStore(JNIEnv *env, jobject instance) {
        mStore.mLength = 0;
        startWatcher(env, &mStoreWatcher, &mStore, instance);
    }

    JNIEXPORT void JNICALL
    Java_com_packtub_Store_finalizeStore(JNIEnv *env, jobject instance) {
        stopWatcher(env, &mStoreWatcher);
        StoreEntry* lEntry = mStore.mEntries;
        StoreEntry* lEntryEnd = lEntry + mStore.mLength;
        while (lEntry < lEntryEnd) {
            if(lEntry != NULL) {
                delete[] lEntry->mKey;
                releaseEntryValue(env, lEntry);
            }
            lEntry++;
        }
        mStore.mLength = 0;
    }
}
#endif //STORE_COM_PACKTUB_STORE_H

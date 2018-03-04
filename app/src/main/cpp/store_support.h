//
// Created by max on 2/21/18.
//

#ifndef _STORE_H_
#define _STORE_H_

#include "jni.h"
#include <stdint.h>
#define STORE_MAX_CAPACITY 16

typedef enum {
    StoreType_Integer, StoreType_String, StoreType_Bool, StoreType_Byte,
    StoreType_Char, StoreType_Double, StoreType_Float, StoreType_Long,
    StoreType_Short, StoreType_Color, StoreType_IntArray, StoreType_StringArray,
    StoreType_BoolArray, StoreType_ByteArray, StoreType_CharArray, StoreType_DoubleArray,
    StoreType_FloatArray, StoreType_LongArray, StoreType_ShortArray, StoreType_ColorArray
} StoreType;

typedef union {
    int32_t mInteger;
    char* mString;
    uint8_t mBool;
    int8_t mByte;
    uint16_t mChar;
    double mDouble;
    float mFloat;
    int64_t mLong;
    int16_t mShort;
    jobject mColor;
    int32_t* mIntArray;
    char** mStringArray;
    uint8_t* mBoolArray;
    int8_t* mByteArray;
    uint16_t* mCharArray;
    double* mDoubleArray;
    float* mFloatArray;
    int64_t* mLongArray;
    int16_t* mShortArray;
    jobject* mColorArray;
} StoreValue;

typedef struct {
    char* mKey;
    StoreType mType;
    StoreValue mValue;
    int32_t mLength; // array
} StoreEntry;

typedef struct {
    StoreEntry mEntries[STORE_MAX_CAPACITY];
    int32_t mLength;
} Store;

int32_t isEntryValid(JNIEnv* pEnv, StoreEntry* pEntry, StoreType pType);

StoreEntry* allocateEntry(JNIEnv* pEnv, Store* pStore, jstring pKey);

StoreEntry* findEntry(JNIEnv* pEnv, Store* pStore, jstring pKey);

void releaseEntryValue(JNIEnv* pEnv, StoreEntry* pEntry);

void throwInvalidTypeException(JNIEnv* pEnv);

void throwNotExistingKeyException(JNIEnv* pEnv);

void throwStoreFullException(JNIEnv* pEnv);

#endif //STORE_STRORE_H

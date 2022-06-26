//
// Created by max on 2/27/18.
//

#ifndef STORE_STOREWATCHER_H
#define STORE_STOREWATCHER_H

#include "store_support.h"
#include "jni.h"
#include "pthread.h"
#include <stdint.h>

#define SLEEP_DURATION 5
#define STATE_OK 0
#define STATE_KO 1

typedef struct {
    Store* mStore;
    JavaVM* mJavaVM;
    jobject mLock;
    pthread_t mThread;
    int32_t mState;

    jobject mColor;
// Классы.
    jclass ClassStore;
    jclass ClassColor;
// Методы.
    jmethodID MethodOnAlertInt;
    jmethodID MethodOnAlertString;
    jmethodID MethodOnAlertColor;
    jmethodID MethodColorEquals;
} StoreWatcher;

void startWatcher(JNIEnv* pEnv, StoreWatcher* pWatcher, Store* pStore, jobject pStoreFront);

void stopWatcher(JNIEnv* pEnv, StoreWatcher* pWatcher);

void deleteGlobalRef(JNIEnv* pEnv, jobject* pRef);

JNIEnv* getJNIEnv(JavaVM* pJavaVM);

void* runWatcher(void* pArgs);

void processEntry(JNIEnv* pEnv, StoreWatcher* pWatcher, StoreEntry* pEntry);

void makeGlobalRef(JNIEnv* pEnv, jobject* pRef);

void processEntryInt(JNIEnv* pEnv, StoreWatcher* pWatcher, StoreEntry* pEntry);

void processEntryString(JNIEnv* pEnv, StoreWatcher* pWatcher, StoreEntry* pEntry);

void processEntryColor(JNIEnv* pEnv, StoreWatcher* pWatcher, StoreEntry* pEntry);

#endif

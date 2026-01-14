//
// Created by Administrator on 2026/1/7.
//

#include <jni.h>
#include <thread>

#include "Logger/Logger.h"
#include "MainThread.h"

extern "C" jint JNIEXPORT JNI_OnLoad(JavaVM* vm, void *key) {

    LOGI("[+] 进入 JNI_OnLoad");

    JNIEnv *env = nullptr;
    if (vm->GetEnv((void**)&env, JNI_VERSION_1_6) == JNI_OK) {
    //        LOGD("JavaEnv: %p.", env);
    }

    pthread_t hacks;
    pthread_create(&hacks, nullptr, Hack::CheatInitialization, nullptr);


    return JNI_VERSION_1_6;
}
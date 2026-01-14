//
// Created by Administrator on 2026/1/7.
//

#ifndef HOOKEGL_LOGGER_H
#define HOOKEGL_LOGGER_H

#include <android/log.h>

#define TAG "20MinutesTillDawnMod"

#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, TAG, __VA_ARGS__)
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, TAG, __VA_ARGS__)
#define LOGW(...) __android_log_print(ANDROID_LOG_WARN, TAG, __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, TAG, __VA_ARGS__)

#define LOG_SEPARATOR() LOGI("=================================")

#endif //HOOKEGL_LOGGER_H

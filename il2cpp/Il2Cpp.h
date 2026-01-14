//
// Fixed by musk.
//
#pragma once

#include <stdio.h>
#include <android/log.h>
#include <dlfcn.h>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <inttypes.h>
#include <codecvt>
#include <locale>

using namespace std;

#ifndef ML_IL2CPP_H
#define ML_IL2CPP_H

#include "Il2CppType.h"

#define IL2CPP__TAG "li2cpp"
#define IL2CPP_LOGI(...) __android_log_print(ANDROID_LOG_INFO,IL2CPP__TAG,__VA_ARGS__)
#define IL2CPP_LOGD(...) __android_log_print(ANDROID_LOG_DEBUG,IL2CPP__TAG,__VA_ARGS__)
#define IL2CPP_LOGW(...) __android_log_print(ANDROID_LOG_WARN,IL2CPP__TAG,__VA_ARGS__)
#define IL2CPP_LOGE(...) __android_log_print(ANDROID_LOG_ERROR,IL2CPP__TAG,__VA_ARGS__)

extern std::map<std::string, uintptr_t> Fields;
extern std::map<std::string, uintptr_t> Methods;

namespace {
    const void *(*il2cpp_assembly_get_image)(const void *assembly);

    void *(*il2cpp_domain_get)();

    void **(*il2cpp_domain_get_assemblies)(const void *domain, size_t *size);

    const char *(*il2cpp_image_get_name)(void *image);

    void *(*il2cpp_class_from_name)(const void *image, const char *namespaze, const char *name);

    void *(*il2cpp_class_get_field_from_name)(void *klass, const char *name);

    void *(*il2cpp_class_get_method_from_name)(void *klass, const char *name, int argsCount);

    size_t (*il2cpp_field_get_offset)(void *field);

    void (*il2cpp_field_static_get_value)(void *field, void *value);

    void (*il2cpp_field_static_set_value)(void *field, void *value);

    void *(*il2cpp_array_new)(void *elementTypeInfo, size_t length);

    char *(*il2cpp_type_get_name)(void *type);

    void* (*il2cpp_method_get_param)(void *method, uint32_t index);

    void* (*il2cpp_class_get_methods)(void *klass, void* *iter);

    const char* (*il2cpp_method_get_name)(void *method);

    const char *(*il2cpp_class_get_name)(void *klass);

    void *(*il2cpp_class_get_nested_types)(void *, void **);

    void *(*il2cpp_object_new)(void *);

    void *(*il2cpp_runtime_invoke)(void *, void *, void *, void **);
}

namespace Il2Cpp {
    int Attach(const char *libname = "libil2cpp.so");

    void *GetImage(const char *image);

    void *GetClass(const char *image, const char *namespaze, const char *clazz);

    void *CreateArray(const char *image, const char *namespaze, const char *clazz, size_t length);

    void *GetMethodOffset(const char *image, const char *namespaze, const char *clazz, const char *name, int argsCount = 0);

    void *GetMethodOffset(const char *image, const char *namespaze, const char *clazz, const char *name, char **args, int argsCount = 0);

    uintptr_t GetFieldOffset(const char *image, const char *namespaze, const char *clazz, const char *name);

    void GetStaticFieldValue(const char *image, const char *namespaze, const char *clazz, const char *name, void *output);

    void SetStaticFieldValue(const char *image, const char *namespaze, const char *clazz, const char *name, void *value);

    void *NewClassObject(const char *image, const char *namespaze, const char *clazz);

    bool IsAssembliesLoaded();

    template<typename... Args>
    void Il2CppCall(void* method, void* obj, Args... args) {

        // 创建参数数组
        void* paramArray[sizeof...(Args)] = { (void*)args... };
        void* exc = nullptr;

        // 调用 il2cpp_runtime_invoke
        il2cpp_runtime_invoke(method, obj, sizeof...(Args) ? paramArray : nullptr, &exc);

        if (exc) {
            IL2CPP_LOGE("Il2CppCall exception occurred!");
            // 可以考虑再调用 il2cpp_print_exception(exc) 打印
        }
    }
};


template<typename T>
using Array = Il2CppArray<T>;


typedef Il2CppString String;

template<typename T>
using List = Il2CppList<T>;


template<typename K, typename V>
using Dictionary = Il2CppDictionary<K, V>;

void Il2CppGetStaticFieldValue(const char *image, const char *namespaze, const char *clazz, const char *name, void *output);
void *Il2CppGetImageByName(const char *image);
void *Il2CppGetClassType(const char *image, const char *namespaze, const char *clazz);

#endif //ML_IL2CPP_H

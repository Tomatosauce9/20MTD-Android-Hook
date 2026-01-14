//
// Created by Administrator on 2026/1/7.
//

#ifndef HOOKEGL_UTILS_H
#define HOOKEGL_UTILS_H

#include <iostream>

namespace utils{
    //寻找模块 例如 libil2cpp.so libUE4.so
    inline uint64_t findLibrary(const char *library) {
        char filename[0xFF] = {0},
                buffer[1024] = {0};
        FILE *fp = NULL;
        uint64_t address = 0;

        sprintf(filename, "/proc/self/maps");

        fp = fopen(filename, "rt");
        if (fp == NULL) {
            perror("fopen");
            goto done;
        }

        while (fgets(buffer, sizeof(buffer), fp)) {
            if (strstr(buffer, library)) {
                address = (uint64_t) strtoul(buffer, NULL, 16);
                goto done;
            }
        }

        done:

        if (fp) {
            fclose(fp);
        }

        return address;
    }
//检查模块是否加载
    inline bool isLibraryLoaded(const char *libraryName) {
        char line[512] = {0};
        FILE *fp = fopen("/proc/self/maps", "rt");
        if (fp != NULL) {
            while (fgets(line, sizeof(line), fp)) {
                if (strstr(line, libraryName))
                    return true;
            }
            fclose(fp);
        }
        return false;
    }
//模块地址 + 偏移量
    inline uint64_t getAbsoluteAddress(const char *libraryName, uint64_t relativeAddr) {
        uint64_t libBase = findLibrary(libraryName);
        if (libBase == 0)
            return 0;
        return (reinterpret_cast<uint64_t>(libBase + relativeAddr));
    }
//判断地址是否合法
    inline bool IsPtrValid(void *ptr) {
        uintptr_t addr = reinterpret_cast<uintptr_t>(ptr);
        return (addr >= 0xFFFFFFFFF) && (addr <= 0x10000000000);
    }
}

#endif //HOOKEGL_UTILS_H

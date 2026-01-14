//
// Created by Administrator on 2026/1/14.
//

#include <thread>

#include "MainThread.h"
#include "Offset.h"
#include "Hook.h"
#include "utils.h"
#include "Logger.h"
#include "Il2Cpp.h"
#include "FeatureManager.h"

void* Hack::CheatInitialization(void*){
    //检查il2cpp.so是否加载
    do {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        LOGD("等待libil2cpp.so 加载");
    } while (!utils::isLibraryLoaded("libil2cpp.so"));
    LOGI("[+] libil2cpp.so加载 成功");

    //获取Il2CppAPI
    if(Il2Cpp::Attach() == -1) return nullptr;
    LOGI("[+] Il2Cpp::Attach 成功");

    //获取偏移
    Offset::Init();
    LOGI("[+] Offset::Init 成功");

    //Hook 游戏函数
    if(!Hook::InitAll()) return nullptr;
    LOGI("[+] Hook::InitAll 成功");

    //调用 FeatureManager 初始化功能模块
    FeatureManager::Init();

    return nullptr;

}
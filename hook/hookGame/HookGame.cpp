//
// Created by Administrator on 2026/1/11.
//

#include "HookGame.h"
#include "dobby.h"
#include "Logger.h"
#include "Il2Cpp.h"
#include "Class.h"
#include "Config.h"
#include "FeatureManager.h"

Config cfg;

void (*orig_AdsManager_ShowIAD)(void* thiz, uint64_t onIADFinishAction, uint64_t adPosition) = nullptr;
void hook_AdsManager_ShowIAD(void* thiz, uint64_t onIADFinishAction, uint64_t adPosition){
    LOGD("hook_AdsManager_ShowIAD ...");

    return orig_AdsManager_ShowIAD(thiz, onIADFinishAction, adPosition);
}

void (*orig_AdsManager_ShowRAD)(void* thiz, uint64_t onIADFinishAction, uint64_t adPosition) = nullptr;
void hook_AdsManager_ShowRAD(void* thiz, uint64_t onIADFinishAction, uint64_t adPosition){
    LOGD("hook_AdsManager_ShowRAD ...");

    return orig_AdsManager_ShowRAD(thiz, onIADFinishAction, adPosition);
}

void (*orig_PlayerController_Update)(PlayerController* thiz) = nullptr;
void hook_PlayerController_Update(PlayerController* thiz){
//    LOGD("hook_PlayerController_Update ...");

    if(cfg.isModifyPlayerData) {

        FeatureManager::Update(thiz);

    }

    return orig_PlayerController_Update(thiz);
}

void (*orig_PlayerXP_GainXP)(PlayerXP* thiz, float amount) = nullptr;
void hook_PlayerXP_GainXP(PlayerXP* thiz, float amount){
//    LOGD("hook_PlayerXP_GainXP ...");
//    LOGD("amount:%f", amount);
    float newAmount = cfg.xPcount;

    return orig_PlayerXP_GainXP(thiz, newAmount);
}

bool GameHook::InitGameHook(){
    int hookFailedNum = 0;

    if(DobbyHook((void*)(Methods["AdsManager::ShowIAD"]), (void*)hook_AdsManager_ShowIAD, (void**)&orig_AdsManager_ShowIAD) == RT_FAILED) {
        LOGE("[-] hook_AdsManager_ShowIAD Hook 失败!");
        ++hookFailedNum;
    }

    if(DobbyHook((void*)(Methods["AdsManager::ShowRAD"]), (void*)hook_AdsManager_ShowRAD, (void**)&orig_AdsManager_ShowRAD) == RT_FAILED) {
        LOGE("[-] hook_AdsManager_ShowRAD Hook 失败!");
        ++hookFailedNum;
    }

    if(DobbyHook((void*)(Methods["PlayerController::Update"]), (void*)hook_PlayerController_Update, (void**)&orig_PlayerController_Update) == RT_FAILED) {
        LOGE("[-] hook_PlayerController_Update Hook 失败!");
        ++hookFailedNum;
    }

    if(DobbyHook((void*)(Methods["PlayerXP::GainXP"]), (void*)hook_PlayerXP_GainXP, (void**)&orig_PlayerXP_GainXP) == RT_FAILED) {
        LOGE("[-] hook_PlayerController_Update Hook 失败!");
        ++hookFailedNum;
    }

    return hookFailedNum == 0;
}


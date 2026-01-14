//
// Created by Administrator on 2026/1/14.
//

#include "SaveMod.h"

#include "Class.h"
#include "Config.h"
#include "utils.h"
#include "Logger.h"

void SaveMod::ModifySave() {
    if (!cfg.isModifyGameData) return;
    //设置金币（重进游戏生效）
    SaveSystem::set_Points(99999999);

    //设置了但不知有什么效果 需要研究
//    SaveSystem::set_watchUnlockHeroCount(100);
//    SaveSystem::set_watchUnlockGunCount(100);
//    SaveSystem::set_watchUnlockDailyGiftCount(100);
//    SaveSystem::set_AdGetRebirthCouponsCount(9999);
//    SaveSystem::set_AdGetTrialCouponsCount(9999);
    //设定签到 需要研究
//    SaveSystem::set_AdNextSignInTime(1);
//    SaveSystem::set_AdSignInTimes(7);
//    SaveSystem::set_SignInTimes(7);
}
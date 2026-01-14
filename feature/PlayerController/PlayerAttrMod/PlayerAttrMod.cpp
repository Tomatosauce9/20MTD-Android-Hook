//
// Created by Administrator on 2026/1/14.
//

#include "PlayerAttrMod.h"
#include "Class.h"
#include "Config.h"
#include "utils.h"
#include "Logger.h"

void PlayerAttrMod::OnUpdate(void* ctx) {
    if(!cfg.isPlayerAttr) return;

    auto player = (PlayerController*)ctx;
    if (!utils::IsPtrValid(player)) return;

    auto characterData = player->loadedCharacter;
    if(!utils::IsPtrValid(characterData)) return;

//    LOGD("characterData->startHP: %d", characterData->startHP);
//    LOGD("characterData->MoveSpeed: %f", characterData->MoveSpeed);
//    LOGD("characterData->ShootMoveSpeedMultiplier: %f", characterData->ShootMoveSpeedMultiplier);


    characterData->startHP = cfg.startHealth;
    characterData->MoveSpeed = cfg.moveSpeed;
    characterData->ShootMoveSpeedMultiplier = cfg.shootMoveSpeedMultiplier;

}
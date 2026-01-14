//
// Created by Administrator on 2026/1/14.
//

#include "GunMod.h"
#include "Class.h"
#include "Config.h"
#include "utils.h"
#include "Logger.h"

void GunMod::OnUpdate(void* ctx) {
    if (!cfg.isGun) return;

    auto player = (PlayerController*)ctx;
    if (!utils::IsPtrValid(player)) return;

    auto ammo = player->ammo;
    if (!utils::IsPtrValid(ammo)) return;

    auto gun = ammo->gun;
    if (!utils::IsPtrValid(gun)) return;

    auto gunData = gun->k__BackingField;
    if (!utils::IsPtrValid(gunData)) return;


    gunData->damage = cfg.damage;
    gunData->shotCooldown = cfg.shotCooldown;
    gunData->maxAmmo = cfg.maxAmmo;
    gunData->reloadDuration = cfg.reloadDuration;
    gunData->numOfProjectiles = cfg.numOfProjectiles;
    gunData->spread = cfg.spread;
    gunData->knockback = cfg.knockback;
    gunData->projectileSpeed = cfg.projectileSpeed;
    gunData->bounce = cfg.bounce;
    gunData->piercing = cfg.piercing;
    gunData->inaccuracy = cfg.inaccuracy;

//    LOGD("damage: %f", gunData->damage);
//    LOGD("shotCooldown: %f", gunData->shotCooldown);
//    LOGD("maxAmmo: %d", gunData->maxAmmo);
//    LOGD("Ammo: %d", ammo->amount);
//    LOGD("reloadDuration: %f", gunData->reloadDuration);
//    LOGD("numOfProjectiles: %d", gunData->numOfProjectiles);
//    LOGD("spread: %f", gunData->spread);
//    LOGD("knockback: %f", gunData->knockback);
//    LOGD("projectileSpeed: %f", gunData->projectileSpeed);
//    LOGD("bounce: %d", gunData->bounce);
//    LOGD("piercing: %d", gunData->piercing);
//    LOGD("inaccuracy: %f", gunData->inaccuracy);
}


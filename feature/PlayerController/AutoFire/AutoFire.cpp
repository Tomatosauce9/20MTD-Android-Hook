//
// Created by Administrator on 2026/1/14.
//

#include "AutoFire.h"
#include "Class.h"
#include "Config.h"
#include "utils.h"

void AutoFire::OnUpdate(void* ctx) {
    if (!cfg.isGun) return;

    auto player = (PlayerController*)ctx;
    if (!utils::IsPtrValid(player)) return;

    auto ammo = player->ammo;
    if (!utils::IsPtrValid(ammo)) return;

    auto gun = ammo->gun;
    if (!utils::IsPtrValid(gun)) return;

    if(cfg.autoFire)
        gun->set_isShooting(cfg.autoFire);

}
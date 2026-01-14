//
// Created by Administrator on 2026/1/14.
//

#include "GodMode.h"
#include "Class.h"
#include "Config.h"
#include "utils.h"

void GodMode::OnUpdate(void* ctx) {
    if (!cfg.isHealth) return;

    auto player = (PlayerController*)ctx;
    if (!utils::IsPtrValid(player)) return;

    auto health = player->playerHealth;
    if (!utils::IsPtrValid(health)) return;

    //玩家护盾、血量
    static int lastHP = -1;
    static int lastShieldHP = -1;
    if (cfg.health != lastHP || cfg.shieldHealth != lastShieldHP) {

        health->set_HP(cfg.health);
        health->set_ShieldHp(cfg.shieldHealth);

//        health->set_maxHP(cfg.healthMax);
//        health->set_ShieldHpMax(cfg.shieldHealthMax);

        health->set_maxHP(cfg.health);
        health->set_ShieldHpMax(cfg.shieldHealth);

        lastHP = cfg.health;
        lastShieldHP = cfg.shieldHealth;
    }

    static bool godModeActive = false;
    if (cfg.isGodMode) {
        health->set_HP(30);
        health->set_ShieldHp(30);

        health->set_maxHP(30);
        health->set_ShieldHpMax(30);

        godModeActive = true;
    } else if (godModeActive) {
        health->set_HP(cfg.health);
        health->set_ShieldHp(cfg.shieldHealth);
        health->set_maxHP(cfg.health);
        health->set_ShieldHpMax(cfg.shieldHealth);

        godModeActive = false;
    }


}

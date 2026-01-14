//
// Created by Administrator on 2026/1/11.
//

#ifndef INC_20MINUTESTILLDAWNMOD_CLASS_H
#define INC_20MINUTESTILLDAWNMOD_CLASS_H

#include <iostream>
#include "Il2Cpp.h"

extern uint64_t Il2CppModule;

class Screen {
public:
    static int get_width() {
        auto get_width = (int (*) ()) uint64_t(Methods["Screen::get_width"]);
        return get_width();
    }

    static int get_height() {
        auto get_height = (int (*) ()) uint64_t(Methods["Screen::get_height"]);
        return get_height();
    }

    static int get_dpi() {
        auto get_dpi = (float (*) ()) uint64_t(Methods["Screen::get_dpi"]);
        return static_cast<int>(get_dpi());
    }
};

class GameSaveData {
public:
    char pad000[0x10];
    int points; // 0x10
};

class SaveSystem {
public:
    static GameSaveData* get_data() {
        auto get_data = (GameSaveData* (*)()) uint64_t(Methods["SaveSystem::get_data"]);
        return get_data();
    }

    static void set_Points(int value) {
        auto set_Points = (void (*)(int)) uint64_t(Methods["SaveSystem::set_Points"]);
        set_Points(value);
    }

    static void set_watchUnlockHeroCount(int value) {
        auto set_watchUnlockHeroCount = (void (*)(int)) uint64_t(Methods["SaveSystem::set_watchUnlockHeroCount"]);
        set_watchUnlockHeroCount(value);
    }

    static void set_watchUnlockGunCount(int value) {
        auto set_watchUnlockGunCount = (void (*)(int)) uint64_t(Methods["SaveSystem::set_watchUnlockGunCount"]);
        set_watchUnlockGunCount(value);
    }

    static void set_watchUnlockDailyGiftCount(int value) {
        auto set_watchUnlockDailyGiftCount = (void (*)(int)) uint64_t(Methods["SaveSystem::set_watchUnlockDailyGiftCount"]);
        set_watchUnlockDailyGiftCount(value);
    }

    static void set_AdGetTrialCouponsCount(int value) {
        auto set_AdGetTrialCouponsCount = (void (*)(int)) uint64_t(Methods["SaveSystem::set_AdGetTrialCouponsCount"]);
        set_AdGetTrialCouponsCount(value);
    }

    static void set_AdGetRebirthCouponsCount(int value) {
        auto set_AdGetRebirthCouponsCount = (void (*)(int)) uint64_t(Methods["SaveSystem::set_AdGetRebirthCouponsCount"]);
        set_AdGetRebirthCouponsCount(value);
    }

    static void set_SignInTimes(int value) {
        auto set_SignInTimes = (void (*)(int)) uint64_t(Methods["SaveSystem::set_SignInTimes"]);
        set_SignInTimes(value);
    }

    static void set_AdNextSignInTime(int value) {
        auto set_AdNextSignInTime = (void (*)(int)) uint64_t(Methods["SaveSystem::set_AdNextSignInTime"]);
        set_AdNextSignInTime(value);
    }

    static void set_AdSignInTimes(int value) {
        auto set_AdSignInTimes = (void (*)(int)) uint64_t(Methods["SaveSystem::set_AdSignInTimes"]);
        set_AdSignInTimes(value);
    }
};

class Health {
public:
    void set_maxHP(int value) {
        auto set_maxHP = (void (*)(Health*, int)) uint64_t(Methods["Health::set_maxHP"]);
        set_maxHP(this, value);
    }

    void set_HP(int value) {
        auto set_HP = (void (*)(Health*,int)) uint64_t(Methods["Health::set_HP"]);
        set_HP(this, value);
    }

    void set_ShieldHp(int value) {
        auto set_ShieldHp = (void (*)(Health*,int)) uint64_t(Methods["Health::set_ShieldHp"]);
        set_ShieldHp(this, value);
    }

    void set_ShieldHpMax(int value) {
        auto set_ShieldHpMax = (void (*)(Health*,int)) uint64_t(Methods["Health::set_ShieldHpMax"]);
        set_ShieldHpMax(this, value);
    }

    void Heal(int value) {
        auto Heal = (void (*)(Health*,int)) uint64_t(Methods["Health::Heal"]);
        Heal(this, value);
    }
};

class GunData {
public:
    char pad000[0x60];
    float damage; //伤害
    float shotCooldown; //冷却
    int maxAmmo; //容量
    float reloadDuration; //换弹时间
    int numOfProjectiles; //射出数量
    float spread; //散射
    float knockback; //击退
    float projectileSpeed; //飞行速度
    int bounce; //弹射
    int piercing; //穿透
    float inaccuracy; //随机偏移
};

class Gun {
public:

    char pad000[0x34];
    GunData *k__BackingField;

    void StartShooting() {
        auto StartShooting = (void (*)(Gun*)) uint64_t(Methods["Gun::StartShooting"]);
        StartShooting(this);
    }

    void StopShooting() {
        auto StopShooting = (void (*)(Gun*)) uint64_t(Methods["Gun::StopShooting"]);
        StopShooting(this);
    }

    void set_isShooting(bool value) {
        auto set_isShooting = (void (*)(Gun*, bool)) uint64_t(Methods["Gun::set_isShooting"]);
        set_isShooting(this, value);
    }
};

class Ammo {
public:
    char pad000[0x1C];
    Gun* gun;
    char pad001[0x1C];
    int amount;
};

class CharacterData {
public:
    char pad000[0x60];
    int startHP;
    float MoveSpeed;
    float ShootMoveSpeedMultiplier;
};

class PlayerController {
public:
    char pad000[0x44];
    Health* playerHealth;
    char pad001[0x8];
    Gun* gun;
    Ammo* ammo;
    char pad002[0x8];
    CharacterData* loadedCharacter;

    static PlayerController* get_Instance() {
        auto get_Instance = (PlayerController* (*)()) uint64_t(Methods["PlayerController::get_Instance"]);
        return get_Instance();
    }
};

class PlayerXP {
public:

};

#endif //INC_20MINUTESTILLDAWNMOD_CLASS_H

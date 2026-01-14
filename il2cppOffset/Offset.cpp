//
// Created by Administrator on 2026/1/14.
//

#include "Offset.h"
#include "Il2Cpp.h"

std::map<std::string, uintptr_t> Fields;
std::map<std::string, uintptr_t> Methods;

void Offset::Init() {
    Methods["Screen::get_width"] = (uintptr_t) Il2Cpp::GetMethodOffset("UnityEngine.CoreModule.dll", "UnityEngine", "Screen", "get_width");
    Methods["Screen::get_height"] = (uintptr_t) Il2Cpp::GetMethodOffset("UnityEngine.CoreModule.dll", "UnityEngine", "Screen", "get_height");
    Methods["Screen::get_dpi"] = (uintptr_t) Il2Cpp::GetMethodOffset("UnityEngine.CoreModule.dll", "UnityEngine", "Screen", "get_dpi");

    Methods["SaveSystem::get_data"] = (uintptr_t) Il2Cpp::GetMethodOffset("Assembly-CSharp.dll", "flanne", "SaveSystem", "get_data");
    Methods["SaveSystem::set_Points"] = (uintptr_t) Il2Cpp::GetMethodOffset("Assembly-CSharp.dll", "flanne", "SaveSystem", "set_Points", 1);
    Methods["SaveSystem::set_watchUnlockHeroCount"] = (uintptr_t) Il2Cpp::GetMethodOffset("Assembly-CSharp.dll", "flanne", "SaveSystem", "set_watchUnlockHeroCount", 1);
    Methods["SaveSystem::set_watchUnlockGunCount"] = (uintptr_t) Il2Cpp::GetMethodOffset("Assembly-CSharp.dll", "flanne", "SaveSystem", "set_watchUnlockGunCount", 1);
    Methods["SaveSystem::set_watchUnlockDailyGiftCount"] = (uintptr_t) Il2Cpp::GetMethodOffset("Assembly-CSharp.dll", "flanne", "SaveSystem", "set_watchUnlockDailyGiftCount", 1);
    Methods["SaveSystem::set_watchUnlockDailyGiftCount"] = (uintptr_t) Il2Cpp::GetMethodOffset("Assembly-CSharp.dll", "flanne", "SaveSystem", "set_watchUnlockDailyGiftCount", 1);
    Methods["SaveSystem::set_AdGetTrialCouponsCount"] = (uintptr_t) Il2Cpp::GetMethodOffset("Assembly-CSharp.dll", "flanne", "SaveSystem", "set_AdGetTrialCouponsCount", 1);
    Methods["SaveSystem::set_AdGetRebirthCouponsCount"] = (uintptr_t) Il2Cpp::GetMethodOffset("Assembly-CSharp.dll", "flanne", "SaveSystem", "set_AdGetRebirthCouponsCount", 1);
    Methods["SaveSystem::set_AdGetRebirthCouponsCount"] = (uintptr_t) Il2Cpp::GetMethodOffset("Assembly-CSharp.dll", "flanne", "SaveSystem", "set_AdGetRebirthCouponsCount", 1);
    Methods["SaveSystem::set_SignInTimes"] = (uintptr_t) Il2Cpp::GetMethodOffset("Assembly-CSharp.dll", "flanne", "SaveSystem", "set_SignInTimes", 1);
    Methods["SaveSystem::set_AdNextSignInTime"] = (uintptr_t) Il2Cpp::GetMethodOffset("Assembly-CSharp.dll", "flanne", "SaveSystem", "set_AdNextSignInTime", 1);
    Methods["SaveSystem::set_AdSignInTimes"] = (uintptr_t) Il2Cpp::GetMethodOffset("Assembly-CSharp.dll", "flanne", "SaveSystem", "set_AdSignInTimes", 1);
    Methods["SaveSystem::IsUnlock"] = (uintptr_t) Il2Cpp::GetMethodOffset("Assembly-CSharp.dll", "flanne", "SaveSystem", "IsUnlock", 1);

    //还没研究
    Methods["AdsManager::OnIADFinish"] = (uintptr_t) Il2Cpp::GetMethodOffset("Assembly-CSharp.dll", "Sauce", "AdsManager", "OnIADFinish", 1);
    Methods["AdsManager::OnRADFinish"] = (uintptr_t) Il2Cpp::GetMethodOffset("Assembly-CSharp.dll", "Sauce", "AdsManager", "OnRADFinish", 1);
    Methods["AdsManager::ShowIAD"] = (uintptr_t) Il2Cpp::GetMethodOffset("Assembly-CSharp.dll", "Sauce", "AdsManager", "ShowIAD", 2);
    Methods["AdsManager::ShowRAD"] = (uintptr_t) Il2Cpp::GetMethodOffset("Assembly-CSharp.dll", "Sauce", "AdsManager", "ShowRAD", 2);

    Methods["Health::set_maxHP"] = (uintptr_t) Il2Cpp::GetMethodOffset("Assembly-CSharp.dll", "flanne", "Health", "set_maxHP", 1);
    Methods["Health::set_HP"] = (uintptr_t) Il2Cpp::GetMethodOffset("Assembly-CSharp.dll", "flanne", "Health", "set_HP", 1);
    Methods["Health::set_ShieldHp"] = (uintptr_t) Il2Cpp::GetMethodOffset("Assembly-CSharp.dll", "flanne", "Health", "set_ShieldHp", 1);
    Methods["Health::set_ShieldHpMax"] = (uintptr_t) Il2Cpp::GetMethodOffset("Assembly-CSharp.dll", "flanne", "Health", "set_ShieldHpMax", 1);
    Methods["Health::Heal"] = (uintptr_t) Il2Cpp::GetMethodOffset("Assembly-CSharp.dll", "flanne", "Health", "Heal", 1);

    Methods["Gun::StartShooting"] = (uintptr_t) Il2Cpp::GetMethodOffset("Assembly-CSharp.dll", "flanne", "Gun", "StartShooting");
    Methods["Gun::StopShooting"] = (uintptr_t) Il2Cpp::GetMethodOffset("Assembly-CSharp.dll", "flanne", "Gun", "StopShooting");
    Methods["Gun::set_isShooting"] = (uintptr_t) Il2Cpp::GetMethodOffset("Assembly-CSharp.dll", "flanne", "Gun", "set_isShooting", 1);
    Methods["Gun::get_shotCooldown"] = (uintptr_t) Il2Cpp::GetMethodOffset("Assembly-CSharp.dll", "flanne", "Gun", "get_shotCooldown");
    Methods["Gun::get_reloadDuration"] = (uintptr_t) Il2Cpp::GetMethodOffset("Assembly-CSharp.dll", "flanne", "Gun", "get_reloadDuration");
    Methods["Gun::get_damage"] = (uintptr_t) Il2Cpp::GetMethodOffset("Assembly-CSharp.dll", "flanne", "Gun", "get_damage");
    Methods["Gun::get_numOfProjectiles"] = (uintptr_t) Il2Cpp::GetMethodOffset("Assembly-CSharp.dll", "flanne", "Gun", "get_numOfProjectiles");
    Methods["Gun::get_spread"] = (uintptr_t) Il2Cpp::GetMethodOffset("Assembly-CSharp.dll", "flanne", "Gun", "get_spread");
    Methods["Gun::get_maxAmmo"] = (uintptr_t) Il2Cpp::GetMethodOffset("Assembly-CSharp.dll", "flanne", "Gun", "get_maxAmmo");
    Methods["Gun::get_maxAmmo"] = (uintptr_t) Il2Cpp::GetMethodOffset("Assembly-CSharp.dll", "flanne", "Gun", "get_maxAmmo");

    Methods["PlayerController::get_Instance"] = (uintptr_t) Il2Cpp::GetMethodOffset("Assembly-CSharp.dll", "flanne", "PlayerController", "get_Instance");
    Methods["PlayerController::Update"] = (uintptr_t) Il2Cpp::GetMethodOffset("Assembly-CSharp.dll", "flanne", "PlayerController", "Update");

    Methods["PlayerXP::GainXP"] = (uintptr_t) Il2Cpp::GetMethodOffset("Assembly-CSharp.dll", "flanne.Player", "PlayerXP", "GainXP", 1);

    Methods["XPPickup::UsePickup"] = (uintptr_t) Il2Cpp::GetMethodOffset("Assembly-CSharp.dll", "flanne.Pickups", "XPPickup", "UsePickup", 1);
}
//
// Created by Administrator on 2026/1/14.
//

#include "FeatureManager.h"

#include "PlayerController/GodMode/GodMode.h"
#include "PlayerController/AutoFire//AutoFire.h"
#include "PlayerController/GunMod/GunMod.h"
#include "PlayerController/PlayerAttrMod//PlayerAttrMod.h"

std::vector<Feature*> FeatureManager::featuresOnUpdate;
std::vector<Feature*> FeatureManager::featuresOnAwake;

void FeatureManager::Init() {
    featuresOnUpdate.push_back(new GodMode());
    featuresOnUpdate.push_back(new AutoFire());
    featuresOnUpdate.push_back(new GunMod());
    featuresOnUpdate.push_back(new PlayerAttrMod());
}

void FeatureManager::Update(void* ctx) {
    for (auto f : featuresOnUpdate) {
        f->OnUpdate(ctx);
    }
}

void FeatureManager::Awake(void* ctx) {
    for (auto f : featuresOnAwake) {
        f->OnAwake(ctx);
    }
}

void FeatureManager::ResetAll() {
    for (auto f : featuresOnUpdate) {
        f->OnReset();
    }
}


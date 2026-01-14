//
// Created by Administrator on 2026/1/14.
//

#ifndef INC_20MINUTESTILLDAWNMOD_GUNMOD_H
#define INC_20MINUTESTILLDAWNMOD_GUNMOD_H

#include "Feature.h"

class GunMod : public Feature {
public:
    const char* GetName() override { return "GunMod"; }
    void OnUpdate(void* ctx) override;
    void OnAwake(void* ctx) override {};
};


#endif //INC_20MINUTESTILLDAWNMOD_GUNMOD_H

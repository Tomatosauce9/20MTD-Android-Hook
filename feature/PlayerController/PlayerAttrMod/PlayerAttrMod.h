//
// Created by Administrator on 2026/1/14.
//

#ifndef INC_20MINUTESTILLDAWNMOD_PLAYERATTR_H
#define INC_20MINUTESTILLDAWNMOD_PLAYERATTR_H

#include "Feature.h"

class PlayerAttrMod : public Feature {
public:
    const char* GetName() override { return "PlayerAttrMod"; }
    void OnUpdate(void* ctx) override;
    void OnAwake(void* ctx) override {};
};


#endif //INC_20MINUTESTILLDAWNMOD_PLAYERATTR_H

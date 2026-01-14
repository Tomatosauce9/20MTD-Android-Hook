//
// Created by Administrator on 2026/1/14.
//

#ifndef INC_20MINUTESTILLDAWNMOD_GODMODE_H
#define INC_20MINUTESTILLDAWNMOD_GODMODE_H


#include "Feature.h"

class GodMode : public Feature {
public:
    const char* GetName() override { return "GodMode"; }
    void OnUpdate(void* ctx) override;
    void OnAwake(void* ctx) override {};
};


#endif //INC_20MINUTESTILLDAWNMOD_GODMODE_H

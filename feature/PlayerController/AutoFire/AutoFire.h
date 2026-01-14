//
// Created by Administrator on 2026/1/14.
//

#ifndef INC_20MINUTESTILLDAWNMOD_AUTOFIRE_H
#define INC_20MINUTESTILLDAWNMOD_AUTOFIRE_H

#include "Feature.h"

class AutoFire : public Feature {
public:
    const char* GetName() override { return "AutoFire"; }
    void OnUpdate(void* ctx) override;
    void OnAwake(void* ctx) override {};
};


#endif //INC_20MINUTESTILLDAWNMOD_AUTOFIRE_H

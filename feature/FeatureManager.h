//
// Created by Administrator on 2026/1/14.
//

#ifndef INC_20MINUTESTILLDAWNMOD_FEATUREMANAGER_H
#define INC_20MINUTESTILLDAWNMOD_FEATUREMANAGER_H

#include "vector"

#include "Feature.h"

class FeatureManager {
public:
    static void Init();
    static void Update(void* ctx);
    static void ResetAll();
    static void Awake(void* ctx);

private:
    static std::vector<Feature*> featuresOnUpdate;
    static std::vector<Feature*> featuresOnAwake;
};


#endif //INC_20MINUTESTILLDAWNMOD_FEATUREMANAGER_H

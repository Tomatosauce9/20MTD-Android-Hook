//
// Created by Administrator on 2026/1/14.
//

#ifndef INC_20MINUTESTILLDAWNMOD_FEATURE_H
#define INC_20MINUTESTILLDAWNMOD_FEATURE_H

class Feature {
public:
    virtual ~Feature() = default;
    virtual const char* GetName() = 0;

    virtual void OnUpdate(void* ctx) = 0;

    virtual void OnAwake(void* ctx) = 0;

    virtual void OnReset() {}
};


#endif //INC_20MINUTESTILLDAWNMOD_FEATURE_H

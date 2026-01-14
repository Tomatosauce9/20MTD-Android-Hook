//
// Created by Administrator on 2026/1/11.
//

#ifndef INC_20MINUTESTILLDAWNMOD_HOOKGAME_H
#define INC_20MINUTESTILLDAWNMOD_HOOKGAME_H

#include <iostream>

class PlayerController;
class PlayerXP;

extern void (*orig_AdsManager_ShowIAD)(void* thiz, uint64_t onIADFinishAction, uint64_t adPosition);
extern void (*orig_AdsManager_ShowRAD)(void* thiz, uint64_t onIADFinishAction, uint64_t adPosition);
extern void (*orig_PlayerController_Update)(PlayerController* thiz);
extern void (*orig_PlayerXP_GainXP)(PlayerXP* thiz, float amount);

namespace GameHook {
    bool InitGameHook();
}




#endif //INC_20MINUTESTILLDAWNMOD_HOOKGAME_H

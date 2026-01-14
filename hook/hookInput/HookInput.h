//
// Created by Administrator on 2026/1/14.
//

#ifndef INC_20MINUTESTILLDAWNMOD_HOOKINPUT_H
#define INC_20MINUTESTILLDAWNMOD_HOOKINPUT_H

extern float screenWidth, screenHeight;

extern void (*orig_initializeMotionEvent)(void *a1, void *a2, void *a3);

namespace HookInput {
    bool InitInputHook();
}

#endif //INC_20MINUTESTILLDAWNMOD_HOOKINPUT_H

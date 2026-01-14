//
// Created by Administrator on 2026/1/11.
//

#ifndef INC_20MINUTESTILLDAWNMOD_HOOKEGL_H
#define INC_20MINUTESTILLDAWNMOD_HOOKEGL_H

#include <EGL/egl.h>


extern int glWidth, glHeight;

extern EGLBoolean(*orig_eglSwapBuffers) (EGLDisplay dpy, EGLSurface surface);

namespace HookEGL {
    bool InitEGLHook();
}

#endif //INC_20MINUTESTILLDAWNMOD_HOOKEGL_H

//
// Created by Administrator on 2026/1/11.
//

#include "HookEGL.h"
#include "Logger.h"
#include "xdl.h"
#include "dobby.h"
#include "Menu.h"

int glWidth = -1, glHeight = -1;

EGLBoolean(*orig_eglSwapBuffers) (EGLDisplay dpy, EGLSurface surface) = nullptr;
EGLBoolean hook_eglSwapBuffers(EGLDisplay dpy, EGLSurface surface)
{
    eglQuerySurface(dpy, surface, EGL_WIDTH, &glWidth);
    eglQuerySurface(dpy, surface, EGL_HEIGHT, &glHeight);


    if (!menu::initImGui)
        menu::setUpImGui(glWidth, glHeight);

    menu::IMenu(glWidth, glHeight);

    return orig_eglSwapBuffers(dpy, surface);
}

bool HookEGL::InitEGLHook() {

    //进行 EGL Hook 前置操作
    //打开so
    void *handle_egl = xdl_open("libEGL.so", XDL_DEFAULT);

    if (handle_egl == nullptr) {
        LOGE("[-] 加载失败!");
        LOGE("[-] handle_egl:%lx", handle_egl);
        return false;
    }

    //透过符号获取函数地址
    void *xdl_sym_egl = xdl_sym(handle_egl, "eglSwapBuffers", nullptr);

    if (xdl_sym_egl == nullptr) {
        LOGE("[-] 获取失败!");
        LOGE("[-] xdl_sym_egl:%lx", xdl_sym_egl);
        return false;
    }

    int hookFailedNum = 0;

    //使用 Hook 框架对函数 Hook
    if (DobbyHook(xdl_sym_egl, (void *) hook_eglSwapBuffers, (void **) &orig_eglSwapBuffers) == RT_FAILED) {
        LOGE("[-] hook_eglSwapBuffers 失败!");
        ++hookFailedNum;
    }

    xdl_close(handle_egl);

    return hookFailedNum  == 0;
}


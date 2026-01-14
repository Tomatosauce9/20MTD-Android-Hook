//
// Created by Administrator on 2026/1/11.
//

#include "Hook.h"
#include "Logger.h"
#include "hookGame/HookGame.h"
#include "hookEGL/HookEGL.h"
#include "hookInput/HookInput.h"

int Hook::InitAll(){

    if(!HookEGL::InitEGLHook()){
        LOGE("HookEGL::InitEGLHook 失败");
        return false;
    }

    if(!HookInput::InitInputHook()){
        LOGE("HookInput::InitInputHook 失败");
        return false;
    }

    if(!GameHook::InitGameHook()){
        LOGE("GameHook::InitGameHook 失败");
        return false;
    }

    return true;
}


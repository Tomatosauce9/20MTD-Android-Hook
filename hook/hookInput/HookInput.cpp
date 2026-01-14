//
// Created by Administrator on 2026/1/14.
//

#include "HookInput.h"
#include "imgui_impl_android.h"
#include "Customize.h"
#include "Logger.h"
#include "xdl.h"
#include "dobby.h"
#include "Menu.h"
#include "Class.h"
#include "hookEGL/HookEGL.h"

float screenWidth = -1, screenHeight = -1;

void (*orig_initializeMotionEvent)(void *a1, void *a2, void *a3) = nullptr;
void initializeMotionEvent(void *a1, void *a2, void *a3){
    orig_initializeMotionEvent(a1,a2,a3);

    screenWidth = static_cast<float>(Screen::get_width());
    screenHeight = static_cast<float>(Screen::get_height());

    if (menu::initImGui && screenWidth >= 0 || screenHeight >= 0) {
        ImGui_ImplAndroid_HandleInputEvent((AInputEvent *)a1,{screenWidth / glWidth, screenHeight / glHeight});
    }
}

bool HookInput::InitInputHook() {

    //进行 Input Hook 前置操作
    //打开so的
    void *handle_input = xdl_open("libinput.so", XDL_DEFAULT);

    if (handle_input == nullptr) {
        LOGE("[-] 加载失败!");
        LOGE("[-] handle_input:%lx", handle_input);
        return false;
    }

    //透过符号获取函数地址
    void *xdl_sym_input = xdl_sym(handle_input,
                                  "_ZN7android13InputConsumer21initializeMotionEventEPNS_11MotionEventEPKNS_12InputMessageE",
                                  nullptr);

    if (xdl_sym_input == nullptr) {
        LOGE("[-] 获取失败!");
        LOGE("[-] xdl_sym_input:%lx", xdl_sym_input);
        return false;
    }

    int hookFailedNum = 0;

    if (DobbyHook(xdl_sym_input, (void *) initializeMotionEvent, (void **) &orig_initializeMotionEvent) == RT_FAILED){
        LOGE("[-] initializeMotionEvent 失败!");
        ++hookFailedNum;
    }

    xdl_close(handle_input);

    return hookFailedNum  == 0;
}
//
// Created by Administrator on 2026/1/7.
//

#ifndef HOOKEGL_CUSTOMIZE_H
#define HOOKEGL_CUSTOMIZE_H

#include <map>
#include <queue>
#include "imgui_impl_android.h"

extern std::map<int32_t, std::queue<int32_t>> g_KeyEventQueues;

IMGUI_IMPL_API int32_t ImGui_ImplAndroid_HandleInputEvent(AInputEvent *input_event, ImVec2 screen_scale);
IMGUI_IMPL_API void     ImGui_ImplAndroid_NewFrame(int32_t window_width,int32_t window_height);

#endif //HOOKEGL_CUSTOMIZE_H

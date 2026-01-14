//
// Created by Administrator on 2026/1/7.
//

#include <android/input.h>
#include "Customize.h"

std::map<int32_t, std::queue<int32_t>> g_KeyEventQueues; // FIXME: Remove dependency on map and queue once we use upcoming input queue.

int32_t ImGui_ImplAndroid_HandleInputEvent(AInputEvent *input_event, ImVec2 screen_scale) {
    ImGuiIO &io = ImGui::GetIO();
    int32_t event_type = AInputEvent_getType(input_event);
    switch (event_type) {
        case AINPUT_EVENT_TYPE_KEY: {
            int32_t event_key_code = AKeyEvent_getKeyCode(input_event);
            int32_t event_action = AKeyEvent_getAction(input_event);
            int32_t event_meta_state = AKeyEvent_getMetaState(input_event);

            io.KeyCtrl = ((event_meta_state & AMETA_CTRL_ON) != 0);
            io.KeyShift = ((event_meta_state & AMETA_SHIFT_ON) != 0);
            io.KeyAlt = ((event_meta_state & AMETA_ALT_ON) != 0);

            switch (event_action) {
                // FIXME: AKEY_EVENT_ACTION_DOWN and AKEY_EVENT_ACTION_UP occur at once as soon as a touch pointer
                // goes up from a key. We use a simple key event queue/ and process one event per key per frame in
                // ImGui_ImplAndroid_NewFrame()...or consider using IO queue, if suitable: https://github.com/ocornut/imgui/issues/2787
                case AKEY_EVENT_ACTION_DOWN:
                case AKEY_EVENT_ACTION_UP:
                    g_KeyEventQueues[event_key_code].push(event_action);
                    break;
                default:
                    break;
            }
            break;
        }
        case AINPUT_EVENT_TYPE_MOTION: {
            int32_t event_action = AMotionEvent_getAction(input_event);
            int32_t event_pointer_index = (event_action & AMOTION_EVENT_ACTION_POINTER_INDEX_MASK) >> AMOTION_EVENT_ACTION_POINTER_INDEX_SHIFT;
            event_action &= AMOTION_EVENT_ACTION_MASK;
            switch (event_action) {
                case AMOTION_EVENT_ACTION_DOWN:
                case AMOTION_EVENT_ACTION_UP:
                    // Physical mouse buttons (and probably other physical devices) also invoke the actions AMOTION_EVENT_ACTION_DOWN/_UP,
                    // but we have to process them separately to identify the actual button pressed. This is done below via
                    // AMOTION_EVENT_ACTION_BUTTON_PRESS/_RELEASE. Here, we only process "FINGER" input (and "UNKNOWN", as a fallback).
                    if ((AMotionEvent_getToolType(input_event, event_pointer_index) == AMOTION_EVENT_TOOL_TYPE_FINGER) || (AMotionEvent_getToolType(input_event, event_pointer_index) == AMOTION_EVENT_TOOL_TYPE_UNKNOWN)) {
                        io.MouseDown[0] = (event_action == AMOTION_EVENT_ACTION_DOWN);
                        ImVec2 pos(AMotionEvent_getRawX(input_event, event_pointer_index), AMotionEvent_getRawY(input_event, event_pointer_index));
                        io.MousePos = ImVec2(screen_scale.x > 0 ? pos.x / screen_scale.x : pos.x, screen_scale.y > 0 ? pos.y / screen_scale.y : pos.y);
                    }
                    break;
                case AMOTION_EVENT_ACTION_BUTTON_PRESS:
                case AMOTION_EVENT_ACTION_BUTTON_RELEASE: {
                    int32_t button_state = AMotionEvent_getButtonState(input_event);
                    io.MouseDown[0] = ((button_state & AMOTION_EVENT_BUTTON_PRIMARY) != 0);
                    io.MouseDown[1] = ((button_state & AMOTION_EVENT_BUTTON_SECONDARY) != 0);
                    io.MouseDown[2] = ((button_state & AMOTION_EVENT_BUTTON_TERTIARY) != 0);
                }
                    break;
                case AMOTION_EVENT_ACTION_HOVER_MOVE: // Hovering: Tool moves while NOT pressed (such as a physical mouse)
                case AMOTION_EVENT_ACTION_MOVE: {       // Touch pointer moves while DOWN
                    ImVec2 pos(AMotionEvent_getRawX(input_event, event_pointer_index), AMotionEvent_getRawY(input_event, event_pointer_index));
                    io.MousePos = ImVec2(screen_scale.x > 0 ? pos.x / screen_scale.x : pos.x, screen_scale.y > 0 ? pos.y / screen_scale.y : pos.y);
                    break;
                }
                case AMOTION_EVENT_ACTION_SCROLL:
                    io.MouseWheel = AMotionEvent_getAxisValue(input_event,AMOTION_EVENT_AXIS_VSCROLL,event_pointer_index);
                    io.MouseWheelH = AMotionEvent_getAxisValue(input_event,AMOTION_EVENT_AXIS_HSCROLL,event_pointer_index);
                    break;
                default:
                    break;
            }
        }
            return 1;
        default:
            break;
    }

    return 0;
}

static double                                   g_Time = 0.0;

void ImGui_ImplAndroid_NewFrame(int32_t window_width,int32_t window_height)
{
    ImGuiIO& io = ImGui::GetIO();

    // Setup display size (every frame to accommodate for window resizing)
    //int32_t window_width = ANativeWindow_getWidth(g_Window);
    //int32_t window_height = ANativeWindow_getHeight(g_Window);
    int display_width = window_width;
    int display_height = window_height;

    io.DisplaySize = ImVec2((float)window_width, (float)window_height);
    if (window_width > 0 && window_height > 0)
        io.DisplayFramebufferScale = ImVec2((float)display_width / window_width, (float)display_height / window_height);

    // Setup time step
    struct timespec current_timespec;
    clock_gettime(CLOCK_MONOTONIC, &current_timespec);
    double current_time = (double)(current_timespec.tv_sec) + (current_timespec.tv_nsec / 1000000000.0);
    io.DeltaTime = g_Time > 0.0 ? (float)(current_time - g_Time) : (float)(1.0f / 60.0f);
    g_Time = current_time;
}
//
// Created by Administrator on 2026/1/11.
//

#ifndef INC_20MINUTESTILLDAWNMOD_MENU_H
#define INC_20MINUTESTILLDAWNMOD_MENU_H

#include "imgui.h"
#include "imgui_impl_opengl3.h"
#include "imgui_internal.h"
#include "Customize.h"
#include "Font.h"
#include "Config.h"
#include "SaveMod/SaveMod.h"

namespace menu {
    static bool initImGui = false;

    //初始化ImGui
    inline void setUpImGui(int glWidth, int glHeight){
        ImGui::CreateContext();
        ImGuiIO & io = ImGui::GetIO();
        io.IniFilename = NULL;
        ImGui::StyleColorsClassic();
        ImGui_ImplOpenGL3_Init("#version 300 es");
        ImFontConfig font_cfg;
        font_cfg.SizePixels = 16.0f;
        io.Fonts->AddFontFromMemoryTTF((void *)OPPOSans_H, OPPOSans_H_size, 32.0f, NULL,io.Fonts->GetGlyphRangesChineseFull());
        io.Fonts->AddFontDefault(&font_cfg);
        ImGui::GetStyle().ScaleAllSizes(3.0f);
        ImGui::GetStyle().WindowMinSize = ImVec2(static_cast<float>(glHeight)*0.75f, static_cast<float>(glWidth)*0.20f);	// 设置窗口高宽
        LOGI("[+] setUpImGui done!");
        initImGui = true;
    }

    inline void IMenu(int glWidth, int glHeight) {
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplAndroid_NewFrame(glWidth, glHeight);
        ImGui::NewFrame();

        ImGui::SetNextWindowSize(ImVec2(500, 500), ImGuiCond_FirstUseEver);
        ImGui::Begin("Tomatosauce9");

        if (ImGui::BeginTabBar("功能 Tabs")) {

            if (ImGui::BeginTabItem("大厅修改")) {
                ImGui::Checkbox("开启大厅修改[修改后重启游戏]", &cfg.isModifyGameData);

                SaveMod::ModifySave();

                ImGui::EndTabItem();
            }

            if (ImGui::BeginTabItem("对局修改")) {
                ImGui::Checkbox("开启对局修改", &cfg.isModifyPlayerData);

                if (cfg.isModifyPlayerData) {

                    //--------- 血量修改 ---------
                    if (ImGui::CollapsingHeader("血量修改")) {
                        ImGui::Checkbox("启用血量修改", &cfg.isHealth);
                        if (cfg.isHealth) {
                            ImGui::Checkbox("无敌模式", &cfg.isGodMode);
                            ImGui::SliderInt("当前血量", &cfg.health, 4, 30);
                            ImGui::SliderInt("当前护盾血量", &cfg.shieldHealth, 0, 30);
                        }
                    }

                    //--------- 武器修改 ---------
                    if (ImGui::CollapsingHeader("武器修改")) {
                        ImGui::Checkbox("启用武器修改", &cfg.isGun);
                        if (cfg.isGun) {
                            ImGui::Checkbox("自动开火[关闭后手动按住开火即可关闭]", &cfg.autoFire);
                            ImGui::SliderFloat("伤害", &cfg.damage, 20.f, 100000.f, "%.f");
                            ImGui::SliderFloat("冷却", &cfg.shotCooldown, 0.f, 1.f, "%.3f");
//                            ImGui::SliderInt("子弹", &cfg.Ammo, 6, 999);
                            ImGui::SliderInt("最大子弹", &cfg.maxAmmo, 6, 999);
                            ImGui::SliderFloat("换弹时间", &cfg.reloadDuration, 1.f, 0.f, "%.3f");
                            ImGui::SliderInt("射出数量", &cfg.numOfProjectiles, 1, 50);
                            ImGui::SliderFloat("散射", &cfg.spread, 0.f, 10.f, "%.3f");
                            ImGui::SliderFloat("击退", &cfg.knockback, 2.f, 30.f, "%.3f");
                            ImGui::SliderFloat("飞行速度", &cfg.projectileSpeed, 15.f, 300.f, "%.3f");
                            ImGui::SliderInt("弹射", &cfg.bounce, 0, 30);
                            ImGui::SliderInt("穿透", &cfg.piercing, 0, 30);
                            ImGui::SliderFloat("随机偏移", &cfg.inaccuracy, 0.f, 30.f, "%.3f");
                        }
                    }

                }

                ImGui::EndTabItem();
            }


            if (ImGui::BeginTabItem("玩家属性")) {
                ImGui::Checkbox("启用玩家属性修改", &cfg.isPlayerAttr);
                if (cfg.isPlayerAttr) {
                    ImGui::SliderInt("初始血量[在游戏中死掉一次]", &cfg.startHealth, 5, 30);
                    ImGui::SliderFloat("移动速度", &cfg.moveSpeed, 3.f, 30.f, "%.f");
                    ImGui::SliderFloat("射击移动速度", &cfg.shootMoveSpeedMultiplier, 0.35f, 30.f, "%.3f");
                    ImGui::SliderFloat("经验值", &cfg.xPcount, 0.0f, 1000.0f, "%.f");
                }
                ImGui::EndTabItem();
            }

            ImGui::EndTabBar();
        }

        ImGui::End();

        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    }

}


#endif //INC_20MINUTESTILLDAWNMOD_MENU_H

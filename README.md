# 20MTD-Android-Hook

![Build](https://img.shields.io/badge/build-passing-brightgreen?logoColor=%23fff&style=for-the-badge)
![CMake](https://img.shields.io/badge/CMake-3.29-blue?logoColor=%23fff&style=for-the-badge)
[![License](https://img.shields.io/github/license/Tomatosauce9/20MTD-Android-Hook?logo=github&logoColor=%23fff&style=for-the-badge)](LICENSE)
![Size](https://img.shields.io/github/languages/code-size/Tomatosauce9/20MTD-Android-Hook?style=for-the-badge)
![Open Issues](https://img.shields.io/github/issues/Tomatosauce9/20MTD-Android-Hook?style=for-the-badge)
![Forks](https://img.shields.io/github/forks/Tomatosauce9/20MTD-Android-Hook?style=for-the-badge)

---

一个用于 **Android 游戏 Mod 框架**，基于 **EGL + ImGui + Hook**，支持玩家功能修改、UI 显示以及游戏函数 Hook。  
主要目标平台：**Android ARM64 (arm64-v8a)**  

游戏:
* 20 Minutes Till Dawn (Google Play v6.9)

---

## 🌟 功能 Features

- **玩家控制 PlayerController**
    - 自动开火 (AutoFire)
    - 无敌模式 (GodMode)
    - 武器修改 (GunMod)
    - 玩家属性修改 (PlayerAttrMod)
- **存档功能 SaveMod**
- **Hook 模块**
    - (HookGame / HookInput / HookEGL)
- **UI 显示 (ImGui)**
    - 菜单、字体、调试信息
- **第三方库集成**
    - [Dobby](https://github.com/jmpews/Dobby)
    - [ImGui](https://github.com/ocornut/imgui)
    - [xDL](https://github.com/hexhacking/xDL)

---

## 🛠 编译 Build

### 环境要求 Requirements
- Android NDK (>=21)
- CMake (>=3.18)
- clang / gcc

### 构建步骤 Steps
```bash
mkdir -p build && cd build
cmake .. -G "Ninja" -DCMAKE_TOOLCHAIN_FILE=$NDK/build/cmake/android.toolchain.cmake -DANDROID_ABI=arm64-v8a -DANDROID_NATIVE_API_LEVEL=21
cmake --build . -- -j8
```
或者是使用CLion

## 🚀 使用 Usage

使用 Android Injector
将 .so 文件注入目标游戏
使用 ImGui 菜单开启/关闭功能模块

## ⚠️ 注意事项 Notes
本项目仅用于学习和研究，不得用于非法用途
仅支持 Android ARM64
建议在测试环境中运行，避免破坏游戏数据

---

### 📄 许可证 License

本项目基于 GNU General Public License v3.0 开源发布，使用、修改与分发请遵循 GPL-3.0 协议，详见 LICENSE 文件。
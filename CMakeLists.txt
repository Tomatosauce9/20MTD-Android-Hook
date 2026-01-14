cmake_minimum_required(VERSION 3.29)

set(NDK_PATH C:/AAAA/android-ndk-r29-beta4)

set(CMAKE_SYSTEM_NAME ANDROID)
set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_SYSTEM_VERSION 31)
set(ANDROID_PLATFORM 24)
set(ANDROID_SDK_TOOLS_VERSION 30)
set(ANDROID_ABI arm64-v8a)
set(ANDROID_NDK ${NDK_PATH})
set(CMAKE_TOOLCHAIN_FILE ${NDK_PATH}/build/cmake/android.toolchain.cmake)
set(ANDROID_SDK_ROOT ${NDK_PATH})

project(20MTD-Android-Hook)

set(OUTPUT_DIR ${CMAKE_SOURCE_DIR}/outputs/${ANDROID_ABI}/)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/outputs/${ANDROID_ABI}/)

set(CMAKE_CXX_STANDARD 17)


set(OUTPUTNAME 20MinutesTillDawnMod)

aux_source_directory(third_party/imgui imgui-src)

file(GLOB XDL_SRC "third_party/xdl/*.c")

include_directories(
        ${CMAKE_SOURCE_DIR}/customized
        ${CMAKE_SOURCE_DIR}/fonts
        ${CMAKE_SOURCE_DIR}/third_party/imgui
        ${CMAKE_SOURCE_DIR}/third_party/imgui/backends
        ${CMAKE_SOURCE_DIR}/menu
        ${CMAKE_SOURCE_DIR}/sdk/
        ${CMAKE_SOURCE_DIR}/hook/
        ${CMAKE_SOURCE_DIR}/core/hack/
        ${CMAKE_SOURCE_DIR}/feature/
        ${CMAKE_SOURCE_DIR}/il2cppOffset/
        ${CMAKE_SOURCE_DIR}/utils
        ${CMAKE_SOURCE_DIR}/utils/Logger
        ${CMAKE_SOURCE_DIR}/il2cpp
        ${CMAKE_SOURCE_DIR}/third_party/xdl/include
        ${CMAKE_SOURCE_DIR}/third_party/dobby/include/
)

file(GLOB_RECURSE FILE_SOURCES
        utils/**/*.cpp
        il2cpp/*.cpp
        il2cppOffset/*.cpp
        core/hack/*.cpp
        hook/*.cpp
        hook/**/*.cpp
        feature/*.cpp
        feature/**/*.cpp
)

add_library(dobby STATIC IMPORTED)
set_target_properties(dobby PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/third_party/dobby/libs/libdobby.a)

add_library(
        ${OUTPUTNAME}
        SHARED
        ${imgui-src}
        ${XDL_SRC}
        ${FILE_SOURCES}
        third_party/imgui/backends/imgui_impl_opengl3.cpp
        third_party/imgui/backends/imgui_impl_android.cpp
        customized/Customized.cpp
        core/main.cpp
)

find_library(egl EGL)
find_library(GLESV2_LIB GLESv2)
find_library(LZ_LIB z)

if (${ANDROID_PLATFORM_LEVEL} LESS 12)
    message(FATAL_ERROR "OpenGL 2 is not supported before API level 11 /
                      (currently using ${ANDROID_PLATFORM_LEVEL}).")
    return()
elseif (${ANDROID_PLATFORM_LEVEL} LESS 18)
    add_definitions("-DDYNAMIC_ES3")
    set(GL3STUB_SRC gl3stub.c)
    set(OPENGL_LIB GLESv2)
else ()
    set(OPENGL_LIB GLESv3)
endif (${ANDROID_PLATFORM_LEVEL} LESS 12)

target_link_libraries(
        ${OUTPUTNAME}
        log
        android
        ${egl}
        ${GLESV2_LIB}
        ${LZ_LIB}
        ${OPENGL_LIB}
        dobby
)
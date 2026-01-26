cmake_minimum_required(VERSION 3.16)
project(OmegaEngine LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SDL2_DIR "${CMAKE_SOURCE_DIR}/external/SDL2")
set(SDL2_INCLUDE_DIR "${SDL2_DIR}/include")
set(SDL2_LIB_DIR "${SDL2_DIR}/lib")

add_library(imgui STATIC
    external/imgui/imgui.cpp
    external/imgui/imgui_draw.cpp
    external/imgui/imgui_tables.cpp
    external/imgui/imgui_widgets.cpp
    external/imgui/backends/imgui_impl_sdl2.cpp
    external/imgui/backends/imgui_impl_sdlrenderer2.cpp
)

target_include_directories(imgui PUBLIC
    external/imgui
    external/imgui/backends
    ${SDL2_INCLUDE_DIR}
    ${SDL2_INCLUDE_DIR}/SDL2
)

target_compile_definitions(imgui PUBLIC SDL_MAIN_HANDLED)

add_executable(OmegaEngine
    engine/main.cpp
    engine/core/Application.cpp
    engine/platform/sdl/SDLWindow.cpp
)

target_include_directories(OmegaEngine PRIVATE
    engine
    engine/core
    engine/platform/sdl
    ${SDL2_INCLUDE_DIR}
    ${SDL2_INCLUDE_DIR}/SDL2
    )

target_link_libraries(OmegaEngine PRIVATE
    imgui
    mingw32
    "${SDL2_LIB_DIR}/libSDL2.a"
    "${SDL2_LIB_DIR}/libSDL2main.a"
)

if (WIN32)
    target_link_libraries(OmegaEngine PRIVATE
        user32
        gdi32
        winmm
        imm32
        ole32
        oleaut32
        setupapi
        version
    )
endif()

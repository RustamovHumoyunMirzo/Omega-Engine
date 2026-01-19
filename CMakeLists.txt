cmake_minimum_required(VERSION 3.16)

project(OmegaEngine VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(SDL2_DIR "${CMAKE_SOURCE_DIR}/external/SDL2")
set(SDL2_INCLUDE_DIR "${SDL2_DIR}/include")
set(SDL2_LIB_DIR "${SDL2_DIR}/lib")

add_executable(OmegaEngine
    engine/main.cpp
    engine/core/Application.cpp
    engine/platform/sdl/SDLWindow.cpp
)

target_include_directories(OmegaEngine
    PRIVATE
        engine
        engine/core
        engine/platform
        engine/platform/sdl
        ${SDL2_INCLUDE_DIR}
)

target_link_directories(OmegaEngine
    PRIVATE
        ${SDL2_LIB_DIR}
)

target_link_libraries(OmegaEngine
    PRIVATE
        mingw32
        SDL2main
        SDL2
)

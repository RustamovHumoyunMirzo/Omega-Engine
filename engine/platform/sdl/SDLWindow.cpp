#include "SDL2/SDL.h"
#include "SDLWindow.h"
#include <imgui.h>
#include <backends/imgui_impl_sdl2.h>

bool SDLWindow::Init()
{
    SDL_Init(SDL_INIT_VIDEO);

    m_Window = SDL_CreateWindow(
        "OmegaEngine",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        1280,
        720,
        SDL_WINDOW_SHOWN
    );

    m_Renderer = SDL_CreateRenderer(
        m_Window,
        -1,
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
    );

    return m_Window && m_Renderer;
}

void SDLWindow::PollEvents(bool& running)
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        ImGui_ImplSDL2_ProcessEvent(&event);

        if (event.type == SDL_QUIT)
            running = false;
    }
}

void SDLWindow::SwapBuffers()
{
    SDL_RenderPresent(m_Renderer);
}

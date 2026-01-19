#include "Application.h"
#include "SDLWindow.h"
#include <SDL2/SDL.h>
#include <stdexcept>

Application::Application()
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
        throw std::runtime_error(SDL_GetError());

    SDL_Rect usableBounds;
    SDL_GetDisplayUsableBounds(0, &usableBounds);

    m_Window = std::make_unique<SDLWindow>(
        "Omega Engine",
        usableBounds.w,
        usableBounds.h
    );
    
    m_Window->Maximize();
}

Application::~Application()
{
    SDL_Quit();
}

void Application::Run()
{
    SDL_Window* window =
        static_cast<SDL_Window*>(m_Window->GetNativeHandle());

    SDL_Renderer* renderer = SDL_CreateRenderer(
        window,
        -1,
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
    );

    bool running = true;
    while (running)
    {
        m_Window->PollEvents(running);

        SDL_SetRenderDrawColor(renderer, 25, 25, 25, 255);
        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
}

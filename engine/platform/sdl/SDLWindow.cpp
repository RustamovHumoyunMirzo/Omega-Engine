#include "SDLWindow.h"
#include <SDL2/SDL.h>
#include <stdexcept>

SDLWindow::SDLWindow(const std::string& title, int width, int height)
    : m_Width(width), m_Height(height)
{
    m_Window = SDL_CreateWindow(
        title.c_str(),
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        width,
        height,
        SDL_WINDOW_RESIZABLE
    );

    if (!m_Window)
        throw std::runtime_error(SDL_GetError());
}

SDLWindow::~SDLWindow()
{
    if (m_Window)
        SDL_DestroyWindow(m_Window);
}

void SDLWindow::PollEvents(bool& running)
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_QUIT)
            running = false;

        if (event.type == SDL_WINDOWEVENT &&
            event.window.event == SDL_WINDOWEVENT_CLOSE)
            running = false;
    }
}

void* SDLWindow::GetNativeHandle() const
{
    return static_cast<void*>(m_Window);
}

void SDLWindow::Maximize()
{
    SDL_MaximizeWindow(m_Window);
}

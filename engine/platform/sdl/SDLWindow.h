#pragma once
#include <SDL.h>

class SDLWindow
{
public:
    bool Init();
    void PollEvents(bool& running);
    void SwapBuffers();

    SDL_Window* GetWindow() const { return m_Window; }
    SDL_Renderer* GetRenderer() const { return m_Renderer; }

private:
    SDL_Window* m_Window = nullptr;
    SDL_Renderer* m_Renderer = nullptr;
};

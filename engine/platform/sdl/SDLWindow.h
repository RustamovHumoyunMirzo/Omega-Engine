#pragma once

#include <string>

struct SDL_Window;

class SDLWindow
{
public:
    SDLWindow(const std::string& title, int width, int height);
    ~SDLWindow();

    void PollEvents(bool& running);
    void SwapBuffers();
    void Maximize();

    void* GetNativeHandle() const;

    int GetWidth() const { return m_Width; }
    int GetHeight() const { return m_Height; }

private:
    SDL_Window* m_Window = nullptr;
    int m_Width  = 0;
    int m_Height = 0;
};

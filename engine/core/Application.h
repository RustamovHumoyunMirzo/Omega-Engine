#pragma once
#include "platform/sdl/SDLWindow.h"

class Application
{
public:
    void Run();

private:
    SDLWindow m_Window;
    bool m_Running = true;
};

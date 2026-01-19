#pragma once
#include <memory>
#include "SDLWindow.h"

class SDLWindow;

class Application {
public:
    Application();
    ~Application();

    void Run();

private:
    std::unique_ptr<SDLWindow> m_Window;
};

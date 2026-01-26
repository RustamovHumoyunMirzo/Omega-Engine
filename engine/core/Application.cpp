#include "Application.h"

#include <SDL2/SDL.h>
#include <imgui.h>
#include <backends/imgui_impl_sdl2.h>
#include <backends/imgui_impl_sdlrenderer2.h>

void Application::Run()
{
    m_Window.Init();

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGui::StyleColorsDark();

    ImGui_ImplSDL2_InitForSDLRenderer(
        m_Window.GetWindow(),
        m_Window.GetRenderer()
    );
    ImGui_ImplSDLRenderer2_Init(m_Window.GetRenderer());

    while (m_Running)
    {
        m_Window.PollEvents(m_Running);

        ImGui_ImplSDLRenderer2_NewFrame();
        ImGui_ImplSDL2_NewFrame();
        ImGui::NewFrame();

        ImGui::Begin("OmegaEngine");
        ImGui::Text("SDL2 + ImGui (no bgfx)");
        ImGui::Text("Renderer: SDL_Renderer");
        ImGui::End();

        ImGui::Render();

        SDL_SetRenderDrawColor(
            m_Window.GetRenderer(), 25, 25, 25, 255
        );
        SDL_RenderClear(m_Window.GetRenderer());

        ImGui_ImplSDLRenderer2_RenderDrawData(
            ImGui::GetDrawData(),
            m_Window.GetRenderer()
        );

        m_Window.SwapBuffers();
    }

    ImGui_ImplSDLRenderer2_Shutdown();
    ImGui_ImplSDL2_Shutdown();
    ImGui::DestroyContext();
}

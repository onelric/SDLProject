#include "Program.hpp"
#include "SDL2/SDL_render.h"
#include "SDL2/SDL_video.h"

Program::Program(SDL_Renderer* r, SDL_Window* w) : m_Renderer(r), m_Window(w)
{
}

Program::~Program()
{
    SDL_DestroyRenderer(m_Renderer);
    SDL_DestroyWindow(m_Window);
}

void Program::Loop()
{
    SDL_Rect rect;
    rect.x = 200;
    rect.y = 100;
    rect.w = 100;
    rect.h = 45;

    SDL_RenderClear(m_Renderer);

    SDL_SetRenderDrawColor(m_Renderer, 0, 0, 0, 255);
    SDL_RenderDrawRect(m_Renderer, &rect);
    SDL_SetRenderDrawColor(m_Renderer, 255, 255, 255, 255);

    SDL_RenderPresent(m_Renderer);
}

void Program::Events()
{
    SDL_Event ev;
    while (SDL_PollEvent(&ev))
    {
        switch (ev.type)
        {
        case SDL_QUIT:
            m_IsRunning = false;
            break;
        default:
            break;
        }
    }
}

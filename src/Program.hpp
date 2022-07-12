#ifndef PROGRAM_HPP
#define PROGRAM_HPP

#include "SDL2/SDL_events.h"
#include "SDL2/SDL_render.h"
#include "SDL2/SDL_video.h"


class Program
{
public:
    Program(SDL_Renderer*, SDL_Window*);
    ~Program();

    void Loop();

    void Events();

    bool IsRunning() const { return m_IsRunning; }
private:
    SDL_Renderer* m_Renderer;
    SDL_Window* m_Window;

    SDL_Event m_Event;

    bool m_IsRunning{true};
};

#endif

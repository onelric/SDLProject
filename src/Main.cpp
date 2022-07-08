#include <iostream>

#include "Program.hpp"
#include "SDL2/SDL.h"


int main(int argv, char** args)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        std::cerr << "Error: Failed to initialize SDL: " << SDL_GetError() << std::endl;
        exit(-1);
    }

    SDL_Window* window = SDL_CreateWindow("", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 960, 540, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
    if (window == nullptr)
    {
        std::cerr << "Error: Failed to create SDL window: " << SDL_GetError() << std::endl;
        exit(-1);
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
    if (renderer == nullptr)
    {
        std::cerr << "Error: Failed to create SDL renderer: " << SDL_GetError() << std::endl;
        exit(-1);
    }

    Program* program = new Program(std::move(renderer), std::move(window));
    while (program->IsRunning())
    {
        program->Loop();
        program->Events();
    }

    SDL_Quit();
    delete program;

    return 0;
}

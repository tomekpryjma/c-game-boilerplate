#include "core.h"
#include <stdio.h>

Core Core_Init()
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        printf("Whoops: %s\n", SDL_GetError());
        exit(1);
    }

    SDL_Window *window = SDL_CreateWindow("Title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 300, 300, 0);
    if (window == NULL)
    {
        printf("%s\n", SDL_GetError());
        exit(1);
    }
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);
    if (window == NULL)
    {
        printf("%s\n", SDL_GetError());
        exit(1);
    }

    Core core = {
        .window = window, .renderer = renderer};

    printf("Core init done.\n");

    return core;
}

void Core_Loop(const Core *core)
{
    printf("Printf from game loop!\n");
    SDL_Event e;
    uint8_t is_running = 1;

    while (is_running)
    {
        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT)
            {
                is_running = 0;
                break;
            }
        }
    }
    printf("Game loop ended.\n");
}

void Core_Down(Core *core)
{
    printf("Downing core...\n");
    SDL_DestroyRenderer(core->renderer);
    SDL_DestroyWindow(core->window);
    SDL_Quit();
    printf("Core exited. All Done!");
}
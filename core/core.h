#pragma once

#include <SDL.h>

typedef struct Core
{
    SDL_Window *window;
    SDL_Renderer *renderer;
} Core;

Core Core_Init();
void Core_Loop(const Core *core);
void Core_Down(Core *core);
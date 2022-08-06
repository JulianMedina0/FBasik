#ifndef BASIK_H
#define BASIK_H

#include <stdbool.h>

#include <SDL2/SDL.h>

#include "window.h"

static struct {
    Window* window;

    bool quit;
    SDL_Event e;
    float deltatime;
} Basik;

void OnCreate();
void OnDestory();
void Start();

#endif

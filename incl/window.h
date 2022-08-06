#ifndef WINDOW_H
#define WINDOW_H

#include <stdlib.h>

#include <SDL2/SDL.h>

#include "utils.h"

typedef struct {
    SDL_Window* window;
    SDL_Renderer* renderer;
} Window;

Window* CreateWindow(const char* _title, int _width, int _height);
void DestroyWindow(Window* window);

void ChangeWindowDrawColor(Window* window, Color c);

void ClearWindow(Window* window);
void DisplayWindow(Window* window);

#endif

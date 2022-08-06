#include <window.h>

Window* CreateWindow(const char* _title, int _width, int _height) {
    Window* window = malloc(sizeof *window);

    window->window = SDL_CreateWindow(_title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _width, _height, SDL_WINDOW_SHOWN);
    window->renderer = SDL_CreateRenderer(window->window, -1, SDL_RENDERER_ACCELERATED);

    return window;
}

void DestroyWindow(Window* window) {
    SDL_DestroyRenderer(window->renderer);
    SDL_DestroyWindow(window->window);

    free(window);
}

void ChangeWindowDrawColor(Window* window, Color c) {
    SDL_SetRenderDrawColor(window->renderer, c.r, c.g, c.b, c.a);
}

void ClearWindow(Window* window) {
    ChangeWindowDrawColor(window, (Color){85,170,85,255});
    SDL_RenderClear(window->renderer);
}

void DisplayWindow(Window* window) {
    SDL_RenderPresent(window->renderer);
    SDL_ShowWindow(window->window);
}

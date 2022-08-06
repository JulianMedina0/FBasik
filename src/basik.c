#include <basik.h>

struct {
    float x, y;
    float vx, vy;
    float mv;
    float a, d;
} player;

void OnCreate() {
    Basik.window = CreateWindow("Basik", 800, 600);

    player.x = 50;
    player.y = 50;
    player.vx = 0;
    player.vy = 0;
    player.mv = 100;
    player.d = 1;
    player.a = player.mv*player.mv*player.d/1;
}

void OnDestory() {
    DestroyWindow(Basik.window);
}

void EventHandling() {
    while(SDL_PollEvent(&Basik.e))
	switch(Basik.e.type) {
	    case SDL_QUIT:
		Basik.quit = true;
		break;
	    case SDL_KEYDOWN:
		if(Basik.e.key.keysym.sym == SDLK_UP) {
		    player.vy -= player.a * Basik.deltatime;
		    if(fabsf(player.vy) >= player.mv)
			player.vy = -player.mv;
		}
		if(Basik.e.key.keysym.sym == SDLK_DOWN) {
		    player.vy += player.a * Basik.deltatime;
		    if(fabsf(player.vy) >= player.mv)
			player.vy = player.mv;
		}
		if(Basik.e.key.keysym.sym == SDLK_LEFT) {
		    player.vx -= player.a * Basik.deltatime;
		    if(fabsf(player.vx) >= player.mv)
			player.vx = -player.mv;
		}
		if(Basik.e.key.keysym.sym == SDLK_RIGHT) {
		    player.vx += player.a * Basik.deltatime;
		    if(fabsf(player.vx) >= player.mv)
			player.vx = player.mv;
		}
		break;
	    default:
		break;
	}
}

void Update() {
    player.x += player.vx * Basik.deltatime;
    player.y += player.vy * Basik.deltatime;

    player.vx -= player.vx / player.d * Basik.deltatime;
    player.vy -= player.vy / player.d * Basik.deltatime;
}

void Render() {
    ClearWindow(Basik.window);

    ChangeWindowDrawColor(Basik.window, (Color){255,255,255,255});
    SDL_Rect r = {player.x, player.y, 50, 50};
    SDL_RenderDrawRect(Basik.window->renderer, &r);

    DisplayWindow(Basik.window);
}

void Start() {
    Basik.quit = false;

    OnCreate();

    float currenttime;
    float lasttime;

    while(!Basik.quit) {
	Basik.deltatime = (lasttime - currenttime) / 1000.0f;
	currenttime = SDL_GetTicks64();

	EventHandling();
	Update();
	Render();

	lasttime = SDL_GetTicks64();
    }
    
    OnDestory();
}

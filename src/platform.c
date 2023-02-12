#include <SDL2/SDL.h>

internal void platform_init()
{
	SDL_Init(SDL_INIT_VIDEO);
}

internal void platform_destroy()
{
	SDL_Quit();
}

internal void platform_sleep(u32 ms)
{
	SDL_Delay(ms);
}
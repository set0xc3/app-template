#include <SDL2/SDL.h>

#include <stdlib.h>
#include <stdio.h>

internal Window *window_open(const char* title, u32 width, u32 height, u32 xpos, u32 ypos)
{
	Window *result = 0;
	
	result = malloc(sizeof(*result));
	result->title  = title;
	result->width  = width; 
	result->height = height;
	result->xpos   = xpos; 
	result->ypos   = ypos;
	
	u32 window_flags = SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL;
	result->handle = SDL_CreateWindow(title,
											   SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
											   width, height,
											   window_flags);
	
	result->id = SDL_GetWindowID(result->handle);
	return result;
}

internal void window_close(Window* window)
{
	SDL_DestroyWindow(window->handle);
}

internal void window_poll_events(Window* window)
{
	SDL_Event raw_event;
	Event* event = 0;

	while (SDL_PollEvent(&raw_event)) 
	{
		switch (raw_event.type)
		{
			case SDL_WINDOWEVENT:
			{
				switch (raw_event.window.event)
				{
					case SDL_WINDOWEVENT_CLOSE:
					{
						event = malloc(sizeof(*event));
						event->type = CORE_EVENT_WINDOW;

						event->window.id = raw_event.window.windowID;
						event->window.type = CORE_EVENT_WINDOW_CLOSE;
					} break;
				}
			} break;
		}

		if (event)
		{
			window->event_callback(event);
			event = 0;
		}
	}
}

internal void window_set_event_callback(Window* window, void* function)
{
	window->event_callback = function;
}
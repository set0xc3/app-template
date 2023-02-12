#include "types.h"
#include "vector.h"

#include "event.h"
#include "platform.h"
#include "window.h"

#include "platform.c"
#include "window.c"

global b8 is_quit = false;

#define WINDOWS_TOTAL 1
global u32     window_size = 0;
global Window *windows[WINDOWS_TOTAL];

#define EVENTS_TOTAL 256
global u32    event_size = 0;
global Event *event_list[EVENTS_TOTAL];

internal void core_add_event(Event *event)
{
	for (u32 i = 0; i < EVENTS_TOTAL+1; i++)
	{
		if (!event_list[i])
		{
			event_list[i] = event;
			event_size += 1;
			break;
		}
	}
}

internal void core_remove_event(Event* event)
{
	for (u32 i = 0; i < EVENTS_TOTAL+1; i++)
	{
		if (event_list[i] == event)
		{
			free(event);
			event_list[i] = 0;
			event_size -= 1;
			break;
		}
	}
}

internal void core_process_event()
{
	for (u32 i = 0; i < EVENTS_TOTAL+1; i++)
	{
		Event* event = 0;
		event = event_list[i];
		if (event)
		{
			switch (event->type)
			{
				case CORE_EVENT_QUIT:
				{
					is_quit = true;
				} break;

				case CORE_EVENT_WINDOW:
				{
					switch (event->window.type)
					{
						case CORE_EVENT_WINDOW_CLOSE:
						{
							for (u32 i = 0; i < WINDOWS_TOTAL+1; i++)
							{
								if (windows[i])
								{
									if (windows[i]->id == event->window.id)
									{
										printf("[%u, %u] CORE_EVENT_WINDOW_CLOSE\n", event->window.id, event->window.type);

										window_close(windows[i]);
										windows[i] = 0;
										window_size -= 1;
										break;
									}
								}
							}
						} break;
					}
				} break;
			}

			core_remove_event(event);
		}
	}
}

internal void core_on_event(Event *event)
{
	core_add_event(event);
}

int main(int argc, char* argv[])
{
	platform_init();
	
	for (u32 i = 0; i < 1; i++)
	{
		const char title[256];
		u32 len = snprintf(0, 0, "[%u] Application Template", i+1);
		if (len <= 256)
		{
			snprintf(title, len, "[%u] Application Template", i+1);
		}

		windows[i] = window_open(title, 1280, 720, 0, 0);
		window_set_event_callback(windows[i], core_on_event);
		window_size += 1;
	}

	while (!is_quit) 
	{
		if (!window_size)
		{
			break;
		}

		for (u32 i = 0; i < WINDOWS_TOTAL+1; i++)
		{
			if (windows[i])
			{
				window_poll_events(windows[i]);
			}
		}

		core_process_event();
		
		platform_sleep(1);
	}
	
	return 0;
}

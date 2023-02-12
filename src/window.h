#if !defined(WINDOW_H)
#define WINDOW_H

typedef struct 
{
	u32 id;
	const char* title;
	u32 width, height;
	u32 xpos, ypos;
	void* handle;
	
	void (*event_callback)(Event *event);
} Window;

internal Window *window_open(const char* title, u32 width, u32 height, u32 xpos, u32 ypos);
internal void window_close(Window *window);
internal void window_poll_events(Window* window);

internal void window_set_event_callback(Window* window, void *function);

#endif
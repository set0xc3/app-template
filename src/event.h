#if !defined(EVENT_H)
#define EVENT_H

typedef enum 
{
	CORE_EVENT_NONE,
	CORE_EVENT_QUIT,
	CORE_EVENT_WINDOW
} EventType;

typedef enum
{
	CORE_EVENT_WINDOW_NONE,
	CORE_EVENT_WINDOW_CLOSE
} WindowEventType;

typedef struct
{
	u32 type;
	u32 id;
	u32 width, height;
	u32 xpos, ypos;
	void *handle;
} WindowEvent;

typedef struct
{
	u32 type;
	WindowEvent window;
} Event;

#endif
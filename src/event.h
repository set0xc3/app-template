#if !defined(EVENT_H)
#define EVENT_H

typedef enum EventType EventType;
enum EventType
{
	CORE_EVENT_NONE,
	CORE_EVENT_QUIT,
	CORE_EVENT_WINDOW
};

typedef enum WindowEventType WindowEventType;
enum WindowEventType
{
	CORE_EVENT_WINDOW_NONE,
	CORE_EVENT_WINDOW_CLOSE
};

typedef struct WindowEvent WindowEvent;
struct WindowEvent
{
	u32 type;
	u32 width, height;
	u32 xpos, ypos;
	void *handle;
};

typedef struct Event Event;
struct Event
{
	u32 id;
	u32 type;
	WindowEvent window;
};

#endif
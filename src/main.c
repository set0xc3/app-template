#include "types.h"
#include "vector.h"

#include "event.h"
#include "platform.h"
#include "window.h"

#include "platform.c"
#include "window.c"

#include <string.h>

#define MAX_EVENTS 4

typedef struct EventSystem EventSystem;
struct EventSystem
{
	u32 active_count;
	Event events[MAX_EVENTS];
};

void event_system_add(EventSystem *ctx, Event *event)
{

}

void event_system_remove(EventSystem* ctx, Event* event)
{

}

int main(int argc, char* argv[])
{
	EventSystem *event_system = malloc(sizeof(EventSystem));
	memset(event_system, 0, sizeof(*event_system));


	return 0;
}

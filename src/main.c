#include "types.h"
#include "vector.h"

#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	u32 frame_size = 256;
	u8 *frame = 0;
	frame = malloc(frame_size);
	frame = realloc(frame, frame_size);
	free(frame);

	return 0;
}

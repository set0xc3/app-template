#if !defined(VECTOR_H)
#define VECTOR_H

#include "types.h"

typedef union {struct {f32 x,y;}; f32 v[2];} v2;
typedef union {struct {f32 x,y,z;}; f32 v[3];} v3;
typedef union {struct {f32 x,y,z,w;}; struct {f32 r,g,b,a;}; f32 v[4];} v4;

#define v2(x,y)     ((v2){x,y})
#define v3(x,y,z)   ((v3){x,y,z})
#define v4(x,y,z,w) ((v4){x,y,z,w})

#define v2_add(t,a,b) ((t){a.x+b.x, a.y+b.y})
#define v3_add(t,a,b) ((t){a.x+b.x, a.y+b.y, a.z+b.z})
#define v4_add(t,a,b) ((t){a.x+b.x, a.y+b.y, a.z+b.z, a.w+b.w})

#endif
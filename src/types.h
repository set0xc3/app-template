#if !defined(TYPES_H)
#define TYPES_H

#include <stdint.h>
#include <stdbool.h>

typedef int8_t  s8;
typedef int16_t s16;
typedef int32_t s32;
typedef int64_t s64;

typedef uint8_t  u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef float  f32;
typedef double f64;

typedef s8  b8;
typedef s32 b32;

#define local        static
#define local_const  static
#define global       static
#define global_const static
#define internal     static

#if defined(DLL_EXPORT)
#define api __declspec(dllexport)
#else
#define api __declspec(dllimport)
#endif

#endif
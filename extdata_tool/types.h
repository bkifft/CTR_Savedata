#pragma once

#include <stdlib.h>
#include <stdint.h>
//Bools
typedef enum
{
	False,
	True
} _boolean;

typedef enum
{
	Good,
	Fail
} return_basic;

typedef enum
{
	ARG_ERROR = 1,
	IO_ERROR,
	MEM_ERROR,
} errors;

typedef enum
{
	Invalid = -1,
	Valid = 0
}Validity;

typedef enum
{
	BE = 0,
	LE = 1
} endianness_flag;

typedef enum
{
	KB = 1024,
	MB = 1048576,
	GB = 1073741824
} file_unit_size;

typedef unsigned char   u8;
typedef unsigned short  u16;
typedef unsigned int    u32;
typedef unsigned long long      u64;

typedef signed char     s8;
typedef signed short    s16;
typedef signed int      s32;
typedef signed long long        s64;

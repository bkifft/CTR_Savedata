#pragma once

#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>
#include <tgmath.h>

#ifdef _WIN32
	#include <io.h>
	#include <direct.h>
	#include <windows.h>
	#include <wchar.h>
#else
	#include <sys/stat.h>
	#include <unistd.h>
#endif

#include "types.h"
#include "utils.h"
#include "ctx.h"


#define ARG_ERROR 1
#define IO_ERROR 2
#define MEM_ERROR 3

#pragma once

#ifndef GEN_USE_STB_SPRINTF
#define GEN_USE_STB_SPRINTF
#endif

#ifdef GEN_USE_STB_SPRINTF
#include <stb/stb_sprintf.h>

#define GEN_SPRINTF		stbsp_sprintf
#define GEN_SNPRINTF	stbsp_snprintf
#define GEN_VSPRINTF	stbsp_vsprintf
#define GEN_VSNPRINTF	stbsp_vsnprintf
#else
#include <stdio.h>

#define GEN_SPRINTF		sprintf
#define GEN_SNPRINTF	snprintf
#define GEN_VSPRINTF	vsprintf
#define GEN_VSNPRINTF	vsnprintf
#endif

#pragma once

#include "int_types.h"

#ifdef __cplusplus
extern "C" {
#endif

#define ALLOW_BASIC_CONCAT 0

typedef struct stringBuilder_t {
	char*	str;
	u32		length;
	u32		alloc;
} stringBuilder_t;

extern stringBuilder_t	String_Create( const u32 size );

#if ALLOW_BASIC_CONCAT
extern void				String_Append( stringBuilder_t* sb, const char* msg );
#else
#define String_Append	String_Appendf
#endif

extern void				String_Appendf( stringBuilder_t* sb, const char* fmt, ... );

#ifdef __cplusplus
}
#endif

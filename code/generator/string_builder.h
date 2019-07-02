#pragma once

#include "int_types.h"

struct stringBuilder_t {
	char*				str;
	u32					length;
	u32					alloc;
};

extern stringBuilder_t	String_Create( const u32 size );

extern void				String_Append( stringBuilder_t* sb, const char* msg );
extern void				String_Appendf( stringBuilder_t* sb, const char* fmt, ... );

#include "string_builder.h"

#include "allocator.h"

#include <stdio.h>
#include <stdarg.h>
#include <assert.h>

stringBuilder_t String_Create( const u32 size ) {
	assert( size > 0 );

	return {
		(char*) Mem_Alloc( size ),
		0,
		size
	};
}

void String_Append( stringBuilder_t* sb, const char* msg ) {
	assert( sb );
	assert( msg );

	int len = snprintf( sb->str + sb->length, sb->alloc, "%s", msg );

	u32 length = (u32) len;

	assert( sb->length + length <= sb->alloc );

	sb->length += length;
}

void String_Appendf( stringBuilder_t* sb, const char* fmt, ... ) {
	assert( sb );
	assert( fmt );

	va_list args;
	va_start( args, fmt );

	int len = vsnprintf( sb->str + sb->length, sb->alloc, fmt, args );

	u32 length = (u32) len;

	assert( sb->length + length <= sb->alloc );

	sb->length += length;

	va_end( args );
}

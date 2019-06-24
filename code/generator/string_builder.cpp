#include "string_builder.h"

#include "allocator.h"

#include <stdio.h>
#include <stdarg.h>
#include <assert.h>

#if ALLOW_BASIC_CONCAT
static u32 Concat( char* dst, char* src ) {
	u32 length = 0;

	while ( *dst ) dst++;
	while ( ( *dst++ = *src++ ) ) { length++; }
	--dst;

	return length;
}
#endif

stringBuilder_t String_Create( const u32 size ) {
	return {
		(char*) Mem_Alloc( size ),
		0,
		size
	};
}

#if ALLOW_BASIC_CONCAT
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wcast-qual"

void String_Append( stringBuilder_t* sb, const char* msg ) {
	sb->length += Concat( sb->str, (char*) msg );
}

#pragma clang diagnostic pop
#endif

void String_Appendf( stringBuilder_t* sb, const char* fmt, ... ) {
	va_list args;
	va_start( args, fmt );

	int len = vsprintf( sb->str + sb->length, fmt, args );

	u32 length = (u32) len;

	assert( sb->length + length <= sb->alloc );

	sb->length += length;

	va_end( args );
}

/*
===========================================================================

HLML

Copyright (c) Dan Moody 2018 - Present.

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

===========================================================================
*/

#include "string_builder.h"

#include "linear_allocator.h"

#include <stdarg.h>
#include <assert.h>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Weverything"
#include <stb/stb_sprintf.h>
#pragma clang diagnostic pop

stringBuilder_t *StringBuilder_Create( allocatorLinear_t *allocator, const u32 size ) {
	assert( size > 0 );

	stringBuilder_t *stringBuilder = (stringBuilder_t *) Mem_Alloc( allocator, sizeof( stringBuilder_t ) );
	stringBuilder->str = (char *) Mem_Alloc( allocator, size );
	stringBuilder->length = 0;
	stringBuilder->alloc = size;

	return stringBuilder;
}

void StringBuilder_Append( stringBuilder_t *sb, const char *msg ) {
	assert( sb );
	assert( msg );

	int len = stbsp_snprintf( sb->str + sb->length, (int) sb->alloc, "%s", msg );

	u32 length = (u32) len;

	assert( sb->length + length <= sb->alloc && "Maximum length of StringBuilder has been used.  It needs to be made bigger." );

	sb->length += length;
}

static void StringBuilder_Appendfv( stringBuilder_t *sb, const char *fmt, va_list args ) {
	assert( sb );
	assert( fmt );
	assert( args );

	int len = stbsp_vsnprintf( sb->str + sb->length, (int) sb->alloc, fmt, args );

	u32 length = (u32) len;

	assert( sb->length + length <= sb->alloc && "Maximum length of StringBuilder has been used.  It needs to be made bigger." );

	sb->length += length;
}

void StringBuilder_Appendf( stringBuilder_t *sb, const char *fmt, ... ) {
	assert( sb );
	assert( fmt );

	va_list args;
	va_start( args, fmt );

	StringBuilder_Appendfv( sb, fmt, args );

	va_end( args );
}

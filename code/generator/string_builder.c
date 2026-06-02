/*
===========================================================================

HLML Generator.
Copyright (c) Dan Moody 2018 - Present.

This file is part of the HLML Generator.

The HLML Generator is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

The HLML Generator is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with The HLML Generator.  If not, see <http://www.gnu.org/licenses/>.

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
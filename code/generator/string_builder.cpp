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

#include "allocator.h"

#include <stdio.h>
#include <stdarg.h>
#include <assert.h>

stringBuilder_t String_Create( allocatorLinear_t* allocator, const u32 size ) {
	assert( size > 0 );

	return {
		(char*) Mem_Alloc( allocator, size ),
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

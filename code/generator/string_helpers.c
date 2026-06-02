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

#include "string_helpers.h"

#include "linear_allocator.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Weverything"
#include <stb/stb_sprintf.h>
#pragma clang diagnostic pop

#include <assert.h>
#include <stdarg.h>
#include <string.h>

// TODO: DM: 31/05/2026: rename to StringEquals
bool32 String_Equals( const char *lhs, const char *rhs ) {
	return strcmp( lhs, rhs ) == 0;
}

// TODO: DM: 31/05/2026:
//	rename to TempPrintf
//	fix how length is calculated when allocating resultant string
char *String_TPrintf( allocatorLinear_t *tempStorage, const char *fmt, ... ) {
	assert( tempStorage );
	assert( fmt && "Format string MUST be non-NULL." );

	va_list args;

	va_start( args, fmt );
	int len = stbsp_vsnprintf( NULL, 0, fmt, args );
	va_end( args );

	u64 length = (u64) len;
	length++;

	char *result = Mem_Alloc( tempStorage, length * sizeof( char ) );

	va_start( args, fmt );
	stbsp_vsnprintf( result, (int) length, fmt, args );
	va_end( args );

	result[length - 1] = 0;

	return result;
}

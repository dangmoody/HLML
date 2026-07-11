/*
===========================================================================

HLML Generator.
Copyright (c) Dan Moody 2018 - Present.

This file is part of the HLML Generator.

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

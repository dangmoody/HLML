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
#include "int_types.h"
#include "defines.h"

#include <stdlib.h>
#include <assert.h>
#include <memory.h>
#include <stdarg.h>
#include <assert.h>
#include <string.h>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Weverything"
#include <stb/stb_sprintf.h>
#pragma clang diagnostic pop

typedef enum allocatorAlignment_t {
	ALLOCATOR_ALIGNMENT_ZERO					= 0,
	ALLOCATOR_ALIGNMENT_ONE						= 1,
	ALLOCATOR_ALIGNMENT_FOUR					= 4,
	ALLOCATOR_ALIGNMENT_EIGHT					= 8,
	ALLOCATOR_ALIGNMENT_SIXTEEN					= 16
} allocatorAlignment_t;

typedef enum allocatorLinearFlagBits_t {
	ALLOCATOR_LINEAR_FLAG_CREATED_FROM_OTHER	= GEN_BIT( 0 )
} allocatorLinearFlagBits_t;
typedef u32 allocatorLinearFlags_t;

typedef struct allocatorLinear_t {
	u64						offset;
	u64						size;
	allocatorLinearFlags_t	flags;
} allocatorLinear_t;

static allocatorLinear_t* Mem_CreateLinear( const u64 size ) {
	assert( size > 0 );

	void* memory = malloc( sizeof( allocatorLinear_t ) + size );

	allocatorLinear_t* allocator = (allocatorLinear_t*) memory;
	allocator->offset = 0;
	allocator->size = size;
	allocator->flags = 0;

	return allocator;
}

static void Mem_DestroyLinear( allocatorLinear_t** allocator ) {
	assert( *allocator );

	free( *allocator );
	*allocator = NULL;
}

static void* Mem_AllocAligned( allocatorLinear_t* allocator, const u64 size, const allocatorAlignment_t alignment ) {
	assert( allocator );
	assert( allocator->offset + size <= allocator->size );
	assert( size );
	assert( alignment != ALLOCATOR_ALIGNMENT_ZERO );

	allocator->offset = GEN_ALIGN_UP_INT( allocator->offset, (u64) alignment );

	void* basePtr = allocator + sizeof( allocatorLinear_t );
	u8* ptr = (u8*) basePtr + allocator->offset;

	allocator->offset += size;

	return ptr;
}

static void* Mem_Alloc( allocatorLinear_t* allocator, const u64 size ) {
	return Mem_AllocAligned( allocator, size, ALLOCATOR_ALIGNMENT_SIXTEEN );
}

static void Mem_Reset( allocatorLinear_t* allocator ) {
	allocator->offset = 0;
}

static allocatorLinear_t* Mem_CreateFromOther( allocatorLinear_t* original, const u64 sizeBytes ) {
	assert( original );
	assert( sizeBytes );
	// test that the size of the sub-allocator we want to make can fit inside the original allocator
	assert( sizeBytes < original->size );

	allocatorLinear_t* newAllocator = (allocatorLinear_t*) Mem_Alloc( original, sizeBytes );
	newAllocator->offset = 0;
	newAllocator->size = sizeBytes;
	newAllocator->flags = original->flags | ALLOCATOR_LINEAR_FLAG_CREATED_FROM_OTHER;

	return newAllocator;
}


bool32 String_Equals( const char* lhs, const char* rhs ) {
	return strcmp( lhs, rhs ) == 0;
}

char* String_TPrintf( allocatorLinear_t* tempStorage, const char* fmt, ... ) {
	assert( tempStorage );
	assert( fmt && "Format string MUST be non-NULL." );

	va_list args;

	va_start( args, fmt );
	int len = stbsp_vsnprintf( NULL, 0, fmt, args );
	va_end( args );

	u64 length = (u64) len;
	length++;

	char* result = Mem_Alloc( tempStorage, length * sizeof( char ) );

	va_start( args, fmt );
	stbsp_vsnprintf( result, (int) length, fmt, args );
	va_end( args );

	result[length - 1] = 0;

	return result;
}


typedef struct stringBuilder_t {
	char*	str;
	u32		length;
	u32		alloc;
} stringBuilder_t;

static stringBuilder_t* StringBuilder_Create( allocatorLinear_t* allocator, const u32 size ) {
	assert( size > 0 );

	stringBuilder_t* stringBuilder = (stringBuilder_t*) Mem_Alloc( allocator, sizeof( stringBuilder_t ) );
	stringBuilder->str = (char*) Mem_Alloc( allocator, size );
	stringBuilder->length = 0;
	stringBuilder->alloc = size;

	return stringBuilder;
}

static void StringBuilder_Append( stringBuilder_t* sb, const char* msg ) {
	assert( sb );
	assert( msg );

	int len = stbsp_snprintf( sb->str + sb->length, (int) sb->alloc, "%s", msg );

	u32 length = (u32) len;

	assert( sb->length + length <= sb->alloc && "Maximum length of StringBuilder has been used.  It needs to be made bigger." );

	sb->length += length;
}

static void StringBuilder_Appendfv( stringBuilder_t* sb, const char* fmt, va_list args ) {
	assert( sb );
	assert( fmt );
	assert( args );

	int len = stbsp_vsnprintf( sb->str + sb->length, (int) sb->alloc, fmt, args );

	u32 length = (u32) len;

	assert( sb->length + length <= sb->alloc && "Maximum length of StringBuilder has been used.  It needs to be made bigger." );

	sb->length += length;
}

static void StringBuilder_Appendf( stringBuilder_t* sb, const char* fmt, ... ) {
	assert( sb );
	assert( fmt );

	va_list args;
	va_start( args, fmt );

	StringBuilder_Appendfv( sb, fmt, args );

	va_end( args );
}

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

#include "linear_allocator.h"

#include "defines.h"

#include <malloc.h>
#include <assert.h>

typedef enum allocatorLinearFlagBits_t {
	ALLOCATOR_LINEAR_FLAG_CREATED_FROM_OTHER	= GEN_BIT( 0 )
} allocatorLinearFlagBits_t;
typedef u32 allocatorLinearFlags_t;

typedef struct allocatorLinear_t {
	u64						offset;
	u64						size;
	allocatorLinearFlags_t	flags;
} allocatorLinear_t;

allocatorLinear_t* Mem_CreateLinear( const u64 size ) {
	assert( size > 0 );

	void* memory = malloc( sizeof( allocatorLinear_t ) + size );

	allocatorLinear_t* allocator = (allocatorLinear_t*) memory;
	allocator->offset = 0;
	allocator->size = size;
	allocator->flags = 0;

	return allocator;
}

allocatorLinear_t* Mem_CreateFromOther( allocatorLinear_t* original, const u64 sizeBytes ) {
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

void Mem_DestroyLinear( allocatorLinear_t** allocator ) {
	assert( *allocator );

	free( *allocator );
	*allocator = NULL;
}

void* Mem_Alloc( allocatorLinear_t* allocator, const u64 size ) {
	return Mem_AllocAligned( allocator, size, ALLOCATOR_ALIGNMENT_EIGHT );
}

void* Mem_AllocAligned( allocatorLinear_t* allocator, const u64 size, const allocatorAlignment_t alignment ) {
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

void Mem_Reset( allocatorLinear_t* allocator ) {
	allocator->offset = 0;
}
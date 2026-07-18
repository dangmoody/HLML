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

allocatorLinear_t *Mem_CreateLinear( const u64 size ) {
	assert( size > 0 );

	void *memory = malloc( sizeof( allocatorLinear_t ) + size );

	allocatorLinear_t *allocator = (allocatorLinear_t *) memory;
	allocator->offset = 0;
	allocator->size = size;
	allocator->flags = 0;

	return allocator;
}

allocatorLinear_t *Mem_CreateFromOther( allocatorLinear_t *original, const u64 sizeBytes ) {
	assert( original );
	assert( sizeBytes );
	// test that the size of the sub-allocator we want to make can fit inside the original allocator
	assert( sizeBytes < original->size );

	allocatorLinear_t *newAllocator = (allocatorLinear_t *) Mem_Alloc( original, sizeBytes );
	newAllocator->offset = 0;
	newAllocator->size = sizeBytes;
	newAllocator->flags = original->flags | ALLOCATOR_LINEAR_FLAG_CREATED_FROM_OTHER;

	return newAllocator;
}

void Mem_DestroyLinear( allocatorLinear_t **allocator ) {
	assert( *allocator );

	free( *allocator );
	*allocator = NULL;
}

void *Mem_Alloc( allocatorLinear_t *allocator, const u64 size ) {
	return Mem_AllocAligned( allocator, size, ALLOCATOR_ALIGNMENT_EIGHT );
}

void *Mem_AllocAligned( allocatorLinear_t *allocator, const u64 size, const allocatorAlignment_t alignment ) {
	assert( allocator );
	assert( allocator->offset + size <= allocator->size );
	assert( size );
	assert( alignment != ALLOCATOR_ALIGNMENT_ZERO );

	allocator->offset = GEN_ALIGN_UP_INT( allocator->offset, (u64) alignment );

	void *basePtr = allocator + sizeof( allocatorLinear_t );
	u8 *ptr = (u8 *) basePtr + allocator->offset;

	allocator->offset += size;

	return ptr;
}

void Mem_Reset( allocatorLinear_t *allocator ) {
	allocator->offset = 0;
}

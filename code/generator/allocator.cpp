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
#include "allocator.h"

#include <stdlib.h>
#include <assert.h>
#include <memory.h>

allocatorLinear_t* Mem_CreateLinear( const u32 size ) {
	assert( size > 0 );

	allocatorLinear_t* allocator = (allocatorLinear_t*) malloc( sizeof( allocatorLinear_t ) );

	allocator->size = size;
	allocator->offset = 0;
	allocator->ptr = (u8*) calloc( size + sizeof( allocatorLinear_t ), sizeof( u8 ) );

	return allocator;
}

void Mem_DestroyLinear( allocatorLinear_t** allocator ) {
	assert( *allocator );

	free( ( *allocator )->ptr );
	( *allocator )->ptr = NULL;
}

u8* Mem_Alloc( allocatorLinear_t* allocator, const u32 size ) {
	assert( allocator && allocator->ptr );
	assert( allocator->offset + size <= allocator->size );

	u8* ptr = allocator->ptr + allocator->offset;

	allocator->offset += size;

	return ptr;
}

void Mem_Reset( allocatorLinear_t* allocator ) {
	allocator->offset = 0;
}

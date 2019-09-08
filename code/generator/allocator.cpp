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

typedef struct allocatorInfo_t {
	u32	size;
	u32	offset;
	u8*	ptr;
} allocatorInfo_t;

static allocatorInfo_t g_allocatorInfo;

void Mem_Init( const u32 size ) {
	assert( size > 0 );

	g_allocatorInfo.size = size;
	g_allocatorInfo.offset = 0;
	g_allocatorInfo.ptr = (u8*) calloc( size + sizeof( allocatorInfo_t ), sizeof( u8 ) );
}

void Mem_Shutdown( void ) {
	free( g_allocatorInfo.ptr );
	g_allocatorInfo.ptr = NULL;
}

u8* Mem_Alloc( const u32 size ) {
	assert( g_allocatorInfo.offset + size <= g_allocatorInfo.size );

	u8* ptr = g_allocatorInfo.ptr + g_allocatorInfo.offset;

	g_allocatorInfo.offset += size;

	return ptr;
}

void Mem_Reset( void ) {
	g_allocatorInfo.offset = 0;
}

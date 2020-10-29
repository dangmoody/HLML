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
#pragma once

#include "int_types.h"

#define MB_TO_BYTES	( 1024 * 1024 )
#define KB_TO_BYTES	( 1024 )

typedef struct allocatorLinear_t {
	u32				size;
	u32				offset;
	u8*				ptr;
} allocatorLinear_t;

allocatorLinear_t*	Mem_CreateLinear( const u32 size );
void				Mem_DestroyLinear( allocatorLinear_t** allocator );

u8*					Mem_Alloc( allocatorLinear_t* allocator, const u32 size );
void				Mem_Reset( allocatorLinear_t* allocator );

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

#pragma once

#include "int_types.h"

typedef struct allocatorLinear_t allocatorLinear_t;

typedef enum allocatorAlignment_t {
	ALLOCATOR_ALIGNMENT_ZERO	= 0,
	ALLOCATOR_ALIGNMENT_ONE		= 1,
	ALLOCATOR_ALIGNMENT_FOUR	= 4,
	ALLOCATOR_ALIGNMENT_EIGHT	= 8,
	ALLOCATOR_ALIGNMENT_SIXTEEN	= 16
} allocatorAlignment_t;

allocatorLinear_t	*Mem_CreateLinear( const u64 size );
allocatorLinear_t	*Mem_CreateFromOther( allocatorLinear_t *original, const u64 sizeBytes );
void				Mem_DestroyLinear( allocatorLinear_t **allocator );

void				*Mem_Alloc( allocatorLinear_t *allocator, const u64 size );

void				*Mem_AllocAligned( allocatorLinear_t *allocator, const u64 size, const allocatorAlignment_t alignment );

void				Mem_Reset( allocatorLinear_t *allocator );
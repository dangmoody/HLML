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
#include "allocator.h"

#include <assert.h>
#include <malloc.h>
#include <memory.h>

static u8*	g_ptr = NULL;
static u32	g_size = 0;
static u32	g_offset = 0;

void Mem_Init( const u32 size ) {
	assert( size > 0 );

	g_ptr = (u8*) calloc( size, sizeof( u8 ) );
	g_size = size;
}

void Mem_Shutdown( void ) {
	free( g_ptr );
	g_ptr = NULL;
}

u8* Mem_Alloc( const u32 size ) {
	assert( g_offset + size <= g_size );

	u8* ptr = g_ptr + g_offset;

	g_offset += size;

	return ptr;
}

void Mem_Reset( void ) {
	g_offset = 0;
}

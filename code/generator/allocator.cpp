#include "allocator.h"

#include <assert.h>
#include <malloc.h>
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

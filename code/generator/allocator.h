#pragma once

#include "int_types.h"

#ifdef __cplusplus
extern "C" {
#endif

#define MB_TO_BYTES	( 1024 * 1024 )
#define KB_TO_BYTES	( 1024 )

extern void			Mem_Init( const u32 size );
extern void			Mem_Shutdown( void );

extern u8*			Mem_Alloc( const u32 size );
extern void			Mem_Reset( void );

#ifdef __cplusplus
}
#endif

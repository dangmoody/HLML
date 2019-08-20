#pragma once

#define BIT( x )		( 1ULL << (x) )

#ifndef _countof
#define _countof( x )	( sizeof( (x) ) / sizeof( (x)[0] ) )
#endif

#define UNUSED( x )		( (void) (x) )


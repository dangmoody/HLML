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

#define GEN_BIT( x )						( 1ULL << (x) )

// returns number of elements in static array
#ifndef GEN_COUNTOF
#define GEN_COUNTOF( x )					( sizeof( (x) ) / sizeof( (x)[0] ) )
#endif

// used to bypass compiler warning
#define GEN_UNUSED( x )						( (void) (x) )

#define GEN_ALIGN_UP_INT( x, alignment )	( ( (x) + ( (alignment) - 1 ) ) & ~( (alignment) - 1 ) )

// min/max helper macros
#define GEN_MIN( x, y )						( (x) < (y) ? (x) : (y) )
#define GEN_MAX( x, y )						( (x) > (y) ? (x) : (y) )

// memory unit conversion helpers
#define MB_TO_BYTES							( 1024 * 1024 )
#define KB_TO_BYTES							( 1024 )

#define KILOBYTES( x )						( ( (u64) (x) ) * 1024 )
#define MEGABYTES( x )						( ( (u64) (x) ) * 1024 * 1024 )
#define GIGABYTES( x )						( ( (u64) (x) ) * 1024 * 1024 * 1024 )

#define GENERATE_TEMPLATES 1

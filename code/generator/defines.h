/*
===========================================================================

HLML

Copyright (c) Dan Moody 2018 - Present.

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

// TODO: DM: 01/06/2026: probably need to get rid of this header

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
#define KILOBYTES( x )						( ( (u64) (x) ) * 1024 )
#define MEGABYTES( x )						( ( (u64) (x) ) * 1024 * 1024 )
#define GIGABYTES( x )						( ( (u64) (x) ) * 1024 * 1024 * 1024 )

#define GENERATE_TEMPLATES 1

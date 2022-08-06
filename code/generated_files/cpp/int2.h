/*
===========================================================================

HLML.

MIT License

Copyright (c) 2019 Dan Moody

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

// THIS FILE WAS AUTOMATICALLY GENERATED BY A TOOL.
// EDITING THIS FILE MAY CAUSE SIDE EFFECTS.
// DO SO AT YOUR OWN RISK.

#pragma once

struct int3;
struct int4;

struct bool2;
struct uint2;
struct float2;
struct double2;

#include "hlml_types.h"
#include "hlml_defines.h"

#include "swizzle_templates.h"

// ignore prohibition of anymous structs for GCC
#if defined( __clang__ ) || defined( __GNUC__ )
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
#elif defined( _MSC_VER )
#pragma warning( push )
#pragma warning( disable : 4201 ) // C4201 - nonstandard extension used : nameless struct/union
#endif

struct int2
{
	union
	{
		struct
		{
			int32_t x;
			int32_t y;
		};

		struct
		{
			int32_t r;
			int32_t g;
		};

		int32_t v[2];

		// swizzles
		swizzle_2_to_2_nonwritable_t<int2, int32_t, 0, 0> xx;
		swizzle_2_to_2_writable_t<int2, int32_t, 1, 0> yx;
		swizzle_2_to_2_writable_t<int2, int32_t, 0, 1> xy;
		swizzle_2_to_2_nonwritable_t<int2, int32_t, 1, 1> yy;
		swizzle_2_to_3_nonwritable_t<int3, int32_t, 0, 0, 0> xxx;
		swizzle_2_to_3_nonwritable_t<int3, int32_t, 1, 0, 0> yxx;
		swizzle_2_to_3_nonwritable_t<int3, int32_t, 0, 1, 0> xyx;
		swizzle_2_to_3_nonwritable_t<int3, int32_t, 1, 1, 0> yyx;
		swizzle_2_to_3_nonwritable_t<int3, int32_t, 0, 0, 1> xxy;
		swizzle_2_to_3_nonwritable_t<int3, int32_t, 1, 0, 1> yxy;
		swizzle_2_to_3_nonwritable_t<int3, int32_t, 0, 1, 1> xyy;
		swizzle_2_to_3_nonwritable_t<int3, int32_t, 1, 1, 1> yyy;
		swizzle_2_to_4_nonwritable_t<int4, int32_t, 0, 0, 0, 0> xxxx;
		swizzle_2_to_4_nonwritable_t<int4, int32_t, 1, 0, 0, 0> yxxx;
		swizzle_2_to_4_nonwritable_t<int4, int32_t, 0, 1, 0, 0> xyxx;
		swizzle_2_to_4_nonwritable_t<int4, int32_t, 1, 1, 0, 0> yyxx;
		swizzle_2_to_4_nonwritable_t<int4, int32_t, 0, 0, 1, 0> xxyx;
		swizzle_2_to_4_nonwritable_t<int4, int32_t, 1, 0, 1, 0> yxyx;
		swizzle_2_to_4_nonwritable_t<int4, int32_t, 0, 1, 1, 0> xyyx;
		swizzle_2_to_4_nonwritable_t<int4, int32_t, 1, 1, 1, 0> yyyx;
		swizzle_2_to_4_nonwritable_t<int4, int32_t, 0, 0, 0, 1> xxxy;
		swizzle_2_to_4_nonwritable_t<int4, int32_t, 1, 0, 0, 1> yxxy;
		swizzle_2_to_4_nonwritable_t<int4, int32_t, 0, 1, 0, 1> xyxy;
		swizzle_2_to_4_nonwritable_t<int4, int32_t, 1, 1, 0, 1> yyxy;
		swizzle_2_to_4_nonwritable_t<int4, int32_t, 0, 0, 1, 1> xxyy;
		swizzle_2_to_4_nonwritable_t<int4, int32_t, 1, 0, 1, 1> yxyy;
		swizzle_2_to_4_nonwritable_t<int4, int32_t, 0, 1, 1, 1> xyyy;
		swizzle_2_to_4_nonwritable_t<int4, int32_t, 1, 1, 1, 1> yyyy;

		swizzle_2_to_2_nonwritable_t<int2, int32_t, 0, 0> rr;
		swizzle_2_to_2_writable_t<int2, int32_t, 1, 0> gr;
		swizzle_2_to_2_writable_t<int2, int32_t, 0, 1> rg;
		swizzle_2_to_2_nonwritable_t<int2, int32_t, 1, 1> gg;
		swizzle_2_to_3_nonwritable_t<int3, int32_t, 0, 0, 0> rrr;
		swizzle_2_to_3_nonwritable_t<int3, int32_t, 1, 0, 0> grr;
		swizzle_2_to_3_nonwritable_t<int3, int32_t, 0, 1, 0> rgr;
		swizzle_2_to_3_nonwritable_t<int3, int32_t, 1, 1, 0> ggr;
		swizzle_2_to_3_nonwritable_t<int3, int32_t, 0, 0, 1> rrg;
		swizzle_2_to_3_nonwritable_t<int3, int32_t, 1, 0, 1> grg;
		swizzle_2_to_3_nonwritable_t<int3, int32_t, 0, 1, 1> rgg;
		swizzle_2_to_3_nonwritable_t<int3, int32_t, 1, 1, 1> ggg;
		swizzle_2_to_4_nonwritable_t<int4, int32_t, 0, 0, 0, 0> rrrr;
		swizzle_2_to_4_nonwritable_t<int4, int32_t, 1, 0, 0, 0> grrr;
		swizzle_2_to_4_nonwritable_t<int4, int32_t, 0, 1, 0, 0> rgrr;
		swizzle_2_to_4_nonwritable_t<int4, int32_t, 1, 1, 0, 0> ggrr;
		swizzle_2_to_4_nonwritable_t<int4, int32_t, 0, 0, 1, 0> rrgr;
		swizzle_2_to_4_nonwritable_t<int4, int32_t, 1, 0, 1, 0> grgr;
		swizzle_2_to_4_nonwritable_t<int4, int32_t, 0, 1, 1, 0> rggr;
		swizzle_2_to_4_nonwritable_t<int4, int32_t, 1, 1, 1, 0> gggr;
		swizzle_2_to_4_nonwritable_t<int4, int32_t, 0, 0, 0, 1> rrrg;
		swizzle_2_to_4_nonwritable_t<int4, int32_t, 1, 0, 0, 1> grrg;
		swizzle_2_to_4_nonwritable_t<int4, int32_t, 0, 1, 0, 1> rgrg;
		swizzle_2_to_4_nonwritable_t<int4, int32_t, 1, 1, 0, 1> ggrg;
		swizzle_2_to_4_nonwritable_t<int4, int32_t, 0, 0, 1, 1> rrgg;
		swizzle_2_to_4_nonwritable_t<int4, int32_t, 1, 0, 1, 1> grgg;
		swizzle_2_to_4_nonwritable_t<int4, int32_t, 0, 1, 1, 1> rggg;
		swizzle_2_to_4_nonwritable_t<int4, int32_t, 1, 1, 1, 1> gggg;
	};

	// Default constructor.
	HLML_INLINE int2() {}

	// Initialises all components of the vector to the given scalar.
	HLML_INLINE explicit int2( const int32_t scalar );

	// Initialises all components of the vector to the corresponding scalars.
	HLML_INLINE int2( const int32_t x, const int32_t y );

	// Copy constructor.  Copies all elements of 'other' into the vector.
	HLML_INLINE int2( const int2& other );

	// Conversion constructor.  Casts all components of 'vec' from type bool32_t to type int32_t.
	HLML_INLINE explicit int2( const bool2& vec );

	// Conversion constructor.  Casts all components of 'vec' from type uint32_t to type int32_t.
	HLML_INLINE explicit int2( const uint2& vec );

	// Conversion constructor.  Casts all components of 'vec' from type float to type int32_t.
	HLML_INLINE explicit int2( const float2& vec );

	// Conversion constructor.  Casts all components of 'vec' from type double to type int32_t.
	HLML_INLINE explicit int2( const double2& vec );

	~int2() {}

	// Copies all elements of 'other' into the vector.
	HLML_INLINE int2 operator=( const int2& other );

	// Returns the vector component at the given index.
	// Index CANNOT be lower than 0 or greater than 1.
	HLML_INLINE int32_t& operator[]( const int32_t index );

	// Returns the vector component at the given index.
	// Index CANNOT be lower than 0 or greater than 1.
	HLML_INLINE const int32_t& operator[]( const int32_t index ) const;
};

#if defined( __clang__ ) || defined( __GNUC__ )
#pragma GCC diagnostic pop
#elif defined( _MSC_VER )
#pragma warning( pop )
#endif


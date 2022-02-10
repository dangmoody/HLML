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

struct int2;
struct int4;

#include "hlml_types.h"
#include "hlml_defines.h"

// ignore prohibition of anymous structs for GCC
#if defined( __clang__ ) || defined( __GNUC__ )
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
#elif defined( _MSC_VER )
#pragma warning( push )
#pragma warning( disable : 4201 ) // C4201 - nonstandard extension used : nameless struct/union
#endif

struct int3
{
	union
	{
		struct
		{
			int32_t x;
			int32_t y;
			int32_t z;
		};

		struct
		{
			int32_t r;
			int32_t g;
			int32_t b;
		};

		int32_t v[3];
	};

	// Default constructor.
	HLML_INLINE int3() {}

	// Initialises all components of the vector to the given scalar.
	HLML_INLINE explicit int3( const int32_t scalar );

	// Initialises all components of the vector to the corresponding scalars.
	HLML_INLINE int3( const int32_t x, const int32_t y, const int32_t z );

	// Copy constructor.  Copies all elements of 'other' into the vector.
	HLML_INLINE int3( const int2& other );

	// Copy constructor.  Copies all elements of 'other' into the vector.
	HLML_INLINE int3( const int3& other );

	~int3() {}

	// Copies all elements of 'other' into the vector.
	HLML_INLINE int3 operator=( const int2& other );

	// Copies all elements of 'other' into the vector.
	HLML_INLINE int3 operator=( const int3& other );

	// Returns the vector component at the given index.
	// Index CANNOT be lower than 0 or greater than 2.
	HLML_INLINE int32_t& operator[]( const int32_t index );

	// Returns the vector component at the given index.
	// Index CANNOT be lower than 0 or greater than 2.
	HLML_INLINE const int32_t& operator[]( const int32_t index ) const;

	// swizzle functions
	HLML_INLINE int2 xx() const;
	HLML_INLINE int2 xy() const;
	HLML_INLINE int2 xz() const;
	HLML_INLINE int2 yx() const;
	HLML_INLINE int2 yy() const;
	HLML_INLINE int2 yz() const;
	HLML_INLINE int2 zx() const;
	HLML_INLINE int2 zy() const;
	HLML_INLINE int2 zz() const;
	HLML_INLINE int3 xxx() const;
	HLML_INLINE int3 xxy() const;
	HLML_INLINE int3 xxz() const;
	HLML_INLINE int3 xyx() const;
	HLML_INLINE int3 xyy() const;
	HLML_INLINE int3 xyz() const;
	HLML_INLINE int3 xzx() const;
	HLML_INLINE int3 xzy() const;
	HLML_INLINE int3 xzz() const;
	HLML_INLINE int3 yxx() const;
	HLML_INLINE int3 yxy() const;
	HLML_INLINE int3 yxz() const;
	HLML_INLINE int3 yyx() const;
	HLML_INLINE int3 yyy() const;
	HLML_INLINE int3 yyz() const;
	HLML_INLINE int3 yzx() const;
	HLML_INLINE int3 yzy() const;
	HLML_INLINE int3 yzz() const;
	HLML_INLINE int3 zxx() const;
	HLML_INLINE int3 zxy() const;
	HLML_INLINE int3 zxz() const;
	HLML_INLINE int3 zyx() const;
	HLML_INLINE int3 zyy() const;
	HLML_INLINE int3 zyz() const;
	HLML_INLINE int3 zzx() const;
	HLML_INLINE int3 zzy() const;
	HLML_INLINE int3 zzz() const;
	HLML_INLINE int4 xxxx() const;
	HLML_INLINE int4 xxxy() const;
	HLML_INLINE int4 xxxz() const;
	HLML_INLINE int4 xxyx() const;
	HLML_INLINE int4 xxyy() const;
	HLML_INLINE int4 xxyz() const;
	HLML_INLINE int4 xxzx() const;
	HLML_INLINE int4 xxzy() const;
	HLML_INLINE int4 xxzz() const;
	HLML_INLINE int4 xyxx() const;
	HLML_INLINE int4 xyxy() const;
	HLML_INLINE int4 xyxz() const;
	HLML_INLINE int4 xyyx() const;
	HLML_INLINE int4 xyyy() const;
	HLML_INLINE int4 xyyz() const;
	HLML_INLINE int4 xyzx() const;
	HLML_INLINE int4 xyzy() const;
	HLML_INLINE int4 xyzz() const;
	HLML_INLINE int4 xzxx() const;
	HLML_INLINE int4 xzxy() const;
	HLML_INLINE int4 xzxz() const;
	HLML_INLINE int4 xzyx() const;
	HLML_INLINE int4 xzyy() const;
	HLML_INLINE int4 xzyz() const;
	HLML_INLINE int4 xzzx() const;
	HLML_INLINE int4 xzzy() const;
	HLML_INLINE int4 xzzz() const;
	HLML_INLINE int4 yxxx() const;
	HLML_INLINE int4 yxxy() const;
	HLML_INLINE int4 yxxz() const;
	HLML_INLINE int4 yxyx() const;
	HLML_INLINE int4 yxyy() const;
	HLML_INLINE int4 yxyz() const;
	HLML_INLINE int4 yxzx() const;
	HLML_INLINE int4 yxzy() const;
	HLML_INLINE int4 yxzz() const;
	HLML_INLINE int4 yyxx() const;
	HLML_INLINE int4 yyxy() const;
	HLML_INLINE int4 yyxz() const;
	HLML_INLINE int4 yyyx() const;
	HLML_INLINE int4 yyyy() const;
	HLML_INLINE int4 yyyz() const;
	HLML_INLINE int4 yyzx() const;
	HLML_INLINE int4 yyzy() const;
	HLML_INLINE int4 yyzz() const;
	HLML_INLINE int4 yzxx() const;
	HLML_INLINE int4 yzxy() const;
	HLML_INLINE int4 yzxz() const;
	HLML_INLINE int4 yzyx() const;
	HLML_INLINE int4 yzyy() const;
	HLML_INLINE int4 yzyz() const;
	HLML_INLINE int4 yzzx() const;
	HLML_INLINE int4 yzzy() const;
	HLML_INLINE int4 yzzz() const;
	HLML_INLINE int4 zxxx() const;
	HLML_INLINE int4 zxxy() const;
	HLML_INLINE int4 zxxz() const;
	HLML_INLINE int4 zxyx() const;
	HLML_INLINE int4 zxyy() const;
	HLML_INLINE int4 zxyz() const;
	HLML_INLINE int4 zxzx() const;
	HLML_INLINE int4 zxzy() const;
	HLML_INLINE int4 zxzz() const;
	HLML_INLINE int4 zyxx() const;
	HLML_INLINE int4 zyxy() const;
	HLML_INLINE int4 zyxz() const;
	HLML_INLINE int4 zyyx() const;
	HLML_INLINE int4 zyyy() const;
	HLML_INLINE int4 zyyz() const;
	HLML_INLINE int4 zyzx() const;
	HLML_INLINE int4 zyzy() const;
	HLML_INLINE int4 zyzz() const;
	HLML_INLINE int4 zzxx() const;
	HLML_INLINE int4 zzxy() const;
	HLML_INLINE int4 zzxz() const;
	HLML_INLINE int4 zzyx() const;
	HLML_INLINE int4 zzyy() const;
	HLML_INLINE int4 zzyz() const;
	HLML_INLINE int4 zzzx() const;
	HLML_INLINE int4 zzzy() const;
	HLML_INLINE int4 zzzz() const;

	HLML_INLINE int2 rr() const;
	HLML_INLINE int2 rg() const;
	HLML_INLINE int2 rb() const;
	HLML_INLINE int2 gr() const;
	HLML_INLINE int2 gg() const;
	HLML_INLINE int2 gb() const;
	HLML_INLINE int2 br() const;
	HLML_INLINE int2 bg() const;
	HLML_INLINE int2 bb() const;
	HLML_INLINE int3 rrr() const;
	HLML_INLINE int3 rrg() const;
	HLML_INLINE int3 rrb() const;
	HLML_INLINE int3 rgr() const;
	HLML_INLINE int3 rgg() const;
	HLML_INLINE int3 rgb() const;
	HLML_INLINE int3 rbr() const;
	HLML_INLINE int3 rbg() const;
	HLML_INLINE int3 rbb() const;
	HLML_INLINE int3 grr() const;
	HLML_INLINE int3 grg() const;
	HLML_INLINE int3 grb() const;
	HLML_INLINE int3 ggr() const;
	HLML_INLINE int3 ggg() const;
	HLML_INLINE int3 ggb() const;
	HLML_INLINE int3 gbr() const;
	HLML_INLINE int3 gbg() const;
	HLML_INLINE int3 gbb() const;
	HLML_INLINE int3 brr() const;
	HLML_INLINE int3 brg() const;
	HLML_INLINE int3 brb() const;
	HLML_INLINE int3 bgr() const;
	HLML_INLINE int3 bgg() const;
	HLML_INLINE int3 bgb() const;
	HLML_INLINE int3 bbr() const;
	HLML_INLINE int3 bbg() const;
	HLML_INLINE int3 bbb() const;
	HLML_INLINE int4 rrrr() const;
	HLML_INLINE int4 rrrg() const;
	HLML_INLINE int4 rrrb() const;
	HLML_INLINE int4 rrgr() const;
	HLML_INLINE int4 rrgg() const;
	HLML_INLINE int4 rrgb() const;
	HLML_INLINE int4 rrbr() const;
	HLML_INLINE int4 rrbg() const;
	HLML_INLINE int4 rrbb() const;
	HLML_INLINE int4 rgrr() const;
	HLML_INLINE int4 rgrg() const;
	HLML_INLINE int4 rgrb() const;
	HLML_INLINE int4 rggr() const;
	HLML_INLINE int4 rggg() const;
	HLML_INLINE int4 rggb() const;
	HLML_INLINE int4 rgbr() const;
	HLML_INLINE int4 rgbg() const;
	HLML_INLINE int4 rgbb() const;
	HLML_INLINE int4 rbrr() const;
	HLML_INLINE int4 rbrg() const;
	HLML_INLINE int4 rbrb() const;
	HLML_INLINE int4 rbgr() const;
	HLML_INLINE int4 rbgg() const;
	HLML_INLINE int4 rbgb() const;
	HLML_INLINE int4 rbbr() const;
	HLML_INLINE int4 rbbg() const;
	HLML_INLINE int4 rbbb() const;
	HLML_INLINE int4 grrr() const;
	HLML_INLINE int4 grrg() const;
	HLML_INLINE int4 grrb() const;
	HLML_INLINE int4 grgr() const;
	HLML_INLINE int4 grgg() const;
	HLML_INLINE int4 grgb() const;
	HLML_INLINE int4 grbr() const;
	HLML_INLINE int4 grbg() const;
	HLML_INLINE int4 grbb() const;
	HLML_INLINE int4 ggrr() const;
	HLML_INLINE int4 ggrg() const;
	HLML_INLINE int4 ggrb() const;
	HLML_INLINE int4 gggr() const;
	HLML_INLINE int4 gggg() const;
	HLML_INLINE int4 gggb() const;
	HLML_INLINE int4 ggbr() const;
	HLML_INLINE int4 ggbg() const;
	HLML_INLINE int4 ggbb() const;
	HLML_INLINE int4 gbrr() const;
	HLML_INLINE int4 gbrg() const;
	HLML_INLINE int4 gbrb() const;
	HLML_INLINE int4 gbgr() const;
	HLML_INLINE int4 gbgg() const;
	HLML_INLINE int4 gbgb() const;
	HLML_INLINE int4 gbbr() const;
	HLML_INLINE int4 gbbg() const;
	HLML_INLINE int4 gbbb() const;
	HLML_INLINE int4 brrr() const;
	HLML_INLINE int4 brrg() const;
	HLML_INLINE int4 brrb() const;
	HLML_INLINE int4 brgr() const;
	HLML_INLINE int4 brgg() const;
	HLML_INLINE int4 brgb() const;
	HLML_INLINE int4 brbr() const;
	HLML_INLINE int4 brbg() const;
	HLML_INLINE int4 brbb() const;
	HLML_INLINE int4 bgrr() const;
	HLML_INLINE int4 bgrg() const;
	HLML_INLINE int4 bgrb() const;
	HLML_INLINE int4 bggr() const;
	HLML_INLINE int4 bggg() const;
	HLML_INLINE int4 bggb() const;
	HLML_INLINE int4 bgbr() const;
	HLML_INLINE int4 bgbg() const;
	HLML_INLINE int4 bgbb() const;
	HLML_INLINE int4 bbrr() const;
	HLML_INLINE int4 bbrg() const;
	HLML_INLINE int4 bbrb() const;
	HLML_INLINE int4 bbgr() const;
	HLML_INLINE int4 bbgg() const;
	HLML_INLINE int4 bbgb() const;
	HLML_INLINE int4 bbbr() const;
	HLML_INLINE int4 bbbg() const;
	HLML_INLINE int4 bbbb() const;

};

#if defined( __clang__ ) || defined( __GNUC__ )
#pragma GCC diagnostic pop
#elif defined( _MSC_VER )
#pragma warning( pop )
#endif

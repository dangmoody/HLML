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

struct float2;
struct float4;

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

struct float3
{
	union
	{
		struct
		{
			float x;
			float y;
			float z;
		};

		struct
		{
			float r;
			float g;
			float b;
		};

		float v[3];
	};

	// Default constructor.
	HLML_INLINE float3() {}

	// Initialises all components of the vector to the given scalar.
	HLML_INLINE explicit float3( const float scalar );

	// Initialises all components of the vector to the corresponding scalars.
	HLML_INLINE float3( const float x, const float y, const float z );

	// Copy constructor.  Copies all elements of 'other' into the vector.
	HLML_INLINE float3( const float2& other );

	// Copy constructor.  Copies all elements of 'other' into the vector.
	HLML_INLINE float3( const float3& other );

	~float3() {}

	// Copies all elements of 'other' into the vector.
	HLML_INLINE float3 operator=( const float2& other );

	// Copies all elements of 'other' into the vector.
	HLML_INLINE float3 operator=( const float3& other );

	// Returns the vector component at the given index.
	// Index CANNOT be lower than 0 or greater than 2.
	HLML_INLINE float& operator[]( const int32_t index );

	// Returns the vector component at the given index.
	// Index CANNOT be lower than 0 or greater than 2.
	HLML_INLINE const float& operator[]( const int32_t index ) const;

	// swizzle functions
	HLML_INLINE float2 xx() const;
	HLML_INLINE float2 xy() const;
	HLML_INLINE float2 xz() const;
	HLML_INLINE float2 yx() const;
	HLML_INLINE float2 yy() const;
	HLML_INLINE float2 yz() const;
	HLML_INLINE float2 zx() const;
	HLML_INLINE float2 zy() const;
	HLML_INLINE float2 zz() const;
	HLML_INLINE float3 xxx() const;
	HLML_INLINE float3 xxy() const;
	HLML_INLINE float3 xxz() const;
	HLML_INLINE float3 xyx() const;
	HLML_INLINE float3 xyy() const;
	HLML_INLINE float3 xyz() const;
	HLML_INLINE float3 xzx() const;
	HLML_INLINE float3 xzy() const;
	HLML_INLINE float3 xzz() const;
	HLML_INLINE float3 yxx() const;
	HLML_INLINE float3 yxy() const;
	HLML_INLINE float3 yxz() const;
	HLML_INLINE float3 yyx() const;
	HLML_INLINE float3 yyy() const;
	HLML_INLINE float3 yyz() const;
	HLML_INLINE float3 yzx() const;
	HLML_INLINE float3 yzy() const;
	HLML_INLINE float3 yzz() const;
	HLML_INLINE float3 zxx() const;
	HLML_INLINE float3 zxy() const;
	HLML_INLINE float3 zxz() const;
	HLML_INLINE float3 zyx() const;
	HLML_INLINE float3 zyy() const;
	HLML_INLINE float3 zyz() const;
	HLML_INLINE float3 zzx() const;
	HLML_INLINE float3 zzy() const;
	HLML_INLINE float3 zzz() const;
	HLML_INLINE float4 xxxx() const;
	HLML_INLINE float4 xxxy() const;
	HLML_INLINE float4 xxxz() const;
	HLML_INLINE float4 xxyx() const;
	HLML_INLINE float4 xxyy() const;
	HLML_INLINE float4 xxyz() const;
	HLML_INLINE float4 xxzx() const;
	HLML_INLINE float4 xxzy() const;
	HLML_INLINE float4 xxzz() const;
	HLML_INLINE float4 xyxx() const;
	HLML_INLINE float4 xyxy() const;
	HLML_INLINE float4 xyxz() const;
	HLML_INLINE float4 xyyx() const;
	HLML_INLINE float4 xyyy() const;
	HLML_INLINE float4 xyyz() const;
	HLML_INLINE float4 xyzx() const;
	HLML_INLINE float4 xyzy() const;
	HLML_INLINE float4 xyzz() const;
	HLML_INLINE float4 xzxx() const;
	HLML_INLINE float4 xzxy() const;
	HLML_INLINE float4 xzxz() const;
	HLML_INLINE float4 xzyx() const;
	HLML_INLINE float4 xzyy() const;
	HLML_INLINE float4 xzyz() const;
	HLML_INLINE float4 xzzx() const;
	HLML_INLINE float4 xzzy() const;
	HLML_INLINE float4 xzzz() const;
	HLML_INLINE float4 yxxx() const;
	HLML_INLINE float4 yxxy() const;
	HLML_INLINE float4 yxxz() const;
	HLML_INLINE float4 yxyx() const;
	HLML_INLINE float4 yxyy() const;
	HLML_INLINE float4 yxyz() const;
	HLML_INLINE float4 yxzx() const;
	HLML_INLINE float4 yxzy() const;
	HLML_INLINE float4 yxzz() const;
	HLML_INLINE float4 yyxx() const;
	HLML_INLINE float4 yyxy() const;
	HLML_INLINE float4 yyxz() const;
	HLML_INLINE float4 yyyx() const;
	HLML_INLINE float4 yyyy() const;
	HLML_INLINE float4 yyyz() const;
	HLML_INLINE float4 yyzx() const;
	HLML_INLINE float4 yyzy() const;
	HLML_INLINE float4 yyzz() const;
	HLML_INLINE float4 yzxx() const;
	HLML_INLINE float4 yzxy() const;
	HLML_INLINE float4 yzxz() const;
	HLML_INLINE float4 yzyx() const;
	HLML_INLINE float4 yzyy() const;
	HLML_INLINE float4 yzyz() const;
	HLML_INLINE float4 yzzx() const;
	HLML_INLINE float4 yzzy() const;
	HLML_INLINE float4 yzzz() const;
	HLML_INLINE float4 zxxx() const;
	HLML_INLINE float4 zxxy() const;
	HLML_INLINE float4 zxxz() const;
	HLML_INLINE float4 zxyx() const;
	HLML_INLINE float4 zxyy() const;
	HLML_INLINE float4 zxyz() const;
	HLML_INLINE float4 zxzx() const;
	HLML_INLINE float4 zxzy() const;
	HLML_INLINE float4 zxzz() const;
	HLML_INLINE float4 zyxx() const;
	HLML_INLINE float4 zyxy() const;
	HLML_INLINE float4 zyxz() const;
	HLML_INLINE float4 zyyx() const;
	HLML_INLINE float4 zyyy() const;
	HLML_INLINE float4 zyyz() const;
	HLML_INLINE float4 zyzx() const;
	HLML_INLINE float4 zyzy() const;
	HLML_INLINE float4 zyzz() const;
	HLML_INLINE float4 zzxx() const;
	HLML_INLINE float4 zzxy() const;
	HLML_INLINE float4 zzxz() const;
	HLML_INLINE float4 zzyx() const;
	HLML_INLINE float4 zzyy() const;
	HLML_INLINE float4 zzyz() const;
	HLML_INLINE float4 zzzx() const;
	HLML_INLINE float4 zzzy() const;
	HLML_INLINE float4 zzzz() const;

	HLML_INLINE float2 rr() const;
	HLML_INLINE float2 rg() const;
	HLML_INLINE float2 rb() const;
	HLML_INLINE float2 gr() const;
	HLML_INLINE float2 gg() const;
	HLML_INLINE float2 gb() const;
	HLML_INLINE float2 br() const;
	HLML_INLINE float2 bg() const;
	HLML_INLINE float2 bb() const;
	HLML_INLINE float3 rrr() const;
	HLML_INLINE float3 rrg() const;
	HLML_INLINE float3 rrb() const;
	HLML_INLINE float3 rgr() const;
	HLML_INLINE float3 rgg() const;
	HLML_INLINE float3 rgb() const;
	HLML_INLINE float3 rbr() const;
	HLML_INLINE float3 rbg() const;
	HLML_INLINE float3 rbb() const;
	HLML_INLINE float3 grr() const;
	HLML_INLINE float3 grg() const;
	HLML_INLINE float3 grb() const;
	HLML_INLINE float3 ggr() const;
	HLML_INLINE float3 ggg() const;
	HLML_INLINE float3 ggb() const;
	HLML_INLINE float3 gbr() const;
	HLML_INLINE float3 gbg() const;
	HLML_INLINE float3 gbb() const;
	HLML_INLINE float3 brr() const;
	HLML_INLINE float3 brg() const;
	HLML_INLINE float3 brb() const;
	HLML_INLINE float3 bgr() const;
	HLML_INLINE float3 bgg() const;
	HLML_INLINE float3 bgb() const;
	HLML_INLINE float3 bbr() const;
	HLML_INLINE float3 bbg() const;
	HLML_INLINE float3 bbb() const;
	HLML_INLINE float4 rrrr() const;
	HLML_INLINE float4 rrrg() const;
	HLML_INLINE float4 rrrb() const;
	HLML_INLINE float4 rrgr() const;
	HLML_INLINE float4 rrgg() const;
	HLML_INLINE float4 rrgb() const;
	HLML_INLINE float4 rrbr() const;
	HLML_INLINE float4 rrbg() const;
	HLML_INLINE float4 rrbb() const;
	HLML_INLINE float4 rgrr() const;
	HLML_INLINE float4 rgrg() const;
	HLML_INLINE float4 rgrb() const;
	HLML_INLINE float4 rggr() const;
	HLML_INLINE float4 rggg() const;
	HLML_INLINE float4 rggb() const;
	HLML_INLINE float4 rgbr() const;
	HLML_INLINE float4 rgbg() const;
	HLML_INLINE float4 rgbb() const;
	HLML_INLINE float4 rbrr() const;
	HLML_INLINE float4 rbrg() const;
	HLML_INLINE float4 rbrb() const;
	HLML_INLINE float4 rbgr() const;
	HLML_INLINE float4 rbgg() const;
	HLML_INLINE float4 rbgb() const;
	HLML_INLINE float4 rbbr() const;
	HLML_INLINE float4 rbbg() const;
	HLML_INLINE float4 rbbb() const;
	HLML_INLINE float4 grrr() const;
	HLML_INLINE float4 grrg() const;
	HLML_INLINE float4 grrb() const;
	HLML_INLINE float4 grgr() const;
	HLML_INLINE float4 grgg() const;
	HLML_INLINE float4 grgb() const;
	HLML_INLINE float4 grbr() const;
	HLML_INLINE float4 grbg() const;
	HLML_INLINE float4 grbb() const;
	HLML_INLINE float4 ggrr() const;
	HLML_INLINE float4 ggrg() const;
	HLML_INLINE float4 ggrb() const;
	HLML_INLINE float4 gggr() const;
	HLML_INLINE float4 gggg() const;
	HLML_INLINE float4 gggb() const;
	HLML_INLINE float4 ggbr() const;
	HLML_INLINE float4 ggbg() const;
	HLML_INLINE float4 ggbb() const;
	HLML_INLINE float4 gbrr() const;
	HLML_INLINE float4 gbrg() const;
	HLML_INLINE float4 gbrb() const;
	HLML_INLINE float4 gbgr() const;
	HLML_INLINE float4 gbgg() const;
	HLML_INLINE float4 gbgb() const;
	HLML_INLINE float4 gbbr() const;
	HLML_INLINE float4 gbbg() const;
	HLML_INLINE float4 gbbb() const;
	HLML_INLINE float4 brrr() const;
	HLML_INLINE float4 brrg() const;
	HLML_INLINE float4 brrb() const;
	HLML_INLINE float4 brgr() const;
	HLML_INLINE float4 brgg() const;
	HLML_INLINE float4 brgb() const;
	HLML_INLINE float4 brbr() const;
	HLML_INLINE float4 brbg() const;
	HLML_INLINE float4 brbb() const;
	HLML_INLINE float4 bgrr() const;
	HLML_INLINE float4 bgrg() const;
	HLML_INLINE float4 bgrb() const;
	HLML_INLINE float4 bggr() const;
	HLML_INLINE float4 bggg() const;
	HLML_INLINE float4 bggb() const;
	HLML_INLINE float4 bgbr() const;
	HLML_INLINE float4 bgbg() const;
	HLML_INLINE float4 bgbb() const;
	HLML_INLINE float4 bbrr() const;
	HLML_INLINE float4 bbrg() const;
	HLML_INLINE float4 bbrb() const;
	HLML_INLINE float4 bbgr() const;
	HLML_INLINE float4 bbgg() const;
	HLML_INLINE float4 bbgb() const;
	HLML_INLINE float4 bbbr() const;
	HLML_INLINE float4 bbbg() const;
	HLML_INLINE float4 bbbb() const;

};

#if defined( __clang__ ) || defined( __GNUC__ )
#pragma GCC diagnostic pop
#elif defined( _MSC_VER )
#pragma warning( pop )
#endif

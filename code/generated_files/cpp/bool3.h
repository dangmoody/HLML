/*
===========================================================================

HLML
v2.2.0

MIT License:

Copyright (c) 2019 Dan Moody (daniel.guy.moody@gmail.com).

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

#include "hlml_types.h"
#include "hlml_defines.h"
#include "swizzle_templates.h"

#ifdef HLML_NAMESPACE
namespace hlml
{
#endif

struct bool2;
struct bool4;

struct int3;
struct uint3;
struct float3;
struct double3;

// ignore prohibition of anymous structs for GCC
#if defined( __clang__ ) || defined( __GNUC__ )
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
#elif defined( _MSC_VER )
#pragma warning( push )
#pragma warning( disable : 4201 ) // C4201 - nonstandard extension used : nameless struct/union
#endif

struct bool3
{
	union
	{
		struct
		{
			bool32_t x;
			bool32_t y;
			bool32_t z;
		};

		struct
		{
			bool32_t r;
			bool32_t g;
			bool32_t b;
		};

		bool32_t v[3];

		// swizzles
		swizzle_3_to_2_nonwritable_t<bool2, bool32_t, 0, 0> xx;
		swizzle_3_to_2_writable_t<bool2, bool32_t, 1, 0> yx;
		swizzle_3_to_2_writable_t<bool2, bool32_t, 2, 0> zx;
		swizzle_3_to_2_writable_t<bool2, bool32_t, 0, 1> xy;
		swizzle_3_to_2_nonwritable_t<bool2, bool32_t, 1, 1> yy;
		swizzle_3_to_2_writable_t<bool2, bool32_t, 2, 1> zy;
		swizzle_3_to_2_writable_t<bool2, bool32_t, 0, 2> xz;
		swizzle_3_to_2_writable_t<bool2, bool32_t, 1, 2> yz;
		swizzle_3_to_2_nonwritable_t<bool2, bool32_t, 2, 2> zz;
		swizzle_3_to_3_nonwritable_t<bool3, bool32_t, 0, 0, 0> xxx;
		swizzle_3_to_3_nonwritable_t<bool3, bool32_t, 1, 0, 0> yxx;
		swizzle_3_to_3_nonwritable_t<bool3, bool32_t, 2, 0, 0> zxx;
		swizzle_3_to_3_nonwritable_t<bool3, bool32_t, 0, 1, 0> xyx;
		swizzle_3_to_3_nonwritable_t<bool3, bool32_t, 1, 1, 0> yyx;
		swizzle_3_to_3_writable_t<bool3, bool32_t, 2, 1, 0> zyx;
		swizzle_3_to_3_nonwritable_t<bool3, bool32_t, 0, 2, 0> xzx;
		swizzle_3_to_3_writable_t<bool3, bool32_t, 1, 2, 0> yzx;
		swizzle_3_to_3_nonwritable_t<bool3, bool32_t, 2, 2, 0> zzx;
		swizzle_3_to_3_nonwritable_t<bool3, bool32_t, 0, 0, 1> xxy;
		swizzle_3_to_3_nonwritable_t<bool3, bool32_t, 1, 0, 1> yxy;
		swizzle_3_to_3_writable_t<bool3, bool32_t, 2, 0, 1> zxy;
		swizzle_3_to_3_nonwritable_t<bool3, bool32_t, 0, 1, 1> xyy;
		swizzle_3_to_3_nonwritable_t<bool3, bool32_t, 1, 1, 1> yyy;
		swizzle_3_to_3_nonwritable_t<bool3, bool32_t, 2, 1, 1> zyy;
		swizzle_3_to_3_writable_t<bool3, bool32_t, 0, 2, 1> xzy;
		swizzle_3_to_3_nonwritable_t<bool3, bool32_t, 1, 2, 1> yzy;
		swizzle_3_to_3_nonwritable_t<bool3, bool32_t, 2, 2, 1> zzy;
		swizzle_3_to_3_nonwritable_t<bool3, bool32_t, 0, 0, 2> xxz;
		swizzle_3_to_3_writable_t<bool3, bool32_t, 1, 0, 2> yxz;
		swizzle_3_to_3_nonwritable_t<bool3, bool32_t, 2, 0, 2> zxz;
		swizzle_3_to_3_writable_t<bool3, bool32_t, 0, 1, 2> xyz;
		swizzle_3_to_3_nonwritable_t<bool3, bool32_t, 1, 1, 2> yyz;
		swizzle_3_to_3_nonwritable_t<bool3, bool32_t, 2, 1, 2> zyz;
		swizzle_3_to_3_nonwritable_t<bool3, bool32_t, 0, 2, 2> xzz;
		swizzle_3_to_3_nonwritable_t<bool3, bool32_t, 1, 2, 2> yzz;
		swizzle_3_to_3_nonwritable_t<bool3, bool32_t, 2, 2, 2> zzz;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 0, 0, 0, 0> xxxx;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 1, 0, 0, 0> yxxx;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 2, 0, 0, 0> zxxx;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 0, 1, 0, 0> xyxx;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 1, 1, 0, 0> yyxx;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 2, 1, 0, 0> zyxx;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 0, 2, 0, 0> xzxx;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 1, 2, 0, 0> yzxx;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 2, 2, 0, 0> zzxx;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 0, 0, 1, 0> xxyx;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 1, 0, 1, 0> yxyx;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 2, 0, 1, 0> zxyx;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 0, 1, 1, 0> xyyx;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 1, 1, 1, 0> yyyx;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 2, 1, 1, 0> zyyx;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 0, 2, 1, 0> xzyx;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 1, 2, 1, 0> yzyx;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 2, 2, 1, 0> zzyx;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 0, 0, 2, 0> xxzx;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 1, 0, 2, 0> yxzx;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 2, 0, 2, 0> zxzx;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 0, 1, 2, 0> xyzx;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 1, 1, 2, 0> yyzx;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 2, 1, 2, 0> zyzx;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 0, 2, 2, 0> xzzx;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 1, 2, 2, 0> yzzx;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 2, 2, 2, 0> zzzx;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 0, 0, 0, 1> xxxy;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 1, 0, 0, 1> yxxy;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 2, 0, 0, 1> zxxy;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 0, 1, 0, 1> xyxy;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 1, 1, 0, 1> yyxy;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 2, 1, 0, 1> zyxy;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 0, 2, 0, 1> xzxy;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 1, 2, 0, 1> yzxy;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 2, 2, 0, 1> zzxy;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 0, 0, 1, 1> xxyy;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 1, 0, 1, 1> yxyy;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 2, 0, 1, 1> zxyy;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 0, 1, 1, 1> xyyy;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 1, 1, 1, 1> yyyy;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 2, 1, 1, 1> zyyy;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 0, 2, 1, 1> xzyy;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 1, 2, 1, 1> yzyy;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 2, 2, 1, 1> zzyy;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 0, 0, 2, 1> xxzy;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 1, 0, 2, 1> yxzy;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 2, 0, 2, 1> zxzy;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 0, 1, 2, 1> xyzy;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 1, 1, 2, 1> yyzy;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 2, 1, 2, 1> zyzy;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 0, 2, 2, 1> xzzy;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 1, 2, 2, 1> yzzy;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 2, 2, 2, 1> zzzy;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 0, 0, 0, 2> xxxz;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 1, 0, 0, 2> yxxz;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 2, 0, 0, 2> zxxz;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 0, 1, 0, 2> xyxz;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 1, 1, 0, 2> yyxz;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 2, 1, 0, 2> zyxz;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 0, 2, 0, 2> xzxz;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 1, 2, 0, 2> yzxz;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 2, 2, 0, 2> zzxz;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 0, 0, 1, 2> xxyz;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 1, 0, 1, 2> yxyz;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 2, 0, 1, 2> zxyz;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 0, 1, 1, 2> xyyz;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 1, 1, 1, 2> yyyz;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 2, 1, 1, 2> zyyz;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 0, 2, 1, 2> xzyz;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 1, 2, 1, 2> yzyz;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 2, 2, 1, 2> zzyz;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 0, 0, 2, 2> xxzz;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 1, 0, 2, 2> yxzz;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 2, 0, 2, 2> zxzz;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 0, 1, 2, 2> xyzz;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 1, 1, 2, 2> yyzz;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 2, 1, 2, 2> zyzz;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 0, 2, 2, 2> xzzz;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 1, 2, 2, 2> yzzz;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 2, 2, 2, 2> zzzz;

		swizzle_3_to_2_nonwritable_t<bool2, bool32_t, 0, 0> rr;
		swizzle_3_to_2_writable_t<bool2, bool32_t, 1, 0> gr;
		swizzle_3_to_2_writable_t<bool2, bool32_t, 2, 0> br;
		swizzle_3_to_2_writable_t<bool2, bool32_t, 0, 1> rg;
		swizzle_3_to_2_nonwritable_t<bool2, bool32_t, 1, 1> gg;
		swizzle_3_to_2_writable_t<bool2, bool32_t, 2, 1> bg;
		swizzle_3_to_2_writable_t<bool2, bool32_t, 0, 2> rb;
		swizzle_3_to_2_writable_t<bool2, bool32_t, 1, 2> gb;
		swizzle_3_to_2_nonwritable_t<bool2, bool32_t, 2, 2> bb;
		swizzle_3_to_3_nonwritable_t<bool3, bool32_t, 0, 0, 0> rrr;
		swizzle_3_to_3_nonwritable_t<bool3, bool32_t, 1, 0, 0> grr;
		swizzle_3_to_3_nonwritable_t<bool3, bool32_t, 2, 0, 0> brr;
		swizzle_3_to_3_nonwritable_t<bool3, bool32_t, 0, 1, 0> rgr;
		swizzle_3_to_3_nonwritable_t<bool3, bool32_t, 1, 1, 0> ggr;
		swizzle_3_to_3_writable_t<bool3, bool32_t, 2, 1, 0> bgr;
		swizzle_3_to_3_nonwritable_t<bool3, bool32_t, 0, 2, 0> rbr;
		swizzle_3_to_3_writable_t<bool3, bool32_t, 1, 2, 0> gbr;
		swizzle_3_to_3_nonwritable_t<bool3, bool32_t, 2, 2, 0> bbr;
		swizzle_3_to_3_nonwritable_t<bool3, bool32_t, 0, 0, 1> rrg;
		swizzle_3_to_3_nonwritable_t<bool3, bool32_t, 1, 0, 1> grg;
		swizzle_3_to_3_writable_t<bool3, bool32_t, 2, 0, 1> brg;
		swizzle_3_to_3_nonwritable_t<bool3, bool32_t, 0, 1, 1> rgg;
		swizzle_3_to_3_nonwritable_t<bool3, bool32_t, 1, 1, 1> ggg;
		swizzle_3_to_3_nonwritable_t<bool3, bool32_t, 2, 1, 1> bgg;
		swizzle_3_to_3_writable_t<bool3, bool32_t, 0, 2, 1> rbg;
		swizzle_3_to_3_nonwritable_t<bool3, bool32_t, 1, 2, 1> gbg;
		swizzle_3_to_3_nonwritable_t<bool3, bool32_t, 2, 2, 1> bbg;
		swizzle_3_to_3_nonwritable_t<bool3, bool32_t, 0, 0, 2> rrb;
		swizzle_3_to_3_writable_t<bool3, bool32_t, 1, 0, 2> grb;
		swizzle_3_to_3_nonwritable_t<bool3, bool32_t, 2, 0, 2> brb;
		swizzle_3_to_3_writable_t<bool3, bool32_t, 0, 1, 2> rgb;
		swizzle_3_to_3_nonwritable_t<bool3, bool32_t, 1, 1, 2> ggb;
		swizzle_3_to_3_nonwritable_t<bool3, bool32_t, 2, 1, 2> bgb;
		swizzle_3_to_3_nonwritable_t<bool3, bool32_t, 0, 2, 2> rbb;
		swizzle_3_to_3_nonwritable_t<bool3, bool32_t, 1, 2, 2> gbb;
		swizzle_3_to_3_nonwritable_t<bool3, bool32_t, 2, 2, 2> bbb;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 0, 0, 0, 0> rrrr;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 1, 0, 0, 0> grrr;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 2, 0, 0, 0> brrr;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 0, 1, 0, 0> rgrr;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 1, 1, 0, 0> ggrr;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 2, 1, 0, 0> bgrr;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 0, 2, 0, 0> rbrr;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 1, 2, 0, 0> gbrr;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 2, 2, 0, 0> bbrr;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 0, 0, 1, 0> rrgr;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 1, 0, 1, 0> grgr;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 2, 0, 1, 0> brgr;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 0, 1, 1, 0> rggr;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 1, 1, 1, 0> gggr;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 2, 1, 1, 0> bggr;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 0, 2, 1, 0> rbgr;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 1, 2, 1, 0> gbgr;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 2, 2, 1, 0> bbgr;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 0, 0, 2, 0> rrbr;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 1, 0, 2, 0> grbr;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 2, 0, 2, 0> brbr;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 0, 1, 2, 0> rgbr;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 1, 1, 2, 0> ggbr;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 2, 1, 2, 0> bgbr;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 0, 2, 2, 0> rbbr;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 1, 2, 2, 0> gbbr;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 2, 2, 2, 0> bbbr;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 0, 0, 0, 1> rrrg;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 1, 0, 0, 1> grrg;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 2, 0, 0, 1> brrg;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 0, 1, 0, 1> rgrg;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 1, 1, 0, 1> ggrg;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 2, 1, 0, 1> bgrg;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 0, 2, 0, 1> rbrg;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 1, 2, 0, 1> gbrg;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 2, 2, 0, 1> bbrg;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 0, 0, 1, 1> rrgg;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 1, 0, 1, 1> grgg;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 2, 0, 1, 1> brgg;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 0, 1, 1, 1> rggg;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 1, 1, 1, 1> gggg;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 2, 1, 1, 1> bggg;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 0, 2, 1, 1> rbgg;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 1, 2, 1, 1> gbgg;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 2, 2, 1, 1> bbgg;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 0, 0, 2, 1> rrbg;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 1, 0, 2, 1> grbg;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 2, 0, 2, 1> brbg;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 0, 1, 2, 1> rgbg;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 1, 1, 2, 1> ggbg;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 2, 1, 2, 1> bgbg;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 0, 2, 2, 1> rbbg;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 1, 2, 2, 1> gbbg;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 2, 2, 2, 1> bbbg;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 0, 0, 0, 2> rrrb;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 1, 0, 0, 2> grrb;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 2, 0, 0, 2> brrb;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 0, 1, 0, 2> rgrb;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 1, 1, 0, 2> ggrb;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 2, 1, 0, 2> bgrb;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 0, 2, 0, 2> rbrb;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 1, 2, 0, 2> gbrb;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 2, 2, 0, 2> bbrb;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 0, 0, 1, 2> rrgb;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 1, 0, 1, 2> grgb;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 2, 0, 1, 2> brgb;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 0, 1, 1, 2> rggb;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 1, 1, 1, 2> gggb;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 2, 1, 1, 2> bggb;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 0, 2, 1, 2> rbgb;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 1, 2, 1, 2> gbgb;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 2, 2, 1, 2> bbgb;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 0, 0, 2, 2> rrbb;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 1, 0, 2, 2> grbb;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 2, 0, 2, 2> brbb;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 0, 1, 2, 2> rgbb;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 1, 1, 2, 2> ggbb;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 2, 1, 2, 2> bgbb;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 0, 2, 2, 2> rbbb;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 1, 2, 2, 2> gbbb;
		swizzle_3_to_4_nonwritable_t<bool4, bool32_t, 2, 2, 2, 2> bbbb;
	};

	// Default constructor.
	HLML_INLINE bool3() {}

	// Initialises all components of the vector to the given scalar.
	HLML_INLINE explicit bool3( const bool32_t scalar );

	// Initialises all components of the vector to the corresponding scalars.
	HLML_INLINE bool3( const bool32_t x, const bool32_t y, const bool32_t z );

	// Copy constructor.  Copies all elements of 'other' into the vector.
	HLML_INLINE bool3( const bool3& other );

	// Conversion constructor.  Casts all components of 'vec' from type int32_t to type bool32_t.
	HLML_INLINE explicit bool3( const int3& vec );

	// Conversion constructor.  Casts all components of 'vec' from type uint32_t to type bool32_t.
	HLML_INLINE explicit bool3( const uint3& vec );

	// Conversion constructor.  Casts all components of 'vec' from type float to type bool32_t.
	HLML_INLINE explicit bool3( const float3& vec );

	// Conversion constructor.  Casts all components of 'vec' from type double to type bool32_t.
	HLML_INLINE explicit bool3( const double3& vec );

	// Sets the xy components of the vector to that of the corresponding input vector.  Sets the other corresponding vectors to the given scalars.
	HLML_INLINE bool3( const bool2& xy, const bool32_t z );

	// Sets the zw components of the vector to that of the corresponding input vector.  Sets the other corresponding vectors to the given scalars.
	HLML_INLINE bool3( const bool32_t x, const bool2& zw );

	~bool3() {}

	// Copies all elements of 'other' into the vector.
	HLML_INLINE bool3 operator=( const bool2& other );

	// Copies all elements of 'other' into the vector.
	HLML_INLINE bool3 operator=( const bool3& other );

	// Returns the vector component at the given index.
	// Index CANNOT be lower than 0 or greater than 2.
	HLML_INLINE bool32_t& operator[]( const int32_t index );

	// Returns the vector component at the given index.
	// Index CANNOT be lower than 0 or greater than 2.
	HLML_INLINE const bool32_t& operator[]( const int32_t index ) const;
};

#if defined( __clang__ ) || defined( __GNUC__ )
#pragma GCC diagnostic pop
#elif defined( _MSC_VER )
#pragma warning( pop )
#endif

#ifdef HLML_NAMESPACE
}
#endif


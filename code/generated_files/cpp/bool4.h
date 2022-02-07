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

struct bool2;
struct bool3;

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

struct bool4
{
	union
	{
		struct
		{
			bool32_t x;
			bool32_t y;
			bool32_t z;
			bool32_t w;
		};

		struct
		{
			bool32_t r;
			bool32_t g;
			bool32_t b;
			bool32_t a;
		};

		bool32_t v[4];
	};

	// Default constructor.
	HLML_INLINE bool4() {}

	// Initialises all components of the vector to the given scalar.
	HLML_INLINE explicit bool4( const bool32_t scalar );

	// Initialises all components of the vector to the corresponding scalars.
	HLML_INLINE bool4( const bool32_t x, const bool32_t y, const bool32_t z, const bool32_t w );

	// Copy constructor.  Copies all elements of 'other' into the vector.
	HLML_INLINE bool4( const bool2& other );

	// Copy constructor.  Copies all elements of 'other' into the vector.
	HLML_INLINE bool4( const bool3& other );

	// Copy constructor.  Copies all elements of 'other' into the vector.
	HLML_INLINE bool4( const bool4& other );

	~bool4() {}

	// Copies all elements of 'other' into the vector.
	HLML_INLINE bool4 operator=( const bool2& other );

	// Copies all elements of 'other' into the vector.
	HLML_INLINE bool4 operator=( const bool3& other );

	// Copies all elements of 'other' into the vector.
	HLML_INLINE bool4 operator=( const bool4& other );

	// Returns the vector component at the given index.
	// Index CANNOT be lower than 0 or greater than 3.
	HLML_INLINE bool32_t& operator[]( const int32_t index );

	// Returns the vector component at the given index.
	// Index CANNOT be lower than 0 or greater than 3.
	HLML_INLINE const bool32_t& operator[]( const int32_t index ) const;

	// swizzle functions
	HLML_INLINE bool2 xx() const;
	HLML_INLINE bool2 xy() const;
	HLML_INLINE bool2 xz() const;
	HLML_INLINE bool2 xw() const;
	HLML_INLINE bool2 yx() const;
	HLML_INLINE bool2 yy() const;
	HLML_INLINE bool2 yz() const;
	HLML_INLINE bool2 yw() const;
	HLML_INLINE bool2 zx() const;
	HLML_INLINE bool2 zy() const;
	HLML_INLINE bool2 zz() const;
	HLML_INLINE bool2 zw() const;
	HLML_INLINE bool2 wx() const;
	HLML_INLINE bool2 wy() const;
	HLML_INLINE bool2 wz() const;
	HLML_INLINE bool2 ww() const;
	HLML_INLINE bool3 xxx() const;
	HLML_INLINE bool3 xxy() const;
	HLML_INLINE bool3 xxz() const;
	HLML_INLINE bool3 xxw() const;
	HLML_INLINE bool3 xyx() const;
	HLML_INLINE bool3 xyy() const;
	HLML_INLINE bool3 xyz() const;
	HLML_INLINE bool3 xyw() const;
	HLML_INLINE bool3 xzx() const;
	HLML_INLINE bool3 xzy() const;
	HLML_INLINE bool3 xzz() const;
	HLML_INLINE bool3 xzw() const;
	HLML_INLINE bool3 xwx() const;
	HLML_INLINE bool3 xwy() const;
	HLML_INLINE bool3 xwz() const;
	HLML_INLINE bool3 xww() const;
	HLML_INLINE bool3 yxx() const;
	HLML_INLINE bool3 yxy() const;
	HLML_INLINE bool3 yxz() const;
	HLML_INLINE bool3 yxw() const;
	HLML_INLINE bool3 yyx() const;
	HLML_INLINE bool3 yyy() const;
	HLML_INLINE bool3 yyz() const;
	HLML_INLINE bool3 yyw() const;
	HLML_INLINE bool3 yzx() const;
	HLML_INLINE bool3 yzy() const;
	HLML_INLINE bool3 yzz() const;
	HLML_INLINE bool3 yzw() const;
	HLML_INLINE bool3 ywx() const;
	HLML_INLINE bool3 ywy() const;
	HLML_INLINE bool3 ywz() const;
	HLML_INLINE bool3 yww() const;
	HLML_INLINE bool3 zxx() const;
	HLML_INLINE bool3 zxy() const;
	HLML_INLINE bool3 zxz() const;
	HLML_INLINE bool3 zxw() const;
	HLML_INLINE bool3 zyx() const;
	HLML_INLINE bool3 zyy() const;
	HLML_INLINE bool3 zyz() const;
	HLML_INLINE bool3 zyw() const;
	HLML_INLINE bool3 zzx() const;
	HLML_INLINE bool3 zzy() const;
	HLML_INLINE bool3 zzz() const;
	HLML_INLINE bool3 zzw() const;
	HLML_INLINE bool3 zwx() const;
	HLML_INLINE bool3 zwy() const;
	HLML_INLINE bool3 zwz() const;
	HLML_INLINE bool3 zww() const;
	HLML_INLINE bool3 wxx() const;
	HLML_INLINE bool3 wxy() const;
	HLML_INLINE bool3 wxz() const;
	HLML_INLINE bool3 wxw() const;
	HLML_INLINE bool3 wyx() const;
	HLML_INLINE bool3 wyy() const;
	HLML_INLINE bool3 wyz() const;
	HLML_INLINE bool3 wyw() const;
	HLML_INLINE bool3 wzx() const;
	HLML_INLINE bool3 wzy() const;
	HLML_INLINE bool3 wzz() const;
	HLML_INLINE bool3 wzw() const;
	HLML_INLINE bool3 wwx() const;
	HLML_INLINE bool3 wwy() const;
	HLML_INLINE bool3 wwz() const;
	HLML_INLINE bool3 www() const;
	HLML_INLINE bool4 xxxx() const;
	HLML_INLINE bool4 xxxy() const;
	HLML_INLINE bool4 xxxz() const;
	HLML_INLINE bool4 xxxw() const;
	HLML_INLINE bool4 xxyx() const;
	HLML_INLINE bool4 xxyy() const;
	HLML_INLINE bool4 xxyz() const;
	HLML_INLINE bool4 xxyw() const;
	HLML_INLINE bool4 xxzx() const;
	HLML_INLINE bool4 xxzy() const;
	HLML_INLINE bool4 xxzz() const;
	HLML_INLINE bool4 xxzw() const;
	HLML_INLINE bool4 xxwx() const;
	HLML_INLINE bool4 xxwy() const;
	HLML_INLINE bool4 xxwz() const;
	HLML_INLINE bool4 xxww() const;
	HLML_INLINE bool4 xyxx() const;
	HLML_INLINE bool4 xyxy() const;
	HLML_INLINE bool4 xyxz() const;
	HLML_INLINE bool4 xyxw() const;
	HLML_INLINE bool4 xyyx() const;
	HLML_INLINE bool4 xyyy() const;
	HLML_INLINE bool4 xyyz() const;
	HLML_INLINE bool4 xyyw() const;
	HLML_INLINE bool4 xyzx() const;
	HLML_INLINE bool4 xyzy() const;
	HLML_INLINE bool4 xyzz() const;
	HLML_INLINE bool4 xyzw() const;
	HLML_INLINE bool4 xywx() const;
	HLML_INLINE bool4 xywy() const;
	HLML_INLINE bool4 xywz() const;
	HLML_INLINE bool4 xyww() const;
	HLML_INLINE bool4 xzxx() const;
	HLML_INLINE bool4 xzxy() const;
	HLML_INLINE bool4 xzxz() const;
	HLML_INLINE bool4 xzxw() const;
	HLML_INLINE bool4 xzyx() const;
	HLML_INLINE bool4 xzyy() const;
	HLML_INLINE bool4 xzyz() const;
	HLML_INLINE bool4 xzyw() const;
	HLML_INLINE bool4 xzzx() const;
	HLML_INLINE bool4 xzzy() const;
	HLML_INLINE bool4 xzzz() const;
	HLML_INLINE bool4 xzzw() const;
	HLML_INLINE bool4 xzwx() const;
	HLML_INLINE bool4 xzwy() const;
	HLML_INLINE bool4 xzwz() const;
	HLML_INLINE bool4 xzww() const;
	HLML_INLINE bool4 xwxx() const;
	HLML_INLINE bool4 xwxy() const;
	HLML_INLINE bool4 xwxz() const;
	HLML_INLINE bool4 xwxw() const;
	HLML_INLINE bool4 xwyx() const;
	HLML_INLINE bool4 xwyy() const;
	HLML_INLINE bool4 xwyz() const;
	HLML_INLINE bool4 xwyw() const;
	HLML_INLINE bool4 xwzx() const;
	HLML_INLINE bool4 xwzy() const;
	HLML_INLINE bool4 xwzz() const;
	HLML_INLINE bool4 xwzw() const;
	HLML_INLINE bool4 xwwx() const;
	HLML_INLINE bool4 xwwy() const;
	HLML_INLINE bool4 xwwz() const;
	HLML_INLINE bool4 xwww() const;
	HLML_INLINE bool4 yxxx() const;
	HLML_INLINE bool4 yxxy() const;
	HLML_INLINE bool4 yxxz() const;
	HLML_INLINE bool4 yxxw() const;
	HLML_INLINE bool4 yxyx() const;
	HLML_INLINE bool4 yxyy() const;
	HLML_INLINE bool4 yxyz() const;
	HLML_INLINE bool4 yxyw() const;
	HLML_INLINE bool4 yxzx() const;
	HLML_INLINE bool4 yxzy() const;
	HLML_INLINE bool4 yxzz() const;
	HLML_INLINE bool4 yxzw() const;
	HLML_INLINE bool4 yxwx() const;
	HLML_INLINE bool4 yxwy() const;
	HLML_INLINE bool4 yxwz() const;
	HLML_INLINE bool4 yxww() const;
	HLML_INLINE bool4 yyxx() const;
	HLML_INLINE bool4 yyxy() const;
	HLML_INLINE bool4 yyxz() const;
	HLML_INLINE bool4 yyxw() const;
	HLML_INLINE bool4 yyyx() const;
	HLML_INLINE bool4 yyyy() const;
	HLML_INLINE bool4 yyyz() const;
	HLML_INLINE bool4 yyyw() const;
	HLML_INLINE bool4 yyzx() const;
	HLML_INLINE bool4 yyzy() const;
	HLML_INLINE bool4 yyzz() const;
	HLML_INLINE bool4 yyzw() const;
	HLML_INLINE bool4 yywx() const;
	HLML_INLINE bool4 yywy() const;
	HLML_INLINE bool4 yywz() const;
	HLML_INLINE bool4 yyww() const;
	HLML_INLINE bool4 yzxx() const;
	HLML_INLINE bool4 yzxy() const;
	HLML_INLINE bool4 yzxz() const;
	HLML_INLINE bool4 yzxw() const;
	HLML_INLINE bool4 yzyx() const;
	HLML_INLINE bool4 yzyy() const;
	HLML_INLINE bool4 yzyz() const;
	HLML_INLINE bool4 yzyw() const;
	HLML_INLINE bool4 yzzx() const;
	HLML_INLINE bool4 yzzy() const;
	HLML_INLINE bool4 yzzz() const;
	HLML_INLINE bool4 yzzw() const;
	HLML_INLINE bool4 yzwx() const;
	HLML_INLINE bool4 yzwy() const;
	HLML_INLINE bool4 yzwz() const;
	HLML_INLINE bool4 yzww() const;
	HLML_INLINE bool4 ywxx() const;
	HLML_INLINE bool4 ywxy() const;
	HLML_INLINE bool4 ywxz() const;
	HLML_INLINE bool4 ywxw() const;
	HLML_INLINE bool4 ywyx() const;
	HLML_INLINE bool4 ywyy() const;
	HLML_INLINE bool4 ywyz() const;
	HLML_INLINE bool4 ywyw() const;
	HLML_INLINE bool4 ywzx() const;
	HLML_INLINE bool4 ywzy() const;
	HLML_INLINE bool4 ywzz() const;
	HLML_INLINE bool4 ywzw() const;
	HLML_INLINE bool4 ywwx() const;
	HLML_INLINE bool4 ywwy() const;
	HLML_INLINE bool4 ywwz() const;
	HLML_INLINE bool4 ywww() const;
	HLML_INLINE bool4 zxxx() const;
	HLML_INLINE bool4 zxxy() const;
	HLML_INLINE bool4 zxxz() const;
	HLML_INLINE bool4 zxxw() const;
	HLML_INLINE bool4 zxyx() const;
	HLML_INLINE bool4 zxyy() const;
	HLML_INLINE bool4 zxyz() const;
	HLML_INLINE bool4 zxyw() const;
	HLML_INLINE bool4 zxzx() const;
	HLML_INLINE bool4 zxzy() const;
	HLML_INLINE bool4 zxzz() const;
	HLML_INLINE bool4 zxzw() const;
	HLML_INLINE bool4 zxwx() const;
	HLML_INLINE bool4 zxwy() const;
	HLML_INLINE bool4 zxwz() const;
	HLML_INLINE bool4 zxww() const;
	HLML_INLINE bool4 zyxx() const;
	HLML_INLINE bool4 zyxy() const;
	HLML_INLINE bool4 zyxz() const;
	HLML_INLINE bool4 zyxw() const;
	HLML_INLINE bool4 zyyx() const;
	HLML_INLINE bool4 zyyy() const;
	HLML_INLINE bool4 zyyz() const;
	HLML_INLINE bool4 zyyw() const;
	HLML_INLINE bool4 zyzx() const;
	HLML_INLINE bool4 zyzy() const;
	HLML_INLINE bool4 zyzz() const;
	HLML_INLINE bool4 zyzw() const;
	HLML_INLINE bool4 zywx() const;
	HLML_INLINE bool4 zywy() const;
	HLML_INLINE bool4 zywz() const;
	HLML_INLINE bool4 zyww() const;
	HLML_INLINE bool4 zzxx() const;
	HLML_INLINE bool4 zzxy() const;
	HLML_INLINE bool4 zzxz() const;
	HLML_INLINE bool4 zzxw() const;
	HLML_INLINE bool4 zzyx() const;
	HLML_INLINE bool4 zzyy() const;
	HLML_INLINE bool4 zzyz() const;
	HLML_INLINE bool4 zzyw() const;
	HLML_INLINE bool4 zzzx() const;
	HLML_INLINE bool4 zzzy() const;
	HLML_INLINE bool4 zzzz() const;
	HLML_INLINE bool4 zzzw() const;
	HLML_INLINE bool4 zzwx() const;
	HLML_INLINE bool4 zzwy() const;
	HLML_INLINE bool4 zzwz() const;
	HLML_INLINE bool4 zzww() const;
	HLML_INLINE bool4 zwxx() const;
	HLML_INLINE bool4 zwxy() const;
	HLML_INLINE bool4 zwxz() const;
	HLML_INLINE bool4 zwxw() const;
	HLML_INLINE bool4 zwyx() const;
	HLML_INLINE bool4 zwyy() const;
	HLML_INLINE bool4 zwyz() const;
	HLML_INLINE bool4 zwyw() const;
	HLML_INLINE bool4 zwzx() const;
	HLML_INLINE bool4 zwzy() const;
	HLML_INLINE bool4 zwzz() const;
	HLML_INLINE bool4 zwzw() const;
	HLML_INLINE bool4 zwwx() const;
	HLML_INLINE bool4 zwwy() const;
	HLML_INLINE bool4 zwwz() const;
	HLML_INLINE bool4 zwww() const;
	HLML_INLINE bool4 wxxx() const;
	HLML_INLINE bool4 wxxy() const;
	HLML_INLINE bool4 wxxz() const;
	HLML_INLINE bool4 wxxw() const;
	HLML_INLINE bool4 wxyx() const;
	HLML_INLINE bool4 wxyy() const;
	HLML_INLINE bool4 wxyz() const;
	HLML_INLINE bool4 wxyw() const;
	HLML_INLINE bool4 wxzx() const;
	HLML_INLINE bool4 wxzy() const;
	HLML_INLINE bool4 wxzz() const;
	HLML_INLINE bool4 wxzw() const;
	HLML_INLINE bool4 wxwx() const;
	HLML_INLINE bool4 wxwy() const;
	HLML_INLINE bool4 wxwz() const;
	HLML_INLINE bool4 wxww() const;
	HLML_INLINE bool4 wyxx() const;
	HLML_INLINE bool4 wyxy() const;
	HLML_INLINE bool4 wyxz() const;
	HLML_INLINE bool4 wyxw() const;
	HLML_INLINE bool4 wyyx() const;
	HLML_INLINE bool4 wyyy() const;
	HLML_INLINE bool4 wyyz() const;
	HLML_INLINE bool4 wyyw() const;
	HLML_INLINE bool4 wyzx() const;
	HLML_INLINE bool4 wyzy() const;
	HLML_INLINE bool4 wyzz() const;
	HLML_INLINE bool4 wyzw() const;
	HLML_INLINE bool4 wywx() const;
	HLML_INLINE bool4 wywy() const;
	HLML_INLINE bool4 wywz() const;
	HLML_INLINE bool4 wyww() const;
	HLML_INLINE bool4 wzxx() const;
	HLML_INLINE bool4 wzxy() const;
	HLML_INLINE bool4 wzxz() const;
	HLML_INLINE bool4 wzxw() const;
	HLML_INLINE bool4 wzyx() const;
	HLML_INLINE bool4 wzyy() const;
	HLML_INLINE bool4 wzyz() const;
	HLML_INLINE bool4 wzyw() const;
	HLML_INLINE bool4 wzzx() const;
	HLML_INLINE bool4 wzzy() const;
	HLML_INLINE bool4 wzzz() const;
	HLML_INLINE bool4 wzzw() const;
	HLML_INLINE bool4 wzwx() const;
	HLML_INLINE bool4 wzwy() const;
	HLML_INLINE bool4 wzwz() const;
	HLML_INLINE bool4 wzww() const;
	HLML_INLINE bool4 wwxx() const;
	HLML_INLINE bool4 wwxy() const;
	HLML_INLINE bool4 wwxz() const;
	HLML_INLINE bool4 wwxw() const;
	HLML_INLINE bool4 wwyx() const;
	HLML_INLINE bool4 wwyy() const;
	HLML_INLINE bool4 wwyz() const;
	HLML_INLINE bool4 wwyw() const;
	HLML_INLINE bool4 wwzx() const;
	HLML_INLINE bool4 wwzy() const;
	HLML_INLINE bool4 wwzz() const;
	HLML_INLINE bool4 wwzw() const;
	HLML_INLINE bool4 wwwx() const;
	HLML_INLINE bool4 wwwy() const;
	HLML_INLINE bool4 wwwz() const;
	HLML_INLINE bool4 wwww() const;

	HLML_INLINE bool2 rr() const;
	HLML_INLINE bool2 rg() const;
	HLML_INLINE bool2 rb() const;
	HLML_INLINE bool2 ra() const;
	HLML_INLINE bool2 gr() const;
	HLML_INLINE bool2 gg() const;
	HLML_INLINE bool2 gb() const;
	HLML_INLINE bool2 ga() const;
	HLML_INLINE bool2 br() const;
	HLML_INLINE bool2 bg() const;
	HLML_INLINE bool2 bb() const;
	HLML_INLINE bool2 ba() const;
	HLML_INLINE bool2 ar() const;
	HLML_INLINE bool2 ag() const;
	HLML_INLINE bool2 ab() const;
	HLML_INLINE bool2 aa() const;
	HLML_INLINE bool3 rrr() const;
	HLML_INLINE bool3 rrg() const;
	HLML_INLINE bool3 rrb() const;
	HLML_INLINE bool3 rra() const;
	HLML_INLINE bool3 rgr() const;
	HLML_INLINE bool3 rgg() const;
	HLML_INLINE bool3 rgb() const;
	HLML_INLINE bool3 rga() const;
	HLML_INLINE bool3 rbr() const;
	HLML_INLINE bool3 rbg() const;
	HLML_INLINE bool3 rbb() const;
	HLML_INLINE bool3 rba() const;
	HLML_INLINE bool3 rar() const;
	HLML_INLINE bool3 rag() const;
	HLML_INLINE bool3 rab() const;
	HLML_INLINE bool3 raa() const;
	HLML_INLINE bool3 grr() const;
	HLML_INLINE bool3 grg() const;
	HLML_INLINE bool3 grb() const;
	HLML_INLINE bool3 gra() const;
	HLML_INLINE bool3 ggr() const;
	HLML_INLINE bool3 ggg() const;
	HLML_INLINE bool3 ggb() const;
	HLML_INLINE bool3 gga() const;
	HLML_INLINE bool3 gbr() const;
	HLML_INLINE bool3 gbg() const;
	HLML_INLINE bool3 gbb() const;
	HLML_INLINE bool3 gba() const;
	HLML_INLINE bool3 gar() const;
	HLML_INLINE bool3 gag() const;
	HLML_INLINE bool3 gab() const;
	HLML_INLINE bool3 gaa() const;
	HLML_INLINE bool3 brr() const;
	HLML_INLINE bool3 brg() const;
	HLML_INLINE bool3 brb() const;
	HLML_INLINE bool3 bra() const;
	HLML_INLINE bool3 bgr() const;
	HLML_INLINE bool3 bgg() const;
	HLML_INLINE bool3 bgb() const;
	HLML_INLINE bool3 bga() const;
	HLML_INLINE bool3 bbr() const;
	HLML_INLINE bool3 bbg() const;
	HLML_INLINE bool3 bbb() const;
	HLML_INLINE bool3 bba() const;
	HLML_INLINE bool3 bar() const;
	HLML_INLINE bool3 bag() const;
	HLML_INLINE bool3 bab() const;
	HLML_INLINE bool3 baa() const;
	HLML_INLINE bool3 arr() const;
	HLML_INLINE bool3 arg() const;
	HLML_INLINE bool3 arb() const;
	HLML_INLINE bool3 ara() const;
	HLML_INLINE bool3 agr() const;
	HLML_INLINE bool3 agg() const;
	HLML_INLINE bool3 agb() const;
	HLML_INLINE bool3 aga() const;
	HLML_INLINE bool3 abr() const;
	HLML_INLINE bool3 abg() const;
	HLML_INLINE bool3 abb() const;
	HLML_INLINE bool3 aba() const;
	HLML_INLINE bool3 aar() const;
	HLML_INLINE bool3 aag() const;
	HLML_INLINE bool3 aab() const;
	HLML_INLINE bool3 aaa() const;
	HLML_INLINE bool4 rrrr() const;
	HLML_INLINE bool4 rrrg() const;
	HLML_INLINE bool4 rrrb() const;
	HLML_INLINE bool4 rrra() const;
	HLML_INLINE bool4 rrgr() const;
	HLML_INLINE bool4 rrgg() const;
	HLML_INLINE bool4 rrgb() const;
	HLML_INLINE bool4 rrga() const;
	HLML_INLINE bool4 rrbr() const;
	HLML_INLINE bool4 rrbg() const;
	HLML_INLINE bool4 rrbb() const;
	HLML_INLINE bool4 rrba() const;
	HLML_INLINE bool4 rrar() const;
	HLML_INLINE bool4 rrag() const;
	HLML_INLINE bool4 rrab() const;
	HLML_INLINE bool4 rraa() const;
	HLML_INLINE bool4 rgrr() const;
	HLML_INLINE bool4 rgrg() const;
	HLML_INLINE bool4 rgrb() const;
	HLML_INLINE bool4 rgra() const;
	HLML_INLINE bool4 rggr() const;
	HLML_INLINE bool4 rggg() const;
	HLML_INLINE bool4 rggb() const;
	HLML_INLINE bool4 rgga() const;
	HLML_INLINE bool4 rgbr() const;
	HLML_INLINE bool4 rgbg() const;
	HLML_INLINE bool4 rgbb() const;
	HLML_INLINE bool4 rgba() const;
	HLML_INLINE bool4 rgar() const;
	HLML_INLINE bool4 rgag() const;
	HLML_INLINE bool4 rgab() const;
	HLML_INLINE bool4 rgaa() const;
	HLML_INLINE bool4 rbrr() const;
	HLML_INLINE bool4 rbrg() const;
	HLML_INLINE bool4 rbrb() const;
	HLML_INLINE bool4 rbra() const;
	HLML_INLINE bool4 rbgr() const;
	HLML_INLINE bool4 rbgg() const;
	HLML_INLINE bool4 rbgb() const;
	HLML_INLINE bool4 rbga() const;
	HLML_INLINE bool4 rbbr() const;
	HLML_INLINE bool4 rbbg() const;
	HLML_INLINE bool4 rbbb() const;
	HLML_INLINE bool4 rbba() const;
	HLML_INLINE bool4 rbar() const;
	HLML_INLINE bool4 rbag() const;
	HLML_INLINE bool4 rbab() const;
	HLML_INLINE bool4 rbaa() const;
	HLML_INLINE bool4 rarr() const;
	HLML_INLINE bool4 rarg() const;
	HLML_INLINE bool4 rarb() const;
	HLML_INLINE bool4 rara() const;
	HLML_INLINE bool4 ragr() const;
	HLML_INLINE bool4 ragg() const;
	HLML_INLINE bool4 ragb() const;
	HLML_INLINE bool4 raga() const;
	HLML_INLINE bool4 rabr() const;
	HLML_INLINE bool4 rabg() const;
	HLML_INLINE bool4 rabb() const;
	HLML_INLINE bool4 raba() const;
	HLML_INLINE bool4 raar() const;
	HLML_INLINE bool4 raag() const;
	HLML_INLINE bool4 raab() const;
	HLML_INLINE bool4 raaa() const;
	HLML_INLINE bool4 grrr() const;
	HLML_INLINE bool4 grrg() const;
	HLML_INLINE bool4 grrb() const;
	HLML_INLINE bool4 grra() const;
	HLML_INLINE bool4 grgr() const;
	HLML_INLINE bool4 grgg() const;
	HLML_INLINE bool4 grgb() const;
	HLML_INLINE bool4 grga() const;
	HLML_INLINE bool4 grbr() const;
	HLML_INLINE bool4 grbg() const;
	HLML_INLINE bool4 grbb() const;
	HLML_INLINE bool4 grba() const;
	HLML_INLINE bool4 grar() const;
	HLML_INLINE bool4 grag() const;
	HLML_INLINE bool4 grab() const;
	HLML_INLINE bool4 graa() const;
	HLML_INLINE bool4 ggrr() const;
	HLML_INLINE bool4 ggrg() const;
	HLML_INLINE bool4 ggrb() const;
	HLML_INLINE bool4 ggra() const;
	HLML_INLINE bool4 gggr() const;
	HLML_INLINE bool4 gggg() const;
	HLML_INLINE bool4 gggb() const;
	HLML_INLINE bool4 ggga() const;
	HLML_INLINE bool4 ggbr() const;
	HLML_INLINE bool4 ggbg() const;
	HLML_INLINE bool4 ggbb() const;
	HLML_INLINE bool4 ggba() const;
	HLML_INLINE bool4 ggar() const;
	HLML_INLINE bool4 ggag() const;
	HLML_INLINE bool4 ggab() const;
	HLML_INLINE bool4 ggaa() const;
	HLML_INLINE bool4 gbrr() const;
	HLML_INLINE bool4 gbrg() const;
	HLML_INLINE bool4 gbrb() const;
	HLML_INLINE bool4 gbra() const;
	HLML_INLINE bool4 gbgr() const;
	HLML_INLINE bool4 gbgg() const;
	HLML_INLINE bool4 gbgb() const;
	HLML_INLINE bool4 gbga() const;
	HLML_INLINE bool4 gbbr() const;
	HLML_INLINE bool4 gbbg() const;
	HLML_INLINE bool4 gbbb() const;
	HLML_INLINE bool4 gbba() const;
	HLML_INLINE bool4 gbar() const;
	HLML_INLINE bool4 gbag() const;
	HLML_INLINE bool4 gbab() const;
	HLML_INLINE bool4 gbaa() const;
	HLML_INLINE bool4 garr() const;
	HLML_INLINE bool4 garg() const;
	HLML_INLINE bool4 garb() const;
	HLML_INLINE bool4 gara() const;
	HLML_INLINE bool4 gagr() const;
	HLML_INLINE bool4 gagg() const;
	HLML_INLINE bool4 gagb() const;
	HLML_INLINE bool4 gaga() const;
	HLML_INLINE bool4 gabr() const;
	HLML_INLINE bool4 gabg() const;
	HLML_INLINE bool4 gabb() const;
	HLML_INLINE bool4 gaba() const;
	HLML_INLINE bool4 gaar() const;
	HLML_INLINE bool4 gaag() const;
	HLML_INLINE bool4 gaab() const;
	HLML_INLINE bool4 gaaa() const;
	HLML_INLINE bool4 brrr() const;
	HLML_INLINE bool4 brrg() const;
	HLML_INLINE bool4 brrb() const;
	HLML_INLINE bool4 brra() const;
	HLML_INLINE bool4 brgr() const;
	HLML_INLINE bool4 brgg() const;
	HLML_INLINE bool4 brgb() const;
	HLML_INLINE bool4 brga() const;
	HLML_INLINE bool4 brbr() const;
	HLML_INLINE bool4 brbg() const;
	HLML_INLINE bool4 brbb() const;
	HLML_INLINE bool4 brba() const;
	HLML_INLINE bool4 brar() const;
	HLML_INLINE bool4 brag() const;
	HLML_INLINE bool4 brab() const;
	HLML_INLINE bool4 braa() const;
	HLML_INLINE bool4 bgrr() const;
	HLML_INLINE bool4 bgrg() const;
	HLML_INLINE bool4 bgrb() const;
	HLML_INLINE bool4 bgra() const;
	HLML_INLINE bool4 bggr() const;
	HLML_INLINE bool4 bggg() const;
	HLML_INLINE bool4 bggb() const;
	HLML_INLINE bool4 bgga() const;
	HLML_INLINE bool4 bgbr() const;
	HLML_INLINE bool4 bgbg() const;
	HLML_INLINE bool4 bgbb() const;
	HLML_INLINE bool4 bgba() const;
	HLML_INLINE bool4 bgar() const;
	HLML_INLINE bool4 bgag() const;
	HLML_INLINE bool4 bgab() const;
	HLML_INLINE bool4 bgaa() const;
	HLML_INLINE bool4 bbrr() const;
	HLML_INLINE bool4 bbrg() const;
	HLML_INLINE bool4 bbrb() const;
	HLML_INLINE bool4 bbra() const;
	HLML_INLINE bool4 bbgr() const;
	HLML_INLINE bool4 bbgg() const;
	HLML_INLINE bool4 bbgb() const;
	HLML_INLINE bool4 bbga() const;
	HLML_INLINE bool4 bbbr() const;
	HLML_INLINE bool4 bbbg() const;
	HLML_INLINE bool4 bbbb() const;
	HLML_INLINE bool4 bbba() const;
	HLML_INLINE bool4 bbar() const;
	HLML_INLINE bool4 bbag() const;
	HLML_INLINE bool4 bbab() const;
	HLML_INLINE bool4 bbaa() const;
	HLML_INLINE bool4 barr() const;
	HLML_INLINE bool4 barg() const;
	HLML_INLINE bool4 barb() const;
	HLML_INLINE bool4 bara() const;
	HLML_INLINE bool4 bagr() const;
	HLML_INLINE bool4 bagg() const;
	HLML_INLINE bool4 bagb() const;
	HLML_INLINE bool4 baga() const;
	HLML_INLINE bool4 babr() const;
	HLML_INLINE bool4 babg() const;
	HLML_INLINE bool4 babb() const;
	HLML_INLINE bool4 baba() const;
	HLML_INLINE bool4 baar() const;
	HLML_INLINE bool4 baag() const;
	HLML_INLINE bool4 baab() const;
	HLML_INLINE bool4 baaa() const;
	HLML_INLINE bool4 arrr() const;
	HLML_INLINE bool4 arrg() const;
	HLML_INLINE bool4 arrb() const;
	HLML_INLINE bool4 arra() const;
	HLML_INLINE bool4 argr() const;
	HLML_INLINE bool4 argg() const;
	HLML_INLINE bool4 argb() const;
	HLML_INLINE bool4 arga() const;
	HLML_INLINE bool4 arbr() const;
	HLML_INLINE bool4 arbg() const;
	HLML_INLINE bool4 arbb() const;
	HLML_INLINE bool4 arba() const;
	HLML_INLINE bool4 arar() const;
	HLML_INLINE bool4 arag() const;
	HLML_INLINE bool4 arab() const;
	HLML_INLINE bool4 araa() const;
	HLML_INLINE bool4 agrr() const;
	HLML_INLINE bool4 agrg() const;
	HLML_INLINE bool4 agrb() const;
	HLML_INLINE bool4 agra() const;
	HLML_INLINE bool4 aggr() const;
	HLML_INLINE bool4 aggg() const;
	HLML_INLINE bool4 aggb() const;
	HLML_INLINE bool4 agga() const;
	HLML_INLINE bool4 agbr() const;
	HLML_INLINE bool4 agbg() const;
	HLML_INLINE bool4 agbb() const;
	HLML_INLINE bool4 agba() const;
	HLML_INLINE bool4 agar() const;
	HLML_INLINE bool4 agag() const;
	HLML_INLINE bool4 agab() const;
	HLML_INLINE bool4 agaa() const;
	HLML_INLINE bool4 abrr() const;
	HLML_INLINE bool4 abrg() const;
	HLML_INLINE bool4 abrb() const;
	HLML_INLINE bool4 abra() const;
	HLML_INLINE bool4 abgr() const;
	HLML_INLINE bool4 abgg() const;
	HLML_INLINE bool4 abgb() const;
	HLML_INLINE bool4 abga() const;
	HLML_INLINE bool4 abbr() const;
	HLML_INLINE bool4 abbg() const;
	HLML_INLINE bool4 abbb() const;
	HLML_INLINE bool4 abba() const;
	HLML_INLINE bool4 abar() const;
	HLML_INLINE bool4 abag() const;
	HLML_INLINE bool4 abab() const;
	HLML_INLINE bool4 abaa() const;
	HLML_INLINE bool4 aarr() const;
	HLML_INLINE bool4 aarg() const;
	HLML_INLINE bool4 aarb() const;
	HLML_INLINE bool4 aara() const;
	HLML_INLINE bool4 aagr() const;
	HLML_INLINE bool4 aagg() const;
	HLML_INLINE bool4 aagb() const;
	HLML_INLINE bool4 aaga() const;
	HLML_INLINE bool4 aabr() const;
	HLML_INLINE bool4 aabg() const;
	HLML_INLINE bool4 aabb() const;
	HLML_INLINE bool4 aaba() const;
	HLML_INLINE bool4 aaar() const;
	HLML_INLINE bool4 aaag() const;
	HLML_INLINE bool4 aaab() const;
	HLML_INLINE bool4 aaaa() const;

};

#if defined( __clang__ ) || defined( __GNUC__ )
#pragma GCC diagnostic pop
#elif defined( _MSC_VER )
#pragma warning( pop )
#endif
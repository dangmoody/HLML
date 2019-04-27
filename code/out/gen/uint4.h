/*
===========================================================================

hlml.
Copyright (c) Dan Moody 2019 - Present.

This file is part of hlml.

hlml is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

hlml is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with hlml.  If not, see <http://www.gnu.org/licenses/>.

===========================================================================
*/

// GENERATED FILE.  DO NOT EDIT.

#pragma once

#include "bool4.h"

#include <stdint.h>

struct uint2;
struct uint3;
struct float3;

// ignore prohibition of anymous structs for GCC
#if defined( __clang__ ) || defined( __GNUC__ )
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
#endif

/// \brief A vector of 4 uint32_ts with components xyzw and/or rgba.
/// Components are also stored as elements in an array via a union.
struct uint4
{
	union
	{
		struct
		{
			uint32_t x;
			uint32_t y;
			uint32_t z;
			uint32_t w;
		};

		struct
		{
			uint32_t r;
			uint32_t g;
			uint32_t b;
			uint32_t a;
		};

		uint32_t data[4] = { 0 };
	};

	/// Default constructor.  Initializes all values to zero.
	inline uint4();

	/// Initializes all components of the vector to the given scalar value.
	inline explicit uint4( const uint32_t x );

	/// Sets the xyzw members of the vector to the corresponding parameters.
	inline uint4( const uint32_t x, const uint32_t y, const uint32_t z, const uint32_t w );

	/// Copy constructor.  Copies the elements of the given vector via memcpy.
	inline uint4( const uint2& other );

	/// Copy constructor.  Copies the elements of the given vector via memcpy.
	inline uint4( const uint3& other );

	/// Copy constructor.  Copies the elements of the given vector via memcpy.
	inline uint4( const uint4& other );

	~uint4() {}

	/// Copies the elements of the given vector via a single memcpy.
	inline uint4 operator=( const uint2& rhs );

	/// Copies the elements of the given vector via a single memcpy.
	inline uint4 operator=( const uint3& rhs );

	/// Copies the elements of the given vector via a single memcpy.
	inline uint4 operator=( const uint4& rhs );

	/// \brief Returns the vector component at the given index.
	/// Index CANNOT be lower than 0 or higher than 3.
	inline const uint32_t& operator[]( const uint32_t index ) const;

	/// \brief Returns the vector component at the given index.
	/// Index CANNOT be lower than 0 or higher than 3.
	inline uint32_t& operator[]( const uint32_t index );

	// swizzle funcs
	inline uint2 xx() const { return uint2( x, x ); }
	inline uint2 yx() const { return uint2( y, x ); }
	inline uint2 xy() const { return uint2( x, y ); }
	inline uint2 yy() const { return uint2( y, y ); }

	inline uint3 xxx() const { return uint3( x, x, x ); }
	inline uint3 yxx() const { return uint3( y, x, x ); }
	inline uint3 zxx() const { return uint3( z, x, x ); }
	inline uint3 xyx() const { return uint3( x, y, x ); }
	inline uint3 yyx() const { return uint3( y, y, x ); }
	inline uint3 zyx() const { return uint3( z, y, x ); }
	inline uint3 xzx() const { return uint3( x, z, x ); }
	inline uint3 yzx() const { return uint3( y, z, x ); }
	inline uint3 zzx() const { return uint3( z, z, x ); }
	inline uint3 xxy() const { return uint3( x, x, y ); }
	inline uint3 yxy() const { return uint3( y, x, y ); }
	inline uint3 zxy() const { return uint3( z, x, y ); }
	inline uint3 xyy() const { return uint3( x, y, y ); }
	inline uint3 yyy() const { return uint3( y, y, y ); }
	inline uint3 zyy() const { return uint3( z, y, y ); }
	inline uint3 xzy() const { return uint3( x, z, y ); }
	inline uint3 yzy() const { return uint3( y, z, y ); }
	inline uint3 zzy() const { return uint3( z, z, y ); }
	inline uint3 xxz() const { return uint3( x, x, z ); }
	inline uint3 yxz() const { return uint3( y, x, z ); }
	inline uint3 zxz() const { return uint3( z, x, z ); }
	inline uint3 xyz() const { return uint3( x, y, z ); }
	inline uint3 yyz() const { return uint3( y, y, z ); }
	inline uint3 zyz() const { return uint3( z, y, z ); }
	inline uint3 xzz() const { return uint3( x, z, z ); }
	inline uint3 yzz() const { return uint3( y, z, z ); }
	inline uint3 zzz() const { return uint3( z, z, z ); }

	inline uint4 xxxx() const { return uint4( x, x, x, x ); }
	inline uint4 yxxx() const { return uint4( y, x, x, x ); }
	inline uint4 zxxx() const { return uint4( z, x, x, x ); }
	inline uint4 wxxx() const { return uint4( w, x, x, x ); }
	inline uint4 xyxx() const { return uint4( x, y, x, x ); }
	inline uint4 yyxx() const { return uint4( y, y, x, x ); }
	inline uint4 zyxx() const { return uint4( z, y, x, x ); }
	inline uint4 wyxx() const { return uint4( w, y, x, x ); }
	inline uint4 xzxx() const { return uint4( x, z, x, x ); }
	inline uint4 yzxx() const { return uint4( y, z, x, x ); }
	inline uint4 zzxx() const { return uint4( z, z, x, x ); }
	inline uint4 wzxx() const { return uint4( w, z, x, x ); }
	inline uint4 xwxx() const { return uint4( x, w, x, x ); }
	inline uint4 ywxx() const { return uint4( y, w, x, x ); }
	inline uint4 zwxx() const { return uint4( z, w, x, x ); }
	inline uint4 wwxx() const { return uint4( w, w, x, x ); }
	inline uint4 xxyx() const { return uint4( x, x, y, x ); }
	inline uint4 yxyx() const { return uint4( y, x, y, x ); }
	inline uint4 zxyx() const { return uint4( z, x, y, x ); }
	inline uint4 wxyx() const { return uint4( w, x, y, x ); }
	inline uint4 xyyx() const { return uint4( x, y, y, x ); }
	inline uint4 yyyx() const { return uint4( y, y, y, x ); }
	inline uint4 zyyx() const { return uint4( z, y, y, x ); }
	inline uint4 wyyx() const { return uint4( w, y, y, x ); }
	inline uint4 xzyx() const { return uint4( x, z, y, x ); }
	inline uint4 yzyx() const { return uint4( y, z, y, x ); }
	inline uint4 zzyx() const { return uint4( z, z, y, x ); }
	inline uint4 wzyx() const { return uint4( w, z, y, x ); }
	inline uint4 xwyx() const { return uint4( x, w, y, x ); }
	inline uint4 ywyx() const { return uint4( y, w, y, x ); }
	inline uint4 zwyx() const { return uint4( z, w, y, x ); }
	inline uint4 wwyx() const { return uint4( w, w, y, x ); }
	inline uint4 xxzx() const { return uint4( x, x, z, x ); }
	inline uint4 yxzx() const { return uint4( y, x, z, x ); }
	inline uint4 zxzx() const { return uint4( z, x, z, x ); }
	inline uint4 wxzx() const { return uint4( w, x, z, x ); }
	inline uint4 xyzx() const { return uint4( x, y, z, x ); }
	inline uint4 yyzx() const { return uint4( y, y, z, x ); }
	inline uint4 zyzx() const { return uint4( z, y, z, x ); }
	inline uint4 wyzx() const { return uint4( w, y, z, x ); }
	inline uint4 xzzx() const { return uint4( x, z, z, x ); }
	inline uint4 yzzx() const { return uint4( y, z, z, x ); }
	inline uint4 zzzx() const { return uint4( z, z, z, x ); }
	inline uint4 wzzx() const { return uint4( w, z, z, x ); }
	inline uint4 xwzx() const { return uint4( x, w, z, x ); }
	inline uint4 ywzx() const { return uint4( y, w, z, x ); }
	inline uint4 zwzx() const { return uint4( z, w, z, x ); }
	inline uint4 wwzx() const { return uint4( w, w, z, x ); }
	inline uint4 xxwx() const { return uint4( x, x, w, x ); }
	inline uint4 yxwx() const { return uint4( y, x, w, x ); }
	inline uint4 zxwx() const { return uint4( z, x, w, x ); }
	inline uint4 wxwx() const { return uint4( w, x, w, x ); }
	inline uint4 xywx() const { return uint4( x, y, w, x ); }
	inline uint4 yywx() const { return uint4( y, y, w, x ); }
	inline uint4 zywx() const { return uint4( z, y, w, x ); }
	inline uint4 wywx() const { return uint4( w, y, w, x ); }
	inline uint4 xzwx() const { return uint4( x, z, w, x ); }
	inline uint4 yzwx() const { return uint4( y, z, w, x ); }
	inline uint4 zzwx() const { return uint4( z, z, w, x ); }
	inline uint4 wzwx() const { return uint4( w, z, w, x ); }
	inline uint4 xwwx() const { return uint4( x, w, w, x ); }
	inline uint4 ywwx() const { return uint4( y, w, w, x ); }
	inline uint4 zwwx() const { return uint4( z, w, w, x ); }
	inline uint4 wwwx() const { return uint4( w, w, w, x ); }
	inline uint4 xxxy() const { return uint4( x, x, x, y ); }
	inline uint4 yxxy() const { return uint4( y, x, x, y ); }
	inline uint4 zxxy() const { return uint4( z, x, x, y ); }
	inline uint4 wxxy() const { return uint4( w, x, x, y ); }
	inline uint4 xyxy() const { return uint4( x, y, x, y ); }
	inline uint4 yyxy() const { return uint4( y, y, x, y ); }
	inline uint4 zyxy() const { return uint4( z, y, x, y ); }
	inline uint4 wyxy() const { return uint4( w, y, x, y ); }
	inline uint4 xzxy() const { return uint4( x, z, x, y ); }
	inline uint4 yzxy() const { return uint4( y, z, x, y ); }
	inline uint4 zzxy() const { return uint4( z, z, x, y ); }
	inline uint4 wzxy() const { return uint4( w, z, x, y ); }
	inline uint4 xwxy() const { return uint4( x, w, x, y ); }
	inline uint4 ywxy() const { return uint4( y, w, x, y ); }
	inline uint4 zwxy() const { return uint4( z, w, x, y ); }
	inline uint4 wwxy() const { return uint4( w, w, x, y ); }
	inline uint4 xxyy() const { return uint4( x, x, y, y ); }
	inline uint4 yxyy() const { return uint4( y, x, y, y ); }
	inline uint4 zxyy() const { return uint4( z, x, y, y ); }
	inline uint4 wxyy() const { return uint4( w, x, y, y ); }
	inline uint4 xyyy() const { return uint4( x, y, y, y ); }
	inline uint4 yyyy() const { return uint4( y, y, y, y ); }
	inline uint4 zyyy() const { return uint4( z, y, y, y ); }
	inline uint4 wyyy() const { return uint4( w, y, y, y ); }
	inline uint4 xzyy() const { return uint4( x, z, y, y ); }
	inline uint4 yzyy() const { return uint4( y, z, y, y ); }
	inline uint4 zzyy() const { return uint4( z, z, y, y ); }
	inline uint4 wzyy() const { return uint4( w, z, y, y ); }
	inline uint4 xwyy() const { return uint4( x, w, y, y ); }
	inline uint4 ywyy() const { return uint4( y, w, y, y ); }
	inline uint4 zwyy() const { return uint4( z, w, y, y ); }
	inline uint4 wwyy() const { return uint4( w, w, y, y ); }
	inline uint4 xxzy() const { return uint4( x, x, z, y ); }
	inline uint4 yxzy() const { return uint4( y, x, z, y ); }
	inline uint4 zxzy() const { return uint4( z, x, z, y ); }
	inline uint4 wxzy() const { return uint4( w, x, z, y ); }
	inline uint4 xyzy() const { return uint4( x, y, z, y ); }
	inline uint4 yyzy() const { return uint4( y, y, z, y ); }
	inline uint4 zyzy() const { return uint4( z, y, z, y ); }
	inline uint4 wyzy() const { return uint4( w, y, z, y ); }
	inline uint4 xzzy() const { return uint4( x, z, z, y ); }
	inline uint4 yzzy() const { return uint4( y, z, z, y ); }
	inline uint4 zzzy() const { return uint4( z, z, z, y ); }
	inline uint4 wzzy() const { return uint4( w, z, z, y ); }
	inline uint4 xwzy() const { return uint4( x, w, z, y ); }
	inline uint4 ywzy() const { return uint4( y, w, z, y ); }
	inline uint4 zwzy() const { return uint4( z, w, z, y ); }
	inline uint4 wwzy() const { return uint4( w, w, z, y ); }
	inline uint4 xxwy() const { return uint4( x, x, w, y ); }
	inline uint4 yxwy() const { return uint4( y, x, w, y ); }
	inline uint4 zxwy() const { return uint4( z, x, w, y ); }
	inline uint4 wxwy() const { return uint4( w, x, w, y ); }
	inline uint4 xywy() const { return uint4( x, y, w, y ); }
	inline uint4 yywy() const { return uint4( y, y, w, y ); }
	inline uint4 zywy() const { return uint4( z, y, w, y ); }
	inline uint4 wywy() const { return uint4( w, y, w, y ); }
	inline uint4 xzwy() const { return uint4( x, z, w, y ); }
	inline uint4 yzwy() const { return uint4( y, z, w, y ); }
	inline uint4 zzwy() const { return uint4( z, z, w, y ); }
	inline uint4 wzwy() const { return uint4( w, z, w, y ); }
	inline uint4 xwwy() const { return uint4( x, w, w, y ); }
	inline uint4 ywwy() const { return uint4( y, w, w, y ); }
	inline uint4 zwwy() const { return uint4( z, w, w, y ); }
	inline uint4 wwwy() const { return uint4( w, w, w, y ); }
	inline uint4 xxxz() const { return uint4( x, x, x, z ); }
	inline uint4 yxxz() const { return uint4( y, x, x, z ); }
	inline uint4 zxxz() const { return uint4( z, x, x, z ); }
	inline uint4 wxxz() const { return uint4( w, x, x, z ); }
	inline uint4 xyxz() const { return uint4( x, y, x, z ); }
	inline uint4 yyxz() const { return uint4( y, y, x, z ); }
	inline uint4 zyxz() const { return uint4( z, y, x, z ); }
	inline uint4 wyxz() const { return uint4( w, y, x, z ); }
	inline uint4 xzxz() const { return uint4( x, z, x, z ); }
	inline uint4 yzxz() const { return uint4( y, z, x, z ); }
	inline uint4 zzxz() const { return uint4( z, z, x, z ); }
	inline uint4 wzxz() const { return uint4( w, z, x, z ); }
	inline uint4 xwxz() const { return uint4( x, w, x, z ); }
	inline uint4 ywxz() const { return uint4( y, w, x, z ); }
	inline uint4 zwxz() const { return uint4( z, w, x, z ); }
	inline uint4 wwxz() const { return uint4( w, w, x, z ); }
	inline uint4 xxyz() const { return uint4( x, x, y, z ); }
	inline uint4 yxyz() const { return uint4( y, x, y, z ); }
	inline uint4 zxyz() const { return uint4( z, x, y, z ); }
	inline uint4 wxyz() const { return uint4( w, x, y, z ); }
	inline uint4 xyyz() const { return uint4( x, y, y, z ); }
	inline uint4 yyyz() const { return uint4( y, y, y, z ); }
	inline uint4 zyyz() const { return uint4( z, y, y, z ); }
	inline uint4 wyyz() const { return uint4( w, y, y, z ); }
	inline uint4 xzyz() const { return uint4( x, z, y, z ); }
	inline uint4 yzyz() const { return uint4( y, z, y, z ); }
	inline uint4 zzyz() const { return uint4( z, z, y, z ); }
	inline uint4 wzyz() const { return uint4( w, z, y, z ); }
	inline uint4 xwyz() const { return uint4( x, w, y, z ); }
	inline uint4 ywyz() const { return uint4( y, w, y, z ); }
	inline uint4 zwyz() const { return uint4( z, w, y, z ); }
	inline uint4 wwyz() const { return uint4( w, w, y, z ); }
	inline uint4 xxzz() const { return uint4( x, x, z, z ); }
	inline uint4 yxzz() const { return uint4( y, x, z, z ); }
	inline uint4 zxzz() const { return uint4( z, x, z, z ); }
	inline uint4 wxzz() const { return uint4( w, x, z, z ); }
	inline uint4 xyzz() const { return uint4( x, y, z, z ); }
	inline uint4 yyzz() const { return uint4( y, y, z, z ); }
	inline uint4 zyzz() const { return uint4( z, y, z, z ); }
	inline uint4 wyzz() const { return uint4( w, y, z, z ); }
	inline uint4 xzzz() const { return uint4( x, z, z, z ); }
	inline uint4 yzzz() const { return uint4( y, z, z, z ); }
	inline uint4 zzzz() const { return uint4( z, z, z, z ); }
	inline uint4 wzzz() const { return uint4( w, z, z, z ); }
	inline uint4 xwzz() const { return uint4( x, w, z, z ); }
	inline uint4 ywzz() const { return uint4( y, w, z, z ); }
	inline uint4 zwzz() const { return uint4( z, w, z, z ); }
	inline uint4 wwzz() const { return uint4( w, w, z, z ); }
	inline uint4 xxwz() const { return uint4( x, x, w, z ); }
	inline uint4 yxwz() const { return uint4( y, x, w, z ); }
	inline uint4 zxwz() const { return uint4( z, x, w, z ); }
	inline uint4 wxwz() const { return uint4( w, x, w, z ); }
	inline uint4 xywz() const { return uint4( x, y, w, z ); }
	inline uint4 yywz() const { return uint4( y, y, w, z ); }
	inline uint4 zywz() const { return uint4( z, y, w, z ); }
	inline uint4 wywz() const { return uint4( w, y, w, z ); }
	inline uint4 xzwz() const { return uint4( x, z, w, z ); }
	inline uint4 yzwz() const { return uint4( y, z, w, z ); }
	inline uint4 zzwz() const { return uint4( z, z, w, z ); }
	inline uint4 wzwz() const { return uint4( w, z, w, z ); }
	inline uint4 xwwz() const { return uint4( x, w, w, z ); }
	inline uint4 ywwz() const { return uint4( y, w, w, z ); }
	inline uint4 zwwz() const { return uint4( z, w, w, z ); }
	inline uint4 wwwz() const { return uint4( w, w, w, z ); }
	inline uint4 xxxw() const { return uint4( x, x, x, w ); }
	inline uint4 yxxw() const { return uint4( y, x, x, w ); }
	inline uint4 zxxw() const { return uint4( z, x, x, w ); }
	inline uint4 wxxw() const { return uint4( w, x, x, w ); }
	inline uint4 xyxw() const { return uint4( x, y, x, w ); }
	inline uint4 yyxw() const { return uint4( y, y, x, w ); }
	inline uint4 zyxw() const { return uint4( z, y, x, w ); }
	inline uint4 wyxw() const { return uint4( w, y, x, w ); }
	inline uint4 xzxw() const { return uint4( x, z, x, w ); }
	inline uint4 yzxw() const { return uint4( y, z, x, w ); }
	inline uint4 zzxw() const { return uint4( z, z, x, w ); }
	inline uint4 wzxw() const { return uint4( w, z, x, w ); }
	inline uint4 xwxw() const { return uint4( x, w, x, w ); }
	inline uint4 ywxw() const { return uint4( y, w, x, w ); }
	inline uint4 zwxw() const { return uint4( z, w, x, w ); }
	inline uint4 wwxw() const { return uint4( w, w, x, w ); }
	inline uint4 xxyw() const { return uint4( x, x, y, w ); }
	inline uint4 yxyw() const { return uint4( y, x, y, w ); }
	inline uint4 zxyw() const { return uint4( z, x, y, w ); }
	inline uint4 wxyw() const { return uint4( w, x, y, w ); }
	inline uint4 xyyw() const { return uint4( x, y, y, w ); }
	inline uint4 yyyw() const { return uint4( y, y, y, w ); }
	inline uint4 zyyw() const { return uint4( z, y, y, w ); }
	inline uint4 wyyw() const { return uint4( w, y, y, w ); }
	inline uint4 xzyw() const { return uint4( x, z, y, w ); }
	inline uint4 yzyw() const { return uint4( y, z, y, w ); }
	inline uint4 zzyw() const { return uint4( z, z, y, w ); }
	inline uint4 wzyw() const { return uint4( w, z, y, w ); }
	inline uint4 xwyw() const { return uint4( x, w, y, w ); }
	inline uint4 ywyw() const { return uint4( y, w, y, w ); }
	inline uint4 zwyw() const { return uint4( z, w, y, w ); }
	inline uint4 wwyw() const { return uint4( w, w, y, w ); }
	inline uint4 xxzw() const { return uint4( x, x, z, w ); }
	inline uint4 yxzw() const { return uint4( y, x, z, w ); }
	inline uint4 zxzw() const { return uint4( z, x, z, w ); }
	inline uint4 wxzw() const { return uint4( w, x, z, w ); }
	inline uint4 xyzw() const { return uint4( x, y, z, w ); }
	inline uint4 yyzw() const { return uint4( y, y, z, w ); }
	inline uint4 zyzw() const { return uint4( z, y, z, w ); }
	inline uint4 wyzw() const { return uint4( w, y, z, w ); }
	inline uint4 xzzw() const { return uint4( x, z, z, w ); }
	inline uint4 yzzw() const { return uint4( y, z, z, w ); }
	inline uint4 zzzw() const { return uint4( z, z, z, w ); }
	inline uint4 wzzw() const { return uint4( w, z, z, w ); }
	inline uint4 xwzw() const { return uint4( x, w, z, w ); }
	inline uint4 ywzw() const { return uint4( y, w, z, w ); }
	inline uint4 zwzw() const { return uint4( z, w, z, w ); }
	inline uint4 wwzw() const { return uint4( w, w, z, w ); }
	inline uint4 xxww() const { return uint4( x, x, w, w ); }
	inline uint4 yxww() const { return uint4( y, x, w, w ); }
	inline uint4 zxww() const { return uint4( z, x, w, w ); }
	inline uint4 wxww() const { return uint4( w, x, w, w ); }
	inline uint4 xyww() const { return uint4( x, y, w, w ); }
	inline uint4 yyww() const { return uint4( y, y, w, w ); }
	inline uint4 zyww() const { return uint4( z, y, w, w ); }
	inline uint4 wyww() const { return uint4( w, y, w, w ); }
	inline uint4 xzww() const { return uint4( x, z, w, w ); }
	inline uint4 yzww() const { return uint4( y, z, w, w ); }
	inline uint4 zzww() const { return uint4( z, z, w, w ); }
	inline uint4 wzww() const { return uint4( w, z, w, w ); }
	inline uint4 xwww() const { return uint4( x, w, w, w ); }
	inline uint4 ywww() const { return uint4( y, w, w, w ); }
	inline uint4 zwww() const { return uint4( z, w, w, w ); }
	inline uint4 wwww() const { return uint4( w, w, w, w ); }

};

#if defined( __clang__ ) || defined( __GNUC__ )
#pragma GCC diagnostic pop
#endif

/// \relates uint4
/// \brief Returns true if the all the components of the left-hand-side uint4 match the other one, otherwise returns false.
inline bool operator==( const uint4& lhs, const uint4& rhs );

/// \relates uint4
/// \brief Returns true if not all of the components of the left-hand-side uint4 match the other one, otherwise returns false.
inline bool operator!=( const uint4& lhs, const uint4& rhs );

#include "uint4.inl"

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
#include "../hlml_types.h"

struct float2;
struct float3;
struct float3;

// ignore prohibition of anymous structs for GCC
#if defined( __clang__ ) || defined( __GNUC__ )
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
#elif defined( _MSC_VER )
#pragma warning( push )
#pragma warning( disable : 4201 ) // C4201 - nonstandard extension used : nameless struct/union
#endif

/// \brief A vector of 4 floats with components xyzw.
/// Components are also stored as elements in an array via a union.
struct float4
{
	union
	{
		struct
		{
			float x;
			float y;
			float z;
			float w;
		};

		struct
		{
			float r;
			float g;
			float b;
			float a;
		};

		float data[4] = { 0 };
	};

	/// Default constructor.  Initializes all values to zero.
	inline float4();

	/// Initializes all components of the vector to the given scalar value.
	inline explicit float4( const float x );

	/// Sets the xyzw members of the vector to the corresponding parameters.
	inline float4( const float x, const float y, const float z, const float w );

	/// Copy constructor.  Copies the elements of the given vector via memcpy.
	inline float4( const float2& other );

	/// Copy constructor.  Copies the elements of the given vector via memcpy.
	inline float4( const float3& other );

	/// Copy constructor.  Copies the elements of the given vector via memcpy.
	inline float4( const float4& other );

	~float4() {}

	/// Copies the elements of the given vector via a single memcpy.
	inline float4 operator=( const float2& rhs );

	/// Copies the elements of the given vector via a single memcpy.
	inline float4 operator=( const float3& rhs );

	/// Copies the elements of the given vector via a single memcpy.
	inline float4 operator=( const float4& rhs );

	/// \brief Returns the vector component at the given index.
	/// Index CANNOT be lower than 0 or higher than 3.
	inline const float& operator[]( const uint32_t index ) const;

	/// \brief Returns the vector component at the given index.
	/// Index CANNOT be lower than 0 or higher than 3.
	inline float& operator[]( const uint32_t index );

	// swizzle funcs
	inline float2 xx() const { return float2( x, x ); }
	inline float2 yx() const { return float2( y, x ); }
	inline float2 xy() const { return float2( x, y ); }
	inline float2 yy() const { return float2( y, y ); }

	inline float3 xxx() const { return float3( x, x, x ); }
	inline float3 yxx() const { return float3( y, x, x ); }
	inline float3 zxx() const { return float3( z, x, x ); }
	inline float3 xyx() const { return float3( x, y, x ); }
	inline float3 yyx() const { return float3( y, y, x ); }
	inline float3 zyx() const { return float3( z, y, x ); }
	inline float3 xzx() const { return float3( x, z, x ); }
	inline float3 yzx() const { return float3( y, z, x ); }
	inline float3 zzx() const { return float3( z, z, x ); }
	inline float3 xxy() const { return float3( x, x, y ); }
	inline float3 yxy() const { return float3( y, x, y ); }
	inline float3 zxy() const { return float3( z, x, y ); }
	inline float3 xyy() const { return float3( x, y, y ); }
	inline float3 yyy() const { return float3( y, y, y ); }
	inline float3 zyy() const { return float3( z, y, y ); }
	inline float3 xzy() const { return float3( x, z, y ); }
	inline float3 yzy() const { return float3( y, z, y ); }
	inline float3 zzy() const { return float3( z, z, y ); }
	inline float3 xxz() const { return float3( x, x, z ); }
	inline float3 yxz() const { return float3( y, x, z ); }
	inline float3 zxz() const { return float3( z, x, z ); }
	inline float3 xyz() const { return float3( x, y, z ); }
	inline float3 yyz() const { return float3( y, y, z ); }
	inline float3 zyz() const { return float3( z, y, z ); }
	inline float3 xzz() const { return float3( x, z, z ); }
	inline float3 yzz() const { return float3( y, z, z ); }
	inline float3 zzz() const { return float3( z, z, z ); }

	inline float4 xxxx() const { return float4( x, x, x, x ); }
	inline float4 yxxx() const { return float4( y, x, x, x ); }
	inline float4 zxxx() const { return float4( z, x, x, x ); }
	inline float4 wxxx() const { return float4( w, x, x, x ); }
	inline float4 xyxx() const { return float4( x, y, x, x ); }
	inline float4 yyxx() const { return float4( y, y, x, x ); }
	inline float4 zyxx() const { return float4( z, y, x, x ); }
	inline float4 wyxx() const { return float4( w, y, x, x ); }
	inline float4 xzxx() const { return float4( x, z, x, x ); }
	inline float4 yzxx() const { return float4( y, z, x, x ); }
	inline float4 zzxx() const { return float4( z, z, x, x ); }
	inline float4 wzxx() const { return float4( w, z, x, x ); }
	inline float4 xwxx() const { return float4( x, w, x, x ); }
	inline float4 ywxx() const { return float4( y, w, x, x ); }
	inline float4 zwxx() const { return float4( z, w, x, x ); }
	inline float4 wwxx() const { return float4( w, w, x, x ); }
	inline float4 xxyx() const { return float4( x, x, y, x ); }
	inline float4 yxyx() const { return float4( y, x, y, x ); }
	inline float4 zxyx() const { return float4( z, x, y, x ); }
	inline float4 wxyx() const { return float4( w, x, y, x ); }
	inline float4 xyyx() const { return float4( x, y, y, x ); }
	inline float4 yyyx() const { return float4( y, y, y, x ); }
	inline float4 zyyx() const { return float4( z, y, y, x ); }
	inline float4 wyyx() const { return float4( w, y, y, x ); }
	inline float4 xzyx() const { return float4( x, z, y, x ); }
	inline float4 yzyx() const { return float4( y, z, y, x ); }
	inline float4 zzyx() const { return float4( z, z, y, x ); }
	inline float4 wzyx() const { return float4( w, z, y, x ); }
	inline float4 xwyx() const { return float4( x, w, y, x ); }
	inline float4 ywyx() const { return float4( y, w, y, x ); }
	inline float4 zwyx() const { return float4( z, w, y, x ); }
	inline float4 wwyx() const { return float4( w, w, y, x ); }
	inline float4 xxzx() const { return float4( x, x, z, x ); }
	inline float4 yxzx() const { return float4( y, x, z, x ); }
	inline float4 zxzx() const { return float4( z, x, z, x ); }
	inline float4 wxzx() const { return float4( w, x, z, x ); }
	inline float4 xyzx() const { return float4( x, y, z, x ); }
	inline float4 yyzx() const { return float4( y, y, z, x ); }
	inline float4 zyzx() const { return float4( z, y, z, x ); }
	inline float4 wyzx() const { return float4( w, y, z, x ); }
	inline float4 xzzx() const { return float4( x, z, z, x ); }
	inline float4 yzzx() const { return float4( y, z, z, x ); }
	inline float4 zzzx() const { return float4( z, z, z, x ); }
	inline float4 wzzx() const { return float4( w, z, z, x ); }
	inline float4 xwzx() const { return float4( x, w, z, x ); }
	inline float4 ywzx() const { return float4( y, w, z, x ); }
	inline float4 zwzx() const { return float4( z, w, z, x ); }
	inline float4 wwzx() const { return float4( w, w, z, x ); }
	inline float4 xxwx() const { return float4( x, x, w, x ); }
	inline float4 yxwx() const { return float4( y, x, w, x ); }
	inline float4 zxwx() const { return float4( z, x, w, x ); }
	inline float4 wxwx() const { return float4( w, x, w, x ); }
	inline float4 xywx() const { return float4( x, y, w, x ); }
	inline float4 yywx() const { return float4( y, y, w, x ); }
	inline float4 zywx() const { return float4( z, y, w, x ); }
	inline float4 wywx() const { return float4( w, y, w, x ); }
	inline float4 xzwx() const { return float4( x, z, w, x ); }
	inline float4 yzwx() const { return float4( y, z, w, x ); }
	inline float4 zzwx() const { return float4( z, z, w, x ); }
	inline float4 wzwx() const { return float4( w, z, w, x ); }
	inline float4 xwwx() const { return float4( x, w, w, x ); }
	inline float4 ywwx() const { return float4( y, w, w, x ); }
	inline float4 zwwx() const { return float4( z, w, w, x ); }
	inline float4 wwwx() const { return float4( w, w, w, x ); }
	inline float4 xxxy() const { return float4( x, x, x, y ); }
	inline float4 yxxy() const { return float4( y, x, x, y ); }
	inline float4 zxxy() const { return float4( z, x, x, y ); }
	inline float4 wxxy() const { return float4( w, x, x, y ); }
	inline float4 xyxy() const { return float4( x, y, x, y ); }
	inline float4 yyxy() const { return float4( y, y, x, y ); }
	inline float4 zyxy() const { return float4( z, y, x, y ); }
	inline float4 wyxy() const { return float4( w, y, x, y ); }
	inline float4 xzxy() const { return float4( x, z, x, y ); }
	inline float4 yzxy() const { return float4( y, z, x, y ); }
	inline float4 zzxy() const { return float4( z, z, x, y ); }
	inline float4 wzxy() const { return float4( w, z, x, y ); }
	inline float4 xwxy() const { return float4( x, w, x, y ); }
	inline float4 ywxy() const { return float4( y, w, x, y ); }
	inline float4 zwxy() const { return float4( z, w, x, y ); }
	inline float4 wwxy() const { return float4( w, w, x, y ); }
	inline float4 xxyy() const { return float4( x, x, y, y ); }
	inline float4 yxyy() const { return float4( y, x, y, y ); }
	inline float4 zxyy() const { return float4( z, x, y, y ); }
	inline float4 wxyy() const { return float4( w, x, y, y ); }
	inline float4 xyyy() const { return float4( x, y, y, y ); }
	inline float4 yyyy() const { return float4( y, y, y, y ); }
	inline float4 zyyy() const { return float4( z, y, y, y ); }
	inline float4 wyyy() const { return float4( w, y, y, y ); }
	inline float4 xzyy() const { return float4( x, z, y, y ); }
	inline float4 yzyy() const { return float4( y, z, y, y ); }
	inline float4 zzyy() const { return float4( z, z, y, y ); }
	inline float4 wzyy() const { return float4( w, z, y, y ); }
	inline float4 xwyy() const { return float4( x, w, y, y ); }
	inline float4 ywyy() const { return float4( y, w, y, y ); }
	inline float4 zwyy() const { return float4( z, w, y, y ); }
	inline float4 wwyy() const { return float4( w, w, y, y ); }
	inline float4 xxzy() const { return float4( x, x, z, y ); }
	inline float4 yxzy() const { return float4( y, x, z, y ); }
	inline float4 zxzy() const { return float4( z, x, z, y ); }
	inline float4 wxzy() const { return float4( w, x, z, y ); }
	inline float4 xyzy() const { return float4( x, y, z, y ); }
	inline float4 yyzy() const { return float4( y, y, z, y ); }
	inline float4 zyzy() const { return float4( z, y, z, y ); }
	inline float4 wyzy() const { return float4( w, y, z, y ); }
	inline float4 xzzy() const { return float4( x, z, z, y ); }
	inline float4 yzzy() const { return float4( y, z, z, y ); }
	inline float4 zzzy() const { return float4( z, z, z, y ); }
	inline float4 wzzy() const { return float4( w, z, z, y ); }
	inline float4 xwzy() const { return float4( x, w, z, y ); }
	inline float4 ywzy() const { return float4( y, w, z, y ); }
	inline float4 zwzy() const { return float4( z, w, z, y ); }
	inline float4 wwzy() const { return float4( w, w, z, y ); }
	inline float4 xxwy() const { return float4( x, x, w, y ); }
	inline float4 yxwy() const { return float4( y, x, w, y ); }
	inline float4 zxwy() const { return float4( z, x, w, y ); }
	inline float4 wxwy() const { return float4( w, x, w, y ); }
	inline float4 xywy() const { return float4( x, y, w, y ); }
	inline float4 yywy() const { return float4( y, y, w, y ); }
	inline float4 zywy() const { return float4( z, y, w, y ); }
	inline float4 wywy() const { return float4( w, y, w, y ); }
	inline float4 xzwy() const { return float4( x, z, w, y ); }
	inline float4 yzwy() const { return float4( y, z, w, y ); }
	inline float4 zzwy() const { return float4( z, z, w, y ); }
	inline float4 wzwy() const { return float4( w, z, w, y ); }
	inline float4 xwwy() const { return float4( x, w, w, y ); }
	inline float4 ywwy() const { return float4( y, w, w, y ); }
	inline float4 zwwy() const { return float4( z, w, w, y ); }
	inline float4 wwwy() const { return float4( w, w, w, y ); }
	inline float4 xxxz() const { return float4( x, x, x, z ); }
	inline float4 yxxz() const { return float4( y, x, x, z ); }
	inline float4 zxxz() const { return float4( z, x, x, z ); }
	inline float4 wxxz() const { return float4( w, x, x, z ); }
	inline float4 xyxz() const { return float4( x, y, x, z ); }
	inline float4 yyxz() const { return float4( y, y, x, z ); }
	inline float4 zyxz() const { return float4( z, y, x, z ); }
	inline float4 wyxz() const { return float4( w, y, x, z ); }
	inline float4 xzxz() const { return float4( x, z, x, z ); }
	inline float4 yzxz() const { return float4( y, z, x, z ); }
	inline float4 zzxz() const { return float4( z, z, x, z ); }
	inline float4 wzxz() const { return float4( w, z, x, z ); }
	inline float4 xwxz() const { return float4( x, w, x, z ); }
	inline float4 ywxz() const { return float4( y, w, x, z ); }
	inline float4 zwxz() const { return float4( z, w, x, z ); }
	inline float4 wwxz() const { return float4( w, w, x, z ); }
	inline float4 xxyz() const { return float4( x, x, y, z ); }
	inline float4 yxyz() const { return float4( y, x, y, z ); }
	inline float4 zxyz() const { return float4( z, x, y, z ); }
	inline float4 wxyz() const { return float4( w, x, y, z ); }
	inline float4 xyyz() const { return float4( x, y, y, z ); }
	inline float4 yyyz() const { return float4( y, y, y, z ); }
	inline float4 zyyz() const { return float4( z, y, y, z ); }
	inline float4 wyyz() const { return float4( w, y, y, z ); }
	inline float4 xzyz() const { return float4( x, z, y, z ); }
	inline float4 yzyz() const { return float4( y, z, y, z ); }
	inline float4 zzyz() const { return float4( z, z, y, z ); }
	inline float4 wzyz() const { return float4( w, z, y, z ); }
	inline float4 xwyz() const { return float4( x, w, y, z ); }
	inline float4 ywyz() const { return float4( y, w, y, z ); }
	inline float4 zwyz() const { return float4( z, w, y, z ); }
	inline float4 wwyz() const { return float4( w, w, y, z ); }
	inline float4 xxzz() const { return float4( x, x, z, z ); }
	inline float4 yxzz() const { return float4( y, x, z, z ); }
	inline float4 zxzz() const { return float4( z, x, z, z ); }
	inline float4 wxzz() const { return float4( w, x, z, z ); }
	inline float4 xyzz() const { return float4( x, y, z, z ); }
	inline float4 yyzz() const { return float4( y, y, z, z ); }
	inline float4 zyzz() const { return float4( z, y, z, z ); }
	inline float4 wyzz() const { return float4( w, y, z, z ); }
	inline float4 xzzz() const { return float4( x, z, z, z ); }
	inline float4 yzzz() const { return float4( y, z, z, z ); }
	inline float4 zzzz() const { return float4( z, z, z, z ); }
	inline float4 wzzz() const { return float4( w, z, z, z ); }
	inline float4 xwzz() const { return float4( x, w, z, z ); }
	inline float4 ywzz() const { return float4( y, w, z, z ); }
	inline float4 zwzz() const { return float4( z, w, z, z ); }
	inline float4 wwzz() const { return float4( w, w, z, z ); }
	inline float4 xxwz() const { return float4( x, x, w, z ); }
	inline float4 yxwz() const { return float4( y, x, w, z ); }
	inline float4 zxwz() const { return float4( z, x, w, z ); }
	inline float4 wxwz() const { return float4( w, x, w, z ); }
	inline float4 xywz() const { return float4( x, y, w, z ); }
	inline float4 yywz() const { return float4( y, y, w, z ); }
	inline float4 zywz() const { return float4( z, y, w, z ); }
	inline float4 wywz() const { return float4( w, y, w, z ); }
	inline float4 xzwz() const { return float4( x, z, w, z ); }
	inline float4 yzwz() const { return float4( y, z, w, z ); }
	inline float4 zzwz() const { return float4( z, z, w, z ); }
	inline float4 wzwz() const { return float4( w, z, w, z ); }
	inline float4 xwwz() const { return float4( x, w, w, z ); }
	inline float4 ywwz() const { return float4( y, w, w, z ); }
	inline float4 zwwz() const { return float4( z, w, w, z ); }
	inline float4 wwwz() const { return float4( w, w, w, z ); }
	inline float4 xxxw() const { return float4( x, x, x, w ); }
	inline float4 yxxw() const { return float4( y, x, x, w ); }
	inline float4 zxxw() const { return float4( z, x, x, w ); }
	inline float4 wxxw() const { return float4( w, x, x, w ); }
	inline float4 xyxw() const { return float4( x, y, x, w ); }
	inline float4 yyxw() const { return float4( y, y, x, w ); }
	inline float4 zyxw() const { return float4( z, y, x, w ); }
	inline float4 wyxw() const { return float4( w, y, x, w ); }
	inline float4 xzxw() const { return float4( x, z, x, w ); }
	inline float4 yzxw() const { return float4( y, z, x, w ); }
	inline float4 zzxw() const { return float4( z, z, x, w ); }
	inline float4 wzxw() const { return float4( w, z, x, w ); }
	inline float4 xwxw() const { return float4( x, w, x, w ); }
	inline float4 ywxw() const { return float4( y, w, x, w ); }
	inline float4 zwxw() const { return float4( z, w, x, w ); }
	inline float4 wwxw() const { return float4( w, w, x, w ); }
	inline float4 xxyw() const { return float4( x, x, y, w ); }
	inline float4 yxyw() const { return float4( y, x, y, w ); }
	inline float4 zxyw() const { return float4( z, x, y, w ); }
	inline float4 wxyw() const { return float4( w, x, y, w ); }
	inline float4 xyyw() const { return float4( x, y, y, w ); }
	inline float4 yyyw() const { return float4( y, y, y, w ); }
	inline float4 zyyw() const { return float4( z, y, y, w ); }
	inline float4 wyyw() const { return float4( w, y, y, w ); }
	inline float4 xzyw() const { return float4( x, z, y, w ); }
	inline float4 yzyw() const { return float4( y, z, y, w ); }
	inline float4 zzyw() const { return float4( z, z, y, w ); }
	inline float4 wzyw() const { return float4( w, z, y, w ); }
	inline float4 xwyw() const { return float4( x, w, y, w ); }
	inline float4 ywyw() const { return float4( y, w, y, w ); }
	inline float4 zwyw() const { return float4( z, w, y, w ); }
	inline float4 wwyw() const { return float4( w, w, y, w ); }
	inline float4 xxzw() const { return float4( x, x, z, w ); }
	inline float4 yxzw() const { return float4( y, x, z, w ); }
	inline float4 zxzw() const { return float4( z, x, z, w ); }
	inline float4 wxzw() const { return float4( w, x, z, w ); }
	inline float4 xyzw() const { return float4( x, y, z, w ); }
	inline float4 yyzw() const { return float4( y, y, z, w ); }
	inline float4 zyzw() const { return float4( z, y, z, w ); }
	inline float4 wyzw() const { return float4( w, y, z, w ); }
	inline float4 xzzw() const { return float4( x, z, z, w ); }
	inline float4 yzzw() const { return float4( y, z, z, w ); }
	inline float4 zzzw() const { return float4( z, z, z, w ); }
	inline float4 wzzw() const { return float4( w, z, z, w ); }
	inline float4 xwzw() const { return float4( x, w, z, w ); }
	inline float4 ywzw() const { return float4( y, w, z, w ); }
	inline float4 zwzw() const { return float4( z, w, z, w ); }
	inline float4 wwzw() const { return float4( w, w, z, w ); }
	inline float4 xxww() const { return float4( x, x, w, w ); }
	inline float4 yxww() const { return float4( y, x, w, w ); }
	inline float4 zxww() const { return float4( z, x, w, w ); }
	inline float4 wxww() const { return float4( w, x, w, w ); }
	inline float4 xyww() const { return float4( x, y, w, w ); }
	inline float4 yyww() const { return float4( y, y, w, w ); }
	inline float4 zyww() const { return float4( z, y, w, w ); }
	inline float4 wyww() const { return float4( w, y, w, w ); }
	inline float4 xzww() const { return float4( x, z, w, w ); }
	inline float4 yzww() const { return float4( y, z, w, w ); }
	inline float4 zzww() const { return float4( z, z, w, w ); }
	inline float4 wzww() const { return float4( w, z, w, w ); }
	inline float4 xwww() const { return float4( x, w, w, w ); }
	inline float4 ywww() const { return float4( y, w, w, w ); }
	inline float4 zwww() const { return float4( z, w, w, w ); }
	inline float4 wwww() const { return float4( w, w, w, w ); }

};

#if defined( __clang__ ) || defined( __GNUC__ )
#pragma GCC diagnostic pop
#elif defined( _MSC_VER )
#pragma warning( pop )
#endif

/// \relates float4
/// \brief Returns true if the all the components of the left-hand-side float4 match the other one, otherwise returns false.
inline bool operator==( const float4& lhs, const float4& rhs );

/// \relates float4
/// \brief Returns true if not all of the components of the left-hand-side float4 match the other one, otherwise returns false.
inline bool operator!=( const float4& lhs, const float4& rhs );

#include "float4.inl"

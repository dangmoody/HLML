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

#include <stdint.h>

struct bool2;
struct bool3;
struct float3;

// ignore prohibition of anymous structs for GCC
#if defined( __clang__ ) || defined( __GNUC__ )
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
#endif

/// \brief A vector of 4 bools with components xyzw.
/// Components are also stored as elements in an array via a union.
struct bool4
{
	union
	{
		struct
		{
			bool x;
			bool y;
			bool z;
			bool w;
		};

		bool data[4] = { 0 };
	};

	/// Default constructor.  Initializes all values to zero.
	inline bool4();

	/// Initializes all components of the vector to the given scalar value.
	inline explicit bool4( const bool x );

	/// Sets the xyzw members of the vector to the corresponding parameters.
	inline bool4( const bool x, const bool y, const bool z, const bool w );

	/// Copy constructor.  Copies the elements of the given vector via memcpy.
	inline bool4( const bool2& other );

	/// Copy constructor.  Copies the elements of the given vector via memcpy.
	inline bool4( const bool3& other );

	/// Copy constructor.  Copies the elements of the given vector via memcpy.
	inline bool4( const bool4& other );

	~bool4() {}

	/// Copies the elements of the given vector via a single memcpy.
	inline bool4 operator=( const bool2& rhs );

	/// Copies the elements of the given vector via a single memcpy.
	inline bool4 operator=( const bool3& rhs );

	/// Copies the elements of the given vector via a single memcpy.
	inline bool4 operator=( const bool4& rhs );

	/// \brief Returns the vector component at the given index.
	/// Index CANNOT be lower than 0 or higher than 3.
	inline const bool& operator[]( const uint32_t index ) const;

	/// \brief Returns the vector component at the given index.
	/// Index CANNOT be lower than 0 or higher than 3.
	inline bool& operator[]( const uint32_t index );

	// swizzle funcs
	inline bool2 xx() const { return bool2( x, x ); }
	inline bool2 yx() const { return bool2( y, x ); }
	inline bool2 xy() const { return bool2( x, y ); }
	inline bool2 yy() const { return bool2( y, y ); }

	inline bool3 xxx() const { return bool3( x, x, x ); }
	inline bool3 yxx() const { return bool3( y, x, x ); }
	inline bool3 zxx() const { return bool3( z, x, x ); }
	inline bool3 xyx() const { return bool3( x, y, x ); }
	inline bool3 yyx() const { return bool3( y, y, x ); }
	inline bool3 zyx() const { return bool3( z, y, x ); }
	inline bool3 xzx() const { return bool3( x, z, x ); }
	inline bool3 yzx() const { return bool3( y, z, x ); }
	inline bool3 zzx() const { return bool3( z, z, x ); }
	inline bool3 xxy() const { return bool3( x, x, y ); }
	inline bool3 yxy() const { return bool3( y, x, y ); }
	inline bool3 zxy() const { return bool3( z, x, y ); }
	inline bool3 xyy() const { return bool3( x, y, y ); }
	inline bool3 yyy() const { return bool3( y, y, y ); }
	inline bool3 zyy() const { return bool3( z, y, y ); }
	inline bool3 xzy() const { return bool3( x, z, y ); }
	inline bool3 yzy() const { return bool3( y, z, y ); }
	inline bool3 zzy() const { return bool3( z, z, y ); }
	inline bool3 xxz() const { return bool3( x, x, z ); }
	inline bool3 yxz() const { return bool3( y, x, z ); }
	inline bool3 zxz() const { return bool3( z, x, z ); }
	inline bool3 xyz() const { return bool3( x, y, z ); }
	inline bool3 yyz() const { return bool3( y, y, z ); }
	inline bool3 zyz() const { return bool3( z, y, z ); }
	inline bool3 xzz() const { return bool3( x, z, z ); }
	inline bool3 yzz() const { return bool3( y, z, z ); }
	inline bool3 zzz() const { return bool3( z, z, z ); }

	inline bool4 xxxx() const { return bool4( x, x, x, x ); }
	inline bool4 yxxx() const { return bool4( y, x, x, x ); }
	inline bool4 zxxx() const { return bool4( z, x, x, x ); }
	inline bool4 wxxx() const { return bool4( w, x, x, x ); }
	inline bool4 xyxx() const { return bool4( x, y, x, x ); }
	inline bool4 yyxx() const { return bool4( y, y, x, x ); }
	inline bool4 zyxx() const { return bool4( z, y, x, x ); }
	inline bool4 wyxx() const { return bool4( w, y, x, x ); }
	inline bool4 xzxx() const { return bool4( x, z, x, x ); }
	inline bool4 yzxx() const { return bool4( y, z, x, x ); }
	inline bool4 zzxx() const { return bool4( z, z, x, x ); }
	inline bool4 wzxx() const { return bool4( w, z, x, x ); }
	inline bool4 xwxx() const { return bool4( x, w, x, x ); }
	inline bool4 ywxx() const { return bool4( y, w, x, x ); }
	inline bool4 zwxx() const { return bool4( z, w, x, x ); }
	inline bool4 wwxx() const { return bool4( w, w, x, x ); }
	inline bool4 xxyx() const { return bool4( x, x, y, x ); }
	inline bool4 yxyx() const { return bool4( y, x, y, x ); }
	inline bool4 zxyx() const { return bool4( z, x, y, x ); }
	inline bool4 wxyx() const { return bool4( w, x, y, x ); }
	inline bool4 xyyx() const { return bool4( x, y, y, x ); }
	inline bool4 yyyx() const { return bool4( y, y, y, x ); }
	inline bool4 zyyx() const { return bool4( z, y, y, x ); }
	inline bool4 wyyx() const { return bool4( w, y, y, x ); }
	inline bool4 xzyx() const { return bool4( x, z, y, x ); }
	inline bool4 yzyx() const { return bool4( y, z, y, x ); }
	inline bool4 zzyx() const { return bool4( z, z, y, x ); }
	inline bool4 wzyx() const { return bool4( w, z, y, x ); }
	inline bool4 xwyx() const { return bool4( x, w, y, x ); }
	inline bool4 ywyx() const { return bool4( y, w, y, x ); }
	inline bool4 zwyx() const { return bool4( z, w, y, x ); }
	inline bool4 wwyx() const { return bool4( w, w, y, x ); }
	inline bool4 xxzx() const { return bool4( x, x, z, x ); }
	inline bool4 yxzx() const { return bool4( y, x, z, x ); }
	inline bool4 zxzx() const { return bool4( z, x, z, x ); }
	inline bool4 wxzx() const { return bool4( w, x, z, x ); }
	inline bool4 xyzx() const { return bool4( x, y, z, x ); }
	inline bool4 yyzx() const { return bool4( y, y, z, x ); }
	inline bool4 zyzx() const { return bool4( z, y, z, x ); }
	inline bool4 wyzx() const { return bool4( w, y, z, x ); }
	inline bool4 xzzx() const { return bool4( x, z, z, x ); }
	inline bool4 yzzx() const { return bool4( y, z, z, x ); }
	inline bool4 zzzx() const { return bool4( z, z, z, x ); }
	inline bool4 wzzx() const { return bool4( w, z, z, x ); }
	inline bool4 xwzx() const { return bool4( x, w, z, x ); }
	inline bool4 ywzx() const { return bool4( y, w, z, x ); }
	inline bool4 zwzx() const { return bool4( z, w, z, x ); }
	inline bool4 wwzx() const { return bool4( w, w, z, x ); }
	inline bool4 xxwx() const { return bool4( x, x, w, x ); }
	inline bool4 yxwx() const { return bool4( y, x, w, x ); }
	inline bool4 zxwx() const { return bool4( z, x, w, x ); }
	inline bool4 wxwx() const { return bool4( w, x, w, x ); }
	inline bool4 xywx() const { return bool4( x, y, w, x ); }
	inline bool4 yywx() const { return bool4( y, y, w, x ); }
	inline bool4 zywx() const { return bool4( z, y, w, x ); }
	inline bool4 wywx() const { return bool4( w, y, w, x ); }
	inline bool4 xzwx() const { return bool4( x, z, w, x ); }
	inline bool4 yzwx() const { return bool4( y, z, w, x ); }
	inline bool4 zzwx() const { return bool4( z, z, w, x ); }
	inline bool4 wzwx() const { return bool4( w, z, w, x ); }
	inline bool4 xwwx() const { return bool4( x, w, w, x ); }
	inline bool4 ywwx() const { return bool4( y, w, w, x ); }
	inline bool4 zwwx() const { return bool4( z, w, w, x ); }
	inline bool4 wwwx() const { return bool4( w, w, w, x ); }
	inline bool4 xxxy() const { return bool4( x, x, x, y ); }
	inline bool4 yxxy() const { return bool4( y, x, x, y ); }
	inline bool4 zxxy() const { return bool4( z, x, x, y ); }
	inline bool4 wxxy() const { return bool4( w, x, x, y ); }
	inline bool4 xyxy() const { return bool4( x, y, x, y ); }
	inline bool4 yyxy() const { return bool4( y, y, x, y ); }
	inline bool4 zyxy() const { return bool4( z, y, x, y ); }
	inline bool4 wyxy() const { return bool4( w, y, x, y ); }
	inline bool4 xzxy() const { return bool4( x, z, x, y ); }
	inline bool4 yzxy() const { return bool4( y, z, x, y ); }
	inline bool4 zzxy() const { return bool4( z, z, x, y ); }
	inline bool4 wzxy() const { return bool4( w, z, x, y ); }
	inline bool4 xwxy() const { return bool4( x, w, x, y ); }
	inline bool4 ywxy() const { return bool4( y, w, x, y ); }
	inline bool4 zwxy() const { return bool4( z, w, x, y ); }
	inline bool4 wwxy() const { return bool4( w, w, x, y ); }
	inline bool4 xxyy() const { return bool4( x, x, y, y ); }
	inline bool4 yxyy() const { return bool4( y, x, y, y ); }
	inline bool4 zxyy() const { return bool4( z, x, y, y ); }
	inline bool4 wxyy() const { return bool4( w, x, y, y ); }
	inline bool4 xyyy() const { return bool4( x, y, y, y ); }
	inline bool4 yyyy() const { return bool4( y, y, y, y ); }
	inline bool4 zyyy() const { return bool4( z, y, y, y ); }
	inline bool4 wyyy() const { return bool4( w, y, y, y ); }
	inline bool4 xzyy() const { return bool4( x, z, y, y ); }
	inline bool4 yzyy() const { return bool4( y, z, y, y ); }
	inline bool4 zzyy() const { return bool4( z, z, y, y ); }
	inline bool4 wzyy() const { return bool4( w, z, y, y ); }
	inline bool4 xwyy() const { return bool4( x, w, y, y ); }
	inline bool4 ywyy() const { return bool4( y, w, y, y ); }
	inline bool4 zwyy() const { return bool4( z, w, y, y ); }
	inline bool4 wwyy() const { return bool4( w, w, y, y ); }
	inline bool4 xxzy() const { return bool4( x, x, z, y ); }
	inline bool4 yxzy() const { return bool4( y, x, z, y ); }
	inline bool4 zxzy() const { return bool4( z, x, z, y ); }
	inline bool4 wxzy() const { return bool4( w, x, z, y ); }
	inline bool4 xyzy() const { return bool4( x, y, z, y ); }
	inline bool4 yyzy() const { return bool4( y, y, z, y ); }
	inline bool4 zyzy() const { return bool4( z, y, z, y ); }
	inline bool4 wyzy() const { return bool4( w, y, z, y ); }
	inline bool4 xzzy() const { return bool4( x, z, z, y ); }
	inline bool4 yzzy() const { return bool4( y, z, z, y ); }
	inline bool4 zzzy() const { return bool4( z, z, z, y ); }
	inline bool4 wzzy() const { return bool4( w, z, z, y ); }
	inline bool4 xwzy() const { return bool4( x, w, z, y ); }
	inline bool4 ywzy() const { return bool4( y, w, z, y ); }
	inline bool4 zwzy() const { return bool4( z, w, z, y ); }
	inline bool4 wwzy() const { return bool4( w, w, z, y ); }
	inline bool4 xxwy() const { return bool4( x, x, w, y ); }
	inline bool4 yxwy() const { return bool4( y, x, w, y ); }
	inline bool4 zxwy() const { return bool4( z, x, w, y ); }
	inline bool4 wxwy() const { return bool4( w, x, w, y ); }
	inline bool4 xywy() const { return bool4( x, y, w, y ); }
	inline bool4 yywy() const { return bool4( y, y, w, y ); }
	inline bool4 zywy() const { return bool4( z, y, w, y ); }
	inline bool4 wywy() const { return bool4( w, y, w, y ); }
	inline bool4 xzwy() const { return bool4( x, z, w, y ); }
	inline bool4 yzwy() const { return bool4( y, z, w, y ); }
	inline bool4 zzwy() const { return bool4( z, z, w, y ); }
	inline bool4 wzwy() const { return bool4( w, z, w, y ); }
	inline bool4 xwwy() const { return bool4( x, w, w, y ); }
	inline bool4 ywwy() const { return bool4( y, w, w, y ); }
	inline bool4 zwwy() const { return bool4( z, w, w, y ); }
	inline bool4 wwwy() const { return bool4( w, w, w, y ); }
	inline bool4 xxxz() const { return bool4( x, x, x, z ); }
	inline bool4 yxxz() const { return bool4( y, x, x, z ); }
	inline bool4 zxxz() const { return bool4( z, x, x, z ); }
	inline bool4 wxxz() const { return bool4( w, x, x, z ); }
	inline bool4 xyxz() const { return bool4( x, y, x, z ); }
	inline bool4 yyxz() const { return bool4( y, y, x, z ); }
	inline bool4 zyxz() const { return bool4( z, y, x, z ); }
	inline bool4 wyxz() const { return bool4( w, y, x, z ); }
	inline bool4 xzxz() const { return bool4( x, z, x, z ); }
	inline bool4 yzxz() const { return bool4( y, z, x, z ); }
	inline bool4 zzxz() const { return bool4( z, z, x, z ); }
	inline bool4 wzxz() const { return bool4( w, z, x, z ); }
	inline bool4 xwxz() const { return bool4( x, w, x, z ); }
	inline bool4 ywxz() const { return bool4( y, w, x, z ); }
	inline bool4 zwxz() const { return bool4( z, w, x, z ); }
	inline bool4 wwxz() const { return bool4( w, w, x, z ); }
	inline bool4 xxyz() const { return bool4( x, x, y, z ); }
	inline bool4 yxyz() const { return bool4( y, x, y, z ); }
	inline bool4 zxyz() const { return bool4( z, x, y, z ); }
	inline bool4 wxyz() const { return bool4( w, x, y, z ); }
	inline bool4 xyyz() const { return bool4( x, y, y, z ); }
	inline bool4 yyyz() const { return bool4( y, y, y, z ); }
	inline bool4 zyyz() const { return bool4( z, y, y, z ); }
	inline bool4 wyyz() const { return bool4( w, y, y, z ); }
	inline bool4 xzyz() const { return bool4( x, z, y, z ); }
	inline bool4 yzyz() const { return bool4( y, z, y, z ); }
	inline bool4 zzyz() const { return bool4( z, z, y, z ); }
	inline bool4 wzyz() const { return bool4( w, z, y, z ); }
	inline bool4 xwyz() const { return bool4( x, w, y, z ); }
	inline bool4 ywyz() const { return bool4( y, w, y, z ); }
	inline bool4 zwyz() const { return bool4( z, w, y, z ); }
	inline bool4 wwyz() const { return bool4( w, w, y, z ); }
	inline bool4 xxzz() const { return bool4( x, x, z, z ); }
	inline bool4 yxzz() const { return bool4( y, x, z, z ); }
	inline bool4 zxzz() const { return bool4( z, x, z, z ); }
	inline bool4 wxzz() const { return bool4( w, x, z, z ); }
	inline bool4 xyzz() const { return bool4( x, y, z, z ); }
	inline bool4 yyzz() const { return bool4( y, y, z, z ); }
	inline bool4 zyzz() const { return bool4( z, y, z, z ); }
	inline bool4 wyzz() const { return bool4( w, y, z, z ); }
	inline bool4 xzzz() const { return bool4( x, z, z, z ); }
	inline bool4 yzzz() const { return bool4( y, z, z, z ); }
	inline bool4 zzzz() const { return bool4( z, z, z, z ); }
	inline bool4 wzzz() const { return bool4( w, z, z, z ); }
	inline bool4 xwzz() const { return bool4( x, w, z, z ); }
	inline bool4 ywzz() const { return bool4( y, w, z, z ); }
	inline bool4 zwzz() const { return bool4( z, w, z, z ); }
	inline bool4 wwzz() const { return bool4( w, w, z, z ); }
	inline bool4 xxwz() const { return bool4( x, x, w, z ); }
	inline bool4 yxwz() const { return bool4( y, x, w, z ); }
	inline bool4 zxwz() const { return bool4( z, x, w, z ); }
	inline bool4 wxwz() const { return bool4( w, x, w, z ); }
	inline bool4 xywz() const { return bool4( x, y, w, z ); }
	inline bool4 yywz() const { return bool4( y, y, w, z ); }
	inline bool4 zywz() const { return bool4( z, y, w, z ); }
	inline bool4 wywz() const { return bool4( w, y, w, z ); }
	inline bool4 xzwz() const { return bool4( x, z, w, z ); }
	inline bool4 yzwz() const { return bool4( y, z, w, z ); }
	inline bool4 zzwz() const { return bool4( z, z, w, z ); }
	inline bool4 wzwz() const { return bool4( w, z, w, z ); }
	inline bool4 xwwz() const { return bool4( x, w, w, z ); }
	inline bool4 ywwz() const { return bool4( y, w, w, z ); }
	inline bool4 zwwz() const { return bool4( z, w, w, z ); }
	inline bool4 wwwz() const { return bool4( w, w, w, z ); }
	inline bool4 xxxw() const { return bool4( x, x, x, w ); }
	inline bool4 yxxw() const { return bool4( y, x, x, w ); }
	inline bool4 zxxw() const { return bool4( z, x, x, w ); }
	inline bool4 wxxw() const { return bool4( w, x, x, w ); }
	inline bool4 xyxw() const { return bool4( x, y, x, w ); }
	inline bool4 yyxw() const { return bool4( y, y, x, w ); }
	inline bool4 zyxw() const { return bool4( z, y, x, w ); }
	inline bool4 wyxw() const { return bool4( w, y, x, w ); }
	inline bool4 xzxw() const { return bool4( x, z, x, w ); }
	inline bool4 yzxw() const { return bool4( y, z, x, w ); }
	inline bool4 zzxw() const { return bool4( z, z, x, w ); }
	inline bool4 wzxw() const { return bool4( w, z, x, w ); }
	inline bool4 xwxw() const { return bool4( x, w, x, w ); }
	inline bool4 ywxw() const { return bool4( y, w, x, w ); }
	inline bool4 zwxw() const { return bool4( z, w, x, w ); }
	inline bool4 wwxw() const { return bool4( w, w, x, w ); }
	inline bool4 xxyw() const { return bool4( x, x, y, w ); }
	inline bool4 yxyw() const { return bool4( y, x, y, w ); }
	inline bool4 zxyw() const { return bool4( z, x, y, w ); }
	inline bool4 wxyw() const { return bool4( w, x, y, w ); }
	inline bool4 xyyw() const { return bool4( x, y, y, w ); }
	inline bool4 yyyw() const { return bool4( y, y, y, w ); }
	inline bool4 zyyw() const { return bool4( z, y, y, w ); }
	inline bool4 wyyw() const { return bool4( w, y, y, w ); }
	inline bool4 xzyw() const { return bool4( x, z, y, w ); }
	inline bool4 yzyw() const { return bool4( y, z, y, w ); }
	inline bool4 zzyw() const { return bool4( z, z, y, w ); }
	inline bool4 wzyw() const { return bool4( w, z, y, w ); }
	inline bool4 xwyw() const { return bool4( x, w, y, w ); }
	inline bool4 ywyw() const { return bool4( y, w, y, w ); }
	inline bool4 zwyw() const { return bool4( z, w, y, w ); }
	inline bool4 wwyw() const { return bool4( w, w, y, w ); }
	inline bool4 xxzw() const { return bool4( x, x, z, w ); }
	inline bool4 yxzw() const { return bool4( y, x, z, w ); }
	inline bool4 zxzw() const { return bool4( z, x, z, w ); }
	inline bool4 wxzw() const { return bool4( w, x, z, w ); }
	inline bool4 xyzw() const { return bool4( x, y, z, w ); }
	inline bool4 yyzw() const { return bool4( y, y, z, w ); }
	inline bool4 zyzw() const { return bool4( z, y, z, w ); }
	inline bool4 wyzw() const { return bool4( w, y, z, w ); }
	inline bool4 xzzw() const { return bool4( x, z, z, w ); }
	inline bool4 yzzw() const { return bool4( y, z, z, w ); }
	inline bool4 zzzw() const { return bool4( z, z, z, w ); }
	inline bool4 wzzw() const { return bool4( w, z, z, w ); }
	inline bool4 xwzw() const { return bool4( x, w, z, w ); }
	inline bool4 ywzw() const { return bool4( y, w, z, w ); }
	inline bool4 zwzw() const { return bool4( z, w, z, w ); }
	inline bool4 wwzw() const { return bool4( w, w, z, w ); }
	inline bool4 xxww() const { return bool4( x, x, w, w ); }
	inline bool4 yxww() const { return bool4( y, x, w, w ); }
	inline bool4 zxww() const { return bool4( z, x, w, w ); }
	inline bool4 wxww() const { return bool4( w, x, w, w ); }
	inline bool4 xyww() const { return bool4( x, y, w, w ); }
	inline bool4 yyww() const { return bool4( y, y, w, w ); }
	inline bool4 zyww() const { return bool4( z, y, w, w ); }
	inline bool4 wyww() const { return bool4( w, y, w, w ); }
	inline bool4 xzww() const { return bool4( x, z, w, w ); }
	inline bool4 yzww() const { return bool4( y, z, w, w ); }
	inline bool4 zzww() const { return bool4( z, z, w, w ); }
	inline bool4 wzww() const { return bool4( w, z, w, w ); }
	inline bool4 xwww() const { return bool4( x, w, w, w ); }
	inline bool4 ywww() const { return bool4( y, w, w, w ); }
	inline bool4 zwww() const { return bool4( z, w, w, w ); }
	inline bool4 wwww() const { return bool4( w, w, w, w ); }

};

#if defined( __clang__ ) || defined( __GNUC__ )
#pragma GCC diagnostic pop
#endif

/// \relates bool4
/// \brief Returns true if the all the components of the left-hand-side bool4 match the other one, otherwise returns false.
inline bool operator==( const bool4& lhs, const bool4& rhs );

/// \relates bool4
/// \brief Returns true if not all of the components of the left-hand-side bool4 match the other one, otherwise returns false.
inline bool operator!=( const bool4& lhs, const bool4& rhs );

#include "bool4.inl"

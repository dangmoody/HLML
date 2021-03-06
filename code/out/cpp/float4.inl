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

// hlml includes
#include "float2.h"
#include "float3.h"
#include "float4.h"

#include "hlml_functions_scalar.h"

// others
#include <math.h>
#include <memory.h>
#include <assert.h>

float4::float4( const float x )
{
	this->x = this->y = this->z = this->w = x;
}

float4::float4( const float x, const float y, const float z, const float w )
{
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = w;
}

float4::float4( const float2& other )
{
	memcpy( data, other.data, sizeof( other.data ) );
}

float4::float4( const float3& other )
{
	memcpy( data, other.data, sizeof( other.data ) );
}

float4::float4( const float4& other )
{
	memcpy( data, other.data, sizeof( other.data ) );
}

float4 float4::operator=( const float2& rhs )
{
	memcpy( data, rhs.data, sizeof( rhs.data ) );
	return *this;
}

float4 float4::operator=( const float3& rhs )
{
	memcpy( data, rhs.data, sizeof( rhs.data ) );
	return *this;
}

float4 float4::operator=( const float4& rhs )
{
	memcpy( data, rhs.data, sizeof( rhs.data ) );
	return *this;
}

const float& float4::operator[]( const uint32_t index ) const
{
	assert( index < 4 );
	return data[index];
}

float& float4::operator[]( const uint32_t index )
{
	assert( index < 4 );
	return data[index];
}

float2 float4::xx() const { return float2( x, x ); }
float2 float4::yx() const { return float2( y, x ); }
float2 float4::xy() const { return float2( x, y ); }
float2 float4::yy() const { return float2( y, y ); }

float3 float4::xxx() const { return float3( x, x, x ); }
float3 float4::yxx() const { return float3( y, x, x ); }
float3 float4::zxx() const { return float3( z, x, x ); }
float3 float4::xyx() const { return float3( x, y, x ); }
float3 float4::yyx() const { return float3( y, y, x ); }
float3 float4::zyx() const { return float3( z, y, x ); }
float3 float4::xzx() const { return float3( x, z, x ); }
float3 float4::yzx() const { return float3( y, z, x ); }
float3 float4::zzx() const { return float3( z, z, x ); }
float3 float4::xxy() const { return float3( x, x, y ); }
float3 float4::yxy() const { return float3( y, x, y ); }
float3 float4::zxy() const { return float3( z, x, y ); }
float3 float4::xyy() const { return float3( x, y, y ); }
float3 float4::yyy() const { return float3( y, y, y ); }
float3 float4::zyy() const { return float3( z, y, y ); }
float3 float4::xzy() const { return float3( x, z, y ); }
float3 float4::yzy() const { return float3( y, z, y ); }
float3 float4::zzy() const { return float3( z, z, y ); }
float3 float4::xxz() const { return float3( x, x, z ); }
float3 float4::yxz() const { return float3( y, x, z ); }
float3 float4::zxz() const { return float3( z, x, z ); }
float3 float4::xyz() const { return float3( x, y, z ); }
float3 float4::yyz() const { return float3( y, y, z ); }
float3 float4::zyz() const { return float3( z, y, z ); }
float3 float4::xzz() const { return float3( x, z, z ); }
float3 float4::yzz() const { return float3( y, z, z ); }
float3 float4::zzz() const { return float3( z, z, z ); }

float4 float4::xxxx() const { return float4( x, x, x, x ); }
float4 float4::yxxx() const { return float4( y, x, x, x ); }
float4 float4::zxxx() const { return float4( z, x, x, x ); }
float4 float4::wxxx() const { return float4( w, x, x, x ); }
float4 float4::xyxx() const { return float4( x, y, x, x ); }
float4 float4::yyxx() const { return float4( y, y, x, x ); }
float4 float4::zyxx() const { return float4( z, y, x, x ); }
float4 float4::wyxx() const { return float4( w, y, x, x ); }
float4 float4::xzxx() const { return float4( x, z, x, x ); }
float4 float4::yzxx() const { return float4( y, z, x, x ); }
float4 float4::zzxx() const { return float4( z, z, x, x ); }
float4 float4::wzxx() const { return float4( w, z, x, x ); }
float4 float4::xwxx() const { return float4( x, w, x, x ); }
float4 float4::ywxx() const { return float4( y, w, x, x ); }
float4 float4::zwxx() const { return float4( z, w, x, x ); }
float4 float4::wwxx() const { return float4( w, w, x, x ); }
float4 float4::xxyx() const { return float4( x, x, y, x ); }
float4 float4::yxyx() const { return float4( y, x, y, x ); }
float4 float4::zxyx() const { return float4( z, x, y, x ); }
float4 float4::wxyx() const { return float4( w, x, y, x ); }
float4 float4::xyyx() const { return float4( x, y, y, x ); }
float4 float4::yyyx() const { return float4( y, y, y, x ); }
float4 float4::zyyx() const { return float4( z, y, y, x ); }
float4 float4::wyyx() const { return float4( w, y, y, x ); }
float4 float4::xzyx() const { return float4( x, z, y, x ); }
float4 float4::yzyx() const { return float4( y, z, y, x ); }
float4 float4::zzyx() const { return float4( z, z, y, x ); }
float4 float4::wzyx() const { return float4( w, z, y, x ); }
float4 float4::xwyx() const { return float4( x, w, y, x ); }
float4 float4::ywyx() const { return float4( y, w, y, x ); }
float4 float4::zwyx() const { return float4( z, w, y, x ); }
float4 float4::wwyx() const { return float4( w, w, y, x ); }
float4 float4::xxzx() const { return float4( x, x, z, x ); }
float4 float4::yxzx() const { return float4( y, x, z, x ); }
float4 float4::zxzx() const { return float4( z, x, z, x ); }
float4 float4::wxzx() const { return float4( w, x, z, x ); }
float4 float4::xyzx() const { return float4( x, y, z, x ); }
float4 float4::yyzx() const { return float4( y, y, z, x ); }
float4 float4::zyzx() const { return float4( z, y, z, x ); }
float4 float4::wyzx() const { return float4( w, y, z, x ); }
float4 float4::xzzx() const { return float4( x, z, z, x ); }
float4 float4::yzzx() const { return float4( y, z, z, x ); }
float4 float4::zzzx() const { return float4( z, z, z, x ); }
float4 float4::wzzx() const { return float4( w, z, z, x ); }
float4 float4::xwzx() const { return float4( x, w, z, x ); }
float4 float4::ywzx() const { return float4( y, w, z, x ); }
float4 float4::zwzx() const { return float4( z, w, z, x ); }
float4 float4::wwzx() const { return float4( w, w, z, x ); }
float4 float4::xxwx() const { return float4( x, x, w, x ); }
float4 float4::yxwx() const { return float4( y, x, w, x ); }
float4 float4::zxwx() const { return float4( z, x, w, x ); }
float4 float4::wxwx() const { return float4( w, x, w, x ); }
float4 float4::xywx() const { return float4( x, y, w, x ); }
float4 float4::yywx() const { return float4( y, y, w, x ); }
float4 float4::zywx() const { return float4( z, y, w, x ); }
float4 float4::wywx() const { return float4( w, y, w, x ); }
float4 float4::xzwx() const { return float4( x, z, w, x ); }
float4 float4::yzwx() const { return float4( y, z, w, x ); }
float4 float4::zzwx() const { return float4( z, z, w, x ); }
float4 float4::wzwx() const { return float4( w, z, w, x ); }
float4 float4::xwwx() const { return float4( x, w, w, x ); }
float4 float4::ywwx() const { return float4( y, w, w, x ); }
float4 float4::zwwx() const { return float4( z, w, w, x ); }
float4 float4::wwwx() const { return float4( w, w, w, x ); }
float4 float4::xxxy() const { return float4( x, x, x, y ); }
float4 float4::yxxy() const { return float4( y, x, x, y ); }
float4 float4::zxxy() const { return float4( z, x, x, y ); }
float4 float4::wxxy() const { return float4( w, x, x, y ); }
float4 float4::xyxy() const { return float4( x, y, x, y ); }
float4 float4::yyxy() const { return float4( y, y, x, y ); }
float4 float4::zyxy() const { return float4( z, y, x, y ); }
float4 float4::wyxy() const { return float4( w, y, x, y ); }
float4 float4::xzxy() const { return float4( x, z, x, y ); }
float4 float4::yzxy() const { return float4( y, z, x, y ); }
float4 float4::zzxy() const { return float4( z, z, x, y ); }
float4 float4::wzxy() const { return float4( w, z, x, y ); }
float4 float4::xwxy() const { return float4( x, w, x, y ); }
float4 float4::ywxy() const { return float4( y, w, x, y ); }
float4 float4::zwxy() const { return float4( z, w, x, y ); }
float4 float4::wwxy() const { return float4( w, w, x, y ); }
float4 float4::xxyy() const { return float4( x, x, y, y ); }
float4 float4::yxyy() const { return float4( y, x, y, y ); }
float4 float4::zxyy() const { return float4( z, x, y, y ); }
float4 float4::wxyy() const { return float4( w, x, y, y ); }
float4 float4::xyyy() const { return float4( x, y, y, y ); }
float4 float4::yyyy() const { return float4( y, y, y, y ); }
float4 float4::zyyy() const { return float4( z, y, y, y ); }
float4 float4::wyyy() const { return float4( w, y, y, y ); }
float4 float4::xzyy() const { return float4( x, z, y, y ); }
float4 float4::yzyy() const { return float4( y, z, y, y ); }
float4 float4::zzyy() const { return float4( z, z, y, y ); }
float4 float4::wzyy() const { return float4( w, z, y, y ); }
float4 float4::xwyy() const { return float4( x, w, y, y ); }
float4 float4::ywyy() const { return float4( y, w, y, y ); }
float4 float4::zwyy() const { return float4( z, w, y, y ); }
float4 float4::wwyy() const { return float4( w, w, y, y ); }
float4 float4::xxzy() const { return float4( x, x, z, y ); }
float4 float4::yxzy() const { return float4( y, x, z, y ); }
float4 float4::zxzy() const { return float4( z, x, z, y ); }
float4 float4::wxzy() const { return float4( w, x, z, y ); }
float4 float4::xyzy() const { return float4( x, y, z, y ); }
float4 float4::yyzy() const { return float4( y, y, z, y ); }
float4 float4::zyzy() const { return float4( z, y, z, y ); }
float4 float4::wyzy() const { return float4( w, y, z, y ); }
float4 float4::xzzy() const { return float4( x, z, z, y ); }
float4 float4::yzzy() const { return float4( y, z, z, y ); }
float4 float4::zzzy() const { return float4( z, z, z, y ); }
float4 float4::wzzy() const { return float4( w, z, z, y ); }
float4 float4::xwzy() const { return float4( x, w, z, y ); }
float4 float4::ywzy() const { return float4( y, w, z, y ); }
float4 float4::zwzy() const { return float4( z, w, z, y ); }
float4 float4::wwzy() const { return float4( w, w, z, y ); }
float4 float4::xxwy() const { return float4( x, x, w, y ); }
float4 float4::yxwy() const { return float4( y, x, w, y ); }
float4 float4::zxwy() const { return float4( z, x, w, y ); }
float4 float4::wxwy() const { return float4( w, x, w, y ); }
float4 float4::xywy() const { return float4( x, y, w, y ); }
float4 float4::yywy() const { return float4( y, y, w, y ); }
float4 float4::zywy() const { return float4( z, y, w, y ); }
float4 float4::wywy() const { return float4( w, y, w, y ); }
float4 float4::xzwy() const { return float4( x, z, w, y ); }
float4 float4::yzwy() const { return float4( y, z, w, y ); }
float4 float4::zzwy() const { return float4( z, z, w, y ); }
float4 float4::wzwy() const { return float4( w, z, w, y ); }
float4 float4::xwwy() const { return float4( x, w, w, y ); }
float4 float4::ywwy() const { return float4( y, w, w, y ); }
float4 float4::zwwy() const { return float4( z, w, w, y ); }
float4 float4::wwwy() const { return float4( w, w, w, y ); }
float4 float4::xxxz() const { return float4( x, x, x, z ); }
float4 float4::yxxz() const { return float4( y, x, x, z ); }
float4 float4::zxxz() const { return float4( z, x, x, z ); }
float4 float4::wxxz() const { return float4( w, x, x, z ); }
float4 float4::xyxz() const { return float4( x, y, x, z ); }
float4 float4::yyxz() const { return float4( y, y, x, z ); }
float4 float4::zyxz() const { return float4( z, y, x, z ); }
float4 float4::wyxz() const { return float4( w, y, x, z ); }
float4 float4::xzxz() const { return float4( x, z, x, z ); }
float4 float4::yzxz() const { return float4( y, z, x, z ); }
float4 float4::zzxz() const { return float4( z, z, x, z ); }
float4 float4::wzxz() const { return float4( w, z, x, z ); }
float4 float4::xwxz() const { return float4( x, w, x, z ); }
float4 float4::ywxz() const { return float4( y, w, x, z ); }
float4 float4::zwxz() const { return float4( z, w, x, z ); }
float4 float4::wwxz() const { return float4( w, w, x, z ); }
float4 float4::xxyz() const { return float4( x, x, y, z ); }
float4 float4::yxyz() const { return float4( y, x, y, z ); }
float4 float4::zxyz() const { return float4( z, x, y, z ); }
float4 float4::wxyz() const { return float4( w, x, y, z ); }
float4 float4::xyyz() const { return float4( x, y, y, z ); }
float4 float4::yyyz() const { return float4( y, y, y, z ); }
float4 float4::zyyz() const { return float4( z, y, y, z ); }
float4 float4::wyyz() const { return float4( w, y, y, z ); }
float4 float4::xzyz() const { return float4( x, z, y, z ); }
float4 float4::yzyz() const { return float4( y, z, y, z ); }
float4 float4::zzyz() const { return float4( z, z, y, z ); }
float4 float4::wzyz() const { return float4( w, z, y, z ); }
float4 float4::xwyz() const { return float4( x, w, y, z ); }
float4 float4::ywyz() const { return float4( y, w, y, z ); }
float4 float4::zwyz() const { return float4( z, w, y, z ); }
float4 float4::wwyz() const { return float4( w, w, y, z ); }
float4 float4::xxzz() const { return float4( x, x, z, z ); }
float4 float4::yxzz() const { return float4( y, x, z, z ); }
float4 float4::zxzz() const { return float4( z, x, z, z ); }
float4 float4::wxzz() const { return float4( w, x, z, z ); }
float4 float4::xyzz() const { return float4( x, y, z, z ); }
float4 float4::yyzz() const { return float4( y, y, z, z ); }
float4 float4::zyzz() const { return float4( z, y, z, z ); }
float4 float4::wyzz() const { return float4( w, y, z, z ); }
float4 float4::xzzz() const { return float4( x, z, z, z ); }
float4 float4::yzzz() const { return float4( y, z, z, z ); }
float4 float4::zzzz() const { return float4( z, z, z, z ); }
float4 float4::wzzz() const { return float4( w, z, z, z ); }
float4 float4::xwzz() const { return float4( x, w, z, z ); }
float4 float4::ywzz() const { return float4( y, w, z, z ); }
float4 float4::zwzz() const { return float4( z, w, z, z ); }
float4 float4::wwzz() const { return float4( w, w, z, z ); }
float4 float4::xxwz() const { return float4( x, x, w, z ); }
float4 float4::yxwz() const { return float4( y, x, w, z ); }
float4 float4::zxwz() const { return float4( z, x, w, z ); }
float4 float4::wxwz() const { return float4( w, x, w, z ); }
float4 float4::xywz() const { return float4( x, y, w, z ); }
float4 float4::yywz() const { return float4( y, y, w, z ); }
float4 float4::zywz() const { return float4( z, y, w, z ); }
float4 float4::wywz() const { return float4( w, y, w, z ); }
float4 float4::xzwz() const { return float4( x, z, w, z ); }
float4 float4::yzwz() const { return float4( y, z, w, z ); }
float4 float4::zzwz() const { return float4( z, z, w, z ); }
float4 float4::wzwz() const { return float4( w, z, w, z ); }
float4 float4::xwwz() const { return float4( x, w, w, z ); }
float4 float4::ywwz() const { return float4( y, w, w, z ); }
float4 float4::zwwz() const { return float4( z, w, w, z ); }
float4 float4::wwwz() const { return float4( w, w, w, z ); }
float4 float4::xxxw() const { return float4( x, x, x, w ); }
float4 float4::yxxw() const { return float4( y, x, x, w ); }
float4 float4::zxxw() const { return float4( z, x, x, w ); }
float4 float4::wxxw() const { return float4( w, x, x, w ); }
float4 float4::xyxw() const { return float4( x, y, x, w ); }
float4 float4::yyxw() const { return float4( y, y, x, w ); }
float4 float4::zyxw() const { return float4( z, y, x, w ); }
float4 float4::wyxw() const { return float4( w, y, x, w ); }
float4 float4::xzxw() const { return float4( x, z, x, w ); }
float4 float4::yzxw() const { return float4( y, z, x, w ); }
float4 float4::zzxw() const { return float4( z, z, x, w ); }
float4 float4::wzxw() const { return float4( w, z, x, w ); }
float4 float4::xwxw() const { return float4( x, w, x, w ); }
float4 float4::ywxw() const { return float4( y, w, x, w ); }
float4 float4::zwxw() const { return float4( z, w, x, w ); }
float4 float4::wwxw() const { return float4( w, w, x, w ); }
float4 float4::xxyw() const { return float4( x, x, y, w ); }
float4 float4::yxyw() const { return float4( y, x, y, w ); }
float4 float4::zxyw() const { return float4( z, x, y, w ); }
float4 float4::wxyw() const { return float4( w, x, y, w ); }
float4 float4::xyyw() const { return float4( x, y, y, w ); }
float4 float4::yyyw() const { return float4( y, y, y, w ); }
float4 float4::zyyw() const { return float4( z, y, y, w ); }
float4 float4::wyyw() const { return float4( w, y, y, w ); }
float4 float4::xzyw() const { return float4( x, z, y, w ); }
float4 float4::yzyw() const { return float4( y, z, y, w ); }
float4 float4::zzyw() const { return float4( z, z, y, w ); }
float4 float4::wzyw() const { return float4( w, z, y, w ); }
float4 float4::xwyw() const { return float4( x, w, y, w ); }
float4 float4::ywyw() const { return float4( y, w, y, w ); }
float4 float4::zwyw() const { return float4( z, w, y, w ); }
float4 float4::wwyw() const { return float4( w, w, y, w ); }
float4 float4::xxzw() const { return float4( x, x, z, w ); }
float4 float4::yxzw() const { return float4( y, x, z, w ); }
float4 float4::zxzw() const { return float4( z, x, z, w ); }
float4 float4::wxzw() const { return float4( w, x, z, w ); }
float4 float4::xyzw() const { return float4( x, y, z, w ); }
float4 float4::yyzw() const { return float4( y, y, z, w ); }
float4 float4::zyzw() const { return float4( z, y, z, w ); }
float4 float4::wyzw() const { return float4( w, y, z, w ); }
float4 float4::xzzw() const { return float4( x, z, z, w ); }
float4 float4::yzzw() const { return float4( y, z, z, w ); }
float4 float4::zzzw() const { return float4( z, z, z, w ); }
float4 float4::wzzw() const { return float4( w, z, z, w ); }
float4 float4::xwzw() const { return float4( x, w, z, w ); }
float4 float4::ywzw() const { return float4( y, w, z, w ); }
float4 float4::zwzw() const { return float4( z, w, z, w ); }
float4 float4::wwzw() const { return float4( w, w, z, w ); }
float4 float4::xxww() const { return float4( x, x, w, w ); }
float4 float4::yxww() const { return float4( y, x, w, w ); }
float4 float4::zxww() const { return float4( z, x, w, w ); }
float4 float4::wxww() const { return float4( w, x, w, w ); }
float4 float4::xyww() const { return float4( x, y, w, w ); }
float4 float4::yyww() const { return float4( y, y, w, w ); }
float4 float4::zyww() const { return float4( z, y, w, w ); }
float4 float4::wyww() const { return float4( w, y, w, w ); }
float4 float4::xzww() const { return float4( x, z, w, w ); }
float4 float4::yzww() const { return float4( y, z, w, w ); }
float4 float4::zzww() const { return float4( z, z, w, w ); }
float4 float4::wzww() const { return float4( w, z, w, w ); }
float4 float4::xwww() const { return float4( x, w, w, w ); }
float4 float4::ywww() const { return float4( y, w, w, w ); }
float4 float4::zwww() const { return float4( z, w, w, w ); }
float4 float4::wwww() const { return float4( w, w, w, w ); }


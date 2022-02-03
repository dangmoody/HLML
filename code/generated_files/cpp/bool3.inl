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

#include "bool3.h"

#include "hlml_defines.h"

bool3::bool3( const bool32_t scalar )
{
	this->x = scalar;
	this->y = scalar;
	this->z = scalar;
}

bool3::bool3( const bool32_t x, const bool32_t y, const bool32_t z )
{
	this->x = x;
	this->y = y;
	this->z = z;
}

bool3::bool3( const bool2& other )
{
	this->x = other.x;
	this->y = other.y;
}

bool3::bool3( const bool3& other )
{
	this->x = other.x;
	this->y = other.y;
	this->z = other.z;
}

bool3 bool3::operator=( const bool2& other )
{
	this->x = other.x;
	this->y = other.y;

	return *this;
}

bool3 bool3::operator=( const bool3& other )
{
	this->x = other.x;
	this->y = other.y;
	this->z = other.z;

	return *this;
}

bool32_t& bool3::operator[]( const int32_t index )
{
	HLML_ASSERT( index >= 0 && index < 3 );
	return v[index];
}

const bool32_t& bool3::operator[]( const int32_t index ) const
{
	HLML_ASSERT( index >= 0 && index < 3 );
	return v[index];
}

// swizzle functions
bool2 bool3::xx() const { return bool2( x, x ); }
bool2 bool3::xy() const { return bool2( x, y ); }
bool2 bool3::xz() const { return bool2( x, z ); }
bool2 bool3::yx() const { return bool2( y, x ); }
bool2 bool3::yy() const { return bool2( y, y ); }
bool2 bool3::yz() const { return bool2( y, z ); }
bool2 bool3::zx() const { return bool2( z, x ); }
bool2 bool3::zy() const { return bool2( z, y ); }
bool2 bool3::zz() const { return bool2( z, z ); }
bool3 bool3::xxx() const { return bool3( x, x, x ); }
bool3 bool3::xxy() const { return bool3( x, x, y ); }
bool3 bool3::xxz() const { return bool3( x, x, z ); }
bool3 bool3::xyx() const { return bool3( x, y, x ); }
bool3 bool3::xyy() const { return bool3( x, y, y ); }
bool3 bool3::xyz() const { return bool3( x, y, z ); }
bool3 bool3::xzx() const { return bool3( x, z, x ); }
bool3 bool3::xzy() const { return bool3( x, z, y ); }
bool3 bool3::xzz() const { return bool3( x, z, z ); }
bool3 bool3::yxx() const { return bool3( y, x, x ); }
bool3 bool3::yxy() const { return bool3( y, x, y ); }
bool3 bool3::yxz() const { return bool3( y, x, z ); }
bool3 bool3::yyx() const { return bool3( y, y, x ); }
bool3 bool3::yyy() const { return bool3( y, y, y ); }
bool3 bool3::yyz() const { return bool3( y, y, z ); }
bool3 bool3::yzx() const { return bool3( y, z, x ); }
bool3 bool3::yzy() const { return bool3( y, z, y ); }
bool3 bool3::yzz() const { return bool3( y, z, z ); }
bool3 bool3::zxx() const { return bool3( z, x, x ); }
bool3 bool3::zxy() const { return bool3( z, x, y ); }
bool3 bool3::zxz() const { return bool3( z, x, z ); }
bool3 bool3::zyx() const { return bool3( z, y, x ); }
bool3 bool3::zyy() const { return bool3( z, y, y ); }
bool3 bool3::zyz() const { return bool3( z, y, z ); }
bool3 bool3::zzx() const { return bool3( z, z, x ); }
bool3 bool3::zzy() const { return bool3( z, z, y ); }
bool3 bool3::zzz() const { return bool3( z, z, z ); }
bool4 bool3::xxxx() const { return bool4( x, x, x, x ); }
bool4 bool3::xxxy() const { return bool4( x, x, x, y ); }
bool4 bool3::xxxz() const { return bool4( x, x, x, z ); }
bool4 bool3::xxyx() const { return bool4( x, x, y, x ); }
bool4 bool3::xxyy() const { return bool4( x, x, y, y ); }
bool4 bool3::xxyz() const { return bool4( x, x, y, z ); }
bool4 bool3::xxzx() const { return bool4( x, x, z, x ); }
bool4 bool3::xxzy() const { return bool4( x, x, z, y ); }
bool4 bool3::xxzz() const { return bool4( x, x, z, z ); }
bool4 bool3::xyxx() const { return bool4( x, y, x, x ); }
bool4 bool3::xyxy() const { return bool4( x, y, x, y ); }
bool4 bool3::xyxz() const { return bool4( x, y, x, z ); }
bool4 bool3::xyyx() const { return bool4( x, y, y, x ); }
bool4 bool3::xyyy() const { return bool4( x, y, y, y ); }
bool4 bool3::xyyz() const { return bool4( x, y, y, z ); }
bool4 bool3::xyzx() const { return bool4( x, y, z, x ); }
bool4 bool3::xyzy() const { return bool4( x, y, z, y ); }
bool4 bool3::xyzz() const { return bool4( x, y, z, z ); }
bool4 bool3::xzxx() const { return bool4( x, z, x, x ); }
bool4 bool3::xzxy() const { return bool4( x, z, x, y ); }
bool4 bool3::xzxz() const { return bool4( x, z, x, z ); }
bool4 bool3::xzyx() const { return bool4( x, z, y, x ); }
bool4 bool3::xzyy() const { return bool4( x, z, y, y ); }
bool4 bool3::xzyz() const { return bool4( x, z, y, z ); }
bool4 bool3::xzzx() const { return bool4( x, z, z, x ); }
bool4 bool3::xzzy() const { return bool4( x, z, z, y ); }
bool4 bool3::xzzz() const { return bool4( x, z, z, z ); }
bool4 bool3::yxxx() const { return bool4( y, x, x, x ); }
bool4 bool3::yxxy() const { return bool4( y, x, x, y ); }
bool4 bool3::yxxz() const { return bool4( y, x, x, z ); }
bool4 bool3::yxyx() const { return bool4( y, x, y, x ); }
bool4 bool3::yxyy() const { return bool4( y, x, y, y ); }
bool4 bool3::yxyz() const { return bool4( y, x, y, z ); }
bool4 bool3::yxzx() const { return bool4( y, x, z, x ); }
bool4 bool3::yxzy() const { return bool4( y, x, z, y ); }
bool4 bool3::yxzz() const { return bool4( y, x, z, z ); }
bool4 bool3::yyxx() const { return bool4( y, y, x, x ); }
bool4 bool3::yyxy() const { return bool4( y, y, x, y ); }
bool4 bool3::yyxz() const { return bool4( y, y, x, z ); }
bool4 bool3::yyyx() const { return bool4( y, y, y, x ); }
bool4 bool3::yyyy() const { return bool4( y, y, y, y ); }
bool4 bool3::yyyz() const { return bool4( y, y, y, z ); }
bool4 bool3::yyzx() const { return bool4( y, y, z, x ); }
bool4 bool3::yyzy() const { return bool4( y, y, z, y ); }
bool4 bool3::yyzz() const { return bool4( y, y, z, z ); }
bool4 bool3::yzxx() const { return bool4( y, z, x, x ); }
bool4 bool3::yzxy() const { return bool4( y, z, x, y ); }
bool4 bool3::yzxz() const { return bool4( y, z, x, z ); }
bool4 bool3::yzyx() const { return bool4( y, z, y, x ); }
bool4 bool3::yzyy() const { return bool4( y, z, y, y ); }
bool4 bool3::yzyz() const { return bool4( y, z, y, z ); }
bool4 bool3::yzzx() const { return bool4( y, z, z, x ); }
bool4 bool3::yzzy() const { return bool4( y, z, z, y ); }
bool4 bool3::yzzz() const { return bool4( y, z, z, z ); }
bool4 bool3::zxxx() const { return bool4( z, x, x, x ); }
bool4 bool3::zxxy() const { return bool4( z, x, x, y ); }
bool4 bool3::zxxz() const { return bool4( z, x, x, z ); }
bool4 bool3::zxyx() const { return bool4( z, x, y, x ); }
bool4 bool3::zxyy() const { return bool4( z, x, y, y ); }
bool4 bool3::zxyz() const { return bool4( z, x, y, z ); }
bool4 bool3::zxzx() const { return bool4( z, x, z, x ); }
bool4 bool3::zxzy() const { return bool4( z, x, z, y ); }
bool4 bool3::zxzz() const { return bool4( z, x, z, z ); }
bool4 bool3::zyxx() const { return bool4( z, y, x, x ); }
bool4 bool3::zyxy() const { return bool4( z, y, x, y ); }
bool4 bool3::zyxz() const { return bool4( z, y, x, z ); }
bool4 bool3::zyyx() const { return bool4( z, y, y, x ); }
bool4 bool3::zyyy() const { return bool4( z, y, y, y ); }
bool4 bool3::zyyz() const { return bool4( z, y, y, z ); }
bool4 bool3::zyzx() const { return bool4( z, y, z, x ); }
bool4 bool3::zyzy() const { return bool4( z, y, z, y ); }
bool4 bool3::zyzz() const { return bool4( z, y, z, z ); }
bool4 bool3::zzxx() const { return bool4( z, z, x, x ); }
bool4 bool3::zzxy() const { return bool4( z, z, x, y ); }
bool4 bool3::zzxz() const { return bool4( z, z, x, z ); }
bool4 bool3::zzyx() const { return bool4( z, z, y, x ); }
bool4 bool3::zzyy() const { return bool4( z, z, y, y ); }
bool4 bool3::zzyz() const { return bool4( z, z, y, z ); }
bool4 bool3::zzzx() const { return bool4( z, z, z, x ); }
bool4 bool3::zzzy() const { return bool4( z, z, z, y ); }
bool4 bool3::zzzz() const { return bool4( z, z, z, z ); }

bool2 bool3::rr() const { return bool2( r, r ); }
bool2 bool3::rg() const { return bool2( r, g ); }
bool2 bool3::rb() const { return bool2( r, b ); }
bool2 bool3::gr() const { return bool2( g, r ); }
bool2 bool3::gg() const { return bool2( g, g ); }
bool2 bool3::gb() const { return bool2( g, b ); }
bool2 bool3::br() const { return bool2( b, r ); }
bool2 bool3::bg() const { return bool2( b, g ); }
bool2 bool3::bb() const { return bool2( b, b ); }
bool3 bool3::rrr() const { return bool3( r, r, r ); }
bool3 bool3::rrg() const { return bool3( r, r, g ); }
bool3 bool3::rrb() const { return bool3( r, r, b ); }
bool3 bool3::rgr() const { return bool3( r, g, r ); }
bool3 bool3::rgg() const { return bool3( r, g, g ); }
bool3 bool3::rgb() const { return bool3( r, g, b ); }
bool3 bool3::rbr() const { return bool3( r, b, r ); }
bool3 bool3::rbg() const { return bool3( r, b, g ); }
bool3 bool3::rbb() const { return bool3( r, b, b ); }
bool3 bool3::grr() const { return bool3( g, r, r ); }
bool3 bool3::grg() const { return bool3( g, r, g ); }
bool3 bool3::grb() const { return bool3( g, r, b ); }
bool3 bool3::ggr() const { return bool3( g, g, r ); }
bool3 bool3::ggg() const { return bool3( g, g, g ); }
bool3 bool3::ggb() const { return bool3( g, g, b ); }
bool3 bool3::gbr() const { return bool3( g, b, r ); }
bool3 bool3::gbg() const { return bool3( g, b, g ); }
bool3 bool3::gbb() const { return bool3( g, b, b ); }
bool3 bool3::brr() const { return bool3( b, r, r ); }
bool3 bool3::brg() const { return bool3( b, r, g ); }
bool3 bool3::brb() const { return bool3( b, r, b ); }
bool3 bool3::bgr() const { return bool3( b, g, r ); }
bool3 bool3::bgg() const { return bool3( b, g, g ); }
bool3 bool3::bgb() const { return bool3( b, g, b ); }
bool3 bool3::bbr() const { return bool3( b, b, r ); }
bool3 bool3::bbg() const { return bool3( b, b, g ); }
bool3 bool3::bbb() const { return bool3( b, b, b ); }
bool4 bool3::rrrr() const { return bool4( r, r, r, r ); }
bool4 bool3::rrrg() const { return bool4( r, r, r, g ); }
bool4 bool3::rrrb() const { return bool4( r, r, r, b ); }
bool4 bool3::rrgr() const { return bool4( r, r, g, r ); }
bool4 bool3::rrgg() const { return bool4( r, r, g, g ); }
bool4 bool3::rrgb() const { return bool4( r, r, g, b ); }
bool4 bool3::rrbr() const { return bool4( r, r, b, r ); }
bool4 bool3::rrbg() const { return bool4( r, r, b, g ); }
bool4 bool3::rrbb() const { return bool4( r, r, b, b ); }
bool4 bool3::rgrr() const { return bool4( r, g, r, r ); }
bool4 bool3::rgrg() const { return bool4( r, g, r, g ); }
bool4 bool3::rgrb() const { return bool4( r, g, r, b ); }
bool4 bool3::rggr() const { return bool4( r, g, g, r ); }
bool4 bool3::rggg() const { return bool4( r, g, g, g ); }
bool4 bool3::rggb() const { return bool4( r, g, g, b ); }
bool4 bool3::rgbr() const { return bool4( r, g, b, r ); }
bool4 bool3::rgbg() const { return bool4( r, g, b, g ); }
bool4 bool3::rgbb() const { return bool4( r, g, b, b ); }
bool4 bool3::rbrr() const { return bool4( r, b, r, r ); }
bool4 bool3::rbrg() const { return bool4( r, b, r, g ); }
bool4 bool3::rbrb() const { return bool4( r, b, r, b ); }
bool4 bool3::rbgr() const { return bool4( r, b, g, r ); }
bool4 bool3::rbgg() const { return bool4( r, b, g, g ); }
bool4 bool3::rbgb() const { return bool4( r, b, g, b ); }
bool4 bool3::rbbr() const { return bool4( r, b, b, r ); }
bool4 bool3::rbbg() const { return bool4( r, b, b, g ); }
bool4 bool3::rbbb() const { return bool4( r, b, b, b ); }
bool4 bool3::grrr() const { return bool4( g, r, r, r ); }
bool4 bool3::grrg() const { return bool4( g, r, r, g ); }
bool4 bool3::grrb() const { return bool4( g, r, r, b ); }
bool4 bool3::grgr() const { return bool4( g, r, g, r ); }
bool4 bool3::grgg() const { return bool4( g, r, g, g ); }
bool4 bool3::grgb() const { return bool4( g, r, g, b ); }
bool4 bool3::grbr() const { return bool4( g, r, b, r ); }
bool4 bool3::grbg() const { return bool4( g, r, b, g ); }
bool4 bool3::grbb() const { return bool4( g, r, b, b ); }
bool4 bool3::ggrr() const { return bool4( g, g, r, r ); }
bool4 bool3::ggrg() const { return bool4( g, g, r, g ); }
bool4 bool3::ggrb() const { return bool4( g, g, r, b ); }
bool4 bool3::gggr() const { return bool4( g, g, g, r ); }
bool4 bool3::gggg() const { return bool4( g, g, g, g ); }
bool4 bool3::gggb() const { return bool4( g, g, g, b ); }
bool4 bool3::ggbr() const { return bool4( g, g, b, r ); }
bool4 bool3::ggbg() const { return bool4( g, g, b, g ); }
bool4 bool3::ggbb() const { return bool4( g, g, b, b ); }
bool4 bool3::gbrr() const { return bool4( g, b, r, r ); }
bool4 bool3::gbrg() const { return bool4( g, b, r, g ); }
bool4 bool3::gbrb() const { return bool4( g, b, r, b ); }
bool4 bool3::gbgr() const { return bool4( g, b, g, r ); }
bool4 bool3::gbgg() const { return bool4( g, b, g, g ); }
bool4 bool3::gbgb() const { return bool4( g, b, g, b ); }
bool4 bool3::gbbr() const { return bool4( g, b, b, r ); }
bool4 bool3::gbbg() const { return bool4( g, b, b, g ); }
bool4 bool3::gbbb() const { return bool4( g, b, b, b ); }
bool4 bool3::brrr() const { return bool4( b, r, r, r ); }
bool4 bool3::brrg() const { return bool4( b, r, r, g ); }
bool4 bool3::brrb() const { return bool4( b, r, r, b ); }
bool4 bool3::brgr() const { return bool4( b, r, g, r ); }
bool4 bool3::brgg() const { return bool4( b, r, g, g ); }
bool4 bool3::brgb() const { return bool4( b, r, g, b ); }
bool4 bool3::brbr() const { return bool4( b, r, b, r ); }
bool4 bool3::brbg() const { return bool4( b, r, b, g ); }
bool4 bool3::brbb() const { return bool4( b, r, b, b ); }
bool4 bool3::bgrr() const { return bool4( b, g, r, r ); }
bool4 bool3::bgrg() const { return bool4( b, g, r, g ); }
bool4 bool3::bgrb() const { return bool4( b, g, r, b ); }
bool4 bool3::bggr() const { return bool4( b, g, g, r ); }
bool4 bool3::bggg() const { return bool4( b, g, g, g ); }
bool4 bool3::bggb() const { return bool4( b, g, g, b ); }
bool4 bool3::bgbr() const { return bool4( b, g, b, r ); }
bool4 bool3::bgbg() const { return bool4( b, g, b, g ); }
bool4 bool3::bgbb() const { return bool4( b, g, b, b ); }
bool4 bool3::bbrr() const { return bool4( b, b, r, r ); }
bool4 bool3::bbrg() const { return bool4( b, b, r, g ); }
bool4 bool3::bbrb() const { return bool4( b, b, r, b ); }
bool4 bool3::bbgr() const { return bool4( b, b, g, r ); }
bool4 bool3::bbgg() const { return bool4( b, b, g, g ); }
bool4 bool3::bbgb() const { return bool4( b, b, g, b ); }
bool4 bool3::bbbr() const { return bool4( b, b, b, r ); }
bool4 bool3::bbbg() const { return bool4( b, b, b, g ); }
bool4 bool3::bbbb() const { return bool4( b, b, b, b ); }


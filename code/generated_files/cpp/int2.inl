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

#include "int2.h"

#include "hlml_defines.h"

int2::int2( const int32_t scalar )
{
	this->x = scalar;
	this->y = scalar;
}

int2::int2( const int32_t x, const int32_t y )
{
	this->x = x;
	this->y = y;
}

int2::int2( const int2& other )
{
	this->x = other.x;
	this->y = other.y;
}

int2 int2::operator=( const int2& other )
{
	this->x = other.x;
	this->y = other.y;

	return *this;
}

int32_t& int2::operator[]( const int32_t index )
{
	HLML_ASSERT( index >= 0 && index < 2 );
	return v[index];
}

const int32_t& int2::operator[]( const int32_t index ) const
{
	HLML_ASSERT( index >= 0 && index < 2 );
	return v[index];
}

// swizzle functions
int2 int2::xx() const { return int2( x, x ); }
int2 int2::xy() const { return int2( x, y ); }
int2 int2::yx() const { return int2( y, x ); }
int2 int2::yy() const { return int2( y, y ); }
int3 int2::xxx() const { return int3( x, x, x ); }
int3 int2::xxy() const { return int3( x, x, y ); }
int3 int2::xyx() const { return int3( x, y, x ); }
int3 int2::xyy() const { return int3( x, y, y ); }
int3 int2::yxx() const { return int3( y, x, x ); }
int3 int2::yxy() const { return int3( y, x, y ); }
int3 int2::yyx() const { return int3( y, y, x ); }
int3 int2::yyy() const { return int3( y, y, y ); }
int4 int2::xxxx() const { return int4( x, x, x, x ); }
int4 int2::xxxy() const { return int4( x, x, x, y ); }
int4 int2::xxyx() const { return int4( x, x, y, x ); }
int4 int2::xxyy() const { return int4( x, x, y, y ); }
int4 int2::xyxx() const { return int4( x, y, x, x ); }
int4 int2::xyxy() const { return int4( x, y, x, y ); }
int4 int2::xyyx() const { return int4( x, y, y, x ); }
int4 int2::xyyy() const { return int4( x, y, y, y ); }
int4 int2::yxxx() const { return int4( y, x, x, x ); }
int4 int2::yxxy() const { return int4( y, x, x, y ); }
int4 int2::yxyx() const { return int4( y, x, y, x ); }
int4 int2::yxyy() const { return int4( y, x, y, y ); }
int4 int2::yyxx() const { return int4( y, y, x, x ); }
int4 int2::yyxy() const { return int4( y, y, x, y ); }
int4 int2::yyyx() const { return int4( y, y, y, x ); }
int4 int2::yyyy() const { return int4( y, y, y, y ); }

int2 int2::rr() const { return int2( r, r ); }
int2 int2::rg() const { return int2( r, g ); }
int2 int2::gr() const { return int2( g, r ); }
int2 int2::gg() const { return int2( g, g ); }
int3 int2::rrr() const { return int3( r, r, r ); }
int3 int2::rrg() const { return int3( r, r, g ); }
int3 int2::rgr() const { return int3( r, g, r ); }
int3 int2::rgg() const { return int3( r, g, g ); }
int3 int2::grr() const { return int3( g, r, r ); }
int3 int2::grg() const { return int3( g, r, g ); }
int3 int2::ggr() const { return int3( g, g, r ); }
int3 int2::ggg() const { return int3( g, g, g ); }
int4 int2::rrrr() const { return int4( r, r, r, r ); }
int4 int2::rrrg() const { return int4( r, r, r, g ); }
int4 int2::rrgr() const { return int4( r, r, g, r ); }
int4 int2::rrgg() const { return int4( r, r, g, g ); }
int4 int2::rgrr() const { return int4( r, g, r, r ); }
int4 int2::rgrg() const { return int4( r, g, r, g ); }
int4 int2::rggr() const { return int4( r, g, g, r ); }
int4 int2::rggg() const { return int4( r, g, g, g ); }
int4 int2::grrr() const { return int4( g, r, r, r ); }
int4 int2::grrg() const { return int4( g, r, r, g ); }
int4 int2::grgr() const { return int4( g, r, g, r ); }
int4 int2::grgg() const { return int4( g, r, g, g ); }
int4 int2::ggrr() const { return int4( g, g, r, r ); }
int4 int2::ggrg() const { return int4( g, g, r, g ); }
int4 int2::gggr() const { return int4( g, g, g, r ); }
int4 int2::gggg() const { return int4( g, g, g, g ); }


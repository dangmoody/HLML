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

#include "bool2.h"

#include "hlml_defines.h"

bool2::bool2( const bool32_t scalar )
	: x( scalar )
	, y( scalar )
{
}

bool2::bool2( const bool32_t x, const bool32_t y )
	: x( x )
	, y( y )
{
}

bool2::bool2( const bool2& vec )
	: x( vec.x )
	, y( vec.y )
{
}

bool2::bool2( const int2& vec )
	: x( (bool32_t) vec.x )
	, y( (bool32_t) vec.y )
{
}

bool2::bool2( const uint2& vec )
	: x( (bool32_t) vec.x )
	, y( (bool32_t) vec.y )
{
}

bool2::bool2( const float2& vec )
	: x( (bool32_t) vec.x )
	, y( (bool32_t) vec.y )
{
}

bool2::bool2( const double2& vec )
	: x( (bool32_t) vec.x )
	, y( (bool32_t) vec.y )
{
}

bool2 bool2::operator=( const bool2& other )
{
	this->x = other.x;
	this->y = other.y;

	return *this;
}

bool32_t& bool2::operator[]( const int32_t index )
{
	HLML_ASSERT( index >= 0 && index < 2 );
	return v[index];
}

const bool32_t& bool2::operator[]( const int32_t index ) const
{
	HLML_ASSERT( index >= 0 && index < 2 );
	return v[index];
}

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

#ifdef HLML_NAMESPACE
namespace hlml
{
#endif

#include "float4.h"

#include "hlml_defines.h"

float4::float4( const float scalar )
	: x( scalar )
	, y( scalar )
	, z( scalar )
	, w( scalar )
{
}

float4::float4( const float x, const float y, const float z, const float w )
	: x( x )
	, y( y )
	, z( z )
	, w( w )
{
}

float4::float4( const float4& vec )
	: x( vec.x )
	, y( vec.y )
	, z( vec.z )
	, w( vec.w )
{
}

float4::float4( const bool4& vec )
	: x( (float) vec.x )
	, y( (float) vec.y )
	, z( (float) vec.z )
	, w( (float) vec.w )
{
}

float4::float4( const int4& vec )
	: x( (float) vec.x )
	, y( (float) vec.y )
	, z( (float) vec.z )
	, w( (float) vec.w )
{
}

float4::float4( const uint4& vec )
	: x( (float) vec.x )
	, y( (float) vec.y )
	, z( (float) vec.z )
	, w( (float) vec.w )
{
}

float4::float4( const double4& vec )
	: x( (float) vec.x )
	, y( (float) vec.y )
	, z( (float) vec.z )
	, w( (float) vec.w )
{
}

float4::float4( const float2& xy, const float z, const float w )
	: x( xy.x )
	, y( xy.y )
	, z( z )
	, w( w )
{
}

float4::float4( const float x, const float y, const float2& zw )
	: x( x )
	, y( y )
	, z( zw.x )
	, w( zw.y )
{
}

float4::float4( const float3& xyz, const float w )
	: x( xyz.x )
	, y( xyz.y )
	, z( xyz.z )
	, w( w )
{
}

float4::float4( const float x, const float3& w )
	: x( x )
	, y( w.x )
	, z( w.y )
	, w( w.z )
{
}

float4::float4( const float2& xy, const float2& zw )
	: x( xy.x )
	, y( xy.y )
	, z( zw.x )
	, w( zw.y )
{
}

float4 float4::operator=( const float2& other )
{
	this->x = other.x;
	this->y = other.y;

	return *this;
}

float4 float4::operator=( const float3& other )
{
	this->x = other.x;
	this->y = other.y;
	this->z = other.z;

	return *this;
}

float4 float4::operator=( const float4& other )
{
	this->x = other.x;
	this->y = other.y;
	this->z = other.z;
	this->w = other.w;

	return *this;
}

float& float4::operator[]( const int32_t index )
{
	HLML_ASSERT( index >= 0 && index < 4 );
	return v[index];
}

const float& float4::operator[]( const int32_t index ) const
{
	HLML_ASSERT( index >= 0 && index < 4 );
	return v[index];
}
#ifdef HLML_NAMESPACE
}
#endif

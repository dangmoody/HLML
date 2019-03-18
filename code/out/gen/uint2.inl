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

// hlml includes
#include "uint3.h"
#include "uint4.h"

#include "../hlml_main.h"

// others
#include <math.h>
#include <memory.h>
#include <assert.h>

uint2::uint2()
{
	memset( data, 0, 2 * sizeof( uint32_t ) );
}

uint2::uint2( const uint32_t x )
{
	this->x = this->y = x;
}

uint2::uint2( const uint32_t x, const uint32_t y )
{
	this->x = x;
	this->y = y;
}

uint2::uint2( const uint2& other )
{
	memcpy( data, other.data, sizeof( other.data ) );
}

uint2::uint2( const uint3& other )
{
	memcpy( data, other.data, sizeof( other.data ) );
}

uint2::uint2( const uint4& other )
{
	memcpy( data, other.data, sizeof( other.data ) );
}

uint2 uint2::operator=( const uint2& rhs )
{
	memcpy( data, rhs.data, sizeof( rhs.data ) );
	return *this;
}

uint2 uint2::operator=( const uint3& rhs )
{
	memcpy( data, rhs.data, sizeof( rhs.data ) );
	return *this;
}

uint2 uint2::operator=( const uint4& rhs )
{
	memcpy( data, rhs.data, sizeof( rhs.data ) );
	return *this;
}

const uint32_t& uint2::operator[]( const uint32_t index ) const
{
	assert( index < 2 );
	return data[index];
}

uint32_t& uint2::operator[]( const uint32_t index )
{
	assert( index < 2 );
	return data[index];
}

bool operator==( const uint2& lhs, const uint2& rhs )
{
	return ( lhs.x == rhs.x ) && ( lhs.y == rhs.y );
}

bool operator!=( const uint2& lhs, const uint2& rhs )
{
	return !( operator==( lhs, rhs ) );
}


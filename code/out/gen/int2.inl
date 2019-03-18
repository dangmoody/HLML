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
#include "int3.h"
#include "int4.h"

#include "../hlml_main.h"

// others
#include <math.h>
#include <memory.h>
#include <assert.h>

int2::int2()
{
	memset( data, 0, 2 * sizeof( int32_t ) );
}

int2::int2( const int32_t x )
{
	this->x = this->y = x;
}

int2::int2( const int32_t x, const int32_t y )
{
	this->x = x;
	this->y = y;
}

int2::int2( const int2& other )
{
	memcpy( data, other.data, sizeof( other.data ) );
}

int2::int2( const int3& other )
{
	memcpy( data, other.data, sizeof( other.data ) );
}

int2::int2( const int4& other )
{
	memcpy( data, other.data, sizeof( other.data ) );
}

int2 int2::operator=( const int2& rhs )
{
	memcpy( data, rhs.data, sizeof( rhs.data ) );
	return *this;
}

int2 int2::operator=( const int3& rhs )
{
	memcpy( data, rhs.data, sizeof( rhs.data ) );
	return *this;
}

int2 int2::operator=( const int4& rhs )
{
	memcpy( data, rhs.data, sizeof( rhs.data ) );
	return *this;
}

const int32_t& int2::operator[]( const uint32_t index ) const
{
	assert( index < 2 );
	return data[index];
}

int32_t& int2::operator[]( const uint32_t index )
{
	assert( index < 2 );
	return data[index];
}

bool operator==( const int2& lhs, const int2& rhs )
{
	return ( lhs.x == rhs.x ) && ( lhs.y == rhs.y );
}

bool operator!=( const int2& lhs, const int2& rhs )
{
	return !( operator==( lhs, rhs ) );
}


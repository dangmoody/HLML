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
#include "bool3.h"
#include "bool4.h"

#include "../hlml_main.h"

// others
#include <math.h>
#include <memory.h>
#include <assert.h>

bool2::bool2()
{
	memset( data, 0, 2 * sizeof( bool ) );
}

bool2::bool2( const bool x )
{
	this->x = this->y = x;
}

bool2::bool2( const bool x, const bool y )
{
	this->x = x;
	this->y = y;
}

bool2::bool2( const bool2& other )
{
	memcpy( data, other.data, sizeof( other.data ) );
}

bool2::bool2( const bool3& other )
{
	memcpy( data, other.data, sizeof( other.data ) );
}

bool2::bool2( const bool4& other )
{
	memcpy( data, other.data, sizeof( other.data ) );
}

bool2 bool2::operator=( const bool2& rhs )
{
	memcpy( data, rhs.data, sizeof( rhs.data ) );
	return *this;
}

bool2 bool2::operator=( const bool3& rhs )
{
	memcpy( data, rhs.data, sizeof( rhs.data ) );
	return *this;
}

bool2 bool2::operator=( const bool4& rhs )
{
	memcpy( data, rhs.data, sizeof( rhs.data ) );
	return *this;
}

const bool& bool2::operator[]( const uint32_t index ) const
{
	assert( index < 2 );
	return data[index];
}

bool& bool2::operator[]( const uint32_t index )
{
	assert( index < 2 );
	return data[index];
}

bool operator==( const bool2& lhs, const bool2& rhs )
{
	return ( lhs.x == rhs.x ) && ( lhs.y == rhs.y );
}

bool operator!=( const bool2& lhs, const bool2& rhs ) {
	return !( operator==( lhs, rhs ) );
}


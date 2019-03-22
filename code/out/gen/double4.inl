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
#include "double2.h"
#include "double3.h"

#include "../hlml_main.h"

// others
#include <math.h>
#include <memory.h>
#include <assert.h>

double4::double4()
{
	memset( data, 0, 4 * sizeof( double ) );
}

double4::double4( const double x )
{
	this->x = this->y = this->z = this->w = x;
}

double4::double4( const double x, const double y, const double z, const double w )
{
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = w;
}

double4::double4( const double2& other )
{
	memcpy( data, other.data, sizeof( other.data ) );
}

double4::double4( const double3& other )
{
	memcpy( data, other.data, sizeof( other.data ) );
}

double4::double4( const double4& other )
{
	memcpy( data, other.data, sizeof( other.data ) );
}

double4 double4::operator=( const double2& rhs )
{
	memcpy( data, rhs.data, sizeof( rhs.data ) );
	return *this;
}

double4 double4::operator=( const double3& rhs )
{
	memcpy( data, rhs.data, sizeof( rhs.data ) );
	return *this;
}

double4 double4::operator=( const double4& rhs )
{
	memcpy( data, rhs.data, sizeof( rhs.data ) );
	return *this;
}

const double& double4::operator[]( const uint32_t index ) const
{
	assert( index < 4 );
	return data[index];
}

double& double4::operator[]( const uint32_t index )
{
	assert( index < 4 );
	return data[index];
}

bool operator==( const double4& lhs, const double4& rhs )
{
	return doubleeq( lhs.x, rhs. x ) && doubleeq( lhs.y, rhs. y ) && doubleeq( lhs.z, rhs. z ) && doubleeq( lhs.w, rhs. w );
}

bool operator!=( const double4& lhs, const double4& rhs ) {
	return !( operator==( lhs, rhs ) );
}


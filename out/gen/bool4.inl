/*
===========================================================================

hlml.
Copyright (c) Dan Moody 2018 - Present.

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
#include "bool2.h"
#include "bool3.h"

#include "../hlml_main.h"

// others
#include <math.h>

bool4::bool4() {
	memset( data, 0, 4 * sizeof( bool ) );
}

bool4::bool4( const bool x ) {
	this->x = this->y = this->z = this->w = x;
}

bool4::bool4( const bool x, const bool y, const bool z, const bool w ) {
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = w;
}

bool4::bool4( const bool2& other ) {
	memcpy( data, other.data, sizeof( other.data ) );
}

bool4::bool4( const bool3& other ) {
	memcpy( data, other.data, sizeof( other.data ) );
}

bool4::bool4( const bool4& other ) {
	memcpy( data, other.data, sizeof( other.data ) );
}

bool4 bool4::operator=( const bool2& rhs ) {
	memcpy( data, rhs.data, sizeof( rhs.data ) );
	return *this;
}

bool4 bool4::operator=( const bool3& rhs ) {
	memcpy( data, rhs.data, sizeof( rhs.data ) );
	return *this;
}

bool4 bool4::operator=( const bool4& rhs ) {
	memcpy( data, rhs.data, sizeof( rhs.data ) );
	return *this;
}

const bool& bool4::operator[]( const uint32_t index ) const {
	assert( index < 4 );
	return data[index];
}

bool& bool4::operator[]( const uint32_t index ) {
	assert( index < 4 );
	return data[index];
}

bool operator==( const bool4& lhs, const bool4& rhs ) {
	return floateq( lhs.x, rhs. x ) && floateq( lhs.y, rhs. y ) && floateq( lhs.z, rhs. z ) && floateq( lhs.w, rhs. w );
}

bool operator!=( const bool4& lhs, const bool4& rhs ) {
	return !( operator==( lhs, rhs ) );
}


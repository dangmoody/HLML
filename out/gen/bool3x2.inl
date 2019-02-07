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
#include "../hlml_main.h"

// others
#include <math.h>

bool3x2::bool3x2() {
	rows[0] = { 1, 0 };
	rows[1] = { 0, 1 };
	rows[2] = { 0, 0 };
}

bool3x2::bool3x2( const bool diagonal ) {
	rows[0] = { diagonal, 0 };
	rows[1] = { 0, diagonal };
	rows[2] = { 0, 0 };
}

bool3x2::bool3x2( const bool2& diagonal ) {
	rows[0] = { diagonal.x, 0 };
	rows[1] = { 0, diagonal.y };
	rows[2] = { 0, 0 };
}

bool3x2::bool3x2( const bool2& row0, const bool2& row1, const bool2& row2 ) {
	rows[0] = row0;
	rows[1] = row1;
	rows[2] = row2;
}

bool3x2::bool3x2( const bool2 rows[3] ) {
	this->rows[0] = rows[0];
	this->rows[1] = rows[1];
	this->rows[2] = rows[2];
}

bool3x2::bool3x2( const bool m00, const bool m01, const bool m10, const bool m11, const bool m20, const bool m21 ) {
	rows[0] = { m00, m01 };
	rows[1] = { m10, m11 };
	rows[2] = { m20, m21 };
}

bool3x2::bool3x2( const bool3x2& other ) {
	memcpy( rows, other.rows, sizeof( rows ) );
};

bool3x2 bool3x2::operator=( const bool3x2& other ) {
	memcpy( rows, other.rows, sizeof( rows ) );
	return *this;
};

bool2& bool3x2::operator[]( const uint32_t index ) {
	assert( index < 3 );
	return rows[index];
}

const bool2& bool3x2::operator[]( const uint32_t index ) const {
	assert( index < 3 );
	return rows[index];
}

bool operator==( const bool3x2& lhs, const bool3x2& rhs ) {
	return lhs.rows[0] == rhs.rows[0]
		&& lhs.rows[1] == rhs.rows[1]
		&& lhs.rows[2] == rhs.rows[2];
}

bool operator!=( const bool3x2& lhs, const bool3x2& rhs ) {
	return !( operator==( lhs, rhs ) );
}



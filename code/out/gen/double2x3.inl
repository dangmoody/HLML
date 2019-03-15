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
#include "../hlml_main.h"

// others
#include <math.h>

// forward declares
double2x3 inverse( const double2x3& mat );

double2x3::double2x3() {
	rows[0] = { 1, 0, 0 };
	rows[1] = { 0, 1, 0 };
}

double2x3::double2x3( const double diagonal ) {
	rows[0] = { diagonal, 0, 0 };
	rows[1] = { 0, diagonal, 0 };
}

double2x3::double2x3( const double3& diagonal ) {
	rows[0] = { diagonal.x, 0, 0 };
	rows[1] = { 0, diagonal.y, 0 };
}

double2x3::double2x3( const double3& row0, const double3& row1 ) {
	rows[0] = row0;
	rows[1] = row1;
}

double2x3::double2x3( const double3 rows[2] ) {
	this->rows[0] = rows[0];
	this->rows[1] = rows[1];
}

double2x3::double2x3( const double m00, const double m01, const double m02, const double m10, const double m11, const double m12 ) {
	rows[0] = { m00, m01, m02 };
	rows[1] = { m10, m11, m12 };
}

double2x3::double2x3( const double2x3& other ) {
	memcpy( rows, other.rows, sizeof( rows ) );
};

double2x3 double2x3::operator=( const double2x3& other ) {
	memcpy( rows, other.rows, sizeof( rows ) );
	return *this;
};

double3& double2x3::operator[]( const uint32_t index ) {
	assert( index < 2 );
	return rows[index];
}

const double3& double2x3::operator[]( const uint32_t index ) const {
	assert( index < 2 );
	return rows[index];
}

bool operator==( const double2x3& lhs, const double2x3& rhs ) {
	return lhs[0] == rhs[0]
		&& lhs[1] == rhs[1];
}

bool operator!=( const double2x3& lhs, const double2x3& rhs ) {
	return !( operator==( lhs, rhs ) );
}


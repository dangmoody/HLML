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
double2x2 inverse( const double2x2& mat );

double2x2::double2x2() {
	rows[0] = { 1, 0 };
	rows[1] = { 0, 1 };
}

double2x2::double2x2( const double diagonal ) {
	rows[0] = { diagonal, 0 };
	rows[1] = { 0, diagonal };
}

double2x2::double2x2( const double2& diagonal ) {
	rows[0] = { diagonal.x, 0 };
	rows[1] = { 0, diagonal.y };
}

double2x2::double2x2( const double2& row0, const double2& row1 ) {
	rows[0] = row0;
	rows[1] = row1;
}

double2x2::double2x2( const double2 rows[2] ) {
	this->rows[0] = rows[0];
	this->rows[1] = rows[1];
}

double2x2::double2x2( const double m00, const double m01, const double m10, const double m11 ) {
	rows[0] = { m00, m01 };
	rows[1] = { m10, m11 };
}

double2x2::double2x2( const double2x2& other ) {
	memcpy( rows, other.rows, sizeof( rows ) );
};

double2x2 double2x2::operator=( const double2x2& other ) {
	memcpy( rows, other.rows, sizeof( rows ) );
	return *this;
};

double2x2 double2x2::operator+( const double rhs ) const {
	return double2x2(
		rows[0] + rhs,
		rows[1] + rhs
	);
}

double2x2 double2x2::operator+=( const double rhs ) {
	return ( *this = *this + rhs );
}

double2x2 double2x2::operator+( const double2x2& rhs ) const {
	return double2x2(
		rows[0] + rhs[0],
		rows[1] + rhs[1]
	);
}

double2x2 double2x2::operator+=( const double2x2& rhs ) {
	return ( *this = *this + rhs );
}

double2x2 double2x2::operator-( const double rhs ) const {
	return double2x2(
		rows[0] - rhs,
		rows[1] - rhs
	);
}

double2x2 double2x2::operator-=( const double rhs ) {
	return ( *this = *this - rhs );
}

double2x2 double2x2::operator-( const double2x2& rhs ) const {
	return double2x2(
		rows[0] - rhs[0],
		rows[1] - rhs[1]
	);
}

double2x2 double2x2::operator-=( const double2x2& rhs ) {
	return ( *this = *this - rhs );
}

double2x2 double2x2::operator*( const double rhs ) const {
	return double2x2(
		rows[0] * rhs,
		rows[1] * rhs
	);
}

double2x2 double2x2::operator*=( const double rhs ) {
	return ( *this = *this * rhs );
}

double2x2 double2x2::operator*( const double2x2& rhs ) const {
	double2 row0 = rows[0];
	double2 row1 = rows[1];

	double2 col0 = { rhs[0].x, rhs[1].x };
	double2 col1 = { rhs[0].y, rhs[1].y };

	return double2x2(
		row0.x * col0.x + row0.y * col0.y,
		row0.x * col1.x + row0.y * col1.y,

		row1.x * col0.x + row1.y * col0.y,
		row1.x * col1.x + row1.y * col1.y
	);
}

double2x2 double2x2::operator*=( const double2x2& rhs ) {
	return ( *this = *this * rhs );
}

double2x2 double2x2::operator/( const double rhs ) const {
	return double2x2(
		rows[0] / rhs,
		rows[1] / rhs
	);
}

double2x2 double2x2::operator/=( const double rhs ) {
	return ( *this = *this / rhs );
}

double2x2 double2x2::operator/( const double2x2& rhs ) const {
	return *this * inverse( rhs );
}

double2x2 double2x2::operator/=( const double2x2& rhs ) {
	return ( *this = *this / rhs );
}

double2& double2x2::operator[]( const uint32_t index ) {
	assert( index < 2 );
	return rows[index];
}

const double2& double2x2::operator[]( const uint32_t index ) const {
	assert( index < 2 );
	return rows[index];
}

bool operator==( const double2x2& lhs, const double2x2& rhs ) {
	return lhs[0] == rhs[0]
		&& lhs[1] == rhs[1];
}

bool operator!=( const double2x2& lhs, const double2x2& rhs ) {
	return !( operator==( lhs, rhs ) );
}

bool2x2 operator<( const double2x2& lhs, const double2x2& rhs ) {
	return bool2x2(
		lhs[0] < rhs[0],
		lhs[1] < rhs[1]
	);
}

bool2x2 operator<=( const double2x2& lhs, const double2x2& rhs ) {
	return bool2x2(
		lhs[0] <= rhs[0],
		lhs[1] <= rhs[1]
	);
}

bool2x2 operator>( const double2x2& lhs, const double2x2& rhs ) {
	return bool2x2(
		lhs[0] > rhs[0],
		lhs[1] > rhs[1]
	);
}

bool2x2 operator>=( const double2x2& lhs, const double2x2& rhs ) {
	return bool2x2(
		lhs[0] >= rhs[0],
		lhs[1] >= rhs[1]
	);
}


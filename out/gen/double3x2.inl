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
double3x2 inverse( const double3x2& mat );

double3x2::double3x2() {
	rows[0] = { 1, 0 };
	rows[1] = { 0, 1 };
	rows[2] = { 0, 0 };
}

double3x2::double3x2( const double diagonal ) {
	rows[0] = { diagonal, 0 };
	rows[1] = { 0, diagonal };
	rows[2] = { 0, 0 };
}

double3x2::double3x2( const double2& diagonal ) {
	rows[0] = { diagonal.x, 0 };
	rows[1] = { 0, diagonal.y };
	rows[2] = { 0, 0 };
}

double3x2::double3x2( const double2& row0, const double2& row1, const double2& row2 ) {
	rows[0] = row0;
	rows[1] = row1;
	rows[2] = row2;
}

double3x2::double3x2( const double2 rows[3] ) {
	this->rows[0] = rows[0];
	this->rows[1] = rows[1];
	this->rows[2] = rows[2];
}

double3x2::double3x2( const double m00, const double m01, const double m10, const double m11, const double m20, const double m21 ) {
	rows[0] = { m00, m01 };
	rows[1] = { m10, m11 };
	rows[2] = { m20, m21 };
}

double3x2::double3x2( const double3x2& other ) {
	memcpy( rows, other.rows, sizeof( rows ) );
};

double3x2 double3x2::operator=( const double3x2& other ) {
	memcpy( rows, other.rows, sizeof( rows ) );
	return *this;
};

double3x2 double3x2::operator+( const double rhs ) const {
	return double3x2(
		rows[0] + rhs,
		rows[1] + rhs,
		rows[2] + rhs
	);
}

double3x2 double3x2::operator+=( const double rhs ) {
	return ( *this = *this + rhs );
}

double3x2 double3x2::operator+( const double3x2& rhs ) const {
	return double3x2(
		rows[0] + rhs[0],
		rows[1] + rhs[1],
		rows[2] + rhs[2]
	);
}

double3x2 double3x2::operator+=( const double3x2& rhs ) {
	return ( *this = *this + rhs );
}

double3x2 double3x2::operator-( const double rhs ) const {
	return double3x2(
		rows[0] - rhs,
		rows[1] - rhs,
		rows[2] - rhs
	);
}

double3x2 double3x2::operator-=( const double rhs ) {
	return ( *this = *this - rhs );
}

double3x2 double3x2::operator-( const double3x2& rhs ) const {
	return double3x2(
		rows[0] - rhs[0],
		rows[1] - rhs[1],
		rows[2] - rhs[2]
	);
}

double3x2 double3x2::operator-=( const double3x2& rhs ) {
	return ( *this = *this - rhs );
}

double3x2 double3x2::operator*( const double rhs ) const {
	return double3x2(
		rows[0] * rhs,
		rows[1] * rhs,
		rows[2] * rhs
	);
}

double3x2 double3x2::operator*=( const double rhs ) {
	return ( *this = *this * rhs );
}

double3x2 double3x2::operator*( const double3x2& rhs ) const {
	double3 row0 = rows[0];
	double3 row1 = rows[1];
	double3 row2 = rows[2];

	double3 col0 = { rhs[0].x, rhs[1].x, rhs[2].x };
	double3 col1 = { rhs[0].y, rhs[1].y, rhs[2].y };

	return double3x2(
		row0.x * col0.x + row0.y * col0.y + row0.z * col0.z,
		row0.x * col1.x + row0.y * col1.y + row0.z * col1.z,

		row1.x * col0.x + row1.y * col0.y + row1.z * col0.z,
		row1.x * col1.x + row1.y * col1.y + row1.z * col1.z,

		row2.x * col0.x + row2.y * col0.y + row2.z * col0.z,
		row2.x * col1.x + row2.y * col1.y + row2.z * col1.z
	);
}

double3x2 double3x2::operator*=( const double3x2& rhs ) {
	return ( *this = *this * rhs );
}

double3x2 double3x2::operator/( const double rhs ) const {
	return double3x2(
		rows[0] / rhs,
		rows[1] / rhs,
		rows[2] / rhs
	);
}

double3x2 double3x2::operator/=( const double rhs ) {
	return ( *this = *this / rhs );
}

double3x2 double3x2::operator/( const double3x2& rhs ) const {
	return *this * inverse( rhs );
}

double3x2 double3x2::operator/=( const double3x2& rhs ) {
	return ( *this = *this / rhs );
}

double2& double3x2::operator[]( const uint32_t index ) {
	assert( index < 3 );
	return rows[index];
}

const double2& double3x2::operator[]( const uint32_t index ) const {
	assert( index < 3 );
	return rows[index];
}

bool operator==( const double3x2& lhs, const double3x2& rhs ) {
	return lhs[0] == rhs[0]
		&& lhs[1] == rhs[1]
		&& lhs[2] == rhs[2];
}

bool operator!=( const double3x2& lhs, const double3x2& rhs ) {
	return !( operator==( lhs, rhs ) );
}

bool3x2 operator<( const double3x2& lhs, const double3x2& rhs ) {
	return bool3x2(
		lhs[0] < rhs[0],
		lhs[1] < rhs[1],
		lhs[2] < rhs[2]
	);
}

bool3x2 operator<=( const double3x2& lhs, const double3x2& rhs ) {
	return bool3x2(
		lhs[0] <= rhs[0],
		lhs[1] <= rhs[1],
		lhs[2] <= rhs[2]
	);
}

bool3x2 operator>( const double3x2& lhs, const double3x2& rhs ) {
	return bool3x2(
		lhs[0] > rhs[0],
		lhs[1] > rhs[1],
		lhs[2] > rhs[2]
	);
}

bool3x2 operator>=( const double3x2& lhs, const double3x2& rhs ) {
	return bool3x2(
		lhs[0] >= rhs[0],
		lhs[1] >= rhs[1],
		lhs[2] >= rhs[2]
	);
}


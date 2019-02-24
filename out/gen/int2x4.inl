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
int2x4 inverse( const int2x4& mat );

int2x4::int2x4() {
	rows[0] = { 1, 0, 0, 0 };
	rows[1] = { 0, 1, 0, 0 };
}

int2x4::int2x4( const int32_t diagonal ) {
	rows[0] = { diagonal, 0, 0, 0 };
	rows[1] = { 0, diagonal, 0, 0 };
}

int2x4::int2x4( const int4& diagonal ) {
	rows[0] = { diagonal.x, 0, 0, 0 };
	rows[1] = { 0, diagonal.y, 0, 0 };
}

int2x4::int2x4( const int4& row0, const int4& row1 ) {
	rows[0] = row0;
	rows[1] = row1;
}

int2x4::int2x4( const int4 rows[2] ) {
	this->rows[0] = rows[0];
	this->rows[1] = rows[1];
}

int2x4::int2x4( const int32_t m00, const int32_t m01, const int32_t m02, const int32_t m03, const int32_t m10, const int32_t m11, const int32_t m12, const int32_t m13 ) {
	rows[0] = { m00, m01, m02, m03 };
	rows[1] = { m10, m11, m12, m13 };
}

int2x4::int2x4( const int2x4& other ) {
	memcpy( rows, other.rows, sizeof( rows ) );
};

int2x4 int2x4::operator=( const int2x4& other ) {
	memcpy( rows, other.rows, sizeof( rows ) );
	return *this;
};

int2x4 int2x4::operator+( const int32_t rhs ) const {
	return int2x4(
		rows[0] + rhs,
		rows[1] + rhs
	);
}

int2x4 int2x4::operator+=( const int32_t rhs ) {
	return ( *this = *this + rhs );
}

int2x4 int2x4::operator+( const int2x4& rhs ) const {
	return int2x4(
		rows[0] + rhs[0],
		rows[1] + rhs[1]
	);
}

int2x4 int2x4::operator+=( const int2x4& rhs ) {
	return ( *this = *this + rhs );
}

int2x4 int2x4::operator-( const int32_t rhs ) const {
	return int2x4(
		rows[0] - rhs,
		rows[1] - rhs
	);
}

int2x4 int2x4::operator-=( const int32_t rhs ) {
	return ( *this = *this - rhs );
}

int2x4 int2x4::operator-( const int2x4& rhs ) const {
	return int2x4(
		rows[0] - rhs[0],
		rows[1] - rhs[1]
	);
}

int2x4 int2x4::operator-=( const int2x4& rhs ) {
	return ( *this = *this - rhs );
}

int2x4 int2x4::operator*( const int32_t rhs ) const {
	return int2x4(
		rows[0] * rhs,
		rows[1] * rhs
	);
}

int2x4 int2x4::operator*=( const int32_t rhs ) {
	return ( *this = *this * rhs );
}

int2x4 int2x4::operator*( const int2x4& rhs ) const {
	int2 row0 = rows[0];
	int2 row1 = rows[1];

	int2 col0 = { rhs[0].x, rhs[1].x };
	int2 col1 = { rhs[0].y, rhs[1].y };
	int2 col2 = { rhs[0].z, rhs[1].z };
	int2 col3 = { rhs[0].w, rhs[1].w };

	return int2x4(
		row0.x * col0.x + row0.y * col0.y,
		row0.x * col1.x + row0.y * col1.y,
		row0.x * col2.x + row0.y * col2.y,
		row0.x * col3.x + row0.y * col3.y,

		row1.x * col0.x + row1.y * col0.y,
		row1.x * col1.x + row1.y * col1.y,
		row1.x * col2.x + row1.y * col2.y,
		row1.x * col3.x + row1.y * col3.y
	);
}

int2x4 int2x4::operator*=( const int2x4& rhs ) {
	return ( *this = *this * rhs );
}

int2x4 int2x4::operator/( const int32_t rhs ) const {
	return int2x4(
		rows[0] / rhs,
		rows[1] / rhs
	);
}

int2x4 int2x4::operator/=( const int32_t rhs ) {
	return ( *this = *this / rhs );
}

int2x4 int2x4::operator/( const int2x4& rhs ) const {
	return int2x4(
		rows[0] / rhs[0],
		rows[1] / rhs[1]
	);
}

int2x4 int2x4::operator/=( const int2x4& rhs ) {
	return ( *this = *this / rhs );
}

int4& int2x4::operator[]( const uint32_t index ) {
	assert( index < 2 );
	return rows[index];
}

const int4& int2x4::operator[]( const uint32_t index ) const {
	assert( index < 2 );
	return rows[index];
}

bool operator==( const int2x4& lhs, const int2x4& rhs ) {
	return lhs[0] == rhs[0]
		&& lhs[1] == rhs[1];
}

bool operator!=( const int2x4& lhs, const int2x4& rhs ) {
	return !( operator==( lhs, rhs ) );
}

bool2x4 operator<( const int2x4& lhs, const int2x4& rhs ) {
	return bool2x4(
		lhs[0] < rhs[0],
		lhs[1] < rhs[1]
	);
}

bool2x4 operator<=( const int2x4& lhs, const int2x4& rhs ) {
	return bool2x4(
		lhs[0] <= rhs[0],
		lhs[1] <= rhs[1]
	);
}

bool2x4 operator>( const int2x4& lhs, const int2x4& rhs ) {
	return bool2x4(
		lhs[0] > rhs[0],
		lhs[1] > rhs[1]
	);
}

bool2x4 operator>=( const int2x4& lhs, const int2x4& rhs ) {
	return bool2x4(
		lhs[0] >= rhs[0],
		lhs[1] >= rhs[1]
	);
}


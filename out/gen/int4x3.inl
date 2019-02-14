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
int4x3 inverse( const int4x3& mat );

int4x3::int4x3() {
	rows[0] = { 1, 0, 0 };
	rows[1] = { 0, 1, 0 };
	rows[2] = { 0, 0, 1 };
	rows[3] = { 0, 0, 0 };
}

int4x3::int4x3( const int32_t diagonal ) {
	rows[0] = { diagonal, 0, 0 };
	rows[1] = { 0, diagonal, 0 };
	rows[2] = { 0, 0, diagonal };
	rows[3] = { 0, 0, 0 };
}

int4x3::int4x3( const int3& diagonal ) {
	rows[0] = { diagonal.x, 0, 0 };
	rows[1] = { 0, diagonal.y, 0 };
	rows[2] = { 0, 0, diagonal.z };
	rows[3] = { 0, 0, 0 };
}

int4x3::int4x3( const int3& row0, const int3& row1, const int3& row2, const int3& row3 ) {
	rows[0] = row0;
	rows[1] = row1;
	rows[2] = row2;
	rows[3] = row3;
}

int4x3::int4x3( const int3 rows[4] ) {
	this->rows[0] = rows[0];
	this->rows[1] = rows[1];
	this->rows[2] = rows[2];
	this->rows[3] = rows[3];
}

int4x3::int4x3( const int32_t m00, const int32_t m01, const int32_t m02, const int32_t m10, const int32_t m11, const int32_t m12, const int32_t m20, const int32_t m21, const int32_t m22, const int32_t m30, const int32_t m31, const int32_t m32 ) {
	rows[0] = { m00, m01, m02 };
	rows[1] = { m10, m11, m12 };
	rows[2] = { m20, m21, m22 };
	rows[3] = { m30, m31, m32 };
}

int4x3::int4x3( const int4x3& other ) {
	memcpy( rows, other.rows, sizeof( rows ) );
};

int4x3 int4x3::operator=( const int4x3& other ) {
	memcpy( rows, other.rows, sizeof( rows ) );
	return *this;
};

int4x3 int4x3::operator+( const int32_t rhs ) const {
	return int4x3(
		rows[0] + rhs,
		rows[1] + rhs,
		rows[2] + rhs,
		rows[3] + rhs
	);
}

int4x3 int4x3::operator+=( const int32_t rhs ) {
	return ( *this = *this + rhs );
}

int4x3 int4x3::operator+( const int4x3& rhs ) const {
	return int4x3(
		rows[0] + rhs.rows[0],
		rows[1] + rhs.rows[1],
		rows[2] + rhs.rows[2],
		rows[3] + rhs.rows[3]
	);
}

int4x3 int4x3::operator+=( const int4x3& rhs ) {
	return ( *this = *this + rhs );
}

int4x3 int4x3::operator-( const int32_t rhs ) const {
	return int4x3(
		rows[0] - rhs,
		rows[1] - rhs,
		rows[2] - rhs,
		rows[3] - rhs
	);
}

int4x3 int4x3::operator-=( const int32_t rhs ) {
	return ( *this = *this - rhs );
}

int4x3 int4x3::operator-( const int4x3& rhs ) const {
	return int4x3(
		rows[0] - rhs.rows[0],
		rows[1] - rhs.rows[1],
		rows[2] - rhs.rows[2],
		rows[3] - rhs.rows[3]
	);
}

int4x3 int4x3::operator-=( const int4x3& rhs ) {
	return ( *this = *this - rhs );
}

int4x3 int4x3::operator*( const int32_t rhs ) const {
	return int4x3(
		rows[0] * rhs,
		rows[1] * rhs,
		rows[2] * rhs,
		rows[3] * rhs
	);
}

int4x3 int4x3::operator*=( const int32_t rhs ) {
	return ( *this = *this * rhs );
}

int4x3 int4x3::operator*( const int4x3& rhs ) const {
	int4 row0 = rows[0];
	int4 row1 = rows[1];
	int4 row2 = rows[2];
	int4 row3 = rows[3];

	int4 col0 = { rhs.rows[0].x, rhs.rows[1].x, rhs.rows[2].x, rhs.rows[3].x };
	int4 col1 = { rhs.rows[0].y, rhs.rows[1].y, rhs.rows[2].y, rhs.rows[3].y };
	int4 col2 = { rhs.rows[0].z, rhs.rows[1].z, rhs.rows[2].z, rhs.rows[3].z };

	return int4x3(
		row0.x * col0.x + row0.y * col0.y + row0.z * col0.z + row0.w * col0.w,
		row0.x * col1.x + row0.y * col1.y + row0.z * col1.z + row0.w * col1.w,
		row0.x * col2.x + row0.y * col2.y + row0.z * col2.z + row0.w * col2.w,

		row1.x * col0.x + row1.y * col0.y + row1.z * col0.z + row1.w * col0.w,
		row1.x * col1.x + row1.y * col1.y + row1.z * col1.z + row1.w * col1.w,
		row1.x * col2.x + row1.y * col2.y + row1.z * col2.z + row1.w * col2.w,

		row2.x * col0.x + row2.y * col0.y + row2.z * col0.z + row2.w * col0.w,
		row2.x * col1.x + row2.y * col1.y + row2.z * col1.z + row2.w * col1.w,
		row2.x * col2.x + row2.y * col2.y + row2.z * col2.z + row2.w * col2.w,

		row3.x * col0.x + row3.y * col0.y + row3.z * col0.z + row3.w * col0.w,
		row3.x * col1.x + row3.y * col1.y + row3.z * col1.z + row3.w * col1.w,
		row3.x * col2.x + row3.y * col2.y + row3.z * col2.z + row3.w * col2.w
	);
}

int4x3 int4x3::operator*=( const int4x3& rhs ) {
	return ( *this = *this * rhs );
}

int4x3 int4x3::operator/( const int32_t rhs ) const {
	return int4x3(
		rows[0] / rhs,
		rows[1] / rhs,
		rows[2] / rhs,
		rows[3] / rhs
	);
}

int4x3 int4x3::operator/=( const int32_t rhs ) {
	return ( *this = *this / rhs );
}

int4x3 int4x3::operator/( const int4x3& rhs ) const {
	return *this * inverse( rhs );
}

int4x3 int4x3::operator/=( const int4x3& rhs ) {
	return ( *this = *this / rhs );
}

int3& int4x3::operator[]( const uint32_t index ) {
	assert( index < 4 );
	return rows[index];
}

const int3& int4x3::operator[]( const uint32_t index ) const {
	assert( index < 4 );
	return rows[index];
}

bool operator==( const int4x3& lhs, const int4x3& rhs ) {
	return lhs.rows[0] == rhs.rows[0]
		&& lhs.rows[1] == rhs.rows[1]
		&& lhs.rows[2] == rhs.rows[2]
		&& lhs.rows[3] == rhs.rows[3];
}

bool operator!=( const int4x3& lhs, const int4x3& rhs ) {
	return !( operator==( lhs, rhs ) );
}



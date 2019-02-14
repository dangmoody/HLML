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
uint3x4 inverse( const uint3x4& mat );

uint3x4::uint3x4() {
	rows[0] = { 1, 0, 0, 0 };
	rows[1] = { 0, 1, 0, 0 };
	rows[2] = { 0, 0, 1, 0 };
}

uint3x4::uint3x4( const uint32_t diagonal ) {
	rows[0] = { diagonal, 0, 0, 0 };
	rows[1] = { 0, diagonal, 0, 0 };
	rows[2] = { 0, 0, diagonal, 0 };
}

uint3x4::uint3x4( const uint4& diagonal ) {
	rows[0] = { diagonal.x, 0, 0, 0 };
	rows[1] = { 0, diagonal.y, 0, 0 };
	rows[2] = { 0, 0, diagonal.z, 0 };
}

uint3x4::uint3x4( const uint4& row0, const uint4& row1, const uint4& row2 ) {
	rows[0] = row0;
	rows[1] = row1;
	rows[2] = row2;
}

uint3x4::uint3x4( const uint4 rows[3] ) {
	this->rows[0] = rows[0];
	this->rows[1] = rows[1];
	this->rows[2] = rows[2];
}

uint3x4::uint3x4( const uint32_t m00, const uint32_t m01, const uint32_t m02, const uint32_t m03, const uint32_t m10, const uint32_t m11, const uint32_t m12, const uint32_t m13, const uint32_t m20, const uint32_t m21, const uint32_t m22, const uint32_t m23 ) {
	rows[0] = { m00, m01, m02, m03 };
	rows[1] = { m10, m11, m12, m13 };
	rows[2] = { m20, m21, m22, m23 };
}

uint3x4::uint3x4( const uint3x4& other ) {
	memcpy( rows, other.rows, sizeof( rows ) );
};

uint3x4 uint3x4::operator=( const uint3x4& other ) {
	memcpy( rows, other.rows, sizeof( rows ) );
	return *this;
};

uint3x4 uint3x4::operator+( const uint32_t rhs ) const {
	return uint3x4(
		rows[0] + rhs,
		rows[1] + rhs,
		rows[2] + rhs
	);
}

uint3x4 uint3x4::operator+=( const uint32_t rhs ) {
	return ( *this = *this + rhs );
}

uint3x4 uint3x4::operator+( const uint3x4& rhs ) const {
	return uint3x4(
		rows[0] + rhs.rows[0],
		rows[1] + rhs.rows[1],
		rows[2] + rhs.rows[2]
	);
}

uint3x4 uint3x4::operator+=( const uint3x4& rhs ) {
	return ( *this = *this + rhs );
}

uint3x4 uint3x4::operator-( const uint32_t rhs ) const {
	return uint3x4(
		rows[0] - rhs,
		rows[1] - rhs,
		rows[2] - rhs
	);
}

uint3x4 uint3x4::operator-=( const uint32_t rhs ) {
	return ( *this = *this - rhs );
}

uint3x4 uint3x4::operator-( const uint3x4& rhs ) const {
	return uint3x4(
		rows[0] - rhs.rows[0],
		rows[1] - rhs.rows[1],
		rows[2] - rhs.rows[2]
	);
}

uint3x4 uint3x4::operator-=( const uint3x4& rhs ) {
	return ( *this = *this - rhs );
}

uint3x4 uint3x4::operator*( const uint32_t rhs ) const {
	return uint3x4(
		rows[0] * rhs,
		rows[1] * rhs,
		rows[2] * rhs
	);
}

uint3x4 uint3x4::operator*=( const uint32_t rhs ) {
	return ( *this = *this * rhs );
}

uint3x4 uint3x4::operator*( const uint3x4& rhs ) const {
	uint3 row0 = rows[0];
	uint3 row1 = rows[1];
	uint3 row2 = rows[2];

	uint3 col0 = { rhs.rows[0].x, rhs.rows[1].x, rhs.rows[2].x };
	uint3 col1 = { rhs.rows[0].y, rhs.rows[1].y, rhs.rows[2].y };
	uint3 col2 = { rhs.rows[0].z, rhs.rows[1].z, rhs.rows[2].z };
	uint3 col3 = { rhs.rows[0].w, rhs.rows[1].w, rhs.rows[2].w };

	return uint3x4(
		row0.x * col0.x + row0.y * col0.y + row0.z * col0.z,
		row0.x * col1.x + row0.y * col1.y + row0.z * col1.z,
		row0.x * col2.x + row0.y * col2.y + row0.z * col2.z,
		row0.x * col3.x + row0.y * col3.y + row0.z * col3.z,

		row1.x * col0.x + row1.y * col0.y + row1.z * col0.z,
		row1.x * col1.x + row1.y * col1.y + row1.z * col1.z,
		row1.x * col2.x + row1.y * col2.y + row1.z * col2.z,
		row1.x * col3.x + row1.y * col3.y + row1.z * col3.z,

		row2.x * col0.x + row2.y * col0.y + row2.z * col0.z,
		row2.x * col1.x + row2.y * col1.y + row2.z * col1.z,
		row2.x * col2.x + row2.y * col2.y + row2.z * col2.z,
		row2.x * col3.x + row2.y * col3.y + row2.z * col3.z
	);
}

uint3x4 uint3x4::operator*=( const uint3x4& rhs ) {
	return ( *this = *this * rhs );
}

uint3x4 uint3x4::operator/( const uint32_t rhs ) const {
	return uint3x4(
		rows[0] / rhs,
		rows[1] / rhs,
		rows[2] / rhs
	);
}

uint3x4 uint3x4::operator/=( const uint32_t rhs ) {
	return ( *this = *this / rhs );
}

uint3x4 uint3x4::operator/( const uint3x4& rhs ) const {
	return *this * inverse( rhs );
}

uint3x4 uint3x4::operator/=( const uint3x4& rhs ) {
	return ( *this = *this / rhs );
}

uint4& uint3x4::operator[]( const uint32_t index ) {
	assert( index < 3 );
	return rows[index];
}

const uint4& uint3x4::operator[]( const uint32_t index ) const {
	assert( index < 3 );
	return rows[index];
}

bool operator==( const uint3x4& lhs, const uint3x4& rhs ) {
	return lhs.rows[0] == rhs.rows[0]
		&& lhs.rows[1] == rhs.rows[1]
		&& lhs.rows[2] == rhs.rows[2];
}

bool operator!=( const uint3x4& lhs, const uint3x4& rhs ) {
	return !( operator==( lhs, rhs ) );
}



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
uint2x2 inverse( const uint2x2& mat );

uint2x2::uint2x2() {
	rows[0] = { 1, 0 };
	rows[1] = { 0, 1 };
}

uint2x2::uint2x2( const uint32_t diagonal ) {
	rows[0] = { diagonal, 0 };
	rows[1] = { 0, diagonal };
}

uint2x2::uint2x2( const uint2& diagonal ) {
	rows[0] = { diagonal.x, 0 };
	rows[1] = { 0, diagonal.y };
}

uint2x2::uint2x2( const uint2& row0, const uint2& row1 ) {
	rows[0] = row0;
	rows[1] = row1;
}

uint2x2::uint2x2( const uint2 rows[2] ) {
	this->rows[0] = rows[0];
	this->rows[1] = rows[1];
}

uint2x2::uint2x2( const uint32_t m00, const uint32_t m01, const uint32_t m10, const uint32_t m11 ) {
	rows[0] = { m00, m01 };
	rows[1] = { m10, m11 };
}

uint2x2::uint2x2( const uint2x2& other ) {
	memcpy( rows, other.rows, sizeof( rows ) );
};

uint2x2 uint2x2::operator=( const uint2x2& other ) {
	memcpy( rows, other.rows, sizeof( rows ) );
	return *this;
};

uint2x2 uint2x2::operator+( const uint32_t rhs ) const {
	return uint2x2(
		rows[0] + rhs,
		rows[1] + rhs
	);
}

uint2x2 uint2x2::operator+=( const uint32_t rhs ) {
	return ( *this = *this + rhs );
}

uint2x2 uint2x2::operator+( const uint2x2& rhs ) const {
	return uint2x2(
		rows[0] + rhs[0],
		rows[1] + rhs[1]
	);
}

uint2x2 uint2x2::operator+=( const uint2x2& rhs ) {
	return ( *this = *this + rhs );
}

uint2x2 uint2x2::operator-( const uint32_t rhs ) const {
	return uint2x2(
		rows[0] - rhs,
		rows[1] - rhs
	);
}

uint2x2 uint2x2::operator-=( const uint32_t rhs ) {
	return ( *this = *this - rhs );
}

uint2x2 uint2x2::operator-( const uint2x2& rhs ) const {
	return uint2x2(
		rows[0] - rhs[0],
		rows[1] - rhs[1]
	);
}

uint2x2 uint2x2::operator-=( const uint2x2& rhs ) {
	return ( *this = *this - rhs );
}

uint2x2 uint2x2::operator*( const uint32_t rhs ) const {
	return uint2x2(
		rows[0] * rhs,
		rows[1] * rhs
	);
}

uint2x2 uint2x2::operator*=( const uint32_t rhs ) {
	return ( *this = *this * rhs );
}

uint2x2 uint2x2::operator*( const uint2x2& rhs ) const {
	uint2 row0 = rows[0];
	uint2 row1 = rows[1];

	uint2 col0 = { rhs[0].x, rhs[1].x };
	uint2 col1 = { rhs[0].y, rhs[1].y };

	return uint2x2(
		row0.x * col0.x + row0.y * col0.y,
		row0.x * col1.x + row0.y * col1.y,

		row1.x * col0.x + row1.y * col0.y,
		row1.x * col1.x + row1.y * col1.y
	);
}

uint2x2 uint2x2::operator*=( const uint2x2& rhs ) {
	return ( *this = *this * rhs );
}

uint2x2 uint2x2::operator/( const uint32_t rhs ) const {
	return uint2x2(
		rows[0] / rhs,
		rows[1] / rhs
	);
}

uint2x2 uint2x2::operator/=( const uint32_t rhs ) {
	return ( *this = *this / rhs );
}

uint2x2 uint2x2::operator/( const uint2x2& rhs ) const {
	return uint2x2(
		rows[0] / rhs[0],
		rows[1] / rhs[1]
	);
}

uint2x2 uint2x2::operator/=( const uint2x2& rhs ) {
	return ( *this = *this / rhs );
}

uint2& uint2x2::operator[]( const uint32_t index ) {
	assert( index < 2 );
	return rows[index];
}

const uint2& uint2x2::operator[]( const uint32_t index ) const {
	assert( index < 2 );
	return rows[index];
}

bool operator==( const uint2x2& lhs, const uint2x2& rhs ) {
	return lhs[0] == rhs[0]
		&& lhs[1] == rhs[1];
}

bool operator!=( const uint2x2& lhs, const uint2x2& rhs ) {
	return !( operator==( lhs, rhs ) );
}

bool2x2 operator<( const uint2x2& lhs, const uint2x2& rhs ) {
	return bool2x2(
		lhs[0] < rhs[0],
		lhs[1] < rhs[1]
	);
}

bool2x2 operator<=( const uint2x2& lhs, const uint2x2& rhs ) {
	return bool2x2(
		lhs[0] <= rhs[0],
		lhs[1] <= rhs[1]
	);
}

bool2x2 operator>( const uint2x2& lhs, const uint2x2& rhs ) {
	return bool2x2(
		lhs[0] > rhs[0],
		lhs[1] > rhs[1]
	);
}

bool2x2 operator>=( const uint2x2& lhs, const uint2x2& rhs ) {
	return bool2x2(
		lhs[0] >= rhs[0],
		lhs[1] >= rhs[1]
	);
}


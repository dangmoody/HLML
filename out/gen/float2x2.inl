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

// forward declares
float2x2 inverse( const float2x2& mat );

float2x2::float2x2() {
	rows[0] = { 1, 0 };
	rows[1] = { 0, 1 };
}

float2x2::float2x2( const float diagonal ) {
	rows[0] = { diagonal, 0 };
	rows[1] = { 0, diagonal };
}

float2x2::float2x2( const float2& diagonal ) {
	rows[0] = { diagonal.x, 0 };
	rows[1] = { 0, diagonal.y };
}

float2x2::float2x2( const float2& row0, const float2& row1 ) {
	rows[0] = row0;
	rows[1] = row1;
}

float2x2::float2x2( const float2 rows[2] ) {
	this->rows[0] = rows[0];
	this->rows[1] = rows[1];
}

float2x2::float2x2( const float m00, const float m01, const float m10, const float m11 ) {
	rows[0] = { m00, m01 };
	rows[1] = { m10, m11 };
}

float2x2::float2x2( const float2x2& other ) {
	memcpy( rows, other.rows, sizeof( rows ) );
};

float2x2 float2x2::operator=( const float2x2& other ) {
	memcpy( rows, other.rows, sizeof( rows ) );
	return *this;
};

float2x2 float2x2::operator+( const float rhs ) const {
	return float2x2(
		rows[0] + rhs,
		rows[1] + rhs
	);
}

float2x2 float2x2::operator+=( const float rhs ) {
	return ( *this = *this + rhs );
}

float2x2 float2x2::operator+( const float2x2& rhs ) const {
	return float2x2(
		rows[0] + rhs.rows[0],
		rows[1] + rhs.rows[1]
	);
}

float2x2 float2x2::operator+=( const float2x2& rhs ) {
	return ( *this = *this + rhs );
}

float2x2 float2x2::operator-( const float rhs ) const {
	return float2x2(
		rows[0] - rhs,
		rows[1] - rhs
	);
}

float2x2 float2x2::operator-=( const float rhs ) {
	return ( *this = *this - rhs );
}

float2x2 float2x2::operator-( const float2x2& rhs ) const {
	return float2x2(
		rows[0] - rhs.rows[0],
		rows[1] - rhs.rows[1]
	);
}

float2x2 float2x2::operator-=( const float2x2& rhs ) {
	return ( *this = *this - rhs );
}

float2x2 float2x2::operator*( const float rhs ) const {
	return float2x2(
		rows[0] * rhs,
		rows[1] * rhs
	);
}

float2x2 float2x2::operator*=( const float rhs ) {
	return ( *this = *this * rhs );
}

float2x2 float2x2::operator*( const float2x2& rhs ) const {
	float2 row0 = rows[0];
	float2 row1 = rows[1];

	float2 col0 = { rhs.rows[0].x, rhs.rows[1].x };
	float2 col1 = { rhs.rows[0].y, rhs.rows[1].y };

	return float2x2(
		row0.x * col0.x + row0.y * col0.y,
		row0.x * col1.x + row0.y * col1.y,

		row1.x * col0.x + row1.y * col0.y,
		row1.x * col1.x + row1.y * col1.y
	);
}

float2x2 float2x2::operator*=( const float2x2& rhs ) {
	return ( *this = *this * rhs );
}

float2x2 float2x2::operator/( const float rhs ) const {
	return float2x2(
		rows[0] / rhs,
		rows[1] / rhs
	);
}

float2x2 float2x2::operator/=( const float rhs ) {
	return ( *this = *this / rhs );
}

float2x2 float2x2::operator/( const float2x2& rhs ) const {
	return *this * inverse( rhs );
}

float2x2 float2x2::operator/=( const float2x2& rhs ) {
	return ( *this = *this / rhs );
}

float2& float2x2::operator[]( const uint32_t index ) {
	assert( index < 2 );
	return rows[index];
}

const float2& float2x2::operator[]( const uint32_t index ) const {
	assert( index < 2 );
	return rows[index];
}

bool operator==( const float2x2& lhs, const float2x2& rhs ) {
	return lhs.rows[0] == rhs.rows[0]
		&& lhs.rows[1] == rhs.rows[1];
}

bool operator!=( const float2x2& lhs, const float2x2& rhs ) {
	return !( operator==( lhs, rhs ) );
}



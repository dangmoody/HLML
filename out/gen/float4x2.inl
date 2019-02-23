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
float4x2 inverse( const float4x2& mat );

float4x2::float4x2() {
	rows[0] = { 1, 0 };
	rows[1] = { 0, 1 };
	rows[2] = { 0, 0 };
	rows[3] = { 0, 0 };
}

float4x2::float4x2( const float diagonal ) {
	rows[0] = { diagonal, 0 };
	rows[1] = { 0, diagonal };
	rows[2] = { 0, 0 };
	rows[3] = { 0, 0 };
}

float4x2::float4x2( const float2& diagonal ) {
	rows[0] = { diagonal.x, 0 };
	rows[1] = { 0, diagonal.y };
	rows[2] = { 0, 0 };
	rows[3] = { 0, 0 };
}

float4x2::float4x2( const float2& row0, const float2& row1, const float2& row2, const float2& row3 ) {
	rows[0] = row0;
	rows[1] = row1;
	rows[2] = row2;
	rows[3] = row3;
}

float4x2::float4x2( const float2 rows[4] ) {
	this->rows[0] = rows[0];
	this->rows[1] = rows[1];
	this->rows[2] = rows[2];
	this->rows[3] = rows[3];
}

float4x2::float4x2( const float m00, const float m01, const float m10, const float m11, const float m20, const float m21, const float m30, const float m31 ) {
	rows[0] = { m00, m01 };
	rows[1] = { m10, m11 };
	rows[2] = { m20, m21 };
	rows[3] = { m30, m31 };
}

float4x2::float4x2( const float4x2& other ) {
	memcpy( rows, other.rows, sizeof( rows ) );
};

float4x2 float4x2::operator=( const float4x2& other ) {
	memcpy( rows, other.rows, sizeof( rows ) );
	return *this;
};

float4x2 float4x2::operator+( const float rhs ) const {
	return float4x2(
		rows[0] + rhs,
		rows[1] + rhs,
		rows[2] + rhs,
		rows[3] + rhs
	);
}

float4x2 float4x2::operator+=( const float rhs ) {
	return ( *this = *this + rhs );
}

float4x2 float4x2::operator+( const float4x2& rhs ) const {
	return float4x2(
		rows[0] + rhs[0],
		rows[1] + rhs[1],
		rows[2] + rhs[2],
		rows[3] + rhs[3]
	);
}

float4x2 float4x2::operator+=( const float4x2& rhs ) {
	return ( *this = *this + rhs );
}

float4x2 float4x2::operator-( const float rhs ) const {
	return float4x2(
		rows[0] - rhs,
		rows[1] - rhs,
		rows[2] - rhs,
		rows[3] - rhs
	);
}

float4x2 float4x2::operator-=( const float rhs ) {
	return ( *this = *this - rhs );
}

float4x2 float4x2::operator-( const float4x2& rhs ) const {
	return float4x2(
		rows[0] - rhs[0],
		rows[1] - rhs[1],
		rows[2] - rhs[2],
		rows[3] - rhs[3]
	);
}

float4x2 float4x2::operator-=( const float4x2& rhs ) {
	return ( *this = *this - rhs );
}

float4x2 float4x2::operator*( const float rhs ) const {
	return float4x2(
		rows[0] * rhs,
		rows[1] * rhs,
		rows[2] * rhs,
		rows[3] * rhs
	);
}

float4x2 float4x2::operator*=( const float rhs ) {
	return ( *this = *this * rhs );
}

float4x2 float4x2::operator*( const float4x2& rhs ) const {
	float4 row0 = rows[0];
	float4 row1 = rows[1];
	float4 row2 = rows[2];
	float4 row3 = rows[3];

	float4 col0 = { rhs[0].x, rhs[1].x, rhs[2].x, rhs[3].x };
	float4 col1 = { rhs[0].y, rhs[1].y, rhs[2].y, rhs[3].y };

	return float4x2(
		row0.x * col0.x + row0.y * col0.y + row0.z * col0.z + row0.w * col0.w,
		row0.x * col1.x + row0.y * col1.y + row0.z * col1.z + row0.w * col1.w,

		row1.x * col0.x + row1.y * col0.y + row1.z * col0.z + row1.w * col0.w,
		row1.x * col1.x + row1.y * col1.y + row1.z * col1.z + row1.w * col1.w,

		row2.x * col0.x + row2.y * col0.y + row2.z * col0.z + row2.w * col0.w,
		row2.x * col1.x + row2.y * col1.y + row2.z * col1.z + row2.w * col1.w,

		row3.x * col0.x + row3.y * col0.y + row3.z * col0.z + row3.w * col0.w,
		row3.x * col1.x + row3.y * col1.y + row3.z * col1.z + row3.w * col1.w
	);
}

float4x2 float4x2::operator*=( const float4x2& rhs ) {
	return ( *this = *this * rhs );
}

float4x2 float4x2::operator/( const float rhs ) const {
	return float4x2(
		rows[0] / rhs,
		rows[1] / rhs,
		rows[2] / rhs,
		rows[3] / rhs
	);
}

float4x2 float4x2::operator/=( const float rhs ) {
	return ( *this = *this / rhs );
}

float4x2 float4x2::operator/( const float4x2& rhs ) const {
	return *this * inverse( rhs );
}

float4x2 float4x2::operator/=( const float4x2& rhs ) {
	return ( *this = *this / rhs );
}

float2& float4x2::operator[]( const uint32_t index ) {
	assert( index < 4 );
	return rows[index];
}

const float2& float4x2::operator[]( const uint32_t index ) const {
	assert( index < 4 );
	return rows[index];
}

bool operator==( const float4x2& lhs, const float4x2& rhs ) {
	return lhs[0] == rhs[0]
		&& lhs[1] == rhs[1]
		&& lhs[2] == rhs[2]
		&& lhs[3] == rhs[3];
}

bool operator!=( const float4x2& lhs, const float4x2& rhs ) {
	return !( operator==( lhs, rhs ) );
}

bool4x2 operator<( const float4x2& lhs, const float4x2& rhs ) {
	return bool4x2(
		lhs[0] < rhs[0],
		lhs[1] < rhs[1],
		lhs[2] < rhs[2],
		lhs[3] < rhs[3]
	);
}

bool4x2 operator<=( const float4x2& lhs, const float4x2& rhs ) {
	return bool4x2(
		lhs[0] <= rhs[0],
		lhs[1] <= rhs[1],
		lhs[2] <= rhs[2],
		lhs[3] <= rhs[3]
	);
}

bool4x2 operator>( const float4x2& lhs, const float4x2& rhs ) {
	return bool4x2(
		lhs[0] > rhs[0],
		lhs[1] > rhs[1],
		lhs[2] > rhs[2],
		lhs[3] > rhs[3]
	);
}

bool4x2 operator>=( const float4x2& lhs, const float4x2& rhs ) {
	return bool4x2(
		lhs[0] >= rhs[0],
		lhs[1] >= rhs[1],
		lhs[2] >= rhs[2],
		lhs[3] >= rhs[3]
	);
}


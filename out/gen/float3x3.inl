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
float3x3 inverse( const float3x3& mat );

float3x3::float3x3() {
	rows[0] = { 1, 0, 0 };
	rows[1] = { 0, 1, 0 };
	rows[2] = { 0, 0, 1 };
}

float3x3::float3x3( const float diagonal ) {
	rows[0] = { diagonal, 0, 0 };
	rows[1] = { 0, diagonal, 0 };
	rows[2] = { 0, 0, diagonal };
}

float3x3::float3x3( const float3& diagonal ) {
	rows[0] = { diagonal.x, 0, 0 };
	rows[1] = { 0, diagonal.y, 0 };
	rows[2] = { 0, 0, diagonal.z };
}

float3x3::float3x3( const float3& row0, const float3& row1, const float3& row2 ) {
	rows[0] = row0;
	rows[1] = row1;
	rows[2] = row2;
}

float3x3::float3x3( const float3 rows[3] ) {
	this->rows[0] = rows[0];
	this->rows[1] = rows[1];
	this->rows[2] = rows[2];
}

float3x3::float3x3( const float m00, const float m01, const float m02, const float m10, const float m11, const float m12, const float m20, const float m21, const float m22 ) {
	rows[0] = { m00, m01, m02 };
	rows[1] = { m10, m11, m12 };
	rows[2] = { m20, m21, m22 };
}

float3x3::float3x3( const float3x3& other ) {
	memcpy( rows, other.rows, sizeof( rows ) );
};

float3x3 float3x3::operator=( const float3x3& other ) {
	memcpy( rows, other.rows, sizeof( rows ) );
	return *this;
};

float3x3 float3x3::operator+( const float rhs ) const {
	return float3x3(
		rows[0] + rhs,
		rows[1] + rhs,
		rows[2] + rhs
	);
}

float3x3 float3x3::operator+=( const float rhs ) {
	return ( *this = *this + rhs );
}

float3x3 float3x3::operator+( const float3x3& rhs ) const {
	return float3x3(
		rows[0] + rhs.rows[0],
		rows[1] + rhs.rows[1],
		rows[2] + rhs.rows[2]
	);
}

float3x3 float3x3::operator+=( const float3x3& rhs ) {
	return ( *this = *this + rhs );
}

float3x3 float3x3::operator-( const float rhs ) const {
	return float3x3(
		rows[0] - rhs,
		rows[1] - rhs,
		rows[2] - rhs
	);
}

float3x3 float3x3::operator-=( const float rhs ) {
	return ( *this = *this - rhs );
}

float3x3 float3x3::operator-( const float3x3& rhs ) const {
	return float3x3(
		rows[0] - rhs.rows[0],
		rows[1] - rhs.rows[1],
		rows[2] - rhs.rows[2]
	);
}

float3x3 float3x3::operator-=( const float3x3& rhs ) {
	return ( *this = *this - rhs );
}

float3x3 float3x3::operator*( const float rhs ) const {
	return float3x3(
		rows[0] * rhs,
		rows[1] * rhs,
		rows[2] * rhs
	);
}

float3x3 float3x3::operator*=( const float rhs ) {
	return ( *this = *this * rhs );
}

float3x3 float3x3::operator*( const float3x3& rhs ) const {
	float3 row0 = rows[0];
	float3 row1 = rows[1];
	float3 row2 = rows[2];

	float3 col0 = { rhs.rows[0].x, rhs.rows[1].x, rhs.rows[2].x };
	float3 col1 = { rhs.rows[0].y, rhs.rows[1].y, rhs.rows[2].y };
	float3 col2 = { rhs.rows[0].z, rhs.rows[1].z, rhs.rows[2].z };

	return float3x3(
		row0.x * col0.x + row0.y * col0.y + row0.z * col0.z,
		row0.x * col1.x + row0.y * col1.y + row0.z * col1.z,
		row0.x * col2.x + row0.y * col2.y + row0.z * col2.z,

		row1.x * col0.x + row1.y * col0.y + row1.z * col0.z,
		row1.x * col1.x + row1.y * col1.y + row1.z * col1.z,
		row1.x * col2.x + row1.y * col2.y + row1.z * col2.z,

		row2.x * col0.x + row2.y * col0.y + row2.z * col0.z,
		row2.x * col1.x + row2.y * col1.y + row2.z * col1.z,
		row2.x * col2.x + row2.y * col2.y + row2.z * col2.z
	);
}

float3x3 float3x3::operator*=( const float3x3& rhs ) {
	return ( *this = *this * rhs );
}

float3x3 float3x3::operator/( const float rhs ) const {
	return float3x3(
		rows[0] / rhs,
		rows[1] / rhs,
		rows[2] / rhs
	);
}

float3x3 float3x3::operator/=( const float rhs ) {
	return ( *this = *this / rhs );
}

float3x3 float3x3::operator/( const float3x3& rhs ) const {
	return *this * inverse( rhs );
}

float3x3 float3x3::operator/=( const float3x3& rhs ) {
	return ( *this = *this / rhs );
}

float3& float3x3::operator[]( const uint32_t index ) {
	assert( index < 3 );
	return rows[index];
}

const float3& float3x3::operator[]( const uint32_t index ) const {
	assert( index < 3 );
	return rows[index];
}

bool operator==( const float3x3& lhs, const float3x3& rhs ) {
	return lhs.rows[0] == rhs.rows[0]
		&& lhs.rows[1] == rhs.rows[1]
		&& lhs.rows[2] == rhs.rows[2];
}

bool operator!=( const float3x3& lhs, const float3x3& rhs ) {
	return !( operator==( lhs, rhs ) );
}



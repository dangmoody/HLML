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
#include "uint2.h"
#include "uint4.h"

#include "../hlml_main.h"

// others
#include <math.h>

uint3::uint3() {
	memset( data, 0, 3 * sizeof( uint32_t ) );
}

uint3::uint3( const uint32_t x ) {
	this->x = this->y = this->z = x;
}

uint3::uint3( const uint32_t x, const uint32_t y, const uint32_t z ) {
	this->x = x;
	this->y = y;
	this->z = z;
}

uint3::uint3( const uint2& other ) {
	memcpy( data, other.data, sizeof( other.data ) );
}

uint3::uint3( const uint3& other ) {
	memcpy( data, other.data, sizeof( other.data ) );
}

uint3::uint3( const uint4& other ) {
	memcpy( data, other.data, sizeof( other.data ) );
}

uint3 uint3::operator=( const uint2& rhs ) {
	memcpy( data, rhs.data, sizeof( rhs.data ) );
	return *this;
}

uint3 uint3::operator=( const uint3& rhs ) {
	memcpy( data, rhs.data, sizeof( rhs.data ) );
	return *this;
}

uint3 uint3::operator=( const uint4& rhs ) {
	memcpy( data, rhs.data, sizeof( rhs.data ) );
	return *this;
}

uint3 uint3::operator+( const uint32_t rhs ) const {
	return uint3(
		x + rhs,
		y + rhs,
		z + rhs
	);
}

uint3 uint3::operator+=( const uint32_t rhs ) {
	return ( *this = *this + rhs );
}

uint3 uint3::operator+( const uint3& rhs ) const {
	return uint3(
		x + rhs.x,
		y + rhs.y,
		z + rhs.z
	);
}

uint3 uint3::operator+=( const uint3& rhs ) {
	return ( *this = *this + rhs );
}

uint3 uint3::operator-( const uint32_t rhs ) const {
	return uint3(
		x - rhs,
		y - rhs,
		z - rhs
	);
}

uint3 uint3::operator-=( const uint32_t rhs ) {
	return ( *this = *this - rhs );
}

uint3 uint3::operator-( const uint3& rhs ) const {
	return uint3(
		x - rhs.x,
		y - rhs.y,
		z - rhs.z
	);
}

uint3 uint3::operator-=( const uint3& rhs ) {
	return ( *this = *this - rhs );
}

uint3 uint3::operator*( const uint32_t rhs ) const {
	return uint3(
		x * rhs,
		y * rhs,
		z * rhs
	);
}

uint3 uint3::operator*=( const uint32_t rhs ) {
	return ( *this = *this * rhs );
}

uint3 uint3::operator*( const uint3& rhs ) const {
	return uint3(
		x * rhs.x,
		y * rhs.y,
		z * rhs.z
	);
}

uint3 uint3::operator*=( const uint3& rhs ) {
	return ( *this = *this * rhs );
}

uint3 uint3::operator/( const uint32_t rhs ) const {
	return uint3(
		x / rhs,
		y / rhs,
		z / rhs
	);
}

uint3 uint3::operator/=( const uint32_t rhs ) {
	return ( *this = *this / rhs );
}

uint3 uint3::operator/( const uint3& rhs ) const {
	return uint3(
		x / rhs.x,
		y / rhs.y,
		z / rhs.z
	);
}

uint3 uint3::operator/=( const uint3& rhs ) {
	return ( *this = *this / rhs );
}

const uint32_t& uint3::operator[]( const uint32_t index ) const {
	assert( index < 3 );
	return data[index];
}

uint32_t& uint3::operator[]( const uint32_t index ) {
	assert( index < 3 );
	return data[index];
}

bool operator==( const uint3& lhs, const uint3& rhs ) {
	return floateq( lhs.x, rhs. x ) && floateq( lhs.y, rhs. y ) && floateq( lhs.z, rhs. z );
}

bool operator!=( const uint3& lhs, const uint3& rhs ) {
	return !( operator==( lhs, rhs ) );
}

bool3 operator<( const uint3& lhs, const uint3& rhs ) {
	return bool3(
		lhs.x < rhs.x,
		lhs.y < rhs.y,
		lhs.z < rhs.z
	);
}

bool3 operator<=( const uint3& lhs, const uint3& rhs ) {
	return bool3(
		lhs.x <= rhs.x,
		lhs.y <= rhs.y,
		lhs.z <= rhs.z
	);
}

bool3 operator>( const uint3& lhs, const uint3& rhs ) {
	return bool3(
		lhs.x > rhs.x,
		lhs.y > rhs.y,
		lhs.z > rhs.z
	);
}

bool3 operator>=( const uint3& lhs, const uint3& rhs ) {
	return bool3(
		lhs.x >= rhs.x,
		lhs.y >= rhs.y,
		lhs.z >= rhs.z
	);
}


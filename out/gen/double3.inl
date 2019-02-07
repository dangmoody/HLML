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
#include "double2.h"
#include "double4.h"

#include "../hlml_main.h"

// others
#include <math.h>

double3::double3() {
	memset( data, 0, 3 * sizeof( double ) );
}

double3::double3( const double x ) {
	this->x = this->y = this->z = x;
}

double3::double3( const double x, const double y, const double z ) {
	this->x = x;
	this->y = y;
	this->z = z;
}

double3::double3( const double2& other ) {
	memcpy( data, other.data, sizeof( other.data ) );
}

double3::double3( const double3& other ) {
	memcpy( data, other.data, sizeof( other.data ) );
}

double3::double3( const double4& other ) {
	memcpy( data, other.data, sizeof( other.data ) );
}

double3 double3::operator=( const double2& rhs ) {
	memcpy( data, rhs.data, sizeof( rhs.data ) );
	return *this;
}

double3 double3::operator=( const double3& rhs ) {
	memcpy( data, rhs.data, sizeof( rhs.data ) );
	return *this;
}

double3 double3::operator=( const double4& rhs ) {
	memcpy( data, rhs.data, sizeof( rhs.data ) );
	return *this;
}

double3 double3::operator+( const double rhs ) const {
	return double3(
		x + rhs,
		y + rhs,
		z + rhs
	);
}

double3 double3::operator+=( const double rhs ) {
	return ( *this = *this + rhs );
}

double3 double3::operator+( const double3& rhs ) const {
	return double3(
		x + rhs.x,
		y + rhs.y,
		z + rhs.z
	);
}

double3 double3::operator+=( const double3& rhs ) {
	return ( *this = *this + rhs );
}

double3 double3::operator-( const double rhs ) const {
	return double3(
		x - rhs,
		y - rhs,
		z - rhs
	);
}

double3 double3::operator-=( const double rhs ) {
	return ( *this = *this - rhs );
}

double3 double3::operator-( const double3& rhs ) const {
	return double3(
		x - rhs.x,
		y - rhs.y,
		z - rhs.z
	);
}

double3 double3::operator-=( const double3& rhs ) {
	return ( *this = *this - rhs );
}

double3 double3::operator*( const double rhs ) const {
	return double3(
		x * rhs,
		y * rhs,
		z * rhs
	);
}

double3 double3::operator*=( const double rhs ) {
	return ( *this = *this * rhs );
}

double3 double3::operator*( const double3& rhs ) const {
	return double3(
		x * rhs.x,
		y * rhs.y,
		z * rhs.z
	);
}

double3 double3::operator*=( const double3& rhs ) {
	return ( *this = *this * rhs );
}

double3 double3::operator/( const double rhs ) const {
	return double3(
		x / rhs,
		y / rhs,
		z / rhs
	);
}

double3 double3::operator/=( const double rhs ) {
	return ( *this = *this / rhs );
}

double3 double3::operator/( const double3& rhs ) const {
	return double3(
		x / rhs.x,
		y / rhs.y,
		z / rhs.z
	);
}

double3 double3::operator/=( const double3& rhs ) {
	return ( *this = *this / rhs );
}

const double& double3::operator[]( const uint32_t index ) const {
	assert( index < 3 );
	return data[index];
}

double& double3::operator[]( const uint32_t index ) {
	assert( index < 3 );
	return data[index];
}

bool operator==( const double3& lhs, const double3& rhs ) {
	return floateq( lhs.x, rhs. x ) && floateq( lhs.y, rhs. y ) && floateq( lhs.z, rhs. z );
}

bool operator!=( const double3& lhs, const double3& rhs ) {
	return !( operator==( lhs, rhs ) );
}

bool3 operator<( const double3& lhs, const double3& rhs ) {
	return bool3(
		lhs.x < rhs.x,
		lhs.y < rhs.y,
		lhs.z < rhs.z
	);
}

bool3 operator<=( const double3& lhs, const double3& rhs ) {
	return bool3(
		lhs.x <= rhs.x,
		lhs.y <= rhs.y,
		lhs.z <= rhs.z
	);
}

bool3 operator>( const double3& lhs, const double3& rhs ) {
	return bool3(
		lhs.x > rhs.x,
		lhs.y > rhs.y,
		lhs.z > rhs.z
	);
}

bool3 operator>=( const double3& lhs, const double3& rhs ) {
	return bool3(
		lhs.x >= rhs.x,
		lhs.y >= rhs.y,
		lhs.z >= rhs.z
	);
}


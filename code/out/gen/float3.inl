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
#include "float2.h"
#include "float4.h"

#include "../hlml_main.h"

// others
#include <math.h>
#include <memory.h>
#include <assert.h>

float3::float3() {
	memset( data, 0, 3 * sizeof( float ) );
}

float3::float3( const float x ) {
	this->x = this->y = this->z = x;
}

float3::float3( const float x, const float y, const float z ) {
	this->x = x;
	this->y = y;
	this->z = z;
}

float3::float3( const float2& other ) {
	memcpy( data, other.data, sizeof( other.data ) );
}

float3::float3( const float3& other ) {
	memcpy( data, other.data, sizeof( other.data ) );
}

float3::float3( const float4& other ) {
	memcpy( data, other.data, sizeof( other.data ) );
}

float3 float3::operator=( const float2& rhs ) {
	memcpy( data, rhs.data, sizeof( rhs.data ) );
	return *this;
}

float3 float3::operator=( const float3& rhs ) {
	memcpy( data, rhs.data, sizeof( rhs.data ) );
	return *this;
}

float3 float3::operator=( const float4& rhs ) {
	memcpy( data, rhs.data, sizeof( rhs.data ) );
	return *this;
}

const float& float3::operator[]( const uint32_t index ) const {
	assert( index < 3 );
	return data[index];
}

float& float3::operator[]( const uint32_t index ) {
	assert( index < 3 );
	return data[index];
}

bool operator==( const float3& lhs, const float3& rhs ) {
	return floateq( lhs.x, rhs. x ) && floateq( lhs.y, rhs. y ) && floateq( lhs.z, rhs. z );
}

bool operator!=( const float3& lhs, const float3& rhs ) {
	return !( operator==( lhs, rhs ) );
}


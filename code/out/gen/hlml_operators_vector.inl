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

#include "hlml_operators_vector.h"

// int2
int2 int2::operator+( const int rhs ) const {
	return int2(
		x + rhs,
		y + rhs
	);
}

int2 int2::operator+=( const int rhs ) {
	return ( *this = *this + rhs );
}

int2 int2::operator+( const int2& rhs ) const {
	return int2(
		x + rhs.x,
		y + rhs.y
	);
}

int2 int2::operator+=( const int2& rhs ) {
	return ( *this = *this + rhs );
}

int2 int2::operator-( const int rhs ) const {
	return int2(
		x - rhs,
		y - rhs
	);
}

int2 int2::operator-=( const int rhs ) {
	return ( *this = *this - rhs );
}

int2 int2::operator-( const int2& rhs ) const {
	return int2(
		x - rhs.x,
		y - rhs.y
	);
}

int2 int2::operator-=( const int2& rhs ) {
	return ( *this = *this - rhs );
}

int2 int2::operator*( const int rhs ) const {
	return int2(
		x * rhs,
		y * rhs
	);
}

int2 int2::operator*=( const int rhs ) {
	return ( *this = *this * rhs );
}

int2 int2::operator*( const int2& rhs ) const {
	return int2(
		x * rhs.x,
		y * rhs.y
	);
}

int2 int2::operator*=( const int2& rhs ) {
	return ( *this = *this * rhs );
}

int2 int2::operator/( const int rhs ) const {
	return int2(
		x / rhs,
		y / rhs
	);
}

int2 int2::operator/=( const int rhs ) {
	return ( *this = *this / rhs );
}

int2 int2::operator/( const int2& rhs ) const {
	return int2(
		x / rhs.x,
		y / rhs.y
	);
}

int2 int2::operator/=( const int2& rhs ) {
	return ( *this = *this / rhs );
}

bool2 operator<( const int2& lhs, const int2& rhs ) {
	return bool2(
		lhs.x < rhs.x,
		lhs.y < rhs.y
	);
}

bool2 operator<=( const int2& lhs, const int2& rhs ) {
	return bool2(
		lhs.x <= rhs.x,
		lhs.y <= rhs.y
	);
}

bool2 operator>( const int2& lhs, const int2& rhs ) {
	return bool2(
		lhs.x > rhs.x,
		lhs.y > rhs.y
	);
}

bool2 operator>=( const int2& lhs, const int2& rhs ) {
	return bool2(
		lhs.x >= rhs.x,
		lhs.y >= rhs.y
	);
}


// int3
int3 int3::operator+( const int rhs ) const {
	return int3(
		x + rhs,
		y + rhs,
		z + rhs
	);
}

int3 int3::operator+=( const int rhs ) {
	return ( *this = *this + rhs );
}

int3 int3::operator+( const int3& rhs ) const {
	return int3(
		x + rhs.x,
		y + rhs.y,
		z + rhs.z
	);
}

int3 int3::operator+=( const int3& rhs ) {
	return ( *this = *this + rhs );
}

int3 int3::operator-( const int rhs ) const {
	return int3(
		x - rhs,
		y - rhs,
		z - rhs
	);
}

int3 int3::operator-=( const int rhs ) {
	return ( *this = *this - rhs );
}

int3 int3::operator-( const int3& rhs ) const {
	return int3(
		x - rhs.x,
		y - rhs.y,
		z - rhs.z
	);
}

int3 int3::operator-=( const int3& rhs ) {
	return ( *this = *this - rhs );
}

int3 int3::operator*( const int rhs ) const {
	return int3(
		x * rhs,
		y * rhs,
		z * rhs
	);
}

int3 int3::operator*=( const int rhs ) {
	return ( *this = *this * rhs );
}

int3 int3::operator*( const int3& rhs ) const {
	return int3(
		x * rhs.x,
		y * rhs.y,
		z * rhs.z
	);
}

int3 int3::operator*=( const int3& rhs ) {
	return ( *this = *this * rhs );
}

int3 int3::operator/( const int rhs ) const {
	return int3(
		x / rhs,
		y / rhs,
		z / rhs
	);
}

int3 int3::operator/=( const int rhs ) {
	return ( *this = *this / rhs );
}

int3 int3::operator/( const int3& rhs ) const {
	return int3(
		x / rhs.x,
		y / rhs.y,
		z / rhs.z
	);
}

int3 int3::operator/=( const int3& rhs ) {
	return ( *this = *this / rhs );
}

bool3 operator<( const int3& lhs, const int3& rhs ) {
	return bool3(
		lhs.x < rhs.x,
		lhs.y < rhs.y,
		lhs.z < rhs.z
	);
}

bool3 operator<=( const int3& lhs, const int3& rhs ) {
	return bool3(
		lhs.x <= rhs.x,
		lhs.y <= rhs.y,
		lhs.z <= rhs.z
	);
}

bool3 operator>( const int3& lhs, const int3& rhs ) {
	return bool3(
		lhs.x > rhs.x,
		lhs.y > rhs.y,
		lhs.z > rhs.z
	);
}

bool3 operator>=( const int3& lhs, const int3& rhs ) {
	return bool3(
		lhs.x >= rhs.x,
		lhs.y >= rhs.y,
		lhs.z >= rhs.z
	);
}


// int4
int4 int4::operator+( const int rhs ) const {
	return int4(
		x + rhs,
		y + rhs,
		z + rhs,
		w + rhs
	);
}

int4 int4::operator+=( const int rhs ) {
	return ( *this = *this + rhs );
}

int4 int4::operator+( const int4& rhs ) const {
	return int4(
		x + rhs.x,
		y + rhs.y,
		z + rhs.z,
		w + rhs.w
	);
}

int4 int4::operator+=( const int4& rhs ) {
	return ( *this = *this + rhs );
}

int4 int4::operator-( const int rhs ) const {
	return int4(
		x - rhs,
		y - rhs,
		z - rhs,
		w - rhs
	);
}

int4 int4::operator-=( const int rhs ) {
	return ( *this = *this - rhs );
}

int4 int4::operator-( const int4& rhs ) const {
	return int4(
		x - rhs.x,
		y - rhs.y,
		z - rhs.z,
		w - rhs.w
	);
}

int4 int4::operator-=( const int4& rhs ) {
	return ( *this = *this - rhs );
}

int4 int4::operator*( const int rhs ) const {
	return int4(
		x * rhs,
		y * rhs,
		z * rhs,
		w * rhs
	);
}

int4 int4::operator*=( const int rhs ) {
	return ( *this = *this * rhs );
}

int4 int4::operator*( const int4& rhs ) const {
	return int4(
		x * rhs.x,
		y * rhs.y,
		z * rhs.z,
		w * rhs.w
	);
}

int4 int4::operator*=( const int4& rhs ) {
	return ( *this = *this * rhs );
}

int4 int4::operator/( const int rhs ) const {
	return int4(
		x / rhs,
		y / rhs,
		z / rhs,
		w / rhs
	);
}

int4 int4::operator/=( const int rhs ) {
	return ( *this = *this / rhs );
}

int4 int4::operator/( const int4& rhs ) const {
	return int4(
		x / rhs.x,
		y / rhs.y,
		z / rhs.z,
		w / rhs.w
	);
}

int4 int4::operator/=( const int4& rhs ) {
	return ( *this = *this / rhs );
}

bool4 operator<( const int4& lhs, const int4& rhs ) {
	return bool4(
		lhs.x < rhs.x,
		lhs.y < rhs.y,
		lhs.z < rhs.z,
		lhs.w < rhs.w
	);
}

bool4 operator<=( const int4& lhs, const int4& rhs ) {
	return bool4(
		lhs.x <= rhs.x,
		lhs.y <= rhs.y,
		lhs.z <= rhs.z,
		lhs.w <= rhs.w
	);
}

bool4 operator>( const int4& lhs, const int4& rhs ) {
	return bool4(
		lhs.x > rhs.x,
		lhs.y > rhs.y,
		lhs.z > rhs.z,
		lhs.w > rhs.w
	);
}

bool4 operator>=( const int4& lhs, const int4& rhs ) {
	return bool4(
		lhs.x >= rhs.x,
		lhs.y >= rhs.y,
		lhs.z >= rhs.z,
		lhs.w >= rhs.w
	);
}


// uint2
uint2 uint2::operator+( const uint rhs ) const {
	return uint2(
		x + rhs,
		y + rhs
	);
}

uint2 uint2::operator+=( const uint rhs ) {
	return ( *this = *this + rhs );
}

uint2 uint2::operator+( const uint2& rhs ) const {
	return uint2(
		x + rhs.x,
		y + rhs.y
	);
}

uint2 uint2::operator+=( const uint2& rhs ) {
	return ( *this = *this + rhs );
}

uint2 uint2::operator-( const uint rhs ) const {
	return uint2(
		x - rhs,
		y - rhs
	);
}

uint2 uint2::operator-=( const uint rhs ) {
	return ( *this = *this - rhs );
}

uint2 uint2::operator-( const uint2& rhs ) const {
	return uint2(
		x - rhs.x,
		y - rhs.y
	);
}

uint2 uint2::operator-=( const uint2& rhs ) {
	return ( *this = *this - rhs );
}

uint2 uint2::operator*( const uint rhs ) const {
	return uint2(
		x * rhs,
		y * rhs
	);
}

uint2 uint2::operator*=( const uint rhs ) {
	return ( *this = *this * rhs );
}

uint2 uint2::operator*( const uint2& rhs ) const {
	return uint2(
		x * rhs.x,
		y * rhs.y
	);
}

uint2 uint2::operator*=( const uint2& rhs ) {
	return ( *this = *this * rhs );
}

uint2 uint2::operator/( const uint rhs ) const {
	return uint2(
		x / rhs,
		y / rhs
	);
}

uint2 uint2::operator/=( const uint rhs ) {
	return ( *this = *this / rhs );
}

uint2 uint2::operator/( const uint2& rhs ) const {
	return uint2(
		x / rhs.x,
		y / rhs.y
	);
}

uint2 uint2::operator/=( const uint2& rhs ) {
	return ( *this = *this / rhs );
}

bool2 operator<( const uint2& lhs, const uint2& rhs ) {
	return bool2(
		lhs.x < rhs.x,
		lhs.y < rhs.y
	);
}

bool2 operator<=( const uint2& lhs, const uint2& rhs ) {
	return bool2(
		lhs.x <= rhs.x,
		lhs.y <= rhs.y
	);
}

bool2 operator>( const uint2& lhs, const uint2& rhs ) {
	return bool2(
		lhs.x > rhs.x,
		lhs.y > rhs.y
	);
}

bool2 operator>=( const uint2& lhs, const uint2& rhs ) {
	return bool2(
		lhs.x >= rhs.x,
		lhs.y >= rhs.y
	);
}


// uint3
uint3 uint3::operator+( const uint rhs ) const {
	return uint3(
		x + rhs,
		y + rhs,
		z + rhs
	);
}

uint3 uint3::operator+=( const uint rhs ) {
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

uint3 uint3::operator-( const uint rhs ) const {
	return uint3(
		x - rhs,
		y - rhs,
		z - rhs
	);
}

uint3 uint3::operator-=( const uint rhs ) {
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

uint3 uint3::operator*( const uint rhs ) const {
	return uint3(
		x * rhs,
		y * rhs,
		z * rhs
	);
}

uint3 uint3::operator*=( const uint rhs ) {
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

uint3 uint3::operator/( const uint rhs ) const {
	return uint3(
		x / rhs,
		y / rhs,
		z / rhs
	);
}

uint3 uint3::operator/=( const uint rhs ) {
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


// uint4
uint4 uint4::operator+( const uint rhs ) const {
	return uint4(
		x + rhs,
		y + rhs,
		z + rhs,
		w + rhs
	);
}

uint4 uint4::operator+=( const uint rhs ) {
	return ( *this = *this + rhs );
}

uint4 uint4::operator+( const uint4& rhs ) const {
	return uint4(
		x + rhs.x,
		y + rhs.y,
		z + rhs.z,
		w + rhs.w
	);
}

uint4 uint4::operator+=( const uint4& rhs ) {
	return ( *this = *this + rhs );
}

uint4 uint4::operator-( const uint rhs ) const {
	return uint4(
		x - rhs,
		y - rhs,
		z - rhs,
		w - rhs
	);
}

uint4 uint4::operator-=( const uint rhs ) {
	return ( *this = *this - rhs );
}

uint4 uint4::operator-( const uint4& rhs ) const {
	return uint4(
		x - rhs.x,
		y - rhs.y,
		z - rhs.z,
		w - rhs.w
	);
}

uint4 uint4::operator-=( const uint4& rhs ) {
	return ( *this = *this - rhs );
}

uint4 uint4::operator*( const uint rhs ) const {
	return uint4(
		x * rhs,
		y * rhs,
		z * rhs,
		w * rhs
	);
}

uint4 uint4::operator*=( const uint rhs ) {
	return ( *this = *this * rhs );
}

uint4 uint4::operator*( const uint4& rhs ) const {
	return uint4(
		x * rhs.x,
		y * rhs.y,
		z * rhs.z,
		w * rhs.w
	);
}

uint4 uint4::operator*=( const uint4& rhs ) {
	return ( *this = *this * rhs );
}

uint4 uint4::operator/( const uint rhs ) const {
	return uint4(
		x / rhs,
		y / rhs,
		z / rhs,
		w / rhs
	);
}

uint4 uint4::operator/=( const uint rhs ) {
	return ( *this = *this / rhs );
}

uint4 uint4::operator/( const uint4& rhs ) const {
	return uint4(
		x / rhs.x,
		y / rhs.y,
		z / rhs.z,
		w / rhs.w
	);
}

uint4 uint4::operator/=( const uint4& rhs ) {
	return ( *this = *this / rhs );
}

bool4 operator<( const uint4& lhs, const uint4& rhs ) {
	return bool4(
		lhs.x < rhs.x,
		lhs.y < rhs.y,
		lhs.z < rhs.z,
		lhs.w < rhs.w
	);
}

bool4 operator<=( const uint4& lhs, const uint4& rhs ) {
	return bool4(
		lhs.x <= rhs.x,
		lhs.y <= rhs.y,
		lhs.z <= rhs.z,
		lhs.w <= rhs.w
	);
}

bool4 operator>( const uint4& lhs, const uint4& rhs ) {
	return bool4(
		lhs.x > rhs.x,
		lhs.y > rhs.y,
		lhs.z > rhs.z,
		lhs.w > rhs.w
	);
}

bool4 operator>=( const uint4& lhs, const uint4& rhs ) {
	return bool4(
		lhs.x >= rhs.x,
		lhs.y >= rhs.y,
		lhs.z >= rhs.z,
		lhs.w >= rhs.w
	);
}


// float2
float2 float2::operator+( const float rhs ) const {
	return float2(
		x + rhs,
		y + rhs
	);
}

float2 float2::operator+=( const float rhs ) {
	return ( *this = *this + rhs );
}

float2 float2::operator+( const float2& rhs ) const {
	return float2(
		x + rhs.x,
		y + rhs.y
	);
}

float2 float2::operator+=( const float2& rhs ) {
	return ( *this = *this + rhs );
}

float2 float2::operator-( const float rhs ) const {
	return float2(
		x - rhs,
		y - rhs
	);
}

float2 float2::operator-=( const float rhs ) {
	return ( *this = *this - rhs );
}

float2 float2::operator-( const float2& rhs ) const {
	return float2(
		x - rhs.x,
		y - rhs.y
	);
}

float2 float2::operator-=( const float2& rhs ) {
	return ( *this = *this - rhs );
}

float2 float2::operator*( const float rhs ) const {
	return float2(
		x * rhs,
		y * rhs
	);
}

float2 float2::operator*=( const float rhs ) {
	return ( *this = *this * rhs );
}

float2 float2::operator*( const float2& rhs ) const {
	return float2(
		x * rhs.x,
		y * rhs.y
	);
}

float2 float2::operator*=( const float2& rhs ) {
	return ( *this = *this * rhs );
}

float2 float2::operator/( const float rhs ) const {
	return float2(
		x / rhs,
		y / rhs
	);
}

float2 float2::operator/=( const float rhs ) {
	return ( *this = *this / rhs );
}

float2 float2::operator/( const float2& rhs ) const {
	return float2(
		x / rhs.x,
		y / rhs.y
	);
}

float2 float2::operator/=( const float2& rhs ) {
	return ( *this = *this / rhs );
}

bool2 operator<( const float2& lhs, const float2& rhs ) {
	return bool2(
		lhs.x < rhs.x,
		lhs.y < rhs.y
	);
}

bool2 operator<=( const float2& lhs, const float2& rhs ) {
	return bool2(
		lhs.x <= rhs.x,
		lhs.y <= rhs.y
	);
}

bool2 operator>( const float2& lhs, const float2& rhs ) {
	return bool2(
		lhs.x > rhs.x,
		lhs.y > rhs.y
	);
}

bool2 operator>=( const float2& lhs, const float2& rhs ) {
	return bool2(
		lhs.x >= rhs.x,
		lhs.y >= rhs.y
	);
}


// float3
float3 float3::operator+( const float rhs ) const {
	return float3(
		x + rhs,
		y + rhs,
		z + rhs
	);
}

float3 float3::operator+=( const float rhs ) {
	return ( *this = *this + rhs );
}

float3 float3::operator+( const float3& rhs ) const {
	return float3(
		x + rhs.x,
		y + rhs.y,
		z + rhs.z
	);
}

float3 float3::operator+=( const float3& rhs ) {
	return ( *this = *this + rhs );
}

float3 float3::operator-( const float rhs ) const {
	return float3(
		x - rhs,
		y - rhs,
		z - rhs
	);
}

float3 float3::operator-=( const float rhs ) {
	return ( *this = *this - rhs );
}

float3 float3::operator-( const float3& rhs ) const {
	return float3(
		x - rhs.x,
		y - rhs.y,
		z - rhs.z
	);
}

float3 float3::operator-=( const float3& rhs ) {
	return ( *this = *this - rhs );
}

float3 float3::operator*( const float rhs ) const {
	return float3(
		x * rhs,
		y * rhs,
		z * rhs
	);
}

float3 float3::operator*=( const float rhs ) {
	return ( *this = *this * rhs );
}

float3 float3::operator*( const float3& rhs ) const {
	return float3(
		x * rhs.x,
		y * rhs.y,
		z * rhs.z
	);
}

float3 float3::operator*=( const float3& rhs ) {
	return ( *this = *this * rhs );
}

float3 float3::operator/( const float rhs ) const {
	return float3(
		x / rhs,
		y / rhs,
		z / rhs
	);
}

float3 float3::operator/=( const float rhs ) {
	return ( *this = *this / rhs );
}

float3 float3::operator/( const float3& rhs ) const {
	return float3(
		x / rhs.x,
		y / rhs.y,
		z / rhs.z
	);
}

float3 float3::operator/=( const float3& rhs ) {
	return ( *this = *this / rhs );
}

bool3 operator<( const float3& lhs, const float3& rhs ) {
	return bool3(
		lhs.x < rhs.x,
		lhs.y < rhs.y,
		lhs.z < rhs.z
	);
}

bool3 operator<=( const float3& lhs, const float3& rhs ) {
	return bool3(
		lhs.x <= rhs.x,
		lhs.y <= rhs.y,
		lhs.z <= rhs.z
	);
}

bool3 operator>( const float3& lhs, const float3& rhs ) {
	return bool3(
		lhs.x > rhs.x,
		lhs.y > rhs.y,
		lhs.z > rhs.z
	);
}

bool3 operator>=( const float3& lhs, const float3& rhs ) {
	return bool3(
		lhs.x >= rhs.x,
		lhs.y >= rhs.y,
		lhs.z >= rhs.z
	);
}


// float4
float4 float4::operator+( const float rhs ) const {
	return float4(
		x + rhs,
		y + rhs,
		z + rhs,
		w + rhs
	);
}

float4 float4::operator+=( const float rhs ) {
	return ( *this = *this + rhs );
}

float4 float4::operator+( const float4& rhs ) const {
	return float4(
		x + rhs.x,
		y + rhs.y,
		z + rhs.z,
		w + rhs.w
	);
}

float4 float4::operator+=( const float4& rhs ) {
	return ( *this = *this + rhs );
}

float4 float4::operator-( const float rhs ) const {
	return float4(
		x - rhs,
		y - rhs,
		z - rhs,
		w - rhs
	);
}

float4 float4::operator-=( const float rhs ) {
	return ( *this = *this - rhs );
}

float4 float4::operator-( const float4& rhs ) const {
	return float4(
		x - rhs.x,
		y - rhs.y,
		z - rhs.z,
		w - rhs.w
	);
}

float4 float4::operator-=( const float4& rhs ) {
	return ( *this = *this - rhs );
}

float4 float4::operator*( const float rhs ) const {
	return float4(
		x * rhs,
		y * rhs,
		z * rhs,
		w * rhs
	);
}

float4 float4::operator*=( const float rhs ) {
	return ( *this = *this * rhs );
}

float4 float4::operator*( const float4& rhs ) const {
	return float4(
		x * rhs.x,
		y * rhs.y,
		z * rhs.z,
		w * rhs.w
	);
}

float4 float4::operator*=( const float4& rhs ) {
	return ( *this = *this * rhs );
}

float4 float4::operator/( const float rhs ) const {
	return float4(
		x / rhs,
		y / rhs,
		z / rhs,
		w / rhs
	);
}

float4 float4::operator/=( const float rhs ) {
	return ( *this = *this / rhs );
}

float4 float4::operator/( const float4& rhs ) const {
	return float4(
		x / rhs.x,
		y / rhs.y,
		z / rhs.z,
		w / rhs.w
	);
}

float4 float4::operator/=( const float4& rhs ) {
	return ( *this = *this / rhs );
}

bool4 operator<( const float4& lhs, const float4& rhs ) {
	return bool4(
		lhs.x < rhs.x,
		lhs.y < rhs.y,
		lhs.z < rhs.z,
		lhs.w < rhs.w
	);
}

bool4 operator<=( const float4& lhs, const float4& rhs ) {
	return bool4(
		lhs.x <= rhs.x,
		lhs.y <= rhs.y,
		lhs.z <= rhs.z,
		lhs.w <= rhs.w
	);
}

bool4 operator>( const float4& lhs, const float4& rhs ) {
	return bool4(
		lhs.x > rhs.x,
		lhs.y > rhs.y,
		lhs.z > rhs.z,
		lhs.w > rhs.w
	);
}

bool4 operator>=( const float4& lhs, const float4& rhs ) {
	return bool4(
		lhs.x >= rhs.x,
		lhs.y >= rhs.y,
		lhs.z >= rhs.z,
		lhs.w >= rhs.w
	);
}


// double2
double2 double2::operator+( const double rhs ) const {
	return double2(
		x + rhs,
		y + rhs
	);
}

double2 double2::operator+=( const double rhs ) {
	return ( *this = *this + rhs );
}

double2 double2::operator+( const double2& rhs ) const {
	return double2(
		x + rhs.x,
		y + rhs.y
	);
}

double2 double2::operator+=( const double2& rhs ) {
	return ( *this = *this + rhs );
}

double2 double2::operator-( const double rhs ) const {
	return double2(
		x - rhs,
		y - rhs
	);
}

double2 double2::operator-=( const double rhs ) {
	return ( *this = *this - rhs );
}

double2 double2::operator-( const double2& rhs ) const {
	return double2(
		x - rhs.x,
		y - rhs.y
	);
}

double2 double2::operator-=( const double2& rhs ) {
	return ( *this = *this - rhs );
}

double2 double2::operator*( const double rhs ) const {
	return double2(
		x * rhs,
		y * rhs
	);
}

double2 double2::operator*=( const double rhs ) {
	return ( *this = *this * rhs );
}

double2 double2::operator*( const double2& rhs ) const {
	return double2(
		x * rhs.x,
		y * rhs.y
	);
}

double2 double2::operator*=( const double2& rhs ) {
	return ( *this = *this * rhs );
}

double2 double2::operator/( const double rhs ) const {
	return double2(
		x / rhs,
		y / rhs
	);
}

double2 double2::operator/=( const double rhs ) {
	return ( *this = *this / rhs );
}

double2 double2::operator/( const double2& rhs ) const {
	return double2(
		x / rhs.x,
		y / rhs.y
	);
}

double2 double2::operator/=( const double2& rhs ) {
	return ( *this = *this / rhs );
}

bool2 operator<( const double2& lhs, const double2& rhs ) {
	return bool2(
		lhs.x < rhs.x,
		lhs.y < rhs.y
	);
}

bool2 operator<=( const double2& lhs, const double2& rhs ) {
	return bool2(
		lhs.x <= rhs.x,
		lhs.y <= rhs.y
	);
}

bool2 operator>( const double2& lhs, const double2& rhs ) {
	return bool2(
		lhs.x > rhs.x,
		lhs.y > rhs.y
	);
}

bool2 operator>=( const double2& lhs, const double2& rhs ) {
	return bool2(
		lhs.x >= rhs.x,
		lhs.y >= rhs.y
	);
}


// double3
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


// double4
double4 double4::operator+( const double rhs ) const {
	return double4(
		x + rhs,
		y + rhs,
		z + rhs,
		w + rhs
	);
}

double4 double4::operator+=( const double rhs ) {
	return ( *this = *this + rhs );
}

double4 double4::operator+( const double4& rhs ) const {
	return double4(
		x + rhs.x,
		y + rhs.y,
		z + rhs.z,
		w + rhs.w
	);
}

double4 double4::operator+=( const double4& rhs ) {
	return ( *this = *this + rhs );
}

double4 double4::operator-( const double rhs ) const {
	return double4(
		x - rhs,
		y - rhs,
		z - rhs,
		w - rhs
	);
}

double4 double4::operator-=( const double rhs ) {
	return ( *this = *this - rhs );
}

double4 double4::operator-( const double4& rhs ) const {
	return double4(
		x - rhs.x,
		y - rhs.y,
		z - rhs.z,
		w - rhs.w
	);
}

double4 double4::operator-=( const double4& rhs ) {
	return ( *this = *this - rhs );
}

double4 double4::operator*( const double rhs ) const {
	return double4(
		x * rhs,
		y * rhs,
		z * rhs,
		w * rhs
	);
}

double4 double4::operator*=( const double rhs ) {
	return ( *this = *this * rhs );
}

double4 double4::operator*( const double4& rhs ) const {
	return double4(
		x * rhs.x,
		y * rhs.y,
		z * rhs.z,
		w * rhs.w
	);
}

double4 double4::operator*=( const double4& rhs ) {
	return ( *this = *this * rhs );
}

double4 double4::operator/( const double rhs ) const {
	return double4(
		x / rhs,
		y / rhs,
		z / rhs,
		w / rhs
	);
}

double4 double4::operator/=( const double rhs ) {
	return ( *this = *this / rhs );
}

double4 double4::operator/( const double4& rhs ) const {
	return double4(
		x / rhs.x,
		y / rhs.y,
		z / rhs.z,
		w / rhs.w
	);
}

double4 double4::operator/=( const double4& rhs ) {
	return ( *this = *this / rhs );
}

bool4 operator<( const double4& lhs, const double4& rhs ) {
	return bool4(
		lhs.x < rhs.x,
		lhs.y < rhs.y,
		lhs.z < rhs.z,
		lhs.w < rhs.w
	);
}

bool4 operator<=( const double4& lhs, const double4& rhs ) {
	return bool4(
		lhs.x <= rhs.x,
		lhs.y <= rhs.y,
		lhs.z <= rhs.z,
		lhs.w <= rhs.w
	);
}

bool4 operator>( const double4& lhs, const double4& rhs ) {
	return bool4(
		lhs.x > rhs.x,
		lhs.y > rhs.y,
		lhs.z > rhs.z,
		lhs.w > rhs.w
	);
}

bool4 operator>=( const double4& lhs, const double4& rhs ) {
	return bool4(
		lhs.x >= rhs.x,
		lhs.y >= rhs.y,
		lhs.z >= rhs.z,
		lhs.w >= rhs.w
	);
}



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


// int2
float dot( const int2& lhs, const int2& rhs ) {
	return ( lhs.x * rhs.x ) + ( lhs.y * rhs.y );
}

float lengthsqr( const int2& vec ) {
	return dot( vec, vec );
}

float length( const int2& vec ) {
	return sqrtf( lengthsqr( vec ) );
}


// int3
float dot( const int3& lhs, const int3& rhs ) {
	return ( lhs.x * rhs.x ) + ( lhs.y * rhs.y ) + ( lhs.z * rhs.z );
}

float lengthsqr( const int3& vec ) {
	return dot( vec, vec );
}

float length( const int3& vec ) {
	return sqrtf( lengthsqr( vec ) );
}


// int4
float dot( const int4& lhs, const int4& rhs ) {
	return ( lhs.x * rhs.x ) + ( lhs.y * rhs.y ) + ( lhs.z * rhs.z ) + ( lhs.w * rhs.w );
}

float lengthsqr( const int4& vec ) {
	return dot( vec, vec );
}

float length( const int4& vec ) {
	return sqrtf( lengthsqr( vec ) );
}


// uint2
float dot( const uint2& lhs, const uint2& rhs ) {
	return ( lhs.x * rhs.x ) + ( lhs.y * rhs.y );
}

float lengthsqr( const uint2& vec ) {
	return dot( vec, vec );
}

float length( const uint2& vec ) {
	return sqrtf( lengthsqr( vec ) );
}


// uint3
float dot( const uint3& lhs, const uint3& rhs ) {
	return ( lhs.x * rhs.x ) + ( lhs.y * rhs.y ) + ( lhs.z * rhs.z );
}

float lengthsqr( const uint3& vec ) {
	return dot( vec, vec );
}

float length( const uint3& vec ) {
	return sqrtf( lengthsqr( vec ) );
}


// uint4
float dot( const uint4& lhs, const uint4& rhs ) {
	return ( lhs.x * rhs.x ) + ( lhs.y * rhs.y ) + ( lhs.z * rhs.z ) + ( lhs.w * rhs.w );
}

float lengthsqr( const uint4& vec ) {
	return dot( vec, vec );
}

float length( const uint4& vec ) {
	return sqrtf( lengthsqr( vec ) );
}


// float2
float dot( const float2& lhs, const float2& rhs ) {
	return ( lhs.x * rhs.x ) + ( lhs.y * rhs.y );
}

float lengthsqr( const float2& vec ) {
	return dot( vec, vec );
}

float length( const float2& vec ) {
	return sqrtf( lengthsqr( vec ) );
}

void normalize( float2& vec ) {
	float invlen = 1.0f / length( vec );
	vec *= invlen;
}

float2 normalized( const float2& vec ) {
	float invlen = 1.0f / length( vec );
	return (float2) vec * invlen;
}


// float3
float dot( const float3& lhs, const float3& rhs ) {
	return ( lhs.x * rhs.x ) + ( lhs.y * rhs.y ) + ( lhs.z * rhs.z );
}

float lengthsqr( const float3& vec ) {
	return dot( vec, vec );
}

float length( const float3& vec ) {
	return sqrtf( lengthsqr( vec ) );
}

void normalize( float3& vec ) {
	float invlen = 1.0f / length( vec );
	vec *= invlen;
}

float3 normalized( const float3& vec ) {
	float invlen = 1.0f / length( vec );
	return (float3) vec * invlen;
}

float3 cross( const float3& lhs, const float3& rhs ) {
	return float3(
		( lhs.y * rhs.z ) - ( lhs.z * rhs.y ),
		( lhs.z * rhs.x ) - ( lhs.x * rhs.z ),
		( lhs.x * rhs.y ) - ( lhs.y * rhs.x )
	);
}


// float4
float dot( const float4& lhs, const float4& rhs ) {
	return ( lhs.x * rhs.x ) + ( lhs.y * rhs.y ) + ( lhs.z * rhs.z ) + ( lhs.w * rhs.w );
}

float lengthsqr( const float4& vec ) {
	return dot( vec, vec );
}

float length( const float4& vec ) {
	return sqrtf( lengthsqr( vec ) );
}

void normalize( float4& vec ) {
	float invlen = 1.0f / length( vec );
	vec *= invlen;
}

float4 normalized( const float4& vec ) {
	float invlen = 1.0f / length( vec );
	return (float4) vec * invlen;
}

float4 cross( const float4& lhs, const float4& rhs ) {
	return float4(
		( lhs.y * rhs.z ) - ( lhs.z * rhs.y ),
		( lhs.z * rhs.x ) - ( lhs.x * rhs.z ),
		( lhs.x * rhs.y ) - ( lhs.y * rhs.x ),
		0.0f
	);
}


// double2
double dot( const double2& lhs, const double2& rhs ) {
	return ( lhs.x * rhs.x ) + ( lhs.y * rhs.y );
}

double lengthsqr( const double2& vec ) {
	return dot( vec, vec );
}

double length( const double2& vec ) {
	return sqrt( lengthsqr( vec ) );
}

void normalize( double2& vec ) {
	double invlen = 1.0 / length( vec );
	vec *= invlen;
}

double2 normalized( const double2& vec ) {
	double invlen = 1.0 / length( vec );
	return (double2) vec * invlen;
}


// double3
double dot( const double3& lhs, const double3& rhs ) {
	return ( lhs.x * rhs.x ) + ( lhs.y * rhs.y ) + ( lhs.z * rhs.z );
}

double lengthsqr( const double3& vec ) {
	return dot( vec, vec );
}

double length( const double3& vec ) {
	return sqrt( lengthsqr( vec ) );
}

void normalize( double3& vec ) {
	double invlen = 1.0 / length( vec );
	vec *= invlen;
}

double3 normalized( const double3& vec ) {
	double invlen = 1.0 / length( vec );
	return (double3) vec * invlen;
}

double3 cross( const double3& lhs, const double3& rhs ) {
	return double3(
		( lhs.y * rhs.z ) - ( lhs.z * rhs.y ),
		( lhs.z * rhs.x ) - ( lhs.x * rhs.z ),
		( lhs.x * rhs.y ) - ( lhs.y * rhs.x )
	);
}


// double4
double dot( const double4& lhs, const double4& rhs ) {
	return ( lhs.x * rhs.x ) + ( lhs.y * rhs.y ) + ( lhs.z * rhs.z ) + ( lhs.w * rhs.w );
}

double lengthsqr( const double4& vec ) {
	return dot( vec, vec );
}

double length( const double4& vec ) {
	return sqrt( lengthsqr( vec ) );
}

void normalize( double4& vec ) {
	double invlen = 1.0 / length( vec );
	vec *= invlen;
}

double4 normalized( const double4& vec ) {
	double invlen = 1.0 / length( vec );
	return (double4) vec * invlen;
}

double4 cross( const double4& lhs, const double4& rhs ) {
	return double4(
		( lhs.y * rhs.z ) - ( lhs.z * rhs.y ),
		( lhs.z * rhs.x ) - ( lhs.x * rhs.z ),
		( lhs.x * rhs.y ) - ( lhs.y * rhs.x ),
		0.0
	);
}



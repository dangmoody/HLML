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
float dot( const int2& lhs, const int2& rhs )
{
	return ( lhs.x * rhs.x ) + ( lhs.y * rhs.y );
}

float lengthsqr( const int2& vec )
{
	return ( vec.x * vec.x ) + ( vec.y * vec.y );
}

float length( const int2& vec )
{
	return sqrtf( lengthsqr( vec ) );
}

float distancesqr( const int2& lhs, const int2& rhs )
{
	return lengthsqr( lhs - rhs );
}

float distance( const int2& lhs, const int2& rhs )
{
	return length( lhs - rhs );
}


// int3
float dot( const int3& lhs, const int3& rhs )
{
	return ( lhs.x * rhs.x ) + ( lhs.y * rhs.y ) + ( lhs.z * rhs.z );
}

float lengthsqr( const int3& vec )
{
	return ( vec.x * vec.x ) + ( vec.y * vec.y ) + ( vec.z * vec.z );
}

float length( const int3& vec )
{
	return sqrtf( lengthsqr( vec ) );
}

float distancesqr( const int3& lhs, const int3& rhs )
{
	return lengthsqr( lhs - rhs );
}

float distance( const int3& lhs, const int3& rhs )
{
	return length( lhs - rhs );
}


// int4
float dot( const int4& lhs, const int4& rhs )
{
	return ( lhs.x * rhs.x ) + ( lhs.y * rhs.y ) + ( lhs.z * rhs.z ) + ( lhs.w * rhs.w );
}

float lengthsqr( const int4& vec )
{
	return ( vec.x * vec.x ) + ( vec.y * vec.y ) + ( vec.z * vec.z ) + ( vec.w * vec.w );
}

float length( const int4& vec )
{
	return sqrtf( lengthsqr( vec ) );
}


// uint2
float dot( const uint2& lhs, const uint2& rhs )
{
	return ( lhs.x * rhs.x ) + ( lhs.y * rhs.y );
}

float lengthsqr( const uint2& vec )
{
	return ( vec.x * vec.x ) + ( vec.y * vec.y );
}

float length( const uint2& vec )
{
	return sqrtf( lengthsqr( vec ) );
}

float distancesqr( const uint2& lhs, const uint2& rhs )
{
	return lengthsqr( lhs - rhs );
}

float distance( const uint2& lhs, const uint2& rhs )
{
	return length( lhs - rhs );
}


// uint3
float dot( const uint3& lhs, const uint3& rhs )
{
	return ( lhs.x * rhs.x ) + ( lhs.y * rhs.y ) + ( lhs.z * rhs.z );
}

float lengthsqr( const uint3& vec )
{
	return ( vec.x * vec.x ) + ( vec.y * vec.y ) + ( vec.z * vec.z );
}

float length( const uint3& vec )
{
	return sqrtf( lengthsqr( vec ) );
}

float distancesqr( const uint3& lhs, const uint3& rhs )
{
	return lengthsqr( lhs - rhs );
}

float distance( const uint3& lhs, const uint3& rhs )
{
	return length( lhs - rhs );
}


// uint4
float dot( const uint4& lhs, const uint4& rhs )
{
	return ( lhs.x * rhs.x ) + ( lhs.y * rhs.y ) + ( lhs.z * rhs.z ) + ( lhs.w * rhs.w );
}

float lengthsqr( const uint4& vec )
{
	return ( vec.x * vec.x ) + ( vec.y * vec.y ) + ( vec.z * vec.z ) + ( vec.w * vec.w );
}

float length( const uint4& vec )
{
	return sqrtf( lengthsqr( vec ) );
}

uint32_t pack( const uint4& vec )
{
	return ( vec.x << 24 ) | ( vec.y << 16 ) | ( vec.z << 8 ) | ( vec.w << 0 );
}

uint4 unpack( const uint32_t x )
{
	return uint4(
		( x >> 24 ) & 0xFF,
		( x >> 16 ) & 0xFF,
		( x >> 8 ) & 0xFF,
		( x >> 0 ) & 0xFF
	);
}


// float2
float2 saturate( const float2& x )
{
	return float2(
		clamp( x[0], 0.000000f, 1.000000f ),
		clamp( x[1], 0.000000f, 1.000000f )
	);
}

float2 lerp( const float2& a, const float2& b, const float t )
{
	return float2(
		lerp( a[0], b[0], t ),
		lerp( a[1], b[1], t )
	);
}

float2 smoothstep( const float2& low, const float2& high, const float2& x )
{
	return float2(
		smoothstep( low[0], high[0], x[0] ),
		smoothstep( low[1], high[1], x[1] )
	);
}

float2 smootherstep( const float2& low, const float2& high, const float2& x )
{
	return float2(
		smootherstep( low[0], high[0], x[0] ),
		smootherstep( low[1], high[1], x[1] )
	);
}

float dot( const float2& lhs, const float2& rhs )
{
	return ( lhs.x * rhs.x ) + ( lhs.y * rhs.y );
}

float lengthsqr( const float2& vec )
{
	return ( vec.x * vec.x ) + ( vec.y * vec.y );
}

float length( const float2& vec )
{
	return sqrtf( lengthsqr( vec ) );
}

void normalize( float2& vec )
{
	float invlen = 1.000000f / length( vec );
	vec *= invlen;
}

float2 normalized( const float2& vec )
{
	float invlen = 1.000000f / length( vec );
	return (float2)( vec * invlen );
}

float angle( const float2& lhs, const float2& rhs )
{
	return degrees( acosf( dot( normalized( lhs ), normalized( rhs ) ) ) );
}

float distancesqr( const float2& lhs, const float2& rhs )
{
	return lengthsqr( lhs - rhs );
}

float distance( const float2& lhs, const float2& rhs )
{
	return length( lhs - rhs );
}


// float3
float3 saturate( const float3& x )
{
	return float3(
		clamp( x[0], 0.000000f, 1.000000f ),
		clamp( x[1], 0.000000f, 1.000000f ),
		clamp( x[2], 0.000000f, 1.000000f )
	);
}

float3 lerp( const float3& a, const float3& b, const float t )
{
	return float3(
		lerp( a[0], b[0], t ),
		lerp( a[1], b[1], t ),
		lerp( a[2], b[2], t )
	);
}

float3 smoothstep( const float3& low, const float3& high, const float3& x )
{
	return float3(
		smoothstep( low[0], high[0], x[0] ),
		smoothstep( low[1], high[1], x[1] ),
		smoothstep( low[2], high[2], x[2] )
	);
}

float3 smootherstep( const float3& low, const float3& high, const float3& x )
{
	return float3(
		smootherstep( low[0], high[0], x[0] ),
		smootherstep( low[1], high[1], x[1] ),
		smootherstep( low[2], high[2], x[2] )
	);
}

float dot( const float3& lhs, const float3& rhs )
{
	return ( lhs.x * rhs.x ) + ( lhs.y * rhs.y ) + ( lhs.z * rhs.z );
}

float lengthsqr( const float3& vec )
{
	return ( vec.x * vec.x ) + ( vec.y * vec.y ) + ( vec.z * vec.z );
}

float length( const float3& vec )
{
	return sqrtf( lengthsqr( vec ) );
}

void normalize( float3& vec )
{
	float invlen = 1.000000f / length( vec );
	vec *= invlen;
}

float3 normalized( const float3& vec )
{
	float invlen = 1.000000f / length( vec );
	return (float3)( vec * invlen );
}

float3 cross( const float3& lhs, const float3& rhs )
{
	return float3(
		( lhs.y * rhs.z ) - ( lhs.z * rhs.y ),
		( lhs.z * rhs.x ) - ( lhs.x * rhs.z ),
		( lhs.x * rhs.y ) - ( lhs.y * rhs.x )
	);
}

float angle( const float3& lhs, const float3& rhs )
{
	return degrees( acosf( dot( normalized( lhs ), normalized( rhs ) ) ) );
}

float distancesqr( const float3& lhs, const float3& rhs )
{
	return lengthsqr( lhs - rhs );
}

float distance( const float3& lhs, const float3& rhs )
{
	return length( lhs - rhs );
}


// float4
float4 saturate( const float4& x )
{
	return float4(
		clamp( x[0], 0.000000f, 1.000000f ),
		clamp( x[1], 0.000000f, 1.000000f ),
		clamp( x[2], 0.000000f, 1.000000f ),
		clamp( x[3], 0.000000f, 1.000000f )
	);
}

float4 lerp( const float4& a, const float4& b, const float t )
{
	return float4(
		lerp( a[0], b[0], t ),
		lerp( a[1], b[1], t ),
		lerp( a[2], b[2], t ),
		lerp( a[3], b[3], t )
	);
}

float4 smoothstep( const float4& low, const float4& high, const float4& x )
{
	return float4(
		smoothstep( low[0], high[0], x[0] ),
		smoothstep( low[1], high[1], x[1] ),
		smoothstep( low[2], high[2], x[2] ),
		smoothstep( low[3], high[3], x[3] )
	);
}

float4 smootherstep( const float4& low, const float4& high, const float4& x )
{
	return float4(
		smootherstep( low[0], high[0], x[0] ),
		smootherstep( low[1], high[1], x[1] ),
		smootherstep( low[2], high[2], x[2] ),
		smootherstep( low[3], high[3], x[3] )
	);
}

float dot( const float4& lhs, const float4& rhs )
{
	return ( lhs.x * rhs.x ) + ( lhs.y * rhs.y ) + ( lhs.z * rhs.z ) + ( lhs.w * rhs.w );
}

float lengthsqr( const float4& vec )
{
	return ( vec.x * vec.x ) + ( vec.y * vec.y ) + ( vec.z * vec.z ) + ( vec.w * vec.w );
}

float length( const float4& vec )
{
	return sqrtf( lengthsqr( vec ) );
}

void normalize( float4& vec )
{
	float invlen = 1.000000f / length( vec );
	vec *= invlen;
}

float4 normalized( const float4& vec )
{
	float invlen = 1.000000f / length( vec );
	return (float4)( vec * invlen );
}

float4 cross( const float4& lhs, const float4& rhs )
{
	return float4(
		( lhs.y * rhs.z ) - ( lhs.z * rhs.y ),
		( lhs.z * rhs.x ) - ( lhs.x * rhs.z ),
		( lhs.x * rhs.y ) - ( lhs.y * rhs.x ),
		0.0f
	);
}

float angle( const float4& lhs, const float4& rhs )
{
	return degrees( acosf( dot( normalized( lhs ), normalized( rhs ) ) ) );
}


// double2
double2 saturate( const double2& x )
{
	return double2(
		clamp( x[0], 0.000000, 1.000000 ),
		clamp( x[1], 0.000000, 1.000000 )
	);
}

double2 lerp( const double2& a, const double2& b, const double t )
{
	return double2(
		lerp( a[0], b[0], t ),
		lerp( a[1], b[1], t )
	);
}

double2 smoothstep( const double2& low, const double2& high, const double2& x )
{
	return double2(
		smoothstep( low[0], high[0], x[0] ),
		smoothstep( low[1], high[1], x[1] )
	);
}

double2 smootherstep( const double2& low, const double2& high, const double2& x )
{
	return double2(
		smootherstep( low[0], high[0], x[0] ),
		smootherstep( low[1], high[1], x[1] )
	);
}

double dot( const double2& lhs, const double2& rhs )
{
	return ( lhs.x * rhs.x ) + ( lhs.y * rhs.y );
}

double lengthsqr( const double2& vec )
{
	return ( vec.x * vec.x ) + ( vec.y * vec.y );
}

double length( const double2& vec )
{
	return sqrt( lengthsqr( vec ) );
}

void normalize( double2& vec )
{
	double invlen = 1.000000 / length( vec );
	vec *= invlen;
}

double2 normalized( const double2& vec )
{
	double invlen = 1.000000 / length( vec );
	return (double2)( vec * invlen );
}

double angle( const double2& lhs, const double2& rhs )
{
	return degrees( acos( dot( normalized( lhs ), normalized( rhs ) ) ) );
}

double distancesqr( const double2& lhs, const double2& rhs )
{
	return lengthsqr( lhs - rhs );
}

double distance( const double2& lhs, const double2& rhs )
{
	return length( lhs - rhs );
}


// double3
double3 saturate( const double3& x )
{
	return double3(
		clamp( x[0], 0.000000, 1.000000 ),
		clamp( x[1], 0.000000, 1.000000 ),
		clamp( x[2], 0.000000, 1.000000 )
	);
}

double3 lerp( const double3& a, const double3& b, const double t )
{
	return double3(
		lerp( a[0], b[0], t ),
		lerp( a[1], b[1], t ),
		lerp( a[2], b[2], t )
	);
}

double3 smoothstep( const double3& low, const double3& high, const double3& x )
{
	return double3(
		smoothstep( low[0], high[0], x[0] ),
		smoothstep( low[1], high[1], x[1] ),
		smoothstep( low[2], high[2], x[2] )
	);
}

double3 smootherstep( const double3& low, const double3& high, const double3& x )
{
	return double3(
		smootherstep( low[0], high[0], x[0] ),
		smootherstep( low[1], high[1], x[1] ),
		smootherstep( low[2], high[2], x[2] )
	);
}

double dot( const double3& lhs, const double3& rhs )
{
	return ( lhs.x * rhs.x ) + ( lhs.y * rhs.y ) + ( lhs.z * rhs.z );
}

double lengthsqr( const double3& vec )
{
	return ( vec.x * vec.x ) + ( vec.y * vec.y ) + ( vec.z * vec.z );
}

double length( const double3& vec )
{
	return sqrt( lengthsqr( vec ) );
}

void normalize( double3& vec )
{
	double invlen = 1.000000 / length( vec );
	vec *= invlen;
}

double3 normalized( const double3& vec )
{
	double invlen = 1.000000 / length( vec );
	return (double3)( vec * invlen );
}

double3 cross( const double3& lhs, const double3& rhs )
{
	return double3(
		( lhs.y * rhs.z ) - ( lhs.z * rhs.y ),
		( lhs.z * rhs.x ) - ( lhs.x * rhs.z ),
		( lhs.x * rhs.y ) - ( lhs.y * rhs.x )
	);
}

double angle( const double3& lhs, const double3& rhs )
{
	return degrees( acos( dot( normalized( lhs ), normalized( rhs ) ) ) );
}

double distancesqr( const double3& lhs, const double3& rhs )
{
	return lengthsqr( lhs - rhs );
}

double distance( const double3& lhs, const double3& rhs )
{
	return length( lhs - rhs );
}


// double4
double4 saturate( const double4& x )
{
	return double4(
		clamp( x[0], 0.000000, 1.000000 ),
		clamp( x[1], 0.000000, 1.000000 ),
		clamp( x[2], 0.000000, 1.000000 ),
		clamp( x[3], 0.000000, 1.000000 )
	);
}

double4 lerp( const double4& a, const double4& b, const double t )
{
	return double4(
		lerp( a[0], b[0], t ),
		lerp( a[1], b[1], t ),
		lerp( a[2], b[2], t ),
		lerp( a[3], b[3], t )
	);
}

double4 smoothstep( const double4& low, const double4& high, const double4& x )
{
	return double4(
		smoothstep( low[0], high[0], x[0] ),
		smoothstep( low[1], high[1], x[1] ),
		smoothstep( low[2], high[2], x[2] ),
		smoothstep( low[3], high[3], x[3] )
	);
}

double4 smootherstep( const double4& low, const double4& high, const double4& x )
{
	return double4(
		smootherstep( low[0], high[0], x[0] ),
		smootherstep( low[1], high[1], x[1] ),
		smootherstep( low[2], high[2], x[2] ),
		smootherstep( low[3], high[3], x[3] )
	);
}

double dot( const double4& lhs, const double4& rhs )
{
	return ( lhs.x * rhs.x ) + ( lhs.y * rhs.y ) + ( lhs.z * rhs.z ) + ( lhs.w * rhs.w );
}

double lengthsqr( const double4& vec )
{
	return ( vec.x * vec.x ) + ( vec.y * vec.y ) + ( vec.z * vec.z ) + ( vec.w * vec.w );
}

double length( const double4& vec )
{
	return sqrt( lengthsqr( vec ) );
}

void normalize( double4& vec )
{
	double invlen = 1.000000 / length( vec );
	vec *= invlen;
}

double4 normalized( const double4& vec )
{
	double invlen = 1.000000 / length( vec );
	return (double4)( vec * invlen );
}

double4 cross( const double4& lhs, const double4& rhs )
{
	return double4(
		( lhs.y * rhs.z ) - ( lhs.z * rhs.y ),
		( lhs.z * rhs.x ) - ( lhs.x * rhs.z ),
		( lhs.x * rhs.y ) - ( lhs.y * rhs.x ),
		0.0
	);
}

double angle( const double4& lhs, const double4& rhs )
{
	return degrees( acos( dot( normalized( lhs ), normalized( rhs ) ) ) );
}



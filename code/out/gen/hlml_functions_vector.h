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

#pragma once

#include "int2.h"
#include "int3.h"
#include "int4.h"
#include "uint2.h"
#include "uint3.h"
#include "uint4.h"
#include "float2.h"
#include "float3.h"
#include "float4.h"
#include "double2.h"
#include "double3.h"
#include "double4.h"

// int2
/// \relates int2
/// \brief Returns the dot product of the two vectors.
inline int32_t dot( const int2& lhs, const int2& rhs );

/// \relates int2
/// \brief Returns the magnitude of the vector squared.
inline float lengthsqr( const int2& vec );

/// \relates int2
/// \brief Returns the magnitude of the vector.
inline float length( const int2& vec );

/// \relates int2
/// \brief Returns the squared distance between the two vectors.
inline float distancesqr( const int2& lhs, const int2& rhs );

/// \relates int2
/// \brief Returns the distance between the two vectors.
inline float distance( const int2& lhs, const int2& rhs );


// int3
/// \relates int3
/// \brief Returns the dot product of the two vectors.
inline int32_t dot( const int3& lhs, const int3& rhs );

/// \relates int3
/// \brief Returns the magnitude of the vector squared.
inline float lengthsqr( const int3& vec );

/// \relates int3
/// \brief Returns the magnitude of the vector.
inline float length( const int3& vec );

/// \relates int3
/// \brief Returns the squared distance between the two vectors.
inline float distancesqr( const int3& lhs, const int3& rhs );

/// \relates int3
/// \brief Returns the distance between the two vectors.
inline float distance( const int3& lhs, const int3& rhs );


// int4
/// \relates int4
/// \brief Returns the dot product of the two vectors.
inline int32_t dot( const int4& lhs, const int4& rhs );

/// \relates int4
/// \brief Returns the magnitude of the vector squared.
inline float lengthsqr( const int4& vec );

/// \relates int4
/// \brief Returns the magnitude of the vector.
inline float length( const int4& vec );


// uint2
/// \relates uint2
/// \brief Returns the dot product of the two vectors.
inline int32_t dot( const uint2& lhs, const uint2& rhs );

/// \relates uint2
/// \brief Returns the magnitude of the vector squared.
inline float lengthsqr( const uint2& vec );

/// \relates uint2
/// \brief Returns the magnitude of the vector.
inline float length( const uint2& vec );

/// \relates uint2
/// \brief Returns the squared distance between the two vectors.
inline float distancesqr( const uint2& lhs, const uint2& rhs );

/// \relates uint2
/// \brief Returns the distance between the two vectors.
inline float distance( const uint2& lhs, const uint2& rhs );


// uint3
/// \relates uint3
/// \brief Returns the dot product of the two vectors.
inline int32_t dot( const uint3& lhs, const uint3& rhs );

/// \relates uint3
/// \brief Returns the magnitude of the vector squared.
inline float lengthsqr( const uint3& vec );

/// \relates uint3
/// \brief Returns the magnitude of the vector.
inline float length( const uint3& vec );

/// \relates uint3
/// \brief Returns the squared distance between the two vectors.
inline float distancesqr( const uint3& lhs, const uint3& rhs );

/// \relates uint3
/// \brief Returns the distance between the two vectors.
inline float distance( const uint3& lhs, const uint3& rhs );


// uint4
/// \relates uint4
/// \brief Returns the dot product of the two vectors.
inline int32_t dot( const uint4& lhs, const uint4& rhs );

/// \relates uint4
/// \brief Returns the magnitude of the vector squared.
inline float lengthsqr( const uint4& vec );

/// \relates uint4
/// \brief Returns the magnitude of the vector.
inline float length( const uint4& vec );

/// \relates uint4
/// \brief Returns a 32 bit integer containing each component of the vector (starting with x) at each byte.
inline uint32_t pack( const uint4& vec );

/// \relates uint4
/// \brief Returns a 4-component integer vector containing each byte of the given integer.
inline uint4 unpack( const uint32_t x );


// float2
/// \relates float2
/// \brief Returns a copy of the float2 with each component clamped between the range 0 and 1.
inline float2 saturate( const float2& x );

/// \relates float2
/// \brief Returns a linearly interpolated float2 between types "a" and "b".
inline float2 lerp( const float2& a, const float2& b, const float t );

/// \relates float2
/// \brief Performs a sigmoid-like interpolation and clamp.
inline float2 smoothstep( const float2& low, const float2& high, const float2& x );

/// \relates float2
/// \brief Performs a 'smoother' version of smoothstep, as design by Ken Perlin.
/// https://en.wikipedia.org/wiki/Smoothstep#Variations 
inline float2 smootherstep( const float2& low, const float2& high, const float2& x );

/// \relates float2
/// \brief Returns the dot product of the two vectors.
inline float dot( const float2& lhs, const float2& rhs );

/// \relates float2
/// \brief Returns the magnitude of the vector squared.
inline float lengthsqr( const float2& vec );

/// \relates float2
/// \brief Returns the magnitude of the vector.
inline float length( const float2& vec );

/// \relates float2
/// \brief Normalizes the vector.
inline void normalize( float2& vec );

/// \relates float2
/// \brief Returns a normalized copy of the vector.
inline float2 normalized( const float2& vec );

/// \relates float2
/// \brief Returns the angle in degrees between the two vectors.
inline float angle( const float2& lhs, const float2& rhs );

/// \relates float2
/// \brief Returns the squared distance between the two vectors.
inline float distancesqr( const float2& lhs, const float2& rhs );

/// \relates float2
/// \brief Returns the distance between the two vectors.
inline float distance( const float2& lhs, const float2& rhs );


// float3
/// \relates float3
/// \brief Returns a copy of the float3 with each component clamped between the range 0 and 1.
inline float3 saturate( const float3& x );

/// \relates float3
/// \brief Returns a linearly interpolated float3 between types "a" and "b".
inline float3 lerp( const float3& a, const float3& b, const float t );

/// \relates float3
/// \brief Performs a sigmoid-like interpolation and clamp.
inline float3 smoothstep( const float3& low, const float3& high, const float3& x );

/// \relates float3
/// \brief Performs a 'smoother' version of smoothstep, as design by Ken Perlin.
/// https://en.wikipedia.org/wiki/Smoothstep#Variations 
inline float3 smootherstep( const float3& low, const float3& high, const float3& x );

/// \relates float3
/// \brief Returns the dot product of the two vectors.
inline float dot( const float3& lhs, const float3& rhs );

/// \relates float3
/// \brief Returns the magnitude of the vector squared.
inline float lengthsqr( const float3& vec );

/// \relates float3
/// \brief Returns the magnitude of the vector.
inline float length( const float3& vec );

/// \relates float3
/// \brief Normalizes the vector.
inline void normalize( float3& vec );

/// \relates float3
/// \brief Returns a normalized copy of the vector.
inline float3 normalized( const float3& vec );

/// \relates float3
/// \brief Returns a vector perpendicular (normal) to the two vectors.
inline float3 cross( const float3& lhs, const float3& rhs );

/// \relates float3
/// \brief Returns the angle in degrees between the two vectors.
inline float angle( const float3& lhs, const float3& rhs );

/// \relates float3
/// \brief Returns the squared distance between the two vectors.
inline float distancesqr( const float3& lhs, const float3& rhs );

/// \relates float3
/// \brief Returns the distance between the two vectors.
inline float distance( const float3& lhs, const float3& rhs );


// float4
/// \relates float4
/// \brief Returns a copy of the float4 with each component clamped between the range 0 and 1.
inline float4 saturate( const float4& x );

/// \relates float4
/// \brief Returns a linearly interpolated float4 between types "a" and "b".
inline float4 lerp( const float4& a, const float4& b, const float t );

/// \relates float4
/// \brief Performs a sigmoid-like interpolation and clamp.
inline float4 smoothstep( const float4& low, const float4& high, const float4& x );

/// \relates float4
/// \brief Performs a 'smoother' version of smoothstep, as design by Ken Perlin.
/// https://en.wikipedia.org/wiki/Smoothstep#Variations 
inline float4 smootherstep( const float4& low, const float4& high, const float4& x );

/// \relates float4
/// \brief Returns the dot product of the two vectors.
inline float dot( const float4& lhs, const float4& rhs );

/// \relates float4
/// \brief Returns the magnitude of the vector squared.
inline float lengthsqr( const float4& vec );

/// \relates float4
/// \brief Returns the magnitude of the vector.
inline float length( const float4& vec );

/// \relates float4
/// \brief Normalizes the vector.
inline void normalize( float4& vec );

/// \relates float4
/// \brief Returns a normalized copy of the vector.
inline float4 normalized( const float4& vec );

/// \relates float4
/// \brief Returns a vector perpendicular (normal) to the two vectors.
inline float4 cross( const float4& lhs, const float4& rhs );

/// \relates float4
/// \brief Returns the angle in degrees between the two vectors.
inline float angle( const float4& lhs, const float4& rhs );


// double2
/// \relates double2
/// \brief Returns a copy of the double2 with each component clamped between the range 0 and 1.
inline double2 saturate( const double2& x );

/// \relates double2
/// \brief Returns a linearly interpolated double2 between types "a" and "b".
inline double2 lerp( const double2& a, const double2& b, const double t );

/// \relates double2
/// \brief Performs a sigmoid-like interpolation and clamp.
inline double2 smoothstep( const double2& low, const double2& high, const double2& x );

/// \relates double2
/// \brief Performs a 'smoother' version of smoothstep, as design by Ken Perlin.
/// https://en.wikipedia.org/wiki/Smoothstep#Variations 
inline double2 smootherstep( const double2& low, const double2& high, const double2& x );

/// \relates double2
/// \brief Returns the dot product of the two vectors.
inline double dot( const double2& lhs, const double2& rhs );

/// \relates double2
/// \brief Returns the magnitude of the vector squared.
inline double lengthsqr( const double2& vec );

/// \relates double2
/// \brief Returns the magnitude of the vector.
inline double length( const double2& vec );

/// \relates double2
/// \brief Normalizes the vector.
inline void normalize( double2& vec );

/// \relates double2
/// \brief Returns a normalized copy of the vector.
inline double2 normalized( const double2& vec );

/// \relates double2
/// \brief Returns the angle in degrees between the two vectors.
inline double angle( const double2& lhs, const double2& rhs );

/// \relates double2
/// \brief Returns the squared distance between the two vectors.
inline double distancesqr( const double2& lhs, const double2& rhs );

/// \relates double2
/// \brief Returns the distance between the two vectors.
inline double distance( const double2& lhs, const double2& rhs );


// double3
/// \relates double3
/// \brief Returns a copy of the double3 with each component clamped between the range 0 and 1.
inline double3 saturate( const double3& x );

/// \relates double3
/// \brief Returns a linearly interpolated double3 between types "a" and "b".
inline double3 lerp( const double3& a, const double3& b, const double t );

/// \relates double3
/// \brief Performs a sigmoid-like interpolation and clamp.
inline double3 smoothstep( const double3& low, const double3& high, const double3& x );

/// \relates double3
/// \brief Performs a 'smoother' version of smoothstep, as design by Ken Perlin.
/// https://en.wikipedia.org/wiki/Smoothstep#Variations 
inline double3 smootherstep( const double3& low, const double3& high, const double3& x );

/// \relates double3
/// \brief Returns the dot product of the two vectors.
inline double dot( const double3& lhs, const double3& rhs );

/// \relates double3
/// \brief Returns the magnitude of the vector squared.
inline double lengthsqr( const double3& vec );

/// \relates double3
/// \brief Returns the magnitude of the vector.
inline double length( const double3& vec );

/// \relates double3
/// \brief Normalizes the vector.
inline void normalize( double3& vec );

/// \relates double3
/// \brief Returns a normalized copy of the vector.
inline double3 normalized( const double3& vec );

/// \relates double3
/// \brief Returns a vector perpendicular (normal) to the two vectors.
inline double3 cross( const double3& lhs, const double3& rhs );

/// \relates double3
/// \brief Returns the angle in degrees between the two vectors.
inline double angle( const double3& lhs, const double3& rhs );

/// \relates double3
/// \brief Returns the squared distance between the two vectors.
inline double distancesqr( const double3& lhs, const double3& rhs );

/// \relates double3
/// \brief Returns the distance between the two vectors.
inline double distance( const double3& lhs, const double3& rhs );


// double4
/// \relates double4
/// \brief Returns a copy of the double4 with each component clamped between the range 0 and 1.
inline double4 saturate( const double4& x );

/// \relates double4
/// \brief Returns a linearly interpolated double4 between types "a" and "b".
inline double4 lerp( const double4& a, const double4& b, const double t );

/// \relates double4
/// \brief Performs a sigmoid-like interpolation and clamp.
inline double4 smoothstep( const double4& low, const double4& high, const double4& x );

/// \relates double4
/// \brief Performs a 'smoother' version of smoothstep, as design by Ken Perlin.
/// https://en.wikipedia.org/wiki/Smoothstep#Variations 
inline double4 smootherstep( const double4& low, const double4& high, const double4& x );

/// \relates double4
/// \brief Returns the dot product of the two vectors.
inline double dot( const double4& lhs, const double4& rhs );

/// \relates double4
/// \brief Returns the magnitude of the vector squared.
inline double lengthsqr( const double4& vec );

/// \relates double4
/// \brief Returns the magnitude of the vector.
inline double length( const double4& vec );

/// \relates double4
/// \brief Normalizes the vector.
inline void normalize( double4& vec );

/// \relates double4
/// \brief Returns a normalized copy of the vector.
inline double4 normalized( const double4& vec );

/// \relates double4
/// \brief Returns a vector perpendicular (normal) to the two vectors.
inline double4 cross( const double4& lhs, const double4& rhs );

/// \relates double4
/// \brief Returns the angle in degrees between the two vectors.
inline double angle( const double4& lhs, const double4& rhs );


#include "hlml_functions_vector.inl"

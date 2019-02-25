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

#include "bool2.h"
#include "bool3.h"
#include "bool4.h"
#include "bool2x2.h"
#include "bool3x2.h"
#include "bool4x2.h"
#include "bool2x3.h"
#include "bool3x3.h"
#include "bool4x3.h"
#include "bool2x4.h"
#include "bool3x4.h"
#include "bool4x4.h"
#include "int2.h"
#include "int3.h"
#include "int4.h"
#include "int2x2.h"
#include "int3x2.h"
#include "int4x2.h"
#include "int2x3.h"
#include "int3x3.h"
#include "int4x3.h"
#include "int2x4.h"
#include "int3x4.h"
#include "int4x4.h"
#include "uint2.h"
#include "uint3.h"
#include "uint4.h"
#include "uint2x2.h"
#include "uint3x2.h"
#include "uint4x2.h"
#include "uint2x3.h"
#include "uint3x3.h"
#include "uint4x3.h"
#include "uint2x4.h"
#include "uint3x4.h"
#include "uint4x4.h"
#include "float2.h"
#include "float3.h"
#include "float4.h"
#include "float2x2.h"
#include "float3x2.h"
#include "float4x2.h"
#include "float2x3.h"
#include "float3x3.h"
#include "float4x3.h"
#include "float2x4.h"
#include "float3x4.h"
#include "float4x4.h"
#include "double2.h"
#include "double3.h"
#include "double4.h"
#include "double2x2.h"
#include "double3x2.h"
#include "double4x2.h"
#include "double2x3.h"
#include "double3x3.h"
#include "double4x3.h"
#include "double2x4.h"
#include "double3x4.h"
#include "double4x4.h"

// bool2x2
inline void identity( bool2x2& mat );

inline bool2x2 transpose( const bool2x2& mat );


// bool3x2
inline void identity( bool3x2& mat );

inline bool2x3 transpose( const bool3x2& mat );


// bool4x2
inline void identity( bool4x2& mat );

inline bool2x4 transpose( const bool4x2& mat );


// bool2x3
inline void identity( bool2x3& mat );

inline bool3x2 transpose( const bool2x3& mat );


// bool3x3
inline void identity( bool3x3& mat );

inline bool3x3 transpose( const bool3x3& mat );


// bool4x3
inline void identity( bool4x3& mat );

inline bool3x4 transpose( const bool4x3& mat );


// bool2x4
inline void identity( bool2x4& mat );

inline bool4x2 transpose( const bool2x4& mat );


// bool3x4
inline void identity( bool3x4& mat );

inline bool4x3 transpose( const bool3x4& mat );


// bool4x4
inline void identity( bool4x4& mat );

inline bool4x4 transpose( const bool4x4& mat );


// int2x2
inline void identity( int2x2& mat );

inline int2x2 transpose( const int2x2& mat );

inline int32_t determinant( const int2x2& mat );

inline int2x2 scale( const int2x2& mat, const int32_t scalar );
inline int2x2 scale( const int2x2& mat, const int2& vec );


// int3x2
inline void identity( int3x2& mat );

inline int2x3 transpose( const int3x2& mat );

inline int3x2 scale( const int3x2& mat, const int32_t scalar );
inline int3x2 scale( const int3x2& mat, const int2& vec );


// int4x2
inline void identity( int4x2& mat );

inline int2x4 transpose( const int4x2& mat );

inline int4x2 scale( const int4x2& mat, const int32_t scalar );
inline int4x2 scale( const int4x2& mat, const int2& vec );


// int2x3
inline void identity( int2x3& mat );

inline int3x2 transpose( const int2x3& mat );

inline int2x3 scale( const int2x3& mat, const int32_t scalar );
inline int2x3 scale( const int2x3& mat, const int3& vec );


// int3x3
inline void identity( int3x3& mat );

inline int3x3 transpose( const int3x3& mat );

inline int32_t determinant( const int3x3& mat );

inline int3x3 translate( const int3x3& mat, const int2& vec );

inline int3x3 scale( const int3x3& mat, const int32_t scalar );
inline int3x3 scale( const int3x3& mat, const int3& vec );


// int4x3
inline void identity( int4x3& mat );

inline int3x4 transpose( const int4x3& mat );

inline int4x3 scale( const int4x3& mat, const int32_t scalar );
inline int4x3 scale( const int4x3& mat, const int3& vec );


// int2x4
inline void identity( int2x4& mat );

inline int4x2 transpose( const int2x4& mat );

inline int2x4 scale( const int2x4& mat, const int32_t scalar );
inline int2x4 scale( const int2x4& mat, const int3& vec );


// int3x4
inline void identity( int3x4& mat );

inline int4x3 transpose( const int3x4& mat );

inline int3x4 translate( const int3x4& mat, const int3& vec );

inline int3x4 scale( const int3x4& mat, const int32_t scalar );
inline int3x4 scale( const int3x4& mat, const int3& vec );


// int4x4
inline void identity( int4x4& mat );

inline int4x4 transpose( const int4x4& mat );

inline int32_t determinant( const int4x4& mat );

inline int4x4 translate( const int4x4& mat, const int3& vec );

inline int4x4 scale( const int4x4& mat, const int32_t scalar );
inline int4x4 scale( const int4x4& mat, const int3& vec );


// uint2x2
inline void identity( uint2x2& mat );

inline uint2x2 transpose( const uint2x2& mat );

inline uint2x2 scale( const uint2x2& mat, const uint32_t scalar );
inline uint2x2 scale( const uint2x2& mat, const uint2& vec );


// uint3x2
inline void identity( uint3x2& mat );

inline uint2x3 transpose( const uint3x2& mat );

inline uint3x2 scale( const uint3x2& mat, const uint32_t scalar );
inline uint3x2 scale( const uint3x2& mat, const uint2& vec );


// uint4x2
inline void identity( uint4x2& mat );

inline uint2x4 transpose( const uint4x2& mat );

inline uint4x2 scale( const uint4x2& mat, const uint32_t scalar );
inline uint4x2 scale( const uint4x2& mat, const uint2& vec );


// uint2x3
inline void identity( uint2x3& mat );

inline uint3x2 transpose( const uint2x3& mat );

inline uint2x3 scale( const uint2x3& mat, const uint32_t scalar );
inline uint2x3 scale( const uint2x3& mat, const uint3& vec );


// uint3x3
inline void identity( uint3x3& mat );

inline uint3x3 transpose( const uint3x3& mat );

inline uint3x3 translate( const uint3x3& mat, const uint2& vec );

inline uint3x3 scale( const uint3x3& mat, const uint32_t scalar );
inline uint3x3 scale( const uint3x3& mat, const uint3& vec );


// uint4x3
inline void identity( uint4x3& mat );

inline uint3x4 transpose( const uint4x3& mat );

inline uint4x3 scale( const uint4x3& mat, const uint32_t scalar );
inline uint4x3 scale( const uint4x3& mat, const uint3& vec );


// uint2x4
inline void identity( uint2x4& mat );

inline uint4x2 transpose( const uint2x4& mat );

inline uint2x4 scale( const uint2x4& mat, const uint32_t scalar );
inline uint2x4 scale( const uint2x4& mat, const uint3& vec );


// uint3x4
inline void identity( uint3x4& mat );

inline uint4x3 transpose( const uint3x4& mat );

inline uint3x4 translate( const uint3x4& mat, const uint3& vec );

inline uint3x4 scale( const uint3x4& mat, const uint32_t scalar );
inline uint3x4 scale( const uint3x4& mat, const uint3& vec );


// uint4x4
inline void identity( uint4x4& mat );

inline uint4x4 transpose( const uint4x4& mat );

inline uint4x4 translate( const uint4x4& mat, const uint3& vec );

inline uint4x4 scale( const uint4x4& mat, const uint32_t scalar );
inline uint4x4 scale( const uint4x4& mat, const uint3& vec );


// float2x2
inline void identity( float2x2& mat );

inline float2x2 transpose( const float2x2& mat );

inline float2x2 inverse( const float2x2& mat );

inline float determinant( const float2x2& mat );

inline float2x2 rotate( const float2x2& mat, const float radians, const float2& axis );

inline float2x2 scale( const float2x2& mat, const float scalar );
inline float2x2 scale( const float2x2& mat, const float2& vec );


// float3x2
inline void identity( float3x2& mat );

inline float2x3 transpose( const float3x2& mat );

inline float3x2 rotate( const float3x2& mat, const float radians, const float3& axis );

inline float3x2 scale( const float3x2& mat, const float scalar );
inline float3x2 scale( const float3x2& mat, const float2& vec );


// float4x2
inline void identity( float4x2& mat );

inline float2x4 transpose( const float4x2& mat );

inline float4x2 rotate( const float4x2& mat, const float radians, const float4& axis );

inline float4x2 scale( const float4x2& mat, const float scalar );
inline float4x2 scale( const float4x2& mat, const float2& vec );


// float2x3
inline void identity( float2x3& mat );

inline float3x2 transpose( const float2x3& mat );

inline float2x3 rotate( const float2x3& mat, const float radians, const float2& axis );

inline float2x3 scale( const float2x3& mat, const float scalar );
inline float2x3 scale( const float2x3& mat, const float3& vec );


// float3x3
inline void identity( float3x3& mat );

inline float3x3 transpose( const float3x3& mat );

inline float3x3 inverse( const float3x3& mat );

inline float determinant( const float3x3& mat );

inline float3x3 translate( const float3x3& mat, const float2& vec );

inline float3x3 rotate( const float3x3& mat, const float radians, const float3& axis );

inline float3x3 scale( const float3x3& mat, const float scalar );
inline float3x3 scale( const float3x3& mat, const float3& vec );


// float4x3
inline void identity( float4x3& mat );

inline float3x4 transpose( const float4x3& mat );

inline float4x3 rotate( const float4x3& mat, const float radians, const float4& axis );

inline float4x3 scale( const float4x3& mat, const float scalar );
inline float4x3 scale( const float4x3& mat, const float3& vec );


// float2x4
inline void identity( float2x4& mat );

inline float4x2 transpose( const float2x4& mat );

inline float2x4 rotate( const float2x4& mat, const float radians, const float2& axis );

inline float2x4 scale( const float2x4& mat, const float scalar );
inline float2x4 scale( const float2x4& mat, const float3& vec );


// float3x4
inline void identity( float3x4& mat );

inline float4x3 transpose( const float3x4& mat );

inline float3x4 translate( const float3x4& mat, const float3& vec );

inline float3x4 rotate( const float3x4& mat, const float radians, const float3& axis );

inline float3x4 scale( const float3x4& mat, const float scalar );
inline float3x4 scale( const float3x4& mat, const float3& vec );


// float4x4
inline void identity( float4x4& mat );

inline float4x4 transpose( const float4x4& mat );

inline float4x4 inverse( const float4x4& mat );

inline float determinant( const float4x4& mat );

inline float4x4 translate( const float4x4& mat, const float3& vec );

inline float4x4 rotate( const float4x4& mat, const float radians, const float4& axis );

inline float4x4 scale( const float4x4& mat, const float scalar );
inline float4x4 scale( const float4x4& mat, const float3& vec );

inline float4x4 ortho( const float left, const float right, const float top, const float bottom, const float znear, const float zfar );

inline float4x4 perspective( const float fovdeg, const float aspect, const float znear, const float zfar );

inline float4x4 lookat( const float4& eye, const float4& target, const float4& up );


// double2x2
inline void identity( double2x2& mat );

inline double2x2 transpose( const double2x2& mat );

inline double2x2 inverse( const double2x2& mat );

inline double determinant( const double2x2& mat );

inline double2x2 rotate( const double2x2& mat, const double radians, const double2& axis );

inline double2x2 scale( const double2x2& mat, const double scalar );
inline double2x2 scale( const double2x2& mat, const double2& vec );


// double3x2
inline void identity( double3x2& mat );

inline double2x3 transpose( const double3x2& mat );

inline double3x2 rotate( const double3x2& mat, const double radians, const double3& axis );

inline double3x2 scale( const double3x2& mat, const double scalar );
inline double3x2 scale( const double3x2& mat, const double2& vec );


// double4x2
inline void identity( double4x2& mat );

inline double2x4 transpose( const double4x2& mat );

inline double4x2 rotate( const double4x2& mat, const double radians, const double4& axis );

inline double4x2 scale( const double4x2& mat, const double scalar );
inline double4x2 scale( const double4x2& mat, const double2& vec );


// double2x3
inline void identity( double2x3& mat );

inline double3x2 transpose( const double2x3& mat );

inline double2x3 rotate( const double2x3& mat, const double radians, const double2& axis );

inline double2x3 scale( const double2x3& mat, const double scalar );
inline double2x3 scale( const double2x3& mat, const double3& vec );


// double3x3
inline void identity( double3x3& mat );

inline double3x3 transpose( const double3x3& mat );

inline double3x3 inverse( const double3x3& mat );

inline double determinant( const double3x3& mat );

inline double3x3 translate( const double3x3& mat, const double2& vec );

inline double3x3 rotate( const double3x3& mat, const double radians, const double3& axis );

inline double3x3 scale( const double3x3& mat, const double scalar );
inline double3x3 scale( const double3x3& mat, const double3& vec );


// double4x3
inline void identity( double4x3& mat );

inline double3x4 transpose( const double4x3& mat );

inline double4x3 rotate( const double4x3& mat, const double radians, const double4& axis );

inline double4x3 scale( const double4x3& mat, const double scalar );
inline double4x3 scale( const double4x3& mat, const double3& vec );


// double2x4
inline void identity( double2x4& mat );

inline double4x2 transpose( const double2x4& mat );

inline double2x4 rotate( const double2x4& mat, const double radians, const double2& axis );

inline double2x4 scale( const double2x4& mat, const double scalar );
inline double2x4 scale( const double2x4& mat, const double3& vec );


// double3x4
inline void identity( double3x4& mat );

inline double4x3 transpose( const double3x4& mat );

inline double3x4 translate( const double3x4& mat, const double3& vec );

inline double3x4 rotate( const double3x4& mat, const double radians, const double3& axis );

inline double3x4 scale( const double3x4& mat, const double scalar );
inline double3x4 scale( const double3x4& mat, const double3& vec );


// double4x4
inline void identity( double4x4& mat );

inline double4x4 transpose( const double4x4& mat );

inline double4x4 inverse( const double4x4& mat );

inline double determinant( const double4x4& mat );

inline double4x4 translate( const double4x4& mat, const double3& vec );

inline double4x4 rotate( const double4x4& mat, const double radians, const double4& axis );

inline double4x4 scale( const double4x4& mat, const double scalar );
inline double4x4 scale( const double4x4& mat, const double3& vec );

inline double4x4 ortho( const double left, const double right, const double top, const double bottom, const double znear, const double zfar );

inline double4x4 perspective( const double fovdeg, const double aspect, const double znear, const double zfar );

inline double4x4 lookat( const double4& eye, const double4& target, const double4& up );


#include "hlml_functions_matrix.inl"

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
inline float dot( const int2& lhs, const int2& rhs );

inline float lengthsqr( const int2& vec );
inline float length( const int2& vec );


// int3
inline float dot( const int3& lhs, const int3& rhs );

inline float lengthsqr( const int3& vec );
inline float length( const int3& vec );


// int4
inline float dot( const int4& lhs, const int4& rhs );

inline float lengthsqr( const int4& vec );
inline float length( const int4& vec );


// uint2
inline float dot( const uint2& lhs, const uint2& rhs );

inline float lengthsqr( const uint2& vec );
inline float length( const uint2& vec );


// uint3
inline float dot( const uint3& lhs, const uint3& rhs );

inline float lengthsqr( const uint3& vec );
inline float length( const uint3& vec );


// uint4
inline float dot( const uint4& lhs, const uint4& rhs );

inline float lengthsqr( const uint4& vec );
inline float length( const uint4& vec );


// float2
inline float dot( const float2& lhs, const float2& rhs );

inline float lengthsqr( const float2& vec );
inline float length( const float2& vec );

inline void normalize( float2& vec );
inline float2 normalized( const float2& vec );


// float3
inline float dot( const float3& lhs, const float3& rhs );

inline float lengthsqr( const float3& vec );
inline float length( const float3& vec );

inline void normalize( float3& vec );
inline float3 normalized( const float3& vec );

inline float3 cross( const float3& lhs, const float3& rhs );


// float4
inline float dot( const float4& lhs, const float4& rhs );

inline float lengthsqr( const float4& vec );
inline float length( const float4& vec );

inline void normalize( float4& vec );
inline float4 normalized( const float4& vec );

inline float4 cross( const float4& lhs, const float4& rhs );


// double2
inline double dot( const double2& lhs, const double2& rhs );

inline double lengthsqr( const double2& vec );
inline double length( const double2& vec );

inline void normalize( double2& vec );
inline double2 normalized( const double2& vec );


// double3
inline double dot( const double3& lhs, const double3& rhs );

inline double lengthsqr( const double3& vec );
inline double length( const double3& vec );

inline void normalize( double3& vec );
inline double3 normalized( const double3& vec );

inline double3 cross( const double3& lhs, const double3& rhs );


// double4
inline double dot( const double4& lhs, const double4& rhs );

inline double lengthsqr( const double4& vec );
inline double length( const double4& vec );

inline void normalize( double4& vec );
inline double4 normalized( const double4& vec );

inline double4 cross( const double4& lhs, const double4& rhs );


#include "hlml_functions_vector.inl"
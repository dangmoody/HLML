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
/// \relates int2/// \brief Returns a __m128i that holds 4 dot product results.
/// Instead of taking a series of vectors this function takes in a series of vector components (SoA).
/// It is therefore your responsibility to make sure the data is input this way when calling the function.
inline __m128i dot_ps( const int2_dot_data_t& lhs, const int2_dot_data_t& rhs );


// int3
/// \relates int3/// \brief Returns a __m128i that holds 4 dot product results.
/// Instead of taking a series of vectors this function takes in a series of vector components (SoA).
/// It is therefore your responsibility to make sure the data is input this way when calling the function.
inline __m128i dot_ps( const int3_dot_data_t& lhs, const int3_dot_data_t& rhs );


// int4
/// \relates int4/// \brief Returns a __m128i that holds 4 dot product results.
/// Instead of taking a series of vectors this function takes in a series of vector components (SoA).
/// It is therefore your responsibility to make sure the data is input this way when calling the function.
inline __m128i dot_ps( const int4_dot_data_t& lhs, const int4_dot_data_t& rhs );


// uint2
/// \relates uint2/// \brief Returns a __m128i that holds 4 dot product results.
/// Instead of taking a series of vectors this function takes in a series of vector components (SoA).
/// It is therefore your responsibility to make sure the data is input this way when calling the function.
inline __m128i dot_ps( const uint2_dot_data_t& lhs, const uint2_dot_data_t& rhs );


// uint3
/// \relates uint3/// \brief Returns a __m128i that holds 4 dot product results.
/// Instead of taking a series of vectors this function takes in a series of vector components (SoA).
/// It is therefore your responsibility to make sure the data is input this way when calling the function.
inline __m128i dot_ps( const uint3_dot_data_t& lhs, const uint3_dot_data_t& rhs );


// uint4
/// \relates uint4/// \brief Returns a __m128i that holds 4 dot product results.
/// Instead of taking a series of vectors this function takes in a series of vector components (SoA).
/// It is therefore your responsibility to make sure the data is input this way when calling the function.
inline __m128i dot_ps( const uint4_dot_data_t& lhs, const uint4_dot_data_t& rhs );


// float2
/// \relates float2/// \brief Returns a __m128 that holds 4 dot product results.
/// Instead of taking a series of vectors this function takes in a series of vector components (SoA).
/// It is therefore your responsibility to make sure the data is input this way when calling the function.
inline __m128 dot_ps( const float2_dot_data_t& lhs, const float2_dot_data_t& rhs );


// float3
/// \relates float3/// \brief Returns a __m128 that holds 4 dot product results.
/// Instead of taking a series of vectors this function takes in a series of vector components (SoA).
/// It is therefore your responsibility to make sure the data is input this way when calling the function.
inline __m128 dot_ps( const float3_dot_data_t& lhs, const float3_dot_data_t& rhs );


// float4
/// \relates float4/// \brief Returns a __m128 that holds 4 dot product results.
/// Instead of taking a series of vectors this function takes in a series of vector components (SoA).
/// It is therefore your responsibility to make sure the data is input this way when calling the function.
inline __m128 dot_ps( const float4_dot_data_t& lhs, const float4_dot_data_t& rhs );


// double2
/// \relates double2/// \brief Returns a __m128d that holds 4 dot product results.
/// Instead of taking a series of vectors this function takes in a series of vector components (SoA).
/// It is therefore your responsibility to make sure the data is input this way when calling the function.
inline __m128d dot_ps( const double2_dot_data_t& lhs, const double2_dot_data_t& rhs );


// double3
/// \relates double3/// \brief Returns a __m128d that holds 4 dot product results.
/// Instead of taking a series of vectors this function takes in a series of vector components (SoA).
/// It is therefore your responsibility to make sure the data is input this way when calling the function.
inline __m128d dot_ps( const double3_dot_data_t& lhs, const double3_dot_data_t& rhs );


// double4
/// \relates double4/// \brief Returns a __m128d that holds 4 dot product results.
/// Instead of taking a series of vectors this function takes in a series of vector components (SoA).
/// It is therefore your responsibility to make sure the data is input this way when calling the function.
inline __m128d dot_ps( const double4_dot_data_t& lhs, const double4_dot_data_t& rhs );


#include "hlml_functions_simd.inl"

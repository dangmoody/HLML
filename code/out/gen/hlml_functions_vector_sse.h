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

#include <immintrin.h>

// float2
struct sse_input_length_float2_t
{
	__m128 comp[2];
};

inline void lengthsq_sse( const sse_input_length_float2_t& in, __m128* out_results );

inline void length_sse( const sse_input_length_float2_t& in, __m128* out_results );

struct sse_input_normalize_float2_t
{
	__m128 comp[2];
};

inline void normalize_sse( const sse_input_normalize_float2_t& in, __m128 out_results[2] );

struct sse_input_dot_float2_t
{
	__m128 lhs[2];
	__m128 rhs[2];
};

inline void dot_sse( const sse_input_dot_float2_t& in, __m128* out_results );

struct sse_input_distance_float2_t
{
	__m128 lhs[2];
	__m128 rhs[2];
};

inline void distancesq_sse( const sse_input_distance_float2_t& in, __m128* out_results );

inline void distance_sse( const sse_input_distance_float2_t& in, __m128* out_results );


// float3
struct sse_input_length_float3_t
{
	__m128 comp[3];
};

inline void lengthsq_sse( const sse_input_length_float3_t& in, __m128* out_results );

inline void length_sse( const sse_input_length_float3_t& in, __m128* out_results );

struct sse_input_normalize_float3_t
{
	__m128 comp[3];
};

inline void normalize_sse( const sse_input_normalize_float3_t& in, __m128 out_results[3] );

struct sse_input_dot_float3_t
{
	__m128 lhs[3];
	__m128 rhs[3];
};

inline void dot_sse( const sse_input_dot_float3_t& in, __m128* out_results );

struct sse_input_distance_float3_t
{
	__m128 lhs[3];
	__m128 rhs[3];
};

inline void distancesq_sse( const sse_input_distance_float3_t& in, __m128* out_results );

inline void distance_sse( const sse_input_distance_float3_t& in, __m128* out_results );


// float4
struct sse_input_length_float4_t
{
	__m128 comp[4];
};

inline void lengthsq_sse( const sse_input_length_float4_t& in, __m128* out_results );

inline void length_sse( const sse_input_length_float4_t& in, __m128* out_results );

struct sse_input_normalize_float4_t
{
	__m128 comp[4];
};

inline void normalize_sse( const sse_input_normalize_float4_t& in, __m128 out_results[4] );

struct sse_input_dot_float4_t
{
	__m128 lhs[4];
	__m128 rhs[4];
};

inline void dot_sse( const sse_input_dot_float4_t& in, __m128* out_results );

struct sse_input_distance_float4_t
{
	__m128 lhs[4];
	__m128 rhs[4];
};

inline void distancesq_sse( const sse_input_distance_float4_t& in, __m128* out_results );

inline void distance_sse( const sse_input_distance_float4_t& in, __m128* out_results );


#include "hlml_functions_vector_sse.inl"

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

#include <immintrin.h>

// float2x2
struct sse_input_add_float2x2_t
{
	__m128 lhs[2][2];
	__m128 rhs[2][2];
};

inline void comp_add_sse( const sse_input_add_float2x2_t* in, __m128 out_results[2][2] );

struct sse_input_sub_float2x2_t
{
	__m128 lhs[2][2];
	__m128 rhs[2][2];
};

inline void comp_sub_sse( const sse_input_sub_float2x2_t* in, __m128 out_results[2][2] );

struct sse_input_mul_float2x2_t
{
	__m128 lhs[2][2];
	__m128 rhs[2][2];
};

inline void comp_mul_sse( const sse_input_mul_float2x2_t* in, __m128 out_results[2][2] );

struct sse_input_div_float2x2_t
{
	__m128 lhs[2][2];
	__m128 rhs[2][2];
};

inline void comp_div_sse( const sse_input_div_float2x2_t* in, __m128 out_results[2][2] );

struct sse_input_scale_float2x2_t
{
	__m128 diagonal[2];
	__m128 scale[2];
};

inline void scale_sse( const sse_input_scale_float2x2_t* in, __m128 out_results[2] );


// float2x3
struct sse_input_add_float2x3_t
{
	__m128 lhs[2][3];
	__m128 rhs[2][3];
};

inline void comp_add_sse( const sse_input_add_float2x3_t* in, __m128 out_results[2][3] );

struct sse_input_sub_float2x3_t
{
	__m128 lhs[2][3];
	__m128 rhs[2][3];
};

inline void comp_sub_sse( const sse_input_sub_float2x3_t* in, __m128 out_results[2][3] );

struct sse_input_mul_float2x3_t
{
	__m128 lhs[2][3];
	__m128 rhs[2][3];
};

inline void comp_mul_sse( const sse_input_mul_float2x3_t* in, __m128 out_results[2][3] );

struct sse_input_div_float2x3_t
{
	__m128 lhs[2][3];
	__m128 rhs[2][3];
};

inline void comp_div_sse( const sse_input_div_float2x3_t* in, __m128 out_results[2][3] );

struct sse_input_translate_float2x3_t
{
	__m128 column[2];
	__m128 vec[2];
};

inline void translate_sse( const sse_input_translate_float2x3_t* in, __m128 out_results[2] );

struct sse_input_scale_float2x3_t
{
	__m128 diagonal[2];
	__m128 scale[2];
};

inline void scale_sse( const sse_input_scale_float2x3_t* in, __m128 out_results[2] );


// float2x4
struct sse_input_add_float2x4_t
{
	__m128 lhs[2][4];
	__m128 rhs[2][4];
};

inline void comp_add_sse( const sse_input_add_float2x4_t* in, __m128 out_results[2][4] );

struct sse_input_sub_float2x4_t
{
	__m128 lhs[2][4];
	__m128 rhs[2][4];
};

inline void comp_sub_sse( const sse_input_sub_float2x4_t* in, __m128 out_results[2][4] );

struct sse_input_mul_float2x4_t
{
	__m128 lhs[2][4];
	__m128 rhs[2][4];
};

inline void comp_mul_sse( const sse_input_mul_float2x4_t* in, __m128 out_results[2][4] );

struct sse_input_div_float2x4_t
{
	__m128 lhs[2][4];
	__m128 rhs[2][4];
};

inline void comp_div_sse( const sse_input_div_float2x4_t* in, __m128 out_results[2][4] );

struct sse_input_translate_float2x4_t
{
	__m128 column[3];
	__m128 vec[3];
};

inline void translate_sse( const sse_input_translate_float2x4_t* in, __m128 out_results[3] );

struct sse_input_scale_float2x4_t
{
	__m128 diagonal[2];
	__m128 scale[2];
};

inline void scale_sse( const sse_input_scale_float2x4_t* in, __m128 out_results[2] );


// float3x2
struct sse_input_add_float3x2_t
{
	__m128 lhs[3][2];
	__m128 rhs[3][2];
};

inline void comp_add_sse( const sse_input_add_float3x2_t* in, __m128 out_results[3][2] );

struct sse_input_sub_float3x2_t
{
	__m128 lhs[3][2];
	__m128 rhs[3][2];
};

inline void comp_sub_sse( const sse_input_sub_float3x2_t* in, __m128 out_results[3][2] );

struct sse_input_mul_float3x2_t
{
	__m128 lhs[3][2];
	__m128 rhs[3][2];
};

inline void comp_mul_sse( const sse_input_mul_float3x2_t* in, __m128 out_results[3][2] );

struct sse_input_div_float3x2_t
{
	__m128 lhs[3][2];
	__m128 rhs[3][2];
};

inline void comp_div_sse( const sse_input_div_float3x2_t* in, __m128 out_results[3][2] );

struct sse_input_translate_float3x2_t
{
	__m128 column[1];
	__m128 vec[1];
};

inline void translate_sse( const sse_input_translate_float3x2_t* in, __m128 out_results[1] );

struct sse_input_scale_float3x2_t
{
	__m128 diagonal[2];
	__m128 scale[2];
};

inline void scale_sse( const sse_input_scale_float3x2_t* in, __m128 out_results[2] );


// float3x3
struct sse_input_add_float3x3_t
{
	__m128 lhs[3][3];
	__m128 rhs[3][3];
};

inline void comp_add_sse( const sse_input_add_float3x3_t* in, __m128 out_results[3][3] );

struct sse_input_sub_float3x3_t
{
	__m128 lhs[3][3];
	__m128 rhs[3][3];
};

inline void comp_sub_sse( const sse_input_sub_float3x3_t* in, __m128 out_results[3][3] );

struct sse_input_mul_float3x3_t
{
	__m128 lhs[3][3];
	__m128 rhs[3][3];
};

inline void comp_mul_sse( const sse_input_mul_float3x3_t* in, __m128 out_results[3][3] );

struct sse_input_div_float3x3_t
{
	__m128 lhs[3][3];
	__m128 rhs[3][3];
};

inline void comp_div_sse( const sse_input_div_float3x3_t* in, __m128 out_results[3][3] );

struct sse_input_translate_float3x3_t
{
	__m128 column[2];
	__m128 vec[2];
};

inline void translate_sse( const sse_input_translate_float3x3_t* in, __m128 out_results[2] );

struct sse_input_scale_float3x3_t
{
	__m128 diagonal[3];
	__m128 scale[3];
};

inline void scale_sse( const sse_input_scale_float3x3_t* in, __m128 out_results[3] );


// float3x4
struct sse_input_add_float3x4_t
{
	__m128 lhs[3][4];
	__m128 rhs[3][4];
};

inline void comp_add_sse( const sse_input_add_float3x4_t* in, __m128 out_results[3][4] );

struct sse_input_sub_float3x4_t
{
	__m128 lhs[3][4];
	__m128 rhs[3][4];
};

inline void comp_sub_sse( const sse_input_sub_float3x4_t* in, __m128 out_results[3][4] );

struct sse_input_mul_float3x4_t
{
	__m128 lhs[3][4];
	__m128 rhs[3][4];
};

inline void comp_mul_sse( const sse_input_mul_float3x4_t* in, __m128 out_results[3][4] );

struct sse_input_div_float3x4_t
{
	__m128 lhs[3][4];
	__m128 rhs[3][4];
};

inline void comp_div_sse( const sse_input_div_float3x4_t* in, __m128 out_results[3][4] );

struct sse_input_translate_float3x4_t
{
	__m128 column[3];
	__m128 vec[3];
};

inline void translate_sse( const sse_input_translate_float3x4_t* in, __m128 out_results[3] );

struct sse_input_scale_float3x4_t
{
	__m128 diagonal[3];
	__m128 scale[3];
};

inline void scale_sse( const sse_input_scale_float3x4_t* in, __m128 out_results[3] );


// float4x2
struct sse_input_add_float4x2_t
{
	__m128 lhs[4][2];
	__m128 rhs[4][2];
};

inline void comp_add_sse( const sse_input_add_float4x2_t* in, __m128 out_results[4][2] );

struct sse_input_sub_float4x2_t
{
	__m128 lhs[4][2];
	__m128 rhs[4][2];
};

inline void comp_sub_sse( const sse_input_sub_float4x2_t* in, __m128 out_results[4][2] );

struct sse_input_mul_float4x2_t
{
	__m128 lhs[4][2];
	__m128 rhs[4][2];
};

inline void comp_mul_sse( const sse_input_mul_float4x2_t* in, __m128 out_results[4][2] );

struct sse_input_div_float4x2_t
{
	__m128 lhs[4][2];
	__m128 rhs[4][2];
};

inline void comp_div_sse( const sse_input_div_float4x2_t* in, __m128 out_results[4][2] );

struct sse_input_translate_float4x2_t
{
	__m128 column[1];
	__m128 vec[1];
};

inline void translate_sse( const sse_input_translate_float4x2_t* in, __m128 out_results[1] );

struct sse_input_scale_float4x2_t
{
	__m128 diagonal[2];
	__m128 scale[2];
};

inline void scale_sse( const sse_input_scale_float4x2_t* in, __m128 out_results[2] );


// float4x3
struct sse_input_add_float4x3_t
{
	__m128 lhs[4][3];
	__m128 rhs[4][3];
};

inline void comp_add_sse( const sse_input_add_float4x3_t* in, __m128 out_results[4][3] );

struct sse_input_sub_float4x3_t
{
	__m128 lhs[4][3];
	__m128 rhs[4][3];
};

inline void comp_sub_sse( const sse_input_sub_float4x3_t* in, __m128 out_results[4][3] );

struct sse_input_mul_float4x3_t
{
	__m128 lhs[4][3];
	__m128 rhs[4][3];
};

inline void comp_mul_sse( const sse_input_mul_float4x3_t* in, __m128 out_results[4][3] );

struct sse_input_div_float4x3_t
{
	__m128 lhs[4][3];
	__m128 rhs[4][3];
};

inline void comp_div_sse( const sse_input_div_float4x3_t* in, __m128 out_results[4][3] );

struct sse_input_translate_float4x3_t
{
	__m128 column[2];
	__m128 vec[2];
};

inline void translate_sse( const sse_input_translate_float4x3_t* in, __m128 out_results[2] );

struct sse_input_scale_float4x3_t
{
	__m128 diagonal[3];
	__m128 scale[3];
};

inline void scale_sse( const sse_input_scale_float4x3_t* in, __m128 out_results[3] );


// float4x4
struct sse_input_add_float4x4_t
{
	__m128 lhs[4][4];
	__m128 rhs[4][4];
};

inline void comp_add_sse( const sse_input_add_float4x4_t* in, __m128 out_results[4][4] );

struct sse_input_sub_float4x4_t
{
	__m128 lhs[4][4];
	__m128 rhs[4][4];
};

inline void comp_sub_sse( const sse_input_sub_float4x4_t* in, __m128 out_results[4][4] );

struct sse_input_mul_float4x4_t
{
	__m128 lhs[4][4];
	__m128 rhs[4][4];
};

inline void comp_mul_sse( const sse_input_mul_float4x4_t* in, __m128 out_results[4][4] );

struct sse_input_div_float4x4_t
{
	__m128 lhs[4][4];
	__m128 rhs[4][4];
};

inline void comp_div_sse( const sse_input_div_float4x4_t* in, __m128 out_results[4][4] );

struct sse_input_translate_float4x4_t
{
	__m128 column[3];
	__m128 vec[3];
};

inline void translate_sse( const sse_input_translate_float4x4_t* in, __m128 out_results[3] );

struct sse_input_scale_float4x4_t
{
	__m128 diagonal[4];
	__m128 scale[4];
};

inline void scale_sse( const sse_input_scale_float4x4_t* in, __m128 out_results[4] );


#include "hlml_functions_matrix_sse.inl"

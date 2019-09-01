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

#include "../hlml_constants_sse.h"

// float2x2
void transpose_sse( const sse_input_transpose_float2x2_t* in, __m128 out_results[2][2] )
{
	assert( in );

	out_results[0][0] = in->m[0][0];
	out_results[1][0] = in->m[0][1];

	out_results[0][1] = in->m[1][0];
	out_results[1][1] = in->m[1][1];
}

void inverse_sse( const sse_input_inverse_float2x2_t* in, __m128 out_results[2][2] )
{
	assert( in );

	sse_input_determinant_float2x2_t in_det;
	memcpy( in_det.m, in->m, sizeof( in->m ) );

	__m128 determinants;
	determinant_sse( &in_det, &determinants );

	determinants = _mm_rcp_ps( determinants );

	__m128 neg0 = _mm_xor_ps( in->m[0][1], HLML_ZERO_SSE );
	__m128 neg1 = _mm_xor_ps( in->m[1][0], HLML_ZERO_SSE );

	out_results[0][0] = _mm_mul_ps( in->m[1][1], determinants );
	out_results[0][1] = _mm_mul_ps( neg0, determinants );
	out_results[1][0] = _mm_mul_ps( neg1, determinants );
	out_results[1][1] = _mm_mul_ps( in->m[0][0], determinants );
}

void determinant_sse( const sse_input_determinant_float2x2_t* in, __m128* out_result )
{
	assert( in );
	assert( out_result );

	__m128 mul0 = _mm_mul_ps( in->m[0][0], in->m[1][1] );
	__m128 mul1 = _mm_mul_ps( in->m[1][0], in->m[0][1] );

	*out_result = _mm_sub_ps( mul0, mul1 );
}

void comp_add_sse( const sse_input_add_float2x2_t* in, __m128 out_results[2][2] )
{
	assert( in );

	// row 0
	out_results[0][0] = _mm_add_ps( in->lhs[0][0], in->rhs[0][0] );
	out_results[0][1] = _mm_add_ps( in->lhs[0][1], in->rhs[0][1] );

	// row 1
	out_results[1][0] = _mm_add_ps( in->lhs[1][0], in->rhs[1][0] );
	out_results[1][1] = _mm_add_ps( in->lhs[1][1], in->rhs[1][1] );
}

void comp_sub_sse( const sse_input_sub_float2x2_t* in, __m128 out_results[2][2] )
{
	assert( in );

	// row 0
	out_results[0][0] = _mm_sub_ps( in->lhs[0][0], in->rhs[0][0] );
	out_results[0][1] = _mm_sub_ps( in->lhs[0][1], in->rhs[0][1] );

	// row 1
	out_results[1][0] = _mm_sub_ps( in->lhs[1][0], in->rhs[1][0] );
	out_results[1][1] = _mm_sub_ps( in->lhs[1][1], in->rhs[1][1] );
}

void comp_mul_sse( const sse_input_mul_float2x2_t* in, __m128 out_results[2][2] )
{
	assert( in );

	// row 0
	out_results[0][0] = _mm_mul_ps( in->lhs[0][0], in->rhs[0][0] );
	out_results[0][1] = _mm_mul_ps( in->lhs[0][1], in->rhs[0][1] );

	// row 1
	out_results[1][0] = _mm_mul_ps( in->lhs[1][0], in->rhs[1][0] );
	out_results[1][1] = _mm_mul_ps( in->lhs[1][1], in->rhs[1][1] );
}

void comp_div_sse( const sse_input_div_float2x2_t* in, __m128 out_results[2][2] )
{
	assert( in );

	// row 0
	out_results[0][0] = _mm_div_ps( in->lhs[0][0], in->rhs[0][0] );
	out_results[0][1] = _mm_div_ps( in->lhs[0][1], in->rhs[0][1] );

	// row 1
	out_results[1][0] = _mm_div_ps( in->lhs[1][0], in->rhs[1][0] );
	out_results[1][1] = _mm_div_ps( in->lhs[1][1], in->rhs[1][1] );
}

void scale_sse( const sse_input_scale_float2x2_t* in, __m128 out_results[2] )
{
	assert( in );

	out_results[0] = _mm_mul_ps( in->diagonal[0], in->scale[0] );
	out_results[1] = _mm_mul_ps( in->diagonal[1], in->scale[1] );
}


// float2x3
void transpose_sse( const sse_input_transpose_float2x3_t* in, __m128 out_results[3][2] )
{
	assert( in );

	out_results[0][0] = in->m[0][0];
	out_results[1][0] = in->m[0][1];
	out_results[2][0] = in->m[0][2];

	out_results[0][1] = in->m[1][0];
	out_results[1][1] = in->m[1][1];
	out_results[2][1] = in->m[1][2];
}

void comp_add_sse( const sse_input_add_float2x3_t* in, __m128 out_results[2][3] )
{
	assert( in );

	// row 0
	out_results[0][0] = _mm_add_ps( in->lhs[0][0], in->rhs[0][0] );
	out_results[0][1] = _mm_add_ps( in->lhs[0][1], in->rhs[0][1] );
	out_results[0][2] = _mm_add_ps( in->lhs[0][2], in->rhs[0][2] );

	// row 1
	out_results[1][0] = _mm_add_ps( in->lhs[1][0], in->rhs[1][0] );
	out_results[1][1] = _mm_add_ps( in->lhs[1][1], in->rhs[1][1] );
	out_results[1][2] = _mm_add_ps( in->lhs[1][2], in->rhs[1][2] );
}

void comp_sub_sse( const sse_input_sub_float2x3_t* in, __m128 out_results[2][3] )
{
	assert( in );

	// row 0
	out_results[0][0] = _mm_sub_ps( in->lhs[0][0], in->rhs[0][0] );
	out_results[0][1] = _mm_sub_ps( in->lhs[0][1], in->rhs[0][1] );
	out_results[0][2] = _mm_sub_ps( in->lhs[0][2], in->rhs[0][2] );

	// row 1
	out_results[1][0] = _mm_sub_ps( in->lhs[1][0], in->rhs[1][0] );
	out_results[1][1] = _mm_sub_ps( in->lhs[1][1], in->rhs[1][1] );
	out_results[1][2] = _mm_sub_ps( in->lhs[1][2], in->rhs[1][2] );
}

void comp_mul_sse( const sse_input_mul_float2x3_t* in, __m128 out_results[2][3] )
{
	assert( in );

	// row 0
	out_results[0][0] = _mm_mul_ps( in->lhs[0][0], in->rhs[0][0] );
	out_results[0][1] = _mm_mul_ps( in->lhs[0][1], in->rhs[0][1] );
	out_results[0][2] = _mm_mul_ps( in->lhs[0][2], in->rhs[0][2] );

	// row 1
	out_results[1][0] = _mm_mul_ps( in->lhs[1][0], in->rhs[1][0] );
	out_results[1][1] = _mm_mul_ps( in->lhs[1][1], in->rhs[1][1] );
	out_results[1][2] = _mm_mul_ps( in->lhs[1][2], in->rhs[1][2] );
}

void comp_div_sse( const sse_input_div_float2x3_t* in, __m128 out_results[2][3] )
{
	assert( in );

	// row 0
	out_results[0][0] = _mm_div_ps( in->lhs[0][0], in->rhs[0][0] );
	out_results[0][1] = _mm_div_ps( in->lhs[0][1], in->rhs[0][1] );
	out_results[0][2] = _mm_div_ps( in->lhs[0][2], in->rhs[0][2] );

	// row 1
	out_results[1][0] = _mm_div_ps( in->lhs[1][0], in->rhs[1][0] );
	out_results[1][1] = _mm_div_ps( in->lhs[1][1], in->rhs[1][1] );
	out_results[1][2] = _mm_div_ps( in->lhs[1][2], in->rhs[1][2] );
}

void translate_sse( const sse_input_translate_float2x3_t* in, __m128 out_results[2] )
{
	assert( in );

	out_results[0] = _mm_add_ps( in->column[0], in->vec[0] );
	out_results[1] = _mm_add_ps( in->column[1], in->vec[1] );
}

void scale_sse( const sse_input_scale_float2x3_t* in, __m128 out_results[2] )
{
	assert( in );

	out_results[0] = _mm_mul_ps( in->diagonal[0], in->scale[0] );
	out_results[1] = _mm_mul_ps( in->diagonal[1], in->scale[1] );
}


// float2x4
void transpose_sse( const sse_input_transpose_float2x4_t* in, __m128 out_results[4][2] )
{
	assert( in );

	out_results[0][0] = in->m[0][0];
	out_results[1][0] = in->m[0][1];
	out_results[2][0] = in->m[0][2];
	out_results[3][0] = in->m[0][3];

	out_results[0][1] = in->m[1][0];
	out_results[1][1] = in->m[1][1];
	out_results[2][1] = in->m[1][2];
	out_results[3][1] = in->m[1][3];
}

void comp_add_sse( const sse_input_add_float2x4_t* in, __m128 out_results[2][4] )
{
	assert( in );

	// row 0
	out_results[0][0] = _mm_add_ps( in->lhs[0][0], in->rhs[0][0] );
	out_results[0][1] = _mm_add_ps( in->lhs[0][1], in->rhs[0][1] );
	out_results[0][2] = _mm_add_ps( in->lhs[0][2], in->rhs[0][2] );
	out_results[0][3] = _mm_add_ps( in->lhs[0][3], in->rhs[0][3] );

	// row 1
	out_results[1][0] = _mm_add_ps( in->lhs[1][0], in->rhs[1][0] );
	out_results[1][1] = _mm_add_ps( in->lhs[1][1], in->rhs[1][1] );
	out_results[1][2] = _mm_add_ps( in->lhs[1][2], in->rhs[1][2] );
	out_results[1][3] = _mm_add_ps( in->lhs[1][3], in->rhs[1][3] );
}

void comp_sub_sse( const sse_input_sub_float2x4_t* in, __m128 out_results[2][4] )
{
	assert( in );

	// row 0
	out_results[0][0] = _mm_sub_ps( in->lhs[0][0], in->rhs[0][0] );
	out_results[0][1] = _mm_sub_ps( in->lhs[0][1], in->rhs[0][1] );
	out_results[0][2] = _mm_sub_ps( in->lhs[0][2], in->rhs[0][2] );
	out_results[0][3] = _mm_sub_ps( in->lhs[0][3], in->rhs[0][3] );

	// row 1
	out_results[1][0] = _mm_sub_ps( in->lhs[1][0], in->rhs[1][0] );
	out_results[1][1] = _mm_sub_ps( in->lhs[1][1], in->rhs[1][1] );
	out_results[1][2] = _mm_sub_ps( in->lhs[1][2], in->rhs[1][2] );
	out_results[1][3] = _mm_sub_ps( in->lhs[1][3], in->rhs[1][3] );
}

void comp_mul_sse( const sse_input_mul_float2x4_t* in, __m128 out_results[2][4] )
{
	assert( in );

	// row 0
	out_results[0][0] = _mm_mul_ps( in->lhs[0][0], in->rhs[0][0] );
	out_results[0][1] = _mm_mul_ps( in->lhs[0][1], in->rhs[0][1] );
	out_results[0][2] = _mm_mul_ps( in->lhs[0][2], in->rhs[0][2] );
	out_results[0][3] = _mm_mul_ps( in->lhs[0][3], in->rhs[0][3] );

	// row 1
	out_results[1][0] = _mm_mul_ps( in->lhs[1][0], in->rhs[1][0] );
	out_results[1][1] = _mm_mul_ps( in->lhs[1][1], in->rhs[1][1] );
	out_results[1][2] = _mm_mul_ps( in->lhs[1][2], in->rhs[1][2] );
	out_results[1][3] = _mm_mul_ps( in->lhs[1][3], in->rhs[1][3] );
}

void comp_div_sse( const sse_input_div_float2x4_t* in, __m128 out_results[2][4] )
{
	assert( in );

	// row 0
	out_results[0][0] = _mm_div_ps( in->lhs[0][0], in->rhs[0][0] );
	out_results[0][1] = _mm_div_ps( in->lhs[0][1], in->rhs[0][1] );
	out_results[0][2] = _mm_div_ps( in->lhs[0][2], in->rhs[0][2] );
	out_results[0][3] = _mm_div_ps( in->lhs[0][3], in->rhs[0][3] );

	// row 1
	out_results[1][0] = _mm_div_ps( in->lhs[1][0], in->rhs[1][0] );
	out_results[1][1] = _mm_div_ps( in->lhs[1][1], in->rhs[1][1] );
	out_results[1][2] = _mm_div_ps( in->lhs[1][2], in->rhs[1][2] );
	out_results[1][3] = _mm_div_ps( in->lhs[1][3], in->rhs[1][3] );
}

void translate_sse( const sse_input_translate_float2x4_t* in, __m128 out_results[3] )
{
	assert( in );

	out_results[0] = _mm_add_ps( in->column[0], in->vec[0] );
	out_results[1] = _mm_add_ps( in->column[1], in->vec[1] );
	out_results[2] = _mm_add_ps( in->column[2], in->vec[2] );
}

void scale_sse( const sse_input_scale_float2x4_t* in, __m128 out_results[2] )
{
	assert( in );

	out_results[0] = _mm_mul_ps( in->diagonal[0], in->scale[0] );
	out_results[1] = _mm_mul_ps( in->diagonal[1], in->scale[1] );
}


// float3x2
void transpose_sse( const sse_input_transpose_float3x2_t* in, __m128 out_results[2][3] )
{
	assert( in );

	out_results[0][0] = in->m[0][0];
	out_results[1][0] = in->m[0][1];

	out_results[0][1] = in->m[1][0];
	out_results[1][1] = in->m[1][1];

	out_results[0][2] = in->m[2][0];
	out_results[1][2] = in->m[2][1];
}

void comp_add_sse( const sse_input_add_float3x2_t* in, __m128 out_results[3][2] )
{
	assert( in );

	// row 0
	out_results[0][0] = _mm_add_ps( in->lhs[0][0], in->rhs[0][0] );
	out_results[0][1] = _mm_add_ps( in->lhs[0][1], in->rhs[0][1] );

	// row 1
	out_results[1][0] = _mm_add_ps( in->lhs[1][0], in->rhs[1][0] );
	out_results[1][1] = _mm_add_ps( in->lhs[1][1], in->rhs[1][1] );

	// row 2
	out_results[2][0] = _mm_add_ps( in->lhs[2][0], in->rhs[2][0] );
	out_results[2][1] = _mm_add_ps( in->lhs[2][1], in->rhs[2][1] );
}

void comp_sub_sse( const sse_input_sub_float3x2_t* in, __m128 out_results[3][2] )
{
	assert( in );

	// row 0
	out_results[0][0] = _mm_sub_ps( in->lhs[0][0], in->rhs[0][0] );
	out_results[0][1] = _mm_sub_ps( in->lhs[0][1], in->rhs[0][1] );

	// row 1
	out_results[1][0] = _mm_sub_ps( in->lhs[1][0], in->rhs[1][0] );
	out_results[1][1] = _mm_sub_ps( in->lhs[1][1], in->rhs[1][1] );

	// row 2
	out_results[2][0] = _mm_sub_ps( in->lhs[2][0], in->rhs[2][0] );
	out_results[2][1] = _mm_sub_ps( in->lhs[2][1], in->rhs[2][1] );
}

void comp_mul_sse( const sse_input_mul_float3x2_t* in, __m128 out_results[3][2] )
{
	assert( in );

	// row 0
	out_results[0][0] = _mm_mul_ps( in->lhs[0][0], in->rhs[0][0] );
	out_results[0][1] = _mm_mul_ps( in->lhs[0][1], in->rhs[0][1] );

	// row 1
	out_results[1][0] = _mm_mul_ps( in->lhs[1][0], in->rhs[1][0] );
	out_results[1][1] = _mm_mul_ps( in->lhs[1][1], in->rhs[1][1] );

	// row 2
	out_results[2][0] = _mm_mul_ps( in->lhs[2][0], in->rhs[2][0] );
	out_results[2][1] = _mm_mul_ps( in->lhs[2][1], in->rhs[2][1] );
}

void comp_div_sse( const sse_input_div_float3x2_t* in, __m128 out_results[3][2] )
{
	assert( in );

	// row 0
	out_results[0][0] = _mm_div_ps( in->lhs[0][0], in->rhs[0][0] );
	out_results[0][1] = _mm_div_ps( in->lhs[0][1], in->rhs[0][1] );

	// row 1
	out_results[1][0] = _mm_div_ps( in->lhs[1][0], in->rhs[1][0] );
	out_results[1][1] = _mm_div_ps( in->lhs[1][1], in->rhs[1][1] );

	// row 2
	out_results[2][0] = _mm_div_ps( in->lhs[2][0], in->rhs[2][0] );
	out_results[2][1] = _mm_div_ps( in->lhs[2][1], in->rhs[2][1] );
}

void translate_sse( const sse_input_translate_float3x2_t* in, __m128 out_results[1] )
{
	assert( in );

	out_results[0] = _mm_add_ps( in->column[0], in->vec[0] );
}

void scale_sse( const sse_input_scale_float3x2_t* in, __m128 out_results[2] )
{
	assert( in );

	out_results[0] = _mm_mul_ps( in->diagonal[0], in->scale[0] );
	out_results[1] = _mm_mul_ps( in->diagonal[1], in->scale[1] );
}


// float3x3
void transpose_sse( const sse_input_transpose_float3x3_t* in, __m128 out_results[3][3] )
{
	assert( in );

	out_results[0][0] = in->m[0][0];
	out_results[1][0] = in->m[0][1];
	out_results[2][0] = in->m[0][2];

	out_results[0][1] = in->m[1][0];
	out_results[1][1] = in->m[1][1];
	out_results[2][1] = in->m[1][2];

	out_results[0][2] = in->m[2][0];
	out_results[1][2] = in->m[2][1];
	out_results[2][2] = in->m[2][2];
}

void inverse_sse( const sse_input_inverse_float3x3_t* in, __m128 out_results[3][3] )
{
	assert( in );

	sse_input_determinant_float3x3_t in_det;
	memcpy( in_det.m, in->m, sizeof( in->m ) );

	__m128 determinants;
	determinant_sse( &in_det, &determinants );

	determinants = _mm_rcp_ps( determinants );

	// row 0
	__m128 mul00a = _mm_mul_ps( in->m[1][1], in->m[2][2] );
	__m128 mul00b = _mm_mul_ps( in->m[1][2], in->m[2][1] );
	__m128 mul01a = _mm_mul_ps( in->m[0][1], in->m[2][2] );
	__m128 mul01b = _mm_mul_ps( in->m[0][2], in->m[2][1] );
	__m128 mul02a = _mm_mul_ps( in->m[0][1], in->m[1][2] );
	__m128 mul02b = _mm_mul_ps( in->m[0][2], in->m[1][1] );

	__m128 sub00 = _mm_sub_ps( mul00a, mul00b );
	__m128 sub01 = _mm_sub_ps( mul01a, mul01b );
	__m128 sub02 = _mm_sub_ps( mul02a, mul02b );

	sub00 = _mm_mul_ps( sub00, determinants );
	sub01 = _mm_mul_ps( sub01, determinants );
	sub02 = _mm_mul_ps( sub02, determinants );
	sub01 = _mm_xor_ps( sub01, HLML_ZERO_SSE );

	// row 1
	__m128 mul10a = _mm_mul_ps( in->m[1][0], in->m[2][2] );
	__m128 mul10b = _mm_mul_ps( in->m[1][2], in->m[2][0] );
	__m128 mul11a = _mm_mul_ps( in->m[0][0], in->m[2][2] );
	__m128 mul11b = _mm_mul_ps( in->m[0][2], in->m[2][0] );
	__m128 mul12a = _mm_mul_ps( in->m[0][0], in->m[1][2] );
	__m128 mul12b = _mm_mul_ps( in->m[0][2], in->m[1][0] );

	__m128 sub10 = _mm_sub_ps( mul10a, mul10b );
	__m128 sub11 = _mm_sub_ps( mul11a, mul11b );
	__m128 sub12 = _mm_sub_ps( mul12a, mul12b );

	sub10 = _mm_mul_ps( sub10, determinants );
	sub11 = _mm_mul_ps( sub11, determinants );
	sub12 = _mm_mul_ps( sub12, determinants );
	sub10 = _mm_xor_ps( sub10, HLML_ZERO_SSE );
	sub12 = _mm_xor_ps( sub12, HLML_ZERO_SSE );

	// row 2
	__m128 mul20a = _mm_mul_ps( in->m[1][0], in->m[2][1] );
	__m128 mul20b = _mm_mul_ps( in->m[1][1], in->m[2][0] );
	__m128 mul21a = _mm_mul_ps( in->m[0][0], in->m[2][1] );
	__m128 mul21b = _mm_mul_ps( in->m[0][1], in->m[2][0] );
	__m128 mul22a = _mm_mul_ps( in->m[0][0], in->m[1][1] );
	__m128 mul22b = _mm_mul_ps( in->m[0][1], in->m[1][0] );

	__m128 sub20 = _mm_sub_ps( mul20a, mul20b );
	__m128 sub21 = _mm_sub_ps( mul21a, mul21b );
	__m128 sub22 = _mm_sub_ps( mul22a, mul22b );

	sub20 = _mm_mul_ps( sub20, determinants );
	sub21 = _mm_mul_ps( sub21, determinants );
	sub22 = _mm_mul_ps( sub22, determinants );
	sub21 = _mm_xor_ps( sub21, HLML_ZERO_SSE );

	out_results[0][0] = sub00;
	out_results[0][1] = sub01;
	out_results[0][2] = sub02;

	out_results[1][0] = sub10;
	out_results[1][1] = sub11;
	out_results[1][2] = sub12;

	out_results[2][0] = sub20;
	out_results[2][1] = sub21;
	out_results[2][2] = sub22;
}

void determinant_sse( const sse_input_determinant_float3x3_t* in, __m128* out_result )
{
	assert( in );
	assert( out_result );

	__m128 mul0a = _mm_mul_ps( in->m[1][1], in->m[2][2] );
	__m128 mul0b = _mm_mul_ps( in->m[2][1], in->m[1][2] );
	__m128 sub0  = _mm_sub_ps( mul0a, mul0b );

	__m128 mul1a = _mm_mul_ps( in->m[1][0], in->m[2][2] );
	__m128 mul1b = _mm_mul_ps( in->m[2][0], in->m[1][2] );
	__m128 sub1  = _mm_sub_ps( mul1a, mul1b );

	__m128 mul2a = _mm_mul_ps( in->m[1][0], in->m[2][1] );
	__m128 mul2b = _mm_mul_ps( in->m[2][0], in->m[1][1] );
	__m128 sub2  = _mm_sub_ps( mul2a, mul2b );

	__m128 mul0  = _mm_mul_ps( in->m[0][0], sub0 );
	__m128 mul1  = _mm_mul_ps( in->m[0][1], sub1 );
	__m128 mul2  = _mm_mul_ps( in->m[0][2], sub2 );

	__m128 add0  = _mm_sub_ps( mul0, mul1 );

	*out_result = _mm_add_ps( add0, mul2 );
}

void comp_add_sse( const sse_input_add_float3x3_t* in, __m128 out_results[3][3] )
{
	assert( in );

	// row 0
	out_results[0][0] = _mm_add_ps( in->lhs[0][0], in->rhs[0][0] );
	out_results[0][1] = _mm_add_ps( in->lhs[0][1], in->rhs[0][1] );
	out_results[0][2] = _mm_add_ps( in->lhs[0][2], in->rhs[0][2] );

	// row 1
	out_results[1][0] = _mm_add_ps( in->lhs[1][0], in->rhs[1][0] );
	out_results[1][1] = _mm_add_ps( in->lhs[1][1], in->rhs[1][1] );
	out_results[1][2] = _mm_add_ps( in->lhs[1][2], in->rhs[1][2] );

	// row 2
	out_results[2][0] = _mm_add_ps( in->lhs[2][0], in->rhs[2][0] );
	out_results[2][1] = _mm_add_ps( in->lhs[2][1], in->rhs[2][1] );
	out_results[2][2] = _mm_add_ps( in->lhs[2][2], in->rhs[2][2] );
}

void comp_sub_sse( const sse_input_sub_float3x3_t* in, __m128 out_results[3][3] )
{
	assert( in );

	// row 0
	out_results[0][0] = _mm_sub_ps( in->lhs[0][0], in->rhs[0][0] );
	out_results[0][1] = _mm_sub_ps( in->lhs[0][1], in->rhs[0][1] );
	out_results[0][2] = _mm_sub_ps( in->lhs[0][2], in->rhs[0][2] );

	// row 1
	out_results[1][0] = _mm_sub_ps( in->lhs[1][0], in->rhs[1][0] );
	out_results[1][1] = _mm_sub_ps( in->lhs[1][1], in->rhs[1][1] );
	out_results[1][2] = _mm_sub_ps( in->lhs[1][2], in->rhs[1][2] );

	// row 2
	out_results[2][0] = _mm_sub_ps( in->lhs[2][0], in->rhs[2][0] );
	out_results[2][1] = _mm_sub_ps( in->lhs[2][1], in->rhs[2][1] );
	out_results[2][2] = _mm_sub_ps( in->lhs[2][2], in->rhs[2][2] );
}

void comp_mul_sse( const sse_input_mul_float3x3_t* in, __m128 out_results[3][3] )
{
	assert( in );

	// row 0
	out_results[0][0] = _mm_mul_ps( in->lhs[0][0], in->rhs[0][0] );
	out_results[0][1] = _mm_mul_ps( in->lhs[0][1], in->rhs[0][1] );
	out_results[0][2] = _mm_mul_ps( in->lhs[0][2], in->rhs[0][2] );

	// row 1
	out_results[1][0] = _mm_mul_ps( in->lhs[1][0], in->rhs[1][0] );
	out_results[1][1] = _mm_mul_ps( in->lhs[1][1], in->rhs[1][1] );
	out_results[1][2] = _mm_mul_ps( in->lhs[1][2], in->rhs[1][2] );

	// row 2
	out_results[2][0] = _mm_mul_ps( in->lhs[2][0], in->rhs[2][0] );
	out_results[2][1] = _mm_mul_ps( in->lhs[2][1], in->rhs[2][1] );
	out_results[2][2] = _mm_mul_ps( in->lhs[2][2], in->rhs[2][2] );
}

void comp_div_sse( const sse_input_div_float3x3_t* in, __m128 out_results[3][3] )
{
	assert( in );

	// row 0
	out_results[0][0] = _mm_div_ps( in->lhs[0][0], in->rhs[0][0] );
	out_results[0][1] = _mm_div_ps( in->lhs[0][1], in->rhs[0][1] );
	out_results[0][2] = _mm_div_ps( in->lhs[0][2], in->rhs[0][2] );

	// row 1
	out_results[1][0] = _mm_div_ps( in->lhs[1][0], in->rhs[1][0] );
	out_results[1][1] = _mm_div_ps( in->lhs[1][1], in->rhs[1][1] );
	out_results[1][2] = _mm_div_ps( in->lhs[1][2], in->rhs[1][2] );

	// row 2
	out_results[2][0] = _mm_div_ps( in->lhs[2][0], in->rhs[2][0] );
	out_results[2][1] = _mm_div_ps( in->lhs[2][1], in->rhs[2][1] );
	out_results[2][2] = _mm_div_ps( in->lhs[2][2], in->rhs[2][2] );
}

void translate_sse( const sse_input_translate_float3x3_t* in, __m128 out_results[2] )
{
	assert( in );

	out_results[0] = _mm_add_ps( in->column[0], in->vec[0] );
	out_results[1] = _mm_add_ps( in->column[1], in->vec[1] );
}

void scale_sse( const sse_input_scale_float3x3_t* in, __m128 out_results[3] )
{
	assert( in );

	out_results[0] = _mm_mul_ps( in->diagonal[0], in->scale[0] );
	out_results[1] = _mm_mul_ps( in->diagonal[1], in->scale[1] );
	out_results[2] = _mm_mul_ps( in->diagonal[2], in->scale[2] );
}


// float3x4
void transpose_sse( const sse_input_transpose_float3x4_t* in, __m128 out_results[4][3] )
{
	assert( in );

	out_results[0][0] = in->m[0][0];
	out_results[1][0] = in->m[0][1];
	out_results[2][0] = in->m[0][2];
	out_results[3][0] = in->m[0][3];

	out_results[0][1] = in->m[1][0];
	out_results[1][1] = in->m[1][1];
	out_results[2][1] = in->m[1][2];
	out_results[3][1] = in->m[1][3];

	out_results[0][2] = in->m[2][0];
	out_results[1][2] = in->m[2][1];
	out_results[2][2] = in->m[2][2];
	out_results[3][2] = in->m[2][3];
}

void comp_add_sse( const sse_input_add_float3x4_t* in, __m128 out_results[3][4] )
{
	assert( in );

	// row 0
	out_results[0][0] = _mm_add_ps( in->lhs[0][0], in->rhs[0][0] );
	out_results[0][1] = _mm_add_ps( in->lhs[0][1], in->rhs[0][1] );
	out_results[0][2] = _mm_add_ps( in->lhs[0][2], in->rhs[0][2] );
	out_results[0][3] = _mm_add_ps( in->lhs[0][3], in->rhs[0][3] );

	// row 1
	out_results[1][0] = _mm_add_ps( in->lhs[1][0], in->rhs[1][0] );
	out_results[1][1] = _mm_add_ps( in->lhs[1][1], in->rhs[1][1] );
	out_results[1][2] = _mm_add_ps( in->lhs[1][2], in->rhs[1][2] );
	out_results[1][3] = _mm_add_ps( in->lhs[1][3], in->rhs[1][3] );

	// row 2
	out_results[2][0] = _mm_add_ps( in->lhs[2][0], in->rhs[2][0] );
	out_results[2][1] = _mm_add_ps( in->lhs[2][1], in->rhs[2][1] );
	out_results[2][2] = _mm_add_ps( in->lhs[2][2], in->rhs[2][2] );
	out_results[2][3] = _mm_add_ps( in->lhs[2][3], in->rhs[2][3] );
}

void comp_sub_sse( const sse_input_sub_float3x4_t* in, __m128 out_results[3][4] )
{
	assert( in );

	// row 0
	out_results[0][0] = _mm_sub_ps( in->lhs[0][0], in->rhs[0][0] );
	out_results[0][1] = _mm_sub_ps( in->lhs[0][1], in->rhs[0][1] );
	out_results[0][2] = _mm_sub_ps( in->lhs[0][2], in->rhs[0][2] );
	out_results[0][3] = _mm_sub_ps( in->lhs[0][3], in->rhs[0][3] );

	// row 1
	out_results[1][0] = _mm_sub_ps( in->lhs[1][0], in->rhs[1][0] );
	out_results[1][1] = _mm_sub_ps( in->lhs[1][1], in->rhs[1][1] );
	out_results[1][2] = _mm_sub_ps( in->lhs[1][2], in->rhs[1][2] );
	out_results[1][3] = _mm_sub_ps( in->lhs[1][3], in->rhs[1][3] );

	// row 2
	out_results[2][0] = _mm_sub_ps( in->lhs[2][0], in->rhs[2][0] );
	out_results[2][1] = _mm_sub_ps( in->lhs[2][1], in->rhs[2][1] );
	out_results[2][2] = _mm_sub_ps( in->lhs[2][2], in->rhs[2][2] );
	out_results[2][3] = _mm_sub_ps( in->lhs[2][3], in->rhs[2][3] );
}

void comp_mul_sse( const sse_input_mul_float3x4_t* in, __m128 out_results[3][4] )
{
	assert( in );

	// row 0
	out_results[0][0] = _mm_mul_ps( in->lhs[0][0], in->rhs[0][0] );
	out_results[0][1] = _mm_mul_ps( in->lhs[0][1], in->rhs[0][1] );
	out_results[0][2] = _mm_mul_ps( in->lhs[0][2], in->rhs[0][2] );
	out_results[0][3] = _mm_mul_ps( in->lhs[0][3], in->rhs[0][3] );

	// row 1
	out_results[1][0] = _mm_mul_ps( in->lhs[1][0], in->rhs[1][0] );
	out_results[1][1] = _mm_mul_ps( in->lhs[1][1], in->rhs[1][1] );
	out_results[1][2] = _mm_mul_ps( in->lhs[1][2], in->rhs[1][2] );
	out_results[1][3] = _mm_mul_ps( in->lhs[1][3], in->rhs[1][3] );

	// row 2
	out_results[2][0] = _mm_mul_ps( in->lhs[2][0], in->rhs[2][0] );
	out_results[2][1] = _mm_mul_ps( in->lhs[2][1], in->rhs[2][1] );
	out_results[2][2] = _mm_mul_ps( in->lhs[2][2], in->rhs[2][2] );
	out_results[2][3] = _mm_mul_ps( in->lhs[2][3], in->rhs[2][3] );
}

void comp_div_sse( const sse_input_div_float3x4_t* in, __m128 out_results[3][4] )
{
	assert( in );

	// row 0
	out_results[0][0] = _mm_div_ps( in->lhs[0][0], in->rhs[0][0] );
	out_results[0][1] = _mm_div_ps( in->lhs[0][1], in->rhs[0][1] );
	out_results[0][2] = _mm_div_ps( in->lhs[0][2], in->rhs[0][2] );
	out_results[0][3] = _mm_div_ps( in->lhs[0][3], in->rhs[0][3] );

	// row 1
	out_results[1][0] = _mm_div_ps( in->lhs[1][0], in->rhs[1][0] );
	out_results[1][1] = _mm_div_ps( in->lhs[1][1], in->rhs[1][1] );
	out_results[1][2] = _mm_div_ps( in->lhs[1][2], in->rhs[1][2] );
	out_results[1][3] = _mm_div_ps( in->lhs[1][3], in->rhs[1][3] );

	// row 2
	out_results[2][0] = _mm_div_ps( in->lhs[2][0], in->rhs[2][0] );
	out_results[2][1] = _mm_div_ps( in->lhs[2][1], in->rhs[2][1] );
	out_results[2][2] = _mm_div_ps( in->lhs[2][2], in->rhs[2][2] );
	out_results[2][3] = _mm_div_ps( in->lhs[2][3], in->rhs[2][3] );
}

void translate_sse( const sse_input_translate_float3x4_t* in, __m128 out_results[3] )
{
	assert( in );

	out_results[0] = _mm_add_ps( in->column[0], in->vec[0] );
	out_results[1] = _mm_add_ps( in->column[1], in->vec[1] );
	out_results[2] = _mm_add_ps( in->column[2], in->vec[2] );
}

void scale_sse( const sse_input_scale_float3x4_t* in, __m128 out_results[3] )
{
	assert( in );

	out_results[0] = _mm_mul_ps( in->diagonal[0], in->scale[0] );
	out_results[1] = _mm_mul_ps( in->diagonal[1], in->scale[1] );
	out_results[2] = _mm_mul_ps( in->diagonal[2], in->scale[2] );
}


// float4x2
void transpose_sse( const sse_input_transpose_float4x2_t* in, __m128 out_results[2][4] )
{
	assert( in );

	out_results[0][0] = in->m[0][0];
	out_results[1][0] = in->m[0][1];

	out_results[0][1] = in->m[1][0];
	out_results[1][1] = in->m[1][1];

	out_results[0][2] = in->m[2][0];
	out_results[1][2] = in->m[2][1];

	out_results[0][3] = in->m[3][0];
	out_results[1][3] = in->m[3][1];
}

void comp_add_sse( const sse_input_add_float4x2_t* in, __m128 out_results[4][2] )
{
	assert( in );

	// row 0
	out_results[0][0] = _mm_add_ps( in->lhs[0][0], in->rhs[0][0] );
	out_results[0][1] = _mm_add_ps( in->lhs[0][1], in->rhs[0][1] );

	// row 1
	out_results[1][0] = _mm_add_ps( in->lhs[1][0], in->rhs[1][0] );
	out_results[1][1] = _mm_add_ps( in->lhs[1][1], in->rhs[1][1] );

	// row 2
	out_results[2][0] = _mm_add_ps( in->lhs[2][0], in->rhs[2][0] );
	out_results[2][1] = _mm_add_ps( in->lhs[2][1], in->rhs[2][1] );

	// row 3
	out_results[3][0] = _mm_add_ps( in->lhs[3][0], in->rhs[3][0] );
	out_results[3][1] = _mm_add_ps( in->lhs[3][1], in->rhs[3][1] );
}

void comp_sub_sse( const sse_input_sub_float4x2_t* in, __m128 out_results[4][2] )
{
	assert( in );

	// row 0
	out_results[0][0] = _mm_sub_ps( in->lhs[0][0], in->rhs[0][0] );
	out_results[0][1] = _mm_sub_ps( in->lhs[0][1], in->rhs[0][1] );

	// row 1
	out_results[1][0] = _mm_sub_ps( in->lhs[1][0], in->rhs[1][0] );
	out_results[1][1] = _mm_sub_ps( in->lhs[1][1], in->rhs[1][1] );

	// row 2
	out_results[2][0] = _mm_sub_ps( in->lhs[2][0], in->rhs[2][0] );
	out_results[2][1] = _mm_sub_ps( in->lhs[2][1], in->rhs[2][1] );

	// row 3
	out_results[3][0] = _mm_sub_ps( in->lhs[3][0], in->rhs[3][0] );
	out_results[3][1] = _mm_sub_ps( in->lhs[3][1], in->rhs[3][1] );
}

void comp_mul_sse( const sse_input_mul_float4x2_t* in, __m128 out_results[4][2] )
{
	assert( in );

	// row 0
	out_results[0][0] = _mm_mul_ps( in->lhs[0][0], in->rhs[0][0] );
	out_results[0][1] = _mm_mul_ps( in->lhs[0][1], in->rhs[0][1] );

	// row 1
	out_results[1][0] = _mm_mul_ps( in->lhs[1][0], in->rhs[1][0] );
	out_results[1][1] = _mm_mul_ps( in->lhs[1][1], in->rhs[1][1] );

	// row 2
	out_results[2][0] = _mm_mul_ps( in->lhs[2][0], in->rhs[2][0] );
	out_results[2][1] = _mm_mul_ps( in->lhs[2][1], in->rhs[2][1] );

	// row 3
	out_results[3][0] = _mm_mul_ps( in->lhs[3][0], in->rhs[3][0] );
	out_results[3][1] = _mm_mul_ps( in->lhs[3][1], in->rhs[3][1] );
}

void comp_div_sse( const sse_input_div_float4x2_t* in, __m128 out_results[4][2] )
{
	assert( in );

	// row 0
	out_results[0][0] = _mm_div_ps( in->lhs[0][0], in->rhs[0][0] );
	out_results[0][1] = _mm_div_ps( in->lhs[0][1], in->rhs[0][1] );

	// row 1
	out_results[1][0] = _mm_div_ps( in->lhs[1][0], in->rhs[1][0] );
	out_results[1][1] = _mm_div_ps( in->lhs[1][1], in->rhs[1][1] );

	// row 2
	out_results[2][0] = _mm_div_ps( in->lhs[2][0], in->rhs[2][0] );
	out_results[2][1] = _mm_div_ps( in->lhs[2][1], in->rhs[2][1] );

	// row 3
	out_results[3][0] = _mm_div_ps( in->lhs[3][0], in->rhs[3][0] );
	out_results[3][1] = _mm_div_ps( in->lhs[3][1], in->rhs[3][1] );
}

void translate_sse( const sse_input_translate_float4x2_t* in, __m128 out_results[1] )
{
	assert( in );

	out_results[0] = _mm_add_ps( in->column[0], in->vec[0] );
}

void scale_sse( const sse_input_scale_float4x2_t* in, __m128 out_results[2] )
{
	assert( in );

	out_results[0] = _mm_mul_ps( in->diagonal[0], in->scale[0] );
	out_results[1] = _mm_mul_ps( in->diagonal[1], in->scale[1] );
}


// float4x3
void transpose_sse( const sse_input_transpose_float4x3_t* in, __m128 out_results[3][4] )
{
	assert( in );

	out_results[0][0] = in->m[0][0];
	out_results[1][0] = in->m[0][1];
	out_results[2][0] = in->m[0][2];

	out_results[0][1] = in->m[1][0];
	out_results[1][1] = in->m[1][1];
	out_results[2][1] = in->m[1][2];

	out_results[0][2] = in->m[2][0];
	out_results[1][2] = in->m[2][1];
	out_results[2][2] = in->m[2][2];

	out_results[0][3] = in->m[3][0];
	out_results[1][3] = in->m[3][1];
	out_results[2][3] = in->m[3][2];
}

void comp_add_sse( const sse_input_add_float4x3_t* in, __m128 out_results[4][3] )
{
	assert( in );

	// row 0
	out_results[0][0] = _mm_add_ps( in->lhs[0][0], in->rhs[0][0] );
	out_results[0][1] = _mm_add_ps( in->lhs[0][1], in->rhs[0][1] );
	out_results[0][2] = _mm_add_ps( in->lhs[0][2], in->rhs[0][2] );

	// row 1
	out_results[1][0] = _mm_add_ps( in->lhs[1][0], in->rhs[1][0] );
	out_results[1][1] = _mm_add_ps( in->lhs[1][1], in->rhs[1][1] );
	out_results[1][2] = _mm_add_ps( in->lhs[1][2], in->rhs[1][2] );

	// row 2
	out_results[2][0] = _mm_add_ps( in->lhs[2][0], in->rhs[2][0] );
	out_results[2][1] = _mm_add_ps( in->lhs[2][1], in->rhs[2][1] );
	out_results[2][2] = _mm_add_ps( in->lhs[2][2], in->rhs[2][2] );

	// row 3
	out_results[3][0] = _mm_add_ps( in->lhs[3][0], in->rhs[3][0] );
	out_results[3][1] = _mm_add_ps( in->lhs[3][1], in->rhs[3][1] );
	out_results[3][2] = _mm_add_ps( in->lhs[3][2], in->rhs[3][2] );
}

void comp_sub_sse( const sse_input_sub_float4x3_t* in, __m128 out_results[4][3] )
{
	assert( in );

	// row 0
	out_results[0][0] = _mm_sub_ps( in->lhs[0][0], in->rhs[0][0] );
	out_results[0][1] = _mm_sub_ps( in->lhs[0][1], in->rhs[0][1] );
	out_results[0][2] = _mm_sub_ps( in->lhs[0][2], in->rhs[0][2] );

	// row 1
	out_results[1][0] = _mm_sub_ps( in->lhs[1][0], in->rhs[1][0] );
	out_results[1][1] = _mm_sub_ps( in->lhs[1][1], in->rhs[1][1] );
	out_results[1][2] = _mm_sub_ps( in->lhs[1][2], in->rhs[1][2] );

	// row 2
	out_results[2][0] = _mm_sub_ps( in->lhs[2][0], in->rhs[2][0] );
	out_results[2][1] = _mm_sub_ps( in->lhs[2][1], in->rhs[2][1] );
	out_results[2][2] = _mm_sub_ps( in->lhs[2][2], in->rhs[2][2] );

	// row 3
	out_results[3][0] = _mm_sub_ps( in->lhs[3][0], in->rhs[3][0] );
	out_results[3][1] = _mm_sub_ps( in->lhs[3][1], in->rhs[3][1] );
	out_results[3][2] = _mm_sub_ps( in->lhs[3][2], in->rhs[3][2] );
}

void comp_mul_sse( const sse_input_mul_float4x3_t* in, __m128 out_results[4][3] )
{
	assert( in );

	// row 0
	out_results[0][0] = _mm_mul_ps( in->lhs[0][0], in->rhs[0][0] );
	out_results[0][1] = _mm_mul_ps( in->lhs[0][1], in->rhs[0][1] );
	out_results[0][2] = _mm_mul_ps( in->lhs[0][2], in->rhs[0][2] );

	// row 1
	out_results[1][0] = _mm_mul_ps( in->lhs[1][0], in->rhs[1][0] );
	out_results[1][1] = _mm_mul_ps( in->lhs[1][1], in->rhs[1][1] );
	out_results[1][2] = _mm_mul_ps( in->lhs[1][2], in->rhs[1][2] );

	// row 2
	out_results[2][0] = _mm_mul_ps( in->lhs[2][0], in->rhs[2][0] );
	out_results[2][1] = _mm_mul_ps( in->lhs[2][1], in->rhs[2][1] );
	out_results[2][2] = _mm_mul_ps( in->lhs[2][2], in->rhs[2][2] );

	// row 3
	out_results[3][0] = _mm_mul_ps( in->lhs[3][0], in->rhs[3][0] );
	out_results[3][1] = _mm_mul_ps( in->lhs[3][1], in->rhs[3][1] );
	out_results[3][2] = _mm_mul_ps( in->lhs[3][2], in->rhs[3][2] );
}

void comp_div_sse( const sse_input_div_float4x3_t* in, __m128 out_results[4][3] )
{
	assert( in );

	// row 0
	out_results[0][0] = _mm_div_ps( in->lhs[0][0], in->rhs[0][0] );
	out_results[0][1] = _mm_div_ps( in->lhs[0][1], in->rhs[0][1] );
	out_results[0][2] = _mm_div_ps( in->lhs[0][2], in->rhs[0][2] );

	// row 1
	out_results[1][0] = _mm_div_ps( in->lhs[1][0], in->rhs[1][0] );
	out_results[1][1] = _mm_div_ps( in->lhs[1][1], in->rhs[1][1] );
	out_results[1][2] = _mm_div_ps( in->lhs[1][2], in->rhs[1][2] );

	// row 2
	out_results[2][0] = _mm_div_ps( in->lhs[2][0], in->rhs[2][0] );
	out_results[2][1] = _mm_div_ps( in->lhs[2][1], in->rhs[2][1] );
	out_results[2][2] = _mm_div_ps( in->lhs[2][2], in->rhs[2][2] );

	// row 3
	out_results[3][0] = _mm_div_ps( in->lhs[3][0], in->rhs[3][0] );
	out_results[3][1] = _mm_div_ps( in->lhs[3][1], in->rhs[3][1] );
	out_results[3][2] = _mm_div_ps( in->lhs[3][2], in->rhs[3][2] );
}

void translate_sse( const sse_input_translate_float4x3_t* in, __m128 out_results[2] )
{
	assert( in );

	out_results[0] = _mm_add_ps( in->column[0], in->vec[0] );
	out_results[1] = _mm_add_ps( in->column[1], in->vec[1] );
}

void scale_sse( const sse_input_scale_float4x3_t* in, __m128 out_results[3] )
{
	assert( in );

	out_results[0] = _mm_mul_ps( in->diagonal[0], in->scale[0] );
	out_results[1] = _mm_mul_ps( in->diagonal[1], in->scale[1] );
	out_results[2] = _mm_mul_ps( in->diagonal[2], in->scale[2] );
}


// float4x4
void transpose_sse( const sse_input_transpose_float4x4_t* in, __m128 out_results[4][4] )
{
	assert( in );

	out_results[0][0] = in->m[0][0];
	out_results[1][0] = in->m[0][1];
	out_results[2][0] = in->m[0][2];
	out_results[3][0] = in->m[0][3];

	out_results[0][1] = in->m[1][0];
	out_results[1][1] = in->m[1][1];
	out_results[2][1] = in->m[1][2];
	out_results[3][1] = in->m[1][3];

	out_results[0][2] = in->m[2][0];
	out_results[1][2] = in->m[2][1];
	out_results[2][2] = in->m[2][2];
	out_results[3][2] = in->m[2][3];

	out_results[0][3] = in->m[3][0];
	out_results[1][3] = in->m[3][1];
	out_results[2][3] = in->m[3][2];
	out_results[3][3] = in->m[3][3];
}

void inverse_sse( const sse_input_inverse_float4x4_t* in, __m128 out_results[4][4] )
{
	assert( in );

	sse_input_determinant_float4x4_t in_det;
	memcpy( in_det.m, in->m, sizeof( in->m ) );

	__m128 determinants;
	determinant_sse( &in_det, &determinants );

	determinants = _mm_rcp_ps( determinants );

	// TODO(DM): this
	( (void) out_results ); // unused
}

void determinant_sse( const sse_input_determinant_float4x4_t* in, __m128* out_result )
{
	assert( in );
	assert( out_result );

	__m128 submul0a      = _mm_mul_ps( in->m[2][2], in->m[3][3] );
	__m128 submul0b      = _mm_mul_ps( in->m[3][2], in->m[2][3] );
	__m128 sub0          = _mm_sub_ps( submul0a, submul0b );

	__m128 submul1a      = _mm_mul_ps( in->m[2][1], in->m[3][3] );
	__m128 submul1b      = _mm_mul_ps( in->m[2][3], in->m[3][1] );
	__m128 sub1          = _mm_sub_ps( submul1a, submul1b );

	__m128 submul2a      = _mm_mul_ps( in->m[2][1], in->m[3][2] );
	__m128 submul2b      = _mm_mul_ps( in->m[3][1], in->m[2][2] );
	__m128 sub2          = _mm_sub_ps( submul2a, submul2b );

	__m128 submul3a      = _mm_mul_ps( in->m[2][0], in->m[3][3] );
	__m128 submul3b      = _mm_mul_ps( in->m[3][0], in->m[2][3] );
	__m128 sub3          = _mm_sub_ps( submul3a, submul3b );

	__m128 submul4a      = _mm_mul_ps( in->m[2][0], in->m[3][2] );
	__m128 submul4b      = _mm_mul_ps( in->m[3][0], in->m[2][2] );
	__m128 sub4          = _mm_sub_ps( submul4a, submul4b );

	__m128 submul5a      = _mm_mul_ps( in->m[2][0], in->m[3][1] );
	__m128 submul5b      = _mm_mul_ps( in->m[3][0], in->m[2][1] );
	__m128 sub5          = _mm_sub_ps( submul5a, submul5b );

	__m128 cofactor0mul0 = _mm_mul_ps( in->m[1][1], sub0 );
	__m128 cofactor0mul1 = _mm_mul_ps( in->m[1][2], sub1 );
	__m128 cofactor0mul2 = _mm_mul_ps( in->m[1][3], sub2 );
	__m128 cofactor0sub  = _mm_sub_ps( cofactor0mul0, cofactor0mul1 );
	__m128 cofactor0     = _mm_add_ps( cofactor0sub, cofactor0mul2 );

	__m128 cofactor1mul0 = _mm_mul_ps( in->m[1][0], sub0 );
	__m128 cofactor1mul1 = _mm_mul_ps( in->m[1][2], sub3 );
	__m128 cofactor1mul2 = _mm_mul_ps( in->m[1][3], sub4 );
	__m128 cofactor1sub  = _mm_sub_ps( cofactor1mul0, cofactor1mul1 );
	__m128 cofactor1     = _mm_add_ps( cofactor1sub, cofactor1mul2 );
	cofactor1 = _mm_sub_ps( HLML_ZERO_SSE, cofactor1 );

	__m128 cofactor2mul0 = _mm_mul_ps( in->m[1][0], sub1 );
	__m128 cofactor2mul1 = _mm_mul_ps( in->m[1][1], sub3 );
	__m128 cofactor2mul2 = _mm_mul_ps( in->m[1][3], sub5 );
	__m128 cofactor2sub  = _mm_sub_ps( cofactor2mul0, cofactor2mul1 );
	__m128 cofactor2     = _mm_add_ps( cofactor2sub, cofactor2mul2 );

	__m128 cofactor3mul0 = _mm_mul_ps( in->m[1][0], sub2 );
	__m128 cofactor3mul1 = _mm_mul_ps( in->m[1][1], sub4 );
	__m128 cofactor3mul2 = _mm_mul_ps( in->m[1][2], sub5 );
	__m128 cofactor3sub  = _mm_sub_ps( cofactor3mul0, cofactor3mul1 );
	__m128 cofactor3     = _mm_add_ps( cofactor3sub, cofactor3mul2 );
	cofactor3 = _mm_sub_ps( HLML_ZERO_SSE, cofactor3 );

	__m128 finalmul0     = _mm_mul_ps( in->m[0][0], cofactor0 );
	__m128 finalmul1     = _mm_mul_ps( in->m[0][1], cofactor1 );
	__m128 finalmul2     = _mm_mul_ps( in->m[0][2], cofactor2 );
	__m128 finalmul3     = _mm_mul_ps( in->m[0][3], cofactor3 );

	__m128 final0        = _mm_add_ps( finalmul0, finalmul1 );
	__m128 final1        = _mm_add_ps( finalmul2, finalmul3 );

	*out_result = _mm_add_ps( final0, final1 );
}

void comp_add_sse( const sse_input_add_float4x4_t* in, __m128 out_results[4][4] )
{
	assert( in );

	// row 0
	out_results[0][0] = _mm_add_ps( in->lhs[0][0], in->rhs[0][0] );
	out_results[0][1] = _mm_add_ps( in->lhs[0][1], in->rhs[0][1] );
	out_results[0][2] = _mm_add_ps( in->lhs[0][2], in->rhs[0][2] );
	out_results[0][3] = _mm_add_ps( in->lhs[0][3], in->rhs[0][3] );

	// row 1
	out_results[1][0] = _mm_add_ps( in->lhs[1][0], in->rhs[1][0] );
	out_results[1][1] = _mm_add_ps( in->lhs[1][1], in->rhs[1][1] );
	out_results[1][2] = _mm_add_ps( in->lhs[1][2], in->rhs[1][2] );
	out_results[1][3] = _mm_add_ps( in->lhs[1][3], in->rhs[1][3] );

	// row 2
	out_results[2][0] = _mm_add_ps( in->lhs[2][0], in->rhs[2][0] );
	out_results[2][1] = _mm_add_ps( in->lhs[2][1], in->rhs[2][1] );
	out_results[2][2] = _mm_add_ps( in->lhs[2][2], in->rhs[2][2] );
	out_results[2][3] = _mm_add_ps( in->lhs[2][3], in->rhs[2][3] );

	// row 3
	out_results[3][0] = _mm_add_ps( in->lhs[3][0], in->rhs[3][0] );
	out_results[3][1] = _mm_add_ps( in->lhs[3][1], in->rhs[3][1] );
	out_results[3][2] = _mm_add_ps( in->lhs[3][2], in->rhs[3][2] );
	out_results[3][3] = _mm_add_ps( in->lhs[3][3], in->rhs[3][3] );
}

void comp_sub_sse( const sse_input_sub_float4x4_t* in, __m128 out_results[4][4] )
{
	assert( in );

	// row 0
	out_results[0][0] = _mm_sub_ps( in->lhs[0][0], in->rhs[0][0] );
	out_results[0][1] = _mm_sub_ps( in->lhs[0][1], in->rhs[0][1] );
	out_results[0][2] = _mm_sub_ps( in->lhs[0][2], in->rhs[0][2] );
	out_results[0][3] = _mm_sub_ps( in->lhs[0][3], in->rhs[0][3] );

	// row 1
	out_results[1][0] = _mm_sub_ps( in->lhs[1][0], in->rhs[1][0] );
	out_results[1][1] = _mm_sub_ps( in->lhs[1][1], in->rhs[1][1] );
	out_results[1][2] = _mm_sub_ps( in->lhs[1][2], in->rhs[1][2] );
	out_results[1][3] = _mm_sub_ps( in->lhs[1][3], in->rhs[1][3] );

	// row 2
	out_results[2][0] = _mm_sub_ps( in->lhs[2][0], in->rhs[2][0] );
	out_results[2][1] = _mm_sub_ps( in->lhs[2][1], in->rhs[2][1] );
	out_results[2][2] = _mm_sub_ps( in->lhs[2][2], in->rhs[2][2] );
	out_results[2][3] = _mm_sub_ps( in->lhs[2][3], in->rhs[2][3] );

	// row 3
	out_results[3][0] = _mm_sub_ps( in->lhs[3][0], in->rhs[3][0] );
	out_results[3][1] = _mm_sub_ps( in->lhs[3][1], in->rhs[3][1] );
	out_results[3][2] = _mm_sub_ps( in->lhs[3][2], in->rhs[3][2] );
	out_results[3][3] = _mm_sub_ps( in->lhs[3][3], in->rhs[3][3] );
}

void comp_mul_sse( const sse_input_mul_float4x4_t* in, __m128 out_results[4][4] )
{
	assert( in );

	// row 0
	out_results[0][0] = _mm_mul_ps( in->lhs[0][0], in->rhs[0][0] );
	out_results[0][1] = _mm_mul_ps( in->lhs[0][1], in->rhs[0][1] );
	out_results[0][2] = _mm_mul_ps( in->lhs[0][2], in->rhs[0][2] );
	out_results[0][3] = _mm_mul_ps( in->lhs[0][3], in->rhs[0][3] );

	// row 1
	out_results[1][0] = _mm_mul_ps( in->lhs[1][0], in->rhs[1][0] );
	out_results[1][1] = _mm_mul_ps( in->lhs[1][1], in->rhs[1][1] );
	out_results[1][2] = _mm_mul_ps( in->lhs[1][2], in->rhs[1][2] );
	out_results[1][3] = _mm_mul_ps( in->lhs[1][3], in->rhs[1][3] );

	// row 2
	out_results[2][0] = _mm_mul_ps( in->lhs[2][0], in->rhs[2][0] );
	out_results[2][1] = _mm_mul_ps( in->lhs[2][1], in->rhs[2][1] );
	out_results[2][2] = _mm_mul_ps( in->lhs[2][2], in->rhs[2][2] );
	out_results[2][3] = _mm_mul_ps( in->lhs[2][3], in->rhs[2][3] );

	// row 3
	out_results[3][0] = _mm_mul_ps( in->lhs[3][0], in->rhs[3][0] );
	out_results[3][1] = _mm_mul_ps( in->lhs[3][1], in->rhs[3][1] );
	out_results[3][2] = _mm_mul_ps( in->lhs[3][2], in->rhs[3][2] );
	out_results[3][3] = _mm_mul_ps( in->lhs[3][3], in->rhs[3][3] );
}

void comp_div_sse( const sse_input_div_float4x4_t* in, __m128 out_results[4][4] )
{
	assert( in );

	// row 0
	out_results[0][0] = _mm_div_ps( in->lhs[0][0], in->rhs[0][0] );
	out_results[0][1] = _mm_div_ps( in->lhs[0][1], in->rhs[0][1] );
	out_results[0][2] = _mm_div_ps( in->lhs[0][2], in->rhs[0][2] );
	out_results[0][3] = _mm_div_ps( in->lhs[0][3], in->rhs[0][3] );

	// row 1
	out_results[1][0] = _mm_div_ps( in->lhs[1][0], in->rhs[1][0] );
	out_results[1][1] = _mm_div_ps( in->lhs[1][1], in->rhs[1][1] );
	out_results[1][2] = _mm_div_ps( in->lhs[1][2], in->rhs[1][2] );
	out_results[1][3] = _mm_div_ps( in->lhs[1][3], in->rhs[1][3] );

	// row 2
	out_results[2][0] = _mm_div_ps( in->lhs[2][0], in->rhs[2][0] );
	out_results[2][1] = _mm_div_ps( in->lhs[2][1], in->rhs[2][1] );
	out_results[2][2] = _mm_div_ps( in->lhs[2][2], in->rhs[2][2] );
	out_results[2][3] = _mm_div_ps( in->lhs[2][3], in->rhs[2][3] );

	// row 3
	out_results[3][0] = _mm_div_ps( in->lhs[3][0], in->rhs[3][0] );
	out_results[3][1] = _mm_div_ps( in->lhs[3][1], in->rhs[3][1] );
	out_results[3][2] = _mm_div_ps( in->lhs[3][2], in->rhs[3][2] );
	out_results[3][3] = _mm_div_ps( in->lhs[3][3], in->rhs[3][3] );
}

void translate_sse( const sse_input_translate_float4x4_t* in, __m128 out_results[3] )
{
	assert( in );

	out_results[0] = _mm_add_ps( in->column[0], in->vec[0] );
	out_results[1] = _mm_add_ps( in->column[1], in->vec[1] );
	out_results[2] = _mm_add_ps( in->column[2], in->vec[2] );
}

void scale_sse( const sse_input_scale_float4x4_t* in, __m128 out_results[4] )
{
	assert( in );

	out_results[0] = _mm_mul_ps( in->diagonal[0], in->scale[0] );
	out_results[1] = _mm_mul_ps( in->diagonal[1], in->scale[1] );
	out_results[2] = _mm_mul_ps( in->diagonal[2], in->scale[2] );
	out_results[3] = _mm_mul_ps( in->diagonal[3], in->scale[3] );
}



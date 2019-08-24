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

// float2x2
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



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

// float2
void lengthsq_sse( const sse_input_length_float2_t& in, __m128* out_results )
{
	sse_input_dot_float2_t data;

	data.lhs[0] = in.comp[0];
	data.lhs[1] = in.comp[1];

	data.rhs[0] = in.comp[0];
	data.rhs[1] = in.comp[1];

	dot_sse( data, out_results );
}

void length_sse( const sse_input_length_float2_t& in, __m128* out_results )
{
	lengthsq_sse( in, out_results );
	*out_results = _mm_sqrt_ps( *out_results );
}

void normalize_sse( const sse_input_normalize_float2_t& in, __m128 out_results[2] )
{
	__m128 one = _mm_set1_ps( 1.0f );

	__m128 len;

	sse_input_length_float2_t inLength;
	memcpy( inLength.comp, in.comp, 2 * sizeof( __m128 ) );
	length_sse( inLength, &len );

	__m128 invlen = _mm_div_ps( one, len );

	out_results[0] = _mm_mul_ps( in.comp[0], invlen );
	out_results[1] = _mm_mul_ps( in.comp[1], invlen );
}

void dot_sse( const sse_input_dot_float2_t& in, __m128* out_results )
{
	__m128 mul0 = _mm_mul_ps( in.lhs[0], in.rhs[0] );
	__m128 mul1 = _mm_mul_ps( in.lhs[1], in.rhs[1] );

	*out_results = _mm_add_ps( mul0, mul1 );
}

void distancesq_sse( const sse_input_distance_float2_t& in, __m128* out_results )
{
	sse_input_length_float2_t data;

	data.comp[0] = _mm_sub_ps( in.lhs[0], in.rhs[0] );
	data.comp[1] = _mm_sub_ps( in.lhs[1], in.rhs[1] );

	lengthsq_sse( data, out_results );
}

void distance_sse( const sse_input_distance_float2_t& in, __m128* out_results )
{
	sse_input_length_float2_t data;

	data.comp[0] = _mm_sub_ps( in.lhs[0], in.rhs[0] );
	data.comp[1] = _mm_sub_ps( in.lhs[1], in.rhs[1] );

	length_sse( data, out_results );
}


// float3
void lengthsq_sse( const sse_input_length_float3_t& in, __m128* out_results )
{
	sse_input_dot_float3_t data;

	data.lhs[0] = in.comp[0];
	data.lhs[1] = in.comp[1];
	data.lhs[2] = in.comp[2];

	data.rhs[0] = in.comp[0];
	data.rhs[1] = in.comp[1];
	data.rhs[2] = in.comp[2];

	dot_sse( data, out_results );
}

void length_sse( const sse_input_length_float3_t& in, __m128* out_results )
{
	lengthsq_sse( in, out_results );
	*out_results = _mm_sqrt_ps( *out_results );
}

void normalize_sse( const sse_input_normalize_float3_t& in, __m128 out_results[3] )
{
	__m128 one = _mm_set1_ps( 1.0f );

	__m128 len;

	sse_input_length_float3_t inLength;
	memcpy( inLength.comp, in.comp, 3 * sizeof( __m128 ) );
	length_sse( inLength, &len );

	__m128 invlen = _mm_div_ps( one, len );

	out_results[0] = _mm_mul_ps( in.comp[0], invlen );
	out_results[1] = _mm_mul_ps( in.comp[1], invlen );
	out_results[2] = _mm_mul_ps( in.comp[2], invlen );
}

void dot_sse( const sse_input_dot_float3_t& in, __m128* out_results )
{
	__m128 mul0 = _mm_mul_ps( in.lhs[0], in.rhs[0] );
	__m128 mul1 = _mm_mul_ps( in.lhs[1], in.rhs[1] );
	__m128 mul2 = _mm_mul_ps( in.lhs[2], in.rhs[2] );

	__m128 add0 = _mm_add_ps( mul0, mul1 );

	*out_results = _mm_add_ps( add0, mul2 );
}

void distancesq_sse( const sse_input_distance_float3_t& in, __m128* out_results )
{
	sse_input_length_float3_t data;

	data.comp[0] = _mm_sub_ps( in.lhs[0], in.rhs[0] );
	data.comp[1] = _mm_sub_ps( in.lhs[1], in.rhs[1] );
	data.comp[2] = _mm_sub_ps( in.lhs[2], in.rhs[2] );

	lengthsq_sse( data, out_results );
}

void distance_sse( const sse_input_distance_float3_t& in, __m128* out_results )
{
	sse_input_length_float3_t data;

	data.comp[0] = _mm_sub_ps( in.lhs[0], in.rhs[0] );
	data.comp[1] = _mm_sub_ps( in.lhs[1], in.rhs[1] );
	data.comp[2] = _mm_sub_ps( in.lhs[2], in.rhs[2] );

	length_sse( data, out_results );
}


// float4
void lengthsq_sse( const sse_input_length_float4_t& in, __m128* out_results )
{
	sse_input_dot_float4_t data;

	data.lhs[0] = in.comp[0];
	data.lhs[1] = in.comp[1];
	data.lhs[2] = in.comp[2];
	data.lhs[3] = in.comp[3];

	data.rhs[0] = in.comp[0];
	data.rhs[1] = in.comp[1];
	data.rhs[2] = in.comp[2];
	data.rhs[3] = in.comp[3];

	dot_sse( data, out_results );
}

void length_sse( const sse_input_length_float4_t& in, __m128* out_results )
{
	lengthsq_sse( in, out_results );
	*out_results = _mm_sqrt_ps( *out_results );
}

void normalize_sse( const sse_input_normalize_float4_t& in, __m128 out_results[4] )
{
	__m128 one = _mm_set1_ps( 1.0f );

	__m128 len;

	sse_input_length_float4_t inLength;
	memcpy( inLength.comp, in.comp, 4 * sizeof( __m128 ) );
	length_sse( inLength, &len );

	__m128 invlen = _mm_div_ps( one, len );

	out_results[0] = _mm_mul_ps( in.comp[0], invlen );
	out_results[1] = _mm_mul_ps( in.comp[1], invlen );
	out_results[2] = _mm_mul_ps( in.comp[2], invlen );
	out_results[3] = _mm_mul_ps( in.comp[3], invlen );
}

void dot_sse( const sse_input_dot_float4_t& in, __m128* out_results )
{
	__m128 mul0 = _mm_mul_ps( in.lhs[0], in.rhs[0] );
	__m128 mul1 = _mm_mul_ps( in.lhs[1], in.rhs[1] );
	__m128 mul2 = _mm_mul_ps( in.lhs[2], in.rhs[2] );
	__m128 mul3 = _mm_mul_ps( in.lhs[3], in.rhs[3] );

	__m128 add0 = _mm_add_ps( mul0, mul1 );
	__m128 add1 = _mm_add_ps( mul2, mul3 );

	*out_results = _mm_add_ps( add0, add1 );
}

void distancesq_sse( const sse_input_distance_float4_t& in, __m128* out_results )
{
	sse_input_length_float4_t data;

	data.comp[0] = _mm_sub_ps( in.lhs[0], in.rhs[0] );
	data.comp[1] = _mm_sub_ps( in.lhs[1], in.rhs[1] );
	data.comp[2] = _mm_sub_ps( in.lhs[2], in.rhs[2] );
	data.comp[3] = _mm_sub_ps( in.lhs[3], in.rhs[3] );

	lengthsq_sse( data, out_results );
}

void distance_sse( const sse_input_distance_float4_t& in, __m128* out_results )
{
	sse_input_length_float4_t data;

	data.comp[0] = _mm_sub_ps( in.lhs[0], in.rhs[0] );
	data.comp[1] = _mm_sub_ps( in.lhs[1], in.rhs[1] );
	data.comp[2] = _mm_sub_ps( in.lhs[2], in.rhs[2] );
	data.comp[3] = _mm_sub_ps( in.lhs[3], in.rhs[3] );

	length_sse( data, out_results );
}



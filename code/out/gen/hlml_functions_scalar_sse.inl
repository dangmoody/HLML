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

#include <assert.h>

#include "../hlml_constants_sse.h"

// float
void radians_sse( const sse_input_radians_float_t* in, __m128* out_results )
{
	assert( in );
	assert( out_results );

	*out_results = _mm_mul_ps( in->deg, HLML_DEG_TO_RAD_SSE );
}

void degrees_sse( const sse_input_degrees_float_t* in, __m128* out_results )
{
	assert( in );
	assert( out_results );

	*out_results = _mm_mul_ps( in->rad, HLML_RAD_TO_DEG_SSE );
}

void lerp_sse( const sse_input_lerp_float_t* in, __m128* out_results )
{
	assert( in );
	assert( out_results );

	__m128 one = _mm_set1_ps( 1.0f );

	__m128 sub0 = _mm_sub_ps( one, in->t );

	__m128 mul0 = _mm_mul_ps( sub0, in->lhs );
	__m128 mul1 = _mm_mul_ps( in->t, in->rhs );

	*out_results = _mm_add_ps( mul0, mul1 );
}



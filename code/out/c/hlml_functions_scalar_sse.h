/*
===========================================================================

HLML.

MIT License

Copyright (c) 2019 Dan Moody

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

===========================================================================
*/

// THIS FILE WAS AUTOMATICALLY GENERATED BY A TOOL.
// EDITING THIS FILE MAY CAUSE SIDE EFFECTS.
// DO SO AT YOUR OWN RISK.

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

// HLML includes
#include "../hlml_constants_sse.h"

// others
#include <xmmintrin.h>
#include <assert.h>

// float
/// \brief Converts each component of the given __m128 from degrees to radians.
inline static void radiansf_sse( const __m128 deg, __m128* out_radians )
{
	assert( out_radians );

	*out_radians = _mm_mul_ps( deg, HLML_DEG_TO_RAD_SSE );
}

/// \brief Converts each component of the given __m128 from radians to degrees.
inline static void degreesf_sse( const __m128 rad, __m128* out_degrees )
{
	assert( out_degrees );

	*out_degrees = _mm_mul_ps( rad, HLML_RAD_TO_DEG_SSE );
}

/// \brief Lerps each component of register 'lhs' against the corresponding component of register 'rhs' by the corresponding component of register 't'.
inline static void lerpf_sse( const __m128 lhs, const __m128 rhs, const __m128 t, __m128* out_results )
{
	assert( out_results );

	__m128 sub0 = _mm_sub_ps( HLML_ONE_SSE, t );

	__m128 mul0 = _mm_mul_ps( sub0, lhs );
	__m128 mul1 = _mm_mul_ps( t, rhs );

	*out_results = _mm_add_ps( mul0, mul1 );
}


#ifdef __cplusplus
}
#endif


#pragma once

#include <xmmintrin.h>

static const __m128 HLML_ZERO_SSE		= _mm_set1_ps( 0.0f );

static const __m128	HLML_RAD_TO_DEG_SSE	= _mm_set1_ps( 57.2957795130823208768f );
static const __m128	HLML_DEG_TO_RAD_SSE	= _mm_set1_ps( 0.01745329251994329577f );

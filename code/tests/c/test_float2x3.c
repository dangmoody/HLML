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

static float2x3 g_matrixMulLHS_float2x3    = {
		6.000000f, 6.000000f, 6.000000f,
		6.000000f, 6.000000f, 6.000000f
};

static float3x2 g_matrixMulRHS_float2x3    = {
		1.000000f, 1.000000f,
		2.000000f, 2.000000f,
		3.000000f, 3.000000f
};

static float2x2 g_matrixMulAnswer_float2x3 = {
		36.000000f, 36.000000f,
		36.000000f, 36.000000f
};


TEMPER_TEST( TestAssignment_float2x3, TEMPER_FLAG_SHOULD_RUN )
{
	float2x3 mat;

	mat.rows[0] = (float3) { 999.000000f, 0.000000f, 0.000000f };
	mat.rows[1] = (float3) { 0.000000f, 999.000000f, 0.000000f };

	TEMPER_CHECK_TRUE( mat.rows[0].x == 999.0f );
	TEMPER_CHECK_TRUE( mat.rows[0].y == 0.0f );
	TEMPER_CHECK_TRUE( mat.rows[0].z == 0.0f );
	TEMPER_CHECK_TRUE( mat.rows[1].x == 0.0f );
	TEMPER_CHECK_TRUE( mat.rows[1].y == 999.0f );
	TEMPER_CHECK_TRUE( mat.rows[1].z == 0.0f );
}

TEMPER_TEST( TestComponentWiseArithmetic_Scalar_Addition_float2x3, TEMPER_FLAG_SHOULD_RUN )
{
	float2x3 answer = (float2x3) {
		7.000000f, 7.000000f, 7.000000f,
		8.000000f, 8.000000f, 8.000000f
	};

	float2x3 a = (float2x3) {
		6.000000f, 6.000000f, 6.000000f,
		6.000000f, 6.000000f, 6.000000f
	};

	float2x3 b = (float2x3) {
		1.000000f, 1.000000f, 1.000000f,
		2.000000f, 2.000000f, 2.000000f
	};

	float2x3 c = float2x3_caddm( &a, &b );

	TEMPER_CHECK_TRUE( float2x3_cmpe( &c, &answer ) );
}

TEMPER_TEST( TestComponentWiseArithmetic_Scalar_Subtraction_float2x3, TEMPER_FLAG_SHOULD_RUN )
{
	float2x3 answer = (float2x3) {
		5.000000f, 5.000000f, 5.000000f,
		4.000000f, 4.000000f, 4.000000f
	};

	float2x3 a = (float2x3) {
		6.000000f, 6.000000f, 6.000000f,
		6.000000f, 6.000000f, 6.000000f
	};

	float2x3 b = (float2x3) {
		1.000000f, 1.000000f, 1.000000f,
		2.000000f, 2.000000f, 2.000000f
	};

	float2x3 c = float2x3_csubm( &a, &b );

	TEMPER_CHECK_TRUE( float2x3_cmpe( &c, &answer ) );
}

TEMPER_TEST( TestComponentWiseArithmetic_Scalar_Multiplication_float2x3, TEMPER_FLAG_SHOULD_RUN )
{
	float2x3 answer = (float2x3) {
		6.000000f, 6.000000f, 6.000000f,
		12.000000f, 12.000000f, 12.000000f
	};

	float2x3 a = (float2x3) {
		6.000000f, 6.000000f, 6.000000f,
		6.000000f, 6.000000f, 6.000000f
	};

	float2x3 b = (float2x3) {
		1.000000f, 1.000000f, 1.000000f,
		2.000000f, 2.000000f, 2.000000f
	};

	float2x3 c = float2x3_cmulm( &a, &b );

	TEMPER_CHECK_TRUE( float2x3_cmpe( &c, &answer ) );
}

TEMPER_TEST( TestComponentWiseArithmetic_Scalar_Division_float2x3, TEMPER_FLAG_SHOULD_RUN )
{
	float2x3 answer = (float2x3) {
		6.000000f, 6.000000f, 6.000000f,
		3.000000f, 3.000000f, 3.000000f
	};

	float2x3 a = (float2x3) {
		6.000000f, 6.000000f, 6.000000f,
		6.000000f, 6.000000f, 6.000000f
	};

	float2x3 b = (float2x3) {
		1.000000f, 1.000000f, 1.000000f,
		2.000000f, 2.000000f, 2.000000f
	};

	float2x3 c = float2x3_cdivm( &a, &b );

	TEMPER_CHECK_TRUE( float2x3_cmpe( &c, &answer ) );
}

TEMPER_TEST( TestComponentWiseArithmetic_SSE_Addition_float2x3, TEMPER_FLAG_SHOULD_RUN )
{
	float a00[4] =	{ 6.000000f, 6.000000f, 6.000000f, 6.000000f };
	float a01[4] =	{ 6.000000f, 6.000000f, 6.000000f, 6.000000f };
	float a02[4] =	{ 6.000000f, 6.000000f, 6.000000f, 6.000000f };
	float a10[4] =	{ 6.000000f, 6.000000f, 6.000000f, 6.000000f };
	float a11[4] =	{ 6.000000f, 6.000000f, 6.000000f, 6.000000f };
	float a12[4] =	{ 6.000000f, 6.000000f, 6.000000f, 6.000000f };

	float b00[4] =	{ 1.000000f, 1.000000f, 1.000000f, 1.000000f };
	float b01[4] =	{ 1.000000f, 1.000000f, 1.000000f, 1.000000f };
	float b02[4] =	{ 1.000000f, 1.000000f, 1.000000f, 1.000000f };
	float b10[4] =	{ 2.000000f, 2.000000f, 2.000000f, 2.000000f };
	float b11[4] =	{ 2.000000f, 2.000000f, 2.000000f, 2.000000f };
	float b12[4] =	{ 2.000000f, 2.000000f, 2.000000f, 2.000000f };

	float2x3_sse_t results;
	float2x3_sse_t lhs;
	float2x3_sse_t rhs;
	lhs.m[0][0] = _mm_load_ps( a00 );
	lhs.m[0][1] = _mm_load_ps( a01 );
	lhs.m[0][2] = _mm_load_ps( a02 );
	lhs.m[1][0] = _mm_load_ps( a10 );
	lhs.m[1][1] = _mm_load_ps( a11 );
	lhs.m[1][2] = _mm_load_ps( a12 );

	rhs.m[0][0] = _mm_load_ps( b00 );
	rhs.m[0][1] = _mm_load_ps( b01 );
	rhs.m[0][2] = _mm_load_ps( b02 );
	rhs.m[1][0] = _mm_load_ps( b10 );
	rhs.m[1][1] = _mm_load_ps( b11 );
	rhs.m[1][2] = _mm_load_ps( b12 );

	float2x3_caddm_sse( &lhs, &rhs, &results );

	float arithmeticResults[4];

	_mm_store_ps( arithmeticResults, results.m[0][0] );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[0], 7.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[1], 7.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[2], 7.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[3], 7.000000f ) );

	_mm_store_ps( arithmeticResults, results.m[0][1] );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[0], 7.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[1], 7.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[2], 7.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[3], 7.000000f ) );

	_mm_store_ps( arithmeticResults, results.m[0][2] );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[0], 7.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[1], 7.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[2], 7.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[3], 7.000000f ) );

	_mm_store_ps( arithmeticResults, results.m[1][0] );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[0], 8.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[1], 8.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[2], 8.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[3], 8.000000f ) );

	_mm_store_ps( arithmeticResults, results.m[1][1] );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[0], 8.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[1], 8.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[2], 8.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[3], 8.000000f ) );

	_mm_store_ps( arithmeticResults, results.m[1][2] );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[0], 8.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[1], 8.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[2], 8.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[3], 8.000000f ) );

}

TEMPER_TEST( TestComponentWiseArithmetic_SSE_Subtraction_float2x3, TEMPER_FLAG_SHOULD_RUN )
{
	float a00[4] =	{ 6.000000f, 6.000000f, 6.000000f, 6.000000f };
	float a01[4] =	{ 6.000000f, 6.000000f, 6.000000f, 6.000000f };
	float a02[4] =	{ 6.000000f, 6.000000f, 6.000000f, 6.000000f };
	float a10[4] =	{ 6.000000f, 6.000000f, 6.000000f, 6.000000f };
	float a11[4] =	{ 6.000000f, 6.000000f, 6.000000f, 6.000000f };
	float a12[4] =	{ 6.000000f, 6.000000f, 6.000000f, 6.000000f };

	float b00[4] =	{ 1.000000f, 1.000000f, 1.000000f, 1.000000f };
	float b01[4] =	{ 1.000000f, 1.000000f, 1.000000f, 1.000000f };
	float b02[4] =	{ 1.000000f, 1.000000f, 1.000000f, 1.000000f };
	float b10[4] =	{ 2.000000f, 2.000000f, 2.000000f, 2.000000f };
	float b11[4] =	{ 2.000000f, 2.000000f, 2.000000f, 2.000000f };
	float b12[4] =	{ 2.000000f, 2.000000f, 2.000000f, 2.000000f };

	float2x3_sse_t results;
	float2x3_sse_t lhs;
	float2x3_sse_t rhs;
	lhs.m[0][0] = _mm_load_ps( a00 );
	lhs.m[0][1] = _mm_load_ps( a01 );
	lhs.m[0][2] = _mm_load_ps( a02 );
	lhs.m[1][0] = _mm_load_ps( a10 );
	lhs.m[1][1] = _mm_load_ps( a11 );
	lhs.m[1][2] = _mm_load_ps( a12 );

	rhs.m[0][0] = _mm_load_ps( b00 );
	rhs.m[0][1] = _mm_load_ps( b01 );
	rhs.m[0][2] = _mm_load_ps( b02 );
	rhs.m[1][0] = _mm_load_ps( b10 );
	rhs.m[1][1] = _mm_load_ps( b11 );
	rhs.m[1][2] = _mm_load_ps( b12 );

	float2x3_csubm_sse( &lhs, &rhs, &results );

	float arithmeticResults[4];

	_mm_store_ps( arithmeticResults, results.m[0][0] );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[0], 5.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[1], 5.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[2], 5.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[3], 5.000000f ) );

	_mm_store_ps( arithmeticResults, results.m[0][1] );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[0], 5.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[1], 5.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[2], 5.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[3], 5.000000f ) );

	_mm_store_ps( arithmeticResults, results.m[0][2] );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[0], 5.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[1], 5.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[2], 5.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[3], 5.000000f ) );

	_mm_store_ps( arithmeticResults, results.m[1][0] );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[0], 4.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[1], 4.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[2], 4.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[3], 4.000000f ) );

	_mm_store_ps( arithmeticResults, results.m[1][1] );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[0], 4.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[1], 4.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[2], 4.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[3], 4.000000f ) );

	_mm_store_ps( arithmeticResults, results.m[1][2] );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[0], 4.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[1], 4.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[2], 4.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[3], 4.000000f ) );

}

TEMPER_TEST( TestComponentWiseArithmetic_SSE_Multiplication_float2x3, TEMPER_FLAG_SHOULD_RUN )
{
	float a00[4] =	{ 6.000000f, 6.000000f, 6.000000f, 6.000000f };
	float a01[4] =	{ 6.000000f, 6.000000f, 6.000000f, 6.000000f };
	float a02[4] =	{ 6.000000f, 6.000000f, 6.000000f, 6.000000f };
	float a10[4] =	{ 6.000000f, 6.000000f, 6.000000f, 6.000000f };
	float a11[4] =	{ 6.000000f, 6.000000f, 6.000000f, 6.000000f };
	float a12[4] =	{ 6.000000f, 6.000000f, 6.000000f, 6.000000f };

	float b00[4] =	{ 1.000000f, 1.000000f, 1.000000f, 1.000000f };
	float b01[4] =	{ 1.000000f, 1.000000f, 1.000000f, 1.000000f };
	float b02[4] =	{ 1.000000f, 1.000000f, 1.000000f, 1.000000f };
	float b10[4] =	{ 2.000000f, 2.000000f, 2.000000f, 2.000000f };
	float b11[4] =	{ 2.000000f, 2.000000f, 2.000000f, 2.000000f };
	float b12[4] =	{ 2.000000f, 2.000000f, 2.000000f, 2.000000f };

	float2x3_sse_t results;
	float2x3_sse_t lhs;
	float2x3_sse_t rhs;
	lhs.m[0][0] = _mm_load_ps( a00 );
	lhs.m[0][1] = _mm_load_ps( a01 );
	lhs.m[0][2] = _mm_load_ps( a02 );
	lhs.m[1][0] = _mm_load_ps( a10 );
	lhs.m[1][1] = _mm_load_ps( a11 );
	lhs.m[1][2] = _mm_load_ps( a12 );

	rhs.m[0][0] = _mm_load_ps( b00 );
	rhs.m[0][1] = _mm_load_ps( b01 );
	rhs.m[0][2] = _mm_load_ps( b02 );
	rhs.m[1][0] = _mm_load_ps( b10 );
	rhs.m[1][1] = _mm_load_ps( b11 );
	rhs.m[1][2] = _mm_load_ps( b12 );

	float2x3_cmulm_sse( &lhs, &rhs, &results );

	float arithmeticResults[4];

	_mm_store_ps( arithmeticResults, results.m[0][0] );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[0], 6.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[1], 6.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[2], 6.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[3], 6.000000f ) );

	_mm_store_ps( arithmeticResults, results.m[0][1] );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[0], 6.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[1], 6.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[2], 6.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[3], 6.000000f ) );

	_mm_store_ps( arithmeticResults, results.m[0][2] );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[0], 6.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[1], 6.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[2], 6.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[3], 6.000000f ) );

	_mm_store_ps( arithmeticResults, results.m[1][0] );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[0], 12.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[1], 12.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[2], 12.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[3], 12.000000f ) );

	_mm_store_ps( arithmeticResults, results.m[1][1] );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[0], 12.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[1], 12.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[2], 12.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[3], 12.000000f ) );

	_mm_store_ps( arithmeticResults, results.m[1][2] );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[0], 12.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[1], 12.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[2], 12.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[3], 12.000000f ) );

}

TEMPER_TEST( TestComponentWiseArithmetic_SSE_Division_float2x3, TEMPER_FLAG_SHOULD_RUN )
{
	float a00[4] =	{ 6.000000f, 6.000000f, 6.000000f, 6.000000f };
	float a01[4] =	{ 6.000000f, 6.000000f, 6.000000f, 6.000000f };
	float a02[4] =	{ 6.000000f, 6.000000f, 6.000000f, 6.000000f };
	float a10[4] =	{ 6.000000f, 6.000000f, 6.000000f, 6.000000f };
	float a11[4] =	{ 6.000000f, 6.000000f, 6.000000f, 6.000000f };
	float a12[4] =	{ 6.000000f, 6.000000f, 6.000000f, 6.000000f };

	float b00[4] =	{ 1.000000f, 1.000000f, 1.000000f, 1.000000f };
	float b01[4] =	{ 1.000000f, 1.000000f, 1.000000f, 1.000000f };
	float b02[4] =	{ 1.000000f, 1.000000f, 1.000000f, 1.000000f };
	float b10[4] =	{ 2.000000f, 2.000000f, 2.000000f, 2.000000f };
	float b11[4] =	{ 2.000000f, 2.000000f, 2.000000f, 2.000000f };
	float b12[4] =	{ 2.000000f, 2.000000f, 2.000000f, 2.000000f };

	float2x3_sse_t results;
	float2x3_sse_t lhs;
	float2x3_sse_t rhs;
	lhs.m[0][0] = _mm_load_ps( a00 );
	lhs.m[0][1] = _mm_load_ps( a01 );
	lhs.m[0][2] = _mm_load_ps( a02 );
	lhs.m[1][0] = _mm_load_ps( a10 );
	lhs.m[1][1] = _mm_load_ps( a11 );
	lhs.m[1][2] = _mm_load_ps( a12 );

	rhs.m[0][0] = _mm_load_ps( b00 );
	rhs.m[0][1] = _mm_load_ps( b01 );
	rhs.m[0][2] = _mm_load_ps( b02 );
	rhs.m[1][0] = _mm_load_ps( b10 );
	rhs.m[1][1] = _mm_load_ps( b11 );
	rhs.m[1][2] = _mm_load_ps( b12 );

	float2x3_cdivm_sse( &lhs, &rhs, &results );

	float arithmeticResults[4];

	_mm_store_ps( arithmeticResults, results.m[0][0] );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[0], 6.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[1], 6.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[2], 6.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[3], 6.000000f ) );

	_mm_store_ps( arithmeticResults, results.m[0][1] );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[0], 6.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[1], 6.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[2], 6.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[3], 6.000000f ) );

	_mm_store_ps( arithmeticResults, results.m[0][2] );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[0], 6.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[1], 6.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[2], 6.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[3], 6.000000f ) );

	_mm_store_ps( arithmeticResults, results.m[1][0] );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[0], 3.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[1], 3.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[2], 3.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[3], 3.000000f ) );

	_mm_store_ps( arithmeticResults, results.m[1][1] );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[0], 3.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[1], 3.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[2], 3.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[3], 3.000000f ) );

	_mm_store_ps( arithmeticResults, results.m[1][2] );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[0], 3.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[1], 3.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[2], 3.000000f ) );
	TEMPER_CHECK_TRUE( floateq( arithmeticResults[3], 3.000000f ) );

}

TEMPER_TEST( TestMultiplyMatrix_Scalar_float2x3, TEMPER_FLAG_SHOULD_RUN )
{
	float2x2 answer = g_matrixMulAnswer_float2x3;

	float2x3 a = g_matrixMulLHS_float2x3;
	float3x2 b = g_matrixMulRHS_float2x3;
	float2x2 c = float2x3_mulm( &a, &b );

	TEMPER_CHECK_TRUE( float2x2_cmpe( &c, &answer ) );
}

TEMPER_TEST( TestMultiplyMatrix_SSE_float2x3, TEMPER_FLAG_SHOULD_RUN )
{
	float a00[4] =	{ 6.000000f, 6.000000f, 6.000000f, 6.000000f };
	float a01[4] =	{ 6.000000f, 6.000000f, 6.000000f, 6.000000f };
	float a02[4] =	{ 6.000000f, 6.000000f, 6.000000f, 6.000000f };
	float a10[4] =	{ 6.000000f, 6.000000f, 6.000000f, 6.000000f };
	float a11[4] =	{ 6.000000f, 6.000000f, 6.000000f, 6.000000f };
	float a12[4] =	{ 6.000000f, 6.000000f, 6.000000f, 6.000000f };

	float b00[4] =	{ 1.000000f, 1.000000f, 1.000000f, 1.000000f };
	float b01[4] =	{ 1.000000f, 1.000000f, 1.000000f, 1.000000f };
	float b10[4] =	{ 2.000000f, 2.000000f, 2.000000f, 2.000000f };
	float b11[4] =	{ 2.000000f, 2.000000f, 2.000000f, 2.000000f };
	float b20[4] =	{ 3.000000f, 3.000000f, 3.000000f, 3.000000f };
	float b21[4] =	{ 3.000000f, 3.000000f, 3.000000f, 3.000000f };

	float2x2_sse_t results;
	float2x3_sse_t lhs;
	float3x2_sse_t rhs;
	lhs.m[0][0] = _mm_load_ps( a00 );
	lhs.m[0][1] = _mm_load_ps( a01 );
	lhs.m[0][2] = _mm_load_ps( a02 );
	lhs.m[1][0] = _mm_load_ps( a10 );
	lhs.m[1][1] = _mm_load_ps( a11 );
	lhs.m[1][2] = _mm_load_ps( a12 );

	rhs.m[0][0] = _mm_load_ps( b00 );
	rhs.m[0][1] = _mm_load_ps( b01 );
	rhs.m[1][0] = _mm_load_ps( b10 );
	rhs.m[1][1] = _mm_load_ps( b11 );
	rhs.m[2][0] = _mm_load_ps( b20 );
	rhs.m[2][1] = _mm_load_ps( b21 );

	float2x3_mulm_sse( &lhs, &rhs, &results );

	float mulResults[4];

	_mm_store_ps( mulResults, results.m[0][0] );
	TEMPER_CHECK_TRUE( floateq( mulResults[0], g_matrixMulAnswer_float2x3.rows[0].x ) );
	TEMPER_CHECK_TRUE( floateq( mulResults[1], g_matrixMulAnswer_float2x3.rows[0].x ) );
	TEMPER_CHECK_TRUE( floateq( mulResults[2], g_matrixMulAnswer_float2x3.rows[0].x ) );
	TEMPER_CHECK_TRUE( floateq( mulResults[3], g_matrixMulAnswer_float2x3.rows[0].x ) );

	_mm_store_ps( mulResults, results.m[0][1] );
	TEMPER_CHECK_TRUE( floateq( mulResults[0], g_matrixMulAnswer_float2x3.rows[0].y ) );
	TEMPER_CHECK_TRUE( floateq( mulResults[1], g_matrixMulAnswer_float2x3.rows[0].y ) );
	TEMPER_CHECK_TRUE( floateq( mulResults[2], g_matrixMulAnswer_float2x3.rows[0].y ) );
	TEMPER_CHECK_TRUE( floateq( mulResults[3], g_matrixMulAnswer_float2x3.rows[0].y ) );

	_mm_store_ps( mulResults, results.m[1][0] );
	TEMPER_CHECK_TRUE( floateq( mulResults[0], g_matrixMulAnswer_float2x3.rows[1].x ) );
	TEMPER_CHECK_TRUE( floateq( mulResults[1], g_matrixMulAnswer_float2x3.rows[1].x ) );
	TEMPER_CHECK_TRUE( floateq( mulResults[2], g_matrixMulAnswer_float2x3.rows[1].x ) );
	TEMPER_CHECK_TRUE( floateq( mulResults[3], g_matrixMulAnswer_float2x3.rows[1].x ) );

	_mm_store_ps( mulResults, results.m[1][1] );
	TEMPER_CHECK_TRUE( floateq( mulResults[0], g_matrixMulAnswer_float2x3.rows[1].y ) );
	TEMPER_CHECK_TRUE( floateq( mulResults[1], g_matrixMulAnswer_float2x3.rows[1].y ) );
	TEMPER_CHECK_TRUE( floateq( mulResults[2], g_matrixMulAnswer_float2x3.rows[1].y ) );
	TEMPER_CHECK_TRUE( floateq( mulResults[3], g_matrixMulAnswer_float2x3.rows[1].y ) );

}

TEMPER_TEST( TestRelational_float2x3, TEMPER_FLAG_SHOULD_RUN )
{
	float2x3 mat0 =
	{
		1.000000f, 1.000000f, 1.000000f,
		1.000000f, 1.000000f, 1.000000f
	};

	float2x3 mat1 =
	{
		2.000000f, 2.000000f, 2.000000f,
		2.000000f, 2.000000f, 2.000000f
	};

	float2x3 mat2 =
	{
		3.000000f, 3.000000f, 3.000000f,
		3.000000f, 3.000000f, 3.000000f
	};

	float2x3 mat3 =
	{
		4.000000f, 4.000000f, 4.000000f,
		4.000000f, 4.000000f, 4.000000f
	};

	bool2x3 test0  = float2x3_cmple( &mat0, &mat0 );
	bool2x3 test1  = float2x3_cmpge( &mat0, &mat0 );
	bool2x3 test2  = float2x3_cmpl( &mat0, &mat1 );
	bool2x3 test3  = float2x3_cmpl( &mat0, &mat2 );
	bool2x3 test4  = float2x3_cmpl( &mat0, &mat3 );

	bool2x3 test5  = float2x3_cmpg( &mat1, &mat0 );
	bool2x3 test6  = float2x3_cmple( &mat1, &mat1 );
	bool2x3 test7  = float2x3_cmpge( &mat1, &mat1 );
	bool2x3 test8  = float2x3_cmpl( &mat1, &mat2 );
	bool2x3 test9  = float2x3_cmpl( &mat1, &mat3 );

	bool2x3 test10 = float2x3_cmpg( &mat2, &mat0 );
	bool2x3 test11 = float2x3_cmpg( &mat2, &mat1 );
	bool2x3 test12 = float2x3_cmple( &mat2, &mat2 );
	bool2x3 test13 = float2x3_cmpge( &mat2, &mat2 );
	bool2x3 test14 = float2x3_cmpl( &mat2, &mat3 );

	bool2x3 test15 = float2x3_cmpg( &mat3, &mat0 );
	bool2x3 test16 = float2x3_cmpg( &mat3, &mat1 );
	bool2x3 test17 = float2x3_cmpg( &mat3, &mat2 );
	bool2x3 test18 = float2x3_cmple( &mat3, &mat3 );
	bool2x3 test19 = float2x3_cmpge( &mat3, &mat3 );

	TEMPER_CHECK_TRUE( bool2x3_all( &test0 ) );
	TEMPER_CHECK_TRUE( bool2x3_all( &test1 ) );
	TEMPER_CHECK_TRUE( bool2x3_all( &test2 ) );
	TEMPER_CHECK_TRUE( bool2x3_all( &test3 ) );
	TEMPER_CHECK_TRUE( bool2x3_all( &test4 ) );

	TEMPER_CHECK_TRUE( bool2x3_all( &test5 ) );
	TEMPER_CHECK_TRUE( bool2x3_all( &test6 ) );
	TEMPER_CHECK_TRUE( bool2x3_all( &test7 ) );
	TEMPER_CHECK_TRUE( bool2x3_all( &test8 ) );
	TEMPER_CHECK_TRUE( bool2x3_all( &test9 ) );

	TEMPER_CHECK_TRUE( bool2x3_all( &test10 ) );
	TEMPER_CHECK_TRUE( bool2x3_all( &test11 ) );
	TEMPER_CHECK_TRUE( bool2x3_all( &test12 ) );
	TEMPER_CHECK_TRUE( bool2x3_all( &test13 ) );
	TEMPER_CHECK_TRUE( bool2x3_all( &test14 ) );

	TEMPER_CHECK_TRUE( bool2x3_all( &test15 ) );
	TEMPER_CHECK_TRUE( bool2x3_all( &test16 ) );
	TEMPER_CHECK_TRUE( bool2x3_all( &test17 ) );
	TEMPER_CHECK_TRUE( bool2x3_all( &test18 ) );
	TEMPER_CHECK_TRUE( bool2x3_all( &test19 ) );
}

TEMPER_PARAMETRIC( TestNegate_float2x3, TEMPER_FLAG_SHOULD_RUN, const float2x3* vec )
{
	float2x3 negated = float2x3_negate( vec );
	TEMPER_CHECK_TRUE( floateq( negated.rows[0].x, -vec->rows[0].x ) );
	TEMPER_CHECK_TRUE( floateq( negated.rows[0].y, -vec->rows[0].y ) );
	TEMPER_CHECK_TRUE( floateq( negated.rows[0].z, -vec->rows[0].z ) );
	TEMPER_CHECK_TRUE( floateq( negated.rows[1].x, -vec->rows[1].x ) );
	TEMPER_CHECK_TRUE( floateq( negated.rows[1].y, -vec->rows[1].y ) );
	TEMPER_CHECK_TRUE( floateq( negated.rows[1].z, -vec->rows[1].z ) );
}

const float2x3 g_testNegate_zero_float2x3 =
{
		0.000000f, 0.000000f, 0.000000f,
		0.000000f, 0.000000f, 0.000000f
};
TEMPER_INVOKE_PARAMETRIC_TEST( TestNegate_float2x3, &g_testNegate_zero_float2x3 );

const float2x3 g_testNegate_one_float2x3 =
{
		1.000000f, 1.000000f, 1.000000f,
		1.000000f, 1.000000f, 1.000000f
};
TEMPER_INVOKE_PARAMETRIC_TEST( TestNegate_float2x3, &g_testNegate_one_float2x3 );

const float2x3 g_testNegate_minusTwo_float2x3 =
{
		-2.000000f, -2.000000f, -2.000000f,
		-2.000000f, -2.000000f, -2.000000f
};
TEMPER_INVOKE_PARAMETRIC_TEST( TestNegate_float2x3, &g_testNegate_minusTwo_float2x3 );

const float2x3 g_testNegate_alternatingValues_float2x3 =
{
		0.000000f, -0.000000f, 1.000000f,
		-5.000000f, 6.000000f, -7.000000f
};
TEMPER_INVOKE_PARAMETRIC_TEST( TestNegate_float2x3, &g_testNegate_alternatingValues_float2x3 );

TEMPER_TEST( TestIdentity_Scalar_float2x3, TEMPER_FLAG_SHOULD_RUN )
{
	float2x3 id;
	id.rows[0] = (float3) { 1.000000f, 0.000000f, 0.000000f };
	id.rows[1] = (float3) { 0.000000f, 1.000000f, 0.000000f };

	float2x3 mat;
	float2x3_identity( &mat );
	TEMPER_CHECK_TRUE( float2x3_cmpe( &mat, &id ) );
}

TEMPER_TEST( TestIdentity_SSE_float2x3, TEMPER_FLAG_SHOULD_RUN )
{
	float2x3_sse_t matSSE;
	float2x3_identity_sse( &matSSE );

	float identityResults[4];
	_mm_store_ps( identityResults, matSSE.m[0][0] );
	TEMPER_CHECK_TRUE( identityResults[0] == 1.0f );
	TEMPER_CHECK_TRUE( identityResults[1] == 1.0f );
	TEMPER_CHECK_TRUE( identityResults[2] == 1.0f );
	TEMPER_CHECK_TRUE( identityResults[3] == 1.0f );

	_mm_store_ps( identityResults, matSSE.m[0][1] );
	TEMPER_CHECK_TRUE( identityResults[0] == 0.0f );
	TEMPER_CHECK_TRUE( identityResults[1] == 0.0f );
	TEMPER_CHECK_TRUE( identityResults[2] == 0.0f );
	TEMPER_CHECK_TRUE( identityResults[3] == 0.0f );

	_mm_store_ps( identityResults, matSSE.m[0][2] );
	TEMPER_CHECK_TRUE( identityResults[0] == 0.0f );
	TEMPER_CHECK_TRUE( identityResults[1] == 0.0f );
	TEMPER_CHECK_TRUE( identityResults[2] == 0.0f );
	TEMPER_CHECK_TRUE( identityResults[3] == 0.0f );

	_mm_store_ps( identityResults, matSSE.m[1][0] );
	TEMPER_CHECK_TRUE( identityResults[0] == 0.0f );
	TEMPER_CHECK_TRUE( identityResults[1] == 0.0f );
	TEMPER_CHECK_TRUE( identityResults[2] == 0.0f );
	TEMPER_CHECK_TRUE( identityResults[3] == 0.0f );

	_mm_store_ps( identityResults, matSSE.m[1][1] );
	TEMPER_CHECK_TRUE( identityResults[0] == 1.0f );
	TEMPER_CHECK_TRUE( identityResults[1] == 1.0f );
	TEMPER_CHECK_TRUE( identityResults[2] == 1.0f );
	TEMPER_CHECK_TRUE( identityResults[3] == 1.0f );

	_mm_store_ps( identityResults, matSSE.m[1][2] );
	TEMPER_CHECK_TRUE( identityResults[0] == 0.0f );
	TEMPER_CHECK_TRUE( identityResults[1] == 0.0f );
	TEMPER_CHECK_TRUE( identityResults[2] == 0.0f );
	TEMPER_CHECK_TRUE( identityResults[3] == 0.0f );

}

TEMPER_TEST( TestTranspose_Scalar_float2x3, TEMPER_FLAG_SHOULD_RUN )
{
	float3x2 answerTransposed = (float3x2) {
		0.000000f, 4.000000f,
		1.000000f, 5.000000f,
		2.000000f, 6.000000f
	};

	float2x3 mat = (float2x3) {
		0.000000f, 1.000000f, 2.000000f,
		4.000000f, 5.000000f, 6.000000f
	};
	float3x2 trans = float2x3_transpose( &mat );

	TEMPER_CHECK_TRUE( float3x2_cmpe( &trans, &answerTransposed ) );
}

TEMPER_TEST( TestTranspose_SSE_float2x3, TEMPER_FLAG_SHOULD_RUN )
{
	float3x2_sse_t results;
	float2x3_sse_t in;

	// row 0
	in.m[0][0] = _mm_set1_ps( 0.0f );
	in.m[0][1] = _mm_set1_ps( 1.0f );
	in.m[0][2] = _mm_set1_ps( 2.0f );

	// row 1
	in.m[1][0] = _mm_set1_ps( 4.0f );
	in.m[1][1] = _mm_set1_ps( 5.0f );
	in.m[1][2] = _mm_set1_ps( 6.0f );

	float2x3_transpose_sse( &in, &results );

	float transposeResults[4];
	_mm_store_ps( transposeResults, results.m[0][0] );
	TEMPER_CHECK_TRUE( floateq( transposeResults[0], 0.000000f ) );
	TEMPER_CHECK_TRUE( floateq( transposeResults[1], 0.000000f ) );
	TEMPER_CHECK_TRUE( floateq( transposeResults[2], 0.000000f ) );
	TEMPER_CHECK_TRUE( floateq( transposeResults[3], 0.000000f ) );

	_mm_store_ps( transposeResults, results.m[0][1] );
	TEMPER_CHECK_TRUE( floateq( transposeResults[0], 4.000000f ) );
	TEMPER_CHECK_TRUE( floateq( transposeResults[1], 4.000000f ) );
	TEMPER_CHECK_TRUE( floateq( transposeResults[2], 4.000000f ) );
	TEMPER_CHECK_TRUE( floateq( transposeResults[3], 4.000000f ) );

	_mm_store_ps( transposeResults, results.m[1][0] );
	TEMPER_CHECK_TRUE( floateq( transposeResults[0], 1.000000f ) );
	TEMPER_CHECK_TRUE( floateq( transposeResults[1], 1.000000f ) );
	TEMPER_CHECK_TRUE( floateq( transposeResults[2], 1.000000f ) );
	TEMPER_CHECK_TRUE( floateq( transposeResults[3], 1.000000f ) );

	_mm_store_ps( transposeResults, results.m[1][1] );
	TEMPER_CHECK_TRUE( floateq( transposeResults[0], 5.000000f ) );
	TEMPER_CHECK_TRUE( floateq( transposeResults[1], 5.000000f ) );
	TEMPER_CHECK_TRUE( floateq( transposeResults[2], 5.000000f ) );
	TEMPER_CHECK_TRUE( floateq( transposeResults[3], 5.000000f ) );

	_mm_store_ps( transposeResults, results.m[2][0] );
	TEMPER_CHECK_TRUE( floateq( transposeResults[0], 2.000000f ) );
	TEMPER_CHECK_TRUE( floateq( transposeResults[1], 2.000000f ) );
	TEMPER_CHECK_TRUE( floateq( transposeResults[2], 2.000000f ) );
	TEMPER_CHECK_TRUE( floateq( transposeResults[3], 2.000000f ) );

	_mm_store_ps( transposeResults, results.m[2][1] );
	TEMPER_CHECK_TRUE( floateq( transposeResults[0], 6.000000f ) );
	TEMPER_CHECK_TRUE( floateq( transposeResults[1], 6.000000f ) );
	TEMPER_CHECK_TRUE( floateq( transposeResults[2], 6.000000f ) );
	TEMPER_CHECK_TRUE( floateq( transposeResults[3], 6.000000f ) );

}

TEMPER_TEST( TestScale_Scalar_float2x3, TEMPER_FLAG_SHOULD_RUN )
{
	float2 scaleVec = { 2.000000f, 2.000000f };
	float2x3 mat;
	float2x3_identity( &mat );

	float2x3 scaled = float2x3_scale( &mat, &scaleVec );

	TEMPER_CHECK_TRUE( floateq( scaled.rows[0].x, 2.000000f ) );
	TEMPER_CHECK_TRUE( floateq( scaled.rows[1].y, 2.000000f ) );
}


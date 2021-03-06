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

static uint4x2 g_matrixMulLHS_uint4x2    = {
		6U, 6U,
		6U, 6U,
		12U, 12U,
		18U, 18U
};

static uint2x4 g_matrixMulRHS_uint4x2    = {
		1U, 1U, 1U, 1U,
		2U, 2U, 2U, 2U
};

static uint4x4 g_matrixMulAnswer_uint4x2 = {
		18U, 18U, 18U, 18U,
		18U, 18U, 18U, 18U,
		36U, 36U, 36U, 36U,
		54U, 54U, 54U, 54U
};


TEMPER_TEST( TestAssignment_uint4x2, TEMPER_FLAG_SHOULD_RUN )
{
	uint4x2 mat;

	mat.rows[0] = (uint2) { 999U, 0U };
	mat.rows[1] = (uint2) { 0U, 999U };
	mat.rows[2] = (uint2) { 0U, 0U };
	mat.rows[3] = (uint2) { 0U, 0U };

	TEMPER_CHECK_TRUE( mat.rows[0].x == 999U );
	TEMPER_CHECK_TRUE( mat.rows[0].y == 0U );
	TEMPER_CHECK_TRUE( mat.rows[1].x == 0U );
	TEMPER_CHECK_TRUE( mat.rows[1].y == 999U );
	TEMPER_CHECK_TRUE( mat.rows[2].x == 0U );
	TEMPER_CHECK_TRUE( mat.rows[2].y == 0U );
	TEMPER_CHECK_TRUE( mat.rows[3].x == 0U );
	TEMPER_CHECK_TRUE( mat.rows[3].y == 0U );
}

TEMPER_TEST( TestComponentWiseArithmetic_Scalar_Addition_uint4x2, TEMPER_FLAG_SHOULD_RUN )
{
	uint4x2 answer = (uint4x2) {
		7U, 7U,
		8U, 8U,
		15U, 15U,
		24U, 24U
	};

	uint4x2 a = (uint4x2) {
		6U, 6U,
		6U, 6U,
		12U, 12U,
		18U, 18U
	};

	uint4x2 b = (uint4x2) {
		1U, 1U,
		2U, 2U,
		3U, 3U,
		6U, 6U
	};

	uint4x2 c = uint4x2_caddm( &a, &b );

	TEMPER_CHECK_TRUE( uint4x2_cmpe( &c, &answer ) );
}

TEMPER_TEST( TestComponentWiseArithmetic_Scalar_Subtraction_uint4x2, TEMPER_FLAG_SHOULD_RUN )
{
	uint4x2 answer = (uint4x2) {
		5U, 5U,
		4U, 4U,
		9U, 9U,
		12U, 12U
	};

	uint4x2 a = (uint4x2) {
		6U, 6U,
		6U, 6U,
		12U, 12U,
		18U, 18U
	};

	uint4x2 b = (uint4x2) {
		1U, 1U,
		2U, 2U,
		3U, 3U,
		6U, 6U
	};

	uint4x2 c = uint4x2_csubm( &a, &b );

	TEMPER_CHECK_TRUE( uint4x2_cmpe( &c, &answer ) );
}

TEMPER_TEST( TestComponentWiseArithmetic_Scalar_Multiplication_uint4x2, TEMPER_FLAG_SHOULD_RUN )
{
	uint4x2 answer = (uint4x2) {
		6U, 6U,
		12U, 12U,
		36U, 36U,
		108U, 108U
	};

	uint4x2 a = (uint4x2) {
		6U, 6U,
		6U, 6U,
		12U, 12U,
		18U, 18U
	};

	uint4x2 b = (uint4x2) {
		1U, 1U,
		2U, 2U,
		3U, 3U,
		6U, 6U
	};

	uint4x2 c = uint4x2_cmulm( &a, &b );

	TEMPER_CHECK_TRUE( uint4x2_cmpe( &c, &answer ) );
}

TEMPER_TEST( TestComponentWiseArithmetic_Scalar_Division_uint4x2, TEMPER_FLAG_SHOULD_RUN )
{
	uint4x2 answer = (uint4x2) {
		6U, 6U,
		3U, 3U,
		4U, 4U,
		3U, 3U
	};

	uint4x2 a = (uint4x2) {
		6U, 6U,
		6U, 6U,
		12U, 12U,
		18U, 18U
	};

	uint4x2 b = (uint4x2) {
		1U, 1U,
		2U, 2U,
		3U, 3U,
		6U, 6U
	};

	uint4x2 c = uint4x2_cdivm( &a, &b );

	TEMPER_CHECK_TRUE( uint4x2_cmpe( &c, &answer ) );
}

TEMPER_TEST( TestMultiplyMatrix_Scalar_uint4x2, TEMPER_FLAG_SHOULD_RUN )
{
	uint4x4 answer = g_matrixMulAnswer_uint4x2;

	uint4x2 a = g_matrixMulLHS_uint4x2;
	uint2x4 b = g_matrixMulRHS_uint4x2;
	uint4x4 c = uint4x2_mulm( &a, &b );

	TEMPER_CHECK_TRUE( uint4x4_cmpe( &c, &answer ) );
}

TEMPER_TEST( TestRelational_uint4x2, TEMPER_FLAG_SHOULD_RUN )
{
	uint4x2 mat0 =
	{
		1U, 1U,
		1U, 1U,
		1U, 1U,
		1U, 1U
	};

	uint4x2 mat1 =
	{
		2U, 2U,
		2U, 2U,
		2U, 2U,
		2U, 2U
	};

	uint4x2 mat2 =
	{
		3U, 3U,
		3U, 3U,
		3U, 3U,
		3U, 3U
	};

	uint4x2 mat3 =
	{
		4U, 4U,
		4U, 4U,
		4U, 4U,
		4U, 4U
	};

	bool4x2 test0  = uint4x2_cmple( &mat0, &mat0 );
	bool4x2 test1  = uint4x2_cmpge( &mat0, &mat0 );
	bool4x2 test2  = uint4x2_cmpl( &mat0, &mat1 );
	bool4x2 test3  = uint4x2_cmpl( &mat0, &mat2 );
	bool4x2 test4  = uint4x2_cmpl( &mat0, &mat3 );

	bool4x2 test5  = uint4x2_cmpg( &mat1, &mat0 );
	bool4x2 test6  = uint4x2_cmple( &mat1, &mat1 );
	bool4x2 test7  = uint4x2_cmpge( &mat1, &mat1 );
	bool4x2 test8  = uint4x2_cmpl( &mat1, &mat2 );
	bool4x2 test9  = uint4x2_cmpl( &mat1, &mat3 );

	bool4x2 test10 = uint4x2_cmpg( &mat2, &mat0 );
	bool4x2 test11 = uint4x2_cmpg( &mat2, &mat1 );
	bool4x2 test12 = uint4x2_cmple( &mat2, &mat2 );
	bool4x2 test13 = uint4x2_cmpge( &mat2, &mat2 );
	bool4x2 test14 = uint4x2_cmpl( &mat2, &mat3 );

	bool4x2 test15 = uint4x2_cmpg( &mat3, &mat0 );
	bool4x2 test16 = uint4x2_cmpg( &mat3, &mat1 );
	bool4x2 test17 = uint4x2_cmpg( &mat3, &mat2 );
	bool4x2 test18 = uint4x2_cmple( &mat3, &mat3 );
	bool4x2 test19 = uint4x2_cmpge( &mat3, &mat3 );

	TEMPER_CHECK_TRUE( bool4x2_all( &test0 ) );
	TEMPER_CHECK_TRUE( bool4x2_all( &test1 ) );
	TEMPER_CHECK_TRUE( bool4x2_all( &test2 ) );
	TEMPER_CHECK_TRUE( bool4x2_all( &test3 ) );
	TEMPER_CHECK_TRUE( bool4x2_all( &test4 ) );

	TEMPER_CHECK_TRUE( bool4x2_all( &test5 ) );
	TEMPER_CHECK_TRUE( bool4x2_all( &test6 ) );
	TEMPER_CHECK_TRUE( bool4x2_all( &test7 ) );
	TEMPER_CHECK_TRUE( bool4x2_all( &test8 ) );
	TEMPER_CHECK_TRUE( bool4x2_all( &test9 ) );

	TEMPER_CHECK_TRUE( bool4x2_all( &test10 ) );
	TEMPER_CHECK_TRUE( bool4x2_all( &test11 ) );
	TEMPER_CHECK_TRUE( bool4x2_all( &test12 ) );
	TEMPER_CHECK_TRUE( bool4x2_all( &test13 ) );
	TEMPER_CHECK_TRUE( bool4x2_all( &test14 ) );

	TEMPER_CHECK_TRUE( bool4x2_all( &test15 ) );
	TEMPER_CHECK_TRUE( bool4x2_all( &test16 ) );
	TEMPER_CHECK_TRUE( bool4x2_all( &test17 ) );
	TEMPER_CHECK_TRUE( bool4x2_all( &test18 ) );
	TEMPER_CHECK_TRUE( bool4x2_all( &test19 ) );
}

TEMPER_TEST( TestBitwise_And_uint4x2, TEMPER_FLAG_SHOULD_RUN )
{
	uint4x2 answer  = (uint4x2) {
		5U, 5U,
		5U, 5U,
		5U, 5U,
		5U, 5U
	};
	uint4x2 a = (uint4x2) {
		21U, 21U,
		21U, 21U,
		21U, 21U,
		21U, 21U
	};
	uint4x2 b = (uint4x2) {
		7U, 7U,
		7U, 7U,
		7U, 7U,
		7U, 7U
	};
	uint4x2 c = uint4x2_cand( &a, &b );

	TEMPER_CHECK_TRUE( uint4x2_cmpe( &c, &answer ) );
}

TEMPER_TEST( TestBitwise_Or_uint4x2, TEMPER_FLAG_SHOULD_RUN )
{
	uint4x2 answer  = (uint4x2) {
		23U, 23U,
		23U, 23U,
		23U, 23U,
		23U, 23U
	};
	uint4x2 a = (uint4x2) {
		21U, 21U,
		21U, 21U,
		21U, 21U,
		21U, 21U
	};
	uint4x2 b = (uint4x2) {
		7U, 7U,
		7U, 7U,
		7U, 7U,
		7U, 7U
	};
	uint4x2 c = uint4x2_cor( &a, &b );

	TEMPER_CHECK_TRUE( uint4x2_cmpe( &c, &answer ) );
}

TEMPER_TEST( TestBitwise_Xor_uint4x2, TEMPER_FLAG_SHOULD_RUN )
{
	uint4x2 answer  = (uint4x2) {
		18U, 18U,
		18U, 18U,
		18U, 18U,
		18U, 18U
	};
	uint4x2 a = (uint4x2) {
		21U, 21U,
		21U, 21U,
		21U, 21U,
		21U, 21U
	};
	uint4x2 b = (uint4x2) {
		7U, 7U,
		7U, 7U,
		7U, 7U,
		7U, 7U
	};
	uint4x2 c = uint4x2_cxor( &a, &b );

	TEMPER_CHECK_TRUE( uint4x2_cmpe( &c, &answer ) );
}

TEMPER_TEST( TestBitwise_ShiftLeft_uint4x2, TEMPER_FLAG_SHOULD_RUN )
{
	uint4x2 answer  = (uint4x2) {
		4U, 4U,
		4U, 4U,
		4U, 4U,
		4U, 4U
	};
	uint4x2 a = (uint4x2) {
		1U, 1U,
		1U, 1U,
		1U, 1U,
		1U, 1U
	};
	uint4x2 b = (uint4x2) {
		2U, 2U,
		2U, 2U,
		2U, 2U,
		2U, 2U
	};
	uint4x2 c = uint4x2_cshift_left( &a, &b );

	TEMPER_CHECK_TRUE( uint4x2_cmpe( &c, &answer ) );
}

TEMPER_TEST( TestBitwise_ShiftRight_uint4x2, TEMPER_FLAG_SHOULD_RUN )
{
	uint4x2 answer  = (uint4x2) {
		1U, 1U,
		1U, 1U,
		1U, 1U,
		1U, 1U
	};
	uint4x2 a = (uint4x2) {
		16U, 16U,
		16U, 16U,
		16U, 16U,
		16U, 16U
	};
	uint4x2 b = (uint4x2) {
		4U, 4U,
		4U, 4U,
		4U, 4U,
		4U, 4U
	};
	uint4x2 c = uint4x2_cshift_right( &a, &b );

	TEMPER_CHECK_TRUE( uint4x2_cmpe( &c, &answer ) );
}

TEMPER_TEST( TestBitwise_Unary_uint4x2, TEMPER_FLAG_SHOULD_RUN )
{
	uint4x2 answer = (uint4x2) {
		(uint32_t) -1, (uint32_t) -1,
		(uint32_t) -1, (uint32_t) -1,
		(uint32_t) -1, (uint32_t) -1,
		(uint32_t) -1, (uint32_t) -1
	};
	uint4x2 a = (uint4x2) {
		0U, 0U,
		0U, 0U,
		0U, 0U,
		0U, 0U
	};

	uint4x2 b = uint4x2_cunary( &a );

	TEMPER_CHECK_TRUE( uint4x2_cmpe( &b, &answer ) );
}

TEMPER_TEST( TestIdentity_Scalar_uint4x2, TEMPER_FLAG_SHOULD_RUN )
{
	uint4x2 id;
	id.rows[0] = (uint2) { 1U, 0U };
	id.rows[1] = (uint2) { 0U, 1U };
	id.rows[2] = (uint2) { 0U, 0U };
	id.rows[3] = (uint2) { 0U, 0U };

	uint4x2 mat;
	uint4x2_identity( &mat );
	TEMPER_CHECK_TRUE( uint4x2_cmpe( &mat, &id ) );
}

TEMPER_TEST( TestTranspose_Scalar_uint4x2, TEMPER_FLAG_SHOULD_RUN )
{
	uint2x4 answerTransposed = (uint2x4) {
		0U, 4U, 8U, 12U,
		1U, 5U, 9U, 13U
	};

	uint4x2 mat = (uint4x2) {
		0U, 1U,
		4U, 5U,
		8U, 9U,
		12U, 13U
	};
	uint2x4 trans = uint4x2_transpose( &mat );

	TEMPER_CHECK_TRUE( uint2x4_cmpe( &trans, &answerTransposed ) );
}


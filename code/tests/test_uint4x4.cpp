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

#include "hlml.h"

#include <temper/temper.h>

static uint4x4 g_identityMatrix_uint4x4;

static uint4x4 g_matrixMulLHS_uint4x4    = uint4x4(
		6U, 6U, 6U, 6U,
		6U, 6U, 6U, 6U,
		12U, 12U, 12U, 12U,
		18U, 18U, 18U, 18U
	);
static uint4x4 g_matrixMulRHS_uint4x4    = uint4x4(
		1U, 1U, 1U, 1U,
		2U, 2U, 2U, 2U,
		3U, 3U, 3U, 3U,
		6U, 6U, 6U, 6U
	);
static uint4x4 g_matrixMulAnswer_uint4x4 = uint4x4(
		72U, 72U, 72U, 72U,
		72U, 72U, 72U, 72U,
		144U, 144U, 144U, 144U,
		216U, 216U, 216U, 216U
	);

TEMPER_TEST( TestAssignment_uint4x4 )
{
	uint4x4 mat;

	// fill single value
	mat = uint4x4( 999U );
	TEMPER_EXPECT_TRUE( mat[0] == uint4( 999U, 0U, 0U, 0U ) );
	TEMPER_EXPECT_TRUE( mat[1] == uint4( 0U, 999U, 0U, 0U ) );
	TEMPER_EXPECT_TRUE( mat[2] == uint4( 0U, 0U, 999U, 0U ) );
	TEMPER_EXPECT_TRUE( mat[3] == uint4( 0U, 0U, 0U, 999U ) );

	// row filling
	mat = uint4x4(
		uint4( 0U, 1U, 2U, 3U ),
		uint4( 4U, 5U, 6U, 7U ),
		uint4( 8U, 9U, 10U, 11U ),
		uint4( 12U, 13U, 14U, 15U )
	);
	TEMPER_EXPECT_TRUE( mat[0] == uint4( 0U, 1U, 2U, 3U ) );
	TEMPER_EXPECT_TRUE( mat[1] == uint4( 4U, 5U, 6U, 7U ) );
	TEMPER_EXPECT_TRUE( mat[2] == uint4( 8U, 9U, 10U, 11U ) );
	TEMPER_EXPECT_TRUE( mat[3] == uint4( 12U, 13U, 14U, 15U ) );

	// all values filled
	mat = uint4x4(
		16U, 15U, 14U, 13U,
		12U, 11U, 10U, 9U,
		8U, 7U, 6U, 5U,
		4U, 3U, 2U, 1U
	);
	TEMPER_EXPECT_TRUE( mat[0] == uint4( 16U, 15U, 14U, 13U ) );
	TEMPER_EXPECT_TRUE( mat[1] == uint4( 12U, 11U, 10U, 9U ) );
	TEMPER_EXPECT_TRUE( mat[2] == uint4( 8U, 7U, 6U, 5U ) );
	TEMPER_EXPECT_TRUE( mat[3] == uint4( 4U, 3U, 2U, 1U ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestComponentWiseArithmetic_Scalar_Addition_uint4x4 )
{
	uint4x4 answer = uint4x4(
		7U, 7U, 7U, 7U,
		8U, 8U, 8U, 8U,
		15U, 15U, 15U, 15U,
		24U, 24U, 24U, 24U
	);

	uint4x4 a = uint4x4(
		6U, 6U, 6U, 6U,
		6U, 6U, 6U, 6U,
		12U, 12U, 12U, 12U,
		18U, 18U, 18U, 18U
	);
	uint4x4 b = uint4x4(
		1U, 1U, 1U, 1U,
		2U, 2U, 2U, 2U,
		3U, 3U, 3U, 3U,
		6U, 6U, 6U, 6U
	);
	uint4x4 c = a + b;

	TEMPER_EXPECT_TRUE( c == answer );

	TEMPER_PASS();
}

TEMPER_TEST( TestComponentWiseArithmetic_Scalar_Subtraction_uint4x4 )
{
	uint4x4 answer = uint4x4(
		5U, 5U, 5U, 5U,
		4U, 4U, 4U, 4U,
		9U, 9U, 9U, 9U,
		12U, 12U, 12U, 12U
	);

	uint4x4 a = uint4x4(
		6U, 6U, 6U, 6U,
		6U, 6U, 6U, 6U,
		12U, 12U, 12U, 12U,
		18U, 18U, 18U, 18U
	);
	uint4x4 b = uint4x4(
		1U, 1U, 1U, 1U,
		2U, 2U, 2U, 2U,
		3U, 3U, 3U, 3U,
		6U, 6U, 6U, 6U
	);
	uint4x4 c = a - b;

	TEMPER_EXPECT_TRUE( c == answer );

	TEMPER_PASS();
}

TEMPER_TEST( TestComponentWiseArithmetic_Scalar_Multiplication_uint4x4 )
{
	uint4x4 answer = uint4x4(
		6U, 6U, 6U, 6U,
		12U, 12U, 12U, 12U,
		36U, 36U, 36U, 36U,
		108U, 108U, 108U, 108U
	);

	uint4x4 a = uint4x4(
		6U, 6U, 6U, 6U,
		6U, 6U, 6U, 6U,
		12U, 12U, 12U, 12U,
		18U, 18U, 18U, 18U
	);
	uint4x4 b = uint4x4(
		1U, 1U, 1U, 1U,
		2U, 2U, 2U, 2U,
		3U, 3U, 3U, 3U,
		6U, 6U, 6U, 6U
	);
	uint4x4 c = comp_mul( a, b );

	TEMPER_EXPECT_TRUE( c == answer );

	TEMPER_PASS();
}

TEMPER_TEST( TestComponentWiseArithmetic_Scalar_Division_uint4x4 )
{
	uint4x4 answer = uint4x4(
		6U, 6U, 6U, 6U,
		3U, 3U, 3U, 3U,
		4U, 4U, 4U, 4U,
		3U, 3U, 3U, 3U
	);

	uint4x4 a = uint4x4(
		6U, 6U, 6U, 6U,
		6U, 6U, 6U, 6U,
		12U, 12U, 12U, 12U,
		18U, 18U, 18U, 18U
	);
	uint4x4 b = uint4x4(
		1U, 1U, 1U, 1U,
		2U, 2U, 2U, 2U,
		3U, 3U, 3U, 3U,
		6U, 6U, 6U, 6U
	);
	uint4x4 c = comp_div( a, b );

	TEMPER_EXPECT_TRUE( c == answer );

	TEMPER_PASS();
}

TEMPER_TEST( TestMultiplyMatrix_Scalar_uint4x4 )
{
	uint4x4 answer = g_matrixMulAnswer_uint4x4;

	uint4x4 a = g_matrixMulLHS_uint4x4;
	uint4x4 b = g_matrixMulRHS_uint4x4;
	uint4x4 c = a * b;

	TEMPER_EXPECT_TRUE( c == answer );

	TEMPER_PASS();
}

TEMPER_TEST( TestMultiplyVector_uint4x4 )
{
	uint4 answerVec = uint4( 28U, 68U, 108U, 148U );

	uint4x4 a = uint4x4(
		1U, 2U, 3U, 4U,
		5U, 6U, 7U, 8U,
		9U, 10U, 11U, 12U,
		13U, 14U, 15U, 16U
	);
	uint4 b = uint4( 2U, 1U, 4U, 3U );
	uint4 c = a * b;

	TEMPER_EXPECT_TRUE( c == answerVec );

	TEMPER_PASS();
}

TEMPER_TEST( TestIncrement_uint4x4 )
{
	uint4x4 mat;

	// prefix
	mat = uint4x4(
		0U, 0U, 0U, 0U,
		0U, 0U, 0U, 0U,
		0U, 0U, 0U, 0U,
		0U, 0U, 0U, 0U
	);
	++mat;
	TEMPER_EXPECT_TRUE( mat == uint4x4(
		1U, 1U, 1U, 1U,
		1U, 1U, 1U, 1U,
		1U, 1U, 1U, 1U,
		1U, 1U, 1U, 1U
	) );

	// postfix
	mat = uint4x4(
		0U, 0U, 0U, 0U,
		0U, 0U, 0U, 0U,
		0U, 0U, 0U, 0U,
		0U, 0U, 0U, 0U
	);
	mat++;
	TEMPER_EXPECT_TRUE( mat == uint4x4(
		1U, 1U, 1U, 1U,
		1U, 1U, 1U, 1U,
		1U, 1U, 1U, 1U,
		1U, 1U, 1U, 1U
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestDecrement_uint4x4 )
{
	uint4x4 mat;

	// prefix
	mat = uint4x4(
		1U, 1U, 1U, 1U,
		1U, 1U, 1U, 1U,
		1U, 1U, 1U, 1U,
		1U, 1U, 1U, 1U
	);
	--mat;
	TEMPER_EXPECT_TRUE( mat == uint4x4(
		0U, 0U, 0U, 0U,
		0U, 0U, 0U, 0U,
		0U, 0U, 0U, 0U,
		0U, 0U, 0U, 0U
	) );

	// postfix
	mat = uint4x4(
		1U, 1U, 1U, 1U,
		1U, 1U, 1U, 1U,
		1U, 1U, 1U, 1U,
		1U, 1U, 1U, 1U
	);
	mat--;
	TEMPER_EXPECT_TRUE( mat == uint4x4(
		0U, 0U, 0U, 0U,
		0U, 0U, 0U, 0U,
		0U, 0U, 0U, 0U,
		0U, 0U, 0U, 0U
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestRelational_uint4x4 )
{
	bool4x4 allTrue = bool4x4(
		true, true, true, true,
		true, true, true, true,
		true, true, true, true,
		true, true, true, true
	);

	uint4x4 mat0 = uint4x4(
		1U, 1U, 1U, 1U,
		1U, 1U, 1U, 1U,
		1U, 1U, 1U, 1U,
		1U, 1U, 1U, 1U
	);
	uint4x4 mat1 = uint4x4(
		2U, 2U, 2U, 2U,
		2U, 2U, 2U, 2U,
		2U, 2U, 2U, 2U,
		2U, 2U, 2U, 2U
	);
	uint4x4 mat2 = uint4x4(
		3U, 3U, 3U, 3U,
		3U, 3U, 3U, 3U,
		3U, 3U, 3U, 3U,
		3U, 3U, 3U, 3U
	);
	uint4x4 mat3 = uint4x4(
		4U, 4U, 4U, 4U,
		4U, 4U, 4U, 4U,
		4U, 4U, 4U, 4U,
		4U, 4U, 4U, 4U
	);

	bool4x4 test0  = mat0 <= mat0;
	bool4x4 test1  = mat0 >= mat0;
	bool4x4 test2  = mat0 <  mat1;
	bool4x4 test3  = mat0 <  mat2;
	bool4x4 test4  = mat0 <  mat3;

	bool4x4 test5  = mat1 >  mat0;
	bool4x4 test6  = mat1 <= mat1;
	bool4x4 test7  = mat1 >= mat1;
	bool4x4 test8  = mat1 <  mat2;
	bool4x4 test9  = mat1 <  mat3;

	bool4x4 test10 = mat2 >  mat0;
	bool4x4 test11 = mat2 >  mat1;
	bool4x4 test12 = mat2 <= mat2;
	bool4x4 test13 = mat2 >= mat2;
	bool4x4 test14 = mat2 <  mat3;

	bool4x4 test15 = mat3 >  mat0;
	bool4x4 test16 = mat3 >  mat1;
	bool4x4 test17 = mat3 >  mat2;
	bool4x4 test18 = mat3 <= mat3;
	bool4x4 test19 = mat3 >= mat3;

	TEMPER_EXPECT_TRUE( test0  == allTrue );
	TEMPER_EXPECT_TRUE( test1  == allTrue );
	TEMPER_EXPECT_TRUE( test2  == allTrue );
	TEMPER_EXPECT_TRUE( test3  == allTrue );
	TEMPER_EXPECT_TRUE( test4  == allTrue );

	TEMPER_EXPECT_TRUE( test5  == allTrue );
	TEMPER_EXPECT_TRUE( test6  == allTrue );
	TEMPER_EXPECT_TRUE( test7  == allTrue );
	TEMPER_EXPECT_TRUE( test8  == allTrue );
	TEMPER_EXPECT_TRUE( test9  == allTrue );

	TEMPER_EXPECT_TRUE( test10 == allTrue );
	TEMPER_EXPECT_TRUE( test11 == allTrue );
	TEMPER_EXPECT_TRUE( test12 == allTrue );
	TEMPER_EXPECT_TRUE( test13 == allTrue );
	TEMPER_EXPECT_TRUE( test14 == allTrue );

	TEMPER_EXPECT_TRUE( test15 == allTrue );
	TEMPER_EXPECT_TRUE( test16 == allTrue );
	TEMPER_EXPECT_TRUE( test17 == allTrue );
	TEMPER_EXPECT_TRUE( test18 == allTrue );
	TEMPER_EXPECT_TRUE( test19 == allTrue );

	TEMPER_PASS();
}

TEMPER_TEST( TestArray_uint4x4 )
{
	uint4x4 mat;

	TEMPER_EXPECT_TRUE( mat[0] == uint4( 1U, 0U, 0U, 0U ) );
	TEMPER_EXPECT_TRUE( mat[1] == uint4( 0U, 1U, 0U, 0U ) );
	TEMPER_EXPECT_TRUE( mat[2] == uint4( 0U, 0U, 1U, 0U ) );
	TEMPER_EXPECT_TRUE( mat[3] == uint4( 0U, 0U, 0U, 1U ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestBitwise_And_uint4x4 )
{
	uint4x4 a  = uint4x4(
		21U, 21U, 21U, 21U,
		21U, 21U, 21U, 21U,
		21U, 21U, 21U, 21U,
		21U, 21U, 21U, 21U
	);
	uint4x4 b  = uint4x4(
		7U, 7U, 7U, 7U,
		7U, 7U, 7U, 7U,
		7U, 7U, 7U, 7U,
		7U, 7U, 7U, 7U
	);

	uint4x4 answer = a & b;

	TEMPER_EXPECT_TRUE( answer == uint4x4(
		5U, 5U, 5U, 5U,
		5U, 5U, 5U, 5U,
		5U, 5U, 5U, 5U,
		5U, 5U, 5U, 5U
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestBitwise_Or_uint4x4 )
{
	uint4x4 a  = uint4x4(
		21U, 21U, 21U, 21U,
		21U, 21U, 21U, 21U,
		21U, 21U, 21U, 21U,
		21U, 21U, 21U, 21U
	);
	uint4x4 b  = uint4x4(
		7U, 7U, 7U, 7U,
		7U, 7U, 7U, 7U,
		7U, 7U, 7U, 7U,
		7U, 7U, 7U, 7U
	);

	uint4x4 answer = a | b;

	TEMPER_EXPECT_TRUE( answer == uint4x4(
		23U, 23U, 23U, 23U,
		23U, 23U, 23U, 23U,
		23U, 23U, 23U, 23U,
		23U, 23U, 23U, 23U
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestBitwise_Xor_uint4x4 )
{
	uint4x4 a  = uint4x4(
		21U, 21U, 21U, 21U,
		21U, 21U, 21U, 21U,
		21U, 21U, 21U, 21U,
		21U, 21U, 21U, 21U
	);
	uint4x4 b  = uint4x4(
		7U, 7U, 7U, 7U,
		7U, 7U, 7U, 7U,
		7U, 7U, 7U, 7U,
		7U, 7U, 7U, 7U
	);

	uint4x4 answer = a ^ b;

	TEMPER_EXPECT_TRUE( answer == uint4x4(
		18U, 18U, 18U, 18U,
		18U, 18U, 18U, 18U,
		18U, 18U, 18U, 18U,
		18U, 18U, 18U, 18U
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestBitwise_ShiftLeft_uint4x4 )
{
	uint4x4 a  = uint4x4(
		1U, 1U, 1U, 1U,
		1U, 1U, 1U, 1U,
		1U, 1U, 1U, 1U,
		1U, 1U, 1U, 1U
	);
	uint4x4 b  = uint4x4(
		2U, 2U, 2U, 2U,
		2U, 2U, 2U, 2U,
		2U, 2U, 2U, 2U,
		2U, 2U, 2U, 2U
	);

	uint4x4 answer = a << b;

	TEMPER_EXPECT_TRUE( answer == uint4x4(
		4U, 4U, 4U, 4U,
		4U, 4U, 4U, 4U,
		4U, 4U, 4U, 4U,
		4U, 4U, 4U, 4U
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestBitwise_ShiftRight_uint4x4 )
{
	uint4x4 a  = uint4x4(
		16U, 16U, 16U, 16U,
		16U, 16U, 16U, 16U,
		16U, 16U, 16U, 16U,
		16U, 16U, 16U, 16U
	);
	uint4x4 b  = uint4x4(
		4U, 4U, 4U, 4U,
		4U, 4U, 4U, 4U,
		4U, 4U, 4U, 4U,
		4U, 4U, 4U, 4U
	);

	uint4x4 answer = a >> b;

	TEMPER_EXPECT_TRUE( answer == uint4x4(
		1U, 1U, 1U, 1U,
		1U, 1U, 1U, 1U,
		1U, 1U, 1U, 1U,
		1U, 1U, 1U, 1U
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestBitwise_Unary_uint4x4 )
{
	uint4x4 a = uint4x4(
		0U, 0U, 0U, 0U,
		0U, 0U, 0U, 0U,
		0U, 0U, 0U, 0U,
		0U, 0U, 0U, 0U
	);

	uint4x4 answer = ~a;

	TEMPER_EXPECT_TRUE( answer == uint4x4(
		(uint32_t) -1, (uint32_t) -1, (uint32_t) -1, (uint32_t) -1,
		(uint32_t) -1, (uint32_t) -1, (uint32_t) -1, (uint32_t) -1,
		(uint32_t) -1, (uint32_t) -1, (uint32_t) -1, (uint32_t) -1,
		(uint32_t) -1, (uint32_t) -1, (uint32_t) -1, (uint32_t) -1
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestIdentity_Scalar_uint4x4 )
{
	uint4x4 id = uint4x4(
		1U, 0, 0, 0,
		0, 1U, 0, 0,
		0, 0, 1U, 0,
		0, 0, 0, 1U
	);

	uint4x4 mat;
	TEMPER_EXPECT_TRUE( mat == id );

	identity( mat );
	TEMPER_EXPECT_TRUE( mat == id );

	TEMPER_PASS();
}

TEMPER_TEST( TestTranspose_Scalar_uint4x4 )
{
	uint4x4 mat = uint4x4(
		0U, 1U, 2U, 3U,
		4U, 5U, 6U, 7U,
		8U, 9U, 10U, 11U,
		12U, 13U, 14U, 15U
	);
	uint4x4 trans = transpose( mat );

	TEMPER_EXPECT_TRUE( trans == uint4x4(
		0U, 4U, 8U, 12U,
		1U, 5U, 9U, 13U,
		2U, 6U, 10U, 14U,
		3U, 7U, 11U, 15U
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestTranslate_Scalar_uint4x4 )
{
	uint4x4 mat;

	uint3 translation = uint3( 2U, 3U, 4U );
	mat = translate( mat, translation );

	TEMPER_EXPECT_TRUE( mat[0][3] == 2U );
	TEMPER_EXPECT_TRUE( mat[1][3] == 3U );
	TEMPER_EXPECT_TRUE( mat[2][3] == 4U );

	TEMPER_PASS();
}

TEMPER_TEST( TestScale_Scalar_uint4x4 )
{
	uint4x4 mat;
	uint4x4 scaled = scale( mat, uint3( 2U, 2U, 2U ) );

	TEMPER_EXPECT_TRUE( scaled[0][0] == 2U );
	TEMPER_EXPECT_TRUE( scaled[1][1] == 2U );
	TEMPER_EXPECT_TRUE( scaled[2][2] == 2U );

	TEMPER_PASS();
}

TEMPER_SUITE( Test_uint4x4 )
{
	TEMPER_RUN_TEST( TestAssignment_uint4x4 );
	TEMPER_RUN_TEST( TestComponentWiseArithmetic_Scalar_Addition_uint4x4 );
	TEMPER_RUN_TEST( TestComponentWiseArithmetic_Scalar_Subtraction_uint4x4 );
	TEMPER_RUN_TEST( TestComponentWiseArithmetic_Scalar_Multiplication_uint4x4 );
	TEMPER_RUN_TEST( TestComponentWiseArithmetic_Scalar_Division_uint4x4 );
	TEMPER_RUN_TEST( TestMultiplyMatrix_Scalar_uint4x4 );
	TEMPER_RUN_TEST( TestMultiplyVector_uint4x4 );
	TEMPER_RUN_TEST( TestIncrement_uint4x4 );
	TEMPER_RUN_TEST( TestDecrement_uint4x4 );
	TEMPER_RUN_TEST( TestRelational_uint4x4 );
	TEMPER_RUN_TEST( TestArray_uint4x4 );
	TEMPER_RUN_TEST( TestBitwise_And_uint4x4 );
	TEMPER_RUN_TEST( TestBitwise_Or_uint4x4 );
	TEMPER_RUN_TEST( TestBitwise_Xor_uint4x4 );
	TEMPER_RUN_TEST( TestBitwise_ShiftLeft_uint4x4 );
	TEMPER_RUN_TEST( TestBitwise_ShiftRight_uint4x4 );
	TEMPER_RUN_TEST( TestBitwise_Unary_uint4x4 );
	TEMPER_RUN_TEST( TestIdentity_Scalar_uint4x4 );
	TEMPER_RUN_TEST( TestTranspose_Scalar_uint4x4 );
	TEMPER_RUN_TEST( TestTranslate_Scalar_uint4x4 );
	TEMPER_RUN_TEST( TestScale_Scalar_uint4x4 );
}

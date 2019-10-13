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

static double2x3 g_identityMatrix_double2x3;

static double2x3 g_matrixMulLHS_double2x3    = double2x3(
		6.000000, 6.000000, 6.000000,
		6.000000, 6.000000, 6.000000
	);
static double3x2 g_matrixMulRHS_double2x3    = double3x2(
		1.000000, 1.000000,
		2.000000, 2.000000,
		3.000000, 3.000000
	);
static double2x2 g_matrixMulAnswer_double2x3 = double2x2(
		36.000000, 36.000000,
		36.000000, 36.000000
	);

TEMPER_TEST( TestAssignment_double2x3 )
{
	double2x3 mat;

	// fill single value
	mat = double2x3( 999.0 );
	TEMPER_EXPECT_TRUE( mat[0] == double3( 999.000000, 0.000000, 0.000000 ) );
	TEMPER_EXPECT_TRUE( mat[1] == double3( 0.000000, 999.000000, 0.000000 ) );

	// row filling
	mat = double2x3(
		double3( 0.000000, 1.000000, 2.000000 ),
		double3( 4.000000, 5.000000, 6.000000 )
	);
	TEMPER_EXPECT_TRUE( mat[0] == double3( 0.000000, 1.000000, 2.000000 ) );
	TEMPER_EXPECT_TRUE( mat[1] == double3( 4.000000, 5.000000, 6.000000 ) );

	// all values filled
	mat = double2x3(
		16.000000, 15.000000, 14.000000,
		12.000000, 11.000000, 10.000000
	);
	TEMPER_EXPECT_TRUE( mat[0] == double3( 16.000000, 15.000000, 14.000000 ) );
	TEMPER_EXPECT_TRUE( mat[1] == double3( 12.000000, 11.000000, 10.000000 ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestComponentWiseArithmetic_Scalar_Addition_double2x3 )
{
	double2x3 answer = double2x3(
		7.000000, 7.000000, 7.000000,
		8.000000, 8.000000, 8.000000
	);

	double2x3 a = double2x3(
		6.000000, 6.000000, 6.000000,
		6.000000, 6.000000, 6.000000
	);
	double2x3 b = double2x3(
		1.000000, 1.000000, 1.000000,
		2.000000, 2.000000, 2.000000
	);
	double2x3 c = a + b;

	TEMPER_EXPECT_TRUE( c == answer );

	TEMPER_PASS();
}

TEMPER_TEST( TestComponentWiseArithmetic_Scalar_Subtraction_double2x3 )
{
	double2x3 answer = double2x3(
		5.000000, 5.000000, 5.000000,
		4.000000, 4.000000, 4.000000
	);

	double2x3 a = double2x3(
		6.000000, 6.000000, 6.000000,
		6.000000, 6.000000, 6.000000
	);
	double2x3 b = double2x3(
		1.000000, 1.000000, 1.000000,
		2.000000, 2.000000, 2.000000
	);
	double2x3 c = a - b;

	TEMPER_EXPECT_TRUE( c == answer );

	TEMPER_PASS();
}

TEMPER_TEST( TestComponentWiseArithmetic_Scalar_Multiplication_double2x3 )
{
	double2x3 answer = double2x3(
		6.000000, 6.000000, 6.000000,
		12.000000, 12.000000, 12.000000
	);

	double2x3 a = double2x3(
		6.000000, 6.000000, 6.000000,
		6.000000, 6.000000, 6.000000
	);
	double2x3 b = double2x3(
		1.000000, 1.000000, 1.000000,
		2.000000, 2.000000, 2.000000
	);
	double2x3 c = comp_mul( a, b );

	TEMPER_EXPECT_TRUE( c == answer );

	TEMPER_PASS();
}

TEMPER_TEST( TestComponentWiseArithmetic_Scalar_Division_double2x3 )
{
	double2x3 answer = double2x3(
		6.000000, 6.000000, 6.000000,
		3.000000, 3.000000, 3.000000
	);

	double2x3 a = double2x3(
		6.000000, 6.000000, 6.000000,
		6.000000, 6.000000, 6.000000
	);
	double2x3 b = double2x3(
		1.000000, 1.000000, 1.000000,
		2.000000, 2.000000, 2.000000
	);
	double2x3 c = comp_div( a, b );

	TEMPER_EXPECT_TRUE( c == answer );

	TEMPER_PASS();
}

TEMPER_TEST( TestMultiplyMatrix_Scalar_double2x3 )
{
	double2x2 answer = g_matrixMulAnswer_double2x3;

	double2x3 a = g_matrixMulLHS_double2x3;
	double3x2 b = g_matrixMulRHS_double2x3;
	double2x2 c = a * b;

	TEMPER_EXPECT_TRUE( c == answer );

	TEMPER_PASS();
}

TEMPER_TEST( TestIncrement_double2x3 )
{
	double2x3 mat;

	// prefix
	mat = double2x3(
		0.000000, 0.000000, 0.000000,
		0.000000, 0.000000, 0.000000
	);
	++mat;
	TEMPER_EXPECT_TRUE( mat == double2x3(
		1.000000, 1.000000, 1.000000,
		1.000000, 1.000000, 1.000000
	) );

	// postfix
	mat = double2x3(
		0.000000, 0.000000, 0.000000,
		0.000000, 0.000000, 0.000000
	);
	mat++;
	TEMPER_EXPECT_TRUE( mat == double2x3(
		1.000000, 1.000000, 1.000000,
		1.000000, 1.000000, 1.000000
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestDecrement_double2x3 )
{
	double2x3 mat;

	// prefix
	mat = double2x3(
		1.000000, 1.000000, 1.000000,
		1.000000, 1.000000, 1.000000
	);
	--mat;
	TEMPER_EXPECT_TRUE( mat == double2x3(
		0.000000, 0.000000, 0.000000,
		0.000000, 0.000000, 0.000000
	) );

	// postfix
	mat = double2x3(
		1.000000, 1.000000, 1.000000,
		1.000000, 1.000000, 1.000000
	);
	mat--;
	TEMPER_EXPECT_TRUE( mat == double2x3(
		0.000000, 0.000000, 0.000000,
		0.000000, 0.000000, 0.000000
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestRelational_double2x3 )
{
	bool2x3 allTrue = bool2x3(
		true, true, true,
		true, true, true
	);

	double2x3 mat0 = double2x3(
		1.000000, 1.000000, 1.000000,
		1.000000, 1.000000, 1.000000
	);
	double2x3 mat1 = double2x3(
		2.000000, 2.000000, 2.000000,
		2.000000, 2.000000, 2.000000
	);
	double2x3 mat2 = double2x3(
		3.000000, 3.000000, 3.000000,
		3.000000, 3.000000, 3.000000
	);
	double2x3 mat3 = double2x3(
		4.000000, 4.000000, 4.000000,
		4.000000, 4.000000, 4.000000
	);

	bool2x3 test0  = mat0 <= mat0;
	bool2x3 test1  = mat0 >= mat0;
	bool2x3 test2  = mat0 <  mat1;
	bool2x3 test3  = mat0 <  mat2;
	bool2x3 test4  = mat0 <  mat3;

	bool2x3 test5  = mat1 >  mat0;
	bool2x3 test6  = mat1 <= mat1;
	bool2x3 test7  = mat1 >= mat1;
	bool2x3 test8  = mat1 <  mat2;
	bool2x3 test9  = mat1 <  mat3;

	bool2x3 test10 = mat2 >  mat0;
	bool2x3 test11 = mat2 >  mat1;
	bool2x3 test12 = mat2 <= mat2;
	bool2x3 test13 = mat2 >= mat2;
	bool2x3 test14 = mat2 <  mat3;

	bool2x3 test15 = mat3 >  mat0;
	bool2x3 test16 = mat3 >  mat1;
	bool2x3 test17 = mat3 >  mat2;
	bool2x3 test18 = mat3 <= mat3;
	bool2x3 test19 = mat3 >= mat3;

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

TEMPER_TEST( TestArray_double2x3 )
{
	double2x3 mat;

	TEMPER_EXPECT_TRUE( mat[0] == double3( 1.0, 0.0, 0.0 ) );
	TEMPER_EXPECT_TRUE( mat[1] == double3( 0.0, 1.0, 0.0 ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestIdentity_Scalar_double2x3 )
{
	double2x3 id = double2x3(
		1.000000, 0.0, 0.0,
		0.0, 1.000000, 0.0
	);

	double2x3 mat;
	TEMPER_EXPECT_TRUE( mat == id );

	identity( mat );
	TEMPER_EXPECT_TRUE( mat == id );

	TEMPER_PASS();
}

TEMPER_TEST( TestTranspose_Scalar_double2x3 )
{
	double2x3 mat = double2x3(
		0.000000, 1.000000, 2.000000,
		4.000000, 5.000000, 6.000000
	);
	double3x2 trans = transpose( mat );

	TEMPER_EXPECT_TRUE( trans == double3x2(
		0.000000, 4.000000,
		1.000000, 5.000000,
		2.000000, 6.000000
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestScale_Scalar_double2x3 )
{
	double2x3 mat;
	double2x3 scaled = scale( mat, double2( 2.000000, 2.000000 ) );

	TEMPER_EXPECT_TRUE( doubleeq( scaled[0][0], 2.000000 ) );
	TEMPER_EXPECT_TRUE( doubleeq( scaled[1][1], 2.000000 ) );

	TEMPER_PASS();
}

TEMPER_SUITE( Test_double2x3 )
{
	TEMPER_RUN_TEST( TestAssignment_double2x3 );
	TEMPER_RUN_TEST( TestComponentWiseArithmetic_Scalar_Addition_double2x3 );
	TEMPER_RUN_TEST( TestComponentWiseArithmetic_Scalar_Subtraction_double2x3 );
	TEMPER_RUN_TEST( TestComponentWiseArithmetic_Scalar_Multiplication_double2x3 );
	TEMPER_RUN_TEST( TestComponentWiseArithmetic_Scalar_Division_double2x3 );
	TEMPER_RUN_TEST( TestMultiplyMatrix_Scalar_double2x3 );
	TEMPER_RUN_TEST( TestIncrement_double2x3 );
	TEMPER_RUN_TEST( TestDecrement_double2x3 );
	TEMPER_RUN_TEST( TestRelational_double2x3 );
	TEMPER_RUN_TEST( TestArray_double2x3 );
	TEMPER_RUN_TEST( TestIdentity_Scalar_double2x3 );
	TEMPER_RUN_TEST( TestTranspose_Scalar_double2x3 );
	TEMPER_RUN_TEST( TestScale_Scalar_double2x3 );
}

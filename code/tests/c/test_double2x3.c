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

static double2x3 g_matrixMulLHS_double2x3    = (double2x3) {
		6.000000, 6.000000, 6.000000,
		6.000000, 6.000000, 6.000000
};

static double3x2 g_matrixMulRHS_double2x3    = (double3x2) {
		1.000000, 1.000000,
		2.000000, 2.000000,
		3.000000, 3.000000
};

static double2x2 g_matrixMulAnswer_double2x3 = (double2x2) {
		36.000000, 36.000000,
		36.000000, 36.000000
};


TEMPER_TEST( TestAssignment_double2x3 )
{
	double2x3 mat;

	mat.rows[0] = (double3) { 999.000000, 0.000000, 0.000000 };
	mat.rows[1] = (double3) { 0.000000, 999.000000, 0.000000 };

	TEMPER_EXPECT_TRUE( mat.rows[0].x == 999.0 );
	TEMPER_EXPECT_TRUE( mat.rows[0].y == 0.0 );
	TEMPER_EXPECT_TRUE( mat.rows[0].z == 0.0 );
	TEMPER_EXPECT_TRUE( mat.rows[1].x == 0.0 );
	TEMPER_EXPECT_TRUE( mat.rows[1].y == 999.0 );
	TEMPER_EXPECT_TRUE( mat.rows[1].z == 0.0 );

	TEMPER_PASS();
}

TEMPER_TEST( TestComponentWiseArithmetic_Scalar_Addition_double2x3 )
{
	double2x3 answer = (double2x3) {
		7.000000, 7.000000, 7.000000,
		8.000000, 8.000000, 8.000000
	};

	double2x3 a = (double2x3) {
		6.000000, 6.000000, 6.000000,
		6.000000, 6.000000, 6.000000
	};

	double2x3 b = (double2x3) {
		1.000000, 1.000000, 1.000000,
		2.000000, 2.000000, 2.000000
	};

	double2x3 c = double2x3_comp_addm( &a, &b );

	TEMPER_EXPECT_TRUE( double2x3_cmpe( &c, &answer ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestComponentWiseArithmetic_Scalar_Subtraction_double2x3 )
{
	double2x3 answer = (double2x3) {
		5.000000, 5.000000, 5.000000,
		4.000000, 4.000000, 4.000000
	};

	double2x3 a = (double2x3) {
		6.000000, 6.000000, 6.000000,
		6.000000, 6.000000, 6.000000
	};

	double2x3 b = (double2x3) {
		1.000000, 1.000000, 1.000000,
		2.000000, 2.000000, 2.000000
	};

	double2x3 c = double2x3_comp_subm( &a, &b );

	TEMPER_EXPECT_TRUE( double2x3_cmpe( &c, &answer ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestComponentWiseArithmetic_Scalar_Multiplication_double2x3 )
{
	double2x3 answer = (double2x3) {
		6.000000, 6.000000, 6.000000,
		12.000000, 12.000000, 12.000000
	};

	double2x3 a = (double2x3) {
		6.000000, 6.000000, 6.000000,
		6.000000, 6.000000, 6.000000
	};

	double2x3 b = (double2x3) {
		1.000000, 1.000000, 1.000000,
		2.000000, 2.000000, 2.000000
	};

	double2x3 c = double2x3_comp_mulm( &a, &b );

	TEMPER_EXPECT_TRUE( double2x3_cmpe( &c, &answer ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestComponentWiseArithmetic_Scalar_Division_double2x3 )
{
	double2x3 answer = (double2x3) {
		6.000000, 6.000000, 6.000000,
		3.000000, 3.000000, 3.000000
	};

	double2x3 a = (double2x3) {
		6.000000, 6.000000, 6.000000,
		6.000000, 6.000000, 6.000000
	};

	double2x3 b = (double2x3) {
		1.000000, 1.000000, 1.000000,
		2.000000, 2.000000, 2.000000
	};

	double2x3 c = double2x3_comp_divm( &a, &b );

	TEMPER_EXPECT_TRUE( double2x3_cmpe( &c, &answer ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestMultiplyMatrix_Scalar_double2x3 )
{
	double2x2 answer = g_matrixMulAnswer_double2x3;

	double2x3 a = g_matrixMulLHS_double2x3;
	double3x2 b = g_matrixMulRHS_double2x3;
	double2x2 c = double2x3_mulm( &a, &b );

	TEMPER_EXPECT_TRUE( double2x2_cmpe( &c, &answer ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestRelational_double2x3 )
{
	bool2x3 allTrue = { 		true, true, true,
		true, true, true
 };

	double2x3 mat0 = (double2x3) { 		1.000000, 1.000000, 1.000000,
		1.000000, 1.000000, 1.000000
 };
	double2x3 mat1 = (double2x3) { 		2.000000, 2.000000, 2.000000,
		2.000000, 2.000000, 2.000000
 };
	double2x3 mat2 = (double2x3) { 		3.000000, 3.000000, 3.000000,
		3.000000, 3.000000, 3.000000
 };
	double2x3 mat3 = (double2x3) { 		4.000000, 4.000000, 4.000000,
		4.000000, 4.000000, 4.000000
 };

	bool2x3 test0  = double2x3_cmple( &mat0, &mat0 );
	bool2x3 test1  = double2x3_cmpge( &mat0, &mat0 );
	bool2x3 test2  = double2x3_cmpl( &mat0, &mat1 );
	bool2x3 test3  = double2x3_cmpl( &mat0, &mat2 );
	bool2x3 test4  = double2x3_cmpl( &mat0, &mat3 );

	bool2x3 test5  = double2x3_cmpg( &mat1, &mat0 );
	bool2x3 test6  = double2x3_cmple( &mat1, &mat1 );
	bool2x3 test7  = double2x3_cmpge( &mat1, &mat1 );
	bool2x3 test8  = double2x3_cmpl( &mat1, &mat2 );
	bool2x3 test9  = double2x3_cmpl( &mat1, &mat3 );

	bool2x3 test10 = double2x3_cmpg( &mat2, &mat0 );
	bool2x3 test11 = double2x3_cmpg( &mat2, &mat1 );
	bool2x3 test12 = double2x3_cmple( &mat2, &mat2 );
	bool2x3 test13 = double2x3_cmpge( &mat2, &mat2 );
	bool2x3 test14 = double2x3_cmpl( &mat2, &mat3 );

	bool2x3 test15 = double2x3_cmpg( &mat3, &mat0 );
	bool2x3 test16 = double2x3_cmpg( &mat3, &mat1 );
	bool2x3 test17 = double2x3_cmpg( &mat3, &mat2 );
	bool2x3 test18 = double2x3_cmple( &mat3, &mat3 );
	bool2x3 test19 = double2x3_cmpge( &mat3, &mat3 );

	TEMPER_EXPECT_TRUE( bool2x3_cmpe( &test0,  &allTrue ) );
	TEMPER_EXPECT_TRUE( bool2x3_cmpe( &test1,  &allTrue ) );
	TEMPER_EXPECT_TRUE( bool2x3_cmpe( &test2,  &allTrue ) );
	TEMPER_EXPECT_TRUE( bool2x3_cmpe( &test3,  &allTrue ) );
	TEMPER_EXPECT_TRUE( bool2x3_cmpe( &test4,  &allTrue ) );

	TEMPER_EXPECT_TRUE( bool2x3_cmpe( &test5,  &allTrue ) );
	TEMPER_EXPECT_TRUE( bool2x3_cmpe( &test6,  &allTrue ) );
	TEMPER_EXPECT_TRUE( bool2x3_cmpe( &test7,  &allTrue ) );
	TEMPER_EXPECT_TRUE( bool2x3_cmpe( &test8,  &allTrue ) );
	TEMPER_EXPECT_TRUE( bool2x3_cmpe( &test9,  &allTrue ) );

	TEMPER_EXPECT_TRUE( bool2x3_cmpe( &test10, &allTrue ) );
	TEMPER_EXPECT_TRUE( bool2x3_cmpe( &test11, &allTrue ) );
	TEMPER_EXPECT_TRUE( bool2x3_cmpe( &test12, &allTrue ) );
	TEMPER_EXPECT_TRUE( bool2x3_cmpe( &test13, &allTrue ) );
	TEMPER_EXPECT_TRUE( bool2x3_cmpe( &test14, &allTrue ) );

	TEMPER_EXPECT_TRUE( bool2x3_cmpe( &test15, &allTrue ) );
	TEMPER_EXPECT_TRUE( bool2x3_cmpe( &test16, &allTrue ) );
	TEMPER_EXPECT_TRUE( bool2x3_cmpe( &test17, &allTrue ) );
	TEMPER_EXPECT_TRUE( bool2x3_cmpe( &test18, &allTrue ) );
	TEMPER_EXPECT_TRUE( bool2x3_cmpe( &test19, &allTrue ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestIdentity_Scalar_double2x3 )
{
	double2x3 id;
	id.rows[0] = (double3) { 1.000000, 0.000000, 0.000000 };
	id.rows[1] = (double3) { 0.000000, 1.000000, 0.000000 };

	double2x3 mat;
	double2x3_identity( &mat );
	TEMPER_EXPECT_TRUE( double2x3_cmpe( &mat, &id ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestTranspose_Scalar_double2x3 )
{
	double3x2 answerTransposed = (double3x2) {
		0.000000, 4.000000,
		1.000000, 5.000000,
		2.000000, 6.000000
	};

	double2x3 mat = (double2x3) {
		0.000000, 1.000000, 2.000000,
		4.000000, 5.000000, 6.000000
	};
	double3x2 trans = double2x3_transpose( &mat );

	TEMPER_EXPECT_TRUE( double3x2_cmpe( &trans, &answerTransposed ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestScale_Scalar_double2x3 )
{
	double2 scaleVec = { 2.000000, 2.000000 };
	double2x3 mat;
	double2x3_identity( &mat );

	double2x3 scaled = double2x3_scale( &mat, &scaleVec );

	TEMPER_EXPECT_TRUE( doubleeq( scaled.rows[0].x, 2.000000 ) );
	TEMPER_EXPECT_TRUE( doubleeq( scaled.rows[1].y, 2.000000 ) );

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
	TEMPER_RUN_TEST( TestRelational_double2x3 );
	TEMPER_RUN_TEST( TestIdentity_Scalar_double2x3 );
	TEMPER_RUN_TEST( TestTranspose_Scalar_double2x3 );
	TEMPER_RUN_TEST( TestScale_Scalar_double2x3 );
}

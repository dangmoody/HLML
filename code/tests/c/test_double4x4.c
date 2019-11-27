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

static double4x4 g_matrixMulLHS_double4x4    = (double4x4) {
		6.000000, 6.000000, 6.000000, 6.000000,
		6.000000, 6.000000, 6.000000, 6.000000,
		12.000000, 12.000000, 12.000000, 12.000000,
		18.000000, 18.000000, 18.000000, 18.000000
};

static double4x4 g_matrixMulRHS_double4x4    = (double4x4) {
		1.000000, 1.000000, 1.000000, 1.000000,
		2.000000, 2.000000, 2.000000, 2.000000,
		3.000000, 3.000000, 3.000000, 3.000000,
		6.000000, 6.000000, 6.000000, 6.000000
};

static double4x4 g_matrixMulAnswer_double4x4 = (double4x4) {
		72.000000, 72.000000, 72.000000, 72.000000,
		72.000000, 72.000000, 72.000000, 72.000000,
		144.000000, 144.000000, 144.000000, 144.000000,
		216.000000, 216.000000, 216.000000, 216.000000
};


TEMPER_TEST( TestAssignment_double4x4 )
{
	double4x4 mat;

	mat.rows[0] = (double4) { 999.000000, 0.000000, 0.000000, 0.000000 };
	mat.rows[1] = (double4) { 0.000000, 999.000000, 0.000000, 0.000000 };
	mat.rows[2] = (double4) { 0.000000, 0.000000, 999.000000, 0.000000 };
	mat.rows[3] = (double4) { 0.000000, 0.000000, 0.000000, 999.000000 };

	TEMPER_EXPECT_TRUE( mat.rows[0].x == 999.0 );
	TEMPER_EXPECT_TRUE( mat.rows[0].y == 0.0 );
	TEMPER_EXPECT_TRUE( mat.rows[0].z == 0.0 );
	TEMPER_EXPECT_TRUE( mat.rows[0].w == 0.0 );
	TEMPER_EXPECT_TRUE( mat.rows[1].x == 0.0 );
	TEMPER_EXPECT_TRUE( mat.rows[1].y == 999.0 );
	TEMPER_EXPECT_TRUE( mat.rows[1].z == 0.0 );
	TEMPER_EXPECT_TRUE( mat.rows[1].w == 0.0 );
	TEMPER_EXPECT_TRUE( mat.rows[2].x == 0.0 );
	TEMPER_EXPECT_TRUE( mat.rows[2].y == 0.0 );
	TEMPER_EXPECT_TRUE( mat.rows[2].z == 999.0 );
	TEMPER_EXPECT_TRUE( mat.rows[2].w == 0.0 );
	TEMPER_EXPECT_TRUE( mat.rows[3].x == 0.0 );
	TEMPER_EXPECT_TRUE( mat.rows[3].y == 0.0 );
	TEMPER_EXPECT_TRUE( mat.rows[3].z == 0.0 );
	TEMPER_EXPECT_TRUE( mat.rows[3].w == 999.0 );

	TEMPER_PASS();
}

TEMPER_TEST( TestComponentWiseArithmetic_Scalar_Addition_double4x4 )
{
	double4x4 answer = (double4x4) {
		7.000000, 7.000000, 7.000000, 7.000000,
		8.000000, 8.000000, 8.000000, 8.000000,
		15.000000, 15.000000, 15.000000, 15.000000,
		24.000000, 24.000000, 24.000000, 24.000000
	};

	double4x4 a = (double4x4) {
		6.000000, 6.000000, 6.000000, 6.000000,
		6.000000, 6.000000, 6.000000, 6.000000,
		12.000000, 12.000000, 12.000000, 12.000000,
		18.000000, 18.000000, 18.000000, 18.000000
	};

	double4x4 b = (double4x4) {
		1.000000, 1.000000, 1.000000, 1.000000,
		2.000000, 2.000000, 2.000000, 2.000000,
		3.000000, 3.000000, 3.000000, 3.000000,
		6.000000, 6.000000, 6.000000, 6.000000
	};

	double4x4 c = double4x4_comp_addm( &a, &b );

	TEMPER_EXPECT_TRUE( double4x4_cmpe( &c, &answer ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestComponentWiseArithmetic_Scalar_Subtraction_double4x4 )
{
	double4x4 answer = (double4x4) {
		5.000000, 5.000000, 5.000000, 5.000000,
		4.000000, 4.000000, 4.000000, 4.000000,
		9.000000, 9.000000, 9.000000, 9.000000,
		12.000000, 12.000000, 12.000000, 12.000000
	};

	double4x4 a = (double4x4) {
		6.000000, 6.000000, 6.000000, 6.000000,
		6.000000, 6.000000, 6.000000, 6.000000,
		12.000000, 12.000000, 12.000000, 12.000000,
		18.000000, 18.000000, 18.000000, 18.000000
	};

	double4x4 b = (double4x4) {
		1.000000, 1.000000, 1.000000, 1.000000,
		2.000000, 2.000000, 2.000000, 2.000000,
		3.000000, 3.000000, 3.000000, 3.000000,
		6.000000, 6.000000, 6.000000, 6.000000
	};

	double4x4 c = double4x4_comp_subm( &a, &b );

	TEMPER_EXPECT_TRUE( double4x4_cmpe( &c, &answer ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestComponentWiseArithmetic_Scalar_Multiplication_double4x4 )
{
	double4x4 answer = (double4x4) {
		6.000000, 6.000000, 6.000000, 6.000000,
		12.000000, 12.000000, 12.000000, 12.000000,
		36.000000, 36.000000, 36.000000, 36.000000,
		108.000000, 108.000000, 108.000000, 108.000000
	};

	double4x4 a = (double4x4) {
		6.000000, 6.000000, 6.000000, 6.000000,
		6.000000, 6.000000, 6.000000, 6.000000,
		12.000000, 12.000000, 12.000000, 12.000000,
		18.000000, 18.000000, 18.000000, 18.000000
	};

	double4x4 b = (double4x4) {
		1.000000, 1.000000, 1.000000, 1.000000,
		2.000000, 2.000000, 2.000000, 2.000000,
		3.000000, 3.000000, 3.000000, 3.000000,
		6.000000, 6.000000, 6.000000, 6.000000
	};

	double4x4 c = double4x4_comp_mulm( &a, &b );

	TEMPER_EXPECT_TRUE( double4x4_cmpe( &c, &answer ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestComponentWiseArithmetic_Scalar_Division_double4x4 )
{
	double4x4 answer = (double4x4) {
		6.000000, 6.000000, 6.000000, 6.000000,
		3.000000, 3.000000, 3.000000, 3.000000,
		4.000000, 4.000000, 4.000000, 4.000000,
		3.000000, 3.000000, 3.000000, 3.000000
	};

	double4x4 a = (double4x4) {
		6.000000, 6.000000, 6.000000, 6.000000,
		6.000000, 6.000000, 6.000000, 6.000000,
		12.000000, 12.000000, 12.000000, 12.000000,
		18.000000, 18.000000, 18.000000, 18.000000
	};

	double4x4 b = (double4x4) {
		1.000000, 1.000000, 1.000000, 1.000000,
		2.000000, 2.000000, 2.000000, 2.000000,
		3.000000, 3.000000, 3.000000, 3.000000,
		6.000000, 6.000000, 6.000000, 6.000000
	};

	double4x4 c = double4x4_comp_divm( &a, &b );

	TEMPER_EXPECT_TRUE( double4x4_cmpe( &c, &answer ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestMultiplyMatrix_Scalar_double4x4 )
{
	double4x4 answer = g_matrixMulAnswer_double4x4;

	double4x4 a = g_matrixMulLHS_double4x4;
	double4x4 b = g_matrixMulRHS_double4x4;
	double4x4 c = double4x4_mulm( &a, &b );

	TEMPER_EXPECT_TRUE( double4x4_cmpe( &c, &answer ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestMultiplyVector_double4x4 )
{
	double4 answerVec = { 28.000000, 68.000000, 108.000000, 148.000000 };

	double4x4 a = (double4x4) {
		1.000000, 2.000000, 3.000000, 4.000000,
		5.000000, 6.000000, 7.000000, 8.000000,
		9.000000, 10.000000, 11.000000, 12.000000,
		13.000000, 14.000000, 15.000000, 16.000000
	};
	double4 b = { 2.000000, 1.000000, 4.000000, 3.000000 };
	double4 c = double4x4_mulv( &a, &b );

	TEMPER_EXPECT_TRUE( double4_cmpe( &c, &answerVec ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestRelational_double4x4 )
{
	bool4x4 allTrue = { 		true, true, true, true,
		true, true, true, true,
		true, true, true, true,
		true, true, true, true
 };

	double4x4 mat0 = (double4x4) { 		1.000000, 1.000000, 1.000000, 1.000000,
		1.000000, 1.000000, 1.000000, 1.000000,
		1.000000, 1.000000, 1.000000, 1.000000,
		1.000000, 1.000000, 1.000000, 1.000000
 };
	double4x4 mat1 = (double4x4) { 		2.000000, 2.000000, 2.000000, 2.000000,
		2.000000, 2.000000, 2.000000, 2.000000,
		2.000000, 2.000000, 2.000000, 2.000000,
		2.000000, 2.000000, 2.000000, 2.000000
 };
	double4x4 mat2 = (double4x4) { 		3.000000, 3.000000, 3.000000, 3.000000,
		3.000000, 3.000000, 3.000000, 3.000000,
		3.000000, 3.000000, 3.000000, 3.000000,
		3.000000, 3.000000, 3.000000, 3.000000
 };
	double4x4 mat3 = (double4x4) { 		4.000000, 4.000000, 4.000000, 4.000000,
		4.000000, 4.000000, 4.000000, 4.000000,
		4.000000, 4.000000, 4.000000, 4.000000,
		4.000000, 4.000000, 4.000000, 4.000000
 };

	bool4x4 test0  = double4x4_cmple( &mat0, &mat0 );
	bool4x4 test1  = double4x4_cmpge( &mat0, &mat0 );
	bool4x4 test2  = double4x4_cmpl( &mat0, &mat1 );
	bool4x4 test3  = double4x4_cmpl( &mat0, &mat2 );
	bool4x4 test4  = double4x4_cmpl( &mat0, &mat3 );

	bool4x4 test5  = double4x4_cmpg( &mat1, &mat0 );
	bool4x4 test6  = double4x4_cmple( &mat1, &mat1 );
	bool4x4 test7  = double4x4_cmpge( &mat1, &mat1 );
	bool4x4 test8  = double4x4_cmpl( &mat1, &mat2 );
	bool4x4 test9  = double4x4_cmpl( &mat1, &mat3 );

	bool4x4 test10 = double4x4_cmpg( &mat2, &mat0 );
	bool4x4 test11 = double4x4_cmpg( &mat2, &mat1 );
	bool4x4 test12 = double4x4_cmple( &mat2, &mat2 );
	bool4x4 test13 = double4x4_cmpge( &mat2, &mat2 );
	bool4x4 test14 = double4x4_cmpl( &mat2, &mat3 );

	bool4x4 test15 = double4x4_cmpg( &mat3, &mat0 );
	bool4x4 test16 = double4x4_cmpg( &mat3, &mat1 );
	bool4x4 test17 = double4x4_cmpg( &mat3, &mat2 );
	bool4x4 test18 = double4x4_cmple( &mat3, &mat3 );
	bool4x4 test19 = double4x4_cmpge( &mat3, &mat3 );

	TEMPER_EXPECT_TRUE( bool4x4_cmpe( &test0,  &allTrue ) );
	TEMPER_EXPECT_TRUE( bool4x4_cmpe( &test1,  &allTrue ) );
	TEMPER_EXPECT_TRUE( bool4x4_cmpe( &test2,  &allTrue ) );
	TEMPER_EXPECT_TRUE( bool4x4_cmpe( &test3,  &allTrue ) );
	TEMPER_EXPECT_TRUE( bool4x4_cmpe( &test4,  &allTrue ) );

	TEMPER_EXPECT_TRUE( bool4x4_cmpe( &test5,  &allTrue ) );
	TEMPER_EXPECT_TRUE( bool4x4_cmpe( &test6,  &allTrue ) );
	TEMPER_EXPECT_TRUE( bool4x4_cmpe( &test7,  &allTrue ) );
	TEMPER_EXPECT_TRUE( bool4x4_cmpe( &test8,  &allTrue ) );
	TEMPER_EXPECT_TRUE( bool4x4_cmpe( &test9,  &allTrue ) );

	TEMPER_EXPECT_TRUE( bool4x4_cmpe( &test10, &allTrue ) );
	TEMPER_EXPECT_TRUE( bool4x4_cmpe( &test11, &allTrue ) );
	TEMPER_EXPECT_TRUE( bool4x4_cmpe( &test12, &allTrue ) );
	TEMPER_EXPECT_TRUE( bool4x4_cmpe( &test13, &allTrue ) );
	TEMPER_EXPECT_TRUE( bool4x4_cmpe( &test14, &allTrue ) );

	TEMPER_EXPECT_TRUE( bool4x4_cmpe( &test15, &allTrue ) );
	TEMPER_EXPECT_TRUE( bool4x4_cmpe( &test16, &allTrue ) );
	TEMPER_EXPECT_TRUE( bool4x4_cmpe( &test17, &allTrue ) );
	TEMPER_EXPECT_TRUE( bool4x4_cmpe( &test18, &allTrue ) );
	TEMPER_EXPECT_TRUE( bool4x4_cmpe( &test19, &allTrue ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestIdentity_Scalar_double4x4 )
{
	double4x4 id;
	id.rows[0] = (double4) { 1.000000, 0.000000, 0.000000, 0.000000 };
	id.rows[1] = (double4) { 0.000000, 1.000000, 0.000000, 0.000000 };
	id.rows[2] = (double4) { 0.000000, 0.000000, 1.000000, 0.000000 };
	id.rows[3] = (double4) { 0.000000, 0.000000, 0.000000, 1.000000 };

	double4x4 mat;
	double4x4_identity( &mat );
	TEMPER_EXPECT_TRUE( double4x4_cmpe( &mat, &id ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestTranspose_Scalar_double4x4 )
{
	double4x4 answerTransposed = (double4x4) {
		0.000000, 4.000000, 8.000000, 12.000000,
		1.000000, 5.000000, 9.000000, 13.000000,
		2.000000, 6.000000, 10.000000, 14.000000,
		3.000000, 7.000000, 11.000000, 15.000000
	};

	double4x4 mat = (double4x4) {
		0.000000, 1.000000, 2.000000, 3.000000,
		4.000000, 5.000000, 6.000000, 7.000000,
		8.000000, 9.000000, 10.000000, 11.000000,
		12.000000, 13.000000, 14.000000, 15.000000
	};
	double4x4 trans = double4x4_transpose( &mat );

	TEMPER_EXPECT_TRUE( double4x4_cmpe( &trans, &answerTransposed ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestDeterminant_Scalar_double4x4 )
{
	double4x4 mat = (double4x4) {
		6.000000, 2.000000, 3.000000, 4.000000,
		2.000000, 7.000000, 5.000000, 3.000000,
		3.000000, 5.000000, 7.000000, 2.000000,
		4.000000, 3.000000, 2.000000, 6.000000
	};
	double det = double4x4_determinant( &mat );

	TEMPER_EXPECT_TRUE( doubleeq( det, 285.0 ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestInverse_Scalar_double4x4 )
{
	double4x4 id;
	double4x4_identity( &id );

	double4x4 mat = (double4x4) {
		1.000000, 0.000000, 0.000000, 1.000000,
		0.000000, 2.000000, 1.000000, 2.000000,
		2.000000, 1.000000, 0.000000, 1.000000,
		2.000000, 0.000000, 1.000000, 4.000000
	};
	double4x4 matInverse = double4x4_inverse( &mat );

	double4x4 shouldBeIdentity = double4x4_mulm( &mat, &matInverse );

	TEMPER_EXPECT_TRUE( double4x4_cmpe( &shouldBeIdentity, &id ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestTranslate_Scalar_double4x4 )
{
	double4x4 mat;
	double4x4_identity( &mat );

	double3 translation = { 2.000000, 3.000000, 4.000000 };
	mat = double4x4_translate( &mat, &translation );

	TEMPER_EXPECT_TRUE( doubleeq( mat.rows[0].w, 2.0 ) );
	TEMPER_EXPECT_TRUE( doubleeq( mat.rows[1].w, 3.0 ) );
	TEMPER_EXPECT_TRUE( doubleeq( mat.rows[2].w, 4.0 ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestRotate_double4x4 )
{
	double4x4 mat;
	double4x4_identity( &mat );

	double3 rollVec = { 0.000000, 0.000000, 1.000000 };
	double4x4 roll = double4x4_rotate( &mat, radians( 45.0 ), &rollVec );
	double4x4 answerRoll = (double4x4) {
		0.707107, -0.707107, 0.000000, 0.000000,
		0.707107, 0.707107, 0.000000, 0.000000,
		0.000000, 0.000000, 1.000000, 0.000000,
		0.000000, 0.000000, 0.000000, 1.000000
	};
	TEMPER_EXPECT_TRUE( double4x4_cmpe( &roll, &answerRoll ) );

	double4x4_identity( &mat ); // reset the matrix
	double3 yawVec = { 0.000000, 1.000000, 0.000000 };
	double4x4 yaw = double4x4_rotate( &mat, radians( 45.0 ), &yawVec );
	double4x4 answerYaw = (double4x4) {
		0.707107, 0.000000, 0.707107, 0.000000,
		0.000000, 1.000000, 0.000000, 0.000000,
		-0.707107, 0.000000, 0.707107, 0.000000,
		0.000000, 0.000000, 0.000000, 1.000000
	};
	TEMPER_EXPECT_TRUE( double4x4_cmpe( &yaw, &answerYaw ) );

	double4x4_identity( &mat ); // reset the matrix
	double3 pitchVec = { 1.000000, 0.000000, 0.000000 };
	double4x4 pitch = double4x4_rotate( &mat, radians( 45.0 ), &pitchVec );
	double4x4 answerPitch = (double4x4) {
		1.000000, 0.000000, 0.000000, 0.000000,
		0.000000, 0.707107, -0.707107, 0.000000,
		0.000000, 0.707107, 0.707107, 0.000000,
		0.000000, 0.000000, 0.000000, 1.000000
	};
	TEMPER_EXPECT_TRUE( double4x4_cmpe( &pitch, &answerPitch ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestScale_Scalar_double4x4 )
{
	double3 scaleVec = { 2.000000, 2.000000, 2.000000 };
	double4x4 mat;
	double4x4_identity( &mat );

	double4x4 scaled = double4x4_scale( &mat, &scaleVec );

	TEMPER_EXPECT_TRUE( doubleeq( scaled.rows[0].x, 2.000000 ) );
	TEMPER_EXPECT_TRUE( doubleeq( scaled.rows[1].y, 2.000000 ) );
	TEMPER_EXPECT_TRUE( doubleeq( scaled.rows[2].z, 2.000000 ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestOrtho_double4x4 )
{
	double4x4 answerOrtho_LH_ZO = (double4x4) {
		0.112500, 0.000000, 0.000000, 0.000000,
		0.000000, -0.200000, 0.000000, 0.000000,
		0.000000, 0.000000, 0.009901, 0.009901,
		0.000000, 0.000000, 0.000000, 1.000000
	};
	double4x4 answerOrtho_LH_NO = (double4x4) {
		0.112500, 0.000000, 0.000000, -0.000000,
		0.000000, -0.200000, 0.000000, 0.000000,
		0.000000, 0.000000, 0.019802, -0.980198,
		0.000000, 0.000000, 0.000000, 1.000000
	};
	double4x4 answerOrtho_RH_ZO = (double4x4) {
		0.112500, 0.000000, 0.000000, -0.000000,
		0.000000, -0.200000, 0.000000, 0.000000,
		0.000000, 0.000000, -0.009901, 0.009901,
		0.000000, 0.000000, 0.000000, 1.000000
	};
	double4x4 answerOrtho_RH_NO = (double4x4) {
		0.112500, 0.000000, 0.000000, -0.000000,
		0.000000, -0.200000, 0.000000, 0.000000,
		0.000000, 0.000000, -0.019802, -0.980198,
		0.000000, 0.000000, 0.000000, 1.000000
	};

	double width     = 1280.0;
	double height    = 720.0;
	double aspect    = width / height;
	double orthoSize = 5.0;

	double left   = -aspect * orthoSize;
	double right  =  aspect * orthoSize;
	double top    = -orthoSize;
	double bottom =  orthoSize;

	double4x4 mat_LH_ZO = double4x4_ortho_lh_zo( left, right, top, bottom, -1.0, 100.0 );
	double4x4 mat_LH_NO = double4x4_ortho_lh_no( left, right, top, bottom, -1.0, 100.0 );
	double4x4 mat_RH_ZO = double4x4_ortho_rh_zo( left, right, top, bottom, -1.0, 100.0 );
	double4x4 mat_RH_NO = double4x4_ortho_rh_no( left, right, top, bottom, -1.0, 100.0 );

	TEMPER_EXPECT_TRUE( double4x4_cmpe( &mat_LH_ZO, &answerOrtho_LH_ZO ) );
	TEMPER_EXPECT_TRUE( double4x4_cmpe( &mat_LH_NO, &answerOrtho_LH_NO ) );
	TEMPER_EXPECT_TRUE( double4x4_cmpe( &mat_RH_ZO, &answerOrtho_RH_ZO ) );
	TEMPER_EXPECT_TRUE( double4x4_cmpe( &mat_RH_NO, &answerOrtho_RH_NO ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestPerspective_double4x4 )
{
	double4x4 answerPerspective_LH_ZO = (double4x4) {
		0.347270, 0.000000, 0.000000, 0.000000,
		0.000000, 0.617370, 0.000000, 0.000000,
		0.000000, 0.000000, 1.001001, -0.100100,
		0.000000, 0.000000, 1.000000, 0.000000
	};
	double4x4 answerPerspective_LH_NO = (double4x4) {
		0.347270, 0.000000, 0.000000, 0.000000,
		0.000000, 0.617370, 0.000000, 0.000000,
		0.000000, 0.000000, 1.002002, -0.200200,
		0.000000, 0.000000, 1.000000, 0.000000
	};
	double4x4 answerPerspective_RH_ZO = (double4x4) {
		0.347270, 0.000000, 0.000000, 0.000000,
		0.000000, 0.617370, 0.000000, 0.000000,
		0.000000, 0.000000, -1.001001, -0.100100,
		0.000000, 0.000000, -1.000000, 0.000000
	};
	double4x4 answerPerspective_RH_NO = (double4x4) {
		0.347270, 0.000000, 0.000000, 0.000000,
		0.000000, 0.617370, 0.000000, 0.000000,
		0.000000, 0.000000, -1.002002, -0.200200,
		0.000000, 0.000000, -1.000000, 0.000000
	};

	double aspect = 1280.0 / 720.0;

	double4x4 mat_LH_ZO = double4x4_perspective_lh_zo( 90.0, aspect, 0.1, 100.0 );
	double4x4 mat_LH_NO = double4x4_perspective_lh_no( 90.0, aspect, 0.1, 100.0 );
	double4x4 mat_RH_ZO = double4x4_perspective_rh_zo( 90.0, aspect, 0.1, 100.0 );
	double4x4 mat_RH_NO = double4x4_perspective_rh_no( 90.0, aspect, 0.1, 100.0 );

	TEMPER_EXPECT_TRUE( double4x4_cmpe( &mat_LH_ZO, &answerPerspective_LH_ZO ) );
	TEMPER_EXPECT_TRUE( double4x4_cmpe( &mat_LH_NO, &answerPerspective_LH_NO ) );
	TEMPER_EXPECT_TRUE( double4x4_cmpe( &mat_RH_ZO, &answerPerspective_RH_ZO ) );
	TEMPER_EXPECT_TRUE( double4x4_cmpe( &mat_RH_NO, &answerPerspective_RH_NO ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestLookAt_double4x4 )
{
	double4x4 answerLookAt_LH = (double4x4) {
		0.707107, 0.000000, -0.707107, 0.000000,
		0.000000, 1.000000, 0.000000, 0.000000,
		0.707107, 0.000000, 0.707107, 0.000000,
		0.000000, 0.000000, 0.000000, 1.000000
	};
	double4x4 answerLookAt_RH = (double4x4) {
		-0.707107, 0.000000, 0.707107, 0.000000,
		0.000000, 1.000000, 0.000000, 0.000000,
		-0.707107, 0.000000, -0.707107, 0.000000,
		0.000000, 0.000000, 0.000000, 1.000000
	};

	double3 currentPos = { 0.000000, 0.000000, 0.000000 };
	double3 targetPos = { 1.000000, 0.000000, 1.000000 };
	double3 up = { 0.000000, 1.000000, 0.000000 };

	double4x4 mat_LH = double4x4_lookat_lh( &currentPos, &targetPos, &up );
	double4x4 mat_RH = double4x4_lookat_rh( &currentPos, &targetPos, &up );

	TEMPER_EXPECT_TRUE( double4x4_cmpe( &mat_LH, &answerLookAt_LH ) );
	TEMPER_EXPECT_TRUE( double4x4_cmpe( &mat_RH, &answerLookAt_RH ) );

	TEMPER_PASS();
}

TEMPER_SUITE( Test_double4x4 )
{
	TEMPER_RUN_TEST( TestAssignment_double4x4 );
	TEMPER_RUN_TEST( TestComponentWiseArithmetic_Scalar_Addition_double4x4 );
	TEMPER_RUN_TEST( TestComponentWiseArithmetic_Scalar_Subtraction_double4x4 );
	TEMPER_RUN_TEST( TestComponentWiseArithmetic_Scalar_Multiplication_double4x4 );
	TEMPER_RUN_TEST( TestComponentWiseArithmetic_Scalar_Division_double4x4 );
	TEMPER_RUN_TEST( TestMultiplyMatrix_Scalar_double4x4 );
	TEMPER_RUN_TEST( TestMultiplyVector_double4x4 );
	TEMPER_RUN_TEST( TestRelational_double4x4 );
	TEMPER_RUN_TEST( TestIdentity_Scalar_double4x4 );
	TEMPER_RUN_TEST( TestTranspose_Scalar_double4x4 );
	TEMPER_RUN_TEST( TestDeterminant_Scalar_double4x4 );
	TEMPER_RUN_TEST( TestInverse_Scalar_double4x4 );
	TEMPER_RUN_TEST( TestTranslate_Scalar_double4x4 );
	TEMPER_RUN_TEST( TestRotate_double4x4 );
	TEMPER_RUN_TEST( TestScale_Scalar_double4x4 );
	TEMPER_RUN_TEST( TestOrtho_double4x4 );
	TEMPER_RUN_TEST( TestPerspective_double4x4 );
	TEMPER_RUN_TEST( TestLookAt_double4x4 );
}

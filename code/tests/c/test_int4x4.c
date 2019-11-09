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

static int4x4 g_matrixMulLHS_int4x4    = (int4x4) {
		6, 6, 6, 6,
		6, 6, 6, 6,
		12, 12, 12, 12,
		18, 18, 18, 18
};

static int4x4 g_matrixMulRHS_int4x4    = (int4x4) {
		1, 1, 1, 1,
		2, 2, 2, 2,
		3, 3, 3, 3,
		6, 6, 6, 6
};

static int4x4 g_matrixMulAnswer_int4x4 = (int4x4) {
		72, 72, 72, 72,
		72, 72, 72, 72,
		144, 144, 144, 144,
		216, 216, 216, 216
};


TEMPER_TEST( TestAssignment_int4x4 )
{
	int4x4 mat;

	mat.rows[0] = (int4) { 999, 0, 0, 0 };
	mat.rows[1] = (int4) { 0, 999, 0, 0 };
	mat.rows[2] = (int4) { 0, 0, 999, 0 };
	mat.rows[3] = (int4) { 0, 0, 0, 999 };

	TEMPER_EXPECT_TRUE( mat.rows[0].x == 999 );
	TEMPER_EXPECT_TRUE( mat.rows[0].y == 0 );
	TEMPER_EXPECT_TRUE( mat.rows[0].z == 0 );
	TEMPER_EXPECT_TRUE( mat.rows[0].w == 0 );
	TEMPER_EXPECT_TRUE( mat.rows[1].x == 0 );
	TEMPER_EXPECT_TRUE( mat.rows[1].y == 999 );
	TEMPER_EXPECT_TRUE( mat.rows[1].z == 0 );
	TEMPER_EXPECT_TRUE( mat.rows[1].w == 0 );
	TEMPER_EXPECT_TRUE( mat.rows[2].x == 0 );
	TEMPER_EXPECT_TRUE( mat.rows[2].y == 0 );
	TEMPER_EXPECT_TRUE( mat.rows[2].z == 999 );
	TEMPER_EXPECT_TRUE( mat.rows[2].w == 0 );
	TEMPER_EXPECT_TRUE( mat.rows[3].x == 0 );
	TEMPER_EXPECT_TRUE( mat.rows[3].y == 0 );
	TEMPER_EXPECT_TRUE( mat.rows[3].z == 0 );
	TEMPER_EXPECT_TRUE( mat.rows[3].w == 999 );

	TEMPER_PASS();
}

TEMPER_TEST( TestComponentWiseArithmetic_Scalar_Addition_int4x4 )
{
	int4x4 answer = (int4x4) {
		7, 7, 7, 7,
		8, 8, 8, 8,
		15, 15, 15, 15,
		24, 24, 24, 24
	};

	int4x4 a = (int4x4) {
		6, 6, 6, 6,
		6, 6, 6, 6,
		12, 12, 12, 12,
		18, 18, 18, 18
	};

	int4x4 b = (int4x4) {
		1, 1, 1, 1,
		2, 2, 2, 2,
		3, 3, 3, 3,
		6, 6, 6, 6
	};

	int4x4 c = int4x4_comp_addm( &a, &b );

	TEMPER_EXPECT_TRUE( int4x4_cmpe( &c, &answer ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestComponentWiseArithmetic_Scalar_Subtraction_int4x4 )
{
	int4x4 answer = (int4x4) {
		5, 5, 5, 5,
		4, 4, 4, 4,
		9, 9, 9, 9,
		12, 12, 12, 12
	};

	int4x4 a = (int4x4) {
		6, 6, 6, 6,
		6, 6, 6, 6,
		12, 12, 12, 12,
		18, 18, 18, 18
	};

	int4x4 b = (int4x4) {
		1, 1, 1, 1,
		2, 2, 2, 2,
		3, 3, 3, 3,
		6, 6, 6, 6
	};

	int4x4 c = int4x4_comp_subm( &a, &b );

	TEMPER_EXPECT_TRUE( int4x4_cmpe( &c, &answer ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestComponentWiseArithmetic_Scalar_Multiplication_int4x4 )
{
	int4x4 answer = (int4x4) {
		6, 6, 6, 6,
		12, 12, 12, 12,
		36, 36, 36, 36,
		108, 108, 108, 108
	};

	int4x4 a = (int4x4) {
		6, 6, 6, 6,
		6, 6, 6, 6,
		12, 12, 12, 12,
		18, 18, 18, 18
	};

	int4x4 b = (int4x4) {
		1, 1, 1, 1,
		2, 2, 2, 2,
		3, 3, 3, 3,
		6, 6, 6, 6
	};

	int4x4 c = int4x4_comp_mulm( &a, &b );

	TEMPER_EXPECT_TRUE( int4x4_cmpe( &c, &answer ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestComponentWiseArithmetic_Scalar_Division_int4x4 )
{
	int4x4 answer = (int4x4) {
		6, 6, 6, 6,
		3, 3, 3, 3,
		4, 4, 4, 4,
		3, 3, 3, 3
	};

	int4x4 a = (int4x4) {
		6, 6, 6, 6,
		6, 6, 6, 6,
		12, 12, 12, 12,
		18, 18, 18, 18
	};

	int4x4 b = (int4x4) {
		1, 1, 1, 1,
		2, 2, 2, 2,
		3, 3, 3, 3,
		6, 6, 6, 6
	};

	int4x4 c = int4x4_comp_divm( &a, &b );

	TEMPER_EXPECT_TRUE( int4x4_cmpe( &c, &answer ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestMultiplyMatrix_Scalar_int4x4 )
{
	int4x4 answer = g_matrixMulAnswer_int4x4;

	int4x4 a = g_matrixMulLHS_int4x4;
	int4x4 b = g_matrixMulRHS_int4x4;
	int4x4 c = int4x4_mulm( &a, &b );

	TEMPER_EXPECT_TRUE( int4x4_cmpe( &c, &answer ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestMultiplyVector_int4x4 )
{
	int4 answerVec = { 28, 68, 108, 148 };

	int4x4 a = (int4x4) {
		1, 2, 3, 4,
		5, 6, 7, 8,
		9, 10, 11, 12,
		13, 14, 15, 16
	};
	int4 b = { 2, 1, 4, 3 };
	int4 c = int4x4_mulv( &a, &b );

	TEMPER_EXPECT_TRUE( int4_cmpe( &c, &answerVec ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestRelational_int4x4 )
{
	bool4x4 allTrue = { 		true, true, true, true,
		true, true, true, true,
		true, true, true, true,
		true, true, true, true
 };

	int4x4 mat0 = (int4x4) { 		1, 1, 1, 1,
		1, 1, 1, 1,
		1, 1, 1, 1,
		1, 1, 1, 1
 };
	int4x4 mat1 = (int4x4) { 		2, 2, 2, 2,
		2, 2, 2, 2,
		2, 2, 2, 2,
		2, 2, 2, 2
 };
	int4x4 mat2 = (int4x4) { 		3, 3, 3, 3,
		3, 3, 3, 3,
		3, 3, 3, 3,
		3, 3, 3, 3
 };
	int4x4 mat3 = (int4x4) { 		4, 4, 4, 4,
		4, 4, 4, 4,
		4, 4, 4, 4,
		4, 4, 4, 4
 };

	bool4x4 test0  = int4x4_cmple( &mat0, &mat0 );
	bool4x4 test1  = int4x4_cmpge( &mat0, &mat0 );
	bool4x4 test2  = int4x4_cmpl( &mat0, &mat1 );
	bool4x4 test3  = int4x4_cmpl( &mat0, &mat2 );
	bool4x4 test4  = int4x4_cmpl( &mat0, &mat3 );

	bool4x4 test5  = int4x4_cmpg( &mat1, &mat0 );
	bool4x4 test6  = int4x4_cmple( &mat1, &mat1 );
	bool4x4 test7  = int4x4_cmpge( &mat1, &mat1 );
	bool4x4 test8  = int4x4_cmpl( &mat1, &mat2 );
	bool4x4 test9  = int4x4_cmpl( &mat1, &mat3 );

	bool4x4 test10 = int4x4_cmpg( &mat2, &mat0 );
	bool4x4 test11 = int4x4_cmpg( &mat2, &mat1 );
	bool4x4 test12 = int4x4_cmple( &mat2, &mat2 );
	bool4x4 test13 = int4x4_cmpge( &mat2, &mat2 );
	bool4x4 test14 = int4x4_cmpl( &mat2, &mat3 );

	bool4x4 test15 = int4x4_cmpg( &mat3, &mat0 );
	bool4x4 test16 = int4x4_cmpg( &mat3, &mat1 );
	bool4x4 test17 = int4x4_cmpg( &mat3, &mat2 );
	bool4x4 test18 = int4x4_cmple( &mat3, &mat3 );
	bool4x4 test19 = int4x4_cmpge( &mat3, &mat3 );

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

TEMPER_TEST( TestBitwise_And_int4x4 )
{
	int4x4 answer  = (int4x4) {
		5, 5, 5, 5,
		5, 5, 5, 5,
		5, 5, 5, 5,
		5, 5, 5, 5
	};
	int4x4 a = (int4x4) {
		21, 21, 21, 21,
		21, 21, 21, 21,
		21, 21, 21, 21,
		21, 21, 21, 21
	};
	int4x4 b = (int4x4) {
		7, 7, 7, 7,
		7, 7, 7, 7,
		7, 7, 7, 7,
		7, 7, 7, 7
	};
	int4x4 c = int4x4_comp_and( &a, &b );

	TEMPER_EXPECT_TRUE( int4x4_cmpe( &c, &answer ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestBitwise_Or_int4x4 )
{
	int4x4 answer  = (int4x4) {
		23, 23, 23, 23,
		23, 23, 23, 23,
		23, 23, 23, 23,
		23, 23, 23, 23
	};
	int4x4 a = (int4x4) {
		21, 21, 21, 21,
		21, 21, 21, 21,
		21, 21, 21, 21,
		21, 21, 21, 21
	};
	int4x4 b = (int4x4) {
		7, 7, 7, 7,
		7, 7, 7, 7,
		7, 7, 7, 7,
		7, 7, 7, 7
	};
	int4x4 c = int4x4_comp_or( &a, &b );

	TEMPER_EXPECT_TRUE( int4x4_cmpe( &c, &answer ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestBitwise_Xor_int4x4 )
{
	int4x4 answer  = (int4x4) {
		18, 18, 18, 18,
		18, 18, 18, 18,
		18, 18, 18, 18,
		18, 18, 18, 18
	};
	int4x4 a = (int4x4) {
		21, 21, 21, 21,
		21, 21, 21, 21,
		21, 21, 21, 21,
		21, 21, 21, 21
	};
	int4x4 b = (int4x4) {
		7, 7, 7, 7,
		7, 7, 7, 7,
		7, 7, 7, 7,
		7, 7, 7, 7
	};
	int4x4 c = int4x4_comp_xor( &a, &b );

	TEMPER_EXPECT_TRUE( int4x4_cmpe( &c, &answer ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestBitwise_ShiftLeft_int4x4 )
{
	int4x4 answer  = (int4x4) {
		4, 4, 4, 4,
		4, 4, 4, 4,
		4, 4, 4, 4,
		4, 4, 4, 4
	};
	int4x4 a = (int4x4) {
		1, 1, 1, 1,
		1, 1, 1, 1,
		1, 1, 1, 1,
		1, 1, 1, 1
	};
	int4x4 b = (int4x4) {
		2, 2, 2, 2,
		2, 2, 2, 2,
		2, 2, 2, 2,
		2, 2, 2, 2
	};
	int4x4 c = int4x4_comp_shift_left( &a, &b );

	TEMPER_EXPECT_TRUE( int4x4_cmpe( &c, &answer ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestBitwise_ShiftRight_int4x4 )
{
	int4x4 answer  = (int4x4) {
		1, 1, 1, 1,
		1, 1, 1, 1,
		1, 1, 1, 1,
		1, 1, 1, 1
	};
	int4x4 a = (int4x4) {
		16, 16, 16, 16,
		16, 16, 16, 16,
		16, 16, 16, 16,
		16, 16, 16, 16
	};
	int4x4 b = (int4x4) {
		4, 4, 4, 4,
		4, 4, 4, 4,
		4, 4, 4, 4,
		4, 4, 4, 4
	};
	int4x4 c = int4x4_comp_shift_right( &a, &b );

	TEMPER_EXPECT_TRUE( int4x4_cmpe( &c, &answer ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestBitwise_Unary_int4x4 )
{
	int4x4 answer = (int4x4) {
		(int32_t) -1, (int32_t) -1, (int32_t) -1, (int32_t) -1,
		(int32_t) -1, (int32_t) -1, (int32_t) -1, (int32_t) -1,
		(int32_t) -1, (int32_t) -1, (int32_t) -1, (int32_t) -1,
		(int32_t) -1, (int32_t) -1, (int32_t) -1, (int32_t) -1
	};
	int4x4 a = (int4x4) {
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0
	};

	int4x4 b = int4x4_comp_unary( &a );

	TEMPER_EXPECT_TRUE( int4x4_cmpe( &b, &answer ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestIdentity_Scalar_int4x4 )
{
	int4x4 id;
	id.rows[0] = (int4) { 1, 0, 0, 0 };
	id.rows[1] = (int4) { 0, 1, 0, 0 };
	id.rows[2] = (int4) { 0, 0, 1, 0 };
	id.rows[3] = (int4) { 0, 0, 0, 1 };

	int4x4 mat;
	int4x4_identity( &mat );
	TEMPER_EXPECT_TRUE( int4x4_cmpe( &mat, &id ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestTranspose_Scalar_int4x4 )
{
	int4x4 answerTransposed = (int4x4) {
		0, 4, 8, 12,
		1, 5, 9, 13,
		2, 6, 10, 14,
		3, 7, 11, 15
	};

	int4x4 mat = (int4x4) {
		0, 1, 2, 3,
		4, 5, 6, 7,
		8, 9, 10, 11,
		12, 13, 14, 15
	};
	int4x4 trans = int4x4_transpose( &mat );

	TEMPER_EXPECT_TRUE( int4x4_cmpe( &trans, &answerTransposed ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestDeterminant_Scalar_int4x4 )
{
	int4x4 mat = (int4x4) {
		6, 2, 3, 4,
		2, 7, 5, 3,
		3, 5, 7, 2,
		4, 3, 2, 6
	};
	int32_t det = int4x4_determinant( &mat );

	TEMPER_EXPECT_TRUE( det == 285 );

	TEMPER_PASS();
}

TEMPER_TEST( TestTranslate_Scalar_int4x4 )
{
	int4x4 mat;
	int4x4_identity( &mat );

	int3 translation = { 2, 3, 4 };
	mat = int4x4_translate( &mat, &translation );

	TEMPER_EXPECT_TRUE( mat.rows[0].w == 2 );
	TEMPER_EXPECT_TRUE( mat.rows[1].w == 3 );
	TEMPER_EXPECT_TRUE( mat.rows[2].w == 4 );

	TEMPER_PASS();
}

TEMPER_TEST( TestScale_Scalar_int4x4 )
{
	int3 scaleVec = { 2, 2, 2 };
	int4x4 mat;
	int4x4_identity( &mat );

	int4x4 scaled = int4x4_scale( &mat, &scaleVec );

	TEMPER_EXPECT_TRUE( scaled.rows[0].x == 2 );
	TEMPER_EXPECT_TRUE( scaled.rows[1].y == 2 );
	TEMPER_EXPECT_TRUE( scaled.rows[2].z == 2 );

	TEMPER_PASS();
}

TEMPER_SUITE( Test_int4x4 )
{
	TEMPER_RUN_TEST( TestAssignment_int4x4 );
	TEMPER_RUN_TEST( TestComponentWiseArithmetic_Scalar_Addition_int4x4 );
	TEMPER_RUN_TEST( TestComponentWiseArithmetic_Scalar_Subtraction_int4x4 );
	TEMPER_RUN_TEST( TestComponentWiseArithmetic_Scalar_Multiplication_int4x4 );
	TEMPER_RUN_TEST( TestComponentWiseArithmetic_Scalar_Division_int4x4 );
	TEMPER_RUN_TEST( TestMultiplyMatrix_Scalar_int4x4 );
	TEMPER_RUN_TEST( TestMultiplyVector_int4x4 );
	TEMPER_RUN_TEST( TestRelational_int4x4 );
	TEMPER_RUN_TEST( TestBitwise_And_int4x4 );
	TEMPER_RUN_TEST( TestBitwise_Or_int4x4 );
	TEMPER_RUN_TEST( TestBitwise_Xor_int4x4 );
	TEMPER_RUN_TEST( TestBitwise_ShiftLeft_int4x4 );
	TEMPER_RUN_TEST( TestBitwise_ShiftRight_int4x4 );
	TEMPER_RUN_TEST( TestBitwise_Unary_int4x4 );
	TEMPER_RUN_TEST( TestIdentity_Scalar_int4x4 );
	TEMPER_RUN_TEST( TestTranspose_Scalar_int4x4 );
	TEMPER_RUN_TEST( TestDeterminant_Scalar_int4x4 );
	TEMPER_RUN_TEST( TestTranslate_Scalar_int4x4 );
	TEMPER_RUN_TEST( TestScale_Scalar_int4x4 );
}
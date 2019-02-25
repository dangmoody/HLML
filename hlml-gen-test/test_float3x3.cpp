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

#include "../out/gen/hlml_functions_matrix.h"

#include <temper.h>

TEMPER_TEST( TestAssignment_float3x3 ) {
	float3x3 mat;

	// fill single value
	mat = float3x3( 999.0f );
	TEMPER_EXPECT_TRUE( mat[0] == float3( 999.0f, 0.0f, 0.0f ) );
	TEMPER_EXPECT_TRUE( mat[1] == float3( 0.0f, 999.0f, 0.0f ) );
	TEMPER_EXPECT_TRUE( mat[2] == float3( 0.0f, 0.0f, 999.0f ) );

	// row filling
	mat = float3x3(
		float3( 0, 1, 2 ),
		float3( 3, 4, 5 ),
		float3( 6, 7, 8 )
	);
	TEMPER_EXPECT_TRUE( mat[0] == float3( 0, 1, 2 ) );
	TEMPER_EXPECT_TRUE( mat[1] == float3( 3, 4, 5 ) );
	TEMPER_EXPECT_TRUE( mat[2] == float3( 6, 7, 8 ) );

	// all values filled
	mat = float3x3(
		9, 8, 7, 
		6, 5, 4, 
		3, 2, 1
	);
	TEMPER_EXPECT_TRUE( mat[0] == float3( 9, 8, 7 ) );
	TEMPER_EXPECT_TRUE( mat[1] == float3( 6, 5, 4 ) );
	TEMPER_EXPECT_TRUE( mat[2] == float3( 3, 2, 1 ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticAddition_float3x3 ) {
	float3x3 a = float3x3(
		6.0f, 6.0f, 6.0f, 
		6.0f, 6.0f, 6.0f, 
		6.0f,6.0f,6.0f
	);
	float3x3 b = float3x3(
		2.0f, 3.0f, 4.0f,
		6.0f, 6.0f, 8.0f,
		10.0f, 10.0f, 12.0f
	);
	float3x3 c = a + b;

	TEMPER_EXPECT_TRUE( c == float3x3(
		8.0f, 9.0f, 10.0f,
		12.0f, 12.0f, 14.0f,
		16.0f, 16.0f, 18.0f
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticSubtraction_float3x3 ) {
	float3x3 a = float3x3(
		6.0f, 6.0f, 6.0f, 
		6.0f, 6.0f, 6.0f, 
		6.0f,6.0f,6.0f
	);
	float3x3 b = float3x3(
		2.0f, 3.0f, 4.0f,
		6.0f, 6.0f, 8.0f,
		10.0f, 10.0f, 12.0f
	);
	float3x3 c = a - b;

	TEMPER_EXPECT_TRUE( c == float3x3(
		4.0f, 3.0f, 2.0f,
		0.0f, 0.0f, -2.0f,
		-4.0f, -4.0f, -6.0f
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticMultiplication_float3x3 ) {
	float3x3 a = float3x3(
		6.0f, 6.0f, 6.0f, 
		6.0f, 6.0f, 6.0f, 
		6.0f,6.0f,6.0f
	);
	float3x3 b = float3x3(
		2.0f, 3.0f, 4.0f,
		6.0f, 6.0f, 8.0f,
		10.0f, 10.0f, 12.0f
	);
	float3x3 c = a * b;

	TEMPER_EXPECT_TRUE( c == float3x3(
		0.0f, 1.0f, 2.0f,
		1.0f, 2.0f, 3.0f,
		2.0f, 3.0f, 4.0f
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticDivision_float3x3 ) {
	float3x3 a = float3x3(
		2.0f, 3.0f, 4.0f,
		6.0f, 6.0f, 8.0f,
		10.0f, 10.0f, 12.0f
	);
	float3x3 b = a / a;
	float3x3 identity = float3x3(
		1.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 1.0f
	);

	TEMPER_EXPECT_TRUE( b == identity );

	TEMPER_PASS();
}

TEMPER_TEST( TestArray_float3x3 ) {
	float3x3 mat;

	TEMPER_EXPECT_TRUE( mat[0] == float3( 1.0f, 0.0f, 0.0f ) );
	TEMPER_EXPECT_TRUE( mat[1] == float3( 0.0f, 1.0f, 0.0f ) );
	TEMPER_EXPECT_TRUE( mat[2] == float3( 0.0f, 0.0f, 1.0f ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestRelational_float3x3 ) {
	float3x3 mat0 = float3x3(
		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f
	);
	float3x3 mat1 = float3x3(
		2.0f, 2.0f, 2.0f,
		2.0f, 2.0f, 2.0f,
		2.0f, 2.0f, 2.0f
	);
	float3x3 mat2 = float3x3(
		3.0f, 3.0f, 3.0f,
		3.0f, 3.0f, 3.0f,
		3.0f, 3.0f, 3.0f
	);
	float3x3 mat3 = float3x3(
		4.0f, 4.0f, 4.0f,
		4.0f, 4.0f, 4.0f,
		4.0f, 4.0f, 4.0f
	);

	bool3x3 test0 = mat0 <= mat0;
	bool3x3 test1 = mat0 >= mat0;
	bool3x3 test2 = mat0 < mat1;

	bool3x3 test3 = mat1 <= mat1;
	bool3x3 test4 = mat1 >= mat1;
	bool3x3 test5 = mat1 < mat2;
	bool3x3 test6 = mat1 > mat0;

	bool3x3 test7 = mat2 <= mat2;
	bool3x3 test8 = mat2 >= mat2;
	bool3x3 test9 = mat2 < mat3;
	bool3x3 test10 = mat2 > mat1;

	bool3x3 test11 = mat3 <= mat3;
	bool3x3 test12 = mat3 >= mat3;
	bool3x3 test13 = mat3 > mat2;

	TEMPER_EXPECT_TRUE( test0 == bool3x3(
		true, true, true,
		true, true, true,
		true, true, true
	) );

	TEMPER_EXPECT_TRUE( test1 == bool3x3(
		true, true, true,
		true, true, true,
		true, true, true
	) );

	TEMPER_EXPECT_TRUE( test2 == bool3x3(
		true, true, true,
		true, true, true,
		true, true, true
	) );

	TEMPER_EXPECT_TRUE( test3 == bool3x3(
		true, true, true,
		true, true, true,
		true, true, true
	) );

	TEMPER_EXPECT_TRUE( test4 == bool3x3(
		true, true, true,
		true, true, true,
		true, true, true
	) );

	TEMPER_EXPECT_TRUE( test5 == bool3x3(
		true, true, true,
		true, true, true,
		true, true, true
	) );

	TEMPER_EXPECT_TRUE( test6 == bool3x3(
		true, true, true,
		true, true, true,
		true, true, true
	) );

	TEMPER_EXPECT_TRUE( test7 == bool3x3(
		true, true, true,
		true, true, true,
		true, true, true
	) );

	TEMPER_EXPECT_TRUE( test8 == bool3x3(
		true, true, true,
		true, true, true,
		true, true, true
	) );

	TEMPER_EXPECT_TRUE( test9 == bool3x3(
		true, true, true,
		true, true, true,
		true, true, true
	) );

	TEMPER_EXPECT_TRUE( test10 == bool3x3(
		true, true, true,
		true, true, true,
		true, true, true
	) );

	TEMPER_EXPECT_TRUE( test11 == bool3x3(
		true, true, true,
		true, true, true,
		true, true, true
	) );

	TEMPER_EXPECT_TRUE( test12 == bool3x3(
		true, true, true,
		true, true, true,
		true, true, true
	) );

	TEMPER_EXPECT_TRUE( test13 == bool3x3(
		true, true, true,
		true, true, true,
		true, true, true
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestIdentity_float3x3 ) {
	float3x3 id = float3x3(
		1.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 1.0f
	);

	float3x3 mat;
	TEMPER_EXPECT_TRUE( mat == id );

	identity( mat );
	TEMPER_EXPECT_TRUE( mat == id );

	TEMPER_PASS();
}

TEMPER_TEST( TestTranspose_float3x3 ) {
	float3x3 mat = float3x3(
		0.0f, 1.0f, 2.0f,
		3.0f, 4.0f, 5.0f,
		6.0f, 7.0f, 8.0f
	);
	float3x3 trans = transpose( mat );

	TEMPER_EXPECT_TRUE( trans == float3x3(
		0.0f, 3.0f, 6.0f,
		1.0f, 4.0f, 7.0f,
		2.0f, 5.0f, 8.0f
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestInverse_float3x3 ) {
	float3x3 identityMatrix;

	float3x3 mat = float3x3(
		6.0f, 2.0f, 3.0f,
		2.0f, 7.0f, 2.0f,
		3.0f, 2.0f, 6.0f
	);
	float3x3 matInverse = inverse( mat );

	TEMPER_EXPECT_TRUE( mat * matInverse == identityMatrix );

	TEMPER_PASS();
}

TEMPER_TEST( TestDeterminant_float3x3 ) {
	float3x3 mat = float3x3(
		6.0f, 2.0f, 3.0f,
		2.0f, 7.0f, 2.0f,
		3.0f, 2.0f, 6.0f
	);
	float det = determinant( mat );

	TEMPER_EXPECT_TRUE( floateq( det, 165.0f ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestTranslate_float3x3 ) {
	float3x3 mat;
	float3x3 translated = float3x3(
		1.0f, 0.0f, 2.0f,
		0.0f, 1.0f, 3.0f,
		0.0f, 0.0f, 1.0f
	);

	float2 translation = float2( 2.0f, 3.0f );
	mat = translate( mat, translation );

	TEMPER_EXPECT_TRUE( mat == translated );

	TEMPER_PASS();
}

TEMPER_TEST( TestRotate_float3x3 ) {
	TEMPER_FAIL();
}

TEMPER_TEST( TestScale_float3x3 ) {
	TEMPER_FAIL();
}

TEMPER_TEST( TestOrtho_float3x3 ) {
	TEMPER_FAIL();
}

TEMPER_TEST( TestPerspective_float3x3 ) {
	TEMPER_FAIL();
}

TEMPER_TEST( TestLookAt_float3x3 ) {
	TEMPER_FAIL();
}

TEMPER_SUITE( Test_float3x3 ) {
	TEMPER_RUN_TEST( TestAssignment_float3x3 );

	TEMPER_RUN_TEST( TestArithmeticAddition_float3x3 );
	TEMPER_RUN_TEST( TestArithmeticSubtraction_float3x3 );
	TEMPER_SKIP_TEST( TestArithmeticMultiplication_float3x3, "Give me a minute to think about how to structure this one." );
	TEMPER_RUN_TEST( TestArithmeticDivision_float3x3 );

	TEMPER_RUN_TEST( TestArray_float3x3 );
	TEMPER_RUN_TEST( TestRelational_float3x3 );

	TEMPER_RUN_TEST( TestIdentity_float3x3 );
	TEMPER_RUN_TEST( TestTranspose_float3x3 );
	TEMPER_RUN_TEST( TestDeterminant_float3x3 );
	TEMPER_RUN_TEST( TestInverse_float3x3 );

	TEMPER_RUN_TEST( TestTranslate_float3x3 );
	TEMPER_SKIP_TEST( TestRotate_float3x3, "TODO" );
	TEMPER_SKIP_TEST( TestScale_float3x3, "TODO" );

	TEMPER_SKIP_TEST( TestOrtho_float3x3, "TODO" );
	TEMPER_SKIP_TEST( TestPerspective_float3x3, "TODO" );
	TEMPER_SKIP_TEST( TestLookAt_float3x3, "TODO" );
};

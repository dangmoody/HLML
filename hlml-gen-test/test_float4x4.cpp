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

TEMPER_TEST( TestAssignment_float4x4 ) {
	float4x4 mat;

	// fill single value
	mat = float4x4( 999.0f );
	TEMPER_EXPECT_TRUE( mat[0] == float4( 999.0f, 0.0f, 0.0f, 0.0f ) );
	TEMPER_EXPECT_TRUE( mat[1] == float4( 0.0f, 999.0f, 0.0f, 0.0f ) );
	TEMPER_EXPECT_TRUE( mat[2] == float4( 0.0f, 0.0f, 999.0f, 0.0f ) );
	TEMPER_EXPECT_TRUE( mat[3] == float4( 0.0f, 0.0f, 0.0f, 999.0f ) );

	// row filling
	mat = float4x4(
		float4( 0, 1, 2, 3 ),
		float4( 4, 5, 6, 7 ),
		float4( 8, 9, 10, 11 ),
		float4( 12, 13, 14, 15 )
	);
	TEMPER_EXPECT_TRUE( mat[0] == float4( 0, 1, 2, 3 ) );
	TEMPER_EXPECT_TRUE( mat[1] == float4( 4, 5, 6, 7 ) );
	TEMPER_EXPECT_TRUE( mat[2] == float4( 8, 9, 10, 11 ) );
	TEMPER_EXPECT_TRUE( mat[3] == float4( 12, 13, 14, 15 ) );

	// all values filled
	mat = float4x4(
		16, 15, 14, 13, 
		12, 11, 10, 9, 
		8, 7, 6, 5, 
		4, 3, 2, 1
	);
	TEMPER_EXPECT_TRUE( mat[0] == float4( 16, 15, 14, 13 ) );
	TEMPER_EXPECT_TRUE( mat[1] == float4( 12, 11, 10, 9 ) );
	TEMPER_EXPECT_TRUE( mat[2] == float4( 8, 7, 6, 5 ) );
	TEMPER_EXPECT_TRUE( mat[3] == float4( 4, 3, 2, 1 ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticAddition_float4x4 ) {
	float4x4 a = float4x4(
		6.0f, 6.0f, 6.0f, 6.0f, 
		6.0f, 6.0f, 6.0f, 6.0f, 
		6.0f, 6.0f, 6.0f, 6.0f, 
		6.0f,6.0f,6.0f,6.0f
	);
	float4x4 b = float4x4(
		2.0f, 3.0f, 4.0f, 4.0f,
		6.0f, 6.0f, 8.0f, 8.0f,
		10.0f, 10.0f, 12.0f, 12.0f,
		18.0f, 18.0f, 24.0f, 24.0f
	);
	float4x4 c = a + b;

	TEMPER_EXPECT_TRUE( c == float4x4(
		8.0f, 9.0f, 10.0f, 10.0f,
		12.0f, 12.0f, 14.0f, 14.0f,
		16.0f, 16.0f, 18.0f, 18.0f,
		24.0f, 24.0f, 30.0f, 30.0f
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticSubtraction_float4x4 ) {
	float4x4 a = float4x4(
		6.0f, 6.0f, 6.0f, 6.0f, 
		6.0f, 6.0f, 6.0f, 6.0f, 
		6.0f, 6.0f, 6.0f, 6.0f, 
		6.0f,6.0f,6.0f,6.0f
	);
	float4x4 b = float4x4(
		2.0f, 3.0f, 4.0f, 4.0f,
		6.0f, 6.0f, 8.0f, 8.0f,
		10.0f, 10.0f, 12.0f, 12.0f,
		18.0f, 18.0f, 24.0f, 24.0f
	);
	float4x4 c = a - b;

	TEMPER_EXPECT_TRUE( c == float4x4(
		4.0f, 3.0f, 2.0f, 2.0f,
		0.0f, 0.0f, -2.0f, -2.0f,
		-4.0f, -4.0f, -6.0f, -6.0f,
		-12.0f, -12.0f, -18.0f, -18.0f
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticMultiplication_float4x4 ) {
	float4x4 a = float4x4(
		6.0f, 6.0f, 6.0f, 6.0f, 
		6.0f, 6.0f, 6.0f, 6.0f, 
		6.0f, 6.0f, 6.0f, 6.0f, 
		6.0f,6.0f,6.0f,6.0f
	);
	float4x4 b = float4x4(
		2.0f, 3.0f, 4.0f, 4.0f,
		6.0f, 6.0f, 8.0f, 8.0f,
		10.0f, 10.0f, 12.0f, 12.0f,
		18.0f, 18.0f, 24.0f, 24.0f
	);
	float4x4 c = a * b;

	TEMPER_EXPECT_TRUE( c == float4x4(
		0.0f, 1.0f, 2.0f, 3.0f,
		1.0f, 2.0f, 3.0f, 4.0f,
		2.0f, 3.0f, 4.0f, 5.0f,
		3.0f, 4.0f, 5.0f, 6.0f
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticDivision_float4x4 ) {
	float4x4 a = float4x4(
		2.0f, 3.0f, 4.0f, 4.0f,
		6.0f, 6.0f, 8.0f, 8.0f,
		10.0f, 10.0f, 12.0f, 12.0f,
		18.0f, 18.0f, 24.0f, 24.0f
	);
	float4x4 b = a / a;
	float4x4 identity = float4x4(
		1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
	);

	TEMPER_EXPECT_TRUE( b == identity );

	TEMPER_PASS();
}

TEMPER_TEST( TestArray_float4x4 ) {
	float4x4 mat;

	TEMPER_EXPECT_TRUE( mat[0] == float4( 1.0f, 0.0f, 0.0f, 0.0f ) );
	TEMPER_EXPECT_TRUE( mat[1] == float4( 0.0f, 1.0f, 0.0f, 0.0f ) );
	TEMPER_EXPECT_TRUE( mat[2] == float4( 0.0f, 0.0f, 1.0f, 0.0f ) );
	TEMPER_EXPECT_TRUE( mat[3] == float4( 0.0f, 0.0f, 0.0f, 1.0f ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestRelational_float4x4 ) {
	float4x4 mat0 = float4x4(
		1.0f, 1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f, 1.0f
	);
	float4x4 mat1 = float4x4(
		2.0f, 2.0f, 2.0f, 2.0f,
		2.0f, 2.0f, 2.0f, 2.0f,
		2.0f, 2.0f, 2.0f, 2.0f,
		2.0f, 2.0f, 2.0f, 2.0f
	);
	float4x4 mat2 = float4x4(
		3.0f, 3.0f, 3.0f, 3.0f,
		3.0f, 3.0f, 3.0f, 3.0f,
		3.0f, 3.0f, 3.0f, 3.0f,
		3.0f, 3.0f, 3.0f, 3.0f
	);
	float4x4 mat3 = float4x4(
		4.0f, 4.0f, 4.0f, 4.0f,
		4.0f, 4.0f, 4.0f, 4.0f,
		4.0f, 4.0f, 4.0f, 4.0f,
		4.0f, 4.0f, 4.0f, 4.0f
	);

	bool4x4 test0 = mat0 <= mat0;
	bool4x4 test1 = mat0 >= mat0;
	bool4x4 test2 = mat0 < mat1;

	bool4x4 test3 = mat1 <= mat1;
	bool4x4 test4 = mat1 >= mat1;
	bool4x4 test5 = mat1 < mat2;
	bool4x4 test6 = mat1 > mat0;

	bool4x4 test7 = mat2 <= mat2;
	bool4x4 test8 = mat2 >= mat2;
	bool4x4 test9 = mat2 < mat3;
	bool4x4 test10 = mat2 > mat1;

	bool4x4 test11 = mat3 <= mat3;
	bool4x4 test12 = mat3 >= mat3;
	bool4x4 test13 = mat3 > mat2;

	TEMPER_EXPECT_TRUE( test0 == bool4x4(
		true, true, true, true,
		true, true, true, true,
		true, true, true, true,
		true, true, true, true
	) );

	TEMPER_EXPECT_TRUE( test1 == bool4x4(
		true, true, true, true,
		true, true, true, true,
		true, true, true, true,
		true, true, true, true
	) );

	TEMPER_EXPECT_TRUE( test2 == bool4x4(
		true, true, true, true,
		true, true, true, true,
		true, true, true, true,
		true, true, true, true
	) );

	TEMPER_EXPECT_TRUE( test3 == bool4x4(
		true, true, true, true,
		true, true, true, true,
		true, true, true, true,
		true, true, true, true
	) );

	TEMPER_EXPECT_TRUE( test4 == bool4x4(
		true, true, true, true,
		true, true, true, true,
		true, true, true, true,
		true, true, true, true
	) );

	TEMPER_EXPECT_TRUE( test5 == bool4x4(
		true, true, true, true,
		true, true, true, true,
		true, true, true, true,
		true, true, true, true
	) );

	TEMPER_EXPECT_TRUE( test6 == bool4x4(
		true, true, true, true,
		true, true, true, true,
		true, true, true, true,
		true, true, true, true
	) );

	TEMPER_EXPECT_TRUE( test7 == bool4x4(
		true, true, true, true,
		true, true, true, true,
		true, true, true, true,
		true, true, true, true
	) );

	TEMPER_EXPECT_TRUE( test8 == bool4x4(
		true, true, true, true,
		true, true, true, true,
		true, true, true, true,
		true, true, true, true
	) );

	TEMPER_EXPECT_TRUE( test9 == bool4x4(
		true, true, true, true,
		true, true, true, true,
		true, true, true, true,
		true, true, true, true
	) );

	TEMPER_EXPECT_TRUE( test10 == bool4x4(
		true, true, true, true,
		true, true, true, true,
		true, true, true, true,
		true, true, true, true
	) );

	TEMPER_EXPECT_TRUE( test11 == bool4x4(
		true, true, true, true,
		true, true, true, true,
		true, true, true, true,
		true, true, true, true
	) );

	TEMPER_EXPECT_TRUE( test12 == bool4x4(
		true, true, true, true,
		true, true, true, true,
		true, true, true, true,
		true, true, true, true
	) );

	TEMPER_EXPECT_TRUE( test13 == bool4x4(
		true, true, true, true,
		true, true, true, true,
		true, true, true, true,
		true, true, true, true
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestIdentity_float4x4 ) {
	float4x4 id = float4x4(
		1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
	);

	float4x4 mat;
	TEMPER_EXPECT_TRUE( mat == id );

	identity( mat );
	TEMPER_EXPECT_TRUE( mat == id );

	TEMPER_PASS();
}

TEMPER_TEST( TestTranspose_float4x4 ) {
	float4x4 mat = float4x4(
		0.0f, 1.0f, 2.0f, 3.0f,
		4.0f, 5.0f, 6.0f, 7.0f,
		8.0f, 9.0f, 10.0f, 11.0f,
		12.0f, 13.0f, 14.0f, 15.0f
	);
	float4x4 trans = transpose( mat );

	TEMPER_EXPECT_TRUE( trans == float4x4(
		0.0f, 4.0f, 8.0f, 12.0f,
		1.0f, 5.0f, 9.0f, 13.0f,
		2.0f, 6.0f, 10.0f, 14.0f,
		3.0f, 7.0f, 11.0f, 15.0f
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestInverse_float4x4 ) {
	float4x4 identityMatrix;

	float4x4 mat = float4x4(
		6.0f, 2.0f, 3.0f, 4.0f,
		2.0f, 7.0f, 5.0f, 3.0f,
		3.0f, 5.0f, 7.0f, 2.0f,
		4.0f, 3.0f, 2.0f, 6.0f
	);
	float4x4 matInverse = inverse( mat );

	TEMPER_EXPECT_TRUE( mat * matInverse == identityMatrix );

	TEMPER_PASS();
}

TEMPER_TEST( TestDeterminant_float4x4 ) {
	float4x4 mat = float4x4(
		6.0f, 2.0f, 3.0f, 4.0f,
		2.0f, 7.0f, 5.0f, 3.0f,
		3.0f, 5.0f, 7.0f, 2.0f,
		4.0f, 3.0f, 2.0f, 6.0f
	);
	float det = determinant( mat );

	TEMPER_EXPECT_TRUE( floateq( det, 285.0f ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestTranslate_float4x4 ) {
	float4x4 mat;
	float4x4 translated = float4x4(
		1.0f, 0.0f, 0.0f, 2.0f,
		0.0f, 1.0f, 0.0f, 3.0f,
		0.0f, 0.0f, 1.0f, 4.0f,
		0.0f, 0.0f, 0.0f, 1.0f
	);

	float3 translation = float3( 2.0f, 3.0f, 4.0f );
	mat = translate( mat, translation );

	TEMPER_EXPECT_TRUE( mat == translated );

	TEMPER_PASS();
}

TEMPER_TEST( TestRotate_float4x4 ) {
	TEMPER_FAIL();
}

TEMPER_TEST( TestScale_float4x4 ) {
	TEMPER_FAIL();
}

TEMPER_TEST( TestOrtho_float4x4 ) {
	TEMPER_FAIL();
}

TEMPER_TEST( TestPerspective_float4x4 ) {
	TEMPER_FAIL();
}

TEMPER_TEST( TestLookAt_float4x4 ) {
	TEMPER_FAIL();
}

TEMPER_SUITE( Test_float4x4 ) {
	TEMPER_RUN_TEST( TestAssignment_float4x4 );

	TEMPER_RUN_TEST( TestArithmeticAddition_float4x4 );
	TEMPER_RUN_TEST( TestArithmeticSubtraction_float4x4 );
	TEMPER_SKIP_TEST( TestArithmeticMultiplication_float4x4, "Give me a minute to think about how to structure this one." );
	TEMPER_RUN_TEST( TestArithmeticDivision_float4x4 );

	TEMPER_RUN_TEST( TestArray_float4x4 );
	TEMPER_RUN_TEST( TestRelational_float4x4 );

	TEMPER_RUN_TEST( TestIdentity_float4x4 );
	TEMPER_RUN_TEST( TestTranspose_float4x4 );
	TEMPER_RUN_TEST( TestDeterminant_float4x4 );
	TEMPER_RUN_TEST( TestInverse_float4x4 );

	TEMPER_RUN_TEST( TestTranslate_float4x4 );
	TEMPER_SKIP_TEST( TestRotate_float4x4, "TODO" );
	TEMPER_SKIP_TEST( TestScale_float4x4, "TODO" );

	TEMPER_SKIP_TEST( TestOrtho_float4x4, "TODO" );
	TEMPER_SKIP_TEST( TestPerspective_float4x4, "TODO" );
	TEMPER_SKIP_TEST( TestLookAt_float4x4, "TODO" );
};

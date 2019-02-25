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

TEMPER_TEST( TestAssignment_float2x2 ) {
	float2x2 mat;

	// fill single value
	mat = float2x2( 999.0f );
	TEMPER_EXPECT_TRUE( mat[0] == float2( 999.0f, 0.0f ) );
	TEMPER_EXPECT_TRUE( mat[1] == float2( 0.0f, 999.0f ) );

	// row filling
	mat = float2x2(
		float2( 0, 1 ),
		float2( 2, 3 )
	);
	TEMPER_EXPECT_TRUE( mat[0] == float2( 0, 1 ) );
	TEMPER_EXPECT_TRUE( mat[1] == float2( 2, 3 ) );

	// all values filled
	mat = float2x2(
		4, 3, 
		2, 1
	);
	TEMPER_EXPECT_TRUE( mat[0] == float2( 4, 3 ) );
	TEMPER_EXPECT_TRUE( mat[1] == float2( 2, 1 ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticAddition_float2x2 ) {
	float2x2 a = float2x2(
		6.0f, 6.0f, 
		6.0f,6.0f
	);
	float2x2 b = float2x2(
		2.0f, 3.0f,
		6.0f, 6.0f
	);
	float2x2 c = a + b;

	TEMPER_EXPECT_TRUE( c == float2x2(
		8.0f, 9.0f,
		12.0f, 12.0f
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticSubtraction_float2x2 ) {
	float2x2 a = float2x2(
		6.0f, 6.0f, 
		6.0f,6.0f
	);
	float2x2 b = float2x2(
		2.0f, 3.0f,
		6.0f, 6.0f
	);
	float2x2 c = a - b;

	TEMPER_EXPECT_TRUE( c == float2x2(
		4.0f, 3.0f,
		0.0f, 0.0f
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticMultiplication_float2x2 ) {
	float2x2 a = float2x2(
		6.0f, 6.0f, 
		6.0f,6.0f
	);
	float2x2 b = float2x2(
		2.0f, 3.0f,
		6.0f, 6.0f
	);
	float2x2 c = a * b;

	TEMPER_EXPECT_TRUE( c == float2x2(
		0.0f, 1.0f,
		1.0f, 2.0f
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticDivision_float2x2 ) {
	float2x2 a = float2x2(
		2.0f, 3.0f,
		6.0f, 6.0f
	);
	float2x2 b = a / a;
	float2x2 identity = float2x2(
		1.0f, 0.0f,
		0.0f, 1.0f
	);

	TEMPER_EXPECT_TRUE( b == identity );

	TEMPER_PASS();
}

TEMPER_TEST( TestArray_float2x2 ) {
	float2x2 mat;

	TEMPER_EXPECT_TRUE( mat[0] == float2( 1.0f, 0.0f ) );
	TEMPER_EXPECT_TRUE( mat[1] == float2( 0.0f, 1.0f ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestRelational_float2x2 ) {
	TEMPER_FAIL();
}

TEMPER_TEST( TestIdentity_float2x2 ) {
	float2x2 id = float2x2(
		1.0f, 0.0f,
		0.0f, 1.0f
	);

	float2x2 mat;
	TEMPER_EXPECT_TRUE( mat == id );

	identity( mat );
	TEMPER_EXPECT_TRUE( mat == id );

	TEMPER_PASS();
}

TEMPER_TEST( TestTranspose_float2x2 ) {
	float2x2 mat = float2x2(
		0.0f, 1.0f,
		2.0f, 3.0f
	);
	float2x2 trans = transpose( mat );

	TEMPER_EXPECT_TRUE( trans == float2x2(
		0.0f, 2.0f,
		1.0f, 3.0f
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestInverse_float2x2 ) {
	float2x2 identityMatrix;

	float2x2 mat = float2x2(
		6.0f, 2.0f,
		2.0f, 6.0f
	);
	float2x2 matInverse = inverse( mat );

	TEMPER_EXPECT_TRUE( mat * matInverse == identityMatrix );

	TEMPER_PASS();
}

TEMPER_TEST( TestDeterminant_float2x2 ) {
	float2x2 mat = float2x2(
		6.0f, 2.0f,
		2.0f, 6.0f
	);
	float det = determinant( mat );

	TEMPER_EXPECT_TRUE( floateq( det, 32.0f ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestTranslate_float2x2 ) {
	TEMPER_FAIL();
}

TEMPER_TEST( TestRotate_float2x2 ) {
	TEMPER_FAIL();
}

TEMPER_TEST( TestScale_float2x2 ) {
	TEMPER_FAIL();
}

TEMPER_TEST( TestOrtho_float2x2 ) {
	TEMPER_FAIL();
}

TEMPER_TEST( TestPerspective_float2x2 ) {
	TEMPER_FAIL();
}

TEMPER_TEST( TestLookAt_float2x2 ) {
	TEMPER_FAIL();
}

TEMPER_SUITE( Test_float2x2 ) {
	TEMPER_RUN_TEST( TestAssignment_float2x2 );

	TEMPER_RUN_TEST( TestArithmeticAddition_float2x2 );
	TEMPER_RUN_TEST( TestArithmeticSubtraction_float2x2 );
	TEMPER_SKIP_TEST( TestArithmeticMultiplication_float2x2, "Give me a minute to think about how to structure this one." );
	TEMPER_RUN_TEST( TestArithmeticDivision_float2x2 );

	TEMPER_RUN_TEST( TestArray_float2x2 );
	TEMPER_SKIP_TEST( TestRelational_float2x2, "TODO" );

	TEMPER_RUN_TEST( TestIdentity_float2x2 );
	TEMPER_RUN_TEST( TestTranspose_float2x2 );
	TEMPER_RUN_TEST( TestDeterminant_float2x2 );
	TEMPER_RUN_TEST( TestInverse_float2x2 );
	TEMPER_SKIP_TEST( TestTranslate_float2x2, "TODO" );
	TEMPER_SKIP_TEST( TestRotate_float2x2, "TODO" );
	TEMPER_SKIP_TEST( TestScale_float2x2, "TODO" );

	TEMPER_SKIP_TEST( TestOrtho_float2x2, "TODO" );
	TEMPER_SKIP_TEST( TestPerspective_float2x2, "TODO" );
	TEMPER_SKIP_TEST( TestLookAt_float2x2, "TODO" );
};

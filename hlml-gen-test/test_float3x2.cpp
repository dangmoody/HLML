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

TEMPER_TEST( TestAssignment_float3x2 ) {
	float3x2 mat;

	// fill single value
	mat = float3x2( 999.0f );
	TEMPER_EXPECT_TRUE( mat[0] == float2( 999.0f, 0.0f ) );
	TEMPER_EXPECT_TRUE( mat[1] == float2( 0.0f, 999.0f ) );
	TEMPER_EXPECT_TRUE( mat[2] == float2( 0.0f, 0.0f ) );

	// row filling
	mat = float3x2(
		float2( 0, 1 ),
		float2( 2, 3 ),
		float2( 4, 5 )
	);
	TEMPER_EXPECT_TRUE( mat[0] == float2( 0, 1 ) );
	TEMPER_EXPECT_TRUE( mat[1] == float2( 2, 3 ) );
	TEMPER_EXPECT_TRUE( mat[2] == float2( 4, 5 ) );

	// all values filled
	mat = float3x2(
		6, 5, 
		4, 3, 
		2, 1
	);
	TEMPER_EXPECT_TRUE( mat[0] == float2( 6, 5 ) );
	TEMPER_EXPECT_TRUE( mat[1] == float2( 4, 3 ) );
	TEMPER_EXPECT_TRUE( mat[2] == float2( 2, 1 ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticAddition_float3x2 ) {
	float3x2 a = float3x2(
		6.0f, 6.0f, 6.0f, 
		6.0f,6.0f,6.0f
	);
	float3x2 b = float3x2(
		2.0f, 3.0f,
		6.0f, 6.0f,
		10.0f, 10.0f
	);
	float3x2 c = a + b;

	TEMPER_EXPECT_TRUE( c == float3x2(
		8.0f, 9.0f,
		12.0f, 12.0f,
		16.0f, 16.0f
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticSubtraction_float3x2 ) {
	float3x2 a = float3x2(
		6.0f, 6.0f, 6.0f, 
		6.0f,6.0f,6.0f
	);
	float3x2 b = float3x2(
		2.0f, 3.0f,
		6.0f, 6.0f,
		10.0f, 10.0f
	);
	float3x2 c = a - b;

	TEMPER_EXPECT_TRUE( c == float3x2(
		4.0f, 3.0f,
		0.0f, 0.0f,
		-4.0f, -4.0f
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticMultiplication_float3x2 ) {
	float3x2 a = float3x2(
		6.0f, 6.0f, 6.0f, 
		6.0f,6.0f,6.0f
	);
	float3x2 b = float3x2(
		2.0f, 3.0f,
		6.0f, 6.0f,
		10.0f, 10.0f
	);
	float3x2 c = a * b;

	TEMPER_EXPECT_TRUE( c == float3x2(
		0.0f, 1.0f,
		1.0f, 2.0f,
		2.0f, 3.0f
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticDivision_float3x2 ) {
	float3x2 a = float3x2(
		2.0f, 3.0f,
		6.0f, 6.0f,
		10.0f, 10.0f
	);
	float3x2 b = float3x2(
		6.0f, 6.0f, 6.0f, 
		6.0f,6.0f,6.0f
	);
	float3x2 c = b / a;

	TEMPER_EXPECT_TRUE( c == float3x2(
		3.000000f, 2.000000f,
		1.000000f, 1.000000f,
		0.600000f, 0.600000f
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArray_float3x2 ) {
	float3x2 mat;

	TEMPER_EXPECT_TRUE( mat[0] == float2( 1.0f, 0.0f ) );
	TEMPER_EXPECT_TRUE( mat[1] == float2( 0.0f, 1.0f ) );
	TEMPER_EXPECT_TRUE( mat[2] == float2( 0.0f, 0.0f ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestRelational_float3x2 ) {
	TEMPER_FAIL();
}

TEMPER_TEST( TestIdentity_float3x2 ) {
	float3x2 id = float3x2(
		1.0f, 0.0f,
		0.0f, 1.0f,
		0.0f, 0.0f
	);

	float3x2 mat;
	TEMPER_EXPECT_TRUE( mat == id );

	identity( mat );
	TEMPER_EXPECT_TRUE( mat == id );

	TEMPER_PASS();
}

TEMPER_TEST( TestTranspose_float3x2 ) {
	float3x2 mat = float3x2(
		0.0f, 1.0f,
		2.0f, 3.0f,
		4.0f, 5.0f
	);
	float2x3 trans = transpose( mat );

	TEMPER_EXPECT_TRUE( trans == float2x3(
		0.0f, 2.0f, 4.0f,
		1.0f, 3.0f, 5.0f
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestTranslate_float3x2 ) {
	TEMPER_FAIL();
}

TEMPER_TEST( TestRotate_float3x2 ) {
	TEMPER_FAIL();
}

TEMPER_TEST( TestScale_float3x2 ) {
	TEMPER_FAIL();
}

TEMPER_TEST( TestOrtho_float3x2 ) {
	TEMPER_FAIL();
}

TEMPER_TEST( TestPerspective_float3x2 ) {
	TEMPER_FAIL();
}

TEMPER_TEST( TestLookAt_float3x2 ) {
	TEMPER_FAIL();
}

TEMPER_SUITE( Test_float3x2 ) {
	TEMPER_RUN_TEST( TestAssignment_float3x2 );

	TEMPER_RUN_TEST( TestArithmeticAddition_float3x2 );
	TEMPER_RUN_TEST( TestArithmeticSubtraction_float3x2 );
	TEMPER_SKIP_TEST( TestArithmeticMultiplication_float3x2, "Give me a minute to think about how to structure this one." );
	TEMPER_RUN_TEST( TestArithmeticDivision_float3x2 );

	TEMPER_RUN_TEST( TestArray_float3x2 );
	TEMPER_SKIP_TEST( TestRelational_float3x2, "TODO" );

	TEMPER_RUN_TEST( TestIdentity_float3x2 );
	TEMPER_RUN_TEST( TestTranspose_float3x2 );
	TEMPER_SKIP_TEST( TestTranslate_float3x2, "TODO" );
	TEMPER_SKIP_TEST( TestRotate_float3x2, "TODO" );
	TEMPER_SKIP_TEST( TestScale_float3x2, "TODO" );

	TEMPER_SKIP_TEST( TestOrtho_float3x2, "TODO" );
	TEMPER_SKIP_TEST( TestPerspective_float3x2, "TODO" );
	TEMPER_SKIP_TEST( TestLookAt_float3x2, "TODO" );
};

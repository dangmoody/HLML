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

TEMPER_TEST( TestAssignment_uint3x2 ) {
	uint3x2 mat;

	// fill single value
	mat = uint3x2( 999 );
	TEMPER_EXPECT_TRUE( mat[0] == uint2( 999, 0 ) );
	TEMPER_EXPECT_TRUE( mat[1] == uint2( 0, 999 ) );
	TEMPER_EXPECT_TRUE( mat[2] == uint2( 0, 0 ) );

	// row filling
	mat = uint3x2(
		uint2( 0, 1 ),
		uint2( 2, 3 ),
		uint2( 4, 5 )
	);
	TEMPER_EXPECT_TRUE( mat[0] == uint2( 0, 1 ) );
	TEMPER_EXPECT_TRUE( mat[1] == uint2( 2, 3 ) );
	TEMPER_EXPECT_TRUE( mat[2] == uint2( 4, 5 ) );

	// all values filled
	mat = uint3x2(
		6, 5, 
		4, 3, 
		2, 1
	);
	TEMPER_EXPECT_TRUE( mat[0] == uint2( 6, 5 ) );
	TEMPER_EXPECT_TRUE( mat[1] == uint2( 4, 3 ) );
	TEMPER_EXPECT_TRUE( mat[2] == uint2( 2, 1 ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticAddition_uint3x2 ) {
	uint3x2 a = uint3x2(
		6, 6, 6, 
		6,6,6
	);
	uint3x2 b = uint3x2(
		2, 3,
		6, 6,
		10, 10
	);
	uint3x2 c = a + b;

	TEMPER_EXPECT_TRUE( c == uint3x2(
		8, 9,
		12, 12,
		16, 16
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticSubtraction_uint3x2 ) {
	uint3x2 a = uint3x2(
		6, 6, 6, 
		6,6,6
	);
	uint3x2 b = uint3x2(
		2, 3,
		6, 6,
		10, 10
	);
	uint3x2 c = a - b;

	TEMPER_EXPECT_TRUE( c == uint3x2(
		4, 3,
		0, 0,
		-4, -4
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticMultiplication_uint3x2 ) {
	uint3x2 a = uint3x2(
		6, 6, 6, 
		6,6,6
	);
	uint3x2 b = uint3x2(
		2, 3,
		6, 6,
		10, 10
	);
	uint3x2 c = a * b;

	TEMPER_EXPECT_TRUE( c == uint3x2(
		0, 1,
		1, 2,
		2, 3
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticDivision_uint3x2 ) {
	uint3x2 a = uint3x2(
		2, 3,
		6, 6,
		10, 10
	);
	uint3x2 b = uint3x2(
		6, 6, 6, 
		6,6,6
	);
	uint3x2 c = b / a;

	TEMPER_EXPECT_TRUE( c == uint3x2(
		3, 2,
		1, 1,
		0, 0
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArray_uint3x2 ) {
	uint3x2 mat;

	TEMPER_EXPECT_TRUE( mat[0] == uint2( 1, 0 ) );
	TEMPER_EXPECT_TRUE( mat[1] == uint2( 0, 1 ) );
	TEMPER_EXPECT_TRUE( mat[2] == uint2( 0, 0 ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestRelational_uint3x2 ) {
	TEMPER_FAIL();
}

TEMPER_TEST( TestIdentity_uint3x2 ) {
	uint3x2 id = uint3x2(
		1, 0,
		0, 1,
		0, 0
	);

	uint3x2 mat;
	TEMPER_EXPECT_TRUE( mat == id );

	identity( mat );
	TEMPER_EXPECT_TRUE( mat == id );

	TEMPER_PASS();
}

TEMPER_TEST( TestTranspose_uint3x2 ) {
	uint3x2 mat = uint3x2(
		0, 1,
		2, 3,
		4, 5
	);
	uint2x3 trans = transpose( mat );

	TEMPER_EXPECT_TRUE( trans == uint2x3(
		0, 2, 4,
		1, 3, 5
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestInverse_uint3x2 ) {
	TEMPER_FAIL();
}

TEMPER_TEST( TestDeterminant_uint3x2 ) {
	TEMPER_FAIL();
}

TEMPER_TEST( TestTranslate_uint3x2 ) {
	TEMPER_FAIL();
}

TEMPER_TEST( TestRotate_uint3x2 ) {
	TEMPER_FAIL();
}

TEMPER_TEST( TestScale_uint3x2 ) {
	TEMPER_FAIL();
}

TEMPER_TEST( TestOrtho_uint3x2 ) {
	TEMPER_FAIL();
}

TEMPER_TEST( TestPerspective_uint3x2 ) {
	TEMPER_FAIL();
}

TEMPER_TEST( TestLookAt_uint3x2 ) {
	TEMPER_FAIL();
}

TEMPER_SUITE( Test_uint3x2 ) {
	TEMPER_RUN_TEST( TestAssignment_uint3x2 );

	TEMPER_RUN_TEST( TestArithmeticAddition_uint3x2 );
	TEMPER_RUN_TEST( TestArithmeticSubtraction_uint3x2 );
	TEMPER_SKIP_TEST( TestArithmeticMultiplication_uint3x2, "Give me a minute to think about how to structure this one." );
	TEMPER_RUN_TEST( TestArithmeticDivision_uint3x2 );

	TEMPER_RUN_TEST( TestArray_uint3x2 );
	TEMPER_SKIP_TEST( TestRelational_uint3x2, "TODO" );

	TEMPER_RUN_TEST( TestIdentity_uint3x2 );
	TEMPER_RUN_TEST( TestTranspose_uint3x2 );
	TEMPER_SKIP_TEST( TestDeterminant_uint3x2, "TODO" );

	TEMPER_SKIP_TEST( TestTranslate_uint3x2, "TODO" );
	TEMPER_SKIP_TEST( TestRotate_uint3x2, "TODO" );
	TEMPER_SKIP_TEST( TestScale_uint3x2, "TODO" );

	TEMPER_SKIP_TEST( TestOrtho_uint3x2, "TODO" );
	TEMPER_SKIP_TEST( TestPerspective_uint3x2, "TODO" );
	TEMPER_SKIP_TEST( TestLookAt_uint3x2, "TODO" );
};

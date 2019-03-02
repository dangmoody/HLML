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
	mat = float3x2( 999.000000f );
	TEMPER_EXPECT_TRUE( mat[0] == float2( 999.000000f, 0.000000f ) );
	TEMPER_EXPECT_TRUE( mat[1] == float2( 0.000000f, 999.000000f ) );
	TEMPER_EXPECT_TRUE( mat[2] == float2( 0.000000f, 0.000000f ) );

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
		6.000000f, 6.000000f, 6.000000f, 
		6.000000f,6.000000f,6.000000f
	);
	float3x2 b = float3x2(
		2.000000f, 3.000000f,
		6.000000f, 6.000000f,
		10.000000f, 10.000000f
	);
	float3x2 c = a + b;

	TEMPER_EXPECT_TRUE( c == float3x2(
		8.000000f, 9.000000f,
		12.000000f, 12.000000f,
		16.000000f, 16.000000f
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticSubtraction_float3x2 ) {
	float3x2 a = float3x2(
		6.000000f, 6.000000f, 6.000000f, 
		6.000000f,6.000000f,6.000000f
	);
	float3x2 b = float3x2(
		2.000000f, 3.000000f,
		6.000000f, 6.000000f,
		10.000000f, 10.000000f
	);
	float3x2 c = a - b;

	TEMPER_EXPECT_TRUE( c == float3x2(
		4.000000f, 3.000000f,
		0.000000f, 0.000000f,
		-4.000000f, -4.000000f
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticMultiplication_float3x2 ) {
	float3x2 a = float3x2(
		6.000000f, 6.000000f, 6.000000f, 
		6.000000f,6.000000f,6.000000f
	);
	float3x2 b = float3x2(
		2.000000f, 3.000000f,
		6.000000f, 6.000000f,
		10.000000f, 10.000000f
	);
	float3x2 c = a * b;

	TEMPER_EXPECT_TRUE( c == float3x2(
		0.000000f, 1.000000f,
		1.000000f, 2.000000f,
		2.000000f, 3.000000f
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticDivision_float3x2 ) {
	float3x2 a = float3x2(
		2.000000f, 3.000000f,
		6.000000f, 6.000000f,
		10.000000f, 10.000000f
	);
	float3x2 b = float3x2(
		6.000000f, 6.000000f, 6.000000f, 
		6.000000f,6.000000f,6.000000f
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

	TEMPER_EXPECT_TRUE( mat[0] == float2( 1.000000f, 0.000000f ) );
	TEMPER_EXPECT_TRUE( mat[1] == float2( 0.000000f, 1.000000f ) );
	TEMPER_EXPECT_TRUE( mat[2] == float2( 0.000000f, 0.000000f ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestRelational_float3x2 ) {
	float3x2 mat0 = float3x2(
		1.000000f, 1.000000f,
		1.000000f, 1.000000f,
		1.000000f, 1.000000f
	);
	float3x2 mat1 = float3x2(
		2.000000f, 2.000000f,
		2.000000f, 2.000000f,
		2.000000f, 2.000000f
	);
	float3x2 mat2 = float3x2(
		3.000000f, 3.000000f,
		3.000000f, 3.000000f,
		3.000000f, 3.000000f
	);
	float3x2 mat3 = float3x2(
		4.000000f, 4.000000f,
		4.000000f, 4.000000f,
		4.000000f, 4.000000f
	);

	bool3x2 test0 = mat0 <= mat0;
	bool3x2 test1 = mat0 >= mat0;
	bool3x2 test2 = mat0 < mat1;

	bool3x2 test3 = mat1 <= mat1;
	bool3x2 test4 = mat1 >= mat1;
	bool3x2 test5 = mat1 < mat2;
	bool3x2 test6 = mat1 > mat0;

	bool3x2 test7 = mat2 <= mat2;
	bool3x2 test8 = mat2 >= mat2;
	bool3x2 test9 = mat2 < mat3;
	bool3x2 test10 = mat2 > mat1;

	bool3x2 test11 = mat3 <= mat3;
	bool3x2 test12 = mat3 >= mat3;
	bool3x2 test13 = mat3 > mat2;

	TEMPER_EXPECT_TRUE( test0 == bool3x2(
		true, true,
		true, true,
		true, true
	) );

	TEMPER_EXPECT_TRUE( test1 == bool3x2(
		true, true,
		true, true,
		true, true
	) );

	TEMPER_EXPECT_TRUE( test2 == bool3x2(
		true, true,
		true, true,
		true, true
	) );

	TEMPER_EXPECT_TRUE( test3 == bool3x2(
		true, true,
		true, true,
		true, true
	) );

	TEMPER_EXPECT_TRUE( test4 == bool3x2(
		true, true,
		true, true,
		true, true
	) );

	TEMPER_EXPECT_TRUE( test5 == bool3x2(
		true, true,
		true, true,
		true, true
	) );

	TEMPER_EXPECT_TRUE( test6 == bool3x2(
		true, true,
		true, true,
		true, true
	) );

	TEMPER_EXPECT_TRUE( test7 == bool3x2(
		true, true,
		true, true,
		true, true
	) );

	TEMPER_EXPECT_TRUE( test8 == bool3x2(
		true, true,
		true, true,
		true, true
	) );

	TEMPER_EXPECT_TRUE( test9 == bool3x2(
		true, true,
		true, true,
		true, true
	) );

	TEMPER_EXPECT_TRUE( test10 == bool3x2(
		true, true,
		true, true,
		true, true
	) );

	TEMPER_EXPECT_TRUE( test11 == bool3x2(
		true, true,
		true, true,
		true, true
	) );

	TEMPER_EXPECT_TRUE( test12 == bool3x2(
		true, true,
		true, true,
		true, true
	) );

	TEMPER_EXPECT_TRUE( test13 == bool3x2(
		true, true,
		true, true,
		true, true
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestIdentity_float3x2 ) {
	float3x2 id = float3x2(
		1.000000f, 0.000000f,
		0.000000f, 1.000000f,
		0.000000f, 0.000000f
	);

	float3x2 mat;
	TEMPER_EXPECT_TRUE( mat == id );

	identity( mat );
	TEMPER_EXPECT_TRUE( mat == id );

	TEMPER_PASS();
}

TEMPER_TEST( TestTranspose_float3x2 ) {
	float3x2 mat = float3x2(
		0.000000f, 1.000000f,
		2.000000f, 3.000000f,
		4.000000f, 5.000000f
	);
	float2x3 trans = transpose( mat );

	TEMPER_EXPECT_TRUE( trans == float2x3(
		0.000000f, 2.000000f, 4.000000f,
		1.000000f, 3.000000f, 5.000000f
	) );

	TEMPER_PASS();
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
	TEMPER_RUN_TEST( TestRelational_float3x2 );

	TEMPER_RUN_TEST( TestIdentity_float3x2 );
	TEMPER_RUN_TEST( TestTranspose_float3x2 );

	TEMPER_SKIP_TEST( TestScale_float3x2, "TODO" );

	TEMPER_SKIP_TEST( TestOrtho_float3x2, "TODO" );
	TEMPER_SKIP_TEST( TestPerspective_float3x2, "TODO" );
	TEMPER_SKIP_TEST( TestLookAt_float3x2, "TODO" );
};

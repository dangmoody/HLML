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
	mat = float2x2( 999.000000f );
	TEMPER_EXPECT_TRUE( mat[0] == float2( 999.000000f, 0.000000f ) );
	TEMPER_EXPECT_TRUE( mat[1] == float2( 0.000000f, 999.000000f ) );

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
	float2x2 answer = float2x2(
		7.000000f, 7.000000f,
		8.000000f, 8.000000f
	);

	float2x2 a = float2x2(
		6.000000f, 6.000000f,
		6.000000f, 6.000000f
	);
	float2x2 b = float2x2(
		1.000000f, 1.000000f,
		2.000000f, 2.000000f
	);
	float2x2 c = a + b;

	TEMPER_EXPECT_TRUE( c == answer );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticSubtraction_float2x2 ) {
	float2x2 answer = float2x2(
		5.000000f, 5.000000f,
		4.000000f, 4.000000f
	);

	float2x2 a = float2x2(
		6.000000f, 6.000000f,
		6.000000f, 6.000000f
	);
	float2x2 b = float2x2(
		1.000000f, 1.000000f,
		2.000000f, 2.000000f
	);
	float2x2 c = a - b;

	TEMPER_EXPECT_TRUE( c == answer );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticMultiplication_float2x2 ) {
	float2x2 answer = float2x2(
		18.000000f, 18.000000f,
		18.000000f, 18.000000f
	);

	float2x2 a = float2x2(
		6.000000f, 6.000000f,
		6.000000f, 6.000000f
	);
	float2x2 b = float2x2(
		1.000000f, 1.000000f,
		2.000000f, 2.000000f
	);
	float2x2 c = a * b;

	TEMPER_EXPECT_TRUE( c == answer );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticDivision_float2x2 ) {
	float2x2 answer = float2x2(
	);

	float2x2 a = float2x2(
		6.000000f, 6.000000f,
		6.000000f, 6.000000f
	);
	float2x2 b = float2x2(
		1.000000f, 1.000000f,
		2.000000f, 2.000000f
	);
	float2x2 c = a / b;

	TEMPER_EXPECT_TRUE( c == answer );

	TEMPER_PASS();
}

TEMPER_TEST( TestArray_float2x2 ) {
	float2x2 mat;

	TEMPER_EXPECT_TRUE( mat[0] == float2( 1.000000f, 0.000000f ) );
	TEMPER_EXPECT_TRUE( mat[1] == float2( 0.000000f, 1.000000f ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestRelational_float2x2 ) {
	float2x2 mat0 = float2x2(
		1.000000f, 1.000000f,
		1.000000f, 1.000000f
	);
	float2x2 mat1 = float2x2(
		2.000000f, 2.000000f,
		2.000000f, 2.000000f
	);
	float2x2 mat2 = float2x2(
		3.000000f, 3.000000f,
		3.000000f, 3.000000f
	);
	float2x2 mat3 = float2x2(
		4.000000f, 4.000000f,
		4.000000f, 4.000000f
	);

	bool2x2 test0 = mat0 <= mat0;
	bool2x2 test1 = mat0 >= mat0;
	bool2x2 test2 = mat0 < mat1;

	bool2x2 test3 = mat1 <= mat1;
	bool2x2 test4 = mat1 >= mat1;
	bool2x2 test5 = mat1 < mat2;
	bool2x2 test6 = mat1 > mat0;

	bool2x2 test7 = mat2 <= mat2;
	bool2x2 test8 = mat2 >= mat2;
	bool2x2 test9 = mat2 < mat3;
	bool2x2 test10 = mat2 > mat1;

	bool2x2 test11 = mat3 <= mat3;
	bool2x2 test12 = mat3 >= mat3;
	bool2x2 test13 = mat3 > mat2;

	TEMPER_EXPECT_TRUE( test0 == bool2x2(
		true, true,
		true, true
	) );

	TEMPER_EXPECT_TRUE( test1 == bool2x2(
		true, true,
		true, true
	) );

	TEMPER_EXPECT_TRUE( test2 == bool2x2(
		true, true,
		true, true
	) );

	TEMPER_EXPECT_TRUE( test3 == bool2x2(
		true, true,
		true, true
	) );

	TEMPER_EXPECT_TRUE( test4 == bool2x2(
		true, true,
		true, true
	) );

	TEMPER_EXPECT_TRUE( test5 == bool2x2(
		true, true,
		true, true
	) );

	TEMPER_EXPECT_TRUE( test6 == bool2x2(
		true, true,
		true, true
	) );

	TEMPER_EXPECT_TRUE( test7 == bool2x2(
		true, true,
		true, true
	) );

	TEMPER_EXPECT_TRUE( test8 == bool2x2(
		true, true,
		true, true
	) );

	TEMPER_EXPECT_TRUE( test9 == bool2x2(
		true, true,
		true, true
	) );

	TEMPER_EXPECT_TRUE( test10 == bool2x2(
		true, true,
		true, true
	) );

	TEMPER_EXPECT_TRUE( test11 == bool2x2(
		true, true,
		true, true
	) );

	TEMPER_EXPECT_TRUE( test12 == bool2x2(
		true, true,
		true, true
	) );

	TEMPER_EXPECT_TRUE( test13 == bool2x2(
		true, true,
		true, true
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestIdentity_float2x2 ) {
	float2x2 id = float2x2(
		1.000000f, 0.000000f,
		0.000000f, 1.000000f
	);

	float2x2 mat;
	TEMPER_EXPECT_TRUE( mat == id );

	identity( mat );
	TEMPER_EXPECT_TRUE( mat == id );

	TEMPER_PASS();
}

TEMPER_TEST( TestTranspose_float2x2 ) {
	float2x2 mat = float2x2(
		0.000000f, 1.000000f,
		2.000000f, 3.000000f
	);
	float2x2 trans = transpose( mat );

	TEMPER_EXPECT_TRUE( trans == float2x2(
		0.000000f, 2.000000f,
		1.000000f, 3.000000f
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestInverse_float2x2 ) {
	float2x2 identityMatrix;

	float2x2 mat = float2x2(
		6.000000f, 2.000000f,
		2.000000f, 6.000000f
	);
	float2x2 matInverse = inverse( mat );

	TEMPER_EXPECT_TRUE( mat * matInverse == identityMatrix );

	TEMPER_PASS();
}

TEMPER_TEST( TestDeterminant_float2x2 ) {
	float2x2 mat = float2x2(
		6.000000f, 2.000000f,
		2.000000f, 6.000000f
	);
	float det = determinant( mat );

	TEMPER_EXPECT_TRUE( floateq( det, 32.000000f ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestScale_float2x2 ) {
	float2x2 mat;
	float2x2 scaled = scale( mat, float3( 2.000000f, 2.000000f, 2.000000f ) );

	TEMPER_EXPECT_TRUE( scaled == float2x2(
		2.000000f, 0.000000f,
		0.000000f, 2.000000f
	) );

	TEMPER_PASS();
}

TEMPER_SUITE( Test_float2x2 ) {
	TEMPER_RUN_TEST( TestAssignment_float2x2 );

	TEMPER_RUN_TEST( TestArithmeticAddition_float2x2 );
	TEMPER_RUN_TEST( TestArithmeticSubtraction_float2x2 );
	TEMPER_RUN_TEST( TestArithmeticMultiplication_float2x2 );
	TEMPER_RUN_TEST( TestArithmeticDivision_float2x2 );

	TEMPER_RUN_TEST( TestArray_float2x2 );
	TEMPER_RUN_TEST( TestRelational_float2x2 );

	TEMPER_RUN_TEST( TestIdentity_float2x2 );
	TEMPER_RUN_TEST( TestTranspose_float2x2 );
	TEMPER_RUN_TEST( TestDeterminant_float2x2 );
	TEMPER_RUN_TEST( TestInverse_float2x2 );


};

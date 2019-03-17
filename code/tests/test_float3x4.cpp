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

#include "../../code/out/gen/hlml_functions_matrix.h"

#include <temper/temper.h>

TEMPER_TEST( TestAssignment_float3x4 ) {
	float3x4 mat;

	// fill single value
	mat = float3x4( 999.000000f );
	TEMPER_EXPECT_TRUE( mat[0] == float4( 999.000000f, 0.000000f, 0.000000f, 0.000000f ) );
	TEMPER_EXPECT_TRUE( mat[1] == float4( 0.000000f, 999.000000f, 0.000000f, 0.000000f ) );
	TEMPER_EXPECT_TRUE( mat[2] == float4( 0.000000f, 0.000000f, 999.000000f, 0.000000f ) );

	// row filling
	mat = float3x4(
		float4( 0, 1, 2, 3 ),
		float4( 4, 5, 6, 7 ),
		float4( 8, 9, 10, 11 )
	);
	TEMPER_EXPECT_TRUE( mat[0] == float4( 0, 1, 2, 3 ) );
	TEMPER_EXPECT_TRUE( mat[1] == float4( 4, 5, 6, 7 ) );
	TEMPER_EXPECT_TRUE( mat[2] == float4( 8, 9, 10, 11 ) );

	// all values filled
	mat = float3x4(
		12, 11, 10, 9, 
		8, 7, 6, 5, 
		4, 3, 2, 1
	);
	TEMPER_EXPECT_TRUE( mat[0] == float4( 12, 11, 10, 9 ) );
	TEMPER_EXPECT_TRUE( mat[1] == float4( 8, 7, 6, 5 ) );
	TEMPER_EXPECT_TRUE( mat[2] == float4( 4, 3, 2, 1 ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArray_float3x4 ) {
	float3x4 mat;

	TEMPER_EXPECT_TRUE( mat[0] == float4( 1.000000f, 0.000000f, 0.000000f, 0.000000f ) );
	TEMPER_EXPECT_TRUE( mat[1] == float4( 0.000000f, 1.000000f, 0.000000f, 0.000000f ) );
	TEMPER_EXPECT_TRUE( mat[2] == float4( 0.000000f, 0.000000f, 1.000000f, 0.000000f ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticAddition_float3x4 ) {
	float3x4 answer = float3x4(
		7.000000f, 7.000000f, 7.000000f, 7.000000f,
		8.000000f, 8.000000f, 8.000000f, 8.000000f,
		15.000000f, 15.000000f, 15.000000f, 15.000000f
	);

	float3x4 a = float3x4(
		6.000000f, 6.000000f, 6.000000f, 6.000000f,
		6.000000f, 6.000000f, 6.000000f, 6.000000f,
		12.000000f, 12.000000f, 12.000000f, 12.000000f
	);
	float3x4 b = float3x4(
		1.000000f, 1.000000f, 1.000000f, 1.000000f,
		2.000000f, 2.000000f, 2.000000f, 2.000000f,
		3.000000f, 3.000000f, 3.000000f, 3.000000f
	);
	float3x4 c = a + b;

	TEMPER_EXPECT_TRUE( c == answer );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticSubtraction_float3x4 ) {
	float3x4 answer = float3x4(
		5.000000f, 5.000000f, 5.000000f, 5.000000f,
		4.000000f, 4.000000f, 4.000000f, 4.000000f,
		9.000000f, 9.000000f, 9.000000f, 9.000000f
	);

	float3x4 a = float3x4(
		6.000000f, 6.000000f, 6.000000f, 6.000000f,
		6.000000f, 6.000000f, 6.000000f, 6.000000f,
		12.000000f, 12.000000f, 12.000000f, 12.000000f
	);
	float3x4 b = float3x4(
		1.000000f, 1.000000f, 1.000000f, 1.000000f,
		2.000000f, 2.000000f, 2.000000f, 2.000000f,
		3.000000f, 3.000000f, 3.000000f, 3.000000f
	);
	float3x4 c = a - b;

	TEMPER_EXPECT_TRUE( c == answer );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticMultiplication_float3x4 ) {
	float3x3 answer = float3x3(
		72.000000f, 72.000000f, 72.000000f,
		72.000000f, 72.000000f, 72.000000f,
		144.000000f, 144.000000f, 144.000000f
	);

	float3x4 a = float3x4(
		6.000000f, 6.000000f, 6.000000f, 6.000000f,
		6.000000f, 6.000000f, 6.000000f, 6.000000f,
		12.000000f, 12.000000f, 12.000000f, 12.000000f
	);
	float4x3 b = float4x3(
		1.000000f, 1.000000f, 1.000000f,
		2.000000f, 2.000000f, 2.000000f,
		3.000000f, 3.000000f, 3.000000f,
		6.000000f, 6.000000f, 6.000000f
	);
	float3x3 c = a * b;

	TEMPER_EXPECT_TRUE( c == answer );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticDivision_float3x4 ) {
	float3x4 answer = float3x4(
		6.000000f, 6.000000f, 6.000000f, 6.000000f,
		3.000000f, 3.000000f, 3.000000f, 3.000000f,
		4.000000f, 4.000000f, 4.000000f, 4.000000f
	);

	float3x4 a = float3x4(
		6.000000f, 6.000000f, 6.000000f, 6.000000f,
		6.000000f, 6.000000f, 6.000000f, 6.000000f,
		12.000000f, 12.000000f, 12.000000f, 12.000000f
	);
	float3x4 b = float3x4(
		1.000000f, 1.000000f, 1.000000f, 1.000000f,
		2.000000f, 2.000000f, 2.000000f, 2.000000f,
		3.000000f, 3.000000f, 3.000000f, 3.000000f
	);
	float3x4 c = a / b;

	TEMPER_EXPECT_TRUE( c == answer );

	TEMPER_PASS();
}

TEMPER_TEST( TestRelational_float3x4 ) {
	float3x4 mat0 = float3x4(
		1.000000f, 1.000000f, 1.000000f, 1.000000f,
		1.000000f, 1.000000f, 1.000000f, 1.000000f,
		1.000000f, 1.000000f, 1.000000f, 1.000000f
	);
	float3x4 mat1 = float3x4(
		2.000000f, 2.000000f, 2.000000f, 2.000000f,
		2.000000f, 2.000000f, 2.000000f, 2.000000f,
		2.000000f, 2.000000f, 2.000000f, 2.000000f
	);
	float3x4 mat2 = float3x4(
		3.000000f, 3.000000f, 3.000000f, 3.000000f,
		3.000000f, 3.000000f, 3.000000f, 3.000000f,
		3.000000f, 3.000000f, 3.000000f, 3.000000f
	);
	float3x4 mat3 = float3x4(
		4.000000f, 4.000000f, 4.000000f, 4.000000f,
		4.000000f, 4.000000f, 4.000000f, 4.000000f,
		4.000000f, 4.000000f, 4.000000f, 4.000000f
	);

	bool3x4 test0 = mat0 <= mat0;
	bool3x4 test1 = mat0 >= mat0;
	bool3x4 test2 = mat0 < mat1;

	bool3x4 test3 = mat1 <= mat1;
	bool3x4 test4 = mat1 >= mat1;
	bool3x4 test5 = mat1 < mat2;
	bool3x4 test6 = mat1 > mat0;

	bool3x4 test7 = mat2 <= mat2;
	bool3x4 test8 = mat2 >= mat2;
	bool3x4 test9 = mat2 < mat3;
	bool3x4 test10 = mat2 > mat1;

	bool3x4 test11 = mat3 <= mat3;
	bool3x4 test12 = mat3 >= mat3;
	bool3x4 test13 = mat3 > mat2;

	TEMPER_EXPECT_TRUE( test0 == bool3x4(
		true, true, true, true,
		true, true, true, true,
		true, true, true, true
	) );

	TEMPER_EXPECT_TRUE( test1 == bool3x4(
		true, true, true, true,
		true, true, true, true,
		true, true, true, true
	) );

	TEMPER_EXPECT_TRUE( test2 == bool3x4(
		true, true, true, true,
		true, true, true, true,
		true, true, true, true
	) );

	TEMPER_EXPECT_TRUE( test3 == bool3x4(
		true, true, true, true,
		true, true, true, true,
		true, true, true, true
	) );

	TEMPER_EXPECT_TRUE( test4 == bool3x4(
		true, true, true, true,
		true, true, true, true,
		true, true, true, true
	) );

	TEMPER_EXPECT_TRUE( test5 == bool3x4(
		true, true, true, true,
		true, true, true, true,
		true, true, true, true
	) );

	TEMPER_EXPECT_TRUE( test6 == bool3x4(
		true, true, true, true,
		true, true, true, true,
		true, true, true, true
	) );

	TEMPER_EXPECT_TRUE( test7 == bool3x4(
		true, true, true, true,
		true, true, true, true,
		true, true, true, true
	) );

	TEMPER_EXPECT_TRUE( test8 == bool3x4(
		true, true, true, true,
		true, true, true, true,
		true, true, true, true
	) );

	TEMPER_EXPECT_TRUE( test9 == bool3x4(
		true, true, true, true,
		true, true, true, true,
		true, true, true, true
	) );

	TEMPER_EXPECT_TRUE( test10 == bool3x4(
		true, true, true, true,
		true, true, true, true,
		true, true, true, true
	) );

	TEMPER_EXPECT_TRUE( test11 == bool3x4(
		true, true, true, true,
		true, true, true, true,
		true, true, true, true
	) );

	TEMPER_EXPECT_TRUE( test12 == bool3x4(
		true, true, true, true,
		true, true, true, true,
		true, true, true, true
	) );

	TEMPER_EXPECT_TRUE( test13 == bool3x4(
		true, true, true, true,
		true, true, true, true,
		true, true, true, true
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestIdentity_float3x4 ) {
	float3x4 id = float3x4(
		1.000000f, 0.000000f, 0.000000f, 0.000000f,
		0.000000f, 1.000000f, 0.000000f, 0.000000f,
		0.000000f, 0.000000f, 1.000000f, 0.000000f
	);

	float3x4 mat;
	TEMPER_EXPECT_TRUE( mat == id );

	identity( mat );
	TEMPER_EXPECT_TRUE( mat == id );

	TEMPER_PASS();
}

TEMPER_TEST( TestTranspose_float3x4 ) {
	float3x4 mat = float3x4(
		0.000000f, 1.000000f, 2.000000f, 3.000000f,
		4.000000f, 5.000000f, 6.000000f, 7.000000f,
		8.000000f, 9.000000f, 10.000000f, 11.000000f
	);
	float4x3 trans = transpose( mat );

	TEMPER_EXPECT_TRUE( trans == float4x3(
		0.000000f, 4.000000f, 8.000000f,
		1.000000f, 5.000000f, 9.000000f,
		2.000000f, 6.000000f, 10.000000f,
		3.000000f, 7.000000f, 11.000000f
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestTranslate_float3x4 ) {
	float3x4 mat;
	float3x4 translated = float3x4(
		1.000000f, 0.000000f, 0.000000f, 2.000000f,
		0.000000f, 1.000000f, 0.000000f, 3.000000f,
		0.000000f, 0.000000f, 1.000000f, 4.000000f
	);

	float3 translation = float3( 2.000000f, 3.000000f, 4.000000f );
	mat = translate( mat, translation );

	TEMPER_EXPECT_TRUE( mat == translated );

	TEMPER_PASS();
}

TEMPER_TEST( TestScale_float3x4 ) {
	float3x4 mat;
	float3x4 scaled = scale( mat, float3( 2.000000f, 2.000000f, 2.000000f ) );

	TEMPER_EXPECT_TRUE( scaled == float3x4(
		2.000000f, 0.000000f, 0.000000f, 0.000000f,
		0.000000f, 2.000000f, 0.000000f, 0.000000f,
		0.000000f, 0.000000f, 2.000000f, 0.000000f
	) );

	TEMPER_PASS();
}

TEMPER_SUITE( Test_float3x4 ) {
	TEMPER_RUN_TEST( TestAssignment_float3x4 );

	TEMPER_RUN_TEST( TestArithmeticAddition_float3x4 );
	TEMPER_RUN_TEST( TestArithmeticSubtraction_float3x4 );
	TEMPER_RUN_TEST( TestArithmeticMultiplication_float3x4 );
	TEMPER_RUN_TEST( TestArithmeticDivision_float3x4 );

	TEMPER_RUN_TEST( TestRelational_float3x4 );

	TEMPER_RUN_TEST( TestArray_float3x4 );

	TEMPER_RUN_TEST( TestIdentity_float3x4 );
	TEMPER_RUN_TEST( TestTranspose_float3x4 );

	TEMPER_RUN_TEST( TestTranslate_float3x4 );
	TEMPER_RUN_TEST( TestScale_float3x4 );

};

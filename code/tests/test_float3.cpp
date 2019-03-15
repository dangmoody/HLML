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

#include "../../code/out/gen/hlml_functions_vector.h"

#include <temper/temper.h>

// also tests equality operators
TEMPER_TEST( TestAssignment_float3 ) {
	float3 a;

	a = float3( 1.000000f );
	TEMPER_EXPECT_TRUE( a == float3( 1.000000f ) );
	TEMPER_EXPECT_TRUE( a != float3( 0.000000f, 1.000000f, 2.000000f ) );

	a = float3( 0.000000f, 1.000000f, 2.000000f );
	TEMPER_EXPECT_TRUE( a == float3( 0.000000f, 1.000000f, 2.000000f ) );
	TEMPER_EXPECT_TRUE( a != float3( 1.000000f ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticAddition_float3 ) {
	float3 a  = float3( 6.000000f );
	float3 b  = float3( 2.000000f, 3.000000f, 4.000000f );

	float3 c = a + b;

	TEMPER_EXPECT_TRUE( c == float3( 8.000000f, 9.000000f, 10.000000f ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticSubtraction_float3 ) {
	float3 a  = float3( 6.000000f );
	float3 b  = float3( 2.000000f, 3.000000f, 4.000000f );

	float3 c = a - b;

	TEMPER_EXPECT_TRUE( c == float3( 4.000000f, 3.000000f, 2.000000f ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticMultiplication_float3 ) {
	float3 a  = float3( 6.000000f );
	float3 b  = float3( 2.000000f, 3.000000f, 4.000000f );

	float3 c = a * b;

	TEMPER_EXPECT_TRUE( c == float3( 12.000000f, 18.000000f, 24.000000f ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticDivision_float3 ) {
	float3 a  = float3( 6.000000f );
	float3 b  = float3( 2.000000f, 2.000000f, 3.000000f );

	float3 c = a / b;

	TEMPER_EXPECT_TRUE( c == float3( 3.000000f, 3.000000f, 2.000000f ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArray_float3 ) {
	float3 a = float3( 0.000000f, 1.000000f, 2.000000f );

	TEMPER_EXPECT_TRUE( a[0] == 0.000000f );
	TEMPER_EXPECT_TRUE( a[1] == 1.000000f );
	TEMPER_EXPECT_TRUE( a[2] == 2.000000f );

	TEMPER_PASS();
}

TEMPER_TEST( TestRelational_float3 ) {
	float3 vec0 = float3( 0.000000f, 0.000000f, 0.000000f );
	float3 vec1 = float3( 1.000000f, 1.000000f, 1.000000f );
	float3 vec2 = float3( 2.000000f, 2.000000f, 2.000000f );

	bool3 test0 = vec0 <= vec0;
	bool3 test1 = vec0 >= vec0;
	bool3 test2 = vec0 < vec1;

	bool3 test3 = vec1 <= vec1;
	bool3 test4 = vec1 >= vec1;
	bool3 test5 = vec1 < vec2;
	bool3 test6 = vec1 > vec0;

	bool3 test7 = vec2 <= vec2;
	bool3 test8 = vec2 >= vec2;
	bool3 test9 = vec2 > vec1;

	TEMPER_EXPECT_TRUE( test0 == bool3( true ) );
	TEMPER_EXPECT_TRUE( test1 == bool3( true ) );
	TEMPER_EXPECT_TRUE( test2 == bool3( true ) );
	TEMPER_EXPECT_TRUE( test3 == bool3( true ) );
	TEMPER_EXPECT_TRUE( test4 == bool3( true ) );
	TEMPER_EXPECT_TRUE( test5 == bool3( true ) );
	TEMPER_EXPECT_TRUE( test6 == bool3( true ) );
	TEMPER_EXPECT_TRUE( test7 == bool3( true ) );
	TEMPER_EXPECT_TRUE( test8 == bool3( true ) );
	TEMPER_EXPECT_TRUE( test9 == bool3( true ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestLength_float3 ) {
	float3 vec = float3( 2.000000f );

	TEMPER_EXPECT_TRUE( floateq( lengthsqr( vec ), 12.0f ) );
	TEMPER_EXPECT_TRUE( floateq( length( vec ), 3.46410161514f ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestNormalized_float3 ) {
	float3 vec = float3( 2.000000f, 3.000000f, 4.000000f );
	vec = normalized( vec );

	TEMPER_EXPECT_TRUE( length( vec ) == 1.000000f );

	TEMPER_PASS();
}

TEMPER_TEST( TestDot_float3 ) {
	float3 a = float3( 0.000000f, 0.000000f, 1.000000f );
	float3 b = float3( 0.000000f, 0.000000f, -1.000000f );

	TEMPER_EXPECT_TRUE( dot( a, b ) == -1.0f );

	TEMPER_PASS();
}

TEMPER_TEST( TestCross_float3 ) {
	float3 left = float3( -1.000000f, 0.000000f, 0.000000f );
	float3 forward = float3( 0.000000f, 0.000000f, 1.000000f );
	float3 up = float3( 0.000000f, 1.000000f, 0.000000f );

	TEMPER_EXPECT_TRUE( cross( left, forward ) == up );

	TEMPER_PASS();
}

TEMPER_TEST( TestAngle_float3 ) {
	float3 right = float3( 1.000000f, 0.000000f, 0.000000f );
	float3 up = float3( 0.000000f, 1.000000f, 0.000000f );
	float answer = angle( up, right );

	TEMPER_EXPECT_TRUE( floateq( answer, 90.000000f ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestSaturate_float3 ) {
	float3 answer = float3( 0.000000f, 1.000000f, 1.000000f );

	float3 vec = float3( -1.000000f, 2.000000f, 4.000000f );
	float3 clamped = saturate( vec );

	TEMPER_EXPECT_TRUE( clamped == answer );

	TEMPER_PASS();
}

TEMPER_TEST( TestLerp_float3 ) {
	float3 answer = float3( 0.500000f, 0.500000f, 0.000000f );

	float3 a = float3( 0.000000f, 1.000000f, 0.000000f );
	float3 b = float3( 1.000000f, 0.000000f, 0.000000f );
	float3 lerped = lerp( a, b, 0.500000f );

	TEMPER_EXPECT_TRUE( lerped == answer );

	TEMPER_PASS();
}

TEMPER_SUITE( Test_float3 ) {
	TEMPER_RUN_TEST( TestAssignment_float3 );
	TEMPER_RUN_TEST( TestArray_float3 );

	TEMPER_RUN_TEST( TestArithmeticAddition_float3 );
	TEMPER_RUN_TEST( TestArithmeticSubtraction_float3 );
	TEMPER_RUN_TEST( TestArithmeticMultiplication_float3 );
	TEMPER_RUN_TEST( TestArithmeticDivision_float3 );

	TEMPER_RUN_TEST( TestRelational_float3 );

	TEMPER_RUN_TEST( TestLength_float3 );
	TEMPER_RUN_TEST( TestNormalized_float3 );
	TEMPER_RUN_TEST( TestDot_float3 );
	TEMPER_RUN_TEST( TestCross_float3 );
	TEMPER_RUN_TEST( TestAngle_float3 );
	TEMPER_RUN_TEST( TestSaturate_float3 );
	TEMPER_RUN_TEST( TestLerp_float3 );
};

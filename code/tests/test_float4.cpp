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
TEMPER_TEST( TestAssignment_float4 )
{
	float4 a;

	a = float4( 1.000000f );
	TEMPER_EXPECT_TRUE( a == float4( 1.000000f ) );
	TEMPER_EXPECT_TRUE( a != float4( 0.000000f, 1.000000f, 2.000000f, 3.000000f ) );

	a = float4( 0.000000f, 1.000000f, 2.000000f, 3.000000f );
	TEMPER_EXPECT_TRUE( a == float4( 0.000000f, 1.000000f, 2.000000f, 3.000000f ) );
	TEMPER_EXPECT_TRUE( a != float4( 1.000000f ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArray_float4 )
{
	float4 a = float4( 0.000000f, 1.000000f, 2.000000f, 3.000000f );

	TEMPER_EXPECT_TRUE( a[0] == 0.000000f );
	TEMPER_EXPECT_TRUE( a[1] == 1.000000f );
	TEMPER_EXPECT_TRUE( a[2] == 2.000000f );
	TEMPER_EXPECT_TRUE( a[3] == 3.000000f );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticAddition_float4 )
{
	float4 a = float4( 6.000000f );
	float4 b = float4( 2.000000f, 3.000000f, 4.000000f, 5.000000f );

	float4 c = a + b;

	TEMPER_EXPECT_TRUE( c == float4( 8.000000f, 9.000000f, 10.000000f, 11.000000f ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticSubtraction_float4 )
{
	float4 a = float4( 6.000000f );
	float4 b = float4( 2.000000f, 3.000000f, 4.000000f, 5.000000f );

	float4 c = a - b;

	TEMPER_EXPECT_TRUE( c == float4( 4.000000f, 3.000000f, 2.000000f, 1.000000f ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticMultiplication_float4 )
{
	float4 a = float4( 6.000000f );
	float4 b = float4( 2.000000f, 3.000000f, 4.000000f, 5.000000f );

	float4 c = a * b;

	TEMPER_EXPECT_TRUE( c == float4( 12.000000f, 18.000000f, 24.000000f, 30.000000f ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticDivision_float4 )
{
	float4 a = float4( 6.000000f );
	float4 b = float4( 2.000000f, 2.000000f, 3.000000f, 6.000000f );

	float4 c = a / b;

	TEMPER_EXPECT_TRUE( c == float4( 3.000000f, 3.000000f, 2.000000f, 1.000000f ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestIncrement_float4 )
{
	float4 vec;

	// prefix
	vec = float4( 0.000000f, 0.000000f, 0.000000f, 0.000000f );
	++vec;
	TEMPER_EXPECT_TRUE( vec == float4( 1.000000f, 1.000000f, 1.000000f, 1.000000f ) );

	// postfix
	vec = float4( 0.000000f, 0.000000f, 0.000000f, 0.000000f );
	vec++;
	TEMPER_EXPECT_TRUE( vec == float4( 1.000000f, 1.000000f, 1.000000f, 1.000000f ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestDecrement_float4 )
{
	float4 vec;

	// prefix
	vec = float4( 1.000000f, 1.000000f, 1.000000f, 1.000000f );
	--vec;
	TEMPER_EXPECT_TRUE( vec == float4( 0.000000f, 0.000000f, 0.000000f, 0.000000f ) );

	// postfix
	vec = float4( 1.000000f, 1.000000f, 1.000000f, 1.000000f );
	vec--;
	TEMPER_EXPECT_TRUE( vec == float4( 0.000000f, 0.000000f, 0.000000f, 0.000000f ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestRelational_float4 )
{
	bool4 allTrue = bool4( true );

	float4 vec0 = float4( 0.000000f );
	float4 vec1 = float4( 1.000000f );
	float4 vec2 = float4( 2.000000f );
	float4 vec3 = float4( 3.000000f );

	bool4 test0  = vec0 <= vec0;
	bool4 test1  = vec0 >= vec0;
	bool4 test2  = vec0 <  vec1;
	bool4 test3  = vec0 <  vec2;
	bool4 test4  = vec0 <  vec3;

	bool4 test5  = vec1 >  vec0;
	bool4 test6  = vec1 <= vec1;
	bool4 test7  = vec1 >= vec1;
	bool4 test8  = vec1 <  vec2;
	bool4 test9  = vec1 <  vec3;

	bool4 test10 = vec2 >  vec0;
	bool4 test11 = vec2 >  vec1;
	bool4 test12 = vec2 <= vec2;
	bool4 test13 = vec2 >= vec2;
	bool4 test14 = vec2 <  vec3;

	bool4 test15 = vec3 >  vec0;
	bool4 test16 = vec3 >  vec1;
	bool4 test17 = vec3 >  vec2;
	bool4 test18 = vec3 <= vec3;
	bool4 test19 = vec3 >= vec3;

	TEMPER_EXPECT_TRUE( test0  == allTrue );
	TEMPER_EXPECT_TRUE( test1  == allTrue );
	TEMPER_EXPECT_TRUE( test2  == allTrue );
	TEMPER_EXPECT_TRUE( test3  == allTrue );
	TEMPER_EXPECT_TRUE( test4  == allTrue );

	TEMPER_EXPECT_TRUE( test5  == allTrue );
	TEMPER_EXPECT_TRUE( test6  == allTrue );
	TEMPER_EXPECT_TRUE( test7  == allTrue );
	TEMPER_EXPECT_TRUE( test8  == allTrue );
	TEMPER_EXPECT_TRUE( test9  == allTrue );

	TEMPER_EXPECT_TRUE( test10 == allTrue );
	TEMPER_EXPECT_TRUE( test11 == allTrue );
	TEMPER_EXPECT_TRUE( test12 == allTrue );
	TEMPER_EXPECT_TRUE( test13 == allTrue );
	TEMPER_EXPECT_TRUE( test14 == allTrue );

	TEMPER_EXPECT_TRUE( test15 == allTrue );
	TEMPER_EXPECT_TRUE( test16 == allTrue );
	TEMPER_EXPECT_TRUE( test17 == allTrue );
	TEMPER_EXPECT_TRUE( test18 == allTrue );
	TEMPER_EXPECT_TRUE( test19 == allTrue );

	TEMPER_PASS();
}

TEMPER_TEST( TestLength_float4 )
{
	float4 vec = float4( 2.000000f );

	TEMPER_EXPECT_TRUE( floateq( lengthsqr( vec ), 16.0f ) );
	TEMPER_EXPECT_TRUE( floateq( length( vec ), 4.0f ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestNormalized_float4 )
{
	float4 vec = float4( 2.000000f, 3.000000f, 4.000000f, 5.000000f );
	vec = normalized( vec );

	TEMPER_EXPECT_TRUE( length( vec ) == 1.000000f );

	TEMPER_PASS();
}

TEMPER_TEST( TestDot_float4 )
{
	float4 a = float4( 0.000000f, 1.000000f, 0.000000f, 0.000000f );
	float4 b = float4( 0.000000f, -1.000000f, 0.000000f, 0.000000f );

	TEMPER_EXPECT_TRUE( floateq( dot( a, b ), -1.000000f ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestCross_float4 )
{
	float4 left = float4( -1.000000f, 0.000000f, 0.000000f, 0.000000f );
	float4 forward = float4( 0.000000f, 0.000000f, 1.000000f, 0.000000f );
	float4 up = float4( 0.000000f, 1.000000f, 0.000000f, 0.000000f );

	TEMPER_EXPECT_TRUE( cross( left, forward ) == up );

	TEMPER_PASS();
}

TEMPER_TEST( TestAngle_float4 )
{
	float4 right = float4( 1.000000f, 0.000000f, 0.000000f, 0.000000f );
	float4 up =    float4( 0.000000f, 1.000000f, 0.000000f, 0.000000f );
	float answer = angle( up, right );

	TEMPER_EXPECT_TRUE( floateq( answer, 90.000000f ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestSaturate_float4 )
{
	float4 answer = float4( 0.000000f, 1.000000f, 1.000000f, 1.000000f );

	float4 vec = float4( -1.000000f, 2.000000f, 4.000000f, 6.000000f );
	float4 clamped = saturate( vec );

	TEMPER_EXPECT_TRUE( clamped == answer );

	TEMPER_PASS();
}

TEMPER_TEST( TestLerp_float4 )
{
	float4 answer = float4( 0.500000f, 0.500000f, 0.000000f, 0.000000f );

	float4 a = float4( 0.000000f, 1.000000f, 0.000000f, 0.000000f );
	float4 b = float4( 1.000000f, 0.000000f, 0.000000f, 0.000000f );
	float4 lerped = lerp( a, b, 0.500000f );

	TEMPER_EXPECT_TRUE( lerped == answer );

	TEMPER_PASS();
}

TEMPER_TEST( TestSmoothstep_float4 )
{
	float4 answerInRangeSmoothstep   = float4( 0.104000f, 0.104000f, 0.104000f, 0.104000f );
	float4 answerClampedSmoothstep   = float4( 1.000000f, 1.000000f, 1.000000f, 1.000000f );
	float4 answerInRangeSmootherstep = float4( 0.057920f, 0.057920f, 0.057920f, 0.057920f );
	float4 answerClampedSmootherstep = float4( 1.000000f, 1.000000f, 1.000000f, 1.000000f );
	float4 answer;

	float4 low  = float4( 0.000000f, 0.000000f, 0.000000f, 0.000000f );
	float4 high = float4( 1.000000f, 1.000000f, 1.000000f, 1.000000f );

	answer = smoothstep( low, high, float4( 0.200000f, 0.200000f, 0.200000f, 0.200000f ) );
	TEMPER_EXPECT_TRUE( answer == answerInRangeSmoothstep );

	answer = smoothstep( low, high, float4( 1.200000f, 1.200000f, 1.200000f, 1.200000f ) );
	TEMPER_EXPECT_TRUE( answer == answerClampedSmoothstep );

	answer = smootherstep( low, high, float4( 0.200000f, 0.200000f, 0.200000f, 0.200000f ) );
	TEMPER_EXPECT_TRUE( answer == answerInRangeSmootherstep );

	answer = smootherstep( low, high, float4( 1.200000f, 1.200000f, 1.200000f, 1.200000f ) );
	TEMPER_EXPECT_TRUE( answer == answerClampedSmootherstep );

	TEMPER_PASS();
}

TEMPER_SUITE( Test_float4 )
{
	TEMPER_RUN_TEST( TestAssignment_float4 );
	TEMPER_RUN_TEST( TestArray_float4 );
	TEMPER_RUN_TEST( TestArithmeticAddition_float4 );
	TEMPER_RUN_TEST( TestArithmeticSubtraction_float4 );
	TEMPER_RUN_TEST( TestArithmeticMultiplication_float4 );
	TEMPER_RUN_TEST( TestArithmeticDivision_float4 );
	TEMPER_RUN_TEST( TestIncrement_float4 );
	TEMPER_RUN_TEST( TestDecrement_float4 );
	TEMPER_RUN_TEST( TestRelational_float4 );
	TEMPER_RUN_TEST( TestRelational_float4 );
	TEMPER_RUN_TEST( TestLength_float4 );
	TEMPER_RUN_TEST( TestNormalized_float4 );
	TEMPER_RUN_TEST( TestDot_float4 );
	TEMPER_RUN_TEST( TestCross_float4 );
	TEMPER_RUN_TEST( TestAngle_float4 );
	TEMPER_RUN_TEST( TestSaturate_float4 );
	TEMPER_RUN_TEST( TestLerp_float4 );
	TEMPER_RUN_TEST( TestSmoothstep_float4 );
}

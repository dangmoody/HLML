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
TEMPER_TEST( TestAssignment_int2 )
{
	int2 a;

	a = int2( 1 );
	TEMPER_EXPECT_TRUE( a == int2( 1 ) );
	TEMPER_EXPECT_TRUE( a != int2( 0, 1 ) );

	a = int2( 0, 1 );
	TEMPER_EXPECT_TRUE( a == int2( 0, 1 ) );
	TEMPER_EXPECT_TRUE( a != int2( 1 ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArray_int2 )
{
	int2 a = int2( 0, 1 );

	TEMPER_EXPECT_TRUE( a[0] == 0 );
	TEMPER_EXPECT_TRUE( a[1] == 1 );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticAddition_int2 )
{
	int2 a = int2( 6 );
	int2 b = int2( 2, 3 );

	int2 c = a + b;

	TEMPER_EXPECT_TRUE( c == int2( 8, 9 ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticSubtraction_int2 )
{
	int2 a = int2( 6 );
	int2 b = int2( 2, 3 );

	int2 c = a - b;

	TEMPER_EXPECT_TRUE( c == int2( 4, 3 ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticMultiplication_int2 )
{
	int2 a = int2( 6 );
	int2 b = int2( 2, 3 );

	int2 c = a * b;

	TEMPER_EXPECT_TRUE( c == int2( 12, 18 ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticDivision_int2 )
{
	int2 a = int2( 6 );
	int2 b = int2( 2, 2 );

	int2 c = a / b;

	TEMPER_EXPECT_TRUE( c == int2( 3, 3 ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestIncrement_int2 )
{
	int2 vec;

	// prefix
	vec = int2( 0, 0 );
	++vec;
	TEMPER_EXPECT_TRUE( vec == int2( 1, 1 ) );

	// postfix
	vec = int2( 0, 0 );
	vec++;
	TEMPER_EXPECT_TRUE( vec == int2( 1, 1 ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestDecrement_int2 )
{
	int2 vec;

	// prefix
	vec = int2( 1, 1 );
	--vec;
	TEMPER_EXPECT_TRUE( vec == int2( 0, 0 ) );

	// postfix
	vec = int2( 1, 1 );
	vec--;
	TEMPER_EXPECT_TRUE( vec == int2( 0, 0 ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestRelational_int2 )
{
	bool2 allTrue = bool2( true );

	int2 vec0 = int2( 0 );
	int2 vec1 = int2( 1 );
	int2 vec2 = int2( 2 );
	int2 vec3 = int2( 3 );

	bool2 test0  = vec0 <= vec0;
	bool2 test1  = vec0 >= vec0;
	bool2 test2  = vec0 <  vec1;
	bool2 test3  = vec0 <  vec2;
	bool2 test4  = vec0 <  vec3;

	bool2 test5  = vec1 >  vec0;
	bool2 test6  = vec1 <= vec1;
	bool2 test7  = vec1 >= vec1;
	bool2 test8  = vec1 <  vec2;
	bool2 test9  = vec1 <  vec3;

	bool2 test10 = vec2 >  vec0;
	bool2 test11 = vec2 >  vec1;
	bool2 test12 = vec2 <= vec2;
	bool2 test13 = vec2 >= vec2;
	bool2 test14 = vec2 <  vec3;

	bool2 test15 = vec3 >  vec0;
	bool2 test16 = vec3 >  vec1;
	bool2 test17 = vec3 >  vec2;
	bool2 test18 = vec3 <= vec3;
	bool2 test19 = vec3 >= vec3;

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

TEMPER_TEST( TestBitwise_And_int2 )
{
	int2 a  = int2( 21, 21 );
	int2 b  = int2( 7, 7 );

	int2 answer = a & b;

	TEMPER_EXPECT_TRUE( answer == int2( 5, 5 ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestBitwise_Or_int2 )
{
	int2 a  = int2( 21, 21 );
	int2 b  = int2( 7, 7 );

	int2 answer = a | b;

	TEMPER_EXPECT_TRUE( answer == int2( 23, 23 ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestBitwise_Xor_int2 )
{
	int2 a  = int2( 21, 21 );
	int2 b  = int2( 7, 7 );

	int2 answer = a ^ b;

	TEMPER_EXPECT_TRUE( answer == int2( 18, 18 ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestBitwise_ShiftLeft_int2 )
{
	int2 a  = int2( 1, 1 );
	int2 b  = int2( 2, 2 );

	int2 answer = a << b;

	TEMPER_EXPECT_TRUE( answer == int2( 4, 4 ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestBitwise_ShiftRight_int2 )
{
	int2 a  = int2( 16, 16 );
	int2 b  = int2( 4, 4 );

	int2 answer = a >> b;

	TEMPER_EXPECT_TRUE( answer == int2( 1, 1 ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestBitwiseUnary_int2 )
{
	int2 a = int2( 0, 0 );

	int2 answer = ~a;

	TEMPER_EXPECT_TRUE( answer == int2( (int32_t) -1 ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestLength_int2 )
{
	int2 vec = int2( 2 );

	TEMPER_EXPECT_TRUE( floateq( lengthsqr( vec ), 8.0f ) );
	TEMPER_EXPECT_TRUE( floateq( length( vec ), 2.82842712475f ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestDot_int2 )
{
	// scalar
	int2 a = int2( 0, 1 );
	int2 b = int2( 0, -1 );

	TEMPER_EXPECT_TRUE( dot( a, b ) == -1 );

	TEMPER_PASS();
}

TEMPER_TEST( TestDistance_int2 )
{
	float answerDistanceSqr = 104.000000f;
	float answerDistance    = 10.198039f;

	int2 a = int2( 7, 4 );
	int2 b = int2( 17, 6 );

	float distSqr = distancesqr( a, b );
	float dist    = distance( a, b );

	TEMPER_EXPECT_TRUE( floateq( distSqr, answerDistanceSqr ) );
	TEMPER_EXPECT_TRUE( floateq( dist, answerDistance ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestStep_int2 )
{
	int2 answer = int2( 1, 1 );

	int2 a = int2( 1, 2 );
	int2 b = int2( 4, 3 );

	TEMPER_EXPECT_TRUE( step( a, b ) == answer );

	TEMPER_PASS();
}

TEMPER_SUITE( Test_int2 )
{
	TEMPER_RUN_TEST( TestAssignment_int2 );
	TEMPER_RUN_TEST( TestArray_int2 );
	TEMPER_RUN_TEST( TestArithmeticAddition_int2 );
	TEMPER_RUN_TEST( TestArithmeticSubtraction_int2 );
	TEMPER_RUN_TEST( TestArithmeticMultiplication_int2 );
	TEMPER_RUN_TEST( TestArithmeticDivision_int2 );
	TEMPER_RUN_TEST( TestIncrement_int2 );
	TEMPER_RUN_TEST( TestDecrement_int2 );
	TEMPER_RUN_TEST( TestRelational_int2 );
	TEMPER_RUN_TEST( TestRelational_int2 );
	TEMPER_RUN_TEST( TestBitwise_And_int2 );
	TEMPER_RUN_TEST( TestBitwise_Or_int2 );
	TEMPER_RUN_TEST( TestBitwise_Xor_int2 );
	TEMPER_RUN_TEST( TestBitwise_ShiftLeft_int2 );
	TEMPER_RUN_TEST( TestBitwise_ShiftRight_int2 );
	TEMPER_RUN_TEST( TestBitwiseUnary_int2 );
	TEMPER_RUN_TEST( TestLength_int2 );
	TEMPER_RUN_TEST( TestDot_int2 );
	TEMPER_RUN_TEST( TestDistance_int2 );
	TEMPER_RUN_TEST( TestStep_int2 );
}

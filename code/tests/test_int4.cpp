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
TEMPER_TEST( TestAssignment_int4 )
{
	int4 a;

	a = int4( 1 );
	TEMPER_EXPECT_TRUE( a == int4( 1 ) );
	TEMPER_EXPECT_TRUE( a != int4( 0, 1, 2, 3 ) );

	a = int4( 0, 1, 2, 3 );
	TEMPER_EXPECT_TRUE( a == int4( 0, 1, 2, 3 ) );
	TEMPER_EXPECT_TRUE( a != int4( 1 ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArray_int4 )
{
	int4 a = int4( 0, 1, 2, 3 );

	TEMPER_EXPECT_TRUE( a[0] == 0 );
	TEMPER_EXPECT_TRUE( a[1] == 1 );
	TEMPER_EXPECT_TRUE( a[2] == 2 );
	TEMPER_EXPECT_TRUE( a[3] == 3 );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticAddition_int4 )
{
	int4 a  = int4( 6 );
	int4 b  = int4( 2, 3, 4, 5 );

	int4 c = a + b;

	TEMPER_EXPECT_TRUE( c == int4( 8, 9, 10, 11 ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticSubtraction_int4 )
{
	int4 a  = int4( 6 );
	int4 b  = int4( 2, 3, 4, 5 );

	int4 c = a - b;

	TEMPER_EXPECT_TRUE( c == int4( 4, 3, 2, 1 ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticMultiplication_int4 )
{
	int4 a  = int4( 6 );
	int4 b  = int4( 2, 3, 4, 5 );

	int4 c = a * b;

	TEMPER_EXPECT_TRUE( c == int4( 12, 18, 24, 30 ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticDivision_int4 )
{
	int4 a  = int4( 6 );
	int4 b  = int4( 2, 2, 3, 6 );

	int4 c = a / b;

	TEMPER_EXPECT_TRUE( c == int4( 3, 3, 2, 1 ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestIncrement_int4 )
{
	int4 vec;

	// prefix
	vec = int4( 0, 0, 0, 0 );
	++vec;
	TEMPER_EXPECT_TRUE( vec == int4( 1, 1, 1, 1 ) );

	// postfix
	vec = int4( 0, 0, 0, 0 );
	vec++;
	TEMPER_EXPECT_TRUE( vec == int4( 1, 1, 1, 1 ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestDecrement_int4 )
{
	int4 vec;

	// prefix
	vec = int4( 1, 1, 1, 1 );
	--vec;
	TEMPER_EXPECT_TRUE( vec == int4( 0, 0, 0, 0 ) );

	// postfix
	vec = int4( 1, 1, 1, 1 );
	vec--;
	TEMPER_EXPECT_TRUE( vec == int4( 0, 0, 0, 0 ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestRelational_int4 )
{
	int4 vec0 = int4( 0, 0, 0, 0 );
	int4 vec1 = int4( 1, 1, 1, 1 );
	int4 vec2 = int4( 2, 2, 2, 2 );
	int4 vec3 = int4( 3, 3, 3, 3 );

	bool4 test0 = vec0 <= vec0;
	bool4 test1 = vec0 >= vec0;
	bool4 test2 = vec0 < vec1;

	bool4 test3 = vec1 <= vec1;
	bool4 test4 = vec1 >= vec1;
	bool4 test5 = vec1 < vec2;
	bool4 test6 = vec1 > vec0;

	bool4 test7 = vec2 <= vec2;
	bool4 test8 = vec2 >= vec2;
	bool4 test9 = vec2 < vec3;
	bool4 test10 = vec2 > vec1;

	bool4 test11 = vec3 <= vec3;
	bool4 test12 = vec3 >= vec3;
	bool4 test13 = vec3 > vec2;

	TEMPER_EXPECT_TRUE( test0 == bool4( true ) );
	TEMPER_EXPECT_TRUE( test1 == bool4( true ) );
	TEMPER_EXPECT_TRUE( test2 == bool4( true ) );
	TEMPER_EXPECT_TRUE( test3 == bool4( true ) );
	TEMPER_EXPECT_TRUE( test4 == bool4( true ) );
	TEMPER_EXPECT_TRUE( test5 == bool4( true ) );
	TEMPER_EXPECT_TRUE( test6 == bool4( true ) );
	TEMPER_EXPECT_TRUE( test7 == bool4( true ) );
	TEMPER_EXPECT_TRUE( test8 == bool4( true ) );
	TEMPER_EXPECT_TRUE( test9 == bool4( true ) );
	TEMPER_EXPECT_TRUE( test10 == bool4( true ) );
	TEMPER_EXPECT_TRUE( test11 == bool4( true ) );
	TEMPER_EXPECT_TRUE( test12 == bool4( true ) );
	TEMPER_EXPECT_TRUE( test13 == bool4( true ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestBitwise_And_int4 )
{
	int4 a  = int4( 21, 21, 21, 21 );
	int4 b  = int4( 7, 7, 7, 7 );

	int4 answer = a & b;

	TEMPER_EXPECT_TRUE( answer == int4( 5, 5, 5, 5 ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestBitwise_Or_int4 )
{
	int4 a  = int4( 21, 21, 21, 21 );
	int4 b  = int4( 7, 7, 7, 7 );

	int4 answer = a | b;

	TEMPER_EXPECT_TRUE( answer == int4( 23, 23, 23, 23 ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestBitwise_Xor_int4 )
{
	int4 a  = int4( 21, 21, 21, 21 );
	int4 b  = int4( 7, 7, 7, 7 );

	int4 answer = a ^ b;

	TEMPER_EXPECT_TRUE( answer == int4( 18, 18, 18, 18 ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestBitwise_ShiftLeft_int4 )
{
	int4 a  = int4( 1, 1, 1, 1 );
	int4 b  = int4( 2, 2, 2, 2 );

	int4 answer = a << b;

	TEMPER_EXPECT_TRUE( answer == int4( 4, 4, 4, 4 ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestBitwise_ShiftRight_int4 )
{
	int4 a  = int4( 16, 16, 16, 16 );
	int4 b  = int4( 4, 4, 4, 4 );

	int4 answer = a >> b;

	TEMPER_EXPECT_TRUE( answer == int4( 1, 1, 1, 1 ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestBitwiseUnary_int4 )
{
	int4 a = int4( 0, 0, 0, 0 );

	int4 answer = ~a;

	TEMPER_EXPECT_TRUE( answer == int4( (int32_t) -1, (int32_t) -1, (int32_t) -1, (int32_t) -1 ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestLength_int4 )
{
	int4 vec = int4( 2 );

	TEMPER_EXPECT_TRUE( floateq( lengthsqr( vec ), 16.0f ) );
	TEMPER_EXPECT_TRUE( floateq( length( vec ), 4.0f ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestDot_int4 )
{
	int4 a = int4( 0, 0, 0, 1 );
	int4 b = int4( 0, 0, 0, -1 );

	TEMPER_EXPECT_TRUE( floateq( dot( a, b ), -1.0f ) );

	TEMPER_PASS();
}

TEMPER_SUITE( Test_int4 )
{
	TEMPER_RUN_TEST( TestAssignment_int4 );
	TEMPER_RUN_TEST( TestArray_int4 );
	TEMPER_RUN_TEST( TestArithmeticAddition_int4 );
	TEMPER_RUN_TEST( TestArithmeticSubtraction_int4 );
	TEMPER_RUN_TEST( TestArithmeticMultiplication_int4 );
	TEMPER_RUN_TEST( TestArithmeticDivision_int4 );
	TEMPER_RUN_TEST( TestIncrement_int4 );
	TEMPER_RUN_TEST( TestDecrement_int4 );
	TEMPER_RUN_TEST( TestRelational_int4 );
	TEMPER_RUN_TEST( TestBitwise_And_int4 );
	TEMPER_RUN_TEST( TestBitwise_Or_int4 );
	TEMPER_RUN_TEST( TestBitwise_Xor_int4 );
	TEMPER_RUN_TEST( TestBitwise_ShiftLeft_int4 );
	TEMPER_RUN_TEST( TestBitwise_ShiftRight_int4 );
	TEMPER_RUN_TEST( TestBitwiseUnary_int4 );
	TEMPER_RUN_TEST( TestLength_int4 );
	TEMPER_RUN_TEST( TestDot_int4 );
};

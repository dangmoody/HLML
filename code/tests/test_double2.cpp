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
TEMPER_TEST( TestAssignment_double2 )
{
	double2 a;

	a = double2( 1.000000 );
	TEMPER_EXPECT_TRUE( a == double2( 1.000000 ) );
	TEMPER_EXPECT_TRUE( a != double2( 0.000000, 1.000000 ) );

	a = double2( 0.000000, 1.000000 );
	TEMPER_EXPECT_TRUE( a == double2( 0.000000, 1.000000 ) );
	TEMPER_EXPECT_TRUE( a != double2( 1.000000 ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArray_double2 )
{
	double2 a = double2( 0.000000, 1.000000 );

	TEMPER_EXPECT_TRUE( a[0] == 0.000000 );
	TEMPER_EXPECT_TRUE( a[1] == 1.000000 );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticAddition_double2 )
{
	double2 a  = double2( 6.000000 );
	double2 b  = double2( 2.000000, 3.000000 );

	double2 c = a + b;

	TEMPER_EXPECT_TRUE( c == double2( 8.000000, 9.000000 ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticSubtraction_double2 )
{
	double2 a  = double2( 6.000000 );
	double2 b  = double2( 2.000000, 3.000000 );

	double2 c = a - b;

	TEMPER_EXPECT_TRUE( c == double2( 4.000000, 3.000000 ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticMultiplication_double2 )
{
	double2 a  = double2( 6.000000 );
	double2 b  = double2( 2.000000, 3.000000 );

	double2 c = a * b;

	TEMPER_EXPECT_TRUE( c == double2( 12.000000, 18.000000 ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticDivision_double2 )
{
	double2 a  = double2( 6.000000 );
	double2 b  = double2( 2.000000, 2.000000 );

	double2 c = a / b;

	TEMPER_EXPECT_TRUE( c == double2( 3.000000, 3.000000 ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestIncrement_double2 )
{
	double2 vec;

	// prefix
	vec = double2( 0.000000, 0.000000 );
	++vec;
	TEMPER_EXPECT_TRUE( vec == double2( 1.000000, 1.000000 ) );

	// postfix
	vec = double2( 0.000000, 0.000000 );
	vec++;
	TEMPER_EXPECT_TRUE( vec == double2( 1.000000, 1.000000 ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestDecrement_double2 )
{
	double2 vec;

	// prefix
	vec = double2( 1.000000, 1.000000 );
	--vec;
	TEMPER_EXPECT_TRUE( vec == double2( 0.000000, 0.000000 ) );

	// postfix
	vec = double2( 1.000000, 1.000000 );
	vec--;
	TEMPER_EXPECT_TRUE( vec == double2( 0.000000, 0.000000 ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestRelational_double2 )
{
	double2 vec0 = double2( 0.000000, 0.000000 );
	double2 vec1 = double2( 1.000000, 1.000000 );

	bool2 test0 = vec0 <= vec0;
	bool2 test1 = vec0 >= vec0;
	bool2 test2 = vec0 < vec1;

	bool2 test3 = vec1 <= vec1;
	bool2 test4 = vec1 >= vec1;
	bool2 test5 = vec1 > vec0;

	TEMPER_EXPECT_TRUE( test0 == bool2( true ) );
	TEMPER_EXPECT_TRUE( test1 == bool2( true ) );
	TEMPER_EXPECT_TRUE( test2 == bool2( true ) );
	TEMPER_EXPECT_TRUE( test3 == bool2( true ) );
	TEMPER_EXPECT_TRUE( test4 == bool2( true ) );
	TEMPER_EXPECT_TRUE( test5 == bool2( true ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestLength_double2 )
{
	double2 vec = double2( 2.000000 );

	TEMPER_EXPECT_TRUE( doubleeq( lengthsqr( vec ), 8.0 ) );
	TEMPER_EXPECT_TRUE( doubleeq( length( vec ), 2.82842712475 ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestNormalized_double2 )
{
	double2 vec = double2( 2.000000, 3.000000 );
	vec = normalized( vec );

	TEMPER_EXPECT_TRUE( length( vec ) == 1.000000 );

	TEMPER_PASS();
}

TEMPER_TEST( TestDot_double2 )
{
	double2 a = double2( 0.000000, 1.000000 );
	double2 b = double2( 0.000000, -1.000000 );

	TEMPER_EXPECT_TRUE( dot( a, b ) == -1.0 );

	TEMPER_PASS();
}

TEMPER_TEST( TestAngle_double2 )
{
	double2 right = double2( 1.000000, 0.000000 );
	double2 up = double2( 0.000000, 1.000000 );
	double answer = angle( up, right );

	TEMPER_EXPECT_TRUE( doubleeq( answer, 90.000000 ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestDistance_double2 )
{
	double answerDistanceSqr = 104.000000;
	double answerDistance    = 10.198039;

	double2 a = double2( 7.000000, 4.000000 );
	double2 b = double2( 17.000000, 6.000000 );

	double distSqr = distancesqr( a, b );
	double dist    = distance( a, b );

	TEMPER_EXPECT_TRUE( doubleeq( distSqr, answerDistanceSqr ) );
	TEMPER_EXPECT_TRUE( doubleeq( dist, answerDistance ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestSaturate_double2 )
{
	double2 answer = double2( 0.000000, 1.000000 );

	double2 vec = double2( -1.000000, 2.000000 );
	double2 clamped = saturate( vec );

	TEMPER_EXPECT_TRUE( clamped == answer );

	TEMPER_PASS();
}

TEMPER_TEST( TestLerp_double2 )
{
	double2 answer = double2( 0.500000, 0.500000 );

	double2 a = double2( 0.000000, 1.000000 );
	double2 b = double2( 1.000000, 0.000000 );
	double2 lerped = lerp( a, b, 0.500000 );

	TEMPER_EXPECT_TRUE( lerped == answer );

	TEMPER_PASS();
}

TEMPER_TEST( TestSmoothstep_double2 )
{
	double2 answerInRangeSmoothstep   = double2( 0.104000, 0.104000 );
	double2 answerClampedSmoothstep   = double2( 1.000000, 1.000000 );
	double2 answerInRangeSmootherstep = double2( 0.057920, 0.057920 );
	double2 answerClampedSmootherstep = double2( 1.000000, 1.000000 );
	double2 answer;

	double2 low  = double2( 0.000000, 0.000000 );
	double2 high = double2( 1.000000, 1.000000 );

	answer = smoothstep( low, high, double2( 0.200000, 0.200000 ) );
	TEMPER_EXPECT_TRUE( answer == answerInRangeSmoothstep );

	answer = smoothstep( low, high, double2( 1.200000, 1.200000 ) );
	TEMPER_EXPECT_TRUE( answer == answerClampedSmoothstep );

	answer = smootherstep( low, high, double2( 0.200000, 0.200000 ) );
	TEMPER_EXPECT_TRUE( answer == answerInRangeSmootherstep );

	answer = smootherstep( low, high, double2( 1.200000, 1.200000 ) );
	TEMPER_EXPECT_TRUE( answer == answerClampedSmootherstep );

	TEMPER_PASS();
}

TEMPER_SUITE( Test_double2 )
{
	TEMPER_RUN_TEST( TestAssignment_double2 );
	TEMPER_RUN_TEST( TestArray_double2 );
	TEMPER_RUN_TEST( TestArithmeticAddition_double2 );
	TEMPER_RUN_TEST( TestArithmeticSubtraction_double2 );
	TEMPER_RUN_TEST( TestArithmeticMultiplication_double2 );
	TEMPER_RUN_TEST( TestArithmeticDivision_double2 );
	TEMPER_RUN_TEST( TestIncrement_double2 );
	TEMPER_RUN_TEST( TestDecrement_double2 );
	TEMPER_RUN_TEST( TestRelational_double2 );
	TEMPER_RUN_TEST( TestLength_double2 );
	TEMPER_RUN_TEST( TestNormalized_double2 );
	TEMPER_RUN_TEST( TestDot_double2 );
	TEMPER_RUN_TEST( TestAngle_double2 );
	TEMPER_RUN_TEST( TestDistance_double2 );
	TEMPER_RUN_TEST( TestSaturate_double2 );
	TEMPER_RUN_TEST( TestLerp_double2 );
	TEMPER_RUN_TEST( TestSmoothstep_double2 );
};

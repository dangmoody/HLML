#include "../../code/out/gen/hlml_functions_scalar.h"

#include <temper/temper.h>

TEMPER_TEST( TestFloateq_double )
{
	double a = 5.000000;
	double b = 5.000000;
	double c = 5.000020;
	double d = 5.000100;

	TEMPER_EXPECT_TRUE(  doubleeq( a, b ) );
	TEMPER_EXPECT_TRUE( !doubleeq( a, c ) );
	TEMPER_EXPECT_TRUE( !doubleeq( a, d ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestSign_double )
{
	TEMPER_EXPECT_TRUE( sign( -5.000000 ) == -1 );
	TEMPER_EXPECT_TRUE( sign( 9.000000 ) ==  1 );

	TEMPER_PASS();
}

TEMPER_TEST( TestDegreesRadians_double )
{
	double deg = 90.000000;
	double rad = 1.57079637;

	double answerRadians = radians( deg );
	double answerDegrees = degrees( rad );

	TEMPER_EXPECT_TRUE( doubleeq( answerRadians, 1.57079637 ) );
	TEMPER_EXPECT_TRUE( doubleeq( answerDegrees, 90.000000 ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestMinMax_double )
{
	double a = 5.000000;
	double b = 9.000000;

	TEMPER_EXPECT_TRUE( doubleeq( min( a, b ), a ) );
	TEMPER_EXPECT_TRUE( doubleeq( max( a, b ), b ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestClamp_double )
{
	double a;
	double low  = 1.000000;
	double high = 10.000000;

	a = clamp( 0.000000, low, high );
	TEMPER_EXPECT_TRUE( doubleeq( a, low ) );

	a = clamp( 11.000000, low, high );
	TEMPER_EXPECT_TRUE( doubleeq( a, high ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestSaturate_double )
{
	double a;

	a = saturate( -1.000000 );
	TEMPER_EXPECT_TRUE( doubleeq( a, 0.000000 ) );

	a = saturate( 2.000000 );
	TEMPER_EXPECT_TRUE( doubleeq( a, 1.000000 ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestLerp_double )
{
	// scalar
	double a = 1.000000;
	double b = 3.000000;

	double answer = lerp( a, b, 0.500000 );

	TEMPER_EXPECT_TRUE( doubleeq( answer, 2.000000 ) );

	TEMPER_PASS();
}

TEMPER_SUITE( Test_double )
{
	TEMPER_RUN_TEST( TestFloateq_double );
	TEMPER_RUN_TEST( TestSign_double );
	TEMPER_RUN_TEST( TestDegreesRadians_double );
	TEMPER_RUN_TEST( TestMinMax_double );
	TEMPER_RUN_TEST( TestClamp_double );
	TEMPER_RUN_TEST( TestSaturate_double );
	TEMPER_RUN_TEST( TestLerp_double );
}

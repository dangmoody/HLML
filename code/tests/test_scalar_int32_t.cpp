#include "../../code/out/gen/hlml_functions_scalar.h"

#include <temper/temper.h>

TEMPER_TEST( TestSign_int32_t )
{
	TEMPER_EXPECT_TRUE( sign( -5 ) == -1 );
	TEMPER_EXPECT_TRUE( sign( 9 ) ==  1 );

	TEMPER_PASS();
}

TEMPER_TEST( TestMinMax_int32_t )
{
	int32_t a = 5;
	int32_t b = 9;

	TEMPER_EXPECT_TRUE( min( a, b ) == a );
	TEMPER_EXPECT_TRUE( max( a, b ) == b );

	TEMPER_PASS();
}

TEMPER_TEST( TestClamp_int32_t )
{
	int32_t a;
	int32_t low  = 1;
	int32_t high = 10;

	a = clamp( 0, low, high );
	TEMPER_EXPECT_TRUE( a == low );

	a = clamp( 11, low, high );
	TEMPER_EXPECT_TRUE( a == high );

	TEMPER_PASS();
}

TEMPER_SUITE( Test_int32_t )
{
	TEMPER_RUN_TEST( TestSign_int32_t );
	TEMPER_RUN_TEST( TestMinMax_int32_t );
	TEMPER_RUN_TEST( TestClamp_int32_t );
}

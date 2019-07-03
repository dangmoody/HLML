#include "../../code/out/gen/hlml_functions_scalar.h"

#include <temper/temper.h>

TEMPER_TEST( TestMinMax_uint32_t )
{
	uint32_t a = 5U;
	uint32_t b = 9U;

	TEMPER_EXPECT_TRUE( min( a, b ) == a );
	TEMPER_EXPECT_TRUE( max( a, b ) == b );

	TEMPER_PASS();
}

TEMPER_TEST( TestClamp_uint32_t )
{
	uint32_t a;
	uint32_t low  = 1U;
	uint32_t high = 10U;

	a = clamp( 0U, low, high );
	TEMPER_EXPECT_TRUE( a == low );

	a = clamp( 11U, low, high );
	TEMPER_EXPECT_TRUE( a == high );

	TEMPER_PASS();
}

TEMPER_SUITE( Test_uint32_t )
{
	TEMPER_RUN_TEST( TestMinMax_uint32_t );
	TEMPER_RUN_TEST( TestClamp_uint32_t );
}

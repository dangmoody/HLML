#include "../../code/out/gen/hlml_functions_scalar.h"

#include <temper/temper.h>

#include "../../code/out/gen/hlml_functions_scalar_sse.h"

#include <xmmintrin.h>

TEMPER_TEST( TestFloateq_float )
{
	float a = 5.0f;
	float b = 5.0f;
	float c = 5.000020f;
	float d = 5.000100f;

	TEMPER_EXPECT_TRUE(  floateq( a, b ) );
	TEMPER_EXPECT_TRUE( !floateq( a, c ) );
	TEMPER_EXPECT_TRUE( !floateq( a, d ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestSign_float )
{
	TEMPER_EXPECT_TRUE( sign( -5.0f ) == -1 );
	TEMPER_EXPECT_TRUE( sign( 9.0f ) ==  1 );

	TEMPER_PASS();
}

TEMPER_TEST( TestDegreesRadians_float )
{
	float deg = 90.0f;
	float rad = 1.57079637f;

	float answerRadians = radians( deg );
	float answerDegrees = degrees( rad );

	TEMPER_EXPECT_TRUE( floateq( answerRadians, 1.57079637f ) );
	TEMPER_EXPECT_TRUE( floateq( answerDegrees, 90.0f ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestMinMax_float )
{
	float a = 5.0f;
	float b = 9.0f;

	TEMPER_EXPECT_TRUE( floateq( min( a, b ), a ) );
	TEMPER_EXPECT_TRUE( floateq( max( a, b ), b ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestClamp_float )
{
	float a;
	float low  = 1.0f;
	float high = 10.0f;

	a = clamp( 0.0f, low, high );
	TEMPER_EXPECT_TRUE( floateq( a, low ) );

	a = clamp( 11.0f, low, high );
	TEMPER_EXPECT_TRUE( floateq( a, high ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestSaturate_float )
{
	float a;

	a = saturate( -1.000000f );
	TEMPER_EXPECT_TRUE( floateq( a, 0.000000f ) );

	a = saturate( 2.000000f );
	TEMPER_EXPECT_TRUE( floateq( a, 1.000000f ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestLerp_float )
{
	// scalar
	float a = 1.0f;
	float b = 3.0f;

	float answer = lerp( a, b, 0.5f );

	TEMPER_EXPECT_TRUE( floateq( answer, 2.0f ) );

	// SSE
	float ones[4]   = { 1.0f, 1.0f, 1.0f, 1.0f };
	float threes[4] = { 3.0f, 3.0f, 3.0f, 3.0f };
	float halves[4] = { 0.5f, 0.5f, 0.5f, 0.5f };

	sse_input_lerp_float_t in;

	in.lhs = _mm_load_ps( ones );
	in.rhs = _mm_load_ps( threes );
	in.t   = _mm_load_ps( halves );

	__m128 results;
	lerp_sse( in, &results );

	float lerpResults[4];
	_mm_store_ps( lerpResults, results );

	TEMPER_EXPECT_TRUE( floateq( lerpResults[0], 2.0f ) );
	TEMPER_EXPECT_TRUE( floateq( lerpResults[1], 2.0f ) );
	TEMPER_EXPECT_TRUE( floateq( lerpResults[2], 2.0f ) );
	TEMPER_EXPECT_TRUE( floateq( lerpResults[3], 2.0f ) );

	TEMPER_PASS();
}

TEMPER_SUITE( Test_float )
{
	TEMPER_RUN_TEST( TestFloateq_float );
	TEMPER_RUN_TEST( TestSign_float );
	TEMPER_RUN_TEST( TestDegreesRadians_float );
	TEMPER_RUN_TEST( TestMinMax_float );
	TEMPER_RUN_TEST( TestClamp_float );
	TEMPER_RUN_TEST( TestSaturate_float );
	TEMPER_RUN_TEST( TestLerp_float );
}

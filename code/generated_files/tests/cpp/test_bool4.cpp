/*
===========================================================================

HLML.

MIT License

Copyright (c) 2019 Dan Moody

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

===========================================================================
*/

// THIS FILE WAS AUTOMATICALLY GENERATED BY A TOOL.
// EDITING THIS FILE MAY CAUSE SIDE EFFECTS.
// DO SO AT YOUR OWN RISK.

TEMPER_PARAMETRIC( Test_bool4_all, TEMPER_FLAG_SHOULD_RUN, const bool4& x, const bool32_t expectedAnswer )
{
	bool32_t actualResult = all( x );
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool4_all,
	bool4( true, true, true, true ),
	true
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool4_all,
	bool4( true, false, false, false ),
	false
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool4_all,
	bool4( false, true, true, true ),
	false
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool4_all,
	bool4( false, true, false, true ),
	false
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool4_all,
	bool4( false, false, false, false ),
	false
);

TEMPER_PARAMETRIC( Test_bool4_any, TEMPER_FLAG_SHOULD_RUN, const bool4& x, const bool32_t expectedAnswer )
{
	bool32_t actualResult = any( x );
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool4_any,
	bool4( true, true, true, true ),
	true
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool4_any,
	bool4( true, false, false, false ),
	true
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool4_any,
	bool4( false, true, true, true ),
	true
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool4_any,
	bool4( false, true, false, true ),
	true
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool4_any,
	bool4( false, false, false, false ),
	false
);

TEMPER_PARAMETRIC( Test_bool4_int4, TEMPER_FLAG_SHOULD_RUN, const int4& convertFrom, const bool4& expectedAnswer )
{
	bool4 actualAnswer = bool4( convertFrom );

	TEMPER_CHECK_TRUE( expectedAnswer.x == actualAnswer.x );
	TEMPER_CHECK_TRUE( expectedAnswer.y == actualAnswer.y );
	TEMPER_CHECK_TRUE( expectedAnswer.z == actualAnswer.z );
	TEMPER_CHECK_TRUE( expectedAnswer.w == actualAnswer.w );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool4_int4,
	int4( 0, 0, 0, 0 ),
	bool4( false, false, false, false )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool4_int4,
	int4( 10, 10, 10, 10 ),
	bool4( true, true, true, true )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool4_int4,
	int4( 10, 20, 30, 40 ),
	bool4( true, true, true, true )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool4_int4,
	int4( 160, 150, 140, 130 ),
	bool4( true, true, true, true )
);

TEMPER_PARAMETRIC( Test_bool4_uint4, TEMPER_FLAG_SHOULD_RUN, const uint4& convertFrom, const bool4& expectedAnswer )
{
	bool4 actualAnswer = bool4( convertFrom );

	TEMPER_CHECK_TRUE( expectedAnswer.x == actualAnswer.x );
	TEMPER_CHECK_TRUE( expectedAnswer.y == actualAnswer.y );
	TEMPER_CHECK_TRUE( expectedAnswer.z == actualAnswer.z );
	TEMPER_CHECK_TRUE( expectedAnswer.w == actualAnswer.w );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool4_uint4,
	uint4( 0U, 0U, 0U, 0U ),
	bool4( false, false, false, false )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool4_uint4,
	uint4( 10U, 10U, 10U, 10U ),
	bool4( true, true, true, true )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool4_uint4,
	uint4( 10U, 20U, 30U, 40U ),
	bool4( true, true, true, true )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool4_uint4,
	uint4( 160U, 150U, 140U, 130U ),
	bool4( true, true, true, true )
);

TEMPER_PARAMETRIC( Test_bool4_float4, TEMPER_FLAG_SHOULD_RUN, const float4& convertFrom, const bool4& expectedAnswer )
{
	bool4 actualAnswer = bool4( convertFrom );

	TEMPER_CHECK_TRUE( expectedAnswer.x == actualAnswer.x );
	TEMPER_CHECK_TRUE( expectedAnswer.y == actualAnswer.y );
	TEMPER_CHECK_TRUE( expectedAnswer.z == actualAnswer.z );
	TEMPER_CHECK_TRUE( expectedAnswer.w == actualAnswer.w );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool4_float4,
	float4( 0.000000f, 0.000000f, 0.000000f, 0.000000f ),
	bool4( false, false, false, false )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool4_float4,
	float4( 10.000000f, 10.000000f, 10.000000f, 10.000000f ),
	bool4( true, true, true, true )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool4_float4,
	float4( 10.000000f, 20.000000f, 30.000000f, 40.000000f ),
	bool4( true, true, true, true )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool4_float4,
	float4( 160.000000f, 150.000000f, 140.000000f, 130.000000f ),
	bool4( true, true, true, true )
);

TEMPER_PARAMETRIC( Test_bool4_double4, TEMPER_FLAG_SHOULD_RUN, const double4& convertFrom, const bool4& expectedAnswer )
{
	bool4 actualAnswer = bool4( convertFrom );

	TEMPER_CHECK_TRUE( expectedAnswer.x == actualAnswer.x );
	TEMPER_CHECK_TRUE( expectedAnswer.y == actualAnswer.y );
	TEMPER_CHECK_TRUE( expectedAnswer.z == actualAnswer.z );
	TEMPER_CHECK_TRUE( expectedAnswer.w == actualAnswer.w );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool4_double4,
	double4( 0.000000f, 0.000000f, 0.000000f, 0.000000f ),
	bool4( false, false, false, false )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool4_double4,
	double4( 10.000000f, 10.000000f, 10.000000f, 10.000000f ),
	bool4( true, true, true, true )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool4_double4,
	double4( 10.000000f, 20.000000f, 30.000000f, 40.000000f ),
	bool4( true, true, true, true )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool4_double4,
	double4( 160.000000f, 150.000000f, 140.000000f, 130.000000f ),
	bool4( true, true, true, true )
);

TEMPER_PARAMETRIC( Test_bool4_composite_ctor_1_vec_before_with_2_leftovers, TEMPER_FLAG_SHOULD_RUN, const bool2& vecPart, const bool32_t scalar0, const bool32_t scalar1, const bool4 expectedAnswer )
{
	bool4 actualAnswer = bool4( vecPart, scalar0, scalar1 );

	TEMPER_CHECK_TRUE( actualAnswer.x == expectedAnswer.x );
	TEMPER_CHECK_TRUE( actualAnswer.y == expectedAnswer.y );
	TEMPER_CHECK_TRUE( actualAnswer.z == expectedAnswer.z );
	TEMPER_CHECK_TRUE( actualAnswer.w == expectedAnswer.w );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool4_composite_ctor_1_vec_before_with_2_leftovers,
	bool2( false, false ),
	false,
	false,
	bool4( false, false, false, false )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool4_composite_ctor_1_vec_before_with_2_leftovers,
	bool2( true, true ),
	true,
	true,
	bool4( true, true, true, true )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool4_composite_ctor_1_vec_before_with_2_leftovers,
	bool2( true, true ),
	true,
	true,
	bool4( true, true, true, true )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool4_composite_ctor_1_vec_before_with_2_leftovers,
	bool2( true, true ),
	true,
	true,
	bool4( true, true, true, true )
);

TEMPER_PARAMETRIC( Test_bool4_composite_ctor_1_vec_after_with_2_leftovers, TEMPER_FLAG_SHOULD_RUN, const bool32_t scalar0, const bool32_t scalar1, const bool2& vecPart, const bool4 expectedAnswer )
{
	bool4 actualAnswer = bool4( scalar0, scalar1, vecPart );

	TEMPER_CHECK_TRUE( actualAnswer.x == expectedAnswer.x );
	TEMPER_CHECK_TRUE( actualAnswer.y == expectedAnswer.y );
	TEMPER_CHECK_TRUE( actualAnswer.z == expectedAnswer.z );
	TEMPER_CHECK_TRUE( actualAnswer.w == expectedAnswer.w );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool4_composite_ctor_1_vec_after_with_2_leftovers,
	false,
	false,
	bool2( false, false ),
	bool4( false, false, false, false )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool4_composite_ctor_1_vec_after_with_2_leftovers,
	true,
	true,
	bool2( true, true ),
	bool4( true, true, true, true )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool4_composite_ctor_1_vec_after_with_2_leftovers,
	true,
	true,
	bool2( true, true ),
	bool4( true, true, true, true )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool4_composite_ctor_1_vec_after_with_2_leftovers,
	true,
	true,
	bool2( true, true ),
	bool4( true, true, true, true )
);

TEMPER_PARAMETRIC( Test_bool4_composite_ctor_1_vec_before_with_3_leftovers, TEMPER_FLAG_SHOULD_RUN, const bool3& vecPart, const bool32_t scalar0, const bool4 expectedAnswer )
{
	bool4 actualAnswer = bool4( vecPart, scalar0 );

	TEMPER_CHECK_TRUE( actualAnswer.x == expectedAnswer.x );
	TEMPER_CHECK_TRUE( actualAnswer.y == expectedAnswer.y );
	TEMPER_CHECK_TRUE( actualAnswer.z == expectedAnswer.z );
	TEMPER_CHECK_TRUE( actualAnswer.w == expectedAnswer.w );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool4_composite_ctor_1_vec_before_with_3_leftovers,
	bool3( false, false, false ),
	false,
	bool4( false, false, false, false )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool4_composite_ctor_1_vec_before_with_3_leftovers,
	bool3( true, true, true ),
	true,
	bool4( true, true, true, true )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool4_composite_ctor_1_vec_before_with_3_leftovers,
	bool3( true, true, true ),
	true,
	bool4( true, true, true, true )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool4_composite_ctor_1_vec_before_with_3_leftovers,
	bool3( true, true, true ),
	true,
	bool4( true, true, true, true )
);

TEMPER_PARAMETRIC( Test_bool4_composite_ctor_1_vec_after_with_3_leftovers, TEMPER_FLAG_SHOULD_RUN, const bool32_t scalar0, const bool3& vecPart, const bool4 expectedAnswer )
{
	bool4 actualAnswer = bool4( scalar0, vecPart );

	TEMPER_CHECK_TRUE( actualAnswer.x == expectedAnswer.x );
	TEMPER_CHECK_TRUE( actualAnswer.y == expectedAnswer.y );
	TEMPER_CHECK_TRUE( actualAnswer.z == expectedAnswer.z );
	TEMPER_CHECK_TRUE( actualAnswer.w == expectedAnswer.w );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool4_composite_ctor_1_vec_after_with_3_leftovers,
	false,
	bool3( false, false, false ),
	bool4( false, false, false, false )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool4_composite_ctor_1_vec_after_with_3_leftovers,
	true,
	bool3( true, true, true ),
	bool4( true, true, true, true )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool4_composite_ctor_1_vec_after_with_3_leftovers,
	true,
	bool3( true, true, true ),
	bool4( true, true, true, true )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool4_composite_ctor_1_vec_after_with_3_leftovers,
	true,
	bool3( true, true, true ),
	bool4( true, true, true, true )
);

TEMPER_PARAMETRIC( Test_bool4_lengthsq, TEMPER_FLAG_SHOULD_RUN, const bool4& vec, const float expectedAnswer )
{
	float actualResult = lengthsq( vec );
	TEMPER_CHECK_TRUE( floateq( actualResult, expectedAnswer ) );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool4_lengthsq,
	bool4( false, false, false, false ),
	0.000000f
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool4_lengthsq,
	bool4( true, true, true, true ),
	4.000000f
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool4_lengthsq,
	bool4( true, true, true, true ),
	16.000000f
);

TEMPER_PARAMETRIC( Test_bool4_length, TEMPER_FLAG_SHOULD_RUN, const bool4& vec, const float expectedAnswer )
{
	float actualResult = length( vec );
	TEMPER_CHECK_TRUE( floateq( actualResult, expectedAnswer ) );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool4_length,
	bool4( false, false, false, false ),
	0.000000f
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool4_length,
	bool4( true, true, true, true ),
	2.000000f
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool4_length,
	bool4( true, true, true, true ),
	4.000000f
);

TEMPER_PARAMETRIC( Test_bool4_dot, TEMPER_FLAG_SHOULD_RUN, const bool4& lhs, const bool4& rhs, const bool32_t expectedAnswer )
{
	bool32_t actualResult = dot( lhs, rhs );
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool4_dot,
	bool4( false, false, false, false ),
	bool4( true, true, true, true ),
	false
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool4_dot,
	bool4( true, true, true, true ),
	bool4( true, true, true, true ),
	true
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool4_dot,
	bool4( true, true, true, true ),
	bool4( true, true, true, true ),
	true
);


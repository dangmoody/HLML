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

TEMPER_PARAMETRIC( Test_double3_less_than, TEMPER_FLAG_SHOULD_RUN, const double3* lhs, const double3* rhs, const bool3* expectedAnswer )
{
	bool3 actualResult = double3_less_than( lhs, rhs );
	TEMPER_CHECK_TRUE( bool3_equals( &actualResult, expectedAnswer ) );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double3_less_than,
	&(double3) { 0.000000f, 0.000000f, 0.000000f },
	&(double3) { 0.000000f, 0.000000f, 0.000000f },
	&(bool3) { false, false, false }
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double3_less_than,
	&(double3) { 0.000000f, 0.000000f, 0.000000f },
	&(double3) { 1.000000f, 1.000000f, 1.000000f },
	&(bool3) { true, true, true }
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double3_less_than,
	&(double3) { 1.000000f, 1.000000f, 1.000000f },
	&(double3) { 1.000000f, 1.000000f, 1.000000f },
	&(bool3) { false, false, false }
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double3_less_than,
	&(double3) { 1.000000f, 1.000000f, 1.000000f },
	&(double3) { 0.000000f, 0.000000f, 0.000000f },
	&(bool3) { false, false, false }
);

TEMPER_PARAMETRIC( Test_double3_less_than_equal, TEMPER_FLAG_SHOULD_RUN, const double3* lhs, const double3* rhs, const bool3* expectedAnswer )
{
	bool3 actualResult = double3_less_than_equal( lhs, rhs );
	TEMPER_CHECK_TRUE( bool3_equals( &actualResult, expectedAnswer ) );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double3_less_than_equal,
	&(double3) { 0.000000f, 0.000000f, 0.000000f },
	&(double3) { 0.000000f, 0.000000f, 0.000000f },
	&(bool3) { true, true, true }
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double3_less_than_equal,
	&(double3) { 0.000000f, 0.000000f, 0.000000f },
	&(double3) { 1.000000f, 1.000000f, 1.000000f },
	&(bool3) { true, true, true }
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double3_less_than_equal,
	&(double3) { 1.000000f, 1.000000f, 1.000000f },
	&(double3) { 1.000000f, 1.000000f, 1.000000f },
	&(bool3) { true, true, true }
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double3_less_than_equal,
	&(double3) { 1.000000f, 1.000000f, 1.000000f },
	&(double3) { 0.000000f, 0.000000f, 0.000000f },
	&(bool3) { false, false, false }
);

TEMPER_PARAMETRIC( Test_double3_greater_than, TEMPER_FLAG_SHOULD_RUN, const double3* lhs, const double3* rhs, const bool3* expectedAnswer )
{
	bool3 actualResult = double3_greater_than( lhs, rhs );
	TEMPER_CHECK_TRUE( bool3_equals( &actualResult, expectedAnswer ) );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double3_greater_than,
	&(double3) { 0.000000f, 0.000000f, 0.000000f },
	&(double3) { 0.000000f, 0.000000f, 0.000000f },
	&(bool3) { false, false, false }
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double3_greater_than,
	&(double3) { 0.000000f, 0.000000f, 0.000000f },
	&(double3) { 1.000000f, 1.000000f, 1.000000f },
	&(bool3) { false, false, false }
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double3_greater_than,
	&(double3) { 1.000000f, 1.000000f, 1.000000f },
	&(double3) { 1.000000f, 1.000000f, 1.000000f },
	&(bool3) { false, false, false }
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double3_greater_than,
	&(double3) { 1.000000f, 1.000000f, 1.000000f },
	&(double3) { 0.000000f, 0.000000f, 0.000000f },
	&(bool3) { true, true, true }
);

TEMPER_PARAMETRIC( Test_double3_greater_than_equal, TEMPER_FLAG_SHOULD_RUN, const double3* lhs, const double3* rhs, const bool3* expectedAnswer )
{
	bool3 actualResult = double3_greater_than_equal( lhs, rhs );
	TEMPER_CHECK_TRUE( bool3_equals( &actualResult, expectedAnswer ) );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double3_greater_than_equal,
	&(double3) { 0.000000f, 0.000000f, 0.000000f },
	&(double3) { 0.000000f, 0.000000f, 0.000000f },
	&(bool3) { true, true, true }
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double3_greater_than_equal,
	&(double3) { 0.000000f, 0.000000f, 0.000000f },
	&(double3) { 1.000000f, 1.000000f, 1.000000f },
	&(bool3) { false, false, false }
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double3_greater_than_equal,
	&(double3) { 1.000000f, 1.000000f, 1.000000f },
	&(double3) { 1.000000f, 1.000000f, 1.000000f },
	&(bool3) { true, true, true }
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double3_greater_than_equal,
	&(double3) { 1.000000f, 1.000000f, 1.000000f },
	&(double3) { 0.000000f, 0.000000f, 0.000000f },
	&(bool3) { true, true, true }
);

TEMPER_PARAMETRIC( Test_double3_cadds, TEMPER_FLAG_SHOULD_RUN, const double3* lhs, const double rhs, const double3* expectedAnswer )
{
	double3 actualResult = double3_cadds( lhs, rhs );
	TEMPER_CHECK_TRUE( double3_equals( &actualResult, expectedAnswer ) );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double3_cadds,
	&(double3) { 1.000000f, 1.000000f, 1.000000f },
	1.000000f,
	&(double3) { 2.000000f, 2.000000f, 2.000000f }
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double3_cadds,
	&(double3) { 2.000000f, 2.000000f, 2.000000f },
	2.000000f,
	&(double3) { 4.000000f, 4.000000f, 4.000000f }
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double3_cadds,
	&(double3) { 4.000000f, 4.000000f, 4.000000f },
	2.000000f,
	&(double3) { 6.000000f, 6.000000f, 6.000000f }
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double3_cadds,
	&(double3) { 8.000000f, 8.000000f, 8.000000f },
	4.000000f,
	&(double3) { 12.000000f, 12.000000f, 12.000000f }
);

TEMPER_PARAMETRIC( Test_double3_csubs, TEMPER_FLAG_SHOULD_RUN, const double3* lhs, const double rhs, const double3* expectedAnswer )
{
	double3 actualResult = double3_csubs( lhs, rhs );
	TEMPER_CHECK_TRUE( double3_equals( &actualResult, expectedAnswer ) );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double3_csubs,
	&(double3) { 1.000000f, 1.000000f, 1.000000f },
	1.000000f,
	&(double3) { 0.000000f, 0.000000f, 0.000000f }
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double3_csubs,
	&(double3) { 2.000000f, 2.000000f, 2.000000f },
	2.000000f,
	&(double3) { 0.000000f, 0.000000f, 0.000000f }
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double3_csubs,
	&(double3) { 4.000000f, 4.000000f, 4.000000f },
	2.000000f,
	&(double3) { 2.000000f, 2.000000f, 2.000000f }
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double3_csubs,
	&(double3) { 8.000000f, 8.000000f, 8.000000f },
	4.000000f,
	&(double3) { 4.000000f, 4.000000f, 4.000000f }
);

TEMPER_PARAMETRIC( Test_double3_cmuls, TEMPER_FLAG_SHOULD_RUN, const double3* lhs, const double rhs, const double3* expectedAnswer )
{
	double3 actualResult = double3_cmuls( lhs, rhs );
	TEMPER_CHECK_TRUE( double3_equals( &actualResult, expectedAnswer ) );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double3_cmuls,
	&(double3) { 1.000000f, 1.000000f, 1.000000f },
	1.000000f,
	&(double3) { 1.000000f, 1.000000f, 1.000000f }
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double3_cmuls,
	&(double3) { 2.000000f, 2.000000f, 2.000000f },
	2.000000f,
	&(double3) { 4.000000f, 4.000000f, 4.000000f }
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double3_cmuls,
	&(double3) { 4.000000f, 4.000000f, 4.000000f },
	2.000000f,
	&(double3) { 8.000000f, 8.000000f, 8.000000f }
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double3_cmuls,
	&(double3) { 8.000000f, 8.000000f, 8.000000f },
	4.000000f,
	&(double3) { 32.000000f, 32.000000f, 32.000000f }
);

TEMPER_PARAMETRIC( Test_double3_cdivs, TEMPER_FLAG_SHOULD_RUN, const double3* lhs, const double rhs, const double3* expectedAnswer )
{
	double3 actualResult = double3_cdivs( lhs, rhs );
	TEMPER_CHECK_TRUE( double3_equals( &actualResult, expectedAnswer ) );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double3_cdivs,
	&(double3) { 1.000000f, 1.000000f, 1.000000f },
	1.000000f,
	&(double3) { 1.000000f, 1.000000f, 1.000000f }
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double3_cdivs,
	&(double3) { 2.000000f, 2.000000f, 2.000000f },
	2.000000f,
	&(double3) { 1.000000f, 1.000000f, 1.000000f }
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double3_cdivs,
	&(double3) { 4.000000f, 4.000000f, 4.000000f },
	2.000000f,
	&(double3) { 2.000000f, 2.000000f, 2.000000f }
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double3_cdivs,
	&(double3) { 8.000000f, 8.000000f, 8.000000f },
	4.000000f,
	&(double3) { 2.000000f, 2.000000f, 2.000000f }
);

TEMPER_PARAMETRIC( Test_double3_caddv, TEMPER_FLAG_SHOULD_RUN, const double3* lhs, const double3* rhs, const double3* expectedAnswer )
{
	double3 actualResult = double3_caddv( lhs, rhs );
	TEMPER_CHECK_TRUE( double3_equals( &actualResult, expectedAnswer ) );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double3_caddv,
	&(double3) { 1.000000f, 1.000000f, 1.000000f },
	&(double3) { 1.000000f, 1.000000f, 1.000000f },
	&(double3) { 2.000000f, 2.000000f, 2.000000f }
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double3_caddv,
	&(double3) { 2.000000f, 2.000000f, 2.000000f },
	&(double3) { 2.000000f, 2.000000f, 2.000000f },
	&(double3) { 4.000000f, 4.000000f, 4.000000f }
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double3_caddv,
	&(double3) { 4.000000f, 4.000000f, 4.000000f },
	&(double3) { 2.000000f, 2.000000f, 2.000000f },
	&(double3) { 6.000000f, 6.000000f, 6.000000f }
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double3_caddv,
	&(double3) { 8.000000f, 8.000000f, 8.000000f },
	&(double3) { 4.000000f, 4.000000f, 4.000000f },
	&(double3) { 12.000000f, 12.000000f, 12.000000f }
);

TEMPER_PARAMETRIC( Test_double3_csubv, TEMPER_FLAG_SHOULD_RUN, const double3* lhs, const double3* rhs, const double3* expectedAnswer )
{
	double3 actualResult = double3_csubv( lhs, rhs );
	TEMPER_CHECK_TRUE( double3_equals( &actualResult, expectedAnswer ) );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double3_csubv,
	&(double3) { 1.000000f, 1.000000f, 1.000000f },
	&(double3) { 1.000000f, 1.000000f, 1.000000f },
	&(double3) { 0.000000f, 0.000000f, 0.000000f }
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double3_csubv,
	&(double3) { 2.000000f, 2.000000f, 2.000000f },
	&(double3) { 2.000000f, 2.000000f, 2.000000f },
	&(double3) { 0.000000f, 0.000000f, 0.000000f }
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double3_csubv,
	&(double3) { 4.000000f, 4.000000f, 4.000000f },
	&(double3) { 2.000000f, 2.000000f, 2.000000f },
	&(double3) { 2.000000f, 2.000000f, 2.000000f }
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double3_csubv,
	&(double3) { 8.000000f, 8.000000f, 8.000000f },
	&(double3) { 4.000000f, 4.000000f, 4.000000f },
	&(double3) { 4.000000f, 4.000000f, 4.000000f }
);

TEMPER_PARAMETRIC( Test_double3_cmulv, TEMPER_FLAG_SHOULD_RUN, const double3* lhs, const double3* rhs, const double3* expectedAnswer )
{
	double3 actualResult = double3_cmulv( lhs, rhs );
	TEMPER_CHECK_TRUE( double3_equals( &actualResult, expectedAnswer ) );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double3_cmulv,
	&(double3) { 1.000000f, 1.000000f, 1.000000f },
	&(double3) { 1.000000f, 1.000000f, 1.000000f },
	&(double3) { 1.000000f, 1.000000f, 1.000000f }
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double3_cmulv,
	&(double3) { 2.000000f, 2.000000f, 2.000000f },
	&(double3) { 2.000000f, 2.000000f, 2.000000f },
	&(double3) { 4.000000f, 4.000000f, 4.000000f }
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double3_cmulv,
	&(double3) { 4.000000f, 4.000000f, 4.000000f },
	&(double3) { 2.000000f, 2.000000f, 2.000000f },
	&(double3) { 8.000000f, 8.000000f, 8.000000f }
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double3_cmulv,
	&(double3) { 8.000000f, 8.000000f, 8.000000f },
	&(double3) { 4.000000f, 4.000000f, 4.000000f },
	&(double3) { 32.000000f, 32.000000f, 32.000000f }
);

TEMPER_PARAMETRIC( Test_double3_cdivv, TEMPER_FLAG_SHOULD_RUN, const double3* lhs, const double3* rhs, const double3* expectedAnswer )
{
	double3 actualResult = double3_cdivv( lhs, rhs );
	TEMPER_CHECK_TRUE( double3_equals( &actualResult, expectedAnswer ) );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double3_cdivv,
	&(double3) { 1.000000f, 1.000000f, 1.000000f },
	&(double3) { 1.000000f, 1.000000f, 1.000000f },
	&(double3) { 1.000000f, 1.000000f, 1.000000f }
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double3_cdivv,
	&(double3) { 2.000000f, 2.000000f, 2.000000f },
	&(double3) { 2.000000f, 2.000000f, 2.000000f },
	&(double3) { 1.000000f, 1.000000f, 1.000000f }
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double3_cdivv,
	&(double3) { 4.000000f, 4.000000f, 4.000000f },
	&(double3) { 2.000000f, 2.000000f, 2.000000f },
	&(double3) { 2.000000f, 2.000000f, 2.000000f }
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double3_cdivv,
	&(double3) { 8.000000f, 8.000000f, 8.000000f },
	&(double3) { 4.000000f, 4.000000f, 4.000000f },
	&(double3) { 2.000000f, 2.000000f, 2.000000f }
);

#if defined( __GNUC__ ) || defined( __clang__ )
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wcast-qual"
#endif
TEMPER_PARAMETRIC( Test_double3_negate_prefix, TEMPER_FLAG_SHOULD_RUN, const double3* x, const double3* expectedAnswer )
{
	// make local copy of x and use that because we cant do increment or decrement operations on a const reference
	// and MSVC throws warnings if we just make the parameter a non-const reference
	double3* xlocal = (double3*) x;
	double3 actualAnswer = double3_negate( xlocal );
	TEMPER_CHECK_TRUE( double3_equals( &actualAnswer, expectedAnswer ) );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double3_negate_prefix,
	&(double3) { 0.000000f, 0.000000f, 0.000000f },
	&(double3) { -0.000000f, -0.000000f, -0.000000f }
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double3_negate_prefix,
	&(double3) { 1.000000f, 1.000000f, 1.000000f },
	&(double3) { -1.000000f, -1.000000f, -1.000000f }
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double3_negate_prefix,
	&(double3) { 2.000000f, 2.000000f, 2.000000f },
	&(double3) { -2.000000f, -2.000000f, -2.000000f }
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double3_negate_prefix,
	&(double3) { 3.000000f, 3.000000f, 3.000000f },
	&(double3) { -3.000000f, -3.000000f, -3.000000f }
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double3_negate_prefix,
	&(double3) { 10.000000f, 10.000000f, 10.000000f },
	&(double3) { -10.000000f, -10.000000f, -10.000000f }
);

#if defined( __GNUC__ ) || defined( __clang__ )
#pragma GCC diagnostic pop
#endif

TEMPER_PARAMETRIC( Test_double3_min, TEMPER_FLAG_SHOULD_RUN, const double3* lhs, const double3* rhs, const double3* expectedAnswer )
{
	double3 actualResult = double3_min( lhs, rhs );
	TEMPER_CHECK_TRUE( double3_equals( &actualResult, expectedAnswer ) );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double3_min,
	&(double3) { 0.000000f, 0.000000f, 0.000000f },
	&(double3) { 1.000000f, 1.000000f, 1.000000f },
	&(double3) { 0.000000f, 0.000000f, 0.000000f }
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double3_min,
	&(double3) { 1.000000f, 1.000000f, 1.000000f },
	&(double3) { 2.000000f, 2.000000f, 2.000000f },
	&(double3) { 1.000000f, 1.000000f, 1.000000f }
);

TEMPER_PARAMETRIC( Test_double3_max, TEMPER_FLAG_SHOULD_RUN, const double3* lhs, const double3* rhs, const double3* expectedAnswer )
{
	double3 actualResult = double3_max( lhs, rhs );
	TEMPER_CHECK_TRUE( double3_equals( &actualResult, expectedAnswer ) );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double3_max,
	&(double3) { 1.000000f, 1.000000f, 1.000000f },
	&(double3) { 0.000000f, 0.000000f, 0.000000f },
	&(double3) { 1.000000f, 1.000000f, 1.000000f }
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double3_max,
	&(double3) { 2.000000f, 2.000000f, 2.000000f },
	&(double3) { 1.000000f, 1.000000f, 1.000000f },
	&(double3) { 2.000000f, 2.000000f, 2.000000f }
);

TEMPER_PARAMETRIC( Test_double3_saturate, TEMPER_FLAG_SHOULD_RUN, const double3* x, const double3* expectedAnswer )
{
	double3 actualResult = double3_saturate( x );
	TEMPER_CHECK_TRUE( double3_equals( &actualResult, expectedAnswer ) );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double3_saturate,
	&(double3) { 0.000000f, 0.000000f, 0.000000f },
	&(double3) { 0.000000f, 0.000000f, 0.000000f }
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double3_saturate,
	&(double3) { 1.000000f, 1.000000f, 1.000000f },
	&(double3) { 1.000000f, 1.000000f, 1.000000f }
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double3_saturate,
	&(double3) { 2.000000f, 2.000000f, 2.000000f },
	&(double3) { 1.000000f, 1.000000f, 1.000000f }
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double3_saturate,
	&(double3) { 3.000000f, 3.000000f, 3.000000f },
	&(double3) { 1.000000f, 1.000000f, 1.000000f }
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double3_saturate,
	&(double3) { 10.000000f, 10.000000f, 10.000000f },
	&(double3) { 1.000000f, 1.000000f, 1.000000f }
);

TEMPER_PARAMETRIC( Test_double3_sign, TEMPER_FLAG_SHOULD_RUN, const double3* x, const int3* expectedAnswer )
{
	int3 actualResult = double3_sign( x );
	TEMPER_CHECK_TRUE( int3_equals( &actualResult, expectedAnswer ) );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double3_sign,
	&(double3) { 0.000000f, 0.000000f, 0.000000f },
	&(int3) { 0, 0, 0 }
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double3_sign,
	&(double3) { 1.000000f, 1.000000f, 1.000000f },
	&(int3) { 1, 1, 1 }
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double3_sign,
	&(double3) { 2.000000f, 2.000000f, 2.000000f },
	&(int3) { 1, 1, 1 }
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double3_sign,
	&(double3) { 3.000000f, 3.000000f, 3.000000f },
	&(int3) { 1, 1, 1 }
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double3_sign,
	&(double3) { -1.000000f, -1.000000f, -1.000000f },
	&(int3) { -1, -1, -1 }
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double3_sign,
	&(double3) { -2.000000f, -2.000000f, -2.000000f },
	&(int3) { -1, -1, -1 }
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double3_sign,
	&(double3) { -3.000000f, -3.000000f, -3.000000f },
	&(int3) { -1, -1, -1 }
);

TEMPER_PARAMETRIC( Test_double3_lerp, TEMPER_FLAG_SHOULD_RUN, const double3* lhs, const double3* rhs, const double t, const double3* expectedAnswer )
{
	double3 actualResult = double3_lerp( lhs, rhs, t );
	TEMPER_CHECK_TRUE( double3_equals( &actualResult, expectedAnswer ) );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double3_lerp,
	&(double3) { 0.000000f, 0.000000f, 0.000000f },
	&(double3) { 1.000000f, 1.000000f, 1.000000f },
	0.500000f,
	&(double3) { 0.500000f, 0.500000f, 0.500000f }
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double3_lerp,
	&(double3) { 1.000000f, 1.000000f, 1.000000f },
	&(double3) { 3.000000f, 3.000000f, 3.000000f },
	0.500000f,
	&(double3) { 2.000000f, 2.000000f, 2.000000f }
);

TEMPER_PARAMETRIC( Test_double3_lengthsq, TEMPER_FLAG_SHOULD_RUN, const double3* vec, const double expectedAnswer )
{
	double actualResult = double3_lengthsq( vec );
	TEMPER_CHECK_TRUE( doubleeq( actualResult, expectedAnswer ) );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double3_lengthsq,
	&(double3) { 0.000000f, 0.000000f, 0.000000f },
	0.000000f
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double3_lengthsq,
	&(double3) { 1.000000f, 1.000000f, 1.000000f },
	3.000000f
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double3_lengthsq,
	&(double3) { 2.000000f, 2.000000f, 2.000000f },
	12.000000f
);

TEMPER_PARAMETRIC( Test_double3_length, TEMPER_FLAG_SHOULD_RUN, const double3* vec, const double expectedAnswer )
{
	double actualResult = double3_length( vec );
	TEMPER_CHECK_TRUE( doubleeq( actualResult, expectedAnswer ) );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double3_length,
	&(double3) { 0.000000f, 0.000000f, 0.000000f },
	0.000000f
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double3_length,
	&(double3) { 1.000000f, 1.000000f, 1.000000f },
	1.732051f
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double3_length,
	&(double3) { 2.000000f, 2.000000f, 2.000000f },
	3.464102f
);

TEMPER_PARAMETRIC( Test_double3_dot, TEMPER_FLAG_SHOULD_RUN, const double3* lhs, const double3* rhs, const double expectedAnswer )
{
	double actualResult = double3_dot( lhs, rhs );
	TEMPER_CHECK_TRUE( doubleeq( actualResult, expectedAnswer ) );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double3_dot,
	&(double3) { 0.000000f, 0.000000f, 0.000000f },
	&(double3) { 1.000000f, 1.000000f, 1.000000f },
	0.000000f
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double3_dot,
	&(double3) { 1.000000f, 1.000000f, 1.000000f },
	&(double3) { 1.000000f, 1.000000f, 1.000000f },
	3.000000f
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double3_dot,
	&(double3) { 1.000000f, 1.000000f, 1.000000f },
	&(double3) { -1.000000f, -1.000000f, -1.000000f },
	-3.000000f
);

TEMPER_PARAMETRIC( Test_double3_cross, TEMPER_FLAG_SHOULD_RUN, const double3* lhs, const double3* rhs, const double3* expectedAnswer )
{
	double3 actualResult = double3_cross( lhs, rhs );
	TEMPER_CHECK_TRUE( double3_equals( &actualResult, expectedAnswer ) );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double3_cross,
	&(double3) { 1.000000f, 0.000000f, 0.000000f },
	&(double3) { 0.000000f, 1.000000f, 0.000000f },
	&(double3) { 0.000000f, 0.000000f, 1.000000f }
);

TEMPER_PARAMETRIC( Test_double3_angle, TEMPER_FLAG_SHOULD_RUN, const double3* lhs, const double3* rhs, const double expectedAnswer )
{
	double actualResult = double3_angle( lhs, rhs );
	TEMPER_CHECK_TRUE( doubleeq( actualResult, expectedAnswer ) );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double3_angle,
	&(double3) { 1.000000f, 0.000000f, 0.000000f },
	&(double3) { 0.000000f, 1.000000f, 0.000000f },
	90.000000f
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double3_angle,
	&(double3) { 1.000000f, 1.000000f, 0.000000f },
	&(double3) { 0.000000f, 1.000000f, 0.000000f },
	45.000000f
);

TEMPER_PARAMETRIC( Test_double3_distancesq, TEMPER_FLAG_SHOULD_RUN, const double3* lhs, const double3* rhs, const double expectedAnswer )
{
	double actualResult = double3_distancesq( lhs, rhs );
	TEMPER_CHECK_TRUE( doubleeq( actualResult, expectedAnswer ) );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double3_distancesq,
	&(double3) { 0.000000f, 0.000000f, 0.000000f },
	&(double3) { 0.000000f, 0.000000f, 0.000000f },
	0.000000f
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double3_distancesq,
	&(double3) { 0.000000f, 0.000000f, 0.000000f },
	&(double3) { 1.000000f, 1.000000f, 1.000000f },
	3.000000f
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double3_distancesq,
	&(double3) { 0.000000f, 0.000000f, 0.000000f },
	&(double3) { 2.000000f, 2.000000f, 2.000000f },
	12.000003f
);

TEMPER_PARAMETRIC( Test_double3_distance, TEMPER_FLAG_SHOULD_RUN, const double3* lhs, const double3* rhs, const double expectedAnswer )
{
	double actualResult = double3_distance( lhs, rhs );
	TEMPER_CHECK_TRUE( doubleeq( actualResult, expectedAnswer ) );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double3_distance,
	&(double3) { 0.000000f, 0.000000f, 0.000000f },
	&(double3) { 0.000000f, 0.000000f, 0.000000f },
	0.000000f
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double3_distance,
	&(double3) { 0.000000f, 0.000000f, 0.000000f },
	&(double3) { 1.000000f, 1.000000f, 1.000000f },
	1.732051f
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double3_distance,
	&(double3) { 0.000000f, 0.000000f, 0.000000f },
	&(double3) { 2.000000f, 2.000000f, 2.000000f },
	3.464102f
);

TEMPER_PARAMETRIC( Test_double3_normalize, TEMPER_FLAG_SHOULD_RUN, const double3* vec, const double3* expectedAnswer )
{
	double3 vecNormalized = *vec;
	double3_normalize( &vecNormalized );
	TEMPER_CHECK_TRUE( double3_equals( &vecNormalized, expectedAnswer ) );
	TEMPER_CHECK_TRUE( doubleeq( double3_length( &vecNormalized ), 1.0 ) );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double3_normalize,
	&(double3) { 1.000000f, 2.000000f, 3.000000f },
	&(double3) { 0.267261f, 0.534522f, 0.801784f }
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double3_normalize,
	&(double3) { 5.000000f, 4.000000f, 3.000000f },
	&(double3) { 0.707107f, 0.565685f, 0.424264f }
);


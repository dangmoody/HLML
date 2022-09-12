/*
===========================================================================

HLML
v2.2.0

MIT License:

Copyright (c) 2019 Dan Moody (daniel.guy.moody@gmail.com).

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

TEMPER_PARAMETRIC( Test_double4_less_than, TEMPER_FLAG_SHOULD_RUN, const double4* lhs, const double4* rhs, const bool4* expectedAnswer )
{
	bool4 actualResult = double4_less_than( lhs, rhs );
	TEMPER_CHECK_TRUE( bool4_equals( &actualResult, expectedAnswer ) );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double4_less_than,
	&(double4) { 0.000000f, 0.000000f, 0.000000f, 0.000000f },
	&(double4) { 0.000000f, 0.000000f, 0.000000f, 0.000000f },
	&(bool4) { false, false, false, false }
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double4_less_than,
	&(double4) { 0.000000f, 0.000000f, 0.000000f, 0.000000f },
	&(double4) { 1.000000f, 1.000000f, 1.000000f, 1.000000f },
	&(bool4) { true, true, true, true }
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double4_less_than,
	&(double4) { 1.000000f, 1.000000f, 1.000000f, 1.000000f },
	&(double4) { 1.000000f, 1.000000f, 1.000000f, 1.000000f },
	&(bool4) { false, false, false, false }
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double4_less_than,
	&(double4) { 1.000000f, 1.000000f, 1.000000f, 1.000000f },
	&(double4) { 0.000000f, 0.000000f, 0.000000f, 0.000000f },
	&(bool4) { false, false, false, false }
);

TEMPER_PARAMETRIC( Test_double4_less_than_equal, TEMPER_FLAG_SHOULD_RUN, const double4* lhs, const double4* rhs, const bool4* expectedAnswer )
{
	bool4 actualResult = double4_less_than_equal( lhs, rhs );
	TEMPER_CHECK_TRUE( bool4_equals( &actualResult, expectedAnswer ) );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double4_less_than_equal,
	&(double4) { 0.000000f, 0.000000f, 0.000000f, 0.000000f },
	&(double4) { 0.000000f, 0.000000f, 0.000000f, 0.000000f },
	&(bool4) { true, true, true, true }
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double4_less_than_equal,
	&(double4) { 0.000000f, 0.000000f, 0.000000f, 0.000000f },
	&(double4) { 1.000000f, 1.000000f, 1.000000f, 1.000000f },
	&(bool4) { true, true, true, true }
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double4_less_than_equal,
	&(double4) { 1.000000f, 1.000000f, 1.000000f, 1.000000f },
	&(double4) { 1.000000f, 1.000000f, 1.000000f, 1.000000f },
	&(bool4) { true, true, true, true }
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double4_less_than_equal,
	&(double4) { 1.000000f, 1.000000f, 1.000000f, 1.000000f },
	&(double4) { 0.000000f, 0.000000f, 0.000000f, 0.000000f },
	&(bool4) { false, false, false, false }
);

TEMPER_PARAMETRIC( Test_double4_greater_than, TEMPER_FLAG_SHOULD_RUN, const double4* lhs, const double4* rhs, const bool4* expectedAnswer )
{
	bool4 actualResult = double4_greater_than( lhs, rhs );
	TEMPER_CHECK_TRUE( bool4_equals( &actualResult, expectedAnswer ) );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double4_greater_than,
	&(double4) { 0.000000f, 0.000000f, 0.000000f, 0.000000f },
	&(double4) { 0.000000f, 0.000000f, 0.000000f, 0.000000f },
	&(bool4) { false, false, false, false }
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double4_greater_than,
	&(double4) { 0.000000f, 0.000000f, 0.000000f, 0.000000f },
	&(double4) { 1.000000f, 1.000000f, 1.000000f, 1.000000f },
	&(bool4) { false, false, false, false }
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double4_greater_than,
	&(double4) { 1.000000f, 1.000000f, 1.000000f, 1.000000f },
	&(double4) { 1.000000f, 1.000000f, 1.000000f, 1.000000f },
	&(bool4) { false, false, false, false }
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double4_greater_than,
	&(double4) { 1.000000f, 1.000000f, 1.000000f, 1.000000f },
	&(double4) { 0.000000f, 0.000000f, 0.000000f, 0.000000f },
	&(bool4) { true, true, true, true }
);

TEMPER_PARAMETRIC( Test_double4_greater_than_equal, TEMPER_FLAG_SHOULD_RUN, const double4* lhs, const double4* rhs, const bool4* expectedAnswer )
{
	bool4 actualResult = double4_greater_than_equal( lhs, rhs );
	TEMPER_CHECK_TRUE( bool4_equals( &actualResult, expectedAnswer ) );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double4_greater_than_equal,
	&(double4) { 0.000000f, 0.000000f, 0.000000f, 0.000000f },
	&(double4) { 0.000000f, 0.000000f, 0.000000f, 0.000000f },
	&(bool4) { true, true, true, true }
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double4_greater_than_equal,
	&(double4) { 0.000000f, 0.000000f, 0.000000f, 0.000000f },
	&(double4) { 1.000000f, 1.000000f, 1.000000f, 1.000000f },
	&(bool4) { false, false, false, false }
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double4_greater_than_equal,
	&(double4) { 1.000000f, 1.000000f, 1.000000f, 1.000000f },
	&(double4) { 1.000000f, 1.000000f, 1.000000f, 1.000000f },
	&(bool4) { true, true, true, true }
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double4_greater_than_equal,
	&(double4) { 1.000000f, 1.000000f, 1.000000f, 1.000000f },
	&(double4) { 0.000000f, 0.000000f, 0.000000f, 0.000000f },
	&(bool4) { true, true, true, true }
);

TEMPER_PARAMETRIC( Test_double4_cadds, TEMPER_FLAG_SHOULD_RUN, const double4* lhs, const double rhs, const double4* expectedAnswer )
{
	double4 actualResult = double4_cadds( lhs, rhs );
	TEMPER_CHECK_TRUE( double4_equals( &actualResult, expectedAnswer ) );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double4_cadds,
	&(double4) { 1.000000f, 1.000000f, 1.000000f, 1.000000f },
	1.000000f,
	&(double4) { 2.000000f, 2.000000f, 2.000000f, 2.000000f }
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double4_cadds,
	&(double4) { 2.000000f, 2.000000f, 2.000000f, 2.000000f },
	2.000000f,
	&(double4) { 4.000000f, 4.000000f, 4.000000f, 4.000000f }
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double4_cadds,
	&(double4) { 4.000000f, 4.000000f, 4.000000f, 4.000000f },
	2.000000f,
	&(double4) { 6.000000f, 6.000000f, 6.000000f, 6.000000f }
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double4_cadds,
	&(double4) { 8.000000f, 8.000000f, 8.000000f, 8.000000f },
	4.000000f,
	&(double4) { 12.000000f, 12.000000f, 12.000000f, 12.000000f }
);

TEMPER_PARAMETRIC( Test_double4_csubs, TEMPER_FLAG_SHOULD_RUN, const double4* lhs, const double rhs, const double4* expectedAnswer )
{
	double4 actualResult = double4_csubs( lhs, rhs );
	TEMPER_CHECK_TRUE( double4_equals( &actualResult, expectedAnswer ) );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double4_csubs,
	&(double4) { 1.000000f, 1.000000f, 1.000000f, 1.000000f },
	1.000000f,
	&(double4) { 0.000000f, 0.000000f, 0.000000f, 0.000000f }
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double4_csubs,
	&(double4) { 2.000000f, 2.000000f, 2.000000f, 2.000000f },
	2.000000f,
	&(double4) { 0.000000f, 0.000000f, 0.000000f, 0.000000f }
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double4_csubs,
	&(double4) { 4.000000f, 4.000000f, 4.000000f, 4.000000f },
	2.000000f,
	&(double4) { 2.000000f, 2.000000f, 2.000000f, 2.000000f }
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double4_csubs,
	&(double4) { 8.000000f, 8.000000f, 8.000000f, 8.000000f },
	4.000000f,
	&(double4) { 4.000000f, 4.000000f, 4.000000f, 4.000000f }
);

TEMPER_PARAMETRIC( Test_double4_cmuls, TEMPER_FLAG_SHOULD_RUN, const double4* lhs, const double rhs, const double4* expectedAnswer )
{
	double4 actualResult = double4_cmuls( lhs, rhs );
	TEMPER_CHECK_TRUE( double4_equals( &actualResult, expectedAnswer ) );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double4_cmuls,
	&(double4) { 1.000000f, 1.000000f, 1.000000f, 1.000000f },
	1.000000f,
	&(double4) { 1.000000f, 1.000000f, 1.000000f, 1.000000f }
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double4_cmuls,
	&(double4) { 2.000000f, 2.000000f, 2.000000f, 2.000000f },
	2.000000f,
	&(double4) { 4.000000f, 4.000000f, 4.000000f, 4.000000f }
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double4_cmuls,
	&(double4) { 4.000000f, 4.000000f, 4.000000f, 4.000000f },
	2.000000f,
	&(double4) { 8.000000f, 8.000000f, 8.000000f, 8.000000f }
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double4_cmuls,
	&(double4) { 8.000000f, 8.000000f, 8.000000f, 8.000000f },
	4.000000f,
	&(double4) { 32.000000f, 32.000000f, 32.000000f, 32.000000f }
);

TEMPER_PARAMETRIC( Test_double4_cdivs, TEMPER_FLAG_SHOULD_RUN, const double4* lhs, const double rhs, const double4* expectedAnswer )
{
	double4 actualResult = double4_cdivs( lhs, rhs );
	TEMPER_CHECK_TRUE( double4_equals( &actualResult, expectedAnswer ) );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double4_cdivs,
	&(double4) { 1.000000f, 1.000000f, 1.000000f, 1.000000f },
	1.000000f,
	&(double4) { 1.000000f, 1.000000f, 1.000000f, 1.000000f }
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double4_cdivs,
	&(double4) { 2.000000f, 2.000000f, 2.000000f, 2.000000f },
	2.000000f,
	&(double4) { 1.000000f, 1.000000f, 1.000000f, 1.000000f }
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double4_cdivs,
	&(double4) { 4.000000f, 4.000000f, 4.000000f, 4.000000f },
	2.000000f,
	&(double4) { 2.000000f, 2.000000f, 2.000000f, 2.000000f }
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double4_cdivs,
	&(double4) { 8.000000f, 8.000000f, 8.000000f, 8.000000f },
	4.000000f,
	&(double4) { 2.000000f, 2.000000f, 2.000000f, 2.000000f }
);

TEMPER_PARAMETRIC( Test_double4_caddv, TEMPER_FLAG_SHOULD_RUN, const double4* lhs, const double4* rhs, const double4* expectedAnswer )
{
	double4 actualResult = double4_caddv( lhs, rhs );
	TEMPER_CHECK_TRUE( double4_equals( &actualResult, expectedAnswer ) );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double4_caddv,
	&(double4) { 1.000000f, 1.000000f, 1.000000f, 1.000000f },
	&(double4) { 1.000000f, 1.000000f, 1.000000f, 1.000000f },
	&(double4) { 2.000000f, 2.000000f, 2.000000f, 2.000000f }
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double4_caddv,
	&(double4) { 2.000000f, 2.000000f, 2.000000f, 2.000000f },
	&(double4) { 2.000000f, 2.000000f, 2.000000f, 2.000000f },
	&(double4) { 4.000000f, 4.000000f, 4.000000f, 4.000000f }
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double4_caddv,
	&(double4) { 4.000000f, 4.000000f, 4.000000f, 4.000000f },
	&(double4) { 2.000000f, 2.000000f, 2.000000f, 2.000000f },
	&(double4) { 6.000000f, 6.000000f, 6.000000f, 6.000000f }
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double4_caddv,
	&(double4) { 8.000000f, 8.000000f, 8.000000f, 8.000000f },
	&(double4) { 4.000000f, 4.000000f, 4.000000f, 4.000000f },
	&(double4) { 12.000000f, 12.000000f, 12.000000f, 12.000000f }
);

TEMPER_PARAMETRIC( Test_double4_csubv, TEMPER_FLAG_SHOULD_RUN, const double4* lhs, const double4* rhs, const double4* expectedAnswer )
{
	double4 actualResult = double4_csubv( lhs, rhs );
	TEMPER_CHECK_TRUE( double4_equals( &actualResult, expectedAnswer ) );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double4_csubv,
	&(double4) { 1.000000f, 1.000000f, 1.000000f, 1.000000f },
	&(double4) { 1.000000f, 1.000000f, 1.000000f, 1.000000f },
	&(double4) { 0.000000f, 0.000000f, 0.000000f, 0.000000f }
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double4_csubv,
	&(double4) { 2.000000f, 2.000000f, 2.000000f, 2.000000f },
	&(double4) { 2.000000f, 2.000000f, 2.000000f, 2.000000f },
	&(double4) { 0.000000f, 0.000000f, 0.000000f, 0.000000f }
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double4_csubv,
	&(double4) { 4.000000f, 4.000000f, 4.000000f, 4.000000f },
	&(double4) { 2.000000f, 2.000000f, 2.000000f, 2.000000f },
	&(double4) { 2.000000f, 2.000000f, 2.000000f, 2.000000f }
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double4_csubv,
	&(double4) { 8.000000f, 8.000000f, 8.000000f, 8.000000f },
	&(double4) { 4.000000f, 4.000000f, 4.000000f, 4.000000f },
	&(double4) { 4.000000f, 4.000000f, 4.000000f, 4.000000f }
);

TEMPER_PARAMETRIC( Test_double4_cmulv, TEMPER_FLAG_SHOULD_RUN, const double4* lhs, const double4* rhs, const double4* expectedAnswer )
{
	double4 actualResult = double4_cmulv( lhs, rhs );
	TEMPER_CHECK_TRUE( double4_equals( &actualResult, expectedAnswer ) );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double4_cmulv,
	&(double4) { 1.000000f, 1.000000f, 1.000000f, 1.000000f },
	&(double4) { 1.000000f, 1.000000f, 1.000000f, 1.000000f },
	&(double4) { 1.000000f, 1.000000f, 1.000000f, 1.000000f }
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double4_cmulv,
	&(double4) { 2.000000f, 2.000000f, 2.000000f, 2.000000f },
	&(double4) { 2.000000f, 2.000000f, 2.000000f, 2.000000f },
	&(double4) { 4.000000f, 4.000000f, 4.000000f, 4.000000f }
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double4_cmulv,
	&(double4) { 4.000000f, 4.000000f, 4.000000f, 4.000000f },
	&(double4) { 2.000000f, 2.000000f, 2.000000f, 2.000000f },
	&(double4) { 8.000000f, 8.000000f, 8.000000f, 8.000000f }
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double4_cmulv,
	&(double4) { 8.000000f, 8.000000f, 8.000000f, 8.000000f },
	&(double4) { 4.000000f, 4.000000f, 4.000000f, 4.000000f },
	&(double4) { 32.000000f, 32.000000f, 32.000000f, 32.000000f }
);

TEMPER_PARAMETRIC( Test_double4_cdivv, TEMPER_FLAG_SHOULD_RUN, const double4* lhs, const double4* rhs, const double4* expectedAnswer )
{
	double4 actualResult = double4_cdivv( lhs, rhs );
	TEMPER_CHECK_TRUE( double4_equals( &actualResult, expectedAnswer ) );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double4_cdivv,
	&(double4) { 1.000000f, 1.000000f, 1.000000f, 1.000000f },
	&(double4) { 1.000000f, 1.000000f, 1.000000f, 1.000000f },
	&(double4) { 1.000000f, 1.000000f, 1.000000f, 1.000000f }
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double4_cdivv,
	&(double4) { 2.000000f, 2.000000f, 2.000000f, 2.000000f },
	&(double4) { 2.000000f, 2.000000f, 2.000000f, 2.000000f },
	&(double4) { 1.000000f, 1.000000f, 1.000000f, 1.000000f }
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double4_cdivv,
	&(double4) { 4.000000f, 4.000000f, 4.000000f, 4.000000f },
	&(double4) { 2.000000f, 2.000000f, 2.000000f, 2.000000f },
	&(double4) { 2.000000f, 2.000000f, 2.000000f, 2.000000f }
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double4_cdivv,
	&(double4) { 8.000000f, 8.000000f, 8.000000f, 8.000000f },
	&(double4) { 4.000000f, 4.000000f, 4.000000f, 4.000000f },
	&(double4) { 2.000000f, 2.000000f, 2.000000f, 2.000000f }
);

#if defined( __GNUC__ ) || defined( __clang__ )
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wcast-qual"
#endif
TEMPER_PARAMETRIC( Test_double4_negate_prefix, TEMPER_FLAG_SHOULD_RUN, const double4* x, const double4* expectedAnswer )
{
	// make local copy of x and use that because we cant do increment or decrement operations on a const reference
	// and MSVC throws warnings if we just make the parameter a non-const reference
	double4* xlocal = (double4*) x;
	double4 actualAnswer = double4_negate( xlocal );
	TEMPER_CHECK_TRUE( double4_equals( &actualAnswer, expectedAnswer ) );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double4_negate_prefix,
	&(double4) { 0.000000f, 0.000000f, 0.000000f, 0.000000f },
	&(double4) { -0.000000f, -0.000000f, -0.000000f, -0.000000f }
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double4_negate_prefix,
	&(double4) { 1.000000f, 1.000000f, 1.000000f, 1.000000f },
	&(double4) { -1.000000f, -1.000000f, -1.000000f, -1.000000f }
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double4_negate_prefix,
	&(double4) { 2.000000f, 2.000000f, 2.000000f, 2.000000f },
	&(double4) { -2.000000f, -2.000000f, -2.000000f, -2.000000f }
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double4_negate_prefix,
	&(double4) { 3.000000f, 3.000000f, 3.000000f, 3.000000f },
	&(double4) { -3.000000f, -3.000000f, -3.000000f, -3.000000f }
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double4_negate_prefix,
	&(double4) { 10.000000f, 10.000000f, 10.000000f, 10.000000f },
	&(double4) { -10.000000f, -10.000000f, -10.000000f, -10.000000f }
);

#if defined( __GNUC__ ) || defined( __clang__ )
#pragma GCC diagnostic pop
#endif

TEMPER_PARAMETRIC( Test_double4_min, TEMPER_FLAG_SHOULD_RUN, const double4* lhs, const double4* rhs, const double4* expectedAnswer )
{
	double4 actualResult = double4_min( lhs, rhs );
	TEMPER_CHECK_TRUE( double4_equals( &actualResult, expectedAnswer ) );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double4_min,
	&(double4) { 0.000000f, 0.000000f, 0.000000f, 0.000000f },
	&(double4) { 1.000000f, 1.000000f, 1.000000f, 1.000000f },
	&(double4) { 0.000000f, 0.000000f, 0.000000f, 0.000000f }
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double4_min,
	&(double4) { 1.000000f, 1.000000f, 1.000000f, 1.000000f },
	&(double4) { 2.000000f, 2.000000f, 2.000000f, 2.000000f },
	&(double4) { 1.000000f, 1.000000f, 1.000000f, 1.000000f }
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double4_min,
	&(double4) { 420.000000f, 420.000000f, 420.000000f, 420.000000f },
	&(double4) { 69.000000f, 69.000000f, 69.000000f, 69.000000f },
	&(double4) { 69.000000f, 69.000000f, 69.000000f, 69.000000f }
);

TEMPER_PARAMETRIC( Test_double4_max, TEMPER_FLAG_SHOULD_RUN, const double4* lhs, const double4* rhs, const double4* expectedAnswer )
{
	double4 actualResult = double4_max( lhs, rhs );
	TEMPER_CHECK_TRUE( double4_equals( &actualResult, expectedAnswer ) );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double4_max,
	&(double4) { 0.000000f, 0.000000f, 0.000000f, 0.000000f },
	&(double4) { 1.000000f, 1.000000f, 1.000000f, 1.000000f },
	&(double4) { 1.000000f, 1.000000f, 1.000000f, 1.000000f }
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double4_max,
	&(double4) { 1.000000f, 1.000000f, 1.000000f, 1.000000f },
	&(double4) { 2.000000f, 2.000000f, 2.000000f, 2.000000f },
	&(double4) { 2.000000f, 2.000000f, 2.000000f, 2.000000f }
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double4_max,
	&(double4) { 69.000000f, 69.000000f, 69.000000f, 69.000000f },
	&(double4) { 420.000000f, 420.000000f, 420.000000f, 420.000000f },
	&(double4) { 420.000000f, 420.000000f, 420.000000f, 420.000000f }
);

TEMPER_PARAMETRIC( Test_double4_saturate, TEMPER_FLAG_SHOULD_RUN, const double4* x, const double4* expectedAnswer )
{
	double4 actualResult = double4_saturate( x );
	TEMPER_CHECK_TRUE( double4_equals( &actualResult, expectedAnswer ) );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double4_saturate,
	&(double4) { 0.000000f, 0.000000f, 0.000000f, 0.000000f },
	&(double4) { 0.000000f, 0.000000f, 0.000000f, 0.000000f }
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double4_saturate,
	&(double4) { 1.000000f, 1.000000f, 1.000000f, 1.000000f },
	&(double4) { 1.000000f, 1.000000f, 1.000000f, 1.000000f }
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double4_saturate,
	&(double4) { 2.000000f, 2.000000f, 2.000000f, 2.000000f },
	&(double4) { 1.000000f, 1.000000f, 1.000000f, 1.000000f }
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double4_saturate,
	&(double4) { 3.000000f, 3.000000f, 3.000000f, 3.000000f },
	&(double4) { 1.000000f, 1.000000f, 1.000000f, 1.000000f }
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double4_saturate,
	&(double4) { 10.000000f, 10.000000f, 10.000000f, 10.000000f },
	&(double4) { 1.000000f, 1.000000f, 1.000000f, 1.000000f }
);

TEMPER_PARAMETRIC( Test_double4_sign, TEMPER_FLAG_SHOULD_RUN, const double4* x, const int4* expectedAnswer )
{
	int4 actualResult = double4_sign( x );
	TEMPER_CHECK_TRUE( int4_equals( &actualResult, expectedAnswer ) );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double4_sign,
	&(double4) { 0.000000f, 0.000000f, 0.000000f, 0.000000f },
	&(int4) { 0, 0, 0, 0 }
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double4_sign,
	&(double4) { 1.000000f, 1.000000f, 1.000000f, 1.000000f },
	&(int4) { 1, 1, 1, 1 }
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double4_sign,
	&(double4) { 2.000000f, 2.000000f, 2.000000f, 2.000000f },
	&(int4) { 1, 1, 1, 1 }
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double4_sign,
	&(double4) { 3.000000f, 3.000000f, 3.000000f, 3.000000f },
	&(int4) { 1, 1, 1, 1 }
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double4_sign,
	&(double4) { -1.000000f, -1.000000f, -1.000000f, -1.000000f },
	&(int4) { -1, -1, -1, -1 }
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double4_sign,
	&(double4) { -2.000000f, -2.000000f, -2.000000f, -2.000000f },
	&(int4) { -1, -1, -1, -1 }
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double4_sign,
	&(double4) { -3.000000f, -3.000000f, -3.000000f, -3.000000f },
	&(int4) { -1, -1, -1, -1 }
);

TEMPER_PARAMETRIC( Test_double4_lerp, TEMPER_FLAG_SHOULD_RUN, const double4* lhs, const double4* rhs, const double t, const double4* expectedAnswer )
{
	double4 actualResult = double4_lerp( lhs, rhs, t );
	TEMPER_CHECK_TRUE( double4_equals( &actualResult, expectedAnswer ) );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double4_lerp,
	&(double4) { 0.000000f, 0.000000f, 0.000000f, 0.000000f },
	&(double4) { 1.000000f, 1.000000f, 1.000000f, 1.000000f },
	0.500000f,
	&(double4) { 0.500000f, 0.500000f, 0.500000f, 0.500000f }
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double4_lerp,
	&(double4) { 1.000000f, 1.000000f, 1.000000f, 1.000000f },
	&(double4) { 3.000000f, 3.000000f, 3.000000f, 3.000000f },
	0.500000f,
	&(double4) { 2.000000f, 2.000000f, 2.000000f, 2.000000f }
);

TEMPER_PARAMETRIC( Test_double4_quat_length, TEMPER_FLAG_SHOULD_RUN, const double4* quat, const double expectedAnswer )
{
	double actualResult = double4_quat_length( quat );
	TEMPER_CHECK_TRUE( doubleeq( actualResult, expectedAnswer ) );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double4_quat_length,
	&(double4) { 0.000000f, 0.000000f, 0.000000f, 0.000000f },
	0.000000f
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double4_quat_length,
	&(double4) { 1.000000f, 1.000000f, 1.000000f, 1.000000f },
	2.000000f
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double4_quat_length,
	&(double4) { 2.000000f, 2.000000f, 2.000000f, 2.000000f },
	4.000000f
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double4_quat_length,
	&(double4) { 3.000000f, 3.000000f, 3.000000f, 3.000000f },
	6.000000f
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double4_quat_length,
	&(double4) { 4.000000f, 4.000000f, 4.000000f, 4.000000f },
	8.000000f
);

TEMPER_PARAMETRIC( Test_double4_quat_lerp, TEMPER_FLAG_SHOULD_RUN, const double4* lhs, const double4* rhs, const double t, const double4* expectedAnswer )
{
	double4 actualResult = double4_quat_lerp( lhs, rhs, t );
	TEMPER_CHECK_TRUE( double4_equals( &actualResult, expectedAnswer ) );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double4_quat_lerp,
	&(double4) { 0.000000f, 0.000000f, 0.000000f, 0.000000f },
	&(double4) { 1.000000f, 1.000000f, 1.000000f, 1.000000f },
	0.500000f,
	&(double4) { 0.500000f, 0.500000f, 0.500000f, 0.500000f }
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double4_quat_lerp,
	&(double4) { 0.000000f, 0.000000f, 0.000000f, 0.000000f },
	&(double4) { 1.000000f, 1.000000f, 1.000000f, 1.000000f },
	0.250000f,
	&(double4) { 0.250000f, 0.250000f, 0.250000f, 0.250000f }
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double4_quat_lerp,
	&(double4) { 0.000000f, 0.000000f, 0.000000f, 0.000000f },
	&(double4) { 1.000000f, 1.000000f, 1.000000f, 1.000000f },
	0.750000f,
	&(double4) { 0.750000f, 0.750000f, 0.750000f, 0.750000f }
);

TEMPER_PARAMETRIC( Test_double4_quat_slerp, TEMPER_FLAG_SHOULD_RUN, const double4* lhs, const double4* rhs, const double t, const double4* expectedAnswer )
{
	double4 actualResult = double4_quat_slerp( lhs, rhs, t );
	TEMPER_CHECK_TRUE( double4_equals( &actualResult, expectedAnswer ) );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double4_quat_slerp,
	&(double4) { 0.000000f, 0.000000f, 0.000000f, 0.000000f },
	&(double4) { 1.000000f, 1.000000f, 1.000000f, 1.000000f },
	0.500000f,
	&(double4) { 0.707107f, 0.707107f, 0.707107f, 0.707107f }
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double4_quat_slerp,
	&(double4) { 0.000000f, 0.000000f, 0.000000f, 0.000000f },
	&(double4) { 1.000000f, 1.000000f, 1.000000f, 1.000000f },
	0.250000f,
	&(double4) { 0.382683f, 0.382683f, 0.382683f, 0.382683f }
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double4_quat_slerp,
	&(double4) { 0.000000f, 0.000000f, 0.000000f, 0.000000f },
	&(double4) { 1.000000f, 1.000000f, 1.000000f, 1.000000f },
	0.750000f,
	&(double4) { 0.923880f, 0.923880f, 0.923880f, 0.923880f }
);

TEMPER_PARAMETRIC( Test_double4_lengthsq, TEMPER_FLAG_SHOULD_RUN, const double4* vec, const double expectedAnswer )
{
	double actualResult = double4_lengthsq( vec );
	TEMPER_CHECK_TRUE( doubleeq( actualResult, expectedAnswer ) );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double4_lengthsq,
	&(double4) { 0.000000f, 0.000000f, 0.000000f, 0.000000f },
	0.000000f
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double4_lengthsq,
	&(double4) { 1.000000f, 1.000000f, 1.000000f, 1.000000f },
	4.000000f
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double4_lengthsq,
	&(double4) { 2.000000f, 2.000000f, 2.000000f, 2.000000f },
	16.000000f
);

TEMPER_PARAMETRIC( Test_double4_length, TEMPER_FLAG_SHOULD_RUN, const double4* vec, const double expectedAnswer )
{
	double actualResult = double4_length( vec );
	TEMPER_CHECK_TRUE( doubleeq( actualResult, expectedAnswer ) );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double4_length,
	&(double4) { 0.000000f, 0.000000f, 0.000000f, 0.000000f },
	0.000000f
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double4_length,
	&(double4) { 1.000000f, 1.000000f, 1.000000f, 1.000000f },
	2.000000f
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double4_length,
	&(double4) { 2.000000f, 2.000000f, 2.000000f, 2.000000f },
	4.000000f
);

TEMPER_PARAMETRIC( Test_double4_dot, TEMPER_FLAG_SHOULD_RUN, const double4* lhs, const double4* rhs, const double expectedAnswer )
{
	double actualResult = double4_dot( lhs, rhs );
	TEMPER_CHECK_TRUE( doubleeq( actualResult, expectedAnswer ) );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double4_dot,
	&(double4) { 0.000000f, 0.000000f, 0.000000f, 0.000000f },
	&(double4) { 1.000000f, 1.000000f, 1.000000f, 1.000000f },
	0.000000f
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double4_dot,
	&(double4) { 1.000000f, 1.000000f, 1.000000f, 1.000000f },
	&(double4) { 1.000000f, 1.000000f, 1.000000f, 1.000000f },
	4.000000f
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double4_dot,
	&(double4) { 1.000000f, 1.000000f, 1.000000f, 1.000000f },
	&(double4) { -1.000000f, -1.000000f, -1.000000f, -1.000000f },
	-4.000000f
);


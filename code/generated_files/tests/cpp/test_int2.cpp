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

TEMPER_PARAMETRIC( Test_int2_less_than, TEMPER_FLAG_SHOULD_RUN, const int2& lhs, const int2& rhs, const bool2& expectedAnswer )
{
	bool2 actualResult = lhs < rhs;
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_less_than,
	int2( 0, 0 ),
	int2( 0, 0 ),
	bool2( false, false )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_less_than,
	int2( 0, 0 ),
	int2( 1, 1 ),
	bool2( true, true )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_less_than,
	int2( 1, 1 ),
	int2( 1, 1 ),
	bool2( false, false )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_less_than,
	int2( 1, 1 ),
	int2( 0, 0 ),
	bool2( false, false )
);

TEMPER_PARAMETRIC( Test_int2_less_than_equal, TEMPER_FLAG_SHOULD_RUN, const int2& lhs, const int2& rhs, const bool2& expectedAnswer )
{
	bool2 actualResult = lhs <= rhs;
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_less_than_equal,
	int2( 0, 0 ),
	int2( 0, 0 ),
	bool2( true, true )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_less_than_equal,
	int2( 0, 0 ),
	int2( 1, 1 ),
	bool2( true, true )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_less_than_equal,
	int2( 1, 1 ),
	int2( 1, 1 ),
	bool2( true, true )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_less_than_equal,
	int2( 1, 1 ),
	int2( 0, 0 ),
	bool2( false, false )
);

TEMPER_PARAMETRIC( Test_int2_greater_than, TEMPER_FLAG_SHOULD_RUN, const int2& lhs, const int2& rhs, const bool2& expectedAnswer )
{
	bool2 actualResult = lhs > rhs;
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_greater_than,
	int2( 0, 0 ),
	int2( 0, 0 ),
	bool2( false, false )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_greater_than,
	int2( 0, 0 ),
	int2( 1, 1 ),
	bool2( false, false )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_greater_than,
	int2( 1, 1 ),
	int2( 1, 1 ),
	bool2( false, false )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_greater_than,
	int2( 1, 1 ),
	int2( 0, 0 ),
	bool2( true, true )
);

TEMPER_PARAMETRIC( Test_int2_greater_than_equal, TEMPER_FLAG_SHOULD_RUN, const int2& lhs, const int2& rhs, const bool2& expectedAnswer )
{
	bool2 actualResult = lhs >= rhs;
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_greater_than_equal,
	int2( 0, 0 ),
	int2( 0, 0 ),
	bool2( true, true )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_greater_than_equal,
	int2( 0, 0 ),
	int2( 1, 1 ),
	bool2( false, false )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_greater_than_equal,
	int2( 1, 1 ),
	int2( 1, 1 ),
	bool2( true, true )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_greater_than_equal,
	int2( 1, 1 ),
	int2( 0, 0 ),
	bool2( true, true )
);

TEMPER_PARAMETRIC( Test_int2_cadds, TEMPER_FLAG_SHOULD_RUN, const int2& lhs, const int32_t& rhs, const int2& expectedAnswer )
{
	int2 actualResult = lhs + rhs;
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_cadds,
	int2( 1, 1 ),
	1,
	int2( 2, 2 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_cadds,
	int2( 2, 2 ),
	2,
	int2( 4, 4 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_cadds,
	int2( 4, 4 ),
	2,
	int2( 6, 6 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_cadds,
	int2( 8, 8 ),
	4,
	int2( 12, 12 )
);

TEMPER_PARAMETRIC( Test_int2_csubs, TEMPER_FLAG_SHOULD_RUN, const int2& lhs, const int32_t& rhs, const int2& expectedAnswer )
{
	int2 actualResult = lhs - rhs;
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_csubs,
	int2( 1, 1 ),
	1,
	int2( 0, 0 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_csubs,
	int2( 2, 2 ),
	2,
	int2( 0, 0 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_csubs,
	int2( 4, 4 ),
	2,
	int2( 2, 2 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_csubs,
	int2( 8, 8 ),
	4,
	int2( 4, 4 )
);

TEMPER_PARAMETRIC( Test_int2_cmuls, TEMPER_FLAG_SHOULD_RUN, const int2& lhs, const int32_t& rhs, const int2& expectedAnswer )
{
	int2 actualResult = lhs * rhs;
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_cmuls,
	int2( 1, 1 ),
	1,
	int2( 1, 1 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_cmuls,
	int2( 2, 2 ),
	2,
	int2( 4, 4 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_cmuls,
	int2( 4, 4 ),
	2,
	int2( 8, 8 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_cmuls,
	int2( 8, 8 ),
	4,
	int2( 32, 32 )
);

TEMPER_PARAMETRIC( Test_int2_cdivs, TEMPER_FLAG_SHOULD_RUN, const int2& lhs, const int32_t& rhs, const int2& expectedAnswer )
{
	int2 actualResult = lhs / rhs;
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_cdivs,
	int2( 1, 1 ),
	1,
	int2( 1, 1 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_cdivs,
	int2( 2, 2 ),
	2,
	int2( 1, 1 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_cdivs,
	int2( 4, 4 ),
	2,
	int2( 2, 2 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_cdivs,
	int2( 8, 8 ),
	4,
	int2( 2, 2 )
);

TEMPER_PARAMETRIC( Test_int2_caddv, TEMPER_FLAG_SHOULD_RUN, const int2& lhs, const int2& rhs, const int2& expectedAnswer )
{
	int2 actualResult = lhs + rhs;
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_caddv,
	int2( 1, 1 ),
	int2( 1, 1 ),
	int2( 2, 2 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_caddv,
	int2( 2, 2 ),
	int2( 2, 2 ),
	int2( 4, 4 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_caddv,
	int2( 4, 4 ),
	int2( 2, 2 ),
	int2( 6, 6 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_caddv,
	int2( 8, 8 ),
	int2( 4, 4 ),
	int2( 12, 12 )
);

TEMPER_PARAMETRIC( Test_int2_csubv, TEMPER_FLAG_SHOULD_RUN, const int2& lhs, const int2& rhs, const int2& expectedAnswer )
{
	int2 actualResult = lhs - rhs;
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_csubv,
	int2( 1, 1 ),
	int2( 1, 1 ),
	int2( 0, 0 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_csubv,
	int2( 2, 2 ),
	int2( 2, 2 ),
	int2( 0, 0 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_csubv,
	int2( 4, 4 ),
	int2( 2, 2 ),
	int2( 2, 2 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_csubv,
	int2( 8, 8 ),
	int2( 4, 4 ),
	int2( 4, 4 )
);

TEMPER_PARAMETRIC( Test_int2_cmulv, TEMPER_FLAG_SHOULD_RUN, const int2& lhs, const int2& rhs, const int2& expectedAnswer )
{
	int2 actualResult = lhs * rhs;
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_cmulv,
	int2( 1, 1 ),
	int2( 1, 1 ),
	int2( 1, 1 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_cmulv,
	int2( 2, 2 ),
	int2( 2, 2 ),
	int2( 4, 4 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_cmulv,
	int2( 4, 4 ),
	int2( 2, 2 ),
	int2( 8, 8 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_cmulv,
	int2( 8, 8 ),
	int2( 4, 4 ),
	int2( 32, 32 )
);

TEMPER_PARAMETRIC( Test_int2_cdivv, TEMPER_FLAG_SHOULD_RUN, const int2& lhs, const int2& rhs, const int2& expectedAnswer )
{
	int2 actualResult = lhs / rhs;
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_cdivv,
	int2( 1, 1 ),
	int2( 1, 1 ),
	int2( 1, 1 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_cdivv,
	int2( 2, 2 ),
	int2( 2, 2 ),
	int2( 1, 1 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_cdivv,
	int2( 4, 4 ),
	int2( 2, 2 ),
	int2( 2, 2 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_cdivv,
	int2( 8, 8 ),
	int2( 4, 4 ),
	int2( 2, 2 )
);

#if defined( __GNUC__ ) || defined( __clang__ )
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wcast-qual"
#endif

TEMPER_PARAMETRIC( Test_int2_increment_prefix, TEMPER_FLAG_SHOULD_RUN, const int2& x, const int2& expectedAnswer )
{
	// make local copy of x and use that because we cant do increment or decrement operations on a const reference
	// and MSVC throws warnings if we just make the parameter a non-const reference
	int2 xlocal = (int2) x;
	int2 actualAnswer = ++xlocal;
	TEMPER_CHECK_TRUE( actualAnswer == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_increment_prefix,
	int2( 1, 1 ),
	int2( 2, 2 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_increment_prefix,
	int2( 2, 2 ),
	int2( 3, 3 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_increment_prefix,
	int2( 3, 3 ),
	int2( 4, 4 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_increment_prefix,
	int2( 4, 4 ),
	int2( 5, 5 )
);

TEMPER_PARAMETRIC( Test_int2_increment_postfix, TEMPER_FLAG_SHOULD_RUN, const int2& x, const int2& expectedAnswer )
{
	// make local copy of x and use that because we cant do increment or decrement operations on a const reference
	// and MSVC throws warnings if we just make the parameter a non-const reference
	int2 xlocal = (int2) x;
	int2 actualAnswer = xlocal++;
	TEMPER_CHECK_TRUE( actualAnswer == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_increment_postfix,
	int2( 1, 1 ),
	int2( 2, 2 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_increment_postfix,
	int2( 2, 2 ),
	int2( 3, 3 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_increment_postfix,
	int2( 3, 3 ),
	int2( 4, 4 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_increment_postfix,
	int2( 4, 4 ),
	int2( 5, 5 )
);

TEMPER_PARAMETRIC( Test_int2_decrement_prefix, TEMPER_FLAG_SHOULD_RUN, const int2& x, const int2& expectedAnswer )
{
	// make local copy of x and use that because we cant do increment or decrement operations on a const reference
	// and MSVC throws warnings if we just make the parameter a non-const reference
	int2 xlocal = (int2) x;
	int2 actualAnswer = --xlocal;
	TEMPER_CHECK_TRUE( actualAnswer == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_decrement_prefix,
	int2( 1, 1 ),
	int2( 0, 0 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_decrement_prefix,
	int2( 2, 2 ),
	int2( 1, 1 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_decrement_prefix,
	int2( 3, 3 ),
	int2( 2, 2 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_decrement_prefix,
	int2( 4, 4 ),
	int2( 3, 3 )
);

TEMPER_PARAMETRIC( Test_int2_decrement_postfix, TEMPER_FLAG_SHOULD_RUN, const int2& x, const int2& expectedAnswer )
{
	// make local copy of x and use that because we cant do increment or decrement operations on a const reference
	// and MSVC throws warnings if we just make the parameter a non-const reference
	int2 xlocal = (int2) x;
	int2 actualAnswer = xlocal--;
	TEMPER_CHECK_TRUE( actualAnswer == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_decrement_postfix,
	int2( 1, 1 ),
	int2( 0, 0 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_decrement_postfix,
	int2( 2, 2 ),
	int2( 1, 1 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_decrement_postfix,
	int2( 3, 3 ),
	int2( 2, 2 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_decrement_postfix,
	int2( 4, 4 ),
	int2( 3, 3 )
);

#if defined( __GNUC__ ) || defined( __clang__ )
#pragma GCC diagnostic pop
#endif
#if defined( __GNUC__ ) || defined( __clang__ )
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wcast-qual"
#endif
TEMPER_PARAMETRIC( Test_int2_negate_prefix, TEMPER_FLAG_SHOULD_RUN, const int2& x, const int2& expectedAnswer )
{
	// make local copy of x and use that because we cant do increment or decrement operations on a const reference
	// and MSVC throws warnings if we just make the parameter a non-const reference
	int2 xlocal = (int2) x;
	int2 actualAnswer = -xlocal;
	TEMPER_CHECK_TRUE( actualAnswer == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_negate_prefix,
	int2( 0, 0 ),
	int2( 0, 0 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_negate_prefix,
	int2( 1, 1 ),
	int2( -1, -1 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_negate_prefix,
	int2( 2, 2 ),
	int2( -2, -2 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_negate_prefix,
	int2( 3, 3 ),
	int2( -3, -3 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_negate_prefix,
	int2( 10, 10 ),
	int2( -10, -10 )
);

#if defined( __GNUC__ ) || defined( __clang__ )
#pragma GCC diagnostic pop
#endif

#if defined( __GNUC__ ) || defined( __clang__ )
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wcast-qual"
#endif
TEMPER_PARAMETRIC( Test_int2_unary_prefix, TEMPER_FLAG_SHOULD_RUN, const int2& x, const int2& expectedAnswer )
{
	// make local copy of x and use that because we cant do increment or decrement operations on a const reference
	// and MSVC throws warnings if we just make the parameter a non-const reference
	int2 xlocal = (int2) x;
	int2 actualAnswer = ~xlocal;
	TEMPER_CHECK_TRUE( actualAnswer == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_unary_prefix,
	int2( 1, 1 ),
	int2( -2, -2 )
);

#if defined( __GNUC__ ) || defined( __clang__ )
#pragma GCC diagnostic pop
#endif

TEMPER_PARAMETRIC( Test_int2_cands, TEMPER_FLAG_SHOULD_RUN, const int2& lhs, const int32_t& rhs, const int2& expectedAnswer )
{
	int2 actualResult = lhs & rhs;
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_cands,
	int2( 0, 0 ),
	0,
	int2( 0, 0 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_cands,
	int2( 2, 2 ),
	1,
	int2( 0, 0 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_cands,
	int2( 1, 1 ),
	0,
	int2( 0, 0 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_cands,
	int2( 1, 1 ),
	1,
	int2( 1, 1 )
);

TEMPER_PARAMETRIC( Test_int2_cors, TEMPER_FLAG_SHOULD_RUN, const int2& lhs, const int32_t& rhs, const int2& expectedAnswer )
{
	int2 actualResult = lhs | rhs;
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_cors,
	int2( 0, 0 ),
	0,
	int2( 0, 0 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_cors,
	int2( 2, 2 ),
	1,
	int2( 3, 3 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_cors,
	int2( 1, 1 ),
	0,
	int2( 1, 1 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_cors,
	int2( 1, 1 ),
	1,
	int2( 1, 1 )
);

TEMPER_PARAMETRIC( Test_int2_cxors, TEMPER_FLAG_SHOULD_RUN, const int2& lhs, const int32_t& rhs, const int2& expectedAnswer )
{
	int2 actualResult = lhs ^ rhs;
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_cxors,
	int2( 0, 0 ),
	0,
	int2( 0, 0 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_cxors,
	int2( 2, 2 ),
	1,
	int2( 3, 3 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_cxors,
	int2( 1, 1 ),
	0,
	int2( 1, 1 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_cxors,
	int2( 1, 1 ),
	1,
	int2( 0, 0 )
);

TEMPER_PARAMETRIC( Test_int2_cshift_lefts, TEMPER_FLAG_SHOULD_RUN, const int2& lhs, const int32_t& rhs, const int2& expectedAnswer )
{
	int2 actualResult = lhs << rhs;
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_cshift_lefts,
	int2( 0, 0 ),
	0,
	int2( 0, 0 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_cshift_lefts,
	int2( 2, 2 ),
	1,
	int2( 4, 4 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_cshift_lefts,
	int2( 1, 1 ),
	0,
	int2( 1, 1 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_cshift_lefts,
	int2( 1, 1 ),
	1,
	int2( 2, 2 )
);

TEMPER_PARAMETRIC( Test_int2_cshift_rights, TEMPER_FLAG_SHOULD_RUN, const int2& lhs, const int32_t& rhs, const int2& expectedAnswer )
{
	int2 actualResult = lhs >> rhs;
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_cshift_rights,
	int2( 0, 0 ),
	0,
	int2( 0, 0 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_cshift_rights,
	int2( 2, 2 ),
	1,
	int2( 1, 1 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_cshift_rights,
	int2( 1, 1 ),
	0,
	int2( 1, 1 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_cshift_rights,
	int2( 1, 1 ),
	1,
	int2( 0, 0 )
);

TEMPER_PARAMETRIC( Test_int2_candv, TEMPER_FLAG_SHOULD_RUN, const int2& lhs, const int2& rhs, const int2& expectedAnswer )
{
	int2 actualResult = lhs & rhs;
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_candv,
	int2( 0, 0 ),
	int2( 0, 0 ),
	int2( 0, 0 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_candv,
	int2( 2, 2 ),
	int2( 1, 1 ),
	int2( 0, 0 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_candv,
	int2( 1, 1 ),
	int2( 0, 0 ),
	int2( 0, 0 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_candv,
	int2( 1, 1 ),
	int2( 1, 1 ),
	int2( 1, 1 )
);

TEMPER_PARAMETRIC( Test_int2_corv, TEMPER_FLAG_SHOULD_RUN, const int2& lhs, const int2& rhs, const int2& expectedAnswer )
{
	int2 actualResult = lhs | rhs;
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_corv,
	int2( 0, 0 ),
	int2( 0, 0 ),
	int2( 0, 0 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_corv,
	int2( 2, 2 ),
	int2( 1, 1 ),
	int2( 3, 3 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_corv,
	int2( 1, 1 ),
	int2( 0, 0 ),
	int2( 1, 1 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_corv,
	int2( 1, 1 ),
	int2( 1, 1 ),
	int2( 1, 1 )
);

TEMPER_PARAMETRIC( Test_int2_cxorv, TEMPER_FLAG_SHOULD_RUN, const int2& lhs, const int2& rhs, const int2& expectedAnswer )
{
	int2 actualResult = lhs ^ rhs;
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_cxorv,
	int2( 0, 0 ),
	int2( 0, 0 ),
	int2( 0, 0 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_cxorv,
	int2( 2, 2 ),
	int2( 1, 1 ),
	int2( 3, 3 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_cxorv,
	int2( 1, 1 ),
	int2( 0, 0 ),
	int2( 1, 1 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_cxorv,
	int2( 1, 1 ),
	int2( 1, 1 ),
	int2( 0, 0 )
);

TEMPER_PARAMETRIC( Test_int2_cshift_leftv, TEMPER_FLAG_SHOULD_RUN, const int2& lhs, const int2& rhs, const int2& expectedAnswer )
{
	int2 actualResult = lhs << rhs;
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_cshift_leftv,
	int2( 0, 0 ),
	int2( 0, 0 ),
	int2( 0, 0 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_cshift_leftv,
	int2( 2, 2 ),
	int2( 1, 1 ),
	int2( 4, 4 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_cshift_leftv,
	int2( 1, 1 ),
	int2( 0, 0 ),
	int2( 1, 1 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_cshift_leftv,
	int2( 1, 1 ),
	int2( 1, 1 ),
	int2( 2, 2 )
);

TEMPER_PARAMETRIC( Test_int2_cshift_rightv, TEMPER_FLAG_SHOULD_RUN, const int2& lhs, const int2& rhs, const int2& expectedAnswer )
{
	int2 actualResult = lhs >> rhs;
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_cshift_rightv,
	int2( 0, 0 ),
	int2( 0, 0 ),
	int2( 0, 0 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_cshift_rightv,
	int2( 2, 2 ),
	int2( 1, 1 ),
	int2( 1, 1 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_cshift_rightv,
	int2( 1, 1 ),
	int2( 0, 0 ),
	int2( 1, 1 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_cshift_rightv,
	int2( 1, 1 ),
	int2( 1, 1 ),
	int2( 0, 0 )
);

TEMPER_PARAMETRIC( Test_int2_min, TEMPER_FLAG_SHOULD_RUN, const int2& lhs, const int2& rhs, const int2& expectedAnswer )
{
	int2 actualResult = min( lhs, rhs );
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_min,
	int2( 0, 0 ),
	int2( 1, 1 ),
	int2( 0, 0 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_min,
	int2( 1, 1 ),
	int2( 2, 2 ),
	int2( 1, 1 )
);

TEMPER_PARAMETRIC( Test_int2_max, TEMPER_FLAG_SHOULD_RUN, const int2& lhs, const int2& rhs, const int2& expectedAnswer )
{
	int2 actualResult = max( lhs, rhs );
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_max,
	int2( 1, 1 ),
	int2( 0, 0 ),
	int2( 1, 1 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_max,
	int2( 2, 2 ),
	int2( 1, 1 ),
	int2( 2, 2 )
);

TEMPER_PARAMETRIC( Test_int2_saturate, TEMPER_FLAG_SHOULD_RUN, const int2& x, const int2& expectedAnswer )
{
	int2 actualResult = saturate( x );
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_saturate,
	int2( 0, 0 ),
	int2( 0, 0 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_saturate,
	int2( 1, 1 ),
	int2( 1, 1 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_saturate,
	int2( 2, 2 ),
	int2( 1, 1 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_saturate,
	int2( 3, 3 ),
	int2( 1, 1 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_saturate,
	int2( 10, 10 ),
	int2( 1, 1 )
);

TEMPER_PARAMETRIC( Test_int2_sign, TEMPER_FLAG_SHOULD_RUN, const int2& x, const int2& expectedAnswer )
{
	int2 actualResult = sign( x );
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_sign,
	int2( 0, 0 ),
	int2( 0, 0 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_sign,
	int2( 1, 1 ),
	int2( 1, 1 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_sign,
	int2( 2, 2 ),
	int2( 1, 1 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_sign,
	int2( 3, 3 ),
	int2( 1, 1 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_sign,
	int2( -1, -1 ),
	int2( -1, -1 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_sign,
	int2( -2, -2 ),
	int2( -1, -1 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_sign,
	int2( -3, -3 ),
	int2( -1, -1 )
);

TEMPER_PARAMETRIC( Test_int2_lengthsq, TEMPER_FLAG_SHOULD_RUN, const int2& vec, const float expectedAnswer )
{
	float actualResult = lengthsq( vec );
	TEMPER_CHECK_TRUE( floateq( actualResult, expectedAnswer ) );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_lengthsq,
	int2( 0, 0 ),
	0.000000f
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_lengthsq,
	int2( 1, 1 ),
	2.000000f
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_lengthsq,
	int2( 2, 2 ),
	8.000000f
);

TEMPER_PARAMETRIC( Test_int2_length, TEMPER_FLAG_SHOULD_RUN, const int2& vec, const float expectedAnswer )
{
	float actualResult = length( vec );
	TEMPER_CHECK_TRUE( floateq( actualResult, expectedAnswer ) );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_length,
	int2( 0, 0 ),
	0.000000f
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_length,
	int2( 1, 1 ),
	1.414214f
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_length,
	int2( 2, 2 ),
	2.828427f
);

TEMPER_PARAMETRIC( Test_int2_dot, TEMPER_FLAG_SHOULD_RUN, const int2& lhs, const int2& rhs, const int32_t expectedAnswer )
{
	int32_t actualResult = dot( lhs, rhs );
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_dot,
	int2( 0, 0 ),
	int2( 1, 1 ),
	0
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_dot,
	int2( 1, 1 ),
	int2( 1, 1 ),
	2
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_dot,
	int2( 1, 1 ),
	int2( -1, -1 ),
	-2
);

TEMPER_PARAMETRIC( Test_int2_distancesq, TEMPER_FLAG_SHOULD_RUN, const int2& lhs, const int2& rhs, const float expectedAnswer )
{
	float actualResult = distancesq( lhs, rhs );
	TEMPER_CHECK_TRUE( floateq( actualResult, expectedAnswer ) );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_distancesq,
	int2( 0, 0 ),
	int2( 0, 0 ),
	0.000000f
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_distancesq,
	int2( 0, 0 ),
	int2( 1, 1 ),
	2.000000f
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_distancesq,
	int2( 0, 0 ),
	int2( 2, 2 ),
	8.000000f
);

TEMPER_PARAMETRIC( Test_int2_distance, TEMPER_FLAG_SHOULD_RUN, const int2& lhs, const int2& rhs, const float expectedAnswer )
{
	float actualResult = distance( lhs, rhs );
	TEMPER_CHECK_TRUE( floateq( actualResult, expectedAnswer ) );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_distance,
	int2( 0, 0 ),
	int2( 0, 0 ),
	0.000000f
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_distance,
	int2( 0, 0 ),
	int2( 1, 1 ),
	1.414214f
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_distance,
	int2( 0, 0 ),
	int2( 2, 2 ),
	2.828427f
);


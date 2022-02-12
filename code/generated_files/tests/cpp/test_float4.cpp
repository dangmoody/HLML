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

TEMPER_PARAMETRIC( Test_float4_less_than, TEMPER_FLAG_SHOULD_RUN, const float4& lhs, const float4& rhs, const bool4& expectedAnswer )
{
	bool4 actualResult = lhs < rhs;
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float4_less_than,
	float4( 0.000000f, 0.000000f, 0.000000f, 0.000000f ),
	float4( 0.000000f, 0.000000f, 0.000000f, 0.000000f ),
	bool4( false, false, false, false )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float4_less_than,
	float4( 0.000000f, 0.000000f, 0.000000f, 0.000000f ),
	float4( 1.000000f, 1.000000f, 1.000000f, 1.000000f ),
	bool4( true, true, true, true )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float4_less_than,
	float4( 1.000000f, 1.000000f, 1.000000f, 1.000000f ),
	float4( 1.000000f, 1.000000f, 1.000000f, 1.000000f ),
	bool4( false, false, false, false )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float4_less_than,
	float4( 1.000000f, 1.000000f, 1.000000f, 1.000000f ),
	float4( 0.000000f, 0.000000f, 0.000000f, 0.000000f ),
	bool4( false, false, false, false )
);

TEMPER_PARAMETRIC( Test_float4_less_than_equal, TEMPER_FLAG_SHOULD_RUN, const float4& lhs, const float4& rhs, const bool4& expectedAnswer )
{
	bool4 actualResult = lhs <= rhs;
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float4_less_than_equal,
	float4( 0.000000f, 0.000000f, 0.000000f, 0.000000f ),
	float4( 0.000000f, 0.000000f, 0.000000f, 0.000000f ),
	bool4( true, true, true, true )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float4_less_than_equal,
	float4( 0.000000f, 0.000000f, 0.000000f, 0.000000f ),
	float4( 1.000000f, 1.000000f, 1.000000f, 1.000000f ),
	bool4( true, true, true, true )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float4_less_than_equal,
	float4( 1.000000f, 1.000000f, 1.000000f, 1.000000f ),
	float4( 1.000000f, 1.000000f, 1.000000f, 1.000000f ),
	bool4( true, true, true, true )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float4_less_than_equal,
	float4( 1.000000f, 1.000000f, 1.000000f, 1.000000f ),
	float4( 0.000000f, 0.000000f, 0.000000f, 0.000000f ),
	bool4( false, false, false, false )
);

TEMPER_PARAMETRIC( Test_float4_greater_than, TEMPER_FLAG_SHOULD_RUN, const float4& lhs, const float4& rhs, const bool4& expectedAnswer )
{
	bool4 actualResult = lhs > rhs;
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float4_greater_than,
	float4( 0.000000f, 0.000000f, 0.000000f, 0.000000f ),
	float4( 0.000000f, 0.000000f, 0.000000f, 0.000000f ),
	bool4( false, false, false, false )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float4_greater_than,
	float4( 0.000000f, 0.000000f, 0.000000f, 0.000000f ),
	float4( 1.000000f, 1.000000f, 1.000000f, 1.000000f ),
	bool4( false, false, false, false )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float4_greater_than,
	float4( 1.000000f, 1.000000f, 1.000000f, 1.000000f ),
	float4( 1.000000f, 1.000000f, 1.000000f, 1.000000f ),
	bool4( false, false, false, false )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float4_greater_than,
	float4( 1.000000f, 1.000000f, 1.000000f, 1.000000f ),
	float4( 0.000000f, 0.000000f, 0.000000f, 0.000000f ),
	bool4( true, true, true, true )
);

TEMPER_PARAMETRIC( Test_float4_greater_than_equal, TEMPER_FLAG_SHOULD_RUN, const float4& lhs, const float4& rhs, const bool4& expectedAnswer )
{
	bool4 actualResult = lhs >= rhs;
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float4_greater_than_equal,
	float4( 0.000000f, 0.000000f, 0.000000f, 0.000000f ),
	float4( 0.000000f, 0.000000f, 0.000000f, 0.000000f ),
	bool4( true, true, true, true )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float4_greater_than_equal,
	float4( 0.000000f, 0.000000f, 0.000000f, 0.000000f ),
	float4( 1.000000f, 1.000000f, 1.000000f, 1.000000f ),
	bool4( false, false, false, false )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float4_greater_than_equal,
	float4( 1.000000f, 1.000000f, 1.000000f, 1.000000f ),
	float4( 1.000000f, 1.000000f, 1.000000f, 1.000000f ),
	bool4( true, true, true, true )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float4_greater_than_equal,
	float4( 1.000000f, 1.000000f, 1.000000f, 1.000000f ),
	float4( 0.000000f, 0.000000f, 0.000000f, 0.000000f ),
	bool4( true, true, true, true )
);

TEMPER_PARAMETRIC( Test_float4_cadds, TEMPER_FLAG_SHOULD_RUN, const float4& lhs, const float& rhs, const float4& expectedAnswer )
{
	float4 actualResult = lhs + rhs;
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float4_cadds,
	float4( 1.000000f, 1.000000f, 1.000000f, 1.000000f ),
	1.000000f,
	float4( 2.000000f, 2.000000f, 2.000000f, 2.000000f )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float4_cadds,
	float4( 2.000000f, 2.000000f, 2.000000f, 2.000000f ),
	2.000000f,
	float4( 4.000000f, 4.000000f, 4.000000f, 4.000000f )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float4_cadds,
	float4( 4.000000f, 4.000000f, 4.000000f, 4.000000f ),
	2.000000f,
	float4( 6.000000f, 6.000000f, 6.000000f, 6.000000f )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float4_cadds,
	float4( 8.000000f, 8.000000f, 8.000000f, 8.000000f ),
	4.000000f,
	float4( 12.000000f, 12.000000f, 12.000000f, 12.000000f )
);

TEMPER_PARAMETRIC( Test_float4_csubs, TEMPER_FLAG_SHOULD_RUN, const float4& lhs, const float& rhs, const float4& expectedAnswer )
{
	float4 actualResult = lhs - rhs;
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float4_csubs,
	float4( 1.000000f, 1.000000f, 1.000000f, 1.000000f ),
	1.000000f,
	float4( 0.000000f, 0.000000f, 0.000000f, 0.000000f )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float4_csubs,
	float4( 2.000000f, 2.000000f, 2.000000f, 2.000000f ),
	2.000000f,
	float4( 0.000000f, 0.000000f, 0.000000f, 0.000000f )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float4_csubs,
	float4( 4.000000f, 4.000000f, 4.000000f, 4.000000f ),
	2.000000f,
	float4( 2.000000f, 2.000000f, 2.000000f, 2.000000f )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float4_csubs,
	float4( 8.000000f, 8.000000f, 8.000000f, 8.000000f ),
	4.000000f,
	float4( 4.000000f, 4.000000f, 4.000000f, 4.000000f )
);

TEMPER_PARAMETRIC( Test_float4_cmuls, TEMPER_FLAG_SHOULD_RUN, const float4& lhs, const float& rhs, const float4& expectedAnswer )
{
	float4 actualResult = lhs * rhs;
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float4_cmuls,
	float4( 1.000000f, 1.000000f, 1.000000f, 1.000000f ),
	1.000000f,
	float4( 1.000000f, 1.000000f, 1.000000f, 1.000000f )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float4_cmuls,
	float4( 2.000000f, 2.000000f, 2.000000f, 2.000000f ),
	2.000000f,
	float4( 4.000000f, 4.000000f, 4.000000f, 4.000000f )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float4_cmuls,
	float4( 4.000000f, 4.000000f, 4.000000f, 4.000000f ),
	2.000000f,
	float4( 8.000000f, 8.000000f, 8.000000f, 8.000000f )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float4_cmuls,
	float4( 8.000000f, 8.000000f, 8.000000f, 8.000000f ),
	4.000000f,
	float4( 32.000000f, 32.000000f, 32.000000f, 32.000000f )
);

TEMPER_PARAMETRIC( Test_float4_cdivs, TEMPER_FLAG_SHOULD_RUN, const float4& lhs, const float& rhs, const float4& expectedAnswer )
{
	float4 actualResult = lhs / rhs;
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float4_cdivs,
	float4( 1.000000f, 1.000000f, 1.000000f, 1.000000f ),
	1.000000f,
	float4( 1.000000f, 1.000000f, 1.000000f, 1.000000f )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float4_cdivs,
	float4( 2.000000f, 2.000000f, 2.000000f, 2.000000f ),
	2.000000f,
	float4( 1.000000f, 1.000000f, 1.000000f, 1.000000f )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float4_cdivs,
	float4( 4.000000f, 4.000000f, 4.000000f, 4.000000f ),
	2.000000f,
	float4( 2.000000f, 2.000000f, 2.000000f, 2.000000f )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float4_cdivs,
	float4( 8.000000f, 8.000000f, 8.000000f, 8.000000f ),
	4.000000f,
	float4( 2.000000f, 2.000000f, 2.000000f, 2.000000f )
);

TEMPER_PARAMETRIC( Test_float4_caddv, TEMPER_FLAG_SHOULD_RUN, const float4& lhs, const float4& rhs, const float4& expectedAnswer )
{
	float4 actualResult = lhs + rhs;
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float4_caddv,
	float4( 1.000000f, 1.000000f, 1.000000f, 1.000000f ),
	float4( 1.000000f, 1.000000f, 1.000000f, 1.000000f ),
	float4( 2.000000f, 2.000000f, 2.000000f, 2.000000f )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float4_caddv,
	float4( 2.000000f, 2.000000f, 2.000000f, 2.000000f ),
	float4( 2.000000f, 2.000000f, 2.000000f, 2.000000f ),
	float4( 4.000000f, 4.000000f, 4.000000f, 4.000000f )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float4_caddv,
	float4( 4.000000f, 4.000000f, 4.000000f, 4.000000f ),
	float4( 2.000000f, 2.000000f, 2.000000f, 2.000000f ),
	float4( 6.000000f, 6.000000f, 6.000000f, 6.000000f )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float4_caddv,
	float4( 8.000000f, 8.000000f, 8.000000f, 8.000000f ),
	float4( 4.000000f, 4.000000f, 4.000000f, 4.000000f ),
	float4( 12.000000f, 12.000000f, 12.000000f, 12.000000f )
);

TEMPER_PARAMETRIC( Test_float4_csubv, TEMPER_FLAG_SHOULD_RUN, const float4& lhs, const float4& rhs, const float4& expectedAnswer )
{
	float4 actualResult = lhs - rhs;
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float4_csubv,
	float4( 1.000000f, 1.000000f, 1.000000f, 1.000000f ),
	float4( 1.000000f, 1.000000f, 1.000000f, 1.000000f ),
	float4( 0.000000f, 0.000000f, 0.000000f, 0.000000f )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float4_csubv,
	float4( 2.000000f, 2.000000f, 2.000000f, 2.000000f ),
	float4( 2.000000f, 2.000000f, 2.000000f, 2.000000f ),
	float4( 0.000000f, 0.000000f, 0.000000f, 0.000000f )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float4_csubv,
	float4( 4.000000f, 4.000000f, 4.000000f, 4.000000f ),
	float4( 2.000000f, 2.000000f, 2.000000f, 2.000000f ),
	float4( 2.000000f, 2.000000f, 2.000000f, 2.000000f )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float4_csubv,
	float4( 8.000000f, 8.000000f, 8.000000f, 8.000000f ),
	float4( 4.000000f, 4.000000f, 4.000000f, 4.000000f ),
	float4( 4.000000f, 4.000000f, 4.000000f, 4.000000f )
);

TEMPER_PARAMETRIC( Test_float4_cmulv, TEMPER_FLAG_SHOULD_RUN, const float4& lhs, const float4& rhs, const float4& expectedAnswer )
{
	float4 actualResult = lhs * rhs;
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float4_cmulv,
	float4( 1.000000f, 1.000000f, 1.000000f, 1.000000f ),
	float4( 1.000000f, 1.000000f, 1.000000f, 1.000000f ),
	float4( 1.000000f, 1.000000f, 1.000000f, 1.000000f )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float4_cmulv,
	float4( 2.000000f, 2.000000f, 2.000000f, 2.000000f ),
	float4( 2.000000f, 2.000000f, 2.000000f, 2.000000f ),
	float4( 4.000000f, 4.000000f, 4.000000f, 4.000000f )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float4_cmulv,
	float4( 4.000000f, 4.000000f, 4.000000f, 4.000000f ),
	float4( 2.000000f, 2.000000f, 2.000000f, 2.000000f ),
	float4( 8.000000f, 8.000000f, 8.000000f, 8.000000f )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float4_cmulv,
	float4( 8.000000f, 8.000000f, 8.000000f, 8.000000f ),
	float4( 4.000000f, 4.000000f, 4.000000f, 4.000000f ),
	float4( 32.000000f, 32.000000f, 32.000000f, 32.000000f )
);

TEMPER_PARAMETRIC( Test_float4_cdivv, TEMPER_FLAG_SHOULD_RUN, const float4& lhs, const float4& rhs, const float4& expectedAnswer )
{
	float4 actualResult = lhs / rhs;
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float4_cdivv,
	float4( 1.000000f, 1.000000f, 1.000000f, 1.000000f ),
	float4( 1.000000f, 1.000000f, 1.000000f, 1.000000f ),
	float4( 1.000000f, 1.000000f, 1.000000f, 1.000000f )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float4_cdivv,
	float4( 2.000000f, 2.000000f, 2.000000f, 2.000000f ),
	float4( 2.000000f, 2.000000f, 2.000000f, 2.000000f ),
	float4( 1.000000f, 1.000000f, 1.000000f, 1.000000f )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float4_cdivv,
	float4( 4.000000f, 4.000000f, 4.000000f, 4.000000f ),
	float4( 2.000000f, 2.000000f, 2.000000f, 2.000000f ),
	float4( 2.000000f, 2.000000f, 2.000000f, 2.000000f )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float4_cdivv,
	float4( 8.000000f, 8.000000f, 8.000000f, 8.000000f ),
	float4( 4.000000f, 4.000000f, 4.000000f, 4.000000f ),
	float4( 2.000000f, 2.000000f, 2.000000f, 2.000000f )
);

#if defined( __GNUC__ ) || defined( __clang__ )
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wcast-qual"
#endif

TEMPER_PARAMETRIC( Test_float4_increment_prefix, TEMPER_FLAG_SHOULD_RUN, const float4& x, const float4& expectedAnswer )
{
	// make local copy of x and use that because we cant do increment or decrement operations on a const reference
	// and MSVC throws warnings if we just make the parameter a non-const reference
	float4 xlocal = (float4) x;
	float4 actualAnswer = ++xlocal;
	TEMPER_CHECK_TRUE( actualAnswer == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float4_increment_prefix,
	float4( 1.000000f, 1.000000f, 1.000000f, 1.000000f ),
	float4( 2.000000f, 2.000000f, 2.000000f, 2.000000f )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float4_increment_prefix,
	float4( 2.000000f, 2.000000f, 2.000000f, 2.000000f ),
	float4( 3.000000f, 3.000000f, 3.000000f, 3.000000f )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float4_increment_prefix,
	float4( 3.000000f, 3.000000f, 3.000000f, 3.000000f ),
	float4( 4.000000f, 4.000000f, 4.000000f, 4.000000f )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float4_increment_prefix,
	float4( 4.000000f, 4.000000f, 4.000000f, 4.000000f ),
	float4( 5.000000f, 5.000000f, 5.000000f, 5.000000f )
);

TEMPER_PARAMETRIC( Test_float4_increment_postfix, TEMPER_FLAG_SHOULD_RUN, const float4& x, const float4& expectedAnswer )
{
	// make local copy of x and use that because we cant do increment or decrement operations on a const reference
	// and MSVC throws warnings if we just make the parameter a non-const reference
	float4 xlocal = (float4) x;
	float4 actualAnswer = xlocal++;
	TEMPER_CHECK_TRUE( actualAnswer == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float4_increment_postfix,
	float4( 1.000000f, 1.000000f, 1.000000f, 1.000000f ),
	float4( 2.000000f, 2.000000f, 2.000000f, 2.000000f )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float4_increment_postfix,
	float4( 2.000000f, 2.000000f, 2.000000f, 2.000000f ),
	float4( 3.000000f, 3.000000f, 3.000000f, 3.000000f )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float4_increment_postfix,
	float4( 3.000000f, 3.000000f, 3.000000f, 3.000000f ),
	float4( 4.000000f, 4.000000f, 4.000000f, 4.000000f )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float4_increment_postfix,
	float4( 4.000000f, 4.000000f, 4.000000f, 4.000000f ),
	float4( 5.000000f, 5.000000f, 5.000000f, 5.000000f )
);

TEMPER_PARAMETRIC( Test_float4_decrement_prefix, TEMPER_FLAG_SHOULD_RUN, const float4& x, const float4& expectedAnswer )
{
	// make local copy of x and use that because we cant do increment or decrement operations on a const reference
	// and MSVC throws warnings if we just make the parameter a non-const reference
	float4 xlocal = (float4) x;
	float4 actualAnswer = --xlocal;
	TEMPER_CHECK_TRUE( actualAnswer == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float4_decrement_prefix,
	float4( 1.000000f, 1.000000f, 1.000000f, 1.000000f ),
	float4( 0.000000f, 0.000000f, 0.000000f, 0.000000f )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float4_decrement_prefix,
	float4( 2.000000f, 2.000000f, 2.000000f, 2.000000f ),
	float4( 1.000000f, 1.000000f, 1.000000f, 1.000000f )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float4_decrement_prefix,
	float4( 3.000000f, 3.000000f, 3.000000f, 3.000000f ),
	float4( 2.000000f, 2.000000f, 2.000000f, 2.000000f )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float4_decrement_prefix,
	float4( 4.000000f, 4.000000f, 4.000000f, 4.000000f ),
	float4( 3.000000f, 3.000000f, 3.000000f, 3.000000f )
);

TEMPER_PARAMETRIC( Test_float4_decrement_postfix, TEMPER_FLAG_SHOULD_RUN, const float4& x, const float4& expectedAnswer )
{
	// make local copy of x and use that because we cant do increment or decrement operations on a const reference
	// and MSVC throws warnings if we just make the parameter a non-const reference
	float4 xlocal = (float4) x;
	float4 actualAnswer = xlocal--;
	TEMPER_CHECK_TRUE( actualAnswer == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float4_decrement_postfix,
	float4( 1.000000f, 1.000000f, 1.000000f, 1.000000f ),
	float4( 0.000000f, 0.000000f, 0.000000f, 0.000000f )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float4_decrement_postfix,
	float4( 2.000000f, 2.000000f, 2.000000f, 2.000000f ),
	float4( 1.000000f, 1.000000f, 1.000000f, 1.000000f )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float4_decrement_postfix,
	float4( 3.000000f, 3.000000f, 3.000000f, 3.000000f ),
	float4( 2.000000f, 2.000000f, 2.000000f, 2.000000f )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float4_decrement_postfix,
	float4( 4.000000f, 4.000000f, 4.000000f, 4.000000f ),
	float4( 3.000000f, 3.000000f, 3.000000f, 3.000000f )
);

#if defined( __GNUC__ ) || defined( __clang__ )
#pragma GCC diagnostic pop
#endif
#if defined( __GNUC__ ) || defined( __clang__ )
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wcast-qual"
#endif
TEMPER_PARAMETRIC( Test_float4_negate_prefix, TEMPER_FLAG_SHOULD_RUN, const float4& x, const float4& expectedAnswer )
{
	// make local copy of x and use that because we cant do increment or decrement operations on a const reference
	// and MSVC throws warnings if we just make the parameter a non-const reference
	float4 xlocal = (float4) x;
	float4 actualAnswer = -xlocal;
	TEMPER_CHECK_TRUE( actualAnswer == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float4_negate_prefix,
	float4( 0.000000f, 0.000000f, 0.000000f, 0.000000f ),
	float4( -0.000000f, -0.000000f, -0.000000f, -0.000000f )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float4_negate_prefix,
	float4( 1.000000f, 1.000000f, 1.000000f, 1.000000f ),
	float4( -1.000000f, -1.000000f, -1.000000f, -1.000000f )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float4_negate_prefix,
	float4( 2.000000f, 2.000000f, 2.000000f, 2.000000f ),
	float4( -2.000000f, -2.000000f, -2.000000f, -2.000000f )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float4_negate_prefix,
	float4( 3.000000f, 3.000000f, 3.000000f, 3.000000f ),
	float4( -3.000000f, -3.000000f, -3.000000f, -3.000000f )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float4_negate_prefix,
	float4( 10.000000f, 10.000000f, 10.000000f, 10.000000f ),
	float4( -10.000000f, -10.000000f, -10.000000f, -10.000000f )
);

#if defined( __GNUC__ ) || defined( __clang__ )
#pragma GCC diagnostic pop
#endif

TEMPER_PARAMETRIC( Test_float4_min, TEMPER_FLAG_SHOULD_RUN, const float4& lhs, const float4& rhs, const float4& expectedAnswer )
{
	float4 actualResult = min( lhs, rhs );
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float4_min,
	float4( 0.000000f, 0.000000f, 0.000000f, 0.000000f ),
	float4( 1.000000f, 1.000000f, 1.000000f, 1.000000f ),
	float4( 0.000000f, 0.000000f, 0.000000f, 0.000000f )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float4_min,
	float4( 1.000000f, 1.000000f, 1.000000f, 1.000000f ),
	float4( 2.000000f, 2.000000f, 2.000000f, 2.000000f ),
	float4( 1.000000f, 1.000000f, 1.000000f, 1.000000f )
);

TEMPER_PARAMETRIC( Test_float4_max, TEMPER_FLAG_SHOULD_RUN, const float4& lhs, const float4& rhs, const float4& expectedAnswer )
{
	float4 actualResult = max( lhs, rhs );
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float4_max,
	float4( 1.000000f, 1.000000f, 1.000000f, 1.000000f ),
	float4( 0.000000f, 0.000000f, 0.000000f, 0.000000f ),
	float4( 1.000000f, 1.000000f, 1.000000f, 1.000000f )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float4_max,
	float4( 2.000000f, 2.000000f, 2.000000f, 2.000000f ),
	float4( 1.000000f, 1.000000f, 1.000000f, 1.000000f ),
	float4( 2.000000f, 2.000000f, 2.000000f, 2.000000f )
);

TEMPER_PARAMETRIC( Test_float4_saturate, TEMPER_FLAG_SHOULD_RUN, const float4& x, const float4& expectedAnswer )
{
	float4 actualResult = saturate( x );
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float4_saturate,
	float4( 0.000000f, 0.000000f, 0.000000f, 0.000000f ),
	float4( 0.000000f, 0.000000f, 0.000000f, 0.000000f )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float4_saturate,
	float4( 1.000000f, 1.000000f, 1.000000f, 1.000000f ),
	float4( 1.000000f, 1.000000f, 1.000000f, 1.000000f )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float4_saturate,
	float4( 2.000000f, 2.000000f, 2.000000f, 2.000000f ),
	float4( 1.000000f, 1.000000f, 1.000000f, 1.000000f )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float4_saturate,
	float4( 3.000000f, 3.000000f, 3.000000f, 3.000000f ),
	float4( 1.000000f, 1.000000f, 1.000000f, 1.000000f )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float4_saturate,
	float4( 10.000000f, 10.000000f, 10.000000f, 10.000000f ),
	float4( 1.000000f, 1.000000f, 1.000000f, 1.000000f )
);

TEMPER_PARAMETRIC( Test_float4_sign, TEMPER_FLAG_SHOULD_RUN, const float4& x, const int4& expectedAnswer )
{
	int4 actualResult = sign( x );
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float4_sign,
	float4( 0.000000f, 0.000000f, 0.000000f, 0.000000f ),
	int4( 0, 0, 0, 0 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float4_sign,
	float4( 1.000000f, 1.000000f, 1.000000f, 1.000000f ),
	int4( 1, 1, 1, 1 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float4_sign,
	float4( 2.000000f, 2.000000f, 2.000000f, 2.000000f ),
	int4( 1, 1, 1, 1 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float4_sign,
	float4( 3.000000f, 3.000000f, 3.000000f, 3.000000f ),
	int4( 1, 1, 1, 1 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float4_sign,
	float4( -1.000000f, -1.000000f, -1.000000f, -1.000000f ),
	int4( -1, -1, -1, -1 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float4_sign,
	float4( -2.000000f, -2.000000f, -2.000000f, -2.000000f ),
	int4( -1, -1, -1, -1 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float4_sign,
	float4( -3.000000f, -3.000000f, -3.000000f, -3.000000f ),
	int4( -1, -1, -1, -1 )
);

TEMPER_PARAMETRIC( Test_float4_lerp, TEMPER_FLAG_SHOULD_RUN, const float4& lhs, const float4& rhs, const float t, const float4& expectedAnswer )
{
	float4 actualResult = lerp( lhs, rhs, t );
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float4_lerp,
	float4( 0.000000f, 0.000000f, 0.000000f, 0.000000f ),
	float4( 1.000000f, 1.000000f, 1.000000f, 1.000000f ),
	0.500000f,
	float4( 0.500000f, 0.500000f, 0.500000f, 0.500000f )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float4_lerp,
	float4( 1.000000f, 1.000000f, 1.000000f, 1.000000f ),
	float4( 3.000000f, 3.000000f, 3.000000f, 3.000000f ),
	0.500000f,
	float4( 2.000000f, 2.000000f, 2.000000f, 2.000000f )
);

TEMPER_PARAMETRIC( Test_float4_quat_length, TEMPER_FLAG_SHOULD_RUN, const float4& quat, const float expectedAnswer )
{
	float actualResult = quat_length( quat );
	TEMPER_CHECK_TRUE( floateq( actualResult, expectedAnswer ) );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float4_quat_length,
	float4( 0.000000f, 0.000000f, 0.000000f, 0.000000f ),
	0.000000f
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float4_quat_length,
	float4( 1.000000f, 1.000000f, 1.000000f, 1.000000f ),
	2.000000f
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float4_quat_length,
	float4( 2.000000f, 2.000000f, 2.000000f, 2.000000f ),
	4.000000f
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float4_quat_length,
	float4( 3.000000f, 3.000000f, 3.000000f, 3.000000f ),
	6.000000f
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float4_quat_length,
	float4( 4.000000f, 4.000000f, 4.000000f, 4.000000f ),
	8.000000f
);

TEMPER_PARAMETRIC( Test_float4_quat_lerp, TEMPER_FLAG_SHOULD_RUN, const float4& lhs, const float4& rhs, const float t, const float4& expectedAnswer )
{
	float4 actualResult = quat_lerp( lhs, rhs, t );
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float4_quat_lerp,
	float4( 0.000000f, 0.000000f, 0.000000f, 0.000000f ),
	float4( 1.000000f, 1.000000f, 1.000000f, 1.000000f ),
	0.500000f,
	float4( 0.500000f, 0.500000f, 0.500000f, 0.500000f )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float4_quat_lerp,
	float4( 0.000000f, 0.000000f, 0.000000f, 0.000000f ),
	float4( 1.000000f, 1.000000f, 1.000000f, 1.000000f ),
	0.250000f,
	float4( 0.250000f, 0.250000f, 0.250000f, 0.250000f )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float4_quat_lerp,
	float4( 0.000000f, 0.000000f, 0.000000f, 0.000000f ),
	float4( 1.000000f, 1.000000f, 1.000000f, 1.000000f ),
	0.750000f,
	float4( 0.750000f, 0.750000f, 0.750000f, 0.750000f )
);

TEMPER_PARAMETRIC( Test_float4_quat_slerp, TEMPER_FLAG_SHOULD_RUN, const float4& lhs, const float4& rhs, const float t, const float4& expectedAnswer )
{
	float4 actualResult = quat_slerp( lhs, rhs, t );
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float4_quat_slerp,
	float4( 0.000000f, 0.000000f, 0.000000f, 0.000000f ),
	float4( 1.000000f, 1.000000f, 1.000000f, 1.000000f ),
	0.500000f,
	float4( 0.707107f, 0.707107f, 0.707107f, 0.707107f )
);

TEMPER_PARAMETRIC( Test_float4_lengthsq, TEMPER_FLAG_SHOULD_RUN, const float4& vec, const float expectedAnswer )
{
	float actualResult = lengthsq( vec );
	TEMPER_CHECK_TRUE( floateq( actualResult, expectedAnswer ) );
}

TEMPER_PARAMETRIC( Test_float4_lengthsq_sse, TEMPER_FLAG_SHOULD_RUN, const float4& vec, const float expectedAnswer )
{
	__m128 reg_vec_x = _mm_set1_ps( vec.x );
	__m128 reg_vec_y = _mm_set1_ps( vec.y );
	__m128 reg_vec_z = _mm_set1_ps( vec.z );
	__m128 reg_vec_w = _mm_set1_ps( vec.w );

	__m128 reg_actualAnswer = lengthsq_sse( reg_vec_x, reg_vec_y, reg_vec_z, reg_vec_w );

	float actualAnswer[4];
	_mm_store_ps( actualAnswer, reg_actualAnswer );

	TEMPER_CHECK_TRUE( floateq( actualAnswer[0], expectedAnswer ) );
	TEMPER_CHECK_TRUE( floateq( actualAnswer[1], expectedAnswer ) );
	TEMPER_CHECK_TRUE( floateq( actualAnswer[2], expectedAnswer ) );
	TEMPER_CHECK_TRUE( floateq( actualAnswer[3], expectedAnswer ) );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float4_lengthsq,
	float4( 0.000000f, 0.000000f, 0.000000f, 0.000000f ),
	0.000000f
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float4_lengthsq,
	float4( 1.000000f, 1.000000f, 1.000000f, 1.000000f ),
	4.000000f
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float4_lengthsq,
	float4( 2.000000f, 2.000000f, 2.000000f, 2.000000f ),
	16.000000f
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float4_lengthsq_sse,
	float4( 0.000000f, 0.000000f, 0.000000f, 0.000000f ),
	0.000000f
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float4_lengthsq_sse,
	float4( 1.000000f, 1.000000f, 1.000000f, 1.000000f ),
	4.000000f
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float4_lengthsq_sse,
	float4( 2.000000f, 2.000000f, 2.000000f, 2.000000f ),
	16.000000f
);

TEMPER_PARAMETRIC( Test_float4_length, TEMPER_FLAG_SHOULD_RUN, const float4& vec, const float expectedAnswer )
{
	float actualResult = length( vec );
	TEMPER_CHECK_TRUE( floateq( actualResult, expectedAnswer ) );
}

TEMPER_PARAMETRIC( Test_float4_length_sse, TEMPER_FLAG_SHOULD_RUN, const float4& vec, const float expectedAnswer )
{
	__m128 reg_vec_x = _mm_set1_ps( vec.x );
	__m128 reg_vec_y = _mm_set1_ps( vec.y );
	__m128 reg_vec_z = _mm_set1_ps( vec.z );
	__m128 reg_vec_w = _mm_set1_ps( vec.w );

	__m128 reg_actualAnswer = length_sse( reg_vec_x, reg_vec_y, reg_vec_z, reg_vec_w );

	float actualAnswer[4];
	_mm_store_ps( actualAnswer, reg_actualAnswer );

	TEMPER_CHECK_TRUE( floateq( actualAnswer[0], expectedAnswer ) );
	TEMPER_CHECK_TRUE( floateq( actualAnswer[1], expectedAnswer ) );
	TEMPER_CHECK_TRUE( floateq( actualAnswer[2], expectedAnswer ) );
	TEMPER_CHECK_TRUE( floateq( actualAnswer[3], expectedAnswer ) );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float4_length,
	float4( 0.000000f, 0.000000f, 0.000000f, 0.000000f ),
	0.000000f
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float4_length,
	float4( 1.000000f, 1.000000f, 1.000000f, 1.000000f ),
	2.000000f
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float4_length,
	float4( 2.000000f, 2.000000f, 2.000000f, 2.000000f ),
	4.000000f
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float4_length_sse,
	float4( 0.000000f, 0.000000f, 0.000000f, 0.000000f ),
	0.000000f
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float4_length_sse,
	float4( 1.000000f, 1.000000f, 1.000000f, 1.000000f ),
	2.000000f
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float4_length_sse,
	float4( 2.000000f, 2.000000f, 2.000000f, 2.000000f ),
	4.000000f
);

TEMPER_PARAMETRIC( Test_float4_dot, TEMPER_FLAG_SHOULD_RUN, const float4& lhs, const float4& rhs, const float expectedAnswer )
{
	float actualResult = dot( lhs, rhs );
	TEMPER_CHECK_TRUE( floateq( actualResult, expectedAnswer ) );
}

TEMPER_PARAMETRIC( Test_float4_dot_sse, TEMPER_FLAG_SHOULD_RUN, const float4& lhs, const float4& rhs, const float expectedAnswer )
{
	__m128 reg_lhs_x = _mm_set1_ps( lhs.x );
	__m128 reg_lhs_y = _mm_set1_ps( lhs.y );
	__m128 reg_lhs_z = _mm_set1_ps( lhs.z );
	__m128 reg_lhs_w = _mm_set1_ps( lhs.w );

	__m128 reg_rhs_x = _mm_set1_ps( rhs.x );
	__m128 reg_rhs_y = _mm_set1_ps( rhs.y );
	__m128 reg_rhs_z = _mm_set1_ps( rhs.z );
	__m128 reg_rhs_w = _mm_set1_ps( rhs.w );

	__m128 reg_actualAnswer = dot_sse( reg_lhs_x, reg_lhs_y, reg_lhs_z, reg_lhs_w, reg_rhs_x, reg_rhs_y, reg_rhs_z, reg_rhs_w );

	float actualAnswer[4];
	_mm_store_ps( actualAnswer, reg_actualAnswer );

	TEMPER_CHECK_TRUE( floateq( actualAnswer[0], expectedAnswer ) );
	TEMPER_CHECK_TRUE( floateq( actualAnswer[1], expectedAnswer ) );
	TEMPER_CHECK_TRUE( floateq( actualAnswer[2], expectedAnswer ) );
	TEMPER_CHECK_TRUE( floateq( actualAnswer[3], expectedAnswer ) );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float4_dot,
	float4( 0.000000f, 0.000000f, 0.000000f, 0.000000f ),
	float4( 1.000000f, 1.000000f, 1.000000f, 1.000000f ),
	0.000000f
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float4_dot,
	float4( 1.000000f, 1.000000f, 1.000000f, 1.000000f ),
	float4( 1.000000f, 1.000000f, 1.000000f, 1.000000f ),
	4.000000f
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float4_dot,
	float4( 1.000000f, 1.000000f, 1.000000f, 1.000000f ),
	float4( -1.000000f, -1.000000f, -1.000000f, -1.000000f ),
	-4.000000f
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float4_dot_sse,
	float4( 0.000000f, 0.000000f, 0.000000f, 0.000000f ),
	float4( 1.000000f, 1.000000f, 1.000000f, 1.000000f ),
	0.000000f
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float4_dot_sse,
	float4( 1.000000f, 1.000000f, 1.000000f, 1.000000f ),
	float4( 1.000000f, 1.000000f, 1.000000f, 1.000000f ),
	4.000000f
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float4_dot_sse,
	float4( 1.000000f, 1.000000f, 1.000000f, 1.000000f ),
	float4( -1.000000f, -1.000000f, -1.000000f, -1.000000f ),
	-4.000000f
);


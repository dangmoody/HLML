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

TEMPER_PARAMETRIC( Test_uint2x3_less_than, TEMPER_FLAG_SHOULD_RUN, const uint2x3& lhs, const uint2x3& rhs, const bool2x3& expectedAnswer )
{
	bool2x3 actualResult = lhs < rhs;
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_less_than,
	uint2x3(
		0U, 0U, 0U,
		0U, 0U, 0U
	),
	uint2x3(
		0U, 0U, 0U,
		0U, 0U, 0U
	),
	bool2x3(
		false, false, false,
		false, false, false
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_less_than,
	uint2x3(
		0U, 0U, 0U,
		0U, 0U, 0U
	),
	uint2x3(
		1U, 1U, 1U,
		1U, 1U, 1U
	),
	bool2x3(
		true, true, true,
		true, true, true
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_less_than,
	uint2x3(
		1U, 1U, 1U,
		1U, 1U, 1U
	),
	uint2x3(
		1U, 1U, 1U,
		1U, 1U, 1U
	),
	bool2x3(
		false, false, false,
		false, false, false
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_less_than,
	uint2x3(
		1U, 1U, 1U,
		1U, 1U, 1U
	),
	uint2x3(
		0U, 0U, 0U,
		0U, 0U, 0U
	),
	bool2x3(
		false, false, false,
		false, false, false
	)
);

TEMPER_PARAMETRIC( Test_uint2x3_less_than_equal, TEMPER_FLAG_SHOULD_RUN, const uint2x3& lhs, const uint2x3& rhs, const bool2x3& expectedAnswer )
{
	bool2x3 actualResult = lhs <= rhs;
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_less_than_equal,
	uint2x3(
		0U, 0U, 0U,
		0U, 0U, 0U
	),
	uint2x3(
		0U, 0U, 0U,
		0U, 0U, 0U
	),
	bool2x3(
		true, true, true,
		true, true, true
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_less_than_equal,
	uint2x3(
		0U, 0U, 0U,
		0U, 0U, 0U
	),
	uint2x3(
		1U, 1U, 1U,
		1U, 1U, 1U
	),
	bool2x3(
		true, true, true,
		true, true, true
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_less_than_equal,
	uint2x3(
		1U, 1U, 1U,
		1U, 1U, 1U
	),
	uint2x3(
		1U, 1U, 1U,
		1U, 1U, 1U
	),
	bool2x3(
		true, true, true,
		true, true, true
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_less_than_equal,
	uint2x3(
		1U, 1U, 1U,
		1U, 1U, 1U
	),
	uint2x3(
		0U, 0U, 0U,
		0U, 0U, 0U
	),
	bool2x3(
		false, false, false,
		false, false, false
	)
);

TEMPER_PARAMETRIC( Test_uint2x3_greater_than, TEMPER_FLAG_SHOULD_RUN, const uint2x3& lhs, const uint2x3& rhs, const bool2x3& expectedAnswer )
{
	bool2x3 actualResult = lhs > rhs;
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_greater_than,
	uint2x3(
		0U, 0U, 0U,
		0U, 0U, 0U
	),
	uint2x3(
		0U, 0U, 0U,
		0U, 0U, 0U
	),
	bool2x3(
		false, false, false,
		false, false, false
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_greater_than,
	uint2x3(
		0U, 0U, 0U,
		0U, 0U, 0U
	),
	uint2x3(
		1U, 1U, 1U,
		1U, 1U, 1U
	),
	bool2x3(
		false, false, false,
		false, false, false
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_greater_than,
	uint2x3(
		1U, 1U, 1U,
		1U, 1U, 1U
	),
	uint2x3(
		1U, 1U, 1U,
		1U, 1U, 1U
	),
	bool2x3(
		false, false, false,
		false, false, false
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_greater_than,
	uint2x3(
		1U, 1U, 1U,
		1U, 1U, 1U
	),
	uint2x3(
		0U, 0U, 0U,
		0U, 0U, 0U
	),
	bool2x3(
		true, true, true,
		true, true, true
	)
);

TEMPER_PARAMETRIC( Test_uint2x3_greater_than_equal, TEMPER_FLAG_SHOULD_RUN, const uint2x3& lhs, const uint2x3& rhs, const bool2x3& expectedAnswer )
{
	bool2x3 actualResult = lhs >= rhs;
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_greater_than_equal,
	uint2x3(
		0U, 0U, 0U,
		0U, 0U, 0U
	),
	uint2x3(
		0U, 0U, 0U,
		0U, 0U, 0U
	),
	bool2x3(
		true, true, true,
		true, true, true
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_greater_than_equal,
	uint2x3(
		0U, 0U, 0U,
		0U, 0U, 0U
	),
	uint2x3(
		1U, 1U, 1U,
		1U, 1U, 1U
	),
	bool2x3(
		false, false, false,
		false, false, false
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_greater_than_equal,
	uint2x3(
		1U, 1U, 1U,
		1U, 1U, 1U
	),
	uint2x3(
		1U, 1U, 1U,
		1U, 1U, 1U
	),
	bool2x3(
		true, true, true,
		true, true, true
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_greater_than_equal,
	uint2x3(
		1U, 1U, 1U,
		1U, 1U, 1U
	),
	uint2x3(
		0U, 0U, 0U,
		0U, 0U, 0U
	),
	bool2x3(
		true, true, true,
		true, true, true
	)
);

TEMPER_PARAMETRIC( Test_uint2x3_cadds, TEMPER_FLAG_SHOULD_RUN, const uint2x3& lhs, const uint32_t& rhs, const uint2x3& expectedAnswer )
{
	uint2x3 actualResult = lhs + rhs;
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_cadds,
	uint2x3(
		1U, 1U, 1U,
		1U, 1U, 1U
	),
	1U,
	uint2x3(
		2U, 2U, 2U,
		2U, 2U, 2U
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_cadds,
	uint2x3(
		2U, 2U, 2U,
		2U, 2U, 2U
	),
	2U,
	uint2x3(
		4U, 4U, 4U,
		4U, 4U, 4U
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_cadds,
	uint2x3(
		4U, 4U, 4U,
		4U, 4U, 4U
	),
	2U,
	uint2x3(
		6U, 6U, 6U,
		6U, 6U, 6U
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_cadds,
	uint2x3(
		8U, 8U, 8U,
		8U, 8U, 8U
	),
	4U,
	uint2x3(
		12U, 12U, 12U,
		12U, 12U, 12U
	)
);

TEMPER_PARAMETRIC( Test_uint2x3_csubs, TEMPER_FLAG_SHOULD_RUN, const uint2x3& lhs, const uint32_t& rhs, const uint2x3& expectedAnswer )
{
	uint2x3 actualResult = lhs - rhs;
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_csubs,
	uint2x3(
		1U, 1U, 1U,
		1U, 1U, 1U
	),
	1U,
	uint2x3(
		0U, 0U, 0U,
		0U, 0U, 0U
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_csubs,
	uint2x3(
		2U, 2U, 2U,
		2U, 2U, 2U
	),
	2U,
	uint2x3(
		0U, 0U, 0U,
		0U, 0U, 0U
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_csubs,
	uint2x3(
		4U, 4U, 4U,
		4U, 4U, 4U
	),
	2U,
	uint2x3(
		2U, 2U, 2U,
		2U, 2U, 2U
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_csubs,
	uint2x3(
		8U, 8U, 8U,
		8U, 8U, 8U
	),
	4U,
	uint2x3(
		4U, 4U, 4U,
		4U, 4U, 4U
	)
);

TEMPER_PARAMETRIC( Test_uint2x3_cmuls, TEMPER_FLAG_SHOULD_RUN, const uint2x3& lhs, const uint32_t& rhs, const uint2x3& expectedAnswer )
{
	uint2x3 actualResult = lhs * rhs;
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_cmuls,
	uint2x3(
		1U, 1U, 1U,
		1U, 1U, 1U
	),
	1U,
	uint2x3(
		1U, 1U, 1U,
		1U, 1U, 1U
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_cmuls,
	uint2x3(
		2U, 2U, 2U,
		2U, 2U, 2U
	),
	2U,
	uint2x3(
		4U, 4U, 4U,
		4U, 4U, 4U
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_cmuls,
	uint2x3(
		4U, 4U, 4U,
		4U, 4U, 4U
	),
	2U,
	uint2x3(
		8U, 8U, 8U,
		8U, 8U, 8U
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_cmuls,
	uint2x3(
		8U, 8U, 8U,
		8U, 8U, 8U
	),
	4U,
	uint2x3(
		32U, 32U, 32U,
		32U, 32U, 32U
	)
);

TEMPER_PARAMETRIC( Test_uint2x3_cdivs, TEMPER_FLAG_SHOULD_RUN, const uint2x3& lhs, const uint32_t& rhs, const uint2x3& expectedAnswer )
{
	uint2x3 actualResult = lhs / rhs;
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_cdivs,
	uint2x3(
		1U, 1U, 1U,
		1U, 1U, 1U
	),
	1U,
	uint2x3(
		1U, 1U, 1U,
		1U, 1U, 1U
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_cdivs,
	uint2x3(
		2U, 2U, 2U,
		2U, 2U, 2U
	),
	2U,
	uint2x3(
		1U, 1U, 1U,
		1U, 1U, 1U
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_cdivs,
	uint2x3(
		4U, 4U, 4U,
		4U, 4U, 4U
	),
	2U,
	uint2x3(
		2U, 2U, 2U,
		2U, 2U, 2U
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_cdivs,
	uint2x3(
		8U, 8U, 8U,
		8U, 8U, 8U
	),
	4U,
	uint2x3(
		2U, 2U, 2U,
		2U, 2U, 2U
	)
);

TEMPER_PARAMETRIC( Test_uint2x3_caddm, TEMPER_FLAG_SHOULD_RUN, const uint2x3& lhs, const uint2x3& rhs, const uint2x3& expectedAnswer )
{
	uint2x3 actualResult = lhs + rhs;
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_caddm,
	uint2x3(
		1U, 1U, 1U,
		1U, 1U, 1U
	),
	uint2x3(
		1U, 1U, 1U,
		1U, 1U, 1U
	),
	uint2x3(
		2U, 2U, 2U,
		2U, 2U, 2U
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_caddm,
	uint2x3(
		2U, 2U, 2U,
		2U, 2U, 2U
	),
	uint2x3(
		2U, 2U, 2U,
		2U, 2U, 2U
	),
	uint2x3(
		4U, 4U, 4U,
		4U, 4U, 4U
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_caddm,
	uint2x3(
		4U, 4U, 4U,
		4U, 4U, 4U
	),
	uint2x3(
		2U, 2U, 2U,
		2U, 2U, 2U
	),
	uint2x3(
		6U, 6U, 6U,
		6U, 6U, 6U
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_caddm,
	uint2x3(
		8U, 8U, 8U,
		8U, 8U, 8U
	),
	uint2x3(
		4U, 4U, 4U,
		4U, 4U, 4U
	),
	uint2x3(
		12U, 12U, 12U,
		12U, 12U, 12U
	)
);

TEMPER_PARAMETRIC( Test_uint2x3_csubm, TEMPER_FLAG_SHOULD_RUN, const uint2x3& lhs, const uint2x3& rhs, const uint2x3& expectedAnswer )
{
	uint2x3 actualResult = lhs - rhs;
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_csubm,
	uint2x3(
		1U, 1U, 1U,
		1U, 1U, 1U
	),
	uint2x3(
		1U, 1U, 1U,
		1U, 1U, 1U
	),
	uint2x3(
		0U, 0U, 0U,
		0U, 0U, 0U
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_csubm,
	uint2x3(
		2U, 2U, 2U,
		2U, 2U, 2U
	),
	uint2x3(
		2U, 2U, 2U,
		2U, 2U, 2U
	),
	uint2x3(
		0U, 0U, 0U,
		0U, 0U, 0U
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_csubm,
	uint2x3(
		4U, 4U, 4U,
		4U, 4U, 4U
	),
	uint2x3(
		2U, 2U, 2U,
		2U, 2U, 2U
	),
	uint2x3(
		2U, 2U, 2U,
		2U, 2U, 2U
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_csubm,
	uint2x3(
		8U, 8U, 8U,
		8U, 8U, 8U
	),
	uint2x3(
		4U, 4U, 4U,
		4U, 4U, 4U
	),
	uint2x3(
		4U, 4U, 4U,
		4U, 4U, 4U
	)
);

TEMPER_PARAMETRIC( Test_uint2x3_cmulm, TEMPER_FLAG_SHOULD_RUN, const uint2x3& lhs, const uint2x3& rhs, const uint2x3& expectedAnswer )
{
	uint2x3 actualResult = lhs * rhs;
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_cmulm,
	uint2x3(
		1U, 1U, 1U,
		1U, 1U, 1U
	),
	uint2x3(
		1U, 1U, 1U,
		1U, 1U, 1U
	),
	uint2x3(
		1U, 1U, 1U,
		1U, 1U, 1U
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_cmulm,
	uint2x3(
		2U, 2U, 2U,
		2U, 2U, 2U
	),
	uint2x3(
		2U, 2U, 2U,
		2U, 2U, 2U
	),
	uint2x3(
		4U, 4U, 4U,
		4U, 4U, 4U
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_cmulm,
	uint2x3(
		4U, 4U, 4U,
		4U, 4U, 4U
	),
	uint2x3(
		2U, 2U, 2U,
		2U, 2U, 2U
	),
	uint2x3(
		8U, 8U, 8U,
		8U, 8U, 8U
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_cmulm,
	uint2x3(
		8U, 8U, 8U,
		8U, 8U, 8U
	),
	uint2x3(
		4U, 4U, 4U,
		4U, 4U, 4U
	),
	uint2x3(
		32U, 32U, 32U,
		32U, 32U, 32U
	)
);

TEMPER_PARAMETRIC( Test_uint2x3_cdivm, TEMPER_FLAG_SHOULD_RUN, const uint2x3& lhs, const uint2x3& rhs, const uint2x3& expectedAnswer )
{
	uint2x3 actualResult = lhs / rhs;
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_cdivm,
	uint2x3(
		1U, 1U, 1U,
		1U, 1U, 1U
	),
	uint2x3(
		1U, 1U, 1U,
		1U, 1U, 1U
	),
	uint2x3(
		1U, 1U, 1U,
		1U, 1U, 1U
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_cdivm,
	uint2x3(
		2U, 2U, 2U,
		2U, 2U, 2U
	),
	uint2x3(
		2U, 2U, 2U,
		2U, 2U, 2U
	),
	uint2x3(
		1U, 1U, 1U,
		1U, 1U, 1U
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_cdivm,
	uint2x3(
		4U, 4U, 4U,
		4U, 4U, 4U
	),
	uint2x3(
		2U, 2U, 2U,
		2U, 2U, 2U
	),
	uint2x3(
		2U, 2U, 2U,
		2U, 2U, 2U
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_cdivm,
	uint2x3(
		8U, 8U, 8U,
		8U, 8U, 8U
	),
	uint2x3(
		4U, 4U, 4U,
		4U, 4U, 4U
	),
	uint2x3(
		2U, 2U, 2U,
		2U, 2U, 2U
	)
);

#if defined( __GNUC__ ) || defined( __clang__ )
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wcast-qual"
#endif

TEMPER_PARAMETRIC( Test_uint2x3_increment_prefix, TEMPER_FLAG_SHOULD_RUN, const uint2x3& x, const uint2x3& expectedAnswer )
{
	// make local copy of x and use that because we cant do increment or decrement operations on a const reference
	// and MSVC throws warnings if we just make the parameter a non-const reference
	uint2x3 xlocal = (uint2x3) x;
	uint2x3 actualAnswer = ++xlocal;
	TEMPER_CHECK_TRUE( actualAnswer == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_increment_prefix,
	uint2x3(
		1U, 1U, 1U,
		1U, 1U, 1U
	),
	uint2x3(
		2U, 2U, 2U,
		2U, 2U, 2U
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_increment_prefix,
	uint2x3(
		2U, 2U, 2U,
		2U, 2U, 2U
	),
	uint2x3(
		3U, 3U, 3U,
		3U, 3U, 3U
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_increment_prefix,
	uint2x3(
		3U, 3U, 3U,
		3U, 3U, 3U
	),
	uint2x3(
		4U, 4U, 4U,
		4U, 4U, 4U
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_increment_prefix,
	uint2x3(
		4U, 4U, 4U,
		4U, 4U, 4U
	),
	uint2x3(
		5U, 5U, 5U,
		5U, 5U, 5U
	)
);

TEMPER_PARAMETRIC( Test_uint2x3_increment_postfix, TEMPER_FLAG_SHOULD_RUN, const uint2x3& x, const uint2x3& expectedAnswer )
{
	// make local copy of x and use that because we cant do increment or decrement operations on a const reference
	// and MSVC throws warnings if we just make the parameter a non-const reference
	uint2x3 xlocal = (uint2x3) x;
	uint2x3 actualAnswer = xlocal++;
	TEMPER_CHECK_TRUE( actualAnswer == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_increment_postfix,
	uint2x3(
		1U, 1U, 1U,
		1U, 1U, 1U
	),
	uint2x3(
		2U, 2U, 2U,
		2U, 2U, 2U
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_increment_postfix,
	uint2x3(
		2U, 2U, 2U,
		2U, 2U, 2U
	),
	uint2x3(
		3U, 3U, 3U,
		3U, 3U, 3U
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_increment_postfix,
	uint2x3(
		3U, 3U, 3U,
		3U, 3U, 3U
	),
	uint2x3(
		4U, 4U, 4U,
		4U, 4U, 4U
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_increment_postfix,
	uint2x3(
		4U, 4U, 4U,
		4U, 4U, 4U
	),
	uint2x3(
		5U, 5U, 5U,
		5U, 5U, 5U
	)
);

TEMPER_PARAMETRIC( Test_uint2x3_decrement_prefix, TEMPER_FLAG_SHOULD_RUN, const uint2x3& x, const uint2x3& expectedAnswer )
{
	// make local copy of x and use that because we cant do increment or decrement operations on a const reference
	// and MSVC throws warnings if we just make the parameter a non-const reference
	uint2x3 xlocal = (uint2x3) x;
	uint2x3 actualAnswer = --xlocal;
	TEMPER_CHECK_TRUE( actualAnswer == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_decrement_prefix,
	uint2x3(
		1U, 1U, 1U,
		1U, 1U, 1U
	),
	uint2x3(
		0U, 0U, 0U,
		0U, 0U, 0U
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_decrement_prefix,
	uint2x3(
		2U, 2U, 2U,
		2U, 2U, 2U
	),
	uint2x3(
		1U, 1U, 1U,
		1U, 1U, 1U
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_decrement_prefix,
	uint2x3(
		3U, 3U, 3U,
		3U, 3U, 3U
	),
	uint2x3(
		2U, 2U, 2U,
		2U, 2U, 2U
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_decrement_prefix,
	uint2x3(
		4U, 4U, 4U,
		4U, 4U, 4U
	),
	uint2x3(
		3U, 3U, 3U,
		3U, 3U, 3U
	)
);

TEMPER_PARAMETRIC( Test_uint2x3_decrement_postfix, TEMPER_FLAG_SHOULD_RUN, const uint2x3& x, const uint2x3& expectedAnswer )
{
	// make local copy of x and use that because we cant do increment or decrement operations on a const reference
	// and MSVC throws warnings if we just make the parameter a non-const reference
	uint2x3 xlocal = (uint2x3) x;
	uint2x3 actualAnswer = xlocal--;
	TEMPER_CHECK_TRUE( actualAnswer == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_decrement_postfix,
	uint2x3(
		1U, 1U, 1U,
		1U, 1U, 1U
	),
	uint2x3(
		0U, 0U, 0U,
		0U, 0U, 0U
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_decrement_postfix,
	uint2x3(
		2U, 2U, 2U,
		2U, 2U, 2U
	),
	uint2x3(
		1U, 1U, 1U,
		1U, 1U, 1U
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_decrement_postfix,
	uint2x3(
		3U, 3U, 3U,
		3U, 3U, 3U
	),
	uint2x3(
		2U, 2U, 2U,
		2U, 2U, 2U
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_decrement_postfix,
	uint2x3(
		4U, 4U, 4U,
		4U, 4U, 4U
	),
	uint2x3(
		3U, 3U, 3U,
		3U, 3U, 3U
	)
);

#if defined( __GNUC__ ) || defined( __clang__ )
#pragma GCC diagnostic pop
#endif
#if defined( __GNUC__ ) || defined( __clang__ )
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wcast-qual"
#endif
TEMPER_PARAMETRIC( Test_uint2x3_negate_prefix, TEMPER_FLAG_SHOULD_RUN, const uint2x3& x, const uint2x3& expectedAnswer )
{
	// make local copy of x and use that because we cant do increment or decrement operations on a const reference
	// and MSVC throws warnings if we just make the parameter a non-const reference
	uint2x3 xlocal = (uint2x3) x;
	uint2x3 actualAnswer = -xlocal;
	TEMPER_CHECK_TRUE( actualAnswer == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_negate_prefix,
	uint2x3(
		0U, 0U, 0U,
		0U, 0U, 0U
	),
	uint2x3(
		0U, 0U, 0U,
		0U, 0U, 0U
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_negate_prefix,
	uint2x3(
		1U, 1U, 1U,
		1U, 1U, 1U
	),
	uint2x3(
		4294967295U, 4294967295U, 4294967295U,
		4294967295U, 4294967295U, 4294967295U
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_negate_prefix,
	uint2x3(
		2U, 2U, 2U,
		2U, 2U, 2U
	),
	uint2x3(
		4294967294U, 4294967294U, 4294967294U,
		4294967294U, 4294967294U, 4294967294U
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_negate_prefix,
	uint2x3(
		3U, 3U, 3U,
		3U, 3U, 3U
	),
	uint2x3(
		4294967293U, 4294967293U, 4294967293U,
		4294967293U, 4294967293U, 4294967293U
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_negate_prefix,
	uint2x3(
		10U, 10U, 10U,
		10U, 10U, 10U
	),
	uint2x3(
		4294967286U, 4294967286U, 4294967286U,
		4294967286U, 4294967286U, 4294967286U
	)
);

#if defined( __GNUC__ ) || defined( __clang__ )
#pragma GCC diagnostic pop
#endif

#if defined( __GNUC__ ) || defined( __clang__ )
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wcast-qual"
#endif
TEMPER_PARAMETRIC( Test_uint2x3_not_prefix, TEMPER_FLAG_SHOULD_RUN, const uint2x3& x, const uint2x3& expectedAnswer )
{
	// make local copy of x and use that because we cant do increment or decrement operations on a const reference
	// and MSVC throws warnings if we just make the parameter a non-const reference
	uint2x3 xlocal = (uint2x3) x;
	uint2x3 actualAnswer = ~xlocal;
	TEMPER_CHECK_TRUE( actualAnswer == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_not_prefix,
	uint2x3(
		1U, 1U, 1U,
		1U, 1U, 1U
	),
	uint2x3(
		4294967294U, 4294967294U, 4294967294U,
		4294967294U, 4294967294U, 4294967294U
	)
);

#if defined( __GNUC__ ) || defined( __clang__ )
#pragma GCC diagnostic pop
#endif

TEMPER_PARAMETRIC( Test_uint2x3_cands, TEMPER_FLAG_SHOULD_RUN, const uint2x3& lhs, const uint32_t& rhs, const uint2x3& expectedAnswer )
{
	uint2x3 actualResult = lhs & rhs;
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_cands,
	uint2x3(
		0U, 0U, 0U,
		0U, 0U, 0U
	),
	0U,
	uint2x3(
		0U, 0U, 0U,
		0U, 0U, 0U
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_cands,
	uint2x3(
		2U, 2U, 2U,
		2U, 2U, 2U
	),
	1U,
	uint2x3(
		0U, 0U, 0U,
		0U, 0U, 0U
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_cands,
	uint2x3(
		1U, 1U, 1U,
		1U, 1U, 1U
	),
	0U,
	uint2x3(
		0U, 0U, 0U,
		0U, 0U, 0U
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_cands,
	uint2x3(
		1U, 1U, 1U,
		1U, 1U, 1U
	),
	1U,
	uint2x3(
		1U, 1U, 1U,
		1U, 1U, 1U
	)
);

TEMPER_PARAMETRIC( Test_uint2x3_cors, TEMPER_FLAG_SHOULD_RUN, const uint2x3& lhs, const uint32_t& rhs, const uint2x3& expectedAnswer )
{
	uint2x3 actualResult = lhs | rhs;
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_cors,
	uint2x3(
		0U, 0U, 0U,
		0U, 0U, 0U
	),
	0U,
	uint2x3(
		0U, 0U, 0U,
		0U, 0U, 0U
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_cors,
	uint2x3(
		2U, 2U, 2U,
		2U, 2U, 2U
	),
	1U,
	uint2x3(
		3U, 3U, 3U,
		3U, 3U, 3U
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_cors,
	uint2x3(
		1U, 1U, 1U,
		1U, 1U, 1U
	),
	0U,
	uint2x3(
		1U, 1U, 1U,
		1U, 1U, 1U
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_cors,
	uint2x3(
		1U, 1U, 1U,
		1U, 1U, 1U
	),
	1U,
	uint2x3(
		1U, 1U, 1U,
		1U, 1U, 1U
	)
);

TEMPER_PARAMETRIC( Test_uint2x3_cxors, TEMPER_FLAG_SHOULD_RUN, const uint2x3& lhs, const uint32_t& rhs, const uint2x3& expectedAnswer )
{
	uint2x3 actualResult = lhs ^ rhs;
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_cxors,
	uint2x3(
		0U, 0U, 0U,
		0U, 0U, 0U
	),
	0U,
	uint2x3(
		0U, 0U, 0U,
		0U, 0U, 0U
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_cxors,
	uint2x3(
		2U, 2U, 2U,
		2U, 2U, 2U
	),
	1U,
	uint2x3(
		3U, 3U, 3U,
		3U, 3U, 3U
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_cxors,
	uint2x3(
		1U, 1U, 1U,
		1U, 1U, 1U
	),
	0U,
	uint2x3(
		1U, 1U, 1U,
		1U, 1U, 1U
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_cxors,
	uint2x3(
		1U, 1U, 1U,
		1U, 1U, 1U
	),
	1U,
	uint2x3(
		0U, 0U, 0U,
		0U, 0U, 0U
	)
);

TEMPER_PARAMETRIC( Test_uint2x3_cshift_lefts, TEMPER_FLAG_SHOULD_RUN, const uint2x3& lhs, const uint32_t& rhs, const uint2x3& expectedAnswer )
{
	uint2x3 actualResult = lhs << rhs;
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_cshift_lefts,
	uint2x3(
		0U, 0U, 0U,
		0U, 0U, 0U
	),
	0U,
	uint2x3(
		0U, 0U, 0U,
		0U, 0U, 0U
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_cshift_lefts,
	uint2x3(
		2U, 2U, 2U,
		2U, 2U, 2U
	),
	1U,
	uint2x3(
		4U, 4U, 4U,
		4U, 4U, 4U
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_cshift_lefts,
	uint2x3(
		1U, 1U, 1U,
		1U, 1U, 1U
	),
	0U,
	uint2x3(
		1U, 1U, 1U,
		1U, 1U, 1U
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_cshift_lefts,
	uint2x3(
		1U, 1U, 1U,
		1U, 1U, 1U
	),
	1U,
	uint2x3(
		2U, 2U, 2U,
		2U, 2U, 2U
	)
);

TEMPER_PARAMETRIC( Test_uint2x3_cshift_rights, TEMPER_FLAG_SHOULD_RUN, const uint2x3& lhs, const uint32_t& rhs, const uint2x3& expectedAnswer )
{
	uint2x3 actualResult = lhs >> rhs;
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_cshift_rights,
	uint2x3(
		0U, 0U, 0U,
		0U, 0U, 0U
	),
	0U,
	uint2x3(
		0U, 0U, 0U,
		0U, 0U, 0U
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_cshift_rights,
	uint2x3(
		2U, 2U, 2U,
		2U, 2U, 2U
	),
	1U,
	uint2x3(
		1U, 1U, 1U,
		1U, 1U, 1U
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_cshift_rights,
	uint2x3(
		1U, 1U, 1U,
		1U, 1U, 1U
	),
	0U,
	uint2x3(
		1U, 1U, 1U,
		1U, 1U, 1U
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_cshift_rights,
	uint2x3(
		1U, 1U, 1U,
		1U, 1U, 1U
	),
	1U,
	uint2x3(
		0U, 0U, 0U,
		0U, 0U, 0U
	)
);

TEMPER_PARAMETRIC( Test_uint2x3_candm, TEMPER_FLAG_SHOULD_RUN, const uint2x3& lhs, const uint2x3& rhs, const uint2x3& expectedAnswer )
{
	uint2x3 actualResult = lhs & rhs;
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_candm,
	uint2x3(
		0U, 0U, 0U,
		0U, 0U, 0U
	),
	uint2x3(
		0U, 0U, 0U,
		0U, 0U, 0U
	),
	uint2x3(
		0U, 0U, 0U,
		0U, 0U, 0U
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_candm,
	uint2x3(
		2U, 2U, 2U,
		2U, 2U, 2U
	),
	uint2x3(
		1U, 1U, 1U,
		1U, 1U, 1U
	),
	uint2x3(
		0U, 0U, 0U,
		0U, 0U, 0U
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_candm,
	uint2x3(
		1U, 1U, 1U,
		1U, 1U, 1U
	),
	uint2x3(
		0U, 0U, 0U,
		0U, 0U, 0U
	),
	uint2x3(
		0U, 0U, 0U,
		0U, 0U, 0U
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_candm,
	uint2x3(
		1U, 1U, 1U,
		1U, 1U, 1U
	),
	uint2x3(
		1U, 1U, 1U,
		1U, 1U, 1U
	),
	uint2x3(
		1U, 1U, 1U,
		1U, 1U, 1U
	)
);

TEMPER_PARAMETRIC( Test_uint2x3_corm, TEMPER_FLAG_SHOULD_RUN, const uint2x3& lhs, const uint2x3& rhs, const uint2x3& expectedAnswer )
{
	uint2x3 actualResult = lhs | rhs;
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_corm,
	uint2x3(
		0U, 0U, 0U,
		0U, 0U, 0U
	),
	uint2x3(
		0U, 0U, 0U,
		0U, 0U, 0U
	),
	uint2x3(
		0U, 0U, 0U,
		0U, 0U, 0U
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_corm,
	uint2x3(
		2U, 2U, 2U,
		2U, 2U, 2U
	),
	uint2x3(
		1U, 1U, 1U,
		1U, 1U, 1U
	),
	uint2x3(
		3U, 3U, 3U,
		3U, 3U, 3U
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_corm,
	uint2x3(
		1U, 1U, 1U,
		1U, 1U, 1U
	),
	uint2x3(
		0U, 0U, 0U,
		0U, 0U, 0U
	),
	uint2x3(
		1U, 1U, 1U,
		1U, 1U, 1U
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_corm,
	uint2x3(
		1U, 1U, 1U,
		1U, 1U, 1U
	),
	uint2x3(
		1U, 1U, 1U,
		1U, 1U, 1U
	),
	uint2x3(
		1U, 1U, 1U,
		1U, 1U, 1U
	)
);

TEMPER_PARAMETRIC( Test_uint2x3_cxorm, TEMPER_FLAG_SHOULD_RUN, const uint2x3& lhs, const uint2x3& rhs, const uint2x3& expectedAnswer )
{
	uint2x3 actualResult = lhs ^ rhs;
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_cxorm,
	uint2x3(
		0U, 0U, 0U,
		0U, 0U, 0U
	),
	uint2x3(
		0U, 0U, 0U,
		0U, 0U, 0U
	),
	uint2x3(
		0U, 0U, 0U,
		0U, 0U, 0U
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_cxorm,
	uint2x3(
		2U, 2U, 2U,
		2U, 2U, 2U
	),
	uint2x3(
		1U, 1U, 1U,
		1U, 1U, 1U
	),
	uint2x3(
		3U, 3U, 3U,
		3U, 3U, 3U
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_cxorm,
	uint2x3(
		1U, 1U, 1U,
		1U, 1U, 1U
	),
	uint2x3(
		0U, 0U, 0U,
		0U, 0U, 0U
	),
	uint2x3(
		1U, 1U, 1U,
		1U, 1U, 1U
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_cxorm,
	uint2x3(
		1U, 1U, 1U,
		1U, 1U, 1U
	),
	uint2x3(
		1U, 1U, 1U,
		1U, 1U, 1U
	),
	uint2x3(
		0U, 0U, 0U,
		0U, 0U, 0U
	)
);

TEMPER_PARAMETRIC( Test_uint2x3_cshift_leftm, TEMPER_FLAG_SHOULD_RUN, const uint2x3& lhs, const uint2x3& rhs, const uint2x3& expectedAnswer )
{
	uint2x3 actualResult = lhs << rhs;
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_cshift_leftm,
	uint2x3(
		0U, 0U, 0U,
		0U, 0U, 0U
	),
	uint2x3(
		0U, 0U, 0U,
		0U, 0U, 0U
	),
	uint2x3(
		0U, 0U, 0U,
		0U, 0U, 0U
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_cshift_leftm,
	uint2x3(
		2U, 2U, 2U,
		2U, 2U, 2U
	),
	uint2x3(
		1U, 1U, 1U,
		1U, 1U, 1U
	),
	uint2x3(
		4U, 4U, 4U,
		4U, 4U, 4U
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_cshift_leftm,
	uint2x3(
		1U, 1U, 1U,
		1U, 1U, 1U
	),
	uint2x3(
		0U, 0U, 0U,
		0U, 0U, 0U
	),
	uint2x3(
		1U, 1U, 1U,
		1U, 1U, 1U
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_cshift_leftm,
	uint2x3(
		1U, 1U, 1U,
		1U, 1U, 1U
	),
	uint2x3(
		1U, 1U, 1U,
		1U, 1U, 1U
	),
	uint2x3(
		2U, 2U, 2U,
		2U, 2U, 2U
	)
);

TEMPER_PARAMETRIC( Test_uint2x3_cshift_rightm, TEMPER_FLAG_SHOULD_RUN, const uint2x3& lhs, const uint2x3& rhs, const uint2x3& expectedAnswer )
{
	uint2x3 actualResult = lhs >> rhs;
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_cshift_rightm,
	uint2x3(
		0U, 0U, 0U,
		0U, 0U, 0U
	),
	uint2x3(
		0U, 0U, 0U,
		0U, 0U, 0U
	),
	uint2x3(
		0U, 0U, 0U,
		0U, 0U, 0U
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_cshift_rightm,
	uint2x3(
		2U, 2U, 2U,
		2U, 2U, 2U
	),
	uint2x3(
		1U, 1U, 1U,
		1U, 1U, 1U
	),
	uint2x3(
		1U, 1U, 1U,
		1U, 1U, 1U
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_cshift_rightm,
	uint2x3(
		1U, 1U, 1U,
		1U, 1U, 1U
	),
	uint2x3(
		0U, 0U, 0U,
		0U, 0U, 0U
	),
	uint2x3(
		1U, 1U, 1U,
		1U, 1U, 1U
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_cshift_rightm,
	uint2x3(
		1U, 1U, 1U,
		1U, 1U, 1U
	),
	uint2x3(
		1U, 1U, 1U,
		1U, 1U, 1U
	),
	uint2x3(
		0U, 0U, 0U,
		0U, 0U, 0U
	)
);

TEMPER_PARAMETRIC( Test_uint2x3_min, TEMPER_FLAG_SHOULD_RUN, const uint2x3& lhs, const uint2x3& rhs, const uint2x3& expectedAnswer )
{
	uint2x3 actualResult = min( lhs, rhs );
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_min,
	uint2x3(
		0U, 0U, 0U,
		0U, 0U, 0U
	),
	uint2x3(
		1U, 1U, 1U,
		1U, 1U, 1U
	),
	uint2x3(
		0U, 0U, 0U,
		0U, 0U, 0U
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_min,
	uint2x3(
		1U, 1U, 1U,
		1U, 1U, 1U
	),
	uint2x3(
		2U, 2U, 2U,
		2U, 2U, 2U
	),
	uint2x3(
		1U, 1U, 1U,
		1U, 1U, 1U
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_min,
	uint2x3(
		420U, 420U, 420U,
		420U, 420U, 420U
	),
	uint2x3(
		69U, 69U, 69U,
		69U, 69U, 69U
	),
	uint2x3(
		69U, 69U, 69U,
		69U, 69U, 69U
	)
);

TEMPER_PARAMETRIC( Test_uint2x3_max, TEMPER_FLAG_SHOULD_RUN, const uint2x3& lhs, const uint2x3& rhs, const uint2x3& expectedAnswer )
{
	uint2x3 actualResult = max( lhs, rhs );
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_max,
	uint2x3(
		0U, 0U, 0U,
		0U, 0U, 0U
	),
	uint2x3(
		1U, 1U, 1U,
		1U, 1U, 1U
	),
	uint2x3(
		1U, 1U, 1U,
		1U, 1U, 1U
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_max,
	uint2x3(
		1U, 1U, 1U,
		1U, 1U, 1U
	),
	uint2x3(
		2U, 2U, 2U,
		2U, 2U, 2U
	),
	uint2x3(
		2U, 2U, 2U,
		2U, 2U, 2U
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_max,
	uint2x3(
		69U, 69U, 69U,
		69U, 69U, 69U
	),
	uint2x3(
		420U, 420U, 420U,
		420U, 420U, 420U
	),
	uint2x3(
		420U, 420U, 420U,
		420U, 420U, 420U
	)
);

TEMPER_PARAMETRIC( Test_uint2x3_saturate, TEMPER_FLAG_SHOULD_RUN, const uint2x3& x, const uint2x3& expectedAnswer )
{
	uint2x3 actualResult = saturate( x );
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_saturate,
	uint2x3(
		0U, 0U, 0U,
		0U, 0U, 0U
	),
	uint2x3(
		0U, 0U, 0U,
		0U, 0U, 0U
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_saturate,
	uint2x3(
		1U, 1U, 1U,
		1U, 1U, 1U
	),
	uint2x3(
		1U, 1U, 1U,
		1U, 1U, 1U
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_saturate,
	uint2x3(
		2U, 2U, 2U,
		2U, 2U, 2U
	),
	uint2x3(
		1U, 1U, 1U,
		1U, 1U, 1U
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_saturate,
	uint2x3(
		3U, 3U, 3U,
		3U, 3U, 3U
	),
	uint2x3(
		1U, 1U, 1U,
		1U, 1U, 1U
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_saturate,
	uint2x3(
		10U, 10U, 10U,
		10U, 10U, 10U
	),
	uint2x3(
		1U, 1U, 1U,
		1U, 1U, 1U
	)
);

TEMPER_PARAMETRIC( Test_uint2x3_int2x3, TEMPER_FLAG_SHOULD_RUN, const int2x3& convertFrom, const uint2x3& expectedAnswer )
{
	uint2x3 actualAnswer = uint2x3( convertFrom );

	TEMPER_CHECK_TRUE( expectedAnswer[0][0] == actualAnswer[0][0] );
	TEMPER_CHECK_TRUE( expectedAnswer[0][1] == actualAnswer[0][1] );
	TEMPER_CHECK_TRUE( expectedAnswer[0][2] == actualAnswer[0][2] );

	TEMPER_CHECK_TRUE( expectedAnswer[1][0] == actualAnswer[1][0] );
	TEMPER_CHECK_TRUE( expectedAnswer[1][1] == actualAnswer[1][1] );
	TEMPER_CHECK_TRUE( expectedAnswer[1][2] == actualAnswer[1][2] );

}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_int2x3,
	int2x3(
		0, 0, 0,
		0, 0, 0
	),
	uint2x3(
		0U, 0U, 0U,
		0U, 0U, 0U
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_int2x3,
	int2x3(
		10, 10, 10,
		10, 10, 10
	),
	uint2x3(
		10U, 10U, 10U,
		10U, 10U, 10U
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_int2x3,
	int2x3(
		10, 20, 30,
		50, 60, 70
	),
	uint2x3(
		10U, 20U, 30U,
		50U, 60U, 70U
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_int2x3,
	int2x3(
		160, 150, 140,
		120, 110, 100
	),
	uint2x3(
		160U, 150U, 140U,
		120U, 110U, 100U
	)
);

TEMPER_PARAMETRIC( Test_uint2x3_uint2x3, TEMPER_FLAG_SHOULD_RUN, const uint2x3& convertFrom, const uint2x3& expectedAnswer )
{
	uint2x3 actualAnswer = uint2x3( convertFrom );

	TEMPER_CHECK_TRUE( expectedAnswer[0][0] == actualAnswer[0][0] );
	TEMPER_CHECK_TRUE( expectedAnswer[0][1] == actualAnswer[0][1] );
	TEMPER_CHECK_TRUE( expectedAnswer[0][2] == actualAnswer[0][2] );

	TEMPER_CHECK_TRUE( expectedAnswer[1][0] == actualAnswer[1][0] );
	TEMPER_CHECK_TRUE( expectedAnswer[1][1] == actualAnswer[1][1] );
	TEMPER_CHECK_TRUE( expectedAnswer[1][2] == actualAnswer[1][2] );

}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_uint2x3,
	uint2x3(
		0U, 0U, 0U,
		0U, 0U, 0U
	),
	uint2x3(
		0U, 0U, 0U,
		0U, 0U, 0U
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_uint2x3,
	uint2x3(
		10U, 10U, 10U,
		10U, 10U, 10U
	),
	uint2x3(
		10U, 10U, 10U,
		10U, 10U, 10U
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_uint2x3,
	uint2x3(
		10U, 20U, 30U,
		50U, 60U, 70U
	),
	uint2x3(
		10U, 20U, 30U,
		50U, 60U, 70U
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_uint2x3,
	uint2x3(
		160U, 150U, 140U,
		120U, 110U, 100U
	),
	uint2x3(
		160U, 150U, 140U,
		120U, 110U, 100U
	)
);

TEMPER_PARAMETRIC( Test_uint2x3_float2x3, TEMPER_FLAG_SHOULD_RUN, const float2x3& convertFrom, const uint2x3& expectedAnswer )
{
	uint2x3 actualAnswer = uint2x3( convertFrom );

	TEMPER_CHECK_TRUE( expectedAnswer[0][0] == actualAnswer[0][0] );
	TEMPER_CHECK_TRUE( expectedAnswer[0][1] == actualAnswer[0][1] );
	TEMPER_CHECK_TRUE( expectedAnswer[0][2] == actualAnswer[0][2] );

	TEMPER_CHECK_TRUE( expectedAnswer[1][0] == actualAnswer[1][0] );
	TEMPER_CHECK_TRUE( expectedAnswer[1][1] == actualAnswer[1][1] );
	TEMPER_CHECK_TRUE( expectedAnswer[1][2] == actualAnswer[1][2] );

}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_float2x3,
	float2x3(
		0.000000f, 0.000000f, 0.000000f,
		0.000000f, 0.000000f, 0.000000f
	),
	uint2x3(
		0U, 0U, 0U,
		0U, 0U, 0U
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_float2x3,
	float2x3(
		10.000000f, 10.000000f, 10.000000f,
		10.000000f, 10.000000f, 10.000000f
	),
	uint2x3(
		10U, 10U, 10U,
		10U, 10U, 10U
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_float2x3,
	float2x3(
		10.000000f, 20.000000f, 30.000000f,
		50.000000f, 60.000000f, 70.000000f
	),
	uint2x3(
		10U, 20U, 30U,
		50U, 60U, 70U
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_float2x3,
	float2x3(
		160.000000f, 150.000000f, 140.000000f,
		120.000000f, 110.000000f, 100.000000f
	),
	uint2x3(
		160U, 150U, 140U,
		120U, 110U, 100U
	)
);

TEMPER_PARAMETRIC( Test_uint2x3_double2x3, TEMPER_FLAG_SHOULD_RUN, const double2x3& convertFrom, const uint2x3& expectedAnswer )
{
	uint2x3 actualAnswer = uint2x3( convertFrom );

	TEMPER_CHECK_TRUE( expectedAnswer[0][0] == actualAnswer[0][0] );
	TEMPER_CHECK_TRUE( expectedAnswer[0][1] == actualAnswer[0][1] );
	TEMPER_CHECK_TRUE( expectedAnswer[0][2] == actualAnswer[0][2] );

	TEMPER_CHECK_TRUE( expectedAnswer[1][0] == actualAnswer[1][0] );
	TEMPER_CHECK_TRUE( expectedAnswer[1][1] == actualAnswer[1][1] );
	TEMPER_CHECK_TRUE( expectedAnswer[1][2] == actualAnswer[1][2] );

}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_double2x3,
	double2x3(
		0.000000f, 0.000000f, 0.000000f,
		0.000000f, 0.000000f, 0.000000f
	),
	uint2x3(
		0U, 0U, 0U,
		0U, 0U, 0U
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_double2x3,
	double2x3(
		10.000000f, 10.000000f, 10.000000f,
		10.000000f, 10.000000f, 10.000000f
	),
	uint2x3(
		10U, 10U, 10U,
		10U, 10U, 10U
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_double2x3,
	double2x3(
		10.000000f, 20.000000f, 30.000000f,
		50.000000f, 60.000000f, 70.000000f
	),
	uint2x3(
		10U, 20U, 30U,
		50U, 60U, 70U
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_double2x3,
	double2x3(
		160.000000f, 150.000000f, 140.000000f,
		120.000000f, 110.000000f, 100.000000f
	),
	uint2x3(
		160U, 150U, 140U,
		120U, 110U, 100U
	)
);

TEMPER_PARAMETRIC( Test_uint2x3_identity, TEMPER_FLAG_SHOULD_RUN, const uint2x3& matrix, const bool expectedAnswer )
{
	uint2x3 identityMat;
	identity( identityMat );
	bool isMatrixIdentity = ( identityMat == matrix );
	TEMPER_CHECK_TRUE( isMatrixIdentity == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_identity,
	uint2x3(
		1U, 0U, 0U,
		0U, 1U, 0U
	),
	true
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_identity,
	uint2x3(
		1U, 1U, 0U,
		0U, 1U, 0U
	),
	false
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_identity,
	uint2x3(
		1U, 0U, 0U,
		1U, 1U, 0U
	),
	false
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_identity,
	uint2x3(
		1U, 1U, 0U,
		1U, 1U, 0U
	),
	false
);

TEMPER_PARAMETRIC( Test_uint2x3_transpose, TEMPER_FLAG_SHOULD_RUN, const uint2x3& matrix, const uint3x2& expectedAnswer )
{
	uint3x2 actualResult = transpose( matrix );
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_transpose,
	uint2x3(
		1U, 0U, 0U,
		0U, 1U, 0U
	),
	uint3x2(
		1U, 0U,
		0U, 1U,
		0U, 0U
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_transpose,
	uint2x3(
		0U, 1U, 2U,
		4U, 5U, 6U
	),
	uint3x2(
		0U, 4U,
		1U, 5U,
		2U, 6U
	)
);

TEMPER_PARAMETRIC( Test_uint2x3_mulm, TEMPER_FLAG_SHOULD_RUN, const uint2x3& lhs, const uint3x2& rhs, const uint2x2& expectedAnswer )
{
	uint2x2 actualResult = mul( lhs, rhs );
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_mulm,
	uint2x3(
		2U, 2U, 2U,
		2U, 2U, 2U
	),
	uint3x2(
		4U, 4U,
		4U, 4U,
		4U, 4U
	),
	uint2x2(
		24U, 24U,
		24U, 24U
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint2x3_mulm,
	uint2x3(
		2U, 2U, 2U,
		2U, 2U, 2U
	),
	uint3x2(
		1U, 0U,
		0U, 1U,
		0U, 0U
	),
	uint2x2(
		2U, 2U,
		2U, 2U
	)
);


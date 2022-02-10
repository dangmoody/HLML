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

TEMPER_PARAMETRIC( Test_float2x2_less_than, TEMPER_FLAG_SHOULD_RUN, const float2x2& lhs, const float2x2& rhs, const bool2x2& expectedAnswer )
{
	bool2x2 actualResult = lhs < rhs;
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float2x2_less_than,
	float2x2(
		0.000000f, 0.000000f,
		0.000000f, 0.000000f
	),
	float2x2(
		0.000000f, 0.000000f,
		0.000000f, 0.000000f
	),
	bool2x2(
		false, false,
		false, false
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float2x2_less_than,
	float2x2(
		0.000000f, 0.000000f,
		0.000000f, 0.000000f
	),
	float2x2(
		1.000000f, 1.000000f,
		1.000000f, 1.000000f
	),
	bool2x2(
		true, true,
		true, true
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float2x2_less_than,
	float2x2(
		1.000000f, 1.000000f,
		1.000000f, 1.000000f
	),
	float2x2(
		1.000000f, 1.000000f,
		1.000000f, 1.000000f
	),
	bool2x2(
		false, false,
		false, false
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float2x2_less_than,
	float2x2(
		1.000000f, 1.000000f,
		1.000000f, 1.000000f
	),
	float2x2(
		0.000000f, 0.000000f,
		0.000000f, 0.000000f
	),
	bool2x2(
		false, false,
		false, false
	)
);

TEMPER_PARAMETRIC( Test_float2x2_less_than_equal, TEMPER_FLAG_SHOULD_RUN, const float2x2& lhs, const float2x2& rhs, const bool2x2& expectedAnswer )
{
	bool2x2 actualResult = lhs <= rhs;
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float2x2_less_than_equal,
	float2x2(
		0.000000f, 0.000000f,
		0.000000f, 0.000000f
	),
	float2x2(
		0.000000f, 0.000000f,
		0.000000f, 0.000000f
	),
	bool2x2(
		true, true,
		true, true
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float2x2_less_than_equal,
	float2x2(
		0.000000f, 0.000000f,
		0.000000f, 0.000000f
	),
	float2x2(
		1.000000f, 1.000000f,
		1.000000f, 1.000000f
	),
	bool2x2(
		true, true,
		true, true
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float2x2_less_than_equal,
	float2x2(
		1.000000f, 1.000000f,
		1.000000f, 1.000000f
	),
	float2x2(
		1.000000f, 1.000000f,
		1.000000f, 1.000000f
	),
	bool2x2(
		true, true,
		true, true
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float2x2_less_than_equal,
	float2x2(
		1.000000f, 1.000000f,
		1.000000f, 1.000000f
	),
	float2x2(
		0.000000f, 0.000000f,
		0.000000f, 0.000000f
	),
	bool2x2(
		false, false,
		false, false
	)
);

TEMPER_PARAMETRIC( Test_float2x2_greater_than, TEMPER_FLAG_SHOULD_RUN, const float2x2& lhs, const float2x2& rhs, const bool2x2& expectedAnswer )
{
	bool2x2 actualResult = lhs > rhs;
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float2x2_greater_than,
	float2x2(
		0.000000f, 0.000000f,
		0.000000f, 0.000000f
	),
	float2x2(
		0.000000f, 0.000000f,
		0.000000f, 0.000000f
	),
	bool2x2(
		false, false,
		false, false
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float2x2_greater_than,
	float2x2(
		0.000000f, 0.000000f,
		0.000000f, 0.000000f
	),
	float2x2(
		1.000000f, 1.000000f,
		1.000000f, 1.000000f
	),
	bool2x2(
		false, false,
		false, false
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float2x2_greater_than,
	float2x2(
		1.000000f, 1.000000f,
		1.000000f, 1.000000f
	),
	float2x2(
		1.000000f, 1.000000f,
		1.000000f, 1.000000f
	),
	bool2x2(
		false, false,
		false, false
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float2x2_greater_than,
	float2x2(
		1.000000f, 1.000000f,
		1.000000f, 1.000000f
	),
	float2x2(
		0.000000f, 0.000000f,
		0.000000f, 0.000000f
	),
	bool2x2(
		true, true,
		true, true
	)
);

TEMPER_PARAMETRIC( Test_float2x2_greater_than_equal, TEMPER_FLAG_SHOULD_RUN, const float2x2& lhs, const float2x2& rhs, const bool2x2& expectedAnswer )
{
	bool2x2 actualResult = lhs >= rhs;
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float2x2_greater_than_equal,
	float2x2(
		0.000000f, 0.000000f,
		0.000000f, 0.000000f
	),
	float2x2(
		0.000000f, 0.000000f,
		0.000000f, 0.000000f
	),
	bool2x2(
		true, true,
		true, true
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float2x2_greater_than_equal,
	float2x2(
		0.000000f, 0.000000f,
		0.000000f, 0.000000f
	),
	float2x2(
		1.000000f, 1.000000f,
		1.000000f, 1.000000f
	),
	bool2x2(
		false, false,
		false, false
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float2x2_greater_than_equal,
	float2x2(
		1.000000f, 1.000000f,
		1.000000f, 1.000000f
	),
	float2x2(
		1.000000f, 1.000000f,
		1.000000f, 1.000000f
	),
	bool2x2(
		true, true,
		true, true
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float2x2_greater_than_equal,
	float2x2(
		1.000000f, 1.000000f,
		1.000000f, 1.000000f
	),
	float2x2(
		0.000000f, 0.000000f,
		0.000000f, 0.000000f
	),
	bool2x2(
		true, true,
		true, true
	)
);

TEMPER_PARAMETRIC( Test_float2x2_cadds, TEMPER_FLAG_SHOULD_RUN, const float2x2& lhs, const float& rhs, const float2x2& expectedAnswer )
{
	float2x2 actualResult = lhs + rhs;
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float2x2_cadds,
	float2x2(
		1.000000f, 1.000000f,
		1.000000f, 1.000000f
	),
	1.000000f,
	float2x2(
		2.000000f, 2.000000f,
		2.000000f, 2.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float2x2_cadds,
	float2x2(
		2.000000f, 2.000000f,
		2.000000f, 2.000000f
	),
	2.000000f,
	float2x2(
		4.000000f, 4.000000f,
		4.000000f, 4.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float2x2_cadds,
	float2x2(
		4.000000f, 4.000000f,
		4.000000f, 4.000000f
	),
	2.000000f,
	float2x2(
		6.000000f, 6.000000f,
		6.000000f, 6.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float2x2_cadds,
	float2x2(
		8.000000f, 8.000000f,
		8.000000f, 8.000000f
	),
	4.000000f,
	float2x2(
		12.000000f, 12.000000f,
		12.000000f, 12.000000f
	)
);

TEMPER_PARAMETRIC( Test_float2x2_csubs, TEMPER_FLAG_SHOULD_RUN, const float2x2& lhs, const float& rhs, const float2x2& expectedAnswer )
{
	float2x2 actualResult = lhs - rhs;
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float2x2_csubs,
	float2x2(
		1.000000f, 1.000000f,
		1.000000f, 1.000000f
	),
	1.000000f,
	float2x2(
		0.000000f, 0.000000f,
		0.000000f, 0.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float2x2_csubs,
	float2x2(
		2.000000f, 2.000000f,
		2.000000f, 2.000000f
	),
	2.000000f,
	float2x2(
		0.000000f, 0.000000f,
		0.000000f, 0.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float2x2_csubs,
	float2x2(
		4.000000f, 4.000000f,
		4.000000f, 4.000000f
	),
	2.000000f,
	float2x2(
		2.000000f, 2.000000f,
		2.000000f, 2.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float2x2_csubs,
	float2x2(
		8.000000f, 8.000000f,
		8.000000f, 8.000000f
	),
	4.000000f,
	float2x2(
		4.000000f, 4.000000f,
		4.000000f, 4.000000f
	)
);

TEMPER_PARAMETRIC( Test_float2x2_cmuls, TEMPER_FLAG_SHOULD_RUN, const float2x2& lhs, const float& rhs, const float2x2& expectedAnswer )
{
	float2x2 actualResult = lhs * rhs;
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float2x2_cmuls,
	float2x2(
		1.000000f, 1.000000f,
		1.000000f, 1.000000f
	),
	1.000000f,
	float2x2(
		1.000000f, 1.000000f,
		1.000000f, 1.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float2x2_cmuls,
	float2x2(
		2.000000f, 2.000000f,
		2.000000f, 2.000000f
	),
	2.000000f,
	float2x2(
		4.000000f, 4.000000f,
		4.000000f, 4.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float2x2_cmuls,
	float2x2(
		4.000000f, 4.000000f,
		4.000000f, 4.000000f
	),
	2.000000f,
	float2x2(
		8.000000f, 8.000000f,
		8.000000f, 8.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float2x2_cmuls,
	float2x2(
		8.000000f, 8.000000f,
		8.000000f, 8.000000f
	),
	4.000000f,
	float2x2(
		32.000000f, 32.000000f,
		32.000000f, 32.000000f
	)
);

TEMPER_PARAMETRIC( Test_float2x2_cdivs, TEMPER_FLAG_SHOULD_RUN, const float2x2& lhs, const float& rhs, const float2x2& expectedAnswer )
{
	float2x2 actualResult = lhs / rhs;
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float2x2_cdivs,
	float2x2(
		1.000000f, 1.000000f,
		1.000000f, 1.000000f
	),
	1.000000f,
	float2x2(
		1.000000f, 1.000000f,
		1.000000f, 1.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float2x2_cdivs,
	float2x2(
		2.000000f, 2.000000f,
		2.000000f, 2.000000f
	),
	2.000000f,
	float2x2(
		1.000000f, 1.000000f,
		1.000000f, 1.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float2x2_cdivs,
	float2x2(
		4.000000f, 4.000000f,
		4.000000f, 4.000000f
	),
	2.000000f,
	float2x2(
		2.000000f, 2.000000f,
		2.000000f, 2.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float2x2_cdivs,
	float2x2(
		8.000000f, 8.000000f,
		8.000000f, 8.000000f
	),
	4.000000f,
	float2x2(
		2.000000f, 2.000000f,
		2.000000f, 2.000000f
	)
);

TEMPER_PARAMETRIC( Test_float2x2_caddm, TEMPER_FLAG_SHOULD_RUN, const float2x2& lhs, const float2x2& rhs, const float2x2& expectedAnswer )
{
	float2x2 actualResult = lhs + rhs;
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float2x2_caddm,
	float2x2(
		1.000000f, 1.000000f,
		1.000000f, 1.000000f
	),
	float2x2(
		1.000000f, 1.000000f,
		1.000000f, 1.000000f
	),
	float2x2(
		2.000000f, 2.000000f,
		2.000000f, 2.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float2x2_caddm,
	float2x2(
		2.000000f, 2.000000f,
		2.000000f, 2.000000f
	),
	float2x2(
		2.000000f, 2.000000f,
		2.000000f, 2.000000f
	),
	float2x2(
		4.000000f, 4.000000f,
		4.000000f, 4.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float2x2_caddm,
	float2x2(
		4.000000f, 4.000000f,
		4.000000f, 4.000000f
	),
	float2x2(
		2.000000f, 2.000000f,
		2.000000f, 2.000000f
	),
	float2x2(
		6.000000f, 6.000000f,
		6.000000f, 6.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float2x2_caddm,
	float2x2(
		8.000000f, 8.000000f,
		8.000000f, 8.000000f
	),
	float2x2(
		4.000000f, 4.000000f,
		4.000000f, 4.000000f
	),
	float2x2(
		12.000000f, 12.000000f,
		12.000000f, 12.000000f
	)
);

TEMPER_PARAMETRIC( Test_float2x2_csubm, TEMPER_FLAG_SHOULD_RUN, const float2x2& lhs, const float2x2& rhs, const float2x2& expectedAnswer )
{
	float2x2 actualResult = lhs - rhs;
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float2x2_csubm,
	float2x2(
		1.000000f, 1.000000f,
		1.000000f, 1.000000f
	),
	float2x2(
		1.000000f, 1.000000f,
		1.000000f, 1.000000f
	),
	float2x2(
		0.000000f, 0.000000f,
		0.000000f, 0.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float2x2_csubm,
	float2x2(
		2.000000f, 2.000000f,
		2.000000f, 2.000000f
	),
	float2x2(
		2.000000f, 2.000000f,
		2.000000f, 2.000000f
	),
	float2x2(
		0.000000f, 0.000000f,
		0.000000f, 0.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float2x2_csubm,
	float2x2(
		4.000000f, 4.000000f,
		4.000000f, 4.000000f
	),
	float2x2(
		2.000000f, 2.000000f,
		2.000000f, 2.000000f
	),
	float2x2(
		2.000000f, 2.000000f,
		2.000000f, 2.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float2x2_csubm,
	float2x2(
		8.000000f, 8.000000f,
		8.000000f, 8.000000f
	),
	float2x2(
		4.000000f, 4.000000f,
		4.000000f, 4.000000f
	),
	float2x2(
		4.000000f, 4.000000f,
		4.000000f, 4.000000f
	)
);

TEMPER_PARAMETRIC( Test_float2x2_cmulm, TEMPER_FLAG_SHOULD_RUN, const float2x2& lhs, const float2x2& rhs, const float2x2& expectedAnswer )
{
	float2x2 actualResult = lhs * rhs;
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float2x2_cmulm,
	float2x2(
		1.000000f, 1.000000f,
		1.000000f, 1.000000f
	),
	float2x2(
		1.000000f, 1.000000f,
		1.000000f, 1.000000f
	),
	float2x2(
		1.000000f, 1.000000f,
		1.000000f, 1.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float2x2_cmulm,
	float2x2(
		2.000000f, 2.000000f,
		2.000000f, 2.000000f
	),
	float2x2(
		2.000000f, 2.000000f,
		2.000000f, 2.000000f
	),
	float2x2(
		4.000000f, 4.000000f,
		4.000000f, 4.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float2x2_cmulm,
	float2x2(
		4.000000f, 4.000000f,
		4.000000f, 4.000000f
	),
	float2x2(
		2.000000f, 2.000000f,
		2.000000f, 2.000000f
	),
	float2x2(
		8.000000f, 8.000000f,
		8.000000f, 8.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float2x2_cmulm,
	float2x2(
		8.000000f, 8.000000f,
		8.000000f, 8.000000f
	),
	float2x2(
		4.000000f, 4.000000f,
		4.000000f, 4.000000f
	),
	float2x2(
		32.000000f, 32.000000f,
		32.000000f, 32.000000f
	)
);

TEMPER_PARAMETRIC( Test_float2x2_cdivm, TEMPER_FLAG_SHOULD_RUN, const float2x2& lhs, const float2x2& rhs, const float2x2& expectedAnswer )
{
	float2x2 actualResult = lhs / rhs;
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float2x2_cdivm,
	float2x2(
		1.000000f, 1.000000f,
		1.000000f, 1.000000f
	),
	float2x2(
		1.000000f, 1.000000f,
		1.000000f, 1.000000f
	),
	float2x2(
		1.000000f, 1.000000f,
		1.000000f, 1.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float2x2_cdivm,
	float2x2(
		2.000000f, 2.000000f,
		2.000000f, 2.000000f
	),
	float2x2(
		2.000000f, 2.000000f,
		2.000000f, 2.000000f
	),
	float2x2(
		1.000000f, 1.000000f,
		1.000000f, 1.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float2x2_cdivm,
	float2x2(
		4.000000f, 4.000000f,
		4.000000f, 4.000000f
	),
	float2x2(
		2.000000f, 2.000000f,
		2.000000f, 2.000000f
	),
	float2x2(
		2.000000f, 2.000000f,
		2.000000f, 2.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float2x2_cdivm,
	float2x2(
		8.000000f, 8.000000f,
		8.000000f, 8.000000f
	),
	float2x2(
		4.000000f, 4.000000f,
		4.000000f, 4.000000f
	),
	float2x2(
		2.000000f, 2.000000f,
		2.000000f, 2.000000f
	)
);

#if defined( __GNUC__ ) || defined( __clang__ )
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wcast-qual"
#endif

TEMPER_PARAMETRIC( Test_float2x2_increment_prefix, TEMPER_FLAG_SHOULD_RUN, const float2x2& x, const float2x2& expectedAnswer )
{
	// make local copy of x and use that because we cant do increment or decrement operations on a const reference
	// and MSVC throws warnings if we just make the parameter a non-const reference
	float2x2 xlocal = (float2x2) x;
	float2x2 actualAnswer = ++xlocal;
	TEMPER_CHECK_TRUE( actualAnswer == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float2x2_increment_prefix,
	float2x2(
		1.000000f, 1.000000f,
		1.000000f, 1.000000f
	),
	float2x2(
		2.000000f, 2.000000f,
		2.000000f, 2.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float2x2_increment_prefix,
	float2x2(
		2.000000f, 2.000000f,
		2.000000f, 2.000000f
	),
	float2x2(
		3.000000f, 3.000000f,
		3.000000f, 3.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float2x2_increment_prefix,
	float2x2(
		3.000000f, 3.000000f,
		3.000000f, 3.000000f
	),
	float2x2(
		4.000000f, 4.000000f,
		4.000000f, 4.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float2x2_increment_prefix,
	float2x2(
		4.000000f, 4.000000f,
		4.000000f, 4.000000f
	),
	float2x2(
		5.000000f, 5.000000f,
		5.000000f, 5.000000f
	)
);

TEMPER_PARAMETRIC( Test_float2x2_increment_postfix, TEMPER_FLAG_SHOULD_RUN, const float2x2& x, const float2x2& expectedAnswer )
{
	// make local copy of x and use that because we cant do increment or decrement operations on a const reference
	// and MSVC throws warnings if we just make the parameter a non-const reference
	float2x2 xlocal = (float2x2) x;
	float2x2 actualAnswer = xlocal++;
	TEMPER_CHECK_TRUE( actualAnswer == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float2x2_increment_postfix,
	float2x2(
		1.000000f, 1.000000f,
		1.000000f, 1.000000f
	),
	float2x2(
		2.000000f, 2.000000f,
		2.000000f, 2.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float2x2_increment_postfix,
	float2x2(
		2.000000f, 2.000000f,
		2.000000f, 2.000000f
	),
	float2x2(
		3.000000f, 3.000000f,
		3.000000f, 3.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float2x2_increment_postfix,
	float2x2(
		3.000000f, 3.000000f,
		3.000000f, 3.000000f
	),
	float2x2(
		4.000000f, 4.000000f,
		4.000000f, 4.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float2x2_increment_postfix,
	float2x2(
		4.000000f, 4.000000f,
		4.000000f, 4.000000f
	),
	float2x2(
		5.000000f, 5.000000f,
		5.000000f, 5.000000f
	)
);

TEMPER_PARAMETRIC( Test_float2x2_decrement_prefix, TEMPER_FLAG_SHOULD_RUN, const float2x2& x, const float2x2& expectedAnswer )
{
	// make local copy of x and use that because we cant do increment or decrement operations on a const reference
	// and MSVC throws warnings if we just make the parameter a non-const reference
	float2x2 xlocal = (float2x2) x;
	float2x2 actualAnswer = --xlocal;
	TEMPER_CHECK_TRUE( actualAnswer == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float2x2_decrement_prefix,
	float2x2(
		1.000000f, 1.000000f,
		1.000000f, 1.000000f
	),
	float2x2(
		0.000000f, 0.000000f,
		0.000000f, 0.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float2x2_decrement_prefix,
	float2x2(
		2.000000f, 2.000000f,
		2.000000f, 2.000000f
	),
	float2x2(
		1.000000f, 1.000000f,
		1.000000f, 1.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float2x2_decrement_prefix,
	float2x2(
		3.000000f, 3.000000f,
		3.000000f, 3.000000f
	),
	float2x2(
		2.000000f, 2.000000f,
		2.000000f, 2.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float2x2_decrement_prefix,
	float2x2(
		4.000000f, 4.000000f,
		4.000000f, 4.000000f
	),
	float2x2(
		3.000000f, 3.000000f,
		3.000000f, 3.000000f
	)
);

TEMPER_PARAMETRIC( Test_float2x2_decrement_postfix, TEMPER_FLAG_SHOULD_RUN, const float2x2& x, const float2x2& expectedAnswer )
{
	// make local copy of x and use that because we cant do increment or decrement operations on a const reference
	// and MSVC throws warnings if we just make the parameter a non-const reference
	float2x2 xlocal = (float2x2) x;
	float2x2 actualAnswer = xlocal--;
	TEMPER_CHECK_TRUE( actualAnswer == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float2x2_decrement_postfix,
	float2x2(
		1.000000f, 1.000000f,
		1.000000f, 1.000000f
	),
	float2x2(
		0.000000f, 0.000000f,
		0.000000f, 0.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float2x2_decrement_postfix,
	float2x2(
		2.000000f, 2.000000f,
		2.000000f, 2.000000f
	),
	float2x2(
		1.000000f, 1.000000f,
		1.000000f, 1.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float2x2_decrement_postfix,
	float2x2(
		3.000000f, 3.000000f,
		3.000000f, 3.000000f
	),
	float2x2(
		2.000000f, 2.000000f,
		2.000000f, 2.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float2x2_decrement_postfix,
	float2x2(
		4.000000f, 4.000000f,
		4.000000f, 4.000000f
	),
	float2x2(
		3.000000f, 3.000000f,
		3.000000f, 3.000000f
	)
);

#if defined( __GNUC__ ) || defined( __clang__ )
#pragma GCC diagnostic pop
#endif
TEMPER_PARAMETRIC( Test_float2x2_min, TEMPER_FLAG_SHOULD_RUN, const float2x2& lhs, const float2x2& rhs, const float2x2& expectedAnswer )
{
	float2x2 actualResult = min( lhs, rhs );
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float2x2_min,
	float2x2(
		0.000000f, 0.000000f,
		0.000000f, 0.000000f
	),
	float2x2(
		1.000000f, 1.000000f,
		1.000000f, 1.000000f
	),
	float2x2(
		0.000000f, 0.000000f,
		0.000000f, 0.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float2x2_min,
	float2x2(
		1.000000f, 1.000000f,
		1.000000f, 1.000000f
	),
	float2x2(
		2.000000f, 2.000000f,
		2.000000f, 2.000000f
	),
	float2x2(
		1.000000f, 1.000000f,
		1.000000f, 1.000000f
	)
);

TEMPER_PARAMETRIC( Test_float2x2_max, TEMPER_FLAG_SHOULD_RUN, const float2x2& lhs, const float2x2& rhs, const float2x2& expectedAnswer )
{
	float2x2 actualResult = max( lhs, rhs );
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float2x2_max,
	float2x2(
		1.000000f, 1.000000f,
		1.000000f, 1.000000f
	),
	float2x2(
		0.000000f, 0.000000f,
		0.000000f, 0.000000f
	),
	float2x2(
		1.000000f, 1.000000f,
		1.000000f, 1.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float2x2_max,
	float2x2(
		2.000000f, 2.000000f,
		2.000000f, 2.000000f
	),
	float2x2(
		1.000000f, 1.000000f,
		1.000000f, 1.000000f
	),
	float2x2(
		2.000000f, 2.000000f,
		2.000000f, 2.000000f
	)
);

TEMPER_PARAMETRIC( Test_float2x2_saturate, TEMPER_FLAG_SHOULD_RUN, const float2x2& x, const float2x2& expectedAnswer )
{
	float2x2 actualResult = saturate( x );
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float2x2_saturate,
	float2x2(
		0.000000f, 0.000000f,
		0.000000f, 0.000000f
	),
	float2x2(
		0.000000f, 0.000000f,
		0.000000f, 0.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float2x2_saturate,
	float2x2(
		1.000000f, 1.000000f,
		1.000000f, 1.000000f
	),
	float2x2(
		1.000000f, 1.000000f,
		1.000000f, 1.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float2x2_saturate,
	float2x2(
		2.000000f, 2.000000f,
		2.000000f, 2.000000f
	),
	float2x2(
		1.000000f, 1.000000f,
		1.000000f, 1.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float2x2_saturate,
	float2x2(
		3.000000f, 3.000000f,
		3.000000f, 3.000000f
	),
	float2x2(
		1.000000f, 1.000000f,
		1.000000f, 1.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float2x2_saturate,
	float2x2(
		10.000000f, 10.000000f,
		10.000000f, 10.000000f
	),
	float2x2(
		1.000000f, 1.000000f,
		1.000000f, 1.000000f
	)
);

TEMPER_PARAMETRIC( Test_float2x2_sign, TEMPER_FLAG_SHOULD_RUN, const float2x2& x, const int2x2& expectedAnswer )
{
	int2x2 actualResult = sign( x );
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float2x2_sign,
	float2x2(
		0.000000f, 0.000000f,
		0.000000f, 0.000000f
	),
	int2x2(
		0, 0,
		0, 0
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float2x2_sign,
	float2x2(
		1.000000f, 1.000000f,
		1.000000f, 1.000000f
	),
	int2x2(
		1, 1,
		1, 1
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float2x2_sign,
	float2x2(
		2.000000f, 2.000000f,
		2.000000f, 2.000000f
	),
	int2x2(
		1, 1,
		1, 1
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float2x2_sign,
	float2x2(
		3.000000f, 3.000000f,
		3.000000f, 3.000000f
	),
	int2x2(
		1, 1,
		1, 1
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float2x2_sign,
	float2x2(
		-1.000000f, -1.000000f,
		-1.000000f, -1.000000f
	),
	int2x2(
		-1, -1,
		-1, -1
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float2x2_sign,
	float2x2(
		-2.000000f, -2.000000f,
		-2.000000f, -2.000000f
	),
	int2x2(
		-1, -1,
		-1, -1
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float2x2_sign,
	float2x2(
		-3.000000f, -3.000000f,
		-3.000000f, -3.000000f
	),
	int2x2(
		-1, -1,
		-1, -1
	)
);

TEMPER_PARAMETRIC( Test_float2x2_lerp, TEMPER_FLAG_SHOULD_RUN, const float2x2& lhs, const float2x2& rhs, const float t, const float2x2& expectedAnswer )
{
	float2x2 actualResult = lerp( lhs, rhs, t );
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float2x2_lerp,
	float2x2(
		0.000000f, 0.000000f,
		0.000000f, 0.000000f
	),
	float2x2(
		1.000000f, 1.000000f,
		1.000000f, 1.000000f
	),
	0.500000f,
	float2x2(
		0.500000f, 0.500000f,
		0.500000f, 0.500000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float2x2_lerp,
	float2x2(
		1.000000f, 1.000000f,
		1.000000f, 1.000000f
	),
	float2x2(
		3.000000f, 3.000000f,
		3.000000f, 3.000000f
	),
	0.500000f,
	float2x2(
		2.000000f, 2.000000f,
		2.000000f, 2.000000f
	)
);

TEMPER_PARAMETRIC( Test_float2x2_identity, TEMPER_FLAG_SHOULD_RUN, const float2x2& matrix, const bool expectedAnswer )
{
	float2x2 identityMat;
	identity( identityMat );
	bool isMatrixIdentity = ( identityMat == matrix );
	TEMPER_CHECK_TRUE( isMatrixIdentity == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float2x2_identity,
	float2x2(
		1.000000f, 0.000000f,
		0.000000f, 1.000000f
	),
	true
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float2x2_identity,
	float2x2(
		1.000000f, 1.000000f,
		0.000000f, 1.000000f
	),
	false
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float2x2_identity,
	float2x2(
		1.000000f, 0.000000f,
		1.000000f, 1.000000f
	),
	false
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float2x2_identity,
	float2x2(
		1.000000f, 1.000000f,
		1.000000f, 1.000000f
	),
	false
);

TEMPER_PARAMETRIC( Test_float2x2_transpose, TEMPER_FLAG_SHOULD_RUN, const float2x2& matrix, const float2x2& expectedAnswer )
{
	float2x2 actualResult = transpose( matrix );
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float2x2_transpose,
	float2x2(
		1.000000f, 0.000000f,
		0.000000f, 1.000000f
	),
	float2x2(
		1.000000f, 0.000000f,
		0.000000f, 1.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float2x2_transpose,
	float2x2(
		0.000000f, 1.000000f,
		4.000000f, 5.000000f
	),
	float2x2(
		0.000000f, 4.000000f,
		1.000000f, 5.000000f
	)
);

TEMPER_PARAMETRIC( Test_float2x2_mulm, TEMPER_FLAG_SHOULD_RUN, const float2x2& lhs, const float2x2& rhs, const float2x2& expectedAnswer )
{
	float2x2 actualResult = mul( lhs, rhs );
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float2x2_mulm,
	float2x2(
		2.000000f, 2.000000f,
		2.000000f, 2.000000f
	),
	float2x2(
		4.000000f, 4.000000f,
		4.000000f, 4.000000f
	),
	float2x2(
		16.000000f, 16.000000f,
		16.000000f, 16.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float2x2_mulm,
	float2x2(
		2.000000f, 2.000000f,
		2.000000f, 2.000000f
	),
	float2x2(
		1.000000f, 0.000000f,
		0.000000f, 1.000000f
	),
	float2x2(
		2.000000f, 2.000000f,
		2.000000f, 2.000000f
	)
);

TEMPER_PARAMETRIC( Test_float2x2_mulv, TEMPER_FLAG_SHOULD_RUN, const float2& vec, const float2x2& mat, const float2& expectedAnswer )
{
	float2 actualResult = mul( vec, mat );
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float2x2_mulv,
	float2( 0.000000f, 0.000000f ),
	float2x2(
		1.000000f, 0.000000f,
		0.000000f, 1.000000f
	),
	float2(
		0.000000f, 0.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float2x2_mulv,
	float2( 2.000000f, 1.000000f ),
	float2x2(
		1.000000f, 2.000000f,
		5.000000f, 6.000000f
	),
	float2(
		7.000000f, 10.000000f
	)
);

TEMPER_PARAMETRIC( Test_float2x2_determinant, TEMPER_FLAG_SHOULD_RUN, const float2x2& matrix, const float expectedAnswer )
{
	float actualResult = determinant( matrix );
	TEMPER_CHECK_TRUE( floateq( actualResult, expectedAnswer ) );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float2x2_determinant,
	float2x2(
		6.000000f, 2.000000f,
		2.000000f, 7.000000f
	),
	38.000000f
);

TEMPER_PARAMETRIC( Test_float2x2_inverse, TEMPER_FLAG_SHOULD_RUN, const float2x2& mat, const float2x2& expectedAnswer )
{
	float2x2 inversed = inverse( mat );
	TEMPER_CHECK_TRUE( inversed == expectedAnswer );

	// test inversed matrix multiplied by the original equals identity
	float2x2 identityMat;
	identity( identityMat );

	float2x2 matMultipliedByItsInverse = mul( mat, inversed );
	TEMPER_CHECK_TRUE( matMultipliedByItsInverse == identityMat );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_float2x2_inverse,
	float2x2(
		6.000000f, 2.000000f,
		2.000000f, 7.000000f
	),
	float2x2(
		0.184211f, -0.052632f,
		-0.052632f, 0.157895f
	)
);


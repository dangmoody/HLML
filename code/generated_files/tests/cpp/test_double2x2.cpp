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

TEMPER_PARAMETRIC( Test_double2x2_less_than, TEMPER_FLAG_SHOULD_RUN, const double2x2& lhs, const double2x2& rhs, const bool2x2& expectedAnswer )
{
	bool2x2 actualResult = lhs < rhs;
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x2_less_than,
	double2x2(
		0.000000f, 0.000000f,
		0.000000f, 0.000000f
	),
	double2x2(
		0.000000f, 0.000000f,
		0.000000f, 0.000000f
	),
	bool2x2(
		false, false,
		false, false
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x2_less_than,
	double2x2(
		0.000000f, 0.000000f,
		0.000000f, 0.000000f
	),
	double2x2(
		1.000000f, 1.000000f,
		1.000000f, 1.000000f
	),
	bool2x2(
		true, true,
		true, true
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x2_less_than,
	double2x2(
		1.000000f, 1.000000f,
		1.000000f, 1.000000f
	),
	double2x2(
		1.000000f, 1.000000f,
		1.000000f, 1.000000f
	),
	bool2x2(
		false, false,
		false, false
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x2_less_than,
	double2x2(
		1.000000f, 1.000000f,
		1.000000f, 1.000000f
	),
	double2x2(
		0.000000f, 0.000000f,
		0.000000f, 0.000000f
	),
	bool2x2(
		false, false,
		false, false
	)
);

TEMPER_PARAMETRIC( Test_double2x2_less_than_equal, TEMPER_FLAG_SHOULD_RUN, const double2x2& lhs, const double2x2& rhs, const bool2x2& expectedAnswer )
{
	bool2x2 actualResult = lhs <= rhs;
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x2_less_than_equal,
	double2x2(
		0.000000f, 0.000000f,
		0.000000f, 0.000000f
	),
	double2x2(
		0.000000f, 0.000000f,
		0.000000f, 0.000000f
	),
	bool2x2(
		true, true,
		true, true
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x2_less_than_equal,
	double2x2(
		0.000000f, 0.000000f,
		0.000000f, 0.000000f
	),
	double2x2(
		1.000000f, 1.000000f,
		1.000000f, 1.000000f
	),
	bool2x2(
		true, true,
		true, true
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x2_less_than_equal,
	double2x2(
		1.000000f, 1.000000f,
		1.000000f, 1.000000f
	),
	double2x2(
		1.000000f, 1.000000f,
		1.000000f, 1.000000f
	),
	bool2x2(
		true, true,
		true, true
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x2_less_than_equal,
	double2x2(
		1.000000f, 1.000000f,
		1.000000f, 1.000000f
	),
	double2x2(
		0.000000f, 0.000000f,
		0.000000f, 0.000000f
	),
	bool2x2(
		false, false,
		false, false
	)
);

TEMPER_PARAMETRIC( Test_double2x2_greater_than, TEMPER_FLAG_SHOULD_RUN, const double2x2& lhs, const double2x2& rhs, const bool2x2& expectedAnswer )
{
	bool2x2 actualResult = lhs > rhs;
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x2_greater_than,
	double2x2(
		0.000000f, 0.000000f,
		0.000000f, 0.000000f
	),
	double2x2(
		0.000000f, 0.000000f,
		0.000000f, 0.000000f
	),
	bool2x2(
		false, false,
		false, false
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x2_greater_than,
	double2x2(
		0.000000f, 0.000000f,
		0.000000f, 0.000000f
	),
	double2x2(
		1.000000f, 1.000000f,
		1.000000f, 1.000000f
	),
	bool2x2(
		false, false,
		false, false
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x2_greater_than,
	double2x2(
		1.000000f, 1.000000f,
		1.000000f, 1.000000f
	),
	double2x2(
		1.000000f, 1.000000f,
		1.000000f, 1.000000f
	),
	bool2x2(
		false, false,
		false, false
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x2_greater_than,
	double2x2(
		1.000000f, 1.000000f,
		1.000000f, 1.000000f
	),
	double2x2(
		0.000000f, 0.000000f,
		0.000000f, 0.000000f
	),
	bool2x2(
		true, true,
		true, true
	)
);

TEMPER_PARAMETRIC( Test_double2x2_greater_than_equal, TEMPER_FLAG_SHOULD_RUN, const double2x2& lhs, const double2x2& rhs, const bool2x2& expectedAnswer )
{
	bool2x2 actualResult = lhs >= rhs;
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x2_greater_than_equal,
	double2x2(
		0.000000f, 0.000000f,
		0.000000f, 0.000000f
	),
	double2x2(
		0.000000f, 0.000000f,
		0.000000f, 0.000000f
	),
	bool2x2(
		true, true,
		true, true
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x2_greater_than_equal,
	double2x2(
		0.000000f, 0.000000f,
		0.000000f, 0.000000f
	),
	double2x2(
		1.000000f, 1.000000f,
		1.000000f, 1.000000f
	),
	bool2x2(
		false, false,
		false, false
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x2_greater_than_equal,
	double2x2(
		1.000000f, 1.000000f,
		1.000000f, 1.000000f
	),
	double2x2(
		1.000000f, 1.000000f,
		1.000000f, 1.000000f
	),
	bool2x2(
		true, true,
		true, true
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x2_greater_than_equal,
	double2x2(
		1.000000f, 1.000000f,
		1.000000f, 1.000000f
	),
	double2x2(
		0.000000f, 0.000000f,
		0.000000f, 0.000000f
	),
	bool2x2(
		true, true,
		true, true
	)
);

TEMPER_PARAMETRIC( Test_double2x2_cadds, TEMPER_FLAG_SHOULD_RUN, const double2x2& lhs, const double& rhs, const double2x2& expectedAnswer )
{
	double2x2 actualResult = lhs + rhs;
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x2_cadds,
	double2x2(
		1.000000f, 1.000000f,
		1.000000f, 1.000000f
	),
	1.000000f,
	double2x2(
		2.000000f, 2.000000f,
		2.000000f, 2.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x2_cadds,
	double2x2(
		2.000000f, 2.000000f,
		2.000000f, 2.000000f
	),
	2.000000f,
	double2x2(
		4.000000f, 4.000000f,
		4.000000f, 4.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x2_cadds,
	double2x2(
		4.000000f, 4.000000f,
		4.000000f, 4.000000f
	),
	2.000000f,
	double2x2(
		6.000000f, 6.000000f,
		6.000000f, 6.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x2_cadds,
	double2x2(
		8.000000f, 8.000000f,
		8.000000f, 8.000000f
	),
	4.000000f,
	double2x2(
		12.000000f, 12.000000f,
		12.000000f, 12.000000f
	)
);

TEMPER_PARAMETRIC( Test_double2x2_csubs, TEMPER_FLAG_SHOULD_RUN, const double2x2& lhs, const double& rhs, const double2x2& expectedAnswer )
{
	double2x2 actualResult = lhs - rhs;
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x2_csubs,
	double2x2(
		1.000000f, 1.000000f,
		1.000000f, 1.000000f
	),
	1.000000f,
	double2x2(
		0.000000f, 0.000000f,
		0.000000f, 0.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x2_csubs,
	double2x2(
		2.000000f, 2.000000f,
		2.000000f, 2.000000f
	),
	2.000000f,
	double2x2(
		0.000000f, 0.000000f,
		0.000000f, 0.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x2_csubs,
	double2x2(
		4.000000f, 4.000000f,
		4.000000f, 4.000000f
	),
	2.000000f,
	double2x2(
		2.000000f, 2.000000f,
		2.000000f, 2.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x2_csubs,
	double2x2(
		8.000000f, 8.000000f,
		8.000000f, 8.000000f
	),
	4.000000f,
	double2x2(
		4.000000f, 4.000000f,
		4.000000f, 4.000000f
	)
);

TEMPER_PARAMETRIC( Test_double2x2_cmuls, TEMPER_FLAG_SHOULD_RUN, const double2x2& lhs, const double& rhs, const double2x2& expectedAnswer )
{
	double2x2 actualResult = lhs * rhs;
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x2_cmuls,
	double2x2(
		1.000000f, 1.000000f,
		1.000000f, 1.000000f
	),
	1.000000f,
	double2x2(
		1.000000f, 1.000000f,
		1.000000f, 1.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x2_cmuls,
	double2x2(
		2.000000f, 2.000000f,
		2.000000f, 2.000000f
	),
	2.000000f,
	double2x2(
		4.000000f, 4.000000f,
		4.000000f, 4.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x2_cmuls,
	double2x2(
		4.000000f, 4.000000f,
		4.000000f, 4.000000f
	),
	2.000000f,
	double2x2(
		8.000000f, 8.000000f,
		8.000000f, 8.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x2_cmuls,
	double2x2(
		8.000000f, 8.000000f,
		8.000000f, 8.000000f
	),
	4.000000f,
	double2x2(
		32.000000f, 32.000000f,
		32.000000f, 32.000000f
	)
);

TEMPER_PARAMETRIC( Test_double2x2_cdivs, TEMPER_FLAG_SHOULD_RUN, const double2x2& lhs, const double& rhs, const double2x2& expectedAnswer )
{
	double2x2 actualResult = lhs / rhs;
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x2_cdivs,
	double2x2(
		1.000000f, 1.000000f,
		1.000000f, 1.000000f
	),
	1.000000f,
	double2x2(
		1.000000f, 1.000000f,
		1.000000f, 1.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x2_cdivs,
	double2x2(
		2.000000f, 2.000000f,
		2.000000f, 2.000000f
	),
	2.000000f,
	double2x2(
		1.000000f, 1.000000f,
		1.000000f, 1.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x2_cdivs,
	double2x2(
		4.000000f, 4.000000f,
		4.000000f, 4.000000f
	),
	2.000000f,
	double2x2(
		2.000000f, 2.000000f,
		2.000000f, 2.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x2_cdivs,
	double2x2(
		8.000000f, 8.000000f,
		8.000000f, 8.000000f
	),
	4.000000f,
	double2x2(
		2.000000f, 2.000000f,
		2.000000f, 2.000000f
	)
);

TEMPER_PARAMETRIC( Test_double2x2_caddm, TEMPER_FLAG_SHOULD_RUN, const double2x2& lhs, const double2x2& rhs, const double2x2& expectedAnswer )
{
	double2x2 actualResult = lhs + rhs;
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x2_caddm,
	double2x2(
		1.000000f, 1.000000f,
		1.000000f, 1.000000f
	),
	double2x2(
		1.000000f, 1.000000f,
		1.000000f, 1.000000f
	),
	double2x2(
		2.000000f, 2.000000f,
		2.000000f, 2.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x2_caddm,
	double2x2(
		2.000000f, 2.000000f,
		2.000000f, 2.000000f
	),
	double2x2(
		2.000000f, 2.000000f,
		2.000000f, 2.000000f
	),
	double2x2(
		4.000000f, 4.000000f,
		4.000000f, 4.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x2_caddm,
	double2x2(
		4.000000f, 4.000000f,
		4.000000f, 4.000000f
	),
	double2x2(
		2.000000f, 2.000000f,
		2.000000f, 2.000000f
	),
	double2x2(
		6.000000f, 6.000000f,
		6.000000f, 6.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x2_caddm,
	double2x2(
		8.000000f, 8.000000f,
		8.000000f, 8.000000f
	),
	double2x2(
		4.000000f, 4.000000f,
		4.000000f, 4.000000f
	),
	double2x2(
		12.000000f, 12.000000f,
		12.000000f, 12.000000f
	)
);

TEMPER_PARAMETRIC( Test_double2x2_csubm, TEMPER_FLAG_SHOULD_RUN, const double2x2& lhs, const double2x2& rhs, const double2x2& expectedAnswer )
{
	double2x2 actualResult = lhs - rhs;
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x2_csubm,
	double2x2(
		1.000000f, 1.000000f,
		1.000000f, 1.000000f
	),
	double2x2(
		1.000000f, 1.000000f,
		1.000000f, 1.000000f
	),
	double2x2(
		0.000000f, 0.000000f,
		0.000000f, 0.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x2_csubm,
	double2x2(
		2.000000f, 2.000000f,
		2.000000f, 2.000000f
	),
	double2x2(
		2.000000f, 2.000000f,
		2.000000f, 2.000000f
	),
	double2x2(
		0.000000f, 0.000000f,
		0.000000f, 0.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x2_csubm,
	double2x2(
		4.000000f, 4.000000f,
		4.000000f, 4.000000f
	),
	double2x2(
		2.000000f, 2.000000f,
		2.000000f, 2.000000f
	),
	double2x2(
		2.000000f, 2.000000f,
		2.000000f, 2.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x2_csubm,
	double2x2(
		8.000000f, 8.000000f,
		8.000000f, 8.000000f
	),
	double2x2(
		4.000000f, 4.000000f,
		4.000000f, 4.000000f
	),
	double2x2(
		4.000000f, 4.000000f,
		4.000000f, 4.000000f
	)
);

TEMPER_PARAMETRIC( Test_double2x2_cmulm, TEMPER_FLAG_SHOULD_RUN, const double2x2& lhs, const double2x2& rhs, const double2x2& expectedAnswer )
{
	double2x2 actualResult = lhs * rhs;
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x2_cmulm,
	double2x2(
		1.000000f, 1.000000f,
		1.000000f, 1.000000f
	),
	double2x2(
		1.000000f, 1.000000f,
		1.000000f, 1.000000f
	),
	double2x2(
		1.000000f, 1.000000f,
		1.000000f, 1.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x2_cmulm,
	double2x2(
		2.000000f, 2.000000f,
		2.000000f, 2.000000f
	),
	double2x2(
		2.000000f, 2.000000f,
		2.000000f, 2.000000f
	),
	double2x2(
		4.000000f, 4.000000f,
		4.000000f, 4.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x2_cmulm,
	double2x2(
		4.000000f, 4.000000f,
		4.000000f, 4.000000f
	),
	double2x2(
		2.000000f, 2.000000f,
		2.000000f, 2.000000f
	),
	double2x2(
		8.000000f, 8.000000f,
		8.000000f, 8.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x2_cmulm,
	double2x2(
		8.000000f, 8.000000f,
		8.000000f, 8.000000f
	),
	double2x2(
		4.000000f, 4.000000f,
		4.000000f, 4.000000f
	),
	double2x2(
		32.000000f, 32.000000f,
		32.000000f, 32.000000f
	)
);

TEMPER_PARAMETRIC( Test_double2x2_cdivm, TEMPER_FLAG_SHOULD_RUN, const double2x2& lhs, const double2x2& rhs, const double2x2& expectedAnswer )
{
	double2x2 actualResult = lhs / rhs;
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x2_cdivm,
	double2x2(
		1.000000f, 1.000000f,
		1.000000f, 1.000000f
	),
	double2x2(
		1.000000f, 1.000000f,
		1.000000f, 1.000000f
	),
	double2x2(
		1.000000f, 1.000000f,
		1.000000f, 1.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x2_cdivm,
	double2x2(
		2.000000f, 2.000000f,
		2.000000f, 2.000000f
	),
	double2x2(
		2.000000f, 2.000000f,
		2.000000f, 2.000000f
	),
	double2x2(
		1.000000f, 1.000000f,
		1.000000f, 1.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x2_cdivm,
	double2x2(
		4.000000f, 4.000000f,
		4.000000f, 4.000000f
	),
	double2x2(
		2.000000f, 2.000000f,
		2.000000f, 2.000000f
	),
	double2x2(
		2.000000f, 2.000000f,
		2.000000f, 2.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x2_cdivm,
	double2x2(
		8.000000f, 8.000000f,
		8.000000f, 8.000000f
	),
	double2x2(
		4.000000f, 4.000000f,
		4.000000f, 4.000000f
	),
	double2x2(
		2.000000f, 2.000000f,
		2.000000f, 2.000000f
	)
);

#if defined( __GNUC__ ) || defined( __clang__ )
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wcast-qual"
#endif

TEMPER_PARAMETRIC( Test_double2x2_increment_prefix, TEMPER_FLAG_SHOULD_RUN, const double2x2& x, const double2x2& expectedAnswer )
{
	// make local copy of x and use that because we cant do increment or decrement operations on a const reference
	// and MSVC throws warnings if we just make the parameter a non-const reference
	double2x2 xlocal = (double2x2) x;
	double2x2 actualAnswer = ++xlocal;
	TEMPER_CHECK_TRUE( actualAnswer == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x2_increment_prefix,
	double2x2(
		1.000000f, 1.000000f,
		1.000000f, 1.000000f
	),
	double2x2(
		2.000000f, 2.000000f,
		2.000000f, 2.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x2_increment_prefix,
	double2x2(
		2.000000f, 2.000000f,
		2.000000f, 2.000000f
	),
	double2x2(
		3.000000f, 3.000000f,
		3.000000f, 3.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x2_increment_prefix,
	double2x2(
		3.000000f, 3.000000f,
		3.000000f, 3.000000f
	),
	double2x2(
		4.000000f, 4.000000f,
		4.000000f, 4.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x2_increment_prefix,
	double2x2(
		4.000000f, 4.000000f,
		4.000000f, 4.000000f
	),
	double2x2(
		5.000000f, 5.000000f,
		5.000000f, 5.000000f
	)
);

TEMPER_PARAMETRIC( Test_double2x2_increment_postfix, TEMPER_FLAG_SHOULD_RUN, const double2x2& x, const double2x2& expectedAnswer )
{
	// make local copy of x and use that because we cant do increment or decrement operations on a const reference
	// and MSVC throws warnings if we just make the parameter a non-const reference
	double2x2 xlocal = (double2x2) x;
	double2x2 actualAnswer = xlocal++;
	TEMPER_CHECK_TRUE( actualAnswer == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x2_increment_postfix,
	double2x2(
		1.000000f, 1.000000f,
		1.000000f, 1.000000f
	),
	double2x2(
		2.000000f, 2.000000f,
		2.000000f, 2.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x2_increment_postfix,
	double2x2(
		2.000000f, 2.000000f,
		2.000000f, 2.000000f
	),
	double2x2(
		3.000000f, 3.000000f,
		3.000000f, 3.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x2_increment_postfix,
	double2x2(
		3.000000f, 3.000000f,
		3.000000f, 3.000000f
	),
	double2x2(
		4.000000f, 4.000000f,
		4.000000f, 4.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x2_increment_postfix,
	double2x2(
		4.000000f, 4.000000f,
		4.000000f, 4.000000f
	),
	double2x2(
		5.000000f, 5.000000f,
		5.000000f, 5.000000f
	)
);

TEMPER_PARAMETRIC( Test_double2x2_decrement_prefix, TEMPER_FLAG_SHOULD_RUN, const double2x2& x, const double2x2& expectedAnswer )
{
	// make local copy of x and use that because we cant do increment or decrement operations on a const reference
	// and MSVC throws warnings if we just make the parameter a non-const reference
	double2x2 xlocal = (double2x2) x;
	double2x2 actualAnswer = --xlocal;
	TEMPER_CHECK_TRUE( actualAnswer == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x2_decrement_prefix,
	double2x2(
		1.000000f, 1.000000f,
		1.000000f, 1.000000f
	),
	double2x2(
		0.000000f, 0.000000f,
		0.000000f, 0.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x2_decrement_prefix,
	double2x2(
		2.000000f, 2.000000f,
		2.000000f, 2.000000f
	),
	double2x2(
		1.000000f, 1.000000f,
		1.000000f, 1.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x2_decrement_prefix,
	double2x2(
		3.000000f, 3.000000f,
		3.000000f, 3.000000f
	),
	double2x2(
		2.000000f, 2.000000f,
		2.000000f, 2.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x2_decrement_prefix,
	double2x2(
		4.000000f, 4.000000f,
		4.000000f, 4.000000f
	),
	double2x2(
		3.000000f, 3.000000f,
		3.000000f, 3.000000f
	)
);

TEMPER_PARAMETRIC( Test_double2x2_decrement_postfix, TEMPER_FLAG_SHOULD_RUN, const double2x2& x, const double2x2& expectedAnswer )
{
	// make local copy of x and use that because we cant do increment or decrement operations on a const reference
	// and MSVC throws warnings if we just make the parameter a non-const reference
	double2x2 xlocal = (double2x2) x;
	double2x2 actualAnswer = xlocal--;
	TEMPER_CHECK_TRUE( actualAnswer == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x2_decrement_postfix,
	double2x2(
		1.000000f, 1.000000f,
		1.000000f, 1.000000f
	),
	double2x2(
		0.000000f, 0.000000f,
		0.000000f, 0.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x2_decrement_postfix,
	double2x2(
		2.000000f, 2.000000f,
		2.000000f, 2.000000f
	),
	double2x2(
		1.000000f, 1.000000f,
		1.000000f, 1.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x2_decrement_postfix,
	double2x2(
		3.000000f, 3.000000f,
		3.000000f, 3.000000f
	),
	double2x2(
		2.000000f, 2.000000f,
		2.000000f, 2.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x2_decrement_postfix,
	double2x2(
		4.000000f, 4.000000f,
		4.000000f, 4.000000f
	),
	double2x2(
		3.000000f, 3.000000f,
		3.000000f, 3.000000f
	)
);

#if defined( __GNUC__ ) || defined( __clang__ )
#pragma GCC diagnostic pop
#endif
#if defined( __GNUC__ ) || defined( __clang__ )
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wcast-qual"
#endif
TEMPER_PARAMETRIC( Test_double2x2_negate_prefix, TEMPER_FLAG_SHOULD_RUN, const double2x2& x, const double2x2& expectedAnswer )
{
	// make local copy of x and use that because we cant do increment or decrement operations on a const reference
	// and MSVC throws warnings if we just make the parameter a non-const reference
	double2x2 xlocal = (double2x2) x;
	double2x2 actualAnswer = -xlocal;
	TEMPER_CHECK_TRUE( actualAnswer == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x2_negate_prefix,
	double2x2(
		0.000000f, 0.000000f,
		0.000000f, 0.000000f
	),
	double2x2(
		-0.000000f, -0.000000f,
		-0.000000f, -0.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x2_negate_prefix,
	double2x2(
		1.000000f, 1.000000f,
		1.000000f, 1.000000f
	),
	double2x2(
		-1.000000f, -1.000000f,
		-1.000000f, -1.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x2_negate_prefix,
	double2x2(
		2.000000f, 2.000000f,
		2.000000f, 2.000000f
	),
	double2x2(
		-2.000000f, -2.000000f,
		-2.000000f, -2.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x2_negate_prefix,
	double2x2(
		3.000000f, 3.000000f,
		3.000000f, 3.000000f
	),
	double2x2(
		-3.000000f, -3.000000f,
		-3.000000f, -3.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x2_negate_prefix,
	double2x2(
		10.000000f, 10.000000f,
		10.000000f, 10.000000f
	),
	double2x2(
		-10.000000f, -10.000000f,
		-10.000000f, -10.000000f
	)
);

#if defined( __GNUC__ ) || defined( __clang__ )
#pragma GCC diagnostic pop
#endif

TEMPER_PARAMETRIC( Test_double2x2_min, TEMPER_FLAG_SHOULD_RUN, const double2x2& lhs, const double2x2& rhs, const double2x2& expectedAnswer )
{
	double2x2 actualResult = min( lhs, rhs );
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x2_min,
	double2x2(
		0.000000f, 0.000000f,
		0.000000f, 0.000000f
	),
	double2x2(
		1.000000f, 1.000000f,
		1.000000f, 1.000000f
	),
	double2x2(
		0.000000f, 0.000000f,
		0.000000f, 0.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x2_min,
	double2x2(
		1.000000f, 1.000000f,
		1.000000f, 1.000000f
	),
	double2x2(
		2.000000f, 2.000000f,
		2.000000f, 2.000000f
	),
	double2x2(
		1.000000f, 1.000000f,
		1.000000f, 1.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x2_min,
	double2x2(
		420.000000f, 420.000000f,
		420.000000f, 420.000000f
	),
	double2x2(
		69.000000f, 69.000000f,
		69.000000f, 69.000000f
	),
	double2x2(
		69.000000f, 69.000000f,
		69.000000f, 69.000000f
	)
);

TEMPER_PARAMETRIC( Test_double2x2_max, TEMPER_FLAG_SHOULD_RUN, const double2x2& lhs, const double2x2& rhs, const double2x2& expectedAnswer )
{
	double2x2 actualResult = max( lhs, rhs );
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x2_max,
	double2x2(
		0.000000f, 0.000000f,
		0.000000f, 0.000000f
	),
	double2x2(
		1.000000f, 1.000000f,
		1.000000f, 1.000000f
	),
	double2x2(
		1.000000f, 1.000000f,
		1.000000f, 1.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x2_max,
	double2x2(
		1.000000f, 1.000000f,
		1.000000f, 1.000000f
	),
	double2x2(
		2.000000f, 2.000000f,
		2.000000f, 2.000000f
	),
	double2x2(
		2.000000f, 2.000000f,
		2.000000f, 2.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x2_max,
	double2x2(
		69.000000f, 69.000000f,
		69.000000f, 69.000000f
	),
	double2x2(
		420.000000f, 420.000000f,
		420.000000f, 420.000000f
	),
	double2x2(
		420.000000f, 420.000000f,
		420.000000f, 420.000000f
	)
);

TEMPER_PARAMETRIC( Test_double2x2_saturate, TEMPER_FLAG_SHOULD_RUN, const double2x2& x, const double2x2& expectedAnswer )
{
	double2x2 actualResult = saturate( x );
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x2_saturate,
	double2x2(
		0.000000f, 0.000000f,
		0.000000f, 0.000000f
	),
	double2x2(
		0.000000f, 0.000000f,
		0.000000f, 0.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x2_saturate,
	double2x2(
		1.000000f, 1.000000f,
		1.000000f, 1.000000f
	),
	double2x2(
		1.000000f, 1.000000f,
		1.000000f, 1.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x2_saturate,
	double2x2(
		2.000000f, 2.000000f,
		2.000000f, 2.000000f
	),
	double2x2(
		1.000000f, 1.000000f,
		1.000000f, 1.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x2_saturate,
	double2x2(
		3.000000f, 3.000000f,
		3.000000f, 3.000000f
	),
	double2x2(
		1.000000f, 1.000000f,
		1.000000f, 1.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x2_saturate,
	double2x2(
		10.000000f, 10.000000f,
		10.000000f, 10.000000f
	),
	double2x2(
		1.000000f, 1.000000f,
		1.000000f, 1.000000f
	)
);

TEMPER_PARAMETRIC( Test_double2x2_sign, TEMPER_FLAG_SHOULD_RUN, const double2x2& x, const int2x2& expectedAnswer )
{
	int2x2 actualResult = sign( x );
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x2_sign,
	double2x2(
		0.000000f, 0.000000f,
		0.000000f, 0.000000f
	),
	int2x2(
		0, 0,
		0, 0
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x2_sign,
	double2x2(
		1.000000f, 1.000000f,
		1.000000f, 1.000000f
	),
	int2x2(
		1, 1,
		1, 1
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x2_sign,
	double2x2(
		2.000000f, 2.000000f,
		2.000000f, 2.000000f
	),
	int2x2(
		1, 1,
		1, 1
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x2_sign,
	double2x2(
		3.000000f, 3.000000f,
		3.000000f, 3.000000f
	),
	int2x2(
		1, 1,
		1, 1
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x2_sign,
	double2x2(
		-1.000000f, -1.000000f,
		-1.000000f, -1.000000f
	),
	int2x2(
		-1, -1,
		-1, -1
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x2_sign,
	double2x2(
		-2.000000f, -2.000000f,
		-2.000000f, -2.000000f
	),
	int2x2(
		-1, -1,
		-1, -1
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x2_sign,
	double2x2(
		-3.000000f, -3.000000f,
		-3.000000f, -3.000000f
	),
	int2x2(
		-1, -1,
		-1, -1
	)
);

TEMPER_PARAMETRIC( Test_double2x2_lerp, TEMPER_FLAG_SHOULD_RUN, const double2x2& lhs, const double2x2& rhs, const double t, const double2x2& expectedAnswer )
{
	double2x2 actualResult = lerp( lhs, rhs, t );
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x2_lerp,
	double2x2(
		0.000000f, 0.000000f,
		0.000000f, 0.000000f
	),
	double2x2(
		1.000000f, 1.000000f,
		1.000000f, 1.000000f
	),
	0.500000f,
	double2x2(
		0.500000f, 0.500000f,
		0.500000f, 0.500000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x2_lerp,
	double2x2(
		1.000000f, 1.000000f,
		1.000000f, 1.000000f
	),
	double2x2(
		3.000000f, 3.000000f,
		3.000000f, 3.000000f
	),
	0.500000f,
	double2x2(
		2.000000f, 2.000000f,
		2.000000f, 2.000000f
	)
);

TEMPER_PARAMETRIC( Test_double2x2_int2x2, TEMPER_FLAG_SHOULD_RUN, const int2x2& convertFrom, const double2x2& expectedAnswer )
{
	double2x2 actualAnswer = double2x2( convertFrom );

	TEMPER_CHECK_TRUE( doubleeq( expectedAnswer[0][0], actualAnswer[0][0] ) );
	TEMPER_CHECK_TRUE( doubleeq( expectedAnswer[0][1], actualAnswer[0][1] ) );

	TEMPER_CHECK_TRUE( doubleeq( expectedAnswer[1][0], actualAnswer[1][0] ) );
	TEMPER_CHECK_TRUE( doubleeq( expectedAnswer[1][1], actualAnswer[1][1] ) );

}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x2_int2x2,
	int2x2(
		0, 0,
		0, 0
	),
	double2x2(
		0.000000f, 0.000000f,
		0.000000f, 0.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x2_int2x2,
	int2x2(
		10, 10,
		10, 10
	),
	double2x2(
		10.000000f, 10.000000f,
		10.000000f, 10.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x2_int2x2,
	int2x2(
		10, 20,
		50, 60
	),
	double2x2(
		10.000000f, 20.000000f,
		50.000000f, 60.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x2_int2x2,
	int2x2(
		160, 150,
		120, 110
	),
	double2x2(
		160.000000f, 150.000000f,
		120.000000f, 110.000000f
	)
);

TEMPER_PARAMETRIC( Test_double2x2_uint2x2, TEMPER_FLAG_SHOULD_RUN, const uint2x2& convertFrom, const double2x2& expectedAnswer )
{
	double2x2 actualAnswer = double2x2( convertFrom );

	TEMPER_CHECK_TRUE( doubleeq( expectedAnswer[0][0], actualAnswer[0][0] ) );
	TEMPER_CHECK_TRUE( doubleeq( expectedAnswer[0][1], actualAnswer[0][1] ) );

	TEMPER_CHECK_TRUE( doubleeq( expectedAnswer[1][0], actualAnswer[1][0] ) );
	TEMPER_CHECK_TRUE( doubleeq( expectedAnswer[1][1], actualAnswer[1][1] ) );

}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x2_uint2x2,
	uint2x2(
		0U, 0U,
		0U, 0U
	),
	double2x2(
		0.000000f, 0.000000f,
		0.000000f, 0.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x2_uint2x2,
	uint2x2(
		10U, 10U,
		10U, 10U
	),
	double2x2(
		10.000000f, 10.000000f,
		10.000000f, 10.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x2_uint2x2,
	uint2x2(
		10U, 20U,
		50U, 60U
	),
	double2x2(
		10.000000f, 20.000000f,
		50.000000f, 60.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x2_uint2x2,
	uint2x2(
		160U, 150U,
		120U, 110U
	),
	double2x2(
		160.000000f, 150.000000f,
		120.000000f, 110.000000f
	)
);

TEMPER_PARAMETRIC( Test_double2x2_float2x2, TEMPER_FLAG_SHOULD_RUN, const float2x2& convertFrom, const double2x2& expectedAnswer )
{
	double2x2 actualAnswer = double2x2( convertFrom );

	TEMPER_CHECK_TRUE( doubleeq( expectedAnswer[0][0], actualAnswer[0][0] ) );
	TEMPER_CHECK_TRUE( doubleeq( expectedAnswer[0][1], actualAnswer[0][1] ) );

	TEMPER_CHECK_TRUE( doubleeq( expectedAnswer[1][0], actualAnswer[1][0] ) );
	TEMPER_CHECK_TRUE( doubleeq( expectedAnswer[1][1], actualAnswer[1][1] ) );

}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x2_float2x2,
	float2x2(
		0.000000f, 0.000000f,
		0.000000f, 0.000000f
	),
	double2x2(
		0.000000f, 0.000000f,
		0.000000f, 0.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x2_float2x2,
	float2x2(
		10.000000f, 10.000000f,
		10.000000f, 10.000000f
	),
	double2x2(
		10.000000f, 10.000000f,
		10.000000f, 10.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x2_float2x2,
	float2x2(
		10.000000f, 20.000000f,
		50.000000f, 60.000000f
	),
	double2x2(
		10.000000f, 20.000000f,
		50.000000f, 60.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x2_float2x2,
	float2x2(
		160.000000f, 150.000000f,
		120.000000f, 110.000000f
	),
	double2x2(
		160.000000f, 150.000000f,
		120.000000f, 110.000000f
	)
);

TEMPER_PARAMETRIC( Test_double2x2_double2x2, TEMPER_FLAG_SHOULD_RUN, const double2x2& convertFrom, const double2x2& expectedAnswer )
{
	double2x2 actualAnswer = double2x2( convertFrom );

	TEMPER_CHECK_TRUE( doubleeq( expectedAnswer[0][0], actualAnswer[0][0] ) );
	TEMPER_CHECK_TRUE( doubleeq( expectedAnswer[0][1], actualAnswer[0][1] ) );

	TEMPER_CHECK_TRUE( doubleeq( expectedAnswer[1][0], actualAnswer[1][0] ) );
	TEMPER_CHECK_TRUE( doubleeq( expectedAnswer[1][1], actualAnswer[1][1] ) );

}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x2_double2x2,
	double2x2(
		0.000000f, 0.000000f,
		0.000000f, 0.000000f
	),
	double2x2(
		0.000000f, 0.000000f,
		0.000000f, 0.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x2_double2x2,
	double2x2(
		10.000000f, 10.000000f,
		10.000000f, 10.000000f
	),
	double2x2(
		10.000000f, 10.000000f,
		10.000000f, 10.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x2_double2x2,
	double2x2(
		10.000000f, 20.000000f,
		50.000000f, 60.000000f
	),
	double2x2(
		10.000000f, 20.000000f,
		50.000000f, 60.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x2_double2x2,
	double2x2(
		160.000000f, 150.000000f,
		120.000000f, 110.000000f
	),
	double2x2(
		160.000000f, 150.000000f,
		120.000000f, 110.000000f
	)
);

TEMPER_PARAMETRIC( Test_double2x2_identity, TEMPER_FLAG_SHOULD_RUN, const double2x2& matrix, const bool expectedAnswer )
{
	double2x2 identityMat;
	identity( identityMat );
	bool isMatrixIdentity = ( identityMat == matrix );
	TEMPER_CHECK_TRUE( isMatrixIdentity == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x2_identity,
	double2x2(
		1.000000f, 0.000000f,
		0.000000f, 1.000000f
	),
	true
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x2_identity,
	double2x2(
		1.000000f, 1.000000f,
		0.000000f, 1.000000f
	),
	false
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x2_identity,
	double2x2(
		1.000000f, 0.000000f,
		1.000000f, 1.000000f
	),
	false
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x2_identity,
	double2x2(
		1.000000f, 1.000000f,
		1.000000f, 1.000000f
	),
	false
);

TEMPER_PARAMETRIC( Test_double2x2_transpose, TEMPER_FLAG_SHOULD_RUN, const double2x2& matrix, const double2x2& expectedAnswer )
{
	double2x2 actualResult = transpose( matrix );
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x2_transpose,
	double2x2(
		1.000000f, 0.000000f,
		0.000000f, 1.000000f
	),
	double2x2(
		1.000000f, 0.000000f,
		0.000000f, 1.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x2_transpose,
	double2x2(
		0.000000f, 1.000000f,
		4.000000f, 5.000000f
	),
	double2x2(
		0.000000f, 4.000000f,
		1.000000f, 5.000000f
	)
);

TEMPER_PARAMETRIC( Test_double2x2_mulm, TEMPER_FLAG_SHOULD_RUN, const double2x2& lhs, const double2x2& rhs, const double2x2& expectedAnswer )
{
	double2x2 actualResult = mul( lhs, rhs );
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x2_mulm,
	double2x2(
		2.000000f, 2.000000f,
		2.000000f, 2.000000f
	),
	double2x2(
		4.000000f, 4.000000f,
		4.000000f, 4.000000f
	),
	double2x2(
		16.000000f, 16.000000f,
		16.000000f, 16.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x2_mulm,
	double2x2(
		2.000000f, 2.000000f,
		2.000000f, 2.000000f
	),
	double2x2(
		1.000000f, 0.000000f,
		0.000000f, 1.000000f
	),
	double2x2(
		2.000000f, 2.000000f,
		2.000000f, 2.000000f
	)
);

TEMPER_PARAMETRIC( Test_double2x2_mulv, TEMPER_FLAG_SHOULD_RUN, const double2& vec, const double2x2& mat, const double2& expectedAnswer )
{
	double2 actualResult = mul( vec, mat );
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x2_mulv,
	double2( 0.000000f, 0.000000f ),
	double2x2(
		1.000000f, 0.000000f,
		0.000000f, 1.000000f
	),
	double2(
		0.000000f, 0.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x2_mulv,
	double2( 2.000000f, 1.000000f ),
	double2x2(
		1.000000f, 2.000000f,
		5.000000f, 6.000000f
	),
	double2(
		7.000000f, 10.000000f
	)
);

TEMPER_PARAMETRIC( Test_double2x2_determinant, TEMPER_FLAG_SHOULD_RUN, const double2x2& matrix, const double expectedAnswer )
{
	double actualResult = determinant( matrix );
	TEMPER_CHECK_TRUE( doubleeq( actualResult, expectedAnswer ) );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x2_determinant,
	double2x2(
		6.000000f, 2.000000f,
		2.000000f, 7.000000f
	),
	38.000000f
);

TEMPER_PARAMETRIC( Test_double2x2_inverse, TEMPER_FLAG_SHOULD_RUN, const double2x2& mat, const double2x2& expectedAnswer )
{
	double2x2 inversed = inverse( mat );
	TEMPER_CHECK_TRUE( inversed == expectedAnswer );

	// test inversed matrix multiplied by the original equals identity
	double2x2 identityMat;
	identity( identityMat );

	double2x2 matMultipliedByItsInverse = mul( mat, inversed );
	TEMPER_CHECK_TRUE( matMultipliedByItsInverse == identityMat );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x2_inverse,
	double2x2(
		1.000000f, 0.000000f,
		0.000000f, 1.000000f
	),
	double2x2(
		1.000000f, 0.000000f,
		0.000000f, 1.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x2_inverse,
	double2x2(
		6.000000f, 2.000000f,
		2.000000f, 7.000000f
	),
	double2x2(
		0.184211f, -0.052632f,
		-0.052632f, 0.157895f
	)
);


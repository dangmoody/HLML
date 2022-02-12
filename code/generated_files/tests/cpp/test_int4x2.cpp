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

TEMPER_PARAMETRIC( Test_int4x2_less_than, TEMPER_FLAG_SHOULD_RUN, const int4x2& lhs, const int4x2& rhs, const bool4x2& expectedAnswer )
{
	bool4x2 actualResult = lhs < rhs;
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int4x2_less_than,
	int4x2(
		0, 0,
		0, 0,
		0, 0,
		0, 0
	),
	int4x2(
		0, 0,
		0, 0,
		0, 0,
		0, 0
	),
	bool4x2(
		false, false,
		false, false,
		false, false,
		false, false
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int4x2_less_than,
	int4x2(
		0, 0,
		0, 0,
		0, 0,
		0, 0
	),
	int4x2(
		1, 1,
		1, 1,
		1, 1,
		1, 1
	),
	bool4x2(
		true, true,
		true, true,
		true, true,
		true, true
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int4x2_less_than,
	int4x2(
		1, 1,
		1, 1,
		1, 1,
		1, 1
	),
	int4x2(
		1, 1,
		1, 1,
		1, 1,
		1, 1
	),
	bool4x2(
		false, false,
		false, false,
		false, false,
		false, false
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int4x2_less_than,
	int4x2(
		1, 1,
		1, 1,
		1, 1,
		1, 1
	),
	int4x2(
		0, 0,
		0, 0,
		0, 0,
		0, 0
	),
	bool4x2(
		false, false,
		false, false,
		false, false,
		false, false
	)
);

TEMPER_PARAMETRIC( Test_int4x2_less_than_equal, TEMPER_FLAG_SHOULD_RUN, const int4x2& lhs, const int4x2& rhs, const bool4x2& expectedAnswer )
{
	bool4x2 actualResult = lhs <= rhs;
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int4x2_less_than_equal,
	int4x2(
		0, 0,
		0, 0,
		0, 0,
		0, 0
	),
	int4x2(
		0, 0,
		0, 0,
		0, 0,
		0, 0
	),
	bool4x2(
		true, true,
		true, true,
		true, true,
		true, true
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int4x2_less_than_equal,
	int4x2(
		0, 0,
		0, 0,
		0, 0,
		0, 0
	),
	int4x2(
		1, 1,
		1, 1,
		1, 1,
		1, 1
	),
	bool4x2(
		true, true,
		true, true,
		true, true,
		true, true
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int4x2_less_than_equal,
	int4x2(
		1, 1,
		1, 1,
		1, 1,
		1, 1
	),
	int4x2(
		1, 1,
		1, 1,
		1, 1,
		1, 1
	),
	bool4x2(
		true, true,
		true, true,
		true, true,
		true, true
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int4x2_less_than_equal,
	int4x2(
		1, 1,
		1, 1,
		1, 1,
		1, 1
	),
	int4x2(
		0, 0,
		0, 0,
		0, 0,
		0, 0
	),
	bool4x2(
		false, false,
		false, false,
		false, false,
		false, false
	)
);

TEMPER_PARAMETRIC( Test_int4x2_greater_than, TEMPER_FLAG_SHOULD_RUN, const int4x2& lhs, const int4x2& rhs, const bool4x2& expectedAnswer )
{
	bool4x2 actualResult = lhs > rhs;
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int4x2_greater_than,
	int4x2(
		0, 0,
		0, 0,
		0, 0,
		0, 0
	),
	int4x2(
		0, 0,
		0, 0,
		0, 0,
		0, 0
	),
	bool4x2(
		false, false,
		false, false,
		false, false,
		false, false
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int4x2_greater_than,
	int4x2(
		0, 0,
		0, 0,
		0, 0,
		0, 0
	),
	int4x2(
		1, 1,
		1, 1,
		1, 1,
		1, 1
	),
	bool4x2(
		false, false,
		false, false,
		false, false,
		false, false
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int4x2_greater_than,
	int4x2(
		1, 1,
		1, 1,
		1, 1,
		1, 1
	),
	int4x2(
		1, 1,
		1, 1,
		1, 1,
		1, 1
	),
	bool4x2(
		false, false,
		false, false,
		false, false,
		false, false
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int4x2_greater_than,
	int4x2(
		1, 1,
		1, 1,
		1, 1,
		1, 1
	),
	int4x2(
		0, 0,
		0, 0,
		0, 0,
		0, 0
	),
	bool4x2(
		true, true,
		true, true,
		true, true,
		true, true
	)
);

TEMPER_PARAMETRIC( Test_int4x2_greater_than_equal, TEMPER_FLAG_SHOULD_RUN, const int4x2& lhs, const int4x2& rhs, const bool4x2& expectedAnswer )
{
	bool4x2 actualResult = lhs >= rhs;
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int4x2_greater_than_equal,
	int4x2(
		0, 0,
		0, 0,
		0, 0,
		0, 0
	),
	int4x2(
		0, 0,
		0, 0,
		0, 0,
		0, 0
	),
	bool4x2(
		true, true,
		true, true,
		true, true,
		true, true
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int4x2_greater_than_equal,
	int4x2(
		0, 0,
		0, 0,
		0, 0,
		0, 0
	),
	int4x2(
		1, 1,
		1, 1,
		1, 1,
		1, 1
	),
	bool4x2(
		false, false,
		false, false,
		false, false,
		false, false
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int4x2_greater_than_equal,
	int4x2(
		1, 1,
		1, 1,
		1, 1,
		1, 1
	),
	int4x2(
		1, 1,
		1, 1,
		1, 1,
		1, 1
	),
	bool4x2(
		true, true,
		true, true,
		true, true,
		true, true
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int4x2_greater_than_equal,
	int4x2(
		1, 1,
		1, 1,
		1, 1,
		1, 1
	),
	int4x2(
		0, 0,
		0, 0,
		0, 0,
		0, 0
	),
	bool4x2(
		true, true,
		true, true,
		true, true,
		true, true
	)
);

TEMPER_PARAMETRIC( Test_int4x2_cadds, TEMPER_FLAG_SHOULD_RUN, const int4x2& lhs, const int32_t& rhs, const int4x2& expectedAnswer )
{
	int4x2 actualResult = lhs + rhs;
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int4x2_cadds,
	int4x2(
		1, 1,
		1, 1,
		1, 1,
		1, 1
	),
	1,
	int4x2(
		2, 2,
		2, 2,
		2, 2,
		2, 2
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int4x2_cadds,
	int4x2(
		2, 2,
		2, 2,
		2, 2,
		2, 2
	),
	2,
	int4x2(
		4, 4,
		4, 4,
		4, 4,
		4, 4
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int4x2_cadds,
	int4x2(
		4, 4,
		4, 4,
		4, 4,
		4, 4
	),
	2,
	int4x2(
		6, 6,
		6, 6,
		6, 6,
		6, 6
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int4x2_cadds,
	int4x2(
		8, 8,
		8, 8,
		8, 8,
		8, 8
	),
	4,
	int4x2(
		12, 12,
		12, 12,
		12, 12,
		12, 12
	)
);

TEMPER_PARAMETRIC( Test_int4x2_csubs, TEMPER_FLAG_SHOULD_RUN, const int4x2& lhs, const int32_t& rhs, const int4x2& expectedAnswer )
{
	int4x2 actualResult = lhs - rhs;
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int4x2_csubs,
	int4x2(
		1, 1,
		1, 1,
		1, 1,
		1, 1
	),
	1,
	int4x2(
		0, 0,
		0, 0,
		0, 0,
		0, 0
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int4x2_csubs,
	int4x2(
		2, 2,
		2, 2,
		2, 2,
		2, 2
	),
	2,
	int4x2(
		0, 0,
		0, 0,
		0, 0,
		0, 0
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int4x2_csubs,
	int4x2(
		4, 4,
		4, 4,
		4, 4,
		4, 4
	),
	2,
	int4x2(
		2, 2,
		2, 2,
		2, 2,
		2, 2
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int4x2_csubs,
	int4x2(
		8, 8,
		8, 8,
		8, 8,
		8, 8
	),
	4,
	int4x2(
		4, 4,
		4, 4,
		4, 4,
		4, 4
	)
);

TEMPER_PARAMETRIC( Test_int4x2_cmuls, TEMPER_FLAG_SHOULD_RUN, const int4x2& lhs, const int32_t& rhs, const int4x2& expectedAnswer )
{
	int4x2 actualResult = lhs * rhs;
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int4x2_cmuls,
	int4x2(
		1, 1,
		1, 1,
		1, 1,
		1, 1
	),
	1,
	int4x2(
		1, 1,
		1, 1,
		1, 1,
		1, 1
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int4x2_cmuls,
	int4x2(
		2, 2,
		2, 2,
		2, 2,
		2, 2
	),
	2,
	int4x2(
		4, 4,
		4, 4,
		4, 4,
		4, 4
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int4x2_cmuls,
	int4x2(
		4, 4,
		4, 4,
		4, 4,
		4, 4
	),
	2,
	int4x2(
		8, 8,
		8, 8,
		8, 8,
		8, 8
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int4x2_cmuls,
	int4x2(
		8, 8,
		8, 8,
		8, 8,
		8, 8
	),
	4,
	int4x2(
		32, 32,
		32, 32,
		32, 32,
		32, 32
	)
);

TEMPER_PARAMETRIC( Test_int4x2_cdivs, TEMPER_FLAG_SHOULD_RUN, const int4x2& lhs, const int32_t& rhs, const int4x2& expectedAnswer )
{
	int4x2 actualResult = lhs / rhs;
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int4x2_cdivs,
	int4x2(
		1, 1,
		1, 1,
		1, 1,
		1, 1
	),
	1,
	int4x2(
		1, 1,
		1, 1,
		1, 1,
		1, 1
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int4x2_cdivs,
	int4x2(
		2, 2,
		2, 2,
		2, 2,
		2, 2
	),
	2,
	int4x2(
		1, 1,
		1, 1,
		1, 1,
		1, 1
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int4x2_cdivs,
	int4x2(
		4, 4,
		4, 4,
		4, 4,
		4, 4
	),
	2,
	int4x2(
		2, 2,
		2, 2,
		2, 2,
		2, 2
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int4x2_cdivs,
	int4x2(
		8, 8,
		8, 8,
		8, 8,
		8, 8
	),
	4,
	int4x2(
		2, 2,
		2, 2,
		2, 2,
		2, 2
	)
);

TEMPER_PARAMETRIC( Test_int4x2_caddm, TEMPER_FLAG_SHOULD_RUN, const int4x2& lhs, const int4x2& rhs, const int4x2& expectedAnswer )
{
	int4x2 actualResult = lhs + rhs;
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int4x2_caddm,
	int4x2(
		1, 1,
		1, 1,
		1, 1,
		1, 1
	),
	int4x2(
		1, 1,
		1, 1,
		1, 1,
		1, 1
	),
	int4x2(
		2, 2,
		2, 2,
		2, 2,
		2, 2
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int4x2_caddm,
	int4x2(
		2, 2,
		2, 2,
		2, 2,
		2, 2
	),
	int4x2(
		2, 2,
		2, 2,
		2, 2,
		2, 2
	),
	int4x2(
		4, 4,
		4, 4,
		4, 4,
		4, 4
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int4x2_caddm,
	int4x2(
		4, 4,
		4, 4,
		4, 4,
		4, 4
	),
	int4x2(
		2, 2,
		2, 2,
		2, 2,
		2, 2
	),
	int4x2(
		6, 6,
		6, 6,
		6, 6,
		6, 6
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int4x2_caddm,
	int4x2(
		8, 8,
		8, 8,
		8, 8,
		8, 8
	),
	int4x2(
		4, 4,
		4, 4,
		4, 4,
		4, 4
	),
	int4x2(
		12, 12,
		12, 12,
		12, 12,
		12, 12
	)
);

TEMPER_PARAMETRIC( Test_int4x2_csubm, TEMPER_FLAG_SHOULD_RUN, const int4x2& lhs, const int4x2& rhs, const int4x2& expectedAnswer )
{
	int4x2 actualResult = lhs - rhs;
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int4x2_csubm,
	int4x2(
		1, 1,
		1, 1,
		1, 1,
		1, 1
	),
	int4x2(
		1, 1,
		1, 1,
		1, 1,
		1, 1
	),
	int4x2(
		0, 0,
		0, 0,
		0, 0,
		0, 0
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int4x2_csubm,
	int4x2(
		2, 2,
		2, 2,
		2, 2,
		2, 2
	),
	int4x2(
		2, 2,
		2, 2,
		2, 2,
		2, 2
	),
	int4x2(
		0, 0,
		0, 0,
		0, 0,
		0, 0
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int4x2_csubm,
	int4x2(
		4, 4,
		4, 4,
		4, 4,
		4, 4
	),
	int4x2(
		2, 2,
		2, 2,
		2, 2,
		2, 2
	),
	int4x2(
		2, 2,
		2, 2,
		2, 2,
		2, 2
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int4x2_csubm,
	int4x2(
		8, 8,
		8, 8,
		8, 8,
		8, 8
	),
	int4x2(
		4, 4,
		4, 4,
		4, 4,
		4, 4
	),
	int4x2(
		4, 4,
		4, 4,
		4, 4,
		4, 4
	)
);

TEMPER_PARAMETRIC( Test_int4x2_cmulm, TEMPER_FLAG_SHOULD_RUN, const int4x2& lhs, const int4x2& rhs, const int4x2& expectedAnswer )
{
	int4x2 actualResult = lhs * rhs;
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int4x2_cmulm,
	int4x2(
		1, 1,
		1, 1,
		1, 1,
		1, 1
	),
	int4x2(
		1, 1,
		1, 1,
		1, 1,
		1, 1
	),
	int4x2(
		1, 1,
		1, 1,
		1, 1,
		1, 1
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int4x2_cmulm,
	int4x2(
		2, 2,
		2, 2,
		2, 2,
		2, 2
	),
	int4x2(
		2, 2,
		2, 2,
		2, 2,
		2, 2
	),
	int4x2(
		4, 4,
		4, 4,
		4, 4,
		4, 4
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int4x2_cmulm,
	int4x2(
		4, 4,
		4, 4,
		4, 4,
		4, 4
	),
	int4x2(
		2, 2,
		2, 2,
		2, 2,
		2, 2
	),
	int4x2(
		8, 8,
		8, 8,
		8, 8,
		8, 8
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int4x2_cmulm,
	int4x2(
		8, 8,
		8, 8,
		8, 8,
		8, 8
	),
	int4x2(
		4, 4,
		4, 4,
		4, 4,
		4, 4
	),
	int4x2(
		32, 32,
		32, 32,
		32, 32,
		32, 32
	)
);

TEMPER_PARAMETRIC( Test_int4x2_cdivm, TEMPER_FLAG_SHOULD_RUN, const int4x2& lhs, const int4x2& rhs, const int4x2& expectedAnswer )
{
	int4x2 actualResult = lhs / rhs;
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int4x2_cdivm,
	int4x2(
		1, 1,
		1, 1,
		1, 1,
		1, 1
	),
	int4x2(
		1, 1,
		1, 1,
		1, 1,
		1, 1
	),
	int4x2(
		1, 1,
		1, 1,
		1, 1,
		1, 1
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int4x2_cdivm,
	int4x2(
		2, 2,
		2, 2,
		2, 2,
		2, 2
	),
	int4x2(
		2, 2,
		2, 2,
		2, 2,
		2, 2
	),
	int4x2(
		1, 1,
		1, 1,
		1, 1,
		1, 1
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int4x2_cdivm,
	int4x2(
		4, 4,
		4, 4,
		4, 4,
		4, 4
	),
	int4x2(
		2, 2,
		2, 2,
		2, 2,
		2, 2
	),
	int4x2(
		2, 2,
		2, 2,
		2, 2,
		2, 2
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int4x2_cdivm,
	int4x2(
		8, 8,
		8, 8,
		8, 8,
		8, 8
	),
	int4x2(
		4, 4,
		4, 4,
		4, 4,
		4, 4
	),
	int4x2(
		2, 2,
		2, 2,
		2, 2,
		2, 2
	)
);

#if defined( __GNUC__ ) || defined( __clang__ )
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wcast-qual"
#endif

TEMPER_PARAMETRIC( Test_int4x2_increment_prefix, TEMPER_FLAG_SHOULD_RUN, const int4x2& x, const int4x2& expectedAnswer )
{
	// make local copy of x and use that because we cant do increment or decrement operations on a const reference
	// and MSVC throws warnings if we just make the parameter a non-const reference
	int4x2 xlocal = (int4x2) x;
	int4x2 actualAnswer = ++xlocal;
	TEMPER_CHECK_TRUE( actualAnswer == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int4x2_increment_prefix,
	int4x2(
		1, 1,
		1, 1,
		1, 1,
		1, 1
	),
	int4x2(
		2, 2,
		2, 2,
		2, 2,
		2, 2
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int4x2_increment_prefix,
	int4x2(
		2, 2,
		2, 2,
		2, 2,
		2, 2
	),
	int4x2(
		3, 3,
		3, 3,
		3, 3,
		3, 3
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int4x2_increment_prefix,
	int4x2(
		3, 3,
		3, 3,
		3, 3,
		3, 3
	),
	int4x2(
		4, 4,
		4, 4,
		4, 4,
		4, 4
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int4x2_increment_prefix,
	int4x2(
		4, 4,
		4, 4,
		4, 4,
		4, 4
	),
	int4x2(
		5, 5,
		5, 5,
		5, 5,
		5, 5
	)
);

TEMPER_PARAMETRIC( Test_int4x2_increment_postfix, TEMPER_FLAG_SHOULD_RUN, const int4x2& x, const int4x2& expectedAnswer )
{
	// make local copy of x and use that because we cant do increment or decrement operations on a const reference
	// and MSVC throws warnings if we just make the parameter a non-const reference
	int4x2 xlocal = (int4x2) x;
	int4x2 actualAnswer = xlocal++;
	TEMPER_CHECK_TRUE( actualAnswer == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int4x2_increment_postfix,
	int4x2(
		1, 1,
		1, 1,
		1, 1,
		1, 1
	),
	int4x2(
		2, 2,
		2, 2,
		2, 2,
		2, 2
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int4x2_increment_postfix,
	int4x2(
		2, 2,
		2, 2,
		2, 2,
		2, 2
	),
	int4x2(
		3, 3,
		3, 3,
		3, 3,
		3, 3
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int4x2_increment_postfix,
	int4x2(
		3, 3,
		3, 3,
		3, 3,
		3, 3
	),
	int4x2(
		4, 4,
		4, 4,
		4, 4,
		4, 4
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int4x2_increment_postfix,
	int4x2(
		4, 4,
		4, 4,
		4, 4,
		4, 4
	),
	int4x2(
		5, 5,
		5, 5,
		5, 5,
		5, 5
	)
);

TEMPER_PARAMETRIC( Test_int4x2_decrement_prefix, TEMPER_FLAG_SHOULD_RUN, const int4x2& x, const int4x2& expectedAnswer )
{
	// make local copy of x and use that because we cant do increment or decrement operations on a const reference
	// and MSVC throws warnings if we just make the parameter a non-const reference
	int4x2 xlocal = (int4x2) x;
	int4x2 actualAnswer = --xlocal;
	TEMPER_CHECK_TRUE( actualAnswer == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int4x2_decrement_prefix,
	int4x2(
		1, 1,
		1, 1,
		1, 1,
		1, 1
	),
	int4x2(
		0, 0,
		0, 0,
		0, 0,
		0, 0
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int4x2_decrement_prefix,
	int4x2(
		2, 2,
		2, 2,
		2, 2,
		2, 2
	),
	int4x2(
		1, 1,
		1, 1,
		1, 1,
		1, 1
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int4x2_decrement_prefix,
	int4x2(
		3, 3,
		3, 3,
		3, 3,
		3, 3
	),
	int4x2(
		2, 2,
		2, 2,
		2, 2,
		2, 2
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int4x2_decrement_prefix,
	int4x2(
		4, 4,
		4, 4,
		4, 4,
		4, 4
	),
	int4x2(
		3, 3,
		3, 3,
		3, 3,
		3, 3
	)
);

TEMPER_PARAMETRIC( Test_int4x2_decrement_postfix, TEMPER_FLAG_SHOULD_RUN, const int4x2& x, const int4x2& expectedAnswer )
{
	// make local copy of x and use that because we cant do increment or decrement operations on a const reference
	// and MSVC throws warnings if we just make the parameter a non-const reference
	int4x2 xlocal = (int4x2) x;
	int4x2 actualAnswer = xlocal--;
	TEMPER_CHECK_TRUE( actualAnswer == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int4x2_decrement_postfix,
	int4x2(
		1, 1,
		1, 1,
		1, 1,
		1, 1
	),
	int4x2(
		0, 0,
		0, 0,
		0, 0,
		0, 0
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int4x2_decrement_postfix,
	int4x2(
		2, 2,
		2, 2,
		2, 2,
		2, 2
	),
	int4x2(
		1, 1,
		1, 1,
		1, 1,
		1, 1
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int4x2_decrement_postfix,
	int4x2(
		3, 3,
		3, 3,
		3, 3,
		3, 3
	),
	int4x2(
		2, 2,
		2, 2,
		2, 2,
		2, 2
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int4x2_decrement_postfix,
	int4x2(
		4, 4,
		4, 4,
		4, 4,
		4, 4
	),
	int4x2(
		3, 3,
		3, 3,
		3, 3,
		3, 3
	)
);

#if defined( __GNUC__ ) || defined( __clang__ )
#pragma GCC diagnostic pop
#endif
#if defined( __GNUC__ ) || defined( __clang__ )
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wcast-qual"
#endif
TEMPER_PARAMETRIC( Test_int4x2_negate_prefix, TEMPER_FLAG_SHOULD_RUN, const int4x2& x, const int4x2& expectedAnswer )
{
	// make local copy of x and use that because we cant do increment or decrement operations on a const reference
	// and MSVC throws warnings if we just make the parameter a non-const reference
	int4x2 xlocal = (int4x2) x;
	int4x2 actualAnswer = -xlocal;
	TEMPER_CHECK_TRUE( actualAnswer == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int4x2_negate_prefix,
	int4x2(
		0, 0,
		0, 0,
		0, 0,
		0, 0
	),
	int4x2(
		0, 0,
		0, 0,
		0, 0,
		0, 0
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int4x2_negate_prefix,
	int4x2(
		1, 1,
		1, 1,
		1, 1,
		1, 1
	),
	int4x2(
		-1, -1,
		-1, -1,
		-1, -1,
		-1, -1
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int4x2_negate_prefix,
	int4x2(
		2, 2,
		2, 2,
		2, 2,
		2, 2
	),
	int4x2(
		-2, -2,
		-2, -2,
		-2, -2,
		-2, -2
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int4x2_negate_prefix,
	int4x2(
		3, 3,
		3, 3,
		3, 3,
		3, 3
	),
	int4x2(
		-3, -3,
		-3, -3,
		-3, -3,
		-3, -3
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int4x2_negate_prefix,
	int4x2(
		10, 10,
		10, 10,
		10, 10,
		10, 10
	),
	int4x2(
		-10, -10,
		-10, -10,
		-10, -10,
		-10, -10
	)
);

#if defined( __GNUC__ ) || defined( __clang__ )
#pragma GCC diagnostic pop
#endif

#if defined( __GNUC__ ) || defined( __clang__ )
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wcast-qual"
#endif
TEMPER_PARAMETRIC( Test_int4x2_unary_prefix, TEMPER_FLAG_SHOULD_RUN, const int4x2& x, const int4x2& expectedAnswer )
{
	// make local copy of x and use that because we cant do increment or decrement operations on a const reference
	// and MSVC throws warnings if we just make the parameter a non-const reference
	int4x2 xlocal = (int4x2) x;
	int4x2 actualAnswer = ~xlocal;
	TEMPER_CHECK_TRUE( actualAnswer == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int4x2_unary_prefix,
	int4x2(
		1, 1,
		1, 1,
		1, 1,
		1, 1
	),
	int4x2(
		-2, -2,
		-2, -2,
		-2, -2,
		-2, -2
	)
);

#if defined( __GNUC__ ) || defined( __clang__ )
#pragma GCC diagnostic pop
#endif

TEMPER_PARAMETRIC( Test_int4x2_cands, TEMPER_FLAG_SHOULD_RUN, const int4x2& lhs, const int32_t& rhs, const int4x2& expectedAnswer )
{
	int4x2 actualResult = lhs & rhs;
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int4x2_cands,
	int4x2(
		0, 0,
		0, 0,
		0, 0,
		0, 0
	),
	0,
	int4x2(
		0, 0,
		0, 0,
		0, 0,
		0, 0
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int4x2_cands,
	int4x2(
		2, 2,
		2, 2,
		2, 2,
		2, 2
	),
	1,
	int4x2(
		0, 0,
		0, 0,
		0, 0,
		0, 0
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int4x2_cands,
	int4x2(
		1, 1,
		1, 1,
		1, 1,
		1, 1
	),
	0,
	int4x2(
		0, 0,
		0, 0,
		0, 0,
		0, 0
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int4x2_cands,
	int4x2(
		1, 1,
		1, 1,
		1, 1,
		1, 1
	),
	1,
	int4x2(
		1, 1,
		1, 1,
		1, 1,
		1, 1
	)
);

TEMPER_PARAMETRIC( Test_int4x2_cors, TEMPER_FLAG_SHOULD_RUN, const int4x2& lhs, const int32_t& rhs, const int4x2& expectedAnswer )
{
	int4x2 actualResult = lhs | rhs;
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int4x2_cors,
	int4x2(
		0, 0,
		0, 0,
		0, 0,
		0, 0
	),
	0,
	int4x2(
		0, 0,
		0, 0,
		0, 0,
		0, 0
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int4x2_cors,
	int4x2(
		2, 2,
		2, 2,
		2, 2,
		2, 2
	),
	1,
	int4x2(
		3, 3,
		3, 3,
		3, 3,
		3, 3
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int4x2_cors,
	int4x2(
		1, 1,
		1, 1,
		1, 1,
		1, 1
	),
	0,
	int4x2(
		1, 1,
		1, 1,
		1, 1,
		1, 1
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int4x2_cors,
	int4x2(
		1, 1,
		1, 1,
		1, 1,
		1, 1
	),
	1,
	int4x2(
		1, 1,
		1, 1,
		1, 1,
		1, 1
	)
);

TEMPER_PARAMETRIC( Test_int4x2_cxors, TEMPER_FLAG_SHOULD_RUN, const int4x2& lhs, const int32_t& rhs, const int4x2& expectedAnswer )
{
	int4x2 actualResult = lhs ^ rhs;
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int4x2_cxors,
	int4x2(
		0, 0,
		0, 0,
		0, 0,
		0, 0
	),
	0,
	int4x2(
		0, 0,
		0, 0,
		0, 0,
		0, 0
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int4x2_cxors,
	int4x2(
		2, 2,
		2, 2,
		2, 2,
		2, 2
	),
	1,
	int4x2(
		3, 3,
		3, 3,
		3, 3,
		3, 3
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int4x2_cxors,
	int4x2(
		1, 1,
		1, 1,
		1, 1,
		1, 1
	),
	0,
	int4x2(
		1, 1,
		1, 1,
		1, 1,
		1, 1
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int4x2_cxors,
	int4x2(
		1, 1,
		1, 1,
		1, 1,
		1, 1
	),
	1,
	int4x2(
		0, 0,
		0, 0,
		0, 0,
		0, 0
	)
);

TEMPER_PARAMETRIC( Test_int4x2_cshift_lefts, TEMPER_FLAG_SHOULD_RUN, const int4x2& lhs, const int32_t& rhs, const int4x2& expectedAnswer )
{
	int4x2 actualResult = lhs << rhs;
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int4x2_cshift_lefts,
	int4x2(
		0, 0,
		0, 0,
		0, 0,
		0, 0
	),
	0,
	int4x2(
		0, 0,
		0, 0,
		0, 0,
		0, 0
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int4x2_cshift_lefts,
	int4x2(
		2, 2,
		2, 2,
		2, 2,
		2, 2
	),
	1,
	int4x2(
		4, 4,
		4, 4,
		4, 4,
		4, 4
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int4x2_cshift_lefts,
	int4x2(
		1, 1,
		1, 1,
		1, 1,
		1, 1
	),
	0,
	int4x2(
		1, 1,
		1, 1,
		1, 1,
		1, 1
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int4x2_cshift_lefts,
	int4x2(
		1, 1,
		1, 1,
		1, 1,
		1, 1
	),
	1,
	int4x2(
		2, 2,
		2, 2,
		2, 2,
		2, 2
	)
);

TEMPER_PARAMETRIC( Test_int4x2_cshift_rights, TEMPER_FLAG_SHOULD_RUN, const int4x2& lhs, const int32_t& rhs, const int4x2& expectedAnswer )
{
	int4x2 actualResult = lhs >> rhs;
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int4x2_cshift_rights,
	int4x2(
		0, 0,
		0, 0,
		0, 0,
		0, 0
	),
	0,
	int4x2(
		0, 0,
		0, 0,
		0, 0,
		0, 0
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int4x2_cshift_rights,
	int4x2(
		2, 2,
		2, 2,
		2, 2,
		2, 2
	),
	1,
	int4x2(
		1, 1,
		1, 1,
		1, 1,
		1, 1
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int4x2_cshift_rights,
	int4x2(
		1, 1,
		1, 1,
		1, 1,
		1, 1
	),
	0,
	int4x2(
		1, 1,
		1, 1,
		1, 1,
		1, 1
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int4x2_cshift_rights,
	int4x2(
		1, 1,
		1, 1,
		1, 1,
		1, 1
	),
	1,
	int4x2(
		0, 0,
		0, 0,
		0, 0,
		0, 0
	)
);

TEMPER_PARAMETRIC( Test_int4x2_candm, TEMPER_FLAG_SHOULD_RUN, const int4x2& lhs, const int4x2& rhs, const int4x2& expectedAnswer )
{
	int4x2 actualResult = lhs & rhs;
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int4x2_candm,
	int4x2(
		0, 0,
		0, 0,
		0, 0,
		0, 0
	),
	int4x2(
		0, 0,
		0, 0,
		0, 0,
		0, 0
	),
	int4x2(
		0, 0,
		0, 0,
		0, 0,
		0, 0
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int4x2_candm,
	int4x2(
		2, 2,
		2, 2,
		2, 2,
		2, 2
	),
	int4x2(
		1, 1,
		1, 1,
		1, 1,
		1, 1
	),
	int4x2(
		0, 0,
		0, 0,
		0, 0,
		0, 0
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int4x2_candm,
	int4x2(
		1, 1,
		1, 1,
		1, 1,
		1, 1
	),
	int4x2(
		0, 0,
		0, 0,
		0, 0,
		0, 0
	),
	int4x2(
		0, 0,
		0, 0,
		0, 0,
		0, 0
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int4x2_candm,
	int4x2(
		1, 1,
		1, 1,
		1, 1,
		1, 1
	),
	int4x2(
		1, 1,
		1, 1,
		1, 1,
		1, 1
	),
	int4x2(
		1, 1,
		1, 1,
		1, 1,
		1, 1
	)
);

TEMPER_PARAMETRIC( Test_int4x2_corm, TEMPER_FLAG_SHOULD_RUN, const int4x2& lhs, const int4x2& rhs, const int4x2& expectedAnswer )
{
	int4x2 actualResult = lhs | rhs;
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int4x2_corm,
	int4x2(
		0, 0,
		0, 0,
		0, 0,
		0, 0
	),
	int4x2(
		0, 0,
		0, 0,
		0, 0,
		0, 0
	),
	int4x2(
		0, 0,
		0, 0,
		0, 0,
		0, 0
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int4x2_corm,
	int4x2(
		2, 2,
		2, 2,
		2, 2,
		2, 2
	),
	int4x2(
		1, 1,
		1, 1,
		1, 1,
		1, 1
	),
	int4x2(
		3, 3,
		3, 3,
		3, 3,
		3, 3
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int4x2_corm,
	int4x2(
		1, 1,
		1, 1,
		1, 1,
		1, 1
	),
	int4x2(
		0, 0,
		0, 0,
		0, 0,
		0, 0
	),
	int4x2(
		1, 1,
		1, 1,
		1, 1,
		1, 1
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int4x2_corm,
	int4x2(
		1, 1,
		1, 1,
		1, 1,
		1, 1
	),
	int4x2(
		1, 1,
		1, 1,
		1, 1,
		1, 1
	),
	int4x2(
		1, 1,
		1, 1,
		1, 1,
		1, 1
	)
);

TEMPER_PARAMETRIC( Test_int4x2_cxorm, TEMPER_FLAG_SHOULD_RUN, const int4x2& lhs, const int4x2& rhs, const int4x2& expectedAnswer )
{
	int4x2 actualResult = lhs ^ rhs;
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int4x2_cxorm,
	int4x2(
		0, 0,
		0, 0,
		0, 0,
		0, 0
	),
	int4x2(
		0, 0,
		0, 0,
		0, 0,
		0, 0
	),
	int4x2(
		0, 0,
		0, 0,
		0, 0,
		0, 0
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int4x2_cxorm,
	int4x2(
		2, 2,
		2, 2,
		2, 2,
		2, 2
	),
	int4x2(
		1, 1,
		1, 1,
		1, 1,
		1, 1
	),
	int4x2(
		3, 3,
		3, 3,
		3, 3,
		3, 3
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int4x2_cxorm,
	int4x2(
		1, 1,
		1, 1,
		1, 1,
		1, 1
	),
	int4x2(
		0, 0,
		0, 0,
		0, 0,
		0, 0
	),
	int4x2(
		1, 1,
		1, 1,
		1, 1,
		1, 1
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int4x2_cxorm,
	int4x2(
		1, 1,
		1, 1,
		1, 1,
		1, 1
	),
	int4x2(
		1, 1,
		1, 1,
		1, 1,
		1, 1
	),
	int4x2(
		0, 0,
		0, 0,
		0, 0,
		0, 0
	)
);

TEMPER_PARAMETRIC( Test_int4x2_cshift_leftm, TEMPER_FLAG_SHOULD_RUN, const int4x2& lhs, const int4x2& rhs, const int4x2& expectedAnswer )
{
	int4x2 actualResult = lhs << rhs;
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int4x2_cshift_leftm,
	int4x2(
		0, 0,
		0, 0,
		0, 0,
		0, 0
	),
	int4x2(
		0, 0,
		0, 0,
		0, 0,
		0, 0
	),
	int4x2(
		0, 0,
		0, 0,
		0, 0,
		0, 0
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int4x2_cshift_leftm,
	int4x2(
		2, 2,
		2, 2,
		2, 2,
		2, 2
	),
	int4x2(
		1, 1,
		1, 1,
		1, 1,
		1, 1
	),
	int4x2(
		4, 4,
		4, 4,
		4, 4,
		4, 4
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int4x2_cshift_leftm,
	int4x2(
		1, 1,
		1, 1,
		1, 1,
		1, 1
	),
	int4x2(
		0, 0,
		0, 0,
		0, 0,
		0, 0
	),
	int4x2(
		1, 1,
		1, 1,
		1, 1,
		1, 1
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int4x2_cshift_leftm,
	int4x2(
		1, 1,
		1, 1,
		1, 1,
		1, 1
	),
	int4x2(
		1, 1,
		1, 1,
		1, 1,
		1, 1
	),
	int4x2(
		2, 2,
		2, 2,
		2, 2,
		2, 2
	)
);

TEMPER_PARAMETRIC( Test_int4x2_cshift_rightm, TEMPER_FLAG_SHOULD_RUN, const int4x2& lhs, const int4x2& rhs, const int4x2& expectedAnswer )
{
	int4x2 actualResult = lhs >> rhs;
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int4x2_cshift_rightm,
	int4x2(
		0, 0,
		0, 0,
		0, 0,
		0, 0
	),
	int4x2(
		0, 0,
		0, 0,
		0, 0,
		0, 0
	),
	int4x2(
		0, 0,
		0, 0,
		0, 0,
		0, 0
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int4x2_cshift_rightm,
	int4x2(
		2, 2,
		2, 2,
		2, 2,
		2, 2
	),
	int4x2(
		1, 1,
		1, 1,
		1, 1,
		1, 1
	),
	int4x2(
		1, 1,
		1, 1,
		1, 1,
		1, 1
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int4x2_cshift_rightm,
	int4x2(
		1, 1,
		1, 1,
		1, 1,
		1, 1
	),
	int4x2(
		0, 0,
		0, 0,
		0, 0,
		0, 0
	),
	int4x2(
		1, 1,
		1, 1,
		1, 1,
		1, 1
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int4x2_cshift_rightm,
	int4x2(
		1, 1,
		1, 1,
		1, 1,
		1, 1
	),
	int4x2(
		1, 1,
		1, 1,
		1, 1,
		1, 1
	),
	int4x2(
		0, 0,
		0, 0,
		0, 0,
		0, 0
	)
);

TEMPER_PARAMETRIC( Test_int4x2_min, TEMPER_FLAG_SHOULD_RUN, const int4x2& lhs, const int4x2& rhs, const int4x2& expectedAnswer )
{
	int4x2 actualResult = min( lhs, rhs );
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int4x2_min,
	int4x2(
		0, 0,
		0, 0,
		0, 0,
		0, 0
	),
	int4x2(
		1, 1,
		1, 1,
		1, 1,
		1, 1
	),
	int4x2(
		0, 0,
		0, 0,
		0, 0,
		0, 0
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int4x2_min,
	int4x2(
		1, 1,
		1, 1,
		1, 1,
		1, 1
	),
	int4x2(
		2, 2,
		2, 2,
		2, 2,
		2, 2
	),
	int4x2(
		1, 1,
		1, 1,
		1, 1,
		1, 1
	)
);

TEMPER_PARAMETRIC( Test_int4x2_max, TEMPER_FLAG_SHOULD_RUN, const int4x2& lhs, const int4x2& rhs, const int4x2& expectedAnswer )
{
	int4x2 actualResult = max( lhs, rhs );
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int4x2_max,
	int4x2(
		1, 1,
		1, 1,
		1, 1,
		1, 1
	),
	int4x2(
		0, 0,
		0, 0,
		0, 0,
		0, 0
	),
	int4x2(
		1, 1,
		1, 1,
		1, 1,
		1, 1
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int4x2_max,
	int4x2(
		2, 2,
		2, 2,
		2, 2,
		2, 2
	),
	int4x2(
		1, 1,
		1, 1,
		1, 1,
		1, 1
	),
	int4x2(
		2, 2,
		2, 2,
		2, 2,
		2, 2
	)
);

TEMPER_PARAMETRIC( Test_int4x2_saturate, TEMPER_FLAG_SHOULD_RUN, const int4x2& x, const int4x2& expectedAnswer )
{
	int4x2 actualResult = saturate( x );
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int4x2_saturate,
	int4x2(
		0, 0,
		0, 0,
		0, 0,
		0, 0
	),
	int4x2(
		0, 0,
		0, 0,
		0, 0,
		0, 0
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int4x2_saturate,
	int4x2(
		1, 1,
		1, 1,
		1, 1,
		1, 1
	),
	int4x2(
		1, 1,
		1, 1,
		1, 1,
		1, 1
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int4x2_saturate,
	int4x2(
		2, 2,
		2, 2,
		2, 2,
		2, 2
	),
	int4x2(
		1, 1,
		1, 1,
		1, 1,
		1, 1
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int4x2_saturate,
	int4x2(
		3, 3,
		3, 3,
		3, 3,
		3, 3
	),
	int4x2(
		1, 1,
		1, 1,
		1, 1,
		1, 1
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int4x2_saturate,
	int4x2(
		10, 10,
		10, 10,
		10, 10,
		10, 10
	),
	int4x2(
		1, 1,
		1, 1,
		1, 1,
		1, 1
	)
);

TEMPER_PARAMETRIC( Test_int4x2_sign, TEMPER_FLAG_SHOULD_RUN, const int4x2& x, const int4x2& expectedAnswer )
{
	int4x2 actualResult = sign( x );
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int4x2_sign,
	int4x2(
		0, 0,
		0, 0,
		0, 0,
		0, 0
	),
	int4x2(
		0, 0,
		0, 0,
		0, 0,
		0, 0
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int4x2_sign,
	int4x2(
		1, 1,
		1, 1,
		1, 1,
		1, 1
	),
	int4x2(
		1, 1,
		1, 1,
		1, 1,
		1, 1
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int4x2_sign,
	int4x2(
		2, 2,
		2, 2,
		2, 2,
		2, 2
	),
	int4x2(
		1, 1,
		1, 1,
		1, 1,
		1, 1
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int4x2_sign,
	int4x2(
		3, 3,
		3, 3,
		3, 3,
		3, 3
	),
	int4x2(
		1, 1,
		1, 1,
		1, 1,
		1, 1
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int4x2_sign,
	int4x2(
		-1, -1,
		-1, -1,
		-1, -1,
		-1, -1
	),
	int4x2(
		-1, -1,
		-1, -1,
		-1, -1,
		-1, -1
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int4x2_sign,
	int4x2(
		-2, -2,
		-2, -2,
		-2, -2,
		-2, -2
	),
	int4x2(
		-1, -1,
		-1, -1,
		-1, -1,
		-1, -1
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int4x2_sign,
	int4x2(
		-3, -3,
		-3, -3,
		-3, -3,
		-3, -3
	),
	int4x2(
		-1, -1,
		-1, -1,
		-1, -1,
		-1, -1
	)
);

TEMPER_PARAMETRIC( Test_int4x2_identity, TEMPER_FLAG_SHOULD_RUN, const int4x2& matrix, const bool expectedAnswer )
{
	int4x2 identityMat;
	identity( identityMat );
	bool isMatrixIdentity = ( identityMat == matrix );
	TEMPER_CHECK_TRUE( isMatrixIdentity == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int4x2_identity,
	int4x2(
		1, 0,
		0, 1,
		0, 0,
		0, 0
	),
	true
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int4x2_identity,
	int4x2(
		1, 1,
		0, 1,
		0, 0,
		0, 0
	),
	false
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int4x2_identity,
	int4x2(
		1, 0,
		1, 1,
		0, 0,
		0, 0
	),
	false
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int4x2_identity,
	int4x2(
		1, 1,
		1, 1,
		0, 0,
		0, 0
	),
	false
);

TEMPER_PARAMETRIC( Test_int4x2_transpose, TEMPER_FLAG_SHOULD_RUN, const int4x2& matrix, const int2x4& expectedAnswer )
{
	int2x4 actualResult = transpose( matrix );
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int4x2_transpose,
	int4x2(
		1, 0,
		0, 1,
		0, 0,
		0, 0
	),
	int2x4(
		1, 0, 0, 0,
		0, 1, 0, 0
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int4x2_transpose,
	int4x2(
		0, 1,
		4, 5,
		8, 9,
		12, 13
	),
	int2x4(
		0, 4, 8, 12,
		1, 5, 9, 13
	)
);

TEMPER_PARAMETRIC( Test_int4x2_mulm, TEMPER_FLAG_SHOULD_RUN, const int4x2& lhs, const int2x4& rhs, const int4x4& expectedAnswer )
{
	int4x4 actualResult = mul( lhs, rhs );
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int4x2_mulm,
	int4x2(
		2, 2,
		2, 2,
		2, 2,
		2, 2
	),
	int2x4(
		4, 4, 4, 4,
		4, 4, 4, 4
	),
	int4x4(
		16, 16, 16, 16,
		16, 16, 16, 16,
		16, 16, 16, 16,
		16, 16, 16, 16
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int4x2_mulm,
	int4x2(
		2, 2,
		2, 2,
		2, 2,
		2, 2
	),
	int2x4(
		1, 0, 0, 0,
		0, 1, 0, 0
	),
	int4x4(
		2, 2, 0, 0,
		2, 2, 0, 0,
		2, 2, 0, 0,
		2, 2, 0, 0
	)
);


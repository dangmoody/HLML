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

TEMPER_PARAMETRIC( Test_double2x4_less_than, TEMPER_FLAG_SHOULD_RUN, const double2x4& lhs, const double2x4& rhs, const bool2x4& expectedAnswer )
{
	bool2x4 actualResult = lhs < rhs;
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x4_less_than,
	double2x4(
		0.000000f, 0.000000f, 0.000000f, 0.000000f,
		0.000000f, 0.000000f, 0.000000f, 0.000000f
	),
	double2x4(
		0.000000f, 0.000000f, 0.000000f, 0.000000f,
		0.000000f, 0.000000f, 0.000000f, 0.000000f
	),
	bool2x4(
		false, false, false, false,
		false, false, false, false
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x4_less_than,
	double2x4(
		0.000000f, 0.000000f, 0.000000f, 0.000000f,
		0.000000f, 0.000000f, 0.000000f, 0.000000f
	),
	double2x4(
		1.000000f, 1.000000f, 1.000000f, 1.000000f,
		1.000000f, 1.000000f, 1.000000f, 1.000000f
	),
	bool2x4(
		true, true, true, true,
		true, true, true, true
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x4_less_than,
	double2x4(
		1.000000f, 1.000000f, 1.000000f, 1.000000f,
		1.000000f, 1.000000f, 1.000000f, 1.000000f
	),
	double2x4(
		1.000000f, 1.000000f, 1.000000f, 1.000000f,
		1.000000f, 1.000000f, 1.000000f, 1.000000f
	),
	bool2x4(
		false, false, false, false,
		false, false, false, false
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x4_less_than,
	double2x4(
		1.000000f, 1.000000f, 1.000000f, 1.000000f,
		1.000000f, 1.000000f, 1.000000f, 1.000000f
	),
	double2x4(
		0.000000f, 0.000000f, 0.000000f, 0.000000f,
		0.000000f, 0.000000f, 0.000000f, 0.000000f
	),
	bool2x4(
		false, false, false, false,
		false, false, false, false
	)
);

TEMPER_PARAMETRIC( Test_double2x4_less_than_equal, TEMPER_FLAG_SHOULD_RUN, const double2x4& lhs, const double2x4& rhs, const bool2x4& expectedAnswer )
{
	bool2x4 actualResult = lhs <= rhs;
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x4_less_than_equal,
	double2x4(
		0.000000f, 0.000000f, 0.000000f, 0.000000f,
		0.000000f, 0.000000f, 0.000000f, 0.000000f
	),
	double2x4(
		0.000000f, 0.000000f, 0.000000f, 0.000000f,
		0.000000f, 0.000000f, 0.000000f, 0.000000f
	),
	bool2x4(
		true, true, true, true,
		true, true, true, true
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x4_less_than_equal,
	double2x4(
		0.000000f, 0.000000f, 0.000000f, 0.000000f,
		0.000000f, 0.000000f, 0.000000f, 0.000000f
	),
	double2x4(
		1.000000f, 1.000000f, 1.000000f, 1.000000f,
		1.000000f, 1.000000f, 1.000000f, 1.000000f
	),
	bool2x4(
		true, true, true, true,
		true, true, true, true
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x4_less_than_equal,
	double2x4(
		1.000000f, 1.000000f, 1.000000f, 1.000000f,
		1.000000f, 1.000000f, 1.000000f, 1.000000f
	),
	double2x4(
		1.000000f, 1.000000f, 1.000000f, 1.000000f,
		1.000000f, 1.000000f, 1.000000f, 1.000000f
	),
	bool2x4(
		true, true, true, true,
		true, true, true, true
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x4_less_than_equal,
	double2x4(
		1.000000f, 1.000000f, 1.000000f, 1.000000f,
		1.000000f, 1.000000f, 1.000000f, 1.000000f
	),
	double2x4(
		0.000000f, 0.000000f, 0.000000f, 0.000000f,
		0.000000f, 0.000000f, 0.000000f, 0.000000f
	),
	bool2x4(
		false, false, false, false,
		false, false, false, false
	)
);

TEMPER_PARAMETRIC( Test_double2x4_greater_than, TEMPER_FLAG_SHOULD_RUN, const double2x4& lhs, const double2x4& rhs, const bool2x4& expectedAnswer )
{
	bool2x4 actualResult = lhs > rhs;
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x4_greater_than,
	double2x4(
		0.000000f, 0.000000f, 0.000000f, 0.000000f,
		0.000000f, 0.000000f, 0.000000f, 0.000000f
	),
	double2x4(
		0.000000f, 0.000000f, 0.000000f, 0.000000f,
		0.000000f, 0.000000f, 0.000000f, 0.000000f
	),
	bool2x4(
		false, false, false, false,
		false, false, false, false
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x4_greater_than,
	double2x4(
		0.000000f, 0.000000f, 0.000000f, 0.000000f,
		0.000000f, 0.000000f, 0.000000f, 0.000000f
	),
	double2x4(
		1.000000f, 1.000000f, 1.000000f, 1.000000f,
		1.000000f, 1.000000f, 1.000000f, 1.000000f
	),
	bool2x4(
		false, false, false, false,
		false, false, false, false
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x4_greater_than,
	double2x4(
		1.000000f, 1.000000f, 1.000000f, 1.000000f,
		1.000000f, 1.000000f, 1.000000f, 1.000000f
	),
	double2x4(
		1.000000f, 1.000000f, 1.000000f, 1.000000f,
		1.000000f, 1.000000f, 1.000000f, 1.000000f
	),
	bool2x4(
		false, false, false, false,
		false, false, false, false
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x4_greater_than,
	double2x4(
		1.000000f, 1.000000f, 1.000000f, 1.000000f,
		1.000000f, 1.000000f, 1.000000f, 1.000000f
	),
	double2x4(
		0.000000f, 0.000000f, 0.000000f, 0.000000f,
		0.000000f, 0.000000f, 0.000000f, 0.000000f
	),
	bool2x4(
		true, true, true, true,
		true, true, true, true
	)
);

TEMPER_PARAMETRIC( Test_double2x4_greater_than_equal, TEMPER_FLAG_SHOULD_RUN, const double2x4& lhs, const double2x4& rhs, const bool2x4& expectedAnswer )
{
	bool2x4 actualResult = lhs >= rhs;
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x4_greater_than_equal,
	double2x4(
		0.000000f, 0.000000f, 0.000000f, 0.000000f,
		0.000000f, 0.000000f, 0.000000f, 0.000000f
	),
	double2x4(
		0.000000f, 0.000000f, 0.000000f, 0.000000f,
		0.000000f, 0.000000f, 0.000000f, 0.000000f
	),
	bool2x4(
		true, true, true, true,
		true, true, true, true
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x4_greater_than_equal,
	double2x4(
		0.000000f, 0.000000f, 0.000000f, 0.000000f,
		0.000000f, 0.000000f, 0.000000f, 0.000000f
	),
	double2x4(
		1.000000f, 1.000000f, 1.000000f, 1.000000f,
		1.000000f, 1.000000f, 1.000000f, 1.000000f
	),
	bool2x4(
		false, false, false, false,
		false, false, false, false
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x4_greater_than_equal,
	double2x4(
		1.000000f, 1.000000f, 1.000000f, 1.000000f,
		1.000000f, 1.000000f, 1.000000f, 1.000000f
	),
	double2x4(
		1.000000f, 1.000000f, 1.000000f, 1.000000f,
		1.000000f, 1.000000f, 1.000000f, 1.000000f
	),
	bool2x4(
		true, true, true, true,
		true, true, true, true
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x4_greater_than_equal,
	double2x4(
		1.000000f, 1.000000f, 1.000000f, 1.000000f,
		1.000000f, 1.000000f, 1.000000f, 1.000000f
	),
	double2x4(
		0.000000f, 0.000000f, 0.000000f, 0.000000f,
		0.000000f, 0.000000f, 0.000000f, 0.000000f
	),
	bool2x4(
		true, true, true, true,
		true, true, true, true
	)
);

TEMPER_PARAMETRIC( Test_double2x4_cadds, TEMPER_FLAG_SHOULD_RUN, const double2x4& lhs, const double& rhs, const double2x4& expectedAnswer )
{
	double2x4 actualResult = lhs + rhs;
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x4_cadds,
	double2x4(
		1.000000f, 1.000000f, 1.000000f, 1.000000f,
		1.000000f, 1.000000f, 1.000000f, 1.000000f
	),
	1.000000f,
	double2x4(
		2.000000f, 2.000000f, 2.000000f, 2.000000f,
		2.000000f, 2.000000f, 2.000000f, 2.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x4_cadds,
	double2x4(
		2.000000f, 2.000000f, 2.000000f, 2.000000f,
		2.000000f, 2.000000f, 2.000000f, 2.000000f
	),
	2.000000f,
	double2x4(
		4.000000f, 4.000000f, 4.000000f, 4.000000f,
		4.000000f, 4.000000f, 4.000000f, 4.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x4_cadds,
	double2x4(
		4.000000f, 4.000000f, 4.000000f, 4.000000f,
		4.000000f, 4.000000f, 4.000000f, 4.000000f
	),
	2.000000f,
	double2x4(
		6.000000f, 6.000000f, 6.000000f, 6.000000f,
		6.000000f, 6.000000f, 6.000000f, 6.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x4_cadds,
	double2x4(
		8.000000f, 8.000000f, 8.000000f, 8.000000f,
		8.000000f, 8.000000f, 8.000000f, 8.000000f
	),
	4.000000f,
	double2x4(
		12.000000f, 12.000000f, 12.000000f, 12.000000f,
		12.000000f, 12.000000f, 12.000000f, 12.000000f
	)
);

TEMPER_PARAMETRIC( Test_double2x4_csubs, TEMPER_FLAG_SHOULD_RUN, const double2x4& lhs, const double& rhs, const double2x4& expectedAnswer )
{
	double2x4 actualResult = lhs - rhs;
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x4_csubs,
	double2x4(
		1.000000f, 1.000000f, 1.000000f, 1.000000f,
		1.000000f, 1.000000f, 1.000000f, 1.000000f
	),
	1.000000f,
	double2x4(
		0.000000f, 0.000000f, 0.000000f, 0.000000f,
		0.000000f, 0.000000f, 0.000000f, 0.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x4_csubs,
	double2x4(
		2.000000f, 2.000000f, 2.000000f, 2.000000f,
		2.000000f, 2.000000f, 2.000000f, 2.000000f
	),
	2.000000f,
	double2x4(
		0.000000f, 0.000000f, 0.000000f, 0.000000f,
		0.000000f, 0.000000f, 0.000000f, 0.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x4_csubs,
	double2x4(
		4.000000f, 4.000000f, 4.000000f, 4.000000f,
		4.000000f, 4.000000f, 4.000000f, 4.000000f
	),
	2.000000f,
	double2x4(
		2.000000f, 2.000000f, 2.000000f, 2.000000f,
		2.000000f, 2.000000f, 2.000000f, 2.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x4_csubs,
	double2x4(
		8.000000f, 8.000000f, 8.000000f, 8.000000f,
		8.000000f, 8.000000f, 8.000000f, 8.000000f
	),
	4.000000f,
	double2x4(
		4.000000f, 4.000000f, 4.000000f, 4.000000f,
		4.000000f, 4.000000f, 4.000000f, 4.000000f
	)
);

TEMPER_PARAMETRIC( Test_double2x4_cmuls, TEMPER_FLAG_SHOULD_RUN, const double2x4& lhs, const double& rhs, const double2x4& expectedAnswer )
{
	double2x4 actualResult = lhs * rhs;
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x4_cmuls,
	double2x4(
		1.000000f, 1.000000f, 1.000000f, 1.000000f,
		1.000000f, 1.000000f, 1.000000f, 1.000000f
	),
	1.000000f,
	double2x4(
		1.000000f, 1.000000f, 1.000000f, 1.000000f,
		1.000000f, 1.000000f, 1.000000f, 1.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x4_cmuls,
	double2x4(
		2.000000f, 2.000000f, 2.000000f, 2.000000f,
		2.000000f, 2.000000f, 2.000000f, 2.000000f
	),
	2.000000f,
	double2x4(
		4.000000f, 4.000000f, 4.000000f, 4.000000f,
		4.000000f, 4.000000f, 4.000000f, 4.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x4_cmuls,
	double2x4(
		4.000000f, 4.000000f, 4.000000f, 4.000000f,
		4.000000f, 4.000000f, 4.000000f, 4.000000f
	),
	2.000000f,
	double2x4(
		8.000000f, 8.000000f, 8.000000f, 8.000000f,
		8.000000f, 8.000000f, 8.000000f, 8.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x4_cmuls,
	double2x4(
		8.000000f, 8.000000f, 8.000000f, 8.000000f,
		8.000000f, 8.000000f, 8.000000f, 8.000000f
	),
	4.000000f,
	double2x4(
		32.000000f, 32.000000f, 32.000000f, 32.000000f,
		32.000000f, 32.000000f, 32.000000f, 32.000000f
	)
);

TEMPER_PARAMETRIC( Test_double2x4_cdivs, TEMPER_FLAG_SHOULD_RUN, const double2x4& lhs, const double& rhs, const double2x4& expectedAnswer )
{
	double2x4 actualResult = lhs / rhs;
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x4_cdivs,
	double2x4(
		1.000000f, 1.000000f, 1.000000f, 1.000000f,
		1.000000f, 1.000000f, 1.000000f, 1.000000f
	),
	1.000000f,
	double2x4(
		1.000000f, 1.000000f, 1.000000f, 1.000000f,
		1.000000f, 1.000000f, 1.000000f, 1.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x4_cdivs,
	double2x4(
		2.000000f, 2.000000f, 2.000000f, 2.000000f,
		2.000000f, 2.000000f, 2.000000f, 2.000000f
	),
	2.000000f,
	double2x4(
		1.000000f, 1.000000f, 1.000000f, 1.000000f,
		1.000000f, 1.000000f, 1.000000f, 1.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x4_cdivs,
	double2x4(
		4.000000f, 4.000000f, 4.000000f, 4.000000f,
		4.000000f, 4.000000f, 4.000000f, 4.000000f
	),
	2.000000f,
	double2x4(
		2.000000f, 2.000000f, 2.000000f, 2.000000f,
		2.000000f, 2.000000f, 2.000000f, 2.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x4_cdivs,
	double2x4(
		8.000000f, 8.000000f, 8.000000f, 8.000000f,
		8.000000f, 8.000000f, 8.000000f, 8.000000f
	),
	4.000000f,
	double2x4(
		2.000000f, 2.000000f, 2.000000f, 2.000000f,
		2.000000f, 2.000000f, 2.000000f, 2.000000f
	)
);

TEMPER_PARAMETRIC( Test_double2x4_caddm, TEMPER_FLAG_SHOULD_RUN, const double2x4& lhs, const double2x4& rhs, const double2x4& expectedAnswer )
{
	double2x4 actualResult = lhs + rhs;
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x4_caddm,
	double2x4(
		1.000000f, 1.000000f, 1.000000f, 1.000000f,
		1.000000f, 1.000000f, 1.000000f, 1.000000f
	),
	double2x4(
		1.000000f, 1.000000f, 1.000000f, 1.000000f,
		1.000000f, 1.000000f, 1.000000f, 1.000000f
	),
	double2x4(
		2.000000f, 2.000000f, 2.000000f, 2.000000f,
		2.000000f, 2.000000f, 2.000000f, 2.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x4_caddm,
	double2x4(
		2.000000f, 2.000000f, 2.000000f, 2.000000f,
		2.000000f, 2.000000f, 2.000000f, 2.000000f
	),
	double2x4(
		2.000000f, 2.000000f, 2.000000f, 2.000000f,
		2.000000f, 2.000000f, 2.000000f, 2.000000f
	),
	double2x4(
		4.000000f, 4.000000f, 4.000000f, 4.000000f,
		4.000000f, 4.000000f, 4.000000f, 4.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x4_caddm,
	double2x4(
		4.000000f, 4.000000f, 4.000000f, 4.000000f,
		4.000000f, 4.000000f, 4.000000f, 4.000000f
	),
	double2x4(
		2.000000f, 2.000000f, 2.000000f, 2.000000f,
		2.000000f, 2.000000f, 2.000000f, 2.000000f
	),
	double2x4(
		6.000000f, 6.000000f, 6.000000f, 6.000000f,
		6.000000f, 6.000000f, 6.000000f, 6.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x4_caddm,
	double2x4(
		8.000000f, 8.000000f, 8.000000f, 8.000000f,
		8.000000f, 8.000000f, 8.000000f, 8.000000f
	),
	double2x4(
		4.000000f, 4.000000f, 4.000000f, 4.000000f,
		4.000000f, 4.000000f, 4.000000f, 4.000000f
	),
	double2x4(
		12.000000f, 12.000000f, 12.000000f, 12.000000f,
		12.000000f, 12.000000f, 12.000000f, 12.000000f
	)
);

TEMPER_PARAMETRIC( Test_double2x4_csubm, TEMPER_FLAG_SHOULD_RUN, const double2x4& lhs, const double2x4& rhs, const double2x4& expectedAnswer )
{
	double2x4 actualResult = lhs - rhs;
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x4_csubm,
	double2x4(
		1.000000f, 1.000000f, 1.000000f, 1.000000f,
		1.000000f, 1.000000f, 1.000000f, 1.000000f
	),
	double2x4(
		1.000000f, 1.000000f, 1.000000f, 1.000000f,
		1.000000f, 1.000000f, 1.000000f, 1.000000f
	),
	double2x4(
		0.000000f, 0.000000f, 0.000000f, 0.000000f,
		0.000000f, 0.000000f, 0.000000f, 0.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x4_csubm,
	double2x4(
		2.000000f, 2.000000f, 2.000000f, 2.000000f,
		2.000000f, 2.000000f, 2.000000f, 2.000000f
	),
	double2x4(
		2.000000f, 2.000000f, 2.000000f, 2.000000f,
		2.000000f, 2.000000f, 2.000000f, 2.000000f
	),
	double2x4(
		0.000000f, 0.000000f, 0.000000f, 0.000000f,
		0.000000f, 0.000000f, 0.000000f, 0.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x4_csubm,
	double2x4(
		4.000000f, 4.000000f, 4.000000f, 4.000000f,
		4.000000f, 4.000000f, 4.000000f, 4.000000f
	),
	double2x4(
		2.000000f, 2.000000f, 2.000000f, 2.000000f,
		2.000000f, 2.000000f, 2.000000f, 2.000000f
	),
	double2x4(
		2.000000f, 2.000000f, 2.000000f, 2.000000f,
		2.000000f, 2.000000f, 2.000000f, 2.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x4_csubm,
	double2x4(
		8.000000f, 8.000000f, 8.000000f, 8.000000f,
		8.000000f, 8.000000f, 8.000000f, 8.000000f
	),
	double2x4(
		4.000000f, 4.000000f, 4.000000f, 4.000000f,
		4.000000f, 4.000000f, 4.000000f, 4.000000f
	),
	double2x4(
		4.000000f, 4.000000f, 4.000000f, 4.000000f,
		4.000000f, 4.000000f, 4.000000f, 4.000000f
	)
);

TEMPER_PARAMETRIC( Test_double2x4_cmulm, TEMPER_FLAG_SHOULD_RUN, const double2x4& lhs, const double2x4& rhs, const double2x4& expectedAnswer )
{
	double2x4 actualResult = lhs * rhs;
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x4_cmulm,
	double2x4(
		1.000000f, 1.000000f, 1.000000f, 1.000000f,
		1.000000f, 1.000000f, 1.000000f, 1.000000f
	),
	double2x4(
		1.000000f, 1.000000f, 1.000000f, 1.000000f,
		1.000000f, 1.000000f, 1.000000f, 1.000000f
	),
	double2x4(
		1.000000f, 1.000000f, 1.000000f, 1.000000f,
		1.000000f, 1.000000f, 1.000000f, 1.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x4_cmulm,
	double2x4(
		2.000000f, 2.000000f, 2.000000f, 2.000000f,
		2.000000f, 2.000000f, 2.000000f, 2.000000f
	),
	double2x4(
		2.000000f, 2.000000f, 2.000000f, 2.000000f,
		2.000000f, 2.000000f, 2.000000f, 2.000000f
	),
	double2x4(
		4.000000f, 4.000000f, 4.000000f, 4.000000f,
		4.000000f, 4.000000f, 4.000000f, 4.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x4_cmulm,
	double2x4(
		4.000000f, 4.000000f, 4.000000f, 4.000000f,
		4.000000f, 4.000000f, 4.000000f, 4.000000f
	),
	double2x4(
		2.000000f, 2.000000f, 2.000000f, 2.000000f,
		2.000000f, 2.000000f, 2.000000f, 2.000000f
	),
	double2x4(
		8.000000f, 8.000000f, 8.000000f, 8.000000f,
		8.000000f, 8.000000f, 8.000000f, 8.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x4_cmulm,
	double2x4(
		8.000000f, 8.000000f, 8.000000f, 8.000000f,
		8.000000f, 8.000000f, 8.000000f, 8.000000f
	),
	double2x4(
		4.000000f, 4.000000f, 4.000000f, 4.000000f,
		4.000000f, 4.000000f, 4.000000f, 4.000000f
	),
	double2x4(
		32.000000f, 32.000000f, 32.000000f, 32.000000f,
		32.000000f, 32.000000f, 32.000000f, 32.000000f
	)
);

TEMPER_PARAMETRIC( Test_double2x4_cdivm, TEMPER_FLAG_SHOULD_RUN, const double2x4& lhs, const double2x4& rhs, const double2x4& expectedAnswer )
{
	double2x4 actualResult = lhs / rhs;
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x4_cdivm,
	double2x4(
		1.000000f, 1.000000f, 1.000000f, 1.000000f,
		1.000000f, 1.000000f, 1.000000f, 1.000000f
	),
	double2x4(
		1.000000f, 1.000000f, 1.000000f, 1.000000f,
		1.000000f, 1.000000f, 1.000000f, 1.000000f
	),
	double2x4(
		1.000000f, 1.000000f, 1.000000f, 1.000000f,
		1.000000f, 1.000000f, 1.000000f, 1.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x4_cdivm,
	double2x4(
		2.000000f, 2.000000f, 2.000000f, 2.000000f,
		2.000000f, 2.000000f, 2.000000f, 2.000000f
	),
	double2x4(
		2.000000f, 2.000000f, 2.000000f, 2.000000f,
		2.000000f, 2.000000f, 2.000000f, 2.000000f
	),
	double2x4(
		1.000000f, 1.000000f, 1.000000f, 1.000000f,
		1.000000f, 1.000000f, 1.000000f, 1.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x4_cdivm,
	double2x4(
		4.000000f, 4.000000f, 4.000000f, 4.000000f,
		4.000000f, 4.000000f, 4.000000f, 4.000000f
	),
	double2x4(
		2.000000f, 2.000000f, 2.000000f, 2.000000f,
		2.000000f, 2.000000f, 2.000000f, 2.000000f
	),
	double2x4(
		2.000000f, 2.000000f, 2.000000f, 2.000000f,
		2.000000f, 2.000000f, 2.000000f, 2.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x4_cdivm,
	double2x4(
		8.000000f, 8.000000f, 8.000000f, 8.000000f,
		8.000000f, 8.000000f, 8.000000f, 8.000000f
	),
	double2x4(
		4.000000f, 4.000000f, 4.000000f, 4.000000f,
		4.000000f, 4.000000f, 4.000000f, 4.000000f
	),
	double2x4(
		2.000000f, 2.000000f, 2.000000f, 2.000000f,
		2.000000f, 2.000000f, 2.000000f, 2.000000f
	)
);

#if defined( __GNUC__ ) || defined( __clang__ )
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wcast-qual"
#endif

TEMPER_PARAMETRIC( Test_double2x4_increment_prefix, TEMPER_FLAG_SHOULD_RUN, const double2x4& x, const double2x4& expectedAnswer )
{
	// make local copy of x and use that because we cant do increment or decrement operations on a const reference
	// and MSVC throws warnings if we just make the parameter a non-const reference
	double2x4 xlocal = (double2x4) x;
	double2x4 actualAnswer = ++xlocal;
	TEMPER_CHECK_TRUE( actualAnswer == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x4_increment_prefix,
	double2x4(
		1.000000f, 1.000000f, 1.000000f, 1.000000f,
		1.000000f, 1.000000f, 1.000000f, 1.000000f
	),
	double2x4(
		2.000000f, 2.000000f, 2.000000f, 2.000000f,
		2.000000f, 2.000000f, 2.000000f, 2.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x4_increment_prefix,
	double2x4(
		2.000000f, 2.000000f, 2.000000f, 2.000000f,
		2.000000f, 2.000000f, 2.000000f, 2.000000f
	),
	double2x4(
		3.000000f, 3.000000f, 3.000000f, 3.000000f,
		3.000000f, 3.000000f, 3.000000f, 3.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x4_increment_prefix,
	double2x4(
		3.000000f, 3.000000f, 3.000000f, 3.000000f,
		3.000000f, 3.000000f, 3.000000f, 3.000000f
	),
	double2x4(
		4.000000f, 4.000000f, 4.000000f, 4.000000f,
		4.000000f, 4.000000f, 4.000000f, 4.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x4_increment_prefix,
	double2x4(
		4.000000f, 4.000000f, 4.000000f, 4.000000f,
		4.000000f, 4.000000f, 4.000000f, 4.000000f
	),
	double2x4(
		5.000000f, 5.000000f, 5.000000f, 5.000000f,
		5.000000f, 5.000000f, 5.000000f, 5.000000f
	)
);

TEMPER_PARAMETRIC( Test_double2x4_increment_postfix, TEMPER_FLAG_SHOULD_RUN, const double2x4& x, const double2x4& expectedAnswer )
{
	// make local copy of x and use that because we cant do increment or decrement operations on a const reference
	// and MSVC throws warnings if we just make the parameter a non-const reference
	double2x4 xlocal = (double2x4) x;
	double2x4 actualAnswer = xlocal++;
	TEMPER_CHECK_TRUE( actualAnswer == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x4_increment_postfix,
	double2x4(
		1.000000f, 1.000000f, 1.000000f, 1.000000f,
		1.000000f, 1.000000f, 1.000000f, 1.000000f
	),
	double2x4(
		2.000000f, 2.000000f, 2.000000f, 2.000000f,
		2.000000f, 2.000000f, 2.000000f, 2.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x4_increment_postfix,
	double2x4(
		2.000000f, 2.000000f, 2.000000f, 2.000000f,
		2.000000f, 2.000000f, 2.000000f, 2.000000f
	),
	double2x4(
		3.000000f, 3.000000f, 3.000000f, 3.000000f,
		3.000000f, 3.000000f, 3.000000f, 3.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x4_increment_postfix,
	double2x4(
		3.000000f, 3.000000f, 3.000000f, 3.000000f,
		3.000000f, 3.000000f, 3.000000f, 3.000000f
	),
	double2x4(
		4.000000f, 4.000000f, 4.000000f, 4.000000f,
		4.000000f, 4.000000f, 4.000000f, 4.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x4_increment_postfix,
	double2x4(
		4.000000f, 4.000000f, 4.000000f, 4.000000f,
		4.000000f, 4.000000f, 4.000000f, 4.000000f
	),
	double2x4(
		5.000000f, 5.000000f, 5.000000f, 5.000000f,
		5.000000f, 5.000000f, 5.000000f, 5.000000f
	)
);

TEMPER_PARAMETRIC( Test_double2x4_decrement_prefix, TEMPER_FLAG_SHOULD_RUN, const double2x4& x, const double2x4& expectedAnswer )
{
	// make local copy of x and use that because we cant do increment or decrement operations on a const reference
	// and MSVC throws warnings if we just make the parameter a non-const reference
	double2x4 xlocal = (double2x4) x;
	double2x4 actualAnswer = --xlocal;
	TEMPER_CHECK_TRUE( actualAnswer == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x4_decrement_prefix,
	double2x4(
		1.000000f, 1.000000f, 1.000000f, 1.000000f,
		1.000000f, 1.000000f, 1.000000f, 1.000000f
	),
	double2x4(
		0.000000f, 0.000000f, 0.000000f, 0.000000f,
		0.000000f, 0.000000f, 0.000000f, 0.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x4_decrement_prefix,
	double2x4(
		2.000000f, 2.000000f, 2.000000f, 2.000000f,
		2.000000f, 2.000000f, 2.000000f, 2.000000f
	),
	double2x4(
		1.000000f, 1.000000f, 1.000000f, 1.000000f,
		1.000000f, 1.000000f, 1.000000f, 1.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x4_decrement_prefix,
	double2x4(
		3.000000f, 3.000000f, 3.000000f, 3.000000f,
		3.000000f, 3.000000f, 3.000000f, 3.000000f
	),
	double2x4(
		2.000000f, 2.000000f, 2.000000f, 2.000000f,
		2.000000f, 2.000000f, 2.000000f, 2.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x4_decrement_prefix,
	double2x4(
		4.000000f, 4.000000f, 4.000000f, 4.000000f,
		4.000000f, 4.000000f, 4.000000f, 4.000000f
	),
	double2x4(
		3.000000f, 3.000000f, 3.000000f, 3.000000f,
		3.000000f, 3.000000f, 3.000000f, 3.000000f
	)
);

TEMPER_PARAMETRIC( Test_double2x4_decrement_postfix, TEMPER_FLAG_SHOULD_RUN, const double2x4& x, const double2x4& expectedAnswer )
{
	// make local copy of x and use that because we cant do increment or decrement operations on a const reference
	// and MSVC throws warnings if we just make the parameter a non-const reference
	double2x4 xlocal = (double2x4) x;
	double2x4 actualAnswer = xlocal--;
	TEMPER_CHECK_TRUE( actualAnswer == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x4_decrement_postfix,
	double2x4(
		1.000000f, 1.000000f, 1.000000f, 1.000000f,
		1.000000f, 1.000000f, 1.000000f, 1.000000f
	),
	double2x4(
		0.000000f, 0.000000f, 0.000000f, 0.000000f,
		0.000000f, 0.000000f, 0.000000f, 0.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x4_decrement_postfix,
	double2x4(
		2.000000f, 2.000000f, 2.000000f, 2.000000f,
		2.000000f, 2.000000f, 2.000000f, 2.000000f
	),
	double2x4(
		1.000000f, 1.000000f, 1.000000f, 1.000000f,
		1.000000f, 1.000000f, 1.000000f, 1.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x4_decrement_postfix,
	double2x4(
		3.000000f, 3.000000f, 3.000000f, 3.000000f,
		3.000000f, 3.000000f, 3.000000f, 3.000000f
	),
	double2x4(
		2.000000f, 2.000000f, 2.000000f, 2.000000f,
		2.000000f, 2.000000f, 2.000000f, 2.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x4_decrement_postfix,
	double2x4(
		4.000000f, 4.000000f, 4.000000f, 4.000000f,
		4.000000f, 4.000000f, 4.000000f, 4.000000f
	),
	double2x4(
		3.000000f, 3.000000f, 3.000000f, 3.000000f,
		3.000000f, 3.000000f, 3.000000f, 3.000000f
	)
);

#if defined( __GNUC__ ) || defined( __clang__ )
#pragma GCC diagnostic pop
#endif
TEMPER_PARAMETRIC( Test_double2x4_min, TEMPER_FLAG_SHOULD_RUN, const double2x4& lhs, const double2x4& rhs, const double2x4& expectedAnswer )
{
	double2x4 actualResult = min( lhs, rhs );
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x4_min,
	double2x4(
		0.000000f, 0.000000f, 0.000000f, 0.000000f,
		0.000000f, 0.000000f, 0.000000f, 0.000000f
	),
	double2x4(
		1.000000f, 1.000000f, 1.000000f, 1.000000f,
		1.000000f, 1.000000f, 1.000000f, 1.000000f
	),
	double2x4(
		0.000000f, 0.000000f, 0.000000f, 0.000000f,
		0.000000f, 0.000000f, 0.000000f, 0.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x4_min,
	double2x4(
		1.000000f, 1.000000f, 1.000000f, 1.000000f,
		1.000000f, 1.000000f, 1.000000f, 1.000000f
	),
	double2x4(
		2.000000f, 2.000000f, 2.000000f, 2.000000f,
		2.000000f, 2.000000f, 2.000000f, 2.000000f
	),
	double2x4(
		1.000000f, 1.000000f, 1.000000f, 1.000000f,
		1.000000f, 1.000000f, 1.000000f, 1.000000f
	)
);

TEMPER_PARAMETRIC( Test_double2x4_max, TEMPER_FLAG_SHOULD_RUN, const double2x4& lhs, const double2x4& rhs, const double2x4& expectedAnswer )
{
	double2x4 actualResult = max( lhs, rhs );
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x4_max,
	double2x4(
		1.000000f, 1.000000f, 1.000000f, 1.000000f,
		1.000000f, 1.000000f, 1.000000f, 1.000000f
	),
	double2x4(
		0.000000f, 0.000000f, 0.000000f, 0.000000f,
		0.000000f, 0.000000f, 0.000000f, 0.000000f
	),
	double2x4(
		1.000000f, 1.000000f, 1.000000f, 1.000000f,
		1.000000f, 1.000000f, 1.000000f, 1.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x4_max,
	double2x4(
		2.000000f, 2.000000f, 2.000000f, 2.000000f,
		2.000000f, 2.000000f, 2.000000f, 2.000000f
	),
	double2x4(
		1.000000f, 1.000000f, 1.000000f, 1.000000f,
		1.000000f, 1.000000f, 1.000000f, 1.000000f
	),
	double2x4(
		2.000000f, 2.000000f, 2.000000f, 2.000000f,
		2.000000f, 2.000000f, 2.000000f, 2.000000f
	)
);

TEMPER_PARAMETRIC( Test_double2x4_saturate, TEMPER_FLAG_SHOULD_RUN, const double2x4& x, const double2x4& expectedAnswer )
{
	double2x4 actualResult = saturate( x );
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x4_saturate,
	double2x4(
		0.000000f, 0.000000f, 0.000000f, 0.000000f,
		0.000000f, 0.000000f, 0.000000f, 0.000000f
	),
	double2x4(
		0.000000f, 0.000000f, 0.000000f, 0.000000f,
		0.000000f, 0.000000f, 0.000000f, 0.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x4_saturate,
	double2x4(
		1.000000f, 1.000000f, 1.000000f, 1.000000f,
		1.000000f, 1.000000f, 1.000000f, 1.000000f
	),
	double2x4(
		1.000000f, 1.000000f, 1.000000f, 1.000000f,
		1.000000f, 1.000000f, 1.000000f, 1.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x4_saturate,
	double2x4(
		2.000000f, 2.000000f, 2.000000f, 2.000000f,
		2.000000f, 2.000000f, 2.000000f, 2.000000f
	),
	double2x4(
		1.000000f, 1.000000f, 1.000000f, 1.000000f,
		1.000000f, 1.000000f, 1.000000f, 1.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x4_saturate,
	double2x4(
		3.000000f, 3.000000f, 3.000000f, 3.000000f,
		3.000000f, 3.000000f, 3.000000f, 3.000000f
	),
	double2x4(
		1.000000f, 1.000000f, 1.000000f, 1.000000f,
		1.000000f, 1.000000f, 1.000000f, 1.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x4_saturate,
	double2x4(
		10.000000f, 10.000000f, 10.000000f, 10.000000f,
		10.000000f, 10.000000f, 10.000000f, 10.000000f
	),
	double2x4(
		1.000000f, 1.000000f, 1.000000f, 1.000000f,
		1.000000f, 1.000000f, 1.000000f, 1.000000f
	)
);

TEMPER_PARAMETRIC( Test_double2x4_sign, TEMPER_FLAG_SHOULD_RUN, const double2x4& x, const int2x4& expectedAnswer )
{
	int2x4 actualResult = sign( x );
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x4_sign,
	double2x4(
		0.000000f, 0.000000f, 0.000000f, 0.000000f,
		0.000000f, 0.000000f, 0.000000f, 0.000000f
	),
	int2x4(
		0, 0, 0, 0,
		0, 0, 0, 0
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x4_sign,
	double2x4(
		1.000000f, 1.000000f, 1.000000f, 1.000000f,
		1.000000f, 1.000000f, 1.000000f, 1.000000f
	),
	int2x4(
		1, 1, 1, 1,
		1, 1, 1, 1
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x4_sign,
	double2x4(
		2.000000f, 2.000000f, 2.000000f, 2.000000f,
		2.000000f, 2.000000f, 2.000000f, 2.000000f
	),
	int2x4(
		1, 1, 1, 1,
		1, 1, 1, 1
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x4_sign,
	double2x4(
		3.000000f, 3.000000f, 3.000000f, 3.000000f,
		3.000000f, 3.000000f, 3.000000f, 3.000000f
	),
	int2x4(
		1, 1, 1, 1,
		1, 1, 1, 1
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x4_sign,
	double2x4(
		-1.000000f, -1.000000f, -1.000000f, -1.000000f,
		-1.000000f, -1.000000f, -1.000000f, -1.000000f
	),
	int2x4(
		-1, -1, -1, -1,
		-1, -1, -1, -1
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x4_sign,
	double2x4(
		-2.000000f, -2.000000f, -2.000000f, -2.000000f,
		-2.000000f, -2.000000f, -2.000000f, -2.000000f
	),
	int2x4(
		-1, -1, -1, -1,
		-1, -1, -1, -1
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x4_sign,
	double2x4(
		-3.000000f, -3.000000f, -3.000000f, -3.000000f,
		-3.000000f, -3.000000f, -3.000000f, -3.000000f
	),
	int2x4(
		-1, -1, -1, -1,
		-1, -1, -1, -1
	)
);

TEMPER_PARAMETRIC( Test_double2x4_lerp, TEMPER_FLAG_SHOULD_RUN, const double2x4& lhs, const double2x4& rhs, const double t, const double2x4& expectedAnswer )
{
	double2x4 actualResult = lerp( lhs, rhs, t );
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x4_lerp,
	double2x4(
		0.000000f, 0.000000f, 0.000000f, 0.000000f,
		0.000000f, 0.000000f, 0.000000f, 0.000000f
	),
	double2x4(
		1.000000f, 1.000000f, 1.000000f, 1.000000f,
		1.000000f, 1.000000f, 1.000000f, 1.000000f
	),
	0.500000f,
	double2x4(
		0.500000f, 0.500000f, 0.500000f, 0.500000f,
		0.500000f, 0.500000f, 0.500000f, 0.500000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x4_lerp,
	double2x4(
		1.000000f, 1.000000f, 1.000000f, 1.000000f,
		1.000000f, 1.000000f, 1.000000f, 1.000000f
	),
	double2x4(
		3.000000f, 3.000000f, 3.000000f, 3.000000f,
		3.000000f, 3.000000f, 3.000000f, 3.000000f
	),
	0.500000f,
	double2x4(
		2.000000f, 2.000000f, 2.000000f, 2.000000f,
		2.000000f, 2.000000f, 2.000000f, 2.000000f
	)
);

TEMPER_PARAMETRIC( Test_double2x4_identity, TEMPER_FLAG_SHOULD_RUN, const double2x4& matrix, const bool expectedAnswer )
{
	double2x4 identityMat;
	identity( identityMat );
	bool isMatrixIdentity = ( identityMat == matrix );
	TEMPER_CHECK_TRUE( isMatrixIdentity == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x4_identity,
	double2x4(
		1.000000f, 0.000000f, 0.000000f, 0.000000f,
		0.000000f, 1.000000f, 0.000000f, 0.000000f
	),
	true
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x4_identity,
	double2x4(
		1.000000f, 1.000000f, 0.000000f, 0.000000f,
		0.000000f, 1.000000f, 0.000000f, 0.000000f
	),
	false
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x4_identity,
	double2x4(
		1.000000f, 0.000000f, 0.000000f, 0.000000f,
		1.000000f, 1.000000f, 0.000000f, 0.000000f
	),
	false
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x4_identity,
	double2x4(
		1.000000f, 1.000000f, 0.000000f, 0.000000f,
		1.000000f, 1.000000f, 0.000000f, 0.000000f
	),
	false
);

TEMPER_PARAMETRIC( Test_double2x4_transpose, TEMPER_FLAG_SHOULD_RUN, const double2x4& matrix, const double4x2& expectedAnswer )
{
	double4x2 actualResult = transpose( matrix );
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x4_transpose,
	double2x4(
		1.000000f, 0.000000f, 0.000000f, 0.000000f,
		0.000000f, 1.000000f, 0.000000f, 0.000000f
	),
	double4x2(
		1.000000f, 0.000000f,
		0.000000f, 1.000000f,
		0.000000f, 0.000000f,
		0.000000f, 0.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x4_transpose,
	double2x4(
		0.000000f, 1.000000f, 2.000000f, 3.000000f,
		4.000000f, 5.000000f, 6.000000f, 7.000000f
	),
	double4x2(
		0.000000f, 4.000000f,
		1.000000f, 5.000000f,
		2.000000f, 6.000000f,
		3.000000f, 7.000000f
	)
);

TEMPER_PARAMETRIC( Test_double2x4_mulm, TEMPER_FLAG_SHOULD_RUN, const double2x4& lhs, const double4x2& rhs, const double2x2& expectedAnswer )
{
	double2x2 actualResult = mul( lhs, rhs );
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x4_mulm,
	double2x4(
		2.000000f, 2.000000f, 2.000000f, 2.000000f,
		2.000000f, 2.000000f, 2.000000f, 2.000000f
	),
	double4x2(
		4.000000f, 4.000000f,
		4.000000f, 4.000000f,
		4.000000f, 4.000000f,
		4.000000f, 4.000000f
	),
	double2x2(
		32.000000f, 32.000000f,
		32.000000f, 32.000000f
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_double2x4_mulm,
	double2x4(
		2.000000f, 2.000000f, 2.000000f, 2.000000f,
		2.000000f, 2.000000f, 2.000000f, 2.000000f
	),
	double4x2(
		1.000000f, 0.000000f,
		0.000000f, 1.000000f,
		0.000000f, 0.000000f,
		0.000000f, 0.000000f
	),
	double2x2(
		2.000000f, 2.000000f,
		2.000000f, 2.000000f
	)
);


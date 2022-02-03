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

TEMPER_PARAMETRIC( Test_bool4_bool4_all, TEMPER_FLAG_SHOULD_RUN, const bool4* x, const bool32_t expectedAnswer )
{
	bool32_t actualResult = bool4_bool4_all( x );
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool4_bool4_all,
	&(bool4) { true, true, true, true },
	true
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool4_bool4_all,
	&(bool4) { true, false, false, false },
	false
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool4_bool4_all,
	&(bool4) { false, true, true, true },
	false
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool4_bool4_all,
	&(bool4) { false, true, false, true },
	false
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool4_bool4_all,
	&(bool4) { false, false, false, false },
	false
);

TEMPER_PARAMETRIC( Test_bool4_bool4_any, TEMPER_FLAG_SHOULD_RUN, const bool4* x, const bool32_t expectedAnswer )
{
	bool32_t actualResult = bool4_bool4_any( x );
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool4_bool4_any,
	&(bool4) { true, true, true, true },
	true
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool4_bool4_any,
	&(bool4) { true, false, false, false },
	true
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool4_bool4_any,
	&(bool4) { false, true, true, true },
	true
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool4_bool4_any,
	&(bool4) { false, true, false, true },
	true
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool4_bool4_any,
	&(bool4) { false, false, false, false },
	false
);

TEMPER_PARAMETRIC( Test_bool4_lengthsq, TEMPER_FLAG_SHOULD_RUN, const bool4* vec, const float expectedAnswer )
{
	float actualResult = bool4_lengthsq( vec );
	TEMPER_CHECK_TRUE( floateq( actualResult, expectedAnswer ) );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool4_lengthsq,
	&(bool4) { false, false, false, false },
	0.000000f
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool4_lengthsq,
	&(bool4) { true, true, true, true },
	4.000000f
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool4_lengthsq,
	&(bool4) { true, true, true, true },
	16.000000f
);

TEMPER_PARAMETRIC( Test_bool4_length, TEMPER_FLAG_SHOULD_RUN, const bool4* vec, const float expectedAnswer )
{
	float actualResult = bool4_length( vec );
	TEMPER_CHECK_TRUE( floateq( actualResult, expectedAnswer ) );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool4_length,
	&(bool4) { false, false, false, false },
	0.000000f
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool4_length,
	&(bool4) { true, true, true, true },
	2.000000f
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool4_length,
	&(bool4) { true, true, true, true },
	4.000000f
);

TEMPER_PARAMETRIC( Test_bool4_dot, TEMPER_FLAG_SHOULD_RUN, const bool4* lhs, const bool4* rhs, const bool32_t expectedAnswer )
{
	bool32_t actualResult = bool4_dot( lhs, rhs );
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool4_dot,
	&(bool4) { false, false, false, false },
	&(bool4) { true, true, true, true },
	false
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool4_dot,
	&(bool4) { true, true, true, true },
	&(bool4) { true, true, true, true },
	true
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool4_dot,
	&(bool4) { true, true, true, true },
	&(bool4) { true, true, true, true },
	true
);


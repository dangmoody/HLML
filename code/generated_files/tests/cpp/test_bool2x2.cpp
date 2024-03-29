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

TEMPER_TEST_PARAMETRIC( Test_bool2x2_all, TEMPER_FLAG_SHOULD_RUN, const bool2x2& x, const bool32_t expectedAnswer )
{
	bool32_t actualResult = all( x );
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool2x2_all,
	bool2x2(
		true, true,
		true, true
	),
	true
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool2x2_all,
	bool2x2(
		true, false,
		false, false
	),
	false
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool2x2_all,
	bool2x2(
		false, true,
		true, true
	),
	false
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool2x2_all,
	bool2x2(
		false, true,
		true, false
	),
	false
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool2x2_all,
	bool2x2(
		false, false,
		false, false
	),
	false
);

TEMPER_TEST_PARAMETRIC( Test_bool2x2_any, TEMPER_FLAG_SHOULD_RUN, const bool2x2& x, const bool32_t expectedAnswer )
{
	bool32_t actualResult = any( x );
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool2x2_any,
	bool2x2(
		true, true,
		true, true
	),
	true
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool2x2_any,
	bool2x2(
		true, false,
		false, false
	),
	true
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool2x2_any,
	bool2x2(
		false, true,
		true, true
	),
	true
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool2x2_any,
	bool2x2(
		false, true,
		true, false
	),
	true
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool2x2_any,
	bool2x2(
		false, false,
		false, false
	),
	false
);

TEMPER_TEST_PARAMETRIC( Test_bool2x2_int2x2, TEMPER_FLAG_SHOULD_RUN, const int2x2& convertFrom, const bool2x2& expectedAnswer )
{
	bool2x2 actualAnswer = bool2x2( convertFrom );

	TEMPER_CHECK_TRUE( expectedAnswer[0][0] == actualAnswer[0][0] );
	TEMPER_CHECK_TRUE( expectedAnswer[0][1] == actualAnswer[0][1] );

	TEMPER_CHECK_TRUE( expectedAnswer[1][0] == actualAnswer[1][0] );
	TEMPER_CHECK_TRUE( expectedAnswer[1][1] == actualAnswer[1][1] );

}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool2x2_int2x2,
	int2x2(
		0, 0,
		0, 0
	),
	bool2x2(
		false, false,
		false, false
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool2x2_int2x2,
	int2x2(
		10, 10,
		10, 10
	),
	bool2x2(
		true, true,
		true, true
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool2x2_int2x2,
	int2x2(
		10, 20,
		50, 60
	),
	bool2x2(
		true, true,
		true, true
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool2x2_int2x2,
	int2x2(
		160, 150,
		120, 110
	),
	bool2x2(
		true, true,
		true, true
	)
);

TEMPER_TEST_PARAMETRIC( Test_bool2x2_uint2x2, TEMPER_FLAG_SHOULD_RUN, const uint2x2& convertFrom, const bool2x2& expectedAnswer )
{
	bool2x2 actualAnswer = bool2x2( convertFrom );

	TEMPER_CHECK_TRUE( expectedAnswer[0][0] == actualAnswer[0][0] );
	TEMPER_CHECK_TRUE( expectedAnswer[0][1] == actualAnswer[0][1] );

	TEMPER_CHECK_TRUE( expectedAnswer[1][0] == actualAnswer[1][0] );
	TEMPER_CHECK_TRUE( expectedAnswer[1][1] == actualAnswer[1][1] );

}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool2x2_uint2x2,
	uint2x2(
		0U, 0U,
		0U, 0U
	),
	bool2x2(
		false, false,
		false, false
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool2x2_uint2x2,
	uint2x2(
		10U, 10U,
		10U, 10U
	),
	bool2x2(
		true, true,
		true, true
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool2x2_uint2x2,
	uint2x2(
		10U, 20U,
		50U, 60U
	),
	bool2x2(
		true, true,
		true, true
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool2x2_uint2x2,
	uint2x2(
		160U, 150U,
		120U, 110U
	),
	bool2x2(
		true, true,
		true, true
	)
);

TEMPER_TEST_PARAMETRIC( Test_bool2x2_float2x2, TEMPER_FLAG_SHOULD_RUN, const float2x2& convertFrom, const bool2x2& expectedAnswer )
{
	bool2x2 actualAnswer = bool2x2( convertFrom );

	TEMPER_CHECK_TRUE( expectedAnswer[0][0] == actualAnswer[0][0] );
	TEMPER_CHECK_TRUE( expectedAnswer[0][1] == actualAnswer[0][1] );

	TEMPER_CHECK_TRUE( expectedAnswer[1][0] == actualAnswer[1][0] );
	TEMPER_CHECK_TRUE( expectedAnswer[1][1] == actualAnswer[1][1] );

}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool2x2_float2x2,
	float2x2(
		0.000000f, 0.000000f,
		0.000000f, 0.000000f
	),
	bool2x2(
		false, false,
		false, false
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool2x2_float2x2,
	float2x2(
		10.000000f, 10.000000f,
		10.000000f, 10.000000f
	),
	bool2x2(
		true, true,
		true, true
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool2x2_float2x2,
	float2x2(
		10.000000f, 20.000000f,
		50.000000f, 60.000000f
	),
	bool2x2(
		true, true,
		true, true
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool2x2_float2x2,
	float2x2(
		160.000000f, 150.000000f,
		120.000000f, 110.000000f
	),
	bool2x2(
		true, true,
		true, true
	)
);

TEMPER_TEST_PARAMETRIC( Test_bool2x2_double2x2, TEMPER_FLAG_SHOULD_RUN, const double2x2& convertFrom, const bool2x2& expectedAnswer )
{
	bool2x2 actualAnswer = bool2x2( convertFrom );

	TEMPER_CHECK_TRUE( expectedAnswer[0][0] == actualAnswer[0][0] );
	TEMPER_CHECK_TRUE( expectedAnswer[0][1] == actualAnswer[0][1] );

	TEMPER_CHECK_TRUE( expectedAnswer[1][0] == actualAnswer[1][0] );
	TEMPER_CHECK_TRUE( expectedAnswer[1][1] == actualAnswer[1][1] );

}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool2x2_double2x2,
	double2x2(
		0.000000f, 0.000000f,
		0.000000f, 0.000000f
	),
	bool2x2(
		false, false,
		false, false
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool2x2_double2x2,
	double2x2(
		10.000000f, 10.000000f,
		10.000000f, 10.000000f
	),
	bool2x2(
		true, true,
		true, true
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool2x2_double2x2,
	double2x2(
		10.000000f, 20.000000f,
		50.000000f, 60.000000f
	),
	bool2x2(
		true, true,
		true, true
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool2x2_double2x2,
	double2x2(
		160.000000f, 150.000000f,
		120.000000f, 110.000000f
	),
	bool2x2(
		true, true,
		true, true
	)
);

TEMPER_TEST_PARAMETRIC( Test_bool2x2_identity, TEMPER_FLAG_SHOULD_RUN, const bool2x2& matrix, const bool expectedAnswer )
{
	bool2x2 identityMat;
	identity( identityMat );
	bool isMatrixIdentity = ( identityMat == matrix );
	TEMPER_CHECK_TRUE( isMatrixIdentity == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool2x2_identity,
	bool2x2(
		true, false,
		false, true
	),
	true
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool2x2_identity,
	bool2x2(
		true, true,
		false, true
	),
	false
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool2x2_identity,
	bool2x2(
		true, false,
		true, true
	),
	false
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool2x2_identity,
	bool2x2(
		true, true,
		true, true
	),
	false
);

TEMPER_TEST_PARAMETRIC( Test_bool2x2_transpose, TEMPER_FLAG_SHOULD_RUN, const bool2x2& matrix, const bool2x2& expectedAnswer )
{
	bool2x2 actualResult = transpose( matrix );
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool2x2_transpose,
	bool2x2(
		true, false,
		false, true
	),
	bool2x2(
		true, false,
		false, true
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool2x2_transpose,
	bool2x2(
		false, true,
		true, true
	),
	bool2x2(
		false, true,
		true, true
	)
);


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

TEMPER_PARAMETRIC( Test_bool2x4_all, TEMPER_FLAG_SHOULD_RUN, const bool2x4& x, const bool32_t expectedAnswer )
{
	bool32_t actualResult = all( x );
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool2x4_all,
	bool2x4(
		true, true, true, true,
		true, true, true, true
	),
	true
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool2x4_all,
	bool2x4(
		true, false, false, false,
		false, false, false, false
	),
	false
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool2x4_all,
	bool2x4(
		false, true, true, true,
		true, true, true, true
	),
	false
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool2x4_all,
	bool2x4(
		false, true, false, true,
		true, false, true, false
	),
	false
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool2x4_all,
	bool2x4(
		false, false, false, false,
		false, false, false, false
	),
	false
);

TEMPER_PARAMETRIC( Test_bool2x4_any, TEMPER_FLAG_SHOULD_RUN, const bool2x4& x, const bool32_t expectedAnswer )
{
	bool32_t actualResult = any( x );
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool2x4_any,
	bool2x4(
		true, true, true, true,
		true, true, true, true
	),
	true
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool2x4_any,
	bool2x4(
		true, false, false, false,
		false, false, false, false
	),
	true
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool2x4_any,
	bool2x4(
		false, true, true, true,
		true, true, true, true
	),
	true
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool2x4_any,
	bool2x4(
		false, true, false, true,
		true, false, true, false
	),
	true
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool2x4_any,
	bool2x4(
		false, false, false, false,
		false, false, false, false
	),
	false
);

TEMPER_PARAMETRIC( Test_bool2x4_int2x4, TEMPER_FLAG_SHOULD_RUN, const int2x4& convertFrom, const bool2x4& expectedAnswer )
{
	bool2x4 actualAnswer = bool2x4( convertFrom );

	TEMPER_CHECK_TRUE( expectedAnswer[0][0] == actualAnswer[0][0] );
	TEMPER_CHECK_TRUE( expectedAnswer[0][1] == actualAnswer[0][1] );
	TEMPER_CHECK_TRUE( expectedAnswer[0][2] == actualAnswer[0][2] );
	TEMPER_CHECK_TRUE( expectedAnswer[0][3] == actualAnswer[0][3] );

	TEMPER_CHECK_TRUE( expectedAnswer[1][0] == actualAnswer[1][0] );
	TEMPER_CHECK_TRUE( expectedAnswer[1][1] == actualAnswer[1][1] );
	TEMPER_CHECK_TRUE( expectedAnswer[1][2] == actualAnswer[1][2] );
	TEMPER_CHECK_TRUE( expectedAnswer[1][3] == actualAnswer[1][3] );

}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool2x4_int2x4,
	int2x4(
		0, 0, 0, 0,
		0, 0, 0, 0
	),
	bool2x4(
		false, false, false, false,
		false, false, false, false
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool2x4_int2x4,
	int2x4(
		10, 10, 10, 10,
		10, 10, 10, 10
	),
	bool2x4(
		true, true, true, true,
		true, true, true, true
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool2x4_int2x4,
	int2x4(
		10, 20, 30, 40,
		50, 60, 70, 80
	),
	bool2x4(
		true, true, true, true,
		true, true, true, true
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool2x4_int2x4,
	int2x4(
		160, 150, 140, 130,
		120, 110, 100, 90
	),
	bool2x4(
		true, true, true, true,
		true, true, true, true
	)
);

TEMPER_PARAMETRIC( Test_bool2x4_uint2x4, TEMPER_FLAG_SHOULD_RUN, const uint2x4& convertFrom, const bool2x4& expectedAnswer )
{
	bool2x4 actualAnswer = bool2x4( convertFrom );

	TEMPER_CHECK_TRUE( expectedAnswer[0][0] == actualAnswer[0][0] );
	TEMPER_CHECK_TRUE( expectedAnswer[0][1] == actualAnswer[0][1] );
	TEMPER_CHECK_TRUE( expectedAnswer[0][2] == actualAnswer[0][2] );
	TEMPER_CHECK_TRUE( expectedAnswer[0][3] == actualAnswer[0][3] );

	TEMPER_CHECK_TRUE( expectedAnswer[1][0] == actualAnswer[1][0] );
	TEMPER_CHECK_TRUE( expectedAnswer[1][1] == actualAnswer[1][1] );
	TEMPER_CHECK_TRUE( expectedAnswer[1][2] == actualAnswer[1][2] );
	TEMPER_CHECK_TRUE( expectedAnswer[1][3] == actualAnswer[1][3] );

}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool2x4_uint2x4,
	uint2x4(
		0U, 0U, 0U, 0U,
		0U, 0U, 0U, 0U
	),
	bool2x4(
		false, false, false, false,
		false, false, false, false
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool2x4_uint2x4,
	uint2x4(
		10U, 10U, 10U, 10U,
		10U, 10U, 10U, 10U
	),
	bool2x4(
		true, true, true, true,
		true, true, true, true
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool2x4_uint2x4,
	uint2x4(
		10U, 20U, 30U, 40U,
		50U, 60U, 70U, 80U
	),
	bool2x4(
		true, true, true, true,
		true, true, true, true
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool2x4_uint2x4,
	uint2x4(
		160U, 150U, 140U, 130U,
		120U, 110U, 100U, 90U
	),
	bool2x4(
		true, true, true, true,
		true, true, true, true
	)
);

TEMPER_PARAMETRIC( Test_bool2x4_float2x4, TEMPER_FLAG_SHOULD_RUN, const float2x4& convertFrom, const bool2x4& expectedAnswer )
{
	bool2x4 actualAnswer = bool2x4( convertFrom );

	TEMPER_CHECK_TRUE( expectedAnswer[0][0] == actualAnswer[0][0] );
	TEMPER_CHECK_TRUE( expectedAnswer[0][1] == actualAnswer[0][1] );
	TEMPER_CHECK_TRUE( expectedAnswer[0][2] == actualAnswer[0][2] );
	TEMPER_CHECK_TRUE( expectedAnswer[0][3] == actualAnswer[0][3] );

	TEMPER_CHECK_TRUE( expectedAnswer[1][0] == actualAnswer[1][0] );
	TEMPER_CHECK_TRUE( expectedAnswer[1][1] == actualAnswer[1][1] );
	TEMPER_CHECK_TRUE( expectedAnswer[1][2] == actualAnswer[1][2] );
	TEMPER_CHECK_TRUE( expectedAnswer[1][3] == actualAnswer[1][3] );

}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool2x4_float2x4,
	float2x4(
		0.000000f, 0.000000f, 0.000000f, 0.000000f,
		0.000000f, 0.000000f, 0.000000f, 0.000000f
	),
	bool2x4(
		false, false, false, false,
		false, false, false, false
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool2x4_float2x4,
	float2x4(
		10.000000f, 10.000000f, 10.000000f, 10.000000f,
		10.000000f, 10.000000f, 10.000000f, 10.000000f
	),
	bool2x4(
		true, true, true, true,
		true, true, true, true
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool2x4_float2x4,
	float2x4(
		10.000000f, 20.000000f, 30.000000f, 40.000000f,
		50.000000f, 60.000000f, 70.000000f, 80.000000f
	),
	bool2x4(
		true, true, true, true,
		true, true, true, true
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool2x4_float2x4,
	float2x4(
		160.000000f, 150.000000f, 140.000000f, 130.000000f,
		120.000000f, 110.000000f, 100.000000f, 90.000000f
	),
	bool2x4(
		true, true, true, true,
		true, true, true, true
	)
);

TEMPER_PARAMETRIC( Test_bool2x4_double2x4, TEMPER_FLAG_SHOULD_RUN, const double2x4& convertFrom, const bool2x4& expectedAnswer )
{
	bool2x4 actualAnswer = bool2x4( convertFrom );

	TEMPER_CHECK_TRUE( expectedAnswer[0][0] == actualAnswer[0][0] );
	TEMPER_CHECK_TRUE( expectedAnswer[0][1] == actualAnswer[0][1] );
	TEMPER_CHECK_TRUE( expectedAnswer[0][2] == actualAnswer[0][2] );
	TEMPER_CHECK_TRUE( expectedAnswer[0][3] == actualAnswer[0][3] );

	TEMPER_CHECK_TRUE( expectedAnswer[1][0] == actualAnswer[1][0] );
	TEMPER_CHECK_TRUE( expectedAnswer[1][1] == actualAnswer[1][1] );
	TEMPER_CHECK_TRUE( expectedAnswer[1][2] == actualAnswer[1][2] );
	TEMPER_CHECK_TRUE( expectedAnswer[1][3] == actualAnswer[1][3] );

}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool2x4_double2x4,
	double2x4(
		0.000000f, 0.000000f, 0.000000f, 0.000000f,
		0.000000f, 0.000000f, 0.000000f, 0.000000f
	),
	bool2x4(
		false, false, false, false,
		false, false, false, false
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool2x4_double2x4,
	double2x4(
		10.000000f, 10.000000f, 10.000000f, 10.000000f,
		10.000000f, 10.000000f, 10.000000f, 10.000000f
	),
	bool2x4(
		true, true, true, true,
		true, true, true, true
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool2x4_double2x4,
	double2x4(
		10.000000f, 20.000000f, 30.000000f, 40.000000f,
		50.000000f, 60.000000f, 70.000000f, 80.000000f
	),
	bool2x4(
		true, true, true, true,
		true, true, true, true
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool2x4_double2x4,
	double2x4(
		160.000000f, 150.000000f, 140.000000f, 130.000000f,
		120.000000f, 110.000000f, 100.000000f, 90.000000f
	),
	bool2x4(
		true, true, true, true,
		true, true, true, true
	)
);

TEMPER_PARAMETRIC( Test_bool2x4_identity, TEMPER_FLAG_SHOULD_RUN, const bool2x4& matrix, const bool expectedAnswer )
{
	bool2x4 identityMat;
	identity( identityMat );
	bool isMatrixIdentity = ( identityMat == matrix );
	TEMPER_CHECK_TRUE( isMatrixIdentity == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool2x4_identity,
	bool2x4(
		true, false, false, false,
		false, true, false, false
	),
	true
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool2x4_identity,
	bool2x4(
		true, true, false, false,
		false, true, false, false
	),
	false
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool2x4_identity,
	bool2x4(
		true, false, false, false,
		true, true, false, false
	),
	false
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool2x4_identity,
	bool2x4(
		true, true, false, false,
		true, true, false, false
	),
	false
);

TEMPER_PARAMETRIC( Test_bool2x4_transpose, TEMPER_FLAG_SHOULD_RUN, const bool2x4& matrix, const bool4x2& expectedAnswer )
{
	bool4x2 actualResult = transpose( matrix );
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool2x4_transpose,
	bool2x4(
		true, false, false, false,
		false, true, false, false
	),
	bool4x2(
		true, false,
		false, true,
		false, false,
		false, false
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool2x4_transpose,
	bool2x4(
		false, true, true, true,
		true, true, true, true
	),
	bool4x2(
		false, true,
		true, true,
		true, true,
		true, true
	)
);


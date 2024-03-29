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

TEMPER_TEST_PARAMETRIC( Test_bool3x4_all, TEMPER_FLAG_SHOULD_RUN, const bool3x4& x, const bool32_t expectedAnswer )
{
	bool32_t actualResult = all( x );
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool3x4_all,
	bool3x4(
		true, true, true, true,
		true, true, true, true,
		true, true, true, true
	),
	true
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool3x4_all,
	bool3x4(
		true, false, false, false,
		false, false, false, false,
		false, false, false, false
	),
	false
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool3x4_all,
	bool3x4(
		false, true, true, true,
		true, true, true, true,
		true, true, true, true
	),
	false
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool3x4_all,
	bool3x4(
		false, true, false, true,
		true, false, true, false,
		false, true, false, true
	),
	false
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool3x4_all,
	bool3x4(
		false, false, false, false,
		false, false, false, false,
		false, false, false, false
	),
	false
);

TEMPER_TEST_PARAMETRIC( Test_bool3x4_any, TEMPER_FLAG_SHOULD_RUN, const bool3x4& x, const bool32_t expectedAnswer )
{
	bool32_t actualResult = any( x );
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool3x4_any,
	bool3x4(
		true, true, true, true,
		true, true, true, true,
		true, true, true, true
	),
	true
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool3x4_any,
	bool3x4(
		true, false, false, false,
		false, false, false, false,
		false, false, false, false
	),
	true
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool3x4_any,
	bool3x4(
		false, true, true, true,
		true, true, true, true,
		true, true, true, true
	),
	true
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool3x4_any,
	bool3x4(
		false, true, false, true,
		true, false, true, false,
		false, true, false, true
	),
	true
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool3x4_any,
	bool3x4(
		false, false, false, false,
		false, false, false, false,
		false, false, false, false
	),
	false
);

TEMPER_TEST_PARAMETRIC( Test_bool3x4_int3x4, TEMPER_FLAG_SHOULD_RUN, const int3x4& convertFrom, const bool3x4& expectedAnswer )
{
	bool3x4 actualAnswer = bool3x4( convertFrom );

	TEMPER_CHECK_TRUE( expectedAnswer[0][0] == actualAnswer[0][0] );
	TEMPER_CHECK_TRUE( expectedAnswer[0][1] == actualAnswer[0][1] );
	TEMPER_CHECK_TRUE( expectedAnswer[0][2] == actualAnswer[0][2] );
	TEMPER_CHECK_TRUE( expectedAnswer[0][3] == actualAnswer[0][3] );

	TEMPER_CHECK_TRUE( expectedAnswer[1][0] == actualAnswer[1][0] );
	TEMPER_CHECK_TRUE( expectedAnswer[1][1] == actualAnswer[1][1] );
	TEMPER_CHECK_TRUE( expectedAnswer[1][2] == actualAnswer[1][2] );
	TEMPER_CHECK_TRUE( expectedAnswer[1][3] == actualAnswer[1][3] );

	TEMPER_CHECK_TRUE( expectedAnswer[2][0] == actualAnswer[2][0] );
	TEMPER_CHECK_TRUE( expectedAnswer[2][1] == actualAnswer[2][1] );
	TEMPER_CHECK_TRUE( expectedAnswer[2][2] == actualAnswer[2][2] );
	TEMPER_CHECK_TRUE( expectedAnswer[2][3] == actualAnswer[2][3] );

}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool3x4_int3x4,
	int3x4(
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0
	),
	bool3x4(
		false, false, false, false,
		false, false, false, false,
		false, false, false, false
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool3x4_int3x4,
	int3x4(
		10, 10, 10, 10,
		10, 10, 10, 10,
		10, 10, 10, 10
	),
	bool3x4(
		true, true, true, true,
		true, true, true, true,
		true, true, true, true
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool3x4_int3x4,
	int3x4(
		10, 20, 30, 40,
		50, 60, 70, 80,
		90, 100, 110, 120
	),
	bool3x4(
		true, true, true, true,
		true, true, true, true,
		true, true, true, true
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool3x4_int3x4,
	int3x4(
		160, 150, 140, 130,
		120, 110, 100, 90,
		80, 70, 60, 50
	),
	bool3x4(
		true, true, true, true,
		true, true, true, true,
		true, true, true, true
	)
);

TEMPER_TEST_PARAMETRIC( Test_bool3x4_uint3x4, TEMPER_FLAG_SHOULD_RUN, const uint3x4& convertFrom, const bool3x4& expectedAnswer )
{
	bool3x4 actualAnswer = bool3x4( convertFrom );

	TEMPER_CHECK_TRUE( expectedAnswer[0][0] == actualAnswer[0][0] );
	TEMPER_CHECK_TRUE( expectedAnswer[0][1] == actualAnswer[0][1] );
	TEMPER_CHECK_TRUE( expectedAnswer[0][2] == actualAnswer[0][2] );
	TEMPER_CHECK_TRUE( expectedAnswer[0][3] == actualAnswer[0][3] );

	TEMPER_CHECK_TRUE( expectedAnswer[1][0] == actualAnswer[1][0] );
	TEMPER_CHECK_TRUE( expectedAnswer[1][1] == actualAnswer[1][1] );
	TEMPER_CHECK_TRUE( expectedAnswer[1][2] == actualAnswer[1][2] );
	TEMPER_CHECK_TRUE( expectedAnswer[1][3] == actualAnswer[1][3] );

	TEMPER_CHECK_TRUE( expectedAnswer[2][0] == actualAnswer[2][0] );
	TEMPER_CHECK_TRUE( expectedAnswer[2][1] == actualAnswer[2][1] );
	TEMPER_CHECK_TRUE( expectedAnswer[2][2] == actualAnswer[2][2] );
	TEMPER_CHECK_TRUE( expectedAnswer[2][3] == actualAnswer[2][3] );

}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool3x4_uint3x4,
	uint3x4(
		0U, 0U, 0U, 0U,
		0U, 0U, 0U, 0U,
		0U, 0U, 0U, 0U
	),
	bool3x4(
		false, false, false, false,
		false, false, false, false,
		false, false, false, false
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool3x4_uint3x4,
	uint3x4(
		10U, 10U, 10U, 10U,
		10U, 10U, 10U, 10U,
		10U, 10U, 10U, 10U
	),
	bool3x4(
		true, true, true, true,
		true, true, true, true,
		true, true, true, true
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool3x4_uint3x4,
	uint3x4(
		10U, 20U, 30U, 40U,
		50U, 60U, 70U, 80U,
		90U, 100U, 110U, 120U
	),
	bool3x4(
		true, true, true, true,
		true, true, true, true,
		true, true, true, true
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool3x4_uint3x4,
	uint3x4(
		160U, 150U, 140U, 130U,
		120U, 110U, 100U, 90U,
		80U, 70U, 60U, 50U
	),
	bool3x4(
		true, true, true, true,
		true, true, true, true,
		true, true, true, true
	)
);

TEMPER_TEST_PARAMETRIC( Test_bool3x4_float3x4, TEMPER_FLAG_SHOULD_RUN, const float3x4& convertFrom, const bool3x4& expectedAnswer )
{
	bool3x4 actualAnswer = bool3x4( convertFrom );

	TEMPER_CHECK_TRUE( expectedAnswer[0][0] == actualAnswer[0][0] );
	TEMPER_CHECK_TRUE( expectedAnswer[0][1] == actualAnswer[0][1] );
	TEMPER_CHECK_TRUE( expectedAnswer[0][2] == actualAnswer[0][2] );
	TEMPER_CHECK_TRUE( expectedAnswer[0][3] == actualAnswer[0][3] );

	TEMPER_CHECK_TRUE( expectedAnswer[1][0] == actualAnswer[1][0] );
	TEMPER_CHECK_TRUE( expectedAnswer[1][1] == actualAnswer[1][1] );
	TEMPER_CHECK_TRUE( expectedAnswer[1][2] == actualAnswer[1][2] );
	TEMPER_CHECK_TRUE( expectedAnswer[1][3] == actualAnswer[1][3] );

	TEMPER_CHECK_TRUE( expectedAnswer[2][0] == actualAnswer[2][0] );
	TEMPER_CHECK_TRUE( expectedAnswer[2][1] == actualAnswer[2][1] );
	TEMPER_CHECK_TRUE( expectedAnswer[2][2] == actualAnswer[2][2] );
	TEMPER_CHECK_TRUE( expectedAnswer[2][3] == actualAnswer[2][3] );

}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool3x4_float3x4,
	float3x4(
		0.000000f, 0.000000f, 0.000000f, 0.000000f,
		0.000000f, 0.000000f, 0.000000f, 0.000000f,
		0.000000f, 0.000000f, 0.000000f, 0.000000f
	),
	bool3x4(
		false, false, false, false,
		false, false, false, false,
		false, false, false, false
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool3x4_float3x4,
	float3x4(
		10.000000f, 10.000000f, 10.000000f, 10.000000f,
		10.000000f, 10.000000f, 10.000000f, 10.000000f,
		10.000000f, 10.000000f, 10.000000f, 10.000000f
	),
	bool3x4(
		true, true, true, true,
		true, true, true, true,
		true, true, true, true
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool3x4_float3x4,
	float3x4(
		10.000000f, 20.000000f, 30.000000f, 40.000000f,
		50.000000f, 60.000000f, 70.000000f, 80.000000f,
		90.000000f, 100.000000f, 110.000000f, 120.000000f
	),
	bool3x4(
		true, true, true, true,
		true, true, true, true,
		true, true, true, true
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool3x4_float3x4,
	float3x4(
		160.000000f, 150.000000f, 140.000000f, 130.000000f,
		120.000000f, 110.000000f, 100.000000f, 90.000000f,
		80.000000f, 70.000000f, 60.000000f, 50.000000f
	),
	bool3x4(
		true, true, true, true,
		true, true, true, true,
		true, true, true, true
	)
);

TEMPER_TEST_PARAMETRIC( Test_bool3x4_double3x4, TEMPER_FLAG_SHOULD_RUN, const double3x4& convertFrom, const bool3x4& expectedAnswer )
{
	bool3x4 actualAnswer = bool3x4( convertFrom );

	TEMPER_CHECK_TRUE( expectedAnswer[0][0] == actualAnswer[0][0] );
	TEMPER_CHECK_TRUE( expectedAnswer[0][1] == actualAnswer[0][1] );
	TEMPER_CHECK_TRUE( expectedAnswer[0][2] == actualAnswer[0][2] );
	TEMPER_CHECK_TRUE( expectedAnswer[0][3] == actualAnswer[0][3] );

	TEMPER_CHECK_TRUE( expectedAnswer[1][0] == actualAnswer[1][0] );
	TEMPER_CHECK_TRUE( expectedAnswer[1][1] == actualAnswer[1][1] );
	TEMPER_CHECK_TRUE( expectedAnswer[1][2] == actualAnswer[1][2] );
	TEMPER_CHECK_TRUE( expectedAnswer[1][3] == actualAnswer[1][3] );

	TEMPER_CHECK_TRUE( expectedAnswer[2][0] == actualAnswer[2][0] );
	TEMPER_CHECK_TRUE( expectedAnswer[2][1] == actualAnswer[2][1] );
	TEMPER_CHECK_TRUE( expectedAnswer[2][2] == actualAnswer[2][2] );
	TEMPER_CHECK_TRUE( expectedAnswer[2][3] == actualAnswer[2][3] );

}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool3x4_double3x4,
	double3x4(
		0.000000f, 0.000000f, 0.000000f, 0.000000f,
		0.000000f, 0.000000f, 0.000000f, 0.000000f,
		0.000000f, 0.000000f, 0.000000f, 0.000000f
	),
	bool3x4(
		false, false, false, false,
		false, false, false, false,
		false, false, false, false
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool3x4_double3x4,
	double3x4(
		10.000000f, 10.000000f, 10.000000f, 10.000000f,
		10.000000f, 10.000000f, 10.000000f, 10.000000f,
		10.000000f, 10.000000f, 10.000000f, 10.000000f
	),
	bool3x4(
		true, true, true, true,
		true, true, true, true,
		true, true, true, true
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool3x4_double3x4,
	double3x4(
		10.000000f, 20.000000f, 30.000000f, 40.000000f,
		50.000000f, 60.000000f, 70.000000f, 80.000000f,
		90.000000f, 100.000000f, 110.000000f, 120.000000f
	),
	bool3x4(
		true, true, true, true,
		true, true, true, true,
		true, true, true, true
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool3x4_double3x4,
	double3x4(
		160.000000f, 150.000000f, 140.000000f, 130.000000f,
		120.000000f, 110.000000f, 100.000000f, 90.000000f,
		80.000000f, 70.000000f, 60.000000f, 50.000000f
	),
	bool3x4(
		true, true, true, true,
		true, true, true, true,
		true, true, true, true
	)
);

TEMPER_TEST_PARAMETRIC( Test_bool3x4_identity, TEMPER_FLAG_SHOULD_RUN, const bool3x4& matrix, const bool expectedAnswer )
{
	bool3x4 identityMat;
	identity( identityMat );
	bool isMatrixIdentity = ( identityMat == matrix );
	TEMPER_CHECK_TRUE( isMatrixIdentity == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool3x4_identity,
	bool3x4(
		true, false, false, false,
		false, true, false, false,
		false, false, true, false
	),
	true
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool3x4_identity,
	bool3x4(
		true, true, false, false,
		false, true, false, false,
		false, false, true, false
	),
	false
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool3x4_identity,
	bool3x4(
		true, false, false, false,
		true, true, false, false,
		false, false, true, false
	),
	false
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool3x4_identity,
	bool3x4(
		true, true, false, false,
		true, true, false, false,
		false, false, true, false
	),
	false
);

TEMPER_TEST_PARAMETRIC( Test_bool3x4_transpose, TEMPER_FLAG_SHOULD_RUN, const bool3x4& matrix, const bool4x3& expectedAnswer )
{
	bool4x3 actualResult = transpose( matrix );
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool3x4_transpose,
	bool3x4(
		true, false, false, false,
		false, true, false, false,
		false, false, true, false
	),
	bool4x3(
		true, false, false,
		false, true, false,
		false, false, true,
		false, false, false
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool3x4_transpose,
	bool3x4(
		false, true, true, true,
		true, true, true, true,
		true, true, true, true
	),
	bool4x3(
		false, true, true,
		true, true, true,
		true, true, true,
		true, true, true
	)
);


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

TEMPER_PARAMETRIC( Test_bool4x3_all, TEMPER_FLAG_SHOULD_RUN, const bool4x3& x, const bool32_t expectedAnswer )
{
	bool32_t actualResult = all( x );
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool4x3_all,
	bool4x3(
		true, true, true,
		true, true, true,
		true, true, true,
		true, true, true
	),
	true
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool4x3_all,
	bool4x3(
		true, false, false,
		false, false, false,
		false, false, false,
		false, false, false
	),
	false
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool4x3_all,
	bool4x3(
		false, true, true,
		true, true, true,
		true, true, true,
		true, true, true
	),
	false
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool4x3_all,
	bool4x3(
		false, true, false,
		true, false, true,
		false, true, false,
		true, false, true
	),
	false
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool4x3_all,
	bool4x3(
		false, false, false,
		false, false, false,
		false, false, false,
		false, false, false
	),
	false
);

TEMPER_PARAMETRIC( Test_bool4x3_any, TEMPER_FLAG_SHOULD_RUN, const bool4x3& x, const bool32_t expectedAnswer )
{
	bool32_t actualResult = any( x );
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool4x3_any,
	bool4x3(
		true, true, true,
		true, true, true,
		true, true, true,
		true, true, true
	),
	true
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool4x3_any,
	bool4x3(
		true, false, false,
		false, false, false,
		false, false, false,
		false, false, false
	),
	true
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool4x3_any,
	bool4x3(
		false, true, true,
		true, true, true,
		true, true, true,
		true, true, true
	),
	true
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool4x3_any,
	bool4x3(
		false, true, false,
		true, false, true,
		false, true, false,
		true, false, true
	),
	true
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool4x3_any,
	bool4x3(
		false, false, false,
		false, false, false,
		false, false, false,
		false, false, false
	),
	false
);

TEMPER_PARAMETRIC( Test_bool4x3_int4x3, TEMPER_FLAG_SHOULD_RUN, const int4x3& convertFrom, const bool4x3& expectedAnswer )
{
	bool4x3 actualAnswer = bool4x3( convertFrom );

	TEMPER_CHECK_TRUE( expectedAnswer[0][0] == actualAnswer[0][0] );
	TEMPER_CHECK_TRUE( expectedAnswer[0][1] == actualAnswer[0][1] );
	TEMPER_CHECK_TRUE( expectedAnswer[0][2] == actualAnswer[0][2] );

	TEMPER_CHECK_TRUE( expectedAnswer[1][0] == actualAnswer[1][0] );
	TEMPER_CHECK_TRUE( expectedAnswer[1][1] == actualAnswer[1][1] );
	TEMPER_CHECK_TRUE( expectedAnswer[1][2] == actualAnswer[1][2] );

	TEMPER_CHECK_TRUE( expectedAnswer[2][0] == actualAnswer[2][0] );
	TEMPER_CHECK_TRUE( expectedAnswer[2][1] == actualAnswer[2][1] );
	TEMPER_CHECK_TRUE( expectedAnswer[2][2] == actualAnswer[2][2] );

	TEMPER_CHECK_TRUE( expectedAnswer[3][0] == actualAnswer[3][0] );
	TEMPER_CHECK_TRUE( expectedAnswer[3][1] == actualAnswer[3][1] );
	TEMPER_CHECK_TRUE( expectedAnswer[3][2] == actualAnswer[3][2] );

}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool4x3_int4x3,
	int4x3(
		0, 0, 0,
		0, 0, 0,
		0, 0, 0,
		0, 0, 0
	),
	bool4x3(
		false, false, false,
		false, false, false,
		false, false, false,
		false, false, false
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool4x3_int4x3,
	int4x3(
		10, 10, 10,
		10, 10, 10,
		10, 10, 10,
		10, 10, 10
	),
	bool4x3(
		true, true, true,
		true, true, true,
		true, true, true,
		true, true, true
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool4x3_int4x3,
	int4x3(
		10, 20, 30,
		50, 60, 70,
		90, 100, 110,
		130, 140, 150
	),
	bool4x3(
		true, true, true,
		true, true, true,
		true, true, true,
		true, true, true
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool4x3_int4x3,
	int4x3(
		160, 150, 140,
		120, 110, 100,
		80, 70, 60,
		40, 30, 20
	),
	bool4x3(
		true, true, true,
		true, true, true,
		true, true, true,
		true, true, true
	)
);

TEMPER_PARAMETRIC( Test_bool4x3_uint4x3, TEMPER_FLAG_SHOULD_RUN, const uint4x3& convertFrom, const bool4x3& expectedAnswer )
{
	bool4x3 actualAnswer = bool4x3( convertFrom );

	TEMPER_CHECK_TRUE( expectedAnswer[0][0] == actualAnswer[0][0] );
	TEMPER_CHECK_TRUE( expectedAnswer[0][1] == actualAnswer[0][1] );
	TEMPER_CHECK_TRUE( expectedAnswer[0][2] == actualAnswer[0][2] );

	TEMPER_CHECK_TRUE( expectedAnswer[1][0] == actualAnswer[1][0] );
	TEMPER_CHECK_TRUE( expectedAnswer[1][1] == actualAnswer[1][1] );
	TEMPER_CHECK_TRUE( expectedAnswer[1][2] == actualAnswer[1][2] );

	TEMPER_CHECK_TRUE( expectedAnswer[2][0] == actualAnswer[2][0] );
	TEMPER_CHECK_TRUE( expectedAnswer[2][1] == actualAnswer[2][1] );
	TEMPER_CHECK_TRUE( expectedAnswer[2][2] == actualAnswer[2][2] );

	TEMPER_CHECK_TRUE( expectedAnswer[3][0] == actualAnswer[3][0] );
	TEMPER_CHECK_TRUE( expectedAnswer[3][1] == actualAnswer[3][1] );
	TEMPER_CHECK_TRUE( expectedAnswer[3][2] == actualAnswer[3][2] );

}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool4x3_uint4x3,
	uint4x3(
		0U, 0U, 0U,
		0U, 0U, 0U,
		0U, 0U, 0U,
		0U, 0U, 0U
	),
	bool4x3(
		false, false, false,
		false, false, false,
		false, false, false,
		false, false, false
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool4x3_uint4x3,
	uint4x3(
		10U, 10U, 10U,
		10U, 10U, 10U,
		10U, 10U, 10U,
		10U, 10U, 10U
	),
	bool4x3(
		true, true, true,
		true, true, true,
		true, true, true,
		true, true, true
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool4x3_uint4x3,
	uint4x3(
		10U, 20U, 30U,
		50U, 60U, 70U,
		90U, 100U, 110U,
		130U, 140U, 150U
	),
	bool4x3(
		true, true, true,
		true, true, true,
		true, true, true,
		true, true, true
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool4x3_uint4x3,
	uint4x3(
		160U, 150U, 140U,
		120U, 110U, 100U,
		80U, 70U, 60U,
		40U, 30U, 20U
	),
	bool4x3(
		true, true, true,
		true, true, true,
		true, true, true,
		true, true, true
	)
);

TEMPER_PARAMETRIC( Test_bool4x3_float4x3, TEMPER_FLAG_SHOULD_RUN, const float4x3& convertFrom, const bool4x3& expectedAnswer )
{
	bool4x3 actualAnswer = bool4x3( convertFrom );

	TEMPER_CHECK_TRUE( expectedAnswer[0][0] == actualAnswer[0][0] );
	TEMPER_CHECK_TRUE( expectedAnswer[0][1] == actualAnswer[0][1] );
	TEMPER_CHECK_TRUE( expectedAnswer[0][2] == actualAnswer[0][2] );

	TEMPER_CHECK_TRUE( expectedAnswer[1][0] == actualAnswer[1][0] );
	TEMPER_CHECK_TRUE( expectedAnswer[1][1] == actualAnswer[1][1] );
	TEMPER_CHECK_TRUE( expectedAnswer[1][2] == actualAnswer[1][2] );

	TEMPER_CHECK_TRUE( expectedAnswer[2][0] == actualAnswer[2][0] );
	TEMPER_CHECK_TRUE( expectedAnswer[2][1] == actualAnswer[2][1] );
	TEMPER_CHECK_TRUE( expectedAnswer[2][2] == actualAnswer[2][2] );

	TEMPER_CHECK_TRUE( expectedAnswer[3][0] == actualAnswer[3][0] );
	TEMPER_CHECK_TRUE( expectedAnswer[3][1] == actualAnswer[3][1] );
	TEMPER_CHECK_TRUE( expectedAnswer[3][2] == actualAnswer[3][2] );

}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool4x3_float4x3,
	float4x3(
		0.000000f, 0.000000f, 0.000000f,
		0.000000f, 0.000000f, 0.000000f,
		0.000000f, 0.000000f, 0.000000f,
		0.000000f, 0.000000f, 0.000000f
	),
	bool4x3(
		false, false, false,
		false, false, false,
		false, false, false,
		false, false, false
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool4x3_float4x3,
	float4x3(
		10.000000f, 10.000000f, 10.000000f,
		10.000000f, 10.000000f, 10.000000f,
		10.000000f, 10.000000f, 10.000000f,
		10.000000f, 10.000000f, 10.000000f
	),
	bool4x3(
		true, true, true,
		true, true, true,
		true, true, true,
		true, true, true
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool4x3_float4x3,
	float4x3(
		10.000000f, 20.000000f, 30.000000f,
		50.000000f, 60.000000f, 70.000000f,
		90.000000f, 100.000000f, 110.000000f,
		130.000000f, 140.000000f, 150.000000f
	),
	bool4x3(
		true, true, true,
		true, true, true,
		true, true, true,
		true, true, true
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool4x3_float4x3,
	float4x3(
		160.000000f, 150.000000f, 140.000000f,
		120.000000f, 110.000000f, 100.000000f,
		80.000000f, 70.000000f, 60.000000f,
		40.000000f, 30.000000f, 20.000000f
	),
	bool4x3(
		true, true, true,
		true, true, true,
		true, true, true,
		true, true, true
	)
);

TEMPER_PARAMETRIC( Test_bool4x3_double4x3, TEMPER_FLAG_SHOULD_RUN, const double4x3& convertFrom, const bool4x3& expectedAnswer )
{
	bool4x3 actualAnswer = bool4x3( convertFrom );

	TEMPER_CHECK_TRUE( expectedAnswer[0][0] == actualAnswer[0][0] );
	TEMPER_CHECK_TRUE( expectedAnswer[0][1] == actualAnswer[0][1] );
	TEMPER_CHECK_TRUE( expectedAnswer[0][2] == actualAnswer[0][2] );

	TEMPER_CHECK_TRUE( expectedAnswer[1][0] == actualAnswer[1][0] );
	TEMPER_CHECK_TRUE( expectedAnswer[1][1] == actualAnswer[1][1] );
	TEMPER_CHECK_TRUE( expectedAnswer[1][2] == actualAnswer[1][2] );

	TEMPER_CHECK_TRUE( expectedAnswer[2][0] == actualAnswer[2][0] );
	TEMPER_CHECK_TRUE( expectedAnswer[2][1] == actualAnswer[2][1] );
	TEMPER_CHECK_TRUE( expectedAnswer[2][2] == actualAnswer[2][2] );

	TEMPER_CHECK_TRUE( expectedAnswer[3][0] == actualAnswer[3][0] );
	TEMPER_CHECK_TRUE( expectedAnswer[3][1] == actualAnswer[3][1] );
	TEMPER_CHECK_TRUE( expectedAnswer[3][2] == actualAnswer[3][2] );

}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool4x3_double4x3,
	double4x3(
		0.000000f, 0.000000f, 0.000000f,
		0.000000f, 0.000000f, 0.000000f,
		0.000000f, 0.000000f, 0.000000f,
		0.000000f, 0.000000f, 0.000000f
	),
	bool4x3(
		false, false, false,
		false, false, false,
		false, false, false,
		false, false, false
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool4x3_double4x3,
	double4x3(
		10.000000f, 10.000000f, 10.000000f,
		10.000000f, 10.000000f, 10.000000f,
		10.000000f, 10.000000f, 10.000000f,
		10.000000f, 10.000000f, 10.000000f
	),
	bool4x3(
		true, true, true,
		true, true, true,
		true, true, true,
		true, true, true
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool4x3_double4x3,
	double4x3(
		10.000000f, 20.000000f, 30.000000f,
		50.000000f, 60.000000f, 70.000000f,
		90.000000f, 100.000000f, 110.000000f,
		130.000000f, 140.000000f, 150.000000f
	),
	bool4x3(
		true, true, true,
		true, true, true,
		true, true, true,
		true, true, true
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool4x3_double4x3,
	double4x3(
		160.000000f, 150.000000f, 140.000000f,
		120.000000f, 110.000000f, 100.000000f,
		80.000000f, 70.000000f, 60.000000f,
		40.000000f, 30.000000f, 20.000000f
	),
	bool4x3(
		true, true, true,
		true, true, true,
		true, true, true,
		true, true, true
	)
);

TEMPER_PARAMETRIC( Test_bool4x3_identity, TEMPER_FLAG_SHOULD_RUN, const bool4x3& matrix, const bool expectedAnswer )
{
	bool4x3 identityMat;
	identity( identityMat );
	bool isMatrixIdentity = ( identityMat == matrix );
	TEMPER_CHECK_TRUE( isMatrixIdentity == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool4x3_identity,
	bool4x3(
		true, false, false,
		false, true, false,
		false, false, true,
		false, false, false
	),
	true
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool4x3_identity,
	bool4x3(
		true, true, false,
		false, true, false,
		false, false, true,
		false, false, false
	),
	false
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool4x3_identity,
	bool4x3(
		true, false, false,
		true, true, false,
		false, false, true,
		false, false, false
	),
	false
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool4x3_identity,
	bool4x3(
		true, true, false,
		true, true, false,
		false, false, true,
		false, false, false
	),
	false
);

TEMPER_PARAMETRIC( Test_bool4x3_transpose, TEMPER_FLAG_SHOULD_RUN, const bool4x3& matrix, const bool3x4& expectedAnswer )
{
	bool3x4 actualResult = transpose( matrix );
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool4x3_transpose,
	bool4x3(
		true, false, false,
		false, true, false,
		false, false, true,
		false, false, false
	),
	bool3x4(
		true, false, false, false,
		false, true, false, false,
		false, false, true, false
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool4x3_transpose,
	bool4x3(
		false, true, true,
		true, true, true,
		true, true, true,
		true, true, true
	),
	bool3x4(
		false, true, true, true,
		true, true, true, true,
		true, true, true, true
	)
);


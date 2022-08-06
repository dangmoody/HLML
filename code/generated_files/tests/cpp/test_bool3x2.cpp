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

TEMPER_PARAMETRIC( Test_bool3x2_all, TEMPER_FLAG_SHOULD_RUN, const bool3x2& x, const bool32_t expectedAnswer )
{
	bool32_t actualResult = all( x );
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool3x2_all,
	bool3x2(
		true, true,
		true, true,
		true, true
	),
	true
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool3x2_all,
	bool3x2(
		true, false,
		false, false,
		false, false
	),
	false
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool3x2_all,
	bool3x2(
		false, true,
		true, true,
		true, true
	),
	false
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool3x2_all,
	bool3x2(
		false, true,
		true, false,
		false, true
	),
	false
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool3x2_all,
	bool3x2(
		false, false,
		false, false,
		false, false
	),
	false
);

TEMPER_PARAMETRIC( Test_bool3x2_any, TEMPER_FLAG_SHOULD_RUN, const bool3x2& x, const bool32_t expectedAnswer )
{
	bool32_t actualResult = any( x );
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool3x2_any,
	bool3x2(
		true, true,
		true, true,
		true, true
	),
	true
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool3x2_any,
	bool3x2(
		true, false,
		false, false,
		false, false
	),
	true
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool3x2_any,
	bool3x2(
		false, true,
		true, true,
		true, true
	),
	true
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool3x2_any,
	bool3x2(
		false, true,
		true, false,
		false, true
	),
	true
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool3x2_any,
	bool3x2(
		false, false,
		false, false,
		false, false
	),
	false
);

TEMPER_PARAMETRIC( Test_bool3x2_int3x2, TEMPER_FLAG_SHOULD_RUN, const int3x2& convertFrom, const bool3x2& expectedAnswer )
{
	bool3x2 actualAnswer = bool3x2( convertFrom );

	TEMPER_CHECK_TRUE( expectedAnswer[0][0] == actualAnswer[0][0] );
	TEMPER_CHECK_TRUE( expectedAnswer[0][1] == actualAnswer[0][1] );

	TEMPER_CHECK_TRUE( expectedAnswer[1][0] == actualAnswer[1][0] );
	TEMPER_CHECK_TRUE( expectedAnswer[1][1] == actualAnswer[1][1] );

	TEMPER_CHECK_TRUE( expectedAnswer[2][0] == actualAnswer[2][0] );
	TEMPER_CHECK_TRUE( expectedAnswer[2][1] == actualAnswer[2][1] );

}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool3x2_int3x2,
	int3x2(
		0, 0,
		0, 0,
		0, 0
	),
	bool3x2(
		false, false,
		false, false,
		false, false
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool3x2_int3x2,
	int3x2(
		10, 10,
		10, 10,
		10, 10
	),
	bool3x2(
		true, true,
		true, true,
		true, true
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool3x2_int3x2,
	int3x2(
		10, 20,
		50, 60,
		90, 100
	),
	bool3x2(
		true, true,
		true, true,
		true, true
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool3x2_int3x2,
	int3x2(
		160, 150,
		120, 110,
		80, 70
	),
	bool3x2(
		true, true,
		true, true,
		true, true
	)
);

TEMPER_PARAMETRIC( Test_bool3x2_uint3x2, TEMPER_FLAG_SHOULD_RUN, const uint3x2& convertFrom, const bool3x2& expectedAnswer )
{
	bool3x2 actualAnswer = bool3x2( convertFrom );

	TEMPER_CHECK_TRUE( expectedAnswer[0][0] == actualAnswer[0][0] );
	TEMPER_CHECK_TRUE( expectedAnswer[0][1] == actualAnswer[0][1] );

	TEMPER_CHECK_TRUE( expectedAnswer[1][0] == actualAnswer[1][0] );
	TEMPER_CHECK_TRUE( expectedAnswer[1][1] == actualAnswer[1][1] );

	TEMPER_CHECK_TRUE( expectedAnswer[2][0] == actualAnswer[2][0] );
	TEMPER_CHECK_TRUE( expectedAnswer[2][1] == actualAnswer[2][1] );

}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool3x2_uint3x2,
	uint3x2(
		0U, 0U,
		0U, 0U,
		0U, 0U
	),
	bool3x2(
		false, false,
		false, false,
		false, false
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool3x2_uint3x2,
	uint3x2(
		10U, 10U,
		10U, 10U,
		10U, 10U
	),
	bool3x2(
		true, true,
		true, true,
		true, true
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool3x2_uint3x2,
	uint3x2(
		10U, 20U,
		50U, 60U,
		90U, 100U
	),
	bool3x2(
		true, true,
		true, true,
		true, true
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool3x2_uint3x2,
	uint3x2(
		160U, 150U,
		120U, 110U,
		80U, 70U
	),
	bool3x2(
		true, true,
		true, true,
		true, true
	)
);

TEMPER_PARAMETRIC( Test_bool3x2_float3x2, TEMPER_FLAG_SHOULD_RUN, const float3x2& convertFrom, const bool3x2& expectedAnswer )
{
	bool3x2 actualAnswer = bool3x2( convertFrom );

	TEMPER_CHECK_TRUE( expectedAnswer[0][0] == actualAnswer[0][0] );
	TEMPER_CHECK_TRUE( expectedAnswer[0][1] == actualAnswer[0][1] );

	TEMPER_CHECK_TRUE( expectedAnswer[1][0] == actualAnswer[1][0] );
	TEMPER_CHECK_TRUE( expectedAnswer[1][1] == actualAnswer[1][1] );

	TEMPER_CHECK_TRUE( expectedAnswer[2][0] == actualAnswer[2][0] );
	TEMPER_CHECK_TRUE( expectedAnswer[2][1] == actualAnswer[2][1] );

}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool3x2_float3x2,
	float3x2(
		0.000000f, 0.000000f,
		0.000000f, 0.000000f,
		0.000000f, 0.000000f
	),
	bool3x2(
		false, false,
		false, false,
		false, false
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool3x2_float3x2,
	float3x2(
		10.000000f, 10.000000f,
		10.000000f, 10.000000f,
		10.000000f, 10.000000f
	),
	bool3x2(
		true, true,
		true, true,
		true, true
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool3x2_float3x2,
	float3x2(
		10.000000f, 20.000000f,
		50.000000f, 60.000000f,
		90.000000f, 100.000000f
	),
	bool3x2(
		true, true,
		true, true,
		true, true
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool3x2_float3x2,
	float3x2(
		160.000000f, 150.000000f,
		120.000000f, 110.000000f,
		80.000000f, 70.000000f
	),
	bool3x2(
		true, true,
		true, true,
		true, true
	)
);

TEMPER_PARAMETRIC( Test_bool3x2_double3x2, TEMPER_FLAG_SHOULD_RUN, const double3x2& convertFrom, const bool3x2& expectedAnswer )
{
	bool3x2 actualAnswer = bool3x2( convertFrom );

	TEMPER_CHECK_TRUE( expectedAnswer[0][0] == actualAnswer[0][0] );
	TEMPER_CHECK_TRUE( expectedAnswer[0][1] == actualAnswer[0][1] );

	TEMPER_CHECK_TRUE( expectedAnswer[1][0] == actualAnswer[1][0] );
	TEMPER_CHECK_TRUE( expectedAnswer[1][1] == actualAnswer[1][1] );

	TEMPER_CHECK_TRUE( expectedAnswer[2][0] == actualAnswer[2][0] );
	TEMPER_CHECK_TRUE( expectedAnswer[2][1] == actualAnswer[2][1] );

}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool3x2_double3x2,
	double3x2(
		0.000000f, 0.000000f,
		0.000000f, 0.000000f,
		0.000000f, 0.000000f
	),
	bool3x2(
		false, false,
		false, false,
		false, false
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool3x2_double3x2,
	double3x2(
		10.000000f, 10.000000f,
		10.000000f, 10.000000f,
		10.000000f, 10.000000f
	),
	bool3x2(
		true, true,
		true, true,
		true, true
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool3x2_double3x2,
	double3x2(
		10.000000f, 20.000000f,
		50.000000f, 60.000000f,
		90.000000f, 100.000000f
	),
	bool3x2(
		true, true,
		true, true,
		true, true
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool3x2_double3x2,
	double3x2(
		160.000000f, 150.000000f,
		120.000000f, 110.000000f,
		80.000000f, 70.000000f
	),
	bool3x2(
		true, true,
		true, true,
		true, true
	)
);

TEMPER_PARAMETRIC( Test_bool3x2_identity, TEMPER_FLAG_SHOULD_RUN, const bool3x2& matrix, const bool expectedAnswer )
{
	bool3x2 identityMat;
	identity( identityMat );
	bool isMatrixIdentity = ( identityMat == matrix );
	TEMPER_CHECK_TRUE( isMatrixIdentity == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool3x2_identity,
	bool3x2(
		true, false,
		false, true,
		false, false
	),
	true
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool3x2_identity,
	bool3x2(
		true, true,
		false, true,
		false, false
	),
	false
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool3x2_identity,
	bool3x2(
		true, false,
		true, true,
		false, false
	),
	false
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool3x2_identity,
	bool3x2(
		true, true,
		true, true,
		false, false
	),
	false
);

TEMPER_PARAMETRIC( Test_bool3x2_transpose, TEMPER_FLAG_SHOULD_RUN, const bool3x2& matrix, const bool2x3& expectedAnswer )
{
	bool2x3 actualResult = transpose( matrix );
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool3x2_transpose,
	bool3x2(
		true, false,
		false, true,
		false, false
	),
	bool2x3(
		true, false, false,
		false, true, false
	)
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_bool3x2_transpose,
	bool3x2(
		false, true,
		true, true,
		true, true
	),
	bool2x3(
		false, true, true,
		true, true, true
	)
);


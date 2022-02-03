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


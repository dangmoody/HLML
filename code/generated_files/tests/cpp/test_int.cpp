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

TEMPER_TEST_PARAMETRIC( Test_int32_t_min, TEMPER_FLAG_SHOULD_RUN, const int32_t lhs, const int32_t rhs, const int32_t expectedAnswer )
{
	int32_t actualResult = min( lhs, rhs );
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int32_t_min, 0, 1, 0 );

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int32_t_min, 1, 2, 1 );

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int32_t_min, 420, 69, 69 );

TEMPER_TEST_PARAMETRIC( Test_int32_t_max, TEMPER_FLAG_SHOULD_RUN, const int32_t lhs, const int32_t rhs, const int32_t expectedAnswer )
{
	int32_t actualResult = max( lhs, rhs );
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int32_t_max, 0, 1, 1 );

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int32_t_max, 1, 2, 2 );

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int32_t_max, 69, 420, 420 );

TEMPER_TEST_PARAMETRIC( Test_int32_t_saturate, TEMPER_FLAG_SHOULD_RUN, const int32_t x, const int32_t expectedAnswer )
{
	int32_t actualResult = saturate( x );
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int32_t_saturate, 0, 0 );

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int32_t_saturate, 1, 1 );

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int32_t_saturate, 2, 1 );

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int32_t_saturate, 3, 1 );

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int32_t_saturate, 10, 1 );

TEMPER_TEST_PARAMETRIC( Test_int32_t_sign, TEMPER_FLAG_SHOULD_RUN, const int32_t x, const int32_t expectedAnswer )
{
	int32_t actualResult = sign( x );
	TEMPER_CHECK_TRUE( actualResult == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int32_t_sign, 0, 0 );

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int32_t_sign, 1, 1 );

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int32_t_sign, 2, 1 );

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int32_t_sign, 3, 1 );

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int32_t_sign, -1, -1 );

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int32_t_sign, -2, -1 );

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int32_t_sign, -3, -1 );


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

#include "hlml.h"
#include <temper/temper.h>

TEMPER_TEST( TestArithmeticMultiplyScalar_float4 )
{
	const float4 a = float4( ( 2.0f ), ( 3.0f ), ( 4.0f ), ( 5.0f ) );
	const float b = 6.0f;

	float4 c = quaternion_mul(a, b);

	TEMPER_EXPECT_TRUE( c == float4( ( 12.0f ), ( 18.0f ), ( 24.0f ), ( 30.0f ) ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticMultiply_float4 )
{
	const float4 a = float4( ( 2.0f ), ( 3.0f ), ( 4.0f ), ( 5.0f ) );
	const float4 b = float4( ( 1.0f ), ( 3.0f ), ( 5.0f ), ( 7.0f ) );

	float4 c = quaternion_mul( a, b );

	TEMPER_EXPECT_TRUE( c == float4( ( 22.0f ), ( 30.0f ), ( 56.0f ), ( 4.0f ) ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticLength_float4 )
{
	const float4 a = float4( ( 2.0f ), ( 3.0f ), ( 4.0f ), ( 5.0f ) );

	float b = quaternion_length( a );

	TEMPER_EXPECT_TRUE( floateq( b, ( 7.34846925735f ) ) );

	TEMPER_PASS();
}

TEMPER_SUITE( Test_quaternion_float4 )
{
	TEMPER_RUN_TEST( TestArithmeticMultiplyScalar_float4 );
	TEMPER_RUN_TEST( TestArithmeticMultiply_float4 );
	TEMPER_RUN_TEST( TestArithmeticLength_float4 );
}

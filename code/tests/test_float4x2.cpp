/*
===========================================================================

hlml.
Copyright (c) Dan Moody 2019 - Present.

This file is part of hlml.

hlml is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

hlml is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with hlml.  If not, see <http://www.gnu.org/licenses/>.

===========================================================================
*/

// GENERATED FILE.  DO NOT EDIT.

#include "../../code/out/gen/hlml_functions_matrix.h"
#include "../../code/out/gen/hlml_functions_matrix_sse.h"

#include <temper/temper.h>

TEMPER_TEST( TestAssignment_float4x2 )
{
	float4x2 mat;

	// fill single value
	mat = float4x2( 999.0f );
	TEMPER_EXPECT_TRUE( mat[0] == float2( 999.000000f, 0.000000f ) );
	TEMPER_EXPECT_TRUE( mat[1] == float2( 0.000000f, 999.000000f ) );
	TEMPER_EXPECT_TRUE( mat[2] == float2( 0.000000f, 0.000000f ) );
	TEMPER_EXPECT_TRUE( mat[3] == float2( 0.000000f, 0.000000f ) );

	// row filling
	mat = float4x2(
		float2( 0.000000f, 1.000000f ),
		float2( 4.000000f, 5.000000f ),
		float2( 8.000000f, 9.000000f ),
		float2( 12.000000f, 13.000000f )
	);
	TEMPER_EXPECT_TRUE( mat[0] == float2( 0.000000f, 1.000000f ) );
	TEMPER_EXPECT_TRUE( mat[1] == float2( 4.000000f, 5.000000f ) );
	TEMPER_EXPECT_TRUE( mat[2] == float2( 8.000000f, 9.000000f ) );
	TEMPER_EXPECT_TRUE( mat[3] == float2( 12.000000f, 13.000000f ) );

	// all values filled
	mat = float4x2(
		16.000000f, 15.000000f,
		12.000000f, 11.000000f,
		8.000000f, 7.000000f,
		4.000000f, 3.000000f
	);
	TEMPER_EXPECT_TRUE( mat[0] == float2( 16.000000f, 15.000000f ) );
	TEMPER_EXPECT_TRUE( mat[1] == float2( 12.000000f, 11.000000f ) );
	TEMPER_EXPECT_TRUE( mat[2] == float2( 8.000000f, 7.000000f ) );
	TEMPER_EXPECT_TRUE( mat[3] == float2( 4.000000f, 3.000000f ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestComponentWiseArithmeticAddition_float4x2 )
{
	// scalar
	float4x2 answer = float4x2(
		7.000000f, 7.000000f,
		8.000000f, 8.000000f,
		15.000000f, 15.000000f,
		24.000000f, 24.000000f
	);

	float4x2 a = float4x2(
		6.000000f, 6.000000f,
		6.000000f, 6.000000f,
		12.000000f, 12.000000f,
		18.000000f, 18.000000f
	);
	float4x2 b = float4x2(
		1.000000f, 1.000000f,
		2.000000f, 2.000000f,
		3.000000f, 3.000000f,
		6.000000f, 6.000000f
	);
	float4x2 c = a + b;

	TEMPER_EXPECT_TRUE( c == answer );

	// SSE
	float a00[4] =	{ 6.000000f, 6.000000f, 6.000000f, 6.000000f };
	float a01[4] =	{ 6.000000f, 6.000000f, 6.000000f, 6.000000f };
	float a10[4] =	{ 6.000000f, 6.000000f, 6.000000f, 6.000000f };
	float a11[4] =	{ 6.000000f, 6.000000f, 6.000000f, 6.000000f };
	float a20[4] =	{ 12.000000f, 12.000000f, 12.000000f, 12.000000f };
	float a21[4] =	{ 12.000000f, 12.000000f, 12.000000f, 12.000000f };
	float a30[4] =	{ 18.000000f, 18.000000f, 18.000000f, 18.000000f };
	float a31[4] =	{ 18.000000f, 18.000000f, 18.000000f, 18.000000f };

	float b00[4] =	{ 1.000000f, 1.000000f, 1.000000f, 1.000000f };
	float b01[4] =	{ 1.000000f, 1.000000f, 1.000000f, 1.000000f };
	float b10[4] =	{ 2.000000f, 2.000000f, 2.000000f, 2.000000f };
	float b11[4] =	{ 2.000000f, 2.000000f, 2.000000f, 2.000000f };
	float b20[4] =	{ 3.000000f, 3.000000f, 3.000000f, 3.000000f };
	float b21[4] =	{ 3.000000f, 3.000000f, 3.000000f, 3.000000f };
	float b30[4] =	{ 6.000000f, 6.000000f, 6.000000f, 6.000000f };
	float b31[4] =	{ 6.000000f, 6.000000f, 6.000000f, 6.000000f };

	__m128 results[4][2];
	sse_input_add_float4x2_t in;
	in.lhs[0][0] = _mm_load_ps( a00 );
	in.lhs[0][1] = _mm_load_ps( a01 );
	in.lhs[1][0] = _mm_load_ps( a10 );
	in.lhs[1][1] = _mm_load_ps( a11 );
	in.lhs[2][0] = _mm_load_ps( a20 );
	in.lhs[2][1] = _mm_load_ps( a21 );
	in.lhs[3][0] = _mm_load_ps( a30 );
	in.lhs[3][1] = _mm_load_ps( a31 );

	in.rhs[0][0] = _mm_load_ps( b00 );
	in.rhs[0][1] = _mm_load_ps( b01 );
	in.rhs[1][0] = _mm_load_ps( b10 );
	in.rhs[1][1] = _mm_load_ps( b11 );
	in.rhs[2][0] = _mm_load_ps( b20 );
	in.rhs[2][1] = _mm_load_ps( b21 );
	in.rhs[3][0] = _mm_load_ps( b30 );
	in.rhs[3][1] = _mm_load_ps( b31 );

	comp_add_sse( &in, results );

	float arithmeticResults[4];

	_mm_store_ps( arithmeticResults, results[0][0] );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[0], answer[0][0] ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[1], answer[0][0] ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[2], answer[0][0] ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[3], answer[0][0] ) );

	_mm_store_ps( arithmeticResults, results[0][1] );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[0], answer[0][1] ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[1], answer[0][1] ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[2], answer[0][1] ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[3], answer[0][1] ) );

	_mm_store_ps( arithmeticResults, results[1][0] );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[0], answer[1][0] ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[1], answer[1][0] ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[2], answer[1][0] ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[3], answer[1][0] ) );

	_mm_store_ps( arithmeticResults, results[1][1] );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[0], answer[1][1] ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[1], answer[1][1] ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[2], answer[1][1] ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[3], answer[1][1] ) );

	_mm_store_ps( arithmeticResults, results[2][0] );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[0], answer[2][0] ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[1], answer[2][0] ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[2], answer[2][0] ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[3], answer[2][0] ) );

	_mm_store_ps( arithmeticResults, results[2][1] );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[0], answer[2][1] ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[1], answer[2][1] ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[2], answer[2][1] ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[3], answer[2][1] ) );

	_mm_store_ps( arithmeticResults, results[3][0] );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[0], answer[3][0] ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[1], answer[3][0] ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[2], answer[3][0] ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[3], answer[3][0] ) );

	_mm_store_ps( arithmeticResults, results[3][1] );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[0], answer[3][1] ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[1], answer[3][1] ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[2], answer[3][1] ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[3], answer[3][1] ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestComponentWiseArithmeticSubtraction_float4x2 )
{
	// scalar
	float4x2 answer = float4x2(
		5.000000f, 5.000000f,
		4.000000f, 4.000000f,
		9.000000f, 9.000000f,
		12.000000f, 12.000000f
	);

	float4x2 a = float4x2(
		6.000000f, 6.000000f,
		6.000000f, 6.000000f,
		12.000000f, 12.000000f,
		18.000000f, 18.000000f
	);
	float4x2 b = float4x2(
		1.000000f, 1.000000f,
		2.000000f, 2.000000f,
		3.000000f, 3.000000f,
		6.000000f, 6.000000f
	);
	float4x2 c = a - b;

	TEMPER_EXPECT_TRUE( c == answer );

	// SSE
	float a00[4] =	{ 6.000000f, 6.000000f, 6.000000f, 6.000000f };
	float a01[4] =	{ 6.000000f, 6.000000f, 6.000000f, 6.000000f };
	float a10[4] =	{ 6.000000f, 6.000000f, 6.000000f, 6.000000f };
	float a11[4] =	{ 6.000000f, 6.000000f, 6.000000f, 6.000000f };
	float a20[4] =	{ 12.000000f, 12.000000f, 12.000000f, 12.000000f };
	float a21[4] =	{ 12.000000f, 12.000000f, 12.000000f, 12.000000f };
	float a30[4] =	{ 18.000000f, 18.000000f, 18.000000f, 18.000000f };
	float a31[4] =	{ 18.000000f, 18.000000f, 18.000000f, 18.000000f };

	float b00[4] =	{ 1.000000f, 1.000000f, 1.000000f, 1.000000f };
	float b01[4] =	{ 1.000000f, 1.000000f, 1.000000f, 1.000000f };
	float b10[4] =	{ 2.000000f, 2.000000f, 2.000000f, 2.000000f };
	float b11[4] =	{ 2.000000f, 2.000000f, 2.000000f, 2.000000f };
	float b20[4] =	{ 3.000000f, 3.000000f, 3.000000f, 3.000000f };
	float b21[4] =	{ 3.000000f, 3.000000f, 3.000000f, 3.000000f };
	float b30[4] =	{ 6.000000f, 6.000000f, 6.000000f, 6.000000f };
	float b31[4] =	{ 6.000000f, 6.000000f, 6.000000f, 6.000000f };

	__m128 results[4][2];
	sse_input_sub_float4x2_t in;
	in.lhs[0][0] = _mm_load_ps( a00 );
	in.lhs[0][1] = _mm_load_ps( a01 );
	in.lhs[1][0] = _mm_load_ps( a10 );
	in.lhs[1][1] = _mm_load_ps( a11 );
	in.lhs[2][0] = _mm_load_ps( a20 );
	in.lhs[2][1] = _mm_load_ps( a21 );
	in.lhs[3][0] = _mm_load_ps( a30 );
	in.lhs[3][1] = _mm_load_ps( a31 );

	in.rhs[0][0] = _mm_load_ps( b00 );
	in.rhs[0][1] = _mm_load_ps( b01 );
	in.rhs[1][0] = _mm_load_ps( b10 );
	in.rhs[1][1] = _mm_load_ps( b11 );
	in.rhs[2][0] = _mm_load_ps( b20 );
	in.rhs[2][1] = _mm_load_ps( b21 );
	in.rhs[3][0] = _mm_load_ps( b30 );
	in.rhs[3][1] = _mm_load_ps( b31 );

	comp_sub_sse( &in, results );

	float arithmeticResults[4];

	_mm_store_ps( arithmeticResults, results[0][0] );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[0], answer[0][0] ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[1], answer[0][0] ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[2], answer[0][0] ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[3], answer[0][0] ) );

	_mm_store_ps( arithmeticResults, results[0][1] );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[0], answer[0][1] ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[1], answer[0][1] ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[2], answer[0][1] ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[3], answer[0][1] ) );

	_mm_store_ps( arithmeticResults, results[1][0] );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[0], answer[1][0] ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[1], answer[1][0] ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[2], answer[1][0] ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[3], answer[1][0] ) );

	_mm_store_ps( arithmeticResults, results[1][1] );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[0], answer[1][1] ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[1], answer[1][1] ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[2], answer[1][1] ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[3], answer[1][1] ) );

	_mm_store_ps( arithmeticResults, results[2][0] );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[0], answer[2][0] ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[1], answer[2][0] ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[2], answer[2][0] ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[3], answer[2][0] ) );

	_mm_store_ps( arithmeticResults, results[2][1] );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[0], answer[2][1] ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[1], answer[2][1] ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[2], answer[2][1] ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[3], answer[2][1] ) );

	_mm_store_ps( arithmeticResults, results[3][0] );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[0], answer[3][0] ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[1], answer[3][0] ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[2], answer[3][0] ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[3], answer[3][0] ) );

	_mm_store_ps( arithmeticResults, results[3][1] );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[0], answer[3][1] ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[1], answer[3][1] ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[2], answer[3][1] ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[3], answer[3][1] ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestComponentWiseArithmeticMultiplication_float4x2 )
{
	// scalar
	float4x2 answer = float4x2(
		6.000000f, 6.000000f,
		12.000000f, 12.000000f,
		36.000000f, 36.000000f,
		108.000000f, 108.000000f
	);

	float4x2 a = float4x2(
		6.000000f, 6.000000f,
		6.000000f, 6.000000f,
		12.000000f, 12.000000f,
		18.000000f, 18.000000f
	);
	float4x2 b = float4x2(
		1.000000f, 1.000000f,
		2.000000f, 2.000000f,
		3.000000f, 3.000000f,
		6.000000f, 6.000000f
	);
	float4x2 c = comp_mul( a, b );

	TEMPER_EXPECT_TRUE( c == answer );

	// SSE
	float a00[4] =	{ 6.000000f, 6.000000f, 6.000000f, 6.000000f };
	float a01[4] =	{ 6.000000f, 6.000000f, 6.000000f, 6.000000f };
	float a10[4] =	{ 6.000000f, 6.000000f, 6.000000f, 6.000000f };
	float a11[4] =	{ 6.000000f, 6.000000f, 6.000000f, 6.000000f };
	float a20[4] =	{ 12.000000f, 12.000000f, 12.000000f, 12.000000f };
	float a21[4] =	{ 12.000000f, 12.000000f, 12.000000f, 12.000000f };
	float a30[4] =	{ 18.000000f, 18.000000f, 18.000000f, 18.000000f };
	float a31[4] =	{ 18.000000f, 18.000000f, 18.000000f, 18.000000f };

	float b00[4] =	{ 1.000000f, 1.000000f, 1.000000f, 1.000000f };
	float b01[4] =	{ 1.000000f, 1.000000f, 1.000000f, 1.000000f };
	float b10[4] =	{ 2.000000f, 2.000000f, 2.000000f, 2.000000f };
	float b11[4] =	{ 2.000000f, 2.000000f, 2.000000f, 2.000000f };
	float b20[4] =	{ 3.000000f, 3.000000f, 3.000000f, 3.000000f };
	float b21[4] =	{ 3.000000f, 3.000000f, 3.000000f, 3.000000f };
	float b30[4] =	{ 6.000000f, 6.000000f, 6.000000f, 6.000000f };
	float b31[4] =	{ 6.000000f, 6.000000f, 6.000000f, 6.000000f };

	__m128 results[4][2];
	sse_input_mul_float4x2_t in;
	in.lhs[0][0] = _mm_load_ps( a00 );
	in.lhs[0][1] = _mm_load_ps( a01 );
	in.lhs[1][0] = _mm_load_ps( a10 );
	in.lhs[1][1] = _mm_load_ps( a11 );
	in.lhs[2][0] = _mm_load_ps( a20 );
	in.lhs[2][1] = _mm_load_ps( a21 );
	in.lhs[3][0] = _mm_load_ps( a30 );
	in.lhs[3][1] = _mm_load_ps( a31 );

	in.rhs[0][0] = _mm_load_ps( b00 );
	in.rhs[0][1] = _mm_load_ps( b01 );
	in.rhs[1][0] = _mm_load_ps( b10 );
	in.rhs[1][1] = _mm_load_ps( b11 );
	in.rhs[2][0] = _mm_load_ps( b20 );
	in.rhs[2][1] = _mm_load_ps( b21 );
	in.rhs[3][0] = _mm_load_ps( b30 );
	in.rhs[3][1] = _mm_load_ps( b31 );

	comp_mul_sse( &in, results );

	float arithmeticResults[4];

	_mm_store_ps( arithmeticResults, results[0][0] );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[0], answer[0][0] ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[1], answer[0][0] ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[2], answer[0][0] ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[3], answer[0][0] ) );

	_mm_store_ps( arithmeticResults, results[0][1] );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[0], answer[0][1] ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[1], answer[0][1] ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[2], answer[0][1] ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[3], answer[0][1] ) );

	_mm_store_ps( arithmeticResults, results[1][0] );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[0], answer[1][0] ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[1], answer[1][0] ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[2], answer[1][0] ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[3], answer[1][0] ) );

	_mm_store_ps( arithmeticResults, results[1][1] );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[0], answer[1][1] ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[1], answer[1][1] ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[2], answer[1][1] ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[3], answer[1][1] ) );

	_mm_store_ps( arithmeticResults, results[2][0] );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[0], answer[2][0] ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[1], answer[2][0] ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[2], answer[2][0] ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[3], answer[2][0] ) );

	_mm_store_ps( arithmeticResults, results[2][1] );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[0], answer[2][1] ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[1], answer[2][1] ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[2], answer[2][1] ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[3], answer[2][1] ) );

	_mm_store_ps( arithmeticResults, results[3][0] );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[0], answer[3][0] ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[1], answer[3][0] ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[2], answer[3][0] ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[3], answer[3][0] ) );

	_mm_store_ps( arithmeticResults, results[3][1] );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[0], answer[3][1] ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[1], answer[3][1] ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[2], answer[3][1] ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[3], answer[3][1] ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestComponentWiseArithmeticDivision_float4x2 )
{
	// scalar
	float4x2 answer = float4x2(
		6.000000f, 6.000000f,
		3.000000f, 3.000000f,
		4.000000f, 4.000000f,
		3.000000f, 3.000000f
	);

	float4x2 a = float4x2(
		6.000000f, 6.000000f,
		6.000000f, 6.000000f,
		12.000000f, 12.000000f,
		18.000000f, 18.000000f
	);
	float4x2 b = float4x2(
		1.000000f, 1.000000f,
		2.000000f, 2.000000f,
		3.000000f, 3.000000f,
		6.000000f, 6.000000f
	);
	float4x2 c = comp_div( a, b );

	TEMPER_EXPECT_TRUE( c == answer );

	// SSE
	float a00[4] =	{ 6.000000f, 6.000000f, 6.000000f, 6.000000f };
	float a01[4] =	{ 6.000000f, 6.000000f, 6.000000f, 6.000000f };
	float a10[4] =	{ 6.000000f, 6.000000f, 6.000000f, 6.000000f };
	float a11[4] =	{ 6.000000f, 6.000000f, 6.000000f, 6.000000f };
	float a20[4] =	{ 12.000000f, 12.000000f, 12.000000f, 12.000000f };
	float a21[4] =	{ 12.000000f, 12.000000f, 12.000000f, 12.000000f };
	float a30[4] =	{ 18.000000f, 18.000000f, 18.000000f, 18.000000f };
	float a31[4] =	{ 18.000000f, 18.000000f, 18.000000f, 18.000000f };

	float b00[4] =	{ 1.000000f, 1.000000f, 1.000000f, 1.000000f };
	float b01[4] =	{ 1.000000f, 1.000000f, 1.000000f, 1.000000f };
	float b10[4] =	{ 2.000000f, 2.000000f, 2.000000f, 2.000000f };
	float b11[4] =	{ 2.000000f, 2.000000f, 2.000000f, 2.000000f };
	float b20[4] =	{ 3.000000f, 3.000000f, 3.000000f, 3.000000f };
	float b21[4] =	{ 3.000000f, 3.000000f, 3.000000f, 3.000000f };
	float b30[4] =	{ 6.000000f, 6.000000f, 6.000000f, 6.000000f };
	float b31[4] =	{ 6.000000f, 6.000000f, 6.000000f, 6.000000f };

	__m128 results[4][2];
	sse_input_div_float4x2_t in;
	in.lhs[0][0] = _mm_load_ps( a00 );
	in.lhs[0][1] = _mm_load_ps( a01 );
	in.lhs[1][0] = _mm_load_ps( a10 );
	in.lhs[1][1] = _mm_load_ps( a11 );
	in.lhs[2][0] = _mm_load_ps( a20 );
	in.lhs[2][1] = _mm_load_ps( a21 );
	in.lhs[3][0] = _mm_load_ps( a30 );
	in.lhs[3][1] = _mm_load_ps( a31 );

	in.rhs[0][0] = _mm_load_ps( b00 );
	in.rhs[0][1] = _mm_load_ps( b01 );
	in.rhs[1][0] = _mm_load_ps( b10 );
	in.rhs[1][1] = _mm_load_ps( b11 );
	in.rhs[2][0] = _mm_load_ps( b20 );
	in.rhs[2][1] = _mm_load_ps( b21 );
	in.rhs[3][0] = _mm_load_ps( b30 );
	in.rhs[3][1] = _mm_load_ps( b31 );

	comp_div_sse( &in, results );

	float arithmeticResults[4];

	_mm_store_ps( arithmeticResults, results[0][0] );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[0], answer[0][0] ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[1], answer[0][0] ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[2], answer[0][0] ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[3], answer[0][0] ) );

	_mm_store_ps( arithmeticResults, results[0][1] );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[0], answer[0][1] ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[1], answer[0][1] ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[2], answer[0][1] ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[3], answer[0][1] ) );

	_mm_store_ps( arithmeticResults, results[1][0] );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[0], answer[1][0] ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[1], answer[1][0] ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[2], answer[1][0] ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[3], answer[1][0] ) );

	_mm_store_ps( arithmeticResults, results[1][1] );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[0], answer[1][1] ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[1], answer[1][1] ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[2], answer[1][1] ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[3], answer[1][1] ) );

	_mm_store_ps( arithmeticResults, results[2][0] );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[0], answer[2][0] ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[1], answer[2][0] ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[2], answer[2][0] ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[3], answer[2][0] ) );

	_mm_store_ps( arithmeticResults, results[2][1] );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[0], answer[2][1] ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[1], answer[2][1] ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[2], answer[2][1] ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[3], answer[2][1] ) );

	_mm_store_ps( arithmeticResults, results[3][0] );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[0], answer[3][0] ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[1], answer[3][0] ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[2], answer[3][0] ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[3], answer[3][0] ) );

	_mm_store_ps( arithmeticResults, results[3][1] );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[0], answer[3][1] ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[1], answer[3][1] ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[2], answer[3][1] ) );
	TEMPER_EXPECT_TRUE( floateq( arithmeticResults[3], answer[3][1] ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestMultiplyMatrix_float4x2 )
{
	// scalar
	float4x4 answer = float4x4(
		18.000000f, 18.000000f, 18.000000f, 18.000000f,
		18.000000f, 18.000000f, 18.000000f, 18.000000f,
		36.000000f, 36.000000f, 36.000000f, 36.000000f,
		54.000000f, 54.000000f, 54.000000f, 54.000000f
	);

	float4x2 a = float4x2(
		6.000000f, 6.000000f,
		6.000000f, 6.000000f,
		12.000000f, 12.000000f,
		18.000000f, 18.000000f
	);
	float2x4 b = float2x4(
		1.000000f, 1.000000f, 1.000000f, 1.000000f,
		2.000000f, 2.000000f, 2.000000f, 2.000000f
	);
	float4x4 c = a * b;

	TEMPER_EXPECT_TRUE( c == answer );

	TEMPER_PASS();
}

TEMPER_TEST( TestIncrement_float4x2 )
{
	float4x2 mat;

	// prefix
	mat = float4x2(
		0.000000f, 0.000000f,
		0.000000f, 0.000000f,
		0.000000f, 0.000000f,
		0.000000f, 0.000000f
	);
	++mat;
	TEMPER_EXPECT_TRUE( mat == float4x2(
		1.000000f, 1.000000f,
		1.000000f, 1.000000f,
		1.000000f, 1.000000f,
		1.000000f, 1.000000f
	) );

	// postfix
	mat = float4x2(
		0.000000f, 0.000000f,
		0.000000f, 0.000000f,
		0.000000f, 0.000000f,
		0.000000f, 0.000000f
	);
	mat++;
	TEMPER_EXPECT_TRUE( mat == float4x2(
		1.000000f, 1.000000f,
		1.000000f, 1.000000f,
		1.000000f, 1.000000f,
		1.000000f, 1.000000f
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestDecrement_float4x2 )
{
	float4x2 mat;

	// prefix
	mat = float4x2(
		1.000000f, 1.000000f,
		1.000000f, 1.000000f,
		1.000000f, 1.000000f,
		1.000000f, 1.000000f
	);
	--mat;
	TEMPER_EXPECT_TRUE( mat == float4x2(
		0.000000f, 0.000000f,
		0.000000f, 0.000000f,
		0.000000f, 0.000000f,
		0.000000f, 0.000000f
	) );

	// postfix
	mat = float4x2(
		1.000000f, 1.000000f,
		1.000000f, 1.000000f,
		1.000000f, 1.000000f,
		1.000000f, 1.000000f
	);
	mat--;
	TEMPER_EXPECT_TRUE( mat == float4x2(
		0.000000f, 0.000000f,
		0.000000f, 0.000000f,
		0.000000f, 0.000000f,
		0.000000f, 0.000000f
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestRelational_float4x2 )
{
	bool4x2 allTrue = bool4x2(
		true, true,
		true, true,
		true, true,
		true, true
	);

	float4x2 mat0 = float4x2(
		1.000000f, 1.000000f,
		1.000000f, 1.000000f,
		1.000000f, 1.000000f,
		1.000000f, 1.000000f
	);
	float4x2 mat1 = float4x2(
		2.000000f, 2.000000f,
		2.000000f, 2.000000f,
		2.000000f, 2.000000f,
		2.000000f, 2.000000f
	);
	float4x2 mat2 = float4x2(
		3.000000f, 3.000000f,
		3.000000f, 3.000000f,
		3.000000f, 3.000000f,
		3.000000f, 3.000000f
	);
	float4x2 mat3 = float4x2(
		4.000000f, 4.000000f,
		4.000000f, 4.000000f,
		4.000000f, 4.000000f,
		4.000000f, 4.000000f
	);

	bool4x2 test0  = mat0 <= mat0;
	bool4x2 test1  = mat0 >= mat0;
	bool4x2 test2  = mat0 <  mat1;
	bool4x2 test3  = mat0 <  mat2;
	bool4x2 test4  = mat0 <  mat3;

	bool4x2 test5  = mat1 >  mat0;
	bool4x2 test6  = mat1 <= mat1;
	bool4x2 test7  = mat1 >= mat1;
	bool4x2 test8  = mat1 <  mat2;
	bool4x2 test9  = mat1 <  mat3;

	bool4x2 test10 = mat2 >  mat0;
	bool4x2 test11 = mat2 >  mat1;
	bool4x2 test12 = mat2 <= mat2;
	bool4x2 test13 = mat2 >= mat2;
	bool4x2 test14 = mat2 <  mat3;

	bool4x2 test15 = mat3 >  mat0;
	bool4x2 test16 = mat3 >  mat1;
	bool4x2 test17 = mat3 >  mat2;
	bool4x2 test18 = mat3 <= mat3;
	bool4x2 test19 = mat3 >= mat3;

	TEMPER_EXPECT_TRUE( test0  == allTrue );
	TEMPER_EXPECT_TRUE( test1  == allTrue );
	TEMPER_EXPECT_TRUE( test2  == allTrue );
	TEMPER_EXPECT_TRUE( test3  == allTrue );
	TEMPER_EXPECT_TRUE( test4  == allTrue );

	TEMPER_EXPECT_TRUE( test5  == allTrue );
	TEMPER_EXPECT_TRUE( test6  == allTrue );
	TEMPER_EXPECT_TRUE( test7  == allTrue );
	TEMPER_EXPECT_TRUE( test8  == allTrue );
	TEMPER_EXPECT_TRUE( test9  == allTrue );

	TEMPER_EXPECT_TRUE( test10 == allTrue );
	TEMPER_EXPECT_TRUE( test11 == allTrue );
	TEMPER_EXPECT_TRUE( test12 == allTrue );
	TEMPER_EXPECT_TRUE( test13 == allTrue );
	TEMPER_EXPECT_TRUE( test14 == allTrue );

	TEMPER_EXPECT_TRUE( test15 == allTrue );
	TEMPER_EXPECT_TRUE( test16 == allTrue );
	TEMPER_EXPECT_TRUE( test17 == allTrue );
	TEMPER_EXPECT_TRUE( test18 == allTrue );
	TEMPER_EXPECT_TRUE( test19 == allTrue );

	TEMPER_PASS();
}

TEMPER_TEST( TestArray_float4x2 )
{
	float4x2 mat;

	TEMPER_EXPECT_TRUE( mat[0] == float2( 1.0f, 0.0f ) );
	TEMPER_EXPECT_TRUE( mat[1] == float2( 0.0f, 1.0f ) );
	TEMPER_EXPECT_TRUE( mat[2] == float2( 0.0f, 0.0f ) );
	TEMPER_EXPECT_TRUE( mat[3] == float2( 0.0f, 0.0f ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestIdentity_float4x2 )
{
	// scalar
	float4x2 id = float4x2(
		1.000000f, 0.0f,
		0.0f, 1.000000f,
		0.0f, 0.0f,
		0.0f, 0.0f
	);

	float4x2 mat;
	TEMPER_EXPECT_TRUE( mat == id );

	identity( mat );
	TEMPER_EXPECT_TRUE( mat == id );

	TEMPER_PASS();
}

TEMPER_TEST( TestTranspose_float4x2 )
{
	// scalar
	float4x2 mat = float4x2(
		0.000000f, 1.000000f,
		4.000000f, 5.000000f,
		8.000000f, 9.000000f,
		12.000000f, 13.000000f
	);
	float2x4 trans = transpose( mat );

	TEMPER_EXPECT_TRUE( trans == float2x4(
		0.000000f, 4.000000f, 8.000000f, 12.000000f,
		1.000000f, 5.000000f, 9.000000f, 13.000000f
	) );

	// SSE
	__m128 results[2][4];
	sse_input_transpose_float4x2_t in;

	// row 0
	in.m[0][0] = _mm_set1_ps( 0.0f );
	in.m[0][1] = _mm_set1_ps( 1.0f );

	// row 1
	in.m[1][0] = _mm_set1_ps( 4.0f );
	in.m[1][1] = _mm_set1_ps( 5.0f );

	// row 2
	in.m[2][0] = _mm_set1_ps( 8.0f );
	in.m[2][1] = _mm_set1_ps( 9.0f );

	// row 3
	in.m[3][0] = _mm_set1_ps( 12.0f );
	in.m[3][1] = _mm_set1_ps( 13.0f );

	transpose_sse( &in, results );

	float transposeResults[4];
	_mm_store_ps( transposeResults, results[0][0] );
	TEMPER_EXPECT_TRUE( floateq( transposeResults[0], trans[0][0] ) );
	TEMPER_EXPECT_TRUE( floateq( transposeResults[1], trans[0][0] ) );
	TEMPER_EXPECT_TRUE( floateq( transposeResults[2], trans[0][0] ) );
	TEMPER_EXPECT_TRUE( floateq( transposeResults[3], trans[0][0] ) );

	_mm_store_ps( transposeResults, results[0][1] );
	TEMPER_EXPECT_TRUE( floateq( transposeResults[0], trans[0][1] ) );
	TEMPER_EXPECT_TRUE( floateq( transposeResults[1], trans[0][1] ) );
	TEMPER_EXPECT_TRUE( floateq( transposeResults[2], trans[0][1] ) );
	TEMPER_EXPECT_TRUE( floateq( transposeResults[3], trans[0][1] ) );

	_mm_store_ps( transposeResults, results[0][2] );
	TEMPER_EXPECT_TRUE( floateq( transposeResults[0], trans[0][2] ) );
	TEMPER_EXPECT_TRUE( floateq( transposeResults[1], trans[0][2] ) );
	TEMPER_EXPECT_TRUE( floateq( transposeResults[2], trans[0][2] ) );
	TEMPER_EXPECT_TRUE( floateq( transposeResults[3], trans[0][2] ) );

	_mm_store_ps( transposeResults, results[0][3] );
	TEMPER_EXPECT_TRUE( floateq( transposeResults[0], trans[0][3] ) );
	TEMPER_EXPECT_TRUE( floateq( transposeResults[1], trans[0][3] ) );
	TEMPER_EXPECT_TRUE( floateq( transposeResults[2], trans[0][3] ) );
	TEMPER_EXPECT_TRUE( floateq( transposeResults[3], trans[0][3] ) );

	_mm_store_ps( transposeResults, results[1][0] );
	TEMPER_EXPECT_TRUE( floateq( transposeResults[0], trans[1][0] ) );
	TEMPER_EXPECT_TRUE( floateq( transposeResults[1], trans[1][0] ) );
	TEMPER_EXPECT_TRUE( floateq( transposeResults[2], trans[1][0] ) );
	TEMPER_EXPECT_TRUE( floateq( transposeResults[3], trans[1][0] ) );

	_mm_store_ps( transposeResults, results[1][1] );
	TEMPER_EXPECT_TRUE( floateq( transposeResults[0], trans[1][1] ) );
	TEMPER_EXPECT_TRUE( floateq( transposeResults[1], trans[1][1] ) );
	TEMPER_EXPECT_TRUE( floateq( transposeResults[2], trans[1][1] ) );
	TEMPER_EXPECT_TRUE( floateq( transposeResults[3], trans[1][1] ) );

	_mm_store_ps( transposeResults, results[1][2] );
	TEMPER_EXPECT_TRUE( floateq( transposeResults[0], trans[1][2] ) );
	TEMPER_EXPECT_TRUE( floateq( transposeResults[1], trans[1][2] ) );
	TEMPER_EXPECT_TRUE( floateq( transposeResults[2], trans[1][2] ) );
	TEMPER_EXPECT_TRUE( floateq( transposeResults[3], trans[1][2] ) );

	_mm_store_ps( transposeResults, results[1][3] );
	TEMPER_EXPECT_TRUE( floateq( transposeResults[0], trans[1][3] ) );
	TEMPER_EXPECT_TRUE( floateq( transposeResults[1], trans[1][3] ) );
	TEMPER_EXPECT_TRUE( floateq( transposeResults[2], trans[1][3] ) );
	TEMPER_EXPECT_TRUE( floateq( transposeResults[3], trans[1][3] ) );

	TEMPER_PASS();
}

TEMPER_SUITE( Test_float4x2 )
{
	TEMPER_RUN_TEST( TestAssignment_float4x2 );
	TEMPER_RUN_TEST( TestComponentWiseArithmeticAddition_float4x2 );
	TEMPER_RUN_TEST( TestComponentWiseArithmeticSubtraction_float4x2 );
	TEMPER_RUN_TEST( TestComponentWiseArithmeticMultiplication_float4x2 );
	TEMPER_RUN_TEST( TestComponentWiseArithmeticDivision_float4x2 );
	TEMPER_RUN_TEST( TestMultiplyMatrix_float4x2 );
	TEMPER_RUN_TEST( TestIncrement_float4x2 );
	TEMPER_RUN_TEST( TestDecrement_float4x2 );
	TEMPER_RUN_TEST( TestRelational_float4x2 );
	TEMPER_RUN_TEST( TestArray_float4x2 );
	TEMPER_RUN_TEST( TestIdentity_float4x2 );
	TEMPER_RUN_TEST( TestTranspose_float4x2 );
}

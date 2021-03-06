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

TEMPER_TEST( TestAssignment_uint4, TEMPER_FLAG_SHOULD_RUN )
{
	uint4 vec;

	vec.x = 1U;
	vec.y = 1U;
	vec.z = 1U;
	vec.w = 1U;
	TEMPER_CHECK_TRUE( vec.x == 1U );
	TEMPER_CHECK_TRUE( vec.y == 1U );
	TEMPER_CHECK_TRUE( vec.z == 1U );
	TEMPER_CHECK_TRUE( vec.w == 1U );

	vec.x = 0U;
	vec.y = 1U;
	vec.z = 2U;
	vec.w = 3U;
	TEMPER_CHECK_TRUE( vec.x == 0U );
	TEMPER_CHECK_TRUE( vec.y == 1U );
	TEMPER_CHECK_TRUE( vec.z == 2U );
	TEMPER_CHECK_TRUE( vec.w == 3U );
}

TEMPER_TEST( TestArithmeticAddition_uint4, TEMPER_FLAG_SHOULD_RUN )
{
	uint4 a = (uint4)	{ 6U, 6U, 6U, 6U };
	uint4 b = (uint4)	{ 2U, 3U, 4U, 5U };
	uint4 c = uint4_caddv( &a, &b );

	TEMPER_CHECK_TRUE( c.x == 8U );
	TEMPER_CHECK_TRUE( c.y == 9U );
	TEMPER_CHECK_TRUE( c.z == 10U );
	TEMPER_CHECK_TRUE( c.w == 11U );
}

TEMPER_TEST( TestArithmeticSubtraction_uint4, TEMPER_FLAG_SHOULD_RUN )
{
	uint4 a = (uint4)	{ 6U, 6U, 6U, 6U };
	uint4 b = (uint4)	{ 2U, 3U, 4U, 5U };
	uint4 c = uint4_csubv( &a, &b );

	TEMPER_CHECK_TRUE( c.x == 4U );
	TEMPER_CHECK_TRUE( c.y == 3U );
	TEMPER_CHECK_TRUE( c.z == 2U );
	TEMPER_CHECK_TRUE( c.w == 1U );
}

TEMPER_TEST( TestArithmeticMultiplication_uint4, TEMPER_FLAG_SHOULD_RUN )
{
	uint4 a = (uint4)	{ 6U, 6U, 6U, 6U };
	uint4 b = (uint4)	{ 2U, 3U, 4U, 5U };
	uint4 c = uint4_cmulv( &a, &b );

	TEMPER_CHECK_TRUE( c.x == 12U );
	TEMPER_CHECK_TRUE( c.y == 18U );
	TEMPER_CHECK_TRUE( c.z == 24U );
	TEMPER_CHECK_TRUE( c.w == 30U );
}

TEMPER_TEST( TestArithmeticDivision_uint4, TEMPER_FLAG_SHOULD_RUN )
{
	uint4 a = (uint4)	{ 6U, 6U, 6U, 6U };
	uint4 b = (uint4)	{ 2U, 2U, 3U, 6U };
	uint4 c = uint4_cdivv( &a, &b );

	TEMPER_CHECK_TRUE( c.x == 3U );
	TEMPER_CHECK_TRUE( c.y == 3U );
	TEMPER_CHECK_TRUE( c.z == 2U );
	TEMPER_CHECK_TRUE( c.w == 1U );
}

TEMPER_TEST( TestRelational_uint4, TEMPER_FLAG_SHOULD_RUN )
{
	uint4 vec0 =	{ 0U, 0U, 0U, 0U };
	uint4 vec1 =	{ 1U, 1U, 1U, 1U };
	uint4 vec2 =	{ 2U, 2U, 2U, 2U };
	uint4 vec3 =	{ 3U, 3U, 3U, 3U };

	bool4 test0  = uint4_cmple( &vec0, &vec0 );
	bool4 test1  = uint4_cmpge( &vec0, &vec0 );
	bool4 test2  = uint4_cmpl( &vec0, &vec1 );
	bool4 test3  = uint4_cmpl( &vec0, &vec2 );
	bool4 test4  = uint4_cmpl( &vec0, &vec3 );

	bool4 test5  = uint4_cmpg( &vec1, &vec0 );
	bool4 test6  = uint4_cmple( &vec1, &vec1 );
	bool4 test7  = uint4_cmpge( &vec1, &vec1 );
	bool4 test8  = uint4_cmpl( &vec1, &vec2 );
	bool4 test9  = uint4_cmpl( &vec1, &vec3 );

	bool4 test10 = uint4_cmpg( &vec2, &vec0 );
	bool4 test11 = uint4_cmpg( &vec2, &vec1 );
	bool4 test12 = uint4_cmple( &vec2, &vec2 );
	bool4 test13 = uint4_cmpge( &vec2, &vec2 );
	bool4 test14 = uint4_cmpl( &vec2, &vec3 );

	bool4 test15 = uint4_cmpg( &vec3, &vec0 );
	bool4 test16 = uint4_cmpg( &vec3, &vec1 );
	bool4 test17 = uint4_cmpg( &vec3, &vec2 );
	bool4 test18 = uint4_cmple( &vec3, &vec3 );
	bool4 test19 = uint4_cmpge( &vec3, &vec3 );

	TEMPER_CHECK_TRUE( bool4_all( &test0 ) );
	TEMPER_CHECK_TRUE( bool4_all( &test1 ) );
	TEMPER_CHECK_TRUE( bool4_all( &test2 ) );
	TEMPER_CHECK_TRUE( bool4_all( &test3 ) );
	TEMPER_CHECK_TRUE( bool4_all( &test4 ) );

	TEMPER_CHECK_TRUE( bool4_all( &test5 ) );
	TEMPER_CHECK_TRUE( bool4_all( &test6 ) );
	TEMPER_CHECK_TRUE( bool4_all( &test7 ) );
	TEMPER_CHECK_TRUE( bool4_all( &test8 ) );
	TEMPER_CHECK_TRUE( bool4_all( &test9 ) );

	TEMPER_CHECK_TRUE( bool4_all( &test10 ) );
	TEMPER_CHECK_TRUE( bool4_all( &test11 ) );
	TEMPER_CHECK_TRUE( bool4_all( &test12 ) );
	TEMPER_CHECK_TRUE( bool4_all( &test13 ) );
	TEMPER_CHECK_TRUE( bool4_all( &test14 ) );

	TEMPER_CHECK_TRUE( bool4_all( &test15 ) );
	TEMPER_CHECK_TRUE( bool4_all( &test16 ) );
	TEMPER_CHECK_TRUE( bool4_all( &test17 ) );
	TEMPER_CHECK_TRUE( bool4_all( &test18 ) );
	TEMPER_CHECK_TRUE( bool4_all( &test19 ) );
}

TEMPER_TEST( TestBitwise_And_uint4, TEMPER_FLAG_SHOULD_RUN )
{
	uint4 answer = (uint4) { 5U, 5U, 5U, 5U };

	uint4 a = (uint4) { 21U, 21U, 21U, 21U };
	uint4 b = (uint4) { 7U, 7U, 7U, 7U };

	uint4 c = uint4_cand( &a, &b );

	TEMPER_CHECK_TRUE( uint4_cmpe( &c, &answer ) );
}

TEMPER_TEST( TestBitwise_Or_uint4, TEMPER_FLAG_SHOULD_RUN )
{
	uint4 answer = (uint4) { 23U, 23U, 23U, 23U };

	uint4 a = (uint4) { 21U, 21U, 21U, 21U };
	uint4 b = (uint4) { 7U, 7U, 7U, 7U };

	uint4 c = uint4_cor( &a, &b );

	TEMPER_CHECK_TRUE( uint4_cmpe( &c, &answer ) );
}

TEMPER_TEST( TestBitwise_Xor_uint4, TEMPER_FLAG_SHOULD_RUN )
{
	uint4 answer = (uint4) { 18U, 18U, 18U, 18U };

	uint4 a = (uint4) { 21U, 21U, 21U, 21U };
	uint4 b = (uint4) { 7U, 7U, 7U, 7U };

	uint4 c = uint4_cxor( &a, &b );

	TEMPER_CHECK_TRUE( uint4_cmpe( &c, &answer ) );
}

TEMPER_TEST( TestBitwise_ShiftLeft_uint4, TEMPER_FLAG_SHOULD_RUN )
{
	uint4 answer = (uint4) { 4U, 4U, 4U, 4U };

	uint4 a = (uint4) { 1U, 1U, 1U, 1U };
	uint4 b = (uint4) { 2U, 2U, 2U, 2U };

	uint4 c = uint4_cshift_left( &a, &b );

	TEMPER_CHECK_TRUE( uint4_cmpe( &c, &answer ) );
}

TEMPER_TEST( TestBitwise_ShiftRight_uint4, TEMPER_FLAG_SHOULD_RUN )
{
	uint4 answer = (uint4) { 1U, 1U, 1U, 1U };

	uint4 a = (uint4) { 16U, 16U, 16U, 16U };
	uint4 b = (uint4) { 4U, 4U, 4U, 4U };

	uint4 c = uint4_cshift_right( &a, &b );

	TEMPER_CHECK_TRUE( uint4_cmpe( &c, &answer ) );
}

TEMPER_TEST( TestBitwise_Unary_uint4, TEMPER_FLAG_SHOULD_RUN )
{
	uint4 answer = (uint4) { (uint32_t) -1, (uint32_t) -1, (uint32_t) -1, (uint32_t) -1 };

	uint4 a = (uint4) { 0U, 0U, 0U, 0U };

	uint4 b = uint4_cunary( &a );

	TEMPER_CHECK_TRUE( uint4_cmpe( &b, &answer ) );
}

TEMPER_TEST( TestLength_Scalar_uint4, TEMPER_FLAG_SHOULD_RUN )
{
	uint4 vec = (uint4) { 2U, 2U, 2U, 2U };

	TEMPER_CHECK_TRUE( floateq( uint4_lengthsqr( &vec ), 16.0f ) );
	TEMPER_CHECK_TRUE( floateq( uint4_length( &vec ), 4.0f ) );
}

TEMPER_TEST( TestPacking_uint4, TEMPER_FLAG_SHOULD_RUN )
{
	uint32_t answerPacked = 0xFFFF00FF;
	uint4 vec = (uint4) { 255U, 255U, 0U, 255U };
	uint32_t packed = pack( &vec );
	TEMPER_CHECK_TRUE( packed == answerPacked );

	uint4 answerUnpacked = (uint4) { 255U, 255U, 0U, 255U };
	uint4 unpacked = unpack( packed );
	TEMPER_CHECK_TRUE( uint4_cmpe( &unpacked, &answerUnpacked ) );
}


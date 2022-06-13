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

#define NOMINMAX

#define TEMPER_IMPLEMENTATION
#include <temper/temper.h>

#include "../../../code/generated_files/c/hlml.h"

TEMPER_TEST( Test_TypeSizes, TEMPER_FLAG_SHOULD_RUN )
{
	TEMPER_CHECK_TRUE( sizeof( bool2 ) == 8 );
	TEMPER_CHECK_TRUE( sizeof( bool3 ) == 12 );
	TEMPER_CHECK_TRUE( sizeof( bool4 ) == 16 );
	TEMPER_CHECK_TRUE( sizeof( int2 ) == 8 );
	TEMPER_CHECK_TRUE( sizeof( int3 ) == 12 );
	TEMPER_CHECK_TRUE( sizeof( int4 ) == 16 );
	TEMPER_CHECK_TRUE( sizeof( uint2 ) == 8 );
	TEMPER_CHECK_TRUE( sizeof( uint3 ) == 12 );
	TEMPER_CHECK_TRUE( sizeof( uint4 ) == 16 );
	TEMPER_CHECK_TRUE( sizeof( float2 ) == 8 );
	TEMPER_CHECK_TRUE( sizeof( float3 ) == 12 );
	TEMPER_CHECK_TRUE( sizeof( float4 ) == 16 );
	TEMPER_CHECK_TRUE( sizeof( double2 ) == 16 );
	TEMPER_CHECK_TRUE( sizeof( double3 ) == 24 );
	TEMPER_CHECK_TRUE( sizeof( double4 ) == 32 );

	TEMPER_CHECK_TRUE( sizeof( bool2x2 ) == 16 );
	TEMPER_CHECK_TRUE( sizeof( bool2x3 ) == 24 );
	TEMPER_CHECK_TRUE( sizeof( bool2x4 ) == 32 );
	TEMPER_CHECK_TRUE( sizeof( bool3x2 ) == 24 );
	TEMPER_CHECK_TRUE( sizeof( bool3x3 ) == 36 );
	TEMPER_CHECK_TRUE( sizeof( bool3x4 ) == 48 );
	TEMPER_CHECK_TRUE( sizeof( bool4x2 ) == 32 );
	TEMPER_CHECK_TRUE( sizeof( bool4x3 ) == 48 );
	TEMPER_CHECK_TRUE( sizeof( bool4x4 ) == 64 );
	TEMPER_CHECK_TRUE( sizeof( int2x2 ) == 16 );
	TEMPER_CHECK_TRUE( sizeof( int2x3 ) == 24 );
	TEMPER_CHECK_TRUE( sizeof( int2x4 ) == 32 );
	TEMPER_CHECK_TRUE( sizeof( int3x2 ) == 24 );
	TEMPER_CHECK_TRUE( sizeof( int3x3 ) == 36 );
	TEMPER_CHECK_TRUE( sizeof( int3x4 ) == 48 );
	TEMPER_CHECK_TRUE( sizeof( int4x2 ) == 32 );
	TEMPER_CHECK_TRUE( sizeof( int4x3 ) == 48 );
	TEMPER_CHECK_TRUE( sizeof( int4x4 ) == 64 );
	TEMPER_CHECK_TRUE( sizeof( uint2x2 ) == 16 );
	TEMPER_CHECK_TRUE( sizeof( uint2x3 ) == 24 );
	TEMPER_CHECK_TRUE( sizeof( uint2x4 ) == 32 );
	TEMPER_CHECK_TRUE( sizeof( uint3x2 ) == 24 );
	TEMPER_CHECK_TRUE( sizeof( uint3x3 ) == 36 );
	TEMPER_CHECK_TRUE( sizeof( uint3x4 ) == 48 );
	TEMPER_CHECK_TRUE( sizeof( uint4x2 ) == 32 );
	TEMPER_CHECK_TRUE( sizeof( uint4x3 ) == 48 );
	TEMPER_CHECK_TRUE( sizeof( uint4x4 ) == 64 );
	TEMPER_CHECK_TRUE( sizeof( float2x2 ) == 16 );
	TEMPER_CHECK_TRUE( sizeof( float2x3 ) == 24 );
	TEMPER_CHECK_TRUE( sizeof( float2x4 ) == 32 );
	TEMPER_CHECK_TRUE( sizeof( float3x2 ) == 24 );
	TEMPER_CHECK_TRUE( sizeof( float3x3 ) == 36 );
	TEMPER_CHECK_TRUE( sizeof( float3x4 ) == 48 );
	TEMPER_CHECK_TRUE( sizeof( float4x2 ) == 32 );
	TEMPER_CHECK_TRUE( sizeof( float4x3 ) == 48 );
	TEMPER_CHECK_TRUE( sizeof( float4x4 ) == 64 );
	TEMPER_CHECK_TRUE( sizeof( double2x2 ) == 32 );
	TEMPER_CHECK_TRUE( sizeof( double2x3 ) == 48 );
	TEMPER_CHECK_TRUE( sizeof( double2x4 ) == 64 );
	TEMPER_CHECK_TRUE( sizeof( double3x2 ) == 48 );
	TEMPER_CHECK_TRUE( sizeof( double3x3 ) == 72 );
	TEMPER_CHECK_TRUE( sizeof( double3x4 ) == 96 );
	TEMPER_CHECK_TRUE( sizeof( double4x2 ) == 64 );
	TEMPER_CHECK_TRUE( sizeof( double4x3 ) == 96 );
	TEMPER_CHECK_TRUE( sizeof( double4x4 ) == 128 );
}

#include "test_int.c"
#include "test_uint.c"
#include "test_float.c"
#include "test_double.c"

#include "test_int2.c"
#include "test_int3.c"
#include "test_int4.c"
#include "test_uint2.c"
#include "test_uint3.c"
#include "test_uint4.c"
#include "test_float2.c"
#include "test_float3.c"
#include "test_float4.c"
#include "test_double2.c"
#include "test_double3.c"
#include "test_double4.c"

#include "test_quat_float4.c"
#include "test_quat_double4.c"

#include "test_int2x2.c"
#include "test_int2x3.c"
#include "test_int2x4.c"
#include "test_int3x2.c"
#include "test_int3x3.c"
#include "test_int3x4.c"
#include "test_int4x2.c"
#include "test_int4x3.c"
#include "test_int4x4.c"
#include "test_uint2x2.c"
#include "test_uint2x3.c"
#include "test_uint2x4.c"
#include "test_uint3x2.c"
#include "test_uint3x3.c"
#include "test_uint3x4.c"
#include "test_uint4x2.c"
#include "test_uint4x3.c"
#include "test_uint4x4.c"
#include "test_float2x2.c"
#include "test_float2x3.c"
#include "test_float2x4.c"
#include "test_float3x2.c"
#include "test_float3x3.c"
#include "test_float3x4.c"
#include "test_float4x2.c"
#include "test_float4x3.c"
#include "test_float4x4.c"
#include "test_double2x2.c"
#include "test_double2x3.c"
#include "test_double2x4.c"
#include "test_double3x2.c"
#include "test_double3x3.c"
#include "test_double3x4.c"
#include "test_double4x2.c"
#include "test_double4x3.c"
#include "test_double4x4.c"

#define TEST_PADDING "................................................................"

static void OnBeforeTest( const temperTestInfo_t* testInfo )
{
	const int padLengthMax = (int) strlen( TEST_PADDING );

	const int dotLength = padLengthMax - (int) strlen( testInfo->testNameStr );
	assert( dotLength );

	printf( "%s %*.*s ", testInfo->testNameStr, dotLength, dotLength, TEST_PADDING );
}

static void OnAfterTest( const temperTestInfo_t* testInfo )
{
	if ( testInfo->testingFlag == TEMPER_FLAG_SHOULD_SKIP )
	{
		TemperSetTextColorInternal( TEMPERDEV_COLOR_YELLOW );
		printf( "SKIPPED\n" );
		TemperSetTextColorInternal( TEMPERDEV_COLOR_DEFAULT );
	}
	else
	{
		if ( g_temperTestContext.currentTestErrorCount == 0 )
		{
			TemperSetTextColorInternal( TEMPERDEV_COLOR_GREEN );
			printf( "OK" );
			TemperSetTextColorInternal( TEMPERDEV_COLOR_DEFAULT );
		}
		else
		{
			TemperSetTextColorInternal( TEMPERDEV_COLOR_RED );
			printf( "FAILED\n" );
			TemperSetTextColorInternal( TEMPERDEV_COLOR_DEFAULT );
		}

		printf( " (%f %s)\n", testInfo->testTimeTaken, TemperGetTimeUnitStringInternal( g_temperTestContext.timeUnit ) );
	}
}

int main( int argc, char** argv )
{
	g_temperTestContext.callbacks.OnBeforeTest = OnBeforeTest;
	g_temperTestContext.callbacks.OnAfterTest = OnAfterTest;

	TEMPER_RUN( argc, argv );

	return TEMPER_GET_EXIT_CODE();
}

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

#include <temper.h>

static void OnSuiteEnd( void* userdata ) {
	( (void) userdata );
	printf( "\n" );
}

TEMPER_SUITE_EXTERN( Test_bool2 );
TEMPER_SUITE_EXTERN( Test_bool2x2 );
TEMPER_SUITE_EXTERN( Test_bool3x2 );
TEMPER_SUITE_EXTERN( Test_bool4x2 );

TEMPER_SUITE_EXTERN( Test_bool3 );
TEMPER_SUITE_EXTERN( Test_bool2x3 );
TEMPER_SUITE_EXTERN( Test_bool3x3 );
TEMPER_SUITE_EXTERN( Test_bool4x3 );

TEMPER_SUITE_EXTERN( Test_bool4 );
TEMPER_SUITE_EXTERN( Test_bool2x4 );
TEMPER_SUITE_EXTERN( Test_bool3x4 );
TEMPER_SUITE_EXTERN( Test_bool4x4 );

TEMPER_SUITE_EXTERN( Test_int2 );
TEMPER_SUITE_EXTERN( Test_int2x2 );
TEMPER_SUITE_EXTERN( Test_int3x2 );
TEMPER_SUITE_EXTERN( Test_int4x2 );

TEMPER_SUITE_EXTERN( Test_int3 );
TEMPER_SUITE_EXTERN( Test_int2x3 );
TEMPER_SUITE_EXTERN( Test_int3x3 );
TEMPER_SUITE_EXTERN( Test_int4x3 );

TEMPER_SUITE_EXTERN( Test_int4 );
TEMPER_SUITE_EXTERN( Test_int2x4 );
TEMPER_SUITE_EXTERN( Test_int3x4 );
TEMPER_SUITE_EXTERN( Test_int4x4 );

TEMPER_SUITE_EXTERN( Test_uint2 );
TEMPER_SUITE_EXTERN( Test_uint2x2 );
TEMPER_SUITE_EXTERN( Test_uint3x2 );
TEMPER_SUITE_EXTERN( Test_uint4x2 );

TEMPER_SUITE_EXTERN( Test_uint3 );
TEMPER_SUITE_EXTERN( Test_uint2x3 );
TEMPER_SUITE_EXTERN( Test_uint3x3 );
TEMPER_SUITE_EXTERN( Test_uint4x3 );

TEMPER_SUITE_EXTERN( Test_uint4 );
TEMPER_SUITE_EXTERN( Test_uint2x4 );
TEMPER_SUITE_EXTERN( Test_uint3x4 );
TEMPER_SUITE_EXTERN( Test_uint4x4 );

TEMPER_SUITE_EXTERN( Test_float2 );
TEMPER_SUITE_EXTERN( Test_float2x2 );
TEMPER_SUITE_EXTERN( Test_float3x2 );
TEMPER_SUITE_EXTERN( Test_float4x2 );

TEMPER_SUITE_EXTERN( Test_float3 );
TEMPER_SUITE_EXTERN( Test_float2x3 );
TEMPER_SUITE_EXTERN( Test_float3x3 );
TEMPER_SUITE_EXTERN( Test_float4x3 );

TEMPER_SUITE_EXTERN( Test_float4 );
TEMPER_SUITE_EXTERN( Test_float2x4 );
TEMPER_SUITE_EXTERN( Test_float3x4 );
TEMPER_SUITE_EXTERN( Test_float4x4 );

TEMPER_SUITE_EXTERN( Test_double2 );
TEMPER_SUITE_EXTERN( Test_double2x2 );
TEMPER_SUITE_EXTERN( Test_double3x2 );
TEMPER_SUITE_EXTERN( Test_double4x2 );

TEMPER_SUITE_EXTERN( Test_double3 );
TEMPER_SUITE_EXTERN( Test_double2x3 );
TEMPER_SUITE_EXTERN( Test_double3x3 );
TEMPER_SUITE_EXTERN( Test_double4x3 );

TEMPER_SUITE_EXTERN( Test_double4 );
TEMPER_SUITE_EXTERN( Test_double2x4 );
TEMPER_SUITE_EXTERN( Test_double3x4 );
TEMPER_SUITE_EXTERN( Test_double4x4 );

TEMPER_DEFS();

int main( int argc, char** argv ) {
	TEMPER_SET_COMMAND_LINE_ARGS( argc, argv );

	TEMPER_SET_SUITE_END_CALLBACK( OnSuiteEnd, nullptr );

	TEMPER_RUN_SUITE( Test_bool2 );
	TEMPER_RUN_SUITE( Test_bool2x2 );
	TEMPER_RUN_SUITE( Test_bool3x2 );
	TEMPER_RUN_SUITE( Test_bool4x2 );

	TEMPER_RUN_SUITE( Test_bool3 );
	TEMPER_RUN_SUITE( Test_bool2x3 );
	TEMPER_RUN_SUITE( Test_bool3x3 );
	TEMPER_RUN_SUITE( Test_bool4x3 );

	TEMPER_RUN_SUITE( Test_bool4 );
	TEMPER_RUN_SUITE( Test_bool2x4 );
	TEMPER_RUN_SUITE( Test_bool3x4 );
	TEMPER_RUN_SUITE( Test_bool4x4 );

	TEMPER_RUN_SUITE( Test_int2 );
	TEMPER_RUN_SUITE( Test_int2x2 );
	TEMPER_RUN_SUITE( Test_int3x2 );
	TEMPER_RUN_SUITE( Test_int4x2 );

	TEMPER_RUN_SUITE( Test_int3 );
	TEMPER_RUN_SUITE( Test_int2x3 );
	TEMPER_RUN_SUITE( Test_int3x3 );
	TEMPER_RUN_SUITE( Test_int4x3 );

	TEMPER_RUN_SUITE( Test_int4 );
	TEMPER_RUN_SUITE( Test_int2x4 );
	TEMPER_RUN_SUITE( Test_int3x4 );
	TEMPER_RUN_SUITE( Test_int4x4 );

	TEMPER_RUN_SUITE( Test_uint2 );
	TEMPER_RUN_SUITE( Test_uint2x2 );
	TEMPER_RUN_SUITE( Test_uint3x2 );
	TEMPER_RUN_SUITE( Test_uint4x2 );

	TEMPER_RUN_SUITE( Test_uint3 );
	TEMPER_RUN_SUITE( Test_uint2x3 );
	TEMPER_RUN_SUITE( Test_uint3x3 );
	TEMPER_RUN_SUITE( Test_uint4x3 );

	TEMPER_RUN_SUITE( Test_uint4 );
	TEMPER_RUN_SUITE( Test_uint2x4 );
	TEMPER_RUN_SUITE( Test_uint3x4 );
	TEMPER_RUN_SUITE( Test_uint4x4 );

	TEMPER_RUN_SUITE( Test_float2 );
	TEMPER_RUN_SUITE( Test_float2x2 );
	TEMPER_RUN_SUITE( Test_float3x2 );
	TEMPER_RUN_SUITE( Test_float4x2 );

	TEMPER_RUN_SUITE( Test_float3 );
	TEMPER_RUN_SUITE( Test_float2x3 );
	TEMPER_RUN_SUITE( Test_float3x3 );
	TEMPER_RUN_SUITE( Test_float4x3 );

	TEMPER_RUN_SUITE( Test_float4 );
	TEMPER_RUN_SUITE( Test_float2x4 );
	TEMPER_RUN_SUITE( Test_float3x4 );
	TEMPER_RUN_SUITE( Test_float4x4 );

	TEMPER_RUN_SUITE( Test_double2 );
	TEMPER_RUN_SUITE( Test_double2x2 );
	TEMPER_RUN_SUITE( Test_double3x2 );
	TEMPER_RUN_SUITE( Test_double4x2 );

	TEMPER_RUN_SUITE( Test_double3 );
	TEMPER_RUN_SUITE( Test_double2x3 );
	TEMPER_RUN_SUITE( Test_double3x3 );
	TEMPER_RUN_SUITE( Test_double4x3 );

	TEMPER_RUN_SUITE( Test_double4 );
	TEMPER_RUN_SUITE( Test_double2x4 );
	TEMPER_RUN_SUITE( Test_double3x4 );
	TEMPER_RUN_SUITE( Test_double4x4 );

	TEMPER_SHOW_STATS();

	return TEMPER_EXIT_CODE();
}
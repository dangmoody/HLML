/*
===========================================================================

HLML Generator.
Copyright (c) Dan Moody 2018 - Present.

This file is part of the HLML Generator.

The HLML Generator is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

The HLML Generator is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with The HLML Generator.  If not, see <http://www.gnu.org/licenses/>.

===========================================================================
*/

static const char* Gen_GetFuncName_Scalar_SSE( allocatorLinear_t* tempStorage, const genType_t type, const generatorFlags_t flags, const char* funcName ) {
	assert( tempStorage );
	assert( type != GEN_TYPE_COUNT );
	assert( funcName );

	const char* actualFuncName = Gen_GetFuncName_Scalar( tempStorage, type, flags, funcName );

	return String_TPrintf( tempStorage, "%s_sse", actualFuncName );
}

static void GenerateFunction_Radians_SSE( allocatorLinear_t* tempStorage, stringBuilder_t* code, const genType_t type, const generatorFlags_t flags ) {
	assert( tempStorage );
	assert( code );
	assert( type != GEN_TYPE_COUNT );

	const char* funcName = Gen_GetFuncName_Scalar_SSE( tempStorage, type, flags, GEN_FUNCTION_NAME_RADIANS );

	StringBuilder_Appendf( code, "inline static __m128 %s( const __m128 degrees )\n", funcName );
	StringBuilder_Append(  code, "{\n" );
	StringBuilder_Append(  code, "\treturn _mm_mul_ps( degrees, HLML_DEG_TO_RAD_SSE );\n" );
	StringBuilder_Append(  code, "}\n\n" );
}

static void GenerateFunction_Degrees_SSE( allocatorLinear_t* tempStorage, stringBuilder_t* code, const genType_t type, const generatorFlags_t flags ) {
	assert( tempStorage );
	assert( code );
	assert( type != GEN_TYPE_COUNT );

	const char* funcName = Gen_GetFuncName_Scalar_SSE( tempStorage, type, flags, GEN_FUNCTION_NAME_DEGREES );

	StringBuilder_Appendf( code, "inline static __m128 %s( const __m128 radians )\n", funcName );
	StringBuilder_Append(  code, "{\n" );
	StringBuilder_Append(  code, "\treturn _mm_mul_ps( radians, HLML_RAD_TO_DEG_SSE );\n" );
	StringBuilder_Append(  code, "}\n\n" );
}

static void GenerateFunction_Lerp_SSE( allocatorLinear_t* tempStorage, stringBuilder_t* code, const genType_t type, const generatorFlags_t flags ) {
	assert( tempStorage );
	assert( code );
	assert( type != GEN_TYPE_COUNT );

	const char* funcName = Gen_GetFuncName_Scalar_SSE( tempStorage, type, flags, GEN_FUNCTION_NAME_LERP );

	StringBuilder_Appendf( code, "inline static __m128 %s( const __m128 lhs, const __m128 rhs, const __m128 t )\n", funcName );
	StringBuilder_Append(  code, "{\n" );
	StringBuilder_Append(  code, "\t__m128 sub = _mm_sub_ps( HLML_ONE_SSE, t );\n" );
	StringBuilder_Append(  code, "\n" );
	StringBuilder_Append(  code, "\treturn _mm_add_ps(\n" );
	StringBuilder_Append(  code, "\t\t_mm_mul_ps( sub, lhs ),\n" );
	StringBuilder_Append(  code, "\t\t_mm_mul_ps( t, rhs )\n" );
	StringBuilder_Append(  code, "\t);\n" );
	StringBuilder_Append(  code, "}\n\n" );
}

static void GenerateScalarFiles_SSE( allocatorLinear_t* tempStorage, const char* generatedCodePath, const generatorFlags_t flags ) {
	assert( tempStorage );
	assert( generatedCodePath );

	bool32 cLinkage = flags & GENERATOR_FLAG_C_LINKAGE;

	stringBuilder_t* code = StringBuilder_Create( tempStorage, KILOBYTES( 12 ) );

	StringBuilder_Append( code,
		GEN_FILE_HEADER
		"#pragma once\n"
		"\n"
	);

	if ( cLinkage ) {
		StringBuilder_Append( code,
			"#ifdef __cplusplus\n"
			"extern \"C\" {\n"
			"#endif\n"
			"\n"
		);
	}

	StringBuilder_Append( code, "#include \"" GEN_HEADER_CONSTANTS_SSE "\"\n\n" );

	StringBuilder_Append( code, "#include <immintrin.h>\n" );

	if ( cLinkage ) {
		StringBuilder_Append( code,
			"#ifndef __cplusplus\n"
			"#include <stdbool.h>\n"
			"#endif\n"
			"\n"
		);
	}

	genType_t type = GEN_TYPE_FLOAT;

	const char* memberTypeString = Gen_GetMemberTypeString( type );

	printf( "SSE Scalar functions %s...", memberTypeString );

	StringBuilder_Appendf( code, "// %s\n", memberTypeString );

	GenerateFunction_Radians_SSE( tempStorage, code, type, flags );
	GenerateFunction_Degrees_SSE( tempStorage, code, type, flags );
	GenerateFunction_Lerp_SSE( tempStorage, code, type, flags );

	StringBuilder_Append( code, "\n" );

	printf( "OK.\n" );

	if ( cLinkage ) {
		StringBuilder_Append( code,
			"#ifdef __cplusplus\n"
			"}\n"
			"#endif\n"
		);
	}

	const char* fileNameHeader = String_TPrintf( tempStorage, "%s/%s.h", generatedCodePath, GEN_FILENAME_FUNCTIONS_SCALAR_SSE );

	FS_WriteEntireFile( fileNameHeader, code->str, code->length );

	Mem_Reset( tempStorage );
}
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
#include "gen_common.h"
#include "gen_doc_common.h"
#include "gen_common_sse.h"
#include "gen_scalar_cpp.h"
#include "gen_vector_cpp.h"
#include "gen_matrix_cpp.h"
#include "gen_funcs_vector.h"
#include "gen_funcs_matrix.h"
#include "gen_funcs_quaternion.h"
#include "gen_funcs_vector_sse.h"
#include "gen_funcs_matrix_sse.h"
#include "gen_quaternion_tests_cpp.h"

#include "defines.h"
#include "string_builder.h"
#include "allocator.h"
#include "file_io.h"

#include <assert.h>

static void GenerateOperatorIncrementInl( const genType_t type, const u32 numRows, const u32 numCols, const genOpIncrement_t op, stringBuilder_t* sbFwdDec, stringBuilder_t* sbImpl ) {
	assert( numRows >= 1 );	// 1 for vectors
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );
	assert( sbFwdDec );
	assert( sbImpl );

	u32 numComponents = ( numRows == 1 ) ? numCols : numRows;

	char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetFullTypeName( type, numRows, numCols, fullTypeName );

	const char* opStr = GEN_OPERATORS_INCREMENT[op];

	// prefix
	String_Append(  sbFwdDec, "// prefix\n" );
	Doc_OperatorIncrementPrefix( sbFwdDec, fullTypeName, op );
	String_Appendf( sbFwdDec, "inline %s& operator%s( %s& lhs );\n", fullTypeName, opStr, fullTypeName );
	String_Append(  sbFwdDec, "\n" );

	String_Appendf( sbImpl, "%s& operator%s( %s& lhs )\n", fullTypeName, opStr, fullTypeName );
	String_Append(  sbImpl, "{\n" );
	for ( u32 i = 0; i < numComponents; i++ ) {
		String_Appendf( sbImpl, "\t%slhs[%d];\n", opStr, i );
	}
	String_Append( sbImpl, "\treturn lhs;\n" );
	String_Append( sbImpl, "}\n" );
	String_Append( sbImpl, "\n" );

	// postfix
	String_Append(  sbFwdDec, "// postfix\n" );
	Doc_OperatorIncrementPostfix( sbFwdDec, fullTypeName, op );
	String_Appendf( sbFwdDec, "inline %s& operator%s( %s& lhs, const int );\n", fullTypeName, opStr, fullTypeName );

	String_Appendf( sbImpl, "%s& operator%s( %s& lhs, const int )\n", fullTypeName, opStr, fullTypeName );
	String_Append(  sbImpl, "{\n" );
	for ( u32 i = 0; i < numComponents; i++ ) {
		String_Appendf( sbImpl, "\tlhs[%d]%s;\n", i, opStr );
	}
	String_Append( sbImpl, "\treturn lhs;\n" );
	String_Append( sbImpl, "}\n" );
	String_Append( sbImpl, "\n" );
}


void Gen_HeaderMain( allocatorLinear_t* allocator, const genLanguage_t language ) {
	assert( allocator );

	const char* outGenFolder = GEN_FOLDER_PATHS_OUT_GEN[language];

	printf( "%s%s...", outGenFolder, GEN_HEADER_MAIN );

	char headerFilePath[1024] = { 0 };
	snprintf( headerFilePath, 1024, "%s%s", outGenFolder, GEN_HEADER_MAIN );

	stringBuilder_t sb = String_Create( allocator, 8 * KB_TO_BYTES );

	String_Append( &sb, GEN_FILE_HEADER );
	String_Append( &sb,
		"#pragma once\n"
		"\n"
	);

	if ( language == GEN_LANGUAGE_C ) {
		String_Append( &sb,
			"#ifdef __cplusplus\n"
			"extern \"C\" {\n"
			"#endif\n"
			"\n"
		);
	}

	// include vectors
	for ( u32 typeIndex = 0; typeIndex < GEN_TYPE_COUNT; typeIndex++ ) {
		const genType_t type = (genType_t) typeIndex;

		for ( u32 componentIndex = GEN_COMPONENT_COUNT_MIN; componentIndex <= GEN_COMPONENT_COUNT_MAX; componentIndex++ ) {
			char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
			Gen_GetFullTypeName( type, 1, componentIndex, fullTypeName );

			String_Appendf( &sb, "#include \"%s.h\"\n", fullTypeName );
		}

		String_Append( &sb, "\n" );
	}

	// include matrices
	for ( u32 typeIndex = 0; typeIndex < GEN_TYPE_COUNT; typeIndex++ ) {
		const genType_t type = (genType_t) typeIndex;

		for ( u32 rows = GEN_COMPONENT_COUNT_MIN; rows <= GEN_COMPONENT_COUNT_MAX; rows++ ) {
			for ( u32 cols = GEN_COMPONENT_COUNT_MIN; cols <= GEN_COMPONENT_COUNT_MAX; cols++ ) {
				char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
				Gen_GetFullTypeName( type, rows, cols, fullTypeName );

				String_Appendf( &sb, "#include \"%s.h\"\n", fullTypeName );
			}
		}

		String_Append( &sb, "\n" );
	}

	if ( language == GEN_LANGUAGE_CPP ) {
		String_Append( &sb, "\n" );

		// include vectors
		for ( u32 typeIndex = 0; typeIndex < GEN_TYPE_COUNT; typeIndex++ ) {
			const genType_t type = (genType_t) typeIndex;

			for ( u32 componentIndex = GEN_COMPONENT_COUNT_MIN; componentIndex <= GEN_COMPONENT_COUNT_MAX; componentIndex++ ) {
				char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
				Gen_GetFullTypeName( type, 1, componentIndex, fullTypeName );

				String_Appendf( &sb, "#include \"%s.inl\"\n", fullTypeName );
			}

			String_Append( &sb, "\n" );
		}

		// include matrices
		for ( u32 typeIndex = 0; typeIndex < GEN_TYPE_COUNT; typeIndex++ ) {
			const genType_t type = (genType_t) typeIndex;

			for ( u32 rows = GEN_COMPONENT_COUNT_MIN; rows <= GEN_COMPONENT_COUNT_MAX; rows++ ) {
				for ( u32 cols = GEN_COMPONENT_COUNT_MIN; cols <= GEN_COMPONENT_COUNT_MAX; cols++ ) {
					char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
					Gen_GetFullTypeName( type, rows, cols, fullTypeName );

					String_Appendf( &sb, "#include \"%s.inl\"\n", fullTypeName );
				}
			}

			String_Append( &sb, "\n" );
		}
	}

	// include operators
	if ( language == GEN_LANGUAGE_CPP ) {
		String_Appendf( &sb, "#include \"" GEN_FILENAME_OPERATORS_VECTOR ".h\"\n" );
		String_Appendf( &sb, "#include \"" GEN_FILENAME_OPERATORS_MATRIX ".h\"\n" );
		String_Append(  &sb, "\n" );
	}

	// include functions
	String_Appendf( &sb, "#include \"" GEN_FILENAME_FUNCTIONS_SCALAR ".h\"\n" );
	String_Appendf( &sb, "#include \"" GEN_FILENAME_FUNCTIONS_VECTOR ".h\"\n" );
	String_Appendf( &sb, "#include \"" GEN_FILENAME_FUNCTIONS_MATRIX ".h\"\n" );
	String_Appendf( &sb, "#include \"" GEN_FILENAME_FUNCTIONS_QUATERNION ".h\"\n" );
	String_Append(  &sb, "\n" );

	// include SSE helpers
	String_Appendf( &sb, "#include \"" GEN_FILENAME_FUNCTIONS_SCALAR_SSE ".h\"\n" );
	String_Appendf( &sb, "#include \"" GEN_FILENAME_FUNCTIONS_VECTOR_SSE ".h\"\n" );
	String_Appendf( &sb, "#include \"" GEN_FILENAME_FUNCTIONS_MATRIX_SSE ".h\"\n" );
	String_Append( &sb, "\n" );

	if ( language == GEN_LANGUAGE_C ) {
		String_Append( &sb,
			"#ifdef __cplusplus\n"
			"}\n"
			"#endif\n"
		);
	}

	FS_WriteEntireFile( headerFilePath, sb.str, sb.length );

	Mem_Reset( allocator );

	printf( "OK.\n" );
}

void Gen_FunctionsScalar( allocatorLinear_t* allocator, const genLanguage_t language ) {
	char fileNameHeader[1024];
	snprintf( fileNameHeader, 1024, "%s%s.h", GEN_FOLDER_PATHS_OUT_GEN[language], GEN_FILENAME_FUNCTIONS_SCALAR );

	stringBuilder_t sbFwdDec = String_Create( allocator, 9 * KB_TO_BYTES );
	stringBuilder_t sbImpl = String_Create( allocator, 9 * KB_TO_BYTES );

	stringBuilder_t sb = String_Create( allocator, sbFwdDec.alloc + sbImpl.alloc );

	String_Append( &sbFwdDec, GEN_FILE_HEADER );
	String_Append( &sbFwdDec,
		"#pragma once\n"
		"\n"
	);

	if ( language == GEN_LANGUAGE_C ) {
		String_Append( &sbFwdDec,
			"#ifdef __cplusplus\n"
			"extern \"C\" {\n"
			"#endif\n"
			"\n"
		);
	}

	String_Append( &sbFwdDec,
		"#include \"../" GEN_HEADER_CONSTANTS "\"\n"
		"\n"
		"#include <math.h>\n"
		"#include <stdint.h>\n"
		"\n"
		"#ifndef __cplusplus\n"
		"#include <stdbool.h>\n"
		"#endif\n"
		"\n"
	);

	for ( u32 typeIndex = 0; typeIndex < GEN_TYPE_COUNT; typeIndex++ ) {
		genType_t type = (genType_t) typeIndex;

		if ( type == GEN_TYPE_BOOL ) {
			continue;
		}

		const char* memberTypeString = Gen_GetMemberTypeString( type );

		printf( "Generating %s...", memberTypeString );

		String_Appendf( &sbFwdDec, "// %s\n", memberTypeString );

		// scalar only funcs
		Gen_Floateq( type, &sbFwdDec, &sbImpl );

		Gen_Sign( type, &sbFwdDec, &sbImpl );

		Gen_Radians( type, &sbFwdDec, &sbImpl );
		Gen_Degrees( type, &sbFwdDec, &sbImpl );

		Gen_MinMax( type, &sbFwdDec, &sbImpl );
		Gen_Clamp( type, &sbFwdDec, &sbImpl );

		// generic/scalar/vector funcs
		Gen_Saturate( GEN_LANGUAGE_C, type, 1, &sbFwdDec, &sbImpl );
		Gen_Lerp( GEN_LANGUAGE_C, type, 1, &sbFwdDec, &sbImpl );
		Gen_Step( GEN_LANGUAGE_C, type, 1, &sbFwdDec, &sbImpl );
		Gen_Smoothstep( GEN_LANGUAGE_C, type, 1, &sbFwdDec, &sbImpl );

		String_Append( &sbFwdDec, "\n" );

		printf( "OK.\n" );
	}

	String_Append( &sb, sbFwdDec.str );

	if ( language == GEN_LANGUAGE_C ) {
		String_Append( &sbImpl,
			"#ifdef __cplusplus\n"
			"}\n"
			"#endif\n"
		);
	}

	String_Append( &sb, sbImpl.str );

	FS_WriteEntireFile( fileNameHeader, sb.str, sb.length );

	Mem_Reset( allocator );
}

void Gen_FunctionsVector( allocatorLinear_t* allocator, const genLanguage_t language ) {
	assert( allocator );

	char filePathHeader[64] = { 0 };
	snprintf( filePathHeader, 64, "%s%s.h", GEN_FOLDER_PATHS_OUT_GEN[language], GEN_FILENAME_FUNCTIONS_VECTOR );

	stringBuilder_t contentFwdDec = String_Create( allocator, 128 * KB_TO_BYTES );
	stringBuilder_t contentImpl = String_Create( allocator, 128 * KB_TO_BYTES );

	stringBuilder_t content = String_Create( allocator, contentFwdDec.alloc + contentImpl.alloc );

	String_Append( &contentFwdDec, GEN_FILE_HEADER );
	String_Append( &contentFwdDec,
		"#pragma once\n"
		"\n"
	);

	if ( language == GEN_LANGUAGE_C ) {
		String_Append( &contentFwdDec,
			"#ifdef __cplusplus\n"
			"extern \"C\" {\n"
			"#endif\n"
			"\n"
		);
	}

	String_Append( &contentFwdDec,
		"#include \"../" GEN_HEADER_DEFINES "\"\n"
		"\n"
	);

	// includes
	for ( u32 typeIndex = 0; typeIndex < GEN_TYPE_COUNT; typeIndex++ ) {
		genType_t type = (genType_t) typeIndex;

		const char* typeString = Gen_GetTypeString( type );

		for ( u32 componentIndex = GEN_COMPONENT_COUNT_MIN; componentIndex <= GEN_COMPONENT_COUNT_MAX; componentIndex++ ) {
			String_Appendf( &contentFwdDec, "#include \"%s%d.h\"\n", typeString, componentIndex );
		}

		String_Appendf( &contentFwdDec, "\n" );
	}

	String_Appendf( &contentFwdDec, "#include \"" GEN_FILENAME_FUNCTIONS_SCALAR ".h\"\n" );
	if ( language == GEN_LANGUAGE_CPP ) {
		String_Appendf( &contentFwdDec, "#include \"" GEN_FILENAME_OPERATORS_VECTOR ".h\"\n" );
	}
	String_Appendf( &contentFwdDec, "\n" );

	// actual functions
	for ( u32 typeIndex = 0; typeIndex < GEN_TYPE_COUNT; typeIndex++ ) {
		genType_t type = (genType_t) typeIndex;

		const char* typeString = Gen_GetTypeString( type );

		for ( u32 componentIndex = GEN_COMPONENT_COUNT_MIN; componentIndex <= GEN_COMPONENT_COUNT_MAX; componentIndex++ ) {
			printf( "Functions %s%d...", typeString, componentIndex );

			String_Appendf( &contentFwdDec, "// %s%d\n", typeString, componentIndex );

			// generic scalar funcs
			Gen_Saturate( language, type, componentIndex, &contentFwdDec, &contentImpl );
			Gen_Lerp( language, type, componentIndex, &contentFwdDec, &contentImpl );
			Gen_Step( language, type, componentIndex, &contentFwdDec, &contentImpl );
			Gen_Smoothstep( language, type, componentIndex, &contentFwdDec, &contentImpl );

			// generic vector funcs
			Gen_FunctionAll( language, type, 1, componentIndex, &contentFwdDec, &contentImpl );
			Gen_VectorFunctionsEquals( language, type, componentIndex, &contentFwdDec, &contentImpl );
			Gen_VectorFunctionsComponentWiseArithmetic( language, type, componentIndex, &contentFwdDec, &contentImpl );
			Gen_VectorFunctionsComponentWiseBitwise( language, type, componentIndex, &contentFwdDec, &contentImpl );
			Gen_VectorFunctionsComponentWiseRelational( language, type, componentIndex, &contentFwdDec, &contentImpl );
			Gen_Negate( language, type, 1, componentIndex, &contentFwdDec, &contentImpl );

			// vector-specific funcs
			Gen_VectorLength( language, type, componentIndex, &contentFwdDec, &contentImpl );
			Gen_VectorNormalize( language, type, componentIndex, &contentFwdDec, &contentImpl );
			Gen_VectorDot( language, type, componentIndex, &contentFwdDec, &contentImpl );
			Gen_VectorCross( language, type, componentIndex, &contentFwdDec, &contentImpl );
			Gen_VectorAngle( language, type, componentIndex, &contentFwdDec, &contentImpl );
			Gen_VectorDistance( language, type, componentIndex, &contentFwdDec, &contentImpl );
			Gen_VectorPack( language, type, componentIndex, &contentFwdDec, &contentImpl );
			Gen_VectorUnpack( type, componentIndex, &contentFwdDec, &contentImpl );

			String_Append( &contentFwdDec, "\n" );

			printf( "OK.\n" );
		}
	}

	String_Append( &content, contentFwdDec.str );
	String_Append( &content, contentImpl.str );

	if ( language == GEN_LANGUAGE_C ) {
		String_Append( &content,
			"#ifdef __cplusplus\n"
			"}\n"
			"#endif\n"
			"\n"
		);
	}

	FS_WriteEntireFile( filePathHeader, content.str, content.length );

	Mem_Reset( allocator );
}

void Gen_FunctionsMatrix( allocatorLinear_t* allocator, const genLanguage_t language ) {
	assert( allocator );

	char filePathHeader[64] = { 0 };
	snprintf( filePathHeader, 64, "%s%s.h", GEN_FOLDER_PATHS_OUT_GEN[language], GEN_FILENAME_FUNCTIONS_MATRIX );

	stringBuilder_t contentFwdDec = String_Create( allocator, 512 * KB_TO_BYTES );
	stringBuilder_t contentImpl = String_Create( allocator, 512 * KB_TO_BYTES );

	stringBuilder_t content = String_Create( allocator, contentFwdDec.alloc + contentImpl.alloc );

	String_Append( &contentFwdDec, GEN_FILE_HEADER );

	if ( language == GEN_LANGUAGE_C ) {
		String_Append( &contentFwdDec,
			"#ifdef __cplusplus\n"
			"extern \"C\" {\n"
			"#endif\n"
			"\n"
		);
	}

	for ( u32 typeIndex = 0; typeIndex < GEN_TYPE_COUNT; typeIndex++ ) {
		genType_t type = (genType_t) typeIndex;

		const char* typeString = Gen_GetTypeString( type );

		for ( u32 row = GEN_COMPONENT_COUNT_MIN; row <= GEN_COMPONENT_COUNT_MAX; row++ ) {
			for ( u32 col = GEN_COMPONENT_COUNT_MIN; col <= GEN_COMPONENT_COUNT_MAX; col++ ) {
				String_Appendf( &contentFwdDec, "#include \"%s%dx%d.h\"\n", typeString, row, col );
			}
		}

		String_Appendf( &contentFwdDec, "\n" );
	}

	String_Appendf( &contentFwdDec, "#include \"" GEN_FILENAME_FUNCTIONS_VECTOR ".h\"\n" );
	String_Appendf( &contentFwdDec, "\n" );

	for ( u32 typeIndex = 0; typeIndex < GEN_TYPE_COUNT; typeIndex++ ) {
		genType_t type = (genType_t) typeIndex;

		for ( u32 row = GEN_COMPONENT_COUNT_MIN; row <= GEN_COMPONENT_COUNT_MAX; row++ ) {
			for ( u32 col = GEN_COMPONENT_COUNT_MIN; col <= GEN_COMPONENT_COUNT_MAX; col++ ) {
				char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
				Gen_GetFullTypeName( type, row, col, fullTypeName );

				printf( "Basic functions %s...", fullTypeName );

				String_Appendf( &contentFwdDec, "// %s\n", fullTypeName );

				Gen_FunctionAll( language, type, row, col, &contentFwdDec, &contentImpl );
				Gen_MatrixEquals( language, type, row, col, &contentFwdDec, &contentImpl );
				Gen_MatrixComponentWiseArithmetic( language, type, row, col, &contentFwdDec, &contentImpl );
				Gen_MatrixComponentWiseBitwise( language, type, row, col, &contentFwdDec, &contentImpl );
				Gen_MatrixComponentWiseRelational( language, type, row, col, &contentFwdDec, &contentImpl );

				Gen_MatrixIdentity( language, type, row, col, &contentFwdDec, &contentImpl );
				Gen_MatrixTranspose( language, type, row, col, &contentFwdDec, &contentImpl );

				Gen_MatrixDeterminant( language, type, row, col, &contentFwdDec, &contentImpl );
				Gen_MatrixInverse( language, type, row, col, &contentFwdDec, &contentImpl );

				Gen_MatrixMultiply( language, type, row, col, &contentFwdDec, &contentImpl );
				Gen_MatrixMultiplyVector( language, type, row, col, &contentFwdDec, &contentImpl );

				Gen_MatrixTranslate( language, type, row, col, &contentFwdDec, &contentImpl );
				Gen_MatrixRotate( allocator, language, type, row, col, &contentFwdDec, &contentImpl );
				Gen_MatrixScale( language, type, row, col, &contentFwdDec, &contentImpl );

				Gen_MatrixOrtho( language, type, row, col, &contentFwdDec, &contentImpl );
				Gen_MatrixPerspective( language, type, row, col, &contentFwdDec, &contentImpl );
				Gen_MatrixLookAt( language, type, row, col, &contentFwdDec, &contentImpl );

				String_Append( &contentFwdDec, "\n" );

				printf( "OK.\n" );
			}
		}
	}

	String_Append( &contentImpl,
		"#if defined( __GNUC__ ) || defined( __clang__ )\n"
		"#pragma GCC diagnostic pop\n"
		"#endif\n"
	);

	String_Append( &content, contentFwdDec.str );
	String_Append( &content, "\n" );
	String_Append( &content,
		"#pragma once\n"
		"\n"
		"// ignore missing brace initializers\n"
		"#if defined( __GNUC__ ) || defined( __clang__ )\n"
		"#pragma GCC diagnostic push\n"
		"#pragma GCC diagnostic ignored \"-Wmissing-braces\"\n"
		"#endif\n"
		"\n"
	);

	if ( language == GEN_LANGUAGE_C ) {
		String_Append( &contentImpl,
			"\n"
			"#ifdef __cplusplus\n"
			"}\n"
			"#endif\n"
		);
	}

	String_Append( &content, contentImpl.str );

	FS_WriteEntireFile( filePathHeader, content.str, content.length );

	Mem_Reset( allocator );
}

void Gen_FunctionsQuaternion( allocatorLinear_t* allocator, const genLanguage_t language ) {
	assert( allocator );

	char filePathHeader[64] = { 0 };
	snprintf( filePathHeader, 64, "%s%s.h", GEN_FOLDER_PATHS_OUT_GEN[language], GEN_FILENAME_FUNCTIONS_QUATERNION );

	stringBuilder_t contentFwdDec = String_Create( allocator, 512 * KB_TO_BYTES );
	stringBuilder_t contentImpl = String_Create( allocator, 512 * KB_TO_BYTES );

	stringBuilder_t content = String_Create( allocator, contentFwdDec.alloc + contentImpl.alloc );

	String_Append( &contentFwdDec, GEN_FILE_HEADER );

	if ( language == GEN_LANGUAGE_C ) {
		String_Append( &contentFwdDec,
			"#ifdef __cplusplus\n"
			"extern \"C\" {\n"
			"#endif\n"
			"\n"
		);
	}

	for ( u32 typeIndex = 0; typeIndex < GEN_TYPE_COUNT; typeIndex++ ) {
		genType_t type = (genType_t) typeIndex;

		const char* typeString = Gen_GetTypeString( type );

		for ( u32 row = GEN_COMPONENT_COUNT_MIN; row <= GEN_COMPONENT_COUNT_MAX; row++ ) {
			for ( u32 col = GEN_COMPONENT_COUNT_MIN; col <= GEN_COMPONENT_COUNT_MAX; col++ ) {
				String_Appendf( &contentFwdDec, "#include \"%s%dx%d.h\"\n", typeString, row, col );
			}
		}

		String_Appendf( &contentFwdDec, "\n" );
	}

	String_Appendf( &contentFwdDec, "#include \"" GEN_FILENAME_FUNCTIONS_VECTOR ".h\"\n" );
	String_Appendf( &contentFwdDec, "\n" );

	for ( u32 typeIndex = 0; typeIndex < GEN_TYPE_COUNT; typeIndex++ ) {
		genType_t type = (genType_t) typeIndex;
		if (Gen_TypeIsFloatingPoint(type) == false) {
			continue;
		}
		
		char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
		Gen_GetFullTypeName(type, 1, 4, fullTypeName);

		printf("Basic functions %s...", fullTypeName);

		String_Appendf(&contentFwdDec, "// %s\n", fullTypeName);

		Gen_QuaternionMultiply( language, type, &contentFwdDec, &contentImpl );
		Gen_QuaternionMultiplyScalar( language, type, &contentFwdDec, &contentImpl );
		Gen_QuaternionLength( language, type, &contentFwdDec, &contentImpl );
		Gen_QuaternionNormalize( language, type, &contentFwdDec, &contentImpl );
		Gen_QuaternionConjugate( language, type, &contentFwdDec, &contentImpl );
		Gen_QuaternionInverse( language, type, &contentFwdDec, &contentImpl );
		Gen_QuaternionRotationAxis( language, type, &contentFwdDec, &contentImpl );
		Gen_QuaternionLerp( language, type, &contentFwdDec, &contentImpl );
		Gen_QuaternionSlerp( language, type, &contentFwdDec, &contentImpl );

		String_Append(&contentFwdDec, "\n");
		printf("OK.\n");
	}

	String_Append( &contentImpl,
		"#if defined( __GNUC__ ) || defined( __clang__ )\n"
		"#pragma GCC diagnostic pop\n"
		"#endif\n"
	);

	String_Append( &content, contentFwdDec.str );
	String_Append( &content, "\n" );
	String_Append( &content,
		"#pragma once\n"
		"\n"
		"// ignore missing brace initializers\n"
		"#if defined( __GNUC__ ) || defined( __clang__ )\n"
		"#pragma GCC diagnostic push\n"
		"#pragma GCC diagnostic ignored \"-Wmissing-braces\"\n"
		"#endif\n"
		"\n"
	);

	if ( language == GEN_LANGUAGE_C ) {
		String_Append( &contentImpl,
			"\n"
			"#ifdef __cplusplus\n"
			"}\n"
			"#endif\n"
		);
	}

	String_Append( &content, contentImpl.str );

	FS_WriteEntireFile( filePathHeader, content.str, content.length );

	Mem_Reset( allocator );
}

void Gen_FunctionsScalarSSE( allocatorLinear_t* allocator, const genLanguage_t language ) {
	assert( allocator );

	const char* folder = GEN_FOLDER_PATHS_OUT_GEN[language];

	char filePathHeader[64] = { 0 };
	snprintf( filePathHeader, 64, "%s%s.h", folder, GEN_FILENAME_FUNCTIONS_SCALAR_SSE );

	stringBuilder_t contentFwdDec = String_Create( allocator, 4 * KB_TO_BYTES );
	String_Append( &contentFwdDec, GEN_FILE_HEADER );
	String_Append( &contentFwdDec,
		"#pragma once\n"
		"\n"
	);

	if ( language == GEN_LANGUAGE_C ) {
		String_Append( &contentFwdDec,
			"#ifdef __cplusplus\n"
			"extern \"C\" {\n"
			"#endif\n"
			"\n"
		);
	}

	String_Append( &contentFwdDec,
		"// HLML includes\n"
		"#include \"../hlml_constants_sse.h\"\n"
		"\n"
		"// others\n"
		"#include <xmmintrin.h>\n"
		"#include <assert.h>\n"
		"\n"
	);

	for ( u32 typeIndex = 0; typeIndex < GEN_TYPE_COUNT; typeIndex++ ) {
		genType_t type = (genType_t) typeIndex;

		if ( !Gen_TypeSupportsSSE( type ) ) {
			continue;
		}

		const char* memberTypeString = Gen_GetMemberTypeString( type );

		printf( "SIMD vector functions %s...", memberTypeString );

		String_Appendf( &contentFwdDec, "// %s\n", memberTypeString );

		Gen_SSE_Radians( language, type, &contentFwdDec );
		Gen_SSE_Degrees( language, type, &contentFwdDec );

		Gen_SSE_Lerp( language, type, 1, &contentFwdDec );

		String_Append( &contentFwdDec, "\n" );

		printf( "OK.\n" );
	}

	if ( language == GEN_LANGUAGE_C ) {
		String_Append( &contentFwdDec,
			"#ifdef __cplusplus\n"
			"}\n"
			"#endif\n"
			"\n"
		);
	}

	FS_WriteEntireFile( filePathHeader, contentFwdDec.str, contentFwdDec.length );

	Mem_Reset( allocator );
}

void Gen_FunctionsVectorSSE( allocatorLinear_t* allocator, const genLanguage_t language ) {
	assert( allocator );

	const char* folder = GEN_FOLDER_PATHS_OUT_GEN[language];

	char filePathHeader[64] = { 0 };
	snprintf( filePathHeader, 64, "%s%s.h", folder, GEN_FILENAME_FUNCTIONS_VECTOR_SSE );

	stringBuilder_t contentFwdDec = String_Create( allocator, 16 * KB_TO_BYTES );

	String_Append( &contentFwdDec, GEN_FILE_HEADER );
	String_Append( &contentFwdDec,
		"#pragma once\n"
		"\n"
	);

	if ( language == GEN_LANGUAGE_C ) {
		String_Append( &contentFwdDec,
			"#ifdef __cplusplus\n"
			"extern \"C\" {\n"
			"#endif\n"
			"\n"
		);
	}

	String_Append( &contentFwdDec,
		"// HLML includes\n"
		"#include \"" GEN_FILENAME_FUNCTIONS_VECTOR_SSE ".h\"\n"
		"#include \"../" GEN_HEADER_CONSTANTS_SSE "\"\n"
		"\n"
		"#include <immintrin.h>\n"
		"\n"
	);

	for ( u32 typeIndex = 0; typeIndex < GEN_TYPE_COUNT; typeIndex++ ) {
		genType_t type = (genType_t) typeIndex;

		if ( !Gen_TypeSupportsSSE( type ) ) {
			continue;
		}

		const char* registerName = Gen_SSE_GetRegisterName( type );

		for ( u32 componentIndex = GEN_COMPONENT_COUNT_MIN; componentIndex <= GEN_COMPONENT_COUNT_MAX; componentIndex++ ) {
			char sseTypeName[GEN_STRING_LENGTH_SSE_INPUT_NAME];
			Gen_SSE_GetFullTypeName( type, 1, componentIndex, sseTypeName );

			String_Appendf( &contentFwdDec,
				"// Holds %d %ss where each register is a vertical stream of that vector component.\n"
				"// Basically, this struct holds 4 vectors.\n"
				, componentIndex, registerName
			);
			String_Appendf( &contentFwdDec, "typedef struct %s\n", sseTypeName );
			String_Append(  &contentFwdDec, "{\n" );
			for ( u32 i = 0; i < componentIndex; i++ ) {
				String_Appendf( &contentFwdDec, "\t%s %c;\n", registerName, GEN_COMPONENT_NAMES_VECTOR[i] );
			}
			String_Appendf( &contentFwdDec, "} %s;\n", sseTypeName );
			String_Append(  &contentFwdDec, "\n" );
		}
	}

	for ( u32 typeIndex = 0; typeIndex < GEN_TYPE_COUNT; typeIndex++ ) {
		genType_t type = (genType_t) typeIndex;

		if ( !Gen_TypeSupportsSSE( type ) ) {
			continue;
		}

		for ( u32 componentIndex = GEN_COMPONENT_COUNT_MIN; componentIndex <= GEN_COMPONENT_COUNT_MAX; componentIndex++ ) {
			char sseTypeName[GEN_STRING_LENGTH_SSE_INPUT_NAME];
			Gen_SSE_GetFullTypeName( type, 1, componentIndex, sseTypeName );

			printf( "SIMD vector functions %s...", sseTypeName );

			String_Appendf( &contentFwdDec, "// %s\n", sseTypeName );
			Gen_SSE_VectorDot( language, type, componentIndex, &contentFwdDec );
			Gen_SSE_VectorCross( language, type, componentIndex, &contentFwdDec );
			Gen_SSE_VectorLength( language, type, componentIndex, &contentFwdDec );
			Gen_SSE_VectorNormalize( language, type, componentIndex, &contentFwdDec );
			Gen_SSE_VectorDistance( language, type, componentIndex, &contentFwdDec );

			String_Append( &contentFwdDec, "\n" );

			printf( "OK.\n" );
		}
	}

	if ( language == GEN_LANGUAGE_C ) {
		String_Append( &contentFwdDec,
			"#ifdef __cplusplus\n"
			"}\n"
			"#endif\n"
		);
	}

	FS_WriteEntireFile( filePathHeader, contentFwdDec.str, contentFwdDec.length );

	Mem_Reset( allocator );
}

void Gen_FunctionsMatrixSSE( allocatorLinear_t* allocator, const genLanguage_t language ) {
	assert( allocator );

	const char* folder = GEN_FOLDER_PATHS_OUT_GEN[language];

	char filePathHeader[64] = { 0 };
	snprintf( filePathHeader, 64, "%s%s.h", folder, GEN_FILENAME_FUNCTIONS_MATRIX_SSE );

	stringBuilder_t contentFwdDec = String_Create( allocator, 84 * KB_TO_BYTES );

	String_Append( &contentFwdDec, GEN_FILE_HEADER );
	String_Append( &contentFwdDec,
		"#pragma once\n"
		"\n"
	);

	if ( language == GEN_LANGUAGE_C ) {
		String_Append( &contentFwdDec,
			"#ifdef __cplusplus\n"
			"extern \"C\" {\n"
			"#endif\n"
			"\n"
		);
	}

	String_Append( &contentFwdDec,
		"#include <immintrin.h>\n"
		"\n"
		"#include \"" GEN_FILENAME_FUNCTIONS_VECTOR_SSE ".h\"\n"
		"\n"
	);

	Gen_SSE_MacroNegate( GEN_TYPE_FLOAT, &contentFwdDec );

	// generate type forward declarations
	for ( u32 typeIndex = 0; typeIndex < GEN_TYPE_COUNT; typeIndex++ ) {
		genType_t type = (genType_t) typeIndex;

		if ( !Gen_TypeSupportsSSE( type ) ) {
			continue;
		}

		const char* registerName = Gen_SSE_GetRegisterName( type );

		for ( u32 row = GEN_COMPONENT_COUNT_MIN; row <= GEN_COMPONENT_COUNT_MAX; row++ ) {
			for ( u32 col = GEN_COMPONENT_COUNT_MIN; col <= GEN_COMPONENT_COUNT_MAX; col++ ) {
				char sseTypeName[GEN_STRING_LENGTH_SSE_INPUT_NAME];
				Gen_SSE_GetFullTypeName( type, row, col, sseTypeName );

				String_Appendf( &contentFwdDec,
					"// Holds %d x %d %ss where each regster is a vertical stream of that matrix component.\n"
					"// Basically, this struct holds 4 matrices.\n"
					, row, col, registerName
				);
				String_Appendf( &contentFwdDec, "typedef struct %s\n", sseTypeName );
				String_Append(  &contentFwdDec, "{\n" );
				String_Appendf( &contentFwdDec, "\t%s m[%d][%d];\n", registerName, row, col );
				String_Appendf( &contentFwdDec, "} %s;\n", sseTypeName );
				String_Append(  &contentFwdDec, "\n" );
			}
		}
	}
	String_Appendf( &contentFwdDec, "\n" );

	// generate functions
	for ( u32 typeIndex = 0; typeIndex < GEN_TYPE_COUNT; typeIndex++ ) {
		genType_t type = (genType_t) typeIndex;

		if ( !Gen_TypeSupportsSSE( type ) ) {
			continue;
		}

		for ( u32 row = GEN_COMPONENT_COUNT_MIN; row <= GEN_COMPONENT_COUNT_MAX; row++ ) {
			for ( u32 col = GEN_COMPONENT_COUNT_MIN; col <= GEN_COMPONENT_COUNT_MAX; col++ ) {
				char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
				Gen_GetFullTypeName( type, row, col, fullTypeName );

				printf( "SIMD matrix functions %s...", fullTypeName );

				String_Appendf( &contentFwdDec, "// %s\n", fullTypeName );

				Gen_SSE_MatrixIdentity( language, type, row, col, &contentFwdDec );
				Gen_SSE_MatrixTranspose( language, type, row, col, &contentFwdDec );

				Gen_SSE_MatrixDeterminant( language, type, row, col, &contentFwdDec );
				Gen_SSE_MatrixInverse( language, type, row, col, &contentFwdDec );

				for ( u32 opIndex = 0; opIndex < GEN_OP_ARITHMETIC_COUNT; opIndex++ ) {
					genOpArithmetic_t op = (genOpArithmetic_t) opIndex;
					Gen_SSE_MatrixArithmeticComponentWise( language, type, row, col, op, &contentFwdDec );
				}

				Gen_SSE_MatrixMultiply( language, type, row, col, &contentFwdDec );

				Gen_SSE_MatrixTranslate( language, type, row, col, &contentFwdDec );
				Gen_SSE_MatrixScale( language, type, row, col, &contentFwdDec );

				String_Append( &contentFwdDec, "\n" );

				printf( "OK.\n" );
			}
		}
	}

	if ( language == GEN_LANGUAGE_C ) {
		String_Append( &contentFwdDec,
			"#ifdef __cplusplus\n"
			"}\n"
			"#endif\n"
		);
	}

	FS_WriteEntireFile( filePathHeader, contentFwdDec.str, contentFwdDec.length );

	Mem_Reset( allocator );
}

void Gen_Tests( allocatorLinear_t* allocator, const genLanguage_t language ) {
	assert( allocator );

	const char* fileExtension = GEN_SOURCE_FILE_EXTENSIONS[language];

	// scalar tests
	for ( u32 typeIndex = 0; typeIndex < GEN_TYPE_COUNT; typeIndex++ ) {
		genType_t type = (genType_t) typeIndex;

		if ( type == GEN_TYPE_BOOL ) {
			continue;
		}

		const char* typeString = Gen_GetTypeString( type );

		printf( "Generating test_scalar_%s.%s...", typeString, fileExtension );

		Gen_ScalarTests( allocator, language, type );

		printf( "OK.\n" );
	}

	// vector tests
	for ( u32 typeIndex = 0; typeIndex < GEN_TYPE_COUNT; typeIndex++ ) {
		genType_t type = (genType_t) typeIndex;

		const char* typeString = Gen_GetTypeString( type );

		for ( u32 componentIndex = GEN_COMPONENT_COUNT_MIN; componentIndex <= GEN_COMPONENT_COUNT_MAX; componentIndex++ ) {
			printf( "Generating test_%s%d.%s...", typeString, componentIndex, fileExtension );

			Gen_VectorTests( allocator, language, type, componentIndex );

			printf( "OK.\n" );
		}
	}

	// matrix tests
	for ( u32 typeIndex = 0; typeIndex < GEN_TYPE_COUNT; typeIndex++ ) {
		genType_t type = (genType_t) typeIndex;

		const char* typeString = Gen_GetTypeString( type );

		for ( u32 row = GEN_COMPONENT_COUNT_MIN; row <= GEN_COMPONENT_COUNT_MAX; row++ ) {
			for ( u32 col = GEN_COMPONENT_COUNT_MIN; col <= GEN_COMPONENT_COUNT_MAX; col++ ) {
				printf( "Generating test_%s%dx%d.%s...", typeString, row, col, fileExtension );

				Gen_MatrixTests( allocator, language, type, row, col );

				printf( "OK.\n" );
			}
		}
	}

	// quaternion tests
	for ( u32 typeIndex = 0; typeIndex < GEN_TYPE_COUNT; typeIndex++ ) {
		genType_t type = (genType_t) typeIndex;
		if (Gen_TypeIsFloatingPoint( type ) == false) {
			continue;
		}

		const char* typeString = Gen_GetTypeString( type );

		printf( "Generating test_quaternion_%s.%s...", typeString, fileExtension );

		Gen_QuaternionTests( allocator, language, type );

		printf( "OK.\n" );
	}
}

void Gen_TestsMain( allocatorLinear_t* allocator, const genLanguage_t language ) {
	assert( allocator );

	const char* testsFolder = GEN_FOLDER_PATHS_TESTS[language];
	const char* fileExtension = GEN_SOURCE_FILE_EXTENSIONS[language];

	char outGenInclude[1024];
	snprintf( outGenInclude, 1024, "../../../%s", GEN_FOLDER_PATHS_OUT_GEN[language] );

	char filePathMain[1024] = { 0 };
	snprintf( filePathMain, 1024, "%smain.%s", testsFolder, fileExtension );

	stringBuilder_t sb = String_Create( allocator, 8 * KB_TO_BYTES );

	String_Append( &sb, GEN_FILE_HEADER );

	String_Append( &sb, "#define NOMINMAX\n" );
	String_Append( &sb, "\n" );

	String_Append( &sb, "typedef struct temperTestInfo_t temperTestInfo_t;\n" );
	String_Append( &sb, "void OnBeforeTest( const temperTestInfo_t* testInfo );\n" );
	String_Append( &sb, "void OnAfterTest( const temperTestInfo_t* testInfo );\n" );

	String_Append( &sb, "#define TEMPER_IMPLEMENTATION\n" );
	String_Append( &sb, "#define TEMPERDEV__ON_BEFORE_TEST OnBeforeTest\n" );
	String_Append( &sb, "#define TEMPERDEV__ON_AFTER_TEST OnAfterTest\n" );
	String_Append( &sb, "#include <temper/temper.h>\n" );
	String_Append( &sb, "\n" );

	String_Appendf( &sb, "#include \"%s%s\"\n", outGenInclude, GEN_HEADER_MAIN );
	String_Append(  &sb, "\n" );

	// scalar tests
	for ( u32 typeIndex = 0; typeIndex < GEN_TYPE_COUNT; typeIndex++ ) {
		genType_t type = (genType_t) typeIndex;

		if ( type == GEN_TYPE_BOOL ) {
			continue;
		}

		const char* memberTypeString = Gen_GetMemberTypeString( type );

		String_Appendf( &sb, "#include \"test_scalar_%s.%s\"\n", memberTypeString, fileExtension );
	}

	String_Append( &sb, "\n" );

	// vector tests
	for ( u32 typeIndex = 0; typeIndex < GEN_TYPE_COUNT; typeIndex++ ) {
		genType_t type = (genType_t) typeIndex;

		for ( u32 componentIndex = GEN_COMPONENT_COUNT_MIN; componentIndex <= GEN_COMPONENT_COUNT_MAX; componentIndex++ ) {
			char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME] = { 0 };
			Gen_GetFullTypeName( type, 1, componentIndex, fullTypeName );

			String_Appendf( &sb, "#include \"test_%s.%s\"\n", fullTypeName, fileExtension );
		}

		String_Append( &sb, "\n" );
	}

	// matrix tests
	for ( u32 typeIndex = 0; typeIndex < GEN_TYPE_COUNT; typeIndex++ ) {
		genType_t type = (genType_t) typeIndex;

		for ( u32 row = GEN_COMPONENT_COUNT_MIN; row <= GEN_COMPONENT_COUNT_MAX; row++ ) {
			for ( u32 col = GEN_COMPONENT_COUNT_MIN; col <= GEN_COMPONENT_COUNT_MAX; col++ ) {
				char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME] = { 0 };
				Gen_GetFullTypeName( type, row, col, fullTypeName );

				String_Appendf( &sb, "#include \"test_%s.%s\"\n", fullTypeName, fileExtension );
			}

			String_Append( &sb, "\n" );
		}
	}

	// quaternion tests
	for ( u32 typeIndex = 0; typeIndex < GEN_TYPE_COUNT; typeIndex++ ) {
		genType_t type = (genType_t) typeIndex;
		if (Gen_TypeIsFloatingPoint(type) == false) {
			continue;
		}

		char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME] = { 0 };
		Gen_GetFullTypeName( type, 1, 1, fullTypeName );

		String_Appendf( &sb, "#include \"test_quaternion_%s4.%s\"\n", fullTypeName, fileExtension );
	}
	String_Append( &sb, "\n" );

	String_Append( &sb, "#define TEST_PADDING \"................................................................\"\n" );
	String_Append( &sb, "\n" );

	String_Append( &sb, "void OnBeforeTest( const temperTestInfo_t* testInfo )\n" );
	String_Append( &sb, "{\n" );
	String_Append( &sb, "\tconst int padLengthMax = (int) strlen( TEST_PADDING );\n" );
	String_Append( &sb, "\n" );
	String_Append( &sb, "\tconst int dotLength = padLengthMax - (int) strlen( testInfo->testNameStr );\n" );
	String_Append( &sb, "\tassert( dotLength );\n" );
	String_Append( &sb, "\n" );
	String_Append( &sb, "\tprintf( \"%s %*.*s \", testInfo->testNameStr, dotLength, dotLength, TEST_PADDING );\n" );
	String_Append( &sb, "}\n" );
	String_Append( &sb, "\n" );

	String_Append( &sb, "void OnAfterTest( const temperTestInfo_t* testInfo )\n" );
	String_Append( &sb, "{\n" );
	String_Append( &sb, "\t\tif ( testInfo->testingFlag == TEMPER_FLAG_SHOULD_SKIP )\n" );
	String_Append( &sb, "\t\t{\n" );
	String_Append( &sb, "\t\t\tTemperSetTextColorInternal( TEMPERDEV__COLOR_YELLOW );\n" );
	String_Append( &sb, "\t\t\tprintf( \"SKIPPED\\n\" );\n" );
	String_Append( &sb, "\t\t\tTemperSetTextColorInternal( TEMPERDEV__COLOR_DEFAULT );\n" );
	String_Append( &sb, "\t\t}\n" );
	String_Append( &sb, "\t\telse\n" );
	String_Append( &sb, "\t\t{\n" );
	String_Append( &sb, "\t\t\tif ( g_temperTestContext.currentTestErrorCount == 0 )\n" );
	String_Append( &sb, "\t\t\t{\n" );
	String_Append( &sb, "\t\t\t\tTemperSetTextColorInternal( TEMPERDEV__COLOR_GREEN );\n" );
	String_Append( &sb, "\t\t\t\tprintf( \"OK\" );\n" );
	String_Append( &sb, "\t\t\t\tTemperSetTextColorInternal( TEMPERDEV__COLOR_DEFAULT );\n" );
	String_Append( &sb, "\t\t\t}\n" );
	String_Append( &sb, "\t\t\telse\n" );
	String_Append( &sb, "\t\t\t{\n" );
	String_Append( &sb, "\t\t\t\tTemperSetTextColorInternal( TEMPERDEV__COLOR_RED );\n" );
	String_Append( &sb, "\t\t\t\tprintf( \"FAILED\\n\" );\n" );
	String_Append( &sb, "\t\t\t\tTemperSetTextColorInternal( TEMPERDEV__COLOR_DEFAULT );\n" );
	String_Append( &sb, "\t\t\t}\n" );
	String_Append( &sb, "\n" );
	String_Append( &sb, "\t\t\tprintf( \" (%f %s)\\n\", testInfo->testTimeTaken, TemperGetTimeUnitStringInternal( g_temperTestContext.timeUnit ) );\n" );
	String_Append( &sb, "\t\t}\n" );
	String_Append( &sb, "\t}\n" );

	String_Append( &sb, "int main( int argc, char** argv )\n" );
	String_Append( &sb, "{\n" );
	String_Append( &sb, "\tTEMPER_RUN( argc, argv );\n" );
	String_Append( &sb, "\treturn TEMPER_GET_EXIT_CODE();\n" );
	String_Append( &sb, "}" );
	String_Append( &sb, "\n" );

	FS_WriteEntireFile( filePathMain, sb.str, sb.length );

	Mem_Reset( allocator );
}

void Gen_GetValuesArray1D( const genType_t type, const u32 numValues, const float* values, stringBuilder_t* sb ) {
	String_Append(  sb, "\t{ " );
	for ( u32 componentIndex = 0; componentIndex < numValues; componentIndex++ ) {
		char componentStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
		Gen_GetNumericLiteral( type, values[componentIndex], componentStr );

		String_Appendf( sb, "%s", componentStr );

		if ( componentIndex != numValues - 1 ) {
			String_Append( sb, ", " );
		}
	}
	String_Append(  sb, " }" );
}

void Gen_GetValuesArray2D( const genType_t type, const u32 rows, const u32 cols, const float* values, stringBuilder_t* sb ) {
	String_Append( sb, "\t{\n" );
	for ( u32 row = 0; row < rows; row++ ) {
		String_Append( sb, "\t\t{ " );
		for ( u32 col = 0; col < cols; col++ ) {
			const float* value = values + ( row * cols );

			char componentStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
			Gen_GetNumericLiteral( type, *value, componentStr );
			
			String_Appendf( sb, "%s", componentStr );

			if ( col != cols - 1 ) {
				String_Append( sb, ", " );
			}
		}
		String_Append( sb, " }" );

		if ( row != rows - 1 ) {
			String_Append( sb, "," );
		}

		String_Append( sb, "\n" );
	}
	String_Append( sb, "\t};\n" );
}

void Gen_Floateq( const genType_t type, stringBuilder_t* sbFwdDec, stringBuilder_t* sbImpl ) {
	assert( sbFwdDec );
	assert( sbImpl );

	if ( !Gen_TypeIsFloatingPoint( type ) ) {
		return;
	}

	const char* typeString = Gen_GetTypeString( type );

	const char* floateqStr = Gen_GetFuncNameFloateq( type );
	const char* floateqepsStr = Gen_GetFuncNameFloateqeps( type );

	const char* parmEpsilonStr = Gen_GetConstantNameEpsilon( type );

	Doc_Floateq( sbFwdDec );
	String_Appendf( sbFwdDec, "inline bool %s( const %s lhs, const %s rhs, const %s epsilon );\n", floateqepsStr, typeString, typeString, typeString );
	String_Append(  sbFwdDec, "\n" );

	String_Appendf( sbImpl, "bool %s( const %s lhs, const %s rhs, const %s epsilon )\n", floateqepsStr, typeString, typeString, typeString );
	String_Append(  sbImpl, "{\n" );
	String_Appendf( sbImpl, "\treturn %s( lhs - rhs ) < epsilon;\n", Gen_GetFuncNameFabs( type ) );
	String_Append(  sbImpl, "}\n" );
	String_Append(  sbImpl, "\n" );

	Doc_Floateq( sbFwdDec );
	String_Appendf( sbFwdDec, "inline bool %s( const %s lhs, const %s rhs );\n", floateqStr, typeString, typeString );
	String_Append(  sbFwdDec, "\n" );

	String_Appendf( sbImpl, "bool %s( const %s lhs, const %s rhs )\n", floateqStr, typeString, typeString );
	String_Append(  sbImpl, "{\n" );
	String_Appendf( sbImpl, "\treturn %s( lhs, rhs, %s );\n", floateqepsStr, parmEpsilonStr );
	String_Append(  sbImpl, "}\n" );
	String_Append(  sbImpl, "\n" );
}

void Gen_Sign( const genType_t type, stringBuilder_t* sbFwdDec, stringBuilder_t* sbImpl ) {
	assert( sbFwdDec );
	assert( sbImpl );

	if ( type == GEN_TYPE_BOOL || type == GEN_TYPE_UINT ) {
		return;
	}

	const char* memberTypeString = Gen_GetMemberTypeString( type );
	const char* intTypeString = Gen_GetMemberTypeString( GEN_TYPE_INT );

	const char* signFuncStr = Gen_GetFuncNameSign( type );

	char zeroStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	Gen_GetNumericLiteral( type, 0, zeroStr, 1 );

	Doc_Sign( sbFwdDec );
	String_Appendf( sbFwdDec, "inline %s %s( const %s x );\n", intTypeString, signFuncStr, memberTypeString );
	String_Append(  sbFwdDec, "\n" );

	String_Appendf( sbImpl, "%s %s( const %s x )\n", intTypeString, signFuncStr, memberTypeString );
	String_Append(  sbImpl, "{\n" );
	String_Appendf( sbImpl, "\treturn ( %s < x ) - ( x < %s );\n", zeroStr, zeroStr );
	String_Append(  sbImpl, "}\n" );
	String_Append(  sbImpl, "\n" );
}

void Gen_Radians( const genType_t type, stringBuilder_t* sbFwdDec, stringBuilder_t* sbImpl ) {
	assert( sbFwdDec );
	assert( sbImpl );

	if ( !Gen_TypeIsFloatingPoint( type ) ) {
		return;
	}

	const char* typeString = Gen_GetTypeString( type );

	const char* radiansFuncStr = Gen_GetFuncNameRadians( type );

	char oneHundredEightyStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	Gen_GetNumericLiteral( type, 180, oneHundredEightyStr, 1 );

	const char* piStr = Gen_GetConstantNamePi( type );

	Doc_Radians( sbFwdDec );
	String_Appendf( sbFwdDec, "inline %s %s( const %s deg );\n", typeString, radiansFuncStr, typeString );

	String_Appendf( sbImpl, "%s %s( const %s deg )\n", typeString, radiansFuncStr, typeString );
	String_Append(  sbImpl, "{\n" );
	String_Appendf( sbImpl, "\treturn deg * %s / %s;\n", piStr, oneHundredEightyStr );
	String_Append(  sbImpl, "}\n" );
	String_Append(  sbImpl, "\n" );
}

void Gen_Degrees( const genType_t type, stringBuilder_t* sbFwdDec, stringBuilder_t* sbImpl ) {
	assert( sbFwdDec );
	assert( sbImpl );

	if ( !Gen_TypeIsFloatingPoint( type ) ) {
		return;
	}

	const char* typeString = Gen_GetTypeString( type );

	const char* degreesFuncStr = Gen_GetFuncNameDegrees( type );

	char oneHundredEightyStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	Gen_GetNumericLiteral( type, 180, oneHundredEightyStr, 1 );

	const char* piStr = Gen_GetConstantNamePi( type );

	Doc_Degrees( sbFwdDec );
	String_Appendf( sbFwdDec, "inline %s %s( const %s rad );\n", typeString, degreesFuncStr, typeString );
	String_Append(  sbFwdDec, "\n" );

	String_Appendf( sbImpl, "%s %s( const %s rad )\n", typeString, degreesFuncStr, typeString );
	String_Append(  sbImpl, "{\n" );
	String_Appendf( sbImpl, "\treturn rad * %s / %s;\n", oneHundredEightyStr, piStr );
	String_Append(  sbImpl, "}\n" );
	String_Append(  sbImpl, "\n" );
}

void Gen_MinMax( const genType_t type, stringBuilder_t* sbFwdDec, stringBuilder_t* sbImpl ) {
	assert( sbFwdDec );
	assert( sbImpl );

	if ( type == GEN_TYPE_BOOL ) {
		return;
	}

	const char* memberTypeString = Gen_GetMemberTypeString( type );

	const char* minFuncStr = Gen_GetFuncNameMin( type );
	const char* maxFuncStr = Gen_GetFuncNameMax( type );

	// min
	Doc_Min( sbFwdDec );
	String_Appendf( sbFwdDec, "inline %s %s( const %s x, const %s y );\n", memberTypeString, minFuncStr, memberTypeString, memberTypeString );
	String_Append(  sbFwdDec, "\n" );

	String_Appendf( sbImpl, "%s %s( const %s x, const %s y )\n", memberTypeString, minFuncStr, memberTypeString, memberTypeString );
	String_Append(  sbImpl, "{\n" );
	String_Append(  sbImpl, "\treturn ( x < y ) ? x : y;\n" );
	String_Append(  sbImpl, "}\n" );
	String_Append(  sbImpl, "\n" );

	// max
	Doc_Max( sbFwdDec );
	String_Appendf( sbFwdDec, "inline %s %s( const %s x, const %s y );\n", memberTypeString, maxFuncStr, memberTypeString, memberTypeString );
	String_Append(  sbFwdDec, "\n" );

	String_Appendf( sbImpl, "%s %s( const %s x, const %s y )\n", memberTypeString, maxFuncStr, memberTypeString, memberTypeString );
	String_Append(  sbImpl, "{\n" );
	String_Append(  sbImpl, "\treturn ( x > y ) ? x : y;\n" );
	String_Append(  sbImpl, "}\n" );
	String_Append(  sbImpl, "\n" );
}

void Gen_Clamp( const genType_t type, stringBuilder_t* sbFwdDec, stringBuilder_t* sbImpl ) {
	assert( sbFwdDec );
	assert( sbImpl );

	if ( type == GEN_TYPE_BOOL ) {
		return;
	}

	const char* memberTypeString = Gen_GetMemberTypeString( type );

	const char* clampFuncStr = Gen_GetFuncNameClamp( type );

	const char* minFuncStr = Gen_GetFuncNameMin( type );
	const char* maxFuncStr = Gen_GetFuncNameMax( type );

	Doc_Clamp( sbFwdDec );
	String_Appendf( sbFwdDec, "inline %s %s( const %s x, const %s low, const %s high );\n", memberTypeString, clampFuncStr, memberTypeString, memberTypeString, memberTypeString );
	String_Append(  sbFwdDec, "\n" );

	String_Appendf( sbImpl, "%s %s( const %s x, const %s low, const %s high )\n", memberTypeString, clampFuncStr, memberTypeString, memberTypeString, memberTypeString );
	String_Append(  sbImpl, "{\n" );
	String_Appendf( sbImpl, "\treturn %s( %s( x, low ), high );\n", minFuncStr, maxFuncStr );
	String_Append(  sbImpl, "}\n" );
	String_Append(  sbImpl, "\n" );
}

void Gen_Saturate( const genLanguage_t language, const genType_t type, const u32 numComponents, stringBuilder_t* sbFwdDec, stringBuilder_t* sbImpl ) {
	assert( numComponents >= 1 );	// we allow scalar types for this function
	assert( numComponents <= GEN_COMPONENT_COUNT_MAX );
	assert( sbFwdDec );
	assert( sbImpl );

	if ( !Gen_TypeIsFloatingPoint( type ) ) {
		return;
	}

	char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetFullTypeName( type, 1, numComponents, fullTypeName );

	char saturateFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameSaturate( language, type, numComponents, saturateFuncStr );

	const char* clampFuncStr = Gen_GetFuncNameClamp( type );

	char zeroStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	Gen_GetNumericLiteral( type, 0.0f, zeroStr, 1 );

	char oneStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	Gen_GetNumericLiteral( type, 1.0f, oneStr, 1 );

	char parmTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetParmTypeName( language, type, 1, numComponents, parmTypeName );

	const char* parmAccessStr = GEN_TYPE_ACCESS_OPERATORS[language];

	bool isVector = numComponents > 1;

	Doc_Saturate( sbFwdDec, fullTypeName );
	String_Appendf( sbFwdDec, "inline %s %s( const %s x );\n", fullTypeName, saturateFuncStr, parmTypeName );

	String_Appendf( sbImpl, "%s %s( const %s x )\n", fullTypeName, saturateFuncStr, parmTypeName );
	if ( isVector ) {
		String_Append(  sbImpl, "{\n" );
		String_Appendf( sbImpl, "\treturn HLML_CONSTRUCT( %s ) {\n", fullTypeName );
		for ( u32 i = 0; i < numComponents; i++ ) {
			String_Appendf( sbImpl, "\t\t%s( x%s%c, %s, %s )", clampFuncStr, parmAccessStr, GEN_COMPONENT_NAMES_VECTOR[i], zeroStr, oneStr );

			if ( i != numComponents - 1 ) {
				String_Append( sbImpl, "," );
			}

			String_Append( sbImpl, "\n" );
		}

		String_Append( sbImpl, "\t};\n" );
		String_Append( sbImpl, "}\n" );
		String_Append( sbImpl, "\n" );
	} else {
		String_Append(  sbImpl, "{\n" );
		String_Appendf( sbImpl, "\treturn %s( x, %s, %s );\n", clampFuncStr, zeroStr, oneStr );
		String_Append(  sbImpl, "}\n" );
		String_Append(  sbImpl, "\n" );
	}
}

void Gen_Lerp( const genLanguage_t language, const genType_t type, const u32 numComponents, stringBuilder_t* sbFwdDec, stringBuilder_t* sbImpl ) {
	assert( numComponents >= 1 );	// we allow scalar types for this function
	assert( numComponents <= GEN_COMPONENT_COUNT_MAX );
	assert( sbFwdDec );
	assert( sbImpl );

	if ( !Gen_TypeIsFloatingPoint( type ) ) {
		return;
	}

	const char* typeString = Gen_GetTypeString( type );

	char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetFullTypeName( type, 1, numComponents, fullTypeName );

	char lerpFuncStrScalar[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameLerp( language, type, 1, lerpFuncStrScalar );

	char lerpFuncStrVector[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameLerp( language, type, numComponents, lerpFuncStrVector );

	char oneStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	Gen_GetNumericLiteral( type, 1.0f, oneStr, 1 );

	char parmTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetParmTypeName( language, type, 1, numComponents, parmTypeName );

	const char* parmAccessStr = GEN_TYPE_ACCESS_OPERATORS[language];

	Doc_Lerp( sbFwdDec, fullTypeName );
	String_Appendf( sbFwdDec, "inline %s %s( const %s a, const %s b, const %s t );\n", fullTypeName, lerpFuncStrVector, parmTypeName, parmTypeName, typeString );
	String_Append(  sbFwdDec, "\n" );

	String_Appendf( sbImpl, "%s %s( const %s a, const %s b, const %s t )\n", fullTypeName, lerpFuncStrVector, parmTypeName, parmTypeName, typeString );
	if ( numComponents > 1 ) {
		String_Append(  sbImpl, "{\n" );
		String_Appendf( sbImpl, "\treturn HLML_CONSTRUCT( %s ) {\n", fullTypeName );
		for ( u32 i = 0; i < numComponents; i++ ) {
			const char componentStr = GEN_COMPONENT_NAMES_VECTOR[i];
			String_Appendf( sbImpl, "\t\t%s( a%s%c, b%s%c, t )", lerpFuncStrScalar, parmAccessStr, componentStr, parmAccessStr, componentStr );

			if ( i != numComponents - 1 ) {
				String_Append( sbImpl, "," );
			}

			String_Append( sbImpl, "\n" );
		}

		String_Append( sbImpl, "\t};\n" );
		String_Append( sbImpl, "}\n" );
		String_Append( sbImpl, "\n" );
	} else {
		String_Append(  sbImpl, "{\n" );
		String_Appendf( sbImpl, "\treturn ( %s - t ) * a + t * b;\n", oneStr );
		String_Append(  sbImpl, "}\n" );
		String_Append(  sbImpl, "\n" );
	}
}

void Gen_Step( const genLanguage_t language, const genType_t type, const u32 numComponents, stringBuilder_t* sbFwdDec, stringBuilder_t* sbImpl ) {
	assert( numComponents >= 1 );
	assert( numComponents <= GEN_COMPONENT_COUNT_MAX );
	assert( sbFwdDec );
	assert( sbImpl );

	if ( !Gen_TypeIsFloatingPoint( type ) ) {
		return;
	}

	char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetFullTypeName( type, 1, numComponents, fullTypeName );

	char stepFuncStrScalar[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameStep( language, type, 1, stepFuncStrScalar );

	char stepFuncStrVector[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameStep( language, type, numComponents, stepFuncStrVector );

	char zeroStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	Gen_GetNumericLiteral( type, 0.0f, zeroStr, 1 );

	char oneStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	Gen_GetNumericLiteral( type, 1.0f, oneStr, 1 );

	char parmTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetParmTypeName( language, type, 1, numComponents, parmTypeName );

	const char* parmAccessStr = GEN_TYPE_ACCESS_OPERATORS[language];

	Doc_Step( sbFwdDec, fullTypeName );
	String_Appendf( sbFwdDec, "inline %s %s( const %s x, const %s y );\n", fullTypeName, stepFuncStrVector, parmTypeName, parmTypeName );
	String_Append(  sbFwdDec, "\n" );

	String_Appendf( sbImpl, "%s %s( const %s x, const %s y )\n", fullTypeName, stepFuncStrVector, parmTypeName, parmTypeName );
	if ( numComponents > 1 ) {
		String_Append(  sbImpl, "{\n" );
		String_Appendf( sbImpl, "\treturn HLML_CONSTRUCT( %s ) {\n", fullTypeName );
		for ( u32 i = 0; i < numComponents; i++ ) {
				const char componentStr = GEN_COMPONENT_NAMES_VECTOR[i];
				String_Appendf( sbImpl, "\t\t%s( x%s%c, y%s%c )", stepFuncStrScalar, parmAccessStr, componentStr, parmAccessStr, componentStr );

				if ( i != numComponents - 1 ) {
					String_Append( sbImpl, "," );
				}

				String_Append( sbImpl, "\n" );
		}
		String_Appendf( sbImpl, "\t};\n" );
		String_Append(  sbImpl, "}\n" );
		String_Append(  sbImpl, "\n" );
	} else {
		String_Append(  sbImpl, "{\n" );
		String_Appendf( sbImpl, "\treturn ( y > x ? %s : %s );\n", oneStr, zeroStr );
		String_Append(  sbImpl, "}\n" );
		String_Append(  sbImpl, "\n" );
	}
}

void Gen_Smoothstep( const genLanguage_t language, const genType_t type, const u32 numComponents, stringBuilder_t* sbFwdDec, stringBuilder_t* sbImpl ) {
	assert( numComponents >= 1 );	// we allow scalar types for this function
	assert( numComponents <= GEN_COMPONENT_COUNT_MAX );
	assert( sbFwdDec );
	assert( sbImpl );

	if ( !Gen_TypeIsFloatingPoint( type ) ) {
		return;
	}

	char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetFullTypeName( type, 1, numComponents, fullTypeName );

	char smoothstepFuncStrScalar[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameSmoothstep( language, type, 1, smoothstepFuncStrScalar );

	char smoothstepFuncStrVector[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameSmoothstep( language, type, numComponents, smoothstepFuncStrVector );

	char smootherstepFuncStrScalar[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameSmootherstep( language, type, 1, smootherstepFuncStrScalar );

	char smootherstepFuncStrVector[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameSmootherstep( language, type, numComponents, smootherstepFuncStrVector );

	char saturateFuncStrScalar[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameSaturate( language, type, 1, saturateFuncStrScalar );

	char saturateFuncStrVector[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameSaturate( language, type, numComponents, saturateFuncStrVector );

	char twoStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	Gen_GetNumericLiteral( type, 2.0f,  twoStr, 1 );

	char threeStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	Gen_GetNumericLiteral( type, 3.0f,  threeStr, 1 );

	char sixStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	Gen_GetNumericLiteral( type, 6.0f,  sixStr, 1 );

	char tenStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	Gen_GetNumericLiteral( type, 10.0f, tenStr, 1 );

	char fifteenStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	Gen_GetNumericLiteral( type, 15.0f, fifteenStr, 1 );

	char parmTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetParmTypeName( language, type, 1, numComponents, parmTypeName );

	const char* parmAccessStr = GEN_TYPE_ACCESS_OPERATORS[language];

	bool32 isVector = numComponents > 1;

	// smoothstep
	{
		Doc_Smoothstep( sbFwdDec, fullTypeName );
		String_Appendf( sbFwdDec, "inline %s %s( const %s low, const %s high, const %s x );\n", fullTypeName, smoothstepFuncStrVector, parmTypeName, parmTypeName, parmTypeName );
		String_Append(  sbFwdDec, "\n" );

		String_Appendf( sbImpl, "%s %s( const %s low, const %s high, const %s x )\n", fullTypeName, smoothstepFuncStrVector, parmTypeName, parmTypeName, parmTypeName );
		if ( isVector ) {
			String_Append(  sbImpl, "{\n" );
			String_Appendf( sbImpl, "\treturn HLML_CONSTRUCT( %s ) {\n", fullTypeName );
			for ( u32 i = 0; i < numComponents; i++ ) {
				const char componentStr = GEN_COMPONENT_NAMES_VECTOR[i];
				String_Appendf( sbImpl, "\t\t%s( low%s%c, high%s%c, x%s%c )", smoothstepFuncStrScalar, parmAccessStr, componentStr, parmAccessStr, componentStr, parmAccessStr, componentStr );

				if ( i != numComponents - 1 ) {
					String_Append( sbImpl, "," );
				}

				String_Append( sbImpl, "\n" );
			}
			String_Append( sbImpl, "\t};\n" );
			String_Append( sbImpl, "}\n" );
			String_Append( sbImpl, "\n" );
		} else {
			String_Append(  sbImpl, "{\n" );
			String_Appendf( sbImpl, "\t%s t = %s( ( x - low ) / ( high - low ) );\n", fullTypeName, saturateFuncStrScalar );
			String_Appendf( sbImpl, "\treturn t * t * ( %s - %s * t );\n", threeStr, twoStr );
			String_Append(  sbImpl, "}\n" );
			String_Append(  sbImpl, "\n" );
		}
	}

	// smootherstep
	{
		Doc_Smootherstep( sbFwdDec, fullTypeName );
		String_Appendf( sbFwdDec, "inline %s %s( const %s low, const %s high, const %s x );\n", fullTypeName, smootherstepFuncStrVector, parmTypeName, parmTypeName, parmTypeName );
		String_Append(  sbFwdDec, "\n" );

		String_Appendf( sbImpl, "%s %s( const %s low, const %s high, const %s x )\n", fullTypeName, smootherstepFuncStrVector, parmTypeName, parmTypeName, parmTypeName );
		if ( isVector ) {
			String_Append(  sbImpl, "{\n" );
			String_Appendf( sbImpl, "\treturn HLML_CONSTRUCT( %s ) {\n", fullTypeName );
			for ( u32 i = 0; i < numComponents; i++ ) {
				const char componentStr = GEN_COMPONENT_NAMES_VECTOR[i];
				String_Appendf( sbImpl, "\t\t%s( low%s%c, high%s%c, x%s%c )", smootherstepFuncStrScalar, parmAccessStr, componentStr, parmAccessStr, componentStr, parmAccessStr, componentStr );

				if ( i != numComponents - 1 ) {
					String_Append( sbImpl, "," );
				}

				String_Append( sbImpl, "\n" );
			}
			String_Append( sbImpl, "\t};\n" );
			String_Append( sbImpl, "}\n" );
			String_Append( sbImpl, "\n" );
		} else {
			String_Append(  sbImpl, "{\n" );
			String_Appendf( sbImpl, "\t%s t = %s( ( x - low ) / ( high - low ) );\n", fullTypeName, saturateFuncStrScalar );
			String_Appendf( sbImpl, "\treturn t * t * t * ( t * ( t * %s - %s ) + %s );\n", sixStr, fifteenStr, tenStr );
			String_Append(  sbImpl, "}\n" );
			String_Append(  sbImpl, "\n" );
		}
	}
}

void Gen_FunctionAll( const genLanguage_t language, const genType_t type, const u32 numRows, const u32 numCols, stringBuilder_t* sbFwdDec, stringBuilder_t* sbImpl ) {
	assert( numRows >= 1 );	// 1 for vector
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );
	assert( sbFwdDec );
	assert( sbImpl );

	if ( type != GEN_TYPE_BOOL ) {
		return;
	}

	char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetFullTypeName( type, numRows, numCols, fullTypeName );

	char parmTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetParmTypeName( language, type, numRows, numCols, parmTypeName );

	char allFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameAll( language, type, numRows, numCols, allFuncStr );

	const char* parmAccessStr = GEN_TYPE_ACCESS_OPERATORS[language];

	Doc_FunctionAll( sbFwdDec, fullTypeName );
	String_Appendf( sbFwdDec, "inline bool %s( const %s x );\n", allFuncStr, parmTypeName );
	String_Append(  sbFwdDec, "\n" );

	String_Appendf( sbImpl, "bool %s( const %s x )\n", allFuncStr, parmTypeName );
	String_Append(  sbImpl, "{\n" );
	String_Append(  sbImpl, "\treturn " );
	if ( numRows == 1 ) {
		for ( u32 componentIndex = 0; componentIndex < numCols; componentIndex++ ) {
			String_Appendf( sbImpl, "x%s%c", parmAccessStr, GEN_COMPONENT_NAMES_VECTOR[componentIndex] );

			if ( componentIndex != numCols - 1 ) {
				String_Append( sbImpl, " && " );
			}
		}
	} else {
		for ( u32 row = 0; row < numRows; row++ ) {
			for ( u32 col = 0; col < numCols; col++ ) {
				String_Appendf( sbImpl, "x%srows[%d].%c", parmAccessStr, row, GEN_COMPONENT_NAMES_VECTOR[col] );

				if ( col != numCols - 1 ) {
					String_Append( sbImpl, " && " );
				}
			}

			if ( row != numRows - 1 ) {
				String_Append( sbImpl, " && " );
			}
		}
	}
	String_Append(  sbImpl, ";\n" );
	String_Append(  sbImpl, "}\n" );
	String_Append(  sbImpl, "\n" );
}

void Gen_Negate( const genLanguage_t language, const genType_t type, const u32 numRows, const u32 numCols, stringBuilder_t* sbFwdDec, stringBuilder_t* sbImpl ) {
	assert( numRows >= 1 );	// pass through 1 for vectors
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );
	assert( sbFwdDec );
	assert( sbImpl );

	if ( type == GEN_TYPE_BOOL ) {
		return;
	}

	char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetFullTypeName( type, numRows, numCols, fullTypeName );

	char parmTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetParmTypeName( language, type, numRows, numCols, parmTypeName );

	char negateFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameNegate( language, type, numRows, numCols, negateFuncStr );

	const char* parmAccessStr = GEN_TYPE_ACCESS_OPERATORS[language];

	bool32 isMatrix = numRows > 1;

	const char* parmName = isMatrix ? "mat" : "vec";

	Doc_Negate( sbFwdDec, fullTypeName );
	String_Appendf( sbFwdDec, "inline %s %s( const %s %s );\n", fullTypeName, negateFuncStr, parmTypeName, parmName );
	String_Append(  sbFwdDec, "\n" );

	String_Appendf( sbImpl, "%s %s( const %s %s )\n", fullTypeName, negateFuncStr, parmTypeName, parmName );
	String_Append(  sbImpl, "{\n" );
	String_Appendf( sbImpl, "\treturn HLML_CONSTRUCT( %s )\n", fullTypeName );
	String_Append(  sbImpl, "\t{\n" );
	if ( isMatrix ) {
		char funcNameNegateVector[GEN_STRING_LENGTH_FUNCTION_NAME];
		Gen_GetFuncNameNegate( language, type, 1, numRows, funcNameNegateVector );

		for ( u32 row = 0; row < numRows; row++ ) {
			String_Appendf( sbImpl, "\t\t%s( %s%srows[%d] )", funcNameNegateVector, parmAccessStr, parmName, row );

			if ( row != numRows - 1 ) {
				String_Append( sbImpl, "," );
			}

			String_Append( sbImpl, "\n" );
		}
	} else {
		for ( u32 componentIndex = 0; componentIndex < numCols; componentIndex++ ) {
			String_Appendf( sbImpl, "\t\t-%s%s%c", parmName, parmAccessStr, GEN_COMPONENT_NAMES_VECTOR[componentIndex] );

			if ( componentIndex != numCols - 1 ) {
				String_Append( sbImpl, "," );
			}

			String_Append( sbImpl, "\n" );
		}
	}
	String_Append(  sbImpl, "\t};\n" );
	String_Append(  sbImpl, "}\n" );
	String_Append(  sbImpl, "\n" );
}

void Gen_OperatorsEquality( const genType_t type, const u32 numRows, const u32 numCols, stringBuilder_t* sbFwdDec, stringBuilder_t* sbImpl ) {
	assert( numRows >= 1 );	// pass through 1 for vectors
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );
	assert( sbFwdDec );
	assert( sbImpl );

	char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetFullTypeName( type, numRows, numCols, fullTypeName );

	char equalsFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameEquals( GEN_LANGUAGE_CPP, type, numRows, numCols, equalsFuncStr );

	// equals
	String_Appendf( sbFwdDec, "inline bool operator==( const %s& lhs, const %s& rhs );\n", fullTypeName, fullTypeName );
	String_Append(  sbFwdDec, "\n" );

	String_Appendf( sbImpl, "bool operator==( const %s& lhs, const %s& rhs )\n", fullTypeName, fullTypeName );
	String_Append(  sbImpl, "{\n" );
	if ( numRows == 1 ) {
		Gen_VectorGetCodeEquals( GEN_LANGUAGE_CPP, type, numCols, sbImpl );
	} else {
		Gen_MatrixGetCodeEquals( GEN_LANGUAGE_CPP, type, numRows, numCols, sbImpl );
	}
	String_Append(  sbImpl, "}\n" );
	String_Append(  sbImpl, "\n" );

	// not equals
	String_Appendf( sbFwdDec, "inline bool operator!=( const %s& lhs, const %s& rhs );\n", fullTypeName, fullTypeName );
	String_Append(  sbFwdDec, "\n" );

	String_Appendf( sbImpl, "bool operator!=( const %s& lhs, const %s& rhs )\n", fullTypeName, fullTypeName );
	String_Append(  sbImpl, "{\n" );
	String_Appendf( sbImpl, "\treturn !( operator==( lhs, rhs ) );\n", equalsFuncStr );
	String_Append(  sbImpl, "}\n" );
	String_Append(  sbImpl, "\n" );
}

void Gen_OperatorsIncrement( const genType_t type, const u32 numRows, const u32 numCols, stringBuilder_t* sbFwdDec, stringBuilder_t* sbImpl ) {
	assert( numRows >= 1 );	// pass through 1 for vectors
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );
	assert( sbFwdDec );
	assert( sbImpl );

	if ( type == GEN_TYPE_BOOL ) {
		return;
	}

	for ( u32 opIndex = 0; opIndex < GEN_OP_INCREMENT_COUNT; opIndex++ ) {
		genOpIncrement_t op = (genOpIncrement_t) opIndex;

		GenerateOperatorIncrementInl( type, numRows, numCols, op, sbFwdDec, sbImpl );
	}
}

void Gen_OperatorNegate( const genType_t type, const u32 numRows, const u32 numCols, stringBuilder_t* sbFwdDec, stringBuilder_t* sbImpl ) {
	assert( numRows >= 1 );	// pass through 1 for vectors
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );
	assert( sbFwdDec );
	assert( sbImpl );

	if ( type == GEN_TYPE_BOOL ) {
		return;
	}

	char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetFullTypeName( type, numRows, numCols, fullTypeName );

	bool32 isMatrix = numRows > 1;

	const char* parmName = isMatrix ? "mat" : "vec";

	Doc_Negate( sbFwdDec, fullTypeName );
	String_Appendf( sbFwdDec, "inline %s operator-( const %s& %s );\n", fullTypeName, fullTypeName, parmName );
	String_Append(  sbFwdDec, "\n");

	String_Appendf( sbImpl, "%s operator-( const %s& %s )\n", fullTypeName, fullTypeName, parmName );
	String_Append(  sbImpl, "{\n");
	String_Appendf( sbImpl, "\treturn HLML_CONSTRUCT( %s ) {\n", fullTypeName );
	if ( isMatrix ) {
		for ( u32 row = 0; row < numRows; row++ ) {
			for ( u32 col = 0; col < numCols; col++ ) {
				String_Appendf( sbImpl, "-%s.rows[%d]", parmName, col );

				if ( col != numCols - 1 ) {
					String_Append( sbImpl, "," );
				}

				String_Append( sbImpl, "\n" );
			}
		}
	} else {
		for ( u32 componentIndex = 0; componentIndex < numCols; componentIndex++ ) {
			String_Appendf( sbImpl, "\t\t-%s.%c", parmName, GEN_COMPONENT_NAMES_VECTOR[componentIndex] );

			if ( componentIndex != numCols - 1 ) {
				String_Append( sbImpl, "," );
			}

			String_Append( sbImpl, "\n" );
		}
	}
	String_Append(  sbImpl, "\t};\n" );
	String_Append(  sbImpl, "}\n");
	String_Append(  sbImpl, "\n");
}

void Gen_NotEquals( const genLanguage_t language, const genType_t type, const u32 numRows, const u32 numCols, stringBuilder_t* sbFwdDec, stringBuilder_t* sbImpl ) {
	assert( numRows >= 1 );	// pass through 1 for vectors
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );
	assert( sbFwdDec );
	assert( sbImpl );

	char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetFullTypeName( type, numRows, numCols, fullTypeName );

	char parmTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetParmTypeName( language, type, numRows, numCols, parmTypeName );

	char equalsFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameEquals( language, type, numRows, numCols, equalsFuncStr );

	char notEqualsFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameNotEquals( language, type, numRows, numCols, notEqualsFuncStr );

	Doc_OperatorNotEquals( sbFwdDec, fullTypeName );
	String_Appendf( sbFwdDec, "inline bool %s( const %s lhs, const %s rhs );\n", notEqualsFuncStr, parmTypeName, parmTypeName );
	String_Append(  sbFwdDec, "\n" );

	String_Appendf( sbImpl, "bool %s( const %s lhs, const %s rhs )\n", notEqualsFuncStr, parmTypeName, parmTypeName );
	String_Append(  sbImpl, "{\n" );
	String_Appendf( sbImpl, "\treturn !( %s( lhs, rhs ) );\n", equalsFuncStr );
	String_Append(  sbImpl, "}\n" );
	String_Append(  sbImpl, "\n" );
}

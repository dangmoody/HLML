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
#include "gen_c.h"

#include "defines.h"

#include "gen_common.h"
#include "gen_common_sse.h"

#include "gen_doc_common.h"

#include "gen_funcs_vector_sse.h"
#include "gen_funcs_matrix_sse.h"

#include "allocator.h"
#include "string_builder.h"
#include "file_io.h"

static void Gen_VectorType_C( const genType_t type, const u32 numComponents ) {
	assert( numComponents >= GEN_COMPONENT_COUNT_MIN );
	assert( numComponents <= GEN_COMPONENT_COUNT_MAX );

	const char* typeString = Gen_GetTypeString( type );
	const char* memberTypeString = Gen_GetMemberTypeString( type );

	char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	snprintf( fullTypeName, GEN_STRING_LENGTH_TYPE_NAME, "%s%d", typeString, numComponents );

	stringBuilder_t codeHeader = String_Create( 3 * KB_TO_BYTES );

	String_Append(  &codeHeader, GEN_FILE_HEADER );
	String_Append(  &codeHeader,
		"#pragma once\n"
		"\n"
	);

	if ( type == GEN_TYPE_BOOL ) {
		String_Append(  &codeHeader, "#include \"../" GEN_HEADER_TYPES "\"\n" );
		String_Append(  &codeHeader, "\n" );
	}

	Doc_Vector( &codeHeader, numComponents, memberTypeString );
	String_Appendf( &codeHeader, "typedef struct %s\n", fullTypeName );
	String_Append(  &codeHeader, "{\n" );
	for ( u32 i = 0; i < numComponents; i++ ) {
		String_Appendf( &codeHeader, "\t%s %c;\n", memberTypeString, GEN_COMPONENT_NAMES_VECTOR[i] );
	}
	String_Appendf( &codeHeader, "} %s;\n", fullTypeName );

	char fileNameHeader[64] = {};
	snprintf( fileNameHeader, 64, "%s%s.h", GEN_FOLDER_PATHS_OUT_GEN[GEN_LANGUAGE_C], fullTypeName );

	FS_WriteEntireFile( fileNameHeader, codeHeader.str, codeHeader.length );

	Mem_Reset();
}

static void Gen_MatrixType_C( const genType_t type, const u32 numRows, const u32 numCols ) {
	assert( numRows >= GEN_COMPONENT_COUNT_MIN );
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );

	const char* typeString = Gen_GetTypeString( type );

	char vectorMemberTypeString[GEN_STRING_LENGTH_TYPE_NAME];
	snprintf( vectorMemberTypeString, GEN_STRING_LENGTH_TYPE_NAME, "%s%d", typeString, numCols );

	char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	snprintf( fullTypeName, GEN_STRING_LENGTH_TYPE_NAME, "%s%dx%d", typeString, numRows, numCols );

	stringBuilder_t codeHeader = String_Create( 3 * KB_TO_BYTES );

	String_Append(  &codeHeader, GEN_FILE_HEADER );

	String_Append(  &codeHeader,
		"#pragma once\n"
		"\n"
	);

	Doc_Matrix( &codeHeader, numRows, vectorMemberTypeString );
	String_Appendf( &codeHeader, "typedef struct %s\n", fullTypeName );
	String_Append(  &codeHeader, "{\n" );
	String_Appendf( &codeHeader, "\t%s rows[%d];\n", vectorMemberTypeString, numRows );
	String_Appendf( &codeHeader, "} %s;\n", fullTypeName );

	char fileNameHeader[64] = {};
	snprintf( fileNameHeader, 64, "%s%s.h", GEN_FOLDER_PATHS_OUT_GEN[GEN_LANGUAGE_C], fullTypeName );

	FS_WriteEntireFile( fileNameHeader, codeHeader.str, codeHeader.length );

	Mem_Reset();
}

void Gen_Vectors_C( void ) {
	for ( u32 typeIndex = 0; typeIndex < GEN_TYPE_COUNT; typeIndex++ ) {
		genType_t type = (genType_t) typeIndex;

		const char* typeString = Gen_GetTypeString( type );

		for ( u32 componentIndex = GEN_COMPONENT_COUNT_MIN; componentIndex <= GEN_COMPONENT_COUNT_MAX; componentIndex++ ) {
			printf( "Generating %s%d...", typeString, componentIndex );

			Gen_VectorType_C( type, componentIndex );

			printf( "OK.\n" );
		}
	}
}

void Gen_Matrices_C( void ) {
	for ( u32 typeIndex = 0; typeIndex < GEN_TYPE_COUNT; typeIndex++ ) {
		genType_t type = (genType_t) typeIndex;

		const char* typeString = Gen_GetTypeString( type );

		for ( u32 row = GEN_COMPONENT_COUNT_MIN; row <= GEN_COMPONENT_COUNT_MAX; row++ ) {
			for ( u32 col = GEN_COMPONENT_COUNT_MIN; col <= GEN_COMPONENT_COUNT_MAX; col++ ) {
				printf( "Generating %s%dx%d...", typeString, row, col );

				Gen_MatrixType_C( type, row, col );

				printf( "OK.\n" );
			}
		}
	}
}
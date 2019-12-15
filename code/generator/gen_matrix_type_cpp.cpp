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
#include "gen_matrix_cpp.h"

#include "gen_common.h"
#include "gen_doc_common.h"

#include "string_builder.h"
#include "allocator.h"
#include "file_io.h"

static void GenerateDocCtorDefault( stringBuilder_t* codeHeader ) {
	assert( codeHeader );

	String_Append( codeHeader, "\t/// Default constructor.  Sets the matrix to an identity matrix.\n" );
}

static void GenerateDocCtorDiagonalScalar( stringBuilder_t* codeHeader ) {
	assert( codeHeader );

	String_Append( codeHeader,
		"\t/// \\brief Sets each of the diagonal values of the matrix to the given scalar value.\n" \
		"\t/// Setting the scalar to 1 will give an identity matrix.\n" );
}

static void GenerateDocCtorDiagonalVector( stringBuilder_t* codeHeader ) {
	assert( codeHeader );

	String_Append( codeHeader,
		"\t/// \\brief Sets the diagonal values of the matrix to the corresponding components of the given vector.\n" \
		"\t/// Setting each component of the vector to 1 will give an identity matrix.\n" );
}

static void GenerateDocCtorRow( stringBuilder_t* codeHeader ) {
	assert( codeHeader );

	String_Append( codeHeader, "\t/// Sets each row of the matrix to the given vectors.\n" );
}

static void GenerateDocCtorRowArray( stringBuilder_t* codeHeader ) {
	assert( codeHeader );

	String_Append( codeHeader, "\t/// Sets each row of the matrix to the corresponding vector in the array.\n" );
}

static void GenerateDocCtorRowsAndCols( stringBuilder_t* codeHeader ) {
	assert( codeHeader );

	String_Append( codeHeader, "\t/// Sets each component of the vector to the corresponding scalar value (row major).\n" );
}

static void GenerateDocCtorCopy( stringBuilder_t* codeHeader ) {
	assert( codeHeader );

	String_Append( codeHeader, "\t/// Copy constructor.  Sets each row of the matrix to the rows in the other matrix.\n" );
}

static void GenerateDocOperatorAssignment( stringBuilder_t* codeHeader ) {
	assert( codeHeader );

	String_Append( codeHeader, "\t/// Copies each row of the given matrix via a single memcpy.\n" );
}

static void GenerateDocOperatorArray( stringBuilder_t* codeHeader, const u32 numRows ) {
	assert( codeHeader );
	assert( numRows >= GEN_COMPONENT_COUNT_MIN );
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );

	String_Appendf( codeHeader,
		"\t/// \\brief Returns the row at the given index of the matrix.\n" \
		"\t/// Index CANNOT be lower than 0 or higher than %d.\n", numRows - 1 );
}

static void GenerateConstructors( stringBuilder_t* codeFwdDec, stringBuilder_t* codeInl, const u32 numRows, const u32 numCols, const char* fullTypeName, const char* memberTypeString, const char* vectorMemberTypeString ) {
	assert( codeFwdDec );
	assert( codeInl );
	assert( numRows >= GEN_COMPONENT_COUNT_MIN );
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );
	assert( fullTypeName );
	assert( memberTypeString );

	// default ctor
	{
		GenerateDocCtorDefault( codeFwdDec );
		String_Appendf( codeFwdDec, "\tinline %s() {}\n", fullTypeName );
		String_Append(  codeFwdDec, "\n" );
	}

	// "diagonal" scaled uniform identity ctor
	{
		GenerateDocCtorDiagonalScalar( codeFwdDec );
		String_Appendf( codeFwdDec, "\tinline %s( const %s diagonal );\n", fullTypeName, memberTypeString );
		String_Append(  codeFwdDec, "\n" );

		String_Appendf( codeInl, "%s::%s( const %s diagonal )\n", fullTypeName, fullTypeName, memberTypeString );
		String_Append(  codeInl, "{\n" );
		for ( u32 i = 0; i < numRows; i++ ) {
			String_Appendf( codeInl, "\trows[%d] = { ", i );
			for ( u32 j = 0; j < numCols; j++ ) {
				String_Append( codeInl, ( i == j ) ? "diagonal" : "0" );

				if ( j != numCols - 1 ) {
					String_Append( codeInl, ", " );
				}
			}
			String_Append( codeInl, " };\n" );
		}
		String_Append( codeInl, "}\n\n" );
	}

	// "diagonal" scaled non-uniform identity ctor
	{
		GenerateDocCtorDiagonalVector( codeFwdDec );
		String_Appendf( codeFwdDec, "\tinline %s( const %s& diagonal );\n", fullTypeName, vectorMemberTypeString );
		String_Append(  codeFwdDec, "\n" );

		String_Appendf( codeInl, "%s::%s( const %s& diagonal )\n", fullTypeName, fullTypeName, vectorMemberTypeString );
		String_Append(  codeInl, "{\n" );
		for ( u32 i = 0; i < numRows; i++ ) {
			String_Appendf( codeInl, "\trows[%d] = { ", i );
			for ( u32 j = 0; j < numCols; j++ ) {
				if ( i == j ) {
					String_Appendf( codeInl, "diagonal.%c", GEN_COMPONENT_NAMES_VECTOR[j] );
				} else {
					String_Append( codeInl, "0" );
				}

				if ( j != numCols - 1 ) {
					String_Append( codeInl, ", " );
				}
			}
			String_Append( codeInl, " };\n" );
		}
		String_Append( codeInl, "}\n\n" );
	}

	// row memberwise ctor
	{
		GenerateDocCtorRow( codeFwdDec );
		String_Appendf( codeFwdDec, "\tinline %s( ", fullTypeName );
		for ( u32 i = 0; i < numRows; i++ ) {
			String_Appendf( codeFwdDec, "const %s& row%d", vectorMemberTypeString, i );

			if ( i != numRows - 1 ) {
				String_Append( codeFwdDec, ", " );
			}
		}
		String_Append( codeFwdDec, " );\n" );
		String_Append( codeFwdDec, "\n" );

		String_Appendf( codeInl, "%s::%s( ", fullTypeName, fullTypeName );
		for ( u32 i = 0; i < numRows; i++ ) {
			String_Appendf( codeInl, "const %s& row%d", vectorMemberTypeString, i );

			if ( i != numRows - 1 ) {
				String_Append( codeInl, ", " );
			}
		}
		String_Append( codeInl, " )\n" );
		String_Append( codeInl, "{\n" );
		for ( u32 i = 0; i < numRows; i++ ) {
			String_Appendf( codeInl, "\trows[%d] = row%d;\n", i, i );
		}
		String_Append( codeInl, "}\n\n" );
	}

	// array of rows ctor
	{
		GenerateDocCtorRowArray( codeFwdDec );
		String_Appendf( codeFwdDec, "\tinline %s( const %s rows[%d] );\n", fullTypeName, vectorMemberTypeString, numRows );
		String_Append(  codeFwdDec, "\n" );

		String_Appendf( codeInl, "%s::%s( const %s rows[%d] )\n", fullTypeName, fullTypeName, vectorMemberTypeString, numRows );
		String_Append(  codeInl, "{\n" );
		for ( u32 i = 0; i < numRows; i++ ) {
			String_Appendf( codeInl, "\tthis->rows[%d] = rows[%d];\n", i, i );
		}
		String_Append( codeInl, "}\n\n" );
	}

	// memberwise rows * cols ctor
	{
		GenerateDocCtorRowsAndCols( codeFwdDec );
		String_Appendf( codeFwdDec, "\tinline %s( ", fullTypeName );
		for ( u32 row = 0; row < numRows; row++ ) {
			for ( u32 col = 0; col < numCols; col++ ) {
				String_Appendf( codeFwdDec, "const %s m%d%d", memberTypeString, row, col );

				if ( col != numCols - 1 ) {
					String_Append( codeFwdDec, ", " );
				}
			}

			if ( row != numRows - 1 ) {
				String_Append( codeFwdDec, ", " );
			}
		}
		String_Append( codeFwdDec, " );\n" );
		String_Append( codeFwdDec, "\n" );

		String_Appendf( codeInl, "%s::%s( ", fullTypeName, fullTypeName );
		for ( u32 row = 0; row < numRows; row++ ) {
			for ( u32 col = 0; col < numCols; col++ ) {
				String_Appendf( codeInl, "const %s m%d%d", memberTypeString, row, col );

				if ( col != numCols - 1 ) {
					String_Append( codeInl, ", " );
				}
			}

			if ( row != numRows - 1 ) {
				String_Append( codeInl, ", " );
			}
		}
		String_Append( codeInl, " )\n" );
		String_Append( codeInl, "{\n" );
		for ( u32 row = 0; row < numRows; row++ ) {
			String_Appendf( codeInl, "\trows[%d] = { ", row );

			for ( u32 col = 0; col < numCols; col++ ) {
				String_Appendf( codeInl, "m%d%d", row, col );

				if ( col != numCols - 1 ) {
					String_Append( codeInl, ", " );
				}
			}
			String_Append( codeInl, " };\n" );
		}
		String_Append( codeInl, "}\n\n" );
	}

	// copy ctor
	{
		GenerateDocCtorCopy( codeFwdDec );
		String_Appendf( codeFwdDec, "\tinline %s( const %s& other );\n", fullTypeName, fullTypeName );
		String_Append(  codeFwdDec, "\n" );

		String_Appendf( codeInl, "%s::%s( const %s& other )\n", fullTypeName, fullTypeName, fullTypeName );
		String_Append(  codeInl, "{\n" );
		String_Appendf( codeInl, "\tmemcpy( rows, other.rows, sizeof( rows ) );\n" );
		String_Append(  codeInl, "}\n" );
		String_Append(  codeInl, "\n" );
	}

	// dtor
	String_Appendf( codeFwdDec, "\tinline ~%s() {}\n", fullTypeName );
	String_Append(  codeFwdDec, "\n" );
}

static void GenerateOperatorsAssignment( stringBuilder_t* codeHeader, stringBuilder_t* codeInl, const char* fullTypeName ) {
	assert( codeHeader );
	assert( codeInl );
	assert( fullTypeName );

	// assignment operator
	GenerateDocOperatorAssignment( codeHeader );
	String_Appendf( codeHeader, "\tinline %s operator=( const %s& other );\n", fullTypeName, fullTypeName );
	String_Append(  codeHeader, "\n" );

	String_Appendf( codeInl, "%s %s::operator=( const %s& other )\n", fullTypeName, fullTypeName, fullTypeName );
	String_Append(  codeInl, "{\n" );
	String_Append(  codeInl, "\tmemcpy( rows, other.rows, sizeof( rows ) );\n" );
	String_Append(  codeInl, "\treturn *this;\n" );
	String_Append(  codeInl, "}\n" );
	String_Append(  codeInl, "\n" );
}

static void GenerateOperatorsArray( stringBuilder_t* codeHeader, stringBuilder_t* codeInl, const u32 numRows, const char* vectorMemberTypeString, const char* fullTypeName ) {
	assert( codeHeader );
	assert( codeInl );
	assert( numRows >= GEN_COMPONENT_COUNT_MIN );
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( vectorMemberTypeString );
	assert( fullTypeName );

	GenerateDocOperatorArray( codeHeader, numRows );
	String_Appendf( codeHeader, "\tinline %s& operator[]( const uint32_t index );\n", vectorMemberTypeString );
	String_Append(  codeHeader, "\n" );

	String_Appendf( codeInl, "%s& %s::operator[]( const uint32_t index )\n", vectorMemberTypeString, fullTypeName );
	String_Append(  codeInl, "{\n" );
	String_Appendf( codeInl, "\tassert( index < %d );\n", numRows );
	String_Append(  codeInl, "\treturn rows[index];\n" );
	String_Append(  codeInl, "}\n" );
	String_Append(  codeInl, "\n" );

	GenerateDocOperatorArray( codeHeader, numRows );
	String_Appendf( codeHeader, "\tinline const %s& operator[]( const uint32_t index ) const;\n", vectorMemberTypeString );

	String_Appendf( codeInl, "const %s& %s::operator[]( const uint32_t index ) const\n", vectorMemberTypeString, fullTypeName );
	String_Append(  codeInl, "{\n" );
	String_Appendf( codeInl, "\tassert( index < %d );\n", numRows );
	String_Append(  codeInl, "\treturn rows[index];\n" );
	String_Append(  codeInl, "}\n" );
	String_Append(  codeInl, "\n" );
}

void Gen_MatrixType_CPP( const genType_t type, const u32 numRows, const u32 numCols ) {
	assert( numRows >= GEN_COMPONENT_COUNT_MIN );
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );

	const char* typeString = Gen_GetTypeString( type );
	const char* memberTypeString = Gen_GetMemberTypeString( type );

	char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	snprintf( fullTypeName, GEN_STRING_LENGTH_TYPE_NAME, "%s%dx%d", typeString, numRows, numCols );

	char transposedTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	snprintf( transposedTypeName, GEN_STRING_LENGTH_TYPE_NAME, "%s%dx%d", typeString, numCols, numRows );

	char vectorMemberTypeString[GEN_STRING_LENGTH_TYPE_NAME];
	snprintf( vectorMemberTypeString, GEN_STRING_LENGTH_TYPE_NAME, "%s%d", typeString, numCols );

	stringBuilder_t codeHeader = String_Create( 8 * KB_TO_BYTES );
	stringBuilder_t codeInl = String_Create( 8 * KB_TO_BYTES );

	// header pre-functions
	{
		String_Append( &codeHeader, GEN_FILE_HEADER );

		String_Append( &codeHeader, "#pragma once\n" );
		String_Append( &codeHeader, "\n" );

		String_Appendf( &codeHeader, "#include \"%s%d.h\"\n", typeString, numCols );						// vec type
		if ( numRows != numCols ) {
			String_Appendf( &codeHeader, "#include \"%s%dx%d.h\"\n", typeString, numRows, numRows );	// multiplication return type
			String_Appendf( &codeHeader, "#include \"%s.h\"\n", transposedTypeName );						// transpose type
		}
		String_Append( &codeHeader, "\n" );

		Doc_Matrix( &codeHeader, numRows, vectorMemberTypeString );
		String_Appendf( &codeHeader, "struct %s\n", fullTypeName );
		String_Append(  &codeHeader, "{\n" );
		String_Appendf( &codeHeader, "\t%s rows[%d];\n", vectorMemberTypeString, numRows );
		String_Append(  &codeHeader, "\n" );
	}

	// inl pre-functions
	{
		String_Append(  &codeInl, GEN_FILE_HEADER );
		String_Append(  &codeInl, "#pragma once\n" );
		String_Append(  &codeInl, "\n" );

		String_Append(  &codeInl, "// hlml includes\n" );
		String_Appendf( &codeInl, "#include \"%s.h\"\n", fullTypeName );
		String_Append(  &codeInl, "\n" );

		String_Append(  &codeInl, "// others\n" );
		String_Append(  &codeInl, "#include <math.h>\n" );
		String_Append(  &codeInl, "#include <memory.h>\n" );
		String_Append(  &codeInl, "#include <assert.h>\n" );
		String_Append(  &codeInl, "\n" );

		if ( type != GEN_TYPE_BOOL ) {
			String_Append(  &codeInl, "// forward declares\n" );
			String_Appendf( &codeInl, "%s inverse( const %s& mat );\n", fullTypeName, fullTypeName );

			String_Append( &codeInl, "\n" );
		}
	}

	GenerateConstructors( &codeHeader, &codeInl, numRows, numCols, fullTypeName, memberTypeString, vectorMemberTypeString );

	GenerateOperatorsAssignment( &codeHeader, &codeInl, fullTypeName );

	GenerateOperatorsArray( &codeHeader, &codeInl, numRows, vectorMemberTypeString, fullTypeName );

	String_Append( &codeHeader, "};\n\n" );

	// GenerateOperatorsEquality( &codeHeader, &codeInl, type, numRows, numCols, fullTypeName );

	const char* folder = GEN_FOLDER_PATHS_OUT_GEN[GEN_LANGUAGE_CPP];

	char fileNameHeader[64];
	snprintf( fileNameHeader, 64, "%s%s.h", folder, fullTypeName );

	char fileNameInl[64];
	snprintf( fileNameInl, 64, "%s%s.inl", folder, fullTypeName );

	FS_WriteEntireFile( fileNameHeader, codeHeader.str, codeHeader.length );
	FS_WriteEntireFile( fileNameInl, codeInl.str, codeInl.length );

	Mem_Reset();
}

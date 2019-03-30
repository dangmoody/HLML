/*
===========================================================================

hlml.
Copyright (c) Dan Moody 2018 - Present.

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

#include "GeneratorVector.h"
#include "GeneratorMatrix.h"

#include "GeneratorScalarTests.h"
#include "GeneratorVectorTests.h"
#include "GeneratorMatrixTests.h"

#include "gen_funcs_vector.h"
#include "gen_funcs_matrix.h"

#include "FileIO.h"

#include <stdio.h>
#include <assert.h>

#include <string>

static bool GenerateMainHeaderFuncs( void ) {
	char fileNameHeader[1024];
	sprintf( fileNameHeader, "%s%s.h", GEN_OUT_GEN_FOLDER_PATH, GEN_FILENAME_FUNCTIONS_SCALAR );

	std::string contentHeader = GEN_FILE_HEADER;
	contentHeader += "#pragma once\n";
	contentHeader += "\n";
	contentHeader += "#include \"../" + std::string( GEN_HEADER_CONSTANTS ) + "\"\n";
	contentHeader += "\n";
	contentHeader += "#include <math.h>\n";
	contentHeader += "#include <stdint.h>\n";
	contentHeader += "\n";

	for ( uint32_t typeIndex = 0; typeIndex < GEN_TYPE_COUNT; typeIndex++ ) {
		genType_t type = static_cast<genType_t>( typeIndex );

		if ( type == GEN_TYPE_BOOL ) {
			continue;
		}

		std::string memberTypeString = Gen_GetMemberTypeString( type );

		printf( "Generating %s...", memberTypeString.c_str() );

		contentHeader += "// " + memberTypeString + "\n";

		// scalar only funcs
		Gen_Floateq( type, contentHeader );

		Gen_IsInf( type, contentHeader );
		Gen_IsNaN( type, contentHeader );

		Gen_Sign( type, contentHeader );

		Gen_Radians( type, contentHeader );
		Gen_Degrees( type, contentHeader );

		Gen_MinMax( type, contentHeader );
		Gen_Clamp( type, contentHeader );

		// generic/scalar/vector funcs
		Gen_Saturate( type, 1, contentHeader, nullptr );

		Gen_Lerp( type, 1, contentHeader, nullptr );
		Gen_Smoothstep( type, 1, contentHeader, nullptr );

		contentHeader += "\n";

		printf( "OK.\n" );
	}

	if ( !FS_WriteToFile( fileNameHeader, contentHeader.c_str(), contentHeader.size() ) ) {
		return false;
	}

	return true;
}

static bool GenerateImplVectors( void ) {
	GeneratorVector gen;

	for ( uint32_t typeIndex = 0; typeIndex < GEN_TYPE_COUNT; typeIndex++ ) {
		genType_t type = static_cast<genType_t>( typeIndex );

		std::string typeString = Gen_GetTypeString( type );

		for ( uint32_t componentIndex = GEN_COMPONENT_COUNT_MIN; componentIndex <= GEN_COMPONENT_COUNT_MAX; componentIndex++ ) {
			printf( "Generating %s%d...", typeString.c_str(), componentIndex );

			if ( !gen.Generate( type, componentIndex ) ) {
				return false;
			}

			printf( "OK.\n" );
		}
	}

	return true;
}

static bool GenerateImplMatrices( void ) {
	GeneratorMatrix gen;

	for ( uint32_t typeIndex = 0; typeIndex < GEN_TYPE_COUNT; typeIndex++ ) {
		genType_t type = static_cast<genType_t>( typeIndex );

		std::string typeString = Gen_GetTypeString( type );

		for ( uint32_t row = GEN_COMPONENT_COUNT_MIN; row <= GEN_COMPONENT_COUNT_MAX; row++ ) {
			for ( uint32_t col = GEN_COMPONENT_COUNT_MIN; col <= GEN_COMPONENT_COUNT_MAX; col++ ) {
				printf( "Generating %s%dx%d...", typeString.c_str(), row, col );

				if ( !gen.Generate( type, row, col ) ) {
					return false;
				}

				printf( "OK.\n" );
			}
		}
	}

	return true;
}

static bool GenerateMainTypeHeaderVector( void ) {
	char headerFilePath[1024] = { 0 };
	sprintf( headerFilePath, "%s%s", GEN_OUT_GEN_FOLDER_PATH, GEN_HEADER_VECTOR );

	std::string content = GEN_FILE_HEADER;

	for ( uint32_t typeIndex = 0; typeIndex < GEN_TYPE_COUNT; typeIndex++ ) {
		genType_t type = static_cast<genType_t>( typeIndex );

		for ( uint32_t componentIndex = GEN_COMPONENT_COUNT_MIN; componentIndex <= GEN_COMPONENT_COUNT_MAX; componentIndex++ ) {
			content += "#include \"" + Gen_GetFullTypeName( type, 1, componentIndex ) + ".h\"\n";
		}
		content += "\n";
	}

	content += "#include \"hlml_functions_vector.h\"\n";

	return FS_WriteToFile( headerFilePath, content.c_str(), content.size() );
}

static bool GenerateMainTypeHeaderMatrix( void ) {
	char headerFilePath[1024] = { 0 };
	sprintf( headerFilePath, "%s%s", GEN_OUT_GEN_FOLDER_PATH, GEN_HEADER_MATRIX );

	std::string content = GEN_FILE_HEADER;

	for ( uint32_t typeIndex = 0; typeIndex < GEN_TYPE_COUNT; typeIndex++ ) {
		genType_t type = static_cast<genType_t>( typeIndex );

		for ( uint32_t row = GEN_COMPONENT_COUNT_MIN; row <= GEN_COMPONENT_COUNT_MAX; row++ ) {
			for ( uint32_t col = GEN_COMPONENT_COUNT_MIN; col <= GEN_COMPONENT_COUNT_MAX; col++ ) {
				content += "#include \"" + Gen_GetFullTypeName( type, row, col ) + ".h\"\n";
			}
			content += "\n";
		}
	}

	content += "#include \"hlml_functions_matrix.h\"\n";

	return FS_WriteToFile( headerFilePath, content.c_str(), content.size() );
}

static bool GenerateOperatorsVector( void ) {
	char filePathHeader[1024] = { 0 };
	sprintf( filePathHeader, "%s%s.h", GEN_OUT_GEN_FOLDER_PATH, GEN_FILENAME_OPERATORS_VECTOR );

	char filePathInl[1024] = { 0 };
	sprintf( filePathInl, "%s%s.inl", GEN_OUT_GEN_FOLDER_PATH, GEN_FILENAME_OPERATORS_VECTOR );

	std::string content = GEN_FILE_HEADER;

	std::string contentHeader = content;
	contentHeader += "#pragma once\n";
	contentHeader += "\n";

	std::string contentInl = content;
	contentInl += std::string( "#include \"" ) + GEN_FILENAME_OPERATORS_VECTOR + ".h\"\n";

	// includes
	for ( uint32_t typeIndex = 0; typeIndex < GEN_TYPE_COUNT; typeIndex++ ) {
		genType_t type = static_cast<genType_t>( typeIndex );

		for ( uint32_t componentIndex = GEN_COMPONENT_COUNT_MIN; componentIndex <= GEN_COMPONENT_COUNT_MAX; componentIndex++ ) {
			contentHeader += "#include \"" + Gen_GetFullTypeName( type, 1, componentIndex ) + ".h\"\n";
		}
	}

	contentHeader += "\n";
	contentInl += "\n";

	// header and inl code
	for ( uint32_t typeIndex = 0; typeIndex < GEN_TYPE_COUNT; typeIndex++ ) {
		genType_t type = static_cast<genType_t>( typeIndex );

		if ( type == GEN_TYPE_BOOL ) {
			continue;
		}

		for ( uint32_t componentIndex = GEN_COMPONENT_COUNT_MIN; componentIndex <= GEN_COMPONENT_COUNT_MAX; componentIndex++ ) {
			std::string fullTypeName = Gen_GetFullTypeName( type, 1, componentIndex );

			printf( "Vector operators %s...", fullTypeName.c_str() );

			contentHeader += "// " + fullTypeName + "\n";
			contentInl += "// " + fullTypeName + "\n";

			Gen_VectorOperatorsArithmetic( type, componentIndex, contentHeader, contentInl );
			Gen_OperatorsIncrement( type, 1, componentIndex, contentHeader, contentInl );
			Gen_OperatorsRelational( type, 1, componentIndex, contentHeader, contentInl );
			Gen_OperatorsBitwise( type, 1, componentIndex, contentHeader, contentInl );

			contentHeader += "\n";
			contentInl += "\n";

			printf( "OK.\n" );
		}
	}

	contentHeader += "#include \"" + std::string( GEN_FILENAME_OPERATORS_VECTOR ) + ".inl\"\n";

	if ( !FS_WriteToFile( filePathHeader, contentHeader.c_str(), contentHeader.size() ) ) {
		return false;
	}

	if ( !FS_WriteToFile( filePathInl, contentInl.c_str(), contentInl.size() ) ) {
		return false;
	}

	return true;
}

static bool GenerateFunctionsVector( void ) {
	char filePathHeader[1024] = { 0 };
	sprintf( filePathHeader, "%s%s.h", GEN_OUT_GEN_FOLDER_PATH, GEN_FILENAME_FUNCTIONS_VECTOR );

	char filePathInl[1024] = { 0 };
	sprintf( filePathInl, "%s%s.inl", GEN_OUT_GEN_FOLDER_PATH, GEN_FILENAME_FUNCTIONS_VECTOR );

	std::string content = GEN_FILE_HEADER;

	std::string contentHeader = content;
	contentHeader += "#pragma once\n";
	contentHeader += "\n";

	std::string contentInl = content;
	contentInl += std::string( "#include \"" ) + GEN_FILENAME_OPERATORS_VECTOR + ".h\"\n";

	for ( uint32_t typeIndex = 0; typeIndex < GEN_TYPE_COUNT; typeIndex++ ) {
		genType_t type = static_cast<genType_t>( typeIndex );

		if ( type == GEN_TYPE_BOOL ) {
			continue;
		}

		for ( uint32_t componentIndex = GEN_COMPONENT_COUNT_MIN; componentIndex <= GEN_COMPONENT_COUNT_MAX; componentIndex++ ) {
			contentHeader += "#include \"" + Gen_GetFullTypeName( type, 1, componentIndex ) + ".h\"\n";
		}
	}

	contentHeader += "\n";
	contentInl += "\n";

	for ( uint32_t typeIndex = 0; typeIndex < GEN_TYPE_COUNT; typeIndex++ ) {
		genType_t type = static_cast<genType_t>( typeIndex );

		if ( type == GEN_TYPE_BOOL ) {
			continue;
		}

		for ( uint32_t componentIndex = GEN_COMPONENT_COUNT_MIN; componentIndex <= GEN_COMPONENT_COUNT_MAX; componentIndex++ ) {
			std::string fullTypeName = Gen_GetFullTypeName( type, 1, componentIndex );

			printf( "Algebra %s...", fullTypeName.c_str() );

			contentHeader += "// " + fullTypeName + "\n";
			contentInl += "// " + fullTypeName + "\n";

			// generic/scalar funcs
			Gen_Saturate( type, componentIndex, contentHeader, &contentInl );
			Gen_Lerp( type, componentIndex, contentHeader, &contentInl );
			Gen_Smoothstep( type, componentIndex, contentHeader, &contentInl );

			// generic/scalar/vector funcs
			Gen_VectorDot( type, componentIndex, contentHeader, contentInl );
			Gen_VectorLength( type, componentIndex, contentHeader, contentInl );
			Gen_VectorNormalize( type, componentIndex, contentHeader, contentInl );
			Gen_VectorCross( type, componentIndex, contentHeader, contentInl );
			Gen_VectorAngle( type, componentIndex, contentHeader, contentInl );
			Gen_VectorDistance( type, componentIndex, contentHeader, contentInl );
			Gen_VectorPack( type, componentIndex, contentHeader, contentInl );
			Gen_VectorUnpack( type, componentIndex, contentHeader, contentInl );

			contentHeader += "\n";
			contentInl += "\n";

			printf( "OK.\n" );
		}
	}

	contentHeader += "#include \"" + std::string( GEN_FILENAME_FUNCTIONS_VECTOR ) + ".inl\"\n";

	if ( !FS_WriteToFile( filePathHeader, contentHeader.c_str(), contentHeader.size() ) ) {
		return false;
	}

	if ( !FS_WriteToFile( filePathInl, contentInl.c_str(), contentInl.size() ) ) {
		return false;
	}

	return true;
}

static bool GenerateOperatorsMatrix( void ) {
	char filePathHeader[1024] = { 0 };
	sprintf( filePathHeader, "%s%s.h", GEN_OUT_GEN_FOLDER_PATH, GEN_FILENAME_OPERATORS_MATRIX );

	char filePathInl[1024] = { 0 };
	sprintf( filePathInl, "%s%s.inl", GEN_OUT_GEN_FOLDER_PATH, GEN_FILENAME_OPERATORS_MATRIX );

	std::string content = GEN_FILE_HEADER;

	std::string contentHeader = content;
	contentHeader += "#pragma once\n";
	contentHeader += "\n";

	std::string contentInl = content;
	contentInl += std::string( "#include \"" ) + GEN_FILENAME_OPERATORS_MATRIX + ".h\"\n";

	// includes
	for ( uint32_t typeIndex = 0; typeIndex < GEN_TYPE_COUNT; typeIndex++ ) {
		genType_t type = static_cast<genType_t>( typeIndex );

		if ( type == GEN_TYPE_BOOL ) {
			continue;
		}

		std::string typeString = Gen_GetTypeString( type );

		for ( uint32_t row = GEN_COMPONENT_COUNT_MIN; row <= GEN_COMPONENT_COUNT_MAX; row++ ) {
			std::string rowStr = std::to_string( row );

			for ( uint32_t col = GEN_COMPONENT_COUNT_MIN; col <= GEN_COMPONENT_COUNT_MAX; col++ ) {
				std::string colStr = std::to_string( col );

				contentHeader += "#include \"" + typeString + rowStr + "x" + colStr + ".h\"\n";
			}
		}
	}

	contentHeader += "\n";
	contentInl += "\n";

	// header and inl code
	for ( uint32_t typeIndex = 0; typeIndex < GEN_TYPE_COUNT; typeIndex++ ) {
		genType_t type = static_cast<genType_t>( typeIndex );

		if ( type == GEN_TYPE_BOOL ) {
			continue;
		}

		for ( uint32_t row = GEN_COMPONENT_COUNT_MIN; row <= GEN_COMPONENT_COUNT_MAX; row++ ) {
			for ( uint32_t col = GEN_COMPONENT_COUNT_MIN; col <= GEN_COMPONENT_COUNT_MAX; col++ ) {
				std::string fullTypeName = Gen_GetFullTypeName( type, row, col );

				printf( "Matrix operators %s...", fullTypeName.c_str() );

				contentHeader += "// " + fullTypeName + "\n";
				contentInl += "// " + fullTypeName + "\n";

				Gen_MatrixOperatorsArithmetic( type, row, col, contentHeader, contentInl );
				Gen_OperatorsIncrement( type, row, col, contentHeader, contentInl );
				Gen_OperatorsRelational( type, row, col, contentHeader, contentInl );
				Gen_OperatorsBitwise( type, row, col, contentHeader, contentInl );

				contentHeader += "\n";
				contentInl += "\n";

				printf( "OK.\n" );
			}
		}
	}

	contentHeader += "#include \"" + std::string( GEN_FILENAME_OPERATORS_MATRIX ) + ".inl\"\n";

	if ( !FS_WriteToFile( filePathHeader, contentHeader.c_str(), contentHeader.size() ) ) {
		return false;
	}

	if ( !FS_WriteToFile( filePathInl, contentInl.c_str(), contentInl.size() ) ) {
		return false;
	}

	return true;
}

static bool GenerateFunctionsMatrix( void ) {
	char filePathHeader[1024] = { 0 };
	sprintf( filePathHeader, "%s%s.h", GEN_OUT_GEN_FOLDER_PATH, GEN_FILENAME_FUNCTIONS_MATRIX );

	char filePathInl[1024] = { 0 };
	sprintf( filePathInl, "%s%s.inl", GEN_OUT_GEN_FOLDER_PATH, GEN_FILENAME_FUNCTIONS_MATRIX );

	std::string content = GEN_FILE_HEADER;

	std::string contentHeader = content;
	contentHeader += "#pragma once\n";
	contentHeader += "\n";

	std::string contentInl = content;
	contentInl += std::string( "#include \"" ) + GEN_FILENAME_FUNCTIONS_VECTOR + ".h\"\n";
	contentInl += std::string( "#include \"" ) + GEN_FILENAME_OPERATORS_MATRIX + ".h\"\n";

	for ( uint32_t typeIndex = 0; typeIndex < GEN_TYPE_COUNT; typeIndex++ ) {
		genType_t type = static_cast<genType_t>( typeIndex );

		std::string typeString = Gen_GetTypeString( type );

		for ( uint32_t row = GEN_COMPONENT_COUNT_MIN; row <= GEN_COMPONENT_COUNT_MAX; row++ ) {
			const std::string rowStr = std::to_string( row );

			for ( uint32_t col = GEN_COMPONENT_COUNT_MIN; col <= GEN_COMPONENT_COUNT_MAX; col++ ) {
				const std::string colStr = std::to_string( col );

				// TODO(DM): only include the header files we actually need
				contentHeader += "#include \"" + typeString + rowStr + "x" + colStr + ".h\"\n";
			}
		}

		contentHeader += "\n";
	}

	contentHeader += "\n";
	contentInl += "\n";

	for ( uint32_t typeIndex = 0; typeIndex < GEN_TYPE_COUNT; typeIndex++ ) {
		genType_t type = static_cast<genType_t>( typeIndex );

		for ( uint32_t row = GEN_COMPONENT_COUNT_MIN; row <= GEN_COMPONENT_COUNT_MAX; row++ ) {
			for ( uint32_t col = GEN_COMPONENT_COUNT_MIN; col <= GEN_COMPONENT_COUNT_MAX; col++ ) {
				std::string fullTypeName = Gen_GetFullTypeName( type, row, col );

				printf( "Basic functions %s...", fullTypeName.c_str() );

				contentHeader += "// " + fullTypeName + "\n";
				contentInl += "// " + fullTypeName + "\n";

				Gen_MatrixIdentity( type, row, col, contentHeader, contentInl );
				Gen_MatrixTranspose( type, row, col, contentHeader, contentInl );

				Gen_MatrixInverse( type, row, col, contentHeader, contentInl );
				Gen_MatrixDeterminant( type, row, col, contentHeader, contentInl );

				Gen_MatrixTranslate( type, row, col, contentHeader, contentInl );
				Gen_MatrixRotate( type, row, col, contentHeader, contentInl );
				Gen_MatrixScale( type, row, col, contentHeader, contentInl );

				Gen_MatrixOrtho( type, row, col, contentHeader, contentInl );
				Gen_MatrixPerspective( type, row, col, contentHeader, contentInl );
				Gen_MatrixLookAt( type, row, col, contentHeader, contentInl );

				contentHeader += "\n";
				contentInl += "\n";

				printf( "OK.\n" );
			}
		}
	}

	contentHeader += "#include \"" + std::string( GEN_FILENAME_FUNCTIONS_MATRIX ) + ".inl\"\n";

	if ( !FS_WriteToFile( filePathHeader, contentHeader.c_str(), contentHeader.size() ) ) {
		return false;
	}

	if ( !FS_WriteToFile( filePathInl, contentInl.c_str(), contentInl.size() ) ) {
		return false;
	}

	return true;
}

static bool GenerateTestsScalar( void ) {
	GeneratorScalarTest gen;

	for ( uint32_t typeIndex = 0; typeIndex < GEN_TYPE_COUNT; typeIndex++ ) {
		genType_t type = static_cast<genType_t>( typeIndex );

		if ( type == GEN_TYPE_BOOL ) {
			continue;
		}

		std::string typeString = Gen_GetTypeString( type );

		printf( "Generating test_scalar_%s.cpp...", typeString.c_str() );

		if ( !gen.Generate( type ) ) {
			return false;
		}

		printf( "OK.\n" );
	}

	return true;
}

static bool GenerateTestsVector( void ) {
	GeneratorVectorTests gen;

	for ( uint32_t typeIndex = 0; typeIndex < GEN_TYPE_COUNT; typeIndex++ ) {
		genType_t type = static_cast<genType_t>( typeIndex );

		std::string typeString = Gen_GetTypeString( type );

		for ( uint32_t componentIndex = GEN_COMPONENT_COUNT_MIN; componentIndex <= GEN_COMPONENT_COUNT_MAX; componentIndex++ ) {
			std::string typeName = typeString + std::to_string( componentIndex );

			printf( "Generating test_%s.cpp...", typeName.c_str() );

			if ( !gen.Generate( type, componentIndex ) ) {
				return false;
			}

			printf( "OK.\n" );
		}
	}

	return true;
}

static bool GenerateTestsMatrix( void ) {
	GeneratorMatrixTests gen;

	for ( uint32_t typeIndex = 0; typeIndex < GEN_TYPE_COUNT; typeIndex++ ) {
		genType_t type = static_cast<genType_t>( typeIndex );

		for ( uint32_t row = GEN_COMPONENT_COUNT_MIN; row <= GEN_COMPONENT_COUNT_MAX; row++ ) {
			for ( uint32_t col = GEN_COMPONENT_COUNT_MIN; col <= GEN_COMPONENT_COUNT_MAX; col++ ) {
				std::string typeName = Gen_GetFullTypeName( type, row, col );

				printf( "Generating test_%s.cpp...", typeName.c_str() );

				if ( !gen.Generate( type, row, col ) ) {
					return false;
				}

				printf( "OK.\n" );
			}
		}
	}

	return true;
}

static bool GenerateTestsMain( void ) {
	char filePathMain[1024] = { 0 };
	snprintf( filePathMain, 1024, "%smain.cpp", GEN_TESTS_FOLDER_PATH );

	std::string content = GEN_FILE_HEADER;

	content += "#include <temper/temper.h>\n";
	content += "\n";

	content += "static void OnSuiteEnd( void* userdata )\n";
	content += "{\n";
	content += "\t( (void) userdata );\n";
	content += "\tprintf( \"\\n\" );\n";
	content += "}\n";

	content += "\n";

	for ( uint32_t typeIndex = 0; typeIndex < GEN_TYPE_COUNT; typeIndex++ ) {
		genType_t type = static_cast<genType_t>( typeIndex );

		for ( uint32_t row = 1; row <= GEN_COMPONENT_COUNT_MAX; row++ ) {
			for ( uint32_t col = 1; col <= GEN_COMPONENT_COUNT_MAX; col++ ) {
				std::string fullTypeName = Gen_GetFullTypeName( type, row, col );

				content += "TEMPER_SUITE_EXTERN( Test_" + fullTypeName + " );\n";
			}
			content += "\n";
		}
	}

	content += "TEMPER_DEFS();\n";
	content += "\n";

	content += "int main( int argc, char** argv )\n";
	content += "{\n";
	content += "\tTEMPER_SET_COMMAND_LINE_ARGS( argc, argv );\n";
	content += "\n";

	content += "\tTEMPER_SET_SUITE_END_CALLBACK( OnSuiteEnd, nullptr );\n";
	content += "\n";

	// run the scalar tests first
	// the vector/matrix functions make heavy use of these per-component
	// so if these fail, the problem might be easier to diagnose
	content += "\t// scalar tests\n";
	for ( uint32_t typeIndex = 0; typeIndex < GEN_TYPE_COUNT; typeIndex++ ) {
		genType_t type = static_cast<genType_t>( typeIndex );

		if ( type == GEN_TYPE_BOOL ) {
			continue;
		}

		content += "\tTEMPER_RUN_SUITE( Test_" + Gen_GetMemberTypeString( type ) + " );\n";
	}

	content += "\n";

	// now do vector and matrix types
	content += "\t// vector/matrix tests\n";
	for ( uint32_t typeIndex = 0; typeIndex < GEN_TYPE_COUNT; typeIndex++ ) {
		genType_t type = static_cast<genType_t>( typeIndex );

		for ( uint32_t row = 1; row <= GEN_COMPONENT_COUNT_MAX; row++ ) {
			for ( uint32_t col = GEN_COMPONENT_COUNT_MIN; col <= GEN_COMPONENT_COUNT_MAX; col++ ) {
				std::string fullTypeName = Gen_GetFullTypeName( type, row, col );

				content += "\tTEMPER_RUN_SUITE( Test_" + fullTypeName + " );\n";
			}
			content += "\n";
		}
	}
	content += "\tTEMPER_SHOW_STATS();\n";
	content += "\n";
	content += "\treturn TEMPER_EXIT_CODE();\n";
	content += "}";

	if ( !FS_WriteToFile( filePathMain, content.c_str(), content.size() ) ) {
		return false;
	}

	return true;
}

#define FAIL_IF( x, msg ) \
	do { \
		if ( x ) { \
			printf( "ERROR: " ); \
			printf( msg ); \
			return EXIT_FAILURE; \
		} \
	} while ( 0 )

int main( int argc, char** argv ) {
	UNUSED( argc );
	UNUSED( argv );

	// TODO(DM): handle errors for these
	FS_CreateFolder( GEN_OUT_GEN_FOLDER_PATH );
	FS_CreateFolder( GEN_TESTS_FOLDER_PATH );

	printf( "======= Generating type implementations. =======\n" );
	FAIL_IF( !GenerateImplVectors(),  "Failed generating a vector implementation.\n" );
	FAIL_IF( !GenerateImplMatrices(), "Failed generating a vector implementation.\n" );
	printf( "======= Done. =======\n\n" );

	printf( "======= Generating main headers. =======\n" );
	FAIL_IF( !GenerateMainHeaderFuncs(),      "Failed generating " GEN_FILENAME_FUNCTIONS_SCALAR "!\n" );
	FAIL_IF( !GenerateMainTypeHeaderVector(), "Failed generating main vector header!\n" );
	FAIL_IF( !GenerateMainTypeHeaderMatrix(), "Failed generating main matrix header!\n" );
	printf( "======= Done. =======\n\n" );

	printf( "======= Generating functions. =======\n" );
	FAIL_IF( !GenerateFunctionsVector(), "Failed generating main vector functions header!\n" );
	FAIL_IF( !GenerateFunctionsMatrix(), "Failed generating main matrix functions header!\n" );
	printf( "======= Done. =======\n\n" );

	printf( "======= Generating operators. =======\n" );
	FAIL_IF( !GenerateOperatorsVector(), "Failed generating vector operators header!\n" );
	FAIL_IF( !GenerateOperatorsMatrix(), "Failed generating matrix operators header!\n" );
	printf( "======= Done. =======\n\n" );

	printf( "======= Generating tests. =======\n" );
	FAIL_IF( !GenerateTestsScalar(), "Failed generating scalar tests.\n" );
	FAIL_IF( !GenerateTestsVector(), "Failed generating vector tests.\n" );
	FAIL_IF( !GenerateTestsMatrix(), "Failed generating matrix tests.\n" );
	FAIL_IF( !GenerateTestsMain(),   "Failed generating " GEN_TESTS_FOLDER_PATH "/main.cpp.\n" );
	printf( "======= Done. =======\n\n" );

	printf( "Finished.\n" );

	return 0;
}

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

#include "VectorGenerator.h"
#include "MatrixGenerator.h"
#include "TestsGeneratorVector.h"
#include "TestsGeneratorMatrix.h"

#include "gen_funcs_vector.h"
#include "gen_funcs_matrix.h"

#include "FileIO.h"

#include <stdio.h>
#include <assert.h>

#include <string>

static bool GenerateMainHeaderFuncs( void ) {
	char fileNameHeader[1024];
	sprintf( fileNameHeader, "%s%s.h", GEN_OUT_GEN_FOLDER_PATH, GEN_FILENAME_FUNCTIONS_SCALAR );

	char fileNameInl[1024];
	sprintf( fileNameInl, "%s%s.inl", GEN_OUT_GEN_FOLDER_PATH, GEN_FILENAME_FUNCTIONS_SCALAR );

	std::string contentHeader = GEN_FILE_HEADER;
	contentHeader += "#pragma once\n";
	contentHeader += "\n";
	contentHeader += "#include \"../" + std::string( GEN_HEADER_CONSTANTS ) + "\"\n";
	contentHeader += "\n";
	contentHeader += "#include <math.h>\n";
	contentHeader += "\n";

	std::string contentInl = GEN_FILE_HEADER;

	for ( uint32_t typeIndex = 0; typeIndex < GEN_TYPE_COUNT; typeIndex++ ) {
		genType_t type = static_cast<genType_t>( typeIndex );

		if ( type == GEN_TYPE_BOOL ) {
			continue;
		}

		std::string memberTypeString = Gen_GetMemberTypeString( type );

		printf( "Generating %s...", memberTypeString.c_str() );

		contentHeader += "// " + memberTypeString + "\n";
		contentInl += "// " + memberTypeString + "\n";

		Gen_Floateq( type, contentHeader );
		Gen_Radians( type, contentHeader );
		Gen_Degrees( type, contentHeader );

		Gen_MinMax( type, contentHeader );
		Gen_Clamp( type, contentHeader );
		Gen_Saturate( type, 1, contentHeader, contentInl );
		Gen_Lerp( type, 1, contentHeader, contentInl );

		contentHeader += "\n";
		contentInl += "\n";

		printf( "OK.\n" );
	}

//	contentHeader += "#include \"" + std::string( GEN_FILENAME_FUNCTIONS_SCALAR ) + ".inl\"\n";

	if ( !FS_WriteToFile( fileNameHeader, contentHeader.c_str(), contentHeader.size() ) ) {
		return false;
	}

//	if ( !FS_WriteToFile( fileNameInl, contentInl.c_str(), contentInl.size() ) ) {
//		return false;
//	}

	return true;
}

static void GenerateImplVectors( void ) {
	VectorGenerator gen;

	for ( uint32_t typeIndex = 0; typeIndex < GEN_TYPE_COUNT; typeIndex++ ) {
		genType_t type = static_cast<genType_t>( typeIndex );

		std::string typeString = Gen_GetTypeString( type );

		for ( uint32_t componentIndex = GEN_COMPONENT_COUNT_MIN; componentIndex <= GEN_COMPONENT_COUNT_MAX; componentIndex++ ) {
			printf( "Generating %s%d...", typeString.c_str(), componentIndex );

			gen.Generate( type, componentIndex );

			printf( "OK.\n" );
		}
	}
}

static void GenerateImplMatrices( void ) {
	MatrixGenerator gen;

	for ( uint32_t typeIndex = 0; typeIndex < GEN_TYPE_COUNT; typeIndex++ ) {
		genType_t type = static_cast<genType_t>( typeIndex );

		std::string typeString = Gen_GetTypeString( type );

		for ( uint32_t row = GEN_COMPONENT_COUNT_MIN; row <= GEN_COMPONENT_COUNT_MAX; row++ ) {
			for ( uint32_t col = GEN_COMPONENT_COUNT_MIN; col <= GEN_COMPONENT_COUNT_MAX; col++ ) {
				printf( "Generating %s%dx%d...", typeString.c_str(), row, col );

				gen.Generate( type, row, col );

				printf( "OK.\n" );
			}
		}
	}
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

			Gen_VectorDot( type, componentIndex, contentHeader, contentInl );
			Gen_VectorLength( type, componentIndex, contentHeader, contentInl );
			Gen_VectorNormalize( type, componentIndex, contentHeader, contentInl );
			Gen_VectorCross( type, componentIndex, contentHeader, contentInl );
			Gen_VectorAngle( type, componentIndex, contentHeader, contentInl );

			Gen_Saturate( type, componentIndex, contentHeader, contentInl );
			Gen_Lerp( type, componentIndex, contentHeader, contentInl );

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
//	contentInl += "#include \"../" GEN_FILENAME_FUNCTIONS_SCALAR "\"\n";
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

static void GenerateTestsVector( void ) {
	TestsGeneratorVector gen;

	for ( uint32_t typeIndex = 0; typeIndex < GEN_TYPE_COUNT; typeIndex++ ) {
		genType_t type = static_cast<genType_t>( typeIndex );

		std::string typeString = Gen_GetTypeString( type );

		for ( uint32_t componentIndex = GEN_COMPONENT_COUNT_MIN; componentIndex <= GEN_COMPONENT_COUNT_MAX; componentIndex++ ) {
			std::string typeName = typeString + std::to_string( componentIndex );

			printf( "Generating test_%s.cpp...", typeName.c_str() );

			gen.Generate( type, componentIndex );

			printf( "OK.\n" );
		}
	}
}

static void GenerateTestsMatrix( void ) {
	TestsGeneratorMatrix gen;

	for ( uint32_t typeIndex = 0; typeIndex < GEN_TYPE_COUNT; typeIndex++ ) {
		genType_t type = static_cast<genType_t>( typeIndex );

		for ( uint32_t row = GEN_COMPONENT_COUNT_MIN; row <= GEN_COMPONENT_COUNT_MAX; row++ ) {
			for ( uint32_t col = GEN_COMPONENT_COUNT_MIN; col <= GEN_COMPONENT_COUNT_MAX; col++ ) {
				std::string typeName = Gen_GetFullTypeName( type, row, col );

				printf( "Generating test_%s.cpp...", typeName.c_str() );

				gen.Generate( type, row, col );

				printf( "OK.\n" );
			}
		}
	}
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
			for ( uint32_t col = GEN_COMPONENT_COUNT_MIN; col <= GEN_COMPONENT_COUNT_MAX; col++ ) {
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

int main( int argc, char** argv ) {
	UNUSED( argc );
	UNUSED( argv );

	FS_CreateFolder( GEN_OUT_GEN_FOLDER_PATH );
	FS_CreateFolder( GEN_TESTS_FOLDER_PATH );

	printf( "======= Generating type implementations. =======\n" );
	GenerateImplVectors();
	GenerateImplMatrices();
	printf( "======= Done. =======\n\n" );

	printf( "======= Generating tests. =======\n" );
	GenerateTestsVector();
	GenerateTestsMatrix();
	printf( "======= Done. =======\n\n" );

	// TODO(DM): tidy this somehow?
	printf( "======= Generating main headers. =======\n" );
	if ( !GenerateMainHeaderFuncs() ) {
		printf( "ERROR: Failed generating %s!\n", GEN_FILENAME_FUNCTIONS_SCALAR );
		return EXIT_FAILURE;
	}

	if ( !GenerateMainTypeHeaderVector() ) {
		printf( "ERROR: Failed generating main vector header!\n" );
		return EXIT_FAILURE;
	}

	if ( !GenerateMainTypeHeaderMatrix() ) {
		printf( "ERROR: Failed generating main matrix header!\n" );
		return EXIT_FAILURE;
	}
	printf( "======= Done. =======\n\n" );

	printf( "======= Generating vector functions. =======\n" );
	if ( !GenerateFunctionsVector() ) {
		printf( "ERROR: Failed generating main vector functions header!\n" );
		return EXIT_FAILURE;
	}
	printf( "======= Done. =======\n\n" );

	printf( "======= Generating vectors operators. =======\n" );
	if ( !GenerateOperatorsVector() ) {
		printf( "ERROR: Failed generating vector operators header!\n" );
		return EXIT_FAILURE;
	}
	printf( "======= Done. =======\n\n" );

	printf( "======= Generating matrix operators. =======\n" );
	if ( !GenerateOperatorsMatrix() ) {
		printf( "ERROR: Failed generating matrix operators header!\n" );
		return EXIT_FAILURE;
	}
	printf( "======= Done. =======\n\n" );

	printf( "======= Generating matrix functions. =======\n" );
	if ( !GenerateFunctionsMatrix() ) {
		printf( "ERROR: Failed generating main matrix functions header!\n" );
		return EXIT_FAILURE;
	}
	printf( "======= Done. =======\n\n" );

	printf( "======= Generating tests. =======\n" );
	if ( !GenerateTestsMain() ) {
		printf( "ERROR: Failed generating %s/main.cpp.\n", GEN_TESTS_FOLDER_PATH );
		return EXIT_FAILURE;
	}
	printf( "======= Done. =======\n\n" );

	printf( "Finished.\n" );

	return 0;
}

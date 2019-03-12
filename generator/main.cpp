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

genHand_t g_hand = GEN_HAND_COUNT;

// TODO(DM): tidy me
static const char* GetNextArg( const int currentArg, const int argc, char** argv ) {
	return ( currentArg + 1 < argc ) ? argv[currentArg + 1] : nullptr;
}

static bool ProcessArgs( const int argc, char** argv ) {
	bool foundArg = true;

	for ( int i = 0; i < argc; i++ ) {
		const char* arg = argv[i];

		if ( arg[0] == '-' ) {
			switch ( arg[1] ) {
				case 'h': {
					const char* value = GetNextArg( i, argc, argv );
					if ( !value ) {
						return false;
					}

					if ( strcmp( value, "left" ) == 0 ) {
						g_hand = GEN_HAND_LEFT;
						i++;
					} else if ( strcmp( value, "right" ) == 0 ) {
						g_hand = GEN_HAND_RIGHT;
						i++;
					} else {
						return false;
					}
					break;
				}

				default:
					foundArg = false;
					break;
			}
		}
	}

	return foundArg;
}

static void ShowUsage( void ) {
	printf(
		"HLML Code :\n"
		"Usage:\n"
		"	-h <hand>: Which 'handedness' you want to generate maths functions like \"ortho\" for.  Options: left, right.  Must be set.\n"
	);
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

		std::string typeString = Gen_GetTypeString( type );

		for ( uint32_t componentIndex = GEN_COMPONENT_COUNT_MIN; componentIndex <= GEN_COMPONENT_COUNT_MAX; componentIndex++ ) {
			content += "#include \"" + typeString + std::to_string( componentIndex ) + ".h\"\n";
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

		std::string typeString = Gen_GetTypeString( type );

		for ( uint32_t row = GEN_COMPONENT_COUNT_MIN; row <= GEN_COMPONENT_COUNT_MAX; row++ ) {
			const std::string rowStr = std::to_string( row );

			for ( uint32_t col = GEN_COMPONENT_COUNT_MIN; col <= GEN_COMPONENT_COUNT_MAX; col++ ) {
				const std::string colStr = std::to_string( col );

				content += "#include \"" + typeString + rowStr + "x" + colStr + ".h\"\n";
			}
			content += "\n";
		}
	}

	content += "#include \"hlml_functions_matrix.h\"\n";

	return FS_WriteToFile( headerFilePath, content.c_str(), content.size() );
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

	for ( uint32_t typeIndex = 0; typeIndex < GEN_TYPE_COUNT; typeIndex++ ) {
		genType_t type = static_cast<genType_t>( typeIndex );

		if ( type == GEN_TYPE_BOOL ) {
			continue;
		}

		std::string typeString = Gen_GetTypeString( type );

		for ( uint32_t componentIndex = GEN_COMPONENT_COUNT_MIN; componentIndex <= GEN_COMPONENT_COUNT_MAX; componentIndex++ ) {
			contentHeader += "#include \"" + typeString + std::to_string( componentIndex ) + ".h\"\n";
		}
	}

	contentHeader += "\n";
	contentInl += "\n";

	for ( uint32_t typeIndex = 0; typeIndex < GEN_TYPE_COUNT; typeIndex++ ) {
		genType_t type = static_cast<genType_t>( typeIndex );

		if ( type == GEN_TYPE_BOOL ) {
			continue;
		}

		std::string typeString = Gen_GetTypeString( type );

		for ( uint32_t componentIndex = GEN_COMPONENT_COUNT_MIN; componentIndex <= GEN_COMPONENT_COUNT_MAX; componentIndex++ ) {
			std::string fullTypeName = typeString + std::to_string( componentIndex );

			printf( "Algebra %s...\n", fullTypeName.c_str() );

			contentHeader += "// " + fullTypeName + "\n";
			contentInl += "// " + fullTypeName + "\n";

			Gen_VectorDot( type, componentIndex, contentHeader, contentInl );
			Gen_VectorLength( type, componentIndex, contentHeader, contentInl );
			Gen_VectorNormalize( type, componentIndex, contentHeader, contentInl );
			Gen_VectorCross( type, componentIndex, contentHeader, contentInl );
			Gen_VectorAngle( type, componentIndex, contentHeader, contentInl );

			Gen_VectorSaturate( type, componentIndex, contentHeader, contentInl );

			contentHeader += "\n";
			contentInl += "\n";
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

		std::string typeString = Gen_GetTypeString( type );

		for ( uint32_t row = GEN_COMPONENT_COUNT_MIN; row <= GEN_COMPONENT_COUNT_MAX; row++ ) {
			std::string rowStr = std::to_string( row );

			for ( uint32_t col = GEN_COMPONENT_COUNT_MIN; col <= GEN_COMPONENT_COUNT_MAX; col++ ) {
				std::string colStr = std::to_string( col );

				std::string fullTypeName = typeString + rowStr + "x" + colStr;

				printf( "Matrix operators %s...\n", fullTypeName.c_str() );

				contentHeader += "// " + fullTypeName + "\n";
				contentInl += "// " + fullTypeName + "\n";

				Gen_MatrixOperatorsArithmetic( type, row, col, contentHeader, contentInl );
				Gen_MatrixOperatorsRelational( type, row, col, contentHeader, contentInl );

				contentHeader += "\n";
				contentInl += "\n";
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

			for ( uint32_t col = 1; col <= GEN_COMPONENT_COUNT_MAX; col++ ) {
				const std::string colStr = std::to_string( col );

				// TODO(DM): only include the header files we actually need
				if ( col == 1 ) {
					contentHeader += "#include \"" + typeString + rowStr + ".h\"\n";
				} else {
					contentHeader += "#include \"" + typeString + rowStr + "x" + colStr + ".h\"\n";
				}
			}
		}
	}

	contentHeader += "\n";
	contentInl += "\n";

	for ( uint32_t typeIndex = 0; typeIndex < GEN_TYPE_COUNT; typeIndex++ ) {
		genType_t type = static_cast<genType_t>( typeIndex );

		std::string typeString = Gen_GetTypeString( type );

		for ( uint32_t row = GEN_COMPONENT_COUNT_MIN; row <= GEN_COMPONENT_COUNT_MAX; row++ ) {
			std::string rowStr = std::to_string( row );

			for ( uint32_t col = GEN_COMPONENT_COUNT_MIN; col <= GEN_COMPONENT_COUNT_MAX; col++ ) {
				std::string colStr = std::to_string( col );

				std::string fullTypeName = typeString + rowStr + "x" + colStr;

				printf( "Basic functions %s...\n", fullTypeName.c_str() );

				contentHeader += "// " + fullTypeName + "\n";
				contentInl += "// " + fullTypeName + "\n";

				Gen_MatrixIdentity( type, row, col, contentHeader, contentInl );
				Gen_MatrixTranspose( type, row, col, contentHeader, contentInl );

				Gen_MatrixInverse( type, row, col, contentHeader, contentInl );
				Gen_MatrixDeterminant( type, row, col, contentHeader, contentInl );

				Gen_MatrixTranslate( type, row, col, contentHeader, contentInl );
				Gen_MatrixRotate( type, row, col, contentHeader, contentInl );
				Gen_MatrixScale( type, row, col, contentHeader, contentInl );

				Gen_MatrixOrtho( g_hand, type, row, col, contentHeader, contentInl );
				Gen_MatrixPerspective( g_hand, type, row, col, contentHeader, contentInl );
				Gen_MatrixLookAt( g_hand, type, row, col, contentHeader, contentInl );

				contentHeader += "\n";
				contentInl += "\n";
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

		std::string typeString = Gen_GetTypeString( type );

		for ( uint32_t row = GEN_COMPONENT_COUNT_MIN; row <= GEN_COMPONENT_COUNT_MAX; row++ ) {
			std::string rowStr = std::to_string( row );

			for ( uint32_t col = GEN_COMPONENT_COUNT_MIN; col <= GEN_COMPONENT_COUNT_MAX; col++ ) {
				std::string colStr = std::to_string( col );

				std::string typeName = typeString + rowStr + "x" + colStr;

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

	content += "#include <temper.h>\n";
	content += "\n";

	content += "static void OnSuiteEnd( void* userdata ) {\n";
	content += "\t( (void) userdata );\n";
	content += "\tprintf( \"\\n\" );\n";
	content += "}\n";

	content += "\n";

	for ( uint32_t typeIndex = 0; typeIndex < GEN_TYPE_COUNT; typeIndex++ ) {
		genType_t type = static_cast<genType_t>( typeIndex );

		std::string typeString = Gen_GetTypeString( type );

		for ( uint32_t col = GEN_COMPONENT_COUNT_MIN; col <= GEN_COMPONENT_COUNT_MAX; col++ ) {
			std::string colStr = std::to_string( col );

			for ( uint32_t row = 1; row <= GEN_COMPONENT_COUNT_MAX; row++ ) {
				std::string rowStr = std::to_string( row );

				std::string fullTypeName = typeString;
				if ( row > 1 ) {
					fullTypeName += rowStr + "x";
				}
				fullTypeName += colStr;

				content += "TEMPER_SUITE_EXTERN( Test_" + fullTypeName + " );\n";
			}
			content += "\n";
		}
	}

	content += "TEMPER_DEFS();\n";
	content += "\n";

	content += "int main( int argc, char** argv ) {\n";
	content += "\tTEMPER_SET_COMMAND_LINE_ARGS( argc, argv );\n";
	content += "\n";

	content += "\tTEMPER_SET_SUITE_END_CALLBACK( OnSuiteEnd, nullptr );\n";
	content += "\n";

	for ( uint32_t typeIndex = 0; typeIndex < GEN_TYPE_COUNT; typeIndex++ ) {
		genType_t type = static_cast<genType_t>( typeIndex );

		std::string typeString = Gen_GetTypeString( type );

		for ( uint32_t col = GEN_COMPONENT_COUNT_MIN; col <= GEN_COMPONENT_COUNT_MAX; col++ ) {
			std::string colStr = std::to_string( col );

			for ( uint32_t row = 1; row <= GEN_COMPONENT_COUNT_MAX; row++ ) {
				std::string rowStr = std::to_string( row );

				std::string fullTypeName = typeString;
				if ( row > 1 ) {
					fullTypeName += rowStr + "x";
				}
				fullTypeName += colStr;

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
	if ( !ProcessArgs( argc, argv ) ) {
		ShowUsage();
		return 0;
	}

	printf( "Generating %s hand linear algebra functions.\n", ( g_hand == GEN_HAND_LEFT ) ? "left" : "right" );
	printf( "\n" );

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

	// TODO(DM): tidy this
	printf( "======= Generating main headers. =======\n" );
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

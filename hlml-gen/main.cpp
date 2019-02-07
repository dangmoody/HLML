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

#include "FileIO.h"

#include <stdio.h>
#include <assert.h>

#include <string>

hand_t g_hand = GEN_HAND_COUNT;

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

						foundArg = true;
						i++;
					} else if ( strcmp( value, "right" ) == 0 ) {
						g_hand = GEN_HAND_RIGHT;

						foundArg = true;
						i++;
					} else {
						return false;
					}
					break;
				}
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

static bool GenerateMainTypeHeaderVector( void ) {
	char headerFilePath[1024] = { 0 };
	sprintf( headerFilePath, "%s%s", GEN_OUT_FOLDER_PATH, GEN_HEADER_VECTOR );

	// TODO(DM): cache this as "GEN_FILE_HEADER" constant
	std::string content = GEN_COPYRIGHT_HEADER;
	content += "\n";
	content += GEN_GENERATED_WARNING;
	content += "\n";

	for ( uint32_t typeIndex = 0; typeIndex < GEN_TYPE_COUNT; typeIndex++ ) {
		for ( uint32_t componentIndex = GEN_COMPONENT_COUNT_MIN; componentIndex <= GEN_COMPONENT_COUNT_MAX; componentIndex++ ) {
			genType_t type = static_cast<genType_t>( typeIndex );

			content += "#include \"" + Gen_GetTypeString( type ) + std::to_string( componentIndex ) + ".h\"\n";
		}
		content += "\n";
	}

	content += "#include \"hlml_functions_vector.h\"\n";

	return FS_WriteToFile( headerFilePath, content.c_str(), content.size() );
}

static bool GenerateMainTypeHeaderMatrix( void ) {
	char headerFilePath[1024] = { 0 };
	sprintf( headerFilePath, "%s%s", GEN_OUT_FOLDER_PATH, GEN_HEADER_MATRIX );

	// TODO(DM): cache this as "GEN_FILE_HEADER" constant
	std::string content = GEN_COPYRIGHT_HEADER;
	content += "\n";
	content += GEN_GENERATED_WARNING;
	content += "\n";

	for ( uint32_t typeIndex = 0; typeIndex < GEN_TYPE_COUNT; typeIndex++ ) {
		for ( uint32_t col = GEN_COMPONENT_COUNT_MIN; col <= GEN_COMPONENT_COUNT_MAX; col++ ) {
			const std::string colStr = std::to_string( col );

			for ( uint32_t row = GEN_COMPONENT_COUNT_MIN; row <= GEN_COMPONENT_COUNT_MAX; row++ ) {
				const std::string rowStr = std::to_string( row );

				genType_t type = static_cast<genType_t>( typeIndex );

				content += "#include \"" + Gen_GetTypeString( type ) + rowStr + "x" + colStr + ".h\"\n";
			}
			content += "\n";
		}
	}

	content += "#include \"hlml_functions_matrix.h\"\n";

	return FS_WriteToFile( headerFilePath, content.c_str(), content.size() );
}

static bool GenerateFunctionsVector( void ) {
	char filePathHeader[1024] = { 0 };
	sprintf( filePathHeader, "%s%s.h", GEN_OUT_FOLDER_PATH, GEN_HEADER_FUNCTIONS_VECTOR );

	char filePathInl[1024] = { 0 };
	sprintf( filePathInl, "%s%s.inl", GEN_OUT_FOLDER_PATH, GEN_HEADER_FUNCTIONS_VECTOR );

	std::string content = GEN_COPYRIGHT_HEADER;
	content += "\n";
	content += GEN_GENERATED_WARNING;
	content += "\n";

	std::string contentHeader = content;
	std::string contentInl = content;

	for ( uint32_t typeIndex = 0; typeIndex < GEN_TYPE_COUNT; typeIndex++ ) {
		for ( uint32_t componentIndex = GEN_COMPONENT_COUNT_MIN; componentIndex <= GEN_COMPONENT_COUNT_MAX; componentIndex++ ) {
			genType_t type = static_cast<genType_t>( typeIndex );

			if ( type == GEN_TYPE_BOOL ) {
				continue;
			}

			contentHeader += "#include \"" + Gen_GetTypeString( type ) + std::to_string( componentIndex ) + ".h\"\n";
		}
	}

	contentHeader += "\n";
	contentInl += "\n";

	for ( uint32_t typeIndex = 0; typeIndex < GEN_TYPE_COUNT; typeIndex++ ) {
		for ( uint32_t componentIndex = GEN_COMPONENT_COUNT_MIN; componentIndex <= GEN_COMPONENT_COUNT_MAX; componentIndex++ ) {
			genType_t type = static_cast<genType_t>( typeIndex );

			if ( type == GEN_TYPE_BOOL ) {
				continue;
			}

			std::string fullTypeName = Gen_GetTypeString( type ) + std::to_string( componentIndex );

			printf( "Algebra %s...\n", fullTypeName.c_str() );

			contentHeader += "// " + fullTypeName + "\n";
			contentInl += "// " + fullTypeName + "\n";

			Gen_VectorDot( type, componentIndex, contentHeader, contentInl );
			Gen_VectorLength( type, componentIndex, contentHeader, contentInl );
			Gen_VectorNormalize( type, componentIndex, contentHeader, contentInl );
			Gen_VectorCross( type, componentIndex, contentHeader, contentInl );
//			Gen_VectorAngle( type, componentIndex, contentHeader, contentInl );

			contentHeader += "\n";
			contentInl += "\n";
		}
	}

	contentHeader += "#include \"" + std::string( GEN_HEADER_FUNCTIONS_VECTOR ) + ".inl\"";

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
	sprintf( filePathHeader, "%s%s.h", GEN_OUT_FOLDER_PATH, GEN_HEADER_FUNCTIONS_MATRIX );

	char filePathInl[1024] = { 0 };
	sprintf( filePathInl, "%s%s.inl", GEN_OUT_FOLDER_PATH, GEN_HEADER_FUNCTIONS_MATRIX );

	std::string content = GEN_COPYRIGHT_HEADER;
	content += "\n";
	content += GEN_GENERATED_WARNING;
	content += "\n";

	std::string contentHeader = content;
	std::string contentInl = content;

	for ( uint32_t typeIndex = 0; typeIndex < GEN_TYPE_COUNT; typeIndex++ ) {
		for ( uint32_t col = 1; col <= GEN_COMPONENT_COUNT_MAX; col++ ) {
			const std::string colStr = std::to_string( col );

			for ( uint32_t row = GEN_COMPONENT_COUNT_MIN; row <= GEN_COMPONENT_COUNT_MAX; row++ ) {
				const std::string rowStr = std::to_string( row );

				genType_t type = static_cast<genType_t>( typeIndex );

				// TODO(DM): only include the header files we actually need
				if ( col == 1 ) {
					contentHeader += "#include \"" + Gen_GetTypeString( type ) + rowStr + ".h\"\n";
				} else {
					contentHeader += "#include \"" + Gen_GetTypeString( type ) + rowStr + "x" + colStr + ".h\"\n";
				}
			}
		}
	}

	contentHeader += "\n";
	contentInl += "\n";

	for ( uint32_t typeIndex = 0; typeIndex < GEN_TYPE_COUNT; typeIndex++ ) {
		for ( uint32_t col = GEN_COMPONENT_COUNT_MIN; col <= GEN_COMPONENT_COUNT_MAX; col++ ) {
			std::string colStr = std::to_string( col );

			for ( uint32_t row = GEN_COMPONENT_COUNT_MIN; row <= GEN_COMPONENT_COUNT_MAX; row++ ) {
				std::string rowStr = std::to_string( row );

				genType_t type = static_cast<genType_t>( typeIndex );

				std::string fullTypeName = Gen_GetTypeString( type ) + rowStr + "x" + colStr;

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

	contentHeader += "#include \"" + std::string( GEN_HEADER_FUNCTIONS_MATRIX ) + ".inl\"";

	if ( !FS_WriteToFile( filePathHeader, contentHeader.c_str(), contentHeader.size() ) ) {
		return false;
	}

	if ( !FS_WriteToFile( filePathInl, contentInl.c_str(), contentInl.size() ) ) {
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

	FS_CreateFolder( GEN_OUT_FOLDER_PATH );

	genFlags_t genFlags;

	// generate vectors
	{
		printf( "======= Generating vector types. =======\n" );

		genFlags = GEN_FLAGS_BIT_EQUALITY | GEN_FLAGS_BIT_ARRAY;

		VectorGenerator gen;

		for ( uint32_t typeIndex = 0; typeIndex < GEN_TYPE_COUNT; typeIndex++ ) {
			for ( uint32_t componentIndex = GEN_COMPONENT_COUNT_MIN; componentIndex <= GEN_COMPONENT_COUNT_MAX; componentIndex++ ) {
				genType_t type = static_cast<genType_t>( typeIndex );

				printf( "Generating %s%d...", Gen_GetTypeString( type ).c_str(), componentIndex );

				// DM: is this a hack?
				if ( type != GEN_TYPE_BOOL ) {
					genFlags |= GEN_FLAGS_BIT_COLOR | GEN_FLAGS_BIT_ARITHMETIC | GEN_FLAGS_BIT_RELATIONAL;
				}

				gen.Generate( type, componentIndex, genFlags );
//				gen.PrintHeader();
//				gen.PrintInl();

				printf( "OK.\n" );
			}
		}

		printf( "======= Done. =======\n" );
	}

	printf( "\n" );

	// generate matrices
	{
		printf( "======= Generating matrix types. =======\n" );

		genFlags = GEN_FLAGS_BIT_EQUALITY | GEN_FLAGS_BIT_ARRAY;

		MatrixGenerator gen;

		for ( uint32_t typeIndex = 0; typeIndex < GEN_TYPE_COUNT; typeIndex++ ) {
			for ( uint32_t col = GEN_COMPONENT_COUNT_MIN; col <= GEN_COMPONENT_COUNT_MAX; col++ ) {
				for ( uint32_t row = GEN_COMPONENT_COUNT_MIN; row <= GEN_COMPONENT_COUNT_MAX; row++ ) {
					genType_t type = static_cast<genType_t>( typeIndex );

					printf( "Generating %s%dx%d...", Gen_GetTypeString( type ).c_str(), row, col );

					// DM: is this a hack?
					if ( type != GEN_TYPE_BOOL ) {
						genFlags |= GEN_FLAGS_BIT_ARITHMETIC;
					}

					gen.Generate( type, row, col, genFlags );
//					gen.PrintHeader();
//					gen.PrintInl();

					printf( "OK.\n" );
				}
			}
		}

		printf( "======= Done. =======\n" );
	}

	printf( "\n" );

	printf( "======= Generating main headers. =======\n" );
	GenerateMainTypeHeaderVector();
	GenerateMainTypeHeaderMatrix();
	printf( "======= Done. =======\n\n" );

	printf( "======= Generating vector functions. =======\n" );
	GenerateFunctionsVector();
	printf( "======= Done. =======\n\n" );

	printf( "======= Generating matrix functions. =======\n" );
	GenerateFunctionsMatrix();
	printf( "======= Done. =======\n" );

	printf( "\nFinished.\n" );

	return 0;
}

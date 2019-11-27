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
#include "gen_vector_cpp.h"

#include "defines.h"

#include "gen_common.h"
#include "gen_doc_common.h"

#include "string_builder.h"
#include "allocator.h"
#include "file_io.h"

#include <math.h>

static void GenerateDocStruct( stringBuilder_t* codeHeader, const u32 numComponents, const char* memberTypeString ) {
	assert( codeHeader );
	assert( numComponents >= GEN_COMPONENT_COUNT_MIN );
	assert( numComponents <= GEN_COMPONENT_COUNT_MAX );
	assert( memberTypeString );

	char componentsStr[GEN_COMPONENT_COUNT_MAX + 1];
	strncpy( componentsStr, GEN_COMPONENT_NAMES_VECTOR, numComponents );
	componentsStr[numComponents] = 0;

	String_Appendf( codeHeader,
		"/// \\brief A vector of %d %ss with components %s.\n" \
		"/// Components are also stored as elements in an array via a union.\n", numComponents, memberTypeString, componentsStr );
}

static void GenerateDocCtorDefault( stringBuilder_t* codeHeader ) {
	assert( codeHeader );

	String_Append( codeHeader, "\t/// Default constructor.  Initializes all values to zero.\n" );
}

static void GenerateDocCtorScalar( stringBuilder_t* codeHeader ) {
	assert( codeHeader );

	String_Append( codeHeader, "\t/// Initializes all components of the vector to the given scalar value.\n" );
}

static void GenerateDocCtorMemberwise( stringBuilder_t* codeHeader, const u32 numComponents ) {
	assert( codeHeader );
	assert( numComponents >= GEN_COMPONENT_COUNT_MIN );
	assert( numComponents <= GEN_COMPONENT_COUNT_MAX );

	char componentsStr[GEN_COMPONENT_COUNT_MAX + 1];
	strncpy( componentsStr, GEN_COMPONENT_NAMES_VECTOR, numComponents );
	componentsStr[numComponents] = 0;

	String_Appendf( codeHeader, "\t/// Sets the %s members of the vector to the corresponding parameters.\n", componentsStr );
}

static void GenerateDocCtorCopy( stringBuilder_t* codeHeader ) {
	assert( codeHeader );

	String_Append( codeHeader, "\t/// Copy constructor.  Copies the elements of the given vector via memcpy.\n" );
}

static void GenerateDocOperatorAssignment( stringBuilder_t* codeHeader ) {
	assert( codeHeader );

	String_Append( codeHeader, "\t/// Copies the elements of the given vector via a single memcpy.\n" );
}

static void GenerateDocOperatorArray( stringBuilder_t* codeHeader, const u32 numComponents ) {
	assert( codeHeader );
	assert( numComponents >= GEN_COMPONENT_COUNT_MIN );
	assert( numComponents <= GEN_COMPONENT_COUNT_MAX );

	String_Appendf( codeHeader,
		"\t/// \\brief Returns the vector component at the given index.\n" \
		"\t/// Index CANNOT be lower than 0 or higher than %d.\n", numComponents - 1 );
}

static void GenerateConstructors( stringBuilder_t* codeHeader, stringBuilder_t* codeInl, const genType_t type, const u32 numComponents, const char* fullTypeName, const char* memberTypeString, const char* typeString ) {
	assert( codeHeader );
	assert( codeInl );
	assert( numComponents >= GEN_COMPONENT_COUNT_MIN );
	assert( numComponents <= GEN_COMPONENT_COUNT_MAX );
	assert( fullTypeName );
	assert( memberTypeString );
	assert( typeString );

	// default ctor
	{
		const char* defaultValueStr = Gen_GetDefaultLiteralValue( type );

		GenerateDocCtorDefault( codeHeader );
		String_Appendf( codeHeader, "\tinline %s();\n", fullTypeName );
		String_Append(  codeHeader, "\n" );

		String_Appendf( codeInl, "%s::%s()\n", fullTypeName, fullTypeName );
		String_Append(  codeInl, "{\n" );
		for ( u32 i = 0; i < numComponents; i++ ) {
			String_Appendf( codeInl, "\t%c = %s;\n", GEN_COMPONENT_NAMES_VECTOR[i], defaultValueStr );
		}
		String_Append(  codeInl, "}\n" );
		String_Append(  codeInl, "\n" );
	}

	// single scalar ctor
	{
		GenerateDocCtorScalar( codeHeader );
		String_Appendf( codeHeader, "\tinline explicit %s( const %s x );\n", fullTypeName, memberTypeString );
		String_Append(  codeHeader, "\n" );

		String_Appendf( codeInl, "%s::%s( const %s x )\n", fullTypeName, fullTypeName, memberTypeString );
		String_Append(  codeInl, "{\n" );
		String_Append(  codeInl, "\t" );
		for ( u32 i = 0; i < numComponents; i++ ) {
			String_Appendf( codeInl, "this->%c = ", GEN_COMPONENT_NAMES_VECTOR[i] );
		}
		String_Append( codeInl, "x;\n" );
		String_Append( codeInl, "}\n" );
		String_Append( codeInl, "\n" );
	}

	// member-wise ctor
	{
		GenerateDocCtorMemberwise( codeHeader, numComponents );
		String_Appendf( codeHeader, "\tinline %s( ", fullTypeName );
		for ( u32 i = 0; i < numComponents; i++ ) {
			String_Appendf( codeHeader, "const %s %c", memberTypeString, GEN_COMPONENT_NAMES_VECTOR[i] );

			if ( i != numComponents - 1 ) {
				String_Append( codeHeader, ", " );
			}
		}
		String_Append( codeHeader, " );\n" );
		String_Append( codeHeader, "\n" );

		String_Appendf( codeInl, "%s::%s( ", fullTypeName, fullTypeName );
		for ( u32 i = 0; i < numComponents; i++ ) {
			String_Appendf( codeInl, "const %s %c", memberTypeString, GEN_COMPONENT_NAMES_VECTOR[i] );

			if ( i != numComponents - 1 ) {
				String_Append( codeInl, ", " );
			}
		}
		String_Append( codeInl, " )\n" );
		String_Append( codeInl, "{\n" );
		for ( u32 i = 0; i < numComponents; i++ ) {
			const char componentName = GEN_COMPONENT_NAMES_VECTOR[i];

			String_Append(  codeInl, "\t" );
			String_Appendf( codeInl, "this->%c = %c", componentName, componentName );
			String_Append(  codeInl, ";\n" );
		}
		String_Append( codeInl, "}\n" );
		String_Append( codeInl, "\n" );
	}

	// copy ctors for all valid vector types
	{
		for ( u32 i = GEN_COMPONENT_COUNT_MIN; i <= GEN_COMPONENT_COUNT_MAX; i++ ) {
			GenerateDocCtorCopy( codeHeader );
			String_Appendf( codeHeader, "\tinline %s( const %s%d& other );\n", fullTypeName, typeString, i );
			String_Append(  codeHeader, "\n" );

			String_Appendf( codeInl, "%s::%s( const %s%d& other )\n", fullTypeName, fullTypeName, typeString, i );
			String_Append(  codeInl, "{\n" );
			String_Append(  codeInl, "\tmemcpy( data, other.data, sizeof( other.data ) );\n" );
			String_Append(  codeInl, "}\n" );
			String_Append(  codeInl, "\n" );
		}
	}

	// dtor
	String_Appendf( codeHeader, "\t~%s() {}\n", fullTypeName );
	String_Append( codeHeader, "\n" );
}

static void GenerateOperatorsAssignment( stringBuilder_t* codeHeader, stringBuilder_t* codeInl, const char* fullTypeName, const char* typeString ) {
	assert( codeHeader );
	assert( codeInl );
	assert( fullTypeName );
	assert( typeString );

	for ( u32 i = GEN_COMPONENT_COUNT_MIN; i <= GEN_COMPONENT_COUNT_MAX; i++ ) {
		GenerateDocOperatorAssignment( codeHeader );
		String_Appendf( codeHeader, "\tinline %s operator=( const %s%d& rhs );\n", fullTypeName, typeString, i );
		String_Append(  codeHeader, "\n" );

		String_Appendf( codeInl, "%s %s::operator=( const %s%d& rhs )\n", fullTypeName, fullTypeName, typeString, i );
		String_Append(  codeInl, "{\n" );
		String_Append(  codeInl, "\tmemcpy( data, rhs.data, sizeof( rhs.data ) );\n" );
		String_Append(  codeInl, "\treturn *this;\n" );
		String_Append(  codeInl, "}\n" );
		String_Append(  codeInl, "\n" );
	}
}

static void GenerateOperatorsArray( stringBuilder_t* codeHeader, stringBuilder_t* codeInl, const u32 numComponents, const char* memberTypeString, const char* fullTypeName ) {
	assert( codeHeader );
	assert( codeInl );
	assert( numComponents >= GEN_COMPONENT_COUNT_MIN );
	assert( numComponents <= GEN_COMPONENT_COUNT_MAX );
	assert( memberTypeString );
	assert( fullTypeName );

	GenerateDocOperatorArray( codeHeader, numComponents );
	String_Appendf( codeHeader, "\tinline const %s& operator[]( const uint32_t index ) const;\n", memberTypeString );
	String_Append(  codeHeader, "\n" );

	String_Appendf( codeInl, "const %s& %s::operator[]( const uint32_t index ) const\n", memberTypeString, fullTypeName );
	String_Append(  codeInl, "{\n" );
	String_Appendf( codeInl, "\tassert( index < %d );\n", numComponents );
	String_Append(  codeInl, "\treturn data[index];\n" );
	String_Append(  codeInl, "}\n" );
	String_Append(  codeInl, "\n" );

	GenerateDocOperatorArray( codeHeader, numComponents );
	String_Appendf( codeHeader, "\tinline %s& operator[]( const uint32_t index );\n", memberTypeString );
	String_Append(  codeHeader, "\n" );

	String_Appendf( codeInl, "%s& %s::operator[]( const uint32_t index )\n", memberTypeString, fullTypeName );
	String_Append(  codeInl, "{\n" );
	String_Appendf( codeInl, "\tassert( index < %d );\n", numComponents );
	String_Append(  codeInl, "\treturn data[index];\n" );
	String_Append(  codeInl, "}\n" );
	String_Append(  codeInl, "\n" );
}

static void GenerateSwizzleFuncs( stringBuilder_t* codeHeader, stringBuilder_t* codeInl, const u32 numComponents, const char* typeString, const char* fullTypeName ) {
	assert( codeHeader );
	assert( codeInl );
	assert( numComponents >= GEN_COMPONENT_COUNT_MIN );
	assert( numComponents <= GEN_COMPONENT_COUNT_MAX );
	assert( typeString );
	assert( fullTypeName );

	String_Append( codeHeader, "\t// swizzle funcs\n" );

	char funcName[GEN_COMPONENT_COUNT_MAX + 1];
	memset( funcName, 0, sizeof( funcName ) );

	// for every vector type compatible with this one (that is: for each vector type with less components than this one)
	for ( u32 vecComponents = GEN_COMPONENT_COUNT_MIN; vecComponents <= numComponents; vecComponents++ ) {
		// generate every possible function combination ("xxxx" -> "xwzx" (etc.) -> "wwww")
		u32 numFuncs = (u32) pow( vecComponents, vecComponents );
		for ( u32 funcIndex = 0; funcIndex < numFuncs; funcIndex++ ) {
			// convert 1d index into 4d
			// follows the general formula: xn = ( ( Index - Index( x1, ..., x{n-1} ) ) / Product( D1, ..., D{N-1} ) ) % Dn
			// taken from: https://stackoverflow.com/questions/29142417/4d-position-from-1d-index
			const u32 x = funcIndex % vecComponents;
			const u32 y = ( ( funcIndex - x ) / vecComponents ) % vecComponents;
			const u32 z = ( ( funcIndex - y * vecComponents - x ) / ( vecComponents * vecComponents ) ) % vecComponents;
			const u32 w = ( ( funcIndex - z * vecComponents * vecComponents - x ) / ( vecComponents * vecComponents * vecComponents ) ) % vecComponents;

			snprintf( funcName, GEN_COMPONENT_COUNT_MAX + 1, "%c%c%c%c",
				GEN_COMPONENT_NAMES_VECTOR[x], GEN_COMPONENT_NAMES_VECTOR[y], GEN_COMPONENT_NAMES_VECTOR[z], GEN_COMPONENT_NAMES_VECTOR[w] );
			funcName[vecComponents] = 0;

			String_Appendf( codeHeader, "\tinline %s%d %s() const;\n", typeString, vecComponents, funcName );

			String_Appendf( codeInl, "%s%d %s::%s() const { ", typeString, vecComponents, fullTypeName, funcName );
			String_Appendf( codeInl, "return %s%d( ", typeString, vecComponents );
			for ( u32 componentIndex = 0; componentIndex < vecComponents; componentIndex++ ) {
				String_Appendf( codeInl, "%c", funcName[componentIndex] );

				if ( componentIndex != vecComponents - 1 ) {
					String_Append( codeInl, ", " );
				}
			}
			String_Append( codeInl, " );" );
			String_Append( codeInl, " }\n" );
		}

		String_Append( codeInl, "\n" );
	}
}

void Gen_VectorType_CPP( const genType_t type, const u32 numComponents ) {
	assert( numComponents >= GEN_COMPONENT_COUNT_MIN );
	assert( numComponents <= GEN_COMPONENT_COUNT_MAX );

	const char* typeString = Gen_GetTypeString( type );
	const char* memberTypeString = Gen_GetMemberTypeString( type );

	char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	snprintf( fullTypeName, GEN_STRING_LENGTH_TYPE_NAME, "%s%d", typeString, numComponents );

	stringBuilder_t codeHeader = String_Create( 32 * KB_TO_BYTES );
	stringBuilder_t codeInl = String_Create( 32 * KB_TO_BYTES );

	// header pre-functions
	{
		String_Append( &codeHeader, GEN_FILE_HEADER );

		String_Append( &codeHeader, "#pragma once\n" );
		String_Append( &codeHeader, "\n" );

		if ( type != GEN_TYPE_BOOL ) {
			String_Appendf( &codeHeader, "#include \"bool%d.h\"\n", numComponents );
			String_Append(  &codeHeader, "\n" );
		}

		String_Append( &codeHeader, "#include <stdint.h>\n" );
		String_Append( &codeHeader, "#include \"../" GEN_HEADER_TYPES "\"\n" );
		String_Append( &codeHeader, "\n" );

		// forward declarations & includes
		for ( u32 i = GEN_COMPONENT_COUNT_MIN; i <= GEN_COMPONENT_COUNT_MAX; i++ ) {
			// includes for smaller vectors due to swizzle functions
			if (i < numComponents) {
				String_Appendf( &codeHeader, "#include \"%s%d.h\"\n", typeString, i );
			}
			// dont forward declare ourself
			else if ( i != numComponents ) {
				String_Appendf( &codeHeader, "struct %s%d;\n", typeString, i );
			}
		}

		if ( numComponents >= 3 ) {
			String_Append( &codeHeader, "struct float3;\n" );
		}

		String_Append( &codeHeader, "\n" );

		// unfortunately, the only way around this is to turn off pedantic/
		// if anyone has a better suggestion, while still keeping structs anonymous, I'm all ears
		String_Append( &codeHeader,
			"// ignore prohibition of anymous structs for GCC\n" \
			"#if defined( __clang__ ) || defined( __GNUC__ )\n" \
			"#pragma GCC diagnostic push\n" \
			"#pragma GCC diagnostic ignored \"-Wpedantic\"\n" \
			"#elif defined( _MSC_VER )\n" \
			"#pragma warning( push )\n" \
			"#pragma warning( disable : 4201 ) // C4201 - nonstandard extension used : nameless struct/union\n" \
			"#endif\n" \
			"\n" );

		GenerateDocStruct( &codeHeader, numComponents, memberTypeString );
		String_Appendf( &codeHeader, "struct %s\n", fullTypeName );
		String_Append(  &codeHeader, "{\n" );
		String_Append(  &codeHeader, "\tunion\n" );
		String_Append(  &codeHeader, "\t{\n" );
		String_Append(  &codeHeader, "\t\tstruct\n" );
		String_Append(  &codeHeader, "\t\t{\n" );
		for ( u32 i = 0; i < numComponents; i++ ) {
			String_Appendf( &codeHeader, "\t\t\t%s %c;\n", memberTypeString, GEN_COMPONENT_NAMES_VECTOR[i] );
		}
		String_Append(  &codeHeader, "\t\t};\n" );
		String_Append(  &codeHeader, "\n" );

		// no point in bool vectors generating RGB members
		if ( type != GEN_TYPE_BOOL ) {
			String_Append( &codeHeader, "\t\tstruct\n" );
			String_Append( &codeHeader, "\t\t{\n" );
			for ( u32 i = 0; i < numComponents; i++ ) {
				String_Appendf( &codeHeader, "\t\t\t%s %c;\n", memberTypeString, GEN_COMPONENT_NAMES_COLOR[i] );
			}
			String_Append( &codeHeader, "\t\t};\n" );
			String_Append( &codeHeader, "\n" );
		}

		String_Appendf( &codeHeader, "\t\t%s data[%d];\n", memberTypeString, numComponents );
		String_Append(  &codeHeader, "\t};\n" );
		String_Append( &codeHeader, "\n" );
		String_Append(  &codeHeader, "\n" );
	}

	// inl before functions
	{
		String_Append( &codeInl, GEN_FILE_HEADER );
		String_Append( &codeInl, "#pragma once\n" );
		String_Append( &codeInl, "\n" );

		String_Append( &codeInl, "// hlml includes\n" );

		for ( u32 i = GEN_COMPONENT_COUNT_MIN; i <= GEN_COMPONENT_COUNT_MAX; i++ ) {
			String_Appendf( &codeInl, "#include \"%s%d.h\"\n", typeString, i );
		}
		String_Append( &codeInl, "\n" );

		if ( type == GEN_TYPE_FLOAT ) {
			String_Append( &codeInl, "#include \"" GEN_FILENAME_FUNCTIONS_SCALAR ".h\"\n" );
			String_Append( &codeInl, "\n" );
		}

		String_Append( &codeInl,
			"// others\n" \
			"#include <math.h>\n" \
			"#include <memory.h>\n" \
			"#include <assert.h>\n" \
			"\n" );
	}

	GenerateConstructors( &codeHeader, &codeInl, type, numComponents, fullTypeName, memberTypeString, typeString );

	GenerateOperatorsAssignment( &codeHeader, &codeInl, fullTypeName, typeString );

	GenerateOperatorsArray( &codeHeader, &codeInl, numComponents, memberTypeString, fullTypeName );

	GenerateSwizzleFuncs( &codeHeader, &codeInl, numComponents, typeString, fullTypeName );

	String_Append( &codeHeader, "};\n\n" );

	String_Append( &codeHeader,
		"#if defined( __clang__ ) || defined( __GNUC__ )\n" \
		"#pragma GCC diagnostic pop\n" \
		"#elif defined( _MSC_VER )\n" \
		"#pragma warning( pop )\n" \
		"#endif\n" \
		"\n" );

	// GenerateOperatorsEquality( &codeHeader, &codeInl, type, numComponents, fullTypeName );

	const char* folder = GEN_FOLDER_PATHS_OUT_GEN[GEN_LANGUAGE_CPP];

	char fileNameHeader[64] = {};
	snprintf( fileNameHeader, 64, "%s%s.h", folder, fullTypeName );

	char fileNameInl[64] = {};
	snprintf( fileNameInl, 64, "%s%s.inl", folder, fullTypeName );

	FS_WriteEntireFile( fileNameHeader, codeHeader.str, codeHeader.length );
	FS_WriteEntireFile( fileNameInl, codeInl.str, codeInl.length );

	Mem_Reset();
}
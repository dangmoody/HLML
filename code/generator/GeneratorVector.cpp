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
#include "GeneratorVector.h"

#include "allocator.h"
#include "string_builder.h"

#include "gen_doc_common.h"

#include "file_io.h"

#include <string.h>
#include <assert.h>
#include <memory.h>
#include <math.h>

bool GeneratorVector::Generate( const genType_t type, const u32 numComponents ) {
	assert( numComponents >= GEN_COMPONENT_COUNT_MIN );
	assert( numComponents <= GEN_COMPONENT_COUNT_MAX );

	m_type = type;
	m_numComponents = numComponents;

	m_typeString = Gen_GetTypeString( m_type );
	m_memberTypeString = Gen_GetMemberTypeString( m_type );

	snprintf( m_fullTypeName, GEN_STRING_LENGTH_TYPE_NAME, "%s%d", m_typeString, numComponents );

	m_codeHeader = String_Create( 32 * KB_TO_BYTES );
	m_codeInl = String_Create( 32 * KB_TO_BYTES );

	// header pre-functions
	{
		String_Append( &m_codeHeader, GEN_FILE_HEADER );

		String_Append( &m_codeHeader, "#pragma once\n" );
		String_Append( &m_codeHeader, "\n" );

		if ( m_type != GEN_TYPE_BOOL ) {
			String_Appendf( &m_codeHeader, "#include \"bool%d.h\"\n", m_numComponents );
			String_Append(  &m_codeHeader, "\n" );
		}

		String_Append( &m_codeHeader, "#include <stdint.h>\n" );
		String_Append( &m_codeHeader, "#include \"../" GEN_HEADER_TYPES "\"\n" );
		String_Append( &m_codeHeader, "\n" );

		// forward declarations & includes
		for ( u32 i = GEN_COMPONENT_COUNT_MIN; i <= GEN_COMPONENT_COUNT_MAX; i++ ) {
			// includes for smaller vectors due to swizzle functions
			if (i < m_numComponents) {
				String_Appendf( &m_codeHeader, "#include \"%s%d.h\"\n", m_typeString, i );
			}
			// dont forward declare ourself
			else if ( i != m_numComponents ) {
				String_Appendf( &m_codeHeader, "struct %s%d;\n", m_typeString, i );
			}
		}

		if ( m_numComponents >= 3 ) {
			String_Append( &m_codeHeader, "struct float3;\n" );
		}

		String_Append( &m_codeHeader, "\n" );

		// unfortunately, the only way around this is to turn off pedantic/
		// if anyone has a better suggestion, while still keeping structs anonymous, I'm all ears
		String_Append( &m_codeHeader,
			"// ignore prohibition of anymous structs for GCC\n" \
			"#if defined( __clang__ ) || defined( __GNUC__ )\n" \
			"#pragma GCC diagnostic push\n" \
			"#pragma GCC diagnostic ignored \"-Wpedantic\"\n" \
			"#elif defined( _MSC_VER )\n" \
			"#pragma warning( push )\n" \
			"#pragma warning( disable : 4201 ) // C4201 - nonstandard extension used : nameless struct/union\n" \
			"#endif\n" \
			"\n" );

		GenerateDocStruct();
		String_Appendf( &m_codeHeader, "struct %s\n", m_fullTypeName );
		String_Append(  &m_codeHeader, "{\n" );
		String_Append(  &m_codeHeader, "\tunion\n" );
		String_Append(  &m_codeHeader, "\t{\n" );

		HeaderGenerateMembersStruct( GEN_COMPONENT_NAMES_VECTOR );

		if ( m_type != GEN_TYPE_BOOL ) {
			HeaderGenerateMembersStruct( GEN_COMPONENT_NAMES_COLOR );
		}

		String_Appendf( &m_codeHeader, "\t\t%s data[%d] = { 0 };\n", m_memberTypeString, m_numComponents );
		String_Append(  &m_codeHeader, "\t};\n" );
		String_Append(  &m_codeHeader, "\n" );
	}

	// inl before functions
	{
		String_Append( &m_codeInl, GEN_FILE_HEADER );
		String_Append( &m_codeInl, "#pragma once\n" );
		String_Append( &m_codeInl, "\n" );

		String_Append( &m_codeInl, "// hlml includes\n" );

		for ( u32 i = GEN_COMPONENT_COUNT_MIN; i <= GEN_COMPONENT_COUNT_MAX; i++ ) {
			String_Appendf( &m_codeInl, "#include \"%s%d.h\"\n", m_typeString, i );
		}
		String_Append( &m_codeInl, "\n" );

		if ( m_type == GEN_TYPE_FLOAT ) {
			String_Append( &m_codeInl, "#include \"" GEN_HEADER_FUNCTIONS_SCALAR "\"\n" );
			String_Append( &m_codeInl, "\n" );
		}

		String_Append( &m_codeInl,
			"// others\n" \
			"#include <math.h>\n" \
			"#include <memory.h>\n" \
			"#include <assert.h>\n" \
			"\n" );
	}

	GenerateConstructors();

	GenerateOperatorsAssignment();

	GenerateOperatorsArray();

	GenerateSwizzleFuncs();

	String_Append( &m_codeHeader, "};\n\n" );

	String_Append( &m_codeHeader,
		"#if defined( __clang__ ) || defined( __GNUC__ )\n" \
		"#pragma GCC diagnostic pop\n" \
		"#elif defined( _MSC_VER )\n" \
		"#pragma warning( pop )\n" \
		"#endif\n" \
		"\n" );

	GenerateOperatorsEquality();

	char fileNameHeader[64] = {};
	snprintf( fileNameHeader, 64, "%s%s.h", GEN_OUT_GEN_FOLDER_PATH, m_fullTypeName );

	char fileNameInl[64] = {};
	snprintf( fileNameInl, 64, "%s%s.inl", GEN_OUT_GEN_FOLDER_PATH, m_fullTypeName );

	FS_WriteEntireFile( fileNameHeader, m_codeHeader.str, m_codeHeader.length );
	FS_WriteEntireFile( fileNameInl, m_codeInl.str, m_codeInl.length );

	Mem_Reset();

	return true;
}

#ifdef _DEBUG
void GeneratorVector::PrintHeader() const {
	printf( "%s\n", m_codeHeader.str );
}

void GeneratorVector::PrintInl() const {
	printf( "%s\n", m_codeInl.str );
}
#endif

void GeneratorVector::HeaderGenerateMembersStruct( const char componentNames[GEN_COMPONENT_COUNT_MAX] ) {
	String_Append( &m_codeHeader, "\t\tstruct\n" );
	String_Append( &m_codeHeader, "\t\t{\n" );

	for ( u32 i = 0; i < m_numComponents; i++ ) {
		String_Appendf( &m_codeHeader, "\t\t\t%s %c;\n", m_memberTypeString, componentNames[i] );
	}
	String_Append( &m_codeHeader, "\t\t};\n" );

	String_Append( &m_codeHeader, "\n" );
}

void GeneratorVector::GenerateConstructors() {
	// default ctor
	{
		GenerateDocCtorDefault();
		String_Appendf( &m_codeHeader, "\tinline %s();\n", m_fullTypeName );
		String_Append(  &m_codeHeader, "\n" );

		String_Appendf( &m_codeInl, "%s::%s()\n", m_fullTypeName, m_fullTypeName );
		String_Append(  &m_codeInl, "{\n" );
		String_Appendf( &m_codeInl, "\tmemset( data, 0, %d * sizeof( %s ) );\n", m_numComponents, m_memberTypeString );
		String_Append(  &m_codeInl, "}\n" );
		String_Append(  &m_codeInl, "\n" );
	}

	// single scalar ctor
	{
		GenerateDocCtorScalar();
		String_Appendf( &m_codeHeader, "\tinline explicit %s( const %s x );\n", m_fullTypeName, m_memberTypeString );
		String_Append(  &m_codeHeader, "\n" );

		String_Appendf( &m_codeInl, "%s::%s( const %s x )\n", m_fullTypeName, m_fullTypeName, m_memberTypeString );
		String_Append(  &m_codeInl, "{\n" );
		String_Append(  &m_codeInl, "\t" );
		for ( u32 i = 0; i < m_numComponents; i++ ) {
			String_Appendf( &m_codeInl, "this->%c = ", GEN_COMPONENT_NAMES_VECTOR[i] );
		}
		String_Append( &m_codeInl, "x;\n" );
		String_Append( &m_codeInl, "}\n" );
		String_Append( &m_codeInl, "\n" );
	}

	// member-wise ctor
	{
		GenerateDocCtorMemberwise();
		String_Appendf( &m_codeHeader, "\tinline %s( ", m_fullTypeName );
		for ( u32 i = 0; i < m_numComponents; i++ ) {
			String_Appendf( &m_codeHeader, "const %s %c", m_memberTypeString, GEN_COMPONENT_NAMES_VECTOR[i] );

			if ( i != m_numComponents - 1 ) {
				String_Append( &m_codeHeader, ", " );
			}
		}
		String_Append( &m_codeHeader, " );\n" );
		String_Append( &m_codeHeader, "\n" );

		String_Appendf( &m_codeInl, "%s::%s( ", m_fullTypeName, m_fullTypeName );
		for ( u32 i = 0; i < m_numComponents; i++ ) {
			String_Appendf( &m_codeInl, "const %s %c", m_memberTypeString, GEN_COMPONENT_NAMES_VECTOR[i] );

			if ( i != m_numComponents - 1 ) {
				String_Append( &m_codeInl, ", " );
			}
		}
		String_Append( &m_codeInl, " )\n" );
		String_Append( &m_codeInl, "{\n" );
		for ( u32 i = 0; i < m_numComponents; i++ ) {
			const char componentName = GEN_COMPONENT_NAMES_VECTOR[i];

			String_Append(  &m_codeInl, "\t" );
			String_Appendf( &m_codeInl, "this->%c = %c", componentName, componentName );
			String_Append(  &m_codeInl, ";\n" );
		}
		String_Append( &m_codeInl, "}\n" );
		String_Append( &m_codeInl, "\n" );
	}

	// copy ctors for all valid vector types
	{
		for ( u32 i = GEN_COMPONENT_COUNT_MIN; i <= GEN_COMPONENT_COUNT_MAX; i++ ) {
			GenerateDocCtorCopy();
			String_Appendf( &m_codeHeader, "\tinline %s( const %s%d& other );\n", m_fullTypeName, m_typeString, i );
			String_Append(  &m_codeHeader, "\n" );

			String_Appendf( &m_codeInl, "%s::%s( const %s%d& other )\n", m_fullTypeName, m_fullTypeName, m_typeString, i );
			String_Append(  &m_codeInl, "{\n" );
			String_Append(  &m_codeInl, "\tmemcpy( data, other.data, sizeof( other.data ) );\n" );
			String_Append(  &m_codeInl, "}\n" );
			String_Append(  &m_codeInl, "\n" );
		}
	}

	// dtor
	String_Appendf( &m_codeHeader, "\t~%s() {}\n", m_fullTypeName );
	String_Append( &m_codeHeader, "\n" );
}

void GeneratorVector::GenerateOperatorsAssignment() {
	for ( u32 i = GEN_COMPONENT_COUNT_MIN; i <= GEN_COMPONENT_COUNT_MAX; i++ ) {
		GenerateDocOperatorAssignment();
		String_Appendf( &m_codeHeader, "\tinline %s operator=( const %s%d& rhs );\n", m_fullTypeName, m_typeString, i );
		String_Append(  &m_codeHeader, "\n" );

		String_Appendf( &m_codeInl, "%s %s::operator=( const %s%d& rhs )\n", m_fullTypeName, m_fullTypeName, m_typeString, i );
		String_Append(  &m_codeInl, "{\n" );
		String_Append(  &m_codeInl, "\tmemcpy( data, rhs.data, sizeof( rhs.data ) );\n" );
		String_Append(  &m_codeInl, "\treturn *this;\n" );
		String_Append(  &m_codeInl, "}\n" );
		String_Append(  &m_codeInl, "\n" );
	}
}

void GeneratorVector::GenerateOperatorsArray() {
	GenerateDocOperatorArray();
	String_Appendf( &m_codeHeader, "\tinline const %s& operator[]( const uint32_t index ) const;\n", m_memberTypeString );
	String_Append(  &m_codeHeader, "\n" );

	String_Appendf( &m_codeInl, "const %s& %s::operator[]( const uint32_t index ) const\n", m_memberTypeString, m_fullTypeName );
	String_Append(  &m_codeInl, "{\n" );
	String_Appendf( &m_codeInl, "\tassert( index < %d );\n", m_numComponents );
	String_Append(  &m_codeInl, "\treturn data[index];\n" );
	String_Append(  &m_codeInl, "}\n" );
	String_Append(  &m_codeInl, "\n" );

	GenerateDocOperatorArray();
	String_Appendf( &m_codeHeader, "\tinline %s& operator[]( const uint32_t index );\n", m_memberTypeString );
	String_Append(  &m_codeHeader, "\n" );

	String_Appendf( &m_codeInl, "%s& %s::operator[]( const uint32_t index )\n", m_memberTypeString, m_fullTypeName );
	String_Append(  &m_codeInl, "{\n" );
	String_Appendf( &m_codeInl, "\tassert( index < %d );\n", m_numComponents );
	String_Append(  &m_codeInl, "\treturn data[index];\n" );
	String_Append(  &m_codeInl, "}\n" );
	String_Append(  &m_codeInl, "\n" );
}

void GeneratorVector::GenerateOperatorsEquality() {
	// operator==
	{
		Doc_OperatorEquals( &m_codeHeader, m_fullTypeName );
		String_Appendf( &m_codeHeader, "inline bool operator==( const %s& lhs, const %s& rhs );\n", m_fullTypeName, m_fullTypeName );
		String_Append(  &m_codeHeader, "\n" );

		String_Appendf( &m_codeInl, "bool operator==( const %s& lhs, const %s& rhs )\n", m_fullTypeName, m_fullTypeName );
		String_Append(  &m_codeInl, "{\n" );
		String_Append(  &m_codeInl, "\treturn " );
		for ( u32 i = 0; i < m_numComponents; i++ ) {
			char component = GEN_COMPONENT_NAMES_VECTOR[i];

			if ( Gen_TypeIsFloatingPoint( m_type ) ) {
				const char* floateqStr = Gen_GetFuncNameFloateq( m_type );

				String_Appendf( &m_codeInl, "%s( lhs.%c, rhs.%c )", floateqStr, component, component );
			} else {
				String_Appendf( &m_codeInl, "( lhs.%c == rhs.%c )", component, component );
			}

			if ( i != m_numComponents - 1 ) {
				String_Append( &m_codeInl, " && " );
			}
		}
		String_Append( &m_codeInl, ";\n" );
		String_Append( &m_codeInl, "}\n" );
		String_Append( &m_codeInl, "\n" );
	}

	Gen_OperatorNotEquals( m_type, 1, m_numComponents, &m_codeHeader, &m_codeInl );
}

void GeneratorVector::GenerateSwizzleFuncs() {
	String_Append( &m_codeHeader, "\t// swizzle funcs\n" );

	char funcName[GEN_COMPONENT_COUNT_MAX + 1];
	memset( funcName, 0, sizeof( funcName ) );

	// for every vector type compatible with this one (that is: for each vector type with less components than this one)
	for ( u32 vecComponents = GEN_COMPONENT_COUNT_MIN; vecComponents <= m_numComponents; vecComponents++ ) {
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

			String_Appendf( &m_codeHeader, "\tinline %s%d %s() const;\n", m_typeString, vecComponents, funcName );

			String_Appendf( &m_codeInl, "%s%d %s::%s() const { ", m_typeString, vecComponents, m_fullTypeName, funcName );
			String_Appendf( &m_codeInl, "return %s%d( ", m_typeString, vecComponents );
			for ( u32 componentIndex = 0; componentIndex < vecComponents; componentIndex++ ) {
				String_Appendf( &m_codeInl, "%c", funcName[componentIndex] );

				if ( componentIndex != vecComponents - 1 ) {
					String_Append( &m_codeInl, ", " );
				}
			}
			String_Append( &m_codeInl, " );" );
			String_Append( &m_codeInl, " }\n" );
		}

		String_Append( &m_codeInl, "\n" );
	}
}

void GeneratorVector::GenerateDocStruct() {
	char componentsStr[GEN_COMPONENT_COUNT_MAX + 1];
	strncpy( componentsStr, GEN_COMPONENT_NAMES_VECTOR, m_numComponents );
	componentsStr[m_numComponents] = 0;

	String_Appendf( &m_codeHeader,
		"/// \\brief A vector of %d %ss with components %s.\n" \
		"/// Components are also stored as elements in an array via a union.\n", m_numComponents, m_memberTypeString, componentsStr );
}

void GeneratorVector::GenerateDocCtorDefault( void ) {
	String_Append( &m_codeHeader, "\t/// Default constructor.  Initializes all values to zero.\n" );
}

void GeneratorVector::GenerateDocCtorScalar() {
	String_Append( &m_codeHeader, "\t/// Initializes all components of the vector to the given scalar value.\n" );
}

void GeneratorVector::GenerateDocCtorMemberwise() {
	char componentsStr[GEN_COMPONENT_COUNT_MAX + 1];
	strncpy( componentsStr, GEN_COMPONENT_NAMES_VECTOR, m_numComponents );
	componentsStr[m_numComponents] = 0;

	String_Appendf( &m_codeHeader, "\t/// Sets the %s members of the vector to the corresponding parameters.\n", componentsStr );
}

void GeneratorVector::GenerateDocCtorCopy( void ) {
	String_Append( &m_codeHeader, "\t/// Copy constructor.  Copies the elements of the given vector via memcpy.\n" );
}

void GeneratorVector::GenerateDocOperatorAssignment() {
	String_Append( &m_codeHeader, "\t/// Copies the elements of the given vector via a single memcpy.\n" );
}

void GeneratorVector::GenerateDocOperatorArray() {
	String_Appendf( &m_codeHeader,
		"\t/// \\brief Returns the vector component at the given index.\n" \
		"\t/// Index CANNOT be lower than 0 or higher than %d.\n", m_numComponents - 1 );
}

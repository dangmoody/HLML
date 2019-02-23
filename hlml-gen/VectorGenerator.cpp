#include "VectorGenerator.h"

#include "FileIO.h"

#include <assert.h>
#include <string>

void VectorGenerator::Generate( const genType_t type, const uint32_t numComponents ) {
	m_type = type;
	m_numComponents = numComponents;

	if ( m_numComponents < GEN_COMPONENT_COUNT_MIN ) {
		printf( "ERROR: Can't generator a math type with less than %d components!\n", GEN_COMPONENT_COUNT_MIN );
		return;
	}

	if ( m_numComponents > GEN_COMPONENT_COUNT_MAX ) {
		printf( "ERROR: Can't generator a math type with more than %d components!\n", GEN_COMPONENT_COUNT_MAX );
		return;
	}

	m_typeString = Gen_GetMemberTypeString( m_type );
	m_fullTypeName = Gen_GetTypeString( type ) + std::to_string( m_numComponents );

	GenerateHeader();
	GenerateInl();

	FS_WriteToFile( ( GEN_OUT_GEN_FOLDER_PATH + m_fullTypeName + ".h" ).c_str(), m_codeHeader.c_str(), m_codeHeader.size() );
	FS_WriteToFile( ( GEN_OUT_GEN_FOLDER_PATH + m_fullTypeName + ".inl" ).c_str(), m_codeInl.c_str(), m_codeInl.size() );
}

void VectorGenerator::PrintHeader() const {
	printf( "%s\n", m_codeHeader.c_str() );
}

void VectorGenerator::PrintInl() const {
	printf( "%s\n", m_codeInl.c_str() );
}

void VectorGenerator::GenerateHeader() {
	m_codeHeader = std::string();

	// generate code
	m_codeHeader += GEN_COPYRIGHT_HEADER;
	m_codeHeader += "\n";
	m_codeHeader += GEN_GENERATED_WARNING;
	m_codeHeader += "\n";

	m_codeHeader += "#pragma once\n";
	m_codeHeader += "\n";

	if ( m_type != GEN_TYPE_BOOL ) {
		m_codeHeader += "#include \"bool" + std::to_string( m_numComponents ) + ".h\"\n";
		m_codeHeader += "\n";
	}

	m_codeHeader += "#include <stdint.h>\n";
	m_codeHeader += "\n";

	HeaderGenerateForwardDeclarations();

	m_codeHeader += "struct " + m_fullTypeName + " {\n";
	HeaderGenerateMembers();

	HeaderGenerateConstructors();

	HeaderGenerateOperatorsAssignment();

	HeaderGenerateOperatorsArithmetic();

	HeaderGenerateOperatorsArray();

	m_codeHeader += "};\n\n";

	HeaderGenerateOperatorsEquality();

	HeaderGenerateOperatorsRelational();
	
	m_codeHeader += "#include \"" + m_fullTypeName + ".inl\"";
}

void VectorGenerator::GenerateInl() {
	m_codeInl = std::string();

	m_codeInl += GEN_COPYRIGHT_HEADER;
	m_codeInl += "\n";
	m_codeInl += GEN_GENERATED_WARNING;
	m_codeInl += "\n";

	m_codeInl += "// hlml includes\n";

	for ( uint32_t i = GEN_COMPONENT_COUNT_MIN; i <= GEN_COMPONENT_COUNT_MAX; i++ ) {
		if ( m_numComponents != i ) {
			m_codeInl += "#include \"" + Gen_GetTypeString( m_type ) + std::to_string( i ) + ".h\"\n";
		}
	}
	m_codeInl += "\n";

	m_codeInl += "#include \"../" + std::string( GEN_HEADER_MAIN ) + "\"\n";
	m_codeInl += "\n";

	m_codeInl += "// others\n";
	m_codeInl += "#include <math.h>\n";
	m_codeInl += "#include <memory.h>\n";
	m_codeInl += "#include <assert.h>\n";
	m_codeInl += "\n";

	InlGenerateConstructors();

	InlGenerateOperatorsAssignment();

	InlGenerateOperatorsArithmetic();

	InlGenerateOperatorsArray();

	InlGenerateOperatorsEquality();

	InlGenerateOperatorsRelational();
}

void VectorGenerator::HeaderGenerateForwardDeclarations() {
	for ( uint32_t i = GEN_COMPONENT_COUNT_MIN; i <= GEN_COMPONENT_COUNT_MAX; i++ ) {
		// dont forward declare ourself
		if ( i != m_numComponents ) {
			m_codeHeader += "struct " + Gen_GetTypeString( m_type ) + std::to_string( i ) + ";\n";
		}
	}

	if ( m_numComponents >= 3 ) {
		m_codeHeader += "struct float3;\n";
	}

	m_codeHeader += "\n";
}

void VectorGenerator::HeaderGenerateMembers() {
	m_codeHeader += "\tunion {\n";

	HeaderGenerateMembersStruct( GEN_COMPONENT_NAMES_VECTOR );

	if ( m_type != GEN_TYPE_BOOL ) {
		HeaderGenerateMembersStruct( GEN_COMPONENT_NAMES_COLOR );
	}

	m_codeHeader += "\t\t" + m_typeString + std::string( " data[" ) + std::to_string( m_numComponents ) + std::string( "] = { 0 };\n" );
	m_codeHeader += "\t};\n";

	m_codeHeader += "\n";
}

void VectorGenerator::HeaderGenerateMembersStruct( const std::string& componentNames ) {
	m_codeHeader += "\t\tstruct {\n";

	for ( uint32_t i = 0; i < m_numComponents; i++ ) {
		m_codeHeader += "\t\t\t" + m_typeString + " " + componentNames[i] + ";\n";
	}
	m_codeHeader += "\t\t};\n";

	m_codeHeader += "\n";
}

void VectorGenerator::HeaderGenerateConstructors() {
	// default ctor
	m_codeHeader += "\tinline " + m_fullTypeName + "();\n";

	// single scalar ctor
	m_codeHeader += "\tinline explicit " + m_fullTypeName + "( const " + m_typeString + " x );\n";

	// member-wise ctors
	m_codeHeader += "\tinline " + m_fullTypeName + "( ";
	for ( uint32_t i = 0; i < m_numComponents; i++ ) {
		m_codeHeader += std::string( "const " ) + m_typeString + std::string( " " ) + GEN_COMPONENT_NAMES_VECTOR[i];

		if ( i != m_numComponents - 1 ) {
			m_codeHeader += ", ";
		}
	}
	m_codeHeader += " );\n";

	// copy ctors for all valid vector types
	for ( uint32_t i = GEN_COMPONENT_COUNT_MIN; i <= GEN_COMPONENT_COUNT_MAX; i++ ) {
		m_codeHeader += "\tinline " + m_fullTypeName + "( const " + Gen_GetTypeString( m_type ) + std::to_string( i ) + "& other );\n";
	}

	// dtor
	m_codeHeader += "\t~" + m_fullTypeName + "() {}\n";

	m_codeHeader += "\n";
}

void VectorGenerator::HeaderGenerateOperatorsAssignment() {
	for ( uint32_t i = GEN_COMPONENT_COUNT_MIN; i <= GEN_COMPONENT_COUNT_MAX; i++ ) {
		m_codeHeader += "\tinline " + m_fullTypeName + " operator=( const " + Gen_GetTypeString( m_type ) + std::to_string( i ) + "& rhs );\n";
	}

	m_codeHeader += "\n";
}

void VectorGenerator::HeaderGenerateOperatorsArithmetic() {
	if ( m_type == GEN_TYPE_BOOL ) {
		return;
	}

	for ( uint32_t i = 0; i < _countof( GEN_OPERATORS_ARITHMETIC ); i++ ) {
		const std::string op = GEN_OPERATORS_ARITHMETIC[i];

		m_codeHeader += "\tinline " + m_fullTypeName + " operator" + op + "( const " + m_typeString + " rhs ) const;\n";
		m_codeHeader += "\tinline " + m_fullTypeName + " operator" + op + "=( const " + m_typeString + " rhs );\n";

		m_codeHeader += "\tinline " + m_fullTypeName + " operator" + op + "( const " + m_fullTypeName + "& rhs ) const;\n";
		m_codeHeader += "\tinline " + m_fullTypeName + " operator" + op + "=( const " + m_fullTypeName + "& rhs );\n";
	}

	m_codeHeader += "\n";
}

void VectorGenerator::HeaderGenerateOperatorsArray() {
	m_codeHeader += "\tinline const " + m_typeString + "& operator[]( const uint32_t index ) const;\n";
	m_codeHeader += "\tinline " + m_typeString + "& operator[]( const uint32_t index );\n";
}

void VectorGenerator::HeaderGenerateOperatorsEquality() {
	m_codeHeader += "inline bool operator==( const " + m_fullTypeName + "& lhs, const " + m_fullTypeName + "& rhs );\n";
	m_codeHeader += "inline bool operator!=( const " + m_fullTypeName + "& lhs, const " + m_fullTypeName + "& rhs );\n";

	m_codeHeader += "\n";
}

void VectorGenerator::HeaderGenerateOperatorsRelational() {
	if ( m_type == GEN_TYPE_BOOL ) {
		return;
	}

	std::string boolReturnType = "bool" + std::to_string( m_numComponents );

	for ( uint32_t i = 0; i < _countof( GEN_OPERATORS_EQUALITY ); i++ ) {
		m_codeHeader += "inline " + boolReturnType + " operator" + GEN_OPERATORS_EQUALITY[i] + "( const " + m_fullTypeName + "& lhs, const " + m_fullTypeName + "& rhs );\n";
	}

	m_codeHeader += "\n";
}


void VectorGenerator::InlGenerateConstructors() {
	// default ctor
	m_codeInl += m_fullTypeName + "::" + m_fullTypeName + "() {\n";
	m_codeInl += "\tmemset( data, 0, " + std::to_string( m_numComponents ) + " * sizeof( " + m_typeString + " ) );\n";
	m_codeInl += "}\n";

	m_codeInl += "\n";

	// single scalar ctor
	m_codeInl += m_fullTypeName + "::" + m_fullTypeName + "( const " + m_typeString + " x ) {\n";
	m_codeInl += "\t";
	for ( uint32_t i = 0; i < m_numComponents; i++ ) {
		m_codeInl += std::string( "this->" ) + GEN_COMPONENT_NAMES_VECTOR[i] + std::string( " = " );
	}
	m_codeInl += "x;\n";
	m_codeInl += "}\n";

	m_codeInl += "\n";

	// memberwise ctor
	m_codeInl += m_fullTypeName + "::" + m_fullTypeName + "( ";
	for ( uint32_t i = 0; i < m_numComponents; i++ ) {
		m_codeInl += std::string( "const " ) + m_typeString + std::string( " " ) + GEN_COMPONENT_NAMES_VECTOR[i];

		if ( i != m_numComponents - 1 ) {
			m_codeInl += ", ";
		}
	}
	m_codeInl += " ) {\n";
	for ( uint32_t i = 0; i < m_numComponents; i++ ) {
		m_codeInl += "\t";
		m_codeInl += std::string( "this->" ) + GEN_COMPONENT_NAMES_VECTOR[i] + std::string( " = " ) + GEN_COMPONENT_NAMES_VECTOR[i];
		m_codeInl += ";\n";
	}
	m_codeInl += "}\n";

	m_codeInl += "\n";

	// copy ctors for all valid vector types
	for ( uint32_t i = GEN_COMPONENT_COUNT_MIN; i <= GEN_COMPONENT_COUNT_MAX; i++ ) {
		m_codeInl += m_fullTypeName + "::" + m_fullTypeName + "( const " + Gen_GetTypeString( m_type ) + std::to_string( i ) + "& other ) {\n";
		m_codeInl += "\tmemcpy( data, other.data, sizeof( other.data ) );\n";
		m_codeInl += "}\n";

		if ( i != GEN_COMPONENT_COUNT_MAX ) {
			m_codeInl += "\n";
		}
	}

	m_codeInl += "\n";
}

void VectorGenerator::InlGenerateOperatorsAssignment() {
	for ( uint32_t i = GEN_COMPONENT_COUNT_MIN; i <= GEN_COMPONENT_COUNT_MAX; i++ ) {
		m_codeInl += m_fullTypeName + " " + m_fullTypeName + "::operator=( const " + Gen_GetTypeString( m_type ) + std::to_string( i ) + "& rhs ) {\n";
		m_codeInl += "\tmemcpy( data, rhs.data, sizeof( rhs.data ) );\n";
		m_codeInl += "\treturn *this;\n";
		m_codeInl += "}\n";

		if ( i != GEN_COMPONENT_COUNT_MAX ) {
			m_codeInl += "\n";
		}
	}

	m_codeInl += "\n";
}

void VectorGenerator::InlGenerateOperatorsArithmetic() {
	if ( m_type == GEN_TYPE_BOOL ) {
		return;
	}

	for ( uint32_t i = 0; i < _countof( GEN_OPERATORS_ARITHMETIC ); i++ ) {
		const std::string op = GEN_OPERATORS_ARITHMETIC[i];

		// single scalar
		m_codeInl += m_fullTypeName + " " + m_fullTypeName + "::operator" + op + "( const " + m_typeString + " rhs ) const {\n";
		m_codeInl += "\treturn " + m_fullTypeName + "(\n";
		for ( uint32_t i = 0; i < m_numComponents; i++ ) {
			m_codeInl += std::string( "\t\t" ) + GEN_COMPONENT_NAMES_VECTOR[i] + " " + op + " rhs";
			if ( i != m_numComponents - 1 ) {
				m_codeInl += ",";
			}
			m_codeInl += "\n";
		}
		m_codeInl += "\t);\n";
		m_codeInl += "}\n";

		m_codeInl += "\n";

		m_codeInl += m_fullTypeName + " " + m_fullTypeName + "::operator" + op + "=( const " + m_typeString + " rhs ) {\n";
		m_codeInl += "\treturn ( *this = *this " + op + " rhs );\n";
		m_codeInl += "}\n";

		m_codeInl += "\n";

		// compound lhs/rhs types
		m_codeInl += m_fullTypeName + " " + m_fullTypeName + "::operator" + op + "( const " + m_fullTypeName + "& rhs ) const {\n";
		m_codeInl += "\treturn " + m_fullTypeName + "(\n";
		for ( uint32_t i = 0; i < m_numComponents; i++ ) {
			m_codeInl += std::string( "\t\t" ) + GEN_COMPONENT_NAMES_VECTOR[i] + " " + op + " rhs." + GEN_COMPONENT_NAMES_VECTOR[i];
			if ( i != m_numComponents - 1 ) {
				m_codeInl += ",";
			}
			m_codeInl += "\n";
		}
		m_codeInl += "\t);\n";
		m_codeInl += "}\n";

		m_codeInl += "\n";

		m_codeInl += m_fullTypeName + " " + m_fullTypeName + "::operator" + op + "=( const " + m_fullTypeName + "& rhs ) {\n";
		m_codeInl += "\treturn ( *this = *this " + op + " rhs );\n";
		m_codeInl += "}\n";

		m_codeInl += "\n";
	}
}

void VectorGenerator::InlGenerateOperatorsArray() {
	m_codeInl += "const " + m_typeString + "& " + m_fullTypeName + "::operator[]( const uint32_t index ) const {\n";
	m_codeInl += "\tassert( index < " + std::to_string( m_numComponents ) + " );\n";
	m_codeInl += "\treturn data[index];\n";
	m_codeInl += "}\n";

	m_codeInl += "\n";

	m_codeInl += m_typeString + "& " + m_fullTypeName + "::operator[]( const uint32_t index ) {\n";
	m_codeInl += "\tassert( index < " + std::to_string( m_numComponents ) + " );\n";
	m_codeInl += "\treturn data[index];\n";
	m_codeInl += "}\n";

	m_codeInl += "\n";
}

void VectorGenerator::InlGenerateOperatorsEquality() {
	m_codeInl += "bool operator==( const " + m_fullTypeName + "& lhs, const " + m_fullTypeName + "& rhs ) {\n";
	m_codeInl += "\treturn ";
	for ( uint32_t i = 0; i < m_numComponents; i++ ) {
		m_codeInl += std::string( "floateq( lhs." ) + GEN_COMPONENT_NAMES_VECTOR[i] + std::string( ", rhs. " ) + GEN_COMPONENT_NAMES_VECTOR[i] + " )";

		if ( i != m_numComponents - 1 ) {
			m_codeInl += " && ";
		}
	}
	m_codeInl += ";\n";
	m_codeInl += "}\n";

	m_codeInl += "\n";

	m_codeInl += "bool operator!=( const " + m_fullTypeName + "& lhs, const " + m_fullTypeName + "& rhs ) {\n";
	m_codeInl += "\treturn !( operator==( lhs, rhs ) );\n";
	m_codeInl += "}\n";

	m_codeInl += "\n";
}

void VectorGenerator::InlGenerateOperatorsRelational() {
	if ( m_type == GEN_TYPE_BOOL ) {
		return;
	}

	std::string boolReturnType = "bool" + std::to_string( m_numComponents );

	uint32_t numOperators = _countof( GEN_OPERATORS_EQUALITY );

	for ( uint32_t operatorIndex = 0; operatorIndex < numOperators; operatorIndex++ ) {
		m_codeInl += boolReturnType + " operator" + GEN_OPERATORS_EQUALITY[operatorIndex] + "( const " + m_fullTypeName + "& lhs, const " + m_fullTypeName + "& rhs ) {\n";
		m_codeInl += "\treturn " + boolReturnType + "(\n";
		for ( uint32_t componentIndex = 0; componentIndex < m_numComponents; componentIndex++ ) {
			m_codeInl += std::string( "\t\tlhs." ) + GEN_COMPONENT_NAMES_VECTOR[componentIndex] + " " + GEN_OPERATORS_EQUALITY[operatorIndex] + " rhs." + GEN_COMPONENT_NAMES_VECTOR[componentIndex];

			if ( componentIndex < m_numComponents - 1 ) {
				m_codeInl += ",\n";
			} else {
				m_codeInl += "\n";
			}
		}
		m_codeInl += "\t);\n";
		m_codeInl += "}\n";

		if ( operatorIndex != numOperators - 1 ) {
			m_codeInl += "\n";
		}
	}

	m_codeInl += "\n";
}
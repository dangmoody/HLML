#include "MatrixGenerator.h"

#include "FileIO.h"

void MatrixGenerator::Generate( const genType_t type, const uint32_t numRows, const uint32_t numCols ) {
	m_type = type;

	m_numRows = numRows;
	m_numCols = numCols;

	m_numRowsStr = std::to_string( numRows );
	m_numColsStr = std::to_string( numCols );

	m_typeString = Gen_GetTypeString( type );
	m_memberTypeString = Gen_GetMemberTypeString( type );

	m_fullTypeName = m_typeString + m_numRowsStr + "x" + m_numColsStr;
	m_transposedTypeName = m_typeString + m_numColsStr + "x" + m_numRowsStr;

	m_vectorMemberTypeString = m_typeString + m_numColsStr;

	GenerateHeader();
	GenerateInl();

	FS_WriteToFile( ( GEN_OUT_GEN_FOLDER_PATH + m_fullTypeName + ".h" ).c_str(), m_codeHeader.c_str(), m_codeHeader.size() );
	FS_WriteToFile( ( GEN_OUT_GEN_FOLDER_PATH + m_fullTypeName + ".inl" ).c_str(), m_codeInl.c_str(), m_codeInl.size() );
}

void MatrixGenerator::PrintHeader() const {
	printf( "%s\n", m_codeHeader.c_str() );
}

void MatrixGenerator::PrintInl() const {
	printf( "%s\n", m_codeInl.c_str() );
}

void MatrixGenerator::GenerateHeader() {
	m_codeHeader = std::string();

	// generate code
	m_codeHeader += GEN_FILE_HEADER;

	m_codeHeader += "#pragma once\n";
	m_codeHeader += "\n";

	m_codeHeader += "#include \"" + m_typeString + m_numColsStr + ".h\"\n";								// vec type
	if ( m_numRows != m_numCols ) {
		m_codeHeader += "#include \"" + m_typeString + m_numRowsStr + "x" + m_numRowsStr + ".h\"\n";	// multiplication return type
		m_codeHeader += "#include \"" + m_transposedTypeName + ".h\"\n";								// transpose type
	}
	m_codeHeader += "\n";
	m_codeHeader += "struct " + m_fullTypeName + " {\n";

	HeaderGenerateMembers();

	HeaderGenerateConstructors();

	HeaderGenerateOperatorsAssignment();

	HeaderGenerateOperatorsArray();

	m_codeHeader += "};\n\n";

	HeaderGenerateOperatorsEquality();

	m_codeHeader += "#include \"" + m_fullTypeName + ".inl\"";
}

void MatrixGenerator::GenerateInl() {
	m_codeInl = std::string();

	m_codeInl += GEN_FILE_HEADER;

	m_codeInl += "// hlml includes\n";
	m_codeInl += "#include \"../" + std::string( GEN_HEADER_MAIN ) + "\"\n";
	m_codeInl += "\n";

	m_codeInl += "// others\n";
	m_codeInl += "#include <math.h>\n";
	m_codeInl += "\n";

	if ( m_type != GEN_TYPE_BOOL ) {
		m_codeInl += "// forward declares\n";
		m_codeInl += m_fullTypeName + " inverse( const " + m_fullTypeName + "& mat );\n";

		m_codeInl += "\n";
	}

	InlGenerateConstructors();

	InlGenerateOperatorsAssignment();

	InlGenerateOperatorsArray();

	InlGenerateOperatorsEquality();
}

void MatrixGenerator::HeaderGenerateMembers() {
	m_codeHeader += "\t" + m_vectorMemberTypeString + " rows[" + m_numRowsStr + "];\n";
	m_codeHeader += "\n";
}

void MatrixGenerator::HeaderGenerateConstructors() {
	// default ctor
	m_codeHeader += "\tinline " + m_fullTypeName + "();\n";

	// "diagonal" scaled uniform identity ctor
	m_codeHeader += "\tinline " + m_fullTypeName + "( const " + m_memberTypeString + " diagonal );\n";

	// "diagonal" scaled non-uniform identity ctor
	m_codeHeader += "\tinline " + m_fullTypeName + "( const " + m_vectorMemberTypeString + "& diagonal );\n";

	// row memberwise ctor
	m_codeHeader += "\tinline " + m_fullTypeName + "( ";
	for ( uint32_t i = 0; i < m_numRows; i++ ) {
		m_codeHeader += "const " + m_vectorMemberTypeString + "& row" + std::to_string( i );

		if ( i != m_numRows - 1 ) {
			m_codeHeader += ", ";
		}
	}
	m_codeHeader += " );\n";

	// array of rows ctor
	m_codeHeader += "\tinline " + m_fullTypeName + "( const " + m_vectorMemberTypeString + " rows[" + m_numRowsStr + "] );\n";

	// memberwise rows * cols ctor
	m_codeHeader += "\tinline " + m_fullTypeName + "( ";
	for ( uint32_t row = 0; row < m_numRows; row++ ) {
		for ( uint32_t col = 0; col < m_numCols; col++ ) {
			std::string rowStr = std::to_string( row );
			std::string colStr = std::to_string( col );

			m_codeHeader += "const " + m_memberTypeString + " m" + rowStr + colStr;

			if ( col != m_numCols - 1 ) {
				m_codeHeader += ", ";
			}
		}

		if ( row != m_numRows - 1 ) {
			m_codeHeader += ", ";
		}
	}
	m_codeHeader += " );\n";

	// copy ctor
	m_codeHeader += "\tinline " + m_fullTypeName + "( const " + m_fullTypeName + "& other );\n";

	// dtor
	m_codeHeader += "\tinline ~" + m_fullTypeName + "() {}\n";

	m_codeHeader += "\n";
}

void MatrixGenerator::HeaderGenerateOperatorsAssignment() {
	// assignment operator
	m_codeHeader += "\tinline " + m_fullTypeName + " operator=( const " + m_fullTypeName + "& other );\n";
	m_codeHeader += "\n";
}

void MatrixGenerator::HeaderGenerateOperatorsArray() {
	m_codeHeader += "\tinline " + m_vectorMemberTypeString + "& operator[]( const uint32_t index );\n";
	m_codeHeader += "\tinline const " + m_vectorMemberTypeString + "& operator[]( const uint32_t index ) const;\n";
}

void MatrixGenerator::HeaderGenerateOperatorsEquality() {
	m_codeHeader += "inline bool operator==( const " + m_fullTypeName + "& lhs, const " + m_fullTypeName + "& rhs );\n";
	m_codeHeader += "inline bool operator!=( const " + m_fullTypeName + "& lhs, const " + m_fullTypeName + "& rhs );\n";

	m_codeHeader += "\n";
}


void MatrixGenerator::InlGenerateConstructors() {
	// default ctor
	m_codeInl += m_fullTypeName + "::" + m_fullTypeName + "() {\n";
	for ( uint32_t row = 0; row < m_numRows; row++ ) {
		m_codeInl += "\trows[" + std::to_string( row ) + "] = { ";
		for ( uint32_t col = 0; col < m_numCols; col++ ) {
			m_codeInl += ( row == col ) ? "1" : "0";

			if ( col != m_numCols - 1 ) {
				m_codeInl += ", ";
			}
		}
		m_codeInl += " };\n";
	}
	m_codeInl += "}\n\n";

	// "diagonal" scaled non-uniform identity ctor
	m_codeInl += m_fullTypeName + "::" + m_fullTypeName + "( const " + m_memberTypeString + " diagonal ) {\n";
	for ( uint32_t i = 0; i < m_numRows; i++ ) {
		m_codeInl += "\trows[" + std::to_string( i ) + "] = { ";
		for ( uint32_t j = 0; j < m_numCols; j++ ) {
			m_codeInl += ( i == j ) ? "diagonal" : "0";

			if ( j != m_numCols - 1 ) {
				m_codeInl += ", ";
			}
		}
		m_codeInl += " };\n";
	}
	m_codeInl += "}\n\n";

	// "diagonal" scaled non-uniform identity ctor
	m_codeInl += m_fullTypeName + "::" + m_fullTypeName + "( const " + m_vectorMemberTypeString + "& diagonal ) {\n";
	for ( uint32_t i = 0; i < m_numRows; i++ ) {
		m_codeInl += "\trows[" + std::to_string( i ) + "] = { ";
		for ( uint32_t j = 0; j < m_numCols; j++ ) {
			m_codeInl += ( i == j ) ? std::string( "diagonal." ) + GEN_COMPONENT_NAMES_VECTOR[j] : "0";

			if ( j != m_numCols - 1 ) {
				m_codeInl += ", ";
			}
		}
		m_codeInl += " };\n";
	}
	m_codeInl += "}\n\n";

	// row memberwise ctor
	m_codeInl += m_fullTypeName + "::" + m_fullTypeName + "( ";
	for ( uint32_t i = 0; i < m_numRows; i++ ) {
		m_codeInl += "const " + m_vectorMemberTypeString + "& row" + std::to_string( i );

		if ( i != m_numRows - 1 ) {
			m_codeInl += ", ";
		}
	}
	m_codeInl += " ) {\n";
	for ( uint32_t i = 0; i < m_numRows; i++ ) {
		const std::string indexstr = std::to_string( i );
		m_codeInl += "\trows[" + indexstr + "] = row" + indexstr + ";\n";
	}
	m_codeInl += "}\n\n";

	// array of rows ctor
	m_codeInl += m_fullTypeName + "::" + m_fullTypeName + "( const " + m_vectorMemberTypeString + " rows[" + m_numRowsStr + "] ) {\n";
	for ( uint32_t i = 0; i < m_numRows; i++ ) {
		std::string indexstr = std::to_string( i );
		m_codeInl += "\tthis->rows[" + indexstr + "] = rows[" + indexstr + "];\n";
	}
	m_codeInl += "}\n\n";

	// memberwise rows * cols ctor
	m_codeInl += m_fullTypeName + "::" + m_fullTypeName + "( ";
	for ( uint32_t row = 0; row < m_numRows; row++ ) {
		for ( uint32_t col = 0; col < m_numCols; col++ ) {
			std::string rowStr = std::to_string( row );
			std::string colStr = std::to_string( col );

			m_codeInl += "const " + m_memberTypeString + " m" + rowStr + colStr;

			if ( col != m_numCols - 1 ) {
				m_codeInl += ", ";
			}
		}

		if ( row != m_numRows - 1 ) {
			m_codeInl += ", ";
		}
	}
	m_codeInl += " ) {\n";
	for ( uint32_t row = 0; row < m_numRows; row++ ) {
		std::string rowstr = std::to_string( row );

		m_codeInl += "\trows[" + rowstr + "] = { ";

		for ( uint32_t col = 0; col < m_numCols; col++ ) {
			std::string colstr = std::to_string( col );

			m_codeInl += "m" + rowstr + colstr;

			if ( col != m_numCols - 1 ) {
				m_codeInl += ", ";
			}
		}
		m_codeInl += " };\n";
	}
	m_codeInl += "}\n\n";

	// copy ctor
	m_codeInl += m_fullTypeName + "::" + m_fullTypeName + "( const " + m_fullTypeName + "& other ) {\n";
	m_codeInl += "\tmemcpy( rows, other.rows, sizeof( rows ) );\n";
	m_codeInl += "};\n";

	m_codeInl += "\n";
}

void MatrixGenerator::InlGenerateOperatorsAssignment() {
	m_codeInl += m_fullTypeName + " " + m_fullTypeName + "::operator=( const " + m_fullTypeName + "& other ) {\n";
	m_codeInl += "\tmemcpy( rows, other.rows, sizeof( rows ) );\n";
	m_codeInl += "\treturn *this;\n";
	m_codeInl += "};\n";

	m_codeInl += "\n";
}

void MatrixGenerator::InlGenerateOperatorsArray() {
	m_codeInl += m_vectorMemberTypeString + "& " + m_fullTypeName + "::operator[]( const uint32_t index ) {\n";
	m_codeInl += "\tassert( index < " + m_numRowsStr + " );\n";
	m_codeInl += "\treturn rows[index];\n";
	m_codeInl += "}\n";

	m_codeInl += "\n";

	m_codeInl += "const " + m_vectorMemberTypeString + "& " + m_fullTypeName + "::operator[]( const uint32_t index ) const {\n";
	m_codeInl += "\tassert( index < " + m_numRowsStr + " );\n";
	m_codeInl += "\treturn rows[index];\n";
	m_codeInl += "}\n";

	m_codeInl += "\n";
}

void MatrixGenerator::InlGenerateOperatorsEquality() {
	m_codeInl += "bool operator==( const " + m_fullTypeName + "& lhs, const " + m_fullTypeName + "& rhs ) {\n";
	m_codeInl += "\treturn ";
	for ( uint32_t i = 0; i < m_numRows; i++ ) {
		m_codeInl += "lhs[" + std::to_string( i ) + "] == rhs[" + std::to_string( i ) + "]";

		if ( i != m_numRows - 1 ) {
			m_codeInl += "\n\t\t&& ";
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

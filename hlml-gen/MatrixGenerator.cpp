#include "MatrixGenerator.h"

#include "FileIO.h"

void MatrixGenerator::Generate( const genType_t type, const uint32_t numRows, const uint32_t numCols ) {
	m_type = type;

	m_numRows = numRows;
	m_numCols = numCols;

	m_numVectors = numRows;

	m_typeString = Gen_GetTypeString( type );
	m_memberTypeString = Gen_GetMemberTypeString( type );
	m_fullTypeName = Gen_GetTypeString( type ) + std::to_string( numRows ) + "x" + std::to_string( numCols );
	m_vectorMemberTypeString = m_typeString + std::to_string( numCols );

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
	m_codeHeader += GEN_COPYRIGHT_HEADER;
	m_codeHeader += "\n";
	m_codeHeader += GEN_GENERATED_WARNING;
	m_codeHeader += "\n";

	m_codeHeader += "#pragma once\n";
	m_codeHeader += "\n";

	m_codeHeader += "#include \"" + m_typeString + std::to_string( m_numCols ) + ".h\"\n";
	m_codeHeader += "\n";
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

void MatrixGenerator::GenerateInl() {
	m_codeInl = std::string();

	m_codeInl += GEN_COPYRIGHT_HEADER;
	m_codeInl += "\n";
	m_codeInl += GEN_GENERATED_WARNING;
	m_codeInl += "\n";

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

	InlGenerateOperatorsArithmetic();

	InlGenerateOperatorsArray();

	InlGenerateOperatorsEquality();

	InlGenerateOperatorsRelational();
}

void MatrixGenerator::HeaderGenerateMembers() {
	m_codeHeader += "\t" + m_vectorMemberTypeString + " rows[" + std::to_string( m_numVectors ) + "];\n";

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
	for ( uint32_t i = 0; i < m_numVectors; i++ ) {
		m_codeHeader += "const " + m_vectorMemberTypeString + "& row" + std::to_string( i );

		if ( i != m_numVectors - 1 ) {
			m_codeHeader += ", ";
		}
	}
	m_codeHeader += " );\n";

	// array of rows ctor
	m_codeHeader += "\tinline " + m_fullTypeName + "( const " + m_vectorMemberTypeString + " rows[" + std::to_string( m_numVectors ) + "] );\n";

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
}

void MatrixGenerator::HeaderGenerateOperatorsArithmetic() {
	if ( m_type == GEN_TYPE_BOOL ) {
		return;
	}

	for ( uint32_t i = 0; i < _countof( GEN_OPERATORS_ARITHMETIC ); i++ ) {
		const std::string op = GEN_OPERATORS_ARITHMETIC[i];

		m_codeHeader += "\tinline " + m_fullTypeName + " operator" + op + "( const " + m_memberTypeString + " rhs ) const;\n";
		m_codeHeader += "\tinline " + m_fullTypeName + " operator" + op + "=( const " + m_memberTypeString + " rhs );\n";

		m_codeHeader += "\tinline " + m_fullTypeName + " operator" + op + "( const " + m_fullTypeName + "& rhs ) const;\n";
		m_codeHeader += "\tinline " + m_fullTypeName + " operator" + op + "=( const " + m_fullTypeName + "& rhs );\n";
	}

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

void MatrixGenerator::HeaderGenerateOperatorsRelational() {
	if ( m_type == GEN_TYPE_BOOL ) {
		return;
	}

	std::string boolReturnType = "bool" + std::to_string( m_numRows ) + "x" + std::to_string( m_numCols );

	for ( uint32_t i = 0; i < _countof( GEN_OPERATORS_EQUALITY ); i++ ) {
		m_codeHeader += "inline " + boolReturnType + " operator" + GEN_OPERATORS_EQUALITY[i] + "( const " + m_fullTypeName + "& lhs, const " + m_fullTypeName + "& rhs );\n";
	}

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
	for ( uint32_t i = 0; i < m_numVectors; i++ ) {
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
	for ( uint32_t i = 0; i < m_numVectors; i++ ) {
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
	for ( uint32_t i = 0; i < m_numVectors; i++ ) {
		m_codeInl += "const " + m_vectorMemberTypeString + "& row" + std::to_string( i );

		if ( i != m_numVectors - 1 ) {
			m_codeInl += ", ";
		}
	}
	m_codeInl += " ) {\n";
	for ( uint32_t i = 0; i < m_numVectors; i++ ) {
		const std::string indexstr = std::to_string( i );
		m_codeInl += "\trows[" + indexstr + "] = row" + indexstr + ";\n";
	}
	m_codeInl += "}\n\n";

	// array of rows ctor
	m_codeInl += m_fullTypeName + "::" + m_fullTypeName + "( const " + m_vectorMemberTypeString + " rows[" + std::to_string( m_numVectors ) + "] ) {\n";
	for ( uint32_t i = 0; i < m_numVectors; i++ ) {
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

void MatrixGenerator::InlGenerateOperatorsArithmetic() {
	if ( m_type == GEN_TYPE_BOOL ) {
		return;
	}

	uint32_t numOperators = _countof( GEN_OPERATORS_ARITHMETIC );
	for ( uint32_t operatorIndex = 0; operatorIndex < numOperators; operatorIndex++ ) {
		std::string op = GEN_OPERATORS_ARITHMETIC[operatorIndex];

		// scalar arithmetic operator
		m_codeInl += m_fullTypeName + " " + m_fullTypeName + "::operator" + op + "( const " + m_memberTypeString + " rhs ) const {\n";
		m_codeInl += "\treturn " + m_fullTypeName + "(\n";
		for ( uint32_t row = 0; row < m_numRows; row++ ) {
			m_codeInl += "\t\trows[" + std::to_string( row ) + "] " + op + " rhs";
			if ( row != m_numRows - 1 ) {
				m_codeInl += ",";
			}
			m_codeInl += "\n";
		}
		m_codeInl += "\t);\n";
		m_codeInl += "}\n";

		m_codeInl += "\n";

		// scalar compound arithmetic operator
		m_codeInl += m_fullTypeName + " " + m_fullTypeName + "::operator" + op + "=( const " + m_memberTypeString + " rhs ) {\n";
		m_codeInl += "\treturn ( *this = *this " + op + " rhs );\n";
		m_codeInl += "}\n";

		m_codeInl += "\n";

		// rhs type arithmetic operator
		m_codeInl += m_fullTypeName + " " + m_fullTypeName + "::operator" + op + "( const " + m_fullTypeName + "& rhs ) const {\n";

		if ( op == "+" || op == "-" ) {
			m_codeInl += "\treturn " + m_fullTypeName + "(\n";
			for ( uint32_t row = 0; row < m_numRows; row++ ) {
				m_codeInl += "\t\trows[" + std::to_string( row ) + "] " + op + " rhs[" + std::to_string( row ) + "]";
				if ( row != m_numRows - 1 ) {
					m_codeInl += ",";
				}
				m_codeInl += "\n";
			}
			m_codeInl += "\t);\n";
		} else if ( op == "*" ) {
			for ( uint32_t row = 0; row < m_numRows; row++ ) {
				std::string rowStr = std::to_string( row );
				m_codeInl += "\t" + m_typeString + std::to_string( m_numRows ) + " row" + rowStr + " = rows[" + rowStr + "];\n";
			}

			m_codeInl += "\n";

			for ( uint32_t col = 0; col < m_numCols; col++ ) {
				std::string colStr = std::to_string( col );
				m_codeInl += "\t" + m_typeString + std::to_string( m_numRows ) + " col" + colStr + " = { ";
				for ( uint32_t row = 0; row < m_numRows; row++ ) {
					m_codeInl += "rhs[" + std::to_string( row ) + "]." + GEN_COMPONENT_NAMES_VECTOR[col];

					if ( row != m_numRows - 1 ) {
						m_codeInl += ", ";
					}
				}

				m_codeInl += " };\n";
			}

			m_codeInl += "\n";

			m_codeInl += "\treturn " + m_fullTypeName + "(\n";

			for ( uint32_t row = 0; row < m_numRows; row++ ) {
				std::string rowStr = std::to_string( row );

				for ( uint32_t col = 0; col < m_numCols; col++ ) {
					std::string colStr = std::to_string( col );

					m_codeInl += "\t\t";

					for ( uint32_t row2 = 0; row2 < m_numRows; row2++ ) {
						m_codeInl += "row" + rowStr + "." + GEN_COMPONENT_NAMES_VECTOR[row2] + " * " + "col" + colStr + "." + GEN_COMPONENT_NAMES_VECTOR[row2];

						if ( row2 != m_numRows - 1 ) {
							m_codeInl += " + ";
						} else {
							if ( row + col != ( m_numRows - 1 ) + ( m_numCols - 1 ) ) {
								m_codeInl += ",";
							}

							m_codeInl += "\n";
						}
					}
				}

				if ( row != m_numRows - 1 ) {
					m_codeInl += "\n";
				}
			}
			m_codeInl += "\t);\n";
		} else if ( op == "/" ) {
			m_codeInl += "\treturn *this * inverse( rhs );\n";
		}

		m_codeInl += "}\n";

		m_codeInl += "\n";

		// rhs type compound arithmetic operator
		m_codeInl += m_fullTypeName + " " + m_fullTypeName + "::operator" + op + "=( const " + m_fullTypeName + "& rhs ) {\n";
		m_codeInl += "\treturn ( *this = *this " + op + " rhs );\n";
		m_codeInl += "}\n";

		if ( operatorIndex != numOperators - 1 ) {
			m_codeInl += "\n";
		}
	}

	m_codeInl += "\n";
}

void MatrixGenerator::InlGenerateOperatorsArray() {
	m_codeInl += m_vectorMemberTypeString + "& " + m_fullTypeName + "::operator[]( const uint32_t index ) {\n";
	m_codeInl += "\tassert( index < " + std::to_string( m_numRows ) + " );\n";
	m_codeInl += "\treturn rows[index];\n";
	m_codeInl += "}\n";

	m_codeInl += "\n";

	m_codeInl += "const " + m_vectorMemberTypeString + "& " + m_fullTypeName + "::operator[]( const uint32_t index ) const {\n";
	m_codeInl += "\tassert( index < " + std::to_string( m_numRows ) + " );\n";
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

void MatrixGenerator::InlGenerateOperatorsRelational() {
	if ( m_type == GEN_TYPE_BOOL ) {
		return;
	}

	std::string boolReturnType = "bool" + std::to_string( m_numRows ) + "x" + std::to_string( m_numCols );

	uint32_t numOperators = _countof( GEN_OPERATORS_EQUALITY );

	for ( uint32_t operatorIndex = 0; operatorIndex < numOperators; operatorIndex++ ) {
		m_codeInl += boolReturnType + " operator" + GEN_OPERATORS_EQUALITY[operatorIndex] + "( const " + m_fullTypeName + "& lhs, const " + m_fullTypeName + "& rhs ) {\n";
		m_codeInl += "\treturn " + boolReturnType + "(\n";

		for ( uint32_t row = 0; row < m_numRows; row++ ) {
			std::string rowStr = std::to_string( row );

			m_codeInl += "\t\tlhs[" + rowStr + "] " + GEN_OPERATORS_EQUALITY[operatorIndex] + " rhs[" + rowStr + "]";

			if ( row != m_numRows - 1 ) {
				m_codeInl += ",";
			}

			m_codeInl += "\n";
		}
		m_codeInl += "\t);\n";
		m_codeInl += "}\n";

		m_codeInl += "\n";
	}
}

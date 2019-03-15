#include "gen_funcs_matrix.h"

#include <assert.h>

// TODO(DM): move these functions into their own file
static std::string GetDocOperatorArithmeticScalar( const std::string& fullTypeName, const genOpArithmetic_t op ) {
	std::string adjective;
	switch ( op ) {
		case GEN_OP_ARITHMETIC_ADD: adjective = "added"; break;
		case GEN_OP_ARITHMETIC_SUB: adjective = "subtracted"; break;
		case GEN_OP_ARITHMETIC_MUL: adjective = "multiplied"; break;
		case GEN_OP_ARITHMETIC_DIV: adjective = "divided"; break;

		case GEN_OP_ARITHMETIC_COUNT:
		default:
			printf( "ERROR: Bad genOpArithmetic_t enum passed into %s.\n", __FUNCTION__ );
			return std::string();
	}

	return "/// \\relates " + fullTypeName + "\n" \
		"/// \\brief Returns a copy of the matrix that has been component-wise " + adjective + " by the given scalar value.\n";
}

// TODO(DM): this can go into gen_doc_common.h
static std::string GetDocOperatorCompoundArithmeticScalar( const std::string& fullTypeName, const genOpArithmetic_t op ) {
	std::string verb;
	switch ( op ) {
		case GEN_OP_ARITHMETIC_ADD: verb = "Adds"; break;
		case GEN_OP_ARITHMETIC_SUB: verb = "Subtracts"; break;
		case GEN_OP_ARITHMETIC_MUL: verb = "Multiplies"; break;
		case GEN_OP_ARITHMETIC_DIV: verb = "Divides"; break;

		case GEN_OP_ARITHMETIC_COUNT:
		default:
			printf( "ERROR: Bad genOpArithmetic_t enum passed into %s.\n", __FUNCTION__ );
			return std::string();
	}

	return "/// \\relates " + fullTypeName + "\n" \
		"/// \\brief " + verb + " each component of the matrix by the given scalar value.\n";
}

static std::string GetDocOperatorArithmeticRhsType( const std::string& fullTypeName, const genType_t type, const uint32_t numRows, const uint32_t numCols, const genOpArithmetic_t op ) {
	std::string adjective;
	switch ( op ) {
		case GEN_OP_ARITHMETIC_ADD: adjective = "added"; break;
		case GEN_OP_ARITHMETIC_SUB: adjective = "subtracted"; break;
		case GEN_OP_ARITHMETIC_MUL: adjective = "multiplied"; break;
		case GEN_OP_ARITHMETIC_DIV: adjective = "divided"; break;

		case GEN_OP_ARITHMETIC_COUNT:
		default:
			printf( "ERROR: Bad genOpArithmetic_t enum passed into %s.\n", __FUNCTION__ );
			return std::string();
	}

	switch ( op ) {
		case GEN_OP_ARITHMETIC_MUL:
			return "/// \\relates " + fullTypeName + "\n" \
				"/// \\brief Returns a copy of the matrix where each row of the left-hand matrix has been dot-producted by the corresponding column of the right-hand matrix.\n";

		case GEN_OP_ARITHMETIC_DIV: {
			if ( numRows == numCols && Gen_IsFloatingPointType( type ) ) {
				return "/// \\relates " + fullTypeName + "\n" \
					"/// \\brief Returns a copy of the matrix where the left-hand matrix has been mathematically multiplied by the inverse of the right-hand matrix.\n";
			} else {
				return "/// \\relates " + fullTypeName + "\n" \
					"/// \\brief Returns a copy of the matrix that has been component-wise " + adjective + " by the other matrix.\n";
			}
		}

		case GEN_OP_ARITHMETIC_ADD:
		case GEN_OP_ARITHMETIC_SUB:
			return "/// \\relates " + fullTypeName + "\n" \
				"/// \\brief Returns a copy of the matrix that has been component-wise " + adjective + " by the other matrix.\n";

		case GEN_OP_ARITHMETIC_COUNT:
		default:
			printf( "ERROR: Bad genOpArithmetic_t enum passed into %s.\n", __FUNCTION__ );
			return std::string();
	}
}

static std::string GetDocOperatorRelational( const std::string& fullTypeName, const uint32_t numRows, const uint32_t numCols, const genOpRelational_t op ) {
	std::string noun;
	switch ( op ) {
		case GEN_OP_RELATIONAL_LESS: noun = "less than"; break;
		case GEN_OP_RELATIONAL_LESS_EQUAL: noun = "less than"; break;
		case GEN_OP_RELATIONAL_GREATER: noun = "less than"; break;
		case GEN_OP_RELATIONAL_GREATER_EQUAL: noun = "less than"; break;

		case GEN_OP_RELATIONAL_COUNT:
		default:
			printf( "ERROR: Bad genOpRelational_t enum passed into %s.\n", __FUNCTION__ );
			return std::string();
	}

	return "/// \\relates " + fullTypeName + "\n" \
		"/// \\brief Returns a bool" + std::to_string( numRows ) + "x" + std::to_string( numCols ) \
		+ " where each component is true if the component of the left-hand vector is " + noun + " than the corresponding rhs-hand vector component.\n";
}

static std::string GetDocIdentity( const std::string& fullTypeName ) {
	return "/// \\relates " + fullTypeName + "\n" \
		"/// \\brief Sets the matrix to an identity matrix.\n";
}

static std::string GetDocTranpose( const std::string& fullTypeName ) {
	return "/// \\relates " + fullTypeName + "\n" \
		"/// \\brief Returns a copy of the matrix that is transposed, where the value of each row is set to the value of each column and vice versa.\n";
}

static std::string GetDocInverse( const std::string& fullTypeName ) {
	return "/// \\relates " + fullTypeName + "\n" \
		"/// \\brief Returns a copy of the matrix that is inversed.\n" \
		"/// Currently this is only applicable for square matrices.  Pseudo-inverse support for non-square matrices is coming soon.\n";
}

static std::string GetDocDeterminant( const std::string& fullTypeName ) {
	return "/// \\relates " + fullTypeName + "\n" \
		"/// \\brief Returns the determinant of the matrix.\n";
}

static std::string GetDocTranslate( const std::string& fullTypeName ) {
	return "/// \\relates " + fullTypeName + "\n" \
		"/// \\brief Returns a copy of the matrix where each component of the 3rd column has been added by the given vector.\n";
}

static std::string GetDocRotate( const std::string& fullTypeName ) {
	return "/// \\relates " + fullTypeName + "\n" \
		"/// \\brief Returns a copy of the matrix that has had a rotation applied to it in radians on one or more of the following axes.\n";
}

static std::string GetDocScaleUniform( const std::string& fullTypeName ) {
	return "/// \\relates " + fullTypeName + "\n" \
		"/// \\brief Returns a copy of the matrix that has had a uniform scale applied to it.\n";
}

static std::string GetDocScaleNonUniform( const std::string& fullTypeName ) {
	return "/// \\relates " + fullTypeName + "\n" \
		"/// \\brief Returns a copy of the matrix that has had a non-uniform scale applied to it.\n";
}

static std::string GetDocOrtho( const std::string& fullTypeName ) {
	return "/// \\relates " + fullTypeName + "\n" \
		"/// \\brief Returns an orthographic projection matrix.\n";
}

static std::string GetDocPerspective( const std::string& fullTypeName ) {
	return "/// \\relates " + fullTypeName + "\n" \
		"/// \\brief Returns a perspective projection matrix based on a vertical field-of-view in degrees and an aspect ratio.\n";
}

static std::string GetDocLookAt( const std::string& fullTypeName ) {
	return "/// \\relates " + fullTypeName + "\n" \
		"/// \\brief Returns a orthonormal matrix that is oriented at position eye to look at position target.\n";
}

std::string Gen_GetParmListMatrix( const genType_t type, const uint32_t numRows, const uint32_t numCols, const float values[GEN_COMPONENT_COUNT_MAX][GEN_COMPONENT_COUNT_MAX] ) {
	assert( numRows >= GEN_COMPONENT_COUNT_MIN );
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );

	std::string parmList = "(\n";
	for ( uint32_t row = 0; row < numRows; row++ ) {
		parmList += "\t\t";

		for ( uint32_t col = 0; col < numCols; col++ ) {
			parmList += Gen_GetNumericLiteral( type, values[row][col] );

			if ( row + col != ( numRows - 1 ) + ( numCols - 1 ) ) {
				parmList += ",";
			}

			if ( col != numCols - 1 ) {
				parmList += " ";
			}
		}

		parmList += "\n";
	}
	parmList += "\t)";

	return parmList;
}

std::string Gen_GetParmListMatrixIdentity( const genType_t type, const uint32_t numRows, const uint32_t numCols ) {
	assert( numRows >= GEN_COMPONENT_COUNT_MIN );
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );

	float values[] = { 1.0f, 1.0f, 1.0f, 1.0f };

	return Gen_GetParmListMatrixDiagonal( type, numRows, numCols, values, __min( numRows, numCols ) );
}

std::string Gen_GetParmListMatrixDiagonal( const genType_t type, const uint32_t numRows, const uint32_t numCols, const float* values, const uint32_t numValues ) {
	assert( numRows >= GEN_COMPONENT_COUNT_MIN );
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );

	assert( numValues <= 4 );

	std::string zeroStr = Gen_GetNumericLiteral( type, 0.0f );

	uint32_t valueIndex = 0;

	std::string paramList = "(\n";
	for ( uint32_t row = 0; row < numRows; row++ ) {
		paramList += "\t\t";

		for ( uint32_t col = 0; col < numCols; col++ ) {
			if ( row == col ) {
				paramList += Gen_GetNumericLiteral( type, values[valueIndex++] );
			} else {
				paramList += zeroStr;
			}

			if ( row + col != ( numRows - 1 ) + ( numCols - 1 ) ) {
				paramList += ",";
			}

			if ( col != numCols - 1 ) {
				paramList += " ";
			}
		}

		paramList += "\n";
	}
	paramList += "\t)";

	return paramList;
}

std::string Gen_GetParmListMatrixSingleValue( const genType_t type, const uint32_t numRows, const uint32_t numCols, const float value ) {
	assert( numRows >= GEN_COMPONENT_COUNT_MIN );
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );

	std::string valueStr = Gen_GetNumericLiteral( type, value );

	std::string paramList = "(\n";
	for ( uint32_t row = 0; row < numRows; row++ ) {
		paramList += "\t\t";

		for ( uint32_t col = 0; col < numCols; col++ ) {
			paramList += valueStr;

			if ( row + col != ( numRows - 1 ) + ( numCols - 1 ) ) {
				paramList += ",";
			}

			if ( col != numCols - 1 ) {
				paramList += " ";
			}
		}

		paramList += "\n";
	}
	paramList += "\t)";

	return paramList;
}

static std::string HeaderGetArithmeticFuncScalar( const genType_t type, const uint32_t numRows, const uint32_t numCols, const genOpArithmetic_t op ) {
	assert( numRows >= GEN_COMPONENT_COUNT_MIN );
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );

	std::string fullTypeName = Gen_GetTypeString( type ) + std::to_string( numRows ) + "x" + std::to_string( numCols );
	std::string memberTypeString = Gen_GetMemberTypeString( type );

	std::string code;

	code += GetDocOperatorArithmeticScalar( fullTypeName, op );
	code += "inline " + fullTypeName + " operator" + GEN_OPERATORS_ARITHMETIC[op] + "( const " + fullTypeName + "& lhs, const " + memberTypeString + " rhs );\n";
	code += "\n";

	code += GetDocOperatorCompoundArithmeticScalar( fullTypeName, op );
	code += "inline " + fullTypeName + " operator" + GEN_OPERATORS_ARITHMETIC[op] + "=( " + fullTypeName + "& lhs, const " + memberTypeString + " rhs );\n";
	code += "\n";

	return code;
}

static std::string InlGetArithmeticFuncScalar( const genType_t type, const uint32_t numRows, const uint32_t numCols, const genOpArithmetic_t op ) {
	assert( numRows >= GEN_COMPONENT_COUNT_MIN );
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );

	char opStr = GEN_OPERATORS_ARITHMETIC[op];

	std::string fullTypeName = Gen_GetTypeString( type ) + std::to_string( numRows ) + "x" + std::to_string( numCols );
	std::string memberTypeString = Gen_GetMemberTypeString( type );

	std::string code;

	// main arithmetic func
	code += fullTypeName + " " + "operator" + opStr + "( const " + fullTypeName + "& lhs, const " + memberTypeString + " rhs ) {\n";
	code += "\treturn " + fullTypeName + "(\n";
	for ( uint32_t row = 0; row < numRows; row++ ) {
		code += "\t\tlhs[" + std::to_string( row ) + "] " + opStr + " rhs";
		if ( row != numRows - 1 ) {
			code += ",";
		}
		code += "\n";
	}
	code += "\t);\n";
	code += "}\n";
	code += "\n";

	// compound arithmetic func
	code += fullTypeName + " " + "operator" + opStr + "=( " + fullTypeName + "& lhs, const " + memberTypeString + " rhs ) {\n";
	code += std::string( "\treturn ( lhs = lhs " ) + opStr + " rhs );\n";
	code += "}\n";
	code += "\n";

	return code;
}

static std::string HeaderGetArithmeticFuncRhsType( const genType_t type, const uint32_t numRows, const uint32_t numCols, const genOpArithmetic_t op ) {
	assert( numRows >= GEN_COMPONENT_COUNT_MIN );
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );

	std::string numRowsStr = std::to_string( numRows );
	std::string numColsStr = std::to_string( numCols );

	std::string typeString = Gen_GetTypeString( type );
	std::string fullTypeName = typeString + numRowsStr + "x" + numColsStr;
	std::string transposedTypeName = typeString + numColsStr + "x" + numRowsStr;

	std::string returnTypeName = typeString + numRowsStr + "x";
	if ( op == GEN_OP_ARITHMETIC_MUL ) {
		returnTypeName += numRowsStr;
	} else {
		returnTypeName += numColsStr;
	}

	std::string rhsTypeName = ( op == GEN_OP_ARITHMETIC_MUL ) ? transposedTypeName : fullTypeName;

	std::string code;

	code += GetDocOperatorArithmeticRhsType( fullTypeName, type, numRows, numCols, op );
	code += "inline " + returnTypeName + " operator" + GEN_OPERATORS_ARITHMETIC[op] + "( const " + fullTypeName + "& lhs, const " + rhsTypeName + "& rhs );\n";
	code += "\n";

	// DM!!! FIXME!
//	code += GetDocOperatorCompoundArithmeticRhsType( type, numRows, numCols, op );
//	code += "inline " + returnTypeName + " operator" + GEN_OPERATORS_ARITHMETIC[op] + "=( " + fullTypeName + "& lhs, const " + rhsTypeName + "& rhs );\n";
//	code += "\n";

	return code;
}

static std::string InlGetArithmeticFuncRhsType( const genType_t type, const uint32_t numRows, const uint32_t numCols, const genOpArithmetic_t op ) {
	assert( numRows >= GEN_COMPONENT_COUNT_MIN );
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );

	std::string numRowsStr = std::to_string( numRows );
	std::string numColsStr = std::to_string( numCols );

	std::string typeString = Gen_GetTypeString( type );
	std::string fullTypeName = typeString + numRowsStr + "x" + numColsStr;
	std::string transposedTypeName = typeString + numColsStr + "x" + numRowsStr;

	std::string returnTypeName = typeString + numRowsStr + "x";
	if ( op == GEN_OP_ARITHMETIC_MUL ) {
		returnTypeName += numRowsStr;
	} else {
		returnTypeName += numColsStr;
	}

	std::string rhsTypeName = ( op == GEN_OP_ARITHMETIC_MUL ) ? transposedTypeName : fullTypeName;

	char opStr = GEN_OPERATORS_ARITHMETIC[op];

	// the default arithmetic code, which does a component-wise operation between the lhs/rhs parms
	std::string defaultArithmeticCode = "\treturn " + fullTypeName + "(\n";
	for ( uint32_t row = 0; row < numRows; row++ ) {
		std::string rowStr = std::to_string( row );

		defaultArithmeticCode += "\t\tlhs[" + rowStr + "] " + opStr + " rhs[" + rowStr + "]";

		if ( row != numRows - 1 ) {
			defaultArithmeticCode += ",";
		}

		defaultArithmeticCode += "\n";
	}
	defaultArithmeticCode += "\t);\n";

	std::string code;
	code += returnTypeName + " operator" + opStr + "( const " + fullTypeName + "& lhs, const " + rhsTypeName + "& rhs ) {\n";

	// main arithmetic func
	switch ( op ) {
		case GEN_OP_ARITHMETIC_ADD:
		case GEN_OP_ARITHMETIC_SUB: {
			code += defaultArithmeticCode;
			break;
		}

		case GEN_OP_ARITHMETIC_MUL: {
			uint32_t numRhsRows = numCols;
			uint32_t numRhsCols = numRows;

			// generate row vars
			for ( uint32_t row = 0; row < numRows; row++ ) {
				std::string rowStr = std::to_string( row );
				code += "\t" + typeString + numColsStr + " row" + rowStr + " = lhs[" + rowStr + "];\n";
			}

			code += "\n";

			// generate col vars
			for ( uint32_t col = 0; col < numRhsCols; col++ ) {
				code += "\t" + typeString + numColsStr + " col" + std::to_string( col ) + " = { ";
				for ( uint32_t rhsRow = 0; rhsRow < numRhsRows; rhsRow++ ) {
					code += "rhs[" + std::to_string( rhsRow ) + "]." + GEN_COMPONENT_NAMES_VECTOR[col];

					if ( rhsRow != numCols - 1 ) {
						code += ", ";
					}
				}

				code += " };\n";
			}
			code += "\n";

			// now do the row/col dot products
			code += "\treturn " + returnTypeName + "(\n";

			for ( uint32_t row = 0; row < numRows; row++ ) {
				std::string rowStr = std::to_string( row );

				for ( uint32_t col = 0; col < numRows; col++ ) {
					std::string colStr = std::to_string( col );

					code += "\t\t";

					for ( uint32_t rhsRow = 0; rhsRow < numRhsRows; rhsRow++ ) {
						code += "row" + rowStr + "." + GEN_COMPONENT_NAMES_VECTOR[rhsRow] + " * " + "col" + colStr + "." + GEN_COMPONENT_NAMES_VECTOR[rhsRow];

						if ( rhsRow != numRhsRows - 1 ) {
							code += " + ";
						} else {
							if ( col + ( row * numRows ) != ( numRows * numRows ) - 1 ) {
								code += ",";
							}

							code += "\n";
						}
					}
				}

				if ( row != numRows - 1 ) {
					code += "\n";
				}
			}
			code += "\t);\n";

			break;
		}

		case GEN_OP_ARITHMETIC_DIV: {
			if ( numRows == numCols && Gen_IsFloatingPointType( type ) ) {
				code += "\treturn lhs * inverse( rhs );\n";
			} else {
				code += defaultArithmeticCode;
			}

			break;
		}

		case GEN_OP_ARITHMETIC_COUNT:
			printf( "ERROR: Bad arithmetic op passed into %s.\n", __FUNCTION__ );
			break;

		default:
			// nothing
			break;
	}
	code += "}\n";
	code += "\n";

	// DM!!!FIXME!
	// compound arithmetic func
//	code += returnTypeName + " operator" + opStr + "=( " + fullTypeName + "& lhs, const " + fullTypeName + "& rhs ) {\n";
//	code += std::string( "\treturn ( lhs = lhs " ) + opStr + " rhs );\n";
//	code += "}\n";
//	code += "\n";

	return code;
}

static std::string HeaderGetOperatorRelational( const genType_t type, const uint32_t numRows, const uint32_t numCols, const genOpRelational_t op ) {
	assert( numRows >= GEN_COMPONENT_COUNT_MIN );
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );

	std::string numRowsStr = std::to_string( numRows );
	std::string numColsStr = std::to_string( numCols );

	std::string fullTypeName = Gen_GetTypeString( type ) + numRowsStr + "x" + numColsStr;
	std::string boolTypeName = "bool" + numRowsStr + "x" + numColsStr;

	std::string code;

	code += GetDocOperatorRelational( fullTypeName, numRows, numCols, op );
	code += "inline " + boolTypeName + " operator" + GEN_OPERATORS_RELATIONAL[op] + "( const " + fullTypeName + "& lhs, const " + fullTypeName + "& rhs );\n";
	code += "\n";

	return code;
}

static std::string InlGetOperatorRelational( const genType_t type, const uint32_t numRows, const uint32_t numCols, const genOpRelational_t op ) {
	assert( numRows >= GEN_COMPONENT_COUNT_MIN );
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );

	std::string numRowsStr = std::to_string( numRows );
	std::string numColsStr = std::to_string( numCols );

	std::string fullTypeName = Gen_GetTypeString( type ) + numRowsStr + "x" + numColsStr;
	std::string boolTypeName = "bool" + numRowsStr + "x" + numColsStr;

	std::string code;

	code += boolTypeName + " operator" + GEN_OPERATORS_RELATIONAL[op] + "( const " + fullTypeName + "& lhs, const " + fullTypeName + "& rhs ) {\n";
	code += "\treturn " + boolTypeName + "(\n";

	for ( uint32_t row = 0; row < numRows; row++ ) {
		std::string rowStr = std::to_string( row );

		code += "\t\tlhs[" + rowStr + "] " + GEN_OPERATORS_RELATIONAL[op] + " rhs[" + rowStr + "]";

		if ( row != numRows - 1 ) {
			code += ",";
		}

		code += "\n";
	}
	code += "\t);\n";
	code += "}\n";

	code += "\n";

	return code;
}


void Gen_MatrixOperatorsArithmetic( const genType_t type, const uint32_t numRows, const uint32_t numCols, std::string& outHeader, std::string& outInl ) {
	assert( numRows >= GEN_COMPONENT_COUNT_MIN );
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );

	if ( type == GEN_TYPE_BOOL ) {
		return;
	}

	for ( uint32_t opIndex = 0; opIndex < GEN_OP_ARITHMETIC_COUNT; opIndex++ ) {
		genOpArithmetic_t op = static_cast<genOpArithmetic_t>( opIndex );

		outHeader += HeaderGetArithmeticFuncScalar( type, numRows, numCols, op );
		outHeader += HeaderGetArithmeticFuncRhsType( type, numRows, numCols, op );

		outInl += InlGetArithmeticFuncScalar( type, numRows, numCols, op );
		outInl += InlGetArithmeticFuncRhsType( type, numRows, numCols, op );
	}
}

void Gen_MatrixOperatorsRelational( const genType_t type, const uint32_t numRows, const uint32_t numCols, std::string& outHeader, std::string& outInl ) {
	assert( numRows >= GEN_COMPONENT_COUNT_MIN );
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );

	if ( type == GEN_TYPE_BOOL ) {
		return;
	}

	for ( uint32_t opIndex = 0; opIndex < GEN_OP_RELATIONAL_COUNT; opIndex++ ) {
		genOpRelational_t op = static_cast<genOpRelational_t>( opIndex );

		outHeader += HeaderGetOperatorRelational( type, numRows, numCols, op );

		outInl += InlGetOperatorRelational( type, numRows, numCols, op );
	}
}

void Gen_MatrixIdentity( const genType_t type, const uint32_t numRows, const uint32_t numCols, std::string& outHeader, std::string& outInl ) {
	assert( numRows >= GEN_COMPONENT_COUNT_MIN );
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );

	std::string fullTypeName = Gen_GetTypeString( type ) + std::to_string( numRows ) + "x" + std::to_string( numCols );

	outHeader += GetDocIdentity( fullTypeName );
	outHeader += "inline void identity( " + fullTypeName + "& mat );\n";
	outHeader += "\n";

	outInl += "void identity( " + fullTypeName + "& mat ) {\n";
	for ( uint32_t row = 0; row < numRows; row++ ) {
		outInl += "\tmat[" + std::to_string( row ) + "] = { ";
		for ( uint32_t col = 0; col < numCols; col++ ) {
			outInl += ( row == col ) ? "1" : "0";

			if ( col != numCols - 1 ) {
				outInl += ", ";
			}
		}
		outInl += " };\n";
	}
	outInl += "}\n";
	outInl += "\n";
}

void Gen_MatrixTranspose( const genType_t type, const uint32_t numRows, const uint32_t numCols, std::string& outHeader, std::string& outInl ) {
	assert( numRows >= GEN_COMPONENT_COUNT_MIN );
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );

	std::string typeString = Gen_GetTypeString( type );
	std::string fullTypeName = typeString + std::to_string( numRows ) + "x" + std::to_string( numCols );
	std::string transposeTypeName = typeString + std::to_string( numCols ) + "x" + std::to_string( numRows );

	outHeader += GetDocTranpose( fullTypeName );
	outHeader += "inline " + transposeTypeName + " transpose( const " + fullTypeName + "& mat );\n";
	outHeader += "\n";

	outInl += transposeTypeName + " transpose( const " + fullTypeName + "& mat ) {\n";
	outInl += "\treturn " + transposeTypeName + "(\n";

	for ( uint32_t col = 0; col < numCols; col++ ) {
		std::string colStr = std::to_string( col );

		outInl += "\t\t";

		for ( uint32_t row = 0; row < numRows; row++ ) {
			std::string rowStr = std::to_string( row );

			outInl += "mat[" + rowStr + "][" + colStr + "]";

			if ( row + col != ( numRows - 1 ) + ( numCols - 1 ) ) {
				outInl += ",";
			}

			if ( row != numRows - 1 ) {
				outInl += " ";
			} else {
				outInl += "\n";
			}
		}
	}
	outInl += "\t);\n";
	outInl += "}\n";
	outInl += "\n";
}

void Gen_MatrixInverse( const genType_t type, const uint32_t numRows, const uint32_t numCols, std::string& outHeader, std::string& outInl ) {
	assert( numRows >= GEN_COMPONENT_COUNT_MIN );
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );

	if ( !Gen_IsFloatingPointType( type ) ) {
		return;
	}

	// true inverse can only be done for NxN matrices
	// only pseudo-inverse can be done for NxM matrices where N != M
	if ( numRows != numCols ) {
		return;
	}

	std::string typeString = Gen_GetTypeString( type );
	std::string memberTypeString = Gen_GetMemberTypeString( type );
	std::string vectorTypeName = typeString + std::to_string( numCols );
	std::string fullTypeName = typeString + std::to_string( numRows ) + "x" + std::to_string( numCols );

	std::string literalOneStr = Gen_GetNumericLiteral( type, 1 );

	outHeader += GetDocInverse( fullTypeName );
	outHeader += "inline " + fullTypeName + " inverse( const " + fullTypeName + "& mat );\n";
	outHeader += "\n";

	outInl += fullTypeName + " inverse( const " + fullTypeName + "& mat ) {\n";

	switch ( numRows ) {
		case 2: {
			outInl += "\tconst " + memberTypeString + " invdet = " + literalOneStr + " / determinant( mat );\n";
			outInl += "\treturn " + fullTypeName + "(\n";
			outInl += "\t\t mat[1][1] * invdet, -mat[0][1] * invdet,\n";
			outInl += "\t\t-mat[1][0] * invdet,  mat[0][0] * invdet\n";
			outInl += "\t);\n";
			break;
		}

		case 3: {
			outInl += "\tconst " + memberTypeString + " invdet = " + literalOneStr + " / determinant( mat );\n";
			outInl += "\treturn " + fullTypeName + "(\n";
			outInl += "\t\t ( mat[1][1] * mat[2][2] - mat[1][2] * mat[2][1] ) * invdet,\n";
			outInl += "\t\t-( mat[0][1] * mat[2][2] - mat[0][2] * mat[2][1] ) * invdet,\n";
			outInl += "\t\t ( mat[0][1] * mat[1][2] - mat[0][2] * mat[1][1] ) * invdet,\n";
			outInl += "\n";
			outInl += "\t\t-( mat[1][0] * mat[2][2] - mat[1][2] * mat[2][0] ) * invdet,\n";
			outInl += "\t\t ( mat[0][0] * mat[2][2] - mat[0][2] * mat[2][0] ) * invdet,\n";
			outInl += "\t\t-( mat[0][0] * mat[1][2] - mat[0][2] * mat[1][0] ) * invdet,\n";
			outInl += "\n";
			outInl += "\t\t ( mat[1][0] * mat[2][1] - mat[1][1] * mat[2][0] ) * invdet,\n";
			outInl += "\t\t-( mat[0][0] * mat[2][1] - mat[0][1] * mat[2][0] ) * invdet,\n";
			outInl += "\t\t ( mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0] ) * invdet\n";
			outInl += "\t);\n";
			break;
		}

		case 4: {
			outInl += "\t// uses the glm version, which is basically just an optimised version of the adjugate formula\n";
			outInl += "\t" + memberTypeString + " sub00 = mat[2][2] * mat[3][3] - mat[3][2] * mat[2][3];\n";
			outInl += "\t" + memberTypeString + " sub01 = mat[1][2] * mat[3][3] - mat[1][3] * mat[2][3];\n";
			outInl += "\t" + memberTypeString + " sub02 = mat[1][2] * mat[2][3] - mat[1][3] * mat[2][2];\n";
			outInl += "\n";
			outInl += "\t" + memberTypeString + " sub03 = mat[2][1] * mat[3][3] - mat[2][3] * mat[3][1];\n";
			outInl += "\t" + memberTypeString + " sub04 = mat[1][1] * mat[3][3] - mat[1][3] * mat[3][1];\n";
			outInl += "\t" + memberTypeString + " sub05 = mat[1][1] * mat[2][3] - mat[1][3] * mat[2][1];\n";
			outInl += "\n";
			outInl += "\t" + memberTypeString + " sub06 = mat[2][1] * mat[3][2] - mat[2][2] * mat[3][1];\n";
			outInl += "\t" + memberTypeString + " sub07 = mat[1][1] * mat[3][2] - mat[1][2] * mat[3][1];\n";
			outInl += "\t" + memberTypeString + " sub08 = mat[1][1] * mat[2][2] - mat[1][2] * mat[2][1];\n";
			outInl += "\n";
			outInl += "\t" + memberTypeString + " sub09 = mat[2][0] * mat[3][3] - mat[3][0] * mat[2][3];\n";
			outInl += "\t" + memberTypeString + " sub10 = mat[1][0] * mat[3][3] - mat[3][0] * mat[1][3];\n";
			outInl += "\t" + memberTypeString + " sub11 = mat[1][0] * mat[2][3] - mat[2][0] * mat[1][3];\n";
			outInl += "\n";
			outInl += "\t" + memberTypeString + " sub12 = mat[2][0] * mat[3][2] - mat[2][2] * mat[3][0];\n";
			outInl += "\t" + memberTypeString + " sub13 = mat[1][0] * mat[3][2] - mat[1][2] * mat[3][0];\n";
			outInl += "\t" + memberTypeString + " sub14 = mat[1][0] * mat[2][2] - mat[1][2] * mat[2][0];\n";
			outInl += "\n";
			outInl += "\t" + memberTypeString + " sub15 = mat[2][0] * mat[3][1] - mat[2][1] * mat[3][0];\n";
			outInl += "\t" + memberTypeString + " sub16 = mat[1][0] * mat[3][1] - mat[1][1] * mat[3][0];\n";
			outInl += "\t" + memberTypeString + " sub17 = mat[1][0] * mat[2][1] - mat[1][1] * mat[2][0];\n";
			outInl += "\n";
			outInl += "\t" + vectorTypeName + " fac0 = " + vectorTypeName + "( sub00, sub00, sub01, sub02 );\n";
			outInl += "\t" + vectorTypeName + " fac1 = " + vectorTypeName + "( sub03, sub03, sub04, sub05 );\n";
			outInl += "\t" + vectorTypeName + " fac2 = " + vectorTypeName + "( sub06, sub06, sub07, sub08 );\n";
			outInl += "\t" + vectorTypeName + " fac3 = " + vectorTypeName + "( sub09, sub09, sub10, sub11 );\n";
			outInl += "\t" + vectorTypeName + " fac4 = " + vectorTypeName + "( sub12, sub12, sub13, sub14 );\n";
			outInl += "\t" + vectorTypeName + " fac5 = " + vectorTypeName + "( sub15, sub15, sub16, sub17 );\n";
			outInl += "\n";
			outInl += "\t" + vectorTypeName + " vec0 = " + vectorTypeName + "( mat[1][0], mat[0][0], mat[0][0], mat[0][0] );\n";
			outInl += "\t" + vectorTypeName + " vec1 = " + vectorTypeName + "( mat[1][1], mat[0][1], mat[0][1], mat[0][1] );\n";
			outInl += "\t" + vectorTypeName + " vec2 = " + vectorTypeName + "( mat[1][2], mat[0][2], mat[0][2], mat[0][2] );\n";
			outInl += "\t" + vectorTypeName + " vec3 = " + vectorTypeName + "( mat[1][3], mat[0][3], mat[0][3], mat[0][3] );\n";
			outInl += "\n";
			outInl += "\t" + vectorTypeName + " inv0 = vec1 * fac0 - vec2 * fac1 + vec3 * fac2;\n";
			outInl += "\t" + vectorTypeName + " inv1 = vec0 * fac0 - vec2 * fac3 + vec3 * fac4;\n";
			outInl += "\t" + vectorTypeName + " inv2 = vec0 * fac1 - vec1 * fac3 + vec3 * fac5;\n";
			outInl += "\t" + vectorTypeName + " inv3 = vec0 * fac2 - vec1 * fac4 + vec2 * fac5;\n";
			outInl += "\n";
			outInl += "\t" + vectorTypeName + " sign0 = " + vectorTypeName + "(  1, -1,  1, -1 );\n";
			outInl += "\t" + vectorTypeName + " sign1 = " + vectorTypeName + "( -1,  1, -1,  1 );\n";
			outInl += "\n";
			outInl += "\t" + fullTypeName + " result = " + fullTypeName + "(\n";
			outInl += "\t\tinv0 * sign0,\n";
			outInl += "\t\tinv1 * sign1,\n";
			outInl += "\t\tinv2 * sign0,\n";
			outInl += "\t\tinv3 * sign1\n";
			outInl += "\t);\n";
			outInl += "\n";
			outInl += "\t" + vectorTypeName + " col0 = " + vectorTypeName + "( result[0][0], result[1][0], result[2][0], result[3][0] );\n";
			outInl += "\t" + vectorTypeName + " dot0 = mat[0] * col0;\n";
			outInl += "\n";
			outInl += "\tconst " + memberTypeString + " dot1 = ( dot0.x + dot0.y ) + ( dot0.z + dot0.w );\n";
			outInl += "\n";
			outInl += "\tconst " + memberTypeString + " invdet = " + literalOneStr + " / dot1;\n";
			outInl += "\n";
			outInl += "\treturn result * invdet;\n";
			break;
		}
	}
	outInl += "}\n";
	outInl += "\n";
}

void Gen_MatrixDeterminant( const genType_t type, const uint32_t numRows, const uint32_t numCols, std::string& outHeader, std::string& outInl ) {
	assert( numRows >= GEN_COMPONENT_COUNT_MIN );
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );

	if ( type == GEN_TYPE_BOOL || type == GEN_TYPE_UINT ) {
		return;
	}

	if ( numRows != numCols ) {
		return;
	}

	std::string typeString = Gen_GetTypeString( type );
	std::string memberTypeString = Gen_GetMemberTypeString( type );
	std::string vectorTypeName = typeString + std::to_string( numCols );
	std::string fullTypeName = typeString + std::to_string( numRows ) + "x" + std::to_string( numCols );

	outHeader += GetDocDeterminant( fullTypeName );
	outHeader += "inline " + memberTypeString + " determinant( const " + fullTypeName + "& mat );\n";
	outHeader += "\n";

	outInl += memberTypeString + " determinant( const " + fullTypeName + "& mat ) {\n";
	switch ( numRows ) {
		case 2: {
			outInl += "\treturn mat[0][0] * mat[1][1] - mat[1][0] * mat[0][1];\n";
			break;
		}

		case 3: {
			outInl += "\treturn\n";
			outInl += "\t\t+ mat[0][0] * ( mat[1][1] * mat[2][2] - mat[2][1] * mat[1][2] )\n";
			outInl += "\t\t- mat[0][1] * ( mat[1][0] * mat[2][2] - mat[2][0] * mat[1][2] )\n";
			outInl += "\t\t+ mat[0][2] * ( mat[1][0] * mat[2][1] - mat[2][0] * mat[1][1] );\n";
			break;
		}

		case 4: {
			outInl += "\t// using glm's method where you basically take determinants from each sub matrix and cache the repeat occurences\n";
			outInl += "\t" + memberTypeString + " sub00 = mat[2][2] * mat[3][3] - mat[3][2] * mat[2][3];\n";
			outInl += "\t" + memberTypeString + " sub01 = mat[2][1] * mat[3][3] - mat[2][3] * mat[3][1];\n";
			outInl += "\t" + memberTypeString + " sub02 = mat[2][1] * mat[3][2] - mat[3][1] * mat[2][2];\n";
			outInl += "\t" + memberTypeString + " sub03 = mat[2][0] * mat[3][3] - mat[3][0] * mat[2][3];\n";
			outInl += "\t" + memberTypeString + " sub04 = mat[2][0] * mat[3][2] - mat[3][0] * mat[2][2];\n";
			outInl += "\t" + memberTypeString + " sub05 = mat[2][0] * mat[3][1] - mat[3][0] * mat[2][1];\n";
			outInl += "\n";
			outInl += "\t" + vectorTypeName + " cofactor = " + vectorTypeName + "(\n";
			outInl += "\t\t ( mat[1][1] * sub00 - mat[1][2] * sub01 + mat[1][3] * sub02 ),\n";
			outInl += "\t\t-( mat[1][0] * sub00 - mat[1][2] * sub03 + mat[1][3] * sub04 ),\n";
			outInl += "\t\t ( mat[1][0] * sub01 - mat[1][1] * sub03 + mat[1][3] * sub05 ),\n";
			outInl += "\t\t-( mat[1][0] * sub02 - mat[1][1] * sub04 + mat[1][2] * sub05 )\n";
			outInl += "\t);\n";
			outInl += "\n";
			outInl += "\treturn\n";
			outInl += "\t\tmat[0][0] * cofactor.x + mat[0][1] * cofactor.y +\n";
			outInl += "\t\tmat[0][2] * cofactor.z + mat[0][3] * cofactor.w;\n";
			break;
		}
	}
	outInl += "}\n";
	outInl += "\n";
}

void Gen_MatrixTranslate( const genType_t type, const uint32_t numRows, const uint32_t numCols, std::string& outHeader, std::string& outInl ) {
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );

	if ( type == GEN_TYPE_BOOL ) {
		return;
	}

	if ( numRows < 3 || numCols < numRows ) {
		return;
	}

	uint32_t vecComponents = numCols - 1;

	std::string typeString = Gen_GetTypeString( type );
	std::string fullTypeName = typeString + std::to_string( numRows ) + "x" + std::to_string( numCols );

	outHeader += GetDocTranslate( fullTypeName );
	outHeader += "inline " + fullTypeName + " translate( const " + fullTypeName + "& mat, const " + typeString + std::to_string( vecComponents ) + "& vec );\n";
	outHeader += "\n";

	outInl += fullTypeName + " translate( const " + fullTypeName + "& mat, const " + typeString + std::to_string( vecComponents ) + "& vec ) {\n";
	outInl += "\treturn " + fullTypeName + "(\n";
	outInl += "\t\t";
	for ( uint32_t row = 0; row < numRows; row++ ) {
		for ( uint32_t col = 0; col < numCols; col++ ) {
			outInl += "mat[" + std::to_string( row ) + "][" + std::to_string( col ) + "]";

			if ( col != numCols - 1 ) {
				outInl += ", ";
			} else {
				if ( col == vecComponents && row < vecComponents ) {
					outInl += std::string( " + vec." ) + GEN_COMPONENT_NAMES_VECTOR[row];
				}

				if ( row != numRows - 1 ) {
					outInl += ",";
				}
			}
		}
		outInl += "\n";

		if ( row != numRows - 1 ) {
			outInl += "\t\t";
		}
	}
	outInl += "\t);\n";
	outInl += "}\n";
	outInl += "\n";
}

void Gen_MatrixRotate( const genType_t type, const uint32_t numRows, const uint32_t numCols, std::string& outHeader, std::string& outInl ) {
	assert( numRows >= GEN_COMPONENT_COUNT_MIN );
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );

	if ( !Gen_IsFloatingPointType( type ) ) {
		return;
	}

	if ( numRows < 3 ) {
		return;
	}

	if ( numRows != numCols ) {
		return;
	}

	uint32_t numRotateVectorComponents = 3;

	std::string typeString = Gen_GetTypeString( type );
	std::string vectorTypeString = Gen_GetTypeString( type ) + std::to_string( numRotateVectorComponents );
	std::string fullTypeName = typeString + std::to_string( numRows ) + "x" + std::to_string( numCols );

	std::string literalOneStr = Gen_GetNumericLiteral( type, 1 );

	std::string parmListStr = "const " + fullTypeName + "& mat, const " + typeString + " rad";
	if ( numCols > 3 ) {
		parmListStr += ", const " + vectorTypeString + "& axis";
	}

	outHeader += GetDocRotate( fullTypeName );
	outHeader += "inline " + fullTypeName + " rotate( " + parmListStr + " );\n";
	outHeader += "\n";

	std::string cosFuncStr = ( type == GEN_TYPE_FLOAT ) ? "cosf" : "cos";
	std::string sinFuncStr = ( type == GEN_TYPE_FLOAT ) ? "sinf" : "sin";

	outInl += fullTypeName + " rotate( " + parmListStr + " ) {\n";
	outInl += "\tconst " + typeString + " c = " + cosFuncStr + "( rad );\n";
	outInl += "\tconst " + typeString + " s = " + sinFuncStr + "( rad );\n";
	outInl += "\n";

	switch ( numCols ) {
		case 3: {
			outInl += "\treturn " + fullTypeName + "(\n";
			outInl += "\t\tmat[0] * c + mat[1] * -s,\n";
			outInl += "\t\tmat[0] * s + mat[1] * c,\n";
			outInl += "\t\tmat[2]\n";
			outInl += "\t);\n";
			break;
		}

		case 4: {
			outInl += "\t" + vectorTypeString + " u = normalized( axis );\n";
			outInl += "\t" + typeString + " ic = " + literalOneStr + " - c;\n";
			outInl += "\n";
			outInl += "\t" + fullTypeName + " rotation = mat;\n";
			outInl += "\trotation[0][0] = c + u.x * ic;\n";
			outInl += "\trotation[0][1] = u.x * u.y * ic - u.z * s;\n";
			outInl += "\trotation[0][2] = u.x * u.z * ic + u.y * s;\n";
			outInl += "\n";
			outInl += "\trotation[1][0] = u.y * u.x * ic + u.z * s;\n";
			outInl += "\trotation[1][1] = c + u.y * ic;\n";
			outInl += "\trotation[1][2] = u.y * u.z * ic - u.x * s;\n";
			outInl += "\n";
			outInl += "\trotation[2][0] = u.z * u.x * ic - u.y * s;\n";
			outInl += "\trotation[2][1] = u.z * u.y * ic + u.x * s;\n";
			outInl += "\trotation[2][2] = c + u.z * ic;\n";
			outInl += "\n";
			outInl += "\treturn mat * rotation;\n";
			break;
		}
	}
	outInl += "}\n";
	outInl += "\n";
}

void Gen_MatrixScale( const genType_t type, const uint32_t numRows, const uint32_t numCols, std::string& outHeader, std::string& outInl ) {
	assert( numRows >= GEN_COMPONENT_COUNT_MIN );
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );

	if ( type == GEN_TYPE_BOOL ) {
		return;
	}

	if ( numCols < 3 && numCols < numRows ) {
		return;
	}

	std::string typeString = Gen_GetTypeString( type );
	std::string memberTypeString = Gen_GetMemberTypeString( type );
	std::string fullTypeName = typeString + std::to_string( numRows ) + "x" + std::to_string( numCols );

	const uint32_t scaleCols = 3;

	std::string scaleVectorString = typeString + std::to_string( scaleCols );

	outHeader += GetDocScaleUniform( fullTypeName );
	outHeader += "inline " + fullTypeName + " scale( const " + fullTypeName + "& mat, const " + memberTypeString + " scalar );\n";
	outHeader += "\n";

	outHeader += GetDocScaleNonUniform( fullTypeName );
	outHeader += "inline " + fullTypeName + " scale( const " + fullTypeName + "& mat, const " + scaleVectorString + "& vec );\n";
	outHeader += "\n";

	outInl += fullTypeName + " scale( const " + fullTypeName + "& mat, const " + memberTypeString + " scalar ) {\n";
	outInl += "\treturn scale( mat, " + scaleVectorString + "( ";
	for ( uint32_t col = 0; col < scaleCols; col++ ) {
		outInl += "scalar";

		if ( col != scaleCols - 1 ) {
			outInl += ", ";
		}
	}
	outInl += " ) );\n";
	outInl += "}\n";
	outInl += "\n";

	outInl += fullTypeName + " scale( const " + fullTypeName + "& mat, const " + scaleVectorString + "& vec ) {\n";
	outInl += "\treturn " + fullTypeName + "(\n";

	for ( uint32_t row = 0; row < numRows; row++ ) {
		std::string rowStr = std::to_string( row );

		for ( uint32_t col = 0; col < numCols; col++ ) {
			std::string colStr = std::to_string( col );

			outInl += "\t\tmat[" + rowStr + "][" + colStr + "]";

			if ( row == col && col < scaleCols ) {
				outInl += std::string( " * vec." ) + GEN_COMPONENT_NAMES_VECTOR[row];
			}

			if ( row + col != ( numRows - 1 ) + ( numCols - 1 ) ) {
				outInl += ",\n";
			} else {
				outInl += "\n";
			}
		}

		if ( row != numRows - 1 ) {
			outInl += "\n";
		}
	}
	outInl += "\t);\n";
	outInl += "}\n";
	outInl += "\n";
}

void Gen_MatrixOrtho( const genHand_t hand, const genType_t type, const uint32_t numRows, const uint32_t numCols, std::string& outHeader, std::string& outInl ) {
	assert( numRows >= GEN_COMPONENT_COUNT_MIN );
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );

	if ( !Gen_IsFloatingPointType( type ) ) {
		return;
	}

	if ( numRows < 4 || numCols < 4 ) {
		return;
	}

	std::string typeString = Gen_GetTypeString( type );
	std::string fullTypeName = typeString + std::to_string( numRows ) + "x" + std::to_string( numCols );

	std::string zeroStr	= Gen_GetNumericLiteral( type, 0 );
	std::string oneStr	= Gen_GetNumericLiteral( type, 1 );
	std::string twoStr	= Gen_GetNumericLiteral( type, 2 );

	outHeader += GetDocOrtho( fullTypeName );
	outHeader += "inline " + fullTypeName + " ortho( const " + typeString + " left, const " + typeString + " right, const " + typeString + " top, const " + typeString + " bottom, const " + typeString + " znear, const " + typeString + " zfar );\n";
	outHeader += "\n";

	outInl += "inline " + fullTypeName + " ortho( const " + typeString + " left, const " + typeString + " right, const " + typeString + " top, const " + typeString + " bottom, const " + typeString + " znear, const " + typeString + " zfar ) {\n";
	switch ( hand ) {
		case GEN_HAND_LEFT: {
			outInl += "\tconst " + typeString + " right_plus_left = right + left;\n";
			outInl += "\tconst " + typeString + " right_minus_left = right - left;\n";
			outInl += "\tconst " + typeString + " top_plus_bottom = top + bottom;\n";
			outInl += "\tconst " + typeString + " top_minus_bottom = top - bottom;\n";
			outInl += "\tconst " + typeString + " far_minus_near = zfar - znear;\n";
			outInl += "\n";
			outInl += "\treturn " + fullTypeName + "(\n";
			outInl += "\t\t" + twoStr + " / right_minus_left, " + zeroStr + ", " + zeroStr + ", -right_plus_left / right_minus_left,\n";
			outInl += "\t\t" + zeroStr + ", " + twoStr + " / top_minus_bottom, " + zeroStr + ", -top_plus_bottom / top_minus_bottom,\n";
			outInl += "\t\t" + zeroStr + ", " + zeroStr + ", " + oneStr + " / far_minus_near, " + "-znear / far_minus_near";
			outInl += ",\n\t\t" + zeroStr + ", " + zeroStr + ", " + zeroStr + ", " + oneStr + "\n";
			outInl += "\t);\n";
			break;
		}

		case GEN_HAND_RIGHT: {
			// TODO(DM):
			break;
		}

		case GEN_HAND_COUNT:
		default:
			printf( "ERROR: Bad genHand_t enum passed into %s.\n", __FUNCTION__ );
			break;
	}
	outInl += "}\n";
	outInl += "\n";
}

void Gen_MatrixPerspective( const genHand_t hand, const genType_t type, const uint32_t numRows, const uint32_t numCols, std::string& outHeader, std::string& outInl ) {
	assert( numRows >= GEN_COMPONENT_COUNT_MIN );
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );

	if ( !Gen_IsFloatingPointType( type ) ) {
		return;
	}

	if ( numRows != 4 || numCols != 4 ) {
		return;
	}

	std::string typeString = Gen_GetTypeString( type );
	std::string fullTypeName = typeString + std::to_string( numRows ) + "x" + std::to_string( numCols );

	std::string zeroStr	= Gen_GetNumericLiteral( type, 0.0f );
	std::string halfStr	= Gen_GetNumericLiteral( type, 0.5f );
	std::string oneStr	= Gen_GetNumericLiteral( type, 1.0f );

	std::string tanFuncStr = Gen_GetFuncNameTan( type );

	outHeader += GetDocPerspective( fullTypeName );
	outHeader += "inline " + fullTypeName + " perspective( const " + typeString + " fovdeg, const " + typeString + " aspect, const " + typeString + " znear, const " + typeString + " zfar );\n";
	outHeader += "\n";

	outInl += fullTypeName + " perspective( const " + typeString + " fovdeg, const " + typeString + " aspect, const " + typeString + " znear, const " + typeString + " zfar ) {\n";
	switch ( hand ) {
		case GEN_HAND_LEFT: {
			outInl += "\tconst " + typeString + " far_minus_near = zfar - znear;\n";
			outInl += "\tconst " + typeString + " tan_half_fov = " + tanFuncStr + "( fovdeg * " + halfStr + " );\n";
			outInl += "\n";
			outInl += "\treturn " + fullTypeName + "(\n";
			outInl += "\t\t" + oneStr + " / ( aspect * tan_half_fov ), " + zeroStr + ", " + zeroStr + ", " + zeroStr + ",\n";
			outInl += "\t\t" + zeroStr + ", " + oneStr + " / tan_half_fov, " + zeroStr + ", " + zeroStr + ",\n";
			outInl += "\t\t" + zeroStr + ", " + zeroStr + ", zfar / far_minus_near, -( zfar * znear ) / far_minus_near,\n";
			outInl += "\t\t" + zeroStr + ", " + zeroStr + ", " + oneStr + ", " + zeroStr + "\n";
			outInl += "\t);\n";
			break;
		}

		case GEN_HAND_RIGHT: {
			// TODO(DM):
			break;
		}

		case GEN_HAND_COUNT:
		default:
			printf( "ERROR: Bad genHand_t enum passed into %s.\n", __FUNCTION__ );
			break;
	}
	outInl += "}\n";
	outInl += "\n";
}

void Gen_MatrixLookAt( const genHand_t hand, const genType_t type, const uint32_t numRows, const uint32_t numCols, std::string& outHeader, std::string& outInl ) {
	assert( numRows >= GEN_COMPONENT_COUNT_MIN );
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );

	if ( !Gen_IsFloatingPointType( type ) ) {
		return;
	}

	if ( numRows != 4 || numCols != 4 ) {
		return;
	}

	uint32_t numVecComponents = 3;

	std::string typeString = Gen_GetTypeString( type );
	std::string vectorTypeString = typeString + std::to_string( numVecComponents );
	std::string fullTypeName = typeString + std::to_string( numRows ) + "x" + std::to_string( numCols );

	std::string zeroStr	= Gen_GetNumericLiteral( type, 0.0f );
	std::string oneStr	= Gen_GetNumericLiteral( type, 1.0f );

	outHeader += GetDocLookAt( fullTypeName );
	outHeader += "inline " + fullTypeName + " lookat( const " + vectorTypeString + "& eye, const " + vectorTypeString + "& target, const " + vectorTypeString + "& up );\n";
	outHeader += "\n";

	outInl += fullTypeName + " lookat( const " + vectorTypeString + "& eye, const " + vectorTypeString + "& target, const " + vectorTypeString + "& up ) {\n";
	switch ( hand ) {
		case GEN_HAND_LEFT: {
			outInl += "\tconst " + vectorTypeString + " forward = normalized( target - eye );\n";
			outInl += "\tconst " + vectorTypeString + " right = normalized( cross( up, forward ) );\n";
			outInl += "\tconst " + vectorTypeString + " up1 = cross( forward, right );\n";
			outInl += "\n";
			outInl += "\treturn " + fullTypeName + "(\n";
			outInl += "\t\tright.x,   right.y,   right.z,   -dot( right, eye ),\n";
			outInl += "\t\tup1.x,     up1.y,     up1.z,     -dot( up1, eye ),\n";
			outInl += "\t\tforward.x, forward.y, forward.z, -dot( forward, eye ),\n";
			outInl += "\t\t" + zeroStr + ", " + zeroStr + ", " + zeroStr + ", " + oneStr + "\n";
			outInl += "\t);\n";
			break;
		}

		case GEN_HAND_RIGHT: {
			// TODO(DM):
			break;
		}

		case GEN_HAND_COUNT:
		default:
			printf( "ERROR: Bad genHand_t enum passed into %s.\n", __FUNCTION__ );
			break;
	}
	outInl += "}\n";
	outInl += "\n";
}
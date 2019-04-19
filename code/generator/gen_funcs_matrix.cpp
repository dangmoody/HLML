#include "gen_funcs_matrix.h"

#include "gen_doc_common.h"

#include <assert.h>

// TODO(DM): move these functions into their own file
static std::string GetDocMatrixMultiplication( const std::string& fullTypeName ) {
	return "/// \\relates " + fullTypeName + "\n" \
		"/// \\brief Returns a copy of the matrix where each row of the left-hand matrix has been dot-producted by the corresponding column of the right-hand matrix.\n";
}

static std::string GetDocCompoundMatrixMultiplication( const std::string& fullTypeName ) {
	return "/// \\relates " + fullTypeName + "\n" \
		"/// \\brief Dot products each row of the left-hand matrix with the corresponding column of the right-hand matrix.\n";
}

static std::string GetDocMatrixDivision( const std::string& fullTypeName ) {
	return "/// \\relates " + fullTypeName + "\n" \
		"/// \\brief Returns a copy of the matrix where the left-hand matrix has been mathematically multiplied by the inverse of the right-hand matrix.\n";
}

static std::string GetDocCompoundMatrixDivision( const std::string& fullTypeName ) {
	return "/// \\relates " + fullTypeName + "\n" \
		"/// \\brief Multiplies the left-hand matrix by the right-hand matrix (dot product row/col style).\n";
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

static std::string GetDocOrtho( const std::string& fullTypeName, const genHand_t hand, const genClipSpace_t range ) {
	std::string handStr = Gen_GetHandString( hand );
	std::string rangeStr = Gen_GetClipSpaceRangeString( range );

	return "/// \\relates " + fullTypeName + "\n" \
		"/// \\brief Returns an " + handStr + "-handed orthographic projection matrix with the clip-space range " + rangeStr + ".\n";
}

static std::string GetDocPerspective( const std::string& fullTypeName, const genHand_t hand, const genClipSpace_t range ) {
	std::string handStr = Gen_GetHandString( hand );
	std::string rangeStr = Gen_GetClipSpaceRangeString( range );

	return "/// \\relates " + fullTypeName + "\n" \
		+  "/// \\brief Returns a "+ handStr + "-handed perspective projection matrix based on a vertical field-of-view in degrees and an aspect ratio " \
		+  "in the clip-space range of " + rangeStr + ".\n";
}

static std::string GetDocLookAt( const std::string& fullTypeName, const genHand_t hand ) {
	std::string handStr = Gen_GetHandString( hand );

	return "/// \\relates " + fullTypeName + "\n" \
		"/// \\brief Returns a " + handStr + "-handed orthonormal matrix that is oriented at position eye to look at position target.\n";
}

static void MatrixOperatorMul( const genType_t type, const uint32_t numRows, const uint32_t numCols, std::string& outHeader, std::string& outInl ) {
	uint32_t numRhsRows = numCols;
	uint32_t numRhsCols = numRows;

	std::string numRowsStr = std::to_string( numRows );
	std::string numColsStr = std::to_string( numCols );

	std::string typeString = Gen_GetTypeString( type );
	std::string fullTypeName = Gen_GetFullTypeName( type, numRows, numCols );

	// also the tranposed type name
	std::string rhsTypeName = typeString + numColsStr + "x" + numRowsStr;
	std::string returnTypeName = typeString + numRowsStr + "x" + numRowsStr;

	// header
	{
		outHeader += GetDocMatrixMultiplication( fullTypeName );
		outHeader += "inline " + returnTypeName + " operator*( const " + fullTypeName + "& lhs, const " + rhsTypeName + "& rhs );\n";
		outHeader += "\n";

		outHeader += GetDocCompoundMatrixMultiplication( fullTypeName );
		outHeader += "inline " + returnTypeName + " operator*=( " + fullTypeName + "& lhs, const " + rhsTypeName + "& rhs );\n";
		outHeader += "\n";
	}

	// inl
	{
		// main operator
		outInl += returnTypeName + " operator*( const " + fullTypeName + "& lhs, const " + rhsTypeName + "& rhs )\n";
		outInl += "{\n";
		// generate row vars
		for ( uint32_t row = 0; row < numRows; row++ ) {
			std::string rowStr = std::to_string( row );
			outInl += "\t" + typeString + numColsStr + " row" + rowStr + " = lhs[" + rowStr + "];\n";
		}

		outInl += "\n";

		// generate col vars
		for ( uint32_t col = 0; col < numRhsCols; col++ ) {
			outInl += "\t" + typeString + numColsStr + " col" + std::to_string( col ) + " = { ";
			for ( uint32_t rhsRow = 0; rhsRow < numRhsRows; rhsRow++ ) {
				outInl += "rhs[" + std::to_string( rhsRow ) + "]." + GEN_COMPONENT_NAMES_VECTOR[col];

				if ( rhsRow != numCols - 1 ) {
					outInl += ", ";
				}
			}

			outInl += " };\n";
		}
		outInl += "\n";

		// now do the row/col dot products
		outInl += "\treturn " + returnTypeName + "(\n";

		for ( uint32_t row = 0; row < numRows; row++ ) {
			std::string rowStr = std::to_string( row );

			for ( uint32_t col = 0; col < numRows; col++ ) {
				std::string colStr = std::to_string( col );

				outInl += "\t\t";

				for ( uint32_t rhsRow = 0; rhsRow < numRhsRows; rhsRow++ ) {
					outInl += "row" + rowStr + "." + GEN_COMPONENT_NAMES_VECTOR[rhsRow] + " * " + "col" + colStr + "." + GEN_COMPONENT_NAMES_VECTOR[rhsRow];

					if ( rhsRow != numRhsRows - 1 ) {
						outInl += " + ";
					} else {
						if ( col + ( row * numRows ) != ( numRows * numRows ) - 1 ) {
							outInl += ",";
						}

						outInl += "\n";
					}
				}
			}

			if ( row != numRows - 1 ) {
				outInl += "\n";
			}
		}
		outInl += "\t);\n";
		outInl += "}\n";
		outInl += "\n";

		// compound operator
		if ( numRows == numCols ) {
			outInl += returnTypeName + " operator*=( " + fullTypeName + "& lhs, const " + rhsTypeName + "& rhs )\n";
			outInl += "{\n";
			outInl += "\treturn ( lhs = lhs * rhs );\n";
			outInl += "}\n";
			outInl += "\n";
		}
	}
}

static void MatrixOperatorDiv( const genType_t type, const uint32_t numRows, const uint32_t numCols, std::string& outHeader, std::string& outInl ) {
	std::string fullTypeName = Gen_GetFullTypeName( type, numRows, numCols );

	// main operator
	outHeader += GetDocMatrixDivision( fullTypeName );
	outHeader += "inline " + fullTypeName + " operator/( const " + fullTypeName + "& lhs, const " + fullTypeName + "& rhs );\n";
	outHeader += "\n";

	outInl += fullTypeName + " operator/( const " + fullTypeName + "& lhs, const " + fullTypeName + "& rhs )\n";
	outInl += "{\n";
	outInl += "\treturn lhs * inverse( rhs );\n";
	outInl += "}\n";
	outInl += "\n";

	// compound operator
	outHeader += GetDocCompoundMatrixDivision( fullTypeName );
	outHeader += "inline " + fullTypeName + " operator/=( " + fullTypeName + "& lhs, const " + fullTypeName + "& rhs );\n";
	outHeader += "\n";

	outInl += fullTypeName + " operator/=( " + fullTypeName + "& lhs, const " + fullTypeName + "& rhs )\n";
	outInl += "{\n";
	outInl += "\treturn ( lhs = lhs / rhs );\n";
	outInl += "}\n";
	outInl += "\n";
}

static void MatrixMulVector( const genType_t type, const uint32_t numRows, const uint32_t numCols, std::string& outHeader, std::string& outInl ) {
	assert( numRows >= GEN_COMPONENT_COUNT_MIN );
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );

	std::string memberTypeString = Gen_GetMemberTypeString( type );
	std::string vectorTypeName = Gen_GetTypeString( type ) + std::to_string( numCols );
	std::string fullTypeName = Gen_GetFullTypeName( type, numRows, numCols );

	// main operator
	{
		outHeader += Gen_GetDocOperatorComponentWiseArithmeticRhsType( vectorTypeName, fullTypeName, GEN_OP_ARITHMETIC_MUL );
		outHeader += "inline " + vectorTypeName + " operator*( const " + fullTypeName + "& lhs, const " + vectorTypeName + "& rhs );\n";
		outHeader += "\n";

		outInl += vectorTypeName + " operator*( const " + fullTypeName + "& lhs, const " + vectorTypeName + "& rhs )\n";
		outInl += "{\n";
		outInl += "\treturn " + vectorTypeName + "(\n";
		for ( uint32_t row = 0; row < numRows; row++ ) {
			outInl += "\t\t(" + memberTypeString + ") dot( lhs[" + std::to_string( row ) + "], rhs )";

			if ( row != numRows - 1 ) {
				outInl += ",";
			}

			outInl += "\n";
		}
		outInl += "\t);\n";
		outInl += "}\n";
		outInl += "\n";
	}

	// compound operator
	{
		outHeader += Gen_GetDocOperatorCompoundComponentWiseArithmeticRhsType( vectorTypeName, fullTypeName, GEN_OP_ARITHMETIC_MUL );
		outHeader += "inline " + vectorTypeName + " operator*=( " + vectorTypeName + "& lhs, const " + fullTypeName + "& rhs );\n";
		outHeader += "\n";

		outInl += vectorTypeName + " operator*=( " + vectorTypeName + "& lhs, const " + fullTypeName + "& rhs )\n";
		outInl += "{\n";
		outInl += "\treturn ( lhs = rhs * lhs );\n";
		outInl += "}\n";
		outInl += "\n";
	}
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

	return Gen_GetParmListMatrixDiagonal( type, numRows, numCols, values, GEN_MIN( numRows, numCols ) );
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

void Gen_MatrixOperatorsArithmetic( const genType_t type, const uint32_t numRows, const uint32_t numCols, std::string& outHeader, std::string& outInl ) {
	assert( numRows >= GEN_COMPONENT_COUNT_MIN );
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );

	if ( type == GEN_TYPE_BOOL ) {
		return;
	}

	Gen_OperatorComponentWiseArithmeticScalar( type, numRows, numCols, GEN_OP_ARITHMETIC_ADD, outHeader, outInl );
	Gen_OperatorComponentWiseArithmeticRhsType( type, numRows, numCols, GEN_OP_ARITHMETIC_ADD, outHeader, outInl );

	Gen_OperatorComponentWiseArithmeticScalar( type, numRows, numCols, GEN_OP_ARITHMETIC_SUB, outHeader, outInl );
	Gen_OperatorComponentWiseArithmeticRhsType( type, numRows, numCols, GEN_OP_ARITHMETIC_SUB, outHeader, outInl );

	Gen_OperatorComponentWiseArithmeticScalar( type, numRows, numCols, GEN_OP_ARITHMETIC_MUL, outHeader, outInl );
	MatrixOperatorMul( type, numRows, numCols, outHeader, outInl );

	Gen_OperatorComponentWiseArithmeticScalar( type, numRows, numCols, GEN_OP_ARITHMETIC_DIV, outHeader, outInl );
	// TODO(DM): pseudo-inverse
	if ( numRows == numCols && Gen_IsFloatingPointType( type ) ) {
		MatrixOperatorDiv( type, numRows, numCols, outHeader, outInl );
	} else {
		Gen_OperatorComponentWiseArithmeticRhsType( type, numRows, numCols, GEN_OP_ARITHMETIC_DIV, outHeader, outInl );
	}

	if ( numRows == numCols ) {
		MatrixMulVector( type, numRows, numCols, outHeader, outInl );
	}
}

void Gen_MatrixIdentity( const genType_t type, const uint32_t numRows, const uint32_t numCols, std::string& outHeader, std::string& outInl ) {
	assert( numRows >= GEN_COMPONENT_COUNT_MIN );
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );

	std::string fullTypeName = Gen_GetTypeString( type ) + std::to_string( numRows ) + "x" + std::to_string( numCols );

	std::string zeroStr = Gen_GetNumericLiteral( type, 0.0f );
	std::string oneStr = Gen_GetNumericLiteral( type, 1.0f );

	outHeader += GetDocIdentity( fullTypeName );
	outHeader += "inline void identity( " + fullTypeName + "& mat );\n";
	outHeader += "\n";

	outInl += "void identity( " + fullTypeName + "& mat )\n";
	outInl += "{\n";
	for ( uint32_t row = 0; row < numRows; row++ ) {
		outInl += "\tmat[" + std::to_string( row ) + "] = { ";
		for ( uint32_t col = 0; col < numCols; col++ ) {
			outInl += ( row == col ) ? oneStr : zeroStr;

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

	outInl += transposeTypeName + " transpose( const " + fullTypeName + "& mat )\n";
	outInl += "{\n";
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

	outInl += fullTypeName + " inverse( const " + fullTypeName + "& mat )\n";
	outInl += "{\n";

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

	outInl += memberTypeString + " determinant( const " + fullTypeName + "& mat )\n";
	outInl += "{\n";
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

	outInl += fullTypeName + " translate( const " + fullTypeName + "& mat, const " + typeString + std::to_string( vecComponents ) + "& vec )\n";
	outInl += "{\n";
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

	std::string cosFuncStr = Gen_GetFuncNameCos( type );
	std::string sinFuncStr = Gen_GetFuncNameSin( type );

	outHeader += GetDocRotate( fullTypeName );
	outHeader += "inline " + fullTypeName + " rotate( " + parmListStr + " );\n";
	outHeader += "\n";

	outInl += fullTypeName + " rotate( " + parmListStr + " )\n";
	outInl += "{\n";
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

	outInl += fullTypeName + " scale( const " + fullTypeName + "& mat, const " + memberTypeString + " scalar )\n";
	outInl += "{\n";
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

	outInl += fullTypeName + " scale( const " + fullTypeName + "& mat, const " + scaleVectorString + "& vec )\n";
	outInl += "{\n";
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

void Gen_MatrixOrtho( const genType_t type, const uint32_t numRows, const uint32_t numCols, std::string& outHeader, std::string& outInl ) {
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

	std::string minusTwoStr	= Gen_GetNumericLiteral( type, -2.0f );
	std::string minusOneStr	= Gen_GetNumericLiteral( type, -1.0f );
	std::string zeroStr		= Gen_GetNumericLiteral( type, 0.0f );
	std::string oneStr		= Gen_GetNumericLiteral( type, 1.0f );
	std::string twoStr		= Gen_GetNumericLiteral( type, 2.0f );

	genHand_t hand;
	genClipSpace_t range;

	std::string handStr, rangeStr;

	// TODO(DM): do we need to generate each one?
	// what if had handedness and clip-space range as cmd args?

	// left-hand, zero to one
	{
		hand = GEN_HAND_LEFT;
		range = GEN_CLIP_SPACE_ZERO_TO_ONE;

		handStr = Gen_GetHandString( hand );
		rangeStr = Gen_GetClipSpaceRangeString( range );

		outHeader += GetDocOrtho( fullTypeName, hand, range );
		outHeader += "inline " + fullTypeName + " ortho_lh_zo( const " + typeString + " left, const " + typeString + " right, const " + typeString + " top, const " + typeString + " bottom, const " + typeString + " znear, const " + typeString + " zfar );\n";
		outHeader += "\n";

		outInl += "inline " + fullTypeName + " ortho_lh_zo( const " + typeString + " left, const " + typeString + " right, const " + typeString + " top, const " + typeString + " bottom, const " + typeString + " znear, const " + typeString + " zfar )\n";
		outInl += "{\n";
		outInl += "\t// " + handStr + "-handed, clip-space range: " + rangeStr + "\n";
		outInl += "\tconst " + typeString + " right_minus_left = right - left;\n";
		outInl += "\tconst " + typeString + " right_plus_left = right + left;\n";
		outInl += "\tconst " + typeString + " top_minus_bottom = top - bottom;\n";
		outInl += "\tconst " + typeString + " top_plus_bottom = top + bottom;\n";
		outInl += "\tconst " + typeString + " far_minus_near = zfar - znear;\n";
		outInl += "\n";
		outInl += "\treturn " + fullTypeName + "(\n";
		outInl += "\t\t" + twoStr + " / right_minus_left, " + zeroStr + ", " + zeroStr + ", -right_plus_left / right_minus_left,\n";
		outInl += "\t\t" + zeroStr + ", " + twoStr + " / top_minus_bottom, " + zeroStr + ", -top_plus_bottom / top_minus_bottom,\n";
		outInl += "\t\t" + zeroStr + ", " + zeroStr + ", " + oneStr + " / far_minus_near, -znear / far_minus_near";
		outInl += ",\n\t\t" + zeroStr + ", " + zeroStr + ", " + zeroStr + ", " + oneStr + "\n";
		outInl += "\t);\n";
		outInl += "}\n";
		outInl += "\n";
	}

	// left-hand, minus-one to one
	{
		hand = GEN_HAND_LEFT;
		range = GEN_CLIP_SPACE_MINUS_ONE_TO_ONE;

		handStr = Gen_GetHandString( hand );
		rangeStr = Gen_GetClipSpaceRangeString( range );

		outHeader += GetDocOrtho( fullTypeName, hand, range );
		outHeader += "inline " + fullTypeName + " ortho_lh_no( const " + typeString + " left, const " + typeString + " right, const " + typeString + " top, const " + typeString + " bottom, const " + typeString + " znear, const " + typeString + " zfar );\n";
		outHeader += "\n";

		outInl += "inline " + fullTypeName + " ortho_lh_no( const " + typeString + " left, const " + typeString + " right, const " + typeString + " top, const " + typeString + " bottom, const " + typeString + " znear, const " + typeString + " zfar )\n";
		outInl += "{\n";
		outInl += "\t// " + handStr + "-handed, clip-space range: " + rangeStr + "\n";
		outInl += "\tconst " + typeString + " right_minus_left = right - left;\n";
		outInl += "\tconst " + typeString + " right_plus_left = right + left;\n";
		outInl += "\tconst " + typeString + " top_minus_bottom = top - bottom;\n";
		outInl += "\tconst " + typeString + " top_plus_bottom = top + bottom;\n";
		outInl += "\tconst " + typeString + " far_minus_near = zfar - znear;\n";
		outInl += "\tconst " + typeString + " far_plus_near = zfar + znear;\n";
		outInl += "\n";
		outInl += "\treturn " + fullTypeName + "(\n";
		outInl += "\t\t" + twoStr + " / right_minus_left, " + zeroStr + ", " + zeroStr + ", -right_plus_left / right_minus_left,\n";
		outInl += "\t\t" + zeroStr + ", " + twoStr + " / top_minus_bottom, " + zeroStr + ", -top_plus_bottom / top_minus_bottom,\n";
		outInl += "\t\t" + zeroStr + ", " + zeroStr + ", " + twoStr + " / far_minus_near, -far_plus_near / far_minus_near";
		outInl += ",\n\t\t" + zeroStr + ", " + zeroStr + ", " + zeroStr + ", " + oneStr + "\n";
		outInl += "\t);\n";
		outInl += "}\n";
		outInl += "\n";
	}
	
	// right-hand, zero to one
	{
		hand = GEN_HAND_RIGHT;
		range = GEN_CLIP_SPACE_ZERO_TO_ONE;

		handStr = Gen_GetHandString( hand );
		rangeStr = Gen_GetClipSpaceRangeString( range );

		outHeader += GetDocOrtho( fullTypeName, hand, range );
		outHeader += "inline " + fullTypeName + " ortho_rh_zo( const " + typeString + " left, const " + typeString + " right, const " + typeString + " top, const " + typeString + " bottom, const " + typeString + " znear, const " + typeString + " zfar );\n";
		outHeader += "\n";

		outInl += "inline " + fullTypeName + " ortho_rh_zo( const " + typeString + " left, const " + typeString + " right, const " + typeString + " top, const " + typeString + " bottom, const " + typeString + " znear, const " + typeString + " zfar )\n";
		outInl += "{\n";
		outInl += "\t// " + handStr + "-handed, clip-space range: " + rangeStr + "\n";
		outInl += "\tconst " + typeString + " right_minus_left = right - left;\n";
		outInl += "\tconst " + typeString + " right_plus_left = right + left;\n";
		outInl += "\tconst " + typeString + " top_minus_bottom = top - bottom;\n";
		outInl += "\tconst " + typeString + " top_plus_bottom = top + bottom;\n";
		outInl += "\tconst " + typeString + " far_minus_near = zfar - znear;\n";
		outInl += "\n";
		outInl += "\treturn " + fullTypeName + "(\n";
		outInl += "\t\t" + twoStr + " / right_minus_left, " + zeroStr + ", " + zeroStr + ", -right_plus_left / right_minus_left,\n";
		outInl += "\t\t" + zeroStr + ", " + twoStr + " / top_minus_bottom, " + zeroStr + ", -top_plus_bottom / top_minus_bottom,\n";
		outInl += "\t\t" + zeroStr + ", " + zeroStr + ", " + minusOneStr + " / far_minus_near, -znear / far_minus_near";
		outInl += ",\n\t\t" + zeroStr + ", " + zeroStr + ", " + zeroStr + ", " + oneStr + "\n";
		outInl += "\t);\n";
		outInl += "}\n";
		outInl += "\n";
	}

	// right-hand, minus-one to one
	{
		hand = GEN_HAND_RIGHT;
		range = GEN_CLIP_SPACE_MINUS_ONE_TO_ONE;

		handStr = Gen_GetHandString( hand );
		rangeStr = Gen_GetClipSpaceRangeString( range );

		outHeader += GetDocOrtho( fullTypeName, hand, range );
		outHeader += "inline " + fullTypeName + " ortho_rh_no( const " + typeString + " left, const " + typeString + " right, const " + typeString + " top, const " + typeString + " bottom, const " + typeString + " znear, const " + typeString + " zfar );\n";
		outHeader += "\n";

		outInl += "inline " + fullTypeName + " ortho_rh_no( const " + typeString + " left, const " + typeString + " right, const " + typeString + " top, const " + typeString + " bottom, const " + typeString + " znear, const " + typeString + " zfar )\n";
		outInl += "{\n";
		outInl += "\t// " + handStr + "-handed, clip-space range: " + rangeStr + "\n";
		outInl += "\tconst " + typeString + " right_minus_left = right - left;\n";
		outInl += "\tconst " + typeString + " right_plus_left = right + left;\n";
		outInl += "\tconst " + typeString + " top_minus_bottom = top - bottom;\n";
		outInl += "\tconst " + typeString + " top_plus_bottom = top + bottom;\n";
		outInl += "\tconst " + typeString + " far_minus_near = zfar - znear;\n";
		outInl += "\tconst " + typeString + " far_plus_near = zfar + znear;\n";
		outInl += "\n";
		outInl += "\treturn " + fullTypeName + "(\n";
		outInl += "\t\t" + twoStr + " / right_minus_left, " + zeroStr + ", " + zeroStr + ", -right_plus_left / right_minus_left,\n";
		outInl += "\t\t" + zeroStr + ", " + twoStr + " / top_minus_bottom, " + zeroStr + ", -top_plus_bottom / top_minus_bottom,\n";
		outInl += "\t\t" + zeroStr + ", " + zeroStr + ", " + minusTwoStr + " / far_minus_near, -far_plus_near / far_minus_near";
		outInl += ",\n\t\t" + zeroStr + ", " + zeroStr + ", " + zeroStr + ", " + oneStr + "\n";
		outInl += "\t);\n";
		outInl += "}\n";
		outInl += "\n";
	}
}

void Gen_MatrixPerspective( const genType_t type, const uint32_t numRows, const uint32_t numCols, std::string& outHeader, std::string& outInl ) {
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

	std::string minusOneStr	= Gen_GetNumericLiteral( type, -1.0f );
	std::string zeroStr		= Gen_GetNumericLiteral( type,  0.0f );
	std::string halfStr		= Gen_GetNumericLiteral( type,  0.5f );
	std::string oneStr		= Gen_GetNumericLiteral( type,  1.0f );
	std::string twoStr		= Gen_GetNumericLiteral( type,  2.0f );

	std::string tanFuncStr = Gen_GetFuncNameTan( type );

	genHand_t hand;
	genClipSpace_t range;

	std::string handStr, rangeStr;

	// left-handed, zero to one
	{
		hand = GEN_HAND_LEFT;
		range = GEN_CLIP_SPACE_ZERO_TO_ONE;

		handStr = Gen_GetHandString( hand );
		rangeStr = Gen_GetClipSpaceRangeString( range );

		outHeader += GetDocPerspective( fullTypeName, hand, range );
		outHeader += "inline " + fullTypeName + " perspective_lh_zo( const " + typeString + " fovdeg, const " + typeString + " aspect, const " + typeString + " znear, const " + typeString + " zfar );\n";
		outHeader += "\n";

		outInl += fullTypeName + " perspective_lh_zo( const " + typeString + " fovdeg, const " + typeString + " aspect, const " + typeString + " znear, const " + typeString + " zfar )\n";
		outInl += "{\n";
		outInl += "\t// " + handStr + "-handed, clip space range: " + rangeStr + "\n";
		outInl += "\tconst " + typeString + " far_minus_near = zfar - znear;\n";
		outInl += "\tconst " + typeString + " tan_half_fov = " + tanFuncStr + "( fovdeg * " + halfStr + " );\n";
		outInl += "\n";
		outInl += "\treturn " + fullTypeName + "(\n";
		outInl += "\t\t" + oneStr + " / ( aspect * tan_half_fov ), " + zeroStr + ", " + zeroStr + ", " + zeroStr + ",\n";
		outInl += "\t\t" + zeroStr + ", " + oneStr + " / tan_half_fov, " + zeroStr + ", " + zeroStr + ",\n";
		outInl += "\t\t" + zeroStr + ", " + zeroStr + ", zfar / far_minus_near, -( zfar * znear ) / far_minus_near,\n";
		outInl += "\t\t" + zeroStr + ", " + zeroStr + ", " + oneStr + ", " + zeroStr + "\n";
		outInl += "\t);\n";
		outInl += "}\n";
		outInl += "\n";
	}

	// left-handed, minus-one to one
	{
		hand = GEN_HAND_LEFT;
		range = GEN_CLIP_SPACE_MINUS_ONE_TO_ONE;

		handStr = Gen_GetHandString( hand );
		rangeStr = Gen_GetClipSpaceRangeString( range );

		outHeader += GetDocPerspective( fullTypeName, hand, range );
		outHeader += "inline " + fullTypeName + " perspective_lh_no( const " + typeString + " fovdeg, const " + typeString + " aspect, const " + typeString + " znear, const " + typeString + " zfar );\n";
		outHeader += "\n";

		outInl += fullTypeName + " perspective_lh_no( const " + typeString + " fovdeg, const " + typeString + " aspect, const " + typeString + " znear, const " + typeString + " zfar )\n";
		outInl += "{\n";
		outInl += "\t// " + handStr + "-handed, clip space range: " + rangeStr + "\n";
		outInl += "\tconst " + typeString + " far_minus_near = zfar - znear;\n";
		outInl += "\tconst " + typeString + " far_plus_near = zfar + znear;\n";
		outInl += "\tconst " + typeString + " tan_half_fov = " + tanFuncStr + "( fovdeg * " + halfStr + " );\n";
		outInl += "\n";
		outInl += "\treturn " + fullTypeName + "(\n";
		outInl += "\t\t" + oneStr + " / ( aspect * tan_half_fov ), " + zeroStr + ", " + zeroStr + ", " + zeroStr + ",\n";
		outInl += "\t\t" + zeroStr + ", " + oneStr + " / tan_half_fov, " + zeroStr + ", " + zeroStr + ",\n";
		outInl += "\t\t" + zeroStr + ", " + zeroStr + ", far_plus_near / far_minus_near, -( " + twoStr + " * zfar * znear ) / far_minus_near,\n";
		outInl += "\t\t" + zeroStr + ", " + zeroStr + ", " + oneStr + ", " + zeroStr + "\n";
		outInl += "\t);\n";
		outInl += "}\n";
		outInl += "\n";
	}

	// right-handed, zero to one
	{
		hand = GEN_HAND_RIGHT;
		range = GEN_CLIP_SPACE_ZERO_TO_ONE;

		handStr = Gen_GetHandString( hand );
		rangeStr = Gen_GetClipSpaceRangeString( range );

		outHeader += GetDocPerspective( fullTypeName, hand, range );
		outHeader += "inline " + fullTypeName + " perspective_rh_zo( const " + typeString + " fovdeg, const " + typeString + " aspect, const " + typeString + " znear, const " + typeString + " zfar );\n";
		outHeader += "\n";

		outInl += fullTypeName + " perspective_rh_zo( const " + typeString + " fovdeg, const " + typeString + " aspect, const " + typeString + " znear, const " + typeString + " zfar )\n";
		outInl += "{\n";
		outInl += "\t// " + handStr + "-handed, clip space range: " + rangeStr + "\n";
		outInl += "\tconst " + typeString + " tan_half_fov = " + tanFuncStr + "( fovdeg * " + halfStr + " );\n";
		outInl += "\n";
		outInl += "\treturn " + fullTypeName + "(\n";
		outInl += "\t\t" + oneStr + " / ( aspect * tan_half_fov ), " + zeroStr + ", " + zeroStr + ", " + zeroStr + ",\n";
		outInl += "\t\t" + zeroStr + ", " + oneStr + " / tan_half_fov, " + zeroStr + ", " + zeroStr + ",\n";
		outInl += "\t\t" + zeroStr + ", " + zeroStr + ", zfar / ( znear - zfar ), -( zfar * znear ) / ( zfar - znear ),\n";
		outInl += "\t\t" + zeroStr + ", " + zeroStr + ", " + minusOneStr + ", " + zeroStr + "\n";
		outInl += "\t);\n";
		outInl += "}\n";
		outInl += "\n";
	}

	// right-handed, minus-one to one
	{
		hand = GEN_HAND_RIGHT;
		range = GEN_CLIP_SPACE_MINUS_ONE_TO_ONE;

		handStr = Gen_GetHandString( hand );
		rangeStr = Gen_GetClipSpaceRangeString( range );

		outHeader += GetDocPerspective( fullTypeName, hand, range );
		outHeader += "inline " + fullTypeName + " perspective_rh_no( const " + typeString + " fovdeg, const " + typeString + " aspect, const " + typeString + " znear, const " + typeString + " zfar );\n";
		outHeader += "\n";

		outInl += fullTypeName + " perspective_rh_no( const " + typeString + " fovdeg, const " + typeString + " aspect, const " + typeString + " znear, const " + typeString + " zfar )\n";
		outInl += "{\n";
		outInl += "\t// " + handStr + "-handed, clip space range: " + rangeStr + "\n";
		outInl += "\tconst " + typeString + " far_minus_near = zfar - znear;\n";
		outInl += "\tconst " + typeString + " far_plus_near = zfar + znear;\n";
		outInl += "\tconst " + typeString + " tan_half_fov = " + tanFuncStr + "( fovdeg * " + halfStr + " );\n";
		outInl += "\n";
		outInl += "\treturn " + fullTypeName + "(\n";
		outInl += "\t\t" + oneStr + " / ( aspect * tan_half_fov ), " + zeroStr + ", " + zeroStr + ", " + zeroStr + ",\n";
		outInl += "\t\t" + zeroStr + ", " + oneStr + " / tan_half_fov, " + zeroStr + ", " + zeroStr + ",\n";
		outInl += "\t\t" + zeroStr + ", " + zeroStr + ", -far_plus_near / far_minus_near, -( " + twoStr + " * zfar * znear ) / far_minus_near,\n";
		outInl += "\t\t" + zeroStr + ", " + zeroStr + ", " + minusOneStr + ", " + zeroStr + "\n";
		outInl += "\t);\n";
		outInl += "}\n";
		outInl += "\n";
	}
}

void Gen_MatrixLookAt( const genType_t type, const uint32_t numRows, const uint32_t numCols, std::string& outHeader, std::string& outInl ) {
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

	// left-handed
	{
		outHeader += GetDocLookAt( fullTypeName, GEN_HAND_LEFT );
		outHeader += "inline " + fullTypeName + " lookat_lh( const " + vectorTypeString + "& eye, const " + vectorTypeString + "& target, const " + vectorTypeString + "& up );\n";
		outHeader += "\n";

		outInl += fullTypeName + " lookat_lh( const " + vectorTypeString + "& eye, const " + vectorTypeString + "& target, const " + vectorTypeString + "& up )\n";
		outInl += "{\n";
		outInl += "\t// left handed\n";
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
		outInl += "}\n";
		outInl += "\n";
	}

	// right-handed
	{
		outHeader += GetDocLookAt( fullTypeName, GEN_HAND_RIGHT );
		outHeader += "inline " + fullTypeName + " lookat_rh( const " + vectorTypeString + "& eye, const " + vectorTypeString + "& target, const " + vectorTypeString + "& up );\n";
		outHeader += "\n";

		outInl += fullTypeName + " lookat_rh( const " + vectorTypeString + "& eye, const " + vectorTypeString + "& target, const " + vectorTypeString + "& up )\n";
		outInl += "{\n";
		outInl += "\t// right handed\n";
		outInl += "\tconst " + vectorTypeString + " forward = normalized( target - eye );\n";
		outInl += "\tconst " + vectorTypeString + " right = normalized( cross( forward, up ) );\n";
		outInl += "\tconst " + vectorTypeString + " up1 = cross( right, forward );\n";
		outInl += "\n";
		outInl += "\treturn " + fullTypeName + "(\n";
		outInl += "\t\t right.x,    right.y,    right.z,   -dot( right, eye ),\n";
		outInl += "\t\t up1.x,      up1.y,      up1.z,     -dot( up1, eye ),\n";
		outInl += "\t\t-forward.x, -forward.y, -forward.z,  dot( forward, eye ),\n";
		outInl += "\t\t" + zeroStr + ", " + zeroStr + ", " + zeroStr + ", " + oneStr + "\n";
		outInl += "\t);\n";
		outInl += "}\n";
		outInl += "\n";
	}
}
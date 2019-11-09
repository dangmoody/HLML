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
#include "gen_funcs_matrix.h"

#include "gen_doc_common.h"
#include "gen_doc_matrix.h"

#include "defines.h"

#include <assert.h>

static void GenerateFunctionComponentWiseArithmeticScalar( const genLanguage_t language, const genType_t type, const u32 numRows, const u32 numCols, const genOpArithmetic_t op, stringBuilder_t* sbHeader ) {
	assert( numRows >= GEN_COMPONENT_COUNT_MIN );
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );
	assert( sbHeader );

	if ( type == GEN_TYPE_BOOL ) {
		return;
	}

	const char* memberTypeString = Gen_GetMemberTypeString( type );

	char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetFullTypeName( type, numRows, numCols, fullTypeName );

	char parmTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetParmTypeName( language, type, numRows, numCols, parmTypeName );

	char compFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameComponentWiseArithmeticScalar( language, type, numRows, numCols, op, compFuncStr );

	Doc_ComponentWiseArithmeticScalar( sbHeader, fullTypeName, op );
	String_Appendf( sbHeader, "inline %s %s( const %s lhs, const %s scalar )\n", fullTypeName, compFuncStr, parmTypeName, memberTypeString );
	String_Append(  sbHeader, "{\n" );
	Gen_MatrixGetCodeComponentWiseArithmeticScalar( language, type, numRows, numCols, op, sbHeader );
	String_Append( sbHeader, "}\n" );
	String_Append( sbHeader, "\n" );
}

static void GenerateFunctionComponentWiseArithmeticMatrix( const genLanguage_t language, const genType_t type, const u32 numRows, const u32 numCols, const genOpArithmetic_t op, stringBuilder_t* sbHeader ) {
	assert( numRows >= GEN_COMPONENT_COUNT_MIN );
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );
	assert( sbHeader );

	if ( type == GEN_TYPE_BOOL ) {
		return;
	}

	char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetFullTypeName( type, numRows, numCols, fullTypeName );

	char parmTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetParmTypeName( language, type, numRows, numCols, parmTypeName );

	char compFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameComponentWiseArithmeticMatrix( language, type, numRows, numCols, op, compFuncStr );

	Doc_ComponentWiseArithmeticRhsType( sbHeader, fullTypeName, fullTypeName, op );
	String_Appendf( sbHeader, "inline %s %s( const %s lhs, const %s rhs )\n", fullTypeName, compFuncStr, parmTypeName, parmTypeName );
	String_Append(  sbHeader, "{\n" );
	Gen_MatrixGetCodeComponentWiseArithmeticRhsType( language, type, numRows, numCols, op, sbHeader );
	String_Append( sbHeader, "}\n" );
	String_Append( sbHeader, "\n" );
}

static void GenerateFunctionComponentWiseBitwiseMatrix( const genLanguage_t language, const genType_t type, const u32 numRows, const u32 numCols, const genOpBitwise_t op, stringBuilder_t* sbHeader ) {
	assert( numRows >= GEN_COMPONENT_COUNT_MIN );
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );
	assert( sbHeader );

	if ( !Gen_TypeIsInteger( type ) ) {
		return;
	}

	char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetFullTypeName( type, numRows, numCols, fullTypeName );

	char parmTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetParmTypeName( language, type, numRows, numCols, parmTypeName );

	const char* parmAccessStr = GEN_TYPE_ACCESS_OPERATORS[language];

	char funcStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameBitwise( language, type, numRows, numCols, op, funcStr );

	if ( op == GEN_OP_BITWISE_UNARY ) {
		Doc_OperatorBitwiseUnary( sbHeader, fullTypeName );
		String_Appendf( sbHeader, "inline %s %s( const %s lhs )\n", fullTypeName, funcStr, parmTypeName );
		String_Append( sbHeader, "{\n" );
		String_Appendf( sbHeader, "\treturn HLML_CONSTRUCT( %s ) {\n", fullTypeName );
		for ( u32 row = 0; row < numRows; row++ ) {
			for ( u32 col = 0; col < numCols; col++ ) {
				String_Appendf( sbHeader, "\t\t~lhs%srows[%d].%c", parmAccessStr, row, GEN_COMPONENT_NAMES_VECTOR[col] );

				if ( ( row + col ) != ( numRows - 1 ) + ( numCols - 1 ) ) {
					String_Append( sbHeader, "," );
				}

				String_Append( sbHeader, "\n" );
			}

			String_Append( sbHeader, "\n" );
		}
		String_Append( sbHeader, "\t};\n" );
		String_Append( sbHeader, "}\n" );
		String_Append( sbHeader, "\n" );
	} else {
		Doc_OperatorBitwiseRhsType( sbHeader, fullTypeName, op );
		String_Appendf( sbHeader, "inline %s %s( const %s lhs, const %s rhs )\n", fullTypeName, funcStr, parmTypeName, parmTypeName );
		String_Append(  sbHeader, "{\n" );
		Gen_MatrixGetCodeComponentWiseBitwise( language, type, numRows, numCols, op, sbHeader );
		String_Append( sbHeader, "}\n" );
		String_Append( sbHeader, "\n" );
	}
}

static void GenerateFunctionComponentWiseRelational( const genLanguage_t language, const genType_t type, const u32 numRows, const u32 numCols, const genOpRelational_t op, stringBuilder_t* sbHeader ) {
	assert( numRows >= GEN_COMPONENT_COUNT_MIN );
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );
	assert( sbHeader );

	if ( type == GEN_TYPE_BOOL ) {
		return;
	}

	char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetFullTypeName( type, numRows, numCols, fullTypeName );

	char boolReturnType[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetFullTypeName( GEN_TYPE_BOOL, numRows, numCols, boolReturnType );

	char parmTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetParmTypeName( language, type, numRows, numCols, parmTypeName );

	char cmpFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameRelational( language, type, numRows, numCols, op, cmpFuncStr );

	Doc_ComponentWiseRelational( sbHeader, fullTypeName, numRows, numCols, op );
	String_Appendf( sbHeader, "inline %s %s( const %s lhs, const %s rhs )\n", boolReturnType, cmpFuncStr, parmTypeName, parmTypeName );
	String_Append(  sbHeader, "{\n" );
	Gen_MatrixGetCodeComponentWiseRelational( language, type, numRows, numCols, op, sbHeader );
	String_Append( sbHeader, "}\n" );
	String_Append( sbHeader, "\n" );
}


void Gen_GetParmListMatrix( const genType_t type, const u32 numRows, const u32 numCols, const float values[GEN_COMPONENT_COUNT_MAX][GEN_COMPONENT_COUNT_MAX], char* outString ) {
	assert( numRows >= GEN_COMPONENT_COUNT_MIN );
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );

	char valueStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];

	int pos = 0;

	for ( u32 row = 0; row < numRows; row++ ) {
		pos += snprintf( outString + pos, GEN_STRING_LENGTH_PARM_LIST_MATRIX, "\t\t" );

		for ( u32 col = 0; col < numCols; col++ ) {
			const float value = values[row][col];

			Gen_GetNumericLiteral( type, value, valueStr );

			pos += snprintf( outString + pos, GEN_STRING_LENGTH_PARM_LIST_MATRIX, "%s", valueStr );

			if ( row + col != ( numRows - 1 ) + ( numCols - 1 ) ) {
				pos += snprintf( outString + pos, GEN_STRING_LENGTH_PARM_LIST_MATRIX, "," );
			}

			if ( col != numCols - 1 ) {
				pos += snprintf( outString + pos, GEN_STRING_LENGTH_PARM_LIST_MATRIX, " " );
			}
		}

		pos += snprintf( outString + pos, GEN_STRING_LENGTH_PARM_LIST_MATRIX, "\n" );
	}
}

void Gen_GetParmListMatrixIdentity( const genType_t type, const u32 numRows, const u32 numCols, char* outString ) {
	assert( numRows >= GEN_COMPONENT_COUNT_MIN );
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );

	const float values[] = { 1.0f, 1.0f, 1.0f, 1.0f };

	Gen_GetParmListMatrixDiagonal( type, numRows, numCols, values, GEN_MIN( numRows, numCols ), outString );
}

void Gen_GetParmListMatrixDiagonal( const genType_t type, const u32 numRows, const u32 numCols, const float* values, const u32 numValues, char* outString ) {
	assert( numRows >= GEN_COMPONENT_COUNT_MIN );
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );

	assert( numValues <= 4 );

	char valueStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];

	int pos = 0;

	u32 valueIndex = 0;

	for ( u32 row = 0; row < numRows; row++ ) {
		pos += snprintf( outString + pos, GEN_STRING_LENGTH_PARM_LIST_MATRIX, "\t\t" );

		for ( u32 col = 0; col < numCols; col++ ) {
			if ( row == col ) {
				Gen_GetNumericLiteral( type, values[valueIndex++], valueStr );

				pos += snprintf( outString + pos, GEN_STRING_LENGTH_PARM_LIST_MATRIX, "%s", valueStr );
			} else {
				pos += snprintf( outString + pos, GEN_STRING_LENGTH_PARM_LIST_MATRIX, "%s", Gen_GetDefaultLiteralValue( type ) );
			}

			if ( row + col != ( numRows - 1 ) + ( numCols - 1 ) ) {
				pos += snprintf( outString + pos, GEN_STRING_LENGTH_PARM_LIST_MATRIX, "," );
			}

			if ( col != numCols - 1 ) {
				pos += snprintf( outString + pos, GEN_STRING_LENGTH_PARM_LIST_MATRIX, " " );
			}
		}

		pos += snprintf( outString + pos, GEN_STRING_LENGTH_PARM_LIST_MATRIX, "\n" );
	}
}

void Gen_GetParmListMatrixSingleValue( const genType_t type, const u32 numRows, const u32 numCols, const float value, char* outString ) {
	assert( numRows >= GEN_COMPONENT_COUNT_MIN );
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );

	char valueStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	Gen_GetNumericLiteral( type, value, valueStr );

	int pos = 0;

	for ( u32 row = 0; row < numRows; row++ ) {
		pos += snprintf( outString + pos, GEN_STRING_LENGTH_PARM_LIST_MATRIX, "\t\t" );

		for ( u32 col = 0; col < numCols; col++ ) {
			pos += snprintf( outString + pos, GEN_STRING_LENGTH_PARM_LIST_MATRIX, "%s", valueStr );

			if ( row + col != ( numRows - 1 ) + ( numCols - 1 ) ) {
				pos += snprintf( outString + pos, GEN_STRING_LENGTH_PARM_LIST_MATRIX, "," );
			}

			if ( col != numCols - 1 ) {
				pos += snprintf( outString + pos, GEN_STRING_LENGTH_PARM_LIST_MATRIX, " " );
			}
		}

		pos += snprintf( outString + pos, GEN_STRING_LENGTH_PARM_LIST_MATRIX, "\n" );
	}
}

void Gen_GetParmListMatrixSingleValueStr( const u32 numRows, const u32 numCols, const char* valueStr, char* outString ) {
	assert( numRows >= GEN_COMPONENT_COUNT_MIN );
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );

	int pos = 0;

	for ( u32 row = 0; row < numRows; row++ ) {
		pos += snprintf( outString + pos, GEN_STRING_LENGTH_PARM_LIST_MATRIX, "\t\t" );

		for ( u32 col = 0; col < numCols; col++ ) {
			pos += snprintf( outString + pos, GEN_STRING_LENGTH_PARM_LIST_MATRIX, "%s", valueStr );

			if ( row + col != ( numRows - 1 ) + ( numCols - 1 ) ) {
				pos += snprintf( outString + pos, GEN_STRING_LENGTH_PARM_LIST_MATRIX, "," );
			}

			if ( col != numCols - 1 ) {
				pos += snprintf( outString + pos, GEN_STRING_LENGTH_PARM_LIST_MATRIX, " " );
			}
		}

		pos += snprintf( outString + pos, GEN_STRING_LENGTH_PARM_LIST_MATRIX, "\n" );
	}
}

void Gen_MatrixGetCodeEquals( const genLanguage_t language, const genType_t type, const u32 numRows, const u32 numCols, stringBuilder_t* sbHeader ) {
	assert( numRows >= GEN_COMPONENT_COUNT_MIN );
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );
	assert( sbHeader );

	const char* parmAccessStr = GEN_TYPE_ACCESS_OPERATORS[language];

	char vectorEqualsFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameEquals( language, type, 1, numCols, vectorEqualsFuncStr );

	String_Append(  sbHeader, "\treturn " );
	if ( language == GEN_LANGUAGE_C ) {
		for ( u32 row = 0; row < numRows; row++ ) {
			String_Appendf( sbHeader, "%s( &lhs%srows[%d], &rhs%srows[%d] )", vectorEqualsFuncStr, parmAccessStr, row, parmAccessStr, row );

			if ( row != numRows - 1 ) {
				String_Append( sbHeader, "\n\t\t&& " );
			}
		}
	} else {
		for ( u32 row = 0; row < numRows; row++ ) {
			String_Appendf( sbHeader, "( lhs[%d] == rhs[%d] )", row, row );

			if ( row != numRows - 1 ) {
				String_Append( sbHeader, "\n\t\t&& " );
			}
		}
	}
	String_Append( sbHeader, ";\n" );
}

void Gen_MatrixGetCodeComponentWiseArithmeticScalar( const genLanguage_t language, const genType_t type, const u32 numRows, const u32 numCols, const genOpArithmetic_t op, stringBuilder_t* sbHeader ) {
	assert( numRows >= GEN_COMPONENT_COUNT_MIN );
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );
	assert( sbHeader );

	char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetFullTypeName( type, numRows, numCols, fullTypeName );

	const char opStr = GEN_OPERATORS_ARITHMETIC[op];

	const char* parmAccessStr = GEN_TYPE_ACCESS_OPERATORS[language];

	if ( language == GEN_LANGUAGE_C ) {
		String_Appendf( sbHeader, "\treturn HLML_CONSTRUCT( %s ) {\n", fullTypeName );
		for ( u32 row = 0; row < numRows; row++ ) {
			String_Append( sbHeader, "\t\t" );

			for ( u32 col = 0; col < numCols; col++ ) {
				char componentStr = GEN_COMPONENT_NAMES_VECTOR[col];

				String_Appendf( sbHeader, "lhs%srows[%d].%c %c scalar", parmAccessStr, row, componentStr, opStr );

				if ( row + col != ( numRows - 1 ) + ( numCols - 1 ) ) {
					String_Append( sbHeader, "," );
				}

				if ( col != numCols - 1 ) {
					String_Append( sbHeader, " " );
				} else {
					String_Append( sbHeader, "\n" );
				}
			}
		}
		String_Append( sbHeader, "\t};\n" );
	} else {
		String_Appendf( sbHeader, "\treturn %s(\n", fullTypeName );
		for ( u32 row = 0; row < numRows; row++ ) {
			String_Appendf( sbHeader, "\t\tlhs[%d] %c scalar", row, opStr );

			if ( row != numRows - 1 ) {
				String_Append( sbHeader, "," );
			}

			String_Append( sbHeader, "\n" );
		}
		String_Append( sbHeader, "\t);\n" );
	}
}

void Gen_MatrixGetCodeComponentWiseArithmeticRhsType( const genLanguage_t language, const genType_t type, const u32 numRows, const u32 numCols, const genOpArithmetic_t op, stringBuilder_t* sbHeader ) {
	assert( numRows >= GEN_COMPONENT_COUNT_MIN );
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );
	assert( sbHeader );

	char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetFullTypeName( type, numRows, numCols, fullTypeName );

	const char* parmAccessStr = GEN_TYPE_ACCESS_OPERATORS[language];

	const char* parmRefStr = GEN_TYPE_PARM_REFERENCE_MODIFIERS[language];

	char rowOpFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameComponentWiseArithmeticVector( language, type, 1, numCols, op, rowOpFuncStr );

	String_Appendf( sbHeader, "\treturn HLML_CONSTRUCT( %s ) {\n", fullTypeName );
	for ( u32 row = 0; row < numRows; row++ ) {
		String_Append( sbHeader, "\t\t" );

		String_Appendf( sbHeader, "%s( %slhs%srows[%d], %srhs%srows[%d] )", rowOpFuncStr, parmRefStr, parmAccessStr, row, parmRefStr, parmAccessStr, row );

		if ( row != numRows - 1 ) {
			String_Append( sbHeader, "," );
		}

		String_Append( sbHeader, "\n" );
	}
	String_Append( sbHeader, "\t};\n" );
}

void Gen_MatrixGetCodeComponentWiseBitwise( const genLanguage_t language, const genType_t type, const u32 numRows, const u32 numCols, const genOpBitwise_t op, stringBuilder_t* sbHeader ) {
	assert( numRows >= GEN_COMPONENT_COUNT_MIN );
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );
	assert( sbHeader );

	char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetFullTypeName( type, numRows, numCols, fullTypeName );

	const char* parmRefStr = GEN_TYPE_PARM_REFERENCE_MODIFIERS[language];

	const char* parmAccessStr = GEN_TYPE_ACCESS_OPERATORS[language];

	char rowBitwiseFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameBitwise( language, type, 1, numCols, op, rowBitwiseFuncStr );

	if ( op == GEN_OP_BITWISE_UNARY ) {
		String_Appendf( sbHeader, "\treturn HLML_CONSTRUCT( %s ) {\n", fullTypeName );
		for ( u32 row = 0; row < numRows; row++ ) {
			String_Appendf( sbHeader, "\t\t%s( %slhs%srows[%d] )", rowBitwiseFuncStr, parmRefStr, parmAccessStr, row );

			if ( row != numRows - 1 ) {
				String_Append( sbHeader, "," );
			}

			String_Append( sbHeader, "\n" );
		}
		String_Append(  sbHeader, "\t};\n" );
	} else {
		String_Appendf( sbHeader, "\treturn HLML_CONSTRUCT( %s ) {\n", fullTypeName );
		for ( u32 row = 0; row < numRows; row++ ) {
			String_Appendf( sbHeader, "\t\t%s( %slhs%srows[%d], %srhs%srows[%d] )", rowBitwiseFuncStr, parmRefStr, parmAccessStr, row, parmRefStr, parmAccessStr, row );

			if ( row != numRows - 1 ) {
				String_Append( sbHeader, "," );
			}

			String_Append( sbHeader, "\n" );
		}
		String_Append(  sbHeader, "\t};\n" );
	}
}

void Gen_MatrixGetCodeComponentWiseRelational( const genLanguage_t language, const genType_t type, const u32 numRows, const u32 numCols, const genOpRelational_t op, stringBuilder_t* sbHeader ) {
	assert( numRows >= GEN_COMPONENT_COUNT_MIN );
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );
	assert( sbHeader );

	char boolTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetFullTypeName( GEN_TYPE_BOOL, numRows, numCols, boolTypeName );

	const char* parmRefStr = GEN_TYPE_PARM_REFERENCE_MODIFIERS[language];

	const char* parmAccessStr = GEN_TYPE_ACCESS_OPERATORS[language];

	char rowRelationalFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameRelational( language, type, 1, numCols, op, rowRelationalFuncStr );

	String_Appendf( sbHeader, "\treturn HLML_CONSTRUCT( %s ) {\n", boolTypeName );
	for ( u32 row = 0; row < numRows; row++ ) {
		String_Appendf( sbHeader, "\t\t%s( %slhs%srows[%d], %srhs%srows[%d] )", rowRelationalFuncStr, parmRefStr, parmAccessStr, row, parmRefStr, parmAccessStr, row );

		if ( row != numRows - 1 ) {
			String_Append( sbHeader, "," );
		}

		String_Append( sbHeader, "\n" );
	}
	String_Append( sbHeader, "\t};\n" );
}

void Gen_MatrixGetCodeMultiply( const genLanguage_t language, const genType_t type, const u32 numRows, const u32 numCols, stringBuilder_t* sbHeader ) {
	assert( numRows >= GEN_COMPONENT_COUNT_MIN );
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );
	assert( sbHeader );

	u32 numRhsRows = numCols;
	u32 numRhsCols = numRows;

	const char* typeString = Gen_GetTypeString( type );

	char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	char rhsTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	char returnTypeName[GEN_STRING_LENGTH_TYPE_NAME];

	snprintf( fullTypeName, GEN_STRING_LENGTH_TYPE_NAME, "%s%dx%d", typeString, numRows, numCols );
	snprintf( rhsTypeName, GEN_STRING_LENGTH_TYPE_NAME, "%s%dx%d", typeString, numCols, numRows );
	snprintf( returnTypeName, GEN_STRING_LENGTH_TYPE_NAME, "%s%dx%d", typeString, numRows, numRows );

	const char* parmAccessStr = GEN_TYPE_ACCESS_OPERATORS[language];

	// main operator

	// generate row vars
	for ( u32 row = 0; row < numRows; row++ ) {
		String_Appendf( sbHeader, "\t%s%d row%d = lhs%srows[%d];\n", typeString, numCols, row, parmAccessStr, row );
	}

	String_Append( sbHeader, "\n" );

	// generate col vars
	for ( u32 col = 0; col < numRhsCols; col++ ) {
		String_Appendf( sbHeader, "\t%s%d col%d = { ", typeString, numCols, col );
		for ( u32 rhsRow = 0; rhsRow < numRhsRows; rhsRow++ ) {
			String_Appendf( sbHeader, "rhs%srows[%d].%c", parmAccessStr, rhsRow, GEN_COMPONENT_NAMES_VECTOR[col] );

			if ( rhsRow != numCols - 1 ) {
				String_Append( sbHeader, ", " );
			}
		}

		String_Append( sbHeader, " };\n" );
	}
	String_Append( sbHeader, "\n" );

	// now do the row/col dot products
	String_Appendf( sbHeader, "\treturn HLML_CONSTRUCT( %s ) {\n", returnTypeName );

	for ( u32 row = 0; row < numRows; row++ ) {
		for ( u32 col = 0; col < numRows; col++ ) {
			String_Append( sbHeader, "\t\t" );

			for ( u32 rhsRow = 0; rhsRow < numRhsRows; rhsRow++ ) {
				char rhsComponent = GEN_COMPONENT_NAMES_VECTOR[rhsRow];

				String_Appendf( sbHeader, "row%d.%c * col%d.%c", row, rhsComponent, col, rhsComponent );

				if ( rhsRow != numRhsRows - 1 ) {
					String_Append( sbHeader, " + " );
				} else {
					if ( col + ( row * numRows ) != ( numRows * numRows ) - 1 ) {
						String_Append( sbHeader, "," );
					}

					String_Append( sbHeader, "\n" );
				}
			}
		}

		if ( row != numRows - 1 ) {
			String_Append( sbHeader, "\n" );
		}
	}
	String_Append( sbHeader, "\t};\n" );
}

void Gen_MatrixGetCodeMultiplyVector( const genLanguage_t language, const genType_t type, const u32 numRows, const u32 numCols, stringBuilder_t* sbHeader ) {
	assert( numRows >= GEN_COMPONENT_COUNT_MIN );
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );
	assert( sbHeader );

	const char* typeString = Gen_GetTypeString( type );

	char vectorTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	snprintf( vectorTypeName, GEN_STRING_LENGTH_TYPE_NAME, "%s%d", typeString, numCols );

	const char* parmAccessStr = GEN_TYPE_ACCESS_OPERATORS[language];

	String_Appendf( sbHeader, "\treturn HLML_CONSTRUCT( %s ) {\n", vectorTypeName );
	for ( u32 col = 0; col < numCols; col++ ) {
		String_Append( sbHeader, "\t\t" );

		for ( u32 rhsRow = 0; rhsRow < numCols; rhsRow++ ) {
			char rhsComponent = GEN_COMPONENT_NAMES_VECTOR[rhsRow];

			String_Appendf( sbHeader, "lhs%srows[%d].%c * rhs%s%c", parmAccessStr, col, rhsComponent, parmAccessStr, rhsComponent );

			if ( rhsRow != numCols - 1 ) {
				String_Append( sbHeader, " + " );
			}
		}

		if ( col != numCols - 1 ) {
			String_Append( sbHeader, "," );
		}

		String_Append( sbHeader, "\n" );
	}
	String_Append( sbHeader, "\t};\n" );
}

void Gen_MatrixEquals( const genLanguage_t language, const genType_t type, const u32 numRows, const u32 numCols, stringBuilder_t* sbHeader ) {
	assert( numRows >= GEN_COMPONENT_COUNT_MIN );
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );
	assert( sbHeader );

	char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetFullTypeName( type, numRows, numCols, fullTypeName );

	char parmTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetParmTypeName( language, type, numRows, numCols, parmTypeName );

	char cmpFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameEquals( language, type, numRows, numCols, cmpFuncStr );

	Doc_OperatorEquals( sbHeader, fullTypeName );
	String_Appendf( sbHeader, "inline bool %s( const %s lhs, const %s rhs )\n", cmpFuncStr, parmTypeName, parmTypeName );
	String_Append(  sbHeader, "{\n" );
	Gen_MatrixGetCodeEquals( language, type, numRows, numCols, sbHeader );
	String_Append( sbHeader, "}\n" );
	String_Append( sbHeader, "\n" );

	Gen_NotEquals( language, type, numRows, numCols, sbHeader );
}

void Gen_MatrixComponentWiseArithmetic( const genLanguage_t language, const genType_t type, const u32 numRows, const u32 numCols, stringBuilder_t* sbHeader ) {
	assert( numRows >= GEN_COMPONENT_COUNT_MIN );
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );
	assert( sbHeader );

	if ( type == GEN_TYPE_BOOL ) {
		return;
	}

	for ( u32 opIndex = 0; opIndex < GEN_OP_ARITHMETIC_COUNT; opIndex++ ) {
		genOpArithmetic_t op = (genOpArithmetic_t) opIndex;

		GenerateFunctionComponentWiseArithmeticScalar( language, type, numRows, numCols, op, sbHeader );
		GenerateFunctionComponentWiseArithmeticMatrix( language, type, numRows, numCols, op, sbHeader );
	}
}

void Gen_MatrixComponentWiseBitwise( const genLanguage_t language, const genType_t type, const u32 numRows, const u32 numCols, stringBuilder_t* sbHeader ) {
	assert( numRows >= GEN_COMPONENT_COUNT_MIN );
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );
	assert( sbHeader );

	if ( !Gen_TypeIsInteger( type ) ) {
		return;
	}

	for ( u32 opIndex = 0; opIndex < GEN_OP_BITWISE_COUNT; opIndex++ ) {
		genOpBitwise_t op = (genOpBitwise_t) opIndex;

		GenerateFunctionComponentWiseBitwiseMatrix( language, type, numRows, numCols, op, sbHeader );
	}
}

void Gen_MatrixComponentWiseRelational( const genLanguage_t language, const genType_t type, const u32 numRows, const u32 numCols, stringBuilder_t* sbHeader ) {
	assert( numRows >= GEN_COMPONENT_COUNT_MIN );
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );
	assert( sbHeader );

	if ( type == GEN_TYPE_BOOL ) {
		return;
	}

	for ( u32 opIndex = 0; opIndex < GEN_OP_RELATIONAL_COUNT; opIndex++ ) {
		genOpRelational_t op = (genOpRelational_t) opIndex;

		GenerateFunctionComponentWiseRelational( language, type, numRows, numCols, op, sbHeader );
	}
}

// void Gen_MatrixBitwise( const genLanguage_t language, const genType_t type, const u32 numRows, const u32 numCols, stringBuilder_t* sbHeader ) {
// 	assert( numRows >= GEN_COMPONENT_COUNT_MIN );
// 	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
// 	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
// 	assert( numCols <= GEN_COMPONENT_COUNT_MAX );
// 	assert( sbHeader );

// 	if ( !Gen_TypeIsInteger( type ) ) {
// 		return;
// 	}

// 	if ( language == GEN_LANGUAGE_C ) {
// 		for ( u32 opIndex = 0; opIndex < GEN_OP_BITWISE_COUNT; opIndex++ ) {
// 			genOpBitwise_t op = (genOpBitwise_t) opIndex;

// 			GenerateFunctionComponentWiseBitwise( language, type, numRows, numCols, op, sbHeader );
// 		}
// 	} else {
// 		for ( u32 opIndex = 0; opIndex < GEN_OP_BITWISE_COUNT; opIndex++ ) {
// 			genOpBitwise_t op = (genOpBitwise_t) opIndex;

// 			Gen_OperatorComponentWiseBitwise( type, numRows, numCols, op, sbHeader );
// 		}
// 	}
// }

void Gen_MatrixIdentity( const genLanguage_t language, const genType_t type, const u32 numRows, const u32 numCols, stringBuilder_t* sbHeader ) {
	assert( numRows >= GEN_COMPONENT_COUNT_MIN );
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );

	const char* typeString = Gen_GetTypeString( type );

	char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	snprintf( fullTypeName, GEN_STRING_LENGTH_TYPE_NAME, "%s%dx%d", typeString, numRows, numCols );

	char vecTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	snprintf( vecTypeName, GEN_STRING_LENGTH_TYPE_NAME, "%s%d", typeString, numCols );

	char parmTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetParmTypeName( language, type, numRows, numCols, parmTypeName );

	char zeroStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	Gen_GetNumericLiteral( type, 0, zeroStr, 1 );

	char oneStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	Gen_GetNumericLiteral( type, 1, oneStr, 1 );

	const char* parmAccessStr = GEN_TYPE_ACCESS_OPERATORS[language];

	char identityFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameIdentity( language, type, numRows, numCols, identityFuncStr );

	Doc_MatrixIdentity( sbHeader, fullTypeName );
	String_Appendf( sbHeader, "inline void %s( %s mat )\n", identityFuncStr, parmTypeName );
	String_Append(  sbHeader, "{\n" );
	for ( u32 row = 0; row < numRows; row++ ) {
		String_Appendf( sbHeader, "\tmat%srows[%d] = HLML_CONSTRUCT( %s ) { ", parmAccessStr, row, vecTypeName );
		for ( u32 col = 0; col < numCols; col++ ) {
			String_Appendf( sbHeader, "%s", ( row == col ) ? oneStr : zeroStr );

			if ( col != numCols - 1 ) {
				String_Append( sbHeader, ", " );
			}
		}
		String_Append( sbHeader, " };\n" );
	}
	String_Append( sbHeader, "}\n" );
	String_Append( sbHeader, "\n" );
}

void Gen_MatrixTranspose( const genLanguage_t language, const genType_t type, const u32 numRows, const u32 numCols, stringBuilder_t* sbHeader ) {
	assert( numRows >= GEN_COMPONENT_COUNT_MIN );
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );

	const char* typeString = Gen_GetTypeString( type );

	char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	snprintf( fullTypeName, GEN_STRING_LENGTH_TYPE_NAME, "%s%dx%d", typeString, numRows, numCols );

	char parmTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetParmTypeName( language, type, numRows, numCols, parmTypeName );

	char transposeTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	snprintf( transposeTypeName, GEN_STRING_LENGTH_TYPE_NAME, "%s%dx%d", typeString, numCols, numRows );

	const char* parmAccessStr = GEN_TYPE_ACCESS_OPERATORS[language];

	char transposeFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameTranspose( language, type, numRows, numCols, transposeFuncStr );

	Doc_MatrixTranpose( sbHeader, fullTypeName );
	String_Appendf( sbHeader, "inline %s %s( const %s mat )\n", transposeTypeName, transposeFuncStr, parmTypeName );
	String_Append(  sbHeader, "{\n" );
	String_Appendf( sbHeader, "\treturn HLML_CONSTRUCT( %s ) {\n", transposeTypeName );

	// row/col iteration order reversed here because we're returning the transposed type
	for ( u32 col = 0; col < numCols; col++ ) {
		String_Append( sbHeader, "\t\t" );

		for ( u32 row = 0; row < numRows; row++ ) {
			String_Appendf( sbHeader, "mat%srows[%d].%c", parmAccessStr, row, GEN_COMPONENT_NAMES_VECTOR[col] );

			if ( row + col != ( numRows - 1 ) + ( numCols - 1 ) ) {
				String_Append( sbHeader, "," );
			}

			if ( row != numRows - 1 ) {
				String_Append( sbHeader, " " );
			} else {
				String_Append( sbHeader, "\n" );
			}
		}
	}
	String_Append( sbHeader, "\t};\n" );
	String_Append( sbHeader, "}\n" );
	String_Append( sbHeader, "\n" );
}

void Gen_MatrixInverse( const genLanguage_t language, const genType_t type, const u32 numRows, const u32 numCols, stringBuilder_t* sbHeader ) {
	assert( numRows >= GEN_COMPONENT_COUNT_MIN );
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );

	if ( !Gen_TypeIsFloatingPoint( type ) ) {
		return;
	}

	// true inverse can only be done for NxN matrices
	// only pseudo-inverse can be done for NxM matrices where N != M
	if ( numRows != numCols ) {
		return;
	}

	char oneStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	Gen_GetNumericLiteral( type, 1, oneStr, 1 );

	const char* typeString = Gen_GetTypeString( type );
	const char* memberTypeString = Gen_GetMemberTypeString( type );

	char vectorTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	snprintf( vectorTypeName, GEN_STRING_LENGTH_TYPE_NAME, "%s%d", typeString, numCols );

	char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	snprintf( fullTypeName, GEN_STRING_LENGTH_TYPE_NAME, "%s%dx%d", typeString, numRows, numCols );

	char parmTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetParmTypeName( language, type, numRows, numCols, parmTypeName );

	const char* parmAccessStr = GEN_TYPE_ACCESS_OPERATORS[language];

	char inverseFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameInverse( language, type, numRows, numCols, inverseFuncStr );

	char determinantFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameDeterminant( language, type, numRows, numCols, determinantFuncStr );

	char addVectorFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameComponentWiseArithmeticVector( language, type, 1, numCols, GEN_OP_ARITHMETIC_ADD, addVectorFuncStr );

	char subVectorFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameComponentWiseArithmeticVector( language, type, 1, numCols, GEN_OP_ARITHMETIC_SUB, subVectorFuncStr );

	char mulVectorFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameComponentWiseArithmeticVector( language, type, 1, numCols, GEN_OP_ARITHMETIC_MUL, mulVectorFuncStr );

	char mulMatrixScalarFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameComponentWiseArithmeticScalar( language, type, numRows, numCols, GEN_OP_ARITHMETIC_MUL, mulMatrixScalarFuncStr );

	Doc_MatrixInverse( sbHeader, fullTypeName );
	String_Appendf( sbHeader, "inline %s %s( const %s mat )\n", fullTypeName, inverseFuncStr, parmTypeName );
	String_Append(  sbHeader, "{\n" );

	switch ( numRows ) {
		case 2: {
			String_Appendf( sbHeader, "\tconst %s invdet = %s / %s( mat );\n", memberTypeString, oneStr, determinantFuncStr );
			String_Appendf( sbHeader, "\treturn HLML_CONSTRUCT( %s ) {\n", fullTypeName );
			String_Appendf( sbHeader, "\t\t mat%srows[1].y * invdet, -mat%srows[0].y * invdet,\n", parmAccessStr, parmAccessStr );
			String_Appendf( sbHeader, "\t\t-mat%srows[1].x * invdet,  mat%srows[0].x * invdet\n", parmAccessStr, parmAccessStr );
			String_Append(  sbHeader, "\t};\n" );
			break;
		}

		case 3: {
			String_Appendf( sbHeader, "\tconst %s invdet = %s / %s( mat );\n", memberTypeString, oneStr, determinantFuncStr );
			String_Appendf( sbHeader, "\treturn HLML_CONSTRUCT( %s ) {\n", fullTypeName );
			String_Appendf( sbHeader, "\t\t ( mat%srows[1].y * mat%srows[2].z - mat%srows[1].z * mat%srows[2].y ) * invdet,\n", parmAccessStr, parmAccessStr, parmAccessStr, parmAccessStr );
			String_Appendf( sbHeader, "\t\t-( mat%srows[0].y * mat%srows[2].z - mat%srows[0].z * mat%srows[2].y ) * invdet,\n", parmAccessStr, parmAccessStr, parmAccessStr, parmAccessStr );
			String_Appendf( sbHeader, "\t\t ( mat%srows[0].y * mat%srows[1].z - mat%srows[0].z * mat%srows[1].y ) * invdet,\n", parmAccessStr, parmAccessStr, parmAccessStr, parmAccessStr );
			String_Append(  sbHeader, "\n" );
			String_Appendf( sbHeader, "\t\t-( mat%srows[1].x * mat%srows[2].z - mat%srows[1].z * mat%srows[2].x ) * invdet,\n", parmAccessStr, parmAccessStr, parmAccessStr, parmAccessStr );
			String_Appendf( sbHeader, "\t\t ( mat%srows[0].x * mat%srows[2].z - mat%srows[0].z * mat%srows[2].x ) * invdet,\n", parmAccessStr, parmAccessStr, parmAccessStr, parmAccessStr );
			String_Appendf( sbHeader, "\t\t-( mat%srows[0].x * mat%srows[1].z - mat%srows[0].z * mat%srows[1].x ) * invdet,\n", parmAccessStr, parmAccessStr, parmAccessStr, parmAccessStr );
			String_Append(  sbHeader, "\n" );
			String_Appendf( sbHeader, "\t\t ( mat%srows[1].x * mat%srows[2].y - mat%srows[1].y * mat%srows[2].x ) * invdet,\n", parmAccessStr, parmAccessStr, parmAccessStr, parmAccessStr );
			String_Appendf( sbHeader, "\t\t-( mat%srows[0].x * mat%srows[2].y - mat%srows[0].y * mat%srows[2].x ) * invdet,\n", parmAccessStr, parmAccessStr, parmAccessStr, parmAccessStr );
			String_Appendf( sbHeader, "\t\t ( mat%srows[0].x * mat%srows[1].y - mat%srows[0].y * mat%srows[1].x ) * invdet\n", parmAccessStr, parmAccessStr, parmAccessStr, parmAccessStr );
			String_Append(  sbHeader, "\t};\n" );
			break;
		}

		case 4: {
			String_Append(  sbHeader, "\t// uses the glm version, which is basically just an optimised version of the adjugate formula\n" );
			String_Appendf( sbHeader, "\t%s sub00 = mat%srows[2].z * mat%srows[3].w - mat%srows[3].z * mat%srows[2].w;\n", memberTypeString, parmAccessStr, parmAccessStr, parmAccessStr, parmAccessStr );
			String_Appendf( sbHeader, "\t%s sub01 = mat%srows[1].z * mat%srows[3].w - mat%srows[1].w * mat%srows[2].w;\n", memberTypeString, parmAccessStr, parmAccessStr, parmAccessStr, parmAccessStr );
			String_Appendf( sbHeader, "\t%s sub02 = mat%srows[1].z * mat%srows[2].w - mat%srows[1].w * mat%srows[2].z;\n", memberTypeString, parmAccessStr, parmAccessStr, parmAccessStr, parmAccessStr );
			String_Append(  sbHeader, "\n" );
			String_Appendf( sbHeader, "\t%s sub03 = mat%srows[2].y * mat%srows[3].w - mat%srows[2].w * mat%srows[3].y;\n", memberTypeString, parmAccessStr, parmAccessStr, parmAccessStr, parmAccessStr );
			String_Appendf( sbHeader, "\t%s sub04 = mat%srows[1].y * mat%srows[3].w - mat%srows[1].w * mat%srows[3].y;\n", memberTypeString, parmAccessStr, parmAccessStr, parmAccessStr, parmAccessStr );
			String_Appendf( sbHeader, "\t%s sub05 = mat%srows[1].y * mat%srows[2].w - mat%srows[1].w * mat%srows[2].y;\n", memberTypeString, parmAccessStr, parmAccessStr, parmAccessStr, parmAccessStr );
			String_Append(  sbHeader, "\n" );
			String_Appendf( sbHeader, "\t%s sub06 = mat%srows[2].y * mat%srows[3].z - mat%srows[2].z * mat%srows[3].y;\n", memberTypeString, parmAccessStr, parmAccessStr, parmAccessStr, parmAccessStr );
			String_Appendf( sbHeader, "\t%s sub07 = mat%srows[1].y * mat%srows[3].z - mat%srows[1].z * mat%srows[3].y;\n", memberTypeString, parmAccessStr, parmAccessStr, parmAccessStr, parmAccessStr );
			String_Appendf( sbHeader, "\t%s sub08 = mat%srows[1].y * mat%srows[2].z - mat%srows[1].z * mat%srows[2].y;\n", memberTypeString, parmAccessStr, parmAccessStr, parmAccessStr, parmAccessStr );
			String_Append(  sbHeader, "\n" );
			String_Appendf( sbHeader, "\t%s sub09 = mat%srows[2].x * mat%srows[3].w - mat%srows[3].x * mat%srows[2].w;\n", memberTypeString, parmAccessStr, parmAccessStr, parmAccessStr, parmAccessStr );
			String_Appendf( sbHeader, "\t%s sub10 = mat%srows[1].x * mat%srows[3].w - mat%srows[3].x * mat%srows[1].w;\n", memberTypeString, parmAccessStr, parmAccessStr, parmAccessStr, parmAccessStr );
			String_Appendf( sbHeader, "\t%s sub11 = mat%srows[1].x * mat%srows[2].w - mat%srows[2].x * mat%srows[1].w;\n", memberTypeString, parmAccessStr, parmAccessStr, parmAccessStr, parmAccessStr );
			String_Append(  sbHeader, "\n" );
			String_Appendf( sbHeader, "\t%s sub12 = mat%srows[2].x * mat%srows[3].z - mat%srows[2].z * mat%srows[3].x;\n", memberTypeString, parmAccessStr, parmAccessStr, parmAccessStr, parmAccessStr );
			String_Appendf( sbHeader, "\t%s sub13 = mat%srows[1].x * mat%srows[3].z - mat%srows[1].z * mat%srows[3].x;\n", memberTypeString, parmAccessStr, parmAccessStr, parmAccessStr, parmAccessStr );
			String_Appendf( sbHeader, "\t%s sub14 = mat%srows[1].x * mat%srows[2].z - mat%srows[1].z * mat%srows[2].x;\n", memberTypeString, parmAccessStr, parmAccessStr, parmAccessStr, parmAccessStr );
			String_Append(  sbHeader, "\n" );
			String_Appendf( sbHeader, "\t%s sub15 = mat%srows[2].x * mat%srows[3].y - mat%srows[2].y * mat%srows[3].x;\n", memberTypeString, parmAccessStr, parmAccessStr, parmAccessStr, parmAccessStr );
			String_Appendf( sbHeader, "\t%s sub16 = mat%srows[1].x * mat%srows[3].y - mat%srows[1].y * mat%srows[3].x;\n", memberTypeString, parmAccessStr, parmAccessStr, parmAccessStr, parmAccessStr );
			String_Appendf( sbHeader, "\t%s sub17 = mat%srows[1].x * mat%srows[2].y - mat%srows[1].y * mat%srows[2].x;\n", memberTypeString, parmAccessStr, parmAccessStr, parmAccessStr, parmAccessStr );
			String_Append(  sbHeader, "\n" );
			if ( language == GEN_LANGUAGE_C ) {
				String_Appendf( sbHeader, "\t%s fac0 = (%s) { sub00, sub00, sub01, sub02 };\n", vectorTypeName, vectorTypeName );
				String_Appendf( sbHeader, "\t%s fac1 = (%s) { sub03, sub03, sub04, sub05 };\n", vectorTypeName, vectorTypeName );
				String_Appendf( sbHeader, "\t%s fac2 = (%s) { sub06, sub06, sub07, sub08 };\n", vectorTypeName, vectorTypeName );
				String_Appendf( sbHeader, "\t%s fac3 = (%s) { sub09, sub09, sub10, sub11 };\n", vectorTypeName, vectorTypeName );
				String_Appendf( sbHeader, "\t%s fac4 = (%s) { sub12, sub12, sub13, sub14 };\n", vectorTypeName, vectorTypeName );
				String_Appendf( sbHeader, "\t%s fac5 = (%s) { sub15, sub15, sub16, sub17 };\n", vectorTypeName, vectorTypeName );
				String_Append(  sbHeader, "\n" );
				String_Appendf( sbHeader, "\t%s vec0 = (%s) { mat%srows[1].x, mat%srows[0].x, mat%srows[0].x, mat%srows[0].x };\n", vectorTypeName, vectorTypeName, parmAccessStr, parmAccessStr, parmAccessStr, parmAccessStr );
				String_Appendf( sbHeader, "\t%s vec1 = (%s) { mat%srows[1].y, mat%srows[0].y, mat%srows[0].y, mat%srows[0].y };\n", vectorTypeName, vectorTypeName, parmAccessStr, parmAccessStr, parmAccessStr, parmAccessStr );
				String_Appendf( sbHeader, "\t%s vec2 = (%s) { mat%srows[1].z, mat%srows[0].z, mat%srows[0].z, mat%srows[0].z };\n", vectorTypeName, vectorTypeName, parmAccessStr, parmAccessStr, parmAccessStr, parmAccessStr );
				String_Appendf( sbHeader, "\t%s vec3 = (%s) { mat%srows[1].w, mat%srows[0].w, mat%srows[0].w, mat%srows[0].w };\n", vectorTypeName, vectorTypeName, parmAccessStr, parmAccessStr, parmAccessStr, parmAccessStr );
				String_Append(  sbHeader, "\n" );
				String_Appendf( sbHeader, "\t%s inv0mula = %s( &vec1, &fac0 );\n",     vectorTypeName, mulVectorFuncStr );
				String_Appendf( sbHeader, "\t%s inv0mulb = %s( &vec2, &fac1 );\n",     vectorTypeName, mulVectorFuncStr );
				String_Appendf( sbHeader, "\t%s inv0mulc = %s( &vec3, &fac2 );\n",     vectorTypeName, mulVectorFuncStr );
				String_Appendf( sbHeader, "\t%s inv0     = %s( &inv0mula, &inv0mulb );\n", vectorTypeName, subVectorFuncStr );
				String_Appendf( sbHeader, "\tinv0 = %s( &inv0, &inv0mulc );\n", addVectorFuncStr );
				String_Append(  sbHeader, "\n" );
				String_Appendf( sbHeader, "\t%s inv1mula = %s( &vec0, &fac0 );\n",     vectorTypeName, mulVectorFuncStr );
				String_Appendf( sbHeader, "\t%s inv1mulb = %s( &vec2, &fac3 );\n",     vectorTypeName, mulVectorFuncStr );
				String_Appendf( sbHeader, "\t%s inv1mulc = %s( &vec3, &fac4 );\n",     vectorTypeName, mulVectorFuncStr );
				String_Appendf( sbHeader, "\t%s inv1     = %s( &inv1mula, &inv1mulb );\n", vectorTypeName, subVectorFuncStr );
				String_Appendf( sbHeader, "\tinv1 = %s( &inv1, &inv1mulc );\n", addVectorFuncStr );
				String_Append(  sbHeader, "\n" );
				String_Appendf( sbHeader, "\t%s inv2mula = %s( &vec0, &fac1 );\n",     vectorTypeName, mulVectorFuncStr );
				String_Appendf( sbHeader, "\t%s inv2mulb = %s( &vec1, &fac3 );\n",     vectorTypeName, mulVectorFuncStr );
				String_Appendf( sbHeader, "\t%s inv2mulc = %s( &vec3, &fac5 );\n",     vectorTypeName, mulVectorFuncStr );
				String_Appendf( sbHeader, "\t%s inv2     = %s( &inv2mula, &inv2mulb );\n", vectorTypeName, subVectorFuncStr );
				String_Appendf( sbHeader, "\tinv2 = %s( &inv2, &inv2mulc );\n", addVectorFuncStr );
				String_Append(  sbHeader, "\n" );
				String_Appendf( sbHeader, "\t%s inv3mula = %s( &vec0, &fac2 );\n",     vectorTypeName, mulVectorFuncStr );
				String_Appendf( sbHeader, "\t%s inv3mulb = %s( &vec1, &fac4 );\n",     vectorTypeName, mulVectorFuncStr );
				String_Appendf( sbHeader, "\t%s inv3mulc = %s( &vec2, &fac5 );\n",     vectorTypeName, mulVectorFuncStr );
				String_Appendf( sbHeader, "\t%s inv3     = %s( &inv3mula, &inv3mulb );\n", vectorTypeName, subVectorFuncStr );
				String_Appendf( sbHeader, "\tinv3 = %s( &inv3, &inv3mulc );\n", addVectorFuncStr );
				String_Append(  sbHeader, "\n" );
				String_Append(  sbHeader, "\n" );
				String_Appendf( sbHeader, "\t%s sign0 = (%s) {  1, -1,  1, -1 };\n", vectorTypeName, vectorTypeName );
				String_Appendf( sbHeader, "\t%s sign1 = (%s) { -1,  1, -1,  1 };\n", vectorTypeName, vectorTypeName );
				String_Append(  sbHeader, "\n" );
				String_Appendf( sbHeader, "\t%s result = (%s) {\n", fullTypeName, fullTypeName );
				String_Appendf( sbHeader, "\t\t%s( &inv0, &sign0 ),\n", mulVectorFuncStr );
				String_Appendf( sbHeader, "\t\t%s( &inv1, &sign1 ),\n", mulVectorFuncStr );
				String_Appendf( sbHeader, "\t\t%s( &inv2, &sign0 ),\n", mulVectorFuncStr );
				String_Appendf( sbHeader, "\t\t%s( &inv3, &sign1 )\n", mulVectorFuncStr );
				String_Append(  sbHeader, "\t};\n" );
				String_Append(  sbHeader, "\n" );
				String_Appendf( sbHeader, "\t%s col0 = (%s) { result.rows[0].x, result.rows[1].x, result.rows[2].x, result.rows[3].x };\n",
					vectorTypeName, vectorTypeName, parmAccessStr, parmAccessStr, parmAccessStr, parmAccessStr );
				String_Appendf( sbHeader, "\t%s dot0 = %s( &mat%srows[0], &col0 );\n", vectorTypeName, mulVectorFuncStr, parmAccessStr );
				String_Append(  sbHeader, "\n" );
				String_Appendf( sbHeader, "\tconst %s dot1 = ( dot0.x + dot0.y ) + ( dot0.z + dot0.w );\n", memberTypeString );
				String_Append(  sbHeader, "\n" );
				String_Appendf( sbHeader, "\tconst %s invdet = %s / dot1;\n", memberTypeString, oneStr );
				String_Append(  sbHeader, "\n" );
				String_Appendf( sbHeader, "\treturn %s( &result, invdet );\n", mulMatrixScalarFuncStr );
			} else {
				String_Appendf( sbHeader, "\t%s fac0 = %s( sub00, sub00, sub01, sub02 );\n", vectorTypeName, vectorTypeName );
				String_Appendf( sbHeader, "\t%s fac1 = %s( sub03, sub03, sub04, sub05 );\n", vectorTypeName, vectorTypeName );
				String_Appendf( sbHeader, "\t%s fac2 = %s( sub06, sub06, sub07, sub08 );\n", vectorTypeName, vectorTypeName );
				String_Appendf( sbHeader, "\t%s fac3 = %s( sub09, sub09, sub10, sub11 );\n", vectorTypeName, vectorTypeName );
				String_Appendf( sbHeader, "\t%s fac4 = %s( sub12, sub12, sub13, sub14 );\n", vectorTypeName, vectorTypeName );
				String_Appendf( sbHeader, "\t%s fac5 = %s( sub15, sub15, sub16, sub17 );\n", vectorTypeName, vectorTypeName );
				String_Append(  sbHeader, "\n" );
				String_Appendf( sbHeader, "\t%s vec0 = %s( mat%srows[1].x, mat%srows[0].x, mat%srows[0].x, mat%srows[0].x );\n", vectorTypeName, vectorTypeName, parmAccessStr, parmAccessStr, parmAccessStr, parmAccessStr );
				String_Appendf( sbHeader, "\t%s vec1 = %s( mat%srows[1].y, mat%srows[0].y, mat%srows[0].y, mat%srows[0].y );\n", vectorTypeName, vectorTypeName, parmAccessStr, parmAccessStr, parmAccessStr, parmAccessStr );
				String_Appendf( sbHeader, "\t%s vec2 = %s( mat%srows[1].z, mat%srows[0].z, mat%srows[0].z, mat%srows[0].z );\n", vectorTypeName, vectorTypeName, parmAccessStr, parmAccessStr, parmAccessStr, parmAccessStr );
				String_Appendf( sbHeader, "\t%s vec3 = %s( mat%srows[1].w, mat%srows[0].w, mat%srows[0].w, mat%srows[0].w );\n", vectorTypeName, vectorTypeName, parmAccessStr, parmAccessStr, parmAccessStr, parmAccessStr );
				String_Append(  sbHeader, "\n" );
				String_Appendf( sbHeader, "\t%s inv0 = vec1 * fac0 - vec2 * fac1 + vec3 * fac2;\n", vectorTypeName );
				String_Appendf( sbHeader, "\t%s inv1 = vec0 * fac0 - vec2 * fac3 + vec3 * fac4;\n", vectorTypeName );
				String_Appendf( sbHeader, "\t%s inv2 = vec0 * fac1 - vec1 * fac3 + vec3 * fac5;\n", vectorTypeName );
				String_Appendf( sbHeader, "\t%s inv3 = vec0 * fac2 - vec1 * fac4 + vec2 * fac5;\n", vectorTypeName );
				String_Append(  sbHeader, "\n" );
				String_Appendf( sbHeader, "\t%s sign0 = %s(  1, -1,  1, -1 );\n", vectorTypeName, vectorTypeName );
				String_Appendf( sbHeader, "\t%s sign1 = %s( -1,  1, -1,  1 );\n", vectorTypeName, vectorTypeName );
				String_Append(  sbHeader, "\n" );
				String_Appendf( sbHeader, "\t%s result = %s(\n", fullTypeName, fullTypeName );
				String_Append(  sbHeader, "\t\tinv0 * sign0,\n" );
				String_Append(  sbHeader, "\t\tinv1 * sign1,\n" );
				String_Append(  sbHeader, "\t\tinv2 * sign0,\n" );
				String_Append(  sbHeader, "\t\tinv3 * sign1\n" );
				String_Append(  sbHeader, "\t);\n" );
				String_Append(  sbHeader, "\n" );
				String_Appendf( sbHeader, "\t%s col0 = %s( result%srows[0].x, result%srows[1].x, result%srows[2].x, result%srows[3].x );\n",
					vectorTypeName, vectorTypeName, parmAccessStr, parmAccessStr, parmAccessStr, parmAccessStr );
				String_Appendf( sbHeader, "\t%s dot0 = mat%srows[0] * col0;\n", vectorTypeName, parmAccessStr );
				String_Append(  sbHeader, "\n" );
				String_Appendf( sbHeader, "\tconst %s dot1 = ( dot0.x + dot0.y ) + ( dot0.z + dot0.w );\n", memberTypeString );
				String_Append(  sbHeader, "\n" );
				String_Appendf( sbHeader, "\tconst %s invdet = %s / dot1;\n", memberTypeString, oneStr );
				String_Append(  sbHeader, "\n" );
				String_Append(  sbHeader, "\treturn result * invdet;\n" );
			}
			break;
		}
	}
	String_Append( sbHeader, "}\n" );
	String_Append( sbHeader, "\n" );
}

void Gen_MatrixDeterminant( const genLanguage_t language, const genType_t type, const u32 numRows, const u32 numCols, stringBuilder_t* sbHeader ) {
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

	const char* typeString = Gen_GetTypeString( type );
	const char* memberTypeString = Gen_GetMemberTypeString( type );

	char vectorTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	snprintf( vectorTypeName, GEN_STRING_LENGTH_TYPE_NAME, "%s%d", typeString, numCols );

	char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	snprintf( fullTypeName, GEN_STRING_LENGTH_TYPE_NAME, "%s%dx%d", typeString, numRows, numCols );

	char parmTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetParmTypeName( language, type, numRows, numCols, parmTypeName );

	const char* parmAccessStr = GEN_TYPE_ACCESS_OPERATORS[language];

	char determinantFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameDeterminant( language, type, numRows, numCols, determinantFuncStr );

	Doc_MatrixDeterminant( sbHeader, fullTypeName );
	String_Appendf( sbHeader, "inline %s %s( const %s mat )\n", memberTypeString, determinantFuncStr, parmTypeName );
	String_Appendf( sbHeader, "{\n" );
	switch ( numRows ) {
		case 2: {
			String_Appendf( sbHeader, "\treturn mat%srows[0].x * mat%srows[1].y - mat%srows[1].x * mat%srows[0].y;\n", parmAccessStr, parmAccessStr, parmAccessStr, parmAccessStr );
			break;
		}

		case 3: {
			String_Append(  sbHeader, "\treturn\n" );
			String_Appendf( sbHeader, "\t\t+ mat%srows[0].x * ( mat%srows[1].y * mat%srows[2].z - mat%srows[2].y * mat%srows[1].z ) \n", parmAccessStr, parmAccessStr, parmAccessStr, parmAccessStr, parmAccessStr );
			String_Appendf( sbHeader, "\t\t- mat%srows[0].y * ( mat%srows[1].x * mat%srows[2].z - mat%srows[2].x * mat%srows[1].z ) \n", parmAccessStr, parmAccessStr, parmAccessStr, parmAccessStr, parmAccessStr );
			String_Appendf( sbHeader, "\t\t+ mat%srows[0].z * ( mat%srows[1].x * mat%srows[2].y - mat%srows[2].x * mat%srows[1].y );\n", parmAccessStr, parmAccessStr, parmAccessStr, parmAccessStr, parmAccessStr );
			break;
		}

		case 4: {
			String_Append(  sbHeader, "\t// using glm's method where you basically take determinants from each sub matrix and cache the repeat occurences\n" );
			String_Appendf( sbHeader, "\t%s sub00 = mat%srows[2].z * mat%srows[3].w - mat%srows[3].z * mat%srows[2].w;\n", memberTypeString, parmAccessStr, parmAccessStr, parmAccessStr, parmAccessStr );
			String_Appendf( sbHeader, "\t%s sub01 = mat%srows[2].y * mat%srows[3].w - mat%srows[2].w * mat%srows[3].y;\n", memberTypeString, parmAccessStr, parmAccessStr, parmAccessStr, parmAccessStr );
			String_Appendf( sbHeader, "\t%s sub02 = mat%srows[2].y * mat%srows[3].z - mat%srows[3].y * mat%srows[2].z;\n", memberTypeString, parmAccessStr, parmAccessStr, parmAccessStr, parmAccessStr );
			String_Appendf( sbHeader, "\t%s sub03 = mat%srows[2].x * mat%srows[3].w - mat%srows[3].x * mat%srows[2].w;\n", memberTypeString, parmAccessStr, parmAccessStr, parmAccessStr, parmAccessStr );
			String_Appendf( sbHeader, "\t%s sub04 = mat%srows[2].x * mat%srows[3].z - mat%srows[3].x * mat%srows[2].z;\n", memberTypeString, parmAccessStr, parmAccessStr, parmAccessStr, parmAccessStr );
			String_Appendf( sbHeader, "\t%s sub05 = mat%srows[2].x * mat%srows[3].y - mat%srows[3].x * mat%srows[2].y;\n", memberTypeString, parmAccessStr, parmAccessStr, parmAccessStr, parmAccessStr );
			String_Append(  sbHeader, "\n" );
			String_Appendf( sbHeader, "\t%s cofactor = HLML_CONSTRUCT( %s ) {\n", vectorTypeName, vectorTypeName );
			String_Appendf( sbHeader, "\t\t ( ( ( mat%srows[1].y * sub00 ) - ( mat%srows[1].z * sub01 ) ) + ( mat%srows[1].w * sub02 ) ),\n", parmAccessStr, parmAccessStr, parmAccessStr );
			String_Appendf( sbHeader, "\t\t-( ( ( mat%srows[1].x * sub00 ) - ( mat%srows[1].z * sub03 ) ) + ( mat%srows[1].w * sub04 ) ),\n", parmAccessStr, parmAccessStr, parmAccessStr );
			String_Appendf( sbHeader, "\t\t ( ( ( mat%srows[1].x * sub01 ) - ( mat%srows[1].y * sub03 ) ) + ( mat%srows[1].w * sub05 ) ),\n", parmAccessStr, parmAccessStr, parmAccessStr );
			String_Appendf( sbHeader, "\t\t-( ( ( mat%srows[1].x * sub02 ) - ( mat%srows[1].y * sub04 ) ) + ( mat%srows[1].z * sub05 ) ) \n", parmAccessStr, parmAccessStr, parmAccessStr );
			String_Append(  sbHeader, "\t};\n" );
			String_Append(  sbHeader, "\n" );
			String_Append(  sbHeader, "\treturn\n" );
			String_Appendf( sbHeader, "\t\tmat%srows[0].x * cofactor.x + mat%srows[0].y * cofactor.y +\n", parmAccessStr, parmAccessStr );
			String_Appendf( sbHeader, "\t\tmat%srows[0].z * cofactor.z + mat%srows[0].w * cofactor.w; \n", parmAccessStr, parmAccessStr );
			break;
		}
	}
	String_Append( sbHeader, "}\n" );
	String_Append( sbHeader, "\n" );
}

void Gen_MatrixTranslate( const genLanguage_t language, const genType_t type, const u32 numRows, const u32 numCols, stringBuilder_t* sbHeader ) {
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );

	if ( type == GEN_TYPE_BOOL ) {
		return;
	}

	if ( numRows < 3 || numCols < numRows ) {
		return;
	}

	u32 vecComponents = numCols - 1;

	const char* typeString = Gen_GetTypeString( type );

	char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetFullTypeName( type, numRows, numCols, fullTypeName );

	const char parmRefStr = GEN_TYPE_PARM_MODIFIERS[language];
	const char* parmAccessStr = GEN_TYPE_ACCESS_OPERATORS[language];

	char translateFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameTranslate( language, type, numRows, numCols, translateFuncStr );

	Doc_MatrixTranslate( sbHeader, fullTypeName );
	String_Appendf( sbHeader, "inline %s %s( const %s%c mat, const %s%d%c vec )\n", fullTypeName, translateFuncStr, fullTypeName, parmRefStr, typeString, vecComponents, parmRefStr );
	String_Append(  sbHeader, "{\n" );
	String_Appendf( sbHeader, "\treturn HLML_CONSTRUCT( %s ) {\n", fullTypeName );
	for ( u32 row = 0; row < numRows; row++ ) {
		String_Append(  sbHeader, "\t\t" );

		for ( u32 col = 0; col < numCols; col++ ) {
			char componentStr = GEN_COMPONENT_NAMES_VECTOR[col];
			String_Appendf( sbHeader, "mat%srows[%d].%c", parmAccessStr, row, componentStr );

			if ( col != numCols - 1 ) {
				String_Append( sbHeader, ", " );
			} else {
				if ( col == vecComponents && row < vecComponents ) {
					String_Appendf( sbHeader, " + vec%s%c", parmAccessStr, GEN_COMPONENT_NAMES_VECTOR[row] );
				}

				if ( row != numRows - 1 ) {
					String_Append( sbHeader, "," );
				}
			}
		}
		String_Append( sbHeader, "\n" );
	}
	String_Append( sbHeader, "\t};\n" );
	String_Append( sbHeader, "}\n" );
	String_Append( sbHeader, "\n" );
}

void Gen_MatrixRotate( const genLanguage_t language, const genType_t type, const u32 numRows, const u32 numCols, stringBuilder_t* sbHeader ) {
	assert( numRows >= GEN_COMPONENT_COUNT_MIN );
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );

	if ( !Gen_TypeIsFloatingPoint( type ) ) {
		return;
	}

	if ( numRows < 3 ) {
		return;
	}

	if ( numRows != numCols ) {
		return;
	}

	u32 numRotateVectorComponents = 3;

	const char* typeString = Gen_GetTypeString( type );

	char vectorTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	snprintf( vectorTypeName, GEN_STRING_LENGTH_TYPE_NAME, "%s%d", typeString, numRotateVectorComponents );

	char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	snprintf( fullTypeName, GEN_STRING_LENGTH_TYPE_NAME, "%s%dx%d", typeString, numRows, numCols );

	char oneStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	Gen_GetNumericLiteral( type, 1, oneStr, 1 );

	const char parmRefStr = GEN_TYPE_PARM_MODIFIERS[language];
	const char* parmAccessStr = GEN_TYPE_ACCESS_OPERATORS[language];

	const char* derefStr = ( language == GEN_LANGUAGE_C ) ? "*" : "";

	stringBuilder_t parmListStr = String_Create( 64 );
	String_Appendf( &parmListStr, "const %s%c mat, const %s rad", fullTypeName, parmRefStr, typeString );
	if ( numCols > 3 ) {
		String_Appendf( &parmListStr, ", const %s%c axis", vectorTypeName, parmRefStr );
	}

	const char* cosFuncStr = Gen_GetFuncNameCos( type );
	const char* sinFuncStr = Gen_GetFuncNameSin( type );

	char rotateFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameRotate( language, type, numRows, numCols, rotateFuncStr );

	char normalizedFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameNormalized( language, type, numRotateVectorComponents, normalizedFuncStr );

	char addVectorFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameComponentWiseArithmeticVector( language, type, 1, numCols, GEN_OP_ARITHMETIC_ADD, addVectorFuncStr );

	char mulScalarFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameComponentWiseArithmeticScalar( language, type, 1, numCols, GEN_OP_ARITHMETIC_MUL, mulScalarFuncStr );

	char matrixMulFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameMatrixMultiply( language, type, numRows, numCols, matrixMulFuncStr );

	Doc_MatrixRotate( sbHeader, fullTypeName );
	String_Appendf( sbHeader, "inline %s %s( %s )\n", fullTypeName, rotateFuncStr, parmListStr.str );
	String_Append(  sbHeader, "{\n" );
	String_Appendf( sbHeader, "\tconst %s c = %s( rad );\n", typeString, cosFuncStr );
	String_Appendf( sbHeader, "\tconst %s s = %s( rad );\n", typeString, sinFuncStr );
	String_Append(  sbHeader, "\n" );

	switch ( numCols ) {
		case 3: {
			if ( language == GEN_LANGUAGE_C ) {
				String_Appendf( sbHeader, "\t%s row0_cos  = %s( &mat%srows[0], c );\n",  vectorTypeName, mulScalarFuncStr, parmAccessStr );
				String_Appendf( sbHeader, "\t%s row0_sin  = %s( &mat%srows[0], s );\n",  vectorTypeName, mulScalarFuncStr, parmAccessStr );
				String_Appendf( sbHeader, "\t%s row1_nsin = %s( &mat%srows[1], -s );\n", vectorTypeName, mulScalarFuncStr, parmAccessStr );
				String_Appendf( sbHeader, "\t%s row1_cos  = %s( &mat%srows[1], c );\n",  vectorTypeName, mulScalarFuncStr, parmAccessStr );
				String_Append(  sbHeader, "\n" );
				String_Appendf( sbHeader, "\treturn (%s) {\n", fullTypeName );
				String_Appendf( sbHeader, "\t\t%s( &row0_cos, &row1_nsin ),\n", addVectorFuncStr );
				String_Appendf( sbHeader, "\t\t%s( &row0_sin, &row1_cos  ),\n", addVectorFuncStr );
				String_Appendf( sbHeader, "\t\tmat%srows[2]\n", parmAccessStr );
				String_Append(  sbHeader, "\t};\n" );
			} else {
				String_Appendf( sbHeader, "\treturn %s(\n", fullTypeName );
				String_Appendf( sbHeader, "\t\tmat%srows[0] * c + mat%srows[1] * -s,\n", parmAccessStr, parmAccessStr );
				String_Appendf( sbHeader, "\t\tmat%srows[0] * s + mat%srows[1] * c,\n", parmAccessStr, parmAccessStr );
				String_Appendf( sbHeader, "\t\tmat%srows[2]\n", parmAccessStr );
				String_Append(  sbHeader, "\t);\n" );
			}
			break;
		}

		case 4: {
			String_Appendf( sbHeader, "\t%s u = %s( axis );\n", vectorTypeName, normalizedFuncStr );
			String_Appendf( sbHeader, "\t%s ic = %s - c;\n", typeString, oneStr );
			String_Append(  sbHeader, "\n" );
			String_Appendf( sbHeader, "\t%s rotation = %smat;\n", fullTypeName, derefStr );
			String_Append(  sbHeader, "\trotation.rows[0].x = c + u.x * ic;\n" );
			String_Append(  sbHeader, "\trotation.rows[0].y = u.x * u.y * ic - u.z * s;\n" );
			String_Append(  sbHeader, "\trotation.rows[0].z = u.x * u.z * ic + u.y * s;\n" );
			String_Append(  sbHeader, "\n" );
			String_Append(  sbHeader, "\trotation.rows[1].x = u.y * u.x * ic + u.z * s;\n" );
			String_Append(  sbHeader, "\trotation.rows[1].y = c + u.y * ic;\n" );
			String_Append(  sbHeader, "\trotation.rows[1].z = u.y * u.z * ic - u.x * s;\n" );
			String_Append(  sbHeader, "\n" );
			String_Append(  sbHeader, "\trotation.rows[2].x = u.z * u.x * ic - u.y * s;\n" );
			String_Append(  sbHeader, "\trotation.rows[2].y = u.z * u.y * ic + u.x * s;\n" );
			String_Append(  sbHeader, "\trotation.rows[2].z = c + u.z * ic;\n" );
			String_Append(  sbHeader, "\n" );
			if ( language == GEN_LANGUAGE_C ) {
				String_Appendf( sbHeader, "\treturn %s( mat, &rotation );\n", matrixMulFuncStr );
			} else {
				String_Append(  sbHeader, "\treturn mat * rotation;\n" );
			}
			break;
		}

		default:
			assert( false );	// should never make it here!
			break;
	}
	String_Append( sbHeader, "}\n" );
	String_Append( sbHeader, "\n" );
}

void Gen_MatrixScale( const genLanguage_t language, const genType_t type, const u32 numRows, const u32 numCols, stringBuilder_t* sbHeader ) {
	assert( numRows >= GEN_COMPONENT_COUNT_MIN );
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );

	if ( type == GEN_TYPE_BOOL ) {
		return;
	}

	if ( numCols < 3 ) {
		return;
	}

	const char* typeString = Gen_GetTypeString( type );

	char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	snprintf( fullTypeName, GEN_STRING_LENGTH_TYPE_NAME, "%s%dx%d", typeString, numRows, numCols );

	char parmTypeNameMatrix[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetParmTypeName( language, type, numRows, numCols, parmTypeNameMatrix );

	u32 numScaleComponents = GEN_MIN( numRows, numCols );
	numScaleComponents = GEN_MAX( numScaleComponents - 1, 2 );

	char scaleVectorString[GEN_STRING_LENGTH_TYPE_NAME];
	snprintf( scaleVectorString, GEN_STRING_LENGTH_TYPE_NAME, "%s%d", typeString, numScaleComponents );

	char parmTypeNameScaleVec[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetParmTypeName( language, type, 1, numScaleComponents, parmTypeNameScaleVec );

	const char* parmAccessStr = GEN_TYPE_ACCESS_OPERATORS[language];

	char scaleFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameScale( language, type, numRows, numCols, scaleFuncStr );

	Doc_MatrixScaleNonUniform( sbHeader, fullTypeName );
	String_Appendf( sbHeader, "inline %s %s( const %s mat, const %s vec )\n", fullTypeName, scaleFuncStr, parmTypeNameMatrix, parmTypeNameScaleVec );
	String_Append(  sbHeader, "{\n" );
	String_Appendf( sbHeader, "\treturn HLML_CONSTRUCT( %s ) {\n", fullTypeName );

	for ( u32 row = 0; row < numRows; row++ ) {
		char componentStrRow = GEN_COMPONENT_NAMES_VECTOR[row];

		for ( u32 col = 0; col < numCols; col++ ) {
			char componentStrCol = GEN_COMPONENT_NAMES_VECTOR[col];
			String_Appendf( sbHeader, "\t\tmat%srows[%d].%c", parmAccessStr, row, componentStrCol );

			if ( row == col && col < numScaleComponents ) {
				String_Appendf( sbHeader, " * vec%s%c", parmAccessStr, componentStrRow );
			}

			if ( row + col != ( numRows - 1 ) + ( numCols - 1 ) ) {
				String_Append( sbHeader, ",\n" );
			} else {
				String_Append( sbHeader, "\n" );
			}
		}

		if ( row != numRows - 1 ) {
			String_Append( sbHeader, "\n" );
		}
	}
	String_Append( sbHeader, "\t};\n" );
	String_Append( sbHeader, "}\n" );
	String_Append( sbHeader, "\n" );
}

void Gen_MatrixOrtho( const genLanguage_t language, const genType_t type, const u32 numRows, const u32 numCols, stringBuilder_t* sbHeader ) {
	assert( numRows >= GEN_COMPONENT_COUNT_MIN );
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );

	if ( !Gen_TypeIsFloatingPoint( type ) ) {
		return;
	}

	if ( numRows < 4 || numCols < 4 ) {
		return;
	}

	const char* typeString = Gen_GetTypeString( type );

	char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	snprintf( fullTypeName, GEN_STRING_LENGTH_TYPE_NAME, "%s%dx%d", typeString, numRows, numCols );

	char minusTwoStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	char minusOneStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	char zeroStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	char oneStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	char twoStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];

	Gen_GetNumericLiteral( type, -2, minusTwoStr, 1 );
	Gen_GetNumericLiteral( type, -1, minusOneStr, 1 );
	Gen_GetNumericLiteral( type,  0, zeroStr, 1 );
	Gen_GetNumericLiteral( type,  1, oneStr, 1 );
	Gen_GetNumericLiteral( type,  2, twoStr, 1 );

	genHand_t hand;
	genClipSpace_t range;

	const char* handStr;
	const char* rangeStr;

	char funcStr[GEN_STRING_LENGTH_FUNCTION_NAME];

	// left-hand, zero to one
	{
		hand = GEN_HAND_LEFT;
		range = GEN_CLIP_SPACE_ZERO_TO_ONE;

		handStr = Gen_GetHandString( hand );
		rangeStr = Gen_GetClipSpaceRangeString( range );

		Gen_GetFuncNameOrtho( language, type, numRows, numCols, hand, range, funcStr );

		Doc_MatrixOrtho( sbHeader, fullTypeName, hand, range );
		String_Appendf( sbHeader, "inline %s %s( const %s left, const %s right, const %s top, const %s bottom, const %s znear, const %s zfar )\n",
			fullTypeName, funcStr, typeString, typeString, typeString, typeString, typeString, typeString );
		String_Append(  sbHeader, "{\n" );
		String_Appendf( sbHeader, "\t// %s-handed, clip-space range: %s\n", handStr, rangeStr );
		String_Appendf( sbHeader, "\tconst %s right_minus_left = right - left;\n", typeString );
		String_Appendf( sbHeader, "\tconst %s right_plus_left = right + left;\n", typeString );
		String_Appendf( sbHeader, "\tconst %s top_minus_bottom = top - bottom;\n", typeString );
		String_Appendf( sbHeader, "\tconst %s top_plus_bottom = top + bottom;\n", typeString );
		String_Appendf( sbHeader, "\tconst %s far_minus_near = zfar - znear;\n", typeString );
		String_Append(  sbHeader, "\n" );
		String_Appendf( sbHeader, "\treturn HLML_CONSTRUCT( %s ) {\n", fullTypeName );
		String_Appendf( sbHeader, "\t\t%s / right_minus_left, %s, %s, -right_plus_left / right_minus_left,\n", twoStr, zeroStr, zeroStr );
		String_Appendf( sbHeader, "\t\t%s, %s / top_minus_bottom, %s, -top_plus_bottom / top_minus_bottom,\n", zeroStr, twoStr, zeroStr );
		String_Appendf( sbHeader, "\t\t%s, %s, %s / far_minus_near, -znear / far_minus_near,\n", zeroStr, zeroStr, oneStr );
		String_Appendf( sbHeader, "\t\t%s, %s, %s, %s\n", zeroStr, zeroStr, zeroStr, oneStr );
		String_Append(  sbHeader, "\t};\n" );
		String_Append(  sbHeader, "}\n" );
		String_Append(  sbHeader, "\n" );
	}

	// left-hand, minus-one to one
	{
		hand = GEN_HAND_LEFT;
		range = GEN_CLIP_SPACE_MINUS_ONE_TO_ONE;

		handStr = Gen_GetHandString( hand );
		rangeStr = Gen_GetClipSpaceRangeString( range );

		Gen_GetFuncNameOrtho( language, type, numRows, numCols, hand, range, funcStr );

		Doc_MatrixOrtho( sbHeader, fullTypeName, hand, range );
		String_Appendf( sbHeader, "inline %s %s( const %s left, const %s right, const %s top, const %s bottom, const %s znear, const %s zfar )\n",
			fullTypeName, funcStr, typeString, typeString, typeString, typeString, typeString, typeString );
		String_Append(  sbHeader, "{\n" );
		String_Appendf( sbHeader, "\t// %s-handed, clip-space range: %s\n", handStr, rangeStr );
		String_Appendf( sbHeader, "\tconst %s right_minus_left = right - left;\n", typeString );
		String_Appendf( sbHeader, "\tconst %s right_plus_left = right + left;\n", typeString );
		String_Appendf( sbHeader, "\tconst %s top_minus_bottom = top - bottom;\n", typeString );
		String_Appendf( sbHeader, "\tconst %s top_plus_bottom = top + bottom;\n", typeString );
		String_Appendf( sbHeader, "\tconst %s far_minus_near = zfar - znear;\n", typeString );
		String_Appendf( sbHeader, "\tconst %s far_plus_near = zfar + znear;\n", typeString );
		String_Append(  sbHeader, "\n" );
		String_Appendf( sbHeader, "\treturn HLML_CONSTRUCT( %s ) {\n", fullTypeName );
		String_Appendf( sbHeader, "\t\t%s / right_minus_left, %s, %s, -right_plus_left / right_minus_left,\n", twoStr, zeroStr, zeroStr );
		String_Appendf( sbHeader, "\t\t%s, %s / top_minus_bottom, %s, -top_plus_bottom / top_minus_bottom,\n", zeroStr, twoStr, zeroStr );
		String_Appendf( sbHeader, "\t\t%s, %s, %s / far_minus_near, -far_plus_near / far_minus_near,\n", zeroStr, zeroStr, twoStr );
		String_Appendf( sbHeader, "\t\t%s, %s, %s, %s\n", zeroStr, zeroStr, zeroStr, oneStr );
		String_Append(  sbHeader, "\t};\n" );
		String_Append(  sbHeader, "}\n" );
		String_Append(  sbHeader, "\n" );
	}
	
	// right-hand, zero to one
	{
		hand = GEN_HAND_RIGHT;
		range = GEN_CLIP_SPACE_ZERO_TO_ONE;

		handStr = Gen_GetHandString( hand );
		rangeStr = Gen_GetClipSpaceRangeString( range );

		Gen_GetFuncNameOrtho( language, type, numRows, numCols, hand, range, funcStr );

		Doc_MatrixOrtho( sbHeader, fullTypeName, hand, range );
		String_Appendf( sbHeader, "inline %s %s( const %s left, const %s right, const %s top, const %s bottom, const %s znear, const %s zfar )\n",
			fullTypeName, funcStr, typeString, typeString, typeString, typeString, typeString, typeString );
		String_Append(  sbHeader, "{\n" );
		String_Appendf( sbHeader, "\t// %s-handed, clip-space range: %s\n", handStr, rangeStr );
		String_Appendf( sbHeader, "\tconst %s right_minus_left = right - left;\n", typeString );
		String_Appendf( sbHeader, "\tconst %s right_plus_left = right + left;\n", typeString );
		String_Appendf( sbHeader, "\tconst %s top_minus_bottom = top - bottom;\n", typeString );
		String_Appendf( sbHeader, "\tconst %s top_plus_bottom = top + bottom;\n", typeString );
		String_Appendf( sbHeader, "\tconst %s far_minus_near = zfar - znear;\n", typeString );
		String_Append(  sbHeader, "\n" );
		String_Appendf( sbHeader, "\treturn HLML_CONSTRUCT( %s ) {\n", fullTypeName );
		String_Appendf( sbHeader, "\t\t%s / right_minus_left, %s, %s, -right_plus_left / right_minus_left,\n", twoStr, zeroStr, zeroStr );
		String_Appendf( sbHeader, "\t\t%s, %s / top_minus_bottom, %s, -top_plus_bottom / top_minus_bottom,\n", zeroStr, twoStr, zeroStr );
		String_Appendf( sbHeader, "\t\t%s, %s, %s / far_minus_near, -znear / far_minus_near,\n", zeroStr, zeroStr, minusOneStr );
		String_Appendf( sbHeader, "\t\t%s, %s, %s, %s\n", zeroStr, zeroStr, zeroStr, oneStr );
		String_Append(  sbHeader, "\t};\n" );
		String_Append(  sbHeader, "}\n" );
		String_Append(  sbHeader, "\n" );
	}

	// right-hand, minus-one to one
	{
		hand = GEN_HAND_RIGHT;
		range = GEN_CLIP_SPACE_MINUS_ONE_TO_ONE;

		handStr = Gen_GetHandString( hand );
		rangeStr = Gen_GetClipSpaceRangeString( range );

		Gen_GetFuncNameOrtho( language, type, numRows, numCols, hand, range, funcStr );

		Doc_MatrixOrtho( sbHeader, fullTypeName, hand, range );
		String_Appendf( sbHeader, "inline %s %s( const %s left, const %s right, const %s top, const %s bottom, const %s znear, const %s zfar )\n",
			fullTypeName, funcStr, typeString, typeString, typeString, typeString, typeString, typeString );
		String_Append(  sbHeader, "{\n" );
		String_Appendf( sbHeader, "\t// %s-handed, clip-space range: %s\n", handStr, rangeStr );
		String_Appendf( sbHeader, "\tconst %s right_minus_left = right - left;\n", typeString );
		String_Appendf( sbHeader, "\tconst %s right_plus_left = right + left;\n", typeString );
		String_Appendf( sbHeader, "\tconst %s top_minus_bottom = top - bottom;\n", typeString );
		String_Appendf( sbHeader, "\tconst %s top_plus_bottom = top + bottom;\n", typeString );
		String_Appendf( sbHeader, "\tconst %s far_minus_near = zfar - znear;\n", typeString );
		String_Appendf( sbHeader, "\tconst %s far_plus_near = zfar + znear;\n", typeString );
		String_Append(  sbHeader, "\n" );
		String_Appendf( sbHeader, "\treturn HLML_CONSTRUCT( %s ) {\n", fullTypeName );
		String_Appendf( sbHeader, "\t\t%s / right_minus_left, %s, %s, -right_plus_left / right_minus_left,\n", twoStr, zeroStr, zeroStr );
		String_Appendf( sbHeader, "\t\t%s, %s / top_minus_bottom, %s, -top_plus_bottom / top_minus_bottom,\n", zeroStr, twoStr, zeroStr );
		String_Appendf( sbHeader, "\t\t%s, %s, %s / far_minus_near, -far_plus_near / far_minus_near,\n", zeroStr, zeroStr, minusTwoStr );
		String_Appendf( sbHeader, "\t\t%s, %s, %s, %s\n", zeroStr, zeroStr, zeroStr, oneStr );
		String_Append(  sbHeader, "\t};\n" );
		String_Append(  sbHeader, "}\n" );
		String_Append(  sbHeader, "\n" );
	}
}

void Gen_MatrixPerspective( const genLanguage_t language, const genType_t type, const u32 numRows, const u32 numCols, stringBuilder_t* sbHeader ) {
	assert( numRows >= GEN_COMPONENT_COUNT_MIN );
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );

	if ( !Gen_TypeIsFloatingPoint( type ) ) {
		return;
	}

	if ( numRows != 4 || numCols != 4 ) {
		return;
	}

	const char* typeString = Gen_GetTypeString( type );

	char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	snprintf( fullTypeName, GEN_STRING_LENGTH_TYPE_NAME, "%s%dx%d", typeString, numRows, numCols );

	char minusOneStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	char zeroStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	char halfStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	char oneStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	char twoStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];

	Gen_GetNumericLiteral( type, -1.0f, minusOneStr, 1 );
	Gen_GetNumericLiteral( type,  0.0f, zeroStr, 1 );
	Gen_GetNumericLiteral( type,  0.5f, halfStr, 1 );
	Gen_GetNumericLiteral( type,  1.0f, oneStr, 1 );
	Gen_GetNumericLiteral( type,  2.0f, twoStr, 1 );

	const char* tanFuncStr = Gen_GetFuncNameTan( type );

	genHand_t hand;
	genClipSpace_t range;

	const char* handStr;
	const char* rangeStr;

	char funcStr[GEN_STRING_LENGTH_FUNCTION_NAME];

	// left-handed, zero to one
	{
		hand = GEN_HAND_LEFT;
		range = GEN_CLIP_SPACE_ZERO_TO_ONE;

		handStr = Gen_GetHandString( hand );
		rangeStr = Gen_GetClipSpaceRangeString( range );

		Gen_GetFuncNamePerspective( language, type, numRows, numCols, hand, range, funcStr );

		Doc_MatrixPerspective( sbHeader, fullTypeName, hand, range );
		String_Appendf( sbHeader, "inline %s %s( const %s fovdeg, const %s aspect, const %s znear, const %s zfar )\n",
			fullTypeName, funcStr, typeString, typeString, typeString, typeString );
		String_Appendf( sbHeader, "{\n" );
		String_Appendf( sbHeader, "\t// %s-handed, clip space range: %s\n", handStr, rangeStr );
		String_Appendf( sbHeader, "\tconst %s far_minus_near = zfar - znear;\n", typeString );
		String_Appendf( sbHeader, "\tconst %s tan_half_fov = %s( fovdeg * %s );\n", typeString, tanFuncStr, halfStr );
		String_Append(  sbHeader, "\n" );
		String_Appendf( sbHeader, "\treturn HLML_CONSTRUCT( %s ) {\n", fullTypeName );
		String_Appendf( sbHeader, "\t\t%s / ( aspect * tan_half_fov ), %s, %s, %s,\n", oneStr, zeroStr, zeroStr, zeroStr );
		String_Appendf( sbHeader, "\t\t%s, %s / tan_half_fov, %s, %s,\n", zeroStr, oneStr, zeroStr, zeroStr );
		String_Appendf( sbHeader, "\t\t%s, %s, zfar / far_minus_near, -( zfar * znear ) / far_minus_near,\n", zeroStr, zeroStr );
		String_Appendf( sbHeader, "\t\t%s, %s, %s, %s\n", zeroStr, zeroStr, oneStr, zeroStr );
		String_Append(  sbHeader, "\t};\n" );
		String_Append(  sbHeader, "}\n" );
		String_Append(  sbHeader, "\n" );
	}

	// left-handed, minus-one to one
	{
		hand = GEN_HAND_LEFT;
		range = GEN_CLIP_SPACE_MINUS_ONE_TO_ONE;

		handStr = Gen_GetHandString( hand );
		rangeStr = Gen_GetClipSpaceRangeString( range );

		Gen_GetFuncNamePerspective( language, type, numRows, numCols, hand, range, funcStr );

		Doc_MatrixPerspective( sbHeader, fullTypeName, hand, range );
		String_Appendf( sbHeader, "inline %s %s( const %s fovdeg, const %s aspect, const %s znear, const %s zfar )\n",
			fullTypeName, funcStr, typeString, typeString, typeString, typeString );
		String_Append(  sbHeader, "{\n" );
		String_Appendf( sbHeader, "\t// %s-handed, clip space range: %s\n", handStr, rangeStr );
		String_Appendf( sbHeader, "\tconst %s far_minus_near = zfar - znear;\n", typeString );
		String_Appendf( sbHeader, "\tconst %s far_plus_near = zfar + znear;\n", typeString );
		String_Appendf( sbHeader, "\tconst %s tan_half_fov = %s( fovdeg * %s );\n", typeString, tanFuncStr, halfStr );
		String_Append(  sbHeader, "\n" );
		String_Appendf( sbHeader, "\treturn HLML_CONSTRUCT( %s ) {\n", fullTypeName );
		String_Appendf( sbHeader, "\t\t%s / ( aspect * tan_half_fov ), %s, %s, %s,\n", oneStr, zeroStr, zeroStr, zeroStr );
		String_Appendf( sbHeader, "\t\t%s, %s / tan_half_fov, %s, %s,\n", zeroStr, oneStr, zeroStr, zeroStr );
		String_Appendf( sbHeader, "\t\t%s, %s, far_plus_near / far_minus_near, -( %s * zfar * znear ) / far_minus_near,\n", zeroStr, zeroStr, twoStr );
		String_Appendf( sbHeader, "\t\t%s, %s, %s, %s\n", zeroStr, zeroStr, oneStr, zeroStr );
		String_Append(  sbHeader, "\t};\n" );
		String_Append(  sbHeader, "}\n" );
		String_Append(  sbHeader, "\n" );
	}

	// right-handed, zero to one
	{
		hand = GEN_HAND_RIGHT;
		range = GEN_CLIP_SPACE_ZERO_TO_ONE;

		handStr = Gen_GetHandString( hand );
		rangeStr = Gen_GetClipSpaceRangeString( range );

		Gen_GetFuncNamePerspective( language, type, numRows, numCols, hand, range, funcStr );

		Doc_MatrixPerspective( sbHeader, fullTypeName, hand, range );
		String_Appendf( sbHeader, "inline %s %s( const %s fovdeg, const %s aspect, const %s znear, const %s zfar )\n",
			fullTypeName, funcStr, typeString, typeString, typeString, typeString );
		String_Append(  sbHeader, "{\n" );
		String_Appendf( sbHeader, "\t// %s-handed, clip space range: %s\n", handStr, rangeStr );
		String_Appendf( sbHeader, "\tconst %s tan_half_fov = %s( fovdeg * %s );\n", typeString, tanFuncStr, halfStr );
		String_Append(  sbHeader, "\n" );
		String_Appendf( sbHeader, "\treturn HLML_CONSTRUCT( %s ) {\n", fullTypeName );
		String_Appendf( sbHeader, "\t\t%s / ( aspect * tan_half_fov ), %s, %s, %s,\n", oneStr, zeroStr, zeroStr, zeroStr );
		String_Appendf( sbHeader, "\t\t%s, %s / tan_half_fov, %s, %s,\n", zeroStr, oneStr, zeroStr, zeroStr );
		String_Appendf( sbHeader, "\t\t%s, %s, zfar / ( znear - zfar ), -( zfar * znear ) / ( zfar - znear ),\n", zeroStr, zeroStr );
		String_Appendf( sbHeader, "\t\t%s, %s, %s, %s\n", zeroStr, zeroStr, minusOneStr, zeroStr );
		String_Append(  sbHeader, "\t};\n" );
		String_Append(  sbHeader, "}\n" );
		String_Append(  sbHeader, "\n" );
	}

	// right-handed, minus-one to one
	{
		hand = GEN_HAND_RIGHT;
		range = GEN_CLIP_SPACE_MINUS_ONE_TO_ONE;

		handStr = Gen_GetHandString( hand );
		rangeStr = Gen_GetClipSpaceRangeString( range );

		Gen_GetFuncNamePerspective( language, type, numRows, numCols, hand, range, funcStr );

		Doc_MatrixPerspective( sbHeader, fullTypeName, hand, range );
		String_Appendf( sbHeader, "inline %s %s( const %s fovdeg, const %s aspect, const %s znear, const %s zfar )\n",
			fullTypeName, funcStr, typeString, typeString, typeString, typeString );
		String_Append(  sbHeader, "{\n" );
		String_Appendf( sbHeader, "\t// %s-handed, clip space range: %s\n", handStr, rangeStr );
		String_Appendf( sbHeader, "\tconst %s far_minus_near = zfar - znear;\n", typeString );
		String_Appendf( sbHeader, "\tconst %s far_plus_near = zfar + znear;\n", typeString );
		String_Appendf( sbHeader, "\tconst %s tan_half_fov = %s( fovdeg * %s );\n", typeString, tanFuncStr, halfStr );
		String_Append(  sbHeader, "\n" );
		String_Appendf( sbHeader, "\treturn HLML_CONSTRUCT( %s ) {\n", fullTypeName );
		String_Appendf( sbHeader, "\t\t%s / ( aspect * tan_half_fov ), %s, %s, %s,\n", oneStr, zeroStr, zeroStr, zeroStr );
		String_Appendf( sbHeader, "\t\t%s, %s / tan_half_fov, %s, %s,\n", zeroStr, oneStr, zeroStr, zeroStr );
		String_Appendf( sbHeader, "\t\t%s, %s, -far_plus_near / far_minus_near, -( %s * zfar * znear ) / far_minus_near,\n", zeroStr, zeroStr, twoStr );
		String_Appendf( sbHeader, "\t\t%s, %s, %s, %s\n", zeroStr, zeroStr, minusOneStr, zeroStr );
		String_Append(  sbHeader, "\t};\n" );
		String_Append(  sbHeader, "}\n" );
		String_Append(  sbHeader, "\n" );
	}
}

void Gen_MatrixLookAt( const genLanguage_t language, const genType_t type, const u32 numRows, const u32 numCols, stringBuilder_t* sbHeader ) {
	assert( numRows >= GEN_COMPONENT_COUNT_MIN );
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );

	if ( !Gen_TypeIsFloatingPoint( type ) ) {
		return;
	}

	if ( numRows != 4 || numCols != 4 ) {
		return;
	}

	u32 numVecComponents = 3;

	const char* typeString = Gen_GetTypeString( type );

	char zeroStr[GEN_STRING_LENGTH_NUMERIC_LITERAL] = { 0 };
	char oneStr[GEN_STRING_LENGTH_NUMERIC_LITERAL] = { 0 };

	Gen_GetNumericLiteral( type, 0.0f, zeroStr, 1 );
	Gen_GetNumericLiteral( type, 1.0f, oneStr, 1 );

	char vectorTypeString[GEN_STRING_LENGTH_TYPE_NAME] = { 0 };
	snprintf( vectorTypeString, GEN_STRING_LENGTH_TYPE_NAME, "%s%d", typeString, numVecComponents );

	char vectorParmTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetParmTypeName( language, type, 1, numVecComponents, vectorParmTypeName );

	char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME] = { 0 };
	snprintf( fullTypeName, GEN_STRING_LENGTH_TYPE_NAME, "%s%dx%d", typeString, numRows, numCols );

	char normalizedFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameNormalized( language, type, numVecComponents, normalizedFuncStr );

	char crossFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameCross( language, type, numVecComponents, crossFuncStr );

	char vectorCompWiseSubFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameComponentWiseArithmeticVector( language, type, 1, numVecComponents, GEN_OP_ARITHMETIC_SUB, vectorCompWiseSubFuncStr );

	char dotFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameDot( language, type, numVecComponents, dotFuncStr );

	char funcStr[GEN_STRING_LENGTH_FUNCTION_NAME];

	// left-handed
	{
		Gen_GetFuncNameLookAt( language, type, numRows, numCols, GEN_HAND_LEFT, funcStr );

		Doc_MatrixLookAt( sbHeader, fullTypeName, GEN_HAND_LEFT );
		String_Appendf( sbHeader, "inline %s %s( const %s eye, const %s target, const %s up )\n",
			fullTypeName, funcStr, vectorParmTypeName, vectorParmTypeName, vectorParmTypeName );
		String_Append(  sbHeader, "{\n" );
		String_Append(  sbHeader, "\t// left handed\n" );
		if ( language == GEN_LANGUAGE_C ) {
			String_Appendf( sbHeader, "\tconst %s eye_to_target = %s( target, eye );\n", vectorTypeString, vectorCompWiseSubFuncStr );
			String_Appendf( sbHeader, "\tconst %s forward = %s( &eye_to_target );\n", vectorTypeString, normalizedFuncStr );
			String_Appendf( sbHeader, "\tconst %s up_cross_forward = %s( up, &forward );\n", vectorTypeString, crossFuncStr );
			String_Appendf( sbHeader, "\tconst %s right = %s( &up_cross_forward );\n", vectorTypeString, normalizedFuncStr );
			String_Appendf( sbHeader, "\tconst %s up1 = %s( &forward, &right );\n", vectorTypeString, crossFuncStr );
		} else {
			String_Appendf( sbHeader, "\tconst %s forward = %s( target - eye );\n", vectorTypeString, normalizedFuncStr );
			String_Appendf( sbHeader, "\tconst %s right = %s( %s( up, forward ) );\n", vectorTypeString, normalizedFuncStr, crossFuncStr );
			String_Appendf( sbHeader, "\tconst %s up1 = %s( forward, right );\n", vectorTypeString, crossFuncStr );
		}
		String_Append(  sbHeader, "\n" );
		String_Appendf( sbHeader, "\treturn HLML_CONSTRUCT( %s ) {\n", fullTypeName );
		if ( language == GEN_LANGUAGE_C ) {
			String_Appendf( sbHeader, "\t\tright.x,   right.y,   right.z,   -%s( &right, eye ),\n", dotFuncStr );
			String_Appendf( sbHeader, "\t\tup1.x,     up1.y,     up1.z,     -%s( &up1, eye ),\n", dotFuncStr );
			String_Appendf( sbHeader, "\t\tforward.x, forward.y, forward.z, -%s( &forward, eye ),\n", dotFuncStr );
		} else {
			String_Appendf( sbHeader, "\t\tright.x,   right.y,   right.z,   -%s( right, eye ),\n", dotFuncStr );
			String_Appendf( sbHeader, "\t\tup1.x,     up1.y,     up1.z,     -%s( up1, eye ),\n", dotFuncStr );
			String_Appendf( sbHeader, "\t\tforward.x, forward.y, forward.z, -%s( forward, eye ),\n", dotFuncStr );
		}
		String_Appendf( sbHeader, "\t\t%s, %s, %s, %s\n", zeroStr, zeroStr, zeroStr, oneStr );
		String_Append(  sbHeader, "\t};\n" );
		String_Append(  sbHeader, "}\n" );
		String_Append(  sbHeader, "\n" );
	}

	// right-handed
	{
		Gen_GetFuncNameLookAt( language, type, numRows, numCols, GEN_HAND_RIGHT, funcStr );

		Doc_MatrixLookAt( sbHeader, fullTypeName, GEN_HAND_RIGHT );
		String_Appendf( sbHeader, "inline %s %s( const %s eye, const %s target, const %s up )\n",
			fullTypeName, funcStr, vectorParmTypeName, vectorParmTypeName, vectorParmTypeName );
		String_Append(  sbHeader, "{\n" );
		String_Append(  sbHeader, "\t// right handed\n" );
		if ( language == GEN_LANGUAGE_C ) {
			String_Appendf( sbHeader, "\tconst %s eye_to_target = %s( target, eye );\n", vectorTypeString, vectorCompWiseSubFuncStr );
			String_Appendf( sbHeader, "\tconst %s forward = %s( &eye_to_target );\n", vectorTypeString, normalizedFuncStr );
			String_Appendf( sbHeader, "\tconst %s forward_cross_up = %s( &forward, up );\n", vectorTypeString, crossFuncStr );
			String_Appendf( sbHeader, "\tconst %s right = %s( &forward_cross_up );\n", vectorTypeString, normalizedFuncStr );
			String_Appendf( sbHeader, "\tconst %s up1 = %s( &right, &forward );\n", vectorTypeString, crossFuncStr );
		} else {
			String_Appendf( sbHeader, "\tconst %s forward = normalized( target - eye );\n", vectorTypeString );
			String_Appendf( sbHeader, "\tconst %s right = normalized( cross( forward, up ) );\n", vectorTypeString );
			String_Appendf( sbHeader, "\tconst %s up1 = cross( right, forward );\n", vectorTypeString );
		}
		String_Append(  sbHeader, "\n" );
		String_Appendf( sbHeader, "\treturn HLML_CONSTRUCT( %s ) {\n", fullTypeName );
		if ( language == GEN_LANGUAGE_C ) {
			String_Appendf( sbHeader, "\t\t right.x,    right.y,    right.z,   -%s( &right, eye ),\n", dotFuncStr );
			String_Appendf( sbHeader, "\t\t up1.x,      up1.y,      up1.z,     -%s( &up1, eye ),\n", dotFuncStr );
			String_Appendf( sbHeader, "\t\t-forward.x, -forward.y, -forward.z,  %s( &forward, eye ),\n", dotFuncStr );
		} else {
			String_Appendf( sbHeader, "\t\t right.x,    right.y,    right.z,   -%s( right, eye ),\n", dotFuncStr );
			String_Appendf( sbHeader, "\t\t up1.x,      up1.y,      up1.z,     -%s( up1, eye ),\n", dotFuncStr );
			String_Appendf( sbHeader, "\t\t-forward.x, -forward.y, -forward.z,  %s( forward, eye ),\n", dotFuncStr );
		}
		String_Appendf( sbHeader, "\t\t%s, %s, %s, %s\n", zeroStr, zeroStr, zeroStr, oneStr );
		String_Append(  sbHeader, "\t};\n" );
		String_Append(  sbHeader, "}\n" );
		String_Append(  sbHeader, "\n" );
	}
}

void Gen_MatrixMultiply( const genLanguage_t language, const genType_t type, const u32 numRows, const u32 numCols, stringBuilder_t* sbHeader ) {
	assert( numRows >= GEN_COMPONENT_COUNT_MIN );
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );
	assert( sbHeader );

	if ( type == GEN_TYPE_BOOL ) {
		return;
	}

	char typeNameLhs[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetFullTypeName( type, numRows, numCols, typeNameLhs );

	char typeNameRhs[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetFullTypeName( type, numCols, numRows, typeNameRhs );

	char typeNameReturn[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetFullTypeName( type, numRows, numRows, typeNameReturn );

	const char parmRefStr = GEN_TYPE_PARM_MODIFIERS[language];

	char mulFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameMatrixMultiply( language, type, numRows, numCols, mulFuncStr );

	Doc_MatrixMultiplication( sbHeader, typeNameLhs );
	String_Appendf( sbHeader, "inline %s %s( const %s%c lhs, const %s%c rhs )\n", typeNameReturn, mulFuncStr, typeNameLhs, parmRefStr, typeNameRhs, parmRefStr );
	String_Append(  sbHeader, "{\n" );
	Gen_MatrixGetCodeMultiply( language, type, numRows, numCols, sbHeader );
	String_Append(  sbHeader, "}\n" );
	String_Append(  sbHeader, "\n" );
}

void Gen_MatrixMultiplyVector( const genLanguage_t language, const genType_t type, const u32 numRows, const u32 numCols, stringBuilder_t* sbHeader ) {
	assert( numRows >= GEN_COMPONENT_COUNT_MIN );
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );
	assert( sbHeader );

	if ( type == GEN_TYPE_BOOL ) {
		return;
	}

	if ( numRows != numCols ) {
		return;
	}

	const char* typeString = Gen_GetTypeString( type );

	char vectorTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	snprintf( vectorTypeName, GEN_STRING_LENGTH_TYPE_NAME, "%s%d", typeString, numCols );

	char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	snprintf( fullTypeName, GEN_STRING_LENGTH_TYPE_NAME, "%s%dx%d", typeString, numRows, numCols );

	const char parmRefStr = GEN_TYPE_PARM_MODIFIERS[language];

	char mulVectorFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameMatrixMultiplyVector( language, type, numRows, numCols, mulVectorFuncStr );

	Doc_MatrixMultiplicationVector( sbHeader, fullTypeName );
	String_Appendf( sbHeader, "inline %s %s( const %s%c lhs, const %s%c rhs )\n", vectorTypeName, mulVectorFuncStr, fullTypeName, parmRefStr, vectorTypeName, parmRefStr );
	String_Append(  sbHeader, "{\n" );
	Gen_MatrixGetCodeMultiplyVector( language, type, numRows, numCols, sbHeader );
	String_Append(  sbHeader, "}\n" );
	String_Append(  sbHeader, "\n" );
}

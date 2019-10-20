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
#include "gen_common.h"

#include "gen_doc_common.h"

#include "string_builder.h"

#include <assert.h>

static void GenerateOperatorIncrementInl( const genType_t type, const u32 numRows, const u32 numCols, const genOpIncrement_t op, stringBuilder_t* sb ) {
	assert( sb );

	u32 numComponents = ( numRows == 1 ) ? numCols : numRows;

	char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetFullTypeName( type, numRows, numCols, fullTypeName );

	const char* opStr = GEN_OPERATORS_INCREMENT[op];

	// prefix
	String_Append(  sb, "// prefix\n" );
	Doc_OperatorIncrementPrefix( sb, fullTypeName, op );
	String_Appendf( sb, "inline %s& operator%s( %s& lhs )\n", fullTypeName, opStr, fullTypeName );
	String_Append(  sb, "{\n" );
	for ( u32 i = 0; i < numComponents; i++ ) {
		String_Appendf( sb, "\t%slhs[%d];\n", opStr, i );
	}
	String_Append( sb, "\treturn lhs;\n" );
	String_Append( sb, "}\n" );
	String_Append( sb, "\n" );

	// postfix
	String_Append(  sb, "// postfix\n" );
	Doc_OperatorIncrementPostfix( sb, fullTypeName, op );
	String_Appendf( sb, "inline %s& operator%s( %s& lhs, const int )\n", fullTypeName, opStr, fullTypeName );
	String_Append(  sb, "{\n" );
	for ( u32 i = 0; i < numComponents; i++ ) {
		String_Appendf( sb, "\tlhs[%d]%s;\n", i, opStr );
	}
	String_Append( sb, "\treturn lhs;\n" );
	String_Append( sb, "}\n" );
	String_Append( sb, "\n" );
}

static void InlGenerateOperatorRelational( const genType_t type, const u32 numRows, const u32 numCols, const genOpRelational_t op, stringBuilder_t* sb ) {
	assert( sb );

	u32 numComponents = ( numRows == 1 ) ? numCols : numRows;

	char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetFullTypeName( type, numRows, numCols, fullTypeName );

	char boolReturnTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetFullTypeName( GEN_TYPE_BOOL, numRows, numCols, boolReturnTypeName );

	const char* opStr = GEN_OPERATORS_RELATIONAL[op];

	Doc_OperatorRelational( sb, fullTypeName, numRows, numCols, op );
	String_Appendf( sb, "inline %s operator%s( const %s& lhs, const %s& rhs )\n", boolReturnTypeName, opStr, fullTypeName, fullTypeName );
	String_Append(  sb, "{\n" );
	String_Appendf( sb, "\treturn %s(\n", boolReturnTypeName );

	for ( u32 i = 0; i < numComponents; i++ ) {
		String_Appendf( sb, "\t\tlhs[%d] %s rhs[%d]", i, opStr, i );

		if ( i != numComponents - 1 ) {
			String_Append( sb, "," );
		}

		String_Append( sb, "\n" );
	}
	String_Append( sb, "\t);\n" );
	String_Append( sb, "}\n" );
	String_Append( sb, "\n" );
}

static void InlGenerateOperatorBitwiseScalar( const genType_t type, const u32 numRows, const u32 numCols, const genOpBitwise_t op, stringBuilder_t* sb ) {
	assert( sb );

	u32 numComponents = ( numRows == 1 ) ? numCols : numRows;

	char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetFullTypeName( type, numRows, numCols, fullTypeName );

	const char* memberTypeString = Gen_GetMemberTypeString( type );

	const char* opStr = GEN_OPERATORS_BITWISE[op];

	// main bitwise operator
	Doc_OperatorBitwiseScalar( sb, fullTypeName, op );
	String_Appendf( sb, "inline %s operator%s( const %s& lhs, const %s& rhs )\n", fullTypeName, opStr, fullTypeName, memberTypeString );
	String_Append(  sb, "{\n" );
	String_Appendf( sb, "\treturn %s(\n", fullTypeName );
	for ( u32 i = 0; i < numComponents; i++ ) {
		String_Appendf( sb, "\t\tlhs[%d] %s rhs", i, opStr );

		if ( i != numComponents - 1 ) {
			String_Append( sb, "," );
		}

		String_Append( sb, "\n" );
	}
	String_Append( sb, "\t);\n" );
	String_Append( sb, "}\n" );
	String_Append( sb, "\n" );

	// compound bitwise operator
	Doc_OperatorCompoundBitwiseScalar( sb, fullTypeName, op );
	String_Appendf( sb, "inline %s operator%s=( %s& lhs, const %s& rhs )\n", fullTypeName, opStr, fullTypeName, memberTypeString );
	String_Append(  sb, "{\n" );
	String_Appendf( sb, "\treturn ( lhs = lhs %s rhs );\n", opStr );
	String_Append(  sb, "}\n" );
	String_Append(  sb, "\n" );
}

static void InlGenerateOperatorBitwiseRhsType( const genType_t type, const u32 numRows, const u32 numCols, const genOpBitwise_t op, stringBuilder_t* sb ) {
	assert( sb );

	u32 numComponents = ( numRows == 1 ) ? numCols : numRows;

	char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetFullTypeName( type, numRows, numCols, fullTypeName );

	const char* opStr = GEN_OPERATORS_BITWISE[op];

	// main bitwise operator
	Doc_OperatorBitwiseRhsType( sb, fullTypeName, op );
	String_Appendf( sb, "inline %s operator%s( const %s& lhs, const %s& rhs )\n", fullTypeName, opStr, fullTypeName, fullTypeName );
	String_Append(  sb, "{\n" );
	String_Appendf( sb, "\treturn %s(\n", fullTypeName );
	for ( u32 i = 0; i < numComponents; i++ ) {
		String_Appendf( sb, "\t\tlhs[%d] %s rhs[%d]", i, opStr, i );

		if ( i != numComponents - 1 ) {
			String_Append( sb, "," );
		}

		String_Append( sb, "\n" );
	}
	String_Append( sb, "\t);\n" );
	String_Append( sb, "}\n" );
	String_Append( sb, "\n" );

	// compound bitwise operator
	Doc_OperatorCompoundBitwiseRhsType( sb, fullTypeName, op );
	String_Appendf( sb, "inline %s operator%s=( %s& lhs, const %s& rhs )\n", fullTypeName, opStr, fullTypeName, fullTypeName );
	String_Append(  sb, "{\n" );
	String_Appendf( sb, "\treturn ( lhs = lhs %s rhs );\n", opStr );
	String_Append(  sb, "}\n" );
	String_Append(  sb, "\n" );
}


void Gen_GetValuesArray1D( const genType_t type, const u32 numValues, const float* values, stringBuilder_t* sb ) {
	String_Append(  sb, "\t{ " );
	for ( u32 componentIndex = 0; componentIndex < numValues; componentIndex++ ) {
		char componentStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
		Gen_GetNumericLiteral( type, values[componentIndex], componentStr );

		String_Appendf( sb, "%s", componentStr );

		if ( componentIndex != numValues - 1 ) {
			String_Append( sb, ", " );
		}
	}
	String_Append(  sb, " }" );
}

void Gen_GetValuesArray2D( const genType_t type, const u32 rows, const u32 cols, const float* values, stringBuilder_t* sb ) {
	String_Append( sb, "\t{\n" );
	for ( u32 row = 0; row < rows; row++ ) {
		String_Append( sb, "\t\t{ " );
		for ( u32 col = 0; col < cols; col++ ) {
			const float* value = values + ( row * cols );

			char componentStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
			Gen_GetNumericLiteral( type, *value, componentStr );
			
			String_Appendf( sb, "%s", componentStr );

			if ( col != cols - 1 ) {
				String_Append( sb, ", " );
			}
		}
		String_Append( sb, " }" );

		if ( row != rows - 1 ) {
			String_Append( sb, "," );
		}

		String_Append( sb, "\n" );
	}
	String_Append( sb, "\t};\n" );
}

void Gen_Floateq( const genType_t type, stringBuilder_t* sb ) {
	assert( sb );

	if ( !Gen_TypeIsFloatingPoint( type ) ) {
		return;
	}

	const char* typeString = Gen_GetTypeString( type );

	const char* floateqStr = Gen_GetFuncNameFloateq( type );

	const char* parmEpsilonStr = Gen_GetConstantNameEpsilon( type );

	Doc_Floateq( sb );
	String_Appendf( sb, "inline bool %s_eps( const %s lhs, const %s rhs, const %s epsilon )\n", floateqStr, typeString, typeString, typeString );
	String_Append(  sb, "{\n" );
	String_Appendf( sb, "\treturn %s( lhs - rhs ) < epsilon;\n", Gen_GetFuncNameFabs( type ) );
	String_Append(  sb, "}\n" );
	String_Append(  sb, "\n" );

	Doc_Floateq( sb );
	String_Appendf( sb, "inline bool %s( const %s lhs, const %s rhs )\n", floateqStr, typeString, typeString );
	String_Append(  sb, "{\n" );
	String_Appendf( sb, "\treturn %s_eps( lhs, rhs, %s );\n", floateqStr, parmEpsilonStr );
	String_Append(  sb, "}\n" );
	String_Append(  sb, "\n" );
}

void Gen_Sign( const genType_t type, stringBuilder_t* sb ) {
	assert( sb );

	if ( type == GEN_TYPE_BOOL || type == GEN_TYPE_UINT ) {
		return;
	}

	const char* memberTypeString = Gen_GetMemberTypeString( type );
	const char* intTypeString = Gen_GetMemberTypeString( GEN_TYPE_INT );

	const char* signFuncStr = Gen_GetFuncNameSign( type );

	char zeroStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	Gen_GetNumericLiteral( type, 0, zeroStr, 1 );

	Doc_Sign( sb );
	String_Appendf( sb, "inline %s %s( const %s x )\n", intTypeString, signFuncStr, memberTypeString );
	String_Append(  sb, "{\n" );
	String_Appendf( sb, "\treturn ( %s < x ) - ( x < %s );\n", zeroStr, zeroStr );
	String_Append(  sb, "}\n" );
	String_Append(  sb, "\n" );
}

void Gen_Radians( const genType_t type, stringBuilder_t* sb ) {
	assert( sb );

	if ( !Gen_TypeIsFloatingPoint( type ) ) {
		return;
	}

	const char* typeString = Gen_GetTypeString( type );

	const char* radiansFuncStr = Gen_GetFuncNameRadians( type );

	char oneHundredEightyStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	Gen_GetNumericLiteral( type, 180, oneHundredEightyStr, 1 );

	const char* piStr = Gen_GetConstantNamePi( type );

	Doc_Radians( sb );
	String_Appendf( sb, "inline %s %s( const %s deg )\n", typeString, radiansFuncStr, typeString );
	String_Append(  sb, "{\n" );
	String_Appendf( sb, "\treturn deg * %s / %s;\n", piStr, oneHundredEightyStr );
	String_Append(  sb, "}\n" );
	String_Append(  sb, "\n" );
}

void Gen_Degrees( const genType_t type, stringBuilder_t* sb ) {
	assert( sb );

	if ( !Gen_TypeIsFloatingPoint( type ) ) {
		return;
	}

	const char* typeString = Gen_GetTypeString( type );

	const char* degreesFuncStr = Gen_GetFuncNameDegrees( type );

	char oneHundredEightyStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	Gen_GetNumericLiteral( type, 180, oneHundredEightyStr, 1 );

	const char* piStr = Gen_GetConstantNamePi( type );

	Doc_Degrees( sb );
	String_Appendf( sb, "inline %s %s( const %s rad )\n", typeString, degreesFuncStr, typeString );
	String_Append(  sb, "{\n" );
	String_Appendf( sb, "\treturn rad * %s / %s;\n", oneHundredEightyStr, piStr );
	String_Append(  sb, "}\n" );
	String_Append(  sb, "\n" );
}

void Gen_MinMax( const genType_t type, stringBuilder_t* sb ) {
	assert( sb );

	if ( type == GEN_TYPE_BOOL ) {
		return;
	}

	const char* memberTypeString = Gen_GetMemberTypeString( type );

	const char* minFuncStr = Gen_GetFuncNameMin( type );
	const char* maxFuncStr = Gen_GetFuncNameMax( type );

	// min
	Doc_Min( sb );
	String_Appendf( sb, "inline %s %s( const %s x, const %s y )\n", memberTypeString, minFuncStr, memberTypeString, memberTypeString );
	String_Append(  sb, "{\n" );
	String_Append(  sb, "\treturn ( x < y ) ? x : y;\n" );
	String_Append(  sb, "}\n" );
	String_Append(  sb, "\n" );

	// max
	Doc_Max( sb );
	String_Appendf( sb, "inline %s %s( const %s x, const %s y )\n", memberTypeString, maxFuncStr, memberTypeString, memberTypeString );
	String_Append(  sb, "{\n" );
	String_Append(  sb, "\treturn ( x > y ) ? x : y;\n" );
	String_Append(  sb, "}\n" );
	String_Append(  sb, "\n" );
}

void Gen_Clamp( const genType_t type, stringBuilder_t* sb ) {
	assert( sb );

	if ( type == GEN_TYPE_BOOL ) {
		return;
	}

	const char* memberTypeString = Gen_GetMemberTypeString( type );

	const char* clampFuncStr = Gen_GetFuncNameClamp( type );

	const char* minFuncStr = Gen_GetFuncNameMin( type );
	const char* maxFuncStr = Gen_GetFuncNameMax( type );

	Doc_Clamp( sb );
	String_Appendf( sb, "inline %s %s( const %s x, const %s low, const %s high )\n", memberTypeString, clampFuncStr, memberTypeString, memberTypeString, memberTypeString );
	String_Append(  sb, "{\n" );
	String_Appendf( sb, "\treturn %s( %s( x, low ), high );\n", minFuncStr, maxFuncStr );
	String_Append(  sb, "}\n" );
	String_Append(  sb, "\n" );
}

void Gen_Saturate( const genType_t type, const u32 numComponents, stringBuilder_t* sbHeader ) {
	assert( sbHeader );

	assert( numComponents >= 1 );	// we allow scalar types for this function
	assert( numComponents <= GEN_COMPONENT_COUNT_MAX );

	if ( !Gen_TypeIsFloatingPoint( type ) ) {
		return;
	}

	char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetFullTypeName( type, 1, numComponents, fullTypeName );

	const char* saturateFuncStr = Gen_GetFuncNameSaturate( type );
	const char* clampFuncStr = Gen_GetFuncNameClamp( type );

	char zeroStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	char oneStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];

	Gen_GetNumericLiteral( type, 0.0f, zeroStr, 1 );
	Gen_GetNumericLiteral( type, 1.0f, oneStr, 1 );

	char parmTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetParmTypeName( type, numComponents, parmTypeName );

	bool isVector = numComponents > 1;

	Doc_Saturate( sbHeader, fullTypeName );
	String_Appendf( sbHeader, "inline %s %s( const %s x )\n", fullTypeName, saturateFuncStr, parmTypeName );
	if ( isVector ) {
		String_Append(  sbHeader, "{\n" );
		String_Appendf( sbHeader, "\treturn %s(\n", fullTypeName );
		for ( u32 i = 0; i < numComponents; i++ ) {
			String_Appendf( sbHeader, "\t\t%s( x[%d], %s, %s )", clampFuncStr, i, zeroStr, oneStr );

			if ( i != numComponents - 1 ) {
				String_Append( sbHeader, "," );
			}

			String_Append( sbHeader, "\n" );
		}

		String_Append( sbHeader, "\t);\n" );
		String_Append( sbHeader, "}\n" );
		String_Append( sbHeader, "\n" );
	} else {
		String_Append(  sbHeader, "{\n" );
		String_Appendf( sbHeader, "\treturn %s( x, %s, %s );\n", clampFuncStr, zeroStr, oneStr );
		String_Append(  sbHeader, "}\n" );
		String_Append(  sbHeader, "\n" );
	}
}

void Gen_Lerp( const genType_t type, const u32 numComponents, stringBuilder_t* sbHeader ) {
	assert( sbHeader );

	assert( numComponents >= 1 );	// we allow scalar types for this function
	assert( numComponents <= GEN_COMPONENT_COUNT_MAX );

	if ( !Gen_TypeIsFloatingPoint( type ) ) {
		return;
	}

	const char* typeString = Gen_GetTypeString( type );

	char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetFullTypeName( type, 1, numComponents, fullTypeName );

	const char* lerpFuncStr = Gen_GetFuncNameLerp( type );

	char oneStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	Gen_GetNumericLiteral( type, 1.0f, oneStr, 1 );

	char parmTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetParmTypeName( type, numComponents, parmTypeName );

	bool isVector = numComponents > 1;

	Doc_Lerp( sbHeader, fullTypeName );
	String_Appendf( sbHeader, "inline %s %s( const %s a, const %s b, const %s t )\n", fullTypeName, lerpFuncStr, parmTypeName, parmTypeName, typeString );
	if ( isVector ) {
		String_Append(  sbHeader, "{\n" );
		String_Appendf( sbHeader, "\treturn %s(\n", fullTypeName );
		for ( u32 i = 0; i < numComponents; i++ ) {
			String_Appendf( sbHeader, "\t\tlerp( a[%d], b[%d], t )", i, i );

			if ( i != numComponents - 1 ) {
				String_Append( sbHeader, "," );
			}

			String_Append( sbHeader, "\n" );
		}

		String_Append( sbHeader, "\t);\n" );
		String_Append( sbHeader, "}\n" );
		String_Append( sbHeader, "\n" );
	} else {
		String_Append(  sbHeader, "{\n" );
		String_Appendf( sbHeader, "\treturn ( %s - t ) * a + t * b;\n", oneStr );
		String_Append(  sbHeader, "}\n" );
		String_Append(  sbHeader, "\n" );
	}
}

void Gen_Step( const genType_t type, const u32 numComponents, stringBuilder_t* sbHeader ) {
	assert( sbHeader );

	assert( numComponents >= 1 );
	assert( numComponents <= GEN_COMPONENT_COUNT_MAX );

	if ( !Gen_TypeIsFloatingPoint( type ) ) {
		return;
	}

	char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetFullTypeName( type, 1, numComponents, fullTypeName );

	const char* stepFuncStr = Gen_GetFuncNameStep( type );

	char zeroStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	Gen_GetNumericLiteral( type, 0.0f, zeroStr, 1 );

	char oneStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	Gen_GetNumericLiteral( type, 1.0f, oneStr, 1 );

	char parmTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetParmTypeName( type, numComponents, parmTypeName );

	Doc_Step( sbHeader, fullTypeName );
	String_Appendf( sbHeader, "inline %s %s( const %s x, const %s y )\n", fullTypeName, stepFuncStr, parmTypeName, parmTypeName );
	if ( numComponents > 1 ) {
		String_Append(  sbHeader, "{\n" );
		String_Appendf( sbHeader, "\treturn %s(\n", fullTypeName );
		for ( u32 i = 0; i < numComponents; i++ ) {
				String_Appendf( sbHeader, "\t\t%s( x[%d], y[%d] )", stepFuncStr, i, i );

				if ( i != numComponents - 1 ) {
					String_Append( sbHeader, "," );
				}

				String_Append( sbHeader, "\n" );
		}
		String_Appendf( sbHeader, "\t);\n" );
		String_Append(  sbHeader, "}\n" );
		String_Append(  sbHeader, "\n" );
	} else {
		String_Append(  sbHeader, "{\n" );
		String_Appendf( sbHeader, "\treturn ( y > x ? %s : %s );\n", oneStr, zeroStr );
		String_Append(  sbHeader, "}\n" );
		String_Append(  sbHeader, "\n" );
	}
}

void Gen_Smoothstep( const genType_t type, const u32 numComponents, stringBuilder_t* sbHeader ) {
	assert( sbHeader );

	assert( numComponents >= 1 );	// we allow scalar types for this function
	assert( numComponents <= GEN_COMPONENT_COUNT_MAX );

	if ( !Gen_TypeIsFloatingPoint( type ) ) {
		return;
	}

	char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetFullTypeName( type, 1, numComponents, fullTypeName );

	const char* smoothstepFuncStr = Gen_GetFuncNameSmoothstep( type );
	const char* smootherstepFuncStr = Gen_GetFuncNameSmootherstep( type );
	const char* saturateFuncStr = Gen_GetFuncNameSaturate( type );

	char twoStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	Gen_GetNumericLiteral( type, 2.0f,  twoStr, 1 );

	char threeStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	Gen_GetNumericLiteral( type, 3.0f,  threeStr, 1 );

	char sixStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	Gen_GetNumericLiteral( type, 6.0f,  sixStr, 1 );

	char tenStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	Gen_GetNumericLiteral( type, 10.0f, tenStr, 1 );

	char fifteenStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	Gen_GetNumericLiteral( type, 15.0f, fifteenStr, 1 );

	char parmTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetParmTypeName( type, numComponents, parmTypeName );

	bool32 isVector = numComponents > 1;

	// smoothstep
	{
		Doc_Smoothstep( sbHeader, fullTypeName );
		String_Appendf( sbHeader, "inline %s %s( const %s low, const %s high, const %s x )\n", fullTypeName, smoothstepFuncStr, parmTypeName, parmTypeName, parmTypeName );
		if ( isVector ) {
			String_Append(  sbHeader, "{\n" );
			String_Appendf( sbHeader, "\treturn %s(\n", fullTypeName );
			for ( u32 i = 0; i < numComponents; i++ ) {
				String_Appendf( sbHeader, "\t\t%s( low[%d], high[%d], x[%d] )", smoothstepFuncStr, i, i, i );

				if ( i != numComponents - 1 ) {
					String_Append( sbHeader, "," );
				}

				String_Append( sbHeader, "\n" );
			}
			String_Append( sbHeader, "\t);\n" );
			String_Append( sbHeader, "}\n" );
			String_Append( sbHeader, "\n" );
		} else {
			String_Append(  sbHeader, "{\n" );
			String_Appendf( sbHeader, "\t%s t = %s( ( x - low ) / ( high - low ) );\n", fullTypeName, saturateFuncStr );
			String_Appendf( sbHeader, "\treturn t * t * ( %s - %s * t );\n", threeStr, twoStr );
			String_Append(  sbHeader, "}\n" );
			String_Append(  sbHeader, "\n" );
		}
	}

	// smootherstep
	{
		Doc_Smootherstep( sbHeader, fullTypeName );
		String_Appendf( sbHeader, "inline %s %s( const %s low, const %s high, const %s x )\n", fullTypeName, smootherstepFuncStr, parmTypeName, parmTypeName, parmTypeName );
		if ( isVector ) {
			String_Append(  sbHeader, "{\n" );
			String_Appendf( sbHeader, "\treturn %s(\n", fullTypeName );
			for ( u32 i = 0; i < numComponents; i++ ) {
				String_Appendf( sbHeader, "\t\t%s( low[%d], high[%d], x[%d] )", smootherstepFuncStr, i, i, i );

				if ( i != numComponents - 1 ) {
					String_Append( sbHeader, "," );
				}

				String_Append( sbHeader, "\n" );
			}
			String_Append( sbHeader, "\t);\n" );
			String_Append( sbHeader, "}\n" );
			String_Append( sbHeader, "\n" );
		} else {
			String_Append(  sbHeader, "{\n" );
			String_Appendf( sbHeader, "\t%s t = %s( ( x - low ) / ( high - low ) );\n", fullTypeName, saturateFuncStr );
			String_Appendf( sbHeader, "\treturn t * t * t * ( t * ( t * %s - %s ) + %s );\n", sixStr, fifteenStr, tenStr );
			String_Append(  sbHeader, "}\n" );
			String_Append(  sbHeader, "\n" );
		}
	}
}

void Gen_OperatorsIncrement( const genType_t type, const u32 numRows, const u32 numCols, stringBuilder_t* sbHeader ) {
	assert( sbHeader );

	assert( numRows >= 1 );	// pass through 1 for vectors
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );

	if ( type == GEN_TYPE_BOOL ) {
		return;
	}

	for ( u32 opIndex = 0; opIndex < GEN_OP_INCREMENT_COUNT; opIndex++ ) {
		genOpIncrement_t op = (genOpIncrement_t) opIndex;

		GenerateOperatorIncrementInl( type, numRows, numCols, op, sbHeader );
	}
}

void Gen_OperatorsRelational( const genType_t type, const u32 numRows, const u32 numCols, stringBuilder_t* sbHeader ) {
	assert( sbHeader );

	assert( numRows >= 1 );	// pass through 1 for vectors
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );

	if ( type == GEN_TYPE_BOOL ) {
		return;
	}

	for ( u32 opIndex = 0; opIndex < GEN_OP_RELATIONAL_COUNT; opIndex++ ) {
		genOpRelational_t op = (genOpRelational_t) opIndex;

		InlGenerateOperatorRelational( type, numRows, numCols, op, sbHeader );
	}
}

void Gen_OperatorsBitwise( const genType_t type, const u32 numRows, const u32 numCols, stringBuilder_t* sbHeader ) {
	assert( sbHeader );

	assert( numRows >= 1 );	// pass through 1 for vectors
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );

	if ( type != GEN_TYPE_BOOL && !Gen_TypeIsInteger( type ) ) {
		return;
	}

	// do all except unary operator
	// unary doesn't take rhs type, so do that one separately
	genOpBitwise_t ops[] = {
		GEN_OP_BITWISE_AND,
		GEN_OP_BITWISE_OR,
		GEN_OP_BITWISE_XOR,
		GEN_OP_BITWISE_SHIFT_LEFT,
		GEN_OP_BITWISE_SHIFT_RIGHT
	};

	for ( genOpBitwise_t op : ops ) {
		InlGenerateOperatorBitwiseScalar( type, numRows, numCols, op, sbHeader );
		InlGenerateOperatorBitwiseRhsType( type, numRows, numCols, op, sbHeader );
	}

	// unary operator
	u32 numComponents = ( numRows == 1 ) ? numCols : numRows;
	char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetFullTypeName( type, numRows, numCols, fullTypeName );

	Doc_OperatorBitwiseUnary( sbHeader, fullTypeName );
	String_Appendf( sbHeader, "inline %s operator~( const %s& lhs )\n", fullTypeName, fullTypeName );
	String_Append( sbHeader, "{\n" );
	String_Appendf( sbHeader, "\treturn %s(\n", fullTypeName );
	for ( u32 i = 0; i < numComponents; i++ ) {
		String_Appendf( sbHeader, "\t\t~lhs[%d]", i );

		if ( i != numComponents - 1 ) {
			String_Append( sbHeader, "," );
		}

		String_Append( sbHeader, "\n" );
	}
	String_Append( sbHeader, "\t);\n" );
	String_Append( sbHeader, "}\n" );
	String_Append( sbHeader, "\n" );
}

void Gen_OperatorComponentWiseArithmeticScalar( const genType_t type, const u32 numRows, const u32 numCols, const genOpArithmetic_t op, stringBuilder_t* sbHeader ) {
	assert( sbHeader );

	assert( numRows >= 1 );	// pass through 1 for vectors
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );

	if ( type == GEN_TYPE_BOOL ) {
		return;
	}

	u32 numComponents = ( numRows == 1 ) ? numCols : numRows;

	char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetFullTypeName( type, numRows, numCols, fullTypeName );

	const char* memberTypeString = Gen_GetMemberTypeString( type );

	char opStr = GEN_OPERATORS_ARITHMETIC[op];

	// main arithmetic func
	Doc_ComponentWiseArithmeticScalar( sbHeader, fullTypeName, op );
	String_Appendf( sbHeader, "inline %s operator%c( const %s& lhs, const %s rhs )\n", fullTypeName, opStr, fullTypeName, memberTypeString );
	String_Append(  sbHeader, "{\n" );
	String_Appendf( sbHeader, "\treturn %s(\n", fullTypeName );
	for ( u32 i = 0; i < numComponents; i++ ) {
		String_Appendf( sbHeader, "\t\tlhs[%d] %c rhs", i, opStr );

		if ( i != numComponents - 1 ) {
			String_Append( sbHeader, "," );
		}

		String_Append( sbHeader, "\n" );
	}
	String_Append( sbHeader, "\t);\n" );
	String_Append( sbHeader, "}\n" );
	String_Append( sbHeader, "\n" );

	// compound arithmetic func
	Doc_OperatorCompoundArithmeticScalar( sbHeader, fullTypeName, op );
	String_Appendf( sbHeader, "inline %s operator%c=( %s& lhs, const %s rhs )\n", fullTypeName, opStr, fullTypeName, memberTypeString );
	String_Append(  sbHeader, "{\n" );
	String_Appendf( sbHeader, "\treturn ( lhs = lhs %c rhs );\n", opStr );
	String_Append(  sbHeader, "}\n" );
	String_Append(  sbHeader, "\n" );
}

void Gen_OperatorComponentWiseArithmeticRhsType( const genType_t type, const u32 numRows, const u32 numCols, const genOpArithmetic_t op, stringBuilder_t* sbHeader ) {
	assert( sbHeader );

	assert( numRows >= 1 );	// pass through 1 for vectors
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );

	if ( type == GEN_TYPE_BOOL ) {
		return;
	}

	// don't generate compound arithmetic func on mul/div ops for non-square matrices
	bool canGenerateCompound = true;
	if ( op == GEN_OP_ARITHMETIC_MUL || op == GEN_OP_ARITHMETIC_DIV ) {
		if ( numRows > 1 && numRows != numCols ) {
			canGenerateCompound = false;
		}
	}

	u32 numComponents = ( numRows == 1 ) ? numCols : numRows;

	char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetFullTypeName( type, numRows, numCols, fullTypeName );

	char opStr = GEN_OPERATORS_ARITHMETIC[op];

	// main arithmetic func
	Doc_ComponentWiseArithmeticRhsType( sbHeader, fullTypeName, fullTypeName, op );
	String_Appendf( sbHeader, "inline %s operator%c( const %s& lhs, const %s& rhs )\n", fullTypeName, opStr, fullTypeName, fullTypeName );
	String_Append(  sbHeader, "{\n" );
	String_Appendf( sbHeader, "\treturn %s(\n", fullTypeName );
	for ( u32 i = 0; i < numComponents; i++ ) {
		String_Appendf( sbHeader, "\t\tlhs[%d] %c rhs[%d]", i, opStr, i );

		if ( i != numComponents - 1 ) {
			String_Append( sbHeader, "," );
		}

		String_Append( sbHeader, "\n" );
	}
	String_Append( sbHeader, "\t);\n" );
	String_Append( sbHeader, "}\n" );
	String_Append( sbHeader, "\n" );

	// compound arithmetic func
	if ( canGenerateCompound ) {
		Doc_OperatorCompoundComponentWiseArithmeticRhsType( sbHeader, fullTypeName, fullTypeName, op );
		String_Appendf( sbHeader, "inline %s operator%c=( %s& lhs, const %s& rhs )\n", fullTypeName, opStr, fullTypeName, fullTypeName );
		String_Append(  sbHeader, "{\n" );
		String_Appendf( sbHeader, "\treturn ( lhs = lhs %c rhs );\n", opStr );
		String_Append(  sbHeader, "}\n" );
		String_Append(  sbHeader, "\n" );
	}
}

void Gen_OperatorNotEquals( const genType_t type, const u32 numRows, const u32 numCols, stringBuilder_t* sbHeader, stringBuilder_t* sbInl ) {
	assert( sbHeader );

	assert( numRows >= 1 );	// pass through 1 for vectors
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );

	char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetFullTypeName( type, numRows, numCols, fullTypeName );

	Doc_OperatorNotEquals( sbHeader, fullTypeName );
	String_Appendf( sbHeader, "inline bool operator!=( const %s& lhs, const %s& rhs );\n", fullTypeName, fullTypeName );
	String_Append(  sbHeader, "\n" );

	String_Appendf( sbInl, "inline bool operator!=( const %s& lhs, const %s& rhs )\n", fullTypeName, fullTypeName );
	String_Append(  sbInl, "{\n" );
	String_Append(  sbInl, "\treturn !( operator==( lhs, rhs ) );\n" );
	String_Append(  sbInl, "}\n" );
	String_Append(  sbInl, "\n" );
}

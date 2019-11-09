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
#include "gen_funcs_vector.h"

#include "gen_doc_common.h"
#include "gen_doc_vector.h"

#include <assert.h>

static void GenerateFunctionComponentWiseArithmeticScalar( const genLanguage_t language, const genType_t type, const u32 numComponents, const genOpArithmetic_t op, stringBuilder_t* sbHeader ) {
	assert( numComponents >= GEN_COMPONENT_COUNT_MIN );
	assert( numComponents <= GEN_COMPONENT_COUNT_MAX );
	assert( sbHeader );

	if ( type == GEN_TYPE_BOOL ) {
		return;
	}

	const char* memberTypeString = Gen_GetMemberTypeString( type );

	char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetFullTypeName( type, 1, numComponents, fullTypeName );

	char parmTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetParmTypeName( language, type, 1, numComponents, parmTypeName );

	char compFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameComponentWiseArithmeticScalar( language, type, 1, numComponents, op, compFuncStr );

	Doc_ComponentWiseArithmeticScalar( sbHeader, fullTypeName, op );
	String_Appendf( sbHeader, "inline %s %s( const %s lhs, const %s scalar )\n", fullTypeName, compFuncStr, parmTypeName, memberTypeString );
	String_Append(  sbHeader, "{\n" );
	Gen_VectorGetCodeComponentWiseArithmeticScalar( language, type, numComponents, op, sbHeader );
	String_Append( sbHeader, "}\n" );
	String_Append( sbHeader, "\n" );
}

static void GenerateFunctionComponentWiseArithmeticVector( const genLanguage_t language, const genType_t type, const u32 numComponents, const genOpArithmetic_t op, stringBuilder_t* sbHeader ) {
	assert( numComponents >= GEN_COMPONENT_COUNT_MIN );
	assert( numComponents <= GEN_COMPONENT_COUNT_MAX );
	assert( sbHeader );

	if ( type == GEN_TYPE_BOOL ) {
		return;
	}

	char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetFullTypeName( type, 1, numComponents, fullTypeName );

	char parmTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetParmTypeName( language, type, 1, numComponents, parmTypeName );

	char compFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameComponentWiseArithmeticVector( language, type, 1, numComponents, op, compFuncStr );

	Doc_ComponentWiseArithmeticRhsType( sbHeader, fullTypeName, fullTypeName, op );
	String_Appendf( sbHeader, "inline %s %s( const %s lhs, const %s rhs )\n", fullTypeName, compFuncStr, parmTypeName, parmTypeName );
	String_Append(  sbHeader, "{\n" );
	Gen_VectorGetCodeComponentWiseArithmeticRhsType( language, type, numComponents, op, sbHeader );
	String_Append( sbHeader, "}\n" );
	String_Append( sbHeader, "\n" );
}

static void GenerateFunctionComponentWiseBitwiseRhsType( const genLanguage_t language, const genType_t type, const u32 numComponents, const genOpBitwise_t op, stringBuilder_t* sbHeader ) {
	assert( numComponents >= 1 );	// pass through > 1 for vectors
	assert( numComponents <= GEN_COMPONENT_COUNT_MAX );
	assert( sbHeader );

	if ( !Gen_TypeIsInteger( type ) ) {
		return;
	}

	char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetFullTypeName( type, 1, numComponents, fullTypeName );

	char parmTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetParmTypeName( language, type, 1, numComponents, parmTypeName );

	char bitwiseFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameBitwise( language, type, 1, numComponents, op, bitwiseFuncStr );

	if ( op == GEN_OP_BITWISE_UNARY ) {
		Doc_OperatorBitwiseUnary( sbHeader, fullTypeName );
		String_Appendf( sbHeader, "inline %s %s( const %s lhs )\n", fullTypeName, bitwiseFuncStr, parmTypeName );
		String_Append(  sbHeader, "{\n" );
		Gen_VectorGetCodeComponentWiseBitwise( language, type, numComponents, op, sbHeader );
		String_Append(  sbHeader, "}\n" );
		String_Append(  sbHeader, "\n" );
	} else {
		Doc_OperatorBitwiseRhsType( sbHeader, fullTypeName, op );
		String_Appendf( sbHeader, "inline %s %s( const %s lhs, const %s rhs )\n", fullTypeName, bitwiseFuncStr, parmTypeName, parmTypeName );
		String_Append(  sbHeader, "{\n" );
		Gen_VectorGetCodeComponentWiseBitwise( language, type, numComponents, op, sbHeader );
		String_Append( sbHeader, "}\n" );
		String_Append( sbHeader, "\n" );
	}
}

static void GenerateFunctionComponentWiseRelational( const genLanguage_t language, const genType_t type, const u32 numComponents, const genOpRelational_t op, stringBuilder_t* sbHeader ) {
	assert( numComponents >= 1 );	// pass through > 1 for vectors
	assert( numComponents <= GEN_COMPONENT_COUNT_MAX );
	assert( sbHeader );

	if ( type == GEN_TYPE_BOOL ) {
		return;
	}

	char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetFullTypeName( type, 1, numComponents, fullTypeName );

	char parmTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetParmTypeName( language, type, 1, numComponents, parmTypeName );

	char boolReturnType[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetFullTypeName( GEN_TYPE_BOOL, 1, numComponents, boolReturnType );

	char cmpFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameRelational( language, type, 1, numComponents, op, cmpFuncStr );

	Doc_ComponentWiseRelational( sbHeader, fullTypeName, 1, numComponents, op );
	String_Appendf( sbHeader, "inline %s %s( const %s lhs, const %s rhs )\n", boolReturnType, cmpFuncStr, parmTypeName, parmTypeName );
	String_Append(  sbHeader, "{\n" );
	Gen_VectorGetCodeComponentWiseRelational( language, numComponents, op, sbHeader );
	String_Append(  sbHeader, "}\n" );
	String_Append(  sbHeader, "\n" );
}

void Gen_GetParmListVector( const genType_t type, const u32 numComponents, const float* values, char* outParmListStr ) {
	assert( numComponents >= GEN_COMPONENT_COUNT_MIN );
	assert( numComponents <= GEN_COMPONENT_COUNT_MAX );
	assert( values );
	assert( outParmListStr );

	char valueStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];

	int pos = 0;

	for ( u32 i = 0; i < numComponents; i++ ) {
		const float value = values[i];

		Gen_GetNumericLiteral( type, value, valueStr );

		pos += snprintf( outParmListStr + pos, GEN_STRING_LENGTH_PARM_LIST_VECTOR, "%s", valueStr );

		if ( i != numComponents - 1 ) {
			pos += snprintf( outParmListStr + pos, GEN_STRING_LENGTH_PARM_LIST_VECTOR, ", " );
		}
	}
}

void Gen_VectorGetCodeComponentWiseArithmeticScalar( const genLanguage_t language, const genType_t type, const u32 numComponents, const genOpArithmetic_t op, stringBuilder_t* sbHeader ) {
	assert( numComponents >= GEN_COMPONENT_COUNT_MIN );
	assert( numComponents <= GEN_COMPONENT_COUNT_MAX );
	assert( sbHeader );

	char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetFullTypeName( type, 1, numComponents, fullTypeName );

	const char opStr = GEN_OPERATORS_ARITHMETIC[op];

	const char* parmAccessStr = GEN_TYPE_ACCESS_OPERATORS[language];

	String_Appendf( sbHeader, "\treturn HLML_CONSTRUCT( %s ) {\n", fullTypeName );
	for ( u32 i = 0; i < numComponents; i++ ) {
		const char componentStr = GEN_COMPONENT_NAMES_VECTOR[i];
		String_Appendf( sbHeader, "\t\tlhs%s%c %c scalar", parmAccessStr, componentStr, opStr, parmAccessStr, componentStr );

		if ( i != numComponents - 1 ) {
			String_Append( sbHeader, "," );
		}

		String_Append( sbHeader, "\n" );
	}
	String_Append( sbHeader, "\t};\n" );
}

void Gen_VectorGetCodeComponentWiseArithmeticRhsType( const genLanguage_t language, const genType_t type, const u32 numComponents, const genOpArithmetic_t op, stringBuilder_t* sbHeader ) {
	assert( numComponents >= GEN_COMPONENT_COUNT_MIN );
	assert( numComponents <= GEN_COMPONENT_COUNT_MAX );
	assert( sbHeader );

	char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetFullTypeName( type, 1, numComponents, fullTypeName );

	const char opStr = GEN_OPERATORS_ARITHMETIC[op];

	const char* parmAccessStr = GEN_TYPE_ACCESS_OPERATORS[language];

	String_Appendf( sbHeader, "\treturn HLML_CONSTRUCT( %s ) {\n", fullTypeName );
	for ( u32 i = 0; i < numComponents; i++ ) {
		const char componentStr = GEN_COMPONENT_NAMES_VECTOR[i];
		String_Appendf( sbHeader, "\t\tlhs%s%c %c rhs%s%c", parmAccessStr, componentStr, opStr, parmAccessStr, componentStr );

		if ( i != numComponents - 1 ) {
			String_Append( sbHeader, "," );
		}

		String_Append( sbHeader, "\n" );
	}
	String_Append( sbHeader, "\t};\n" );
}

void Gen_VectorGetCodeComponentWiseBitwise( const genLanguage_t language, const genType_t type, const u32 numComponents, const genOpBitwise_t op, stringBuilder_t* sbHeader ) {
	assert( numComponents >= GEN_COMPONENT_COUNT_MIN );
	assert( numComponents <= GEN_COMPONENT_COUNT_MAX );
	assert( sbHeader );

	char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetFullTypeName( type, 1, numComponents, fullTypeName );

	const char* opStr = GEN_OPERATORS_BITWISE[op];

	const char* parmAccessStr = GEN_TYPE_ACCESS_OPERATORS[language];

	if ( op == GEN_OP_BITWISE_UNARY ) {
		String_Appendf( sbHeader, "\treturn HLML_CONSTRUCT( %s ) {\n", fullTypeName );
		for ( u32 i = 0; i < numComponents; i++ ) {
			const char componentStr = GEN_COMPONENT_NAMES_VECTOR[i];
			String_Appendf( sbHeader, "\t\t%slhs%s%c", opStr, parmAccessStr, componentStr );

			if ( i != numComponents - 1 ) {
				String_Append( sbHeader, "," );
			}

			String_Append( sbHeader, "\n" );
		}
		String_Append( sbHeader, "\t};\n" );
	} else {
		String_Appendf( sbHeader, "\treturn HLML_CONSTRUCT( %s ) {\n", fullTypeName );
		for ( u32 i = 0; i < numComponents; i++ ) {
			const char componentStr = GEN_COMPONENT_NAMES_VECTOR[i];
			String_Appendf( sbHeader, "\t\tlhs%s%c %s rhs%s%c", parmAccessStr, componentStr, opStr, parmAccessStr, componentStr );

			if ( i != numComponents - 1 ) {
				String_Append( sbHeader, "," );
			}

			String_Append( sbHeader, "\n" );
		}
		String_Append( sbHeader, "\t};\n" );
	}
}

void Gen_VectorGetCodeComponentWiseRelational( const genLanguage_t language, const u32 numComponents, const genOpRelational_t op, stringBuilder_t* sbHeader ) {
	assert( numComponents >= GEN_COMPONENT_COUNT_MIN );
	assert( numComponents <= GEN_COMPONENT_COUNT_MAX );
	assert( sbHeader );

	char boolReturnType[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetFullTypeName( GEN_TYPE_BOOL, 1, numComponents, boolReturnType );

	const char* opStr = GEN_OPERATORS_RELATIONAL[op];

	const char* parmAccessStr = GEN_TYPE_ACCESS_OPERATORS[language];

	String_Appendf( sbHeader, "\treturn HLML_CONSTRUCT( %s ) {\n", boolReturnType );
	for ( u32 i = 0; i < numComponents; i++ ) {
		const char componentStr = GEN_COMPONENT_NAMES_VECTOR[i];
		String_Appendf( sbHeader, "\t\tlhs%s%c %s rhs%s%c", parmAccessStr, componentStr, opStr, parmAccessStr, componentStr );

		if ( i != numComponents - 1 ) {
			String_Append( sbHeader, "," );
		}

		String_Append( sbHeader, "\n" );
	}
	String_Append( sbHeader, "\t};\n" );
}

void Gen_VectorGetCodeEquals( const genLanguage_t language, const genType_t type, const u32 numComponents, stringBuilder_t* sbHeader ) {
	assert( numComponents >= GEN_COMPONENT_COUNT_MIN );
	assert( numComponents <= GEN_COMPONENT_COUNT_MAX );
	assert( sbHeader );

	const char* parmAccessStr = GEN_TYPE_ACCESS_OPERATORS[language];

	String_Append(  sbHeader, "\treturn " );
	for ( u32 i = 0; i < numComponents; i++ ) {
		char component = GEN_COMPONENT_NAMES_VECTOR[i];

		if ( Gen_TypeIsFloatingPoint( type ) ) {
			const char* floateqStr = Gen_GetFuncNameFloateq( type );

			String_Appendf( sbHeader, "%s( lhs%s%c, rhs%s%c )", floateqStr, parmAccessStr, component, parmAccessStr, component );
		} else {
			String_Appendf( sbHeader, "( lhs%s%c == rhs%s%c )", parmAccessStr, component, parmAccessStr, component );
		}

		if ( i != numComponents - 1 ) {
			String_Append( sbHeader, " && " );
		}
	}
	String_Append( sbHeader, ";\n" );
}

void Gen_VectorFunctionsEquals( const genLanguage_t language, const genType_t type, const u32 numComponents, stringBuilder_t* sbHeader ) {
	assert( numComponents >= GEN_COMPONENT_COUNT_MIN );
	assert( numComponents <= GEN_COMPONENT_COUNT_MAX );
	assert( sbHeader );

	char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetFullTypeName( type, 1, numComponents, fullTypeName );

	char parmTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetParmTypeName( language, type, 1, numComponents, parmTypeName );

	char cmpFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameEquals( language, type, 1, numComponents, cmpFuncStr );

	Doc_OperatorEquals( sbHeader, fullTypeName );
	String_Appendf( sbHeader, "inline bool %s( const %s lhs, const %s rhs )\n", cmpFuncStr, parmTypeName, parmTypeName );
	String_Append(  sbHeader, "{\n" );
	Gen_VectorGetCodeEquals( language, type, numComponents, sbHeader );
	String_Append( sbHeader, "}\n" );
	String_Append( sbHeader, "\n" );

	Gen_NotEquals( language, type, 1, numComponents, sbHeader );
}

void Gen_VectorFunctionsComponentWiseArithmetic( const genLanguage_t language, const genType_t type, const u32 numComponents, stringBuilder_t* sbHeader ) {
	assert( numComponents >= GEN_COMPONENT_COUNT_MIN );
	assert( numComponents <= GEN_COMPONENT_COUNT_MAX );
	assert( sbHeader );

	if ( type == GEN_TYPE_BOOL ) {
		return;
	}

	for ( u32 opIndex = 0; opIndex < GEN_OP_ARITHMETIC_COUNT; opIndex++ ) {
		genOpArithmetic_t op = (genOpArithmetic_t) opIndex;

		GenerateFunctionComponentWiseArithmeticScalar( language, type, numComponents, op, sbHeader );
		GenerateFunctionComponentWiseArithmeticVector( language, type, numComponents, op, sbHeader );
	}
}

void Gen_VectorFunctionsComponentWiseBitwise( const genLanguage_t language, const genType_t type, const u32 numComponents, stringBuilder_t* sbHeader ) {
	assert( numComponents >= GEN_COMPONENT_COUNT_MIN );
	assert( numComponents <= GEN_COMPONENT_COUNT_MAX );
	assert( sbHeader );

	if ( !Gen_TypeIsInteger( type ) ) {
		return;
	}

	for ( u32 opIndex = 0; opIndex < GEN_OP_BITWISE_COUNT; opIndex++ ) {
		genOpBitwise_t op = (genOpBitwise_t) opIndex;

		GenerateFunctionComponentWiseBitwiseRhsType( language, type, numComponents, op, sbHeader );
	}
}

void Gen_VectorFunctionsComponentWiseRelational( const genLanguage_t language, const genType_t type, const u32 numComponents, stringBuilder_t* sbHeader ) {
	assert( numComponents >= GEN_COMPONENT_COUNT_MIN );
	assert( numComponents <= GEN_COMPONENT_COUNT_MAX );
	assert( sbHeader );

	if ( type == GEN_TYPE_BOOL ) {
		return;
	}

	for ( u32 opIndex = 0; opIndex < GEN_OP_RELATIONAL_COUNT; opIndex++ ) {
		genOpRelational_t op = (genOpRelational_t) opIndex;

		GenerateFunctionComponentWiseRelational( language, type, numComponents, op, sbHeader );
	}
}

void Gen_VectorLength( const genLanguage_t language, const genType_t type, const u32 numComponents, stringBuilder_t* sbHeader ) {
	assert( numComponents >= GEN_COMPONENT_COUNT_MIN );
	assert( numComponents <= GEN_COMPONENT_COUNT_MAX );

	if ( type == GEN_TYPE_BOOL ) {
		return;
	}

	genType_t floatingPointType = Gen_GetSupportedFloatingPointType( type );

	bool32 shouldTypecast = !Gen_TypeIsFloatingPoint( type );

	const char* returnTypeString = Gen_GetTypeString( floatingPointType );

	char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetFullTypeName( type, 1, numComponents, fullTypeName );

	char parmTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetParmTypeName( language, type, 1, numComponents, parmTypeName );

	char lengthsqrFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameLengthsqr( language, type, numComponents, lengthsqrFuncStr );

	char lengthFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameLength( language, type, numComponents, lengthFuncStr );

	const char* sqrtFuncStr = Gen_GetFuncNameSqrt( type );

	const char* parmAccessStr = GEN_TYPE_ACCESS_OPERATORS[language];

	Doc_VectorLengthSqr( sbHeader, fullTypeName );
	String_Appendf( sbHeader, "inline %s %s( const %s vec )\n", returnTypeString, lengthsqrFuncStr, parmTypeName );
	String_Append(  sbHeader, "{\n" );
	String_Append(  sbHeader, "\treturn " );

	if ( shouldTypecast ) {
		String_Appendf( sbHeader, "(%s)( ", returnTypeString );
	}

	for ( u32 i = 0; i < numComponents; i++ ) {
		char componentName = GEN_COMPONENT_NAMES_VECTOR[i];

		String_Appendf( sbHeader, "( vec%s%c * vec%s%c )", parmAccessStr, componentName, parmAccessStr, componentName );

		if ( i != numComponents - 1 ) {
			String_Append( sbHeader, " + " );
		}
	}

	if ( shouldTypecast ) {
		String_Append( sbHeader, " )" );
	}

	String_Append( sbHeader, ";\n" );
	String_Append( sbHeader, "}\n" );
	String_Append( sbHeader, "\n" );

	Doc_VectorLength( sbHeader, fullTypeName );
	String_Appendf( sbHeader, "inline %s %s( const %s vec )\n", returnTypeString, lengthFuncStr, parmTypeName );
	String_Append(  sbHeader, "{\n" );
	String_Appendf( sbHeader, "\treturn %s( %s( vec ) );\n", sqrtFuncStr, lengthsqrFuncStr );
	String_Append(  sbHeader, "}\n" );
	String_Append(  sbHeader, "\n" );
}

void Gen_VectorNormalize( const genLanguage_t language, const genType_t type, const u32 numComponents, stringBuilder_t* sbHeader ) {
	assert( numComponents >= GEN_COMPONENT_COUNT_MIN );
	assert( numComponents <= GEN_COMPONENT_COUNT_MAX );

	if ( !Gen_TypeIsFloatingPoint( type ) ) {
		return;
	}

	const char* typeString = Gen_GetTypeString( type );

	const char* parmRefStr = GEN_TYPE_PARM_REFERENCE_MODIFIERS[language];

	char oneStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	Gen_GetNumericLiteral( type, 1, oneStr, 1 );

	char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetFullTypeName( type, 1, numComponents, fullTypeName );

	char parmTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetParmTypeName( language, type, 1, numComponents, parmTypeName );

	char normalizeFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameNormalize( language, type, numComponents, normalizeFuncStr );

	char normalizedFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameNormalized( language, type, numComponents, normalizedFuncStr );

	char lengthFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameLength( language, type, numComponents, lengthFuncStr );

	char compMulStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameComponentWiseArithmeticVector( language, type, 1, numComponents, GEN_OP_ARITHMETIC_MUL, compMulStr );

	char compDivStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameComponentWiseArithmeticVector( language, type, 1, numComponents, GEN_OP_ARITHMETIC_DIV, compDivStr );

	// normalize
	Doc_VectorNormalize( sbHeader, fullTypeName );
	String_Appendf( sbHeader, "inline void %s( %s vec )\n", normalizeFuncStr, parmTypeName );
	String_Append(  sbHeader, "{\n" );
	String_Appendf( sbHeader, "\t%s len = %s( vec );\n", typeString, lengthFuncStr );
	String_Appendf( sbHeader, "\t%s invlen = HLML_CONSTRUCT( %s ) {\n", fullTypeName, fullTypeName );
	for ( u32 i = 0; i < numComponents; i++ ) {
		String_Appendf( sbHeader, "\t\t%s / len", oneStr );

		if ( i != numComponents - 1 ) {
			String_Append( sbHeader, "," );
		}

		String_Append( sbHeader, "\n" );
	}
	String_Append(  sbHeader, "\t};\n" );
	String_Append(  sbHeader, "\n" );
	String_Appendf( sbHeader, "\t%svec = %s( vec, %sinvlen );\n", GEN_TYPE_PARM_DEREFERENCE_MODIFIERS[language], compMulStr, parmRefStr );
	String_Append(  sbHeader, "}\n" );
	String_Append(  sbHeader, "\n" );

	// normalized
	Doc_VectorNormalized( sbHeader, fullTypeName );
	String_Appendf( sbHeader, "inline %s %s( const %s vec )\n", fullTypeName, normalizedFuncStr, parmTypeName );
	String_Append(  sbHeader, "{\n" );
	String_Appendf( sbHeader, "\t%s len = %s( vec );\n", typeString, lengthFuncStr );
	String_Appendf( sbHeader, "\t%s invlen = HLML_CONSTRUCT( %s ) {\n", fullTypeName, fullTypeName );
	for ( u32 i = 0; i < numComponents; i++ ) {
		String_Appendf( sbHeader, "\t\t%s / len", oneStr );

		if ( i != numComponents - 1 ) {
			String_Append( sbHeader, "," );
		}

		String_Append( sbHeader, "\n" );
	}
	String_Append(  sbHeader, "\t};\n" );
	String_Append(  sbHeader, "\n" );
	String_Appendf( sbHeader, "\treturn %s( vec, %sinvlen );\n", compMulStr, parmRefStr);
	String_Append(  sbHeader, "}\n" );
	String_Append(  sbHeader, "\n" );
}

void Gen_VectorDot( const genLanguage_t language, const genType_t type, const u32 numComponents, stringBuilder_t* sbHeader ) {
	assert( numComponents >= GEN_COMPONENT_COUNT_MIN );
	assert( numComponents <= GEN_COMPONENT_COUNT_MAX );

	if ( type == GEN_TYPE_BOOL ) {
		return;
	}

	// dot can return negative values, so uint vectors have to return signed int
	bool shouldTypeCast = type == GEN_TYPE_UINT;

	genType_t returnType = shouldTypeCast ? GEN_TYPE_INT : type;
	const char* returnTypeString = Gen_GetMemberTypeString( returnType );

	char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetFullTypeName( type, 1, numComponents, fullTypeName );

	char dotFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameDot( language, type, numComponents, dotFuncStr );

	const char parmRefStr = GEN_TYPE_PARM_MODIFIERS[language];
	const char* parmAccessStr = GEN_TYPE_ACCESS_OPERATORS[language];

	Doc_VectorDot( sbHeader, fullTypeName );
	String_Appendf( sbHeader, "inline %s %s( const %s%c lhs, const %s%c rhs )\n", returnTypeString, dotFuncStr, fullTypeName, parmRefStr, fullTypeName, parmRefStr );
	String_Append(  sbHeader, "{\n" );
	String_Append(  sbHeader, "\treturn " );

	if ( shouldTypeCast ) {
		String_Appendf( sbHeader, "(%s)( ", returnTypeString );
	}

	for ( u32 i = 0; i < numComponents; i++ ) {
		char componentName = GEN_COMPONENT_NAMES_VECTOR[i];

		String_Appendf( sbHeader, "( lhs%s%c * rhs%s%c )", parmAccessStr, componentName, parmAccessStr, componentName );

		if ( i != numComponents - 1 ) {
			String_Append( sbHeader, " + " );
		}
	}

	if ( shouldTypeCast ) {
		String_Append( sbHeader, " )" );
	}

	String_Append( sbHeader, ";\n" );
	String_Append( sbHeader, "}\n" );
	String_Append( sbHeader, "\n" );
}

void Gen_VectorCross( const genLanguage_t language, const genType_t type, const u32 numComponents, stringBuilder_t* sbHeader ) {
	assert( numComponents >= GEN_COMPONENT_COUNT_MIN );
	assert( numComponents <= GEN_COMPONENT_COUNT_MAX );

	if ( !Gen_TypeIsFloatingPoint( type ) ) {
		return;
	}

	if ( numComponents < 3 ) {
		return;
	}

	char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetFullTypeName( type, 1, numComponents, fullTypeName );

	char parmTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetParmTypeName( language, type, 1, numComponents, parmTypeName );

	char crossFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameCross( language, type, numComponents, crossFuncStr );

	const char* parmAccessStr = GEN_TYPE_ACCESS_OPERATORS[language];

	Doc_VectorCross( sbHeader, fullTypeName );
	String_Appendf( sbHeader, "inline %s %s( const %s lhs, const %s rhs )\n", fullTypeName, crossFuncStr, parmTypeName, parmTypeName );
	String_Append(  sbHeader, "{\n" );
	String_Appendf( sbHeader, "\treturn HLML_CONSTRUCT( %s ) {\n", fullTypeName );
	String_Appendf( sbHeader, "\t\t( lhs%sy * rhs%sz ) - ( lhs%sz * rhs%sy ),\n", parmAccessStr, parmAccessStr, parmAccessStr, parmAccessStr );
	String_Appendf( sbHeader, "\t\t( lhs%sz * rhs%sx ) - ( lhs%sx * rhs%sz ),\n", parmAccessStr, parmAccessStr, parmAccessStr, parmAccessStr );
	String_Appendf( sbHeader, "\t\t( lhs%sx * rhs%sy ) - ( lhs%sy * rhs%sx )", parmAccessStr, parmAccessStr, parmAccessStr, parmAccessStr );
	if ( numComponents > 3 ) {
		String_Appendf( sbHeader, ",\n\t\t%s\n", Gen_GetDefaultLiteralValue( type ) );
	} else {
		String_Append( sbHeader, "\n" );
	}
	String_Append( sbHeader, "\t};\n" );
	String_Append( sbHeader, "}\n" );
	String_Append( sbHeader, "\n" );
}

void Gen_VectorAngle( const genLanguage_t language, const genType_t type, const u32 numComponents, stringBuilder_t* sbHeader ) {
	assert( numComponents >= GEN_COMPONENT_COUNT_MIN );
	assert( numComponents <= GEN_COMPONENT_COUNT_MAX );

	if ( !Gen_TypeIsFloatingPoint( type ) ) {
		return;
	}

	genType_t floatingPointType = Gen_GetSupportedFloatingPointType( type );

	const char* returnTypeString = Gen_GetTypeString( floatingPointType );

	char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetFullTypeName( type, 1, numComponents, fullTypeName );

	char parmTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetParmTypeName( language, type, 1, numComponents, parmTypeName );

	const char* degreesFuncStr = Gen_GetFuncNameDegrees( type );

	const char* acosString = Gen_GetFuncNameAcos( floatingPointType );

	char angleFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameAngle( language, type, numComponents, angleFuncStr );

	char dotFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameDot( language, type, numComponents, dotFuncStr );

	char normalizedFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameNormalized( language, type, numComponents, normalizedFuncStr );

	Doc_VectorAngle( sbHeader, fullTypeName );
	String_Appendf( sbHeader, "inline %s %s( const %s lhs, const %s rhs )\n", returnTypeString, angleFuncStr, parmTypeName, parmTypeName );
	String_Append(  sbHeader, "{\n" );
	if ( language == GEN_LANGUAGE_C ) {
		String_Appendf( sbHeader, "\t%s lhs_unit = %s( lhs );\n", fullTypeName, normalizedFuncStr );
		String_Appendf( sbHeader, "\t%s rhs_unit = %s( rhs );\n", fullTypeName, normalizedFuncStr );
		String_Appendf( sbHeader, "\treturn %s( %s( %s( &lhs_unit, &rhs_unit ) ) );\n", degreesFuncStr, acosString, dotFuncStr );
	} else {
		String_Appendf( sbHeader, "\treturn %s( %s( %s( %s( lhs ), %s( rhs ) ) ) );\n", degreesFuncStr, acosString, dotFuncStr, normalizedFuncStr, normalizedFuncStr );
	}
	String_Append(  sbHeader, "}\n" );
	String_Append(  sbHeader, "\n" );
}

void Gen_VectorDistance( const genLanguage_t language, const genType_t type, const u32 numComponents, stringBuilder_t* sbHeader ) {
	assert( numComponents >= GEN_COMPONENT_COUNT_MIN );
	assert( numComponents <= GEN_COMPONENT_COUNT_MAX );

	if ( type == GEN_TYPE_BOOL ) {
		return;
	}

	if ( numComponents > 3 ) {
		return;
	}

	char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetFullTypeName( type, 1, numComponents, fullTypeName );

	char parmTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetParmTypeName( language, type, 1, numComponents, parmTypeName );

	const char* returnTypeString = Gen_GetTypeString( Gen_GetSupportedFloatingPointType( type ) );

	const char* parmRefStr = GEN_TYPE_PARM_REFERENCE_MODIFIERS[language];

	char distancesqrFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameDistancesqr( language, type, numComponents, distancesqrFuncStr );

	char distanceFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameDistance( language, type, numComponents, distanceFuncStr );

	char subRhsTypeFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameComponentWiseArithmeticVector( language, type, 1, numComponents, GEN_OP_ARITHMETIC_SUB, subRhsTypeFuncStr );

	char lengthsqrFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameLengthsqr( language, type, numComponents, lengthsqrFuncStr );

	char lengthFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameLength( language, type, numComponents, lengthFuncStr );

	// distancesq
	{
		Doc_VectorDistanceSq( sbHeader, fullTypeName );
		String_Appendf( sbHeader, "inline %s %s( const %s lhs, const %s rhs )\n", returnTypeString, distancesqrFuncStr, parmTypeName, parmTypeName );
		String_Append(  sbHeader, "{\n" );
		String_Appendf( sbHeader, "\t%s delta = %s( lhs, rhs );\n", fullTypeName, subRhsTypeFuncStr );
		String_Appendf( sbHeader, "\treturn %s( %sdelta );\n", lengthsqrFuncStr, parmRefStr );
		String_Append(  sbHeader, "}\n" );
		String_Append(  sbHeader, "\n" );
	}

	// distance
	{
		Doc_VectorDistance( sbHeader, fullTypeName );
		String_Appendf( sbHeader, "inline %s %s( const %s lhs, const %s rhs )\n", returnTypeString, distanceFuncStr, parmTypeName, parmTypeName );
		String_Append(  sbHeader, "{\n" );
		String_Appendf( sbHeader, "\t%s delta = %s( lhs, rhs );\n", fullTypeName, subRhsTypeFuncStr );
		String_Appendf( sbHeader, "\treturn %s( %sdelta );\n", lengthFuncStr, parmRefStr );
		String_Append(  sbHeader, "}\n" );
		String_Append(  sbHeader, "\n" );
	}
}

void Gen_VectorPack( const genLanguage_t language, const genType_t type, const u32 numComponents, stringBuilder_t* sbHeader ) {
	assert( numComponents >= GEN_COMPONENT_COUNT_MIN );
	assert( numComponents <= GEN_COMPONENT_COUNT_MAX );

	if ( type != GEN_TYPE_UINT ) {
		return;
	}

	if ( numComponents != 4 ) {
		return;
	}

	u32 shiftVals[] = {
		24, 16, 8, 0
	};

	char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetFullTypeName( type, 1, numComponents, fullTypeName );

	char parmTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetParmTypeName( language, type, 1, numComponents, parmTypeName );

	const char* memberTypeString = Gen_GetMemberTypeString( type );

	const char* parmAccessStr = GEN_TYPE_ACCESS_OPERATORS[language];

	Doc_VectorPack( sbHeader, fullTypeName );
	String_Appendf( sbHeader, "inline %s pack( const %s vec )\n", memberTypeString, parmTypeName );
	String_Append(  sbHeader, "{\n" );
	String_Append(  sbHeader, "\treturn " );
	for ( u32 i = 0; i < numComponents; i++ ) {
		String_Appendf( sbHeader, "( vec%s%c << %d )", parmAccessStr, GEN_COMPONENT_NAMES_VECTOR[i], shiftVals[i] );

		if ( i != numComponents - 1 ) {
			String_Append( sbHeader, " | " );
		}
	}
	String_Append( sbHeader, ";\n" );
	String_Append( sbHeader, "}\n" );
	String_Append( sbHeader, "\n" );
}

void Gen_VectorUnpack( const genLanguage_t language, const genType_t type, const u32 numComponents, stringBuilder_t* sbHeader ) {
	assert( numComponents >= GEN_COMPONENT_COUNT_MIN );
	assert( numComponents <= GEN_COMPONENT_COUNT_MAX );

	( (void) language );

	if ( type != GEN_TYPE_UINT ) {
		return;
	}

	if ( numComponents != 4 ) {
		return;
	}

	u32 shiftVals[] = {
		24, 16, 8, 0
	};

	char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetFullTypeName( type, 1, numComponents, fullTypeName );

	const char* memberTypeString = Gen_GetMemberTypeString( type );

	Doc_VectorUnpack( sbHeader, fullTypeName );
	String_Appendf( sbHeader, "inline %s unpack( const %s x )\n", fullTypeName, memberTypeString );
	String_Append(  sbHeader, "{\n" );
	String_Appendf( sbHeader, "\treturn HLML_CONSTRUCT( %s ) {\n", fullTypeName );
	for ( u32 i = 0; i < numComponents; i++ ) {
		String_Appendf( sbHeader, "\t\t( x >> %d ) & 0xFF", shiftVals[i] );

		if ( i != numComponents - 1 ) {
			String_Append( sbHeader, "," );
		}

		String_Append( sbHeader, "\n" );
	}
	String_Append( sbHeader, "\t};\n" );
	String_Append( sbHeader, "}\n" );
	String_Append( sbHeader, "\n" );
}

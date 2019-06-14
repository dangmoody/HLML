#include "gen_common.h"

#include "gen_doc_common.h"

#include <assert.h>

static std::string HeaderGetOperatorIncrement( const genType_t type, const u32 numRows, const u32 numCols, const genOpIncrement_t op ) {
	std::string fullTypeName = Gen_GetFullTypeName( type, numRows, numCols );
	std::string memberTypeString = Gen_GetMemberTypeString( type );

	std::string code;

	// prefix
	code += Gen_GetDocOperatorIncrementPrefix( fullTypeName, op );
	code += "inline " + fullTypeName + "& operator" + GEN_OPERATORS_INCREMENT[op] + "( " + fullTypeName + "& lhs );\n";
	code += "\n";

	// postfix
	code += Gen_GetDocOperatorIncrementPostfix( fullTypeName, op );
	code += "inline " + fullTypeName + "& operator" + GEN_OPERATORS_INCREMENT[op] + "( " + fullTypeName + "& lhs, const int );\n";
	code += "\n";

	return code;
}

static std::string InlGetOperatorIncrement( const genType_t type, const u32 numRows, const u32 numCols, const genOpIncrement_t op ) {
	u32 numComponents = ( numRows == 1 ) ? numCols : numRows;

	std::string fullTypeName = Gen_GetFullTypeName( type, numRows, numCols );
	std::string memberTypeString = Gen_GetMemberTypeString( type );

	std::string code;

	// prefix
	code += "// prefix\n";
	code += fullTypeName + "& operator" + GEN_OPERATORS_INCREMENT[op] + "( " + fullTypeName + "& lhs )\n";
	code += "{\n";
	for ( u32 i = 0; i < numComponents; i++ ) {
		code += "\t" + GEN_OPERATORS_INCREMENT[op] + "lhs[" + std::to_string( i ) + "];\n";
	}
	code += "\treturn lhs;\n";
	code += "}\n";
	code += "\n";

	// postfix
	code += "// postfix\n";
	code += fullTypeName + "& operator" + GEN_OPERATORS_INCREMENT[op] + "( " + fullTypeName + "& lhs, const int )\n";
	code += "{\n";
	for ( u32 i = 0; i < numComponents; i++ ) {
		code += std::string( "\tlhs[" ) + std::to_string( i ) + "]" + GEN_OPERATORS_INCREMENT[op] + ";\n";
	}
	code += "\treturn lhs;\n";
	code += "}\n";
	code += "\n";

	return code;
}

static std::string HeaderGetOperatorRelational( const genType_t type, const u32 numRows, const u32 numCols, const genOpRelational_t op ) {
	std::string fullTypeName = Gen_GetFullTypeName( type, numRows, numCols );
	std::string boolReturnType = Gen_GetFullTypeName( GEN_TYPE_BOOL, numRows, numCols );

	std::string code;

	code += Gen_GetDocOperatorRelational( fullTypeName, numRows, numCols, op );
	code += "inline " + boolReturnType + " operator" + GEN_OPERATORS_RELATIONAL[op] + "( const " + fullTypeName + "& lhs, const " + fullTypeName + "& rhs );\n";
	code += "\n";

	return code;
}

static std::string InlGetOperatorRelational( const genType_t type, const u32 numRows, const u32 numCols, const genOpRelational_t op ) {
	u32 numComponents = ( numRows == 1 ) ? numCols : numRows;

	std::string fullTypeName = Gen_GetFullTypeName( type, numRows, numCols );
	std::string boolReturnType = Gen_GetFullTypeName( GEN_TYPE_BOOL, numRows, numCols );

	std::string opStr = GEN_OPERATORS_RELATIONAL[op];

	std::string code;

	code += boolReturnType + " operator" + opStr + "( const " + fullTypeName + "& lhs, const " + fullTypeName + "& rhs )\n";
	code += "{\n";
	code += "\treturn " + boolReturnType + "(\n";

	for ( u32 i = 0; i < numComponents; i++ ) {
		std::string componentStr = std::to_string( i );

		code += "\t\tlhs[" + componentStr + "] " + opStr + " rhs[" + componentStr + "]";

		if ( i != numComponents - 1 ) {
			code += ",";
		}

		code += "\n";
	}
	code += "\t);\n";
	code += "}\n";
	code += "\n";

	return code;
}

static std::string HeaderGetOperatorBitwiseScalar( const genType_t type, const u32 numRows, const u32 numCols, const genOpBitwise_t op ) {
	std::string fullTypeName = Gen_GetFullTypeName( type, numRows, numCols );
	std::string memberTypeString = Gen_GetMemberTypeString( type );

	std::string opStr = GEN_OPERATORS_BITWISE[op];

	std::string code;

	code += Gen_GetDocOperatorBitwiseScalar( fullTypeName, op );
	code += "inline " + fullTypeName + " operator" + opStr + "( const " + fullTypeName + "& lhs, const " + memberTypeString + "& rhs );\n";
	code += "\n";

	code += Gen_GetDocOperatorCompoundBitwiseScalar( fullTypeName, op );
	code += "inline " + fullTypeName + " operator" + opStr + "=( " + fullTypeName + "& lhs, const " + memberTypeString + "& rhs );\n";
	code += "\n";

	return code;
}

static std::string InlGetOperatorBitwiseScalar( const genType_t type, const u32 numRows, const u32 numCols, const genOpBitwise_t op ) {
	u32 numComponents = ( numRows == 1 ) ? numCols : numRows;

	std::string fullTypeName = Gen_GetFullTypeName( type, numRows, numCols );
	std::string memberTypeString = Gen_GetMemberTypeString( type );

	std::string opStr = GEN_OPERATORS_BITWISE[op];

	std::string code;

	// main bitwise operator
	code += fullTypeName + " operator" + opStr + "( const " + fullTypeName + "& lhs, const " + memberTypeString + "& rhs )\n";
	code += "{\n";
	code += "\treturn " + fullTypeName + "(\n";
	for ( u32 i = 0; i < numComponents; i++ ) {
		code += std::string( "\t\tlhs[" ) + std::to_string( i ) + "] " + opStr + " rhs";

		if ( i != numComponents - 1 ) {
			code += ",";
		}

		code += "\n";
	}
	code += "\t);\n";
	code += "}\n";
	code += "\n";

	// compound bitwise operator
	code += fullTypeName + " operator" + opStr + "=( " + fullTypeName + "& lhs, const " + memberTypeString + "& rhs )\n";
	code += "{\n";
	code += "\treturn ( lhs = lhs " + opStr + " rhs );\n";
	code += "}\n";
	code += "\n";

	return code;
}

static std::string HeaderGetOperatorBitwiseRhsType( const genType_t type, const u32 numRows, const u32 numCols, const genOpBitwise_t op ) {
	std::string fullTypeName = Gen_GetFullTypeName( type, numRows, numCols );
	std::string memberTypeString = Gen_GetMemberTypeString( type );

	std::string opStr = GEN_OPERATORS_BITWISE[op];

	std::string code;

	code += Gen_GetDocOperatorBitwiseRhsType( fullTypeName, op );
	code += "inline " + fullTypeName + " operator" + opStr + "( const " + fullTypeName + "& lhs, const " + fullTypeName + "& rhs );\n";
	code += "\n";

	code += Gen_GetDocOperatorCompoundBitwiseRhsType( fullTypeName, op );
	code += "inline " + fullTypeName + " operator" + opStr + "=( " + fullTypeName + "& lhs, const " + fullTypeName + "& rhs );\n";
	code += "\n";

	return code;
}

static std::string InlGetOperatorBitwiseRhsType( const genType_t type, const u32 numRows, const u32 numCols, const genOpBitwise_t op ) {
	u32 numComponents = ( numRows == 1 ) ? numCols : numRows;

	std::string fullTypeName = Gen_GetFullTypeName( type, numRows, numCols );

	std::string opStr = GEN_OPERATORS_BITWISE[op];

	std::string code;

	// main bitwise operator
	code += fullTypeName + " operator" + opStr + "( const " + fullTypeName + "& lhs, const " + fullTypeName + "& rhs )\n";
	code += "{\n";
	code += "\treturn " + fullTypeName + "(\n";
	for ( u32 i = 0; i < numComponents; i++ ) {
		std::string componentStr = std::to_string( i );

		code += "\t\tlhs[" + componentStr + "] " + opStr + " rhs[" + componentStr + "]";

		if ( i != numComponents - 1 ) {
			code += ",";
		}

		code += "\n";
	}
	code += "\t);\n";
	code += "}\n";
	code += "\n";

	// compound bitwise operator
	code += fullTypeName + " operator" + opStr + "=( " + fullTypeName + "& lhs, const " + fullTypeName + "& rhs )\n";
	code += "{\n";
	code += "\treturn ( lhs = lhs " + opStr + " rhs );\n";
	code += "}\n";
	code += "\n";

	return code;
}


void Gen_Floateq( const genType_t type, std::string& outHeader ) {
	if ( !Gen_IsFloatingPointType( type ) ) {
		return;
	}

	std::string typeString = Gen_GetTypeString( type );

	std::string floateqStr = Gen_GetFuncNameFloateq( type );

	std::string parmEpsilonStr = Gen_GetConstantNameEpsilon( type );

	outHeader += Gen_GetDocFloateq();
	outHeader += "inline bool " + floateqStr + "( const " + typeString + " lhs, const " + typeString + " rhs, const " + typeString + " epsilon = " + parmEpsilonStr + " )\n";
	outHeader += "{\n";
	outHeader += "\treturn " + Gen_GetFuncNameFabs( type ) + "( lhs - rhs ) < epsilon;\n";
	outHeader += "}\n";
	outHeader += "\n";
}

void Gen_Sign( const genType_t type, std::string& outHeader ) {
	if ( type == GEN_TYPE_BOOL || type == GEN_TYPE_UINT ) {
		return;
	}

	std::string memberTypeString = Gen_GetMemberTypeString( type );
	std::string intTypeString = Gen_GetMemberTypeString( GEN_TYPE_INT );

	std::string zeroStr = Gen_GetNumericLiteral( type, 0.0f );

	outHeader += Gen_GetDocSign();
	outHeader += "inline " + intTypeString + " sign( const " + memberTypeString + " x )\n";
	outHeader += "{\n";
	outHeader += "\treturn ( " + zeroStr + " < x ) - ( x < " + zeroStr + " );\n";
	outHeader += "}\n";
	outHeader += "\n";
}

void Gen_Radians( const genType_t type, std::string& outHeader ) {
	if ( !Gen_IsFloatingPointType( type ) ) {
		return;
	}

	std::string typeString = Gen_GetTypeString( type );
	std::string oneHundredEightyStr = Gen_GetNumericLiteral( type, 180.0f );

	std::string piStr = Gen_GetConstantNamePi( type );

	outHeader += Gen_GetDocRadians();
	outHeader += "inline " + typeString + " radians( const " + typeString + " deg )\n";
	outHeader += "{\n";
	outHeader += "\treturn deg * " + piStr + " / " + oneHundredEightyStr + ";\n";
	outHeader += "}\n";
	outHeader += "\n";
}

void Gen_Degrees( const genType_t type, std::string& outHeader ) {
	if ( !Gen_IsFloatingPointType( type ) ) {
		return;
	}

	std::string typeString = Gen_GetTypeString( type );
	std::string oneHundredEightyStr = Gen_GetNumericLiteral( type, 180.0f );

	std::string piStr = Gen_GetConstantNamePi( type );

	outHeader += Gen_GetDocDegrees();
	outHeader += "inline " + typeString + " degrees( const " + typeString + " rad )\n";
	outHeader += "{\n";
	outHeader += "\treturn rad * " + oneHundredEightyStr + " / " + piStr + ";\n";
	outHeader += "}\n";
	outHeader += "\n";
}

void Gen_MinMax( const genType_t type, std::string& outHeader ) {
	if ( type == GEN_TYPE_BOOL ) {
		return;
	}

	std::string memberTypeString = Gen_GetMemberTypeString( type );

	// min
	outHeader += Gen_GetDocMin();
	outHeader += "inline " + memberTypeString + " min( const " + memberTypeString + "& x, const " + memberTypeString + "& y )\n";
	outHeader += "{\n";
	outHeader += "\treturn ( x < y ) ? x : y;\n";
	outHeader += "}\n";
	outHeader += "\n";

	// max
	outHeader += Gen_GetDocMax();
	outHeader += "inline " + memberTypeString + " max( const " + memberTypeString + "& x, const " + memberTypeString + "& y )\n";
	outHeader += "{\n";
	outHeader += "\treturn ( x > y ) ? x : y;\n";
	outHeader += "}\n";
	outHeader += "\n";
}

void Gen_Clamp( const genType_t type, std::string& outHeader ) {
	if ( type == GEN_TYPE_BOOL ) {
		return;
	}

	std::string memberTypeString = Gen_GetMemberTypeString( type );

	outHeader += Gen_GetDocClamp();
	outHeader += "inline " + memberTypeString + " clamp( const " + memberTypeString + "& x, const " + memberTypeString + "& low, const " + memberTypeString + "& high )\n";
	outHeader += "{\n";
	outHeader += "\treturn min( max( x, low ), high );\n";
	outHeader += "}\n";
	outHeader += "\n";
}

void Gen_Saturate( const genType_t type, const u32 numComponents, std::string& outHeader, std::string* outInl ) {
	assert( numComponents >= 1 );	// we allow scalar types for this function
	assert( numComponents <= GEN_COMPONENT_COUNT_MAX );

	if ( !Gen_IsFloatingPointType( type ) ) {
		return;
	}

	std::string fullTypeName = Gen_GetFullTypeName( type, 1, numComponents );

	std::string zeroStr	= Gen_GetNumericLiteral( type, 0.0f );
	std::string oneStr	= Gen_GetNumericLiteral( type, 1.0f );

	bool isVector = numComponents > 1;
	if ( isVector ) {
		assert( outInl );	// only don't output to an .inl file for scalar impls
	}

	outHeader += Gen_GetDocSaturate( fullTypeName );
	outHeader += "inline " + fullTypeName + " saturate( const " + fullTypeName + "& x )";
	if ( isVector ) {
		outHeader += ";\n";
		outHeader += "\n";

		*outInl += fullTypeName + " saturate( const " + fullTypeName + "& x )\n";
		*outInl += "{\n";
		*outInl += "\treturn " + fullTypeName + "(\n";
		for ( u32 i = 0; i < numComponents; i++ ) {
			*outInl += "\t\tclamp( x[" + std::to_string( i ) + "], " + zeroStr + ", " + oneStr + " )";

			if ( i != numComponents - 1 ) {
				*outInl += ",";
			}

			*outInl += "\n";
		}

		*outInl += "\t);\n";
		*outInl += "}\n";
		*outInl += "\n";
	} else {
		outHeader += "\n";
		outHeader += "{\n";
		outHeader += "\treturn clamp( x, " + zeroStr + ", " + oneStr + " );\n";
		outHeader += "}\n";
		outHeader += "\n";
	}
}

void Gen_Lerp( const genType_t type, const u32 numComponents, std::string& outHeader, std::string* outInl ) {
	assert( numComponents >= 1 );	// we allow scalar types for this function
	assert( numComponents <= GEN_COMPONENT_COUNT_MAX );

	if ( !Gen_IsFloatingPointType( type ) ) {
		return;
	}

	std::string typeString = Gen_GetTypeString( type );
	std::string fullTypeName = Gen_GetFullTypeName( type, 1, numComponents );

	std::string oneStr = Gen_GetNumericLiteral( type, 1.0f );

	bool isVector = numComponents > 1;
	if ( isVector ) {
		assert( outInl );	// only don't output to an .inl file for scalar impls
	}

	outHeader += Gen_GetDocLerp( fullTypeName );
	outHeader += "inline " + fullTypeName + " lerp( const " + fullTypeName + "& a, const " + fullTypeName + "& b, const " + typeString + " t )";
	if ( isVector ) {
		outHeader += ";\n";
		outHeader += "\n";

		*outInl += fullTypeName + " lerp( const " + fullTypeName + "& a, const " + fullTypeName + "& b, const " + typeString + " t )\n";
		*outInl += "{\n";
		*outInl += "\treturn " + fullTypeName + "(\n";
		for ( u32 i = 0; i < numComponents; i++ ) {
			std::string componentStr = std::to_string( i );

			*outInl += "\t\tlerp( a[" + componentStr + "], b[" + componentStr + "], t )";

			if ( i != numComponents - 1 ) {
				*outInl += ",";
			}

			*outInl += "\n";
		}

		*outInl += "\t);\n";
		*outInl += "}\n";
		*outInl += "\n";
	} else {
		outHeader += "\n";
		outHeader += "{\n";
		outHeader += "\treturn ( " + oneStr + " - t ) * a + t * b;\n";
		outHeader += "}\n";
		outHeader += "\n";
	}
}

void Gen_Smoothstep( const genType_t type, const u32 numComponents, std::string& outHeader, std::string* outInl ) {
	assert( numComponents >= 1 );	// we allow scalar types for this function
	assert( numComponents <= GEN_COMPONENT_COUNT_MAX );

	if ( !Gen_IsFloatingPointType( type ) ) {
		return;
	}

	std::string typeString		= Gen_GetTypeString( type );
	std::string fullTypeName	= Gen_GetFullTypeName( type, 1, numComponents );

	std::string twoStr		= Gen_GetNumericLiteral( type, 2.0f );
	std::string threeStr	= Gen_GetNumericLiteral( type, 3.0f );
	std::string sixStr		= Gen_GetNumericLiteral( type, 6.0f );
	std::string tenStr		= Gen_GetNumericLiteral( type, 10.0f );
	std::string fifteenStr	= Gen_GetNumericLiteral( type, 15.0f );

	std::string twoVec		= fullTypeName + "( " + twoStr + " )";
	std::string threeVec	= fullTypeName + "( " + threeStr + " )";
	std::string sixVec		= fullTypeName + "( " + sixStr + " )";
	std::string tenVec		= fullTypeName + "( " + tenStr + " )";
	std::string fifteenVec	= fullTypeName + "( " + fifteenStr + " )";

	bool isVector = numComponents > 1;
	if ( isVector ) {
		assert( outInl );	// only don't output to an .inl file for scalar impls
	}

	// smoothstep
	{
		outHeader += Gen_GetDocSmoothstep( fullTypeName );
		outHeader += "inline " + fullTypeName + " smoothstep( const " + fullTypeName + "& low, const " + fullTypeName + "& high, const " + fullTypeName + "& x )";
		if ( isVector ) {
			outHeader += ";\n";
			outHeader += "\n";

			*outInl += fullTypeName + " smoothstep( const " + fullTypeName + "& low, const " + fullTypeName + "& high, const " + fullTypeName + "& x )\n";
			*outInl += "{\n";
			*outInl += "\treturn " + fullTypeName + "(\n";
			for ( u32 i = 0; i < numComponents; i++ ) {
				std::string componentStr = std::to_string( i );

				*outInl += "\t\tsmoothstep( low[" + componentStr + "], high[" + componentStr + "], x[" + componentStr + "] )";

				if ( i != numComponents - 1 ) {
					*outInl += ",";
				}

				*outInl += "\n";
			}
			*outInl += "\t);\n";
			*outInl += "}\n";
			*outInl += "\n";
		} else {
			outHeader += "\n";
			outHeader += "{\n";
			outHeader += "\t" + fullTypeName + " t = saturate( ( x - low ) / ( high - low ) );\n";
			outHeader += "\treturn t * t * ( " + threeStr + " - " + twoStr + " * t );\n";
			outHeader += "}\n";
			outHeader += "\n";
		}
	}

	// smootherstep
	{
		outHeader += Gen_GetDocSmootherstep( fullTypeName );
		outHeader += "inline " + fullTypeName + " smootherstep( const " + fullTypeName + "& low, const " + fullTypeName + "& high, const " + fullTypeName + "& x )";
		if ( isVector ) {
			outHeader += ";\n";
			outHeader += "\n";

			*outInl += fullTypeName + " smootherstep( const " + fullTypeName + "& low, const " + fullTypeName + "& high, const " + fullTypeName + "& x )\n";
			*outInl += "{\n";
			*outInl += "\treturn " + fullTypeName + "(\n";
			for ( u32 i = 0; i < numComponents; i++ ) {
				std::string componentStr = std::to_string( i );

				*outInl += "\t\tsmootherstep( low[" + componentStr + "], high[" + componentStr + "], x[" + componentStr + "] )";

				if ( i != numComponents - 1 ) {
					*outInl += ",";
				}

				*outInl += "\n";
			}
			*outInl += "\t);\n";
			*outInl += "}\n";
			*outInl += "\n";
		} else {
			outHeader += "\n";
			outHeader += "{\n";
			outHeader += "\t" + fullTypeName + " t = saturate( ( x - low ) / ( high - low ) );\n";
			outHeader += "\treturn t * t * t * ( t * ( t * " + sixStr + " - " + fifteenStr + " ) + " + tenStr + " );\n";
			outHeader += "}\n";
			outHeader += "\n";
		}
	}
}

void Gen_OperatorsIncrement( const genType_t type, const u32 numRows, const u32 numCols, std::string& outHeader, std::string& outInl ) {
	assert( numRows >= 1 );	// pass through 1 for vectors
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );

	if ( type == GEN_TYPE_BOOL ) {
		return;
	}

	for ( u32 opIndex = 0; opIndex < GEN_OP_INCREMENT_COUNT; opIndex++ ) {
		genOpIncrement_t op = static_cast<genOpIncrement_t>( opIndex );

		outHeader += HeaderGetOperatorIncrement( type, numRows, numCols, op );

		outInl += InlGetOperatorIncrement( type, numRows, numCols, op );
	}
}

void Gen_OperatorsRelational( const genType_t type, const u32 numRows, const u32 numCols, std::string& outHeader, std::string& outInl ) {
	assert( numRows >= 1 );	// pass through 1 for vectors
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );

	if ( type == GEN_TYPE_BOOL ) {
		return;
	}

	for ( u32 opIndex = 0; opIndex < GEN_OP_RELATIONAL_COUNT; opIndex++ ) {
		genOpRelational_t op = static_cast<genOpRelational_t>( opIndex );

		outHeader += HeaderGetOperatorRelational( type, numRows, numCols, op );

		outInl += InlGetOperatorRelational( type, numRows, numCols, op );
	}
}

void Gen_OperatorsBitwise( const genType_t type, const u32 numRows, const u32 numCols, std::string& outHeader, std::string& outInl ) {
	assert( numRows >= 1 );	// pass through 1 for vectors
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );

	if ( type != GEN_TYPE_BOOL && !Gen_IsIntegerType( type ) ) {
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
		outHeader += HeaderGetOperatorBitwiseScalar( type, numRows, numCols, op );
		outHeader += HeaderGetOperatorBitwiseRhsType( type, numRows, numCols, op );

		outInl += InlGetOperatorBitwiseScalar( type, numRows, numCols, op );
		outInl += InlGetOperatorBitwiseRhsType( type, numRows, numCols, op );
	}

	// unary operator
	u32 numComponents = ( numRows == 1 ) ? numCols : numRows;
	std::string fullTypeName = Gen_GetFullTypeName( type, numRows, numCols );

	outHeader += Gen_GetDocOperatorBitwiseUnary( fullTypeName );
	outHeader += "inline " + fullTypeName + " operator~( const " + fullTypeName + "& lhs );\n";
	outHeader += "\n";

	outInl += fullTypeName + " operator~( const " + fullTypeName + "& lhs )\n";
	outInl += "{\n";
	outInl += "\treturn " + fullTypeName + "(\n";
	for ( u32 i = 0; i < numComponents; i++ ) {
		outInl += std::string( "\t\t~lhs[" ) + std::to_string( i ) + "]";

		if ( i != numComponents - 1 ) {
			outInl += ",";
		}

		outInl += "\n";
	}
	outInl += "\t);\n";
	outInl += "}\n";
	outInl += "\n";
}

void Gen_OperatorComponentWiseArithmeticScalar( const genType_t type, const u32 numRows, const u32 numCols, const genOpArithmetic_t op, std::string& outHeader, std::string& outInl ) {
	assert( numRows >= 1 );	// pass through 1 for vectors
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );

	if ( type == GEN_TYPE_BOOL ) {
		return;
	}

	u32 numComponents = ( numRows == 1 ) ? numCols : numRows;

	std::string fullTypeName = Gen_GetFullTypeName( type, numRows, numCols );
	std::string memberTypeString = Gen_GetMemberTypeString( type );

	char opStr = GEN_OPERATORS_ARITHMETIC[op];

	outHeader += Gen_GetDocOperatorArithmeticScalar( fullTypeName, op );
	outHeader += "inline " + fullTypeName + " operator" + opStr + "( const " + fullTypeName + "& lhs, const " + memberTypeString + " rhs );\n";
	outHeader += "\n";

	outHeader += Gen_GetDocOperatorCompoundArithmeticScalar( fullTypeName, op );
	outHeader += "inline " + fullTypeName + " operator" + opStr + "=( " + fullTypeName + "& lhs, const " + memberTypeString + " rhs );\n";
	outHeader += "\n";

	// main arithmetic func
	outInl += fullTypeName + " " + "operator" + opStr + "( const " + fullTypeName + "& lhs, const " + memberTypeString + " rhs )\n";
	outInl += "{\n";
	outInl += "\treturn " + fullTypeName + "(\n";
	for ( u32 i = 0; i < numComponents; i++ ) {
		outInl += "\t\tlhs[" + std::to_string( i ) + "] " + opStr + " rhs";

		if ( i != numComponents - 1 ) {
			outInl += ",";
		}

		outInl += "\n";
	}
	outInl += "\t);\n";
	outInl += "}\n";
	outInl += "\n";

	// compound arithmetic func
	outInl += fullTypeName + " " + "operator" + opStr + "=( " + fullTypeName + "& lhs, const " + memberTypeString + " rhs )\n";
	outInl += "{\n";
	outInl += std::string( "\treturn ( lhs = lhs " ) + opStr + " rhs );\n";
	outInl += "}\n";
	outInl += "\n";
}

void Gen_OperatorComponentWiseArithmeticRhsType( const genType_t type, const u32 numRows, const u32 numCols, const genOpArithmetic_t op, std::string& outHeader, std::string& outInl ) {
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

	std::string fullTypeName = Gen_GetFullTypeName( type, numRows, numCols );

	char opStr = GEN_OPERATORS_ARITHMETIC[op];

	outHeader += Gen_GetDocOperatorComponentWiseArithmeticRhsType( fullTypeName, fullTypeName, op );
	outHeader += "inline " + fullTypeName + " operator" + opStr + "( const " + fullTypeName + "& lhs, const " + fullTypeName + "& rhs );\n";
	outHeader += "\n";

	if ( canGenerateCompound ) {
		outHeader += Gen_GetDocOperatorCompoundComponentWiseArithmeticRhsType( fullTypeName, fullTypeName, op );
		outHeader += "inline " + fullTypeName + " operator" + opStr + "=( " + fullTypeName + "& lhs, const " + fullTypeName + "& rhs );\n";
		outHeader += "\n";
	}

	// main arithmetic func
	outInl += fullTypeName + " " + "operator" + opStr + "( const " + fullTypeName + "& lhs, const " + fullTypeName + "& rhs )\n";
	outInl += "{\n";
	outInl += "\treturn " + fullTypeName + "(\n";
	for ( u32 i = 0; i < numComponents; i++ ) {
		std::string componentStr = std::to_string( i );

		outInl += "\t\tlhs[" + componentStr + "] " + opStr + " rhs[" + componentStr + "]";

		if ( i != numComponents - 1 ) {
			outInl += ",";
		}

		outInl += "\n";
	}
	outInl += "\t);\n";
	outInl += "}\n";
	outInl += "\n";

	// compound arithmetic func
	if ( canGenerateCompound ) {
		outInl += fullTypeName + " " + "operator" + opStr + "=( " + fullTypeName + "& lhs, const " + fullTypeName + "& rhs )\n";
		outInl += "{\n";
		outInl += std::string( "\treturn ( lhs = lhs " ) + opStr + " rhs );\n";
		outInl += "}\n";
		outInl += "\n";
	}
}

void Gen_OperatorNotEquals( const genType_t type, const u32 numRows, const u32 numCols, std::string& outHeader, std::string& outInl ) {
	assert( numRows >= 1 );	// pass through 1 for vectors
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );

	std::string fullTypeName = Gen_GetFullTypeName( type, numRows, numCols );

	outHeader += Gen_GetDocOperatorNotEquals( fullTypeName );
	outHeader += "inline bool operator!=( const " + fullTypeName + "& lhs, const " + fullTypeName + "& rhs );\n";
	outHeader += "\n";

	outInl += "bool operator!=( const " + fullTypeName + "& lhs, const " + fullTypeName + "& rhs )\n";
	outInl += "{\n";
	outInl += "\treturn !( operator==( lhs, rhs ) );\n";
	outInl += "}\n";
	outInl += "\n";
}

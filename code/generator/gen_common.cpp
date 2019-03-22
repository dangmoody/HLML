#include "gen_common.h"

#include "gen_doc_common.h"

#include <assert.h>

static std::string HeaderGetOperatorIncrement( const genType_t type, const uint32_t numRows, const uint32_t numCols, const genOpIncrement_t op ) {
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

static std::string InlGetOperatorIncrement( const genType_t type, const uint32_t numRows, const uint32_t numCols, const genOpIncrement_t op ) {
	uint32_t numComponents = ( numRows == 1 ) ? numCols : numRows;

	std::string fullTypeName = Gen_GetFullTypeName( type, numRows, numCols );
	std::string memberTypeString = Gen_GetMemberTypeString( type );

	std::string code;

	// prefix
	code += "// prefix\n";
	code += fullTypeName + "& operator" + GEN_OPERATORS_INCREMENT[op] + "( " + fullTypeName + "& lhs )\n";
	code += "{\n";
	for ( uint32_t i = 0; i < numComponents; i++ ) {
		code += "\t" + GEN_OPERATORS_INCREMENT[op] + "lhs[" + std::to_string( i ) + "];\n";
	}
	code += "\treturn lhs;\n";
	code += "}\n";
	code += "\n";

	// postfix
	code += "// postfix\n";
	code += fullTypeName + "& operator" + GEN_OPERATORS_INCREMENT[op] + "( " + fullTypeName + "& lhs, const int )\n";
	code += "{\n";
	for ( uint32_t i = 0; i < numComponents; i++ ) {
		code += std::string( "\tlhs[" ) + std::to_string( i ) + "]" + GEN_OPERATORS_INCREMENT[op] + ";\n";
	}
	code += "\treturn lhs;\n";
	code += "}\n";
	code += "\n";

	return code;
}

static std::string HeaderGetOperatorRelational( const genType_t type, const uint32_t numRows, const uint32_t numCols, const genOpRelational_t op ) {
	std::string fullTypeName = Gen_GetFullTypeName( type, numRows, numCols );
	std::string boolReturnType = Gen_GetFullTypeName( GEN_TYPE_BOOL, numRows, numCols );

	std::string code;

	code += Gen_GetDocOperatorRelational( fullTypeName, numRows, numCols, op );
	code += "inline " + boolReturnType + " operator" + GEN_OPERATORS_RELATIONAL[op] + "( const " + fullTypeName + "& lhs, const " + fullTypeName + "& rhs );\n";
	code += "\n";

	return code;
}

static std::string InlGetOperatorRelational( const genType_t type, const uint32_t numRows, const uint32_t numCols, const genOpRelational_t op ) {
	uint32_t numComponents = ( numRows == 1 ) ? numCols : numRows;

	std::string fullTypeName = Gen_GetFullTypeName( type, numRows, numCols );
	std::string boolReturnType = Gen_GetFullTypeName( GEN_TYPE_BOOL, numRows, numCols );

	std::string opStr = GEN_OPERATORS_RELATIONAL[op];

	std::string code;

	code += boolReturnType + " operator" + opStr + "( const " + fullTypeName + "& lhs, const " + fullTypeName + "& rhs )\n";
	code += "{\n";
	code += "\treturn " + boolReturnType + "(\n";

	for ( uint32_t i = 0; i < numComponents; i++ ) {
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

static std::string HeaderGetOperatorBitwiseScalar( const genType_t type, const uint32_t numRows, const uint32_t numCols, const genOpBitwise_t op ) {
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

static std::string InlGetOperatorBitwiseScalar( const genType_t type, const uint32_t numRows, const uint32_t numCols, const genOpBitwise_t op ) {
	uint32_t numComponents = ( numRows == 1 ) ? numCols : numRows;

	std::string fullTypeName = Gen_GetFullTypeName( type, numRows, numCols );
	std::string memberTypeString = Gen_GetMemberTypeString( type );

	std::string opStr = GEN_OPERATORS_BITWISE[op];

	std::string code;

	// main bitwise operator
	code += fullTypeName + " operator" + opStr + "( const " + fullTypeName + "& lhs, const " + memberTypeString + "& rhs )\n";
	code += "{\n";
	code += "\treturn " + fullTypeName + "(\n";
	for ( uint32_t i = 0; i < numComponents; i++ ) {
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

static std::string HeaderGetOperatorBitwiseRhsType( const genType_t type, const uint32_t numRows, const uint32_t numCols, const genOpBitwise_t op ) {
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

static std::string InlGetOperatorBitwiseRhsType( const genType_t type, const uint32_t numRows, const uint32_t numCols, const genOpBitwise_t op ) {
	uint32_t numComponents = ( numRows == 1 ) ? numCols : numRows;

	std::string fullTypeName = Gen_GetFullTypeName( type, numRows, numCols );

	std::string opStr = GEN_OPERATORS_BITWISE[op];

	std::string code;

	// main bitwise operator
	code += fullTypeName + " operator" + opStr + "( const " + fullTypeName + "& lhs, const " + fullTypeName + "& rhs )\n";
	code += "{\n";
	code += "\treturn " + fullTypeName + "(\n";
	for ( uint32_t i = 0; i < numComponents; i++ ) {
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


void Gen_OperatorsIncrement( const genType_t type, const uint32_t numRows, const uint32_t numCols, std::string& outHeader, std::string& outInl ) {
	assert( numRows >= 1 );	// pass through 1 for vectors
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );

	if ( type == GEN_TYPE_BOOL ) {
		return;
	}

	for ( uint32_t opIndex = 0; opIndex < GEN_OP_INCREMENT_COUNT; opIndex++ ) {
		genOpIncrement_t op = static_cast<genOpIncrement_t>( opIndex );

		outHeader += HeaderGetOperatorIncrement( type, numRows, numCols, op );

		outInl += InlGetOperatorIncrement( type, numRows, numCols, op );
	}
}

void Gen_OperatorsRelational( const genType_t type, const uint32_t numRows, const uint32_t numCols, std::string& outHeader, std::string& outInl ) {
	assert( numRows >= 1 );	// pass through 1 for vectors
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

void Gen_OperatorsBitwise( const genType_t type, const uint32_t numRows, const uint32_t numCols, std::string& outHeader, std::string& outInl ) {
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
	uint32_t numComponents = ( numRows == 1 ) ? numCols : numRows;
	std::string fullTypeName = Gen_GetFullTypeName( type, numRows, numCols );

	outHeader += Gen_GetDocOperatorBitwiseUnary( fullTypeName );
	outHeader += "inline " + fullTypeName + " operator~( const " + fullTypeName + "& lhs );\n";
	outHeader += "\n";

	outInl += fullTypeName + " operator~( const " + fullTypeName + "& lhs )\n";
	outInl += "{\n";
	outInl += "\treturn " + fullTypeName + "(\n";
	for ( uint32_t i = 0; i < numComponents; i++ ) {
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

void Gen_OperatorComponentWiseArithmeticScalar( const genType_t type, const uint32_t numRows, const uint32_t numCols, const genOpArithmetic_t op, std::string& outHeader, std::string& outInl ) {
	assert( numRows >= 1 );	// pass through 1 for vectors
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );

	if ( type == GEN_TYPE_BOOL ) {
		return;
	}

	uint32_t numComponents = ( numRows == 1 ) ? numCols : numRows;

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
	for ( uint32_t i = 0; i < numComponents; i++ ) {
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

void Gen_OperatorComponentWiseArithmeticRhsType( const genType_t type, const uint32_t numRows, const uint32_t numCols, const genOpArithmetic_t op, std::string& outHeader, std::string& outInl ) {
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

	uint32_t numComponents = ( numRows == 1 ) ? numCols : numRows;

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
	for ( uint32_t i = 0; i < numComponents; i++ ) {
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

void Gen_OperatorNotEquals( const genType_t type, const uint32_t numRows, const uint32_t numCols, std::string& outHeader, std::string& outInl ) {
	assert( numRows >= 1 );	// pass through 1 for vectors
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );

	std::string fullTypeName = Gen_GetFullTypeName( type, numRows, numCols );

	outHeader += Gen_GetDocOperatorNotEquals( fullTypeName );
	outHeader += "inline bool operator!=( const " + fullTypeName + "& lhs, const " + fullTypeName + "& rhs );\n";
	outHeader += "\n";

	outInl += "bool operator!=( const " + fullTypeName + "& lhs, const " + fullTypeName + "& rhs ) {\n";
	outInl += "\treturn !( operator==( lhs, rhs ) );\n";
	outInl += "}\n";
	outInl += "\n";
}
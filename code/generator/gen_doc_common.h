#pragma once

#include <string>

#include <assert.h>

inline std::string	Gen_GetDocOperatorEquals( const std::string& fullTypeName );
inline std::string	Gen_GetDocOperatorNotEquals( const std::string& fullTypeName );

inline std::string	Gen_GetDocOperatorArithmeticScalar( const std::string& fullTypeName, const genOpArithmetic_t op );
inline std::string	Gen_GetDocOperatorCompoundArithmeticScalar( const std::string& fullTypeName, const genOpArithmetic_t op );

inline std::string	Gen_GetDocOperatorRelational( const std::string& fullTypeName, const uint32_t numRows, const uint32_t numCols, const genOpRelational_t op );


std::string Gen_GetDocOperatorEquals( const std::string& fullTypeName ) {
	return "/// \\relates " + fullTypeName + "\n" \
		"/// \\brief Returns true if the all the components of the left-hand-side " + fullTypeName + " match the other one, otherwise returns false.\n";
}

std::string Gen_GetDocOperatorNotEquals( const std::string& fullTypeName ) {
	return "/// \\relates " + fullTypeName + "\n" \
		"/// \\brief Returns true if not all of the components of the left-hand-side " + fullTypeName + " match the other one, otherwise returns false.\n";
}

std::string Gen_GetDocOperatorArithmeticScalar( const std::string& fullTypeName, const genOpArithmetic_t op ) {
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
		"/// \\brief Returns a copy that has been component-wise " + adjective + " by the given scalar value.\n";
}

std::string Gen_GetDocOperatorCompoundArithmeticScalar( const std::string& fullTypeName, const genOpArithmetic_t op ) {
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
		"/// \\brief " + verb + " each component by the given scalar value.\n";
}

std::string Gen_GetDocOperatorRelational( const std::string& fullTypeName, const uint32_t numRows, const uint32_t numCols, const genOpRelational_t op ) {
	assert( numRows >= 1 );	// pass through 1 for vectors
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );

	std::string noun;
	switch ( op ) {
		case GEN_OP_RELATIONAL_LESS: noun = "less than"; break;
		case GEN_OP_RELATIONAL_LESS_EQUAL: noun = "less than or equal to"; break;
		case GEN_OP_RELATIONAL_GREATER: noun = "greater than"; break;
		case GEN_OP_RELATIONAL_GREATER_EQUAL: noun = "greater than or equal to"; break;

		case GEN_OP_RELATIONAL_COUNT:
		default:
			printf( "ERROR: Bad genOpRelational_t enum passed into %s.\n", __FUNCTION__ );
			return std::string();
	}

	std::string boolTypeName;
	if ( numRows > 1 ) {
		boolTypeName = "bool" + std::to_string( numRows ) + "x" + std::to_string( numCols );
	} else {
		boolTypeName = "bool" + std::to_string( numCols );
	}

	return "/// \\relates " + fullTypeName + "\n" \
		+ "/// \\brief Returns a " + boolTypeName \
		+ " where each component is true if the component of the left-hand type is " + noun + " the corresponding right-hand type component.\n";
}
#pragma once

#include <string>

#include <assert.h>

inline std::string	Gen_GetDocOperatorEquals( const std::string& fullTypeName );
inline std::string	Gen_GetDocOperatorNotEquals( const std::string& fullTypeName );

inline std::string	Gen_GetDocOperatorArithmeticScalar( const std::string& fullTypeName, const genOpArithmetic_t op );
inline std::string	Gen_GetDocOperatorCompoundArithmeticScalar( const std::string& fullTypeName, const genOpArithmetic_t op );

inline std::string	Gen_GetDocOperatorComponentWiseArithmeticRhsType( const std::string& fullTypeName, const genOpArithmetic_t op );
inline std::string	Gen_GetDocOperatorCompoundComponentWiseArithmeticRhsType( const std::string& fullTypeName, const genOpArithmetic_t op );

inline std::string	Gen_GetDocOperatorIncrementPrefix( const std::string& fullTypeName, const genOpIncrement_t op );
inline std::string	Gen_GetDocOperatorIncrementPostfix( const std::string& fullTypeName, const genOpIncrement_t op );

inline std::string	Gen_GetDocOperatorRelational( const std::string& fullTypeName, const uint32_t numRows, const uint32_t numCols, const genOpRelational_t op );

inline std::string	Gen_GetDocOperatorBitwiseScalar( const std::string& fullTypeName, const genOpBitwise_t op );
inline std::string	Gen_GetDocOperatorBitwiseRhsType( const std::string& fullTypeName, const genOpBitwise_t op );
inline std::string	Gen_GetDocOperatorCompoundBitwiseScalar( const std::string& fullTypeName, const genOpBitwise_t op );
inline std::string	Gen_GetDocOperatorCompoundBitwiseRhsType( const std::string& fullTypeName, const genOpBitwise_t op );

inline std::string	Gen_GetDocOperatorBitwiseUnary( const std::string& fullTypeName );


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
		case GEN_OP_ARITHMETIC_ADD:	adjective = "added";		break;
		case GEN_OP_ARITHMETIC_SUB:	adjective = "subtracted";	break;
		case GEN_OP_ARITHMETIC_MUL:	adjective = "multiplied";	break;
		case GEN_OP_ARITHMETIC_DIV:	adjective = "divided";		break;

		case GEN_OP_ARITHMETIC_COUNT:
		default:
			printf( "ERROR: Bad genOpArithmetic_t enum passed into %s.\n", __FUNCTION__ );
			return std::string();
	}

	return "/// \\relates " + fullTypeName + "\n" \
		"/// \\brief Returns a copy of the " + fullTypeName + " that has been component-wise " + adjective + " by the given scalar value.\n";
}

std::string Gen_GetDocOperatorCompoundArithmeticScalar( const std::string& fullTypeName, const genOpArithmetic_t op ) {
	std::string verb;
	switch ( op ) {
		case GEN_OP_ARITHMETIC_ADD:	verb = "Adds";			break;
		case GEN_OP_ARITHMETIC_SUB:	verb = "Subtracts";		break;
		case GEN_OP_ARITHMETIC_MUL:	verb = "Multiplies";	break;
		case GEN_OP_ARITHMETIC_DIV:	verb = "Divides";		break;

		case GEN_OP_ARITHMETIC_COUNT:
		default:
			printf( "ERROR: Bad genOpArithmetic_t enum passed into %s.\n", __FUNCTION__ );
			return std::string();
	}

	return "/// \\relates " + fullTypeName + "\n" \
		"/// \\brief " + verb + " each component by the given scalar value.\n";
}

std::string Gen_GetDocOperatorComponentWiseArithmeticRhsType( const std::string& fullTypeName, const genOpArithmetic_t op ) {
	std::string adjective;
	switch ( op ) {
		case GEN_OP_ARITHMETIC_ADD:	adjective = "added";		break;
		case GEN_OP_ARITHMETIC_SUB:	adjective = "subtracted";	break;
		case GEN_OP_ARITHMETIC_MUL:	adjective = "multiplied";	break;
		case GEN_OP_ARITHMETIC_DIV:	adjective = "divided";		break;

		case GEN_OP_ARITHMETIC_COUNT:
		default:
			printf( "ERROR: Bad genOpArithmetic_t enum passed into %s.\n", __FUNCTION__ );
			return std::string();
	}

	return "/// \\relates " + fullTypeName + "\n" \
		+ "/// \\brief Returns a copy of the " + fullTypeName + " that has been component-wise " + adjective + " by the corresponding component of the right-hand " \
		+ fullTypeName + ".\n";
}

std::string Gen_GetDocOperatorCompoundComponentWiseArithmeticRhsType( const std::string& fullTypeName, const genOpArithmetic_t op ) {
	std::string verb;
	switch ( op ) {
		case GEN_OP_ARITHMETIC_ADD:	verb = "Adds";			break;
		case GEN_OP_ARITHMETIC_SUB:	verb = "Subtracts";		break;
		case GEN_OP_ARITHMETIC_MUL:	verb = "Multiplies";	break;
		case GEN_OP_ARITHMETIC_DIV:	verb = "Divides";		break;

		case GEN_OP_ARITHMETIC_COUNT:
		default:
			printf( "ERROR: Bad genOpArithmetic_t enum passed into %s.\n", __FUNCTION__ );
			return std::string();
	}

	return "/// \\relates " + fullTypeName + "\n" \
		"/// \\brief " + verb + " each component of the " + fullTypeName + " by the corresponding component of the right-hand " + fullTypeName + ".\n";
}

std::string Gen_GetDocOperatorIncrementPrefix( const std::string& fullTypeName, const genOpIncrement_t op ) {
	std::string verb;
	std::string noun;
	switch ( op ) {
		case GEN_OP_INCREMENT_INCREMENT:
			noun = "increment";
			verb = "Adds one to";
			break;

		case GEN_OP_INCREMENT_DECREMENT:
			noun = "decrement";
			verb = "Subtracts one from";
			break;

		case GEN_OP_INCREMENT_COUNT:
		default:
			printf( "ERROR: Bad genOpIncrement_t enum passed into %s.\n", __FUNCTION__ );
			break;
	}

	return "/// \\relates " + fullTypeName + "\n" \
		"/// \\brief Prefix " + noun + " operator.  " + verb + " each component of the given " + fullTypeName + " before evaluation.\n";
}

std::string Gen_GetDocOperatorIncrementPostfix( const std::string& fullTypeName, const genOpIncrement_t op ) {
	std::string verb;
	std::string noun;
	switch ( op ) {
		case GEN_OP_INCREMENT_INCREMENT:
			noun = "increment";
			verb = "Adds one to";
			break;

		case GEN_OP_INCREMENT_DECREMENT:
			noun = "decrement";
			verb = "Subtracts one from";
			break;

		case GEN_OP_INCREMENT_COUNT:
		default:
			printf( "ERROR: Bad genOpIncrement_t enum passed into %s.\n", __FUNCTION__ );
			break;
	}

	return "/// \\relates " + fullTypeName + "\n" \
		"/// \\brief Postfix " + noun + " operator.  " + verb + " each component of the given " + fullTypeName + " after evaluation.\n";
}

std::string Gen_GetDocOperatorRelational( const std::string& fullTypeName, const uint32_t numRows, const uint32_t numCols, const genOpRelational_t op ) {
	assert( numRows >= 1 );	// pass through 1 for vectors
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );

	std::string noun;
	switch ( op ) {
		case GEN_OP_RELATIONAL_LESS:			noun = "less than";					break;
		case GEN_OP_RELATIONAL_LESS_EQUAL:		noun = "less than or equal to";		break;
		case GEN_OP_RELATIONAL_GREATER:			noun = "greater than";				break;
		case GEN_OP_RELATIONAL_GREATER_EQUAL:	noun = "greater than or equal to";	break;

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

std::string Gen_GetDocOperatorBitwiseScalar( const std::string& fullTypeName, const genOpBitwise_t op ) {
	std::string adjective;
	std::string preposition;
	switch ( op ) {
		case GEN_OP_BITWISE_AND:
			adjective = "bitwise AND'd";
			preposition = "against";
			break;

		case GEN_OP_BITWISE_OR:
			adjective = "bitwise OR'd";
			preposition = "against";
			break;

		case GEN_OP_BITWISE_XOR:
			adjective = "bitwise XOR'd";
			preposition = "against";
			break;

		case GEN_OP_BITWISE_UNARY:
			printf( "ERROR: For bitwise unary documentation, call Gen_GetDocOperatorBitwiseUnary().\n" );
			return std::string();

		case GEN_OP_BITWISE_SHIFT_LEFT:
			adjective = "bitwise left-shifted";
			preposition = "by";
			break;

		case GEN_OP_BITWISE_SHIFT_RIGHT:
			adjective = "bitwise right-shifted";
			preposition = "by";
			break;

		case GEN_OP_BITWISE_COUNT:
		default:
			printf( "ERROR: Bad genOpArithmetic_t enum passed into %s.\n", __FUNCTION__ );
			return std::string();
	}

	return "/// \\relates " + fullTypeName + "\n" \
		 + "/// \\brief Returns a copy of the " + fullTypeName + " where each component has been " + adjective + " " + preposition + " the given scalar value.\n";
}

std::string Gen_GetDocOperatorBitwiseRhsType( const std::string& fullTypeName, const genOpBitwise_t op ) {
	std::string adjective;
	std::string preposition;
	switch ( op ) {
		case GEN_OP_BITWISE_AND:
			adjective = "bitwise AND'd";
			preposition = "against";
			break;

		case GEN_OP_BITWISE_OR:
			adjective = "bitwise OR'd";
			preposition = "against";
			break;

		case GEN_OP_BITWISE_XOR:
			adjective = "bitwise XOR'd";
			preposition = "against";
			break;

		case GEN_OP_BITWISE_UNARY:
			printf( "ERROR: For bitwise unary documentation, call Gen_GetDocOperatorBitwiseUnary().\n" );
			return std::string();

		case GEN_OP_BITWISE_SHIFT_LEFT:
			adjective = "bitwise left-shifted";
			preposition = "by";
			break;

		case GEN_OP_BITWISE_SHIFT_RIGHT:
			adjective = "bitwise right-shifted";
			preposition = "by";
			break;

		case GEN_OP_BITWISE_COUNT:
		default:
			printf( "ERROR: Bad genOpArithmetic_t enum passed into %s.\n", __FUNCTION__ );
			return std::string();
	}

	return "/// \\relates " + fullTypeName + "\n" \
		+ "/// \\brief Returns a copy of the " + fullTypeName + " where each component of the left-hand " + fullTypeName + \
		+ " has been " + adjective + " " + preposition + " the corresponding component of the right-hand side " + fullTypeName + ".\n";
}

std::string Gen_GetDocOperatorCompoundBitwiseScalar( const std::string& fullTypeName, const genOpBitwise_t op ) {
	std::string opDesc;
	std::string preposition;
	switch ( op ) {
		case GEN_OP_BITWISE_AND:
			opDesc = "bitwise AND";
			preposition = "against";
			break;

		case GEN_OP_BITWISE_OR:
			opDesc = "bitwise OR";
			preposition = "against";
			break;

		case GEN_OP_BITWISE_XOR:
			opDesc = "bitwise XOR";
			preposition = "against";
			break;

		case GEN_OP_BITWISE_UNARY:
			printf( "ERROR: For bitwise unary documentation, call Gen_GetDocOperatorBitwiseUnary().\n" );
			return std::string();

		case GEN_OP_BITWISE_SHIFT_LEFT:
			opDesc = "left bitshift";
			preposition = "by";
			break;

		case GEN_OP_BITWISE_SHIFT_RIGHT:
			opDesc = "right bitshift";
			preposition = "by";
			break;

		case GEN_OP_BITWISE_COUNT:
		default:
			printf( "ERROR: Bad genOpArithmetic_t enum passed into %s.\n", __FUNCTION__ );
			return std::string();
	}

	return "/// \\relates " + fullTypeName + "\n" \
		"/// \\brief Performs a " + opDesc + " on the given left-hand " + fullTypeName + " " + preposition + " the given scalar value.\n";
}

std::string Gen_GetDocOperatorCompoundBitwiseRhsType( const std::string& fullTypeName, const genOpBitwise_t op ) {
	std::string opDesc;
	std::string preposition;
	switch ( op ) {
		case GEN_OP_BITWISE_AND:
			opDesc = "bitwise AND";
			preposition = "against";
			break;

		case GEN_OP_BITWISE_OR:
			opDesc = "bitwise OR";
			preposition = "against";
			break;

		case GEN_OP_BITWISE_XOR:
			opDesc = "bitwise XOR";
			preposition = "against";
			break;

		case GEN_OP_BITWISE_UNARY:
			printf( "ERROR: For bitwise unary documentation, call Gen_GetDocOperatorBitwiseUnary().\n" );
			return std::string();

		case GEN_OP_BITWISE_SHIFT_LEFT:
			opDesc = "left bitshift";
			preposition = "by";
			break;

		case GEN_OP_BITWISE_SHIFT_RIGHT:
			opDesc = "right bitshift";
			preposition = "by";
			break;

		case GEN_OP_BITWISE_COUNT:
		default:
			printf( "ERROR: Bad genOpArithmetic_t enum passed into %s.\n", __FUNCTION__ );
			return std::string();
	}

	return "/// \\relates " + fullTypeName + "\n" \
		"/// \\brief Performs a " + opDesc + " on the given left-hand " + fullTypeName + " " + preposition + \
		" the corresponding component of the given right-hand " + fullTypeName + ".\n";
}

std::string Gen_GetDocOperatorBitwiseUnary( const std::string& fullTypeName ) {
	return "/// \\relates " + fullTypeName + "\n" \
		"/// \\brief Performs a unary bitwise operation on all components of the given " + fullTypeName + ".\n";
}
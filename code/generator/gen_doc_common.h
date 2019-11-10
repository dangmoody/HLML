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
#pragma once

#include "string_builder.h"

inline void Doc_Floateq( stringBuilder_t* sb ) {
	String_Append( sb,
		"/// \\brief Returns true if the two given floating-point numbers are within a small enough epsilon range of each other that takes into account floating-point inaccuracy.\n"
	);
}

inline void Doc_Sign( stringBuilder_t* sb ) {
	String_Append( sb,
		"/// \\brief Returns -1 if x is < 0, 0 if x == 0, or 1 if x > 1.\n"
		"/// This function does no branching.\n"
	);
}

inline void Doc_Radians( stringBuilder_t* sb ) {
	String_Append( sb, "/// \\brief Returns the given degrees to radians.\n" );
}

inline void Doc_Degrees( stringBuilder_t* sb ) {
	String_Append( sb, "/// \\brief Returns the given radians to degrees.\n" );
}

inline void Doc_Min( stringBuilder_t* sb ) {
	String_Append( sb, "/// \\brief Returns x if its smaller than y, otherwise returns y.\n" );
}

inline void Doc_Max( stringBuilder_t* sb ) {
	String_Append( sb, "/// \\brief Returns x if its bigger than y, otherwise returns y.\n" );
}

inline void Doc_Clamp( stringBuilder_t* sb ) {
	String_Append( sb, "/// \\brief If x is lower than low or higher than high then returns low or high respectively, otherwise returns x.\n" );
}

inline void Doc_Saturate( stringBuilder_t* sb, const char* fullTypeName ) {
	String_Appendf( sb,
		"/// \\relates %s\n"
		"/// \\brief Returns a copy of the %s with each component clamped between the range 0 and 1.\n", fullTypeName, fullTypeName
	);
}

inline void Doc_Lerp( stringBuilder_t* sb, const char* fullTypeName ) {
	String_Appendf( sb,
		"/// \\relates %s\n"
		"/// \\brief Returns a linearly interpolated %s between types \"a\" and \"b\".\n", fullTypeName, fullTypeName
	);
}

inline void Doc_Step( stringBuilder_t* sb, const char* fullTypeName ) {
	String_Appendf( sb,
		"/// \\relates %s\n"
		"/// \\brief Returns 1 if y is greater than x, otherwise returns 0.\n", fullTypeName
	);
}

inline void Doc_Smoothstep( stringBuilder_t* sb, const char* fullTypeName ) {
	String_Appendf( sb,
		"/// \\relates %s\n"
		"/// \\brief Performs a sigmoid-like interpolation and clamp.\n", fullTypeName
	);
}

inline void Doc_Smootherstep( stringBuilder_t* sb, const char* fullTypeName ) {
	String_Appendf( sb,
		"/// \\relates %s\n"
		"/// \\brief Performs a 'smoother' version of smoothstep, as design by Ken Perlin.\n"
		"/// https://en.wikipedia.org/wiki/Smoothstep#Variations\n", fullTypeName
	);
}

inline void Doc_OperatorEquals( stringBuilder_t* sb, const char* fullTypeName ) {
	String_Appendf( sb,
		"/// \\relates %s\n"
		"/// \\brief Returns true if the all the components of the left-hand-side %s match the other one, "
		"otherwise returns false.\n", fullTypeName, fullTypeName
	);
}

inline void Doc_OperatorNotEquals( stringBuilder_t* sb, const char* fullTypeName ) {
	String_Appendf( sb,
		"/// \\relates %s\n"
		"/// \\brief Returns true if not all of the components of the left-hand-side %s match the other one, "
		"otherwise returns false.\n", fullTypeName, fullTypeName
	);
}

inline void Doc_ComponentWiseArithmeticScalar( stringBuilder_t* sb, const char* fullTypeName, const genOpArithmetic_t op ) {
	const char* adjective;
	switch ( op ) {
		case GEN_OP_ARITHMETIC_ADD:	adjective = "added";		break;
		case GEN_OP_ARITHMETIC_SUB:	adjective = "subtracted";	break;
		case GEN_OP_ARITHMETIC_MUL:	adjective = "multiplied";	break;
		case GEN_OP_ARITHMETIC_DIV:	adjective = "divided";		break;

		case GEN_OP_ARITHMETIC_COUNT:
		default:
			printf( "ERROR: Bad genOpArithmetic_t enum passed into %s.\n", __FUNCTION__ );
			return;
	}

	String_Appendf( sb,
		"/// \\relates %s\n"
		"/// \\brief Returns a copy of the %s that has been component-wise %s by the given scalar value.\n", fullTypeName, fullTypeName, adjective
	);
}

inline void Doc_OperatorCompoundArithmeticScalar( stringBuilder_t* sb, const char* fullTypeName, const genOpArithmetic_t op ) {
	const char* verb;
	switch ( op ) {
		case GEN_OP_ARITHMETIC_ADD:	verb = "Adds";			break;
		case GEN_OP_ARITHMETIC_SUB:	verb = "Subtracts";		break;
		case GEN_OP_ARITHMETIC_MUL:	verb = "Multiplies";	break;
		case GEN_OP_ARITHMETIC_DIV:	verb = "Divides";		break;

		case GEN_OP_ARITHMETIC_COUNT:
		default:
			printf( "ERROR: Bad genOpArithmetic_t enum passed into %s.\n", __FUNCTION__ );
			return;
	}

	String_Appendf( sb,
		"/// \\relates %s\n"
		"/// \\brief %s each component by the given scalar value.\n", fullTypeName, verb
	);
}

inline void Doc_ComponentWiseArithmeticRhsType( stringBuilder_t* sb, const char* lhsTypeName, const char* rhsTypeName, const genOpArithmetic_t op ) {
	const char* adjective;
	switch ( op ) {
		case GEN_OP_ARITHMETIC_ADD:	adjective = "added";		break;
		case GEN_OP_ARITHMETIC_SUB:	adjective = "subtracted";	break;
		case GEN_OP_ARITHMETIC_MUL:	adjective = "multiplied";	break;
		case GEN_OP_ARITHMETIC_DIV:	adjective = "divided";		break;

		case GEN_OP_ARITHMETIC_COUNT:
		default:
			printf( "ERROR: Bad genOpArithmetic_t enum passed into %s.\n", __FUNCTION__ );
			return;
	}

	String_Appendf( sb,
		"/// \\relates %s\n"
		"/// \\brief Returns a copy of the %s that has been component-wise %s by the corresponding component of the right-hand %s.\n",
		lhsTypeName, lhsTypeName, adjective, rhsTypeName
	);
}

inline void Doc_OperatorCompoundComponentWiseArithmeticRhsType( stringBuilder_t* sb, const char* lhsTypeName, const char* rhsTypeName, const genOpArithmetic_t op ) {
	const char* verb;
	switch ( op ) {
		case GEN_OP_ARITHMETIC_ADD:	verb = "Adds";			break;
		case GEN_OP_ARITHMETIC_SUB:	verb = "Subtracts";		break;
		case GEN_OP_ARITHMETIC_MUL:	verb = "Multiplies";	break;
		case GEN_OP_ARITHMETIC_DIV:	verb = "Divides";		break;

		case GEN_OP_ARITHMETIC_COUNT:
		default:
			printf( "ERROR: Bad genOpArithmetic_t enum passed into %s.\n", __FUNCTION__ );
			return;
	}

	String_Appendf( sb,
		"/// \\relates %s\n"
		"/// \\brief %s each component of the %s by the corresponding component of the right-hand %s.\n", lhsTypeName, verb, lhsTypeName, rhsTypeName
	);
}

inline void Doc_OperatorIncrementPrefix( stringBuilder_t* sb, const char* fullTypeName, const genOpIncrement_t op ) {
	const char* verb;
	const char* noun;
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
			return;
	}

	String_Appendf( sb,
		"/// \\relates %s\n"
		"/// \\brief Prefix %s operator.  %s each component of the given %s before evaluation.\n", fullTypeName, noun, verb, fullTypeName
	);
}

inline void Doc_OperatorIncrementPostfix( stringBuilder_t* sb, const char* fullTypeName, const genOpIncrement_t op ) {
	const char* verb;
	const char* noun;
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
			return;
	}

	String_Appendf( sb,
		"/// \\relates %s\n"
		"/// \\brief Postfix %s operator.  %s each component of the given %s after evaluation.\n", fullTypeName, noun, verb, fullTypeName
	);
}

inline void Doc_ComponentWiseRelational( stringBuilder_t* sb, const char* fullTypeName, const u32 numRows, const u32 numCols, const genOpRelational_t op ) {
	assert( numRows >= 1 );	// pass through 1 for vectors
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );

	const char* noun;
	switch ( op ) {
		case GEN_OP_RELATIONAL_LESS:			noun = "less than";					break;
		case GEN_OP_RELATIONAL_LESS_EQUAL:		noun = "less than or equal to";		break;
		case GEN_OP_RELATIONAL_GREATER:			noun = "greater than";				break;
		case GEN_OP_RELATIONAL_GREATER_EQUAL:	noun = "greater than or equal to";	break;

		case GEN_OP_RELATIONAL_COUNT:
		default:
			printf( "ERROR: Bad genOpRelational_t enum passed into %s.\n", __FUNCTION__ );
			return;
	}

	char boolTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetFullTypeName( GEN_TYPE_BOOL, numRows, numCols, boolTypeName );

	String_Appendf( sb,
		"/// \\relates %s\n"
		"/// \\brief Returns a %s "
		"where each component is true if the component of the left-hand type is %s the corresponding right-hand type component.\n", fullTypeName, boolTypeName, noun
	);
}

inline void Doc_OperatorBitwiseRhsType( stringBuilder_t* sb, const char* fullTypeName, const genOpBitwise_t op ) {
	const char* adjective;
	const char* preposition;
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
			printf( "ERROR: For bitwise unary documentation, call Doc_OperatorBitwiseUnary().\n" );
			return;

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
			return;
	}

	String_Appendf( sb,
		"/// \\relates %s\n"
		"/// \\brief Returns a copy of the %s where each component of the left-hand %s"
		" has been %s %s the corresponding component of the right-hand side %s.\n", fullTypeName, fullTypeName, fullTypeName, adjective, preposition, fullTypeName
	);
}

inline void Doc_OperatorCompoundBitwiseScalar( stringBuilder_t* sb, const char* fullTypeName, const genOpBitwise_t op ) {
	const char* opDesc;
	const char* preposition;
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
			printf( "ERROR: For bitwise unary documentation, call Doc_OperatorBitwiseUnary().\n" );
			return;

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
			return;
	}

	String_Appendf( sb,
		"/// \\relates %s\n"
		"/// \\brief Performs a %s on the given left-hand %s %s the given scalar value.\n", fullTypeName, opDesc, fullTypeName, preposition
	);
}

inline void Doc_OperatorCompoundBitwiseRhsType( stringBuilder_t* sb, const char* fullTypeName, const genOpBitwise_t op ) {
	const char* opDesc;
	const char* preposition;
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
			printf( "ERROR: For bitwise unary documentation, call Doc_OperatorBitwiseUnary().\n" );
			return;

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
			return;
	}

	String_Appendf( sb,
		"/// \\relates %s\n"
		"/// \\brief Performs a %s on the given left-hand %s %s "
		"the corresponding component of the given right-hand %s.\n", fullTypeName, opDesc, fullTypeName, preposition, fullTypeName
	);
}

inline void Doc_OperatorBitwiseUnary( stringBuilder_t* sb, const char* fullTypeName ) {
	String_Appendf( sb,
		"/// \\relates %s\n"
		"/// \\brief Performs a unary bitwise operation on all components of the given %s.\n", fullTypeName, fullTypeName
	);
}

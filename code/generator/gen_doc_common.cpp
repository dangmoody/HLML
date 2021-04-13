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
#include "gen_doc_common.h"

#include "gen_common.h"

#include "string_builder.h"

#include <string.h>
#include <assert.h>

void Doc_Vector( stringBuilder_t* codeHeader, const genLanguage_t language, const u32 numComponents, const char* memberTypeString ) {
	assert( codeHeader );
	assert( numComponents >= GEN_COMPONENT_COUNT_MIN );
	assert( numComponents <= GEN_COMPONENT_COUNT_MAX );
	assert( memberTypeString );

	char componentsStr[GEN_COMPONENT_COUNT_MAX + 1];
	strncpy( componentsStr, GEN_COMPONENT_NAMES_VECTOR, numComponents );
	componentsStr[numComponents] = 0;

	String_Appendf( codeHeader, "/// \\brief A vector of %d %ss with components %s.\n", numComponents, memberTypeString, componentsStr );
	if ( language == GEN_LANGUAGE_CPP ) {
		String_Append( codeHeader, "/// Components are also stored as elements in an array via a union.\n" );
	}
}

void Doc_Matrix( stringBuilder_t* codeHeader, const u32 numRows, const char* vectorMemberTypeString ) {
	assert( codeHeader );
	assert( numRows >= GEN_COMPONENT_COUNT_MIN );
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( vectorMemberTypeString );

	String_Appendf( codeHeader, "/// A matrix of %d %ss.\n", numRows, vectorMemberTypeString );
}

void Doc_Floateq( stringBuilder_t* sb ) {
	assert( sb );

	String_Append( sb,
		"/// \\brief Returns true if the two given floating-point numbers are within a small enough epsilon range of each other that takes into account floating-point inaccuracy.\n"
	);
}

void Doc_Sign( stringBuilder_t* sb ) {
	assert( sb );

	String_Append( sb,
		"/// \\brief Returns -1 if x is < 0, 0 if x == 0, or 1 if x > 1.\n"
		"/// This function does no branching.\n"
	);
}

void Doc_Radians( stringBuilder_t* sb ) {
	assert( sb );

	String_Append( sb, "/// \\brief Returns the given degrees to radians.\n" );
}

void Doc_Degrees( stringBuilder_t* sb ) {
	assert( sb );

	String_Append( sb, "/// \\brief Returns the given radians to degrees.\n" );
}

void Doc_Min( stringBuilder_t* sb ) {
	assert( sb );

	String_Append( sb, "/// \\brief Returns x if its smaller than y, otherwise returns y.\n" );
}

void Doc_Max( stringBuilder_t* sb ) {
	assert( sb );

	String_Append( sb, "/// \\brief Returns x if its bigger than y, otherwise returns y.\n" );
}

void Doc_Clamp( stringBuilder_t* sb ) {
	assert( sb );

	String_Append( sb, "/// \\brief If x is lower than low or higher than high then returns low or high respectively, otherwise returns x.\n" );
}

void Doc_Saturate( stringBuilder_t* sb, const char* fullTypeName ) {
	assert( sb );
	assert( fullTypeName );

	String_Appendf( sb,
		"/// \\relates %s\n"
		"/// \\brief Returns a copy of the %s with each component clamped between the range 0 and 1.\n", fullTypeName, fullTypeName
	);
}

void Doc_Lerp( stringBuilder_t* sb, const char* fullTypeName ) {
	assert( sb );
	assert( fullTypeName );

	String_Appendf( sb,
		"/// \\relates %s\n"
		"/// \\brief Returns a linearly interpolated %s between types \"a\" and \"b\".\n", fullTypeName, fullTypeName
	);
}

void Doc_Step( stringBuilder_t* sb, const char* fullTypeName ) {
	assert( sb );
	assert( fullTypeName );

	String_Appendf( sb,
		"/// \\relates %s\n"
		"/// \\brief Returns 1 if y is greater than x, otherwise returns 0.\n", fullTypeName
	);
}

void Doc_Smoothstep( stringBuilder_t* sb, const char* fullTypeName ) {
	assert( sb );
	assert( fullTypeName );

	String_Appendf( sb,
		"/// \\relates %s\n"
		"/// \\brief Performs a sigmoid-like interpolation and clamp.\n", fullTypeName
	);
}

void Doc_Smootherstep( stringBuilder_t* sb, const char* fullTypeName ) {
	assert( sb );
	assert( fullTypeName );

	String_Appendf( sb,
		"/// \\relates %s\n"
		"/// \\brief Performs a 'smoother' version of smoothstep, as design by Ken Perlin.\n"
		"/// https://en.wikipedia.org/wiki/Smoothstep#Variations\n", fullTypeName
	);
}

void Doc_FunctionAll( stringBuilder_t* sb, const char* fullTypeName ) {
	assert( sb );
	assert( fullTypeName );

	String_Appendf( sb,
		"/// \\relates %s\n"
		"/// \\brief Returns true if all components of the %s are true, otherwise returns false.\n", fullTypeName, fullTypeName
	);
}

void Doc_OperatorEquals( stringBuilder_t* sb, const char* fullTypeName ) {
	assert( sb );
	assert( fullTypeName );

	String_Appendf( sb,
		"/// \\relates %s\n"
		"/// \\brief Returns true if the all the components of the left-hand-side %s match the other one, "
		"otherwise returns false.\n", fullTypeName, fullTypeName
	);
}

void Doc_OperatorNotEquals( stringBuilder_t* sb, const char* fullTypeName ) {
	assert( sb );
	assert( fullTypeName );

	String_Appendf( sb,
		"/// \\relates %s\n"
		"/// \\brief Returns true if not all of the components of the left-hand-side %s match the other one, "
		"otherwise returns false.\n", fullTypeName, fullTypeName
	);
}

void Doc_ComponentWiseArithmeticScalar( stringBuilder_t* sb, const char* fullTypeName, const genOpArithmetic_t op ) {
	assert( sb );
	assert( fullTypeName );
	assert( op >= GEN_OP_ARITHMETIC_ADD && op < GEN_OP_ARITHMETIC_COUNT );

	const char* adjective = NULL;

	switch ( op ) {
		case GEN_OP_ARITHMETIC_ADD:	adjective = "added";		break;
		case GEN_OP_ARITHMETIC_SUB:	adjective = "subtracted";	break;
		case GEN_OP_ARITHMETIC_MUL:	adjective = "multiplied";	break;
		case GEN_OP_ARITHMETIC_DIV:	adjective = "divided";		break;

		case GEN_OP_ARITHMETIC_COUNT:
			return;
	}

	String_Appendf( sb,
		"/// \\relates %s\n"
		"/// \\brief Returns a copy of the %s that has been component-wise %s by the given scalar value.\n", fullTypeName, fullTypeName, adjective
	);
}

void Doc_OperatorCompoundArithmeticScalar( stringBuilder_t* sb, const char* fullTypeName, const genOpArithmetic_t op ) {
	assert( sb );
	assert( fullTypeName );
	assert( op >= GEN_OP_ARITHMETIC_ADD && op < GEN_OP_ARITHMETIC_COUNT );

	const char* verb = NULL;

	switch ( op ) {
		case GEN_OP_ARITHMETIC_ADD:	verb = "Adds";			break;
		case GEN_OP_ARITHMETIC_SUB:	verb = "Subtracts";		break;
		case GEN_OP_ARITHMETIC_MUL:	verb = "Multiplies";	break;
		case GEN_OP_ARITHMETIC_DIV:	verb = "Divides";		break;

		case GEN_OP_ARITHMETIC_COUNT:
			return;
	}

	String_Appendf( sb,
		"/// \\relates %s\n"
		"/// \\brief %s each component by the given scalar value.\n", fullTypeName, verb
	);
}

void Doc_ComponentWiseArithmeticRhsType( stringBuilder_t* sb, const char* lhsTypeName, const char* rhsTypeName, const genOpArithmetic_t op ) {
	assert( sb );
	assert( lhsTypeName );
	assert( rhsTypeName );
	assert( op >= GEN_OP_ARITHMETIC_ADD && op < GEN_OP_ARITHMETIC_COUNT );

	const char* adjective = NULL;

	switch ( op ) {
		case GEN_OP_ARITHMETIC_ADD:	adjective = "added";		break;
		case GEN_OP_ARITHMETIC_SUB:	adjective = "subtracted";	break;
		case GEN_OP_ARITHMETIC_MUL:	adjective = "multiplied";	break;
		case GEN_OP_ARITHMETIC_DIV:	adjective = "divided";		break;

		case GEN_OP_ARITHMETIC_COUNT:
			return;
	}

	String_Appendf( sb,
		"/// \\relates %s\n"
		"/// \\brief Returns a copy of the %s that has been component-wise %s by the corresponding component of the right-hand %s.\n",
		lhsTypeName, lhsTypeName, adjective, rhsTypeName
	);
}

void Doc_OperatorCompoundComponentWiseArithmeticRhsType( stringBuilder_t* sb, const char* lhsTypeName, const char* rhsTypeName, const genOpArithmetic_t op ) {
	assert( sb );
	assert( lhsTypeName );
	assert( rhsTypeName );
	assert( op >= GEN_OP_ARITHMETIC_ADD && op < GEN_OP_ARITHMETIC_COUNT );

	const char* verb = NULL;

	switch ( op ) {
		case GEN_OP_ARITHMETIC_ADD:	verb = "Adds";			break;
		case GEN_OP_ARITHMETIC_SUB:	verb = "Subtracts";		break;
		case GEN_OP_ARITHMETIC_MUL:	verb = "Multiplies";	break;
		case GEN_OP_ARITHMETIC_DIV:	verb = "Divides";		break;

		case GEN_OP_ARITHMETIC_COUNT:
			return;
	}

	String_Appendf( sb,
		"/// \\relates %s\n"
		"/// \\brief %s each component of the %s by the corresponding component of the right-hand %s.\n", lhsTypeName, verb, lhsTypeName, rhsTypeName
	);
}

void Doc_OperatorIncrementPrefix( stringBuilder_t* sb, const char* fullTypeName, const genOpIncrement_t op ) {
	assert( sb );
	assert( fullTypeName );
	assert( op >= GEN_OP_INCREMENT_INCREMENT && op < GEN_OP_INCREMENT_COUNT );

	const char* verb = NULL;
	const char* noun = NULL;

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
			return;
	}

	String_Appendf( sb,
		"/// \\relates %s\n"
		"/// \\brief Prefix %s operator.  %s each component of the given %s before evaluation.\n", fullTypeName, noun, verb, fullTypeName
	);
}

void Doc_OperatorIncrementPostfix( stringBuilder_t* sb, const char* fullTypeName, const genOpIncrement_t op ) {
	assert( sb );
	assert( fullTypeName );
	assert( op >= GEN_OP_INCREMENT_INCREMENT && op < GEN_OP_INCREMENT_COUNT );

	const char* verb = NULL;
	const char* noun = NULL;

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
			return;
	}

	String_Appendf( sb,
		"/// \\relates %s\n"
		"/// \\brief Postfix %s operator.  %s each component of the given %s after evaluation.\n", fullTypeName, noun, verb, fullTypeName
	);
}

void Doc_ComponentWiseRelational( stringBuilder_t* sb, const char* fullTypeName, const u32 numRows, const u32 numCols, const genOpRelational_t op ) {
	assert( sb );
	assert( fullTypeName );
	assert( numRows >= 1 );	// pass through 1 for vectors
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );
	assert( op >= GEN_OP_RELATIONAL_LESS && op < GEN_OP_RELATIONAL_COUNT );

	const char* noun = NULL;

	switch ( op ) {
		case GEN_OP_RELATIONAL_LESS:			noun = "less than";					break;
		case GEN_OP_RELATIONAL_LESS_EQUAL:		noun = "less than or equal to";		break;
		case GEN_OP_RELATIONAL_GREATER:			noun = "greater than";				break;
		case GEN_OP_RELATIONAL_GREATER_EQUAL:	noun = "greater than or equal to";	break;

		case GEN_OP_RELATIONAL_COUNT:
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

void Doc_OperatorBitwiseRhsType( stringBuilder_t* sb, const char* fullTypeName, const genOpBitwise_t op ) {
	assert( sb );
	assert( fullTypeName );
	assert( op >= GEN_OP_BITWISE_AND && op < GEN_OP_BITWISE_COUNT );

	const char* adjective = NULL;
	const char* preposition = NULL;

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
			assert( false && "ERROR: For bitwise unary documentation, call Doc_OperatorBitwiseUnary().\n" );
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
			return;
	}

	String_Appendf( sb,
		"/// \\relates %s\n"
		"/// \\brief Returns a copy of the %s where each component of the left-hand %s"
		" has been %s %s the corresponding component of the right-hand side %s.\n", fullTypeName, fullTypeName, fullTypeName, adjective, preposition, fullTypeName
	);
}

void Doc_OperatorCompoundBitwiseScalar( stringBuilder_t* sb, const char* fullTypeName, const genOpBitwise_t op ) {
	assert( sb );
	assert( fullTypeName );
	assert( op >= GEN_OP_BITWISE_AND && op < GEN_OP_BITWISE_COUNT );

	const char* opDesc = NULL;
	const char* preposition = NULL;

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
			assert( false && "ERROR: For bitwise unary documentation, call Doc_OperatorBitwiseUnary().\n" );
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
			return;
	}

	String_Appendf( sb,
		"/// \\relates %s\n"
		"/// \\brief Performs a %s on the given left-hand %s %s the given scalar value.\n", fullTypeName, opDesc, fullTypeName, preposition
	);
}

void Doc_OperatorCompoundBitwiseRhsType( stringBuilder_t* sb, const char* fullTypeName, const genOpBitwise_t op ) {
	assert( sb );
	assert( fullTypeName );
	assert( op >= GEN_OP_BITWISE_AND && op < GEN_OP_BITWISE_COUNT );

	const char* opDesc = NULL;
	const char* preposition = NULL;

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
			assert( false && "ERROR: For bitwise unary documentation, call Doc_OperatorBitwiseUnary().\n" );
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
			return;
	}

	String_Appendf( sb,
		"/// \\relates %s\n"
		"/// \\brief Performs a %s on the given left-hand %s %s "
		"the corresponding component of the given right-hand %s.\n", fullTypeName, opDesc, fullTypeName, preposition, fullTypeName
	);
}

void Doc_OperatorBitwiseUnary( stringBuilder_t* sb, const char* fullTypeName ) {
	assert( sb );
	assert( fullTypeName );

	String_Appendf( sb,
		"/// \\relates %s\n"
		"/// \\brief Performs a unary bitwise operation on all components of the given %s.\n", fullTypeName, fullTypeName
	);
}

#include "gen_shared.h"

#include "int_types.h"
#include "common_names.h"

#include <assert.h>
#include <stdbool.h>


typedef enum operatorSingleParmFlagBits_t {
	OPERATOR_PREFIX_FLAG_RETURN_COPY	= GEN_BIT( 0 ),
} operatorSingleParmFlagBits_t;
typedef u32 operatorSingleParmFlags_t;


static genType_t Gen_GetSupportedFloatingPointType( const genType_t type ) {
	return ( type == GEN_TYPE_DOUBLE ) ? GEN_TYPE_DOUBLE : GEN_TYPE_FLOAT;
}

static bool32 Gen_TypeIsFloatingPoint( const genType_t type ) {
	return type == GEN_TYPE_FLOAT || type == GEN_TYPE_DOUBLE;
}

static bool32 Gen_TypeIsInteger( const genType_t type ) {
	return type == GEN_TYPE_INT || type == GEN_TYPE_UINT;
}

static bool32 Gen_TypeSupportsSIMD( const genType_t type ) {
	// DM: I'm not even sure yet if we will want to have SIMD support for anything other than float...
	return type == GEN_TYPE_FLOAT;
}

static const char* Gen_GetTypeString( const genType_t type ) {
	assert( type != GEN_TYPE_COUNT && "Bad enum passed in!\n" );

	switch ( type ) {
		case GEN_TYPE_BOOL:		return "bool";
		case GEN_TYPE_INT:		return "int";
		case GEN_TYPE_UINT:		return "uint";
		case GEN_TYPE_FLOAT:	return "float";
		case GEN_TYPE_DOUBLE:	return "double";

		case GEN_TYPE_COUNT:	return "ERROR";
	}
}

static const char* Gen_GetMemberTypeString( const genType_t type ) {
	assert( type != GEN_TYPE_COUNT && "Bad enum passed in!\n" );

	switch ( type ) {
		case GEN_TYPE_BOOL:		return "bool32_t";
		case GEN_TYPE_INT:		return "int32_t";
		case GEN_TYPE_UINT:		return "uint32_t";
		case GEN_TYPE_FLOAT:	return "float";
		case GEN_TYPE_DOUBLE:	return "double";

		case GEN_TYPE_COUNT:	return "ERROR";
	}
}

static u32 Gen_GetTypeBytes( const genType_t type ) {
	assert( type != GEN_TYPE_COUNT && "Bad enum passed in!\n" );

	switch ( type ) {
		case GEN_TYPE_BOOL:
		case GEN_TYPE_INT:
		case GEN_TYPE_UINT:
		case GEN_TYPE_FLOAT:
			return 4;

		case GEN_TYPE_DOUBLE:
			return 8;


		case GEN_TYPE_COUNT:	return (u32) -1;
	}
}

//================================================================

static bool32 Gen_VectorQualifiesAsQuaternion( const typeInfo_t* typeInfo ) {
	return Gen_TypeIsFloatingPoint( typeInfo->type ) && typeInfo->numCols == 4;
}

static typeInfo_t Gen_GetQuaternionImaginaryPartType( const typeInfo_t* typeInfo, allocatorLinear_t* tempStorage ) {
	assert( Gen_VectorQualifiesAsQuaternion( typeInfo ) );

	const char* typeString = Gen_GetTypeString( typeInfo->type );

	typeInfo_t imaginaryType = { 0 };
	imaginaryType.type = typeInfo->type;
	imaginaryType.numRows = 1;
	imaginaryType.numCols = 3;
	imaginaryType.fullTypeName = String_TPrintf( tempStorage, "%s%d", typeString, imaginaryType.numCols );

	return imaginaryType;
}

//================================================================

// DM: I know this isnt correct for all built in C functions
// but it should cover all the ones that we care about
static const char* Gen_GetBuiltinFunction( allocatorLinear_t* tempStorage, const genType_t type, const char* functionName ) {
	assert( tempStorage );
	assert( type != GEN_TYPE_COUNT );
	assert( functionName );

	if ( type == GEN_TYPE_DOUBLE ) {
		return functionName;
	} else {
		return String_TPrintf( tempStorage, "%sf", functionName );
	}
}

static const char* Gen_GetRelationalName( const genOpRelational_t op ) {
	assert( op != GEN_OP_RELATIONAL_COUNT );

	switch ( op ) {
		case GEN_OP_RELATIONAL_LESS_THAN:			return "less_than";
		case GEN_OP_RELATIONAL_LESS_THAN_EQUAL:		return "less_than_equal";
		case GEN_OP_RELATIONAL_GREATER_THAN:		return "greater_than";
		case GEN_OP_RELATIONAL_GREATER_THAN_EQUAL:	return "greater_than_equal";

		case GEN_OP_RELATIONAL_COUNT:				return "ERROR";
	}
}

static const char* Gen_GetOperatorRelational( const genOpRelational_t op ) {
	assert( op != GEN_OP_RELATIONAL_COUNT );

	switch ( op ) {
		case GEN_OP_RELATIONAL_LESS_THAN:			return "<";
		case GEN_OP_RELATIONAL_LESS_THAN_EQUAL:		return "<=";
		case GEN_OP_RELATIONAL_GREATER_THAN:		return ">";
		case GEN_OP_RELATIONAL_GREATER_THAN_EQUAL:	return ">=";

		case GEN_OP_RELATIONAL_COUNT:				return "ERROR";
	}
}

static const char* Gen_GetArithmeticName( const genOpArithmetic_t op ) {
	assert( op != GEN_OP_ARITHMETIC_COUNT );

	switch ( op ) {
		case GEN_OP_ARITHMETIC_ADD:		return "add";
		case GEN_OP_ARITHMETIC_SUB:		return "sub";
		case GEN_OP_ARITHMETIC_MUL:		return "mul";
		case GEN_OP_ARITHMETIC_DIV:		return "div";

		case GEN_OP_ARITHMETIC_COUNT:	return "ERROR";
	}
}

static const char* Gen_GetOperatorArithmetic( const genOpArithmetic_t op ) {
	assert( op != GEN_OP_ARITHMETIC_COUNT );

	switch ( op ) {
		case GEN_OP_ARITHMETIC_ADD:		return "+";
		case GEN_OP_ARITHMETIC_SUB:		return "-";
		case GEN_OP_ARITHMETIC_MUL:		return "*";
		case GEN_OP_ARITHMETIC_DIV:		return "/";

		case GEN_OP_ARITHMETIC_COUNT:	return "ERROR";
	}
}

static const char* Gen_GetIncrementName( const genOpIncrement_t op ) {
	assert( op != GEN_OP_INCREMENT_COUNT );

	switch ( op ) {
		case GEN_OP_INCREMENT:			return "increment";
		case GEN_OP_DECREMENT:			return "decrement";

		case GEN_OP_INCREMENT_COUNT:	return "ERROR";
	}
}

static const char* Gen_GetOperatorIncrement( const genOpIncrement_t op ) {
	assert( op != GEN_OP_INCREMENT_COUNT );

	switch ( op ) {
		case GEN_OP_INCREMENT:			return "++";
		case GEN_OP_DECREMENT:			return "--";

		case GEN_OP_INCREMENT_COUNT:	return "ERROR";
	}
}

static const char* Gen_GetBitwiseName( const genOpBitwise_t op ) {
	assert( op != GEN_OP_BITWISE_COUNT );

	switch ( op ) {
		case GEN_OP_BITWISE_UNARY:			return "unary";
		case GEN_OP_BITWISE_AND:			return "and";
		case GEN_OP_BITWISE_OR:				return "or";
		case GEN_OP_BITWISE_XOR:			return "xor";
		case GEN_OP_BITWISE_SHIFT_LEFT:		return "shift_left";
		case GEN_OP_BITWISE_SHIFT_RIGHT:	return "shift_right";

		case GEN_OP_BITWISE_COUNT:			return "ERROR";
	}
}

static const char* Gen_GetOperatorBitwise( const genOpBitwise_t op ) {
	assert( op != GEN_OP_BITWISE_COUNT );

	switch ( op ) {
		case GEN_OP_BITWISE_UNARY:			return "~";
		case GEN_OP_BITWISE_AND:			return "&";
		case GEN_OP_BITWISE_OR:				return "|";
		case GEN_OP_BITWISE_XOR:			return "^";
		case GEN_OP_BITWISE_SHIFT_LEFT:		return "<<";
		case GEN_OP_BITWISE_SHIFT_RIGHT:	return ">>";

		case GEN_OP_BITWISE_COUNT:			return "ERROR";
	}
}

//================================================================

static bool32 Gen_TypeIsScalar( const typeInfo_t* typeInfo ) {
	assert( typeInfo );

	return typeInfo->numRows == 1 && typeInfo->numCols == 1;
}

static bool32 Gen_TypeIsVector( const typeInfo_t* typeInfo ) {
	assert( typeInfo );

	return typeInfo->numRows == 1 && typeInfo->numCols >= 2;
}

static bool32 Gen_TypeIsMatrix( const typeInfo_t* typeInfo ) {
	assert( typeInfo );

	return typeInfo->numRows >= 2 && typeInfo->numCols >= 2;
}

static typeInfo_t Gen_GetScalarType( const typeInfo_t* typeInfo ) {
	assert( typeInfo );
	assert( !Gen_TypeIsScalar( typeInfo ) );

	return (typeInfo_t) {
		.type			= typeInfo->type,
		.numRows		= 1,
		.numCols		= 1,
		.fullTypeName	= Gen_GetMemberTypeString( typeInfo->type )
	};
}

//================================================================

static const char* Gen_GetFuncName_Floateq( const genType_t type ) {
	return ( type == GEN_TYPE_DOUBLE ) ? "doubleeq" : "floateq";
}

static const char* Gen_GetFuncName_Floateq_eps( const genType_t type ) {
	return ( type == GEN_TYPE_DOUBLE ) ? "doubleeq_eps" : "floateq_eps";
}

static const char* Gen_GetFuncName_Scalar( allocatorLinear_t* tempStorage, const genType_t type, const generatorFlags_t flags, const char* functionName ) {
	assert( tempStorage );
	assert( type != GEN_TYPE_COUNT );
	assert( functionName );

	if ( flags & GENERATOR_FLAG_NAME_MANGLING ) {
		return functionName;
	} else {
		const char* fmt = NULL;

		switch ( type ) {
			case GEN_TYPE_BOOL:		fmt = "%sb"; break;
			case GEN_TYPE_INT:		fmt = "%si"; break;
			case GEN_TYPE_UINT:		fmt = "%su"; break;
			case GEN_TYPE_FLOAT:	fmt = "%sf"; break;
			case GEN_TYPE_DOUBLE:	fmt = "%sd"; break;

			case GEN_TYPE_COUNT:	fmt = NULL; break;
		}

		assert( fmt );

		return String_TPrintf( tempStorage, fmt, functionName );
	}
}

static const char* Gen_GetFuncName_Vector( allocatorLinear_t* tempStorage, const typeInfo_t* typeInfo, const generatorFlags_t flags, const char* functionName ) {
	assert( tempStorage );
	assert( typeInfo );
	assert( typeInfo->fullTypeName );
	assert( Gen_TypeIsVector( typeInfo ) || Gen_TypeIsMatrix( typeInfo ) );
	assert( functionName );

	if ( flags & GENERATOR_FLAG_NAME_MANGLING ) {
		return functionName;
	} else {
		return String_TPrintf( tempStorage, "%s_%s", typeInfo->fullTypeName, functionName );
	}
}

static const char* Gen_GetFuncName_VectorRelational( allocatorLinear_t* tempStorage, const typeInfo_t* typeInfo, const genOpRelational_t op ) {
	assert( tempStorage );
	assert( typeInfo );
	assert( typeInfo->fullTypeName );
	assert( op != GEN_OP_RELATIONAL_COUNT );

	const char* opName = Gen_GetRelationalName( op );

	return String_TPrintf( tempStorage, "%s_%s", typeInfo->fullTypeName, opName );
}

static const char* Gen_GetFuncName_VectorArithmeticScalar( allocatorLinear_t* tempStorage, const typeInfo_t* typeInfo, const genOpArithmetic_t op ) {
	assert( tempStorage );
	assert( typeInfo );
	assert( typeInfo->fullTypeName );
	assert( op != GEN_OP_ARITHMETIC_COUNT );

	const char* opName = Gen_GetArithmeticName( op );

	return String_TPrintf( tempStorage, "%s_c%ss", typeInfo->fullTypeName, opName );
}

static const char* Gen_GetFuncName_VectorArithmeticVector( allocatorLinear_t* tempStorage, const typeInfo_t* typeInfo, const genOpArithmetic_t op ) {
	assert( tempStorage );
	assert( typeInfo );
	assert( typeInfo->fullTypeName );
	assert( op != GEN_OP_ARITHMETIC_COUNT );

	const char* opName = Gen_GetArithmeticName( op );

	return String_TPrintf( tempStorage, "%s_c%sv", typeInfo->fullTypeName, opName );
}

static const char* Gen_GetFuncName_VectorArithmeticMatrix( allocatorLinear_t* tempStorage, const typeInfo_t* typeInfo, const genOpArithmetic_t op ) {
	assert( tempStorage );
	assert( typeInfo );
	assert( typeInfo->fullTypeName );
	assert( op != GEN_OP_ARITHMETIC_COUNT );

	const char* opName = Gen_GetArithmeticName( op );

	return String_TPrintf( tempStorage, "%s_c%sm", typeInfo->fullTypeName, opName );
}

static const char* Gen_GetFuncName_VectorBitwiseScalar( allocatorLinear_t* tempStorage, const typeInfo_t* typeInfo, const genOpBitwise_t op ) {
	assert( tempStorage );
	assert( typeInfo );
	assert( typeInfo->fullTypeName );
	assert( op != GEN_OP_BITWISE_COUNT );
	assert( op != GEN_OP_BITWISE_UNARY );

	const char* opName = Gen_GetBitwiseName( op );

	return String_TPrintf( tempStorage, "%s_c%ss", typeInfo->fullTypeName, opName );
}

static const char* Gen_GetFuncName_VectorBitwiseVector( allocatorLinear_t* tempStorage, const typeInfo_t* typeInfo, const genOpBitwise_t op ) {
	assert( tempStorage );
	assert( typeInfo );
	assert( typeInfo->fullTypeName );
	assert( op != GEN_OP_BITWISE_COUNT );
	assert( op != GEN_OP_BITWISE_UNARY );

	const char* opName = Gen_GetBitwiseName( op );

	return String_TPrintf( tempStorage, "%s_c%sv", typeInfo->fullTypeName, opName );
}

static const char* Gen_GetFuncName_VectorBitwiseMatrix( allocatorLinear_t* tempStorage, const typeInfo_t* typeInfo, const genOpBitwise_t op ) {
	assert( tempStorage );
	assert( typeInfo );
	assert( typeInfo->fullTypeName );
	assert( op != GEN_OP_BITWISE_COUNT );
	assert( op != GEN_OP_BITWISE_UNARY );

	const char* opName = Gen_GetBitwiseName( op );

	return String_TPrintf( tempStorage, "%s_c%sm", typeInfo->fullTypeName, opName );
}

static const char* Gen_GetFuncName_MatrixMul( allocatorLinear_t* tempStorage, const typeInfo_t* lhsType, const typeInfo_t* rhsType, const generatorFlags_t flags ) {
	assert( tempStorage );
	assert( lhsType );
	assert( lhsType->fullTypeName );
	assert( Gen_TypeIsMatrix( lhsType ) );
	assert( rhsType );
	assert( rhsType->fullTypeName );
	assert( !Gen_TypeIsScalar( rhsType ) );

	if ( flags & GENERATOR_FLAG_NAME_MANGLING ) {
		return GEN_FUNCTION_NAME_MUL;
	} else {
		const char* suffix = Gen_TypeIsVector( rhsType ) ? "v" : "m";

		return String_TPrintf( tempStorage, "%s_mul%s", lhsType->fullTypeName, suffix );
	}
}

//================================================================

static void GetMatrixCodeMultiply( allocatorLinear_t* tempStorage, const typeInfo_t* typeInfo, stringBuilder_t* code, const char* accessOperatorStr, const bool32 useConstructor ) {
	assert( tempStorage );
	assert( typeInfo );
	assert( code );
	assert( accessOperatorStr );

	u32 numRhsRows = typeInfo->numCols;
	u32 numRhsCols = typeInfo->numRows;

	const char* typeString = Gen_GetTypeString( typeInfo->type );

	const char* returnTypeName = String_TPrintf( tempStorage, "%s%dx%d", typeString, typeInfo->numRows, typeInfo->numRows );

	// main operator

	// generate row vars
	for ( u32 row = 0; row < typeInfo->numRows; row++ ) {
		StringBuilder_Appendf( code, "\t%s%d row%d = lhs%srows[%d];\n", typeString, typeInfo->numCols, row, accessOperatorStr, row );
	}

	StringBuilder_Append( code, "\n" );

	// generate col vars
	for ( u32 col = 0; col < numRhsCols; col++ ) {
		StringBuilder_Appendf( code, "\t%s%d col%d = { ", typeString, typeInfo->numCols, col );
		for ( u32 rhsRow = 0; rhsRow < numRhsRows; rhsRow++ ) {
			StringBuilder_Appendf( code, "rhs%srows[%d].%c", accessOperatorStr, rhsRow, GEN_COMPONENT_NAMES_VECTOR[col] );

			if ( rhsRow != typeInfo->numCols - 1 ) {
				StringBuilder_Append( code, ", " );
			}
		}

		StringBuilder_Append( code, " };\n" );
	}
	StringBuilder_Append( code, "\n" );

	// now do the row/col dot products
	if ( useConstructor ) {
		StringBuilder_Appendf( code, "\treturn %s(\n", returnTypeName );
	} else {
		StringBuilder_Appendf( code, "\treturn HLML_CONSTRUCT( %s )\n", returnTypeName );
		StringBuilder_Append(  code, "\t{\n" );
	}

	for ( u32 row = 0; row < typeInfo->numRows; row++ ) {
		for ( u32 col = 0; col < typeInfo->numRows; col++ ) {
			StringBuilder_Append( code, "\t\t" );

			for ( u32 rhsRow = 0; rhsRow < numRhsRows; rhsRow++ ) {
				char rhsComponent = GEN_COMPONENT_NAMES_VECTOR[rhsRow];

				StringBuilder_Appendf( code, "row%d.%c * col%d.%c", row, rhsComponent, col, rhsComponent );

				if ( rhsRow != numRhsRows - 1 ) {
					StringBuilder_Append( code, " + " );
				} else {
					if ( col + ( row * typeInfo->numRows ) != ( typeInfo->numRows * typeInfo->numRows ) - 1 ) {
						StringBuilder_Append( code, "," );
					}

					StringBuilder_Append( code, "\n" );
				}
			}
		}

		if ( row != typeInfo->numRows - 1 ) {
			StringBuilder_Append( code, "\n" );
		}
	}
	if ( useConstructor ) {
		StringBuilder_Append( code, "\t);\n" );
	} else {
		StringBuilder_Append( code, "\t};\n" );
	}
}

static void GetMatrixCodeMultiplyVector( allocatorLinear_t* tempStorage, const typeInfo_t* matrixType, const typeInfo_t* vectorType, stringBuilder_t* code, const char* accessOperatorStr, const bool32 useConstructor ) {
	assert( tempStorage );
	assert( matrixType );
	assert( vectorType );
	assert( vectorType->fullTypeName );
	assert( matrixType->type == vectorType->type );
	assert( Gen_TypeIsMatrix( matrixType ) );
	assert( Gen_TypeIsVector( vectorType ) );
	assert( matrixType->numRows == matrixType->numCols );
	assert( matrixType->numCols == vectorType->numCols );
	assert( code );
	assert( accessOperatorStr );

	if ( useConstructor ) {
		StringBuilder_Appendf( code, "\treturn %s(\n", vectorType->fullTypeName );
	} else {
		StringBuilder_Appendf( code, "\treturn HLML_CONSTRUCT( %s )\n", vectorType->fullTypeName );
		StringBuilder_Append(  code, "\t{\n" );
	}
	for ( u32 row = 0; row < matrixType->numRows; row++ ) {
		StringBuilder_Append( code, "\t\t" );

		const char matrixRowComponentStr = GEN_COMPONENT_NAMES_VECTOR[row];

		for ( u32 componentIndex = 0; componentIndex < vectorType->numCols; componentIndex++ ) {
			const char vectorComponentStr = GEN_COMPONENT_NAMES_VECTOR[componentIndex];

			StringBuilder_Appendf( code, "( lhs%s%c * rhs%srows[%d].%c )", accessOperatorStr, vectorComponentStr, accessOperatorStr, componentIndex, matrixRowComponentStr );

			if ( componentIndex != vectorType->numCols - 1 ) {
				StringBuilder_Append( code, " + " );
			}
		}

		if ( row != matrixType->numRows - 1 ) {
			StringBuilder_Append( code, "," );
		}

		StringBuilder_Append( code, "\n" );
	}
	if ( useConstructor ) {
		StringBuilder_Append( code, "\t);\n" );
	} else {
		StringBuilder_Append( code, "\t};\n" );
	}
}

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wfloat-equal"

static const char* Gen_GetNumericLiteral( allocatorLinear_t* tempStorage, const genType_t type, const float32 x, const u32 decimalPlaces ) {
	assert( tempStorage );
	assert( type != GEN_TYPE_COUNT );

	switch ( type ) {
		case GEN_TYPE_BOOL:
			return String_TPrintf( tempStorage, "%s", ( x != 0 ) ? "true" : "false" );

		case GEN_TYPE_INT:
			return String_TPrintf( tempStorage, "%d", (s32) x );

		case GEN_TYPE_UINT:
			return String_TPrintf( tempStorage, "%uU", (u32) x );

		case GEN_TYPE_FLOAT:
			if ( decimalPlaces == 0 ) {
				return String_TPrintf( tempStorage, "%ff", (float) x );
			} else {
				return String_TPrintf( tempStorage, "%.*ff", decimalPlaces, (float) x );
			}

		case GEN_TYPE_DOUBLE:
			if ( decimalPlaces == 0 ) {
				return String_TPrintf( tempStorage, "%ff", (double) x );
			} else {
				return String_TPrintf( tempStorage, "%.*f", decimalPlaces, (double) x );
			}

		case GEN_TYPE_COUNT:
			return "ERROR";
	}
}

#pragma clang diagnostic pop

static stringBuilder_t* Gen_GetParmList_Vector( allocatorLinear_t* tempStorage, const typeInfo_t* typeInfo, const float32* values, const u32 decimalPlaces ) {
	stringBuilder_t* stringBuilder = StringBuilder_Create( tempStorage, 1 * KB_TO_BYTES );

	for ( u32 i = 0; i < typeInfo->numCols; i++ ) {
		const char* valueAsStr = Gen_GetNumericLiteral( tempStorage, typeInfo->type, values[i], decimalPlaces );

		StringBuilder_Append( stringBuilder, valueAsStr );

		if ( i < typeInfo->numCols - 1 ) {
			StringBuilder_Append( stringBuilder, ", " );
		}
	}

	return stringBuilder;
}

static stringBuilder_t* Gen_GetParmList_Matrix( allocatorLinear_t* tempStorage, const typeInfo_t* typeInfo, const float32* values, const u32 decimalPlaces ) {
	stringBuilder_t* stringBuilder = StringBuilder_Create( tempStorage, 1 * KB_TO_BYTES );

	for ( u32 row = 0; row < typeInfo->numRows; row++ ) {
		StringBuilder_Append( stringBuilder, "\t\t" );
		for ( u32 col = 0; col < typeInfo->numCols; col++ ) {
			u32 index = col + ( row * 4 );

			const char* valueAsStr = Gen_GetNumericLiteral( tempStorage, typeInfo->type, values[index], decimalPlaces );

			StringBuilder_Append( stringBuilder, valueAsStr );

			if ( col < typeInfo->numCols - 1 ) {
				StringBuilder_Append( stringBuilder, ", " );
			}
		}

		if ( row < typeInfo->numRows - 1 ) {
			StringBuilder_Append( stringBuilder, "," );
		}

		StringBuilder_Append( stringBuilder, "\n" );
	}

	return stringBuilder;
}

static stringBuilder_t* Gen_GetParmList_MatrixMultiply( allocatorLinear_t* tempStorage, const typeInfo_t* lhsType, const typeInfo_t* rhsType, const float32* valuesLhs, const float32* valuesRhs ) {
	assert( tempStorage );
	assert( lhsType );
	assert( lhsType->fullTypeName );
	assert( rhsType );
	assert( rhsType->fullTypeName );
	assert( !Gen_TypeIsScalar( lhsType ) );
	assert( Gen_TypeIsMatrix( rhsType ) );
	assert( lhsType->type == rhsType->type );
	assert( valuesLhs );
	assert( valuesRhs );

	u32 returnTypeRows = lhsType->numRows;
	u32 returnTypeCols = rhsType->numCols;

	stringBuilder_t* parmList = StringBuilder_Create( tempStorage, 1 * KB_TO_BYTES );

	for ( u32 row = 0; row < returnTypeRows; row++ ) {
		StringBuilder_Append( parmList, "\t\t" );

		for ( u32 col = 0; col < returnTypeCols; col++ ) {
			// get the left-hand row
			float lhsRow[4];
			for ( u32 lhsComponent = 0; lhsComponent < lhsType->numCols; lhsComponent++ ) {
				u32 index = lhsComponent + ( row * 4 );
				lhsRow[lhsComponent] = valuesLhs[index];
			}

			// get the right-hand column
			float rhsCol[4];
			for ( u32 rhsComponent = 0; rhsComponent < rhsType->numRows; rhsComponent++ ) {
				u32 index = col + ( rhsComponent * 4 );
				rhsCol[rhsComponent] = valuesRhs[index];
			}

			// do the dot product procedurally
			float dots[4];
			for ( u32 i = 0; i < lhsType->numCols; i++ ) {
				dots[i] = lhsRow[i] * rhsCol[i];
			}

			float value = 0.0f;
			for ( u32 i = 0; i < lhsType->numCols; i++ ) {
				value += dots[i];
			}

			const char* valueStr = Gen_GetNumericLiteral( tempStorage, lhsType->type, value, 0 );

			StringBuilder_Appendf( parmList, "%s", valueStr );

			if ( row + col != ( returnTypeRows - 1 ) + ( returnTypeCols - 1 ) ) {
				StringBuilder_Append( parmList, "," );
			}

			if ( col != returnTypeCols - 1 ) {
				StringBuilder_Append( parmList, " " );
			}
		}

		StringBuilder_Append( parmList, "\n" );
	}

	return parmList;
}

static stringBuilder_t* Gen_GetConstructor( allocatorLinear_t* tempStorage, const typeInfo_t* typeInfo, const float32* values, const generatorStrings_t* strings, const generatorFlags_t flags ) {
	assert( tempStorage );
	assert( typeInfo );
	assert( typeInfo->fullTypeName );
	assert( values );
	assert( strings );

	bool32 generateConstructors = flags & GENERATOR_FLAG_GENERATE_CONSTRUCTORS;

	stringBuilder_t* result = StringBuilder_Create( tempStorage, 1024 * KB_TO_BYTES );

	if ( Gen_TypeIsVector( typeInfo ) ) {
		stringBuilder_t* parmList = Gen_GetParmList_Vector( tempStorage, typeInfo, values, 0 );

		if ( generateConstructors ) {
			StringBuilder_Appendf( result, "\t%s( ", typeInfo->fullTypeName );
			StringBuilder_Append(  result, parmList->str );
			StringBuilder_Append(  result, " )" );
		} else {
			StringBuilder_Appendf( result, "\t%s(%s) { ", strings->parmReferenceStr, typeInfo->fullTypeName );
			StringBuilder_Append(  result, parmList->str );
			StringBuilder_Append(  result, " }" );
		}
	} else if ( Gen_TypeIsMatrix( typeInfo ) ) {
		stringBuilder_t* parmList = Gen_GetParmList_Matrix( tempStorage, typeInfo, values, 0 );

		if ( generateConstructors ) {
			StringBuilder_Appendf( result, "\t%s(\n", typeInfo->fullTypeName );
			StringBuilder_Append(  result, parmList->str );
			StringBuilder_Append(  result, "\t)" );
		} else {
			StringBuilder_Appendf( result, "\t%s(%s)\n", strings->parmReferenceStr, typeInfo->fullTypeName );
			StringBuilder_Append(  result, "\t{\n" );
			StringBuilder_Append(  result, parmList->str );
			StringBuilder_Append(  result, "\t}" );
		}
	} else {
		StringBuilder_Appendf( result, "\t%s", Gen_GetNumericLiteral( tempStorage, typeInfo->type, values[0], 0 ) );
	}

	return result;
}

static void GenerateFunction_Equals( allocatorLinear_t* tempStorage, const typeInfo_t* typeInfo, stringBuilder_t* code, const generatorFlags_t flags ) {
	assert( tempStorage );
	assert( typeInfo );
	assert( !Gen_TypeIsScalar( typeInfo ) );
	assert( code );

	u32 numIterations = Gen_TypeIsVector( typeInfo ) ? typeInfo->numCols : typeInfo->numRows;

	StringBuilder_Append( code, "// Returns true if the contents of 'lhs' are the same as the contents of 'rhs', otherwise returns false.\n" );

	if ( flags & GENERATOR_FLAG_GENERATE_OPERATORS ) {
		StringBuilder_Appendf( code, "HLML_INLINE bool operator==( const %s& lhs, const %s& rhs )\n", typeInfo->fullTypeName, typeInfo->fullTypeName );
		StringBuilder_Append(  code, "{\n");
		StringBuilder_Append(  code, "\treturn\n" );

		if ( Gen_TypeIsVector( typeInfo ) && Gen_TypeIsFloatingPoint( typeInfo->type ) ) {
			const char* floateqFuncStr = Gen_GetFuncName_Floateq( typeInfo->type );

			for ( u32 i = 0; i < numIterations; i++ ) {
				StringBuilder_Appendf( code, "\t\t%s( lhs[%d], rhs[%d] )", floateqFuncStr, i, i );

				if ( i < numIterations - 1 ) {
					StringBuilder_Append( code, " &&\n" );
				}
			}
		} else {
			for ( u32 i = 0; i < numIterations; i++ ) {
				StringBuilder_Appendf( code, "\t\tlhs[%d] == rhs[%d]", i, i );

				if ( i < numIterations - 1 ) {
					StringBuilder_Append( code, " &&\n" );
				}
			}
		}

		StringBuilder_Append( code, ";\n" );
		StringBuilder_Append( code, "}\n\n" );
	} else {
		const char* equalsFuncStr = Gen_GetFuncName_Vector( tempStorage, typeInfo, flags, GEN_FUNCTION_NAME_EQUALS );

		StringBuilder_Appendf( code, "HLML_INLINE bool %s( const %s* lhs, const %s* rhs )\n", equalsFuncStr, typeInfo->fullTypeName, typeInfo->fullTypeName );
		StringBuilder_Append(  code, "{\n" );
		StringBuilder_Append(  code, "\treturn\n" );

		if ( Gen_TypeIsVector( typeInfo ) ) {
			if ( Gen_TypeIsFloatingPoint( typeInfo->type ) ) {
				const char* floateqFuncStr = Gen_GetFuncName_Floateq( typeInfo->type );

				for ( u32 i = 0; i < typeInfo->numCols; i++ ) {
					const char componentName = GEN_COMPONENT_NAMES_VECTOR[i];

					StringBuilder_Appendf( code, "\t\t%s( lhs->%c, rhs->%c )", floateqFuncStr, componentName, componentName );

					if ( i < typeInfo->numCols - 1 ) {
						StringBuilder_Append( code, " &&\n" );
					}
				}
			} else {
				for ( u32 i = 0; i < typeInfo->numCols; i++ ) {
					const char componentName = GEN_COMPONENT_NAMES_VECTOR[i];

					StringBuilder_Appendf( code, "\t\tlhs->%c == rhs->%c", componentName, componentName );

					if ( i < typeInfo->numCols - 1 ) {
						StringBuilder_Append( code, " &&\n" );
					}
				}
			}
		} else {
			typeInfo_t memberType = {
				.type			= typeInfo->type,
				.numRows		= 1,
				.numCols		= typeInfo->numCols,
				.fullTypeName	= String_TPrintf( tempStorage, "%s%d", Gen_GetTypeString( memberType.type ), memberType.numCols )
			};

			const char* memberEqualsFunc = Gen_GetFuncName_Vector( tempStorage, &memberType, flags, GEN_FUNCTION_NAME_EQUALS );

			for ( u32 i = 0; i < typeInfo->numRows; i++ ) {
				StringBuilder_Appendf( code, "\t\t%s( &lhs->rows[%d], &rhs->rows[%d] )", memberEqualsFunc, i, i );

				if ( i < typeInfo->numRows - 1 ) {
					StringBuilder_Append( code, " &&\n" );
				}
			}
		}

		StringBuilder_Append( code, ";\n" );
		StringBuilder_Append( code, "}\n\n" );
	}
}

static void GenerateFunction_NotEquals( allocatorLinear_t* tempStorage, const typeInfo_t* typeInfo, stringBuilder_t* code, const generatorFlags_t flags ) {
	assert( tempStorage );
	assert( typeInfo );
	assert( code );

	StringBuilder_Append( code, "// Returns true if the contents of 'lhs' are NOT the same as the contents of 'rhs', otherwise returns false.\n" );

	if ( flags & GENERATOR_FLAG_GENERATE_OPERATORS ) {
		StringBuilder_Appendf( code, "HLML_INLINE bool operator!=( const %s& lhs, const %s& rhs )\n", typeInfo->fullTypeName, typeInfo->fullTypeName );
		StringBuilder_Append(  code, "{\n");
		StringBuilder_Append(  code, "\treturn !( lhs == rhs );\n" );
		StringBuilder_Append(  code, "}\n\n");
	} else {
		const char* equalsFuncStr = Gen_GetFuncName_Vector( tempStorage, typeInfo, flags, GEN_FUNCTION_NAME_EQUALS );
		const char* notEqualsFuncStr = Gen_GetFuncName_Vector( tempStorage, typeInfo, flags, GEN_FUNCTION_NAME_NOT_EQUALS );

		StringBuilder_Appendf( code, "HLML_INLINE bool %s( const %s* lhs, const %s* rhs )\n", notEqualsFuncStr, typeInfo->fullTypeName, typeInfo->fullTypeName );
		StringBuilder_Append(  code, "{\n");
		StringBuilder_Appendf( code, "\treturn !%s( lhs, rhs );\n", equalsFuncStr );
		StringBuilder_Append(  code, "}\n\n");
	}
}

static void GenerateComponentWiseOperator( allocatorLinear_t* tempStorage, stringBuilder_t* code, const typeInfo_t* returnType, const typeInfo_t* lhsType, const typeInfo_t* rhsType, const char* opStr, const char* commentStr ) {
	assert( tempStorage );
	assert( code );
	assert( returnType );
	assert( returnType->fullTypeName );
	assert( lhsType );
	assert( lhsType->fullTypeName );
	assert( !Gen_TypeIsScalar( lhsType ) );
	assert( rhsType );
	assert( rhsType->fullTypeName );
	assert( opStr );

	const char* rhsReferenceStr = rhsType && Gen_TypeIsScalar( rhsType ) ? "" : "&";

	StringBuilder_Append(  code, commentStr );
	StringBuilder_Appendf( code, "HLML_INLINE %s operator%s( const %s& lhs, const %s%s rhs )\n", returnType->fullTypeName, opStr, lhsType->fullTypeName, rhsType->fullTypeName, rhsReferenceStr );
	StringBuilder_Append(  code, "{\n" );
	StringBuilder_Appendf( code, "\treturn %s(\n", returnType->fullTypeName );

	if ( Gen_TypeIsVector( lhsType ) ) {
		if ( Gen_TypeIsScalar( rhsType ) ) {
			for ( u32 i = 0; i < returnType->numCols; i++ ) {
				StringBuilder_Appendf( code, "\t\tlhs[%d] %s rhs", i, opStr );

				if ( i < returnType->numCols - 1 ) {
					StringBuilder_Append( code, "," );
				}

				StringBuilder_Append( code, "\n" );
			}
		} else {
			for ( u32 i = 0; i < returnType->numCols; i++ ) {
				StringBuilder_Appendf( code, "\t\tlhs[%d] %s rhs[%d]", i, opStr, i );

				if ( i < returnType->numCols - 1 ) {
					StringBuilder_Append( code, "," );
				}

				StringBuilder_Append( code, "\n" );
			}
		}
	} else {
		if ( Gen_TypeIsScalar( rhsType ) ) {
			for ( u32 i = 0; i < returnType->numRows; i++ ) {
				StringBuilder_Appendf( code, "\t\tlhs[%d] %s rhs", i, opStr );

				if ( i < returnType->numRows - 1 ) {
					StringBuilder_Append( code, "," );
				}

				StringBuilder_Append( code, "\n" );
			}
		} else {
			for ( u32 i = 0; i < returnType->numRows; i++ ) {
				StringBuilder_Appendf( code, "\t\tlhs[%d] %s rhs[%d]", i, opStr, i );

				if ( i < returnType->numRows - 1 ) {
					StringBuilder_Append( code, "," );
				}

				StringBuilder_Append( code, "\n" );
			}
		}
	}

	StringBuilder_Append( code, "\t);\n" );
	StringBuilder_Append( code, "}\n\n" );
}

static void GenerateCompundComponentWiseOperator( allocatorLinear_t* tempStorage, stringBuilder_t* code, const typeInfo_t* returnType, const typeInfo_t* lhsType, const typeInfo_t* rhsType, const char* opStr, const char* commentStr ) {
	assert( tempStorage );
	assert( code );
	assert( returnType );
	assert( returnType->fullTypeName );
	assert( lhsType );
	assert( lhsType->fullTypeName );
	assert( !Gen_TypeIsScalar( lhsType ) );
	assert( rhsType );
	assert( rhsType->fullTypeName );
	assert( opStr );
	assert( commentStr );

	const char* rhsReferenceStr = rhsType && Gen_TypeIsScalar( rhsType ) ? "" : "&";

	StringBuilder_Append(  code, commentStr );
	StringBuilder_Appendf( code, "HLML_INLINE %s operator%s=( %s& lhs, const %s%s rhs )\n", returnType->fullTypeName, opStr, lhsType->fullTypeName, rhsType->fullTypeName, rhsReferenceStr );
	StringBuilder_Append(  code, "{\n" );
	StringBuilder_Appendf( code, "\treturn ( lhs = lhs %s rhs );\n", opStr );
	StringBuilder_Append(  code, "}\n\n" );
}

static void GenerateOperatorSingleParm( allocatorLinear_t* tempStorage, stringBuilder_t* code, const typeInfo_t* typeInfo, const char* opStr, const operatorSingleParmType_t type, const operatorSingleParmFlags_t flags, const char* commentStr ) {
	assert( tempStorage );
	assert( code );
	assert( typeInfo );
	assert( typeInfo->fullTypeName );
	assert( opStr );
	assert( commentStr );

	StringBuilder_Append( code, commentStr );

	u32 numIterations = Gen_TypeIsVector( typeInfo ) ? typeInfo->numCols : typeInfo->numRows;

	if ( type == OPERATOR_SINGLE_PARM_TYPE_PREFIX ) {
		if ( flags & OPERATOR_PREFIX_FLAG_RETURN_COPY ) {
			StringBuilder_Append(  code, "// pre-fix\n" );
			StringBuilder_Appendf( code, "HLML_INLINE %s operator%s( const %s& x )\n", typeInfo->fullTypeName, opStr, typeInfo->fullTypeName );
			StringBuilder_Append(  code, "{\n" );
			StringBuilder_Appendf( code, "\treturn %s(\n", typeInfo->fullTypeName );
			for ( u32 i = 0; i < numIterations; i++ ) {
				StringBuilder_Appendf( code, "\t\t%sx[%d]", opStr, i );

				if ( i != numIterations - 1 ) {
					StringBuilder_Append( code, "," );
				}

				StringBuilder_Append( code, "\n" );
			}
			StringBuilder_Append( code, "\t);\n" );
			StringBuilder_Append( code, "}\n\n" );
		} else {
			StringBuilder_Appendf( code, "HLML_INLINE %s operator%s( %s& x )\n", typeInfo->fullTypeName, opStr, typeInfo->fullTypeName );
			StringBuilder_Append(  code, "{\n" );
			for ( u32 i = 0; i < numIterations; i++ ) {
				StringBuilder_Appendf( code, "\t%sx[%d];\n", opStr, i );
			}
			StringBuilder_Append( code, "\treturn x;\n" );
			StringBuilder_Append( code, "}\n\n" );
		}
	} else {
		assert( ( flags & OPERATOR_PREFIX_FLAG_RETURN_COPY ) == 0 );

		StringBuilder_Append(  code, "// post-fix\n" );
		StringBuilder_Appendf( code, "HLML_INLINE %s operator%s( %s& x, const %s )\n", typeInfo->fullTypeName, opStr, typeInfo->fullTypeName, Gen_GetMemberTypeString( GEN_TYPE_INT ) );
		StringBuilder_Append(  code, "{\n" );
		for ( u32 i = 0; i < numIterations; i++ ) {
			StringBuilder_Appendf( code, "\tx[%d]%s;\n", i, opStr );
		}
		StringBuilder_Append( code, "\treturn x;\n" );
		StringBuilder_Append( code, "}\n\n" );
	}
}

static void GenerateComponentWiseFunction_Operator( allocatorLinear_t* tempStorage, stringBuilder_t* code, const typeInfo_t* returnType, const typeInfo_t* lhsType, const typeInfo_t* lhsMemberType, const typeInfo_t* rhsType, const char* funcStr, const char* memberFuncStr, const char* opStr, const char* commentStr ) {
	assert( tempStorage );
	assert( code );
	assert( returnType );
	assert( returnType->fullTypeName );
	assert( lhsType );
	assert( lhsType->fullTypeName );
	assert( !Gen_TypeIsScalar( lhsType ) );
	assert( lhsMemberType );
	assert( lhsMemberType->fullTypeName );
	assert( rhsType );
	assert( rhsType->fullTypeName );
	assert( funcStr );
	assert( memberFuncStr );
	assert( opStr );
	assert( commentStr );

	const char* parmPointerStr = Gen_TypeIsScalar( rhsType ) ? "" : "*";
	const char* referenceStr = Gen_TypeIsScalar( rhsType ) ? "." : "->";

	StringBuilder_Appendf( code, commentStr );
	StringBuilder_Appendf( code, "HLML_INLINE %s %s( const %s* lhs, const %s%s rhs )\n", returnType->fullTypeName, funcStr, lhsType->fullTypeName, rhsType->fullTypeName, parmPointerStr );
	StringBuilder_Append(  code, "{\n" );
	StringBuilder_Appendf( code, "\treturn HLML_CONSTRUCT( %s )\n", returnType->fullTypeName );
	StringBuilder_Append(  code, "\t{\n" );

	if ( Gen_TypeIsVector( lhsType ) ) {
		for ( u32 i = 0; i < returnType->numCols; i++ ) {
			const char componentName = GEN_COMPONENT_NAMES_VECTOR[i];

			StringBuilder_Appendf( code, "\t\tlhs->%c %s ", componentName, opStr );

			if ( Gen_TypeIsScalar( rhsType ) ) {
				StringBuilder_Append( code, "rhs" );
			} else {
				StringBuilder_Appendf( code, "rhs%s%c", referenceStr, componentName );
			}

			if ( i < returnType->numCols - 1 ) {
				StringBuilder_Append( code, "," );
			}

			StringBuilder_Append( code, "\n" );
		}
	} else {
		if ( Gen_TypeIsScalar( rhsType ) ) {
			for ( u32 i = 0; i < returnType->numRows; i++ ) {
				StringBuilder_Appendf( code, "\t\t%s( &lhs->rows[%d], rhs )", memberFuncStr, i );

				if ( i < returnType->numRows - 1 ) {
					StringBuilder_Append( code, "," );
				}

				StringBuilder_Append( code, "\n" );
			}
		} else if ( Gen_TypeIsVector( rhsType ) ) {
			for ( u32 i = 0; i < returnType->numRows; i++ ) {
				StringBuilder_Appendf( code, "\t\t%s( &lhs->rows[%d], rhs->%c )", memberFuncStr, i, GEN_COMPONENT_NAMES_VECTOR[i] );

				if ( i < returnType->numRows - 1 ) {
					StringBuilder_Append( code, "," );
				}

				StringBuilder_Append( code, "\n" );
			}
		} else {
			for ( u32 i = 0; i < returnType->numRows; i++ ) {
				StringBuilder_Appendf( code, "\t\t%s( &lhs->rows[%d], &rhs->rows[%d] )", memberFuncStr, i, i );

				if ( i < returnType->numRows - 1 ) {
					StringBuilder_Append( code, "," );
				}

				StringBuilder_Append( code, "\n" );
			}
		}
	}

	StringBuilder_Append( code, "\t};\n" );
	StringBuilder_Append( code, "}\n\n" );
}

static void GenerateComponentWiseFunction_OperatorSingleParm( allocatorLinear_t* tempStorage, stringBuilder_t* code, const typeInfo_t* typeInfo, const char* opName, const char* opStr, const operatorSingleParmType_t type, const generatorStrings_t* strings, const generatorFlags_t flags, const char* commentStr ) {
	assert( tempStorage );
	assert( code );
	assert( typeInfo );
	assert( typeInfo->fullTypeName );
	assert( !Gen_TypeIsScalar( typeInfo ) );
	assert( opName );
	assert( opStr );
	assert( strings );
	assert( commentStr );

	const char* funcStr = Gen_GetFuncName_Vector( tempStorage, typeInfo, flags, opName );

	StringBuilder_Append(  code, commentStr );
	StringBuilder_Appendf( code, "HLML_INLINE %s %s( const %s* x )\n", typeInfo->fullTypeName, funcStr, typeInfo->fullTypeName );
	StringBuilder_Append(  code, "{\n" );
	StringBuilder_Appendf( code, "\treturn HLML_CONSTRUCT( %s )\n", typeInfo->fullTypeName );
	StringBuilder_Append(  code, "\t{\n" );

	if ( Gen_TypeIsVector( typeInfo ) ) {
		if ( type == OPERATOR_SINGLE_PARM_TYPE_PREFIX ) {
			for ( u32 i = 0; i < typeInfo->numCols; i++ ) {
				StringBuilder_Appendf( code, "\t\t%sx%s%c", opStr, strings->parmAccessOperatorStr, GEN_COMPONENT_NAMES_VECTOR[i] );

				if ( i != typeInfo->numCols - 1 ) {
					StringBuilder_Append( code, "," );
				}

				StringBuilder_Append( code, "\n" );
			}
		} else {
			for ( u32 i = 0; i < typeInfo->numCols; i++ ) {
				StringBuilder_Appendf( code, "\t\tx%s%c%s", strings->parmAccessOperatorStr, GEN_COMPONENT_NAMES_VECTOR[i], opStr );

				if ( i != typeInfo->numCols - 1 ) {
					StringBuilder_Append( code, "," );
				}

				StringBuilder_Append( code, "\n" );
			}
		}
	} else {
		typeInfo_t memberType = {
			.type			= typeInfo->type,
			.numRows		= 1,
			.numCols		= typeInfo->numCols,
			.fullTypeName	= String_TPrintf( tempStorage, "%s%d", Gen_GetTypeString( memberType.type ), memberType.numCols )
		};

		const char* memberFuncStr = Gen_GetFuncName_Vector( tempStorage, &memberType, flags, opName );

		for ( u32 i = 0; i < typeInfo->numRows; i++ ) {
			StringBuilder_Appendf( code, "\t\t%s( &x->rows[%d] )", memberFuncStr, i );

			if ( i < typeInfo->numRows - 1 ) {
				StringBuilder_Append( code, "," );
			}

			StringBuilder_Append( code, "\n" );
		}
	}

	StringBuilder_Append( code, "\t};\n" );
	StringBuilder_Append( code, "}\n\n" );
}

// branching everywhere in this function due to 2 main factors:
//	- function parameters can come in any order so we cant sort them and take advantage of any optimisations there
//	- some functions access some parameters just as a whole and some functions access each component of some parameters, which means checking per parameter what you want to do with it
// if anyone knows ways of optimising this so we dont have to do so much branching then I would love to know about it
static void GenerateComponentWiseFunction( allocatorLinear_t* tempStorage, stringBuilder_t* code, const typeInfo_t* typeInfo, const char* funcName, const typeInfo_t* returnType, const typeInfo_t* memberTypeInfo, const generatorStrings_t* strings, const generatorFlags_t flags, const u32 parmsCount, const genFunctionParm_t* parms ) {
	assert( tempStorage );
	assert( code );
	assert( typeInfo );
	assert( !Gen_TypeIsScalar( typeInfo ) );
	assert( funcName );
	assert( returnType );
	assert( memberTypeInfo );
	assert( strings );
	assert( parmsCount );
	assert( parms );

	bool32 generateOperators = flags & GENERATOR_FLAG_GENERATE_OPERATORS;
	bool32 generateConstructors = flags & GENERATOR_FLAG_GENERATE_CONSTRUCTORS;

	const char* funcStr = Gen_GetFuncName_Vector( tempStorage, typeInfo, flags, funcName );

	const char* funcStrMember = NULL;
	if ( Gen_TypeIsScalar( memberTypeInfo ) ) {
		funcStrMember = Gen_GetFuncName_Scalar( tempStorage, memberTypeInfo->type, flags, funcName );
	} else {
		funcStrMember = Gen_GetFuncName_Vector( tempStorage, memberTypeInfo, flags, funcName );
	}

	u32 numIterations = 0;
	if ( Gen_TypeIsMatrix( returnType ) ) {
		numIterations = returnType->numRows;
	} else if ( Gen_TypeIsVector( returnType ) ) {
		numIterations = returnType->numCols;
	} else {
		assert( false && "The return type was a scalar up in this bitch\n" );
	}

	const char* componentDescStr = Gen_TypeIsVector( typeInfo ) ? "component" : "row";
	const char* typeDescSingular = Gen_TypeIsVector( typeInfo ) ? "vector" : "matrix";

	StringBuilder_Appendf( code, "// Performs a %s function on each %s of the %s.\n", funcStr, componentDescStr, typeDescSingular );
	StringBuilder_Appendf( code, "HLML_INLINE %s %s( ", returnType->fullTypeName, funcStr );
	for ( u32 i = 0; i < parmsCount; i++ ) {
		const genFunctionParm_t* parm = &parms[i];

		const char* parmPointerStr = Gen_TypeIsScalar( parm->typeInfo ) ? "" : strings->parmPassByStr;

		StringBuilder_Appendf( code, "const %s%s %s", parm->typeInfo->fullTypeName, parmPointerStr, parm->name );

		if ( i < parmsCount - 1 ) {
			StringBuilder_Appendf( code, ", " );
		}
	}
	StringBuilder_Append( code, " )\n" );

	StringBuilder_Append(  code, "{\n" );

	if ( generateConstructors ) {
		StringBuilder_Appendf( code, "\treturn %s(\n", returnType->fullTypeName );
	} else {
		StringBuilder_Appendf( code, "\treturn HLML_CONSTRUCT( %s )\n", returnType->fullTypeName );
		StringBuilder_Append(  code, "\t{\n" );
	}

	for ( u32 i = 0; i < numIterations; i++ ) {
		StringBuilder_Appendf( code, "\t\t%s( ", funcStrMember );

		for ( u32 parmIndex = 0; parmIndex < parmsCount; parmIndex++ ) {
			const genFunctionParm_t* parm = &parms[parmIndex];

			// if ( Gen_TypeIsScalar( typeInfo ) ) {
			if ( Gen_TypeIsScalar( parm->typeInfo ) ) {
				StringBuilder_Appendf( code, "%s", parm->name );
			} else {
				if ( Gen_TypeIsVector( parm->typeInfo ) ) {
					if ( generateOperators ) {
						StringBuilder_Appendf( code, "%s[%d]", parm->name, i );
					} else {
						StringBuilder_Appendf( code, "%s%s%c", parm->name, strings->parmAccessOperatorStr, GEN_COMPONENT_NAMES_VECTOR[i] );
					}
				} else if ( Gen_TypeIsMatrix( parm->typeInfo ) ) {
					if ( generateOperators ) {
						StringBuilder_Appendf( code, "%s[%d]", parm->name, i );
					} else {
						StringBuilder_Appendf( code, "%s%s%srows[%d]", strings->parmReferenceStr, parm->name, strings->parmAccessOperatorStr, i );
					}
				}
			}

			if ( parmIndex < parmsCount - 1 ) {
				StringBuilder_Append( code, ", " );
			}
		}

		StringBuilder_Append( code, " )" );

		if ( i < numIterations - 1 ) {
			StringBuilder_Append( code, "," );
		}

		StringBuilder_Append( code, "\n" );
	}

	if ( generateOperators ) {
		StringBuilder_Append( code, "\t);\n" );
	} else {
		StringBuilder_Append( code, "\t};\n" );
	}
	StringBuilder_Append( code, "}\n\n" );
}

static void GenerateComponentWiseFunctions( allocatorLinear_t* tempStorage, const typeInfo_t* typeInfo, const typeInfo_t* memberTypeInfo, stringBuilder_t* code, const generatorStrings_t* strings, const generatorFlags_t flags ) {
	assert( tempStorage );
	assert( typeInfo );
	assert( typeInfo->fullTypeName );
	assert( !Gen_TypeIsScalar( typeInfo ) );
	assert( memberTypeInfo );
	assert( memberTypeInfo->fullTypeName );
	assert( code );
	assert( strings );

	typeInfo_t returnTypeInt = {
		.type		= GEN_TYPE_INT,
		.numRows	= typeInfo->numRows,
		.numCols	= typeInfo->numCols
	};

	if ( Gen_TypeIsVector( &returnTypeInt ) ) {
		returnTypeInt.fullTypeName = String_TPrintf( tempStorage, "%s%d", Gen_GetTypeString( returnTypeInt.type ), returnTypeInt.numCols );
	} else if ( Gen_TypeIsMatrix( &returnTypeInt ) ) {
		returnTypeInt.fullTypeName = String_TPrintf( tempStorage, "%s%dx%d", Gen_GetTypeString( returnTypeInt.type ), returnTypeInt.numRows, returnTypeInt.numCols );
	} else {
		assert( false && "We got a scalar up in this bitch\n" );
	}

	typeInfo_t returnTypeBoolVector = {
		.type		= GEN_TYPE_BOOL,
		.numRows	= typeInfo->numRows,
		.numCols	= typeInfo->numCols
	};

	if ( Gen_TypeIsVector( &returnTypeBoolVector ) ) {
		returnTypeBoolVector.fullTypeName = String_TPrintf( tempStorage, "%s%d", Gen_GetTypeString( returnTypeBoolVector.type ), returnTypeBoolVector.numCols );
	} else if ( Gen_TypeIsMatrix( &returnTypeBoolVector ) ) {
		returnTypeBoolVector.fullTypeName = String_TPrintf( tempStorage, "%s%dx%d", Gen_GetTypeString( returnTypeBoolVector.type ), returnTypeBoolVector.numRows, returnTypeBoolVector.numCols );
	} else {
		assert( false && "We got a scalar up in this bitch\n" );
	}

	typeInfo_t returnTypeBoolScalar = {
		.type			= GEN_TYPE_BOOL,
		.numRows		= 1,
		.numCols		= 1,
		.fullTypeName	= Gen_GetMemberTypeString( returnTypeBoolScalar.type )
	};

	const typeInfo_t scalarType = {
		.type			= typeInfo->type,
		.numRows		= 1,
		.numCols		= 1,
		.fullTypeName	= Gen_GetMemberTypeString( typeInfo->type )
	};

	typeInfo_t memberType = {
		.type = typeInfo->type
	};

	bool32 typeIsVector = Gen_TypeIsVector( typeInfo );

	if ( typeIsVector ) {
		memberType.numRows = 1;
		memberType.numCols = 1;
		memberType.fullTypeName = Gen_GetTypeString( typeInfo->type );
	} else {
		memberType.numRows = 1;
		memberType.numCols = typeInfo->numRows;
		memberType.fullTypeName = String_TPrintf( tempStorage, "%s%d", Gen_GetTypeString( typeInfo->type ), typeInfo->numCols );
	}

	if ( typeInfo->type != GEN_TYPE_BOOL ) {
		if ( typeInfo->type != GEN_TYPE_UINT ) {
			GenerateComponentWiseFunction( tempStorage, code, typeInfo,
				GEN_FUNCTION_NAME_SIGN,
				&returnTypeInt,
				memberTypeInfo,
				strings,
				flags,
				1,
				(genFunctionParm_t[]) {
					{ typeInfo, "x" }
				}
			);
		}

		GenerateComponentWiseFunction( tempStorage, code, typeInfo,
			GEN_FUNCTION_NAME_MIN,
			typeInfo,
			memberTypeInfo,
			strings,
			flags,
			2,
			(genFunctionParm_t[]) {
				{ typeInfo, "x" },
				{ typeInfo, "y" }
			}
		);

		GenerateComponentWiseFunction( tempStorage, code, typeInfo,
			GEN_FUNCTION_NAME_MAX,
			typeInfo,
			memberTypeInfo,
			strings,
			flags,
			2,
			(genFunctionParm_t[]) {
				{ typeInfo, "x" },
				{ typeInfo, "y" }
			}
		);

		GenerateComponentWiseFunction( tempStorage, code, typeInfo,
			GEN_FUNCTION_NAME_CLAMP,
			typeInfo,
			memberTypeInfo,
			strings,
			flags,
			3,
			(genFunctionParm_t[]) {
				{ typeInfo, "x"    },
				{ typeInfo, "low"  },
				{ typeInfo, "high" }
			}
		);

		GenerateComponentWiseFunction( tempStorage, code, typeInfo,
			GEN_FUNCTION_NAME_SATURATE,
			typeInfo,
			memberTypeInfo,
			strings,
			flags,
			1,
			(genFunctionParm_t[]) {
				{ typeInfo, "x" }
			}
		);

		if ( Gen_TypeIsFloatingPoint( typeInfo->type ) ) {
			GenerateComponentWiseFunction( tempStorage, code, typeInfo,
				GEN_FUNCTION_NAME_LERP,
				typeInfo,
				memberTypeInfo,
				strings,
				flags,
				3,
				(genFunctionParm_t[]) {
					{  typeInfo,   "lhs" },
					{  typeInfo,   "rhs" },
					{ &scalarType, "t"   }
				}
			);
		}
	}
}

static const char* GetComment_ComponentWiseRelational( allocatorLinear_t* tempStorage, const char* opStr, const char* typeDescPlural ) {
	assert( opStr );
	assert( typeDescPlural );

	return String_TPrintf( tempStorage, "// Performs a component-wise '%s' check against the two %s and returns the result.\n", opStr, typeDescPlural );
}

static const char* GetComment_ComponentWiseArithmetic_Scalar( allocatorLinear_t* tempStorage, const char* opStr, const char* typeDescSingular ) {
	assert( opStr );
	assert( typeDescSingular );

	return String_TPrintf( tempStorage, "// Performs a component-wise %s on the %s by the scalar and returns the result.\n", opStr, typeDescSingular );
}

static const char* GetComment_CompoundComponentWiseArithmetic_Scalar( allocatorLinear_t* tempStorage, const char* opStr ) {
	assert( opStr );

	return String_TPrintf( tempStorage, "// Returns a copy of 'lhs' where each component has been %s'd against the scalar.\n", opStr );
}

static const char* GetComment_ComponentWiseArithmetic_Vector( allocatorLinear_t* tempStorage, const char* opStr, const char* typeDescPlural ) {
	assert( opStr );
	assert( typeDescPlural );

	return String_TPrintf( tempStorage, "// Performs a component-wise %s against the two %s and returns the result.\n", opStr, typeDescPlural );
}

static const char* GetComment_CompoundComponentWiseArithmetic_Vector( allocatorLinear_t* tempStorage, const char* opStr ) {
	assert( opStr );

	return String_TPrintf( tempStorage, "// Returns a copy of 'lhs' that has been component-wise %s'd against 'rhs'.\n", opStr );
}

static const char* GetComment_ComponentWiseIncrement( allocatorLinear_t* tempStorage, const char* opStr, const char* typeDescSingular ) {
	assert( opStr );
	assert( typeDescSingular );

	return String_TPrintf( tempStorage, "// %ss each component of the %s and returns the result.\n", opStr, typeDescSingular );
}

static const char* GetComment_ComponentWiseNegate( allocatorLinear_t* tempStorage, const char* typeDescSingular ) {
	assert( typeDescSingular );

	return String_TPrintf( tempStorage, "// Returns a copy of the %s that has been negated.\n", typeDescSingular );
}

static const char* GetComment_ComponentWiseBitwiseNot( allocatorLinear_t* tempStorage, const char* typeDescSingular ) {
	assert( tempStorage );
	assert( typeDescSingular );

	return String_TPrintf( tempStorage, "// Returns a copy of the %s where each component has been bitwise NOT'd.\n", typeDescSingular );
}

static const char* GetComment_ComponentWiseBitwise_Scalar( allocatorLinear_t* tempStorage, const genOpBitwise_t op, const char* typeDescSingular ) {
	assert( tempStorage );
	assert( op != GEN_OP_BITWISE_COUNT );
	assert( typeDescSingular );

	const char* opStr = Gen_GetOperatorBitwise( op );

	return String_TPrintf( tempStorage, "// Performs a component-wise bitwise %s on the %s by the scalar and returns the result.\n", opStr, typeDescSingular );
}

static const char* GetComment_CompoundComponentWiseBitwise_Scalar( allocatorLinear_t* tempStorage, const genOpBitwise_t op ) {
	assert( tempStorage );
	assert( op != GEN_OP_BITWISE_COUNT );

	const char* opStr = Gen_GetOperatorBitwise( op );

	return String_TPrintf( tempStorage, "// Returns a copy of 'lhs' where each component has been bitwise %s'd against the scalar.\n", opStr );
}

static const char* GetComment_ComponentWiseBitwise_Vector( allocatorLinear_t* tempStorage, const genOpBitwise_t op, const char* typeDescPlural ) {
	assert( tempStorage );
	assert( op != GEN_OP_BITWISE_COUNT );
	assert( typeDescPlural );

	const char* opStr = Gen_GetOperatorBitwise( op );

	return String_TPrintf( tempStorage, "// Performs a component-wise bitwise %s against the two %s and returns the result.\n", opStr, typeDescPlural );
}

static const char* GetComment_CompoundComponentWiseBitwise_Vector( allocatorLinear_t* tempStorage, const genOpBitwise_t op ) {
	assert( tempStorage );
	assert( op != GEN_OP_BITWISE_COUNT );

	const char* opStr = Gen_GetOperatorBitwise( op );

	return String_TPrintf( tempStorage, "// Returns a copy of 'lhs' that has been component-wise bitwise %s'd against 'rhs'.\n", opStr );
}

static void GenerateComponentWiseOperators( allocatorLinear_t* tempStorage, const typeInfo_t* typeInfo, stringBuilder_t* code, const generatorStrings_t* strings, const generatorFlags_t flags ) {
	assert( tempStorage );
	assert( typeInfo );
	assert( typeInfo->fullTypeName );
	assert( code );
	assert( strings );

	typeInfo_t returnTypeBoolVector = {
		.type		= GEN_TYPE_BOOL,
		.numRows	= typeInfo->numRows,
		.numCols	= typeInfo->numCols
	};

	if ( Gen_TypeIsVector( &returnTypeBoolVector ) ) {
		returnTypeBoolVector.fullTypeName = String_TPrintf( tempStorage, "%s%d", Gen_GetTypeString( returnTypeBoolVector.type ), returnTypeBoolVector.numCols );
	} else if ( Gen_TypeIsMatrix( &returnTypeBoolVector ) ) {
		returnTypeBoolVector.fullTypeName = String_TPrintf( tempStorage, "%s%dx%d", Gen_GetTypeString( returnTypeBoolVector.type ), returnTypeBoolVector.numRows, returnTypeBoolVector.numCols );
	} else {
		assert( false && "We got a scalar up in this bitch\n" );
	}

	typeInfo_t scalarType = Gen_GetScalarType( typeInfo );

	typeInfo_t memberType = {
		.type = typeInfo->type
	};

	bool32 typeIsVector = Gen_TypeIsVector( typeInfo );

	if ( typeIsVector ) {
		memberType.numRows = 1;
		memberType.numCols = 1;
		memberType.fullTypeName = Gen_GetTypeString( typeInfo->type );
	} else {
		memberType.numRows = 1;
		memberType.numCols = typeInfo->numRows;
		memberType.fullTypeName = String_TPrintf( tempStorage, "%s%d", Gen_GetTypeString( typeInfo->type ), typeInfo->numCols );
	}

	const char* commentStr = NULL;

	const char* typeDescSingular = Gen_TypeIsVector( typeInfo ) ? "vector" : "matrix";
	const char* typeDescPlural = Gen_TypeIsVector( typeInfo ) ? "vectors" : "matrices";

	GenerateFunction_Equals( tempStorage, typeInfo, code, flags );
	GenerateFunction_NotEquals( tempStorage, typeInfo, code, flags );

	if ( flags & GENERATOR_FLAG_GENERATE_OPERATORS ) {
		for ( u32 opIndex = 0; opIndex < GEN_OP_RELATIONAL_COUNT; opIndex++ ) {
			const genOpRelational_t op = (genOpRelational_t) opIndex;

			const char* opStr = Gen_GetOperatorRelational( op );

			commentStr = GetComment_ComponentWiseRelational( tempStorage, opStr, typeDescPlural );

			GenerateComponentWiseOperator( tempStorage, code, &returnTypeBoolVector, typeInfo, typeInfo, opStr, commentStr );
		}

		for ( u32 opIndex = 0; opIndex < GEN_OP_ARITHMETIC_COUNT; opIndex++ ) {
			const genOpArithmetic_t op = (genOpArithmetic_t) opIndex;

			const char* opStr = Gen_GetOperatorArithmetic( op );

			{
				commentStr = GetComment_ComponentWiseArithmetic_Scalar( tempStorage, opStr, typeDescSingular );

				GenerateComponentWiseOperator( tempStorage, code, typeInfo, typeInfo, &scalarType, opStr, commentStr );

				commentStr = GetComment_CompoundComponentWiseArithmetic_Scalar( tempStorage, opStr );

				GenerateCompundComponentWiseOperator( tempStorage, code, typeInfo, typeInfo, &scalarType, opStr, commentStr );
			}

			{
				commentStr = GetComment_ComponentWiseArithmetic_Vector( tempStorage, opStr, typeDescPlural );

				GenerateComponentWiseOperator( tempStorage, code, typeInfo, typeInfo, typeInfo, opStr, commentStr );

				commentStr = GetComment_CompoundComponentWiseArithmetic_Vector( tempStorage, opStr );

				GenerateCompundComponentWiseOperator( tempStorage, code, typeInfo, typeInfo, typeInfo, opStr, commentStr );
			}
		}

		for ( u32 opIndex = 0; opIndex < GEN_OP_INCREMENT_COUNT; opIndex++ ) {
			const genOpIncrement_t op = (genOpIncrement_t) opIndex;

			const char* opStr = Gen_GetOperatorIncrement( op );

			commentStr = GetComment_ComponentWiseIncrement( tempStorage, opStr, typeDescSingular );

			GenerateOperatorSingleParm( tempStorage, code, typeInfo, opStr, OPERATOR_SINGLE_PARM_TYPE_PREFIX, 0, commentStr );
			GenerateOperatorSingleParm( tempStorage, code, typeInfo, opStr, OPERATOR_SINGLE_PARM_TYPE_POSTFIX, 0, commentStr );
		}

		if ( typeInfo->type != GEN_TYPE_BOOL ) {
			commentStr = GetComment_ComponentWiseNegate( tempStorage, typeDescSingular );
			GenerateOperatorSingleParm( tempStorage, code, typeInfo, "-", OPERATOR_SINGLE_PARM_TYPE_PREFIX, OPERATOR_PREFIX_FLAG_RETURN_COPY, commentStr );
		}

		if ( Gen_TypeIsInteger( typeInfo->type ) ) {
			for ( u32 opIndex = 0; opIndex < GEN_OP_BITWISE_COUNT; opIndex++ ) {
				const genOpBitwise_t op = (genOpBitwise_t) opIndex;

				const char* opStr = Gen_GetOperatorBitwise( op );

				// unary is separate because the function body is different
				if ( op == GEN_OP_BITWISE_UNARY ) {
					commentStr = GetComment_ComponentWiseBitwiseNot( tempStorage, typeDescSingular );

					GenerateOperatorSingleParm( tempStorage, code, typeInfo, opStr, OPERATOR_SINGLE_PARM_TYPE_PREFIX, OPERATOR_PREFIX_FLAG_RETURN_COPY, commentStr );
					continue;
				}

				{
					commentStr = GetComment_ComponentWiseBitwise_Scalar( tempStorage, op, typeDescSingular );

					GenerateComponentWiseOperator( tempStorage, code, typeInfo, typeInfo, &scalarType, opStr, commentStr );

					commentStr = GetComment_CompoundComponentWiseBitwise_Scalar( tempStorage, op );

					GenerateCompundComponentWiseOperator( tempStorage, code, typeInfo, typeInfo, &scalarType, opStr, commentStr );
				}

				{
					commentStr = GetComment_ComponentWiseBitwise_Vector( tempStorage, op, typeDescPlural );

					GenerateComponentWiseOperator( tempStorage, code, typeInfo, typeInfo, typeInfo, opStr, commentStr );

					commentStr = GetComment_CompoundComponentWiseBitwise_Vector( tempStorage, op );

					GenerateCompundComponentWiseOperator( tempStorage, code, typeInfo, typeInfo, typeInfo, opStr, commentStr );
				}
			}
		}
	} else {
		for ( u32 opIndex = 0; opIndex < GEN_OP_RELATIONAL_COUNT; opIndex++ ) {
			const genOpRelational_t op = (genOpRelational_t) opIndex;

			const char* funcName = Gen_GetFuncName_VectorRelational( tempStorage, typeInfo, op );
			const char* opStr = Gen_GetOperatorRelational( op );
			const char* memberFuncStr = Gen_GetFuncName_VectorRelational( tempStorage, &memberType, op );

			commentStr = GetComment_ComponentWiseRelational( tempStorage, opStr, typeDescPlural );

			GenerateComponentWiseFunction_Operator( tempStorage, code, &returnTypeBoolVector, typeInfo, &memberType, typeInfo, funcName, memberFuncStr, opStr, commentStr );
		}

		for ( u32 opIndex = 0; opIndex < GEN_OP_ARITHMETIC_COUNT; opIndex++ ) {
			const genOpArithmetic_t op = (genOpArithmetic_t) opIndex;

			const char* funcName = NULL;
			const char* opStr = Gen_GetOperatorArithmetic( op );

			const char* memberFuncStrScalar = String_TPrintf( tempStorage, "%s_c%ss", memberType.fullTypeName, Gen_GetArithmeticName( op ) );
			const char* memberFuncStrVector = String_TPrintf( tempStorage, "%s_c%sv", memberType.fullTypeName, Gen_GetArithmeticName( op ) );

			funcName = Gen_GetFuncName_VectorArithmeticScalar( tempStorage, typeInfo, op );

			commentStr = GetComment_ComponentWiseArithmetic_Scalar( tempStorage, opStr, typeDescSingular );

			GenerateComponentWiseFunction_Operator( tempStorage, code, typeInfo, typeInfo, &memberType, &scalarType, funcName, memberFuncStrScalar, opStr, commentStr );

			if ( typeIsVector ) {
				funcName = Gen_GetFuncName_VectorArithmeticVector( tempStorage, typeInfo, op );
			} else {
				funcName = Gen_GetFuncName_VectorArithmeticMatrix( tempStorage, typeInfo, op );
			}

			commentStr = GetComment_ComponentWiseArithmetic_Vector( tempStorage, opStr, typeDescPlural );

			GenerateComponentWiseFunction_Operator( tempStorage, code, typeInfo, typeInfo, &memberType, typeInfo, funcName, memberFuncStrVector, opStr, commentStr );
		}

		if ( typeInfo->type != GEN_TYPE_BOOL ) {
			commentStr = GetComment_ComponentWiseNegate( tempStorage, typeDescSingular );
			GenerateComponentWiseFunction_OperatorSingleParm( tempStorage, code, typeInfo, "negate", "-", OPERATOR_SINGLE_PARM_TYPE_PREFIX, strings, flags, commentStr );
		}

		if ( Gen_TypeIsInteger( typeInfo->type ) ) {
			for ( u32 opIndex = 0; opIndex < GEN_OP_BITWISE_COUNT; opIndex++ ) {
				const genOpBitwise_t op = (genOpBitwise_t) opIndex;

				const char* opName = Gen_GetBitwiseName( op );
				const char* opStr = Gen_GetOperatorBitwise( op );

				if ( op == GEN_OP_BITWISE_UNARY ) {
					// unary is separate because the function body is different
					commentStr = GetComment_ComponentWiseBitwiseNot( tempStorage, typeDescSingular );

					//GenerateFunction_BitwiseUnary( tempStorage, typeInfo, code, flags, commentStr );
					GenerateComponentWiseFunction_OperatorSingleParm( tempStorage, code, typeInfo, opName, opStr, OPERATOR_SINGLE_PARM_TYPE_PREFIX, strings, flags, commentStr );
					continue;
				}

				const char* funcName = NULL;

				const char* memberFuncStrScalar = String_TPrintf( tempStorage, "%s_c%ss", memberType.fullTypeName, Gen_GetBitwiseName( op ) );
				const char* memberFuncStrVector = String_TPrintf( tempStorage, "%s_c%sv", memberType.fullTypeName, Gen_GetBitwiseName( op ) );

				funcName = Gen_GetFuncName_VectorBitwiseScalar( tempStorage, typeInfo, op );

				commentStr = GetComment_ComponentWiseBitwise_Scalar( tempStorage, op, typeDescSingular );

				GenerateComponentWiseFunction_Operator( tempStorage, code, typeInfo, typeInfo, &memberType, &scalarType, funcName, memberFuncStrScalar, opStr, commentStr );

				if ( typeIsVector ) {
					funcName = Gen_GetFuncName_VectorBitwiseVector( tempStorage, typeInfo, op );
				} else {
					funcName = Gen_GetFuncName_VectorBitwiseMatrix( tempStorage, typeInfo, op );
				}

				commentStr = GetComment_ComponentWiseBitwise_Vector( tempStorage, op, typeDescPlural );

				GenerateComponentWiseFunction_Operator( tempStorage, code, typeInfo, typeInfo, &memberType, typeInfo, funcName, memberFuncStrVector, opStr, commentStr );
			}
		}
	}
}
#include <math.h>

#if GENERATE_TEMPLATES
#include <ctype.h>
#endif

typedef void ( *generateSwizzleFunc_t )( allocatorLinear_t* tempStorage, stringBuilder_t* code, const typeInfo_t* typeInfo, const generatorStrings_t* strings, const generatorFlags_t flags, const u32 numSwizzleComponents, const char* swizzleStr );

// not really a "component-wise" function in the common sense, just so happens to use touch all of them
static void GenerateFunction_All( allocatorLinear_t* tempStorage, const typeInfo_t* typeInfo, stringBuilder_t* code, const generatorFlags_t flags ) {
	assert( tempStorage );
	assert( typeInfo );
	assert( code );

	if ( typeInfo->type != GEN_TYPE_BOOL ) {
		return;
	}

	const char* allFuncStr = Gen_GetFuncName_Vector( tempStorage, typeInfo, flags, GEN_FUNCTION_NAME_ALL );

	StringBuilder_Append(  code, "// Returns true if ALL components of the 'x' are true, otherwise returns false.\n" );
	StringBuilder_Appendf( code, "HLML_INLINE bool %s( const %s* x )\n", allFuncStr, typeInfo->fullTypeName );
	StringBuilder_Append(  code, "{\n" );
	StringBuilder_Append(  code, "\treturn " );

	for ( u32 i = 0; i < typeInfo->numCols; i++ ) {
		StringBuilder_Appendf( code, "x->%c", GEN_COMPONENT_NAMES_VECTOR[i] );

		if ( i != typeInfo->numCols - 1 ) {
			StringBuilder_Append( code, " && " );
		}
	}

	StringBuilder_Append( code, ";\n}\n\n" );
}

static void GenerateFunction_Any( allocatorLinear_t* tempStorage, const typeInfo_t* typeInfo, stringBuilder_t* code, const generatorFlags_t flags ) {
	assert( tempStorage );
	assert( typeInfo );
	assert( code );

	if ( typeInfo->type != GEN_TYPE_BOOL ) {
		return;
	}

	const char* anyFuncStr = Gen_GetFuncName_Vector( tempStorage, typeInfo, flags, GEN_FUNCTION_NAME_ANY );

	StringBuilder_Append(  code, "// Returns true if ANY one component of 'x' is true, otherwise returns false.\n" );
	StringBuilder_Appendf( code, "HLML_INLINE bool %s( const %s* x )\n", anyFuncStr, typeInfo->fullTypeName );
	StringBuilder_Append(  code, "{\n" );
	StringBuilder_Append(  code, "\treturn " );

	for ( u32 i = 0; i < typeInfo->numCols; i++ ) {
		StringBuilder_Appendf( code, "x->%c", GEN_COMPONENT_NAMES_VECTOR[i] );

		if ( i != typeInfo->numCols - 1 ) {
			StringBuilder_Append( code, " || " );
		}
	}

	StringBuilder_Append( code, ";\n}\n\n" );
}

static void GenerateFunction_LengthSqr( allocatorLinear_t* tempStorage, const typeInfo_t* typeInfo, stringBuilder_t* code, const generatorStrings_t* strings, const generatorFlags_t flags ) {
	assert( tempStorage );
	assert( typeInfo );
	assert( code );
	assert( strings );

	if ( typeInfo->type == GEN_TYPE_BOOL ) {
		return;
	}

	genType_t floatingPointType = Gen_GetSupportedFloatingPointType( typeInfo->type );

	const char* returnTypeName = Gen_GetMemberTypeString( floatingPointType );

	const char* lengthsqrFuncStr = Gen_GetFuncName_Vector( tempStorage, typeInfo, flags, GEN_FUNCTION_NAME_LENGTHSQ );

	bool32 shouldTypecast = !Gen_TypeIsFloatingPoint( typeInfo->type );

	StringBuilder_Append(  code, "// Returns the magnitude of vector squared.\n" );
	StringBuilder_Appendf( code, "HLML_INLINE %s %s( const %s%s vec )\n", returnTypeName, lengthsqrFuncStr, typeInfo->fullTypeName, strings->parmPassByStr );
	StringBuilder_Append(  code, "{\n" );
	StringBuilder_Append(  code, "\treturn " );

	if ( shouldTypecast ) {
		StringBuilder_Appendf( code, "(%s)( ", returnTypeName );
	}

	for ( u32 i = 0; i < typeInfo->numCols; i++ ) {
		char componentName = GEN_COMPONENT_NAMES_VECTOR[i];

		StringBuilder_Appendf( code, "( vec%s%c * vec%s%c )", strings->parmAccessOperatorStr, componentName, strings->parmAccessOperatorStr, componentName );

		if ( i != typeInfo->numCols - 1 ) {
			StringBuilder_Append( code, " + " );
		}
	}

	if ( shouldTypecast ) {
		StringBuilder_Append( code, " )" );
	}

	StringBuilder_Append( code, ";\n" );
	StringBuilder_Append( code, "}\n\n" );
}

static void GenerateFunction_Length( allocatorLinear_t* tempStorage, const typeInfo_t* typeInfo, stringBuilder_t* code, const generatorStrings_t* strings, const generatorFlags_t flags ) {
	assert( tempStorage );
	assert( typeInfo );
	assert( code );
	assert( strings );

	if ( typeInfo->type == GEN_TYPE_BOOL ) {
		return;
	}

	genType_t floatingPointType = Gen_GetSupportedFloatingPointType( typeInfo->type );

	const char* returnTypeName = Gen_GetMemberTypeString( floatingPointType );

	const char* lengthFuncStr = Gen_GetFuncName_Vector( tempStorage, typeInfo, flags, GEN_FUNCTION_NAME_LENGTH );
	const char* lengthsqFuncStr = Gen_GetFuncName_Vector( tempStorage, typeInfo, flags, GEN_FUNCTION_NAME_LENGTHSQ );

	const char* sqrtFuncStr = Gen_GetBuiltinFunction( tempStorage, typeInfo->type, GEN_BUILTIN_FUNCTION_NAME_SQRT );

	StringBuilder_Append(  code, "// Returns the magnitude of the vector.\n" );
	StringBuilder_Appendf( code, "HLML_INLINE %s %s( const %s%s vec )\n", returnTypeName, lengthFuncStr, typeInfo->fullTypeName, strings->parmPassByStr );
	StringBuilder_Append(  code, "{\n" );
	StringBuilder_Appendf( code, "\treturn %s( %s( vec ) );\n", sqrtFuncStr, lengthsqFuncStr );
	StringBuilder_Append(  code, "}\n\n" );
}

static void GenerateFunction_Normalize( allocatorLinear_t* tempStorage, const typeInfo_t* typeInfo, stringBuilder_t* code, const generatorStrings_t* strings, const generatorFlags_t flags ) {
	assert( tempStorage );
	assert( typeInfo );
	assert( code );
	assert( strings );

	if ( !Gen_TypeIsFloatingPoint( typeInfo->type ) ) {
		return;
	}

	const char* normalizeFuncStr = Gen_GetFuncName_Vector( tempStorage, typeInfo, flags, GEN_FUNCTION_NAME_NORMALIZE );
	const char* lengthFuncStr = Gen_GetFuncName_Vector( tempStorage, typeInfo, flags, GEN_FUNCTION_NAME_LENGTH );

	const char* mulStr = Gen_GetFuncName_VectorArithmeticScalar( tempStorage, typeInfo, GEN_OP_ARITHMETIC_MUL );

	const char* memberTypeString = Gen_GetMemberTypeString( typeInfo->type );

	const char* oneStr = Gen_GetNumericLiteral( tempStorage, typeInfo->type, 1.0f, 1 );

	StringBuilder_Append(  code, "// Normalizes the vector.\n" );
	StringBuilder_Appendf( code, "HLML_INLINE void %s( %s%s vec )\n", normalizeFuncStr, typeInfo->fullTypeName, strings->parmPassByStr );
	StringBuilder_Append(  code, "{\n" );
	StringBuilder_Appendf( code, "\t%s invlen = %s / %s( vec );\n", memberTypeString, oneStr, lengthFuncStr );
	StringBuilder_Append(  code, "\n" );
	if ( flags & GENERATOR_FLAG_GENERATE_OPERATORS ) {
		StringBuilder_Appendf( code, "\t%svec %s= invlen;\n", strings->parmDereferenceStr, Gen_GetOperatorArithmetic( GEN_OP_ARITHMETIC_MUL ) );
	} else {
		StringBuilder_Appendf( code, "\t%svec = %s( vec, invlen );\n", strings->parmDereferenceStr, mulStr );
	}
	StringBuilder_Append(  code, "}\n\n" );
}

static void GenerateFunction_Normalized( allocatorLinear_t* tempStorage, const typeInfo_t* typeInfo, stringBuilder_t* code, const generatorStrings_t* strings, const generatorFlags_t flags ) {
	assert( tempStorage );
	assert( typeInfo );
	assert( code );
	assert( strings );

	if ( !Gen_TypeIsFloatingPoint( typeInfo->type ) ) {
		return;
	}

	const char* normalizedFuncStr = Gen_GetFuncName_Vector( tempStorage, typeInfo, flags, GEN_FUNCTION_NAME_NORMALIZED );
	const char* lengthFuncStr = Gen_GetFuncName_Vector( tempStorage, typeInfo, flags, GEN_FUNCTION_NAME_LENGTH );

	const char* memberTypeString = Gen_GetMemberTypeString( typeInfo->type );

	const char* oneStr = Gen_GetNumericLiteral( tempStorage, typeInfo->type, 1.0f, 1 );

	const char* mulStr = Gen_GetFuncName_VectorArithmeticScalar( tempStorage, typeInfo, GEN_OP_ARITHMETIC_MUL );

	StringBuilder_Append(  code, "// Returns a normalized copy of the vector.\n" );
	StringBuilder_Appendf( code, "HLML_INLINE %s %s( const %s%s vec )\n", typeInfo->fullTypeName, normalizedFuncStr, typeInfo->fullTypeName, strings->parmPassByStr );
	StringBuilder_Append(  code, "{\n" );
	StringBuilder_Appendf( code, "\t%s invlen = %s / %s( vec );\n", memberTypeString, oneStr, lengthFuncStr );
	StringBuilder_Append(  code, "\n" );
	if ( flags & GENERATOR_FLAG_GENERATE_OPERATORS ) {
		StringBuilder_Appendf( code, "\treturn vec %s invlen;\n", Gen_GetOperatorArithmetic( GEN_OP_ARITHMETIC_MUL ) );
	} else {
		StringBuilder_Appendf( code, "\treturn %s( vec, invlen );\n", mulStr );
	}
	StringBuilder_Append(  code, "}\n\n" );
}

static void GenerateFunction_Dot( allocatorLinear_t* tempStorage, const typeInfo_t* typeInfo, stringBuilder_t* code, const generatorStrings_t* strings, const generatorFlags_t flags ) {
	assert( tempStorage );
	assert( typeInfo );
	assert( code );
	assert( strings );

	if ( typeInfo->type == GEN_TYPE_BOOL ) {
		return;
	}

	// bool32 isUint = typeInfo->type == GEN_TYPE_UINT;

	// // dot can return negative values, so uint vectors have to return signed int
	// genType_t returnType = isUint ? GEN_TYPE_INT : typeInfo->type;
	// const char* returnTypeString = Gen_GetMemberTypeString( returnType );

	// bool32 shouldTypecast = returnType != typeInfo->type;

	const char* returnTypeString = Gen_GetMemberTypeString( typeInfo->type );

	const char* dotFuncStr = Gen_GetFuncName_Vector( tempStorage, typeInfo, flags, GEN_FUNCTION_NAME_DOT );

	StringBuilder_Append(  code, "// Returns the dot product of the two vectors.\n" );
	StringBuilder_Appendf( code, "HLML_INLINE %s %s( const %s%s lhs, const %s%s rhs )\n", returnTypeString, dotFuncStr, typeInfo->fullTypeName, strings->parmPassByStr, typeInfo->fullTypeName, strings->parmPassByStr );
	StringBuilder_Append(  code, "{\n" );
	StringBuilder_Append(  code, "\treturn " );

	// if ( shouldTypecast ) {
	// 	StringBuilder_Appendf( code, "(%s)( ", returnTypeString );
	// }

	for ( u32 i = 0; i < typeInfo->numCols; i++ ) {
		char componentName = GEN_COMPONENT_NAMES_VECTOR[i];

		StringBuilder_Appendf( code, "( lhs%s%c * rhs%s%c )", strings->parmAccessOperatorStr, componentName, strings->parmAccessOperatorStr, componentName );

		if ( i != typeInfo->numCols - 1 ) {
			StringBuilder_Append( code, " + " );
		}
	}

	// if ( shouldTypecast ) {
	// 	StringBuilder_Append( code, " )" );
	// }

	StringBuilder_Append( code, ";\n" );
	StringBuilder_Append( code, "}\n\n" );
}

static void GenerateFunction_Cross( allocatorLinear_t* tempStorage, const typeInfo_t* typeInfo, stringBuilder_t* code, const generatorStrings_t* strings, const generatorFlags_t flags ) {
	assert( tempStorage );
	assert( typeInfo );
	assert( code );
	assert( strings );

	if ( !Gen_TypeIsFloatingPoint( typeInfo->type ) ) {
		return;
	}

	if ( typeInfo->numCols != 3 ) {
		return;
	}

	const char* crossFuncStr = Gen_GetFuncName_Vector( tempStorage, typeInfo, flags, GEN_FUNCTION_NAME_CROSS );

	StringBuilder_Append(  code, "// Returns a vector perpendicular to the two vectors.\n" );
	StringBuilder_Appendf( code, "HLML_INLINE %s %s( const %s%s lhs, const %s%s rhs )\n", typeInfo->fullTypeName, crossFuncStr, typeInfo->fullTypeName, strings->parmPassByStr, typeInfo->fullTypeName, strings->parmPassByStr );
	StringBuilder_Append(  code, "{\n" );
	StringBuilder_Appendf( code, "\treturn HLML_CONSTRUCT( %s )\n", typeInfo->fullTypeName );
	StringBuilder_Append(  code, "\t{\n" );
	StringBuilder_Appendf( code, "\t\t( lhs%sy * rhs%sz ) - ( lhs%sz * rhs%sy ),\n", strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr );
	StringBuilder_Appendf( code, "\t\t( lhs%sz * rhs%sx ) - ( lhs%sx * rhs%sz ),\n", strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr );
	StringBuilder_Appendf( code, "\t\t( lhs%sx * rhs%sy ) - ( lhs%sy * rhs%sx )", strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr );
	if ( typeInfo->numCols > 3 ) {
		StringBuilder_Appendf( code, ",\n\t\t%s\n", Gen_GetNumericLiteral( tempStorage, typeInfo->type, 0.0f, 1 ) );
	} else {
		StringBuilder_Append( code, "\n" );
	}
	StringBuilder_Append( code, "\t};\n" );
	StringBuilder_Append( code, "}\n\n" );
}

static void GenerateFunction_Angle( allocatorLinear_t* tempStorage, const typeInfo_t* typeInfo, stringBuilder_t* code, const generatorStrings_t* strings, const generatorFlags_t flags ) {
	assert( tempStorage );
	assert( typeInfo );
	assert( code );
	assert( strings );

	if ( !Gen_TypeIsFloatingPoint( typeInfo->type ) ) {
		return;
	}

	genType_t floatingPointType = Gen_GetSupportedFloatingPointType( typeInfo->type );

	const char* returnTypeString = Gen_GetMemberTypeString( floatingPointType );

	const char* angleFuncStr = Gen_GetFuncName_Vector( tempStorage, typeInfo, flags, GEN_FUNCTION_NAME_ANGLE );
	const char* normalizedFuncStr = Gen_GetFuncName_Vector( tempStorage, typeInfo, flags, GEN_FUNCTION_NAME_NORMALIZED );
	const char* degreesFuncStr = Gen_GetFuncName_Scalar( tempStorage, typeInfo->type, flags, GEN_FUNCTION_NAME_DEGREES );
	const char* dotFuncStr = Gen_GetFuncName_Vector( tempStorage, typeInfo, flags, GEN_FUNCTION_NAME_DOT );
	const char* acosFuncStr = Gen_GetBuiltinFunction( tempStorage, typeInfo->type, GEN_BUILTIN_FUNCTION_NAME_ACOS );

	StringBuilder_Append(  code, "// Returns the angle (in degrees) between the two vectors.\n" );
	StringBuilder_Appendf( code, "HLML_INLINE %s %s( const %s%s lhs, const %s%s rhs )\n", returnTypeString, angleFuncStr, typeInfo->fullTypeName, strings->parmPassByStr, typeInfo->fullTypeName, strings->parmPassByStr );
	StringBuilder_Append(  code, "{\n" );
	if ( flags & GENERATOR_FLAG_PARMS_ARE_POINTERS ) {
		StringBuilder_Appendf( code, "\t%s lhs_unit = %s( lhs );\n", typeInfo->fullTypeName, normalizedFuncStr );
		StringBuilder_Appendf( code, "\t%s rhs_unit = %s( rhs );\n", typeInfo->fullTypeName, normalizedFuncStr );
		StringBuilder_Appendf( code, "\treturn %s( %s( %s( &lhs_unit, &rhs_unit ) ) );\n", degreesFuncStr, acosFuncStr, dotFuncStr );
	} else {
		StringBuilder_Appendf( code, "\treturn %s( %s( %s( %s( lhs ), %s( rhs ) ) ) );\n", degreesFuncStr, acosFuncStr, dotFuncStr, normalizedFuncStr, normalizedFuncStr );
	}
	StringBuilder_Append(  code, "}\n\n" );
}

static void GenerateFunction_Distancesq( allocatorLinear_t* tempStorage, const typeInfo_t* typeInfo, stringBuilder_t* code, const generatorStrings_t* strings, const generatorFlags_t flags ) {
	assert( tempStorage );
	assert( typeInfo );
	assert( code );
	assert( strings );

	if ( typeInfo->type == GEN_TYPE_BOOL ) {
		return;
	}

	if ( typeInfo->numCols > 3 ) {
		return;
	}

	const char* returnTypeName = Gen_GetTypeString( Gen_GetSupportedFloatingPointType( typeInfo->type ) );

	const char* distancesqFuncStr = Gen_GetFuncName_Vector( tempStorage, typeInfo, flags, GEN_FUNCTION_NAME_DISTANCESQ );
	const char* lengthsqFuncStr = Gen_GetFuncName_Vector( tempStorage, typeInfo, flags, GEN_FUNCTION_NAME_LENGTHSQ );

	StringBuilder_Append(  code, "// Returns the squared distance between the two vectors.\n" );
	StringBuilder_Appendf( code, "HLML_INLINE %s %s( const %s%s lhs, const %s%s rhs )\n", returnTypeName, distancesqFuncStr, typeInfo->fullTypeName, strings->parmPassByStr, typeInfo->fullTypeName, strings->parmPassByStr );
	StringBuilder_Append(  code, "{\n" );
	if ( flags & GENERATOR_FLAG_GENERATE_OPERATORS ) {
		StringBuilder_Appendf( code, "\treturn %s( lhs - rhs );\n", lengthsqFuncStr );
	} else {
		const char* subFuncStr = Gen_GetFuncName_VectorArithmeticVector( tempStorage, typeInfo, GEN_OP_ARITHMETIC_SUB );

		StringBuilder_Appendf( code, "\t%s delta = %s( lhs, rhs );\n", typeInfo->fullTypeName, subFuncStr );
		StringBuilder_Appendf( code, "\treturn %s( &delta );\n", lengthsqFuncStr );
	}
	StringBuilder_Append(  code, "}\n\n" );
}

static void GenerateFunction_Distance( allocatorLinear_t* tempStorage, const typeInfo_t* typeInfo, stringBuilder_t* code, const generatorStrings_t* strings, const generatorFlags_t flags ) {
	assert( tempStorage );
	assert( typeInfo );
	assert( code );
	assert( strings );

	if ( typeInfo->type == GEN_TYPE_BOOL ) {
		return;
	}

	if ( typeInfo->numCols > 3 ) {
		return;
	}

	const char* returnTypeName = Gen_GetMemberTypeString( Gen_GetSupportedFloatingPointType( typeInfo->type ) );

	const char* distancesqFuncStr = Gen_GetFuncName_Vector( tempStorage, typeInfo, flags, GEN_FUNCTION_NAME_DISTANCE );
	const char* lengthFuncStr = Gen_GetFuncName_Vector( tempStorage, typeInfo, flags, GEN_FUNCTION_NAME_LENGTH );

	StringBuilder_Append(  code, "// Returns the distance between the two vectors.\n" );
	StringBuilder_Appendf( code, "HLML_INLINE %s %s( const %s%s lhs, const %s%s rhs )\n", returnTypeName, distancesqFuncStr, typeInfo->fullTypeName, strings->parmPassByStr, typeInfo->fullTypeName, strings->parmPassByStr );
	StringBuilder_Append(  code, "{\n" );
	if ( flags & GENERATOR_FLAG_GENERATE_OPERATORS ) {
		StringBuilder_Appendf( code, "\treturn %s( lhs - rhs );\n", lengthFuncStr );

	} else {
		const char* subFuncStr = Gen_GetFuncName_VectorArithmeticVector( tempStorage, typeInfo, GEN_OP_ARITHMETIC_SUB );

		StringBuilder_Appendf( code, "\t%s delta = %s( lhs, rhs );\n", typeInfo->fullTypeName, subFuncStr );
		StringBuilder_Appendf( code, "\treturn %s( &delta );\n", lengthFuncStr );
	}
	StringBuilder_Append(  code, "}\n\n" );
}

static void GenerateFunction_Pack( allocatorLinear_t* tempStorage, const typeInfo_t* typeInfo, stringBuilder_t* code, const generatorStrings_t* strings, const generatorFlags_t flags ) {
	assert( typeInfo );
	assert( code );
	assert( strings );

	if ( typeInfo->type != GEN_TYPE_UINT ) {
		return;
	}

	if ( typeInfo->numCols != 4 ) {
		return;
	}

	const char* memberTypeString = Gen_GetMemberTypeString( typeInfo->type );

	const char* packFuncStr = Gen_GetFuncName_Vector( tempStorage, typeInfo, flags, GEN_FUNCTION_NAME_PACK );

	StringBuilder_Append(  code, "// Returns a 32 bit integer containing each component of the vector at each byte (where the X component contains the left-most byte).\n" );
	StringBuilder_Appendf( code, "HLML_INLINE %s %s( const %s%s vec )\n", memberTypeString, packFuncStr, typeInfo->fullTypeName, strings->parmPassByStr );
	StringBuilder_Append(  code, "{\n" );
	StringBuilder_Appendf( code, "\treturn ( vec%sx << 24 ) | ( vec%sy << 16 ) | ( vec%sz << 8 ) | ( vec%sw );\n", strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr );
	StringBuilder_Append(  code, "}\n\n" );
}

static void GenerateFunction_Unpack( allocatorLinear_t* tempStorage, const typeInfo_t* typeInfo, stringBuilder_t* code, const generatorFlags_t flags ) {
	assert( typeInfo );
	assert( code );

	if ( typeInfo->type != GEN_TYPE_UINT ) {
		return;
	}

	if ( typeInfo->numCols != 4 ) {
		return;
	}

	u32 shiftVals[] = {
		24, 16, 8, 0
	};

	const char* memberTypeString = Gen_GetMemberTypeString( typeInfo->type );

	const char* unpackFuncStr = Gen_GetFuncName_Vector( tempStorage, typeInfo, flags, GEN_FUNCTION_NAME_UNPACK );

	StringBuilder_Append(  code, "// Returns a 4-component int vector where each component contains each byte of the integer (where the X component contains the left-most byte).\n" );
	StringBuilder_Appendf( code, "HLML_INLINE %s %s( const %s x )\n", typeInfo->fullTypeName, unpackFuncStr, memberTypeString );
	StringBuilder_Append(  code, "{\n" );
	StringBuilder_Appendf( code, "\treturn HLML_CONSTRUCT( %s )\n", typeInfo->fullTypeName );
	StringBuilder_Append(  code, "\t{\n" );
	for ( u32 i = 0; i < typeInfo->numCols; i++ ) {
		StringBuilder_Appendf( code, "\t\t( x >> %d ) & 0xFF", shiftVals[i] );

		if ( i != typeInfo->numCols - 1 ) {
			StringBuilder_Append( code, "," );
		}

		StringBuilder_Append( code, "\n" );
	}
	StringBuilder_Append( code, "\t};\n" );
	StringBuilder_Append( code, "}\n\n" );
}

static bool32 SwizzleTypeIsWritable( const char* swizzleStr, const u32 numSwizzleComponents ) {
	// if the swizzle contains duplicate components in the name (eg xzx, xxy, etc.) then the swizzle cant be written to
	for ( u32 i = 0; i < numSwizzleComponents - 1; i++ ) {
		for ( u32 j = i + 1; j < numSwizzleComponents; j++ ) {
			if ( swizzleStr[i] == swizzleStr[j] ) {
				return false;
			}
		}
	}

	return true;
}

#if !GENERATE_TEMPLATES
static void GenerateSwizzleFunc_Type( allocatorLinear_t* tempStorage, stringBuilder_t* code, const typeInfo_t* typeInfo, const generatorStrings_t* strings, const generatorFlags_t flags, const u32 numSwizzleComponents, const char* swizzleStr ) {
	assert( tempStorage );
	assert( code );
	assert( typeInfo );
	assert( typeInfo->fullTypeName );
	assert( Gen_TypeIsVector( typeInfo ) );
	assert( strings );
	assert( numSwizzleComponents );
	assert( swizzleStr );

	GEN_UNUSED( flags );

	const char* typeString = Gen_GetTypeString( typeInfo->type );
	const char* memberTypeString = Gen_GetMemberTypeString( typeInfo->type );

	const char* swizzleTypeName = String_TPrintf( tempStorage, "%s%d", typeString, numSwizzleComponents );

	bool32 isWritable = SwizzleTypeIsWritable( swizzleStr, numSwizzleComponents );

	StringBuilder_Appendf( code, "struct %s_swizzle_%d_to_%d_%s_t\n", typeInfo->fullTypeName, typeInfo->numCols, numSwizzleComponents, swizzleStr );
	StringBuilder_Append(  code, "{\n" );
	StringBuilder_Appendf( code, "\t%s v[%d];\n", memberTypeString, typeInfo->numCols );
	StringBuilder_Append(  code, "\n" );

	if ( isWritable ) {
		StringBuilder_Appendf( code, "\tHLML_INLINE %s operator=( const %s%s vec );\n", swizzleTypeName, swizzleTypeName, strings->parmPassByStr );
		StringBuilder_Append(  code, "\n" );
	}

	StringBuilder_Appendf( code, "\tHLML_INLINE operator %s() const;\n", swizzleTypeName );
	StringBuilder_Append(  code, "};\n\n" );
}
#endif

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-parameter"
static void GenerateSwizzleFunc_Members( allocatorLinear_t* tempStorage, stringBuilder_t* code, const typeInfo_t* typeInfo, const generatorStrings_t* strings, const generatorFlags_t flags, const u32 numSwizzleComponents, const char* swizzleStr ) {
#pragma clang diagnostic pop
	assert( tempStorage );
	assert( code );
	assert( typeInfo );
	assert( typeInfo->fullTypeName );
	assert( Gen_TypeIsVector( typeInfo ) );
	assert( strings );
	assert( numSwizzleComponents );
	assert( swizzleStr );

	GEN_UNUSED( flags );

#if GENERATE_TEMPLATES
	const char* memberTypeString = Gen_GetMemberTypeString( typeInfo->type );

	const char* typeString = Gen_GetTypeString( typeInfo->type );
	const char* swizzleTypeName = String_TPrintf( tempStorage, "%s%d", typeString, numSwizzleComponents );

	const char* writableStr = SwizzleTypeIsWritable( swizzleStr, numSwizzleComponents ) ? "writable" : "nonwritable";

	StringBuilder_Appendf( code, "\t\tswizzle_%d_to_%d_%s_t<%s, %s, ", typeInfo->numCols, numSwizzleComponents, writableStr, swizzleTypeName, memberTypeString );
	for ( u32 i = 0; i < numSwizzleComponents; i++ ) {
		u32 swizzleIndex = Gen_GetComponentIndex( swizzleStr[i] );

		StringBuilder_Appendf( code, "%d", swizzleIndex );

		if ( i != numSwizzleComponents - 1 ) {
			StringBuilder_Append( code, ", " );
		}
	}
	StringBuilder_Appendf( code, "> %s;\n", swizzleStr );
#else // GENERATE_TEMPLATES
	StringBuilder_Appendf( code, "\t\t%s_swizzle_%d_to_%d_%s_t %s;\n", typeInfo->fullTypeName, typeInfo->numCols, numSwizzleComponents, swizzleStr, swizzleStr );
#endif // GENERATE_TEMPLATES
}

#if !GENERATE_TEMPLATES
static void GenerateSwizzleFunc_OperatorDefinitions( allocatorLinear_t* tempStorage, stringBuilder_t* code, const typeInfo_t* typeInfo, const generatorStrings_t* strings, const generatorFlags_t flags, const u32 numSwizzleComponents, const char* swizzleStr ) {
	assert( tempStorage );
	assert( code );
	assert( typeInfo );
	assert( typeInfo->fullTypeName );
	assert( Gen_TypeIsVector( typeInfo ) );
	assert( strings );
	assert( numSwizzleComponents );
	assert( swizzleStr );

	GEN_UNUSED( flags );

	const char* typeString = Gen_GetTypeString( typeInfo->type );
	const char* swizzleTypeName = String_TPrintf( tempStorage, "%s%d", typeString, numSwizzleComponents );

	bool32 isWritable = SwizzleTypeIsWritable( swizzleStr, numSwizzleComponents );

	// assignment operator
	if ( isWritable ) {
		StringBuilder_Append( code, "\n" );
		StringBuilder_Appendf( code, "%s %s_swizzle_%d_to_%d_%s_t::operator=( const %s%s vec )\n", swizzleTypeName, typeInfo->fullTypeName, typeInfo->numCols, numSwizzleComponents, swizzleStr, swizzleTypeName, strings->parmPassByStr );
		StringBuilder_Append(  code, "{\n" );
		StringBuilder_Appendf( code, "\treturn %s(\n", swizzleTypeName );
		for ( u32 componentIndex = 0; componentIndex < numSwizzleComponents; componentIndex++ ) {
			StringBuilder_Appendf( code, "\t\tv[%d] = vec.%c", componentIndex, GEN_COMPONENT_NAMES_VECTOR[componentIndex] );

			if ( componentIndex != numSwizzleComponents - 1 ) {
				StringBuilder_Append(  code, "," );
			}

			StringBuilder_Append(  code, "\n" );
		}
		StringBuilder_Append(  code, "\t);\n}\n\n" );
	}

	// conversion function
	StringBuilder_Appendf( code, "%s_swizzle_%d_to_%d_%s_t::operator %s() const ", typeInfo->fullTypeName, typeInfo->numCols, numSwizzleComponents, swizzleStr, swizzleTypeName );
	StringBuilder_Appendf( code, "{ return %s( ", swizzleTypeName );
	for ( u32 componentIndex = 0; componentIndex < numSwizzleComponents; componentIndex++ ) {
		u32 swizzleComponentIndex = Gen_GetComponentIndex( swizzleStr[componentIndex] );

		StringBuilder_Appendf( code, "v[%d]", swizzleComponentIndex );

		if ( componentIndex != numSwizzleComponents - 1 ) {
			StringBuilder_Append(  code, ", " );
		}
	}
	StringBuilder_Append(  code, " ); }\n" );
}
#endif // GENERATE_TEMPLATES

// generating vector component swizzles:
// the main work of this function is to transform a base 10 number (12, for example) into a swizzle string like zxwy, xxzz, etc.
// for vec2, for example, you can count all the 2-component swizzles by counting in base 2 from 0 through to 2^2
// this can then be repeated for generating the 3-component swizzles for vec2 types by counting in base 2 from 0 through to 2^3 and so on
// the same logic applies for vec3 and vec4
static void GenerateSwizzleFunctions( allocatorLinear_t* tempStorage, stringBuilder_t* code, const typeInfo_t* typeInfo, const generatorStrings_t* strings, const generatorFlags_t flags, const char* componentNames, generateSwizzleFunc_t generateSwizzleFunc ) {
	assert( tempStorage );
	assert( code );
	assert( typeInfo );
	assert( typeInfo->fullTypeName );
	assert( strlen( componentNames ) == 4 );
	assert( strings );
	assert( flags & GENERATOR_FLAG_VECTOR_SWIZZLES );
	assert( componentNames );
	assert( generateSwizzleFunc );

	u32 numVectorComponents = typeInfo->numCols;

	// for vec2, vec3, vec4...
	for ( u32 swizzleComponentIndex = 2; swizzleComponentIndex <= 4; swizzleComponentIndex++ ) {
		// number of permutations that this vector can generate for the given swizzle type
		u32 numPermutations = (u32) pow( numVectorComponents, swizzleComponentIndex );

		// now go through each permutation
		for ( u32 permutationIndex = 0; permutationIndex < numPermutations; permutationIndex++ ) {
			u32 permutationIndexCopy = permutationIndex;
			u32 numberInBase = 0;

			char swizzleStr[4] = {
				componentNames[0],
				componentNames[0],
				componentNames[0],
				componentNames[0]
			};

			u32 swizzleCharIndex = 0;

			// count in the radix of the vector that we are generating the swizzles for
			// so convert from base 10 to base 2 (if generating for vec2, for example)
			// turn that number into a swizzle name
			while ( permutationIndexCopy ) {
				numberInBase = permutationIndexCopy % numVectorComponents;
				permutationIndexCopy /= numVectorComponents;

				swizzleStr[swizzleCharIndex++] = componentNames[numberInBase];
			}

			swizzleStr[swizzleComponentIndex] = 0;

			generateSwizzleFunc( tempStorage, code, typeInfo, strings, flags, swizzleComponentIndex, swizzleStr );
		}
	}
}

static void GenerateVectorFiles( allocatorLinear_t* tempStorage, const char* generatedCodePath, const typeInfo_t* typeInfos, const u32 typeInfosCount, const generatorStrings_t* strings, const generatorFlags_t flags ) {
	assert( tempStorage );
	assert( generatedCodePath );
	assert( typeInfos );
	assert( typeInfosCount );
	assert( strings );

	bool32 cLinkage = flags & GENERATOR_FLAG_C_LINKAGE;
	bool32 vectorUnions = flags & GENERATOR_FLAG_VECTOR_UNIONS;
	bool32 generateConstructors = flags & GENERATOR_FLAG_GENERATE_CONSTRUCTORS;
	bool32 generateOperators = flags & GENERATOR_FLAG_GENERATE_OPERATORS;
	bool32 generateSwizzles = flags & GENERATOR_FLAG_VECTOR_SWIZZLES;

	bool32 generateInlFile = generateConstructors || generateOperators;

	// vector types
	for ( u32 typeInfoIndex = 0; typeInfoIndex < typeInfosCount; typeInfoIndex++ ) {
		const typeInfo_t* typeInfo = &typeInfos[typeInfoIndex];

		const char* typeString = Gen_GetTypeString( typeInfo->type );
		const char* memberTypeString = Gen_GetMemberTypeString( typeInfo->type );

		// vector header file
		{
			stringBuilder_t* codeHeader = StringBuilder_Create( tempStorage, KILOBYTES( 128 ) );

			StringBuilder_Append(  codeHeader, GEN_FILE_HEADER );
			StringBuilder_Append(  codeHeader,
				"#pragma once\n"
				"\n"
			);

			if ( cLinkage ) {
				StringBuilder_Append( codeHeader,
					"#ifdef __cplusplus\n"
					"extern \"C\" {\n"
					"#endif\n"
					"\n"
				);
			}

			if ( !cLinkage ) {
				for ( u32 componentIndex = 2; componentIndex <= 4; componentIndex++ ) {
					if ( componentIndex != typeInfo->numCols ) {
						StringBuilder_Appendf( codeHeader, "struct %s%d;\n", typeString, componentIndex );
					}
				}

				StringBuilder_Append( codeHeader, "\n" );

				for ( u32 typeIndex = 0; typeIndex < GEN_TYPE_COUNT; typeIndex++ ) {
					const genType_t type = (genType_t) typeIndex;

					// dont forward declare the same type as what were about to define
					if ( type == typeInfo->type ) {
						continue;
					}

					const char* rhsTypeString = Gen_GetTypeString( type );

					StringBuilder_Appendf( codeHeader, "struct %s%d;\n", rhsTypeString, typeInfo->numCols );
				}
			}

			StringBuilder_Append( codeHeader, "\n" );
			StringBuilder_Append(  codeHeader, "#include \"" GEN_HEADER_TYPES "\"\n" );
			StringBuilder_Append(  codeHeader, "#include \"" GEN_HEADER_DEFINES "\"\n\n" );

			if ( generateSwizzles ) {
#if GENERATE_TEMPLATES
				StringBuilder_Appendf( codeHeader, "#include \"swizzle_templates.h\"\n\n", typeInfo->fullTypeName );
#else
				StringBuilder_Appendf( codeHeader, "#include \"%s_swizzle_types.h\"\n\n", typeInfo->fullTypeName );
#endif // GENERATE_TEMPLATES
			}

			if ( vectorUnions ) {
				StringBuilder_Appendf( codeHeader,
					"// ignore prohibition of anymous structs for GCC\n"
					"#if defined( __clang__ ) || defined( __GNUC__ )\n"
					"#pragma GCC diagnostic push\n"
					"#pragma GCC diagnostic ignored \"-Wpedantic\"\n"
					"#elif defined( _MSC_VER )\n"
					"#pragma warning( push )\n"
					"#pragma warning( disable : 4201 ) // C4201 - nonstandard extension used : nameless struct/union\n"
					"#endif\n\n"
				);
			}

			// StringBuilder_Appendf( codeHeader, "// A mathematical vector containing %d x %ss.\n", typeInfo->numCols, memberTypeString );
			if ( cLinkage ) {
				StringBuilder_Appendf( codeHeader, "typedef struct %s\n", typeInfo->fullTypeName );
			} else {
				StringBuilder_Appendf( codeHeader, "struct %s\n", typeInfo->fullTypeName );
			}

			StringBuilder_Append( codeHeader, "{\n" );

			if ( vectorUnions ) {
				StringBuilder_Append( codeHeader,
					"\tunion\n"
					"\t{\n"
				);

				// xyzw
				{
					StringBuilder_Append( codeHeader,
						"\t\tstruct\n"
						"\t\t{\n"
					);
					for ( u32 componentIndex = 0; componentIndex < typeInfo->numCols; componentIndex++ ) {
						StringBuilder_Appendf( codeHeader, "\t\t\t%s %c;\n", memberTypeString, GEN_COMPONENT_NAMES_VECTOR[componentIndex] );
					}
					StringBuilder_Append( codeHeader, "\t\t};\n\n" );
				}

				// rgba
				{
					StringBuilder_Append( codeHeader,
						"\t\tstruct\n"
						"\t\t{\n"
					);
					for ( u32 componentIndex = 0; componentIndex < typeInfo->numCols; componentIndex++ ) {
						StringBuilder_Appendf( codeHeader, "\t\t\t%s %c;\n", memberTypeString, GEN_COMPONENT_NAMES_COLOR[componentIndex] );
					}
					StringBuilder_Append( codeHeader, "\t\t};\n\n" );
				}

				// array
				StringBuilder_Appendf( codeHeader, "\t\t%s v[%d];\n", memberTypeString, typeInfo->numCols );

				// swizzles
				if ( generateSwizzles ) {
					StringBuilder_Appendf( codeHeader, "\n\t\t// swizzles\n" );

					GenerateSwizzleFunctions( tempStorage, codeHeader, typeInfo, strings, flags, GEN_COMPONENT_NAMES_VECTOR, GenerateSwizzleFunc_Members );

					StringBuilder_Append( codeHeader, "\n" );

					if ( vectorUnions ) {
						GenerateSwizzleFunctions( tempStorage, codeHeader, typeInfo, strings, flags, GEN_COMPONENT_NAMES_COLOR, GenerateSwizzleFunc_Members );
					}
				}

				// end of union
				StringBuilder_Append(  codeHeader, "\t};\n\n" );
			} else {
				for ( u32 componentIndex = 0; componentIndex < typeInfo->numCols; componentIndex++ ) {
					StringBuilder_Appendf( codeHeader, "\t%s %c;\n", memberTypeString, GEN_COMPONENT_NAMES_VECTOR[componentIndex] );
				}
			}

			if ( generateConstructors ) {
				// default ctor
				StringBuilder_Append(  codeHeader, "\t// Default constructor.\n" );
				StringBuilder_Appendf( codeHeader, "\tHLML_INLINE %s() {}\n\n", typeInfo->fullTypeName );

				// single scalar ctor
				StringBuilder_Append(  codeHeader, "\t// Initialises all components of the vector to the given scalar.\n" );
				StringBuilder_Appendf( codeHeader, "\tHLML_INLINE explicit %s( const %s scalar );\n\n", typeInfo->fullTypeName, memberTypeString );

				// per component ctor
				StringBuilder_Append(  codeHeader, "\t// Initialises all components of the vector to the corresponding scalars.\n" );
				StringBuilder_Appendf( codeHeader, "\tHLML_INLINE %s( ", typeInfo->fullTypeName );
				for ( u32 componentIndex = 0; componentIndex < typeInfo->numCols; componentIndex++ ) {
					StringBuilder_Appendf( codeHeader, "const %s %c", memberTypeString, GEN_COMPONENT_NAMES_VECTOR[componentIndex] );

					if ( componentIndex < typeInfo->numCols - 1 ) {
						StringBuilder_Append( codeHeader, ", " );
					}
				}
				StringBuilder_Append( codeHeader, " );\n\n" );

				// copy ctors
				StringBuilder_Append(  codeHeader, "\t// Copy constructor.  Copies all elements of 'other' into the vector.\n" );
				StringBuilder_Appendf( codeHeader, "\tHLML_INLINE %s( const %s& other );\n\n", typeInfo->fullTypeName, typeInfo->fullTypeName );

				// conversion ctors
				for ( u32 typeIndex = 0; typeIndex < GEN_TYPE_COUNT; typeIndex++ ) {
					const genType_t otherType = (genType_t) typeIndex;

					// dont do the conversion ctor for the same type because we just generated that
					if ( otherType == typeInfo->type ) {
						continue;
					}

					const char* otherTypeString = Gen_GetTypeString( otherType );
					const char* otherMemberTypeString = Gen_GetMemberTypeString( otherType );

					StringBuilder_Appendf( codeHeader, "\t// Conversion constructor.  Casts all components of 'vec' from type %s to type %s.\n", otherMemberTypeString, memberTypeString );
					StringBuilder_Appendf( codeHeader, "\tHLML_INLINE explicit %s( const %s%d& vec );\n\n", typeInfo->fullTypeName, otherTypeString, typeInfo->numCols );
				}

				// scalar/vector composite ctors
				{
					// the components that the input vector will set
					// component names are used as parm names here
					char subVecStr[4];

					// generate the ctors where we can fit a vector and some scalars
					for ( u32 componentIndex = 2; componentIndex < typeInfo->numCols; componentIndex++ ) {
						u32 leftoverOnes = typeInfo->numCols - componentIndex;

						if ( !leftoverOnes ) {
							continue;
						}

						memcpy( subVecStr, GEN_COMPONENT_NAMES_VECTOR, componentIndex * sizeof( char ) );
						subVecStr[componentIndex] = 0;

						// vector before
						StringBuilder_Appendf( codeHeader, "\t// Sets the %s components of the vector to that of the corresponding input vector.  Sets the other corresponding vectors to the given scalars.\n", subVecStr );
						StringBuilder_Appendf( codeHeader, "\tHLML_INLINE %s( const %s%d& %s, ", typeInfo->fullTypeName, typeString, componentIndex, subVecStr );
						for ( u32 i = 0; i < leftoverOnes; i++ ) {
							const u32 componentNameIndex = componentIndex + i;

							assert( componentNameIndex < 4 );

							StringBuilder_Appendf( codeHeader, "const %s %c", memberTypeString, GEN_COMPONENT_NAMES_VECTOR[componentNameIndex] );

							if ( i != leftoverOnes - 1 ) {
								StringBuilder_Append( codeHeader, ", " );
							}
						}
						StringBuilder_Appendf( codeHeader, " );\n\n" );

						// vector after
						memcpy( subVecStr, GEN_COMPONENT_NAMES_VECTOR + ( 4 - componentIndex ), componentIndex * sizeof( char ) );
						subVecStr[componentIndex] = 0;

						StringBuilder_Appendf( codeHeader, "\t// Sets the %s components of the vector to that of the corresponding input vector.  Sets the other corresponding vectors to the given scalars.\n", subVecStr );
						StringBuilder_Appendf( codeHeader, "\tHLML_INLINE %s( ", typeInfo->fullTypeName );
						for ( u32 i = 0; i < leftoverOnes; i++ ) {
							const char componentName = GEN_COMPONENT_NAMES_VECTOR[i];

							StringBuilder_Appendf( codeHeader, "const %s %c, ", memberTypeString, componentName );
						}

						StringBuilder_Appendf( codeHeader, "const %s%d& %s );\n\n", typeString, componentIndex, subVecStr );
					}

					// if we can also have a ctors consisting of two input vectors then generate that one now
					if ( typeInfo->numCols > 2 && typeInfo->numCols % 2 == 0 ) {
						StringBuilder_Appendf( codeHeader, "\tHLML_INLINE %s( ", typeInfo->fullTypeName );

						const u32 numVectorParms = typeInfo->numCols - 2;
						const u32 numVectorParmComponents = numVectorParms;

						for ( u32 i = 0; i < numVectorParms; i++ ) {
							u32 subVecStrOffset = ( i * numVectorParmComponents );

							assert( subVecStrOffset < 4 );

							memcpy( subVecStr, GEN_COMPONENT_NAMES_VECTOR + subVecStrOffset, numVectorParmComponents * sizeof( char ) );
							subVecStr[numVectorParmComponents] = 0;

							StringBuilder_Appendf( codeHeader, "const %s%d& %s", typeString, numVectorParmComponents, subVecStr );

							if ( i != numVectorParms - 1 ) {
								StringBuilder_Append( codeHeader, ", " );
							}
						}
						StringBuilder_Append( codeHeader, " );\n\n" );
					}
				}

				// dtor
				StringBuilder_Appendf( codeHeader, "\t~%s() {}\n\n", typeInfo->fullTypeName );
			}

			if ( generateOperators ) {
				// assignment operators
				for ( u32 componentIndex = 2; componentIndex <= typeInfo->numCols; componentIndex++ ) {
					const char* otherTypeName = String_TPrintf( tempStorage, "%s%d", Gen_GetTypeString( typeInfo->type ), componentIndex );

					StringBuilder_Append(  codeHeader, "\t// Copies all elements of 'other' into the vector.\n" );
					StringBuilder_Appendf( codeHeader, "\tHLML_INLINE %s operator=( const %s& other );\n\n", typeInfo->fullTypeName, otherTypeName );
				}

				const char* returnTypeName = Gen_GetMemberTypeString( GEN_TYPE_INT );

				// array operators
				StringBuilder_Append(  codeHeader, "\t// Returns the vector component at the given index.\n" );
				StringBuilder_Appendf( codeHeader, "\t// Index CANNOT be lower than 0 or greater than %d.\n", typeInfo->numCols - 1 );
				StringBuilder_Appendf( codeHeader, "\tHLML_INLINE %s& operator[]( const %s index );\n\n", memberTypeString, returnTypeName );

				StringBuilder_Append(  codeHeader, "\t// Returns the vector component at the given index.\n" );
				StringBuilder_Appendf( codeHeader, "\t// Index CANNOT be lower than 0 or greater than %d.\n", typeInfo->numCols - 1 );
				StringBuilder_Appendf( codeHeader, "\tHLML_INLINE const %s& operator[]( const %s index ) const;\n", memberTypeString, returnTypeName );
			}

			// struct end
			if ( cLinkage ) {
				StringBuilder_Appendf( codeHeader, "} %s;\n", typeInfo->fullTypeName );
			} else {
				StringBuilder_Append( codeHeader, "};\n" );
			}

			if ( vectorUnions ) {
				StringBuilder_Appendf( codeHeader,
					"\n"
					"#if defined( __clang__ ) || defined( __GNUC__ )\n"
					"#pragma GCC diagnostic pop\n"
					"#elif defined( _MSC_VER )\n"
					"#pragma warning( pop )\n"
					"#endif\n\n"
				);
			}

			if ( cLinkage ) {
				StringBuilder_Append(  codeHeader,
					"\n"
					"#ifdef __cplusplus\n"
					"}\n"
					"#endif\n"
				);
			}

			const char* fileNameHeader = String_TPrintf( tempStorage, "%s/%s.h", generatedCodePath, typeInfo->fullTypeName );

			FS_WriteEntireFile( fileNameHeader, codeHeader->str, codeHeader->length );
		}

		// vector inl file
		if ( generateInlFile ) {
			stringBuilder_t* codeInl = StringBuilder_Create( tempStorage, KILOBYTES( 64 ) );

			StringBuilder_Appendf( codeInl,
				GEN_FILE_HEADER
				"#pragma once\n\n"
			);

			StringBuilder_Appendf( codeInl, "#include \"%s.h\"\n\n", typeInfo->fullTypeName );
			StringBuilder_Appendf( codeInl, "#include \"%s\"\n\n", GEN_HEADER_DEFINES );

			if ( generateConstructors ) {
				// single scalar ctor
				StringBuilder_Appendf( codeInl, "%s::%s( const %s scalar )\n", typeInfo->fullTypeName, typeInfo->fullTypeName, memberTypeString );
				StringBuilder_Append(  codeInl, "\t: x( scalar )\n" );

				for ( u32 componentIndex = 1; componentIndex < typeInfo->numCols; componentIndex++ ) {
					StringBuilder_Appendf( codeInl, "\t, %c( scalar )\n", GEN_COMPONENT_NAMES_VECTOR[componentIndex] );
				}

				StringBuilder_Append(  codeInl,
					"{\n"
					"}\n\n"
				);

				// per component ctor
				StringBuilder_Appendf( codeInl, "%s::%s( ", typeInfo->fullTypeName, typeInfo->fullTypeName );
				for ( u32 componentIndex = 0; componentIndex < typeInfo->numCols; componentIndex++ ) {
					const char componentName = GEN_COMPONENT_NAMES_VECTOR[componentIndex];

					StringBuilder_Appendf( codeInl, "const %s %c", memberTypeString, componentName );

					if ( componentIndex < typeInfo->numCols - 1 ) {
						StringBuilder_Append( codeInl, ", " );
					}
				}
				StringBuilder_Append( codeInl, " )\n" );
				StringBuilder_Append( codeInl, "\t: x( x )\n" );

				for ( u32 componentIndex = 1; componentIndex < typeInfo->numCols; componentIndex++ ) {
					const char componentName = GEN_COMPONENT_NAMES_VECTOR[componentIndex];

					StringBuilder_Appendf( codeInl, "\t, %c( %c )\n", componentName, componentName );
				}

				StringBuilder_Append(  codeInl,
					"{\n"
					"}\n\n"
				);

				// copy ctors
				StringBuilder_Appendf( codeInl, "%s::%s( const %s& vec )\n", typeInfo->fullTypeName, typeInfo->fullTypeName, typeInfo->fullTypeName );
				StringBuilder_Append( codeInl, "\t: x( vec.x )\n" );

				for ( u32 componentIndex = 1; componentIndex < typeInfo->numCols; componentIndex++ ) {
					const char componentName = GEN_COMPONENT_NAMES_VECTOR[componentIndex];

					StringBuilder_Appendf( codeInl, "\t, %c( vec.%c )\n", componentName, componentName );
				}

				StringBuilder_Append(  codeInl,
					"{\n"
					"}\n\n"
				);

				// conversion ctors
				for ( u32 typeIndex = 0; typeIndex < GEN_TYPE_COUNT; typeIndex++ ) {
					const genType_t otherType = (genType_t) typeIndex;

					// dont do the conversion ctor for the same type because we just generated that
					if ( otherType == typeInfo->type ) {
						continue;
					}

					const char* otherTypeString = Gen_GetTypeString( otherType );

					StringBuilder_Appendf( codeInl, "%s::%s( const %s%d& vec )\n", typeInfo->fullTypeName, typeInfo->fullTypeName, otherTypeString, typeInfo->numCols );

					if ( otherType != typeInfo->type ) {
						StringBuilder_Appendf( codeInl, "\t: x( (%s) vec.x )\n", memberTypeString );
					} else {
						StringBuilder_Append( codeInl, "\t: x( vec.x )\n" );
					}

					for ( u32 componentIndex = 1; componentIndex < typeInfo->numCols; componentIndex++ ) {
						const char componentName = GEN_COMPONENT_NAMES_VECTOR[componentIndex];

						if ( otherType != typeInfo->type ) {
							StringBuilder_Appendf( codeInl, "\t, %c( (%s) vec.%c )\n", componentName, memberTypeString, componentName );
						} else {
							StringBuilder_Appendf( codeInl, "\t, %c( vec.%c )\n", componentName, componentName );
						}
					}

					StringBuilder_Append( codeInl,
						"{\n"
						"}\n\n"
					);
				}

				// scalar/vector composite ctors
				{
					char subVecStr[4];

					for ( u32 componentIndex = 2; componentIndex < typeInfo->numCols; componentIndex++ ) {
						u32 leftoverOnes = typeInfo->numCols - componentIndex;

						if ( !leftoverOnes ) {
							continue;
						}

						memcpy( subVecStr, GEN_COMPONENT_NAMES_VECTOR, componentIndex * sizeof( char ) );
						subVecStr[componentIndex] = 0;

						// vector before
						StringBuilder_Appendf( codeInl, "%s::%s( const %s%d& %s, ", typeInfo->fullTypeName, typeInfo->fullTypeName, typeString, componentIndex, subVecStr );
						for ( u32 i = 0; i < leftoverOnes; i++ ) {
							const u32 componentNameIndex = componentIndex + i;

							assert( componentNameIndex <= 3 );

							StringBuilder_Appendf( codeInl, "const %s %c", memberTypeString, GEN_COMPONENT_NAMES_VECTOR[componentNameIndex] );

							if ( i != leftoverOnes - 1 ) {
								StringBuilder_Append( codeInl, ", " );
							}
						}
						StringBuilder_Appendf( codeInl, " )\n" );
						StringBuilder_Appendf( codeInl, "\t: x( %s.x )\n", subVecStr );
						for ( u32 i = 1; i < componentIndex; i++ ) {
							const char componentName = GEN_COMPONENT_NAMES_VECTOR[i];

							StringBuilder_Appendf( codeInl, "\t, %c( %s.%c )\n", componentName, subVecStr, componentName );
						}
						for ( u32 i = 0; i < leftoverOnes; i++ ) {
							const u32 componentNameIndex = componentIndex + i;

							assert( componentNameIndex <= 3 );

							const char componentName = GEN_COMPONENT_NAMES_VECTOR[componentNameIndex];

							StringBuilder_Appendf( codeInl, "\t, %c( %c )\n", componentName, componentName );
						}
						StringBuilder_Appendf( codeInl,
							"{\n"
							"}\n\n"
						);

						// vector after
						StringBuilder_Appendf( codeInl, "%s::%s( ", typeInfo->fullTypeName, typeInfo->fullTypeName );
						for ( u32 i = 0; i < leftoverOnes; i++ ) {
							const char componentName = GEN_COMPONENT_NAMES_VECTOR[i];

							StringBuilder_Appendf( codeInl, "const %s %c, ", memberTypeString, componentName );
						}

						memcpy( subVecStr, GEN_COMPONENT_NAMES_VECTOR + componentIndex, componentIndex * sizeof( char ) );
						subVecStr[componentIndex] = 0;

						StringBuilder_Appendf( codeInl, "const %s%d& %s )\n", typeString, componentIndex, subVecStr );
						StringBuilder_Append(  codeInl, "\t: x( x )\n" );
						for ( u32 i = 1; i < leftoverOnes; i++ ) {
							const char componentName = GEN_COMPONENT_NAMES_VECTOR[i];

							StringBuilder_Appendf( codeInl, "\t, %c( %c )\n", componentName, componentName );
						}
						for ( u32 i = 0; i < componentIndex; i++ ) {
							u32 componentNameIndex = i + leftoverOnes;

							assert( componentNameIndex <= 3 );

							const char componentName = GEN_COMPONENT_NAMES_VECTOR[componentNameIndex];

							const char subVecComponentName = GEN_COMPONENT_NAMES_VECTOR[i];

							StringBuilder_Appendf( codeInl, "\t, %c( %s.%c )\n", componentName, subVecStr, subVecComponentName );
						}
						StringBuilder_Append( codeInl,
							"{\n"
							"}\n\n"
						);
					}

					// if we can also have a ctors consisting of two input vectors then generate that one now
					if ( typeInfo->numCols > 2 && typeInfo->numCols % 2 == 0 ) {
						StringBuilder_Appendf( codeInl, "%s::%s( ", typeInfo->fullTypeName, typeInfo->fullTypeName );

						const u32 numVectorParms = typeInfo->numCols - 2;
						const u32 numVectorParmComponents = numVectorParms;

						for ( u32 parmIndex = 0; parmIndex < numVectorParms; parmIndex++ ) {
							u32 subVecStrOffset = ( parmIndex * numVectorParmComponents );

							assert( subVecStrOffset < 4 );

							memcpy( subVecStr, GEN_COMPONENT_NAMES_VECTOR + subVecStrOffset, numVectorParmComponents * sizeof( char ) );
							subVecStr[numVectorParmComponents] = 0;

							StringBuilder_Appendf( codeInl, "const %s%d& %s", typeString, numVectorParmComponents, subVecStr );

							if ( parmIndex != numVectorParms - 1 ) {
								StringBuilder_Append( codeInl, ", " );
							}
						}
						StringBuilder_Append( codeInl, " )\n" );

						char initializerListToken = ':';

						for ( u32 parmIndex = 0; parmIndex < numVectorParms; parmIndex++ ) {
							u32 subVecStrOffset = ( parmIndex * numVectorParmComponents );

							assert( subVecStrOffset < 4 );

							memcpy( subVecStr, GEN_COMPONENT_NAMES_VECTOR + subVecStrOffset, numVectorParmComponents * sizeof( char ) );
							subVecStr[numVectorParmComponents] = 0;

							for ( u32 componentIndex = 0; componentIndex < numVectorParmComponents; componentIndex++ ) {
								// 00 = x
								// 01 = y
								// 10 = z
								// 11 = w
								// DM!!! this is a hack! redo this!
								u32 componentNameIndex = ( parmIndex << 1 ) | componentIndex;
								const char componentName = GEN_COMPONENT_NAMES_VECTOR[componentNameIndex];

								const char inputParmComponentName = GEN_COMPONENT_NAMES_VECTOR[componentIndex];

								StringBuilder_Appendf( codeInl, "\t%c %c( %s.%c )\n", initializerListToken, componentName, subVecStr, inputParmComponentName );

								initializerListToken = ',';
							}
						}
						StringBuilder_Append( codeInl,
							"{\n"
							"}\n\n"
						);
					}
				}
			}

			if ( generateOperators ) {
				// assignment operators
				for ( u32 otherVecComponentIndex = 2; otherVecComponentIndex <= typeInfo->numCols; otherVecComponentIndex++ ) {
					const char* otherTypeName = String_TPrintf( tempStorage, "%s%d", Gen_GetTypeString( typeInfo->type ), otherVecComponentIndex );

					StringBuilder_Appendf( codeInl, "%s %s::operator=( const %s& other )\n", typeInfo->fullTypeName, typeInfo->fullTypeName, otherTypeName );
					StringBuilder_Append(  codeInl, "{\n" );
					for ( u32 componentIndex = 0; componentIndex < otherVecComponentIndex; componentIndex++ ) {
						const char componentName = GEN_COMPONENT_NAMES_VECTOR[componentIndex];

						StringBuilder_Appendf( codeInl, "\tthis->%c = other.%c;\n", componentName, componentName );
					}
					StringBuilder_Append( codeInl, "\n" );
					StringBuilder_Append( codeInl, "\treturn *this;\n" );
					StringBuilder_Append( codeInl, "}\n\n" );
				}

				// array operators
				StringBuilder_Appendf( codeInl, "%s& %s::operator[]( const %s index )\n", memberTypeString, typeInfo->fullTypeName, Gen_GetMemberTypeString( GEN_TYPE_INT ) );
				StringBuilder_Append(  codeInl, "{\n" );
				StringBuilder_Appendf( codeInl, "\tHLML_ASSERT( index >= 0 && index < %d );\n", typeInfo->numCols );
				StringBuilder_Append(  codeInl, "\treturn v[index];\n" );
				StringBuilder_Append(  codeInl, "}\n\n" );

				StringBuilder_Appendf( codeInl, "const %s& %s::operator[]( const %s index ) const\n", memberTypeString, typeInfo->fullTypeName, Gen_GetMemberTypeString( GEN_TYPE_INT ) );
				StringBuilder_Append(  codeInl, "{\n" );
				StringBuilder_Appendf( codeInl, "\tHLML_ASSERT( index >= 0 && index < %d );\n", typeInfo->numCols );
				StringBuilder_Append(  codeInl, "\treturn v[index];\n" );
				StringBuilder_Append(  codeInl, "}\n" );
			}

#if !GENERATE_TEMPLATES
			if ( generateSwizzles ) {
				StringBuilder_Appendf( codeInl, "\n#include \"%s_swizzle_types.inl\"\n", typeInfo->fullTypeName );
			}
#endif // GENERATE_TEMPLATES

			const char* fileNameInl = String_TPrintf( tempStorage, "%s/%s.inl", generatedCodePath, typeInfo->fullTypeName );

			FS_WriteEntireFile( fileNameInl, codeInl->str, codeInl->length );
		}

#if !GENERATE_TEMPLATES
		// generate swizzles
		if ( generateSwizzles ) {
			// swizzle header file
			{
				stringBuilder_t* codeHeader = StringBuilder_Create( tempStorage, KILOBYTES( 128 ) );

				StringBuilder_Appendf( codeHeader,
					GEN_FILE_HEADER
					"#pragma once\n\n"
				);

				for ( uint32_t i = 2; i <= 4; i++ ) {
					StringBuilder_Appendf( codeHeader, "struct %s%d;\n", typeString, i );
				}
				StringBuilder_Append( codeHeader, "\n" );

				GenerateSwizzleFunctions( tempStorage, codeHeader, typeInfo, strings, flags, GEN_COMPONENT_NAMES_VECTOR, GenerateSwizzleFunc_Type );
				GenerateSwizzleFunctions( tempStorage, codeHeader, typeInfo, strings, flags, GEN_COMPONENT_NAMES_COLOR, GenerateSwizzleFunc_Type );

				const char* fileNameHeader = String_TPrintf( tempStorage, "%s/%s_swizzle_types.h", generatedCodePath, typeInfo->fullTypeName );

				FS_WriteEntireFile( fileNameHeader, codeHeader->str, codeHeader->length );
			}

			// swizzle inl file
			{
				stringBuilder_t* codeInl = StringBuilder_Create( tempStorage, KILOBYTES( 128 ) );

				StringBuilder_Appendf( codeInl,
					GEN_FILE_HEADER
					"#pragma once\n\n"
				);

				StringBuilder_Appendf( codeInl, "#include \"%s_swizzle_types.h\"\n\n", typeInfo->fullTypeName );

				StringBuilder_Append( codeInl, "// xyzw swizzles\n" );
				GenerateSwizzleFunctions( tempStorage, codeInl, typeInfo, strings, flags, GEN_COMPONENT_NAMES_VECTOR, GenerateSwizzleFunc_OperatorDefinitions );
				StringBuilder_Append( codeInl, "\n" );

				StringBuilder_Append( codeInl, "// rgba swizzles\n" );
				GenerateSwizzleFunctions( tempStorage, codeInl, typeInfo, strings, flags, GEN_COMPONENT_NAMES_COLOR, GenerateSwizzleFunc_OperatorDefinitions );

				const char* fileNameInl = String_TPrintf( tempStorage, "%s/%s_swizzle_types.inl", generatedCodePath, typeInfo->fullTypeName );

				FS_WriteEntireFile( fileNameInl, codeInl->str, codeInl->length );
			}
		}
#endif // !GENERATE_TEMPLATES

		Mem_Reset( tempStorage );
	}

#if GENERATE_TEMPLATES
	// swizzle templates header file
	if ( generateSwizzles ) {
		stringBuilder_t* codeHeader = StringBuilder_Create( tempStorage, KILOBYTES( 8 ) );

		StringBuilder_Appendf( codeHeader,
			GEN_FILE_HEADER
			"#pragma once\n\n"
		);

		for ( u32 numComponents = 2; numComponents <= 4; numComponents++ ) {
			for ( u32 numSwizzleComponents = 2; numSwizzleComponents <= 4; numSwizzleComponents++ ) {
				bool32 isWritable = numComponents >= numSwizzleComponents;

				if ( isWritable ) {
					StringBuilder_Append(  codeHeader, "template<class ReturnType, class ScalarType, " );
					for ( u32 i = 0; i < numSwizzleComponents; i++ ) {
						StringBuilder_Appendf( codeHeader, "int %c", toupper( GEN_COMPONENT_NAMES_VECTOR[i] ) );
		
						if ( i != numSwizzleComponents - 1 ) {
							StringBuilder_Append( codeHeader, ", " );
						}
					}
					StringBuilder_Append(  codeHeader, ">\n" );
					StringBuilder_Appendf( codeHeader, "struct swizzle_%d_to_%d_writable_t\n", numComponents, numSwizzleComponents );
					StringBuilder_Append(  codeHeader, "{\n" );
					StringBuilder_Appendf( codeHeader, "\tScalarType v[%d];\n", numComponents );
					StringBuilder_Append(  codeHeader, "\n" );

					StringBuilder_Append(  codeHeader, "\tHLML_INLINE ReturnType operator=( const ReturnType& vec )\n" );
					StringBuilder_Append(  codeHeader, "\t{\n" );
					StringBuilder_Append(  codeHeader, "\t\treturn ReturnType(\n" );
					for ( u32 i = 0; i < numSwizzleComponents; i++ ) {
						const char componentStr = GEN_COMPONENT_NAMES_VECTOR[i];

						StringBuilder_Appendf( codeHeader, "\t\t\tv[%c] = vec.%c", toupper( componentStr ), componentStr );

						if ( i != numSwizzleComponents - 1 ) {
							StringBuilder_Append( codeHeader, "," );
						}

						StringBuilder_Append( codeHeader, "\n" );
					}
					StringBuilder_Append(  codeHeader, "\t\t);\n" );
					StringBuilder_Append(  codeHeader, "\t}\n\n" );
		
					StringBuilder_Append(  codeHeader, "\tHLML_INLINE operator ReturnType() const\n" );
					StringBuilder_Append(  codeHeader, "\t{\n" );
					StringBuilder_Append(  codeHeader, "\t\treturn ReturnType( " );
					for ( u32 i = 0; i < numSwizzleComponents; i++ ) {
						StringBuilder_Appendf( codeHeader, "v[%c]", toupper( GEN_COMPONENT_NAMES_VECTOR[i] ) );
		
						if ( i != numSwizzleComponents - 1 ) {
							StringBuilder_Append( codeHeader, ", " );
						}
					}
					StringBuilder_Append(  codeHeader, " );\n" );
					StringBuilder_Append(  codeHeader, "\t}\n" );
					StringBuilder_Append(  codeHeader, "};\n\n" );
				}

				StringBuilder_Append(  codeHeader, "template<class ReturnType, class ScalarType, " );
				for ( u32 i = 0; i < numSwizzleComponents; i++ ) {
					StringBuilder_Appendf( codeHeader, "int %c", toupper( GEN_COMPONENT_NAMES_VECTOR[i] ) );
		
					if ( i != numSwizzleComponents - 1 ) {
						StringBuilder_Append( codeHeader, ", " );
					}
				}
				StringBuilder_Append(  codeHeader, ">\n" );
				StringBuilder_Appendf( codeHeader, "struct swizzle_%d_to_%d_nonwritable_t\n", numComponents, numSwizzleComponents );
				StringBuilder_Append(  codeHeader, "{\n" );
				StringBuilder_Appendf( codeHeader, "\tScalarType v[%d];\n", numComponents );
				StringBuilder_Append(  codeHeader, "\n" );
		
				StringBuilder_Append(  codeHeader, "\tHLML_INLINE operator ReturnType() const\n" );
				StringBuilder_Append(  codeHeader, "\t{\n" );
				StringBuilder_Append(  codeHeader, "\t\treturn ReturnType( " );
				for ( u32 i = 0; i < numSwizzleComponents; i++ ) {
					StringBuilder_Appendf( codeHeader, "v[%c]", toupper( GEN_COMPONENT_NAMES_VECTOR[i] ) );
		
					if ( i != numSwizzleComponents - 1 ) {
						StringBuilder_Append( codeHeader, ", " );
					}
				}
				StringBuilder_Append(  codeHeader, " );\n" );
				StringBuilder_Append(  codeHeader, "\t}\n" );
				StringBuilder_Append(  codeHeader, "};\n\n" );
			}
		}

		const char* fileNameHeader = String_TPrintf( tempStorage, "%s/swizzle_templates.h", generatedCodePath );

		FS_WriteEntireFile( fileNameHeader, codeHeader->str, codeHeader->length );

		Mem_Reset( tempStorage );
	}
#endif // GENERATE_TEMPLATES

	// vector functions
	{
		stringBuilder_t* code = StringBuilder_Create( tempStorage, KILOBYTES( 256 ) );

		StringBuilder_Append( code,
			GEN_FILE_HEADER
			"#pragma once\n"
			"\n"
		);

		if ( cLinkage ) {
			StringBuilder_Append( code,
				"#ifdef __cplusplus\n"
				"extern \"C\" {\n"
				"#endif\n"
				"\n"
			);
		}

		StringBuilder_Append( code,
			"#include \"" GEN_HEADER_DEFINES "\"\n"
			"\n"
		);

		if ( generateInlFile ) {
			for ( u32 i = 0; i < typeInfosCount; i++ ) {
				StringBuilder_Appendf( code, "#include \"%s.inl\"\n", typeInfos[i].fullTypeName );
			}
		} else {
			for ( u32 i = 0; i < typeInfosCount; i++ ) {
				StringBuilder_Appendf( code, "#include \"%s.h\"\n", typeInfos[i].fullTypeName );
			}
		}
		
		StringBuilder_Append( code, "\n" );

		StringBuilder_Appendf( code, "#include \"" GEN_FILENAME_FUNCTIONS_SCALAR ".h\"\n\n" );

		// generate vector types
		for ( u32 i = 0; i < typeInfosCount; i++ ) {
			const typeInfo_t* typeInfo = &typeInfos[i];

			typeInfo_t scalarMemberType = {
				.type			= typeInfo->type,
				.numRows		= 1,
				.numCols		= 1,
				.fullTypeName	= Gen_GetMemberTypeString( typeInfo->type )
			};

			printf( "Vector functions %s...", typeInfo->fullTypeName );

			StringBuilder_Appendf( code, "// %s\n", typeInfo->fullTypeName );

			GenerateComponentWiseOperators( tempStorage, typeInfo, code, strings, flags );

			GenerateComponentWiseFunctions( tempStorage, typeInfo, &scalarMemberType, code, strings, flags );

			GenerateFunction_All( tempStorage, typeInfo, code, flags );
			GenerateFunction_Any( tempStorage, typeInfo, code, flags );

			GenerateFunction_LengthSqr( tempStorage, typeInfo, code, strings, flags );
			GenerateFunction_Length( tempStorage, typeInfo, code, strings, flags );
			GenerateFunction_Normalize( tempStorage, typeInfo, code, strings, flags );
			GenerateFunction_Normalized( tempStorage, typeInfo, code, strings, flags );
			GenerateFunction_Dot( tempStorage, typeInfo, code, strings, flags );
			GenerateFunction_Cross( tempStorage, typeInfo, code, strings, flags );
			GenerateFunction_Angle( tempStorage, typeInfo, code, strings, flags );
			GenerateFunction_Distancesq( tempStorage, typeInfo, code, strings, flags );
			GenerateFunction_Distance( tempStorage, typeInfo, code, strings, flags );
			GenerateFunction_Pack( tempStorage, typeInfo, code, strings, flags );
			GenerateFunction_Unpack( tempStorage, typeInfo, code, /*strings,*/ flags );

			printf( "OK.\n" );
		}

		if ( cLinkage ) {
			StringBuilder_Append( code,
				"#ifdef __cplusplus\n"
				"}\n"
				"#endif\n"
			);
		}

		const char* fileNameHeader = String_TPrintf( tempStorage, "%s/%s.h", generatedCodePath, GEN_FILENAME_FUNCTIONS_VECTOR );

		FS_WriteEntireFile( fileNameHeader, code->str, code->length );

		Mem_Reset( tempStorage );
	}
}
#include <math.h>

typedef void ( *generateSwizzleFunc_t )( allocatorLinear_t* tempStorage, stringBuilder_t* code, const typeInfo_t* typeInfo, const u32 numSwizzleComponents, const char* swizzleStr );

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

static void GenerateSwizzleFunc_FwdDec( allocatorLinear_t* tempStorage, stringBuilder_t* code, const typeInfo_t* typeInfo, const u32 numSwizzleComponents, const char* swizzleStr ) {
	assert( tempStorage );
	assert( code );
	assert( typeInfo );
	assert( typeInfo->fullTypeName );
	assert( swizzleStr );

	const char* typeString = Gen_GetTypeString( typeInfo->type );

	StringBuilder_Appendf( code, "\tHLML_INLINE %s%d ", typeString, numSwizzleComponents );
	for ( u32 i = numSwizzleComponents; i-- > 0; ) {
		StringBuilder_Appendf( code, "%c", swizzleStr[i] );
	}
	StringBuilder_Append( code, "() const;\n" );
}

static void GenerateSwizzleFunc_Impl( allocatorLinear_t* tempStorage, stringBuilder_t* code, const typeInfo_t* typeInfo, const u32 numSwizzleComponents, const char* swizzleStr ) {
	assert( tempStorage );
	assert( code );
	assert( typeInfo );
	assert( typeInfo->fullTypeName );
	assert( swizzleStr );

	const char* typeString = Gen_GetTypeString( typeInfo->type );

	StringBuilder_Appendf( code, "%s%d %s::", typeString, numSwizzleComponents, typeInfo->fullTypeName );
	for ( u32 i = numSwizzleComponents; i-- > 0; ) {
		StringBuilder_Appendf( code, "%c", swizzleStr[i] );
	}
	StringBuilder_Appendf( code, "() const { return %s%d( ", typeString, numSwizzleComponents );
	for ( u32 i = numSwizzleComponents; i-- > 0; ) {
		StringBuilder_Appendf( code, "%c", swizzleStr[i] );

		if ( i > 0 ) {
			StringBuilder_Append( code, ", " );
		}
	}
	StringBuilder_Append( code, " ); }\n" );
}

// generating vector component swizzles:
// the main work of this function is to transform a base 10 number (12, for example) into a swizzle string like zxwy, xxzz, etc.
// for vec2, for example, you can count all the 2-component swizzles by counting in base 2 from 0 through to 2^2
// this can then be repeated for generating the 3-component swizzles for vec2 types by counting in base 2 from 0 through to 2^3 and so on
// the same logic applies for vec3 and vec4
static void GenerateSwizzleFunctions( allocatorLinear_t* tempStorage, stringBuilder_t* code, const typeInfo_t* typeInfo, const char* componentNames, generateSwizzleFunc_t generateSwizzleFunc ) {
	assert( tempStorage );
	assert( code );
	assert( typeInfo );
	assert( typeInfo->fullTypeName );
	assert( strlen( componentNames ) == 4 );

	u32 numVectorComponents = typeInfo->numCols;

	// for vec2, vec3, vec4...
	for ( u32 swizzleComponentIndex = 2; swizzleComponentIndex <= 4; swizzleComponentIndex++ ) {
		// number of permutations that this vector can generate for the given swizzle type
		u32 numPermutations = (u32) pow( numVectorComponents, swizzleComponentIndex );

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
				permutationIndexCopy = permutationIndexCopy / numVectorComponents;

				swizzleStr[swizzleCharIndex++] = componentNames[numberInBase];
			}

			generateSwizzleFunc( tempStorage, code, typeInfo, swizzleComponentIndex, swizzleStr );
		}
	}
	StringBuilder_Append( code, "\n" );
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

	bool32 generateInlFile = generateConstructors || generateOperators;

	// vector types
	for ( u32 typeInfoIndex = 0; typeInfoIndex < typeInfosCount; typeInfoIndex++ ) {
		const typeInfo_t* typeInfo = &typeInfos[typeInfoIndex];

		const char* typeString = Gen_GetTypeString( typeInfo->type );
		const char* memberTypeString = Gen_GetMemberTypeString( typeInfo->type );

		// header file
		{
			stringBuilder_t* codeHeader = StringBuilder_Create( tempStorage, 64 * KB_TO_BYTES );

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

			for ( u32 i = 2; i <= 4; i++ ) {
				if ( i != typeInfo->numCols ) {
					if ( !cLinkage ) {
						StringBuilder_Appendf( codeHeader, "struct %s%d;\n", typeString, i );
					}
				}
			}
			StringBuilder_Append( codeHeader, "\n" );

			StringBuilder_Append( codeHeader, "#include \"" GEN_HEADER_TYPES "\"\n" );
			StringBuilder_Append( codeHeader, "#include \"" GEN_HEADER_DEFINES "\"\n\n" );

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
				StringBuilder_Append(  codeHeader, "\t};\n\n" );	// end of union
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
				for ( u32 componentIndex = 2; componentIndex <= typeInfo->numCols; componentIndex++ ) {
					const char* otherTypeName = String_TPrintf( tempStorage, "%s%d", Gen_GetTypeString( typeInfo->type ), componentIndex );

					StringBuilder_Append(  codeHeader, "\t// Copy constructor.  Copies all elements of 'other' into the vector.\n" );
					StringBuilder_Appendf( codeHeader, "\tHLML_INLINE %s( const %s& other );\n\n", typeInfo->fullTypeName, otherTypeName );
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

			// swizzle functions
			if ( generateConstructors ) {
				StringBuilder_Appendf( codeHeader, "\n\t// swizzle functions\n" );

				GenerateSwizzleFunctions( tempStorage, codeHeader, typeInfo, GEN_COMPONENT_NAMES_VECTOR, GenerateSwizzleFunc_FwdDec );

				if ( flags & GENERATOR_FLAG_VECTOR_UNIONS ) {
					GenerateSwizzleFunctions( tempStorage, codeHeader, typeInfo, GEN_COMPONENT_NAMES_COLOR, GenerateSwizzleFunc_FwdDec );
				}
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
					"#endif\n"
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

		// inl file
		if ( generateInlFile ) {
			stringBuilder_t* codeInl = StringBuilder_Create( tempStorage, 64 * KB_TO_BYTES );

			StringBuilder_Appendf( codeInl,
				GEN_FILE_HEADER
				"#pragma once\n\n"
			);

			StringBuilder_Appendf( codeInl, "#include \"%s.h\"\n\n", typeInfo->fullTypeName );
			StringBuilder_Appendf( codeInl, "#include \"%s\"\n\n", GEN_HEADER_DEFINES );

			if ( generateConstructors ) {
				// single scalar ctor
				StringBuilder_Appendf( codeInl, "%s::%s( const %s scalar )\n", typeInfo->fullTypeName, typeInfo->fullTypeName, memberTypeString );
				StringBuilder_Append(  codeInl, "{\n" );
				for ( u32 componentIndex = 0; componentIndex < typeInfo->numCols; componentIndex++ ) {
					StringBuilder_Appendf( codeInl, "\tthis->%c = scalar;\n", GEN_COMPONENT_NAMES_VECTOR[componentIndex] );
				}
				StringBuilder_Append(  codeInl, "}\n\n" );

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
				StringBuilder_Append( codeInl, "{\n" );
				for ( u32 componentIndex = 0; componentIndex < typeInfo->numCols; componentIndex++ ) {
					const char componentName = GEN_COMPONENT_NAMES_VECTOR[componentIndex];

					StringBuilder_Appendf( codeInl, "\tthis->%c = %c;\n", componentName, componentName );
				}
				StringBuilder_Append( codeInl, "}\n\n" );

				// copy ctors
				for ( u32 otherVecComponentIndex = 2; otherVecComponentIndex <= typeInfo->numCols; otherVecComponentIndex++ ) {
					const char* otherTypeName = String_TPrintf( tempStorage, "%s%d", Gen_GetTypeString( typeInfo->type ), otherVecComponentIndex );

					StringBuilder_Appendf( codeInl, "%s::%s( const %s& other )\n", typeInfo->fullTypeName, typeInfo->fullTypeName, otherTypeName );
					StringBuilder_Append(  codeInl, "{\n" );
					for ( u32 componentIndex = 0; componentIndex < otherVecComponentIndex; componentIndex++ ) {
						const char componentName = GEN_COMPONENT_NAMES_VECTOR[componentIndex];

						StringBuilder_Appendf( codeInl, "\tthis->%c = other.%c;\n", componentName, componentName );
					}
					StringBuilder_Append(  codeInl, "}\n\n" );
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

			// swizzle functions
			if ( generateConstructors ) {
				StringBuilder_Appendf( codeInl, "\n// swizzle functions\n" );

				GenerateSwizzleFunctions( tempStorage, codeInl, typeInfo, GEN_COMPONENT_NAMES_VECTOR, GenerateSwizzleFunc_Impl );

				if ( flags & GENERATOR_FLAG_VECTOR_UNIONS ) {
					GenerateSwizzleFunctions( tempStorage, codeInl, typeInfo, GEN_COMPONENT_NAMES_COLOR, GenerateSwizzleFunc_Impl );
				}
			}

			const char* fileNameInl = String_TPrintf( tempStorage, "%s/%s.inl", generatedCodePath, typeInfo->fullTypeName );

			FS_WriteEntireFile( fileNameInl, codeInl->str, codeInl->length );
		}

		Mem_Reset( tempStorage );
	}

	// vector functions
	{
		stringBuilder_t* code = StringBuilder_Create( tempStorage, 256 * KB_TO_BYTES );

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
static void GenerateFunction_All_Matrix( allocatorLinear_t* tempStorage, const typeInfo_t* typeInfo, const typeInfo_t* memberTypeInfo, stringBuilder_t* code, const generatorFlags_t flags ) {
	assert( tempStorage );
	assert( typeInfo );
	assert( memberTypeInfo );
	assert( code );

	if ( typeInfo->type != GEN_TYPE_BOOL ) {
		return;
	}

	const char* allFuncMatrixStr = Gen_GetFuncName_Vector( tempStorage, typeInfo, flags, GEN_FUNCTION_NAME_ALL );
	const char* allFuncVectorStr = Gen_GetFuncName_Vector( tempStorage, memberTypeInfo, flags, GEN_FUNCTION_NAME_ALL );

	StringBuilder_Append(  code, "// Returns true if ALL components of the 'x' are true, otherwise returns false.\n" );
	StringBuilder_Appendf( code, "HLML_INLINE bool %s( const %s* x )\n", allFuncMatrixStr, typeInfo->fullTypeName );
	StringBuilder_Append(  code, "{\n" );
	StringBuilder_Append(  code, "\treturn\n" );

	for ( u32 row = 0; row < typeInfo->numRows; row++ ) {
		StringBuilder_Appendf( code, "\t\t%s( &x->rows[%d] )", allFuncVectorStr, row );

		if ( row != typeInfo->numRows - 1 ) {
			StringBuilder_Append( code, " &&\n" );
		}
	}

	StringBuilder_Append(  code, ";\n}\n\n" );
}

static void GenerateFunction_Any_Matrix( allocatorLinear_t* tempStorage, const typeInfo_t* typeInfo, const typeInfo_t* memberTypeInfo, stringBuilder_t* code, const generatorFlags_t flags ) {
	assert( tempStorage );
	assert( typeInfo );
	assert( memberTypeInfo );
	assert( code );

	if ( typeInfo->type != GEN_TYPE_BOOL ) {
		return;
	}

	const char* anyFuncStrMatrix = Gen_GetFuncName_Vector( tempStorage, typeInfo, flags, GEN_FUNCTION_NAME_ANY );
	const char* anyFuncStrVector = Gen_GetFuncName_Vector( tempStorage, memberTypeInfo, flags, GEN_FUNCTION_NAME_ANY );

	StringBuilder_Append(  code, "// Returns true if ANY one component of 'x' is true, otherwise returns false.\n" );
	StringBuilder_Appendf( code, "HLML_INLINE bool %s( const %s* x )\n", anyFuncStrMatrix, typeInfo->fullTypeName );
	StringBuilder_Append(  code, "{\n" );
	StringBuilder_Append(  code, "\treturn\n" );

	for ( u32 row = 0; row < typeInfo->numRows; row++ ) {
		StringBuilder_Appendf( code, "\t\t%s( &x->rows[%d] )", anyFuncStrVector, row );

		if ( row != typeInfo->numRows - 1 ) {
			StringBuilder_Append( code, " ||\n" );
		}
	}

	StringBuilder_Append(  code, ";\n}\n\n" );
}

static void GenerateFunction_Identity_Matrix( allocatorLinear_t* tempStorage, const typeInfo_t* typeInfo, const typeInfo_t* memberTypeInfo, stringBuilder_t* code, const generatorStrings_t* strings, const generatorFlags_t flags ) {
	assert( tempStorage );
	assert( typeInfo );
	assert( memberTypeInfo );
	assert( code );
	assert( strings );

	const float32 valuesIdentity[4][4] = {
		{ 1.0f, 0.0f, 0.0f, 0.0f },
		{ 0.0f, 1.0f, 0.0f, 0.0f },
		{ 0.0f, 0.0f, 1.0f, 0.0f },
		{ 0.0f, 0.0f, 0.0f, 1.0f }
	};

	const char* identityFuncStr = Gen_GetFuncName_Vector( tempStorage, typeInfo, flags, GEN_FUNCTION_NAME_IDENTITY );

	StringBuilder_Append(  code, "// Sets the matrix to an identity matrix.\n" );
	StringBuilder_Appendf( code, "HLML_INLINE void %s( %s%s mat )\n", identityFuncStr, typeInfo->fullTypeName, strings->parmPassByStr );
	StringBuilder_Append(  code, "{\n" );

	for ( u32 row = 0; row < typeInfo->numRows; row++ ) {
		StringBuilder_Appendf( code, "\tmat%srows[%d] = HLML_CONSTRUCT( %s ) { ", strings->parmAccessOperatorStr, row, memberTypeInfo->fullTypeName );
		for ( u32 col = 0; col < typeInfo->numCols; col++ ) {
			const char* valueStr = Gen_GetNumericLiteral( tempStorage, typeInfo->type, valuesIdentity[row][col], 1.0f );

			StringBuilder_Appendf( code, "%s", valueStr );

			if ( col != typeInfo->numCols - 1 ) {
				StringBuilder_Append( code, ", " );
			}
		}
		StringBuilder_Append( code, " };\n" );
	}

	StringBuilder_Append(  code, "}\n\n" );
}

static void GenerateFunction_Transpose_Matrix( allocatorLinear_t* tempStorage, const typeInfo_t* typeInfo, stringBuilder_t* code, const generatorStrings_t* strings, const generatorFlags_t flags ) {
	assert( tempStorage );
	assert( typeInfo );
	assert( code );
	assert( strings );

	// create transposed type, reverse rows and cols
	const char* transposeTypeName = String_TPrintf( tempStorage, "%s%dx%d", Gen_GetTypeString( typeInfo->type ), typeInfo->numCols, typeInfo->numRows );

	const char* transposeFuncStr = Gen_GetFuncName_Vector( tempStorage, typeInfo, flags, GEN_FUNCTION_NAME_TRANSPOSE );

	StringBuilder_Append(  code, "// Returns a copy of the matrix that is transposed, where the value of each row is set to the value of each column and vice versa.\n" );
	StringBuilder_Appendf( code, "HLML_INLINE %s %s( const %s%s mat )\n", transposeTypeName, transposeFuncStr, typeInfo->fullTypeName, strings->parmPassByStr );
	StringBuilder_Append(  code, "{\n" );
	StringBuilder_Appendf( code, "\treturn HLML_CONSTRUCT( %s )\n", transposeTypeName );
	StringBuilder_Append(  code, "\t{\n" );

	// row/col iteration order reversed here because we are returning the transposed type
	for ( u32 col = 0; col < typeInfo->numCols; col++ ) {
		StringBuilder_Append( code, "\t\t" );

		for ( u32 row = 0; row < typeInfo->numRows; row++ ) {
			StringBuilder_Appendf( code, "mat%srows[%d].%c", strings->parmAccessOperatorStr, row, GEN_COMPONENT_NAMES_VECTOR[col] );

			if ( row + col != ( typeInfo->numRows - 1 ) + ( typeInfo->numCols - 1 ) ) {
				StringBuilder_Append( code, "," );
			}

			if ( row != typeInfo->numRows - 1 ) {
				StringBuilder_Append( code, " " );
			} else {
				StringBuilder_Append( code, "\n" );
			}
		}
	}

	StringBuilder_Append(  code, "\t};\n" );
	StringBuilder_Append(  code, "}\n\n" );
}

static void GenerateFunction_Determinant_Matrix( allocatorLinear_t* tempStorage, const typeInfo_t* typeInfo, const typeInfo_t* memberTypeInfo, stringBuilder_t* code, const generatorStrings_t* strings, const generatorFlags_t flags ) {
	assert( tempStorage );
	assert( typeInfo );
	assert( memberTypeInfo );
	assert( code );
	assert( strings );

	if ( typeInfo->type == GEN_TYPE_BOOL || typeInfo->type == GEN_TYPE_UINT ) {
		return;
	}

	if ( typeInfo->numRows != typeInfo->numCols ) {
		return;
	}

	const char* memberTypeString = Gen_GetMemberTypeString( typeInfo->type );

	const char* determinantFuncStr = Gen_GetFuncName_Vector( tempStorage, typeInfo, flags, GEN_FUNCTION_NAME_DETERMINANT );

	StringBuilder_Append(  code, "// Returns the determinant of the matrix.\n" );
	StringBuilder_Appendf( code, "HLML_INLINE %s %s( const %s%s mat )\n", memberTypeString, determinantFuncStr, typeInfo->fullTypeName, strings->parmPassByStr );
	StringBuilder_Appendf( code, "{\n" );
	switch ( typeInfo->numRows ) {
		case 2: {
			StringBuilder_Appendf( code, "\treturn mat%srows[0].x * mat%srows[1].y - mat%srows[1].x * mat%srows[0].y;\n", strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr );
			break;
		}

		case 3: {
			StringBuilder_Append(  code, "\treturn\n" );
			StringBuilder_Appendf( code, "\t\t+ mat%srows[0].x * ( mat%srows[1].y * mat%srows[2].z - mat%srows[2].y * mat%srows[1].z ) \n", strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr );
			StringBuilder_Appendf( code, "\t\t- mat%srows[0].y * ( mat%srows[1].x * mat%srows[2].z - mat%srows[2].x * mat%srows[1].z ) \n", strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr );
			StringBuilder_Appendf( code, "\t\t+ mat%srows[0].z * ( mat%srows[1].x * mat%srows[2].y - mat%srows[2].x * mat%srows[1].y );\n", strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr );
			break;
		}

		case 4: {
			StringBuilder_Append(  code, "\t// using glm's method where you basically take determinants from each sub matrix and cache the repeat occurences\n" );
			StringBuilder_Appendf( code, "\t%s sub00 = mat%srows[2].z * mat%srows[3].w - mat%srows[3].z * mat%srows[2].w;\n", memberTypeString, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr );
			StringBuilder_Appendf( code, "\t%s sub01 = mat%srows[2].y * mat%srows[3].w - mat%srows[2].w * mat%srows[3].y;\n", memberTypeString, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr );
			StringBuilder_Appendf( code, "\t%s sub02 = mat%srows[2].y * mat%srows[3].z - mat%srows[3].y * mat%srows[2].z;\n", memberTypeString, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr );
			StringBuilder_Appendf( code, "\t%s sub03 = mat%srows[2].x * mat%srows[3].w - mat%srows[3].x * mat%srows[2].w;\n", memberTypeString, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr );
			StringBuilder_Appendf( code, "\t%s sub04 = mat%srows[2].x * mat%srows[3].z - mat%srows[3].x * mat%srows[2].z;\n", memberTypeString, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr );
			StringBuilder_Appendf( code, "\t%s sub05 = mat%srows[2].x * mat%srows[3].y - mat%srows[3].x * mat%srows[2].y;\n", memberTypeString, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr );
			StringBuilder_Append(  code, "\n" );
			StringBuilder_Appendf( code, "\t%s cofactor = HLML_CONSTRUCT( %s )\n", memberTypeInfo->fullTypeName, memberTypeInfo->fullTypeName );
			StringBuilder_Append(  code, "\t{\n" );
			StringBuilder_Appendf( code, "\t\t ( ( ( mat%srows[1].y * sub00 ) - ( mat%srows[1].z * sub01 ) ) + ( mat%srows[1].w * sub02 ) ),\n", strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr );
			StringBuilder_Appendf( code, "\t\t-( ( ( mat%srows[1].x * sub00 ) - ( mat%srows[1].z * sub03 ) ) + ( mat%srows[1].w * sub04 ) ),\n", strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr );
			StringBuilder_Appendf( code, "\t\t ( ( ( mat%srows[1].x * sub01 ) - ( mat%srows[1].y * sub03 ) ) + ( mat%srows[1].w * sub05 ) ),\n", strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr );
			StringBuilder_Appendf( code, "\t\t-( ( ( mat%srows[1].x * sub02 ) - ( mat%srows[1].y * sub04 ) ) + ( mat%srows[1].z * sub05 ) ) \n", strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr );
			StringBuilder_Append(  code, "\t};\n" );
			StringBuilder_Append(  code, "\n" );
			StringBuilder_Append(  code, "\treturn\n" );
			StringBuilder_Appendf( code, "\t\tmat%srows[0].x * cofactor.x + mat%srows[0].y * cofactor.y +\n", strings->parmAccessOperatorStr, strings->parmAccessOperatorStr );
			StringBuilder_Appendf( code, "\t\tmat%srows[0].z * cofactor.z + mat%srows[0].w * cofactor.w; \n", strings->parmAccessOperatorStr, strings->parmAccessOperatorStr );
			break;
		}
	}
	StringBuilder_Append( code, "}\n" );
	StringBuilder_Append( code, "\n" );
}

static void GenerateFunction_Inverse_Matrix( allocatorLinear_t* tempStorage, const typeInfo_t* typeInfo, const typeInfo_t* memberTypeInfo, stringBuilder_t* code, const generatorStrings_t* strings, const generatorFlags_t flags ) {
	assert( tempStorage );
	assert( typeInfo );
	assert( memberTypeInfo );
	assert( code );
	assert( strings );

	if ( !Gen_TypeIsFloatingPoint( typeInfo->type ) ) {
		return;
	}

	// true inverse can only be done for NxN matrices
	// only pseudo-inverse can be done for NxM matrices where N != M
	if ( typeInfo->numRows != typeInfo->numCols ) {
		return;
	}

	const char* inverseFuncStr = Gen_GetFuncName_Vector( tempStorage, typeInfo, flags, GEN_FUNCTION_NAME_INVERSE );
	const char* determinantFuncStr = Gen_GetFuncName_Vector( tempStorage, typeInfo, flags, GEN_FUNCTION_NAME_DETERMINANT );

	const char* addVectorFuncStr = Gen_GetFuncName_VectorArithmeticVector( tempStorage, memberTypeInfo, GEN_OP_ARITHMETIC_ADD );
	const char* subVectorFuncStr = Gen_GetFuncName_VectorArithmeticVector( tempStorage, memberTypeInfo, GEN_OP_ARITHMETIC_SUB );
	const char* mulVectorFuncStr = Gen_GetFuncName_VectorArithmeticVector( tempStorage, memberTypeInfo, GEN_OP_ARITHMETIC_MUL );
	const char* mulMatrixScalarFuncStr = Gen_GetFuncName_VectorArithmeticScalar( tempStorage, typeInfo, GEN_OP_ARITHMETIC_MUL );

	const char* memberTypeString = Gen_GetMemberTypeString( typeInfo->type );

	const char* oneStr = Gen_GetNumericLiteral( tempStorage, typeInfo->type, 1.0f, 1 );

	StringBuilder_Append(  code,
		"// Returns a copy of the matrix that is inversed.\n"
		"// This is only applicable for square matrices.\n"
	);
	StringBuilder_Appendf( code, "HLML_INLINE %s %s( const %s%s mat )\n", typeInfo->fullTypeName, inverseFuncStr, typeInfo->fullTypeName, strings->parmPassByStr );
	StringBuilder_Append(  code, "{\n" );

	switch ( typeInfo->numRows ) {
		case 2: {
			StringBuilder_Appendf( code, "\tconst %s invdet = %s / %s( mat );\n", memberTypeString, oneStr, determinantFuncStr );
			StringBuilder_Appendf( code, "\treturn HLML_CONSTRUCT( %s )\n", typeInfo->fullTypeName );
			StringBuilder_Append(  code, "\t{\n" );
			StringBuilder_Appendf( code, "\t\t mat%srows[1].y * invdet, -mat%srows[0].y * invdet,\n", strings->parmAccessOperatorStr, strings->parmAccessOperatorStr );
			StringBuilder_Appendf( code, "\t\t-mat%srows[1].x * invdet,  mat%srows[0].x * invdet\n", strings->parmAccessOperatorStr, strings->parmAccessOperatorStr );
			StringBuilder_Append(  code, "\t};\n" );
			break;
		}

		case 3: {
			StringBuilder_Appendf( code, "\tconst %s invdet = %s / %s( mat );\n", memberTypeString, oneStr, determinantFuncStr );
			StringBuilder_Appendf( code, "\treturn HLML_CONSTRUCT( %s )\n", typeInfo->fullTypeName );
			StringBuilder_Append(  code, "\t{\n" );
			StringBuilder_Appendf( code, "\t\t ( mat%srows[1].y * mat%srows[2].z - mat%srows[1].z * mat%srows[2].y ) * invdet,\n", strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr );
			StringBuilder_Appendf( code, "\t\t-( mat%srows[0].y * mat%srows[2].z - mat%srows[0].z * mat%srows[2].y ) * invdet,\n", strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr );
			StringBuilder_Appendf( code, "\t\t ( mat%srows[0].y * mat%srows[1].z - mat%srows[0].z * mat%srows[1].y ) * invdet,\n", strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr );
			StringBuilder_Append(  code, "\n" );
			StringBuilder_Appendf( code, "\t\t-( mat%srows[1].x * mat%srows[2].z - mat%srows[1].z * mat%srows[2].x ) * invdet,\n", strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr );
			StringBuilder_Appendf( code, "\t\t ( mat%srows[0].x * mat%srows[2].z - mat%srows[0].z * mat%srows[2].x ) * invdet,\n", strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr );
			StringBuilder_Appendf( code, "\t\t-( mat%srows[0].x * mat%srows[1].z - mat%srows[0].z * mat%srows[1].x ) * invdet,\n", strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr );
			StringBuilder_Append(  code, "\n" );
			StringBuilder_Appendf( code, "\t\t ( mat%srows[1].x * mat%srows[2].y - mat%srows[1].y * mat%srows[2].x ) * invdet,\n", strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr );
			StringBuilder_Appendf( code, "\t\t-( mat%srows[0].x * mat%srows[2].y - mat%srows[0].y * mat%srows[2].x ) * invdet,\n", strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr );
			StringBuilder_Appendf( code, "\t\t ( mat%srows[0].x * mat%srows[1].y - mat%srows[0].y * mat%srows[1].x ) * invdet\n", strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr );
			StringBuilder_Append(  code, "\t};\n" );
			break;
		}

		case 4: {
			StringBuilder_Append(  code, "\t// uses the glm version, which is basically just an optimised version of the adjugate formula\n" );
#if 1
			StringBuilder_Appendf( code, "\t%s coef00 = mat%srows[2].z * mat%srows[3].w - mat%srows[3].z * mat%srows[2].w;\n", memberTypeString, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr );
			StringBuilder_Appendf( code, "\t%s coef02 = mat%srows[1].z * mat%srows[3].w - mat%srows[3].z * mat%srows[1].w;\n", memberTypeString, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr );
			StringBuilder_Appendf( code, "\t%s coef03 = mat%srows[1].z * mat%srows[2].w - mat%srows[2].z * mat%srows[1].w;\n", memberTypeString, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr );
			StringBuilder_Append(  code, "\n" );
			StringBuilder_Appendf( code, "\t%s coef04 = mat%srows[2].y * mat%srows[3].w - mat%srows[3].y * mat%srows[2].w;\n", memberTypeString, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr );
			StringBuilder_Appendf( code, "\t%s coef06 = mat%srows[1].y * mat%srows[3].w - mat%srows[3].y * mat%srows[1].w;\n", memberTypeString, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr );
			StringBuilder_Appendf( code, "\t%s coef07 = mat%srows[1].y * mat%srows[2].w - mat%srows[2].y * mat%srows[1].w;\n", memberTypeString, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr );
			StringBuilder_Append(  code, "\n" );
			StringBuilder_Appendf( code, "\t%s coef08 = mat%srows[2].y * mat%srows[3].z - mat%srows[3].y * mat%srows[2].z;\n", memberTypeString, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr );
			StringBuilder_Appendf( code, "\t%s coef10 = mat%srows[1].y * mat%srows[3].z - mat%srows[3].y * mat%srows[1].z;\n", memberTypeString, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr );
			StringBuilder_Appendf( code, "\t%s coef11 = mat%srows[1].y * mat%srows[2].z - mat%srows[2].y * mat%srows[1].z;\n", memberTypeString, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr );
			StringBuilder_Append(  code, "\n" );
			StringBuilder_Appendf( code, "\t%s coef12 = mat%srows[2].x * mat%srows[3].w - mat%srows[3].x * mat%srows[2].w;\n", memberTypeString, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr );
			StringBuilder_Appendf( code, "\t%s coef14 = mat%srows[1].x * mat%srows[3].w - mat%srows[3].x * mat%srows[1].w;\n", memberTypeString, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr );
			StringBuilder_Appendf( code, "\t%s coef15 = mat%srows[1].x * mat%srows[2].w - mat%srows[2].x * mat%srows[1].w;\n", memberTypeString, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr );
			StringBuilder_Append(  code, "\n" );
			StringBuilder_Appendf( code, "\t%s coef16 = mat%srows[2].x * mat%srows[3].z - mat%srows[3].x * mat%srows[2].z;\n", memberTypeString, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr );
			StringBuilder_Appendf( code, "\t%s coef18 = mat%srows[1].x * mat%srows[3].z - mat%srows[3].x * mat%srows[1].z;\n", memberTypeString, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr );
			StringBuilder_Appendf( code, "\t%s coef19 = mat%srows[1].x * mat%srows[2].z - mat%srows[2].x * mat%srows[1].z;\n", memberTypeString, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr );
			StringBuilder_Append(  code, "\n" );
			StringBuilder_Appendf( code, "\t%s coef20 = mat%srows[2].x * mat%srows[3].y - mat%srows[3].x * mat%srows[2].y;\n", memberTypeString, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr );
			StringBuilder_Appendf( code, "\t%s coef22 = mat%srows[1].x * mat%srows[3].y - mat%srows[3].x * mat%srows[1].y;\n", memberTypeString, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr );
			StringBuilder_Appendf( code, "\t%s coef23 = mat%srows[1].x * mat%srows[2].y - mat%srows[2].x * mat%srows[1].y;\n", memberTypeString, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr );
#else
			StringBuilder_Appendf( code, "\t%s coef00 = mat%srows[2].z * mat%srows[3].w - mat%srows[2].w * mat%srows[3].z;\n", memberTypeString, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr );
			StringBuilder_Appendf( code, "\t%s coef02 = mat%srows[2].y * mat%srows[3].w - mat%srows[2].w * mat%srows[3].y;\n", memberTypeString, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr );
			StringBuilder_Appendf( code, "\t%s coef03 = mat%srows[2].y * mat%srows[3].z - mat%srows[2].z * mat%srows[3].y;\n", memberTypeString, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr );
			StringBuilder_Append(  code, "\n" );
			StringBuilder_Appendf( code, "\t%s coef04 = mat%srows[1].z * mat%srows[3].w - mat%srows[1].w * mat%srows[3].z;\n", memberTypeString, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr );
			StringBuilder_Appendf( code, "\t%s coef06 = mat%srows[1].y * mat%srows[3].w - mat%srows[1].w * mat%srows[3].y;\n", memberTypeString, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr );
			StringBuilder_Appendf( code, "\t%s coef07 = mat%srows[1].y * mat%srows[3].z - mat%srows[1].z * mat%srows[3].y;\n", memberTypeString, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr );
			StringBuilder_Append(  code, "\n" );
			StringBuilder_Appendf( code, "\t%s coef08 = mat%srows[1].z * mat%srows[2].w - mat%srows[1].w * mat%srows[2].z;\n", memberTypeString, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr );
			StringBuilder_Appendf( code, "\t%s coef10 = mat%srows[1].y * mat%srows[2].w - mat%srows[1].w * mat%srows[2].y;\n", memberTypeString, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr );
			StringBuilder_Appendf( code, "\t%s coef11 = mat%srows[1].y * mat%srows[2].z - mat%srows[1].z * mat%srows[2].y;\n", memberTypeString, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr );
			StringBuilder_Append(  code, "\n" );
			StringBuilder_Appendf( code, "\t%s coef12 = mat%srows[2].x * mat%srows[3].w - mat%srows[0].w * mat%srows[3].z;\n", memberTypeString, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr );
			StringBuilder_Appendf( code, "\t%s coef14 = mat%srows[0].y * mat%srows[3].w - mat%srows[0].w * mat%srows[3].y;\n", memberTypeString, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr );
			StringBuilder_Appendf( code, "\t%s coef15 = mat%srows[0].y * mat%srows[3].z - mat%srows[0].z * mat%srows[3].y;\n", memberTypeString, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr );
			StringBuilder_Append(  code, "\n" );
			StringBuilder_Appendf( code, "\t%s coef16 = mat%srows[0].z * mat%srows[2].w - mat%srows[0].w * mat%srows[2].z;\n", memberTypeString, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr );
			StringBuilder_Appendf( code, "\t%s coef18 = mat%srows[0].y * mat%srows[2].w - mat%srows[0].w * mat%srows[2].y;\n", memberTypeString, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr );
			StringBuilder_Appendf( code, "\t%s coef19 = mat%srows[0].y * mat%srows[2].z - mat%srows[0].z * mat%srows[2].y;\n", memberTypeString, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr );
			StringBuilder_Append(  code, "\n" );
			StringBuilder_Appendf( code, "\t%s coef20 = mat%srows[0].z * mat%srows[1].w - mat%srows[0].w * mat%srows[1].z;\n", memberTypeString, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr );
			StringBuilder_Appendf( code, "\t%s coef22 = mat%srows[0].y * mat%srows[1].w - mat%srows[0].w * mat%srows[1].y;\n", memberTypeString, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr );
			StringBuilder_Appendf( code, "\t%s coef23 = mat%srows[0].y * mat%srows[1].z - mat%srows[0].z * mat%srows[1].y;\n", memberTypeString, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr );
#endif
			StringBuilder_Append(  code, "\n" );
			StringBuilder_Appendf( code, "\t%s fac0 = { coef00, coef00, coef02, coef03 };\n", memberTypeInfo->fullTypeName );
			StringBuilder_Appendf( code, "\t%s fac1 = { coef04, coef04, coef06, coef07 };\n", memberTypeInfo->fullTypeName );
			StringBuilder_Appendf( code, "\t%s fac2 = { coef08, coef08, coef10, coef11 };\n", memberTypeInfo->fullTypeName );
			StringBuilder_Appendf( code, "\t%s fac3 = { coef12, coef12, coef14, coef15 };\n", memberTypeInfo->fullTypeName );
			StringBuilder_Appendf( code, "\t%s fac4 = { coef16, coef16, coef18, coef19 };\n", memberTypeInfo->fullTypeName );
			StringBuilder_Appendf( code, "\t%s fac5 = { coef20, coef20, coef22, coef23 };\n", memberTypeInfo->fullTypeName );
			StringBuilder_Append(  code, "\n" );
			StringBuilder_Appendf( code, "\t%s vec0 = { mat%srows[1].x, mat%srows[0].x, mat%srows[0].x, mat%srows[0].x };\n", memberTypeInfo->fullTypeName, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr );
			StringBuilder_Appendf( code, "\t%s vec1 = { mat%srows[1].y, mat%srows[0].y, mat%srows[0].y, mat%srows[0].y };\n", memberTypeInfo->fullTypeName, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr );
			StringBuilder_Appendf( code, "\t%s vec2 = { mat%srows[1].z, mat%srows[0].z, mat%srows[0].z, mat%srows[0].z };\n", memberTypeInfo->fullTypeName, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr );
			StringBuilder_Appendf( code, "\t%s vec3 = { mat%srows[1].w, mat%srows[0].w, mat%srows[0].w, mat%srows[0].w };\n", memberTypeInfo->fullTypeName, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr );
			StringBuilder_Append( code, "\n" );
			if ( flags & GENERATOR_FLAG_GENERATE_OPERATORS ) {
				StringBuilder_Appendf( code, "\t%s inv0 = vec1 * fac0 - vec2 * fac1 + vec3 * fac2;\n", memberTypeInfo->fullTypeName );
				StringBuilder_Appendf( code, "\t%s inv1 = vec0 * fac0 - vec2 * fac3 + vec3 * fac4;\n", memberTypeInfo->fullTypeName );
				StringBuilder_Appendf( code, "\t%s inv2 = vec0 * fac1 - vec1 * fac3 + vec3 * fac5;\n", memberTypeInfo->fullTypeName );
				StringBuilder_Appendf( code, "\t%s inv3 = vec0 * fac2 - vec1 * fac4 + vec2 * fac5;\n", memberTypeInfo->fullTypeName );
				StringBuilder_Append(  code, "\n" );
				StringBuilder_Appendf( code, "\t%s sign0 = %s(  1, -1,  1, -1 );\n", memberTypeInfo->fullTypeName, memberTypeInfo->fullTypeName );
				StringBuilder_Appendf( code, "\t%s sign1 = %s( -1,  1, -1,  1 );\n", memberTypeInfo->fullTypeName, memberTypeInfo->fullTypeName );
				StringBuilder_Append(  code, "\n" );
				StringBuilder_Appendf( code, "\t%s result = %s(\n", typeInfo->fullTypeName, typeInfo->fullTypeName );
				StringBuilder_Append(  code, "\t\tinv0 * sign0,\n" );
				StringBuilder_Append(  code, "\t\tinv1 * sign1,\n" );
				StringBuilder_Append(  code, "\t\tinv2 * sign0,\n" );
				StringBuilder_Append(  code, "\t\tinv3 * sign1\n" );
				StringBuilder_Append(  code, "\t);\n" );
				StringBuilder_Append(  code, "\n" );
				StringBuilder_Appendf( code, "\t%s row0 = %s( result.rows[0][0], result.rows[1][0], result.rows[2][0], result.rows[3][0] );\n", memberTypeInfo->fullTypeName, memberTypeInfo->fullTypeName );
				StringBuilder_Appendf( code, "\t%s dot0 = mat.rows[0] * row0;\n", memberTypeInfo->fullTypeName );
				StringBuilder_Append(  code, "\n" );
				StringBuilder_Appendf( code, "\tconst %s dot1 = ( dot0.x + dot0.y ) + ( dot0.z + dot0.w );\n", memberTypeString );
				StringBuilder_Append(  code, "\n" );
				StringBuilder_Appendf( code, "\tconst %s invdet = %s / dot1;\n", memberTypeString, oneStr );
				StringBuilder_Append(  code, "\n" );
				StringBuilder_Appendf( code, "\treturn result * invdet;\n" );
			} else {
				StringBuilder_Appendf( code, "\t%s inv0mula = %s( &vec1, &fac0 );\n",         memberTypeInfo->fullTypeName, mulVectorFuncStr );
				StringBuilder_Appendf( code, "\t%s inv0mulb = %s( &vec2, &fac1 );\n",         memberTypeInfo->fullTypeName, mulVectorFuncStr );
				StringBuilder_Appendf( code, "\t%s inv0mulc = %s( &vec3, &fac2 );\n",         memberTypeInfo->fullTypeName, mulVectorFuncStr );
				StringBuilder_Appendf( code, "\t%s inv0     = %s( &inv0mula, &inv0mulb );\n", memberTypeInfo->fullTypeName, subVectorFuncStr );
				StringBuilder_Appendf( code, "\tinv0 = %s( &inv0, &inv0mulc );\n",            addVectorFuncStr );
				StringBuilder_Append(  code, "\n" );
				StringBuilder_Appendf( code, "\t%s inv1mula = %s( &vec0, &fac0 );\n",         memberTypeInfo->fullTypeName, mulVectorFuncStr );
				StringBuilder_Appendf( code, "\t%s inv1mulb = %s( &vec2, &fac3 );\n",         memberTypeInfo->fullTypeName, mulVectorFuncStr );
				StringBuilder_Appendf( code, "\t%s inv1mulc = %s( &vec3, &fac4 );\n",         memberTypeInfo->fullTypeName, mulVectorFuncStr );
				StringBuilder_Appendf( code, "\t%s inv1     = %s( &inv1mula, &inv1mulb );\n", memberTypeInfo->fullTypeName, subVectorFuncStr );
				StringBuilder_Appendf( code, "\tinv1 = %s( &inv1, &inv1mulc );\n",            addVectorFuncStr );
				StringBuilder_Append(  code, "\n" );
				StringBuilder_Appendf( code, "\t%s inv2mula = %s( &vec0, &fac1 );\n",         memberTypeInfo->fullTypeName, mulVectorFuncStr );
				StringBuilder_Appendf( code, "\t%s inv2mulb = %s( &vec1, &fac3 );\n",         memberTypeInfo->fullTypeName, mulVectorFuncStr );
				StringBuilder_Appendf( code, "\t%s inv2mulc = %s( &vec3, &fac5 );\n",         memberTypeInfo->fullTypeName, mulVectorFuncStr );
				StringBuilder_Appendf( code, "\t%s inv2     = %s( &inv2mula, &inv2mulb );\n", memberTypeInfo->fullTypeName, subVectorFuncStr );
				StringBuilder_Appendf( code, "\tinv2 = %s( &inv2, &inv2mulc );\n",            addVectorFuncStr );
				StringBuilder_Append(  code, "\n" );
				StringBuilder_Appendf( code, "\t%s inv3mula = %s( &vec0, &fac2 );\n",         memberTypeInfo->fullTypeName, mulVectorFuncStr );
				StringBuilder_Appendf( code, "\t%s inv3mulb = %s( &vec1, &fac4 );\n",         memberTypeInfo->fullTypeName, mulVectorFuncStr );
				StringBuilder_Appendf( code, "\t%s inv3mulc = %s( &vec2, &fac5 );\n",         memberTypeInfo->fullTypeName, mulVectorFuncStr );
				StringBuilder_Appendf( code, "\t%s inv3     = %s( &inv3mula, &inv3mulb );\n", memberTypeInfo->fullTypeName, subVectorFuncStr );
				StringBuilder_Appendf( code, "\tinv3 = %s( &inv3, &inv3mulc );\n",            addVectorFuncStr );
				StringBuilder_Append(  code, "\n" );
				StringBuilder_Append(  code, "\n" );
				StringBuilder_Appendf( code, "\t%s sign0 = {  1, -1,  1, -1 };\n", memberTypeInfo->fullTypeName );
				StringBuilder_Appendf( code, "\t%s sign1 = { -1,  1, -1,  1 };\n", memberTypeInfo->fullTypeName );
				StringBuilder_Append(  code, "\n" );
				StringBuilder_Appendf( code, "\t%s result = {\n", typeInfo->fullTypeName );
				StringBuilder_Appendf( code, "\t\t%s( &inv0, &sign0 ),\n", mulVectorFuncStr );
				StringBuilder_Appendf( code, "\t\t%s( &inv1, &sign1 ),\n", mulVectorFuncStr );
				StringBuilder_Appendf( code, "\t\t%s( &inv2, &sign0 ),\n", mulVectorFuncStr );
				StringBuilder_Appendf( code, "\t\t%s( &inv3, &sign1 )\n", mulVectorFuncStr );
				StringBuilder_Append(  code, "\t};\n" );
				StringBuilder_Append(  code, "\n" );
				StringBuilder_Appendf( code, "\t%s col0 = { result.rows[0].x, result.rows[1].x, result.rows[2].x, result.rows[3].x };\n", memberTypeInfo->fullTypeName );
				StringBuilder_Appendf( code, "\t%s dot0 = %s( &mat->rows[0], &col0 );\n", memberTypeInfo->fullTypeName, mulVectorFuncStr );
				StringBuilder_Append(  code, "\n" );
				StringBuilder_Appendf( code, "\tconst %s dot1 = ( dot0.x + dot0.y ) + ( dot0.z + dot0.w );\n", memberTypeString );
				StringBuilder_Append(  code, "\n" );
				StringBuilder_Appendf( code, "\tconst %s invdet = %s / dot1;\n", memberTypeString, oneStr );
				StringBuilder_Append(  code, "\n" );
				StringBuilder_Appendf( code, "\treturn %s( &result, invdet );\n", mulMatrixScalarFuncStr );
			}
			break;
		}
	}
	StringBuilder_Append( code, "}\n\n" );
}

static void GenerateFunction_Multiply_Matrix( allocatorLinear_t* tempStorage, const typeInfo_t* typeInfo, stringBuilder_t* code, const generatorStrings_t* strings, const generatorFlags_t flags ) {
	assert( tempStorage );
	assert( typeInfo );
	assert( code );
	assert( strings );

	if ( typeInfo->type == GEN_TYPE_BOOL ) {
		return;
	}

	const char* typeString = Gen_GetTypeString( typeInfo->type );

	const char* typeNameLhs = typeInfo->fullTypeName;
	const char* typeNameRhs = String_TPrintf( tempStorage, "%s%dx%d", typeString, typeInfo->numCols, typeInfo->numRows );
	const char* typeNameReturn = String_TPrintf( tempStorage, "%s%dx%d", typeString, typeInfo->numRows, typeInfo->numRows );

	const char* matrixMulFuncStr = Gen_GetFuncName_Vector( tempStorage, typeInfo, flags, GEN_FUNCTION_NAME_MUL );

	if ( ( flags & GENERATOR_FLAG_NAME_MANGLING ) == 0 ) {
		matrixMulFuncStr = String_TPrintf( tempStorage, "%sm", matrixMulFuncStr );
	}

	StringBuilder_Append(  code, "// Performs a matrix multiplication with 'lhs' and 'rhs' and returns the result.\n" );
	StringBuilder_Appendf( code, "HLML_INLINE %s %s( const %s%s lhs, const %s%s rhs )\n", typeNameReturn, matrixMulFuncStr, typeNameLhs, strings->parmPassByStr, typeNameRhs, strings->parmPassByStr );
	StringBuilder_Append(  code, "{\n" );
	GetMatrixCodeMultiply( tempStorage, typeInfo, code, strings->parmAccessOperatorStr, false );
	StringBuilder_Append(  code, "}\n\n" );
}

static void GenerateFunction_MultiplyVector_Matrix( allocatorLinear_t* tempStorage, const typeInfo_t* typeInfo, const typeInfo_t* memberTypeInfo, stringBuilder_t* code, const generatorStrings_t* strings, const generatorFlags_t flags ) {
	assert( tempStorage );
	assert( typeInfo );
	assert( memberTypeInfo );
	assert( code );
	assert( strings );

	if ( typeInfo->type == GEN_TYPE_BOOL ) {
		return;
	}

	if ( typeInfo->numRows != typeInfo->numCols ) {
		return;
	}

	const char* mulVectorFuncStr = Gen_GetFuncName_Vector( tempStorage, typeInfo, flags, GEN_FUNCTION_NAME_MUL );

	if ( ( flags & GENERATOR_FLAG_NAME_MANGLING ) == 0 ) {
		mulVectorFuncStr = String_TPrintf( tempStorage, "%sv", mulVectorFuncStr );
	}

	const char* vectorTypeName = memberTypeInfo->fullTypeName;

	StringBuilder_Append(  code, "// Multiplies the vector 'lhs' against the matrix 'rhs' and returns the result.\n" );
	StringBuilder_Appendf( code, "HLML_INLINE %s %s( const %s%s lhs, const %s%s rhs )\n", vectorTypeName, mulVectorFuncStr, vectorTypeName, strings->parmPassByStr, typeInfo->fullTypeName, strings->parmPassByStr );
	StringBuilder_Append(  code, "{\n" );
	GetMatrixCodeMultiplyVector( tempStorage, typeInfo, memberTypeInfo, code, strings->parmAccessOperatorStr, false );
	StringBuilder_Append(  code, "}\n\n" );
}

static void GenerateFunction_Translate_Matrix( allocatorLinear_t* tempStorage, const typeInfo_t* typeInfo, stringBuilder_t* code, const generatorStrings_t* strings, const generatorFlags_t flags ) {
	assert( tempStorage );
	assert( typeInfo );
	assert( code );
	assert( strings );

	if ( typeInfo->type == GEN_TYPE_BOOL ) {
		return;
	}

	if ( typeInfo->numRows < 4 || typeInfo->numCols < typeInfo->numRows ) {
		return;
	}

	u32 vecComponents = typeInfo->numCols - 1;

	const char* typeString = Gen_GetTypeString( typeInfo->type );

	const char* translateFuncStr = Gen_GetFuncName_Vector( tempStorage, typeInfo, flags, GEN_FUNCTION_NAME_TRANSLATE );

	StringBuilder_Append(  code, "// \"Translates\" the matrix.  Adds the last column of 'mat' by the position vector 'vec'.\n" );
	StringBuilder_Appendf( code, "HLML_INLINE %s %s( const %s%s mat, const %s%d%s vec )\n", typeInfo->fullTypeName, translateFuncStr, typeInfo->fullTypeName, strings->parmPassByStr, typeString, vecComponents, strings->parmPassByStr );
	StringBuilder_Append(  code, "{\n" );
	StringBuilder_Appendf( code, "\treturn HLML_CONSTRUCT( %s )\n", typeInfo->fullTypeName );
	StringBuilder_Append(  code, "\t{\n" );
	for ( u32 row = 0; row < typeInfo->numRows; row++ ) {
		StringBuilder_Append(  code, "\t\t" );

		for ( u32 col = 0; col < typeInfo->numCols; col++ ) {
			char componentStr = GEN_COMPONENT_NAMES_VECTOR[col];
			StringBuilder_Appendf( code, "mat%srows[%d].%c", strings->parmAccessOperatorStr, row, componentStr );

			if ( col != typeInfo->numCols - 1 ) {
				StringBuilder_Append( code, ", " );
			} else {
				if ( col == vecComponents && row < vecComponents ) {
					StringBuilder_Appendf( code, " + vec%s%c", strings->parmAccessOperatorStr, GEN_COMPONENT_NAMES_VECTOR[row] );
				}

				if ( row != typeInfo->numRows - 1 ) {
					StringBuilder_Append( code, "," );
				}
			}
		}
		StringBuilder_Append( code, "\n" );
	}
	StringBuilder_Append( code, "\t};\n" );
	StringBuilder_Append( code, "}\n\n" );
}

static void GenerateFunction_Rotate_Matrix( allocatorLinear_t* tempStorage, const typeInfo_t* typeInfo, const typeInfo_t* memberTypeInfo, stringBuilder_t* code, const generatorStrings_t* strings, const generatorFlags_t flags ) {
	assert( tempStorage );
	assert( typeInfo );
	assert( typeInfo->fullTypeName );
	assert( memberTypeInfo );
	assert( memberTypeInfo->fullTypeName );
	assert( code );
	assert( strings );

	if ( !Gen_TypeIsFloatingPoint( typeInfo->type ) ) {
		return;
	}

	if ( typeInfo->numRows < 4 ) {
		return;
	}

	if ( typeInfo->numRows != typeInfo->numCols ) {
		return;
	}

	u32 numRotateVectorComponents = 3;

	const char* typeString = Gen_GetTypeString( typeInfo->type );

	typeInfo_t rotateVectorType = {
		.type			= typeInfo->type,
		.numRows		= 1,
		.numCols		= numRotateVectorComponents,
		.fullTypeName	= String_TPrintf( tempStorage, "%s%d", typeString, numRotateVectorComponents )
	};

	const char* oneStr = Gen_GetNumericLiteral( tempStorage, typeInfo->type, 1.0f, 1 );

	stringBuilder_t* parmListStr = StringBuilder_Create( tempStorage, 64 );
	StringBuilder_Appendf( parmListStr, "const %s%s mat, const %s rad", typeInfo->fullTypeName, strings->parmPassByStr, typeString );
	if ( typeInfo->numCols > 3 ) {
		StringBuilder_Appendf( parmListStr, ", const %s%s axis", rotateVectorType.fullTypeName, strings->parmPassByStr );
	}

	const char* cosFuncStr = Gen_GetBuiltinFunction( tempStorage, typeInfo->type, GEN_BUILTIN_FUNCTION_NAME_COS );
	const char* sinFuncStr = Gen_GetBuiltinFunction( tempStorage, typeInfo->type, GEN_BUILTIN_FUNCTION_NAME_SIN );

	const char* rotateFuncStr = Gen_GetFuncName_Vector( tempStorage, typeInfo, flags, GEN_FUNCTION_NAME_ROTATE );
	const char* normalizedFuncStr = Gen_GetFuncName_Vector( tempStorage, &rotateVectorType, flags, GEN_FUNCTION_NAME_NORMALIZED );

	const char* matrixMulFuncStr = Gen_GetFuncName_Vector( tempStorage, typeInfo, flags, GEN_FUNCTION_NAME_MUL );
	if ( ( flags & GENERATOR_FLAG_NAME_MANGLING ) == 0 ) {
		matrixMulFuncStr = String_TPrintf( tempStorage, "%sm", matrixMulFuncStr );
	}

	StringBuilder_Append(  code, "// Rotates the matrix by the given axis-angle (in radians) and returns the result.\n" );
	StringBuilder_Appendf( code, "HLML_INLINE %s %s( %s )\n", typeInfo->fullTypeName, rotateFuncStr, parmListStr->str );
	StringBuilder_Append(  code, "{\n" );
	StringBuilder_Appendf( code, "\tconst %s c = %s( rad );\n", typeString, cosFuncStr );
	StringBuilder_Appendf( code, "\tconst %s s = %s( rad );\n", typeString, sinFuncStr );
	StringBuilder_Append(  code, "\n" );
	StringBuilder_Appendf( code, "\t%s u = %s( axis );\n", rotateVectorType.fullTypeName, normalizedFuncStr );
	StringBuilder_Appendf( code, "\t%s ic = %s - c;\n", typeString, oneStr );
	StringBuilder_Append(  code, "\n" );
	StringBuilder_Appendf( code, "\t%s rotation = %smat;\n", typeInfo->fullTypeName, strings->parmDereferenceStr );
	StringBuilder_Append(  code, "\trotation.rows[0].x = c + u.x * ic;\n" );
	StringBuilder_Append(  code, "\trotation.rows[0].y = u.x * u.y * ic - u.z * s;\n" );
	StringBuilder_Append(  code, "\trotation.rows[0].z = u.x * u.z * ic + u.y * s;\n" );
	StringBuilder_Append(  code, "\n" );
	StringBuilder_Append(  code, "\trotation.rows[1].x = u.y * u.x * ic + u.z * s;\n" );
	StringBuilder_Append(  code, "\trotation.rows[1].y = c + u.y * ic;\n" );
	StringBuilder_Append(  code, "\trotation.rows[1].z = u.y * u.z * ic - u.x * s;\n" );
	StringBuilder_Append(  code, "\n" );
	StringBuilder_Append(  code, "\trotation.rows[2].x = u.z * u.x * ic - u.y * s;\n" );
	StringBuilder_Append(  code, "\trotation.rows[2].y = u.z * u.y * ic + u.x * s;\n" );
	StringBuilder_Append(  code, "\trotation.rows[2].z = c + u.z * ic;\n" );
	StringBuilder_Append(  code, "\n" );
	StringBuilder_Appendf( code, "\treturn %s( mat, %srotation );\n", matrixMulFuncStr, strings->parmReferenceStr );
	StringBuilder_Append(  code, "}\n\n" );
}

static void GenerateFunction_Scale_Matrix( allocatorLinear_t* tempStorage, const typeInfo_t* typeInfo, stringBuilder_t* code, const generatorStrings_t* strings, const generatorFlags_t flags ) {
	assert( tempStorage );
	assert( typeInfo );
	assert( code );
	assert( strings );

	if ( typeInfo->type == GEN_TYPE_BOOL ) {
		return;
	}

	if ( typeInfo->numRows < 4 || ( typeInfo->numRows != typeInfo->numCols ) ) {
		return;
	}

	const char* typeString = Gen_GetTypeString( typeInfo->type );

	u32 numScaleComponents = 3;

	const char* scaleVectorTypeString = String_TPrintf( tempStorage, "%s%d", typeString, numScaleComponents );

	const char* scaleFuncStr = Gen_GetFuncName_Vector( tempStorage, typeInfo, flags, GEN_FUNCTION_NAME_SCALE );

	StringBuilder_Append(  code, "// Applies a non-uniform scale to the matrix and returns the result.\n" );
	StringBuilder_Appendf( code, "HLML_INLINE %s %s( const %s%s mat, const %s%s scale )\n", typeInfo->fullTypeName, scaleFuncStr, typeInfo->fullTypeName, strings->parmPassByStr, scaleVectorTypeString, strings->parmPassByStr );
	StringBuilder_Append(  code, "{\n" );
	StringBuilder_Appendf( code, "\treturn HLML_CONSTRUCT( %s )\n", typeInfo->fullTypeName );
	StringBuilder_Append(  code, "\t{\n" );
	StringBuilder_Appendf( code, "\t\tmat%srows[0].x * scale%sx,\n", strings->parmAccessOperatorStr, strings->parmAccessOperatorStr );
	StringBuilder_Appendf( code, "\t\tmat%srows[0].y,\n", strings->parmAccessOperatorStr );
	StringBuilder_Appendf( code, "\t\tmat%srows[0].z,\n", strings->parmAccessOperatorStr );
	StringBuilder_Appendf( code, "\t\tmat%srows[0].w,\n", strings->parmAccessOperatorStr );
	StringBuilder_Append(  code, "\n" );
	StringBuilder_Appendf( code, "\t\tmat%srows[1].x,\n", strings->parmAccessOperatorStr );
	StringBuilder_Appendf( code, "\t\tmat%srows[1].y * scale%sy,\n", strings->parmAccessOperatorStr, strings->parmAccessOperatorStr );
	StringBuilder_Appendf( code, "\t\tmat%srows[1].z,\n", strings->parmAccessOperatorStr );
	StringBuilder_Appendf( code, "\t\tmat%srows[1].w,\n", strings->parmAccessOperatorStr );
	StringBuilder_Append(  code, "\n" );
	StringBuilder_Appendf( code, "\t\tmat%srows[2].x,\n", strings->parmAccessOperatorStr );
	StringBuilder_Appendf( code, "\t\tmat%srows[2].y,\n", strings->parmAccessOperatorStr );
	StringBuilder_Appendf( code, "\t\tmat%srows[2].z * scale%sz,\n", strings->parmAccessOperatorStr, strings->parmAccessOperatorStr );
	StringBuilder_Appendf( code, "\t\tmat%srows[2].w,\n", strings->parmAccessOperatorStr );
	StringBuilder_Append(  code, "\n" );
	StringBuilder_Appendf( code, "\t\tmat%srows[3].x,\n", strings->parmAccessOperatorStr );
	StringBuilder_Appendf( code, "\t\tmat%srows[3].y,\n", strings->parmAccessOperatorStr );
	StringBuilder_Appendf( code, "\t\tmat%srows[3].z,\n", strings->parmAccessOperatorStr );
	StringBuilder_Appendf( code, "\t\tmat%srows[3].w\n", strings->parmAccessOperatorStr );
	StringBuilder_Append( code, "\t};\n" );
	StringBuilder_Append( code, "}\n\n" );
}

static void GenerateFunction_Ortho_LH_ZO_Matrix( allocatorLinear_t* tempStorage, const typeInfo_t* typeInfo, stringBuilder_t* code, const generatorFlags_t flags ) {
	assert( tempStorage );
	assert( typeInfo );
	assert( code );

	if ( !Gen_TypeIsFloatingPoint( typeInfo->type ) ) {
		return;
	}

	if ( typeInfo->numRows < 4 || typeInfo->numCols < 4 ) {
		return;
	}

	const char* memberTypeString = Gen_GetMemberTypeString( typeInfo->type );

	const char* zeroStr = Gen_GetNumericLiteral( tempStorage, typeInfo->type, 0.0f, 1 );
	const char* oneStr = Gen_GetNumericLiteral( tempStorage, typeInfo->type, 1.0f, 1 );
	const char* twoStr = Gen_GetNumericLiteral( tempStorage, typeInfo->type, 2.0f, 1 );

	const char* orthoFuncStr = Gen_GetFuncName_Vector( tempStorage, typeInfo, flags, GEN_FUNCTION_NAME_ORTHO_LH_ZO );

	StringBuilder_Append(  code, "// Returns an left-handed orthographic projection matrix with the clip-space range 0 to 1.\n" );
	StringBuilder_Appendf( code, "HLML_INLINE %s %s( const %s left, const %s right, const %s top, const %s bottom, const %s znear, const %s zfar )\n",
			typeInfo->fullTypeName, orthoFuncStr, memberTypeString, memberTypeString, memberTypeString, memberTypeString, memberTypeString, memberTypeString );
	StringBuilder_Appendf( code, "{\n" );
	StringBuilder_Appendf( code, "\t// left-handed, clip space range: zero-to-one\n" );
	StringBuilder_Appendf( code, "\tconst %s right_minus_left = right - left;\n", memberTypeString );
	StringBuilder_Appendf( code, "\tconst %s right_plus_left = right + left;\n", memberTypeString );
	StringBuilder_Appendf( code, "\tconst %s top_minus_bottom = top - bottom;\n", memberTypeString );
	StringBuilder_Appendf( code, "\tconst %s top_plus_bottom = top + bottom;\n", memberTypeString );
	StringBuilder_Appendf( code, "\tconst %s far_minus_near = zfar - znear;\n", memberTypeString );
	StringBuilder_Append(  code, "\n" );
	StringBuilder_Appendf( code, "\treturn HLML_CONSTRUCT( %s )\n", typeInfo->fullTypeName );
	StringBuilder_Append(  code, "\t{\n" );
	StringBuilder_Appendf( code, "\t\t%s / right_minus_left, %s, %s, -right_plus_left / right_minus_left,\n", twoStr, zeroStr, zeroStr );
	StringBuilder_Appendf( code, "\t\t%s, %s / top_minus_bottom, %s, -top_plus_bottom / top_minus_bottom,\n", zeroStr, twoStr, zeroStr );
	StringBuilder_Appendf( code, "\t\t%s, %s, %s / far_minus_near, -znear / far_minus_near,\n", zeroStr, zeroStr, oneStr );
	StringBuilder_Appendf( code, "\t\t%s, %s, %s, %s\n", zeroStr, zeroStr, zeroStr, oneStr );
	StringBuilder_Append(  code, "\t};\n" );
	StringBuilder_Append(  code, "}\n\n" );
}

static void GenerateFunction_Ortho_LH_NO_Matrix( allocatorLinear_t* tempStorage, const typeInfo_t* typeInfo, stringBuilder_t* code, const generatorFlags_t flags ) {
	assert( tempStorage );
	assert( typeInfo );
	assert( code );

	if ( !Gen_TypeIsFloatingPoint( typeInfo->type ) ) {
		return;
	}

	if ( typeInfo->numRows < 4 || typeInfo->numCols < 4 ) {
		return;
	}

	const char* memberTypeString = Gen_GetMemberTypeString( typeInfo->type );

	const char* zeroStr = Gen_GetNumericLiteral( tempStorage, typeInfo->type, 0.0f, 1 );
	const char* oneStr = Gen_GetNumericLiteral( tempStorage, typeInfo->type, 1.0f, 1 );
	const char* twoStr = Gen_GetNumericLiteral( tempStorage, typeInfo->type, 2.0f, 1 );

	const char* orthoFuncStr = Gen_GetFuncName_Vector( tempStorage, typeInfo, flags, GEN_FUNCTION_NAME_ORTHO_LH_NO );

	StringBuilder_Append(  code, "// Returns an left-handed orthographic projection matrix with the clip-space range -1 to 1.\n" );
	StringBuilder_Appendf( code, "HLML_INLINE %s %s( const %s left, const %s right, const %s top, const %s bottom, const %s znear, const %s zfar )\n",
			typeInfo->fullTypeName, orthoFuncStr, memberTypeString, memberTypeString, memberTypeString, memberTypeString, memberTypeString, memberTypeString );
	StringBuilder_Appendf( code, "{\n" );
	StringBuilder_Appendf( code, "\t// left-handed, clip space range: minus-one-to-one\n" );
	StringBuilder_Appendf( code, "\tconst %s right_minus_left = right - left;\n", memberTypeString );
	StringBuilder_Appendf( code, "\tconst %s right_plus_left = right + left;\n", memberTypeString );
	StringBuilder_Appendf( code, "\tconst %s top_minus_bottom = top - bottom;\n", memberTypeString );
	StringBuilder_Appendf( code, "\tconst %s top_plus_bottom = top + bottom;\n", memberTypeString );
	StringBuilder_Appendf( code, "\tconst %s far_minus_near = zfar - znear;\n", memberTypeString );
	StringBuilder_Appendf( code, "\tconst %s far_plus_near = zfar + znear;\n", memberTypeString );
	StringBuilder_Append(  code, "\n" );
	StringBuilder_Appendf( code, "\treturn HLML_CONSTRUCT( %s )\n", typeInfo->fullTypeName );
	StringBuilder_Append(  code, "\t{\n" );
	StringBuilder_Appendf( code, "\t\t%s / right_minus_left, %s, %s, -right_plus_left / right_minus_left,\n", twoStr, zeroStr, zeroStr );
	StringBuilder_Appendf( code, "\t\t%s, %s / top_minus_bottom, %s, -top_plus_bottom / top_minus_bottom,\n", zeroStr, twoStr, zeroStr );
	StringBuilder_Appendf( code, "\t\t%s, %s, %s / far_minus_near, -far_plus_near / far_minus_near,\n", zeroStr, zeroStr, twoStr );
	StringBuilder_Appendf( code, "\t\t%s, %s, %s, %s\n", zeroStr, zeroStr, zeroStr, oneStr );
	StringBuilder_Append(  code, "\t};\n" );
	StringBuilder_Append(  code, "}\n\n" );
}

static void GenerateFunction_Ortho_RH_ZO_Matrix( allocatorLinear_t* tempStorage, const typeInfo_t* typeInfo, stringBuilder_t* code, const generatorFlags_t flags ) {
	assert( tempStorage );
	assert( typeInfo );
	assert( code );

	if ( !Gen_TypeIsFloatingPoint( typeInfo->type ) ) {
		return;
	}

	if ( typeInfo->numRows < 4 || typeInfo->numCols < 4 ) {
		return;
	}

	const char* memberTypeString = Gen_GetMemberTypeString( typeInfo->type );

	const char* zeroStr = Gen_GetNumericLiteral( tempStorage, typeInfo->type, 0.0f, 1 );
	const char* oneStr = Gen_GetNumericLiteral( tempStorage, typeInfo->type, 1.0f, 1 );
	const char* minusOneStr = Gen_GetNumericLiteral( tempStorage, typeInfo->type, -1.0f, 1 );
	const char* twoStr = Gen_GetNumericLiteral( tempStorage, typeInfo->type, 2.0f, 1 );

	const char* orthoFuncStr = Gen_GetFuncName_Vector( tempStorage, typeInfo, flags, GEN_FUNCTION_NAME_ORTHO_RH_ZO );

	StringBuilder_Append(  code, "// Returns an right-handed orthographic projection matrix with the clip-space range 0 to 1.\n" );
	StringBuilder_Appendf( code, "HLML_INLINE %s %s( const %s left, const %s right, const %s top, const %s bottom, const %s znear, const %s zfar )\n",
			typeInfo->fullTypeName, orthoFuncStr, memberTypeString, memberTypeString, memberTypeString, memberTypeString, memberTypeString, memberTypeString );
	StringBuilder_Appendf( code, "{\n" );
	StringBuilder_Appendf( code, "\t// right-handed, clip space range: zero-to-one\n" );
	StringBuilder_Appendf( code, "\tconst %s right_minus_left = right - left;\n", memberTypeString );
	StringBuilder_Appendf( code, "\tconst %s right_plus_left = right + left;\n", memberTypeString );
	StringBuilder_Appendf( code, "\tconst %s top_minus_bottom = top - bottom;\n", memberTypeString );
	StringBuilder_Appendf( code, "\tconst %s top_plus_bottom = top + bottom;\n", memberTypeString );
	StringBuilder_Appendf( code, "\tconst %s far_minus_near = zfar - znear;\n", memberTypeString );
	StringBuilder_Append(  code, "\n" );
	StringBuilder_Appendf( code, "\treturn HLML_CONSTRUCT( %s )\n", typeInfo->fullTypeName );
	StringBuilder_Append(  code, "\t{\n" );
	StringBuilder_Appendf( code, "\t\t%s / right_minus_left, %s, %s, -right_plus_left / right_minus_left,\n", twoStr, zeroStr, zeroStr );
	StringBuilder_Appendf( code, "\t\t%s, %s / top_minus_bottom, %s, -top_plus_bottom / top_minus_bottom,\n", zeroStr, twoStr, zeroStr );
	StringBuilder_Appendf( code, "\t\t%s, %s, %s / far_minus_near, -znear / far_minus_near,\n", zeroStr, zeroStr, minusOneStr );
	StringBuilder_Appendf( code, "\t\t%s, %s, %s, %s\n", zeroStr, zeroStr, zeroStr, oneStr );
	StringBuilder_Append(  code, "\t};\n" );
	StringBuilder_Append(  code, "}\n\n" );
}

static void GenerateFunction_Ortho_RH_NO_Matrix( allocatorLinear_t* tempStorage, const typeInfo_t* typeInfo, stringBuilder_t* code, const generatorFlags_t flags ) {
	assert( tempStorage );
	assert( typeInfo );
	assert( code );

	if ( !Gen_TypeIsFloatingPoint( typeInfo->type ) ) {
		return;
	}

	if ( typeInfo->numRows < 4 || typeInfo->numCols < 4 ) {
		return;
	}

	const char* memberTypeString = Gen_GetMemberTypeString( typeInfo->type );

	const char* zeroStr = Gen_GetNumericLiteral( tempStorage, typeInfo->type, 0.0f, 1 );
	const char* oneStr = Gen_GetNumericLiteral( tempStorage, typeInfo->type, 1.0f, 1 );
	const char* twoStr = Gen_GetNumericLiteral( tempStorage, typeInfo->type, 2.0f, 1 );
	const char* minusTwoStr = Gen_GetNumericLiteral( tempStorage, typeInfo->type, -2.0f, 1 );

	const char* orthoFuncStr = Gen_GetFuncName_Vector( tempStorage, typeInfo, flags, GEN_FUNCTION_NAME_ORTHO_RH_NO );

	StringBuilder_Append(  code, "// Returns an right-handed orthographic projection matrix with the clip-space range -1 to 1.\n" );
	StringBuilder_Appendf( code, "HLML_INLINE %s %s( const %s left, const %s right, const %s top, const %s bottom, const %s znear, const %s zfar )\n",
			typeInfo->fullTypeName, orthoFuncStr, memberTypeString, memberTypeString, memberTypeString, memberTypeString, memberTypeString, memberTypeString );
	StringBuilder_Appendf( code, "{\n" );
	StringBuilder_Appendf( code, "\t// right-handed, clip space range: minus-one-to-one\n" );
	StringBuilder_Appendf( code, "\tconst %s right_minus_left = right - left;\n", memberTypeString );
	StringBuilder_Appendf( code, "\tconst %s right_plus_left = right + left;\n", memberTypeString );
	StringBuilder_Appendf( code, "\tconst %s top_minus_bottom = top - bottom;\n", memberTypeString );
	StringBuilder_Appendf( code, "\tconst %s top_plus_bottom = top + bottom;\n", memberTypeString );
	StringBuilder_Appendf( code, "\tconst %s far_minus_near = zfar - znear;\n", memberTypeString );
	StringBuilder_Appendf( code, "\tconst %s far_plus_near = zfar + znear;\n", memberTypeString );
	StringBuilder_Append(  code, "\n" );
	StringBuilder_Appendf( code, "\treturn HLML_CONSTRUCT( %s )\n", typeInfo->fullTypeName );
	StringBuilder_Append(  code, "\t{\n" );
	StringBuilder_Appendf( code, "\t\t%s / right_minus_left, %s, %s, -right_plus_left / right_minus_left,\n", twoStr, zeroStr, zeroStr );
	StringBuilder_Appendf( code, "\t\t%s, %s / top_minus_bottom, %s, -top_plus_bottom / top_minus_bottom,\n", zeroStr, twoStr, zeroStr );
	StringBuilder_Appendf( code, "\t\t%s, %s, %s / far_minus_near, -far_plus_near / far_minus_near,\n", zeroStr, zeroStr, minusTwoStr );
	StringBuilder_Appendf( code, "\t\t%s, %s, %s, %s\n", zeroStr, zeroStr, zeroStr, oneStr );
	StringBuilder_Append(  code, "\t};\n" );
	StringBuilder_Append(  code, "}\n\n" );
}

static void GenerateFunction_Perspective_LH_ZO_Matrix( allocatorLinear_t* tempStorage, const typeInfo_t* typeInfo, stringBuilder_t* code, const generatorFlags_t flags ) {
	assert( tempStorage );
	assert( typeInfo );
	assert( code );

	if ( !Gen_TypeIsFloatingPoint( typeInfo->type ) ) {
		return;
	}

	if ( typeInfo->numRows != 4 || typeInfo->numCols != 4 ) {
		return;
	}

	const char* perspectiveFuncStr = Gen_GetFuncName_Vector( tempStorage, typeInfo, flags, GEN_FUNCTION_NAME_PERSPECTIVE_LH_ZO );

	const char* memberTypeString = Gen_GetMemberTypeString( typeInfo->type );

	const char* tanFuncStr = Gen_GetBuiltinFunction( tempStorage, typeInfo->type, GEN_BUILTIN_FUNCTION_NAME_TAN );

	const char* zeroStr = Gen_GetNumericLiteral( tempStorage, typeInfo->type, 0.0f, 1 );
	const char* halfStr = Gen_GetNumericLiteral( tempStorage, typeInfo->type, 0.5f, 1 );
	const char* oneStr = Gen_GetNumericLiteral( tempStorage, typeInfo->type, 1.0f, 1 );

	StringBuilder_Append(  code, "// Returns a left-handed perspective projection matrix based on a vertical field-of-view in degrees and an aspect ratio in the clip-space range of 0 to 1.\n" );
	StringBuilder_Appendf( code, "HLML_INLINE %s %s( const %s fovdeg, const %s aspect, const %s znear, const %s zfar )\n",
		typeInfo->fullTypeName, perspectiveFuncStr, memberTypeString, memberTypeString, memberTypeString, memberTypeString );
	StringBuilder_Appendf( code, "{\n" );
	StringBuilder_Append(  code, "\t// left-handed, clip space range: zero-to-one\n" );
	StringBuilder_Appendf( code, "\tconst %s far_minus_near = zfar - znear;\n", memberTypeString );
	StringBuilder_Appendf( code, "\tconst %s tan_half_fov = %s( fovdeg * %s );\n", memberTypeString, tanFuncStr, halfStr );
	StringBuilder_Append(  code, "\n" );
	StringBuilder_Appendf( code, "\treturn HLML_CONSTRUCT( %s )\n", typeInfo->fullTypeName );
	StringBuilder_Append(  code, "\t{\n" );
	StringBuilder_Appendf( code, "\t\t%s / ( aspect * tan_half_fov ), %s, %s, %s,\n", oneStr, zeroStr, zeroStr, zeroStr );
	StringBuilder_Appendf( code, "\t\t%s, %s / tan_half_fov, %s, %s,\n", zeroStr, oneStr, zeroStr, zeroStr );
	StringBuilder_Appendf( code, "\t\t%s, %s, zfar / far_minus_near, -( zfar * znear ) / far_minus_near,\n", zeroStr, zeroStr );
	StringBuilder_Appendf( code, "\t\t%s, %s, %s, %s\n", zeroStr, zeroStr, oneStr, zeroStr );
	StringBuilder_Append(  code, "\t};\n" );
	StringBuilder_Append(  code, "}\n\n" );
}

static void GenerateFunction_Perspective_LH_NO_Matrix( allocatorLinear_t* tempStorage, const typeInfo_t* typeInfo, stringBuilder_t* code, const generatorFlags_t flags ) {
	assert( tempStorage );
	assert( typeInfo );
	assert( code );

	if ( !Gen_TypeIsFloatingPoint( typeInfo->type ) ) {
		return;
	}

	if ( typeInfo->numRows != 4 || typeInfo->numCols != 4 ) {
		return;
	}

	const char* perspectiveFuncStr = Gen_GetFuncName_Vector( tempStorage, typeInfo, flags, GEN_FUNCTION_NAME_PERSPECTIVE_LH_NO );

	const char* memberTypeString = Gen_GetMemberTypeString( typeInfo->type );

	const char* tanFuncStr = Gen_GetBuiltinFunction( tempStorage, typeInfo->type, GEN_BUILTIN_FUNCTION_NAME_TAN );

	const char* zeroStr = Gen_GetNumericLiteral( tempStorage, typeInfo->type, 0.0f, 1 );
	const char* halfStr = Gen_GetNumericLiteral( tempStorage, typeInfo->type, 0.5f, 1 );
	const char* oneStr = Gen_GetNumericLiteral( tempStorage, typeInfo->type, 1.0f, 1 );
	const char* twoStr = Gen_GetNumericLiteral( tempStorage, typeInfo->type, 2.0f, 1 );

	StringBuilder_Append(  code, "// Returns a right-handed perspective projection matrix based on a vertical field-of-view in degrees and an aspect ratio in the clip-space range of -1 to 1.\n" );
	StringBuilder_Appendf( code, "HLML_INLINE %s %s( const %s fovdeg, const %s aspect, const %s znear, const %s zfar )\n",
		typeInfo->fullTypeName, perspectiveFuncStr, memberTypeString, memberTypeString, memberTypeString, memberTypeString );
	StringBuilder_Append(  code, "{\n" );
	StringBuilder_Append(  code, "\t// left-handed, clip space range: minus-one-to-one\n" );
	StringBuilder_Appendf( code, "\tconst %s far_minus_near = zfar - znear;\n", memberTypeString );
	StringBuilder_Appendf( code, "\tconst %s far_plus_near = zfar + znear;\n", memberTypeString );
	StringBuilder_Appendf( code, "\tconst %s tan_half_fov = %s( fovdeg * %s );\n", memberTypeString, tanFuncStr, halfStr );
	StringBuilder_Append(  code, "\n" );
	StringBuilder_Appendf( code, "\treturn HLML_CONSTRUCT( %s )\n", typeInfo->fullTypeName );
	StringBuilder_Append(  code, "\t{\n" );
	StringBuilder_Appendf( code, "\t\t%s / ( aspect * tan_half_fov ), %s, %s, %s,\n", oneStr, zeroStr, zeroStr, zeroStr );
	StringBuilder_Appendf( code, "\t\t%s, %s / tan_half_fov, %s, %s,\n", zeroStr, oneStr, zeroStr, zeroStr );
	StringBuilder_Appendf( code, "\t\t%s, %s, far_plus_near / far_minus_near, -( %s * zfar * znear ) / far_minus_near,\n", zeroStr, zeroStr, twoStr );
	StringBuilder_Appendf( code, "\t\t%s, %s, %s, %s\n", zeroStr, zeroStr, oneStr, zeroStr );
	StringBuilder_Append(  code, "\t};\n" );
	StringBuilder_Append(  code, "}\n\n" );
}

static void GenerateFunction_Perspective_RH_ZO_Matrix( allocatorLinear_t* tempStorage, const typeInfo_t* typeInfo, stringBuilder_t* code, const generatorFlags_t flags ) {
	assert( tempStorage );
	assert( typeInfo );
	assert( code );

	if ( !Gen_TypeIsFloatingPoint( typeInfo->type ) ) {
		return;
	}

	if ( typeInfo->numRows != 4 || typeInfo->numCols != 4 ) {
		return;
	}

	const char* perspectiveFuncStr = Gen_GetFuncName_Vector( tempStorage, typeInfo, flags, GEN_FUNCTION_NAME_PERSPECTIVE_RH_ZO );

	const char* memberTypeString = Gen_GetMemberTypeString( typeInfo->type );

	const char* tanFuncStr = Gen_GetBuiltinFunction( tempStorage, typeInfo->type, GEN_BUILTIN_FUNCTION_NAME_TAN );

	const char* zeroStr = Gen_GetNumericLiteral( tempStorage, typeInfo->type, 0.0f, 1 );
	const char* halfStr = Gen_GetNumericLiteral( tempStorage, typeInfo->type, 0.5f, 1 );
	const char* oneStr = Gen_GetNumericLiteral( tempStorage, typeInfo->type, 1.0f, 1 );
	const char* minusOneStr = Gen_GetNumericLiteral( tempStorage, typeInfo->type, -1.0f, 1 );

	StringBuilder_Append(  code, "// Returns a right-handed perspective projection matrix based on a vertical field-of-view in degrees and an aspect ratio in the clip-space range of 0 to 1.\n" );
	StringBuilder_Appendf( code, "HLML_INLINE %s %s( const %s fovdeg, const %s aspect, const %s znear, const %s zfar )\n",
		typeInfo->fullTypeName, perspectiveFuncStr, memberTypeString, memberTypeString, memberTypeString, memberTypeString );
	StringBuilder_Append(  code, "{\n" );
	StringBuilder_Append(  code, "\t// right-handed, clip space range: zero-to-one\n" );
	StringBuilder_Appendf( code, "\tconst %s tan_half_fov = %s( fovdeg * %s );\n", memberTypeString, tanFuncStr, halfStr );
	StringBuilder_Append(  code, "\n" );
	StringBuilder_Appendf( code, "\treturn HLML_CONSTRUCT( %s )\n", typeInfo->fullTypeName );
	StringBuilder_Append(  code, "\t{\n" );
	StringBuilder_Appendf( code, "\t\t%s / ( aspect * tan_half_fov ), %s, %s, %s,\n", oneStr, zeroStr, zeroStr, zeroStr );
	StringBuilder_Appendf( code, "\t\t%s, %s / tan_half_fov, %s, %s,\n", zeroStr, oneStr, zeroStr, zeroStr );
	StringBuilder_Appendf( code, "\t\t%s, %s, zfar / ( znear - zfar ), -( zfar * znear ) / ( zfar - znear ),\n", zeroStr, zeroStr );
	StringBuilder_Appendf( code, "\t\t%s, %s, %s, %s\n", zeroStr, zeroStr, minusOneStr, zeroStr );
	StringBuilder_Append(  code, "\t};\n" );
	StringBuilder_Append(  code, "}\n\n" );
}

static void GenerateFunction_Perspective_RH_NO_Matrix( allocatorLinear_t* tempStorage, const typeInfo_t* typeInfo, stringBuilder_t* code, const generatorFlags_t flags ) {
	assert( tempStorage );
	assert( typeInfo );
	assert( code );

	if ( !Gen_TypeIsFloatingPoint( typeInfo->type ) ) {
		return;
	}

	if ( typeInfo->numRows != 4 || typeInfo->numCols != 4 ) {
		return;
	}

	const char* perspectiveFuncStr = Gen_GetFuncName_Vector( tempStorage, typeInfo, flags, GEN_FUNCTION_NAME_PERSPECTIVE_RH_NO );

	const char* memberTypeString = Gen_GetMemberTypeString( typeInfo->type );

	const char* tanFuncStr = Gen_GetBuiltinFunction( tempStorage, typeInfo->type, GEN_BUILTIN_FUNCTION_NAME_TAN );

	const char* zeroStr = Gen_GetNumericLiteral( tempStorage, typeInfo->type, 0.0f, 1 );
	const char* halfStr = Gen_GetNumericLiteral( tempStorage, typeInfo->type, 0.5f, 1 );
	const char* oneStr = Gen_GetNumericLiteral( tempStorage, typeInfo->type, 1.0f, 1 );
	const char* twoStr = Gen_GetNumericLiteral( tempStorage, typeInfo->type, 2.0f, 1 );
	const char* minusOneStr = Gen_GetNumericLiteral( tempStorage, typeInfo->type, -1.0f, 1 );

	StringBuilder_Append(  code, "// Returns a right-handed perspective projection matrix based on a vertical field-of-view in degrees and an aspect ratio in the clip-space range of -1 to 1.\n" );
	StringBuilder_Appendf( code, "HLML_INLINE %s %s( const %s fovdeg, const %s aspect, const %s znear, const %s zfar )\n",
		typeInfo->fullTypeName, perspectiveFuncStr, memberTypeString, memberTypeString, memberTypeString, memberTypeString );
	StringBuilder_Append(  code, "{\n" );
	StringBuilder_Append(  code, "\t// right-handed, clip space range: minus-one-to-one\n" );
	StringBuilder_Appendf( code, "\tconst %s far_minus_near = zfar - znear;\n", memberTypeString );
	StringBuilder_Appendf( code, "\tconst %s far_plus_near = zfar + znear;\n", memberTypeString );
	StringBuilder_Appendf( code, "\tconst %s tan_half_fov = %s( fovdeg * %s );\n", memberTypeString, tanFuncStr, halfStr );
	StringBuilder_Append(  code, "\n" );
	StringBuilder_Appendf( code, "\treturn HLML_CONSTRUCT( %s )\n", typeInfo->fullTypeName );
	StringBuilder_Append(  code, "\t{\n" );
	StringBuilder_Appendf( code, "\t\t%s / ( aspect * tan_half_fov ), %s, %s, %s,\n", oneStr, zeroStr, zeroStr, zeroStr );
	StringBuilder_Appendf( code, "\t\t%s, %s / tan_half_fov, %s, %s,\n", zeroStr, oneStr, zeroStr, zeroStr );
	StringBuilder_Appendf( code, "\t\t%s, %s, -far_plus_near / far_minus_near, -( %s * zfar * znear ) / far_minus_near,\n", zeroStr, zeroStr, twoStr );
	StringBuilder_Appendf( code, "\t\t%s, %s, %s, %s\n", zeroStr, zeroStr, minusOneStr, zeroStr );
	StringBuilder_Append(  code, "\t};\n" );
	StringBuilder_Append(  code, "}\n\n" );
}

static void GenerateFunction_LookAt_LH_Matrix( allocatorLinear_t* tempStorage, const typeInfo_t* typeInfo, stringBuilder_t* code, const generatorStrings_t* strings, const generatorFlags_t flags ) {
	assert( tempStorage );
	assert( typeInfo );
	assert( typeInfo->fullTypeName );
	assert( code );
	assert( strings );

	if ( !Gen_TypeIsFloatingPoint( typeInfo->type ) ) {
		return;
	}

	if ( typeInfo->numRows < 4 || typeInfo->numCols < 4 ) {
		return;
	}

	typeInfo_t vectorType = {
		.type = typeInfo->type,
		.numRows = 1,
		.numCols = 3,
		.fullTypeName = String_TPrintf( tempStorage, "%s3", Gen_GetTypeString( vectorType.type ) )
	};

	const char* lookAtFuncStr = Gen_GetFuncName_Vector( tempStorage, typeInfo, flags, GEN_FUNCTION_NAME_LOOK_AT_LH );

	const char* vectorTypeName = vectorType.fullTypeName;

	const char* normalizedFuncStr = Gen_GetFuncName_Vector( tempStorage, &vectorType, flags, GEN_FUNCTION_NAME_NORMALIZED );
	const char* crossFuncStr = Gen_GetFuncName_Vector( tempStorage, &vectorType, flags, GEN_FUNCTION_NAME_CROSS );
	const char* dotFuncStr = Gen_GetFuncName_Vector( tempStorage, &vectorType, flags, GEN_FUNCTION_NAME_DOT );

	const char* zeroStr = Gen_GetNumericLiteral( tempStorage, typeInfo->type, 0.0f, 1 );
	const char* oneStr = Gen_GetNumericLiteral( tempStorage, typeInfo->type, 1.0f, 1 );

	StringBuilder_Append(  code, "// Returns a left-handed orthonormal matrix that is oriented at position 'eye' to look at position 'target'.\n" );
	StringBuilder_Appendf( code, "HLML_INLINE %s %s( const %s%s eye, const %s%s target, const %s%s up )\n",
		typeInfo->fullTypeName, lookAtFuncStr, vectorTypeName, strings->parmPassByStr, vectorTypeName, strings->parmPassByStr, vectorTypeName, strings->parmPassByStr );
	StringBuilder_Append(  code, "{\n" );
	StringBuilder_Append(  code, "\t// left handed\n" );
	if ( flags & GENERATOR_FLAG_GENERATE_OPERATORS ) {
		StringBuilder_Appendf( code, "\tconst %s forward = %s( target - eye );\n", vectorTypeName, normalizedFuncStr );
	} else {
		const char* vectorSubFuncStr = Gen_GetFuncName_VectorArithmeticVector( tempStorage, &vectorType, GEN_OP_ARITHMETIC_SUB );

		StringBuilder_Appendf( code, "\tconst %s eye_to_target = %s( target, eye );\n", vectorTypeName, vectorSubFuncStr );
		StringBuilder_Appendf( code, "\tconst %s forward = %s( %seye_to_target );\n", vectorTypeName, normalizedFuncStr, strings->parmReferenceStr );
	}
	StringBuilder_Appendf( code, "\tconst %s up_cross_forward = %s( up, %sforward );\n", vectorTypeName, crossFuncStr, strings->parmReferenceStr );
	StringBuilder_Appendf( code, "\tconst %s right = %s( %sup_cross_forward );\n", vectorTypeName, normalizedFuncStr, strings->parmReferenceStr );
	StringBuilder_Appendf( code, "\tconst %s up1 = %s( %sforward, %sright );\n", vectorTypeName, crossFuncStr, strings->parmReferenceStr, strings->parmReferenceStr );
	StringBuilder_Append(  code, "\n" );
	StringBuilder_Appendf( code, "\treturn HLML_CONSTRUCT( %s )\n", typeInfo->fullTypeName );
	StringBuilder_Append(  code, "\t{\n" );
	StringBuilder_Appendf( code, "\t\tright.x,   right.y,   right.z,   -%s( %sright, eye ),\n", dotFuncStr, strings->parmReferenceStr );
	StringBuilder_Appendf( code, "\t\tup1.x,     up1.y,     up1.z,     -%s( %sup1, eye ),\n", dotFuncStr, strings->parmReferenceStr );
	StringBuilder_Appendf( code, "\t\tforward.x, forward.y, forward.z, -%s( %sforward, eye ),\n", dotFuncStr, strings->parmReferenceStr );
	StringBuilder_Appendf( code, "\t\t%s, %s, %s, %s\n", zeroStr, zeroStr, zeroStr, oneStr );
	StringBuilder_Append(  code, "\t};\n" );
	StringBuilder_Append(  code, "}\n\n" );
}

static void GenerateFunction_LookAt_RH_Matrix( allocatorLinear_t* tempStorage, const typeInfo_t* typeInfo, stringBuilder_t* code, const generatorStrings_t* strings, const generatorFlags_t flags ) {
	assert( tempStorage );
	assert( typeInfo );
	assert( typeInfo->fullTypeName );
	assert( code );
	assert( strings );

	if ( !Gen_TypeIsFloatingPoint( typeInfo->type ) ) {
		return;
	}

	if ( typeInfo->numRows != 4 || typeInfo->numCols != 4 ) {
		return;
	}

	typeInfo_t vectorType = {
		.type = typeInfo->type,
		.numRows = 1,
		.numCols = 3,
		.fullTypeName = String_TPrintf( tempStorage, "%s3", Gen_GetTypeString( vectorType.type ) )
	};

	const char* lookAtFuncStr = Gen_GetFuncName_Vector( tempStorage, typeInfo, flags, GEN_FUNCTION_NAME_LOOK_AT_RH );

	const char* vectorTypeName = vectorType.fullTypeName;

	const char* normalizedFuncStr = Gen_GetFuncName_Vector( tempStorage, &vectorType, flags, GEN_FUNCTION_NAME_NORMALIZED );
	const char* crossFuncStr = Gen_GetFuncName_Vector( tempStorage, &vectorType, flags, GEN_FUNCTION_NAME_CROSS );
	const char* dotFuncStr = Gen_GetFuncName_Vector( tempStorage, &vectorType, flags, GEN_FUNCTION_NAME_DOT );

	const char* zeroStr = Gen_GetNumericLiteral( tempStorage, typeInfo->type, 0.0f, 1 );
	const char* oneStr = Gen_GetNumericLiteral( tempStorage, typeInfo->type, 1.0f, 1 );

	StringBuilder_Append(  code, "// Returns a right-handed orthonormal matrix that is oriented at position 'eye' to look at position 'target'.\n" );
	StringBuilder_Appendf( code, "HLML_INLINE %s %s( const %s%s eye, const %s%s target, const %s%s up )\n",
		typeInfo->fullTypeName, lookAtFuncStr, vectorTypeName, strings->parmPassByStr, vectorTypeName, strings->parmPassByStr, vectorTypeName, strings->parmPassByStr );
	StringBuilder_Append(  code, "{\n" );
	StringBuilder_Append(  code, "\t// right handed\n" );
	if ( flags & GENERATOR_FLAG_GENERATE_OPERATORS ) {
		StringBuilder_Appendf( code, "\tconst %s forward = %s( target - eye );\n", vectorTypeName, normalizedFuncStr );
	} else {
		const char* vectorSubFuncStr = Gen_GetFuncName_VectorArithmeticVector( tempStorage, &vectorType, GEN_OP_ARITHMETIC_SUB );

		StringBuilder_Appendf( code, "\tconst %s eye_to_target = %s( target, eye );\n", vectorTypeName, vectorSubFuncStr );
		StringBuilder_Appendf( code, "\tconst %s forward = %s( %seye_to_target );\n", vectorTypeName, normalizedFuncStr, strings->parmReferenceStr );
	}
	StringBuilder_Appendf( code, "\tconst %s forward_cross_up = %s( %sforward, up );\n", vectorTypeName, crossFuncStr, strings->parmReferenceStr );
	StringBuilder_Appendf( code, "\tconst %s right = %s( %sforward_cross_up );\n", vectorTypeName, normalizedFuncStr, strings->parmReferenceStr );
	StringBuilder_Appendf( code, "\tconst %s up1 = %s( %sright, %sforward );\n", vectorTypeName, crossFuncStr, strings->parmReferenceStr, strings->parmReferenceStr );
	StringBuilder_Append(  code, "\n" );
	StringBuilder_Appendf( code, "\treturn HLML_CONSTRUCT( %s )\n", typeInfo->fullTypeName );
	StringBuilder_Append(  code, "\t{\n" );
	StringBuilder_Appendf( code, "\t\t right.x,    right.y,    right.z,   -%s( %sright, eye ),\n", dotFuncStr, strings->parmReferenceStr );
	StringBuilder_Appendf( code, "\t\t up1.x,      up1.y,      up1.z,     -%s( %sup1, eye ),\n", dotFuncStr, strings->parmReferenceStr );
	StringBuilder_Appendf( code, "\t\t-forward.x, -forward.y, -forward.z,  %s( %sforward, eye ),\n", dotFuncStr, strings->parmReferenceStr );
	StringBuilder_Appendf( code, "\t\t%s, %s, %s, %s\n", zeroStr, zeroStr, zeroStr, oneStr );
	StringBuilder_Append(  code, "\t};\n" );
	StringBuilder_Append(  code, "}\n\n" );
}

static void GenerateMatrixFiles( allocatorLinear_t* tempStorage, const char* generatedCodePath, const typeInfo_t* typeInfos, const u32 typeInfosCount, const generatorStrings_t* strings, const generatorFlags_t flags ) {
	assert( tempStorage );
	assert( generatedCodePath );
	assert( typeInfos );
	assert( typeInfosCount );

	bool32 cLinkage = flags & GENERATOR_FLAG_C_LINKAGE;
	bool32 generateConstructors = flags & GENERATOR_FLAG_GENERATE_CONSTRUCTORS;
	bool32 generateOperators = flags & GENERATOR_FLAG_GENERATE_OPERATORS;

	bool32 generateInlFile = generateConstructors || generateOperators;

	// matrix types
	for ( u32 typeInfoIndex = 0; typeInfoIndex < typeInfosCount; typeInfoIndex++ ) {
		const typeInfo_t* typeInfo = &typeInfos[typeInfoIndex];

		const char* typeString = Gen_GetTypeString( typeInfo->type );

		const char* memberTypeString = Gen_GetMemberTypeString( typeInfo->type );

		const char* vectorMemberTypeName = String_TPrintf( tempStorage, "%s%d", typeString, typeInfo->numCols );

		// header file
		{
			stringBuilder_t* codeHeader = StringBuilder_Create( tempStorage, KILOBYTES( 10 ) );

			StringBuilder_Append( codeHeader, GEN_FILE_HEADER );

			StringBuilder_Append( codeHeader,
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
				for ( u32 typeIndex = 0; typeIndex < GEN_TYPE_COUNT; typeIndex++ ) {
					const genType_t otherType = (genType_t) typeIndex;

					const char* otherTypeString = Gen_GetTypeString( otherType );

					for ( u32 row = 2; row <= 4; row++ ) {
						for ( u32 col = 2; col <= 4; col++ ) {
							// dont forward declare the same type as what were about to define
							if ( otherType == typeInfo->type && row == typeInfo->numRows && col == typeInfo->numCols ) {
								continue;
							}

							StringBuilder_Appendf( codeHeader, "struct %s%dx%d;\n", otherTypeString, row, col );
						}
					}
				}
			}

			StringBuilder_Append( codeHeader, "\n" );

			StringBuilder_Appendf( codeHeader, "#include \"%s.h\"\n\n", vectorMemberTypeName );

			if ( cLinkage ) {
				StringBuilder_Appendf( codeHeader, "typedef struct %s\n", typeInfo->fullTypeName );
			} else {
				StringBuilder_Appendf( codeHeader, "struct %s\n", typeInfo->fullTypeName );
			}

			StringBuilder_Append(  codeHeader, "{\n" );
			StringBuilder_Appendf( codeHeader, "\t%s rows[%d];\n", vectorMemberTypeName, typeInfo->numRows );

			if ( generateConstructors ) {
				StringBuilder_Append(  codeHeader, "\n" );

				// default ctor
				StringBuilder_Append(  codeHeader, "\t// Default constructor.\n" );
				StringBuilder_Appendf( codeHeader, "\tHLML_INLINE %s() {}\n\n", typeInfo->fullTypeName );

				// diagonal scalar ctor
				StringBuilder_Append(  codeHeader, "\t// Sets each diagonal component of the matrix to the given scalar.\n" );
				StringBuilder_Appendf( codeHeader, "\tHLML_INLINE explicit %s( const %s diagonal );\n\n", typeInfo->fullTypeName, memberTypeString );

				// diagonal vector ctor
				StringBuilder_Append(  codeHeader, "\t// Sets each diagonal component of the matrix to the corresponding vector component.\n" );
				StringBuilder_Appendf( codeHeader, "\tHLML_INLINE %s( const %s& diagonal );\n\n", typeInfo->fullTypeName, vectorMemberTypeName );

				// per-row vector ctor
				StringBuilder_Append(  codeHeader, "\t// Sets each row of the matrix to the corresponding vector.\n" );
				StringBuilder_Appendf( codeHeader, "\tHLML_INLINE %s( ", typeInfo->fullTypeName );
				for ( u32 row = 0; row < typeInfo->numRows; row++ ) {
					StringBuilder_Appendf( codeHeader, "const %s& row%d", vectorMemberTypeName, row );

					if ( row < typeInfo->numRows - 1 ) {
						StringBuilder_Appendf( codeHeader, ", " );
					}
				}
				StringBuilder_Append(  codeHeader, " );\n\n" );

				// per-component scalar ctor
				StringBuilder_Append(  codeHeader, "\t// Sets each component of the matrix to the corresponding scalar value.\n" );
				StringBuilder_Appendf( codeHeader, "\tHLML_INLINE %s( ", typeInfo->fullTypeName );
				for ( u32 row = 0; row < typeInfo->numRows; row++ ) {
					for ( u32 col = 0; col < typeInfo->numCols; col++ ) {
						StringBuilder_Appendf( codeHeader, "const %s m%d%d", memberTypeString, row, col );

						if ( col != ( typeInfo->numCols ) - 1 ) {
							StringBuilder_Append( codeHeader, ", " );
						}
					}

					if ( row != ( typeInfo->numRows ) - 1 ) {
						StringBuilder_Append( codeHeader, ",\n\t\t\t\t\t" );
					}
				}
				StringBuilder_Append(  codeHeader, " );\n\n" );

				// copy ctor
				StringBuilder_Append(  codeHeader, "\t// Copy constructor.\n" );
				StringBuilder_Appendf( codeHeader, "\tHLML_INLINE %s( const %s& mat );\n\n", typeInfo->fullTypeName, typeInfo->fullTypeName );

				// conversion ctors
				for ( u32 typeIndex = 0; typeIndex < GEN_TYPE_COUNT; typeIndex++ ) {
					const genType_t otherType = (genType_t) typeIndex;

					const char* otherTypeString = Gen_GetTypeString( otherType );
					const char* otherMemberTypeString = Gen_GetMemberTypeString( otherType );

					for ( u32 row = 2; row <= 4; row++ ) {
						for ( u32 col = 2; col <= 4; col++ ) {
							if ( otherType == typeInfo->type && row == typeInfo->numRows && col == typeInfo->numCols ) {
								continue;
							}

							StringBuilder_Appendf( codeHeader, "\t// Conversion constructor.  Casts all components of 'mat' from type %s to type %s.\n", otherMemberTypeString, memberTypeString );
							StringBuilder_Appendf( codeHeader, "\tHLML_INLINE explicit %s( const %s%dx%d& mat );\n\n", typeInfo->fullTypeName, otherTypeString, row, col );
						}
					}
				}

				// dtor
				StringBuilder_Appendf( codeHeader, "\tHLML_INLINE ~%s() {}\n\n", typeInfo->fullTypeName );
			}

			if ( generateOperators ) {
				// assignment operator
				StringBuilder_Append(  codeHeader, "\t// Sets each row of the matrix to be the same as the parameter.\n" );
				StringBuilder_Appendf( codeHeader, "\tHLML_INLINE %s operator=( const %s& mat );\n\n", typeInfo->fullTypeName, typeInfo->fullTypeName );

				// array access operators
				StringBuilder_Appendf( codeHeader,
					"\t// Returns the row vector at the given index of the matrix.\n"
					"\t// Index CANNOT be lower than 0 or higher than %d.\n", typeInfo->numRows );
				StringBuilder_Appendf( codeHeader, "\tHLML_INLINE %s& operator[]( const int32_t index );\n\n", vectorMemberTypeName );

				StringBuilder_Appendf( codeHeader,
					"\t// Returns the row vector at the given index of the matrix.\n"
					"\t// Index CANNOT be lower than 0 or higher than %d.\n", typeInfo->numRows );
				StringBuilder_Appendf( codeHeader, "\tHLML_INLINE const %s& operator[]( const int32_t index ) const;\n", vectorMemberTypeName );
			}

			if ( cLinkage ) {
				StringBuilder_Appendf( codeHeader, "} %s;\n", typeInfo->fullTypeName );
			} else {
				StringBuilder_Append(  codeHeader, "};\n" );
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
			stringBuilder_t* codeInl = StringBuilder_Create( tempStorage, KILOBYTES( 16 ) );

			StringBuilder_Appendf( codeInl,
				GEN_FILE_HEADER
				"#pragma once\n\n"
			);

			StringBuilder_Appendf( codeInl, "#include \"%s.h\"\n", typeInfo->fullTypeName );
			StringBuilder_Appendf( codeInl, "#include \"%s.inl\"\n\n", vectorMemberTypeName );

			if ( generateConstructors ) {
				// diagonal scalar ctor
				StringBuilder_Appendf( codeInl, "%s::%s( const %s diagonal )\n", typeInfo->fullTypeName, typeInfo->fullTypeName, memberTypeString );
				StringBuilder_Append(  codeInl, "{\n" );
				for ( u32 row = 0; row < typeInfo->numRows; row++ ) {
					StringBuilder_Appendf( codeInl, "\trows[%d][%d] = diagonal;\n", row, row );
				}
				StringBuilder_Append( codeInl, "}\n\n" );

				// diagonal vector ctor
				StringBuilder_Appendf( codeInl, "%s::%s( const %s& diagonal )\n", typeInfo->fullTypeName, typeInfo->fullTypeName, vectorMemberTypeName );
				StringBuilder_Append(  codeInl, "{\n" );
				for ( u32 row = 0; row < typeInfo->numRows; row++ ) {
					StringBuilder_Appendf( codeInl, "\trows[%d][%d] = diagonal[%d];\n", row, row, row );
				}
				StringBuilder_Append( codeInl, "}\n\n" );

				// per-row vector ctor
				StringBuilder_Append(  codeInl, "// Sets each row of the matrix to the corresponding vector.\n" );
				StringBuilder_Appendf( codeInl, "%s::%s( ", typeInfo->fullTypeName, typeInfo->fullTypeName );
				for ( u32 row = 0; row < typeInfo->numRows; row++ ) {
					StringBuilder_Appendf( codeInl, "const %s& row%d", vectorMemberTypeName, row );

					if ( row < typeInfo->numRows - 1 ) {
						StringBuilder_Append( codeInl, ", " );
					}
				}
				StringBuilder_Append( codeInl, " )\n" );
				StringBuilder_Append( codeInl, "{\n" );
				for ( u32 row = 0; row < typeInfo->numRows; row++ ) {
					StringBuilder_Appendf( codeInl, "\trows[%d] = row%d;\n", row, row );
				}
				StringBuilder_Append( codeInl, "}\n\n" );

				// per-component scalar ctor
				StringBuilder_Append(  codeInl, "// Sets each component of the matrix to the corresponding scalar value.\n" );
				StringBuilder_Appendf( codeInl, "%s::%s( ", typeInfo->fullTypeName, typeInfo->fullTypeName );
				for ( u32 row = 0; row < typeInfo->numRows; row++ ) {
					for ( u32 col = 0; col < typeInfo->numCols; col++ ) {
						StringBuilder_Appendf( codeInl, "const %s m%d%d", memberTypeString, row, col );

						if ( col != ( typeInfo->numCols ) - 1 ) {
							StringBuilder_Append( codeInl, ", " );
						}
					}

					if ( row != ( typeInfo->numRows ) - 1 ) {
						StringBuilder_Append( codeInl, ",\n\t\t\t\t\t" );
					}
				}
				StringBuilder_Append( codeInl, " )\n" );
				StringBuilder_Append( codeInl, "{\n" );
				for ( u32 row = 0; row < typeInfo->numRows; row++ ) {
					StringBuilder_Appendf( codeInl, "\trows[%d] = %s( ", row, vectorMemberTypeName );
					for ( u32 col = 0; col < typeInfo->numCols; col++ ) {
						StringBuilder_Appendf( codeInl, "m%d%d", row, col );

						if ( col < typeInfo->numCols - 1 ) {
							StringBuilder_Append( codeInl, ", " );
						}
					}
					StringBuilder_Append( codeInl, " );\n" );
				}
				StringBuilder_Append( codeInl, "}\n\n" );

				// copy ctor
				StringBuilder_Appendf( codeInl, "%s::%s( const %s& mat )\n", typeInfo->fullTypeName, typeInfo->fullTypeName, typeInfo->fullTypeName );
				StringBuilder_Append(  codeInl, "{\n" );
				for ( u32 row = 0; row < typeInfo->numRows; row++ ) {
					StringBuilder_Appendf( codeInl, "\trows[%d] = mat[%d];\n", row, row );
				}
				StringBuilder_Append(  codeInl, "}\n\n" );

				// conversion ctors
				for ( u32 typeIndex = 0; typeIndex < GEN_TYPE_COUNT; typeIndex++ ) {
					const genType_t otherType = (genType_t) typeIndex;

					const char* otherTypeString = Gen_GetTypeString( otherType );

					for ( u32 row = 2; row <= 4; row++ ) {
						for ( u32 col = 2; col <= 4; col++ ) {
							// dont do the conversion ctor for the same type because we just generated that
							if ( otherType == typeInfo->type && row == typeInfo->numRows && col == typeInfo->numCols ) {
								continue;
							}

							u32 numConvertRows = GEN_MIN( typeInfo->numRows, row );

							StringBuilder_Appendf( codeInl, "%s::%s( const %s%dx%d& mat )\n", typeInfo->fullTypeName, typeInfo->fullTypeName, otherTypeString, row, col );
							StringBuilder_Append(  codeInl, "{\n" );

							for ( u32 i = 0; i < numConvertRows; i++ ) {
								StringBuilder_Appendf( codeInl, "\trows[%d] = %s( mat[%d] );\n", i, vectorMemberTypeName, i );
							}

							StringBuilder_Append(  codeInl, "}\n\n" );
						}
					}
				}
			}

			if ( generateOperators ) {
				// assignment operator
				StringBuilder_Appendf( codeInl, "%s %s::operator=( const %s& other )\n", typeInfo->fullTypeName, typeInfo->fullTypeName, typeInfo->fullTypeName );
				StringBuilder_Append(  codeInl, "{\n" );
				for ( u32 row = 0; row < typeInfo->numRows; row++ ) {
					StringBuilder_Appendf( codeInl, "\trows[%d] = other[%d];\n", row, row );
				}
				StringBuilder_Append( codeInl, "\n" );
				StringBuilder_Append( codeInl, "\treturn *this;\n" );
				StringBuilder_Append( codeInl, "}\n\n" );

				// array operators
				StringBuilder_Appendf( codeInl, "%s& %s::operator[]( const %s index )\n", vectorMemberTypeName, typeInfo->fullTypeName, Gen_GetMemberTypeString( GEN_TYPE_INT ) );
				StringBuilder_Append(  codeInl, "{\n" );
				StringBuilder_Appendf( codeInl, "\tHLML_ASSERT( index >= 0 && index < %d );\n", typeInfo->numRows );
				StringBuilder_Append( codeInl, "\treturn rows[index];\n" );
				StringBuilder_Append(  codeInl, "}\n\n" );

				StringBuilder_Appendf( codeInl, "const %s& %s::operator[]( const %s index ) const\n", vectorMemberTypeName, typeInfo->fullTypeName, Gen_GetMemberTypeString( GEN_TYPE_INT ) );
				StringBuilder_Append(  codeInl, "{\n" );
				StringBuilder_Appendf( codeInl, "\tHLML_ASSERT( index >= 0 && index < %d );\n", typeInfo->numRows );
				StringBuilder_Append( codeInl, "\treturn rows[index];\n" );
				StringBuilder_Append(  codeInl, "}\n" );
			}

			const char* fileNameInl = String_TPrintf( tempStorage, "%s/%s.inl", generatedCodePath, typeInfo->fullTypeName );

			FS_WriteEntireFile( fileNameInl, codeInl->str, codeInl->length );
		}

		Mem_Reset( tempStorage );
	}

	// matrix functions
	{
		stringBuilder_t* code = StringBuilder_Create( tempStorage, KILOBYTES( 512 ) );

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

		for ( u32 i = 0; i < typeInfosCount; i++ ) {
			StringBuilder_Appendf( code, "#include \"%s.h\"\n", typeInfos[i].fullTypeName );
		}
		StringBuilder_Append( code, "\n" );

		StringBuilder_Appendf( code, "#include \"" GEN_FILENAME_FUNCTIONS_VECTOR ".h\"\n\n" );

		for ( u32 typeInfoIndex = 0; typeInfoIndex < typeInfosCount; typeInfoIndex++ ) {
			const typeInfo_t* typeInfo = &typeInfos[typeInfoIndex];

			typeInfo_t vectorMemberType = {
				.type			= typeInfo->type,
				.numRows		= 1,
				.numCols		= typeInfo->numCols,
				.fullTypeName	= String_TPrintf( tempStorage, "%s%d", Gen_GetTypeString( typeInfo->type ), typeInfo->numCols )
			};

			printf( "Matrix functions %s...", typeInfo->fullTypeName );

			StringBuilder_Appendf( code, "// %s\n", typeInfo->fullTypeName );

			GenerateComponentWiseFunctions( tempStorage, typeInfo, &vectorMemberType, code, strings, flags );

			GenerateComponentWiseOperators( tempStorage, typeInfo, code, strings, flags );

			GenerateFunction_All_Matrix( tempStorage, typeInfo, &vectorMemberType, code, flags );
			GenerateFunction_Any_Matrix( tempStorage, typeInfo, &vectorMemberType, code, flags );

			GenerateFunction_Identity_Matrix( tempStorage, typeInfo, &vectorMemberType, code, strings, flags );
			GenerateFunction_Transpose_Matrix( tempStorage, typeInfo, code, strings, flags );
			GenerateFunction_Determinant_Matrix( tempStorage, typeInfo, &vectorMemberType, code, strings, flags );
			GenerateFunction_Inverse_Matrix( tempStorage, typeInfo, &vectorMemberType, code, strings, flags );
			GenerateFunction_Multiply_Matrix( tempStorage, typeInfo, code, strings, flags );
			GenerateFunction_MultiplyVector_Matrix( tempStorage, typeInfo, &vectorMemberType, code, strings, flags );
			GenerateFunction_Translate_Matrix( tempStorage, typeInfo, code, strings, flags );
			GenerateFunction_Rotate_Matrix( tempStorage, typeInfo, &vectorMemberType, code, strings, flags );
			GenerateFunction_Scale_Matrix( tempStorage, typeInfo, code, strings, flags );
			GenerateFunction_Ortho_LH_ZO_Matrix( tempStorage, typeInfo, code, flags );
			GenerateFunction_Ortho_LH_NO_Matrix( tempStorage, typeInfo, code, flags );
			GenerateFunction_Ortho_RH_ZO_Matrix( tempStorage, typeInfo, code, flags );
			GenerateFunction_Ortho_RH_NO_Matrix( tempStorage, typeInfo, code, flags );
			GenerateFunction_Perspective_LH_ZO_Matrix( tempStorage, typeInfo, code, flags );
			GenerateFunction_Perspective_LH_NO_Matrix( tempStorage, typeInfo, code, flags );
			GenerateFunction_Perspective_RH_ZO_Matrix( tempStorage, typeInfo, code, flags );
			GenerateFunction_Perspective_RH_NO_Matrix( tempStorage, typeInfo, code, flags );
			GenerateFunction_LookAt_LH_Matrix( tempStorage, typeInfo, code, strings, flags );
			GenerateFunction_LookAt_RH_Matrix( tempStorage, typeInfo, code, strings, flags );

			printf( "OK.\n" );
		}

		if ( cLinkage ) {
			StringBuilder_Append( code,
				"#ifdef __cplusplus\n"
				"}\n"
				"#endif\n"
			);
		}

		const char* fileNameHeader = String_TPrintf( tempStorage, "%s/%s.h", generatedCodePath, GEN_FILENAME_FUNCTIONS_MATRIX );

		FS_WriteEntireFile( fileNameHeader, code->str, code->length );

		Mem_Reset( tempStorage );
	}
}
static const char* Gen_GetFuncName_Vector_SSE( allocatorLinear_t* tempStorage, const typeInfo_t* typeInfo, const generatorFlags_t flags, const char* funcName ) {
	assert( tempStorage );
	assert( typeInfo );
	assert( funcName );

	const char* actualFuncName = Gen_GetFuncName_Vector( tempStorage, typeInfo, flags, funcName );

	return String_TPrintf( tempStorage, "%s_sse", actualFuncName );
}

typedef enum simdParmListFlagBits_t {
	SIMD_PARM_LIST_FLAG_LHS	= GEN_BIT( 0 ),	// include "lhs" parms
	SIMD_PARM_LIST_FLAG_RHS	= GEN_BIT( 1 ),	// include "rhs" parms
	SIMD_PARM_LIST_FLAG_OUT	= GEN_BIT( 2 ),	// include "out" parms
} simdParmListFlagBits_t;
typedef u32 simdParmListFlags_t;

static void MakeSSEParmList( stringBuilder_t* code, const u32 numComponents, const generatorStrings_t* strings, const simdParmListFlags_t parmFlags ) {
	assert( code );
	assert( numComponents >= 2 );
	assert( numComponents <= 4 );

	//StringBuilder_Append( code, "\n" );

	bool32 genLHS = parmFlags & SIMD_PARM_LIST_FLAG_LHS;
	bool32 genRHS = parmFlags & SIMD_PARM_LIST_FLAG_RHS;
	bool32 genOut = parmFlags & SIMD_PARM_LIST_FLAG_OUT;

	const char* whitespacePaddingIn = ( genOut ) ? "  ": " ";
	const char* whitespacePaddingOut = ( genLHS || genRHS ) ? "      ": " ";

	if ( genLHS ) {
		if ( genRHS || genOut ) {
			StringBuilder_Append( code, "\n\t" );
		}

		for ( u32 i = 0; i < numComponents; i++ ) {
			StringBuilder_Appendf( code, "const __m128%slhs_%c", whitespacePaddingIn, GEN_COMPONENT_NAMES_VECTOR[i] );

			if ( i < numComponents - 1 ) {
				StringBuilder_Append( code, ", " );
			}
		}
	}

	if ( genRHS ) {
		if ( genLHS ) {
			StringBuilder_Append( code, ",\n\t" );
		}

		for ( u32 i = 0; i < numComponents; i++ ) {
			StringBuilder_Appendf( code, "const __m128%srhs_%c", whitespacePaddingIn, GEN_COMPONENT_NAMES_VECTOR[i] );

			if ( i < numComponents - 1 ) {
				StringBuilder_Append( code, ", " );
			}
		}
	}

	if ( genOut ) {
		if ( genLHS || genRHS ) {
			StringBuilder_Append( code, ",\n\t" );
		}

		for ( u32 i = 0; i < numComponents; i++ ) {
			StringBuilder_Appendf( code, "%s__m128%s out_%c", whitespacePaddingOut, strings->parmPassByStr, GEN_COMPONENT_NAMES_VECTOR[i] );
			
			if ( i < numComponents - 1 ) {
				StringBuilder_Append( code, ", " );
			}
		}
	}
}

static void GenerateFunction_Dot_SSE( allocatorLinear_t* tempStorage, stringBuilder_t* code, const typeInfo_t* typeInfo, const generatorStrings_t* strings, const generatorFlags_t flags ) {
	assert( tempStorage );
	assert( code );
	assert( typeInfo );
	assert( typeInfo->fullTypeName );
	assert( strings );

	const char* dotFuncStr = Gen_GetFuncName_Vector_SSE( tempStorage, typeInfo, flags, GEN_FUNCTION_NAME_DOT );

	StringBuilder_Appendf( code, "inline static __m128 %s( ", dotFuncStr );
	MakeSSEParmList( code, typeInfo->numCols, strings, SIMD_PARM_LIST_FLAG_LHS | SIMD_PARM_LIST_FLAG_RHS );
	StringBuilder_Append( code, " )\n" );
	StringBuilder_Append( code, "{\n" );

	for ( u32 i = 0; i < typeInfo->numCols; i++ ) {
		const char componentStr = GEN_COMPONENT_NAMES_VECTOR[i];
		StringBuilder_Appendf( code, "\t__m128 mul_%c = _mm_mul_ps( lhs_%c, rhs_%c );\n", componentStr, componentStr, componentStr );
	}
	StringBuilder_Append( code, "\n" );

	switch ( typeInfo->numCols ) {
		case 2:
			StringBuilder_Appendf( code, "\treturn _mm_add_ps( mul_x, mul_y );\n" );
			break;

		case 3:
			StringBuilder_Append( code, "\t__m128 add = _mm_add_ps( mul_x, mul_y );\n" );
			StringBuilder_Append( code, "\t       add = _mm_add_ps( add,   mul_z );\n" );
			StringBuilder_Append( code, "\treturn add;\n" );
			break;

		case 4:
			StringBuilder_Append( code, "\t__m128 add = _mm_add_ps( mul_x, mul_y );\n" );
			StringBuilder_Append( code, "\t       add = _mm_add_ps( add,   mul_z );\n" );
			StringBuilder_Append( code, "\t       add = _mm_add_ps( add,   mul_w );\n" );
			StringBuilder_Append( code, "\treturn add;\n" );
			break;
	}

	StringBuilder_Append( code, "}\n\n" );
}

static void GenerateFunction_Cross_SSE( allocatorLinear_t* tempStorage, stringBuilder_t* code, const typeInfo_t* typeInfo, const generatorStrings_t* strings, const generatorFlags_t flags ) {
	assert( tempStorage );
	assert( code );
	assert( typeInfo );
	assert( typeInfo->fullTypeName );
	assert( strings );

	if ( typeInfo->numCols != 3 ) {
		return;
	}

	// cross product doesnt use w component
	u32 numComponents = 3;

	const char* crossFuncStr = Gen_GetFuncName_Vector_SSE( tempStorage, typeInfo, flags, GEN_FUNCTION_NAME_CROSS );

	StringBuilder_Appendf( code, "inline static void %s( ", crossFuncStr );
	MakeSSEParmList( code, numComponents, strings, SIMD_PARM_LIST_FLAG_LHS | SIMD_PARM_LIST_FLAG_RHS | SIMD_PARM_LIST_FLAG_OUT );
	StringBuilder_Append(  code, " )\n" );
	StringBuilder_Append(  code, "{\n" );

	StringBuilder_Append(  code, "\t__m128 mul_xa = _mm_mul_ps( lhs_y, rhs_z );\n" );
	StringBuilder_Append(  code, "\t__m128 mul_xb = _mm_mul_ps( lhs_z, rhs_y );\n" );
	StringBuilder_Appendf( code, "\t%sout_x = _mm_sub_ps( mul_xa, mul_xb );\n", strings->parmDereferenceStr );
	StringBuilder_Append(  code, "\n" );

	StringBuilder_Append(  code, "\t__m128 mul_ya = _mm_mul_ps( lhs_z, rhs_x );\n" );
	StringBuilder_Append(  code, "\t__m128 mul_yb = _mm_mul_ps( lhs_x, rhs_z );\n" );
	StringBuilder_Appendf( code, "\t%sout_y = _mm_sub_ps( mul_ya, mul_yb );\n", strings->parmDereferenceStr );
	StringBuilder_Append(  code, "\n" );

	StringBuilder_Append(  code, "\t__m128 mul_za = _mm_mul_ps( lhs_x, rhs_y );\n" );
	StringBuilder_Append(  code, "\t__m128 mul_zb = _mm_mul_ps( lhs_y, rhs_x );\n" );
	StringBuilder_Appendf( code, "\t%sout_z = _mm_sub_ps( mul_za, mul_zb );\n", strings->parmDereferenceStr );

	StringBuilder_Append( code, "}\n\n" );
}

static void GenerateFunction_Lengthsq_SSE( allocatorLinear_t* tempStorage, stringBuilder_t* code, const typeInfo_t* typeInfo, const generatorStrings_t* strings, const generatorFlags_t flags ) {
	assert( tempStorage );
	assert( code );
	assert( typeInfo );
	assert( typeInfo->fullTypeName );
	assert( strings );

	const char* funcName = Gen_GetFuncName_Vector_SSE( tempStorage, typeInfo, flags, GEN_FUNCTION_NAME_LENGTHSQ );

	StringBuilder_Appendf( code, "inline static __m128 %s( ", funcName );
	MakeSSEParmList( code, typeInfo->numCols, strings, SIMD_PARM_LIST_FLAG_LHS );
	StringBuilder_Append( code, " )\n" );
	StringBuilder_Append( code, "{\n" );

	for ( u32 i = 0; i < typeInfo->numCols; i++ ) {
		const char componentStr = GEN_COMPONENT_NAMES_VECTOR[i];
		StringBuilder_Appendf( code, "\t__m128 mul_%c = _mm_mul_ps( lhs_%c, lhs_%c );\n", componentStr, componentStr, componentStr );
	}
	StringBuilder_Append( code, "\n" );

	switch ( typeInfo->numCols ) {
		case 2:
			StringBuilder_Append( code, "\treturn _mm_add_ps( mul_x, mul_y );\n" );
			break;

		case 3:
			StringBuilder_Append( code, "\t__m128 add = _mm_add_ps( mul_x, mul_y );\n" );
			StringBuilder_Append( code, "\t       add = _mm_add_ps( add,   mul_z );\n" );
			StringBuilder_Append( code, "\treturn add;\n" );
			break;

		case 4:
			StringBuilder_Append( code, "\t__m128 add = _mm_add_ps( mul_x, mul_y );\n" );
			StringBuilder_Append( code, "\t       add = _mm_add_ps( add,   mul_z );\n" );
			StringBuilder_Append( code, "\t       add = _mm_add_ps( add,   mul_w );\n" );
			StringBuilder_Append( code, "\treturn add;\n" );
			break;
	}

	StringBuilder_Append( code, "}\n\n" );
}

static void GenerateFunction_Length_SSE( allocatorLinear_t* tempStorage, stringBuilder_t* code, const typeInfo_t* typeInfo, const generatorStrings_t* strings, const generatorFlags_t flags ) {
	assert( tempStorage );
	assert( code );
	assert( typeInfo );
	assert( typeInfo->fullTypeName );
	assert( strings );

	const char* funcName = Gen_GetFuncName_Vector_SSE( tempStorage, typeInfo, flags, GEN_FUNCTION_NAME_LENGTH );
	const char* lengthsqFuncStr = Gen_GetFuncName_Vector_SSE( tempStorage, typeInfo, flags, GEN_FUNCTION_NAME_LENGTHSQ );

	StringBuilder_Appendf( code, "inline static __m128 %s( ", funcName );
	MakeSSEParmList( code, typeInfo->numCols, strings, SIMD_PARM_LIST_FLAG_LHS );
	StringBuilder_Append(  code, " )\n" );
	StringBuilder_Append(  code, "{\n" );
	StringBuilder_Append(  code, "\t" );
	StringBuilder_Appendf( code, "return _mm_sqrt_ps( %s( ", lengthsqFuncStr );
	for ( u32 i = 0; i < typeInfo->numCols; i++ ) {
		StringBuilder_Appendf( code, "lhs_%c", GEN_COMPONENT_NAMES_VECTOR[i] );

		if ( i < typeInfo->numCols - 1 ) {
			StringBuilder_Append( code, ", " );
		}
	}
	StringBuilder_Append(  code, " ) );\n" );
	StringBuilder_Append(  code, "}\n\n" );
}

static void GenerateFunction_Normalize_SSE( allocatorLinear_t* tempStorage, stringBuilder_t* code, const typeInfo_t* typeInfo, const generatorStrings_t* strings, const generatorFlags_t flags ) {
	assert( tempStorage );
	assert( code );
	assert( typeInfo );
	assert( typeInfo->fullTypeName );
	assert( strings );

	const char* funcName = Gen_GetFuncName_Vector_SSE( tempStorage, typeInfo, flags, GEN_FUNCTION_NAME_NORMALIZE );
	const char* lengthSSEFuncStr = Gen_GetFuncName_Vector_SSE( tempStorage, typeInfo, flags, GEN_FUNCTION_NAME_LENGTH );

	// TODO(DM): generated asm isnt good enough - do better!
	StringBuilder_Appendf( code, "inline static void %s( ", funcName );
	MakeSSEParmList( code, typeInfo->numCols, strings, SIMD_PARM_LIST_FLAG_LHS | SIMD_PARM_LIST_FLAG_OUT );
	StringBuilder_Append(  code, " )\n" );
	StringBuilder_Append(  code, "{\n" );
	StringBuilder_Appendf( code, "\t__m128 invlen = %s( ", lengthSSEFuncStr );
	for ( u32 i = 0; i < typeInfo->numCols; i++ ) {
		StringBuilder_Appendf( code, "lhs_%c", GEN_COMPONENT_NAMES_VECTOR[i] );

		if ( i < typeInfo->numCols - 1 ) {
			StringBuilder_Append( code, ", " );
		}
	}
	StringBuilder_Append(  code, " );\n" );
	StringBuilder_Append(  code, "\tinvlen = _mm_rcp_ps( invlen );\n" );
	StringBuilder_Append(  code, "\n" );
	for ( u32 i = 0; i < typeInfo->numCols; i++ ) {
		const char componentStr = GEN_COMPONENT_NAMES_VECTOR[i];

		StringBuilder_Appendf( code, "\t%sout_%c = _mm_mul_ps( lhs_%c, invlen );\n", strings->parmDereferenceStr, componentStr, componentStr );
	}
	StringBuilder_Append(  code, "}\n\n" );
}

static void GenerateFunction_Distancesq_SSE( allocatorLinear_t* tempStorage, stringBuilder_t* code, const typeInfo_t* typeInfo, const generatorStrings_t* strings, const generatorFlags_t flags ) {
	assert( tempStorage );
	assert( code );
	assert( typeInfo );
	assert( typeInfo->fullTypeName );
	assert( strings );

	const char* funcName = Gen_GetFuncName_Vector_SSE( tempStorage, typeInfo, flags, GEN_FUNCTION_NAME_DISTANCESQ );

	StringBuilder_Appendf( code, "inline static __m128 %s( ", funcName );
	MakeSSEParmList( code, typeInfo->numCols, strings, SIMD_PARM_LIST_FLAG_LHS | SIMD_PARM_LIST_FLAG_RHS );
	StringBuilder_Append(  code, " )\n" );
	StringBuilder_Append(  code, "{\n" );

	for ( u32 i = 0; i < typeInfo->numCols; i++ ) {
		const char componentStr = GEN_COMPONENT_NAMES_VECTOR[i];

		StringBuilder_Appendf( code, "\t__m128 d%c  = _mm_sub_ps( lhs_%c, rhs_%c );\n", componentStr, componentStr, componentStr );
	}
	StringBuilder_Append( code, "\n" );

	for ( u32 i = 0; i < typeInfo->numCols; i++ ) {
		const char componentStr = GEN_COMPONENT_NAMES_VECTOR[i];
		
		StringBuilder_Appendf( code, "\t       d%c  = _mm_mul_ps( d%c, d%c );\n", componentStr, componentStr, componentStr );
	}
	StringBuilder_Append( code, "\n" );

	switch ( typeInfo->numCols ) {
		case 2:
			StringBuilder_Append(  code, "\treturn _mm_add_ps( dx,  dy );\n" );
			break;

		case 3:
			StringBuilder_Appendf( code, "\t__m128 add = _mm_add_ps( dx,  dy );\n" );
			StringBuilder_Appendf( code, "\t       add = _mm_add_ps( add, dz );\n" );
			StringBuilder_Append(  code, "\treturn add;\n" );
			break;

		case 4:
			StringBuilder_Appendf( code, "\t__m128 add = _mm_add_ps( dx,  dy );\n" );
			StringBuilder_Appendf( code, "\t       add = _mm_add_ps( add, dz );\n" );
			StringBuilder_Appendf( code, "\t       add = _mm_add_ps( add, dw );\n" );
			StringBuilder_Append(  code, "\treturn add;\n" );
			break;
	}

	StringBuilder_Append(  code, "}\n\n" );
}

static void GenerateFunction_Distance_SSE( allocatorLinear_t* tempStorage, stringBuilder_t* code, const typeInfo_t* typeInfo, const generatorStrings_t* strings, const generatorFlags_t flags ) {
	assert( tempStorage );
	assert( code );
	assert( typeInfo );
	assert( typeInfo->fullTypeName );
	assert( strings );

	const char* funcName = Gen_GetFuncName_Vector_SSE( tempStorage, typeInfo, flags, GEN_FUNCTION_NAME_DISTANCE );

	const char* distancesqFuncStr = Gen_GetFuncName_Vector_SSE( tempStorage, typeInfo, flags, GEN_FUNCTION_NAME_DISTANCESQ );
	
	StringBuilder_Appendf( code, "inline static __m128 %s( ", funcName );
	MakeSSEParmList( code, typeInfo->numCols, strings, SIMD_PARM_LIST_FLAG_LHS | SIMD_PARM_LIST_FLAG_RHS );
	StringBuilder_Append(  code, " )\n" );
	StringBuilder_Append(  code, "{\n\t" );
	u64 lineStart = code->length;
	StringBuilder_Appendf( code, "return _mm_sqrt_ps( %s( ", distancesqFuncStr );
	u64 lineEnd = code->length;
	u64 lineLength = lineEnd - lineStart;
	for ( u32 i = 0; i < typeInfo->numCols; i++ ) {
		StringBuilder_Appendf( code, "lhs_%c, ", GEN_COMPONENT_NAMES_VECTOR[i] );
	}
	StringBuilder_Append(  code, "\n\t" );
	for ( u32 i = 0; i < lineLength; i++ ) {
		StringBuilder_Append(  code, " " );
	}
	for ( u32 i = 0; i < typeInfo->numCols; i++ ) {
		StringBuilder_Appendf( code, "rhs_%c", GEN_COMPONENT_NAMES_VECTOR[i] );
		
		if ( i < typeInfo->numCols - 1 ) {
			StringBuilder_Append( code, ", " );
		}
	}
	StringBuilder_Append(  code, " ) );\n" );
	StringBuilder_Append(  code, "}\n\n" );
}

static void GenerateVectorFiles_SSE( allocatorLinear_t* tempStorage, const char* generatedCodePath, const typeInfo_t* typeInfos, const u32 typeInfosCount, const generatorStrings_t* strings, const generatorFlags_t flags ) {
	assert( tempStorage );
	assert( generatedCodePath );
	assert( typeInfos );
	assert( typeInfosCount );
	assert( flags );

	bool32 cLinkage = flags & GENERATOR_FLAG_C_LINKAGE;

	stringBuilder_t* code = StringBuilder_Create( tempStorage, 12 * KB_TO_BYTES );

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

	StringBuilder_Append( code, "#include \"" GEN_HEADER_CONSTANTS_SSE "\"\n" );

	if ( cLinkage ) {
		StringBuilder_Append( code,
			"#ifndef __cplusplus\n"
			"#include <stdbool.h>\n"
			"#endif\n"
			"\n"
		);
	}

	for ( u32 i = 0; i < typeInfosCount; i++ ) {
		const typeInfo_t* typeInfo = &typeInfos[i];

		if ( typeInfo->type != GEN_TYPE_FLOAT ) {
			continue;
		}

		printf( "SSE Scalar functions %s...", typeInfo->fullTypeName );

		StringBuilder_Appendf( code, "// %s\n", typeInfo->fullTypeName );

		GenerateFunction_Dot_SSE( tempStorage, code, typeInfo, strings, flags );
		GenerateFunction_Cross_SSE( tempStorage, code, typeInfo, strings, flags );
		GenerateFunction_Lengthsq_SSE( tempStorage, code, typeInfo, strings, flags );
		GenerateFunction_Length_SSE( tempStorage, code, typeInfo, strings, flags );
		GenerateFunction_Normalize_SSE( tempStorage, code, typeInfo, strings, flags );
		GenerateFunction_Distancesq_SSE( tempStorage, code, typeInfo, strings, flags );
		GenerateFunction_Distance_SSE( tempStorage, code, typeInfo, strings, flags );

		StringBuilder_Append( code, "\n" );

		printf( "OK.\n" );
	}

	if ( cLinkage ) {
		StringBuilder_Append( code,
			"#ifdef __cplusplus\n"
			"}\n"
			"#endif\n"
		);
	}

	const char* fileNameHeader = String_TPrintf( tempStorage, "%s/%s.h", generatedCodePath, GEN_FILENAME_FUNCTIONS_VECTOR_SSE );

	FS_WriteEntireFile( fileNameHeader, code->str, code->length );

	Mem_Reset( tempStorage );
}
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
#include "gen_common_sse.h"

#include "string_builder.h"

void Gen_SSE_MacroNegate( const genType_t type, stringBuilder_t* sbHeader ) {
	if ( !Gen_TypeSupportsSSE( type ) ) {
		return;
	}

	const char* macroName = Gen_SSE_GetMacroNameNegate( type );

	char subFuncStr[GEN_STRING_LENGTH_SSE_INTRINSIC];
	Gen_SSE_GetIntrinsicArithmetic( type, GEN_OP_ARITHMETIC_SUB, subFuncStr );

	String_Append(  sbHeader, "/// \\brief Changes the sign of the values in the register.\n" );
	String_Appendf( sbHeader, "#define %s( reg ) %s( HLML_ZERO_SSE, (reg) )\n", macroName, subFuncStr );
	String_Append(  sbHeader, "\n" );
}

void Gen_SSE_Radians( const genLanguage_t language, const genType_t type, stringBuilder_t* sbHeader ) {
	if ( !Gen_TypeSupportsSSE( type ) ) {
		return;
	}

	const char* registerName	= Gen_SSE_GetRegisterName( type );

	char mulFuncStr[GEN_STRING_LENGTH_SSE_INTRINSIC];
	Gen_SSE_GetIntrinsicArithmetic( type, GEN_OP_ARITHMETIC_MUL, mulFuncStr );

	char radiansFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_SSE_GetFuncNameRadians( language, type, radiansFuncStr );

	String_Appendf( sbHeader, "inline static void %s( const %s deg, %s* out_radians )\n", radiansFuncStr, registerName, registerName );
	String_Append(  sbHeader, "{\n" );
	String_Append(  sbHeader, "\tassert( out_radians );\n" );
	String_Append(  sbHeader, "\n" );
	String_Appendf( sbHeader, "\t*out_radians = %s( deg, HLML_DEG_TO_RAD_SSE );\n", mulFuncStr );
	String_Append(  sbHeader, "}\n" );
	String_Append(  sbHeader, "\n" );
}

void Gen_SSE_Degrees( const genLanguage_t language, const genType_t type, stringBuilder_t* sbHeader ) {
	if ( !Gen_TypeSupportsSSE( type ) ) {
		return;
	}

	const char* registerName = Gen_SSE_GetRegisterName( type );

	char mulFuncStr[GEN_STRING_LENGTH_SSE_INTRINSIC];
	Gen_SSE_GetIntrinsicArithmetic( type, GEN_OP_ARITHMETIC_MUL, mulFuncStr );

	char degreesFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_SSE_GetFuncNameDegrees( language, type, degreesFuncStr );

	String_Appendf( sbHeader, "inline static void %s( const %s rad, %s* out_degrees )\n", degreesFuncStr, registerName, registerName );
	String_Append(  sbHeader, "{\n" );
	String_Append(  sbHeader, "\tassert( out_degrees );\n" );
	String_Append(  sbHeader, "\n" );
	String_Appendf( sbHeader, "\t*out_degrees = %s( rad, HLML_RAD_TO_DEG_SSE );\n", mulFuncStr );
	String_Append(  sbHeader, "}\n" );
	String_Append(  sbHeader, "\n" );
}

void Gen_SSE_Lerp( const genLanguage_t language, const genType_t type, const u32 numComponents, stringBuilder_t* sbHeader ) {
	assert( numComponents >= 1 );	// 1 for non-vector types
	assert( numComponents <= GEN_COMPONENT_COUNT_MAX );

	if ( !Gen_TypeSupportsSSE( type ) ) {
		return;
	}

	char lerpFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_SSE_GetFuncNameLerp( language, type, numComponents, lerpFuncStr );

	if ( numComponents == 1 ) {
		const char* registerName = Gen_SSE_GetRegisterName( type );

		char addFuncStr[GEN_STRING_LENGTH_SSE_INTRINSIC];
		Gen_SSE_GetIntrinsicArithmetic( type, GEN_OP_ARITHMETIC_ADD, addFuncStr );

		char subFuncStr[GEN_STRING_LENGTH_SSE_INTRINSIC];
		Gen_SSE_GetIntrinsicArithmetic( type, GEN_OP_ARITHMETIC_SUB, subFuncStr );

		char mulFuncStr[GEN_STRING_LENGTH_SSE_INTRINSIC];
		Gen_SSE_GetIntrinsicArithmetic( type, GEN_OP_ARITHMETIC_MUL, mulFuncStr );

		String_Appendf( sbHeader, "inline static void %s( const %s lhs, const %s rhs, const %s t, %s* out_results )\n", lerpFuncStr, registerName, registerName, registerName, registerName );
		String_Append(  sbHeader, "{\n" );
		String_Append(  sbHeader, "\tassert( out_results );\n" );
		String_Append(  sbHeader, "\n" );
		String_Appendf( sbHeader, "\t%s sub0 = %s( HLML_ONE_SSE, t );\n", registerName, subFuncStr );
		String_Append(  sbHeader, "\n" );
		String_Appendf( sbHeader, "\t%s mul0 = %s( sub0, lhs );\n", registerName, mulFuncStr );
		String_Appendf( sbHeader, "\t%s mul1 = %s( t, rhs );\n", registerName, mulFuncStr );
		String_Append(  sbHeader, "\n" );
		String_Appendf( sbHeader, "\t*out_results = %s( mul0, mul1 );\n", addFuncStr );
		String_Append(  sbHeader, "}\n" );
		String_Append(  sbHeader, "\n" );
	} else {
		char sseTypeName[GEN_STRING_LENGTH_SSE_INPUT_NAME];
		Gen_SSE_GetFullTypeName( type, 1, numComponents, sseTypeName );

		String_Appendf( sbHeader, "inline static void %s( const %s* lhs, const %s* rhs, const %s* t, %s* out_results )\n", lerpFuncStr, sseTypeName, sseTypeName, sseTypeName, sseTypeName );
		String_Append(  sbHeader, "{\n" );
		String_Appendf( sbHeader, "\tassert( lhs );\n" );
		String_Appendf( sbHeader, "\tassert( rhs );\n" );
		String_Appendf( sbHeader, "\tassert( t );\n" );
		String_Appendf( sbHeader, "\tassert( out_results );\n" );
		String_Append(  sbHeader, "\n" );
		for ( u32 i = 0; i < numComponents; i++ ) {
			char componentStr = GEN_COMPONENT_NAMES_VECTOR[i];

			String_Appendf( sbHeader, "\tlerp_sse( lhs->%c, rhs->%c, t->%c, out_results->%c );\n", componentStr, componentStr, componentStr, componentStr );
		}
		String_Append(  sbHeader, "}\n" );
		String_Append(  sbHeader, "\n" );
	}
}

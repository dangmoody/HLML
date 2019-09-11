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

void Gen_SSE_Radians( const genType_t type, stringBuilder_t* sbHeader, stringBuilder_t* sbInl ) {
	if ( !Gen_TypeSupportsSSE( type ) ) {
		return;
	}

//	const char* memberTypeString = Gen_GetMemberTypeString( type );

	const char* registerName	= Gen_SSE_GetRegisterName( type );

	char mulFuncStr[GEN_STRING_LENGTH_SSE_INTRINSIC];
	Gen_SSE_GetIntrinsicArithmetic( type, GEN_OP_ARITHMETIC_MUL, mulFuncStr );

	String_Appendf( sbHeader, "inline void radians_sse( const %s deg, %s* out_radians );\n", registerName, registerName );
	String_Append(  sbHeader, "\n" );

	String_Appendf( sbInl, "void radians_sse( const %s deg, %s* out_radians )\n", registerName, registerName );
	String_Append(  sbInl, "{\n" );
	String_Append(  sbInl, "\tassert( out_radians );\n" );
	String_Append(  sbInl, "\n" );
	String_Appendf( sbInl, "\t*out_radians = %s( deg, HLML_DEG_TO_RAD_SSE );\n", mulFuncStr );
	String_Append(  sbInl, "}\n" );
	String_Append(  sbInl, "\n" );
}

void Gen_SSE_Degrees( const genType_t type, stringBuilder_t* sbHeader, stringBuilder_t* sbInl ) {
	if ( !Gen_TypeSupportsSSE( type ) ) {
		return;
	}

//	const char* memberTypeString = Gen_GetMemberTypeString( type );

	const char* registerName = Gen_SSE_GetRegisterName( type );

	char mulFuncStr[GEN_STRING_LENGTH_SSE_INTRINSIC];
	Gen_SSE_GetIntrinsicArithmetic( type, GEN_OP_ARITHMETIC_MUL, mulFuncStr );

	String_Appendf( sbHeader, "inline void degrees_sse( const %s rad, %s* out_degrees );\n", registerName, registerName );
	String_Append(  sbHeader, "\n" );

	String_Appendf( sbInl, "void degrees_sse( const %s rad, %s* out_degrees )\n", registerName, registerName );
	String_Append(  sbInl, "{\n" );
	String_Append(  sbInl, "\tassert( out_degrees );\n" );
	String_Append(  sbInl, "\n" );
	String_Appendf( sbInl, "\t*out_degrees = %s( rad, HLML_RAD_TO_DEG_SSE );\n", mulFuncStr );
	String_Append(  sbInl, "}\n" );
	String_Append(  sbInl, "\n" );
}

void Gen_SSE_Lerp( const genType_t type, const u32 numComponents, stringBuilder_t* sbHeader, stringBuilder_t* sbInl ) {
	assert( numComponents >= 1 );	// 1 for non-vector types
	assert( numComponents <= GEN_COMPONENT_COUNT_MAX );

	if ( !Gen_TypeSupportsSSE( type ) ) {
		return;
	}

	char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetFullTypeName( type, 1, numComponents, fullTypeName );

	char oneStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	Gen_GetNumericLiteral( type, 1.0f, oneStr, 1 );

	const char* registerName	= Gen_SSE_GetRegisterName( type );
	const char* set1FuncStr		= Gen_SSE_GetIntrinsicSet1( type );

	char addFuncStr[GEN_STRING_LENGTH_SSE_INTRINSIC];
	char subFuncStr[GEN_STRING_LENGTH_SSE_INTRINSIC];
	char mulFuncStr[GEN_STRING_LENGTH_SSE_INTRINSIC];

	Gen_SSE_GetIntrinsicArithmetic( type, GEN_OP_ARITHMETIC_ADD, addFuncStr );
	Gen_SSE_GetIntrinsicArithmetic( type, GEN_OP_ARITHMETIC_SUB, subFuncStr );
	Gen_SSE_GetIntrinsicArithmetic( type, GEN_OP_ARITHMETIC_MUL, mulFuncStr );

	char sseTypeName[GEN_STRING_LENGTH_SSE_INPUT_NAME];
	Gen_SSE_GetFullTypeName( fullTypeName, sseTypeName );

	String_Appendf( sbHeader, "struct %s\n", sseTypeName );
	String_Append(  sbHeader, "{\n" );
	String_Appendf( sbHeader, "\t%s lhs;\n", registerName );
	String_Appendf( sbHeader, "\t%s rhs;\n", registerName );
	String_Appendf( sbHeader, "\t%s t;\n", registerName );
	String_Append(  sbHeader, "};\n" );
	String_Append(  sbHeader, "\n" );

	String_Appendf( sbHeader, "inline void lerp_sse( const %s* in, %s* out_results );\n", sseTypeName, registerName );
	String_Append(  sbHeader, "\n" );

	String_Appendf( sbInl, "void lerp_sse( const %s* in, %s* out_results )\n", sseTypeName, registerName );
	String_Append(  sbInl, "{\n" );
	String_Append(  sbInl, "\tassert( in );\n" );
	String_Append(  sbInl, "\tassert( out_results );\n" );
	String_Append(  sbInl, "\n" );
	String_Appendf( sbInl, "\t%s one = %s( %s );\n", registerName, set1FuncStr, oneStr );
	String_Append(  sbInl, "\n" );
	String_Appendf( sbInl, "\t%s sub0 = %s( one, in->t );\n", registerName, subFuncStr );
	String_Append(  sbInl, "\n" );
	String_Appendf( sbInl, "\t%s mul0 = %s( sub0, in->lhs );\n", registerName, mulFuncStr );
	String_Appendf( sbInl, "\t%s mul1 = %s( in->t, in->rhs );\n", registerName, mulFuncStr );
	String_Append(  sbInl, "\n" );
	String_Appendf( sbInl, "\t*out_results = %s( mul0, mul1 );\n", addFuncStr );
	String_Append(  sbInl, "}\n" );
	String_Append(  sbInl, "\n" );
}

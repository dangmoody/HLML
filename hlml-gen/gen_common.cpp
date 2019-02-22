#include "gen_common.h"

#ifdef _WIN32
#include <Windows.h>
#endif

#include <stdio.h>
#include <assert.h>

const std::string GEN_COPYRIGHT_HEADER = \
"/*\n" \
"===========================================================================\n" \
"\n" \
"hlml.\n" \
"Copyright (c) Dan Moody 2019 - Present.\n" \
"\n" \
"This file is part of hlml.\n" \
"\n" \
"hlml is free software: you can redistribute it and/or modify\n" \
"it under the terms of the GNU General Public License as published by\n" \
"the Free Software Foundation, either version 3 of the License, or\n" \
"(at your option) any later version.\n" \
"\n" \
"hlml is distributed in the hope that it will be useful,\n" \
"but WITHOUT ANY WARRANTY; without even the implied warranty of\n" \
"MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n" \
"GNU General Public License for more details.\n" \
"\n" \
"You should have received a copy of the GNU General Public License\n" \
"along with hlml.  If not, see <http://www.gnu.org/licenses/>.\n" \
"\n" \
"===========================================================================\n" \
"*/\n";

const std::string GEN_GENERATED_WARNING = "// GENERATED FILE.  DO NOT EDIT.\n";

const std::string GEN_COMPONENT_NAMES_VECTOR = "xyzw";
const std::string GEN_COMPONENT_NAMES_COLOR = "rgba";
const std::string GEN_OPERATORS_ARITHMETIC[4] = {
	"+",
	"-",
	"*",
	"/",
};

const std::string GEN_OPERATORS_EQUALITY[4] = {
	"<",
	"<=",
	">",
	">=",
};

void Gen_VectorLength( const genType_t type, const uint32_t numComponents, std::string& outHeader, std::string& outInl ) {
	assert( numComponents >= GEN_COMPONENT_COUNT_MIN );
	assert( numComponents <= GEN_COMPONENT_COUNT_MAX );

	if ( type == GEN_TYPE_BOOL ) {
		return;
	}

	genType_t floatingPointType = Gen_GetSupportedFloatingPointType( type );

	std::string typeString = Gen_GetTypeString( type );
	std::string returnTypeString = Gen_GetTypeString( floatingPointType );
	std::string fullTypeName = typeString + std::to_string( numComponents );

	std::string sqrtString = ( floatingPointType == GEN_TYPE_DOUBLE ) ? "sqrt" : "sqrtf";

	outHeader += "inline " + returnTypeString + " lengthsqr( const " + fullTypeName + "& vec );\n";
	outHeader += "inline " + returnTypeString + " length( const " + fullTypeName + "& vec );\n";

	outHeader += "\n";

	outInl += returnTypeString + " lengthsqr( const " + fullTypeName + "& vec ) {\n";
	outInl += "\treturn ";
	for ( uint32_t i = 0; i < numComponents; i++ ) {
		char componentName = GEN_COMPONENT_NAMES_VECTOR[i];
		outInl += std::string( "( vec." ) + componentName + " * vec." + componentName + " )";

		if ( i != numComponents - 1 ) {
			outInl += " + ";
		}
	}
	outInl += ";\n";
	outInl += "}\n";

	outInl += "\n";

	// TODO(DM): do sqrtf for float, sqrt for double
	outInl += returnTypeString + " length( const " + fullTypeName + "& vec ) {\n";
	outInl += "\treturn " + sqrtString + "( lengthsqr( vec ) );\n";
	outInl += "}\n";

	outInl += "\n";
}

void Gen_VectorNormalize( const genType_t type, const uint32_t numComponents, std::string& outHeader, std::string& outInl ) {
	assert( numComponents >= GEN_COMPONENT_COUNT_MIN );
	assert( numComponents <= GEN_COMPONENT_COUNT_MAX );

	if ( type != GEN_TYPE_FLOAT && type != GEN_TYPE_DOUBLE ) {
		return;
	}

	std::string typeString = Gen_GetTypeString( type );
	std::string fullTypeName = typeString + std::to_string( numComponents );

	std::string oneStr = Gen_GetNumericLiteral( type, 1 );

	outHeader += "inline void normalize( " + fullTypeName + "& vec );\n";
	outHeader += "inline " + fullTypeName + " normalized( const " + fullTypeName + "& vec );\n";

	outHeader += "\n";

	outInl += "void normalize( " + fullTypeName + "& vec ) {\n";
	outInl += "\t" + typeString + " invlen = " + oneStr + " / length( vec );\n";
	outInl += "\tvec *= invlen;\n";
	outInl += "}\n";

	outInl += "\n";

	outInl += fullTypeName + " normalized( const " + fullTypeName + "& vec ) {\n";
	outInl += "\t" + typeString + " invlen = " + oneStr + " / length( vec );\n";
	outInl += "\treturn (" + fullTypeName + ") vec * invlen;\n";
	outInl += "}\n";

	outInl += "\n";
}

void Gen_VectorDot( const genType_t type, const uint32_t numComponents, std::string& outHeader, std::string& outInl ) {
	assert( numComponents >= GEN_COMPONENT_COUNT_MIN );
	assert( numComponents <= GEN_COMPONENT_COUNT_MAX );

	if ( type == GEN_TYPE_BOOL || type == GEN_TYPE_UINT ) {
		return;
	}

	std::string typeString = Gen_GetTypeString( type );
	std::string returnTypeString = Gen_GetTypeString( Gen_GetSupportedFloatingPointType( type ) );
	std::string fullTypeName = typeString + std::to_string( numComponents );

	outHeader += "inline " + returnTypeString + " dot( const " + fullTypeName + "& lhs, const " + fullTypeName + "& rhs );\n";

	outHeader += "\n";

	outInl += returnTypeString + " dot( const " + fullTypeName + "& lhs, const " + fullTypeName + "& rhs ) {\n";
	outInl += "\treturn ";
	for ( uint32_t i = 0; i < numComponents; i++ ) {
		outInl += "( " + std::string( "lhs." ) + GEN_COMPONENT_NAMES_VECTOR[i] + std::string( " * " ) + std::string( "rhs." ) + GEN_COMPONENT_NAMES_VECTOR[i] + " )";

		if ( i != numComponents - 1 ) {
			outInl += " + ";
		}
	}
	outInl += ";\n";
	outInl += "}\n";

	outInl += "\n";
}

void Gen_VectorCross( const genType_t type, const uint32_t numComponents, std::string& outHeader, std::string& outInl ) {
	assert( numComponents >= GEN_COMPONENT_COUNT_MIN );
	assert( numComponents <= GEN_COMPONENT_COUNT_MAX );

	if ( type != GEN_TYPE_FLOAT && type != GEN_TYPE_DOUBLE ) {
		return;
	}

	if ( numComponents < 3 ) {
		return;
	}

	std::string typeString = Gen_GetTypeString( type );
	std::string fullTypeName = typeString + std::to_string( numComponents );

	outHeader += "inline " + fullTypeName + " cross( const " + fullTypeName + "& lhs, const " + fullTypeName + "& rhs );\n";

	outHeader += "\n";

	outInl += fullTypeName + " cross( const " + fullTypeName + "& lhs, const " + fullTypeName + "& rhs ) {\n";
	outInl += "\treturn " + fullTypeName + "(\n";
	outInl += "\t\t( lhs.y * rhs.z ) - ( lhs.z * rhs.y ),\n";
	outInl += "\t\t( lhs.z * rhs.x ) - ( lhs.x * rhs.z ),\n";
	outInl += "\t\t( lhs.x * rhs.y ) - ( lhs.y * rhs.x )";
	if ( numComponents > 3 ) {
		outInl += ",\n\t\t" + Gen_GetDefaultLiteralValue( type ) + "\n";
	} else {
		outInl += "\n";
	}
	outInl += "\t);\n";
	outInl += "}\n";

	outInl += "\n";
}

void Gen_VectorAngle( const genType_t type, const uint32_t numComponents, std::string& outHeader, std::string& outInl ) {
	assert( numComponents >= GEN_COMPONENT_COUNT_MIN );
	assert( numComponents <= GEN_COMPONENT_COUNT_MAX );

	if ( type != GEN_TYPE_FLOAT && type != GEN_TYPE_DOUBLE ) {
		return;
	}

	genType_t floatingPointType = Gen_GetSupportedFloatingPointType( type );

	std::string typeString = Gen_GetTypeString( type );
	std::string returnTypeString = Gen_GetTypeString( floatingPointType );
	std::string fullTypeName = typeString + std::to_string( numComponents );

	std::string acosString = ( floatingPointType == GEN_TYPE_DOUBLE ) ? "acos" : "acosf";

	outHeader += "inline " + returnTypeString + " angle( const " + fullTypeName + "& lhs, const " + fullTypeName + "& rhs );\n";

	outHeader += "\n";

	outInl += returnTypeString + " angle( const " + fullTypeName + "& lhs, const " + fullTypeName + "& rhs ) {\n";
	outInl += "\treturn degrees( " + acosString + "( dot( normalized( lhs ), normalized( rhs ) ) ) );\n";
	outInl += "}\n";

	outInl += "\n";
}

void Gen_MatrixIdentity( const genType_t type, const uint32_t numRows, const uint32_t numCols, std::string& outHeader, std::string& outInl ) {
	assert( numRows >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );

	std::string fullTypeName = Gen_GetTypeString( type ) + std::to_string( numRows ) + "x" + std::to_string( numCols );

	outHeader += "inline void identity( " + fullTypeName + "& mat );\n";

	outHeader += "\n";

	outInl += "void identity( " + fullTypeName + "& mat ) {\n";
	for ( uint32_t row = 0; row < numRows; row++ ) {
		outInl += "\tmat.rows[" + std::to_string( row ) + "] = { ";
		for ( uint32_t col = 0; col < numCols; col++ ) {
			outInl += ( row == col ) ? "1" : "0";

			if ( col != numCols - 1 ) {
				outInl += ", ";
			}
		}
		outInl += " };\n";
	}
	outInl += "}\n";

	outInl += "\n";
}

void Gen_MatrixTranspose( const genType_t type, const uint32_t numRows, const uint32_t numCols, std::string& outHeader, std::string& outInl ) {
	assert( numRows >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );

	if ( type == GEN_TYPE_BOOL ) {
		return;
	}

	std::string typeString = Gen_GetTypeString( type );
	std::string fullTypeName = typeString + std::to_string( numRows ) + "x" + std::to_string( numCols );
	std::string transposeTypeName = typeString + std::to_string( numCols ) + "x" + std::to_string( numRows );

	outHeader += "inline " + transposeTypeName + " transpose( const " + fullTypeName + "& mat );\n";

	outHeader += "\n";

	outInl += transposeTypeName + " transpose( const " + fullTypeName + "& mat ) {\n";
	outInl += "\treturn " + transposeTypeName + "(\n";

	for ( uint32_t col = 0; col < numCols; col++ ) {
		std::string colStr = std::to_string( col );

		outInl += "\t\t";

		for ( uint32_t row = 0; row < numRows; row++ ) {
			std::string rowStr = std::to_string( row );

			outInl += "mat.rows[" + rowStr + "][" + colStr + "]";

			if ( row + col != ( numRows - 1 ) + ( numCols - 1 ) ) {
				outInl += ",";
			}

			if ( row != numRows - 1 ) {
				outInl += " ";
			} else {
				outInl += "\n";
			}
		}
	}
	outInl += "\t);\n";
	outInl += "}\n";

	outInl += "\n";
}

void Gen_MatrixInverse( const genType_t type, const uint32_t numRows, const uint32_t numCols, std::string& outHeader, std::string& outInl ) {
	assert( numRows >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );

	if ( type == GEN_TYPE_BOOL ) {
		return;
	}

	if ( numRows != numCols ) {
		return;
	}

	std::string typeString = Gen_GetTypeString( type );
	std::string memberTypeString = Gen_GetMemberTypeString( type );
	std::string vectorTypeName = typeString + std::to_string( numCols );
	std::string fullTypeName = typeString + std::to_string( numRows ) + "x" + std::to_string( numCols );

	std::string literalOneStr = Gen_GetNumericLiteral( type, 1 );

	outHeader += "inline " + fullTypeName + " inverse( const " + fullTypeName + "& mat );\n";

	outHeader += "\n";

	outInl += fullTypeName + " inverse( const " + fullTypeName + "& mat ) {\n";
	switch ( numRows ) {
		case 2: {
			outInl += "\tconst " + memberTypeString + " invdet = " + literalOneStr + " / determinant( mat );\n";
			outInl += "\treturn " + fullTypeName + "(\n";
			outInl += "\t\t mat.rows[1][1] * invdet, -mat.rows[0][1] * invdet,\n";
			outInl += "\t\t-mat.rows[1][0] * invdet,  mat.rows[0][0] * invdet\n";
			outInl += "\t);\n";
			break;
		}

		case 3: {
			outInl += "\tconst " + memberTypeString + " invdet = " + literalOneStr + " / determinant( mat );\n";
			outInl += "\t// also transposed here\n";
			outInl += "\treturn " + fullTypeName + "(\n";
			outInl += "\t\t ( mat.rows[1][1] * mat.rows[2][2] - mat.rows[1][2] * mat.rows[2][1] ) * invdet,\n";
			outInl += "\t\t-( mat.rows[0][1] * mat.rows[2][2] - mat.rows[0][2] * mat.rows[2][1] ) * invdet,\n";
			outInl += "\t\t ( mat.rows[0][1] * mat.rows[1][2] - mat.rows[0][2] * mat.rows[1][1] ) * invdet,\n";
			outInl += "\n";
			outInl += "\t\t-( mat.rows[1][0] * mat.rows[2][2] - mat.rows[1][2] * mat.rows[2][0] ) * invdet,\n";
			outInl += "\t\t ( mat.rows[0][0] * mat.rows[2][2] - mat.rows[0][2] * mat.rows[2][0] ) * invdet,\n";
			outInl += "\t\t-( mat.rows[0][0] * mat.rows[1][2] - mat.rows[0][2] * mat.rows[1][0] ) * invdet,\n";
			outInl += "\n";
			outInl += "\t\t ( mat.rows[1][0] * mat.rows[2][1] - mat.rows[1][1] * mat.rows[2][0] ) * invdet,\n";
			outInl += "\t\t-( mat.rows[0][0] * mat.rows[2][1] - mat.rows[0][1] * mat.rows[2][0] ) * invdet,\n";
			outInl += "\t\t ( mat.rows[0][0] * mat.rows[1][1] - mat.rows[0][1] * mat.rows[1][0] ) * invdet\n";
			outInl += "\t);\n";
			break;
		}

		case 4: {
			outInl += "\t// uses the glm version, which is basically just an optimised version of the adjugate formula\n";
			outInl += "\t" + memberTypeString + " sub00 = mat.rows[2][2] * mat.rows[3][3] - mat.rows[3][2] * mat.rows[2][3];\n";
			outInl += "\t" + memberTypeString + " sub01 = mat.rows[1][2] * mat.rows[3][3] - mat.rows[1][3] * mat.rows[2][3];\n";
			outInl += "\t" + memberTypeString + " sub02 = mat.rows[1][2] * mat.rows[2][3] - mat.rows[1][3] * mat.rows[2][2];\n";
			outInl += "\n";
			outInl += "\t" + memberTypeString + " sub03 = mat.rows[2][1] * mat.rows[3][3] - mat.rows[2][3] * mat.rows[3][1];\n";
			outInl += "\t" + memberTypeString + " sub04 = mat.rows[1][1] * mat.rows[3][3] - mat.rows[1][3] * mat.rows[3][1];\n";
			outInl += "\t" + memberTypeString + " sub05 = mat.rows[1][1] * mat.rows[2][3] - mat.rows[1][3] * mat.rows[2][1];\n";
			outInl += "\n";
			outInl += "\t" + memberTypeString + " sub06 = mat.rows[2][1] * mat.rows[3][2] - mat.rows[2][2] * mat.rows[3][1];\n";
			outInl += "\t" + memberTypeString + " sub07 = mat.rows[1][1] * mat.rows[3][2] - mat.rows[1][2] * mat.rows[3][1];\n";
			outInl += "\t" + memberTypeString + " sub08 = mat.rows[1][1] * mat.rows[2][2] - mat.rows[1][2] * mat.rows[2][1];\n";
			outInl += "\n";
			outInl += "\t" + memberTypeString + " sub09 = mat.rows[2][0] * mat.rows[3][3] - mat.rows[3][0] * mat.rows[2][3];\n";
			outInl += "\t" + memberTypeString + " sub10 = mat.rows[1][0] * mat.rows[3][3] - mat.rows[3][0] * mat.rows[1][3];\n";
			outInl += "\t" + memberTypeString + " sub11 = mat.rows[1][0] * mat.rows[2][3] - mat.rows[2][0] * mat.rows[1][3];\n";
			outInl += "\n";
			outInl += "\t" + memberTypeString + " sub12 = mat.rows[2][0] * mat.rows[3][2] - mat.rows[2][2] * mat.rows[3][0];\n";
			outInl += "\t" + memberTypeString + " sub13 = mat.rows[1][0] * mat.rows[3][2] - mat.rows[1][2] * mat.rows[3][0];\n";
			outInl += "\t" + memberTypeString + " sub14 = mat.rows[1][0] * mat.rows[2][2] - mat.rows[1][2] * mat.rows[2][0];\n";
			outInl += "\n";
			outInl += "\t" + memberTypeString + " sub15 = mat.rows[2][0] * mat.rows[3][1] - mat.rows[2][1] * mat.rows[3][0];\n";
			outInl += "\t" + memberTypeString + " sub16 = mat.rows[1][0] * mat.rows[3][1] - mat.rows[1][1] * mat.rows[3][0];\n";
			outInl += "\t" + memberTypeString + " sub17 = mat.rows[1][0] * mat.rows[2][1] - mat.rows[1][1] * mat.rows[2][0];\n";
			outInl += "\n";
			outInl += "\t" + vectorTypeName + " fac0 = " + vectorTypeName + "( sub00, sub00, sub01, sub02 );\n";
			outInl += "\t" + vectorTypeName + " fac1 = " + vectorTypeName + "( sub03, sub03, sub04, sub05 );\n";
			outInl += "\t" + vectorTypeName + " fac2 = " + vectorTypeName + "( sub06, sub06, sub07, sub08 );\n";
			outInl += "\t" + vectorTypeName + " fac3 = " + vectorTypeName + "( sub09, sub09, sub10, sub11 );\n";
			outInl += "\t" + vectorTypeName + " fac4 = " + vectorTypeName + "( sub12, sub12, sub13, sub14 );\n";
			outInl += "\t" + vectorTypeName + " fac5 = " + vectorTypeName + "( sub15, sub15, sub16, sub17 );\n";
			outInl += "\n";
			outInl += "\t" + vectorTypeName + " vec0 = " + vectorTypeName + "( mat.rows[1][0], mat.rows[0][0], mat.rows[0][0], mat.rows[0][0] );\n";
			outInl += "\t" + vectorTypeName + " vec1 = " + vectorTypeName + "( mat.rows[1][1], mat.rows[0][1], mat.rows[0][1], mat.rows[0][1] );\n";
			outInl += "\t" + vectorTypeName + " vec2 = " + vectorTypeName + "( mat.rows[1][2], mat.rows[0][2], mat.rows[0][2], mat.rows[0][2] );\n";
			outInl += "\t" + vectorTypeName + " vec3 = " + vectorTypeName + "( mat.rows[1][3], mat.rows[0][3], mat.rows[0][3], mat.rows[0][3] );\n";
			outInl += "\n";
			outInl += "\t" + vectorTypeName + " inv0 = vec1 * fac0 - vec2 * fac1 + vec3 * fac2;\n";
			outInl += "\t" + vectorTypeName + " inv1 = vec0 * fac0 - vec2 * fac3 + vec3 * fac4;\n";
			outInl += "\t" + vectorTypeName + " inv2 = vec0 * fac1 - vec1 * fac3 + vec3 * fac5;\n";
			outInl += "\t" + vectorTypeName + " inv3 = vec0 * fac2 - vec1 * fac4 + vec2 * fac5;\n";
			outInl += "\n";
			outInl += "\t" + vectorTypeName + " sign0 = " + vectorTypeName + "(  1, -1,  1, -1 );\n";
			outInl += "\t" + vectorTypeName + " sign1 = " + vectorTypeName + "( -1,  1, -1,  1 );\n";
			outInl += "\n";
			outInl += "\t" + fullTypeName + " result = " + fullTypeName + "(\n";
			outInl += "\t\tinv0 * sign0,\n";
			outInl += "\t\tinv1 * sign1,\n";
			outInl += "\t\tinv2 * sign0,\n";
			outInl += "\t\tinv3 * sign1\n";
			outInl += "\t);\n";
			outInl += "\n";
			outInl += "\t" + vectorTypeName + " col0 = " + vectorTypeName + "( result.rows[0][0], result.rows[1][0], result.rows[2][0], result.rows[3][0] );\n";
			outInl += "\t" + vectorTypeName + " dot0 = mat.rows[0] * col0;\n";
			outInl += "\n";
			outInl += "\tconst " + memberTypeString + " dot1 = ( dot0.x + dot0.y ) + ( dot0.z + dot0.w );\n";
			outInl += "\n";
			outInl += "\tconst " + memberTypeString + " invdet = " + literalOneStr + " / dot1;\n";
			outInl += "\n";
			outInl += "\treturn result * invdet;\n";
			break;
		}
	}
	outInl += "}\n";

	outInl += "\n";
}

void Gen_MatrixDeterminant( const genType_t type, const uint32_t numRows, const uint32_t numCols, std::string& outHeader, std::string& outInl ) {
	assert( numRows >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );

	if ( type == GEN_TYPE_BOOL ) {
		return;
	}

	if ( numRows != numCols ) {
		return;
	}

	std::string typeString = Gen_GetTypeString( type );
	std::string memberTypeString = Gen_GetMemberTypeString( type );
	std::string vectorTypeName = typeString + std::to_string( numCols );
	std::string fullTypeName = typeString + std::to_string( numRows ) + "x" + std::to_string( numCols );

	outHeader += "inline " + memberTypeString + " determinant( const " + fullTypeName + "& mat );\n";

	outHeader += "\n";

	outInl += memberTypeString + " determinant( const " + fullTypeName + "& mat ) {\n";
	switch ( numRows ) {
		case 2: {
			outInl += "\treturn mat.rows[0][0] * mat.rows[1][1] - mat.rows[1][0] * mat.rows[0][1];\n";
			break;
		}

		case 3: {
			outInl += "\treturn\n";
			outInl += "\t\tmat.rows[0][0] * ( mat.rows[1][1] * mat.rows[2][2] - mat.rows[2][1] * mat.rows[1][2] )\n";
			outInl += "\t\t- mat.rows[0][1] * ( mat.rows[1][0] * mat.rows[2][2] - mat.rows[2][0] * mat.rows[1][2] )\n";
			outInl += "\t\t+ mat.rows[0][2] * ( mat.rows[1][0] * mat.rows[2][1] - mat.rows[2][0] * mat.rows[1][1] );\n";
			break;
		}

		case 4: {
			outInl += "\t// using glm's method where you basically take determinants from each sub matrix and cache the repeat occurences\n";
			outInl += "\t" + memberTypeString + " sub00 = mat.rows[2][2] * mat.rows[3][3] - mat.rows[3][2] * mat.rows[2][3];\n";
			outInl += "\t" + memberTypeString + " sub01 = mat.rows[2][1] * mat.rows[3][3] - mat.rows[2][3] * mat.rows[3][1];\n";
			outInl += "\t" + memberTypeString + " sub02 = mat.rows[2][1] * mat.rows[3][2] - mat.rows[3][1] * mat.rows[2][2];\n";
			outInl += "\t" + memberTypeString + " sub03 = mat.rows[2][0] * mat.rows[3][3] - mat.rows[3][0] * mat.rows[2][3];\n";
			outInl += "\t" + memberTypeString + " sub04 = mat.rows[2][0] * mat.rows[3][2] - mat.rows[3][0] * mat.rows[2][2];\n";
			outInl += "\t" + memberTypeString + " sub05 = mat.rows[2][0] * mat.rows[3][1] - mat.rows[3][0] * mat.rows[2][1];\n";
			outInl += "\n";
			outInl += "\t" + vectorTypeName + " cofactor = " + vectorTypeName + "(\n";
			outInl += "\t\t ( mat.rows[1][1] * sub00 - mat.rows[1][2] * sub01 + mat.rows[1][3] * sub02 ),\n";
			outInl += "\t\t-( mat.rows[1][0] * sub00 - mat.rows[1][2] * sub03 + mat.rows[1][3] * sub04 ),\n";
			outInl += "\t\t ( mat.rows[1][0] * sub01 - mat.rows[1][1] * sub03 + mat.rows[1][3] * sub05 ),\n";
			outInl += "\t\t-( mat.rows[1][0] * sub02 - mat.rows[1][1] * sub04 + mat.rows[1][2] * sub05 )\n";
			outInl += "\t);\n";
			outInl += "\n";
			outInl += "\treturn\n";
			outInl += "\t\tmat.rows[0][0] * cofactor.x + mat.rows[0][1] * cofactor.y +\n";
			outInl += "\t\tmat.rows[0][2] * cofactor.z + mat.rows[0][3] * cofactor.w;\n";
			break;
		}
	}
	outInl += "}\n";

	outInl += "\n";
}

void Gen_MatrixTranslate( const genType_t type, const uint32_t numRows, const uint32_t numCols, std::string& outHeader, std::string& outInl ) {
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );

	if ( type == GEN_TYPE_BOOL ) {
		return;
	}

	if ( numRows < 3 || numCols < 3 ) {
		return;
	}

	std::string typeString = Gen_GetTypeString( type );
	std::string fullTypeName = typeString + std::to_string( numRows ) + "x" + std::to_string( numCols );

	outHeader += "inline " + fullTypeName + " translate( const " + fullTypeName + "& mat, const " + typeString + std::to_string( numRows - 1 ) + "& vec );\n";

	outHeader += "\n";

	outInl += fullTypeName + " translate( const " + fullTypeName + "& mat, const " + typeString + std::to_string( numRows - 1 ) + "& vec ) {\n";
	outInl += "\treturn " + fullTypeName + "(\n";
	outInl += "\t\t";
	for ( uint32_t row = 0; row < numRows; row++ ) {
		for ( uint32_t col = 0; col < numCols; col++ ) {
			outInl += "mat[" + std::to_string( row ) + "][" + std::to_string( col ) + "]";

			if ( col != numCols - 1 ) {
				outInl += ", ";
			} else {
				if ( row != numRows - 1 ) {
					outInl += std::string( " + vec." ) + GEN_COMPONENT_NAMES_VECTOR[row] + ",";
				}
			}
		}
		outInl += "\n";

		if ( row != numRows - 1 ) {
			outInl += "\t\t";
		}
	}
	outInl += "\t);\n";
	outInl += "}\n";

	outInl += "\n";
}

void Gen_MatrixRotate( const genType_t type, const uint32_t numRows, const uint32_t numCols, std::string& outHeader, std::string& outInl ) {
	assert( numRows >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );

	if ( type != GEN_TYPE_FLOAT || type != GEN_TYPE_DOUBLE ) {
		return;
	}

	std::string typeString = Gen_GetTypeString( type );
	std::string vectorTypeString = Gen_GetTypeString( type ) + std::to_string( numRows );
	std::string fullTypeName = typeString + std::to_string( numRows ) + "x" + std::to_string( numCols );

	std::string literalOneStr = Gen_GetNumericLiteral( type, 1 );

	outHeader += "inline " + fullTypeName + " rotate( const " + fullTypeName + "& mat, const " + typeString + " radians, const " + vectorTypeString + "& axis );\n";

	outHeader += "\n";

	outInl += fullTypeName + " rotate( const " + fullTypeName + "& mat, const " + typeString + " radians, const " + vectorTypeString + "& axis ) {\n";
	outInl += "\tconst " + typeString + " c = static_cast<" + typeString + ">( cos( radians ) );\n";
	outInl += "\tconst " + typeString + " s = static_cast<" + typeString + ">( sin( radians ) );\n";
	outInl += "\n";

	switch ( numRows ) {
		case 2: {
			outInl += "\treturn " + fullTypeName + "(\n";
			outInl += "\t\tmat.rows[0] * c + mat.rows[1] * -s,\n";
			outInl += "\t\tmat.rows[0] * s + mat.rows[1] * c,\n";
			outInl += "\t);\n";
			break;
		}

		case 3: {
			outInl += "\treturn " + fullTypeName + "(\n";
			outInl += "\t\tmat.rows[0] * c + mat.rows[1] * -s,\n";
			outInl += "\t\tmat.rows[0] * s + mat.rows[1] * c,\n";
			outInl += "\t\tmat.rows[2]\n";
			outInl += "\t);\n";
			break;
		}

		case 4: {
			outInl += "\t" + vectorTypeString + " u = normalized( axis );\n";
			outInl += "\t" + typeString + " ic = " + literalOneStr + " - c;\n";
			outInl += "\n";
			outInl += "\t" + fullTypeName + " rotation = mat;\n";
			outInl += "\trotation[0][0] = c + u.x * ic;\n";
			outInl += "\trotation[0][1] = u.x * u.y * ic - u.z * s;\n";
			outInl += "\trotation[0][2] = u.x * u.z * ic + u.y * s;\n";
			outInl += "\n";
			outInl += "\trotation[1][0] = u.y * u.x * ic + u.z * s;\n";
			outInl += "\trotation[1][1] = c + u.y * ic;\n";
			outInl += "\trotation[1][2] = u.y * u.z * ic - u.x * s;\n";
			outInl += "\n";
			outInl += "\trotation[2][0] = u.z * u.x * ic - u.y * s;\n";
			outInl += "\trotation[2][1] = u.z * u.y * ic + u.x * s;\n";
			outInl += "\trotation[2][2] = c + u.z * ic;\n";
			outInl += "\n";
			outInl += "\treturn mat * rotation;\n";
			break;
		}
	}
	outInl += "}\n";

	outInl += "\n";
}

void Gen_MatrixScale( const genType_t type, const uint32_t numRows, const uint32_t numCols, std::string& outHeader, std::string& outInl ) {
	assert( numRows >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );

	if ( type == GEN_TYPE_BOOL ) {
		return;
	}

	std::string typeString = Gen_GetTypeString( type );
	std::string memberTypeString = Gen_GetMemberTypeString( type );
	std::string fullTypeName = typeString + std::to_string( numRows ) + "x" + std::to_string( numCols );

	// TODO(DM): is this the best way to handle this?
	uint32_t scaleCols = 0;
	switch ( numCols ) {
		case 2: scaleCols = 2; break;
		case 3: scaleCols = 3; break;
		case 4: scaleCols = 3; break;
	}

	std::string scaleVectorString = typeString + std::to_string( scaleCols );

	outHeader += "inline " + fullTypeName + " scale( const " + fullTypeName + "& mat, const " + memberTypeString + " scalar );\n";
	outHeader += "inline " + fullTypeName + " scale( const " + fullTypeName + "& mat, const " + scaleVectorString + "& vec );\n";

	outHeader += "\n";

	outInl += fullTypeName + " scale( const " + fullTypeName + "& mat, const " + memberTypeString + " scalar ) {\n";
	outInl += "\treturn scale( mat, " + scaleVectorString + "( ";
	for ( uint32_t col = 0; col < scaleCols; col++ ) {
		outInl += "scalar";

		if ( col != scaleCols - 1 ) {
			outInl += ", ";
		}
	}
	outInl += " ) );\n";
	outInl += "}\n";

	outInl += "\n";

	outInl += fullTypeName + " scale( const " + fullTypeName + "& mat, const " + scaleVectorString + "& vec ) {\n";
	outInl += "\treturn " + fullTypeName + "(\n";

	for ( uint32_t row = 0; row < numRows; row++ ) {
		std::string rowStr = std::to_string( row );

		for ( uint32_t col = 0; col < numCols; col++ ) {
			std::string colStr = std::to_string( col );

			outInl += "\t\tmat.rows[" + rowStr + "][" + colStr + "]";

			if ( row == col && col < scaleCols ) {
				outInl += std::string( " * vec." ) + GEN_COMPONENT_NAMES_VECTOR[row];
			}

			if ( row + col != ( numRows - 1 ) + ( numCols - 1 ) ) {
				outInl += ",\n";
			} else {
				outInl += "\n";
			}
		}

		if ( row != numRows - 1 ) {
			outInl += "\n";
		}
	}
	outInl += "\t);\n";
	outInl += "}\n";

	outInl += "\n";
}

void Gen_MatrixOrtho( const hand_t hand, const genType_t type, const uint32_t numRows, const uint32_t numCols, std::string& outHeader, std::string& outInl ) {
	assert( numRows >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );

	if ( type != GEN_TYPE_FLOAT && type != GEN_TYPE_DOUBLE ) {
		return;
	}

	if ( numRows < 4 || numCols < 4 ) {
		return;
	}

	std::string typeString = Gen_GetTypeString( type );
	std::string fullTypeName = typeString + std::to_string( numRows ) + "x" + std::to_string( numCols );

	std::string zeroStr = Gen_GetNumericLiteral( type, 0 );
	std::string oneStr = Gen_GetNumericLiteral( type, 1 );
	std::string twoStr = Gen_GetNumericLiteral( type, 2 );

	outHeader += "inline " + fullTypeName + " ortho( const " + typeString + " left, const " + typeString + " right, const " + typeString + " top, const " + typeString + " bottom, const " + typeString + " znear, const " + typeString + " zfar );\n";

	outHeader += "\n";

	outInl += "inline " + fullTypeName + " ortho( const " + typeString + " left, const " + typeString + " right, const " + typeString + " top, const " + typeString + " bottom, const " + typeString + " znear, const " + typeString + " zfar ) {\n";
	switch ( hand ) {
		case GEN_HAND_LEFT: {
			outInl += "\tconst " + typeString + " right_plus_left = right + left;\n";
			outInl += "\tconst " + typeString + " right_minus_left = right - left;\n";
			outInl += "\tconst " + typeString + " top_plus_bottom = top + bottom;\n";
			outInl += "\tconst " + typeString + " top_minus_bottom = top - bottom;\n";
			outInl += "\tconst " + typeString + " far_minus_near = zfar - znear;\n";
			outInl += "\n";
			outInl += "\treturn " + fullTypeName + "(\n";
			outInl += "\t\t" + twoStr + " / right_minus_left, " + zeroStr + ", " + zeroStr + ", -right_plus_left / right_minus_left,\n";
			outInl += "\t\t" + zeroStr + ", " + twoStr + " / top_minus_bottom, " + zeroStr + ", -top_plus_bottom / top_minus_bottom,\n";
			outInl += "\t\t" + zeroStr + ", " + zeroStr + ", " + oneStr + " / far_minus_near, " + "-znear / far_minus_near";
			outInl += ",\n\t\t" + zeroStr + ", " + zeroStr + ", " + zeroStr + ", " + oneStr + "\n";
			outInl += "\t);\n";
			break;
		}

		case GEN_HAND_RIGHT: {
			// TODO(DM):
			break;
		}

		default:
			// nothing
			break;
	}
	outInl += "}\n";

	outInl += "\n";
}

void Gen_MatrixPerspective( const hand_t hand, const genType_t type, const uint32_t numRows, const uint32_t numCols, std::string& outHeader, std::string& outInl ) {
	assert( numRows >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );

	if ( type != GEN_TYPE_FLOAT && type != GEN_TYPE_DOUBLE ) {
		return;
	}

	if ( numRows != 4 || numCols != 4 ) {
		return;
	}

	std::string typeString = Gen_GetTypeString( type );
	std::string fullTypeName = typeString + std::to_string( numRows ) + "x" + std::to_string( numCols );

	std::string zeroStr = Gen_GetNumericLiteral( type, 0 );
	std::string oneStr = Gen_GetNumericLiteral( type, 1 );

	outHeader += "inline " + fullTypeName + " perspective( const " + typeString + " fovdeg, const " + typeString + " aspect, const " + typeString + " znear, const " + typeString + " zfar );\n";

	outHeader += "\n";

	outInl += fullTypeName + " perspective( const " + typeString + " fovdeg, const " + typeString + " aspect, const " + typeString + " znear, const " + typeString + " zfar ) {\n";
	switch ( hand ) {
		case GEN_HAND_LEFT: {
			outInl += "\tconst " + typeString + " far_minus_near = zfar - znear;\n";
			outInl += "\tconst " + typeString + " tan_half_fov = static_cast<" + typeString + ">( tan( ( fovdeg / " + Gen_GetNumericLiteral( type, 2 ) + " ) * radians( fovdeg ) ) );\n";
			outInl += "\n";
			outInl += "\treturn " + fullTypeName + "(\n";
			outInl += "\t\t" + oneStr + " / ( aspect * tan_half_fov ), " + zeroStr + ", " + zeroStr + ", " + zeroStr + ",\n";
			outInl += "\t\t" + zeroStr + ", " + oneStr + " / tan_half_fov, " + zeroStr + ", " + zeroStr + ",\n";
			outInl += "\t\t" + zeroStr + ", " + zeroStr + ", zfar / far_minus_near, " + oneStr + ",\n";
			outInl += "\t\t" + zeroStr + ", " + zeroStr + ", -( zfar * znear ) / far_minus_near, " + zeroStr + "\n";
			outInl += "\t);\n";
			break;
		}

		case GEN_HAND_RIGHT: {
			// TODO(DM):
			break;
		}

		default:
			// nothing
			break;
	}
	outInl += "}\n";

	outInl += "\n";
}

void Gen_MatrixLookAt( const hand_t hand, const genType_t type, const uint32_t numRows, const uint32_t numCols, std::string& outHeader, std::string& outInl ) {
	assert( numRows >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );

	if ( type != GEN_TYPE_FLOAT && type != GEN_TYPE_DOUBLE ) {
		return;
	}

	if ( numRows != 4 || numCols != 4 ) {
		return;
	}

	std::string typeString = Gen_GetTypeString( type );
	std::string vectorTypeString = typeString + std::to_string( numRows );
	std::string fullTypeName = typeString + std::to_string( numRows ) + "x" + std::to_string( numCols );

	outHeader += "inline " + fullTypeName + " lookat( const " + vectorTypeString + "& eye, const " + vectorTypeString + "& target, const " + vectorTypeString + "& up );\n";

	outHeader += "\n";

	outInl += fullTypeName + " lookat( const " + vectorTypeString + "& eye, const " + vectorTypeString + "& target, const " + vectorTypeString + "& up ) {\n";
	switch ( hand ) {
		case GEN_HAND_LEFT: {
			outInl += "\tconst " + vectorTypeString + " forward = normalized( target - eye );\n";
			outInl += "\tconst " + vectorTypeString + " right = normalized( cross( up, forward ) );\n";
			outInl += "\tconst " + vectorTypeString + " up1 = normalized( cross( forward, right ) );\n";
			outInl += "\n";
			outInl += "\treturn " + fullTypeName + "(\n";
			outInl += "\t\tright,\n";
			outInl += "\t\tup1,\n";
			outInl += "\t\tforward,\n";
			outInl += "\t\t" + vectorTypeString + "( -dot( right, eye ), -dot( up1, eye ), -dot( forward, eye ), " + Gen_GetNumericLiteral( type, 1 ) + " )\n";
			outInl += "\t);\n";
			break;
		}

		case GEN_HAND_RIGHT: {
			// TODO(DM):
			break;
		}

		default:
			// nothing
			break;
	}
	outInl += "}\n";

	outInl += "\n";
}
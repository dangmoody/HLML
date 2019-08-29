#pragma once

#include "gen_common.h"
#include "string_builder.h"

inline void Doc_MatrixMultiplication( stringBuilder_t* sb, const char* fullTypeName ) {
	String_Appendf( sb,
		"/// \\relates %s\n" \
		"/// \\brief Returns a copy of the matrix where each row of the left-hand matrix has been dot-producted by the corresponding column of the right-hand matrix.\n", fullTypeName
	);
}

inline void Doc_MatrixMultiplicationCompound( stringBuilder_t* sb, const char* fullTypeName ) {
	String_Appendf( sb,
		"/// \\relates %s\n" \
		"/// \\brief Dot products each row of the left-hand matrix with the corresponding column of the right-hand matrix.\n", fullTypeName
	);
}

inline void Doc_MatrixDivision( stringBuilder_t* sb, const char* fullTypeName ) {
	String_Appendf( sb,
		"/// \\relates %s\n" \
		"/// \\brief Returns a copy of the matrix where the left-hand matrix has been mathematically multiplied by the inverse of the right-hand matrix.\n", fullTypeName
	);
}

inline void Doc_MatrixDivisionCompound( stringBuilder_t* sb, const char* fullTypeName ) {
	String_Appendf( sb,
		"/// \\relates %s\n" \
		"/// \\brief Multiplies the left-hand matrix by the right-hand matrix (dot product row/col style).\n", fullTypeName
	);
}

inline void Doc_MatrixIdentity( stringBuilder_t* sb, const char* fullTypeName ) {
	String_Appendf( sb,
		"/// \\relates %s\n" \
		"/// \\brief Sets the matrix to an identity matrix.\n", fullTypeName
	);
}

inline void Doc_MatrixTranpose( stringBuilder_t* sb, const char* fullTypeName ) {
	String_Appendf( sb,
		"/// \\relates %s\n" \
		"/// \\brief Returns a copy of the matrix that is transposed, where the value of each row is set to the value of each column and vice versa.\n", fullTypeName
	);
}

inline void Doc_MatrixInverse( stringBuilder_t* sb, const char* fullTypeName ) {
	String_Appendf( sb,
		"/// \\relates %s\n" \
		"/// \\brief Returns a copy of the matrix that is inversed.\n" \
		"/// Currently this is only applicable for square matrices.  Pseudo-inverse support for non-square matrices is coming soon.\n", fullTypeName
	);
}

inline void Doc_MatrixDeterminant( stringBuilder_t* sb, const char* fullTypeName ) {
	String_Appendf( sb,
		"/// \\relates %s\n" \
		"/// \\brief Returns the determinant of the matrix.\n", fullTypeName
	);
}

inline void Doc_MatrixTranslate( stringBuilder_t* sb, const char* fullTypeName ) {
	String_Appendf( sb,
		"/// \\relates %s\n" \
		"/// \\brief Returns a copy of the matrix where each component of the 3rd column has been added by the given vector.\n", fullTypeName
	);
}

inline void Doc_MatrixRotate( stringBuilder_t* sb, const char* fullTypeName ) {
	String_Appendf( sb,
		"/// \\relates %s\n" \
		"/// \\brief Returns a copy of the matrix that has had a rotation applied to it in radians on one or more of the following axes.\n", fullTypeName
	);
}

inline void Doc_MatrixScaleUniform( stringBuilder_t* sb, const char* fullTypeName ) {
	String_Appendf( sb,
		"/// \\relates %s\n" \
		"/// \\brief Returns a copy of the matrix that has had a uniform scale applied to it.\n", fullTypeName
	);
}

inline void Doc_MatrixScaleNonUniform( stringBuilder_t* sb, const char* fullTypeName ) {
	String_Appendf( sb,
		"/// \\relates %s\n" \
		"/// \\brief Returns a copy of the matrix that has had a non-uniform scale applied to it.\n", fullTypeName
	);
}

inline void Doc_MatrixOrtho( stringBuilder_t* sb, const char* fullTypeName, const genHand_t hand, const genClipSpace_t range ) {
	const char* handStr = Gen_GetHandString( hand );
	const char* rangeStr = Gen_GetClipSpaceRangeString( range );

	String_Appendf( sb,
		"/// \\relates %s\n" \
		"/// \\brief Returns an %s-handed orthographic projection matrix with the clip-space range %s.\n", fullTypeName, handStr, rangeStr
	);
}

inline void Doc_MatrixPerspective( stringBuilder_t* sb, const char* fullTypeName, const genHand_t hand, const genClipSpace_t range ) {
	const char* handStr = Gen_GetHandString( hand );
	const char* rangeStr = Gen_GetClipSpaceRangeString( range );

	String_Appendf( sb,
		"/// \\relates %s\n" \
		"/// \\brief Returns a %s-handed perspective projection matrix based on a vertical field-of-view in degrees and an aspect ratio " \
		"in the clip-space range of %s.\n", fullTypeName, handStr, rangeStr
	);
}

inline void Doc_MatrixLookAt( stringBuilder_t* sb, const char* fullTypeName, const genHand_t hand ) {
	const char* handStr = Gen_GetHandString( hand );

	String_Appendf( sb,
		"/// \\relates %s\n" \
		"/// \\brief Returns a %s-handed orthonormal matrix that is oriented at position eye to look at position target.\n", fullTypeName, handStr
	);
}
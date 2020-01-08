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
#pragma once

#include "gen_common.h"
#include "string_builder.h"

inline void Doc_QuaternionMultiplyRhsType( stringBuilder_t* sb, const char* fullTypeName ) {
	String_Appendf( sb,
		"/// \\relates %s\n"
		"/// \\brief Performs a quaternion multiplication of the two given quaternions.\n", fullTypeName
	);
}

inline void Doc_QuaternionMultiplyScalar( stringBuilder_t* sb, const char* fullTypeName ) {
	String_Appendf( sb,
		"/// \\relates %s\n"
		"/// \\brief Multiplies the given quaternion by the given scalar.\n", fullTypeName
	);
}

inline void Doc_QuaternionLength( stringBuilder_t* sb, const char* fullTypeName ) {
	String_Appendf( sb,
		"/// \\relates %s\n"
		"/// \\brief Returns the length of the quaternion.\n", fullTypeName
	);
}

inline void Doc_QuaternionNormalize( stringBuilder_t* sb, const char* fullTypeName ) {
	String_Appendf( sb,
		"/// \\relates %s\n"
		"/// \\brief Normalizes the quaternion.\n", fullTypeName
	);
}

inline void Doc_QuaternionConjugate( stringBuilder_t* sb, const char* fullTypeName ) {
	String_Appendf( sb,
		"/// \\relates %s\n"
		"/// \\brief Returns the conjugate of the quaternion.\n", fullTypeName
	);
}

inline void Doc_QuaternionInverse( stringBuilder_t* sb, const char* fullTypeName ) {
	String_Appendf( sb,
		"/// \\relates %s\n"
		"/// \\brief Returns the inverse of the quaternion.\n", fullTypeName
	);
}

inline void Doc_QuaternionRotateAxis( stringBuilder_t* sb, const char* fullTypeName ) {
	String_Appendf( sb,
		"/// \\relates %s\n"
		"/// \\brief Performs a rotation on the quaternion by the given axis-angle and angle (in degrees).\n", fullTypeName
	);
}

inline void Doc_QuaternionSlerp( stringBuilder_t* sb, const char* fullTypeName ) {
	String_Appendf( sb,
		"/// \\relates %s\n"
		"/// \\brief Returns a 'slowly' linearly interpolated %s between \"a\" and \"b\".\n", fullTypeName, fullTypeName
	);
}
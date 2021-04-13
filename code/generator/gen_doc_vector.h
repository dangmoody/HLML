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
#include "string_builder.h"

inline void Doc_VectorLengthSqr( stringBuilder_t* sb, const char* fullTypeName ) {
	String_Appendf( sb,
		"// Returns the magnitude of the vector squared.\n", fullTypeName
	);
}

inline void Doc_VectorLength( stringBuilder_t* sb, const char* fullTypeName ) {
	String_Appendf( sb,
		"// Returns the magnitude of the vector.\n", fullTypeName
	);
}

inline void Doc_VectorNormalize( stringBuilder_t* sb, const char* fullTypeName ) {
	String_Appendf( sb,
		"// Normalizes the vector.\n", fullTypeName
	);
}

inline void Doc_VectorNormalized( stringBuilder_t* sb, const char* fullTypeName ) {
	String_Appendf( sb,
		"// Returns a normalized copy of the vector.\n", fullTypeName
	);
}

inline void Doc_VectorDot( stringBuilder_t* sb, const char* fullTypeName ) {
	String_Appendf( sb,
		"// Returns the dot product of the two vectors.\n", fullTypeName
	);
}

inline void Doc_VectorCross( stringBuilder_t* sb, const char* fullTypeName ) {
	String_Appendf( sb,
		"// Returns a vector perpendicular (normal) to the two vectors.\n", fullTypeName
	);
}

inline void Doc_VectorAngle( stringBuilder_t* sb, const char* fullTypeName ) {
	String_Appendf( sb,
		"// Returns the angle in degrees between the two vectors.\n", fullTypeName
	);
}

inline void Doc_VectorDistanceSq( stringBuilder_t* sb, const char* fullTypeName ) {
	String_Appendf( sb,
		"// Returns the squared distance between the two vectors.\n", fullTypeName
	);
}

inline void Doc_VectorDistance( stringBuilder_t* sb, const char* fullTypeName ) {
	String_Appendf( sb,
		"// Returns the distance between the two vectors.\n", fullTypeName
	);
}

inline void Doc_VectorPack( stringBuilder_t* sb, const char* fullTypeName ) {
	String_Appendf( sb,
		"// Returns a 32 bit integer containing each component of the vector (starting with x) at each byte.\n", fullTypeName
	);
}

inline void Doc_VectorUnpack( stringBuilder_t* sb, const char* fullTypeName ) {
	String_Appendf( sb,
		"// Returns a 4-component integer vector containing each byte of the given integer.\n", fullTypeName
	);
}

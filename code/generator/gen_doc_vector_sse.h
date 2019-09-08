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

#include "string_builder.h"

inline void Doc_SSE_VectorNormalize( stringBuilder_t* sbHeader, const char* fullTypeName ) {
	String_Appendf( sbHeader,
		"/// \\relates %s\n" \
		"/// \\brief Normalizes each input array element and stores the normalized result in the corresponding element in the output.\n", fullTypeName
	);
}

inline void Doc_SSE_VectorDot( stringBuilder_t* sbHeader, const char* fullTypeName ) {
	String_Appendf( sbHeader,
		"/// \\relates %s\n" \
		"/// \\brief Performs a dot-product on each index of the left-hand-side and right-hand-side registers, respectively, and stores the result in its respective component in the output register.\n", fullTypeName
	);
}

inline void Doc_SSE_VectorLengthsq( stringBuilder_t* sbHeader, const char* fullTypeName ) {
	String_Appendf( sbHeader,
		"/// \\relates %s\n" \
		"/// \\brief Finds the squared length of each input vector and stores it in its respective component in the output register.\n", fullTypeName
	);
}

inline void Doc_SSE_VectorLength( stringBuilder_t* sbHeader, const char* fullTypeName ) {
	String_Appendf( sbHeader,
		"/// \\relates %s\n" \
		"/// \\brief Finds the length of each input vector and stores it in its respective component in the output register.\n", fullTypeName
	);
}

inline void Doc_SSE_VectorDistancesq( stringBuilder_t* sbHeader, const char* fullTypeName ) {
	String_Appendf( sbHeader,
		"/// \\relates %s\n" \
		"/// \\brief Finds the squared distance between each vector and stores the result in its respective component in the output register.\n", fullTypeName
	);
}

inline void Doc_SSE_VectorDistance( stringBuilder_t* sbHeader, const char* fullTypeName ) {
	String_Appendf( sbHeader,
		"/// \\relates %s\n" \
		"/// \\brief Finds the distance between each vector and stores the result in its respective component in the output register.\n", fullTypeName
	);
}

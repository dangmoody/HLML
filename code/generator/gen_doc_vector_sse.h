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

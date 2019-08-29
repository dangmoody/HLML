#include "string_builder.h"

inline void Doc_VectorLengthSqr( stringBuilder_t* sb, const char* fullTypeName ) {
	String_Appendf( sb,
		"/// \\relates %s\n" \
		"/// \\brief Returns the magnitude of the vector squared.\n", fullTypeName
	);
}

inline void Doc_VectorLength( stringBuilder_t* sb, const char* fullTypeName ) {
	String_Appendf( sb,
		"/// \\relates %s\n" \
		"/// \\brief Returns the magnitude of the vector.\n", fullTypeName
	);
}

inline void Doc_VectorNormalize( stringBuilder_t* sb, const char* fullTypeName ) {
	String_Appendf( sb,
		"/// \\relates %s\n" \
		"/// \\brief Normalizes the vector.\n", fullTypeName
	);
}

inline void Doc_VectorNormalized( stringBuilder_t* sb, const char* fullTypeName ) {
	String_Appendf( sb,
		"/// \\relates %s\n" \
		"/// \\brief Returns a normalized copy of the vector.\n", fullTypeName
	);
}

inline void Doc_VectorDot( stringBuilder_t* sb, const char* fullTypeName ) {
	String_Appendf( sb,
		"/// \\relates %s\n" \
		"/// \\brief Returns the dot product of the two vectors.\n", fullTypeName
	);
}

inline void Doc_VectorCross( stringBuilder_t* sb, const char* fullTypeName ) {
	String_Appendf( sb,
		"/// \\relates %s\n" \
		"/// \\brief Returns a vector perpendicular (normal) to the two vectors.\n", fullTypeName
	);
}

inline void Doc_VectorAngle( stringBuilder_t* sb, const char* fullTypeName ) {
	String_Appendf( sb,
		"/// \\relates %s\n" \
		"/// \\brief Returns the angle in degrees between the two vectors.\n", fullTypeName
	);
}

inline void Doc_VectorDistanceSq( stringBuilder_t* sb, const char* fullTypeName ) {
	String_Appendf( sb,
		"/// \\relates %s\n" \
		"/// \\brief Returns the squared distance between the two vectors.\n", fullTypeName
	);
}

inline void Doc_VectorDistance( stringBuilder_t* sb, const char* fullTypeName ) {
	String_Appendf( sb,
		"/// \\relates %s\n" \
		"/// \\brief Returns the distance between the two vectors.\n", fullTypeName
	);
}

inline void Doc_VectorPack( stringBuilder_t* sb, const char* fullTypeName ) {
	String_Appendf( sb,
		"/// \\relates %s\n" \
		"/// \\brief Returns a 32 bit integer containing each component of the vector (starting with x) at each byte.\n", fullTypeName
	);
}

inline void Doc_VectorUnpack( stringBuilder_t* sb, const char* fullTypeName ) {
	String_Appendf( sb,
		"/// \\relates %s\n" \
		"/// \\brief Returns a 4-component integer vector containing each byte of the given integer.\n", fullTypeName
	);
}

static void DocLengthSqr( stringBuilder_t* sb, const char* fullTypeName ) {
	String_Appendf( sb,
		"/// \\relates %s\n" \
		"/// \\brief Returns the magnitude of the vector squared.\n", fullTypeName );
}

static void DocLength( stringBuilder_t* sb, const char* fullTypeName ) {
	String_Appendf( sb,
		"/// \\relates %s\n" \
		"/// \\brief Returns the magnitude of the vector.\n", fullTypeName );
}

static void DocNormalize( stringBuilder_t* sb, const char* fullTypeName ) {
	String_Appendf( sb,
		"/// \\relates %s\n" \
		"/// \\brief Normalizes the vector.\n", fullTypeName );
}

static void DocNormalized( stringBuilder_t* sb, const char* fullTypeName ) {
	String_Appendf( sb,
		"/// \\relates %s\n" \
		"/// \\brief Returns a normalized copy of the vector.\n", fullTypeName );
}

static void DocDot( stringBuilder_t* sb, const char* fullTypeName ) {
	String_Appendf( sb,
		"/// \\relates %s\n" \
		"/// \\brief Returns the dot product of the two vectors.\n", fullTypeName );
}

static void DocCross( stringBuilder_t* sb, const char* fullTypeName ) {
	String_Appendf( sb,
		"/// \\relates %s\n" \
		"/// \\brief Returns a vector perpendicular (normal) to the two vectors.\n", fullTypeName );
}

static void DocAngle( stringBuilder_t* sb, const char* fullTypeName ) {
	String_Appendf( sb,
		"/// \\relates %s\n" \
		"/// \\brief Returns the angle in degrees between the two vectors.\n", fullTypeName );
}

static void DocDistanceSq( stringBuilder_t* sb, const char* fullTypeName ) {
	String_Appendf( sb,
		"/// \\relates %s\n" \
		"/// \\brief Returns the squared distance between the two vectors.\n", fullTypeName );
}

static void DocDistance( stringBuilder_t* sb, const char* fullTypeName ) {
	String_Appendf( sb,
		"/// \\relates %s\n" \
		"/// \\brief Returns the distance between the two vectors.\n", fullTypeName );
}

static void DocPack( stringBuilder_t* sb, const char* fullTypeName ) {
	String_Appendf( sb,
		"/// \\relates %s\n" \
		"/// \\brief Returns a 32 bit integer containing each component of the vector (starting with x) at each byte.\n", fullTypeName );
}

static void DocUnpack( stringBuilder_t* sb, const char* fullTypeName ) {
	String_Appendf( sb,
		"/// \\relates %s\n" \
		"/// \\brief Returns a 4-component integer vector containing each byte of the given integer.\n", fullTypeName );
}

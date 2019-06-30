#include "GeneratorMatrix.h"

#include "allocator.h"
#include "string_builder.h"

#include "gen_doc_common.h"

#include "FileIO.h"

bool GeneratorMatrix::Generate( const genType_t type, const u32 numRows, const u32 numCols ) {
	assert( numRows >= GEN_COMPONENT_COUNT_MIN );
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );

	m_type = type;

	m_numRows = numRows;
	m_numCols = numCols;

	m_typeString = Gen_GetTypeString( type );
	m_memberTypeString = Gen_GetMemberTypeString( type );

	snprintf( m_fullTypeName, GEN_STRING_LENGTH_TYPE_NAME, "%s%dx%d", m_typeString, m_numRows, m_numCols );
	snprintf( m_transposedTypeName, GEN_STRING_LENGTH_TYPE_NAME, "%s%dx%d", m_typeString, m_numCols, m_numRows );

	snprintf( m_vectorMemberTypeString, GEN_STRING_LENGTH_TYPE_NAME, "%s%d", m_typeString, m_numCols );

	m_codeHeader = String_Create( 8 * KB_TO_BYTES );
	m_codeInl = String_Create( 8 * KB_TO_BYTES );

	// header pre-functions
	{
		String_Append( &m_codeHeader, GEN_FILE_HEADER );

		String_Append( &m_codeHeader, "#pragma once\n" );
		String_Append( &m_codeHeader, "\n" );

		String_Appendf( &m_codeHeader, "#include \"%s%d.h\"\n", m_typeString, m_numCols );						// vec type
		if ( m_numRows != m_numCols ) {
			String_Appendf( &m_codeHeader, "#include \"%s%dx%d.h\"\n", m_typeString, m_numRows, m_numRows );	// multiplication return type
			String_Appendf( &m_codeHeader, "#include \"%s.h\"\n", m_transposedTypeName );						// transpose type
		}
		String_Append( &m_codeHeader, "\n" );

		GenerateDocStruct();
		String_Appendf( &m_codeHeader, "struct %s\n", m_fullTypeName );
		String_Append(  &m_codeHeader, "{\n" );

		String_Appendf( &m_codeHeader, "\t%s rows[%d];\n", m_vectorMemberTypeString, m_numRows );
		String_Append(  &m_codeHeader, "\n" );
	}

	// inl pre-functions
	{
		String_Append( &m_codeInl, GEN_FILE_HEADER );

//		String_Append( &m_codeInl, "// hlml includes\n" );
//		String_Append( &m_codeInl, "#include \"../" GEN_HEADER_CONSTANTS "\"\n" );
//		String_Append( &m_codeInl, "\n" );

		String_Append( &m_codeInl, "// others\n" );
		String_Append( &m_codeInl, "#include <math.h>\n" );
		String_Append( &m_codeInl, "\n" );

		if ( m_type != GEN_TYPE_BOOL ) {
			String_Append(  &m_codeInl, "// forward declares\n" );
			String_Appendf( &m_codeInl, "%s inverse( const %s& mat );\n", m_fullTypeName, m_fullTypeName );

			String_Append( &m_codeInl, "\n" );
		}
	}

	GenerateConstructors();

	GenerateOperatorsAssignment();

	GenerateOperatorsArray();

	String_Append( &m_codeHeader, "};\n\n" );

	GenerateOperatorsEquality();

	String_Appendf( &m_codeHeader, "#include \"%s.inl\"", m_fullTypeName );
	String_Append(  &m_codeHeader, "\n" );

	char fileNameHeader[64];
	snprintf( fileNameHeader, 64, "%s%s.h", GEN_OUT_GEN_FOLDER_PATH, m_fullTypeName );

	char fileNameInl[64];
	snprintf( fileNameInl, 64, "%s%s.inl", GEN_OUT_GEN_FOLDER_PATH, m_fullTypeName );

	bool32 wroteHeader	= FS_WriteEntireFile( fileNameHeader, m_codeHeader.str, m_codeHeader.length );
	bool32 wroteInl		= FS_WriteEntireFile( fileNameInl, m_codeInl.str, m_codeInl.length );

	Mem_Reset();

	return wroteHeader && wroteInl;
}

#ifdef _DEBUG
void GeneratorMatrix::PrintHeader() const {
	printf( "%s\n", m_codeHeader.str );
}

void GeneratorMatrix::PrintInl() const {
	printf( "%s\n", m_codeInl.str );
}
#endif

void GeneratorMatrix::GenerateConstructors() {
	// default ctor
	{
		GenerateDocCtorDefault();
		String_Appendf( &m_codeHeader, "\tinline %s();\n", m_fullTypeName );
		String_Append(  &m_codeHeader, "\n" );

		String_Appendf( &m_codeInl, "%s::%s()\n", m_fullTypeName, m_fullTypeName );
		String_Append(  &m_codeInl, "{\n" );
		for ( u32 row = 0; row < m_numRows; row++ ) {
			String_Appendf( &m_codeInl, "\trows[%d] = { ", row );
			for ( u32 col = 0; col < m_numCols; col++ ) {
				String_Append( &m_codeInl, ( row == col ) ? "1" : "0" );

				if ( col != m_numCols - 1 ) {
					String_Append( &m_codeInl, ", " );
				}
			}
			String_Append( &m_codeInl, " };\n" );
		}
		String_Append( &m_codeInl, "}\n\n" );
	}

	// "diagonal" scaled uniform identity ctor
	{
		GenerateDocCtorDiagonalScalar();
		String_Appendf( &m_codeHeader, "\tinline %s( const %s diagonal );\n", m_fullTypeName, m_memberTypeString );
		String_Append(  &m_codeHeader, "\n" );

		String_Appendf( &m_codeInl, "%s::%s( const %s diagonal )\n", m_fullTypeName, m_fullTypeName, m_memberTypeString );
		String_Append(  &m_codeInl, "{\n" );
		for ( u32 i = 0; i < m_numRows; i++ ) {
			String_Appendf( &m_codeInl, "\trows[%d] = { ", i );
			for ( u32 j = 0; j < m_numCols; j++ ) {
				String_Append( &m_codeInl, ( i == j ) ? "diagonal" : "0" );

				if ( j != m_numCols - 1 ) {
					String_Append( &m_codeInl, ", " );
				}
			}
			String_Append( &m_codeInl, " };\n" );
		}
		String_Append( &m_codeInl, "}\n\n" );
	}

	// "diagonal" scaled non-uniform identity ctor
	{
		GenerateDocCtorDiagonalVector();
		String_Appendf( &m_codeHeader, "\tinline %s( const %s& diagonal );\n", m_fullTypeName, m_vectorMemberTypeString );
		String_Append(  &m_codeHeader, "\n" );

		String_Appendf( &m_codeInl, "%s::%s( const %s& diagonal )\n", m_fullTypeName, m_fullTypeName, m_vectorMemberTypeString );
		String_Append(  &m_codeInl, "{\n" );
		for ( u32 i = 0; i < m_numRows; i++ ) {
			String_Appendf( &m_codeInl, "\trows[%d] = { ", i );
			for ( u32 j = 0; j < m_numCols; j++ ) {
				if ( i == j ) {
					String_Appendf( &m_codeInl, "diagonal.%c", GEN_COMPONENT_NAMES_VECTOR[j] );
				} else {
					String_Append( &m_codeInl, "0" );
				}

				if ( j != m_numCols - 1 ) {
					String_Append( &m_codeInl, ", " );
				}
			}
			String_Append( &m_codeInl, " };\n" );
		}
		String_Append( &m_codeInl, "}\n\n" );
	}

	// row memberwise ctor
	{
		GenerateDocCtorRow();
		String_Appendf( &m_codeHeader, "\tinline %s( ", m_fullTypeName );
		for ( u32 i = 0; i < m_numRows; i++ ) {
			String_Appendf( &m_codeHeader, "const %s& row%d", m_vectorMemberTypeString, i );

			if ( i != m_numRows - 1 ) {
				String_Append( &m_codeHeader, ", " );
			}
		}
		String_Append( &m_codeHeader, " );\n" );
		String_Append( &m_codeHeader, "\n" );

		String_Appendf( &m_codeInl, "%s::%s( ", m_fullTypeName, m_fullTypeName );
		for ( u32 i = 0; i < m_numRows; i++ ) {
			String_Appendf( &m_codeInl, "const %s& row%d", m_vectorMemberTypeString, i );

			if ( i != m_numRows - 1 ) {
				String_Append( &m_codeInl, ", " );
			}
		}
		String_Append( &m_codeInl, " )\n" );
		String_Append( &m_codeInl, "{\n" );
		for ( u32 i = 0; i < m_numRows; i++ ) {
			String_Appendf( &m_codeInl, "\trows[%d] = row%d;\n", i, i );
		}
		String_Append( &m_codeInl, "}\n\n" );
	}

	// array of rows ctor
	{
		GenerateDocCtorRowArray();
		String_Appendf( &m_codeHeader, "\tinline %s( const %s rows[%d] );\n", m_fullTypeName, m_vectorMemberTypeString, m_numRows );
		String_Append(  &m_codeHeader, "\n" );

		String_Appendf( &m_codeInl, "%s::%s( const %s rows[%d] )\n", m_fullTypeName, m_fullTypeName, m_vectorMemberTypeString, m_numRows );
		String_Append(  &m_codeInl, "{\n" );
		for ( u32 i = 0; i < m_numRows; i++ ) {
			String_Appendf( &m_codeInl, "\tthis->rows[%d] = rows[%d];\n", i, i );
		}
		String_Append( &m_codeInl, "}\n\n" );
	}

	// memberwise rows * cols ctor
	{
		GenerateDocCtorRowsAndCols();
		String_Appendf( &m_codeHeader, "\tinline %s( ", m_fullTypeName );
		for ( u32 row = 0; row < m_numRows; row++ ) {
			for ( u32 col = 0; col < m_numCols; col++ ) {
				String_Appendf( &m_codeHeader, "const %s m%d%d", m_memberTypeString, row, col );

				if ( col != m_numCols - 1 ) {
					String_Append( &m_codeHeader, ", " );
				}
			}

			if ( row != m_numRows - 1 ) {
				String_Append( &m_codeHeader, ", " );
			}
		}
		String_Append( &m_codeHeader, " );\n" );
		String_Append( &m_codeHeader, "\n" );

		String_Appendf( &m_codeInl, "%s::%s( ", m_fullTypeName, m_fullTypeName );
		for ( u32 row = 0; row < m_numRows; row++ ) {
			for ( u32 col = 0; col < m_numCols; col++ ) {
				String_Appendf( &m_codeInl, "const %s m%d%d", m_memberTypeString, row, col );

				if ( col != m_numCols - 1 ) {
					String_Append( &m_codeInl, ", " );
				}
			}

			if ( row != m_numRows - 1 ) {
				String_Append( &m_codeInl, ", " );
			}
		}
		String_Append( &m_codeInl, " )\n" );
		String_Append( &m_codeInl, "{\n" );
		for ( u32 row = 0; row < m_numRows; row++ ) {
			String_Appendf( &m_codeInl, "\trows[%d] = { ", row );

			for ( u32 col = 0; col < m_numCols; col++ ) {
				String_Appendf( &m_codeInl, "m%d%d", row, col );

				if ( col != m_numCols - 1 ) {
					String_Append( &m_codeInl, ", " );
				}
			}
			String_Append( &m_codeInl, " };\n" );
		}
		String_Append( &m_codeInl, "}\n\n" );
	}

	// copy ctor
	{
		GenerateDocCtorCopy();
		String_Appendf( &m_codeHeader, "\tinline %s( const %s& other );\n", m_fullTypeName, m_fullTypeName );
		String_Append(  &m_codeHeader, "\n" );

		String_Appendf( &m_codeInl, "%s::%s( const %s& other )\n", m_fullTypeName, m_fullTypeName, m_fullTypeName );
		String_Append(  &m_codeInl, "{\n" );
		String_Appendf( &m_codeInl, "\tmemcpy( rows, other.rows, sizeof( rows ) );\n" );
		String_Append(  &m_codeInl, "}\n" );
		String_Append(  &m_codeInl, "\n" );
	}

	// dtor
	String_Appendf( &m_codeHeader, "\tinline ~%s() {}\n", m_fullTypeName );
	String_Append(  &m_codeHeader, "\n" );
}

void GeneratorMatrix::GenerateOperatorsAssignment() {
	// assignment operator
	GenerateDocOperatorAssignment();
	String_Appendf( &m_codeHeader, "\tinline %s operator=( const %s& other );\n", m_fullTypeName, m_fullTypeName );
	String_Append(  &m_codeHeader, "\n" );

	String_Appendf( &m_codeInl, "%s %s::operator=( const %s& other )\n", m_fullTypeName, m_fullTypeName, m_fullTypeName );
	String_Append(  &m_codeInl, "{\n" );
	String_Append(  &m_codeInl, "\tmemcpy( rows, other.rows, sizeof( rows ) );\n" );
	String_Append(  &m_codeInl, "\treturn *this;\n" );
	String_Append(  &m_codeInl, "}\n" );
	String_Append(  &m_codeInl, "\n" );
}

void GeneratorMatrix::GenerateOperatorsArray() {
	GenerateDocOperatorArray();
	String_Appendf( &m_codeHeader, "\tinline %s& operator[]( const uint32_t index );\n", m_vectorMemberTypeString );
	String_Append(  &m_codeHeader, "\n" );

	String_Appendf( &m_codeInl, "%s& %s::operator[]( const uint32_t index )\n", m_vectorMemberTypeString, m_fullTypeName );
	String_Append(  &m_codeInl, "{\n" );
	String_Appendf( &m_codeInl, "\tassert( index < %d );\n", m_numRows );
	String_Append(  &m_codeInl, "\treturn rows[index];\n" );
	String_Append(  &m_codeInl, "}\n" );
	String_Append(  &m_codeInl, "\n" );

	GenerateDocOperatorArray();
	String_Appendf( &m_codeHeader, "\tinline const %s& operator[]( const uint32_t index ) const;\n", m_vectorMemberTypeString );

	String_Appendf( &m_codeInl, "const %s& %s::operator[]( const uint32_t index ) const\n", m_vectorMemberTypeString, m_fullTypeName );
	String_Append(  &m_codeInl, "{\n" );
	String_Appendf( &m_codeInl, "\tassert( index < %d );\n", m_numRows );
	String_Append(  &m_codeInl, "\treturn rows[index];\n" );
	String_Append(  &m_codeInl, "}\n" );
	String_Append(  &m_codeInl, "\n" );
}

void GeneratorMatrix::GenerateOperatorsEquality() {
	// operator==
	{
		Gen_DocOperatorEquals( &m_codeHeader, m_fullTypeName );
		String_Appendf( &m_codeHeader, "inline bool operator==( const %s& lhs, const %s& rhs );\n", m_fullTypeName, m_fullTypeName );
		String_Append(  &m_codeHeader, "\n" );

		String_Appendf( &m_codeInl, "bool operator==( const %s& lhs, const %s& rhs )\n", m_fullTypeName, m_fullTypeName );
		String_Append(  &m_codeInl, "{\n" );
		String_Append(  &m_codeInl, "\treturn " );
		for ( u32 i = 0; i < m_numRows; i++ ) {
			String_Appendf( &m_codeInl, "lhs[%d] == rhs[%d]", i, i );

			if ( i != m_numRows - 1 ) {
				String_Append( &m_codeInl, "\n\t\t&& " );
			}
		}
		String_Append( &m_codeInl, ";\n" );
		String_Append( &m_codeInl, "}\n" );
		String_Append( &m_codeInl, "\n" );
	}

	Gen_OperatorNotEquals( m_type, m_numRows, m_numCols, &m_codeHeader, &m_codeInl );
}

void GeneratorMatrix::GenerateDocStruct() {
	String_Appendf( &m_codeHeader, "/// A matrix of %d %ss.\n", m_numRows, m_vectorMemberTypeString );
}

void GeneratorMatrix::GenerateDocCtorDefault() {
	String_Append( &m_codeHeader, "\t/// Default constructor.  Sets the matrix to an identity matrix.\n" );
}

void GeneratorMatrix::GenerateDocCtorDiagonalScalar() {
	String_Append( &m_codeHeader,
		"\t/// \\brief Sets each of the diagonal values of the matrix to the given scalar value.\n" \
		"\t/// Setting the scalar to 1 will give an identity matrix.\n" );
}

void GeneratorMatrix::GenerateDocCtorDiagonalVector() {
	String_Append( &m_codeHeader, 
		"\t/// \\brief Sets the diagonal values of the matrix to the corresponding components of the given vector.\n" \
		"\t/// Setting each component of the vector to 1 will give an identity matrix.\n" );
}

void GeneratorMatrix::GenerateDocCtorRow() {
	String_Append( &m_codeHeader, "\t/// Sets each row of the matrix to the given vectors.\n" );
}

void GeneratorMatrix::GenerateDocCtorRowArray() {
	String_Append( &m_codeHeader, "\t/// Sets each row of the matrix to the corresponding vector in the array.\n" );
}

void GeneratorMatrix::GenerateDocCtorRowsAndCols() {
	String_Append( &m_codeHeader, "\t/// Sets each component of the vector to the corresponding scalar value (row major).\n" );
}

void GeneratorMatrix::GenerateDocCtorCopy() {
	String_Append( &m_codeHeader, "\t/// Copy constructor.  Sets each row of the matrix to the rows in the other matrix.\n" );
}

void GeneratorMatrix::GenerateDocOperatorAssignment() {
	String_Append( &m_codeHeader, "\t/// Copies each row of the given matrix via a single memcpy.\n" );
}

void GeneratorMatrix::GenerateDocOperatorArray() {
	String_Appendf( &m_codeHeader,
		"\t/// \\brief Returns the row at the given index of the matrix.\n" \
		"\t/// Index CANNOT be lower than 0 or higher than %d.\n", m_numRows - 1 );
}

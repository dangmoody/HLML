/*
===========================================================================

HLML

Copyright (c) Dan Moody 2018 - Present.

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

===========================================================================
*/

#pragma once

#include "int_types.h"

typedef struct allocatorLinear_t allocatorLinear_t;
typedef struct stringBuilder_t stringBuilder_t;

// suffixes only - the "file_prefix" config value (default "hlml_") is prepended at generation time,
// see Gen_GetPrefixedFilename() in gen_shared.c
#define GEN_FILENAME_SUFFIX_TYPES					"types.h"
#define GEN_FILENAME_SUFFIX_CONSTANTS				"constants.h"
#define GEN_FILENAME_SUFFIX_CONSTANTS_SSE			"constants_sse.h"
#define GEN_FILENAME_SUFFIX_DEFINES				"defines.h"

#define GEN_FILENAME_SUFFIX_FUNCTIONS_SCALAR		"functions_scalar"
#define GEN_FILENAME_SUFFIX_FUNCTIONS_VECTOR		"functions_vector"
#define GEN_FILENAME_SUFFIX_FUNCTIONS_MATRIX		"functions_matrix"
#define GEN_FILENAME_SUFFIX_FUNCTIONS_QUATERNION	"functions_quaternion"

#define GEN_FILENAME_SUFFIX_FUNCTIONS_SCALAR_SSE	"functions_scalar_sse"
#define GEN_FILENAME_SUFFIX_FUNCTIONS_VECTOR_SSE	"functions_vector_sse"
//#define GEN_FILENAME_SUFFIX_FUNCTIONS_MATRIX_SSE	"functions_matrix_sse"

// C specific maths functions
#define GEN_BUILTIN_FUNCTION_NAME_SIN			"sin"
#define GEN_BUILTIN_FUNCTION_NAME_COS			"cos"
#define GEN_BUILTIN_FUNCTION_NAME_ACOS			"acos"
#define GEN_BUILTIN_FUNCTION_NAME_TAN			"tan"
#define GEN_BUILTIN_FUNCTION_NAME_FABS			"fabs"
#define GEN_BUILTIN_FUNCTION_NAME_SQRT			"sqrt"

// SSE intrinsics
#define GEN_INTRINSIC_SET1						"set1"
#define GEN_INTRINSIC_MUL						"mul"


typedef enum {
	GEN_VERSION_MAJOR		= 3,
	GEN_VERSION_MINOR		= 0,
	GEN_VERSION_PATCH		= 0,
} genVersion_t;

typedef enum genType_t {
	GEN_TYPE_BOOL			= 0,
	GEN_TYPE_INT,
	GEN_TYPE_UINT,
	GEN_TYPE_FLOAT,
	GEN_TYPE_DOUBLE,

	GEN_TYPE_COUNT
} genType_t;

typedef enum genMathsType_t {
	GEN_MATHS_TYPE_SCALAR	= 0,
	GEN_MATHS_TYPE_VECTOR,
	GEN_MATHS_TYPE_MATRIX
} genMathsType_t;

typedef struct typeInfo_t {
	genType_t		type;
	u32				numRows;
	u32				numCols;
	const char		*fullTypeName;
} typeInfo_t;

typedef enum genOpRelational_t {
	GEN_OP_RELATIONAL_LESS_THAN			= 0,
	GEN_OP_RELATIONAL_LESS_THAN_EQUAL,
	GEN_OP_RELATIONAL_GREATER_THAN,
	GEN_OP_RELATIONAL_GREATER_THAN_EQUAL,

	GEN_OP_RELATIONAL_COUNT
} genOpRelational_t;

typedef enum genOpArithmetic_t {
	GEN_OP_ARITHMETIC_ADD				= 0,
	GEN_OP_ARITHMETIC_SUB,
	GEN_OP_ARITHMETIC_MUL,
	GEN_OP_ARITHMETIC_DIV,

	GEN_OP_ARITHMETIC_COUNT
} genOpArithmetic_t;

typedef enum genOpIncrement_t {
	GEN_OP_INCREMENT					= 0,
	GEN_OP_DECREMENT,

	GEN_OP_INCREMENT_COUNT
} genOpIncrement_t;

typedef enum genOpBitwise_t {
	GEN_OP_BITWISE_NOT					= 0,
	GEN_OP_BITWISE_AND,
	GEN_OP_BITWISE_OR,
	GEN_OP_BITWISE_XOR,
	GEN_OP_BITWISE_SHIFT_LEFT,
	GEN_OP_BITWISE_SHIFT_RIGHT,

	GEN_OP_BITWISE_COUNT
} genOpBitwise_t;

typedef struct genFunctionParm_t {
	const typeInfo_t	*typeInfo;
	const char			*name;
} genFunctionParm_t;

static const char		*GEN_COMPONENT_NAMES_VECTOR	= "xyzw";
static const char		*GEN_COMPONENT_NAMES_COLOR	= "rgba";

typedef enum generatorFlagBits_t {
	GENERATOR_FLAG_GENERATE_OPERATORS						= GEN_BIT( 0 ),
	GENERATOR_FLAG_NAME_MANGLING							= GEN_BIT( 1 ),
	GENERATOR_FLAG_VECTOR_UNIONS							= GEN_BIT( 2 ),
	GENERATOR_FLAG_GENERATE_CONSTRUCTORS					= GEN_BIT( 3 ),
	GENERATOR_FLAG_PARMS_ARE_POINTERS						= GEN_BIT( 4 ),		// if not set then parms are references
	GENERATOR_FLAG_C_LINKAGE								= GEN_BIT( 5 ),		// will generate all the extern "C" stuff and all things related to that
	GENERATOR_FLAG_VECTOR_SWIZZLES							= GEN_BIT( 6 ),		// generate HLSL-style vector swizzles
	GENERATOR_FLAG_ALLOW_NAMESPACE							= GEN_BIT( 7 ),		// allow an (optional) namespace in the generated code called "hlml"
	GENERATOR_FLAG_GENERATE_RELATIONAL_OPERATORS			= GEN_BIT( 8 ),		// generates <, <=, >, >= for every type; equality (==, !=) is unaffected, since it's unconditionally required by the generated tests
	GENERATOR_FLAG_GENERATE_QUATERNIONS						= GEN_BIT( 9 ),		// generate quaternion types/functions (float4/double4 treated as quaternions); also requires float, double, and 4-component types to be enabled, see Gen_BuildTypeInfos in gen_config.c
	GENERATOR_FLAG_GENERATE_NON_SQUARE_MATRICES				= GEN_BIT( 10 ),	// generate non-square matrices (e.g. float2x3, float4x2) in addition to square ones
	GENERATOR_FLAG_GENERATE_SSE								= GEN_BIT( 11 ),	// generate the SSE API (hlml_functions_scalar_sse.h/hlml_functions_vector_sse.h and their #includes in hlml.h) for types that support it, see Gen_TypeSupportsSIMD in gen_shared.c
	GENERATOR_FLAG_GENERATE_RGBA							= GEN_BIT( 12 ),	// generate rgba-named vector members/swizzles alongside xyzw; only meaningful when GENERATOR_FLAG_VECTOR_UNIONS is also set, since rgba members live inside that union - gen_config.c rejects a config that sets this without it
	GENERATOR_FLAG_GENERATE_ASSIGNMENT_OPERATOR				= GEN_BIT( 13 ),	// generate operator= for vectors and matrices; only meaningful when GENERATOR_FLAG_GENERATE_OPERATORS is also set
	GENERATOR_FLAG_SUPPRESS_ANONYMOUS_STRUCT_WARNINGS		= GEN_BIT( 14 ),	// wrap vector types' anonymous struct/union members in a push/pop of Clang/GCC's -Wpedantic and MSVC's C4201, since anonymous structs/unions are a nonstandard extension; only meaningful when GENERATOR_FLAG_VECTOR_UNIONS is also set, since that's the only place vectors use anonymous structs/unions
	GENERATOR_FLAG_BRACES_SAME_LINE							= GEN_BIT( 15 ),	// put opening scope braces (functions, structs, namespace blocks, control-flow) on the same line as the preceding statement instead of on their own line; does not affect aggregate-initializer braces (e.g. HLML_CONSTRUCT( type ) { ... })
	GENERATOR_FLAG_REFERENCE_OPERATOR_ATTACH_TO_VARIABLE	= GEN_BIT( 16 ),	// attach declarator '*'/'&' to the variable/function name (e.g. "float3 *vec", "float3 &vec") instead of the type (e.g. "float3* vec", "float3& vec"); only affects declarators (function parameters, reference return types, constructors, operator=/operator[], swizzle operators) - never expression-level unary '*'/'&' (dereference/address-of)
	GENERATOR_FLAG_GENERATE_HEADER_COMMENT					= GEN_BIT( 17 ),	// prepend the "This file was automatically generated by HLML..." comment (see Gen_AppendGeneratedHeaderComment in gen_shared.c) to every generated file

	GENERATOR_FLAG_ALL
} generatorFlagBits_t;
typedef s32 generatorFlags_t;

typedef struct generatorStrings_t {
	const char *parmPassByStr;
	const char *parmAccessOperatorStr;
	const char *parmReferenceStr;
	const char *parmDereferenceStr;
	const char *refDeclStr;	// '&' declarator (C++ reference syntax) with spacing already applied per GENERATOR_FLAG_REFERENCE_OPERATOR_ATTACH_TO_VARIABLE - always '&', regardless of GENERATOR_FLAG_PARMS_ARE_POINTERS, since these are C++-only constructs (copy constructors, operator=, operator[], swizzle operators) that are never pointer-based
	const char *ptrDeclStr;	// '*' declarator with spacing already applied per GENERATOR_FLAG_REFERENCE_OPERATOR_ATTACH_TO_VARIABLE - always '*', regardless of GENERATOR_FLAG_PARMS_ARE_POINTERS, for the handful of functions (equals/not-equals/all/any) that always take a pointer parameter regardless of language
	const char *mainHeaderName;	// filename of the umbrella header that #includes every generated API file (hlml.h by default) - not derived from flags, just carried here from genConfig_t::mainHeaderName for convenience since strings is already threaded everywhere it's needed
	const char *constantsPrefix;	// prefix applied to the constants generated in hlml_constants.h (HLML_PI, HLML_TAU, HLML_EPSILON, HLML_ROOT_2 by default) and to internal references to them (radians()/degrees()/floateq()) - not derived from flags, just carried here from genConfig_t::constantsPrefix for convenience since strings is already threaded everywhere it's needed
	const char *filePrefix;	// prefix applied to the generated filenames that aren't independently configurable (hlml_types.h, hlml_constants.h, hlml_constants_sse.h, hlml_defines.h, hlml_functions_*.h by default) - not derived from flags, just carried here from genConfig_t::filePrefix for convenience since strings is already threaded everywhere it's needed.  See Gen_GetPrefixedFilename().
} generatorStrings_t;

typedef enum operatorSingleParmType_t {
	OPERATOR_SINGLE_PARM_TYPE_PREFIX = 0,
	OPERATOR_SINGLE_PARM_TYPE_POSTFIX
} operatorSingleParmType_t;

void				Gen_AppendGeneratedHeaderComment( stringBuilder_t *sb, const generatorFlags_t flags );

// returns "<strings->filePrefix><suffix>", e.g. "hlml_functions_vector" for suffix "functions_vector" -
// used to build the configurable filenames of hlml_types.h, hlml_constants.h, hlml_functions_*.h, etc.
const char			*Gen_GetPrefixedFilename( allocatorLinear_t *tempStorage, const generatorStrings_t *strings, const char *suffix );

genType_t			Gen_GetSupportedFloatingPointType( const genType_t type );

bool32				Gen_TypeIsFloatingPoint( const genType_t type );
bool32				Gen_TypeIsInteger( const genType_t type );
bool32				Gen_TypeSupportsSIMD( const genType_t type );
bool32				Gen_ShouldGenerateSSE( const genType_t type, const generatorFlags_t flags );

const char			*Gen_GetTypeString( const genType_t type );
const char			*Gen_GetMemberTypeString( const genType_t type );

u32					Gen_GetTypeBytes( const genType_t type );

bool32				Gen_VectorQualifiesAsQuaternion( const typeInfo_t *typeInfo );
typeInfo_t			Gen_GetQuaternionImaginaryPartType( const typeInfo_t *typeInfo, allocatorLinear_t *tempStorage );

const char			*Gen_GetBuiltinFunction( allocatorLinear_t *tempStorage, const genType_t type, const char *functionName );

const char			*Gen_GetRelationalName( const genOpRelational_t op );
const char			*Gen_GetOperatorRelational( const genOpRelational_t op );

const char			*Gen_GetArithmeticName( const genOpArithmetic_t op );
const char			*Gen_GetOperatorArithmetic( const genOpArithmetic_t op );

const char			*Gen_GetIncrementName( const genOpIncrement_t op );
const char			*Gen_GetOperatorIncrement( const genOpIncrement_t op );

const char			*Gen_GetBitwiseName( const genOpBitwise_t op );
const char			*Gen_GetOperatorBitwise( const genOpBitwise_t op );

u32					Gen_GetComponentIndex( const char component );

bool32				Gen_TypeIsScalar( const typeInfo_t *typeInfo );
bool32				Gen_TypeIsVector( const typeInfo_t *typeInfo );
bool32				Gen_TypeIsMatrix( const typeInfo_t *typeInfo );

typeInfo_t			Gen_GetScalarType( const typeInfo_t *typeInfo );

const char			*Gen_GetFuncName_Floateq( const genType_t type );
const char			*Gen_GetFuncName_Floateq_eps( const genType_t type );

const char			*Gen_GetFuncName_Scalar( allocatorLinear_t *tempStorage, const genType_t type, const generatorFlags_t flags, const char *functionName );
const char			*Gen_GetFuncName_Vector( allocatorLinear_t *tempStorage, const typeInfo_t *typeInfo, const generatorFlags_t flags, const char *functionName );

const char			*Gen_GetFuncName_VectorArithmeticScalar( allocatorLinear_t *tempStorage, const typeInfo_t *typeInfo, const genOpArithmetic_t op );
const char			*Gen_GetFuncName_VectorArithmeticVector( allocatorLinear_t *tempStorage, const typeInfo_t *typeInfo, const genOpArithmetic_t op );

const char			*Gen_GetFuncName_MatrixMul( allocatorLinear_t *tempStorage, const typeInfo_t *lhsType, const typeInfo_t *rhsType, const generatorFlags_t flags );

void				GetMatrixCodeMultiply( allocatorLinear_t *tempStorage, const typeInfo_t *typeInfo, stringBuilder_t *code, const char *accessOperatorStr, const bool32 useConstructor, const generatorFlags_t flags );

const char			*Gen_GetNumericLiteral( allocatorLinear_t *tempStorage, const genType_t type, const float32 x, const u32 decimalPlaces );

// Appends an opening scope brace to 'sb'. If GENERATOR_FLAG_BRACES_SAME_LINE is set, joins it onto the end
// of the line already in 'sb' (which must end in '\n'); otherwise appends it on its own line, indented by
// 'indent' (a string of tabs). Not for aggregate-initializer braces - those aren't a "scope".
void				Gen_AppendOpenBrace( stringBuilder_t *sb, const generatorFlags_t flags, const char *indent );

void				GetMatrixCodeMultiplyVector( const typeInfo_t *matrixType, const typeInfo_t *vectorType, stringBuilder_t *code, const char *accessOperatorStr, const bool32 useConstructor, const generatorFlags_t flags );

stringBuilder_t	*Gen_GetParmList_MatrixMultiply( allocatorLinear_t *tempStorage, const typeInfo_t *lhsType, const typeInfo_t *rhsType, const float32 *valuesLhs, const float32 *valuesRhs );

stringBuilder_t	*Gen_GetConstructor( allocatorLinear_t *tempStorage, const typeInfo_t *typeInfo, const float32 *values, const generatorStrings_t *strings, const generatorFlags_t flags );

void				GenerateComponentWiseFunctions( allocatorLinear_t *tempStorage, const typeInfo_t *typeInfo, const typeInfo_t *memberTypeInfo, stringBuilder_t *code, const generatorStrings_t *strings, const generatorFlags_t flags, const bool32 *scalarTypeEnabled );

void				GenerateComponentWiseOperators( allocatorLinear_t *tempStorage, const typeInfo_t *typeInfo, stringBuilder_t *code, const generatorStrings_t *strings, const generatorFlags_t flags );

//
// SSE
//
const char			*Gen_GetFuncName_Scalar_SSE( allocatorLinear_t *tempStorage, const genType_t type, const generatorFlags_t flags, const char *funcName );
const char			*Gen_GetFuncName_Vector_SSE( allocatorLinear_t *tempStorage, const typeInfo_t *typeInfo, const generatorFlags_t flags, const char *funcName );

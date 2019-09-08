/*
===========================================================================

HLML.

MIT License

Copyright (c) 2019 Dan Moody

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

// THIS FILE WAS AUTOMATICALLY GENERATED BY A TOOL.
// EDITING THIS FILE MAY CAUSE SIDE EFFECTS.
// DO SO AT YOUR OWN RISK.

#pragma once

#include <immintrin.h>

// float2x2
/// \brief changes the sign of the values in register x
#define _NEGATE_PS( x ) _mm_sub_ps( HLML_ZERO_SSE, (x) )

struct sse_input_transpose_float2x2_t
{
	__m128 m[2][2];
};

/// \relates float2x2
/// \brief Stores a transposed matrix of 2 x 2 __m128 registers in the output given the input 2 x 2 register matrix.
inline void transpose_sse( const sse_input_transpose_float2x2_t* in, __m128 out_results[2][2] );

struct sse_input_determinant_float2x2_t
{
	__m128 m[2][2];
};

/// \relates float2x2
/// \brief Stores the determinants of a matrix of 2 x 2 __m128 registers.
inline void determinant_sse( const sse_input_determinant_float2x2_t* in, __m128* out_result );

struct sse_input_inverse_float2x2_t
{
	__m128 m[2][2];
};

/// \relates float2x2
/// \brief Stores an inverted matrix of 2 x 2 __m128 registers.
inline void inverse_sse( const sse_input_inverse_float2x2_t* in, __m128 out_results[2][2] );

struct sse_input_comp_add_float2x2_t
{
	__m128 lhs[2][2];
	__m128 rhs[2][2];
};

/// \relates float2x2
/// \brief Stores a matrix that is the result of the component-wise addition between the lhs and rhs __m128 registers of the input.
inline void comp_add_sse( const sse_input_comp_add_float2x2_t* in, __m128 out_results[2][2] );

struct sse_input_comp_sub_float2x2_t
{
	__m128 lhs[2][2];
	__m128 rhs[2][2];
};

/// \relates float2x2
/// \brief Stores a matrix that is the result of the component-wise subtraction between the lhs and rhs __m128 registers of the input.
inline void comp_sub_sse( const sse_input_comp_sub_float2x2_t* in, __m128 out_results[2][2] );

struct sse_input_comp_mul_float2x2_t
{
	__m128 lhs[2][2];
	__m128 rhs[2][2];
};

/// \relates float2x2
/// \brief Stores a matrix that is the result of the component-wise multiplication between the lhs and rhs __m128 registers of the input.
inline void comp_mul_sse( const sse_input_comp_mul_float2x2_t* in, __m128 out_results[2][2] );

struct sse_input_comp_div_float2x2_t
{
	__m128 lhs[2][2];
	__m128 rhs[2][2];
};

/// \relates float2x2
/// \brief Stores a matrix that is the result of the component-wise division between the lhs and rhs __m128 registers of the input.
inline void comp_div_sse( const sse_input_comp_div_float2x2_t* in, __m128 out_results[2][2] );

struct sse_input_mul_float2x2_t
{
	__m128 lhs[2][2];
	__m128 rhs[2][2];
};

inline void mul_sse( const sse_input_mul_float2x2_t* in, __m128 out_results[2][2] );

struct sse_input_scale_float2x2_t
{
	__m128 diagonal[2];
	__m128 scale[2];
};

/// \relates float2x2
/// \brief Stores an array of float2x2 diagonals that have been scaled by the given vector in the input.
inline void scale_sse( const sse_input_scale_float2x2_t* in, __m128 out_results[2] );


// float2x3
/// \brief changes the sign of the values in register x
#define _NEGATE_PS( x ) _mm_sub_ps( HLML_ZERO_SSE, (x) )

struct sse_input_transpose_float2x3_t
{
	__m128 m[2][3];
};

/// \relates float2x3
/// \brief Stores a transposed matrix of 3 x 2 __m128 registers in the output given the input 2 x 3 register matrix.
inline void transpose_sse( const sse_input_transpose_float2x3_t* in, __m128 out_results[3][2] );

struct sse_input_comp_add_float2x3_t
{
	__m128 lhs[2][3];
	__m128 rhs[2][3];
};

/// \relates float2x3
/// \brief Stores a matrix that is the result of the component-wise addition between the lhs and rhs __m128 registers of the input.
inline void comp_add_sse( const sse_input_comp_add_float2x3_t* in, __m128 out_results[2][3] );

struct sse_input_comp_sub_float2x3_t
{
	__m128 lhs[2][3];
	__m128 rhs[2][3];
};

/// \relates float2x3
/// \brief Stores a matrix that is the result of the component-wise subtraction between the lhs and rhs __m128 registers of the input.
inline void comp_sub_sse( const sse_input_comp_sub_float2x3_t* in, __m128 out_results[2][3] );

struct sse_input_comp_mul_float2x3_t
{
	__m128 lhs[2][3];
	__m128 rhs[2][3];
};

/// \relates float2x3
/// \brief Stores a matrix that is the result of the component-wise multiplication between the lhs and rhs __m128 registers of the input.
inline void comp_mul_sse( const sse_input_comp_mul_float2x3_t* in, __m128 out_results[2][3] );

struct sse_input_comp_div_float2x3_t
{
	__m128 lhs[2][3];
	__m128 rhs[2][3];
};

/// \relates float2x3
/// \brief Stores a matrix that is the result of the component-wise division between the lhs and rhs __m128 registers of the input.
inline void comp_div_sse( const sse_input_comp_div_float2x3_t* in, __m128 out_results[2][3] );

struct sse_input_mul_float2x3_t
{
	__m128 lhs[2][3];
	__m128 rhs[3][2];
};

inline void mul_sse( const sse_input_mul_float2x3_t* in, __m128 out_results[2][2] );

struct sse_input_translate_float2x3_t
{
	__m128 column[2];
	__m128 vec[2];
};

/// \relates float2x3
/// \brief Stores a last matrix column that has been translated by the given __m128 register vector in the input.
inline void translate_sse( const sse_input_translate_float2x3_t* in, __m128 out_results[2] );

struct sse_input_scale_float2x3_t
{
	__m128 diagonal[2];
	__m128 scale[2];
};

/// \relates float2x3
/// \brief Stores an array of float2x3 diagonals that have been scaled by the given vector in the input.
inline void scale_sse( const sse_input_scale_float2x3_t* in, __m128 out_results[2] );


// float2x4
/// \brief changes the sign of the values in register x
#define _NEGATE_PS( x ) _mm_sub_ps( HLML_ZERO_SSE, (x) )

struct sse_input_transpose_float2x4_t
{
	__m128 m[2][4];
};

/// \relates float2x4
/// \brief Stores a transposed matrix of 4 x 2 __m128 registers in the output given the input 2 x 4 register matrix.
inline void transpose_sse( const sse_input_transpose_float2x4_t* in, __m128 out_results[4][2] );

struct sse_input_comp_add_float2x4_t
{
	__m128 lhs[2][4];
	__m128 rhs[2][4];
};

/// \relates float2x4
/// \brief Stores a matrix that is the result of the component-wise addition between the lhs and rhs __m128 registers of the input.
inline void comp_add_sse( const sse_input_comp_add_float2x4_t* in, __m128 out_results[2][4] );

struct sse_input_comp_sub_float2x4_t
{
	__m128 lhs[2][4];
	__m128 rhs[2][4];
};

/// \relates float2x4
/// \brief Stores a matrix that is the result of the component-wise subtraction between the lhs and rhs __m128 registers of the input.
inline void comp_sub_sse( const sse_input_comp_sub_float2x4_t* in, __m128 out_results[2][4] );

struct sse_input_comp_mul_float2x4_t
{
	__m128 lhs[2][4];
	__m128 rhs[2][4];
};

/// \relates float2x4
/// \brief Stores a matrix that is the result of the component-wise multiplication between the lhs and rhs __m128 registers of the input.
inline void comp_mul_sse( const sse_input_comp_mul_float2x4_t* in, __m128 out_results[2][4] );

struct sse_input_comp_div_float2x4_t
{
	__m128 lhs[2][4];
	__m128 rhs[2][4];
};

/// \relates float2x4
/// \brief Stores a matrix that is the result of the component-wise division between the lhs and rhs __m128 registers of the input.
inline void comp_div_sse( const sse_input_comp_div_float2x4_t* in, __m128 out_results[2][4] );

struct sse_input_mul_float2x4_t
{
	__m128 lhs[2][4];
	__m128 rhs[4][2];
};

inline void mul_sse( const sse_input_mul_float2x4_t* in, __m128 out_results[2][2] );

struct sse_input_translate_float2x4_t
{
	__m128 column[3];
	__m128 vec[3];
};

/// \relates float2x4
/// \brief Stores a last matrix column that has been translated by the given __m128 register vector in the input.
inline void translate_sse( const sse_input_translate_float2x4_t* in, __m128 out_results[3] );

struct sse_input_scale_float2x4_t
{
	__m128 diagonal[2];
	__m128 scale[2];
};

/// \relates float2x4
/// \brief Stores an array of float2x4 diagonals that have been scaled by the given vector in the input.
inline void scale_sse( const sse_input_scale_float2x4_t* in, __m128 out_results[2] );


// float3x2
/// \brief changes the sign of the values in register x
#define _NEGATE_PS( x ) _mm_sub_ps( HLML_ZERO_SSE, (x) )

struct sse_input_transpose_float3x2_t
{
	__m128 m[3][2];
};

/// \relates float3x2
/// \brief Stores a transposed matrix of 2 x 3 __m128 registers in the output given the input 3 x 2 register matrix.
inline void transpose_sse( const sse_input_transpose_float3x2_t* in, __m128 out_results[2][3] );

struct sse_input_comp_add_float3x2_t
{
	__m128 lhs[3][2];
	__m128 rhs[3][2];
};

/// \relates float3x2
/// \brief Stores a matrix that is the result of the component-wise addition between the lhs and rhs __m128 registers of the input.
inline void comp_add_sse( const sse_input_comp_add_float3x2_t* in, __m128 out_results[3][2] );

struct sse_input_comp_sub_float3x2_t
{
	__m128 lhs[3][2];
	__m128 rhs[3][2];
};

/// \relates float3x2
/// \brief Stores a matrix that is the result of the component-wise subtraction between the lhs and rhs __m128 registers of the input.
inline void comp_sub_sse( const sse_input_comp_sub_float3x2_t* in, __m128 out_results[3][2] );

struct sse_input_comp_mul_float3x2_t
{
	__m128 lhs[3][2];
	__m128 rhs[3][2];
};

/// \relates float3x2
/// \brief Stores a matrix that is the result of the component-wise multiplication between the lhs and rhs __m128 registers of the input.
inline void comp_mul_sse( const sse_input_comp_mul_float3x2_t* in, __m128 out_results[3][2] );

struct sse_input_comp_div_float3x2_t
{
	__m128 lhs[3][2];
	__m128 rhs[3][2];
};

/// \relates float3x2
/// \brief Stores a matrix that is the result of the component-wise division between the lhs and rhs __m128 registers of the input.
inline void comp_div_sse( const sse_input_comp_div_float3x2_t* in, __m128 out_results[3][2] );

struct sse_input_mul_float3x2_t
{
	__m128 lhs[3][2];
	__m128 rhs[2][3];
};

inline void mul_sse( const sse_input_mul_float3x2_t* in, __m128 out_results[3][3] );

struct sse_input_translate_float3x2_t
{
	__m128 column[1];
	__m128 vec[1];
};

/// \relates float3x2
/// \brief Stores a last matrix column that has been translated by the given __m128 register vector in the input.
inline void translate_sse( const sse_input_translate_float3x2_t* in, __m128 out_results[1] );

struct sse_input_scale_float3x2_t
{
	__m128 diagonal[2];
	__m128 scale[2];
};

/// \relates float3x2
/// \brief Stores an array of float3x2 diagonals that have been scaled by the given vector in the input.
inline void scale_sse( const sse_input_scale_float3x2_t* in, __m128 out_results[2] );


// float3x3
/// \brief changes the sign of the values in register x
#define _NEGATE_PS( x ) _mm_sub_ps( HLML_ZERO_SSE, (x) )

struct sse_input_transpose_float3x3_t
{
	__m128 m[3][3];
};

/// \relates float3x3
/// \brief Stores a transposed matrix of 3 x 3 __m128 registers in the output given the input 3 x 3 register matrix.
inline void transpose_sse( const sse_input_transpose_float3x3_t* in, __m128 out_results[3][3] );

struct sse_input_determinant_float3x3_t
{
	__m128 m[3][3];
};

/// \relates float3x3
/// \brief Stores the determinants of a matrix of 3 x 3 __m128 registers.
inline void determinant_sse( const sse_input_determinant_float3x3_t* in, __m128* out_result );

struct sse_input_inverse_float3x3_t
{
	__m128 m[3][3];
};

/// \relates float3x3
/// \brief Stores an inverted matrix of 3 x 3 __m128 registers.
inline void inverse_sse( const sse_input_inverse_float3x3_t* in, __m128 out_results[3][3] );

struct sse_input_comp_add_float3x3_t
{
	__m128 lhs[3][3];
	__m128 rhs[3][3];
};

/// \relates float3x3
/// \brief Stores a matrix that is the result of the component-wise addition between the lhs and rhs __m128 registers of the input.
inline void comp_add_sse( const sse_input_comp_add_float3x3_t* in, __m128 out_results[3][3] );

struct sse_input_comp_sub_float3x3_t
{
	__m128 lhs[3][3];
	__m128 rhs[3][3];
};

/// \relates float3x3
/// \brief Stores a matrix that is the result of the component-wise subtraction between the lhs and rhs __m128 registers of the input.
inline void comp_sub_sse( const sse_input_comp_sub_float3x3_t* in, __m128 out_results[3][3] );

struct sse_input_comp_mul_float3x3_t
{
	__m128 lhs[3][3];
	__m128 rhs[3][3];
};

/// \relates float3x3
/// \brief Stores a matrix that is the result of the component-wise multiplication between the lhs and rhs __m128 registers of the input.
inline void comp_mul_sse( const sse_input_comp_mul_float3x3_t* in, __m128 out_results[3][3] );

struct sse_input_comp_div_float3x3_t
{
	__m128 lhs[3][3];
	__m128 rhs[3][3];
};

/// \relates float3x3
/// \brief Stores a matrix that is the result of the component-wise division between the lhs and rhs __m128 registers of the input.
inline void comp_div_sse( const sse_input_comp_div_float3x3_t* in, __m128 out_results[3][3] );

struct sse_input_mul_float3x3_t
{
	__m128 lhs[3][3];
	__m128 rhs[3][3];
};

inline void mul_sse( const sse_input_mul_float3x3_t* in, __m128 out_results[3][3] );

struct sse_input_translate_float3x3_t
{
	__m128 column[2];
	__m128 vec[2];
};

/// \relates float3x3
/// \brief Stores a last matrix column that has been translated by the given __m128 register vector in the input.
inline void translate_sse( const sse_input_translate_float3x3_t* in, __m128 out_results[2] );

struct sse_input_scale_float3x3_t
{
	__m128 diagonal[3];
	__m128 scale[3];
};

/// \relates float3x3
/// \brief Stores an array of float3x3 diagonals that have been scaled by the given vector in the input.
inline void scale_sse( const sse_input_scale_float3x3_t* in, __m128 out_results[3] );


// float3x4
/// \brief changes the sign of the values in register x
#define _NEGATE_PS( x ) _mm_sub_ps( HLML_ZERO_SSE, (x) )

struct sse_input_transpose_float3x4_t
{
	__m128 m[3][4];
};

/// \relates float3x4
/// \brief Stores a transposed matrix of 4 x 3 __m128 registers in the output given the input 3 x 4 register matrix.
inline void transpose_sse( const sse_input_transpose_float3x4_t* in, __m128 out_results[4][3] );

struct sse_input_comp_add_float3x4_t
{
	__m128 lhs[3][4];
	__m128 rhs[3][4];
};

/// \relates float3x4
/// \brief Stores a matrix that is the result of the component-wise addition between the lhs and rhs __m128 registers of the input.
inline void comp_add_sse( const sse_input_comp_add_float3x4_t* in, __m128 out_results[3][4] );

struct sse_input_comp_sub_float3x4_t
{
	__m128 lhs[3][4];
	__m128 rhs[3][4];
};

/// \relates float3x4
/// \brief Stores a matrix that is the result of the component-wise subtraction between the lhs and rhs __m128 registers of the input.
inline void comp_sub_sse( const sse_input_comp_sub_float3x4_t* in, __m128 out_results[3][4] );

struct sse_input_comp_mul_float3x4_t
{
	__m128 lhs[3][4];
	__m128 rhs[3][4];
};

/// \relates float3x4
/// \brief Stores a matrix that is the result of the component-wise multiplication between the lhs and rhs __m128 registers of the input.
inline void comp_mul_sse( const sse_input_comp_mul_float3x4_t* in, __m128 out_results[3][4] );

struct sse_input_comp_div_float3x4_t
{
	__m128 lhs[3][4];
	__m128 rhs[3][4];
};

/// \relates float3x4
/// \brief Stores a matrix that is the result of the component-wise division between the lhs and rhs __m128 registers of the input.
inline void comp_div_sse( const sse_input_comp_div_float3x4_t* in, __m128 out_results[3][4] );

struct sse_input_mul_float3x4_t
{
	__m128 lhs[3][4];
	__m128 rhs[4][3];
};

inline void mul_sse( const sse_input_mul_float3x4_t* in, __m128 out_results[3][3] );

struct sse_input_translate_float3x4_t
{
	__m128 column[3];
	__m128 vec[3];
};

/// \relates float3x4
/// \brief Stores a last matrix column that has been translated by the given __m128 register vector in the input.
inline void translate_sse( const sse_input_translate_float3x4_t* in, __m128 out_results[3] );

struct sse_input_scale_float3x4_t
{
	__m128 diagonal[3];
	__m128 scale[3];
};

/// \relates float3x4
/// \brief Stores an array of float3x4 diagonals that have been scaled by the given vector in the input.
inline void scale_sse( const sse_input_scale_float3x4_t* in, __m128 out_results[3] );


// float4x2
/// \brief changes the sign of the values in register x
#define _NEGATE_PS( x ) _mm_sub_ps( HLML_ZERO_SSE, (x) )

struct sse_input_transpose_float4x2_t
{
	__m128 m[4][2];
};

/// \relates float4x2
/// \brief Stores a transposed matrix of 2 x 4 __m128 registers in the output given the input 4 x 2 register matrix.
inline void transpose_sse( const sse_input_transpose_float4x2_t* in, __m128 out_results[2][4] );

struct sse_input_comp_add_float4x2_t
{
	__m128 lhs[4][2];
	__m128 rhs[4][2];
};

/// \relates float4x2
/// \brief Stores a matrix that is the result of the component-wise addition between the lhs and rhs __m128 registers of the input.
inline void comp_add_sse( const sse_input_comp_add_float4x2_t* in, __m128 out_results[4][2] );

struct sse_input_comp_sub_float4x2_t
{
	__m128 lhs[4][2];
	__m128 rhs[4][2];
};

/// \relates float4x2
/// \brief Stores a matrix that is the result of the component-wise subtraction between the lhs and rhs __m128 registers of the input.
inline void comp_sub_sse( const sse_input_comp_sub_float4x2_t* in, __m128 out_results[4][2] );

struct sse_input_comp_mul_float4x2_t
{
	__m128 lhs[4][2];
	__m128 rhs[4][2];
};

/// \relates float4x2
/// \brief Stores a matrix that is the result of the component-wise multiplication between the lhs and rhs __m128 registers of the input.
inline void comp_mul_sse( const sse_input_comp_mul_float4x2_t* in, __m128 out_results[4][2] );

struct sse_input_comp_div_float4x2_t
{
	__m128 lhs[4][2];
	__m128 rhs[4][2];
};

/// \relates float4x2
/// \brief Stores a matrix that is the result of the component-wise division between the lhs and rhs __m128 registers of the input.
inline void comp_div_sse( const sse_input_comp_div_float4x2_t* in, __m128 out_results[4][2] );

struct sse_input_mul_float4x2_t
{
	__m128 lhs[4][2];
	__m128 rhs[2][4];
};

inline void mul_sse( const sse_input_mul_float4x2_t* in, __m128 out_results[4][4] );

struct sse_input_translate_float4x2_t
{
	__m128 column[1];
	__m128 vec[1];
};

/// \relates float4x2
/// \brief Stores a last matrix column that has been translated by the given __m128 register vector in the input.
inline void translate_sse( const sse_input_translate_float4x2_t* in, __m128 out_results[1] );

struct sse_input_scale_float4x2_t
{
	__m128 diagonal[2];
	__m128 scale[2];
};

/// \relates float4x2
/// \brief Stores an array of float4x2 diagonals that have been scaled by the given vector in the input.
inline void scale_sse( const sse_input_scale_float4x2_t* in, __m128 out_results[2] );


// float4x3
/// \brief changes the sign of the values in register x
#define _NEGATE_PS( x ) _mm_sub_ps( HLML_ZERO_SSE, (x) )

struct sse_input_transpose_float4x3_t
{
	__m128 m[4][3];
};

/// \relates float4x3
/// \brief Stores a transposed matrix of 3 x 4 __m128 registers in the output given the input 4 x 3 register matrix.
inline void transpose_sse( const sse_input_transpose_float4x3_t* in, __m128 out_results[3][4] );

struct sse_input_comp_add_float4x3_t
{
	__m128 lhs[4][3];
	__m128 rhs[4][3];
};

/// \relates float4x3
/// \brief Stores a matrix that is the result of the component-wise addition between the lhs and rhs __m128 registers of the input.
inline void comp_add_sse( const sse_input_comp_add_float4x3_t* in, __m128 out_results[4][3] );

struct sse_input_comp_sub_float4x3_t
{
	__m128 lhs[4][3];
	__m128 rhs[4][3];
};

/// \relates float4x3
/// \brief Stores a matrix that is the result of the component-wise subtraction between the lhs and rhs __m128 registers of the input.
inline void comp_sub_sse( const sse_input_comp_sub_float4x3_t* in, __m128 out_results[4][3] );

struct sse_input_comp_mul_float4x3_t
{
	__m128 lhs[4][3];
	__m128 rhs[4][3];
};

/// \relates float4x3
/// \brief Stores a matrix that is the result of the component-wise multiplication between the lhs and rhs __m128 registers of the input.
inline void comp_mul_sse( const sse_input_comp_mul_float4x3_t* in, __m128 out_results[4][3] );

struct sse_input_comp_div_float4x3_t
{
	__m128 lhs[4][3];
	__m128 rhs[4][3];
};

/// \relates float4x3
/// \brief Stores a matrix that is the result of the component-wise division between the lhs and rhs __m128 registers of the input.
inline void comp_div_sse( const sse_input_comp_div_float4x3_t* in, __m128 out_results[4][3] );

struct sse_input_mul_float4x3_t
{
	__m128 lhs[4][3];
	__m128 rhs[3][4];
};

inline void mul_sse( const sse_input_mul_float4x3_t* in, __m128 out_results[4][4] );

struct sse_input_translate_float4x3_t
{
	__m128 column[2];
	__m128 vec[2];
};

/// \relates float4x3
/// \brief Stores a last matrix column that has been translated by the given __m128 register vector in the input.
inline void translate_sse( const sse_input_translate_float4x3_t* in, __m128 out_results[2] );

struct sse_input_scale_float4x3_t
{
	__m128 diagonal[3];
	__m128 scale[3];
};

/// \relates float4x3
/// \brief Stores an array of float4x3 diagonals that have been scaled by the given vector in the input.
inline void scale_sse( const sse_input_scale_float4x3_t* in, __m128 out_results[3] );


// float4x4
/// \brief changes the sign of the values in register x
#define _NEGATE_PS( x ) _mm_sub_ps( HLML_ZERO_SSE, (x) )

struct sse_input_transpose_float4x4_t
{
	__m128 m[4][4];
};

/// \relates float4x4
/// \brief Stores a transposed matrix of 4 x 4 __m128 registers in the output given the input 4 x 4 register matrix.
inline void transpose_sse( const sse_input_transpose_float4x4_t* in, __m128 out_results[4][4] );

struct sse_input_determinant_float4x4_t
{
	__m128 m[4][4];
};

/// \relates float4x4
/// \brief Stores the determinants of a matrix of 4 x 4 __m128 registers.
inline void determinant_sse( const sse_input_determinant_float4x4_t* in, __m128* out_result );

struct sse_input_inverse_float4x4_t
{
	__m128 m[4][4];
};

/// \relates float4x4
/// \brief Stores an inverted matrix of 4 x 4 __m128 registers.
inline void inverse_sse( const sse_input_inverse_float4x4_t* in, __m128 out_results[4][4] );

struct sse_input_comp_add_float4x4_t
{
	__m128 lhs[4][4];
	__m128 rhs[4][4];
};

/// \relates float4x4
/// \brief Stores a matrix that is the result of the component-wise addition between the lhs and rhs __m128 registers of the input.
inline void comp_add_sse( const sse_input_comp_add_float4x4_t* in, __m128 out_results[4][4] );

struct sse_input_comp_sub_float4x4_t
{
	__m128 lhs[4][4];
	__m128 rhs[4][4];
};

/// \relates float4x4
/// \brief Stores a matrix that is the result of the component-wise subtraction between the lhs and rhs __m128 registers of the input.
inline void comp_sub_sse( const sse_input_comp_sub_float4x4_t* in, __m128 out_results[4][4] );

struct sse_input_comp_mul_float4x4_t
{
	__m128 lhs[4][4];
	__m128 rhs[4][4];
};

/// \relates float4x4
/// \brief Stores a matrix that is the result of the component-wise multiplication between the lhs and rhs __m128 registers of the input.
inline void comp_mul_sse( const sse_input_comp_mul_float4x4_t* in, __m128 out_results[4][4] );

struct sse_input_comp_div_float4x4_t
{
	__m128 lhs[4][4];
	__m128 rhs[4][4];
};

/// \relates float4x4
/// \brief Stores a matrix that is the result of the component-wise division between the lhs and rhs __m128 registers of the input.
inline void comp_div_sse( const sse_input_comp_div_float4x4_t* in, __m128 out_results[4][4] );

struct sse_input_mul_float4x4_t
{
	__m128 lhs[4][4];
	__m128 rhs[4][4];
};

inline void mul_sse( const sse_input_mul_float4x4_t* in, __m128 out_results[4][4] );

struct sse_input_translate_float4x4_t
{
	__m128 column[3];
	__m128 vec[3];
};

/// \relates float4x4
/// \brief Stores a last matrix column that has been translated by the given __m128 register vector in the input.
inline void translate_sse( const sse_input_translate_float4x4_t* in, __m128 out_results[3] );

struct sse_input_scale_float4x4_t
{
	__m128 diagonal[4];
	__m128 scale[4];
};

/// \relates float4x4
/// \brief Stores an array of float4x4 diagonals that have been scaled by the given vector in the input.
inline void scale_sse( const sse_input_scale_float4x4_t* in, __m128 out_results[4] );


#include "hlml_functions_matrix_sse.inl"

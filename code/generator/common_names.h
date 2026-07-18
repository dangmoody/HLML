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

/*
The names of all HLML constants, functions, etc.

All generators should use these defines for the sake of uniformity.

Some generators will need to modify names because of language-specific reasons
(E.G: C doesn't support function-overloading, so we prefix each function).

Generators for some languages also might not use some of these for same/similar reasons
(E.G: HLML generated C++ doesn't have "equals" and "not_equals" because we have the operators for that instead).
*/

#define GEN_CONSTANT_NAME_PI						"HLML_PI"
#define GEN_CONSTANT_NAME_EPSILON					"HLML_EPSILON"

#define GEN_FUNCTION_NAME_RADIANS					"radians"
#define GEN_FUNCTION_NAME_DEGREES					"degrees"
#define GEN_FUNCTION_NAME_SIGN						"sign"
#define GEN_FUNCTION_NAME_MIN						"min"
#define GEN_FUNCTION_NAME_MAX						"max"
#define GEN_FUNCTION_NAME_CLAMP						"clamp"
#define GEN_FUNCTION_NAME_SATURATE					"saturate"
#define GEN_FUNCTION_NAME_LERP						"lerp"
#define GEN_FUNCTION_NAME_SLERP						"slerp"
#define GEN_FUNCTION_NAME_STEP						"step"
#define GEN_FUNCTION_NAME_SMOOTHSTEP				"smoothstep"
#define GEN_FUNCTION_NAME_SMOOTHERSTEP				"smootherstep"

#define GEN_FUNCTION_NAME_ALL						"all"
#define GEN_FUNCTION_NAME_ANY						"any"
#define GEN_FUNCTION_NAME_EQUALS					"equals"
#define GEN_FUNCTION_NAME_NOT_EQUALS				"not_equals"
#define GEN_FUNCTION_NAME_LESS_THAN					"less_than"
#define GEN_FUNCTION_NAME_LESS_THAN_EQUAL			"less_than_equal"
#define GEN_FUNCTION_NAME_GREATER_THAN				"greater_than"
#define GEN_FUNCTION_NAME_GREATER_THAN_EQUAL		"greater_than_equal"
#define GEN_FUNCTION_NAME_NEGATE					"negate"

#define GEN_FUNCTION_NAME_LENGTHSQ					"lengthsq"
#define GEN_FUNCTION_NAME_LENGTH					"length"
#define GEN_FUNCTION_NAME_NORMALIZE					"normalize"
#define GEN_FUNCTION_NAME_NORMALIZED				"normalized"
#define GEN_FUNCTION_NAME_DOT						"dot"
#define GEN_FUNCTION_NAME_CROSS						"cross"
#define GEN_FUNCTION_NAME_ANGLE						"angle"
#define GEN_FUNCTION_NAME_DISTANCESQ				"distancesq"
#define GEN_FUNCTION_NAME_DISTANCE					"distance"
#define GEN_FUNCTION_NAME_PACK						"pack"
#define GEN_FUNCTION_NAME_UNPACK					"unpack"

#define GEN_FUNCTION_NAME_QUAT_NORMALIZE			"quat_normalize"
#define GEN_FUNCTION_NAME_QUAT_CONJUGATE			"quat_conjugate"
#define GEN_FUNCTION_NAME_QUAT_INVERSE				"quat_inverse"
#define GEN_FUNCTION_NAME_QUAT_LENGTH				"quat_length"
#define GEN_FUNCTION_NAME_QUAT_ROTATE				"quat_rotate"
#define GEN_FUNCTION_NAME_QUAT_LERP					"quat_lerp"
#define GEN_FUNCTION_NAME_QUAT_SLERP				"quat_slerp"
#define GEN_FUNCTION_NAME_QUAT_TO_ROTATION_MATRIX	"quat_to_rotation_matrix"
#define GEN_FUNCTION_NAME_QUAT_MUL					"quat_mul"

#define GEN_FUNCTION_NAME_IDENTITY					"identity"
#define GEN_FUNCTION_NAME_TRANSPOSE					"transpose"
#define GEN_FUNCTION_NAME_DETERMINANT				"determinant"
#define GEN_FUNCTION_NAME_INVERSE					"inverse"
#define GEN_FUNCTION_NAME_MUL						"mul"
#define GEN_FUNCTION_NAME_TRANSLATE					"translate"
#define GEN_FUNCTION_NAME_ROTATE					"rotate"
#define GEN_FUNCTION_NAME_SCALE						"scale"
#define GEN_FUNCTION_NAME_ORTHO_LH_ZO				"ortho_lh_zo"
#define GEN_FUNCTION_NAME_ORTHO_LH_NO				"ortho_lh_no"
#define GEN_FUNCTION_NAME_ORTHO_RH_ZO				"ortho_rh_zo"
#define GEN_FUNCTION_NAME_ORTHO_RH_NO				"ortho_rh_no"
#define GEN_FUNCTION_NAME_PERSPECTIVE_LH_ZO			"perspective_lh_zo"
#define GEN_FUNCTION_NAME_PERSPECTIVE_LH_NO			"perspective_lh_no"
#define GEN_FUNCTION_NAME_PERSPECTIVE_RH_ZO			"perspective_rh_zo"
#define GEN_FUNCTION_NAME_PERSPECTIVE_RH_NO			"perspective_rh_no"
#define GEN_FUNCTION_NAME_LOOK_AT_LH				"look_at_lh"
#define GEN_FUNCTION_NAME_LOOK_AT_RH				"look_at_rh"

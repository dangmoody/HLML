/*
===========================================================================

hlml.
Copyright (c) Dan Moody 2018 - Present.

This file is part of hlml.

hlml is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

hlml is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with hlml.  If not, see <http://www.gnu.org/licenses/>.

===========================================================================
*/
#pragma once

// TODO(DM): remove include in this header
#include <math.h>

#define HLML_PI			3.141592653589793238462643383279502884197169399375105820974f
#define HLML_TAU		6.283185307179586476925286766559005768394338798750211641949f

#define HLML_EPSILON	1e-5

inline bool floateq( const float lhs, const float rhs ) {
	return fabs( lhs - rhs ) < HLML_EPSILON;
}

inline float degrees( const float radians ) {
	return radians * 180.0f / HLML_PI;
}

inline float radians( const float degrees ) {
	return degrees * HLML_PI / 180.0f;
}
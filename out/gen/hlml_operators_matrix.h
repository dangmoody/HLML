/*
===========================================================================

hlml.
Copyright (c) Dan Moody 2019 - Present.

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

// GENERATED FILE.  DO NOT EDIT.

#pragma once

#include "int2x2.h"
#include "int2x3.h"
#include "int2x4.h"
#include "int3x2.h"
#include "int3x3.h"
#include "int3x4.h"
#include "int4x2.h"
#include "int4x3.h"
#include "int4x4.h"
#include "uint2x2.h"
#include "uint2x3.h"
#include "uint2x4.h"
#include "uint3x2.h"
#include "uint3x3.h"
#include "uint3x4.h"
#include "uint4x2.h"
#include "uint4x3.h"
#include "uint4x4.h"
#include "float2x2.h"
#include "float2x3.h"
#include "float2x4.h"
#include "float3x2.h"
#include "float3x3.h"
#include "float3x4.h"
#include "float4x2.h"
#include "float4x3.h"
#include "float4x4.h"
#include "double2x2.h"
#include "double2x3.h"
#include "double2x4.h"
#include "double3x2.h"
#include "double3x3.h"
#include "double3x4.h"
#include "double4x2.h"
#include "double4x3.h"
#include "double4x4.h"

// int2x2
/// \relates int2x2
/// \brief Returns a copy of the matrix that has been component-wise added by the given scalar value.
inline int2x2 operator+( const int2x2& lhs, const int32_t rhs );

/// \relates int2x2
/// \brief Adds each component of the matrix by the given scalar value.
inline int2x2 operator+=( int2x2& lhs, const int32_t rhs );

/// \relates int2x2
/// \brief Returns a copy of the matrix that has been component-wise added by the other matrix.
inline int2x2 operator+( const int2x2& lhs, const int2x2& rhs );

/// \relates int2x2
/// \brief Returns a copy of the matrix that has been component-wise subtracted by the given scalar value.
inline int2x2 operator-( const int2x2& lhs, const int32_t rhs );

/// \relates int2x2
/// \brief Subtracts each component of the matrix by the given scalar value.
inline int2x2 operator-=( int2x2& lhs, const int32_t rhs );

/// \relates int2x2
/// \brief Returns a copy of the matrix that has been component-wise subtracted by the other matrix.
inline int2x2 operator-( const int2x2& lhs, const int2x2& rhs );

/// \relates int2x2
/// \brief Returns a copy of the matrix that has been component-wise multiplied by the given scalar value.
inline int2x2 operator*( const int2x2& lhs, const int32_t rhs );

/// \relates int2x2
/// \brief Multiplies each component of the matrix by the given scalar value.
inline int2x2 operator*=( int2x2& lhs, const int32_t rhs );

/// \relates int2x2
/// \brief Returns a copy of the matrix where each row of the left-hand matrix has been dot-producted by the corresponding column of the right-hand matrix.
inline int2x2 operator*( const int2x2& lhs, const int2x2& rhs );

/// \relates int2x2
/// \brief Returns a copy of the matrix that has been component-wise divided by the given scalar value.
inline int2x2 operator/( const int2x2& lhs, const int32_t rhs );

/// \relates int2x2
/// \brief Divides each component of the matrix by the given scalar value.
inline int2x2 operator/=( int2x2& lhs, const int32_t rhs );

/// \relates int2x2
/// \brief Returns a copy of the matrix that has been component-wise divided by the other matrix.
inline int2x2 operator/( const int2x2& lhs, const int2x2& rhs );

/// \relates int2x2
/// \brief Returns a bool2x2 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool2x2 operator<( const int2x2& lhs, const int2x2& rhs );

/// \relates int2x2
/// \brief Returns a bool2x2 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool2x2 operator<=( const int2x2& lhs, const int2x2& rhs );

/// \relates int2x2
/// \brief Returns a bool2x2 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool2x2 operator>( const int2x2& lhs, const int2x2& rhs );

/// \relates int2x2
/// \brief Returns a bool2x2 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool2x2 operator>=( const int2x2& lhs, const int2x2& rhs );


// int2x3
/// \relates int2x3
/// \brief Returns a copy of the matrix that has been component-wise added by the given scalar value.
inline int2x3 operator+( const int2x3& lhs, const int32_t rhs );

/// \relates int2x3
/// \brief Adds each component of the matrix by the given scalar value.
inline int2x3 operator+=( int2x3& lhs, const int32_t rhs );

/// \relates int2x3
/// \brief Returns a copy of the matrix that has been component-wise added by the other matrix.
inline int2x3 operator+( const int2x3& lhs, const int2x3& rhs );

/// \relates int2x3
/// \brief Returns a copy of the matrix that has been component-wise subtracted by the given scalar value.
inline int2x3 operator-( const int2x3& lhs, const int32_t rhs );

/// \relates int2x3
/// \brief Subtracts each component of the matrix by the given scalar value.
inline int2x3 operator-=( int2x3& lhs, const int32_t rhs );

/// \relates int2x3
/// \brief Returns a copy of the matrix that has been component-wise subtracted by the other matrix.
inline int2x3 operator-( const int2x3& lhs, const int2x3& rhs );

/// \relates int2x3
/// \brief Returns a copy of the matrix that has been component-wise multiplied by the given scalar value.
inline int2x3 operator*( const int2x3& lhs, const int32_t rhs );

/// \relates int2x3
/// \brief Multiplies each component of the matrix by the given scalar value.
inline int2x3 operator*=( int2x3& lhs, const int32_t rhs );

/// \relates int2x3
/// \brief Returns a copy of the matrix where each row of the left-hand matrix has been dot-producted by the corresponding column of the right-hand matrix.
inline int2x2 operator*( const int2x3& lhs, const int3x2& rhs );

/// \relates int2x3
/// \brief Returns a copy of the matrix that has been component-wise divided by the given scalar value.
inline int2x3 operator/( const int2x3& lhs, const int32_t rhs );

/// \relates int2x3
/// \brief Divides each component of the matrix by the given scalar value.
inline int2x3 operator/=( int2x3& lhs, const int32_t rhs );

/// \relates int2x3
/// \brief Returns a copy of the matrix that has been component-wise divided by the other matrix.
inline int2x3 operator/( const int2x3& lhs, const int2x3& rhs );

/// \relates int2x3
/// \brief Returns a bool2x3 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool2x3 operator<( const int2x3& lhs, const int2x3& rhs );

/// \relates int2x3
/// \brief Returns a bool2x3 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool2x3 operator<=( const int2x3& lhs, const int2x3& rhs );

/// \relates int2x3
/// \brief Returns a bool2x3 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool2x3 operator>( const int2x3& lhs, const int2x3& rhs );

/// \relates int2x3
/// \brief Returns a bool2x3 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool2x3 operator>=( const int2x3& lhs, const int2x3& rhs );


// int2x4
/// \relates int2x4
/// \brief Returns a copy of the matrix that has been component-wise added by the given scalar value.
inline int2x4 operator+( const int2x4& lhs, const int32_t rhs );

/// \relates int2x4
/// \brief Adds each component of the matrix by the given scalar value.
inline int2x4 operator+=( int2x4& lhs, const int32_t rhs );

/// \relates int2x4
/// \brief Returns a copy of the matrix that has been component-wise added by the other matrix.
inline int2x4 operator+( const int2x4& lhs, const int2x4& rhs );

/// \relates int2x4
/// \brief Returns a copy of the matrix that has been component-wise subtracted by the given scalar value.
inline int2x4 operator-( const int2x4& lhs, const int32_t rhs );

/// \relates int2x4
/// \brief Subtracts each component of the matrix by the given scalar value.
inline int2x4 operator-=( int2x4& lhs, const int32_t rhs );

/// \relates int2x4
/// \brief Returns a copy of the matrix that has been component-wise subtracted by the other matrix.
inline int2x4 operator-( const int2x4& lhs, const int2x4& rhs );

/// \relates int2x4
/// \brief Returns a copy of the matrix that has been component-wise multiplied by the given scalar value.
inline int2x4 operator*( const int2x4& lhs, const int32_t rhs );

/// \relates int2x4
/// \brief Multiplies each component of the matrix by the given scalar value.
inline int2x4 operator*=( int2x4& lhs, const int32_t rhs );

/// \relates int2x4
/// \brief Returns a copy of the matrix where each row of the left-hand matrix has been dot-producted by the corresponding column of the right-hand matrix.
inline int2x2 operator*( const int2x4& lhs, const int4x2& rhs );

/// \relates int2x4
/// \brief Returns a copy of the matrix that has been component-wise divided by the given scalar value.
inline int2x4 operator/( const int2x4& lhs, const int32_t rhs );

/// \relates int2x4
/// \brief Divides each component of the matrix by the given scalar value.
inline int2x4 operator/=( int2x4& lhs, const int32_t rhs );

/// \relates int2x4
/// \brief Returns a copy of the matrix that has been component-wise divided by the other matrix.
inline int2x4 operator/( const int2x4& lhs, const int2x4& rhs );

/// \relates int2x4
/// \brief Returns a bool2x4 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool2x4 operator<( const int2x4& lhs, const int2x4& rhs );

/// \relates int2x4
/// \brief Returns a bool2x4 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool2x4 operator<=( const int2x4& lhs, const int2x4& rhs );

/// \relates int2x4
/// \brief Returns a bool2x4 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool2x4 operator>( const int2x4& lhs, const int2x4& rhs );

/// \relates int2x4
/// \brief Returns a bool2x4 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool2x4 operator>=( const int2x4& lhs, const int2x4& rhs );


// int3x2
/// \relates int3x2
/// \brief Returns a copy of the matrix that has been component-wise added by the given scalar value.
inline int3x2 operator+( const int3x2& lhs, const int32_t rhs );

/// \relates int3x2
/// \brief Adds each component of the matrix by the given scalar value.
inline int3x2 operator+=( int3x2& lhs, const int32_t rhs );

/// \relates int3x2
/// \brief Returns a copy of the matrix that has been component-wise added by the other matrix.
inline int3x2 operator+( const int3x2& lhs, const int3x2& rhs );

/// \relates int3x2
/// \brief Returns a copy of the matrix that has been component-wise subtracted by the given scalar value.
inline int3x2 operator-( const int3x2& lhs, const int32_t rhs );

/// \relates int3x2
/// \brief Subtracts each component of the matrix by the given scalar value.
inline int3x2 operator-=( int3x2& lhs, const int32_t rhs );

/// \relates int3x2
/// \brief Returns a copy of the matrix that has been component-wise subtracted by the other matrix.
inline int3x2 operator-( const int3x2& lhs, const int3x2& rhs );

/// \relates int3x2
/// \brief Returns a copy of the matrix that has been component-wise multiplied by the given scalar value.
inline int3x2 operator*( const int3x2& lhs, const int32_t rhs );

/// \relates int3x2
/// \brief Multiplies each component of the matrix by the given scalar value.
inline int3x2 operator*=( int3x2& lhs, const int32_t rhs );

/// \relates int3x2
/// \brief Returns a copy of the matrix where each row of the left-hand matrix has been dot-producted by the corresponding column of the right-hand matrix.
inline int3x3 operator*( const int3x2& lhs, const int2x3& rhs );

/// \relates int3x2
/// \brief Returns a copy of the matrix that has been component-wise divided by the given scalar value.
inline int3x2 operator/( const int3x2& lhs, const int32_t rhs );

/// \relates int3x2
/// \brief Divides each component of the matrix by the given scalar value.
inline int3x2 operator/=( int3x2& lhs, const int32_t rhs );

/// \relates int3x2
/// \brief Returns a copy of the matrix that has been component-wise divided by the other matrix.
inline int3x2 operator/( const int3x2& lhs, const int3x2& rhs );

/// \relates int3x2
/// \brief Returns a bool3x2 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool3x2 operator<( const int3x2& lhs, const int3x2& rhs );

/// \relates int3x2
/// \brief Returns a bool3x2 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool3x2 operator<=( const int3x2& lhs, const int3x2& rhs );

/// \relates int3x2
/// \brief Returns a bool3x2 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool3x2 operator>( const int3x2& lhs, const int3x2& rhs );

/// \relates int3x2
/// \brief Returns a bool3x2 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool3x2 operator>=( const int3x2& lhs, const int3x2& rhs );


// int3x3
/// \relates int3x3
/// \brief Returns a copy of the matrix that has been component-wise added by the given scalar value.
inline int3x3 operator+( const int3x3& lhs, const int32_t rhs );

/// \relates int3x3
/// \brief Adds each component of the matrix by the given scalar value.
inline int3x3 operator+=( int3x3& lhs, const int32_t rhs );

/// \relates int3x3
/// \brief Returns a copy of the matrix that has been component-wise added by the other matrix.
inline int3x3 operator+( const int3x3& lhs, const int3x3& rhs );

/// \relates int3x3
/// \brief Returns a copy of the matrix that has been component-wise subtracted by the given scalar value.
inline int3x3 operator-( const int3x3& lhs, const int32_t rhs );

/// \relates int3x3
/// \brief Subtracts each component of the matrix by the given scalar value.
inline int3x3 operator-=( int3x3& lhs, const int32_t rhs );

/// \relates int3x3
/// \brief Returns a copy of the matrix that has been component-wise subtracted by the other matrix.
inline int3x3 operator-( const int3x3& lhs, const int3x3& rhs );

/// \relates int3x3
/// \brief Returns a copy of the matrix that has been component-wise multiplied by the given scalar value.
inline int3x3 operator*( const int3x3& lhs, const int32_t rhs );

/// \relates int3x3
/// \brief Multiplies each component of the matrix by the given scalar value.
inline int3x3 operator*=( int3x3& lhs, const int32_t rhs );

/// \relates int3x3
/// \brief Returns a copy of the matrix where each row of the left-hand matrix has been dot-producted by the corresponding column of the right-hand matrix.
inline int3x3 operator*( const int3x3& lhs, const int3x3& rhs );

/// \relates int3x3
/// \brief Returns a copy of the matrix that has been component-wise divided by the given scalar value.
inline int3x3 operator/( const int3x3& lhs, const int32_t rhs );

/// \relates int3x3
/// \brief Divides each component of the matrix by the given scalar value.
inline int3x3 operator/=( int3x3& lhs, const int32_t rhs );

/// \relates int3x3
/// \brief Returns a copy of the matrix that has been component-wise divided by the other matrix.
inline int3x3 operator/( const int3x3& lhs, const int3x3& rhs );

/// \relates int3x3
/// \brief Returns a bool3x3 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool3x3 operator<( const int3x3& lhs, const int3x3& rhs );

/// \relates int3x3
/// \brief Returns a bool3x3 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool3x3 operator<=( const int3x3& lhs, const int3x3& rhs );

/// \relates int3x3
/// \brief Returns a bool3x3 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool3x3 operator>( const int3x3& lhs, const int3x3& rhs );

/// \relates int3x3
/// \brief Returns a bool3x3 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool3x3 operator>=( const int3x3& lhs, const int3x3& rhs );


// int3x4
/// \relates int3x4
/// \brief Returns a copy of the matrix that has been component-wise added by the given scalar value.
inline int3x4 operator+( const int3x4& lhs, const int32_t rhs );

/// \relates int3x4
/// \brief Adds each component of the matrix by the given scalar value.
inline int3x4 operator+=( int3x4& lhs, const int32_t rhs );

/// \relates int3x4
/// \brief Returns a copy of the matrix that has been component-wise added by the other matrix.
inline int3x4 operator+( const int3x4& lhs, const int3x4& rhs );

/// \relates int3x4
/// \brief Returns a copy of the matrix that has been component-wise subtracted by the given scalar value.
inline int3x4 operator-( const int3x4& lhs, const int32_t rhs );

/// \relates int3x4
/// \brief Subtracts each component of the matrix by the given scalar value.
inline int3x4 operator-=( int3x4& lhs, const int32_t rhs );

/// \relates int3x4
/// \brief Returns a copy of the matrix that has been component-wise subtracted by the other matrix.
inline int3x4 operator-( const int3x4& lhs, const int3x4& rhs );

/// \relates int3x4
/// \brief Returns a copy of the matrix that has been component-wise multiplied by the given scalar value.
inline int3x4 operator*( const int3x4& lhs, const int32_t rhs );

/// \relates int3x4
/// \brief Multiplies each component of the matrix by the given scalar value.
inline int3x4 operator*=( int3x4& lhs, const int32_t rhs );

/// \relates int3x4
/// \brief Returns a copy of the matrix where each row of the left-hand matrix has been dot-producted by the corresponding column of the right-hand matrix.
inline int3x3 operator*( const int3x4& lhs, const int4x3& rhs );

/// \relates int3x4
/// \brief Returns a copy of the matrix that has been component-wise divided by the given scalar value.
inline int3x4 operator/( const int3x4& lhs, const int32_t rhs );

/// \relates int3x4
/// \brief Divides each component of the matrix by the given scalar value.
inline int3x4 operator/=( int3x4& lhs, const int32_t rhs );

/// \relates int3x4
/// \brief Returns a copy of the matrix that has been component-wise divided by the other matrix.
inline int3x4 operator/( const int3x4& lhs, const int3x4& rhs );

/// \relates int3x4
/// \brief Returns a bool3x4 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool3x4 operator<( const int3x4& lhs, const int3x4& rhs );

/// \relates int3x4
/// \brief Returns a bool3x4 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool3x4 operator<=( const int3x4& lhs, const int3x4& rhs );

/// \relates int3x4
/// \brief Returns a bool3x4 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool3x4 operator>( const int3x4& lhs, const int3x4& rhs );

/// \relates int3x4
/// \brief Returns a bool3x4 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool3x4 operator>=( const int3x4& lhs, const int3x4& rhs );


// int4x2
/// \relates int4x2
/// \brief Returns a copy of the matrix that has been component-wise added by the given scalar value.
inline int4x2 operator+( const int4x2& lhs, const int32_t rhs );

/// \relates int4x2
/// \brief Adds each component of the matrix by the given scalar value.
inline int4x2 operator+=( int4x2& lhs, const int32_t rhs );

/// \relates int4x2
/// \brief Returns a copy of the matrix that has been component-wise added by the other matrix.
inline int4x2 operator+( const int4x2& lhs, const int4x2& rhs );

/// \relates int4x2
/// \brief Returns a copy of the matrix that has been component-wise subtracted by the given scalar value.
inline int4x2 operator-( const int4x2& lhs, const int32_t rhs );

/// \relates int4x2
/// \brief Subtracts each component of the matrix by the given scalar value.
inline int4x2 operator-=( int4x2& lhs, const int32_t rhs );

/// \relates int4x2
/// \brief Returns a copy of the matrix that has been component-wise subtracted by the other matrix.
inline int4x2 operator-( const int4x2& lhs, const int4x2& rhs );

/// \relates int4x2
/// \brief Returns a copy of the matrix that has been component-wise multiplied by the given scalar value.
inline int4x2 operator*( const int4x2& lhs, const int32_t rhs );

/// \relates int4x2
/// \brief Multiplies each component of the matrix by the given scalar value.
inline int4x2 operator*=( int4x2& lhs, const int32_t rhs );

/// \relates int4x2
/// \brief Returns a copy of the matrix where each row of the left-hand matrix has been dot-producted by the corresponding column of the right-hand matrix.
inline int4x4 operator*( const int4x2& lhs, const int2x4& rhs );

/// \relates int4x2
/// \brief Returns a copy of the matrix that has been component-wise divided by the given scalar value.
inline int4x2 operator/( const int4x2& lhs, const int32_t rhs );

/// \relates int4x2
/// \brief Divides each component of the matrix by the given scalar value.
inline int4x2 operator/=( int4x2& lhs, const int32_t rhs );

/// \relates int4x2
/// \brief Returns a copy of the matrix that has been component-wise divided by the other matrix.
inline int4x2 operator/( const int4x2& lhs, const int4x2& rhs );

/// \relates int4x2
/// \brief Returns a bool4x2 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool4x2 operator<( const int4x2& lhs, const int4x2& rhs );

/// \relates int4x2
/// \brief Returns a bool4x2 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool4x2 operator<=( const int4x2& lhs, const int4x2& rhs );

/// \relates int4x2
/// \brief Returns a bool4x2 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool4x2 operator>( const int4x2& lhs, const int4x2& rhs );

/// \relates int4x2
/// \brief Returns a bool4x2 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool4x2 operator>=( const int4x2& lhs, const int4x2& rhs );


// int4x3
/// \relates int4x3
/// \brief Returns a copy of the matrix that has been component-wise added by the given scalar value.
inline int4x3 operator+( const int4x3& lhs, const int32_t rhs );

/// \relates int4x3
/// \brief Adds each component of the matrix by the given scalar value.
inline int4x3 operator+=( int4x3& lhs, const int32_t rhs );

/// \relates int4x3
/// \brief Returns a copy of the matrix that has been component-wise added by the other matrix.
inline int4x3 operator+( const int4x3& lhs, const int4x3& rhs );

/// \relates int4x3
/// \brief Returns a copy of the matrix that has been component-wise subtracted by the given scalar value.
inline int4x3 operator-( const int4x3& lhs, const int32_t rhs );

/// \relates int4x3
/// \brief Subtracts each component of the matrix by the given scalar value.
inline int4x3 operator-=( int4x3& lhs, const int32_t rhs );

/// \relates int4x3
/// \brief Returns a copy of the matrix that has been component-wise subtracted by the other matrix.
inline int4x3 operator-( const int4x3& lhs, const int4x3& rhs );

/// \relates int4x3
/// \brief Returns a copy of the matrix that has been component-wise multiplied by the given scalar value.
inline int4x3 operator*( const int4x3& lhs, const int32_t rhs );

/// \relates int4x3
/// \brief Multiplies each component of the matrix by the given scalar value.
inline int4x3 operator*=( int4x3& lhs, const int32_t rhs );

/// \relates int4x3
/// \brief Returns a copy of the matrix where each row of the left-hand matrix has been dot-producted by the corresponding column of the right-hand matrix.
inline int4x4 operator*( const int4x3& lhs, const int3x4& rhs );

/// \relates int4x3
/// \brief Returns a copy of the matrix that has been component-wise divided by the given scalar value.
inline int4x3 operator/( const int4x3& lhs, const int32_t rhs );

/// \relates int4x3
/// \brief Divides each component of the matrix by the given scalar value.
inline int4x3 operator/=( int4x3& lhs, const int32_t rhs );

/// \relates int4x3
/// \brief Returns a copy of the matrix that has been component-wise divided by the other matrix.
inline int4x3 operator/( const int4x3& lhs, const int4x3& rhs );

/// \relates int4x3
/// \brief Returns a bool4x3 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool4x3 operator<( const int4x3& lhs, const int4x3& rhs );

/// \relates int4x3
/// \brief Returns a bool4x3 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool4x3 operator<=( const int4x3& lhs, const int4x3& rhs );

/// \relates int4x3
/// \brief Returns a bool4x3 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool4x3 operator>( const int4x3& lhs, const int4x3& rhs );

/// \relates int4x3
/// \brief Returns a bool4x3 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool4x3 operator>=( const int4x3& lhs, const int4x3& rhs );


// int4x4
/// \relates int4x4
/// \brief Returns a copy of the matrix that has been component-wise added by the given scalar value.
inline int4x4 operator+( const int4x4& lhs, const int32_t rhs );

/// \relates int4x4
/// \brief Adds each component of the matrix by the given scalar value.
inline int4x4 operator+=( int4x4& lhs, const int32_t rhs );

/// \relates int4x4
/// \brief Returns a copy of the matrix that has been component-wise added by the other matrix.
inline int4x4 operator+( const int4x4& lhs, const int4x4& rhs );

/// \relates int4x4
/// \brief Returns a copy of the matrix that has been component-wise subtracted by the given scalar value.
inline int4x4 operator-( const int4x4& lhs, const int32_t rhs );

/// \relates int4x4
/// \brief Subtracts each component of the matrix by the given scalar value.
inline int4x4 operator-=( int4x4& lhs, const int32_t rhs );

/// \relates int4x4
/// \brief Returns a copy of the matrix that has been component-wise subtracted by the other matrix.
inline int4x4 operator-( const int4x4& lhs, const int4x4& rhs );

/// \relates int4x4
/// \brief Returns a copy of the matrix that has been component-wise multiplied by the given scalar value.
inline int4x4 operator*( const int4x4& lhs, const int32_t rhs );

/// \relates int4x4
/// \brief Multiplies each component of the matrix by the given scalar value.
inline int4x4 operator*=( int4x4& lhs, const int32_t rhs );

/// \relates int4x4
/// \brief Returns a copy of the matrix where each row of the left-hand matrix has been dot-producted by the corresponding column of the right-hand matrix.
inline int4x4 operator*( const int4x4& lhs, const int4x4& rhs );

/// \relates int4x4
/// \brief Returns a copy of the matrix that has been component-wise divided by the given scalar value.
inline int4x4 operator/( const int4x4& lhs, const int32_t rhs );

/// \relates int4x4
/// \brief Divides each component of the matrix by the given scalar value.
inline int4x4 operator/=( int4x4& lhs, const int32_t rhs );

/// \relates int4x4
/// \brief Returns a copy of the matrix that has been component-wise divided by the other matrix.
inline int4x4 operator/( const int4x4& lhs, const int4x4& rhs );

/// \relates int4x4
/// \brief Returns a bool4x4 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool4x4 operator<( const int4x4& lhs, const int4x4& rhs );

/// \relates int4x4
/// \brief Returns a bool4x4 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool4x4 operator<=( const int4x4& lhs, const int4x4& rhs );

/// \relates int4x4
/// \brief Returns a bool4x4 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool4x4 operator>( const int4x4& lhs, const int4x4& rhs );

/// \relates int4x4
/// \brief Returns a bool4x4 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool4x4 operator>=( const int4x4& lhs, const int4x4& rhs );


// uint2x2
/// \relates uint2x2
/// \brief Returns a copy of the matrix that has been component-wise added by the given scalar value.
inline uint2x2 operator+( const uint2x2& lhs, const uint32_t rhs );

/// \relates uint2x2
/// \brief Adds each component of the matrix by the given scalar value.
inline uint2x2 operator+=( uint2x2& lhs, const uint32_t rhs );

/// \relates uint2x2
/// \brief Returns a copy of the matrix that has been component-wise added by the other matrix.
inline uint2x2 operator+( const uint2x2& lhs, const uint2x2& rhs );

/// \relates uint2x2
/// \brief Returns a copy of the matrix that has been component-wise subtracted by the given scalar value.
inline uint2x2 operator-( const uint2x2& lhs, const uint32_t rhs );

/// \relates uint2x2
/// \brief Subtracts each component of the matrix by the given scalar value.
inline uint2x2 operator-=( uint2x2& lhs, const uint32_t rhs );

/// \relates uint2x2
/// \brief Returns a copy of the matrix that has been component-wise subtracted by the other matrix.
inline uint2x2 operator-( const uint2x2& lhs, const uint2x2& rhs );

/// \relates uint2x2
/// \brief Returns a copy of the matrix that has been component-wise multiplied by the given scalar value.
inline uint2x2 operator*( const uint2x2& lhs, const uint32_t rhs );

/// \relates uint2x2
/// \brief Multiplies each component of the matrix by the given scalar value.
inline uint2x2 operator*=( uint2x2& lhs, const uint32_t rhs );

/// \relates uint2x2
/// \brief Returns a copy of the matrix where each row of the left-hand matrix has been dot-producted by the corresponding column of the right-hand matrix.
inline uint2x2 operator*( const uint2x2& lhs, const uint2x2& rhs );

/// \relates uint2x2
/// \brief Returns a copy of the matrix that has been component-wise divided by the given scalar value.
inline uint2x2 operator/( const uint2x2& lhs, const uint32_t rhs );

/// \relates uint2x2
/// \brief Divides each component of the matrix by the given scalar value.
inline uint2x2 operator/=( uint2x2& lhs, const uint32_t rhs );

/// \relates uint2x2
/// \brief Returns a copy of the matrix that has been component-wise divided by the other matrix.
inline uint2x2 operator/( const uint2x2& lhs, const uint2x2& rhs );

/// \relates uint2x2
/// \brief Returns a bool2x2 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool2x2 operator<( const uint2x2& lhs, const uint2x2& rhs );

/// \relates uint2x2
/// \brief Returns a bool2x2 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool2x2 operator<=( const uint2x2& lhs, const uint2x2& rhs );

/// \relates uint2x2
/// \brief Returns a bool2x2 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool2x2 operator>( const uint2x2& lhs, const uint2x2& rhs );

/// \relates uint2x2
/// \brief Returns a bool2x2 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool2x2 operator>=( const uint2x2& lhs, const uint2x2& rhs );


// uint2x3
/// \relates uint2x3
/// \brief Returns a copy of the matrix that has been component-wise added by the given scalar value.
inline uint2x3 operator+( const uint2x3& lhs, const uint32_t rhs );

/// \relates uint2x3
/// \brief Adds each component of the matrix by the given scalar value.
inline uint2x3 operator+=( uint2x3& lhs, const uint32_t rhs );

/// \relates uint2x3
/// \brief Returns a copy of the matrix that has been component-wise added by the other matrix.
inline uint2x3 operator+( const uint2x3& lhs, const uint2x3& rhs );

/// \relates uint2x3
/// \brief Returns a copy of the matrix that has been component-wise subtracted by the given scalar value.
inline uint2x3 operator-( const uint2x3& lhs, const uint32_t rhs );

/// \relates uint2x3
/// \brief Subtracts each component of the matrix by the given scalar value.
inline uint2x3 operator-=( uint2x3& lhs, const uint32_t rhs );

/// \relates uint2x3
/// \brief Returns a copy of the matrix that has been component-wise subtracted by the other matrix.
inline uint2x3 operator-( const uint2x3& lhs, const uint2x3& rhs );

/// \relates uint2x3
/// \brief Returns a copy of the matrix that has been component-wise multiplied by the given scalar value.
inline uint2x3 operator*( const uint2x3& lhs, const uint32_t rhs );

/// \relates uint2x3
/// \brief Multiplies each component of the matrix by the given scalar value.
inline uint2x3 operator*=( uint2x3& lhs, const uint32_t rhs );

/// \relates uint2x3
/// \brief Returns a copy of the matrix where each row of the left-hand matrix has been dot-producted by the corresponding column of the right-hand matrix.
inline uint2x2 operator*( const uint2x3& lhs, const uint3x2& rhs );

/// \relates uint2x3
/// \brief Returns a copy of the matrix that has been component-wise divided by the given scalar value.
inline uint2x3 operator/( const uint2x3& lhs, const uint32_t rhs );

/// \relates uint2x3
/// \brief Divides each component of the matrix by the given scalar value.
inline uint2x3 operator/=( uint2x3& lhs, const uint32_t rhs );

/// \relates uint2x3
/// \brief Returns a copy of the matrix that has been component-wise divided by the other matrix.
inline uint2x3 operator/( const uint2x3& lhs, const uint2x3& rhs );

/// \relates uint2x3
/// \brief Returns a bool2x3 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool2x3 operator<( const uint2x3& lhs, const uint2x3& rhs );

/// \relates uint2x3
/// \brief Returns a bool2x3 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool2x3 operator<=( const uint2x3& lhs, const uint2x3& rhs );

/// \relates uint2x3
/// \brief Returns a bool2x3 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool2x3 operator>( const uint2x3& lhs, const uint2x3& rhs );

/// \relates uint2x3
/// \brief Returns a bool2x3 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool2x3 operator>=( const uint2x3& lhs, const uint2x3& rhs );


// uint2x4
/// \relates uint2x4
/// \brief Returns a copy of the matrix that has been component-wise added by the given scalar value.
inline uint2x4 operator+( const uint2x4& lhs, const uint32_t rhs );

/// \relates uint2x4
/// \brief Adds each component of the matrix by the given scalar value.
inline uint2x4 operator+=( uint2x4& lhs, const uint32_t rhs );

/// \relates uint2x4
/// \brief Returns a copy of the matrix that has been component-wise added by the other matrix.
inline uint2x4 operator+( const uint2x4& lhs, const uint2x4& rhs );

/// \relates uint2x4
/// \brief Returns a copy of the matrix that has been component-wise subtracted by the given scalar value.
inline uint2x4 operator-( const uint2x4& lhs, const uint32_t rhs );

/// \relates uint2x4
/// \brief Subtracts each component of the matrix by the given scalar value.
inline uint2x4 operator-=( uint2x4& lhs, const uint32_t rhs );

/// \relates uint2x4
/// \brief Returns a copy of the matrix that has been component-wise subtracted by the other matrix.
inline uint2x4 operator-( const uint2x4& lhs, const uint2x4& rhs );

/// \relates uint2x4
/// \brief Returns a copy of the matrix that has been component-wise multiplied by the given scalar value.
inline uint2x4 operator*( const uint2x4& lhs, const uint32_t rhs );

/// \relates uint2x4
/// \brief Multiplies each component of the matrix by the given scalar value.
inline uint2x4 operator*=( uint2x4& lhs, const uint32_t rhs );

/// \relates uint2x4
/// \brief Returns a copy of the matrix where each row of the left-hand matrix has been dot-producted by the corresponding column of the right-hand matrix.
inline uint2x2 operator*( const uint2x4& lhs, const uint4x2& rhs );

/// \relates uint2x4
/// \brief Returns a copy of the matrix that has been component-wise divided by the given scalar value.
inline uint2x4 operator/( const uint2x4& lhs, const uint32_t rhs );

/// \relates uint2x4
/// \brief Divides each component of the matrix by the given scalar value.
inline uint2x4 operator/=( uint2x4& lhs, const uint32_t rhs );

/// \relates uint2x4
/// \brief Returns a copy of the matrix that has been component-wise divided by the other matrix.
inline uint2x4 operator/( const uint2x4& lhs, const uint2x4& rhs );

/// \relates uint2x4
/// \brief Returns a bool2x4 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool2x4 operator<( const uint2x4& lhs, const uint2x4& rhs );

/// \relates uint2x4
/// \brief Returns a bool2x4 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool2x4 operator<=( const uint2x4& lhs, const uint2x4& rhs );

/// \relates uint2x4
/// \brief Returns a bool2x4 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool2x4 operator>( const uint2x4& lhs, const uint2x4& rhs );

/// \relates uint2x4
/// \brief Returns a bool2x4 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool2x4 operator>=( const uint2x4& lhs, const uint2x4& rhs );


// uint3x2
/// \relates uint3x2
/// \brief Returns a copy of the matrix that has been component-wise added by the given scalar value.
inline uint3x2 operator+( const uint3x2& lhs, const uint32_t rhs );

/// \relates uint3x2
/// \brief Adds each component of the matrix by the given scalar value.
inline uint3x2 operator+=( uint3x2& lhs, const uint32_t rhs );

/// \relates uint3x2
/// \brief Returns a copy of the matrix that has been component-wise added by the other matrix.
inline uint3x2 operator+( const uint3x2& lhs, const uint3x2& rhs );

/// \relates uint3x2
/// \brief Returns a copy of the matrix that has been component-wise subtracted by the given scalar value.
inline uint3x2 operator-( const uint3x2& lhs, const uint32_t rhs );

/// \relates uint3x2
/// \brief Subtracts each component of the matrix by the given scalar value.
inline uint3x2 operator-=( uint3x2& lhs, const uint32_t rhs );

/// \relates uint3x2
/// \brief Returns a copy of the matrix that has been component-wise subtracted by the other matrix.
inline uint3x2 operator-( const uint3x2& lhs, const uint3x2& rhs );

/// \relates uint3x2
/// \brief Returns a copy of the matrix that has been component-wise multiplied by the given scalar value.
inline uint3x2 operator*( const uint3x2& lhs, const uint32_t rhs );

/// \relates uint3x2
/// \brief Multiplies each component of the matrix by the given scalar value.
inline uint3x2 operator*=( uint3x2& lhs, const uint32_t rhs );

/// \relates uint3x2
/// \brief Returns a copy of the matrix where each row of the left-hand matrix has been dot-producted by the corresponding column of the right-hand matrix.
inline uint3x3 operator*( const uint3x2& lhs, const uint2x3& rhs );

/// \relates uint3x2
/// \brief Returns a copy of the matrix that has been component-wise divided by the given scalar value.
inline uint3x2 operator/( const uint3x2& lhs, const uint32_t rhs );

/// \relates uint3x2
/// \brief Divides each component of the matrix by the given scalar value.
inline uint3x2 operator/=( uint3x2& lhs, const uint32_t rhs );

/// \relates uint3x2
/// \brief Returns a copy of the matrix that has been component-wise divided by the other matrix.
inline uint3x2 operator/( const uint3x2& lhs, const uint3x2& rhs );

/// \relates uint3x2
/// \brief Returns a bool3x2 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool3x2 operator<( const uint3x2& lhs, const uint3x2& rhs );

/// \relates uint3x2
/// \brief Returns a bool3x2 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool3x2 operator<=( const uint3x2& lhs, const uint3x2& rhs );

/// \relates uint3x2
/// \brief Returns a bool3x2 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool3x2 operator>( const uint3x2& lhs, const uint3x2& rhs );

/// \relates uint3x2
/// \brief Returns a bool3x2 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool3x2 operator>=( const uint3x2& lhs, const uint3x2& rhs );


// uint3x3
/// \relates uint3x3
/// \brief Returns a copy of the matrix that has been component-wise added by the given scalar value.
inline uint3x3 operator+( const uint3x3& lhs, const uint32_t rhs );

/// \relates uint3x3
/// \brief Adds each component of the matrix by the given scalar value.
inline uint3x3 operator+=( uint3x3& lhs, const uint32_t rhs );

/// \relates uint3x3
/// \brief Returns a copy of the matrix that has been component-wise added by the other matrix.
inline uint3x3 operator+( const uint3x3& lhs, const uint3x3& rhs );

/// \relates uint3x3
/// \brief Returns a copy of the matrix that has been component-wise subtracted by the given scalar value.
inline uint3x3 operator-( const uint3x3& lhs, const uint32_t rhs );

/// \relates uint3x3
/// \brief Subtracts each component of the matrix by the given scalar value.
inline uint3x3 operator-=( uint3x3& lhs, const uint32_t rhs );

/// \relates uint3x3
/// \brief Returns a copy of the matrix that has been component-wise subtracted by the other matrix.
inline uint3x3 operator-( const uint3x3& lhs, const uint3x3& rhs );

/// \relates uint3x3
/// \brief Returns a copy of the matrix that has been component-wise multiplied by the given scalar value.
inline uint3x3 operator*( const uint3x3& lhs, const uint32_t rhs );

/// \relates uint3x3
/// \brief Multiplies each component of the matrix by the given scalar value.
inline uint3x3 operator*=( uint3x3& lhs, const uint32_t rhs );

/// \relates uint3x3
/// \brief Returns a copy of the matrix where each row of the left-hand matrix has been dot-producted by the corresponding column of the right-hand matrix.
inline uint3x3 operator*( const uint3x3& lhs, const uint3x3& rhs );

/// \relates uint3x3
/// \brief Returns a copy of the matrix that has been component-wise divided by the given scalar value.
inline uint3x3 operator/( const uint3x3& lhs, const uint32_t rhs );

/// \relates uint3x3
/// \brief Divides each component of the matrix by the given scalar value.
inline uint3x3 operator/=( uint3x3& lhs, const uint32_t rhs );

/// \relates uint3x3
/// \brief Returns a copy of the matrix that has been component-wise divided by the other matrix.
inline uint3x3 operator/( const uint3x3& lhs, const uint3x3& rhs );

/// \relates uint3x3
/// \brief Returns a bool3x3 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool3x3 operator<( const uint3x3& lhs, const uint3x3& rhs );

/// \relates uint3x3
/// \brief Returns a bool3x3 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool3x3 operator<=( const uint3x3& lhs, const uint3x3& rhs );

/// \relates uint3x3
/// \brief Returns a bool3x3 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool3x3 operator>( const uint3x3& lhs, const uint3x3& rhs );

/// \relates uint3x3
/// \brief Returns a bool3x3 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool3x3 operator>=( const uint3x3& lhs, const uint3x3& rhs );


// uint3x4
/// \relates uint3x4
/// \brief Returns a copy of the matrix that has been component-wise added by the given scalar value.
inline uint3x4 operator+( const uint3x4& lhs, const uint32_t rhs );

/// \relates uint3x4
/// \brief Adds each component of the matrix by the given scalar value.
inline uint3x4 operator+=( uint3x4& lhs, const uint32_t rhs );

/// \relates uint3x4
/// \brief Returns a copy of the matrix that has been component-wise added by the other matrix.
inline uint3x4 operator+( const uint3x4& lhs, const uint3x4& rhs );

/// \relates uint3x4
/// \brief Returns a copy of the matrix that has been component-wise subtracted by the given scalar value.
inline uint3x4 operator-( const uint3x4& lhs, const uint32_t rhs );

/// \relates uint3x4
/// \brief Subtracts each component of the matrix by the given scalar value.
inline uint3x4 operator-=( uint3x4& lhs, const uint32_t rhs );

/// \relates uint3x4
/// \brief Returns a copy of the matrix that has been component-wise subtracted by the other matrix.
inline uint3x4 operator-( const uint3x4& lhs, const uint3x4& rhs );

/// \relates uint3x4
/// \brief Returns a copy of the matrix that has been component-wise multiplied by the given scalar value.
inline uint3x4 operator*( const uint3x4& lhs, const uint32_t rhs );

/// \relates uint3x4
/// \brief Multiplies each component of the matrix by the given scalar value.
inline uint3x4 operator*=( uint3x4& lhs, const uint32_t rhs );

/// \relates uint3x4
/// \brief Returns a copy of the matrix where each row of the left-hand matrix has been dot-producted by the corresponding column of the right-hand matrix.
inline uint3x3 operator*( const uint3x4& lhs, const uint4x3& rhs );

/// \relates uint3x4
/// \brief Returns a copy of the matrix that has been component-wise divided by the given scalar value.
inline uint3x4 operator/( const uint3x4& lhs, const uint32_t rhs );

/// \relates uint3x4
/// \brief Divides each component of the matrix by the given scalar value.
inline uint3x4 operator/=( uint3x4& lhs, const uint32_t rhs );

/// \relates uint3x4
/// \brief Returns a copy of the matrix that has been component-wise divided by the other matrix.
inline uint3x4 operator/( const uint3x4& lhs, const uint3x4& rhs );

/// \relates uint3x4
/// \brief Returns a bool3x4 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool3x4 operator<( const uint3x4& lhs, const uint3x4& rhs );

/// \relates uint3x4
/// \brief Returns a bool3x4 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool3x4 operator<=( const uint3x4& lhs, const uint3x4& rhs );

/// \relates uint3x4
/// \brief Returns a bool3x4 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool3x4 operator>( const uint3x4& lhs, const uint3x4& rhs );

/// \relates uint3x4
/// \brief Returns a bool3x4 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool3x4 operator>=( const uint3x4& lhs, const uint3x4& rhs );


// uint4x2
/// \relates uint4x2
/// \brief Returns a copy of the matrix that has been component-wise added by the given scalar value.
inline uint4x2 operator+( const uint4x2& lhs, const uint32_t rhs );

/// \relates uint4x2
/// \brief Adds each component of the matrix by the given scalar value.
inline uint4x2 operator+=( uint4x2& lhs, const uint32_t rhs );

/// \relates uint4x2
/// \brief Returns a copy of the matrix that has been component-wise added by the other matrix.
inline uint4x2 operator+( const uint4x2& lhs, const uint4x2& rhs );

/// \relates uint4x2
/// \brief Returns a copy of the matrix that has been component-wise subtracted by the given scalar value.
inline uint4x2 operator-( const uint4x2& lhs, const uint32_t rhs );

/// \relates uint4x2
/// \brief Subtracts each component of the matrix by the given scalar value.
inline uint4x2 operator-=( uint4x2& lhs, const uint32_t rhs );

/// \relates uint4x2
/// \brief Returns a copy of the matrix that has been component-wise subtracted by the other matrix.
inline uint4x2 operator-( const uint4x2& lhs, const uint4x2& rhs );

/// \relates uint4x2
/// \brief Returns a copy of the matrix that has been component-wise multiplied by the given scalar value.
inline uint4x2 operator*( const uint4x2& lhs, const uint32_t rhs );

/// \relates uint4x2
/// \brief Multiplies each component of the matrix by the given scalar value.
inline uint4x2 operator*=( uint4x2& lhs, const uint32_t rhs );

/// \relates uint4x2
/// \brief Returns a copy of the matrix where each row of the left-hand matrix has been dot-producted by the corresponding column of the right-hand matrix.
inline uint4x4 operator*( const uint4x2& lhs, const uint2x4& rhs );

/// \relates uint4x2
/// \brief Returns a copy of the matrix that has been component-wise divided by the given scalar value.
inline uint4x2 operator/( const uint4x2& lhs, const uint32_t rhs );

/// \relates uint4x2
/// \brief Divides each component of the matrix by the given scalar value.
inline uint4x2 operator/=( uint4x2& lhs, const uint32_t rhs );

/// \relates uint4x2
/// \brief Returns a copy of the matrix that has been component-wise divided by the other matrix.
inline uint4x2 operator/( const uint4x2& lhs, const uint4x2& rhs );

/// \relates uint4x2
/// \brief Returns a bool4x2 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool4x2 operator<( const uint4x2& lhs, const uint4x2& rhs );

/// \relates uint4x2
/// \brief Returns a bool4x2 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool4x2 operator<=( const uint4x2& lhs, const uint4x2& rhs );

/// \relates uint4x2
/// \brief Returns a bool4x2 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool4x2 operator>( const uint4x2& lhs, const uint4x2& rhs );

/// \relates uint4x2
/// \brief Returns a bool4x2 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool4x2 operator>=( const uint4x2& lhs, const uint4x2& rhs );


// uint4x3
/// \relates uint4x3
/// \brief Returns a copy of the matrix that has been component-wise added by the given scalar value.
inline uint4x3 operator+( const uint4x3& lhs, const uint32_t rhs );

/// \relates uint4x3
/// \brief Adds each component of the matrix by the given scalar value.
inline uint4x3 operator+=( uint4x3& lhs, const uint32_t rhs );

/// \relates uint4x3
/// \brief Returns a copy of the matrix that has been component-wise added by the other matrix.
inline uint4x3 operator+( const uint4x3& lhs, const uint4x3& rhs );

/// \relates uint4x3
/// \brief Returns a copy of the matrix that has been component-wise subtracted by the given scalar value.
inline uint4x3 operator-( const uint4x3& lhs, const uint32_t rhs );

/// \relates uint4x3
/// \brief Subtracts each component of the matrix by the given scalar value.
inline uint4x3 operator-=( uint4x3& lhs, const uint32_t rhs );

/// \relates uint4x3
/// \brief Returns a copy of the matrix that has been component-wise subtracted by the other matrix.
inline uint4x3 operator-( const uint4x3& lhs, const uint4x3& rhs );

/// \relates uint4x3
/// \brief Returns a copy of the matrix that has been component-wise multiplied by the given scalar value.
inline uint4x3 operator*( const uint4x3& lhs, const uint32_t rhs );

/// \relates uint4x3
/// \brief Multiplies each component of the matrix by the given scalar value.
inline uint4x3 operator*=( uint4x3& lhs, const uint32_t rhs );

/// \relates uint4x3
/// \brief Returns a copy of the matrix where each row of the left-hand matrix has been dot-producted by the corresponding column of the right-hand matrix.
inline uint4x4 operator*( const uint4x3& lhs, const uint3x4& rhs );

/// \relates uint4x3
/// \brief Returns a copy of the matrix that has been component-wise divided by the given scalar value.
inline uint4x3 operator/( const uint4x3& lhs, const uint32_t rhs );

/// \relates uint4x3
/// \brief Divides each component of the matrix by the given scalar value.
inline uint4x3 operator/=( uint4x3& lhs, const uint32_t rhs );

/// \relates uint4x3
/// \brief Returns a copy of the matrix that has been component-wise divided by the other matrix.
inline uint4x3 operator/( const uint4x3& lhs, const uint4x3& rhs );

/// \relates uint4x3
/// \brief Returns a bool4x3 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool4x3 operator<( const uint4x3& lhs, const uint4x3& rhs );

/// \relates uint4x3
/// \brief Returns a bool4x3 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool4x3 operator<=( const uint4x3& lhs, const uint4x3& rhs );

/// \relates uint4x3
/// \brief Returns a bool4x3 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool4x3 operator>( const uint4x3& lhs, const uint4x3& rhs );

/// \relates uint4x3
/// \brief Returns a bool4x3 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool4x3 operator>=( const uint4x3& lhs, const uint4x3& rhs );


// uint4x4
/// \relates uint4x4
/// \brief Returns a copy of the matrix that has been component-wise added by the given scalar value.
inline uint4x4 operator+( const uint4x4& lhs, const uint32_t rhs );

/// \relates uint4x4
/// \brief Adds each component of the matrix by the given scalar value.
inline uint4x4 operator+=( uint4x4& lhs, const uint32_t rhs );

/// \relates uint4x4
/// \brief Returns a copy of the matrix that has been component-wise added by the other matrix.
inline uint4x4 operator+( const uint4x4& lhs, const uint4x4& rhs );

/// \relates uint4x4
/// \brief Returns a copy of the matrix that has been component-wise subtracted by the given scalar value.
inline uint4x4 operator-( const uint4x4& lhs, const uint32_t rhs );

/// \relates uint4x4
/// \brief Subtracts each component of the matrix by the given scalar value.
inline uint4x4 operator-=( uint4x4& lhs, const uint32_t rhs );

/// \relates uint4x4
/// \brief Returns a copy of the matrix that has been component-wise subtracted by the other matrix.
inline uint4x4 operator-( const uint4x4& lhs, const uint4x4& rhs );

/// \relates uint4x4
/// \brief Returns a copy of the matrix that has been component-wise multiplied by the given scalar value.
inline uint4x4 operator*( const uint4x4& lhs, const uint32_t rhs );

/// \relates uint4x4
/// \brief Multiplies each component of the matrix by the given scalar value.
inline uint4x4 operator*=( uint4x4& lhs, const uint32_t rhs );

/// \relates uint4x4
/// \brief Returns a copy of the matrix where each row of the left-hand matrix has been dot-producted by the corresponding column of the right-hand matrix.
inline uint4x4 operator*( const uint4x4& lhs, const uint4x4& rhs );

/// \relates uint4x4
/// \brief Returns a copy of the matrix that has been component-wise divided by the given scalar value.
inline uint4x4 operator/( const uint4x4& lhs, const uint32_t rhs );

/// \relates uint4x4
/// \brief Divides each component of the matrix by the given scalar value.
inline uint4x4 operator/=( uint4x4& lhs, const uint32_t rhs );

/// \relates uint4x4
/// \brief Returns a copy of the matrix that has been component-wise divided by the other matrix.
inline uint4x4 operator/( const uint4x4& lhs, const uint4x4& rhs );

/// \relates uint4x4
/// \brief Returns a bool4x4 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool4x4 operator<( const uint4x4& lhs, const uint4x4& rhs );

/// \relates uint4x4
/// \brief Returns a bool4x4 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool4x4 operator<=( const uint4x4& lhs, const uint4x4& rhs );

/// \relates uint4x4
/// \brief Returns a bool4x4 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool4x4 operator>( const uint4x4& lhs, const uint4x4& rhs );

/// \relates uint4x4
/// \brief Returns a bool4x4 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool4x4 operator>=( const uint4x4& lhs, const uint4x4& rhs );


// float2x2
/// \relates float2x2
/// \brief Returns a copy of the matrix that has been component-wise added by the given scalar value.
inline float2x2 operator+( const float2x2& lhs, const float rhs );

/// \relates float2x2
/// \brief Adds each component of the matrix by the given scalar value.
inline float2x2 operator+=( float2x2& lhs, const float rhs );

/// \relates float2x2
/// \brief Returns a copy of the matrix that has been component-wise added by the other matrix.
inline float2x2 operator+( const float2x2& lhs, const float2x2& rhs );

/// \relates float2x2
/// \brief Returns a copy of the matrix that has been component-wise subtracted by the given scalar value.
inline float2x2 operator-( const float2x2& lhs, const float rhs );

/// \relates float2x2
/// \brief Subtracts each component of the matrix by the given scalar value.
inline float2x2 operator-=( float2x2& lhs, const float rhs );

/// \relates float2x2
/// \brief Returns a copy of the matrix that has been component-wise subtracted by the other matrix.
inline float2x2 operator-( const float2x2& lhs, const float2x2& rhs );

/// \relates float2x2
/// \brief Returns a copy of the matrix that has been component-wise multiplied by the given scalar value.
inline float2x2 operator*( const float2x2& lhs, const float rhs );

/// \relates float2x2
/// \brief Multiplies each component of the matrix by the given scalar value.
inline float2x2 operator*=( float2x2& lhs, const float rhs );

/// \relates float2x2
/// \brief Returns a copy of the matrix where each row of the left-hand matrix has been dot-producted by the corresponding column of the right-hand matrix.
inline float2x2 operator*( const float2x2& lhs, const float2x2& rhs );

/// \relates float2x2
/// \brief Returns a copy of the matrix that has been component-wise divided by the given scalar value.
inline float2x2 operator/( const float2x2& lhs, const float rhs );

/// \relates float2x2
/// \brief Divides each component of the matrix by the given scalar value.
inline float2x2 operator/=( float2x2& lhs, const float rhs );

/// \relates float2x2
/// \brief Returns a copy of the matrix where the left-hand matrix has been mathematically multiplied by the inverse of the right-hand matrix.
inline float2x2 operator/( const float2x2& lhs, const float2x2& rhs );

/// \relates float2x2
/// \brief Returns a bool2x2 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool2x2 operator<( const float2x2& lhs, const float2x2& rhs );

/// \relates float2x2
/// \brief Returns a bool2x2 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool2x2 operator<=( const float2x2& lhs, const float2x2& rhs );

/// \relates float2x2
/// \brief Returns a bool2x2 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool2x2 operator>( const float2x2& lhs, const float2x2& rhs );

/// \relates float2x2
/// \brief Returns a bool2x2 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool2x2 operator>=( const float2x2& lhs, const float2x2& rhs );


// float2x3
/// \relates float2x3
/// \brief Returns a copy of the matrix that has been component-wise added by the given scalar value.
inline float2x3 operator+( const float2x3& lhs, const float rhs );

/// \relates float2x3
/// \brief Adds each component of the matrix by the given scalar value.
inline float2x3 operator+=( float2x3& lhs, const float rhs );

/// \relates float2x3
/// \brief Returns a copy of the matrix that has been component-wise added by the other matrix.
inline float2x3 operator+( const float2x3& lhs, const float2x3& rhs );

/// \relates float2x3
/// \brief Returns a copy of the matrix that has been component-wise subtracted by the given scalar value.
inline float2x3 operator-( const float2x3& lhs, const float rhs );

/// \relates float2x3
/// \brief Subtracts each component of the matrix by the given scalar value.
inline float2x3 operator-=( float2x3& lhs, const float rhs );

/// \relates float2x3
/// \brief Returns a copy of the matrix that has been component-wise subtracted by the other matrix.
inline float2x3 operator-( const float2x3& lhs, const float2x3& rhs );

/// \relates float2x3
/// \brief Returns a copy of the matrix that has been component-wise multiplied by the given scalar value.
inline float2x3 operator*( const float2x3& lhs, const float rhs );

/// \relates float2x3
/// \brief Multiplies each component of the matrix by the given scalar value.
inline float2x3 operator*=( float2x3& lhs, const float rhs );

/// \relates float2x3
/// \brief Returns a copy of the matrix where each row of the left-hand matrix has been dot-producted by the corresponding column of the right-hand matrix.
inline float2x2 operator*( const float2x3& lhs, const float3x2& rhs );

/// \relates float2x3
/// \brief Returns a copy of the matrix that has been component-wise divided by the given scalar value.
inline float2x3 operator/( const float2x3& lhs, const float rhs );

/// \relates float2x3
/// \brief Divides each component of the matrix by the given scalar value.
inline float2x3 operator/=( float2x3& lhs, const float rhs );

/// \relates float2x3
/// \brief Returns a copy of the matrix that has been component-wise divided by the other matrix.
inline float2x3 operator/( const float2x3& lhs, const float2x3& rhs );

/// \relates float2x3
/// \brief Returns a bool2x3 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool2x3 operator<( const float2x3& lhs, const float2x3& rhs );

/// \relates float2x3
/// \brief Returns a bool2x3 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool2x3 operator<=( const float2x3& lhs, const float2x3& rhs );

/// \relates float2x3
/// \brief Returns a bool2x3 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool2x3 operator>( const float2x3& lhs, const float2x3& rhs );

/// \relates float2x3
/// \brief Returns a bool2x3 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool2x3 operator>=( const float2x3& lhs, const float2x3& rhs );


// float2x4
/// \relates float2x4
/// \brief Returns a copy of the matrix that has been component-wise added by the given scalar value.
inline float2x4 operator+( const float2x4& lhs, const float rhs );

/// \relates float2x4
/// \brief Adds each component of the matrix by the given scalar value.
inline float2x4 operator+=( float2x4& lhs, const float rhs );

/// \relates float2x4
/// \brief Returns a copy of the matrix that has been component-wise added by the other matrix.
inline float2x4 operator+( const float2x4& lhs, const float2x4& rhs );

/// \relates float2x4
/// \brief Returns a copy of the matrix that has been component-wise subtracted by the given scalar value.
inline float2x4 operator-( const float2x4& lhs, const float rhs );

/// \relates float2x4
/// \brief Subtracts each component of the matrix by the given scalar value.
inline float2x4 operator-=( float2x4& lhs, const float rhs );

/// \relates float2x4
/// \brief Returns a copy of the matrix that has been component-wise subtracted by the other matrix.
inline float2x4 operator-( const float2x4& lhs, const float2x4& rhs );

/// \relates float2x4
/// \brief Returns a copy of the matrix that has been component-wise multiplied by the given scalar value.
inline float2x4 operator*( const float2x4& lhs, const float rhs );

/// \relates float2x4
/// \brief Multiplies each component of the matrix by the given scalar value.
inline float2x4 operator*=( float2x4& lhs, const float rhs );

/// \relates float2x4
/// \brief Returns a copy of the matrix where each row of the left-hand matrix has been dot-producted by the corresponding column of the right-hand matrix.
inline float2x2 operator*( const float2x4& lhs, const float4x2& rhs );

/// \relates float2x4
/// \brief Returns a copy of the matrix that has been component-wise divided by the given scalar value.
inline float2x4 operator/( const float2x4& lhs, const float rhs );

/// \relates float2x4
/// \brief Divides each component of the matrix by the given scalar value.
inline float2x4 operator/=( float2x4& lhs, const float rhs );

/// \relates float2x4
/// \brief Returns a copy of the matrix that has been component-wise divided by the other matrix.
inline float2x4 operator/( const float2x4& lhs, const float2x4& rhs );

/// \relates float2x4
/// \brief Returns a bool2x4 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool2x4 operator<( const float2x4& lhs, const float2x4& rhs );

/// \relates float2x4
/// \brief Returns a bool2x4 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool2x4 operator<=( const float2x4& lhs, const float2x4& rhs );

/// \relates float2x4
/// \brief Returns a bool2x4 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool2x4 operator>( const float2x4& lhs, const float2x4& rhs );

/// \relates float2x4
/// \brief Returns a bool2x4 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool2x4 operator>=( const float2x4& lhs, const float2x4& rhs );


// float3x2
/// \relates float3x2
/// \brief Returns a copy of the matrix that has been component-wise added by the given scalar value.
inline float3x2 operator+( const float3x2& lhs, const float rhs );

/// \relates float3x2
/// \brief Adds each component of the matrix by the given scalar value.
inline float3x2 operator+=( float3x2& lhs, const float rhs );

/// \relates float3x2
/// \brief Returns a copy of the matrix that has been component-wise added by the other matrix.
inline float3x2 operator+( const float3x2& lhs, const float3x2& rhs );

/// \relates float3x2
/// \brief Returns a copy of the matrix that has been component-wise subtracted by the given scalar value.
inline float3x2 operator-( const float3x2& lhs, const float rhs );

/// \relates float3x2
/// \brief Subtracts each component of the matrix by the given scalar value.
inline float3x2 operator-=( float3x2& lhs, const float rhs );

/// \relates float3x2
/// \brief Returns a copy of the matrix that has been component-wise subtracted by the other matrix.
inline float3x2 operator-( const float3x2& lhs, const float3x2& rhs );

/// \relates float3x2
/// \brief Returns a copy of the matrix that has been component-wise multiplied by the given scalar value.
inline float3x2 operator*( const float3x2& lhs, const float rhs );

/// \relates float3x2
/// \brief Multiplies each component of the matrix by the given scalar value.
inline float3x2 operator*=( float3x2& lhs, const float rhs );

/// \relates float3x2
/// \brief Returns a copy of the matrix where each row of the left-hand matrix has been dot-producted by the corresponding column of the right-hand matrix.
inline float3x3 operator*( const float3x2& lhs, const float2x3& rhs );

/// \relates float3x2
/// \brief Returns a copy of the matrix that has been component-wise divided by the given scalar value.
inline float3x2 operator/( const float3x2& lhs, const float rhs );

/// \relates float3x2
/// \brief Divides each component of the matrix by the given scalar value.
inline float3x2 operator/=( float3x2& lhs, const float rhs );

/// \relates float3x2
/// \brief Returns a copy of the matrix that has been component-wise divided by the other matrix.
inline float3x2 operator/( const float3x2& lhs, const float3x2& rhs );

/// \relates float3x2
/// \brief Returns a bool3x2 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool3x2 operator<( const float3x2& lhs, const float3x2& rhs );

/// \relates float3x2
/// \brief Returns a bool3x2 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool3x2 operator<=( const float3x2& lhs, const float3x2& rhs );

/// \relates float3x2
/// \brief Returns a bool3x2 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool3x2 operator>( const float3x2& lhs, const float3x2& rhs );

/// \relates float3x2
/// \brief Returns a bool3x2 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool3x2 operator>=( const float3x2& lhs, const float3x2& rhs );


// float3x3
/// \relates float3x3
/// \brief Returns a copy of the matrix that has been component-wise added by the given scalar value.
inline float3x3 operator+( const float3x3& lhs, const float rhs );

/// \relates float3x3
/// \brief Adds each component of the matrix by the given scalar value.
inline float3x3 operator+=( float3x3& lhs, const float rhs );

/// \relates float3x3
/// \brief Returns a copy of the matrix that has been component-wise added by the other matrix.
inline float3x3 operator+( const float3x3& lhs, const float3x3& rhs );

/// \relates float3x3
/// \brief Returns a copy of the matrix that has been component-wise subtracted by the given scalar value.
inline float3x3 operator-( const float3x3& lhs, const float rhs );

/// \relates float3x3
/// \brief Subtracts each component of the matrix by the given scalar value.
inline float3x3 operator-=( float3x3& lhs, const float rhs );

/// \relates float3x3
/// \brief Returns a copy of the matrix that has been component-wise subtracted by the other matrix.
inline float3x3 operator-( const float3x3& lhs, const float3x3& rhs );

/// \relates float3x3
/// \brief Returns a copy of the matrix that has been component-wise multiplied by the given scalar value.
inline float3x3 operator*( const float3x3& lhs, const float rhs );

/// \relates float3x3
/// \brief Multiplies each component of the matrix by the given scalar value.
inline float3x3 operator*=( float3x3& lhs, const float rhs );

/// \relates float3x3
/// \brief Returns a copy of the matrix where each row of the left-hand matrix has been dot-producted by the corresponding column of the right-hand matrix.
inline float3x3 operator*( const float3x3& lhs, const float3x3& rhs );

/// \relates float3x3
/// \brief Returns a copy of the matrix that has been component-wise divided by the given scalar value.
inline float3x3 operator/( const float3x3& lhs, const float rhs );

/// \relates float3x3
/// \brief Divides each component of the matrix by the given scalar value.
inline float3x3 operator/=( float3x3& lhs, const float rhs );

/// \relates float3x3
/// \brief Returns a copy of the matrix where the left-hand matrix has been mathematically multiplied by the inverse of the right-hand matrix.
inline float3x3 operator/( const float3x3& lhs, const float3x3& rhs );

/// \relates float3x3
/// \brief Returns a bool3x3 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool3x3 operator<( const float3x3& lhs, const float3x3& rhs );

/// \relates float3x3
/// \brief Returns a bool3x3 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool3x3 operator<=( const float3x3& lhs, const float3x3& rhs );

/// \relates float3x3
/// \brief Returns a bool3x3 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool3x3 operator>( const float3x3& lhs, const float3x3& rhs );

/// \relates float3x3
/// \brief Returns a bool3x3 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool3x3 operator>=( const float3x3& lhs, const float3x3& rhs );


// float3x4
/// \relates float3x4
/// \brief Returns a copy of the matrix that has been component-wise added by the given scalar value.
inline float3x4 operator+( const float3x4& lhs, const float rhs );

/// \relates float3x4
/// \brief Adds each component of the matrix by the given scalar value.
inline float3x4 operator+=( float3x4& lhs, const float rhs );

/// \relates float3x4
/// \brief Returns a copy of the matrix that has been component-wise added by the other matrix.
inline float3x4 operator+( const float3x4& lhs, const float3x4& rhs );

/// \relates float3x4
/// \brief Returns a copy of the matrix that has been component-wise subtracted by the given scalar value.
inline float3x4 operator-( const float3x4& lhs, const float rhs );

/// \relates float3x4
/// \brief Subtracts each component of the matrix by the given scalar value.
inline float3x4 operator-=( float3x4& lhs, const float rhs );

/// \relates float3x4
/// \brief Returns a copy of the matrix that has been component-wise subtracted by the other matrix.
inline float3x4 operator-( const float3x4& lhs, const float3x4& rhs );

/// \relates float3x4
/// \brief Returns a copy of the matrix that has been component-wise multiplied by the given scalar value.
inline float3x4 operator*( const float3x4& lhs, const float rhs );

/// \relates float3x4
/// \brief Multiplies each component of the matrix by the given scalar value.
inline float3x4 operator*=( float3x4& lhs, const float rhs );

/// \relates float3x4
/// \brief Returns a copy of the matrix where each row of the left-hand matrix has been dot-producted by the corresponding column of the right-hand matrix.
inline float3x3 operator*( const float3x4& lhs, const float4x3& rhs );

/// \relates float3x4
/// \brief Returns a copy of the matrix that has been component-wise divided by the given scalar value.
inline float3x4 operator/( const float3x4& lhs, const float rhs );

/// \relates float3x4
/// \brief Divides each component of the matrix by the given scalar value.
inline float3x4 operator/=( float3x4& lhs, const float rhs );

/// \relates float3x4
/// \brief Returns a copy of the matrix that has been component-wise divided by the other matrix.
inline float3x4 operator/( const float3x4& lhs, const float3x4& rhs );

/// \relates float3x4
/// \brief Returns a bool3x4 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool3x4 operator<( const float3x4& lhs, const float3x4& rhs );

/// \relates float3x4
/// \brief Returns a bool3x4 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool3x4 operator<=( const float3x4& lhs, const float3x4& rhs );

/// \relates float3x4
/// \brief Returns a bool3x4 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool3x4 operator>( const float3x4& lhs, const float3x4& rhs );

/// \relates float3x4
/// \brief Returns a bool3x4 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool3x4 operator>=( const float3x4& lhs, const float3x4& rhs );


// float4x2
/// \relates float4x2
/// \brief Returns a copy of the matrix that has been component-wise added by the given scalar value.
inline float4x2 operator+( const float4x2& lhs, const float rhs );

/// \relates float4x2
/// \brief Adds each component of the matrix by the given scalar value.
inline float4x2 operator+=( float4x2& lhs, const float rhs );

/// \relates float4x2
/// \brief Returns a copy of the matrix that has been component-wise added by the other matrix.
inline float4x2 operator+( const float4x2& lhs, const float4x2& rhs );

/// \relates float4x2
/// \brief Returns a copy of the matrix that has been component-wise subtracted by the given scalar value.
inline float4x2 operator-( const float4x2& lhs, const float rhs );

/// \relates float4x2
/// \brief Subtracts each component of the matrix by the given scalar value.
inline float4x2 operator-=( float4x2& lhs, const float rhs );

/// \relates float4x2
/// \brief Returns a copy of the matrix that has been component-wise subtracted by the other matrix.
inline float4x2 operator-( const float4x2& lhs, const float4x2& rhs );

/// \relates float4x2
/// \brief Returns a copy of the matrix that has been component-wise multiplied by the given scalar value.
inline float4x2 operator*( const float4x2& lhs, const float rhs );

/// \relates float4x2
/// \brief Multiplies each component of the matrix by the given scalar value.
inline float4x2 operator*=( float4x2& lhs, const float rhs );

/// \relates float4x2
/// \brief Returns a copy of the matrix where each row of the left-hand matrix has been dot-producted by the corresponding column of the right-hand matrix.
inline float4x4 operator*( const float4x2& lhs, const float2x4& rhs );

/// \relates float4x2
/// \brief Returns a copy of the matrix that has been component-wise divided by the given scalar value.
inline float4x2 operator/( const float4x2& lhs, const float rhs );

/// \relates float4x2
/// \brief Divides each component of the matrix by the given scalar value.
inline float4x2 operator/=( float4x2& lhs, const float rhs );

/// \relates float4x2
/// \brief Returns a copy of the matrix that has been component-wise divided by the other matrix.
inline float4x2 operator/( const float4x2& lhs, const float4x2& rhs );

/// \relates float4x2
/// \brief Returns a bool4x2 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool4x2 operator<( const float4x2& lhs, const float4x2& rhs );

/// \relates float4x2
/// \brief Returns a bool4x2 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool4x2 operator<=( const float4x2& lhs, const float4x2& rhs );

/// \relates float4x2
/// \brief Returns a bool4x2 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool4x2 operator>( const float4x2& lhs, const float4x2& rhs );

/// \relates float4x2
/// \brief Returns a bool4x2 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool4x2 operator>=( const float4x2& lhs, const float4x2& rhs );


// float4x3
/// \relates float4x3
/// \brief Returns a copy of the matrix that has been component-wise added by the given scalar value.
inline float4x3 operator+( const float4x3& lhs, const float rhs );

/// \relates float4x3
/// \brief Adds each component of the matrix by the given scalar value.
inline float4x3 operator+=( float4x3& lhs, const float rhs );

/// \relates float4x3
/// \brief Returns a copy of the matrix that has been component-wise added by the other matrix.
inline float4x3 operator+( const float4x3& lhs, const float4x3& rhs );

/// \relates float4x3
/// \brief Returns a copy of the matrix that has been component-wise subtracted by the given scalar value.
inline float4x3 operator-( const float4x3& lhs, const float rhs );

/// \relates float4x3
/// \brief Subtracts each component of the matrix by the given scalar value.
inline float4x3 operator-=( float4x3& lhs, const float rhs );

/// \relates float4x3
/// \brief Returns a copy of the matrix that has been component-wise subtracted by the other matrix.
inline float4x3 operator-( const float4x3& lhs, const float4x3& rhs );

/// \relates float4x3
/// \brief Returns a copy of the matrix that has been component-wise multiplied by the given scalar value.
inline float4x3 operator*( const float4x3& lhs, const float rhs );

/// \relates float4x3
/// \brief Multiplies each component of the matrix by the given scalar value.
inline float4x3 operator*=( float4x3& lhs, const float rhs );

/// \relates float4x3
/// \brief Returns a copy of the matrix where each row of the left-hand matrix has been dot-producted by the corresponding column of the right-hand matrix.
inline float4x4 operator*( const float4x3& lhs, const float3x4& rhs );

/// \relates float4x3
/// \brief Returns a copy of the matrix that has been component-wise divided by the given scalar value.
inline float4x3 operator/( const float4x3& lhs, const float rhs );

/// \relates float4x3
/// \brief Divides each component of the matrix by the given scalar value.
inline float4x3 operator/=( float4x3& lhs, const float rhs );

/// \relates float4x3
/// \brief Returns a copy of the matrix that has been component-wise divided by the other matrix.
inline float4x3 operator/( const float4x3& lhs, const float4x3& rhs );

/// \relates float4x3
/// \brief Returns a bool4x3 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool4x3 operator<( const float4x3& lhs, const float4x3& rhs );

/// \relates float4x3
/// \brief Returns a bool4x3 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool4x3 operator<=( const float4x3& lhs, const float4x3& rhs );

/// \relates float4x3
/// \brief Returns a bool4x3 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool4x3 operator>( const float4x3& lhs, const float4x3& rhs );

/// \relates float4x3
/// \brief Returns a bool4x3 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool4x3 operator>=( const float4x3& lhs, const float4x3& rhs );


// float4x4
/// \relates float4x4
/// \brief Returns a copy of the matrix that has been component-wise added by the given scalar value.
inline float4x4 operator+( const float4x4& lhs, const float rhs );

/// \relates float4x4
/// \brief Adds each component of the matrix by the given scalar value.
inline float4x4 operator+=( float4x4& lhs, const float rhs );

/// \relates float4x4
/// \brief Returns a copy of the matrix that has been component-wise added by the other matrix.
inline float4x4 operator+( const float4x4& lhs, const float4x4& rhs );

/// \relates float4x4
/// \brief Returns a copy of the matrix that has been component-wise subtracted by the given scalar value.
inline float4x4 operator-( const float4x4& lhs, const float rhs );

/// \relates float4x4
/// \brief Subtracts each component of the matrix by the given scalar value.
inline float4x4 operator-=( float4x4& lhs, const float rhs );

/// \relates float4x4
/// \brief Returns a copy of the matrix that has been component-wise subtracted by the other matrix.
inline float4x4 operator-( const float4x4& lhs, const float4x4& rhs );

/// \relates float4x4
/// \brief Returns a copy of the matrix that has been component-wise multiplied by the given scalar value.
inline float4x4 operator*( const float4x4& lhs, const float rhs );

/// \relates float4x4
/// \brief Multiplies each component of the matrix by the given scalar value.
inline float4x4 operator*=( float4x4& lhs, const float rhs );

/// \relates float4x4
/// \brief Returns a copy of the matrix where each row of the left-hand matrix has been dot-producted by the corresponding column of the right-hand matrix.
inline float4x4 operator*( const float4x4& lhs, const float4x4& rhs );

/// \relates float4x4
/// \brief Returns a copy of the matrix that has been component-wise divided by the given scalar value.
inline float4x4 operator/( const float4x4& lhs, const float rhs );

/// \relates float4x4
/// \brief Divides each component of the matrix by the given scalar value.
inline float4x4 operator/=( float4x4& lhs, const float rhs );

/// \relates float4x4
/// \brief Returns a copy of the matrix where the left-hand matrix has been mathematically multiplied by the inverse of the right-hand matrix.
inline float4x4 operator/( const float4x4& lhs, const float4x4& rhs );

/// \relates float4x4
/// \brief Returns a bool4x4 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool4x4 operator<( const float4x4& lhs, const float4x4& rhs );

/// \relates float4x4
/// \brief Returns a bool4x4 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool4x4 operator<=( const float4x4& lhs, const float4x4& rhs );

/// \relates float4x4
/// \brief Returns a bool4x4 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool4x4 operator>( const float4x4& lhs, const float4x4& rhs );

/// \relates float4x4
/// \brief Returns a bool4x4 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool4x4 operator>=( const float4x4& lhs, const float4x4& rhs );


// double2x2
/// \relates double2x2
/// \brief Returns a copy of the matrix that has been component-wise added by the given scalar value.
inline double2x2 operator+( const double2x2& lhs, const double rhs );

/// \relates double2x2
/// \brief Adds each component of the matrix by the given scalar value.
inline double2x2 operator+=( double2x2& lhs, const double rhs );

/// \relates double2x2
/// \brief Returns a copy of the matrix that has been component-wise added by the other matrix.
inline double2x2 operator+( const double2x2& lhs, const double2x2& rhs );

/// \relates double2x2
/// \brief Returns a copy of the matrix that has been component-wise subtracted by the given scalar value.
inline double2x2 operator-( const double2x2& lhs, const double rhs );

/// \relates double2x2
/// \brief Subtracts each component of the matrix by the given scalar value.
inline double2x2 operator-=( double2x2& lhs, const double rhs );

/// \relates double2x2
/// \brief Returns a copy of the matrix that has been component-wise subtracted by the other matrix.
inline double2x2 operator-( const double2x2& lhs, const double2x2& rhs );

/// \relates double2x2
/// \brief Returns a copy of the matrix that has been component-wise multiplied by the given scalar value.
inline double2x2 operator*( const double2x2& lhs, const double rhs );

/// \relates double2x2
/// \brief Multiplies each component of the matrix by the given scalar value.
inline double2x2 operator*=( double2x2& lhs, const double rhs );

/// \relates double2x2
/// \brief Returns a copy of the matrix where each row of the left-hand matrix has been dot-producted by the corresponding column of the right-hand matrix.
inline double2x2 operator*( const double2x2& lhs, const double2x2& rhs );

/// \relates double2x2
/// \brief Returns a copy of the matrix that has been component-wise divided by the given scalar value.
inline double2x2 operator/( const double2x2& lhs, const double rhs );

/// \relates double2x2
/// \brief Divides each component of the matrix by the given scalar value.
inline double2x2 operator/=( double2x2& lhs, const double rhs );

/// \relates double2x2
/// \brief Returns a copy of the matrix where the left-hand matrix has been mathematically multiplied by the inverse of the right-hand matrix.
inline double2x2 operator/( const double2x2& lhs, const double2x2& rhs );

/// \relates double2x2
/// \brief Returns a bool2x2 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool2x2 operator<( const double2x2& lhs, const double2x2& rhs );

/// \relates double2x2
/// \brief Returns a bool2x2 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool2x2 operator<=( const double2x2& lhs, const double2x2& rhs );

/// \relates double2x2
/// \brief Returns a bool2x2 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool2x2 operator>( const double2x2& lhs, const double2x2& rhs );

/// \relates double2x2
/// \brief Returns a bool2x2 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool2x2 operator>=( const double2x2& lhs, const double2x2& rhs );


// double2x3
/// \relates double2x3
/// \brief Returns a copy of the matrix that has been component-wise added by the given scalar value.
inline double2x3 operator+( const double2x3& lhs, const double rhs );

/// \relates double2x3
/// \brief Adds each component of the matrix by the given scalar value.
inline double2x3 operator+=( double2x3& lhs, const double rhs );

/// \relates double2x3
/// \brief Returns a copy of the matrix that has been component-wise added by the other matrix.
inline double2x3 operator+( const double2x3& lhs, const double2x3& rhs );

/// \relates double2x3
/// \brief Returns a copy of the matrix that has been component-wise subtracted by the given scalar value.
inline double2x3 operator-( const double2x3& lhs, const double rhs );

/// \relates double2x3
/// \brief Subtracts each component of the matrix by the given scalar value.
inline double2x3 operator-=( double2x3& lhs, const double rhs );

/// \relates double2x3
/// \brief Returns a copy of the matrix that has been component-wise subtracted by the other matrix.
inline double2x3 operator-( const double2x3& lhs, const double2x3& rhs );

/// \relates double2x3
/// \brief Returns a copy of the matrix that has been component-wise multiplied by the given scalar value.
inline double2x3 operator*( const double2x3& lhs, const double rhs );

/// \relates double2x3
/// \brief Multiplies each component of the matrix by the given scalar value.
inline double2x3 operator*=( double2x3& lhs, const double rhs );

/// \relates double2x3
/// \brief Returns a copy of the matrix where each row of the left-hand matrix has been dot-producted by the corresponding column of the right-hand matrix.
inline double2x2 operator*( const double2x3& lhs, const double3x2& rhs );

/// \relates double2x3
/// \brief Returns a copy of the matrix that has been component-wise divided by the given scalar value.
inline double2x3 operator/( const double2x3& lhs, const double rhs );

/// \relates double2x3
/// \brief Divides each component of the matrix by the given scalar value.
inline double2x3 operator/=( double2x3& lhs, const double rhs );

/// \relates double2x3
/// \brief Returns a copy of the matrix that has been component-wise divided by the other matrix.
inline double2x3 operator/( const double2x3& lhs, const double2x3& rhs );

/// \relates double2x3
/// \brief Returns a bool2x3 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool2x3 operator<( const double2x3& lhs, const double2x3& rhs );

/// \relates double2x3
/// \brief Returns a bool2x3 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool2x3 operator<=( const double2x3& lhs, const double2x3& rhs );

/// \relates double2x3
/// \brief Returns a bool2x3 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool2x3 operator>( const double2x3& lhs, const double2x3& rhs );

/// \relates double2x3
/// \brief Returns a bool2x3 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool2x3 operator>=( const double2x3& lhs, const double2x3& rhs );


// double2x4
/// \relates double2x4
/// \brief Returns a copy of the matrix that has been component-wise added by the given scalar value.
inline double2x4 operator+( const double2x4& lhs, const double rhs );

/// \relates double2x4
/// \brief Adds each component of the matrix by the given scalar value.
inline double2x4 operator+=( double2x4& lhs, const double rhs );

/// \relates double2x4
/// \brief Returns a copy of the matrix that has been component-wise added by the other matrix.
inline double2x4 operator+( const double2x4& lhs, const double2x4& rhs );

/// \relates double2x4
/// \brief Returns a copy of the matrix that has been component-wise subtracted by the given scalar value.
inline double2x4 operator-( const double2x4& lhs, const double rhs );

/// \relates double2x4
/// \brief Subtracts each component of the matrix by the given scalar value.
inline double2x4 operator-=( double2x4& lhs, const double rhs );

/// \relates double2x4
/// \brief Returns a copy of the matrix that has been component-wise subtracted by the other matrix.
inline double2x4 operator-( const double2x4& lhs, const double2x4& rhs );

/// \relates double2x4
/// \brief Returns a copy of the matrix that has been component-wise multiplied by the given scalar value.
inline double2x4 operator*( const double2x4& lhs, const double rhs );

/// \relates double2x4
/// \brief Multiplies each component of the matrix by the given scalar value.
inline double2x4 operator*=( double2x4& lhs, const double rhs );

/// \relates double2x4
/// \brief Returns a copy of the matrix where each row of the left-hand matrix has been dot-producted by the corresponding column of the right-hand matrix.
inline double2x2 operator*( const double2x4& lhs, const double4x2& rhs );

/// \relates double2x4
/// \brief Returns a copy of the matrix that has been component-wise divided by the given scalar value.
inline double2x4 operator/( const double2x4& lhs, const double rhs );

/// \relates double2x4
/// \brief Divides each component of the matrix by the given scalar value.
inline double2x4 operator/=( double2x4& lhs, const double rhs );

/// \relates double2x4
/// \brief Returns a copy of the matrix that has been component-wise divided by the other matrix.
inline double2x4 operator/( const double2x4& lhs, const double2x4& rhs );

/// \relates double2x4
/// \brief Returns a bool2x4 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool2x4 operator<( const double2x4& lhs, const double2x4& rhs );

/// \relates double2x4
/// \brief Returns a bool2x4 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool2x4 operator<=( const double2x4& lhs, const double2x4& rhs );

/// \relates double2x4
/// \brief Returns a bool2x4 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool2x4 operator>( const double2x4& lhs, const double2x4& rhs );

/// \relates double2x4
/// \brief Returns a bool2x4 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool2x4 operator>=( const double2x4& lhs, const double2x4& rhs );


// double3x2
/// \relates double3x2
/// \brief Returns a copy of the matrix that has been component-wise added by the given scalar value.
inline double3x2 operator+( const double3x2& lhs, const double rhs );

/// \relates double3x2
/// \brief Adds each component of the matrix by the given scalar value.
inline double3x2 operator+=( double3x2& lhs, const double rhs );

/// \relates double3x2
/// \brief Returns a copy of the matrix that has been component-wise added by the other matrix.
inline double3x2 operator+( const double3x2& lhs, const double3x2& rhs );

/// \relates double3x2
/// \brief Returns a copy of the matrix that has been component-wise subtracted by the given scalar value.
inline double3x2 operator-( const double3x2& lhs, const double rhs );

/// \relates double3x2
/// \brief Subtracts each component of the matrix by the given scalar value.
inline double3x2 operator-=( double3x2& lhs, const double rhs );

/// \relates double3x2
/// \brief Returns a copy of the matrix that has been component-wise subtracted by the other matrix.
inline double3x2 operator-( const double3x2& lhs, const double3x2& rhs );

/// \relates double3x2
/// \brief Returns a copy of the matrix that has been component-wise multiplied by the given scalar value.
inline double3x2 operator*( const double3x2& lhs, const double rhs );

/// \relates double3x2
/// \brief Multiplies each component of the matrix by the given scalar value.
inline double3x2 operator*=( double3x2& lhs, const double rhs );

/// \relates double3x2
/// \brief Returns a copy of the matrix where each row of the left-hand matrix has been dot-producted by the corresponding column of the right-hand matrix.
inline double3x3 operator*( const double3x2& lhs, const double2x3& rhs );

/// \relates double3x2
/// \brief Returns a copy of the matrix that has been component-wise divided by the given scalar value.
inline double3x2 operator/( const double3x2& lhs, const double rhs );

/// \relates double3x2
/// \brief Divides each component of the matrix by the given scalar value.
inline double3x2 operator/=( double3x2& lhs, const double rhs );

/// \relates double3x2
/// \brief Returns a copy of the matrix that has been component-wise divided by the other matrix.
inline double3x2 operator/( const double3x2& lhs, const double3x2& rhs );

/// \relates double3x2
/// \brief Returns a bool3x2 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool3x2 operator<( const double3x2& lhs, const double3x2& rhs );

/// \relates double3x2
/// \brief Returns a bool3x2 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool3x2 operator<=( const double3x2& lhs, const double3x2& rhs );

/// \relates double3x2
/// \brief Returns a bool3x2 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool3x2 operator>( const double3x2& lhs, const double3x2& rhs );

/// \relates double3x2
/// \brief Returns a bool3x2 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool3x2 operator>=( const double3x2& lhs, const double3x2& rhs );


// double3x3
/// \relates double3x3
/// \brief Returns a copy of the matrix that has been component-wise added by the given scalar value.
inline double3x3 operator+( const double3x3& lhs, const double rhs );

/// \relates double3x3
/// \brief Adds each component of the matrix by the given scalar value.
inline double3x3 operator+=( double3x3& lhs, const double rhs );

/// \relates double3x3
/// \brief Returns a copy of the matrix that has been component-wise added by the other matrix.
inline double3x3 operator+( const double3x3& lhs, const double3x3& rhs );

/// \relates double3x3
/// \brief Returns a copy of the matrix that has been component-wise subtracted by the given scalar value.
inline double3x3 operator-( const double3x3& lhs, const double rhs );

/// \relates double3x3
/// \brief Subtracts each component of the matrix by the given scalar value.
inline double3x3 operator-=( double3x3& lhs, const double rhs );

/// \relates double3x3
/// \brief Returns a copy of the matrix that has been component-wise subtracted by the other matrix.
inline double3x3 operator-( const double3x3& lhs, const double3x3& rhs );

/// \relates double3x3
/// \brief Returns a copy of the matrix that has been component-wise multiplied by the given scalar value.
inline double3x3 operator*( const double3x3& lhs, const double rhs );

/// \relates double3x3
/// \brief Multiplies each component of the matrix by the given scalar value.
inline double3x3 operator*=( double3x3& lhs, const double rhs );

/// \relates double3x3
/// \brief Returns a copy of the matrix where each row of the left-hand matrix has been dot-producted by the corresponding column of the right-hand matrix.
inline double3x3 operator*( const double3x3& lhs, const double3x3& rhs );

/// \relates double3x3
/// \brief Returns a copy of the matrix that has been component-wise divided by the given scalar value.
inline double3x3 operator/( const double3x3& lhs, const double rhs );

/// \relates double3x3
/// \brief Divides each component of the matrix by the given scalar value.
inline double3x3 operator/=( double3x3& lhs, const double rhs );

/// \relates double3x3
/// \brief Returns a copy of the matrix where the left-hand matrix has been mathematically multiplied by the inverse of the right-hand matrix.
inline double3x3 operator/( const double3x3& lhs, const double3x3& rhs );

/// \relates double3x3
/// \brief Returns a bool3x3 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool3x3 operator<( const double3x3& lhs, const double3x3& rhs );

/// \relates double3x3
/// \brief Returns a bool3x3 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool3x3 operator<=( const double3x3& lhs, const double3x3& rhs );

/// \relates double3x3
/// \brief Returns a bool3x3 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool3x3 operator>( const double3x3& lhs, const double3x3& rhs );

/// \relates double3x3
/// \brief Returns a bool3x3 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool3x3 operator>=( const double3x3& lhs, const double3x3& rhs );


// double3x4
/// \relates double3x4
/// \brief Returns a copy of the matrix that has been component-wise added by the given scalar value.
inline double3x4 operator+( const double3x4& lhs, const double rhs );

/// \relates double3x4
/// \brief Adds each component of the matrix by the given scalar value.
inline double3x4 operator+=( double3x4& lhs, const double rhs );

/// \relates double3x4
/// \brief Returns a copy of the matrix that has been component-wise added by the other matrix.
inline double3x4 operator+( const double3x4& lhs, const double3x4& rhs );

/// \relates double3x4
/// \brief Returns a copy of the matrix that has been component-wise subtracted by the given scalar value.
inline double3x4 operator-( const double3x4& lhs, const double rhs );

/// \relates double3x4
/// \brief Subtracts each component of the matrix by the given scalar value.
inline double3x4 operator-=( double3x4& lhs, const double rhs );

/// \relates double3x4
/// \brief Returns a copy of the matrix that has been component-wise subtracted by the other matrix.
inline double3x4 operator-( const double3x4& lhs, const double3x4& rhs );

/// \relates double3x4
/// \brief Returns a copy of the matrix that has been component-wise multiplied by the given scalar value.
inline double3x4 operator*( const double3x4& lhs, const double rhs );

/// \relates double3x4
/// \brief Multiplies each component of the matrix by the given scalar value.
inline double3x4 operator*=( double3x4& lhs, const double rhs );

/// \relates double3x4
/// \brief Returns a copy of the matrix where each row of the left-hand matrix has been dot-producted by the corresponding column of the right-hand matrix.
inline double3x3 operator*( const double3x4& lhs, const double4x3& rhs );

/// \relates double3x4
/// \brief Returns a copy of the matrix that has been component-wise divided by the given scalar value.
inline double3x4 operator/( const double3x4& lhs, const double rhs );

/// \relates double3x4
/// \brief Divides each component of the matrix by the given scalar value.
inline double3x4 operator/=( double3x4& lhs, const double rhs );

/// \relates double3x4
/// \brief Returns a copy of the matrix that has been component-wise divided by the other matrix.
inline double3x4 operator/( const double3x4& lhs, const double3x4& rhs );

/// \relates double3x4
/// \brief Returns a bool3x4 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool3x4 operator<( const double3x4& lhs, const double3x4& rhs );

/// \relates double3x4
/// \brief Returns a bool3x4 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool3x4 operator<=( const double3x4& lhs, const double3x4& rhs );

/// \relates double3x4
/// \brief Returns a bool3x4 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool3x4 operator>( const double3x4& lhs, const double3x4& rhs );

/// \relates double3x4
/// \brief Returns a bool3x4 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool3x4 operator>=( const double3x4& lhs, const double3x4& rhs );


// double4x2
/// \relates double4x2
/// \brief Returns a copy of the matrix that has been component-wise added by the given scalar value.
inline double4x2 operator+( const double4x2& lhs, const double rhs );

/// \relates double4x2
/// \brief Adds each component of the matrix by the given scalar value.
inline double4x2 operator+=( double4x2& lhs, const double rhs );

/// \relates double4x2
/// \brief Returns a copy of the matrix that has been component-wise added by the other matrix.
inline double4x2 operator+( const double4x2& lhs, const double4x2& rhs );

/// \relates double4x2
/// \brief Returns a copy of the matrix that has been component-wise subtracted by the given scalar value.
inline double4x2 operator-( const double4x2& lhs, const double rhs );

/// \relates double4x2
/// \brief Subtracts each component of the matrix by the given scalar value.
inline double4x2 operator-=( double4x2& lhs, const double rhs );

/// \relates double4x2
/// \brief Returns a copy of the matrix that has been component-wise subtracted by the other matrix.
inline double4x2 operator-( const double4x2& lhs, const double4x2& rhs );

/// \relates double4x2
/// \brief Returns a copy of the matrix that has been component-wise multiplied by the given scalar value.
inline double4x2 operator*( const double4x2& lhs, const double rhs );

/// \relates double4x2
/// \brief Multiplies each component of the matrix by the given scalar value.
inline double4x2 operator*=( double4x2& lhs, const double rhs );

/// \relates double4x2
/// \brief Returns a copy of the matrix where each row of the left-hand matrix has been dot-producted by the corresponding column of the right-hand matrix.
inline double4x4 operator*( const double4x2& lhs, const double2x4& rhs );

/// \relates double4x2
/// \brief Returns a copy of the matrix that has been component-wise divided by the given scalar value.
inline double4x2 operator/( const double4x2& lhs, const double rhs );

/// \relates double4x2
/// \brief Divides each component of the matrix by the given scalar value.
inline double4x2 operator/=( double4x2& lhs, const double rhs );

/// \relates double4x2
/// \brief Returns a copy of the matrix that has been component-wise divided by the other matrix.
inline double4x2 operator/( const double4x2& lhs, const double4x2& rhs );

/// \relates double4x2
/// \brief Returns a bool4x2 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool4x2 operator<( const double4x2& lhs, const double4x2& rhs );

/// \relates double4x2
/// \brief Returns a bool4x2 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool4x2 operator<=( const double4x2& lhs, const double4x2& rhs );

/// \relates double4x2
/// \brief Returns a bool4x2 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool4x2 operator>( const double4x2& lhs, const double4x2& rhs );

/// \relates double4x2
/// \brief Returns a bool4x2 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool4x2 operator>=( const double4x2& lhs, const double4x2& rhs );


// double4x3
/// \relates double4x3
/// \brief Returns a copy of the matrix that has been component-wise added by the given scalar value.
inline double4x3 operator+( const double4x3& lhs, const double rhs );

/// \relates double4x3
/// \brief Adds each component of the matrix by the given scalar value.
inline double4x3 operator+=( double4x3& lhs, const double rhs );

/// \relates double4x3
/// \brief Returns a copy of the matrix that has been component-wise added by the other matrix.
inline double4x3 operator+( const double4x3& lhs, const double4x3& rhs );

/// \relates double4x3
/// \brief Returns a copy of the matrix that has been component-wise subtracted by the given scalar value.
inline double4x3 operator-( const double4x3& lhs, const double rhs );

/// \relates double4x3
/// \brief Subtracts each component of the matrix by the given scalar value.
inline double4x3 operator-=( double4x3& lhs, const double rhs );

/// \relates double4x3
/// \brief Returns a copy of the matrix that has been component-wise subtracted by the other matrix.
inline double4x3 operator-( const double4x3& lhs, const double4x3& rhs );

/// \relates double4x3
/// \brief Returns a copy of the matrix that has been component-wise multiplied by the given scalar value.
inline double4x3 operator*( const double4x3& lhs, const double rhs );

/// \relates double4x3
/// \brief Multiplies each component of the matrix by the given scalar value.
inline double4x3 operator*=( double4x3& lhs, const double rhs );

/// \relates double4x3
/// \brief Returns a copy of the matrix where each row of the left-hand matrix has been dot-producted by the corresponding column of the right-hand matrix.
inline double4x4 operator*( const double4x3& lhs, const double3x4& rhs );

/// \relates double4x3
/// \brief Returns a copy of the matrix that has been component-wise divided by the given scalar value.
inline double4x3 operator/( const double4x3& lhs, const double rhs );

/// \relates double4x3
/// \brief Divides each component of the matrix by the given scalar value.
inline double4x3 operator/=( double4x3& lhs, const double rhs );

/// \relates double4x3
/// \brief Returns a copy of the matrix that has been component-wise divided by the other matrix.
inline double4x3 operator/( const double4x3& lhs, const double4x3& rhs );

/// \relates double4x3
/// \brief Returns a bool4x3 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool4x3 operator<( const double4x3& lhs, const double4x3& rhs );

/// \relates double4x3
/// \brief Returns a bool4x3 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool4x3 operator<=( const double4x3& lhs, const double4x3& rhs );

/// \relates double4x3
/// \brief Returns a bool4x3 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool4x3 operator>( const double4x3& lhs, const double4x3& rhs );

/// \relates double4x3
/// \brief Returns a bool4x3 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool4x3 operator>=( const double4x3& lhs, const double4x3& rhs );


// double4x4
/// \relates double4x4
/// \brief Returns a copy of the matrix that has been component-wise added by the given scalar value.
inline double4x4 operator+( const double4x4& lhs, const double rhs );

/// \relates double4x4
/// \brief Adds each component of the matrix by the given scalar value.
inline double4x4 operator+=( double4x4& lhs, const double rhs );

/// \relates double4x4
/// \brief Returns a copy of the matrix that has been component-wise added by the other matrix.
inline double4x4 operator+( const double4x4& lhs, const double4x4& rhs );

/// \relates double4x4
/// \brief Returns a copy of the matrix that has been component-wise subtracted by the given scalar value.
inline double4x4 operator-( const double4x4& lhs, const double rhs );

/// \relates double4x4
/// \brief Subtracts each component of the matrix by the given scalar value.
inline double4x4 operator-=( double4x4& lhs, const double rhs );

/// \relates double4x4
/// \brief Returns a copy of the matrix that has been component-wise subtracted by the other matrix.
inline double4x4 operator-( const double4x4& lhs, const double4x4& rhs );

/// \relates double4x4
/// \brief Returns a copy of the matrix that has been component-wise multiplied by the given scalar value.
inline double4x4 operator*( const double4x4& lhs, const double rhs );

/// \relates double4x4
/// \brief Multiplies each component of the matrix by the given scalar value.
inline double4x4 operator*=( double4x4& lhs, const double rhs );

/// \relates double4x4
/// \brief Returns a copy of the matrix where each row of the left-hand matrix has been dot-producted by the corresponding column of the right-hand matrix.
inline double4x4 operator*( const double4x4& lhs, const double4x4& rhs );

/// \relates double4x4
/// \brief Returns a copy of the matrix that has been component-wise divided by the given scalar value.
inline double4x4 operator/( const double4x4& lhs, const double rhs );

/// \relates double4x4
/// \brief Divides each component of the matrix by the given scalar value.
inline double4x4 operator/=( double4x4& lhs, const double rhs );

/// \relates double4x4
/// \brief Returns a copy of the matrix where the left-hand matrix has been mathematically multiplied by the inverse of the right-hand matrix.
inline double4x4 operator/( const double4x4& lhs, const double4x4& rhs );

/// \relates double4x4
/// \brief Returns a bool4x4 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool4x4 operator<( const double4x4& lhs, const double4x4& rhs );

/// \relates double4x4
/// \brief Returns a bool4x4 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool4x4 operator<=( const double4x4& lhs, const double4x4& rhs );

/// \relates double4x4
/// \brief Returns a bool4x4 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool4x4 operator>( const double4x4& lhs, const double4x4& rhs );

/// \relates double4x4
/// \brief Returns a bool4x4 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool4x4 operator>=( const double4x4& lhs, const double4x4& rhs );


#include "hlml_operators_matrix.inl"

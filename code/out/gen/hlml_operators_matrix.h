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
/// \brief Returns a copy of the int2x2 that has been component-wise added by the given scalar value.
inline int2x2 operator+( const int2x2& lhs, const int32_t rhs );

/// \relates int2x2
/// \brief Adds each component by the given scalar value.
inline int2x2 operator+=( int2x2& lhs, const int32_t rhs );

/// \relates int2x2
/// \brief Returns a copy of the int2x2 that has been component-wise added by the corresponding component of the right-hand int2x2.
inline int2x2 operator+( const int2x2& lhs, const int2x2& rhs );

/// \relates int2x2
/// \brief Adds each component of the int2x2 by the corresponding component of the right-hand int2x2.
inline int2x2 operator+=( int2x2& lhs, const int2x2& rhs );

/// \relates int2x2
/// \brief Returns a copy of the int2x2 that has been component-wise subtracted by the given scalar value.
inline int2x2 operator-( const int2x2& lhs, const int32_t rhs );

/// \relates int2x2
/// \brief Subtracts each component by the given scalar value.
inline int2x2 operator-=( int2x2& lhs, const int32_t rhs );

/// \relates int2x2
/// \brief Returns a copy of the int2x2 that has been component-wise subtracted by the corresponding component of the right-hand int2x2.
inline int2x2 operator-( const int2x2& lhs, const int2x2& rhs );

/// \relates int2x2
/// \brief Subtracts each component of the int2x2 by the corresponding component of the right-hand int2x2.
inline int2x2 operator-=( int2x2& lhs, const int2x2& rhs );

/// \relates int2x2
/// \brief Returns a copy of the int2x2 that has been component-wise multiplied by the given scalar value.
inline int2x2 operator*( const int2x2& lhs, const int32_t rhs );

/// \relates int2x2
/// \brief Multiplies each component by the given scalar value.
inline int2x2 operator*=( int2x2& lhs, const int32_t rhs );

/// \relates int2x2
/// \brief Returns a copy of the matrix where each row of the left-hand matrix has been dot-producted by the corresponding column of the right-hand matrix.
inline int2x2 operator*( const int2x2& lhs, const int2x2& rhs );

/// \relates int2x2
/// \brief Dot products each row of the left-hand matrix with the corresponding column of the right-hand matrix.
inline int2x2 operator*=( int2x2& lhs, const int2x2& rhs );

/// \relates int2x2
/// \brief Returns a copy of the int2x2 that has been component-wise divided by the given scalar value.
inline int2x2 operator/( const int2x2& lhs, const int32_t rhs );

/// \relates int2x2
/// \brief Divides each component by the given scalar value.
inline int2x2 operator/=( int2x2& lhs, const int32_t rhs );

/// \relates int2x2
/// \brief Returns a copy of the int2x2 that has been component-wise divided by the corresponding component of the right-hand int2x2.
inline int2x2 operator/( const int2x2& lhs, const int2x2& rhs );

/// \relates int2x2
/// \brief Divides each component of the int2x2 by the corresponding component of the right-hand int2x2.
inline int2x2 operator/=( int2x2& lhs, const int2x2& rhs );

/// \relates int2x2
/// \brief Prefix increment operator.  Adds one to each component of the given int2x2 before evaluation.
inline int2x2& operator++( int2x2& lhs );

/// \relates int2x2
/// \brief Postfix increment operator.  Adds one to each component of the given int2x2 after evaluation.
inline int2x2& operator++( int2x2& lhs, const int );

/// \relates int2x2
/// \brief Prefix decrement operator.  Subtracts one from each component of the given int2x2 before evaluation.
inline int2x2& operator--( int2x2& lhs );

/// \relates int2x2
/// \brief Postfix decrement operator.  Subtracts one from each component of the given int2x2 after evaluation.
inline int2x2& operator--( int2x2& lhs, const int );

/// \relates int2x2
/// \brief Returns a bool2x2 where each component is true if the component of the left-hand type is less than the corresponding right-hand type component.
inline bool2x2 operator<( const int2x2& lhs, const int2x2& rhs );

/// \relates int2x2
/// \brief Returns a bool2x2 where each component is true if the component of the left-hand type is less than or equal to the corresponding right-hand type component.
inline bool2x2 operator<=( const int2x2& lhs, const int2x2& rhs );

/// \relates int2x2
/// \brief Returns a bool2x2 where each component is true if the component of the left-hand type is greater than the corresponding right-hand type component.
inline bool2x2 operator>( const int2x2& lhs, const int2x2& rhs );

/// \relates int2x2
/// \brief Returns a bool2x2 where each component is true if the component of the left-hand type is greater than or equal to the corresponding right-hand type component.
inline bool2x2 operator>=( const int2x2& lhs, const int2x2& rhs );

/// \relates int2x2
/// \brief Returns a copy of the int2x2 where each component has been bitwise AND'd against the given scalar value.
inline int2x2 operator&( const int2x2& lhs, const int32_t& rhs );

/// \relates int2x2
/// \brief Performs a bitwise AND on the given left-hand int2x2 against the given scalar value.
inline int2x2 operator&=( int2x2& lhs, const int32_t& rhs );

/// \relates int2x2
/// \brief Returns a copy of the int2x2 where each component of the left-hand int2x2 has been bitwise AND'd against the corresponding component of the right-hand side int2x2.
inline int2x2 operator&( const int2x2& lhs, const int2x2& rhs );

/// \relates int2x2
/// \brief Performs a bitwise AND on the given left-hand int2x2 against the corresponding component of the given right-hand int2x2.
inline int2x2 operator&=( int2x2& lhs, const int2x2& rhs );

/// \relates int2x2
/// \brief Returns a copy of the int2x2 where each component has been bitwise OR'd against the given scalar value.
inline int2x2 operator|( const int2x2& lhs, const int32_t& rhs );

/// \relates int2x2
/// \brief Performs a bitwise OR on the given left-hand int2x2 against the given scalar value.
inline int2x2 operator|=( int2x2& lhs, const int32_t& rhs );

/// \relates int2x2
/// \brief Returns a copy of the int2x2 where each component of the left-hand int2x2 has been bitwise OR'd against the corresponding component of the right-hand side int2x2.
inline int2x2 operator|( const int2x2& lhs, const int2x2& rhs );

/// \relates int2x2
/// \brief Performs a bitwise OR on the given left-hand int2x2 against the corresponding component of the given right-hand int2x2.
inline int2x2 operator|=( int2x2& lhs, const int2x2& rhs );

/// \relates int2x2
/// \brief Returns a copy of the int2x2 where each component has been bitwise XOR'd against the given scalar value.
inline int2x2 operator^( const int2x2& lhs, const int32_t& rhs );

/// \relates int2x2
/// \brief Performs a bitwise XOR on the given left-hand int2x2 against the given scalar value.
inline int2x2 operator^=( int2x2& lhs, const int32_t& rhs );

/// \relates int2x2
/// \brief Returns a copy of the int2x2 where each component of the left-hand int2x2 has been bitwise XOR'd against the corresponding component of the right-hand side int2x2.
inline int2x2 operator^( const int2x2& lhs, const int2x2& rhs );

/// \relates int2x2
/// \brief Performs a bitwise XOR on the given left-hand int2x2 against the corresponding component of the given right-hand int2x2.
inline int2x2 operator^=( int2x2& lhs, const int2x2& rhs );

/// \relates int2x2
/// \brief Returns a copy of the int2x2 where each component has been bitwise left-shifted by the given scalar value.
inline int2x2 operator<<( const int2x2& lhs, const int32_t& rhs );

/// \relates int2x2
/// \brief Performs a left bitshift on the given left-hand int2x2 by the given scalar value.
inline int2x2 operator<<=( int2x2& lhs, const int32_t& rhs );

/// \relates int2x2
/// \brief Returns a copy of the int2x2 where each component of the left-hand int2x2 has been bitwise left-shifted by the corresponding component of the right-hand side int2x2.
inline int2x2 operator<<( const int2x2& lhs, const int2x2& rhs );

/// \relates int2x2
/// \brief Performs a left bitshift on the given left-hand int2x2 by the corresponding component of the given right-hand int2x2.
inline int2x2 operator<<=( int2x2& lhs, const int2x2& rhs );

/// \relates int2x2
/// \brief Returns a copy of the int2x2 where each component has been bitwise right-shifted by the given scalar value.
inline int2x2 operator>>( const int2x2& lhs, const int32_t& rhs );

/// \relates int2x2
/// \brief Performs a right bitshift on the given left-hand int2x2 by the given scalar value.
inline int2x2 operator>>=( int2x2& lhs, const int32_t& rhs );

/// \relates int2x2
/// \brief Returns a copy of the int2x2 where each component of the left-hand int2x2 has been bitwise right-shifted by the corresponding component of the right-hand side int2x2.
inline int2x2 operator>>( const int2x2& lhs, const int2x2& rhs );

/// \relates int2x2
/// \brief Performs a right bitshift on the given left-hand int2x2 by the corresponding component of the given right-hand int2x2.
inline int2x2 operator>>=( int2x2& lhs, const int2x2& rhs );

/// \relates int2x2
/// \brief Performs a unary bitwise operation on all components of the given int2x2.
inline int2x2 operator~( const int2x2& lhs );


// int2x3
/// \relates int2x3
/// \brief Returns a copy of the int2x3 that has been component-wise added by the given scalar value.
inline int2x3 operator+( const int2x3& lhs, const int32_t rhs );

/// \relates int2x3
/// \brief Adds each component by the given scalar value.
inline int2x3 operator+=( int2x3& lhs, const int32_t rhs );

/// \relates int2x3
/// \brief Returns a copy of the int2x3 that has been component-wise added by the corresponding component of the right-hand int2x3.
inline int2x3 operator+( const int2x3& lhs, const int2x3& rhs );

/// \relates int2x3
/// \brief Adds each component of the int2x3 by the corresponding component of the right-hand int2x3.
inline int2x3 operator+=( int2x3& lhs, const int2x3& rhs );

/// \relates int2x3
/// \brief Returns a copy of the int2x3 that has been component-wise subtracted by the given scalar value.
inline int2x3 operator-( const int2x3& lhs, const int32_t rhs );

/// \relates int2x3
/// \brief Subtracts each component by the given scalar value.
inline int2x3 operator-=( int2x3& lhs, const int32_t rhs );

/// \relates int2x3
/// \brief Returns a copy of the int2x3 that has been component-wise subtracted by the corresponding component of the right-hand int2x3.
inline int2x3 operator-( const int2x3& lhs, const int2x3& rhs );

/// \relates int2x3
/// \brief Subtracts each component of the int2x3 by the corresponding component of the right-hand int2x3.
inline int2x3 operator-=( int2x3& lhs, const int2x3& rhs );

/// \relates int2x3
/// \brief Returns a copy of the int2x3 that has been component-wise multiplied by the given scalar value.
inline int2x3 operator*( const int2x3& lhs, const int32_t rhs );

/// \relates int2x3
/// \brief Multiplies each component by the given scalar value.
inline int2x3 operator*=( int2x3& lhs, const int32_t rhs );

/// \relates int2x3
/// \brief Returns a copy of the matrix where each row of the left-hand matrix has been dot-producted by the corresponding column of the right-hand matrix.
inline int2x2 operator*( const int2x3& lhs, const int3x2& rhs );

/// \relates int2x3
/// \brief Dot products each row of the left-hand matrix with the corresponding column of the right-hand matrix.
inline int2x2 operator*=( int2x3& lhs, const int3x2& rhs );

/// \relates int2x3
/// \brief Returns a copy of the int2x3 that has been component-wise divided by the given scalar value.
inline int2x3 operator/( const int2x3& lhs, const int32_t rhs );

/// \relates int2x3
/// \brief Divides each component by the given scalar value.
inline int2x3 operator/=( int2x3& lhs, const int32_t rhs );

/// \relates int2x3
/// \brief Returns a copy of the int2x3 that has been component-wise divided by the corresponding component of the right-hand int2x3.
inline int2x3 operator/( const int2x3& lhs, const int2x3& rhs );

/// \relates int2x3
/// \brief Prefix increment operator.  Adds one to each component of the given int2x3 before evaluation.
inline int2x3& operator++( int2x3& lhs );

/// \relates int2x3
/// \brief Postfix increment operator.  Adds one to each component of the given int2x3 after evaluation.
inline int2x3& operator++( int2x3& lhs, const int );

/// \relates int2x3
/// \brief Prefix decrement operator.  Subtracts one from each component of the given int2x3 before evaluation.
inline int2x3& operator--( int2x3& lhs );

/// \relates int2x3
/// \brief Postfix decrement operator.  Subtracts one from each component of the given int2x3 after evaluation.
inline int2x3& operator--( int2x3& lhs, const int );

/// \relates int2x3
/// \brief Returns a bool2x3 where each component is true if the component of the left-hand type is less than the corresponding right-hand type component.
inline bool2x3 operator<( const int2x3& lhs, const int2x3& rhs );

/// \relates int2x3
/// \brief Returns a bool2x3 where each component is true if the component of the left-hand type is less than or equal to the corresponding right-hand type component.
inline bool2x3 operator<=( const int2x3& lhs, const int2x3& rhs );

/// \relates int2x3
/// \brief Returns a bool2x3 where each component is true if the component of the left-hand type is greater than the corresponding right-hand type component.
inline bool2x3 operator>( const int2x3& lhs, const int2x3& rhs );

/// \relates int2x3
/// \brief Returns a bool2x3 where each component is true if the component of the left-hand type is greater than or equal to the corresponding right-hand type component.
inline bool2x3 operator>=( const int2x3& lhs, const int2x3& rhs );

/// \relates int2x3
/// \brief Returns a copy of the int2x3 where each component has been bitwise AND'd against the given scalar value.
inline int2x3 operator&( const int2x3& lhs, const int32_t& rhs );

/// \relates int2x3
/// \brief Performs a bitwise AND on the given left-hand int2x3 against the given scalar value.
inline int2x3 operator&=( int2x3& lhs, const int32_t& rhs );

/// \relates int2x3
/// \brief Returns a copy of the int2x3 where each component of the left-hand int2x3 has been bitwise AND'd against the corresponding component of the right-hand side int2x3.
inline int2x3 operator&( const int2x3& lhs, const int2x3& rhs );

/// \relates int2x3
/// \brief Performs a bitwise AND on the given left-hand int2x3 against the corresponding component of the given right-hand int2x3.
inline int2x3 operator&=( int2x3& lhs, const int2x3& rhs );

/// \relates int2x3
/// \brief Returns a copy of the int2x3 where each component has been bitwise OR'd against the given scalar value.
inline int2x3 operator|( const int2x3& lhs, const int32_t& rhs );

/// \relates int2x3
/// \brief Performs a bitwise OR on the given left-hand int2x3 against the given scalar value.
inline int2x3 operator|=( int2x3& lhs, const int32_t& rhs );

/// \relates int2x3
/// \brief Returns a copy of the int2x3 where each component of the left-hand int2x3 has been bitwise OR'd against the corresponding component of the right-hand side int2x3.
inline int2x3 operator|( const int2x3& lhs, const int2x3& rhs );

/// \relates int2x3
/// \brief Performs a bitwise OR on the given left-hand int2x3 against the corresponding component of the given right-hand int2x3.
inline int2x3 operator|=( int2x3& lhs, const int2x3& rhs );

/// \relates int2x3
/// \brief Returns a copy of the int2x3 where each component has been bitwise XOR'd against the given scalar value.
inline int2x3 operator^( const int2x3& lhs, const int32_t& rhs );

/// \relates int2x3
/// \brief Performs a bitwise XOR on the given left-hand int2x3 against the given scalar value.
inline int2x3 operator^=( int2x3& lhs, const int32_t& rhs );

/// \relates int2x3
/// \brief Returns a copy of the int2x3 where each component of the left-hand int2x3 has been bitwise XOR'd against the corresponding component of the right-hand side int2x3.
inline int2x3 operator^( const int2x3& lhs, const int2x3& rhs );

/// \relates int2x3
/// \brief Performs a bitwise XOR on the given left-hand int2x3 against the corresponding component of the given right-hand int2x3.
inline int2x3 operator^=( int2x3& lhs, const int2x3& rhs );

/// \relates int2x3
/// \brief Returns a copy of the int2x3 where each component has been bitwise left-shifted by the given scalar value.
inline int2x3 operator<<( const int2x3& lhs, const int32_t& rhs );

/// \relates int2x3
/// \brief Performs a left bitshift on the given left-hand int2x3 by the given scalar value.
inline int2x3 operator<<=( int2x3& lhs, const int32_t& rhs );

/// \relates int2x3
/// \brief Returns a copy of the int2x3 where each component of the left-hand int2x3 has been bitwise left-shifted by the corresponding component of the right-hand side int2x3.
inline int2x3 operator<<( const int2x3& lhs, const int2x3& rhs );

/// \relates int2x3
/// \brief Performs a left bitshift on the given left-hand int2x3 by the corresponding component of the given right-hand int2x3.
inline int2x3 operator<<=( int2x3& lhs, const int2x3& rhs );

/// \relates int2x3
/// \brief Returns a copy of the int2x3 where each component has been bitwise right-shifted by the given scalar value.
inline int2x3 operator>>( const int2x3& lhs, const int32_t& rhs );

/// \relates int2x3
/// \brief Performs a right bitshift on the given left-hand int2x3 by the given scalar value.
inline int2x3 operator>>=( int2x3& lhs, const int32_t& rhs );

/// \relates int2x3
/// \brief Returns a copy of the int2x3 where each component of the left-hand int2x3 has been bitwise right-shifted by the corresponding component of the right-hand side int2x3.
inline int2x3 operator>>( const int2x3& lhs, const int2x3& rhs );

/// \relates int2x3
/// \brief Performs a right bitshift on the given left-hand int2x3 by the corresponding component of the given right-hand int2x3.
inline int2x3 operator>>=( int2x3& lhs, const int2x3& rhs );

/// \relates int2x3
/// \brief Performs a unary bitwise operation on all components of the given int2x3.
inline int2x3 operator~( const int2x3& lhs );


// int2x4
/// \relates int2x4
/// \brief Returns a copy of the int2x4 that has been component-wise added by the given scalar value.
inline int2x4 operator+( const int2x4& lhs, const int32_t rhs );

/// \relates int2x4
/// \brief Adds each component by the given scalar value.
inline int2x4 operator+=( int2x4& lhs, const int32_t rhs );

/// \relates int2x4
/// \brief Returns a copy of the int2x4 that has been component-wise added by the corresponding component of the right-hand int2x4.
inline int2x4 operator+( const int2x4& lhs, const int2x4& rhs );

/// \relates int2x4
/// \brief Adds each component of the int2x4 by the corresponding component of the right-hand int2x4.
inline int2x4 operator+=( int2x4& lhs, const int2x4& rhs );

/// \relates int2x4
/// \brief Returns a copy of the int2x4 that has been component-wise subtracted by the given scalar value.
inline int2x4 operator-( const int2x4& lhs, const int32_t rhs );

/// \relates int2x4
/// \brief Subtracts each component by the given scalar value.
inline int2x4 operator-=( int2x4& lhs, const int32_t rhs );

/// \relates int2x4
/// \brief Returns a copy of the int2x4 that has been component-wise subtracted by the corresponding component of the right-hand int2x4.
inline int2x4 operator-( const int2x4& lhs, const int2x4& rhs );

/// \relates int2x4
/// \brief Subtracts each component of the int2x4 by the corresponding component of the right-hand int2x4.
inline int2x4 operator-=( int2x4& lhs, const int2x4& rhs );

/// \relates int2x4
/// \brief Returns a copy of the int2x4 that has been component-wise multiplied by the given scalar value.
inline int2x4 operator*( const int2x4& lhs, const int32_t rhs );

/// \relates int2x4
/// \brief Multiplies each component by the given scalar value.
inline int2x4 operator*=( int2x4& lhs, const int32_t rhs );

/// \relates int2x4
/// \brief Returns a copy of the matrix where each row of the left-hand matrix has been dot-producted by the corresponding column of the right-hand matrix.
inline int2x2 operator*( const int2x4& lhs, const int4x2& rhs );

/// \relates int2x4
/// \brief Dot products each row of the left-hand matrix with the corresponding column of the right-hand matrix.
inline int2x2 operator*=( int2x4& lhs, const int4x2& rhs );

/// \relates int2x4
/// \brief Returns a copy of the int2x4 that has been component-wise divided by the given scalar value.
inline int2x4 operator/( const int2x4& lhs, const int32_t rhs );

/// \relates int2x4
/// \brief Divides each component by the given scalar value.
inline int2x4 operator/=( int2x4& lhs, const int32_t rhs );

/// \relates int2x4
/// \brief Returns a copy of the int2x4 that has been component-wise divided by the corresponding component of the right-hand int2x4.
inline int2x4 operator/( const int2x4& lhs, const int2x4& rhs );

/// \relates int2x4
/// \brief Prefix increment operator.  Adds one to each component of the given int2x4 before evaluation.
inline int2x4& operator++( int2x4& lhs );

/// \relates int2x4
/// \brief Postfix increment operator.  Adds one to each component of the given int2x4 after evaluation.
inline int2x4& operator++( int2x4& lhs, const int );

/// \relates int2x4
/// \brief Prefix decrement operator.  Subtracts one from each component of the given int2x4 before evaluation.
inline int2x4& operator--( int2x4& lhs );

/// \relates int2x4
/// \brief Postfix decrement operator.  Subtracts one from each component of the given int2x4 after evaluation.
inline int2x4& operator--( int2x4& lhs, const int );

/// \relates int2x4
/// \brief Returns a bool2x4 where each component is true if the component of the left-hand type is less than the corresponding right-hand type component.
inline bool2x4 operator<( const int2x4& lhs, const int2x4& rhs );

/// \relates int2x4
/// \brief Returns a bool2x4 where each component is true if the component of the left-hand type is less than or equal to the corresponding right-hand type component.
inline bool2x4 operator<=( const int2x4& lhs, const int2x4& rhs );

/// \relates int2x4
/// \brief Returns a bool2x4 where each component is true if the component of the left-hand type is greater than the corresponding right-hand type component.
inline bool2x4 operator>( const int2x4& lhs, const int2x4& rhs );

/// \relates int2x4
/// \brief Returns a bool2x4 where each component is true if the component of the left-hand type is greater than or equal to the corresponding right-hand type component.
inline bool2x4 operator>=( const int2x4& lhs, const int2x4& rhs );

/// \relates int2x4
/// \brief Returns a copy of the int2x4 where each component has been bitwise AND'd against the given scalar value.
inline int2x4 operator&( const int2x4& lhs, const int32_t& rhs );

/// \relates int2x4
/// \brief Performs a bitwise AND on the given left-hand int2x4 against the given scalar value.
inline int2x4 operator&=( int2x4& lhs, const int32_t& rhs );

/// \relates int2x4
/// \brief Returns a copy of the int2x4 where each component of the left-hand int2x4 has been bitwise AND'd against the corresponding component of the right-hand side int2x4.
inline int2x4 operator&( const int2x4& lhs, const int2x4& rhs );

/// \relates int2x4
/// \brief Performs a bitwise AND on the given left-hand int2x4 against the corresponding component of the given right-hand int2x4.
inline int2x4 operator&=( int2x4& lhs, const int2x4& rhs );

/// \relates int2x4
/// \brief Returns a copy of the int2x4 where each component has been bitwise OR'd against the given scalar value.
inline int2x4 operator|( const int2x4& lhs, const int32_t& rhs );

/// \relates int2x4
/// \brief Performs a bitwise OR on the given left-hand int2x4 against the given scalar value.
inline int2x4 operator|=( int2x4& lhs, const int32_t& rhs );

/// \relates int2x4
/// \brief Returns a copy of the int2x4 where each component of the left-hand int2x4 has been bitwise OR'd against the corresponding component of the right-hand side int2x4.
inline int2x4 operator|( const int2x4& lhs, const int2x4& rhs );

/// \relates int2x4
/// \brief Performs a bitwise OR on the given left-hand int2x4 against the corresponding component of the given right-hand int2x4.
inline int2x4 operator|=( int2x4& lhs, const int2x4& rhs );

/// \relates int2x4
/// \brief Returns a copy of the int2x4 where each component has been bitwise XOR'd against the given scalar value.
inline int2x4 operator^( const int2x4& lhs, const int32_t& rhs );

/// \relates int2x4
/// \brief Performs a bitwise XOR on the given left-hand int2x4 against the given scalar value.
inline int2x4 operator^=( int2x4& lhs, const int32_t& rhs );

/// \relates int2x4
/// \brief Returns a copy of the int2x4 where each component of the left-hand int2x4 has been bitwise XOR'd against the corresponding component of the right-hand side int2x4.
inline int2x4 operator^( const int2x4& lhs, const int2x4& rhs );

/// \relates int2x4
/// \brief Performs a bitwise XOR on the given left-hand int2x4 against the corresponding component of the given right-hand int2x4.
inline int2x4 operator^=( int2x4& lhs, const int2x4& rhs );

/// \relates int2x4
/// \brief Returns a copy of the int2x4 where each component has been bitwise left-shifted by the given scalar value.
inline int2x4 operator<<( const int2x4& lhs, const int32_t& rhs );

/// \relates int2x4
/// \brief Performs a left bitshift on the given left-hand int2x4 by the given scalar value.
inline int2x4 operator<<=( int2x4& lhs, const int32_t& rhs );

/// \relates int2x4
/// \brief Returns a copy of the int2x4 where each component of the left-hand int2x4 has been bitwise left-shifted by the corresponding component of the right-hand side int2x4.
inline int2x4 operator<<( const int2x4& lhs, const int2x4& rhs );

/// \relates int2x4
/// \brief Performs a left bitshift on the given left-hand int2x4 by the corresponding component of the given right-hand int2x4.
inline int2x4 operator<<=( int2x4& lhs, const int2x4& rhs );

/// \relates int2x4
/// \brief Returns a copy of the int2x4 where each component has been bitwise right-shifted by the given scalar value.
inline int2x4 operator>>( const int2x4& lhs, const int32_t& rhs );

/// \relates int2x4
/// \brief Performs a right bitshift on the given left-hand int2x4 by the given scalar value.
inline int2x4 operator>>=( int2x4& lhs, const int32_t& rhs );

/// \relates int2x4
/// \brief Returns a copy of the int2x4 where each component of the left-hand int2x4 has been bitwise right-shifted by the corresponding component of the right-hand side int2x4.
inline int2x4 operator>>( const int2x4& lhs, const int2x4& rhs );

/// \relates int2x4
/// \brief Performs a right bitshift on the given left-hand int2x4 by the corresponding component of the given right-hand int2x4.
inline int2x4 operator>>=( int2x4& lhs, const int2x4& rhs );

/// \relates int2x4
/// \brief Performs a unary bitwise operation on all components of the given int2x4.
inline int2x4 operator~( const int2x4& lhs );


// int3x2
/// \relates int3x2
/// \brief Returns a copy of the int3x2 that has been component-wise added by the given scalar value.
inline int3x2 operator+( const int3x2& lhs, const int32_t rhs );

/// \relates int3x2
/// \brief Adds each component by the given scalar value.
inline int3x2 operator+=( int3x2& lhs, const int32_t rhs );

/// \relates int3x2
/// \brief Returns a copy of the int3x2 that has been component-wise added by the corresponding component of the right-hand int3x2.
inline int3x2 operator+( const int3x2& lhs, const int3x2& rhs );

/// \relates int3x2
/// \brief Adds each component of the int3x2 by the corresponding component of the right-hand int3x2.
inline int3x2 operator+=( int3x2& lhs, const int3x2& rhs );

/// \relates int3x2
/// \brief Returns a copy of the int3x2 that has been component-wise subtracted by the given scalar value.
inline int3x2 operator-( const int3x2& lhs, const int32_t rhs );

/// \relates int3x2
/// \brief Subtracts each component by the given scalar value.
inline int3x2 operator-=( int3x2& lhs, const int32_t rhs );

/// \relates int3x2
/// \brief Returns a copy of the int3x2 that has been component-wise subtracted by the corresponding component of the right-hand int3x2.
inline int3x2 operator-( const int3x2& lhs, const int3x2& rhs );

/// \relates int3x2
/// \brief Subtracts each component of the int3x2 by the corresponding component of the right-hand int3x2.
inline int3x2 operator-=( int3x2& lhs, const int3x2& rhs );

/// \relates int3x2
/// \brief Returns a copy of the int3x2 that has been component-wise multiplied by the given scalar value.
inline int3x2 operator*( const int3x2& lhs, const int32_t rhs );

/// \relates int3x2
/// \brief Multiplies each component by the given scalar value.
inline int3x2 operator*=( int3x2& lhs, const int32_t rhs );

/// \relates int3x2
/// \brief Returns a copy of the matrix where each row of the left-hand matrix has been dot-producted by the corresponding column of the right-hand matrix.
inline int3x3 operator*( const int3x2& lhs, const int2x3& rhs );

/// \relates int3x2
/// \brief Dot products each row of the left-hand matrix with the corresponding column of the right-hand matrix.
inline int3x3 operator*=( int3x2& lhs, const int2x3& rhs );

/// \relates int3x2
/// \brief Returns a copy of the int3x2 that has been component-wise divided by the given scalar value.
inline int3x2 operator/( const int3x2& lhs, const int32_t rhs );

/// \relates int3x2
/// \brief Divides each component by the given scalar value.
inline int3x2 operator/=( int3x2& lhs, const int32_t rhs );

/// \relates int3x2
/// \brief Returns a copy of the int3x2 that has been component-wise divided by the corresponding component of the right-hand int3x2.
inline int3x2 operator/( const int3x2& lhs, const int3x2& rhs );

/// \relates int3x2
/// \brief Prefix increment operator.  Adds one to each component of the given int3x2 before evaluation.
inline int3x2& operator++( int3x2& lhs );

/// \relates int3x2
/// \brief Postfix increment operator.  Adds one to each component of the given int3x2 after evaluation.
inline int3x2& operator++( int3x2& lhs, const int );

/// \relates int3x2
/// \brief Prefix decrement operator.  Subtracts one from each component of the given int3x2 before evaluation.
inline int3x2& operator--( int3x2& lhs );

/// \relates int3x2
/// \brief Postfix decrement operator.  Subtracts one from each component of the given int3x2 after evaluation.
inline int3x2& operator--( int3x2& lhs, const int );

/// \relates int3x2
/// \brief Returns a bool3x2 where each component is true if the component of the left-hand type is less than the corresponding right-hand type component.
inline bool3x2 operator<( const int3x2& lhs, const int3x2& rhs );

/// \relates int3x2
/// \brief Returns a bool3x2 where each component is true if the component of the left-hand type is less than or equal to the corresponding right-hand type component.
inline bool3x2 operator<=( const int3x2& lhs, const int3x2& rhs );

/// \relates int3x2
/// \brief Returns a bool3x2 where each component is true if the component of the left-hand type is greater than the corresponding right-hand type component.
inline bool3x2 operator>( const int3x2& lhs, const int3x2& rhs );

/// \relates int3x2
/// \brief Returns a bool3x2 where each component is true if the component of the left-hand type is greater than or equal to the corresponding right-hand type component.
inline bool3x2 operator>=( const int3x2& lhs, const int3x2& rhs );

/// \relates int3x2
/// \brief Returns a copy of the int3x2 where each component has been bitwise AND'd against the given scalar value.
inline int3x2 operator&( const int3x2& lhs, const int32_t& rhs );

/// \relates int3x2
/// \brief Performs a bitwise AND on the given left-hand int3x2 against the given scalar value.
inline int3x2 operator&=( int3x2& lhs, const int32_t& rhs );

/// \relates int3x2
/// \brief Returns a copy of the int3x2 where each component of the left-hand int3x2 has been bitwise AND'd against the corresponding component of the right-hand side int3x2.
inline int3x2 operator&( const int3x2& lhs, const int3x2& rhs );

/// \relates int3x2
/// \brief Performs a bitwise AND on the given left-hand int3x2 against the corresponding component of the given right-hand int3x2.
inline int3x2 operator&=( int3x2& lhs, const int3x2& rhs );

/// \relates int3x2
/// \brief Returns a copy of the int3x2 where each component has been bitwise OR'd against the given scalar value.
inline int3x2 operator|( const int3x2& lhs, const int32_t& rhs );

/// \relates int3x2
/// \brief Performs a bitwise OR on the given left-hand int3x2 against the given scalar value.
inline int3x2 operator|=( int3x2& lhs, const int32_t& rhs );

/// \relates int3x2
/// \brief Returns a copy of the int3x2 where each component of the left-hand int3x2 has been bitwise OR'd against the corresponding component of the right-hand side int3x2.
inline int3x2 operator|( const int3x2& lhs, const int3x2& rhs );

/// \relates int3x2
/// \brief Performs a bitwise OR on the given left-hand int3x2 against the corresponding component of the given right-hand int3x2.
inline int3x2 operator|=( int3x2& lhs, const int3x2& rhs );

/// \relates int3x2
/// \brief Returns a copy of the int3x2 where each component has been bitwise XOR'd against the given scalar value.
inline int3x2 operator^( const int3x2& lhs, const int32_t& rhs );

/// \relates int3x2
/// \brief Performs a bitwise XOR on the given left-hand int3x2 against the given scalar value.
inline int3x2 operator^=( int3x2& lhs, const int32_t& rhs );

/// \relates int3x2
/// \brief Returns a copy of the int3x2 where each component of the left-hand int3x2 has been bitwise XOR'd against the corresponding component of the right-hand side int3x2.
inline int3x2 operator^( const int3x2& lhs, const int3x2& rhs );

/// \relates int3x2
/// \brief Performs a bitwise XOR on the given left-hand int3x2 against the corresponding component of the given right-hand int3x2.
inline int3x2 operator^=( int3x2& lhs, const int3x2& rhs );

/// \relates int3x2
/// \brief Returns a copy of the int3x2 where each component has been bitwise left-shifted by the given scalar value.
inline int3x2 operator<<( const int3x2& lhs, const int32_t& rhs );

/// \relates int3x2
/// \brief Performs a left bitshift on the given left-hand int3x2 by the given scalar value.
inline int3x2 operator<<=( int3x2& lhs, const int32_t& rhs );

/// \relates int3x2
/// \brief Returns a copy of the int3x2 where each component of the left-hand int3x2 has been bitwise left-shifted by the corresponding component of the right-hand side int3x2.
inline int3x2 operator<<( const int3x2& lhs, const int3x2& rhs );

/// \relates int3x2
/// \brief Performs a left bitshift on the given left-hand int3x2 by the corresponding component of the given right-hand int3x2.
inline int3x2 operator<<=( int3x2& lhs, const int3x2& rhs );

/// \relates int3x2
/// \brief Returns a copy of the int3x2 where each component has been bitwise right-shifted by the given scalar value.
inline int3x2 operator>>( const int3x2& lhs, const int32_t& rhs );

/// \relates int3x2
/// \brief Performs a right bitshift on the given left-hand int3x2 by the given scalar value.
inline int3x2 operator>>=( int3x2& lhs, const int32_t& rhs );

/// \relates int3x2
/// \brief Returns a copy of the int3x2 where each component of the left-hand int3x2 has been bitwise right-shifted by the corresponding component of the right-hand side int3x2.
inline int3x2 operator>>( const int3x2& lhs, const int3x2& rhs );

/// \relates int3x2
/// \brief Performs a right bitshift on the given left-hand int3x2 by the corresponding component of the given right-hand int3x2.
inline int3x2 operator>>=( int3x2& lhs, const int3x2& rhs );

/// \relates int3x2
/// \brief Performs a unary bitwise operation on all components of the given int3x2.
inline int3x2 operator~( const int3x2& lhs );


// int3x3
/// \relates int3x3
/// \brief Returns a copy of the int3x3 that has been component-wise added by the given scalar value.
inline int3x3 operator+( const int3x3& lhs, const int32_t rhs );

/// \relates int3x3
/// \brief Adds each component by the given scalar value.
inline int3x3 operator+=( int3x3& lhs, const int32_t rhs );

/// \relates int3x3
/// \brief Returns a copy of the int3x3 that has been component-wise added by the corresponding component of the right-hand int3x3.
inline int3x3 operator+( const int3x3& lhs, const int3x3& rhs );

/// \relates int3x3
/// \brief Adds each component of the int3x3 by the corresponding component of the right-hand int3x3.
inline int3x3 operator+=( int3x3& lhs, const int3x3& rhs );

/// \relates int3x3
/// \brief Returns a copy of the int3x3 that has been component-wise subtracted by the given scalar value.
inline int3x3 operator-( const int3x3& lhs, const int32_t rhs );

/// \relates int3x3
/// \brief Subtracts each component by the given scalar value.
inline int3x3 operator-=( int3x3& lhs, const int32_t rhs );

/// \relates int3x3
/// \brief Returns a copy of the int3x3 that has been component-wise subtracted by the corresponding component of the right-hand int3x3.
inline int3x3 operator-( const int3x3& lhs, const int3x3& rhs );

/// \relates int3x3
/// \brief Subtracts each component of the int3x3 by the corresponding component of the right-hand int3x3.
inline int3x3 operator-=( int3x3& lhs, const int3x3& rhs );

/// \relates int3x3
/// \brief Returns a copy of the int3x3 that has been component-wise multiplied by the given scalar value.
inline int3x3 operator*( const int3x3& lhs, const int32_t rhs );

/// \relates int3x3
/// \brief Multiplies each component by the given scalar value.
inline int3x3 operator*=( int3x3& lhs, const int32_t rhs );

/// \relates int3x3
/// \brief Returns a copy of the matrix where each row of the left-hand matrix has been dot-producted by the corresponding column of the right-hand matrix.
inline int3x3 operator*( const int3x3& lhs, const int3x3& rhs );

/// \relates int3x3
/// \brief Dot products each row of the left-hand matrix with the corresponding column of the right-hand matrix.
inline int3x3 operator*=( int3x3& lhs, const int3x3& rhs );

/// \relates int3x3
/// \brief Returns a copy of the int3x3 that has been component-wise divided by the given scalar value.
inline int3x3 operator/( const int3x3& lhs, const int32_t rhs );

/// \relates int3x3
/// \brief Divides each component by the given scalar value.
inline int3x3 operator/=( int3x3& lhs, const int32_t rhs );

/// \relates int3x3
/// \brief Returns a copy of the int3x3 that has been component-wise divided by the corresponding component of the right-hand int3x3.
inline int3x3 operator/( const int3x3& lhs, const int3x3& rhs );

/// \relates int3x3
/// \brief Divides each component of the int3x3 by the corresponding component of the right-hand int3x3.
inline int3x3 operator/=( int3x3& lhs, const int3x3& rhs );

/// \relates int3x3
/// \brief Prefix increment operator.  Adds one to each component of the given int3x3 before evaluation.
inline int3x3& operator++( int3x3& lhs );

/// \relates int3x3
/// \brief Postfix increment operator.  Adds one to each component of the given int3x3 after evaluation.
inline int3x3& operator++( int3x3& lhs, const int );

/// \relates int3x3
/// \brief Prefix decrement operator.  Subtracts one from each component of the given int3x3 before evaluation.
inline int3x3& operator--( int3x3& lhs );

/// \relates int3x3
/// \brief Postfix decrement operator.  Subtracts one from each component of the given int3x3 after evaluation.
inline int3x3& operator--( int3x3& lhs, const int );

/// \relates int3x3
/// \brief Returns a bool3x3 where each component is true if the component of the left-hand type is less than the corresponding right-hand type component.
inline bool3x3 operator<( const int3x3& lhs, const int3x3& rhs );

/// \relates int3x3
/// \brief Returns a bool3x3 where each component is true if the component of the left-hand type is less than or equal to the corresponding right-hand type component.
inline bool3x3 operator<=( const int3x3& lhs, const int3x3& rhs );

/// \relates int3x3
/// \brief Returns a bool3x3 where each component is true if the component of the left-hand type is greater than the corresponding right-hand type component.
inline bool3x3 operator>( const int3x3& lhs, const int3x3& rhs );

/// \relates int3x3
/// \brief Returns a bool3x3 where each component is true if the component of the left-hand type is greater than or equal to the corresponding right-hand type component.
inline bool3x3 operator>=( const int3x3& lhs, const int3x3& rhs );

/// \relates int3x3
/// \brief Returns a copy of the int3x3 where each component has been bitwise AND'd against the given scalar value.
inline int3x3 operator&( const int3x3& lhs, const int32_t& rhs );

/// \relates int3x3
/// \brief Performs a bitwise AND on the given left-hand int3x3 against the given scalar value.
inline int3x3 operator&=( int3x3& lhs, const int32_t& rhs );

/// \relates int3x3
/// \brief Returns a copy of the int3x3 where each component of the left-hand int3x3 has been bitwise AND'd against the corresponding component of the right-hand side int3x3.
inline int3x3 operator&( const int3x3& lhs, const int3x3& rhs );

/// \relates int3x3
/// \brief Performs a bitwise AND on the given left-hand int3x3 against the corresponding component of the given right-hand int3x3.
inline int3x3 operator&=( int3x3& lhs, const int3x3& rhs );

/// \relates int3x3
/// \brief Returns a copy of the int3x3 where each component has been bitwise OR'd against the given scalar value.
inline int3x3 operator|( const int3x3& lhs, const int32_t& rhs );

/// \relates int3x3
/// \brief Performs a bitwise OR on the given left-hand int3x3 against the given scalar value.
inline int3x3 operator|=( int3x3& lhs, const int32_t& rhs );

/// \relates int3x3
/// \brief Returns a copy of the int3x3 where each component of the left-hand int3x3 has been bitwise OR'd against the corresponding component of the right-hand side int3x3.
inline int3x3 operator|( const int3x3& lhs, const int3x3& rhs );

/// \relates int3x3
/// \brief Performs a bitwise OR on the given left-hand int3x3 against the corresponding component of the given right-hand int3x3.
inline int3x3 operator|=( int3x3& lhs, const int3x3& rhs );

/// \relates int3x3
/// \brief Returns a copy of the int3x3 where each component has been bitwise XOR'd against the given scalar value.
inline int3x3 operator^( const int3x3& lhs, const int32_t& rhs );

/// \relates int3x3
/// \brief Performs a bitwise XOR on the given left-hand int3x3 against the given scalar value.
inline int3x3 operator^=( int3x3& lhs, const int32_t& rhs );

/// \relates int3x3
/// \brief Returns a copy of the int3x3 where each component of the left-hand int3x3 has been bitwise XOR'd against the corresponding component of the right-hand side int3x3.
inline int3x3 operator^( const int3x3& lhs, const int3x3& rhs );

/// \relates int3x3
/// \brief Performs a bitwise XOR on the given left-hand int3x3 against the corresponding component of the given right-hand int3x3.
inline int3x3 operator^=( int3x3& lhs, const int3x3& rhs );

/// \relates int3x3
/// \brief Returns a copy of the int3x3 where each component has been bitwise left-shifted by the given scalar value.
inline int3x3 operator<<( const int3x3& lhs, const int32_t& rhs );

/// \relates int3x3
/// \brief Performs a left bitshift on the given left-hand int3x3 by the given scalar value.
inline int3x3 operator<<=( int3x3& lhs, const int32_t& rhs );

/// \relates int3x3
/// \brief Returns a copy of the int3x3 where each component of the left-hand int3x3 has been bitwise left-shifted by the corresponding component of the right-hand side int3x3.
inline int3x3 operator<<( const int3x3& lhs, const int3x3& rhs );

/// \relates int3x3
/// \brief Performs a left bitshift on the given left-hand int3x3 by the corresponding component of the given right-hand int3x3.
inline int3x3 operator<<=( int3x3& lhs, const int3x3& rhs );

/// \relates int3x3
/// \brief Returns a copy of the int3x3 where each component has been bitwise right-shifted by the given scalar value.
inline int3x3 operator>>( const int3x3& lhs, const int32_t& rhs );

/// \relates int3x3
/// \brief Performs a right bitshift on the given left-hand int3x3 by the given scalar value.
inline int3x3 operator>>=( int3x3& lhs, const int32_t& rhs );

/// \relates int3x3
/// \brief Returns a copy of the int3x3 where each component of the left-hand int3x3 has been bitwise right-shifted by the corresponding component of the right-hand side int3x3.
inline int3x3 operator>>( const int3x3& lhs, const int3x3& rhs );

/// \relates int3x3
/// \brief Performs a right bitshift on the given left-hand int3x3 by the corresponding component of the given right-hand int3x3.
inline int3x3 operator>>=( int3x3& lhs, const int3x3& rhs );

/// \relates int3x3
/// \brief Performs a unary bitwise operation on all components of the given int3x3.
inline int3x3 operator~( const int3x3& lhs );


// int3x4
/// \relates int3x4
/// \brief Returns a copy of the int3x4 that has been component-wise added by the given scalar value.
inline int3x4 operator+( const int3x4& lhs, const int32_t rhs );

/// \relates int3x4
/// \brief Adds each component by the given scalar value.
inline int3x4 operator+=( int3x4& lhs, const int32_t rhs );

/// \relates int3x4
/// \brief Returns a copy of the int3x4 that has been component-wise added by the corresponding component of the right-hand int3x4.
inline int3x4 operator+( const int3x4& lhs, const int3x4& rhs );

/// \relates int3x4
/// \brief Adds each component of the int3x4 by the corresponding component of the right-hand int3x4.
inline int3x4 operator+=( int3x4& lhs, const int3x4& rhs );

/// \relates int3x4
/// \brief Returns a copy of the int3x4 that has been component-wise subtracted by the given scalar value.
inline int3x4 operator-( const int3x4& lhs, const int32_t rhs );

/// \relates int3x4
/// \brief Subtracts each component by the given scalar value.
inline int3x4 operator-=( int3x4& lhs, const int32_t rhs );

/// \relates int3x4
/// \brief Returns a copy of the int3x4 that has been component-wise subtracted by the corresponding component of the right-hand int3x4.
inline int3x4 operator-( const int3x4& lhs, const int3x4& rhs );

/// \relates int3x4
/// \brief Subtracts each component of the int3x4 by the corresponding component of the right-hand int3x4.
inline int3x4 operator-=( int3x4& lhs, const int3x4& rhs );

/// \relates int3x4
/// \brief Returns a copy of the int3x4 that has been component-wise multiplied by the given scalar value.
inline int3x4 operator*( const int3x4& lhs, const int32_t rhs );

/// \relates int3x4
/// \brief Multiplies each component by the given scalar value.
inline int3x4 operator*=( int3x4& lhs, const int32_t rhs );

/// \relates int3x4
/// \brief Returns a copy of the matrix where each row of the left-hand matrix has been dot-producted by the corresponding column of the right-hand matrix.
inline int3x3 operator*( const int3x4& lhs, const int4x3& rhs );

/// \relates int3x4
/// \brief Dot products each row of the left-hand matrix with the corresponding column of the right-hand matrix.
inline int3x3 operator*=( int3x4& lhs, const int4x3& rhs );

/// \relates int3x4
/// \brief Returns a copy of the int3x4 that has been component-wise divided by the given scalar value.
inline int3x4 operator/( const int3x4& lhs, const int32_t rhs );

/// \relates int3x4
/// \brief Divides each component by the given scalar value.
inline int3x4 operator/=( int3x4& lhs, const int32_t rhs );

/// \relates int3x4
/// \brief Returns a copy of the int3x4 that has been component-wise divided by the corresponding component of the right-hand int3x4.
inline int3x4 operator/( const int3x4& lhs, const int3x4& rhs );

/// \relates int3x4
/// \brief Prefix increment operator.  Adds one to each component of the given int3x4 before evaluation.
inline int3x4& operator++( int3x4& lhs );

/// \relates int3x4
/// \brief Postfix increment operator.  Adds one to each component of the given int3x4 after evaluation.
inline int3x4& operator++( int3x4& lhs, const int );

/// \relates int3x4
/// \brief Prefix decrement operator.  Subtracts one from each component of the given int3x4 before evaluation.
inline int3x4& operator--( int3x4& lhs );

/// \relates int3x4
/// \brief Postfix decrement operator.  Subtracts one from each component of the given int3x4 after evaluation.
inline int3x4& operator--( int3x4& lhs, const int );

/// \relates int3x4
/// \brief Returns a bool3x4 where each component is true if the component of the left-hand type is less than the corresponding right-hand type component.
inline bool3x4 operator<( const int3x4& lhs, const int3x4& rhs );

/// \relates int3x4
/// \brief Returns a bool3x4 where each component is true if the component of the left-hand type is less than or equal to the corresponding right-hand type component.
inline bool3x4 operator<=( const int3x4& lhs, const int3x4& rhs );

/// \relates int3x4
/// \brief Returns a bool3x4 where each component is true if the component of the left-hand type is greater than the corresponding right-hand type component.
inline bool3x4 operator>( const int3x4& lhs, const int3x4& rhs );

/// \relates int3x4
/// \brief Returns a bool3x4 where each component is true if the component of the left-hand type is greater than or equal to the corresponding right-hand type component.
inline bool3x4 operator>=( const int3x4& lhs, const int3x4& rhs );

/// \relates int3x4
/// \brief Returns a copy of the int3x4 where each component has been bitwise AND'd against the given scalar value.
inline int3x4 operator&( const int3x4& lhs, const int32_t& rhs );

/// \relates int3x4
/// \brief Performs a bitwise AND on the given left-hand int3x4 against the given scalar value.
inline int3x4 operator&=( int3x4& lhs, const int32_t& rhs );

/// \relates int3x4
/// \brief Returns a copy of the int3x4 where each component of the left-hand int3x4 has been bitwise AND'd against the corresponding component of the right-hand side int3x4.
inline int3x4 operator&( const int3x4& lhs, const int3x4& rhs );

/// \relates int3x4
/// \brief Performs a bitwise AND on the given left-hand int3x4 against the corresponding component of the given right-hand int3x4.
inline int3x4 operator&=( int3x4& lhs, const int3x4& rhs );

/// \relates int3x4
/// \brief Returns a copy of the int3x4 where each component has been bitwise OR'd against the given scalar value.
inline int3x4 operator|( const int3x4& lhs, const int32_t& rhs );

/// \relates int3x4
/// \brief Performs a bitwise OR on the given left-hand int3x4 against the given scalar value.
inline int3x4 operator|=( int3x4& lhs, const int32_t& rhs );

/// \relates int3x4
/// \brief Returns a copy of the int3x4 where each component of the left-hand int3x4 has been bitwise OR'd against the corresponding component of the right-hand side int3x4.
inline int3x4 operator|( const int3x4& lhs, const int3x4& rhs );

/// \relates int3x4
/// \brief Performs a bitwise OR on the given left-hand int3x4 against the corresponding component of the given right-hand int3x4.
inline int3x4 operator|=( int3x4& lhs, const int3x4& rhs );

/// \relates int3x4
/// \brief Returns a copy of the int3x4 where each component has been bitwise XOR'd against the given scalar value.
inline int3x4 operator^( const int3x4& lhs, const int32_t& rhs );

/// \relates int3x4
/// \brief Performs a bitwise XOR on the given left-hand int3x4 against the given scalar value.
inline int3x4 operator^=( int3x4& lhs, const int32_t& rhs );

/// \relates int3x4
/// \brief Returns a copy of the int3x4 where each component of the left-hand int3x4 has been bitwise XOR'd against the corresponding component of the right-hand side int3x4.
inline int3x4 operator^( const int3x4& lhs, const int3x4& rhs );

/// \relates int3x4
/// \brief Performs a bitwise XOR on the given left-hand int3x4 against the corresponding component of the given right-hand int3x4.
inline int3x4 operator^=( int3x4& lhs, const int3x4& rhs );

/// \relates int3x4
/// \brief Returns a copy of the int3x4 where each component has been bitwise left-shifted by the given scalar value.
inline int3x4 operator<<( const int3x4& lhs, const int32_t& rhs );

/// \relates int3x4
/// \brief Performs a left bitshift on the given left-hand int3x4 by the given scalar value.
inline int3x4 operator<<=( int3x4& lhs, const int32_t& rhs );

/// \relates int3x4
/// \brief Returns a copy of the int3x4 where each component of the left-hand int3x4 has been bitwise left-shifted by the corresponding component of the right-hand side int3x4.
inline int3x4 operator<<( const int3x4& lhs, const int3x4& rhs );

/// \relates int3x4
/// \brief Performs a left bitshift on the given left-hand int3x4 by the corresponding component of the given right-hand int3x4.
inline int3x4 operator<<=( int3x4& lhs, const int3x4& rhs );

/// \relates int3x4
/// \brief Returns a copy of the int3x4 where each component has been bitwise right-shifted by the given scalar value.
inline int3x4 operator>>( const int3x4& lhs, const int32_t& rhs );

/// \relates int3x4
/// \brief Performs a right bitshift on the given left-hand int3x4 by the given scalar value.
inline int3x4 operator>>=( int3x4& lhs, const int32_t& rhs );

/// \relates int3x4
/// \brief Returns a copy of the int3x4 where each component of the left-hand int3x4 has been bitwise right-shifted by the corresponding component of the right-hand side int3x4.
inline int3x4 operator>>( const int3x4& lhs, const int3x4& rhs );

/// \relates int3x4
/// \brief Performs a right bitshift on the given left-hand int3x4 by the corresponding component of the given right-hand int3x4.
inline int3x4 operator>>=( int3x4& lhs, const int3x4& rhs );

/// \relates int3x4
/// \brief Performs a unary bitwise operation on all components of the given int3x4.
inline int3x4 operator~( const int3x4& lhs );


// int4x2
/// \relates int4x2
/// \brief Returns a copy of the int4x2 that has been component-wise added by the given scalar value.
inline int4x2 operator+( const int4x2& lhs, const int32_t rhs );

/// \relates int4x2
/// \brief Adds each component by the given scalar value.
inline int4x2 operator+=( int4x2& lhs, const int32_t rhs );

/// \relates int4x2
/// \brief Returns a copy of the int4x2 that has been component-wise added by the corresponding component of the right-hand int4x2.
inline int4x2 operator+( const int4x2& lhs, const int4x2& rhs );

/// \relates int4x2
/// \brief Adds each component of the int4x2 by the corresponding component of the right-hand int4x2.
inline int4x2 operator+=( int4x2& lhs, const int4x2& rhs );

/// \relates int4x2
/// \brief Returns a copy of the int4x2 that has been component-wise subtracted by the given scalar value.
inline int4x2 operator-( const int4x2& lhs, const int32_t rhs );

/// \relates int4x2
/// \brief Subtracts each component by the given scalar value.
inline int4x2 operator-=( int4x2& lhs, const int32_t rhs );

/// \relates int4x2
/// \brief Returns a copy of the int4x2 that has been component-wise subtracted by the corresponding component of the right-hand int4x2.
inline int4x2 operator-( const int4x2& lhs, const int4x2& rhs );

/// \relates int4x2
/// \brief Subtracts each component of the int4x2 by the corresponding component of the right-hand int4x2.
inline int4x2 operator-=( int4x2& lhs, const int4x2& rhs );

/// \relates int4x2
/// \brief Returns a copy of the int4x2 that has been component-wise multiplied by the given scalar value.
inline int4x2 operator*( const int4x2& lhs, const int32_t rhs );

/// \relates int4x2
/// \brief Multiplies each component by the given scalar value.
inline int4x2 operator*=( int4x2& lhs, const int32_t rhs );

/// \relates int4x2
/// \brief Returns a copy of the matrix where each row of the left-hand matrix has been dot-producted by the corresponding column of the right-hand matrix.
inline int4x4 operator*( const int4x2& lhs, const int2x4& rhs );

/// \relates int4x2
/// \brief Dot products each row of the left-hand matrix with the corresponding column of the right-hand matrix.
inline int4x4 operator*=( int4x2& lhs, const int2x4& rhs );

/// \relates int4x2
/// \brief Returns a copy of the int4x2 that has been component-wise divided by the given scalar value.
inline int4x2 operator/( const int4x2& lhs, const int32_t rhs );

/// \relates int4x2
/// \brief Divides each component by the given scalar value.
inline int4x2 operator/=( int4x2& lhs, const int32_t rhs );

/// \relates int4x2
/// \brief Returns a copy of the int4x2 that has been component-wise divided by the corresponding component of the right-hand int4x2.
inline int4x2 operator/( const int4x2& lhs, const int4x2& rhs );

/// \relates int4x2
/// \brief Prefix increment operator.  Adds one to each component of the given int4x2 before evaluation.
inline int4x2& operator++( int4x2& lhs );

/// \relates int4x2
/// \brief Postfix increment operator.  Adds one to each component of the given int4x2 after evaluation.
inline int4x2& operator++( int4x2& lhs, const int );

/// \relates int4x2
/// \brief Prefix decrement operator.  Subtracts one from each component of the given int4x2 before evaluation.
inline int4x2& operator--( int4x2& lhs );

/// \relates int4x2
/// \brief Postfix decrement operator.  Subtracts one from each component of the given int4x2 after evaluation.
inline int4x2& operator--( int4x2& lhs, const int );

/// \relates int4x2
/// \brief Returns a bool4x2 where each component is true if the component of the left-hand type is less than the corresponding right-hand type component.
inline bool4x2 operator<( const int4x2& lhs, const int4x2& rhs );

/// \relates int4x2
/// \brief Returns a bool4x2 where each component is true if the component of the left-hand type is less than or equal to the corresponding right-hand type component.
inline bool4x2 operator<=( const int4x2& lhs, const int4x2& rhs );

/// \relates int4x2
/// \brief Returns a bool4x2 where each component is true if the component of the left-hand type is greater than the corresponding right-hand type component.
inline bool4x2 operator>( const int4x2& lhs, const int4x2& rhs );

/// \relates int4x2
/// \brief Returns a bool4x2 where each component is true if the component of the left-hand type is greater than or equal to the corresponding right-hand type component.
inline bool4x2 operator>=( const int4x2& lhs, const int4x2& rhs );

/// \relates int4x2
/// \brief Returns a copy of the int4x2 where each component has been bitwise AND'd against the given scalar value.
inline int4x2 operator&( const int4x2& lhs, const int32_t& rhs );

/// \relates int4x2
/// \brief Performs a bitwise AND on the given left-hand int4x2 against the given scalar value.
inline int4x2 operator&=( int4x2& lhs, const int32_t& rhs );

/// \relates int4x2
/// \brief Returns a copy of the int4x2 where each component of the left-hand int4x2 has been bitwise AND'd against the corresponding component of the right-hand side int4x2.
inline int4x2 operator&( const int4x2& lhs, const int4x2& rhs );

/// \relates int4x2
/// \brief Performs a bitwise AND on the given left-hand int4x2 against the corresponding component of the given right-hand int4x2.
inline int4x2 operator&=( int4x2& lhs, const int4x2& rhs );

/// \relates int4x2
/// \brief Returns a copy of the int4x2 where each component has been bitwise OR'd against the given scalar value.
inline int4x2 operator|( const int4x2& lhs, const int32_t& rhs );

/// \relates int4x2
/// \brief Performs a bitwise OR on the given left-hand int4x2 against the given scalar value.
inline int4x2 operator|=( int4x2& lhs, const int32_t& rhs );

/// \relates int4x2
/// \brief Returns a copy of the int4x2 where each component of the left-hand int4x2 has been bitwise OR'd against the corresponding component of the right-hand side int4x2.
inline int4x2 operator|( const int4x2& lhs, const int4x2& rhs );

/// \relates int4x2
/// \brief Performs a bitwise OR on the given left-hand int4x2 against the corresponding component of the given right-hand int4x2.
inline int4x2 operator|=( int4x2& lhs, const int4x2& rhs );

/// \relates int4x2
/// \brief Returns a copy of the int4x2 where each component has been bitwise XOR'd against the given scalar value.
inline int4x2 operator^( const int4x2& lhs, const int32_t& rhs );

/// \relates int4x2
/// \brief Performs a bitwise XOR on the given left-hand int4x2 against the given scalar value.
inline int4x2 operator^=( int4x2& lhs, const int32_t& rhs );

/// \relates int4x2
/// \brief Returns a copy of the int4x2 where each component of the left-hand int4x2 has been bitwise XOR'd against the corresponding component of the right-hand side int4x2.
inline int4x2 operator^( const int4x2& lhs, const int4x2& rhs );

/// \relates int4x2
/// \brief Performs a bitwise XOR on the given left-hand int4x2 against the corresponding component of the given right-hand int4x2.
inline int4x2 operator^=( int4x2& lhs, const int4x2& rhs );

/// \relates int4x2
/// \brief Returns a copy of the int4x2 where each component has been bitwise left-shifted by the given scalar value.
inline int4x2 operator<<( const int4x2& lhs, const int32_t& rhs );

/// \relates int4x2
/// \brief Performs a left bitshift on the given left-hand int4x2 by the given scalar value.
inline int4x2 operator<<=( int4x2& lhs, const int32_t& rhs );

/// \relates int4x2
/// \brief Returns a copy of the int4x2 where each component of the left-hand int4x2 has been bitwise left-shifted by the corresponding component of the right-hand side int4x2.
inline int4x2 operator<<( const int4x2& lhs, const int4x2& rhs );

/// \relates int4x2
/// \brief Performs a left bitshift on the given left-hand int4x2 by the corresponding component of the given right-hand int4x2.
inline int4x2 operator<<=( int4x2& lhs, const int4x2& rhs );

/// \relates int4x2
/// \brief Returns a copy of the int4x2 where each component has been bitwise right-shifted by the given scalar value.
inline int4x2 operator>>( const int4x2& lhs, const int32_t& rhs );

/// \relates int4x2
/// \brief Performs a right bitshift on the given left-hand int4x2 by the given scalar value.
inline int4x2 operator>>=( int4x2& lhs, const int32_t& rhs );

/// \relates int4x2
/// \brief Returns a copy of the int4x2 where each component of the left-hand int4x2 has been bitwise right-shifted by the corresponding component of the right-hand side int4x2.
inline int4x2 operator>>( const int4x2& lhs, const int4x2& rhs );

/// \relates int4x2
/// \brief Performs a right bitshift on the given left-hand int4x2 by the corresponding component of the given right-hand int4x2.
inline int4x2 operator>>=( int4x2& lhs, const int4x2& rhs );

/// \relates int4x2
/// \brief Performs a unary bitwise operation on all components of the given int4x2.
inline int4x2 operator~( const int4x2& lhs );


// int4x3
/// \relates int4x3
/// \brief Returns a copy of the int4x3 that has been component-wise added by the given scalar value.
inline int4x3 operator+( const int4x3& lhs, const int32_t rhs );

/// \relates int4x3
/// \brief Adds each component by the given scalar value.
inline int4x3 operator+=( int4x3& lhs, const int32_t rhs );

/// \relates int4x3
/// \brief Returns a copy of the int4x3 that has been component-wise added by the corresponding component of the right-hand int4x3.
inline int4x3 operator+( const int4x3& lhs, const int4x3& rhs );

/// \relates int4x3
/// \brief Adds each component of the int4x3 by the corresponding component of the right-hand int4x3.
inline int4x3 operator+=( int4x3& lhs, const int4x3& rhs );

/// \relates int4x3
/// \brief Returns a copy of the int4x3 that has been component-wise subtracted by the given scalar value.
inline int4x3 operator-( const int4x3& lhs, const int32_t rhs );

/// \relates int4x3
/// \brief Subtracts each component by the given scalar value.
inline int4x3 operator-=( int4x3& lhs, const int32_t rhs );

/// \relates int4x3
/// \brief Returns a copy of the int4x3 that has been component-wise subtracted by the corresponding component of the right-hand int4x3.
inline int4x3 operator-( const int4x3& lhs, const int4x3& rhs );

/// \relates int4x3
/// \brief Subtracts each component of the int4x3 by the corresponding component of the right-hand int4x3.
inline int4x3 operator-=( int4x3& lhs, const int4x3& rhs );

/// \relates int4x3
/// \brief Returns a copy of the int4x3 that has been component-wise multiplied by the given scalar value.
inline int4x3 operator*( const int4x3& lhs, const int32_t rhs );

/// \relates int4x3
/// \brief Multiplies each component by the given scalar value.
inline int4x3 operator*=( int4x3& lhs, const int32_t rhs );

/// \relates int4x3
/// \brief Returns a copy of the matrix where each row of the left-hand matrix has been dot-producted by the corresponding column of the right-hand matrix.
inline int4x4 operator*( const int4x3& lhs, const int3x4& rhs );

/// \relates int4x3
/// \brief Dot products each row of the left-hand matrix with the corresponding column of the right-hand matrix.
inline int4x4 operator*=( int4x3& lhs, const int3x4& rhs );

/// \relates int4x3
/// \brief Returns a copy of the int4x3 that has been component-wise divided by the given scalar value.
inline int4x3 operator/( const int4x3& lhs, const int32_t rhs );

/// \relates int4x3
/// \brief Divides each component by the given scalar value.
inline int4x3 operator/=( int4x3& lhs, const int32_t rhs );

/// \relates int4x3
/// \brief Returns a copy of the int4x3 that has been component-wise divided by the corresponding component of the right-hand int4x3.
inline int4x3 operator/( const int4x3& lhs, const int4x3& rhs );

/// \relates int4x3
/// \brief Prefix increment operator.  Adds one to each component of the given int4x3 before evaluation.
inline int4x3& operator++( int4x3& lhs );

/// \relates int4x3
/// \brief Postfix increment operator.  Adds one to each component of the given int4x3 after evaluation.
inline int4x3& operator++( int4x3& lhs, const int );

/// \relates int4x3
/// \brief Prefix decrement operator.  Subtracts one from each component of the given int4x3 before evaluation.
inline int4x3& operator--( int4x3& lhs );

/// \relates int4x3
/// \brief Postfix decrement operator.  Subtracts one from each component of the given int4x3 after evaluation.
inline int4x3& operator--( int4x3& lhs, const int );

/// \relates int4x3
/// \brief Returns a bool4x3 where each component is true if the component of the left-hand type is less than the corresponding right-hand type component.
inline bool4x3 operator<( const int4x3& lhs, const int4x3& rhs );

/// \relates int4x3
/// \brief Returns a bool4x3 where each component is true if the component of the left-hand type is less than or equal to the corresponding right-hand type component.
inline bool4x3 operator<=( const int4x3& lhs, const int4x3& rhs );

/// \relates int4x3
/// \brief Returns a bool4x3 where each component is true if the component of the left-hand type is greater than the corresponding right-hand type component.
inline bool4x3 operator>( const int4x3& lhs, const int4x3& rhs );

/// \relates int4x3
/// \brief Returns a bool4x3 where each component is true if the component of the left-hand type is greater than or equal to the corresponding right-hand type component.
inline bool4x3 operator>=( const int4x3& lhs, const int4x3& rhs );

/// \relates int4x3
/// \brief Returns a copy of the int4x3 where each component has been bitwise AND'd against the given scalar value.
inline int4x3 operator&( const int4x3& lhs, const int32_t& rhs );

/// \relates int4x3
/// \brief Performs a bitwise AND on the given left-hand int4x3 against the given scalar value.
inline int4x3 operator&=( int4x3& lhs, const int32_t& rhs );

/// \relates int4x3
/// \brief Returns a copy of the int4x3 where each component of the left-hand int4x3 has been bitwise AND'd against the corresponding component of the right-hand side int4x3.
inline int4x3 operator&( const int4x3& lhs, const int4x3& rhs );

/// \relates int4x3
/// \brief Performs a bitwise AND on the given left-hand int4x3 against the corresponding component of the given right-hand int4x3.
inline int4x3 operator&=( int4x3& lhs, const int4x3& rhs );

/// \relates int4x3
/// \brief Returns a copy of the int4x3 where each component has been bitwise OR'd against the given scalar value.
inline int4x3 operator|( const int4x3& lhs, const int32_t& rhs );

/// \relates int4x3
/// \brief Performs a bitwise OR on the given left-hand int4x3 against the given scalar value.
inline int4x3 operator|=( int4x3& lhs, const int32_t& rhs );

/// \relates int4x3
/// \brief Returns a copy of the int4x3 where each component of the left-hand int4x3 has been bitwise OR'd against the corresponding component of the right-hand side int4x3.
inline int4x3 operator|( const int4x3& lhs, const int4x3& rhs );

/// \relates int4x3
/// \brief Performs a bitwise OR on the given left-hand int4x3 against the corresponding component of the given right-hand int4x3.
inline int4x3 operator|=( int4x3& lhs, const int4x3& rhs );

/// \relates int4x3
/// \brief Returns a copy of the int4x3 where each component has been bitwise XOR'd against the given scalar value.
inline int4x3 operator^( const int4x3& lhs, const int32_t& rhs );

/// \relates int4x3
/// \brief Performs a bitwise XOR on the given left-hand int4x3 against the given scalar value.
inline int4x3 operator^=( int4x3& lhs, const int32_t& rhs );

/// \relates int4x3
/// \brief Returns a copy of the int4x3 where each component of the left-hand int4x3 has been bitwise XOR'd against the corresponding component of the right-hand side int4x3.
inline int4x3 operator^( const int4x3& lhs, const int4x3& rhs );

/// \relates int4x3
/// \brief Performs a bitwise XOR on the given left-hand int4x3 against the corresponding component of the given right-hand int4x3.
inline int4x3 operator^=( int4x3& lhs, const int4x3& rhs );

/// \relates int4x3
/// \brief Returns a copy of the int4x3 where each component has been bitwise left-shifted by the given scalar value.
inline int4x3 operator<<( const int4x3& lhs, const int32_t& rhs );

/// \relates int4x3
/// \brief Performs a left bitshift on the given left-hand int4x3 by the given scalar value.
inline int4x3 operator<<=( int4x3& lhs, const int32_t& rhs );

/// \relates int4x3
/// \brief Returns a copy of the int4x3 where each component of the left-hand int4x3 has been bitwise left-shifted by the corresponding component of the right-hand side int4x3.
inline int4x3 operator<<( const int4x3& lhs, const int4x3& rhs );

/// \relates int4x3
/// \brief Performs a left bitshift on the given left-hand int4x3 by the corresponding component of the given right-hand int4x3.
inline int4x3 operator<<=( int4x3& lhs, const int4x3& rhs );

/// \relates int4x3
/// \brief Returns a copy of the int4x3 where each component has been bitwise right-shifted by the given scalar value.
inline int4x3 operator>>( const int4x3& lhs, const int32_t& rhs );

/// \relates int4x3
/// \brief Performs a right bitshift on the given left-hand int4x3 by the given scalar value.
inline int4x3 operator>>=( int4x3& lhs, const int32_t& rhs );

/// \relates int4x3
/// \brief Returns a copy of the int4x3 where each component of the left-hand int4x3 has been bitwise right-shifted by the corresponding component of the right-hand side int4x3.
inline int4x3 operator>>( const int4x3& lhs, const int4x3& rhs );

/// \relates int4x3
/// \brief Performs a right bitshift on the given left-hand int4x3 by the corresponding component of the given right-hand int4x3.
inline int4x3 operator>>=( int4x3& lhs, const int4x3& rhs );

/// \relates int4x3
/// \brief Performs a unary bitwise operation on all components of the given int4x3.
inline int4x3 operator~( const int4x3& lhs );


// int4x4
/// \relates int4x4
/// \brief Returns a copy of the int4x4 that has been component-wise added by the given scalar value.
inline int4x4 operator+( const int4x4& lhs, const int32_t rhs );

/// \relates int4x4
/// \brief Adds each component by the given scalar value.
inline int4x4 operator+=( int4x4& lhs, const int32_t rhs );

/// \relates int4x4
/// \brief Returns a copy of the int4x4 that has been component-wise added by the corresponding component of the right-hand int4x4.
inline int4x4 operator+( const int4x4& lhs, const int4x4& rhs );

/// \relates int4x4
/// \brief Adds each component of the int4x4 by the corresponding component of the right-hand int4x4.
inline int4x4 operator+=( int4x4& lhs, const int4x4& rhs );

/// \relates int4x4
/// \brief Returns a copy of the int4x4 that has been component-wise subtracted by the given scalar value.
inline int4x4 operator-( const int4x4& lhs, const int32_t rhs );

/// \relates int4x4
/// \brief Subtracts each component by the given scalar value.
inline int4x4 operator-=( int4x4& lhs, const int32_t rhs );

/// \relates int4x4
/// \brief Returns a copy of the int4x4 that has been component-wise subtracted by the corresponding component of the right-hand int4x4.
inline int4x4 operator-( const int4x4& lhs, const int4x4& rhs );

/// \relates int4x4
/// \brief Subtracts each component of the int4x4 by the corresponding component of the right-hand int4x4.
inline int4x4 operator-=( int4x4& lhs, const int4x4& rhs );

/// \relates int4x4
/// \brief Returns a copy of the int4x4 that has been component-wise multiplied by the given scalar value.
inline int4x4 operator*( const int4x4& lhs, const int32_t rhs );

/// \relates int4x4
/// \brief Multiplies each component by the given scalar value.
inline int4x4 operator*=( int4x4& lhs, const int32_t rhs );

/// \relates int4x4
/// \brief Returns a copy of the matrix where each row of the left-hand matrix has been dot-producted by the corresponding column of the right-hand matrix.
inline int4x4 operator*( const int4x4& lhs, const int4x4& rhs );

/// \relates int4x4
/// \brief Dot products each row of the left-hand matrix with the corresponding column of the right-hand matrix.
inline int4x4 operator*=( int4x4& lhs, const int4x4& rhs );

/// \relates int4x4
/// \brief Returns a copy of the int4x4 that has been component-wise divided by the given scalar value.
inline int4x4 operator/( const int4x4& lhs, const int32_t rhs );

/// \relates int4x4
/// \brief Divides each component by the given scalar value.
inline int4x4 operator/=( int4x4& lhs, const int32_t rhs );

/// \relates int4x4
/// \brief Returns a copy of the int4x4 that has been component-wise divided by the corresponding component of the right-hand int4x4.
inline int4x4 operator/( const int4x4& lhs, const int4x4& rhs );

/// \relates int4x4
/// \brief Divides each component of the int4x4 by the corresponding component of the right-hand int4x4.
inline int4x4 operator/=( int4x4& lhs, const int4x4& rhs );

/// \relates int4x4
/// \brief Prefix increment operator.  Adds one to each component of the given int4x4 before evaluation.
inline int4x4& operator++( int4x4& lhs );

/// \relates int4x4
/// \brief Postfix increment operator.  Adds one to each component of the given int4x4 after evaluation.
inline int4x4& operator++( int4x4& lhs, const int );

/// \relates int4x4
/// \brief Prefix decrement operator.  Subtracts one from each component of the given int4x4 before evaluation.
inline int4x4& operator--( int4x4& lhs );

/// \relates int4x4
/// \brief Postfix decrement operator.  Subtracts one from each component of the given int4x4 after evaluation.
inline int4x4& operator--( int4x4& lhs, const int );

/// \relates int4x4
/// \brief Returns a bool4x4 where each component is true if the component of the left-hand type is less than the corresponding right-hand type component.
inline bool4x4 operator<( const int4x4& lhs, const int4x4& rhs );

/// \relates int4x4
/// \brief Returns a bool4x4 where each component is true if the component of the left-hand type is less than or equal to the corresponding right-hand type component.
inline bool4x4 operator<=( const int4x4& lhs, const int4x4& rhs );

/// \relates int4x4
/// \brief Returns a bool4x4 where each component is true if the component of the left-hand type is greater than the corresponding right-hand type component.
inline bool4x4 operator>( const int4x4& lhs, const int4x4& rhs );

/// \relates int4x4
/// \brief Returns a bool4x4 where each component is true if the component of the left-hand type is greater than or equal to the corresponding right-hand type component.
inline bool4x4 operator>=( const int4x4& lhs, const int4x4& rhs );

/// \relates int4x4
/// \brief Returns a copy of the int4x4 where each component has been bitwise AND'd against the given scalar value.
inline int4x4 operator&( const int4x4& lhs, const int32_t& rhs );

/// \relates int4x4
/// \brief Performs a bitwise AND on the given left-hand int4x4 against the given scalar value.
inline int4x4 operator&=( int4x4& lhs, const int32_t& rhs );

/// \relates int4x4
/// \brief Returns a copy of the int4x4 where each component of the left-hand int4x4 has been bitwise AND'd against the corresponding component of the right-hand side int4x4.
inline int4x4 operator&( const int4x4& lhs, const int4x4& rhs );

/// \relates int4x4
/// \brief Performs a bitwise AND on the given left-hand int4x4 against the corresponding component of the given right-hand int4x4.
inline int4x4 operator&=( int4x4& lhs, const int4x4& rhs );

/// \relates int4x4
/// \brief Returns a copy of the int4x4 where each component has been bitwise OR'd against the given scalar value.
inline int4x4 operator|( const int4x4& lhs, const int32_t& rhs );

/// \relates int4x4
/// \brief Performs a bitwise OR on the given left-hand int4x4 against the given scalar value.
inline int4x4 operator|=( int4x4& lhs, const int32_t& rhs );

/// \relates int4x4
/// \brief Returns a copy of the int4x4 where each component of the left-hand int4x4 has been bitwise OR'd against the corresponding component of the right-hand side int4x4.
inline int4x4 operator|( const int4x4& lhs, const int4x4& rhs );

/// \relates int4x4
/// \brief Performs a bitwise OR on the given left-hand int4x4 against the corresponding component of the given right-hand int4x4.
inline int4x4 operator|=( int4x4& lhs, const int4x4& rhs );

/// \relates int4x4
/// \brief Returns a copy of the int4x4 where each component has been bitwise XOR'd against the given scalar value.
inline int4x4 operator^( const int4x4& lhs, const int32_t& rhs );

/// \relates int4x4
/// \brief Performs a bitwise XOR on the given left-hand int4x4 against the given scalar value.
inline int4x4 operator^=( int4x4& lhs, const int32_t& rhs );

/// \relates int4x4
/// \brief Returns a copy of the int4x4 where each component of the left-hand int4x4 has been bitwise XOR'd against the corresponding component of the right-hand side int4x4.
inline int4x4 operator^( const int4x4& lhs, const int4x4& rhs );

/// \relates int4x4
/// \brief Performs a bitwise XOR on the given left-hand int4x4 against the corresponding component of the given right-hand int4x4.
inline int4x4 operator^=( int4x4& lhs, const int4x4& rhs );

/// \relates int4x4
/// \brief Returns a copy of the int4x4 where each component has been bitwise left-shifted by the given scalar value.
inline int4x4 operator<<( const int4x4& lhs, const int32_t& rhs );

/// \relates int4x4
/// \brief Performs a left bitshift on the given left-hand int4x4 by the given scalar value.
inline int4x4 operator<<=( int4x4& lhs, const int32_t& rhs );

/// \relates int4x4
/// \brief Returns a copy of the int4x4 where each component of the left-hand int4x4 has been bitwise left-shifted by the corresponding component of the right-hand side int4x4.
inline int4x4 operator<<( const int4x4& lhs, const int4x4& rhs );

/// \relates int4x4
/// \brief Performs a left bitshift on the given left-hand int4x4 by the corresponding component of the given right-hand int4x4.
inline int4x4 operator<<=( int4x4& lhs, const int4x4& rhs );

/// \relates int4x4
/// \brief Returns a copy of the int4x4 where each component has been bitwise right-shifted by the given scalar value.
inline int4x4 operator>>( const int4x4& lhs, const int32_t& rhs );

/// \relates int4x4
/// \brief Performs a right bitshift on the given left-hand int4x4 by the given scalar value.
inline int4x4 operator>>=( int4x4& lhs, const int32_t& rhs );

/// \relates int4x4
/// \brief Returns a copy of the int4x4 where each component of the left-hand int4x4 has been bitwise right-shifted by the corresponding component of the right-hand side int4x4.
inline int4x4 operator>>( const int4x4& lhs, const int4x4& rhs );

/// \relates int4x4
/// \brief Performs a right bitshift on the given left-hand int4x4 by the corresponding component of the given right-hand int4x4.
inline int4x4 operator>>=( int4x4& lhs, const int4x4& rhs );

/// \relates int4x4
/// \brief Performs a unary bitwise operation on all components of the given int4x4.
inline int4x4 operator~( const int4x4& lhs );


// uint2x2
/// \relates uint2x2
/// \brief Returns a copy of the uint2x2 that has been component-wise added by the given scalar value.
inline uint2x2 operator+( const uint2x2& lhs, const uint32_t rhs );

/// \relates uint2x2
/// \brief Adds each component by the given scalar value.
inline uint2x2 operator+=( uint2x2& lhs, const uint32_t rhs );

/// \relates uint2x2
/// \brief Returns a copy of the uint2x2 that has been component-wise added by the corresponding component of the right-hand uint2x2.
inline uint2x2 operator+( const uint2x2& lhs, const uint2x2& rhs );

/// \relates uint2x2
/// \brief Adds each component of the uint2x2 by the corresponding component of the right-hand uint2x2.
inline uint2x2 operator+=( uint2x2& lhs, const uint2x2& rhs );

/// \relates uint2x2
/// \brief Returns a copy of the uint2x2 that has been component-wise subtracted by the given scalar value.
inline uint2x2 operator-( const uint2x2& lhs, const uint32_t rhs );

/// \relates uint2x2
/// \brief Subtracts each component by the given scalar value.
inline uint2x2 operator-=( uint2x2& lhs, const uint32_t rhs );

/// \relates uint2x2
/// \brief Returns a copy of the uint2x2 that has been component-wise subtracted by the corresponding component of the right-hand uint2x2.
inline uint2x2 operator-( const uint2x2& lhs, const uint2x2& rhs );

/// \relates uint2x2
/// \brief Subtracts each component of the uint2x2 by the corresponding component of the right-hand uint2x2.
inline uint2x2 operator-=( uint2x2& lhs, const uint2x2& rhs );

/// \relates uint2x2
/// \brief Returns a copy of the uint2x2 that has been component-wise multiplied by the given scalar value.
inline uint2x2 operator*( const uint2x2& lhs, const uint32_t rhs );

/// \relates uint2x2
/// \brief Multiplies each component by the given scalar value.
inline uint2x2 operator*=( uint2x2& lhs, const uint32_t rhs );

/// \relates uint2x2
/// \brief Returns a copy of the matrix where each row of the left-hand matrix has been dot-producted by the corresponding column of the right-hand matrix.
inline uint2x2 operator*( const uint2x2& lhs, const uint2x2& rhs );

/// \relates uint2x2
/// \brief Dot products each row of the left-hand matrix with the corresponding column of the right-hand matrix.
inline uint2x2 operator*=( uint2x2& lhs, const uint2x2& rhs );

/// \relates uint2x2
/// \brief Returns a copy of the uint2x2 that has been component-wise divided by the given scalar value.
inline uint2x2 operator/( const uint2x2& lhs, const uint32_t rhs );

/// \relates uint2x2
/// \brief Divides each component by the given scalar value.
inline uint2x2 operator/=( uint2x2& lhs, const uint32_t rhs );

/// \relates uint2x2
/// \brief Returns a copy of the uint2x2 that has been component-wise divided by the corresponding component of the right-hand uint2x2.
inline uint2x2 operator/( const uint2x2& lhs, const uint2x2& rhs );

/// \relates uint2x2
/// \brief Divides each component of the uint2x2 by the corresponding component of the right-hand uint2x2.
inline uint2x2 operator/=( uint2x2& lhs, const uint2x2& rhs );

/// \relates uint2x2
/// \brief Prefix increment operator.  Adds one to each component of the given uint2x2 before evaluation.
inline uint2x2& operator++( uint2x2& lhs );

/// \relates uint2x2
/// \brief Postfix increment operator.  Adds one to each component of the given uint2x2 after evaluation.
inline uint2x2& operator++( uint2x2& lhs, const int );

/// \relates uint2x2
/// \brief Prefix decrement operator.  Subtracts one from each component of the given uint2x2 before evaluation.
inline uint2x2& operator--( uint2x2& lhs );

/// \relates uint2x2
/// \brief Postfix decrement operator.  Subtracts one from each component of the given uint2x2 after evaluation.
inline uint2x2& operator--( uint2x2& lhs, const int );

/// \relates uint2x2
/// \brief Returns a bool2x2 where each component is true if the component of the left-hand type is less than the corresponding right-hand type component.
inline bool2x2 operator<( const uint2x2& lhs, const uint2x2& rhs );

/// \relates uint2x2
/// \brief Returns a bool2x2 where each component is true if the component of the left-hand type is less than or equal to the corresponding right-hand type component.
inline bool2x2 operator<=( const uint2x2& lhs, const uint2x2& rhs );

/// \relates uint2x2
/// \brief Returns a bool2x2 where each component is true if the component of the left-hand type is greater than the corresponding right-hand type component.
inline bool2x2 operator>( const uint2x2& lhs, const uint2x2& rhs );

/// \relates uint2x2
/// \brief Returns a bool2x2 where each component is true if the component of the left-hand type is greater than or equal to the corresponding right-hand type component.
inline bool2x2 operator>=( const uint2x2& lhs, const uint2x2& rhs );

/// \relates uint2x2
/// \brief Returns a copy of the uint2x2 where each component has been bitwise AND'd against the given scalar value.
inline uint2x2 operator&( const uint2x2& lhs, const uint32_t& rhs );

/// \relates uint2x2
/// \brief Performs a bitwise AND on the given left-hand uint2x2 against the given scalar value.
inline uint2x2 operator&=( uint2x2& lhs, const uint32_t& rhs );

/// \relates uint2x2
/// \brief Returns a copy of the uint2x2 where each component of the left-hand uint2x2 has been bitwise AND'd against the corresponding component of the right-hand side uint2x2.
inline uint2x2 operator&( const uint2x2& lhs, const uint2x2& rhs );

/// \relates uint2x2
/// \brief Performs a bitwise AND on the given left-hand uint2x2 against the corresponding component of the given right-hand uint2x2.
inline uint2x2 operator&=( uint2x2& lhs, const uint2x2& rhs );

/// \relates uint2x2
/// \brief Returns a copy of the uint2x2 where each component has been bitwise OR'd against the given scalar value.
inline uint2x2 operator|( const uint2x2& lhs, const uint32_t& rhs );

/// \relates uint2x2
/// \brief Performs a bitwise OR on the given left-hand uint2x2 against the given scalar value.
inline uint2x2 operator|=( uint2x2& lhs, const uint32_t& rhs );

/// \relates uint2x2
/// \brief Returns a copy of the uint2x2 where each component of the left-hand uint2x2 has been bitwise OR'd against the corresponding component of the right-hand side uint2x2.
inline uint2x2 operator|( const uint2x2& lhs, const uint2x2& rhs );

/// \relates uint2x2
/// \brief Performs a bitwise OR on the given left-hand uint2x2 against the corresponding component of the given right-hand uint2x2.
inline uint2x2 operator|=( uint2x2& lhs, const uint2x2& rhs );

/// \relates uint2x2
/// \brief Returns a copy of the uint2x2 where each component has been bitwise XOR'd against the given scalar value.
inline uint2x2 operator^( const uint2x2& lhs, const uint32_t& rhs );

/// \relates uint2x2
/// \brief Performs a bitwise XOR on the given left-hand uint2x2 against the given scalar value.
inline uint2x2 operator^=( uint2x2& lhs, const uint32_t& rhs );

/// \relates uint2x2
/// \brief Returns a copy of the uint2x2 where each component of the left-hand uint2x2 has been bitwise XOR'd against the corresponding component of the right-hand side uint2x2.
inline uint2x2 operator^( const uint2x2& lhs, const uint2x2& rhs );

/// \relates uint2x2
/// \brief Performs a bitwise XOR on the given left-hand uint2x2 against the corresponding component of the given right-hand uint2x2.
inline uint2x2 operator^=( uint2x2& lhs, const uint2x2& rhs );

/// \relates uint2x2
/// \brief Returns a copy of the uint2x2 where each component has been bitwise left-shifted by the given scalar value.
inline uint2x2 operator<<( const uint2x2& lhs, const uint32_t& rhs );

/// \relates uint2x2
/// \brief Performs a left bitshift on the given left-hand uint2x2 by the given scalar value.
inline uint2x2 operator<<=( uint2x2& lhs, const uint32_t& rhs );

/// \relates uint2x2
/// \brief Returns a copy of the uint2x2 where each component of the left-hand uint2x2 has been bitwise left-shifted by the corresponding component of the right-hand side uint2x2.
inline uint2x2 operator<<( const uint2x2& lhs, const uint2x2& rhs );

/// \relates uint2x2
/// \brief Performs a left bitshift on the given left-hand uint2x2 by the corresponding component of the given right-hand uint2x2.
inline uint2x2 operator<<=( uint2x2& lhs, const uint2x2& rhs );

/// \relates uint2x2
/// \brief Returns a copy of the uint2x2 where each component has been bitwise right-shifted by the given scalar value.
inline uint2x2 operator>>( const uint2x2& lhs, const uint32_t& rhs );

/// \relates uint2x2
/// \brief Performs a right bitshift on the given left-hand uint2x2 by the given scalar value.
inline uint2x2 operator>>=( uint2x2& lhs, const uint32_t& rhs );

/// \relates uint2x2
/// \brief Returns a copy of the uint2x2 where each component of the left-hand uint2x2 has been bitwise right-shifted by the corresponding component of the right-hand side uint2x2.
inline uint2x2 operator>>( const uint2x2& lhs, const uint2x2& rhs );

/// \relates uint2x2
/// \brief Performs a right bitshift on the given left-hand uint2x2 by the corresponding component of the given right-hand uint2x2.
inline uint2x2 operator>>=( uint2x2& lhs, const uint2x2& rhs );

/// \relates uint2x2
/// \brief Performs a unary bitwise operation on all components of the given uint2x2.
inline uint2x2 operator~( const uint2x2& lhs );


// uint2x3
/// \relates uint2x3
/// \brief Returns a copy of the uint2x3 that has been component-wise added by the given scalar value.
inline uint2x3 operator+( const uint2x3& lhs, const uint32_t rhs );

/// \relates uint2x3
/// \brief Adds each component by the given scalar value.
inline uint2x3 operator+=( uint2x3& lhs, const uint32_t rhs );

/// \relates uint2x3
/// \brief Returns a copy of the uint2x3 that has been component-wise added by the corresponding component of the right-hand uint2x3.
inline uint2x3 operator+( const uint2x3& lhs, const uint2x3& rhs );

/// \relates uint2x3
/// \brief Adds each component of the uint2x3 by the corresponding component of the right-hand uint2x3.
inline uint2x3 operator+=( uint2x3& lhs, const uint2x3& rhs );

/// \relates uint2x3
/// \brief Returns a copy of the uint2x3 that has been component-wise subtracted by the given scalar value.
inline uint2x3 operator-( const uint2x3& lhs, const uint32_t rhs );

/// \relates uint2x3
/// \brief Subtracts each component by the given scalar value.
inline uint2x3 operator-=( uint2x3& lhs, const uint32_t rhs );

/// \relates uint2x3
/// \brief Returns a copy of the uint2x3 that has been component-wise subtracted by the corresponding component of the right-hand uint2x3.
inline uint2x3 operator-( const uint2x3& lhs, const uint2x3& rhs );

/// \relates uint2x3
/// \brief Subtracts each component of the uint2x3 by the corresponding component of the right-hand uint2x3.
inline uint2x3 operator-=( uint2x3& lhs, const uint2x3& rhs );

/// \relates uint2x3
/// \brief Returns a copy of the uint2x3 that has been component-wise multiplied by the given scalar value.
inline uint2x3 operator*( const uint2x3& lhs, const uint32_t rhs );

/// \relates uint2x3
/// \brief Multiplies each component by the given scalar value.
inline uint2x3 operator*=( uint2x3& lhs, const uint32_t rhs );

/// \relates uint2x3
/// \brief Returns a copy of the matrix where each row of the left-hand matrix has been dot-producted by the corresponding column of the right-hand matrix.
inline uint2x2 operator*( const uint2x3& lhs, const uint3x2& rhs );

/// \relates uint2x3
/// \brief Dot products each row of the left-hand matrix with the corresponding column of the right-hand matrix.
inline uint2x2 operator*=( uint2x3& lhs, const uint3x2& rhs );

/// \relates uint2x3
/// \brief Returns a copy of the uint2x3 that has been component-wise divided by the given scalar value.
inline uint2x3 operator/( const uint2x3& lhs, const uint32_t rhs );

/// \relates uint2x3
/// \brief Divides each component by the given scalar value.
inline uint2x3 operator/=( uint2x3& lhs, const uint32_t rhs );

/// \relates uint2x3
/// \brief Returns a copy of the uint2x3 that has been component-wise divided by the corresponding component of the right-hand uint2x3.
inline uint2x3 operator/( const uint2x3& lhs, const uint2x3& rhs );

/// \relates uint2x3
/// \brief Prefix increment operator.  Adds one to each component of the given uint2x3 before evaluation.
inline uint2x3& operator++( uint2x3& lhs );

/// \relates uint2x3
/// \brief Postfix increment operator.  Adds one to each component of the given uint2x3 after evaluation.
inline uint2x3& operator++( uint2x3& lhs, const int );

/// \relates uint2x3
/// \brief Prefix decrement operator.  Subtracts one from each component of the given uint2x3 before evaluation.
inline uint2x3& operator--( uint2x3& lhs );

/// \relates uint2x3
/// \brief Postfix decrement operator.  Subtracts one from each component of the given uint2x3 after evaluation.
inline uint2x3& operator--( uint2x3& lhs, const int );

/// \relates uint2x3
/// \brief Returns a bool2x3 where each component is true if the component of the left-hand type is less than the corresponding right-hand type component.
inline bool2x3 operator<( const uint2x3& lhs, const uint2x3& rhs );

/// \relates uint2x3
/// \brief Returns a bool2x3 where each component is true if the component of the left-hand type is less than or equal to the corresponding right-hand type component.
inline bool2x3 operator<=( const uint2x3& lhs, const uint2x3& rhs );

/// \relates uint2x3
/// \brief Returns a bool2x3 where each component is true if the component of the left-hand type is greater than the corresponding right-hand type component.
inline bool2x3 operator>( const uint2x3& lhs, const uint2x3& rhs );

/// \relates uint2x3
/// \brief Returns a bool2x3 where each component is true if the component of the left-hand type is greater than or equal to the corresponding right-hand type component.
inline bool2x3 operator>=( const uint2x3& lhs, const uint2x3& rhs );

/// \relates uint2x3
/// \brief Returns a copy of the uint2x3 where each component has been bitwise AND'd against the given scalar value.
inline uint2x3 operator&( const uint2x3& lhs, const uint32_t& rhs );

/// \relates uint2x3
/// \brief Performs a bitwise AND on the given left-hand uint2x3 against the given scalar value.
inline uint2x3 operator&=( uint2x3& lhs, const uint32_t& rhs );

/// \relates uint2x3
/// \brief Returns a copy of the uint2x3 where each component of the left-hand uint2x3 has been bitwise AND'd against the corresponding component of the right-hand side uint2x3.
inline uint2x3 operator&( const uint2x3& lhs, const uint2x3& rhs );

/// \relates uint2x3
/// \brief Performs a bitwise AND on the given left-hand uint2x3 against the corresponding component of the given right-hand uint2x3.
inline uint2x3 operator&=( uint2x3& lhs, const uint2x3& rhs );

/// \relates uint2x3
/// \brief Returns a copy of the uint2x3 where each component has been bitwise OR'd against the given scalar value.
inline uint2x3 operator|( const uint2x3& lhs, const uint32_t& rhs );

/// \relates uint2x3
/// \brief Performs a bitwise OR on the given left-hand uint2x3 against the given scalar value.
inline uint2x3 operator|=( uint2x3& lhs, const uint32_t& rhs );

/// \relates uint2x3
/// \brief Returns a copy of the uint2x3 where each component of the left-hand uint2x3 has been bitwise OR'd against the corresponding component of the right-hand side uint2x3.
inline uint2x3 operator|( const uint2x3& lhs, const uint2x3& rhs );

/// \relates uint2x3
/// \brief Performs a bitwise OR on the given left-hand uint2x3 against the corresponding component of the given right-hand uint2x3.
inline uint2x3 operator|=( uint2x3& lhs, const uint2x3& rhs );

/// \relates uint2x3
/// \brief Returns a copy of the uint2x3 where each component has been bitwise XOR'd against the given scalar value.
inline uint2x3 operator^( const uint2x3& lhs, const uint32_t& rhs );

/// \relates uint2x3
/// \brief Performs a bitwise XOR on the given left-hand uint2x3 against the given scalar value.
inline uint2x3 operator^=( uint2x3& lhs, const uint32_t& rhs );

/// \relates uint2x3
/// \brief Returns a copy of the uint2x3 where each component of the left-hand uint2x3 has been bitwise XOR'd against the corresponding component of the right-hand side uint2x3.
inline uint2x3 operator^( const uint2x3& lhs, const uint2x3& rhs );

/// \relates uint2x3
/// \brief Performs a bitwise XOR on the given left-hand uint2x3 against the corresponding component of the given right-hand uint2x3.
inline uint2x3 operator^=( uint2x3& lhs, const uint2x3& rhs );

/// \relates uint2x3
/// \brief Returns a copy of the uint2x3 where each component has been bitwise left-shifted by the given scalar value.
inline uint2x3 operator<<( const uint2x3& lhs, const uint32_t& rhs );

/// \relates uint2x3
/// \brief Performs a left bitshift on the given left-hand uint2x3 by the given scalar value.
inline uint2x3 operator<<=( uint2x3& lhs, const uint32_t& rhs );

/// \relates uint2x3
/// \brief Returns a copy of the uint2x3 where each component of the left-hand uint2x3 has been bitwise left-shifted by the corresponding component of the right-hand side uint2x3.
inline uint2x3 operator<<( const uint2x3& lhs, const uint2x3& rhs );

/// \relates uint2x3
/// \brief Performs a left bitshift on the given left-hand uint2x3 by the corresponding component of the given right-hand uint2x3.
inline uint2x3 operator<<=( uint2x3& lhs, const uint2x3& rhs );

/// \relates uint2x3
/// \brief Returns a copy of the uint2x3 where each component has been bitwise right-shifted by the given scalar value.
inline uint2x3 operator>>( const uint2x3& lhs, const uint32_t& rhs );

/// \relates uint2x3
/// \brief Performs a right bitshift on the given left-hand uint2x3 by the given scalar value.
inline uint2x3 operator>>=( uint2x3& lhs, const uint32_t& rhs );

/// \relates uint2x3
/// \brief Returns a copy of the uint2x3 where each component of the left-hand uint2x3 has been bitwise right-shifted by the corresponding component of the right-hand side uint2x3.
inline uint2x3 operator>>( const uint2x3& lhs, const uint2x3& rhs );

/// \relates uint2x3
/// \brief Performs a right bitshift on the given left-hand uint2x3 by the corresponding component of the given right-hand uint2x3.
inline uint2x3 operator>>=( uint2x3& lhs, const uint2x3& rhs );

/// \relates uint2x3
/// \brief Performs a unary bitwise operation on all components of the given uint2x3.
inline uint2x3 operator~( const uint2x3& lhs );


// uint2x4
/// \relates uint2x4
/// \brief Returns a copy of the uint2x4 that has been component-wise added by the given scalar value.
inline uint2x4 operator+( const uint2x4& lhs, const uint32_t rhs );

/// \relates uint2x4
/// \brief Adds each component by the given scalar value.
inline uint2x4 operator+=( uint2x4& lhs, const uint32_t rhs );

/// \relates uint2x4
/// \brief Returns a copy of the uint2x4 that has been component-wise added by the corresponding component of the right-hand uint2x4.
inline uint2x4 operator+( const uint2x4& lhs, const uint2x4& rhs );

/// \relates uint2x4
/// \brief Adds each component of the uint2x4 by the corresponding component of the right-hand uint2x4.
inline uint2x4 operator+=( uint2x4& lhs, const uint2x4& rhs );

/// \relates uint2x4
/// \brief Returns a copy of the uint2x4 that has been component-wise subtracted by the given scalar value.
inline uint2x4 operator-( const uint2x4& lhs, const uint32_t rhs );

/// \relates uint2x4
/// \brief Subtracts each component by the given scalar value.
inline uint2x4 operator-=( uint2x4& lhs, const uint32_t rhs );

/// \relates uint2x4
/// \brief Returns a copy of the uint2x4 that has been component-wise subtracted by the corresponding component of the right-hand uint2x4.
inline uint2x4 operator-( const uint2x4& lhs, const uint2x4& rhs );

/// \relates uint2x4
/// \brief Subtracts each component of the uint2x4 by the corresponding component of the right-hand uint2x4.
inline uint2x4 operator-=( uint2x4& lhs, const uint2x4& rhs );

/// \relates uint2x4
/// \brief Returns a copy of the uint2x4 that has been component-wise multiplied by the given scalar value.
inline uint2x4 operator*( const uint2x4& lhs, const uint32_t rhs );

/// \relates uint2x4
/// \brief Multiplies each component by the given scalar value.
inline uint2x4 operator*=( uint2x4& lhs, const uint32_t rhs );

/// \relates uint2x4
/// \brief Returns a copy of the matrix where each row of the left-hand matrix has been dot-producted by the corresponding column of the right-hand matrix.
inline uint2x2 operator*( const uint2x4& lhs, const uint4x2& rhs );

/// \relates uint2x4
/// \brief Dot products each row of the left-hand matrix with the corresponding column of the right-hand matrix.
inline uint2x2 operator*=( uint2x4& lhs, const uint4x2& rhs );

/// \relates uint2x4
/// \brief Returns a copy of the uint2x4 that has been component-wise divided by the given scalar value.
inline uint2x4 operator/( const uint2x4& lhs, const uint32_t rhs );

/// \relates uint2x4
/// \brief Divides each component by the given scalar value.
inline uint2x4 operator/=( uint2x4& lhs, const uint32_t rhs );

/// \relates uint2x4
/// \brief Returns a copy of the uint2x4 that has been component-wise divided by the corresponding component of the right-hand uint2x4.
inline uint2x4 operator/( const uint2x4& lhs, const uint2x4& rhs );

/// \relates uint2x4
/// \brief Prefix increment operator.  Adds one to each component of the given uint2x4 before evaluation.
inline uint2x4& operator++( uint2x4& lhs );

/// \relates uint2x4
/// \brief Postfix increment operator.  Adds one to each component of the given uint2x4 after evaluation.
inline uint2x4& operator++( uint2x4& lhs, const int );

/// \relates uint2x4
/// \brief Prefix decrement operator.  Subtracts one from each component of the given uint2x4 before evaluation.
inline uint2x4& operator--( uint2x4& lhs );

/// \relates uint2x4
/// \brief Postfix decrement operator.  Subtracts one from each component of the given uint2x4 after evaluation.
inline uint2x4& operator--( uint2x4& lhs, const int );

/// \relates uint2x4
/// \brief Returns a bool2x4 where each component is true if the component of the left-hand type is less than the corresponding right-hand type component.
inline bool2x4 operator<( const uint2x4& lhs, const uint2x4& rhs );

/// \relates uint2x4
/// \brief Returns a bool2x4 where each component is true if the component of the left-hand type is less than or equal to the corresponding right-hand type component.
inline bool2x4 operator<=( const uint2x4& lhs, const uint2x4& rhs );

/// \relates uint2x4
/// \brief Returns a bool2x4 where each component is true if the component of the left-hand type is greater than the corresponding right-hand type component.
inline bool2x4 operator>( const uint2x4& lhs, const uint2x4& rhs );

/// \relates uint2x4
/// \brief Returns a bool2x4 where each component is true if the component of the left-hand type is greater than or equal to the corresponding right-hand type component.
inline bool2x4 operator>=( const uint2x4& lhs, const uint2x4& rhs );

/// \relates uint2x4
/// \brief Returns a copy of the uint2x4 where each component has been bitwise AND'd against the given scalar value.
inline uint2x4 operator&( const uint2x4& lhs, const uint32_t& rhs );

/// \relates uint2x4
/// \brief Performs a bitwise AND on the given left-hand uint2x4 against the given scalar value.
inline uint2x4 operator&=( uint2x4& lhs, const uint32_t& rhs );

/// \relates uint2x4
/// \brief Returns a copy of the uint2x4 where each component of the left-hand uint2x4 has been bitwise AND'd against the corresponding component of the right-hand side uint2x4.
inline uint2x4 operator&( const uint2x4& lhs, const uint2x4& rhs );

/// \relates uint2x4
/// \brief Performs a bitwise AND on the given left-hand uint2x4 against the corresponding component of the given right-hand uint2x4.
inline uint2x4 operator&=( uint2x4& lhs, const uint2x4& rhs );

/// \relates uint2x4
/// \brief Returns a copy of the uint2x4 where each component has been bitwise OR'd against the given scalar value.
inline uint2x4 operator|( const uint2x4& lhs, const uint32_t& rhs );

/// \relates uint2x4
/// \brief Performs a bitwise OR on the given left-hand uint2x4 against the given scalar value.
inline uint2x4 operator|=( uint2x4& lhs, const uint32_t& rhs );

/// \relates uint2x4
/// \brief Returns a copy of the uint2x4 where each component of the left-hand uint2x4 has been bitwise OR'd against the corresponding component of the right-hand side uint2x4.
inline uint2x4 operator|( const uint2x4& lhs, const uint2x4& rhs );

/// \relates uint2x4
/// \brief Performs a bitwise OR on the given left-hand uint2x4 against the corresponding component of the given right-hand uint2x4.
inline uint2x4 operator|=( uint2x4& lhs, const uint2x4& rhs );

/// \relates uint2x4
/// \brief Returns a copy of the uint2x4 where each component has been bitwise XOR'd against the given scalar value.
inline uint2x4 operator^( const uint2x4& lhs, const uint32_t& rhs );

/// \relates uint2x4
/// \brief Performs a bitwise XOR on the given left-hand uint2x4 against the given scalar value.
inline uint2x4 operator^=( uint2x4& lhs, const uint32_t& rhs );

/// \relates uint2x4
/// \brief Returns a copy of the uint2x4 where each component of the left-hand uint2x4 has been bitwise XOR'd against the corresponding component of the right-hand side uint2x4.
inline uint2x4 operator^( const uint2x4& lhs, const uint2x4& rhs );

/// \relates uint2x4
/// \brief Performs a bitwise XOR on the given left-hand uint2x4 against the corresponding component of the given right-hand uint2x4.
inline uint2x4 operator^=( uint2x4& lhs, const uint2x4& rhs );

/// \relates uint2x4
/// \brief Returns a copy of the uint2x4 where each component has been bitwise left-shifted by the given scalar value.
inline uint2x4 operator<<( const uint2x4& lhs, const uint32_t& rhs );

/// \relates uint2x4
/// \brief Performs a left bitshift on the given left-hand uint2x4 by the given scalar value.
inline uint2x4 operator<<=( uint2x4& lhs, const uint32_t& rhs );

/// \relates uint2x4
/// \brief Returns a copy of the uint2x4 where each component of the left-hand uint2x4 has been bitwise left-shifted by the corresponding component of the right-hand side uint2x4.
inline uint2x4 operator<<( const uint2x4& lhs, const uint2x4& rhs );

/// \relates uint2x4
/// \brief Performs a left bitshift on the given left-hand uint2x4 by the corresponding component of the given right-hand uint2x4.
inline uint2x4 operator<<=( uint2x4& lhs, const uint2x4& rhs );

/// \relates uint2x4
/// \brief Returns a copy of the uint2x4 where each component has been bitwise right-shifted by the given scalar value.
inline uint2x4 operator>>( const uint2x4& lhs, const uint32_t& rhs );

/// \relates uint2x4
/// \brief Performs a right bitshift on the given left-hand uint2x4 by the given scalar value.
inline uint2x4 operator>>=( uint2x4& lhs, const uint32_t& rhs );

/// \relates uint2x4
/// \brief Returns a copy of the uint2x4 where each component of the left-hand uint2x4 has been bitwise right-shifted by the corresponding component of the right-hand side uint2x4.
inline uint2x4 operator>>( const uint2x4& lhs, const uint2x4& rhs );

/// \relates uint2x4
/// \brief Performs a right bitshift on the given left-hand uint2x4 by the corresponding component of the given right-hand uint2x4.
inline uint2x4 operator>>=( uint2x4& lhs, const uint2x4& rhs );

/// \relates uint2x4
/// \brief Performs a unary bitwise operation on all components of the given uint2x4.
inline uint2x4 operator~( const uint2x4& lhs );


// uint3x2
/// \relates uint3x2
/// \brief Returns a copy of the uint3x2 that has been component-wise added by the given scalar value.
inline uint3x2 operator+( const uint3x2& lhs, const uint32_t rhs );

/// \relates uint3x2
/// \brief Adds each component by the given scalar value.
inline uint3x2 operator+=( uint3x2& lhs, const uint32_t rhs );

/// \relates uint3x2
/// \brief Returns a copy of the uint3x2 that has been component-wise added by the corresponding component of the right-hand uint3x2.
inline uint3x2 operator+( const uint3x2& lhs, const uint3x2& rhs );

/// \relates uint3x2
/// \brief Adds each component of the uint3x2 by the corresponding component of the right-hand uint3x2.
inline uint3x2 operator+=( uint3x2& lhs, const uint3x2& rhs );

/// \relates uint3x2
/// \brief Returns a copy of the uint3x2 that has been component-wise subtracted by the given scalar value.
inline uint3x2 operator-( const uint3x2& lhs, const uint32_t rhs );

/// \relates uint3x2
/// \brief Subtracts each component by the given scalar value.
inline uint3x2 operator-=( uint3x2& lhs, const uint32_t rhs );

/// \relates uint3x2
/// \brief Returns a copy of the uint3x2 that has been component-wise subtracted by the corresponding component of the right-hand uint3x2.
inline uint3x2 operator-( const uint3x2& lhs, const uint3x2& rhs );

/// \relates uint3x2
/// \brief Subtracts each component of the uint3x2 by the corresponding component of the right-hand uint3x2.
inline uint3x2 operator-=( uint3x2& lhs, const uint3x2& rhs );

/// \relates uint3x2
/// \brief Returns a copy of the uint3x2 that has been component-wise multiplied by the given scalar value.
inline uint3x2 operator*( const uint3x2& lhs, const uint32_t rhs );

/// \relates uint3x2
/// \brief Multiplies each component by the given scalar value.
inline uint3x2 operator*=( uint3x2& lhs, const uint32_t rhs );

/// \relates uint3x2
/// \brief Returns a copy of the matrix where each row of the left-hand matrix has been dot-producted by the corresponding column of the right-hand matrix.
inline uint3x3 operator*( const uint3x2& lhs, const uint2x3& rhs );

/// \relates uint3x2
/// \brief Dot products each row of the left-hand matrix with the corresponding column of the right-hand matrix.
inline uint3x3 operator*=( uint3x2& lhs, const uint2x3& rhs );

/// \relates uint3x2
/// \brief Returns a copy of the uint3x2 that has been component-wise divided by the given scalar value.
inline uint3x2 operator/( const uint3x2& lhs, const uint32_t rhs );

/// \relates uint3x2
/// \brief Divides each component by the given scalar value.
inline uint3x2 operator/=( uint3x2& lhs, const uint32_t rhs );

/// \relates uint3x2
/// \brief Returns a copy of the uint3x2 that has been component-wise divided by the corresponding component of the right-hand uint3x2.
inline uint3x2 operator/( const uint3x2& lhs, const uint3x2& rhs );

/// \relates uint3x2
/// \brief Prefix increment operator.  Adds one to each component of the given uint3x2 before evaluation.
inline uint3x2& operator++( uint3x2& lhs );

/// \relates uint3x2
/// \brief Postfix increment operator.  Adds one to each component of the given uint3x2 after evaluation.
inline uint3x2& operator++( uint3x2& lhs, const int );

/// \relates uint3x2
/// \brief Prefix decrement operator.  Subtracts one from each component of the given uint3x2 before evaluation.
inline uint3x2& operator--( uint3x2& lhs );

/// \relates uint3x2
/// \brief Postfix decrement operator.  Subtracts one from each component of the given uint3x2 after evaluation.
inline uint3x2& operator--( uint3x2& lhs, const int );

/// \relates uint3x2
/// \brief Returns a bool3x2 where each component is true if the component of the left-hand type is less than the corresponding right-hand type component.
inline bool3x2 operator<( const uint3x2& lhs, const uint3x2& rhs );

/// \relates uint3x2
/// \brief Returns a bool3x2 where each component is true if the component of the left-hand type is less than or equal to the corresponding right-hand type component.
inline bool3x2 operator<=( const uint3x2& lhs, const uint3x2& rhs );

/// \relates uint3x2
/// \brief Returns a bool3x2 where each component is true if the component of the left-hand type is greater than the corresponding right-hand type component.
inline bool3x2 operator>( const uint3x2& lhs, const uint3x2& rhs );

/// \relates uint3x2
/// \brief Returns a bool3x2 where each component is true if the component of the left-hand type is greater than or equal to the corresponding right-hand type component.
inline bool3x2 operator>=( const uint3x2& lhs, const uint3x2& rhs );

/// \relates uint3x2
/// \brief Returns a copy of the uint3x2 where each component has been bitwise AND'd against the given scalar value.
inline uint3x2 operator&( const uint3x2& lhs, const uint32_t& rhs );

/// \relates uint3x2
/// \brief Performs a bitwise AND on the given left-hand uint3x2 against the given scalar value.
inline uint3x2 operator&=( uint3x2& lhs, const uint32_t& rhs );

/// \relates uint3x2
/// \brief Returns a copy of the uint3x2 where each component of the left-hand uint3x2 has been bitwise AND'd against the corresponding component of the right-hand side uint3x2.
inline uint3x2 operator&( const uint3x2& lhs, const uint3x2& rhs );

/// \relates uint3x2
/// \brief Performs a bitwise AND on the given left-hand uint3x2 against the corresponding component of the given right-hand uint3x2.
inline uint3x2 operator&=( uint3x2& lhs, const uint3x2& rhs );

/// \relates uint3x2
/// \brief Returns a copy of the uint3x2 where each component has been bitwise OR'd against the given scalar value.
inline uint3x2 operator|( const uint3x2& lhs, const uint32_t& rhs );

/// \relates uint3x2
/// \brief Performs a bitwise OR on the given left-hand uint3x2 against the given scalar value.
inline uint3x2 operator|=( uint3x2& lhs, const uint32_t& rhs );

/// \relates uint3x2
/// \brief Returns a copy of the uint3x2 where each component of the left-hand uint3x2 has been bitwise OR'd against the corresponding component of the right-hand side uint3x2.
inline uint3x2 operator|( const uint3x2& lhs, const uint3x2& rhs );

/// \relates uint3x2
/// \brief Performs a bitwise OR on the given left-hand uint3x2 against the corresponding component of the given right-hand uint3x2.
inline uint3x2 operator|=( uint3x2& lhs, const uint3x2& rhs );

/// \relates uint3x2
/// \brief Returns a copy of the uint3x2 where each component has been bitwise XOR'd against the given scalar value.
inline uint3x2 operator^( const uint3x2& lhs, const uint32_t& rhs );

/// \relates uint3x2
/// \brief Performs a bitwise XOR on the given left-hand uint3x2 against the given scalar value.
inline uint3x2 operator^=( uint3x2& lhs, const uint32_t& rhs );

/// \relates uint3x2
/// \brief Returns a copy of the uint3x2 where each component of the left-hand uint3x2 has been bitwise XOR'd against the corresponding component of the right-hand side uint3x2.
inline uint3x2 operator^( const uint3x2& lhs, const uint3x2& rhs );

/// \relates uint3x2
/// \brief Performs a bitwise XOR on the given left-hand uint3x2 against the corresponding component of the given right-hand uint3x2.
inline uint3x2 operator^=( uint3x2& lhs, const uint3x2& rhs );

/// \relates uint3x2
/// \brief Returns a copy of the uint3x2 where each component has been bitwise left-shifted by the given scalar value.
inline uint3x2 operator<<( const uint3x2& lhs, const uint32_t& rhs );

/// \relates uint3x2
/// \brief Performs a left bitshift on the given left-hand uint3x2 by the given scalar value.
inline uint3x2 operator<<=( uint3x2& lhs, const uint32_t& rhs );

/// \relates uint3x2
/// \brief Returns a copy of the uint3x2 where each component of the left-hand uint3x2 has been bitwise left-shifted by the corresponding component of the right-hand side uint3x2.
inline uint3x2 operator<<( const uint3x2& lhs, const uint3x2& rhs );

/// \relates uint3x2
/// \brief Performs a left bitshift on the given left-hand uint3x2 by the corresponding component of the given right-hand uint3x2.
inline uint3x2 operator<<=( uint3x2& lhs, const uint3x2& rhs );

/// \relates uint3x2
/// \brief Returns a copy of the uint3x2 where each component has been bitwise right-shifted by the given scalar value.
inline uint3x2 operator>>( const uint3x2& lhs, const uint32_t& rhs );

/// \relates uint3x2
/// \brief Performs a right bitshift on the given left-hand uint3x2 by the given scalar value.
inline uint3x2 operator>>=( uint3x2& lhs, const uint32_t& rhs );

/// \relates uint3x2
/// \brief Returns a copy of the uint3x2 where each component of the left-hand uint3x2 has been bitwise right-shifted by the corresponding component of the right-hand side uint3x2.
inline uint3x2 operator>>( const uint3x2& lhs, const uint3x2& rhs );

/// \relates uint3x2
/// \brief Performs a right bitshift on the given left-hand uint3x2 by the corresponding component of the given right-hand uint3x2.
inline uint3x2 operator>>=( uint3x2& lhs, const uint3x2& rhs );

/// \relates uint3x2
/// \brief Performs a unary bitwise operation on all components of the given uint3x2.
inline uint3x2 operator~( const uint3x2& lhs );


// uint3x3
/// \relates uint3x3
/// \brief Returns a copy of the uint3x3 that has been component-wise added by the given scalar value.
inline uint3x3 operator+( const uint3x3& lhs, const uint32_t rhs );

/// \relates uint3x3
/// \brief Adds each component by the given scalar value.
inline uint3x3 operator+=( uint3x3& lhs, const uint32_t rhs );

/// \relates uint3x3
/// \brief Returns a copy of the uint3x3 that has been component-wise added by the corresponding component of the right-hand uint3x3.
inline uint3x3 operator+( const uint3x3& lhs, const uint3x3& rhs );

/// \relates uint3x3
/// \brief Adds each component of the uint3x3 by the corresponding component of the right-hand uint3x3.
inline uint3x3 operator+=( uint3x3& lhs, const uint3x3& rhs );

/// \relates uint3x3
/// \brief Returns a copy of the uint3x3 that has been component-wise subtracted by the given scalar value.
inline uint3x3 operator-( const uint3x3& lhs, const uint32_t rhs );

/// \relates uint3x3
/// \brief Subtracts each component by the given scalar value.
inline uint3x3 operator-=( uint3x3& lhs, const uint32_t rhs );

/// \relates uint3x3
/// \brief Returns a copy of the uint3x3 that has been component-wise subtracted by the corresponding component of the right-hand uint3x3.
inline uint3x3 operator-( const uint3x3& lhs, const uint3x3& rhs );

/// \relates uint3x3
/// \brief Subtracts each component of the uint3x3 by the corresponding component of the right-hand uint3x3.
inline uint3x3 operator-=( uint3x3& lhs, const uint3x3& rhs );

/// \relates uint3x3
/// \brief Returns a copy of the uint3x3 that has been component-wise multiplied by the given scalar value.
inline uint3x3 operator*( const uint3x3& lhs, const uint32_t rhs );

/// \relates uint3x3
/// \brief Multiplies each component by the given scalar value.
inline uint3x3 operator*=( uint3x3& lhs, const uint32_t rhs );

/// \relates uint3x3
/// \brief Returns a copy of the matrix where each row of the left-hand matrix has been dot-producted by the corresponding column of the right-hand matrix.
inline uint3x3 operator*( const uint3x3& lhs, const uint3x3& rhs );

/// \relates uint3x3
/// \brief Dot products each row of the left-hand matrix with the corresponding column of the right-hand matrix.
inline uint3x3 operator*=( uint3x3& lhs, const uint3x3& rhs );

/// \relates uint3x3
/// \brief Returns a copy of the uint3x3 that has been component-wise divided by the given scalar value.
inline uint3x3 operator/( const uint3x3& lhs, const uint32_t rhs );

/// \relates uint3x3
/// \brief Divides each component by the given scalar value.
inline uint3x3 operator/=( uint3x3& lhs, const uint32_t rhs );

/// \relates uint3x3
/// \brief Returns a copy of the uint3x3 that has been component-wise divided by the corresponding component of the right-hand uint3x3.
inline uint3x3 operator/( const uint3x3& lhs, const uint3x3& rhs );

/// \relates uint3x3
/// \brief Divides each component of the uint3x3 by the corresponding component of the right-hand uint3x3.
inline uint3x3 operator/=( uint3x3& lhs, const uint3x3& rhs );

/// \relates uint3x3
/// \brief Prefix increment operator.  Adds one to each component of the given uint3x3 before evaluation.
inline uint3x3& operator++( uint3x3& lhs );

/// \relates uint3x3
/// \brief Postfix increment operator.  Adds one to each component of the given uint3x3 after evaluation.
inline uint3x3& operator++( uint3x3& lhs, const int );

/// \relates uint3x3
/// \brief Prefix decrement operator.  Subtracts one from each component of the given uint3x3 before evaluation.
inline uint3x3& operator--( uint3x3& lhs );

/// \relates uint3x3
/// \brief Postfix decrement operator.  Subtracts one from each component of the given uint3x3 after evaluation.
inline uint3x3& operator--( uint3x3& lhs, const int );

/// \relates uint3x3
/// \brief Returns a bool3x3 where each component is true if the component of the left-hand type is less than the corresponding right-hand type component.
inline bool3x3 operator<( const uint3x3& lhs, const uint3x3& rhs );

/// \relates uint3x3
/// \brief Returns a bool3x3 where each component is true if the component of the left-hand type is less than or equal to the corresponding right-hand type component.
inline bool3x3 operator<=( const uint3x3& lhs, const uint3x3& rhs );

/// \relates uint3x3
/// \brief Returns a bool3x3 where each component is true if the component of the left-hand type is greater than the corresponding right-hand type component.
inline bool3x3 operator>( const uint3x3& lhs, const uint3x3& rhs );

/// \relates uint3x3
/// \brief Returns a bool3x3 where each component is true if the component of the left-hand type is greater than or equal to the corresponding right-hand type component.
inline bool3x3 operator>=( const uint3x3& lhs, const uint3x3& rhs );

/// \relates uint3x3
/// \brief Returns a copy of the uint3x3 where each component has been bitwise AND'd against the given scalar value.
inline uint3x3 operator&( const uint3x3& lhs, const uint32_t& rhs );

/// \relates uint3x3
/// \brief Performs a bitwise AND on the given left-hand uint3x3 against the given scalar value.
inline uint3x3 operator&=( uint3x3& lhs, const uint32_t& rhs );

/// \relates uint3x3
/// \brief Returns a copy of the uint3x3 where each component of the left-hand uint3x3 has been bitwise AND'd against the corresponding component of the right-hand side uint3x3.
inline uint3x3 operator&( const uint3x3& lhs, const uint3x3& rhs );

/// \relates uint3x3
/// \brief Performs a bitwise AND on the given left-hand uint3x3 against the corresponding component of the given right-hand uint3x3.
inline uint3x3 operator&=( uint3x3& lhs, const uint3x3& rhs );

/// \relates uint3x3
/// \brief Returns a copy of the uint3x3 where each component has been bitwise OR'd against the given scalar value.
inline uint3x3 operator|( const uint3x3& lhs, const uint32_t& rhs );

/// \relates uint3x3
/// \brief Performs a bitwise OR on the given left-hand uint3x3 against the given scalar value.
inline uint3x3 operator|=( uint3x3& lhs, const uint32_t& rhs );

/// \relates uint3x3
/// \brief Returns a copy of the uint3x3 where each component of the left-hand uint3x3 has been bitwise OR'd against the corresponding component of the right-hand side uint3x3.
inline uint3x3 operator|( const uint3x3& lhs, const uint3x3& rhs );

/// \relates uint3x3
/// \brief Performs a bitwise OR on the given left-hand uint3x3 against the corresponding component of the given right-hand uint3x3.
inline uint3x3 operator|=( uint3x3& lhs, const uint3x3& rhs );

/// \relates uint3x3
/// \brief Returns a copy of the uint3x3 where each component has been bitwise XOR'd against the given scalar value.
inline uint3x3 operator^( const uint3x3& lhs, const uint32_t& rhs );

/// \relates uint3x3
/// \brief Performs a bitwise XOR on the given left-hand uint3x3 against the given scalar value.
inline uint3x3 operator^=( uint3x3& lhs, const uint32_t& rhs );

/// \relates uint3x3
/// \brief Returns a copy of the uint3x3 where each component of the left-hand uint3x3 has been bitwise XOR'd against the corresponding component of the right-hand side uint3x3.
inline uint3x3 operator^( const uint3x3& lhs, const uint3x3& rhs );

/// \relates uint3x3
/// \brief Performs a bitwise XOR on the given left-hand uint3x3 against the corresponding component of the given right-hand uint3x3.
inline uint3x3 operator^=( uint3x3& lhs, const uint3x3& rhs );

/// \relates uint3x3
/// \brief Returns a copy of the uint3x3 where each component has been bitwise left-shifted by the given scalar value.
inline uint3x3 operator<<( const uint3x3& lhs, const uint32_t& rhs );

/// \relates uint3x3
/// \brief Performs a left bitshift on the given left-hand uint3x3 by the given scalar value.
inline uint3x3 operator<<=( uint3x3& lhs, const uint32_t& rhs );

/// \relates uint3x3
/// \brief Returns a copy of the uint3x3 where each component of the left-hand uint3x3 has been bitwise left-shifted by the corresponding component of the right-hand side uint3x3.
inline uint3x3 operator<<( const uint3x3& lhs, const uint3x3& rhs );

/// \relates uint3x3
/// \brief Performs a left bitshift on the given left-hand uint3x3 by the corresponding component of the given right-hand uint3x3.
inline uint3x3 operator<<=( uint3x3& lhs, const uint3x3& rhs );

/// \relates uint3x3
/// \brief Returns a copy of the uint3x3 where each component has been bitwise right-shifted by the given scalar value.
inline uint3x3 operator>>( const uint3x3& lhs, const uint32_t& rhs );

/// \relates uint3x3
/// \brief Performs a right bitshift on the given left-hand uint3x3 by the given scalar value.
inline uint3x3 operator>>=( uint3x3& lhs, const uint32_t& rhs );

/// \relates uint3x3
/// \brief Returns a copy of the uint3x3 where each component of the left-hand uint3x3 has been bitwise right-shifted by the corresponding component of the right-hand side uint3x3.
inline uint3x3 operator>>( const uint3x3& lhs, const uint3x3& rhs );

/// \relates uint3x3
/// \brief Performs a right bitshift on the given left-hand uint3x3 by the corresponding component of the given right-hand uint3x3.
inline uint3x3 operator>>=( uint3x3& lhs, const uint3x3& rhs );

/// \relates uint3x3
/// \brief Performs a unary bitwise operation on all components of the given uint3x3.
inline uint3x3 operator~( const uint3x3& lhs );


// uint3x4
/// \relates uint3x4
/// \brief Returns a copy of the uint3x4 that has been component-wise added by the given scalar value.
inline uint3x4 operator+( const uint3x4& lhs, const uint32_t rhs );

/// \relates uint3x4
/// \brief Adds each component by the given scalar value.
inline uint3x4 operator+=( uint3x4& lhs, const uint32_t rhs );

/// \relates uint3x4
/// \brief Returns a copy of the uint3x4 that has been component-wise added by the corresponding component of the right-hand uint3x4.
inline uint3x4 operator+( const uint3x4& lhs, const uint3x4& rhs );

/// \relates uint3x4
/// \brief Adds each component of the uint3x4 by the corresponding component of the right-hand uint3x4.
inline uint3x4 operator+=( uint3x4& lhs, const uint3x4& rhs );

/// \relates uint3x4
/// \brief Returns a copy of the uint3x4 that has been component-wise subtracted by the given scalar value.
inline uint3x4 operator-( const uint3x4& lhs, const uint32_t rhs );

/// \relates uint3x4
/// \brief Subtracts each component by the given scalar value.
inline uint3x4 operator-=( uint3x4& lhs, const uint32_t rhs );

/// \relates uint3x4
/// \brief Returns a copy of the uint3x4 that has been component-wise subtracted by the corresponding component of the right-hand uint3x4.
inline uint3x4 operator-( const uint3x4& lhs, const uint3x4& rhs );

/// \relates uint3x4
/// \brief Subtracts each component of the uint3x4 by the corresponding component of the right-hand uint3x4.
inline uint3x4 operator-=( uint3x4& lhs, const uint3x4& rhs );

/// \relates uint3x4
/// \brief Returns a copy of the uint3x4 that has been component-wise multiplied by the given scalar value.
inline uint3x4 operator*( const uint3x4& lhs, const uint32_t rhs );

/// \relates uint3x4
/// \brief Multiplies each component by the given scalar value.
inline uint3x4 operator*=( uint3x4& lhs, const uint32_t rhs );

/// \relates uint3x4
/// \brief Returns a copy of the matrix where each row of the left-hand matrix has been dot-producted by the corresponding column of the right-hand matrix.
inline uint3x3 operator*( const uint3x4& lhs, const uint4x3& rhs );

/// \relates uint3x4
/// \brief Dot products each row of the left-hand matrix with the corresponding column of the right-hand matrix.
inline uint3x3 operator*=( uint3x4& lhs, const uint4x3& rhs );

/// \relates uint3x4
/// \brief Returns a copy of the uint3x4 that has been component-wise divided by the given scalar value.
inline uint3x4 operator/( const uint3x4& lhs, const uint32_t rhs );

/// \relates uint3x4
/// \brief Divides each component by the given scalar value.
inline uint3x4 operator/=( uint3x4& lhs, const uint32_t rhs );

/// \relates uint3x4
/// \brief Returns a copy of the uint3x4 that has been component-wise divided by the corresponding component of the right-hand uint3x4.
inline uint3x4 operator/( const uint3x4& lhs, const uint3x4& rhs );

/// \relates uint3x4
/// \brief Prefix increment operator.  Adds one to each component of the given uint3x4 before evaluation.
inline uint3x4& operator++( uint3x4& lhs );

/// \relates uint3x4
/// \brief Postfix increment operator.  Adds one to each component of the given uint3x4 after evaluation.
inline uint3x4& operator++( uint3x4& lhs, const int );

/// \relates uint3x4
/// \brief Prefix decrement operator.  Subtracts one from each component of the given uint3x4 before evaluation.
inline uint3x4& operator--( uint3x4& lhs );

/// \relates uint3x4
/// \brief Postfix decrement operator.  Subtracts one from each component of the given uint3x4 after evaluation.
inline uint3x4& operator--( uint3x4& lhs, const int );

/// \relates uint3x4
/// \brief Returns a bool3x4 where each component is true if the component of the left-hand type is less than the corresponding right-hand type component.
inline bool3x4 operator<( const uint3x4& lhs, const uint3x4& rhs );

/// \relates uint3x4
/// \brief Returns a bool3x4 where each component is true if the component of the left-hand type is less than or equal to the corresponding right-hand type component.
inline bool3x4 operator<=( const uint3x4& lhs, const uint3x4& rhs );

/// \relates uint3x4
/// \brief Returns a bool3x4 where each component is true if the component of the left-hand type is greater than the corresponding right-hand type component.
inline bool3x4 operator>( const uint3x4& lhs, const uint3x4& rhs );

/// \relates uint3x4
/// \brief Returns a bool3x4 where each component is true if the component of the left-hand type is greater than or equal to the corresponding right-hand type component.
inline bool3x4 operator>=( const uint3x4& lhs, const uint3x4& rhs );

/// \relates uint3x4
/// \brief Returns a copy of the uint3x4 where each component has been bitwise AND'd against the given scalar value.
inline uint3x4 operator&( const uint3x4& lhs, const uint32_t& rhs );

/// \relates uint3x4
/// \brief Performs a bitwise AND on the given left-hand uint3x4 against the given scalar value.
inline uint3x4 operator&=( uint3x4& lhs, const uint32_t& rhs );

/// \relates uint3x4
/// \brief Returns a copy of the uint3x4 where each component of the left-hand uint3x4 has been bitwise AND'd against the corresponding component of the right-hand side uint3x4.
inline uint3x4 operator&( const uint3x4& lhs, const uint3x4& rhs );

/// \relates uint3x4
/// \brief Performs a bitwise AND on the given left-hand uint3x4 against the corresponding component of the given right-hand uint3x4.
inline uint3x4 operator&=( uint3x4& lhs, const uint3x4& rhs );

/// \relates uint3x4
/// \brief Returns a copy of the uint3x4 where each component has been bitwise OR'd against the given scalar value.
inline uint3x4 operator|( const uint3x4& lhs, const uint32_t& rhs );

/// \relates uint3x4
/// \brief Performs a bitwise OR on the given left-hand uint3x4 against the given scalar value.
inline uint3x4 operator|=( uint3x4& lhs, const uint32_t& rhs );

/// \relates uint3x4
/// \brief Returns a copy of the uint3x4 where each component of the left-hand uint3x4 has been bitwise OR'd against the corresponding component of the right-hand side uint3x4.
inline uint3x4 operator|( const uint3x4& lhs, const uint3x4& rhs );

/// \relates uint3x4
/// \brief Performs a bitwise OR on the given left-hand uint3x4 against the corresponding component of the given right-hand uint3x4.
inline uint3x4 operator|=( uint3x4& lhs, const uint3x4& rhs );

/// \relates uint3x4
/// \brief Returns a copy of the uint3x4 where each component has been bitwise XOR'd against the given scalar value.
inline uint3x4 operator^( const uint3x4& lhs, const uint32_t& rhs );

/// \relates uint3x4
/// \brief Performs a bitwise XOR on the given left-hand uint3x4 against the given scalar value.
inline uint3x4 operator^=( uint3x4& lhs, const uint32_t& rhs );

/// \relates uint3x4
/// \brief Returns a copy of the uint3x4 where each component of the left-hand uint3x4 has been bitwise XOR'd against the corresponding component of the right-hand side uint3x4.
inline uint3x4 operator^( const uint3x4& lhs, const uint3x4& rhs );

/// \relates uint3x4
/// \brief Performs a bitwise XOR on the given left-hand uint3x4 against the corresponding component of the given right-hand uint3x4.
inline uint3x4 operator^=( uint3x4& lhs, const uint3x4& rhs );

/// \relates uint3x4
/// \brief Returns a copy of the uint3x4 where each component has been bitwise left-shifted by the given scalar value.
inline uint3x4 operator<<( const uint3x4& lhs, const uint32_t& rhs );

/// \relates uint3x4
/// \brief Performs a left bitshift on the given left-hand uint3x4 by the given scalar value.
inline uint3x4 operator<<=( uint3x4& lhs, const uint32_t& rhs );

/// \relates uint3x4
/// \brief Returns a copy of the uint3x4 where each component of the left-hand uint3x4 has been bitwise left-shifted by the corresponding component of the right-hand side uint3x4.
inline uint3x4 operator<<( const uint3x4& lhs, const uint3x4& rhs );

/// \relates uint3x4
/// \brief Performs a left bitshift on the given left-hand uint3x4 by the corresponding component of the given right-hand uint3x4.
inline uint3x4 operator<<=( uint3x4& lhs, const uint3x4& rhs );

/// \relates uint3x4
/// \brief Returns a copy of the uint3x4 where each component has been bitwise right-shifted by the given scalar value.
inline uint3x4 operator>>( const uint3x4& lhs, const uint32_t& rhs );

/// \relates uint3x4
/// \brief Performs a right bitshift on the given left-hand uint3x4 by the given scalar value.
inline uint3x4 operator>>=( uint3x4& lhs, const uint32_t& rhs );

/// \relates uint3x4
/// \brief Returns a copy of the uint3x4 where each component of the left-hand uint3x4 has been bitwise right-shifted by the corresponding component of the right-hand side uint3x4.
inline uint3x4 operator>>( const uint3x4& lhs, const uint3x4& rhs );

/// \relates uint3x4
/// \brief Performs a right bitshift on the given left-hand uint3x4 by the corresponding component of the given right-hand uint3x4.
inline uint3x4 operator>>=( uint3x4& lhs, const uint3x4& rhs );

/// \relates uint3x4
/// \brief Performs a unary bitwise operation on all components of the given uint3x4.
inline uint3x4 operator~( const uint3x4& lhs );


// uint4x2
/// \relates uint4x2
/// \brief Returns a copy of the uint4x2 that has been component-wise added by the given scalar value.
inline uint4x2 operator+( const uint4x2& lhs, const uint32_t rhs );

/// \relates uint4x2
/// \brief Adds each component by the given scalar value.
inline uint4x2 operator+=( uint4x2& lhs, const uint32_t rhs );

/// \relates uint4x2
/// \brief Returns a copy of the uint4x2 that has been component-wise added by the corresponding component of the right-hand uint4x2.
inline uint4x2 operator+( const uint4x2& lhs, const uint4x2& rhs );

/// \relates uint4x2
/// \brief Adds each component of the uint4x2 by the corresponding component of the right-hand uint4x2.
inline uint4x2 operator+=( uint4x2& lhs, const uint4x2& rhs );

/// \relates uint4x2
/// \brief Returns a copy of the uint4x2 that has been component-wise subtracted by the given scalar value.
inline uint4x2 operator-( const uint4x2& lhs, const uint32_t rhs );

/// \relates uint4x2
/// \brief Subtracts each component by the given scalar value.
inline uint4x2 operator-=( uint4x2& lhs, const uint32_t rhs );

/// \relates uint4x2
/// \brief Returns a copy of the uint4x2 that has been component-wise subtracted by the corresponding component of the right-hand uint4x2.
inline uint4x2 operator-( const uint4x2& lhs, const uint4x2& rhs );

/// \relates uint4x2
/// \brief Subtracts each component of the uint4x2 by the corresponding component of the right-hand uint4x2.
inline uint4x2 operator-=( uint4x2& lhs, const uint4x2& rhs );

/// \relates uint4x2
/// \brief Returns a copy of the uint4x2 that has been component-wise multiplied by the given scalar value.
inline uint4x2 operator*( const uint4x2& lhs, const uint32_t rhs );

/// \relates uint4x2
/// \brief Multiplies each component by the given scalar value.
inline uint4x2 operator*=( uint4x2& lhs, const uint32_t rhs );

/// \relates uint4x2
/// \brief Returns a copy of the matrix where each row of the left-hand matrix has been dot-producted by the corresponding column of the right-hand matrix.
inline uint4x4 operator*( const uint4x2& lhs, const uint2x4& rhs );

/// \relates uint4x2
/// \brief Dot products each row of the left-hand matrix with the corresponding column of the right-hand matrix.
inline uint4x4 operator*=( uint4x2& lhs, const uint2x4& rhs );

/// \relates uint4x2
/// \brief Returns a copy of the uint4x2 that has been component-wise divided by the given scalar value.
inline uint4x2 operator/( const uint4x2& lhs, const uint32_t rhs );

/// \relates uint4x2
/// \brief Divides each component by the given scalar value.
inline uint4x2 operator/=( uint4x2& lhs, const uint32_t rhs );

/// \relates uint4x2
/// \brief Returns a copy of the uint4x2 that has been component-wise divided by the corresponding component of the right-hand uint4x2.
inline uint4x2 operator/( const uint4x2& lhs, const uint4x2& rhs );

/// \relates uint4x2
/// \brief Prefix increment operator.  Adds one to each component of the given uint4x2 before evaluation.
inline uint4x2& operator++( uint4x2& lhs );

/// \relates uint4x2
/// \brief Postfix increment operator.  Adds one to each component of the given uint4x2 after evaluation.
inline uint4x2& operator++( uint4x2& lhs, const int );

/// \relates uint4x2
/// \brief Prefix decrement operator.  Subtracts one from each component of the given uint4x2 before evaluation.
inline uint4x2& operator--( uint4x2& lhs );

/// \relates uint4x2
/// \brief Postfix decrement operator.  Subtracts one from each component of the given uint4x2 after evaluation.
inline uint4x2& operator--( uint4x2& lhs, const int );

/// \relates uint4x2
/// \brief Returns a bool4x2 where each component is true if the component of the left-hand type is less than the corresponding right-hand type component.
inline bool4x2 operator<( const uint4x2& lhs, const uint4x2& rhs );

/// \relates uint4x2
/// \brief Returns a bool4x2 where each component is true if the component of the left-hand type is less than or equal to the corresponding right-hand type component.
inline bool4x2 operator<=( const uint4x2& lhs, const uint4x2& rhs );

/// \relates uint4x2
/// \brief Returns a bool4x2 where each component is true if the component of the left-hand type is greater than the corresponding right-hand type component.
inline bool4x2 operator>( const uint4x2& lhs, const uint4x2& rhs );

/// \relates uint4x2
/// \brief Returns a bool4x2 where each component is true if the component of the left-hand type is greater than or equal to the corresponding right-hand type component.
inline bool4x2 operator>=( const uint4x2& lhs, const uint4x2& rhs );

/// \relates uint4x2
/// \brief Returns a copy of the uint4x2 where each component has been bitwise AND'd against the given scalar value.
inline uint4x2 operator&( const uint4x2& lhs, const uint32_t& rhs );

/// \relates uint4x2
/// \brief Performs a bitwise AND on the given left-hand uint4x2 against the given scalar value.
inline uint4x2 operator&=( uint4x2& lhs, const uint32_t& rhs );

/// \relates uint4x2
/// \brief Returns a copy of the uint4x2 where each component of the left-hand uint4x2 has been bitwise AND'd against the corresponding component of the right-hand side uint4x2.
inline uint4x2 operator&( const uint4x2& lhs, const uint4x2& rhs );

/// \relates uint4x2
/// \brief Performs a bitwise AND on the given left-hand uint4x2 against the corresponding component of the given right-hand uint4x2.
inline uint4x2 operator&=( uint4x2& lhs, const uint4x2& rhs );

/// \relates uint4x2
/// \brief Returns a copy of the uint4x2 where each component has been bitwise OR'd against the given scalar value.
inline uint4x2 operator|( const uint4x2& lhs, const uint32_t& rhs );

/// \relates uint4x2
/// \brief Performs a bitwise OR on the given left-hand uint4x2 against the given scalar value.
inline uint4x2 operator|=( uint4x2& lhs, const uint32_t& rhs );

/// \relates uint4x2
/// \brief Returns a copy of the uint4x2 where each component of the left-hand uint4x2 has been bitwise OR'd against the corresponding component of the right-hand side uint4x2.
inline uint4x2 operator|( const uint4x2& lhs, const uint4x2& rhs );

/// \relates uint4x2
/// \brief Performs a bitwise OR on the given left-hand uint4x2 against the corresponding component of the given right-hand uint4x2.
inline uint4x2 operator|=( uint4x2& lhs, const uint4x2& rhs );

/// \relates uint4x2
/// \brief Returns a copy of the uint4x2 where each component has been bitwise XOR'd against the given scalar value.
inline uint4x2 operator^( const uint4x2& lhs, const uint32_t& rhs );

/// \relates uint4x2
/// \brief Performs a bitwise XOR on the given left-hand uint4x2 against the given scalar value.
inline uint4x2 operator^=( uint4x2& lhs, const uint32_t& rhs );

/// \relates uint4x2
/// \brief Returns a copy of the uint4x2 where each component of the left-hand uint4x2 has been bitwise XOR'd against the corresponding component of the right-hand side uint4x2.
inline uint4x2 operator^( const uint4x2& lhs, const uint4x2& rhs );

/// \relates uint4x2
/// \brief Performs a bitwise XOR on the given left-hand uint4x2 against the corresponding component of the given right-hand uint4x2.
inline uint4x2 operator^=( uint4x2& lhs, const uint4x2& rhs );

/// \relates uint4x2
/// \brief Returns a copy of the uint4x2 where each component has been bitwise left-shifted by the given scalar value.
inline uint4x2 operator<<( const uint4x2& lhs, const uint32_t& rhs );

/// \relates uint4x2
/// \brief Performs a left bitshift on the given left-hand uint4x2 by the given scalar value.
inline uint4x2 operator<<=( uint4x2& lhs, const uint32_t& rhs );

/// \relates uint4x2
/// \brief Returns a copy of the uint4x2 where each component of the left-hand uint4x2 has been bitwise left-shifted by the corresponding component of the right-hand side uint4x2.
inline uint4x2 operator<<( const uint4x2& lhs, const uint4x2& rhs );

/// \relates uint4x2
/// \brief Performs a left bitshift on the given left-hand uint4x2 by the corresponding component of the given right-hand uint4x2.
inline uint4x2 operator<<=( uint4x2& lhs, const uint4x2& rhs );

/// \relates uint4x2
/// \brief Returns a copy of the uint4x2 where each component has been bitwise right-shifted by the given scalar value.
inline uint4x2 operator>>( const uint4x2& lhs, const uint32_t& rhs );

/// \relates uint4x2
/// \brief Performs a right bitshift on the given left-hand uint4x2 by the given scalar value.
inline uint4x2 operator>>=( uint4x2& lhs, const uint32_t& rhs );

/// \relates uint4x2
/// \brief Returns a copy of the uint4x2 where each component of the left-hand uint4x2 has been bitwise right-shifted by the corresponding component of the right-hand side uint4x2.
inline uint4x2 operator>>( const uint4x2& lhs, const uint4x2& rhs );

/// \relates uint4x2
/// \brief Performs a right bitshift on the given left-hand uint4x2 by the corresponding component of the given right-hand uint4x2.
inline uint4x2 operator>>=( uint4x2& lhs, const uint4x2& rhs );

/// \relates uint4x2
/// \brief Performs a unary bitwise operation on all components of the given uint4x2.
inline uint4x2 operator~( const uint4x2& lhs );


// uint4x3
/// \relates uint4x3
/// \brief Returns a copy of the uint4x3 that has been component-wise added by the given scalar value.
inline uint4x3 operator+( const uint4x3& lhs, const uint32_t rhs );

/// \relates uint4x3
/// \brief Adds each component by the given scalar value.
inline uint4x3 operator+=( uint4x3& lhs, const uint32_t rhs );

/// \relates uint4x3
/// \brief Returns a copy of the uint4x3 that has been component-wise added by the corresponding component of the right-hand uint4x3.
inline uint4x3 operator+( const uint4x3& lhs, const uint4x3& rhs );

/// \relates uint4x3
/// \brief Adds each component of the uint4x3 by the corresponding component of the right-hand uint4x3.
inline uint4x3 operator+=( uint4x3& lhs, const uint4x3& rhs );

/// \relates uint4x3
/// \brief Returns a copy of the uint4x3 that has been component-wise subtracted by the given scalar value.
inline uint4x3 operator-( const uint4x3& lhs, const uint32_t rhs );

/// \relates uint4x3
/// \brief Subtracts each component by the given scalar value.
inline uint4x3 operator-=( uint4x3& lhs, const uint32_t rhs );

/// \relates uint4x3
/// \brief Returns a copy of the uint4x3 that has been component-wise subtracted by the corresponding component of the right-hand uint4x3.
inline uint4x3 operator-( const uint4x3& lhs, const uint4x3& rhs );

/// \relates uint4x3
/// \brief Subtracts each component of the uint4x3 by the corresponding component of the right-hand uint4x3.
inline uint4x3 operator-=( uint4x3& lhs, const uint4x3& rhs );

/// \relates uint4x3
/// \brief Returns a copy of the uint4x3 that has been component-wise multiplied by the given scalar value.
inline uint4x3 operator*( const uint4x3& lhs, const uint32_t rhs );

/// \relates uint4x3
/// \brief Multiplies each component by the given scalar value.
inline uint4x3 operator*=( uint4x3& lhs, const uint32_t rhs );

/// \relates uint4x3
/// \brief Returns a copy of the matrix where each row of the left-hand matrix has been dot-producted by the corresponding column of the right-hand matrix.
inline uint4x4 operator*( const uint4x3& lhs, const uint3x4& rhs );

/// \relates uint4x3
/// \brief Dot products each row of the left-hand matrix with the corresponding column of the right-hand matrix.
inline uint4x4 operator*=( uint4x3& lhs, const uint3x4& rhs );

/// \relates uint4x3
/// \brief Returns a copy of the uint4x3 that has been component-wise divided by the given scalar value.
inline uint4x3 operator/( const uint4x3& lhs, const uint32_t rhs );

/// \relates uint4x3
/// \brief Divides each component by the given scalar value.
inline uint4x3 operator/=( uint4x3& lhs, const uint32_t rhs );

/// \relates uint4x3
/// \brief Returns a copy of the uint4x3 that has been component-wise divided by the corresponding component of the right-hand uint4x3.
inline uint4x3 operator/( const uint4x3& lhs, const uint4x3& rhs );

/// \relates uint4x3
/// \brief Prefix increment operator.  Adds one to each component of the given uint4x3 before evaluation.
inline uint4x3& operator++( uint4x3& lhs );

/// \relates uint4x3
/// \brief Postfix increment operator.  Adds one to each component of the given uint4x3 after evaluation.
inline uint4x3& operator++( uint4x3& lhs, const int );

/// \relates uint4x3
/// \brief Prefix decrement operator.  Subtracts one from each component of the given uint4x3 before evaluation.
inline uint4x3& operator--( uint4x3& lhs );

/// \relates uint4x3
/// \brief Postfix decrement operator.  Subtracts one from each component of the given uint4x3 after evaluation.
inline uint4x3& operator--( uint4x3& lhs, const int );

/// \relates uint4x3
/// \brief Returns a bool4x3 where each component is true if the component of the left-hand type is less than the corresponding right-hand type component.
inline bool4x3 operator<( const uint4x3& lhs, const uint4x3& rhs );

/// \relates uint4x3
/// \brief Returns a bool4x3 where each component is true if the component of the left-hand type is less than or equal to the corresponding right-hand type component.
inline bool4x3 operator<=( const uint4x3& lhs, const uint4x3& rhs );

/// \relates uint4x3
/// \brief Returns a bool4x3 where each component is true if the component of the left-hand type is greater than the corresponding right-hand type component.
inline bool4x3 operator>( const uint4x3& lhs, const uint4x3& rhs );

/// \relates uint4x3
/// \brief Returns a bool4x3 where each component is true if the component of the left-hand type is greater than or equal to the corresponding right-hand type component.
inline bool4x3 operator>=( const uint4x3& lhs, const uint4x3& rhs );

/// \relates uint4x3
/// \brief Returns a copy of the uint4x3 where each component has been bitwise AND'd against the given scalar value.
inline uint4x3 operator&( const uint4x3& lhs, const uint32_t& rhs );

/// \relates uint4x3
/// \brief Performs a bitwise AND on the given left-hand uint4x3 against the given scalar value.
inline uint4x3 operator&=( uint4x3& lhs, const uint32_t& rhs );

/// \relates uint4x3
/// \brief Returns a copy of the uint4x3 where each component of the left-hand uint4x3 has been bitwise AND'd against the corresponding component of the right-hand side uint4x3.
inline uint4x3 operator&( const uint4x3& lhs, const uint4x3& rhs );

/// \relates uint4x3
/// \brief Performs a bitwise AND on the given left-hand uint4x3 against the corresponding component of the given right-hand uint4x3.
inline uint4x3 operator&=( uint4x3& lhs, const uint4x3& rhs );

/// \relates uint4x3
/// \brief Returns a copy of the uint4x3 where each component has been bitwise OR'd against the given scalar value.
inline uint4x3 operator|( const uint4x3& lhs, const uint32_t& rhs );

/// \relates uint4x3
/// \brief Performs a bitwise OR on the given left-hand uint4x3 against the given scalar value.
inline uint4x3 operator|=( uint4x3& lhs, const uint32_t& rhs );

/// \relates uint4x3
/// \brief Returns a copy of the uint4x3 where each component of the left-hand uint4x3 has been bitwise OR'd against the corresponding component of the right-hand side uint4x3.
inline uint4x3 operator|( const uint4x3& lhs, const uint4x3& rhs );

/// \relates uint4x3
/// \brief Performs a bitwise OR on the given left-hand uint4x3 against the corresponding component of the given right-hand uint4x3.
inline uint4x3 operator|=( uint4x3& lhs, const uint4x3& rhs );

/// \relates uint4x3
/// \brief Returns a copy of the uint4x3 where each component has been bitwise XOR'd against the given scalar value.
inline uint4x3 operator^( const uint4x3& lhs, const uint32_t& rhs );

/// \relates uint4x3
/// \brief Performs a bitwise XOR on the given left-hand uint4x3 against the given scalar value.
inline uint4x3 operator^=( uint4x3& lhs, const uint32_t& rhs );

/// \relates uint4x3
/// \brief Returns a copy of the uint4x3 where each component of the left-hand uint4x3 has been bitwise XOR'd against the corresponding component of the right-hand side uint4x3.
inline uint4x3 operator^( const uint4x3& lhs, const uint4x3& rhs );

/// \relates uint4x3
/// \brief Performs a bitwise XOR on the given left-hand uint4x3 against the corresponding component of the given right-hand uint4x3.
inline uint4x3 operator^=( uint4x3& lhs, const uint4x3& rhs );

/// \relates uint4x3
/// \brief Returns a copy of the uint4x3 where each component has been bitwise left-shifted by the given scalar value.
inline uint4x3 operator<<( const uint4x3& lhs, const uint32_t& rhs );

/// \relates uint4x3
/// \brief Performs a left bitshift on the given left-hand uint4x3 by the given scalar value.
inline uint4x3 operator<<=( uint4x3& lhs, const uint32_t& rhs );

/// \relates uint4x3
/// \brief Returns a copy of the uint4x3 where each component of the left-hand uint4x3 has been bitwise left-shifted by the corresponding component of the right-hand side uint4x3.
inline uint4x3 operator<<( const uint4x3& lhs, const uint4x3& rhs );

/// \relates uint4x3
/// \brief Performs a left bitshift on the given left-hand uint4x3 by the corresponding component of the given right-hand uint4x3.
inline uint4x3 operator<<=( uint4x3& lhs, const uint4x3& rhs );

/// \relates uint4x3
/// \brief Returns a copy of the uint4x3 where each component has been bitwise right-shifted by the given scalar value.
inline uint4x3 operator>>( const uint4x3& lhs, const uint32_t& rhs );

/// \relates uint4x3
/// \brief Performs a right bitshift on the given left-hand uint4x3 by the given scalar value.
inline uint4x3 operator>>=( uint4x3& lhs, const uint32_t& rhs );

/// \relates uint4x3
/// \brief Returns a copy of the uint4x3 where each component of the left-hand uint4x3 has been bitwise right-shifted by the corresponding component of the right-hand side uint4x3.
inline uint4x3 operator>>( const uint4x3& lhs, const uint4x3& rhs );

/// \relates uint4x3
/// \brief Performs a right bitshift on the given left-hand uint4x3 by the corresponding component of the given right-hand uint4x3.
inline uint4x3 operator>>=( uint4x3& lhs, const uint4x3& rhs );

/// \relates uint4x3
/// \brief Performs a unary bitwise operation on all components of the given uint4x3.
inline uint4x3 operator~( const uint4x3& lhs );


// uint4x4
/// \relates uint4x4
/// \brief Returns a copy of the uint4x4 that has been component-wise added by the given scalar value.
inline uint4x4 operator+( const uint4x4& lhs, const uint32_t rhs );

/// \relates uint4x4
/// \brief Adds each component by the given scalar value.
inline uint4x4 operator+=( uint4x4& lhs, const uint32_t rhs );

/// \relates uint4x4
/// \brief Returns a copy of the uint4x4 that has been component-wise added by the corresponding component of the right-hand uint4x4.
inline uint4x4 operator+( const uint4x4& lhs, const uint4x4& rhs );

/// \relates uint4x4
/// \brief Adds each component of the uint4x4 by the corresponding component of the right-hand uint4x4.
inline uint4x4 operator+=( uint4x4& lhs, const uint4x4& rhs );

/// \relates uint4x4
/// \brief Returns a copy of the uint4x4 that has been component-wise subtracted by the given scalar value.
inline uint4x4 operator-( const uint4x4& lhs, const uint32_t rhs );

/// \relates uint4x4
/// \brief Subtracts each component by the given scalar value.
inline uint4x4 operator-=( uint4x4& lhs, const uint32_t rhs );

/// \relates uint4x4
/// \brief Returns a copy of the uint4x4 that has been component-wise subtracted by the corresponding component of the right-hand uint4x4.
inline uint4x4 operator-( const uint4x4& lhs, const uint4x4& rhs );

/// \relates uint4x4
/// \brief Subtracts each component of the uint4x4 by the corresponding component of the right-hand uint4x4.
inline uint4x4 operator-=( uint4x4& lhs, const uint4x4& rhs );

/// \relates uint4x4
/// \brief Returns a copy of the uint4x4 that has been component-wise multiplied by the given scalar value.
inline uint4x4 operator*( const uint4x4& lhs, const uint32_t rhs );

/// \relates uint4x4
/// \brief Multiplies each component by the given scalar value.
inline uint4x4 operator*=( uint4x4& lhs, const uint32_t rhs );

/// \relates uint4x4
/// \brief Returns a copy of the matrix where each row of the left-hand matrix has been dot-producted by the corresponding column of the right-hand matrix.
inline uint4x4 operator*( const uint4x4& lhs, const uint4x4& rhs );

/// \relates uint4x4
/// \brief Dot products each row of the left-hand matrix with the corresponding column of the right-hand matrix.
inline uint4x4 operator*=( uint4x4& lhs, const uint4x4& rhs );

/// \relates uint4x4
/// \brief Returns a copy of the uint4x4 that has been component-wise divided by the given scalar value.
inline uint4x4 operator/( const uint4x4& lhs, const uint32_t rhs );

/// \relates uint4x4
/// \brief Divides each component by the given scalar value.
inline uint4x4 operator/=( uint4x4& lhs, const uint32_t rhs );

/// \relates uint4x4
/// \brief Returns a copy of the uint4x4 that has been component-wise divided by the corresponding component of the right-hand uint4x4.
inline uint4x4 operator/( const uint4x4& lhs, const uint4x4& rhs );

/// \relates uint4x4
/// \brief Divides each component of the uint4x4 by the corresponding component of the right-hand uint4x4.
inline uint4x4 operator/=( uint4x4& lhs, const uint4x4& rhs );

/// \relates uint4x4
/// \brief Prefix increment operator.  Adds one to each component of the given uint4x4 before evaluation.
inline uint4x4& operator++( uint4x4& lhs );

/// \relates uint4x4
/// \brief Postfix increment operator.  Adds one to each component of the given uint4x4 after evaluation.
inline uint4x4& operator++( uint4x4& lhs, const int );

/// \relates uint4x4
/// \brief Prefix decrement operator.  Subtracts one from each component of the given uint4x4 before evaluation.
inline uint4x4& operator--( uint4x4& lhs );

/// \relates uint4x4
/// \brief Postfix decrement operator.  Subtracts one from each component of the given uint4x4 after evaluation.
inline uint4x4& operator--( uint4x4& lhs, const int );

/// \relates uint4x4
/// \brief Returns a bool4x4 where each component is true if the component of the left-hand type is less than the corresponding right-hand type component.
inline bool4x4 operator<( const uint4x4& lhs, const uint4x4& rhs );

/// \relates uint4x4
/// \brief Returns a bool4x4 where each component is true if the component of the left-hand type is less than or equal to the corresponding right-hand type component.
inline bool4x4 operator<=( const uint4x4& lhs, const uint4x4& rhs );

/// \relates uint4x4
/// \brief Returns a bool4x4 where each component is true if the component of the left-hand type is greater than the corresponding right-hand type component.
inline bool4x4 operator>( const uint4x4& lhs, const uint4x4& rhs );

/// \relates uint4x4
/// \brief Returns a bool4x4 where each component is true if the component of the left-hand type is greater than or equal to the corresponding right-hand type component.
inline bool4x4 operator>=( const uint4x4& lhs, const uint4x4& rhs );

/// \relates uint4x4
/// \brief Returns a copy of the uint4x4 where each component has been bitwise AND'd against the given scalar value.
inline uint4x4 operator&( const uint4x4& lhs, const uint32_t& rhs );

/// \relates uint4x4
/// \brief Performs a bitwise AND on the given left-hand uint4x4 against the given scalar value.
inline uint4x4 operator&=( uint4x4& lhs, const uint32_t& rhs );

/// \relates uint4x4
/// \brief Returns a copy of the uint4x4 where each component of the left-hand uint4x4 has been bitwise AND'd against the corresponding component of the right-hand side uint4x4.
inline uint4x4 operator&( const uint4x4& lhs, const uint4x4& rhs );

/// \relates uint4x4
/// \brief Performs a bitwise AND on the given left-hand uint4x4 against the corresponding component of the given right-hand uint4x4.
inline uint4x4 operator&=( uint4x4& lhs, const uint4x4& rhs );

/// \relates uint4x4
/// \brief Returns a copy of the uint4x4 where each component has been bitwise OR'd against the given scalar value.
inline uint4x4 operator|( const uint4x4& lhs, const uint32_t& rhs );

/// \relates uint4x4
/// \brief Performs a bitwise OR on the given left-hand uint4x4 against the given scalar value.
inline uint4x4 operator|=( uint4x4& lhs, const uint32_t& rhs );

/// \relates uint4x4
/// \brief Returns a copy of the uint4x4 where each component of the left-hand uint4x4 has been bitwise OR'd against the corresponding component of the right-hand side uint4x4.
inline uint4x4 operator|( const uint4x4& lhs, const uint4x4& rhs );

/// \relates uint4x4
/// \brief Performs a bitwise OR on the given left-hand uint4x4 against the corresponding component of the given right-hand uint4x4.
inline uint4x4 operator|=( uint4x4& lhs, const uint4x4& rhs );

/// \relates uint4x4
/// \brief Returns a copy of the uint4x4 where each component has been bitwise XOR'd against the given scalar value.
inline uint4x4 operator^( const uint4x4& lhs, const uint32_t& rhs );

/// \relates uint4x4
/// \brief Performs a bitwise XOR on the given left-hand uint4x4 against the given scalar value.
inline uint4x4 operator^=( uint4x4& lhs, const uint32_t& rhs );

/// \relates uint4x4
/// \brief Returns a copy of the uint4x4 where each component of the left-hand uint4x4 has been bitwise XOR'd against the corresponding component of the right-hand side uint4x4.
inline uint4x4 operator^( const uint4x4& lhs, const uint4x4& rhs );

/// \relates uint4x4
/// \brief Performs a bitwise XOR on the given left-hand uint4x4 against the corresponding component of the given right-hand uint4x4.
inline uint4x4 operator^=( uint4x4& lhs, const uint4x4& rhs );

/// \relates uint4x4
/// \brief Returns a copy of the uint4x4 where each component has been bitwise left-shifted by the given scalar value.
inline uint4x4 operator<<( const uint4x4& lhs, const uint32_t& rhs );

/// \relates uint4x4
/// \brief Performs a left bitshift on the given left-hand uint4x4 by the given scalar value.
inline uint4x4 operator<<=( uint4x4& lhs, const uint32_t& rhs );

/// \relates uint4x4
/// \brief Returns a copy of the uint4x4 where each component of the left-hand uint4x4 has been bitwise left-shifted by the corresponding component of the right-hand side uint4x4.
inline uint4x4 operator<<( const uint4x4& lhs, const uint4x4& rhs );

/// \relates uint4x4
/// \brief Performs a left bitshift on the given left-hand uint4x4 by the corresponding component of the given right-hand uint4x4.
inline uint4x4 operator<<=( uint4x4& lhs, const uint4x4& rhs );

/// \relates uint4x4
/// \brief Returns a copy of the uint4x4 where each component has been bitwise right-shifted by the given scalar value.
inline uint4x4 operator>>( const uint4x4& lhs, const uint32_t& rhs );

/// \relates uint4x4
/// \brief Performs a right bitshift on the given left-hand uint4x4 by the given scalar value.
inline uint4x4 operator>>=( uint4x4& lhs, const uint32_t& rhs );

/// \relates uint4x4
/// \brief Returns a copy of the uint4x4 where each component of the left-hand uint4x4 has been bitwise right-shifted by the corresponding component of the right-hand side uint4x4.
inline uint4x4 operator>>( const uint4x4& lhs, const uint4x4& rhs );

/// \relates uint4x4
/// \brief Performs a right bitshift on the given left-hand uint4x4 by the corresponding component of the given right-hand uint4x4.
inline uint4x4 operator>>=( uint4x4& lhs, const uint4x4& rhs );

/// \relates uint4x4
/// \brief Performs a unary bitwise operation on all components of the given uint4x4.
inline uint4x4 operator~( const uint4x4& lhs );


// float2x2
/// \relates float2x2
/// \brief Returns a copy of the float2x2 that has been component-wise added by the given scalar value.
inline float2x2 operator+( const float2x2& lhs, const float rhs );

/// \relates float2x2
/// \brief Adds each component by the given scalar value.
inline float2x2 operator+=( float2x2& lhs, const float rhs );

/// \relates float2x2
/// \brief Returns a copy of the float2x2 that has been component-wise added by the corresponding component of the right-hand float2x2.
inline float2x2 operator+( const float2x2& lhs, const float2x2& rhs );

/// \relates float2x2
/// \brief Adds each component of the float2x2 by the corresponding component of the right-hand float2x2.
inline float2x2 operator+=( float2x2& lhs, const float2x2& rhs );

/// \relates float2x2
/// \brief Returns a copy of the float2x2 that has been component-wise subtracted by the given scalar value.
inline float2x2 operator-( const float2x2& lhs, const float rhs );

/// \relates float2x2
/// \brief Subtracts each component by the given scalar value.
inline float2x2 operator-=( float2x2& lhs, const float rhs );

/// \relates float2x2
/// \brief Returns a copy of the float2x2 that has been component-wise subtracted by the corresponding component of the right-hand float2x2.
inline float2x2 operator-( const float2x2& lhs, const float2x2& rhs );

/// \relates float2x2
/// \brief Subtracts each component of the float2x2 by the corresponding component of the right-hand float2x2.
inline float2x2 operator-=( float2x2& lhs, const float2x2& rhs );

/// \relates float2x2
/// \brief Returns a copy of the float2x2 that has been component-wise multiplied by the given scalar value.
inline float2x2 operator*( const float2x2& lhs, const float rhs );

/// \relates float2x2
/// \brief Multiplies each component by the given scalar value.
inline float2x2 operator*=( float2x2& lhs, const float rhs );

/// \relates float2x2
/// \brief Returns a copy of the matrix where each row of the left-hand matrix has been dot-producted by the corresponding column of the right-hand matrix.
inline float2x2 operator*( const float2x2& lhs, const float2x2& rhs );

/// \relates float2x2
/// \brief Dot products each row of the left-hand matrix with the corresponding column of the right-hand matrix.
inline float2x2 operator*=( float2x2& lhs, const float2x2& rhs );

/// \relates float2x2
/// \brief Returns a copy of the float2x2 that has been component-wise divided by the given scalar value.
inline float2x2 operator/( const float2x2& lhs, const float rhs );

/// \relates float2x2
/// \brief Divides each component by the given scalar value.
inline float2x2 operator/=( float2x2& lhs, const float rhs );

/// \relates float2x2
/// \brief Returns a copy of the matrix where the left-hand matrix has been mathematically multiplied by the inverse of the right-hand matrix.
inline float2x2 operator/( const float2x2& lhs, const float2x2& rhs );

/// \relates float2x2
/// \brief Multiplies the left-hand matrix by the right-hand matrix (dot product row/col style).
inline float2x2 operator/=( float2x2& lhs, const float2x2& rhs );

/// \relates float2x2
/// \brief Prefix increment operator.  Adds one to each component of the given float2x2 before evaluation.
inline float2x2& operator++( float2x2& lhs );

/// \relates float2x2
/// \brief Postfix increment operator.  Adds one to each component of the given float2x2 after evaluation.
inline float2x2& operator++( float2x2& lhs, const int );

/// \relates float2x2
/// \brief Prefix decrement operator.  Subtracts one from each component of the given float2x2 before evaluation.
inline float2x2& operator--( float2x2& lhs );

/// \relates float2x2
/// \brief Postfix decrement operator.  Subtracts one from each component of the given float2x2 after evaluation.
inline float2x2& operator--( float2x2& lhs, const int );

/// \relates float2x2
/// \brief Returns a bool2x2 where each component is true if the component of the left-hand type is less than the corresponding right-hand type component.
inline bool2x2 operator<( const float2x2& lhs, const float2x2& rhs );

/// \relates float2x2
/// \brief Returns a bool2x2 where each component is true if the component of the left-hand type is less than or equal to the corresponding right-hand type component.
inline bool2x2 operator<=( const float2x2& lhs, const float2x2& rhs );

/// \relates float2x2
/// \brief Returns a bool2x2 where each component is true if the component of the left-hand type is greater than the corresponding right-hand type component.
inline bool2x2 operator>( const float2x2& lhs, const float2x2& rhs );

/// \relates float2x2
/// \brief Returns a bool2x2 where each component is true if the component of the left-hand type is greater than or equal to the corresponding right-hand type component.
inline bool2x2 operator>=( const float2x2& lhs, const float2x2& rhs );


// float2x3
/// \relates float2x3
/// \brief Returns a copy of the float2x3 that has been component-wise added by the given scalar value.
inline float2x3 operator+( const float2x3& lhs, const float rhs );

/// \relates float2x3
/// \brief Adds each component by the given scalar value.
inline float2x3 operator+=( float2x3& lhs, const float rhs );

/// \relates float2x3
/// \brief Returns a copy of the float2x3 that has been component-wise added by the corresponding component of the right-hand float2x3.
inline float2x3 operator+( const float2x3& lhs, const float2x3& rhs );

/// \relates float2x3
/// \brief Adds each component of the float2x3 by the corresponding component of the right-hand float2x3.
inline float2x3 operator+=( float2x3& lhs, const float2x3& rhs );

/// \relates float2x3
/// \brief Returns a copy of the float2x3 that has been component-wise subtracted by the given scalar value.
inline float2x3 operator-( const float2x3& lhs, const float rhs );

/// \relates float2x3
/// \brief Subtracts each component by the given scalar value.
inline float2x3 operator-=( float2x3& lhs, const float rhs );

/// \relates float2x3
/// \brief Returns a copy of the float2x3 that has been component-wise subtracted by the corresponding component of the right-hand float2x3.
inline float2x3 operator-( const float2x3& lhs, const float2x3& rhs );

/// \relates float2x3
/// \brief Subtracts each component of the float2x3 by the corresponding component of the right-hand float2x3.
inline float2x3 operator-=( float2x3& lhs, const float2x3& rhs );

/// \relates float2x3
/// \brief Returns a copy of the float2x3 that has been component-wise multiplied by the given scalar value.
inline float2x3 operator*( const float2x3& lhs, const float rhs );

/// \relates float2x3
/// \brief Multiplies each component by the given scalar value.
inline float2x3 operator*=( float2x3& lhs, const float rhs );

/// \relates float2x3
/// \brief Returns a copy of the matrix where each row of the left-hand matrix has been dot-producted by the corresponding column of the right-hand matrix.
inline float2x2 operator*( const float2x3& lhs, const float3x2& rhs );

/// \relates float2x3
/// \brief Dot products each row of the left-hand matrix with the corresponding column of the right-hand matrix.
inline float2x2 operator*=( float2x3& lhs, const float3x2& rhs );

/// \relates float2x3
/// \brief Returns a copy of the float2x3 that has been component-wise divided by the given scalar value.
inline float2x3 operator/( const float2x3& lhs, const float rhs );

/// \relates float2x3
/// \brief Divides each component by the given scalar value.
inline float2x3 operator/=( float2x3& lhs, const float rhs );

/// \relates float2x3
/// \brief Returns a copy of the float2x3 that has been component-wise divided by the corresponding component of the right-hand float2x3.
inline float2x3 operator/( const float2x3& lhs, const float2x3& rhs );

/// \relates float2x3
/// \brief Prefix increment operator.  Adds one to each component of the given float2x3 before evaluation.
inline float2x3& operator++( float2x3& lhs );

/// \relates float2x3
/// \brief Postfix increment operator.  Adds one to each component of the given float2x3 after evaluation.
inline float2x3& operator++( float2x3& lhs, const int );

/// \relates float2x3
/// \brief Prefix decrement operator.  Subtracts one from each component of the given float2x3 before evaluation.
inline float2x3& operator--( float2x3& lhs );

/// \relates float2x3
/// \brief Postfix decrement operator.  Subtracts one from each component of the given float2x3 after evaluation.
inline float2x3& operator--( float2x3& lhs, const int );

/// \relates float2x3
/// \brief Returns a bool2x3 where each component is true if the component of the left-hand type is less than the corresponding right-hand type component.
inline bool2x3 operator<( const float2x3& lhs, const float2x3& rhs );

/// \relates float2x3
/// \brief Returns a bool2x3 where each component is true if the component of the left-hand type is less than or equal to the corresponding right-hand type component.
inline bool2x3 operator<=( const float2x3& lhs, const float2x3& rhs );

/// \relates float2x3
/// \brief Returns a bool2x3 where each component is true if the component of the left-hand type is greater than the corresponding right-hand type component.
inline bool2x3 operator>( const float2x3& lhs, const float2x3& rhs );

/// \relates float2x3
/// \brief Returns a bool2x3 where each component is true if the component of the left-hand type is greater than or equal to the corresponding right-hand type component.
inline bool2x3 operator>=( const float2x3& lhs, const float2x3& rhs );


// float2x4
/// \relates float2x4
/// \brief Returns a copy of the float2x4 that has been component-wise added by the given scalar value.
inline float2x4 operator+( const float2x4& lhs, const float rhs );

/// \relates float2x4
/// \brief Adds each component by the given scalar value.
inline float2x4 operator+=( float2x4& lhs, const float rhs );

/// \relates float2x4
/// \brief Returns a copy of the float2x4 that has been component-wise added by the corresponding component of the right-hand float2x4.
inline float2x4 operator+( const float2x4& lhs, const float2x4& rhs );

/// \relates float2x4
/// \brief Adds each component of the float2x4 by the corresponding component of the right-hand float2x4.
inline float2x4 operator+=( float2x4& lhs, const float2x4& rhs );

/// \relates float2x4
/// \brief Returns a copy of the float2x4 that has been component-wise subtracted by the given scalar value.
inline float2x4 operator-( const float2x4& lhs, const float rhs );

/// \relates float2x4
/// \brief Subtracts each component by the given scalar value.
inline float2x4 operator-=( float2x4& lhs, const float rhs );

/// \relates float2x4
/// \brief Returns a copy of the float2x4 that has been component-wise subtracted by the corresponding component of the right-hand float2x4.
inline float2x4 operator-( const float2x4& lhs, const float2x4& rhs );

/// \relates float2x4
/// \brief Subtracts each component of the float2x4 by the corresponding component of the right-hand float2x4.
inline float2x4 operator-=( float2x4& lhs, const float2x4& rhs );

/// \relates float2x4
/// \brief Returns a copy of the float2x4 that has been component-wise multiplied by the given scalar value.
inline float2x4 operator*( const float2x4& lhs, const float rhs );

/// \relates float2x4
/// \brief Multiplies each component by the given scalar value.
inline float2x4 operator*=( float2x4& lhs, const float rhs );

/// \relates float2x4
/// \brief Returns a copy of the matrix where each row of the left-hand matrix has been dot-producted by the corresponding column of the right-hand matrix.
inline float2x2 operator*( const float2x4& lhs, const float4x2& rhs );

/// \relates float2x4
/// \brief Dot products each row of the left-hand matrix with the corresponding column of the right-hand matrix.
inline float2x2 operator*=( float2x4& lhs, const float4x2& rhs );

/// \relates float2x4
/// \brief Returns a copy of the float2x4 that has been component-wise divided by the given scalar value.
inline float2x4 operator/( const float2x4& lhs, const float rhs );

/// \relates float2x4
/// \brief Divides each component by the given scalar value.
inline float2x4 operator/=( float2x4& lhs, const float rhs );

/// \relates float2x4
/// \brief Returns a copy of the float2x4 that has been component-wise divided by the corresponding component of the right-hand float2x4.
inline float2x4 operator/( const float2x4& lhs, const float2x4& rhs );

/// \relates float2x4
/// \brief Prefix increment operator.  Adds one to each component of the given float2x4 before evaluation.
inline float2x4& operator++( float2x4& lhs );

/// \relates float2x4
/// \brief Postfix increment operator.  Adds one to each component of the given float2x4 after evaluation.
inline float2x4& operator++( float2x4& lhs, const int );

/// \relates float2x4
/// \brief Prefix decrement operator.  Subtracts one from each component of the given float2x4 before evaluation.
inline float2x4& operator--( float2x4& lhs );

/// \relates float2x4
/// \brief Postfix decrement operator.  Subtracts one from each component of the given float2x4 after evaluation.
inline float2x4& operator--( float2x4& lhs, const int );

/// \relates float2x4
/// \brief Returns a bool2x4 where each component is true if the component of the left-hand type is less than the corresponding right-hand type component.
inline bool2x4 operator<( const float2x4& lhs, const float2x4& rhs );

/// \relates float2x4
/// \brief Returns a bool2x4 where each component is true if the component of the left-hand type is less than or equal to the corresponding right-hand type component.
inline bool2x4 operator<=( const float2x4& lhs, const float2x4& rhs );

/// \relates float2x4
/// \brief Returns a bool2x4 where each component is true if the component of the left-hand type is greater than the corresponding right-hand type component.
inline bool2x4 operator>( const float2x4& lhs, const float2x4& rhs );

/// \relates float2x4
/// \brief Returns a bool2x4 where each component is true if the component of the left-hand type is greater than or equal to the corresponding right-hand type component.
inline bool2x4 operator>=( const float2x4& lhs, const float2x4& rhs );


// float3x2
/// \relates float3x2
/// \brief Returns a copy of the float3x2 that has been component-wise added by the given scalar value.
inline float3x2 operator+( const float3x2& lhs, const float rhs );

/// \relates float3x2
/// \brief Adds each component by the given scalar value.
inline float3x2 operator+=( float3x2& lhs, const float rhs );

/// \relates float3x2
/// \brief Returns a copy of the float3x2 that has been component-wise added by the corresponding component of the right-hand float3x2.
inline float3x2 operator+( const float3x2& lhs, const float3x2& rhs );

/// \relates float3x2
/// \brief Adds each component of the float3x2 by the corresponding component of the right-hand float3x2.
inline float3x2 operator+=( float3x2& lhs, const float3x2& rhs );

/// \relates float3x2
/// \brief Returns a copy of the float3x2 that has been component-wise subtracted by the given scalar value.
inline float3x2 operator-( const float3x2& lhs, const float rhs );

/// \relates float3x2
/// \brief Subtracts each component by the given scalar value.
inline float3x2 operator-=( float3x2& lhs, const float rhs );

/// \relates float3x2
/// \brief Returns a copy of the float3x2 that has been component-wise subtracted by the corresponding component of the right-hand float3x2.
inline float3x2 operator-( const float3x2& lhs, const float3x2& rhs );

/// \relates float3x2
/// \brief Subtracts each component of the float3x2 by the corresponding component of the right-hand float3x2.
inline float3x2 operator-=( float3x2& lhs, const float3x2& rhs );

/// \relates float3x2
/// \brief Returns a copy of the float3x2 that has been component-wise multiplied by the given scalar value.
inline float3x2 operator*( const float3x2& lhs, const float rhs );

/// \relates float3x2
/// \brief Multiplies each component by the given scalar value.
inline float3x2 operator*=( float3x2& lhs, const float rhs );

/// \relates float3x2
/// \brief Returns a copy of the matrix where each row of the left-hand matrix has been dot-producted by the corresponding column of the right-hand matrix.
inline float3x3 operator*( const float3x2& lhs, const float2x3& rhs );

/// \relates float3x2
/// \brief Dot products each row of the left-hand matrix with the corresponding column of the right-hand matrix.
inline float3x3 operator*=( float3x2& lhs, const float2x3& rhs );

/// \relates float3x2
/// \brief Returns a copy of the float3x2 that has been component-wise divided by the given scalar value.
inline float3x2 operator/( const float3x2& lhs, const float rhs );

/// \relates float3x2
/// \brief Divides each component by the given scalar value.
inline float3x2 operator/=( float3x2& lhs, const float rhs );

/// \relates float3x2
/// \brief Returns a copy of the float3x2 that has been component-wise divided by the corresponding component of the right-hand float3x2.
inline float3x2 operator/( const float3x2& lhs, const float3x2& rhs );

/// \relates float3x2
/// \brief Prefix increment operator.  Adds one to each component of the given float3x2 before evaluation.
inline float3x2& operator++( float3x2& lhs );

/// \relates float3x2
/// \brief Postfix increment operator.  Adds one to each component of the given float3x2 after evaluation.
inline float3x2& operator++( float3x2& lhs, const int );

/// \relates float3x2
/// \brief Prefix decrement operator.  Subtracts one from each component of the given float3x2 before evaluation.
inline float3x2& operator--( float3x2& lhs );

/// \relates float3x2
/// \brief Postfix decrement operator.  Subtracts one from each component of the given float3x2 after evaluation.
inline float3x2& operator--( float3x2& lhs, const int );

/// \relates float3x2
/// \brief Returns a bool3x2 where each component is true if the component of the left-hand type is less than the corresponding right-hand type component.
inline bool3x2 operator<( const float3x2& lhs, const float3x2& rhs );

/// \relates float3x2
/// \brief Returns a bool3x2 where each component is true if the component of the left-hand type is less than or equal to the corresponding right-hand type component.
inline bool3x2 operator<=( const float3x2& lhs, const float3x2& rhs );

/// \relates float3x2
/// \brief Returns a bool3x2 where each component is true if the component of the left-hand type is greater than the corresponding right-hand type component.
inline bool3x2 operator>( const float3x2& lhs, const float3x2& rhs );

/// \relates float3x2
/// \brief Returns a bool3x2 where each component is true if the component of the left-hand type is greater than or equal to the corresponding right-hand type component.
inline bool3x2 operator>=( const float3x2& lhs, const float3x2& rhs );


// float3x3
/// \relates float3x3
/// \brief Returns a copy of the float3x3 that has been component-wise added by the given scalar value.
inline float3x3 operator+( const float3x3& lhs, const float rhs );

/// \relates float3x3
/// \brief Adds each component by the given scalar value.
inline float3x3 operator+=( float3x3& lhs, const float rhs );

/// \relates float3x3
/// \brief Returns a copy of the float3x3 that has been component-wise added by the corresponding component of the right-hand float3x3.
inline float3x3 operator+( const float3x3& lhs, const float3x3& rhs );

/// \relates float3x3
/// \brief Adds each component of the float3x3 by the corresponding component of the right-hand float3x3.
inline float3x3 operator+=( float3x3& lhs, const float3x3& rhs );

/// \relates float3x3
/// \brief Returns a copy of the float3x3 that has been component-wise subtracted by the given scalar value.
inline float3x3 operator-( const float3x3& lhs, const float rhs );

/// \relates float3x3
/// \brief Subtracts each component by the given scalar value.
inline float3x3 operator-=( float3x3& lhs, const float rhs );

/// \relates float3x3
/// \brief Returns a copy of the float3x3 that has been component-wise subtracted by the corresponding component of the right-hand float3x3.
inline float3x3 operator-( const float3x3& lhs, const float3x3& rhs );

/// \relates float3x3
/// \brief Subtracts each component of the float3x3 by the corresponding component of the right-hand float3x3.
inline float3x3 operator-=( float3x3& lhs, const float3x3& rhs );

/// \relates float3x3
/// \brief Returns a copy of the float3x3 that has been component-wise multiplied by the given scalar value.
inline float3x3 operator*( const float3x3& lhs, const float rhs );

/// \relates float3x3
/// \brief Multiplies each component by the given scalar value.
inline float3x3 operator*=( float3x3& lhs, const float rhs );

/// \relates float3x3
/// \brief Returns a copy of the matrix where each row of the left-hand matrix has been dot-producted by the corresponding column of the right-hand matrix.
inline float3x3 operator*( const float3x3& lhs, const float3x3& rhs );

/// \relates float3x3
/// \brief Dot products each row of the left-hand matrix with the corresponding column of the right-hand matrix.
inline float3x3 operator*=( float3x3& lhs, const float3x3& rhs );

/// \relates float3x3
/// \brief Returns a copy of the float3x3 that has been component-wise divided by the given scalar value.
inline float3x3 operator/( const float3x3& lhs, const float rhs );

/// \relates float3x3
/// \brief Divides each component by the given scalar value.
inline float3x3 operator/=( float3x3& lhs, const float rhs );

/// \relates float3x3
/// \brief Returns a copy of the matrix where the left-hand matrix has been mathematically multiplied by the inverse of the right-hand matrix.
inline float3x3 operator/( const float3x3& lhs, const float3x3& rhs );

/// \relates float3x3
/// \brief Multiplies the left-hand matrix by the right-hand matrix (dot product row/col style).
inline float3x3 operator/=( float3x3& lhs, const float3x3& rhs );

/// \relates float3x3
/// \brief Prefix increment operator.  Adds one to each component of the given float3x3 before evaluation.
inline float3x3& operator++( float3x3& lhs );

/// \relates float3x3
/// \brief Postfix increment operator.  Adds one to each component of the given float3x3 after evaluation.
inline float3x3& operator++( float3x3& lhs, const int );

/// \relates float3x3
/// \brief Prefix decrement operator.  Subtracts one from each component of the given float3x3 before evaluation.
inline float3x3& operator--( float3x3& lhs );

/// \relates float3x3
/// \brief Postfix decrement operator.  Subtracts one from each component of the given float3x3 after evaluation.
inline float3x3& operator--( float3x3& lhs, const int );

/// \relates float3x3
/// \brief Returns a bool3x3 where each component is true if the component of the left-hand type is less than the corresponding right-hand type component.
inline bool3x3 operator<( const float3x3& lhs, const float3x3& rhs );

/// \relates float3x3
/// \brief Returns a bool3x3 where each component is true if the component of the left-hand type is less than or equal to the corresponding right-hand type component.
inline bool3x3 operator<=( const float3x3& lhs, const float3x3& rhs );

/// \relates float3x3
/// \brief Returns a bool3x3 where each component is true if the component of the left-hand type is greater than the corresponding right-hand type component.
inline bool3x3 operator>( const float3x3& lhs, const float3x3& rhs );

/// \relates float3x3
/// \brief Returns a bool3x3 where each component is true if the component of the left-hand type is greater than or equal to the corresponding right-hand type component.
inline bool3x3 operator>=( const float3x3& lhs, const float3x3& rhs );


// float3x4
/// \relates float3x4
/// \brief Returns a copy of the float3x4 that has been component-wise added by the given scalar value.
inline float3x4 operator+( const float3x4& lhs, const float rhs );

/// \relates float3x4
/// \brief Adds each component by the given scalar value.
inline float3x4 operator+=( float3x4& lhs, const float rhs );

/// \relates float3x4
/// \brief Returns a copy of the float3x4 that has been component-wise added by the corresponding component of the right-hand float3x4.
inline float3x4 operator+( const float3x4& lhs, const float3x4& rhs );

/// \relates float3x4
/// \brief Adds each component of the float3x4 by the corresponding component of the right-hand float3x4.
inline float3x4 operator+=( float3x4& lhs, const float3x4& rhs );

/// \relates float3x4
/// \brief Returns a copy of the float3x4 that has been component-wise subtracted by the given scalar value.
inline float3x4 operator-( const float3x4& lhs, const float rhs );

/// \relates float3x4
/// \brief Subtracts each component by the given scalar value.
inline float3x4 operator-=( float3x4& lhs, const float rhs );

/// \relates float3x4
/// \brief Returns a copy of the float3x4 that has been component-wise subtracted by the corresponding component of the right-hand float3x4.
inline float3x4 operator-( const float3x4& lhs, const float3x4& rhs );

/// \relates float3x4
/// \brief Subtracts each component of the float3x4 by the corresponding component of the right-hand float3x4.
inline float3x4 operator-=( float3x4& lhs, const float3x4& rhs );

/// \relates float3x4
/// \brief Returns a copy of the float3x4 that has been component-wise multiplied by the given scalar value.
inline float3x4 operator*( const float3x4& lhs, const float rhs );

/// \relates float3x4
/// \brief Multiplies each component by the given scalar value.
inline float3x4 operator*=( float3x4& lhs, const float rhs );

/// \relates float3x4
/// \brief Returns a copy of the matrix where each row of the left-hand matrix has been dot-producted by the corresponding column of the right-hand matrix.
inline float3x3 operator*( const float3x4& lhs, const float4x3& rhs );

/// \relates float3x4
/// \brief Dot products each row of the left-hand matrix with the corresponding column of the right-hand matrix.
inline float3x3 operator*=( float3x4& lhs, const float4x3& rhs );

/// \relates float3x4
/// \brief Returns a copy of the float3x4 that has been component-wise divided by the given scalar value.
inline float3x4 operator/( const float3x4& lhs, const float rhs );

/// \relates float3x4
/// \brief Divides each component by the given scalar value.
inline float3x4 operator/=( float3x4& lhs, const float rhs );

/// \relates float3x4
/// \brief Returns a copy of the float3x4 that has been component-wise divided by the corresponding component of the right-hand float3x4.
inline float3x4 operator/( const float3x4& lhs, const float3x4& rhs );

/// \relates float3x4
/// \brief Prefix increment operator.  Adds one to each component of the given float3x4 before evaluation.
inline float3x4& operator++( float3x4& lhs );

/// \relates float3x4
/// \brief Postfix increment operator.  Adds one to each component of the given float3x4 after evaluation.
inline float3x4& operator++( float3x4& lhs, const int );

/// \relates float3x4
/// \brief Prefix decrement operator.  Subtracts one from each component of the given float3x4 before evaluation.
inline float3x4& operator--( float3x4& lhs );

/// \relates float3x4
/// \brief Postfix decrement operator.  Subtracts one from each component of the given float3x4 after evaluation.
inline float3x4& operator--( float3x4& lhs, const int );

/// \relates float3x4
/// \brief Returns a bool3x4 where each component is true if the component of the left-hand type is less than the corresponding right-hand type component.
inline bool3x4 operator<( const float3x4& lhs, const float3x4& rhs );

/// \relates float3x4
/// \brief Returns a bool3x4 where each component is true if the component of the left-hand type is less than or equal to the corresponding right-hand type component.
inline bool3x4 operator<=( const float3x4& lhs, const float3x4& rhs );

/// \relates float3x4
/// \brief Returns a bool3x4 where each component is true if the component of the left-hand type is greater than the corresponding right-hand type component.
inline bool3x4 operator>( const float3x4& lhs, const float3x4& rhs );

/// \relates float3x4
/// \brief Returns a bool3x4 where each component is true if the component of the left-hand type is greater than or equal to the corresponding right-hand type component.
inline bool3x4 operator>=( const float3x4& lhs, const float3x4& rhs );


// float4x2
/// \relates float4x2
/// \brief Returns a copy of the float4x2 that has been component-wise added by the given scalar value.
inline float4x2 operator+( const float4x2& lhs, const float rhs );

/// \relates float4x2
/// \brief Adds each component by the given scalar value.
inline float4x2 operator+=( float4x2& lhs, const float rhs );

/// \relates float4x2
/// \brief Returns a copy of the float4x2 that has been component-wise added by the corresponding component of the right-hand float4x2.
inline float4x2 operator+( const float4x2& lhs, const float4x2& rhs );

/// \relates float4x2
/// \brief Adds each component of the float4x2 by the corresponding component of the right-hand float4x2.
inline float4x2 operator+=( float4x2& lhs, const float4x2& rhs );

/// \relates float4x2
/// \brief Returns a copy of the float4x2 that has been component-wise subtracted by the given scalar value.
inline float4x2 operator-( const float4x2& lhs, const float rhs );

/// \relates float4x2
/// \brief Subtracts each component by the given scalar value.
inline float4x2 operator-=( float4x2& lhs, const float rhs );

/// \relates float4x2
/// \brief Returns a copy of the float4x2 that has been component-wise subtracted by the corresponding component of the right-hand float4x2.
inline float4x2 operator-( const float4x2& lhs, const float4x2& rhs );

/// \relates float4x2
/// \brief Subtracts each component of the float4x2 by the corresponding component of the right-hand float4x2.
inline float4x2 operator-=( float4x2& lhs, const float4x2& rhs );

/// \relates float4x2
/// \brief Returns a copy of the float4x2 that has been component-wise multiplied by the given scalar value.
inline float4x2 operator*( const float4x2& lhs, const float rhs );

/// \relates float4x2
/// \brief Multiplies each component by the given scalar value.
inline float4x2 operator*=( float4x2& lhs, const float rhs );

/// \relates float4x2
/// \brief Returns a copy of the matrix where each row of the left-hand matrix has been dot-producted by the corresponding column of the right-hand matrix.
inline float4x4 operator*( const float4x2& lhs, const float2x4& rhs );

/// \relates float4x2
/// \brief Dot products each row of the left-hand matrix with the corresponding column of the right-hand matrix.
inline float4x4 operator*=( float4x2& lhs, const float2x4& rhs );

/// \relates float4x2
/// \brief Returns a copy of the float4x2 that has been component-wise divided by the given scalar value.
inline float4x2 operator/( const float4x2& lhs, const float rhs );

/// \relates float4x2
/// \brief Divides each component by the given scalar value.
inline float4x2 operator/=( float4x2& lhs, const float rhs );

/// \relates float4x2
/// \brief Returns a copy of the float4x2 that has been component-wise divided by the corresponding component of the right-hand float4x2.
inline float4x2 operator/( const float4x2& lhs, const float4x2& rhs );

/// \relates float4x2
/// \brief Prefix increment operator.  Adds one to each component of the given float4x2 before evaluation.
inline float4x2& operator++( float4x2& lhs );

/// \relates float4x2
/// \brief Postfix increment operator.  Adds one to each component of the given float4x2 after evaluation.
inline float4x2& operator++( float4x2& lhs, const int );

/// \relates float4x2
/// \brief Prefix decrement operator.  Subtracts one from each component of the given float4x2 before evaluation.
inline float4x2& operator--( float4x2& lhs );

/// \relates float4x2
/// \brief Postfix decrement operator.  Subtracts one from each component of the given float4x2 after evaluation.
inline float4x2& operator--( float4x2& lhs, const int );

/// \relates float4x2
/// \brief Returns a bool4x2 where each component is true if the component of the left-hand type is less than the corresponding right-hand type component.
inline bool4x2 operator<( const float4x2& lhs, const float4x2& rhs );

/// \relates float4x2
/// \brief Returns a bool4x2 where each component is true if the component of the left-hand type is less than or equal to the corresponding right-hand type component.
inline bool4x2 operator<=( const float4x2& lhs, const float4x2& rhs );

/// \relates float4x2
/// \brief Returns a bool4x2 where each component is true if the component of the left-hand type is greater than the corresponding right-hand type component.
inline bool4x2 operator>( const float4x2& lhs, const float4x2& rhs );

/// \relates float4x2
/// \brief Returns a bool4x2 where each component is true if the component of the left-hand type is greater than or equal to the corresponding right-hand type component.
inline bool4x2 operator>=( const float4x2& lhs, const float4x2& rhs );


// float4x3
/// \relates float4x3
/// \brief Returns a copy of the float4x3 that has been component-wise added by the given scalar value.
inline float4x3 operator+( const float4x3& lhs, const float rhs );

/// \relates float4x3
/// \brief Adds each component by the given scalar value.
inline float4x3 operator+=( float4x3& lhs, const float rhs );

/// \relates float4x3
/// \brief Returns a copy of the float4x3 that has been component-wise added by the corresponding component of the right-hand float4x3.
inline float4x3 operator+( const float4x3& lhs, const float4x3& rhs );

/// \relates float4x3
/// \brief Adds each component of the float4x3 by the corresponding component of the right-hand float4x3.
inline float4x3 operator+=( float4x3& lhs, const float4x3& rhs );

/// \relates float4x3
/// \brief Returns a copy of the float4x3 that has been component-wise subtracted by the given scalar value.
inline float4x3 operator-( const float4x3& lhs, const float rhs );

/// \relates float4x3
/// \brief Subtracts each component by the given scalar value.
inline float4x3 operator-=( float4x3& lhs, const float rhs );

/// \relates float4x3
/// \brief Returns a copy of the float4x3 that has been component-wise subtracted by the corresponding component of the right-hand float4x3.
inline float4x3 operator-( const float4x3& lhs, const float4x3& rhs );

/// \relates float4x3
/// \brief Subtracts each component of the float4x3 by the corresponding component of the right-hand float4x3.
inline float4x3 operator-=( float4x3& lhs, const float4x3& rhs );

/// \relates float4x3
/// \brief Returns a copy of the float4x3 that has been component-wise multiplied by the given scalar value.
inline float4x3 operator*( const float4x3& lhs, const float rhs );

/// \relates float4x3
/// \brief Multiplies each component by the given scalar value.
inline float4x3 operator*=( float4x3& lhs, const float rhs );

/// \relates float4x3
/// \brief Returns a copy of the matrix where each row of the left-hand matrix has been dot-producted by the corresponding column of the right-hand matrix.
inline float4x4 operator*( const float4x3& lhs, const float3x4& rhs );

/// \relates float4x3
/// \brief Dot products each row of the left-hand matrix with the corresponding column of the right-hand matrix.
inline float4x4 operator*=( float4x3& lhs, const float3x4& rhs );

/// \relates float4x3
/// \brief Returns a copy of the float4x3 that has been component-wise divided by the given scalar value.
inline float4x3 operator/( const float4x3& lhs, const float rhs );

/// \relates float4x3
/// \brief Divides each component by the given scalar value.
inline float4x3 operator/=( float4x3& lhs, const float rhs );

/// \relates float4x3
/// \brief Returns a copy of the float4x3 that has been component-wise divided by the corresponding component of the right-hand float4x3.
inline float4x3 operator/( const float4x3& lhs, const float4x3& rhs );

/// \relates float4x3
/// \brief Prefix increment operator.  Adds one to each component of the given float4x3 before evaluation.
inline float4x3& operator++( float4x3& lhs );

/// \relates float4x3
/// \brief Postfix increment operator.  Adds one to each component of the given float4x3 after evaluation.
inline float4x3& operator++( float4x3& lhs, const int );

/// \relates float4x3
/// \brief Prefix decrement operator.  Subtracts one from each component of the given float4x3 before evaluation.
inline float4x3& operator--( float4x3& lhs );

/// \relates float4x3
/// \brief Postfix decrement operator.  Subtracts one from each component of the given float4x3 after evaluation.
inline float4x3& operator--( float4x3& lhs, const int );

/// \relates float4x3
/// \brief Returns a bool4x3 where each component is true if the component of the left-hand type is less than the corresponding right-hand type component.
inline bool4x3 operator<( const float4x3& lhs, const float4x3& rhs );

/// \relates float4x3
/// \brief Returns a bool4x3 where each component is true if the component of the left-hand type is less than or equal to the corresponding right-hand type component.
inline bool4x3 operator<=( const float4x3& lhs, const float4x3& rhs );

/// \relates float4x3
/// \brief Returns a bool4x3 where each component is true if the component of the left-hand type is greater than the corresponding right-hand type component.
inline bool4x3 operator>( const float4x3& lhs, const float4x3& rhs );

/// \relates float4x3
/// \brief Returns a bool4x3 where each component is true if the component of the left-hand type is greater than or equal to the corresponding right-hand type component.
inline bool4x3 operator>=( const float4x3& lhs, const float4x3& rhs );


// float4x4
/// \relates float4x4
/// \brief Returns a copy of the float4x4 that has been component-wise added by the given scalar value.
inline float4x4 operator+( const float4x4& lhs, const float rhs );

/// \relates float4x4
/// \brief Adds each component by the given scalar value.
inline float4x4 operator+=( float4x4& lhs, const float rhs );

/// \relates float4x4
/// \brief Returns a copy of the float4x4 that has been component-wise added by the corresponding component of the right-hand float4x4.
inline float4x4 operator+( const float4x4& lhs, const float4x4& rhs );

/// \relates float4x4
/// \brief Adds each component of the float4x4 by the corresponding component of the right-hand float4x4.
inline float4x4 operator+=( float4x4& lhs, const float4x4& rhs );

/// \relates float4x4
/// \brief Returns a copy of the float4x4 that has been component-wise subtracted by the given scalar value.
inline float4x4 operator-( const float4x4& lhs, const float rhs );

/// \relates float4x4
/// \brief Subtracts each component by the given scalar value.
inline float4x4 operator-=( float4x4& lhs, const float rhs );

/// \relates float4x4
/// \brief Returns a copy of the float4x4 that has been component-wise subtracted by the corresponding component of the right-hand float4x4.
inline float4x4 operator-( const float4x4& lhs, const float4x4& rhs );

/// \relates float4x4
/// \brief Subtracts each component of the float4x4 by the corresponding component of the right-hand float4x4.
inline float4x4 operator-=( float4x4& lhs, const float4x4& rhs );

/// \relates float4x4
/// \brief Returns a copy of the float4x4 that has been component-wise multiplied by the given scalar value.
inline float4x4 operator*( const float4x4& lhs, const float rhs );

/// \relates float4x4
/// \brief Multiplies each component by the given scalar value.
inline float4x4 operator*=( float4x4& lhs, const float rhs );

/// \relates float4x4
/// \brief Returns a copy of the matrix where each row of the left-hand matrix has been dot-producted by the corresponding column of the right-hand matrix.
inline float4x4 operator*( const float4x4& lhs, const float4x4& rhs );

/// \relates float4x4
/// \brief Dot products each row of the left-hand matrix with the corresponding column of the right-hand matrix.
inline float4x4 operator*=( float4x4& lhs, const float4x4& rhs );

/// \relates float4x4
/// \brief Returns a copy of the float4x4 that has been component-wise divided by the given scalar value.
inline float4x4 operator/( const float4x4& lhs, const float rhs );

/// \relates float4x4
/// \brief Divides each component by the given scalar value.
inline float4x4 operator/=( float4x4& lhs, const float rhs );

/// \relates float4x4
/// \brief Returns a copy of the matrix where the left-hand matrix has been mathematically multiplied by the inverse of the right-hand matrix.
inline float4x4 operator/( const float4x4& lhs, const float4x4& rhs );

/// \relates float4x4
/// \brief Multiplies the left-hand matrix by the right-hand matrix (dot product row/col style).
inline float4x4 operator/=( float4x4& lhs, const float4x4& rhs );

/// \relates float4x4
/// \brief Prefix increment operator.  Adds one to each component of the given float4x4 before evaluation.
inline float4x4& operator++( float4x4& lhs );

/// \relates float4x4
/// \brief Postfix increment operator.  Adds one to each component of the given float4x4 after evaluation.
inline float4x4& operator++( float4x4& lhs, const int );

/// \relates float4x4
/// \brief Prefix decrement operator.  Subtracts one from each component of the given float4x4 before evaluation.
inline float4x4& operator--( float4x4& lhs );

/// \relates float4x4
/// \brief Postfix decrement operator.  Subtracts one from each component of the given float4x4 after evaluation.
inline float4x4& operator--( float4x4& lhs, const int );

/// \relates float4x4
/// \brief Returns a bool4x4 where each component is true if the component of the left-hand type is less than the corresponding right-hand type component.
inline bool4x4 operator<( const float4x4& lhs, const float4x4& rhs );

/// \relates float4x4
/// \brief Returns a bool4x4 where each component is true if the component of the left-hand type is less than or equal to the corresponding right-hand type component.
inline bool4x4 operator<=( const float4x4& lhs, const float4x4& rhs );

/// \relates float4x4
/// \brief Returns a bool4x4 where each component is true if the component of the left-hand type is greater than the corresponding right-hand type component.
inline bool4x4 operator>( const float4x4& lhs, const float4x4& rhs );

/// \relates float4x4
/// \brief Returns a bool4x4 where each component is true if the component of the left-hand type is greater than or equal to the corresponding right-hand type component.
inline bool4x4 operator>=( const float4x4& lhs, const float4x4& rhs );


// double2x2
/// \relates double2x2
/// \brief Returns a copy of the double2x2 that has been component-wise added by the given scalar value.
inline double2x2 operator+( const double2x2& lhs, const double rhs );

/// \relates double2x2
/// \brief Adds each component by the given scalar value.
inline double2x2 operator+=( double2x2& lhs, const double rhs );

/// \relates double2x2
/// \brief Returns a copy of the double2x2 that has been component-wise added by the corresponding component of the right-hand double2x2.
inline double2x2 operator+( const double2x2& lhs, const double2x2& rhs );

/// \relates double2x2
/// \brief Adds each component of the double2x2 by the corresponding component of the right-hand double2x2.
inline double2x2 operator+=( double2x2& lhs, const double2x2& rhs );

/// \relates double2x2
/// \brief Returns a copy of the double2x2 that has been component-wise subtracted by the given scalar value.
inline double2x2 operator-( const double2x2& lhs, const double rhs );

/// \relates double2x2
/// \brief Subtracts each component by the given scalar value.
inline double2x2 operator-=( double2x2& lhs, const double rhs );

/// \relates double2x2
/// \brief Returns a copy of the double2x2 that has been component-wise subtracted by the corresponding component of the right-hand double2x2.
inline double2x2 operator-( const double2x2& lhs, const double2x2& rhs );

/// \relates double2x2
/// \brief Subtracts each component of the double2x2 by the corresponding component of the right-hand double2x2.
inline double2x2 operator-=( double2x2& lhs, const double2x2& rhs );

/// \relates double2x2
/// \brief Returns a copy of the double2x2 that has been component-wise multiplied by the given scalar value.
inline double2x2 operator*( const double2x2& lhs, const double rhs );

/// \relates double2x2
/// \brief Multiplies each component by the given scalar value.
inline double2x2 operator*=( double2x2& lhs, const double rhs );

/// \relates double2x2
/// \brief Returns a copy of the matrix where each row of the left-hand matrix has been dot-producted by the corresponding column of the right-hand matrix.
inline double2x2 operator*( const double2x2& lhs, const double2x2& rhs );

/// \relates double2x2
/// \brief Dot products each row of the left-hand matrix with the corresponding column of the right-hand matrix.
inline double2x2 operator*=( double2x2& lhs, const double2x2& rhs );

/// \relates double2x2
/// \brief Returns a copy of the double2x2 that has been component-wise divided by the given scalar value.
inline double2x2 operator/( const double2x2& lhs, const double rhs );

/// \relates double2x2
/// \brief Divides each component by the given scalar value.
inline double2x2 operator/=( double2x2& lhs, const double rhs );

/// \relates double2x2
/// \brief Returns a copy of the matrix where the left-hand matrix has been mathematically multiplied by the inverse of the right-hand matrix.
inline double2x2 operator/( const double2x2& lhs, const double2x2& rhs );

/// \relates double2x2
/// \brief Multiplies the left-hand matrix by the right-hand matrix (dot product row/col style).
inline double2x2 operator/=( double2x2& lhs, const double2x2& rhs );

/// \relates double2x2
/// \brief Prefix increment operator.  Adds one to each component of the given double2x2 before evaluation.
inline double2x2& operator++( double2x2& lhs );

/// \relates double2x2
/// \brief Postfix increment operator.  Adds one to each component of the given double2x2 after evaluation.
inline double2x2& operator++( double2x2& lhs, const int );

/// \relates double2x2
/// \brief Prefix decrement operator.  Subtracts one from each component of the given double2x2 before evaluation.
inline double2x2& operator--( double2x2& lhs );

/// \relates double2x2
/// \brief Postfix decrement operator.  Subtracts one from each component of the given double2x2 after evaluation.
inline double2x2& operator--( double2x2& lhs, const int );

/// \relates double2x2
/// \brief Returns a bool2x2 where each component is true if the component of the left-hand type is less than the corresponding right-hand type component.
inline bool2x2 operator<( const double2x2& lhs, const double2x2& rhs );

/// \relates double2x2
/// \brief Returns a bool2x2 where each component is true if the component of the left-hand type is less than or equal to the corresponding right-hand type component.
inline bool2x2 operator<=( const double2x2& lhs, const double2x2& rhs );

/// \relates double2x2
/// \brief Returns a bool2x2 where each component is true if the component of the left-hand type is greater than the corresponding right-hand type component.
inline bool2x2 operator>( const double2x2& lhs, const double2x2& rhs );

/// \relates double2x2
/// \brief Returns a bool2x2 where each component is true if the component of the left-hand type is greater than or equal to the corresponding right-hand type component.
inline bool2x2 operator>=( const double2x2& lhs, const double2x2& rhs );


// double2x3
/// \relates double2x3
/// \brief Returns a copy of the double2x3 that has been component-wise added by the given scalar value.
inline double2x3 operator+( const double2x3& lhs, const double rhs );

/// \relates double2x3
/// \brief Adds each component by the given scalar value.
inline double2x3 operator+=( double2x3& lhs, const double rhs );

/// \relates double2x3
/// \brief Returns a copy of the double2x3 that has been component-wise added by the corresponding component of the right-hand double2x3.
inline double2x3 operator+( const double2x3& lhs, const double2x3& rhs );

/// \relates double2x3
/// \brief Adds each component of the double2x3 by the corresponding component of the right-hand double2x3.
inline double2x3 operator+=( double2x3& lhs, const double2x3& rhs );

/// \relates double2x3
/// \brief Returns a copy of the double2x3 that has been component-wise subtracted by the given scalar value.
inline double2x3 operator-( const double2x3& lhs, const double rhs );

/// \relates double2x3
/// \brief Subtracts each component by the given scalar value.
inline double2x3 operator-=( double2x3& lhs, const double rhs );

/// \relates double2x3
/// \brief Returns a copy of the double2x3 that has been component-wise subtracted by the corresponding component of the right-hand double2x3.
inline double2x3 operator-( const double2x3& lhs, const double2x3& rhs );

/// \relates double2x3
/// \brief Subtracts each component of the double2x3 by the corresponding component of the right-hand double2x3.
inline double2x3 operator-=( double2x3& lhs, const double2x3& rhs );

/// \relates double2x3
/// \brief Returns a copy of the double2x3 that has been component-wise multiplied by the given scalar value.
inline double2x3 operator*( const double2x3& lhs, const double rhs );

/// \relates double2x3
/// \brief Multiplies each component by the given scalar value.
inline double2x3 operator*=( double2x3& lhs, const double rhs );

/// \relates double2x3
/// \brief Returns a copy of the matrix where each row of the left-hand matrix has been dot-producted by the corresponding column of the right-hand matrix.
inline double2x2 operator*( const double2x3& lhs, const double3x2& rhs );

/// \relates double2x3
/// \brief Dot products each row of the left-hand matrix with the corresponding column of the right-hand matrix.
inline double2x2 operator*=( double2x3& lhs, const double3x2& rhs );

/// \relates double2x3
/// \brief Returns a copy of the double2x3 that has been component-wise divided by the given scalar value.
inline double2x3 operator/( const double2x3& lhs, const double rhs );

/// \relates double2x3
/// \brief Divides each component by the given scalar value.
inline double2x3 operator/=( double2x3& lhs, const double rhs );

/// \relates double2x3
/// \brief Returns a copy of the double2x3 that has been component-wise divided by the corresponding component of the right-hand double2x3.
inline double2x3 operator/( const double2x3& lhs, const double2x3& rhs );

/// \relates double2x3
/// \brief Prefix increment operator.  Adds one to each component of the given double2x3 before evaluation.
inline double2x3& operator++( double2x3& lhs );

/// \relates double2x3
/// \brief Postfix increment operator.  Adds one to each component of the given double2x3 after evaluation.
inline double2x3& operator++( double2x3& lhs, const int );

/// \relates double2x3
/// \brief Prefix decrement operator.  Subtracts one from each component of the given double2x3 before evaluation.
inline double2x3& operator--( double2x3& lhs );

/// \relates double2x3
/// \brief Postfix decrement operator.  Subtracts one from each component of the given double2x3 after evaluation.
inline double2x3& operator--( double2x3& lhs, const int );

/// \relates double2x3
/// \brief Returns a bool2x3 where each component is true if the component of the left-hand type is less than the corresponding right-hand type component.
inline bool2x3 operator<( const double2x3& lhs, const double2x3& rhs );

/// \relates double2x3
/// \brief Returns a bool2x3 where each component is true if the component of the left-hand type is less than or equal to the corresponding right-hand type component.
inline bool2x3 operator<=( const double2x3& lhs, const double2x3& rhs );

/// \relates double2x3
/// \brief Returns a bool2x3 where each component is true if the component of the left-hand type is greater than the corresponding right-hand type component.
inline bool2x3 operator>( const double2x3& lhs, const double2x3& rhs );

/// \relates double2x3
/// \brief Returns a bool2x3 where each component is true if the component of the left-hand type is greater than or equal to the corresponding right-hand type component.
inline bool2x3 operator>=( const double2x3& lhs, const double2x3& rhs );


// double2x4
/// \relates double2x4
/// \brief Returns a copy of the double2x4 that has been component-wise added by the given scalar value.
inline double2x4 operator+( const double2x4& lhs, const double rhs );

/// \relates double2x4
/// \brief Adds each component by the given scalar value.
inline double2x4 operator+=( double2x4& lhs, const double rhs );

/// \relates double2x4
/// \brief Returns a copy of the double2x4 that has been component-wise added by the corresponding component of the right-hand double2x4.
inline double2x4 operator+( const double2x4& lhs, const double2x4& rhs );

/// \relates double2x4
/// \brief Adds each component of the double2x4 by the corresponding component of the right-hand double2x4.
inline double2x4 operator+=( double2x4& lhs, const double2x4& rhs );

/// \relates double2x4
/// \brief Returns a copy of the double2x4 that has been component-wise subtracted by the given scalar value.
inline double2x4 operator-( const double2x4& lhs, const double rhs );

/// \relates double2x4
/// \brief Subtracts each component by the given scalar value.
inline double2x4 operator-=( double2x4& lhs, const double rhs );

/// \relates double2x4
/// \brief Returns a copy of the double2x4 that has been component-wise subtracted by the corresponding component of the right-hand double2x4.
inline double2x4 operator-( const double2x4& lhs, const double2x4& rhs );

/// \relates double2x4
/// \brief Subtracts each component of the double2x4 by the corresponding component of the right-hand double2x4.
inline double2x4 operator-=( double2x4& lhs, const double2x4& rhs );

/// \relates double2x4
/// \brief Returns a copy of the double2x4 that has been component-wise multiplied by the given scalar value.
inline double2x4 operator*( const double2x4& lhs, const double rhs );

/// \relates double2x4
/// \brief Multiplies each component by the given scalar value.
inline double2x4 operator*=( double2x4& lhs, const double rhs );

/// \relates double2x4
/// \brief Returns a copy of the matrix where each row of the left-hand matrix has been dot-producted by the corresponding column of the right-hand matrix.
inline double2x2 operator*( const double2x4& lhs, const double4x2& rhs );

/// \relates double2x4
/// \brief Dot products each row of the left-hand matrix with the corresponding column of the right-hand matrix.
inline double2x2 operator*=( double2x4& lhs, const double4x2& rhs );

/// \relates double2x4
/// \brief Returns a copy of the double2x4 that has been component-wise divided by the given scalar value.
inline double2x4 operator/( const double2x4& lhs, const double rhs );

/// \relates double2x4
/// \brief Divides each component by the given scalar value.
inline double2x4 operator/=( double2x4& lhs, const double rhs );

/// \relates double2x4
/// \brief Returns a copy of the double2x4 that has been component-wise divided by the corresponding component of the right-hand double2x4.
inline double2x4 operator/( const double2x4& lhs, const double2x4& rhs );

/// \relates double2x4
/// \brief Prefix increment operator.  Adds one to each component of the given double2x4 before evaluation.
inline double2x4& operator++( double2x4& lhs );

/// \relates double2x4
/// \brief Postfix increment operator.  Adds one to each component of the given double2x4 after evaluation.
inline double2x4& operator++( double2x4& lhs, const int );

/// \relates double2x4
/// \brief Prefix decrement operator.  Subtracts one from each component of the given double2x4 before evaluation.
inline double2x4& operator--( double2x4& lhs );

/// \relates double2x4
/// \brief Postfix decrement operator.  Subtracts one from each component of the given double2x4 after evaluation.
inline double2x4& operator--( double2x4& lhs, const int );

/// \relates double2x4
/// \brief Returns a bool2x4 where each component is true if the component of the left-hand type is less than the corresponding right-hand type component.
inline bool2x4 operator<( const double2x4& lhs, const double2x4& rhs );

/// \relates double2x4
/// \brief Returns a bool2x4 where each component is true if the component of the left-hand type is less than or equal to the corresponding right-hand type component.
inline bool2x4 operator<=( const double2x4& lhs, const double2x4& rhs );

/// \relates double2x4
/// \brief Returns a bool2x4 where each component is true if the component of the left-hand type is greater than the corresponding right-hand type component.
inline bool2x4 operator>( const double2x4& lhs, const double2x4& rhs );

/// \relates double2x4
/// \brief Returns a bool2x4 where each component is true if the component of the left-hand type is greater than or equal to the corresponding right-hand type component.
inline bool2x4 operator>=( const double2x4& lhs, const double2x4& rhs );


// double3x2
/// \relates double3x2
/// \brief Returns a copy of the double3x2 that has been component-wise added by the given scalar value.
inline double3x2 operator+( const double3x2& lhs, const double rhs );

/// \relates double3x2
/// \brief Adds each component by the given scalar value.
inline double3x2 operator+=( double3x2& lhs, const double rhs );

/// \relates double3x2
/// \brief Returns a copy of the double3x2 that has been component-wise added by the corresponding component of the right-hand double3x2.
inline double3x2 operator+( const double3x2& lhs, const double3x2& rhs );

/// \relates double3x2
/// \brief Adds each component of the double3x2 by the corresponding component of the right-hand double3x2.
inline double3x2 operator+=( double3x2& lhs, const double3x2& rhs );

/// \relates double3x2
/// \brief Returns a copy of the double3x2 that has been component-wise subtracted by the given scalar value.
inline double3x2 operator-( const double3x2& lhs, const double rhs );

/// \relates double3x2
/// \brief Subtracts each component by the given scalar value.
inline double3x2 operator-=( double3x2& lhs, const double rhs );

/// \relates double3x2
/// \brief Returns a copy of the double3x2 that has been component-wise subtracted by the corresponding component of the right-hand double3x2.
inline double3x2 operator-( const double3x2& lhs, const double3x2& rhs );

/// \relates double3x2
/// \brief Subtracts each component of the double3x2 by the corresponding component of the right-hand double3x2.
inline double3x2 operator-=( double3x2& lhs, const double3x2& rhs );

/// \relates double3x2
/// \brief Returns a copy of the double3x2 that has been component-wise multiplied by the given scalar value.
inline double3x2 operator*( const double3x2& lhs, const double rhs );

/// \relates double3x2
/// \brief Multiplies each component by the given scalar value.
inline double3x2 operator*=( double3x2& lhs, const double rhs );

/// \relates double3x2
/// \brief Returns a copy of the matrix where each row of the left-hand matrix has been dot-producted by the corresponding column of the right-hand matrix.
inline double3x3 operator*( const double3x2& lhs, const double2x3& rhs );

/// \relates double3x2
/// \brief Dot products each row of the left-hand matrix with the corresponding column of the right-hand matrix.
inline double3x3 operator*=( double3x2& lhs, const double2x3& rhs );

/// \relates double3x2
/// \brief Returns a copy of the double3x2 that has been component-wise divided by the given scalar value.
inline double3x2 operator/( const double3x2& lhs, const double rhs );

/// \relates double3x2
/// \brief Divides each component by the given scalar value.
inline double3x2 operator/=( double3x2& lhs, const double rhs );

/// \relates double3x2
/// \brief Returns a copy of the double3x2 that has been component-wise divided by the corresponding component of the right-hand double3x2.
inline double3x2 operator/( const double3x2& lhs, const double3x2& rhs );

/// \relates double3x2
/// \brief Prefix increment operator.  Adds one to each component of the given double3x2 before evaluation.
inline double3x2& operator++( double3x2& lhs );

/// \relates double3x2
/// \brief Postfix increment operator.  Adds one to each component of the given double3x2 after evaluation.
inline double3x2& operator++( double3x2& lhs, const int );

/// \relates double3x2
/// \brief Prefix decrement operator.  Subtracts one from each component of the given double3x2 before evaluation.
inline double3x2& operator--( double3x2& lhs );

/// \relates double3x2
/// \brief Postfix decrement operator.  Subtracts one from each component of the given double3x2 after evaluation.
inline double3x2& operator--( double3x2& lhs, const int );

/// \relates double3x2
/// \brief Returns a bool3x2 where each component is true if the component of the left-hand type is less than the corresponding right-hand type component.
inline bool3x2 operator<( const double3x2& lhs, const double3x2& rhs );

/// \relates double3x2
/// \brief Returns a bool3x2 where each component is true if the component of the left-hand type is less than or equal to the corresponding right-hand type component.
inline bool3x2 operator<=( const double3x2& lhs, const double3x2& rhs );

/// \relates double3x2
/// \brief Returns a bool3x2 where each component is true if the component of the left-hand type is greater than the corresponding right-hand type component.
inline bool3x2 operator>( const double3x2& lhs, const double3x2& rhs );

/// \relates double3x2
/// \brief Returns a bool3x2 where each component is true if the component of the left-hand type is greater than or equal to the corresponding right-hand type component.
inline bool3x2 operator>=( const double3x2& lhs, const double3x2& rhs );


// double3x3
/// \relates double3x3
/// \brief Returns a copy of the double3x3 that has been component-wise added by the given scalar value.
inline double3x3 operator+( const double3x3& lhs, const double rhs );

/// \relates double3x3
/// \brief Adds each component by the given scalar value.
inline double3x3 operator+=( double3x3& lhs, const double rhs );

/// \relates double3x3
/// \brief Returns a copy of the double3x3 that has been component-wise added by the corresponding component of the right-hand double3x3.
inline double3x3 operator+( const double3x3& lhs, const double3x3& rhs );

/// \relates double3x3
/// \brief Adds each component of the double3x3 by the corresponding component of the right-hand double3x3.
inline double3x3 operator+=( double3x3& lhs, const double3x3& rhs );

/// \relates double3x3
/// \brief Returns a copy of the double3x3 that has been component-wise subtracted by the given scalar value.
inline double3x3 operator-( const double3x3& lhs, const double rhs );

/// \relates double3x3
/// \brief Subtracts each component by the given scalar value.
inline double3x3 operator-=( double3x3& lhs, const double rhs );

/// \relates double3x3
/// \brief Returns a copy of the double3x3 that has been component-wise subtracted by the corresponding component of the right-hand double3x3.
inline double3x3 operator-( const double3x3& lhs, const double3x3& rhs );

/// \relates double3x3
/// \brief Subtracts each component of the double3x3 by the corresponding component of the right-hand double3x3.
inline double3x3 operator-=( double3x3& lhs, const double3x3& rhs );

/// \relates double3x3
/// \brief Returns a copy of the double3x3 that has been component-wise multiplied by the given scalar value.
inline double3x3 operator*( const double3x3& lhs, const double rhs );

/// \relates double3x3
/// \brief Multiplies each component by the given scalar value.
inline double3x3 operator*=( double3x3& lhs, const double rhs );

/// \relates double3x3
/// \brief Returns a copy of the matrix where each row of the left-hand matrix has been dot-producted by the corresponding column of the right-hand matrix.
inline double3x3 operator*( const double3x3& lhs, const double3x3& rhs );

/// \relates double3x3
/// \brief Dot products each row of the left-hand matrix with the corresponding column of the right-hand matrix.
inline double3x3 operator*=( double3x3& lhs, const double3x3& rhs );

/// \relates double3x3
/// \brief Returns a copy of the double3x3 that has been component-wise divided by the given scalar value.
inline double3x3 operator/( const double3x3& lhs, const double rhs );

/// \relates double3x3
/// \brief Divides each component by the given scalar value.
inline double3x3 operator/=( double3x3& lhs, const double rhs );

/// \relates double3x3
/// \brief Returns a copy of the matrix where the left-hand matrix has been mathematically multiplied by the inverse of the right-hand matrix.
inline double3x3 operator/( const double3x3& lhs, const double3x3& rhs );

/// \relates double3x3
/// \brief Multiplies the left-hand matrix by the right-hand matrix (dot product row/col style).
inline double3x3 operator/=( double3x3& lhs, const double3x3& rhs );

/// \relates double3x3
/// \brief Prefix increment operator.  Adds one to each component of the given double3x3 before evaluation.
inline double3x3& operator++( double3x3& lhs );

/// \relates double3x3
/// \brief Postfix increment operator.  Adds one to each component of the given double3x3 after evaluation.
inline double3x3& operator++( double3x3& lhs, const int );

/// \relates double3x3
/// \brief Prefix decrement operator.  Subtracts one from each component of the given double3x3 before evaluation.
inline double3x3& operator--( double3x3& lhs );

/// \relates double3x3
/// \brief Postfix decrement operator.  Subtracts one from each component of the given double3x3 after evaluation.
inline double3x3& operator--( double3x3& lhs, const int );

/// \relates double3x3
/// \brief Returns a bool3x3 where each component is true if the component of the left-hand type is less than the corresponding right-hand type component.
inline bool3x3 operator<( const double3x3& lhs, const double3x3& rhs );

/// \relates double3x3
/// \brief Returns a bool3x3 where each component is true if the component of the left-hand type is less than or equal to the corresponding right-hand type component.
inline bool3x3 operator<=( const double3x3& lhs, const double3x3& rhs );

/// \relates double3x3
/// \brief Returns a bool3x3 where each component is true if the component of the left-hand type is greater than the corresponding right-hand type component.
inline bool3x3 operator>( const double3x3& lhs, const double3x3& rhs );

/// \relates double3x3
/// \brief Returns a bool3x3 where each component is true if the component of the left-hand type is greater than or equal to the corresponding right-hand type component.
inline bool3x3 operator>=( const double3x3& lhs, const double3x3& rhs );


// double3x4
/// \relates double3x4
/// \brief Returns a copy of the double3x4 that has been component-wise added by the given scalar value.
inline double3x4 operator+( const double3x4& lhs, const double rhs );

/// \relates double3x4
/// \brief Adds each component by the given scalar value.
inline double3x4 operator+=( double3x4& lhs, const double rhs );

/// \relates double3x4
/// \brief Returns a copy of the double3x4 that has been component-wise added by the corresponding component of the right-hand double3x4.
inline double3x4 operator+( const double3x4& lhs, const double3x4& rhs );

/// \relates double3x4
/// \brief Adds each component of the double3x4 by the corresponding component of the right-hand double3x4.
inline double3x4 operator+=( double3x4& lhs, const double3x4& rhs );

/// \relates double3x4
/// \brief Returns a copy of the double3x4 that has been component-wise subtracted by the given scalar value.
inline double3x4 operator-( const double3x4& lhs, const double rhs );

/// \relates double3x4
/// \brief Subtracts each component by the given scalar value.
inline double3x4 operator-=( double3x4& lhs, const double rhs );

/// \relates double3x4
/// \brief Returns a copy of the double3x4 that has been component-wise subtracted by the corresponding component of the right-hand double3x4.
inline double3x4 operator-( const double3x4& lhs, const double3x4& rhs );

/// \relates double3x4
/// \brief Subtracts each component of the double3x4 by the corresponding component of the right-hand double3x4.
inline double3x4 operator-=( double3x4& lhs, const double3x4& rhs );

/// \relates double3x4
/// \brief Returns a copy of the double3x4 that has been component-wise multiplied by the given scalar value.
inline double3x4 operator*( const double3x4& lhs, const double rhs );

/// \relates double3x4
/// \brief Multiplies each component by the given scalar value.
inline double3x4 operator*=( double3x4& lhs, const double rhs );

/// \relates double3x4
/// \brief Returns a copy of the matrix where each row of the left-hand matrix has been dot-producted by the corresponding column of the right-hand matrix.
inline double3x3 operator*( const double3x4& lhs, const double4x3& rhs );

/// \relates double3x4
/// \brief Dot products each row of the left-hand matrix with the corresponding column of the right-hand matrix.
inline double3x3 operator*=( double3x4& lhs, const double4x3& rhs );

/// \relates double3x4
/// \brief Returns a copy of the double3x4 that has been component-wise divided by the given scalar value.
inline double3x4 operator/( const double3x4& lhs, const double rhs );

/// \relates double3x4
/// \brief Divides each component by the given scalar value.
inline double3x4 operator/=( double3x4& lhs, const double rhs );

/// \relates double3x4
/// \brief Returns a copy of the double3x4 that has been component-wise divided by the corresponding component of the right-hand double3x4.
inline double3x4 operator/( const double3x4& lhs, const double3x4& rhs );

/// \relates double3x4
/// \brief Prefix increment operator.  Adds one to each component of the given double3x4 before evaluation.
inline double3x4& operator++( double3x4& lhs );

/// \relates double3x4
/// \brief Postfix increment operator.  Adds one to each component of the given double3x4 after evaluation.
inline double3x4& operator++( double3x4& lhs, const int );

/// \relates double3x4
/// \brief Prefix decrement operator.  Subtracts one from each component of the given double3x4 before evaluation.
inline double3x4& operator--( double3x4& lhs );

/// \relates double3x4
/// \brief Postfix decrement operator.  Subtracts one from each component of the given double3x4 after evaluation.
inline double3x4& operator--( double3x4& lhs, const int );

/// \relates double3x4
/// \brief Returns a bool3x4 where each component is true if the component of the left-hand type is less than the corresponding right-hand type component.
inline bool3x4 operator<( const double3x4& lhs, const double3x4& rhs );

/// \relates double3x4
/// \brief Returns a bool3x4 where each component is true if the component of the left-hand type is less than or equal to the corresponding right-hand type component.
inline bool3x4 operator<=( const double3x4& lhs, const double3x4& rhs );

/// \relates double3x4
/// \brief Returns a bool3x4 where each component is true if the component of the left-hand type is greater than the corresponding right-hand type component.
inline bool3x4 operator>( const double3x4& lhs, const double3x4& rhs );

/// \relates double3x4
/// \brief Returns a bool3x4 where each component is true if the component of the left-hand type is greater than or equal to the corresponding right-hand type component.
inline bool3x4 operator>=( const double3x4& lhs, const double3x4& rhs );


// double4x2
/// \relates double4x2
/// \brief Returns a copy of the double4x2 that has been component-wise added by the given scalar value.
inline double4x2 operator+( const double4x2& lhs, const double rhs );

/// \relates double4x2
/// \brief Adds each component by the given scalar value.
inline double4x2 operator+=( double4x2& lhs, const double rhs );

/// \relates double4x2
/// \brief Returns a copy of the double4x2 that has been component-wise added by the corresponding component of the right-hand double4x2.
inline double4x2 operator+( const double4x2& lhs, const double4x2& rhs );

/// \relates double4x2
/// \brief Adds each component of the double4x2 by the corresponding component of the right-hand double4x2.
inline double4x2 operator+=( double4x2& lhs, const double4x2& rhs );

/// \relates double4x2
/// \brief Returns a copy of the double4x2 that has been component-wise subtracted by the given scalar value.
inline double4x2 operator-( const double4x2& lhs, const double rhs );

/// \relates double4x2
/// \brief Subtracts each component by the given scalar value.
inline double4x2 operator-=( double4x2& lhs, const double rhs );

/// \relates double4x2
/// \brief Returns a copy of the double4x2 that has been component-wise subtracted by the corresponding component of the right-hand double4x2.
inline double4x2 operator-( const double4x2& lhs, const double4x2& rhs );

/// \relates double4x2
/// \brief Subtracts each component of the double4x2 by the corresponding component of the right-hand double4x2.
inline double4x2 operator-=( double4x2& lhs, const double4x2& rhs );

/// \relates double4x2
/// \brief Returns a copy of the double4x2 that has been component-wise multiplied by the given scalar value.
inline double4x2 operator*( const double4x2& lhs, const double rhs );

/// \relates double4x2
/// \brief Multiplies each component by the given scalar value.
inline double4x2 operator*=( double4x2& lhs, const double rhs );

/// \relates double4x2
/// \brief Returns a copy of the matrix where each row of the left-hand matrix has been dot-producted by the corresponding column of the right-hand matrix.
inline double4x4 operator*( const double4x2& lhs, const double2x4& rhs );

/// \relates double4x2
/// \brief Dot products each row of the left-hand matrix with the corresponding column of the right-hand matrix.
inline double4x4 operator*=( double4x2& lhs, const double2x4& rhs );

/// \relates double4x2
/// \brief Returns a copy of the double4x2 that has been component-wise divided by the given scalar value.
inline double4x2 operator/( const double4x2& lhs, const double rhs );

/// \relates double4x2
/// \brief Divides each component by the given scalar value.
inline double4x2 operator/=( double4x2& lhs, const double rhs );

/// \relates double4x2
/// \brief Returns a copy of the double4x2 that has been component-wise divided by the corresponding component of the right-hand double4x2.
inline double4x2 operator/( const double4x2& lhs, const double4x2& rhs );

/// \relates double4x2
/// \brief Prefix increment operator.  Adds one to each component of the given double4x2 before evaluation.
inline double4x2& operator++( double4x2& lhs );

/// \relates double4x2
/// \brief Postfix increment operator.  Adds one to each component of the given double4x2 after evaluation.
inline double4x2& operator++( double4x2& lhs, const int );

/// \relates double4x2
/// \brief Prefix decrement operator.  Subtracts one from each component of the given double4x2 before evaluation.
inline double4x2& operator--( double4x2& lhs );

/// \relates double4x2
/// \brief Postfix decrement operator.  Subtracts one from each component of the given double4x2 after evaluation.
inline double4x2& operator--( double4x2& lhs, const int );

/// \relates double4x2
/// \brief Returns a bool4x2 where each component is true if the component of the left-hand type is less than the corresponding right-hand type component.
inline bool4x2 operator<( const double4x2& lhs, const double4x2& rhs );

/// \relates double4x2
/// \brief Returns a bool4x2 where each component is true if the component of the left-hand type is less than or equal to the corresponding right-hand type component.
inline bool4x2 operator<=( const double4x2& lhs, const double4x2& rhs );

/// \relates double4x2
/// \brief Returns a bool4x2 where each component is true if the component of the left-hand type is greater than the corresponding right-hand type component.
inline bool4x2 operator>( const double4x2& lhs, const double4x2& rhs );

/// \relates double4x2
/// \brief Returns a bool4x2 where each component is true if the component of the left-hand type is greater than or equal to the corresponding right-hand type component.
inline bool4x2 operator>=( const double4x2& lhs, const double4x2& rhs );


// double4x3
/// \relates double4x3
/// \brief Returns a copy of the double4x3 that has been component-wise added by the given scalar value.
inline double4x3 operator+( const double4x3& lhs, const double rhs );

/// \relates double4x3
/// \brief Adds each component by the given scalar value.
inline double4x3 operator+=( double4x3& lhs, const double rhs );

/// \relates double4x3
/// \brief Returns a copy of the double4x3 that has been component-wise added by the corresponding component of the right-hand double4x3.
inline double4x3 operator+( const double4x3& lhs, const double4x3& rhs );

/// \relates double4x3
/// \brief Adds each component of the double4x3 by the corresponding component of the right-hand double4x3.
inline double4x3 operator+=( double4x3& lhs, const double4x3& rhs );

/// \relates double4x3
/// \brief Returns a copy of the double4x3 that has been component-wise subtracted by the given scalar value.
inline double4x3 operator-( const double4x3& lhs, const double rhs );

/// \relates double4x3
/// \brief Subtracts each component by the given scalar value.
inline double4x3 operator-=( double4x3& lhs, const double rhs );

/// \relates double4x3
/// \brief Returns a copy of the double4x3 that has been component-wise subtracted by the corresponding component of the right-hand double4x3.
inline double4x3 operator-( const double4x3& lhs, const double4x3& rhs );

/// \relates double4x3
/// \brief Subtracts each component of the double4x3 by the corresponding component of the right-hand double4x3.
inline double4x3 operator-=( double4x3& lhs, const double4x3& rhs );

/// \relates double4x3
/// \brief Returns a copy of the double4x3 that has been component-wise multiplied by the given scalar value.
inline double4x3 operator*( const double4x3& lhs, const double rhs );

/// \relates double4x3
/// \brief Multiplies each component by the given scalar value.
inline double4x3 operator*=( double4x3& lhs, const double rhs );

/// \relates double4x3
/// \brief Returns a copy of the matrix where each row of the left-hand matrix has been dot-producted by the corresponding column of the right-hand matrix.
inline double4x4 operator*( const double4x3& lhs, const double3x4& rhs );

/// \relates double4x3
/// \brief Dot products each row of the left-hand matrix with the corresponding column of the right-hand matrix.
inline double4x4 operator*=( double4x3& lhs, const double3x4& rhs );

/// \relates double4x3
/// \brief Returns a copy of the double4x3 that has been component-wise divided by the given scalar value.
inline double4x3 operator/( const double4x3& lhs, const double rhs );

/// \relates double4x3
/// \brief Divides each component by the given scalar value.
inline double4x3 operator/=( double4x3& lhs, const double rhs );

/// \relates double4x3
/// \brief Returns a copy of the double4x3 that has been component-wise divided by the corresponding component of the right-hand double4x3.
inline double4x3 operator/( const double4x3& lhs, const double4x3& rhs );

/// \relates double4x3
/// \brief Prefix increment operator.  Adds one to each component of the given double4x3 before evaluation.
inline double4x3& operator++( double4x3& lhs );

/// \relates double4x3
/// \brief Postfix increment operator.  Adds one to each component of the given double4x3 after evaluation.
inline double4x3& operator++( double4x3& lhs, const int );

/// \relates double4x3
/// \brief Prefix decrement operator.  Subtracts one from each component of the given double4x3 before evaluation.
inline double4x3& operator--( double4x3& lhs );

/// \relates double4x3
/// \brief Postfix decrement operator.  Subtracts one from each component of the given double4x3 after evaluation.
inline double4x3& operator--( double4x3& lhs, const int );

/// \relates double4x3
/// \brief Returns a bool4x3 where each component is true if the component of the left-hand type is less than the corresponding right-hand type component.
inline bool4x3 operator<( const double4x3& lhs, const double4x3& rhs );

/// \relates double4x3
/// \brief Returns a bool4x3 where each component is true if the component of the left-hand type is less than or equal to the corresponding right-hand type component.
inline bool4x3 operator<=( const double4x3& lhs, const double4x3& rhs );

/// \relates double4x3
/// \brief Returns a bool4x3 where each component is true if the component of the left-hand type is greater than the corresponding right-hand type component.
inline bool4x3 operator>( const double4x3& lhs, const double4x3& rhs );

/// \relates double4x3
/// \brief Returns a bool4x3 where each component is true if the component of the left-hand type is greater than or equal to the corresponding right-hand type component.
inline bool4x3 operator>=( const double4x3& lhs, const double4x3& rhs );


// double4x4
/// \relates double4x4
/// \brief Returns a copy of the double4x4 that has been component-wise added by the given scalar value.
inline double4x4 operator+( const double4x4& lhs, const double rhs );

/// \relates double4x4
/// \brief Adds each component by the given scalar value.
inline double4x4 operator+=( double4x4& lhs, const double rhs );

/// \relates double4x4
/// \brief Returns a copy of the double4x4 that has been component-wise added by the corresponding component of the right-hand double4x4.
inline double4x4 operator+( const double4x4& lhs, const double4x4& rhs );

/// \relates double4x4
/// \brief Adds each component of the double4x4 by the corresponding component of the right-hand double4x4.
inline double4x4 operator+=( double4x4& lhs, const double4x4& rhs );

/// \relates double4x4
/// \brief Returns a copy of the double4x4 that has been component-wise subtracted by the given scalar value.
inline double4x4 operator-( const double4x4& lhs, const double rhs );

/// \relates double4x4
/// \brief Subtracts each component by the given scalar value.
inline double4x4 operator-=( double4x4& lhs, const double rhs );

/// \relates double4x4
/// \brief Returns a copy of the double4x4 that has been component-wise subtracted by the corresponding component of the right-hand double4x4.
inline double4x4 operator-( const double4x4& lhs, const double4x4& rhs );

/// \relates double4x4
/// \brief Subtracts each component of the double4x4 by the corresponding component of the right-hand double4x4.
inline double4x4 operator-=( double4x4& lhs, const double4x4& rhs );

/// \relates double4x4
/// \brief Returns a copy of the double4x4 that has been component-wise multiplied by the given scalar value.
inline double4x4 operator*( const double4x4& lhs, const double rhs );

/// \relates double4x4
/// \brief Multiplies each component by the given scalar value.
inline double4x4 operator*=( double4x4& lhs, const double rhs );

/// \relates double4x4
/// \brief Returns a copy of the matrix where each row of the left-hand matrix has been dot-producted by the corresponding column of the right-hand matrix.
inline double4x4 operator*( const double4x4& lhs, const double4x4& rhs );

/// \relates double4x4
/// \brief Dot products each row of the left-hand matrix with the corresponding column of the right-hand matrix.
inline double4x4 operator*=( double4x4& lhs, const double4x4& rhs );

/// \relates double4x4
/// \brief Returns a copy of the double4x4 that has been component-wise divided by the given scalar value.
inline double4x4 operator/( const double4x4& lhs, const double rhs );

/// \relates double4x4
/// \brief Divides each component by the given scalar value.
inline double4x4 operator/=( double4x4& lhs, const double rhs );

/// \relates double4x4
/// \brief Returns a copy of the matrix where the left-hand matrix has been mathematically multiplied by the inverse of the right-hand matrix.
inline double4x4 operator/( const double4x4& lhs, const double4x4& rhs );

/// \relates double4x4
/// \brief Multiplies the left-hand matrix by the right-hand matrix (dot product row/col style).
inline double4x4 operator/=( double4x4& lhs, const double4x4& rhs );

/// \relates double4x4
/// \brief Prefix increment operator.  Adds one to each component of the given double4x4 before evaluation.
inline double4x4& operator++( double4x4& lhs );

/// \relates double4x4
/// \brief Postfix increment operator.  Adds one to each component of the given double4x4 after evaluation.
inline double4x4& operator++( double4x4& lhs, const int );

/// \relates double4x4
/// \brief Prefix decrement operator.  Subtracts one from each component of the given double4x4 before evaluation.
inline double4x4& operator--( double4x4& lhs );

/// \relates double4x4
/// \brief Postfix decrement operator.  Subtracts one from each component of the given double4x4 after evaluation.
inline double4x4& operator--( double4x4& lhs, const int );

/// \relates double4x4
/// \brief Returns a bool4x4 where each component is true if the component of the left-hand type is less than the corresponding right-hand type component.
inline bool4x4 operator<( const double4x4& lhs, const double4x4& rhs );

/// \relates double4x4
/// \brief Returns a bool4x4 where each component is true if the component of the left-hand type is less than or equal to the corresponding right-hand type component.
inline bool4x4 operator<=( const double4x4& lhs, const double4x4& rhs );

/// \relates double4x4
/// \brief Returns a bool4x4 where each component is true if the component of the left-hand type is greater than the corresponding right-hand type component.
inline bool4x4 operator>( const double4x4& lhs, const double4x4& rhs );

/// \relates double4x4
/// \brief Returns a bool4x4 where each component is true if the component of the left-hand type is greater than or equal to the corresponding right-hand type component.
inline bool4x4 operator>=( const double4x4& lhs, const double4x4& rhs );


#include "hlml_operators_matrix.inl"

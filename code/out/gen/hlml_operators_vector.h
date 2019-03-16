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

#include "int2.h"
#include "int3.h"
#include "int4.h"
#include "uint2.h"
#include "uint3.h"
#include "uint4.h"
#include "float2.h"
#include "float3.h"
#include "float4.h"
#include "double2.h"
#include "double3.h"
#include "double4.h"

// int2
/// \relates int2
/// \brief Returns a copy that has been component-wise added by the given scalar value.
inline int2 operator+( const int2& lhs, const int32_t rhs );

/// \relates int2
/// \brief Adds each component by the given scalar value.
inline int2 operator+=( int2& lhs, const int32_t rhs );

/// \relates int2.
inline int2 operator+( const int2& lhs, const int2& rhs );

/// \relates int2.
inline int2 operator+=( int2& lhs, const int2& rhs );

/// \relates int2
/// \brief Returns a copy that has been component-wise subtracted by the given scalar value.
inline int2 operator-( const int2& lhs, const int32_t rhs );

/// \relates int2
/// \brief Subtracts each component by the given scalar value.
inline int2 operator-=( int2& lhs, const int32_t rhs );

/// \relates int2.
inline int2 operator-( const int2& lhs, const int2& rhs );

/// \relates int2.
inline int2 operator-=( int2& lhs, const int2& rhs );

/// \relates int2
/// \brief Returns a copy that has been component-wise multiplied by the given scalar value.
inline int2 operator*( const int2& lhs, const int32_t rhs );

/// \relates int2
/// \brief Multiplies each component by the given scalar value.
inline int2 operator*=( int2& lhs, const int32_t rhs );

/// \relates int2.
inline int2 operator*( const int2& lhs, const int2& rhs );

/// \relates int2.
inline int2 operator*=( int2& lhs, const int2& rhs );

/// \relates int2
/// \brief Returns a copy that has been component-wise divided by the given scalar value.
inline int2 operator/( const int2& lhs, const int32_t rhs );

/// \relates int2
/// \brief Divides each component by the given scalar value.
inline int2 operator/=( int2& lhs, const int32_t rhs );

/// \relates int2.
inline int2 operator/( const int2& lhs, const int2& rhs );

/// \relates int2.
inline int2 operator/=( int2& lhs, const int2& rhs );

/// \relates int2
/// \brief Returns a bool2 where each component is true if the component of the left-hand type is less than the corresponding right-hand type component.
inline bool2 operator<( const int2& lhs, const int2& rhs );

/// \relates int2
/// \brief Returns a bool2 where each component is true if the component of the left-hand type is less than or equal to the corresponding right-hand type component.
inline bool2 operator<=( const int2& lhs, const int2& rhs );

/// \relates int2
/// \brief Returns a bool2 where each component is true if the component of the left-hand type is greater than the corresponding right-hand type component.
inline bool2 operator>( const int2& lhs, const int2& rhs );

/// \relates int2
/// \brief Returns a bool2 where each component is true if the component of the left-hand type is greater than or equal to the corresponding right-hand type component.
inline bool2 operator>=( const int2& lhs, const int2& rhs );

/// \relates int2
/// \brief Returns a copy of the int2 where each component has been bitwise AND'd against the given scalar value.
inline int2 operator&( const int2& lhs, const int32_t& rhs );

/// \relates int2
/// \brief Performs a bitwise AND on the given left-hand int2 against the given scalar value.
inline int2 operator&=( int2& lhs, const int32_t& rhs );

/// \relates int2
/// \brief Returns a copy of the int2 where each component of the left-hand int2 has been bitwise AND'd against the corresponding component of the right-hand side int2.
inline int2 operator&( const int2& lhs, const int2& rhs );

/// \relates int2
/// \brief Performs a bitwise AND on the given left-hand int2 against the corresponding component of the given right-hand int2.
inline int2 operator&=( int2& lhs, const int2& rhs );

/// \relates int2
/// \brief Returns a copy of the int2 where each component has been bitwise OR'd against the given scalar value.
inline int2 operator|( const int2& lhs, const int32_t& rhs );

/// \relates int2
/// \brief Performs a bitwise OR on the given left-hand int2 against the given scalar value.
inline int2 operator|=( int2& lhs, const int32_t& rhs );

/// \relates int2
/// \brief Returns a copy of the int2 where each component of the left-hand int2 has been bitwise OR'd against the corresponding component of the right-hand side int2.
inline int2 operator|( const int2& lhs, const int2& rhs );

/// \relates int2
/// \brief Performs a bitwise OR on the given left-hand int2 against the corresponding component of the given right-hand int2.
inline int2 operator|=( int2& lhs, const int2& rhs );

/// \relates int2
/// \brief Returns a copy of the int2 where each component has been bitwise XOR'd against the given scalar value.
inline int2 operator^( const int2& lhs, const int32_t& rhs );

/// \relates int2
/// \brief Performs a bitwise XOR on the given left-hand int2 against the given scalar value.
inline int2 operator^=( int2& lhs, const int32_t& rhs );

/// \relates int2
/// \brief Returns a copy of the int2 where each component of the left-hand int2 has been bitwise XOR'd against the corresponding component of the right-hand side int2.
inline int2 operator^( const int2& lhs, const int2& rhs );

/// \relates int2
/// \brief Performs a bitwise XOR on the given left-hand int2 against the corresponding component of the given right-hand int2.
inline int2 operator^=( int2& lhs, const int2& rhs );

/// \relates int2
/// \brief Returns a copy of the int2 where each component has been bitwise left-shifted by the given scalar value.
inline int2 operator<<( const int2& lhs, const int32_t& rhs );

/// \relates int2
/// \brief Performs a left bitshift on the given left-hand int2 by the given scalar value.
inline int2 operator<<=( int2& lhs, const int32_t& rhs );

/// \relates int2
/// \brief Returns a copy of the int2 where each component of the left-hand int2 has been bitwise left-shifted by the corresponding component of the right-hand side int2.
inline int2 operator<<( const int2& lhs, const int2& rhs );

/// \relates int2
/// \brief Performs a left bitshift on the given left-hand int2 by the corresponding component of the given right-hand int2.
inline int2 operator<<=( int2& lhs, const int2& rhs );

/// \relates int2
/// \brief Returns a copy of the int2 where each component has been bitwise right-shifted by the given scalar value.
inline int2 operator>>( const int2& lhs, const int32_t& rhs );

/// \relates int2
/// \brief Performs a right bitshift on the given left-hand int2 by the given scalar value.
inline int2 operator>>=( int2& lhs, const int32_t& rhs );

/// \relates int2
/// \brief Returns a copy of the int2 where each component of the left-hand int2 has been bitwise right-shifted by the corresponding component of the right-hand side int2.
inline int2 operator>>( const int2& lhs, const int2& rhs );

/// \relates int2
/// \brief Performs a right bitshift on the given left-hand int2 by the corresponding component of the given right-hand int2.
inline int2 operator>>=( int2& lhs, const int2& rhs );

/// \relates int2
/// \brief Performs a unary bitwise operation on all components of the given int2.
inline int2 operator~( const int2& lhs );

// int3
/// \relates int3
/// \brief Returns a copy that has been component-wise added by the given scalar value.
inline int3 operator+( const int3& lhs, const int32_t rhs );

/// \relates int3
/// \brief Adds each component by the given scalar value.
inline int3 operator+=( int3& lhs, const int32_t rhs );

/// \relates int3.
inline int3 operator+( const int3& lhs, const int3& rhs );

/// \relates int3.
inline int3 operator+=( int3& lhs, const int3& rhs );

/// \relates int3
/// \brief Returns a copy that has been component-wise subtracted by the given scalar value.
inline int3 operator-( const int3& lhs, const int32_t rhs );

/// \relates int3
/// \brief Subtracts each component by the given scalar value.
inline int3 operator-=( int3& lhs, const int32_t rhs );

/// \relates int3.
inline int3 operator-( const int3& lhs, const int3& rhs );

/// \relates int3.
inline int3 operator-=( int3& lhs, const int3& rhs );

/// \relates int3
/// \brief Returns a copy that has been component-wise multiplied by the given scalar value.
inline int3 operator*( const int3& lhs, const int32_t rhs );

/// \relates int3
/// \brief Multiplies each component by the given scalar value.
inline int3 operator*=( int3& lhs, const int32_t rhs );

/// \relates int3.
inline int3 operator*( const int3& lhs, const int3& rhs );

/// \relates int3.
inline int3 operator*=( int3& lhs, const int3& rhs );

/// \relates int3
/// \brief Returns a copy that has been component-wise divided by the given scalar value.
inline int3 operator/( const int3& lhs, const int32_t rhs );

/// \relates int3
/// \brief Divides each component by the given scalar value.
inline int3 operator/=( int3& lhs, const int32_t rhs );

/// \relates int3.
inline int3 operator/( const int3& lhs, const int3& rhs );

/// \relates int3.
inline int3 operator/=( int3& lhs, const int3& rhs );

/// \relates int3
/// \brief Returns a bool3 where each component is true if the component of the left-hand type is less than the corresponding right-hand type component.
inline bool3 operator<( const int3& lhs, const int3& rhs );

/// \relates int3
/// \brief Returns a bool3 where each component is true if the component of the left-hand type is less than or equal to the corresponding right-hand type component.
inline bool3 operator<=( const int3& lhs, const int3& rhs );

/// \relates int3
/// \brief Returns a bool3 where each component is true if the component of the left-hand type is greater than the corresponding right-hand type component.
inline bool3 operator>( const int3& lhs, const int3& rhs );

/// \relates int3
/// \brief Returns a bool3 where each component is true if the component of the left-hand type is greater than or equal to the corresponding right-hand type component.
inline bool3 operator>=( const int3& lhs, const int3& rhs );

/// \relates int3
/// \brief Returns a copy of the int3 where each component has been bitwise AND'd against the given scalar value.
inline int3 operator&( const int3& lhs, const int32_t& rhs );

/// \relates int3
/// \brief Performs a bitwise AND on the given left-hand int3 against the given scalar value.
inline int3 operator&=( int3& lhs, const int32_t& rhs );

/// \relates int3
/// \brief Returns a copy of the int3 where each component of the left-hand int3 has been bitwise AND'd against the corresponding component of the right-hand side int3.
inline int3 operator&( const int3& lhs, const int3& rhs );

/// \relates int3
/// \brief Performs a bitwise AND on the given left-hand int3 against the corresponding component of the given right-hand int3.
inline int3 operator&=( int3& lhs, const int3& rhs );

/// \relates int3
/// \brief Returns a copy of the int3 where each component has been bitwise OR'd against the given scalar value.
inline int3 operator|( const int3& lhs, const int32_t& rhs );

/// \relates int3
/// \brief Performs a bitwise OR on the given left-hand int3 against the given scalar value.
inline int3 operator|=( int3& lhs, const int32_t& rhs );

/// \relates int3
/// \brief Returns a copy of the int3 where each component of the left-hand int3 has been bitwise OR'd against the corresponding component of the right-hand side int3.
inline int3 operator|( const int3& lhs, const int3& rhs );

/// \relates int3
/// \brief Performs a bitwise OR on the given left-hand int3 against the corresponding component of the given right-hand int3.
inline int3 operator|=( int3& lhs, const int3& rhs );

/// \relates int3
/// \brief Returns a copy of the int3 where each component has been bitwise XOR'd against the given scalar value.
inline int3 operator^( const int3& lhs, const int32_t& rhs );

/// \relates int3
/// \brief Performs a bitwise XOR on the given left-hand int3 against the given scalar value.
inline int3 operator^=( int3& lhs, const int32_t& rhs );

/// \relates int3
/// \brief Returns a copy of the int3 where each component of the left-hand int3 has been bitwise XOR'd against the corresponding component of the right-hand side int3.
inline int3 operator^( const int3& lhs, const int3& rhs );

/// \relates int3
/// \brief Performs a bitwise XOR on the given left-hand int3 against the corresponding component of the given right-hand int3.
inline int3 operator^=( int3& lhs, const int3& rhs );

/// \relates int3
/// \brief Returns a copy of the int3 where each component has been bitwise left-shifted by the given scalar value.
inline int3 operator<<( const int3& lhs, const int32_t& rhs );

/// \relates int3
/// \brief Performs a left bitshift on the given left-hand int3 by the given scalar value.
inline int3 operator<<=( int3& lhs, const int32_t& rhs );

/// \relates int3
/// \brief Returns a copy of the int3 where each component of the left-hand int3 has been bitwise left-shifted by the corresponding component of the right-hand side int3.
inline int3 operator<<( const int3& lhs, const int3& rhs );

/// \relates int3
/// \brief Performs a left bitshift on the given left-hand int3 by the corresponding component of the given right-hand int3.
inline int3 operator<<=( int3& lhs, const int3& rhs );

/// \relates int3
/// \brief Returns a copy of the int3 where each component has been bitwise right-shifted by the given scalar value.
inline int3 operator>>( const int3& lhs, const int32_t& rhs );

/// \relates int3
/// \brief Performs a right bitshift on the given left-hand int3 by the given scalar value.
inline int3 operator>>=( int3& lhs, const int32_t& rhs );

/// \relates int3
/// \brief Returns a copy of the int3 where each component of the left-hand int3 has been bitwise right-shifted by the corresponding component of the right-hand side int3.
inline int3 operator>>( const int3& lhs, const int3& rhs );

/// \relates int3
/// \brief Performs a right bitshift on the given left-hand int3 by the corresponding component of the given right-hand int3.
inline int3 operator>>=( int3& lhs, const int3& rhs );

/// \relates int3
/// \brief Performs a unary bitwise operation on all components of the given int3.
inline int3 operator~( const int3& lhs );

// int4
/// \relates int4
/// \brief Returns a copy that has been component-wise added by the given scalar value.
inline int4 operator+( const int4& lhs, const int32_t rhs );

/// \relates int4
/// \brief Adds each component by the given scalar value.
inline int4 operator+=( int4& lhs, const int32_t rhs );

/// \relates int4.
inline int4 operator+( const int4& lhs, const int4& rhs );

/// \relates int4.
inline int4 operator+=( int4& lhs, const int4& rhs );

/// \relates int4
/// \brief Returns a copy that has been component-wise subtracted by the given scalar value.
inline int4 operator-( const int4& lhs, const int32_t rhs );

/// \relates int4
/// \brief Subtracts each component by the given scalar value.
inline int4 operator-=( int4& lhs, const int32_t rhs );

/// \relates int4.
inline int4 operator-( const int4& lhs, const int4& rhs );

/// \relates int4.
inline int4 operator-=( int4& lhs, const int4& rhs );

/// \relates int4
/// \brief Returns a copy that has been component-wise multiplied by the given scalar value.
inline int4 operator*( const int4& lhs, const int32_t rhs );

/// \relates int4
/// \brief Multiplies each component by the given scalar value.
inline int4 operator*=( int4& lhs, const int32_t rhs );

/// \relates int4.
inline int4 operator*( const int4& lhs, const int4& rhs );

/// \relates int4.
inline int4 operator*=( int4& lhs, const int4& rhs );

/// \relates int4
/// \brief Returns a copy that has been component-wise divided by the given scalar value.
inline int4 operator/( const int4& lhs, const int32_t rhs );

/// \relates int4
/// \brief Divides each component by the given scalar value.
inline int4 operator/=( int4& lhs, const int32_t rhs );

/// \relates int4.
inline int4 operator/( const int4& lhs, const int4& rhs );

/// \relates int4.
inline int4 operator/=( int4& lhs, const int4& rhs );

/// \relates int4
/// \brief Returns a bool4 where each component is true if the component of the left-hand type is less than the corresponding right-hand type component.
inline bool4 operator<( const int4& lhs, const int4& rhs );

/// \relates int4
/// \brief Returns a bool4 where each component is true if the component of the left-hand type is less than or equal to the corresponding right-hand type component.
inline bool4 operator<=( const int4& lhs, const int4& rhs );

/// \relates int4
/// \brief Returns a bool4 where each component is true if the component of the left-hand type is greater than the corresponding right-hand type component.
inline bool4 operator>( const int4& lhs, const int4& rhs );

/// \relates int4
/// \brief Returns a bool4 where each component is true if the component of the left-hand type is greater than or equal to the corresponding right-hand type component.
inline bool4 operator>=( const int4& lhs, const int4& rhs );

/// \relates int4
/// \brief Returns a copy of the int4 where each component has been bitwise AND'd against the given scalar value.
inline int4 operator&( const int4& lhs, const int32_t& rhs );

/// \relates int4
/// \brief Performs a bitwise AND on the given left-hand int4 against the given scalar value.
inline int4 operator&=( int4& lhs, const int32_t& rhs );

/// \relates int4
/// \brief Returns a copy of the int4 where each component of the left-hand int4 has been bitwise AND'd against the corresponding component of the right-hand side int4.
inline int4 operator&( const int4& lhs, const int4& rhs );

/// \relates int4
/// \brief Performs a bitwise AND on the given left-hand int4 against the corresponding component of the given right-hand int4.
inline int4 operator&=( int4& lhs, const int4& rhs );

/// \relates int4
/// \brief Returns a copy of the int4 where each component has been bitwise OR'd against the given scalar value.
inline int4 operator|( const int4& lhs, const int32_t& rhs );

/// \relates int4
/// \brief Performs a bitwise OR on the given left-hand int4 against the given scalar value.
inline int4 operator|=( int4& lhs, const int32_t& rhs );

/// \relates int4
/// \brief Returns a copy of the int4 where each component of the left-hand int4 has been bitwise OR'd against the corresponding component of the right-hand side int4.
inline int4 operator|( const int4& lhs, const int4& rhs );

/// \relates int4
/// \brief Performs a bitwise OR on the given left-hand int4 against the corresponding component of the given right-hand int4.
inline int4 operator|=( int4& lhs, const int4& rhs );

/// \relates int4
/// \brief Returns a copy of the int4 where each component has been bitwise XOR'd against the given scalar value.
inline int4 operator^( const int4& lhs, const int32_t& rhs );

/// \relates int4
/// \brief Performs a bitwise XOR on the given left-hand int4 against the given scalar value.
inline int4 operator^=( int4& lhs, const int32_t& rhs );

/// \relates int4
/// \brief Returns a copy of the int4 where each component of the left-hand int4 has been bitwise XOR'd against the corresponding component of the right-hand side int4.
inline int4 operator^( const int4& lhs, const int4& rhs );

/// \relates int4
/// \brief Performs a bitwise XOR on the given left-hand int4 against the corresponding component of the given right-hand int4.
inline int4 operator^=( int4& lhs, const int4& rhs );

/// \relates int4
/// \brief Returns a copy of the int4 where each component has been bitwise left-shifted by the given scalar value.
inline int4 operator<<( const int4& lhs, const int32_t& rhs );

/// \relates int4
/// \brief Performs a left bitshift on the given left-hand int4 by the given scalar value.
inline int4 operator<<=( int4& lhs, const int32_t& rhs );

/// \relates int4
/// \brief Returns a copy of the int4 where each component of the left-hand int4 has been bitwise left-shifted by the corresponding component of the right-hand side int4.
inline int4 operator<<( const int4& lhs, const int4& rhs );

/// \relates int4
/// \brief Performs a left bitshift on the given left-hand int4 by the corresponding component of the given right-hand int4.
inline int4 operator<<=( int4& lhs, const int4& rhs );

/// \relates int4
/// \brief Returns a copy of the int4 where each component has been bitwise right-shifted by the given scalar value.
inline int4 operator>>( const int4& lhs, const int32_t& rhs );

/// \relates int4
/// \brief Performs a right bitshift on the given left-hand int4 by the given scalar value.
inline int4 operator>>=( int4& lhs, const int32_t& rhs );

/// \relates int4
/// \brief Returns a copy of the int4 where each component of the left-hand int4 has been bitwise right-shifted by the corresponding component of the right-hand side int4.
inline int4 operator>>( const int4& lhs, const int4& rhs );

/// \relates int4
/// \brief Performs a right bitshift on the given left-hand int4 by the corresponding component of the given right-hand int4.
inline int4 operator>>=( int4& lhs, const int4& rhs );

/// \relates int4
/// \brief Performs a unary bitwise operation on all components of the given int4.
inline int4 operator~( const int4& lhs );

// uint2
/// \relates uint2
/// \brief Returns a copy that has been component-wise added by the given scalar value.
inline uint2 operator+( const uint2& lhs, const uint32_t rhs );

/// \relates uint2
/// \brief Adds each component by the given scalar value.
inline uint2 operator+=( uint2& lhs, const uint32_t rhs );

/// \relates uint2.
inline uint2 operator+( const uint2& lhs, const uint2& rhs );

/// \relates uint2.
inline uint2 operator+=( uint2& lhs, const uint2& rhs );

/// \relates uint2
/// \brief Returns a copy that has been component-wise subtracted by the given scalar value.
inline uint2 operator-( const uint2& lhs, const uint32_t rhs );

/// \relates uint2
/// \brief Subtracts each component by the given scalar value.
inline uint2 operator-=( uint2& lhs, const uint32_t rhs );

/// \relates uint2.
inline uint2 operator-( const uint2& lhs, const uint2& rhs );

/// \relates uint2.
inline uint2 operator-=( uint2& lhs, const uint2& rhs );

/// \relates uint2
/// \brief Returns a copy that has been component-wise multiplied by the given scalar value.
inline uint2 operator*( const uint2& lhs, const uint32_t rhs );

/// \relates uint2
/// \brief Multiplies each component by the given scalar value.
inline uint2 operator*=( uint2& lhs, const uint32_t rhs );

/// \relates uint2.
inline uint2 operator*( const uint2& lhs, const uint2& rhs );

/// \relates uint2.
inline uint2 operator*=( uint2& lhs, const uint2& rhs );

/// \relates uint2
/// \brief Returns a copy that has been component-wise divided by the given scalar value.
inline uint2 operator/( const uint2& lhs, const uint32_t rhs );

/// \relates uint2
/// \brief Divides each component by the given scalar value.
inline uint2 operator/=( uint2& lhs, const uint32_t rhs );

/// \relates uint2.
inline uint2 operator/( const uint2& lhs, const uint2& rhs );

/// \relates uint2.
inline uint2 operator/=( uint2& lhs, const uint2& rhs );

/// \relates uint2
/// \brief Returns a bool2 where each component is true if the component of the left-hand type is less than the corresponding right-hand type component.
inline bool2 operator<( const uint2& lhs, const uint2& rhs );

/// \relates uint2
/// \brief Returns a bool2 where each component is true if the component of the left-hand type is less than or equal to the corresponding right-hand type component.
inline bool2 operator<=( const uint2& lhs, const uint2& rhs );

/// \relates uint2
/// \brief Returns a bool2 where each component is true if the component of the left-hand type is greater than the corresponding right-hand type component.
inline bool2 operator>( const uint2& lhs, const uint2& rhs );

/// \relates uint2
/// \brief Returns a bool2 where each component is true if the component of the left-hand type is greater than or equal to the corresponding right-hand type component.
inline bool2 operator>=( const uint2& lhs, const uint2& rhs );

/// \relates uint2
/// \brief Returns a copy of the uint2 where each component has been bitwise AND'd against the given scalar value.
inline uint2 operator&( const uint2& lhs, const uint32_t& rhs );

/// \relates uint2
/// \brief Performs a bitwise AND on the given left-hand uint2 against the given scalar value.
inline uint2 operator&=( uint2& lhs, const uint32_t& rhs );

/// \relates uint2
/// \brief Returns a copy of the uint2 where each component of the left-hand uint2 has been bitwise AND'd against the corresponding component of the right-hand side uint2.
inline uint2 operator&( const uint2& lhs, const uint2& rhs );

/// \relates uint2
/// \brief Performs a bitwise AND on the given left-hand uint2 against the corresponding component of the given right-hand uint2.
inline uint2 operator&=( uint2& lhs, const uint2& rhs );

/// \relates uint2
/// \brief Returns a copy of the uint2 where each component has been bitwise OR'd against the given scalar value.
inline uint2 operator|( const uint2& lhs, const uint32_t& rhs );

/// \relates uint2
/// \brief Performs a bitwise OR on the given left-hand uint2 against the given scalar value.
inline uint2 operator|=( uint2& lhs, const uint32_t& rhs );

/// \relates uint2
/// \brief Returns a copy of the uint2 where each component of the left-hand uint2 has been bitwise OR'd against the corresponding component of the right-hand side uint2.
inline uint2 operator|( const uint2& lhs, const uint2& rhs );

/// \relates uint2
/// \brief Performs a bitwise OR on the given left-hand uint2 against the corresponding component of the given right-hand uint2.
inline uint2 operator|=( uint2& lhs, const uint2& rhs );

/// \relates uint2
/// \brief Returns a copy of the uint2 where each component has been bitwise XOR'd against the given scalar value.
inline uint2 operator^( const uint2& lhs, const uint32_t& rhs );

/// \relates uint2
/// \brief Performs a bitwise XOR on the given left-hand uint2 against the given scalar value.
inline uint2 operator^=( uint2& lhs, const uint32_t& rhs );

/// \relates uint2
/// \brief Returns a copy of the uint2 where each component of the left-hand uint2 has been bitwise XOR'd against the corresponding component of the right-hand side uint2.
inline uint2 operator^( const uint2& lhs, const uint2& rhs );

/// \relates uint2
/// \brief Performs a bitwise XOR on the given left-hand uint2 against the corresponding component of the given right-hand uint2.
inline uint2 operator^=( uint2& lhs, const uint2& rhs );

/// \relates uint2
/// \brief Returns a copy of the uint2 where each component has been bitwise left-shifted by the given scalar value.
inline uint2 operator<<( const uint2& lhs, const uint32_t& rhs );

/// \relates uint2
/// \brief Performs a left bitshift on the given left-hand uint2 by the given scalar value.
inline uint2 operator<<=( uint2& lhs, const uint32_t& rhs );

/// \relates uint2
/// \brief Returns a copy of the uint2 where each component of the left-hand uint2 has been bitwise left-shifted by the corresponding component of the right-hand side uint2.
inline uint2 operator<<( const uint2& lhs, const uint2& rhs );

/// \relates uint2
/// \brief Performs a left bitshift on the given left-hand uint2 by the corresponding component of the given right-hand uint2.
inline uint2 operator<<=( uint2& lhs, const uint2& rhs );

/// \relates uint2
/// \brief Returns a copy of the uint2 where each component has been bitwise right-shifted by the given scalar value.
inline uint2 operator>>( const uint2& lhs, const uint32_t& rhs );

/// \relates uint2
/// \brief Performs a right bitshift on the given left-hand uint2 by the given scalar value.
inline uint2 operator>>=( uint2& lhs, const uint32_t& rhs );

/// \relates uint2
/// \brief Returns a copy of the uint2 where each component of the left-hand uint2 has been bitwise right-shifted by the corresponding component of the right-hand side uint2.
inline uint2 operator>>( const uint2& lhs, const uint2& rhs );

/// \relates uint2
/// \brief Performs a right bitshift on the given left-hand uint2 by the corresponding component of the given right-hand uint2.
inline uint2 operator>>=( uint2& lhs, const uint2& rhs );

/// \relates uint2
/// \brief Performs a unary bitwise operation on all components of the given uint2.
inline uint2 operator~( const uint2& lhs );

// uint3
/// \relates uint3
/// \brief Returns a copy that has been component-wise added by the given scalar value.
inline uint3 operator+( const uint3& lhs, const uint32_t rhs );

/// \relates uint3
/// \brief Adds each component by the given scalar value.
inline uint3 operator+=( uint3& lhs, const uint32_t rhs );

/// \relates uint3.
inline uint3 operator+( const uint3& lhs, const uint3& rhs );

/// \relates uint3.
inline uint3 operator+=( uint3& lhs, const uint3& rhs );

/// \relates uint3
/// \brief Returns a copy that has been component-wise subtracted by the given scalar value.
inline uint3 operator-( const uint3& lhs, const uint32_t rhs );

/// \relates uint3
/// \brief Subtracts each component by the given scalar value.
inline uint3 operator-=( uint3& lhs, const uint32_t rhs );

/// \relates uint3.
inline uint3 operator-( const uint3& lhs, const uint3& rhs );

/// \relates uint3.
inline uint3 operator-=( uint3& lhs, const uint3& rhs );

/// \relates uint3
/// \brief Returns a copy that has been component-wise multiplied by the given scalar value.
inline uint3 operator*( const uint3& lhs, const uint32_t rhs );

/// \relates uint3
/// \brief Multiplies each component by the given scalar value.
inline uint3 operator*=( uint3& lhs, const uint32_t rhs );

/// \relates uint3.
inline uint3 operator*( const uint3& lhs, const uint3& rhs );

/// \relates uint3.
inline uint3 operator*=( uint3& lhs, const uint3& rhs );

/// \relates uint3
/// \brief Returns a copy that has been component-wise divided by the given scalar value.
inline uint3 operator/( const uint3& lhs, const uint32_t rhs );

/// \relates uint3
/// \brief Divides each component by the given scalar value.
inline uint3 operator/=( uint3& lhs, const uint32_t rhs );

/// \relates uint3.
inline uint3 operator/( const uint3& lhs, const uint3& rhs );

/// \relates uint3.
inline uint3 operator/=( uint3& lhs, const uint3& rhs );

/// \relates uint3
/// \brief Returns a bool3 where each component is true if the component of the left-hand type is less than the corresponding right-hand type component.
inline bool3 operator<( const uint3& lhs, const uint3& rhs );

/// \relates uint3
/// \brief Returns a bool3 where each component is true if the component of the left-hand type is less than or equal to the corresponding right-hand type component.
inline bool3 operator<=( const uint3& lhs, const uint3& rhs );

/// \relates uint3
/// \brief Returns a bool3 where each component is true if the component of the left-hand type is greater than the corresponding right-hand type component.
inline bool3 operator>( const uint3& lhs, const uint3& rhs );

/// \relates uint3
/// \brief Returns a bool3 where each component is true if the component of the left-hand type is greater than or equal to the corresponding right-hand type component.
inline bool3 operator>=( const uint3& lhs, const uint3& rhs );

/// \relates uint3
/// \brief Returns a copy of the uint3 where each component has been bitwise AND'd against the given scalar value.
inline uint3 operator&( const uint3& lhs, const uint32_t& rhs );

/// \relates uint3
/// \brief Performs a bitwise AND on the given left-hand uint3 against the given scalar value.
inline uint3 operator&=( uint3& lhs, const uint32_t& rhs );

/// \relates uint3
/// \brief Returns a copy of the uint3 where each component of the left-hand uint3 has been bitwise AND'd against the corresponding component of the right-hand side uint3.
inline uint3 operator&( const uint3& lhs, const uint3& rhs );

/// \relates uint3
/// \brief Performs a bitwise AND on the given left-hand uint3 against the corresponding component of the given right-hand uint3.
inline uint3 operator&=( uint3& lhs, const uint3& rhs );

/// \relates uint3
/// \brief Returns a copy of the uint3 where each component has been bitwise OR'd against the given scalar value.
inline uint3 operator|( const uint3& lhs, const uint32_t& rhs );

/// \relates uint3
/// \brief Performs a bitwise OR on the given left-hand uint3 against the given scalar value.
inline uint3 operator|=( uint3& lhs, const uint32_t& rhs );

/// \relates uint3
/// \brief Returns a copy of the uint3 where each component of the left-hand uint3 has been bitwise OR'd against the corresponding component of the right-hand side uint3.
inline uint3 operator|( const uint3& lhs, const uint3& rhs );

/// \relates uint3
/// \brief Performs a bitwise OR on the given left-hand uint3 against the corresponding component of the given right-hand uint3.
inline uint3 operator|=( uint3& lhs, const uint3& rhs );

/// \relates uint3
/// \brief Returns a copy of the uint3 where each component has been bitwise XOR'd against the given scalar value.
inline uint3 operator^( const uint3& lhs, const uint32_t& rhs );

/// \relates uint3
/// \brief Performs a bitwise XOR on the given left-hand uint3 against the given scalar value.
inline uint3 operator^=( uint3& lhs, const uint32_t& rhs );

/// \relates uint3
/// \brief Returns a copy of the uint3 where each component of the left-hand uint3 has been bitwise XOR'd against the corresponding component of the right-hand side uint3.
inline uint3 operator^( const uint3& lhs, const uint3& rhs );

/// \relates uint3
/// \brief Performs a bitwise XOR on the given left-hand uint3 against the corresponding component of the given right-hand uint3.
inline uint3 operator^=( uint3& lhs, const uint3& rhs );

/// \relates uint3
/// \brief Returns a copy of the uint3 where each component has been bitwise left-shifted by the given scalar value.
inline uint3 operator<<( const uint3& lhs, const uint32_t& rhs );

/// \relates uint3
/// \brief Performs a left bitshift on the given left-hand uint3 by the given scalar value.
inline uint3 operator<<=( uint3& lhs, const uint32_t& rhs );

/// \relates uint3
/// \brief Returns a copy of the uint3 where each component of the left-hand uint3 has been bitwise left-shifted by the corresponding component of the right-hand side uint3.
inline uint3 operator<<( const uint3& lhs, const uint3& rhs );

/// \relates uint3
/// \brief Performs a left bitshift on the given left-hand uint3 by the corresponding component of the given right-hand uint3.
inline uint3 operator<<=( uint3& lhs, const uint3& rhs );

/// \relates uint3
/// \brief Returns a copy of the uint3 where each component has been bitwise right-shifted by the given scalar value.
inline uint3 operator>>( const uint3& lhs, const uint32_t& rhs );

/// \relates uint3
/// \brief Performs a right bitshift on the given left-hand uint3 by the given scalar value.
inline uint3 operator>>=( uint3& lhs, const uint32_t& rhs );

/// \relates uint3
/// \brief Returns a copy of the uint3 where each component of the left-hand uint3 has been bitwise right-shifted by the corresponding component of the right-hand side uint3.
inline uint3 operator>>( const uint3& lhs, const uint3& rhs );

/// \relates uint3
/// \brief Performs a right bitshift on the given left-hand uint3 by the corresponding component of the given right-hand uint3.
inline uint3 operator>>=( uint3& lhs, const uint3& rhs );

/// \relates uint3
/// \brief Performs a unary bitwise operation on all components of the given uint3.
inline uint3 operator~( const uint3& lhs );

// uint4
/// \relates uint4
/// \brief Returns a copy that has been component-wise added by the given scalar value.
inline uint4 operator+( const uint4& lhs, const uint32_t rhs );

/// \relates uint4
/// \brief Adds each component by the given scalar value.
inline uint4 operator+=( uint4& lhs, const uint32_t rhs );

/// \relates uint4.
inline uint4 operator+( const uint4& lhs, const uint4& rhs );

/// \relates uint4.
inline uint4 operator+=( uint4& lhs, const uint4& rhs );

/// \relates uint4
/// \brief Returns a copy that has been component-wise subtracted by the given scalar value.
inline uint4 operator-( const uint4& lhs, const uint32_t rhs );

/// \relates uint4
/// \brief Subtracts each component by the given scalar value.
inline uint4 operator-=( uint4& lhs, const uint32_t rhs );

/// \relates uint4.
inline uint4 operator-( const uint4& lhs, const uint4& rhs );

/// \relates uint4.
inline uint4 operator-=( uint4& lhs, const uint4& rhs );

/// \relates uint4
/// \brief Returns a copy that has been component-wise multiplied by the given scalar value.
inline uint4 operator*( const uint4& lhs, const uint32_t rhs );

/// \relates uint4
/// \brief Multiplies each component by the given scalar value.
inline uint4 operator*=( uint4& lhs, const uint32_t rhs );

/// \relates uint4.
inline uint4 operator*( const uint4& lhs, const uint4& rhs );

/// \relates uint4.
inline uint4 operator*=( uint4& lhs, const uint4& rhs );

/// \relates uint4
/// \brief Returns a copy that has been component-wise divided by the given scalar value.
inline uint4 operator/( const uint4& lhs, const uint32_t rhs );

/// \relates uint4
/// \brief Divides each component by the given scalar value.
inline uint4 operator/=( uint4& lhs, const uint32_t rhs );

/// \relates uint4.
inline uint4 operator/( const uint4& lhs, const uint4& rhs );

/// \relates uint4.
inline uint4 operator/=( uint4& lhs, const uint4& rhs );

/// \relates uint4
/// \brief Returns a bool4 where each component is true if the component of the left-hand type is less than the corresponding right-hand type component.
inline bool4 operator<( const uint4& lhs, const uint4& rhs );

/// \relates uint4
/// \brief Returns a bool4 where each component is true if the component of the left-hand type is less than or equal to the corresponding right-hand type component.
inline bool4 operator<=( const uint4& lhs, const uint4& rhs );

/// \relates uint4
/// \brief Returns a bool4 where each component is true if the component of the left-hand type is greater than the corresponding right-hand type component.
inline bool4 operator>( const uint4& lhs, const uint4& rhs );

/// \relates uint4
/// \brief Returns a bool4 where each component is true if the component of the left-hand type is greater than or equal to the corresponding right-hand type component.
inline bool4 operator>=( const uint4& lhs, const uint4& rhs );

/// \relates uint4
/// \brief Returns a copy of the uint4 where each component has been bitwise AND'd against the given scalar value.
inline uint4 operator&( const uint4& lhs, const uint32_t& rhs );

/// \relates uint4
/// \brief Performs a bitwise AND on the given left-hand uint4 against the given scalar value.
inline uint4 operator&=( uint4& lhs, const uint32_t& rhs );

/// \relates uint4
/// \brief Returns a copy of the uint4 where each component of the left-hand uint4 has been bitwise AND'd against the corresponding component of the right-hand side uint4.
inline uint4 operator&( const uint4& lhs, const uint4& rhs );

/// \relates uint4
/// \brief Performs a bitwise AND on the given left-hand uint4 against the corresponding component of the given right-hand uint4.
inline uint4 operator&=( uint4& lhs, const uint4& rhs );

/// \relates uint4
/// \brief Returns a copy of the uint4 where each component has been bitwise OR'd against the given scalar value.
inline uint4 operator|( const uint4& lhs, const uint32_t& rhs );

/// \relates uint4
/// \brief Performs a bitwise OR on the given left-hand uint4 against the given scalar value.
inline uint4 operator|=( uint4& lhs, const uint32_t& rhs );

/// \relates uint4
/// \brief Returns a copy of the uint4 where each component of the left-hand uint4 has been bitwise OR'd against the corresponding component of the right-hand side uint4.
inline uint4 operator|( const uint4& lhs, const uint4& rhs );

/// \relates uint4
/// \brief Performs a bitwise OR on the given left-hand uint4 against the corresponding component of the given right-hand uint4.
inline uint4 operator|=( uint4& lhs, const uint4& rhs );

/// \relates uint4
/// \brief Returns a copy of the uint4 where each component has been bitwise XOR'd against the given scalar value.
inline uint4 operator^( const uint4& lhs, const uint32_t& rhs );

/// \relates uint4
/// \brief Performs a bitwise XOR on the given left-hand uint4 against the given scalar value.
inline uint4 operator^=( uint4& lhs, const uint32_t& rhs );

/// \relates uint4
/// \brief Returns a copy of the uint4 where each component of the left-hand uint4 has been bitwise XOR'd against the corresponding component of the right-hand side uint4.
inline uint4 operator^( const uint4& lhs, const uint4& rhs );

/// \relates uint4
/// \brief Performs a bitwise XOR on the given left-hand uint4 against the corresponding component of the given right-hand uint4.
inline uint4 operator^=( uint4& lhs, const uint4& rhs );

/// \relates uint4
/// \brief Returns a copy of the uint4 where each component has been bitwise left-shifted by the given scalar value.
inline uint4 operator<<( const uint4& lhs, const uint32_t& rhs );

/// \relates uint4
/// \brief Performs a left bitshift on the given left-hand uint4 by the given scalar value.
inline uint4 operator<<=( uint4& lhs, const uint32_t& rhs );

/// \relates uint4
/// \brief Returns a copy of the uint4 where each component of the left-hand uint4 has been bitwise left-shifted by the corresponding component of the right-hand side uint4.
inline uint4 operator<<( const uint4& lhs, const uint4& rhs );

/// \relates uint4
/// \brief Performs a left bitshift on the given left-hand uint4 by the corresponding component of the given right-hand uint4.
inline uint4 operator<<=( uint4& lhs, const uint4& rhs );

/// \relates uint4
/// \brief Returns a copy of the uint4 where each component has been bitwise right-shifted by the given scalar value.
inline uint4 operator>>( const uint4& lhs, const uint32_t& rhs );

/// \relates uint4
/// \brief Performs a right bitshift on the given left-hand uint4 by the given scalar value.
inline uint4 operator>>=( uint4& lhs, const uint32_t& rhs );

/// \relates uint4
/// \brief Returns a copy of the uint4 where each component of the left-hand uint4 has been bitwise right-shifted by the corresponding component of the right-hand side uint4.
inline uint4 operator>>( const uint4& lhs, const uint4& rhs );

/// \relates uint4
/// \brief Performs a right bitshift on the given left-hand uint4 by the corresponding component of the given right-hand uint4.
inline uint4 operator>>=( uint4& lhs, const uint4& rhs );

/// \relates uint4
/// \brief Performs a unary bitwise operation on all components of the given uint4.
inline uint4 operator~( const uint4& lhs );

// float2
/// \relates float2
/// \brief Returns a copy that has been component-wise added by the given scalar value.
inline float2 operator+( const float2& lhs, const float rhs );

/// \relates float2
/// \brief Adds each component by the given scalar value.
inline float2 operator+=( float2& lhs, const float rhs );

/// \relates float2.
inline float2 operator+( const float2& lhs, const float2& rhs );

/// \relates float2.
inline float2 operator+=( float2& lhs, const float2& rhs );

/// \relates float2
/// \brief Returns a copy that has been component-wise subtracted by the given scalar value.
inline float2 operator-( const float2& lhs, const float rhs );

/// \relates float2
/// \brief Subtracts each component by the given scalar value.
inline float2 operator-=( float2& lhs, const float rhs );

/// \relates float2.
inline float2 operator-( const float2& lhs, const float2& rhs );

/// \relates float2.
inline float2 operator-=( float2& lhs, const float2& rhs );

/// \relates float2
/// \brief Returns a copy that has been component-wise multiplied by the given scalar value.
inline float2 operator*( const float2& lhs, const float rhs );

/// \relates float2
/// \brief Multiplies each component by the given scalar value.
inline float2 operator*=( float2& lhs, const float rhs );

/// \relates float2.
inline float2 operator*( const float2& lhs, const float2& rhs );

/// \relates float2.
inline float2 operator*=( float2& lhs, const float2& rhs );

/// \relates float2
/// \brief Returns a copy that has been component-wise divided by the given scalar value.
inline float2 operator/( const float2& lhs, const float rhs );

/// \relates float2
/// \brief Divides each component by the given scalar value.
inline float2 operator/=( float2& lhs, const float rhs );

/// \relates float2.
inline float2 operator/( const float2& lhs, const float2& rhs );

/// \relates float2.
inline float2 operator/=( float2& lhs, const float2& rhs );

/// \relates float2
/// \brief Returns a bool2 where each component is true if the component of the left-hand type is less than the corresponding right-hand type component.
inline bool2 operator<( const float2& lhs, const float2& rhs );

/// \relates float2
/// \brief Returns a bool2 where each component is true if the component of the left-hand type is less than or equal to the corresponding right-hand type component.
inline bool2 operator<=( const float2& lhs, const float2& rhs );

/// \relates float2
/// \brief Returns a bool2 where each component is true if the component of the left-hand type is greater than the corresponding right-hand type component.
inline bool2 operator>( const float2& lhs, const float2& rhs );

/// \relates float2
/// \brief Returns a bool2 where each component is true if the component of the left-hand type is greater than or equal to the corresponding right-hand type component.
inline bool2 operator>=( const float2& lhs, const float2& rhs );


// float3
/// \relates float3
/// \brief Returns a copy that has been component-wise added by the given scalar value.
inline float3 operator+( const float3& lhs, const float rhs );

/// \relates float3
/// \brief Adds each component by the given scalar value.
inline float3 operator+=( float3& lhs, const float rhs );

/// \relates float3.
inline float3 operator+( const float3& lhs, const float3& rhs );

/// \relates float3.
inline float3 operator+=( float3& lhs, const float3& rhs );

/// \relates float3
/// \brief Returns a copy that has been component-wise subtracted by the given scalar value.
inline float3 operator-( const float3& lhs, const float rhs );

/// \relates float3
/// \brief Subtracts each component by the given scalar value.
inline float3 operator-=( float3& lhs, const float rhs );

/// \relates float3.
inline float3 operator-( const float3& lhs, const float3& rhs );

/// \relates float3.
inline float3 operator-=( float3& lhs, const float3& rhs );

/// \relates float3
/// \brief Returns a copy that has been component-wise multiplied by the given scalar value.
inline float3 operator*( const float3& lhs, const float rhs );

/// \relates float3
/// \brief Multiplies each component by the given scalar value.
inline float3 operator*=( float3& lhs, const float rhs );

/// \relates float3.
inline float3 operator*( const float3& lhs, const float3& rhs );

/// \relates float3.
inline float3 operator*=( float3& lhs, const float3& rhs );

/// \relates float3
/// \brief Returns a copy that has been component-wise divided by the given scalar value.
inline float3 operator/( const float3& lhs, const float rhs );

/// \relates float3
/// \brief Divides each component by the given scalar value.
inline float3 operator/=( float3& lhs, const float rhs );

/// \relates float3.
inline float3 operator/( const float3& lhs, const float3& rhs );

/// \relates float3.
inline float3 operator/=( float3& lhs, const float3& rhs );

/// \relates float3
/// \brief Returns a bool3 where each component is true if the component of the left-hand type is less than the corresponding right-hand type component.
inline bool3 operator<( const float3& lhs, const float3& rhs );

/// \relates float3
/// \brief Returns a bool3 where each component is true if the component of the left-hand type is less than or equal to the corresponding right-hand type component.
inline bool3 operator<=( const float3& lhs, const float3& rhs );

/// \relates float3
/// \brief Returns a bool3 where each component is true if the component of the left-hand type is greater than the corresponding right-hand type component.
inline bool3 operator>( const float3& lhs, const float3& rhs );

/// \relates float3
/// \brief Returns a bool3 where each component is true if the component of the left-hand type is greater than or equal to the corresponding right-hand type component.
inline bool3 operator>=( const float3& lhs, const float3& rhs );


// float4
/// \relates float4
/// \brief Returns a copy that has been component-wise added by the given scalar value.
inline float4 operator+( const float4& lhs, const float rhs );

/// \relates float4
/// \brief Adds each component by the given scalar value.
inline float4 operator+=( float4& lhs, const float rhs );

/// \relates float4.
inline float4 operator+( const float4& lhs, const float4& rhs );

/// \relates float4.
inline float4 operator+=( float4& lhs, const float4& rhs );

/// \relates float4
/// \brief Returns a copy that has been component-wise subtracted by the given scalar value.
inline float4 operator-( const float4& lhs, const float rhs );

/// \relates float4
/// \brief Subtracts each component by the given scalar value.
inline float4 operator-=( float4& lhs, const float rhs );

/// \relates float4.
inline float4 operator-( const float4& lhs, const float4& rhs );

/// \relates float4.
inline float4 operator-=( float4& lhs, const float4& rhs );

/// \relates float4
/// \brief Returns a copy that has been component-wise multiplied by the given scalar value.
inline float4 operator*( const float4& lhs, const float rhs );

/// \relates float4
/// \brief Multiplies each component by the given scalar value.
inline float4 operator*=( float4& lhs, const float rhs );

/// \relates float4.
inline float4 operator*( const float4& lhs, const float4& rhs );

/// \relates float4.
inline float4 operator*=( float4& lhs, const float4& rhs );

/// \relates float4
/// \brief Returns a copy that has been component-wise divided by the given scalar value.
inline float4 operator/( const float4& lhs, const float rhs );

/// \relates float4
/// \brief Divides each component by the given scalar value.
inline float4 operator/=( float4& lhs, const float rhs );

/// \relates float4.
inline float4 operator/( const float4& lhs, const float4& rhs );

/// \relates float4.
inline float4 operator/=( float4& lhs, const float4& rhs );

/// \relates float4
/// \brief Returns a bool4 where each component is true if the component of the left-hand type is less than the corresponding right-hand type component.
inline bool4 operator<( const float4& lhs, const float4& rhs );

/// \relates float4
/// \brief Returns a bool4 where each component is true if the component of the left-hand type is less than or equal to the corresponding right-hand type component.
inline bool4 operator<=( const float4& lhs, const float4& rhs );

/// \relates float4
/// \brief Returns a bool4 where each component is true if the component of the left-hand type is greater than the corresponding right-hand type component.
inline bool4 operator>( const float4& lhs, const float4& rhs );

/// \relates float4
/// \brief Returns a bool4 where each component is true if the component of the left-hand type is greater than or equal to the corresponding right-hand type component.
inline bool4 operator>=( const float4& lhs, const float4& rhs );


// double2
/// \relates double2
/// \brief Returns a copy that has been component-wise added by the given scalar value.
inline double2 operator+( const double2& lhs, const double rhs );

/// \relates double2
/// \brief Adds each component by the given scalar value.
inline double2 operator+=( double2& lhs, const double rhs );

/// \relates double2.
inline double2 operator+( const double2& lhs, const double2& rhs );

/// \relates double2.
inline double2 operator+=( double2& lhs, const double2& rhs );

/// \relates double2
/// \brief Returns a copy that has been component-wise subtracted by the given scalar value.
inline double2 operator-( const double2& lhs, const double rhs );

/// \relates double2
/// \brief Subtracts each component by the given scalar value.
inline double2 operator-=( double2& lhs, const double rhs );

/// \relates double2.
inline double2 operator-( const double2& lhs, const double2& rhs );

/// \relates double2.
inline double2 operator-=( double2& lhs, const double2& rhs );

/// \relates double2
/// \brief Returns a copy that has been component-wise multiplied by the given scalar value.
inline double2 operator*( const double2& lhs, const double rhs );

/// \relates double2
/// \brief Multiplies each component by the given scalar value.
inline double2 operator*=( double2& lhs, const double rhs );

/// \relates double2.
inline double2 operator*( const double2& lhs, const double2& rhs );

/// \relates double2.
inline double2 operator*=( double2& lhs, const double2& rhs );

/// \relates double2
/// \brief Returns a copy that has been component-wise divided by the given scalar value.
inline double2 operator/( const double2& lhs, const double rhs );

/// \relates double2
/// \brief Divides each component by the given scalar value.
inline double2 operator/=( double2& lhs, const double rhs );

/// \relates double2.
inline double2 operator/( const double2& lhs, const double2& rhs );

/// \relates double2.
inline double2 operator/=( double2& lhs, const double2& rhs );

/// \relates double2
/// \brief Returns a bool2 where each component is true if the component of the left-hand type is less than the corresponding right-hand type component.
inline bool2 operator<( const double2& lhs, const double2& rhs );

/// \relates double2
/// \brief Returns a bool2 where each component is true if the component of the left-hand type is less than or equal to the corresponding right-hand type component.
inline bool2 operator<=( const double2& lhs, const double2& rhs );

/// \relates double2
/// \brief Returns a bool2 where each component is true if the component of the left-hand type is greater than the corresponding right-hand type component.
inline bool2 operator>( const double2& lhs, const double2& rhs );

/// \relates double2
/// \brief Returns a bool2 where each component is true if the component of the left-hand type is greater than or equal to the corresponding right-hand type component.
inline bool2 operator>=( const double2& lhs, const double2& rhs );


// double3
/// \relates double3
/// \brief Returns a copy that has been component-wise added by the given scalar value.
inline double3 operator+( const double3& lhs, const double rhs );

/// \relates double3
/// \brief Adds each component by the given scalar value.
inline double3 operator+=( double3& lhs, const double rhs );

/// \relates double3.
inline double3 operator+( const double3& lhs, const double3& rhs );

/// \relates double3.
inline double3 operator+=( double3& lhs, const double3& rhs );

/// \relates double3
/// \brief Returns a copy that has been component-wise subtracted by the given scalar value.
inline double3 operator-( const double3& lhs, const double rhs );

/// \relates double3
/// \brief Subtracts each component by the given scalar value.
inline double3 operator-=( double3& lhs, const double rhs );

/// \relates double3.
inline double3 operator-( const double3& lhs, const double3& rhs );

/// \relates double3.
inline double3 operator-=( double3& lhs, const double3& rhs );

/// \relates double3
/// \brief Returns a copy that has been component-wise multiplied by the given scalar value.
inline double3 operator*( const double3& lhs, const double rhs );

/// \relates double3
/// \brief Multiplies each component by the given scalar value.
inline double3 operator*=( double3& lhs, const double rhs );

/// \relates double3.
inline double3 operator*( const double3& lhs, const double3& rhs );

/// \relates double3.
inline double3 operator*=( double3& lhs, const double3& rhs );

/// \relates double3
/// \brief Returns a copy that has been component-wise divided by the given scalar value.
inline double3 operator/( const double3& lhs, const double rhs );

/// \relates double3
/// \brief Divides each component by the given scalar value.
inline double3 operator/=( double3& lhs, const double rhs );

/// \relates double3.
inline double3 operator/( const double3& lhs, const double3& rhs );

/// \relates double3.
inline double3 operator/=( double3& lhs, const double3& rhs );

/// \relates double3
/// \brief Returns a bool3 where each component is true if the component of the left-hand type is less than the corresponding right-hand type component.
inline bool3 operator<( const double3& lhs, const double3& rhs );

/// \relates double3
/// \brief Returns a bool3 where each component is true if the component of the left-hand type is less than or equal to the corresponding right-hand type component.
inline bool3 operator<=( const double3& lhs, const double3& rhs );

/// \relates double3
/// \brief Returns a bool3 where each component is true if the component of the left-hand type is greater than the corresponding right-hand type component.
inline bool3 operator>( const double3& lhs, const double3& rhs );

/// \relates double3
/// \brief Returns a bool3 where each component is true if the component of the left-hand type is greater than or equal to the corresponding right-hand type component.
inline bool3 operator>=( const double3& lhs, const double3& rhs );


// double4
/// \relates double4
/// \brief Returns a copy that has been component-wise added by the given scalar value.
inline double4 operator+( const double4& lhs, const double rhs );

/// \relates double4
/// \brief Adds each component by the given scalar value.
inline double4 operator+=( double4& lhs, const double rhs );

/// \relates double4.
inline double4 operator+( const double4& lhs, const double4& rhs );

/// \relates double4.
inline double4 operator+=( double4& lhs, const double4& rhs );

/// \relates double4
/// \brief Returns a copy that has been component-wise subtracted by the given scalar value.
inline double4 operator-( const double4& lhs, const double rhs );

/// \relates double4
/// \brief Subtracts each component by the given scalar value.
inline double4 operator-=( double4& lhs, const double rhs );

/// \relates double4.
inline double4 operator-( const double4& lhs, const double4& rhs );

/// \relates double4.
inline double4 operator-=( double4& lhs, const double4& rhs );

/// \relates double4
/// \brief Returns a copy that has been component-wise multiplied by the given scalar value.
inline double4 operator*( const double4& lhs, const double rhs );

/// \relates double4
/// \brief Multiplies each component by the given scalar value.
inline double4 operator*=( double4& lhs, const double rhs );

/// \relates double4.
inline double4 operator*( const double4& lhs, const double4& rhs );

/// \relates double4.
inline double4 operator*=( double4& lhs, const double4& rhs );

/// \relates double4
/// \brief Returns a copy that has been component-wise divided by the given scalar value.
inline double4 operator/( const double4& lhs, const double rhs );

/// \relates double4
/// \brief Divides each component by the given scalar value.
inline double4 operator/=( double4& lhs, const double rhs );

/// \relates double4.
inline double4 operator/( const double4& lhs, const double4& rhs );

/// \relates double4.
inline double4 operator/=( double4& lhs, const double4& rhs );

/// \relates double4
/// \brief Returns a bool4 where each component is true if the component of the left-hand type is less than the corresponding right-hand type component.
inline bool4 operator<( const double4& lhs, const double4& rhs );

/// \relates double4
/// \brief Returns a bool4 where each component is true if the component of the left-hand type is less than or equal to the corresponding right-hand type component.
inline bool4 operator<=( const double4& lhs, const double4& rhs );

/// \relates double4
/// \brief Returns a bool4 where each component is true if the component of the left-hand type is greater than the corresponding right-hand type component.
inline bool4 operator>( const double4& lhs, const double4& rhs );

/// \relates double4
/// \brief Returns a bool4 where each component is true if the component of the left-hand type is greater than or equal to the corresponding right-hand type component.
inline bool4 operator>=( const double4& lhs, const double4& rhs );


#include "hlml_operators_vector.inl"

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

#include "float4.h"
#include "float3x3.h"
#include "float4x3.h"

struct float3x4 {
	float4 rows[3];

	inline float3x4();
	inline float3x4( const float diagonal );
	inline float3x4( const float4& diagonal );
	inline float3x4( const float4& row0, const float4& row1, const float4& row2 );
	inline float3x4( const float4 rows[3] );
	inline float3x4( const float m00, const float m01, const float m02, const float m03, const float m10, const float m11, const float m12, const float m13, const float m20, const float m21, const float m22, const float m23 );
	inline float3x4( const float3x4& other );
	inline ~float3x4() {}

	inline float3x4 operator=( const float3x4& other );

	inline float4& operator[]( const uint32_t index );
	inline const float4& operator[]( const uint32_t index ) const;
};

inline bool operator==( const float3x4& lhs, const float3x4& rhs );
inline bool operator!=( const float3x4& lhs, const float3x4& rhs );

#include "float3x4.inl"
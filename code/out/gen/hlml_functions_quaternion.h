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

#include "float4.h"
#include "double4.h"

// float4
inline float quaternion_mul( const float4& lhs, const float4& rhs );

inline float quaternion_mul( const float4& lhs, const float& rhs );

inline float quaternion_magnitude( const float4& quat );

inline float4 quaternion_normalize( const float4& quat );

inline float4 quaternion_conjugate( const float4& quat );

inline float4 quaternion_inverse( const float4& quat );


// double4
inline double quaternion_mul( const double4& lhs, const double4& rhs );

inline double quaternion_mul( const double4& lhs, const double& rhs );

inline double quaternion_magnitude( const double4& quat );

inline double4 quaternion_normalize( const double4& quat );

inline double4 quaternion_conjugate( const double4& quat );

inline double4 quaternion_inverse( const double4& quat );


#include "hlml_functions_quaternion.inl"

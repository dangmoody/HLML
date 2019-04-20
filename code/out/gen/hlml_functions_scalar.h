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

#include "../hlml_constants.h"

#include <math.h>
#include <stdint.h>

// replace windows defines with our own min/max functions
#ifdef HLML_UNDEF_SYSTEM_MIN_MAX
#undef min
#undef max
#endif


// int32_t
/// \brief Returns -1 if x is < 0, 0 if x == 0, or 1 if x > 1.
/// This function does no branching.
inline int32_t sign( const int32_t x )
{
	return ( 0 < x ) - ( x < 0 );
}

/// \brief Returns x if its smaller than y, otherwise returns y.
inline int32_t min( const int32_t& x, const int32_t& y )
{
	return ( x < y ) ? x : y;
}

/// \brief Returns x if its bigger than y, otherwise returns y.
inline int32_t max( const int32_t& x, const int32_t& y )
{
	return ( x > y ) ? x : y;
}

/// \brief If x is lower than low or higher than high then returns low or high respectively, otherwise returns x.
inline int32_t clamp( const int32_t& x, const int32_t& low, const int32_t& high )
{
	return min( max( x, low ), high );
}


// uint32_t
/// \brief Returns x if its smaller than y, otherwise returns y.
inline uint32_t min( const uint32_t& x, const uint32_t& y )
{
	return ( x < y ) ? x : y;
}

/// \brief Returns x if its bigger than y, otherwise returns y.
inline uint32_t max( const uint32_t& x, const uint32_t& y )
{
	return ( x > y ) ? x : y;
}

/// \brief If x is lower than low or higher than high then returns low or high respectively, otherwise returns x.
inline uint32_t clamp( const uint32_t& x, const uint32_t& low, const uint32_t& high )
{
	return min( max( x, low ), high );
}


// float
/// \brief Returns true if the two given floating-point numbers are within a small enough epsilon range of each other that takes into account floating-point inaccuracy.
inline bool floateq( const float lhs, const float rhs, const float epsilon = static_cast<float>( HLML_EPSILON ) )
{
	return fabsf( lhs - rhs ) < epsilon;
}

/// \brief Returns true if the given floating-point number is considered to be infinity.
inline bool isinf( const float x )
{
	return ( x == x ) && !floateq( x * 0.000000f, x * 0.000000f );
}

/// \brief Returns true if the given floating-point number is considered to be not-a-number.
inline bool isnan( const float x )
{
	return x != x;
}

/// \brief Returns -1 if x is < 0, 0 if x == 0, or 1 if x > 1.
/// This function does no branching.
inline int32_t sign( const float x )
{
	return ( 0.000000f < x ) - ( x < 0.000000f );
}

/// \brief Returns the given degrees to radians.
inline float radians( const float deg )
{
	return deg * static_cast<float>( HLML_PI ) / 180.000000f;
}

/// \brief Returns the given radians to degrees.
inline float degrees( const float rad )
{
	return rad * 180.000000f / static_cast<float>( HLML_PI );
}

/// \brief Returns x if its smaller than y, otherwise returns y.
inline float min( const float& x, const float& y )
{
	return ( x < y ) ? x : y;
}

/// \brief Returns x if its bigger than y, otherwise returns y.
inline float max( const float& x, const float& y )
{
	return ( x > y ) ? x : y;
}

/// \brief If x is lower than low or higher than high then returns low or high respectively, otherwise returns x.
inline float clamp( const float& x, const float& low, const float& high )
{
	return min( max( x, low ), high );
}

/// \relates float
/// \brief Returns a copy of the float with each component clamped between the range 0 and 1.
inline float saturate( const float& x )
{
	return clamp( x, 0.000000f, 1.000000f );
}

/// \relates float
/// \brief Returns a linearly interpolated float between types "a" and "b".
inline float lerp( const float& a, const float& b, const float t )
{
	return ( 1.000000f - t ) * a + t * b;
}

/// \relates float
/// \brief Performs a sigmoid-like interpolation and clamp.
inline float smoothstep( const float& low, const float& high, const float& x )
{
	float t = saturate( ( x - low ) / ( high - low ) );
	return t * t * ( 3.000000f - 2.000000f * t );
}

/// \relates float
/// \brief Performs a 'smoother' version of smoothstep, as design by Ken Perlin.
/// https://en.wikipedia.org/wiki/Smoothstep#Variations 
inline float smootherstep( const float& low, const float& high, const float& x )
{
	float t = saturate( ( x - low ) / ( high - low ) );
	return t * t * t * ( t * ( t * 6.000000f - 15.000000f ) + 10.000000f );
}


// double
/// \brief Returns true if the two given floating-point numbers are within a small enough epsilon range of each other that takes into account floating-point inaccuracy.
inline bool doubleeq( const double lhs, const double rhs, const double epsilon = HLML_EPSILON )
{
	return fabs( lhs - rhs ) < epsilon;
}

/// \brief Returns true if the given floating-point number is considered to be infinity.
inline bool isinf( const double x )
{
	return ( x == x ) && !doubleeq( x * 0.000000, x * 0.000000 );
}

/// \brief Returns true if the given floating-point number is considered to be not-a-number.
inline bool isnan( const double x )
{
	return x != x;
}

/// \brief Returns -1 if x is < 0, 0 if x == 0, or 1 if x > 1.
/// This function does no branching.
inline int32_t sign( const double x )
{
	return ( 0.000000 < x ) - ( x < 0.000000 );
}

/// \brief Returns the given degrees to radians.
inline double radians( const double deg )
{
	return deg * HLML_PI / 180.000000;
}

/// \brief Returns the given radians to degrees.
inline double degrees( const double rad )
{
	return rad * 180.000000 / HLML_PI;
}

/// \brief Returns x if its smaller than y, otherwise returns y.
inline double min( const double& x, const double& y )
{
	return ( x < y ) ? x : y;
}

/// \brief Returns x if its bigger than y, otherwise returns y.
inline double max( const double& x, const double& y )
{
	return ( x > y ) ? x : y;
}

/// \brief If x is lower than low or higher than high then returns low or high respectively, otherwise returns x.
inline double clamp( const double& x, const double& low, const double& high )
{
	return min( max( x, low ), high );
}

/// \relates double
/// \brief Returns a copy of the double with each component clamped between the range 0 and 1.
inline double saturate( const double& x )
{
	return clamp( x, 0.000000, 1.000000 );
}

/// \relates double
/// \brief Returns a linearly interpolated double between types "a" and "b".
inline double lerp( const double& a, const double& b, const double t )
{
	return ( 1.000000 - t ) * a + t * b;
}

/// \relates double
/// \brief Performs a sigmoid-like interpolation and clamp.
inline double smoothstep( const double& low, const double& high, const double& x )
{
	double t = saturate( ( x - low ) / ( high - low ) );
	return t * t * ( 3.000000 - 2.000000 * t );
}

/// \relates double
/// \brief Performs a 'smoother' version of smoothstep, as design by Ken Perlin.
/// https://en.wikipedia.org/wiki/Smoothstep#Variations 
inline double smootherstep( const double& low, const double& high, const double& x )
{
	double t = saturate( ( x - low ) / ( high - low ) );
	return t * t * t * ( t * ( t * 6.000000 - 15.000000 ) + 10.000000 );
}



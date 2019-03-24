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

// int2
__m128i dot_ps( const int2_dot_data_t& lhs, const int2_dot_data_t& rhs )
{
	const __m128i mul_x	= _mm_mul_ps( lhs.components_x, rhs.components_x );
	const __m128i mul_y	= _mm_mul_ps( lhs.components_y, rhs.components_y );

	return _mm_add_ps( mul_x, mul_y );
}


// int3
__m128i dot_ps( const int3_dot_data_t& lhs, const int3_dot_data_t& rhs )
{
	const __m128i mul_x	= _mm_mul_ps( lhs.components_x, rhs.components_x );
	const __m128i mul_y	= _mm_mul_ps( lhs.components_y, rhs.components_y );
	const __m128i mul_z	= _mm_mul_ps( lhs.components_z, rhs.components_z );

	const __m128 add0	= _mm_add_ps( mul_x, mul_y );

	return _mm_add_ps( add0, mul_z );
}


// int4
__m128i dot_ps( const int4_dot_data_t& lhs, const int4_dot_data_t& rhs )
{
	const __m128i mul_x	= _mm_mul_ps( lhs.components_x, rhs.components_x );
	const __m128i mul_y	= _mm_mul_ps( lhs.components_y, rhs.components_y );
	const __m128i mul_z	= _mm_mul_ps( lhs.components_z, rhs.components_z );
	const __m128i mul_w	= _mm_mul_ps( lhs.components_w, rhs.components_w );

	const __m128 add0	= _mm_add_ps( mul_x, mul_y );
	const __m128 add1	= _mm_add_ps( mul_z, mul_w );

	return _mm_add_ps( add0, add1 );
}


// uint2
__m128i dot_ps( const uint2_dot_data_t& lhs, const uint2_dot_data_t& rhs )
{
	const __m128i mul_x	= _mm_mul_ps( lhs.components_x, rhs.components_x );
	const __m128i mul_y	= _mm_mul_ps( lhs.components_y, rhs.components_y );

	return _mm_add_ps( mul_x, mul_y );
}


// uint3
__m128i dot_ps( const uint3_dot_data_t& lhs, const uint3_dot_data_t& rhs )
{
	const __m128i mul_x	= _mm_mul_ps( lhs.components_x, rhs.components_x );
	const __m128i mul_y	= _mm_mul_ps( lhs.components_y, rhs.components_y );
	const __m128i mul_z	= _mm_mul_ps( lhs.components_z, rhs.components_z );

	const __m128 add0	= _mm_add_ps( mul_x, mul_y );

	return _mm_add_ps( add0, mul_z );
}


// uint4
__m128i dot_ps( const uint4_dot_data_t& lhs, const uint4_dot_data_t& rhs )
{
	const __m128i mul_x	= _mm_mul_ps( lhs.components_x, rhs.components_x );
	const __m128i mul_y	= _mm_mul_ps( lhs.components_y, rhs.components_y );
	const __m128i mul_z	= _mm_mul_ps( lhs.components_z, rhs.components_z );
	const __m128i mul_w	= _mm_mul_ps( lhs.components_w, rhs.components_w );

	const __m128 add0	= _mm_add_ps( mul_x, mul_y );
	const __m128 add1	= _mm_add_ps( mul_z, mul_w );

	return _mm_add_ps( add0, add1 );
}


// float2
__m128 dot_ps( const float2_dot_data_t& lhs, const float2_dot_data_t& rhs )
{
	const __m128 mul_x	= _mm_mul_ps( lhs.components_x, rhs.components_x );
	const __m128 mul_y	= _mm_mul_ps( lhs.components_y, rhs.components_y );

	return _mm_add_ps( mul_x, mul_y );
}


// float3
__m128 dot_ps( const float3_dot_data_t& lhs, const float3_dot_data_t& rhs )
{
	const __m128 mul_x	= _mm_mul_ps( lhs.components_x, rhs.components_x );
	const __m128 mul_y	= _mm_mul_ps( lhs.components_y, rhs.components_y );
	const __m128 mul_z	= _mm_mul_ps( lhs.components_z, rhs.components_z );

	const __m128 add0	= _mm_add_ps( mul_x, mul_y );

	return _mm_add_ps( add0, mul_z );
}


// float4
__m128 dot_ps( const float4_dot_data_t& lhs, const float4_dot_data_t& rhs )
{
	const __m128 mul_x	= _mm_mul_ps( lhs.components_x, rhs.components_x );
	const __m128 mul_y	= _mm_mul_ps( lhs.components_y, rhs.components_y );
	const __m128 mul_z	= _mm_mul_ps( lhs.components_z, rhs.components_z );
	const __m128 mul_w	= _mm_mul_ps( lhs.components_w, rhs.components_w );

	const __m128 add0	= _mm_add_ps( mul_x, mul_y );
	const __m128 add1	= _mm_add_ps( mul_z, mul_w );

	return _mm_add_ps( add0, add1 );
}


// double2
__m128d dot_ps( const double2_dot_data_t& lhs, const double2_dot_data_t& rhs )
{
	const __m128d mul_x	= _mm_mul_ps( lhs.components_x, rhs.components_x );
	const __m128d mul_y	= _mm_mul_ps( lhs.components_y, rhs.components_y );

	return _mm_add_ps( mul_x, mul_y );
}


// double3
__m128d dot_ps( const double3_dot_data_t& lhs, const double3_dot_data_t& rhs )
{
	const __m128d mul_x	= _mm_mul_ps( lhs.components_x, rhs.components_x );
	const __m128d mul_y	= _mm_mul_ps( lhs.components_y, rhs.components_y );
	const __m128d mul_z	= _mm_mul_ps( lhs.components_z, rhs.components_z );

	const __m128 add0	= _mm_add_ps( mul_x, mul_y );

	return _mm_add_ps( add0, mul_z );
}


// double4
__m128d dot_ps( const double4_dot_data_t& lhs, const double4_dot_data_t& rhs )
{
	const __m128d mul_x	= _mm_mul_ps( lhs.components_x, rhs.components_x );
	const __m128d mul_y	= _mm_mul_ps( lhs.components_y, rhs.components_y );
	const __m128d mul_z	= _mm_mul_ps( lhs.components_z, rhs.components_z );
	const __m128d mul_w	= _mm_mul_ps( lhs.components_w, rhs.components_w );

	const __m128 add0	= _mm_add_ps( mul_x, mul_y );
	const __m128 add1	= _mm_add_ps( mul_z, mul_w );

	return _mm_add_ps( add0, add1 );
}



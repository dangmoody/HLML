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

#include <temper/temper.h>

TEMPER_TEST( TestArithmeticMultiplyScalar_double4 )
{
	const double4 a = HLML_CONSTRUCT( double4 ) { ( 2.0 ), ( 3.0 ), ( 4.0 ), ( 5.0 ) };
	const double b = 6.0;

	double4 c = quaternion_mul( a, b );

	TEMPER_EXPECT_TRUE( doubleeq( c.x, ( 12.0 ) ) );
	TEMPER_EXPECT_TRUE( doubleeq( c.y, ( 18.0 ) ) );
	TEMPER_EXPECT_TRUE( doubleeq( c.z, ( 24.0 ) ) );
	TEMPER_EXPECT_TRUE( doubleeq( c.w, ( 30.0 ) ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticMultiply_double4 )
{
	const double4 a = HLML_CONSTRUCT( double4 ) { ( 2.0 ), ( 3.0 ), ( 4.0 ), ( 5.0 ) };
	const double4 b = HLML_CONSTRUCT( double4 ) { ( 1.0 ), ( 3.0 ), ( 5.0 ), ( 7.0 ) };

	double4 c = quaternion_mul( a, b );

	TEMPER_EXPECT_TRUE( c.x == ( 22.0 ) );
	TEMPER_EXPECT_TRUE( c.y == ( 30.0 ) );
	TEMPER_EXPECT_TRUE( c.z == ( 56.0 ) );
	TEMPER_EXPECT_TRUE( c.w == ( 4.0 ) );
	TEMPER_EXPECT_TRUE( doubleeq( c.x, ( 22.0 ) ) );
	TEMPER_EXPECT_TRUE( doubleeq( c.y, ( 30.0 ) ) );
	TEMPER_EXPECT_TRUE( doubleeq( c.z, ( 56.0 ) ) );
	TEMPER_EXPECT_TRUE( doubleeq( c.w, ( 4.0 ) ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticLength_double4 )
{
	const double4 a = HLML_CONSTRUCT( double4 ) { ( 2.0 ), ( 3.0 ), ( 4.0 ), ( 5.0 ) };

	double b = quaternion_length( a );

	TEMPER_EXPECT_TRUE( doubleeq( b, ( 7.34846925735 ) ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticNormalize_double4 )
{
	const double4 a = HLML_CONSTRUCT( double4 ) { ( 2.0 ), ( 3.0 ), ( 4.0 ), ( 5.0 ) };

	double4 b = quaternion_normalize( a );

	TEMPER_EXPECT_TRUE( doubleeq( b.x, ( 0.272166 ) ) );
	TEMPER_EXPECT_TRUE( doubleeq( b.y, ( 0.408248 ) ) );
	TEMPER_EXPECT_TRUE( doubleeq( b.z, ( 0.544331 ) ) );
	TEMPER_EXPECT_TRUE( doubleeq( b.w, ( 0.680414 ) ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticConjugate_double4 )
{
	const double4 a = HLML_CONSTRUCT( double4 ) { ( 2.0 ), ( 3.0 ), ( 4.0 ), ( 5.0 ) };

	double4 b = quaternion_conjugate( a );

	TEMPER_EXPECT_TRUE( doubleeq( b.x, ( -2.000000 ) ) );
	TEMPER_EXPECT_TRUE( doubleeq( b.y, ( -3.000000 ) ) );
	TEMPER_EXPECT_TRUE( doubleeq( b.z, ( -4.000000 ) ) );
	TEMPER_EXPECT_TRUE( doubleeq( b.w, ( 5.000000 ) ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticInverse_double4 )
{
	const double4 a = HLML_CONSTRUCT( double4 ) { ( 2.0 ), ( 3.0 ), ( 4.0 ), ( 5.0 ) };

	double4 b = quaternion_inverse( a );

	TEMPER_EXPECT_TRUE( doubleeq( b.x, ( -0.037037 ) ) );
	TEMPER_EXPECT_TRUE( doubleeq( b.y, ( -0.0555556 ) ) );
	TEMPER_EXPECT_TRUE( doubleeq( b.z, ( -0.0740741 ) ) );
	TEMPER_EXPECT_TRUE( doubleeq( b.w, ( 0.092593 ) ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticVectorRotationByAngleAxis_double4 )
{
	const double3 vector = HLML_CONSTRUCT( double3 ) { 0.0, 1.0, 0.0 };
	const double3 axis = HLML_CONSTRUCT( double3 ) { 1.0, 0.0, 0.0 };
	const double angle = 1.570800;

	double3 rotated_vector = quaternion_rotate_vector_about_angle_axis( vector, angle, axis );

	TEMPER_EXPECT_TRUE( doubleeq( rotated_vector.x, ( 0.0 ) ) );
	TEMPER_EXPECT_TRUE( doubleeq( rotated_vector.y, ( 0.0 ) ) );
	TEMPER_EXPECT_TRUE( doubleeq( rotated_vector.z, ( 1.0 ) ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticLerp_double4 )
{
	const double4 a = HLML_CONSTRUCT( double4 ) { ( 0.0 ), ( 0.0 ), ( 0.0 ), ( 0.0 ) };
	const double4 b = HLML_CONSTRUCT( double4 ) { ( 1.0 ), ( 1.0 ), ( 1.0 ), ( 1.0 ) };

	double4 c = quaternion_lerp( a, b, 0.5 );

	TEMPER_EXPECT_TRUE( doubleeq( c.x, ( 0.5 ) ) );
	TEMPER_EXPECT_TRUE( doubleeq( c.y, ( 0.5 ) ) );
	TEMPER_EXPECT_TRUE( doubleeq( c.z, ( 0.5 ) ) );
	TEMPER_EXPECT_TRUE( doubleeq( c.w, ( 0.5 ) ) );

	TEMPER_PASS();
}

TEMPER_SUITE( Test_quaternion_double4 )
{
	TEMPER_RUN_TEST( TestArithmeticMultiplyScalar_double4 );
	TEMPER_RUN_TEST( TestArithmeticMultiply_double4 );
	TEMPER_RUN_TEST( TestArithmeticLength_double4 );
	TEMPER_RUN_TEST( TestArithmeticNormalize_double4 );
	TEMPER_RUN_TEST( TestArithmeticConjugate_double4 );
	TEMPER_RUN_TEST( TestArithmeticInverse_double4 );
	TEMPER_RUN_TEST( TestArithmeticVectorRotationByAngleAxis_double4 );
	TEMPER_RUN_TEST( TestArithmeticLerp_double4 );
}

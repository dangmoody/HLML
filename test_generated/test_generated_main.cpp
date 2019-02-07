#include <stdint.h>
#include <assert.h>
#include <memory.h>

#include "../out/gen/hlml_functions_vector.h"
#include "../out/gen/hlml_functions_matrix.h"

#include <stdio.h>

int main( int argc, char** argv ) {
	float3 a = float3( 1.0f, 1.0f, 1.0f );
	float3 b = float3( 2.0f, 3.0f, 4.0f );

	float3 c = a + b;

	printf( "c = (%f, %f, %f)\n", c.x, c.y, c.z );

	float3x4 m0 = float3x4(
		1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f, 0.0f
	);

	float3x4 m1 = float3x4(
		2.0f,  3.0f,  4.0f,  5.0f,
		6.0f,  7.0f,  8.0f,  9.0f,
		10.0f, 11.0f, 12.0f, 13.0f
	);

	float3x4 m2 = translate( m1, float2( 1.0f, 0.0f ) );
	float3x4 m3 = scale( m2, float3( 1.0f, 2.0f, 3.0f ) );
	float4x3 m4 = transpose( m3 );

//	float3x4 m2 = m0 + m1;
//
//	printf( "m2 =\n" );
//	printf( "(%f, %f, %f, %f)\n", m2.rows[0][0], m2.rows[0][1], m2.rows[0][2], m2.rows[0][3] );
//	printf( "(%f, %f, %f, %f)\n", m2.rows[1][0], m2.rows[1][1], m2.rows[1][2], m2.rows[1][3] );
//	printf( "(%f, %f, %f, %f)\n", m2.rows[2][0], m2.rows[2][1], m2.rows[2][2], m2.rows[2][3] );

	return 0;
}
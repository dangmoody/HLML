//#define TEST_TEMPLATE_IMPLEMENTATION
#include "test_template.h"

#include <stdio.h>

int main( int argc, char** argv ) {
	float3 a = float3( 1.0f, 1.0f, 1.0f );
	float3 b = float3( 2.0f, 3.0f, 4.0f );

	float3 c = a + b;

	printf( "c = (%f, %f, %f)\n", c.x, c.y, c.z );

	return 0;
}
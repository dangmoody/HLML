# Using HLML's SSE Functionality

**WARNING: HLML'S SIMD FUNCTIONALITY IS STILL IN PROGRESS AND IS SUBJECT TO CHANGE.**
-------------------

If you wanted to find the dot product of two vectors in HLML (in scalar), you'd call the `dot` function like so:
```C
float4 a = float4( 1.0f, 0.0f, 0.0f, 0.0f );
float4 b = float4( 0.0f, 1.0f, 0.0f, 0.0f );

float c = dot( a, b );
```

In the above example, each vector holds an X, Y, Z, and W component.

To call the SSE version of a HLML function, you'll need to do the following things:

1. Create and fill all data of the required input struct.
	* The struct follows the naming convention: `sse_input_<function>_<vector>_t` (where `<function>` is something like `dot` and `<vector>` is something like `float4`).
2. Create, or have ready, an SSE register to store the output.
	* Some functions, like `normalize_sse`, output to an array of registers.
2. Call the function of the same name with "`_sse`" appended on the end (For example: The SSE version `dot` in HLML would be `dot_sse`).

Therefore, an example of doing the dot product via SSE in HLML looks like this (for X, Y, Z, and W components):
```C
#include <hlml/gen/hlml_functions_vector_sse.h>

// these 2 arrays are just for example data only
// it's up to your app to re-arrange vectors into arrays of each component
// and load them into each register in the input data
float componentsLHS[4][4] =
{
	{ 0.000000f, 0.000000f, 0.000000f, 0.000000f }, // 4 x components
	{ 1.000000f, 1.000000f, 1.000000f, 1.000000f }, // 4 y components
	{ 0.000000f, 0.000000f, 0.000000f, 0.000000f }, // 4 z components
	{ 0.000000f, 0.000000f, 0.000000f, 0.000000f }  // 4 w components
};

float componentsRHS[4][4] =
{
	{  0.000000f,  0.000000f,  0.000000f,  0.000000f }, // 4 x components
	{ -1.000000f, -1.000000f, -1.000000f, -1.000000f }, // 4 y components
	{  0.000000f,  0.000000f,  0.000000f,  0.000000f }, // 4 z components
	{  0.000000f,  0.000000f,  0.000000f,  0.000000f }  // 4 w components
};

// here you fill the registers
// index 0 corresponds to X, index 1 corresponds to Y, etc.
sse_input_dot_float4_t in;

in.lhs[0] = _mm_load_ps( componentsLHS[0] );
in.lhs[1] = _mm_load_ps( componentsLHS[1] );
in.lhs[2] = _mm_load_ps( componentsLHS[2] );
in.lhs[3] = _mm_load_ps( componentsLHS[3] );

in.rhs[0] = _mm_load_ps( componentsRHS[0] );
in.rhs[1] = _mm_load_ps( componentsRHS[1] );
in.rhs[2] = _mm_load_ps( componentsRHS[2] );
in.rhs[3] = _mm_load_ps( componentsRHS[3] );

__m128 results;
dot_sse( &in, &results );
```

HLML's `dot_sse` function does 4 multiplications and 3 additions (for a `float4`) and puts through 32 floats.  This means that `dot_sse` does 7 operations total on 128 bytes at a time, compared to the scalar version, which does 7 arithmetic operations on 8 floats (or 32 bytes).

This pattern repeats across all SSE functions in HLML.

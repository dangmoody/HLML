# Using HLML's SSE Functionality

**WARNING: HLML'S SIMD FUNCTIONALITY IS STILL IN PROGRESS AND IS SUBJECT TO CHANGE.**
-------------------

HLML is designed such that changing between the scalar/SIMD versions of functions is as simple as possible, to allow for easier changing of code and better refactorability within your codebase.

If you wanted to, for example, find the dot product of two vectors in HLML (in scalar), you'd call the `dot` function like so:
```C
#include <hlml/gen/hlml_functions_vector.h>

float4 a = float4( 1.0f, 0.0f, 0.0f, 0.0f );
float4 b = float4( 0.0f, 1.0f, 0.0f, 0.0f );

float c = dot( a, b );
```

In the above example, each vector holds an X, Y, Z, and W component.

To call the SSE version of a HLML function, you'll need to do the following things:

1. Create and fill all data of the required input struct.
	* All input structs follow the same naming convention: `sse_input_<function>_<vector>_t` (where `<function>` is something like `dot` and `<vector>` is something like `float4`).
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

If you wanted to do the same for, say, just X and Y components, then all you'd need to do is remove the the Z and W component arrays, and change the input struct name to `sse_input_dot_float2_t`.

This naming convention repeats across all SSE functions in HLML.  It is written this way so that programmers can figure out the names of the input struct and function they need, without having to look it up constantly (however, you can always find everything in your locally generated documentation).

For a `float4` components HLML's `dot_sse` function does 4 multiplications and 3 additions and puts through 32 floats, which is 7 operations total on 128 bytes at a time - compared to the scalar version, which does 7 arithmetic operations on 8 floats (or 32 bytes) at a time.

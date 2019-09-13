# Using HLML's SSE Functionality

**WARNING: HLML'S SIMD FUNCTIONALITY IS STILL EXPERIMENTAL, IS NOT FINAL, AND IS SUBJECT TO CHANGE.**
-------------------

HLML is designed such that changing between the scalar/SIMD versions of functions is as simple as possible to allow for easier changing of code and better refactorability within your codebase.

If you wanted to, for example, find the dot product of two vectors in HLML (in scalar), you'd call the `dot` function like so:
```C
#include <hlml/gen/hlml_functions_vector.h>

float4 a = float4( 1.0f, 0.0f, 0.0f, 0.0f );
float4 b = float4( 0.0f, 1.0f, 0.0f, 0.0f );

float c = dot( a, b );
```

In the above example, each vector holds an X, Y, Z, and W component.

To call the SSE version of a HLML function, you'll need to do the following things:

1. Rename the vector/matrix type to `<type>_sse_t` where `<type>` is, for example, `float4`.
2. Replace each component for a SIMD register where each register holds 4 of each component (for example: element 0 of a `float4_sse_t` would hold 4 X components, element 1 holds 4 Y components, and so on).
3. Call the function of the same name with "`_sse`" appended on the end (For example: The SSE version `dot` in HLML would be `dot_sse`).

Therefore an example of doing the dot product via SSE in HLML looks like this (for X, Y, Z, and W components):
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
float4_sse_t a;
a.comp[0] = _mm_load_ps( componentsLHS[0] );	// x
a.comp[1] = _mm_load_ps( componentsLHS[1] );	// y
a.comp[2] = _mm_load_ps( componentsLHS[2] );	// z
a.comp[3] = _mm_load_ps( componentsLHS[3] );	// w

float4_sse_t b;
b.comp[0] = _mm_load_ps( componentsRHS[0] );	// x
b.comp[1] = _mm_load_ps( componentsRHS[1] );	// y
b.comp[2] = _mm_load_ps( componentsRHS[2] );	// z
b.comp[3] = _mm_load_ps( componentsRHS[3] );	// w

__m128 results;
dot_sse( &a, &b, &results );
```

In the above example, all the X components (element 0) of `a` will get multiplied by all the X components in `b` and so on.  The resulting mutliplications will then get added together with each result put into each register.

Currently all HLML SSE functions work in chunks of 4 for each component (that is: each component array holds 4 components at a time).

If you wanted to do the same for, say, just X and Y components, then all you'd need to do is remove the the Z and W component arrays, and change the input struct name to `float2_sse_t`.

This naming convention repeats across all SIMD functions in HLML.  It is written this way so that programmers can figure out the names of the input struct and function call they need without having to look it up constantly (however you can always find everything in your locally generated documentation).

For a `float4` HLML's `dot_sse` function does 4 multiplications and 3 additions and puts through 32 floats, which is 7 operations total on 128 bytes at a time, compared to the scalar version which does 7 arithmetic operations on 8 floats (32 bytes) at a time.

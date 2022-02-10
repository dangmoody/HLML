# Using HLML's SSE Functionality

**WARNING: HLML'S SIMD API IS STILL VERY EXPERIMENTAL, IS NOT FINAL, AND IS SUBJECT TO CHANGE.**
-------------------

There are few things you should know before trying to use HLML's SIMD API:
* It is still very experimental, is not final, and is subject to change (that's twice you've been warned).
* Currently only `__m128` is supported.  More may be added later.
* Currently only SSE is supported.  ARM Neon support is coming in a future update.
* Currently support only exists for scalar and vector types.  Support for matrix types is coming in a future update.
* Given this is part of HLML's API is still experimental feedback is welcome and encouraged.

If you wanted to, for example, find the dot product of two vectors in HLML (in scalar), you'd call the `dot` function like so:
```C
#include <hlml/hlml.h>

float4 a = { 1.0f, 0.0f, 0.0f, 0.0f };
float4 b = { 0.0f, 1.0f, 0.0f, 0.0f };

// in C:
float d = float4_dot( &a, &b );

// in C++:
float d = dot( a, b );
```

To do the same thing using HLML's SSE API:
```C
#include <hlml/hlml.h>

__m128 lhs_x = _mm_set_ps( x_data );
__m128 lhs_y = _mm_set_ps( y_data );
__m128 lhs_z = _mm_set_ps( z_data );
__m128 lhs_w = _mm_set_ps( w_data );

__m128 rhs_x = _mm_set_ps( x_data );
__m128 rhs_y = _mm_set_ps( y_data );
__m128 rhs_z = _mm_set_ps( z_data );
__m128 rhs_w = _mm_set_ps( w_data );

// in C:
__m128 dots = float4_dot_sse( lhs_x, lhs_y, lhs_z, lhs_w,
	                          rhs_x, rhs_y, rhs_z, rhs_w );

// in C++:
__m128 dots = dot_sse( lhs_x, lhs_y, lhs_z, lhs_w,
	                   rhs_x, rhs_y, rhs_z, rhs_w );
```

Both implementations of HLML's SSE dot product function produces the following ASM in Clang:
```ASM
mulps xmm0, xmm4
mulps xmm1, xmm5
addps xmm0, xmm1
mulps xmm2, xmm6
mulps xmm3, xmm7
addps xmm3, xmm2
addps xmm0, xmm3
ret
```

The above example is doing the dot product of 4 vectors using only 7 operations, which is a lot quicker than calling the dot product function 4 times in scalar.

HLML's SIMD API is reliant on the programmer passing in their data as "vertical streams".  That is: All the `X` components are grouped together, as are the `Y` and `Z` components, and so on.  This typically requires the programmer to do additional work and re-organise their data layout so that all vector components are split from each other.  However, if that work is done, the performance payoffs (as shown above) can be significant.

See the files `hlml_functions_scalar_sse.h` and `hlml_functions_vector_sse.h` to see the full SSE API in its current form.

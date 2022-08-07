/*
===========================================================================

HLML
v2.2.0

MIT License:

Copyright (c) 2019 Dan Moody (daniel.guy.moody@gmail.com).

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

TEMPER_PARAMETRIC( Test_int2_Swizzle_xx, TEMPER_FLAG_SHOULD_RUN, const int2& vec, const int2& expectedAnswer )
{
	int2 vecCopy = vec;

	int2 vecSwizzled = vecCopy.xx;
	TEMPER_CHECK_TRUE( vecSwizzled == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_xx,
	int2( 0, 0 ),
	int2( 0, 0 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_xx,
	int2( 0, 1 ),
	int2( 0, 0 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_xx,
	int2( 3, 2 ),
	int2( 3, 3 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_xx,
	int2( 10, 20 ),
	int2( 10, 10 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_xx,
	int2( 40, 30 ),
	int2( 40, 40 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_xx,
	int2( 69, 420 ),
	int2( 69, 69 )
);

TEMPER_PARAMETRIC( Test_int2_Swizzle_yx, TEMPER_FLAG_SHOULD_RUN, const int2& vec, const int2& expectedAnswer )
{
	int2 vecCopy = vec;

	int2 vecSwizzled = vecCopy.yx;
	TEMPER_CHECK_TRUE( vecSwizzled == expectedAnswer );

	// write swizzle test
	{
		int32_t old_y = vecCopy.y;
		int32_t old_x = vecCopy.x;

		vecCopy.yx = vecCopy.xy;

		TEMPER_CHECK_TRUE( vecCopy.x == old_y );
		TEMPER_CHECK_TRUE( vecCopy.y == old_x );
	}
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_yx,
	int2( 0, 0 ),
	int2( 0, 0 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_yx,
	int2( 0, 1 ),
	int2( 1, 0 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_yx,
	int2( 3, 2 ),
	int2( 2, 3 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_yx,
	int2( 10, 20 ),
	int2( 20, 10 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_yx,
	int2( 40, 30 ),
	int2( 30, 40 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_yx,
	int2( 69, 420 ),
	int2( 420, 69 )
);

TEMPER_PARAMETRIC( Test_int2_Swizzle_xy, TEMPER_FLAG_SHOULD_RUN, const int2& vec, const int2& expectedAnswer )
{
	int2 vecCopy = vec;

	int2 vecSwizzled = vecCopy.xy;
	TEMPER_CHECK_TRUE( vecSwizzled == expectedAnswer );

	// write swizzle test
	{
		int32_t old_x = vecCopy.x;
		int32_t old_y = vecCopy.y;

		vecCopy.xy = vecCopy.yx;

		TEMPER_CHECK_TRUE( vecCopy.y == old_x );
		TEMPER_CHECK_TRUE( vecCopy.x == old_y );
	}
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_xy,
	int2( 0, 0 ),
	int2( 0, 0 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_xy,
	int2( 0, 1 ),
	int2( 0, 1 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_xy,
	int2( 3, 2 ),
	int2( 3, 2 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_xy,
	int2( 10, 20 ),
	int2( 10, 20 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_xy,
	int2( 40, 30 ),
	int2( 40, 30 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_xy,
	int2( 69, 420 ),
	int2( 69, 420 )
);

TEMPER_PARAMETRIC( Test_int2_Swizzle_yy, TEMPER_FLAG_SHOULD_RUN, const int2& vec, const int2& expectedAnswer )
{
	int2 vecCopy = vec;

	int2 vecSwizzled = vecCopy.yy;
	TEMPER_CHECK_TRUE( vecSwizzled == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_yy,
	int2( 0, 0 ),
	int2( 0, 0 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_yy,
	int2( 0, 1 ),
	int2( 1, 1 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_yy,
	int2( 3, 2 ),
	int2( 2, 2 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_yy,
	int2( 10, 20 ),
	int2( 20, 20 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_yy,
	int2( 40, 30 ),
	int2( 30, 30 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_yy,
	int2( 69, 420 ),
	int2( 420, 420 )
);

TEMPER_PARAMETRIC( Test_int2_Swizzle_xxx, TEMPER_FLAG_SHOULD_RUN, const int2& vec, const int3& expectedAnswer )
{
	int2 vecCopy = vec;

	int3 vecSwizzled = vecCopy.xxx;
	TEMPER_CHECK_TRUE( vecSwizzled == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_xxx,
	int2( 0, 0 ),
	int3( 0, 0, 0 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_xxx,
	int2( 0, 1 ),
	int3( 0, 0, 0 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_xxx,
	int2( 3, 2 ),
	int3( 3, 3, 3 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_xxx,
	int2( 10, 20 ),
	int3( 10, 10, 10 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_xxx,
	int2( 40, 30 ),
	int3( 40, 40, 40 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_xxx,
	int2( 69, 420 ),
	int3( 69, 69, 69 )
);

TEMPER_PARAMETRIC( Test_int2_Swizzle_yxx, TEMPER_FLAG_SHOULD_RUN, const int2& vec, const int3& expectedAnswer )
{
	int2 vecCopy = vec;

	int3 vecSwizzled = vecCopy.yxx;
	TEMPER_CHECK_TRUE( vecSwizzled == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_yxx,
	int2( 0, 0 ),
	int3( 0, 0, 0 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_yxx,
	int2( 0, 1 ),
	int3( 1, 0, 0 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_yxx,
	int2( 3, 2 ),
	int3( 2, 3, 3 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_yxx,
	int2( 10, 20 ),
	int3( 20, 10, 10 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_yxx,
	int2( 40, 30 ),
	int3( 30, 40, 40 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_yxx,
	int2( 69, 420 ),
	int3( 420, 69, 69 )
);

TEMPER_PARAMETRIC( Test_int2_Swizzle_xyx, TEMPER_FLAG_SHOULD_RUN, const int2& vec, const int3& expectedAnswer )
{
	int2 vecCopy = vec;

	int3 vecSwizzled = vecCopy.xyx;
	TEMPER_CHECK_TRUE( vecSwizzled == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_xyx,
	int2( 0, 0 ),
	int3( 0, 0, 0 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_xyx,
	int2( 0, 1 ),
	int3( 0, 1, 0 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_xyx,
	int2( 3, 2 ),
	int3( 3, 2, 3 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_xyx,
	int2( 10, 20 ),
	int3( 10, 20, 10 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_xyx,
	int2( 40, 30 ),
	int3( 40, 30, 40 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_xyx,
	int2( 69, 420 ),
	int3( 69, 420, 69 )
);

TEMPER_PARAMETRIC( Test_int2_Swizzle_yyx, TEMPER_FLAG_SHOULD_RUN, const int2& vec, const int3& expectedAnswer )
{
	int2 vecCopy = vec;

	int3 vecSwizzled = vecCopy.yyx;
	TEMPER_CHECK_TRUE( vecSwizzled == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_yyx,
	int2( 0, 0 ),
	int3( 0, 0, 0 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_yyx,
	int2( 0, 1 ),
	int3( 1, 1, 0 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_yyx,
	int2( 3, 2 ),
	int3( 2, 2, 3 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_yyx,
	int2( 10, 20 ),
	int3( 20, 20, 10 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_yyx,
	int2( 40, 30 ),
	int3( 30, 30, 40 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_yyx,
	int2( 69, 420 ),
	int3( 420, 420, 69 )
);

TEMPER_PARAMETRIC( Test_int2_Swizzle_xxy, TEMPER_FLAG_SHOULD_RUN, const int2& vec, const int3& expectedAnswer )
{
	int2 vecCopy = vec;

	int3 vecSwizzled = vecCopy.xxy;
	TEMPER_CHECK_TRUE( vecSwizzled == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_xxy,
	int2( 0, 0 ),
	int3( 0, 0, 0 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_xxy,
	int2( 0, 1 ),
	int3( 0, 0, 1 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_xxy,
	int2( 3, 2 ),
	int3( 3, 3, 2 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_xxy,
	int2( 10, 20 ),
	int3( 10, 10, 20 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_xxy,
	int2( 40, 30 ),
	int3( 40, 40, 30 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_xxy,
	int2( 69, 420 ),
	int3( 69, 69, 420 )
);

TEMPER_PARAMETRIC( Test_int2_Swizzle_yxy, TEMPER_FLAG_SHOULD_RUN, const int2& vec, const int3& expectedAnswer )
{
	int2 vecCopy = vec;

	int3 vecSwizzled = vecCopy.yxy;
	TEMPER_CHECK_TRUE( vecSwizzled == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_yxy,
	int2( 0, 0 ),
	int3( 0, 0, 0 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_yxy,
	int2( 0, 1 ),
	int3( 1, 0, 1 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_yxy,
	int2( 3, 2 ),
	int3( 2, 3, 2 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_yxy,
	int2( 10, 20 ),
	int3( 20, 10, 20 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_yxy,
	int2( 40, 30 ),
	int3( 30, 40, 30 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_yxy,
	int2( 69, 420 ),
	int3( 420, 69, 420 )
);

TEMPER_PARAMETRIC( Test_int2_Swizzle_xyy, TEMPER_FLAG_SHOULD_RUN, const int2& vec, const int3& expectedAnswer )
{
	int2 vecCopy = vec;

	int3 vecSwizzled = vecCopy.xyy;
	TEMPER_CHECK_TRUE( vecSwizzled == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_xyy,
	int2( 0, 0 ),
	int3( 0, 0, 0 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_xyy,
	int2( 0, 1 ),
	int3( 0, 1, 1 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_xyy,
	int2( 3, 2 ),
	int3( 3, 2, 2 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_xyy,
	int2( 10, 20 ),
	int3( 10, 20, 20 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_xyy,
	int2( 40, 30 ),
	int3( 40, 30, 30 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_xyy,
	int2( 69, 420 ),
	int3( 69, 420, 420 )
);

TEMPER_PARAMETRIC( Test_int2_Swizzle_yyy, TEMPER_FLAG_SHOULD_RUN, const int2& vec, const int3& expectedAnswer )
{
	int2 vecCopy = vec;

	int3 vecSwizzled = vecCopy.yyy;
	TEMPER_CHECK_TRUE( vecSwizzled == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_yyy,
	int2( 0, 0 ),
	int3( 0, 0, 0 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_yyy,
	int2( 0, 1 ),
	int3( 1, 1, 1 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_yyy,
	int2( 3, 2 ),
	int3( 2, 2, 2 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_yyy,
	int2( 10, 20 ),
	int3( 20, 20, 20 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_yyy,
	int2( 40, 30 ),
	int3( 30, 30, 30 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_yyy,
	int2( 69, 420 ),
	int3( 420, 420, 420 )
);

TEMPER_PARAMETRIC( Test_int2_Swizzle_xxxx, TEMPER_FLAG_SHOULD_RUN, const int2& vec, const int4& expectedAnswer )
{
	int2 vecCopy = vec;

	int4 vecSwizzled = vecCopy.xxxx;
	TEMPER_CHECK_TRUE( vecSwizzled == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_xxxx,
	int2( 0, 0 ),
	int4( 0, 0, 0, 0 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_xxxx,
	int2( 0, 1 ),
	int4( 0, 0, 0, 0 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_xxxx,
	int2( 3, 2 ),
	int4( 3, 3, 3, 3 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_xxxx,
	int2( 10, 20 ),
	int4( 10, 10, 10, 10 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_xxxx,
	int2( 40, 30 ),
	int4( 40, 40, 40, 40 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_xxxx,
	int2( 69, 420 ),
	int4( 69, 69, 69, 69 )
);

TEMPER_PARAMETRIC( Test_int2_Swizzle_yxxx, TEMPER_FLAG_SHOULD_RUN, const int2& vec, const int4& expectedAnswer )
{
	int2 vecCopy = vec;

	int4 vecSwizzled = vecCopy.yxxx;
	TEMPER_CHECK_TRUE( vecSwizzled == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_yxxx,
	int2( 0, 0 ),
	int4( 0, 0, 0, 0 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_yxxx,
	int2( 0, 1 ),
	int4( 1, 0, 0, 0 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_yxxx,
	int2( 3, 2 ),
	int4( 2, 3, 3, 3 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_yxxx,
	int2( 10, 20 ),
	int4( 20, 10, 10, 10 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_yxxx,
	int2( 40, 30 ),
	int4( 30, 40, 40, 40 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_yxxx,
	int2( 69, 420 ),
	int4( 420, 69, 69, 69 )
);

TEMPER_PARAMETRIC( Test_int2_Swizzle_xyxx, TEMPER_FLAG_SHOULD_RUN, const int2& vec, const int4& expectedAnswer )
{
	int2 vecCopy = vec;

	int4 vecSwizzled = vecCopy.xyxx;
	TEMPER_CHECK_TRUE( vecSwizzled == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_xyxx,
	int2( 0, 0 ),
	int4( 0, 0, 0, 0 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_xyxx,
	int2( 0, 1 ),
	int4( 0, 1, 0, 0 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_xyxx,
	int2( 3, 2 ),
	int4( 3, 2, 3, 3 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_xyxx,
	int2( 10, 20 ),
	int4( 10, 20, 10, 10 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_xyxx,
	int2( 40, 30 ),
	int4( 40, 30, 40, 40 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_xyxx,
	int2( 69, 420 ),
	int4( 69, 420, 69, 69 )
);

TEMPER_PARAMETRIC( Test_int2_Swizzle_yyxx, TEMPER_FLAG_SHOULD_RUN, const int2& vec, const int4& expectedAnswer )
{
	int2 vecCopy = vec;

	int4 vecSwizzled = vecCopy.yyxx;
	TEMPER_CHECK_TRUE( vecSwizzled == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_yyxx,
	int2( 0, 0 ),
	int4( 0, 0, 0, 0 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_yyxx,
	int2( 0, 1 ),
	int4( 1, 1, 0, 0 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_yyxx,
	int2( 3, 2 ),
	int4( 2, 2, 3, 3 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_yyxx,
	int2( 10, 20 ),
	int4( 20, 20, 10, 10 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_yyxx,
	int2( 40, 30 ),
	int4( 30, 30, 40, 40 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_yyxx,
	int2( 69, 420 ),
	int4( 420, 420, 69, 69 )
);

TEMPER_PARAMETRIC( Test_int2_Swizzle_xxyx, TEMPER_FLAG_SHOULD_RUN, const int2& vec, const int4& expectedAnswer )
{
	int2 vecCopy = vec;

	int4 vecSwizzled = vecCopy.xxyx;
	TEMPER_CHECK_TRUE( vecSwizzled == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_xxyx,
	int2( 0, 0 ),
	int4( 0, 0, 0, 0 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_xxyx,
	int2( 0, 1 ),
	int4( 0, 0, 1, 0 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_xxyx,
	int2( 3, 2 ),
	int4( 3, 3, 2, 3 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_xxyx,
	int2( 10, 20 ),
	int4( 10, 10, 20, 10 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_xxyx,
	int2( 40, 30 ),
	int4( 40, 40, 30, 40 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_xxyx,
	int2( 69, 420 ),
	int4( 69, 69, 420, 69 )
);

TEMPER_PARAMETRIC( Test_int2_Swizzle_yxyx, TEMPER_FLAG_SHOULD_RUN, const int2& vec, const int4& expectedAnswer )
{
	int2 vecCopy = vec;

	int4 vecSwizzled = vecCopy.yxyx;
	TEMPER_CHECK_TRUE( vecSwizzled == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_yxyx,
	int2( 0, 0 ),
	int4( 0, 0, 0, 0 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_yxyx,
	int2( 0, 1 ),
	int4( 1, 0, 1, 0 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_yxyx,
	int2( 3, 2 ),
	int4( 2, 3, 2, 3 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_yxyx,
	int2( 10, 20 ),
	int4( 20, 10, 20, 10 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_yxyx,
	int2( 40, 30 ),
	int4( 30, 40, 30, 40 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_yxyx,
	int2( 69, 420 ),
	int4( 420, 69, 420, 69 )
);

TEMPER_PARAMETRIC( Test_int2_Swizzle_xyyx, TEMPER_FLAG_SHOULD_RUN, const int2& vec, const int4& expectedAnswer )
{
	int2 vecCopy = vec;

	int4 vecSwizzled = vecCopy.xyyx;
	TEMPER_CHECK_TRUE( vecSwizzled == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_xyyx,
	int2( 0, 0 ),
	int4( 0, 0, 0, 0 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_xyyx,
	int2( 0, 1 ),
	int4( 0, 1, 1, 0 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_xyyx,
	int2( 3, 2 ),
	int4( 3, 2, 2, 3 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_xyyx,
	int2( 10, 20 ),
	int4( 10, 20, 20, 10 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_xyyx,
	int2( 40, 30 ),
	int4( 40, 30, 30, 40 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_xyyx,
	int2( 69, 420 ),
	int4( 69, 420, 420, 69 )
);

TEMPER_PARAMETRIC( Test_int2_Swizzle_yyyx, TEMPER_FLAG_SHOULD_RUN, const int2& vec, const int4& expectedAnswer )
{
	int2 vecCopy = vec;

	int4 vecSwizzled = vecCopy.yyyx;
	TEMPER_CHECK_TRUE( vecSwizzled == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_yyyx,
	int2( 0, 0 ),
	int4( 0, 0, 0, 0 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_yyyx,
	int2( 0, 1 ),
	int4( 1, 1, 1, 0 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_yyyx,
	int2( 3, 2 ),
	int4( 2, 2, 2, 3 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_yyyx,
	int2( 10, 20 ),
	int4( 20, 20, 20, 10 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_yyyx,
	int2( 40, 30 ),
	int4( 30, 30, 30, 40 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_yyyx,
	int2( 69, 420 ),
	int4( 420, 420, 420, 69 )
);

TEMPER_PARAMETRIC( Test_int2_Swizzle_xxxy, TEMPER_FLAG_SHOULD_RUN, const int2& vec, const int4& expectedAnswer )
{
	int2 vecCopy = vec;

	int4 vecSwizzled = vecCopy.xxxy;
	TEMPER_CHECK_TRUE( vecSwizzled == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_xxxy,
	int2( 0, 0 ),
	int4( 0, 0, 0, 0 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_xxxy,
	int2( 0, 1 ),
	int4( 0, 0, 0, 1 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_xxxy,
	int2( 3, 2 ),
	int4( 3, 3, 3, 2 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_xxxy,
	int2( 10, 20 ),
	int4( 10, 10, 10, 20 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_xxxy,
	int2( 40, 30 ),
	int4( 40, 40, 40, 30 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_xxxy,
	int2( 69, 420 ),
	int4( 69, 69, 69, 420 )
);

TEMPER_PARAMETRIC( Test_int2_Swizzle_yxxy, TEMPER_FLAG_SHOULD_RUN, const int2& vec, const int4& expectedAnswer )
{
	int2 vecCopy = vec;

	int4 vecSwizzled = vecCopy.yxxy;
	TEMPER_CHECK_TRUE( vecSwizzled == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_yxxy,
	int2( 0, 0 ),
	int4( 0, 0, 0, 0 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_yxxy,
	int2( 0, 1 ),
	int4( 1, 0, 0, 1 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_yxxy,
	int2( 3, 2 ),
	int4( 2, 3, 3, 2 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_yxxy,
	int2( 10, 20 ),
	int4( 20, 10, 10, 20 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_yxxy,
	int2( 40, 30 ),
	int4( 30, 40, 40, 30 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_yxxy,
	int2( 69, 420 ),
	int4( 420, 69, 69, 420 )
);

TEMPER_PARAMETRIC( Test_int2_Swizzle_xyxy, TEMPER_FLAG_SHOULD_RUN, const int2& vec, const int4& expectedAnswer )
{
	int2 vecCopy = vec;

	int4 vecSwizzled = vecCopy.xyxy;
	TEMPER_CHECK_TRUE( vecSwizzled == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_xyxy,
	int2( 0, 0 ),
	int4( 0, 0, 0, 0 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_xyxy,
	int2( 0, 1 ),
	int4( 0, 1, 0, 1 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_xyxy,
	int2( 3, 2 ),
	int4( 3, 2, 3, 2 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_xyxy,
	int2( 10, 20 ),
	int4( 10, 20, 10, 20 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_xyxy,
	int2( 40, 30 ),
	int4( 40, 30, 40, 30 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_xyxy,
	int2( 69, 420 ),
	int4( 69, 420, 69, 420 )
);

TEMPER_PARAMETRIC( Test_int2_Swizzle_yyxy, TEMPER_FLAG_SHOULD_RUN, const int2& vec, const int4& expectedAnswer )
{
	int2 vecCopy = vec;

	int4 vecSwizzled = vecCopy.yyxy;
	TEMPER_CHECK_TRUE( vecSwizzled == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_yyxy,
	int2( 0, 0 ),
	int4( 0, 0, 0, 0 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_yyxy,
	int2( 0, 1 ),
	int4( 1, 1, 0, 1 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_yyxy,
	int2( 3, 2 ),
	int4( 2, 2, 3, 2 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_yyxy,
	int2( 10, 20 ),
	int4( 20, 20, 10, 20 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_yyxy,
	int2( 40, 30 ),
	int4( 30, 30, 40, 30 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_yyxy,
	int2( 69, 420 ),
	int4( 420, 420, 69, 420 )
);

TEMPER_PARAMETRIC( Test_int2_Swizzle_xxyy, TEMPER_FLAG_SHOULD_RUN, const int2& vec, const int4& expectedAnswer )
{
	int2 vecCopy = vec;

	int4 vecSwizzled = vecCopy.xxyy;
	TEMPER_CHECK_TRUE( vecSwizzled == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_xxyy,
	int2( 0, 0 ),
	int4( 0, 0, 0, 0 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_xxyy,
	int2( 0, 1 ),
	int4( 0, 0, 1, 1 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_xxyy,
	int2( 3, 2 ),
	int4( 3, 3, 2, 2 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_xxyy,
	int2( 10, 20 ),
	int4( 10, 10, 20, 20 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_xxyy,
	int2( 40, 30 ),
	int4( 40, 40, 30, 30 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_xxyy,
	int2( 69, 420 ),
	int4( 69, 69, 420, 420 )
);

TEMPER_PARAMETRIC( Test_int2_Swizzle_yxyy, TEMPER_FLAG_SHOULD_RUN, const int2& vec, const int4& expectedAnswer )
{
	int2 vecCopy = vec;

	int4 vecSwizzled = vecCopy.yxyy;
	TEMPER_CHECK_TRUE( vecSwizzled == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_yxyy,
	int2( 0, 0 ),
	int4( 0, 0, 0, 0 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_yxyy,
	int2( 0, 1 ),
	int4( 1, 0, 1, 1 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_yxyy,
	int2( 3, 2 ),
	int4( 2, 3, 2, 2 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_yxyy,
	int2( 10, 20 ),
	int4( 20, 10, 20, 20 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_yxyy,
	int2( 40, 30 ),
	int4( 30, 40, 30, 30 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_yxyy,
	int2( 69, 420 ),
	int4( 420, 69, 420, 420 )
);

TEMPER_PARAMETRIC( Test_int2_Swizzle_xyyy, TEMPER_FLAG_SHOULD_RUN, const int2& vec, const int4& expectedAnswer )
{
	int2 vecCopy = vec;

	int4 vecSwizzled = vecCopy.xyyy;
	TEMPER_CHECK_TRUE( vecSwizzled == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_xyyy,
	int2( 0, 0 ),
	int4( 0, 0, 0, 0 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_xyyy,
	int2( 0, 1 ),
	int4( 0, 1, 1, 1 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_xyyy,
	int2( 3, 2 ),
	int4( 3, 2, 2, 2 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_xyyy,
	int2( 10, 20 ),
	int4( 10, 20, 20, 20 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_xyyy,
	int2( 40, 30 ),
	int4( 40, 30, 30, 30 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_xyyy,
	int2( 69, 420 ),
	int4( 69, 420, 420, 420 )
);

TEMPER_PARAMETRIC( Test_int2_Swizzle_yyyy, TEMPER_FLAG_SHOULD_RUN, const int2& vec, const int4& expectedAnswer )
{
	int2 vecCopy = vec;

	int4 vecSwizzled = vecCopy.yyyy;
	TEMPER_CHECK_TRUE( vecSwizzled == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_yyyy,
	int2( 0, 0 ),
	int4( 0, 0, 0, 0 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_yyyy,
	int2( 0, 1 ),
	int4( 1, 1, 1, 1 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_yyyy,
	int2( 3, 2 ),
	int4( 2, 2, 2, 2 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_yyyy,
	int2( 10, 20 ),
	int4( 20, 20, 20, 20 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_yyyy,
	int2( 40, 30 ),
	int4( 30, 30, 30, 30 )
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int2_Swizzle_yyyy,
	int2( 69, 420 ),
	int4( 420, 420, 420, 420 )
);


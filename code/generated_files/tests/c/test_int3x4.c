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

TEMPER_PARAMETRIC( Test_int3x4_less_than, TEMPER_FLAG_SHOULD_RUN, const int3x4* lhs, const int3x4* rhs, const bool3x4* expectedAnswer )
{
	bool3x4 actualResult = int3x4_less_than( lhs, rhs );
	TEMPER_CHECK_TRUE( bool3x4_equals( &actualResult, expectedAnswer ) );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int3x4_less_than,
	&(int3x4)
	{
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0
	},
	&(int3x4)
	{
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0
	},
	&(bool3x4)
	{
		false, false, false, false,
		false, false, false, false,
		false, false, false, false
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int3x4_less_than,
	&(int3x4)
	{
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0
	},
	&(int3x4)
	{
		1, 1, 1, 1,
		1, 1, 1, 1,
		1, 1, 1, 1
	},
	&(bool3x4)
	{
		true, true, true, true,
		true, true, true, true,
		true, true, true, true
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int3x4_less_than,
	&(int3x4)
	{
		1, 1, 1, 1,
		1, 1, 1, 1,
		1, 1, 1, 1
	},
	&(int3x4)
	{
		1, 1, 1, 1,
		1, 1, 1, 1,
		1, 1, 1, 1
	},
	&(bool3x4)
	{
		false, false, false, false,
		false, false, false, false,
		false, false, false, false
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int3x4_less_than,
	&(int3x4)
	{
		1, 1, 1, 1,
		1, 1, 1, 1,
		1, 1, 1, 1
	},
	&(int3x4)
	{
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0
	},
	&(bool3x4)
	{
		false, false, false, false,
		false, false, false, false,
		false, false, false, false
	}
);

TEMPER_PARAMETRIC( Test_int3x4_less_than_equal, TEMPER_FLAG_SHOULD_RUN, const int3x4* lhs, const int3x4* rhs, const bool3x4* expectedAnswer )
{
	bool3x4 actualResult = int3x4_less_than_equal( lhs, rhs );
	TEMPER_CHECK_TRUE( bool3x4_equals( &actualResult, expectedAnswer ) );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int3x4_less_than_equal,
	&(int3x4)
	{
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0
	},
	&(int3x4)
	{
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0
	},
	&(bool3x4)
	{
		true, true, true, true,
		true, true, true, true,
		true, true, true, true
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int3x4_less_than_equal,
	&(int3x4)
	{
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0
	},
	&(int3x4)
	{
		1, 1, 1, 1,
		1, 1, 1, 1,
		1, 1, 1, 1
	},
	&(bool3x4)
	{
		true, true, true, true,
		true, true, true, true,
		true, true, true, true
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int3x4_less_than_equal,
	&(int3x4)
	{
		1, 1, 1, 1,
		1, 1, 1, 1,
		1, 1, 1, 1
	},
	&(int3x4)
	{
		1, 1, 1, 1,
		1, 1, 1, 1,
		1, 1, 1, 1
	},
	&(bool3x4)
	{
		true, true, true, true,
		true, true, true, true,
		true, true, true, true
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int3x4_less_than_equal,
	&(int3x4)
	{
		1, 1, 1, 1,
		1, 1, 1, 1,
		1, 1, 1, 1
	},
	&(int3x4)
	{
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0
	},
	&(bool3x4)
	{
		false, false, false, false,
		false, false, false, false,
		false, false, false, false
	}
);

TEMPER_PARAMETRIC( Test_int3x4_greater_than, TEMPER_FLAG_SHOULD_RUN, const int3x4* lhs, const int3x4* rhs, const bool3x4* expectedAnswer )
{
	bool3x4 actualResult = int3x4_greater_than( lhs, rhs );
	TEMPER_CHECK_TRUE( bool3x4_equals( &actualResult, expectedAnswer ) );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int3x4_greater_than,
	&(int3x4)
	{
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0
	},
	&(int3x4)
	{
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0
	},
	&(bool3x4)
	{
		false, false, false, false,
		false, false, false, false,
		false, false, false, false
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int3x4_greater_than,
	&(int3x4)
	{
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0
	},
	&(int3x4)
	{
		1, 1, 1, 1,
		1, 1, 1, 1,
		1, 1, 1, 1
	},
	&(bool3x4)
	{
		false, false, false, false,
		false, false, false, false,
		false, false, false, false
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int3x4_greater_than,
	&(int3x4)
	{
		1, 1, 1, 1,
		1, 1, 1, 1,
		1, 1, 1, 1
	},
	&(int3x4)
	{
		1, 1, 1, 1,
		1, 1, 1, 1,
		1, 1, 1, 1
	},
	&(bool3x4)
	{
		false, false, false, false,
		false, false, false, false,
		false, false, false, false
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int3x4_greater_than,
	&(int3x4)
	{
		1, 1, 1, 1,
		1, 1, 1, 1,
		1, 1, 1, 1
	},
	&(int3x4)
	{
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0
	},
	&(bool3x4)
	{
		true, true, true, true,
		true, true, true, true,
		true, true, true, true
	}
);

TEMPER_PARAMETRIC( Test_int3x4_greater_than_equal, TEMPER_FLAG_SHOULD_RUN, const int3x4* lhs, const int3x4* rhs, const bool3x4* expectedAnswer )
{
	bool3x4 actualResult = int3x4_greater_than_equal( lhs, rhs );
	TEMPER_CHECK_TRUE( bool3x4_equals( &actualResult, expectedAnswer ) );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int3x4_greater_than_equal,
	&(int3x4)
	{
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0
	},
	&(int3x4)
	{
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0
	},
	&(bool3x4)
	{
		true, true, true, true,
		true, true, true, true,
		true, true, true, true
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int3x4_greater_than_equal,
	&(int3x4)
	{
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0
	},
	&(int3x4)
	{
		1, 1, 1, 1,
		1, 1, 1, 1,
		1, 1, 1, 1
	},
	&(bool3x4)
	{
		false, false, false, false,
		false, false, false, false,
		false, false, false, false
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int3x4_greater_than_equal,
	&(int3x4)
	{
		1, 1, 1, 1,
		1, 1, 1, 1,
		1, 1, 1, 1
	},
	&(int3x4)
	{
		1, 1, 1, 1,
		1, 1, 1, 1,
		1, 1, 1, 1
	},
	&(bool3x4)
	{
		true, true, true, true,
		true, true, true, true,
		true, true, true, true
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int3x4_greater_than_equal,
	&(int3x4)
	{
		1, 1, 1, 1,
		1, 1, 1, 1,
		1, 1, 1, 1
	},
	&(int3x4)
	{
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0
	},
	&(bool3x4)
	{
		true, true, true, true,
		true, true, true, true,
		true, true, true, true
	}
);

TEMPER_PARAMETRIC( Test_int3x4_cadds, TEMPER_FLAG_SHOULD_RUN, const int3x4* lhs, const int32_t rhs, const int3x4* expectedAnswer )
{
	int3x4 actualResult = int3x4_cadds( lhs, rhs );
	TEMPER_CHECK_TRUE( int3x4_equals( &actualResult, expectedAnswer ) );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int3x4_cadds,
	&(int3x4)
	{
		1, 1, 1, 1,
		1, 1, 1, 1,
		1, 1, 1, 1
	},
	1,
	&(int3x4)
	{
		2, 2, 2, 2,
		2, 2, 2, 2,
		2, 2, 2, 2
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int3x4_cadds,
	&(int3x4)
	{
		2, 2, 2, 2,
		2, 2, 2, 2,
		2, 2, 2, 2
	},
	2,
	&(int3x4)
	{
		4, 4, 4, 4,
		4, 4, 4, 4,
		4, 4, 4, 4
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int3x4_cadds,
	&(int3x4)
	{
		4, 4, 4, 4,
		4, 4, 4, 4,
		4, 4, 4, 4
	},
	2,
	&(int3x4)
	{
		6, 6, 6, 6,
		6, 6, 6, 6,
		6, 6, 6, 6
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int3x4_cadds,
	&(int3x4)
	{
		8, 8, 8, 8,
		8, 8, 8, 8,
		8, 8, 8, 8
	},
	4,
	&(int3x4)
	{
		12, 12, 12, 12,
		12, 12, 12, 12,
		12, 12, 12, 12
	}
);

TEMPER_PARAMETRIC( Test_int3x4_csubs, TEMPER_FLAG_SHOULD_RUN, const int3x4* lhs, const int32_t rhs, const int3x4* expectedAnswer )
{
	int3x4 actualResult = int3x4_csubs( lhs, rhs );
	TEMPER_CHECK_TRUE( int3x4_equals( &actualResult, expectedAnswer ) );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int3x4_csubs,
	&(int3x4)
	{
		1, 1, 1, 1,
		1, 1, 1, 1,
		1, 1, 1, 1
	},
	1,
	&(int3x4)
	{
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int3x4_csubs,
	&(int3x4)
	{
		2, 2, 2, 2,
		2, 2, 2, 2,
		2, 2, 2, 2
	},
	2,
	&(int3x4)
	{
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int3x4_csubs,
	&(int3x4)
	{
		4, 4, 4, 4,
		4, 4, 4, 4,
		4, 4, 4, 4
	},
	2,
	&(int3x4)
	{
		2, 2, 2, 2,
		2, 2, 2, 2,
		2, 2, 2, 2
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int3x4_csubs,
	&(int3x4)
	{
		8, 8, 8, 8,
		8, 8, 8, 8,
		8, 8, 8, 8
	},
	4,
	&(int3x4)
	{
		4, 4, 4, 4,
		4, 4, 4, 4,
		4, 4, 4, 4
	}
);

TEMPER_PARAMETRIC( Test_int3x4_cmuls, TEMPER_FLAG_SHOULD_RUN, const int3x4* lhs, const int32_t rhs, const int3x4* expectedAnswer )
{
	int3x4 actualResult = int3x4_cmuls( lhs, rhs );
	TEMPER_CHECK_TRUE( int3x4_equals( &actualResult, expectedAnswer ) );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int3x4_cmuls,
	&(int3x4)
	{
		1, 1, 1, 1,
		1, 1, 1, 1,
		1, 1, 1, 1
	},
	1,
	&(int3x4)
	{
		1, 1, 1, 1,
		1, 1, 1, 1,
		1, 1, 1, 1
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int3x4_cmuls,
	&(int3x4)
	{
		2, 2, 2, 2,
		2, 2, 2, 2,
		2, 2, 2, 2
	},
	2,
	&(int3x4)
	{
		4, 4, 4, 4,
		4, 4, 4, 4,
		4, 4, 4, 4
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int3x4_cmuls,
	&(int3x4)
	{
		4, 4, 4, 4,
		4, 4, 4, 4,
		4, 4, 4, 4
	},
	2,
	&(int3x4)
	{
		8, 8, 8, 8,
		8, 8, 8, 8,
		8, 8, 8, 8
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int3x4_cmuls,
	&(int3x4)
	{
		8, 8, 8, 8,
		8, 8, 8, 8,
		8, 8, 8, 8
	},
	4,
	&(int3x4)
	{
		32, 32, 32, 32,
		32, 32, 32, 32,
		32, 32, 32, 32
	}
);

TEMPER_PARAMETRIC( Test_int3x4_cdivs, TEMPER_FLAG_SHOULD_RUN, const int3x4* lhs, const int32_t rhs, const int3x4* expectedAnswer )
{
	int3x4 actualResult = int3x4_cdivs( lhs, rhs );
	TEMPER_CHECK_TRUE( int3x4_equals( &actualResult, expectedAnswer ) );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int3x4_cdivs,
	&(int3x4)
	{
		1, 1, 1, 1,
		1, 1, 1, 1,
		1, 1, 1, 1
	},
	1,
	&(int3x4)
	{
		1, 1, 1, 1,
		1, 1, 1, 1,
		1, 1, 1, 1
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int3x4_cdivs,
	&(int3x4)
	{
		2, 2, 2, 2,
		2, 2, 2, 2,
		2, 2, 2, 2
	},
	2,
	&(int3x4)
	{
		1, 1, 1, 1,
		1, 1, 1, 1,
		1, 1, 1, 1
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int3x4_cdivs,
	&(int3x4)
	{
		4, 4, 4, 4,
		4, 4, 4, 4,
		4, 4, 4, 4
	},
	2,
	&(int3x4)
	{
		2, 2, 2, 2,
		2, 2, 2, 2,
		2, 2, 2, 2
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int3x4_cdivs,
	&(int3x4)
	{
		8, 8, 8, 8,
		8, 8, 8, 8,
		8, 8, 8, 8
	},
	4,
	&(int3x4)
	{
		2, 2, 2, 2,
		2, 2, 2, 2,
		2, 2, 2, 2
	}
);

TEMPER_PARAMETRIC( Test_int3x4_caddm, TEMPER_FLAG_SHOULD_RUN, const int3x4* lhs, const int3x4* rhs, const int3x4* expectedAnswer )
{
	int3x4 actualResult = int3x4_caddm( lhs, rhs );
	TEMPER_CHECK_TRUE( int3x4_equals( &actualResult, expectedAnswer ) );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int3x4_caddm,
	&(int3x4)
	{
		1, 1, 1, 1,
		1, 1, 1, 1,
		1, 1, 1, 1
	},
	&(int3x4)
	{
		1, 1, 1, 1,
		1, 1, 1, 1,
		1, 1, 1, 1
	},
	&(int3x4)
	{
		2, 2, 2, 2,
		2, 2, 2, 2,
		2, 2, 2, 2
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int3x4_caddm,
	&(int3x4)
	{
		2, 2, 2, 2,
		2, 2, 2, 2,
		2, 2, 2, 2
	},
	&(int3x4)
	{
		2, 2, 2, 2,
		2, 2, 2, 2,
		2, 2, 2, 2
	},
	&(int3x4)
	{
		4, 4, 4, 4,
		4, 4, 4, 4,
		4, 4, 4, 4
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int3x4_caddm,
	&(int3x4)
	{
		4, 4, 4, 4,
		4, 4, 4, 4,
		4, 4, 4, 4
	},
	&(int3x4)
	{
		2, 2, 2, 2,
		2, 2, 2, 2,
		2, 2, 2, 2
	},
	&(int3x4)
	{
		6, 6, 6, 6,
		6, 6, 6, 6,
		6, 6, 6, 6
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int3x4_caddm,
	&(int3x4)
	{
		8, 8, 8, 8,
		8, 8, 8, 8,
		8, 8, 8, 8
	},
	&(int3x4)
	{
		4, 4, 4, 4,
		4, 4, 4, 4,
		4, 4, 4, 4
	},
	&(int3x4)
	{
		12, 12, 12, 12,
		12, 12, 12, 12,
		12, 12, 12, 12
	}
);

TEMPER_PARAMETRIC( Test_int3x4_csubm, TEMPER_FLAG_SHOULD_RUN, const int3x4* lhs, const int3x4* rhs, const int3x4* expectedAnswer )
{
	int3x4 actualResult = int3x4_csubm( lhs, rhs );
	TEMPER_CHECK_TRUE( int3x4_equals( &actualResult, expectedAnswer ) );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int3x4_csubm,
	&(int3x4)
	{
		1, 1, 1, 1,
		1, 1, 1, 1,
		1, 1, 1, 1
	},
	&(int3x4)
	{
		1, 1, 1, 1,
		1, 1, 1, 1,
		1, 1, 1, 1
	},
	&(int3x4)
	{
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int3x4_csubm,
	&(int3x4)
	{
		2, 2, 2, 2,
		2, 2, 2, 2,
		2, 2, 2, 2
	},
	&(int3x4)
	{
		2, 2, 2, 2,
		2, 2, 2, 2,
		2, 2, 2, 2
	},
	&(int3x4)
	{
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int3x4_csubm,
	&(int3x4)
	{
		4, 4, 4, 4,
		4, 4, 4, 4,
		4, 4, 4, 4
	},
	&(int3x4)
	{
		2, 2, 2, 2,
		2, 2, 2, 2,
		2, 2, 2, 2
	},
	&(int3x4)
	{
		2, 2, 2, 2,
		2, 2, 2, 2,
		2, 2, 2, 2
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int3x4_csubm,
	&(int3x4)
	{
		8, 8, 8, 8,
		8, 8, 8, 8,
		8, 8, 8, 8
	},
	&(int3x4)
	{
		4, 4, 4, 4,
		4, 4, 4, 4,
		4, 4, 4, 4
	},
	&(int3x4)
	{
		4, 4, 4, 4,
		4, 4, 4, 4,
		4, 4, 4, 4
	}
);

TEMPER_PARAMETRIC( Test_int3x4_cmulm, TEMPER_FLAG_SHOULD_RUN, const int3x4* lhs, const int3x4* rhs, const int3x4* expectedAnswer )
{
	int3x4 actualResult = int3x4_cmulm( lhs, rhs );
	TEMPER_CHECK_TRUE( int3x4_equals( &actualResult, expectedAnswer ) );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int3x4_cmulm,
	&(int3x4)
	{
		1, 1, 1, 1,
		1, 1, 1, 1,
		1, 1, 1, 1
	},
	&(int3x4)
	{
		1, 1, 1, 1,
		1, 1, 1, 1,
		1, 1, 1, 1
	},
	&(int3x4)
	{
		1, 1, 1, 1,
		1, 1, 1, 1,
		1, 1, 1, 1
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int3x4_cmulm,
	&(int3x4)
	{
		2, 2, 2, 2,
		2, 2, 2, 2,
		2, 2, 2, 2
	},
	&(int3x4)
	{
		2, 2, 2, 2,
		2, 2, 2, 2,
		2, 2, 2, 2
	},
	&(int3x4)
	{
		4, 4, 4, 4,
		4, 4, 4, 4,
		4, 4, 4, 4
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int3x4_cmulm,
	&(int3x4)
	{
		4, 4, 4, 4,
		4, 4, 4, 4,
		4, 4, 4, 4
	},
	&(int3x4)
	{
		2, 2, 2, 2,
		2, 2, 2, 2,
		2, 2, 2, 2
	},
	&(int3x4)
	{
		8, 8, 8, 8,
		8, 8, 8, 8,
		8, 8, 8, 8
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int3x4_cmulm,
	&(int3x4)
	{
		8, 8, 8, 8,
		8, 8, 8, 8,
		8, 8, 8, 8
	},
	&(int3x4)
	{
		4, 4, 4, 4,
		4, 4, 4, 4,
		4, 4, 4, 4
	},
	&(int3x4)
	{
		32, 32, 32, 32,
		32, 32, 32, 32,
		32, 32, 32, 32
	}
);

TEMPER_PARAMETRIC( Test_int3x4_cdivm, TEMPER_FLAG_SHOULD_RUN, const int3x4* lhs, const int3x4* rhs, const int3x4* expectedAnswer )
{
	int3x4 actualResult = int3x4_cdivm( lhs, rhs );
	TEMPER_CHECK_TRUE( int3x4_equals( &actualResult, expectedAnswer ) );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int3x4_cdivm,
	&(int3x4)
	{
		1, 1, 1, 1,
		1, 1, 1, 1,
		1, 1, 1, 1
	},
	&(int3x4)
	{
		1, 1, 1, 1,
		1, 1, 1, 1,
		1, 1, 1, 1
	},
	&(int3x4)
	{
		1, 1, 1, 1,
		1, 1, 1, 1,
		1, 1, 1, 1
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int3x4_cdivm,
	&(int3x4)
	{
		2, 2, 2, 2,
		2, 2, 2, 2,
		2, 2, 2, 2
	},
	&(int3x4)
	{
		2, 2, 2, 2,
		2, 2, 2, 2,
		2, 2, 2, 2
	},
	&(int3x4)
	{
		1, 1, 1, 1,
		1, 1, 1, 1,
		1, 1, 1, 1
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int3x4_cdivm,
	&(int3x4)
	{
		4, 4, 4, 4,
		4, 4, 4, 4,
		4, 4, 4, 4
	},
	&(int3x4)
	{
		2, 2, 2, 2,
		2, 2, 2, 2,
		2, 2, 2, 2
	},
	&(int3x4)
	{
		2, 2, 2, 2,
		2, 2, 2, 2,
		2, 2, 2, 2
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int3x4_cdivm,
	&(int3x4)
	{
		8, 8, 8, 8,
		8, 8, 8, 8,
		8, 8, 8, 8
	},
	&(int3x4)
	{
		4, 4, 4, 4,
		4, 4, 4, 4,
		4, 4, 4, 4
	},
	&(int3x4)
	{
		2, 2, 2, 2,
		2, 2, 2, 2,
		2, 2, 2, 2
	}
);

#if defined( __GNUC__ ) || defined( __clang__ )
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wcast-qual"
#endif
TEMPER_PARAMETRIC( Test_int3x4_negate_prefix, TEMPER_FLAG_SHOULD_RUN, const int3x4* x, const int3x4* expectedAnswer )
{
	// make local copy of x and use that because we cant do increment or decrement operations on a const reference
	// and MSVC throws warnings if we just make the parameter a non-const reference
	int3x4* xlocal = (int3x4*) x;
	int3x4 actualAnswer = int3x4_negate( xlocal );
	TEMPER_CHECK_TRUE( int3x4_equals( &actualAnswer, expectedAnswer ) );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int3x4_negate_prefix,
	&(int3x4)
	{
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0
	},
	&(int3x4)
	{
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int3x4_negate_prefix,
	&(int3x4)
	{
		1, 1, 1, 1,
		1, 1, 1, 1,
		1, 1, 1, 1
	},
	&(int3x4)
	{
		-1, -1, -1, -1,
		-1, -1, -1, -1,
		-1, -1, -1, -1
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int3x4_negate_prefix,
	&(int3x4)
	{
		2, 2, 2, 2,
		2, 2, 2, 2,
		2, 2, 2, 2
	},
	&(int3x4)
	{
		-2, -2, -2, -2,
		-2, -2, -2, -2,
		-2, -2, -2, -2
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int3x4_negate_prefix,
	&(int3x4)
	{
		3, 3, 3, 3,
		3, 3, 3, 3,
		3, 3, 3, 3
	},
	&(int3x4)
	{
		-3, -3, -3, -3,
		-3, -3, -3, -3,
		-3, -3, -3, -3
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int3x4_negate_prefix,
	&(int3x4)
	{
		10, 10, 10, 10,
		10, 10, 10, 10,
		10, 10, 10, 10
	},
	&(int3x4)
	{
		-10, -10, -10, -10,
		-10, -10, -10, -10,
		-10, -10, -10, -10
	}
);

#if defined( __GNUC__ ) || defined( __clang__ )
#pragma GCC diagnostic pop
#endif

#if defined( __GNUC__ ) || defined( __clang__ )
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wcast-qual"
#endif
TEMPER_PARAMETRIC( Test_int3x4_not_prefix, TEMPER_FLAG_SHOULD_RUN, const int3x4* x, const int3x4* expectedAnswer )
{
	// make local copy of x and use that because we cant do increment or decrement operations on a const reference
	// and MSVC throws warnings if we just make the parameter a non-const reference
	int3x4* xlocal = (int3x4*) x;
	int3x4 actualAnswer = int3x4_not( xlocal );
	TEMPER_CHECK_TRUE( int3x4_equals( &actualAnswer, expectedAnswer ) );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int3x4_not_prefix,
	&(int3x4)
	{
		1, 1, 1, 1,
		1, 1, 1, 1,
		1, 1, 1, 1
	},
	&(int3x4)
	{
		-2, -2, -2, -2,
		-2, -2, -2, -2,
		-2, -2, -2, -2
	}
);

#if defined( __GNUC__ ) || defined( __clang__ )
#pragma GCC diagnostic pop
#endif

TEMPER_PARAMETRIC( Test_int3x4_cands, TEMPER_FLAG_SHOULD_RUN, const int3x4* lhs, const int32_t rhs, const int3x4* expectedAnswer )
{
	int3x4 actualResult = int3x4_cands( lhs, rhs );
	TEMPER_CHECK_TRUE( int3x4_equals( &actualResult, expectedAnswer ) );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int3x4_cands,
	&(int3x4)
	{
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0
	},
	0,
	&(int3x4)
	{
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int3x4_cands,
	&(int3x4)
	{
		2, 2, 2, 2,
		2, 2, 2, 2,
		2, 2, 2, 2
	},
	1,
	&(int3x4)
	{
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int3x4_cands,
	&(int3x4)
	{
		1, 1, 1, 1,
		1, 1, 1, 1,
		1, 1, 1, 1
	},
	0,
	&(int3x4)
	{
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int3x4_cands,
	&(int3x4)
	{
		1, 1, 1, 1,
		1, 1, 1, 1,
		1, 1, 1, 1
	},
	1,
	&(int3x4)
	{
		1, 1, 1, 1,
		1, 1, 1, 1,
		1, 1, 1, 1
	}
);

TEMPER_PARAMETRIC( Test_int3x4_cors, TEMPER_FLAG_SHOULD_RUN, const int3x4* lhs, const int32_t rhs, const int3x4* expectedAnswer )
{
	int3x4 actualResult = int3x4_cors( lhs, rhs );
	TEMPER_CHECK_TRUE( int3x4_equals( &actualResult, expectedAnswer ) );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int3x4_cors,
	&(int3x4)
	{
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0
	},
	0,
	&(int3x4)
	{
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int3x4_cors,
	&(int3x4)
	{
		2, 2, 2, 2,
		2, 2, 2, 2,
		2, 2, 2, 2
	},
	1,
	&(int3x4)
	{
		3, 3, 3, 3,
		3, 3, 3, 3,
		3, 3, 3, 3
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int3x4_cors,
	&(int3x4)
	{
		1, 1, 1, 1,
		1, 1, 1, 1,
		1, 1, 1, 1
	},
	0,
	&(int3x4)
	{
		1, 1, 1, 1,
		1, 1, 1, 1,
		1, 1, 1, 1
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int3x4_cors,
	&(int3x4)
	{
		1, 1, 1, 1,
		1, 1, 1, 1,
		1, 1, 1, 1
	},
	1,
	&(int3x4)
	{
		1, 1, 1, 1,
		1, 1, 1, 1,
		1, 1, 1, 1
	}
);

TEMPER_PARAMETRIC( Test_int3x4_cxors, TEMPER_FLAG_SHOULD_RUN, const int3x4* lhs, const int32_t rhs, const int3x4* expectedAnswer )
{
	int3x4 actualResult = int3x4_cxors( lhs, rhs );
	TEMPER_CHECK_TRUE( int3x4_equals( &actualResult, expectedAnswer ) );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int3x4_cxors,
	&(int3x4)
	{
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0
	},
	0,
	&(int3x4)
	{
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int3x4_cxors,
	&(int3x4)
	{
		2, 2, 2, 2,
		2, 2, 2, 2,
		2, 2, 2, 2
	},
	1,
	&(int3x4)
	{
		3, 3, 3, 3,
		3, 3, 3, 3,
		3, 3, 3, 3
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int3x4_cxors,
	&(int3x4)
	{
		1, 1, 1, 1,
		1, 1, 1, 1,
		1, 1, 1, 1
	},
	0,
	&(int3x4)
	{
		1, 1, 1, 1,
		1, 1, 1, 1,
		1, 1, 1, 1
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int3x4_cxors,
	&(int3x4)
	{
		1, 1, 1, 1,
		1, 1, 1, 1,
		1, 1, 1, 1
	},
	1,
	&(int3x4)
	{
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0
	}
);

TEMPER_PARAMETRIC( Test_int3x4_cshift_lefts, TEMPER_FLAG_SHOULD_RUN, const int3x4* lhs, const int32_t rhs, const int3x4* expectedAnswer )
{
	int3x4 actualResult = int3x4_cshift_lefts( lhs, rhs );
	TEMPER_CHECK_TRUE( int3x4_equals( &actualResult, expectedAnswer ) );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int3x4_cshift_lefts,
	&(int3x4)
	{
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0
	},
	0,
	&(int3x4)
	{
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int3x4_cshift_lefts,
	&(int3x4)
	{
		2, 2, 2, 2,
		2, 2, 2, 2,
		2, 2, 2, 2
	},
	1,
	&(int3x4)
	{
		4, 4, 4, 4,
		4, 4, 4, 4,
		4, 4, 4, 4
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int3x4_cshift_lefts,
	&(int3x4)
	{
		1, 1, 1, 1,
		1, 1, 1, 1,
		1, 1, 1, 1
	},
	0,
	&(int3x4)
	{
		1, 1, 1, 1,
		1, 1, 1, 1,
		1, 1, 1, 1
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int3x4_cshift_lefts,
	&(int3x4)
	{
		1, 1, 1, 1,
		1, 1, 1, 1,
		1, 1, 1, 1
	},
	1,
	&(int3x4)
	{
		2, 2, 2, 2,
		2, 2, 2, 2,
		2, 2, 2, 2
	}
);

TEMPER_PARAMETRIC( Test_int3x4_cshift_rights, TEMPER_FLAG_SHOULD_RUN, const int3x4* lhs, const int32_t rhs, const int3x4* expectedAnswer )
{
	int3x4 actualResult = int3x4_cshift_rights( lhs, rhs );
	TEMPER_CHECK_TRUE( int3x4_equals( &actualResult, expectedAnswer ) );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int3x4_cshift_rights,
	&(int3x4)
	{
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0
	},
	0,
	&(int3x4)
	{
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int3x4_cshift_rights,
	&(int3x4)
	{
		2, 2, 2, 2,
		2, 2, 2, 2,
		2, 2, 2, 2
	},
	1,
	&(int3x4)
	{
		1, 1, 1, 1,
		1, 1, 1, 1,
		1, 1, 1, 1
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int3x4_cshift_rights,
	&(int3x4)
	{
		1, 1, 1, 1,
		1, 1, 1, 1,
		1, 1, 1, 1
	},
	0,
	&(int3x4)
	{
		1, 1, 1, 1,
		1, 1, 1, 1,
		1, 1, 1, 1
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int3x4_cshift_rights,
	&(int3x4)
	{
		1, 1, 1, 1,
		1, 1, 1, 1,
		1, 1, 1, 1
	},
	1,
	&(int3x4)
	{
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0
	}
);

TEMPER_PARAMETRIC( Test_int3x4_candm, TEMPER_FLAG_SHOULD_RUN, const int3x4* lhs, const int3x4* rhs, const int3x4* expectedAnswer )
{
	int3x4 actualResult = int3x4_candm( lhs, rhs );
	TEMPER_CHECK_TRUE( int3x4_equals( &actualResult, expectedAnswer ) );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int3x4_candm,
	&(int3x4)
	{
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0
	},
	&(int3x4)
	{
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0
	},
	&(int3x4)
	{
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int3x4_candm,
	&(int3x4)
	{
		2, 2, 2, 2,
		2, 2, 2, 2,
		2, 2, 2, 2
	},
	&(int3x4)
	{
		1, 1, 1, 1,
		1, 1, 1, 1,
		1, 1, 1, 1
	},
	&(int3x4)
	{
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int3x4_candm,
	&(int3x4)
	{
		1, 1, 1, 1,
		1, 1, 1, 1,
		1, 1, 1, 1
	},
	&(int3x4)
	{
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0
	},
	&(int3x4)
	{
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int3x4_candm,
	&(int3x4)
	{
		1, 1, 1, 1,
		1, 1, 1, 1,
		1, 1, 1, 1
	},
	&(int3x4)
	{
		1, 1, 1, 1,
		1, 1, 1, 1,
		1, 1, 1, 1
	},
	&(int3x4)
	{
		1, 1, 1, 1,
		1, 1, 1, 1,
		1, 1, 1, 1
	}
);

TEMPER_PARAMETRIC( Test_int3x4_corm, TEMPER_FLAG_SHOULD_RUN, const int3x4* lhs, const int3x4* rhs, const int3x4* expectedAnswer )
{
	int3x4 actualResult = int3x4_corm( lhs, rhs );
	TEMPER_CHECK_TRUE( int3x4_equals( &actualResult, expectedAnswer ) );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int3x4_corm,
	&(int3x4)
	{
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0
	},
	&(int3x4)
	{
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0
	},
	&(int3x4)
	{
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int3x4_corm,
	&(int3x4)
	{
		2, 2, 2, 2,
		2, 2, 2, 2,
		2, 2, 2, 2
	},
	&(int3x4)
	{
		1, 1, 1, 1,
		1, 1, 1, 1,
		1, 1, 1, 1
	},
	&(int3x4)
	{
		3, 3, 3, 3,
		3, 3, 3, 3,
		3, 3, 3, 3
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int3x4_corm,
	&(int3x4)
	{
		1, 1, 1, 1,
		1, 1, 1, 1,
		1, 1, 1, 1
	},
	&(int3x4)
	{
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0
	},
	&(int3x4)
	{
		1, 1, 1, 1,
		1, 1, 1, 1,
		1, 1, 1, 1
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int3x4_corm,
	&(int3x4)
	{
		1, 1, 1, 1,
		1, 1, 1, 1,
		1, 1, 1, 1
	},
	&(int3x4)
	{
		1, 1, 1, 1,
		1, 1, 1, 1,
		1, 1, 1, 1
	},
	&(int3x4)
	{
		1, 1, 1, 1,
		1, 1, 1, 1,
		1, 1, 1, 1
	}
);

TEMPER_PARAMETRIC( Test_int3x4_cxorm, TEMPER_FLAG_SHOULD_RUN, const int3x4* lhs, const int3x4* rhs, const int3x4* expectedAnswer )
{
	int3x4 actualResult = int3x4_cxorm( lhs, rhs );
	TEMPER_CHECK_TRUE( int3x4_equals( &actualResult, expectedAnswer ) );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int3x4_cxorm,
	&(int3x4)
	{
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0
	},
	&(int3x4)
	{
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0
	},
	&(int3x4)
	{
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int3x4_cxorm,
	&(int3x4)
	{
		2, 2, 2, 2,
		2, 2, 2, 2,
		2, 2, 2, 2
	},
	&(int3x4)
	{
		1, 1, 1, 1,
		1, 1, 1, 1,
		1, 1, 1, 1
	},
	&(int3x4)
	{
		3, 3, 3, 3,
		3, 3, 3, 3,
		3, 3, 3, 3
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int3x4_cxorm,
	&(int3x4)
	{
		1, 1, 1, 1,
		1, 1, 1, 1,
		1, 1, 1, 1
	},
	&(int3x4)
	{
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0
	},
	&(int3x4)
	{
		1, 1, 1, 1,
		1, 1, 1, 1,
		1, 1, 1, 1
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int3x4_cxorm,
	&(int3x4)
	{
		1, 1, 1, 1,
		1, 1, 1, 1,
		1, 1, 1, 1
	},
	&(int3x4)
	{
		1, 1, 1, 1,
		1, 1, 1, 1,
		1, 1, 1, 1
	},
	&(int3x4)
	{
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0
	}
);

TEMPER_PARAMETRIC( Test_int3x4_cshift_leftm, TEMPER_FLAG_SHOULD_RUN, const int3x4* lhs, const int3x4* rhs, const int3x4* expectedAnswer )
{
	int3x4 actualResult = int3x4_cshift_leftm( lhs, rhs );
	TEMPER_CHECK_TRUE( int3x4_equals( &actualResult, expectedAnswer ) );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int3x4_cshift_leftm,
	&(int3x4)
	{
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0
	},
	&(int3x4)
	{
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0
	},
	&(int3x4)
	{
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int3x4_cshift_leftm,
	&(int3x4)
	{
		2, 2, 2, 2,
		2, 2, 2, 2,
		2, 2, 2, 2
	},
	&(int3x4)
	{
		1, 1, 1, 1,
		1, 1, 1, 1,
		1, 1, 1, 1
	},
	&(int3x4)
	{
		4, 4, 4, 4,
		4, 4, 4, 4,
		4, 4, 4, 4
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int3x4_cshift_leftm,
	&(int3x4)
	{
		1, 1, 1, 1,
		1, 1, 1, 1,
		1, 1, 1, 1
	},
	&(int3x4)
	{
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0
	},
	&(int3x4)
	{
		1, 1, 1, 1,
		1, 1, 1, 1,
		1, 1, 1, 1
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int3x4_cshift_leftm,
	&(int3x4)
	{
		1, 1, 1, 1,
		1, 1, 1, 1,
		1, 1, 1, 1
	},
	&(int3x4)
	{
		1, 1, 1, 1,
		1, 1, 1, 1,
		1, 1, 1, 1
	},
	&(int3x4)
	{
		2, 2, 2, 2,
		2, 2, 2, 2,
		2, 2, 2, 2
	}
);

TEMPER_PARAMETRIC( Test_int3x4_cshift_rightm, TEMPER_FLAG_SHOULD_RUN, const int3x4* lhs, const int3x4* rhs, const int3x4* expectedAnswer )
{
	int3x4 actualResult = int3x4_cshift_rightm( lhs, rhs );
	TEMPER_CHECK_TRUE( int3x4_equals( &actualResult, expectedAnswer ) );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int3x4_cshift_rightm,
	&(int3x4)
	{
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0
	},
	&(int3x4)
	{
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0
	},
	&(int3x4)
	{
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int3x4_cshift_rightm,
	&(int3x4)
	{
		2, 2, 2, 2,
		2, 2, 2, 2,
		2, 2, 2, 2
	},
	&(int3x4)
	{
		1, 1, 1, 1,
		1, 1, 1, 1,
		1, 1, 1, 1
	},
	&(int3x4)
	{
		1, 1, 1, 1,
		1, 1, 1, 1,
		1, 1, 1, 1
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int3x4_cshift_rightm,
	&(int3x4)
	{
		1, 1, 1, 1,
		1, 1, 1, 1,
		1, 1, 1, 1
	},
	&(int3x4)
	{
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0
	},
	&(int3x4)
	{
		1, 1, 1, 1,
		1, 1, 1, 1,
		1, 1, 1, 1
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int3x4_cshift_rightm,
	&(int3x4)
	{
		1, 1, 1, 1,
		1, 1, 1, 1,
		1, 1, 1, 1
	},
	&(int3x4)
	{
		1, 1, 1, 1,
		1, 1, 1, 1,
		1, 1, 1, 1
	},
	&(int3x4)
	{
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0
	}
);

TEMPER_PARAMETRIC( Test_int3x4_min, TEMPER_FLAG_SHOULD_RUN, const int3x4* lhs, const int3x4* rhs, const int3x4* expectedAnswer )
{
	int3x4 actualResult = int3x4_min( lhs, rhs );
	TEMPER_CHECK_TRUE( int3x4_equals( &actualResult, expectedAnswer ) );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int3x4_min,
	&(int3x4)
	{
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0
	},
	&(int3x4)
	{
		1, 1, 1, 1,
		1, 1, 1, 1,
		1, 1, 1, 1
	},
	&(int3x4)
	{
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int3x4_min,
	&(int3x4)
	{
		1, 1, 1, 1,
		1, 1, 1, 1,
		1, 1, 1, 1
	},
	&(int3x4)
	{
		2, 2, 2, 2,
		2, 2, 2, 2,
		2, 2, 2, 2
	},
	&(int3x4)
	{
		1, 1, 1, 1,
		1, 1, 1, 1,
		1, 1, 1, 1
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int3x4_min,
	&(int3x4)
	{
		420, 420, 420, 420,
		420, 420, 420, 420,
		420, 420, 420, 420
	},
	&(int3x4)
	{
		69, 69, 69, 69,
		69, 69, 69, 69,
		69, 69, 69, 69
	},
	&(int3x4)
	{
		69, 69, 69, 69,
		69, 69, 69, 69,
		69, 69, 69, 69
	}
);

TEMPER_PARAMETRIC( Test_int3x4_max, TEMPER_FLAG_SHOULD_RUN, const int3x4* lhs, const int3x4* rhs, const int3x4* expectedAnswer )
{
	int3x4 actualResult = int3x4_max( lhs, rhs );
	TEMPER_CHECK_TRUE( int3x4_equals( &actualResult, expectedAnswer ) );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int3x4_max,
	&(int3x4)
	{
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0
	},
	&(int3x4)
	{
		1, 1, 1, 1,
		1, 1, 1, 1,
		1, 1, 1, 1
	},
	&(int3x4)
	{
		1, 1, 1, 1,
		1, 1, 1, 1,
		1, 1, 1, 1
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int3x4_max,
	&(int3x4)
	{
		1, 1, 1, 1,
		1, 1, 1, 1,
		1, 1, 1, 1
	},
	&(int3x4)
	{
		2, 2, 2, 2,
		2, 2, 2, 2,
		2, 2, 2, 2
	},
	&(int3x4)
	{
		2, 2, 2, 2,
		2, 2, 2, 2,
		2, 2, 2, 2
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int3x4_max,
	&(int3x4)
	{
		69, 69, 69, 69,
		69, 69, 69, 69,
		69, 69, 69, 69
	},
	&(int3x4)
	{
		420, 420, 420, 420,
		420, 420, 420, 420,
		420, 420, 420, 420
	},
	&(int3x4)
	{
		420, 420, 420, 420,
		420, 420, 420, 420,
		420, 420, 420, 420
	}
);

TEMPER_PARAMETRIC( Test_int3x4_saturate, TEMPER_FLAG_SHOULD_RUN, const int3x4* x, const int3x4* expectedAnswer )
{
	int3x4 actualResult = int3x4_saturate( x );
	TEMPER_CHECK_TRUE( int3x4_equals( &actualResult, expectedAnswer ) );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int3x4_saturate,
	&(int3x4)
	{
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0
	},
	&(int3x4)
	{
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int3x4_saturate,
	&(int3x4)
	{
		1, 1, 1, 1,
		1, 1, 1, 1,
		1, 1, 1, 1
	},
	&(int3x4)
	{
		1, 1, 1, 1,
		1, 1, 1, 1,
		1, 1, 1, 1
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int3x4_saturate,
	&(int3x4)
	{
		2, 2, 2, 2,
		2, 2, 2, 2,
		2, 2, 2, 2
	},
	&(int3x4)
	{
		1, 1, 1, 1,
		1, 1, 1, 1,
		1, 1, 1, 1
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int3x4_saturate,
	&(int3x4)
	{
		3, 3, 3, 3,
		3, 3, 3, 3,
		3, 3, 3, 3
	},
	&(int3x4)
	{
		1, 1, 1, 1,
		1, 1, 1, 1,
		1, 1, 1, 1
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int3x4_saturate,
	&(int3x4)
	{
		10, 10, 10, 10,
		10, 10, 10, 10,
		10, 10, 10, 10
	},
	&(int3x4)
	{
		1, 1, 1, 1,
		1, 1, 1, 1,
		1, 1, 1, 1
	}
);

TEMPER_PARAMETRIC( Test_int3x4_sign, TEMPER_FLAG_SHOULD_RUN, const int3x4* x, const int3x4* expectedAnswer )
{
	int3x4 actualResult = int3x4_sign( x );
	TEMPER_CHECK_TRUE( int3x4_equals( &actualResult, expectedAnswer ) );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int3x4_sign,
	&(int3x4)
	{
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0
	},
	&(int3x4)
	{
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int3x4_sign,
	&(int3x4)
	{
		1, 1, 1, 1,
		1, 1, 1, 1,
		1, 1, 1, 1
	},
	&(int3x4)
	{
		1, 1, 1, 1,
		1, 1, 1, 1,
		1, 1, 1, 1
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int3x4_sign,
	&(int3x4)
	{
		2, 2, 2, 2,
		2, 2, 2, 2,
		2, 2, 2, 2
	},
	&(int3x4)
	{
		1, 1, 1, 1,
		1, 1, 1, 1,
		1, 1, 1, 1
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int3x4_sign,
	&(int3x4)
	{
		3, 3, 3, 3,
		3, 3, 3, 3,
		3, 3, 3, 3
	},
	&(int3x4)
	{
		1, 1, 1, 1,
		1, 1, 1, 1,
		1, 1, 1, 1
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int3x4_sign,
	&(int3x4)
	{
		-1, -1, -1, -1,
		-1, -1, -1, -1,
		-1, -1, -1, -1
	},
	&(int3x4)
	{
		-1, -1, -1, -1,
		-1, -1, -1, -1,
		-1, -1, -1, -1
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int3x4_sign,
	&(int3x4)
	{
		-2, -2, -2, -2,
		-2, -2, -2, -2,
		-2, -2, -2, -2
	},
	&(int3x4)
	{
		-1, -1, -1, -1,
		-1, -1, -1, -1,
		-1, -1, -1, -1
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int3x4_sign,
	&(int3x4)
	{
		-3, -3, -3, -3,
		-3, -3, -3, -3,
		-3, -3, -3, -3
	},
	&(int3x4)
	{
		-1, -1, -1, -1,
		-1, -1, -1, -1,
		-1, -1, -1, -1
	}
);

TEMPER_PARAMETRIC( Test_int3x4_identity, TEMPER_FLAG_SHOULD_RUN, const int3x4* matrix, const bool expectedAnswer )
{
	int3x4 identityMat;
	int3x4_identity( &identityMat );
	bool isMatrixIdentity = int3x4_equals( &identityMat, matrix );
	TEMPER_CHECK_TRUE( isMatrixIdentity == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int3x4_identity,
	&(int3x4)
	{
		1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0
	},
	true
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int3x4_identity,
	&(int3x4)
	{
		1, 1, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0
	},
	false
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int3x4_identity,
	&(int3x4)
	{
		1, 0, 0, 0,
		1, 1, 0, 0,
		0, 0, 1, 0
	},
	false
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int3x4_identity,
	&(int3x4)
	{
		1, 1, 0, 0,
		1, 1, 0, 0,
		0, 0, 1, 0
	},
	false
);

TEMPER_PARAMETRIC( Test_int3x4_transpose, TEMPER_FLAG_SHOULD_RUN, const int3x4* matrix, const int4x3* expectedAnswer )
{
	int4x3 actualResult = int3x4_transpose( matrix );
	TEMPER_CHECK_TRUE( int4x3_equals( &actualResult, expectedAnswer ) );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int3x4_transpose,
	&(int3x4)
	{
		1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0
	},
	&(int4x3)
	{
		1, 0, 0,
		0, 1, 0,
		0, 0, 1,
		0, 0, 0
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int3x4_transpose,
	&(int3x4)
	{
		0, 1, 2, 3,
		4, 5, 6, 7,
		8, 9, 10, 11
	},
	&(int4x3)
	{
		0, 4, 8,
		1, 5, 9,
		2, 6, 10,
		3, 7, 11
	}
);

TEMPER_PARAMETRIC( Test_int3x4_mulm, TEMPER_FLAG_SHOULD_RUN, const int3x4* lhs, const int4x3* rhs, const int3x3* expectedAnswer )
{
	int3x3 actualResult = int3x4_mulm( lhs, rhs );
	TEMPER_CHECK_TRUE( int3x3_equals( &actualResult, expectedAnswer ) );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int3x4_mulm,
	&(int3x4)
	{
		2, 2, 2, 2,
		2, 2, 2, 2,
		2, 2, 2, 2
	},
	&(int4x3)
	{
		4, 4, 4,
		4, 4, 4,
		4, 4, 4,
		4, 4, 4
	},
	&(int3x3)
	{
		32, 32, 32,
		32, 32, 32,
		32, 32, 32
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_int3x4_mulm,
	&(int3x4)
	{
		2, 2, 2, 2,
		2, 2, 2, 2,
		2, 2, 2, 2
	},
	&(int4x3)
	{
		1, 0, 0,
		0, 1, 0,
		0, 0, 1,
		0, 0, 0
	},
	&(int3x3)
	{
		2, 2, 2,
		2, 2, 2,
		2, 2, 2
	}
);


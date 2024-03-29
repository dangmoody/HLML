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

TEMPER_TEST_PARAMETRIC( Test_uint4x2_less_than, TEMPER_FLAG_SHOULD_RUN, const uint4x2* lhs, const uint4x2* rhs, const bool4x2* expectedAnswer )
{
	bool4x2 actualResult = uint4x2_less_than( lhs, rhs );
	TEMPER_CHECK_TRUE( bool4x2_equals( &actualResult, expectedAnswer ) );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint4x2_less_than,
	&(uint4x2)
	{
		0U, 0U,
		0U, 0U,
		0U, 0U,
		0U, 0U
	},
	&(uint4x2)
	{
		0U, 0U,
		0U, 0U,
		0U, 0U,
		0U, 0U
	},
	&(bool4x2)
	{
		false, false,
		false, false,
		false, false,
		false, false
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint4x2_less_than,
	&(uint4x2)
	{
		0U, 0U,
		0U, 0U,
		0U, 0U,
		0U, 0U
	},
	&(uint4x2)
	{
		1U, 1U,
		1U, 1U,
		1U, 1U,
		1U, 1U
	},
	&(bool4x2)
	{
		true, true,
		true, true,
		true, true,
		true, true
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint4x2_less_than,
	&(uint4x2)
	{
		1U, 1U,
		1U, 1U,
		1U, 1U,
		1U, 1U
	},
	&(uint4x2)
	{
		1U, 1U,
		1U, 1U,
		1U, 1U,
		1U, 1U
	},
	&(bool4x2)
	{
		false, false,
		false, false,
		false, false,
		false, false
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint4x2_less_than,
	&(uint4x2)
	{
		1U, 1U,
		1U, 1U,
		1U, 1U,
		1U, 1U
	},
	&(uint4x2)
	{
		0U, 0U,
		0U, 0U,
		0U, 0U,
		0U, 0U
	},
	&(bool4x2)
	{
		false, false,
		false, false,
		false, false,
		false, false
	}
);

TEMPER_TEST_PARAMETRIC( Test_uint4x2_less_than_equal, TEMPER_FLAG_SHOULD_RUN, const uint4x2* lhs, const uint4x2* rhs, const bool4x2* expectedAnswer )
{
	bool4x2 actualResult = uint4x2_less_than_equal( lhs, rhs );
	TEMPER_CHECK_TRUE( bool4x2_equals( &actualResult, expectedAnswer ) );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint4x2_less_than_equal,
	&(uint4x2)
	{
		0U, 0U,
		0U, 0U,
		0U, 0U,
		0U, 0U
	},
	&(uint4x2)
	{
		0U, 0U,
		0U, 0U,
		0U, 0U,
		0U, 0U
	},
	&(bool4x2)
	{
		true, true,
		true, true,
		true, true,
		true, true
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint4x2_less_than_equal,
	&(uint4x2)
	{
		0U, 0U,
		0U, 0U,
		0U, 0U,
		0U, 0U
	},
	&(uint4x2)
	{
		1U, 1U,
		1U, 1U,
		1U, 1U,
		1U, 1U
	},
	&(bool4x2)
	{
		true, true,
		true, true,
		true, true,
		true, true
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint4x2_less_than_equal,
	&(uint4x2)
	{
		1U, 1U,
		1U, 1U,
		1U, 1U,
		1U, 1U
	},
	&(uint4x2)
	{
		1U, 1U,
		1U, 1U,
		1U, 1U,
		1U, 1U
	},
	&(bool4x2)
	{
		true, true,
		true, true,
		true, true,
		true, true
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint4x2_less_than_equal,
	&(uint4x2)
	{
		1U, 1U,
		1U, 1U,
		1U, 1U,
		1U, 1U
	},
	&(uint4x2)
	{
		0U, 0U,
		0U, 0U,
		0U, 0U,
		0U, 0U
	},
	&(bool4x2)
	{
		false, false,
		false, false,
		false, false,
		false, false
	}
);

TEMPER_TEST_PARAMETRIC( Test_uint4x2_greater_than, TEMPER_FLAG_SHOULD_RUN, const uint4x2* lhs, const uint4x2* rhs, const bool4x2* expectedAnswer )
{
	bool4x2 actualResult = uint4x2_greater_than( lhs, rhs );
	TEMPER_CHECK_TRUE( bool4x2_equals( &actualResult, expectedAnswer ) );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint4x2_greater_than,
	&(uint4x2)
	{
		0U, 0U,
		0U, 0U,
		0U, 0U,
		0U, 0U
	},
	&(uint4x2)
	{
		0U, 0U,
		0U, 0U,
		0U, 0U,
		0U, 0U
	},
	&(bool4x2)
	{
		false, false,
		false, false,
		false, false,
		false, false
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint4x2_greater_than,
	&(uint4x2)
	{
		0U, 0U,
		0U, 0U,
		0U, 0U,
		0U, 0U
	},
	&(uint4x2)
	{
		1U, 1U,
		1U, 1U,
		1U, 1U,
		1U, 1U
	},
	&(bool4x2)
	{
		false, false,
		false, false,
		false, false,
		false, false
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint4x2_greater_than,
	&(uint4x2)
	{
		1U, 1U,
		1U, 1U,
		1U, 1U,
		1U, 1U
	},
	&(uint4x2)
	{
		1U, 1U,
		1U, 1U,
		1U, 1U,
		1U, 1U
	},
	&(bool4x2)
	{
		false, false,
		false, false,
		false, false,
		false, false
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint4x2_greater_than,
	&(uint4x2)
	{
		1U, 1U,
		1U, 1U,
		1U, 1U,
		1U, 1U
	},
	&(uint4x2)
	{
		0U, 0U,
		0U, 0U,
		0U, 0U,
		0U, 0U
	},
	&(bool4x2)
	{
		true, true,
		true, true,
		true, true,
		true, true
	}
);

TEMPER_TEST_PARAMETRIC( Test_uint4x2_greater_than_equal, TEMPER_FLAG_SHOULD_RUN, const uint4x2* lhs, const uint4x2* rhs, const bool4x2* expectedAnswer )
{
	bool4x2 actualResult = uint4x2_greater_than_equal( lhs, rhs );
	TEMPER_CHECK_TRUE( bool4x2_equals( &actualResult, expectedAnswer ) );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint4x2_greater_than_equal,
	&(uint4x2)
	{
		0U, 0U,
		0U, 0U,
		0U, 0U,
		0U, 0U
	},
	&(uint4x2)
	{
		0U, 0U,
		0U, 0U,
		0U, 0U,
		0U, 0U
	},
	&(bool4x2)
	{
		true, true,
		true, true,
		true, true,
		true, true
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint4x2_greater_than_equal,
	&(uint4x2)
	{
		0U, 0U,
		0U, 0U,
		0U, 0U,
		0U, 0U
	},
	&(uint4x2)
	{
		1U, 1U,
		1U, 1U,
		1U, 1U,
		1U, 1U
	},
	&(bool4x2)
	{
		false, false,
		false, false,
		false, false,
		false, false
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint4x2_greater_than_equal,
	&(uint4x2)
	{
		1U, 1U,
		1U, 1U,
		1U, 1U,
		1U, 1U
	},
	&(uint4x2)
	{
		1U, 1U,
		1U, 1U,
		1U, 1U,
		1U, 1U
	},
	&(bool4x2)
	{
		true, true,
		true, true,
		true, true,
		true, true
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint4x2_greater_than_equal,
	&(uint4x2)
	{
		1U, 1U,
		1U, 1U,
		1U, 1U,
		1U, 1U
	},
	&(uint4x2)
	{
		0U, 0U,
		0U, 0U,
		0U, 0U,
		0U, 0U
	},
	&(bool4x2)
	{
		true, true,
		true, true,
		true, true,
		true, true
	}
);

TEMPER_TEST_PARAMETRIC( Test_uint4x2_cadds, TEMPER_FLAG_SHOULD_RUN, const uint4x2* lhs, const uint32_t rhs, const uint4x2* expectedAnswer )
{
	uint4x2 actualResult = uint4x2_cadds( lhs, rhs );
	TEMPER_CHECK_TRUE( uint4x2_equals( &actualResult, expectedAnswer ) );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint4x2_cadds,
	&(uint4x2)
	{
		1U, 1U,
		1U, 1U,
		1U, 1U,
		1U, 1U
	},
	1U,
	&(uint4x2)
	{
		2U, 2U,
		2U, 2U,
		2U, 2U,
		2U, 2U
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint4x2_cadds,
	&(uint4x2)
	{
		2U, 2U,
		2U, 2U,
		2U, 2U,
		2U, 2U
	},
	2U,
	&(uint4x2)
	{
		4U, 4U,
		4U, 4U,
		4U, 4U,
		4U, 4U
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint4x2_cadds,
	&(uint4x2)
	{
		4U, 4U,
		4U, 4U,
		4U, 4U,
		4U, 4U
	},
	2U,
	&(uint4x2)
	{
		6U, 6U,
		6U, 6U,
		6U, 6U,
		6U, 6U
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint4x2_cadds,
	&(uint4x2)
	{
		8U, 8U,
		8U, 8U,
		8U, 8U,
		8U, 8U
	},
	4U,
	&(uint4x2)
	{
		12U, 12U,
		12U, 12U,
		12U, 12U,
		12U, 12U
	}
);

TEMPER_TEST_PARAMETRIC( Test_uint4x2_csubs, TEMPER_FLAG_SHOULD_RUN, const uint4x2* lhs, const uint32_t rhs, const uint4x2* expectedAnswer )
{
	uint4x2 actualResult = uint4x2_csubs( lhs, rhs );
	TEMPER_CHECK_TRUE( uint4x2_equals( &actualResult, expectedAnswer ) );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint4x2_csubs,
	&(uint4x2)
	{
		1U, 1U,
		1U, 1U,
		1U, 1U,
		1U, 1U
	},
	1U,
	&(uint4x2)
	{
		0U, 0U,
		0U, 0U,
		0U, 0U,
		0U, 0U
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint4x2_csubs,
	&(uint4x2)
	{
		2U, 2U,
		2U, 2U,
		2U, 2U,
		2U, 2U
	},
	2U,
	&(uint4x2)
	{
		0U, 0U,
		0U, 0U,
		0U, 0U,
		0U, 0U
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint4x2_csubs,
	&(uint4x2)
	{
		4U, 4U,
		4U, 4U,
		4U, 4U,
		4U, 4U
	},
	2U,
	&(uint4x2)
	{
		2U, 2U,
		2U, 2U,
		2U, 2U,
		2U, 2U
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint4x2_csubs,
	&(uint4x2)
	{
		8U, 8U,
		8U, 8U,
		8U, 8U,
		8U, 8U
	},
	4U,
	&(uint4x2)
	{
		4U, 4U,
		4U, 4U,
		4U, 4U,
		4U, 4U
	}
);

TEMPER_TEST_PARAMETRIC( Test_uint4x2_cmuls, TEMPER_FLAG_SHOULD_RUN, const uint4x2* lhs, const uint32_t rhs, const uint4x2* expectedAnswer )
{
	uint4x2 actualResult = uint4x2_cmuls( lhs, rhs );
	TEMPER_CHECK_TRUE( uint4x2_equals( &actualResult, expectedAnswer ) );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint4x2_cmuls,
	&(uint4x2)
	{
		1U, 1U,
		1U, 1U,
		1U, 1U,
		1U, 1U
	},
	1U,
	&(uint4x2)
	{
		1U, 1U,
		1U, 1U,
		1U, 1U,
		1U, 1U
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint4x2_cmuls,
	&(uint4x2)
	{
		2U, 2U,
		2U, 2U,
		2U, 2U,
		2U, 2U
	},
	2U,
	&(uint4x2)
	{
		4U, 4U,
		4U, 4U,
		4U, 4U,
		4U, 4U
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint4x2_cmuls,
	&(uint4x2)
	{
		4U, 4U,
		4U, 4U,
		4U, 4U,
		4U, 4U
	},
	2U,
	&(uint4x2)
	{
		8U, 8U,
		8U, 8U,
		8U, 8U,
		8U, 8U
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint4x2_cmuls,
	&(uint4x2)
	{
		8U, 8U,
		8U, 8U,
		8U, 8U,
		8U, 8U
	},
	4U,
	&(uint4x2)
	{
		32U, 32U,
		32U, 32U,
		32U, 32U,
		32U, 32U
	}
);

TEMPER_TEST_PARAMETRIC( Test_uint4x2_cdivs, TEMPER_FLAG_SHOULD_RUN, const uint4x2* lhs, const uint32_t rhs, const uint4x2* expectedAnswer )
{
	uint4x2 actualResult = uint4x2_cdivs( lhs, rhs );
	TEMPER_CHECK_TRUE( uint4x2_equals( &actualResult, expectedAnswer ) );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint4x2_cdivs,
	&(uint4x2)
	{
		1U, 1U,
		1U, 1U,
		1U, 1U,
		1U, 1U
	},
	1U,
	&(uint4x2)
	{
		1U, 1U,
		1U, 1U,
		1U, 1U,
		1U, 1U
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint4x2_cdivs,
	&(uint4x2)
	{
		2U, 2U,
		2U, 2U,
		2U, 2U,
		2U, 2U
	},
	2U,
	&(uint4x2)
	{
		1U, 1U,
		1U, 1U,
		1U, 1U,
		1U, 1U
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint4x2_cdivs,
	&(uint4x2)
	{
		4U, 4U,
		4U, 4U,
		4U, 4U,
		4U, 4U
	},
	2U,
	&(uint4x2)
	{
		2U, 2U,
		2U, 2U,
		2U, 2U,
		2U, 2U
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint4x2_cdivs,
	&(uint4x2)
	{
		8U, 8U,
		8U, 8U,
		8U, 8U,
		8U, 8U
	},
	4U,
	&(uint4x2)
	{
		2U, 2U,
		2U, 2U,
		2U, 2U,
		2U, 2U
	}
);

TEMPER_TEST_PARAMETRIC( Test_uint4x2_caddm, TEMPER_FLAG_SHOULD_RUN, const uint4x2* lhs, const uint4x2* rhs, const uint4x2* expectedAnswer )
{
	uint4x2 actualResult = uint4x2_caddm( lhs, rhs );
	TEMPER_CHECK_TRUE( uint4x2_equals( &actualResult, expectedAnswer ) );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint4x2_caddm,
	&(uint4x2)
	{
		1U, 1U,
		1U, 1U,
		1U, 1U,
		1U, 1U
	},
	&(uint4x2)
	{
		1U, 1U,
		1U, 1U,
		1U, 1U,
		1U, 1U
	},
	&(uint4x2)
	{
		2U, 2U,
		2U, 2U,
		2U, 2U,
		2U, 2U
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint4x2_caddm,
	&(uint4x2)
	{
		2U, 2U,
		2U, 2U,
		2U, 2U,
		2U, 2U
	},
	&(uint4x2)
	{
		2U, 2U,
		2U, 2U,
		2U, 2U,
		2U, 2U
	},
	&(uint4x2)
	{
		4U, 4U,
		4U, 4U,
		4U, 4U,
		4U, 4U
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint4x2_caddm,
	&(uint4x2)
	{
		4U, 4U,
		4U, 4U,
		4U, 4U,
		4U, 4U
	},
	&(uint4x2)
	{
		2U, 2U,
		2U, 2U,
		2U, 2U,
		2U, 2U
	},
	&(uint4x2)
	{
		6U, 6U,
		6U, 6U,
		6U, 6U,
		6U, 6U
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint4x2_caddm,
	&(uint4x2)
	{
		8U, 8U,
		8U, 8U,
		8U, 8U,
		8U, 8U
	},
	&(uint4x2)
	{
		4U, 4U,
		4U, 4U,
		4U, 4U,
		4U, 4U
	},
	&(uint4x2)
	{
		12U, 12U,
		12U, 12U,
		12U, 12U,
		12U, 12U
	}
);

TEMPER_TEST_PARAMETRIC( Test_uint4x2_csubm, TEMPER_FLAG_SHOULD_RUN, const uint4x2* lhs, const uint4x2* rhs, const uint4x2* expectedAnswer )
{
	uint4x2 actualResult = uint4x2_csubm( lhs, rhs );
	TEMPER_CHECK_TRUE( uint4x2_equals( &actualResult, expectedAnswer ) );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint4x2_csubm,
	&(uint4x2)
	{
		1U, 1U,
		1U, 1U,
		1U, 1U,
		1U, 1U
	},
	&(uint4x2)
	{
		1U, 1U,
		1U, 1U,
		1U, 1U,
		1U, 1U
	},
	&(uint4x2)
	{
		0U, 0U,
		0U, 0U,
		0U, 0U,
		0U, 0U
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint4x2_csubm,
	&(uint4x2)
	{
		2U, 2U,
		2U, 2U,
		2U, 2U,
		2U, 2U
	},
	&(uint4x2)
	{
		2U, 2U,
		2U, 2U,
		2U, 2U,
		2U, 2U
	},
	&(uint4x2)
	{
		0U, 0U,
		0U, 0U,
		0U, 0U,
		0U, 0U
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint4x2_csubm,
	&(uint4x2)
	{
		4U, 4U,
		4U, 4U,
		4U, 4U,
		4U, 4U
	},
	&(uint4x2)
	{
		2U, 2U,
		2U, 2U,
		2U, 2U,
		2U, 2U
	},
	&(uint4x2)
	{
		2U, 2U,
		2U, 2U,
		2U, 2U,
		2U, 2U
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint4x2_csubm,
	&(uint4x2)
	{
		8U, 8U,
		8U, 8U,
		8U, 8U,
		8U, 8U
	},
	&(uint4x2)
	{
		4U, 4U,
		4U, 4U,
		4U, 4U,
		4U, 4U
	},
	&(uint4x2)
	{
		4U, 4U,
		4U, 4U,
		4U, 4U,
		4U, 4U
	}
);

TEMPER_TEST_PARAMETRIC( Test_uint4x2_cmulm, TEMPER_FLAG_SHOULD_RUN, const uint4x2* lhs, const uint4x2* rhs, const uint4x2* expectedAnswer )
{
	uint4x2 actualResult = uint4x2_cmulm( lhs, rhs );
	TEMPER_CHECK_TRUE( uint4x2_equals( &actualResult, expectedAnswer ) );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint4x2_cmulm,
	&(uint4x2)
	{
		1U, 1U,
		1U, 1U,
		1U, 1U,
		1U, 1U
	},
	&(uint4x2)
	{
		1U, 1U,
		1U, 1U,
		1U, 1U,
		1U, 1U
	},
	&(uint4x2)
	{
		1U, 1U,
		1U, 1U,
		1U, 1U,
		1U, 1U
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint4x2_cmulm,
	&(uint4x2)
	{
		2U, 2U,
		2U, 2U,
		2U, 2U,
		2U, 2U
	},
	&(uint4x2)
	{
		2U, 2U,
		2U, 2U,
		2U, 2U,
		2U, 2U
	},
	&(uint4x2)
	{
		4U, 4U,
		4U, 4U,
		4U, 4U,
		4U, 4U
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint4x2_cmulm,
	&(uint4x2)
	{
		4U, 4U,
		4U, 4U,
		4U, 4U,
		4U, 4U
	},
	&(uint4x2)
	{
		2U, 2U,
		2U, 2U,
		2U, 2U,
		2U, 2U
	},
	&(uint4x2)
	{
		8U, 8U,
		8U, 8U,
		8U, 8U,
		8U, 8U
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint4x2_cmulm,
	&(uint4x2)
	{
		8U, 8U,
		8U, 8U,
		8U, 8U,
		8U, 8U
	},
	&(uint4x2)
	{
		4U, 4U,
		4U, 4U,
		4U, 4U,
		4U, 4U
	},
	&(uint4x2)
	{
		32U, 32U,
		32U, 32U,
		32U, 32U,
		32U, 32U
	}
);

TEMPER_TEST_PARAMETRIC( Test_uint4x2_cdivm, TEMPER_FLAG_SHOULD_RUN, const uint4x2* lhs, const uint4x2* rhs, const uint4x2* expectedAnswer )
{
	uint4x2 actualResult = uint4x2_cdivm( lhs, rhs );
	TEMPER_CHECK_TRUE( uint4x2_equals( &actualResult, expectedAnswer ) );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint4x2_cdivm,
	&(uint4x2)
	{
		1U, 1U,
		1U, 1U,
		1U, 1U,
		1U, 1U
	},
	&(uint4x2)
	{
		1U, 1U,
		1U, 1U,
		1U, 1U,
		1U, 1U
	},
	&(uint4x2)
	{
		1U, 1U,
		1U, 1U,
		1U, 1U,
		1U, 1U
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint4x2_cdivm,
	&(uint4x2)
	{
		2U, 2U,
		2U, 2U,
		2U, 2U,
		2U, 2U
	},
	&(uint4x2)
	{
		2U, 2U,
		2U, 2U,
		2U, 2U,
		2U, 2U
	},
	&(uint4x2)
	{
		1U, 1U,
		1U, 1U,
		1U, 1U,
		1U, 1U
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint4x2_cdivm,
	&(uint4x2)
	{
		4U, 4U,
		4U, 4U,
		4U, 4U,
		4U, 4U
	},
	&(uint4x2)
	{
		2U, 2U,
		2U, 2U,
		2U, 2U,
		2U, 2U
	},
	&(uint4x2)
	{
		2U, 2U,
		2U, 2U,
		2U, 2U,
		2U, 2U
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint4x2_cdivm,
	&(uint4x2)
	{
		8U, 8U,
		8U, 8U,
		8U, 8U,
		8U, 8U
	},
	&(uint4x2)
	{
		4U, 4U,
		4U, 4U,
		4U, 4U,
		4U, 4U
	},
	&(uint4x2)
	{
		2U, 2U,
		2U, 2U,
		2U, 2U,
		2U, 2U
	}
);

#if defined( __GNUC__ ) || defined( __clang__ )
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wcast-qual"
#endif
TEMPER_TEST_PARAMETRIC( Test_uint4x2_negate_prefix, TEMPER_FLAG_SHOULD_RUN, const uint4x2* x, const uint4x2* expectedAnswer )
{
	// make local copy of x and use that because we cant do increment or decrement operations on a const reference
	// and MSVC throws warnings if we just make the parameter a non-const reference
	uint4x2* xlocal = (uint4x2*) x;
	uint4x2 actualAnswer = uint4x2_negate( xlocal );
	TEMPER_CHECK_TRUE( uint4x2_equals( &actualAnswer, expectedAnswer ) );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint4x2_negate_prefix,
	&(uint4x2)
	{
		0U, 0U,
		0U, 0U,
		0U, 0U,
		0U, 0U
	},
	&(uint4x2)
	{
		0U, 0U,
		0U, 0U,
		0U, 0U,
		0U, 0U
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint4x2_negate_prefix,
	&(uint4x2)
	{
		1U, 1U,
		1U, 1U,
		1U, 1U,
		1U, 1U
	},
	&(uint4x2)
	{
		4294967295U, 4294967295U,
		4294967295U, 4294967295U,
		4294967295U, 4294967295U,
		4294967295U, 4294967295U
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint4x2_negate_prefix,
	&(uint4x2)
	{
		2U, 2U,
		2U, 2U,
		2U, 2U,
		2U, 2U
	},
	&(uint4x2)
	{
		4294967294U, 4294967294U,
		4294967294U, 4294967294U,
		4294967294U, 4294967294U,
		4294967294U, 4294967294U
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint4x2_negate_prefix,
	&(uint4x2)
	{
		3U, 3U,
		3U, 3U,
		3U, 3U,
		3U, 3U
	},
	&(uint4x2)
	{
		4294967293U, 4294967293U,
		4294967293U, 4294967293U,
		4294967293U, 4294967293U,
		4294967293U, 4294967293U
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint4x2_negate_prefix,
	&(uint4x2)
	{
		10U, 10U,
		10U, 10U,
		10U, 10U,
		10U, 10U
	},
	&(uint4x2)
	{
		4294967286U, 4294967286U,
		4294967286U, 4294967286U,
		4294967286U, 4294967286U,
		4294967286U, 4294967286U
	}
);

#if defined( __GNUC__ ) || defined( __clang__ )
#pragma GCC diagnostic pop
#endif

#if defined( __GNUC__ ) || defined( __clang__ )
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wcast-qual"
#endif
TEMPER_TEST_PARAMETRIC( Test_uint4x2_not_prefix, TEMPER_FLAG_SHOULD_RUN, const uint4x2* x, const uint4x2* expectedAnswer )
{
	// make local copy of x and use that because we cant do increment or decrement operations on a const reference
	// and MSVC throws warnings if we just make the parameter a non-const reference
	uint4x2* xlocal = (uint4x2*) x;
	uint4x2 actualAnswer = uint4x2_not( xlocal );
	TEMPER_CHECK_TRUE( uint4x2_equals( &actualAnswer, expectedAnswer ) );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint4x2_not_prefix,
	&(uint4x2)
	{
		1U, 1U,
		1U, 1U,
		1U, 1U,
		1U, 1U
	},
	&(uint4x2)
	{
		4294967294U, 4294967294U,
		4294967294U, 4294967294U,
		4294967294U, 4294967294U,
		4294967294U, 4294967294U
	}
);

#if defined( __GNUC__ ) || defined( __clang__ )
#pragma GCC diagnostic pop
#endif

TEMPER_TEST_PARAMETRIC( Test_uint4x2_cands, TEMPER_FLAG_SHOULD_RUN, const uint4x2* lhs, const uint32_t rhs, const uint4x2* expectedAnswer )
{
	uint4x2 actualResult = uint4x2_cands( lhs, rhs );
	TEMPER_CHECK_TRUE( uint4x2_equals( &actualResult, expectedAnswer ) );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint4x2_cands,
	&(uint4x2)
	{
		0U, 0U,
		0U, 0U,
		0U, 0U,
		0U, 0U
	},
	0U,
	&(uint4x2)
	{
		0U, 0U,
		0U, 0U,
		0U, 0U,
		0U, 0U
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint4x2_cands,
	&(uint4x2)
	{
		2U, 2U,
		2U, 2U,
		2U, 2U,
		2U, 2U
	},
	1U,
	&(uint4x2)
	{
		0U, 0U,
		0U, 0U,
		0U, 0U,
		0U, 0U
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint4x2_cands,
	&(uint4x2)
	{
		1U, 1U,
		1U, 1U,
		1U, 1U,
		1U, 1U
	},
	0U,
	&(uint4x2)
	{
		0U, 0U,
		0U, 0U,
		0U, 0U,
		0U, 0U
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint4x2_cands,
	&(uint4x2)
	{
		1U, 1U,
		1U, 1U,
		1U, 1U,
		1U, 1U
	},
	1U,
	&(uint4x2)
	{
		1U, 1U,
		1U, 1U,
		1U, 1U,
		1U, 1U
	}
);

TEMPER_TEST_PARAMETRIC( Test_uint4x2_cors, TEMPER_FLAG_SHOULD_RUN, const uint4x2* lhs, const uint32_t rhs, const uint4x2* expectedAnswer )
{
	uint4x2 actualResult = uint4x2_cors( lhs, rhs );
	TEMPER_CHECK_TRUE( uint4x2_equals( &actualResult, expectedAnswer ) );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint4x2_cors,
	&(uint4x2)
	{
		0U, 0U,
		0U, 0U,
		0U, 0U,
		0U, 0U
	},
	0U,
	&(uint4x2)
	{
		0U, 0U,
		0U, 0U,
		0U, 0U,
		0U, 0U
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint4x2_cors,
	&(uint4x2)
	{
		2U, 2U,
		2U, 2U,
		2U, 2U,
		2U, 2U
	},
	1U,
	&(uint4x2)
	{
		3U, 3U,
		3U, 3U,
		3U, 3U,
		3U, 3U
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint4x2_cors,
	&(uint4x2)
	{
		1U, 1U,
		1U, 1U,
		1U, 1U,
		1U, 1U
	},
	0U,
	&(uint4x2)
	{
		1U, 1U,
		1U, 1U,
		1U, 1U,
		1U, 1U
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint4x2_cors,
	&(uint4x2)
	{
		1U, 1U,
		1U, 1U,
		1U, 1U,
		1U, 1U
	},
	1U,
	&(uint4x2)
	{
		1U, 1U,
		1U, 1U,
		1U, 1U,
		1U, 1U
	}
);

TEMPER_TEST_PARAMETRIC( Test_uint4x2_cxors, TEMPER_FLAG_SHOULD_RUN, const uint4x2* lhs, const uint32_t rhs, const uint4x2* expectedAnswer )
{
	uint4x2 actualResult = uint4x2_cxors( lhs, rhs );
	TEMPER_CHECK_TRUE( uint4x2_equals( &actualResult, expectedAnswer ) );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint4x2_cxors,
	&(uint4x2)
	{
		0U, 0U,
		0U, 0U,
		0U, 0U,
		0U, 0U
	},
	0U,
	&(uint4x2)
	{
		0U, 0U,
		0U, 0U,
		0U, 0U,
		0U, 0U
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint4x2_cxors,
	&(uint4x2)
	{
		2U, 2U,
		2U, 2U,
		2U, 2U,
		2U, 2U
	},
	1U,
	&(uint4x2)
	{
		3U, 3U,
		3U, 3U,
		3U, 3U,
		3U, 3U
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint4x2_cxors,
	&(uint4x2)
	{
		1U, 1U,
		1U, 1U,
		1U, 1U,
		1U, 1U
	},
	0U,
	&(uint4x2)
	{
		1U, 1U,
		1U, 1U,
		1U, 1U,
		1U, 1U
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint4x2_cxors,
	&(uint4x2)
	{
		1U, 1U,
		1U, 1U,
		1U, 1U,
		1U, 1U
	},
	1U,
	&(uint4x2)
	{
		0U, 0U,
		0U, 0U,
		0U, 0U,
		0U, 0U
	}
);

TEMPER_TEST_PARAMETRIC( Test_uint4x2_cshift_lefts, TEMPER_FLAG_SHOULD_RUN, const uint4x2* lhs, const uint32_t rhs, const uint4x2* expectedAnswer )
{
	uint4x2 actualResult = uint4x2_cshift_lefts( lhs, rhs );
	TEMPER_CHECK_TRUE( uint4x2_equals( &actualResult, expectedAnswer ) );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint4x2_cshift_lefts,
	&(uint4x2)
	{
		0U, 0U,
		0U, 0U,
		0U, 0U,
		0U, 0U
	},
	0U,
	&(uint4x2)
	{
		0U, 0U,
		0U, 0U,
		0U, 0U,
		0U, 0U
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint4x2_cshift_lefts,
	&(uint4x2)
	{
		2U, 2U,
		2U, 2U,
		2U, 2U,
		2U, 2U
	},
	1U,
	&(uint4x2)
	{
		4U, 4U,
		4U, 4U,
		4U, 4U,
		4U, 4U
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint4x2_cshift_lefts,
	&(uint4x2)
	{
		1U, 1U,
		1U, 1U,
		1U, 1U,
		1U, 1U
	},
	0U,
	&(uint4x2)
	{
		1U, 1U,
		1U, 1U,
		1U, 1U,
		1U, 1U
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint4x2_cshift_lefts,
	&(uint4x2)
	{
		1U, 1U,
		1U, 1U,
		1U, 1U,
		1U, 1U
	},
	1U,
	&(uint4x2)
	{
		2U, 2U,
		2U, 2U,
		2U, 2U,
		2U, 2U
	}
);

TEMPER_TEST_PARAMETRIC( Test_uint4x2_cshift_rights, TEMPER_FLAG_SHOULD_RUN, const uint4x2* lhs, const uint32_t rhs, const uint4x2* expectedAnswer )
{
	uint4x2 actualResult = uint4x2_cshift_rights( lhs, rhs );
	TEMPER_CHECK_TRUE( uint4x2_equals( &actualResult, expectedAnswer ) );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint4x2_cshift_rights,
	&(uint4x2)
	{
		0U, 0U,
		0U, 0U,
		0U, 0U,
		0U, 0U
	},
	0U,
	&(uint4x2)
	{
		0U, 0U,
		0U, 0U,
		0U, 0U,
		0U, 0U
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint4x2_cshift_rights,
	&(uint4x2)
	{
		2U, 2U,
		2U, 2U,
		2U, 2U,
		2U, 2U
	},
	1U,
	&(uint4x2)
	{
		1U, 1U,
		1U, 1U,
		1U, 1U,
		1U, 1U
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint4x2_cshift_rights,
	&(uint4x2)
	{
		1U, 1U,
		1U, 1U,
		1U, 1U,
		1U, 1U
	},
	0U,
	&(uint4x2)
	{
		1U, 1U,
		1U, 1U,
		1U, 1U,
		1U, 1U
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint4x2_cshift_rights,
	&(uint4x2)
	{
		1U, 1U,
		1U, 1U,
		1U, 1U,
		1U, 1U
	},
	1U,
	&(uint4x2)
	{
		0U, 0U,
		0U, 0U,
		0U, 0U,
		0U, 0U
	}
);

TEMPER_TEST_PARAMETRIC( Test_uint4x2_candm, TEMPER_FLAG_SHOULD_RUN, const uint4x2* lhs, const uint4x2* rhs, const uint4x2* expectedAnswer )
{
	uint4x2 actualResult = uint4x2_candm( lhs, rhs );
	TEMPER_CHECK_TRUE( uint4x2_equals( &actualResult, expectedAnswer ) );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint4x2_candm,
	&(uint4x2)
	{
		0U, 0U,
		0U, 0U,
		0U, 0U,
		0U, 0U
	},
	&(uint4x2)
	{
		0U, 0U,
		0U, 0U,
		0U, 0U,
		0U, 0U
	},
	&(uint4x2)
	{
		0U, 0U,
		0U, 0U,
		0U, 0U,
		0U, 0U
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint4x2_candm,
	&(uint4x2)
	{
		2U, 2U,
		2U, 2U,
		2U, 2U,
		2U, 2U
	},
	&(uint4x2)
	{
		1U, 1U,
		1U, 1U,
		1U, 1U,
		1U, 1U
	},
	&(uint4x2)
	{
		0U, 0U,
		0U, 0U,
		0U, 0U,
		0U, 0U
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint4x2_candm,
	&(uint4x2)
	{
		1U, 1U,
		1U, 1U,
		1U, 1U,
		1U, 1U
	},
	&(uint4x2)
	{
		0U, 0U,
		0U, 0U,
		0U, 0U,
		0U, 0U
	},
	&(uint4x2)
	{
		0U, 0U,
		0U, 0U,
		0U, 0U,
		0U, 0U
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint4x2_candm,
	&(uint4x2)
	{
		1U, 1U,
		1U, 1U,
		1U, 1U,
		1U, 1U
	},
	&(uint4x2)
	{
		1U, 1U,
		1U, 1U,
		1U, 1U,
		1U, 1U
	},
	&(uint4x2)
	{
		1U, 1U,
		1U, 1U,
		1U, 1U,
		1U, 1U
	}
);

TEMPER_TEST_PARAMETRIC( Test_uint4x2_corm, TEMPER_FLAG_SHOULD_RUN, const uint4x2* lhs, const uint4x2* rhs, const uint4x2* expectedAnswer )
{
	uint4x2 actualResult = uint4x2_corm( lhs, rhs );
	TEMPER_CHECK_TRUE( uint4x2_equals( &actualResult, expectedAnswer ) );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint4x2_corm,
	&(uint4x2)
	{
		0U, 0U,
		0U, 0U,
		0U, 0U,
		0U, 0U
	},
	&(uint4x2)
	{
		0U, 0U,
		0U, 0U,
		0U, 0U,
		0U, 0U
	},
	&(uint4x2)
	{
		0U, 0U,
		0U, 0U,
		0U, 0U,
		0U, 0U
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint4x2_corm,
	&(uint4x2)
	{
		2U, 2U,
		2U, 2U,
		2U, 2U,
		2U, 2U
	},
	&(uint4x2)
	{
		1U, 1U,
		1U, 1U,
		1U, 1U,
		1U, 1U
	},
	&(uint4x2)
	{
		3U, 3U,
		3U, 3U,
		3U, 3U,
		3U, 3U
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint4x2_corm,
	&(uint4x2)
	{
		1U, 1U,
		1U, 1U,
		1U, 1U,
		1U, 1U
	},
	&(uint4x2)
	{
		0U, 0U,
		0U, 0U,
		0U, 0U,
		0U, 0U
	},
	&(uint4x2)
	{
		1U, 1U,
		1U, 1U,
		1U, 1U,
		1U, 1U
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint4x2_corm,
	&(uint4x2)
	{
		1U, 1U,
		1U, 1U,
		1U, 1U,
		1U, 1U
	},
	&(uint4x2)
	{
		1U, 1U,
		1U, 1U,
		1U, 1U,
		1U, 1U
	},
	&(uint4x2)
	{
		1U, 1U,
		1U, 1U,
		1U, 1U,
		1U, 1U
	}
);

TEMPER_TEST_PARAMETRIC( Test_uint4x2_cxorm, TEMPER_FLAG_SHOULD_RUN, const uint4x2* lhs, const uint4x2* rhs, const uint4x2* expectedAnswer )
{
	uint4x2 actualResult = uint4x2_cxorm( lhs, rhs );
	TEMPER_CHECK_TRUE( uint4x2_equals( &actualResult, expectedAnswer ) );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint4x2_cxorm,
	&(uint4x2)
	{
		0U, 0U,
		0U, 0U,
		0U, 0U,
		0U, 0U
	},
	&(uint4x2)
	{
		0U, 0U,
		0U, 0U,
		0U, 0U,
		0U, 0U
	},
	&(uint4x2)
	{
		0U, 0U,
		0U, 0U,
		0U, 0U,
		0U, 0U
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint4x2_cxorm,
	&(uint4x2)
	{
		2U, 2U,
		2U, 2U,
		2U, 2U,
		2U, 2U
	},
	&(uint4x2)
	{
		1U, 1U,
		1U, 1U,
		1U, 1U,
		1U, 1U
	},
	&(uint4x2)
	{
		3U, 3U,
		3U, 3U,
		3U, 3U,
		3U, 3U
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint4x2_cxorm,
	&(uint4x2)
	{
		1U, 1U,
		1U, 1U,
		1U, 1U,
		1U, 1U
	},
	&(uint4x2)
	{
		0U, 0U,
		0U, 0U,
		0U, 0U,
		0U, 0U
	},
	&(uint4x2)
	{
		1U, 1U,
		1U, 1U,
		1U, 1U,
		1U, 1U
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint4x2_cxorm,
	&(uint4x2)
	{
		1U, 1U,
		1U, 1U,
		1U, 1U,
		1U, 1U
	},
	&(uint4x2)
	{
		1U, 1U,
		1U, 1U,
		1U, 1U,
		1U, 1U
	},
	&(uint4x2)
	{
		0U, 0U,
		0U, 0U,
		0U, 0U,
		0U, 0U
	}
);

TEMPER_TEST_PARAMETRIC( Test_uint4x2_cshift_leftm, TEMPER_FLAG_SHOULD_RUN, const uint4x2* lhs, const uint4x2* rhs, const uint4x2* expectedAnswer )
{
	uint4x2 actualResult = uint4x2_cshift_leftm( lhs, rhs );
	TEMPER_CHECK_TRUE( uint4x2_equals( &actualResult, expectedAnswer ) );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint4x2_cshift_leftm,
	&(uint4x2)
	{
		0U, 0U,
		0U, 0U,
		0U, 0U,
		0U, 0U
	},
	&(uint4x2)
	{
		0U, 0U,
		0U, 0U,
		0U, 0U,
		0U, 0U
	},
	&(uint4x2)
	{
		0U, 0U,
		0U, 0U,
		0U, 0U,
		0U, 0U
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint4x2_cshift_leftm,
	&(uint4x2)
	{
		2U, 2U,
		2U, 2U,
		2U, 2U,
		2U, 2U
	},
	&(uint4x2)
	{
		1U, 1U,
		1U, 1U,
		1U, 1U,
		1U, 1U
	},
	&(uint4x2)
	{
		4U, 4U,
		4U, 4U,
		4U, 4U,
		4U, 4U
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint4x2_cshift_leftm,
	&(uint4x2)
	{
		1U, 1U,
		1U, 1U,
		1U, 1U,
		1U, 1U
	},
	&(uint4x2)
	{
		0U, 0U,
		0U, 0U,
		0U, 0U,
		0U, 0U
	},
	&(uint4x2)
	{
		1U, 1U,
		1U, 1U,
		1U, 1U,
		1U, 1U
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint4x2_cshift_leftm,
	&(uint4x2)
	{
		1U, 1U,
		1U, 1U,
		1U, 1U,
		1U, 1U
	},
	&(uint4x2)
	{
		1U, 1U,
		1U, 1U,
		1U, 1U,
		1U, 1U
	},
	&(uint4x2)
	{
		2U, 2U,
		2U, 2U,
		2U, 2U,
		2U, 2U
	}
);

TEMPER_TEST_PARAMETRIC( Test_uint4x2_cshift_rightm, TEMPER_FLAG_SHOULD_RUN, const uint4x2* lhs, const uint4x2* rhs, const uint4x2* expectedAnswer )
{
	uint4x2 actualResult = uint4x2_cshift_rightm( lhs, rhs );
	TEMPER_CHECK_TRUE( uint4x2_equals( &actualResult, expectedAnswer ) );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint4x2_cshift_rightm,
	&(uint4x2)
	{
		0U, 0U,
		0U, 0U,
		0U, 0U,
		0U, 0U
	},
	&(uint4x2)
	{
		0U, 0U,
		0U, 0U,
		0U, 0U,
		0U, 0U
	},
	&(uint4x2)
	{
		0U, 0U,
		0U, 0U,
		0U, 0U,
		0U, 0U
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint4x2_cshift_rightm,
	&(uint4x2)
	{
		2U, 2U,
		2U, 2U,
		2U, 2U,
		2U, 2U
	},
	&(uint4x2)
	{
		1U, 1U,
		1U, 1U,
		1U, 1U,
		1U, 1U
	},
	&(uint4x2)
	{
		1U, 1U,
		1U, 1U,
		1U, 1U,
		1U, 1U
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint4x2_cshift_rightm,
	&(uint4x2)
	{
		1U, 1U,
		1U, 1U,
		1U, 1U,
		1U, 1U
	},
	&(uint4x2)
	{
		0U, 0U,
		0U, 0U,
		0U, 0U,
		0U, 0U
	},
	&(uint4x2)
	{
		1U, 1U,
		1U, 1U,
		1U, 1U,
		1U, 1U
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint4x2_cshift_rightm,
	&(uint4x2)
	{
		1U, 1U,
		1U, 1U,
		1U, 1U,
		1U, 1U
	},
	&(uint4x2)
	{
		1U, 1U,
		1U, 1U,
		1U, 1U,
		1U, 1U
	},
	&(uint4x2)
	{
		0U, 0U,
		0U, 0U,
		0U, 0U,
		0U, 0U
	}
);

TEMPER_TEST_PARAMETRIC( Test_uint4x2_min, TEMPER_FLAG_SHOULD_RUN, const uint4x2* lhs, const uint4x2* rhs, const uint4x2* expectedAnswer )
{
	uint4x2 actualResult = uint4x2_min( lhs, rhs );
	TEMPER_CHECK_TRUE( uint4x2_equals( &actualResult, expectedAnswer ) );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint4x2_min,
	&(uint4x2)
	{
		0U, 0U,
		0U, 0U,
		0U, 0U,
		0U, 0U
	},
	&(uint4x2)
	{
		1U, 1U,
		1U, 1U,
		1U, 1U,
		1U, 1U
	},
	&(uint4x2)
	{
		0U, 0U,
		0U, 0U,
		0U, 0U,
		0U, 0U
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint4x2_min,
	&(uint4x2)
	{
		1U, 1U,
		1U, 1U,
		1U, 1U,
		1U, 1U
	},
	&(uint4x2)
	{
		2U, 2U,
		2U, 2U,
		2U, 2U,
		2U, 2U
	},
	&(uint4x2)
	{
		1U, 1U,
		1U, 1U,
		1U, 1U,
		1U, 1U
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint4x2_min,
	&(uint4x2)
	{
		420U, 420U,
		420U, 420U,
		420U, 420U,
		420U, 420U
	},
	&(uint4x2)
	{
		69U, 69U,
		69U, 69U,
		69U, 69U,
		69U, 69U
	},
	&(uint4x2)
	{
		69U, 69U,
		69U, 69U,
		69U, 69U,
		69U, 69U
	}
);

TEMPER_TEST_PARAMETRIC( Test_uint4x2_max, TEMPER_FLAG_SHOULD_RUN, const uint4x2* lhs, const uint4x2* rhs, const uint4x2* expectedAnswer )
{
	uint4x2 actualResult = uint4x2_max( lhs, rhs );
	TEMPER_CHECK_TRUE( uint4x2_equals( &actualResult, expectedAnswer ) );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint4x2_max,
	&(uint4x2)
	{
		0U, 0U,
		0U, 0U,
		0U, 0U,
		0U, 0U
	},
	&(uint4x2)
	{
		1U, 1U,
		1U, 1U,
		1U, 1U,
		1U, 1U
	},
	&(uint4x2)
	{
		1U, 1U,
		1U, 1U,
		1U, 1U,
		1U, 1U
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint4x2_max,
	&(uint4x2)
	{
		1U, 1U,
		1U, 1U,
		1U, 1U,
		1U, 1U
	},
	&(uint4x2)
	{
		2U, 2U,
		2U, 2U,
		2U, 2U,
		2U, 2U
	},
	&(uint4x2)
	{
		2U, 2U,
		2U, 2U,
		2U, 2U,
		2U, 2U
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint4x2_max,
	&(uint4x2)
	{
		69U, 69U,
		69U, 69U,
		69U, 69U,
		69U, 69U
	},
	&(uint4x2)
	{
		420U, 420U,
		420U, 420U,
		420U, 420U,
		420U, 420U
	},
	&(uint4x2)
	{
		420U, 420U,
		420U, 420U,
		420U, 420U,
		420U, 420U
	}
);

TEMPER_TEST_PARAMETRIC( Test_uint4x2_saturate, TEMPER_FLAG_SHOULD_RUN, const uint4x2* x, const uint4x2* expectedAnswer )
{
	uint4x2 actualResult = uint4x2_saturate( x );
	TEMPER_CHECK_TRUE( uint4x2_equals( &actualResult, expectedAnswer ) );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint4x2_saturate,
	&(uint4x2)
	{
		0U, 0U,
		0U, 0U,
		0U, 0U,
		0U, 0U
	},
	&(uint4x2)
	{
		0U, 0U,
		0U, 0U,
		0U, 0U,
		0U, 0U
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint4x2_saturate,
	&(uint4x2)
	{
		1U, 1U,
		1U, 1U,
		1U, 1U,
		1U, 1U
	},
	&(uint4x2)
	{
		1U, 1U,
		1U, 1U,
		1U, 1U,
		1U, 1U
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint4x2_saturate,
	&(uint4x2)
	{
		2U, 2U,
		2U, 2U,
		2U, 2U,
		2U, 2U
	},
	&(uint4x2)
	{
		1U, 1U,
		1U, 1U,
		1U, 1U,
		1U, 1U
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint4x2_saturate,
	&(uint4x2)
	{
		3U, 3U,
		3U, 3U,
		3U, 3U,
		3U, 3U
	},
	&(uint4x2)
	{
		1U, 1U,
		1U, 1U,
		1U, 1U,
		1U, 1U
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint4x2_saturate,
	&(uint4x2)
	{
		10U, 10U,
		10U, 10U,
		10U, 10U,
		10U, 10U
	},
	&(uint4x2)
	{
		1U, 1U,
		1U, 1U,
		1U, 1U,
		1U, 1U
	}
);

TEMPER_TEST_PARAMETRIC( Test_uint4x2_identity, TEMPER_FLAG_SHOULD_RUN, const uint4x2* matrix, const bool expectedAnswer )
{
	uint4x2 identityMat;
	uint4x2_identity( &identityMat );
	bool isMatrixIdentity = uint4x2_equals( &identityMat, matrix );
	TEMPER_CHECK_TRUE( isMatrixIdentity == expectedAnswer );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint4x2_identity,
	&(uint4x2)
	{
		1U, 0U,
		0U, 1U,
		0U, 0U,
		0U, 0U
	},
	true
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint4x2_identity,
	&(uint4x2)
	{
		1U, 1U,
		0U, 1U,
		0U, 0U,
		0U, 0U
	},
	false
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint4x2_identity,
	&(uint4x2)
	{
		1U, 0U,
		1U, 1U,
		0U, 0U,
		0U, 0U
	},
	false
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint4x2_identity,
	&(uint4x2)
	{
		1U, 1U,
		1U, 1U,
		0U, 0U,
		0U, 0U
	},
	false
);

TEMPER_TEST_PARAMETRIC( Test_uint4x2_transpose, TEMPER_FLAG_SHOULD_RUN, const uint4x2* matrix, const uint2x4* expectedAnswer )
{
	uint2x4 actualResult = uint4x2_transpose( matrix );
	TEMPER_CHECK_TRUE( uint2x4_equals( &actualResult, expectedAnswer ) );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint4x2_transpose,
	&(uint4x2)
	{
		1U, 0U,
		0U, 1U,
		0U, 0U,
		0U, 0U
	},
	&(uint2x4)
	{
		1U, 0U, 0U, 0U,
		0U, 1U, 0U, 0U
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint4x2_transpose,
	&(uint4x2)
	{
		0U, 1U,
		4U, 5U,
		8U, 9U,
		12U, 13U
	},
	&(uint2x4)
	{
		0U, 4U, 8U, 12U,
		1U, 5U, 9U, 13U
	}
);

TEMPER_TEST_PARAMETRIC( Test_uint4x2_mulm, TEMPER_FLAG_SHOULD_RUN, const uint4x2* lhs, const uint2x4* rhs, const uint4x4* expectedAnswer )
{
	uint4x4 actualResult = uint4x2_mulm( lhs, rhs );
	TEMPER_CHECK_TRUE( uint4x4_equals( &actualResult, expectedAnswer ) );
}

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint4x2_mulm,
	&(uint4x2)
	{
		2U, 2U,
		2U, 2U,
		2U, 2U,
		2U, 2U
	},
	&(uint2x4)
	{
		4U, 4U, 4U, 4U,
		4U, 4U, 4U, 4U
	},
	&(uint4x4)
	{
		16U, 16U, 16U, 16U,
		16U, 16U, 16U, 16U,
		16U, 16U, 16U, 16U,
		16U, 16U, 16U, 16U
	}
);

TEMPER_INVOKE_PARAMETRIC_TEST( Test_uint4x2_mulm,
	&(uint4x2)
	{
		2U, 2U,
		2U, 2U,
		2U, 2U,
		2U, 2U
	},
	&(uint2x4)
	{
		1U, 0U, 0U, 0U,
		0U, 1U, 0U, 0U
	},
	&(uint4x4)
	{
		2U, 2U, 0U, 0U,
		2U, 2U, 0U, 0U,
		2U, 2U, 0U, 0U,
		2U, 2U, 0U, 0U
	}
);


/*
===========================================================================

Temper
v2.0.0

Distributed under MIT License:
Copyright (c) 2021:

	Dan Moody (daniel.guy.moody@gmail.com)
	Mike Young (mikedotcoder@gmail.com)

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


CONTENTS:
	1. INTRO
	2. INSTALLATION
	3. QUICK START GUIDE
	4. COMMAND LINE ARGS
	5. CONTRIBUTING
	6. CREDITS
	7. CHANGELOG


1. INTRO
The new and improved C99, single-header-only, unit testing framework.

Distributed under the MIT license.  See LICENSE file for details.

Features:
	- Automatic test registration at compile time, simply write your test and it will get called for you.
	- Parametric tests.
	- Early exits for tests and a bunch of new condition macros.
	- Handling errors from your program's log output (requires a bit of extra work on your part). `// DM: I'm thinking about this`
	- Low friction, easily overridable functions to help hook Temper into your codebase.
	- Support for Clang, GCC, and MSVC across Windows, Mac OS, and Linux on x64 ISAs (support for ARM in progress).

It's not a new feature but worth stressing. It's still just the one header file.  Drop it into your project, tell it to run all tests somewhere in code and you're good to go! And once again; it's all written in C99 compliant code.


2. INSTALLATION
Download the latest release from the GitHub repository's release tab (https://github.com/dangmoody/Tantrum/releases/latest) and include `temper.h`.


3. QUICK START GUIDE
	#include <temper.h>

	// write some tests

	int main( int argc, char** argv )
	{
		TEMPER_RUN( argc, argv ); // Runs all your tests - parse 0 and NULL as parameters if you don't use start Args
		return TEMPER_GET_EXIT_CODE(); // Fetches your return code
	}

On Windows and Mac OS you shouldn't need to do anything extra on your part to get Temper to compile correctly.  There should be no other dependencies that are required.  If you find that there are, please submit a bug report (https://github.com/dangmoody/Tantrum/issues).

If you are compiling Temper on Linux and you are NOT overriding the default internal functions then you will need to make sure you pass the following arguments to your compiler/linker:
* `-ldl` - required if you're not overriding the `LoadEXEHandle()` and `UnloadEXEHandle()` functions.
* `-lpthread` - required if you're not overriding the `RunTestThread()` function.
* `--export-dynamic` - or some other equivalent, required to allow the compiler to export the test functions so they can be called dynamically by Temper at runtime.

When compiled, this will then produce an executable that will run all tests you have defined and return `TEMPDERDEV__EXIT_SUCCESS` (overridable) if there were no errors.  If there were errors then the program will return `TEMPDERDEV__EXIT_FAILURE` (overridable).


4. COMMAND LINE ARGS
Temper supports the following command line arguments:

	[-h|--help]
		Shows this help and then exits.

	-t <test>
		Only run the test with the given name.

	-s <suite>
		Only run tests in the suite with the given name.

	-p
		Enable partial filtering, which will only run tests and suites that contain the text specified in the filters.

	--time-unit [seconds|ms|us|ns|clocks]
		Set the units to measure test times in.
		The default is microseconds.


5. CONTRIBUTING
Yes!

If you want to submit an idea/bug then use the GitHub issue tracker (https://github.com/dangmoody/Tantrum/issues).

If you want to submit code then we are open to pull requests.  See contributing.md for details.


6. CREDITS
Programming:
	Dan Moody
	Mike Young

Special Thanks:
	Danny Grezel - logo!
	Zack Dutton - bug reports and testing


7. CHANGELOG
v2.0.0, 02/04/2021:
	* Nearly everything has been completely re-written from scratch.
	* Tests are now self-registering.  All you need to do now is write the test code and the tests will get called automatically for you (unless the test is marked as skipped).
		* Because of this, the functions `TEMPER_RUN_TEST` and `TEMPER_SKIP_TEST` have been removed.
		* If you want to skip a test now you must now do so by setting the test flag.
		* Due to how tests are now registered, `TEMPER_SUITE` has also been removed.
			* Suite names are now specified per-test, to allow for being able to specify tests in the same suite across multiple source files.
	* Added parametric testing.
	* Added tests that have OnBeforeTest() and OnAfterTest() callbacks.
	* Added partial filtering for tests and suites.
		* When enabled, will search for suites/tests that only contain the filter given instead of searching for an exact match.
		* Disabled by default.  Use `-p` command line argument to enable.
	* Added some more check functions to make it nicer when writing tests:
		* TEMPER_CHECK_EQUAL
		* TEMPER_CHECK_FLOAT_EQUAL
		* TEMPER_CHECK_ALMOST_EQUAL
		* TEMPER_CHECK_NOT_ALMOST_EQUAL
	* Added self-testing functionality (useful only for Temper developers).
	* Removed `TEMPER_DEFS` in favour of `TEMPER_RUN( argc, argv ) which you call inside main()`.
	* Including Temper now requires defining `TEMPER_IMPLEMENTATION` (same as stb).
	* Each test now runs in its own thread.
		* This allows tests to always exit even if a test is aborted when running code not directly inside the test function.
	* Made nearly all of the internal API extendable/overridable to help hook Temper into your codebase.
	* Removed the `-a` command line argument since this is now configured per check per test.
	* The default console output is no longer on one line to be more accomodating of test suites that have console output.
	* Tests that fail will no longer exit on the first failure, they will report all failures before exiting.
		* If you want a test to exit if it fails use the `_A` suffix on your test function.
	* Colored text console output is now always on.
		* Therefore the command line argument `-c` has been removed.
	* Removed `TEMPER_SUITE_EXTERN` and `TEMPER_TEST_EXTERN` since there is now no need for them.

v1.1.1, 01/10/2019:
	* Fix bug when parsing the --time-unit command line argument.

v1.1.0, 22/09/2019:
	* Tests now display how long they took to run (defaulting to milliseconds).
		* You can configure this yourself via the --time-unit command line argument.
		* The unit you set must be either: "seconds", "ms", "us", "ns", or "clocks" (without speech marks).

v1.0.1, 16/04/2019:
	* Support for macOS.
	* Fixed some other weird issues appearing on some other flavours of Clang and GCC on Linux.

v1.0.0, 13/02/2019:
	* Initial release.

===========================================================================
*/
#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#if defined( __clang__ )
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-function"
#pragma clang diagnostic ignored "-Wreserved-id-macro"
#pragma clang diagnostic ignored "-Wformat-nonliteral"
#pragma clang diagnostic ignored "-Wdouble-promotion"
#pragma clang diagnostic ignored "-Wgnu-zero-variadic-macro-arguments"
#pragma clang diagnostic ignored "-Wcovered-switch-default"
#pragma clang diagnostic ignored "-Wold-style-cast"
#pragma clang diagnostic ignored "-Wzero-as-null-pointer-constant"
#pragma clang diagnostic ignored "-Wc++98-compat-pedantic"
#pragma clang diagnostic ignored "-Wtypedef-redefinition"
#if defined( __APPLE__ )
// DM: only disabling this one to avoid a warning that gets generated when trying to convert function pointers to void*
// if anyone knows of a better way to get around that without disabling all pedantic warnings I'd love to hear about it
// submit an issue telling me how: https://github.com/dangmoody/Temper/issues
#pragma clang diagnostic ignored "-Wpedantic"
#endif
#elif defined( __GNUC__ )	// defined( __clang__ )
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-function"
// DM: only disabling this one to avoid a warning that gets generated when trying to convert function pointers to void*
// if anyone knows of a better way to get around that without disabling all pedantic warnings I'd love to hear about it
// submit an issue telling me how: https://github.com/dangmoody/Temper/issues
#pragma GCC diagnostic ignored "-Wpedantic"
#elif defined( _MSC_VER )
#pragma warning( push, 4 )
#pragma warning( disable : 4505 )	// unused function
#endif	// defined( __clang__ )

#if defined( __linux__ ) || defined( __APPLE__ )
#pragma push_macro( "_POSIX_C_SOURCE" )
#undef _POSIX_C_SOURCE
#define _POSIX_C_SOURCE 200112L
#endif

#if defined( __APPLE__ ) || defined( __linux__ )
#include <unistd.h>
#include <dlfcn.h>			// dlopen, dlsym, dlclose
#include <errno.h>
#include <sys/stat.h>		// lstat
#if defined( __linux__ )
#include <linux/limits.h>	// PATH_MAX
#elif defined( __APPLE__ )
#include <sys/syslimits.h>	// PATH_MAX
#include <mach-o/dyld.h>	// _NSGetExecutablePath()
#endif
#include <time.h>
#include <pthread.h>
#endif

#include <stdio.h>	// printf, snprintf
#include <stdlib.h>	// EXIT_SUCCESS, EXIT_FAILURE
#include <stdarg.h>	// va_arg
#include <string.h>	// strcmp, strstr
#include <assert.h>
#include <stdint.h>

#ifndef __cplusplus
#include <stdbool.h>
#endif


//==========================================================
// Public API
//==========================================================

// Initialises and runs Temper.
#define TEMPER_RUN( argc, argv ) \
	g_temperTestContext.exitCode = TemperExecuteAllTestsWithArgumentsInternal( argc, argv )

//----------------------------------------------------------

// Returns 'TEMPERDEV__EXIT_SUCCESS' if all tests passed, otherwise returns 'TEMPERDEV__EXIT_FAULURE'
#define TEMPER_GET_EXIT_CODE()	g_temperTestContext.exitCode

//----------------------------------------------------------

// Defines a test called 'testName', and will either run, skip, or otherwise depedening on 'runFlag'.
#define TEMPER_TEST( testName, runFlag ) \
	TEMPERDEV__DEFINE_TEST( NULL, testName, NULL, NULL, runFlag )

// Defines a test called 'testName', with callbacks 'onBefore' and 'onAfter', and will either run, skip, or otherwise depedening on 'runFlag'.
#define TEMPER_TEST_C( testName, onBefore, onAfter, runFlag ) \
	TEMPERDEV__DEFINE_TEST( NULL, testName, onBefore, onAfter, runFlag )

//----------------------------------------------------------

// Defines a test called 'testName', which is part of suite 'suiteName', and will either run, skip, or otherwise depedening on 'runFlag'.
#define TEMPER_SUITE_TEST( suiteName, testName, runFlag ) \
	TEMPERDEV__DEFINE_TEST( #suiteName, testName, NULL, NULL, runFlag )

// Defines a test called 'testName', which is part of suite 'suiteName', with callbacks 'onBefore' and 'onAfter', and will either run, skip, or otherwise depedening on 'runFlag'.
#define TEMPER_SUITE_TEST_C( suiteName,  testName, onBefore, onAfter, runFlag ) \
	TEMPERDEV__DEFINE_TEST( #suiteName, testName, onBefore, onAfter, runFlag )

//----------------------------------------------------------

// Defines a test called 'testName', that takes any user-defined parameters, and will either run, skip, or otherwise depedening on 'runFlag'.
#define TEMPER_PARAMETRIC( testName, runFlag, ... ) \
	TEMPERDEV__DEFINE_PARAMETRIC( NULL, testName, NULL, NULL, runFlag, __VA_ARGS__ )

// Defines a test called 'testName', that takes any user-defined parameters, with callbacks 'onBefore' and 'onAfter', and will either run, skip, or otherwise depedening on 'runFlag'.
#define TEMPER_PARAMETRIC_C( testName, onBefore, onAfter, runFlag, ... ) \
	TEMPERDEV__DEFINE_PARAMETRIC( NULL, testName, onBefore, onAfter, runFlag, __VA_ARGS__ )

//----------------------------------------------------------

// Defines a test called 'testName', that takes any user-defined parameters, which is part of suite 'suiteName', and will either run, skip, or otherwise depedening on 'runFlag'.
#define TEMPER_PARAMETRIC_SUITE( suiteName, testName, runFlag, ... ) \
	TEMPERDEV__DEFINE_PARAMETRIC( #suiteName, testName, NULL, NULL, runFlag, __VA_ARGS__ )

// Defines a test called 'testName', that takes any user-defined parameters, which is part of suite 'suiteName', with callbacks 'onBefore' and 'onAfter', and will either run, skip, or otherwise depedening on 'runFlag'.
#define TEMPER_PARAMETRIC_SUITE_C( suiteName, testName, onBefore, onAfter, runFlag, ... ) \
	TEMPERDEV__DEFINE_PARAMETRIC( #suiteName, testName, onBefore, onAfter, runFlag, __VA_ARGS__ )

//----------------------------------------------------------

// Runs a parametric test with the specified parameters.
#define TEMPER_INVOKE_PARAMETRIC_TEST( testName, ... ) \
	TEMPERDEV__INVOKE_PARAMETRIC_TEST( __COUNTER__, testName, __VA_ARGS__ )

//----------------------------------------------------------

// If 'condition' is NOT true then marks the test as failed.
#define TEMPER_CHECK_TRUE( condition ) \
	TemperTestTrueInternal( condition, "TEMPER_CHECK_TRUE(" #condition ")", false, __FILE__, __LINE__, NULL, NULL )

//----------------------------------------------------------

// If 'condition' is NOT true then marks the test as failed and logs the specified printf-formatted error message.
#define TEMPER_CHECK_TRUE_M( condition, ... ) \
	TemperTestTrueInternal( condition, "TEMPER_CHECK_TRUE_M(" #condition ", ...)", false, __FILE__, __LINE__, __VA_ARGS__ )

//----------------------------------------------------------

// If 'condition' is NOT true then marks the test as failed and aborts the test.
#define TEMPER_CHECK_TRUE_A( condition ) \
	TemperTestTrueInternal( condition, "TEMPER_CHECK_TRUE_A(" #condition ")", true, __FILE__, __LINE__, NULL, NULL )

//----------------------------------------------------------

// If 'condition' is NOT true then marks the test as failed, logs the specified printf-formatted error message and aborts the test.
#define TEMPER_CHECK_TRUE_AM( condition, ... ) \
	TemperTestTrueInternal( condition, "TEMPER_CHECK_TRUE_AM(" #condition ", ...)", true, __FILE__, __LINE__, __VA_ARGS__ )

//----------------------------------------------------------

// If 'condition' is NOT false then marks the test as failed.
#define TEMPER_CHECK_FALSE( condition ) \
	TemperTestTrueInternal( !(condition), "TEMPER_CHECK_FALSE(" #condition ")", false, __FILE__, __LINE__, NULL, NULL )

//----------------------------------------------------------

// If 'condition' is NOT false then marks the test as failed and logs the specified printf-formatted error message.
#define TEMPER_CHECK_FALSE_M( condition, ... ) \
	TemperTestTrueInternal( !(condition), "TEMPER_CHECK_FALSE_M(" #condition ", ...)", false, __FILE__, __LINE__, __VA_ARGS__ )

//----------------------------------------------------------

// If 'condition' is NOT false then marks the test as failed and aborts the test.
#define TEMPER_CHECK_FALSE_A( condition ) \
	TemperTestTrueInternal( !(condition), "TEMPER_CHECK_FALSE_A(" #condition ")", true, __FILE__, __LINE__, NULL, NULL )

//----------------------------------------------------------

// If 'condition' is NOT false then marks the test as failed, logs the specified printf-formatted error message and aborts the test.
#define TEMPER_CHECK_FALSE_AM( condition, ... ) \
	TemperTestTrueInternal( !(condition), "TEMPER_CHECK_FALSE_AM(" #condition ", ...)", true, __FILE__, __LINE__, __VA_ARGS__ )

//----------------------------------------------------------

// If 'conditionA' is NOT equal to 'conditionB' then marks the test as failed.
#define TEMPER_CHECK_EQUAL( conditionA, conditionB ) \
	TemperTestTrueInternal( conditionA == conditionB, "TEMPER_CHECK_EQUAL(" #conditionA ", " #conditionB ")", false, __FILE__, __LINE__, NULL, NULL )

//----------------------------------------------------------

// If 'conditionA' is NOT equal to 'conditionB' then marks the test as failed and logs the specified printf-formatted error message.
#define TEMPER_CHECK_EQUAL_M( conditionA, conditionB, ... ) \
	TemperTestTrueInternal( conditionA == conditionB, "TEMPER_CHECK_EQUAL_M(" #conditionA ", " #conditionB ", ...)", false, __FILE__, __LINE__, __VA_ARGS__ )

//----------------------------------------------------------

// If 'conditionA' is NOT equal to 'conditionB' then marks the test as failed and aborts the test.
#define TEMPER_CHECK_EQUAL_A( conditionA, conditionB ) \
	TemperTestTrueInternal( conditionA == conditionB, "TEMPER_CHECK_EQUAL_A(" #conditionA ", " #conditionB ")", true, __FILE__, __LINE__, NULL, NULL )

//----------------------------------------------------------

// If 'conditionA' is NOT equal to 'conditionB' then marks the test as failed, logs the specified printf-formatted error message and aborts the test.
#define TEMPER_CHECK_EQUAL_AM( conditionA, conditionB, ... ) \
	TemperTestTrueInternal( conditionA == conditionB, "TEMPER_CHECK_EQUAL_AM(" #conditionA ", " #conditionB ", ...)", true, __FILE__, __LINE__, __VA_ARGS__ )

//----------------------------------------------------------

// If 'conditionA' is equal to 'conditionB' then marks the test as failed.
#define TEMPER_CHECK_NOT_EQUAL( conditionA, conditionB ) \
	TemperTestTrueInternal( conditionA != conditionB, "TEMPER_CHECK_NOT_EQUAL(" #conditionA ", " #conditionB ")", false, __FILE__, __LINE__, NULL, NULL )

//----------------------------------------------------------

// If 'conditionA' is equal to 'conditionB' then marks the test as failed and logs the specified printf-formatted error message.
#define TEMPER_CHECK_NOT_EQUAL_M( conditionA, conditionB, ... ) \
	TemperTestTrueInternal( conditionA != conditionB, "TEMPER_CHECK_NOT_EQUAL_M(" #conditionA ", " #conditionB ", ...)", false, __FILE__, __LINE__, __VA_ARGS__ )

//----------------------------------------------------------

// If 'conditionA' is equal to 'conditionB' then marks the test as failed and aborts the test.
#define TEMPER_CHECK_NOT_EQUAL_A( conditionA, conditionB ) \
	TemperTestTrueInternal( conditionA != conditionB, "TEMPER_CHECK_NOT_EQUAL_A(" #conditionA ", " #conditionB ")", true, __FILE__, __LINE__, NULL, NULL )

//----------------------------------------------------------

// If 'conditionA' is equal to 'conditionB' then marks the test as failed, logs the specified printf-formatted error message and aborts the test.
#define TEMPER_CHECK_NOT_EQUAL_AM( conditionA, conditionB, ... ) \
	TemperTestTrueInternal( conditionA != conditionB, "TEMPER_CHECK_NOT_EQUAL_AM(" #conditionA ", " #conditionB ", ...)", true, __FILE__, __LINE__, __VA_ARGS__ )

//----------------------------------------------------------

// If 'floatA' is NOT approximately equal enough to floatB (within Temper's default margins of error) then marks the test as failed.
#define TEMPER_CHECK_FLOAT_EQUAL( floatA, floatB ) \
	TemperTestTrueInternal( TEMPERDEV__FLOAT_EQUALS( floatA, floatB, TEMPERDEV__EPSILON_TOLERANCE_ABSOLUTE, TEMPERDEV__EPSILON_TOLERANCE_RELATIVE ), "TEMPER_CHECK_FLOAT_EQUAL(" #floatA ", " #floatB ")", false, __FILE__, __LINE__, NULL, NULL )

//----------------------------------------------------------

// If 'floatA' is NOT approximately equal enough to floatB (within Temper's default margins of error) then marks the test as failed and logs the specified printf-formatted error message.
#define TEMPER_CHECK_FLOAT_EQUAL_M( floatA, floatB, ... ) \
	TemperTestTrueInternal( TEMPERDEV__FLOAT_EQUALS( floatA, floatB, TEMPERDEV__EPSILON_TOLERANCE_ABSOLUTE, TEMPERDEV__EPSILON_TOLERANCE_RELATIVE ), "TEMPER_CHECK_FLOAT_EQUAL_M(" #floatA ", " #floatB ", ...)", false, __FILE__, __LINE__, __VA_ARGS__ )

//----------------------------------------------------------

// If 'floatA' is NOT approximately equal enough to floatB (within Temper's default margins of error) then marks the test as failed and aborts the test.
#define TEMPER_CHECK_FLOAT_EQUAL_A( floatA, floatB ) \
	TemperTestTrueInternal( TEMPERDEV__FLOAT_EQUALS( floatA, floatB, TEMPERDEV__EPSILON_TOLERANCE_ABSOLUTE, TEMPERDEV__EPSILON_TOLERANCE_RELATIVE ), "TEMPER_CHECK_FLOAT_EQUAL_A(" #floatA ", " #floatB ")", true, __FILE__, __LINE__, NULL, NULL )

//----------------------------------------------------------

// If 'floatA' is NOT approximately equal enough to floatB (within Temper's default margins of error) then marks the test as failed, logs the specified printf-formatted error message, and aborts the test.
#define TEMPER_CHECK_FLOAT_EQUAL_AM( floatA, floatB, ... ) \
	TemperTestTrueInternal( TEMPERDEV__FLOAT_EQUALS( floatA, floatB, TEMPERDEV__EPSILON_TOLERANCE_ABSOLUTE, TEMPERDEV__EPSILON_TOLERANCE_RELATIVE ), "TEMPER_CHECK_FLOAT_EQUAL_AM(" #floatA ", " #floatB ", ...)", true, __FILE__, __LINE__, __VA_ARGS__ )

//----------------------------------------------------------

// If 'conditionA' is NOT approximately equal enough to 'conditionB' (within 'tolerance' margin of error) then marks the test as failed.
#define TEMPER_CHECK_ALMOST_EQUAL( conditionA, conditionB, absoluteTolerance ) \
	TemperTestTrueInternal( TEMPERDEV__FLOAT_EQUALS( conditionA, conditionB, absoluteTolerance, TEMPERDEV__EPSILON_TOLERANCE_RELATIVE ), "TEMPER_CHECK_ALMOST_EQUAL(" #conditionA ", " #conditionB ", " #absoluteTolerance ")", false, __FILE__, __LINE__, NULL, NULL )

//----------------------------------------------------------

// If 'conditionA' is NOT approximately equal enough to 'conditionB' (within 'absoluteTolerance' margin of error) then marks the test as failed and logs the specified printf-formatted error message.
#define TEMPER_CHECK_ALMOST_EQUAL_M( conditionA, conditionB, absoluteTolerance, ... ) \
	TemperTestTrueInternal( TEMPERDEV__FLOAT_EQUALS( conditionA, conditionB, absoluteTolerance, TEMPERDEV__EPSILON_TOLERANCE_RELATIVE ), "TEMPER_CHECK_ALMOST_EQUAL_M(" #conditionA ", " #conditionB ", " #absoluteTolerance ", ...)", false, __FILE__, __LINE__, __VA_ARGS__ )

//----------------------------------------------------------

// If 'conditionA' is NOT approximately equal enough to 'conditionB' (within 'absoluteTolerance' margin of error) then marks the test as failed and aborts the test.
#define TEMPER_CHECK_ALMOST_EQUAL_A( conditionA, conditionB, absoluteTolerance ) \
	TemperTestTrueInternal( TEMPERDEV__FLOAT_EQUALS( conditionA, conditionB, absoluteTolerance, TEMPERDEV__EPSILON_TOLERANCE_RELATIVE ), "TEMPER_CHECK_ALMOST_EQUAL_A(" #conditionA ", " #conditionB ", " #absoluteTolerance ")", true, __FILE__, __LINE__, NULL, NULL )

//----------------------------------------------------------

// If 'conditionA' is NOT approximately equal enough to 'conditionB' (within 'absoluteTolerance' margin of error) then marks the test as failed, logs the specified printf-formatted error message, and aborts the test.
#define TEMPER_CHECK_ALMOST_EQUAL_AM( conditionA, conditionB, absoluteTolerance, ... ) \
	TemperTestTrueInternal( TEMPERDEV__FLOAT_EQUALS( conditionA, conditionB, absoluteTolerance, TEMPERDEV__EPSILON_TOLERANCE_RELATIVE ), "TEMPER_CHECK_ALMOST_EQUAL_AM(" #conditionA ", " #conditionB ", " #absoluteTolerance ", ...)", true, __FILE__, __LINE__, __VA_ARGS__ )

//----------------------------------------------------------

// If 'conditionA' is approximately equal enough to 'conditionB' (within 'absoluteTolerance' margin of error) then marks the test as failed.
#define TEMPER_CHECK_NOT_ALMOST_EQUAL( conditionA, conditionB, absoluteTolerance ) \
	TemperTestTrueInternal( !TEMPERDEV__FLOAT_EQUALS( conditionA, conditionB, absoluteTolerance, TEMPERDEV__EPSILON_TOLERANCE_RELATIVE ), "TEMPER_CHECK_NOT_ALMOST_EQUAL(" #conditionA ", " #conditionB ", " #absoluteTolerance ")", false, __FILE__, __LINE__, NULL, NULL )

//----------------------------------------------------------

// If 'conditionA' is approximately equal enough to 'conditionB' (within 'absoluteTolerance' margin of error) then marks the test as failed and logs the specified printf-formatted error message.
#define TEMPER_CHECK_NOT_ALMOST_EQUAL_M( conditionA, conditionB, absoluteTolerance, ... ) \
	TemperTestTrueInternal( !TEMPERDEV__FLOAT_EQUALS( conditionA, conditionB, absoluteTolerance, TEMPERDEV__EPSILON_TOLERANCE_RELATIVE ), "TEMPER_CHECK_NOT_ALMOST_EQUAL_M(" #conditionA ", " #conditionB ", " #absoluteTolerance ", ...)", false,  __FILE__, __LINE__, __VA_ARGS__ )

//----------------------------------------------------------

// If 'conditionA' is approximately equal enough to 'conditionB' (within 'absoluteTolerance' margin of error) then marks the test as failed and aborts the test.
#define TEMPER_CHECK_NOT_ALMOST_EQUAL_A( conditionA, conditionB, absoluteTolerance ) \
	TemperTestTrueInternal( !TEMPERDEV__FLOAT_EQUALS( conditionA, conditionB, absoluteTolerance, TEMPERDEV__EPSILON_TOLERANCE_RELATIVE ), "TEMPER_CHECK_NOT_ALMOST_EQUAL_A(" #conditionA ", " #conditionB ", " #absoluteTolerance ")", true, __FILE__, __LINE__, NULL, NULL )

//----------------------------------------------------------

// If 'conditionA' is approximately equal enough to 'conditionB' (within 'absoluteTolerance' margin of error) then marks the test as failed, logs the specified printf-formatted error message, and aborts the test.
#define TEMPER_CHECK_NOT_ALMOST_EQUAL_AM( conditionA, conditionB, absoluteTolerance, ... ) \
	TemperTestTrueInternal( !TEMPERDEV__FLOAT_EQUALS( conditionA, conditionB, absoluteTolerance, TEMPERDEV__EPSILON_TOLERANCE_RELATIVE ), "TEMPER_CHECK_NOT_ALMOST_EQUAL_AM(" #conditionA ", " #conditionB ", " #absoluteTolerance ", ...)", true, __FILE__, __LINE__, __VA_ARGS__ )


//==========================================================
// User-Overridable Preprocessor defines
//
// By default, Temper will use it's own internal implementations for things.
// But you can override them to help hook Temper into your codebase.
// This must be done before including temper.h
//==========================================================

// Returns a timestamp from the CPU in the 'timeUnit' format.
// See temperTimeUnit_t for time units.
#ifndef TEMPER_GET_TIMESTAMP
#define TEMPER_GET_TIMESTAMP				TemperGetTimestampInternal
#endif

// The code that gets returned if all tests passed.
#ifndef TEMPERDEV__EXIT_SUCCESS
#define TEMPERDEV__EXIT_SUCCESS				EXIT_SUCCESS
#endif

// The code that gets returned if at least one test failed.
#ifndef TEMPERDEV__EXIT_FAILURE
#define TEMPERDEV__EXIT_FAILURE				EXIT_FAILURE
#endif

// Mainly used to avoid 'unused variable' warnings generated by compilers.
#ifndef TEMPERDEV__UNUSED
#define TEMPERDEV__UNUSED( x )				( (void) x )
#endif

#ifndef TEMPERDEV__REALLOC
#define TEMPERDEV__REALLOC					realloc
#endif

#ifndef TEMPERDEV__ASSERT
#define TEMPERDEV__ASSERT					assert
#endif

#ifndef TEMPERDEV__VPRINTF
#define TEMPERDEV__VPRINTF					vprintf
#endif

#ifndef TEMPERDEV__STRCMP
#define TEMPERDEV__STRCMP					strcmp
#endif

#ifndef TEMPERDEV__STRSTR
#define TEMPERDEV__STRSTR					strstr
#endif

#ifndef TEMPERDEV__MAXF
#define TEMPERDEV__MAXF						TemperMaxfInternal
#endif

#ifndef TEMPERDEV__ABSF
#define TEMPERDEV__ABSF						TemperAbsfInternal
#endif

#ifndef TEMPERDEV__FLOAT_EQUALS
#define TEMPERDEV__FLOAT_EQUALS				TemperFloatEqualsInternal
#endif

#ifndef TEMPERDEV__LOG
#define TEMPERDEV__LOG						TemperLogInternal
#endif

#ifndef TEMPERDEV__LOG_WARNING
#define TEMPERDEV__LOG_WARNING				TemperLogWarningInternal
#endif

#ifndef TEMPERDEV__LOG_ERROR
#define TEMPERDEV__LOG_ERROR				TemperLogErrorInternal
#endif

#ifndef TEMPERDEV__ON_BEFORE_TEST
#define TEMPERDEV__ON_BEFORE_TEST			TemperOnBeforeTestInternal
#endif

#ifndef TEMPERDEV__ON_AFTER_TEST
#define TEMPERDEV__ON_AFTER_TEST			TemperOnAfterTestInternal
#endif

#ifndef TEMPERDEV__RUN_TEST_THREAD
#define TEMPERDEV__RUN_TEST_THREAD			TemperRunTestThreadInternal
#endif

#ifndef TEMPERDEV__ON_ALL_TESTS_FINISHED
#define TEMPERDEV__ON_ALL_TESTS_FINISHED	TemperOnAllTestsFinishedInternal
#endif


//==========================================================
// Internal API
//
// You as the user probably don't want to be directly touching any of this.
//==========================================================

typedef uint32_t temperBool32;

//----------------------------------------------------------

typedef enum temperTimeUnit_t {
	TEMPER_TIME_UNIT_CLOCKS	= 1,
	TEMPER_TIME_UNIT_NS,
	TEMPER_TIME_UNIT_US,
	TEMPER_TIME_UNIT_MS,
	TEMPER_TIME_UNIT_SECONDS
} temperTimeUnit_t;

//----------------------------------------------------------

typedef enum temperTestFlag_t {
	TEMPER_FLAG_SHOULD_RUN				= 0,
	TEMPER_FLAG_SHOULD_SKIP,
	TEMPER_FLAG_DEPRECATED
} temperTestFlag_t;

//----------------------------------------------------------

typedef void( *temperTestCallbackOnBeforeTest_t )( void );
typedef void( *temperTestCallbackOnAfterTest_t )( void );

typedef void( *temperTestCallback_t )( void );

//----------------------------------------------------------

typedef struct temperTestInfo_t {
	temperTestCallbackOnBeforeTest_t	OnBeforeTest;
	temperTestCallback_t				TestFuncCallback;
	temperTestCallbackOnAfterTest_t		OnAfterTest;
	double								testTimeTaken;
	temperTestFlag_t					testingFlag;
	uint32_t							pad0;
	const char*							testNameStr;
	const char*							suiteNameStr;
} temperTestInfo_t;

//----------------------------------------------------------

typedef struct temperTestContext_t {
	uint64_t			testInfosCount;
	temperTestInfo_t*	testInfos;
#ifdef _WIN32
	int64_t				timestampFrequency;
#endif
	double				currentTestStartTime;
	double				currentTestEndTime;
	double				totalExecutionTime;
	uint32_t			testsPassed;
	uint32_t			testsFailed;
	uint32_t			testsAborted;
	uint32_t			testsSkipped;
	uint32_t			totalTestsFoundWithFilters;
	uint32_t			totalTestsExecuted;
	uint32_t			currentTestErrorCount;
	int32_t				exitCode;
	temperBool32		currentTestWasAborted;
	temperBool32		partialFilter;
	temperTimeUnit_t	timeUnit;
	uint32_t			pad0;
	const char*			suiteFilterPrevious;
	const char*			suiteFilter;
	const char*			testFilter;
} temperTestContext_t;

//----------------------------------------------------------

#ifdef __cplusplus
#define TEMPERDEV__EXTERN_C				extern "C"
#else
#define TEMPERDEV__EXTERN_C				extern
#endif

//----------------------------------------------------------

TEMPERDEV__EXTERN_C temperTestContext_t g_temperTestContext;

//----------------------------------------------------------

#define TEMPERDEV__BIT( x )				( 1 << ( x ) )

//----------------------------------------------------------

#if defined( _WIN32 )
#define TEMPERDEV__EXIT_TEST_THREAD()	ExitThread( TEMPERDEV__EXIT_FAILURE )
#else
#define TEMPERDEV__EXIT_TEST_THREAD()	pthread_exit( NULL )
#endif

//----------------------------------------------------------

#define TEMPERDEV__EPSILON_TOLERANCE_ABSOLUTE	1e-6f
#define TEMPERDEV__EPSILON_TOLERANCE_RELATIVE	1e-9f

//----------------------------------------------------------

#define TEMPERDEV__CONCAT_( a, b )		a ## b
#define TEMPERDEV__CONCAT( a, b )		TEMPERDEV__CONCAT_( a, b )	// use this one

//----------------------------------------------------------

#define TEMPERDEV__STRINGIFY_( x )		#x
#define TEMPERDEV__STRINGIFY( x )		TEMPERDEV__STRINGIFY_( x )	// use this one

//----------------------------------------------------------

#if defined( __clang__ )
#define TEMPERDEV__TEST_INFO_FETCHER( testName ) \
	void TEMPERDEV__CONCAT( __temper_test_info_fetcher_, testName )( void ) __attribute__( ( constructor ) ); \
	void TEMPERDEV__CONCAT( __temper_test_info_fetcher_, testName )( void )
#elif defined( __GNUC__ )
#define TEMPERDEV__TEST_INFO_FETCHER( testName ) \
	/* add 101 because gcc reserves constructors with priorities between 0 - 100 and __COUNTER__ starts at 0 */ \
	void TEMPERDEV__CONCAT( __temper_test_info_fetcher_, testName )( void ) __attribute__( ( constructor( __COUNTER__ + 101 ) ) ); \
	void TEMPERDEV__CONCAT( __temper_test_info_fetcher_, testName )( void )
#elif defined( _MSC_VER )	// defined( __GNUC__ ) || defined( __clang__ )
#ifdef _WIN64
#define TEMPERDEV__MSVC_PREFIX	""
#else
#define TEMPERDEV__MSVC_PREFIX	"_"
#endif

#pragma section( ".CRT$XCU", read )
#define TEMPERDEV__TEST_INFO_FETCHER( testName ) \
	void TEMPERDEV__CONCAT( __temper_test_info_fetcher_, testName )( void ); \
\
	TEMPERDEV__EXTERN_C __declspec( allocate( ".CRT$XCU" ) ) void ( * TEMPERDEV__CONCAT( testName, _FuncPtr ) )( void ) = TEMPERDEV__CONCAT( __temper_test_info_fetcher_, testName ); \
	__pragma( comment( linker, "/include:" TEMPERDEV__MSVC_PREFIX TEMPERDEV__CONCAT( TEMPERDEV__STRINGIFY( testName ), "_FuncPtr" ) ) ) \
\
	void TEMPERDEV__CONCAT( __temper_test_info_fetcher_, testName )( void )
#endif	// defined( _MSC_VER )

//----------------------------------------------------------

#define TEMPERDEV__DEFINE_TEST( suiteNameString, testName, onBeforeName, onAfterName, runFlag ) \
	/*1. Create a function with a name matching the test.*/ \
	void ( testName )( void ); \
\
	/*2. This is what the runner will loop over to grab the test function as well as all the information concerning it*/ \
	TEMPERDEV__TEST_INFO_FETCHER( testName ) { \
		temperTestInfo_t testInfo; \
		testInfo.OnBeforeTest		= onBeforeName; \
		testInfo.TestFuncCallback	= testName; \
		testInfo.OnAfterTest		= onAfterName; \
		testInfo.testingFlag		= runFlag; \
		testInfo.suiteNameStr		= suiteNameString; \
		testInfo.testNameStr		= #testName; \
\
		TemperAddTestInternal( &testInfo ); \
	} \
\
	/*3. The test function declared at Step1 is now declared here by the user*/ \
	void ( testName )( void )

//----------------------------------------------------------

#define TEMPERDEV__DEFINE_PARAMETRIC( suiteNameString, testName, onBeforeName, onAfterName, runFlag, ... ) \
	void TemperGetParametricTestInfo_ ## testName( temperTestInfo_t* outInfo ); \
	void TemperGetParametricTestInfo_ ## testName( temperTestInfo_t* outInfo ) { \
		outInfo->OnBeforeTest	= onBeforeName; \
		outInfo->OnAfterTest	= onAfterName; \
		outInfo->testingFlag	= runFlag; \
		outInfo->suiteNameStr	= suiteNameString; \
		outInfo->testNameStr	= #testName; \
	} \
\
	void ( testName )( __VA_ARGS__ ); \
	void ( testName )( __VA_ARGS__ )

//----------------------------------------------------------

#define TEMPERDEV__INVOKE_PARAMETRIC_TEST( counter, testName, ... ) \
	void TEMPERDEV__CONCAT( TemperCallParametricTest_, TEMPERDEV__CONCAT( testName, counter ) )( void ); \
	void TEMPERDEV__CONCAT( TemperCallParametricTest_, TEMPERDEV__CONCAT( testName, counter ) )( void ) { \
		testName( __VA_ARGS__ ); \
	} \
\
	TEMPERDEV__TEST_INFO_FETCHER( TEMPERDEV__CONCAT( testName, counter ) ) { \
		temperTestInfo_t testInfo; \
		TemperGetParametricTestInfo_ ## testName( &testInfo ); \
		testInfo.TestFuncCallback = TEMPERDEV__CONCAT( TemperCallParametricTest_, TEMPERDEV__CONCAT( testName, counter ) ); \
\
		TemperAddTestInternal( &testInfo ); \
	} \
\
	void TEMPERDEV__CONCAT( __temper_test_info_fetcher_, TEMPERDEV__CONCAT( testName, counter ) )( void )

//----------------------------------------------------------

#if defined( _WIN32 )
#define TEMPERDEV__COLOR_DEFAULT	0x07
#define TEMPERDEV__COLOR_RED		0x0C
#define TEMPERDEV__COLOR_GREEN		0x02
#define TEMPERDEV__COLOR_YELLOW		0x0E

typedef uint32_t					temperTextColor_t;
#elif defined( __linux__ ) || defined( __APPLE__ )
#define TEMPERDEV__COLOR_DEFAULT	"\033[0m"
#define TEMPERDEV__COLOR_RED		"\033[0;31m"
#define TEMPERDEV__COLOR_GREEN		"\033[0;32m"
#define TEMPERDEV__COLOR_YELLOW		"\033[1;33m"

typedef const char*					temperTextColor_t;
#endif // defined( _WIN32 )

//----------------------------------------------------------

TEMPERDEV__EXTERN_C void	TemperAddTestInternal( const temperTestInfo_t* newTestInfo );

TEMPERDEV__EXTERN_C void	TemperTestTrueInternal( const bool condition, const char* conditionStr, const bool abortOnFail, const char* file, const uint32_t line, const char* fmt, ... );

TEMPERDEV__EXTERN_C void	TemperSetupInternal( void );

TEMPERDEV__EXTERN_C int		TemperExecuteAllTestsInternal( void );

TEMPERDEV__EXTERN_C int		TemperExecuteAllTestsWithArgumentsInternal( int argc, char** argv );

TEMPERDEV__EXTERN_C bool	TemperFloatEqualsInternal( const float a, const float b, const float absoluteTolerance, const float relativeTolerance );

//----------------------------------------------------------

#ifdef TEMPER_IMPLEMENTATION
#ifdef _WIN32
#include <Windows.h>
#endif

temperTestContext_t g_temperTestContext;

//----------------------------------------------------------

static void TemperSetTextColorInternal( const temperTextColor_t color ) {
#if defined( _WIN32 )
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), (WORD) color );
#elif defined( __APPLE__ ) || defined( __linux__ )
	printf( "%s", color );
#else
#error Uncrecognised platform.  It appears Temper does not support it.  If you think this is a bug, please submit an issue at https://github.com/dangmoody/Temper/issues
#endif
}

//----------------------------------------------------------

static void TemperLogInternal( const char* fmt, ... ) {
	TEMPERDEV__ASSERT( fmt );

	va_list args;
	va_start( args, fmt );
	TEMPERDEV__VPRINTF( fmt, args );
	va_end( args );
}

//----------------------------------------------------------

static void TemperLogWarningInternal( const char* fmt, ... ) {
	TEMPERDEV__ASSERT( fmt );

	va_list args;
	va_start( args, fmt );

	TemperSetTextColorInternal( TEMPERDEV__COLOR_RED );

	printf( "WARNING: " );

	TemperSetTextColorInternal( TEMPERDEV__COLOR_YELLOW );

	TEMPERDEV__VPRINTF( fmt, args );

	TemperSetTextColorInternal( TEMPERDEV__COLOR_DEFAULT );

	va_end( args );
}

//----------------------------------------------------------

static void TemperLogErrorInternal( const char* fmt, ... ) {
	TEMPERDEV__ASSERT( fmt );

	va_list args;
	va_start( args, fmt );

	TemperSetTextColorInternal( TEMPERDEV__COLOR_RED );

	printf( "ERROR: " );

	TemperSetTextColorInternal( TEMPERDEV__COLOR_YELLOW );

	TEMPERDEV__VPRINTF( fmt, args );

	TemperSetTextColorInternal( TEMPERDEV__COLOR_DEFAULT );

	va_end( args );
}

//----------------------------------------------------------

static uint32_t TemperGetPercentInternal( uint32_t yourValue, uint32_t yourMax ) {
	return (uint32_t) ( ( ( (float) yourValue ) / ( (float) yourMax ) ) * 100 );
}

//----------------------------------------------------------

static float TemperMaxfInternal( const float a, const float b ) {
	return ( a > b ) ? a : b;
}

//----------------------------------------------------------

static float TemperAbsfInternal( const float x ) {
	return TEMPERDEV__MAXF( -x, x );
}

//----------------------------------------------------------

// uses Christer Ericson's solution:
// https://realtimecollisiondetection.net/blog/?p=89
bool TemperFloatEqualsInternal( const float a, const float b, const float absoluteTolerance, const float relativeTolerance ) {
	return TEMPERDEV__ABSF( a - b ) <= TEMPERDEV__MAXF( absoluteTolerance, relativeTolerance * TEMPERDEV__MAXF( TEMPERDEV__ABSF( a ), TEMPERDEV__ABSF( b ) ) );
}

//----------------------------------------------------------

void TemperAddTestInternal( const temperTestInfo_t* newTestInfo ) {
	TEMPERDEV__ASSERT( newTestInfo );
	TEMPERDEV__ASSERT( newTestInfo->TestFuncCallback );
	TEMPERDEV__ASSERT( newTestInfo->testNameStr );

	uint64_t index = g_temperTestContext.testInfosCount++;

	g_temperTestContext.testInfos = (temperTestInfo_t*) TEMPERDEV__REALLOC( g_temperTestContext.testInfos, g_temperTestContext.testInfosCount * sizeof( temperTestInfo_t ) );

	temperTestInfo_t* testInfo = &g_temperTestContext.testInfos[index];
	testInfo->OnBeforeTest		= newTestInfo->OnBeforeTest;
	testInfo->TestFuncCallback	= newTestInfo->TestFuncCallback;
	testInfo->OnAfterTest		= newTestInfo->OnAfterTest;
	testInfo->testingFlag		= newTestInfo->testingFlag;
	testInfo->suiteNameStr		= newTestInfo->suiteNameStr;
	testInfo->testNameStr		= newTestInfo->testNameStr;
}

//----------------------------------------------------------

static const char* TemperGetNextArgInternal( const int argIndex, const int argc, char** argv ) {
	TEMPERDEV__ASSERT( argc );
	TEMPERDEV__ASSERT( argv );

	return ( argIndex + 1 < argc ) ? argv[argIndex + 1] : NULL;
}

//----------------------------------------------------------

static double TemperGetTimestampInternal( const temperTimeUnit_t timeUnit ) {
	// should never get here
	TEMPERDEV__ASSERT( ( timeUnit > TEMPER_TIME_UNIT_CLOCKS && timeUnit <= TEMPER_TIME_UNIT_SECONDS ) && "Unrecognised time unit passed into TemperGetTimestampInternal().\n" );

#if defined( _WIN32 )
	LARGE_INTEGER now;
	QueryPerformanceCounter( &now );

	switch ( timeUnit ) {
		case TEMPER_TIME_UNIT_CLOCKS:	return ( (double) now.QuadPart );
		case TEMPER_TIME_UNIT_NS:		return ( (double) ( now.QuadPart * 1000000000 ) / (double) g_temperTestContext.timestampFrequency );
		case TEMPER_TIME_UNIT_US:		return ( (double) ( now.QuadPart * 1000000 ) / (double) g_temperTestContext.timestampFrequency );
		case TEMPER_TIME_UNIT_MS:		return ( (double) ( now.QuadPart * 1000 ) / (double) g_temperTestContext.timestampFrequency );
		case TEMPER_TIME_UNIT_SECONDS:	return ( (double) ( now.QuadPart ) / (double) g_temperTestContext.timestampFrequency );
	}
#elif defined( __APPLE__ ) || defined( __linux__ )	// defined( _WIN32 )
	struct timespec now;
	clock_gettime( CLOCK_MONOTONIC, &now );

	int64_t clocks = (int64_t) ( now.tv_sec * 1000000000 + now.tv_nsec );

	switch ( timeUnit ) {
		case TEMPER_TIME_UNIT_CLOCKS:	return (double) clocks;
		case TEMPER_TIME_UNIT_NS:		return (double) clocks;
		case TEMPER_TIME_UNIT_US:		return (double) clocks / 1000.0;
		case TEMPER_TIME_UNIT_MS:		return (double) clocks / 1000000.0;
		case TEMPER_TIME_UNIT_SECONDS:	return (double) clocks / 1000000000.0;
	}
#else	// defined( _WIN32 )
#error Uncrecognised platform.  It appears Temper does not support it.  If you think this is a bug, please submit an issue at https://github.com/dangmoody/Temper/issues
#endif	// defined( _WIN32 )

	// never gets here
	return 0.0;
}

//----------------------------------------------------------

static void TemperShowUsageInternal( void ) {
	TEMPERDEV__LOG(
		"Arguments:\n"
		"    [-h|--help]\n"
		"        Shows this help and then exits.\n"
		"\n"
		"    -t <test>\n"
		"        Only run the test with the given name.\n"
		"\n"
		"    -s <suite>\n"
		"        Only run tests in the suite with the given name.\n"
		"\n"
		"    -p\n"
		"        Enable partial filtering, which will only run tests and suites that contain the text specified in the filters.\n"
		"\n"
		"    --time-unit [seconds|ms|us|ns|clocks]\n"
		"        Set the units to measure test times in.\n"
		"        The default is microseconds.\n"
		"\n"
	);
}

//----------------------------------------------------------

static bool TemperHandleCommandLineArgumentsInternal( int argc, char** argv ) {
	// parse command line args
	for ( int argIndex = 0; argIndex < argc; argIndex++ ) {
		const char* arg = argv[argIndex];

		if ( TEMPERDEV__STRCMP( arg, "-h" ) == 0 || TEMPERDEV__STRCMP( arg, "--help" ) == 0 ) {
			TemperShowUsageInternal();
			return false;
		}

		if ( TEMPERDEV__STRCMP( arg, "-s" ) == 0 ) {
			const char* nextArg = TemperGetNextArgInternal( argIndex, argc, argv );
			if ( !nextArg ) {
				TEMPERDEV__LOG_ERROR( "Value for argument \"%s\" was not set.\n", arg );
				TemperShowUsageInternal();
				return false;
			}

			g_temperTestContext.suiteFilter = nextArg;

			continue;
		}

		if ( TEMPERDEV__STRCMP( arg, "-t" ) == 0 ) {
			const char* nextArg = TemperGetNextArgInternal( argIndex, argc, argv );
			if ( !nextArg ) {
				TEMPERDEV__LOG_ERROR( "Value for argument \"%s\" was not set.\n", arg );
				TemperShowUsageInternal();
				return false;
			}

			g_temperTestContext.testFilter = nextArg;

			continue;
		}

		if ( TEMPERDEV__STRCMP( arg, "-p" ) == 0 ) {
			g_temperTestContext.partialFilter = true;
			continue;
		}

		if ( TEMPERDEV__STRCMP( arg, "--time-unit" ) == 0 ) {
			const char* nextArg = TemperGetNextArgInternal( argIndex, argc, argv );
			if ( !nextArg ) {
				TEMPERDEV__LOG_ERROR( "Value for argument \"%s\" was not set.\n", arg );
				TemperShowUsageInternal();
				return false;
			}

			if ( TEMPERDEV__STRCMP( nextArg, "seconds" ) == 0 ) {
				g_temperTestContext.timeUnit = TEMPER_TIME_UNIT_SECONDS;
			} else if ( TEMPERDEV__STRCMP( nextArg, "ms" ) == 0 ) {
				g_temperTestContext.timeUnit = TEMPER_TIME_UNIT_MS;
			} else if ( TEMPERDEV__STRCMP( nextArg, "us" ) == 0 ) {
				g_temperTestContext.timeUnit = TEMPER_TIME_UNIT_US;
			} else if ( TEMPERDEV__STRCMP( nextArg, "ns" ) == 0 ) {
				g_temperTestContext.timeUnit = TEMPER_TIME_UNIT_NS;
			} else if ( TEMPERDEV__STRCMP( nextArg, "clocks" ) == 0 ) {
				g_temperTestContext.timeUnit = TEMPER_TIME_UNIT_CLOCKS;
			} else {
				TEMPERDEV__LOG_ERROR(
					"Invalid time unit \"%s\" specified.  Please select from one of the following:\n"
					"\t- seconds\n"
					"\t- ms\n"
					"\t- us\n"
					"\t- ns\n"
					"\t- clocks\n"
					"\n",
					nextArg
				);

				TemperShowUsageInternal();

				return false;
			}

			continue;
		}
	}

	// if partial filtering was enabled but the user did not then specify a suite or test filter then they need to know about incorrect usage
	if ( g_temperTestContext.partialFilter ) {
		if ( !g_temperTestContext.suiteFilter && !g_temperTestContext.testFilter ) {
			TEMPERDEV__LOG_ERROR(
				"Partial filtering (-p) was enabled but suite or test filtering (-s, -t) was not.\n"
				"You can only use partial filtering if you have either suite or test filtering enabled as well.\n"
			);

			TemperShowUsageInternal();

			return false;
		}
	}

	return true;
}

//----------------------------------------------------------

static const char* TemperGetTimeUnitStringInternal( const temperTimeUnit_t timeUnit ) {
	TEMPERDEV__ASSERT( ( timeUnit > TEMPER_TIME_UNIT_CLOCKS && timeUnit <= TEMPER_TIME_UNIT_SECONDS ) && "Time unit enum was invalid somehow!?" );

	switch ( timeUnit ) {
		case TEMPER_TIME_UNIT_CLOCKS:	return "clocks";
		case TEMPER_TIME_UNIT_NS:		return "nanoseconds";
		case TEMPER_TIME_UNIT_US:		return "microseconds";
		case TEMPER_TIME_UNIT_MS:		return "milliseconds";
		case TEMPER_TIME_UNIT_SECONDS:	return "seconds";
	}

	// never gets here
	return NULL;
}

//----------------------------------------------------------

#if defined( _WIN32 )
#define TEMPERDEV__THREAD_HANDLE	DWORD WINAPI
#elif defined( __APPLE__ ) || defined( __linux__ )	// defined( _WIN32 )
#define TEMPERDEV__THREAD_HANDLE	void*
#else	// defined( _WIN32 )
#error Uncrecognised platform.  It appears Temper does not support it.  If you think this is a bug, please submit an issue at https://github.com/dangmoody/Temper/issues
#endif	// defined( _WIN32 )

// its ok to write directly to the global test context because only one test thread runs at a time
// if multiple test threads were running asynchronously then probably want to atomic increment at the very end of the test thread
// we don't factor OnBefore and OnAfter calls into the time as they're just for setting up the testing enviornment
// OnBefore and OnAfter should still permit all errors and aborts be heard by the Temper system at large incase any setup or shutdown fails.
static TEMPERDEV__THREAD_HANDLE TemperThreadProcInternal( void* data ) {
	TEMPERDEV__ASSERT( data );

	temperTestInfo_t* information = (temperTestInfo_t*) data;
	TEMPERDEV__ASSERT( information );
	TEMPERDEV__ASSERT( information->TestFuncCallback );

	if ( information->OnBeforeTest ) {
		information->OnBeforeTest();
	}

	g_temperTestContext.currentTestStartTime = TEMPER_GET_TIMESTAMP( g_temperTestContext.timeUnit );
	information->TestFuncCallback();
	g_temperTestContext.currentTestEndTime = TEMPER_GET_TIMESTAMP( g_temperTestContext.timeUnit );

	information->testTimeTaken = g_temperTestContext.currentTestEndTime - g_temperTestContext.currentTestStartTime;

	if ( information->OnAfterTest ) {
		information->OnAfterTest();
	}

	return 0;
}

//----------------------------------------------------------

static void TemperRunTestThreadInternal( temperTestInfo_t* information ) {
	TEMPERDEV__ASSERT( information );

#if defined( _WIN32 )
	HANDLE testThread = CreateThread( NULL, 0, TemperThreadProcInternal, information, 0, NULL );
	TEMPERDEV__ASSERT( testThread );

	DWORD result = WaitForMultipleObjects( 1, &testThread, TRUE, UINT32_MAX );
	TEMPERDEV__ASSERT( result == WAIT_OBJECT_0 );
	TEMPERDEV__UNUSED( result );

	DWORD exitCode = (DWORD) -1;
	BOOL gotExitCode = GetExitCodeThread( testThread, &exitCode );
	TEMPERDEV__ASSERT( gotExitCode );
	TEMPERDEV__UNUSED( gotExitCode );

	CloseHandle( testThread );
	testThread = NULL;
#elif defined( __APPLE__ ) || ( __linux__ )	// defined( _WIN32 )
	int err = 0;

	pthread_t thread;
	pthread_attr_t threadAttribs;
	pthread_attr_init( &threadAttribs );
	if ( pthread_create( &thread, &threadAttribs, TemperThreadProcInternal, information ) != 0 ) {
		err = errno;
		TEMPERDEV__LOG_ERROR( "Failed to create test thread: %s.\n", strerror( err ) );
		return;
	}

	void* exitCode;
	if ( pthread_join( thread, &exitCode ) != 0 ) {
		err = errno;
		TEMPERDEV__LOG_ERROR( "Failed to wait for test thread to finish: %s.\n", strerror( err ) );
		return;
	}
#else	// defined( _WIN32 )
#error Uncrecognised platform.  It appears Temper does not support it.  If you think this is a bug, please submit an issue at https://github.com/dangmoody/Temper/issues
#endif	// defined( _WIN32 )
}

//----------------------------------------------------------

static void TemperPrintDividerInternal( const char* suiteName ) {
	TEMPERDEV__LOG( "----------------------------------------------------------\nSUITE: \"%s\"\n\n", suiteName );
}

//----------------------------------------------------------

static void TemperOnBeforeTestInternal( const temperTestInfo_t* information ) {
	TEMPERDEV__ASSERT( information );

	if ( g_temperTestContext.suiteFilterPrevious && information->suiteNameStr ) {
		if ( TEMPERDEV__STRCMP( g_temperTestContext.suiteFilterPrevious, information->suiteNameStr ) != 0 ) {
			TemperPrintDividerInternal( information->suiteNameStr );
			g_temperTestContext.suiteFilterPrevious = information->suiteNameStr;
		}
	} else if ( ( g_temperTestContext.suiteFilterPrevious && information->suiteNameStr == NULL ) ||
				( g_temperTestContext.suiteFilterPrevious == NULL && information->suiteNameStr ) ) {
		TemperPrintDividerInternal( information->suiteNameStr != NULL ? information->suiteNameStr : "No suite name given" );
		g_temperTestContext.suiteFilterPrevious = information->suiteNameStr;
	}

	if ( information->testNameStr ) {
		TEMPERDEV__LOG( "TEST: \"%s\"\n", information->testNameStr );
	}
}

//----------------------------------------------------------

static void TemperOnAfterTestInternal( const temperTestInfo_t* information ) {
	TEMPERDEV__ASSERT( information );

	if ( information->testingFlag == TEMPER_FLAG_SHOULD_RUN ) {
		const char* timeUnitStr = TemperGetTimeUnitStringInternal( g_temperTestContext.timeUnit );

		if ( g_temperTestContext.currentTestWasAborted ) {
			TemperSetTextColorInternal( TEMPERDEV__COLOR_RED );
			TEMPERDEV__LOG( "=== TEST ABORTED (%.3f %s) ===\n\n", g_temperTestContext.currentTestEndTime - g_temperTestContext.currentTestStartTime, timeUnitStr );
			TemperSetTextColorInternal( TEMPERDEV__COLOR_DEFAULT );
		} else if ( g_temperTestContext.currentTestErrorCount > 0 ) {
			TemperSetTextColorInternal( TEMPERDEV__COLOR_RED );
			TEMPERDEV__LOG( "TEST FAILED (%.3f %s)\n\n", g_temperTestContext.currentTestEndTime - g_temperTestContext.currentTestStartTime, timeUnitStr );
			TemperSetTextColorInternal( TEMPERDEV__COLOR_DEFAULT );
		} else {
			TemperSetTextColorInternal( TEMPERDEV__COLOR_GREEN );
			TEMPERDEV__LOG( "TEST SUCCEEDED (%.3f %s)\n\n", g_temperTestContext.currentTestEndTime - g_temperTestContext.currentTestStartTime, timeUnitStr );
			TemperSetTextColorInternal( TEMPERDEV__COLOR_DEFAULT );
		}
	} else {
		const char* skipReason = information->testingFlag == TEMPER_FLAG_DEPRECATED ? "DEPRECATED" : "SHOULD_SKIP";
		TemperSetTextColorInternal( TEMPERDEV__COLOR_YELLOW );
		TEMPERDEV__LOG( "TEST FLAGGED \"%s\"\n\n", skipReason );
		TemperSetTextColorInternal( TEMPERDEV__COLOR_DEFAULT );
	}
}

//----------------------------------------------------------

static void TemperAbortTestOnFailInternal( const bool abortOnFail ) {
	if ( abortOnFail ) {
		g_temperTestContext.currentTestEndTime = TEMPER_GET_TIMESTAMP( g_temperTestContext.timeUnit );
		g_temperTestContext.testsAborted += 1;
		g_temperTestContext.currentTestWasAborted = true;

		TEMPERDEV__EXIT_TEST_THREAD();
	}
}

//----------------------------------------------------------

void TemperTestTrueInternal( const bool condition, const char* conditionStr, const bool abortOnFail, const char* file, const uint32_t line, const char* fmt, ... ) {
	if ( !( condition ) ) {
		g_temperTestContext.currentTestErrorCount += 1;

		{
			TemperSetTextColorInternal( TEMPERDEV__COLOR_RED );
			TEMPERDEV__LOG( "FAILED: " );
			TemperSetTextColorInternal( TEMPERDEV__COLOR_YELLOW );
			TEMPERDEV__LOG( "%s at %s line %d.\n", conditionStr, file, line );
			if ( fmt ) {
				va_list args;
				va_start( args, fmt );
				TEMPERDEV__VPRINTF( fmt, args );
				va_end( args );
			}
			TemperSetTextColorInternal( TEMPERDEV__COLOR_DEFAULT );
		}

		TemperAbortTestOnFailInternal( abortOnFail );
	}
}

//----------------------------------------------------------

static void TemperOnAllTestsFinishedInternal( void ) {
	TEMPERDEV__LOG(
		"------------------------------------------------------------\n"
		"\n"
		"\n=== ALL TESTS FINISHED ===\n"
		"Total time taken: %.3f %s\n"
		"Total tests defined: %d\n"
		, g_temperTestContext.totalExecutionTime, TemperGetTimeUnitStringInternal( g_temperTestContext.timeUnit )
		, g_temperTestContext.testInfosCount
	);

	if ( g_temperTestContext.suiteFilter || g_temperTestContext.testFilter ) {
		TEMPERDEV__LOG( "\t- Total tests matching filters: %d\n\t- Suite filter: %s\n\t- Test filter: %s\n\t- Partial results %s\n",
				g_temperTestContext.totalTestsFoundWithFilters,
				g_temperTestContext.suiteFilter,
				g_temperTestContext.testFilter,
				g_temperTestContext.partialFilter ? "PERMITTED" : "DISCARDED" );
	}

	uint32_t totalFound = g_temperTestContext.totalTestsFoundWithFilters;
	TEMPERDEV__LOG(
		"Passed:   %d ( %d%% )\n"
		"Failed:   %d ( %d%% )\n"
		"Aborted:  %d ( %d%% )\n"
		"Skipped:  %d ( %d%% )\n",
		g_temperTestContext.testsPassed,  TemperGetPercentInternal( g_temperTestContext.testsPassed,  totalFound ),
		g_temperTestContext.testsFailed,  TemperGetPercentInternal( g_temperTestContext.testsFailed,  totalFound ),
		g_temperTestContext.testsAborted, TemperGetPercentInternal( g_temperTestContext.testsAborted, totalFound ),
		g_temperTestContext.testsSkipped, TemperGetPercentInternal( g_temperTestContext.testsSkipped, totalFound )
	);
}

//----------------------------------------------------------

// MY: I'd like to eventually add more security around this,
// such as ensuring it's only ever called/used once and thowing
// an error if it isn't. Maybe also (SOMEHOW) ensuring no test
// ever has a higher count.
void TemperSetupInternal( void ) {
#ifdef _WIN32
	LARGE_INTEGER frequency;
	QueryPerformanceFrequency( &frequency );

	g_temperTestContext.timestampFrequency = frequency.QuadPart;
#endif

	g_temperTestContext.currentTestStartTime = 0.0;
	g_temperTestContext.currentTestEndTime = 0.0;
	g_temperTestContext.totalExecutionTime = 0.0;
	g_temperTestContext.testsPassed = 0;
	g_temperTestContext.testsFailed = 0;
	g_temperTestContext.testsAborted = 0;
	g_temperTestContext.testsSkipped = 0;
	g_temperTestContext.totalTestsFoundWithFilters = 0;
	g_temperTestContext.totalTestsExecuted = 0;
	g_temperTestContext.currentTestErrorCount = 0;
	g_temperTestContext.currentTestWasAborted = false;
	g_temperTestContext.partialFilter = false;
	g_temperTestContext.timeUnit = TEMPER_TIME_UNIT_US;
	g_temperTestContext.suiteFilterPrevious = NULL;
	g_temperTestContext.suiteFilter = NULL;
	g_temperTestContext.testFilter = NULL;
}

//----------------------------------------------------------

static bool TemperIsSuiteFilteredInternal( const char* suiteName ) {
	if ( !g_temperTestContext.suiteFilter ) {
		return true;
	}

	if ( !suiteName ) {
		return false;
	}

	if ( g_temperTestContext.partialFilter ) {
		return TEMPERDEV__STRSTR( suiteName, g_temperTestContext.suiteFilter ) != NULL;
	} else {
		return TEMPERDEV__STRCMP( suiteName, g_temperTestContext.suiteFilter ) == 0;
	}
}

//----------------------------------------------------------

static bool TemperIsTestFilteredInternal( const char* testName ) {
	if ( !g_temperTestContext.testFilter ) {
		return true;
	}

	if ( !testName ) {
		return false;
	}

	if ( g_temperTestContext.partialFilter ) {
		return TEMPERDEV__STRSTR( testName, g_temperTestContext.testFilter ) != NULL;
	} else {
		return TEMPERDEV__STRCMP( testName, g_temperTestContext.testFilter ) == 0;
	}
}

//----------------------------------------------------------

static int TemperCalculateExitCode( void ) {
	return g_temperTestContext.testsFailed == 0 && g_temperTestContext.testsAborted == 0 ? TEMPERDEV__EXIT_SUCCESS : TEMPERDEV__EXIT_FAILURE;
}

//----------------------------------------------------------

int TemperExecuteAllTestsInternal( void ) {
	double start = TEMPER_GET_TIMESTAMP( g_temperTestContext.timeUnit );

	for ( uint64_t i = 0; i < g_temperTestContext.testInfosCount; i++ ) {
		temperTestInfo_t* testInfo = &g_temperTestContext.testInfos[i];

		// check if whether the suite/test passed the filter first before checking if the run flag was set
		// otherwise the test could be marked as run/skip but still pass the filter and it would never show in the output
		// TODO(DM): profile doing a loop like this with branching vs. adding everything that passes the filter first to a list of things to run
		// we care only about raw execution time in that test and whether or not the initial pass was faster than just running the loop with branching
		if ( TemperIsSuiteFilteredInternal( testInfo->suiteNameStr ) ) {
			if ( TemperIsTestFilteredInternal( testInfo->testNameStr ) ) {
				g_temperTestContext.totalTestsFoundWithFilters += 1;

				TEMPERDEV__ON_BEFORE_TEST( testInfo );

				if ( testInfo->testingFlag == TEMPER_FLAG_SHOULD_RUN ) {
					g_temperTestContext.currentTestErrorCount = 0;
					g_temperTestContext.currentTestWasAborted = false;

					TEMPERDEV__RUN_TEST_THREAD( testInfo );

					g_temperTestContext.totalTestsExecuted += 1;

					if ( g_temperTestContext.currentTestErrorCount > 0 ) {
						g_temperTestContext.testsFailed += 1;
					} else {
						g_temperTestContext.testsPassed += 1;
					}
				} else {
					g_temperTestContext.testsSkipped += 1;
				}

				TEMPERDEV__ON_AFTER_TEST( testInfo );
			}
		}
	}

	double end = TEMPER_GET_TIMESTAMP( g_temperTestContext.timeUnit );
	g_temperTestContext.totalExecutionTime = end - start;

	TEMPERDEV__ON_ALL_TESTS_FINISHED();

	return TemperCalculateExitCode();
}

//----------------------------------------------------------

int TemperExecuteAllTestsWithArgumentsInternal( int argc, char** argv ) {
	TemperSetupInternal();

	if ( !TemperHandleCommandLineArgumentsInternal( argc, argv ) ) {
		return TEMPERDEV__EXIT_FAILURE;
	}

	return TemperExecuteAllTestsInternal();
}

//----------------------------------------------------------

#endif // TEMPER_IMPLEMENTATION

#if defined( __linux__ ) || defined( __APPLE__ )
#pragma pop_macro( "_POSIX_C_SOURCE" )
#endif

#if defined( __clang__ )
#pragma clang diagnostic pop
#elif defined( __GNUC__ )
#pragma GCC diagnostic pop
#elif defined( _MSC_VER )
#pragma warning( pop )
#endif // defined( __GNUC__ ) || defined( __clang__ )

#ifdef __cplusplus
}
#endif

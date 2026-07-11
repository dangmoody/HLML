/*
===========================================================================

HLML Generator.
Copyright (c) Dan Moody 2018 - Present.

This file is part of the HLML Generator.

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

#ifdef _WIN32

#include "../timer.h"

static s64 Frequency( void ) {
	static LARGE_INTEGER frequency = { 0 };
	QueryPerformanceFrequency( &frequency );
	return frequency.QuadPart;
}

s64 Time_Now( void ) {
	LARGE_INTEGER now = { 0 };
	QueryPerformanceCounter( &now );
	return now.QuadPart;
}

float64 Time_NowSeconds( void ) {
	return (float64) Time_Now() / (float64) Frequency();
}

float64 Time_NowMS( void ) {
	return (float64) ( Time_Now() * 1000 ) / (float64) Frequency();
}

float64 Time_NowUS( void ) {
	return (float64) ( Time_Now() * 1000000 ) / (float64) Frequency();
}

float64 Time_NowNS( void ) {
	return (float64) ( Time_Now() * 1000000000 ) / (float64) Frequency();
}

#endif // _WIN32
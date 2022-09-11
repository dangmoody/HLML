@echo off

setlocal EnableDelayedExpansion

REM must be either:
REM 	clang
REM 	gcc
REM 	msvc
set arg_compiler=%1

set compiler_c=""
set compiler_cpp=""

if /I [!arg_compiler!]==[clang] (
	set compiler_c=clang
	set compiler_cpp=clang++
)

if /I [!arg_compiler!]==[gcc] (
	set compiler_c=gcc
	set compiler_cpp=g++
)

if /I [!arg_compiler!]==[msvc] (
	set compiler_c=msvc
	set compiler_cpp=msvc
)

REM verify args
if /I [!arg_compiler!]==[] (
	echo ERROR: Compiler not specified.  This must be set!
	goto :BuildFailure
)

if /I [!compiler_c!]==[] (
	echo ERROR: C compiler not set.  Arg!?
	goto :BuildFailure
)

if /I [!compiler_cpp!]==[] (
	echo ERROR: C++ compiler not set.  Arg!?
	goto :BuildFailure
)

echo Compiling for !compiler_c! (C) and !compiler_cpp! (C++)

pushd %~dp0
pushd ..

REM cleanup old files
if exist .\\bin\\win64\\debug\\tests\\!compiler_c!\\hlml_tests_c.exe (
	del .\\bin\\win64\\debug\\tests\\!compiler_c!\\hlml_tests_c.exe
)

if exist .\\bin\\win64\\debug\\tests\\!compiler_cpp!\\hlml_tests_cpp.exe (
	del .\\bin\\win64\\debug\\tests\\!compiler_cpp!\\hlml_tests_cpp.exe
)


REM generate API files
echo.
echo Running Generator...
call .\\scripts\\build_generator.bat --config debug
if %errorlevel% neq 0 goto :BuildFailure

.\\bin\\win64\\debug\\generator.exe
if %errorlevel% neq 0 goto :RuntimeFailure
echo.


REM C99 tests
echo Compiling C99 tests...
call .\\scripts\\build_!compiler_c!.bat --output hlml_tests_c --config debug --source code\\generated_files\\tests\\c\\test_main.c
if %errorlevel% neq 0 goto :BuildFailure
echo.
echo Running C99 tests...
.\\bin\\win64\\debug\\tests\\!compiler_c!\\hlml_tests_c.exe %*
if %errorlevel% neq 0 goto :RuntimeFailure
echo.


REM C++ tests
echo Compiling C++ tests...
call .\\scripts\\build_!compiler_cpp!.bat --output hlml_tests_cpp --config debug --source code\\generated_files\\tests\\cpp\\test_main.cpp
if %errorlevel% neq 0 goto :BuildFailure
echo.
echo Running C++ tests...
.\\bin\\win64\\debug\\tests\\!compiler_cpp!\\hlml_tests_cpp.exe %*
if %errorlevel% neq 0 goto :RuntimeFailure
echo.

popd
popd

goto :ExitSuccess


:ExitSuccess
echo.
echo No errors were detected for compiler !arg_compiler!.
popd
goto :EOF

:BuildFailure
echo.
echo ERROR: Compile failed.  Stopping...
popd
exit /b %errorlevel%

:RuntimeFailure
echo.
echo ERROR: .EXE returned failure exit code.  Stopping...
popd
exit /b %errorlevel%
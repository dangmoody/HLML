@echo off

pushd %~dp0
pushd ..

REM cleanup old files
if exist .\\bin\\win64\\debug\\tests\\clang\\hlml_tests_c.exe (
	del .\\bin\\win64\\debug\\tests\\clang\\hlml_tests_c.exe
)

if exist .\\bin\\win64\\debug\\tests\\clang\\hlml_tests_cpp.exe (
	del .\\bin\\win64\\debug\\tests\\clang\\hlml_tests_cpp.exe
)


REM generate API files
echo.
echo Running Generator...
call .\\scripts\\build_generator.bat --config debug
if %errorlevel% neq 0 goto :BuildFailure

.\\bin\\win64\\debug\\generator.exe
if %errorlevel% neq 0 goto :BuildFailure
echo.


REM C99 tests
echo Compiling C99 tests...
call .\\scripts\\build_clang.bat --output hlml_tests_c.exe --config debug --source code\\generated_files\\tests\\c\\test_main.c
if %errorlevel% neq 0 goto :BuildFailure
echo.
echo Running C99 tests...
.\\bin\\win64\\debug\\tests\\clang\\hlml_tests_c.exe %*
if %errorlevel% neq 0 goto :BuildFailure
echo.


REM C++ tests
echo Compiling C++ tests...
call .\\scripts\\build_clang++.bat --output hlml_tests_cpp.exe --config debug --source code\\generated_files\\tests\\cpp\\test_main.cpp
if %errorlevel% neq 0 goto :BuildFailure
echo.
echo Running C++ tests...
.\\bin\\win64\\debug\\tests\\clang++\\hlml_tests_cpp.exe %*
if %errorlevel% neq 0 goto :BuildFailure
echo.

popd
popd

goto :ExitSuccess


:ExitSuccess
echo.
echo No errors were detected on any of the compilers.  Everything looks fine.
popd
goto :EOF


:BuildFailure
echo.
echo ERROR: Failed to build.  Stopping...
popd
exit /b %errorlevel%
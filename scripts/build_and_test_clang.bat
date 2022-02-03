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
.\\bin\\win64\\debug\\generator.exe
echo.


REM C99 tests
echo Compiling C99 tests...
call .\\scripts\\build_clang.bat --output hlml_tests_c.exe --config debug --source code\\generated_files\\tests\\c\\test_main.c
echo.
echo Running C99 tests...
.\\bin\\win64\\debug\\tests\\clang\\hlml_tests_c.exe %*
echo.


REM C++ tests
echo Compiling C++ tests...
call .\\scripts\\build_clang++.bat --output hlml_tests_cpp.exe --config debug --source code\\generated_files\\tests\\cpp\\test_main.cpp
echo.
echo Running C++ tests...
.\\bin\\win64\\debug\\tests\\clang++\\hlml_tests_cpp.exe %*
echo.

popd
popd
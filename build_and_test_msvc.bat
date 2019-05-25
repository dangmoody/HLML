@echo off

REM can be "debug" or "release"
set config=%1

REM path to vcvars64.bat, MUST include file name
set vcvars64_path=%3

call %vcvars64_path%

echo ------- Building generator -------
set source_files=code\generator\*.cpp
call build_msvc.bat %config% hlml-gen %source_files%
echo ------- Done -------
echo.

echo ------- Running generator -------
build\msvc\%config%\hlml-gen.exe
echo ------- Done -------
echo.

echo ------- Building tests -------
set source_files=code\tests\*.cpp
call build_msvc.bat %config% hlml-gen-tests %source_files%
echo ------- Done -------
echo.

echo ------- Running tests -------
build\msvc\%config%\hlml-gen-tests.exe -c
echo ------- Done -------
echo.

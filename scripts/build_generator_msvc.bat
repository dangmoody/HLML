@echo off

pushd %~dp0

set config=%1

set source_files=code\generator\*.cpp

echo ------- Building generator -------
call build_msvc.bat %config% hlml-gen %source_files%
echo ------- Done -------
echo.

popd
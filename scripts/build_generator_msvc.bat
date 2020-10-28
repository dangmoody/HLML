@echo off

pushd %~dp0

set config=%1

echo ------- Building generator -------
call build_msvc.bat %config% hlml-gen code\generator\*.cpp
echo ------- Done -------
echo.

popd
@echo off

setlocal EnableDelayedExpansion

pushd %~dp0

call build_and_test_clang.bat clang
if %errorlevel% neq 0 goto :ExitFailure

call build_and_test_clang.bat gcc
if %errorlevel% neq 0 goto :ExitFailure

call build_and_test_clang.bat msvc
if %errorlevel% neq 0 goto :ExitFailure

goto :ExitSuccess


:ExitSuccess
echo.
echo No errors were detected on any of the compilers.  Everything looks fine.
popd
goto :EOF

:ExitFailure
echo.
echo ERROR: Last operation was not successful.  Stopping...
popd
exit /b %errorlevel%
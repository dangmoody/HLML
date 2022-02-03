@echo off

setlocal EnableDelayedExpansion

pushd %~dp0

call build_and_test_clang.bat
if %errorlevel% neq 0 goto :ExitFailure

call build_and_test_gcc.bat
if %errorlevel% neq 0 goto :ExitFailure

call build_and_test_msvc.bat
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
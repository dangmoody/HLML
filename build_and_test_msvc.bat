@echo off

set config=%1

set msvc_path="C:\\Program Files (x86)\\Microsoft Visual Studio\\2017\\Community\\VC\\Tools\\MSVC\\14.16.27023\\bin\\Hostx64\\x64\\cl.exe"

rem set vcvars64_path="C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Auxiliary\Build\vcvars64.bat"
REM call %vcvars64_path%

echo ------- Building generator -------
set source_files=code\\generator\\*.cpp
call build_msvc.bat %msvc_path% %config% hlml-gen %source_files%
echo ------- Done -------
echo.

echo ------- Running generator -------
build\\msvc\\%config%\\hlml-gen.exe
echo ------- Done -------
echo.

echo ------- Building tests -------
set source_files=code\\tests\\*.cpp
call build_msvc.bat %msvc_path% %config% hlml-gen-tests %source_files%
echo ------- Done -------
echo.

echo ------- Running tests -------
build\\msvc\\%config%\\hlml-gen-tests.exe -c
echo ------- Done -------
echo.

@echo off

REM can be either "debug" or "release"
set config=%1
if [%config%]==[] (
	echo ERROR: Config argument was not specified.
	goto :ShowUsage
)

REM name of the exe to make, must NOT include ".exe"
set output_file=%2
if [%output_file%]==[] (
	echo ERROR: Output file was not specified.
	goto :ShowUsage
)

pushd %~dp0
pushd ..

REM path to source of files to build, must NOT include ".cpp"
set source_files_path=%3
if [%source_files_path%]==[] (
	echo ERROR: Source files path was not specified.
	goto :ShowUsage
)

set ignore_warnings=/wd4805 /wd4204 /wd4996
set options_compiler=/W4 /WX %ignore_warnings% /MT /Od /MP /Gm- /EHsc /U "_UNICODE" /Fo"bin\\msvc\\%config%\\intermediate\\%output_file%\\" /Zi /Fd"bin\\msvc\\%config%\\intermediate\\%output_file%\\%output_file%.pdb"
set options_linker=/OUT:bin\\msvc\\%config%\\%output_file%.exe /NOLOGO /opt:ref
set libs=User32.lib gdi32.lib winmm.lib

set additional_includes=/I"code/3rdparty/include/"

REM if the output folder doesn't exist, create it
IF NOT EXIST "bin\\msvc\\%config%\\" (
	mkdir "bin\\msvc\\%config%\\"
)

REM if the intermediate output folder doesn't exist, create it
IF NOT EXIST "bin\\msvc\\%config%\\intermediate\\%output_file%" (
	mkdir "bin\\msvc\\%config%\\intermediate\\%output_file%"
)

cl.exe %source_files_path% %additional_includes% %options_compiler% /link %options_linker% %libs%

popd
popd

goto :EOF


:ShowUsage
echo Usage:
echo build_msvc.bat ^<config^> ^<output_file^> ^<source_files_path^>
echo.
echo Args:
echo     ^<config^>
echo         Must be either "debug" or "release".
echo.
echo     ^<output_file^>
echo         The name of the .exe to generate.  Must NOT include ".exe".
echo.
echo     ^<source_files_path^>
echo         Path to the source files to build.  Must NOT include ".cpp".
goto :EOF

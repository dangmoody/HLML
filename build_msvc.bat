@echo off

REM can be either "debug" or "release"
set config=%1

REM name of the exe to make, must NOT include ".exe"
set output_file=%2

REM path to source of files to build, must NOT include ".cpp"
set source_files_path=%3

set options_compiler=/W4 /WX /MT /Od /MP /Gm- /EHsc /U "_UNICODE" /Fo"build\\msvc\\%config%\\intermediate\%output_file%\\"
set options_linker=/OUT:build\\msvc\\%config%\\%output_file%.exe /NOLOGO /opt:ref
set libs=User32.lib gdi32.lib winmm.lib

set additional_includes=/I"code/3rdparty/include/"

REM if the output folder doesn't exist, create it
IF NOT EXIST "build\msvc\%config%\" (
	mkdir "build\msvc\%config%\"
)

REM if the intermediate output folder doesn't exist, create it
IF NOT EXIST "build\msvc\%config%\intermediate\%output_file%" (
	mkdir "build\msvc\%config%\intermediate\%output_file%"
)

cl.exe %source_files_path% %additional_includes% %options_compiler% /link %options_linker% %libs%

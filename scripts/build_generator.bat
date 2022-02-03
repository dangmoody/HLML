@echo off

setlocal EnableDelayedExpansion

set config=""

set foundSourceFiles=0

REM store this now because were about to fuck around with all the cmd line args
set cwd=%~dp0

:ParseArgs
if "%1" NEQ "" (
	if /I [%1]==[-h] (
		goto :ShowUsage
	)

	if /I [%1]==[--help] (
		goto :ShowUsage
	)

	if /I [%1]==[--config] (
		set config=%2
	)

	shift

	goto :ParseArgs
)

:VerifyArgs
if /I [!config!]==[""] (
	echo ERROR: --config argument not specified.
	echo.
	goto :ShowUsage
)

set warning_levels=-Werror -Wall -Wextra -Weverything -Wpedantic

REM set ignore_warnings=-Wno-old-style-cast -Wno-zero-as-null-pointer-constant -Wno-c++98-compat -Wno-format-nonliteral -Wno-double-promotion -Wno-c++98-compat-pedantic -Wno-newline-eof -Wno-cast-align -Wno-gnu-anonymous-struct -Wno-nested-anon-types
set ignore_warnings=-Wno-newline-eof -Wno-microsoft-anon-tag -Wno-double-promotion -Wno-bad-function-cast

set includes=-Icode\\3rdparty\\include\\

set symbols=""
set defines=-D_CRT_SECURE_NO_WARNINGS -D_DEBUG
set optimisation=""

if /I [!config!]==[debug] (
	set symbols=-g
	set defines=!defines! -D_DEBUG
)

if /I [!config!]==[release] (
	set defines=!defines! -DNDEBUG
	set optimisation=-O3
)

set source_files=code\\generator\\main.c code\\generator\\generator.win64.c code\\generator\\stb_impl.c

pushd %cwd%
pushd ..

set build_dir=bin\\win64\\%config%

if not exist %build_dir% (
	mkdir %build_dir%
)

if exist %build_dir%\\generator.exe (
	del %build_dir%\\generator.exe
)

REM clang -o %build_dir%\\generator.exe -std=c++14 !symbols! !optimisation! %source_files% %warning_levels% %ignore_warnings% %includes% %defines%
clang -o %build_dir%\\generator.exe -std=c99 !symbols! !optimisation! %source_files% %warning_levels% %ignore_warnings% %includes% %defines%

popd
popd

goto :EOF

:ShowUsage
echo USAGE:
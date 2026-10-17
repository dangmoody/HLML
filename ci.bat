:: this file is only to recreate what would otherwise be happening on TeamCity
:: when that gets setup this file will get removed

@echo off

pushd %~dp0

:: generator
build.exe --config=generator

.\bin\debug\hlml-generator.exe

:: clang C
build.exe --config=tests-c
.\bin\debug\hlml-tests-clang-c.exe

:: clang CPP
build.exe --config=tests-cpp
.\bin\debug\hlml-tests-clang-cpp.exe

:: GCC C
build.exe --gcc --config=tests-c
.\bin\debug\hlml-tests-gcc-c.exe

:: GCC CPP
build.exe --gcc --config=tests-cpp
.\bin\debug\hlml-tests-gcc-cpp.exe

:: MSVC C
build.exe --msvc --config=tests-c
.\bin\debug\hlml-tests-msvc-c.exe

:: MSVC CPP
build.exe --msvc --config=tests-cpp
.\bin\debug\hlml-tests-msvc-cpp.exe

popd
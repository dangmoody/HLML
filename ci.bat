:: this file is only to recreate what would otherwise be happening on TeamCity
:: when that gets setup this file will get removed

@echo off

pushd %~dp0

:: generator
builder build.cpp --config=generator

.\bin\debug\hlml-generator.exe

:: clang C
builder build.cpp --config=tests --c
.\bin\debug\hlml-tests-clang-c.exe

:: clang CPP
builder build.cpp --config=tests --cpp
.\bin\debug\hlml-tests-clang-cpp.exe

:: GCC C
builder build.cpp --gcc --config=tests --c
.\bin\debug\hlml-tests-gcc-c.exe

:: GCC CPP
builder build.cpp --gcc --config=tests --cpp
.\bin\debug\hlml-tests-gcc-cpp.exe

:: MSVC C
builder build.cpp --msvc --config=tests --c
.\bin\debug\hlml-tests-msvc-c.exe

:: MSVC CPP
builder build.cpp --msvc --config=tests --cpp
.\bin\debug\hlml-tests-msvc-cpp.exe

popd
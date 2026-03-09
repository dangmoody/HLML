:: this file is only to recreate what would otherwise be happening on TeamCity
:: when that gets setup this file will get removed

@echo off

pushd %~dp0

:: generator
builder build_generator.cpp --config=generator-debug

.\bin\debug\generator.exe

:: clang C
builder build_tests_clang.cpp --config=tests-c-debug
.\bin\debug\hlml-tests-clang-c.exe

:: clang CPP
builder build_tests_clang.cpp --config=tests-cpp-debug
.\bin\debug\hlml-tests-clang-cpp.exe

:: GCC C
builder build_tests_gcc.cpp --config=tests-c-debug
.\bin\debug\hlml-tests-gcc-c.exe

:: GCC CPP
builder build_tests_gcc.cpp --config=tests-cpp-debug
.\bin\debug\hlml-tests-gcc-cpp.exe

:: MSVC C
builder build_tests_msvc.cpp --config=tests-c-debug
.\bin\debug\hlml-tests-msvc-c.exe

:: MSVC CPP
builder build_tests_msvc.cpp --config=tests-cpp-debug
.\bin\debug\hlml-tests-msvc-cpp.exe

popd
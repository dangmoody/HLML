# Intended to be called from build_tests.mak!

include include_clang_settings.mak

compiler_c = gcc
compiler_cpp = g++

build_dir_c=..\\bin\\$(platform)\\$(config)\\tests\\$(compiler_c)
build_dir_cpp=..\\bin\\$(platform)\\$(config)\\tests\\$(compiler_cpp)

additional_flags_cpp = -Wa,-mbig-obj
# Intended to be called from build_tests.mak!

symbols =
defines = -D_CRT_SECURE_NO_WARNINGS
optimisation =

ifeq ($(config), debug)
symbols = -g
defines += -D_DEBUG
else ifeq ($(config), release)
optimisation = -O3
defines += -DNDEBUG
endif

warning_levels = -Werror -Wall -Wextra -Weverything -Wpedantic
ignore_warnings = -Wno-newline-eof -Wno-missing-braces -Wno-double-promotion -Wno-declaration-after-statement -Wno-old-style-cast -Wno-c++98-compat
includes = -I..\\code\\3rdparty\\include\\

compiler_c = clang
compiler_cpp = clang++

build_dir_c=..\\bin\\win64\\$(config)\\tests\\$(compiler_c)
build_dir_cpp=..\\bin\\win64\\$(config)\\tests\\$(compiler_cpp)

build_tests_c:
ifeq ("$(wildcard $(build_dir_c))", "")
	mkdir $(build_dir_c)
endif
	clang -std=c99 -o $(build_dir_c)\\$(hlml_tests_c_filename).exe $(symbols) $(optimisation) $(defines) $(warning_levels) $(ignore_warnings) $(hlml_tests_c_source) $(includes)
	
build_tests_cpp:
ifeq ("$(wildcard $(build_dir_cpp))", "")
	mkdir $(build_dir_cpp)
endif
	clang++ -std=c++11 -o $(build_dir_cpp)\\$(hlml_tests_cpp_filename).exe $(symbols) $(optimisation) $(defines) $(warning_levels) $(ignore_warnings) $(hlml_tests_cpp_source) $(includes)
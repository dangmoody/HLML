# Intended to be called from build_tests.mak!

symbols =
defines = -D_CRT_SECURE_NO_WARNINGS
optimisation =

ifeq ($(config), debug)
symbols = /Zi
defines += -D_DEBUG
else ifeq ($(config), release)
optimisation = /O3
defines += -DNDEBUG
endif

warning_levels = /W4
ignore_warnings = 
includes = /I"..\\code\\3rdparty\\include\\"

compiler_c = msvc
compiler_cpp = msvc

build_dir_c=..\\bin\\win64\\$(config)\\tests\\$(compiler_c)
build_dir_cpp=..\\bin\\win64\\$(config)\\tests\\$(compiler_cpp)

vs_install_dir = C:\\Program\ Files\\Microsoft\ Visual\ Studio
vs_version = 
vs_edition =
vs_vcvars_path =

find_vs_vcvars_path:
ifneq ("$(wildcard C:\\Program\ Files\\Microsoft\ Visual\ Studio\\.)", "")

# Let's determine what version of VS we have
ifneq ("$(wildcard C:\\Program\ Files\\Microsoft\ Visual\ Studio\\2019\\.)", "")
vs_version = 2019
else ifneq ("$(wildcard C:\\Program\ Files\\Microsoft\ Visual\ Studio\\2022\\.)", "")
vs_version = 2022
else
	$(error Cannot find a supported version of Visual Studio in the Visual Studio Install directory)
endif

# Let's determine what edition of VS we have
ifneq ("$(wildcard C:\\Program\ Files\\Microsoft\ Visual\ Studio\\$(vs_version)\\Community\\.)", "")
vs_edition = Community
else ifneq ("$(wildcard C:\\Program\ Files\\Microsoft\ Visual\ Studio\\$(vs_version)\\Professional\\.)", "")
vs_edition = Professional
else ifneq ("$(wildcard C:\\Program\ Files\\Microsoft\ Visual\ Studio\\$(vs_version)\\Enterprise\\.)", "")
vs_edition = Enterprise
else
	$(error Cannot find a supported edition of Visual Studio in the Visual Studio $(vs_version) Install directory)
endif

# We have everything, double check we exist before assigning
vs_vcvars_path = C:\\Program Files\\Microsoft Visual Studio\\$(vs_version)\\$(vs_edition)\\VC\\Auxiliary\\Build\\vcvars64.bat
else
	$(error Cannot find the main Visual Studio Install directory)
endif

make_build_dir:
ifeq ("$(wildcard $(build_dir_cpp))", "")
	mkdir $(build_dir_cpp)
endif

build_tests_c: find_vs_vcvars_path
	"$(vs_vcvars_path)" && cl /Fe:$(build_dir_c)\\$(hlml_tests_c_filename).exe /Fd:$(build_dir_c)\\$(hlml_tests_c_filename).pdb /Fo:$(build_dir_c)\\$(hlml_tests_c_filename).obj $(symbols) $(optimisation) $(defines) $(includes) $(warning_levels) $(ignore_warnings) $(hlml_tests_c_source)
	
build_tests_cpp: find_vs_vcvars_path
	"$(vs_vcvars_path)" && cl /Fe:$(build_dir_cpp)\\$(hlml_tests_cpp_filename).exe /Fd:$(build_dir_cpp)\\$(hlml_tests_cpp_filename).pdb /Fo:$(build_dir_cpp)\\$(hlml_tests_cpp_filename).obj $(symbols) $(optimisation) $(defines) $(includes) $(warning_levels) $(ignore_warnings) $(hlml_tests_cpp_source)
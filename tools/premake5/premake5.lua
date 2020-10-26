code_root = "..\\..\\code\\"
bin_root = "..\\..\\build\\"
scripts_root = "..\\..\\scripts\\"
vs_project_folder = "..\\..\\vs2019\\"

workspace( "hlml-gen" )
	location( vs_project_folder )

	platforms { "win64-msvc", "win64-clang", "win64-gcc" }
	configurations { "debug", "release" }

	startproject( "hlml-gen" )

	architecture( "x64" )

project( "hlml-gen" )
	location( vs_project_folder )

	files {
		code_root .. "generator\\**.cpp",
		code_root .. "generator\\**.h",
	}

	kind( "MakeFile" )

	cleancommands (
		scripts_root .. "clean_generator.bat"
	)

	debugdir( "$(SolutionDir)..\\" )

	filter "platforms:win64-msvc"
		-- required because VS will create these folders if they don't exist
		targetdir( bin_root .. "msvc\\%{cfg.buildcfg}" )
		objdir( bin_root .. "msvc\\%{cfg.buildcfg}\\intermediate\\hlml-gen" )

		debugcommand( bin_root .. "msvc\\%{cfg.buildcfg}\\hlml-gen.exe" )

		buildcommands (
			"..\\scripts\\build_generator_msvc.bat %{cfg.buildcfg}"
		)

		rebuildcommands (
			"..\\scripts\\build_generator_msvc.bat %{cfg.buildcfg}"
		)
	filter {}

project( "hlml-tests-c" )
	location( vs_project_folder )

	files {
		code_root .. "tests\\c\\*.c",
		code_root .. "tests\\c\\*.h",
	}

	kind( "Makefile" )

	cleancommands (
		scripts_root .. "clean_tests.bat"
	)

	filter "platforms:win64-msvc"
		-- required because VS will create these folders if they don't exist
		targetdir( bin_root .. "msvc\\%{cfg.buildcfg}" )
		objdir( bin_root .. "msvc\\%{cfg.buildcfg}\\intermediate\\hlml-gen-tests-c" )

		debugcommand( bin_root .. "msvc\\%{cfg.buildcfg}\\hlml-gen-tests-c.exe" )

		buildcommands (
			"..\\scripts\\build_tests_msvc.bat %{cfg.buildcfg} code\\tests\\c\\main.c"
		)

		rebuildcommands (
			"..\\scripts\\build_tests_msvc.bat %{cfg.buildcfg} code\\tests\\c\\main.c"
		)
	filter {}

--project( "hlml-test-cpp" )
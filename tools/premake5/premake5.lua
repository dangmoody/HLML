folder_code = "code/"

folder_bin = "$(SolutionDir)../bin/"
folder_scripts = "$(SolutionDir)../scripts/"

vs_project_folder = "../../" .. _ACTION .. "/"	-- path must be relative to premake5.lua file

workspace( "hlml-gen" )
	location( vs_project_folder )

	platforms { "win64-msvc" }
	configurations { "debug", "release" }

	startproject( "hlml-gen" )

	architecture( "x64" )

project( "hlml-gen" )
	location( vs_project_folder )

	files {
		"../../" .. folder_code .. "generator/**.cpp",
		"../../" .. folder_code .. "generator/**.h",
	}

	kind( "MakeFile" )

	cleancommands (
		folder_scripts .. "clean_generator.bat"
	)

	debugdir( "$(SolutionDir)../" )

	-- required because VS will create these folders if they don't exist
	targetdir( folder_bin .. "msvc/%{cfg.buildcfg}" )
	objdir( folder_bin .. "msvc/%{cfg.buildcfg}/intermediate/hlml-gen" )

	debugcommand( "$(OutDir)hlml-gen.exe" )

	buildcommands (
		folder_scripts .. "build_generator_msvc.bat %{cfg.buildcfg}"
	)

	rebuildcommands (
		folder_scripts .. "build_generator_msvc.bat %{cfg.buildcfg}"
	)

project( "hlml-tests-c" )
	location( vs_project_folder )

	files {
		"../../" .. folder_code .. "tests/c/*.c",
		"../../" .. folder_code .. "tests/c/*.h",
	}

	kind( "Makefile" )

	cleancommands (
		folder_scripts .. "clean_tests.bat"
	)

	-- required because VS will create these folders if they don't exist
	targetdir( folder_bin .. "msvc/%{cfg.buildcfg}" )
	objdir( folder_bin .. "msvc/%{cfg.buildcfg}/intermediate/hlml-gen-tests-c" )

	debugcommand( "$(OutDir)hlml-gen-tests-c.exe" )

	buildcommands (
		folder_scripts .. "build_msvc.bat %{cfg.buildcfg} hlml-gen-tests-c code/tests/c/main.c"
	)

	rebuildcommands (
		folder_scripts .. "build_msvc.bat %{cfg.buildcfg} hlml-gen-tests-c code/tests/c/main.c"
	)

project( "hlml-test-cpp" )
	location( vs_project_folder )

	files {
		"../../" .. folder_code .. "tests/cpp/*.cpp",
		"../../" .. folder_code .. "tests/cpp/*.h",
	}

	kind( "Makefile" )

	cleancommands (
		folder_scripts .. "clean_tests.bat"
	)

	-- required because VS will create these folders if they don't exist
	targetdir( folder_bin .. "msvc/%{cfg.buildcfg}" )
	objdir( folder_bin .. "msvc/%{cfg.buildcfg}/intermediate/hlml-gen-tests-cpp" )

	debugcommand( "$(OutDir)hlml-gen-tests-cpp.exe" )

	buildcommands (
		folder_scripts .. "build_msvc.bat %{cfg.buildcfg} hlml-gen-tests-cpp code/tests/cpp/main.cpp"
	)

	rebuildcommands (
		folder_scripts .. "build_msvc.bat %{cfg.buildcfg} hlml-gen-tests-cpp code/tests/cpp/main.cpp"
	)
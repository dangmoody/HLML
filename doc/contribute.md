# Contributing Code To HLML

The main things you need to know in general are:
* Please make an issue on the GitHub repo before submitting a PR.
* We build for Clang, GCC, and MSVC so make sure you have all of those installed.
* Performance and usability are the two primary goals of the API.  If at any time those two goals are in confliction with each other then use common sense.


Building The Generator
======================

Windows
-------
1. If you want to use Visual Studio (2019 only):
	* Run `./scripts/generate_vs2019.bat` to get your solution and build.
	* If at any time you want to delete your Visual Studio project files run `./scripts/delete_vs_project_files.bat`.
2. If you're not using Visual Studio:
	* To build the generator, generate the code, and run the tests then run any of the following scripts:
		* `build_and_test.bat [clang|gcc|msvc]`
		* `build_and_test_all.bat`

Mac/Linux
---------
1. To build the generator, generate the code, and run the tests then run any one of the following scripts:

* `./scripts/build_and_test.sh [clang|gcc]`
* `./scripts/build_and_test_all.sh`


Submitting Changes
==================

1. Work in your own branch.  Don't work off `master`.
2. Name new branches using the `snake_case` naming convention.
2. Before submitting a PR make sure all the tests pass both locally on your machine and on GitHub Actions for all platforms.
	* If they don't pass both locally and on CI then I'm not accepting your changes until they do.
3. Please give as much detail as possible when writing your PR.
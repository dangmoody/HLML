# Contributing Code To HLML

HLML is accepting PRs!

## House Rules

* Your PR must be submitted in the form of a fork.
* Your PR fixes one of the issues in the repo's [issues list](https://github.com/dangmoody/HLML/issues).
* I am grateful for any and all PRs that get submitted, but it's entirely my discretion as to whether or not the PR gets accepted.  I will do my best to work with you on the changes before rejecting a PR.


## Prerequisites

Windows:
* MSVC

All platforms:
* [Builder](https://github.com/dangmoody/Builder)
* Clang 20.1.5
* GCC 15.2.0


## Building

### Windows

If you want to use Visual Studio, run `builder generate_solution.cpp`.


### All platforms

Run the following commands:
* `builder build_generator.cpp` to build the generator.
* `builder build_tests_<compiler>.cpp` where `<compiler>` is either `clang`, `gcc` or `msvc`.

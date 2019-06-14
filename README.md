# HLML

[![Build Status](https://travis-ci.com/floorman/HLML.svg?branch=master)](https://travis-ci.com/floorman/HLML)

(High Level Maths Library).

HLML is a C++ maths library (focused on games/graphics programming) which is loosely styled on HLSL syntax where all vector/matrix types are generated by a tool.  This means that there are zero templates in the generated code, which gives the following advantages:
* (Theoretically) Shorter compile times.
* Easier to read and debug.
* Ability to forward declare types.

As well as the above, HLML also offers the following:
* SIMD helper maths functions (experimental: in progress).
* Non-uniform matrix types.
* Boolean vectors to aid equality checking of vector types.

Currently HLML is written to produce optimised assembly for clang.  If you use another compiler then YMMV.

HLML is distributed under the GNU GPL v3 license.  See "LICENSE.md" for details.


Installation
============

1. Go to the [releases](https://github.com/floorman/HLML/releases) page and download the latest version.
2. Unzip the header files into your project.
3. **OPTIONAL:** Run ```hlm-gen-tests.exe``` (you shouldn't need to have a reason to run this and everything will more than likely 'just work', but you never know...).
4. **OPTIONAL:** Run ```generate_documentation.bat``` to generate the documentation.  This will put it into a folder called ```documentation``` and you can freely put it whereever you want.
5. Done!


Usage
=====
The main header files to include are:
* ```hlml_functions_scalar.h```
* ```hlml_functions_vector.h```
* ```hlml_functions_matrix.h```


Common Pitfalls
===============

**READ THIS BEFORE USING HLML:**

* All library functions and tests using floating point were written to be as respective to the IEEE-754 standard as possible.
* All matrix types are row-major, so a ```float3x4``` is a matrix that holds 3 ```float4```s (or, in other words: a ```float4``` array of size 3).
* All vector types are union of ```struct```/fixed-size array.
* HLML is focused on mathemetical expressive power where possible, therefore:
	* All matrices have the ```*``` operator overloaded to do matrix multiplication, **NOT** a component-wise multiplication.
	* All square matrices with floating point types have the ```/``` operator overloaded to multiply the light-hand matrix by the inverse of the right-hand matrix, it does **NOT** do a component-wise divide.
* To avoid conflicts with Windows ```min```/```max``` macros, you can define ```NOMINMAX``` before including HLML.
* HLML doesn't override any maths functions that are a part of C99.


Contributing
============

If this is a project you'd like to contribute to, I'm open to pull requests.  The GitHub issue tracker is being used.

Performance and usability are the two primary goals of the API.  If at any time those two goals are in confliction with each other, default to common sense.  =)


Motivation
==========

I've always primarily used GLM as my maths library of choice, but there were a few things that always bugged me about it:
* Types don't get initialised to default values by design.
* Sometimes had trouble reading past all of the templates.
* Often have trouble debugging the templates.
* Typing the namespace all the time got annoying.

(This isn't an attack on GLM, just some of my personal gripes with it).

One day I stumbled upon the [Unity.Mathematics](https://github.com/Unity-Technologies/Unity.Mathematics) library where I saw that all the maths types were being generated via a tool.  I decided to try the same but for C++: Write a tool that generated maths types for me to see if there were any benefits of doing it that way, and I found that there were:
* Compile time differences between the "generated" code and a templated equivalent were so minimal they weren't worth worrying about.
* Being able to "Peek Definition" on a type in Visual Studio and see just the header with that type in it.  No templates to read past, just very simple, minimal, and straightforward code.
* Maintaining changes across multiple (if not all) types was a lot easier than imagined.  Write the changes into the generator and watch it reflect the change across all the desired generated types automatically.


Licenses
========

HLML is distributed under the GNU GPL v3 license but the following software (which HLML uses) are not.  Therefore HLML's license does not apply to them:

* [Temper](https://github.com/floorman/temper) - MIT
* [Doxygen](http://www.doxygen.nl/) - GNU GPL v2
* [7-Zip](https://www.7-zip.org/download.html) - GNU LGPLv2.1+ with unRAR restriction / LZMA SDK in the public domain

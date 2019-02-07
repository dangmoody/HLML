@echo off

set config=%1%

clang++ -Xclang -flto-visibility-public-std -g -o Debug\\hlml-gen.exe hlml-gen\main.cpp hlml-gen\gen.cpp -Wall -Wextra

@echo off

set config=%1

set warning_flags=-Wall -Wextra -Werror
set ignore_warnings=-Wno-c++98-compat-pedantic -Wno-covered-switch-default -Wno-newline-eof -Wno-reserved-id-macro -Wno-global-constructors -Wno-exit-time-destructors

echo Building...
clang++ -Xclang -flto-visibility-public-std -std=c++14 -g -o %config%\hlml-gen_%config%.exe generator\*.cpp %warning_flags% %ignore_warnings%
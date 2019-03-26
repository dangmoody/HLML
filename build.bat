@echo off

set out_name=%1
set config=%2
set source_file_root=%3

set warning_flags=-Wall -Wextra -Werror
set ignore_warnings=-Wno-c++98-compat-pedantic -Wno-covered-switch-default -Wno-newline-eof -Wno-reserved-id-macro -Wno-global-constructors -Wno-exit-time-destructors

echo Building...
clang++ -Xclang -flto-visibility-public-std -std=c++14 -g -o build\%config%\%out_name%-%config%.exe %source_file_root%\*.cpp %warning_flags% %ignore_warnings%
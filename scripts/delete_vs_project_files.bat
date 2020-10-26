@echo off

REM set cwd to the folder that the batch file is in
pushd %~dp0%
pushd ..

REM delete all the old crap
echo ------- Deleting old VS files. -------

REM first delete all files in .vs
REM then delete .vs folder itself
del /f /s /q ".vs"
rmdir /s /q ".vs"

del /f /s /q *.sln
del /f /s /q *.vcxproj
del /f /s /q *.vcxproj.user
del /f /s /q *.vcxproj.filters
echo ------- Done. -------
echo.

popd
popd
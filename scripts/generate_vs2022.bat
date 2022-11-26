@echo off

echo.
echo WARNING: YOU WILL NEED TO CLOSE VISUAL STUDIO FOR THIS TO WORK PROPERLY.
echo.

REM set cwd to the folder that the batch file is in
pushd %~dp0%

call delete_vs_project_files.bat

pushd ..

REM generate new solution
echo ------- Generating new solution. -------
tools\premake5\premake5.exe --file=tools\premake5\premake5.lua vs2022
echo ------- Done. -------
echo.

popd

popd

echo Solution has been generated.

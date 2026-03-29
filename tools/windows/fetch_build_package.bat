@echo off
setlocal

:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
:: Create Build Folder
:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
set "bat_path=%~dp0"

:: Use fixed folder name to avoid issues with non-ASCII characters in date/time
set "BUILD_FOLDER=%cd%\BuildArtifacts"

echo BUILD_FOLDER=%BUILD_FOLDER%

:: Create the folder
md "%BUILD_FOLDER%" 2>nul

:: Go into the build folder
cd /d "%BUILD_FOLDER%"

echo Starting PreReq Routine...
set "prereq_bat=%bat_path%prereq.bat
call %prereq_bat%

echo Starting Build Routine...
set "build_bat=%bat_path%build.bat
call %build_bat%

echo Build complete. Packaging...
set "package_bat=%bat_path%package.bat
call %package_bat%

echo done...
exit /b
goto :eof


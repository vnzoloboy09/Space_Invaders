@echo off
setlocal

echo Checking for SDL2...

if not exist "..\vendor\SDL2\include" (
    echo SDL2 not found. Downloading...
    powershell -ExecutionPolicy Bypass -File "%~dp0DownloadSDL2.ps1"
)

pushd ..
scripts\premake5.exe --file=Build.lua vs2022
popd
pause
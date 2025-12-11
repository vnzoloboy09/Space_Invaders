$ErrorActionPreference = "Stop"

$SDL_URL = "https://github.com/libsdl-org/SDL/releases/download/release-2.30.5/SDL2-devel-2.30.5-VC.zip"
$ZIP_PATH = "$PSScriptRoot\SDL2.zip"
$DEST = "$PSScriptRoot\..\vendor\SDL2"

Write-Host "Downloading SDL2 from $SDL_URL..."
Invoke-WebRequest -Uri $SDL_URL -OutFile $ZIP_PATH

Write-Host "Extracting..."
Expand-Archive -Path $ZIP_PATH -DestinationPath $PSScriptRoot -Force

# SDL zip extracts into a folder like SDL2-2.30.5
$EXTRACTED = Get-ChildItem -Directory "$PSScriptRoot" | Where-Object { $_.Name -like "SDL2-*" } | Select-Object -First 1

Write-Host "Copying SDL2 files..."
New-Item -ItemType Directory -Force -Path $DEST | Out-Null
Copy-Item -Path "$($EXTRACTED.FullName)\include" -Destination $DEST -Recurse -Force
Copy-Item -Path "$($EXTRACTED.FullName)\lib" -Destination $DEST -Recurse -Force

Write-Host "Cleaning up..."
Remove-Item $ZIP_PATH
Remove-Item $EXTRACTED.FullName -Recurse -Force

Write-Host "SDL2 downloaded and installed."
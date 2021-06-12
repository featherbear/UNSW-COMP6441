@echo off
cd %~dp0
@echo off
setlocal enabledelayedexpansion
rem find directories called bin
for /f "usebackq tokens=*" %%i in (`dir /b /a:d`) do (
  if not "%%i" == "__hugo" rmdir /s /q "%%i"
)
for /f "usebackq tokens=*" %%i in (`dir /b /a:-d-h`) do (
  if not "%%i" == "__build.bat" del /q "%%i"
)
endlocal

cd %~dp0\__hugo
hugo.exe --minify
cd %~dp0
rem hugo


@echo off

pushd %~dp0
call "%VS100COMNTOOLS%/vsvars32.bat"

set dir_10common=.\..\..\10-common\

set compileinfo_dll_d_name=avcollection-d_win32.txt
set compileinfo_dll_r_name=avcollection-r_win32.txt

echo ========avcollection====win32 version========

echo build clean debug
del /F /Q debug\*.*
del /F /Q .\..\..\10-common\version\compileInfo\%compileinfo_dll_d_name%
devenv AVCollection.vcxproj /Rebuild "Debug|Win32"  /Out %dir_10common%\version\compileInfo\%compileinfo_dll_d_name%

echo build clean release
del /F /Q release\*.*
del /F /Q .\..\..\10-common\version\compileInfo\%compileinfo_dll_r_name%
devenv AVCollection.vcxproj /Rebuild "Release|Win32"  /Out %dir_10common%\version\compileInfo\%compileinfo_dll_r_name%

popd

echo on

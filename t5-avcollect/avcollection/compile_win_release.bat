@echo off

pushd %~dp0
call "%VS140COMNTOOLS%/vsvars32.bat"

set dir_10common=.\..\..\10-common\

set compileinfo_dll_r_name=avcollection-r_win32.txt

echo ========avcollection====win32 version========

echo build clean release
if exist "release\*.*" del /F /Q "release\*.*"
if exist ".\..\..\10-common\version\compileInfo\%compileinfo_dll_r_name%" (
    del /F /Q ".\..\..\10-common\version\compileInfo\%compileinfo_dll_r_name%"
)

devenv AVCollection.vcxproj /Rebuild "Release" /Project AVCollection.vcxproj /ProjectConfig "Release|Win32" /Out "%dir_10common%\version\compileInfo\%compileinfo_dll_r_name%"

popd

echo on

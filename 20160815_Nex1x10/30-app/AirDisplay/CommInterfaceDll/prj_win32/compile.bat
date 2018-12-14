echo off
echo CommInterfaceDll.dll build begin


if not exist "release" (
	mkdir "release"
)

set compileInfoPath=..\..\..\..\10-common\version\compileinfo

if exist "%compileInfoPath%\airdisplay_CommInterfaceDll_r.txt" (
del "%compileInfoPath%\airdisplay_CommInterfaceDll_r.txt"
)



call "%VS100COMNTOOLS%\vsvars32.bat"

echo build clean release vs2010
@devenv CommInterfaceDll.vcxproj /ReBuild "Release" /Out "%compileInfoPath%\airdisplay_CommInterfaceDll_r.txt"

rem 还原现场
rem call "%VS60COMNTOOLS%\vcvars32.bat"

echo build CommInterfaceDll.dll over
echo on

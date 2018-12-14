echo off
echo tservice.exe build begin


if not exist "release" (
	mkdir "release"
)

set compileVerPath=..\..\..\..\10-common\version


if exist "%compileVerPath%\compileinfo\airdisplay_tservice_r.txt" (
del "%compileVerPath%\compileinfo\airdisplay_tservice_r.txt"
)

call "%VS100COMNTOOLS%\vsvars32.bat"
echo build clean release vs2010
@devenv tservice.vcxproj /ReBuild "Release" /Out "%compileVerPath%\compileinfo\airdisplay_tservice_r.txt"

rem ��ԭ�ֳ�
rem call "%VS60COMNTOOLS%\vcvars32.bat"

copy /Y release\tservice.exe "%compileVerPath%\release\win32\AirDisplay\tservice.exe"

rem ����ǩ��
autosigntool tservice_r.ini

echo build tservice.exe over
echo on

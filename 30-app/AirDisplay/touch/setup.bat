@echo off
echo NexTransmitter.exe build begin

rem ��ȡNSIS��װ·����softDisk:�̷���softPathTmp:�̷�ð�ź�����ַ�������delims=: ����ʾð�źͿո��Ƿָ���
goto start
for /f "skip=2 tokens=3* delims=: " %%j in ('reg query HKEY_LOCAL_MACHINE\SOFTWARE\NSIS /ve') do (
   set softDisk=%%j
   set softPathTmp=%%k
)
set softPath=%softDisk%:%softPathTmp%
:start
rem ��ȡNSIS��װ·�����ӻ��������ж�ȡ
set softPath=%NSIS%

set compileVerPath=..\..\..\10-common\version\release\win32\AirDisplay

if exist "setup files" (
    rmdir /s/q "setup files"
)


if not exist "setup files" (
    mkdir "setup files"
)


xcopy "%compileVerPath%\*.*" "setup files\" /s /y /h
copy /Y "setup\setup.nsi" "setup files\"
copy /Y "setup\touch.ico" "setup files\"

rem �����NexTransmitter.exe
cd "setup files"
"%softPath%\makensis.exe" setup.nsi
cd..

copy /Y "setup files\NexTransmitter.exe" "%compileVerPath%\"

cd "setup"
call compile.bat %1
cd..

rmdir /s/q "setup files"

echo NexTransmitter.exe build end
:end

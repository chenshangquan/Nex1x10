@echo off
echo NexTransmitter.iso build begin


if exist "setup files" (
    rmdir /s/q "setup files"
)


if not exist "setup files" (
    mkdir "setup files"
)

set compileVerPath=..\..\..\..\10-common\version\release\win32\AirDisplay

rem ����ǩ��
autosigntool NexTransmitter.ini

copy /Y "%compileVerPath%\NexTransmitter.exe" "setup files\"
copy /Y "Autorun.inf" "setup files\"

rem ����Autorun.infΪ�����ļ�
attrib +h "setup files\Autorun.inf"

rem �����iso
"%UltraISO%\UltraISO.exe" -volume NexTransmitter -file "setup files\*.*" -output "%compileVerPath%\NexTransmitter.iso" -joliet -lowercase -silent



rmdir /s/q "setup files"

echo NexTransmitter.iso build end
echo on
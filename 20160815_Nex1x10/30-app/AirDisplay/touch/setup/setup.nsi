
;---------------------------ȫ�ֱ���ű�Ԥ����ĳ���-----------------------------------------------------
!define OUTFILE_NAME "NexTransmitter.exe"
 ;��װͼ���·������
!define MUI_ICON "touch.ico"
!define PRODUCT_DIR_REGKEY "Software\Kedacom\NexTransmitter"
!define PRODUCT_DIR_REGDLL "Software\Microsoft\Windows NT\CurrentVersion\Drivers32"

;tservice.exeʵ�ֿ������е�ע���λ�ü������ֵ
!define PRODUCT_DIR_REGSERVER "Software\Microsoft\Windows\CurrentVersion\Run"
!define TSERVICE_AUTO_RUN "$\"$LOCALAPPDATA\NexTransmitter\tservice.exe$\" hide"

;�汾��,ע����touch�汾�ű���һ��
!define PRODUCT_VER 5.2.0.2.0
!define /date PRODUCT_DATE %Y%m%d
!define PRODUCT_VERSION "${PRODUCT_VER}.${PRODUCT_DATE}"

;dll��Ϣ
!define VIDC_TPH4        "vidc.tph4"
!define MSACM_KDMP3      "msacm.kdmp3"
!define MSACM_KDMP3_ACM  "msacm.kdmp3.acm"

!define TPH4_DLL         "tph4.dll"
!define KDMP3_ACM        "kdmp3.acm"

 
;---------------------------�������ѹ�����ͣ�Ҳ����ͨ���������ű����ƣ�------------------------------------
SetCompressor lzma
SetCompress force
XPStyle on

; ------ MUI �ִ����涨�� (1.67 �汾���ϼ���) ------
!include "nsWindows.nsh"
!include "MUI.nsh"
!include "WordFunc.nsh"

!define MUI_CUSTOMFUNCTION_GUIINIT onGUIInit

;�Զ���ҳ��
Page custom WelcomePage
; ��װ�����������������
!insertmacro MUI_LANGUAGE "SimpChinese" ;ע�ʹ˾پͻ��б߿� �����ͻ��ޱ߿�

;-------------------------��˾��Ϣ-----------------------------------------------------

!define PRODUCT_PUBLISHER "���ݿƴ�Ƽ��ɷ����޹�˾"
!define PRODUCT_NAME "NexTransmitter"
!define PRODUCT_DESC "NexTransmitter Setup"

VIProductVersion "${PRODUCT_VERSION}"
VIAddVersionKey /LANG=2052 "ProductName" "${PRODUCT_NAME}"
VIAddVersionKey /LANG=2052 "CompanyName" "${PRODUCT_PUBLISHER}"
VIAddVersionKey /LANG=2052 "FileDescription" "${PRODUCT_DESC}"
VIAddVersionKey /LANG=2052 "FileVersion" "${PRODUCT_VERSION}"
VIAddVersionKey /LANG=2052 "ProductVersion" "${PRODUCT_VERSION}"
VIAddVersionKey /LANG=2052 "LegalCopyright" "��Ȩ���� (C) 2017 ${PRODUCT_PUBLISHER}"
;------------------------------------------------------MUI �ִ����涨���Լ���������------------------------

;Ӧ�ó�����ʾ����
Name "NexTransmitter"
;Ӧ�ó������·��
OutFile "${OUTFILE_NAME}"
InstallDir "$LOCALAPPDATA\NexTransmitter"
;��ù���ԱȨ��
RequestExecutionLevel user
;ȥ����װ�������CRCУ�飬Ĭ�Ͽ���
CRCCheck off

Var old_ver
Var new_ver
Var info

Function .onInit
    Call onOnlyStartOne
	ClearErrors
	;��ȡ�汾��,û�ж�����Ϊδ��װ
	ReadRegStr $old_ver HKCU "${PRODUCT_DIR_REGKEY}" "Version"
	IfErrors 0 +2
	  Return
    StrCpy $new_ver ${PRODUCT_VERSION}
	;�汾�Ƚ�,���°汾������
	${VersionCompare} $new_ver $old_ver $0
	;MessageBox MB_OK "�ȽϽ��:$0"
	${if} $0 == 0
	    Call isFileNoLack
	    Pop $0
	    ${If} $0 == "true"  
		   ;ע��dll  ���ϵͳ��������dllֵ��ɾ�����
	       Call RegisterDll
           Call OpenTouch
		   Call OpenService
           Call onClose
		   Abort
        ${Else}  
           Call CloseService
		   sleep 100
	       Delete "$INSTDIR\*.*"
		   Return
        ${EndIf}  
	${Else}
	    Call CloseService
		sleep 100
	    Delete "$INSTDIR\*.*"
		Return
	${EndIf}
FunctionEnd

Function onGUIInit
    ;�����߿�
    System::Call `user32::SetWindowLong(i$HWNDPARENT,i${GWL_STYLE},0x9480084C)i.R0`
    ;����һЩ���пؼ�
    GetDlgItem $0 $HWNDPARENT 1034
    ShowWindow $0 ${SW_HIDE}
    GetDlgItem $0 $HWNDPARENT 1035
    ShowWindow $0 ${SW_HIDE}
    GetDlgItem $0 $HWNDPARENT 1036
    ShowWindow $0 ${SW_HIDE}
    GetDlgItem $0 $HWNDPARENT 1037
    ShowWindow $0 ${SW_HIDE}
    GetDlgItem $0 $HWNDPARENT 1038
    ShowWindow $0 ${SW_HIDE}
    GetDlgItem $0 $HWNDPARENT 1039
    ShowWindow $0 ${SW_HIDE}
    GetDlgItem $0 $HWNDPARENT 1256
    ShowWindow $0 ${SW_HIDE}
    GetDlgItem $0 $HWNDPARENT 1028
    ShowWindow $0 ${SW_HIDE}
FunctionEnd

Function isFileNoLack
    ${If} ${FileExists} "$INSTDIR\touch.exe"
    ${AndIf} ${FileExists} "$INSTDIR\tservice.exe"
    ${AndIf} ${FileExists} "$INSTDIR\AVCollection.dll"
    ${AndIf} ${FileExists} "$INSTDIR\asflib.dll"
    ${AndIf} ${FileExists} "$INSTDIR\h264enc_x.dll"
    ${AndIf} ${FileExists} "$INSTDIR\kdvmedianetdll.dll"
	${AndIf} ${FileExists} "$INSTDIR\libkdcrypto-1_1.dll"
	${AndIf} ${FileExists} "$INSTDIR\libkdvsrtp.dll"
	${AndIf} ${FileExists} "$INSTDIR\mediasdkvc10.dll"
	${AndIf} ${FileExists} "$INSTDIR\mediawrapper.dll"
	${AndIf} ${FileExists} "$INSTDIR\ospdll.dll"
	${AndIf} ${FileExists} "$INSTDIR\kdimg.dll"
	${AndIf} ${FileExists} "$INSTDIR\tph4.dll"
	${AndIf} ${FileExists} "$INSTDIR\kdmp3.acm"
	${AndIf} ${FileExists} "$INSTDIR\kdaudproc.dll"
	${AndIf} ${FileExists} "$INSTDIR\mfc100u.dll"
	${AndIf} ${FileExists} "$INSTDIR\msvcp100.dll"
	${AndIf} ${FileExists} "$INSTDIR\msvcr100.dll"
	;Ӳ����������
	${AndIf} ${FileExists} "$INSTDIR\kdaudcodec.dll"
	${AndIf} ${FileExists} "$INSTDIR\HwCodecWrapper.dll"
	${AndIf} ${FileExists} "$INSTDIR\IntelHwWrapper.dll"
	    Push "true"
	${Else}
	    Push "false"
	${EndIf}
FunctionEnd

Function OpenTouch
    ;˫��Ͷ�����̷�����������touch������ʾ�����صĴ���
    ;FindProcDLL::FindProc "touch.exe"
    ;Pop $R0
    ;${If} $R0 == 0
		ExecShell open "$INSTDIR\touch.exe"
    ;${EndIf}
FunctionEnd

Function OpenService
    FindProcDLL::FindProc "tservice.exe"
    Pop $R0
    ${If} $R0 == 0
		ExecShell open "$INSTDIR\tservice.exe"
    ${EndIf}
FunctionEnd

Function CloseService
   FindProcDLL::FindProc "tservice.exe"
   Pop $R0
   ${If} $R0 != 0
	    KillProcDLL::KillProc "tservice.exe"
   ${Endif}
FunctionEnd

;����Ƶ�����dllע�ắ��
Function RegisterDll
    ReadRegStr $info HKCU "${PRODUCT_DIR_REGDLL}" "${VIDC_TPH4}"
	IfErrors 0 +2
	  WriteRegStr HKCU "${PRODUCT_DIR_REGDLL}" "${VIDC_TPH4}" "${TPH4_DLL}"
	ReadRegStr $info HKCU "${PRODUCT_DIR_REGDLL}" "${MSACM_KDMP3}" 
	IfErrors 0 +2
	  WriteRegStr HKCU "${PRODUCT_DIR_REGDLL}" "${MSACM_KDMP3}" "${KDMP3_ACM}"
	ReadRegStr $info HKCU "${PRODUCT_DIR_REGDLL}" "${MSACM_KDMP3_ACM}" 
	IfErrors 0 +2
	  WriteRegStr HKCU "${PRODUCT_DIR_REGDLL}" "${MSACM_KDMP3_ACM}" "${KDMP3_ACM}"
    Return 
FunctionEnd

Function MAINInstall32
  SetOutPath "$INSTDIR"
  SetOverwrite ifnewer
  File "touch.exe"
  File "tservice.exe"
  File "AVCollection.dll"
  File "asflib.dll"
  File "h264enc_x.dll"
  File "kdvmedianetdll.dll"
  File "libkdcrypto-1_1.dll"
  File "libkdvsrtp.dll"
  File "mediasdkvc10.dll"
  File "mediawrapper.dll"
  File "ospdll.dll"
  File "kdimg.dll"
  File "tph4.dll"
  File "kdmp3.acm"
  File "kdaudproc.dll"
  File "mfc100u.dll"
  File "msvcp100.dll"
  File "msvcr100.dll"
  ;Ӳ����������
  File "kdaudcodec.dll"
  File "HwCodecWrapper.dll"
  File "IntelHwWrapper.dll"
  
  Call onComplete
FunctionEnd

;�رմ���
Function onClose
    FindProcDLL::FindProc "${OUTFILE_NAME}"
    Pop $R0
    ${If} $R0 != 0
    KillProcDLL::KillProc "${OUTFILE_NAME}"
    ${EndIf}
FunctionEnd

;ֻ������һ��
Function onOnlyStartOne
    ;���������ֹ�ظ�����  
     System::Call 'kernel32::CreateMutexA(i 0, i 0, t"Winsnap_installer") i .r1 ?e'  
     Pop $R0  
     StrCmp $R0 0 +2  
     Abort  
FunctionEnd

;���������
Function onComplete
      ;ע��汾��
      WriteRegStr HKCU "${PRODUCT_DIR_REGKEY}" "Version" "${PRODUCT_VERSION}"
	  ;ʵ��tservice.exe��������
	  ReadRegStr $info HKCU "${PRODUCT_DIR_REGSERVER}" "NexTransmitter"
	  IfErrors 0 +2
	    WriteRegStr HKCU "${PRODUCT_DIR_REGSERVER}" "NexTransmitter" "${TSERVICE_AUTO_RUN}"
      ;ע��dll
	  Call RegisterDll
	  ;ȥ������ǽ����
	  nsExec::Exec '"cmd.exe" /c netsh advfirewall firewall Delete rule name="allow touch"'
      nsExec::Exec '"cmd.exe" /c netsh advfirewall firewall add rule name="allow touch" dir=in action=allow program="$INSTDIR\touch.exe"'
	  ;���г���
      ExecShell open "$INSTDIR\touch.exe"
	  sleep 1000
      ExecShell open "$INSTDIR\tservice.exe"
FunctionEnd

Function WelcomePage
    GetFunctionAddress $0 MAINInstall32
    BgWorker::CallAndWait
FunctionEnd

Section SEC
SectionEnd

Section -Post
SectionEnd

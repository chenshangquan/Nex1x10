#include "stdafx.h"
#include "ppt.h"
#include "tlhelp32.h"

CPpt::CPpt()
{

}

CPpt::~CPpt()
{

}

BOOL CPpt::IsFullScreenActive( DWORD &dwProcessID )
{
	 /* 
    ���������ȡ��Ļ4�ǵĴ��ڵĽ��̾�����ж��뼤�����Ƿ���ȵķ�ʽ���ж��Ƿ�ȫ������ 
    �ر�ģ��� IE ֮��Ķ��ǩ����̳����Ӵ��ڵĽ��̻�������ڲ�ͬ����Ҫ��ȡ���ڵ����������ԱȲſ��� 
    */  
    bool lbRet = false;  
    HWND lHforewnd=::GetForegroundWindow();  
    DWORD lWDProcessID;  
    GetWindowThreadProcessId( lHforewnd, &lWDProcessID );  
  
    // ��ȡ��Ļ��С  
    int iCx=GetSystemMetrics(SM_CXSCREEN);  
    int iCy=GetSystemMetrics(SM_CYSCREEN);  
    do   
    {  
        if( CheckSame(lWDProcessID,0,0) ==false)   
            break;  
  
        if( CheckSame(lWDProcessID,iCx-1,0) ==false)   
            break;  
  
        if( CheckSame(lWDProcessID,0,iCy-1) ==false)   
            break;  
  
        if( CheckSame(lWDProcessID,iCx-1,iCy-1) ==false)   
            break;  
  
        lbRet = true;  
    } while (false);  
  
	if (lbRet)
	{
		dwProcessID = lWDProcessID;
	}

    return lbRet;  
}

bool CPpt::CheckSame( DWORD dwProcessID,int niX,int niY )
{
	bool lbRet = false;  

	POINT lpt={niX,niY};  
	HWND lhwnd= (HWND)WindowFromPoint (lpt);  
	HWND lHdesktop= (HWND)GetDesktopWindow();  
	HWND lHparent=0;  
	for(;;)  
	{ // ���Ҵ��ڵ�������  
		lHparent= ::GetParent(lhwnd);  
		if( lHparent==lHdesktop || lHparent==0 )  
			break;  
		lhwnd=lHparent;  
	}  
	DWORD dwPid=0;  
	GetWindowThreadProcessId( lhwnd, &dwPid );  
	if (dwPid == dwProcessID)  
	{  
		lbRet = true;  
	}  
	else  
	{  
		lbRet = false;  
	}  
	return lbRet;  
}

BOOL CPpt::ProcessIdToName( CString &strProcessName, DWORD dwPID )
{
	PROCESSENTRY32 pe;      
	DWORD id=0;      
	HANDLE hSnapshot=CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS,0);
	pe.dwSize=sizeof(PROCESSENTRY32);      
	if(!Process32First(hSnapshot,&pe))
	{
		return FALSE;      
	}

	pe.dwSize=sizeof(PROCESSENTRY32);      
	while(Process32Next(hSnapshot,&pe) != FALSE)      
	{
		if (pe.th32ProcessID == dwPID)
		{
			strProcessName.Format(_T("%s"), pe.szExeFile);
			break;
		}
	}      
	CloseHandle(hSnapshot);      
	return TRUE;      
}

bool CPpt::IsPptPlaying()
{
	DWORD lWDProcessID;
	BOOL bRst = IsFullScreenActive(lWDProcessID);
	if (bRst)
	{
		CString strName;
		ProcessIdToName(strName, lWDProcessID);
		strName.MakeLower();

		if (strName == _T("wpp.exe") 
			||strName == _T("powerpnt.exe"))
		{
			return true;
		}
	}

	return false;
}

void CPpt::PPT_StopPlay()
{
	keybd_event(VK_ESCAPE,0,0,0);
	keybd_event(VK_ESCAPE,0,KEYEVENTF_KEYUP,0);
}

void CPpt::PPT_NextPage()
{
	keybd_event(VK_DOWN,0,0,0);    //����һҳ��
	keybd_event(VK_DOWN,0,KEYEVENTF_KEYUP,0);
}

void CPpt::PPT_PriviousPage()
{
	keybd_event(VK_UP,0,0,0);  //����һҳ��
	keybd_event(VK_UP,0,KEYEVENTF_KEYUP,0);
}


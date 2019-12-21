
// tservice.cpp : ����Ӧ�ó��������Ϊ��
//

#include "stdafx.h"
#include "tservice.h"
#include "tserviceDlg.h"
#include <imagehlp.h>

#pragma comment(lib, "DbgHelp.lib")

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CtserviceApp

BEGIN_MESSAGE_MAP(CtserviceApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CtserviceApp ����

CtserviceApp::CtserviceApp()
{
	// ֧����������������
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CtserviceApp ����

CtserviceApp theApp;

//ץ���쳣��Ϣ
LONG ApplicationCrashHandler(EXCEPTION_POINTERS *pException)  
{     
	// ����Dump�ļ�
	HANDLE hDumpFile = CreateFileW(L"tserviceException.dmp", GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	// Dump��Ϣ
	MINIDUMP_EXCEPTION_INFORMATION dumpInfo;
	dumpInfo.ExceptionPointers = pException;
	dumpInfo.ThreadId = GetCurrentThreadId();
	dumpInfo.ClientPointers = TRUE;
	// д��Dump�ļ�����
	MiniDumpWriteDump(GetCurrentProcess(), GetCurrentProcessId(), hDumpFile, MiniDumpNormal, &dumpInfo, NULL, NULL);
	CloseHandle(hDumpFile);
	return EXCEPTION_EXECUTE_HANDLER;  
}

// CtserviceApp ��ʼ��

BOOL CtserviceApp::InitInstance()
{
	//ֻ����һ������ʵ��
	if ( !OnlyStartOne() )
	{
		//AfxMessageBox(_T("!OnlyStartOne()"));
		LPCWSTR className = NULL;
		LPCWSTR windName = _T("tservice");

		HWND hWnd = ::FindWindow( className , windName );
		if ( IsWindow( hWnd ) )
		{
			//AfxMessageBox(_T("IsWindow"));
			if ( !::IsWindowVisible( hWnd ) )
			{
				::ShowWindow( hWnd, SW_SHOWNORMAL );
				::SetForegroundWindow( hWnd );
			}  

			//AfxMessageBox(_T("TerminateProcess"));
			TerminateProcess(GetCurrentProcess(), 0);
			return FALSE;
		}
	}

	CWinApp::InitInstance();


	// ���� shell ���������Է��Ի������
	// �κ� shell ����ͼ�ؼ��� shell �б���ͼ�ؼ���
	CShellManager *pShellManager = new CShellManager;

	// ��׼��ʼ��
	// ���δʹ����Щ���ܲ�ϣ����С
	// ���տ�ִ���ļ��Ĵ�С����Ӧ�Ƴ�����
	// ����Ҫ���ض���ʼ������
	// �������ڴ洢���õ�ע�����
	// TODO: Ӧ�ʵ��޸ĸ��ַ�����
	// �����޸�Ϊ��˾����֯��
	SetRegistryKey(_T("Ӧ�ó��������ɵı���Ӧ�ó���"));

	//ץ���쳣�ļ�
	::SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)ApplicationCrashHandler);  //cash����

	//���ÿ����Զ�����
	//CreateRun();

	CtserviceDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: �ڴ˷��ô����ʱ��
		//  ��ȷ�������رնԻ���Ĵ���
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: �ڴ˷��ô����ʱ��
		//  ��ȡ�������رնԻ���Ĵ���
	}

	// ɾ�����洴���� shell ��������
	if (pShellManager != NULL)
	{
		delete pShellManager;
	}

	// ���ڶԻ����ѹرգ����Խ����� FALSE �Ա��˳�Ӧ�ó���
	//  ����������Ӧ�ó������Ϣ�á�
	return FALSE;
}

int CtserviceApp::CreateRun(void)
{
	//������´���
	HKEY   RegKey;   

	TCHAR achfilePath[MAX_PATH];
	::SHGetSpecialFolderPath (NULL, achfilePath, CSIDL_APPDATA , FALSE);
	CString strDstName;
	strDstName.Format(_T("%s\\NexTransmitter\\tservice.exe"),achfilePath);

	CFileFind   fFind;   
	BOOL   bSuccess;   
	bSuccess=fFind.FindFile(strDstName);
	fFind.Close();   
	if(bSuccess)   
	{   
		CString   fullName;   
		fullName.Format(_T("\"%s\" hide"),strDstName);
		RegKey=NULL;   
		long lRet = RegOpenKeyEx(HKEY_LOCAL_MACHINE,_T("Software\\Microsoft\\Windows\\CurrentVersion\\Run"), 0, KEY_WRITE, &RegKey);
		if(lRet == ERROR_SUCCESS) 
		{ 
			//win7 64��ϵͳ �������⡰HKEY_LOCAL_MACHINE\SOFTWARE\Wow6432Node\Microsoft\Windows\CurrentVersion\explorer\Advanced\Folder\Hidden\SHOWALL��
			lRet = RegSetValueEx(RegKey, _T("touch"), 0, REG_SZ, (const unsigned char*)(LPCTSTR)fullName,MAX_PATH);
			//�ر�ע��� 
			RegCloseKey(RegKey); 
			if(lRet != ERROR_SUCCESS) 
			{ 
				AfxMessageBox(_T("ϵͳ��������,������ϵͳ����")); 
			} 
		}
	}   
	else   
	{   
		AfxMessageBox(_T("û�ҵ�ִ�г����Զ�����ʧ��"));
		exit(0);   
	}   

	return 0;
}

BOOL OnlyStartOne()
{
	HANDLE  hSem  =  CreateSemaphore(NULL,  1,  1, AfxGetApp()->m_pszAppName);   

	//   �ź������ڣ����������һ��ʵ������   
	if (GetLastError()   ==   ERROR_ALREADY_EXISTS)   
	{  		
		//   �ر��ź������   
		CloseHandle(hSem);   
		//   Ѱ����ǰʵ����������   
		HWND   hWndPrevious = ::GetWindow(::GetDesktopWindow(),GW_CHILD);   
		while   (::IsWindow(hWndPrevious))   
		{   
			//   ��鴰���Ƿ���Ԥ��ı��?   
			//   �У���������Ѱ�ҵ�����   
			if   (::GetProp(hWndPrevious, AfxGetApp()->m_pszAppName))   
			{    		 
				//BOOL re = ((CIPSetterDlg)(CWnd::FromHandle(hWndPrevious))).setDestroyFlagEx(FALSE);
				//(CWnd::FromHandle(hWndPrevious))->SendMessage(WM_DESTROY_FLAG,FALSE,TRUE); 

				//   ����������С������ָ����С   
				if   (::IsIconic(hWndPrevious)) 				
					::ShowWindow(hWndPrevious,SW_RESTORE);   

				HWND hdl = GetForegroundWindow();
				if (hWndPrevious !=  hdl )
				{   					
					::ShowWindow(hWndPrevious,SW_RESTORE); 
					::SetForegroundWindow(hWndPrevious);
				}

				return   FALSE;   
			}   
			//   ����Ѱ����һ������   
			hWndPrevious   =   ::GetWindow(hWndPrevious,GW_HWNDNEXT); 
		}   
		//   ǰһʵ���Ѵ��ڣ����Ҳ���������   
		//   �˳���ʵ��   
		return   FALSE;   
	} 
	return TRUE;
}
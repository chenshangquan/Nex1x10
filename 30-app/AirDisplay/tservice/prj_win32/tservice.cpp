
// tservice.cpp : 定义应用程序的类行为。
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


// CtserviceApp 构造

CtserviceApp::CtserviceApp()
{
	// 支持重新启动管理器
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

	// TODO: 在此处添加构造代码，
	// 将所有重要的初始化放置在 InitInstance 中
}


// 唯一的一个 CtserviceApp 对象

CtserviceApp theApp;

//抓捕异常信息
LONG ApplicationCrashHandler(EXCEPTION_POINTERS *pException)  
{     
	// 创建Dump文件
	HANDLE hDumpFile = CreateFileW(L"tserviceException.dmp", GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	// Dump信息
	MINIDUMP_EXCEPTION_INFORMATION dumpInfo;
	dumpInfo.ExceptionPointers = pException;
	dumpInfo.ThreadId = GetCurrentThreadId();
	dumpInfo.ClientPointers = TRUE;
	// 写入Dump文件内容
	MiniDumpWriteDump(GetCurrentProcess(), GetCurrentProcessId(), hDumpFile, MiniDumpNormal, &dumpInfo, NULL, NULL);
	CloseHandle(hDumpFile);
	return EXCEPTION_EXECUTE_HANDLER;  
}

// CtserviceApp 初始化

BOOL CtserviceApp::InitInstance()
{
	//只开启一个程序实例
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


	// 创建 shell 管理器，以防对话框包含
	// 任何 shell 树视图控件或 shell 列表视图控件。
	CShellManager *pShellManager = new CShellManager;

	// 标准初始化
	// 如果未使用这些功能并希望减小
	// 最终可执行文件的大小，则应移除下列
	// 不需要的特定初始化例程
	// 更改用于存储设置的注册表项
	// TODO: 应适当修改该字符串，
	// 例如修改为公司或组织名
	SetRegistryKey(_T("应用程序向导生成的本地应用程序"));

	//抓捕异常文件
	::SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)ApplicationCrashHandler);  //cash代码

	//设置开机自动运行
	//CreateRun();

	CtserviceDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: 在此放置处理何时用
		//  “确定”来关闭对话框的代码
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: 在此放置处理何时用
		//  “取消”来关闭对话框的代码
	}

	// 删除上面创建的 shell 管理器。
	if (pShellManager != NULL)
	{
		delete pShellManager;
	}

	// 由于对话框已关闭，所以将返回 FALSE 以便退出应用程序，
	//  而不是启动应用程序的消息泵。
	return FALSE;
}

int CtserviceApp::CreateRun(void)
{
	//添加以下代码
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
			//win7 64的系统 定向到了这“HKEY_LOCAL_MACHINE\SOFTWARE\Wow6432Node\Microsoft\Windows\CurrentVersion\explorer\Advanced\Folder\Hidden\SHOWALL”
			lRet = RegSetValueEx(RegKey, _T("touch"), 0, REG_SZ, (const unsigned char*)(LPCTSTR)fullName,MAX_PATH);
			//关闭注册表 
			RegCloseKey(RegKey); 
			if(lRet != ERROR_SUCCESS) 
			{ 
				AfxMessageBox(_T("系统参数错误,不能随系统启动")); 
			} 
		}
	}   
	else   
	{   
		AfxMessageBox(_T("没找到执行程序，自动运行失败"));
		exit(0);   
	}   

	return 0;
}

BOOL OnlyStartOne()
{
	HANDLE  hSem  =  CreateSemaphore(NULL,  1,  1, AfxGetApp()->m_pszAppName);   

	//   信号量存在，则程序已有一个实例运行   
	if (GetLastError()   ==   ERROR_ALREADY_EXISTS)   
	{  		
		//   关闭信号量句柄   
		CloseHandle(hSem);   
		//   寻找先前实例的主窗口   
		HWND   hWndPrevious = ::GetWindow(::GetDesktopWindow(),GW_CHILD);   
		while   (::IsWindow(hWndPrevious))   
		{   
			//   检查窗口是否有预设的标记?   
			//   有，则是我们寻找的主窗   
			if   (::GetProp(hWndPrevious, AfxGetApp()->m_pszAppName))   
			{    		 
				//BOOL re = ((CIPSetterDlg)(CWnd::FromHandle(hWndPrevious))).setDestroyFlagEx(FALSE);
				//(CWnd::FromHandle(hWndPrevious))->SendMessage(WM_DESTROY_FLAG,FALSE,TRUE); 

				//   主窗口已最小化，则恢复其大小   
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
			//   继续寻找下一个窗口   
			hWndPrevious   =   ::GetWindow(hWndPrevious,GW_HWNDNEXT); 
		}   
		//   前一实例已存在，但找不到其主窗   
		//   退出本实例   
		return   FALSE;   
	} 
	return TRUE;
}
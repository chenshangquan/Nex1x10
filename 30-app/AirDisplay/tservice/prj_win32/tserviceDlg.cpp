
// tserviceDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "tservice.h"
#include "tserviceDlg.h"
#include "afxdialogex.h"
#include "winioctl.h"
#include <dbt.h>
#include "progress.h"
#include <iostream>
using namespace std;


#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define UdiskExistTimerId 2
#define CheckTouchTimerId 3


// CtserviceDlg 对话框
void CtserviceDlg::OnTimer(UINT_PTR nIDEvent)   
{   
	// TODO: Add your message handler code here and/or call default   
	switch (nIDEvent)   
	{   
	case UdiskExistTimerId:   
		{
			if (UdiskIn())
			{
				KillTimer(UdiskExistTimerId);
				m_bTimerRun = false;

				WriteLog("OnTimer:UdiskIn\r\n");
			}
			break;
		}
	case CheckTouchTimerId:
		{
			UdiskIn();	
			break;
		}
	default:   
		break;   
	}

	CDialogEx::OnTimer(nIDEvent);   
}  

CtserviceDlg::CtserviceDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CtserviceDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_bTimerRun = false;

	m_bCheckTouchTimerRun = false;
	m_nFailCount = 0;

	InitializeCriticalSection(&m_hSem);
}

void CtserviceDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

LRESULT CtserviceDlg::WindowProc(UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_DEVICECHANGE:
		{
			switch (wParam)
			{
			case DBT_DEVICEARRIVAL:// Handle device arrival
				{
					if ( !m_bTimerRun && !m_bCheckTouchTimerRun )
					{
						if ( UdiskIn() )
						{
							WriteLog("WindowProc:UdiskIn\r\n");
						}
					}
				}
				break;

			case DBT_DEVICEREMOVECOMPLETE:// Handle device removal
				break;
			}
		}
	}	  
	return CDialogEx::WindowProc(message, wParam, lParam);
}

bool CtserviceDlg::UdiskIn()
{
	if (CProgress::IsProgressRunning(_T("touch.exe")))
	{
		return true;
	}

	DWORD dwCount = 0;
	SetErrorMode(SEM_FAILCRITICALERRORS);  //set error mode

	DWORD dwLen=GetLogicalDriveStrings(0,NULL);
	if( dwLen == 0) //error
	{
		return false;
	}
	LPTSTR lpDriveStrings=(LPTSTR)HeapAlloc(GetProcessHeap(),0,dwLen*sizeof(TCHAR));
	GetLogicalDriveStrings(dwLen,lpDriveStrings);

	bool bFind = false;
	CString strPathName;

	LPTSTR pszName = lpDriveStrings;    
	while ( *pszName )
	{
		if (DRIVE_CDROM == GetDriveType((pszName)))
		{
			CString strTmp = pszName;
			strPathName = strTmp + _T("NexTransmitter.exe");
			if (PathFileExists(strPathName) )
			{
				bFind = true;
				break;
			}
		}
		pszName+=lstrlen((pszName))+1;
	}
	HeapFree(GetProcessHeap(), 0, lpDriveStrings); // 使用完毕后释放堆

	//判断touch.exe是否已经运行,未运行则打开
	if (bFind)
	{
		BOOL bRunning = TRUE;
		if (!CProgress::OpenProgress(strPathName))
		{
			bRunning = FALSE;
			WriteLog("OpenProgress:启动NexTransmitter.exe失败!\r\n");
		}
		
		//处理touch未运行异常情况
		if ( CProgress::IsProgressRunning(_T("touch.exe")) )
		{
			if ( m_bCheckTouchTimerRun )
			{
				KillTimer(CheckTouchTimerId);
				m_bCheckTouchTimerRun = false;
				m_nFailCount = 0;	
			}
			
			return true;
		}
		else
		{
			bRunning = FALSE;
		}

		if ( !bRunning )
		{
			if ( m_bTimerRun )
			{
				KillTimer(UdiskExistTimerId);
				m_bTimerRun = false;
			}
				
			if ( m_bCheckTouchTimerRun )
			{
				m_nFailCount++;
			}
			else
			{
				SetTimer(CheckTouchTimerId, 1000, NULL);//检测touch的定时器
				m_bCheckTouchTimerRun = true;
				m_nFailCount = 0;
			}			

			if ( 3 == m_nFailCount )
			{
				KillTimer(CheckTouchTimerId);
				m_bCheckTouchTimerRun = false;
				m_nFailCount = 0;

				//这里删除一个文件，重插拔或重启PC后重新运行安装包发现文件不全让其重新安装
				CString strTmp = m_strCurDir + _T("ospdll.dll");
				DeleteFile( strTmp );

				::MessageBox(NULL,_T("无线投屏软件启动失败,请重新插拔投屏器或重启计算机!"), _T("tservice"), MB_OK | MB_ICONWARNING | MB_SYSTEMMODAL );
			}			
		}		
	}
	//else
	//{
	//	if ( !m_bTimerRun )
	//	{
	//		SetTimer(UdiskExistTimerId, 1000, NULL);//重新启用定时器检测
	//		m_bTimerRun = true;
	//		WriteLog("OpenProgress:重新启用定时器!\r\n");
	//	}
	//}

	return bFind;
}

BEGIN_MESSAGE_MAP(CtserviceDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_TIMER()
	ON_WM_QUERYDRAGICON()
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// CtserviceDlg 消息处理程序

BOOL CtserviceDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	MoveWindow( -1, -1, 1, 1 );
	SetWindowText( _T("tservice") );
	SetWindowLong(m_hWnd,GWL_EXSTYLE,WS_EX_TOOLWINDOW);//dyy 2013-9-13 loadtpad不在任务栏显示
	
	//创建目录
	m_strCurDir = GetModuleFullPath();
	CString strLogoPath = m_strCurDir + TP_TEMPFILE_PATH;
	if(!PathFileExists(strLogoPath))
	{
		CreateDirectory(strLogoPath, NULL);
	}
	m_strLogFile = strLogoPath + LOG_FILE;
	WriteLog("-----------tservice run-----------\r\n");

	RegisterNotification(this->GetSafeHwnd(), &m_hDevNotiy);
	if (CProgress::IsProgressRunning(_T("touch.exe")))
	{
		return TRUE;
	}

	SetTimer(UdiskExistTimerId, 2000, NULL);//2s检测U盘是否开机前插入
	m_bTimerRun = true;

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CtserviceDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CtserviceDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CtserviceDlg::OnDestroy()
{
	if (m_hDevNotiy)
	{
		UnRegisterNotification(&m_hDevNotiy);
		m_hDevNotiy = NULL;
	}

	DeleteCriticalSection(&m_hSem); 

	CDialogEx::OnDestroy();
}

bool CtserviceDlg::RegisterNotification( HWND hWnd, HDEVNOTIFY* diNotifyHandle )
{
	bool bRst = false;

	DEV_BROADCAST_DEVICEINTERFACE broadcastInterface;

	broadcastInterface.dbcc_size = sizeof(DEV_BROADCAST_DEVICEINTERFACE);
	broadcastInterface.dbcc_devicetype = DBT_DEVTYP_DEVICEINTERFACE;
	HidD_GetHidGuid(&broadcastInterface.dbcc_classguid);

	*diNotifyHandle = RegisterDeviceNotification(hWnd, &broadcastInterface, DEVICE_NOTIFY_WINDOW_HANDLE);

	if (diNotifyHandle)
	{
		bRst = true;
	}

	return bRst;
}

bool CtserviceDlg::UnRegisterNotification( HDEVNOTIFY* diNotifyHandle )
{
	bool bRst = false;
	if(UnregisterDeviceNotification(*diNotifyHandle))
	{
		bRst = true;
	}

	return bRst;
}

void CtserviceDlg::WriteLog(  char * format,... )
{
	//内容加时间
	SYSTEMTIME st;
	GetLocalTime(&st);
	char achTemp[MAX_PATH] = {0};
	sprintf(achTemp, "[%d-%d-%d %d:%d:%d]", st.wYear, st.wMonth, st.wDay, st.wHour, st.wMinute, st.wSecond);

	va_list arg_ptr;  
	char szBuffer[BUF_SIZE] = { 0 };

	va_start(arg_ptr, format);  

	_vsnprintf ( szBuffer, sizeof (szBuffer) / sizeof (TCHAR),format, arg_ptr) ; 

	va_end(arg_ptr); 

	int n = strlen(szBuffer);

	szBuffer[n] = '\0';

	string strTmp = achTemp;
	strTmp += szBuffer;

	//写文件部分
	EnterCriticalSection(&m_hSem);
	CFile cfile;

	//打开
	if (!PathFileExists(m_strLogFile))
	{
		BOOL bFlag = cfile.Open(m_strLogFile, CFile::modeCreate | CFile::modeWrite);
		if (!bFlag)
		{
			return;
		}
	}
	else
	{
		CFileStatus fileStaus;
		if (CFile::GetStatus(m_strLogFile, fileStaus))  
		{  
			UINT nOpenFlag = 0;
			if (fileStaus.m_size > LOG_SIZE)
			{
				nOpenFlag = CFile::modeCreate | CFile::modeWrite;
			}
			else
			{
				nOpenFlag = CFile::modeCreate | CFile::modeWrite | CFile::modeNoTruncate;
			}

			BOOL bFlag = cfile.Open(m_strLogFile, nOpenFlag);
			if (!bFlag)
			{
				return;
			}
		}  
	}

	//
	if (cfile.m_hFile != CFile::hFileNull)
	{
		cfile.SeekToEnd();
		cfile.Write(strTmp.c_str(), strTmp.size());
		cfile.Close();
	}

	LeaveCriticalSection(&m_hSem);
}

CString CtserviceDlg::GetModuleFullPath( void )
{
	TCHAR achDllName[32768] = _T("");
	CString csPath = _T("");

	//AfxGetInstanceHandle()可能获取失败
	// 	GetModuleFileName( AfxGetInstanceHandle(), achDllName, MAX_PATH);

	MEMORY_BASIC_INFORMATION mbi;   
	static int dummy; 
	UINT dwLength = sizeof(mbi); 
	if ( dwLength == VirtualQuery( &dummy, &mbi, dwLength ) )
	{
		GetModuleFileName( reinterpret_cast<HMODULE>(mbi.AllocationBase), achDllName, _countof(achDllName) ); 
		size_t nBuffLen = GetLongPathName( achDllName, 0, 0 );
		if ( nBuffLen == _tcslen( achDllName ) )
		{
			csPath = achDllName;
		}
		else
		{
			TCHAR* pChar = new TCHAR[nBuffLen + 1];
			ZeroMemory( pChar, sizeof(TCHAR) * ( nBuffLen + 1 ) );
			GetLongPathName( achDllName, pChar, nBuffLen );
			csPath = pChar;
			delete[] pChar;
		}		
	}

	csPath = csPath.Left( csPath.ReverseFind(_T('\\')) + 1 );

	return csPath;
}

void CtserviceDlg::RebootSystem()
{
	//说明:先提升权限，才能进行重启操作
	HANDLE hToken;
	TOKEN_PRIVILEGES tkp;
	// Get a token for this process.
	if (!OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &hToken))
	{
		return;
	}
	// Get the LUID for the shutdown privilege.
	LookupPrivilegeValue(NULL, SE_SHUTDOWN_NAME,
		&tkp.Privileges[0].Luid);
	tkp.PrivilegeCount = 1;  // one privilege to set
	tkp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
	// Get the shutdown privilege for this process.
	AdjustTokenPrivileges(hToken, FALSE, &tkp,  sizeof(TOKEN_PRIVILEGES), (PTOKEN_PRIVILEGES)NULL, NULL);
	if (GetLastError() != ERROR_SUCCESS)
	{
		return;
	}
	// Shut down the system and force all applications to close.
	ExitWindowsEx(EWX_REBOOT | EWX_FORCE, 0); 
}

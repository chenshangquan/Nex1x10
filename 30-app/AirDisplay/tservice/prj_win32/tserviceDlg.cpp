
// tserviceDlg.cpp : ʵ���ļ�
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


// CtserviceDlg �Ի���
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
	HeapFree(GetProcessHeap(), 0, lpDriveStrings); // ʹ����Ϻ��ͷŶ�

	//�ж�touch.exe�Ƿ��Ѿ�����,δ�������
	if (bFind)
	{
		BOOL bRunning = TRUE;
		if (!CProgress::OpenProgress(strPathName))
		{
			bRunning = FALSE;
			WriteLog("OpenProgress:����NexTransmitter.exeʧ��!\r\n");
		}
		
		//����touchδ�����쳣���
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
				SetTimer(CheckTouchTimerId, 1000, NULL);//���touch�Ķ�ʱ��
				m_bCheckTouchTimerRun = true;
				m_nFailCount = 0;
			}			

			if ( 3 == m_nFailCount )
			{
				KillTimer(CheckTouchTimerId);
				m_bCheckTouchTimerRun = false;
				m_nFailCount = 0;

				//����ɾ��һ���ļ����ز�λ�����PC���������а�װ�������ļ���ȫ�������°�װ
				CString strTmp = m_strCurDir + _T("ospdll.dll");
				DeleteFile( strTmp );

				::MessageBox(NULL,_T("����Ͷ���������ʧ��,�����²��Ͷ���������������!"), _T("tservice"), MB_OK | MB_ICONWARNING | MB_SYSTEMMODAL );
			}			
		}		
	}
	//else
	//{
	//	if ( !m_bTimerRun )
	//	{
	//		SetTimer(UdiskExistTimerId, 1000, NULL);//�������ö�ʱ�����
	//		m_bTimerRun = true;
	//		WriteLog("OpenProgress:�������ö�ʱ��!\r\n");
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


// CtserviceDlg ��Ϣ�������

BOOL CtserviceDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	MoveWindow( -1, -1, 1, 1 );
	SetWindowText( _T("tservice") );
	SetWindowLong(m_hWnd,GWL_EXSTYLE,WS_EX_TOOLWINDOW);//dyy 2013-9-13 loadtpad������������ʾ
	
	//����Ŀ¼
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

	SetTimer(UdiskExistTimerId, 2000, NULL);//2s���U���Ƿ񿪻�ǰ����
	m_bTimerRun = true;

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CtserviceDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
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
	//���ݼ�ʱ��
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

	//д�ļ�����
	EnterCriticalSection(&m_hSem);
	CFile cfile;

	//��
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

	//AfxGetInstanceHandle()���ܻ�ȡʧ��
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
	//˵��:������Ȩ�ޣ����ܽ�����������
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

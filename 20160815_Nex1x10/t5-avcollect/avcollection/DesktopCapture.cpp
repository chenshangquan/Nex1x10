// DesktopCapture.cpp : Defines the desktop capture.
//

#include "stdafx.h"
#include "DesktopCapture.h"

#include <limits.h>
#include <malloc.h>
#include <mmsystem.h>
#include <stdio.h>
#include "common.h"
#include <time.h>
#include <io.h>

#pragma comment(lib, "winmm")  //lib file
#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "dxgi.lib")
#pragma warning(disable: 4996)

//Test param
int g_dwIndex=0;

//��ӡ����
bool g_bPrtSwitchOn = false;
//�Ƿ�win8�Ժ�Ĳ���ϵͳ
bool g_bIsWin8OrLater = false;
//ץ����ʽ��win7��ǰΪGDI��ʽ��win8�Ժ�ΪDXGI��ʽ
EmGrabMode g_emGrabMode = MODE_GDI;
//ץ��Ĭ���ڴ���뷽ʽ��GDIΪ4�ֽڶ��룬DXGIΪ16�ֽڶ���
bool g_bAlign4Bytes = true;
//DXGIץ�������״̬
TMouseStatus g_tMouseStatus;

#define AVPROBE_SCORE_MAX       100 ///< maximum score
#define AVPROBE_SCORE_RETRY (AVPROBE_SCORE_MAX/4)
#define AVPROBE_SCORE_STREAM_RETRY (AVPROBE_SCORE_MAX/4-1)

#define MESSAGE_POST_TO_UI   WM_USER+1000

//���Ա�־
bool g_bIsBMP;

unsigned char*g_pDesktopYuvBuf=NULL;
unsigned char*g_pRetDesktopYuvBuf=NULL;


#define REGION_WND_BORDER 3

TDisplayInfo g_tdispInfo;

int g_nSelectScreenIndex;

gdigrab g_gdiInfo;
void *g_pvPreProcHandle=NULL;
	

TImageResizerParam g_tPreResize;


AVFormatContext g_avFormatatContentx;
HANDLE          g_hTimerReady;
//UINT            g_uTimerID;
AVPacket        g_avPacket;
//UINT            g_uCallTimerID;
int64_t         g_nCpuPerial;
int             g_nTimeCapture;

int64_t         g_nLastCpuPerial;

//�����ã���һ��ˢ,�����к���������
HBRUSH         g_sBrush;


#define   Max_Screen_Width        7680
#define   Max_Screen_Heigth       4320

#define   Max_TempCharLength      100
#define   Align_4Byte               4
#define   Align_8Byte               8
#define   Align_16Byte              16
#define   Max_LogFileLength      1024*1024*5
#define   Max_LogNameLength      30
#define   CAPTURE_TIMEOUT        25

#define   Temp_Log_File         _T("c:\\err.log")
CSimpleLock			g_csLog;

bool     g_bIsGetDisplay;//�����ظ���ȡ��Ļ
//=============================
/*=============================================================================
������		 DisplayProc
����		�� ��ʾ����hook����Ϣ����
�㷨ʵ��	������ѡ�
����ȫ�ֱ�����
�������˵������
����ֵ˵���� LRESULT������
=============================================================================*/
HHOOK           g_DisplayHook = NULL;
bool            g_bScreenChange;

extern "C" __declspec(dllexport)LRESULT CALLBACK DisplayProc(
	int code,       // hook code
	WPARAM wParam,  // 
	LPARAM lParam   // message information
)
{
	PCWPSTRUCT pMsg = (PCWPSTRUCT)lParam;

	if (pMsg)
	{
		switch (pMsg->message)
		{
		case WM_DISPLAYCHANGE:
		{
			//��Ļ�����仯�����м��
			g_bScreenChange = true;
			
			break;
		}
		}
	}

	return CallNextHookEx(g_DisplayHook, code, wParam, lParam);
}

/*=============================================================================
������		 InstallHookEv
����		�� ��װ���Ӻ���
�㷨ʵ��	������ѡ�
����ȫ�ֱ�����
�������˵������
����ֵ˵���� ��
=============================================================================*/
VOID __stdcall InstallHookEv()
{

	g_DisplayHook = SetWindowsHookEx(WH_CALLWNDPROC, (HOOKPROC)DisplayProc, NULL, ::GetCurrentThreadId());// theApp.m_hInstance, 0);
}

VOID __stdcall UninstallHookEv()
{
	UnhookWindowsHookEx(g_DisplayHook);

}

/*=============================================================================
������		 IsValidFileName
����		���ж��Ƿ�����Ч���ַ�
�㷨ʵ��	������ѡ�
����ȫ�ֱ�����lpszName�ļ�·��
����ֵ˵����  �Ƿ���Ч
=============================================================================*/
BOOL IsValidFileName(char* lpszName)
{
	if (NULL == lpszName)
	{
		return FALSE;
	}
	char chInvalid[Max_TempCharLength] = { 0 };
	sprintf_s(chInvalid, Max_TempCharLength, "\"*<>?|");

	LPTSTR lpsz = strpbrk(lpszName, chInvalid);
	if (lpsz == NULL)
	{
		return TRUE;
	}
	return FALSE;
}

/*=============================================================================
������		 IsValidFilePath
����		���ж�·���Ƿ���Ч
�㷨ʵ��	������ѡ�
����ȫ�ֱ�����lpszFilePath�ļ�·��
����ֵ˵����  �Ƿ���Ч
=============================================================================*/
BOOL IsValidFilePath(char* lpszFilePath)
{
	bool bRet = false;
	if (NULL == lpszFilePath)
	{
		return bRet;
	}
	int length = strlen(lpszFilePath);
	if (length <= 2)
	{
		return bRet;
	}
	DWORD dwResult = GetFileAttributes(lpszFilePath);
	if (INVALID_FILE_ATTRIBUTES == dwResult)
	{
		bRet = IsValidFileName(lpszFilePath);
	}
	else
	{
		bRet = true;
	}
	return bRet;
}


/*=============================================================================
������		 WriteInvalidPathToLog
����		����־����
�㷨ʵ��	������ѡ�
����ȫ�ֱ�������
�������˵����pLog��Ҫ��¼����־�����ݣ�nLenд�����ݵĳ���
����ֵ˵����
=============================================================================*/
void WriteInvalidPathToLog(char*pLog, int nLen)
{
	if (pLog == NULL)
	{
		return;
	}


	FILE* fileLog = NULL;
	char chFile[MAX_PATH+1] = { 0 };
	sprintf_s(chFile, Temp_Log_File);
	errno_t terr = fopen_s(&fileLog, chFile, "a+");
	if (NOERROR != terr)
	{
		return;
	}

	if (fileLog != NULL)
	{
		SYSTEMTIME sys;
		GetLocalTime(&sys);

		char stTime[1024] = { 0 };
		if (nLen < 990)
		{
			sprintf_s(stTime, "%4d-%02d-%02d %02d:%02d:%02d   %s", sys.wYear, sys.wMonth, sys.wDay, sys.wHour, sys.wMinute, sys.wSecond, pLog);
			fwrite(stTime, 1, strlen(stTime), fileLog);
		}
		else
		{
			sprintf_s(stTime, "%4d-%02d-%02d %02d:%02d:%02d   ", sys.wYear, sys.wMonth, sys.wDay, sys.wHour, sys.wMinute, sys.wSecond);
			fwrite(stTime, 1, strlen(stTime), fileLog);
			fwrite(pLog, 1, strnlen_s(stTime,1024), fileLog);
		}

		fclose(fileLog);
		fileLog = NULL;
	}
}

/*=============================================================================
������		 GetCurrentDir
����		����ȡ��ǰ·������
�㷨ʵ��	������ѡ�
����ȫ�ֱ�������
�������˵����char *chPath���ص�ǰ·��
����ֵ˵����  �Ƿ���������
=============================================================================*/
bool GetCurrentDir(char *chPath)
{
	if (!chPath)
	{
		return false;
	}
	char buffer[MAX_PATH + 1]={0};
	::GetModuleFileName(NULL, buffer, MAX_PATH);
	for (int i = MAX_PATH - 1;i >= 0;i--)
	{
		if (*(buffer + i) != '\\')
		{
			*(buffer + i) = 0;
		}
		else {
			break;
		}
	}

	//������һ��
	int nlen = strlen(buffer);
	if (buffer[nlen - 1] == '\\')
	{
		buffer[nlen - 1] = '\0';
	}
	sprintf_s(chPath, MAX_PATH+1,"%s", buffer);
	return true;
}

/*=============================================================================
������		 CompareFileCreationTime
����		���Ƚ��ļ��޸�ʱ�亯��
�㷨ʵ��	������ѡ�
����ȫ�ֱ�������
�������˵����pchFn1��־�ļ�1��pchFn2��־�ļ�2
����ֵ˵����1=�ļ�1���ļ�2��,2 �ļ�1���ļ�2��,0-ʱ����ͬ,-1-����
=============================================================================*/
int CompareFileCreationTime(const char* pchFn1, const char* pchFn2)
{
	if (NULL == pchFn1 || NULL == pchFn2)
	{
		return -1;
	}
	

	//���ļ�
	HANDLE hFile1 = ::CreateFile(pchFn1, FILE_READ_ATTRIBUTES, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	HANDLE hFile2 = ::CreateFile(pchFn2, FILE_READ_ATTRIBUTES, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (INVALID_HANDLE_VALUE == hFile1 || INVALID_HANDLE_VALUE == hFile2)
	{
		if (INVALID_HANDLE_VALUE != hFile1)
		{
			::CloseHandle(hFile1);
			hFile1 = NULL;
		}
		if (INVALID_HANDLE_VALUE != hFile2)
		{
			::CloseHandle(hFile2);
			hFile2 = NULL;
		}
		return -1;
	}

	//��ȡ�ļ�ʱ��
	FILETIME ft1, ft2, ftAcc12, ft13, ftAcc22, ft23;
	BOOL bSuc = ::GetFileTime(hFile1, &ft1, &ftAcc12, &ft13);
	bSuc &= ::GetFileTime(hFile2, &ft2, &ftAcc22, &ft23);
	::CloseHandle(hFile1);
	::CloseHandle(hFile2);
	if (FALSE == bSuc)
	{
		return -1;
	}

	//�ȱȽϸ�λ
	if (ftAcc12.dwHighDateTime != ftAcc22.dwHighDateTime)
	{
		return (ftAcc12.dwHighDateTime > ftAcc22.dwHighDateTime ? 2 : 1);
	}
	//�ٱȽϵ�λ
	if (ftAcc12.dwLowDateTime == ftAcc22.dwLowDateTime)
	{
		return 0;
	}
	else
	{
		return (ftAcc12.dwLowDateTime > ftAcc22.dwLowDateTime ? 2 : 1);
	}
}

/*=============================================================================
������		 GetFileSize
����		����ȡ��־�ļ��ֽ���
�㷨ʵ��	������ѡ�
����ȫ�ֱ�������
�������˵����pchFile��־�ļ�
����ֵ˵����
=============================================================================*/
long GetFileSize(char* pchFile)
{
	long lnRet=0;
	FILE* sfile;
	if(fopen_s(&sfile,pchFile, "rb")!=0)
	{
		return lnRet;
	}
	
	if(sfile!=NULL)
	{
		fseek(sfile, 0, SEEK_SET);
		fseek(sfile, 0, SEEK_END);
		lnRet = ftell(sfile);

		/*lnRet = filelength(fileno(sfile));  */
		
		fclose(sfile);  
	}  
	return lnRet;
}

/*=============================================================================
������		 GetLogFileName
����		����ȡ��Ҫд���Ǹ���־�ļ�
�㷨ʵ��	������ѡ�
����ȫ�ֱ�������
�������˵����pchFile��־�ļ�
����ֵ˵����false��ʾ����Ҫ����true-��ʾ��Ҫ����
=============================================================================*/
bool GetLogFileName(char* pchFile, int nLen)
{
	bool bret = false;
	if (pchFile == NULL)
	{
		return bret;
	}
	char chFile[MAX_PATH+ Max_LogNameLength] = { 0 };
	char buffer[MAX_PATH + 1] = { 0 };
	GetCurrentDir(buffer);

	if(sprintf_s(chFile,"%s\\log\\avCollectoin.log", buffer)<=0)
	{
		return bret;
	}

	//FILE* sfile;
	//fopen_s(&sfile,chFile, "rb"); 
	long orgsize =GetFileSize(chFile);
	
	
	if (orgsize > Max_LogFileLength)
	{
		//����5M�������ļ�Max_TempCharLength
		char chFile1[MAX_PATH+ Max_LogNameLength] = { 0 };
		sprintf_s(chFile1, "%s\\log\\avCollectoin1.log", buffer);
		long destsize =GetFileSize(chFile1);
		if (destsize > Max_LogFileLength)
		{
			strncpy_s(pchFile, nLen, chFile, MAX_PATH+ Max_LogNameLength);
			bret = true;
			if (CompareFileCreationTime(chFile, chFile1) == 1)
			{
				strncpy_s(pchFile, nLen, chFile1, MAX_PATH+ Max_LogNameLength);
			}
		}//����������
		else
		{
			strncpy_s(pchFile, nLen, chFile1, MAX_PATH+ Max_LogNameLength);
		}
	}
	else
	{
		strncpy_s(pchFile, nLen, chFile, MAX_PATH+ Max_LogNameLength);
	}

	if (IsValidFilePath(pchFile) == false)
	{
		WriteInvalidPathToLog(pchFile, nLen);
		return false;
	}

	return bret;
}

/*=============================================================================
������		 WriteToLog
����		����־����
�㷨ʵ��	������ѡ�
����ȫ�ֱ�������
�������˵����pLog��Ҫ��¼����־�����ݣ�nLenд�����ݵĳ���
����ֵ˵���� 
=============================================================================*/
void WriteToLogTest(char*pLog,int nLen)
{
	CAutoLock  csLock(&g_csLog);
	if (pLog == NULL)
	{
		return;
	}
	FILE* fileLog=NULL;
	char chFile[MAX_PATH+ Max_LogNameLength+1]={0};

	char buffer[MAX_PATH + 1] = { 0 };
	GetCurrentDir(buffer);

	sprintf_s(chFile,"%s\\log\\avCollectoin-t.log", buffer);

	if(fopen_s(&fileLog, chFile, "a+")!=0)
	{
	    return;
	}
	
		
	if(fileLog!=NULL)
	{
		SYSTEMTIME sys;
		GetLocalTime(&sys);
		

		char stTime[Max_TempCharLength]={0};
		sprintf_s(stTime, "%4d-%02d-%02d %02d:%02d:%02d   ", sys.wYear, sys.wMonth, sys.wDay, sys.wHour, sys.wMinute, sys.wSecond);
		fwrite(stTime, 1, strlen(stTime), fileLog);
		int nLen = strnlen_s(pLog, MAX_PATH);
		fwrite(pLog, 1, nLen, fileLog);
	
		fclose(fileLog);
		fileLog=NULL;
	}
}

/*=============================================================================
������		 WriteToLog
����		����־����
�㷨ʵ��	������ѡ�
����ȫ�ֱ�������
�������˵����pLog��Ҫ��¼����־�����ݣ�nLenд�����ݵĳ���
����ֵ˵���� 
=============================================================================*/
void WriteToLog(char*pLog,int nLen)
{
	CAutoLock  csLock(&g_csLog);
	if (pLog == NULL)
	{
		return;
	}
	FILE* fileLog=NULL;
	char chFile[MAX_PATH + Max_LogNameLength+1] = { 0 };

	//char buffer[MAX_PATH + 1] = {0};
	//GetCurrentDir(buffer);

	if (GetLogFileName(chFile, MAX_PATH + Max_LogNameLength +1))
	{
		fopen_s(&fileLog, chFile, "w+");
	}
	else
	{
		fopen_s(&fileLog, chFile, "a+");
	}
	
		
	//fopen_s(&fileLog,chFile, "a+");// "d:\\testXGA0.bmp", "wb+");
	if(fileLog!=NULL)
	{
		SYSTEMTIME sys;
		GetLocalTime(&sys);
		
		//printf("Current time is: %s\n", stTmp);
		char stTime[Max_TempCharLength] = { 0 };
		sprintf_s(stTime, "%4d-%02d-%02d %02d:%02d:%02d   ", sys.wYear, sys.wMonth, sys.wDay, sys.wHour, sys.wMinute, sys.wSecond);
		fwrite(stTime, 1, strlen(stTime), fileLog);
		int nLen = strnlen_s(pLog, MAX_PATH);
		fwrite(pLog, 1, nLen, fileLog);
		
		//fwrite(pLog,1,nLen,fileLog);
		fclose(fileLog);
		fileLog=NULL;
	}
	else
	{
		//WriteToLogTest(pLog, nLen);
	}
}

/*=============================================================================
������		 ErrorLog
����		���ɼ��Ĵ�����־
�㷨ʵ��	������ѡ�
����ȫ�ֱ�����
����ֵ˵����  �Ƿ�ɹ�
=============================================================================*/
BOOL ErrorLog(int nErr)
{
	char ch[Max_TempCharLength] = { 0 };
	switch (nErr)
	{
	//case 1://- ֹͣ
	//	break;
	case 2://- �ɼ�����3 - �ɼ��ֱ��ʲ�һ�£�4ת������5 - data error, 11 - �ֱ��ʱ仯��12���ݲ���
		sprintf_s(ch, "CaptureScreenû�л�ȡ������\n");
		break;
	case 3:// - �ɼ��ֱ��ʲ�һ�£�4ת������5 - data error, 11 - �ֱ��ʱ仯��12���ݲ���
		sprintf_s(ch, "�ɼ��ֱ��ʷ����仯\n");
		break;
	case 4://ת������5 - data error, 11 - �ֱ��ʱ仯��12���ݲ���
		sprintf_s(ch, "ת����YUV���ݷ�������\n");
		break;
	case 5:// - data error, 11 - �ֱ��ʱ仯��12���ݲ���
		sprintf_s(ch, "try��ȡ������\n");
		break;
	case 6:
		sprintf_s(ch, "û�л�ȡ��Ļ����\n");
		break;
	case 7:
		sprintf_s(ch, "�ɼ��ľ��Ϊ��\n");
		break;
	case 11:
		sprintf_s(ch, "�жϷֱ��ʷ����仯\n");
		break;
	case 12:
		sprintf_s(ch, "���ݵĲ������п�ָ��\n");
		break;
	case 13:
		sprintf_s(ch, "ץ����ʽ�����仯\n");
		break;
	case 20://do nothing
		return FALSE;
	default:
		return TRUE;
	}

	//
	WriteToLog(ch, strnlen_s(ch, Max_TempCharLength));
	return FALSE;
}

/*=============================================================================
������		 FindOrCreateDirectory
����		����ȡ��ǰ·���Ƿ���ڣ��������Զ�����
�㷨ʵ��	������ѡ�
����ȫ�ֱ�������
�������˵����char *pszPath����·��
����ֵ˵����  �Ƿ���������
=============================================================================*/
bool FindOrCreateDirectory(const char* pszPath)
{
	if (pszPath == NULL)
	{
		return false;
	}
	if (PathFileExists(pszPath))
	{
		return true;
	}
	if (!::CreateDirectory(pszPath, NULL))
	{
		/*char szDir[MAX_PATH];
		sprintf_s(szDir, sizeof(szDir), "����Ŀ¼[%s]ʧ��,�Ѿ����ڻ�Ȩ�޲���\r\n", pszPath);
		WriteToLog(szDir, strnlen_s(szDir, MAX_PATH));*/
		return false;
	}

	return true;
}


/*=============================================================================
������		 Align4Bytes
����		�� �Ƿ����4�ֽڶ��봦��
�㷨ʵ��	������ѡ�
����ȫ�ֱ�����
�������˵������
����ֵ˵���� �Ƿ���Ҫ����
=============================================================================*/
bool Align4Bytes(int*pnWidth,int*pnHeight)
{
	if (pnWidth == NULL)
	{
		return false;
	}
	bool bResult = false;
	int nWidth = *pnWidth;

	int nAlignType = Align_16Byte;
	if (g_bAlign4Bytes)
	{
		nAlignType = Align_4Byte;
	}

	double dNum = nWidth % nAlignType;
	if (dNum != 0)
	{
		//*pnWidth = (int)nWidth / 16 * 16;
		int nTmp = nWidth / nAlignType;
		if (nWidth % nAlignType > 0)
		{
			nTmp = nTmp + 1;
		}
		*pnWidth = (int)nTmp * nAlignType;
		bResult = true;
	}
	
	return bResult;
}

/*=============================================================================
������		 gdigrab_region_wnd_proc
����		�����Ӻ���
�㷨ʵ��	������ѡ�
����ȫ�ֱ�������
�������˵����HWND���, UINT��Ϣ, WPARAM , LPARAM ��������
����ֵ˵���� 
=============================================================================*/
LRESULT CALLBACK gdigrab_region_wnd_proc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
    PAINTSTRUCT ps;
    HDC hdc;
    RECT rect;

    switch (msg) {
    case WM_PAINT:
        hdc = BeginPaint(hwnd, &ps);

        GetClientRect(hwnd, &rect);
        FrameRect(hdc, &rect, (HBRUSH)GetStockObject(BLACK_BRUSH));

        rect.left++; rect.top++; rect.right--; rect.bottom--;
        FrameRect(hdc, &rect, (HBRUSH)GetStockObject(WHITE_BRUSH));

        rect.left++; rect.top++; rect.right--; rect.bottom--;
        FrameRect(hdc, &rect, (HBRUSH)GetStockObject(BLACK_BRUSH));

        EndPaint(hwnd, &ps);
        break;
    default:
        return DefWindowProc(hwnd, msg, wparam, lparam);
    }
    return 0;
}

/**
 * Initialize the region outline window.
 *
 */
static int gdigrab_region_wnd_init(AVFormatContext *s1, struct gdigrab *gdigrab)
{
	if ( gdigrab == NULL)
	{
		return 1;
	}

    HWND hwnd;
    RECT rect = gdigrab->clip_rect;
    HRGN region = NULL;
    HRGN region_interior = NULL;

    DWORD style = WS_POPUP | WS_VISIBLE;
    DWORD ex = WS_EX_TOOLWINDOW | WS_EX_TOPMOST | WS_EX_TRANSPARENT;

    rect.left -= REGION_WND_BORDER; rect.top -= REGION_WND_BORDER;
    rect.right += REGION_WND_BORDER; rect.bottom += REGION_WND_BORDER;

    AdjustWindowRectEx(&rect, style, FALSE, ex);

    // Create a window with no owner; use WC_DIALOG instead of writing a custom
    // window class
    hwnd = CreateWindowEx(ex, WC_DIALOG, NULL, style, rect.left, rect.top,
            rect.right - rect.left, rect.bottom - rect.top,
            NULL, NULL, NULL, NULL);
    if (!hwnd) {
       // WIN32_API_ERROR("Could not create region display window");
		char chLog[Max_TempCharLength] = { 0 };
		DWORD dwError = GetLastError();

		sprintf_s(chLog, Max_TempCharLength,"CreateWindowEx have GetLastError= %d in function window init\n", dwError);
		WriteToLog(chLog, Max_TempCharLength);
        goto error;
    }

    // Set the window shape to only include the border area
    GetClientRect(hwnd, &rect);
    region = CreateRectRgn(0, 0,
            rect.right - rect.left, rect.bottom - rect.top);
    region_interior = CreateRectRgn(REGION_WND_BORDER, REGION_WND_BORDER,
            rect.right - rect.left - REGION_WND_BORDER,
            rect.bottom - rect.top - REGION_WND_BORDER);
    CombineRgn(region, region, region_interior, RGN_DIFF);
    if (!SetWindowRgn(hwnd, region, FALSE)) {
        //WIN32_API_ERROR("Could not set window region");
		char chLog[Max_TempCharLength] = { 0 };
		DWORD dwError = GetLastError();

		sprintf_s(chLog, "SetWindowRgn have GetLastError %d in function window init\n", dwError);
		WriteToLog(chLog, Max_TempCharLength);
        goto error;
    }
    // The "region" memory is now owned by the window
    region = NULL;
    DeleteObject(region_interior);

    SetWindowLongPtr(hwnd, GWLP_WNDPROC, (LONG_PTR) gdigrab_region_wnd_proc);

    ShowWindow(hwnd, SW_SHOW);

    gdigrab->region_hwnd = hwnd;

    return 0;

error:
    if (region)
        DeleteObject(region);
    if (region_interior)
        DeleteObject(region_interior);
    if (hwnd)
        DestroyWindow(hwnd);
    return 1;
}

    /** 
     * Initializes the gdi grab device demuxer (public device demuxer API). 
     */  
    static int  gdigrab_read_header(AVFormatContext *s1)  
    {  
		if (s1 == NULL)
		{
			return 0;
		}
        struct gdigrab *gdigrab1 = (gdigrab *)s1->priv_data;  
		if (gdigrab1 == NULL)
		{
			return 0;
		}
        //���ھ��  
		HWND hwnd=NULL;  
        HDC source_hdc = NULL;  
        HDC dest_hdc   = NULL;  
        BITMAPINFO bmi;  
        HBITMAP hbmp   = NULL;  
        void *buffer   = NULL;  
      
        const char *filename = s1->filename;  
		if (filename == NULL)
		{
			return 0;
		}
        const char *name     = NULL;  
        //AVStream   *st       = NULL;  
      
        int bpp=24;  
		if (g_emGrabMode == MODE_DXGI)
		{
			bpp = 32;
		}

        RECT virtual_rect;  
        //���ڵ�λ�úʹ�С  
        RECT clip_rect;  
        BITMAP bmp;  
        int ret=0;  
        //filenameΪ��������  
        if (!strncmp(filename, "title=", 6)) {  
            name = filename + 6;  
            //���Ҵ��ڵľ��  
            hwnd = FindWindow(NULL, name);  
            if (!hwnd) {  
                goto error;  
            }  
            if (gdigrab1->show_region) {  
               /* av_log(s1, AV_LOG_WARNING,  
                        "Can't show region when grabbing a window.\n");  */
                gdigrab1->show_region = 0;  
            }  
            //filenameΪdesktop  
        } else if (!strcmp(filename, "desktop")) {  
            //���ھ��ΪNULL  
            hwnd = NULL;  
        } else {  
            goto error;  
        }  
		char chMsgtst[Max_TempCharLength] = { 0 };
		int nScrWidth = 0; //GetSystemMetrics(SM_CXSCREEN); 
		int nScrHeight = 0; //GetSystemMetrics(SM_CYSCREEN);

        if (hwnd) {  
            GetClientRect(hwnd, &virtual_rect);  
        } else {  
            //���ھ��ΪNULL��������ȫ��  
			HWND hh=GetDesktopWindow();
			HDC hd = GetDC(hh);

				///////////////////mult display
			if(g_tdispInfo.nDeviceCount<=0)
			{
				GetAllDisplay();
			}

			 int nLft=0;
			 int nTop=0;
			 if(g_nSelectScreenIndex>g_tdispInfo.nDeviceCount)
			 {
				 g_nSelectScreenIndex=0;
			 }
			if(g_nSelectScreenIndex<2)
			{
				nScrWidth  = g_tdispInfo.arydmDevMode[0].dmPelsWidth; 
				nScrHeight =  g_tdispInfo.arydmDevMode[0].dmPelsHeight; //GetSystemMetrics(SM_CYSCREEN); 
				nLft=g_tdispInfo.arydmDevMode[0].dmPosition.x;
				nTop=g_tdispInfo.arydmDevMode[0].dmPosition.y;
			}
			else
			{
				nScrWidth  = g_tdispInfo.arydmDevMode[1].dmPelsWidth; 
				nScrHeight =  g_tdispInfo.arydmDevMode[1].dmPelsHeight; //GetSystemMetrics(SM_CYSCREEN);
				nLft=g_tdispInfo.arydmDevMode[1].dmPosition.x;
				nTop=g_tdispInfo.arydmDevMode[1].dmPosition.y;
			}
		

			if(nScrWidth>Max_Screen_Width)
			{
				nScrWidth= Max_Screen_Width;
			}
			if(nScrHeight>Max_Screen_Heigth)
			{
				nScrHeight= Max_Screen_Heigth;
			}
			if (nScrHeight <= 0 || nScrWidth <= 0)
			{
				/*char chMsg[Max_TempCharLength] = { 0 };
				sprintf_s(chMsg, Max_TempCharLength, "Get desktop rect have error,display count:%d\n", g_tdispInfo.nDeviceCount);
				WriteToLog(chMsg, Max_TempCharLength);*/
			}
		

            virtual_rect.left = nLft;
            virtual_rect.top =nTop;  
            virtual_rect.right = virtual_rect.left +nScrWidth;// GetSystemMetrics(SM_CXVIRTUALSCREEN);  
            virtual_rect.bottom = virtual_rect.top + nScrHeight;//GetSystemMetrics(SM_CYVIRTUALSCREEN);  
        }  
      
        /* If no width or height set, use full screen/window area */  
     
            clip_rect.left = virtual_rect.left;  
            clip_rect.top = virtual_rect.top;  
            clip_rect.right = virtual_rect.right;  
            clip_rect.bottom = virtual_rect.bottom;  

			gdigrab1->width=clip_rect.right-clip_rect.left;
			gdigrab1->height=clip_rect.bottom-clip_rect.top;
    
      
          if (clip_rect.left < virtual_rect.left ||  
                 clip_rect.top < virtual_rect.top ||  
                clip_rect.right > virtual_rect.right ||  
                clip_rect.bottom > virtual_rect.bottom) {  

			sprintf_s(chMsgtst, Max_TempCharLength, "get desktop rect5,right:%d,left:%d,bottom:%d,nTop:%d\n", clip_rect.right, clip_rect.left, clip_rect.bottom, clip_rect.top);
			WriteToLog(chMsgtst, Max_TempCharLength);

			sprintf_s(chMsgtst, Max_TempCharLength, "get desktop virtual_rect,right:%d,keft:%d,bottom:%d,nTop:%d\n", virtual_rect.right, clip_rect.left, clip_rect.bottom, clip_rect.top);
			WriteToLog(chMsgtst, Max_TempCharLength);
                goto error;  
        }  
 
		char chLog[Max_TempCharLength] = { 0 };
        //�õ�ĳ�����ھ����DC   
        source_hdc = GetDC(hwnd);  
        if (!source_hdc) {  
			DWORD dwError = GetLastError();
			sprintf_s(chLog, "Get desktop dc have GetLastError:%d\n", dwError);
			WriteToLog(chLog, Max_TempCharLength);
			
            goto error;  
        }  

      
        if (clip_rect.right - clip_rect.left <= 0 ||  
                clip_rect.bottom - clip_rect.top <= 0 || bpp%8) {  
			
			sprintf_s(chLog, "Fail to get desktop width in function readheader\n");
			WriteToLog(chLog, Max_TempCharLength);
            goto error;  
        }  
        //����һ����ָ���豸���ݵ�HDC  
        dest_hdc = CreateCompatibleDC(source_hdc);  
        if (!dest_hdc) { 
			DWORD dwError = GetLastError();
			
			sprintf_s(chLog, "CreateCompatibleDC have GetLastError %d in function readheader\n", dwError);
			WriteToLog(chLog, Max_TempCharLength);
            goto error;  
        }  
      
		//�ж��Ƿ���4�ֽڶ���
		nScrWidth = clip_rect.right - clip_rect.left;
		Align4Bytes(&nScrWidth,&nScrHeight);


        /* Create a DIB and select it into the dest_hdc */  
        //BMP  
        bmi.bmiHeader.biSize          = sizeof(BITMAPINFOHEADER);  
		bmi.bmiHeader.biWidth         = nScrWidth;//clip_rect.right - clip_rect.left;
		bmi.bmiHeader.biHeight        = nScrHeight;//clip_rect.bottom - clip_rect.top;////-(clip_rect.bottom - clip_rect.top);  
		if (g_emGrabMode == MODE_DXGI)
		{
			bmi.bmiHeader.biHeight = -abs(bmi.bmiHeader.biHeight);
		}
        bmi.bmiHeader.biPlanes        = 1;  
        bmi.bmiHeader.biBitCount      = bpp;  
        bmi.bmiHeader.biCompression   = BI_RGB;  
        bmi.bmiHeader.biSizeImage     = 0;  
        bmi.bmiHeader.biXPelsPerMeter = 0;  
        bmi.bmiHeader.biYPelsPerMeter = 0;  
        bmi.bmiHeader.biClrUsed       = 0;  
        bmi.bmiHeader.biClrImportant  = 0;  
        hbmp = CreateDIBSection(dest_hdc, &bmi, DIB_RGB_COLORS,  
                &buffer, NULL, 0);  
        if (!hbmp) {  
			DWORD dwError = GetLastError();

			sprintf_s(chLog, "CreateDIBSection have GetLastError %d in function readheader\n", dwError);
			WriteToLog(chLog, Max_TempCharLength);
            goto error;  
        }  
      
        if (!SelectObject(dest_hdc, hbmp)) {  
			DWORD dwError = GetLastError();

			sprintf_s(chLog, "SelectObject have GetLastError %d in function readheader\n", dwError);
			WriteToLog(chLog, Max_TempCharLength);
            goto error;  
        }  
      
        /* Get info from the bitmap */  
        GetObject(hbmp, sizeof(BITMAP), &bmp);  
      
		//0302Ĭ���޸ĳ����1920���1080
		gdigrab1->frame_size  = bmp.bmWidthBytes * bmp.bmHeight * bmp.bmPlanes;  

		gdigrab1->header_size = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) ;
      
        gdigrab1->hwnd       = hwnd;  
        gdigrab1->source_hdc = source_hdc;  
        gdigrab1->dest_hdc   = dest_hdc;  
        gdigrab1->hbmp       = hbmp;  
        gdigrab1->bmi        = bmi;  
        gdigrab1->buffer     = buffer;  
        gdigrab1->clip_rect  = clip_rect;  
      
        gdigrab1->cursor_error_printed = 0;  
      
        if (gdigrab1->show_region) {  
            if (gdigrab_region_wnd_init(s1, gdigrab1)) {  
                //ret = AVERROR(EIO);  
				sprintf_s(chLog, "gdigrab_region_wnd_init error\n");
				WriteToLog(chLog, Max_TempCharLength);
                goto error;  
            }  
        }  
      
     
        return 0;  
      
    error:  
        //���������  
        if (source_hdc)  
            ReleaseDC(hwnd, source_hdc);  
        if (dest_hdc)  
            DeleteDC(dest_hdc);  
        if (hbmp)  
            DeleteObject(hbmp);  
        if (source_hdc)  
            DeleteDC(source_hdc);  
        return ret;  
    }  

	/**
 * Process the Windows message queue.
 *
 */
void gdigrab_region_wnd_update(AVFormatContext *s1, struct gdigrab *gdigrab)
{
    HWND hwnd = gdigrab->region_hwnd;
    MSG msg;

    while (PeekMessage(&msg, hwnd, 0, 0, PM_REMOVE)) {
        DispatchMessage(&msg);
    }
}

/**
 * Paints a mouse pointer in a Win32 image.
 *
 */
void paint_mouse_pointer(AVFormatContext *s1, struct gdigrab *gdigrab)
{
    CURSORINFO ci = {0};
	if (gdigrab == NULL)
	{
		return ;
	}
#define CURSOR_ERROR(str)                 \
    if (!gdigrab->cursor_error_printed) {       \
        WIN32_API_ERROR(str);             \
        gdigrab->cursor_error_printed = 1;      \
    }

    ci.cbSize = sizeof(ci);

    if (GetCursorInfo(&ci)) {
        HCURSOR icon = CopyCursor(ci.hCursor);
        ICONINFO info;
        POINT pos;
        RECT clip_rect = gdigrab->clip_rect;
        HWND hwnd = gdigrab->hwnd;
        int vertres = GetDeviceCaps(gdigrab->source_hdc, VERTRES);
        int desktopvertres = GetDeviceCaps(gdigrab->source_hdc, DESKTOPVERTRES);
        info.hbmMask = NULL;
        info.hbmColor = NULL;

        if (ci.flags != CURSOR_SHOWING)
            return;

        if (!icon) {
            /* Use the standard arrow cursor as a fallback.
                */
            icon = CopyCursor(LoadCursor(NULL, IDC_ARROW));
        }

        if (!GetIconInfo(icon, &info)) {
            goto icon_error;
        }

        pos.x = ci.ptScreenPos.x - clip_rect.left - info.xHotspot;
        pos.y = ci.ptScreenPos.y - clip_rect.top - info.yHotspot;

        if (hwnd) {
            RECT rect;

            if (GetWindowRect(hwnd, &rect)) {
                pos.x -= rect.left;
                pos.y -= rect.top;
            } else {
                goto icon_error;
            }
        }

		if(vertres>0 && vertres>0)
		{
			pos.x = pos.x * desktopvertres / vertres;
			pos.y = pos.y * desktopvertres / vertres;

			if (g_emGrabMode == MODE_DXGI)
			{
				if (g_tMouseStatus.bJudgeNextMousePos)
				{
					//�϶�����ʱ����겻�ٻ��ƣ�DXGIץ�����϶�����ʱ�����������Ѻ�����꣩
					if (g_tMouseStatus.LastMousePosition.x != pos.x
						|| g_tMouseStatus.LastMousePosition.y != pos.y)
					{
						g_tMouseStatus.bNextMousePosChanged = true;
						goto icon_error;
					}
				}
			}

			if (pos.x >= 0 && pos.x <= clip_rect.right - clip_rect.left &&
					pos.y >= 0 && pos.y <= clip_rect.bottom - clip_rect.top) {
				if (!DrawIcon(gdigrab->dest_hdc, pos.x, pos.y, icon))
				{
					int i=0;
					i=0;
				}
			}
		}
icon_error:
        if (info.hbmMask)
            DeleteObject(info.hbmMask);
        if (info.hbmColor)
            DeleteObject(info.hbmColor);
        if (icon)
            DestroyCursor(icon);
    } else {
        //CURSOR_ERROR("Couldn't get cursor info");
    }
}

void paint_mouse_pointer(AVFormatContext *s1, struct gdigrab *gdigrab,int nLeft)
{
	CURSORINFO ci = { 0 };
	if (gdigrab == NULL)
	{
		return;
	}
#define CURSOR_ERROR(str)                 \
    if (!gdigrab->cursor_error_printed) {       \
        WIN32_API_ERROR(str);             \
        gdigrab->cursor_error_printed = 1;      \
    }

	ci.cbSize = sizeof(ci);

	if (GetCursorInfo(&ci)) {
		HCURSOR icon = CopyCursor(ci.hCursor);
		ICONINFO info;
		POINT pos;
		RECT clip_rect = gdigrab->clip_rect;
		HWND hwnd = gdigrab->hwnd;
		int vertres = GetDeviceCaps(gdigrab->source_hdc, VERTRES);
		int desktopvertres = GetDeviceCaps(gdigrab->source_hdc, DESKTOPVERTRES);
		info.hbmMask = NULL;
		info.hbmColor = NULL;

		if (ci.flags != CURSOR_SHOWING)
			return;

		if (!icon) {
			/* Use the standard arrow cursor as a fallback.
			*/
			icon = CopyCursor(LoadCursor(NULL, IDC_ARROW));
		}

		if (!GetIconInfo(icon, &info)) {
			goto icon_error;
		}

		pos.x = ci.ptScreenPos.x - clip_rect.left - info.xHotspot;
		pos.y = ci.ptScreenPos.y - clip_rect.top - info.yHotspot;

		/*if (hwnd) {
			RECT rect;

			if (GetWindowRect(hwnd, &rect)) {
				pos.x -= rect.left;
				pos.y -= rect.top;
			}
			else {
				goto icon_error;
			}
		}*/

		if (vertres>0 && vertres>0)
		{
			//�������ƺ���Ҫ����λ��
			pos.x = pos.x * desktopvertres / vertres+nLeft;
			pos.y = pos.y * desktopvertres / vertres;
			
			if (pos.x >= 0 && pos.x <= clip_rect.right - clip_rect.left &&
				pos.y >= 0 && pos.y <= clip_rect.bottom - clip_rect.top) {
				if (!DrawIcon(gdigrab->dest_hdc, pos.x, pos.y, icon))
				{
					/*int i = 0;
					i = 0;*/
				}
			}
		}
	icon_error:
		if (info.hbmMask)
			DeleteObject(info.hbmMask);
		if (info.hbmColor)
			DeleteObject(info.hbmColor);
		if (icon)
			DestroyCursor(icon);
	}
	else {
		//CURSOR_ERROR("Couldn't get cursor info");
	}
}


void *av_malloc(size_t size)  
{  
    void *ptr = NULL;  
    /* let's disallow possibly ambiguous cases */  
    if (size > (INT_MAX - 32))  
        return NULL;  
    ptr = malloc(size);  
    if(!ptr && !size) {  
        size = 1;  
        ptr= av_malloc(1);  
    }  
    return ptr;  
} 



void av_free(void *ptr)
{
#if CONFIG_MEMALIGN_HACK
    if (ptr) {
        int v= ((char *)ptr)[-1];
        av_assert0(v>0 && v<=ALIGN);
        free((char *)ptr - v);
    }
#elif HAVE_ALIGNED_MALLOC
    _aligned_free(ptr);
#else
    free(ptr);
#endif
}

void av_freep(void *arg)
{
	void **ptr = (void **)arg;
	if (*ptr == NULL)
	{
		return;
	}
	av_free(*ptr);
	*ptr = NULL;
}

void av_init_packet(AVPacket *pkt)
{
	if (pkt == NULL)
	{
		return;
	}
    pkt->pts                  = AV_NOPTS_VALUE;
    pkt->dts                  = AV_NOPTS_VALUE;
    pkt->pos                  = -1;
    pkt->duration             = 0;
    pkt->flags                = 0;
    pkt->stream_index         = 0;
    pkt->buf                  = NULL;
   // pkt->side_data            = NULL;
  //  pkt->side_data_elems      = 0;
}

void *av_mallocz(size_t size)
{
    void *ptr = av_malloc(size);
    if (ptr)
        memset(ptr, 0, size);
    return ptr;
}



//void av_packet_free_side_data(AVPacket *pkt)
//{
//    int i;
//	if (pkt == NULL)
//	{
//		return;
//	}
//   /* for (i = 0; i < pkt->side_data_elems; i++)
//        av_freep(&pkt->side_data[i].data);
//    av_freep(&pkt->side_data);
//    pkt->side_data_elems = 0;*/
//}

 void buffer_replace(AVBufferRef **dst, AVBufferRef **src)
{
    AVBuffer *b;

	if (*dst == NULL )
	{
		return;
	}

    b = (*dst)->buffer;

    if (src) {
        **dst = **src;
        av_freep(src);
    } else
        av_freep(dst);

        b->free(b->opaque, b->data);
        av_freep(&b);

}


void av_buffer_unref(AVBufferRef **buf)
{
    if (!buf || !*buf)
        return;

    buffer_replace(buf, NULL);
}


void av_packet_unref(AVPacket *pkt)
{
	if (pkt == NULL)
	{
		return;
	}
    //av_packet_free_side_data(pkt);
    av_buffer_unref(&pkt->buf);
    av_init_packet(pkt);
    pkt->data = NULL;
    pkt->size = 0;
}

void av_packet_free(AVPacket **pkt)
{
    if (!pkt || !*pkt)
        return;

    av_packet_unref(*pkt);

	*pkt = NULL;
    //av_freep(pkt);
}

AVPacket *av_packet_alloc(void)
{
    AVPacket *pkt =(AVPacket *) av_mallocz(sizeof(AVPacket));
    if (!pkt)
        return pkt;

    av_packet_unref(pkt);

    return pkt;
}



void *av_realloc(void *ptr, size_t size)
{
#if CONFIG_MEMALIGN_HACK
    int diff;
#endif

    /* let's disallow possibly ambiguous cases */
    if (size > (INT_MAX - 32))
        return NULL;

#if CONFIG_MEMALIGN_HACK
    //FIXME this isn't aligned correctly, though it probably isn't needed
    if (!ptr)
        return av_malloc(size);
    diff = ((char *)ptr)[-1];
    av_assert0(diff>0 && diff<=ALIGN);
    ptr = realloc((char *)ptr - diff, size + diff);
    if (ptr)
        ptr = (char *)ptr + diff;
    return ptr;
#elif HAVE_ALIGNED_MALLOC
    return _aligned_realloc(ptr, size + !size, ALIGN);
#else
    return realloc(ptr, size + !size);
#endif
}

void av_buffer_default_free(void *opaque, uint8_t *data)
{
    av_free(data);
}

/*=============================================================================
������		 av_buffer_create
����		��������Ƶ���� 
�㷨ʵ��	������ѡ�
����ȫ�ֱ�������
�������˵����
����ֵ˵���� ��������Ƶ����
=============================================================================*/
AVBufferRef *av_buffer_create(uint8_t *data, int size,
                              void (*free)(void *opaque, uint8_t *data),
                              void *opaque, int flags)
{
    AVBufferRef *ref = NULL;
    AVBuffer    *buf = NULL;

    buf = (AVBuffer *)av_mallocz(sizeof(*buf));
    if (!buf)
        return NULL;

    buf->data     = data;
    buf->size     = size;
    buf->free     = free ? free : av_buffer_default_free;
    buf->opaque   = opaque;
    buf->refcount = 1;

    if (flags & AV_BUFFER_FLAG_READONLY)
        buf->flags |= BUFFER_FLAG_READONLY;

    ref = (AVBufferRef*)av_mallocz(sizeof(*ref));
    if (!ref) {
        av_freep(&buf);
        return NULL;
    }

    ref->buffer = buf;
    ref->data   = data;
    ref->size   = size;

    return ref;
}

int av_buffer_is_writable(const AVBufferRef *buf)
{
	if (buf == NULL)
	{
		return 1;
	}
    if (buf->buffer->flags & AV_BUFFER_FLAG_READONLY)
        return 0;

    return 0;// 
}

int av_buffer_realloc(AVBufferRef **pbuf, int size)
{
    AVBufferRef *buf = *pbuf;
    uint8_t *tmp;

    if (!buf) {
       
        uint8_t *data = ( uint8_t *)av_realloc(NULL, size);
        if (!data)
            return 1;

        buf = av_buffer_create(data, size, av_buffer_default_free, NULL, 0);
        if (!buf) {
            av_freep(&data);
            return 2;
        }

        buf->buffer->flags |= BUFFER_FLAG_REALLOCATABLE;
        *pbuf = buf;

        return 0;
    } else if (buf->size == size)
        return 0;

    if (!(buf->buffer->flags & BUFFER_FLAG_REALLOCATABLE) ||
        !av_buffer_is_writable(buf)) {
        /* cannot realloc, allocate a new reallocable buffer and copy data */
        AVBufferRef *newbuf = NULL;

        int nret = av_buffer_realloc(&newbuf, size);
        if (!newbuf)
            return 7;

		memcpy(newbuf->data, buf->data, min(size, buf->size));

        buffer_replace(pbuf, &newbuf);
        return 0;
    }

    tmp = ( uint8_t *)av_realloc(buf->buffer->data, size);
    if (!tmp)
        return 8;

    buf->buffer->data = buf->data = tmp;
    buf->buffer->size = buf->size = size;
    return 0;
}


int packet_alloc(AVBufferRef **buf, int size)
{
    int ret=0;
    if (size < 0 || size >= INT_MAX - AV_INPUT_BUFFER_PADDING_SIZE)
        return 1;//AVERROR(EINVAL);

    ret = av_buffer_realloc(buf, size + AV_INPUT_BUFFER_PADDING_SIZE);
	if (ret > 0)
	{
		return ret;
	}

    memset((*buf)->data + size, 0, AV_INPUT_BUFFER_PADDING_SIZE);

    return 0;
}

int av_new_packet(AVPacket *pkt, int size)
{
    AVBufferRef *buf = NULL;
    int ret = packet_alloc(&buf, size);
    if (ret > 0)
        return ret;

    av_init_packet(pkt);
    pkt->buf      = buf;
    pkt->data     = buf->data;
    pkt->size     = size;

    return 0;
}
	    /** 
     * Grabs a frame from gdi (public device demuxer API). 
     * 
     * @param s1 Context from avformat core 
     * @param pkt Packet holding the grabbed frame 
     * @return frame size in bytes 
     */  
int gdigrab_read_packet(AVFormatContext *s1, AVPacket *pkt)
{
	char chMsg[Max_TempCharLength] = { 0 };
	if (s1 == NULL)
	{
		/*sprintf_s(chMsg, Max_TempCharLength, "AVFormatContext is null \n");
		WriteToLog(chMsg, strnlen_s(chMsg, Max_TempCharLength));*/
		return 0;
	}
	struct gdigrab *gdigrab = (struct gdigrab *)s1->priv_data;
	if (gdigrab == NULL)
	{
		/*sprintf_s(chMsg, Max_TempCharLength, "gdigrab is null \n");
		WriteToLog(chMsg, strnlen_s(chMsg, Max_TempCharLength));*/
		return 0;
	}
	//��ȡ����  
	HDC        dest_hdc = gdigrab->dest_hdc;
	HDC        source_hdc = gdigrab->source_hdc;
	RECT       clip_rect = gdigrab->clip_rect;
	//int64_t    time_frame = gdigrab->time_frame;

	BITMAPFILEHEADER bfh;
	int file_size = gdigrab->header_size + gdigrab->frame_size;

	int64_t curtime;//, delay;  
	curtime = GetTickCount();

	LONGLONG   tbegin;
	QueryPerformanceCounter((LARGE_INTEGER   *)&tbegin);

	/* Run Window message processing queue */
	if (gdigrab->show_region)
		gdigrab_region_wnd_update(s1, gdigrab);


	pkt->pts = curtime; // 0;//

	//GdiFlush();

	LONGLONG   tGdiFlush;
	QueryPerformanceCounter((LARGE_INTEGER   *)&tGdiFlush);
	
	if (g_nCpuPerial > 0)
	{
#if _Debug
		int ndelay = (tGdiFlush - tbegin) * 1000 / g_nCpuPerial;
		/*sprintf_s(chMsg, Max_TempCharLength, "GdiFlush delay:%d\n", ndelay);
		WriteToLog(chMsg, strnlen_s(chMsg, Max_TempCharLength));*/
#endif
	}

	//�ж��Ƿ���4�ֽڶ���
	int nScrWidth = (int)(gdigrab->width);
	bool bIs4Byte = Align4Bytes(&nScrWidth, 0);
	int nLeft = 0;
	if (bIs4Byte)
	{
		//����󣬾�����ʾ
		nLeft = nScrWidth - (clip_rect.right - clip_rect.left);
		nLeft = nLeft / 2;
		//FillRect(dest_hdc,)


		//StretchDIBits
		/*���У������촦��
		if (!BitBlt(dest_hdc, (nScrWidth - clip_rect.right + clip_rect.left) / 2, 0,
			clip_rect.right - clip_rect.left ,
			clip_rect.bottom - clip_rect.top,
			source_hdc,
			clip_rect.left, clip_rect.top, SRCCOPY)) {  //SRCCOPY| CAPTUREBLT 13369376
			return 0;//AVERROR(EIO);
		}
		*/
		//if (!StretchBlt(dest_hdc, 0, 0,
		//	nScrWidth,
		//	nScrHeigh,
		//	source_hdc,
		//	clip_rect.left, clip_rect.top, clip_rect.right- clip_rect.left,
		//	clip_rect.bottom- clip_rect.top, SRCCOPY )) {  //| CAPTUREBLT
		//	DWORD dwError = GetLastError();
		//	return 0;//AVERROR(EIO);  
		//}

	}
	else
	{
	}
	if (!BitBlt(dest_hdc, nLeft, 0,
		clip_rect.right - clip_rect.left + nLeft,
		clip_rect.bottom - clip_rect.top,
		source_hdc,
		clip_rect.left, clip_rect.top, SRCCOPY )) {  //| CAPTUREBLTSRCCOPY| CAPTUREBLT 13369376NOMIRRORBITMAP

		//��ȡ��ǰ�Ĵ�����Ҫ��ӡ����־
		DWORD dwError = GetLastError();
		sprintf_s(chMsg, Max_TempCharLength, "BitBlt have error,GetLastError code:%d,right:%d,bottom:%d,left:%d,top:%d,nScrWidth:%d\n", 
			dwError, clip_rect.right, clip_rect.bottom,clip_rect.left, clip_rect.top, nScrWidth);
		WriteToLog(chMsg, strnlen_s(chMsg, Max_TempCharLength));

		return 0;//AVERROR(EIO);  
	}
	//}

#if _DEBUG
	LONGLONG   tBitBlt;
	QueryPerformanceCounter((LARGE_INTEGER   *)&tBitBlt);

	if (g_nCpuPerial > 0)
	{
		int ndelay = (tBitBlt - tGdiFlush) * 1000 / g_nCpuPerial;
		/*sprintf_s(chMsg, Max_TempCharLength, "tBitBlt:%d\n", ndelay);
		WriteToLog(chMsg, strnlen_s(chMsg, Max_TempCharLength));*/
	}
#endif
	//�����ָ�룿  
	if (gdigrab->draw_mouse)
		paint_mouse_pointer(s1, gdigrab, nLeft);

#if _DEBUG
	LONGLONG   tpaint_mouse;
	QueryPerformanceCounter((LARGE_INTEGER   *)&tpaint_mouse);

	if (g_nCpuPerial > 0)
	{
		int ndelay = (tpaint_mouse - tBitBlt) * 1000 / g_nCpuPerial;
		/*sprintf_s(chMsg, Max_TempCharLength, "paint_mouse_pointer:%d\n", ndelay);
		WriteToLog(chMsg, strnlen_s(chMsg, Max_TempCharLength));*/
	}
#endif    
	//�����ã�����ɫ
	if (bIs4Byte)
	{
		RECT sFillRect;
		sFillRect.left = nScrWidth - nLeft;
		sFillRect.right = clip_rect.left + nScrWidth;
		sFillRect.top = clip_rect.top;
		sFillRect.bottom = clip_rect.bottom;
		FillRect(dest_hdc, &sFillRect, g_sBrush);
	}
	/* Copy bits to packet data */
	//BMP�ļ�ͷBITMAPFILEHEADER  
	bfh.bfType = 0x4d42; /* "BM" in little-endian */
	bfh.bfSize = file_size;
	bfh.bfReserved1 = 0;
	bfh.bfReserved2 = 0;
	bfh.bfOffBits = gdigrab->header_size;
	//��AVPacket�п�������  
	//����BITMAPFILEHEADER  
	if (pkt->data == NULL)
	{
		
		/*sprintf_s(chMsg, Max_TempCharLength, "BitBlt get dib data error,data is null\n");
		WriteToLog(chMsg, strnlen_s(chMsg, Max_TempCharLength));*/
		return 0;
	}
	memcpy(pkt->data, &bfh, sizeof(bfh));
	//����BITMAPINFOHEADER  
	memcpy(pkt->data + sizeof(bfh), &gdigrab->bmi.bmiHeader, sizeof(gdigrab->bmi.bmiHeader));
	//������  
	if (gdigrab->bmi.bmiHeader.biBitCount <= 8)
	{
		GetDIBColorTable(dest_hdc, 0, 1 << gdigrab->bmi.bmiHeader.biBitCount,
			(RGBQUAD *)(pkt->data + sizeof(bfh) + sizeof(gdigrab->bmi.bmiHeader)));
	}
#if _DEBUG
	LONGLONG   tDIBColor;
	QueryPerformanceCounter((LARGE_INTEGER   *)&tDIBColor);

	if (g_nCpuPerial > 0)
	{
		int ndelay = (tDIBColor - tpaint_mouse) * 1000 / g_nCpuPerial;
		/*sprintf_s(chMsg, Max_TempCharLength, "GetDIBColorTable:%d\n", ndelay);
		WriteToLog(chMsg, strnlen_s(chMsg, Max_TempCharLength));*/
	}
#endif
	//������������  
	memcpy(pkt->data + gdigrab->header_size, gdigrab->buffer, gdigrab->frame_size);
	pkt->size = file_size;

#if _DEBUG
	LONGLONG   tmemcpy;
	QueryPerformanceCounter((LARGE_INTEGER   *)&tmemcpy);
	if (g_nCpuPerial > 0)
	{
		int ndelay = (tmemcpy - tDIBColor) * 1000 / g_nCpuPerial;
		/*sprintf_s(chMsg, Max_TempCharLength, "memcpy:%d\n", ndelay);
		WriteToLog(chMsg, strnlen_s(chMsg, Max_TempCharLength));*/
	}
#endif
	return gdigrab->header_size + gdigrab->frame_size;
}

/**
 * Cleanup/free the region outline window.
 *
 * @param s1 The format context.
 * @param gdigrab gdigrab context.
 */
 void gdigrab_region_wnd_destroy(AVFormatContext *s1, struct gdigrab *gdigrab)
{
	 if (gdigrab == NULL)
	 {
		 return ;
	 }
    if (gdigrab->region_hwnd)
        DestroyWindow(gdigrab->region_hwnd);
    gdigrab->region_hwnd = NULL;
}


/**
 * Closes gdi frame grabber (public device demuxer API).
 *
 * @param s1 Context from avformat core
 * @return 0 success, !0 failure
 */
int gdigrab_read_close(AVFormatContext *s1)
{
	if (s1 == NULL)
	{
		return 0;
	}
    struct gdigrab *s = (struct gdigrab*)s1->priv_data;
	if(s)
	{
		if (s->show_region)
			gdigrab_region_wnd_destroy(s1, s);

		if (s->source_hdc)
			ReleaseDC(s->hwnd, s->source_hdc);
		if (s->dest_hdc)
			DeleteDC(s->dest_hdc);
		if (s->hbmp)
			DeleteObject(s->hbmp);
		if (s->source_hdc)
			DeleteDC(s->source_hdc);
	}
    return 0;
}



// This is the constructor of a class that has been exported.
// see DesktopCapture.h for the class definition
CDesktopCapture::CDesktopCapture()
{ 
	g_tdispInfo.nDeviceCount=0;
	g_nSelectScreenIndex=0;
	m_bIsInit=false;

	m_nRGBtoYUVWidth=0;
	m_nRGBtoYUVHeight=0;
	m_CallbackType=0;
	g_sBrush = CreateSolidBrush(RGB(0, 0, 0));

	g_bIsWin8OrLater = JudgeIsWin8OrLater();
	if (g_bIsWin8OrLater)
	{
		g_emGrabMode = MODE_DXGI;
		g_bAlign4Bytes = false;
	}//DXGIĬ��Ϊ16�ֽڶ���

	//DXGI
	m_bDXInit = FALSE;
	m_hDevice = NULL;
	m_hContext = NULL;
	m_hDeskDupl = NULL;
	ZeroMemory(&m_dxgiOutDesc, sizeof(m_dxgiOutDesc));
	m_bMapBitsChanged = false;
	m_emCurGrabMode = g_emGrabMode;

	return; 
}

CDesktopCapture::~CDesktopCapture()
{
	Destroy();

	m_nRGBtoYUVWidth=0;
	m_nRGBtoYUVHeight=0;

	m_bIsInit=false;
	DeleteObject( g_sBrush);
	/*AVPacket*avTemp = &g_avPacket;
	av_packet_free(&avTemp);*/
	ZeroMemory(&m_dxgiOutDesc, sizeof(m_dxgiOutDesc));
}



void CDesktopCapture::Destroy()
{
	/*if(g_uTimerID)
	{
		::timeKillEvent (g_uTimerID);
		g_uTimerID=0;
	}
	if(g_uCallTimerID)
	{
		::timeKillEvent (g_uCallTimerID);
		g_uCallTimerID=0;
	}*/

	Stop();


	CAutoLock  csLock(&m_csDB);
	//gdigrab_read_close(&g_avFormatatContentx);
	if(NULL != g_pvPreProcHandle)
	{
		ImageUnitClose(g_pvPreProcHandle);
		g_pvPreProcHandle = NULL;
	}
	if(g_pDesktopYuvBuf)
	{
		delete[] g_pDesktopYuvBuf;
		g_pDesktopYuvBuf = NULL;
	}

	
	if(g_pRetDesktopYuvBuf)
	{
		delete[] g_pRetDesktopYuvBuf;
		g_pRetDesktopYuvBuf=NULL;
	}

	AVPacket*avTemp = &g_avPacket;
	av_packet_free(&avTemp);

	//UninstallHookEv();
}

/*=============================================================================
������		 SetVedioCallBack
����		�����ûص�
�㷨ʵ��	������ѡ�
����ȫ�ֱ�������
�������˵����
PVEDIOCALLBACK  �ص�����
dwContext       �ص����ص��û�����
����ֵ˵���� �ɹ�����TRUE, ʧ�ܷ���FALSE
=============================================================================*/
bool CDesktopCapture::SetVedioCallBack(PAVCALLBACK pVedioCallBack, 
									void* dwContext)
{
	
	m_pVedioNetCB = pVedioCallBack;
	m_dwContext = dwContext;
	
	
	return true;
}


/*  ��ʼ������. */  
int init_input(AVFormatContext *s, const char *filename)  
{  
	if (s == NULL)
	{
		return -1;
	}
 	strcpy_s(s->filename,filename);
 
   
    if (s->iformat)  
        return 0;  
   
	return 0;
} 

/*=============================================================================
������		 MySleep
����		�� �Զ�����ʱ����
�㷨ʵ��	������ѡ�
����ȫ�ֱ�������
�������˵������ʱʱ��
����ֵ˵���� ��
=============================================================================*/
void MySleep(int interval)
{
	HANDLE evt;
	if (interval <= 0) interval = 1;
	evt = CreateEvent(NULL, TRUE, FALSE, NULL);
	WaitForSingleObject(evt, interval);
	CloseHandle(evt);

}

int CDesktopCapture::ResizeDestop()
{
	CAutoLock csLock(&m_csDB);
	struct gdigrab *gdigrab1 = (gdigrab *)(&g_avFormatatContentx)->priv_data;

	if (gdigrab1 == NULL)
	{
		return 1;
	}
	 gdigrab_read_close(&g_avFormatatContentx);

    //���ھ��  
	HWND hwnd=NULL;  
    HDC source_hdc = NULL;  
    HDC dest_hdc   = NULL;  
    BITMAPINFO bmi;  
    HBITMAP hbmp   = NULL;  
    void *buffer   = NULL;  
      
    const char *filename = g_avFormatatContentx.filename;  
    const char *name     = NULL;  
     
     int nScrWidth  = 0; //GetSystemMetrics(SM_CXSCREEN); 
     int nScrHeight = 0; //GetSystemMetrics(SM_CYSCREEN);

	 char chLog[Max_TempCharLength] = { 0 };

        int bpp=24;  
		if (g_emGrabMode == MODE_DXGI)
		{
			bpp = 32;
		}

        RECT virtual_rect;  
        //���ڵ�λ�úʹ�С  
        RECT clip_rect;  
        int ret=0;  
        //filenameΪ��������  
        if (!strncmp(filename, "title=", 6)) {  
            name = filename + 6;  
            //���Ҵ��ڵľ��  
            hwnd = FindWindow(NULL, name);  
            if (!hwnd) {  
                goto error;  
            }  
            if (gdigrab1->show_region) {  
                gdigrab1->show_region = 0;  
            }  
            //filenameΪdesktop  
        } else if (!strcmp(filename, "desktop")) {  
            //���ھ��ΪNULL  
            hwnd = NULL;  
        } else {  
            goto error;  
        }  
      
        if (hwnd) {  
            GetClientRect(hwnd, &virtual_rect);  
        } else {  
            //���ھ��ΪNULL��������ȫ��  
			HWND hh=GetDesktopWindow();
			HDC hd = GetDC(hh);
			//
			//HDC hd = CreateDC(("DISPLAY"), NULL, NULL, NULL);

			///////////////////mult display
			if(g_tdispInfo.nDeviceCount<=0)
			{
				GetAllDisplay();
			}

			 if(g_nSelectScreenIndex>g_tdispInfo.nDeviceCount)
			 {
				 g_nSelectScreenIndex=0;
			 }

			 int nleft=0;
			 int ntop=0;
			 if(g_nSelectScreenIndex<2)
			 {
				nScrWidth  = g_tdispInfo.arydmDevMode[0].dmPelsWidth; 
				nScrHeight =  g_tdispInfo.arydmDevMode[0].dmPelsHeight; //GetSystemMetrics(SM_CYSCREEN); 
				nleft=g_tdispInfo.arydmDevMode[0].dmPosition.x;
				ntop=g_tdispInfo.arydmDevMode[0].dmPosition.y;
			 }
			 else
			 {
				nScrWidth  = g_tdispInfo.arydmDevMode[1].dmPelsWidth; 
				nScrHeight =  g_tdispInfo.arydmDevMode[1].dmPelsHeight; //GetSystemMetrics(SM_CYSCREEN); 
				nleft=g_tdispInfo.arydmDevMode[1].dmPosition.x;
				ntop=g_tdispInfo.arydmDevMode[1].dmPosition.y;
		 	}

		
			 if (nScrWidth>Max_Screen_Width)
			 {
				 nScrWidth = Max_Screen_Width;
			 }
			 if (nScrHeight>Max_Screen_Heigth)
			 {
				 nScrHeight = Max_Screen_Heigth;
			 }

			

            virtual_rect.left =nleft;
            virtual_rect.top = ntop;
            virtual_rect.right = virtual_rect.left +nScrWidth;// GetSystemMetrics(SM_CXVIRTUALSCREEN);  
            virtual_rect.bottom = virtual_rect.top + nScrHeight;//GetSystemMetrics(SM_CYVIRTUALSCREEN); 

        }  
      
        /* If no width or height set, use full screen/window area */  
      
            clip_rect.left = virtual_rect.left;  
            clip_rect.top = virtual_rect.top;  
            clip_rect.right = virtual_rect.right;  
            clip_rect.bottom = virtual_rect.bottom;  

			gdigrab1->width = nScrWidth;//clip_rect.right - clip_rect.left;
			gdigrab1->height=clip_rect.bottom-clip_rect.top;
       
      
        if (clip_rect.left < virtual_rect.left ||  
                clip_rect.top < virtual_rect.top ||  
                clip_rect.right > virtual_rect.right ||  
                clip_rect.bottom > virtual_rect.bottom) {  

			sprintf_s(chLog, Max_TempCharLength, "��ȡ�Ŀ�ȣ��߶Ȳ���ȷ,weight<=0,height<=0");
			WriteToLog(chLog, Max_TempCharLength);
                goto error;  
        }  
      
        //�õ�ĳ�����ھ����DC   
        source_hdc = GetDC(hwnd);  
        if (!source_hdc) {  
            /*WIN32_API_ERROR("Couldn't get window device context");  
            ret = AVERROR(EIO);  */
			DWORD dwError = GetLastError();
			sprintf_s(chLog, Max_TempCharLength, "GetLastError��ȡ�����:%d", dwError);
			WriteToLog(chLog, Max_TempCharLength);
            goto error;  
        }  
      
       
      
        if (clip_rect.right - clip_rect.left <= 0 ||  
                clip_rect.bottom - clip_rect.top <= 0 || bpp%8) {  
			sprintf_s(chLog, Max_TempCharLength, "��ȡ��������������,weight<=0,height<=0");
			WriteToLog(chLog, Max_TempCharLength);
            goto error;  
        }  
        //����һ����ָ���豸���ݵ�HDC  
        dest_hdc = CreateCompatibleDC(source_hdc);  
        if (!dest_hdc) { 
			DWORD dwError = GetLastError();
			sprintf_s(chLog, Max_TempCharLength, "CreateCompatibleDC��������GetLastError:%d", dwError);
			WriteToLog(chLog, Max_TempCharLength);
            goto error;  
        }  

		//�ж��Ƿ���4�ֽڶ���
		int nOrgWidth = nScrWidth;
		Align4Bytes(&nScrWidth, 0);


        /* Create a DIB and select it into the dest_hdc */  
        //BMP  
        bmi.bmiHeader.biSize          = sizeof(BITMAPINFOHEADER);  
		bmi.bmiHeader.biWidth         = nScrWidth;//clip_rect.right - clip_rect.left;
		bmi.bmiHeader.biHeight        = nScrHeight;//clip_rect.bottom - clip_rect.top;////-(clip_rect.bottom - clip_rect.top);  
		if (g_emGrabMode == MODE_DXGI)
		{
			bmi.bmiHeader.biHeight = -abs(bmi.bmiHeader.biHeight);
		}
        bmi.bmiHeader.biPlanes        = 1;  
        bmi.bmiHeader.biBitCount      = bpp;  
        bmi.bmiHeader.biCompression   = BI_RGB;  
        bmi.bmiHeader.biSizeImage     = 0;  
        bmi.bmiHeader.biXPelsPerMeter = 0;  
        bmi.bmiHeader.biYPelsPerMeter = 0;  
        bmi.bmiHeader.biClrUsed       = 0;  
        bmi.bmiHeader.biClrImportant  = 0;  
        hbmp = CreateDIBSection(dest_hdc, &bmi, DIB_RGB_COLORS,  
                &buffer, NULL, 0);  
        if (!hbmp) {    
			DWORD dwError = GetLastError();
			/*sprintf_s(chLog, Max_TempCharLength, "CreateDIBSection error:%d", dwError);
			WriteToLog(chLog, Max_TempCharLength);*/
            goto error;  
        }  
      
        if (!SelectObject(dest_hdc, hbmp)) {  
			DWORD dwError = GetLastError();
			/*sprintf_s(chLog, Max_TempCharLength, "SelectObject error:%d", dwError);
			WriteToLog(chLog, Max_TempCharLength);*/
            goto error;  
        }  
      
        /* Get info from the bitmap */  
       // GetObject(hbmp, sizeof(BITMAP), &bmp);  
       
        //������Ϣ��GDIGrab�����Ľṹ��  
		//bmp.bmWidthBytes * bmp.bmHeight * bmp.bmPlanes;
	gdigrab1->frame_size  = nScrWidth * nScrHeight * bpp/8;  // nScrWidth * nScrHeight * bpp/8;
    
		gdigrab1->header_size = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) ;

        
        gdigrab1->hwnd       = hwnd;  
        gdigrab1->source_hdc = source_hdc;  
        gdigrab1->dest_hdc   = dest_hdc;  
        gdigrab1->hbmp       = hbmp;  
        gdigrab1->bmi        = bmi;  
        gdigrab1->buffer     = buffer;  
        gdigrab1->clip_rect  = clip_rect;  
      
        gdigrab1->cursor_error_printed = 0;  
      
        if (gdigrab1->show_region) {  
            if (gdigrab_region_wnd_init(&g_avFormatatContentx, gdigrab1)) {  
                //ret = AVERROR(EIO);

			
				/*sprintf_s(chLog, Max_TempCharLength, "gdigrab_region_wnd_init error");
				WriteToLog(chLog, Max_TempCharLength);*/
                goto error;  
            }  
        }  
      
		gdigrab1->draw_mouse = true;

		//
		//TImageRGBtoYUVParam m_tImageRGBtoYUV;	//�ṹ����
		memset(&m_tImageRGBtoYUV, 0, sizeof(TImageRGBtoYUVParam));
		int nRet = VIDEO_SUCCESS;

		m_nRGBtoYUVWidth = nScrWidth;
	    m_nRGBtoYUVHeight=nScrHeight;

		m_tImageRGBtoYUV.l32SrcWidth   = nScrWidth;
		m_tImageRGBtoYUV.l32SrcHeight  = nScrHeight;
		m_tImageRGBtoYUV.l32SrcStride  = nScrWidth;
		m_tImageRGBtoYUV.l32SrcRGBType = RGB24;
		m_tImageRGBtoYUV.l32DstWidth   = nScrWidth;
		m_tImageRGBtoYUV.l32DstHeight  = nScrHeight;
		m_tImageRGBtoYUV.l32DstStride  = nScrWidth;
		m_tImageRGBtoYUV.l32DstYUVType = YUV420;
		m_tImageRGBtoYUV.l32TransposeFlag = 1;
		m_tImageRGBtoYUV.u32Reserved = 0;
		if (g_emGrabMode == MODE_DXGI)
		{
			m_tImageRGBtoYUV.l32SrcRGBType = RGB32;
			m_tImageRGBtoYUV.l32TransposeFlag = 0;
		}
		//int nRet = ImageUnitSetParam(m_pvPreProcHandle,&m_tPreResize);
		nRet = ImageUnitSetParam(g_pvPreProcHandle, &m_tImageRGBtoYUV);
      
		m_CallbackType++;
		if(m_CallbackType>10000)
		{
			m_CallbackType=0;
		}


		//int dwLen = 1920 * 1080 * 4 + 
		int dwLen = nScrWidth * nScrHeight * 4 +
		sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);
		if (g_pRetDesktopYuvBuf)
		{
			memset(g_pRetDesktopYuvBuf, 0, dwLen);
		}

		if (g_emGrabMode == MODE_DXGI)
		{
			//DXGI
			DestroyDXGI();
			InitDXGI();
		}

        return 0;  
      
    error:  
        //���������  
        if (source_hdc)  
            ReleaseDC(hwnd, source_hdc);  
        if (dest_hdc)  
            DeleteDC(dest_hdc);  
        if (hbmp)  
            DeleteObject(hbmp);  
        if (source_hdc)  
            DeleteDC(source_hdc);  
        return ret; 
}

/*=============================================================================
������		 ThreadQueryAeroFun
����		�� ��ʱ����������ʾ��Ϣ
�㷨ʵ��	������ѡ�
����ȫ�ֱ�������
�������˵����
����ֵ˵���� Ĭ��Ϊ��
=============================================================================*/
DWORD WINAPI ThreadQueryAeroFun(LPVOID pM)  
{ 
	if (pM == NULL)
	{
		return 0;
	}
	CDesktopCapture* pMain=(CDesktopCapture*)pM;
	

	while(pMain->m_bIsStart)
	{


		MySleep(700);
	
		pMain->FindAeroTipWindow();

	}

    return 0;  
}


/*=============================================================================
������		 InitAll
����		�� ��ʼ��
�㷨ʵ��	������ѡ�
����ȫ�ֱ�������
�������˵����bjt�Ƿ����������Ϣ
����ֵ˵���� ��
=============================================================================*/
void CDesktopCapture::InitAll(bool bjt)  
{  
	char strTmp[MAX_PATH + Max_TempCharLength + 1] = { 0 };
	
	char buffer[MAX_PATH + 1];
	GetCurrentDir(buffer);

	sprintf_s(strTmp, "%s\\log\\", buffer);
	FindOrCreateDirectory(strTmp);
	g_bIsGetDisplay = false;
	
	int ret = 0; 
	if ((ret = init_input(&g_avFormatatContentx, "desktop")) < 0)
	{
		/*sprintf_s(strTmp, "init init_input have error\n");
		WriteToLog(strTmp, MAX_PATH);*/
		return;
	}
	g_gdiInfo.draw_mouse=true;
	g_avFormatatContentx.priv_data=&g_gdiInfo;

	g_avFormatatContentx.probe_score=ret;

	//gdigrab_read_header(&g_avFormatatContentx);
	g_bIsBMP=bjt;

	if (g_emGrabMode == MODE_DXGI)
	{
		//DXGIץ������⵽ʵ��ץ������Ϊ4�ֽڶ��뷽ʽ
		if (!m_bMapBitsChanged)
		{
			g_bAlign4Bytes = false;
		}
		else
		{
			m_bMapBitsChanged = false;
		}
	}

	///////////////////mult display
	if(g_tdispInfo.nDeviceCount<=0)
	{
		GetAllDisplay();
	}

	if (g_tdispInfo.nDeviceCount <= 0)
	{
		/*sprintf_s(strTmp, "Use EnumDisplayDevices to get displays %d\n", g_tdispInfo.nDeviceCount);
		WriteToLog(strTmp,MAX_PATH);*/
	}

	 int nScrWidth  = 0;
     int nScrHeight = 0; 
	 if(g_nSelectScreenIndex>g_tdispInfo.nDeviceCount)
	 {
		 g_nSelectScreenIndex=0;
	 }
	if(g_nSelectScreenIndex<2)
	{
		nScrWidth  = g_tdispInfo.arydmDevMode[0].dmPelsWidth; 
		nScrHeight =  g_tdispInfo.arydmDevMode[0].dmPelsHeight; 
	}
	else
	{
		nScrWidth  = g_tdispInfo.arydmDevMode[1].dmPelsWidth; 
		nScrHeight =  g_tdispInfo.arydmDevMode[1].dmPelsHeight; 
	}

	
	//�ж��Ƿ���4�ֽڶ���
	Align4Bytes(&nScrWidth,&nScrHeight);

	char chMsg[Max_TempCharLength]={0};
	#if _DEBUG
	sprintf_s(chMsg,"width:%d,height:%d\n",nScrWidth,nScrHeight);
	OutputDebugString(chMsg);
	#endif

	//TImageRGBtoYUVParam m_tImageRGBtoYUV;	//�ṹ����
	memset(&m_tImageRGBtoYUV, 0, sizeof(TImageRGBtoYUVParam));
	int nRet = VIDEO_SUCCESS;
	m_tImageRGBtoYUV.l32SrcWidth   = nScrWidth;
#if _DEBUG
	sprintf_s(chMsg,"m_tImageRGBtoYUV.l32SrcWidth:%d\n",m_tImageRGBtoYUV.l32SrcWidth);
	OutputDebugString(chMsg);
#endif
	m_tImageRGBtoYUV.l32SrcHeight  = nScrHeight;

	sprintf_s(chMsg,"m_tImageRGBtoYUV.l32SrcHeight:%d\n",m_tImageRGBtoYUV.l32SrcHeight);
	OutputDebugString(chMsg);

	m_tImageRGBtoYUV.l32SrcStride  = nScrWidth;

	m_tImageRGBtoYUV.l32SrcRGBType = RGB24;

	m_tImageRGBtoYUV.l32DstWidth   = nScrWidth;
	m_tImageRGBtoYUV.l32DstHeight  = nScrHeight;
	m_tImageRGBtoYUV.l32DstStride  = nScrWidth;
	m_tImageRGBtoYUV.l32DstYUVType = YUV420;
	m_tImageRGBtoYUV.l32TransposeFlag = 1;
	m_tImageRGBtoYUV.u32Reserved = 0;
	if (g_emGrabMode == MODE_DXGI)
	{
		m_tImageRGBtoYUV.l32SrcRGBType = RGB32;
		m_tImageRGBtoYUV.l32TransposeFlag = 0;
	}

	sprintf_s(chMsg,"m_tImageRGBtoYUV.l32SrcStride:%d,m_tImageRGBtoYUV.l32DstWidth:%d\n",m_tImageRGBtoYUV.l32SrcStride,m_tImageRGBtoYUV.l32DstWidth);
	OutputDebugString(chMsg);

	nRet = 	ImageUnitOpen(&g_pvPreProcHandle, &m_tImageRGBtoYUV, NULL, IMG_RGBTOYUV);
	if (nRet != VIDEO_SUCCESS || g_pvPreProcHandle == NULL)
	{
		unsigned char *pMsg = new unsigned char[1024];
	 	ImageUnitAnalyzeErrorCode(g_pvPreProcHandle,nRet,1024,pMsg);
	 	delete [] pMsg;

		sprintf_s(strTmp, "���ú���ImageUnitOpenʧ��\n");
		WriteToLog(strTmp, MAX_PATH);
 	}

	if (NULL != g_pvPreProcHandle)
	{
			
		nRet = ImageUnitSetParam(g_pvPreProcHandle, &m_tImageRGBtoYUV);
		if (nRet != VIDEO_SUCCESS || g_pvPreProcHandle == NULL)
		{
			unsigned char *pMsg = new unsigned char[1024];
			ImageUnitAnalyzeErrorCode(g_pvPreProcHandle,nRet,1024,pMsg);
			delete [] pMsg;

			char chLog[Max_TempCharLength] = { 0 };
			sprintf_s(chLog, "���ú���ImageUnitSetParamʧ��\n");
			WriteToLog(chLog, Max_TempCharLength);
		}
	}

	nRet = ImageUnitSetParam(g_pvPreProcHandle,&g_tPreResize);

	m_nRGBtoYUVWidth=nScrWidth;
	m_nRGBtoYUVHeight=nScrHeight;

	m_bIsEndChange= FALSE;
	m_nLostCount=0;

	m_bIsInit=true;

	//InstallHookEv();

	InitConstData();
	sprintf_s(strTmp, "ץ����ʽ��GDI \n");
	if (g_emGrabMode == MODE_DXGI)
	{
		if (!InitDXGI())
		{
			m_bDXInit = TRUE;
			DestroyDXGI();

			char chLog1[Max_TempCharLength] = { 0 };
			sprintf_s(chLog1, "InitDXGI Error, �л���GDIץ����ʽ\n");
			WriteToLog(chLog1, Max_TempCharLength);

			//DXGI��ʼ��ʧ��ʱ�л�ΪGDIץ����ʽ
			g_emGrabMode = MODE_GDI;
			m_emCurGrabMode = g_emGrabMode;
			g_bAlign4Bytes = true;
			ResizeDestop();
		}
		else
		{
			sprintf_s(strTmp, "ץ����ʽ��DXGI \n");
		}
	}
	WriteToLog(strTmp, MAX_PATH);
}

// �������ܣ���ȡϵͳʱ��Ƭ 
//   ����ֵ��ϵͳʱ��Ƭ����λ���� 
LONGLONG McGetTick()
{
#if defined (_MSC_VER) 
	LARGE_INTEGER tFrequency = { 0 };
	//LARGE_INTEGER tPerformanceCount = { 0 };
	LONGLONG tPerformanceCount = 0;
	// ��ȡ����Ƶ�� 
	//QueryPerformanceFrequency(&tFrequency);
	// ��ȡ������ 
	//QueryPerformanceCounter(&tPerformanceCount);
	QueryPerformanceCounter((LARGE_INTEGER   *)&tPerformanceCount);
	
	// ������ʱ��Ƭ 
	return (LONGLONG)tPerformanceCount;//(LONGLONG)((tPerformanceCount.QuadPart * 1000 / tFrequency.QuadPart) & 0x00000000FFFFFFFF);
#elif defined (__LINUX__) 
#endif 
}
/*=============================================================================
������		 SendDesktopTimer
����		�� ��ʱ�ɼ�
�㷨ʵ��	������ѡ�
����ȫ�ֱ�������
�������˵����
����ֵ˵���� ��
=============================================================================*/
DWORD WINAPI SendDesktopTimer(LPVOID dwUser)
{
	if (dwUser == NULL)
	{
		return 0;
	}
	CDesktopCapture *pMain = (CDesktopCapture *)dwUser;

	if (pMain == NULL)
	{
		return 0;
	}

#if _DEBUG
	/*char ch[200]={0};
	sprintf_s(ch,"Timer:%d:timer:%d,%d,%d\n",uTimerID,uMsg,dw1,dw2);
	OutputDebugString(ch);*/
#endif

	//
	char ch[Max_TempCharLength] = { 0 };
	//sprintf_s(ch, "Begin to capture\n");
	//WriteToLog(ch, strnlen_s(ch, 200));
	while (pMain->GetIsRunning())
	{
		struct gdigrab *gdigrab = (struct gdigrab *)g_avFormatatContentx.priv_data;
		int nLay = 0;
		//09-15��������ʱ�����ɼ�֡�����Ʋ����ڿ���֡�ʵ�105% 
		if (g_nCpuPerial > 0)
		{
			LONGLONG   t0;
			QueryPerformanceCounter((LARGE_INTEGER*)& t0);
			//����֡��a-nlay-b--c3
			 nLay = (t0 - gdigrab->time_frame) * 1000 / g_nCpuPerial;
			
			int nDelay = 1;//gdigrab->framerate.den;//13;
			//gdigrab->nAllDelay= gdigrab->nAllDelay+ nLay;   //ʱ��
			if (gdigrab->nFrameCount==0)
			{
				if (gdigrab->last_frame < gdigrab->framerate.den*20/21)
				{
					nDelay = gdigrab->framerate.den*20/21- gdigrab->last_frame-2;
				}
				
#if _DEBUG
				char chTesLog[Max_TempCharLength] = { 0 };
				sprintf_s(chTesLog, "gdigrab->nFrameCount=0 --nDelay=%d,last time:%d\n", nDelay, gdigrab->last_frame);
				OutputDebugString(chTesLog);
#endif
			}
			else
			{
				if (gdigrab->nFrameCount*gdigrab->framerate.den *20 / 21 > nLay) //֡�ʹ�
				{
					nDelay = (gdigrab->nFrameCount )*gdigrab->framerate.den * 20 / 21 - nLay-2;// -5;
				}
				
#if _DEBUG
				char chTesLog[Max_TempCharLength] = { 0 };
				sprintf_s(chTesLog, "gdigrab->nFrameCount=%d --nDelay=%d,total delay:%d\n", gdigrab->nFrameCount, nDelay, nLay);
				OutputDebugString(chTesLog);
#endif
			}
			if (nDelay <= 0)
			{
				nDelay = 2;   //��ֹcpuռ�ù��� -5
			}
			else if(nDelay >1000)
			{
				/*sprintf_s(ch, "The delay of the capture screen is to large,%d \n",nDelay);
				WriteToLog(ch, strnlen_s(ch, Max_TempCharLength));*/
				nDelay=gdigrab->framerate.den;
			}
				//Sleep(15);
				MySleep(nDelay);
#if _DEBUG
				char chTestDelay[Max_TempCharLength] = { 0 };
				sprintf_s(chTestDelay, "SendDesktopTimer --last_frame ndelay=%d\n", nLay);
				OutputDebugString(chTestDelay);
#endif
		

		}

		LONGLONG   t1;
		QueryPerformanceCounter((LARGE_INTEGER*)& t1);
		if (gdigrab->nFrameCount == 0)
		{
			gdigrab->time_frame = t1;
		}

		//�����ɹ��ϱ�
		int nRet = pMain->CaptureScreen();

		//if (pMain->CaptureScreen()==0)
		if(nRet == 0)
		{

			PostThreadMessage(pMain->m_dwThreadId, MESSAGE_POST_TO_UI, 0, 0);
			gdigrab->nFrameCount = gdigrab->nFrameCount + 1;
			//pMain->CallbackToUI();
		}
		else
		{
			if (nRet > 1)
			{
				ErrorLog(nRet);

				gdigrab->nAllDelay = 0;
				gdigrab->nFrameCount = 0;
			}
		}

		if (nLay >= 5000 || gdigrab->nFrameCount >= 5 * gdigrab->framerate.num)//5s����һ��
		{
			gdigrab->nAllDelay = 0;
			gdigrab->nFrameCount = 0;
		}

		int nlastdelay = 0;
		if (g_nCpuPerial>0)
		{
			LONGLONG   t2;
			QueryPerformanceCounter((LARGE_INTEGER   *)&t2);
			nlastdelay = (t2 - t1) * 1000 / g_nCpuPerial;

#if _DEBUG
			char chLogDelay[Max_TempCharLength] = { 0 };
			sprintf_s(chLogDelay, "SendDesktopTimer -- ndelay=%d\n", nlastdelay);
			OutputDebugString(chLogDelay);
#endif

		}

		if (nlastdelay >= gdigrab->framerate.den*20/21 || nlastdelay >= CAPTURE_TIMEOUT)
		{
			gdigrab->nAllDelay = 0;
			gdigrab->nFrameCount = 0;
		}

		//Sleep(15);
		gdigrab->last_frame = nlastdelay;// McGetTick();//t1;
	}

	return 0;
}


/*=============================================================================
������		 SendDesktopTimer
����		�� ��ʱ�ɼ�
�㷨ʵ��	������ѡ�
����ȫ�ֱ�������
�������˵����
����ֵ˵���� ��
=============================================================================*/
void CALLBACK SendDesktopTimer(UINT uTimerID, UINT uMsg, DWORD dwUser, DWORD dw1, DWORD dw2)
//DWORD WINAPI SendDesktopTimer(LPVOID dwUser)
{ 
	CDesktopCapture *pMain = (CDesktopCapture *)dwUser; 
	int nLay = 0;
	if(pMain == NULL)
	{
		return ;
	}

	#if _DEBUG
	/*char ch[200]={0};
	sprintf_s(ch,"Timer:%d:timer:%d,%d,%d\n",uTimerID,uMsg,dw1,dw2);
	OutputDebugString(ch);*/
#endif

	//while (pMain->GetIsRunning())
	if(pMain->GetIsRunning())
	{

	
		LONGLONG   t1; 
		QueryPerformanceCounter((LARGE_INTEGER   *)&t1); 
		struct gdigrab *gdigrab = (struct gdigrab *)g_avFormatatContentx.priv_data;  

		//09-15��������ʱ�����ɼ�֡�����Ʋ����ڿ���֡�ʵ�120% 
		if (g_nCpuPerial > 0)
		{

			/*int nLay = (t1 - gdigrab->last_frame) * 1000 / g_nCpuPerial;
			if (nLay < gdigrab->framerate.den*1.2)
			{
				return;
			}*/


			nLay = (t1 - gdigrab->time_frame) * 1000 / g_nCpuPerial;
			if ((nLay + gdigrab->last_frame)*1.4 + g_nTimeCapture < gdigrab->framerate.den)
			{
				//Sleep(10);
				//MySleep(10);
#if _DEBUG
				char chTestDelay[Max_TempCharLength] = { 0 };
				sprintf_s(chTestDelay, "SendDesktopTimer --last_frame ndelay=%d\n", nLay);
				OutputDebugString(chTestDelay);
#endif
				return;
			}

			//pMain->CaptureScreen();
			if (pMain->CaptureScreen() == 0)
			{

				PostThreadMessage(pMain->m_dwThreadId, MESSAGE_POST_TO_UI, 0, 0);
				//pMain->CallbackToUI();
			}

		}
	
		int ndelay=0;
		if(g_nCpuPerial>0)
		{
			LONGLONG   t2; 
		    QueryPerformanceCounter((LARGE_INTEGER   *)&t2); 
			ndelay=(t2 - t1)*1000/g_nCpuPerial;

			#if _DEBUG
			char chLogDelay[Max_TempCharLength]={0};
			sprintf_s(chLogDelay,"SendDesktopTimer -- ndelay=%d\n",ndelay);
			OutputDebugString(chLogDelay);
			#endif

		}

		//Sleep(2);
		//gdigrab->last_frame=t1;
		gdigrab->last_frame = nLay;// McGetTick();//t1;
		gdigrab->time_frame = McGetTick();
	}
	//return 0;
}


/*=============================================================================
������		 ThreadFun
����		�� ��ʱ�ص�
�㷨ʵ��	������ѡ�
����ȫ�ֱ�������
�������˵����
����ֵ˵���� Ĭ��Ϊ0��1�ǽ���
=============================================================================*/
DWORD WINAPI ThreadFun(LPVOID pM)  
{  
	if (pM == NULL)
	{
		return 0;
	}
	CDesktopCapture* pMain=(CDesktopCapture*)pM;
	struct gdigrab *gdigrab = (struct gdigrab *)g_avFormatatContentx.priv_data;  
	int nIn=30;
	if(pMain==NULL)
	{
		return 0;
	}

	while(pMain->m_bIsStart)
	{
		if(!pMain->GetIsRunning())
		{
			return 1;
		}
		nIn=gdigrab->framerate.den-1;
		if(nIn<10)
		{
			nIn=10;
		}

		LONGLONG   t2; 
		QueryPerformanceCounter((LARGE_INTEGER   *)&t2); 
		LONGLONG ndelay1=0;
		int nDelayinf=nIn;
		if(g_nCpuPerial>0)
		{
			ndelay1=(t2 -g_nLastCpuPerial )*1000/g_nCpuPerial;
			
		}
		//char ch[200]={0};

		MySleep(nIn);

		pMain->CallbackToUI();
		g_nLastCpuPerial=t2;
	}



	return 0;
}
/*=============================================================================
������		 MsgThreadFun
����		�� ��ʱ�ص�
�㷨ʵ��	������ѡ�
����ȫ�ֱ�������
�������˵����
����ֵ˵���� Ĭ��Ϊ0��1�ǽ���
=============================================================================*/
DWORD WINAPI MsgThreadFun(LPVOID pM)  
{  
	MSG msg;
	CDesktopCapture* pMain = (CDesktopCapture*)pM;

	while (pMain->GetIsRunning())
	{
		if (GetMessage(&msg, 0, 0, 0))
		{
			if (msg.message == MESSAGE_POST_TO_UI)
			{
				if (pM == NULL)
				{
					return 0;
				}

				struct gdigrab *gdigrab = (struct gdigrab *)g_avFormatatContentx.priv_data;
				int nIn = 30;
				if (pMain == NULL)
				{
					return 0;
				}

			if (pMain->m_bIsStart)
			{
				if (pMain->GetIsRunning())
				{
					pMain->CallbackToUI();
				}
			}
		}

			//DispatchMessage(&msg);
		}
		
		
	

	}
	
    return 0;  
}  


/*=============================================================================
������		 Create
����		�� ��ʼ������
�㷨ʵ��	������ѡ�
����ȫ�ֱ�������
�������˵����
����ֵ˵���� Ĭ��Ϊ0��
=============================================================================*/
int CDesktopCapture::Create()
{
	g_dwIndex=0;


	struct gdigrab *gdigrab = (struct gdigrab *)g_avFormatatContentx.priv_data;  
   
	gdigrab_read_header(&g_avFormatatContentx);

	//09-15 add for lower cpu rate
	if (IsAeroEnabled())
	{
		g_nTimeCapture = MIN_CAPTURE_TIMER;
	}
	else
	{
		g_nTimeCapture = 20;//1.5 * MIN_CAPTURE_TIMER;
	}
	m_bIsEndChange = true;
    g_bScreenChange=false;

    m_bIsStart = true;
	m_handleBack = CreateThread(NULL, 0, MsgThreadFun, this, CREATE_SUSPENDED, &m_dwThreadId);
	//m_handleBack = _beginthreadex(NULL, 0, MsgThreadFun, this, CREATE_SUSPENDED, &m_dwThreadId);
	SetThreadPriority(m_handleBack, THREAD_PRIORITY_TIME_CRITICAL);
	ResumeThread(m_handleBack);

	m_handleCapture = CreateThread(NULL, 0, SendDesktopTimer, this, CREATE_SUSPENDED, NULL);
	SetThreadPriority(m_handleCapture, THREAD_PRIORITY_TIME_CRITICAL);
	ResumeThread(m_handleCapture);

	QueryPerformanceFrequency((LARGE_INTEGER   *)&g_nCpuPerial);//ѯ��ϵͳһ���ӵ�Ƶ�� 
	


	return 0;
}

/*=============================================================================
������		 CpTheCaptureMemory
����		�� �����ɼ�����
�㷨ʵ��	������ѡ�
����ȫ�ֱ�������
�������˵����
����ֵ˵���� �Ƿ�ɹ���
=============================================================================*/

bool CDesktopCapture::CpTheCaptureMemory()
{
	bool bRet=false;
	if(g_pDesktopYuvBuf)
	{
		CAutoLock  csLock(&m_csDB);
		if(g_pRetDesktopYuvBuf )
		{
			if(g_pDesktopYuvBuf)
			{
	            memcpy_s(g_pRetDesktopYuvBuf,m_nRGBtoYUVWidth *m_nRGBtoYUVHeight*1.5,g_pDesktopYuvBuf,m_nRGBtoYUVWidth *m_nRGBtoYUVHeight*1.5);
				//memcpy_s(g_pRetDesktopYuvBuf,g_gdiInfo.width *g_gdiInfo.height*1.5,g_pDesktopYuvBuf,g_gdiInfo.width *g_gdiInfo.height*1.5);
			}
		}
			
			bRet =true;	
		}
	return bRet;
}
/*=============================================================================
������		 CallbackToUI
����		�� �ص����ϲ�
�㷨ʵ��	������ѡ�
����ȫ�ֱ�������
�������˵����
����ֵ˵���� �ޣ�
=============================================================================*/

void CDesktopCapture::CallbackToUI()
{
	//�м�ɼ�����Щͼ��ת������,��Ҫ����
	if(!m_bIsEndChange)
	{
		OutputDebugString("CallbackToUI --diuq----\n");
		return ;
	}

	LONGLONG   t1; 
	QueryPerformanceCounter((LARGE_INTEGER   *)&t1); 
	
	int nDelayinf=0;

	if(m_pVedioNetCB && m_bIsStart)
	{
		if(g_pDesktopYuvBuf)
		{
			if(CpTheCaptureMemory())
			{
				//�ص�ʱ������ת���Ŀ�ߣ�����ʹ�����õĿ��
	             (*m_pVedioNetCB)(g_pRetDesktopYuvBuf, m_nRGBtoYUVWidth *m_nRGBtoYUVHeight*1.5,m_nRGBtoYUVWidth ,m_nRGBtoYUVHeight,m_dwContext,m_CallbackType);
			}
		}
	}
	LONGLONG   t2; 
	QueryPerformanceCounter((LARGE_INTEGER   *)&t2); 
	if(g_nCpuPerial>0)
	{
		nDelayinf=(t2 -t1 )*1000/g_nCpuPerial;
			
	}

	#if 0
	FILE * fTest=NULL;
	fopen_s(&fTest,"d:\\test.txt", "a+");
	if(fTest!=NULL)//fopen_s(&fTest,"D:\\tt.txt", "a+"))//
	{
		char chMsg[Max_TempCharLength]={0};
		sprintf_s(chMsg,"CallbackToUI��ǰִ�к�ʱ:%d\n",nDelayinf);
		fwrite(chMsg, 1, strlen(chMsg), fTest);
				
		fflush(fTest);
		fclose(fTest);
	}
	fTest = NULL;
#endif
}

/*
���window������ʾ����ʾѡ�񷽰�����
*/
bool CDesktopCapture::FindAeroTipWindow()
{
	HWND hwnd = FindWindow(_T("#32770"), _T("Windows"));
	if(hwnd)
	{
		PostMessage(hwnd,WM_QUIT,0,0);
	}
	return true;
}

void SaveToBmp(int nIndex, int nWidth,unsigned char*pData,int nLen)
{
	char buffer[MAX_PATH  + 1] = { 0 };
	GetCurrentDir(buffer);
	char chFile[MAX_PATH + Max_TempCharLength + 1] = { 0 };
	sprintf_s(chFile, "%s\\bmp\\testXGA%d_%d.bmp", buffer, nIndex, nWidth);

	//WriteToLog(chFile,strlen(chFile));
	if (nIndex <= 30 || nIndex == 40 || nIndex == 50 || nIndex == 10260 || nIndex == 10600)
	{
		//WriteToLog(_T("open file start\n"), 17);
		FILE* fw = 0;

		errno_t errT = fopen_s(&fw, chFile, "wb+");
		if(errT!=0)
		{
			/*char chError[Max_TempCharLength] = { 0 };
			sprintf_s(chError, "Open file error:%d\n", errT);
			WriteToLog(chError, strnlen_s(chError, Max_TempCharLength));*/
			return;
		}
		if (fw != NULL)
		{
			if (pData != NULL)
			{
				fwrite(pData, 1, nLen, fw);
			}
			fclose(fw);
		}
	}



}

/*=============================================================================
������		 CaptureScreen
����		�� ��������
�㷨ʵ��	������ѡ�
����ȫ�ֱ�������
�������˵����
����ֵ˵���� Ĭ��Ϊ0,1-ֹͣ��2-�ɼ�����3-�ɼ��ֱ��ʲ�һ�£�4ת������5-data error,11-�ֱ��ʱ仯��12���ݲ���
=============================================================================*/

int CDesktopCapture::CaptureScreen()
{
	char chMsg[Max_TempCharLength] = { 0 };

	//��ǰץ����ʽ�����õ�ץ����ʽ��һ��
	if (m_emCurGrabMode != g_emGrabMode)
	{
		ResizeDestop();
		m_emCurGrabMode = g_emGrabMode;
		sprintf_s(chMsg, Max_TempCharLength, "��ǰץ����ʽ�ı�:%d\n", m_emCurGrabMode);
		WriteToLog(chMsg, strnlen_s(chMsg, Max_TempCharLength));
		return 13;
	}

	if (!m_bIsStart)
	{
		return 1;
	}
	struct gdigrab *gdigrab = (struct gdigrab *)g_avFormatatContentx.priv_data;
	if (gdigrab == NULL)
	{
		return 5;
	}
	//int nstartTime = GetTickCount();

	///////////////////mult display
	//if (g_bScreenChange)
	//{
		if (JudgeScreenChange())
		{
			return 11;
		}
//	}

	if(!m_bIsEndChange && m_nLostCount<max( SCREEN_MIN_LOST,gdigrab->framerate.num))
	{
		m_nLostCount++;
		g_dwIndex = 0;
		return 11;
	}
	else
	{
		m_nLostCount = 0;
		m_bIsEndChange = TRUE;

		g_bScreenChange = false;
	}


	LONGLONG   tbegin;
	QueryPerformanceCounter((LARGE_INTEGER   *)&tbegin);
	CAutoLock  csLock(&m_csDB);

	int nbmpLen = 0;
	if (g_emGrabMode == MODE_DXGI)
	{
		nbmpLen = dxgi_read_packet(&g_avFormatatContentx, &g_avPacket);
	}
	else
	{
		nbmpLen = gdigrab_read_packet(&g_avFormatatContentx, &g_avPacket);
	}

	LONGLONG   tcapure;
	QueryPerformanceCounter((LARGE_INTEGER   *)&tcapure);

#if _DEBUG
	if (g_nCpuPerial > 0)
	{
		int ndelay = (tcapure - tbegin) * 1000 / g_nCpuPerial;
		/*sprintf_s(chMsg, Max_TempCharLength, "read_packet:%d\n", ndelay);
		WriteToLog(chMsg, strnlen_s(chMsg, Max_TempCharLength));*/
	}
#endif



	if (nbmpLen == 0)
	{
		if (m_bDXInit)
		{
			sprintf_s(chMsg, Max_TempCharLength, "����û�л�ȡ�����ݣ�read_packet ���س���:%d\n", nbmpLen);
			WriteToLog(chMsg, strnlen_s(chMsg, Max_TempCharLength));
			return 2;
		}
		return 20;//����ʱ����ȡ����
	}
	RECT   clip_rect = gdigrab->clip_rect;


	//m_bIsEndChange= TRUE;
	//	CAutoLock  csLock(&m_csDB);
	if (NULL != g_pvPreProcHandle)
	{
		l32 nRet = VIDEO_SUCCESS;
		TImageRGBtoYUVInput  tPutIn = {0};
		TImageRGBtoYUVOutput tPutOut = {0};

		int bfOffBits = (int) sizeof(BITMAPFILEHEADER) +  
		                      sizeof(BITMAPINFOHEADER);
	
		unsigned char* m_pDesktopDibBuf = NULL;
		if(g_avPacket.data)
		{
		    m_pDesktopDibBuf = g_avPacket.data + bfOffBits;
		}
		else
		{
			sprintf_s(chMsg, Max_TempCharLength, "������ȡ������ָ��Ϊ��\n");
			WriteToLog(chMsg, strnlen_s(chMsg, Max_TempCharLength));
			return 12;
		}

		tPutIn.pu8SrcBAddr = m_pDesktopDibBuf;//m_pDesktopTestDibBuf;//m_pDesktopDibBuf;
		
		tPutOut.pu8DstYAddr = g_pDesktopYuvBuf;

		int nScrWidth = clip_rect.right - clip_rect.left;
        int nScrHeight= clip_rect.bottom - clip_rect.top;

		//�ж��Ƿ���4�ֽڶ���
		Align4Bytes(&nScrWidth, &nScrHeight);
		
	
		if(m_nRGBtoYUVWidth != nScrWidth || m_nRGBtoYUVHeight != nScrHeight)
		{
			sprintf_s(chMsg, Max_TempCharLength, "��⵽��Ļ�ֱ��ʷ����仯\n");
			WriteToLog(chMsg, strnlen_s(chMsg, Max_TempCharLength));
			return 3;
		}

		tPutOut.pu8DstUAddr = g_pDesktopYuvBuf +nScrWidth * nScrHeight;// m_gdiInfo.width *m_gdiInfo.height;
		tPutOut.pu8DstVAddr = g_pDesktopYuvBuf + nScrWidth * nScrHeight *5/4;// m_gdiInfo.width *m_gdiInfo.height*5/4;


		
		if (g_pvPreProcHandle && g_pDesktopYuvBuf)
		{
			if(g_pvPreProcHandle)
			{
				try
				{
					//����һ���жϣ��Ƿ�ı��˷ֱ���
					if(m_tImageRGBtoYUV.l32SrcWidth==nScrWidth && m_tImageRGBtoYUV.l32SrcHeight==nScrHeight )
					{
						
						if (g_pvPreProcHandle && tPutIn.pu8SrcBAddr)
						{
							nRet = ImageUnitProcess(g_pvPreProcHandle, &tPutIn, &tPutOut);
						}
						if (nRet != VIDEO_SUCCESS)
						{
							unsigned char *pMsg = new unsigned char[1024];
							ImageUnitAnalyzeErrorCode(g_pvPreProcHandle,nRet,1024,pMsg);

			

							delete[] pMsg;

							sprintf_s(chMsg, Max_TempCharLength, "bmp����ת����yuv��������\n");
							WriteToLog(chMsg, strnlen_s(chMsg, Max_TempCharLength));
							return 4;
						}
					}

				}
				catch (...) {
					sprintf_s(chMsg, Max_TempCharLength, "try��ȡ��������������\n");
					WriteToLog(chMsg, strnlen_s(chMsg, Max_TempCharLength));
					return 5;
				}
			}

			//��ת����Ҳ�����ת�����������⣬����Ƚ���ת�����ص�
			if(!m_bIsEndChange && m_nLostCount<max(SCREEN_MIN_LOST ,gdigrab->framerate.num))//SCREEN_MIN_LOST)//
			{
				m_nLostCount++;
			}
			else
			{
				//OutputDebugString("diuqzhong --end----%d\n");
				m_nLostCount=0;
				m_bIsEndChange= TRUE;

				//char chMsg[200] = { 0 };
				LONGLONG   tchange;
				QueryPerformanceCounter((LARGE_INTEGER   *)&tchange);
				if (g_nCpuPerial > 0)
				{
#if _Debug
					int ndelay = (tcapure - tcapure) * 1000 / g_nCpuPerial;
					/*sprintf_s(chMsg, Max_TempCharLength, "capure delay:%d\n", ndelay);
					WriteToLog(chMsg, strnlen_s(chMsg, Max_TempCharLength));*/
#endif
				}

			


				//�ص�ʱ������ת���Ŀ�ߣ�����ʹ�����õĿ��
			/*	if(m_pVedioNetCB)
				{
					(*m_pVedioNetCB)(g_pDesktopYuvBuf, m_nRGBtoYUVWidth *m_nRGBtoYUVHeight*1.5, m_nRGBtoYUVWidth, m_nRGBtoYUVHeight, m_dwContext, m_CallbackType);
				 }*/
			}
		
		}
		else
		{
			sprintf_s(chMsg, Max_TempCharLength, "����û�л�ȡ������\n");
			WriteToLog(chMsg, strnlen_s(chMsg, Max_TempCharLength));
			return 6;
		}

	}
	else
	{
		sprintf_s(chMsg, Max_TempCharLength, "�����ľ��Ϊ��\n");
		WriteToLog(chMsg, strnlen_s(chMsg, Max_TempCharLength));
		return 7;
	}

#if _DEBUG
	if(g_bIsBMP)
	{
		if (g_dwIndex >= 0)
		{
			g_dwIndex++;
		}
		SaveToBmp(g_dwIndex, clip_rect.right - clip_rect.left, g_avPacket.data, g_avPacket.size);

		////if (g_dwIndex <= 30 || g_dwIndex == 40 || g_dwIndex == 50 || g_dwIndex == 10260 || g_dwIndex == 10600)
		////{
		////	FILE* fw = 0;
		////	char chFile[30];
		////	sprintf_s(chFile, "c:\\testXGA%d_%d.bmp", g_dwIndex, clip_rect.right - clip_rect.left);

		////	fopen_s(&fw, chFile, "wb+");// "d:\\testXGA0.bmp", "wb+");
		////	if (fw != NULL)
		////	{
		////		fwrite(g_avPacket.data, 1, g_avPacket.size, fw);
		////		fclose(fw);
		////	}
		////}
		if(g_dwIndex>10000)
		{
			g_dwIndex=g_dwIndex;
		}
		if(g_dwIndex>20000)
		{
			//g_dwIndex=0;
			g_dwIndex = -1;
			g_bIsBMP=false;
		}
	}
#endif

	return 0;
}

//���òɼ�֡��
void CDesktopCapture::SetFrameRate(int nRate)
{
	if(nRate<=0)
	{
		return;
	}
	CAutoLock  csLock(&m_csDB);
	struct gdigrab *gdigrab1 = (gdigrab *)g_avFormatatContentx.priv_data; 
	if (gdigrab1 == NULL)
	{
		return;
	}
	gdigrab1->framerate.num=nRate;// .strict_std_compliance ->duration
	gdigrab1->framerate.den=1000/nRate;


#if 0
	FILE * fTest=NULL;
	fopen_s(&fTest,"d:\\test.txt", "a+");
	if(fTest!=NULL)//fopen_s(&fTest,"D:\\tt.txt", "a+"))//
	{
		char chMsg[Max_TempCharLength]={0};
		sprintf_s(chMsg,"����֡��:%d,den:%d\n",nRate,gdigrab1->framerate.den);
		fwrite(chMsg, 1, strlen(chMsg), fTest);
				
		fflush(fTest);
		fclose(fTest);
	}
	fTest = NULL;
#endif
}

bool CDesktopCapture::GetIsRunning()
{
	return m_bIsStart;
}

void CDesktopCapture::Stop()
{
	m_bIsStart=false;

	

	//10-23 �޸ģ���֤�ϲ㿽�����
	//MySleep(1000);
	MySleep(200);

	CAutoLock  csLock(&m_csDB);

	if (m_handleBack)
	{
		//SuspendThread(m_handleBack);
		PostThreadMessage(m_dwThreadId, MESSAGE_POST_TO_UI, 0, 0);
		CloseHandle(m_handleBack);
		//TerminateThread(m_handleBack, 0);
		m_handleBack = 0;
	}

	//10-23 �޸ģ���֤�ϲ㿽�����
	//MySleep(1000);
	if(m_handleCapture)
	{
		SuspendThread(m_handleCapture);
		CloseHandle(m_handleCapture);
		//TerminateThread(m_handleCapture, 0);
		m_handleCapture =0;
	}
	gdigrab_read_close(&g_avFormatatContentx);

	if (g_emGrabMode == MODE_DXGI)
	{
		DestroyDXGI();
	}
}

/*=============================================================================
������		 GetAllDisplay
����		�� ��ȡ���е���Ļ����
�㷨ʵ��	������ѡ�
����ȫ�ֱ�����g_tdispInfo��Ļ����
�������˵����
����ֵ˵���� ��
=============================================================================*/
void GetAllDisplay()
{
	BOOL           bFlag            = true;
	int            dspNum           = 0;
	DISPLAY_DEVICE ddDisplay;
	DEVMODE        dmDevMode;

	if (g_bIsGetDisplay)
	{
		return;
	}
	g_bIsGetDisplay = true;
	ZeroMemory(&ddDisplay, sizeof(ddDisplay));
	ddDisplay.cb = sizeof(ddDisplay);
	ZeroMemory(&dmDevMode, sizeof(dmDevMode));
	dmDevMode.dmSize = sizeof(dmDevMode);

	char chLogtt[Max_TempCharLength * 3] = { 0 };
	int ndispIndex = 0;
	while (bFlag)
	{
		if (dspNum >= SCREEN_MAX_NUM)
		{
			break;
		}
    	 bFlag = EnumDisplayDevices(NULL, ndispIndex, &ddDisplay, 0);
		 if (bFlag)
		 {
			 //���������
			 //ȱ�ݣ���������л�ʱ������ֱ���һ�£����л�����Ҫ�ֶ�����
			 if (DISPLAY_DEVICE_PRIMARY_DEVICE & ddDisplay.StateFlags <= 0)
			 {
				 ZeroMemory(&dmDevMode, sizeof(ddDisplay));
				 ddDisplay.cb = sizeof(ddDisplay);
				 ndispIndex++;

				 //��⵽�ڶ����Կ�
				 sprintf_s(chLogtt, "GetAllDisplay��ȡ�ڶ����Կ���%s\n", ddDisplay.DeviceName);
				 WriteToLog(chLogtt, Max_TempCharLength);

				 continue;
			 }
			 ndispIndex++;

			 g_tdispInfo.aryddDisplay[dspNum] = ddDisplay;
			 bFlag = EnumDisplaySettings(ddDisplay.DeviceName, ENUM_CURRENT_SETTINGS, &dmDevMode);
			 if (bFlag)
			 {
				 g_tdispInfo.arydmDevMode[dspNum] = dmDevMode;
				 /*g_tdispInfo.arydmDevMode[dspNum].dmBitsPerPel = dmDevMode.dmBitsPerPel;
				 memcpy(g_tdispInfo.arydmDevMode[dspNum].dmDeviceName, dmDevMode.dmDeviceName, CCHDEVICENAME);
				 g_tdispInfo.arydmDevMode[dspNum].dmDisplayFlags = dmDevMode.dmDisplayFlags;
				 g_tdispInfo.arydmDevMode[dspNum].dmPelsHeight = dmDevMode.dmPelsHeight;
				 g_tdispInfo.arydmDevMode[dspNum].dmPelsWidth = dmDevMode.dmPelsWidth;*/
				 if (dmDevMode.dmPelsHeight <= 0 || dmDevMode.dmPelsWidth <= 0)
				 {
					 char chLog[Max_TempCharLength] = { 0 };
					 //DWORD dwError = GetLastError();
					 sprintf_s(chLog, "EnumDisplaySettings��ĵ�����Ϊ��,DeviceName %s,display dmDevMode:%d\n", ddDisplay.DeviceName, dmDevMode.dmPelsWidth);
					 WriteToLog(chLog, Max_TempCharLength);
					 break;
				 }
				 dspNum += 1;
			 }
			 else
			 {
				 if (dspNum <= 0)
				 {
					 char chLog[Max_TempCharLength] = { 0 };
					 //DWORD dwError = GetLastError();
					 sprintf_s(chLog, "EnumDisplaySettingsû�л����Ļ��Ϣ,DeviceName %s,display count:%d\n", ddDisplay.DeviceName, dspNum);
					 WriteToLog(chLog, Max_TempCharLength);
					 break;
				 }
			 }
		 }
		 else
		 {
			/* char chLog[Max_TempCharLength] = { 0 };
			 sprintf_s(chLog, "EnumDisplayDevices get display have error,display count:%d\n", dspNum);
			 WriteToLog(chLog, Max_TempCharLength);*/
		 }
		 
	}
	g_tdispInfo.nDeviceCount=dspNum;

	//2018-3-5 add ���û�м�⵽�Կ���Ĭ�ϸ���һ����ǰ��Ļ����֤�ܲɼ�������
	if (g_tdispInfo.nDeviceCount <= 0)
	{
		sprintf_s(g_tdispInfo.aryddDisplay[dspNum].DeviceName , 32,"display");
		RECT rect;
		HWND hh = GetDesktopWindow();
		GetClientRect(hh,&rect);
		g_tdispInfo.arydmDevMode[dspNum].dmPelsWidth = rect.right - rect.left;
		g_tdispInfo.arydmDevMode[dspNum].dmPelsHeight = rect.bottom - rect.top;
		g_tdispInfo.nDeviceCount = 1;
	}
	g_bIsGetDisplay = false;
}


int CDesktopCapture::GetDisplayInfo(TMonitorInfo*tMonitor)
{
	//int GetAllDisplay(TMonitorInfo*tMonitor);
	if (tMonitor == NULL)
	{
		return 1;
	}
	if(g_tdispInfo.nDeviceCount<=0)
	{
		GetAllDisplay();
	}
	if(tMonitor!=NULL)
	{
		TMonitorInfo*pMon=tMonitor;
		if(pMon!=NULL)
		{
			for(int i=0;i<g_tdispInfo.nDeviceCount;i++)
			{
				sprintf_s( pMon->chName,"%s",g_tdispInfo.aryddDisplay[i].DeviceName);
				pMon->nWidth=g_tdispInfo.arydmDevMode[i].dmPelsWidth;
				pMon->nHeight=g_tdispInfo.arydmDevMode[i].dmPelsHeight;
				pMon++;
			}
		}
	}

	return g_tdispInfo.nDeviceCount;
	
}
/*=============================================================================
������		 SelectCaptureScreen
����		�� �л��ɼ���Ļ
�㷨ʵ��	������ѡ�
����ȫ�ֱ�����g_tdispInfo��Ļ����
�������˵������Ļѡ��1-����
����ֵ˵���� �Ƿ�ɹ�
=============================================================================*/
bool CDesktopCapture::SelectCaptureScreen(int nNum)
{
	if(g_tdispInfo.nDeviceCount<=0)
	{
		GetAllDisplay();
	}
	if(nNum>g_tdispInfo.nDeviceCount)
	{
		return false;
	}
	if(m_bIsInit && g_nSelectScreenIndex!=nNum)
	{
		g_nSelectScreenIndex= nNum;
		ResizeDestop();
	}
	else
	{
		g_nSelectScreenIndex= nNum;
	}
	return true;
}

/*=============================================================================
������		 JudgeScreenChange
����		�� �ж��Ƿ�ֱ��ʸı�
�㷨ʵ��	������ѡ�
����ȫ�ֱ�����g_tdispInfo��Ļ����
�������˵������
����ֵ˵���� �Ƿ��л��ֱ���
=============================================================================*/
bool CDesktopCapture::JudgeScreenChange()
{

	LONGLONG   t1; 
    QueryPerformanceCounter((LARGE_INTEGER   *)&t1); 
	

	struct gdigrab *gdigrab = (struct gdigrab *)g_avFormatatContentx.priv_data;  
	GetAllDisplay();
	

	int nScrWidth  = 0; //GetSystemMetrics(SM_CXSCREEN); 
	int nScrHeight = 0; //GetSystemMetrics(SM_CYSCREEN);
	if(g_nSelectScreenIndex>g_tdispInfo.nDeviceCount)
	{
		g_nSelectScreenIndex=0;
	}

	if(g_nSelectScreenIndex<2)
	{
		nScrWidth  = g_tdispInfo.arydmDevMode[0].dmPelsWidth; 
		nScrHeight =  g_tdispInfo.arydmDevMode[0].dmPelsHeight; //GetSystemMetrics(SM_CYSCREEN); 
	}
	else
	{
		nScrWidth  = g_tdispInfo.arydmDevMode[1].dmPelsWidth; 
		nScrHeight =  g_tdispInfo.arydmDevMode[1].dmPelsHeight; //GetSystemMetrics(SM_CYSCREEN); 
	}


	/*if(nScrWidth>1920)
	{
		nScrWidth=1920;
	}
	if(nScrHeight>1080)
	{
		nScrHeight=1080;
	}*/
	if (nScrWidth>Max_Screen_Width)
	{
		nScrWidth = Max_Screen_Width;
	}
	if (nScrHeight>Max_Screen_Heigth)
	{
		nScrHeight = Max_Screen_Heigth;
	}

	

	#if _DEBUG
	char chLog[Max_TempCharLength]={0};
	sprintf_s(chLog,"JudgeScreenChange -- nScrWidth=%d,nScrHeight=%d\n",nScrWidth,nScrHeight);
	OutputDebugString(chLog);
	#endif

	//��ȡ����  
	bool bischange=false;

	int nyuvWidth = nScrWidth;
	int nyuvHeight = nScrHeight;

	if (nyuvWidth <=0 || nyuvHeight <= 0)
	{
		/*char chLog[Max_TempCharLength] = { 0 };
		sprintf_s(chLog, "JudgeScreenChange Get screen information-- nScrWidth=%d,nScrHeight=%d\n", nScrWidth, nScrHeight);
		WriteToLog(chLog, Max_TempCharLength);*/
		return bischange;
	}
	

	//�ж��Ƿ���4�ֽڶ���
	Align4Bytes(&nyuvWidth, &nScrHeight);


	if(nScrWidth !=gdigrab->width  || nScrHeight != gdigrab->height 
		|| m_nRGBtoYUVWidth != nyuvWidth || m_nRGBtoYUVHeight != nyuvHeight)
	{
		
		/*char chLog[Max_TempCharLength] = { 0 };
		sprintf_s(chLog, "JudgeScreenChange -- nScrWidth=%d,nScrHeight=%d\n", nScrWidth, nScrHeight);
		WriteToLog(chLog,Max_TempCharLength);*/
		
		bischange= true;
	}
	if(bischange)
	{
		ResizeDestop();
		m_bIsEndChange= FALSE;
		m_nLostCount=0;
	}

	LONGLONG   t2; 
    QueryPerformanceCounter((LARGE_INTEGER   *)&t2); 
	
	if(g_nCpuPerial>0)
	{
	int ndelay=(t2-t1 )*1000/g_nCpuPerial;;
	#if _DEBUG
	char chLogDelay[Max_TempCharLength]={0};
	sprintf_s(chLogDelay,"JudgeScreenChange -- ndelay=%d-height:%d\n",ndelay,nScrHeight);
	OutputDebugString(chLogDelay);
	#endif

	#if 0
	FILE * fTest=NULL;
	fopen_s(&fTest,"d:\\test.txt", "a+");
	if(fTest!=NULL)//fopen_s(&fTest,"D:\\tt.txt", "a+"))//
	{
		char chMsg[Max_TempCharLength]={0};
		sprintf_s(chMsg,"JudgeScreenChange:%d,\n",ndelay);
		fwrite(chMsg, 1, strlen(chMsg), fTest);
				
		fflush(fTest);
		fclose(fTest);
	}
	fTest = NULL;
#endif

	}
	return bischange;
}

/*=============================================================================
������		 JudgeIsWin7Vista
����		�� �ж��Ƿ�win7����vista
�㷨ʵ��	������ѡ�
����ȫ�ֱ�����
�������˵������
����ֵ˵���� �Ƿ�win7
=============================================================================*/
bool CDesktopCapture::JudgeIsWin7Vista()
{
	bool bisWin7Vista = false;

	OSVERSIONINFOEXW osvi = { 0 };
	DWORDLONG dwlConditionMask = 0;

	// 1����ʼ��ϵͳ�汾��Ϣ���ݽṹ
	ZeroMemory(&osvi, sizeof(osvi));
	osvi.dwOSVersionInfoSize = sizeof(osvi);
	osvi.dwMajorVersion = 6;
	osvi.dwMinorVersion = 0;

	BOOL bVista = VerifyVersionInfoW(&osvi, VER_MAJORVERSION | VER_MINORVERSION, dwlConditionMask);
	osvi.dwMajorVersion = 6;
	osvi.dwMinorVersion = 1;
	BOOL bWin7 = VerifyVersionInfoW(&osvi, VER_MAJORVERSION | VER_MINORVERSION, dwlConditionMask);
	
	if (bVista || bWin7)
	{
		bisWin7Vista = true;
	}

	return bisWin7Vista;
}

/*=============================================================================
������		 JudgeIsWin8OrLater
����		�� �ж��Ƿ�win8�Ժ�Ĳ���ϵͳ
�㷨ʵ��	������ѡ�
����ȫ�ֱ�����
�������˵������
����ֵ˵���� �Ƿ�win8�Ժ�Ĳ���ϵͳ
=============================================================================*/
bool CDesktopCapture::JudgeIsWin8OrLater()
{
	bool bIsWin8OrLater = false;

	OSVERSIONINFO osvi;
	ZeroMemory(&osvi, sizeof(OSVERSIONINFO));
	osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
	GetVersionEx(&osvi);

	// �ж�ϵͳ���

	if ( (osvi.dwMajorVersion > 6) ||
		(osvi.dwMajorVersion == 6) && (osvi.dwMinorVersion >= 2) )    //win8����
	{
		bIsWin8OrLater = true;
	}

	return bIsWin8OrLater;
}

/*=============================================================================
������		 InvalidAero
����		�� ��Чwindow��Aero
�㷨ʵ��	������ѡ�
����ȫ�ֱ�����
�������˵������
����ֵ˵���� �Ƿ�ɹ�
=============================================================================*/
bool CDesktopCapture::InvalidAero()
{
	bool bResult = false;
	if (!JudgeIsWin7Vista())
	{
		return bResult;
	}

	HMODULE library = ::LoadLibrary("dwmapi.dll");

	if (0 != library)
	{
		fpIsCompositionEnabled tmpGetEnb = (fpIsCompositionEnabled)::GetProcAddress(library,
			"DwmIsCompositionEnabled");
		if (tmpGetEnb)
		{
			BOOL bIsEn = FALSE;
			HRESULT hEnable = (*tmpGetEnb)(&bIsEn);
			if (SUCCEEDED(hEnable))
			{
				if (bIsEn)
				{
					fpDwmEnableComposition tmpEnbFun = (fpDwmEnableComposition)::GetProcAddress(library,
						"DwmEnableComposition");
					HRESULT hRes = (*tmpEnbFun)(0);
					if (SUCCEEDED(hRes))
					{
						bResult = true;
					}
				}
			}
		
		}

		::FreeLibrary(library);
	}
	return bResult;
}


/*=============================================================================
������		 IsAeroEnabled
����		�� �Ƿ�����window��Aero
�㷨ʵ��	������ѡ�
����ȫ�ֱ�����
�������˵������
����ֵ˵���� �Ƿ�ɹ�
=============================================================================*/
bool CDesktopCapture::IsAeroEnabled()
{
	bool bResult = false;
	if (!JudgeIsWin7Vista())
	{
		return bResult;
	}

	HMODULE library = ::LoadLibrary("dwmapi.dll");

	if (0 != library)
	{
		fpIsCompositionEnabled tmpGetEnb = (fpIsCompositionEnabled)::GetProcAddress(library,
			"DwmIsCompositionEnabled");
		if (tmpGetEnb)
		{
			bResult = true;
		
		}

		::FreeLibrary(library);
	}
	return bResult;
}

//��ʼ���ڴ�
int  CDesktopCapture::InitConstData()
{
	struct gdigrab *gdigrab = (struct gdigrab *)g_avFormatatContentx.priv_data;
	if (gdigrab == NULL)
	{
		return 1;
	}

	int file_size = gdigrab->header_size + Max_Screen_Width * 3 * Max_Screen_Heigth * 1;//  gdigrab->frame_size;  

	int dwLen = Max_Screen_Width * Max_Screen_Heigth * 4 +
		sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);


	if (g_pDesktopYuvBuf)
	{
		delete[] g_pDesktopYuvBuf;
		g_pDesktopYuvBuf = NULL;
	}
	g_pDesktopYuvBuf = new unsigned char[dwLen];
	if (g_pDesktopYuvBuf == NULL)
	{
		char chError[Max_TempCharLength] = { 0 };
		sprintf_s(chError, "����YUV�ڴ�ʧ��\n");
		WriteToLog(chError, strnlen_s(chError, Max_TempCharLength));
		return 2;
	}

	if (g_pRetDesktopYuvBuf)
	{
		delete[] g_pRetDesktopYuvBuf;
		g_pRetDesktopYuvBuf = NULL;
	}
	g_pRetDesktopYuvBuf = new unsigned char[dwLen];
	if (g_pRetDesktopYuvBuf == NULL)
	{
		char chError[Max_TempCharLength] = { 0 };
		sprintf_s(chError, "����ص�yuv���ݿռ�ʧ��\n");
		WriteToLog(chError, strnlen_s(chError, Max_TempCharLength));
		return 3;
	}


	////�½�һ��AVPacket  
	int nVal = av_new_packet(&g_avPacket, file_size);
	//if (av_new_packet(&g_avPacket, file_size) < 0)
	if (nVal > 0)
	{
		char chError[Max_TempCharLength] = { 0 };
		sprintf_s(chError, "��ʼ�����������ڴ�packetʧ��\n");
		WriteToLog(chError, strnlen_s(chError, Max_TempCharLength));
		return 10;
	}

	//m_handleBack = CreateThread(NULL, 0, MsgThreadFun, this, CREATE_SUSPENDED, &m_dwThreadId);
	//m_handleBack = _beginthreadex(NULL, 0, MsgThreadFun, this, CREATE_SUSPENDED, &m_dwThreadId);
	//SetThreadPriority(m_handleBack, THREAD_PRIORITY_TIME_CRITICAL);
	//ResumeThread(m_handleBack);
	//m_bIsStart = true;
	//m_handleBack = CreateThread(NULL, 0, MsgThreadFun, this, 0, &m_dwThreadId);

	return 0;
}

/*=============================================================================
������		 InitDXGI
����		�� ��ʼ��DXGI
�㷨ʵ��	������ѡ�
����ȫ�ֱ�����
�������˵������
����ֵ˵���� �Ƿ�ɹ�
=============================================================================*/
bool CDesktopCapture::InitDXGI()
{
	CAutoLock  csLock(&m_csDB);

	char chLog[Max_TempCharLength] = { 0 };
    HRESULT hr = S_OK;

	if (m_bDXInit)
	{
		return FALSE;
	}

    // Driver types supported
    D3D_DRIVER_TYPE DriverTypes[] =
    {
        D3D_DRIVER_TYPE_HARDWARE,
        D3D_DRIVER_TYPE_WARP,
        D3D_DRIVER_TYPE_REFERENCE,
    };
    UINT NumDriverTypes = ARRAYSIZE(DriverTypes);

    // Feature levels supported
    D3D_FEATURE_LEVEL FeatureLevels[] =
    {
        D3D_FEATURE_LEVEL_11_0,
        D3D_FEATURE_LEVEL_10_1,
        D3D_FEATURE_LEVEL_10_0,
        D3D_FEATURE_LEVEL_9_1
    };
    UINT NumFeatureLevels = ARRAYSIZE(FeatureLevels);
    D3D_FEATURE_LEVEL FeatureLevel;

    //
    // Create D3D device
    //
    for (UINT DriverTypeIndex = 0; DriverTypeIndex < NumDriverTypes; ++DriverTypeIndex)
    {
        hr = D3D11CreateDevice(NULL, DriverTypes[DriverTypeIndex], NULL, 0, FeatureLevels, NumFeatureLevels, D3D11_SDK_VERSION, &m_hDevice, &FeatureLevel, &m_hContext);

        if (SUCCEEDED(hr))
        {
            break;
        }
    }

    if (FAILED(hr))
    {
		sprintf_s(chLog, Max_TempCharLength, "Create D3D device failed\n");
		WriteToLog(chLog, Max_TempCharLength);
        return FALSE;
    }

    //
    // Get DXGI device
    //
    IDXGIDevice *hDxgiDevice = NULL;
    hr = m_hDevice->QueryInterface(__uuidof(IDXGIDevice), reinterpret_cast<void**>(&hDxgiDevice));
    if (FAILED(hr))
    {
		sprintf_s(chLog, Max_TempCharLength, "Get DXGI device failed\n");
		WriteToLog(chLog, Max_TempCharLength);
        return FALSE;
    }

    //
    // Get DXGI adapter
    //
    IDXGIAdapter *hDxgiAdapter = NULL;
    hr = hDxgiDevice->GetParent(__uuidof(IDXGIAdapter), reinterpret_cast<void**>(&hDxgiAdapter));
	RESET_OBJECT(hDxgiDevice);
    if (FAILED(hr))
    {
		sprintf_s(chLog, Max_TempCharLength, "Get DXGI adapter failed\n");
		WriteToLog(chLog, Max_TempCharLength);
        return FALSE;
    }

    //
    // Get output
    //
    INT nOutput = 0;
    IDXGIOutput *hDxgiOutput = NULL;
    hr = hDxgiAdapter->EnumOutputs(nOutput, &hDxgiOutput);
    RESET_OBJECT(hDxgiAdapter);
    if (FAILED(hr))
    {
		sprintf_s(chLog, Max_TempCharLength, "Get output failed\n");
		WriteToLog(chLog, Max_TempCharLength);
        return FALSE;
    }

    //
    // get output description struct
    //
    hDxgiOutput->GetDesc(&m_dxgiOutDesc);

    //
    // QI for Output 1
    //
    IDXGIOutput1 *hDxgiOutput1 = NULL;
    hr = hDxgiOutput->QueryInterface(__uuidof(hDxgiOutput1), reinterpret_cast<void**>(&hDxgiOutput1));
    RESET_OBJECT(hDxgiOutput);
    if (FAILED(hr))
    {
		sprintf_s(chLog, Max_TempCharLength, "QI for Output 1 failed\n");
		WriteToLog(chLog, Max_TempCharLength);
        return FALSE;
    }

    //
    // Create desktop duplication
    //
    hr = hDxgiOutput1->DuplicateOutput(m_hDevice, &m_hDeskDupl);
    RESET_OBJECT(hDxgiOutput1);
    if (FAILED(hr))
    {
		sprintf_s(chLog, Max_TempCharLength, "Create desktop duplication failed:%d\n", hr);
		WriteToLog(chLog, Max_TempCharLength);
        return FALSE;
    }

	m_bDXInit = TRUE;
    return TRUE;
}

void CDesktopCapture::DestroyDXGI()
{
	CAutoLock  csLock(&m_csDB);

	if (!m_bDXInit)
	{
		return;
	}

	m_bDXInit = FALSE;

	RESET_OBJECT(m_hDeskDupl);
	RESET_OBJECT(m_hDevice);
	RESET_OBJECT(m_hContext);

	MySleep(200);
}

bool CDesktopCapture::AttatchToThread()
{
	HDESK hCurrentDesktop = OpenInputDesktop(0, FALSE, GENERIC_ALL);
	if (!hCurrentDesktop)
	{
		return FALSE;
	}

	// Attach desktop to this thread
	BOOL bDesktopAttached = SetThreadDesktop(hCurrentDesktop);
	CloseDesktop(hCurrentDesktop);
	hCurrentDesktop = NULL;

	//DestroyDXGIʱ�������³�ʼ��
	InitDXGI();

	return bDesktopAttached;
}

bool CDesktopCapture::QueryFrame(void* pImgData, INT& nImgSize)
{
	char chMsg[Max_TempCharLength] = { 0 };
	if (!AttatchToThread())
	{
		//����ʱ����ȡ������ʧ��
		if (m_bDXInit)
		{
			sprintf_s(chMsg, Max_TempCharLength, "OpenInputDesktop failed\n");
			WriteToLog(chMsg, strnlen_s(chMsg, Max_TempCharLength));
		}
		DestroyDXGI();
		return FALSE;
	}
	struct gdigrab *gdigrab1 = (gdigrab *)(&g_avFormatatContentx)->priv_data;

	IDXGIResource* hDesktopResource = NULL;
	DXGI_OUTDUPL_FRAME_INFO FrameInfo;
	m_hDeskDupl->ReleaseFrame();
	HRESULT hr = m_hDeskDupl->AcquireNextFrame(CAPTURE_TIMEOUT, &FrameInfo, &hDesktopResource);
	if (FAILED(hr))
	{
		//
		// ��һЩwin10��ϵͳ��,�������û�б仯������£�
		// ����ᷢ����ʱ���󣬵����Ⲣ���Ƿ����˴��󣬶���ϵͳ�Ż���ˢ�¶������µġ�
		// ���ԣ�����û��Ҫ����FALSE�����ز����κ����ݵ�TRUE����
		//
		
		if (g_bPrtSwitchOn)
		{
			sprintf_s(chMsg, Max_TempCharLength, "AcquireNextFrame timeout\n");
			WriteToLog(chMsg, strnlen_s(chMsg, Max_TempCharLength));
		}

		gdigrab1->draw_mouse = false;
		return TRUE;
	}

	if (FrameInfo.PointerPosition.Visible == true)
	{//����ƶ�
		g_tMouseStatus.LastMousePosition.x = FrameInfo.PointerPosition.Position.x;
		g_tMouseStatus.LastMousePosition.y = FrameInfo.PointerPosition.Position.y;
		g_tMouseStatus.bJudgeNextMousePos = false;
		g_tMouseStatus.bNextMousePosChanged = false;
	}
	else
	{//����϶����ڻ�ֹ
		g_tMouseStatus.bJudgeNextMousePos = true;
	}

	//����϶�Ӧ�ô���ʱ�����ٻ������
	if (g_tMouseStatus.bNextMousePosChanged)
	{
		gdigrab1->draw_mouse = false;
	}
	else
	{
		gdigrab1->draw_mouse = true;
	}

	if (g_bPrtSwitchOn)
	{
		sprintf_s(chMsg, Max_TempCharLength, "AccumulatedFrames: %d\n", FrameInfo.AccumulatedFrames);
		WriteToLog(chMsg, strnlen_s(chMsg, Max_TempCharLength));
	}

	//
	// query next frame staging buffer
	//
	ID3D11Texture2D* hAcquiredDesktopImage = NULL;
	hr = hDesktopResource->QueryInterface(__uuidof(ID3D11Texture2D), reinterpret_cast<void**>(&hAcquiredDesktopImage));
	RESET_OBJECT(hDesktopResource);
	if (FAILED(hr))
	{
		sprintf_s(chMsg, Max_TempCharLength, "AcquiredDesktopImage failed\n");
		WriteToLog(chMsg, strnlen_s(chMsg, Max_TempCharLength));
		return FALSE;
	}

	//
	// copy old description
	//
	D3D11_TEXTURE2D_DESC frameDescriptor;
	hAcquiredDesktopImage->GetDesc(&frameDescriptor);

	//
	// create a new staging buffer for fill frame image
	//
	ID3D11Texture2D* hNewDesktopImage = NULL;
	frameDescriptor.Usage = D3D11_USAGE_STAGING;
	frameDescriptor.CPUAccessFlags = D3D11_CPU_ACCESS_READ;
	frameDescriptor.BindFlags = 0;
	frameDescriptor.MiscFlags = 0;
	frameDescriptor.MipLevels = 1;
	frameDescriptor.ArraySize = 1;
	frameDescriptor.SampleDesc.Count = 1;
	hr = m_hDevice->CreateTexture2D(&frameDescriptor, NULL, &hNewDesktopImage);
	if (FAILED(hr))
	{
		RESET_OBJECT(hAcquiredDesktopImage);
		m_hDeskDupl->ReleaseFrame();
		sprintf_s(chMsg, Max_TempCharLength, "CreateTexture2D failed\n");
		WriteToLog(chMsg, strnlen_s(chMsg, Max_TempCharLength));
		return FALSE;
	}

	//
	// copy next staging buffer to new staging buffer
	//
	m_hContext->CopyResource(hNewDesktopImage, hAcquiredDesktopImage);
	RESET_OBJECT(hAcquiredDesktopImage);
	//m_hDeskDupl->ReleaseFrame();

	//
	// create staging buffer for map bits
	//
	IDXGISurface* hStagingSurf = NULL;
	hr = hNewDesktopImage->QueryInterface(__uuidof(IDXGISurface), (void**)(&hStagingSurf));
	RESET_OBJECT(hNewDesktopImage);
	if (FAILED(hr))
	{
		sprintf_s(chMsg, Max_TempCharLength, "Greate staging buffer for map bits failed\n");
		WriteToLog(chMsg, strnlen_s(chMsg, Max_TempCharLength));
		return FALSE;
	}

	//
	// copy bits to user space
	//
	DXGI_MAPPED_RECT mappedRect;
	hr = hStagingSurf->Map(&mappedRect, DXGI_MAP_READ);
	if (SUCCEEDED(hr))
	{
		if (g_bPrtSwitchOn)
		{ 
			sprintf_s(chMsg, Max_TempCharLength, "nImgSize:%d, nCaptureSize:%d, Pitch:%d\n",
				nImgSize, mappedRect.Pitch*m_dxgiOutDesc.DesktopCoordinates.bottom, mappedRect.Pitch);
			WriteToLog(chMsg, strnlen_s(chMsg, Max_TempCharLength));
		}

		// DXGIץ���������ͺŵ����ڴ�Ϊ4�ֽڶ���
		if (mappedRect.Pitch * m_dxgiOutDesc.DesktopCoordinates.bottom != nImgSize)
		{
			sprintf_s(chMsg, Max_TempCharLength, "Mapped bits pitch is:%d\n", mappedRect.Pitch);
			WriteToLog(chMsg, strnlen_s(chMsg, Max_TempCharLength));
			g_bAlign4Bytes = true;
			m_bMapBitsChanged = true;
			ResizeDestop();
			return FALSE;
		}

		memcpy(pImgData, mappedRect.pBits, nImgSize);
		hStagingSurf->Unmap();
	}

	RESET_OBJECT(hStagingSurf);
	return SUCCEEDED(hr);
}

int CDesktopCapture::dxgi_read_packet(AVFormatContext* s1, AVPacket* pkt)
{
	char chMsg[Max_TempCharLength] = { 0 };
	if (s1 == NULL)
	{
		return 0;
	}

	struct gdigrab* gdigrab = (struct gdigrab*)s1->priv_data;
	if (gdigrab == NULL)
	{
		return 0;
	}

	//��ȡ����  
	HDC        dest_hdc = gdigrab->dest_hdc;
	HDC        source_hdc = gdigrab->source_hdc;
	RECT       clip_rect = gdigrab->clip_rect;
	//int64_t    time_frame = gdigrab->time_frame;

	BITMAPFILEHEADER bfh;
	int file_size = gdigrab->header_size + gdigrab->frame_size;

	int64_t curtime;//, delay;  
	curtime = GetTickCount();
	pkt->pts = curtime; // 0;//

	/* Run Window message processing queue */
	if (gdigrab->show_region)
		gdigrab_region_wnd_update(s1, gdigrab);

	//�ж��Ƿ���4�ֽڶ���
	int nScrWidth = (int)(gdigrab->width);
	bool bIs4Byte = Align4Bytes(&nScrWidth, 0);
	int nLeft = 0;
	if (bIs4Byte)
	{
		//����󣬾�����ʾ
		nLeft = nScrWidth - (clip_rect.right - clip_rect.left);
		nLeft = nLeft / 2;
	}
	else
	{
	}

	//��ȡ��������
	if (!QueryFrame(gdigrab->buffer, gdigrab->frame_size))
	{
		if (m_bDXInit)
		{
			sprintf_s(chMsg, Max_TempCharLength, "DXGI QueryFrame error\n");
			WriteToLog(chMsg, strnlen_s(chMsg, Max_TempCharLength));
		}
		
		return 0;
	}

	//�����ָ�룿  
	if (gdigrab->draw_mouse)
		paint_mouse_pointer(s1, gdigrab);

	//�����ã�����ɫ
	if (bIs4Byte)
	{
		RECT sFillRect;
		sFillRect.left = nScrWidth - nLeft;
		sFillRect.right = clip_rect.left + nScrWidth;
		sFillRect.top = clip_rect.top;
		sFillRect.bottom = clip_rect.bottom;
		FillRect(dest_hdc, &sFillRect, g_sBrush);
	}

	/* Copy bits to packet data */
	//BMP�ļ�ͷBITMAPFILEHEADER  
	bfh.bfType = 0x4d42; /* "BM" in little-endian */
	bfh.bfSize = file_size;
	bfh.bfReserved1 = 0;
	bfh.bfReserved2 = 0;
	bfh.bfOffBits = gdigrab->header_size;
	//��AVPacket�п�������  
	//����BITMAPFILEHEADER  
	if (pkt->data == NULL)
	{

		sprintf_s(chMsg, Max_TempCharLength, "DXGI get dib data error,data is null\n");
		WriteToLog(chMsg, strnlen_s(chMsg, Max_TempCharLength));
		return 0;
	}
	memcpy(pkt->data, &bfh, sizeof(bfh));
	//����BITMAPINFOHEADER  
	memcpy(pkt->data + sizeof(bfh), &gdigrab->bmi.bmiHeader, sizeof(gdigrab->bmi.bmiHeader));
	//������  
	if (gdigrab->bmi.bmiHeader.biBitCount <= 8)
	{
		GetDIBColorTable(dest_hdc, 0, 1 << gdigrab->bmi.bmiHeader.biBitCount,
			(RGBQUAD*)(pkt->data + sizeof(bfh) + sizeof(gdigrab->bmi.bmiHeader)));
	}
	//������������  
	memcpy(pkt->data + gdigrab->header_size, gdigrab->buffer, gdigrab->frame_size);
	pkt->size = file_size;

	return gdigrab->header_size + gdigrab->frame_size;
}

/*=============================================================================
������		 SetPrtSwitchOn
����		�� ��ӡ����
�㷨ʵ��	������ѡ�
����ȫ�ֱ�����
�������˵����bPrtSwitchOn == true/false(����/�ر�)
����ֵ˵���� �Ƿ�ɹ�
=============================================================================*/
void CDesktopCapture::SetVidPrtSwitchOn(bool bPrtSwitchOn)
{
	CAutoLock  csLock(&m_csDB);

	char chMsg[Max_TempCharLength] = { 0 };
	sprintf_s(chMsg, Max_TempCharLength, "SetVidPrtSwitchOn:%d\n", bPrtSwitchOn);
	WriteToLog(chMsg, strnlen_s(chMsg, Max_TempCharLength));

	if (g_bPrtSwitchOn == bPrtSwitchOn)
	{
		return;
	}

	g_bPrtSwitchOn = bPrtSwitchOn;
}

/*=============================================================================
������		 SetGrabMode
����		�� ����ץ����ʽ
�㷨ʵ��	������ѡ�
����ȫ�ֱ�����
�������˵����emGrabMode ץ����ʽö��ֵ
����ֵ˵���� �Ƿ�ɹ�
=============================================================================*/
bool CDesktopCapture::SetGrabMode(EmGrabMode emGrabMode)
{
	CAutoLock  csLock(&m_csDB);

	//win7��ǰ����ϵͳ��֧��DXGI��ʽ��Ĭ��ΪGDIץ����ʽ
	if (!g_bIsWin8OrLater && emGrabMode == MODE_DXGI)
	{
		return false;
	}

	if (g_emGrabMode == emGrabMode)
	{
		return true;
	}

	g_emGrabMode = emGrabMode;
	return true;
}

/*=============================================================================
������		 GetGrabMode
����		�� ��ȡ��ǰץ����ʽ
�㷨ʵ��	������ѡ�
����ȫ�ֱ�����
�������˵����
����ֵ˵���� �Ƿ�ɹ�
=============================================================================*/
EmGrabMode CDesktopCapture::GetGrabMode()
{
	CAutoLock  csLock(&m_csDB);

	return m_emCurGrabMode;
}
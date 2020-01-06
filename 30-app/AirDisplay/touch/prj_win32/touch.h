
// touch.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


#include "setupapi.h"
#include "dbt.h"
extern "C"
{
#include "hidsdi.h"
}

#pragma comment(lib, "hid.lib")
#pragma comment(lib, "SetupAPI.lib")

#include "AVCollect.h"
#pragma comment(lib, "AVCollection.lib")
// CtouchApp:
// �йش����ʵ�֣������ touch.cpp
//

class CtouchApp : public CWinApp
{
public:
	CtouchApp();

// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

	bool IsAvAuthPassed();     //�Ƿ���Ȩ�޵��ÿ�����AVCollection.dll
	void GetZoomScaleValue();  //��ȡwinodws��������С��Ŵ����С�ı���������Ŀ����ֵ
	void CloseAutoPlayWindow();//�ر�windows�Զ����Ŵ���
	void SetDefaultFont();     //����Ĭ������

	DECLARE_MESSAGE_MAP()

public:
	bool m_bInstallYHFont;     //�Ƿ�װ��΢���ź�
};

BOOL OnlyStartOne();

extern CtouchApp theApp;

//��ӡ��Ϣ
API void help();

API void prt( u8 byLevel );

API void showdev();

API void showsize();

API void mdver();

API void showver();

API void datastatus();

API void cpuadjust();

API void screen( u32 byScreen );

API void sethwenc( BOOL32 bEnable );

API void setlang( u32 byLangID );

API void setvlogon( bool bPrtSwitchOn );

API void setgrabmode( EmGrabMode emGrabMode );

API void getgrabmode();

API void systeminfo();

// tservice.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CtserviceApp:
// �йش����ʵ�֣������ tservice.cpp
//

class CtserviceApp : public CWinApp
{
public:
	CtserviceApp();

// ��д
public:
	virtual BOOL InitInstance();
	int CreateRun(void);//������������ע���
// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CtserviceApp theApp;
BOOL OnlyStartOne();
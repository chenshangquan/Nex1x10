
// tservice.h : PROJECT_NAME 应用程序的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"		// 主符号


// CtserviceApp:
// 有关此类的实现，请参阅 tservice.cpp
//

class CtserviceApp : public CWinApp
{
public:
	CtserviceApp();

// 重写
public:
	virtual BOOL InitInstance();
	int CreateRun(void);//创建开机启动注册表
// 实现

	DECLARE_MESSAGE_MAP()
};

extern CtserviceApp theApp;
BOOL OnlyStartOne();
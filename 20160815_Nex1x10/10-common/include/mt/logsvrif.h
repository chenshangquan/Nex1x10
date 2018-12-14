/*=============================================================================================
ģ����   : logserver
�ļ���   : logsvrif.h
����     : ��־�������ӿ�ͷ�ļ�
����     : ruiyigen
��Ȩ     : <Copyright(C) 2003-2015 Suzhou Keda Technology Co., Ltd. All rights reserved.>
=============================================================================================*/
#ifndef _LOGSVRIF_H_
#define _LOGSVRIF_H_
#include <string>
#include "kdvtype.h"
#include "mtmacro.h"

namespace LOGSERVER {
	typedef struct tagTLogServerCfg
	{
		u16         wListenPort;
		std::string strLogFilePath;
		u32         dwMaxFileSize;         //unit kb
		u16         wMaxBackupNum;
	}TLogServerCfg;

MTCBB_API void LsStart(TLogServerCfg &tCfg);
MTCBB_API void LsEnableFileLog(BOOL32 bEnable);
} // namespace LOGSERVER

#endif // _LOGSVRIF_H_
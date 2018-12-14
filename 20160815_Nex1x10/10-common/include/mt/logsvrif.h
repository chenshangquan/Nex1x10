/*=============================================================================================
模块名   : logserver
文件名   : logsvrif.h
功能     : 日志服务器接口头文件
作者     : ruiyigen
版权     : <Copyright(C) 2003-2015 Suzhou Keda Technology Co., Ltd. All rights reserved.>
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
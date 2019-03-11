/*=============================================================================================
模块名   : logclient
文件名   : logcltif.h
功能     : 日志客户端接口头文件
作者     : ruiyigen
版权     : <Copyright(C) 2003-2015 Suzhou Keda Technology Co., Ltd. All rights reserved.>
=============================================================================================*/
#ifndef _LOGIF_H_
#define _LOGIF_H_
#include <string>
#include "kdvtype.h"
#include "nvmacro.h"

namespace LOGCLIENT {

	typedef struct tagTLogClientCfg
	{
		BOOL32      bToFileLogServer; //TRUE 文件日志输出到日志服务器，FALSE 文件日志输出到本地		

		//本地日志文件配置,bFileLogServer为FALSE时有效
		u16         wAppId;
		std::string strFilePath;
		u32         dwMaxFileSize;
		u16         wMaxBackupNum;

		//服务器配置，bFileLogServer为TRUE时有效
		std::string strSvrIp;
		u16         wSvrPort;
		std::string strCltTag; //用来区分不同的客户端
	} TLogClientCfg;

NVCBB_API BOOL32 LcInit(LOGCLIENT::TLogClientCfg &tCfg);

NVCBB_API BOOL32 LcRegLogger(std::string strLogger);

NVCBB_API void LcEnableFileLog(BOOL32 bEnable);

/*错误类型打印，不可屏蔽*/
NVCBB_API BOOL32 Error(std::string strMod, std::string strLogMsg);

NVCBB_API BOOL32 Warn(std::string strMod, std::string strLogMsg);

NVCBB_API BOOL32 Hint(std::string strMod, std::string strLogMsg);

/*调试类型打印，可通过命令屏蔽，不可输出到文件*/
NVCBB_API BOOL32 Debug(std::string strMod, std::string strLogMsg);

NVCBB_API BOOL32 NvLogOn(std::string strMod);
NVCBB_API BOOL32 NvLogOff(std::string strMod);

NVCBB_API BOOL32 NvDebugOn(std::string strMod);
NVCBB_API BOOL32 NvDebugOff(std::string strMod);

} // namespace LOGCLIENT

#endif // _LOGIF_H_
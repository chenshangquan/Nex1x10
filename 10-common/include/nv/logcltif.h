/*=============================================================================================
ģ����   : logclient
�ļ���   : logcltif.h
����     : ��־�ͻ��˽ӿ�ͷ�ļ�
����     : ruiyigen
��Ȩ     : <Copyright(C) 2003-2015 Suzhou Keda Technology Co., Ltd. All rights reserved.>
=============================================================================================*/
#ifndef _LOGIF_H_
#define _LOGIF_H_
#include <string>
#include "kdvtype.h"
#include "nvmacro.h"

namespace LOGCLIENT {

	typedef struct tagTLogClientCfg
	{
		BOOL32      bToFileLogServer; //TRUE �ļ���־�������־��������FALSE �ļ���־���������		

		//������־�ļ�����,bFileLogServerΪFALSEʱ��Ч
		u16         wAppId;
		std::string strFilePath;
		u32         dwMaxFileSize;
		u16         wMaxBackupNum;

		//���������ã�bFileLogServerΪTRUEʱ��Ч
		std::string strSvrIp;
		u16         wSvrPort;
		std::string strCltTag; //�������ֲ�ͬ�Ŀͻ���
	} TLogClientCfg;

NVCBB_API BOOL32 LcInit(LOGCLIENT::TLogClientCfg &tCfg);

NVCBB_API BOOL32 LcRegLogger(std::string strLogger);

NVCBB_API void LcEnableFileLog(BOOL32 bEnable);

/*�������ʹ�ӡ����������*/
NVCBB_API BOOL32 Error(std::string strMod, std::string strLogMsg);

NVCBB_API BOOL32 Warn(std::string strMod, std::string strLogMsg);

NVCBB_API BOOL32 Hint(std::string strMod, std::string strLogMsg);

/*�������ʹ�ӡ����ͨ���������Σ�����������ļ�*/
NVCBB_API BOOL32 Debug(std::string strMod, std::string strLogMsg);

NVCBB_API BOOL32 NvLogOn(std::string strMod);
NVCBB_API BOOL32 NvLogOff(std::string strMod);

NVCBB_API BOOL32 NvDebugOn(std::string strMod);
NVCBB_API BOOL32 NvDebugOff(std::string strMod);

} // namespace LOGCLIENT

#endif // _LOGIF_H_
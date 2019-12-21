/*****************************************************************************
模块名      : connectsuslib
文件名      : connectsus_api.h
相关文件    : connectsus_api.cpp
文件实现功能: 
作者        : 
版本        : V2.1  Copyright(C) 2011-2012 KDC, All rights reserved.
-----------------------------------------------------------------------------
修改记录:
日  期        版本        修改人      修改内容
2014/04/21    5.0
******************************************************************************/

#ifndef _CONNECT_SUS_API_H_
#define _CONNECT_SUS_API_H_

#include "kdvtype.h"
#include "structconnectsus.h"
#include "structsusdev.h"
#include "suserrcode.h"


#ifdef CONNECTSUS_DLL_EXPORT
#define	CONNECTSUS_API extern "C" __declspec( dllexport )
#else 
#define CONNECTSUS_API extern "C"
#endif


CONNECTSUS_API BOOL32 InitConSus();
CONNECTSUS_API BOOL32 QuitConSus();
CONNECTSUS_API BOOL32 CloseSus( void );

CONNECTSUS_API BOOL32 ConnectSus( const CSusNetParam& tNetParm, const CSusLoginInfo& tDevLogInfo, SusCallBackFunc tCallBackFunc );

// 获取推荐版本信息
CONNECTSUS_API BOOL32 GetRecommendVer( void );

//下载指定版本
CONNECTSUS_API BOOL32 LoadAssignedVer(u32 dwSn, const s8* szLoadPath);

//下载指定模块文件
CONNECTSUS_API BOOL32 LoadAssignedModule(u32 dwSn, const s8* szModuleName, const s8* szLoadPath);



#endif // _CONNECT_SUS_API_H_
// END FILE




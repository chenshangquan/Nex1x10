/*****************************************************************************
ģ����      : connectsuslib
�ļ���      : connectsus_api.h
����ļ�    : connectsus_api.cpp
�ļ�ʵ�ֹ���: 
����        : 
�汾        : V2.1  Copyright(C) 2011-2012 KDC, All rights reserved.
-----------------------------------------------------------------------------
�޸ļ�¼:
��  ��        �汾        �޸���      �޸�����
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

// ��ȡ�Ƽ��汾��Ϣ
CONNECTSUS_API BOOL32 GetRecommendVer( void );

//����ָ���汾
CONNECTSUS_API BOOL32 LoadAssignedVer(u32 dwSn, const s8* szLoadPath);

//����ָ��ģ���ļ�
CONNECTSUS_API BOOL32 LoadAssignedModule(u32 dwSn, const s8* szModuleName, const s8* szLoadPath);



#endif // _CONNECT_SUS_API_H_
// END FILE




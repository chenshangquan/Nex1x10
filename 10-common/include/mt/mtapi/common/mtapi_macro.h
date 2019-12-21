/**===========================================================================
 * @file    $Id$
 * @brief   提供mtapi所有的宏功能定义
 * @author  $Author$
 * @date    $Date$
 * @version  $Revision$ 
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note    
============================================================================*/

#ifndef _MTAPI_MACRO_H_
#define _MTAPI_MACRO_H_

#include "kdvtype.h"
#include "mterrcode_global.h"

#include "mtmacro.h"

/** 判断是否成功:MT_SUCCESS */
#define IS_SUCCESS(dwRet) ((dwRet == MT_SUCCESS) ? TRUE : FALSE )
/** 判断是否失败:MT_FAILED */
#define IS_FAILED(dwRet) ((dwRet == MT_FAILED) ? TRUE : FALSE )

/** 安全释放 */
/*lint -emacro(717, SAFE_RELEASE)*/
#define SAFE_RELEASE(p) \
	do \
{ \
	if ((p) != NULL) \
	{ \
	p->Release();\
	(p) = NULL; \
	} \
} while (0)

/** PB转换缓冲大小 */
#define MAX_PB_BUF_SIZE  (u32)(1024*32)

/** 锁超时时间秒 */
#define  LOCK_TIMEOUT    (u16)10000

/** Proto指针对象的字节数组拷贝(ptr-->ptr) */
/*lint -emacro(717, PB_PTR_MEM_COPY)*/
#define PB_PTR_MEM_COPY(ptrSrc,ptrDst,bRet) \
	do \
{ \
	bRet = FALSE;\
	s8 aszBuf[MAX_PB_BUF_SIZE] = {0};\
	if (NULL != (ptrSrc) ) \
	{ \
	bRet = ptrSrc->SerializeToArray(aszBuf, sizeof(aszBuf));\
	if (TRUE == bRet)\
	   {\
	   bRet = ptrDst->ParseFromArray(aszBuf, sizeof(aszBuf));\
	   }\
	} \
} while (0)

/** Proto对象的字节数组拷贝(obj-->obj) */
/*lint -emacro(717, PB_OBJ_MEM_COPY)*/
#define PB_OBJ_MEM_COPY(objSrc,objDst,bRet) \
	do \
{ \
	bRet = FALSE;\
	s8 aszBuf[MAX_PB_BUF_SIZE] = {0};\
	bRet = objSrc.SerializeToArray(aszBuf, sizeof(aszBuf));\
	if (TRUE == bRet)\
	   {\
	   bRet = objDst.ParseFromArray(aszBuf, sizeof(aszBuf));\
	   }\
} while (0)

/** Proto对象的字节数组拷贝(ptr-->obj) */
/*lint -emacro(717, PB_PTR2OBJ_MEM_COPY)*/
#define PB_PTR2OBJ_MEM_COPY(ptrSrc,objDst,bRet) \
	do \
{ \
	bRet = FALSE;\
	s8 aszBuf[MAX_PB_BUF_SIZE] = {0};\
	bRet = ptrSrc->SerializeToArray(aszBuf, sizeof(aszBuf));\
	if (TRUE == bRet)\
	   {\
	   bRet = objDst.ParseFromArray(aszBuf, sizeof(aszBuf));\
	   }\
} while (0)


/*lint -emacro(717, CREATE_MTAPI_OBJ)*/
#define CREATE_MTAPI_OBJ(cls, iid) \
	do \
{ \
	cls* pcMtObj = new cls( pContext );\
	if ( NULL != pcMtObj )\
	{\
	pcMtObj->Initalize( pContext );\
	dwRet = pcMtObj->QueryInterface( iid, (void**)&pOut );\
	}\
} while (0)

//终端消息订阅
#define CLEAR_MT_MSG() m_tSubsMsgID.Clear()
#define REG_MT_MSG(ID) m_tSubsMsgID.add_msgid( #ID )

/*lint -emacro(717, SEND_SUBS_MSG)*/
#define SEND_SUBS_MSG()  \
	do \
{ \
	CMtMsg  cMtMsg;\
	cMtMsg.SetMsgID( "Ev_MT_Subscribe_Cmd" );\
	cMtMsg.AddMsgBody(((PBMessage*)&m_tSubsMsgID));\
	PostMsgToDispatch( cMtMsg );\
} while (0)

#define SET_INFINITE_LOCK() \
	CAutoLock cLock( &m_cLock );

#define SET_TIMEOUT_LOCK(dwSec) \
	CAutoLock cLock( &m_cLock, dwSec );


//mtbaseapi mtsession检查
/*lint -emacro(717, CHECK_BS_SESSION)*/
#define CHECK_BS_SESSION( SSID ) \
	do \
{ \
	const u32 dwRslt = CheckBsSession( dwSSID );\
	if ( IS_FAILED( dwRslt ) )\
	{\
	return dwRslt;\
	}\
} while (0)

/*lint -emacro(717, CHECK_BS_SESSION_RET)*/
#define CHECK_BS_SESSION_RET( SSID, Ret ) \
	do \
{ \
	const u32 dwRslt = CheckBsSession( dwSSID );\
	if ( IS_FAILED( dwRslt ) )\
	{\
	return Ret;\
	}\
} while (0)


//mtvideoconferenceapi mtsession检查
/*lint -emacro(717, CHECK_VC_SESSION)*/
#define CHECK_VC_SESSION( SSID ) \
	do \
{ \
	const u32 dwRslt = CheckVcSession( dwSSID );\
	if ( IS_FAILED( dwRslt ) )\
	{\
	return dwRslt;\
	}\
} while (0)

/*lint -emacro(717, CHECK_VC_SESSION_RET)*/
#define CHECK_VC_SESSION_RET( SSID, Ret ) \
	do \
{ \
	const u32 dwRslt = CheckVcSession( dwSSID );\
	if ( IS_FAILED( dwRslt ) )\
	{\
	return Ret;\
	}\
} while (0)


//mtvncapi mtsession检查
/*lint -emacro(717, CHECK_VNC_SESSION)*/
#define CHECK_VNC_SESSION( SSID ) \
do \
{ \
	const u32 dwRslt = CheckVncSession( dwSSID );\
	if ( IS_FAILED( dwRslt ) )\
	{\
	return dwRslt;\
	}\
} while (0)


/*lint -emacro(717, CHECK_VNC_SESSION_RET)*/
#define CHECK_VNC_SESSION_RET( SSID, Ret ) \
	do \
{ \
	const u32 dwRslt = CheckVncSession( dwSSID );\
	if ( IS_FAILED( dwRslt ) )\
	{\
	return Ret;\
	}\
} while (0)

//mtimapi mtsession检查
/*lint -emacro(717, CHECK_IM_SESSION)*/
#define CHECK_IM_SESSION( SSID ) \
	do \
{ \
	const u32 dwRslt = CheckImSession( dwSSID );\
	if ( IS_FAILED( dwRslt ) )\
	{\
	return dwRslt;\
	}\
} while (0)


/*lint -emacro(717, CHECK_IM_SESSION_RET)*/
#define CHECK_IM_SESSION_RET( SSID, Ret ) \
	do \
{ \
	const u32 dwRslt = CheckImSession( dwSSID );\
	if ( IS_FAILED( dwRslt ) )\
	{\
	return Ret;\
	}\
} while (0)




//mtmgapi mtsession检查
/*lint -emacro(717, CHECK_MG_SESSION)*/
#define CHECK_CM_SESSION( SSID ) \
	do \
{ \
	const u32 dwRslt = CheckCmSession( dwSSID );\
	if ( IS_FAILED( dwRslt ) )\
	{\
	return dwRslt;\
	}\
} while (0)


/*lint -emacro(717, CHECK_MG_SESSION_RET)*/
#define CHECK_MG_SESSION_RET( SSID, Ret ) \
	do \
{ \
	const u32 dwRslt = CheckMgSession( dwSSID );\
	if ( IS_FAILED( dwRslt ) )\
	{\
	return Ret;\
	}\
} while (0)

//mtdiagnoseapi mtsession检查
/*lint -emacro(717, CHECK_DIAGNOSE_SESSION)*/
#define CHECK_DIAGNOSE_SESSION( SSID ) \
	do \
{ \
	const u32 dwRslt = CheckDiagnoseSession( dwSSID );\
	if ( IS_FAILED( dwRslt ) )\
	{\
	return dwRslt;\
	}\
} while (0)

//mtcloudaddr mtsession检查
/*lint -emacro(717, CHECK_CloudAddr_SESSION)*/
#define CHECK_CloudAddr_SESSION( SSID ) \
	do \
{ \
	const u32 dwRslt = CheckCloudAddrSession( dwSSID );\
	if ( IS_FAILED( dwRslt ) )\
	{\
	return dwRslt;\
	}\
} while (0)

#endif //_MTAPI_MACRO_H_
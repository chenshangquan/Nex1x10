/**===========================================================================
 * @file    $Id$
 * @brief   �ṩnvapi���еĺ깦�ܶ���
 * @author  $Author$
 * @date    $Date$
 * @version  $Revision$ 
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note    
============================================================================*/

#ifndef _NVAPI_MACRO_H_
#define _NVAPI_MACRO_H_

#include "kdvtype.h"
#include "nverrcode_global.h"

#include "nvmacro.h"

/** �ж��Ƿ�ɹ�:NV_SUCCESS */
#define IS_SUCCESS(dwRet) ((dwRet == NV_SUCCESS) ? TRUE : FALSE )
/** �ж��Ƿ�ʧ��:NV_FAILED */
#define IS_FAILED(dwRet) ((dwRet == NV_FAILED) ? TRUE : FALSE )

/** ��ȫ�ͷ� */
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

/** PBת�������С */
#define MAX_PB_BUF_SIZE  (u32)(1024*32)

/** ����ʱʱ���� */
#define  LOCK_TIMEOUT    (u16)10000

/** Protoָ�������ֽ����鿽��(ptr-->ptr) */
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

/** Proto������ֽ����鿽��(obj-->obj) */
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

/** Proto������ֽ����鿽��(ptr-->obj) */
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


/*lint -emacro(717, CREATE_NVAPI_OBJ)*/
#define CREATE_NVAPI_OBJ(cls, iid) \
	do \
{ \
	cls* pcNvObj = new cls( pContext );\
	if ( NULL != pcNvObj )\
	{\
	pcNvObj->Initalize( pContext );\
	dwRet = pcNvObj->QueryInterface( iid, (void**)&pOut );\
	}\
} while (0)

//�ն���Ϣ����
#define CLEAR_NV_MSG() m_tSubsMsgID.Clear()
#define REG_NV_MSG(ID) m_tSubsMsgID.add_msgid( #ID )

/*lint -emacro(717, SEND_SUBS_MSG)*/
#define SEND_SUBS_MSG()  \
	do \
{ \
	CNvMsg  cNvMsg;\
	cNvMsg.SetMsgID( "Ev_NV_Subscribe_Cmd" );\
	cNvMsg.AddMsgBody(((PBMessage*)&m_tSubsMsgID));\
	PostMsgToDispatch( cNvMsg );\
} while (0)

#define SET_INFINITE_LOCK() \
	CAutoLock cLock( &m_cLock );

#define SET_TIMEOUT_LOCK(dwSec) \
	CAutoLock cLock( &m_cLock, dwSec );


//nvbaseapi nvsession���
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


//nvvideoconferenceapi nvsession���
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


//nvvncapi nvsession���
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

//nvimapi nvsession���
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




//nvmgapi nvsession���
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

//nvdiagnoseapi nvsession���
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

//nvcloudaddr nvsession���
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

#endif //_NVAPI_MACRO_H_
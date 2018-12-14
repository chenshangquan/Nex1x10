/**===========================================================================
 * @file    $Id$
 * @brief   ����SDK�Ự����Ľӿڻ��ඨ��
 * @author  $Author$
 * @date    $Date$
 * @version  $Revision$ 
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note    
============================================================================*/

#ifndef _NVAPI_INVAPI_H_
#define _NVAPI_INVAPI_H_

#include "nvapi_typedef.h"
#include "nvapi_if.h"
#include "nvapi_container.h"
#include "nvapi_struct_inner.h"
#include "nvapi_invfset.h"

/**---------------------------------------------------------------------------
 * @class   Interface INvCommApi
 * @brief   ����SDK�Ự����Ľӿڻ��ඨ��
 *            
 * @author  $Author$
 * @version 
 * @date    $Date::                      $
 * @note    
 ---------------------------------------------------------------------------*/
class  INvApi : public INvApiIF
{
public:

	virtual void InitParam( BOOL32 bIsLocalMod = TRUE )
	{
		m_bIsLocalMod = bIsLocalMod;
	}

	//���ûỰ�ڵ���Ϣ
	virtual BOOL32 SetNvObjInfo( SessionID dwSSID, u32 dwSrcNodeID, u32 dwSrcIID, u32 dwDstNodeID, u32 dwDstIID )
	{
		INvFSet* pcFSet = NULL;

		BOOL32 bRet = m_mapNvSession.GetKeyVal( dwSSID, pcFSet );

		if ( TRUE == bRet  && NULL != pcFSet )
		{
			pcFSet->SetNvObjInfo( dwSrcNodeID, dwSrcIID, dwDstNodeID, dwDstIID );
			return TRUE;
		}

		return FALSE;
	}

	//����observer�ص�
	virtual void SetNotify( NOTIFY_NV_OBSERVER_CALLBACK cbNotify )
	{
		INvApiIF::SetNotify( cbNotify );

		u32 dwCnt = m_mapNvSession.GetCount();

		for( u32 dwIdx = 0; dwIdx < dwCnt; ++dwCnt )
		{
			u32 dwKey = 0;
			INvFSet* pcFSet = NULL;
			BOOL32 bRet =  m_mapNvSession.GetItem( dwIdx, dwKey, pcFSet );

			if ( TRUE == bRet && NULL != pcFSet )
			{
				pcFSet->SetNotify( cbNotify );
			}
		}
	}
 
	//����һ��Session
	virtual u32  CreateSession( SessionID dwSSID ) 
	{
		return NV_FAILED;
	}

	//ͨ��SessionID�ͷ�һ���Ѵ�����Session
	virtual u32  DestorySession( SessionID dwSSID )
	{
		u32 dwErrCode = NV_FAILED;

		INvFSet* pcFSet = NULL;

		u32 dwRet = m_mapNvSession.GetKeyVal( dwSSID, pcFSet );

		if ( IS_SUCCESS( dwRet ) && NULL != pcFSet )
		{
			pcFSet->Release();
			m_mapNvSession.RemoveItem( dwSSID );

			dwErrCode = NV_SUCCESS;
		}

		return dwErrCode;
	}

	//�ͷ�����Session
	virtual u32  DestorySession()
	{
		u32 dwErrCode = NV_FAILED;

		u32 dwCnt = m_mapNvSession.GetCount();
		for( u32 dwIdx = 0; dwIdx < dwCnt; dwIdx++ )
		{
			u32 dwKey = 0;
			INvFSet* pcFSet = NULL;
			BOOL32 bRet =  m_mapNvSession.GetItem( dwIdx, dwKey, pcFSet );

			if ( TRUE == bRet && NULL != pcFSet )
			{
				pcFSet->Release();
				dwErrCode = NV_SUCCESS;
			}
		}

		m_mapNvSession.RemoveAll();
		
		return dwErrCode;
	}

	//��ȡNVDis
	virtual u32 OnNvDispCallBack( void* pcNvMsg, u32 dwSrcId, u32 dwSrcNode, SessionID SSID )
	{
		u32 dwErrCode = NV_FAILED;

		nvmsg::CNvMsg *pcNvMsgTmp = (nvmsg::CNvMsg*)pcNvMsg;

		if ( NULL == pcNvMsgTmp )
		{
			return dwErrCode;
		}
 
		INvFSet* pcFSet = NULL;

		BOOL32 bRet = m_mapNvSession.GetKeyVal( SSID, pcFSet );

		if ( bRet && NULL != pcFSet )
		{
			pcFSet->HandleMsg(  pcNvMsgTmp, dwSrcId, dwSrcNode  );

			dwErrCode = NV_SUCCESS;
		}

		return dwErrCode; 
	}



	virtual ~INvApi()
	{
		DestorySession();
		m_mapNvSession.RemoveAll();
	}
	

protected:
	INvApi( const void* pContext )
		:m_bIsLocalMod( TRUE )
	{ 

	}

	//�жϻỰ�Ƿ��Ѿ�����
	BOOL32 IsSessionExist( SessionID dwSSID )
	{
		BOOL32 bRet = FALSE;

		INvFSet* pcFSet = NULL;

		u32 dwRet = m_mapNvSession.GetKeyVal( dwSSID, pcFSet );

		if ( IS_SUCCESS( dwRet ) && NULL != pcFSet )
		{
			bRet = TRUE;
		}

		return bRet;
	}

	//��ȡ�ܵĻỰ����
	u32  GetMaxSessionCnt( ) const
	{
		return KNVAPI_MAX_SESSION_CNT;
	}

	//��ȡ�Ѿ����ڵĻỰ����
	u32  GetUsedSessionCnt( ) const
	{
		return m_mapNvSession.GetCount();
	}


protected:
	INvApiMap<u32,INvFSet*>           m_mapNvSession;                 ///< �Ự�б�(key:SessionID��value:�Ựָ�����)
	BOOL32                            m_bIsLocalMod;                  ///< �Ƿ��Ǳ���ģʽ
};

#endif // _NVAPI_INVAPI_H_


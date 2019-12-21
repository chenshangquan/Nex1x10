/**===========================================================================
 * @file    $Id$
 * @brief   ����SDK�Ự����Ľӿڻ��ඨ��
 * @author  $Author$
 * @date    $Date$
 * @version  $Revision$ 
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note    
============================================================================*/

#ifndef _MTAPI_IMTAPI_H_
#define _MTAPI_IMTAPI_H_

#include "mtapi_typedef.h"
#include "mtapi_if.h"
#include "mtapi_container.h"
#include "mtapi_struct_inner.h"
#include "mtapi_imtfset.h"

/**---------------------------------------------------------------------------
 * @class   Interface IMtCommApi
 * @brief   ����SDK�Ự����Ľӿڻ��ඨ��
 *            
 * @author  $Author$
 * @version 
 * @date    $Date::                      $
 * @note    
 ---------------------------------------------------------------------------*/
class  IMtApi : public IMtApiIF
{
public:

	virtual void InitParam( BOOL32 bIsLocalMod = TRUE )
	{
		m_bIsLocalMod = bIsLocalMod;
	}

	//���ûỰ�ڵ���Ϣ
	virtual BOOL32 SetMtObjInfo( SessionID dwSSID, u32 dwSrcNodeID, u32 dwSrcIID, u32 dwDstNodeID, u32 dwDstIID, u8 *pEncKey,u16 wKeyLen, mt::EmEncryptArithmetic emEncType )
	{
		IMtFSet* pcFSet = NULL;

		BOOL32 bRet = m_mapMtSession.GetKeyVal( dwSSID, pcFSet );

		if ( TRUE == bRet  && NULL != pcFSet )
		{
			pcFSet->SetMtObjInfo( dwSrcNodeID, dwSrcIID, dwDstNodeID, dwDstIID, pEncKey, wKeyLen, emEncType );
			return TRUE;
		}

		return FALSE;
	}

	//����observer�ص�
	virtual void SetNotify( NOTIFY_OBSERVER_CALLBACK cbNotify )
	{
		IMtApiIF::SetNotify( cbNotify );

		u32 dwCnt = m_mapMtSession.GetCount();

		for( u32 dwIdx = 0; dwIdx < dwCnt; ++dwCnt )
		{
			u32 dwKey = 0;
			IMtFSet* pcFSet = NULL;
			BOOL32 bRet =  m_mapMtSession.GetItem( dwIdx, dwKey, pcFSet );

			if ( TRUE == bRet && NULL != pcFSet )
			{
				pcFSet->SetNotify( cbNotify );
			}
		}
	}
 
	//����һ��Session
	virtual u32  CreateSession( SessionID dwSSID ) 
	{
		return MT_FAILED;
	}

	//ͨ��SessionID�ͷ�һ���Ѵ�����Session
	virtual u32  DestorySession( SessionID dwSSID )
	{
		u32 dwErrCode = MT_FAILED;

		IMtFSet* pcFSet = NULL;

		u32 dwRet = m_mapMtSession.GetKeyVal( dwSSID, pcFSet );

		if ( IS_SUCCESS( dwRet ) && NULL != pcFSet )
		{
			pcFSet->Release();
			m_mapMtSession.RemoveItem( dwSSID );

			dwErrCode = MT_SUCCESS;
		}

		return dwErrCode;
	}

	//�ͷ�����Session
	virtual u32  DestorySession()
	{
		u32 dwErrCode = MT_FAILED;

		u32 dwCnt = m_mapMtSession.GetCount();
		for( u32 dwIdx = 0; dwIdx < dwCnt; dwIdx++ )
		{
			u32 dwKey = 0;
			IMtFSet* pcFSet = NULL;
			BOOL32 bRet =  m_mapMtSession.GetItem( dwIdx, dwKey, pcFSet );

			if ( TRUE == bRet && NULL != pcFSet )
			{
				pcFSet->Release();
				dwErrCode = MT_SUCCESS;
			}
		}

		m_mapMtSession.RemoveAll();
		
		return dwErrCode;
	}

	//��ȡMTDis
	virtual u32 OnMtDispCallBack( void* pcMtMsg, u32 dwSrcId, u32 dwSrcNode, SessionID SSID )
	{
		u32 dwErrCode = MT_FAILED;

		mtmsg::CMtMsg *pcMtMsgTmp = (mtmsg::CMtMsg*)pcMtMsg;

		if ( NULL == pcMtMsgTmp )
		{
			return dwErrCode;
		}
 
		IMtFSet* pcFSet = NULL;

		BOOL32 bRet = m_mapMtSession.GetKeyVal( SSID, pcFSet );

		if ( bRet && NULL != pcFSet )
		{
			pcFSet->HandleMsg(  pcMtMsgTmp, dwSrcId, dwSrcNode  );

			dwErrCode = MT_SUCCESS;
		}

		return dwErrCode; 
	}



	virtual ~IMtApi()
	{
		DestorySession();
		m_mapMtSession.RemoveAll();
	}
	

protected:
	IMtApi( const void* pContext )
		:m_bIsLocalMod( TRUE )
	{ 

	}

	//�жϻỰ�Ƿ��Ѿ�����
	BOOL32 IsSessionExist( SessionID dwSSID )
	{
		BOOL32 bRet = FALSE;

		IMtFSet* pcFSet = NULL;

		u32 dwRet = m_mapMtSession.GetKeyVal( dwSSID, pcFSet );

		if ( IS_SUCCESS( dwRet ) && NULL != pcFSet )
		{
			bRet = TRUE;
		}

		return bRet;
	}

	//��ȡ�ܵĻỰ����
	u32  GetMaxSessionCnt( ) const
	{
		return KMTAPI_MAX_SESSION_CNT;
	}

	//��ȡ�Ѿ����ڵĻỰ����
	u32  GetUsedSessionCnt( ) const
	{
		return m_mapMtSession.GetCount();
	}


protected:
	IMtApiMap<u32,IMtFSet*>           m_mapMtSession;                 ///< �Ự�б�(key:SessionID��value:�Ựָ�����)
	BOOL32                            m_bIsLocalMod;                  ///< �Ƿ��Ǳ���ģʽ
};

#endif // _MTAPI_IMTAPI_H_


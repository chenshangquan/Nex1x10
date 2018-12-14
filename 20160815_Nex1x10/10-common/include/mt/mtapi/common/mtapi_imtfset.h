/**===========================================================================
 * @file    $Id$
 * @brief   ����SDK�ĻỰͨ�õ���Ͻӿڻ���
 * @author  $Author$
 * @date    $Date$
 * @version  $Revision$ 
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note    
============================================================================*/

#ifndef _MTAPI_IMtFSET_H_
#define _MTAPI_IMtFSET_H_

#include "mtapi_typedef.h"
#include "mtapi_if.h"
#include "mtapi_container.h"
#include "mtapi_struct_inner.h"



/**---------------------------------------------------------------------------
 * @class   Interface IMtFSet
 * @brief   ����SDK��������ҵ���ܵļ���
 *            
 * @author  $Author$
 * @version 
 * @date    $Date::                      $
 * @note    
 ---------------------------------------------------------------------------*/
class  IMtFSet : public IMtApiIF
{
public:

	virtual ~IMtFSet()
	{
	}

	/**
	* HandleMsg 
	* 
	* @brief ʵ��CAbstraceMsgHandler����Ϣ������ӿ�
	* 
	* @param	[in] *pcMtMsg  �������mt��Ϣ��
	* @param	[in] dwSrcId   ԴID
	* @param	[in] dwSrcNode Դ�ڵ�
	* @return   BOOL32  TRUE:������� FALSE:δ�����
    */
	virtual BOOL32 HandleMsg( mtmsg::CMtMsg *pcMtMsg, u32 dwSrcId, u32 dwSrcNode )
	{
		BOOL32 bRet = FALSE;

		//������Ӧ
		bRet = IMtApiIF::HandleMsg( pcMtMsg, dwSrcId, dwSrcNode);

		//�Ӷ�����Ӧ
		u32 dwCnt = m_vctMtApiIF.GetCount();

		for ( u32 dwIdx = 0; dwIdx < dwCnt; ++dwIdx )
		{
			TIMtApiInfo tInfo;
			BOOL32 bRet = m_vctMtApiIF.GetItem( dwIdx, tInfo );

			if ( TRUE == bRet )
			{
				if( NULL != tInfo.pcMtApiIF )
				{
					bRet |= tInfo.pcMtApiIF->HandleMsg( pcMtMsg, dwSrcId, dwSrcNode );
				}
			}
		}

		return bRet;
	}
 
	/**
	* SetMtObjInfo
	* @brief  ������Ϣ���շ��ڵ���Ϣ
	*
	* @param	[in]    dwSrcNodeID  ԴNodeID
	* @param	[in]    dwSrcIID     ԴIID
	* @param	[in]    dwDstNodeID  Ŀ��NodeID 
	* @param	[in]    dwDstIID     Ŀ��IID
	* @return	void
	* @note     session�����������ҵ��ӿڵ���Ϣ�շ��ڵ���ϢҲ��ͬ���õ�����
	*/
	virtual void SetMtObjInfo( u32 dwSrcNodeID, u32 dwSrcIID, u32 dwDstNodeID, u32 dwDstIID, u8 *pEncKey,u16 wKeyLen, mt::EmEncryptArithmetic emEncType )
	{
		IMtApiIF::SetMtObjInfo( dwSrcNodeID, dwSrcIID, dwDstNodeID, dwDstIID, pEncKey, wKeyLen, emEncType );

		//�Ӷ�����Ӧ
		u32 dwCnt = m_vctMtApiIF.GetCount();

		for ( u32 dwIdx = 0; dwIdx < dwCnt; ++dwIdx )
		{
			TIMtApiInfo tInfo;
			BOOL32 bRet = m_vctMtApiIF.GetItem( dwIdx, tInfo );

			if ( TRUE == bRet )
			{
				if( NULL != tInfo.pcMtApiIF )
				{
					tInfo.pcMtApiIF->SetMtObjInfo( dwSrcNodeID, dwSrcIID, dwDstNodeID, dwDstIID, pEncKey, wKeyLen, emEncType );
				}
			}
		}
	}


	/**
	* SetNotify
	* @brief  ע��Observer(UI)֪ͨ�ص�
	*
	* @param  [in]   cbNotify  Ҫע��Ļص�����
	* @return void
	* @note   session�����������ҵ��ӿڵ�Notify�ص�Ҳ��ͬ���õ�����
	*
	*/
	virtual void SetNotify( NOTIFY_OBSERVER_CALLBACK cbNotify )
	{
		IMtApiIF::SetNotify( cbNotify );

		u32 dwCnt = m_vctMtApiIF.GetCount();

		for ( u32 dwIdx = 0; dwIdx < dwCnt; ++dwIdx )
		{
			TIMtApiInfo tInfo;
			BOOL32 bRet = m_vctMtApiIF.GetItem( dwIdx, tInfo );

			if ( TRUE == bRet )
			{
				if( NULL != tInfo.pcMtApiIF )
				{
					tInfo.pcMtApiIF->SetNotify( cbNotify );
				}
			}
		}
	}

	/**
	* SubscribeMtMsg 
	* 
	* @brief   �ڴ˺���ʵ���ն���Ϣ�Ķ���ͳһ����
	* 
	* @param   [in] void
	* @return  void
	* @note    �ⲿ����
	*/
	virtual void SubscribeMtMsg( ) = 0;

protected:
	IMtFSet( const void* pContext )
	{ 

	}

	/**
	* FindMtApiIFByIID
	* @brief  ����IID����session�����Ӧ��ҵ��ӿ�ָ��
	*
	* @param  [in] IID    Ҫ���ҵ�IID
	* @return IMtApiIF*  �ǿգ����ҵ���ҵ��ӿ�ָ�룬NULL��������
	*
	*/
	IMtApiIF* FindMtApiIFByIID( MT_UUID  IID )
	{
		u32 dwCnt = m_vctMtApiIF.GetCount();

		for ( u32 dwIdx = 0; dwIdx < dwCnt; ++dwIdx )
		{
			TIMtApiInfo tInfo;
			BOOL32 bRet = m_vctMtApiIF.GetItem( dwIdx, tInfo );

			if ( TRUE == bRet )
			{
				if( IID == tInfo.tIID )
				{
					return tInfo.pcMtApiIF;
				}
				else
				{
					if ( NULL == tInfo.pcMtApiIF )
					{
						continue;
					}
					IMtApiIF* pcMtApiIF = NULL;
					if ( MT_SUCCESS == tInfo.pcMtApiIF->QueryInterface( IID, (void**)&pcMtApiIF ) && NULL != pcMtApiIF )
					{
						return pcMtApiIF;
					}
				}
			}
		}

		return NULL;
	}


	/**
	* ReleaseSubObj
	* @brief  �ͷ�session�¶�����ҵ��ӿ�ָ������ã�����ʱ������һ�Σ�
	* @param  [in]  void
	* @return void
	* @note   Session�����ǻ��Զ�����
	*/
	void ReleaseSubObj( )
	{
		u32 dwCnt = m_vctMtApiIF.GetCount();

		for ( u32 dwIdx = 0; dwIdx < dwCnt; ++dwIdx )
		{
			TIMtApiInfo tInfo;
			BOOL32 bRet = m_vctMtApiIF.GetItem( dwIdx, tInfo );

			if ( TRUE == bRet )
			{
				if( NULL != tInfo.pcMtApiIF )
				{
					tInfo.pcMtApiIF->Release();
				}
			}
		}
	}
	
protected:
	IMtApiVct<TIMtApiInfo>  m_vctMtApiIF;                   ///< session���幦�ܲ����ӿ��б�
	mt::TSubsMsgID          m_tSubsMsgID;                   ///< ����MTDispatch����Ϣ�ṹ
};

#endif // _MTAPI_IMtFSET_H_


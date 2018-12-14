/**===========================================================================
 * @file    $Id$
 * @brief   ����SDK�ĻỰͨ�õ���Ͻӿڻ���
 * @author  $Author$
 * @date    $Date$
 * @version  $Revision$ 
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note    
============================================================================*/

#ifndef _NVAPI_INvFSET_H_
#define _NVAPI_INvFSET_H_

#include "nvapi_typedef.h"
#include "nvapi_if.h"
#include "nvapi_container.h"
#include "nvapi_struct_inner.h"



/**---------------------------------------------------------------------------
 * @class   Interface INvFSet
 * @brief   ����SDK��������ҵ���ܵļ���
 *            
 * @author  $Author$
 * @version 
 * @date    $Date::                      $
 * @note    
 ---------------------------------------------------------------------------*/
class  INvFSet : public INvApiIF
{
public:

	virtual ~INvFSet()
	{
	}

	/**
	* HandleMsg 
	* 
	* @brief ʵ��CAbstraceMsgHandler����Ϣ������ӿ�
	* 
	* @param	[in] *pcNvMsg  �������nv��Ϣ��
	* @param	[in] dwSrcId   ԴID
	* @param	[in] dwSrcNode Դ�ڵ�
	* @return   BOOL32  TRUE:������� FALSE:δ�����
    */
	virtual BOOL32 HandleMsg( nvmsg::CNvMsg *pcNvMsg, u32 dwSrcId, u32 dwSrcNode )
	{
		BOOL32 bRet = FALSE;

		//������Ӧ
		bRet = INvApiIF::HandleMsg( pcNvMsg, dwSrcId, dwSrcNode);

		//�Ӷ�����Ӧ
		u32 dwCnt = m_vctNvApiIF.GetCount();

		for ( u32 dwIdx = 0; dwIdx < dwCnt; ++dwIdx )
		{
			TINvApiInfo tInfo;
			BOOL32 bRet = m_vctNvApiIF.GetItem( dwIdx, tInfo );

			if ( TRUE == bRet )
			{
				if( NULL != tInfo.pcNvApiIF )
				{
					bRet |= tInfo.pcNvApiIF->HandleMsg( pcNvMsg, dwSrcId, dwSrcNode );
				}
			}
		}

		return bRet;
	}
 
	/**
	* SetNvObjInfo
	* @brief  ������Ϣ���շ��ڵ���Ϣ
	*
	* @param	[in]    dwSrcNodeID  ԴNodeID
	* @param	[in]    dwSrcIID     ԴIID
	* @param	[in]    dwDstNodeID  Ŀ��NodeID 
	* @param	[in]    dwDstIID     Ŀ��IID
	* @return	void
	* @note     session�����������ҵ��ӿڵ���Ϣ�շ��ڵ���ϢҲ��ͬ���õ�����
	*/
	virtual void SetNvObjInfo( u32 dwSrcNodeID, u32 dwSrcIID, u32 dwDstNodeID, u32 dwDstIID )
	{
		INvApiIF::SetNvObjInfo( dwSrcNodeID, dwSrcIID, dwDstNodeID, dwDstIID );

		//�Ӷ�����Ӧ
		u32 dwCnt = m_vctNvApiIF.GetCount();

		for ( u32 dwIdx = 0; dwIdx < dwCnt; ++dwIdx )
		{
			TINvApiInfo tInfo;
			BOOL32 bRet = m_vctNvApiIF.GetItem( dwIdx, tInfo );
			if ( TRUE == bRet )
			{
				if( NULL != tInfo.pcNvApiIF )
				{
					tInfo.pcNvApiIF->SetNvObjInfo( dwSrcNodeID, dwSrcIID, dwDstNodeID, dwDstIID );
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

	virtual void SetNotify( NOTIFY_NV_OBSERVER_CALLBACK cbNotify )
	{
		INvApiIF::SetNotify( cbNotify );

		u32 dwCnt = m_vctNvApiIF.GetCount();

		for ( u32 dwIdx = 0; dwIdx < dwCnt; ++dwIdx )
		{
			TINvApiInfo tInfo;
			BOOL32 bRet = m_vctNvApiIF.GetItem( dwIdx, tInfo );

			if ( TRUE == bRet )
			{
				if( NULL != tInfo.pcNvApiIF )
				{
					tInfo.pcNvApiIF->SetNotify( cbNotify );
				}
			}
		}
	}

	/**
	* SubscribeNvMsg 
	* 
	* @brief   �ڴ˺���ʵ���ն���Ϣ�Ķ���ͳһ����
	* 
	* @param   [in] void
	* @return  void
	* @note    �ⲿ����
	*/
	virtual void SubscribeNvMsg( ) = 0;

protected:
	INvFSet( const void* pContext )
	{ 

	}

	/**
	* FindNvApiIFByIID
	* @brief  ����IID����session�����Ӧ��ҵ��ӿ�ָ��
	*
	* @param  [in] IID    Ҫ���ҵ�IID
	* @return INvApiIF*  �ǿգ����ҵ���ҵ��ӿ�ָ�룬NULL��������
	*
	*/
	INvApiIF* FindNvApiIFByIID( NV_UUID  IID )
	{
		u32 dwCnt = m_vctNvApiIF.GetCount();

		for ( u32 dwIdx = 0; dwIdx < dwCnt; ++dwIdx )
		{
			TINvApiInfo tInfo;
			BOOL32 bRet = m_vctNvApiIF.GetItem( dwIdx, tInfo );

			if ( TRUE == bRet )
			{
				if( IID == tInfo.tIID )
				{
					return tInfo.pcNvApiIF;
				}
				else
				{
					if ( NULL == tInfo.pcNvApiIF )
					{
						continue;
					}
					INvApiIF* pcNvApiIF = NULL;
					if ( NV_SUCCESS == tInfo.pcNvApiIF->QueryInterface( IID, (void**)&pcNvApiIF ) && NULL != pcNvApiIF )
					{
						return pcNvApiIF;
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
		u32 dwCnt = m_vctNvApiIF.GetCount();

		for ( u32 dwIdx = 0; dwIdx < dwCnt; ++dwIdx )
		{
			TINvApiInfo tInfo;
			BOOL32 bRet = m_vctNvApiIF.GetItem( dwIdx, tInfo );

			if ( TRUE == bRet )
			{
				if( NULL != tInfo.pcNvApiIF )
				{
					tInfo.pcNvApiIF->Release();
				}
			}
		}
	}
	
protected:
	INvApiVct<TINvApiInfo>  m_vctNvApiIF;                   ///< session���幦�ܲ����ӿ��б�
	nv::TNVSubsMsgID          m_tSubsMsgID;                   ///< ����NVDispatch����Ϣ�ṹ
};

#endif // _NVAPI_INvFSET_H_


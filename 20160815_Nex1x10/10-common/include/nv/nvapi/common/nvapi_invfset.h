/**===========================================================================
 * @file    $Id$
 * @brief   各子SDK的会话通用的组合接口基类
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
 * @brief   各子SDK的所有子业务功能的集合
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
	* @brief 实现CAbstraceMsgHandler的消息抽象处理接口
	* 
	* @param	[in] *pcNvMsg  待处理的nv消息体
	* @param	[in] dwSrcId   源ID
	* @param	[in] dwSrcNode 源节点
	* @return   BOOL32  TRUE:处理过， FALSE:未处理过
    */
	virtual BOOL32 HandleMsg( nvmsg::CNvMsg *pcNvMsg, u32 dwSrcId, u32 dwSrcNode )
	{
		BOOL32 bRet = FALSE;

		//自身响应
		bRet = INvApiIF::HandleMsg( pcNvMsg, dwSrcId, dwSrcNode);

		//子对象响应
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
	* @brief  设置消息的收发节点信息
	*
	* @param	[in]    dwSrcNodeID  源NodeID
	* @param	[in]    dwSrcIID     源IID
	* @param	[in]    dwDstNodeID  目标NodeID 
	* @param	[in]    dwDstIID     目标IID
	* @return	void
	* @note     session下面包含的子业务接口的消息收发节点信息也会同步得到更新
	*/
	virtual void SetNvObjInfo( u32 dwSrcNodeID, u32 dwSrcIID, u32 dwDstNodeID, u32 dwDstIID )
	{
		INvApiIF::SetNvObjInfo( dwSrcNodeID, dwSrcIID, dwDstNodeID, dwDstIID );

		//子对象响应
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
	* @brief  注册Observer(UI)通知回调
	*
	* @param  [in]   cbNotify  要注册的回调函数
	* @return void
	* @note   session下面包含的子业务接口的Notify回调也会同步得到更新
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
	* @brief   在此函数实现终端消息的订阅统一处理
	* 
	* @param   [in] void
	* @return  void
	* @note    外部调用
	*/
	virtual void SubscribeNvMsg( ) = 0;

protected:
	INvFSet( const void* pContext )
	{ 

	}

	/**
	* FindNvApiIFByIID
	* @brief  根据IID查找session下面对应的业务接口指针
	*
	* @param  [in] IID    要查找的IID
	* @return INvApiIF*  非空：查找到的业务接口指针，NULL：不存在
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
	* @brief  释放session下对所有业务接口指针的引用（创建时引用了一次）
	* @param  [in]  void
	* @return void
	* @note   Session销毁是会自动调用
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
	INvApiVct<TINvApiInfo>  m_vctNvApiIF;                   ///< session具体功能操作接口列表
	nv::TNVSubsMsgID          m_tSubsMsgID;                   ///< 订阅NVDispatch的消息结构
};

#endif // _NVAPI_INvFSET_H_


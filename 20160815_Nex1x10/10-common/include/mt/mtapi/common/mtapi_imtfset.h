/**===========================================================================
 * @file    $Id$
 * @brief   各子SDK的会话通用的组合接口基类
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
 * @brief   各子SDK的所有子业务功能的集合
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
	* @brief 实现CAbstraceMsgHandler的消息抽象处理接口
	* 
	* @param	[in] *pcMtMsg  待处理的mt消息体
	* @param	[in] dwSrcId   源ID
	* @param	[in] dwSrcNode 源节点
	* @return   BOOL32  TRUE:处理过， FALSE:未处理过
    */
	virtual BOOL32 HandleMsg( mtmsg::CMtMsg *pcMtMsg, u32 dwSrcId, u32 dwSrcNode )
	{
		BOOL32 bRet = FALSE;

		//自身响应
		bRet = IMtApiIF::HandleMsg( pcMtMsg, dwSrcId, dwSrcNode);

		//子对象响应
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
	* @brief  设置消息的收发节点信息
	*
	* @param	[in]    dwSrcNodeID  源NodeID
	* @param	[in]    dwSrcIID     源IID
	* @param	[in]    dwDstNodeID  目标NodeID 
	* @param	[in]    dwDstIID     目标IID
	* @return	void
	* @note     session下面包含的子业务接口的消息收发节点信息也会同步得到更新
	*/
	virtual void SetMtObjInfo( u32 dwSrcNodeID, u32 dwSrcIID, u32 dwDstNodeID, u32 dwDstIID, u8 *pEncKey,u16 wKeyLen, mt::EmEncryptArithmetic emEncType )
	{
		IMtApiIF::SetMtObjInfo( dwSrcNodeID, dwSrcIID, dwDstNodeID, dwDstIID, pEncKey, wKeyLen, emEncType );

		//子对象响应
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
	* @brief  注册Observer(UI)通知回调
	*
	* @param  [in]   cbNotify  要注册的回调函数
	* @return void
	* @note   session下面包含的子业务接口的Notify回调也会同步得到更新
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
	* @brief   在此函数实现终端消息的订阅统一处理
	* 
	* @param   [in] void
	* @return  void
	* @note    外部调用
	*/
	virtual void SubscribeMtMsg( ) = 0;

protected:
	IMtFSet( const void* pContext )
	{ 

	}

	/**
	* FindMtApiIFByIID
	* @brief  根据IID查找session下面对应的业务接口指针
	*
	* @param  [in] IID    要查找的IID
	* @return IMtApiIF*  非空：查找到的业务接口指针，NULL：不存在
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
	* @brief  释放session下对所有业务接口指针的引用（创建时引用了一次）
	* @param  [in]  void
	* @return void
	* @note   Session销毁是会自动调用
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
	IMtApiVct<TIMtApiInfo>  m_vctMtApiIF;                   ///< session具体功能操作接口列表
	mt::TSubsMsgID          m_tSubsMsgID;                   ///< 订阅MTDispatch的消息结构
};

#endif // _MTAPI_IMtFSET_H_


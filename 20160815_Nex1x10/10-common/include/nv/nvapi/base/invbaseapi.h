/**===========================================================================
 * @file    $Id$
 * @brief   负责NVAPI会话管理的接口定义
 * @author  $Author$
 * @date    $Date$
 * @version  $Revision$ 
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note    
============================================================================*/

#ifndef _I_NVBASEAPI_H_
#define _I_NVBASEAPI_H_

#include <map>

#include "nvapi_typedef.h"
#include "nvapi_def.h"
#include "nvapi_export.h"

#include "invbasefset.h"
#include "nvlock.h"

//调用者使用的方式默认为静态方式
#if defined( _USRDLL )
//动态库
#if defined( _KDV_NVBASEAPI_EXP_ )
#define KdvNvBaseAPI __declspec( dllexport )
#else
#define KdvNvBaseAPI __declspec( dllimport )
#endif
#else
//静态库
#define  KdvNvBaseAPI
#endif

/**---------------------------------------------------------------------------
 * @class   Interface INvBaseApi
 * @brief   负责NVAPI会话管理的接口定义
 * @author  $Author$
 * @version 
 * @date    $Date::                      $
 * @note    
 ---------------------------------------------------------------------------*/
class INvBaseApi : public INvApiIF
{
public:
	virtual ~INvBaseApi(){};
	
	/**
	* InitParam
	* @brief  BaseApi的初始化操作
	*
	* @param  [in]   [in] emMode: emNvLocMode_Api: 非C/S模式，emNvRnvMode_Api：C/S模式
	* @return void 
	* @note 
	*
	*/
	virtual void InitParam( const EmNvApiMode_Api emMode  = emNvLocMode_Api ) = 0;

	/**
	* GetApiMode
	* @brief  获取api模式
	*
	* @return emMode: emNvLocMode_Api: 非C/S模式，emNvRnvMode_Api：C/S模式 
	* @note 
	*
	*/
	virtual EmNvApiMode_Api GetApiMode() = 0;

	/**
	* CreateSession
	* @brief  新创建一个Session
	*
	* @param  [out]   dwSSID   返回创建的 SESSIONID
	* @param  [in]    tConnectInfo  连接信息 
	* @return u32  NV_SUCCESS：成功 其他：错误码
	* @note C/S模式需要进行连接处理，已创建的直接返回
	*
	*/
	virtual u32  CreateSession( SessionID& dwSSID, 
								const nv::TNVUserConnectInfo &tConnectInfo) = 0;
	
	/**
	* GetSession
	* @brief  通过终端IP查找已创建的Session
	*
	* @param  [in]    strNvIp  要查找的终端IP 
	* @return  SessionID  返回对应的SessionID, 不存在为INVALID_SESSIONID
	*
	*
	*/
	virtual SessionID GetSession( const nvstring &strNvIp) const  = 0;


	/**
	* GetSession
	* @brief  通过索引查找对应的SessionID
	*
	* @param  [in]    dwIdx  会话列表索引 
	* @return  SessionID  返回对应的SessionID, 不存在为INVALID_SESSIONID
	*
	*
	*/
	virtual SessionID GetSession( const u32 dwIdx ) const  = 0;


	/**
	* DestorySession
	* @brief  通过SessionID释放一个已创建的Session
	*
	* @param  [in]    SessionID  会话ID 
	* @return  u32   返回释放结果
	*
	*/
	virtual u32  DestorySession( SessionID dwSSID ) = 0; 

	/**
	* GetMaxSessionCnt
	* @brief  获取最大支持的会话数量
	*
	* @param  [in]   void 
	* @return  u32   返回最大支持的session数量
	*
	*/
	virtual u16  GetMaxSessionCnt( ) const = 0;

	/**
	* GetUsedSessionCnt
	* @brief  获取已经存在的会话数量
	*
	* @param  [in]   void 
	* @return  u32   返回已经存在的会话数量
	*
	*/
	virtual u16  GetUsedSessionCnt( ) const = 0;


	/**
	* RegDispMsg
	* @brief  注册NvDispatch消息回调
	*
	* @param  [in]   NV_CID           SDK的CID eg: INvXXXApi的CID
	* @param  [in]   pcbDispCallBack  回调地址
	* @return  u32   返回注册结果
	*
	*/
	virtual BOOL32  RegDispMsg( NV_UUID NV_CID , NOTIFY_NVAPI_CALLBACK pDispCB  ) = 0;

	/**
	* UnRegDispMsg
	* @brief  反注册NvDispatch消息回调
	*
	* @param  [in]   NV_CID   SDK的CID eg: INvXXXApi的CID
	* @return  u32   返回反注册结果
	*
	*/
	virtual BOOL32  UnRegDispMsg( NV_UUID NV_CID ) = 0;
 
	/**
	* OnDispCallBackNotify
	* @brief  响应其他子nvapi注册的callback
	*
	* @param  [in]   pcNvMsg    响应的消息
	* @param  [in]   dwSrcId    源NodeID(保留)
	* @param  [in]   dwSrcNode  源IID(保留)
	* @param  [in]   SSID       sessionid
	* @return  u32   返回反注册结果
	*
	*/
	virtual BOOL32  OnDispCallBackNotify( void* pcNvMsg, u32 dwSrcId, u32 dwSrcNode,SessionID SSID  ) = 0;
};

extern "C"
{
//回调函数
/**----------------------------------------------------------------------
	* CreateInstance
	* 
	* @brief    创建实例的回调函数
	* 
	* @param	[in] dwSSID 
	------------------------------------------------------------------------*/
KdvNvBaseAPI typedef u32 (CreateInstance)( IN CONST SessionID dwSSID );

/**----------------------------------------------------------------------
	* DestoryInstance
	* 
	* @brief    销毁实例的回调函数
	* 
	* @param	[in] dwSSID 
	------------------------------------------------------------------------*/
KdvNvBaseAPI typedef u32 (DestoryInstance)( IN CONST SessionID dwSSID );

/**----------------------------------------------------------------------
	* RegisterCreateInstance
	* 
	* @brief    注册一个创建功能实例函数
	* 
	* @param	[in] pf 注册函数
	* @param	[in] pchName 注册函数名称
	* @return	void
	------------------------------------------------------------------------*/
KdvNvBaseAPI void RegisterCreateInstance( CreateInstance *pf, char* pchName );
/**----------------------------------------------------------------------
	* LogOutCreateInstance
	* 
	* @brief    注销一个创建功能实例函数
	* 
	* @param	[in] pf 注册函数名称
	* @return	void
	------------------------------------------------------------------------*/
KdvNvBaseAPI void LogOutCreateInstance( CreateInstance *pf );
/**----------------------------------------------------------------------
	* RegisterDestoryInstance
	* 
	* @brief    注册一个销毁功能实例函数
	* 
	* @param	[in] pf 注册函数
	* @param	[in] pchName 注册函数名称
	* @return	void
	------------------------------------------------------------------------*/
KdvNvBaseAPI void RegisterDestoryInstance( DestoryInstance *pf, char* pchName );

/**----------------------------------------------------------------------
	* LogOutDestoryInstance
	* 
	* @brief    注销一个销毁功能实例函数
	* 
	* @param	[in] pf 注册函数名称
	* @return	void
	------------------------------------------------------------------------*/
KdvNvBaseAPI void LogOutDestoryInstance( DestoryInstance *pf );

KdvNvBaseAPI typedef std::map<SessionID, INvBaseFSet* >  MapNvBSSession;

};

extern "C" KdvNvBaseAPI INvBaseApi*        g_pcNvBsApiIF;            ///< baseapi模块api接口指针
extern "C" KdvNvBaseAPI MapNvBSSession     g_mapINvBaseSession;      ///< baseapi所有NV会话对象  
extern "C" KdvNvBaseAPI COspLock g_cLock;
#endif // _I_NVBASEAPI_H_
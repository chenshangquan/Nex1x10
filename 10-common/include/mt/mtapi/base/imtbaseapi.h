/**===========================================================================
 * @file    $Id$
 * @brief   负责MTAPI会话管理的接口定义
 * @author  $Author$
 * @date    $Date$
 * @version  $Revision$ 
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note    
============================================================================*/

#ifndef _I_MTBASEAPI_H_
#define _I_MTBASEAPI_H_

#include <map>

#include "mtapi_typedef.h"
#include "mtapi_def.h"
#include "mtapi_export.h"

#include "imtbasefset.h"
#include "mtlock.h"

//调用者使用的方式默认为静态方式
#if defined( _USRDLL )
//动态库
#if defined( _KDV_MTBASEAPI_EXP_ )
#define KdvMtBaseAPI __declspec( dllexport )
#else
#define KdvMtBaseAPI __declspec( dllimport )
#endif
#else
//静态库
#define  KdvMtBaseAPI
#endif

/**---------------------------------------------------------------------------
 * @class   Interface IMtBaseApi
 * @brief   负责MTAPI会话管理的接口定义
 * @author  $Author$
 * @version 
 * @date    $Date::                      $
 * @note    
 ---------------------------------------------------------------------------*/
class IMtBaseApi : public IMtApiIF
{
public:
	virtual ~IMtBaseApi(){};
	
	/**
	* InitParam
	* @brief  BaseApi的初始化操作
	*
	* @param  [in]   [in] emMode: emMtLocMode_Api: 非C/S模式，emMtRmtMode_Api：C/S模式
	* @return void 
	* @note 
	*
	*/
	virtual void InitParam( const EmMtApiMode_Api emMode  = emMtLocMode_Api ) = 0;

	/**
	* GetApiMode
	* @brief  获取api模式
	*
	* @return emMode: emMtLocMode_Api: 非C/S模式，emMtRmtMode_Api：C/S模式 
	* @note 
	*
	*/
	virtual EmMtApiMode_Api GetApiMode() = 0;

	virtual u32 CreateSession2( SessionID& dwSSID, TMtcLoginParam_Api *ptParam ) =0;

	virtual u32 GetMtVersionInfoReq( const s8* pchMtIp ) = 0;

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
	* OspDisConnectDestorySession
	* @brief  osp断链消息到来，通过SessionID释放一个已创建的Session
	*
	* @param  [in]    SessionID  会话ID 
	* 
	*
	*/
	virtual u32  OspDisConnectDestorySession( SessionID dwSSID ) = 0; 

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
	* @brief  注册MtDispatch消息回调
	*
	* @param  [in]   MT_CID           SDK的CID eg: IMtXXXApi的CID
	* @param  [in]   pcbDispCallBack  回调地址
	* @return  u32   返回注册结果
	*
	*/
	virtual BOOL32  RegDispMsg( MT_UUID MT_CID , NOTIFY_MTAPI_CALLBACK pDispCB  ) = 0;

	/**
	* UnRegDispMsg
	* @brief  反注册MtDispatch消息回调
	*
	* @param  [in]   MT_CID   SDK的CID eg: IMtXXXApi的CID
	* @return  u32   返回反注册结果
	*
	*/
	virtual BOOL32  UnRegDispMsg( MT_UUID MT_CID ) = 0;
 
	/**
	* OnDispCallBackNotify
	* @brief  响应其他子mtapi注册的callback
	*
	* @param  [in]   pcMtMsg    响应的消息
	* @param  [in]   dwSrcId    源NodeID(保留)
	* @param  [in]   dwSrcNode  源IID(保留)
	* @param  [in]   SSID       sessionid
	* @return  u32   返回反注册结果
	*
	*/
	virtual BOOL32  OnDispCallBackNotify( void* pcMtMsg, u32 dwSrcId, u32 dwSrcNode,SessionID SSID  ) = 0;
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
KdvMtBaseAPI typedef u32 (CreateInstance)( IN CONST SessionID dwSSID );

/**----------------------------------------------------------------------
	* DestoryInstance
	* 
	* @brief    销毁实例的回调函数
	* 
	* @param	[in] dwSSID 
	------------------------------------------------------------------------*/
KdvMtBaseAPI typedef u32 (DestoryInstance)( IN CONST SessionID dwSSID );

/**----------------------------------------------------------------------
	* RegisterCreateInstance
	* 
	* @brief    注册一个创建功能实例函数
	* 
	* @param	[in] pf 注册函数
	* @param	[in] pchName 注册函数名称
	* @return	void
	------------------------------------------------------------------------*/
KdvMtBaseAPI void RegisterCreateInstance( CreateInstance *pf, char* pchName );
/**----------------------------------------------------------------------
	* LogOutCreateInstance
	* 
	* @brief    注销一个创建功能实例函数
	* 
	* @param	[in] pf 注册函数名称
	* @return	void
	------------------------------------------------------------------------*/
KdvMtBaseAPI void LogOutCreateInstance( CreateInstance *pf );
/**----------------------------------------------------------------------
	* RegisterDestoryInstance
	* 
	* @brief    注册一个销毁功能实例函数
	* 
	* @param	[in] pf 注册函数
	* @param	[in] pchName 注册函数名称
	* @return	void
	------------------------------------------------------------------------*/
KdvMtBaseAPI void RegisterDestoryInstance( DestoryInstance *pf, char* pchName );

/**----------------------------------------------------------------------
	* LogOutDestoryInstance
	* 
	* @brief    注销一个销毁功能实例函数
	* 
	* @param	[in] pf 注册函数名称
	* @return	void
	------------------------------------------------------------------------*/
KdvMtBaseAPI void LogOutDestoryInstance( DestoryInstance *pf );

KdvMtBaseAPI typedef std::map<SessionID, IMtBaseFSet* >  MapMtBSSession;

};

extern "C" KdvMtBaseAPI IMtBaseApi*        g_pcMtBsApiIF;            ///< baseapi模块api接口指针
extern "C" KdvMtBaseAPI MapMtBSSession     g_mapIMtBaseSession;      ///< baseapi所有MT会话对象  
extern "C" KdvMtBaseAPI COspLock g_cLock;
extern "C" KdvMtBaseAPI IMtApiMap<DestoryInstance *, char*> g_mapDestoryInstance;
#endif // _I_MTBASEAPI_H_
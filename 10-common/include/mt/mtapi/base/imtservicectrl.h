/**===========================================================================
 * @file    $Id$
 * @brief   负责终端功能服务开启关闭相关操作
 * @author  $Author$
 * @date    $Date$
 * @version  $Revision$ 
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note    
============================================================================*/

#ifndef _MTBASEAPI_INTERFACE_IMTSERVICECTRL_H_
#define _MTBASEAPI_INTERFACE_IMTSERVICECTRL_H_

#include "mtapi_typedef.h"
#include "mtapi_if.h"
#include "mtapi_event_base.h"




/**---------------------------------------------------------------------------
 * @class   Interface IMtserviceCtrl
 * @brief   负责终端功能服务开启关闭相关操作的接口定义
 * @author  $Author$
 * @version 
 * @date    $Date::                      $
 * @note    
 ---------------------------------------------------------------------------*/
class IMtserviceCtrl : public IMtApiIF
{
public:
	/**
	*  BindDefMtService 
	* 
	* @brief 终端绑定默认的终端服务
	* 
	* @param	void
	* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
    */
	virtual u32 BindDefMtService( ) = 0; 

	/**
	*  BindDefMtService 
	* 
	* @brief 新增终端绑定默认的终端服务
	* 
	* @param	[in] tMultiServiceInfo  待处理的mt消息体
	* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
    */
	virtual u32 BindDefMtService( IN CONST TMutiTServiceDefInfo_Api &tMultiDefServiceInfo ) = 0; 

	/**
	*  ModBindDefMtService 
	* 
	* @brief 修改终端绑定默认的终端服务
	* 
	* @param	[in] tMultiServiceInfo  待处理的mt消息体
	* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
    */
	virtual u32 ModBindDefMtService( IN CONST TMutiTServiceDefInfo_Api &tMultiDefServiceInfo ) = 0; 

	/**
	*  DelBindMtService 
	* 
	* @brief 删除终端绑定默认的终端服务
	* 
	* @param	[in] tMultiServiceInfo  待处理的mt消息体
	* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
    */
	virtual u32 DelBindMtService( s8 achAlias[KMTAPI_SYS_MAX_SYSNAME_LEN] ) = 0; 
	
	/**
	*  BindMtService 
	* 
	* @brief 新增终端绑定的终端服务
	* 
	* @param	[in] tMultiServiceInfo  待处理的mt消息体
	* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
    */
	virtual u32 BindMtService( IN CONST TMutiTStartUpServiceInfo_Api &tMultiServiceInfo ) = 0; 

	/**
	*  UnBindMtService 
	* 
	* @brief 解绑终端绑定的终端服务
	* 
	* @param	[in] aachAlias  待解绑终端服务别名
	* @param	[in] wCnt  待解绑终端服务个数
	* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
    */
	virtual u32 UnBindMtService( s8 aachAlias[][KMTAPI_SYS_MAX_SYSNAME_LEN], u16 wCnt ) = 0; 

	/**
	*  StartMtService
	* 
	* @brief 启动终端绑定的终端服务
	* 
	* @param	[in] achAlias  待解绑终端服务别名
	* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
    */
	virtual u32 StartMtService( s8 achAlias[KMTAPI_SYS_MAX_SYSNAME_LEN] ) = 0; 

	/**
	*  StopMtService
	* 
	* @brief 结束终端绑定的终端服务
	* 
	* @param	[in] achAlias  待解绑终端服务别名
	* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
    */
	virtual u32 StopMtService( s8 achAlias[KMTAPI_SYS_MAX_SYSNAME_LEN] ) = 0; 

};

#endif // _MTBASEAPI_INTERFACE_IMTSERVICECTRL_H_
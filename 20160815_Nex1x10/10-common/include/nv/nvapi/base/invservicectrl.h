/**===========================================================================
 * @file    $Id$
 * @brief   负责终端功能服务开启关闭相关操作
 * @author  $Author$
 * @date    $Date$
 * @version  $Revision$ 
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note    
============================================================================*/

#ifndef _NVBASEAPI_INTERFACE_INVSERVICECTRL_H_
#define _NVBASEAPI_INTERFACE_INVSERVICECTRL_H_

#include "nvapi_typedef.h"
#include "nvapi_if.h"
#include "nvapi_event_base.h"




/**---------------------------------------------------------------------------
 * @class   Interface INvserviceCtrl
 * @brief   负责终端功能服务开启关闭相关操作的接口定义
 * @author  $Author$
 * @version 
 * @date    $Date::                      $
 * @note    
 ---------------------------------------------------------------------------*/
class INvserviceCtrl : public INvApiIF
{
public:
	/**
	*  BindDefNvService 
	* 
	* @brief 终端绑定默认的终端服务
	* 
	* @param	void
	* @return   u32  NV_SUCCESS:发送请求成功  其他：错误码
    */
	virtual u32 BindDefNvService( ) = 0; 

	/**
	*  BindDefNvService 
	* 
	* @brief 新增终端绑定默认的终端服务
	* 
	* @param	[in] tMultiServiceInfo  待处理的nv消息体
	* @return   u32  NV_SUCCESS:发送请求成功  其他：错误码
    */
	virtual u32 BindDefNvService( IN CONST nv::TNVMutiTServiceDefInfo &tMultiDefServiceInfo ) = 0; 

	/**
	*  ModBindDefNvService 
	* 
	* @brief 修改终端绑定默认的终端服务
	* 
	* @param	[in] tMultiServiceInfo  待处理的nv消息体
	* @return   u32  NV_SUCCESS:发送请求成功  其他：错误码
    */
	virtual u32 ModBindDefNvService( IN CONST nv::TNVMutiTServiceDefInfo &tMultiDefServiceInfo ) = 0; 

	/**
	*  DelBindNvService 
	* 
	* @brief 删除终端绑定默认的终端服务
	* 
	* @param	[in] tMultiServiceInfo  待处理的nv消息体
	* @return   u32  NV_SUCCESS:发送请求成功  其他：错误码
    */
	virtual u32 DelBindNvService( IN CONST nv::TString &tAlias ) = 0; 
	
	/**
	*  BindNvService 
	* 
	* @brief 新增终端绑定的终端服务
	* 
	* @param	[in] tMultiServiceInfo  待处理的nv消息体
	* @return   u32  NV_SUCCESS:发送请求成功  其他：错误码
    */
	virtual u32 BindNvService( IN CONST nv::TNVMutiTServiceInfo &tMultiServiceInfo ) = 0; 

	/**
	*  UnBindNvService 
	* 
	* @brief 解绑终端绑定的终端服务
	* 
	* @param	[in] tMultiAlias  待解绑终端服务别名
	* @return   u32  NV_SUCCESS:发送请求成功  其他：错误码
    */
	virtual u32 UnBindNvService( IN CONST nv::TMultiStr &tMultiAlias ) = 0; 

	/**
	*  StartNvService
	* 
	* @brief 启动终端绑定的终端服务
	* 
	* @param	[in] tAlias  待解绑终端服务别名
	* @return   u32  NV_SUCCESS:发送请求成功  其他：错误码
    */
	virtual u32 StartNvService( IN CONST nv::TString &tAlias ) = 0; 

	/**
	*  StopNvService
	* 
	* @brief 结束终端绑定的终端服务
	* 
	* @param	[in] tAlias  待解绑终端服务别名
	* @return   u32  NV_SUCCESS:发送请求成功  其他：错误码
    */
	virtual u32 StopNvService( IN CONST nv::TString &tAlias ) = 0; 

};

#endif // _NVBASEAPI_INTERFACE_INVSERVICECTRL_H_
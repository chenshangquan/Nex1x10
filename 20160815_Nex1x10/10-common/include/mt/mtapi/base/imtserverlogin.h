/**===========================================================================
 * @file    $Id$
 * @brief   负责终端服务器登陆相关功能的接口定义
 * @author  $Author$
 * @date    $Date$
 * @version  $Revision$ 
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note    
============================================================================*/

#ifndef _I_MTSERVERLOGIN_H_
#define _I_MTSERVERLOGIN_H_

#include "mtapi_typedef.h"
#include "mtapi_if.h"
#include "mtapi_event_base.h"




/**---------------------------------------------------------------------------
 * @class   Interface IMtUser
 * @brief   负责终端用户控制相关功能的接口定义
 * @author  $Author$
 * @version 
 * @date    $Date::                      $
 * @note    
 ---------------------------------------------------------------------------*/
class IMtServerLogin : public IMtApiIF
{
public:

	/**
	*  LoginServerCmd 
	* 
	* @brief 登陆服务器请求命令
	* 
	* @param	[in] tServerType  要登录的服务器
	* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
    */
	virtual u32 LoginServerCmd( TMtSvrList_Api tServerList ) = 0; 

	/**
	*  LoginApsServerCmd 
	* 
	* @brief 登陆APS服务器请求命令
	* 
	* @param	[in] tParam  登陆所需参数
	* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
    */
	virtual u32 LoginApsServerCmd( TMTApsLoginParam_Api tParam ) = 0; 

	/**
	*  LoginNmsServerCmd 
	* 
	* @brief 登陆NMS服务器请求命令
	* 
	* @param	[in] tParam  登陆所需参数
	* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
    */
	virtual u32 LoginNmsServerCmd( TMtNMAAddr_Api tParam ) = 0; 

	/**
	*  LogoutNmsServerCmd 
	* 
	* @brief 退出登陆NMS服务器请求命令
	* 
	* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
    */
	virtual u32 LogoutNmsServerCmd( ) = 0;

	/**
	*  LogoutApsServerCmd 
	* 
	* @brief 退出登陆APS服务器请求命令
	* 
	* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
    */
	virtual u32 LogoutApsServerCmd( ) = 0; 

	/**
	*  ModifyLoginPwdCmd 
	* 
	* @brief 修改登录密码
	* 
	* @param	[in] pchUserName  用户名
	* @param	[in] pchOldPwd    修改前的密码
	* @param	[in] pchNewPwd    修改后的密码
	*
	* @return   u32  MT_SUCCESS:成功  其他：错误码
    */
	virtual u32 ModifyLoginPwdCmd( IN CONST s8 *pchUserName, IN CONST s8 *pchOldPwd, IN CONST s8 *pchNewPwd ) = 0; 

	/**
	*  LoginPlatformAPIReq 
	* 
	* @brief 登录API
	* 
	* @param	[in] tAPI 用户信息
	*
	* @return   u32  MT_SUCCESS:成功  其他：错误码
    */
	virtual u32 LoginPlatformAPIReq( TMTWeiboLogin_Api & tAPI ) = 0;

	virtual u32 LogOutPlatformAPICmd() = 0;

    virtual u32 GetAPSPlatformInfoReq() = 0;
public:



};

#endif // _I_MTSERVERLOGIN_H_
/**===========================================================================
 * @file    $Id$
 * @brief   负责终端用户控制相关功能的接口定义
 * @author  $Author$
 * @date    $Date$
 * @version  $Revision$ 
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note    
============================================================================*/

#ifndef _I_NVUSER_H_
#define _I_NVUSER_H_

#include "nvapi_typedef.h"
#include "nvapi_if.h"
#include "nvapi_event_base.h"




/**---------------------------------------------------------------------------
 * @class   Interface INvUser
 * @brief   负责终端用户控制相关功能的接口定义
 * @author  $Author$
 * @version 
 * @date    $Date::                      $
 * @note    
 ---------------------------------------------------------------------------*/
class INvUser : public INvApiIF
{
public:
	
	/**
	*  LoginReq 
	* 
	* @brief 账号登录验证请求
	* 
	* @param	[in] tUserInfo  用户信息
	* @return   u32  NV_SUCCESS:发送请求成功  其他：错误码
    */
	virtual u32 LoginReq( IN CONST nv::TNVUserFullInfo& tUserInfo ) = 0;
	/**
	*  LogoutCmd 
	* 
	* @brief 账号注销命令
	* 
	* @param	[in] tUserName  用户名
	* @return   u32  NV_SUCCESS:发送请求成功  其他：错误码
    */
	virtual u32 LogoutCmd( IN CONST nv::TString& tUserName ) = 0;
	/**
	*  AddUserReq 
	* 
	* @brief 添加终端用户请求(支持批量操作)
	* 
	* @param	[in] tUserList  待处理的nv消息体
	* @return   u32  NV_SUCCESS:发送请求成功  其他：错误码
    */
	virtual u32 AddUserReq( const nv::TNVMultiUserFullInfo& tUserList ) = 0; 

	/**
	*  ModifyUserReq 
	* 
	* @brief 修改用户请求(支持批量操作)
	* 
	* @param	[in] tUserList  待处理的nv消息体
	* @return   u32  NV_SUCCESS:发送请求成功  其他：错误码
    */
	virtual u32 ModifyUserReq( const nv::TNVMultiUserFullInfo& tUserList ) = 0;
 
	/**
	*  DeleteUserReq 
	* 
	* @brief 删除用户请求(支持批量操作)
	* 
	* @param	[in] tMulUser  用户ID
	* @return   u32  NV_SUCCESS:发送请求成功  其他：错误码
    */
	virtual u32 DeleteUserReq( const nv::TMultiU32& tMulUser ) = 0;

	/**
	*  GetUserListReq 
	* 
	* @brief 用户信息列表请求
	* 
	* @param	[in] void
	* @return   u32  NV_SUCCESS:发送请求成功  其他：错误码
    */
	virtual u32 GetUserListReq() = 0;

public:

	/**
	*  GetUserListCnt 
	* 
	* @brief  获取用户数量
	* 
	* @param	[in] void
	* @return   u32  返回用户个数
    */
	virtual const u32 GetUserListCnt() = 0;


	/**
	*  GetUserByIdx 
	* 
	* @brief 获取指定索引的用户信息
	* 
	* @param	[in]  nIdx    要获取的用户索引信息
	* @param	[out] tUser   用户信息
	* @return   u32  0：成功获取， 其他：错误码
    */
	virtual const u32 GetUserByIdx( const s32 nIdx, nv::TNVUserFullInfo& tUser ) = 0; 

	/**
	*  GetUserByUsrID 
	* 
	* @brief 获取指定用户ID的用户详细信息
	* 
	* @param	[in]  dwUserID    要获取的用户ID信息
	* @param	[out] tUser   用户信息
	* @return    u32  0：成功获取， 其他：错误码
	*/
	virtual const u32 GetUserByUsrID( const u32 dwUserID, nv::TNVUserFullInfo& tUser ) = 0; 
};

#endif // _I_NVUSER_H_
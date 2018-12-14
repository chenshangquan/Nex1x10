/**===========================================================================
 * @file    $Id$
 * @brief   负责终端用户控制相关功能的接口定义
 * @author  $Author$
 * @date    $Date$
 * @version  $Revision$ 
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note    
============================================================================*/

#ifndef _I_MTUSER_H_
#define _I_MTUSER_H_

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
class IMtUser : public IMtApiIF
{
public:
	
	/**
	*  LoginReq 
	* 
	* @brief 账号登录验证请求
	* 
	* @param	[in] strUser  用户名
	* @param	[in] strPwd   密码（密文）
	* @param	[in] emMtcType   终端类型
	* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
    */
	virtual u32 LoginReq( const mtstring& strUser, const mtstring& strPwd ) = 0;
	/**
	*  LogoutCmd 
	* 
	* @brief 账号注销命令
	* 
	* @param	[in] pchUserName  用户名
	* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
    */
	virtual u32 LogoutCmd( const s8 *pchUserName) = 0;
	/**
	*  AddUserReq 
	* 
	* @brief 添加终端用户请求(支持批量操作)
	* 
	* @param	[in] tUserList  待处理的mt消息体
	* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
    */
	virtual u32 AddUserReq( const TMultiUserFullInfo_Api& tUserList ) = 0; 

	/**
	*  ModifyUserReq 
	* 
	* @brief 修改用户请求(支持批量操作)
	* 
	* @param	[in] tUserList  待处理的mt消息体
	* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
    */
	virtual u32 ModifyUserReq( const TMultiUserFullInfo_Api& tUserList ) = 0;
 
	/**
	*  DeleteUserReq 
	* 
	* @brief 删除用户请求(支持批量操作)
	* 
	* @param	[in] dwUserIDs  用户ID
	* @param	[in] dwCnt  用户ID总数
	* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
    */
	virtual u32 DeleteUserReq( const u32 dwUserIDs[], const u32 dwCnt ) = 0;

	/**
	*  GetUserListReq 
	* 
	* @brief 用户信息列表请求
	* 
	* @param	[in] void
	* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
    */
	virtual u32 GetUserListReq() = 0;

	/**
	*  GetMtcInfoListReq
	* 
	* @brief  MTC信息列表请求
	* 
	* @param	[in] void
	* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
    */
	virtual u32 GetMtcInfoListReq() = 0;

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
	virtual const u32 GetUserByIdx( const s32 nIdx, TUserFullInfo_Api& tUser ) = 0; 

	/**
	*  GetUserByUsrID 
	* 
	* @brief 获取指定用户ID的用户详细信息
	* 
	* @param	[in]  dwUserID    要获取的用户ID信息
	* @param	[out] tUser   用户信息
	* @return    u32  0：成功获取， 其他：错误码
	*/
	virtual const u32 GetUserByUsrID( const u32 dwUserID, TUserFullInfo_Api& tUser ) = 0; 

	virtual const BOOL32 GetSkyShareLoginState() = 0;
	virtual const u32 GetSkyShareLoginStateReq() = 0;
	virtual u32 GetTrueRanderBytes(const u16 wLen ) = 0;
	virtual u32 GetWebMtcLoginStateReq() = 0;
	virtual BOOL32 GetWebMtcLoginState() = 0;

	virtual u32 GetDynamicPwdCmd() = 0;
	virtual u32 CheckDataConfDynamicPwdCmd( const s8 *pchDynPwd ) = 0;
	virtual u32 CleanDataConfDynamicPwdCmd() = 0;
	virtual u32 GetLoginDynamicPwdCmd() = 0;

	virtual u32 GetUserPwdRestTimeReq() = 0;
	virtual u32 SetUserLoginUnLockCmd() = 0;
	virtual u32 GetUserLoginLockStateReq() = 0;
	virtual BOOL32 GetUserLoginLockState() = 0;

};

#endif // _I_MTUSER_H_
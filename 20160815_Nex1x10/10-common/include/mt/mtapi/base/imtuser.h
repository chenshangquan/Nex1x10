/**===========================================================================
 * @file    $Id$
 * @brief   �����ն��û�������ع��ܵĽӿڶ���
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
 * @brief   �����ն��û�������ع��ܵĽӿڶ���
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
	* @brief �˺ŵ�¼��֤����
	* 
	* @param	[in] strUser  �û���
	* @param	[in] strPwd   ���루���ģ�
	* @param	[in] emMtcType   �ն�����
	* @return   u32  MT_SUCCESS:��������ɹ�  ������������
    */
	virtual u32 LoginReq( const mtstring& strUser, const mtstring& strPwd ) = 0;
	/**
	*  LogoutCmd 
	* 
	* @brief �˺�ע������
	* 
	* @param	[in] pchUserName  �û���
	* @return   u32  MT_SUCCESS:��������ɹ�  ������������
    */
	virtual u32 LogoutCmd( const s8 *pchUserName) = 0;
	/**
	*  AddUserReq 
	* 
	* @brief ����ն��û�����(֧����������)
	* 
	* @param	[in] tUserList  �������mt��Ϣ��
	* @return   u32  MT_SUCCESS:��������ɹ�  ������������
    */
	virtual u32 AddUserReq( const TMultiUserFullInfo_Api& tUserList ) = 0; 

	/**
	*  ModifyUserReq 
	* 
	* @brief �޸��û�����(֧����������)
	* 
	* @param	[in] tUserList  �������mt��Ϣ��
	* @return   u32  MT_SUCCESS:��������ɹ�  ������������
    */
	virtual u32 ModifyUserReq( const TMultiUserFullInfo_Api& tUserList ) = 0;
 
	/**
	*  DeleteUserReq 
	* 
	* @brief ɾ���û�����(֧����������)
	* 
	* @param	[in] dwUserIDs  �û�ID
	* @param	[in] dwCnt  �û�ID����
	* @return   u32  MT_SUCCESS:��������ɹ�  ������������
    */
	virtual u32 DeleteUserReq( const u32 dwUserIDs[], const u32 dwCnt ) = 0;

	/**
	*  GetUserListReq 
	* 
	* @brief �û���Ϣ�б�����
	* 
	* @param	[in] void
	* @return   u32  MT_SUCCESS:��������ɹ�  ������������
    */
	virtual u32 GetUserListReq() = 0;

	/**
	*  GetMtcInfoListReq
	* 
	* @brief  MTC��Ϣ�б�����
	* 
	* @param	[in] void
	* @return   u32  MT_SUCCESS:��������ɹ�  ������������
    */
	virtual u32 GetMtcInfoListReq() = 0;

public:

	/**
	*  GetUserListCnt 
	* 
	* @brief  ��ȡ�û�����
	* 
	* @param	[in] void
	* @return   u32  �����û�����
    */
	virtual const u32 GetUserListCnt() = 0;


	/**
	*  GetUserByIdx 
	* 
	* @brief ��ȡָ���������û���Ϣ
	* 
	* @param	[in]  nIdx    Ҫ��ȡ���û�������Ϣ
	* @param	[out] tUser   �û���Ϣ
	* @return   u32  0���ɹ���ȡ�� ������������
    */
	virtual const u32 GetUserByIdx( const s32 nIdx, TUserFullInfo_Api& tUser ) = 0; 

	/**
	*  GetUserByUsrID 
	* 
	* @brief ��ȡָ���û�ID���û���ϸ��Ϣ
	* 
	* @param	[in]  dwUserID    Ҫ��ȡ���û�ID��Ϣ
	* @param	[out] tUser   �û���Ϣ
	* @return    u32  0���ɹ���ȡ�� ������������
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
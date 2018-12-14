/**===========================================================================
 * @file    $Id$
 * @brief   �����ն��û�������ع��ܵĽӿڶ���
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
 * @brief   �����ն��û�������ع��ܵĽӿڶ���
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
	* @brief �˺ŵ�¼��֤����
	* 
	* @param	[in] tUserInfo  �û���Ϣ
	* @return   u32  NV_SUCCESS:��������ɹ�  ������������
    */
	virtual u32 LoginReq( IN CONST nv::TNVUserFullInfo& tUserInfo ) = 0;
	/**
	*  LogoutCmd 
	* 
	* @brief �˺�ע������
	* 
	* @param	[in] tUserName  �û���
	* @return   u32  NV_SUCCESS:��������ɹ�  ������������
    */
	virtual u32 LogoutCmd( IN CONST nv::TString& tUserName ) = 0;
	/**
	*  AddUserReq 
	* 
	* @brief ����ն��û�����(֧����������)
	* 
	* @param	[in] tUserList  �������nv��Ϣ��
	* @return   u32  NV_SUCCESS:��������ɹ�  ������������
    */
	virtual u32 AddUserReq( const nv::TNVMultiUserFullInfo& tUserList ) = 0; 

	/**
	*  ModifyUserReq 
	* 
	* @brief �޸��û�����(֧����������)
	* 
	* @param	[in] tUserList  �������nv��Ϣ��
	* @return   u32  NV_SUCCESS:��������ɹ�  ������������
    */
	virtual u32 ModifyUserReq( const nv::TNVMultiUserFullInfo& tUserList ) = 0;
 
	/**
	*  DeleteUserReq 
	* 
	* @brief ɾ���û�����(֧����������)
	* 
	* @param	[in] tMulUser  �û�ID
	* @return   u32  NV_SUCCESS:��������ɹ�  ������������
    */
	virtual u32 DeleteUserReq( const nv::TMultiU32& tMulUser ) = 0;

	/**
	*  GetUserListReq 
	* 
	* @brief �û���Ϣ�б�����
	* 
	* @param	[in] void
	* @return   u32  NV_SUCCESS:��������ɹ�  ������������
    */
	virtual u32 GetUserListReq() = 0;

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
	virtual const u32 GetUserByIdx( const s32 nIdx, nv::TNVUserFullInfo& tUser ) = 0; 

	/**
	*  GetUserByUsrID 
	* 
	* @brief ��ȡָ���û�ID���û���ϸ��Ϣ
	* 
	* @param	[in]  dwUserID    Ҫ��ȡ���û�ID��Ϣ
	* @param	[out] tUser   �û���Ϣ
	* @return    u32  0���ɹ���ȡ�� ������������
	*/
	virtual const u32 GetUserByUsrID( const u32 dwUserID, nv::TNVUserFullInfo& tUser ) = 0; 
};

#endif // _I_NVUSER_H_
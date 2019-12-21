/**===========================================================================
 * @file    $Id$
 * @brief   �����ն˷�������½��ع��ܵĽӿڶ���
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
 * @brief   �����ն��û�������ع��ܵĽӿڶ���
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
	* @brief ��½��������������
	* 
	* @param	[in] tServerType  Ҫ��¼�ķ�����
	* @return   u32  MT_SUCCESS:��������ɹ�  ������������
    */
	virtual u32 LoginServerCmd( TMtSvrList_Api tServerList ) = 0; 

	/**
	*  LoginApsServerCmd 
	* 
	* @brief ��½APS��������������
	* 
	* @param	[in] tParam  ��½�������
	* @return   u32  MT_SUCCESS:��������ɹ�  ������������
    */
	virtual u32 LoginApsServerCmd( TMTApsLoginParam_Api tParam ) = 0; 

	/**
	*  LoginNmsServerCmd 
	* 
	* @brief ��½NMS��������������
	* 
	* @param	[in] tParam  ��½�������
	* @return   u32  MT_SUCCESS:��������ɹ�  ������������
    */
	virtual u32 LoginNmsServerCmd( TMtNMAAddr_Api tParam ) = 0; 

	/**
	*  LogoutNmsServerCmd 
	* 
	* @brief �˳���½NMS��������������
	* 
	* @return   u32  MT_SUCCESS:��������ɹ�  ������������
    */
	virtual u32 LogoutNmsServerCmd( ) = 0;

	/**
	*  LogoutApsServerCmd 
	* 
	* @brief �˳���½APS��������������
	* 
	* @return   u32  MT_SUCCESS:��������ɹ�  ������������
    */
	virtual u32 LogoutApsServerCmd( ) = 0; 

	/**
	*  ModifyLoginPwdCmd 
	* 
	* @brief �޸ĵ�¼����
	* 
	* @param	[in] pchUserName  �û���
	* @param	[in] pchOldPwd    �޸�ǰ������
	* @param	[in] pchNewPwd    �޸ĺ������
	*
	* @return   u32  MT_SUCCESS:�ɹ�  ������������
    */
	virtual u32 ModifyLoginPwdCmd( IN CONST s8 *pchUserName, IN CONST s8 *pchOldPwd, IN CONST s8 *pchNewPwd ) = 0; 

	/**
	*  LoginPlatformAPIReq 
	* 
	* @brief ��¼API
	* 
	* @param	[in] tAPI �û���Ϣ
	*
	* @return   u32  MT_SUCCESS:�ɹ�  ������������
    */
	virtual u32 LoginPlatformAPIReq( TMTWeiboLogin_Api & tAPI ) = 0;

	virtual u32 LogOutPlatformAPICmd() = 0;

    virtual u32 GetAPSPlatformInfoReq() = 0;
public:



};

#endif // _I_MTSERVERLOGIN_H_
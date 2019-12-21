/**===========================================================================
 * @file    $Id$
 * @brief   ����mtcontactmgrapi �������豸,����豸��Ϣ��ع��ܽӿڶ���
 * @author  $Author$
 * @date    $Date$
 * @version  $Revision$ 
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note    
============================================================================*/

#ifndef _I_MTOTHERCONTACT_H_
#define _I_MTOTHERCONTACT_H_

#include "mtapi_typedef.h"
#include "mtapi_if.h"
#include "mtapi_event_cm.h"


/**---------------------------------------------------------------------------
 * @class   Interface IMtOtherContact
 * @brief   ����mtcontactmgrapi �������豸,����豸��Ϣ��ع��ܽӿڶ���
 * @author  $Author$
 * @version 
 * @date    $Date::                      $
 * @note    
 ---------------------------------------------------------------------------*/

class IMtOtherContact : public IMtApiIF
{
public:
	//��ѯ�˺���ϸ��Ϣ����
	virtual u32 GetAccountInfoReq( const TMTAccountManagerSystem_Api & tAccount ) = 0;

	//�޸��˺���ϸ��Ϣ����
	virtual u32 UpdateAccountInfoReq( const TMTAccountManagerSystem_Api & tAccount ) = 0;

	//�޸��˺���������
	virtual u32 UpdatePasswordReq( const TMTModifyPwd_Api & tPsw ) = 0;

	//��������������
	virtual u32 PassWordByMailReq( const s8 * pchMail ) = 0;

	//��ȡ�������ն��豸��汾��Ϣ����
	virtual u32 GetThirdPartyTerminalSysVersionReq( ) = 0;

	//��ȡ�������ն��豸����豸��Ϣ����
	virtual u32 GetAllThirdPartyTerminalsReq( ) = 0;

	//��ȡ�������ն��豸����Ϣ����
	virtual u32 GetThirdPartyTerminalGroupsReq( ) = 0;

	//��ȡ�������ն��豸�����豸��Ϣ(�������ӷ���)����
	virtual u32 GetThirdPartyTerminalsInGroupReq( const u32  dwGroupId ) = 0;

	//��ȡ����豸��汾��Ϣ����
	virtual u32 GetMonitorGroupVersionReq( ) = 0;

	//��ȡ����豸����豸��Ϣ����
	virtual u32 GetAllMonitorsReq( ) = 0;

	//��ȡ����豸����Ϣ����
	virtual u32 GetMonitorGroupReq( ) = 0;

	//��ȡ����豸�����豸��Ϣ(�������ӷ���)����
	virtual u32 GetMonitorsInGroupReq( ) = 0;

};

#endif // _I_MTOTHERCONTACT_H_
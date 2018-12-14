/**===========================================================================
 * @file    $Id$
 * @brief   ������֯�ܹ���ع��ܽӿڶ���
 * @author  $Author$
 * @date    $Date$
 * @version  $Revision$ 
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note    
============================================================================*/

#ifndef _I_MTORGANIZATION_H_
#define _I_MTORGANIZATION_H_

#include "mtapi_typedef.h"
#include "mtapi_if.h"
#include "mtapi_event_cm.h"


/**---------------------------------------------------------------------------
 * @class   Interface IMtOrganazation
 * @brief   ������֯�ܹ���ع��ܽӿڶ���
 * @author  $Author$
 * @version 
 * @date    $Date::                      $
 * @note    
 ---------------------------------------------------------------------------*/
class IMtOrganazation: public IMtApiIF
{
public:

	//��ȡ��֯�ܹ��汾��
	virtual u32    GetDepartmentVersionReq(  ) = 0;
	//�����ҵ�����ַ���汾��Ϣ
	virtual u32    GetSharedDirectoryVersionReq( u32 dwDepartmentID  ) = 0;
	//�����ҵ�����ַ����Ϣ����
	virtual u32    GetSharedDirectoryReq( ) = 0;

	//��ù�˾��֯�ܹ���������Ա��Ϣ����
	virtual u32 GetDepartmentAllReq() = 0;

	//��ȡ��˾��֯�ܹ�������Ϣ����
	virtual u32 GetDepartmentCompanyReq() = 0;

	//��ȡ��������Ա��Ϣ(�������Ӳ���)����
	virtual u32 GetDepartmentUserReq( u32 dwDepartmentID ) = 0;

	//������ѯ��ҵ��ϵ������
	virtual u32 ConditionQueryReq( const TMTConditionQuery_Api & tInfo ) = 0;

	//�����û���Ϣ����
	virtual u32 QueryUserInfoReq( const TMTQueryUser_Api & tUser ) = 0;

	//���ñ���ͷ���·��
	virtual u32 SetPortraitPathCmd( const s8 * pchPath ) = 0;

	//�����û�ͷ������
	virtual u32 GetUserPortraitReq( const TMTQueryPortrait_Api & tPortrait ) = 0;

	//�޸��û�ͷ������
	virtual u32 MotifyUserPortraitReq( const TMTModifyPortrait_Api & tPortrait ) = 0;

	//�޸ĸ��˽�������
	virtual u32 UpdateUserBriefReq( const TMTModifyBrief_Api & tBrief ) = 0;

	//������ģ�����ұ���ҵ��ϵ������
	virtual u32 GetUserListByStrReq( const TMTUserListByStr_Api & tUserList ) = 0;

	//���������ϵ����֤ģʽ����
	virtual u32 SetAuthModeReq( const TMTSetAuthMode_Api & tSetAuthMode ) = 0;

	//�����֯�ܹ���������
	virtual u32 GetCompanyEmployeeCountReq(const s8 *pchUserDomainMoid ) = 0;

	virtual u32 GetUserDomainAddressBookForPageReq(const u32 &dwStart, const u32 &dwCount) = 0;
    virtual u32 ResumeUserPortraitReq( const s8 *pchUserName ) = 0;
    //��ȡ�û�����Ϣ
    virtual u32 RestGetUserDomainReq( ) = 0;
    //��ȡָ���û�����֯�ܹ���Ϣ
    virtual u32 RestGetUserDomainDepartmentsReq( const s8 *pchUserDomainMoid ) = 0;
    //��ȡ�û���������Ա��Ϣ
    virtual u32 RestGetAllUserDomainUserReq( const s8 *pchUserDomainMoid ) = 0;
    //��ü�����֯�ܹ�������Ա����
    virtual u32 RestGetGroupAllDepartmentUserCountReq() = 0;

    //��ȡ������Ϣ
    virtual u32 RestGetGroupReq() = 0;
    //��ȡ���Ź���Ⱥ��汾��
    virtual u32 RestGetPublicGroupVersionReq() = 0;
    //��ȡ���Ź���Ⱥ��
    virtual u32 RestGetPublicGroupReq() = 0;
    //��ȡ���Ź���Ⱥ��������Ա��Ϣ
    virtual u32 RestGetPublicGroupUserReq() = 0;

private:

};

#endif // _I_MTORGANIZATION_H_
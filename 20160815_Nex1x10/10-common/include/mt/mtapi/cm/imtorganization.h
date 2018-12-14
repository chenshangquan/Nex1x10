/**===========================================================================
 * @file    $Id$
 * @brief   负责组织架构相关功能接口定义
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
 * @brief   负责组织架构相关功能接口定义
 * @author  $Author$
 * @version 
 * @date    $Date::                      $
 * @note    
 ---------------------------------------------------------------------------*/
class IMtOrganazation: public IMtApiIF
{
public:

	//获取组织架构版本号
	virtual u32    GetDepartmentVersionReq(  ) = 0;
	//获得企业共享地址簿版本信息
	virtual u32    GetSharedDirectoryVersionReq( u32 dwDepartmentID  ) = 0;
	//获得企业共享地址簿信息请求
	virtual u32    GetSharedDirectoryReq( ) = 0;

	//获得公司组织架构和所有人员信息请求
	virtual u32 GetDepartmentAllReq() = 0;

	//获取公司组织架构部门信息请求
	virtual u32 GetDepartmentCompanyReq() = 0;

	//获取部门下人员信息(不包含子部门)请求
	virtual u32 GetDepartmentUserReq( u32 dwDepartmentID ) = 0;

	//条件查询企业联系人请求
	virtual u32 ConditionQueryReq( const TMTConditionQuery_Api & tInfo ) = 0;

	//请求用户信息请求
	virtual u32 QueryUserInfoReq( const TMTQueryUser_Api & tUser ) = 0;

	//设置保存头像的路径
	virtual u32 SetPortraitPathCmd( const s8 * pchPath ) = 0;

	//请求用户头像请求
	virtual u32 GetUserPortraitReq( const TMTQueryPortrait_Api & tPortrait ) = 0;

	//修改用户头像请求
	virtual u32 MotifyUserPortraitReq( const TMTModifyPortrait_Api & tPortrait ) = 0;

	//修改个人介绍请求
	virtual u32 UpdateUserBriefReq( const TMTModifyBrief_Api & tBrief ) = 0;

	//按姓名模糊查找本企业联系人请求
	virtual u32 GetUserListByStrReq( const TMTUserListByStr_Api & tUserList ) = 0;

	//设置添加联系人认证模式请求
	virtual u32 SetAuthModeReq( const TMTSetAuthMode_Api & tSetAuthMode ) = 0;

	//获得组织架构人数请求
	virtual u32 GetCompanyEmployeeCountReq(const s8 *pchUserDomainMoid ) = 0;

	virtual u32 GetUserDomainAddressBookForPageReq(const u32 &dwStart, const u32 &dwCount) = 0;
    virtual u32 ResumeUserPortraitReq( const s8 *pchUserName ) = 0;
    //获取用户域信息
    virtual u32 RestGetUserDomainReq( ) = 0;
    //获取指定用户域组织架构信息
    virtual u32 RestGetUserDomainDepartmentsReq( const s8 *pchUserDomainMoid ) = 0;
    //获取用户域所有人员信息
    virtual u32 RestGetAllUserDomainUserReq( const s8 *pchUserDomainMoid ) = 0;
    //获得集团组织架构所有人员总数
    virtual u32 RestGetGroupAllDepartmentUserCountReq() = 0;

    //获取集团信息
    virtual u32 RestGetGroupReq() = 0;
    //获取集团公共群组版本号
    virtual u32 RestGetPublicGroupVersionReq() = 0;
    //获取集团公共群组
    virtual u32 RestGetPublicGroupReq() = 0;
    //获取集团公共群组所有人员信息
    virtual u32 RestGetPublicGroupUserReq() = 0;

private:

};

#endif // _I_MTORGANIZATION_H_
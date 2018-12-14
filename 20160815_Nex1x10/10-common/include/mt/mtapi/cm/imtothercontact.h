/**===========================================================================
 * @file    $Id$
 * @brief   负责mtcontactmgrapi 第三方设备,监控设备信息相关功能接口定义
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
 * @brief   负责mtcontactmgrapi 第三方设备,监控设备信息相关功能接口定义
 * @author  $Author$
 * @version 
 * @date    $Date::                      $
 * @note    
 ---------------------------------------------------------------------------*/

class IMtOtherContact : public IMtApiIF
{
public:
	//查询账号详细信息请求
	virtual u32 GetAccountInfoReq( const TMTAccountManagerSystem_Api & tAccount ) = 0;

	//修改账号详细信息请求
	virtual u32 UpdateAccountInfoReq( const TMTAccountManagerSystem_Api & tAccount ) = 0;

	//修改账号密码请求
	virtual u32 UpdatePasswordReq( const TMTModifyPwd_Api & tPsw ) = 0;

	//忘记密码后的请求
	virtual u32 PassWordByMailReq( const s8 * pchMail ) = 0;

	//获取第三方终端设备组版本信息请求
	virtual u32 GetThirdPartyTerminalSysVersionReq( ) = 0;

	//获取第三方终端设备组和设备信息请求
	virtual u32 GetAllThirdPartyTerminalsReq( ) = 0;

	//获取第三方终端设备组信息请求
	virtual u32 GetThirdPartyTerminalGroupsReq( ) = 0;

	//获取第三方终端设备组下设备信息(不包含子分组)请求
	virtual u32 GetThirdPartyTerminalsInGroupReq( const u32  dwGroupId ) = 0;

	//获取监控设备组版本信息请求
	virtual u32 GetMonitorGroupVersionReq( ) = 0;

	//获取监控设备组和设备信息请求
	virtual u32 GetAllMonitorsReq( ) = 0;

	//获取监控设备组信息请求
	virtual u32 GetMonitorGroupReq( ) = 0;

	//获取监控设备组下设备信息(不包含子分组)请求
	virtual u32 GetMonitorsInGroupReq( ) = 0;

};

#endif // _I_MTOTHERCONTACT_H_
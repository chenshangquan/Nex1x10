/**===========================================================================
 * @file    $Id$
 * @brief   负责NvBaseApi终端网络相关功能接口定义
 * @author  $Author$
 * @date    $Date$
 * @version  $Revision$ 
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note    
============================================================================*/

#ifndef _I_NVNETWORK_H_
#define _I_NVNETWORK_H_

#include "nvapi_typedef.h"
#include "nvapi_if.h"


/**---------------------------------------------------------------------------
 * @class   Interface INvNetwork
 * @brief   负责NvBaseApi终端网络相关功能接口定义
 * @author  $Author$
 * @version 
 * @date    $Date::                      $
 * @note    
 ---------------------------------------------------------------------------*/
class INvNetwork: public INvApiIF
{
public:
	//设置当前日期时间信息
	virtual u32 SetSysDataTimeReq(const  nv::TNVTime &tTime) = 0;
	//获取终端当前日期时间信息
	virtual u32 GetMtSysDataTimeReq() = 0;
	//获取终端当前时间配置信息
	virtual u32 GetMtSysTimeCfgReq() = 0;
	//ping包回应
	virtual u32 SetPingTestRsp(const nv::TBOOL32 tResult) = 0;
	//获取当前日期时间信息
	virtual u32 GetSysDataTimeReq() = 0;
	//打开ftp
	virtual u32 OpenFtpCmd( const nv::TBOOL32 tbOpen) = 0;

	//获取ftp状态
	virtual u32 GetFtpStateReq() = 0;

};

#endif // _I_NVNETWORK_H_
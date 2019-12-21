/**===========================================================================
 * @file    $Id$
 * @brief   负责终端网管功能的接口定义
 * @author  $Author$
 * @date    $Date$
 * @version  $Revision$ 
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note    
============================================================================*/

#ifndef _I_MTAGENT_H_
#define _I_MTAGENT_H_

#include "mtapi_typedef.h"
#include "mtapi_if.h"
#include "mtapi_event_base.h"




/**---------------------------------------------------------------------------
 * @class   Interface IMtAgent
 * @brief   负责终端通用功能的接口定义
 * @author  $Author$
 * @version 
 * @date    $Date::                      $
 * @note    
 ---------------------------------------------------------------------------*/
class IMtAgent : public IMtApiIF
{
public:
	//上报终端设备性能
	virtual u32 ReportAgentMtPFMInfo( const TMtPFMInfo_Api& tInfo_Api ) = 0;

	//异常文件内容上报
	virtual u32 AgentCrashLogReportCmd(const TExceptionFileReportData_Api& tCrashLog_Api) = 0;

	//需要登录的服务器上报
	virtual u32 AgentShoudConnectServersReportCmd(const EmServerType_Api aemServers[], u16 wCount) = 0;
    //设置网管上报日志的文件信息
    virtual u32 AgentSetPackLogInfoCmd(const TAgentLogFileInfo_Api &tLogFileInfo) = 0;
    //日志打包完成，通知网管上传日志
    virtual u32 AgentStartUploadLogReq() = 0;
    //终端打包文件按错误信息上报
    virtual u32 AgentPackFileStateReq(const TAgentPackFileState_Api &tPackState) = 0;
public:

};

#endif // _I_MTCOMMON_H_
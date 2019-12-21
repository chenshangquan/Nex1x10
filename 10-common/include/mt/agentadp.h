/**===========================================================================
 * @file    agentapi.h
 * @brief   网管适配模块接口头文件
 * @author  ruiyigen
 * @date    20140616
 * @version 5.0 
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
============================================================================*/
#if !defined(_AGENTAPI_H_)
#define _AGENTAPI_H_
#include <string>

#include "kdvtype.h"
#include "mtstruct.h"
#include "mtmacro.h"

///<错误码
#define SNMP_SUCCESS               (u8)0
#define SNMP_FINISHED              (u8)1
#define SNMP_NOFINISHED            (u8)2
#define SNMP_GENERAL_ERROR         (u8)3
#define SNMP_RESOURCE_UNAVAIL      (u8)4
#define SNMP_INTERNAL_ERROR        (u8)5
#define SNMP_UNSUPPORTED           (u8)6

#define TNM_CONNECT_TIMEOUT        (u32)(10 * 1000)     // 连接超时时间(单位秒)
#define TNM_REGISTER_TIMEOUT       (u32)(45 * 1000)     // 注册超时时间(单位秒)

extern "C"
{

	/**----------------------------------------------------------------------
	* AgentAdpStart
	* 
	* @brief   网管适配模块启动
	* 
	* @param   void
	* @return  BOOL32 TRUE:成功启动， FALSE:启动失败
	* @see     AgentAdpStop()
	------------------------------------------------------------------------*/
	MTCBB_API BOOL32 AgentAdpStart();

	/**----------------------------------------------------------------------
	* AgentAdpStart
	* 
	* @brief   网管适配模块退出接口
	* 
	* @param   void
	* @return  BOOL32 TRUE:成功退出， FALSE:退出失败
	* @see     AgentAdpStart()
	------------------------------------------------------------------------*/
	MTCBB_API BOOL32 AgentAdpStop();

};

#endif // _AGENTAPI_H_

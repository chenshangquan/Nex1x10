/**===========================================================================
 * @file    agentapi.h
 * @brief   ��������ģ��ӿ�ͷ�ļ�
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

///<������
#define SNMP_SUCCESS               (u8)0
#define SNMP_FINISHED              (u8)1
#define SNMP_NOFINISHED            (u8)2
#define SNMP_GENERAL_ERROR         (u8)3
#define SNMP_RESOURCE_UNAVAIL      (u8)4
#define SNMP_INTERNAL_ERROR        (u8)5
#define SNMP_UNSUPPORTED           (u8)6

#define TNM_CONNECT_TIMEOUT        (u32)(10 * 1000)     // ���ӳ�ʱʱ��(��λ��)
#define TNM_REGISTER_TIMEOUT       (u32)(45 * 1000)     // ע�ᳬʱʱ��(��λ��)

extern "C"
{

	/**----------------------------------------------------------------------
	* AgentAdpStart
	* 
	* @brief   ��������ģ������
	* 
	* @param   void
	* @return  BOOL32 TRUE:�ɹ������� FALSE:����ʧ��
	* @see     AgentAdpStop()
	------------------------------------------------------------------------*/
	MTCBB_API BOOL32 AgentAdpStart();

	/**----------------------------------------------------------------------
	* AgentAdpStart
	* 
	* @brief   ��������ģ���˳��ӿ�
	* 
	* @param   void
	* @return  BOOL32 TRUE:�ɹ��˳��� FALSE:�˳�ʧ��
	* @see     AgentAdpStart()
	------------------------------------------------------------------------*/
	MTCBB_API BOOL32 AgentAdpStop();

};

#endif // _AGENTAPI_H_

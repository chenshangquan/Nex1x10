/**===========================================================================
 * @file    $Id$
 * @brief   �����ն����ܹ��ܵĽӿڶ���
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
 * @brief   �����ն�ͨ�ù��ܵĽӿڶ���
 * @author  $Author$
 * @version 
 * @date    $Date::                      $
 * @note    
 ---------------------------------------------------------------------------*/
class IMtAgent : public IMtApiIF
{
public:
	//�ϱ��ն��豸����
	virtual u32 ReportAgentMtPFMInfo( const TMtPFMInfo_Api& tInfo_Api ) = 0;

	//�쳣�ļ������ϱ�
	virtual u32 AgentCrashLogReportCmd(const TExceptionFileReportData_Api& tCrashLog_Api) = 0;

	//��Ҫ��¼�ķ������ϱ�
	virtual u32 AgentShoudConnectServersReportCmd(const EmServerType_Api aemServers[], u16 wCount) = 0;
    //���������ϱ���־���ļ���Ϣ
    virtual u32 AgentSetPackLogInfoCmd(const TAgentLogFileInfo_Api &tLogFileInfo) = 0;
    //��־�����ɣ�֪ͨ�����ϴ���־
    virtual u32 AgentStartUploadLogReq() = 0;
    //�ն˴���ļ���������Ϣ�ϱ�
    virtual u32 AgentPackFileStateReq(const TAgentPackFileState_Api &tPackState) = 0;
public:

};

#endif // _I_MTCOMMON_H_
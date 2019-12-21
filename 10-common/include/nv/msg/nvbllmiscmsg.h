/*---------------------------------------------------------------------------*/
/*
 * @file    $Id$
 * @brief   Сҵ������Ϣ����
 * @author  �Ĵ���
 * @date    $Date$
 * @version  $Revision$
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * 
 */
/*---------------------------------------------------------------------------*/

#ifndef _NVBLLMISCMSG_H_
#define _NVBLLMISCMSG_H_

#include "nvmsgid.h"

#if !defined(_MESSAGE_HELP_)
enum EmBLLMiscMsg
{
    EV_BLL_BGN(MISC) = EVSEG_BLL_MISC_BGN,
#endif

	/*<<ϵͳ��ʾ>>
	* all -> ui
	*/
    MESSAGE(Ev_NV_BLL_SysHint_Ntf)
	BODY(nv::TSysHint, sys_hint)	//��ʾ����

	/*<<����������>>
	* ui -> misc
	*/
	MESSAGE(Ev_NV_BLL_BandwidthTest_Cmd)
	

	/*<<��������֪ͨ>>
	* misc -> ui
	*/
	MESSAGE(Ev_NV_BLL_BandwidthTestResult_Ntf)
	BODY(nv::TNVNetStatus, is_ok)

	/*<< ���绷���ı���֪ͨ��Ϣ >>
	*    ui -> nvservice
	*/
	MESSAGE(Ev_NV_BLL_NetInfo_Ntf)  
	BODY(nv::TNetUsedInfo, NetInfo)
	
	/*<< ���绷���ı���֪ͨ��Ϣ >>
	*    ui -> nvservice
	*/
	MESSAGE(Ev_NV_BLL_NVDisconnect_Ntf)  
	BODY(nv::TNetUsedInfo, NetInfo)
	
#if !defined(_MESSAGE_HELP_)
    EV_BLL_END(MISC) = EVSEG_BLL_MISC_END
};
#endif

#define Is_BLL_Misc_Msg(m) ((m) >= EV_BLL_BGN(MISC) && (m) <= EV_BLL_END(MISC))

#endif  //_NVBLLMISCMSG_H_
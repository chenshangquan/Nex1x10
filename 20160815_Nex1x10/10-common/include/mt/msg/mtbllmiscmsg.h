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

#ifndef _MTBLLMISCMSG_H_
#define _MTBLLMISCMSG_H_

#include "mtmsgid.h"

#if !defined(_MESSAGE_HELP_)
enum EmBLLMiscMsg
{
    EV_BLL_BGN(MISC) = EVSEG_BLL_MISC_BGN,
#endif

	/*<<ϵͳ��ʾ>>
	* all -> ui
	*/
    MESSAGE(Ev_MT_BLL_SysHint_Ntf)
	BODY(mt::TSysHint, sys_hint)	//��ʾ����

	/*<<����������>>
	* ui -> misc
	*/
	MESSAGE(Ev_MT_BLL_BandwidthTest_Cmd)
	

	/*<<��������֪ͨ>>
	* misc -> ui
	*/
	MESSAGE(Ev_MT_BLL_BandwidthTestResult_Ntf)
	BODY(mt::TMTNetStatus, is_ok)

	/*<< ���绷���ı���֪ͨ��Ϣ >>
	*    ui -> mtservice
	*/
	MESSAGE(Ev_MT_BLL_NetInfo_Ntf)  
	BODY(mt::TNetUsedInfo, NetInfo)

	/*<< ����osd log��ӡ���Ƶ�֪ͨ >>
	*    mtservice -> sdk
	*/
	MESSAGE(Ev_MT_BLL_SetOsdLogCtrl_Ntf)
	BODY(mt::TU32, tdwLogId)

	
#if !defined(_MESSAGE_HELP_)
    EV_BLL_END(MISC) = EVSEG_BLL_MISC_END
};
#endif

#define Is_BLL_Misc_Msg(m) ((m) >= EV_BLL_BGN(MISC) && (m) <= EV_BLL_END(MISC))

#endif  //_MTBLLMISCMSG_H_
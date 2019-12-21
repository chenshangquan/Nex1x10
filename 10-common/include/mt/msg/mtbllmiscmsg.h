/*---------------------------------------------------------------------------*/
/*
 * @file    $Id$
 * @brief   小业务子消息定义
 * @author  瞿戴沣
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

	/*<<系统提示>>
	* all -> ui
	*/
    MESSAGE(Ev_MT_BLL_SysHint_Ntf)
	BODY(mt::TSysHint, sys_hint)	//提示数据

	/*<<带宽检测命令>>
	* ui -> misc
	*/
	MESSAGE(Ev_MT_BLL_BandwidthTest_Cmd)
	

	/*<<带宽检测结果通知>>
	* misc -> ui
	*/
	MESSAGE(Ev_MT_BLL_BandwidthTestResult_Ntf)
	BODY(mt::TMTNetStatus, is_ok)

	/*<< 网络环境改变后的通知消息 >>
	*    ui -> mtservice
	*/
	MESSAGE(Ev_MT_BLL_NetInfo_Ntf)  
	BODY(mt::TNetUsedInfo, NetInfo)

	/*<< 设置osd log打印控制的通知 >>
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
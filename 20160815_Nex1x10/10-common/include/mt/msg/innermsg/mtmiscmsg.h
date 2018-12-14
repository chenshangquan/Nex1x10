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

#ifndef _MTMISCMSG_H_
#define _MTMISCMSG_H_

#include "mtmsgid.h"

#if !defined(_MESSAGE_HELP_)
enum EmMiscMsg
{
    EV_BGN(MISC) = EVSEG_MISC_BGN,
#endif

	/*<<系统提示>>
	* all -> ui
	*/
    MESSAGE(Ev_MT_SysHint_Ntf)
	BODY(mt::TSysHint, sys_hint)	//提示数据
	
	/*<<带宽检测命令>>
	* ui -> misc
	*/
	MESSAGE(Ev_MT_BandwidthTest_Cmd)
	BODY(mt::TU32, server_ip)	//服务器ip
	

	/*<<带宽检测结果通知>>
	* misc -> ui
	*/
	MESSAGE(Ev_MT_BandwidthTestResult_Ntf)
	BODY(mt::TMTNetStatus, is_ok)

#if !defined(_MESSAGE_HELP_)
    EV_END(MISC) = EVSEG_MISC_END
};
#endif

#define Is_Misc_Msg(m) ((m) >= EV_BGN(MISC) && (m) <= EV_END(MISC))

#endif  //_MTMISCMSG_H_
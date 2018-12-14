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

#ifndef _NVMISCMSG_H_
#define _NVMISCMSG_H_

#include "nvmsgid.h"

#if !defined(_MESSAGE_HELP_)
enum EmMiscMsg
{
    EV_BGN(MISC) = EVSEG_MISC_BGN,
#endif

	/*<<系统提示>>
	* all -> ui
	*/
    MESSAGE(Ev_NV_SysHint_Ntf)
	BODY(nv::TSysHint, sys_hint)	//提示数据
	
	/*<<带宽检测命令>>
	* ui -> misc
	*/
	MESSAGE(Ev_NV_BandwidthTest_Cmd)
	BODY(nv::TU32, server_ip)	//服务器ip
	

	/*<<带宽检测结果通知>>
	* misc -> ui
	*/
	MESSAGE(Ev_NV_BandwidthTestResult_Ntf)
	BODY(nv::TNVNetStatus, is_ok)

#if !defined(_MESSAGE_HELP_)
    EV_END(MISC) = EVSEG_MISC_END
};
#endif

#define Is_Misc_Msg(m) ((m) >= EV_BGN(MISC) && (m) <= EV_END(MISC))

#endif  //_NVMISCMSG_H_
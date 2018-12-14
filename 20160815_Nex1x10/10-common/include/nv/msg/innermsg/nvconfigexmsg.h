#ifndef _NV_CONFIG_EXTEND_MSG_H_
#define _NV_CONFIG_EXTEND_MSG_H_

#include "nvmsgid.h"

#if !defined(_MESSAGE_HELP_)
enum EmNvConfigExMsg
{
    EV_BGN(CONFIG_EX) = EVSEG_CONFIG_EX_BGN,
#endif

	/*<< 恢复配置默认值命令 >>
	* 
	*    service -> nvconfig
	*/
	MESSAGE(Ev_NV_RestoreDefaultCfg_Cmd)
	BODY(nv::TNVRestoreDefaultCfgInfo, param)

	/*<< 恢复配置默认值通知 >>
	* 
	*    nvconfig -> service
	*/
	MESSAGE(Ev_NV_RestoreDefaultCfg_Ntf)

 #if !defined(_MESSAGE_HELP_)
    EV_END(CONFIG_EX) = EVSEG_CONFIG_EX_END
};
#endif

#define Is_NvConfigEx_Msg(m) ((m) >= EV_BGN(CONFIG_EX) && (m) <= EV_END(CONFIG_EX))

#endif //_NV_CONFIG_EXTEND_MSG_H_

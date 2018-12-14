#ifndef _NV_BLL_CONFIG_EXTEND_MSG_H_
#define _NV_BLL_CONFIG_EXTEND_MSG_H_

#include "nvmsgid.h"

#if !defined(_MESSAGE_HELP_)
enum EmBLLNvConfigExMsg
{
    EV_BLL_BGN(CONFIG_EX) = EVSEG_BLL_CONFIG_EX_BGN,
#endif

	/*<< »Ö¸´ÅäÖÃÄ¬ÈÏÖµÃüÁî >>
	* 
	*    ui -> misc
	*/
	MESSAGE(Ev_NV_BLL_RestoreDefaultCfg_Cmd)
	BODY(nv::TNVRestoreDefaultCfgInfo, param)
	


	//poll
 #if !defined(_MESSAGE_HELP_)
    EV_BLL_END(CONFIG_EX) = EVSEG_BLL_CONFIG_EX_END
};
#endif

#define Is_BLL_NvConfigEx_Msg(m) ((m) >= EV_BLL_BGN(CONFIG_EX) && (m) <= EV_BLL_END(CONFIG_EX))

#endif //_NV_BLL_CONFIG_EXTEND_MSG_H_

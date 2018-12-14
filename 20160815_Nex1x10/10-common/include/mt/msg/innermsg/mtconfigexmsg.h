#ifndef _MT_CONFIG_EXTEND_MSG_H_
#define _MT_CONFIG_EXTEND_MSG_H_

#include "mtmsgid.h"

#if !defined(_MESSAGE_HELP_)
enum EmMtConfigExMsg
{
    EV_BGN(CONFIG_EX) = EVSEG_CONFIG_EX_BGN,
#endif

	/*<< »Ö¸´ÅäÖÃÄ¬ÈÏÖµÃüÁî >>
	* 
	*    service -> mtconfig
	*/
	MESSAGE(Ev_MT_RestoreDefaultCfg_Cmd)
	BODY(mt::TMTRestoreDefaultCfgInfo, param)

	/*<< »Ö¸´ÅäÖÃÄ¬ÈÏÖµÍ¨Öª >>
	* 
	*    mtconfig -> service
	*/
	MESSAGE(Ev_MT_RestoreDefaultCfg_Ntf)


 #if !defined(_MESSAGE_HELP_)
    EV_END(CONFIG_EX) = EVSEG_CONFIG_EX_END
};
#endif

#define Is_MtConfigEx_Msg(m) ((m) >= EV_BGN(CONFIG_EX) && (m) <= EV_END(CONFIG_EX))

#endif //_MT_CONFIG_EXTEND_MSG_H_

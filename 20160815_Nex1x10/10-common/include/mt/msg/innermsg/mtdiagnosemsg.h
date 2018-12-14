#ifndef _MTDIAGNOSEMSG_H_
#define _MTDIAGNOSEMSG_H_

#include "mtmsgid.h"

#if !defined(_MESSAGE_HELP_)

enum EmMtDiagnoseMsg
{
    EV_BGN(DIAGNOSE) = EVSEG_BLL_DIAGNOSE_BGN,
#endif

	/**********************************************************************************
	* < 本端自环 >
	* ----------------------------------------------------------
	* 参数：TBOOL32					开始/停止
	* ----------------------------------------------------------
	* 发送方向：mtservice -> 
	* ******************************************************************************** */	
	MESSAGE(Ev_MT_DiagnoseLoopBackTest_Cmd)
	BODY(mt::TBOOL32, bStart)




	
 #if !defined(_MESSAGE_HELP_)
     EV_END(DIAGNOSE) = EVSEG_DIAGNOSE_END
};
#endif

#define Is_MtDIAGNOSE_Msg(m) ((m) >= EV_BGN(DIAGNOSE) && (m) <= EV_END(DIAGNOSE))

#endif // _MTDIAGNOSEMSG_H_
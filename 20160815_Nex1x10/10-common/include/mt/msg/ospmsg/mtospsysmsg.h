#ifndef _MTOSPSYSMSG_H_
#define _MTOSPSYSMSG_H_

#include "kdvtype.h"
#include "mtospmsgid.h"

enum EmMtOspMsgSys
{
	Ev_MtOsp_ProtoBufMsg = EVSEG_MTOSPMSG_SYS_BGN,
	EV_MtOsp_InstanceInit,
	EV_MtOsp_InstanceExit,
	Ev_MtOsp_ProtoBufEncMsg, 
};

#endif
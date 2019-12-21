#ifndef _NVOSPSYSMSG_H_
#define _NVOSPSYSMSG_H_

#include "kdvtype.h"
#include "nvospmsgid.h"

enum EmNvOspMsgSys
{
	Ev_NvOsp_ProtoBufMsg = EVSEG_NVOSPMSG_SYS_BGN,
	EV_NvOsp_InstanceInit,
	EV_NvOsp_InstanceExit,
};

#endif
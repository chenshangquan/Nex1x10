#ifndef _NVOSPMSGID_H_
#define _NVOSPMSGID_H_

#include "kdvtype.h"
#include "eventid.h"

//使用OSP的消息，消息id与消息体是分开的，对应osp的CMessage
enum EmNvOspMsgSegs
{
	//OSP内部消息段，各个产品团队如有需要可以使用
	EVSEG_NVOSPMSG_INNER_BGN = EV_NV_BGN,
	EVSEG_NVOSPMSG_INNER_END = (EVSEG_NVOSPMSG_INNER_BGN + 300),

	//系统消息段
	EVSEG_NVOSPMSG_SYS_BGN,
	EVSEG_NVOSPMSG_SYS_END   = (EVSEG_NVOSPMSG_SYS_BGN + 100),

	//定时器消息段
	EVSEG_NVOSPMSG_TIMER_BGN,
	EVSEG_NVOSPMSG_TIMER_END = (EVSEG_NVOSPMSG_TIMER_BGN + 500),
};

#endif
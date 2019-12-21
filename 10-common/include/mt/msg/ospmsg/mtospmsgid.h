#ifndef _MTOSPMSGID_H_
#define _MTOSPMSGID_H_

#include "kdvtype.h"
#include "eventid.h"

//使用OSP的消息，消息id与消息体是分开的，对应osp的CMessage
enum EmMtOspMsgSegs
{
	//OSP内部消息段，各个产品团队如有需要可以使用
	EVSEG_MTOSPMSG_INNER_BGN = EV_MT_BGN,
	EVSEG_MTOSPMSG_INNER_END = (EVSEG_MTOSPMSG_INNER_BGN + 300),

	//系统消息段
	EVSEG_MTOSPMSG_SYS_BGN,
	EVSEG_MTOSPMSG_SYS_END   = (EVSEG_MTOSPMSG_SYS_BGN + 100),

	//定时器消息段
	EVSEG_MTOSPMSG_TIMER_BGN,
	EVSEG_MTOSPMSG_TIMER_END = (EVSEG_MTOSPMSG_TIMER_BGN + 500),
};

#endif
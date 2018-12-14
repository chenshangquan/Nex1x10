#ifndef _MTOSPMSGID_H_
#define _MTOSPMSGID_H_

#include "kdvtype.h"
#include "eventid.h"

//ʹ��OSP����Ϣ����Ϣid����Ϣ���Ƿֿ��ģ���Ӧosp��CMessage
enum EmMtOspMsgSegs
{
	//OSP�ڲ���Ϣ�Σ�������Ʒ�Ŷ�������Ҫ����ʹ��
	EVSEG_MTOSPMSG_INNER_BGN = EV_MT_BGN,
	EVSEG_MTOSPMSG_INNER_END = (EVSEG_MTOSPMSG_INNER_BGN + 300),

	//ϵͳ��Ϣ��
	EVSEG_MTOSPMSG_SYS_BGN,
	EVSEG_MTOSPMSG_SYS_END   = (EVSEG_MTOSPMSG_SYS_BGN + 100),

	//��ʱ����Ϣ��
	EVSEG_MTOSPMSG_TIMER_BGN,
	EVSEG_MTOSPMSG_TIMER_END = (EVSEG_MTOSPMSG_TIMER_BGN + 500),
};

#endif
#ifndef _NVOSPMSGID_H_
#define _NVOSPMSGID_H_

#include "kdvtype.h"
#include "eventid.h"

//ʹ��OSP����Ϣ����Ϣid����Ϣ���Ƿֿ��ģ���Ӧosp��CMessage
enum EmNvOspMsgSegs
{
	//OSP�ڲ���Ϣ�Σ�������Ʒ�Ŷ�������Ҫ����ʹ��
	EVSEG_NVOSPMSG_INNER_BGN = EV_NV_BGN,
	EVSEG_NVOSPMSG_INNER_END = (EVSEG_NVOSPMSG_INNER_BGN + 300),

	//ϵͳ��Ϣ��
	EVSEG_NVOSPMSG_SYS_BGN,
	EVSEG_NVOSPMSG_SYS_END   = (EVSEG_NVOSPMSG_SYS_BGN + 100),

	//��ʱ����Ϣ��
	EVSEG_NVOSPMSG_TIMER_BGN,
	EVSEG_NVOSPMSG_TIMER_END = (EVSEG_NVOSPMSG_TIMER_BGN + 500),
};

#endif
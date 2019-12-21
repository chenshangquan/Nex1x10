#ifndef _NVDISPATCHMSG_H_
#define _NVDISPATCHMSG_H_

#include "nvmsgid.h"

#if !defined(_MESSAGE_HELP_)
enum EmNvDispatchMsg
{
    EV_BGN(DISPATCH) = EVSEG_DISPATCH_BGN,
#endif//_MESSAGE_HELP_

	/*<<������Ϣ>>
	*Subs_msgid ��������Ϣid
	*���䷽��All->dispatch
	*/
	MESSAGE(Ev_NV_Subscribe_Cmd)
	BODY(nv::TSubsMsgID, subs_msgid)

	/*<<ע��������Ϣ>>
	*Subs_msgid ��Ҫע���Ķ�����Ϣid
	*���䷽��All->dispatch
	*/
	MESSAGE(Ev_NV_UnSubscribe_Cmd)
	BODY(nv::TSubsMsgID, unsubs_msgid)

#if !defined(_MESSAGE_HELP_)
    EV_END(DISPATCH) = EVSEG_DISPATCH_END
};
#endif//_MESSAGE_HELP_

#define Is_Dispatch_Msg(m) ((m) >= EV_BGN(DISPATCH) && (m) <= EV_END(DISPATCH))

#endif // _NVDISPATCHMSG_H_
#ifndef _MTDISPATCHMSG_H_
#define _MTDISPATCHMSG_H_

#include "mtmsgid.h"

#if !defined(_MESSAGE_HELP_)
enum EmMtDispatchMsg
{
    EV_BGN(DISPATCH) = EVSEG_DISPATCH_BGN,
#endif//_MESSAGE_HELP_

	/*<<������Ϣ>>
	*Subs_msgid ��������Ϣid
	*���䷽��All->dispatch
	*/
	MESSAGE(Ev_MT_Subscribe_Cmd)
	BODY(mt::TSubsMsgID, subs_msgid)

	/*<<ע��������Ϣ>>
	*Subs_msgid ��Ҫע���Ķ�����Ϣid
	*���䷽��All->dispatch
	*/
	MESSAGE(Ev_MT_UnSubscribe_Cmd)
	BODY(mt::TSubsMsgID, unsubs_msgid)

#if !defined(_MESSAGE_HELP_)
    EV_END(DISPATCH) = EVSEG_DISPATCH_END
};
#endif//_MESSAGE_HELP_

#define Is_Dispatch_Msg(m) ((m) >= EV_BGN(DISPATCH) && (m) <= EV_END(DISPATCH))

#endif // _MTDISPATCHMSG_H_
#ifndef _MTDISPATCHMSG_H_
#define _MTDISPATCHMSG_H_

#include "mtmsgid.h"

#if !defined(_MESSAGE_HELP_)
enum EmMtDispatchMsg
{
    EV_BGN(DISPATCH) = EVSEG_DISPATCH_BGN,
#endif//_MESSAGE_HELP_

	/*<<订阅消息>>
	*Subs_msgid ：订阅消息id
	*传输方向：All->dispatch
	*/
	MESSAGE(Ev_MT_Subscribe_Cmd)
	BODY(mt::TSubsMsgID, subs_msgid)

	/*<<注销订阅消息>>
	*Subs_msgid ：要注销的订阅消息id
	*传输方向：All->dispatch
	*/
	MESSAGE(Ev_MT_UnSubscribe_Cmd)
	BODY(mt::TSubsMsgID, unsubs_msgid)

#if !defined(_MESSAGE_HELP_)
    EV_END(DISPATCH) = EVSEG_DISPATCH_END
};
#endif//_MESSAGE_HELP_

#define Is_Dispatch_Msg(m) ((m) >= EV_BGN(DISPATCH) && (m) <= EV_END(DISPATCH))

#endif // _MTDISPATCHMSG_H_
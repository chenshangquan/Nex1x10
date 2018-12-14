#ifndef _MTMPMOBILEMSG_H_
#define _MTMPMOBILEMSG_H_

#include "mtmsgid.h"

#if !defined(_MESSAGE_HELP_)
enum EmMPMobileMsg
{
    EV_BGN(MPMOBILE) = EVSEG_MPMOBILE_BGN,
#endif
	
	/*<<视频编码器图像加黑框命令,仅对第一个视频编码器生效>>
	*enable ：TRUE加黑框，FALSE不加黑框
	*消息流向 ：service==>dispatch==>mtmp
	*/
	MESSAGE(Ev_MT_CodecVidEncAddBlackBorder_Cmd)
	BODY(mt::TBOOL32, enable)


#if !defined(_MESSAGE_HELP_)
    EV_END(MPMOBILE) = EVSEG_MPMOBILE_END
};
#endif

#define Is_MPMobile_Msg(m) ((m) >= EV_BGN(MPMOBILE) && (m) <= EV_END(MPMOBILE))

#endif // _MTMPMOBILEMSG_H_
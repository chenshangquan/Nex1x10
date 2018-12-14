#ifndef _MTMPMOBILEMSG_H_
#define _MTMPMOBILEMSG_H_

#include "mtmsgid.h"

#if !defined(_MESSAGE_HELP_)
enum EmMPMobileMsg
{
    EV_BGN(MPMOBILE) = EVSEG_MPMOBILE_BGN,
#endif
	
	/*<<��Ƶ������ͼ��Ӻڿ�����,���Ե�һ����Ƶ��������Ч>>
	*enable ��TRUE�Ӻڿ�FALSE���Ӻڿ�
	*��Ϣ���� ��service==>dispatch==>mtmp
	*/
	MESSAGE(Ev_MT_CodecVidEncAddBlackBorder_Cmd)
	BODY(mt::TBOOL32, enable)


#if !defined(_MESSAGE_HELP_)
    EV_END(MPMOBILE) = EVSEG_MPMOBILE_END
};
#endif

#define Is_MPMobile_Msg(m) ((m) >= EV_BGN(MPMOBILE) && (m) <= EV_END(MPMOBILE))

#endif // _MTMPMOBILEMSG_H_
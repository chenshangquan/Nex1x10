#ifndef _MTBLLMPMOBILEMSG_H_
#define _MTBLLMPMOBILEMSG_H_

#include "mtmsgid.h"

#if !defined(_MESSAGE_HELP_)
enum EmBLLMPMobileMsg
{
    EV_BLL_BGN(MPMOBILE) = EVSEG_BLL_MPMOBILE_BGN,
#endif
	
	/*<<��Ƶ������ͼ��Ӻڿ�����,���Ե�һ����Ƶ��������Ч>>
	*enable ��TRUE�Ӻڿ�FALSE���Ӻڿ�
	*��Ϣ���� ��service==>dispatch==>mtmp
	*/
	MESSAGE(Ev_MT_BLL_CodecVidEncAddBlackBorder_Cmd)
	BODY(mt::TBOOL32, enable)


#if !defined(_MESSAGE_HELP_)
    EV_BLL_END(MPMOBILE) = EVSEG_BLL_MPMOBILE_END
};
#endif

#define Is_BLL_MPMobile_Msg(m) ((m) >= EV_BLL_BGN(MPMOBILE) && (m) <= EV_BLL_END(MPMOBILE))

#endif // _MTBLLMPMOBILEMSG_H_
#ifndef _MTTEXTIMAGEMSG_H_
#define _MTTEXTIMAGEMSG_H_

#include "mtmsgid.h"

#if !defined(_MESSAGE_HELP_)
enum EmMtNetMsg
{
    EV_BGN(TEXTIMAGE) = EVSEG_TEXTIMAGE_BGN,
#endif//_MESSAGE_HELP_
	
	/*<<�����ն�̨������>>
	*BODY ��TMTLabelInfo: ̨���ʽ����
	*���䷽��mtservice->dispatch->net
	* see Ev_MT_TextImage_CreateLabelInfo_Rsp
	*/
	MESSAGE(Ev_MT_TextImage_CreateLabelInfo_Req)
	BODY(mt::TMTLabelInfo, TMTLabelInfo)
	
	/*<<�����ն�̨����Ӧ>>
	*BODY ��result  0�ɹ�  ����������
	        TMTLabelInfo: ����̨������ʱ��̨������
	*���䷽��net->dispatch->mtservice
	* see Ev_MT_TextImage_CreateLabelInfo_Req
	* desc ̨��bmp�ļ�����·����
	*/
	MESSAGE(Ev_MT_TextImage_CreateLabelInfo_Rsp)
	BODY(mt::TU32, result)
	BODY(mt::TMTLabelInfo, TMTLabelInfo)
 
	
	/*<<�����ն˺������>>
	*BODY ��TMTBannerInfo: �����ʽ����
	*���䷽��mtservice->dispatch->net
	* see Ev_MT_TextImage_CreateBannerInfo_Rsp
	*/
	MESSAGE(Ev_MT_TextImage_CreateBannerInfo_Req)
	BODY(mt::TMTBannerInfo, TMTBannerInfo)
	
	/*<<�����ն˺����Ӧ>>
	*BODY ��result  0�ɹ�  ����������
	        TMTLabelInfo: ���ɺ������ʱ�������
	*���䷽��net->dispatch->mtservice
	* see Ev_MT_TextImage_CreateBannerInfo_Req
	* desc ���bmp�ļ�����·����
	*/
	MESSAGE(Ev_MT_TextImage_CreateBannerInfo_Rsp)
	BODY(mt::TU32, result)
	BODY(mt::TMTBannerInfo, TMTBannerInfo)
    BODY(mt::TMultiU32, actual_linenum)


#if !defined(_MESSAGE_HELP_)
    EV_END(TEXTIMAGE) = EVSEG_TEXTIMAGE_END
};
#endif//_MESSAGE_HELP_

#define Is_TextImage_Msg(m) ((m) >= EV_BGN(TEXTIMAGE) && (m) <= EV_END(TEXTIMAGE))

#endif//_MTTEXTIMAGEMSG_H_
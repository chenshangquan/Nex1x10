#ifndef _MTTEXTIMAGEMSG_H_
#define _MTTEXTIMAGEMSG_H_

#include "mtmsgid.h"

#if !defined(_MESSAGE_HELP_)
enum EmMtNetMsg
{
    EV_BGN(TEXTIMAGE) = EVSEG_TEXTIMAGE_BGN,
#endif//_MESSAGE_HELP_
	
	/*<<生成终端台标请求>>
	*BODY ：TMTLabelInfo: 台标格式内容
	*传输方向：mtservice->dispatch->net
	* see Ev_MT_TextImage_CreateLabelInfo_Rsp
	*/
	MESSAGE(Ev_MT_TextImage_CreateLabelInfo_Req)
	BODY(mt::TMTLabelInfo, TMTLabelInfo)
	
	/*<<生成终端台标响应>>
	*BODY ：result  0成功  其他错误码
	        TMTLabelInfo: 生成台标请求时的台标内容
	*传输方向：net->dispatch->mtservice
	* see Ev_MT_TextImage_CreateLabelInfo_Req
	* desc 台标bmp文件生成路径：
	*/
	MESSAGE(Ev_MT_TextImage_CreateLabelInfo_Rsp)
	BODY(mt::TU32, result)
	BODY(mt::TMTLabelInfo, TMTLabelInfo)
 
	
	/*<<生成终端横幅请求>>
	*BODY ：TMTBannerInfo: 横幅格式内容
	*传输方向：mtservice->dispatch->net
	* see Ev_MT_TextImage_CreateBannerInfo_Rsp
	*/
	MESSAGE(Ev_MT_TextImage_CreateBannerInfo_Req)
	BODY(mt::TMTBannerInfo, TMTBannerInfo)
	
	/*<<生成终端横幅响应>>
	*BODY ：result  0成功  其他错误码
	        TMTLabelInfo: 生成横幅请求时横幅内容
	*传输方向：net->dispatch->mtservice
	* see Ev_MT_TextImage_CreateBannerInfo_Req
	* desc 横幅bmp文件生成路径：
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
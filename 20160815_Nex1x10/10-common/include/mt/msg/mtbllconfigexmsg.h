#ifndef _MT_BLL_CONFIG_EXTEND_MSG_H_
#define _MT_BLL_CONFIG_EXTEND_MSG_H_

#include "mtmsgid.h"

#if !defined(_MESSAGE_HELP_)
enum EmBLLMtConfigExMsg
{
    EV_BLL_BGN(CONFIG_EX) = EVSEG_BLL_CONFIG_EX_BGN,
#endif

	/*<< �ָ�����Ĭ��ֵ���� >>
	* 
	*    ui -> misc
	*/
	MESSAGE(Ev_MT_BLL_RestoreDefaultCfg_Cmd)
	BODY(mt::TMTRestoreDefaultCfgInfo, param)
	
	/*<< ���õ�����Ƶ������������������ >>
	* 
	*    ui -> misc
	*/
	MESSAGE(Ev_MT_BLL_SetVideoEncoderCfg_Cmd)
	BODY(mt::TMTVideoEncoderParamCfg, param)


	/*<< ������Ƶ��������������֪ͨ >>
	* 
	*    ui -> misc
	*/
	MESSAGE(Ev_MT_BLL_VideoEncoderParamCfg_Ntf)
	BODY(mt::TMTVideoEncoderParamCfg, param)

	/*<< ���õ�����Ƶ������������������ >>
	* 
	*    ui -> misc
	*/
	MESSAGE(Ev_MT_BLL_SetVideoDecoderCfg_Cmd)
	BODY(mt::TMTVideoDecoderParamCfg, param)


	/*<< ������Ƶ��������������֪ͨ >>
	* 
	*    ui -> misc
	*/
	MESSAGE(Ev_MT_BLL_VideoDecoderParamCfg_Ntf)
	BODY(mt::TMTVideoDecoderParamCfg, param)

	/*<< ��ʾ��ͬ������ >>
	* 
	*    ui -> dispatch
	*/
	MESSAGE(Ev_MT_BLL_SyncTooltipBox_Cmd)
	BODY(mt::TString, userid)

	/*<< ��ʾ��ͬ��֪ͨ >>
	* 
	*    dispatch -> ui
	*/
	MESSAGE(Ev_MT_BLL_SyncTooltipBox_Ntf)
	BODY(mt::TString, userid)

	//poll
 #if !defined(_MESSAGE_HELP_)
    EV_BLL_END(CONFIG_EX) = EVSEG_BLL_CONFIG_EX_END
};
#endif

#define Is_BLL_MtConfigEx_Msg(m) ((m) >= EV_BLL_BGN(CONFIG_EX) && (m) <= EV_BLL_END(CONFIG_EX))

#endif //_MT_BLL_CONFIG_EXTEND_MSG_H_

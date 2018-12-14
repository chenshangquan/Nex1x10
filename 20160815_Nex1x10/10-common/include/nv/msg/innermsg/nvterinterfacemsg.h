#ifndef _NVTERINTERFACEMSG_H_
#define _NVTERINTERFACEMSG_H_

#include "nvmsgid.h"

#if !defined(_MESSAGE_HELP_)
enum EmNvTerinterfaceMsg
{
    EV_BGN(TERINTERFACE) = EVSEG_TERINTERFACE_BGN,
#endif//_MESSAGE_HELP_
	
	/*<<�����ն�״̬�ϱ�>>
	* is_login ���Ƿ�����ն˳ɹ�
	*��Ϣ���� nvterinterface ==>dispatch==>nvservice
	*/
	MESSAGE(Ev_NV_MTCLogin_Ntf)         
	BODY(NV::TBOOL32, is_login) 
	
	/*<<��������>>
	*��Ϣ���� nvservice==>dispatch==>nvterinterface
	*/
    MESSAGE(Ev_NV_CodecDspSleep_Req)
	
	/*<<��������>>
	*��Ϣ���� nvservice==>dispatch==>nvterinterface
	*/
    MESSAGE(Ev_NV_CodecDspSleep_Cmd)

	/*<<��������>>
	*��Ϣ���� nvservice==>dispatch==>nvterinterface
	*/
    MESSAGE(Ev_NV_CodecDspWakeup_Cmd)

	/*<<����״̬�ϱ�>>
	*��Ϣ���� nvterinterface==>dispatch==>nvservice
	*is_sleep : TRUE表示进入睡眠状态，FALSE表示进入唤醒状�?
	*/
    MESSAGE(Ev_NV_CodecSleepState_Ntf)
	BODY(nv::TBOOL32, is_sleep)
	
	/*<<������Ӧ>>
	*��Ϣ���� nvterinterface==>dispatch==>nvservice
	* is_sucess: �Ƿ��������
	* fail_reason: ����ʧ��ԭ��
	*/
    MESSAGE(Ev_NV_CodecDspSleep_Rsp)
	BODY(nv::TBOOL32, is_sucess)
	BODY(nv::TS32, fail_reason) //ö��ֵͳһʹ��nv::TS32�����䣬�ô�ʵ��Ϊnv::EmNvSleepFailReason
	
	/*<<����ʧ��ԭ���ϱ�>>
	*��Ϣ���� nvterinterface==>dispatch==>nvservice
	*fail_reason : ʧ��ԭ��
	*/
    MESSAGE(Ev_NV_CodecSleepFailReason_Ntf)
	BODY(nv::TS32, fail_reason) //ö��ֵͳһʹ��nv::TS32�����䣬�ô�ʵ��Ϊnv::EmNvSleepFailReason
	
	/*<<��ui���ʹ�������ʱ֪ͨ>>
	* nvterinterface==>dispatch==>nvservice
	*count_down : ����ʱʱ��
	*/
	MESSAGE(Ev_NV_SleepCountDown_Ntf)
	BODY(nv::TU16, count_down)	//����ʱʱ��
	
	/*<<��ǰ�ĺ���״̬�ϱ�>>
	* callsate ���ϱ��ĺ��в���
	*��Ϣ���� nvterinterface ==>dispatch==>nvservice
	*/
	MESSAGE(Ev_NV_CallLinkState_Ntf)         //post to UI  ��ǰ����״̬
	BODY(nv::TS32, callsate)	//ö��ֵͳһʹ��nv::TS32�����䣬�ô�ʵ��Ϊnv::EmNvCallState
	BODY(nv::TString, peeralias)
	
	/*<<��ǰ��˫��״̬�ϱ�>>
	* is_senddual ���Ƿ���˫��
	*��Ϣ���� nvterinterface ==>dispatch==>nvservice
	*/
	MESSAGE(Ev_NV_AssSndSream_Status_Ntf)         
	BODY(NV::TBOOL32, is_senddual)
	BODY(NV::TS32, vid_lab) //ö��ֵͳһʹ��nv::TS32�����䣬�ô�ʵ��Ϊnv::EmNvVidLabel		
	
	/*<<��ǰ��˫��״̬�ϱ�>>
	* is_rcvdual ���Ƿ����˫��
	*��Ϣ���� nvterinterface ==>dispatch==>nvservice
	*/
	MESSAGE(Ev_NV_AssRcvSream_Status_Ntf)         
	BODY(NV::TBOOL32, is_rcvdual) 
	
	/*<<����ǰ��������״̬>>
	* ��Ϣ���� ��nvservice==>dispatch==>nvterinterface
	*/
	MESSAGE( Ev_NV_AssSndSream_Status_Req)
	

	/*<<����ǰ��������״̬>>
	* ��Ϣ���� ��nvservice==>dispatch==>nvterinterface
	*/
	MESSAGE( Ev_NV_AssRcvSream_Status_Req)             
	
	/*<<��ǰ�ĺ���״̬����>>
	*��Ϣ���� ��nvservice==>dispatch==>nvterinterface
	*/
	MESSAGE( Ev_NV_CallLinkState_Req)
	
	/*<<����ͬ������>>
	* reason ͬ��ԭ��
	* ��Ϣ���� nvservice==>dispatch==>nvterinterface
	*/
	MESSAGE( Ev_NV_UISynchronize_Cmd)           //����ͬ������
	BODY(nv::TS32,       reason)            //ͬ��ԭ��  ö��ֵͳһʹ��nv::TS32�����䣬�ô�ʵ��Ϊnv::EmNvUISynchronizeReason

	/*<<���ڽ���ͬ��>> 
	* reason ͬ��ԭ��
	* ��Ϣ���� nvterinterface==>dispatch==>nvservice
	*/
	MESSAGE( Ev_NV_UISynchronize_Ntf)        //���ڽ���ͬ��
	BODY(nv::TS32,       reason)            //ͬ��ԭ��  ö��ֵͳһʹ��nv::TS32�����䣬�ô�ʵ��Ϊnv::EmNvUISynchronizeReason
	
	/*<<��ǰ�ĵ����ն�����״̬����>>
	*��Ϣ���� ��nvservice==>dispatch==>nvterinterface
	*/
	MESSAGE( Ev_NV_CodecGetLocalMicMute_Req)
	
	/*<<��ǰ����״̬�ϱ�>>
	* is_mute ���Ƿ�����
	*��Ϣ���� nvterinterface ==>dispatch==>nvservice
	*/
	MESSAGE(Ev_NV_CodecMute_Ntf)         
	BODY(NV::TBOOL32, is_mute) 
	
	/*<<���õ�ǰ����ʱ����Ϣ>>
	*BODY ��  tmttime ʱ����Ϣ  
	*���䷽��nvservice==>dispatch==>nvterinterface
	*/
	MESSAGE(Ev_NV_SetMtSysDataTime_Req)
	BODY(nv::TNVTime, tmttime )
	
	
	/*<<���õ�ǰ����ʱ����Ϣ��Ӧ>>
	*BODY ��   result ���ý�� 0�ɹ� ����������
	           tmttime ʱ����Ϣ 
	*���䷽��nvterinterface ==>dispatch==>nvservice
	*/
	MESSAGE(Ev_NV_SetMtSysDataTimeResult_Rsp)
	BODY(nv::TU32, result)
	BODY(nv::TNVTime, tmttime )


    /*<<���õ�ǰ����ʱ��֪ͨ>>
	*BODY ��   tmttime ʱ����Ϣ 
	*���䷽��nvterinterface ==>dispatch==>nvservice
	* see
	*/
	MESSAGE(Ev_NV_SetMtSysDataTime_Ntf)
	BODY(nv::TNVTime, tmttime )
	
	/*<<��ǰ��˫��״̬�ϱ�>>
	* is_senddual ���Ƿ���˫��
	*��Ϣ���� nvterinterface ==>dispatch==>nvservice
	*/
	MESSAGE(Ev_NV_AssSndSream_Status_Rsp)         
	BODY(NV::TBOOL32, is_senddual)
	BODY(NV::TS32, vid_lab) //ö��ֵͳһʹ��nv::TS32�����䣬�ô�ʵ��Ϊnv::EmNvVidLabel	
	
	/*<<��ǰ��˫��״̬�ϱ�>>
	* is_rcvdual ���Ƿ����˫��
	*��Ϣ���� nvterinterface ==>dispatch==>nvservice
	*/
	MESSAGE(Ev_NV_AssRcvSream_Status_Rsp)         
	BODY(NV::TBOOL32, is_rcvdual) 
	
	/*<<��ǰ��˫��Դ״̬�ϱ�>>
	* is_havesrc ���Ƿ���Դ
	*��Ϣ���� nvterinterface ==>dispatch==>nvservice
	*/
	MESSAGE(Ev_NV_AssVidSrc_Status_Ntf)         
	BODY(NV::TBOOL32, is_havesrc)
	
	/*<<video˫�����������>>
	* bOpen �������߹�
	* ��Ϣ���� ��nvservice==>dispatch==>nvterinterface
	*/
	MESSAGE( Ev_NV_VideoAssStream_Cmd )
	BODY(nv:TBOOL32,  bOpen)                       //true : open��  false: close
	
	/*<<ϵͳ�ػ�����>>
	*��Ϣ���� nvterinterface ==>dispatch==>nvmp
	*/
	MESSAGE(Ev_NV_PowerTurnOff_Cmd)

	/*<<ϵͳ�ػ����֪ͨ>>
	* reason �����֪ͨ
	*��Ϣ���� nvmp ==>dispatch==>nvterinterface
	*/
	MESSAGE(Ev_NV_PowerTurnOff_Ntf)
	BODY(nv:TS32,  reason)       //ö��ֵͳһʹ��nv::TS32�����䣬�ô�ʵ��Ϊnv::EmNvPowerTurnOffReason

	MESSAGE(Ev_NV_SetPipMode_Req)
	BODY(nv:TS32,  pipmode)

	MESSAGE(Ev_NV_SetMartix_Req)	

	MESSAGE(Ev_NV_SetDualPort_Req)
	BODY(nv:TS32,  DualPort)	

	MESSAGE(Ev_NV_GetMartix_Req)

	MESSAGE(Ev_NV_GetSrcInfo_Req)

	/*<<��ǰ��Ӧ��ʽ�ϱ�>>
	* bManuMode ���ϱ���Ӧ��ʽ
	*��Ϣ���� nvterinterface ==>dispatch==>nvservice
	*/
	MESSAGE(Ev_NV_AnswerCallMode_Ntf)//post to UI  
	BODY(nv::TBOOL32, bManuMode)	
	
	/*<<��ǰ��Ӧ��ʽ��ѯ>>
	*��Ϣ���� ��nvservice==>dispatch==>nvterinterface
	*/
	MESSAGE( Ev_NV_GetAnswerMode_Reg)

	MESSAGE( Ev_NV_AnswerCall_Req)//post to UI
	BODY(nv::TBOOL32, bAnswerCall)

	/*<<��ȡ��ǰ����ʱ����Ϣ>>
	*���䷽��nvservice==>dispatch==>nvterinterface
	*/
	MESSAGE(Ev_NV_GetMtSysDataTime_Req)

	/*<<��ȡ��ǰ����ʱ����Ϣ��Ӧ>>
	*BODY ��   result ���ý�� 0�ɹ� ����������
	           tmttime ʱ����Ϣ 
	*���䷽��nvterinterface ==>dispatch==>nvservice
	*/
	MESSAGE(Ev_NV_GetMtSysDataTime_Rsp)
	BODY(nv::TU32, result)
	BODY(nv::TNVTime, tmttime )
	
	/*<<��ȡ�ն˵�ǰʱ��������Ϣ>>
	*���䷽��nvservice==>dispatch==>nvterinterface
	*/
	MESSAGE(Ev_NV_GetMtSysTimeCfg_Req)
	
	/*<<��ȡ�ն˵�ǰʱ��������Ϣ��Ӧ>>
	*BODY �� tmttime ʱ����Ϣ
	*���䷽��nvterinterface ==>dispatch==>nvservice
	*/
	MESSAGE(Ev_NV_GetMtSysTimeCfg_Rsp)
	BODY(nv::TNVCfgMtSystemTime, tmttime )
	
	/*<<�ն˵�ǰʱ��������Ϣ֪ͨ>>
	*BODY �� tmttime ʱ����Ϣ
	*���䷽��nvterinterface ==>dispatch==>nvservice
	*/
	MESSAGE(Ev_NV_SetMtSysTimeCfg_Ntf)
	BODY(nv::TNVCfgMtSystemTime, tmttime )

	/*<<����ֱ��ǿ�����ÿ�����Ƶ>>
	*BODY �� tmttime ʱ����Ϣ
	*���䷽��nvterinterface ==>dispatch==>nvservice
	*/
	MESSAGE(Ev_NV_SetOneMartix_Req)
	/*<<��ȡ�ն��ͺŵ���Ϣ>>
	*BODY �� tmttime ʱ����Ϣ
	*���䷽��nvterinterface ==>dispatch==>nvservice
	*/
	MESSAGE(Ev_NV_GetMtModel_Req)
	/*<<�ն˿ص��ӻ�����>>
	*BODY �� tmttime ʱ����Ϣ
	*���䷽��nvterinterface ==>dispatch==>nvservice
	*/
	MESSAGE(Ev_NV_SetTvSleep_Req)
	/*<<�ն˿ص��ӻ�����>>
	*BODY �� tmttime ʱ����Ϣ
	*���䷽��nvterinterface ==>dispatch==>nvservice
	*/
	MESSAGE(Ev_NV_SetTvWake_Req)


	/*<<ϵͳ��Ϣ��ʾ>>
	*BODY �� tSysHint ��Ϣ��ʾ
	*���䷽��nvterinterface ==>dispatch==>nvservice
	*/
	MESSAGE(Ev_NV_MtSysHint_Ntf)
	BODY(nv::TS32, tSysHint ) //ö��ֵͳһʹ��nv::TS32�����䣬�ô�ʵ��Ϊnv::EmNvHintCode
	
	/*<<��ǰ�ĺ���״̬�ϱ�>>
	* callsate ���ϱ��ĺ��в���
	*��Ϣ���� nvterinterface ==>dispatch==>nvservice
	*/
	MESSAGE(Ev_NV_CallLinkState_Rsp)         //post to UI  ��ǰ����״̬
	BODY(nv::TS32, callsate)	//ö��ֵͳһʹ��nv::TS32�����䣬�ô�ʵ��Ϊnv::EmNvCallState
	BODY(nv::TString, peeralias)
	
	/*<<���ô���ʣ��ʱ���������OSD������IMIX�Ĵ���ͬ����>>
	*BODY �� time ����ʣ��ʱ��(��), ע��:  wSleepRemainTime = 0����ʾȡ������
	*nvservice ==>dispatch==>nvterinterface
	*/
	MESSAGE(Ev_NV_SetSleepReaminTime_Cmd)
	BODY(nv::TU16, time ) 
	
	/*<<�ն˳���ȫ�������ɹ�֪ͨ>>
	*��Ϣ���� nvterinterface ==>dispatch==>nvservice
	*/
	MESSAGE(Ev_NV_HDMtStartSucess_Ntf)      
	
	/*<<����IMIXͨ���ýӿڸ��ն˷�����Ϣ(����512�ֽ�)���ն˽��ն���Ϣ����ʾ��OSD�ϣ�>>
	*BODY �� LocSms ���ض���Ϣ
	*nvservice ==>dispatch==>nvterinterface
	*/
	MESSAGE(Ev_NV_SendLocalSms_Cmd)
	BODY(nv::TString, LocSms ) 
	
	/*<<��ѯ�ն�����>>
	*��Ϣ���� ��nvservice==>dispatch==>nvterinterface
	*/
	MESSAGE( Ev_NV_GetTerminalName_Req)
	
	/*<<��ѯ�ն�������Ӧ>>
	*BODY ��   name �ն�����
	*���䷽��nvterinterface ==>dispatch==>nvservice
	*/
	MESSAGE(Ev_NV_GetTerminalName_Rsp)
	BODY(nv::TNVTerminalName, name)
	
	/*<<�ն�����֪ͨ>>
	*BODY ��   name �ն�����
	*���䷽��nvterinterface ==>dispatch==>nvservice
	*/
	MESSAGE(Ev_NV_SetTerminalName_Ntf)
	BODY(nv::TNVTerminalName, name)
	
	/*<<��ѯ�ն˳����Ƿ�ȫ�������ɹ�>>
	*��Ϣ���� nvservice==>dispatch==>nvterinterface
	*/
    MESSAGE(Ev_NV_InquireHDMtStartSucess_Req)
	
	/*<<��ѯ�ն˳����Ƿ�ȫ�������ɹ���Ӧ>>
	*��Ϣ���� nvterinterface ==>dispatch==>nvservice
	*/
    MESSAGE(Ev_NV_InquireHDMtStartSucess_Rsp)
	BODY(nv:TBOOL32,  bsuc)

	MESSAGE(Ev_NV_PowerNotSleep_Ntf)

	MESSAGE(Ev_NV_InnerNotSleep_Ntf)
	
	/*<<����״̬֪ͨ>>
	*��Ϣ���� nvterinterface ==>dispatch==>nvservice
	*/
    MESSAGE(Ev_NV_CalledNty_Ntf)
	BODY(nv:TBOOL32,  bcalled)

	MESSAGE(Ev_NV_SetMartix_Test)	

	/*<<��������>>
	*��Ϣ���� nvservice==>dispatch==>nvterinterface
	*/
	MESSAGE(Ev_NV_CodecDspWakeup_Req)

	/*<<����NAT��ַ>>
	*��Ϣ���� nvservice==>dispatch==>nvterinterface
	*bEnable:�Ƿ�����NAT
	*dwIP:NAT IP��ַ
	*/
	MESSAGE(Ev_Nv_SetNatCfg_Cmd)
	BODY(nv::TBOOL32, bEnable)
	BODY(nv::TU32, dwIP)

	/*<<����NAT��ַ��Ӧ>>
	*��Ϣ���� nvterinterface==>dispatch==>nvservice
	*bResult:���ý��
	*bEnable:�Ƿ�����NAT
	*dwIP:NAT IP��ַ
	*/
	MESSAGE(Ev_Nv_SetNatCfg_Rsp)
	BODY(nv::TBOOL32, bResult)
	BODY(nv::TBOOL32, bEnable)
	BODY(nv::TU32, dwIP)

	/*<<�����ն˻���ϳ��Ƿ���ʾ����˫��Դ>>
	*��Ϣ���� nvservice==>dispatch==>nvterinterface
	*bIsShow:TRUE����ʾ FAULSE:����
	*/
	MESSAGE(Ev_Nv_SetShowAssInVmp_Cmd)
	BODY(nv::TBOOL32, bIsShow)

	/*<<�Ҷ��ն˻���>>
	*��Ϣ���� nvservice==>dispatch==>nvterinterface
	*DisReason:�Ҷ�ԭ��;EmMtCallDisReason_Api
	*/
	MESSAGE(Ev_NV_HangupConf_Cmd)
	BODY(nv::TS32, DisReason)

	/*<<�����ն��Ƿ��Զ�����>>
	*��Ϣ���� nvservice==>dispatch==>nvterinterface
	*tcfg:�Զ�������Ϣ
	*/
	MESSAGE(Ev_NV_SetAutoSleep_Cmd)
	BODY(nv::TNVMtAutoSleepCfg, tcfg)

	/*<<��ѯ�ն��Զ���������>>
	*��Ϣ���� nvservice==>dispatch==>nvterinterface
	*
	*/
	MESSAGE(Ev_NV_GetAutoSleep_Req)

	/*<<�����ն��Ƿ��Զ�����֪ͨ>>
	*��Ϣ���� nvterinterface==>dispatch==>nvservice
	*tcfg:�Զ�������Ϣ
	*/
	MESSAGE(Ev_NV_SetAutoSleep_Nty)
	BODY(nv::TNVMtAutoSleepCfg, tcfg)

	/*<<��ѯ�ն��Ƿ��Զ�������Ӧ>>
	*��Ϣ���� nvterinterface==>dispatch==>nvservice
	*tcfg:�Զ�������Ϣ
	*/
	MESSAGE(Ev_NV_GetAutoSleep_Rsp)
	BODY(nv::TNVMtAutoSleepCfg, tcfg)

	/*<<�����ն˻ָ���������>>
	*��Ϣ���� nvservice==>dispatch==>nvterinterface
	*tDelcfg:�Ƿ�ɾ�������ļ�
	*/
	MESSAGE(Ev_NV_ResetTerCfg_Cmd)
	BODY(nv::TBOOL32, tDelcfg)

	/*<<�����ն�ʱ������>>
	*��Ϣ���� nvservice==>dispatch==>nvterinterface
	*tcfg:ʱ��������Ϣ
	*/
	MESSAGE(Ev_NV_SetTerTimeCfg_Cmd)
	BODY(nv::TNVCfgMtSystemTime, tcfg)

	/*<<�����ն��Ƿ��¼��ƽ̨>>
	*��Ϣ���� nvservice==>dispatch==>nvterinterface
	*tLogin:TRUE:�����¼ƽ̨
	*/
	MESSAGE(Ev_NV_SetTerLoginPlatformSrvCfg_Cmd)
	BODY(nv::TBOOL32, tLogin)

	/*<<�ն�ң��������֪ͨ>>
	*��Ϣ���� nvterinterface==>dispatch==>nvservice
	*
	*/
	MESSAGE(Ev_NV_DeviceKeyCode_Ntf)

	/*<<�����ն˻ص�OSD��������>>
	*��Ϣ���� nvservice==>dispatch==>nvterinterface
	*
	*/
	MESSAGE(Ev_NV_PressTerHomeButton_Cmd)

	/*<<�����ն˱�����������>>
	*��Ϣ���� nvservice==>dispatch==>nvterinterface
	*tSoundPlay:  ���ű���������Ϣ
	*/
	MESSAGE(Ev_NV_TerLocalSoundPlay_Cmd)
	BODY(nv::TNVMtLocalSoundPaly, tSoundPlay)

	/*<<�ն˱�����������֪ͨ>>
	*��Ϣ���� nvterinterface==>dispatch==>nvservice
	*tSoundPlay:  ���ű���������Ϣ
	*/
	MESSAGE(Ev_NV_TerLocalSoundPlay_Nty)
	BODY(nv::TNVMtLocalSoundPaly, tSoundPlay)

	/*<<�ն���Ƶ�������>>
	*��Ϣ���� nvservice==>dispatch==>nvterinterface
	*tCfg:  ������Ϣ
	*/
	MESSAGE(Ev_NV_TerAudioOutPowerTest_Cmd)
	BODY(nv::TNVMtAudioTestCfg, tCfg)

	/*<<�ն���Ƶ�������>>
	*��Ϣ���� nvservice==>dispatch==>nvterinterface
	*tCfg:  ������Ϣ
	*/
	MESSAGE(Ev_NV_TerAudioInPowerTest_Cmd)
	BODY(nv::TNVMtAudioTestCfg, tCfg)

	/*<<�ն���Ƶ�������֪ͨ>>
	*��Ϣ���� nvterinterface==>dispatch==>nvservice
	*tPower:  ��Ƶ�������
	*/
	MESSAGE(Ev_NV_TerAudioOutPowerTest_Nty)
	BODY(nv::TNVMtAudioPower, tPower)

	/*<<�ն���Ƶ�������֪ͨ>>
	*��Ϣ���� nvterinterface==>dispatch==>nvservice
	*tPower:  ��Ƶ��������
	*/
	MESSAGE(Ev_NV_TerAudioInPowerTest_Nty)
	BODY(nv::TNVMtAudioPower, tPower)

	/*<<�ն���Ƶ����ӿ�״̬��ѯ����>>
	*��Ϣ���� nvservice==>dispatch==>nvterinterface
	*tSate:  ״̬
	*/
	MESSAGE(Ev_NV_TerAudioInputState_Req)
	BODY(nv::TNVMtMutiAudInState, tSate)

	/*<<�ն���Ƶ����ӿ�״̬��ѯ��Ӧ>>
	*��Ϣ���� nvterinterface==>dispatch==>nvservice
	*tSate:  ״̬
	*/
	MESSAGE(Ev_NV_TerAudioInputState_Rsp)
	BODY(nv::TNVMtMutiAudInState, tSate)

	/*<<��ȡ��¼APS����Ҫ�Ĳ�������>>
	*��Ϣ���� nvservice==>dispatch==>nvterinterface
	*
	*/
	MESSAGE(Ev_NV_GetLoginApsParamCfg_Req)

	/*<<��ȡ��¼APS����Ҫ�Ĳ�����Ӧ>>
	*��Ϣ���� nvterinterface==>dispatch==>nvservice
	*tParm:  ����
	*/
	MESSAGE(Ev_NV_GetLoginApsParamCfg_Rsp)
	BODY(nv::TNVApsLoginParam, tParm)

	/*<<��ȡ����Э��������������>>
	*��Ϣ���� nvservice==>dispatch==>nvterinterface
	*
	*/
	MESSAGE(Ev_NV_GetCallProtocolCfg_Req)

	/*<<��ȡ����Э���������û�Ӧ>>
	*��Ϣ���� nvterinterface==>dispatch==>nvservice
	*emProtocal:  nv::EmMtConfProtocol,Э������
	*/
	MESSAGE(Ev_NV_GetCallProtocolCfg_Rsp)
	BODY(nv::TS32, emProtocal)

	/*<<��ȡXAPList��������>>
	*��Ϣ���� nvservice==>dispatch==>nvterinterface
	*
	*/
	MESSAGE(Ev_NV_GetXAPListCfg_Req)

	/*<<��ȡXAPList���û�Ӧ>>
	*��Ϣ���� nvterinterface==>dispatch==>nvservice
	*tSrvList:  XAPS�������б�
	*/
	MESSAGE(Ev_NV_GetXAPListCfg_Rsp)
	BODY(nv::TNVMtXAPSvrList, tSrvList)

	/*<<��ȡH323������������>>
	*��Ϣ���� nvservice==>dispatch==>nvterinterface
	*
	*/
	MESSAGE(Ev_NV_GetH323PxyCfg_Req)

	/*<<��ȡH323�������û�Ӧ>>
	*��Ϣ���� nvterinterface==>dispatch==>nvservice
	*tCfg:  H323����������Ϣ
	*/
	MESSAGE(Ev_NV_GetH323PxyCfg_Rsp)
	BODY(nv::TNVH323PxyCfg, tCfg)

	/*<<�����ȡ�ֶ����õ�gk��ַ>>
	*��Ϣ���� nvservice==>dispatch==>nvterinterface
	*
	*/
	MESSAGE(Ev_NV_GetGKCfg_Req)

	/*<<��ȡ�ֶ����õ�gk��ַ��Ӧ>>
	*��Ϣ���� nvterinterface==>dispatch==>nvservice
	*tCfg:  gk��ַ��Ϣ
	*/
	MESSAGE(Ev_NV_GetGKCfg_Rsp)
	BODY(nv::TNVMtCSUAddr, tCfg)

	/*<<��ȡ�ֶ�����Sip������������>>
	*��Ϣ���� nvservice==>dispatch==>nvterinterface
	*
	*/
	MESSAGE(Ev_NV_GetManuSipSvrCfg_Req)

	/*<<��ȡ�ֶ�����Sip�����������û�Ӧ>>
	*��Ϣ���� nvterinterface==>dispatch==>nvservice
	*tCfg:  Sip������������
	*/
	MESSAGE(Ev_NV_GetManuSipSvrCfg_Rsp)
	BODY(nv::TNVSipSrvCfg, tCfg)

	/*<<��ȡ�Ƿ������½ƽ̨��������>>
	*��Ϣ���� nvservice==>dispatch==>nvterinterface
	*
	*/
	MESSAGE(Ev_NV_GetLoginPlatformSrvCfg_Req)

	/*<<��ȡ�Ƿ������½ƽ̨�����Ӧ>>
	*��Ϣ���� nvterinterface==>dispatch==>nvservice
	*tLogin: TRUE:��¼��FALSE��δ��¼
	*/
	MESSAGE(Ev_NV_GetLoginPlatformSrvCfg_Rsp)
	BODY(nv::TBOOL32, tLogin)

	/*<<��ȡ�Ƿ�ǿ������H323Э����������>>
	*��Ϣ���� nvservice==>dispatch==>nvterinterface
	*
	*/
	MESSAGE(Ev_NV_GetForceH323StackCfg_Req)

	/*<<��ȡ�Ƿ�ǿ������H323Э�����ͻ�Ӧ>>
	*��Ϣ���� nvterinterface==>dispatch==>nvservice
	*tForceSet: TRUE:ǿ�����ã�FALSE����ǿ������
	*/
	MESSAGE(Ev_NV_GetForceH323StackCfg_Rsp)
	BODY(nv::TBOOL32, tFoeceSet)

	/*<<��ѯ�˺���ϸ��Ϣ����>>
	*��Ϣ���� nvservice==>dispatch==>nvterinterface
	*
	*/
	MESSAGE(Ev_NV_GetAccountInfo_Req)
	BODY(nv::TNVMtAccountManager, tInfo)

	/*<<��ѯ�˺���ϸ��Ϣ��Ӧ>>
	*��Ϣ���� nvterinterface==>dispatch==>nvservice
	*tInfo: �˺���ϸ��Ϣ
	*/
	MESSAGE(Ev_NV_GetAccountInfo_Rsp)
	BODY(nv::TNVMtAccountManager, tInfo)

	/*<<�����ն�������Ϣ��������>>
	*��Ϣ���� nvservice==>dispatch==>nvterinterface
	*tTerName: �ն�����
	*/
	MESSAGE(Ev_NV_SetTerminalNameCfg_Cmd)
	BODY(nv::TNVTerminalName, tTerName)

	/*<<�Ƿ������½ƽ̨����֪ͨ>>
	*��Ϣ���� nvterinterface==>dispatch==>nvservice
	*tLogin: TRUE:��¼��FALSE��δ��¼
	*/
	MESSAGE(Ev_NV_SetLoginPlatformSrvCfg_Ntf)
	BODY(nv::TBOOL32, tLogin)

	/*<<���õ�¼APS����Ҫ�Ĳ�������>>
	*��Ϣ���� nvservice==>dispatch==>nvterinterface
	*tParam: ����
	*/
	MESSAGE(Ev_NV_SetLoginApsParamCfg_Cmd)
	BODY(nv::TNVApsLoginParam, tParam)

	/*<<APS��½�����Ӧ>>
	*��Ϣ���� nvterinterface==>dispatch==>nvservice
	*tLogin: ��¼�ɹ���ʧ��ԭ��
	*tIP: 
	*/
	MESSAGE(Ev_NV_ApsLoginResult_Ntf)
	BODY(nv::TNVMtApsLoginErrcode, tLogin)
	BODY(nv::TU32, tIP)

	/*<<ǿ������H323Э������(��׼/�Ǳ�)���� >>
	*ע�����Խ��ն˵�½�Լ�ƽ̨ʱ����������enableΪtrueʱ���²Ż�ʹ��bstand��ֵ
	*��Ϣ���� nvservice==>dispatch==>nvterinterface
	*tParam: ����
	*/
	MESSAGE(Ev_NV_ForceSet323StackCfg_Cmd)
	BODY(nv::TNVForceSetH323Stack, tParam)

	/*<<ǿ������H323Э������(��׼/�Ǳ�)֪ͨ>>
	*��Ϣ���� nvterinterface==>dispatch==>nvservice
	*tForce: TRUE��ǿ������
	*/
	MESSAGE(Ev_NV_ForceSet323StackCfg_Ntf)
	BODY(nv::TBOOL32, tForce)

	/*<<����XAPList�������� >>
	*��Ϣ���� nvservice==>dispatch==>nvterinterface
	*tParam: XAPList���ò���
	*/
	MESSAGE(Ev_NV_SetXAPListCfg_Cmd)
	BODY(nv::TNVMtXAPSvrList, tParam)

	/*<<����XAPList����֪ͨ>>
	*��Ϣ���� nvterinterface==>dispatch==>nvservice
	*tParam: XAPList���ò���
	*/
	MESSAGE(Ev_NV_SetXAPListCfg_Ntf)
	BODY(nv::TNVMtXAPSvrList, tParam)

	/*<<����H323�������� >>
	*��Ϣ���� nvservice==>dispatch==>nvterinterface
	*tParam: H323���ò���
	*/
	MESSAGE(Ev_NV_SetH323PxyCfg_Cmd)
	BODY(nv::TNVH323PxyCfg, tParam)

	/*<<����H323����֪ͨ>>
	*��Ϣ���� nvterinterface==>dispatch==>nvservice
	*tParam: H323���ò���
	*/
	MESSAGE(Ev_NV_SetH323PxyCfg_Ntf)
	BODY(nv::TNVH323PxyCfg, tParam)

	/*<<����H460�������� >>
	*��Ϣ���� nvservice==>dispatch==>nvterinterface
	*tParam: H460���ò���
	*/
	MESSAGE(Ev_NV_SetH460Cfg_Cmd)
	BODY(nv::TNVH460PxyCfg, tParam)

	/*<<����H460����֪ͨ>>
	*��Ϣ���� nvterinterface==>dispatch==>nvservice
	*tParam: H460���ò���
	*/
	MESSAGE(Ev_NV_SetH460Cfg_Ntf)
	BODY(nv::TNVH460PxyCfg, tParam)

	/*<<��ȡH460����������� >>
	*��Ϣ���� nvservice==>dispatch==>nvterinterface
	*
	*/
	MESSAGE(Ev_NV_GetH460Cfg_Req)

	/*<<��ȡH460���������Ӧ>>
	*��Ϣ���� nvterinterface==>dispatch==>nvservice
	*tParam: H460���ò���
	*/
	MESSAGE(Ev_NV_GetH460Cfg_Rsp)
	BODY(nv::TNVH460PxyCfg, tParam)

	/*<<ע��Sip�������������� >>
	*��Ϣ���� nvservice==>dispatch==>nvterinterface
	*tParam: Sip���������ò���
	*/
	MESSAGE(Ev_NV_SetSipSvrCfg_Cmd)
	BODY(nv::TNVSipSrvCfg, tParam)

	/*<<ע��Sip����������֪ͨ>>
	*��Ϣ���� nvterinterface==>dispatch==>nvservice
	*tParam: Sip���������ò���
	*/
	MESSAGE(Ev_NV_SetSipSvrCfg_Ntf)
	BODY(nv::TNVSipSrvCfg, tParam)

	/*<<�Զ�����ʱ�Ӽ������ >>
	*��Ϣ���� nvservice==>dispatch==>nvterinterface
	*tStart: TRUE:��ʼ��⣬FALSE��ֹͣ
	*/
	MESSAGE(Ev_NV_AutoAudioDelayCheck_Cmd)
	BODY(nv::TBOOL32, tStart)

	/*<<��ȡ��Ƶ����ӿ����� >>
	*��Ϣ���� nvservice==>dispatch==>nvterinterface
	*
	*/
	MESSAGE(Ev_NV_GetAudInPortListCfg_Req)

	/*<<��ȡ��Ƶ����ӿ���Ӧ>>
	*��Ϣ���� nvterinterface==>dispatch==>nvservice
	*tParam: ��Ƶ����ӿڲ���
	*/
	MESSAGE(Ev_NV_GetAudInPortListCfg_Rsp)
	BODY(nv::TNVMtAudInPortList, tParam)

	/*<<���ú����������� >>
	*��Ϣ���� nvservice==>dispatch==>nvterinterface
	*tRate: ��������
	*/
	MESSAGE(Ev_NV_SetCallBitRateCfg_Cmd)
	BODY(nv::TU32, tRate)

	/*<<��������֪ͨ>>
	*��Ϣ���� nvterinterface==>dispatch==>nvservice
	*tRate: ��������
	*/
	MESSAGE(Ev_NV_SetCallBitRateCfg_Ntf)
	BODY(nv::TNVMtCallBitRate, tRate)

	/*<<��ȡ������������ >>
	*��Ϣ���� nvservice==>dispatch==>nvterinterface
	*
	*/
	MESSAGE(Ev_NV_GetCallBitRateCfg_Req)

	/*<<��ȡ����������Ӧ>>
	*��Ϣ���� nvterinterface==>dispatch==>nvservice
	*tRate: ��������
	*/
	MESSAGE(Ev_NV_GetCallBitRateCfg_Rsp)
	BODY(nv::TNVMtCallBitRate, tRate)

	/*<<��������ʱ�Ӽ��֪ͨ>>
	*��Ϣ���� nvterinterface==>dispatch==>nvservice
	*tState: state(EmMtAudioDelayCheckState)�����״̬
	*tResult:��EmMtAudioDelayCheckStateΪemAudioDelayCheckedʱ����ֵ��Ч����ʾʱ��ֵ
	         ��EmMtAudioDelayCheckStateΪemAudioDelayFailedʱ����ֵ��Ч����ʾʧ�ܴ�����
	*/
	MESSAGE(Ev_NV_AutoAudioDelayCheck_Ntf)
	BODY(nv::TU32, tState)
	BODY(nv::TU32, tResult)

	/*<<��ȡ��������¼״̬���� >>
	*��Ϣ���� nvservice==>dispatch==>nvterinterface
	*
	*/
	MESSAGE(Ev_NV_GetSvrStateList_Req)

	/*<<��ȡ��������¼״̬��Ӧ>>
	*��Ϣ���� nvterinterface==>dispatch==>nvservice
	*tList: ��������¼״̬�б�
	*/
	MESSAGE(Ev_NV_GetSvrStateList_Rsp)
	BODY(nv::TNVMtSvrStateList, tList)

	/*<<����Э��ע����֪ͨ>>
	*��Ϣ���� nvterinterface==>dispatch==>nvservice
	*tProtocol: nv::EmMtConfProtocol ����Э������
	*tRegFailReason: nv::EmMtRegFailedReason ע��ɹ���ʧ��ԭ��
	*/
	MESSAGE(Ev_NV_TerRegResult_Ntf)
	BODY(nv::TS32, tProtocol)
	BODY(nv::TS32, tRegFailReason)

	/*<<�ն�ע��CSU�������������� (GK) >>
	*��Ϣ���� nvservice==>dispatch==>nvterinterface
	*tAddr:�ն�CSU������������Ϣ
	*/
	MESSAGE(Ev_NV_SetCSUCfg_Cmd)
	BODY(nv::TNVMtCSUAddr, tAddr)

	/*<<����CSU����֪ͨ>>
	*��Ϣ���� nvterinterface==>dispatch==>nvservice
	*tAddr:�ն�CSU������������Ϣ
	*/
	MESSAGE(Ev_NV_SetCSUCfg_Ntf)
	BODY(nv::TNVMtCSUAddr, tAddr)

	/*<<��ѯSDI�ӿ���������>>
	*��Ϣ���� nvservice==>dispatch==>nvterinterface
	*
	*/
	MESSAGE(Ev_NV_GetTerSdiInOut_Req)

	/*<<��ѯSDI�ӿ�������Ӧ>>
	*��Ϣ���� nvterinterface==>dispatch==>nvservice
	*tType:  nv::EmMtSdiInOut  SDI�ӿ����� 
	*/
	MESSAGE(Ev_NV_GetTerSdiInOut_Rsp)
	BODY(nv::TS32, tType)

	/*<<��ѯ��˷�����״̬����>>
	*��Ϣ���� nvservice==>dispatch==>nvterinterface
	*
	*/
	MESSAGE(Ev_NV_GetMicrophoneConnectStatus_Req)

	/*<<��ѯ��˷�����״̬��Ӧ>>
	*��Ϣ���� nvterinterface==>dispatch==>nvservice
	*tStatus:  ȫ�������״̬��Ϣ
	*/
	MESSAGE(Ev_NV_GetMicrophoneConnectStatus_Rsp)
	BODY(nv::TNVMtAllMicStatus, tStatus)

	/*<<��˷�����״̬֪ͨ>>
	*��Ϣ���� nvterinterface==>dispatch==>nvservice
	*tStatus:  ȫ�������״̬��Ϣ
	*/
	MESSAGE(Ev_NV_MicrophoneConnectStatus_Ntf)
	BODY(nv::TNVMtAllMicStatus, tStatus)

	/*<<��ȡ��һ·����Ƶ����˿�����>>
	*��Ϣ���� nvservice==>dispatch==>nvterinterface
	*
	*/
	MESSAGE(Ev_NV_GetPri1stVidInPortCfg_Req)

	/*<<��ȡ��һ·����Ƶ����˿ڻ�Ӧ>>
	*��Ϣ���� nvterinterface==>dispatch==>nvservice
	*tPort:  ������Ƶ����˿�
	*/
	MESSAGE(Ev_NV_GetPri1stVidInPortCfg_Rsp)
	BODY(nv::TNVMtHDVidInPort, tPort)

	/*<<��ȡ����Ƶ����˿�����>>
	*��Ϣ���� nvservice==>dispatch==>nvterinterface
	*
	*/
	MESSAGE(Ev_NV_GetAssVidInPortCfg_Req)

	/*<<��ȡ����Ƶ����˿ڻ�Ӧ>>
	*��Ϣ���� nvterinterface==>dispatch==>nvservice
	*tPort:  ������Ƶ����˿�
	*/
	MESSAGE(Ev_NV_GetAssVidInPortCfg_Rsp)
	BODY(nv::TNVMtHDVidInPort, tPort)

	/*<<��ȡ�ڶ�·������Ƶ����˿�����>>
	*��Ϣ���� nvservice==>dispatch==>nvterinterface
	*
	*/
	MESSAGE(Ev_NV_GetPri2ndVidInPortCfg_Req)

	/*<<��ȡ�ڶ�·������Ƶ����˿ڻ�Ӧ>>
	*��Ϣ���� nvterinterface==>dispatch==>nvservice
	*tPort:  ������Ƶ����˿�
	*/
	MESSAGE(Ev_NV_GetPri2ndVidInPortCfg_Rsp)
	BODY(nv::TNVMtHDVidInPort, tPort)

	/*<<������Ƶ����ӿ����� >>
	*��Ϣ���� nvservice==>dispatch==>nvterinterface
	*tList: ��Ƶ����ӿڲ���
	*/
	MESSAGE(Ev_NV_SetAudInPortListCfg_Cmd)
	BODY(nv::TNVMtAudInPortList, tList)

	/*<<������Ƶ����ӿ�֪ͨ>>
	*��Ϣ���� nvterinterface==>dispatch==>nvservice
	*tList: ��Ƶ����ӿڲ���
	*/
	MESSAGE(Ev_NV_SetAudInPortListCfg_Ntf)
	BODY(nv::TNVMtAudInPortList, tList)

	/*<<�����������֪ͨ�ն� >>
	*��Ϣ���� nvservice==>dispatch==>nvterinterface
	*
	*/
	MESSAGE(Ev_NV_SetWizardResult_Cmd)

	/*<<֪ͨimix�ָ���������>>
	*��Ϣ���� nvterinterface==>dispatch==>nvservice
	*/
	MESSAGE(Ev_NV_ResetImixSys_Ntf)

	/*<<��ȡ�ն�GK�Ƿ�ע������>>
	*��Ϣ���� nvservice==>dispatch==>nvterinterface
	*
	*/
	MESSAGE(Ev_NV_GetGKRegistRt_Req)

	/*<<��ȡ�ն�GK�Ƿ�ע���Ӧ>>
	*��Ϣ���� nvterinterface==>dispatch==>nvservice
	*tIsRegist:  �Ƿ�ע��
	*/
	MESSAGE(Ev_NV_GetGKRegistRt_Rsp)
	BODY(nv::TBOOL32, tIsRegist)

	/*<<��ȡ�ն�Sip�Ƿ�ע������>>
	*��Ϣ���� nvservice==>dispatch==>nvterinterface
	*
	*/
	MESSAGE(Ev_NV_GetSipRegistRt_Req)

	/*<<��ȡ�ն�Sip�Ƿ�ע���Ӧ>>
	*��Ϣ���� nvterinterface==>dispatch==>nvservice
	*tIsRegist:  �Ƿ�ע��
	*/
	MESSAGE(Ev_NV_GetSipRegistRt_Rsp)
	BODY(nv::TBOOL32, tIsRegist)

	/*<<�����ն�֪ͨ>>
	*��Ϣ���� nvterinterface==>dispatch==>nvservice
	*tIsReset:  �Ƿ�����
	*/
	MESSAGE(Ev_NV_RestTer_Nty)
	BODY(nv::TBOOL32, tIsReset)

	/*<<�ն�ң������������֪ͨ>>
	*��Ϣ���� nvterinterface==>dispatch==>nvservice
	*tbVolUp:  TRUE: ����+ FALSE: ����-
	*/
	MESSAGE(Ev_NV_DeviceKeyVolume_Nty)
	BODY(nv::TBOOL32, tbVolUp)

	/*<<ϵͳ�ػ�ʱ��֪ͨ�ն˴���>>
	*��Ϣ���� nvdevice==>dispatch==>nvterinterface
	*
	*/
	MESSAGE(Ev_NV_DeviceTurnOffToSleepMT_Nty)

#if !defined(_MESSAGE_HELP_)
    EV_END(TERINTERFACE) = EVSEG_TERINTERFACE_END
};
#endif//_MESSAGE_HELP_

#define Is_Terinterface_Msg(m) ((m) >= EV_BGN(TERINTERFACE) && (m) <= EV_END(TERINTERFACE))

#endif//_NVTERINTERFACEMSG_H_
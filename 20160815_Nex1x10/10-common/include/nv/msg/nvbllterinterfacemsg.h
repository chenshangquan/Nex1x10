#ifndef _NVBLLTERINTERFACEMSG_H_
#define _NVBLLTERINTERFACEMSG_H_

#include "nvmsgid.h"
#include "nvstruct.pb.h"

#if !defined(_MESSAGE_HELP_)
enum EmBLLTerInterfaceCEMsg
{							  
    EV_BLL_BGN(TERINTERFACE) = EVSEG_BLL_TERINTERFACE_BGN,
#endif

/*<<�����ն�״̬�ϱ�>>
	* is_login ���Ƿ�����ն˳ɹ�
	*��Ϣ���� nvterinterface ==>dispatch==>nvservice
	*/
	MESSAGE(Ev_NV_BLL_MTCLogin_Ntf)         
	BODY(nv::TBOOL32, is_login)
	
	
	/*<<��������>>
	*��Ϣ���� sdk==>dispatch==>nvservice
	*/
    MESSAGE(Ev_NV_BLL_CodecDspSleep_Req)

	/*<<������Ӧ>>
	*��Ϣ���� nvservice==>dispatch==>sdk
	* is_sucess: �Ƿ��������
	* fail_reason: ����ʧ��ԭ��
	*/
    MESSAGE(Ev_NV_BLL_CodecDspSleep_Rsp)
	BODY(nv::TBOOL32, is_sucess)
	BODY(nv::TS32, fail_reason) //ö��ֵͳһʹ��nv::TS32�����䣬�ô�ʵ��Ϊnv::EmNvSleepFailReason
		
	/*<<��������>>
	*��Ϣ���� sdk==>dispatch==>nvservice
	*/
    MESSAGE(Ev_NV_BLL_CodecDspWakeup_Cmd)

	/*<<����״̬�ϱ�>>
	*��Ϣ���� nvservice==>dispatch==>sdk
	*is_sleep : TRUE��ʾ����˯��״̬��FALSE��ʾ���뻽��״̬
	*/
    MESSAGE(Ev_NV_BLL_CodecSleepState_Ntf)
	BODY(nv::TBOOL32, is_sleep)

	/*<<����ʧ��ԭ���ϱ�>>
	*��Ϣ���� nvservice==>dispatch==>sdk
	*fail_reason : ʧ��ԭ��
	*/
    MESSAGE(Ev_NV_BLL_CodecSleepFailReason_Ntf)
	BODY(nv::TS32, fail_reason) //ö��ֵͳһʹ��nv::TS32�����䣬�ô�ʵ��Ϊnv::EmNvSleepFailReason
	
	/*<<��ui���ʹ�������ʱ֪ͨ>>
	* nvservice==>dispatch==>sdk
	*count_down : ����ʱʱ��
	*/
	MESSAGE(Ev_NV_BLL_SleepCountDown_Ntf)
	BODY(nv::TU16, count_down)	//����ʱʱ��

	/*<<��ǰ��˫��״̬�ϱ�>>
	* is_senddual ���Ƿ���˫��
	*��Ϣ���� nvservice ==>dispatch==>sdk
	*/
	MESSAGE(Ev_NV_BLL_AssSndSream_Status_Ntf)         
	BODY(NV::TBOOL32, is_senddual)
	BODY(NV::TS32, vid_lab) //ö��ֵͳһʹ��nv::TS32�����䣬�ô�ʵ��Ϊnv::EmNvVidLabel
	
	/*<<��ǰ��˫��״̬�ϱ�>>
	* is_rcvdual ���Ƿ����˫��
	*��Ϣ���� nvservice ==>dispatch==>sdk
	*/
	MESSAGE(Ev_NV_BLL_AssRcvSream_Status_Ntf)         
	BODY(NV::TBOOL32, is_rcvdual)

	/*<<��ǰ�ĺ���״̬�ϱ�>>
	* callsate ���ϱ��ĺ��в���
	*��Ϣ���� nvterinterface ==>dispatch==>nvservice
	*/
	MESSAGE(Ev_NV_BLL_CallLinkState_Ntf)         //post to UI  ��ǰ����״̬
	BODY(nv::TS32, callsate)	//ö��ֵͳһʹ��nv::TS32�����䣬�ô�ʵ��Ϊnv::EmNvCallState
	
	/*<<����ǰ��������״̬>>
	* ��Ϣ���� ��sdk==>dispatch==>nvservice
	*/
	MESSAGE( Ev_NV_BLL_AssSndSream_Status_Req)             //��������ǰ�ն˵�˫���������
	

	/*<<����ǰ��������״̬>>
	* ��Ϣ���� ��sdk==>dispatch==>nvservice
	*/
	MESSAGE( Ev_NV_BLL_AssRcvSream_Status_Req)             //��������ǰ�ն˵�˫���������
	
	/*<<��ǰ�ĺ���״̬����>>
	*��Ϣ���� ��sdk==>dispatch==>nvservice
	*/
	MESSAGE( Ev_NV_BLL_CallLinkState_Req)
	
	/*<<����ͬ������>>
	* reason ͬ��ԭ��
	* ��Ϣ���� ��sdk==>dispatch==>nvservice
	*/
	MESSAGE( Ev_NV_BLL_UISynchronize_Cmd)           //����ͬ������
	BODY(nv::TS32,       reason)            //ͬ��ԭ��  ö��ֵͳһʹ��nv::TS32�����䣬�ô�ʵ��Ϊnv::EmNvUISynchronizeReason

	/*<<���ڽ���ͬ��>> 
	* reason ͬ��ԭ��
	* ��Ϣ���� nvservice==>dispatch==>sdk
	*/
	MESSAGE( Ev_NV_BLL_UISynchronize_Ntf)        //���ڽ���ͬ��
	BODY(nv::TS32,       reason)            //ͬ��ԭ��  ö��ֵͳһʹ��nv::TS32�����䣬�ô�ʵ��Ϊnv::EmNvUISynchronizeReason
	
	/*<<��ǰ�ĵ����ն�״̬����>>
	*��Ϣ���� ��sdk==>dispatch==>nvservice
	*/
	MESSAGE( Ev_NV_BLL_MTCLogin_Status_Req)
	
	/*<<��ǰ�ĵ����ն�����״̬����>>
	*��Ϣ���� ��sdk==>dispatch==>nvservice
	*/
	MESSAGE( Ev_NV_BLL_CodecGetLocalMicMute_Req)
	
	/*<<��ǰ����״̬�ϱ�>>
	* is_mute ���Ƿ�����
	* ��Ϣ���� nvservice==>dispatch==>sdk
	*/
	MESSAGE(Ev_NV_BLL_CodecMute_Ntf)         
	BODY(NV::TBOOL32, is_mute)
	
	/*<<��ǰ��˫��״̬�ϱ�>>
	* is_senddual ���Ƿ���˫��
	*��Ϣ���� nvservice ==>dispatch==>sdk
	*/
	MESSAGE(Ev_NV_BLL_AssSndSream_Status_Rsp)         
	BODY(NV::TBOOL32, is_senddual)
	BODY(NV::TS32, vid_lab) //ö��ֵͳһʹ��nv::TS32�����䣬�ô�ʵ��Ϊnv::EmNvVidLabel
	
	/*<<��ǰ��˫��״̬�ϱ�>>
	* is_rcvdual ���Ƿ����˫��
	*��Ϣ���� nvservice ==>dispatch==>sdk
	*/
	MESSAGE(Ev_NV_BLL_AssRcvSream_Status_Rsp)         
	BODY(NV::TBOOL32, is_rcvdual)
	
	/*<<video˫�����������>>
	* bOpen �������߹�
	* ��Ϣ���� ��sdk==>dispatch==>nvservice
	*/
	MESSAGE( Ev_NV_BLL_VideoAssStream_Cmd )
	BODY(nv:TBOOL32,  bOpen)                       //true : open��  false: close
	
	/*<<�ػ�����ϱ�>>
	*��Ϣ���� nvservice==>dispatch==>sdk
	*reason : ʧ��ԭ��
	*/
    MESSAGE(Ev_NV_BLL_PowerTurnOff_Ntf)
	BODY(nv::TS32, reason) //ö��ֵͳһʹ��nv::TS32�����䣬�ô�ʵ��Ϊnv::EmNvPowerTurnOffReason
	
	/*<<�ػ�����>>
	*��Ϣ���� nvservice==>dispatch==>sdk
	*/
    MESSAGE(Ev_NV_BLL_PowerTurnOff_Req)

	/*<<sdk�ػ��ظ�>>
	*��Ϣ���� sdk==>dispatch==>nvservice
	* bturnoff �������߹�
	*/
    MESSAGE(Ev_NV_BLL_PowerTurnOff_Rsp)
	BODY(nv:TBOOL32,  bturnoff)	

	/*<<��ǰӦ��ʽ��ѯ>>
	* 
	*��Ϣ���� sdk==>dispatch==>nvservice
	*/
	MESSAGE(Ev_NV_BLL_AnswerMode_Req)
	
	/*<<��ȡ��ǰ����ʱ����Ϣ>>
	*���䷽��sdk==>dispatch==>nvservice
	*/
	MESSAGE(Ev_NV_BLL_GetMtSysDataTime_Req)
	
	/*<<��ȡ��ǰ����ʱ����Ϣ��Ӧ>>
	*BODY ��   result ���ý�� 0�ɹ� ����������
	           tmttime ʱ����Ϣ 
	*���䷽��nvservice==>dispatch==>sdk
	*/
	MESSAGE(Ev_NV_BLL_GetMtSysDataTime_Rsp)
	BODY(nv::TU32, result)
	BODY(nv::TNVTime, tmttime )
	
	/*<<�����ն˵�ǰ����ʱ����Ϣ��Ӧ>>
	*BODY ��   result ���ý�� 0�ɹ� ����������
	           tmttime ʱ����Ϣ 
	*���䷽��nvservice==>dispatch==>sdk
	*/
	MESSAGE(Ev_NV_BLL_SetMtSysDataTimeResult_Rsp)
	BODY(nv::TU32, result)
	BODY(nv::TNVTime, tmttime )
	
	/*<<�����ն˵�ǰ����ʱ��֪ͨ>>
	*BODY ��   tmttime ʱ����Ϣ 
	*���䷽��nvservice==>dispatch==>sdk
	* see
	*/
	MESSAGE(Ev_NV_BLL_SetMtSysDataTime_Ntf)
	BODY(nv::TNVTime, tmttime )
	
	/*<<��ȡ�ն˵�ǰʱ��������Ϣ>>
	*���䷽��sdk==>dispatch==>nvservice
	*/
	MESSAGE(Ev_NV_BLL_GetMtSysTimeCfg_Req)
	
	/*<<��ȡ�ն˵�ǰʱ��������Ϣ��Ӧ>>
	*BODY �� tmttime ʱ����Ϣ
	*���䷽��nvservice==>dispatch==>sdk
	*/
	MESSAGE(Ev_NV_BLL_GetMtSysTimeCfg_Rsp)
	BODY(nv::TNVCfgMtSystemTime, tmttime )
	
	/*<<�ն˵�ǰʱ��������Ϣ֪ͨ>>
	*BODY �� tmttime ʱ����Ϣ
	*���䷽��nvservice==>dispatch==>sdk
	*/
	MESSAGE(Ev_NV_BLL_SetMtSysTimeCfg_Ntf)
	BODY(nv::TNVCfgMtSystemTime, tmttime )
	
	/*<<��ɫ��ͼ>>
	*BODY �� tmttime ʱ����Ϣ
	*���䷽��nvservice==>dispatch==>sdk
	*/
	MESSAGE(Ev_NV_BLL_SetBluePic_Nty)
	BODY(nv:TBOOL32,  bBlue)	
	/*<<OSD֪ͨ>>
	*BODY �� tmttime ʱ����Ϣ
	*���䷽��nvservice==>dispatch==>sdk
	*/
	MESSAGE(Ev_NV_BLL_SetOSD_Nty)	
	BODY(nv:TBOOL32,  bOSD)	
	
	/*<<ϵͳ��Ϣ��ʾ>>
	*BODY �� tSysHint ��Ϣ��ʾ
	*���䷽��nvservice ==>dispatch==>sdk
	*/
	MESSAGE(Ev_NV_BLL_MtSysHint_Ntf)
	BODY(nv::TS32, tSysHint ) //ö��ֵͳһʹ��nv::TS32�����䣬�ô�ʵ��Ϊnv::EmNvHintCode
	
	/*<<����״̬����>>
	*��Ϣ���� sdk==>dispatch==>nvservice
	*/
    MESSAGE(Ev_NV_BLL_GetCodecDspSleep_Req)
	
	/*<<����״̬����ظ�>>
	*��Ϣ���� nvservice==>dispatch==>sdk
	*/
    MESSAGE(Ev_NV_BLL_GetCodecDspSleep_Rsp)
	BODY(nv:TBOOL32,  bsleep)
	
	/*<<��ѯ�ն�����>>
	*��Ϣ���� ��sdk==>dispatch==>nvservice
	*/
	MESSAGE( Ev_NV_BLL_GetTerminalName_Req)
	
	/*<<��ѯ�ն�������Ӧ>>
	*BODY ��   name �ն�����
	*���䷽��nvservice==>dispatch==>sdk
	*/
	MESSAGE(Ev_NV_BLL_GetTerminalName_Rsp)
	BODY(nv::TNVTerminalName, name)
	
	/*<<�ն�����֪ͨ>>
	*BODY ��   name �ն�����
	*���䷽��nvservice==>dispatch==>sdk
	*/
	MESSAGE(Ev_NV_BLL_SetTerminalName_Ntf)
	BODY(nv::TNVTerminalName, name)
	
	/*<<�ն˳���ȫ�������ɹ�֪ͨ>>
	*��Ϣ���� nvservice==>dispatch==>sdk
	*/
	MESSAGE(Ev_NV_BLL_HDMtStartSucess_Ntf) 
	
	/*<<��ѯ�ն˳����Ƿ�ȫ�������ɹ�>>
	*��Ϣ���� sdk==>dispatch==>nvservice
	*/
    MESSAGE(Ev_NV_BLL_InquireHDMtStartSucess_Req)
	
	/*<<��ѯ�ն˳����Ƿ�ȫ�������ɹ���Ӧ>>
	*��Ϣ���� nvservice==>dispatch==>sdk
	*/
    MESSAGE(Ev_NV_BLL_InquireHDMtStartSucess_Rsp)
	BODY(nv:TBOOL32,  bsuc)
	
	/*<<����IMIXͨ���ýӿڸ��ն˷�����Ϣ(����512�ֽ�)���ն˽��ն���Ϣ����ʾ��OSD�ϣ�>>
	*BODY �� LocSms ���ض���Ϣ
	*sdk==>dispatch==>nvservice
	*/
	MESSAGE(Ev_NV_BLL_SendLocalSms_Cmd)
	BODY(nv::TString, LocSms )

	/*<<�����ն�NAT��ַ��>>
	*BODY �� NatEnable���Ƿ�����NAT
	*BODY �� NatIP:NatIP��ַ 
	*sdk==>dispatch==>nvservice
	*/
	MESSAGE(Ev_NV_BLL_SetTerNatIpCfg_Cmd)
	BODY(nv::TBOOL32, NatEnable)
	BODY(nv::TString, NatIP)

	/*<<�����ն�NAT��ַ��Ӧ��>>
	*BODY �� NatEnable���Ƿ�����NAT
	*BODY �� NatIP:NatIP��ַ 
	*nvservice==>dispatch==>sdk
	*/
	MESSAGE(Ev_NV_BLL_SetTerNatIpCfg_Rsp)
	BODY(nv::TBOOL32, bResult)
	BODY(nv::TBOOL32, NatEnable)
	BODY(nv::TU32, NatIP)

	/*<<��ѯIMIX�汾>>
	*BODY ��
	*sdk==>dispatch==>nvservice
	*/
	MESSAGE(Ev_NV_BLL_GetImixMode_Req)	
	
	/*<<��ѯIMIX�汾��Ӧ��>>	
	*sdk==>dispatch==>nvservice
	*/
	MESSAGE(Ev_NV_BLL_GetImixMode_Rsp)	
	BODY(nv::TString, ImixMode)

	/*<<�����ն��Զ�������>>
	*BODY �� tcfg���Զ�������Ϣ
	*sdk==>dispatch==>nvservice
	*/
	MESSAGE(Ev_NV_BLL_SetTerAutoSleep_Cmd)
	BODY(nv::TNVMtAutoSleepCfg, tcfg)

	/*<<�����ն��Զ�����֪ͨ��>>
	*BODY �� tcfg���Զ�������Ϣ
	*nvservice==>dispatch==>sdk
	*/
	MESSAGE(Ev_NV_BLL_SetTerAutoSleep_Nty)
	BODY(nv::TNVMtAutoSleepCfg, tcfg)

	/*<<��ѯ�ն��Զ�������Ϣ��>>
	*BODY ��
	*nvservice==>dispatch==>sdk
	*/
	MESSAGE(Ev_NV_BLL_GetTerAutoSleep_Req)

	/*<<��ѯ�ն��Զ�������Ϣ��Ӧ��>>
	*BODY ��tcfg���Զ�������Ϣ
	*nvservice==>dispatch==>sdk
	*/
	MESSAGE(Ev_NV_BLL_GetTerAutoSleep_Rsp)
	BODY(nv::TNVMtAutoSleepCfg, tcfg)

	/*<<˫������ʧ��ԭ��֪ͨ>>
	*BODY ��tcfg���Զ�������Ϣ
	*nvservice==>dispatch==>sdk
	*/
	MESSAGE(Ev_NV_BLL_SendDualFailReason_Nty)
	BODY(nv::TS32, tReason)

	/*<<�ն˻ָ�������������>>
	*BODY ��tDelCfgFile���Ƿ�ɾ�������ļ�
	*sdk==>dispatch==>nvservice
	*/
	MESSAGE(Ev_NV_BLL_ResetTerCfg_Cmd)
	BODY(nv::TBOOL32, tDelCfgFile)

	/*<<�����ն�ʱ����������>>
	*BODY ��tCfg��ʱ����Ϣ
	*sdk==>dispatch==>nvservice
	*/
	MESSAGE(Ev_NV_BLL_SetTerTimeCfg_Cmd)
	BODY(nv::TNVCfgMtSystemTime, tCfg)

	/*<<�����ն˵�ǰʱ����Ϣ>>
	*BODY ��tCfg��ʱ����Ϣ
	*sdk==>dispatch==>nvservice
	*/
	MESSAGE(Ev_NV_BLL_SetMtSysDataTime_Req)
	BODY(nv::TNVTime, tCfg)

	/*<<�����ն��Ƿ������¼��ƽ̨>>
	*BODY ��tLogin��TRUE������
	*sdk==>dispatch==>nvservice
	*/
	MESSAGE(Ev_NV_BLL_SetTerLoginPlatformSrvCfg_Cmd)
	BODY(nv::TBOOL32, tLogin)

	/*<<��ȡ�ն�ip����>>
	*BODY ��tLogin��TRUE������
	*sdk==>dispatch==>nvservice
	*/
	MESSAGE(Ev_NV_BLL_GetTerIp_Req)

	/*<<��ȡ�ն�ip��Ӧ>>
	*BODY ��tTerip���ն�ip
	*nvservice==>dispatch==>sdk
	*/
	MESSAGE(Ev_NV_BLL_GetTerIp_Rsp)
	BODY(nv::TString, tTerIp)

	/*<<��ȡ�ն�Ӳ����Ϣ����>>
	*BODY ��tLogin��TRUE������
	*sdk==>dispatch==>nvservice
	*/
	MESSAGE(Ev_NV_BLL_GetTerHWInfo_Cmd)

	/*<<��ȡ�ն�Ӳ����Ϣ��Ӧ>>
	*BODY ��tInfo���ն�Ӳ����Ϣ
	*nvservice==>dispatch==>sdk
	*/
	MESSAGE(Ev_NV_BLL_GetTerHWInfo_Nty)
	BODY(nv::TNVHWInfo, tInfo)

	/*<<�����ն˱�����������>>
	*��Ϣ���� sdk==>dispatch==>nvservice
	*tSoundPlay:  ���ű���������Ϣ
	*/
	MESSAGE(Ev_NV_BLL_TerLocalSoundPlay_Cmd)
	BODY(nv::TNVMtLocalSoundPaly, tSoundPlay)

	/*<<�ն˱�����������֪ͨ>>
	*��Ϣ���� nvservice==>dispatch==>sdk
	*tSoundPlay:  ���ű���������Ϣ
	*/
	MESSAGE(Ev_NV_BLL_TerLocalSoundPlay_Nty)
	BODY(nv::TNVMtLocalSoundPaly, tSoundPlay)

	/*<<�ն���Ƶ�������>>
	*��Ϣ���� sdk==>dispatch==>nvservice
	*tCfg:  ������Ϣ
	*/
	MESSAGE(Ev_NV_BLL_TerAudioOutPowerTest_Cmd)
	BODY(nv::TNVMtAudioTestCfg, tCfg)

	/*<<�ն���Ƶ�������>>
	*��Ϣ���� sdk==>dispatch==>nvservice
	*tCfg:  ������Ϣ
	*/
	MESSAGE(Ev_NV_BLL_TerAudioInPowerTest_Cmd)
	BODY(nv::TNVMtAudioTestCfg, tCfg)

	/*<<�ն���Ƶ�������֪ͨ>>
	*��Ϣ���� nvservice==>dispatch==>sdk
	*tPower:  ��Ƶ�������
	*/
	MESSAGE(Ev_NV_BLL_TerAudioOutPowerTest_Nty)
	BODY(nv::TNVMtAudioPower, tPower)

	/*<<�ն���Ƶ�������֪ͨ>>
	*��Ϣ���� nvservice==>dispatch==>sdk
	*tPower:  ��Ƶ��������
	*/
	MESSAGE(Ev_NV_BLL_TerAudioInPowerTest_Nty)
	BODY(nv::TNVMtAudioPower, tPower)

	/*<<�ն���Ƶ����ӿ�״̬��ѯ����>>
	*��Ϣ���� sdk==>dispatch==>nvservice
	*tSate:  ״̬
	*/
	MESSAGE(Ev_NV_BLL_TerAudioInputState_Req)
	BODY(nv::TNVMtMutiAudInState, tSate)

	/*<<�ն���Ƶ����ӿ�״̬��ѯ��Ӧ>>
	*��Ϣ���� nvservice==>dispatch==>sdk
	*tSate:  ״̬
	*/
	MESSAGE(Ev_NV_BLL_TerAudioInputState_Rsp)
	BODY(nv::TNVMtMutiAudInState, tSate)

	/*<<��ȡ��¼APS����Ҫ�Ĳ�������>>
	*��Ϣ���� sdk==>dispatch==>nvservice
	*
	*/
	MESSAGE(Ev_NV_BLL_GetLoginApsParamCfg_Req)

	/*<<��ȡ��¼APS����Ҫ�Ĳ�����Ӧ>>
	*��Ϣ���� nvservice==>dispatch==>sdk
	*tParm:  ����
	*/
	MESSAGE(Ev_NV_BLL_GetLoginApsParamCfg_Rsp)
	BODY(nv::TNVApsLoginParam, tParm)

	/*<<��ȡ����Э��������������>>
	*��Ϣ���� sdk==>dispatch==>nvservice
	*
	*/
	MESSAGE(Ev_NV_BLL_GetCallProtocolCfg_Req)

	/*<<��ȡ����Э���������û�Ӧ>>
	*��Ϣ���� nvservice==>dispatch==>sdk
	*emProtocal:  nv::EmMtConfProtocol,Э������
	*/
	MESSAGE(Ev_NV_BLL_GetCallProtocolCfg_Rsp)
	BODY(nv::TS32, emProtocal)

	/*<<��ȡXAPList��������>>
	*��Ϣ���� sdk==>dispatch==>nvservice
	*
	*/
	MESSAGE(Ev_NV_BLL_GetXAPListCfg_Req)

	/*<<��ȡXAPList���������Ӧ>>
	*��Ϣ���� nvservice==>dispatch==>sdk
	*tSrvList:  XAPS�������б�
	*/
	MESSAGE(Ev_NV_BLL_GetXAPListCfg_Rsp)
	BODY(nv::TNVMtXAPSvrList, tSrvList)

	/*<<��ȡH323������������>>
	*��Ϣ���� sdk==>dispatch==>nvservice
	*
	*/
	MESSAGE(Ev_NV_BLL_GetH323PxyCfg_Req)

	/*<<��ȡH323�������û�Ӧ>>
	*��Ϣ���� nvservice==>dispatch==>sdk
	*tCfg:  H323����������Ϣ
	*/
	MESSAGE(Ev_NV_BLL_GetH323PxyCfg_Rsp)
	BODY(nv::TNVH323PxyCfg, tCfg)

	/*<<�����ȡ�ֶ����õ�gk��ַ>>
	*��Ϣ���� sdk==>dispatch==>nvservice
	*
	*/
	MESSAGE(Ev_NV_BLL_GetGKCfg_Req)

	/*<<��ȡ�ֶ����õ�gk��ַ��Ӧ>>
	*��Ϣ���� nvservice==>dispatch==>sdk
	*tCfg:  gk��ַ��Ϣ
	*/
	MESSAGE(Ev_NV_BLL_GetGKCfg_Rsp)
	BODY(nv::TNVMtCSUAddr, tCfg)

	/*<<��ȡ�ֶ�����Sip������������>>
	*��Ϣ���� sdk==>dispatch==>nvservice
	*
	*/
	MESSAGE(Ev_NV_BLL_GetManuSipSvrCfg_Req)

	/*<<��ȡ�ֶ�����Sip�����������û�Ӧ>>
	*��Ϣ���� nvservice==>dispatch==>sdk
	*tCfg:  Sip������������
	*/
	MESSAGE(Ev_NV_BLL_GetManuSipSvrCfg_Rsp)
	BODY(nv::TNVSipSrvCfg, tCfg)

	/*<<��ȡ�Ƿ������½ƽ̨��������>>
	*��Ϣ���� sdk==>dispatch==>nvservice
	*
	*/
	MESSAGE(Ev_NV_BLL_GetLoginPlatformSrvCfg_Req)

	/*<<��ȡ�Ƿ������½ƽ̨�����Ӧ>>
	*��Ϣ���� nvservice==>dispatch==>sdk
	*tLogin: TRUE:��¼��FALSE��δ��¼
	*/
	MESSAGE(Ev_NV_BLL_GetLoginPlatformSrvCfg_Rsp)
	BODY(nv::TBOOL32, tLogin)

	/*<<��ȡ�Ƿ�ǿ������H323Э����������>>
	*��Ϣ���� sdk==>dispatch==>nvservice
	*
	*/
	MESSAGE(Ev_NV_BLL_GetForceH323StackCfg_Req)

	/*<<��ȡ�Ƿ�ǿ������H323Э�����ͻ�Ӧ>>
	*��Ϣ���� nvservice==>dispatch==>sdk
	*tForceSet: TRUE:ǿ�����ã�FALSE����ǿ������
	*/
	MESSAGE(Ev_NV_BLL_GetForceH323StackCfg_Rsp)
	BODY(nv::TBOOL32, tFoeceSet)

	/*<<��ѯ�˺���ϸ��Ϣ����>>
	*��Ϣ���� sdk==>dispatch==>nvservice
	*
	*/
	MESSAGE(Ev_NV_BLL_GetAccountInfo_Req)
	BODY(nv::TNVMtAccountManager, tInfo)

	/*<<��ѯ�˺���ϸ��Ϣ��Ӧ>>
	*��Ϣ���� nvservice==>dispatch==>sdk
	*tInfo: �˺���ϸ��Ϣ
	*/
	MESSAGE(Ev_NV_BLL_GetAccountInfo_Rsp)
	BODY(nv::TNVMtAccountManager, tInfo)

	/*<<�����ն�������Ϣ��������>>
	*��Ϣ���� sdk==>dispatch==>nvservice
	*tTerName: �ն�����
	*/
	MESSAGE(Ev_NV_BLL_SetTerminalNameCfg_Cmd)
	BODY(nv::TNVTerminalName, tTerName)

	/*<<�Ƿ������½ƽ̨����֪ͨ>>
	*��Ϣ���� nvservice==>dispatch==>sdk
	*tLogin: TRUE:��¼��FALSE��δ��¼
	*/
	MESSAGE(Ev_NV_BLL_SetLoginPlatformSrvCfg_Ntf)
	BODY(nv::TBOOL32, tLogin)

	/*<<���õ�¼APS����Ҫ�Ĳ�������>>
	*��Ϣ���� sdk==>dispatch==>nvservice
	*tParam: ����
	*/
	MESSAGE(Ev_NV_BLL_SetLoginApsParamCfg_Cmd)
	BODY(nv::TNVApsLoginParam, tParam)

	/*<<APS��½�����Ӧ>>
	*��Ϣ���� nvservice==>dispatch==>sdk
	*tLogin: ��¼�ɹ���ʧ��ԭ��
	*/
	MESSAGE(Ev_NV_BLL_ApsLoginResult_Ntf)
	BODY(nv::TNVMtApsLoginErrcode, tLogin)
	BODY(nv::TU32, tIP)

	/*<<ǿ������H323Э������(��׼/�Ǳ�)���� >>
	*ע�����Խ��ն˵�½�Լ�ƽ̨ʱ����������enableΪtrueʱ���²Ż�ʹ��bstand��ֵ
	*��Ϣ���� sdk==>dispatch==>nvservice
	*tParam: ����
	*/
	MESSAGE(Ev_NV_BLL_ForceSet323StackCfg_Cmd)
	BODY(nv::TNVForceSetH323Stack, tParam)

	/*<<ǿ������H323Э������(��׼/�Ǳ�)֪ͨ>>
	*��Ϣ���� nvservice==>dispatch==>sdk
	*tForce: TRUE��ǿ������
	*/
	MESSAGE(Ev_NV_BLL_ForceSet323StackCfg_Ntf)
	BODY(nv::TBOOL32, tForce)

	/*<<����XAPList�������� >>
	*��Ϣ���� sdk==>dispatch==>nvservice
	*tParam: XAPList���ò���
	*/
	MESSAGE(Ev_NV_BLL_SetXAPListCfg_Cmd)
	BODY(nv::TNVMtXAPSvrList, tParam)

	/*<<����XAPList����֪ͨ>>
	*��Ϣ���� nvservice==>dispatch==>sdk
	*tParam: XAPList���ò���
	*/
	MESSAGE(Ev_NV_BLL_SetXAPListCfg_Ntf)
	BODY(nv::TNVMtXAPSvrList, tParam)

	/*<<����H323�������� >>
	*��Ϣ���� sdk==>dispatch==>nvservice
	*tParam: H323���ò���
	*/
	MESSAGE(Ev_NV_BLL_SetH323PxyCfg_Cmd)
	BODY(nv::TNVH323PxyCfg, tParam)

	/*<<����H323����֪ͨ>>
	*��Ϣ���� nvservice==>dispatch==>sdk
	*tParam: H323���ò���
	*/
	MESSAGE(Ev_NV_BLL_SetH323PxyCfg_Ntf)
	BODY(nv::TNVH323PxyCfg, tParam)

	/*<<����H460�������� >>
	*��Ϣ���� sdk==>dispatch==>nvservice
	*tParam: H460���ò���
	*/
	MESSAGE(Ev_NV_BLL_SetH460Cfg_Cmd)
	BODY(nv::TNVH460PxyCfg, tParam)

	/*<<����H460����֪ͨ>>
	*��Ϣ���� nvservice==>dispatch==>sdk
	*tParam: H460���ò���
	*/
	MESSAGE(Ev_NV_BLL_SetH460Cfg_Ntf)
	BODY(nv::TNVH460PxyCfg, tParam)

	/*<<��ȡH460����������� >>
	*��Ϣ���� sdk==>dispatch==>nvservice
	*
	*/
	MESSAGE(Ev_NV_BLL_GetH460Cfg_Req)

	/*<<��ȡH460���������Ӧ>>
	*��Ϣ���� nvservice==>dispatch==>sdk
	*tParam: H460���ò���
	*/
	MESSAGE(Ev_NV_BLL_GetH460Cfg_Rsp)
	BODY(nv::TNVH460PxyCfg, tParam)

	/*<<ע��Sip�������������� >>
	*��Ϣ���� sdk==>dispatch==>nvservice
	*tParam: Sip���������ò���
	*/
	MESSAGE(Ev_NV_BLL_SetSipSvrCfg_Cmd)
	BODY(nv::TNVSipSrvCfg, tParam)

	/*<<ע��Sip����������֪ͨ>>
	*��Ϣ���� nvservice==>dispatch==>sdk
	*tParam: Sip���������ò���
	*/
	MESSAGE(Ev_NV_BLL_SetSipSvrCfg_Ntf)
	BODY(nv::TNVSipSrvCfg, tParam)

	/*<<�Զ�����ʱ�Ӽ������ >>
	*��Ϣ���� sdk==>dispatch==>nvservice
	*tStart: TRUE:��ʼ��⣬FALSE��ֹͣ
	*/
	MESSAGE(Ev_NV_BLL_AutoAudioDelayCheck_Cmd)
	BODY(nv::TBOOL32, tStart)

	/*<<��ȡ��Ƶ����ӿ����� >>
	*��Ϣ���� sdk==>dispatch==>nvservice
	*
	*/
	MESSAGE(Ev_NV_BLL_GetAudInPortListCfg_Req)

	/*<<��ȡ��Ƶ����ӿ���Ӧ>>
	*��Ϣ���� nvservice==>dispatch==>sdk
	*tParam: ��Ƶ����ӿڲ���
	*/
	MESSAGE(Ev_NV_BLL_GetAudInPortListCfg_Rsp)
	BODY(nv::TNVMtAudInPortList, tParam)

	/*<<���ú����������� >>
	*��Ϣ���� sdk==>dispatch==>nvservice
	*tRate: ��������
	*/
	MESSAGE(Ev_NV_BLL_SetCallBitRateCfg_Cmd)
	BODY(nv::TU32, tRate)

	/*<<��������֪ͨ>>
	*��Ϣ���� nvservice==>dispatch==>sdk
	*tRate: ��������
	*/
	MESSAGE(Ev_NV_BLL_SetCallBitRateCfg_Ntf)
	BODY(nv::TNVMtCallBitRate, tRate)

	/*<<��ȡ������������ >>
	*��Ϣ���� sdk==>dispatch==>nvservice
	*
	*/
	MESSAGE(Ev_NV_BLL_GetCallBitRateCfg_Req)

	/*<<��ȡ����������Ӧ>>
	*��Ϣ���� nvservice==>dispatch==>sdk
	*tRate: ��������
	*/
	MESSAGE(Ev_NV_BLL_GetCallBitRateCfg_Rsp)
	BODY(nv::TNVMtCallBitRate, tRate)

	/*<<��������ʱ�Ӽ��֪ͨ>>
	*��Ϣ���� nvservice==>dispatch==>sdk
	*tState: state(EmMtAudioDelayCheckState)�����״̬
	*tResult:��EmMtAudioDelayCheckStateΪemAudioDelayCheckedʱ����ֵ��Ч����ʾʱ��ֵ
	         ��EmMtAudioDelayCheckStateΪemAudioDelayFailedʱ����ֵ��Ч����ʾʧ�ܴ�����
	*/
	MESSAGE(Ev_NV_BLL_AutoAudioDelayCheck_Ntf)
	BODY(nv::TU32, tState)
	BODY(nv::TU32, tResult)

	/*<<��ȡ��������¼״̬���� >>
	*��Ϣ���� sdk==>dispatch==>nvservice
	*
	*/
	MESSAGE(Ev_NV_BLL_GetSvrStateList_Req)

	/*<<��ȡ��������¼״̬��Ӧ>>
	*��Ϣ���� nvservice==>dispatch==>sdk
	*tList: ��������¼״̬�б�
	*/
	MESSAGE(Ev_NV_BLL_GetSvrStateList_Rsp)
	BODY(nv::TNVMtSvrStateList, tList)

	/*<<����Э��ע����֪ͨ>>
	*��Ϣ���� nvservice==>dispatch==>sdk
	*tProtocol: nv::EmMtConfProtocol ����Э������
	*tRegFailReason: nv::EmMtRegFailedReason ע��ɹ���ʧ��ԭ��
	*/
	MESSAGE(Ev_NV_BLL_TerRegResult_Ntf)
	BODY(nv::TS32, tProtocol)
	BODY(nv::TS32, tRegFailReason)

	/*<<�ն�ע��CSU�������������� (GK) >>
	*��Ϣ���� sdk==>dispatch==>nvservice
	*tAddr:�ն�CSU������������Ϣ
	*/
	MESSAGE(Ev_NV_BLL_SetCSUCfg_Cmd)
	BODY(nv::TNVMtCSUAddr, tAddr)

	/*<<����CSU����֪ͨ>>
	*��Ϣ���� nvservice==>dispatch==>sdk
	*tAddr:�ն�CSU������������Ϣ
	*/
	MESSAGE(Ev_NV_BLL_SetCSUCfg_Ntf)
	BODY(nv::TNVMtCSUAddr, tAddr)

	/*<<��ѯSDI�ӿ���������>>
	*��Ϣ���� sdk==>dispatch==>nvservice
	*
	*/
	MESSAGE(Ev_NV_BLL_GetTerSdiInOut_Req)

	/*<<��ѯSDI�ӿ�������Ӧ>>
	*��Ϣ���� nvservice==>dispatch==>sdk
	*tType:  nv::EmMtSdiInOut  SDI�ӿ����� 
	*/
	MESSAGE(Ev_NV_BLL_GetTerSdiInOut_Rsp)
	BODY(nv::TS32, tType)

	/*<<��ѯ��˷�����״̬����>>
	*��Ϣ���� sdk==>dispatch==>nvservice
	*
	*/
	MESSAGE(Ev_NV_BLL_GetMicrophoneConnectStatus_Req)

	/*<<��ѯ��˷�����״̬��Ӧ>>
	*��Ϣ���� nvservice==>dispatch==>sdk
	*tStatus:  ȫ�������״̬��Ϣ
	*/
	MESSAGE(Ev_NV_BLL_GetMicrophoneConnectStatus_Rsp)
	BODY(nv::TNVMtAllMicStatus, tStatus)

	/*<<��˷�����״̬֪ͨ>>
	*��Ϣ���� nvservice==>dispatch==>sdk
	*tStatus:  ȫ�������״̬��Ϣ
	*/
	MESSAGE(Ev_NV_BLL_MicrophoneConnectStatus_Ntf)
	BODY(nv::TNVMtAllMicStatus, tStatus)

	/*<<��ȡ��һ·����Ƶ����˿�����>>
	*��Ϣ���� sdk==>dispatch==>nvservice
	*
	*/
	MESSAGE(Ev_NV_BLL_GetPri1stVidInPortCfg_Req)

	/*<<��ȡ��һ·����Ƶ����˿ڻ�Ӧ>>
	*��Ϣ���� nvservice==>dispatch==>sdk
	*tPort:  ������Ƶ����˿�
	*/
	MESSAGE(Ev_NV_BLL_GetPri1stVidInPortCfg_Rsp)
	BODY(nv::TNVMtHDVidInPort, tPort)

	/*<<��ȡ����Ƶ����˿�����>>
	*��Ϣ���� sdk==>dispatch==>nvservice
	*
	*/
	MESSAGE(Ev_NV_BLL_GetAssVidInPortCfg_Req)

	/*<<��ȡ����Ƶ����˿ڻ�Ӧ>>
	*��Ϣ���� nvservice==>dispatch==>sdk
	*tPort:  ������Ƶ����˿�
	*/
	MESSAGE(Ev_NV_BLL_GetAssVidInPortCfg_Rsp)
	BODY(nv::TNVMtHDVidInPort, tPort)

	/*<<��ȡ�ڶ�·������Ƶ����˿�����>>
	*��Ϣ���� sdk==>dispatch==>nvservice
	*
	*/
	MESSAGE(Ev_NV_BLL_GetPri2ndVidInPortCfg_Req)

	/*<<��ȡ�ڶ�·������Ƶ����˿ڻ�Ӧ>>
	*��Ϣ���� nvservice==>dispatch==>sdk
	*tPort:  ������Ƶ����˿�
	*/
	MESSAGE(Ev_NV_BLL_GetPri2ndVidInPortCfg_Rsp)
	BODY(nv::TNVMtHDVidInPort, tPort)

	/*<<������Ƶ����ӿ����� >>
	*��Ϣ���� sdk==>dispatch==>nvservice
	*tList: ��Ƶ����ӿڲ���
	*/
	MESSAGE(Ev_NV_BLL_SetAudInPortListCfg_Cmd)
	BODY(nv::TNVMtAudInPortList, tList)

	/*<<������Ƶ����ӿ�֪ͨ>>
	*��Ϣ���� nvservice==>dispatch==>sdk
	*tList: ��Ƶ����ӿڲ���
	*/
	MESSAGE(Ev_NV_BLL_SetAudInPortListCfg_Ntf)
	BODY(nv::TNVMtAudInPortList, tList)

	/*<<�����������֪ͨ�ն� >>
	*��Ϣ���� sdk==>dispatch==>nvservice
	*
	*/
	MESSAGE(Ev_NV_BLL_SetWizardResult_Cmd)

	/*<<֪ͨimix�ָ���������>>
	*��Ϣ����nvservice==>dispatch==>sdk
	*/
	MESSAGE(Ev_NV_BLL_ResetImixSys_Ntf)

	/*<<��ȡ�ն�GK�Ƿ�ע������>>
	*��Ϣ���� sdk==>dispatch==>nvservice
	*
	*/
	MESSAGE(Ev_NV_BLL_GetGKRegistRt_Req)

	/*<<��ȡ�ն�GK�Ƿ�ע���Ӧ>>
	*��Ϣ���� nvservice==>dispatch==>sdk
	*tIsRegist:  �Ƿ�ע��
	*/
	MESSAGE(Ev_NV_BLL_GetGKRegistRt_Rsp)
	BODY(nv::TBOOL32, tIsRegist)

	/*<<��ȡ�ն�Sip�Ƿ�ע������>>
	*��Ϣ���� sdk==>dispatch==>nvservice
	*
	*/
	MESSAGE(Ev_NV_BLL_GetSipRegistRt_Req)

	/*<<��ȡ�ն�Sip�Ƿ�ע���Ӧ>>
	*��Ϣ���� nvservice==>dispatch==>sdk
	*tIsRegist:  �Ƿ�ע��
	*/
	MESSAGE(Ev_NV_BLL_GetSipRegistRt_Rsp)
	BODY(nv::TBOOL32, tIsRegist)

	/*<<�����ն�֪ͨ>>
	*��Ϣ���� nvservice==>dispatch==>sdk
	*tIsReset:  �Ƿ�����
	*/
	MESSAGE(Ev_NV_BLL_RestTer_Nty)
	BODY(nv::TBOOL32, tIsReset)

	/*<<�ն�ң������������֪ͨ>>
	*��Ϣ���� nvservice==>dispatch==>sdk
	*tbVolUp:  TRUE: ����+ FALSE: ����-
	*/
	MESSAGE(Ev_NV_BLL_DeviceKeyVolume_Nty)
	BODY(nv::TBOOL32, tbVolUp)

	/*<<imix�Ƿ����ն�����>>
	*
	*/
	MESSAGE(Ev_NV_BLL_NVConnectTer_Req)

	/*<<imix�Ƿ����ն����ӻ�Ӧ>>
	*
	*/
	MESSAGE(Ev_NV_BLL_NVConnectTer_Rsp)
	BODY(nv::TBOOL32, tbIsConnect)

#if !defined(_MESSAGE_HELP_)
    EV_BLL_END(TERINTERFACE) = EVSEG_BLL_TERINTERFACE_END
};
#endif

#define Is_BLL_Terinterface_Msg(m) ((m) >= EV_BLL_BGN(TERINTERFACE) && (m) <= EV_BLL_END(TERINTERFACE))

#endif // _NVBLLTERINTERFACMSG_H_
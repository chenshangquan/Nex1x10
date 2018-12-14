/*******************************************************************************//**
*@file          nvapi_event_base.h
*@brief         ʵ��NVAPI BaseSdk ��UI(�۲���)�¼�֪ͨ�Ķ���
*
*@author        ruiyigen
*@version       5.0    
*@date          20150328
*@copyright     (c)1995-2015 Suzhou Keda Technology Co.,Ltd. All rights reserved
***********************************************************************************/
#ifndef _NVAPI_EVENT_BASE_H_
#define _NVAPI_EVENT_BASE_H_
/**@addtogroup event �¼�
*@{
*/

/**@addtogroup baseevent �����¼�
*@{
*/

#include "nvapi_event_def.h"


enum EmNvApiBaseEv
{
	EV_UI_BGN(NVAPI_BASE)  = EV_NVAPI_EVENT_BGN,

	/**
	@brief    �ն˿ͻ����˺���֤Ӧ���Ҷ�Ӧ��Ev_NV_NVCLogin_Rsp	
	
	BODY(nv::TNVUserReqResult, loginuser_rsp)

	*/
	Ev_NvApi_Base_NVCLogin_Rsp,

	/**	
	@brief    ����֪ͨ���Ҷ�Ӧ��OSP_DISCONNECT
	*/
	Ev_NvApi_Base_NVDisconnect_Ntf,

	/**	
	@brief    ����û���Ӧ,Ev_NV_NVCAddUser_Rsp
	
	BODY(nv::TNVMultiUserReqResult, adduser_rsp)

	*/
	Ev_NvApi_Base_NVCAddUser_Rsp,  
	
	/**	
	@brief����û�֪ͨ, Ev_NV_NVCAddUser_Ntf
	
	BODY(nv::TNVMultiUserFullInfo, adduser_ntf)

	*/
	Ev_NvApi_Base_NVCAddUser_Ntf,
	
	/**	
	@brief    �޸��û���Ӧ,Ev_NV_NVCMUser_Rsp
	
	BODY(nv::TNVMultiUserReqResult, muser_rsp)

	*/
	Ev_NvApi_Base_NVCMUser_Rsp,
	
	/**		
	@brief    �޸��û�֪ͨ,Ev_NV_NVCMUser_Ntf
	
	BODY(nv::TNVMultiUserFullInfo, muser_ntf)
	*/
	Ev_NvApi_Base_NVCMUser_Ntf,

	/**		
	@brief    ɾ���û���Ӧ,Ev_NV_NVCDUser_Rsp
	
	BODY(nv::TNVMultiUserReqResult, duser_rsp)
	*/
	Ev_NvApi_Base_NVCDUser_Rsp,

	/**		
	@brief    ɾ���û�֪ͨ,Ev_NV_NVCDUser_Ntf
	
	BODY(nv::TNVMultiUserFullInfo, duser_ntf)
	*/
	Ev_NvApi_Base_NVCDUser_Ntf,

	/**	
	@brief    ��ѯ�û���Ӧ,Ev_NV_NVCSUser_Rsp
	
	BODY(nv::TNVMultiUserFullInfo, duser_rsp)
	*/
	Ev_NvApi_Base_NVCSUser_Rsp,

	/**	
	@brief    ע����Ӧ,Ev_NvApi_Base_NVCLogOut_Ntf
	
	BODY(nv::TString, user_name)
	*/
	Ev_NvApi_Base_NVCLogOut_Ntf,

	/**	
	@brief    UIͬ��֪ͨ���Ҷ�Ӧ��Ev_Conf_UISynchronize_Ntf
	BODY(nv::TS32,       reason) //ö��ֵͳһʹ��nv::TS32�����䣬�ô�ʵ��Ϊnv::EmNvUISynchronizeReason
	*/

	Ev_NvApi_Base_UISynchronize_Ntf, 

	/**	
	@brief    ���ʹ�������ʱ֪ͨ(��Embed)���Ҷ�Ӧ��Ev_NV_BLL_CodecSleepFailReason_Ntf	
	
	BODY(nv::TS32, fail_reason) //ö��ֵͳһʹ��nv::TS32�����䣬�ô�ʵ��Ϊnv::EmSleepFailReason
	*/
	Ev_NvApi_Base_SleepFailReason_Ntf,

	/**	
	@brief    ���ʹ�������ʱ֪ͨ(��Embed)���Ҷ�Ӧ��Ev_NV_CodecSleepState_Ntf	
	
	BODY(nv::TBOOL32, is_sleep) is_sleep : TRUE��ʾ����˯��״̬��FALSE��ʾ���뻽��״̬
	*/
	Ev_NvApi_Base_SleepState_Ntf,

	/**	
	@brief    ���������֪ͨ����Ӧ��Ev_NV_CheckUpgradeResult_Ntf
	
	BODY(nv::TU32, errorcode) //������ NV_SUCCESS:�ɹ�
	                          //ERR_UPGRADE_CONNECT_SERVER_FAILED ���ӷ�����ʧ��
							  //ERR_UPGRADE_UNKNOWN δ֪����
							  //...
	*/
	Ev_NvApi_Base_CheckUpgradeResult_Ntf,

	/**	
	@brief    ���°汾��Ϣ֪ͨ���Ҷ�Ӧ��Ev_NV_UpgradeVersionInfo_Ntf
	
	BODY(TNVDevUpgrade, ver_info)
	*/
	Ev_NvApi_Base_UpgradeVersionInfo_Ntf,

	/**	
	@brief    ���°汾��Ϣ֪ͨ���Ҷ�Ӧ��Ev_NV_BLL_AutoLoadUpgradeFileOk_Ntf
	
	BODY(TNVUpgradeVersionInfoList, ver_info)
	*/
	Ev_NvApi_Base_AutoLoadUpgradeFileOk_Ntf,
	/**	
	@brief    �ļ�����״̬֪ͨ���Ҷ�Ӧ��Ev_NV_UpgradeFileDownloadInfo_Ntf	
	
	BODY( TU8, info )	//���ؽ�����Ϣ
	*/
	Ev_NvApi_Base_UpgradeFileDownloadInfo_Ntf,

	/**
	@brief    �ļ��������֪ͨ���Ҷ�Ӧ��Ev_NV_UpgradeFileDownloadOk_Ntf
	*/
	Ev_NvApi_Base_UpgradeFileDownloadOk_Ntf,
	
	/**
	@brief    �����쳣ʱ ������������ �����Ƿ�װ֪ͨ
	*/	
	Ev_NvApi_Base_UpgradeExceptionPackageIsReady_Ntf,

	/**
	@brief    �����������֪ͨ���Ҷ�Ӧ��Ev_NV_BLL_UpgradeDisconnectServer_Ntf
	*/
	Ev_NvApi_Base_UpgradeDisconnectServer_Ntf,

	/**	
	@brief    ����ϵͳ�ļ�״̬֪ͨ���Ҷ�Ӧ��Ev_NV_UpgradeSysFileUpdateStatus_Ntf
	
	 BODY(nv::TS32, upgrade_notify)   //nv::EmUpgradeNotify
	*/
	Ev_NvApi_Base_UpgradeSysFileUpdateStatus_Ntf,

	/**	
	@brief    �����ܰ�������Щ�Ӱ����Ҷ�Ӧ��Ev_NV_BLL_UpgradePackageContent_Ntf
	
	 BODY(nv::TNVUpgradePackageContent, upgrade_package) 
	*/
	Ev_NvApi_Base_UpgradePackageContent_Ntf,
	
		/**	
	@brief    ����ϵͳ�ļ�״̬֪ͨ���Ҷ�Ӧ��Ev_NV_UpgradeSysFileUpdateStatus_Ntf
	*/
	Ev_NvApi_Base_UpgradeFinishGoingToReboot_Ntf,

	/**	
	@brief    �汾��Ϣ֪ͨ������Ͷ�����Ҷ�Ӧ��Ev_NvApi_Base_UpdateSystem2QuickShare_Ntf
	
	 BODY(nv::TNVDevUpgrade, tDevup)
	*/
    Ev_NvApi_Base_UpdateSystem2QuickShare_Ntf,
    
	/**
	@brief  ����ϵͳ����״̬����ӦEv_MT_BLL_SetSysUpgradeRt_Ntf
	
	BODY(nv::TBOOL32, bSysUpgrade)

	*/	
	Ev_NvApi_Base_SetSysUpgradeRt_Ntf,
	
	/**	
	@brief    ���U����������Ӧ
	
	BODY(nv::TBOOL32, file_found)
    BODY(nv::TString, file_path)
    BODY(nv::TNVUpgradeVersionInfoList, upgrade_info)
	*/
	Ev_NvApi_Base_UsbUpgradeFileCheck_Rsp,

	/**	
	@brief    ����״̬֪ͨ(��Embed)���Ҷ�Ӧ��Ev_NV_BLL_SleepCountDown_Ntf
	
	BODY(nv::TU16, count_down)	 ����ʣ��ʱ��	

	*/
	Ev_NvApi_Base_SleepCountDown_Ntf,

	/**	
	@brief    ������Ӧ(��Embed)
	
	BODY(nv::TBOOL32, is_sucess)
	BODY(nv::TS32, fail_reason) //ö��ֵͳһʹ��nv::TS32�����䣬�ô�ʵ��Ϊnv::EmSleepFailReason
	@endverbatim
	*/
	Ev_NvApi_Base_CodecDspSleep_Rsp,
	
		/**		
	@brief    ϵͳ��Ϣ��ʾ
	
	BODY(nv::TNVSysHint, sys_hint)

	*/
	Ev_NvApi_SysHint_Ntf,
	
	/**		
	@brief   ��ʼ�ն˷��񣬶�ӦEv_NV_BLL_SrvStartResult_Ntf
	
	BODY(nv::TBOOL32, SrvStartRlt)
	BODY(nv::TNVSrvKeepLiveInfo, SrvKeepLiveInfo)
	*/		
	Ev_NvApi_Base_SrvStartResult_Ntf,
	
	/**		
	@brief   ֹͣ�ն˷��񣬶�ӦEv_NV_BLL_SrvEndtResult_Ntf
	
	BODY(nv::TBOOL32, SrvEndRlt)
	BODY(nv::TU32, Nvaid)
	*/		
	Ev_NvApi_Base_SrvEndtResult_Ntf,
	
	/**
	@brief    ��־����֪ͨ
	
	BODY(nv::TBOOL32, bEnableFileLog)

	*/
	Ev_NvApi_Base_LogStatusCfg_Ntf,

	/**
	@brief    ��ȡ��־������Ӧ
	
	BODY(nv::TBOOL32, bEnableFileLog)
	*/
	Ev_NvApi_Base_GetLogStatusCfg_Rsp,
	
	/**		
	@brief    �ն� IP����֪ͨ
	
	BODY(nv::TString, ip)
	*/
	Ev_NvApi_Base_TerIpCfg_Ntf,

	/**		
	@brief    �ն� IP������Ӧ
	
	BODY(nv::TString, ip)
	*/
	Ev_NvApi_Base_GetTerIpCfg_Rsp,
	/**		
	@brief    Imix IP����֪ͨ
	
	BODY(nv::TString, ip)
	*/
	Ev_NvApi_Base_ImixIpCfg_Ntf,

	/**		
	@brief    ��ȡImix IP������Ӧ
	
	BODY(nv::TString, ip)
	*/
	Ev_NvApi_Base_GetImixIpCfg_Rsp,

	/**		
	@brief    ��־������ IP����֪ͨ
	
	BODY(nv::TString, ip)
	*/
	Ev_NvApi_Base_LogSerIpCfg_Ntf,

	/**		
	@brief    ��ȡ��־������ IP������Ӧ
	
	BODY(nv::TString, ip)
	*/
	Ev_NvApi_Base_GetLogSerIpCfg_Rsp,

	/**		
	@brief    �ʼ������� IP����֪ͨ
	
	BODY(nv::TString, ip)
	*/
	Ev_NvApi_Base_EmailSerIpCfg_Ntf,

	/**		
	@brief    ��ȡ�ʼ������� IP������Ӧ
	
	BODY(nv::TString, ip)
	*/
	Ev_NvApi_Base_GetEmailSerIpCfg_Rsp,

	/**		
	@brief    ��̨��������֪ͨ
	
	BODY(nv::TBOOL32, tb)
	*/
	Ev_NvApi_Base_SetBackstageUpgradeCfg_Ntf,

	/**		
	@brief    ��ȡ��̨����������Ӧ
	
	BODY(nv::TBOOL32, tb)
	*/
	Ev_NvApi_Base_GetBackstageUpgradeCfg_Rsp,
	
	/**		
	@brief   �����ն�״̬�ϱ�
	
	BODY(NV::TBOOL32, is_login)

	*/
	Ev_NvApi_Base_MTCLogin_Ntf,
	
	/**		
	@brief   ��ǰ�ĺ���״̬�ϱ�
	
	BODY(nv::TS32, callsate)	//ö��ֵͳһʹ��nv::TS32�����䣬�ô�ʵ��Ϊnv::EmNvCallState

	*/
	Ev_NvApi_Base_CallLinkState_Ntf,
	
	/**		
	@brief   ��ǰ��˫��״̬�ϱ�
	
	BODY(NV::TBOOL32, is_senddual)
	BODY(NV::TS32, vid_lab) //ö��ֵͳһʹ��nv::TS32�����䣬�ô�ʵ��Ϊnv::EmNvVidLabel

	*/
	Ev_NvApi_Base_AssSndSream_Status_Ntf,
	
	/**		
	@brief   ��ǰ��˫��״̬�ϱ�
	
	BODY(NV::TBOOL32, is_rcvdual)

	*/
	Ev_NvApi_Base_AssRcvSream_Status_Ntf,
	
	/**	
	@brief    ע����Ӧ,Ev_NvApi_Base_SetSysDataTimeResult_Rsp
	
	BODY(nv::TU32, result)
	BODY(nv::TNVTime, tmttime )
	*/
	Ev_NvApi_Base_SetSysDataTimeResult_Rsp,

	/**
	@brief    ʱ������֪ͨ
	
	BODY(nv::TS32, timezoon)

	*/
	Ev_NvApi_Base_SetTimeZoneCfg_Ntf,
	
	/**
	@brief    ��ȡʱ����Ӧ
	
	BODY(nv::TS32, timezoon)
	*/
	Ev_NvApi_Base_GetTimeZoneCfg_Rsp,

	/**
	@brief    �л�������Ӧ
	
	BODY(nv::TS32, pic) //ö��ֵͳһʹ��nv::TS32�����䣬�ô�ʵ��Ϊnv::EmNvImixVidSrcType
	BODY(nv::TS32, reason) //ö��ֵͳһʹ��nv::TS32�����䣬�ô�ʵ��Ϊnv::EmNvViewReason
	*/
	Ev_NvApi_Base_ViewPic_Ntf,

	/**
	@brief    Imix�������͵�ǰ�����UI
	
	BODY(nv::TS32, pic) //ö��ֵͳһʹ��nv::TS32�����䣬�ô�ʵ��Ϊnv::EmNvImixVidSrcType
	*/
	Ev_NvApi_Base_ViewPicPosToUI_Ntf,
	
	/**
	@brief    ��ȡ������Ӧ
	
	BODY(nv::TS32, pic) //ö��ֵͳһʹ��nv::TS32�����䣬�ô�ʵ��Ϊnv::EmNvImixVidSrcType
	*/
	Ev_NvApi_Base_GetPic_Rsp,

	/**
	@brief    ���ͼ��������Ӧ
	
	BODY(nv::TString, tStr) //�������
	*/
	Ev_NvApi_Base_SendPCName_Ntf,
	
	/**
	@brief    ���ʹ�����Ϣ��Ӧ
	
	BODY(nv::TNVInputEvents, tInput) //������Ϣ
	*/
	Ev_NvApi_Base_SendInputEvent_Ntf,

	/**
	@brief    ��������Ͷ���б�
	
	BODY(nv::TNVLoginInfos, tLogins) //�б���Ϣ
	*/
	Ev_NvApi_Base_SendQuickShareList_Ntf,

	/**
	@brief    ���ʹ�����Ϣ������Ͷ��
	
	BODY(nv::TNVInputEvents, tInput) //������Ϣ
	*/
	Ev_NvApi_Base_SendInputEventToQuickShare_Ntf,

	/**
	@brief   ����Ͷ�����ͱ���rtp��ַ�Ͷ˿���Ӧ
	*/
	Ev_NvApi_Base_SendQuickShareSendAddr_Ntf,
	
	/**
	@brief   ����Ͷ��������Դ��Ӧ
	BODY(nv::TS32, reason) //ö��ֵͳһʹ��nv::TS32�����䣬�ô�ʵ��Ϊnv::EmNvViewReason
	*/
	Ev_NvApi_Base_QuickShareViewPic_Ntf,	

	/**
	@brief   ����Ͷ������ֹͣͶ����Ӧ
	BODY(nv::TS32, pic) //ö��ֵͳһʹ��nv::TS32�����䣬�ô�ʵ��Ϊnv::EmNvImixVidSrcType
	BODY(nv::TS32, reason) //ö��ֵͳһʹ��nv::TS32�����䣬�ô�ʵ��Ϊnv::EmNvViewReason
	*/
	Ev_NvApi_Base_QuickShareViewPicStop_Ntf,
	
	/**
	@brief    Imix �������ͱ���rtp��ַ�Ͷ˿ڸ�����Ͷ��
	
	BODY(nv::TNVRtpRtcpPair, tAddr) //��Ƶ��ַ
	BODY(nv::TNVRtpRtcpPair, tAddr) //��Ƶ��ַ
	*/
	Ev_NvApi_Base_SendImixRcvAddrToQuickShare_Ntf,

	/**
	@brief    Imix ����������Ͷ�����͹ؼ�֡������
	
	*/
	Ev_NvApi_Base_SendIFrameRequestToQuickShare_Ntf,

	/**
	@brief    Imix ����������Ͷ��ֹͣ��������
	
	*/
	Ev_NvApi_Base_StopTransferCodeStream_Ntf,
	
	/**
	@brief    ������ʾ������֪ͨ
	
	BODY(nv::TNVScreenParamList, screen)

	*/
	Ev_NvApi_Base_SetScreenCfg_Ntf,

	/**
	@brief    ��ȡ��ʾ������֪ͨ
	
	BODY(nv::TNVScreenParamList, screen)

	*/
	Ev_NvApi_Base_GetScreenCfg_Rsp,

	/**
	@brief    �ն˰汾��Ϣ֪ͨ
	
	BODY(nv::TNVTerminalInfo, terinfo)

	*/
	Ev_NvApi_Base_SetTerlInfoRt_Ntf,

	/**
	@brief    ��ȡ�ն˰汾��Ϣ֪ͨ
	
	BODY(nv::TNVTerminalInfo, terinfo)

	*/
	Ev_NvApi_Base_GetTerlInfoRt_Rsp,

	/**
	@brief    ������ʾ������֪ͨ
	
	BODY(nv::TU32, screen)

	*/
	Ev_NvApi_Base_SetScreenNumCfg_Ntf,

	/**
	@brief    ��ȡ��ʾ������֪ͨ
	
	BODY(nv::TU32, screen)

	*/
	Ev_NvApi_Base_GetScreenNumCfg_Rsp,

	/**
	@brief    ���ù���֪ͨ
	
	BODY(nv::TBOOL32, tbCfg)

	*/
	Ev_NvApi_Base_SetIsSharing_Ntf,

	/***
	@brief    ��ȡ����֪ͨ

	BODY(nv::TBOOL32, tbCfg)

	*/
	Ev_NvApi_Base_GetIsSharing_Rsp,

	/**
	@brief    ������ʾ������֪ͨ
	
	BODY(nv::TBOOL32, result)
	BODY(nv::TS32, Screen_type)//ö��ֵͳһʹ��nv::TS32�����䣬�ô�ʵ��Ϊnv::EmNvScreenType
	BODY(nv::TU32, brightness)

	*/
	Ev_NvApi_Base_SetTvBrightness_Rsp,

	/**
	@brief    ������ʾ���Աȶ�֪ͨ
	
	BODY(nv::TBOOL32, result)
	BODY(nv::TS32, Screen_type)//ö��ֵͳһʹ��nv::TS32�����䣬�ô�ʵ��Ϊnv::EmNvScreenType
	BODY(nv::TU32, contrast)

	*/
	Ev_NvApi_Base_SetTvContraste_Rsp,

	/**
	@brief    ������ʾ�����Ͷ�֪ͨ
	
	BODY(nv::TBOOL32, result)
	BODY(nv::TS32, Screen_type)//ö��ֵͳһʹ��nv::TS32�����䣬�ô�ʵ��Ϊnv::EmNvScreenType
	BODY(nv::TU32, saturation)

	*/
	Ev_NvApi_Base_SetTvSaturation_Rsp,
	/**
	@brief    ������ʾ��������֪ͨ
	
	BODY(nv::TBOOL32, result)
	BODY(nv::TS32, Screen_type)//ö��ֵͳһʹ��nv::TS32�����䣬�ô�ʵ��Ϊnv::EmNvScreenType
	BODY(nv::TU32, clarity)

	*/
	Ev_NvApi_Base_SetTvClarity_Rsp,

	/**
	@brief    ������ʾ��ɫ��֪ͨ
	
	BODY(nv::TBOOL32, result)
	BODY(nv::TS32, Screen_type)//ö��ֵͳһʹ��nv::TS32�����䣬�ô�ʵ��Ϊnv::EmNvScreenType
	BODY(nv::TS32, color_temp)//ö��ֵͳһʹ��nv::TS32�����䣬�ô�ʵ��Ϊnv::EmNvScreenColorTemperature

	*/
	Ev_NvApi_Base_SetTvColortemp_Rsp,

	/**
	@brief    ������ʾ����ʾ����֪ͨ
	
	BODY(nv::TBOOL32, result)
	BODY(nv::TS32, Screen_type)//ö��ֵͳһʹ��nv::TS32�����䣬�ô�ʵ��Ϊnv::EmNvScreenType
	BODY(nv::TS32, displayratio)//ö��ֵͳһʹ��nv::TS32�����䣬�ô�ʵ��Ϊnv::EmNvTvDisplayRatio

	*/
	Ev_NvApi_Base_SetTvDisplayratio_Rsp,

	/**
	@brief    ��ƵԴ�ֱ����ϱ�
	
	BODY(nv::TNVVidInPortResInfoList, src_info_list)

	*/
	Ev_NvApi_Base_NvmpVidSrcStatus_Ntf,

	/**
	@brief    ��ƵԴ�ֱ����ϱ�
	
	BODY(nv::TNVVidInPortResInfoList, src_info_list)

	*/
	Ev_NvApi_Base_NvmpVidSrcStatus_Rsp,

	/**
	@brief    ��ǰ���������ϱ�
	
	BODY(nv::TS32, pic) //ö��ֵͳһʹ��nv::TS32�����䣬�ô�ʵ��Ϊnv::EmNvImixVidSrcType

	*/
	Ev_NvApi_Base_PicStatus_Ntf,

	/**
	@brief    ��ȡ��Ƶ���������Ӧ
	
	BODY(nv::TU32, vol)

	*/
	Ev_NvApi_Base_CodecGetAudOutVol_Rsp,

	/**
	@brief    ��ȡ��Ƶ���������Ӧ
	
	BODY(nv::TU32, vol)

	*/
	Ev_NvApi_Base_CodecAudOutVol_Ntf,

	/**
	@brief    ��ȡ����״̬������Ӧ
	
	BODY(nv::TBOOL32, is_quiet)

	*/
	Ev_NvApi_Base_CodecQuiet_Rsp,

	/**
	@brief    ����״̬֪ͨ
	
	BODY(nv::TBOOL32, is_quiet)

	*/
	Ev_NvApi_Base_CodecQuiet_Ntf,

	/***
	@brief    ��ƵԴ�ź�֪ͨ

	BODY(nv::TNVImixVidSrcSignalList, src_list)

	*/
	Ev_NvApi_Base_ImixVidSrcSignalRt_Ntf,

	/***
	@brief    ��ƵԴ�ź�֪ͨ

	BODY(nv::TNVImixVidSrcSignalList, src_list)

	*/
	Ev_NvApi_Base_GetImixVidSrcSignalRt_Rsp,

	/***
	@brief    ����״̬�仯֪ͨ

	BODY(nv::TBOOL32, status)

	*/
	Ev_NvApi_Base_SysUpgradeStatRt_Ntf,

	/***
	@brief    �ػ���Ӧ

	BODY(nv::TS32, reason) //ö��ֵͳһʹ��nv::TS32�����䣬�ô�ʵ��Ϊnv::EmNvPowerTurnOffReason

	*/
	Ev_NvApi_Base_PowerTurnOff_Ntf,

	/**
	@brief    ����ȫ��֪ͨ
	
	BODY(nv::TBOOL32, is_full)

	*/
	Ev_NvApi_Base_SetFullScreen_Ntf,

	/**
	@brief    ��ȡȫ��������Ӧ
	
	BODY(nv::TBOOL32, is_full)

	*/
	Ev_NvApi_Base_GetFullScreen_Rsp,
	
	/***
	@brief    ���������Ӧ

	BODY(nv::TU32, snapshot_state) //��������״̬ 0���ɹ� 1��ʧ��
	BODY(nv::TString, snapshot_name) //����ȫ·������
	BODY(nv::TS32, codec_id) //ö��ֵͳһʹ��nv::TS32�����䣬�ô�ʵ��Ϊnv::EmNvCodecComponentIndex

	*/
	Ev_NvApi_Base_CodecSnapshot_Rsp,

	/***
	@brief    �ػ�����

	*/
	Ev_NvApi_Base_PowerTurnOff_Rsp,

	/***
	@brief    ��Ƶ�����źŻظ�
	BODY(nv::TNVAudInPowerList, aud_list) //��Ƶ�ź��б�
	*/
	Ev_NvApi_Base_CodecGetAllAudInPower_Ntf,
	/**		
	@brief   ��ǰ���з�ʽ�ϱ�
	
	BODY(nv::TBOOL32, answercallmode)	//ö��ֵͳһʹ��nv::TBOOL32

	*/
	Ev_NvApi_Base_AnSwerCallMode_Ntf,

/**		
	@brief    ��ȡhdmi����
	
	BODY(nv::TBOOL32, tb)
	*/
	Ev_NvApi_Base_GetHdmiSwitchCfg_Rsp,

	/**		
	@brief    ��ȡhdmi����
	
	BODY(nv::TBOOL32, tb)
	*/
	Ev_NvApi_Base_GetHdmiSwitchCfg_Ntf,

	/**	
	@brief    ��ȡ�ն�ʱ����Ӧ
	
	BODY(nv::TU32, result)
	BODY(nv::TNVTime, tmttime )
	*/
	Ev_NvApi_Base_GetMtSysDataTime_Rsp,

	/**	
	@brief    �����ն˵�ǰ����ʱ����Ϣ��Ӧ
	
	BODY(nv::TU32, result)
	BODY(nv::TNVTime, tmttime )
	*/
	Ev_NvApi_Base_SetMtSysDataTimeResult_Rsp,

	/**	
	@brief    �����ն˵�ǰ����ʱ��֪ͨ
	BODY(nv::TNVTime, tmttime )
	*/
	Ev_NvApi_Base_SetMtSysDataTime_Ntf,

	/**	
	@brief    �����ն�ʱ������֪ͨ
	BODY(nv::TNVCfgMtSystemTime, tmttime )
	*/
	Ev_NvApi_Base_SetMtSysTimeCfg_Ntf,

	/**	
	@brief     �����ն�ʱ������֪ͨ
	BODY(nv::TNVCfgMtSystemTime, tmttime )
	*/
	Ev_NvApi_Base_GetMtSysTimeCfg_Rsp,
	/**	
	@brief     ������ʾ1080P��ɫ��ͼ	
	*/
	Ev_NvApi_Base_SetBluePic_Ntf,
	/**	
	@brief     ������ʾOsd	
	*/
	Ev_NvApi_Base_SetOsd_Ntf,
	/**	
	@brief     ����IP	
	*/
	Ev_NvApi_Base_SetIp_Ntf,
	/**	BODY(nv::TNVNetUsedInfo, tUsedInfo )
	@brief     Ping������	
	*/
	Ev_NvApi_Base_Ping_Req,
	/**	
	@brief     Ping������ظ�	
	*/
	Ev_NvApi_Base_Ping_Nty,

	/**	
	@brief     ���÷�1080�ֱ���ʱ��ʾ���Իظ�
	BODY(nv::TS32, mode )
	*/
	Ev_NvApi_Base_SetVidResResizeModeCfg_Ntf,

	/**	
	@brief     ��ѯ��1080�ֱ���ʱ��ʾ���Իظ�
	BODY(nv::TS32, mode )
	*/
	Ev_NvApi_Base_GetVidResResizeModeCfg_Rsp,
	/**	
	@brief     �ظ���������֪ͨ	
	*/
	Ev_NvApi_Base_SetDefault_Nty,
	/**	
	@brief     ��������֪ͨ	
	*/
	Ev_NvApi_Base_NVMfTest_Ntf,

	/**	
	@brief     ��ȡ��ǰ����ʱ����Ϣ֪ͨ	
	BODY(nv::TU32, result)
	BODY(nv::TNVTime, tmttime )
	*/
	Ev_NvApi_Base_GetSysDataTime_Rsp,

	/**	
	@brief    �����°汾��Ϣ֪ͨ���Ҷ�Ӧ��Ev_NV_UpgradeNoVersion_Ntf	
	
	*/
	Ev_NvApi_Base_NoVersion_Ntf,

	/**	
	@brief    ���°汾��Ϣ֪ͨ���Ҷ�Ӧ��Ev_NV_UpgradeVersionInfo_Ntf
	
	BODY(TNVDevUpgrade, ver_info)
	*/
	Ev_NvApi_Base_AutoUpgradeVersion_Ntf,
	
	/**
	@brief     �����ն�˫��Դ��ʾλ�ûظ�
	BODY(nv::TBOOL32, bleft )
	*/
	Ev_NvApi_Base_SetIsMtDualLeftCfg_Ntf,

	/**
	@brief     �����ն�˫��Դ��ʾλ�ûظ�
	BODY(nv::TBOOL32, bleft )
	*/
	Ev_NvApi_Base_GetIsMtDualLeftCfg_Rsp,

	/**
	@brief     ��ǰ�ն�����Ƶ��ʾ����֪ͨ
	BODY(nv::TS32, pic)
	*/
	Ev_NvApi_Base_SetMtPic_Ntf,

	/**
	@brief     ��ȡ�ն�����Ƶ��ʾ����ظ�
	BODY(nv::TS32, pic)
	*/
	Ev_NvApi_Base_GetMtPic_Rsp,

	/***
	@brief   ��������Ͷ���汾
	BODY(nv::TString, quickshare_version) 

	*/
	Ev_NvApi_Base_SendQuickShareVersion_Ntf,

	/***
	@brief   ����Ͷ���汾��������
	BODY(nv::TU32�� quickshare_downloadprogress) 

	*/
	Ev_NvApi_Base_QuickShareDownloadProgress_Ntf,

	/***
	@brief   ��������Ͷ���������
	BODY(nv::TBOOL32, is_upgradesucess) 

	*/
	Ev_NvApi_Base_QuickShareUpgradeResult_Ntf,
	/***
	@brief     ����״̬����ظ�
	BODY(nv:TBOOL32,  bsleep)
	*/
	Ev_NvApi_Base_GetCodecDspSleep_Rsp,

	/***
	@brief     ���ò����豸����ʾ�����ظ�
	BODY(nv::TS32, zoon)//ö��ֵͳһʹ��nv::TS32�����䣬�ô�ʵ��Ϊnv::EmNvZoomMode
	*/
	Ev_NvApi_Base_CodecSetPlayZoomMode_Ntf,

	/***
	@brief     ��ȡ�����豸����ʾ�����ظ�
	BODY(nv::TS32, zoon)//ö��ֵͳһʹ��nv::TS32�����䣬�ô�ʵ��Ϊnv::EmNvZoomMode
	*/
	Ev_NvApi_Base_CodecGetPlayZoomMode_Rsp,

	/**
	@brief   ����Ͷ��������Դ��Ӧ
	BODY(nv::TS32, reason) //ö��ֵͳһʹ��nv::TS32�����䣬�ô�ʵ��Ϊnv::EmNvViewReason
	*/
	Ev_NvApi_Base_QuickShareViewPre_Ntf,
	
	/**
	@brief   �ն˳���ȫ�������ɹ�֪ͨ
	*/
	Ev_NvApi_Base_HDMtStartSucess_Ntf,

	/**
	@brief   ��ѯ�ն�������Ӧ
	BODY(nv::TNVTerminalName, name)
	*/
	Ev_NvApi_Base_GetTerminalName_Rsp,

	/**
	@brief   �ն�����֪ͨ
	BODY(nv::TNVTerminalName, name)
	*/
	Ev_NvApi_Base_SetTerminalName_Ntf,

	/**
	@brief   ��ѯ�ն˳����Ƿ�ȫ�������ɹ�����
	BODY(nv:TBOOL32,  bsuc)
	*/
	Ev_NvApi_Base_InquireHDMtStartSucess_Rsp,

	/**
	@brief   ��ǰ���ڻ��ѣ����������	
	*/
	Ev_NvApi_Base_NotSleep_Nty,
	/**
	@brief   ��ǰ���ڴ�������������	
	*/
	Ev_NvApi_Base_NotWake_Nty,

	/**
	@brief   ��ƵԴ����1080	
	BODY(nv::TS32, port)//ö��ֵͳһʹ��nv::TS32�����䣬�ô�ʵ��Ϊnv::EmNvImixVidSrcType
	*/
	Ev_NvApi_Base_CodecVidResIsNot1080_Nty,

	/**
	@brief   Сͼ��֪ͨ
	BODY(nv::TNVMiniVidInfo, info)
	*/
	Ev_NvApi_Base_SetMiniVidInfoRt_Ntf,

	/**
	@brief   Сͼ��֪ͨ
	BODY(nv::TNVMiniVidInfo, info)
	*/
	Ev_NvApi_Base_GetMiniVidInfoRt_Rsp,

	/**
	@brief   �汾��Ϣ֪ͨ
	BODY(nv::TNVImixVerInfo, info)
	*/
	Ev_NvApi_Base_GetImixVerInfoRt_Rsp,

	/**
	@brief   �����ն�NAT��Ӧ
	*/
	Ev_NvApi_Base_SetTerNatIpCfg_Rsp,

	/**
	@brief   ��Ƶ����״̬��ѯ�ظ�
	BODY(nv::TU32, Freeze)
	*/
	Ev_NvApi_Base_CodecGetVidFreezePrm_Rsp,

	/**
	@brief   �򿪹رյ��ӻ����ź�֪ͨ
	BODY(nv::TS32, Screen_type)//ö��ֵͳһʹ��nv::TS32�����䣬�ô�ʵ��Ϊnv::EmNvScreenType
	BODY(nv::BOOL32, open)
	*/
	Ev_NvApi_Base_SetTvSignal_Ntf,

	/**
	@brief   IMIX�汾��ѯ�ظ�
	BODY(nv::TString, tMode)
	*/
	Ev_NvApi_Base_ImixMode_Rsp,
	/**
	@brief	֪ͨUI��ǰpc���״̬
	BODY(nv::BOOL32, NtState)
	*/
	Ev_NvApi_Base_NotifyImixNTState_Nty,

	/**
	@brief	����ѡ��״̬֪ͨ
	BODY(nv::TBOOL32, bstart) TRUE����ʼ�л����� FALSE�����������л�
	*/
	Ev_NvApi_Base_ViewPicState_Nty,

	/**
	@brief   �����ն��Զ�����֪ͨ
	*/
	Ev_NvApi_Base_SetTerAutoSleep_Nty,

	/**
	@brief   ��ѯ�ն��Զ�������Ӧ
	*/
	Ev_NvApi_Base_GetTerAutoSleep_Rsp,

	/**
	@brief	�˳���עԭ��֪ͨ
	BODY(nv::TS32, reason) //ö��ֵͳһʹ��nv::TS32�����䣬�ô�ʵ��Ϊnv::EmNvLeaveDrawReason	
	*/
	Ev_NvApi_Base_LeaveDrawReason_Nty,

	/**
	@brief	˫������ʧ��ԭ��֪ͨ
	BODY(nv::TS32, reason) //ö��ֵͳһʹ��nv::TS32�����䣬�ô�ʵ��Ϊnv::EmNvHintCode	
	*/
	Ev_NvApi_Base_SendDualFailReason_Nty,
	
	/**
	@brief	�������쳣֪ͨ
	*/
	Ev_NvApi_Base_CodecError_Nty,

	/**
	@brief	imix�յ�qk����֪ͨ�����Ϣ֪ͨ
	*/
	Ev_NvApi_Base_ImixSendToQKHeartBeat_Nty,

	/**
	@brief	imix֪ͨ��������Ͷ������ppt״̬
	BODY(nv::TBOOL32, tIsView)0������ppt��1����ppt
	*/
	Ev_NvApi_Base_QKIsViewPPT_Nty,

	/**
	@brief	imix��������Ͷ��ppt��ҳ����
	BODY(nv::TS32, tPageTurn)�ô�ʵ��Ϊnv::EmNvPPTPageTurning
	*/
	Ev_NvApi_Base_SendPPTPageTurn_Cmd,

	/**
	@brief	imix��Ӧ�����Ƿ�ʼ�ػ�����ʱ
	*BODY(nv::TBOOL32, tIsStart)
	*BODY(nv::TS32, tReason)�ô�ʵ��Ϊnv::EmNvAutoShutdownFailReason
	*/
	Ev_NvApi_Base_StartShutdownCount_Rsp,

	/**
	@brief	imixÿ��֪ͨ����ػ�����ʱ
	*BODY(nv::TBOOL32, tIsCount)�Ƿ��������ʱ
	*BODY(nv::TS32, tReason)�ô�ʵ��Ϊnv::EmNvAutoShutdownFailReason
	*/
	Ev_NvApi_Base_ShutdownCount_Nty,

	/**
	@brief	imix��Ӧqk�汾��Ϣ
	*BODY(nv::TString, version)Ͷ�����汾
	*/
	Ev_NvApi_Base_GetQkVersion_Rsp,

	/**
	@brief	imix֪ͨ����һ�����������Ӱ�
	*BODY(nv::TNVAllUpgradePackageContent, upgrade_package)
	*/
	Ev_NvApi_Base_AllUpgradePackageContent_Ntf,

	/**
	@brief	imix֪ͨ���濪ʼ����·����
	*BODY(nv::TNVAllUpgradePackageContent, upgrade_package)
	*/
	Ev_NvApi_Base_StartUpgradeRouter_Ntf,

	/**
	@brief	��ȡ�ն�ip��Ӧ
	*BODY(nv::TNVString, tTerip)
	*/
	Ev_NvApi_Base_GetTerIp_Rsp,

	/**
	@brief	�ܿ��ؿ���100s���ٴΰ�ѹʱ֪ͨ
	*
	*/
	Ev_NvApi_Base_SwbRepeatTurnOn_Nty,

	/**
	@brief   nv�汾��Ϣ��Ӧ
	BODY(nv::TString, imix_ver)
	*/
	Ev_NvApi_Base_GetNvVerInfo_Rsp,

	/**
	@brief   �ն�Ӳ����Ϣ��Ӧ
	BODY(nv::TNVHWInfo, HWInfo)
	*/
	Ev_NvApi_Base_GetTerHWInfo_Nty,

	/**
	@brief   �ն˲��ű�������֪ͨ
	BODY(nv::TNVMtLocalSoundPaly, tPlayInfo)
	*/
	Ev_NvApi_Base_LocalSoundPlay_Nty,

	/**
	@brief   �ն���Ƶ������֪ͨ
	BODY(nv::TNVMtAudioPower, tPower)
	*/
	Ev_NvApi_Base_TerAudioOutPowerTest_Nty,

	/**
	@brief   �ն���Ƶ�������֪ͨ
	BODY(nv::TNVMtAudioPower, tPower)
	*/
	Ev_NvApi_Base_TerAudioInPowerTest_Nty,

	/**
	@brief   �ն���Ƶ����ӿ�״̬��Ӧ
	BODY(nv::TNVMtMutiAudInState, tState)
	*/
	Ev_NvApi_Base_TerAudioInputState_Rsp,

	/**
	@brief   ��ȡ��¼APS����Ҫ�Ĳ�������
	BODY(nv::TNVApsLoginParam, tParam)
	*/
	Ev_NvApi_Base_GetLoginApsParamCfg_Rsp,

	/**
	@brief   ��ȡ����Э���������û�Ӧ
	BODY(nv::TS32, emType) �˴�ʵ��Ϊnv::EmMtConfProtocol,Э������
	*/
	Ev_NvApi_Base_GetCallProtocolCfg_Rsp,

	/**
	@brief   ��ȡXAPList���û�Ӧ
	BODY(nv::TNVMtXAPSvrList, tSrvList)
	*/
	Ev_NvApi_Base_GetXAPListCfg_Rsp,

	/**
	@brief   ��ȡH323�������û�Ӧ
	BODY(nv::TNVH323PxyCfg, tCfg)
	*/
	Ev_NvApi_Base_GetH323PxyCfg_Rsp,

	/**
	@brief   ��ȡ�ֶ����õ�gk��ַ��Ӧ
	BODY(nv::TNVMtCSUAddr, tCfg)
	*/
	Ev_NvApi_Base_GetGKCfg_Rsp,

	/**
	@brief   ��ȡ�ֶ�����Sip�����������û�Ӧ
	BODY(nv::TNVSipSrvCfg, tCfg)
	*/
	Ev_NvApi_Base_GetManuSipSvrCfg_Rsp,

	/**
	@brief   ��ȡ�Ƿ������½ƽ̨�����Ӧ
	BODY(nv::TBOOL32, tLogin)
	*/
	Ev_NvApi_Base_GetLoginPlatformSrvCfg_Rsp,

	/**
	@brief   ��ȡ�Ƿ�ǿ������H323Э�����ͻ�Ӧ
	BODY(nv::TBOOL32, tFoeceSet)
	*/
	Ev_NvApi_Base_GetForceH323StackCfg_Rsp,

	/**
	@brief   ��ѯ�˺���ϸ��Ϣ��Ӧ
	BODY(nv::TNVMtAccountManager, tInfo)
	*/
	Ev_NvApi_Base_GetAccountInfo_Rsp,

	/**
	@brief   �Ƿ������½ƽ̨����֪ͨ
	BODY(nv::TBOOL32, tLogin)
	*/
	Ev_NvApi_Base_SetLoginPlatformSrvCfg_Ntf,

	/**
	@brief   APS��½�����Ӧ
	BODY(nv::TNVMtApsLoginErrcode, tLogin)
	BODY(nv::TU32, tIP)
	*/
	Ev_NvApi_Base_ApsLoginResult_Ntf,

	/**
	@brief   ǿ������H323Э������(��׼/�Ǳ�)֪ͨ
	BODY(nv::TBOOL32, tForce)
	*/
	Ev_NvApi_Base_ForceSet323StackCfg_Ntf,

	/**
	@brief   ����XAPList����֪ͨ
	BODY(nv::TNVMtXAPSvrList, tParam)
	*/
	Ev_NvApi_Base_SetXAPListCfg_Ntf,

	/**
	@brief   ����H323��������֪ͨ
	BODY(nv::TNVH323PxyCfg, tParam)
	*/
	Ev_NvApi_Base_SetH323PxyCfg_Ntf,

	/**
	@brief   ����H460����֪ͨ
	BODY(nv::TNVH460PxyCfg, tParam)
	*/
	Ev_NvApi_Base_SetH460Cfg_Ntf,

	/**
	@brief   ��ȡH460���������Ӧ
	BODY(nv::TNVH460PxyCfg, tParam)
	*/
	Ev_NvApi_Base_GetH460Cfg_Rsp,

	/**
	@brief   ע��Sip����������֪ͨ
	BODY(nv::TNVSipSrvCfg, tParam)
	*/
	Ev_NvApi_Base_SetSipSvrCfg_Ntf,

	/**
	@brief   ��ȡ��Ƶ����ӿ���Ӧ
	BODY(nv::TNVMtAudInPortList, tParam)
	*/
	Ev_NvApi_Base_GetAudInPortListCfg_Rsp,

	/**
	@brief   ��������֪ͨ
	BODY(nv::TNVMtCallBitRate, tRate)
	*/
	Ev_NvApi_Base_SetCallBitRateCfg_Ntf,

	/**
	@brief   ��ȡ����������Ӧ
	BODY(nv::TNVMtCallBitRate, tRate)
	*/
	Ev_NvApi_Base_GetCallBitRateCfg_Rsp,

	/**
	@brief   ��������ʱ�Ӽ��֪ͨ
	BODY(nv::TU32, tState)    state(EmMtAudioDelayCheckState)�����״̬
	BODY(nv::TU32, tResult)   ��EmMtAudioDelayCheckStateΪemAudioDelayCheckedʱ����ֵ��Ч����ʾʱ��ֵ
	                          ��EmMtAudioDelayCheckStateΪemAudioDelayFailedʱ����ֵ��Ч����ʾʧ�ܴ�����
	*/
	Ev_NvApi_Base_AutoAudioDelayCheck_Ntf,

	/**
	@brief   ��ȡ��������¼״̬��Ӧ
	BODY(nv::TNVMtSvrStateList, tList)
	*/
	Ev_NvApi_Base_GetSvrStateList_Rsp,

	/*
	@brief   ����Э��ע����֪ͨ
	BODY(nv::TS32, tProtocol)            nv::EmMtConfProtocol ����Э������
	BODY(nv::TS32, tRegFailReason)       nv::EmMtRegFailedReason ע��ɹ���ʧ��ԭ��
	*/
	Ev_NvApi_Base_TerRegResult_Ntf,

	/**
	@brief   ����CSU����֪ͨ
	BODY(nv::TNVMtCSUAddr, tAddr)
	*/
	Ev_NvApi_Base_SetCSUCfg_Ntf,

	/**
	@brief   ��ѯSDI�ӿ�������Ӧ
	BODY(nv::TS32, tType)
	*/
	Ev_NvApi_Base_GetTerSdiInOut_Rsp,

	/**
	@brief   ��ѯ��˷�����״̬��Ӧ
	BODY(nv::TNVMtAllMicStatus, tStatus)
	*/
	Ev_NvApi_Base_GetMicrophoneConnectStatus_Rsp,

	/**
	@brief   ��˷�����״̬֪ͨ
	BODY(nv::TNVMtAllMicStatus, tStatus)
	*/
	Ev_NvApi_Base_MicrophoneConnectStatus_Ntf,

	/**
	@brief   ��ȡ��һ·����Ƶ����˿ڻ�Ӧ
	BODY(nv::TNVMtHDVidInPort, tPort)
	*/
	Ev_NvApi_Base_GetPri1stVidInPortCfg_Rsp,

	/**
	@brief   ��ȡ����Ƶ����˿ڻ�Ӧ
	BODY(nv::TNVMtHDVidInPort, tPort)
	*/
	Ev_NvApi_Base_GetAssVidInPortCfg_Rsp,

	/**
	@brief   ��ȡ�ڶ�·������Ƶ����˿ڻ�Ӧ
	BODY(nv::TNVMtHDVidInPort, tPort)
	*/
	Ev_NvApi_Base_GetPri2ndVidInPortCfg_Rsp,

	/**
	@brief   ��ȡ�ڶ�·������Ƶ����˿ڻ�Ӧ
	BODY(nv::TNVMtAudInPortList, tList)
	*/
	Ev_NvApi_Base_SetAudInPortListCfg_Ntf,

	/**
	@brief	�ܿ�����ϵͳ����ʱ����С��3��֪ͨ
	*
	*/
	Ev_NvApi_Base_SwbKey_Nty,

	/**
	@brief	imix��Ӧqk�ն˱���
	*BODY(nv::TString, strTerName)�ն˰汾��Ϣ
	*/
	Ev_NvApi_Base_QkGetTerName_Rsp,

	/**
	@brief	pad�汾�������Ӧ
	*BODY(nv::TString, strTerName)pad�汾��
	*/
	Ev_NvApi_Base_GetPadVersion_Rsp,

	/**
	@brief	֪ͨimix�ָ���������
	*/
	Ev_NvApi_Base_ResetImixSys_Ntf,

	/**
	@brief	�ն��Ƿ�ע��GK��Ӧ
	*BODY(nv::TBOOL32, tIsRegist)�Ƿ�ע��
	*/
	Ev_NvApi_Base_GetGKRegistRt_Rsp,

	/**
	@brief	�ն��Ƿ�ע��Sip��Ӧ
	*BODY(nv::TBOOL32, tIsRegist)�Ƿ�ע��
	*/
	Ev_NvApi_Base_GetSipRegistRt_Rsp,

	/**
	@brief	����ftp֪ͨ
	*BODY(nv::TBOOL32, tIsOpen)�Ƿ��ftp
	*/
	Ev_NvApi_Base_OpenFtp_Nty,

	/**
	@brief	��ȡftp״̬��Ӧ
	*BODY(nv::TBOOL32, tIsOpen)�Ƿ��ftp
	*/
	Ev_NvApi_Base_GetFtpState_Rsp,

	/**
	@brief	֪ͨͶ������Ҫ����Э��
	*/
	Ev_NvApi_Base_QKNeedCodeConsult_Ntf,

	/**
	@brief	Ͷ�����������
	*BODY(nv::TQKCodeParam, tParam)�������
	*/
	Ev_NvApi_Base_QKCodeParam_Cmd,

	/**
	@brief	Ͷ��������ֱ���
	*BODY(nv::TS32, tRes)����ֱ���
	*/
	Ev_NvApi_Base_QKCodeRes_Cmd,

	/**
	@brief	Ͷ������������
	*BODY(nv::TU32, tFrame)����֡��
	*/
	Ev_NvApi_Base_QKCodeFrameRate_Cmd,

	/**
	@brief	Ͷ������������
	*BODY(nv::TU32, tRate)��������
	*/
	Ev_NvApi_Base_QKCodeBitRate_Cmd,

	/**
	@brief	֪ͨ�����Ƿ���Ҫ����data�ļ���
	*BODY(nv::TBOOL32, tbNeed)TRUE: ����Ҫ���� FALSE:��Ҫ����
	*/
	Ev_NvApi_Base_NeedClearDataFolder_Cmd,

	/**
	@brief	�����ն�֪ͨ
	*BODY(nv::TBOOL32, tIsReset)TRUE: �ն����ã� FALSE:�ն�δ����
	*/
	Ev_NvApi_Base_RestTer_Nty,

	/**
	@brief	�ն�ң������������֪ͨ
	*BODY(nv::TBOOL32, tbVolUp)TRUE: ����+ FALSE: ����-
	*/
	Ev_NvApi_Base_DeviceKeyVolume_Nty,

	/**
	@brief	imix�����ն˻�Ӧ
	*BODY(nv::TBOOL32, tbLogin)
	*/
	Ev_NvApi_Base_NVConnectTer_Rsp,

	/**
	@brief	֪ͨ�������ù��Ž��
	*BODY(nv::TBOOL32, tbResult)
	*/
	Ev_NvApi_Base_SetAmplifierStatus_Ntf,

	/**
	@brief	֪ͨ�������ñ��ػ��Խ��
	*BODY(nv::TBOOL32, tbResult)
	*/
	Ev_NvApi_Base_SetImixLocalEcho_Ntf,

	/**
	@brief	imix��JDƽ̨�汾�Ƿ�һ�»�Ӧ
	*BODY(nv::TBOOL32, tbSame)
	*/
	Ev_NvApi_Base_NVVerIsSameAsJDServer_Rsp,

	/**
	@brief	��JDƽ̨���ذ汾����֪ͨ
	*BODY(nv::TU32, tdwSchedule)
	*/
	Ev_NvApi_Base_NVDownloadFromJDServer_Nty,

	/**
	@brief	��JDƽ̨���ذ汾���֪ͨ
	*BODY(nv::TBOOL32, tbLogin)
	*/
	Ev_NvApi_Base_NVDownloadResultFromJD_Nty,

	EV_UI_END(NVAPI_BASE) = EVSEG_NVAPI_BASE_END
	
};

#define Is_NvApiBase_Msg(m) ((m) >= EV_UI_BGN(NVAPI_BASE) && (m) <= EV_UI_END(NVAPI_BASE))

/**@}*/

/**@}*/
#endif // _NVAPI_EVENT_BASE_H_

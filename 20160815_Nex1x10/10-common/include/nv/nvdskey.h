/*=============================================================================================
ģ����   : ����ͷ�ļ�
�ļ���   : nvdskey.h
����     : ���������������ʱ�������key����
����     : qianling
��Ȩ     : <Copyright(C) 2003-2015 Suzhou Keda Technology Co., Ltd. All rights reserved.>
----------------------------------------------------------------------------------------------
����     : 2015/05/05
�汾     : 5.0
�޸���   : ruiyigen
�߶���   :
�޸�˵�� : �������ݺ�����ʱ���ݵĶ�������
=============================================================================================*/
#ifndef _NVDSKEY_H_
#define _NVDSKEY_H_
#include "kdvtype.h"

//1.�޸��ϵ�Key���ᵼ��nvconfigmsg.h�е���Ϣ���仯����ע��

//2.Key�����ݺ��壺
// _Cfg_ ����  �������ݣ��ᱣ��
// _Rt_  ����  ����ʱ���ݣ����ᱣ��

//3.Key��Ӧ�Ľṹ�壬������д (value:XXX) configservice�ű�����ʱ����ȡXXX�ŵ�msgbody��

//���ӣ�                                       //����ʹ��Ӣ��:
//Qos����           emNv_Cfg_IPQoS             //(value: TNVIPQoS)
//����ʱ��������¼״̬ emNv_Rt_SvrLoginStatus  //(value: TNvSvrStateTable)

//4.����/**/����ע�ͽű��ݲ�ʶ�� 



//��ʼ��������޸�
#define BGN_KEY

/*************************�������������Key��ʼ********************/									      								           
#define	emNv_Cfg_Port                     "emNv_Cfg_Port"                          //����TCP/UDP��ʼ�˿�������Ϣ (value: TNvPortCfg)
#define	emNv_Cfg_SysCtrlDefSrvInfo	      "emNv_Cfg_SysCtrlDefSrvInfo"             //Ĭ������ӳ��� (value: TNVMutiTServiceDefInfo)
#define	emNv_Cfg_SysCtrlDefSrvNum	      "emNv_Cfg_SysCtrlDefSrvNum"              //Ĭ��ӳ�����ģ����� (value: TU32)
#define	emNv_Cfg_SUS                      "emNv_Cfg_SUS"                           //(value: TNVSUSAddr)  //������������ַ //��ҵ��UI���ã� ��ҵ��XAP��½�ɹ����ȡ
#define	emNv_Cfg_TerIp                    "emNv_Cfg_TerIp"                         //����ʱX500�ն�ip (value: TString)
#define	emNv_Cfg_ImixIp                   "emNv_Cfg_ImixIp"                        //����IMIX ip (value: TNVNetUsedInfo)
#define emNv_Cfg_LogSerIp                 "emNv_Cfg_LogSerIp"                      //������־������ ip (value: TString)
#define emNv_Cfg_EmailSerIp               "emNv_Cfg_EmailSerIp"                    //�����ʼ������� ip (value: TString)
#define	emNv_Cfg_Log                      "emNv_Cfg_Log"                           //������־���� (value: TBOOL32)
#define	emNv_Cfg_TimeZone                 "emNv_Cfg_TimeZone"                      //����ʱ�� (value: TS32)
#define	emNv_Cfg_Screen                   "emNv_Cfg_Screen"                      //������ʾ������ (value: TNVScreenParamList)
#define	emNv_Cfg_ScreenNum                "emNv_Cfg_ScreenNum"                      //������ʾ������ (value: TU32)
#define	emNv_Cfg_BackstageUpgrade         "emNv_Cfg_BackstageUpgrade"              //���ú�̨���� (value: TBOOL32)
#define	emNv_Cfg_QuickShareVersionInfo    "emNv_Cfg_QuickShareVersionInfo"              //����Ͷ���汾��Ϣ (value: TNVDevUpgrade)
#define emNv_Cfg_ImixVersionInfo          "emNv_Cfg_NextVisionVersionInfo"              //Imix�汾��Ϣ (value: TNVDevUpgrade)

#define	emNv_Cfg_IsUpgradeFileDownloadFinish   "emNv_Cfg_IsUpgradeFileDownloadFinish"       //�ļ��Ƿ�������� (value: TBOOL32)
#define	emNv_Cfg_IsUpgradeFinish               "emNv_Cfg_IsUpgradeFinish"                   //�Ƿ�������� (value: TBOOL32)
#define	emNv_Cfg_PreCheckUpgradeInfo           "emNv_Cfg_PreCheckUpgradeInfo"               //�ϴμ�������Ϣ (value: TNVUpgradeClientInfo)
#define emNv_Cfg_CodecAudOutVol           "emNv_Cfg_CodecAudOutVol"                //�������(value: nv::TU32)
#define emNv_Cfg_CodecQuiet               "emNv_Cfg_CodecQuiet"                    //����(value: nv::TBOOL32)
#define emNv_Cfg_IsFullScreen             "emNv_Cfg_IsFullScreen"                  //�Ƿ�ȫ����ʾ(value: nv::TBOOL32)
#define emNv_Cfg_VidResResizeMode         "emNv_Cfg_VidResResizeMode"               //��1080�ֱ���ʱ���Ų���(value: nv::TS32)
#define emNv_Cfg_IsMtDualLeft             "emNv_Cfg_IsMtDualLeft"               //�ն����Դ��ʾλ��(value: nv::TBOOL32)
#define emNv_Cfg_IsUserCorrect            "emNv_Cfg_IsUserCorrect"               //userĿ¼�ռ��㹻��(value: nv::TBOOL32)
#define	emNv_Cfg_TerPwd                    "emNv_Cfg_TerPwd"                         //����ʱ�ն����� (value: TString)
#define emNv_Cfg_ReStartImix              "emNv_Cfg_ReStartImix"                  //��������imix(value: nv::TBOOL32)
#define emNv_Cfg_IsOpenAmplifier           "emNv_Cfg_IsOpenAmplifier"               //�Ƿ�������(value:TBOOL32)
#define emNv_Cfg_IsLocalEcho               "emNv_Cfg_IsLocalEcho"                   //imix�ұ����Ƿ񱾵ػ���(value:TBOOL32)

/*************************�������ʱ������Key��ʼ********************/
#define	emNv_Rt_SysCtrlSrvInfo		      "emNv_Rt_SysCtrlSrvInfo"                 //����ʱӳ��� (value: TNVMutiTServiceInfoRtData)
#define	emNv_Rt_SysCtrlSrvNum		      "emNv_Rt_SysCtrlSrvNum"                  //����ʱӳ�����ģ����� (value: TU32)
#define	emNv_Rt_TerlInfo                  "emNv_Rt_TerlInfo"                       //(value: TNVTerminalInfo)
#define	emNv_Rt_SysUpgrade                "emNv_Rt_SysUpgrade"                     //ϵͳ����״̬ (value: TBOOL32)
#define	emNv_Rt_CallState                 "emNv_Rt_CallState"                     //����״̬ (value: TS32)
#define	emNv_Rt_IsSleep                   "emNv_Rt_IsSleep"                       //����״̬ (value: TBOOL32)
#define	emNv_Rt_IsSendDual                "emNv_Rt_IsSendDual"                    //�Ƿ���˫�� (value: TBOOL32)
#define	emNv_Rt_IsRcvDual                 "emNv_Rt_IsRcvDual"                     //�Ƿ����˫�� (value: TBOOL32)
#define	emNv_Rt_IsLoginMt                 "emNv_Rt_IsLoginMt"                     //�Ƿ����x500�ն� (value: TBOOL32)
#define	emNv_Rt_CodecStatistic            "emNv_Rt_CodecStatistic"                 //�����ͳ����Ϣ(value:TNVCodecStatistic)
#define	emNv_Rt_IsMute                    "emNv_Rt_IsMute"                       //�Ƿ����� (value: TBOOL32)
#define emNv_Rt_QuickShareLoginInfo       "emNv_Rt_QuickShareLoginInfo"            //����Ͷ��������Ϣ (value:TNVLoginInfos)
#define emNv_Rt_ImixVidSrcSignal          "emNv_Rt_ImixVidSrcSignal"               //imix��ƵԴ�ź� (value:TNVImixVidSrcSignalList)
#define emNv_Rt_IsQuite                   "emNv_Rt_IsQuite"                        //��ǰ�Ƿ���(value: TBOOL32)
#define emNv_Rt_IsPowerTurnOff            "emNv_Rt_IsPowerTurnOff"                  //��ǰ�Ƿ����ڹػ�(value: TBOOL32)
#define emNv_Rt_IsSharing                 "emNv_Rt_IsSharing"                      //�Ƿ��� (value: TBOOL32)
#define emNv_Rt_ImixVidSrcStatus          "emNv_Rt_ImixVidSrcStatus"               //��ƵԴ��Ϣ (value:TNVVidInPortResInfoList)
#define emNv_Rt_NetUsedInfo               "emNv_Rt_NetUsedInfo"                    //��ǰ����ͨѶ������IP��ϸ��Ϣ��value��TNVNetUsedInfo
#define emNv_Rt_IsLocalSharing            "emNv_Rt_IsLocalSharing"                 //�Ƿ��� (value: TBOOL32)
#define emNv_Rt_IsPowerUpgrade            "emNv_Rt_IsPowerUpgrade"                 //�Ƿ����� (value: TBOOL32)
#define emNv_Rt_IsCheckResult             "emNv_Rt_IsCheckResult"                  //�����½��(value: TS32)
#define emNv_Rt_IsCheckTpad               "emNv_Rt_IsCheckTpad"                    //Tpad������(value:TNVDevUpgrade )
#define emNv_Rt_IsOpenFtp                 "emNv_Rt_IsOpenFtp"                      //ftp����״̬(value:TBOOL32 )
#define emNv_Rt_FtpLoginInfo              "emNv_Rt_FtpLoginInfo"                   //����ģ��ʹ��ftp��Ϣ(value:TNVFtpLoginInfos )
#define	emNv_Rt_PlayZoomMode              "emNv_Rt_PlayZoomMode"                     //�����豸����ʾ����(value: TS32)
#define	emNv_Rt_MiniVidInfo               "emNv_Rt_MiniVidInfo"                     //Сͼ�����(value: TNVMiniVidInfo)
#define	emNv_Rt_ImixVerInfo               "emNv_Rt_ImixVerInfo"                     //imix�汾��Ϣ(value: TNVImixVerInfo)
#define	emNv_Rt_MtInfo                    "emNv_Rt_MtInfo"                          //MT��Ϣ(value: TNVMtInfo)
#define	emNv_Rt_AppUpgrade                "emNv_Rt_AppUpgrade"                     //Ӧ������״̬ (value: TBOOL32)
#define	emNv_Rt_QkUpgrade                 "emNv_Rt_QkUpgrade"                     //Ͷ��������״̬ (value: TBOOL32)
#define	emNv_Rt_IsToolbarLogin            "emNv_Rt_IsToolbarLogin"                 //toolbar����״̬ (value: TBOOL32)
#define	emNv_Rt_PadIsDown                 "emNv_Rt_PadIsDown"                     //pad�����ļ��Ƿ����������� (value: TBOOL32)
#define emNv_Rt_PadLoginInfo              "emNv_Rt_PadLoginInfo"                  //pad��¼��Ϣ(value:TNVPadLoginInfos)
#define emNv_Rt_RouterIsDown              "emNv_Rt_RouterIsDown"                  //·���������ļ��Ƿ�����������(value: TBOOL32)
#define emNv_Rt_TerminalName              "emNv_Rt_TerminalName"                  //�ն˱���(value:TNVTerminalName)
#define emNv_Rt_ChangeLocalEcho           "emNv_Rt_ChangeLocalEcho"               //�Ƿ�ӻ�������
#define emNv_Rt_ImixSerialNum             "emNv_Rt_ImixSerialNum"                 //imix���к�

/*------------------------ƽ̨�������----------------------------*/
#define emNv_Rt_NvSusInfo                 "emNv_Rt_NvSusInfo"                     //sus��������Ϣ(value:TNVSUSAddr)
#define emNv_Rt_NvImixAllVerInfo          "emNv_Rt_NvImixAllVerInfo"              //��ǰimix��������İ汾��Ϣ(value:TNVImixAllVerInfo)
/*================= �ֽ��ߣ�����Ϊ��Ʒר��Key ====================*/

/********************Ӳ�ն˲�Ʒ����������Key��ʼ********************/
#define	emHD_Cfg_EthnetCfg                "emHD_Cfg_EthnetCfg"                    //��̫����Ϣ(value:TNVEthnetCfg)
#define	emHD_Cfg_LastDisplay              "emHD_Cfg_LastDisplay"                  //��ͼ����ʾ����(value: TNVLastDisplay )
#define	emHD_Cfg_HdmiSwitch               "emHD_Cfg_HdmiSwitch"                  //����HDMI���أ���������(value: TBOOL32 )

/********************Ӳ�ն˲�Ʒ����ʱ������Key��ʼ********************/
#define	emHD_Rt_AppRunInfo		          "emHD_Rt_AppRunInfo"                    //Ӳ�ն�App����״̬ (value: TNVMutiTServiceInfoRtData)
#define	emHD_Rt_IsWifi					  "emHD_Rt_IsWifi"                        //Ӳ���Ƿ���wifiģ��(value: TBOOL32)
#define emHD_Rt_AutoUpgrade				  "emHD_Rt_AutoUpgrade"		              //Ӳ�ն��Զ�������value: TBOOL32)
#define	emHD_Rt_IsMfgTest		          "emHD_Rt_IsMfgTest"                     //�Ƿ��ȡ��e2prom�е��������Ա�־λ(value: TBOOL32)
#define	emHD_Rt_NetCaping                 "emHD_Rt_NetCaping"                     //�Ƿ�����ץ��(value:TBOOL32)
#define emHD_Rt_BrdInfo					  "emHD_Rt_BrdInfo"						  //������Ϣ(value:TNVBrdInfo)
#define	emHD_Rt_UsbStatus                 "emMt_Rt_UsbStatus"                     //USB�ӿ�״̬(value:TNVUsbStatus)
#define	emHD_Rt_SnapExporting             "emHD_Rt_SnapExporting"                 //�Ƿ����ڵ�������(value:TBOOL32)
#define emHD_Rt_EthnetCurIp               "emHD_Rt_EthnetCurIp"                   //��̫����������Ϣ��value:TU32��
#define	emHD_Rt_Is1080PVer 		          "emHD_Rt_Is1080PVer"                     //�Ƿ���1080P�汾(value: TBOOL32)
#define	emHD_Rt_IsOpenMiniVid 		      "emHD_Rt_IsOpenMiniVid"                     //�Ƿ��Сͼ��(value: TBOOL32)

/********************����Ͷ����Ʒ����������Key��ʼ********************/
#define emQK_Cfg_VersionInfo                   "emQK_Cfg_VersionInfo"                       //����Ͷ���汾��Ϣ(value: TString)
#define	emQK_Cfg_IsUpgradeFileDownloadFinish   "emQK_Cfg_IsUpgradeFileDownloadFinish"       //�ļ��Ƿ�������� (value: TBOOL32)
#define	emQK_Cfg_IsUpgradeFinish               "emQK_Cfg_IsUpgradeFinish"                   //�Ƿ�������� (value: TBOOL32)

/********************����Ͷ����Ʒ����ʱ������Key��ʼ********************/

//////���������е�debug���õ�key
/*
   ��Щdebug��key, ��Щ�����ͨ�õ�debug��key,  ��Щkey�� x500����ʽkey, ��windows��debug key
*/






#define END_KEY//End Of emNvDSKey
//������������޸�

#endif //_NVDSKEY_H_

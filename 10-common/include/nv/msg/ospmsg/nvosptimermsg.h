#ifndef _NVOSPTIMERMSG_H_
#define _NVOSPTIMERMSG_H_

#include "kdvtype.h"
#include "nvospmsgid.h"

//OSP�Ķ�ʱ����Ϣͳһ�ڴ˶���
enum EmNvOspMsgTimer
{
	Ev_Nv_OspTimer_Start = EVSEG_NVOSPMSG_TIMER_BGN,

	/* ϵͳ���ƶ�ʱ�� */
	Ev_Nv_SysCtrl_Timer_KeepAlive,      ///< ��ʱɨ�������ϵͳ�Ƿ���Ķ�ʱ��

	Ev_Nv_Timer_KeepAlive,				///< ÿ��ģ�鶨ʱɨ���ϱ��Լ��Ǵ���

	Ev_Nv_Timer_OperationCount,        ///< �����жϴ����õĶ�ʱ��
	Ev_Nv_Timer_ConnectTer,            ///< ���ڶ�ʱ����x500�ն˶�ʱ��
	Ev_Nv_Timer_RegUpdateSer,          ///<����ע��������������ʱ��

	Ev_Nv_Timer_UpgradeFileDownload,   ///<���ڶ�ʱ���������ļ���ʱ��
	Ev_Nv_Timer_CheckQuickShareUpdate,	//<���ڶ�ʱ�������Ͷ����������
	Ev_Nv_Timer_AutoShutDownCount,      //<���ڶ�ʱ�ػ�����ʱ��ʱ��>
	Ev_Nv_Timer_AllUpgradeState,        //���ڼ��һ��������״̬
	//kdvquickshare���
	Ev_Nv_Timer_QuickShareConnectImix, /*< ���ڶ�ʱ����imix�ն˶�ʱ��*/
	Ev_Nv_Timer_FlashControl,		   /*���ڷ������ƹ�1s��˸����*/ 
	Ev_Nv_Timer_QuickShareSendPcName,  /*���ڷ���������PC���ָ�Imix*/ 
	Ev_Nv_Timer_MtDualVidSrc,   //�����ն�˫�����
	Ev_Nv_Timer_MtDualVidSrcSignal,   //�����ն�˫������Ƿ���Դ
	Ev_Nv_Timer_GetTerminalIp,  /*���ڻ�ȡ�ն��豸��Ϣ*/
	Ev_Nv_Timer_WakeUpProtect,  /*���ѱ���*/
	Ev_Nv_Timer_SleepProtect,  /*��������*/
	Ev_Nv_Timer_GetMtVidSrcResWaiting,  /*��ȡ�ն�Դ�ֱ��ʵȴ�ʱ��x300��Ҫ*/
	Ev_Nv_Timer_GetSendDualState, /*����˫�������ͨ����ѯ˫��״̬���ж�*/
	Ev_Nv_Timer_QuickShareHeatToPc, /*���ڶ�ʱ����������PC���*/
	Ev_Nv_Timer_QuickShareChecKWifiState, /*�����ж��Ƿ�wifi���ڼ���״̬*/
	Ev_Nv_Timer_QuickShareFlashChecKWifiState, /*�����ж��Ƿ�wifi���ڼ���״̬*/
	Ev_Nv_Timer_QuickShareUsbChecKWifiState, /*�����ж��Ƿ�wifi���ڼ���״̬*/
	Ev_Nv_Timer_CodecErrorViewPic, //����������������л�
	//Ev_Nv_Timer_QuickShareHeartToImix, /*���ڶ�ʱ����������Imix*/
	//serviceconf���
	Ev_Nv_Timer_WhiteBoard,        //Զ�̰װ嶨ʱ������5s����˫��ʱ���л�˫������
	Ev_Nv_Timer_ChanceTvQuite,//ȡ�����ӻ�������ʱ��
	Ev_Nv_Timer_ChangeEchoOrDual,        //���ն�Դ���������Ժ�˫��Դ���Ķ�ʱ��
	Ev_Nv_Timer_CloseHDMI0ToRecDule,     //����˫������imix��������ӻ������Ķ�ʱ��
	Ev_Nv_Timer_SetMulConfPip,     //������ʱ�������ն��Զ��໭��ϳɶ�ʱ��

	Ev_Nv_Timer_RcvDualTimer,       //����˫����ʱ��
	Ev_Nv_Timer_X700ChangeLocalEcho,       //x700�����ʱ�л��ԵĶ�ʱ��
	Ev_Nv_Timer_QKConnectImixFail, /*< ��ʱ���Ͷ���������ն��Ƿ�ʧ��*/
};

#endif
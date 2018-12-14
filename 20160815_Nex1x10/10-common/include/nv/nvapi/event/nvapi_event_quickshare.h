/*******************************************************************************//**
*@file          nvapi_event_quickshare.h
*@brief         ʵ��NVAPI QuickShareSdk ��UI(�۲���)�¼�֪ͨ�Ķ���
*
*@author        youjiaxing
*@version       1.0    
*@date          20180612
*@copyright     (c)1995-2015 Suzhou Keda Technology Co.,Ltd. All rights reserved
***********************************************************************************/
#ifndef _NVAPI_EVENT_QUICKSHARE_H_
#define _NVAPI_EVENT_QUICKSHARE_H_
/**@addtogroup event �¼�
*@{
*/

/**@addtogroup baseevent �����¼�
*@{
*/

#include "nvapi_event_def.h"


enum EmNvApiQuickShareEv
{
	EV_UI_BGN(NVAPI_QUICKSHARE)  = EVSEG_NVAPI_QUICKSHARE_BGN,

	/**
	@brief    �ն��յ���Ϣ�󣬽�����Ϣ�������ͨ��HID���͸�����Ͷ��
	
	MainBuf(#TNVQKUsbInput_Api)
	@verbatim
	{
	    "achValue": ""
	}
	@endverbatim

	*/
	Ev_NvApi_Qk_UsbEvent_Nty,

	/**
	@brief    ֪ͨ����Ͷ�����汾

	MainBuf(#TNVQKUsbInput_Api)
	@verbatim
	{
		"achValue": ""
	}
	@endverbatim

	*/
	Ev_NvApi_Qk_VerSion_Ntf,

	/**
	@brief    ֪ͨ�ն˴�wps

	*/
	Ev_NvApi_Qk_RequstOpenWps_Cmd,

	/**
	@brief    Wps����Ƿ�ɹ�

	MainBuf(#BOOL32)
	@verbatim
	{
		"bSuc": TRUE:��Գɹ���FALSE:���ʧ��
	}
	@endverbatim

	*/
	Ev_NvApi_Qk_WifiConnectState_Ntf,

	/**
	@brief    Ͷ������¼��Ϣ

	MainBuf(#TNVQKVidSrcSignal_Api)
	@verbatim
	{
		"dwIndex": 0 Ͷ�������
		"bIsHasSrc": TRUE:��Դ FALSE:��Դ
		"achVidName":"" ����Ͷ��pc name
	}
	@endverbatim

	*/
	Ev_NvApi_Qk_Login_Ntf,

	/**
	@brief    Ͷ������ƵԴ��Ϣ

	MainBuf(#TNVQKVidSrcInfo_Api)
	MainBuf(#u32)
	@verbatim
	{
		#TNVQKVidSrcInfo_Api
		{
			"dwVideoWidth":  0 ��Ƶ������Ϊ��λ,Ϊ0��ʾ���ź�
			"dwVideoHeight": 0 ��Ƶ�ߣ���Ϊ��λ,Ϊ0��ʾ���ź�
			"dwFrameRate":   0 ֡�ʣ�����ʱ=��Ƶ������ʱ=��Ƶ/2����60i=30P,Ϊ0��ʾ���ź�
		}
		#u32
		{
			dwQkIndex: 0 Ͷ�������
		}
	}
	@endverbatim

	*/
	Ev_NvApi_Qk_VidSrcInfo_Ntf,

	/**
	@brief    ��ʼ/���� Ͷ��֪ͨ

	MainBuf(#BOOL32)
	MainBuf(#u32)
	MainBuf(#BOOL32)
	@verbatim
	{
		"bView": TRUE:��ʼͶ�� FALSE������Ͷ��
		"dwIndex": Ͷ�������
		"bFromPC":TRUE:Ͷ��������Ͷ�� FALSE��observer����Ͷ��
	}
	@endverbatim

	*/
	Ev_NvApi_Qk_StartViewQuickShare_Ntf,

	/**
	@brief    ��ʼ/���� Ͷ�����֪ͨ

	MainBuf(#BOOL32)
	MainBuf(#u32)
	MainBuf(#EmNvViewQkReason_Api)
	@verbatim
	{
		"bView": TRUE:��ʼͶ�� FALSE������Ͷ��
		"dwIndex": Ͷ�������
		"emReason": �ɹ���ʧ��ԭ��
	}
	@endverbatim

	*/
	Ev_NvApi_Qk_ViewQuickShareResult_Ntf,

	/**
	@brief    ��ʼ/ֹͣ ����PPT֪ͨ

	MainBuf(#BOOL32)
	@verbatim
	{
		"bViewPPT": TRUE:��ʼ FALSE��ֹͣ
	}
	@endverbatim

	*/
	Ev_NvApi_Qk_IsViewPpt_Ntf,

	/**
	@brief    Ͷ���������pc���Ƿ�������

	MainBuf(#BOOL32)
	MainBuf(#U32)
	@verbatim
	{
		"bState": TRUE:������ FALSE��û�д�
		"dwNodeId": Ͷ������¼���
	}
	@endverbatim

	*/
	Ev_NvApi_Qk_IsNTState_Ntf,

	/**
	@brief    Ͷ���������pc���Ƿ�������

	MainBuf(#EmNvQkZoomMode_Api)
	MainBuf(#U32)
	@verbatim
	{
		"EmNvQkZoomMode_Api": �����豸��ʾ����
		"dwIndex": Ͷ�������
	}
	@endverbatim

	*/
	Ev_NvApi_Qk_ZoomMode_Ntf,

	/**
	@brief    Ͷ�������÷ֱ��ʽ��֪ͨ

	MainBuf(#u32)
	MainBuf(#BOOL32)
	@verbatim
	{
		"dwIndex": Ͷ�������
		"bResult": TRUE:���óɹ� FALSE:����ʧ��
	}
	@endverbatim

	*/
	Ev_NvApi_Qk_CodeRes_Ntf,

	/**
	@brief    Ͷ��������֡�ʽ��֪ͨ

	MainBuf(#u32)
	MainBuf(#BOOL32)
	@verbatim
	{
		"dwIndex": Ͷ�������
		"bResult": TRUE:���óɹ� FALSE:����ʧ��
	}
	@endverbatim

	*/
	Ev_NvApi_Qk_CodeFrame_Ntf,

	/**
	@brief    Ͷ��������֡�ʽ��֪ͨ

	MainBuf(#u32)
	MainBuf(#BOOL32)
	@verbatim
	{
		"dwIndex": Ͷ�������
		"bResult": TRUE:���óɹ� FALSE:����ʧ��
	}
	@endverbatim

	*/
	Ev_NvApi_Qk_CodeBitRate_Ntf,

	EV_UI_END(NVAPI_QUICKSHARE) = EVSEG_NVAPI_QUICKSHARE_END
	
};

#define Is_NvApiQK_Msg(m) ((m) >= EV_UI_BGN(NVAPI_QUICKSHARE) && (m) <= EV_UI_END(NVAPI_QUICKSHARE))

/**@}*/

/**@}*/
#endif // _NVAPI_EVENT_BASE_H_

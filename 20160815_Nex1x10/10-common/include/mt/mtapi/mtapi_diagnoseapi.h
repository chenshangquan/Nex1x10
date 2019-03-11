/*******************************************************************************//**
*@file          mtapi_diagnoseapi.h
*@brief         �ṩmtdiagnoseapi����ӿ�
*
*@author        ruiyigen
*@version       5.0    
*@date          20150328
*@copyright     (c)1995-2015 Suzhou Keda Technology Co.,Ltd. All rights reserved
***********************************************************************************/
#ifndef _MTAPI_DIAGNOSEAPI_H_
#define _MTAPI_DIAGNOSEAPI_H_
/**@addtogroup api API�ӿ�
*@{
*/

/**@addtogroup dgapi ���API
*@{
*/

#include <string.h>
#include "mtapi_export.h"
#include "mtapi_typedef.h"
#include "mtapi_struct.h"


/**
* KdvMt_DiagnoseIsInited
*
* @brief mtDiagnoseapi�Ƿ���й���ʼ��
*
* @param	[in] void
* @return	BOOL32  TRUE �� �ѳ�ʼ���� FALSE����δ��ʼ��
* @note MTDiagnoseAPI_DiagnoseInitalize, KdvMt_DiagnoseUnInitalize
*/
KdvMtAPI BOOL32 KdvMtCALL KdvMt_DiagnoseIsInited();

/**
* KdvMt_DiagnoseSetNotify
*
* @brief  ע��Observer(UI)֪ͨ�ص�
*
* @param    [in]  ע��Observer(UI)֪ͨ�ص�(����������û�е�����ʹ��mtbaseapi�еĻص�����)
* @return   void
* @note
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseSetNotify( IN NOTIFY_OBSERVER_CALLBACK cbNotify );

/**
* KdvMt_DiagnoseInitalize
*
* @brief mtdiagnoseapiģ���ʼ��
*
* @return	u32  0: ��ʼ���ɹ��� ��0: ��ʼ��ʧ��
* @note KdvMt_DiagnoseIsInited, KdvMt_DiagnoseUnInitalize
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseInitalize( );



/**
* KdvMt_DiagnoseUnInitalize
*
* @brief mtdiagnoseapiģ���ͷ��˳�
*
* @param	[in] void
* @return	u32  0: �ɹ��� ��0: ʧ��
* @note KdvMt_DiagnoseIsInited, KdvMt_DiagnoseInitalize
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseUnInitalize();


/** 
* KdvMt_DiagnoseCallGetPortInfoReq
*
* @brief  ����˿�ʹ����Ϣ
*
* @param    [in]   dwSSID  MT�ỰID 
* @return    u32   ��������ͽ��
*
* @note ��Ӧ֪ͨ��Ev_MtApi_DiagnoseGetPortInfo_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseCallGetPortInfoReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/** 
* KdvMt_DiagnoseCallGetPortInfo
*
* @brief  ��ȡ�˿�ʹ����Ϣ
*
* @param    [out]  tPortInfo �˿���Ϣ
* @param    [in]   dwSSID    MT�ỰID 
* @return    u32   ��������ͽ��
*
* @note ��Ӧ֪ͨ��Ev_MtApi_DiagnoseGetPortInfo_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseCallGetPortInfo( OUT TMTTotalUsedPort_Api &tPortInfo, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/** 
* KdvMt_DiagnoseCallStatisticsInfoReq
*
* @brief  ��ȡ����롢�������ϳɡ�����ͳ����Ϣ����
*
* @param    [in]   dwSSID    MT�ỰID 
* @return    u32   ��������ͽ��
*
* @note ��Ӧ֪ͨ��Ev_MtApi_DiagnoseCodecGetStatistic_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseCallStatisticsInfoReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/** 
* KdvMt_DiagnoseGetCallStatisticsInfo
*
* @brief  ��ȡ����롢�������ϳɡ�����ͳ����Ϣ
*
* @param    [out]  tStatistic ͳ����Ϣ
* @param    [in]   dwSSID    MT�ỰID 
* @return    u32   ��������ͽ��
*
* @note ��Ӧ֪ͨ:
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetCallStatisticsInfo( OUT TMtCodecStatistic_Api &tStatistic, IN CONST SessionID dwSSID );

/** 
* KdvMt_DiagnoseAudioOutPowerTestCmd
*
* @brief  ���������
*
* @param    [in]   emCodecType  codec ����
* @param    [in]   emStreamIdx  �ڼ�·����
* @param    [in]   bStart  �Ƿ�ʼ 
* @param    [in]   dwSSID  MT�ỰID 
* @return    u32   ��������ͽ��
*
* @note ��Ӧ֪ͨ��Ev_MtApi_Diagnose_CodecAudOutPower_Ntf(bStartΪTRUE��ʱ���Ӧ��ΪFALSE��ʱ�򲻻�Ӧ)
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseAudioOutPowerTestCmd( IN CONST EmCodecComponent_Api emCodecType,IN CONST EmCodecComponentIndex_Api emStreamIdx, IN CONST BOOL32 bStart, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/** 
* KdvMt_DiagnoseGetAudioOutPower
*
* @brief  ��ȡ����������ֵ
*
* @param    [out]  tPower  ������ID������ֵ
* @param    [in]   dwSSID  MT�ỰID 
* @return    u32   ��������ͽ��
*
* @note ��Ӧ֪ͨ��Ev_MtApi_Diagnose_CodecAudOutPower_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetAudioOutPower( OUT TMTAudioPower_Api &tPower, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/** 
* KdvMt_DiagnoseAudioInPowerTestCmd
*
* @brief  ��˷����
* @param    [in]   emCodecType  codec ����
* @param    [in]   emStreamIdx  �ڼ�·����
* @param    [in]   bStart  �Ƿ�ʼ 
* @param    [in]   dwSSID  MT�ỰID 
* @return    u32   ��������ͽ��
*
* @note ��Ӧ֪ͨ��Ev_MtApi_Diagnose_CodecAudInPower_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseAudioInPowerTestCmd( IN CONST EmCodecComponent_Api emCodecType, IN CONST EmCodecComponentIndex_Api emStreamIdx, IN CONST BOOL32 bStart, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/** 
* KdvMt_DiagnoseGetAudioInPower
*
* @brief  ��ȡ��˷�����ֵ
*
* @param    [out] tPower  ������ID������ֵ 
* @param    [in]     dwSSID  MT�ỰID 
* @return    u32     ��������ͽ��
*
* @note ��Ӧ֪ͨ��Ev_MtApi_Diagnose_CodecAudInPower_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetAudioInPower( OUT TMTAudioPower_Api &tPower, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/** 
* KdvMt_DiagnoseSingleLocalLoopBackTestCmd
*
* @brief  ���ػػ�����
*
* @param    [in]   bLoopBack  �Ƿ��Ի� 
* @param    [in]   EmCodecComponentIndex_Api  �������ID 
* @param    [in]   EmCodecComponent_Api  �����������
* @param    [in]   dwSSID     MT�ỰID 
* @return    u32   ��������ͽ��
*
* @note ��Ӧ֪ͨ��Ev_MtApi_Diagnose_LocalSingleLoop_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseSingleLocalLoopBackTestCmd( IN CONST BOOL32 bLoopBack, IN CONST EmCodecComponentIndex_Api emCodecId, IN CONST EmCodecComponent_Api emCodecType, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID  );

/** 
* KdvMt_DiagnoseLocalLoopBackTestCmd
*
* @brief  ���ػػ�����
*
* @param    [in]   bLoopBack  �Ƿ��Ի� 
* @param    [in]   dwSSID     MT�ỰID 
* @return    u32   ��������ͽ��
*
* @note ��Ӧ֪ͨ��Ev_MtApi_Diagnose_LocalLoop_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseLocalLoopBackTestCmd( IN CONST BOOL32 bLoopBack, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID  );


/** 
* KdvMt_DiagnoseRemoteLoopTestCmd
*
* @brief  Զ�˻ػ�����
*
* @param    [in]   bFarLoop  �Ƿ��Ի� 
* @param    [in]   dwSSID     MT�ỰID 
* @return    u32   ��������ͽ��
*
* @note ��Ӧ֪ͨ��Ev_MtApi_Diagnose_RemoteLoop_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseRemoteLoopTestCmd( IN CONST BOOL32 bFarLoop, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/** 
* KdvMt_DiagnoseRibbonTestCmd
*
* @brief  ɫ������(��Embed)
*
* @param    [in]   bTest      ��ʼ/ֹͣ���� 
* @param    [in]   dwSSID     MT�ỰID 
* @return    u32   ��������ͽ��
*
* @note ��Ӧ֪ͨ��
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseRibbonTestCmd( IN CONST BOOL32 bTest, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/** 
* KdvMt_DiagnoseAutoAudioDelayCheckCmd
*
* @brief  �Զ�����ʱ�Ӽ������(��Embed)
*
* @param    [in]   bStart      ��ʼ/ֹͣ
* @param    [in]   dwSSID     MT�ỰID 
* @return    u32   ��������ͽ��
*
* @note ��Ӧ֪ͨ��
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseAutoAudioDelayCheckCmd( IN CONST BOOL32 bStart, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_IsInRibbonTesting
*
* @brief   �Ƿ���ɫ��������(��Embed)
*
* @param    [out]  bInRibbonTesting TRUE:������ FALSE:δ������
* @param    [in]   dwSSID       MT�ỰID 
* @return   u32    0����ȡ�ɹ�  ����������
*
* @note ����֪ͨ��Ev_MtApi_Vc_CodecRibbonTest_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_IsInRibbonTesting( OUT BOOL32& bInRibbonTesting, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID ); 

/** 
* KdvMt_TerminalGetServerInfoReq
*
* @brief  �����������Ϣ
*
* @param    [in]   dwSSID  MT�ỰID 
* @return    u32   ��������ͽ��
*
* @note ��Ӧ֪ͨ��Ev_MtApi_DiagnoseGetSrvInfo_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_TerminalGetServerInfoReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/** 
* KdvMt_TerminalGetServerInfo
*
* @brief  ��ȡ����������״̬
* @param    [out]  tSrvInfo ��������Ϣ
* @param    [in]   dwSSID   MT�ỰID 
* @return    u32   ��������ͽ��
*
* @note ��Ӧ֪ͨ��Ev_MtApi_DiagnoseGetSrvInfo_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_TerminalGetServerInfo( OUT TMTSrvInfoList_Api & tSrvInfo, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/** 
* KdvMt_TerminalGetMtRunTimeReq
*
* @brief  ����ϵͳ����ʱ��
*
* @param    [in]   dwSSID  MT�ỰID 
* @return    u32   ��������ͽ��
*
* @note ��Ӧ֪ͨ��Ev_MtApi_DiagnoseGetMTRunTime_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_TerminalGetMtRunTimeReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/** 
* KdvMt_TerminalGetMtTerInfoReq
*
* @brief  ��ȡ�ն���Ϣ
*
* @param    [in]   dwSSID  MT�ỰID 
* @return    u32   ��������ͽ��
*
* @note ��Ӧ֪ͨ��Ev_MtApi_DiagnoseGetTerInfo_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_TerminalGetMtTerInfoReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/** 
* KdvMt_TerminalGetMtRunTime
*
* @brief  ��ȡϵͳ����ʱ��
* @param    [out]  dwTime  ϵͳ����ʱ��
* @param    [in]   dwSSID  MT�ỰID 
* @return    u32   ��������ͽ��
*
* @note ��Ӧ֪ͨ��Ev_MtApi_DiagnoseGetMTRunTime_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_TerminalGetMtRunTime( OUT u32 &dwTime, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_TerminalGetTerInfo 
* 
* @brief ��ȡ�ն���Ϣ(�ͺ�,�汾��,����)
* 
* @param	[in] tTerInfo �ն���Ϣ
* @param    [in] dwSSID  MT�ỰID 
* @return   u32  MT_SUCCESS:��������ɹ�  ������������
*
* @note ��Ӧ֪ͨ��
*/
KdvMtAPI u32 KdvMtCALL KdvMt_TerminalGetTerInfo(  OUT TTerminalInfo_Api & tTerInfo, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_DTStartNetCaptureCmd 
* 
* @brief ����ץ������
* 
* @param    [in] dwSSID  MT�ỰID 
* @return   u32  MT_SUCCESS:��������ɹ�  ������������
*
* @note ��Ӧ֪ͨ��Ev_MtApi_Base_NetCaptureState_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DTStartNetCaptureCmd( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_DTExportNetCaptureReq 
* 
* @brief ����ץ���ļ�����
* 
* @param    [in] pchExportPath  ����ץ���ļ�·��
* @param    [in] dwSSID  MT�ỰID 
* @return   u32  MT_SUCCESS:��������ɹ�  ������������
*
* @note ��Ӧ֪ͨ��Ev_MtApi_Base_ExportNetCapture_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DTExportNetCaptureReq( IN CONST s8 *pchExportPath, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_DTStopNetCaptureCmd 
* 
* @brief ֹͣץ������
* 
* @param    [in] dwSSID  MT�ỰID 
* @return   u32  MT_SUCCESS:��������ɹ�  ������������
*
* @note ��Ӧ֪ͨ��Ev_MtApi_Base_NetCaptureState_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DTStopNetCaptureCmd( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_DTExportLogReq 
* 
* @brief ������־�ļ�����
*
* @param    [in] pchExportPath  �����ļ�·��
* @param    [in] dwSSID         MT�ỰID 
* @return   u32  MT_SUCCESS:��������ɹ�  ������������
*
* @note ��Ӧ֪ͨ��Ev_MtApi_Base_ExportLog_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DTExportLogReq( IN CONST s8 *pchExportPath, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_DTBandwidthCheckCmd 
* 
* @brief ����������
*
* @param    [in] dwIp	����������ip
* @param    [in] dwSSID  MT�ỰID 
* @return   u32  MT_SUCCESS:��������ɹ�  ������������
*
* @note ��Ӧ֪ͨ��Ev_MtApi_Base_BandwidthTestResult_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DTBandwidthCheckCmd( IN u32 dwIp, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_GetNetCaptureState 
* 
* @brief ��ȡ��ǰ�ն�����ץ��״̬
* 
* @param    [out] dwSSID  ץ��״̬
* @param    [in]  dwSSID  MT�ỰID 
* @return   u32  0���ɹ���ȡ�� ������������ 
*
* @note ����֪ͨ��Ev_MtApi_Base_NetCaptureState_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DTGetNetCaptureState( OUT TMtNetCapStateInfo_Api& tStateInfo, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_GetBandwidthTestResult 
* 
* @brief ��ȡ��������
* 
* @param    [out]  tNetState    MT��������Ϣ 
* @param    [in]   dwSSID       MT�ỰID 
* @return   u32  0���ɹ���ȡ�� ������������ 
*
* @note ����֪ͨ��Ev_MtApi_Base_BandwidthTestResult_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DTGetBandwidthTestResult( OUT TMTNetStatus_Api& tNetState, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_DiagnoseAudioInVolumeReq 
* 
* @brief ��Ƶ����������ѯ����
* 
* @param    [in]   dwSSID       MT�ỰID 
* @return   u32  0���ɹ���ȡ�� ������������ 
*
* @note ����֪ͨ��Ev_MtApi_MtmpAudioInVolume_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseAudioInVolumeReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_DiagnoseGetAudioInVolume 
* 
* @brief ��ȡ��Ƶ��������
* 
* @param    [out]  dwAudInVol   ��������
* @param    [in]   dwSSID       MT�ỰID 
* @return   u32  0���ɹ���ȡ�� ������������ 
*
* @note ����֪ͨ ��
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetAudioInVolume( OUT u32 & dwAudInVol, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_DiagnoseAudioInputStateReq 
* 
* @brief ��Ƶ����ӿ�״̬��ѯ���󣨽�embed��
* 
* @param    [out]  tAudInputState  ����ӿ�״̬
* @param    [in]   dwSSID       MT�ỰID 
* @return   u32  0���ɹ���ȡ�� ������������ 
*
* @note ����֪ͨ��Ev_MtApi_MtmpAudioInputState_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseAudioInputStateReq( IN CONST TMultiAudInputState_Api & tAudInputState, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_DiagnoseGetAudioInputState 
* 
* @brief ��ȡ��Ƶ����ӿ�״̬
* 
* @param    [out]  tAudInputState ����ӿ�״̬
* @param    [in]   dwSSID       MT�ỰID 
* @return   u32  0���ɹ���ȡ�� ������������ 
*
* @note ����֪ͨ����
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetAudioInputState( OUT TMultiAudInputState_Api & tAudInputState, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_DiagnoseAudioOutputStateReq 
* 
* @brief ��Ƶ����ӿ�״̬��ѯ����
* 
* @param    [out]  tAudOutputState  ����ӿ�״̬
* @param    [in]   dwSSID       MT�ỰID 
* @return   u32  0���ɹ���ȡ�� ������������ 
*
* @note ����֪ͨ��Ev_MtApi_MtmpAudioOutputState_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseAudioOutputStateReq( IN CONST TMultiAudOutputState_Api & tAudOutputState, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_DiagnoseGetAudioOutputState 
* 
* @brief ��ȡ��Ƶ����ӿ�״̬
* 
* @param    [out]  tAudOutputState  ����ӿ�״̬
* @param    [in]   dwSSID       MT�ỰID 
* @return   u32  0���ɹ���ȡ�� ������������ 
*
* @note ����֪ͨ����
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetAudioOutputState( TMultiAudOutputState_Api & tAudOutputState, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_DiagnoseVideoInPortCapReq 
* 
* @brief ��Ƶ�ӿ�������ѯ����(��embed)
* 
* @param    [in]   dwSSID       MT�ỰID 
* @return   u32  0���ɹ���ȡ�� ������������ 
*
* @note ����֪ͨ��Ev_MtApi_MtmpVideoInPortCap_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseVideoInPortCapReq ( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_DiagnoseGetSdiInOutReq 
* 
* @brief ��ѯSDI�ӿ���������
* 
* @param    [in]   dwSSID       MT�ỰID 
* @return   u32  0���ɹ���ȡ�� ������������ 
*
* @note ����֪ͨ��Ev_MtApi_MtmpGetSdiInOut_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetSdiInOutReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_DiagnoseMicVolumeDetectReq 
* 
* @brief ���������ѯ����
* 
* @param    [in]   dwSSID       MT�ỰID 
            [in]   s32: ö��ֵ
* @return   u32  0���ɹ���ȡ�� ������������ 
*
* @note ����֪ͨ��Ev_MtApi_MtmpMicVolumeDetect_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseMicVolumeDetectReq( IN CONST EmHDAudPortIn_Api emAudPortIn, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_DiagnoseGetSdiInOutValue 
* 
* @brief ��ȡSDI�ӿ�����
*
* @param    [OUT]   emSdiInOut    SDI�ӿ�����
* @param    [in]   dwSSID       MT�ỰID 
* @return   u32  0���ɹ���ȡ�� ������������ 
*
* @note ����֪ͨ��
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetSdiInOutValue( OUT EmSdiInOut_Api & emSdiInOut,IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_DiagnoseGetVideoInRes 
* 
* @brief ��ȡ��Ƶ�ӿ������б�
* 
* @param    [out]  tVidRes     ��Ƶ�ӿ������б�
* @param    [in]   dwSSID      MT�ỰID 
* @return   u32  0���ɹ���ȡ�� ������������ 
*
* @note ����֪ͨ����
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetVidInPortCapList( TMTHDVidInPortCapList_Api & tVidRes, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );
/**
*  KdvMt_DiagnoseCpuMemUseInfoReq 
* 
* @brief CPU�Լ��ڴ�ʹ�������ѯ
* 
* @param    [in]   dwSSID       MT�ỰID 
* @return   u32  0���ɹ���ȡ�� ������������ 
*
* @note ����֪ͨ��Ev_MTApi_DeviceDetectCpuAndMem_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseCpuMemUseInfoReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_DiagnoseGetVideoInRes 
* 
* @brief ��ȡCPU�Լ��ڴ�ʹ�����
* 
* @param    [out]  tVidRes     CPU�Լ��ڴ�ʹ�����
* @param    [in]   dwSSID      MT�ỰID 
* @return   u32  0���ɹ���ȡ�� ������������ 
*
* @note ����֪ͨ����
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseCpuMemUseInfo( TMTCpuAndMemState_Api & tInfo, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_DiagnoseGetLocalLoopStateReq 
* 
* @brief ��ȡ�����Ի�״̬
*	
* @param    [in]   dwSSID      MT�ỰID 
* @return   u32  0���ɹ���ȡ�� ������������ 
*
* @note ����֪ͨ��Ev_MTApi_Diagnose_LocalLoopState_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetLocalLoopStateReq(IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_DiagnoseGetVidSrcStatusReq 
* 
* @brief ��ƵԴ�ֱ��ʲ�ѯ
*	
* @param    [in]   dwSSID      MT�ỰID 
* @return   u32  0���ɹ���ȡ�� ������������ 
*
* @note ����֪ͨ��Ev_MTApi_Diagnose_VidSrcStatus_Rsp, Ev_MTApi_Diagnose_VidSrcStatus_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetVidSrcStatusReq(IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_DiagnoseGetRibbonTestStatusReq 
* 
* @brief ɫ������״̬��ѯ����
*	
* @param    [in]   dwSSID      MT�ỰID 
* @return   u32  0���ɹ���ȡ�� ������������ 
*
* @note ����֪ͨ��Ev_MTApi_Diagnose_RibbonTestStatus_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetRibbonTestStatusReq(IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/*******************************************************************************//**
*@brief        ��ȡU��״̬��Ϣ(��Embed)
*
*@param[in]     dwSSID  MT�ỰID 
*@return        u32   ��������ͽ��
*@note          ��Ӧ֪ͨ��Ev_MtApi_Diagnose_GetUsbStatusRt_Rsp, Ev_MtApi_Diagnose_GetUsbStatusRt_Ntf
***********************************************************************************/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetUsbStatusReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/*******************************************************************************//**
*@brief        Ŀ¼�ṹ��ѯ(��Embed)
*
*@param[in]		pchSrcPath Ŀ¼�ṹ
*@param[in]     dwSSID  MT�ỰID 
*@return        u32   ��������ͽ��
*@note          ��Ӧ֪ͨ��Ev_MtApi_Diagnose_InquirePathStructure_Rsp
***********************************************************************************/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseInquirePathStructureReq( IN CONST s8 *pchSrcPath, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/*******************************************************************************//**
*@brief        ��ѯ��Ƶ����ӿڵķֱ����Լ����ӿ��Ƿ����ź�(��Embed)
*
*@param[in]     dwSSID  MT�ỰID 
*@return        u32   ��������ͽ��
*@note          ��Ӧ֪ͨ��Ev_MtApi_Diagnose_GetVidInPortRes_Rsp��Ev_MtApi_Diagnose_GetVidInPortRes_Ntf
***********************************************************************************/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetVidInPortResReq(SessionID dwSSID = KMTAPI_DEF_SSID);

/*******************************************************************************//**
*@brief        ��ѯEPLD/CPLD�汾(��Embed)
*
*@param[in]     dwSSID  MT�ỰID 
*@return        u32   ��������ͽ��
*@note          ��Ӧ֪ͨ��Ev_MtApi_Diagnose_InquirePldVersion_Rsp
***********************************************************************************/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseInquirePldVersionReq(SessionID dwSSID = KMTAPI_DEF_SSID);

/*******************************************************************************//**
*@brief        ��ȡEPLD/CPLD�汾(��Embed)
*
*@param[out]   dwVersion  �汾��
*@param[in]     dwSSID  MT�ỰID 
*@return        u32   ��������ͽ��
*@note          ��Ӧ֪ͨ��
***********************************************************************************/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetPldVersion(OUT u32 &dwVersion, SessionID dwSSID = KMTAPI_DEF_SSID);

/*******************************************************************************//**
*@brief        ��ѯFPGA�汾(��Embed)
*
*@param[in]     dwSSID  MT�ỰID 
*@return        u32   ��������ͽ��
*@note          ��Ӧ֪ͨ��Ev_MtApi_Diagnose_InquireFpgaVersion_Rsp
***********************************************************************************/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseInquireFpgaVersionReq(SessionID dwSSID = KMTAPI_DEF_SSID);


/*******************************************************************************//**
*@brief        �µĲ�ѯFPGA�汾(��Embed)
*
*@param[in]     dwSSID  MT�ỰID 
*@return        u32   ��������ͽ��
*@note          ��Ӧ֪ͨ��Ev_MtApi_Diagnose_NewInquireFpgaVersion_Rsp
***********************************************************************************/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseNewInquireFpgaVersionReq(SessionID dwSSID = KMTAPI_DEF_SSID);

/*******************************************************************************//**
*@brief        ��ȡFPGA1�汾(��Embed)
*
*@param[out]   dwVersion  �汾��
*@param[in]     dwSSID  MT�ỰID 
*@return        u32   ��������ͽ��
*@note          ��Ӧ֪ͨ��
***********************************************************************************/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetFpga1Version(OUT u32 &dwVersion, SessionID dwSSID = KMTAPI_DEF_SSID);

/*******************************************************************************//**
*@brief        ��ȡFPGA2�汾(��Embed)
*
*@param[out]   dwVersion  �汾��
*@param[in]     dwSSID  MT�ỰID 
*@return        u32   ��������ͽ��
*@note          ��Ӧ֪ͨ��
***********************************************************************************/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetFpga2Version(OUT u32 &dwVersion, SessionID dwSSID = KMTAPI_DEF_SSID);

/*******************************************************************************//**
*@brief        ��ѯ�ն˳����Ƿ�ȫ�������ɹ�����(��Embed)
*
*@param[in]     dwSSID  MT�ỰID 
*@return        u32   ��������ͽ��
*@note          ��Ӧ֪ͨ��Ev_MtApi_Diagnose_InquireHDMtStartSucess_Rsp, Ev_MtApi_Diagnose_HDMtStartSucess_Ntf
***********************************************************************************/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseInquireHDMtStartSucessReq(SessionID dwSSID = KMTAPI_DEF_SSID);

/*******************************************************************************//**
*@brief        ����ļ��Ƿ����
*@param[in]     pchPath  ������ʼĿ¼
*@param[in]     pchName  �����ļ���
*@param[in]     bRecurse  �Ƿ����������Ŀ¼
*@param[in]     dwSSID  MT�ỰID 
*@return        u32   ��������ͽ��
*@note          ��Ӧ֪ͨ��
***********************************************************************************/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseCheckFileIsExistReq(IN CONST s8 *pchPath, IN CONST s8 *pchName, IN CONST BOOL32 &bRecurse, SessionID dwSSID = KMTAPI_DEF_SSID);

/*******************************************************************************//**
*@brief        ������ַ������
*@param[in]     pchPath  ����Ŀ��·��
*@param[in]     dwSSID  MT�ỰID 
*@return        u32   ��������ͽ��
*@note          ��Ӧ֪ͨ��Ev_MtApi_Diagnose_AddrBookExport_Rsp Ev_MtApi_Diagnose_AddrBookExportProgress_Ntf
***********************************************************************************/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseExportAddrBookReq(IN CONST s8 *pchPath, SessionID dwSSID = KMTAPI_DEF_SSID);

/*******************************************************************************//**
*@brief        �����ַ������
*@param[in]     pchPath  ����Դ·��(���ļ���)
*@param[in]     dwSSID  MT�ỰID 
*@return        u32   ��������ͽ��
*@note          ��Ӧ֪ͨ��Ev_MtApi_Diagnose_AddrBookImport_Rsp Ev_MtApi_Diagnose_AddrBookImportProgress_Ntf
***********************************************************************************/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseImportAddrBookReq(IN CONST s8 *pchPath, SessionID dwSSID = KMTAPI_DEF_SSID);

/**
*  KdvMt_DiagnoseGetLocalLoopStateReq 
* 
* @brief ��ȡ��Ƶ Զ���Ի�״̬����
*	
* @param    [in]   dwSSID      MT�ỰID 
* @return   u32  0���ɹ���ȡ�� ������������ 
*
* @note ����֪ͨ��Ev_MTApi_Diagnose_RemoteLoopState_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetRemoteLoopStateReq(IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_DiagnoseGetAudRmtLoopStateReq 
* 
* @brief ��ȡ��Ƶ Զ���Ի�״̬����
*	
* @param    [in]   dwSSID      MT�ỰID 
* @return   u32  0���ɹ���ȡ�� ������������ 
*
* @note ����֪ͨ��Ev_MTApi_Diagnose_AudRmtLoopState_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetAudRmtLoopStateReq(IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_DiagnoseGetMicrophoneConnectStatusReq 
* 
* @brief ��˷�����״̬����
*	
* @param    [in]   dwSSID      MT�ỰID 
* @return   u32  0���ɹ���ȡ�� ������������ 
*
* @note ����֪ͨ��Ev_MTApi_Diagnose_MicrophoneConnectStatus_Rsp Ev_MTApi_Diagnose_MicrophoneConnectStatus_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetMicrophoneConnectStatusReq(IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_DiagnoseGetMicrophoneBatteryLevelReq 
* 
* @brief ��˷����ߵ�������
*	
* @param    [in]   dwSSID      MT�ỰID 
* @return   u32  0���ɹ���ȡ�� ������������ 
*
* @note ����֪ͨ��Ev_MTApi_Diagnose_MicrophoneBatteryLevel_Rsp Ev_MTApi_Diagnose_MicrophoneBatteryLevel_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetMicrophoneBatteryLevelReq(IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_DiagnoseGetMicrophoneVersionStatusReq 
* 
* @brief ��˷���°��ϴ�״̬����
*	
* @param    [in]   dwSSID      MT�ỰID 
* @return   u32  0���ɹ���ȡ�� ������������ 
*
* @note ����֪ͨ��Ev_MTApi_Diagnose_MicrophoneVersionStatus_Rsp Ev_MTApi_Diagnose_MicrophoneVersionStatus_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetMicrophoneVersionStatusReq(IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_DiagnoseMicrophoneUpgradeCmd 
* 
* @brief ��˷���������
*	
* @param    [in]   tStatus       ���״̬
* @param    [in]   dwSSID      MT�ỰID 
* @return   u32  0���ɹ���ȡ�� ������������ 
*
* @note ����֪ͨ��Ev_MTApi_Diagnose_MicrophoneUpgrade_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseMicrophoneUpgradeCmd(IN CONST TMTAllMicStatus_Api tStatus, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_DiagnoseOpenHotspotReq 
* 
* @brief ������Ƶ�ȵ�����
*	
* @param    [in]   tStatus       ���״̬
* @param    [in]   dwSSID      MT�ỰID 
* @return   u32  0���ɹ���ȡ�� ������������ 
*
* @note ����֪ͨ��Ev_MTApi_Diagnose_OpenHotspot_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseOpenHotspotReq(IN CONST TMTAllMicStatus_Api tStatus, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_DiagnoseGetHotspotStatusReq 
* 
* @brief ��Ƶ״̬����
*	
* @param    [in]   dwSSID      MT�ỰID 
* @return   u32  0���ɹ���ȡ�� ������������ 
*
* @note ����֪ͨ��Ev_MTApi_Diagnose_GetHotspotStatus_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetHotspotStatusReq(IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_DiagnoseSetOsdTransparentReq 
* 
* @brief OSD��͸��������
*	
* @param    [in]   bTrans       TRUE:����FALSE: ��
* @param    [in]   dwSSID      MT�ỰID 
* @return   u32  0���ɹ���ȡ�� ������������ 
*
* @note ����֪ͨ��Ev_MTApi_Diagnose_SetOsdTransparent_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseSetOsdTransparentReq(IN CONST BOOL32 bTrans, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_DiagnoseSetOsdSnapShotBrowseStateCmd 
* 
* @brief OSD�����Ƿ����������
*	
* @param    [in]   bTrans       TRUE:�ǣ�FALSE: ��
* @param    [in]   dwSSID      MT�ỰID 
* @return   u32  0���ɹ���ȡ�� ������������ 
*
* @note ����֪ͨ��Ev_MTApi_Diagnose_OsdSnapshotBrowse_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseSetOsdSnapShotBrowseStateCmd(IN CONST BOOL32 bBrowse, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_DiagnoseSetSyncTooltipBoxCmd 
* 
* @brief ��ʾ��ͬ������
*	
* @param    [in]   pchUserId  �û�ID
* @param    [in]   dwSSID      MT�ỰID 
* @return   u32  0���ɹ���ȡ�� ������������ 
*
* @note ����֪ͨ��Ev_MTApi_Diagnose_SyncTooltipBox_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseSetSyncTooltipBoxCmd(IN CONST s8 *pchUserId, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_DiagnoseGetNetCapFileListReq 
* 
* @brief ��ȡץ���ļ��б�����
*	
* @param    [in]   dwSSID      MT�ỰID 
* @return   u32  0���ɹ���ȡ�� ������������ 
*
* @note ����֪ͨ��Ev_MTApi_Diagnose_GetNetCapFileList_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetNetCapFileListReq(IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_DiagnoseDeleteNetCapFileCmd 
* 
* @brief ɾ��ץ���ļ�
*	
* @param    [in]   dwSSID      MT�ỰID 
* @return   u32  0���ɹ���ȡ�� ������������ 
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseDeleteNetCapFileCmd(IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_DiagnoseGetMicrophoneVersionReq 
* 
* @brief ������˰汾��Ϣ
*	
* @param    [in]   dwSSID      MT�ỰID 
* @return   u32  0���ɹ���ȡ�� ������������ 
*
* @note ����֪ͨ��Ev_MTApi_Diagnose_GetMicrophoneVerInfo_Rsp��Ev_MTApi_Diagnose_MicrophoneVerInfo_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetMicrophoneVersionReq(IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_DiagnoseResetUserFileimgCmd 
* 
* @brief ����/user/fileimg�еİ汾��
*	
* @param    [in]   dwFileType      ��Ҫ���õİ汾�� 1: wind3d.bin.tar ; 2: skyshare_setup.tar
* @param    [in]   dwSSID            MT�ỰID 
* @return   u32  0���ɹ�, ������������ 
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseResetUserFileimgCmd(IN CONST u32 dwFileType, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_DiagnoseGetCurCapStatusReq 
* 
* @brief ��ȡ��ǰץ��״̬
*
* @param    [in]   dwSSID            MT�ỰID 
* @return   u32  0���ɹ�, ������������ 
*
* @note ����֪ͨ��Ev_MTApi_Diagnose_GetCurCapStatus_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetCurCapStatusReq(IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_DiagnoseServerLinkTestCmd
* 
* @brief ��¼���������Ӳ���
*
* @param    [in]   bStart               TRUE:��ʼ FALSE:ֹͣ
* @param    [in]   dwSSID            MT�ỰID 
* @return   u32  0���ɹ�, ������������ 
*
* @note ����֪ͨ��Ev_MTApi_Diagnose_ServerTest_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseServerLinkTestCmd(IN CONST BOOL32 bStart, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_DiagnoseThreadDetectRegCmd
* 
* @brief ע��һ����Ҫ����ģ��
*
* @param    [in]   tInfo                 ģ����Ϣ
* @param    [in]   dwSSID            MT�ỰID 
* @return   u32  0���ɹ�, ������������ 
*
* @note ����֪ͨ����
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseThreadDetectRegCmd(IN CONST TMTServiceInfo_Api tInfo, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_DiagnoseThreadDetectUpdateCmd
* 
* @brief ����һ����ע��ģ�����Ϣ
*
* @param    [in]   dwAppId          ģ���APP ID
* @param    [in]   dwSSID            MT�ỰID 
* @return   u32  0���ɹ�, ������������ 
*
* @note ����֪ͨ����
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseThreadDetectUpdateCmd(IN CONST u32 dwAppId, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_DiagnoseMicrophoneStateReq
* 
* @brief <<��˷�״̬����>>
*
* @param    [in]   dwSSID            MT�ỰID 
* @return   u32  0���ɹ�, ������������ 
*
* @note ����֪ͨ��Ev_MTApi_Diagnose_MicrophoneState_Rsp��Ev_MTApi_Diagnose_MicrophoneState_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseMicrophoneStateReq(IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_DiagnoseMicrophoneUploadCmd
* 
* @brief <<��˷��ϴ�����>>
*
* @param    [in]   dwSSID            MT�ỰID 
* @return   u32  0���ɹ�, ������������ 
*
* @note ����֪ͨ��Ev_MTApi_Diagnose_MicrophoneUpload_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseMicrophoneUploadCmd(IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_DiagnoseMicrophoneInstallCmd
* 
* @brief <<��˷簲װ����>>
*
* @param    [in]   dwSSID            MT�ỰID 
* @return   u32  0���ɹ�, ������������ 
*
* @note ����֪ͨ����
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseMicrophoneInstallCmd(IN CONST TMicInstallList_Api tInstallList, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_DiagnoseMicUpgradeFileImportReq
* 
* @brief <<������˷������ļ�����>>
*
* @param    [in]   pchFileNamePath            ����Դ·��(���ļ���)
* @param    [in]   dwSSID                            MT�ỰID 
* @return   u32  0���ɹ�, ������������ 
*
* @note ����֪ͨ��Ev_MTApi_Diagnose_MicUpgradeFileImport_Rsp��Ev_MTApi_Diagnose_MicUpgradeFileImportProgress_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseMicUpgradeFileImportReq(IN CONST s8* pchFileNamePath, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_DiagnoseExportAllLogFilesReq
* 
* @brief <<����������־�ļ�����>>
*
* @param    [in]   pchPath            �ļ����Ŀ¼
* @param    [in]   dwSSID             MT�ỰID 
* @return   u32  0���ɹ�, ������������ 
*
* @note ����֪ͨ��Ev_MTApi_Diagnose_ExportAllFiles_Rsp��Ev_MTApi_Diagnose_ExportAllFilesProgress_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseExportAllLogFilesReq(IN CONST s8* pchPath, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/*******************************************************************************//**
*@brief        ��ѯ�豸����E1ģ������(��Embed)
*
*@param[in]     dwSSID  MT�ỰID 
*@return        u32   ��������ͽ��
*@note          ��Ӧ֪ͨ��Ev_MtApi_Diagnose_GetE1ModuleNum_Rsp
***********************************************************************************/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetE1ModuleNumReq(IN CONST SessionID dwSSID = KMTAPI_DEF_SSID);

/** 
* KdvMt_DiagnoseIspImgInfSharpnessCmd
*
* @brief  ����Isp���       
* @param    [in]   emGeneralLevel            Ispͼ�����ֵ
* @param    [in]   dwSSID  MT�ỰID 
* @return    u32   ��������ͽ��
*
* @note ��Ӧ֪ͨ��Ev_MtApi_Diagnose_IspImgInfSharpness_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseIspImgInfSharpnessCmd( IN CONST EmGeneralLevel_Api emGeneralLevel, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/** 
* KdvMt_DiagnoseGetIspImgInfSharpnessReq
*
* @brief  ��ȡIsp���       
* @param    [in]   dwSSID  MT�ỰID 
* @return    u32   ��������ͽ��
*
* @note ��Ӧ֪ͨ��Ev_MtApi_Diagnose_IspImgInfSharpness_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetIspImgInfSharpnessReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/** 
* KdvMt_DiagnoseGetIspImgInfSharpness
*
* @brief  ��ȡIsp���       
* @param    [out]   emGeneralLevel            Ispͼ�����ֵ
* @param    [in]   dwSSID  MT�ỰID 
* @return    u32   ��������ͽ��
*
* @note ��Ӧ֪ͨ��
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetIspImgInfSharpness( OUT EmGeneralLevel_Api &emGeneralLevel, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );




/** 
* KdvMt_DiagnoseIspImgInfWhiteBalanceCmd
*
* @brief  ����Isp��ƽ��
* @param    [in]   emWBAMode                 Ispͼ���ƽ��ֵ        
* @param    [in]   dwSSID  MT�ỰID 
* @return    u32   ��������ͽ��
*
* @note ��Ӧ֪ͨ��Ev_MtApi_Diagnose_IspImgInfWhiteBalance_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseIspImgInfWhiteBalanceCmd( IN CONST EmWBAMode_Api emWBAMode, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID  );

/** 
* KdvMt_DiagnoseGetIspImgInfWhiteBalanceReq
*
* @brief  ��ȡIsp��ƽ��       
* @param    [in]   dwSSID  MT�ỰID 
* @return    u32   ��������ͽ��
*
* @note ��Ӧ֪ͨ��Ev_MtApi_Diagnose_IspImgInfWhiteBalance_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetIspImgInfWhiteBalanceReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID  );

/** 
* KdvMt_DiagnoseGetIspImgInfWhiteBalance
*
* @brief  ��ȡIsp��ƽ��
* @param    [out]   emWBAMode                 Ispͼ���ƽ��ֵ        
* @param    [in]   dwSSID  MT�ỰID 
* @return    u32   ��������ͽ��
*
* @note ��Ӧ֪ͨ��
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetIspImgInfWhiteBalance( OUT EmWBAMode_Api &emWBAMode, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID  );




/** 
* KdvMt_DiagnoseIspImgInfShutterCmd
*
* @brief  ����Isp�����ٶ�        
* @param    [in]   emShutterLevel            Ispͼ������ٶ�ֵ
* @param    [in]   dwSSID  MT�ỰID 
* @return    u32   ��������ͽ��
*
* @note ��Ӧ֪ͨ��Ev_MtApi_Diagnose_IspImgInfShutter_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseIspImgInfShutterCmd( IN CONST EmShutterLevel_Api emShutterLevel, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID  );

/** 
* KdvMt_DiagnoseGetIspImgInfShutterReq
*
* @brief  ��ȡIsp�����ٶ�        
* @param    [in]   dwSSID  MT�ỰID 
* @return    u32   ��������ͽ��
*
* @note ��Ӧ֪ͨ��Ev_MtApi_Diagnose_IspImgInfShutter_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetIspImgInfShutterReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID  );

/** 
* KdvMt_DiagnoseGetIspImgInfShutter
*
* @brief  ��ȡIsp�����ٶ�        
* @param    [out]   emShutterLevel            Ispͼ������ٶ�ֵ
* @param    [in]   dwSSID  MT�ỰID 
* @return    u32   ��������ͽ��
*
* @note ��Ӧ֪ͨ��
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetIspImgInfShutter( OUT EmShutterLevel_Api &emShutterLevel, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID  );




/** 
* KdvMt_DiagnoseIspImgInfNoiseCmd
*
* @brief  ����Isp����        
* @param    [in]   emNFMode            Ispͼ����ֵ
* @param    [in]   dwSSID  MT�ỰID 
* @return    u32   ��������ͽ��
*
* @note ��Ӧ֪ͨ��Ev_MtApi_Diagnose_IspImgInfNoise_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseIspImgInfNoiseCmd( IN CONST EmNFMode_Api emNFMode, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID  );


/** 
* KdvMt_DiagnoseGetIspImgInfNoiseReq
*
* @brief  ��ȡIsp����        
* @param    [in]   dwSSID  MT�ỰID 
* @return    u32   ��������ͽ��
*
* @note ��Ӧ֪ͨ��Ev_MtApi_Diagnose_IspImgInfNoise_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetIspImgInfNoiseReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID  );


/** 
* KdvMt_DiagnoseGetIspImgInfNoise
*
* @brief  ��ȡIsp����        
* @param    [out]   emNFMode            Ispͼ����ֵ
* @param    [in]   dwSSID  MT�ỰID 
* @return    u32   ��������ͽ��
*
* @note ��Ӧ֪ͨ��
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetIspImgInfNoise( OUT EmNFMode_Api &emNFMode, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID  );



/** 
* KdvMt_DiagnoseIspImgInfISOCmd
*
* @brief  ����Isp�й��
* @param    [in]   emISO             Ispͼ��й��         
* @param    [in]   dwSSID  MT�ỰID 
* @return    u32   ��������ͽ��
*
* @note ��Ӧ֪ͨ��Ev_MtApi_Diagnose_IspImgInfISO_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseIspImgInfISOCmd( IN CONST EmISO_Api emISO, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID  );


/** 
* KdvMt_DiagnoseGetIspImgInfISOReq
*
* @brief  ��ȡIsp�й��         
* @param    [in]   dwSSID  MT�ỰID 
* @return    u32   ��������ͽ��
*
* @note ��Ӧ֪ͨ��Ev_MtApi_Diagnose_IspImgInfISO_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetIspImgInfISOReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID  );


/** 
* KdvMt_DiagnoseGetIspImgInfISO
*
* @brief  ��ȡIsp�й��
* @param    [out]   emISO             Ispͼ��й��         
* @param    [in]   dwSSID  MT�ỰID 
* @return    u32   ��������ͽ��
*
* @note ��Ӧ֪ͨ��
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetIspImgInfISO( OUT EmISO_Api &emISO, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID  );





/** 
* KdvMt_DiagnoseIspImgInfApertureCmd
*
* @brief  ����Isp��Ȧ��С
* @param    [in]   EmAperture_Api             Isp��Ȧ��С         
* @param    [in]   dwSSID  MT�ỰID 
* @return    u32   ��������ͽ��
*
* @note ��Ӧ֪ͨ��Ev_MtApi_Diagnose_IspImgInfAperture_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseIspImgInfApertureCmd( IN CONST EmAperture_Api emAperture, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/** 
* KdvMt_DiagnoseGetIspImgInfApertureReq
*
* @brief  ����Isp��Ȧ��С      
* @param    [in]   dwSSID  MT�ỰID 
* @return    u32   ��������ͽ��
*
* @note ��Ӧ֪ͨ��Ev_MtApi_Diagnose_IspImgInfAperture_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetIspImgInfApertureReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/** 
* KdvMt_DiagnoseGetIspImgInfAperture
*
* @brief  ��ȡIsp��Ȧ��С
* @param    [out]   EmAperture_Api             Isp��Ȧ��С         
* @param    [in]   dwSSID  MT�ỰID 
* @return    u32   ��������ͽ��
*
* @note ��Ӧ֪ͨ��
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetIspImgInfAperture( OUT  EmAperture_Api &emAperture, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );




/** 
* KdvMt_DiagnoseIspImgInfExposureModeCmd
*
* @brief  ����Isp�ع�ģʽ
* @param    [in]   EmExposureMode_Api        Isp�ع�         
* @param    [in]   dwSSID  MT�ỰID 
* @return    u32   ��������ͽ��
*
* @note ��Ӧ֪ͨ��Ev_MtApi_Diagnose_IspImgInfExposureMode_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseIspImgInfExposureModeCmd( IN CONST EmExposureMode_Api emExposureMode, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/** 
* KdvMt_DiagnoseGetIspImgInfExposureModeReq
*
* @brief  ��ȡIsp�ع�ģʽ         
* @param    [in]   dwSSID  MT�ỰID 
* @return    u32   ��������ͽ��
*
* @note ��Ӧ֪ͨ��Ev_MtApi_Diagnose_IspImgInfExposureMode_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetIspImgInfExposureModeReq(  IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/** 
* KdvMt_DiagnoseGetIspImgInfExposureMode
*
* @brief  ��ȡIsp�ع�ģʽ
* @param    [in]   EmExposureMode_Api        Isp�ع�         
* @param    [out]   dwSSID  MT�ỰID 
* @return    u32   ��������ͽ��
*
* @note ��Ӧ֪ͨ��
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetIspImgInfExposureMode( OUT EmExposureMode_Api &emExposureMode, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );




/** 
* KdvMt_DiagnoseIspImgInfBrightnesssCmd
*
* @brief  ����Isp����
* @param    [in]   EmBrightnessDirection_Api        Isp����         
* @param    [in]   dwSSID  MT�ỰID 
* @return    u32   ��������ͽ��
*
* @note ��Ӧ֪ͨ��
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseIspImgInfBrightnesssCmd( IN CONST EmBrightnessDirection_Api emBrightnessDirection, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/** 
* KdvMt_DiagnoseGetIsDbgCfgExistReq
*
* @brief	��ȡdebug�ļ��Ƿ����
* @param    [in]   dwSSID  MT�ỰID 
* @return    u32   ��������ͽ��
*
* @note ��Ӧ֪ͨ��
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetIsDbgCfgExistReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/** 
* KdvMt_DiagnoseGetMicrophoneInfoReq
*
* @brief	��ȡ�ն˱������˷�汾��Ϣ����
* @param    [in]   dwSSID  MT�ỰID 
* @return   u32   ��������ͽ��
*
* @note ��Ӧ֪ͨ��Ev_MtApi_Diagnose_TermKeepMicrophoneInfo_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetMicrophoneInfoReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_DTGetCurCapStatusInfo 
* 
* @brief ��ȡ��ǰ�ն�����ץ������ץ������Ϣ
* 
* @param    [out] tStatusInfo  ץ����Ϣ
* @param    [in]  dwSSID       MT�ỰID 
* @return   u32  0���ɹ���ȡ�� ������������ 
*
* @note ����֪ͨ��no
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DTGetCurCapStatusInfo( OUT TMtCurCapStatusInfo_Api& tStatusInfo, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/** 
* KdvMt_DiagnoseSetIspImgNoiseCmd
*
* @brief  ����Ispͼ��������        
* @param    [in]   tInfo   ������Ϣ
* @param    [in]   dwSSID  MT�ỰID 
* @return    u32   ��������ͽ��
*
* @note ��Ӧ֪ͨ��Ev_MtApi_Diagnose_SetIspImgNoise_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseSetIspImgNoiseCmd( IN CONST TMTIspImgNFInfo_Api tInfo, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID  );

/** 
* KdvMt_DiagnoseGetIspImgNoiseReq
*
* @brief  ��ȡIspͼ������Ϣ����       
* @param    [in]   emType  ��������,2D����3D 
* @param    [in]   dwSSID  MT�ỰID 
* @return    u32   ��������ͽ��
*
* @note ��Ӧ֪ͨ��	Ev_MtApi_Diagnose_GetIspImgNoise_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetIspImgNoiseReq( IN CONST EmNFType_Api emType, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID  );

/** 
* KdvMt_DiagnoseGetIspImgNoise
*
* @brief  ��ȡIspͼ������Ϣ
* @param    [in/out]  tInfo   ������Ϣ  
* @param    [in]   dwSSID  MT�ỰID 
* @return    u32   ��������ͽ��
*
* @note ��Ӧ֪ͨ��no
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetIspImgNoise( OUT TMTIspImgNFInfo_Api& tInfo, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID  );

/** 
* KdvMt_DiagnoseSetIspImgSharpnessCmd
*
* @brief  ����Ispͼ���������       
* @param    [in]   tInfo   �����Ϣ
* @param    [in]   dwSSID  MT�ỰID 
* @return    u32   ��������ͽ��
*
* @note ��Ӧ֪ͨ��Ev_MtApi_Diagnose_SetIspImgSharpness_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseSetIspImgSharpnessCmd( IN CONST TMTIspImgSharpnessInfo_Api tInfo, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/** 
* KdvMt_DiagnoseGetIspImgSharpnessReq
*
* @brief  ��ȡIspͼ�������Ϣ������       
* @param    [in]   tInfo   �����Ϣ
* @param    [in]   dwSSID  MT�ỰID 
* @return    u32   ��������ͽ��
*
* @note ��Ӧ֪ͨ��Ev_MtApi_Diagnose_GetIspImgSharpness_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetIspImgSharpnessReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/** 
* KdvMt_DiagnoseGetIspImgSharpness
*
* @brief  ��ȡIspͼ�������Ϣ    
* @param    [out]   tInfo   �����Ϣ
* @param    [in]   dwSSID  MT�ỰID 
* @return    u32   ��������ͽ��
*
* @note ��Ӧ֪ͨ��no
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetIspImgSharpness( OUT TMTIspImgSharpnessInfo_Api& tInfo, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/** 
* KdvMt_DiagnoseSetIspExposureGainCmd
*
* @brief  ����Isp�ع�ģʽ������Ϣ����  
* @param    [in]   tInfo   �����Ϣ
* @param    [in]   dwSSID  MT�ỰID 
* @return    u32   ��������ͽ��
*
* @note ��Ӧ֪ͨ��Ev_MtApi_Diagnose_SetIspImgExposureGain_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseSetIspExposureGainCmd( IN CONST TMTIspImgExposureGain_Api tInfo, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/** 
* KdvMt_DiagnoseGetIspExposureGainReq
*
* @brief  ��ȡIsp�ع�ģʽ������Ϣ���� 
* @param    [in]   emType  �������� 
* @param    [in]   dwSSID  MT�ỰID 
* @return    u32   ��������ͽ��
*
* @note ��Ӧ֪ͨ��Ev_MtApi_Diagnose_GetIspImgExposureGain_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetIspExposureGainReq( IN CONST EmExposureGainType_Api emType, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/** 
* KdvMt_DiagnoseGetIspExposureGain
*
* @brief  ��ȡIsp�ع�ģʽ������Ϣ 
* @param    [in/out]   tInfo  ������Ϣ
* @param    [in]   dwSSID  MT�ỰID 
* @return    u32   ��������ͽ��
*
* @note ��Ӧ֪ͨ��no
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetIspExposureGain( OUT TMTIspImgExposureGain_Api& tInfo, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/** 
* KdvMt_DiagnoseSetIspWBGainCmd
*
* @brief  ���ð�ƽ��(�ֶ�ģʽ)������Ϣ����  
* @param    [in]   tInfo   ������Ϣ
* @param    [in]   dwSSID  MT�ỰID 
* @return    u32   ��������ͽ��
*
* @note ��Ӧ֪ͨ��Ev_MtApi_Diagnose_SetIspImgWBAGain_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseSetIspWBGainCmd( IN CONST TMTIspImgWBAGainInfo_Api tInfo, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/** 
* KdvMt_DiagnoseGetIspWBGainReq
*
* @brief  ��ȡ��ƽ��(�ֶ�ģʽ)������Ϣ����
* @param    [in]   emType  �������� 
* @param    [in]   dwSSID  MT�ỰID 
* @return    u32   ��������ͽ��
*
* @note ��Ӧ֪ͨ��Ev_MtApi_Diagnose_GetIspImgWBAGain_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetIspWBGainReq( IN CONST EmWBAGainType_Api emType, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/** 
* KdvMt_DiagnoseGetIspExposureGain
*
* @brief  ��ȡ��ƽ��(�ֶ�ģʽ)������Ϣ 
* @param    [in/out]   tInfo  ������Ϣ
* @param    [in]   dwSSID  MT�ỰID 
* @return    u32   ��������ͽ��
*
* @note ��Ӧ֪ͨ��no
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetIspWBGain( OUT TMTIspImgWBAGainInfo_Api& tInfo, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_DiagnoseSetIspParamCmd
*
* @brief    ����ͼ�����ȡ��Աȶȡ����Ͷȵ�ISP����
*
* @param    [in]   emCodecType   ���������
* @param    [in]   emCodecIdx   ��һ·
* @param    [in]   emMsgSrc    EmImgParam_Api(��ʱ����emContrast_Api��emSaturation_Api��emBright_Api������ֵ��Ч)
* @param    [in]   nValue		����ֵ
* @return   u32    0���ɹ�      ����������
* @note ����֪ͨ�� Ev_MtApi_Diagnose_SetIspParam_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseSetIspParamCmd( IN CONST EmCodecComponent_Api emCodecType, IN CONST EmCodecComponentIndex_Api emCodecIdx, 
													 IN CONST EmIspImgInf_Api emMsgSrc,IN CONST s32 nValue,IN CONST SessionID dwSSID  = KMTAPI_DEF_SSID );

/**
* KdvMt_DiagnoseGetIspParamReq
*
* @brief    ��ѯͼ�����ȡ��Աȶȡ����Ͷȵ�ISP��������
*
* @param    [in]   emCodecType   ���������
* @param    [in]   emCodecIdx   ��һ·
* @param    [in]   emMsgSrc    EmImgParam_Api
* @return   u32    0���ɹ�      ����������
* @note ����֪ͨ��Ev_MtApi_Diagnose_GetIspParam_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetIspParamReq( IN CONST EmCodecComponent_Api emCodecType, IN CONST EmCodecComponentIndex_Api emCodecIdx, 
													 IN CONST EmIspImgInf_Api emMsgSrc, IN CONST SessionID dwSSID  = KMTAPI_DEF_SSID );

/**
* KdvMt_DiagnoseSetBackLightCmd
*
* @brief   ��������ͷ���ⲹ�������Embed��
*
* @param    [in]   bOn            ����ͷ���ⲹ����TRUEΪ�򿪣�FALSEΪ�ر�
* @param    [in]   dwSSID         MT�ỰID 
* @return   u32    0����ȡ�ɹ�  ����������
*
* @note ����֪ͨ��Ev_MtApi_Diagnose_SetIspImgBackLightSwitch_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseSetBackLightCmd( IN CONST BOOL32 bOn, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_DiagnoseGetBackLightReq
*
* @brief   ��ȡ����ͷ���ⲹ�����󣨽�Embed��
*
* @param    [in]   dwSSID         MT�ỰID 
* @return   u32    0����ȡ�ɹ�  ����������
*
* @note ����֪ͨ��Ev_MtApi_Diagnose_GetIspImgBackLightSwitch_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetBackLightReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_DiagnoseGetBackLight
*
* @brief   ��ȡ����ͷ�Ƿ������ⲹ������Embed��
*
* @param    [out]   bOn           TRUEΪ�򿪣�FALSEΪ�ر�
* @param    [in]   dwSSID         MT�ỰID 
* @return   u32    0����ȡ�ɹ�  ����������
*
* @note ����֪ͨ��no
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetBackLight( OUT BOOL32 &bOn, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_DiagnoseSetBackLightLevelCmd
*
* @brief   ��������ͷ���ⲹ���ȼ�����Embed��
*
* @param    [in]   dwValue        �����ȼ��� 0-15
* @param    [in]   dwSSID         MT�ỰID 
* @return   u32    0����ȡ�ɹ�  ����������
*
* @note ����֪ͨ��Ev_MtApi_Diagnose_SetIspImgBackLightLevel_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseSetBackLightLevelCmd( IN CONST u32 dwValue, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_DiagnoseGetBackLightLevelReq
*
* @brief   ��ȡ����ͷ���ⲹ���ȼ����󣨽�Embed��
*
* @param    [in]   dwSSID         MT�ỰID 
* @return   u32    0����ȡ�ɹ�  ����������
*
* @note ����֪ͨ��Ev_MtApi_Diagnose_GetIspImgBackLightLevel_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetBackLightLevelReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_DiagnoseGetBackLightLevel
*
* @brief   ��ȡ����ͷ���ⲹ���ȼ�����Embed��
*
* @param    [out]   dwValue        �����ȼ��� 0-15
* @param    [in]    dwSSID         MT�ỰID 
* @return   u32     0����ȡ�ɹ�    ����������
*
* @note ����֪ͨ��no
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetBackLightLevel( OUT u32 &dwValue, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_DiagnoseSetDigDynSwitchCmd
*
* @brief   Isp���ֿ�̬�������ã���Embed��
*
* @param    [in]   bOn            TRUEΪ�򿪣�FALSEΪ�ر�
* @param    [in]   dwSSID         MT�ỰID 
* @return   u32    0����ȡ�ɹ�  ����������
*
* @note ����֪ͨ��Ev_MtApi_Diagnose_SetIspImgDigDynSwitch_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseSetDigDynSwitchCmd( IN CONST BOOL32 bOn, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_DiagnoseGetDigDynSwitchReq
*
* @brief   ��ȡIsp���ֿ�̬�������󣨽�Embed��
*
* @param    [in]   dwSSID         MT�ỰID 
* @return   u32    0����ȡ�ɹ�  ����������
*
* @note ����֪ͨ��Ev_MtApi_Diagnose_GetIspImgDigDynSwitch_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetDigDynSwitchReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_DiagnoseGetDigDynSwitch
*
* @brief   Isp���ֿ�̬���ػ�ȡ����Embed��
*
* @param    [out]   bOn            TRUEΪ�򿪣�FALSEΪ�ر�
* @param    [in]   dwSSID         MT�ỰID 
* @return   u32    0����ȡ�ɹ�  ����������
*
* @note ����֪ͨ��no
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetDigDynSwitch( OUT BOOL32 &bOn, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_DiagnoseSetDigDynLevelCmd
*
* @brief   Isp���ֿ�̬�ȼ����ã���Embed��
*
* @param    [in]   dwValue        �ȼ�ֵ
* @param    [in]   dwSSID         MT�ỰID 
* @return   u32    0����ȡ�ɹ�  ����������
*
* @note ����֪ͨ��Ev_MtApi_Diagnose_SetIspImgDigDynLevel_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseSetDigDynLevelCmd( IN CONST u32 dwValue, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_DiagnoseGetDigDynLevelReq
*
* @brief   Isp���ֿ�̬�ȼ����󣨽�Embed��
*
* @param    [in]   dwSSID         MT�ỰID 
* @return   u32    0����ȡ�ɹ�  ����������
*
* @note ����֪ͨ��Ev_MtApi_Diagnose_GetIspImgDigDynLevel_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetDigDynLevelReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_DiagnoseGetDigDynLevel
*
* @brief   Isp���ֿ�̬�ȼ���ȡ����Embed��
*
* @param    [out]   dwValue       �ȼ�ֵ
* @param    [in]   dwSSID         MT�ỰID 
* @return   u32    0����ȡ�ɹ�  ����������
*
* @note ����֪ͨ��no
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetDigDynLevel( OUT u32 &dwValue, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_DiagnoseSetIspGammaCmd
*
* @brief   Isp٤�����ã���Embed��
*
* @param    [in]   dwValue        ٤����ֵ
* @param    [in]   dwSSID         MT�ỰID 
* @return   u32    0����ȡ�ɹ�  ����������
*
* @note ����֪ͨ��Ev_MtApi_Diagnose_SetIspImgGamma_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseSetIspGammaCmd( IN CONST u32 dwValue, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_DiagnoseGetIspGammaReq
*
* @brief   Isp٤���ȡ���󣨽�Embed��
*
* @param    [in]   dwSSID         MT�ỰID 
* @return   u32    0����ȡ�ɹ�  ����������
*
* @note ����֪ͨ��Ev_MtApi_Diagnose_GetIspImgGamma_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetIspGammaReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_DiagnoseGetIspGamma
*
* @brief   Isp٤���ȡ����Embed��
*
* @param    [out]   dwValue        ٤����ֵ
* @param    [in]    dwSSID         MT�ỰID 
* @return   u32     0����ȡ�ɹ�  ����������
*
* @note ����֪ͨ��no
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetIspGamma( OUT u32 &dwValue, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_DiagnoseSetIspDefogCmd
*
* @brief   Isp����ȥ�����ã���Embed��
*
* @param    [in]   dwValue        ȥ����ֵ
* @param    [in]   dwSSID         MT�ỰID 
* @return   u32    0����ȡ�ɹ�  ����������
*
* @note ����֪ͨ��Ev_MtApi_Diagnose_SetIspImgDefog_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseSetIspDefogCmd( IN CONST u32 dwValue, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_DiagnoseGetIspDefogReq
*
* @brief   Isp����ȥ���ȡ���󣨽�Embed��
*
* @param    [in]   dwSSID         MT�ỰID 
* @return   u32    0����ȡ�ɹ�  ����������
*
* @note ����֪ͨ��Ev_MtApi_Diagnose_GetIspImgDefog_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetIspDefogReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_DiagnoseGetIspDefog
*
* @brief   Isp����ȥ���ȡ����Embed��
*
* @param    [out]   dwValue        ȥ����ֵ
* @param    [in]   dwSSID         MT�ỰID 
* @return   u32    0����ȡ�ɹ�  ����������
*
* @note ����֪ͨ��no
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetIspDefog( OUT u32 &dwValue, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_DiagnoseSetOsdDisplayCmd
*
* @brief   ����osd�����Ƿ�رգ������ã�
*
* @param    [in]   bOpen          TRUEΪ�򿪣�FALSEΪ�ر�
* @param    [in]   dwSSID         MT�ỰID 
* @return   u32    0����ȡ�ɹ�  ����������
*
* @note ����֪ͨ��Ev_MtApi_Diagnose_SetOsdOpen_Ntf �� Ev_MtApi_Diagnose_SetOsdClose_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseSetOsdDisplayCmd( IN CONST BOOL32 bOpen, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_DiagnoseSetCameraImgInfoCmd
*
* @brief   ���������ͼ��ģʽ�������������
*
* @param    [in]   tInfo          ͼ����Ϣ
* @param    [in]   dwSSID         MT�ỰID 
* @return   u32    0����ȡ�ɹ�  ����������
*
* @note ����֪ͨ��Ev_MtApi_Diagnose_SetCameraImgMode_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseSetCameraImgInfoCmd( IN CONST TMtCameraImgInfo_Api tInfo, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_DiagnoseSetAiCameraCmd
*
* @brief   �����������������
*
* @param    [in]   tInfo          �������Ϣ
* @param    [in]   dwSSID         MT�ỰID 
* @return   u32    0����ȡ�ɹ�  ����������
*
* @note ����֪ͨ��Ev_MtApi_Diagnose_SetAiCamera_Ntf ֪ͨ����������Ϣ
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseSetAiCameraCmd( IN CONST TMtHDCameraAiList_Api &tInfo, IN CONST SessionID dwSSID /*= KMTAPI_DEF_SSID*/ );


/**
* KdvMt_DiagnoseGetCameraImgInfoReq
*
* @brief   ���������ͼ��ģʽ��Ϣ�������������
*
* @param    [in]   dwSSID         MT�ỰID 
* @return   u32    0����ȡ�ɹ�  ����������
*
* @note ����֪ͨ��Ev_MtApi_Diagnose_GetCameraImgMode_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetCameraImgInfoReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_DiagnoseGetCameraImgInfo
*
* @brief   ��ȡ�����ͼ��ģʽ��Ϣ�������������
*
* @param    [out]   tInfo          ͼ����Ϣ
* @param    [in]   dwSSID         MT�ỰID 
* @return   u32    0����ȡ�ɹ�  ����������
*
* @note ����֪ͨ��no
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetCameraImgInfo( OUT TMtCameraImgInfo_Api &tInfo, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_DiagnoseSetCameraPersonFirstCmd
*
* @brief   ����������������ȿ��أ������������
*
* @param    [in]   bOn            ��/��
* @param    [in]   dwSSID         MT�ỰID 
* @return   u32    0����ȡ�ɹ�  ����������
*
* @note ����֪ͨ��Ev_MtApi_Diagnose_SetCameraPersonFirst_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseSetCameraPersonFirstCmd( IN CONST BOOL32 bOn, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_DiagnoseGetCameraPersonFirstReq
*
* @brief   ����������������ȿ��أ������������
*
* @param    [in]   dwSSID         MT�ỰID 
* @return   u32    0����ȡ�ɹ�  ����������
*
* @note ����֪ͨ��Ev_MtApi_Diagnose_GetCameraPersonFirst_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetCameraPersonFirstReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_DiagnoseGetCameraPersonFirst
*
* @brief   ��ȡ������������ȿ��أ������������
*
* @param    [out]  bOn            ��/��
* @param    [in]   dwSSID         MT�ỰID 
* @return   u32    0����ȡ�ɹ�  ����������
*
* @note ����֪ͨ��no
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetCameraPersonFirst( OUT BOOL32 &bOn, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/* KdvMt_SetShowRmtAssVidCmd
* 
* @brief   ����˫��ģʽ��˫���µڶ����Ƿ���ʾԶ�˸����������ã�
*
* @param    [in]   bShow       TRUE:��ʾ  FALSE:����ʾ
* @param    [in]   dwSSID       MT�ỰID 
* @return   u32    ��������ͽ��
*
* @note ��Ӧ֪ͨ��no
*/
KdvMtAPI u32 KdvMtCALL KdvMt_SetShowRmtAssVidCmd( IN CONST BOOL32 bShow, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_DiagnoseSetCameraSceneModeCmd
*
* @brief   �������������ģʽ����
*
* @param    [in]   dwVidIdx		��������
* @param    [in]   emSceneMode  ����ģʽ����
* @param    [in]   dwSSID         MT�ỰID 
* @return   u32    0����ȡ�ɹ�  ����������
*
* @note ����֪ͨ��Ev_MtApi_Diagnose_SetCameraSceneMode_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseSetCameraSceneModeCmd( IN CONST u32 dwVidIdx, IN CONST EmCameraSceneMode_Api emSceneMode, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_DiagnoseGetCameraSceneModeReq
*
* @brief   �������������ģʽ����
*
* @param    [in]   dwVidIdx		��������
* @param    [in]   dwSSID         MT�ỰID 
* @return   u32    0����ȡ�ɹ�  ����������
*
* @note ����֪ͨ��Ev_MtApi_Diagnose_GetCameraSceneMode_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetCameraSceneModeReq( IN CONST u32 dwVidIdx, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_DiagnoseGetCameraUpgradePackReq
*
* @brief   ����ͷ���������ƻ�ȡ����
*
* @param    [in]   emVidPort      ��ƵԴ�˿�
* @param    [in]   dwSSID         MT�ỰID 
* @return   u32    0����ȡ�ɹ�  ����������
*
* @note ����֪ͨ��Ev_MtApi_Diagnose_GetCameraUpgradePack_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_Diagnose_GetCameraUpgradePackReq( IN CONST EmMtVideoPort_Api emVidPort, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_DiagnoseSetLocalAssAudExpCmd
*
* @brief   ���ظ�����������
*
* @param    [in]   bOpen		����/�ر�
* @param    [in]   dwSSID       MT�ỰID 
* @return   u32    0����ȡ�ɹ�  ����������
*
* @note ����֪ͨ��Ev_MtApi_Diagnose_SetLocalAssAudExp_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseSetLocalAssAudExpCmd( IN CONST BOOL32 bOpen, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_DiagnoseGetLocalAssAudExpReq
*
* @brief   ���ظ���������ȡ����
*
* @param    [in]   dwSSID       MT�ỰID 
* @return   u32    0����ȡ�ɹ�  ����������
*
* @note ����֪ͨ��Ev_MtApi_Diagnose_GetLocalAssAudExp_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetLocalAssAudExpReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_DiagnoseGetLocalAssAudExp
*
* @brief   ���ظ���������ȡ
*
* @param    [out]  bOpen        ����/�ر�
* @param    [in]   dwSSID       MT�ỰID 
* @return   u32    0����ȡ�ɹ�  ����������
*
* @note ����֪ͨ��no
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetLocalAssAudExp( OUT BOOL32 &bOpen, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_DiagnoseExportDiagInfoFileCmd
*
* @brief   ���������Ϣ�ļ�����
*
* @param    [in]   pchFilePath      �����ļ���·�� 
* @param    [in]   dwSSID			MT�ỰID 
* @return   u32    0����ȡ�ɹ�  ����������
*
* @note ����֪ͨ��Ev_MtApi_Diagnose_ExportDiagInfoFile_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseExportDiagInfoFileCmd( IN CONST s8 *pchFilePath, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_DiagnoseGetPacketDurationTimeReq
*
* @brief   ��ȡ��ǰץ������ʱ������
*
* @param    [in]   dwSSID			MT�ỰID 
* @return   u32    0����ȡ�ɹ�  ����������
*
* @note ����֪ͨ��Ev_MtApi_Diagnose_GetPacketDurationTime_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetPacketDurationTimeReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_DiagnoseElectricFanCmd
*
* @brief   ����

* @param    [in]   bElectricFan      �Ƿ���� 
* @param    [in]   dwSSID			MT�ỰID 
* @return   u32    0����ȡ�ɹ�  ����������
*
* @note ����֪ͨ��Ev_MtApi_Diagnose_ElectricFan_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseElectricFanCmd( IN CONST BOOL32 bElectricFan, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_DiagnoseElectricFanCmd
*
* @brief   ��ȡ����ʣ��ʱ������
 
* @param    [in]   dwSSID			MT�ỰID 
* @return   u32    0����ȡ�ɹ�  ����������
*
* @note ����֪ͨ��Ev_MtApi_Diagnose_GetElectricFanTime_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetElectricFanTimeReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_DiagnoseCleanUpdateSpaceCmd
* 
* @brief  �����������洢�ռ������(webmtc��)
*  
* @param    [in]   dwSSID  MT�ỰID 
* @return   u32   ��������ͽ��
*
* @note ����֪ͨ:	Ev_MtApi_Diagnose_CleanUpdateSpace_Ntf   
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseCleanUpdateSpaceCmd( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**@}*/

/**@}*/
#endif //_MTAPI_DIAGNOSEAPI_H_
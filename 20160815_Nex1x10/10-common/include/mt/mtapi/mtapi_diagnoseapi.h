/*******************************************************************************//**
*@file          mtapi_diagnoseapi.h
*@brief         提供mtdiagnoseapi对外接口
*
*@author        ruiyigen
*@version       5.0    
*@date          20150328
*@copyright     (c)1995-2015 Suzhou Keda Technology Co.,Ltd. All rights reserved
***********************************************************************************/
#ifndef _MTAPI_DIAGNOSEAPI_H_
#define _MTAPI_DIAGNOSEAPI_H_
/**@addtogroup api API接口
*@{
*/

/**@addtogroup dgapi 诊断API
*@{
*/

#include <string.h>
#include "mtapi_export.h"
#include "mtapi_typedef.h"
#include "mtapi_struct.h"


/**
* KdvMt_DiagnoseIsInited
*
* @brief mtDiagnoseapi是否进行过初始化
*
* @param	[in] void
* @return	BOOL32  TRUE ： 已初始化， FALSE：尚未初始化
* @note MTDiagnoseAPI_DiagnoseInitalize, KdvMt_DiagnoseUnInitalize
*/
KdvMtAPI BOOL32 KdvMtCALL KdvMt_DiagnoseIsInited();

/**
* KdvMt_DiagnoseSetNotify
*
* @brief  注册Observer(UI)通知回调
*
* @param    [in]  注册Observer(UI)通知回调(这个函数如果没有调用则使用mtbaseapi中的回调函数)
* @return   void
* @note
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseSetNotify( IN NOTIFY_OBSERVER_CALLBACK cbNotify );

/**
* KdvMt_DiagnoseInitalize
*
* @brief mtdiagnoseapi模块初始化
*
* @return	u32  0: 初始化成功， 非0: 初始化失败
* @note KdvMt_DiagnoseIsInited, KdvMt_DiagnoseUnInitalize
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseInitalize( );



/**
* KdvMt_DiagnoseUnInitalize
*
* @brief mtdiagnoseapi模块释放退出
*
* @param	[in] void
* @return	u32  0: 成功， 非0: 失败
* @note KdvMt_DiagnoseIsInited, KdvMt_DiagnoseInitalize
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseUnInitalize();


/** 
* KdvMt_DiagnoseCallGetPortInfoReq
*
* @brief  请求端口使用信息
*
* @param    [in]   dwSSID  MT会话ID 
* @return    u32   请求命令发送结果
*
* @note 响应通知：Ev_MtApi_DiagnoseGetPortInfo_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseCallGetPortInfoReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/** 
* KdvMt_DiagnoseCallGetPortInfo
*
* @brief  获取端口使用信息
*
* @param    [out]  tPortInfo 端口信息
* @param    [in]   dwSSID    MT会话ID 
* @return    u32   请求命令发送结果
*
* @note 响应通知：Ev_MtApi_DiagnoseGetPortInfo_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseCallGetPortInfo( OUT TMTTotalUsedPort_Api &tPortInfo, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/** 
* KdvMt_DiagnoseCallStatisticsInfoReq
*
* @brief  获取编解码、混音、合成、网络统计信息请求
*
* @param    [in]   dwSSID    MT会话ID 
* @return    u32   请求命令发送结果
*
* @note 响应通知：Ev_MtApi_DiagnoseCodecGetStatistic_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseCallStatisticsInfoReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/** 
* KdvMt_DiagnoseGetCallStatisticsInfo
*
* @brief  获取编解码、混音、合成、网络统计信息
*
* @param    [out]  tStatistic 统计信息
* @param    [in]   dwSSID    MT会话ID 
* @return    u32   请求命令发送结果
*
* @note 响应通知:
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetCallStatisticsInfo( OUT TMtCodecStatistic_Api &tStatistic, IN CONST SessionID dwSSID );

/** 
* KdvMt_DiagnoseAudioOutPowerTestCmd
*
* @brief  扬声器诊断
*
* @param    [in]   emCodecType  codec 类型
* @param    [in]   emStreamIdx  第几路码流
* @param    [in]   bStart  是否开始 
* @param    [in]   dwSSID  MT会话ID 
* @return    u32   请求命令发送结果
*
* @note 响应通知：Ev_MtApi_Diagnose_CodecAudOutPower_Ntf(bStart为TRUE的时候回应，为FALSE的时候不回应)
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseAudioOutPowerTestCmd( IN CONST EmCodecComponent_Api emCodecType,IN CONST EmCodecComponentIndex_Api emStreamIdx, IN CONST BOOL32 bStart, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/** 
* KdvMt_DiagnoseGetAudioOutPower
*
* @brief  获取扬声器能量值
*
* @param    [out]  tPower  解码器ID及能量值
* @param    [in]   dwSSID  MT会话ID 
* @return    u32   请求命令发送结果
*
* @note 响应通知：Ev_MtApi_Diagnose_CodecAudOutPower_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetAudioOutPower( OUT TMTAudioPower_Api &tPower, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/** 
* KdvMt_DiagnoseAudioInPowerTestCmd
*
* @brief  麦克风诊断
* @param    [in]   emCodecType  codec 类型
* @param    [in]   emStreamIdx  第几路码流
* @param    [in]   bStart  是否开始 
* @param    [in]   dwSSID  MT会话ID 
* @return    u32   请求命令发送结果
*
* @note 响应通知：Ev_MtApi_Diagnose_CodecAudInPower_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseAudioInPowerTestCmd( IN CONST EmCodecComponent_Api emCodecType, IN CONST EmCodecComponentIndex_Api emStreamIdx, IN CONST BOOL32 bStart, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/** 
* KdvMt_DiagnoseGetAudioInPower
*
* @brief  获取麦克风能量值
*
* @param    [out] tPower  编码器ID及能量值 
* @param    [in]     dwSSID  MT会话ID 
* @return    u32     请求命令发送结果
*
* @note 响应通知：Ev_MtApi_Diagnose_CodecAudInPower_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetAudioInPower( OUT TMTAudioPower_Api &tPower, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/** 
* KdvMt_DiagnoseSingleLocalLoopBackTestCmd
*
* @brief  本地回环测试
*
* @param    [in]   bLoopBack  是否自环 
* @param    [in]   EmCodecComponentIndex_Api  编解码器ID 
* @param    [in]   EmCodecComponent_Api  编解码器类型
* @param    [in]   dwSSID     MT会话ID 
* @return    u32   请求命令发送结果
*
* @note 响应通知：Ev_MtApi_Diagnose_LocalSingleLoop_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseSingleLocalLoopBackTestCmd( IN CONST BOOL32 bLoopBack, IN CONST EmCodecComponentIndex_Api emCodecId, IN CONST EmCodecComponent_Api emCodecType, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID  );

/** 
* KdvMt_DiagnoseLocalLoopBackTestCmd
*
* @brief  本地回环测试
*
* @param    [in]   bLoopBack  是否自环 
* @param    [in]   dwSSID     MT会话ID 
* @return    u32   请求命令发送结果
*
* @note 响应通知：Ev_MtApi_Diagnose_LocalLoop_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseLocalLoopBackTestCmd( IN CONST BOOL32 bLoopBack, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID  );


/** 
* KdvMt_DiagnoseRemoteLoopTestCmd
*
* @brief  远端回环测试
*
* @param    [in]   bFarLoop  是否自环 
* @param    [in]   dwSSID     MT会话ID 
* @return    u32   请求命令发送结果
*
* @note 响应通知：Ev_MtApi_Diagnose_RemoteLoop_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseRemoteLoopTestCmd( IN CONST BOOL32 bFarLoop, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/** 
* KdvMt_DiagnoseRibbonTestCmd
*
* @brief  色带测试(仅Embed)
*
* @param    [in]   bTest      开始/停止测试 
* @param    [in]   dwSSID     MT会话ID 
* @return    u32   请求命令发送结果
*
* @note 响应通知：
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseRibbonTestCmd( IN CONST BOOL32 bTest, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/** 
* KdvMt_DiagnoseAutoAudioDelayCheckCmd
*
* @brief  自动声音时延检测命令(仅Embed)
*
* @param    [in]   bStart      开始/停止
* @param    [in]   dwSSID     MT会话ID 
* @return    u32   请求命令发送结果
*
* @note 响应通知：
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseAutoAudioDelayCheckCmd( IN CONST BOOL32 bStart, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_IsInRibbonTesting
*
* @brief   是否在色带测试中(仅Embed)
*
* @param    [out]  bInRibbonTesting TRUE:测试中 FALSE:未测试中
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    0：获取成功  其他错误码
*
* @note 更新通知：Ev_MtApi_Vc_CodecRibbonTest_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_IsInRibbonTesting( OUT BOOL32& bInRibbonTesting, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID ); 

/** 
* KdvMt_TerminalGetServerInfoReq
*
* @brief  请求服务器信息
*
* @param    [in]   dwSSID  MT会话ID 
* @return    u32   请求命令发送结果
*
* @note 响应通知：Ev_MtApi_DiagnoseGetSrvInfo_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_TerminalGetServerInfoReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/** 
* KdvMt_TerminalGetServerInfo
*
* @brief  获取服务器运行状态
* @param    [out]  tSrvInfo 服务器信息
* @param    [in]   dwSSID   MT会话ID 
* @return    u32   请求命令发送结果
*
* @note 响应通知：Ev_MtApi_DiagnoseGetSrvInfo_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_TerminalGetServerInfo( OUT TMTSrvInfoList_Api & tSrvInfo, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/** 
* KdvMt_TerminalGetMtRunTimeReq
*
* @brief  请求系统运行时间
*
* @param    [in]   dwSSID  MT会话ID 
* @return    u32   请求命令发送结果
*
* @note 响应通知：Ev_MtApi_DiagnoseGetMTRunTime_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_TerminalGetMtRunTimeReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/** 
* KdvMt_TerminalGetMtTerInfoReq
*
* @brief  获取终端信息
*
* @param    [in]   dwSSID  MT会话ID 
* @return    u32   请求命令发送结果
*
* @note 响应通知：Ev_MtApi_DiagnoseGetTerInfo_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_TerminalGetMtTerInfoReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/** 
* KdvMt_TerminalGetMtRunTime
*
* @brief  获取系统运行时间
* @param    [out]  dwTime  系统运行时间
* @param    [in]   dwSSID  MT会话ID 
* @return    u32   请求命令发送结果
*
* @note 响应通知：Ev_MtApi_DiagnoseGetMTRunTime_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_TerminalGetMtRunTime( OUT u32 &dwTime, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_TerminalGetTerInfo 
* 
* @brief 获取终端信息(型号,版本号,厂商)
* 
* @param	[in] tTerInfo 终端信息
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：
*/
KdvMtAPI u32 KdvMtCALL KdvMt_TerminalGetTerInfo(  OUT TTerminalInfo_Api & tTerInfo, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_DTStartNetCaptureCmd 
* 
* @brief 开启抓包命令
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_NetCaptureState_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DTStartNetCaptureCmd( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_DTExportNetCaptureReq 
* 
* @brief 导出抓包文件请求
* 
* @param    [in] pchExportPath  导出抓包文件路径
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_ExportNetCapture_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DTExportNetCaptureReq( IN CONST s8 *pchExportPath, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_DTStopNetCaptureCmd 
* 
* @brief 停止抓包命令
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_NetCaptureState_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DTStopNetCaptureCmd( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_DTExportLogReq 
* 
* @brief 导出日志文件请求
*
* @param    [in] pchExportPath  导出文件路径
* @param    [in] dwSSID         MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_ExportLog_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DTExportLogReq( IN CONST s8 *pchExportPath, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_DTBandwidthCheckCmd 
* 
* @brief 带宽检测命令
*
* @param    [in] dwIp	带宽检测服务端ip
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_BandwidthTestResult_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DTBandwidthCheckCmd( IN u32 dwIp, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_GetNetCaptureState 
* 
* @brief 获取当前终端网络抓包状态
* 
* @param    [out] dwSSID  抓包状态
* @param    [in]  dwSSID  MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MtApi_Base_NetCaptureState_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DTGetNetCaptureState( OUT TMtNetCapStateInfo_Api& tStateInfo, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_GetBandwidthTestResult 
* 
* @brief 获取带宽检测结果
* 
* @param    [out]  tNetState    MT带宽检测信息 
* @param    [in]   dwSSID       MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MtApi_Base_BandwidthTestResult_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DTGetBandwidthTestResult( OUT TMTNetStatus_Api& tNetState, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_DiagnoseAudioInVolumeReq 
* 
* @brief 音频输入音量查询请求
* 
* @param    [in]   dwSSID       MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MtApi_MtmpAudioInVolume_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseAudioInVolumeReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_DiagnoseGetAudioInVolume 
* 
* @brief 获取音频输入音量
* 
* @param    [out]  dwAudInVol   输入音量
* @param    [in]   dwSSID       MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知 无
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetAudioInVolume( OUT u32 & dwAudInVol, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_DiagnoseAudioInputStateReq 
* 
* @brief 音频输入接口状态查询请求（仅embed）
* 
* @param    [out]  tAudInputState  输入接口状态
* @param    [in]   dwSSID       MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MtApi_MtmpAudioInputState_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseAudioInputStateReq( IN CONST TMultiAudInputState_Api & tAudInputState, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_DiagnoseGetAudioInputState 
* 
* @brief 获取音频输入接口状态
* 
* @param    [out]  tAudInputState 输入接口状态
* @param    [in]   dwSSID       MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：无
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetAudioInputState( OUT TMultiAudInputState_Api & tAudInputState, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_DiagnoseAudioOutputStateReq 
* 
* @brief 音频输出接口状态查询请求
* 
* @param    [out]  tAudOutputState  输出接口状态
* @param    [in]   dwSSID       MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MtApi_MtmpAudioOutputState_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseAudioOutputStateReq( IN CONST TMultiAudOutputState_Api & tAudOutputState, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_DiagnoseGetAudioOutputState 
* 
* @brief 获取音频输出接口状态
* 
* @param    [out]  tAudOutputState  输出接口状态
* @param    [in]   dwSSID       MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：无
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetAudioOutputState( TMultiAudOutputState_Api & tAudOutputState, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_DiagnoseVideoInPortCapReq 
* 
* @brief 视频接口能力查询请求(仅embed)
* 
* @param    [in]   dwSSID       MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MtApi_MtmpVideoInPortCap_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseVideoInPortCapReq ( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_DiagnoseGetSdiInOutReq 
* 
* @brief 查询SDI接口数量请求
* 
* @param    [in]   dwSSID       MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MtApi_MtmpGetSdiInOut_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetSdiInOutReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_DiagnoseMicVolumeDetectReq 
* 
* @brief 麦克音量查询请求
* 
* @param    [in]   dwSSID       MT会话ID 
            [in]   s32: 枚举值
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MtApi_MtmpMicVolumeDetect_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseMicVolumeDetectReq( IN CONST EmHDAudPortIn_Api emAudPortIn, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_DiagnoseGetSdiInOutValue 
* 
* @brief 获取SDI接口数量
*
* @param    [OUT]   emSdiInOut    SDI接口数量
* @param    [in]   dwSSID       MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetSdiInOutValue( OUT EmSdiInOut_Api & emSdiInOut,IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_DiagnoseGetVideoInRes 
* 
* @brief 获取视频接口能力列表
* 
* @param    [out]  tVidRes     视频接口能力列表
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：无
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetVidInPortCapList( TMTHDVidInPortCapList_Api & tVidRes, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );
/**
*  KdvMt_DiagnoseCpuMemUseInfoReq 
* 
* @brief CPU以及内存使用情况查询
* 
* @param    [in]   dwSSID       MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MTApi_DeviceDetectCpuAndMem_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseCpuMemUseInfoReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_DiagnoseGetVideoInRes 
* 
* @brief 获取CPU以及内存使用情况
* 
* @param    [out]  tVidRes     CPU以及内存使用情况
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：无
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseCpuMemUseInfo( TMTCpuAndMemState_Api & tInfo, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_DiagnoseGetLocalLoopStateReq 
* 
* @brief 获取本地自环状态
*	
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MTApi_Diagnose_LocalLoopState_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetLocalLoopStateReq(IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_DiagnoseGetVidSrcStatusReq 
* 
* @brief 视频源分辨率查询
*	
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MTApi_Diagnose_VidSrcStatus_Rsp, Ev_MTApi_Diagnose_VidSrcStatus_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetVidSrcStatusReq(IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_DiagnoseGetRibbonTestStatusReq 
* 
* @brief 色带测试状态查询请求
*	
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MTApi_Diagnose_RibbonTestStatus_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetRibbonTestStatusReq(IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/*******************************************************************************//**
*@brief        获取U盘状态信息(仅Embed)
*
*@param[in]     dwSSID  MT会话ID 
*@return        u32   请求命令发送结果
*@note          响应通知：Ev_MtApi_Diagnose_GetUsbStatusRt_Rsp, Ev_MtApi_Diagnose_GetUsbStatusRt_Ntf
***********************************************************************************/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetUsbStatusReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/*******************************************************************************//**
*@brief        目录结构查询(仅Embed)
*
*@param[in]		pchSrcPath 目录结构
*@param[in]     dwSSID  MT会话ID 
*@return        u32   请求命令发送结果
*@note          响应通知：Ev_MtApi_Diagnose_InquirePathStructure_Rsp
***********************************************************************************/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseInquirePathStructureReq( IN CONST s8 *pchSrcPath, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/*******************************************************************************//**
*@brief        查询视频输入接口的分辨率以及各接口是否有信号(仅Embed)
*
*@param[in]     dwSSID  MT会话ID 
*@return        u32   请求命令发送结果
*@note          响应通知：Ev_MtApi_Diagnose_GetVidInPortRes_Rsp、Ev_MtApi_Diagnose_GetVidInPortRes_Ntf
***********************************************************************************/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetVidInPortResReq(SessionID dwSSID = KMTAPI_DEF_SSID);

/*******************************************************************************//**
*@brief        查询EPLD/CPLD版本(仅Embed)
*
*@param[in]     dwSSID  MT会话ID 
*@return        u32   请求命令发送结果
*@note          响应通知：Ev_MtApi_Diagnose_InquirePldVersion_Rsp
***********************************************************************************/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseInquirePldVersionReq(SessionID dwSSID = KMTAPI_DEF_SSID);

/*******************************************************************************//**
*@brief        获取EPLD/CPLD版本(仅Embed)
*
*@param[out]   dwVersion  版本号
*@param[in]     dwSSID  MT会话ID 
*@return        u32   请求命令发送结果
*@note          响应通知：
***********************************************************************************/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetPldVersion(OUT u32 &dwVersion, SessionID dwSSID = KMTAPI_DEF_SSID);

/*******************************************************************************//**
*@brief        查询FPGA版本(仅Embed)
*
*@param[in]     dwSSID  MT会话ID 
*@return        u32   请求命令发送结果
*@note          响应通知：Ev_MtApi_Diagnose_InquireFpgaVersion_Rsp
***********************************************************************************/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseInquireFpgaVersionReq(SessionID dwSSID = KMTAPI_DEF_SSID);


/*******************************************************************************//**
*@brief        新的查询FPGA版本(仅Embed)
*
*@param[in]     dwSSID  MT会话ID 
*@return        u32   请求命令发送结果
*@note          响应通知：Ev_MtApi_Diagnose_NewInquireFpgaVersion_Rsp
***********************************************************************************/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseNewInquireFpgaVersionReq(SessionID dwSSID = KMTAPI_DEF_SSID);

/*******************************************************************************//**
*@brief        获取FPGA1版本(仅Embed)
*
*@param[out]   dwVersion  版本号
*@param[in]     dwSSID  MT会话ID 
*@return        u32   请求命令发送结果
*@note          响应通知：
***********************************************************************************/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetFpga1Version(OUT u32 &dwVersion, SessionID dwSSID = KMTAPI_DEF_SSID);

/*******************************************************************************//**
*@brief        获取FPGA2版本(仅Embed)
*
*@param[out]   dwVersion  版本号
*@param[in]     dwSSID  MT会话ID 
*@return        u32   请求命令发送结果
*@note          响应通知：
***********************************************************************************/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetFpga2Version(OUT u32 &dwVersion, SessionID dwSSID = KMTAPI_DEF_SSID);

/*******************************************************************************//**
*@brief        查询终端程序是否全部启动成功请求(仅Embed)
*
*@param[in]     dwSSID  MT会话ID 
*@return        u32   请求命令发送结果
*@note          响应通知：Ev_MtApi_Diagnose_InquireHDMtStartSucess_Rsp, Ev_MtApi_Diagnose_HDMtStartSucess_Ntf
***********************************************************************************/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseInquireHDMtStartSucessReq(SessionID dwSSID = KMTAPI_DEF_SSID);

/*******************************************************************************//**
*@brief        检查文件是否存在
*@param[in]     pchPath  查找起始目录
*@param[in]     pchName  查找文件名
*@param[in]     bRecurse  是否查找所有子目录
*@param[in]     dwSSID  MT会话ID 
*@return        u32   请求命令发送结果
*@note          响应通知：
***********************************************************************************/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseCheckFileIsExistReq(IN CONST s8 *pchPath, IN CONST s8 *pchName, IN CONST BOOL32 &bRecurse, SessionID dwSSID = KMTAPI_DEF_SSID);

/*******************************************************************************//**
*@brief        导出地址簿请求
*@param[in]     pchPath  导出目标路径
*@param[in]     dwSSID  MT会话ID 
*@return        u32   请求命令发送结果
*@note          响应通知：Ev_MtApi_Diagnose_AddrBookExport_Rsp Ev_MtApi_Diagnose_AddrBookExportProgress_Ntf
***********************************************************************************/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseExportAddrBookReq(IN CONST s8 *pchPath, SessionID dwSSID = KMTAPI_DEF_SSID);

/*******************************************************************************//**
*@brief        导入地址簿请求
*@param[in]     pchPath  导入源路径(带文件名)
*@param[in]     dwSSID  MT会话ID 
*@return        u32   请求命令发送结果
*@note          响应通知：Ev_MtApi_Diagnose_AddrBookImport_Rsp Ev_MtApi_Diagnose_AddrBookImportProgress_Ntf
***********************************************************************************/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseImportAddrBookReq(IN CONST s8 *pchPath, SessionID dwSSID = KMTAPI_DEF_SSID);

/**
*  KdvMt_DiagnoseGetLocalLoopStateReq 
* 
* @brief 获取视频 远端自环状态请求
*	
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MTApi_Diagnose_RemoteLoopState_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetRemoteLoopStateReq(IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_DiagnoseGetAudRmtLoopStateReq 
* 
* @brief 获取音频 远端自环状态请求
*	
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MTApi_Diagnose_AudRmtLoopState_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetAudRmtLoopStateReq(IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_DiagnoseGetMicrophoneConnectStatusReq 
* 
* @brief 麦克风连接状态请求
*	
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MTApi_Diagnose_MicrophoneConnectStatus_Rsp Ev_MTApi_Diagnose_MicrophoneConnectStatus_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetMicrophoneConnectStatusReq(IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_DiagnoseGetMicrophoneBatteryLevelReq 
* 
* @brief 麦克风无线电量请求
*	
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MTApi_Diagnose_MicrophoneBatteryLevel_Rsp Ev_MTApi_Diagnose_MicrophoneBatteryLevel_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetMicrophoneBatteryLevelReq(IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_DiagnoseGetMicrophoneVersionStatusReq 
* 
* @brief 麦克风更新包上传状态请求
*	
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MTApi_Diagnose_MicrophoneVersionStatus_Rsp Ev_MTApi_Diagnose_MicrophoneVersionStatus_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetMicrophoneVersionStatusReq(IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_DiagnoseMicrophoneUpgradeCmd 
* 
* @brief 麦克风升级命令
*	
* @param    [in]   tStatus       麦克状态
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MTApi_Diagnose_MicrophoneUpgrade_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseMicrophoneUpgradeCmd(IN CONST TMTAllMicStatus_Api tStatus, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_DiagnoseOpenHotspotReq 
* 
* @brief 开启射频热点请求
*	
* @param    [in]   tStatus       麦克状态
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MTApi_Diagnose_OpenHotspot_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseOpenHotspotReq(IN CONST TMTAllMicStatus_Api tStatus, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_DiagnoseGetHotspotStatusReq 
* 
* @brief 射频状态请求
*	
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MTApi_Diagnose_GetHotspotStatus_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetHotspotStatusReq(IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_DiagnoseSetOsdTransparentReq 
* 
* @brief OSD穿透开关请求
*	
* @param    [in]   bTrans       TRUE:开，FALSE: 关
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MTApi_Diagnose_SetOsdTransparent_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseSetOsdTransparentReq(IN CONST BOOL32 bTrans, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_DiagnoseSetOsdSnapShotBrowseStateCmd 
* 
* @brief OSD界面是否在浏览快照
*	
* @param    [in]   bTrans       TRUE:是，FALSE: 否
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MTApi_Diagnose_OsdSnapshotBrowse_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseSetOsdSnapShotBrowseStateCmd(IN CONST BOOL32 bBrowse, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_DiagnoseSetSyncTooltipBoxCmd 
* 
* @brief 提示框同步命令
*	
* @param    [in]   pchUserId  用户ID
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MTApi_Diagnose_SyncTooltipBox_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseSetSyncTooltipBoxCmd(IN CONST s8 *pchUserId, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_DiagnoseGetNetCapFileListReq 
* 
* @brief 获取抓包文件列表请求
*	
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MTApi_Diagnose_GetNetCapFileList_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetNetCapFileListReq(IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_DiagnoseDeleteNetCapFileCmd 
* 
* @brief 删除抓包文件
*	
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseDeleteNetCapFileCmd(IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_DiagnoseGetMicrophoneVersionReq 
* 
* @brief 请求麦克版本信息
*	
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MTApi_Diagnose_GetMicrophoneVerInfo_Rsp、Ev_MTApi_Diagnose_MicrophoneVerInfo_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetMicrophoneVersionReq(IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_DiagnoseResetUserFileimgCmd 
* 
* @brief 重置/user/fileimg中的版本包
*	
* @param    [in]   dwFileType      需要重置的版本包 1: wind3d.bin.tar ; 2: skyshare_setup.tar
* @param    [in]   dwSSID            MT会话ID 
* @return   u32  0：成功, 其他：错误码 
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseResetUserFileimgCmd(IN CONST u32 dwFileType, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_DiagnoseGetCurCapStatusReq 
* 
* @brief 获取当前抓包状态
*
* @param    [in]   dwSSID            MT会话ID 
* @return   u32  0：成功, 其他：错误码 
*
* @note 更新通知：Ev_MTApi_Diagnose_GetCurCapStatus_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetCurCapStatusReq(IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_DiagnoseServerLinkTestCmd
* 
* @brief 登录服务器连接测试
*
* @param    [in]   bStart               TRUE:开始 FALSE:停止
* @param    [in]   dwSSID            MT会话ID 
* @return   u32  0：成功, 其他：错误码 
*
* @note 更新通知：Ev_MTApi_Diagnose_ServerTest_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseServerLinkTestCmd(IN CONST BOOL32 bStart, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_DiagnoseThreadDetectRegCmd
* 
* @brief 注册一个需要检测的模块
*
* @param    [in]   tInfo                 模块信息
* @param    [in]   dwSSID            MT会话ID 
* @return   u32  0：成功, 其他：错误码 
*
* @note 更新通知：无
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseThreadDetectRegCmd(IN CONST TMTServiceInfo_Api tInfo, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_DiagnoseThreadDetectUpdateCmd
* 
* @brief 更新一个已注册模块的信息
*
* @param    [in]   dwAppId          模块的APP ID
* @param    [in]   dwSSID            MT会话ID 
* @return   u32  0：成功, 其他：错误码 
*
* @note 更新通知：无
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseThreadDetectUpdateCmd(IN CONST u32 dwAppId, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_DiagnoseMicrophoneStateReq
* 
* @brief <<麦克风状态请求>>
*
* @param    [in]   dwSSID            MT会话ID 
* @return   u32  0：成功, 其他：错误码 
*
* @note 更新通知：Ev_MTApi_Diagnose_MicrophoneState_Rsp、Ev_MTApi_Diagnose_MicrophoneState_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseMicrophoneStateReq(IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_DiagnoseMicrophoneUploadCmd
* 
* @brief <<麦克风上传命令>>
*
* @param    [in]   dwSSID            MT会话ID 
* @return   u32  0：成功, 其他：错误码 
*
* @note 更新通知：Ev_MTApi_Diagnose_MicrophoneUpload_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseMicrophoneUploadCmd(IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_DiagnoseMicrophoneInstallCmd
* 
* @brief <<麦克风安装命令>>
*
* @param    [in]   dwSSID            MT会话ID 
* @return   u32  0：成功, 其他：错误码 
*
* @note 更新通知：无
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseMicrophoneInstallCmd(IN CONST TMicInstallList_Api tInstallList, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_DiagnoseMicUpgradeFileImportReq
* 
* @brief <<导入麦克风升级文件请求>>
*
* @param    [in]   pchFileNamePath            导入源路径(带文件名)
* @param    [in]   dwSSID                            MT会话ID 
* @return   u32  0：成功, 其他：错误码 
*
* @note 更新通知：Ev_MTApi_Diagnose_MicUpgradeFileImport_Rsp、Ev_MTApi_Diagnose_MicUpgradeFileImportProgress_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseMicUpgradeFileImportReq(IN CONST s8* pchFileNamePath, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_DiagnoseExportAllLogFilesReq
* 
* @brief <<导出所有日志文件请求>>
*
* @param    [in]   pchPath            文件存放目录
* @param    [in]   dwSSID             MT会话ID 
* @return   u32  0：成功, 其他：错误码 
*
* @note 更新通知：Ev_MTApi_Diagnose_ExportAllFiles_Rsp、Ev_MTApi_Diagnose_ExportAllFilesProgress_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseExportAllLogFilesReq(IN CONST s8* pchPath, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/*******************************************************************************//**
*@brief        查询设备含有E1模块数量(仅Embed)
*
*@param[in]     dwSSID  MT会话ID 
*@return        u32   请求命令发送结果
*@note          响应通知：Ev_MtApi_Diagnose_GetE1ModuleNum_Rsp
***********************************************************************************/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetE1ModuleNumReq(IN CONST SessionID dwSSID = KMTAPI_DEF_SSID);

/** 
* KdvMt_DiagnoseIspImgInfSharpnessCmd
*
* @brief  设置Isp锐度       
* @param    [in]   emGeneralLevel            Isp图像锐度值
* @param    [in]   dwSSID  MT会话ID 
* @return    u32   请求命令发送结果
*
* @note 响应通知：Ev_MtApi_Diagnose_IspImgInfSharpness_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseIspImgInfSharpnessCmd( IN CONST EmGeneralLevel_Api emGeneralLevel, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/** 
* KdvMt_DiagnoseGetIspImgInfSharpnessReq
*
* @brief  获取Isp锐度       
* @param    [in]   dwSSID  MT会话ID 
* @return    u32   请求命令发送结果
*
* @note 响应通知：Ev_MtApi_Diagnose_IspImgInfSharpness_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetIspImgInfSharpnessReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/** 
* KdvMt_DiagnoseGetIspImgInfSharpness
*
* @brief  获取Isp锐度       
* @param    [out]   emGeneralLevel            Isp图像锐度值
* @param    [in]   dwSSID  MT会话ID 
* @return    u32   请求命令发送结果
*
* @note 响应通知：
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetIspImgInfSharpness( OUT EmGeneralLevel_Api &emGeneralLevel, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );




/** 
* KdvMt_DiagnoseIspImgInfWhiteBalanceCmd
*
* @brief  设置Isp白平衡
* @param    [in]   emWBAMode                 Isp图像白平衡值        
* @param    [in]   dwSSID  MT会话ID 
* @return    u32   请求命令发送结果
*
* @note 响应通知：Ev_MtApi_Diagnose_IspImgInfWhiteBalance_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseIspImgInfWhiteBalanceCmd( IN CONST EmWBAMode_Api emWBAMode, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID  );

/** 
* KdvMt_DiagnoseGetIspImgInfWhiteBalanceReq
*
* @brief  获取Isp白平衡       
* @param    [in]   dwSSID  MT会话ID 
* @return    u32   请求命令发送结果
*
* @note 响应通知：Ev_MtApi_Diagnose_IspImgInfWhiteBalance_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetIspImgInfWhiteBalanceReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID  );

/** 
* KdvMt_DiagnoseGetIspImgInfWhiteBalance
*
* @brief  获取Isp白平衡
* @param    [out]   emWBAMode                 Isp图像白平衡值        
* @param    [in]   dwSSID  MT会话ID 
* @return    u32   请求命令发送结果
*
* @note 响应通知：
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetIspImgInfWhiteBalance( OUT EmWBAMode_Api &emWBAMode, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID  );




/** 
* KdvMt_DiagnoseIspImgInfShutterCmd
*
* @brief  设置Isp快门速度        
* @param    [in]   emShutterLevel            Isp图像快门速度值
* @param    [in]   dwSSID  MT会话ID 
* @return    u32   请求命令发送结果
*
* @note 响应通知：Ev_MtApi_Diagnose_IspImgInfShutter_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseIspImgInfShutterCmd( IN CONST EmShutterLevel_Api emShutterLevel, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID  );

/** 
* KdvMt_DiagnoseGetIspImgInfShutterReq
*
* @brief  获取Isp快门速度        
* @param    [in]   dwSSID  MT会话ID 
* @return    u32   请求命令发送结果
*
* @note 响应通知：Ev_MtApi_Diagnose_IspImgInfShutter_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetIspImgInfShutterReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID  );

/** 
* KdvMt_DiagnoseGetIspImgInfShutter
*
* @brief  获取Isp快门速度        
* @param    [out]   emShutterLevel            Isp图像快门速度值
* @param    [in]   dwSSID  MT会话ID 
* @return    u32   请求命令发送结果
*
* @note 响应通知：
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetIspImgInfShutter( OUT EmShutterLevel_Api &emShutterLevel, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID  );




/** 
* KdvMt_DiagnoseIspImgInfNoiseCmd
*
* @brief  设置Isp降噪        
* @param    [in]   emNFMode            Isp图像降噪值
* @param    [in]   dwSSID  MT会话ID 
* @return    u32   请求命令发送结果
*
* @note 响应通知：Ev_MtApi_Diagnose_IspImgInfNoise_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseIspImgInfNoiseCmd( IN CONST EmNFMode_Api emNFMode, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID  );


/** 
* KdvMt_DiagnoseGetIspImgInfNoiseReq
*
* @brief  获取Isp降噪        
* @param    [in]   dwSSID  MT会话ID 
* @return    u32   请求命令发送结果
*
* @note 响应通知：Ev_MtApi_Diagnose_IspImgInfNoise_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetIspImgInfNoiseReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID  );


/** 
* KdvMt_DiagnoseGetIspImgInfNoise
*
* @brief  获取Isp降噪        
* @param    [out]   emNFMode            Isp图像降噪值
* @param    [in]   dwSSID  MT会话ID 
* @return    u32   请求命令发送结果
*
* @note 响应通知：
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetIspImgInfNoise( OUT EmNFMode_Api &emNFMode, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID  );



/** 
* KdvMt_DiagnoseIspImgInfISOCmd
*
* @brief  设置Isp感光度
* @param    [in]   emISO             Isp图像感光度         
* @param    [in]   dwSSID  MT会话ID 
* @return    u32   请求命令发送结果
*
* @note 响应通知：Ev_MtApi_Diagnose_IspImgInfISO_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseIspImgInfISOCmd( IN CONST EmISO_Api emISO, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID  );


/** 
* KdvMt_DiagnoseGetIspImgInfISOReq
*
* @brief  获取Isp感光度         
* @param    [in]   dwSSID  MT会话ID 
* @return    u32   请求命令发送结果
*
* @note 响应通知：Ev_MtApi_Diagnose_IspImgInfISO_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetIspImgInfISOReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID  );


/** 
* KdvMt_DiagnoseGetIspImgInfISO
*
* @brief  获取Isp感光度
* @param    [out]   emISO             Isp图像感光度         
* @param    [in]   dwSSID  MT会话ID 
* @return    u32   请求命令发送结果
*
* @note 响应通知：
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetIspImgInfISO( OUT EmISO_Api &emISO, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID  );





/** 
* KdvMt_DiagnoseIspImgInfApertureCmd
*
* @brief  设置Isp光圈大小
* @param    [in]   EmAperture_Api             Isp光圈大小         
* @param    [in]   dwSSID  MT会话ID 
* @return    u32   请求命令发送结果
*
* @note 响应通知：Ev_MtApi_Diagnose_IspImgInfAperture_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseIspImgInfApertureCmd( IN CONST EmAperture_Api emAperture, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/** 
* KdvMt_DiagnoseGetIspImgInfApertureReq
*
* @brief  设置Isp光圈大小      
* @param    [in]   dwSSID  MT会话ID 
* @return    u32   请求命令发送结果
*
* @note 响应通知：Ev_MtApi_Diagnose_IspImgInfAperture_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetIspImgInfApertureReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/** 
* KdvMt_DiagnoseGetIspImgInfAperture
*
* @brief  获取Isp光圈大小
* @param    [out]   EmAperture_Api             Isp光圈大小         
* @param    [in]   dwSSID  MT会话ID 
* @return    u32   请求命令发送结果
*
* @note 响应通知：
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetIspImgInfAperture( OUT  EmAperture_Api &emAperture, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );




/** 
* KdvMt_DiagnoseIspImgInfExposureModeCmd
*
* @brief  设置Isp曝光模式
* @param    [in]   EmExposureMode_Api        Isp曝光         
* @param    [in]   dwSSID  MT会话ID 
* @return    u32   请求命令发送结果
*
* @note 响应通知：Ev_MtApi_Diagnose_IspImgInfExposureMode_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseIspImgInfExposureModeCmd( IN CONST EmExposureMode_Api emExposureMode, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/** 
* KdvMt_DiagnoseGetIspImgInfExposureModeReq
*
* @brief  获取Isp曝光模式         
* @param    [in]   dwSSID  MT会话ID 
* @return    u32   请求命令发送结果
*
* @note 响应通知：Ev_MtApi_Diagnose_IspImgInfExposureMode_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetIspImgInfExposureModeReq(  IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/** 
* KdvMt_DiagnoseGetIspImgInfExposureMode
*
* @brief  获取Isp曝光模式
* @param    [in]   EmExposureMode_Api        Isp曝光         
* @param    [out]   dwSSID  MT会话ID 
* @return    u32   请求命令发送结果
*
* @note 响应通知：
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetIspImgInfExposureMode( OUT EmExposureMode_Api &emExposureMode, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );




/** 
* KdvMt_DiagnoseIspImgInfBrightnesssCmd
*
* @brief  设置Isp亮度
* @param    [in]   EmBrightnessDirection_Api        Isp亮度         
* @param    [in]   dwSSID  MT会话ID 
* @return    u32   请求命令发送结果
*
* @note 响应通知：
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseIspImgInfBrightnesssCmd( IN CONST EmBrightnessDirection_Api emBrightnessDirection, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/** 
* KdvMt_DiagnoseGetIsDbgCfgExistReq
*
* @brief	获取debug文件是否存在
* @param    [in]   dwSSID  MT会话ID 
* @return    u32   请求命令发送结果
*
* @note 响应通知：
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetIsDbgCfgExistReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/** 
* KdvMt_DiagnoseGetMicrophoneInfoReq
*
* @brief	获取终端保存的麦克风版本信息请求
* @param    [in]   dwSSID  MT会话ID 
* @return   u32   请求命令发送结果
*
* @note 响应通知：Ev_MtApi_Diagnose_TermKeepMicrophoneInfo_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetMicrophoneInfoReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_DTGetCurCapStatusInfo 
* 
* @brief 获取当前终端正在抓包或不在抓包的信息
* 
* @param    [out] tStatusInfo  抓包信息
* @param    [in]  dwSSID       MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：no
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DTGetCurCapStatusInfo( OUT TMtCurCapStatusInfo_Api& tStatusInfo, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/** 
* KdvMt_DiagnoseSetIspImgNoiseCmd
*
* @brief  设置Isp图像降噪命令        
* @param    [in]   tInfo   降噪信息
* @param    [in]   dwSSID  MT会话ID 
* @return    u32   请求命令发送结果
*
* @note 响应通知：Ev_MtApi_Diagnose_SetIspImgNoise_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseSetIspImgNoiseCmd( IN CONST TMTIspImgNFInfo_Api tInfo, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID  );

/** 
* KdvMt_DiagnoseGetIspImgNoiseReq
*
* @brief  获取Isp图像降噪信息请求       
* @param    [in]   emType  降噪类型,2D还是3D 
* @param    [in]   dwSSID  MT会话ID 
* @return    u32   请求命令发送结果
*
* @note 响应通知：	Ev_MtApi_Diagnose_GetIspImgNoise_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetIspImgNoiseReq( IN CONST EmNFType_Api emType, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID  );

/** 
* KdvMt_DiagnoseGetIspImgNoise
*
* @brief  获取Isp图像降噪信息
* @param    [in/out]  tInfo   降噪信息  
* @param    [in]   dwSSID  MT会话ID 
* @return    u32   请求命令发送结果
*
* @note 响应通知：no
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetIspImgNoise( OUT TMTIspImgNFInfo_Api& tInfo, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID  );

/** 
* KdvMt_DiagnoseSetIspImgSharpnessCmd
*
* @brief  设置Isp图像锐度命令       
* @param    [in]   tInfo   锐度信息
* @param    [in]   dwSSID  MT会话ID 
* @return    u32   请求命令发送结果
*
* @note 响应通知：Ev_MtApi_Diagnose_SetIspImgSharpness_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseSetIspImgSharpnessCmd( IN CONST TMTIspImgSharpnessInfo_Api tInfo, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/** 
* KdvMt_DiagnoseGetIspImgSharpnessReq
*
* @brief  获取Isp图像锐度信息的请求       
* @param    [in]   tInfo   锐度信息
* @param    [in]   dwSSID  MT会话ID 
* @return    u32   请求命令发送结果
*
* @note 响应通知：Ev_MtApi_Diagnose_GetIspImgSharpness_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetIspImgSharpnessReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/** 
* KdvMt_DiagnoseGetIspImgSharpness
*
* @brief  获取Isp图像锐度信息    
* @param    [out]   tInfo   锐度信息
* @param    [in]   dwSSID  MT会话ID 
* @return    u32   请求命令发送结果
*
* @note 响应通知：no
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetIspImgSharpness( OUT TMTIspImgSharpnessInfo_Api& tInfo, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/** 
* KdvMt_DiagnoseSetIspExposureGainCmd
*
* @brief  设置Isp曝光模式增益信息命令  
* @param    [in]   tInfo   锐度信息
* @param    [in]   dwSSID  MT会话ID 
* @return    u32   请求命令发送结果
*
* @note 响应通知：Ev_MtApi_Diagnose_SetIspImgExposureGain_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseSetIspExposureGainCmd( IN CONST TMTIspImgExposureGain_Api tInfo, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/** 
* KdvMt_DiagnoseGetIspExposureGainReq
*
* @brief  获取Isp曝光模式增益信息请求 
* @param    [in]   emType  增益类型 
* @param    [in]   dwSSID  MT会话ID 
* @return    u32   请求命令发送结果
*
* @note 响应通知：Ev_MtApi_Diagnose_GetIspImgExposureGain_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetIspExposureGainReq( IN CONST EmExposureGainType_Api emType, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/** 
* KdvMt_DiagnoseGetIspExposureGain
*
* @brief  获取Isp曝光模式增益信息 
* @param    [in/out]   tInfo  增益信息
* @param    [in]   dwSSID  MT会话ID 
* @return    u32   请求命令发送结果
*
* @note 响应通知：no
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetIspExposureGain( OUT TMTIspImgExposureGain_Api& tInfo, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/** 
* KdvMt_DiagnoseSetIspWBGainCmd
*
* @brief  设置白平衡(手动模式)增益信息命令  
* @param    [in]   tInfo   增益信息
* @param    [in]   dwSSID  MT会话ID 
* @return    u32   请求命令发送结果
*
* @note 响应通知：Ev_MtApi_Diagnose_SetIspImgWBAGain_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseSetIspWBGainCmd( IN CONST TMTIspImgWBAGainInfo_Api tInfo, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/** 
* KdvMt_DiagnoseGetIspWBGainReq
*
* @brief  获取白平衡(手动模式)增益信息请求
* @param    [in]   emType  增益类型 
* @param    [in]   dwSSID  MT会话ID 
* @return    u32   请求命令发送结果
*
* @note 响应通知：Ev_MtApi_Diagnose_GetIspImgWBAGain_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetIspWBGainReq( IN CONST EmWBAGainType_Api emType, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/** 
* KdvMt_DiagnoseGetIspExposureGain
*
* @brief  获取白平衡(手动模式)增益信息 
* @param    [in/out]   tInfo  增益信息
* @param    [in]   dwSSID  MT会话ID 
* @return    u32   请求命令发送结果
*
* @note 响应通知：no
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetIspWBGain( OUT TMTIspImgWBAGainInfo_Api& tInfo, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_DiagnoseSetIspParamCmd
*
* @brief    设置图像亮度、对比度、饱和度等ISP参数
*
* @param    [in]   emCodecType   编解码类型
* @param    [in]   emCodecIdx   哪一路
* @param    [in]   emMsgSrc    EmImgParam_Api(暂时可填emContrast_Api、emSaturation_Api、emBright_Api，其它值无效)
* @param    [in]   nValue		参数值
* @return   u32    0：成功      其他错误码
* @note 更新通知： Ev_MtApi_Diagnose_SetIspParam_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseSetIspParamCmd( IN CONST EmCodecComponent_Api emCodecType, IN CONST EmCodecComponentIndex_Api emCodecIdx, 
													 IN CONST EmIspImgInf_Api emMsgSrc,IN CONST s32 nValue,IN CONST SessionID dwSSID  = KMTAPI_DEF_SSID );

/**
* KdvMt_DiagnoseGetIspParamReq
*
* @brief    查询图像亮度、对比度、饱和度等ISP参数请求
*
* @param    [in]   emCodecType   编解码类型
* @param    [in]   emCodecIdx   哪一路
* @param    [in]   emMsgSrc    EmImgParam_Api
* @return   u32    0：成功      其他错误码
* @note 更新通知：Ev_MtApi_Diagnose_GetIspParam_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetIspParamReq( IN CONST EmCodecComponent_Api emCodecType, IN CONST EmCodecComponentIndex_Api emCodecIdx, 
													 IN CONST EmIspImgInf_Api emMsgSrc, IN CONST SessionID dwSSID  = KMTAPI_DEF_SSID );

/**
* KdvMt_DiagnoseSetBackLightCmd
*
* @brief   设置摄像头背光补偿命令（仅Embed）
*
* @param    [in]   bOn            摄像头背光补偿，TRUE为打开，FALSE为关闭
* @param    [in]   dwSSID         MT会话ID 
* @return   u32    0：获取成功  其他错误码
*
* @note 更新通知：Ev_MtApi_Diagnose_SetIspImgBackLightSwitch_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseSetBackLightCmd( IN CONST BOOL32 bOn, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_DiagnoseGetBackLightReq
*
* @brief   获取摄像头背光补偿请求（仅Embed）
*
* @param    [in]   dwSSID         MT会话ID 
* @return   u32    0：获取成功  其他错误码
*
* @note 更新通知：Ev_MtApi_Diagnose_GetIspImgBackLightSwitch_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetBackLightReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_DiagnoseGetBackLight
*
* @brief   获取摄像头是否开启背光补偿（仅Embed）
*
* @param    [out]   bOn           TRUE为打开，FALSE为关闭
* @param    [in]   dwSSID         MT会话ID 
* @return   u32    0：获取成功  其他错误码
*
* @note 更新通知：no
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetBackLight( OUT BOOL32 &bOn, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_DiagnoseSetBackLightLevelCmd
*
* @brief   设置摄像头背光补偿等级（仅Embed）
*
* @param    [in]   dwValue        补偿等级， 0-15
* @param    [in]   dwSSID         MT会话ID 
* @return   u32    0：获取成功  其他错误码
*
* @note 更新通知：Ev_MtApi_Diagnose_SetIspImgBackLightLevel_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseSetBackLightLevelCmd( IN CONST u32 dwValue, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_DiagnoseGetBackLightLevelReq
*
* @brief   获取摄像头背光补偿等级请求（仅Embed）
*
* @param    [in]   dwSSID         MT会话ID 
* @return   u32    0：获取成功  其他错误码
*
* @note 更新通知：Ev_MtApi_Diagnose_GetIspImgBackLightLevel_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetBackLightLevelReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_DiagnoseGetBackLightLevel
*
* @brief   获取摄像头背光补偿等级（仅Embed）
*
* @param    [out]   dwValue        补偿等级， 0-15
* @param    [in]    dwSSID         MT会话ID 
* @return   u32     0：获取成功    其他错误码
*
* @note 更新通知：no
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetBackLightLevel( OUT u32 &dwValue, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_DiagnoseSetDigDynSwitchCmd
*
* @brief   Isp数字宽动态开关设置（仅Embed）
*
* @param    [in]   bOn            TRUE为打开，FALSE为关闭
* @param    [in]   dwSSID         MT会话ID 
* @return   u32    0：获取成功  其他错误码
*
* @note 更新通知：Ev_MtApi_Diagnose_SetIspImgDigDynSwitch_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseSetDigDynSwitchCmd( IN CONST BOOL32 bOn, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_DiagnoseGetDigDynSwitchReq
*
* @brief   获取Isp数字宽动态开关请求（仅Embed）
*
* @param    [in]   dwSSID         MT会话ID 
* @return   u32    0：获取成功  其他错误码
*
* @note 更新通知：Ev_MtApi_Diagnose_GetIspImgDigDynSwitch_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetDigDynSwitchReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_DiagnoseGetDigDynSwitch
*
* @brief   Isp数字宽动态开关获取（仅Embed）
*
* @param    [out]   bOn            TRUE为打开，FALSE为关闭
* @param    [in]   dwSSID         MT会话ID 
* @return   u32    0：获取成功  其他错误码
*
* @note 更新通知：no
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetDigDynSwitch( OUT BOOL32 &bOn, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_DiagnoseSetDigDynLevelCmd
*
* @brief   Isp数字宽动态等级设置（仅Embed）
*
* @param    [in]   dwValue        等级值
* @param    [in]   dwSSID         MT会话ID 
* @return   u32    0：获取成功  其他错误码
*
* @note 更新通知：Ev_MtApi_Diagnose_SetIspImgDigDynLevel_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseSetDigDynLevelCmd( IN CONST u32 dwValue, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_DiagnoseGetDigDynLevelReq
*
* @brief   Isp数字宽动态等级请求（仅Embed）
*
* @param    [in]   dwSSID         MT会话ID 
* @return   u32    0：获取成功  其他错误码
*
* @note 更新通知：Ev_MtApi_Diagnose_GetIspImgDigDynLevel_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetDigDynLevelReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_DiagnoseGetDigDynLevel
*
* @brief   Isp数字宽动态等级获取（仅Embed）
*
* @param    [out]   dwValue       等级值
* @param    [in]   dwSSID         MT会话ID 
* @return   u32    0：获取成功  其他错误码
*
* @note 更新通知：no
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetDigDynLevel( OUT u32 &dwValue, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_DiagnoseSetIspGammaCmd
*
* @brief   Isp伽马设置（仅Embed）
*
* @param    [in]   dwValue        伽马数值
* @param    [in]   dwSSID         MT会话ID 
* @return   u32    0：获取成功  其他错误码
*
* @note 更新通知：Ev_MtApi_Diagnose_SetIspImgGamma_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseSetIspGammaCmd( IN CONST u32 dwValue, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_DiagnoseGetIspGammaReq
*
* @brief   Isp伽马获取请求（仅Embed）
*
* @param    [in]   dwSSID         MT会话ID 
* @return   u32    0：获取成功  其他错误码
*
* @note 更新通知：Ev_MtApi_Diagnose_GetIspImgGamma_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetIspGammaReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_DiagnoseGetIspGamma
*
* @brief   Isp伽马获取（仅Embed）
*
* @param    [out]   dwValue        伽马数值
* @param    [in]    dwSSID         MT会话ID 
* @return   u32     0：获取成功  其他错误码
*
* @note 更新通知：no
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetIspGamma( OUT u32 &dwValue, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_DiagnoseSetIspDefogCmd
*
* @brief   Isp数字去雾设置（仅Embed）
*
* @param    [in]   dwValue        去雾数值
* @param    [in]   dwSSID         MT会话ID 
* @return   u32    0：获取成功  其他错误码
*
* @note 更新通知：Ev_MtApi_Diagnose_SetIspImgDefog_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseSetIspDefogCmd( IN CONST u32 dwValue, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_DiagnoseGetIspDefogReq
*
* @brief   Isp数字去雾获取请求（仅Embed）
*
* @param    [in]   dwSSID         MT会话ID 
* @return   u32    0：获取成功  其他错误码
*
* @note 更新通知：Ev_MtApi_Diagnose_GetIspImgDefog_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetIspDefogReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_DiagnoseGetIspDefog
*
* @brief   Isp数字去雾获取（仅Embed）
*
* @param    [out]   dwValue        去雾数值
* @param    [in]   dwSSID         MT会话ID 
* @return   u32    0：获取成功  其他错误码
*
* @note 更新通知：no
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetIspDefog( OUT u32 &dwValue, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_DiagnoseSetOsdDisplayCmd
*
* @brief   设置osd界面是否关闭（网呈用）
*
* @param    [in]   bOpen          TRUE为打开，FALSE为关闭
* @param    [in]   dwSSID         MT会话ID 
* @return   u32    0：获取成功  其他错误码
*
* @note 更新通知：Ev_MtApi_Diagnose_SetOsdOpen_Ntf 或 Ev_MtApi_Diagnose_SetOsdClose_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseSetOsdDisplayCmd( IN CONST BOOL32 bOpen, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_DiagnoseSetCameraImgInfoCmd
*
* @brief   设置摄像机图像模式（外置摄像机）
*
* @param    [in]   tInfo          图像信息
* @param    [in]   dwSSID         MT会话ID 
* @return   u32    0：获取成功  其他错误码
*
* @note 更新通知：Ev_MtApi_Diagnose_SetCameraImgMode_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseSetCameraImgInfoCmd( IN CONST TMtCameraImgInfo_Api tInfo, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_DiagnoseSetAiCameraCmd
*
* @brief   设置智能摄像机配置
*
* @param    [in]   tInfo          摄像机信息
* @param    [in]   dwSSID         MT会话ID 
* @return   u32    0：获取成功  其他错误码
*
* @note 更新通知：Ev_MtApi_Diagnose_SetAiCamera_Ntf 通知设置摄像消息
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseSetAiCameraCmd( IN CONST TMtHDCameraAiList_Api &tInfo, IN CONST SessionID dwSSID /*= KMTAPI_DEF_SSID*/ );


/**
* KdvMt_DiagnoseGetCameraImgInfoReq
*
* @brief   请求摄像机图像模式信息（外置摄像机）
*
* @param    [in]   dwSSID         MT会话ID 
* @return   u32    0：获取成功  其他错误码
*
* @note 更新通知：Ev_MtApi_Diagnose_GetCameraImgMode_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetCameraImgInfoReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_DiagnoseGetCameraImgInfo
*
* @brief   获取摄像机图像模式信息（外置摄像机）
*
* @param    [out]   tInfo          图像信息
* @param    [in]   dwSSID         MT会话ID 
* @return   u32    0：获取成功  其他错误码
*
* @note 更新通知：no
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetCameraImgInfo( OUT TMtCameraImgInfo_Api &tInfo, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_DiagnoseSetCameraPersonFirstCmd
*
* @brief   设置摄像机人物优先开关（外置摄像机）
*
* @param    [in]   bOn            开/关
* @param    [in]   dwSSID         MT会话ID 
* @return   u32    0：获取成功  其他错误码
*
* @note 更新通知：Ev_MtApi_Diagnose_SetCameraPersonFirst_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseSetCameraPersonFirstCmd( IN CONST BOOL32 bOn, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_DiagnoseGetCameraPersonFirstReq
*
* @brief   请求摄像机人物优先开关（外置摄像机）
*
* @param    [in]   dwSSID         MT会话ID 
* @return   u32    0：获取成功  其他错误码
*
* @note 更新通知：Ev_MtApi_Diagnose_GetCameraPersonFirst_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetCameraPersonFirstReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_DiagnoseGetCameraPersonFirst
*
* @brief   获取摄像机人物优先开关（外置摄像机）
*
* @param    [out]  bOn            开/关
* @param    [in]   dwSSID         MT会话ID 
* @return   u32    0：获取成功  其他错误码
*
* @note 更新通知：no
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetCameraPersonFirst( OUT BOOL32 &bOn, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/* KdvMt_SetShowRmtAssVidCmd
* 
* @brief   设置双屏模式收双流下第二屏是否显示远端辅流（网呈用）
*
* @param    [in]   bShow       TRUE:显示  FALSE:不显示
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 响应通知：no
*/
KdvMtAPI u32 KdvMtCALL KdvMt_SetShowRmtAssVidCmd( IN CONST BOOL32 bShow, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_DiagnoseSetCameraSceneModeCmd
*
* @brief   设置摄像机场景模式能力
*
* @param    [in]   dwVidIdx		摄像机编号
* @param    [in]   emSceneMode  场景模式类型
* @param    [in]   dwSSID         MT会话ID 
* @return   u32    0：获取成功  其他错误码
*
* @note 更新通知：Ev_MtApi_Diagnose_SetCameraSceneMode_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseSetCameraSceneModeCmd( IN CONST u32 dwVidIdx, IN CONST EmCameraSceneMode_Api emSceneMode, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_DiagnoseGetCameraSceneModeReq
*
* @brief   请求摄像机场景模式能力
*
* @param    [in]   dwVidIdx		摄像机编号
* @param    [in]   dwSSID         MT会话ID 
* @return   u32    0：获取成功  其他错误码
*
* @note 更新通知：Ev_MtApi_Diagnose_GetCameraSceneMode_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetCameraSceneModeReq( IN CONST u32 dwVidIdx, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_DiagnoseGetCameraUpgradePackReq
*
* @brief   摄像头升级包名称获取请求
*
* @param    [in]   emVidPort      视频源端口
* @param    [in]   dwSSID         MT会话ID 
* @return   u32    0：获取成功  其他错误码
*
* @note 更新通知：Ev_MtApi_Diagnose_GetCameraUpgradePack_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_Diagnose_GetCameraUpgradePackReq( IN CONST EmMtVideoPort_Api emVidPort, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_DiagnoseSetLocalAssAudExpCmd
*
* @brief   本地辅流扩声设置
*
* @param    [in]   bOpen		开启/关闭
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    0：获取成功  其他错误码
*
* @note 更新通知：Ev_MtApi_Diagnose_SetLocalAssAudExp_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseSetLocalAssAudExpCmd( IN CONST BOOL32 bOpen, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_DiagnoseGetLocalAssAudExpReq
*
* @brief   本地辅流扩声获取请求
*
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    0：获取成功  其他错误码
*
* @note 更新通知：Ev_MtApi_Diagnose_GetLocalAssAudExp_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetLocalAssAudExpReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_DiagnoseGetLocalAssAudExp
*
* @brief   本地辅流扩声获取
*
* @param    [out]  bOpen        开启/关闭
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    0：获取成功  其他错误码
*
* @note 更新通知：no
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetLocalAssAudExp( OUT BOOL32 &bOpen, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_DiagnoseExportDiagInfoFileCmd
*
* @brief   导出诊断信息文件命令
*
* @param    [in]   pchFilePath      导出文件的路径 
* @param    [in]   dwSSID			MT会话ID 
* @return   u32    0：获取成功  其他错误码
*
* @note 更新通知：Ev_MtApi_Diagnose_ExportDiagInfoFile_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseExportDiagInfoFileCmd( IN CONST s8 *pchFilePath, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_DiagnoseGetPacketDurationTimeReq
*
* @brief   获取当前抓包持续时间请求
*
* @param    [in]   dwSSID			MT会话ID 
* @return   u32    0：获取成功  其他错误码
*
* @note 更新通知：Ev_MtApi_Diagnose_GetPacketDurationTime_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetPacketDurationTimeReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_DiagnoseElectricFanCmd
*
* @brief   除雾

* @param    [in]   bElectricFan      是否除雾 
* @param    [in]   dwSSID			MT会话ID 
* @return   u32    0：获取成功  其他错误码
*
* @note 更新通知：Ev_MtApi_Diagnose_ElectricFan_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseElectricFanCmd( IN CONST BOOL32 bElectricFan, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_DiagnoseElectricFanCmd
*
* @brief   获取除雾剩余时间请求
 
* @param    [in]   dwSSID			MT会话ID 
* @return   u32    0：获取成功  其他错误码
*
* @note 更新通知：Ev_MtApi_Diagnose_GetElectricFanTime_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseGetElectricFanTimeReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_DiagnoseCleanUpdateSpaceCmd
* 
* @brief  清理升级包存储空间的命令(webmtc用)
*  
* @param    [in]   dwSSID  MT会话ID 
* @return   u32   请求命令发送结果
*
* @note 更新通知:	Ev_MtApi_Diagnose_CleanUpdateSpace_Ntf   
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DiagnoseCleanUpdateSpaceCmd( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**@}*/

/**@}*/
#endif //_MTAPI_DIAGNOSEAPI_H_
/*******************************************************************************//**
*@file          nvapi_quickshare.h
*@brief         提供无线投屏器SDK接口
*
*@author        youjiaixng
*@version       1.0    
*@date          20180611
*@copyright     (c)1995-2015 Suzhou Keda Technology Co.,Ltd. All rights reserved
***********************************************************************************/
#ifndef _NVAPI_QUICKSHARE_H_
#define _NVAPI_QUICKSHARE_H_
/**@addtogroup api API接口
*@{
*/

/**@addtogroup quickshareapi 
*@{
*/

#include <string.h>
#include "nvapi_export.h"
#include "nvapi_struct.h"
#include "kdvmedianet.h"

//无线投屏消息回调定义
typedef u32 (*NOTIFY_NV_Qk_EVENT_CALLBACK)(u32 dwEvent, u8 *pbyBuf);
//无线投屏码流回调定义
typedef u32 (*NOTIFY_NV_Qk_FRAME_CALLBACK)(PFRAMEHDR pFrmHdr);


/*******************************************************************************//**
*@brief         投屏模块是否已经初始化
*KdvNv_QkIsInited
*
*@param[in]     
*@return        BOOL32  TRUE：成功， FALSE：失败
*@note          更新通知：
***********************************************************************************/
KdvNvAPI BOOL32 KdvNvCALL KdvNv_QkIsInited( );

/*******************************************************************************//**
*@brief         投屏模块释放退出
*KdvNv_QkUnInitalize
*
*@param[in]     
*@return        u32  0：成功， 1：失败
*@note          更新通知：
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_QkUnInitalize( );

/*******************************************************************************//**
*@brief         投屏模块初始化
*KdvNv_QkInitalize
*
*@param[in]     
*@return        u32  0：成功， 1：失败
*@note          更新通知：
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_QkInitalize( );

/*******************************************************************************//**
*@brief         投屏消息回调(回调函数中响应消息处要与回调函数同步)
*KdvNv_QkSetEventCallback
*
*(注意：回调上去的参数不允许改变其值) 
*
*@param[in]     cbCallback  要注册的回调函数
*@return        u32  0：成功， 1：失败
*@note          更新通知：
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_QkSetEventCallback( IN NOTIFY_NV_Qk_EVENT_CALLBACK cbCallback );

/*******************************************************************************//**
*@brief         通知投屏器插入终端的状态
*KdvNv_QkNotifyQkUsbLoginCmd
*
*@param[in]     bLogin TRUE：登入 FALSE：退出
*@return        u32  0：成功， 1：失败
*@note          更新通知：Ev_NvApi_Qk_UsbEvent_Rsp
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_QkNotifyQkUsbLoginCmd ( IN CONST BOOL32 bLogin);

/*******************************************************************************//**
*@brief         发送Usb指令信息（配对，升级）
*KdvNv_QkSetUsbEventReq
*
*@param[in]     tUsbInfo usb指令信息
*@return        u32  0：成功， 1：失败
*@note          更新通知：Ev_NvApi_Qk_UsbEvent_Rsp
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_QkSetUsbEventCmd ( IN CONST TNVQKUsbInput_Api tUsbInfo);

/*******************************************************************************//**
*@brief         通知是否升级投屏器
*KdvNv_QkSetUsbEventReq
*
*@param[in]     bUpgrade TRUE:升级  FALSE:不升级
*@return        u32  0：成功， 1：失败
*@note          更新通知：Ev_NvApi_Qk_UsbEvent_Rsp
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_QkUpgradeCmd (IN CONST BOOL32 bUpgrade);

/*******************************************************************************//**
*@brief         投屏码流回调(回调函数中响应消息处要与回调函数同步)
*KdvNv_QkSetFrameCallback
*
*(注意：回调上去的参数不允许改变其值) 
*
*@param[in]     cbCallback  要注册的回调函数
*@return        u32  0：成功， 1：失败
*@note          更新通知：
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_QkSetFrameCallback( IN NOTIFY_NV_Qk_FRAME_CALLBACK cbCallback );

/*******************************************************************************//**
*@brief         关键帧请求
*KdvNv_QkAskKeyFrame
*
*@param[in]     
*@return        u32  0：成功， 1：失败
*@note          更新通知：
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_QkAskKeyFrame( );

/*******************************************************************************//**
*@brief         投屏请求
*KdvNv_QkStartView
*
*@param[in]     dwIndex 投屏器序号
*@return        u32  0：成功， 1：失败
*@note          更新通知：Ev_NvApi_Qk_StartViewQuickShare_Ntf， Ev_NvApi_Qk_ViewQuickShareResult_Ntf
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_QkStartView(IN CONST u32 dwIndex );

/*******************************************************************************//**
*@brief         结束投屏请求
*KdvNv_QkStopView
*
*@param[in]     dwIndex 投屏器序号
*@return        u32  0：成功， 1：失败
*@note          更新通知：Ev_NvApi_Qk_StartViewQuickShare_Ntf， Ev_NvApi_Qk_ViewQuickShareResult_Ntf
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_QkStopView(IN CONST u32 dwIndex );

/*******************************************************************************//**
*@brief         反控命令
*KdvNv_QkSetControlEvent
*
*@param[in]     tEvent 指令信息
*@return        u32  0：成功， 1：失败
*@note          更新通知：
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_QkSetControlEvent(IN CONST TNVQKControlEvent_Api tEvent);

/*******************************************************************************//**
*@brief         Ppt翻页
*KdvNv_QkPageTurnPPTCmd
*
*@param[in]     emTurnType: ppt控制类型
*@return        u32  0：成功， 1：失败
*@note          更新通知：
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_QkPageTurnPPTCmd(IN CONST EmNvQkPPTPageTurn_Api emTurnType );

/*******************************************************************************//**
*@brief         获取投屏器接入最大个数
*KdvNv_QkGetConnecttMaxNum
*
*@param[OUT]    dwNum 投屏器最大连接个数 
*@return        u32  0：成功， 1：失败
*@note          更新通知：
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_QkGetConnecttMaxNum(OUT u32 &dwNum);

/*******************************************************************************//**
*@brief         获取当前选看的投屏器
*KdvNv_QkGetViewQkIndex
*
*@param[OUT]    dwIndex投屏器序号 
*@return        u32  0：成功， 1：失败
*@note          更新通知：
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_QkGetViewQkIndex(OUT u32 &dwIndex);

/*******************************************************************************//**
*@brief         当前是否在投屏
*KdvNv_QkIsView
*
*@param[OUT]    bView TRUE:在投屏，FALSE：没在投屏 
*@return        u32  0：成功， 1：失败
*@note          更新通知：
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_QkIsView(OUT BOOL32 &bView);

/*******************************************************************************//**
*@brief         通知投屏器当前投屏需要编码协商
*KdvNv_QkNeedCodeConsultCmd
*
*@param[IN]     dwIndex: 投屏器序号
*@return        u32  0：成功， 1：失败
*@note          更新通知：
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_QkNeedCodeConsultCmd(IN CONST u32 dwIndex);

/*******************************************************************************//**
*@brief         当前投屏器的编码参数
*KdvNv_QkCodeParamCmd
*
*@param[IN]     dwIndex: 投屏器序号
*@param[IN]     tParam : 编码参数
*@return        u32  0：成功， 1：失败
*@note          更新通知：
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_QkCodeParamCmd(IN CONST u32 dwIndex, IN CONST TNVQKCodeParam_Api tParam );

/*******************************************************************************//**
*@brief         设置投屏器的分辨率（只针对正在投屏的投屏器有效）
*KdvNv_QkCodeResCmd
*
*@param[IN]     dwIndex: 投屏器序号
*@param[IN]     emQkRes : 分辨率类型
*@return        u32  0：成功， 1：失败
*@note          更新通知：Ev_NvApi_Qk_CodeRes_Ntf
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_QkCodeResCmd(IN CONST u32 dwIndex, IN CONST EmNvQkCodeRes_Api emQkRes );

/*******************************************************************************//**
*@brief         设置投屏器的编码帧率（只针对正在投屏的投屏器有效）
*KdvNv_QkCodeFrameCmd
*
*@param[IN]     dwIndex: 投屏器序号
*@param[IN]     dwFrameRate : 帧率
*@return        u32  0：成功， 1：失败
*@note          更新通知：Ev_NvApi_Qk_CodeFrame_Ntf
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_QkCodeFrameCmd(IN CONST u32 dwIndex, IN CONST u32 dwFrameRate );

/*******************************************************************************//**
*@brief         设置投屏器的编码码率（只针对正在投屏的投屏器有效）
*KdvNv_QkCodeBitRateCmd
*
*@param[IN]     dwIndex: 投屏器序号
*@param[IN]     dwBitRate : 码率
*@return        u32  0：成功， 1：失败
*@note          更新通知：Ev_NvApi_Qk_CodeBitRate_Ntf
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_QkCodeBitRateCmd(IN CONST u32 dwIndex, IN CONST u32 dwBitRate );

/*******************************************************************************//**
*@brief         设置投屏器是否可以投屏（用于商密终端会议中不能投屏专用）
*KdvNv_EnableQkViewCmd
*
*@param[IN]     
*@return        u32  0：成功， 1：失败
*@note          更新通知：
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_EnableQkViewCmd(IN CONST BOOL32 bEnable, IN CONST EmNvQkNotViewReason_Api emReason);

/**@}*/
#endif 
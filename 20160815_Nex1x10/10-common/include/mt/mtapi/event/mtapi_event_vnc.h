/*******************************************************************************//**
*@file          mtapi_event_vnc.h
*@brief         实现MTAPI MtVncSdk 给UI(观察者)事件通知的定义
*
*@author        ruiyigen
*@version       5.0    
*@date          20150328
*@copyright     (c)1995-2015 Suzhou Keda Technology Co.,Ltd. All rights reserved
***********************************************************************************/
#ifndef _MTAPI_EVENT_VNC_H_
#define _MTAPI_EVENT_VNC_H_
/**@addtogroup event 事件
*@{
*/

/**@addtogroup vncevent 客户端双流事件
*@{
*/

#include "mtapi_event_def.h"


enum EmMtApiVncEv
{
	EV_UI_BGN(MTAPI_VNC)  = EVSEG_MTAPI_VNC_BGN,

/**
  @brief    当前辅流发送状态 Ev_Conf_AssSndSream_Status_Ntf
  
  MainBuf(#TMtAssVidStatusList_Api, tMtAssVidStatusList)
  
  @verbatim
  {
  "arrTAssVidStatus": 
  [
  {
  "emChanState": 1,
  "emVidLab": 1,
  "bActive": true
  }
  ]
  }
  @endverbatim
*/	
	Ev_MtApi_Vnc_AssSndSream_Status_Ntf,

/**
  @brief   当前辅流发送状态 Ev_Conf_AssSndSream_Status_Rsp
  
  MainBuf(#TMtAssVidStatusList_Api, tMtAssVidStatusList)
  @verbatim
  {
  "arrTAssVidStatus": 
  [
  {
  "emChanState": 1,
  "emVidLab": 1,
  "bActive": true
  }
  ]
  }
  @endverbatim
*/	
	Ev_MtApi_Vnc_AssSndSream_Status_Rsp,

/**
  @brief    当前辅流接收状态 Ev_Conf_AssRcvSream_Status_Ntf	
  
  MainBuf(#TMtAssVidStatusList_Api, tMtAssVidStatusList)
  @verbatim
  {
  "arrTAssVidStatus": 
  [
  {
  "emChanState": 1,
  "emVidLab": 1,
  "bActive": true
  }
  ]
  }
  @endverbatim
*/	
	Ev_MtApi_Vnc_AssRcvSream_Status_Ntf,

/**
  @brief   当前辅流接收状态 Ev_Conf_AssRcvSream_Status_Rsp
  
  MainBuf(#TMtAssVidStatusList_Api, tMtAssVidStatusList
  @verbatim
  {
  "arrTAssVidStatus": 
  [
  {
  "emChanState": 1,
  "emVidLab": 1,
  "bActive": true
  }
  ]
  }
  @endverbatim
*/	
	Ev_MtApi_Vnc_AssRcvSream_Status_Rsp,

/**
  @brief   桌面共享通道参数上报 Ev_Conf_PcAssStream_ChanParam_Ntf
  
  BODY: 	MainBuf(#TMTPcAssStreamChanParam_Api, tMTPcAssStreamChanParam)
  @verbatim
  {
  "tTransRtp": 
  {
  "emIpType": 0,
  "dwIp": 0,
  "achIpV6": "",
  "dwPort": 0
  },
  "tTransRtcp": 
  {
  "emIpType": 0,
  "dwIp": 0,
  "achIpV6": "",
  "dwPort": 0
  },
  "tEncParam": 
  {
  "emEncMode": 0,
  "emVidFormat": 0,
  "dwMaxKeyFrameInterval": 0,
  "dwMaxQuant": 0,
  "dwMinQuant": 0,
  "dwFrameRate": 0,
  "dwBitrate": 0,
  "dwH264Profile": 0,
  "dwWidth": 0,
  "dwHeight": 0
  },
  "dwPlayLoad": 0,
  "tEncryptKey": 
  {
  "byLen": 0,
  "byKey": ""
  }
  }
  @endverbatim
*/	
	Ev_MtApi_Vnc_PcAssStream_ChanParam_Ntf,

/**
  @brief   pc桌面共享通知界面开始编码 Ev_Conf_PcAssStream_StartEnc_Ntf
  @verbatim
	BODY: 无
  @endverbatim
*/	
	Ev_MtApi_Vnc_PcAssStream_StartEnc_Ntf,

/**
  @brief   pc桌面共享通知界面停止编码 Ev_Conf_PcAssStream_StopEnc_Ntf
  @verbatim
	BODY: 无
  @endverbatim
*/
	Ev_MtApi_Vnc_PcAssStream_StopEnc_Ntf,

/**
  @brief    pc桌面共享通知界面请求关键帧 Ev_Conf_PcAssStream_IFrameRequest_Ntf
  @verbatim
	BODY: 无
  @endverbatim
*/	
	Ev_MtApi_Vnc_PcAssStream_IFrameRequest_Ntf,

/**
  @brief   pc桌面共享通知界面调整bitrate Ev_Conf_PcAssStream_SetBitrate_Cmd
  @verbatim
  BODY:	wParam(u32, dwBitrate)
  {
  "basetype": 0
  }
  @endverbatim
*/	
	Ev_MtApi_Vnc_PcAssStream_SetBitrate_Ntf,

/**
  @brief    终端pc桌面编码统计信息请求通知 Ev_Conf_PCEncStatis_Req
  @verbatim
	BODY: 无
  @endverbatim
*/	
	Ev_MtApi_Vnc_PCAssEncStatisReq_Ntf,

/**
  @brief   发送pc双流失败通知 Ev_Conf_AssStreamSendFailed_Ntf
  @verbatim
	BODY: 无
  @endverbatim
*/
	Ev_MtApi_Vnc_AssStreamSendFailed_Ntf,


/**
  @brief   双流发送方通知 
  @verbatim
	MainBuf(TMtId_Api, ptMTId) 终端ID
	SubBuf(BOOL32, bGrabbed) 是否被抢发（第一次被抢发是true）
  @endverbatim
*/	
	Ev_MtApi_Vnc_AssStreamSender_Ntf,


	/**
  @brief   通知UI的PC双流设置码流标识 
  @verbatim
	MainBuf(s8*, pszEndPointId) 终端的id, 当前仅支持e164号
	SubBuf(u32, dwStreamId) 码流标示符
  @endverbatim
*/	
	Ev_MtApi_Vnc_SetStreamID_Cmd,


	/**
  @brief   通知UI的PC双流设置是否启动防火墙 
  @verbatim
	MainBuf(BOOL32, bEnble) 是否启动防火墙
	MainBuf(TNetParam_Api, tNetParam)网络地址
	 
  @endverbatim
*/	
	Ev_MtApi_Vnc_IsNatTraversal_Cmd,

		/**
  @brief   通知UI的PC双流设置是否剥掉RTP扩展头
  @verbatim
	MainBuf(BOOL32, bEnble) 是否剥掉RTP扩展头
	 
  @endverbatim
*/	
	Ev_MtApi_Vnc_SetBEnableRtpExStrip_Cmd,

  /**
  @brief   设置丢包重传参数
  @verbatim
	MainBuf(u16, wBufTimeSpan) 
	MainBuf(BOOL32, bRepeatSnd) 
	 
  @endverbatim
*/	
	Ev_MtApi_Vnc_SetPrsParam_Cmd,

	 /**
  @brief   设置fec是否开启
  @verbatim
	MainBuf(BOOL32, bEnable) 
	 
  @endverbatim
*/	
	Ev_MtApi_Vnc_SetEnableFec_Cmd,

	/**
  @brief   桌面双流的srtp参数上报
  @verbatim
  BODY:	wParam(TMtSrtpCrypto_Api, tMtSrtpCrypto)
  {
  "emSrtpCryptoType": 0,
  "emSrtpAuthType"  : 0,
  "dwSrtpTag"       : 0;, 
  "achCryptoKey"    : "",
  "achCryptoKeyId"  : "",
  "dwCryptoKeyIdLen": 0,
  }
  @endverbatim
*/	
	Ev_MtApi_Vnc_SrtpCrypto_Ntf,
 
    EV_UI_END(MTAPI_VNC) = EVSEG_MTAPI_VNC_END
};

#define Is_MtApiVnc_Msg(m) ((m) >= EV_UI_BGN(MTAPI_VNC) && (m) <= EV_UI_END(MTAPI_VNC))

/**@}*/

/**@}*/
#endif // _MTAPI_EVENT_VNC_H_

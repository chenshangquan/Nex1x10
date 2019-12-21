/*******************************************************************************//**
*@file          mtapi_event_vnc.h
*@brief         ʵ��MTAPI MtVncSdk ��UI(�۲���)�¼�֪ͨ�Ķ���
*
*@author        ruiyigen
*@version       5.0    
*@date          20150328
*@copyright     (c)1995-2015 Suzhou Keda Technology Co.,Ltd. All rights reserved
***********************************************************************************/
#ifndef _MTAPI_EVENT_VNC_H_
#define _MTAPI_EVENT_VNC_H_
/**@addtogroup event �¼�
*@{
*/

/**@addtogroup vncevent �ͻ���˫���¼�
*@{
*/

#include "mtapi_event_def.h"


enum EmMtApiVncEv
{
	EV_UI_BGN(MTAPI_VNC)  = EVSEG_MTAPI_VNC_BGN,

/**
  @brief    ��ǰ��������״̬ Ev_Conf_AssSndSream_Status_Ntf
  
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
  @brief   ��ǰ��������״̬ Ev_Conf_AssSndSream_Status_Rsp
  
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
  @brief    ��ǰ��������״̬ Ev_Conf_AssRcvSream_Status_Ntf	
  
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
  @brief   ��ǰ��������״̬ Ev_Conf_AssRcvSream_Status_Rsp
  
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
  @brief   ���湲��ͨ�������ϱ� Ev_Conf_PcAssStream_ChanParam_Ntf
  
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
  @brief   pc���湲��֪ͨ���濪ʼ���� Ev_Conf_PcAssStream_StartEnc_Ntf
  @verbatim
	BODY: ��
  @endverbatim
*/	
	Ev_MtApi_Vnc_PcAssStream_StartEnc_Ntf,

/**
  @brief   pc���湲��֪ͨ����ֹͣ���� Ev_Conf_PcAssStream_StopEnc_Ntf
  @verbatim
	BODY: ��
  @endverbatim
*/
	Ev_MtApi_Vnc_PcAssStream_StopEnc_Ntf,

/**
  @brief    pc���湲��֪ͨ��������ؼ�֡ Ev_Conf_PcAssStream_IFrameRequest_Ntf
  @verbatim
	BODY: ��
  @endverbatim
*/	
	Ev_MtApi_Vnc_PcAssStream_IFrameRequest_Ntf,

/**
  @brief   pc���湲��֪ͨ�������bitrate Ev_Conf_PcAssStream_SetBitrate_Cmd
  @verbatim
  BODY:	wParam(u32, dwBitrate)
  {
  "basetype": 0
  }
  @endverbatim
*/	
	Ev_MtApi_Vnc_PcAssStream_SetBitrate_Ntf,

/**
  @brief    �ն�pc�������ͳ����Ϣ����֪ͨ Ev_Conf_PCEncStatis_Req
  @verbatim
	BODY: ��
  @endverbatim
*/	
	Ev_MtApi_Vnc_PCAssEncStatisReq_Ntf,

/**
  @brief   ����pc˫��ʧ��֪ͨ Ev_Conf_AssStreamSendFailed_Ntf
  @verbatim
	BODY: ��
  @endverbatim
*/
	Ev_MtApi_Vnc_AssStreamSendFailed_Ntf,


/**
  @brief   ˫�����ͷ�֪ͨ 
  @verbatim
	MainBuf(TMtId_Api, ptMTId) �ն�ID
	SubBuf(BOOL32, bGrabbed) �Ƿ���������һ�α�������true��
  @endverbatim
*/	
	Ev_MtApi_Vnc_AssStreamSender_Ntf,


	/**
  @brief   ֪ͨUI��PC˫������������ʶ 
  @verbatim
	MainBuf(s8*, pszEndPointId) �ն˵�id, ��ǰ��֧��e164��
	SubBuf(u32, dwStreamId) ������ʾ��
  @endverbatim
*/	
	Ev_MtApi_Vnc_SetStreamID_Cmd,


	/**
  @brief   ֪ͨUI��PC˫�������Ƿ���������ǽ 
  @verbatim
	MainBuf(BOOL32, bEnble) �Ƿ���������ǽ
	MainBuf(TNetParam_Api, tNetParam)�����ַ
	 
  @endverbatim
*/	
	Ev_MtApi_Vnc_IsNatTraversal_Cmd,

		/**
  @brief   ֪ͨUI��PC˫�������Ƿ����RTP��չͷ
  @verbatim
	MainBuf(BOOL32, bEnble) �Ƿ����RTP��չͷ
	 
  @endverbatim
*/	
	Ev_MtApi_Vnc_SetBEnableRtpExStrip_Cmd,

  /**
  @brief   ���ö����ش�����
  @verbatim
	MainBuf(u16, wBufTimeSpan) 
	MainBuf(BOOL32, bRepeatSnd) 
	 
  @endverbatim
*/	
	Ev_MtApi_Vnc_SetPrsParam_Cmd,

	 /**
  @brief   ����fec�Ƿ���
  @verbatim
	MainBuf(BOOL32, bEnable) 
	 
  @endverbatim
*/	
	Ev_MtApi_Vnc_SetEnableFec_Cmd,

	/**
  @brief   ����˫����srtp�����ϱ�
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

/*******************************************************************************//**
*@file          mtapi_vcapi.h
*@brief         提供mtvideoconfapi对外接口
*
*@author        ruiyigen
*@version       5.0    
*@date          20150328
*@copyright     (c)1995-2015 Suzhou Keda Technology Co.,Ltd. All rights reserved
***********************************************************************************/
#ifndef _MTAPI_VCAPI_H_
#define _MTAPI_VCAPI_H_
/**@addtogroup api API接口
*@{
*/

/**@addtogroup vcapi 会议API
*@{
*/

#include <string.h>
#include "mtapi_export.h"
#include "mtapi_typedef.h"
#include "mtapi_struct.h"



/*
Note: 所有接口中的有req,是异步的，需要到发消息到组件拿
      Get**Cmd是异步的，发送到组件的，组件发送平台的， Get**Info 是同步的， 数据保存在Sdk中的。 
	  例如：

	  KdvMt_ConfGetConfInfoCmd: 发送到组件，组件到平台取数据， 结果在：Ev_MtApi_Vc_ConfInfo_Ntf
	  KdvMt_ConfGetConfInfoReq: 发送到组件，组件缓存数据结果在：Ev_MtApi_Vc_ConfInfo_Rsp
	  KdvMt_ConfGetCurConfInfo: 数据保存在sdk中， 同步直接拿到
	  */





/**
* KdvMt_VCIsInited
* 
* @brief mtvcapi是否进行过初始化
*
* @param	[in] void
* @return	BOOL32  TRUE ： 已初始化， FALSE：尚未初始化
* @note KdvMt_VCIsInited, KdvMt_VCUnInitalize
*/
KdvMtAPI BOOL32 KdvMtCALL KdvMt_VCIsInited();


/**
* KdvMt_VCSetNotify
* 
* @brief  注册Observer(UI)通知回调(这个函数如果没有调用则使用mtbaseapi中的回调函数)
*
* @param    [in]   cbNotify  要注册的回调函数
* @return   u32    0: success, 1: fail
* @note
*/
KdvMtAPI u32 KdvMtCALL KdvMt_VCSetNotify( IN NOTIFY_OBSERVER_CALLBACK cbNotify );

/**
* KdvMt_VCInitalize
* 
* @brief mtvcapi模块初始化（这个的调用要在mtbaseapi调用的setnotify之后）
*
* @return	u32  0: 初始化成功， 非0: 初始化失败
* @note KdvMt_VcIsInited, KdvMt_VCUnInitalize
*/
KdvMtAPI u32 KdvMtCALL KdvMt_VCInitalize( );



/**
* KdvMt_VCUnInitalize
* 
* @brief mtvcapi模块释放退出
*
* @param	[in] void
* @return	u32  0: 成功， 非0: 失败
* @note KdvMt_VCIsInited, KdvMt_VCInitalize
*/
KdvMtAPI u32 KdvMtCALL KdvMt_VCUnInitalize();


/** 终端会议控制相关 */
/**
* KdvMt_ConfMakeCallCmd
* 
* @brief   呼叫对端ip/e164/alias , 原先行业加入会议，直接呼叫对端mcu ip/e164/alias， 就是加入会议
*
* @param    [in]   pszCalledInfo  ip/alias/e164 ， sdk层自动判断字符串，判断顺序ip,e164,别名。
                                  如果别名为纯数字，下层会判断为e164号码，有可能呼叫不通
* @param    [in]   emPro          呼叫协议， ip呼叫，323默认1720， sip默认5060
* @param    [in]   wRate          呼叫码率 如果为64k, 为纯音频模式
* @param    [in]   dwSSID         MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 响应通知：
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfMakeCallCmd( IN CONST s8* pszCalledInfo, IN CONST u16 wRate, 
	                                          IN CONST EmConfProtocol_Api emPro =em323_Api,
											  IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_ConfMakeCallByTypeCmd
* 
* @brief   呼叫对端ip/e164/alias , 原先行业加入会议，直接呼叫对端mcu ip/e164/alias， 就是加入会议
*
* @param    [in]   tCalledAddr    上层自己指定是别名/e164/ip呼叫
* @param    [in]   emPro          呼叫协议
* @param    [in]   wRate          呼叫码率 如果为64k, 为纯音频模式
* @param    [in]   dwSSID         MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 响应通知：
*/

KdvMtAPI u32 KdvMtCALL KdvMt_ConfMakeCallByTypeCmd( IN CONST TMtAddr_Api tCalledAddr, IN CONST u16 wRate, 
										      IN CONST EmConfProtocol_Api emPro =em323_Api,
											  IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_ConfMainVideoOffCmd
* 
* @brief    关掉视频主流发，收 通道( 确保关通道操作，在makecall，和acceptcall之前调下来，因为平台不支持先开在关通道操作)
*
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 响应通知：
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfMainVideoOffCmd( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_ConfAcceptCmd
* 
* @brief   手动接听(拒绝接听发hungup消息)
*
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 响应通知：Ev_MtApi_Vc_P2P_Started_Ntf, Ev_MtApi_Vc_MulConf_Started_Ntf 
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfAcceptCmd( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_ConfJoinConfCmd
* 
* @brief   通过ras请求加入会议
*
* @param    [in]   tCallParam       加入会议需要的参数
* @param    [in]   dwSSID           MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 响应通知：Ev_MtApi_Vc_MulConf_Started_Ntf, Ev_MtApi_Vc_Conf_Calling_Ntf ,Ev_MtApi_Vc_PreJoinConfResult_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfJoinConfCmd( IN CONST TMtJoinConfParam_Api& tCallParam, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_ConfCreateConfCmd
* 
* @deprecated 此接口为兼容老版本，建议使用新版本接口
* @brief   通过ras 请求创建会议
*
* @param    [in]   tCallParam   要创建的会议信息 
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 响应通知：Ev_MtApi_Vc_MulConf_Started_Ntf, Ev_MtApi_Vc_Conf_Calling_Ntf 
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfCreateConfCmd( IN CONST TMtCreateConfParam_Api& tCallParam, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/** 终端会议控制相关 */
/**
* KdvMt_ConfSetupCreateConf
* 
* @brief   通过setup，创建会议, 原先行业的creatconf
*
* @param    [in]   TMtCreateConfParam_Api  创建会议参数
* @param    [in]   dwSSID         MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 响应通知：
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfSetupCreateConf( IN CONST TMtSetupCreateConfParam_Api& tCallParam, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID  );




/**
* KdvMt_ConfHangupConfCmd
* 
* @brief   挂断，不区分点对点，和多点，以及，取消呼叫，退出会议，都是这个接口
*
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 响应通知:
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfHangupConfCmd( IN CONST EmMtCallDisReason_Api emReason = emDisconnect_Normal_Api, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID ); 



/**
* KdvMt_ConfRejectConfCmd
* 
* @brief   拒绝呼叫是这个接口
*
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 响应通知:
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfRejectConfCmd( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID ); 



/**
* KdvMt_ConfGetConfLinkStateReq
* 
* @brief   当前呼叫状态请求
*
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 响应通知：Ev_MtApi_Vc_Conf_Calling_Ntf, Ev_MtApi_Vc_Conf_InComing_Ntf, Ev_MtApi_Vc_P2P_Started_Ntf, Ev_MtApi_Vc_MulConf_Started_Ntf
*                Ev_MtApi_Vc_P2P_Ended_Ntf, Ev_MtApi_Vc_MulConf_Ended_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfGetConfLinkStateReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_ConfGetCurConfLinkState
* 
* @brief   当前呼叫状态请求
* 
* @param    [out]   tMtCallInfo  当前呼叫参数，包括呼叫协议， 呼叫状态  
* @param    [in]    dwSSID       MT会话ID
* @return    u32    请求命令发送结果
*
* @note 响应通知：              
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfGetCurCallState( OUT TMtCallLinkSate_Api& tMtCallInfo, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_ConfGetConfListCmd
* 
* @brief   请求会议列表,到平台取
*
* @param    [in]   dwCmdType    要获取的会议列表类型 
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 响应通知：Ev_MtApi_Vc_ConfList_Ntf 
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfGetConfListReq( IN CONST EmConfListType_Api emConfListType, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_ConfGetConfDetailCmd
* 
* @brief   请求会议详细信息, ras 非标通过会议的e164号 获取平台的会议的详细信息，不是当前的会议详细信息
*
* @param    [in]   pszConfE164  会议的E164号码 
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 响应通知：Ev_MtApi_Vc_GetConfDetailInfo_Ntf 
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfGetConfDetailCmd( IN CONST s8* pszConfE164, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_ConfGetConfRoomNumCmd
* 
* @brief   请求会议室数量
*
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 响应通知：Ev_MtApi_Vc_RoomNum_Ntf 
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfGetConfRoomNumCmd( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_ConfGetOnLineTerListReq
* 
* @brief   请求当前会议所有在线终端信息，发req下去   ->service
*
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 响应通知：Ev_MtApi_Vc_OnLineTerList_Rsp, Ev_MtApi_Vc_OnLineTerList_Ntf 
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfGetOnLineTerListReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_ConfGetOffLineTerListReq
* 
* @brief   请求当前会议所有不在线终端    ->service
*
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 响应通知：Ev_MtApi_Vc_OffLineTerList_Rsp, Ev_MtApi_Vc_OffLineTerList_Ntf 
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfGetOffLineTerListReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_ConfGetConfInfoCmd
* 
* @brief   会议信息请求, 发到平台  ui->sdk->平台 非标
*
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 响应通知：Ev_MtApi_Vc_ConfInfo_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfGetConfInfoCmd( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_ConfGetConfInfoReq
* 
* @brief   会议信息请求       ui->sdk->mtservice->sdk
*
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 响应通知：Ev_MtApi_Vc_ConfInfo_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfGetConfInfoReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_ConfGetSelfLabelReq
* 
* @brief   请求终端当前的label 
*
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 响应通知：Ev_MtApi_Vc_TerLabel_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfGetSelfLabelReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_ConfVerifyConfPwdCmd
* 
* @brief    输入验证密码     标准
*
* @param    [in]   pszPwd       会议密码 
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    请求命令发送结果
*
* @note
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfVerifyConfPwdCmd( IN CONST s8* pszPwd, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_ConfSetPasswordDtmf
* 
* @brief    设置dtmf密码     标准
*
* @param    [in]   pszPwdDtmf   dtmf密码
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    请求命令发送结果
*
* @note
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfSetPasswordDtmfCmd(IN CONST s8 * pszPwdDtmf, IN CONST SessionID dwSSID =KMTAPI_DEF_SSID );

/**
* KdvMt_ConfDropConfTerCmd
* 
* @brief   挂断会议终端 （主席操作）  标准
*
* @param    [in]   tMtId        要挂断的终端信息
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 响应通知：Ev_MtApi_Vc_DropTerReject_Ntf, Ev_MT_ConfOnLineTerList_Ntf, Ev_MT_ConfOffLineTerList_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfDropConfTerCmd( IN CONST TMtId_Api& tMtId, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_ConfEndConfCmd
* 
* @brief   结束会议 （主席操作）  标准
*
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 响应通知：Ev_MtApi_Vc_MulConf_Ended_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfEndConfCmd( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_ConfProlongConfTimeCmd
* 
* @brief   主席延长会议 （主席操作）   sdk->平台 非标
*
* @param    [in]   wTime        主席延长的会议时长，单位为分钟
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 响应通知：Ev_MtApi_Vc_ProlongResult_Ntf， Ev_MtApi_Vc_ConfDelay_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfProlongConfTimeCmd( IN CONST u16 wTime, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_ConfInviteTerCmd
* 
* @brief   主席邀请终端 （主席操作）    sdk->平台 非标
*
* @param    [in]   tAddr        邀请的终端信息 
* @param    [in]   bVideoCall   如果是电话呼叫，忽略此字段，是否为视频呼叫  默认为true 
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 响应通知：Ev_MT_ConfOnLineTerList_Ntf, Ev_MT_ConfOffLineTerList_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfInviteTerCmd( IN CONST TMtAddr_Api& tAddr, IN CONST BOOL32 bVideoCall = TRUE, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_ConfCallOffLineTerCmd
* 
* @brief   主席呼叫离线终端 （主席操作）    非标
*
* @param    [in]   tAddr        呼叫的终端信息 
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 响应通知：Ev_MT_ConfOnLineTerList_Ntf, Ev_MT_ConfOffLineTerList_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfCallOffLineTerCmd( IN CONST TMtId_Api& tAddr, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_ConfModifyConfNameCmd
* 
* @brief   修改会议名称 （主席操作）   非标
*
* @param    [in]   pszConfName  要修改的会议名称
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 响应通知：Ev_MtApi_Vc_ModifyConfResult_Ntf, Ev_MtApi_Vc_ConfInfo_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfModifyConfNameCmd( IN CONST s8* pszConfName, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
* KdvMt_ConfModifyVmpShowAliasCmd
* 
* @brief   修改会议画面合成是否显示别名 （主席操作）
*
* @param    [in]   pszConfName  要修改的会议名称
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 响应通知：Ev_MtApi_Vc_ModifyConfResult_Ntf, Ev_MtApi_Vc_ConfInfo_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfModifyVmpShowAliasCmd( IN CONST BOOL32 bShow, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_ConfModifyConfTimeCmd
* 
* @brief   这个接口废掉，因为编译问题， 暂时放着，如果延长会议时间 选择KdvMt_ConfProlongConfTimeCmd， 如果缩短，暂时平台不支持
*
* @param    [in]   wTime        当前主席 设定的会议时长， 单位为分钟
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 响应通知：Ev_MtApi_Vc_ModifyConfResult_Ntf, Ev_MtApi_Vc_ConfInfo_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfModifyConfTimeCmd( IN CONST u16 wTime, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_ConfSetConfNoDisTurb
* 
* @brief   设置会议免打扰模式 （主席操作）
*
* @param    [in]   bDisTurb     TRUE,  开启免打扰， 不是受邀列表中的不可主动加入会议，必须由会议管理方邀请终端
                                FALSE  不开启免打扰
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 响应通知：
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfSetConfNoDisTurb( IN CONST BOOL32 bEnable, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_ConfSetConfDumb
* 
* @brief   设置会议哑音 （主席操作）  非标
*
* @param    [in]   bDumb        是否哑音,设置到平台
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 响应通知：
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfSetConfDumb( IN CONST BOOL32 bDumb, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_ConfSetRecallDial
* 
* @brief   设置电话退会后重呼 ( 主席操作，会议结束后，恢复默认值，默认为TRUE,此功能是终端做 )
*
* @param    [in]   bRecall      设置是否重新呼叫
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 响应通知：
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfSetRecallDial( IN CONST BOOL32 bRecall, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_ConfGetRecallDial
* 
* @brief    获取是否重呼
*
* @param    [out]  bRecall      获取是否重新呼叫
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 响应通知：
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfGetRecallDial( OUT BOOL32 &bRecall, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );




/**
* KdvMt_ConfDetermineRecallDial
* 
* @brief   决定电话退会后是否重呼
*
* @param    [in]   bRecall      是否重新呼叫决定
* @param    [in]   tMtId_Api    终端ID
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 响应通知：
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfDetermineRecallDial( IN CONST BOOL32 bRecall, IN CONST s8 *pchDialNum, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );//add by zwf



/**
* KdvMt_ConfAdjustH264CapRes_Cmd
* 
* @brief   调整H264格式的编解码支持的分辨率
* @note    会把底层保存的264的分辨率覆盖掉
* 
* @param    [in]   ptRes       tRes[]数组指针
* @param    [in]   dwResNum    数组个数
* @return   u32    请求命令发送结果
*
* @note 响应通知：
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfAdjustH264CapRes_Cmd( IN CONST EmMtResolution_Api *ptRes, IN CONST u32 dwResNum, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_ConfStackOnOff_Cmd
* 
* @brief   重启协议栈，先stop,再start
*     
* @param    [in]   bStart     TRUE: start, FALSE: stop
* @param    [in]   emPro      协议 323/sip/sat/tip
* @return   u32    请求命令发送结果
*
* @note 响应通知：
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfStackOnOff_Cmd( IN CONST BOOL32 bStart, IN CONST EmConfProtocol_Api emPro =em323_Api, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_ConfSetStack_Cmd
* 
* @brief   设置协议栈标准，非标
*   
* @param    [in]   bStand     TRUE: stand stack, FALSE: non-stand stack
* @param    [in]   emPro      协议 323/sip/sat/tip
* @return   u32    请求命令发送结果
*
* @note 响应通知：
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfSetStack_Cmd( IN CONST BOOL32 bStand, IN CONST EmConfProtocol_Api emPro =em323_Api, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
* KdvMt_ConfRemoteRecodeCmd
* 
* @brief   主席通知平台录像功能 （主席操作） ---暂时 平台缺消息接口
*
* @param    [in]   bStart       开始录像/结束录像
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 响应通知：Ev_MtApi_Vc_ConfInfo_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfRemoteRecodeCmd( IN CONST BOOL32 bStart, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_ConfSetConfPwdCmd
* 
* @brief   设置会议密码 （主席操作）
*
* @param    [in]   bUsedPwd     是否启用会议密码
* @param    [in]   pszPwd       要修改的会议密码
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 响应通知：Ev_MtApi_Vc_ModifyConfResult_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfSetConfPwdCmd( IN CONST BOOL32 bUsedPwd, IN CONST s8*  pszPwd = NULL, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_ConfSetAssStreamSendModCmd
* 
* @brief   修改双流发送类型 （主席操作），如果mode为emMt_Dual_Mode_SpecTer_Api
*
* @param    [in]   emMode       辅流模式
* @param    [in]   dwSSID       MT会话ID
* @return   u32    请求命令发送结果
*
* @note 响应通知：Ev_MtApi_Vc_ModifyConfResult_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfSetAssStreamSendModCmd( IN CONST EmMtDualMode_Api emMode, 
	                                                     IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_ConfApplySpeakerCmd
* 
* @brief   申请发言操作          标准
*
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 响应通知：Ev_MtApi_Vc_ApplySpeak_Ntf, Ev_MtApi_Vc_SeenByAll_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfApplySpeakerCmd( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_ConfRejectApplySpeakerCmd
* 
* @brief   拒绝申请发言操作    标准
*
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 响应通知：
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfRejectApplySpeakerCmd( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_ConfAccpetSpeakerCmd
* 
* @brief   主席同意某终端的申请发言 （主席操作）  标准
*
* @param    [in]   tMtId        同意的终端信息 
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 响应通知：Ev_MtApi_Vc_ApplySpeak_Ntf, Ev_MtApi_Vc_SeenByAll_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfAccpetSpeakerCmd( IN CONST TMtId_Api& tMtId, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_ConfChairSpecSpeakerCmd
* 
* @brief   主席指定发言终端 （主席操作）  标准
*
* @param    [in]   tMtId        同意的终端信息 
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 响应通知：Ev_MtApi_Vc_ApplySpeak_Ntf, Ev_MtApi_Vc_SeenByAll_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfChairSpecSpeakerCmd( IN CONST TMtId_Api& tMtId, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_ConfChairCancelSpeakerCmd
* 
* @brief   取消发言人 （主席操作或者发言人自己 可以取消， 名字后续改掉）  标准
*
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 响应通知：
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfChairCancelSpeakerCmd( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_ConfGetVideoSeeingReq
* 
* @brief   获取正在观看的视频源请求
*
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    请求发送结果
*
* @note 响应通知：Ev_MtApi_Vc_YouAreSeeing_Rsp, Ev_MtApi_Vc_YouAreSeeing_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfGetVideoSeeingReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_ConfApplyChairmanCmd
* 
* @brief   申请主席请求   标准
*
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 响应通知: Ev_MtApi_Vc_ChairTokenGet_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfApplyChairmanCmd( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_ConfRejectApplyChairmanCmd
* 
* @brief   拒绝申请主席请求   标准
*
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 响应通知: 
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfRejectApplyChairmanCmd( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_ConfWithDrawChairmanCmd
* 
* @brief   释放主席权限 （主席操作）  标准
*
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 响应通知  如果撤销成功， 会收到 Ev_MtApi_Vc_ChairPos_Ntf, 并且里面的位置为 terid为0， 表示当前没有主席
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfWithDrawChairmanCmd( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_ConfWhoIsChairCmd
* 
* @brief   终端查询当前主席    标准
*
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 响应通知：Ev_MtApi_Vc_ChairPos_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfWhoIsChairCmd( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_ConfChairSpecNewChairCmd
* 
* @brief   主席指定新主席终端 （主席操作）  sdk->平台 非标
*
* @param    [in]   tMtId        要指定的主席终端信息 
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 响应通知：Ev_MtApi_Vc_ChairPos_Ntf或者Ev_MtApi_Vc_SimpleConfInfo_Ntf或者Ev_MtApi_Vc_ConfInfo_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfChairSpecNewChairCmd( IN CONST TMtId_Api& tMtId, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_ConfSeeSpecTerAss
* 
* @brief   终端选看某一个终端的双流 （主席操作）(当前 很多人都在发双流)
*
* @param    [in]   tMtId        要选看的终端信息 
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 响应通知：
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfSeeSpecTerAssCmd( IN CONST TMtId_Api& tMtId, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
* KdvMt_ConfIsChairSeeSpecTer
* 
* @brief    获取是否在选看， 如果TRUE, 调用这个接口KdvMt_ConfGetCurViewTerParam 获取参数

* @param    [out]  bView        当前是否在选看，
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    0：获取成功  其他错误码
*
* @note 更新通知：
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfIsChairSeeSpecTer( OUT BOOL32 &bView, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_ConfGetCurViewTerParam
* 
* @brief    获取当前选看参数
* @param    [out]  tParam       选看参数
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    0：获取成功  其他错误码
*
* @note 更新通知：
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfGetCurViewTerParam( OUT TViewTerParam_Api &tParam, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_ConfGetViewTerParamReq
* 
* @brief    得到选看参数
*
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    0：获取成功  其他错误码
*
* @note 更新通知：
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfGetViewTerParamReq(  IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_ConfSeeSpecTerCmd
* 
* @brief   终端选看 （主席操作）    Ev_Mtpa_SendThisTer_Cmd如果选看类型是 av, 是标准信令， 如果选看类型是audio或者video, 是非标信令
								   Ev_Mtpa_SelectViewChan_Cmd 非标
* @note    如果是选看双流通道，仅用在sip，sip下多点会议可以有多个终端都发双流，可以选看某一个终端的双流
* @param    [in]   tParam        选看终端的参数
* @param    [in]   dwSSID        MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 响应通知：
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfSeeSpecTerCmd( IN CONST TViewTerParam_Api &tParam, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_ConfCancelSeeTerCmd
* 
* @brief   取消选看 （主席操作）   指定选看某一路为非标Ev_Mtpa_CacelSelecttViewChan_Cmd
*								  Ev_Mtpa_CancelSendThisTer_Cmd为标准
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 响应通知：
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfCancelSeeTerCmd( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_ConfApplyChimeCmd
* 
* @brief   申请插话      ->平台 非标
*
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 响应通知：Ev_MtApi_Vc_ChimeInState_Ntf, Ev_MtApi_Vc_ApplyChimeIn_Ntf, Ev_MtApi_Vc_ChimeInFailed_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfApplyChimeCmd( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_ConfRejectApplyChimeCmd
* 
* @brief   拒绝申请插话 
*
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 响应通知：
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfRejectApplyChimeCmd( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_ConfAcceptChimeCmd
* 
* @brief   主席同意插话 （主席操作）, 指定插话同一个接口
*
* @param    [in]   tMtId        同意插话的终端信息 
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 响应通知：Ev_MtApi_Vc_MixParam_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfAcceptChimeCmd( IN CONST TMtId_Api& tMtId, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_ConfChairSpecChimeCmd
* 
* @brief   主席指定插话终端 （主席操作）    ->平台 非标
*
* @param    [in]   tMtId        主席指定的插话终端信息 
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 响应通知：Ev_MtApi_Vc_MixParam_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfChairSpecChimeCmd( IN CONST TMtId_Api& tMtId, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_ConfMtChairPollCmd
* 
* @brief   主席轮询 （主席操作）    ->平台 非标
*
* @param    [in]   tMtPollInfo  终端轮询信息 
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 响应通知：Ev_MtApi_Vc_ConfInfo_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfMtChairPollCmd( IN CONST TMtPollInfo_Api& tMtPollInfo, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_ConfGetSpecTerStatusCmd
* 
* @brief  	//获取指定终端的状态信息 ui->sdk->平台->sdk  非标
*             如果是5.0平台，主席终端：不需调这个接口，非主席终端状态变化，5.0平台会推送过来
                             非主席终端: 如果要确切知道别的终端的状态，需要一直调
			  如果是老平台， 因为老平台不会推送终端的状态，所以需要上层调用这个接口后，sdk中才有缓存的数据， 
			  调KdvMt_ConfGetTerCurStatusById才有值

* @param    [in]   tMtId        要获取的终端信息
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 响应通知：Ev_MtApi_Vc_GetTerStatus_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfGetSpecTerStatusCmd( IN CONST TMtId_Api& tMtId, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* kdvmt_ConfGetSpecCurStatusById
* 
* @brief   获取指定终端当前状态信息 ui->sdk 返回终端状态信息
		   注：如果是 5.0平台，主席终端，直接调这个接口，因为终端状态变化， 平台会推送过来
		       其它情况，例如非5.0平台， 或者5.0平台，非主席终端，需要KdvMt_ConfGetSpecTerStatusCmd之后调这个接口,
			   否则获取的sdk缓存的数据不是最新的或者为空
*
* @param    [out]  tCurTerEntityStatus        返回的终端信息
* @param    [in]   tMtId                      终端ID
* @param    [in]   dwSSID                     MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 响应通知：Ev_MtApi_Vc_GetTerStatus_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfGetTerCurStatusById( OUT TMtEntityStatus_Api& tCurTerEntityStatus, IN CONST TMtId_Api& tMtId, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_ConfGetTerListStatusCmd
* 
* @brief   获取当前mtconf中保存的终端列表的状态信息   UI->sdk
*
* @param    [in]   tMtId        要获取的终端信息
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 响应通知：Ev_MtApi_Vc_GetTerStatusList_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfGetTerListStatusReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_ConfStartForceBroadcastCmd
* 
* @brief   主席强制广播         非标
*
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 响应通知：Ev_MtApi_Vc_ConfInfo_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfStartForceBroadcastCmd( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_ConfStopForceBroadcastCmd
* 
* @brief   主席停止强制广播   非标
*
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 响应通知：Ev_MtApi_Vc_ConfInfo_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfStopForceBroadcastCmd( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_ConfStartVacCmd
* 
* @brief   开始语音激励  （主席操作）   ui->平台 非标
*
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 响应通知：Ev_MtApi_Vc_StartVACResult_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfStartVacCmd( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_ConfStopVacCmd
* 
* @brief   停止语音激励  （主席操作）  ui->平台 非标
*
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 响应通知：Ev_MtApi_Vc_StopVACResult_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfStopVacCmd( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_ConfStartDiscussCmd
* 
* @brief   开始讨论模式 （智能混音， 全部混音）  ->平台 非标
*
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 响应通知：Ev_MtApi_Vc_StartDiscussResult_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfStartDiscussCmd( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_ConfStopDiscussCmd
* 
* @brief   停止讨论模块    ->平台 非标
*
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 响应通知：Ev_MtApi_Vc_StopDiscussResult_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfStopDiscussCmd( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
* KdvMt_ConfStartConfVMPCmd
* 
* @brief   开始自主画面合成（端口会议）
*
* @param    [in]   tMtVmpParam  画面合成信息
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 响应通知：Ev_MtApi_Vc_StartCustomVMPResult_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfStartCustomVMPCmd( IN CONST TMtCustomVmpParam_Api& tMtVmpParam, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_ConfStopConfVMPCmd
* 
* @brief   停止会议画面合成（端口会议）
*
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 响应通知：Ev_MtApi_Vc_StopCustomVMPResult_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfStopCustomVMPCmd( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_ConfSetConfVMPParamCmd
* 
* @brief  改变画面合成参数信息 （端口会议）
*
* @param    [in]   tMtVmpParam  更新的画面合成信息
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 响应通知：Ev_MtApi_Vc_SetCustomVMPResult_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfSetCustomVMPParamCmd( IN CONST TMtCustomVmpParam_Api& tMtVmpParam, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_ConfStartConfVMPCmd
* 
* @brief   开始会议画面合成（主席操作）->平台 非标
*
* @param    [in]   tMtVmpParam  画面合成信息
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 响应通知：Ev_MtApi_Vc_StartConfVMPResult_Ntf, Ev_MtApi_Vc_StopConfVMPResult_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfStartConfVMPCmd( IN CONST TMtVmpParam_Api& tMtVmpParam, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_ConfStopConfVMPCmd
* 
* @brief   停止会议画面合成（主席操作） ->平台 非标
*
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 响应通知：Ev_MtApi_Vc_StopConfVMPResult_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfStopConfVMPCmd( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_ConfSetConfVMPParamCmd
* 
* @brief  设置画面合成参数信息 （主席操作）  ->平台 非标
*
* @param    [in]   tMtVmpParam  更新的画面合成信息
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 响应通知：Ev_MtApi_Vc_SetConfVMPResult_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfSetConfVMPParamCmd( IN CONST TMtVmpParam_Api& tMtVmpParam, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_ConfGetConfVMPParamCmd
* 
* @brief  获取画面合成参数   ->平台 非标
*
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 响应通知：Ev_MtApi_Vc_GetConfVMPResult_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfGetConfVMPParamCmd( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_ConfSetTerMuteCmd
* 
* @brief  远端哑音 （主席操作）    ->平台 非标
*
* @param    [in]   tMtId        远端终端信息
* @param    [in]   bMute        TRUE:哑音 FALSE:非哑音
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 响应通知：
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfSetTerMuteCmd( IN CONST TMtId_Api& tMtId, IN CONST BOOL32 bMute, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );	


/**
* KdvMt_ConfSetTerQuiteCmd
* 
* @brief  远端静音 （主席操作）   ->平台 非标
*
* @param    [in]   tMtId        远端终端信息
* @param    [in]   bQuiet       TRUE:静音 FALSE:哑音
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 响应通知：
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfSetTerQuiteCmd( IN CONST TMtId_Api& tMtId, IN CONST BOOL32 bQuiet, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_ConfSwitchBroadCastStyleCmd
* 
* @brief  切换画面合成风格 （主席操作）
*
* @param    [in]   bSingle      TRUE:单屏 FALSE:画中画
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfSwitchBroadCastStyleCmd( IN CONST BOOL32 bSingle, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_ConfSelectVmpCmd
* 
* @brief  终端选看画面合成请求(仅限主席MT)    非标
*
* @param    [in]   bStart       TRUE:选看 FALSE:取消选看
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 响应通知：Ev_MtApi_Vc_SelectConfVmpResult_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfSelectVmpCmd( IN CONST BOOL32 bStart, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_ConfStartCustomMixCmd
* 
* @brief 开始定制混音
*
* @param    [in]   pArr         参加混音的成员，pArr是数组
* @byCount  [in]   byCount      数组个数
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 响应通知：
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfStartCustomMixCmd( IN CONST TMtId_Api* ptArrMt, u8 byCount,  IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_ConfStopCustomMixCmd
* 
* @brief 停止定制混音
*
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 响应通知：
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfStopCustomMixCmd( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_ConfAddMixMemberCmd
* 
* @brief  添加混音成员请求
*
* @param    [in]   ptArrMt      要添加的终端数, 数组[]
* @param    [in]   byCount      终端个数
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 响应通知：Ev_MtApi_Vc_MixParam_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfAddMixMemberCmd( IN CONST TMtId_Api* ptArrMt, u8 byCount, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_ConfRemoveMixMemberCmd
* 
* @brief  删除混音成员请求
*
* @param    [in]   tMtId        要删除的终端信息
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 响应通知：Ev_MtApi_Vc_MixParam_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfRemoveMixMemberCmd( IN CONST TMtId_Api* ptArrMt, u8 byCount, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_ConfGetMixMemberListReq
* 
* @brief  获取混音成员列表请求
*
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 响应通知：Ev_MtApi_Vc_MixParam_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfGetMixMemberListReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_ConfSendConfSmsCmd
* 
* @brief  短消息发送(这个主要是硬终端使用)       ->平台 非标
* @短消息长度较大 经4.7平台转发时，会被平台截去一部分，截去后表现为：消息头+消息体 = 139字节
*
* @param    [in]   tShortMsg    要发送的短消息信息 
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 响应通知：Ev_MtApi_Vc_SMS_Ntf
*/

KdvMtAPI u32 KdvMtCALL KdvMt_ConfSendConfSmsCmd( IN CONST TShortMsg_Api& tShortMsg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_ConfIsInP2PConf
* 
* @brief   是否点对点会议中
*
* @param    [out]  bInP2PConf   TRUE:点对点会议中 FALSE:不在点对点会议中
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    0：获取成功  其他错误码
*
* @note 
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfIsInP2PConf( OUT BOOL32& bInP2PConf, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_ConfIsInMulConf
* 
* @brief   是否在多点会议中
*
* @param    [out]  bInMulConf   TRUE:多点会议中 FALSE:不在多点会议中
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    0：获取成功  其他错误码
* @note
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfIsInMulConf( OUT BOOL32& bInMulConf, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_ConfIsInConf
* 
* @brief   是否在会议中
*
* @param    [out]  bInConf      TRUE:会议中 FALSE:不在会议中
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    0：获取成功  其他错误码
* @note 在点对点或者多点中 即表示在会议中
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfIsInConf( OUT BOOL32& bInConf, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
* KdvMt_ConfIsCalling
* 
* @brief   是否呼叫/被呼叫中
*
* @param    [out]  bCalling     TRUE:呼叫中 FALSE:非呼叫中
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    0：获取成功  其他错误码
* @note 
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfIsCalling( OUT BOOL32& bCalling, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
* KdvMt_ConfIsEncryptConf
* 
* @brief   当前会议是否加密
*
* @param    [out]  bEncrypt     TRUE:加密会议 FALSE:非加密会议
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    0：获取成功  其他错误码
*
* @note 更新通知：Ev_MtApi_Vc_CallEncrypt_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfIsEncryptConf( OUT BOOL32& bEncrypt, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_ConfIsEncryptConfReq
* 
* @brief   当前会议是否加密请求
*
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 响应通知：Ev_MT_BLL_Conf_CallEncrypt_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfIsEncryptConfReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_ConfGetEncryptTypeReq
* 
* @brief   获取会议信息 数据加密类型的请求
*
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 响应通知：Ev_MtApi_Vc_GetEncryptType_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfGetEncryptTypeReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_ConfIsInChime
* 
* @brief   本地终端是否在插话
*
* @param    [out]  bInChime     TRUE:插话中 FALSE:非插话中
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    0：获取成功  其他错误码
*
* @note 更新通知：Ev_MtApi_Vc_ChimeInState_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfIsInChime( OUT BOOL32& bInChime, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_ConfIsInChime
* 
* @brief   本地终端是否是 自定义混音
*
* @param    [out]  bCustomMix   
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    0：获取成功  其他错误码
*
* @note 更新通知：Ev_MtApi_Vc_StartCustomMixResult_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfIsCustomMix( OUT BOOL32& bCustomMix, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_ConfIsInChairVmp
* 
* @brief   是否在主席会议的画面合成中, 会议合成
*
* @param    [out]  bInChairVmp  TRUE:主席画面合成中 FALSE:非画面合成中
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    0：获取成功  其他错误码
*
* @note 更新通知：Ev_MtApi_Vc_StartVMPResult_Ntf, Ev_MtApi_Vc_StopVMPResult_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfIsInChairVmp( OUT BOOL32& bInChairVmp, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_ConfIsInCustomVmp
* 
* @brief   是否在自主画面合成中
*
* @param    [out]  bInCustomVmp  TRUE:主席画面合成中 FALSE:非画面合成中
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    0：获取成功  其他错误码
*
* @note 更新通知：
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfIsInCustomVmp( OUT BOOL32& bInCustomVmp, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_ConfIsInVAC
* 
* @brief   是否开启语音激励
*
* @param    [out]  bInChairVmp  TRUE:开启 FALSE:未开启
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    0：获取成功  其他错误码
*
* @note 更新通知：Ev_MtApi_Vc_StartVACResult_Ntf,Ev_MtApi_Vc_StopVACResult_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfIsInVAC( OUT BOOL32& bInVAC, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_ConfIsInPoll
* 
* @brief   是否在轮询
*
* @param    [out]  bInPoll     TRUE:开启 FALSE:未开启
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    0：获取成功  其他错误码
*
* @note 更新通知：
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfIsInPoll( OUT BOOL32& bInPoll, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_ConfGetPollingMt
* 
* @brief   获取当前正在轮询的终端mt  ui->sdk
*
* @param    [out]  tPollingMt   当前正在轮询的终端id
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    0：获取成功  其他错误码
*
* @note 更新通知：
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfGetPollingMt( OUT TMtId_Api& tPollingMt, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_ConfIsDiscussMode
* 
* @brief   是否会议讨论模式
*
* @param    [out]  bInDiscussMode  TRUE:讨论模式 FALSE:非讨论模式
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    0：获取成功  其他错误码
*
* @note 更新通知：Ev_MtApi_Vc_StartDiscussResult_Ntf,Ev_MtApi_Vc_StopDiscussResult_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfIsDiscussMode( OUT BOOL32& bInDiscussMode, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_ConfIsInChairSelVmp
* 
* @brief   是否主席选看画面合成
*
* @param    [out]  bInChairSelVmp  TRUE:是 FALSE:否
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    0：获取成功  其他错误码
*
* @note 更新通知：Ev_MtApi_Vc_mtSelectVmpResult_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfIsInChairSelVmp( OUT BOOL32& bInChairSelVmp, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_ConfIsSeeSpecTerAss
* 
* @brief   是否主席选看某一个终端的双流
*
* @param    [out]  bSeeSpecTerAss  TRUE:是 FALSE:否
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    0：获取成功  其他错误码
*
* @note 更新通知：
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfIsSeeSpecTerAss( OUT BOOL32& bSeeSpecTerAss, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
* KdvMt_ConfGetTotalRoomNum
* 
* @brief   获取可用的总的会议室数量
*
* @param    [out]  dwTotalRoomNum  可用的数量
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    0：获取成功  其他错误码
*
* @note 更新通知：Ev_MtApi_Vc_RoomNum_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfGetTotalRoomNum( OUT u32& dwTotalRoomNum, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_ConfGetUsedRoomNum
* 
* @brief   获取已用的会议室数量
*
* @param    [out]  dwUsedRoomNum  已用的数量
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    0：获取成功  其他错误码
*
* @note 
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfGetUsedRoomNum( OUT u32& dwUsedRoomNum, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_ConfGetConfRemainTime
* 
* @brief   获取结束会议到计时时间
*          这个接口用法：  平台在会议快结束的时候会发Ev_MtApi_Vc_ConfWillEnd_Ntf， 剩余的时间，sdk会缓存，
                           如果平台没法Ev_MtApi_Vc_ConfWillEnd_Ntf, 缓存的时间是0.
* @param    [out]  dwConfRemainTime  剩余时间（分钟）
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    0：获取成功  其他错误码
*
* @note
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfGetConfRemainTime( OUT u32& dwConfRemainTime, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_ConfGetMissedCallParam
* 
* @brief   获取会议中呼叫到来未接的信息
*
* @param    [out]  tKdvMtCALLParam  呼叫到来详细信息
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    0：获取成功  其他错误码
*
* @note 更新通知：Ev_MtApi_Vc_CallMissed_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfGetMissedCallParam( OUT TMtMissCallParam_Api& tKdvMtCALLParam, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_ConfGetSelfMtID
* 
* @brief   获取自己的mtid信息(多点会议中)
*
* @param    [out]  tMtId       自身的MtId信息
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    0：获取成功  其他错误码
*
* @note 更新通知：Ev_MtApi_Vc_TerLabel_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfGetSelfMtID( OUT TMtId_Api& tMtId, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_ConfGetPeerCapInfo
* 
* @brief   获取对端的能力信息, 暂时没实现
*
* @param    [out]  tPeerCapabilityInfo   对端能力详细信息
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    0：获取成功  其他错误码
*
* @note 更新通知：Ev_MtApi_Vc_PeerCap_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfGetPeerCapInfo( OUT TPeerCapabilityInfo_Api& tPeerCapabilityInfo, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_ConfGetPeerVideoAlias
* 
* @brief   获取对端的视频源参数
*
* @param    [out]  tPeerInfo    对端的视频源参数
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    0：获取成功  其他错误码
*
* @note 更新通知：
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfGetPeerVideoAlias( OUT TMultiVideoAlias_Api& tPeerInfo, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_ConfGetPeerVideoAliasReq
* 
* @brief   请求对端的视频源参数
*
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    0：获取成功  其他错误码
*
* @note 更新通知：Ev_MtApi_Vc_PeerVidSouce_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfGetPeerVideoAliasReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
* KdvMt_ConfGetPeerVideoAlias
* 
* @brief   获取对端的当前的视频源
*
* @param    [out]  tPeerInfo   对端的当前的视频源
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    0：获取成功  其他错误码
*
* @note 更新通知
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfGetPeerVideoSrc( OUT TMultiVideoInfo_Api& tPeerInfo, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_ConfGetTerVidAliasCmd
* 
* @brief   主席获取终端tmtid的视频源列表，用在多点，只有主席有权限，5.0平台支持，非标
*
* @param    [out]  tMtid        对端的当前的视频源
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    0：获取成功  其他错误码
*
* @note Ev_MtApi_Vc_TerGetTerVidAlias_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfGetTerVidAliasCmd( IN CONST TMtId_Api &tMtid, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
* KdvMt_ConfGetPeerVideoSrcReq
* 
* @brief   请求对端的当前的视频源
*
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    0：获取成功  其他错误码
*
* @note 更新通知：Ev_MtApi_Vc_PeerVidSouce_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfGetPeerVideoSrcReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );





/**
* KdvMt_ConfGetCurConfInfo
* 
* @brief   获取当前会议信息   ui->sdk
*
* @param    [out]  tMtConfInfo  当前会议详细信息
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    0：获取成功  其他错误码
*
* @note 更新通知：Ev_MtApi_Vc_ConfInfo_Ntf,Ev_MtApi_Vc_ConfInfo_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfGetCurConfInfo( OUT TMtConfInfo_Api& tMtConfInfo, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_ConfGetCurSimpConfInfo
* 
* @brief   获取当前会议简单信息
*
* @param    [out]  tMtSimpConfInfo  当前会议详细信息
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    0：获取成功  其他错误码
*
* @note 更新通知：Ev_MtApi_Vc_ConfInfo_Ntf,Ev_MtApi_Vc_ConfInfo_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfGetCurSimpConfInfo( OUT TMtSimpConfInfo_Api& tMtSimpConfInfo, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_ConfGetSpeaker
* 
* @brief   获取发言终端
*
* @param    [out]  tMtEntityInfo  当前发言终端
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    0：获取成功  其他错误码
*
* @note 更新通知：Ev_MtApi_Vc_ApplySpeak_Ntf, Ev_MtApi_Vc_SeenByAll_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfGetSpeaker( OUT TMtId_Api& tMtEntityInfo, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_ConfGetChairman
* 
* @brief   获取主席终端
*
* @param    [out]  tMtEntityInfo  当前主席终端
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    0：获取成功  其他错误码
*
* @note 更新通知：Ev_MtApi_Vc_Chair_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfGetChairman( OUT TMtId_Api& tMtEntityInfo, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
* KdvMt_ConfChairSpecVipCmd
* 
* @brief   主席指定Vip（主席操作)  非标
*
* @param    [in]   TMtId_Api*   终端列表，这里必须是数组
* @param    [in]   dwNum        终端数量
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 响应通知：
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfChairSpecVipListCmd( IN CONST TMtId_Api* ptMtId, IN CONST u32 dwNum, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
* KdvMt_GetGkMtlist
* @brief   获取gk 联系人列表，用于兼容
*
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 
*/
KdvMtAPI u32 KdvMtCALL KdvMt_GetGkMtlist(  IN CONST SessionID dwSSID = KMTAPI_DEF_SSID ); 



/**
* KdvMt_ConfChairSpecTerSendAssParamReq
* 
* @brief   主席指定终端发双流参数请求  ->service 拿参数
*
* @param    [in]   tMtId        终端id
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 响应通知：
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfChairSpecTerSendAssParamReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
* KdvMt_ConfChairSpecTerSendAssCmd
* 
* @brief   主席指定终端发双流 （chair->mc， mc->ter  ter 发双流）  非标
*
* @param    [in]   tMtId        终端id
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 响应通知：
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfChairSpecTerSendAssCmd( IN CONST TMtId_Api &tMtId, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_ConfGetVipList
* 
* @brief   获取当前Vip列表    ui->sdk
*
* @param    [out]      ptArrMt    vip列表数组,保证足够大
* @param    [out]      nCount     获取列表个数， 最多 KMTAPI_MAX_CONF_MT_VIPLIST_NUM
* @return   u32        0：获取成功  其他错误码
*
* @note 更新通知：Ev_MtApi_Vc_Chair_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfGetCurVipList( OUT TMtId_Api *ptArrMt, OUT u32 &nCount, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_ConfGetVipListReq
* 
* @brief   请求当前Vip列表   ui->sdk->service->sdk
*
* @return   u32        0：获取成功  其他错误码
*
* @note 更新通知：Ev_MtApi_Vc_Chair_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfGetVipListReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_ConfGetSeenMt
* 
* @brief   获取选看终端
*
* @param    [out]  tMtEntityInfo  选看终端
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    0：获取成功  其他错误码
*
* @note 更新通知：Ev_MtApi_Vc_SeenByAll_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfGetSeenMt( OUT TMtId_Api& tMtEntityInfo, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_ConfGetVideoSrcMt
* 
* @brief   获取当前视频源终端信息
*
* @param    [out]  tVideoSrcMtInfo  当前视频源终端信息
* @param    [out]  EmBitStreamIndex_Api  通道id， 从0开始

* @param    [in]   dwSSID       MT会话ID 
* @return   u32    0：获取成功  其他错误码
*
* @note 更新通知：Ev_MtApi_Vc_YouAreSeeing_Ntf,Ev_MtApi_Vc_YouAreSeeing_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfGetVideoSrcMt( OUT TMtId_Api& tVideoSrcMtInfo, IN CONST EmCodecComponentIndex_Api emChanIdx = em1st_Api, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_ConfGetMixParam
* 
* @brief   获取混音参数信息
*
* @param    [out]  tMtMixParam  混音参数信息信息
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    0：获取成功  其他错误码
*
* @note 更新通知：
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfGetMixParam( OUT TMtMixParam_Api& tMtMixParam, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_ConfGetConfVmpParam
* 
* @brief   获取会议画面合成参数信息
*
* @param    [out]  tMtVmpParam  会议画面合成参数
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    0：获取成功  其他错误码
*
* @note 更新通知：
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfGetCurConfVmpParam( OUT TMtVmpParam_Api& tMtVmpParam, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_ConfGetCustomVmpParam
* 
* @brief   获取自主画面合成参数
*
* @param    [out]  tMtCustomVmpParam  自主画面合成参数
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    0：获取成功  其他错误码
*
* @note 更新通知：
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfGetCurCustomVmpParam( OUT TMtCustomVmpParam_Api& tMtCustomVmpParam, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
* KdvMt_ConfGetCustomVmpParamReq
* 
* @brief   请求自主画面合成参数
*
* @param   
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    0：获取成功  其他错误码
*
* @note 更新通知：
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfGetCustomVmpParamReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_ConfGetConfListCnt
* 
* @brief   获取用户会议列表个数
*
* @param    [out]  dwCnt            会议个数
* @param    [in]  emConfListType   会议室类型(正在召开,预约,空闲,全部)
* @param    [in]   dwSSID           MT会话ID 
* @return   u32    0：获取成功  其他错误码
*
* @note 更新通知：Ev_MtApi_Vc_ConfList_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfGetCurConfListCnt(  OUT u32& dwCnt, IN CONST EmConfListType_Api emConfListType, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_ConfGetConfList
* 
* @brief   获取用户会议列表
*
* @param    [in]     dwStartIdx        从第几个开始获取
* @param    [out]    ptOutBuf          存储获取数据的buf(外部创建，请保证足够大)
* @param    [inout]  dwCnt             获取个数, 如果dwcnt为0， 下层会认为获取所有的
* @param    [in]     emConfListType    会议室类型(正在召开,预约,空闲,全部)
* @param    [in]     dwSSID            MT会话ID 
* @return   u32      0： 获取成功  其他错误码
*
* @note 更新通知：Ev_MtApi_Vc_ConfList_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfGetCurConfList( IN CONST u32 dwStartIdx,  OUT TMtConfNameInfo_Api* ptOutBuf, INOUT u32& dwCnt, IN CONST EmConfListType_Api emConfListType, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_ConfGetCurPollParam
* 
* @brief   获取当前轮询参数  ui->sdk
*
* @param    [out]    tPollParam        当前的轮询参数
* @param    [in]     dwSSID            MT会话ID 
* @return   u32      0： 获取成功  其他错误码
*
* @note 更新通知：
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfGetCurPollParam( IN TMtPollInfo_Api &tPollParam, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_ConfGetPollParamReq
* 
* @brief    请求当前的轮询参数  ui->sdk->mtconf->sdk
*
* @param    [in]     dwSSID            MT会话ID 
* @return   u32      0： 获取成功  其他错误码
*
* @note 更新通知：
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfGetPollParamReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_ConfGetLastConfDetail
* 
* @brief   获取会议详细信息, 上层调用了多次KdvMt_ConfGetConfDetailCmd, sdk中只保存最后一次的detail信息，
*
* @param    [out]  tConfDetail      sdk中最保存最近一次的 会议详细信息 
* @param    [in]   dwSSID           MT会话ID 
* @return   u32    0：获取成功      其他错误码
*
* @note 更新通知：Ev_MtApi_Vc_GetConfDetailInfo_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfGetLastConfDetail( OUT TMtConfDetailInfo_Api &tConfDetail, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_ConfGetConfMtMemberCnt
* 
* @brief   获取与会成员个数
*
* @param    [out]  dwCnt            成员个数
* @param    [in]   dwSSID           MT会话ID 
* @return   u32    0：获取成功  其他错误码
*
* @note 更新通知：Ev_MtApi_Vc_OnLineTerList_Ntf, Ev_MtApi_Vc_OnLineTerList_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfGetConfMtMemberCnt( OUT u32& dwCnt, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_ConfGetConfMtMember
* 
* @brief   获取会议与会成员列表
*
* @param    [out]     ptOutBuf         存储获取数据的buf(外部创建，请保证足够大)， 应该是数组， 从第0个位置开始拷贝到第dwcnt个
* @param    [inout]   dwCnt            获取个数
* @param    [in]      dwStartIdx       从第几个开始获取
* @param    [in]      dwSSID           MT会话ID 
* @return   u32    0：获取成功  其他错误码
*
* @note 更新通知：Ev_MtApi_Vc_OnLineTerList_Ntf, Ev_MtApi_Vc_OnLineTerList_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfGetConfMtMember(OUT TMTEntityInfo_Api* ptOutBuf, INOUT u32 &dwCnt,  IN CONST u32 dwStartIdx = 0, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_ConfGetTerEntityBaseId
* 
* @brief    根据终端的terid,  获取终端的EntityInfo 信息
*           如果找不到响应的id, 那么返回的tEntityInfo 都是初始值
* @param    [out]     tEntityInfo    终端的EntityInfo 信息
* @param    [in]      TMtId_Api      终端的id
* @param    [in]      dwSSID         MT会话ID 
* @return   u32    0：获取成功  其他错误码
*
* @note 更新通知：
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfGetTerEntityBaseId(OUT TMTEntityInfo_Api &tEntityInfo, IN TMtId_Api &tMtid, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
* KdvMt_ConfGetConfMtMemberStatusCnt
* 
* @brief   获取与会成员状态个数
*
* @param    [out]  dwCnt            成员状态个数
* @param    [in]   dwSSID           MT会话ID 
* @return   u32    0：获取成功  其他错误码
*
* @note 更新通知：Ev_MtApi_Vc_GetTerStatus_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfGetConfMtMemberStatusCnt( OUT u32& dwCnt, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_ConfGetConfMtMemberStatus
* 
* @brief   获取与会成员状态列表
*
* @param    [in]  dwStartIdx       从第几个开始获取
* @param    [out]  ptOutBuf         存储获取数据的buf(外部创建，请保证足够大)
* @param    [inout]  dwCnt            获取个数
* @param    [in]   dwSSID           MT会话ID 
* @return   u32    0：获取成功  其他错误码
*
* @note 更新通知：Ev_MtApi_Vc_GetTerStatus_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfGetConfMtMemberStatus( IN CONST u32 dwStartIdx,  TMtEntityStatus_Api* ptOutBuf, INOUT u32& dwCnt, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_ConfGetApplySpeakerListCnt
* 
* @brief   获取申请发言个数(主席终端使用)
*
* @param    [out]  dwCnt            申请发言终端个数
* @param    [in]   dwSSID           MT会话ID 
* @return   u32    0：获取成功  其他错误码
*
* @note 更新通知：Ev_MtApi_Vc_ApplySpeak_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfGetApplySpeakerListCnt( OUT u32& dwCnt, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_ConfGetApplyChairmanListCnt
* 
* @brief   获取申请主席个数(主席终端使用)
*
* @param    [out]  dwCnt            申请主席终端个数
* @param    [in]   dwSSID           MT会话ID 
* @return   u32    0：获取成功  其他错误码
*
* @note 更新通知：Ev_MtApi_Vc_ApplyChair_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfGetApplyChairmanListCnt( OUT u32& dwCnt, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_ConfGetApplyChaimeInListCnt
* 
* @brief   获取申请插话个数(主席终端使用)
*
* @param    [out]  dwCnt            申请插话终端个数
* @param    [in]   dwSSID           MT会话ID 
* @return   u32    0：获取成功  其他错误码
*
* @note 更新通知：Ev_MtApi_Vc_ApplyChimeIn_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfGetApplyChimeInListCnt( OUT u32& dwCnt, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_ConfGetApplySpeakerList
* 
* @brief   获取申请发言人列表(主席终端使用)
*
* @param    [in]  dwStartIdx       从第几个开始获取
* @param    [out]  ptOutBuf         存储获取数据的buf(外部创建，请保证足够大)
* @param    [inout]  dwCnt            获取个数
* @param    [in]   dwSSID           MT会话ID 
* @return   u32    0：获取成功  其他错误码
*
* @note 更新通知：Ev_MtApi_Vc_ApplySpeak_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfGetApplySpeakerList( IN CONST u32 dwStartIdx, OUT TMtId_Api* ptOutBuf, INOUT u32& dwCnt, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_ConfGetApplyChairmanList
* 
* @brief   获取申请主席列表(主席终端使用)
*
* @param    [in]  dwStartIdx       从第几个开始获取
* @param    [out]  ptOutBuf         存储获取数据的buf(外部创建，请保证足够大)
* @param    [inout]  dwCnt            获取个数
* @param    [in]   dwSSID           MT会话ID 
* @return   u32    0：获取成功  其他错误码
*
* @note 更新通知：Ev_MtApi_Vc_ApplyChair_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfGetApplyChairmanList( IN CONST u32 dwStartIdx, OUT TMtId_Api* ptOutBuf, INOUT u32& dwCnt, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
* KdvMt_ConfGetApplyChimeInList
* 
* @brief   获取申请插话列表(主席终端使用)
*
* @param    [in]  dwStartIdx       从第几个开始获取
* @param    [out]  ptOutBuf         存储获取数据的buf(外部创建，请保证足够大)
* @param    [inout]  dwCnt            获取个数
* @param    [in]   dwSSID           MT会话ID 
* @return   u32    0：获取成功  其他错误码
*
* @note 更新通知：Ev_MtApi_Vc_ApplyChimeIn_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfGetApplyChimeInList( IN CONST u32 dwStartIdx, OUT TMtId_Api* ptOutBuf, INOUT u32& dwCnt, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/** 视频预览与控制 */
/**
* KdvMt_VideoAssStreamCmd
* 
* @brief   video双流开始/停止命令
*
* @param    [in]   bStart       TRUE:开始 FALSE:停止
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 响应通知：Ev_MtApi_Vc_AssSndSream_Status_Ntf, Ev_MtApi_SysHint_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_VideoAssStreamCmd( IN CONST BOOL32 bStart, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_StartStreamBroadcastCmd
* 
* @brief   开始码流广播命令
*
* @param    [in]   emCodecType  编解码器类型 
* @param    [in]   emCodecIdx   某一路
* @param    [in]   tRtpAddr     RTP地址信息
* @param    [in]   tRtcpAddr    RTCP地址信息
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    请求命令发送结果
*
* @note
*/
KdvMtAPI u32 KdvMtCALL KdvMt_StartStreamBroadcastCmd( IN CONST EmCodecComponent_Api emCodecType, IN CONST EmCodecComponentIndex_Api emCodecIdx, IN CONST TNetAddr_Api& tRtpAddr, IN CONST TNetAddr_Api& tRtcpAddr, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_StopStreamBroadcastCmd
* 
* @brief   停止码流广播命令
*
* @param    [in]   emCodecType  编解码器类型 
* @param    [in]   emCodecIdx   某一路
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    请求命令发送结果
* @note
*/
KdvMtAPI u32 KdvMtCALL KdvMt_StopStreamBroadcastCmd( IN CONST EmCodecComponent_Api emCodecType, IN CONST EmCodecComponentIndex_Api emCodecIdx, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_StartStreamTransCmd
* 
* @brief   转发某一路码流命令
*
* @param    [in]   emCodecType  编解码器类型 
* @param    [in]   emCodecIdx   某一路
* @param    [in]   tRtpRtcpAddr RTP和RTCP地址信息
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    请求命令发送结果
* @note
*/
KdvMtAPI u32 KdvMtCALL KdvMt_StartStreamTransCmd( IN CONST EmCodecComponent_Api emCodecType, IN CONST EmCodecComponentIndex_Api emCodecIdx, IN CONST TRtpRtcpPair_Api& tRtpRtcpAddr, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_IFrameRequestCmd
* 
* @brief   请求终端发关键帧
*
* @param    [in]   emCodecType  编解码器类型 
* @param    [in]   emCodecIdx   某一路
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    请求命令发送结果
* @note
*/
KdvMtAPI u32 KdvMtCALL KdvMt_IFrameRequestCmd(IN CONST EmCodecComponent_Api emCodecType, IN CONST EmCodecComponentIndex_Api emCodecIdx, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
* KdvMt_StopStreamTransCmd
* 
* @brief   停止某一路码流命令
*
* @param    [in]   emCodecType  编解码器类型 
* @param    [in]   emCodecIdx   某一路
* @param    [in]   tRtpRtcpAddr RTP和RTCP地址信息
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    请求命令发送结果
* @note
*/
KdvMtAPI u32 KdvMtCALL KdvMt_StopStreamTransCmd( IN CONST EmCodecComponent_Api emCodecType, IN CONST EmCodecComponentIndex_Api emCodecIdx, IN CONST TRtpRtcpPair_Api& tRtpRtcpAddr, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_StartRecoderCmd
* 
* @brief   开始某一路录像命令( 仅硬终端 )	[这个接口暂时不用]
*
* @param    [in]   emCodecType  编解码器类型 
* @param    [in]   emCodecIdx   某一路
* @param    [in]   tRtpRtcpAddr RTP和RTCP地址信息
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    请求命令发送结果
* @note     
*/
KdvMtAPI u32 KdvMtCALL KdvMt_StartRecoderCmd( IN CONST EmCodecComponent_Api emCodecType, IN CONST EmCodecComponentIndex_Api emCodecIdx, IN CONST TRtpRtcpPair_Api& tRtpRtcpAddr, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*
* KdvMt_StopRecoderCmd
*
* @brief   停止某一路录像命令	[这个接口暂时不用]
*
* @param    [in]   emCodecType  编解码器类型 
* @param    [in]   emCodecIdx   某一路
* @param    [in]   tRtpRtcpAddr RTP和RTCP地址信息
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    请求命令发送结果
* @note
*/
KdvMtAPI u32 KdvMtCALL KdvMt_StopRecoderCmd( IN CONST EmCodecComponent_Api emCodecType, IN CONST EmCodecComponentIndex_Api emCodecIdx, IN CONST TRtpRtcpPair_Api& tRtpRtcpAddr, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_GetMonitorParamCmd
*
* @brief   获取监控参数命令
*
* @param    [in]   emCodecType  编解码器类型 
* @param    [in]   emCodecIdx   某一路
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 响应通知：Ev_MtApi_Vc_CodecMonitorParam_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_GetMonitorParamCmd(  IN CONST EmCodecComponent_Api emCodecType, IN CONST EmCodecComponentIndex_Api emCodecIdx, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_SendFastUpdateCmd
*
* @brief   请求某一路码流关键帧命令
*
* @param    [in]   emCodecType  编解码器类型 
* @param    [in]   emCodecIdx   某一路
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    请求命令发送结果
* @note
*/
KdvMtAPI u32 KdvMtCALL KdvMt_SendFastUpdateCmd( IN CONST EmCodecComponent_Api emCodecType, IN CONST EmCodecComponentIndex_Api emCodecIdx, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_ClearWindowCmd
*
清空采集播放窗口命令 (仅WIN32)
*
* @param    [in]   emCodecType  编解码器类型 
* @param    [in]   emCodecIdx   某一路
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    请求命令发送结果
* @note
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ClearWindowCmd( IN CONST EmCodecComponent_Api emCodecType, IN CONST EmCodecComponentIndex_Api emCodecIdx, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_SetPlayHwndCmd
*
* @brief   设置解码播放窗口命令 (仅WIN32)
*
* @param    [in]   emCodecType  编解码器类型 
* @param    [in]   emCodecIdx   某一路
* @param    [in]   hWnd         窗口句柄
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    请求命令发送结果
* @note
*/
KdvMtAPI u32 KdvMtCALL KdvMt_SetPlayHwndCmd( IN CONST EmCodecComponent_Api emCodecType, IN CONST EmCodecComponentIndex_Api emCodecIdx, IN CONST u32 hWnd, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_VidCapCtrlCmd
*
* @brief   视频采集控制命令 (仅WIN32)
*
* @param    [in]   emCodecType  编解码器类型 
* @param    [in]   emCodecIdx   某一路
* @param    [in]   bStartCap    TRUE开始采集，FALSE停止采集
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    请求命令发送结果
* @note
*/
KdvMtAPI u32 KdvMtCALL KdvMt_VidCapCtrlCmd( IN CONST EmCodecComponent_Api emCodecType, IN CONST EmCodecComponentIndex_Api emCodecIdx, IN CONST BOOL32 bStartCap, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_GrabPicCmd
*
* @brief   抓图命令 (仅WIN32)
*
* @param    [in]   emCodecType  编解码器类型 
* @param    [in]   emCodecIdx   某一路(TL没有多流，0表示主流，1表示辅流)
* @param    [in]   hWnd         窗口句柄
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    请求命令发送结果
* @note
*/
KdvMtAPI u32 KdvMtCALL KdvMt_GrabPicCmd( IN CONST EmCodecComponent_Api emCodecType, IN CONST EmCodecComponentIndex_Api emCodecIdx, IN CONST u32 hWnd, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_SavePicCmd
*
* @brief   保存抓图命令 (仅WIN32)
*
* @param    [in]   emCodecType     编解码器类型 
* @param    [in]   emCodecIdx      某一路(TL没有多流，0表示主流，1表示辅流)
* @param    [in]   emPicFormat     图片格式
* @param    [in]   pszPicPathName  图片保存路径
* @param    [in]   dwSSID          MT会话ID 
* @return   u32    请求命令发送结果
* @note
*/
KdvMtAPI u32 KdvMtCALL KdvMt_SavePicCmd( IN CONST EmCodecComponent_Api emCodecType, IN CONST EmCodecComponentIndex_Api emCodecIdx, IN CONST EmPicFormat_Api emPicFormat, IN CONST s8 *pszPicPathName, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_SetDecOnlyKeyFrameCmd
*
* @brief   设置只解关键帧命令 (仅WIN32)
*
* @param    [in]   emCodecType  编解码器类型 
* @param    [in]   emCodecIdx   某一路
* @param    [in]   bOn          TRUE:启用 FALSE:不启用
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    请求命令发送结果
* @note
*/
KdvMtAPI u32 KdvMtCALL KdvMt_SetDecOnlyKeyFrameCmd( IN CONST EmCodecComponent_Api emCodecType, IN CONST EmCodecComponentIndex_Api emCodecIdx, IN CONST BOOL32 bOn, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_GetVidCapDevListCmd
*
* @brief   获取视频输入设备列表命令 (仅WIN32)
*
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    请求命令发送结果
* @note 响应通知：Ev_MtApi_Vc_CodecVidCapDevList_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_GetVidCapDevListCmd( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
* KdvMt_GetVidGetCurVidCapDevCmd
*
* @brief   获取当前视频采集设备命令 (仅WIN32)
*
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    请求命令发送结果
* @note 响应通知：Ev_MtApi_Vc_CodecCurVidCapDev_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_GetVidGetCurVidCapDevCmd( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );




/**
* KdvMt_SetVidCapDevCmd
*
* @brief   设置视频输入设备命令 (仅WIN32)
*
* @param    [in]   tDevInfo     视频输出设备信息 
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 
*/
KdvMtAPI u32 KdvMtCALL KdvMt_SetVidCapDevCmd( IN CONST TDevInfo_Api& tDevInfo, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_MovePIPCmd
*
* @brief   移动画中画命令 (仅Embed)
*
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    请求命令发送结果
* @note
*/
KdvMtAPI u32 KdvMtCALL KdvMt_MovePIPCmd( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_SwitchPIPCmd
*
* @brief   切换画中画命令(仅Embed)
*
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    请求命令发送结果
* @note
*/
KdvMtAPI u32 KdvMtCALL KdvMt_SwitchPIPCmd( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
* KdvMt_SetPIPReq
*
* @brief   设置多画面风格请求
*
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    请求命令发送结果
* @note
*/
KdvMtAPI u32 KdvMtCALL KdvMt_SetPIPReq( CONST IN  u32 dwPiPMode,IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_GetLocalVideoViewReq
*
* @brief   本地视频源选看内容查询请求
*
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    请求命令发送结果
* @note
*/
KdvMtAPI u32 KdvMtCALL KdvMt_GetLocalVideoViewReq(IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
	* KdvMt_QueryPIPReq
	* @brief  查询多画面风格请求
	*
	* @param    [in]   SSID       MT会话ID 
	* @return   u32    请求命令发送结果
	* @note  Ev_MT_BLL_CodecQueryPIP_Rsp
	*
	*/
KdvMtAPI u32 KdvMtCALL KdvMt_QueryPIPReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

	
	/**
* KdvMt_SelectLocalVideoViewCmd
*
* @brief   本地视频源选看命令 
*
* @param    [in]   tCfg        该处实际为EmCameraView_Api
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 响应通知：Ev_MtApi_Vc_CodecRibbonTest_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_SelectLocalVideoViewCmd ( IN CONST EmCameraView_Api tCfg, IN CONST SessionID dwSSID  = KMTAPI_DEF_SSID ); 




/**
* KdvMt_StartRecCmd
*
* @brief   开始录像命令 (仅windows)
*
* @param    [in]   tRecParam    录像参数，详见结构体字段说明
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 
*/
KdvMtAPI u32 KdvMtCALL KdvMt_StartRecCmd( IN CONST TRecordParam_Api &tRecParam, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID ); 

/**
* KdvMt_StopRecCmd
*
* @brief   停止录像命令 (仅windows)
*
* @param    [in]   bLocal       TRUE停止录本地，FALSE停止录远端
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 
*/
KdvMtAPI u32 KdvMtCALL KdvMt_StopRecCmd( IN CONST BOOL32 bLocal, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID ); 

/**
* KdvMt_PauseRecCmd
*
* @brief   暂停录像命令 (仅windows)
*
* @param    [in]   bLocal       TRUE暂停录本地，FALSE暂停录远端
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 
*/
KdvMtAPI u32 KdvMtCALL KdvMt_PauseRecCmd( IN CONST BOOL32 bLocal, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID ); 

/**
* KdvMt_ResumeRecCmd
*
* @brief   继续录像命令 (仅windows)
*
* @param    [in]   bLocal       TRUE继续录本地，FALSE继续录远端
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ResumeRecCmd( IN CONST BOOL32 bLocal, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID ); 





/**
* KdvMt_SetRecDiskAlarmLevelCmd
*
* @brief   设置录像磁盘告警阈值命令 (仅windows)
*
* @param    [in]   tRecAlarmParam    录像磁盘告警参数，详见结构体字段说明
* @param    [in]   dwSSID            MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 磁盘告警通知：Ev_MtApi_Vc_CodecRecDiskAlarm_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_SetRecDiskAlarmLevelCmd( IN CONST TRecordDiskAlarmLevel_Api &tRecAlarmParam, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID ); 

/**
* KdvMt_GetCurAssSndVidStatus
*
* @brief   获取当前辅流发送状态信息
*
* @param    [out]  tAssSndVidStatus 辅流发送状态列表信息, 最多MT_MAX_CONF_ASSVID_CHANNEL_NUM个
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    0：获取成功  其他错误码
*
* @note 更新通知：Ev_MtApi_Vc_AssSndSream_Status_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_GetCurAssSndVidStatus( OUT TMtAssVidStatusList_Api& tAssSndVidStatus, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID ); 

/**
* KdvMt_GetCurAssRcvVidStatus
*
* @brief   获取当前辅流接收状态信息
*
* @param    [out]  tAssRcvVidStatus 辅流接收状态列表信息, 最多MT_MAX_CONF_ASSVID_CHANNEL_NUM个
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    0：获取成功  其他错误码
*
* @note 更新通知：Ev_MtApi_Vc_AssRcvSream_Status_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_GetCurAssRcvVidStatus( OUT TMtAssVidStatusList_Api& tAssRcvVidStatus, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID ); 


/**
* KdvMt_ConfGetAssSndVidStatusReq
*
* @brief   请求终端辅流发送状态
*
* @param    [in]   dwSSID      MT会话ID 
* @return   u32    0：获取成功  其他错误码
* @note 回复通知：Ev_MtApi_Vc_AssSndSream_Status_Ntf、Ev_MtApi_Vc_AssSndSream_Status_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfGetAssSndVidStatusReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_ConfGetAssRcvVidStatusReq
*
* @brief   请求终端辅流接收状态
*
* @param    [in]   dwSSID      MT会话ID 
* @return   u32    0：获取成功  其他错误码
* @note 回复通知：Ev_MtApi_Vc_AssSndSream_Status_Ntf、Ev_MtApi_Vc_AssSndSream_Status_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfGetAssRcvVidStatusReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_IsStreamLostPack
*
* @brief   5S内当前是否丢包
*
* @param    [out]  bLostPack    TRUE:丢包 FALSE:未丢包
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    0：获取成功  其他错误码
*
* @note 更新通知：Ev_MtApi_Vc_CodecLostPack_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_IsStreamLostPack( OUT BOOL32& bLostPack, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID ); 


/**
* KdvMt_GetVidCapDevList
*
* @brief   获取视频输入设备列表(仅WIN32)
*
* @param    [out]  tDevInfoList 视频输入设备列表信息 最多MT_MAX_DEVICE_LIST_NUM个
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    0：获取成功  其他错误码
*
* @note 更新通知：Ev_MtApi_Vc_CodecVidCapDevList_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_GetVidCapDevList( OUT TDevInfoList_Api& tDevInfoList, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID ); 


/** 终端音视频控制相关 */
/**
* KdvMt_AudQuiteLocalSpeakerCmd
*
* @brief  本地静音命令
*
* @param    [in]   bOn  TRUE:静音  FALSE:非静音
* @param    [in]   dwSSID  MT会话ID 
* @return    u32   请求命令发送结果
*
* @note 响应通知：Ev_MtApi_Vc_CodecQuiet_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_AudQuiteLocalSpeakerCmd( IN CONST BOOL32 bOn, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_AudMuteLocalMicCmd
*
* @brief  本地哑音命令
*
* @param    [in]   bOn  TRUE:哑音  FALSE:非哑音
* @param    [in]   dwSSID  MT会话ID 
* @return    u32   请求命令发送结果
*
* @note 响应通知：Ev_MtApi_Vc_CodecMute_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_AudMuteLocalMicCmd( IN CONST BOOL32 bOn, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_AudGetWaveInDevListCmd
*
* @brief  获取音频输入设备列表命令 (仅WIN32)
*
* @param    [in]   dwSSID  MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 响应通知：Ev_MtApi_Vc_CodecWaveInDevList_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_AudGetWaveInDevListCmd( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
* KdvMt_AudGetCurWaveInDevCmd
*
* @brief  获取当前的音频输入设备(仅WIN32)
*
* @param    [in]   dwSSID  MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 响应通知：Ev_MtApi_Vc_CodecCurWaveInDev_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_AudGetCurWaveInDevCmd( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
* KdvMt_AudGetWaveOutDevListCmd
*
* @brief  获取音频输出设备列表命令 (仅WIN32)
*
* @param    [in]   dwSSID  MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 响应通知：Ev_MtApi_Vc_CodecWaveOutDevList_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_AudGetWaveOutDevListCmd( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
* KdvMt_AudGetCurWaveOutDevCmd
*
* @brief  获取当前的音频输出设备(仅WIN32)
*
* @param    [in]   dwSSID  MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 响应通知：Ev_MtApi_Vc_CodecCurWaveOutDev_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_AudGetCurWaveOutDevCmd( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
* KdvMt_AudSetWaveInDevCmd
*
* @brief  设置音频输入设备命令 (仅WIN32)
*
* @param    [in]   tDevInfo 音频输入设备信息
* @param    [in]   dwSSID  MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 响应通知：Ev_MtApi_Vc_CodecWaveInDevList_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_AudSetWaveInDevCmd( IN CONST TDevInfo_Api& tDevInfo, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_AudSetWaveOutDevCmd
*
* @brief   设置音频输出设备命令 (仅WIN32)
*
* @param    [in]   tDevInfo 音频输出设备信息
* @param    [in]   dwSSID  MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 响应通知：Ev_MtApi_Vc_CodecWaveOutDevList_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_AudSetWaveOutDevCmd( IN CONST TDevInfo_Api& tDevInfo, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
* KdvMt_GetAudOutVolReq
*
* @brief   /获取音频输出音量请求 (仅WIN32)
*
* @param    [in]   emCodecType  解码器类型
* @param    [in]   emCodecId      解码器索引
* @param    [in]   dwSSID  MT会话ID 
* @return   u32    请求命令发送结果
* @note     Ev_MtApi_Vc_CodecGetAudOutVol_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_GetAudOutVolReq(IN CONST EmCodecComponent_Api emCodecType, IN CONST EmCodecComponentIndex_Api emCodecId, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_LocalSoundPlayCmd
*
* @brief   本地铃声、按键音、音效播放命令 (仅Embed)
*
* @param    [in]   emSoundType     声音种类铃声、按键音、音效
* @param    [in]   emSoundIdx        声音标识
* @param    [in]   bPlay                   TRUE-播放 FALSE-停止播放
* @param    [in]   dwSSID  MT会话ID 
* @return   u32    请求命令发送结果
* @note 更新通知 Ev_MtApi_Vc_CodecLocalSoundPlay_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_LocalSoundPlayCmd( IN CONST EmLocalSoundType_Api emSoundType, IN CONST EmLocalSoundIndex_Api emSoundIdx, IN CONST BOOL32 bPlay, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_LocalSoundPlayOnceCmd
*
* @brief   本地铃声、按键音、音效只播放一次命令 (仅Embed)
*
* @param    [in]   emSoundType     声音种类铃声、按键音、音效
* @param    [in]   emSoundIdx        声音标识
* @param    [in]   bPlay                   TRUE-播放 FALSE-停止播放
* @param    [in]   dwSSID  MT会话ID 
* @return   u32    请求命令发送结果
* @note 更新通知 Ev_MtApi_Vc_CodecLocalSoundPlay_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_LocalSoundPlayOnceCmd( IN CONST EmLocalSoundType_Api emSoundType, IN CONST EmLocalSoundIndex_Api emSoundIdx, IN CONST BOOL32 bPlay, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_GetLocalSoundPlayStateReq
*
* @brief   本地铃声、按键音、音效播放查询请求(按键音和音效由于是个短操作，暂时不提供查询) (仅Embed)
*
* @param    [in]   emSoundType     声音种类铃声、按键音、音效
* @param    [in]   emSoundIdx        声音标识
* @param    [in]   dwSSID  MT会话ID 
* @return   u32    请求命令发送结果
* @note 更新通知：Ev_MtApi_Vc_CodecGetLocalSoundPlayState_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_GetLocalSoundPlayStateReq(IN CONST EmLocalSoundType_Api emSoundType, IN CONST EmLocalSoundIndex_Api emSoundIdx, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID);

/**
* KdvMt_GetAudLocalMicMuteReq
*
* @brief   获取哑音信息同步sdk
*
* @param    [out]  bMicMute   TURE:哑音   FALSE:非哑音
* @param    [in]   dwSSID  MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MtApi_Vc_CodecGetMute_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_GetAudLocalMicMuteReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_AudIsLocalMicMute
*
* @brief   是否哑音
*
* @param    [out]  bMicMute   TURE:哑音   FALSE:非哑音
* @param    [in]   dwSSID  MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note
*/
KdvMtAPI u32 KdvMtCALL KdvMt_AudIsLocalMicMute( OUT BOOL32& bMicMute, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_GetAudLocalSpkQuiteReq
*
* @brief   获取静音状态
*
* @param    [out]  bSpkMute   TURE:静音   FALSE:非静音
* @param    [in]   dwSSID     MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MtApi_Vc_CodecGetQuiet_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_GetAudLocalSpkQuiteReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_AudIsLocalSpeakerQuite
*
* @brief   是否静音
*
* @param    [out]  bSpkMute   TURE:静音   FALSE:非静音
* @param    [in]   dwSSID     MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note
*/
KdvMtAPI u32 KdvMtCALL KdvMt_AudIsLocalSpeakerQuite( OUT BOOL32& bSpkQuite, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
* KdvMt_AudGetWaveInDevList
*
* @brief   获取音频输入设备列表(仅WIN32)
*
* @param    [out]  tDevInfoList  音频输入设备列表信息
* @param    [in]   dwSSID     MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MtApi_Vc_CodecWaveInDevList_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_AudGetWaveInDevList(OUT TDevInfoList_Api& tDevInfoList, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_AudGetWaveInDevList
*
* @brief   获取音频输出设备列表(仅WIN32)
*
* @param    [out]  tDevInfoList  音频输出设备列表信息
* @param    [in]   dwSSID     MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MtApi_Vc_CodecWaveOutDevList_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_AudGetWaveOutDevList( OUT TDevInfoList_Api& tDevInfoList, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );




/** VOD点播与控制 */
/**
* KdvMt_VodVrsLoginReq
*
* @brief   登录VRS平台请求
*
* @param    [in]   ptVrsLoginInfo       登录请求信息
* @param    [in]   dwSSID               MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 响应通知：Ev_MtApi_Vc_VodLogin_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_VodVrsLoginCmd( const TVodLoginInfo_Api *ptVrsLoginInfo, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID  );




/**
* KdvMt_VodVrsGetFolderInfoCmd
*
* @brief   请求文件夹列表
*
* @param    [in]   dwSSID               MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 响应通知：Ev_MtApi_Vc_VodGetFolderInfo_Ntf, Ev_MtApi_Vc_VodGetFolderInfo_Fin_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_VodVrsGetFolderInfoCmd( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );





/**
* KdvMt_VodVrsGetPrgsInfoCmd
*
* @brief   请求某一文件夹下的节目列表
*
* @param    [in]   ptVrsGetPrgsReq       请求信息
* @param    [in]   dwSSID                MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 响应通知：Ev_MtApi_Vc_VodGetPrgsInfo_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_VodVrsGetPrgsInfoCmd( const TVodGetPrgsReq_Api *ptVrsGetPrgsReq, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID  );



/**
* KdvMt_VodVrsSearchFilesInfoCmd   
*
* @brief   根据名称查询某一文件夹下的节目列表  该接口底层实现已经注释掉  和 KdvMt_VodVrsGetPrgsInfoCmd接口重复
*
* @param    [in]   ptVrsSearchFilesReq       请求信息
* @param    [in]   dwSSID					 MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 响应通知：Ev_MtApi_Vc_VodGetPrgsInfo_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_VodVrsSearchFilesInfoCmd( const TVodSearchFilesReq_Api ptVrsSearchFilesReq, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID  );



/**
* KdvMt_VodVrsGetRoomListInfoCmd
*
* @brief   请求直播室列表
*
* @param    [in]   dwSSID                MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 响应通知：Ev_MtApi_Vc_VodGetRoomListInfo_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_VodVrsGetRoomListInfoCmd( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );




/**sp4 新的api接口 获取预约直播室是有参数的 而老的没有参数 又不能直接修改 所以新加接口
* KdvMt_VodNewVrsGetresroomListInfoCmd
*
* @brief   请求预约直播室列表 new
*
* @param    [in]   TVodGetResRoomReq_Api
* @param    [in]   dwSSID                           MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 响应通知：Ev_MtApi_Vc_VodNewGetResRoomInfo_Ntf,Ev_MtApi_Vc_VodNewGetResRoomInfo_Fin_Ntf,
*/
KdvMtAPI u32 KdvMtCALL KdvMt_VodNewVrsGetResRoomListInfoCmd( const TVodGetResRoomReq_Api tVrsGetReserveRoomListReq, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID  );

/**新接入的终端不使用该接口 使用新接口
* KdvMt_VodVrsGetReserveRoomListInfoCmd
*
* @brief   请求预约直播室列表
*
* @param    [in]   无
* @param    [in]   dwSSID                           MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 响应通知：Ev_MtApi_Vc_VodGetReserveRoomListInfo_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_VodVrsGetReserveRoomListInfoCmd( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID  );

/**
* KdvMt_VodStartPlayVodCmd
*
* @brief   开始点播命令
*
* @param    [in]   pszUrl       点播的VOD URL信息
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 响应通知：Ev_MtApi_Vc_VODPlay_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_VodStartPlayVodCmd( IN CONST s8* pszUrl, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID ); 


/**
* KdvMt_VodGetRunVodInfoReq
*
* @brief   获取当前已点播的点播信息
*
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    请求发送结果
*
* @note 更新通知：Ev_MtApi_Vc_GetRunVODInfo_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_VodGetRunVodInfoReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID ); 


/**
* KdvMt_VodGetVodInfoReq
*
* @brief   获取点播源的信息请求
*
* @param    [in]   dwVodId      要获取的VOD点播源ID
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    请求发送结果
*
* @note 响应通知：Ev_MtApi_Vc_GetVODInfo_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_VodGetVodInfoReq( IN CONST u32 dwVodId, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID ); 


/**
* KdvMt_VodStopPlayVodCmd
*
* @brief   停止点播命令
*
* @param    [in]   dwVodId      要停止的VOD点播源ID
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 响应通知：Ev_MtApi_Vc_VODOver_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_VodStopPlayVodCmd( IN CONST u32 dwVodId, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID ); 


/**
* KdvMt_VodPausePlayVodCmd
*
* @brief   暂停点播命令
*
* @param    [in]   dwVodId      要暂停的VOD点播源ID
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 响应通知：Ev_MtApi_Vc_VODPause_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_VodPausePlayVodCmd( IN CONST u32 dwVodId, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID ); 


/**
* KdvMt_VodResumePlayVodCmd
*
* @brief   恢复点播命令
*
* @param    [in]   dwVodId      要恢复的VOD点播源ID
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 响应通知：Ev_MtApi_Vc_VODResume_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_VodResumePlayVodCmd( IN CONST u32 dwVodId, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID ); 

/**
* KdvMt_VodChangeVodSpeedCmd
*
* @brief   改变点播速率
*
* @param    [in]   dwVodId      要改变的VOD点播源ID
* @param    [in]   chSpeedScale 调整速度的倍数，暂时只支持加快速度即使用正整数；
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 更新通知：Ev_MtApi_Vc_VODChangeSpeed_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_VodChangeVodSpeedCmd( IN CONST u32 dwVodId, IN CONST s8 chSpeedScale, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID ); 


/**
* KdvMt_VodChangeVodProcessCmd
*
* @brief   改变点播进度
*
* @param    [in]   dwVodId      要改变的VOD点播源ID
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 响应通知：Ev_MtApi_Vc_VODChangeProcess_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_VodChangeVodProcessCmd( IN CONST u32 dwVodId, IN CONST u32 dwTime, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID ); 


/**
* KdvMt_VodStartPlayVodStreamCmd
*
* @brief   点播源指定流播放(单个停止的后，再播放调用)(暂时不支持)
*
* @param    [in]   dwVodId      要点播的VOD点播源ID
* @param    [in]   byStremId    流ID (一个点播源可能有多个流信息)
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 响应通知：Ev_MtApi_Vc_VODStreamPlay_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_VodStartPlayVodStreamCmd( IN CONST u32 dwVodId, IN CONST u8 byStremId, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID ); 


/**
* KdvMt_VodGetVodStreamInfoReq
*
* @brief   获取点播源信息
*
* @param    [in]   dwVodId      要获取的VOD点播源ID
* @param    [in]   byStremId    流ID (一个点播源可能有多个流信息)
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 响应通知：Ev_MtApi_Vc_GetVODStreamInfo_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_VodGetVodStreamInfoReq( IN CONST u32 dwVodId, IN CONST u8 byStremId, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID ); 


/**
* KdvMt_VodStopPlayVodStreamCmd
*
* @brief   止点播源指定流播放(暂时不支持)
*
* @param    [in]   dwVodId      要停止的VOD点播源ID
* @param    [in]   byStremId    流ID (一个点播源可能有多个流信息)
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 响应通知：Ev_MtApi_Vc_VODStreamOver_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_VodStopPlayVodStreamCmd( IN CONST u32 dwVodId, IN CONST u8 byStremId, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID ); 


/**
* KdvMt_VodGetVodPlayInfo
*
* @brief   最后一次获取的点播信息
*
* @param    [out]  tVodPlayInfo 获取的点播信息
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    0：获取成功  其他错误码
*
* @note 更新通知：Ev_MtApi_Vc_VODStatus_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_VodGetVodPlayInfo( OUT TVodPlayInfo_Api& tVodPlayInfo, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID ); 


/**
* KdvMt_VodGetRuningMultVodPlayInfo
*
* @brief   获取运行中的点播信息
*
* @param    [out]  tMultVodPlayInfo 点播中的点播列表,最多MT_MAX_VOD_STREAM_NUM个
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    0：获取成功  其他错误码
*
* @note 更新通知：Ev_MtApi_Vc_GetRunVODInfo_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_VodGetRuningMultVodPlayInfo( OUT TMultiVodPlayInfo_Api& tMultVodPlayInfo, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID ); 



/**
* KdvMt_CameraSelectCmd
*
* @brief   摄像头选择（仅Embed）
*
* @param    [in]   byIndex      选择摄像头索引
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    0：获取成功  其他错误码
*
* @note 更新通知：
*/
//该接口不用暴露给UI层
//KdvMtAPI u32 KdvMtCALL KdvMt_CameraSelectCmd( IN CONST u8 byIndex, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );





/**
* KdvMt_CameraPresetCmd
*
* @brief   摄像头预置位操作（仅Embed）
*
*@param     [in]   emVideoIndex 主流视频源索引，em1st表示第一路  em2nd表示第二路
* @param    [in]   bSava        预置位操作方式，TRUE表示保存，FALSE表示调用
* @param    [in]   byIndex      预置位操作的索引号
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    0：获取成功  其他错误码
*
* @note 更新通知：
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CameraPresetReq( IN CONST EmCodecComponentIndex_Api emVideoIndex, IN CONST BOOL32 bSava, IN CONST u8 byIndex, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_GetCurCodecPresetIndexReq
*
* @brief   获取当前码流对应预置位请求（仅Embed）
*
*@param     [in]   emVideoIndex 主流视频源索引，em1st表示第一路  em2nd表示第二路
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    0：获取成功  其他错误码
*
* @note 更新通知：
*/
KdvMtAPI u32 KdvMtCALL KdvMt_GetCurCodecPresetIndexReq( IN CONST EmCodecComponentIndex_Api emVideoIndex, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );





/**
* KdvMt_CameraPantiltCmd
*
* @brief   摄像头方位调节（仅Embed）
*
*@param     [in]   emVideoIndex 主流视频源索引，em1st表示第一路  em2nd表示第二路
* @param    [in]   emDir       摄像头调节的方位
* @param    [in]   emAction    摄像头调节的操作
* @param    [in]   dwSSID      MT会话ID 
* @return   u32    0：获取成功  其他错误码
*
* @note 更新通知：
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CameraPantiltCmd( IN CONST EmCodecComponentIndex_Api emVideoIndex, IN CONST EmDirection_Api emDir, IN CONST EmAction_Api emAction, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );





/**
* KdvMt_CameraFocusCmd
*
* @brief   摄像头焦距调节（仅Embed）
*
*@param     [in]   emVideoIndex 主流视频源索引，em1st表示第一路  em2nd表示第二路
* @param    [in]   bFar        摄像头焦距调节的远近，TRUE为远，FALSE为近
* @param    [in]   emAction    摄像头焦距调节的操作
* @param    [in]   dwSSID      MT会话ID 
* @return   u32    0：获取成功  其他错误码
*
* @note 更新通知：
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CameraFocusCmd( IN CONST EmCodecComponentIndex_Api emVideoIndex, IN CONST BOOL32 bFar, IN CONST EmAction_Api emAction, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );





/**
* KdvMt_CameraAutoFocusCmd
*
* @brief   摄像头自动聚焦（仅Embed）
*
*@param     [in]   emVideoIndex 主流视频源索引，em1st表示第一路  em2nd表示第二路
* @param    [in]   dwSSID      MT会话ID 
* @return   u32    0：获取成功  其他错误码
*
* @note 更新通知：
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CameraAutoFocusCmd( IN CONST EmCodecComponentIndex_Api emVideoIndex, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );






/**
* KdvMt_CameraZoomCmd
*
* @brief   摄像头视野调节（仅Embed）
*
*@param     [in]   emVideoIndex 主流视频源索引，em1st表示第一路  em2nd表示第二路
* @param    [in]   bZoomOut    摄像头放大缩小调节，TRUE为缩小，FALSE为放大
* @param    [in]   emAction    摄像头放大缩小调节的操作
* @param    [in]   dwSSID      MT会话ID 
* @return   u32    0：获取成功  其他错误码
*
* @note 更新通知：
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CameraZoomCmd( IN CONST EmCodecComponentIndex_Api emVideoIndex, IN CONST BOOL32 bZoomOut, IN CONST EmAction_Api emAction, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );





/**
* KdvMt_CameraBrightCmd
*
* @brief   摄像头亮度调节（仅Embed）
*
*@param     [in]   emVideoIndex 主流视频源索引，em1st表示第一路  em2nd表示第二路
* @param    [in]   bBrightenUp    摄像头亮度调节，TRUE为调亮，FALSE为调暗
* @param    [in]   emAction       摄像头亮度调节的操作
* @param    [in]   dwSSID         MT会话ID 
* @return   u32    0：获取成功  其他错误码
*
* @note 更新通知：
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CameraBrightCmd( IN CONST EmCodecComponentIndex_Api emVideoIndex, IN CONST BOOL32 bBrightenUp, IN CONST EmAction_Api emAction, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );





/**
* KdvMt_CameraBackLightCmd
*
* @brief   摄像头背光补偿（仅Embed）
*
*@param     [in]   emVideoIndex 主流视频源索引，em1st表示第一路  em2nd表示第二路
* @param    [in]   bOn            摄像头背光补偿，TRUE为打开，FALSE为关闭
* @param    [in]   dwSSID         MT会话ID 
* @return   u32    0：获取成功  其他错误码
*
* @note 更新通知：
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CameraBackLightCmd( IN CONST EmCodecComponentIndex_Api emVideoIndex, IN CONST BOOL32 bOn, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_CameraUpgradeCmd
*
* @brief   摄像头升级（仅Embed）
*
*@param     [in]   emVideoIndex 视频源接口
* @param    [in]   tCameraUpgrade    摄像机升级信息
* @param    [in]   dwSSID            MT会话ID 
* @return   u32    0：获取成功  其他错误码
*
* @note 结果通知：Ev_MtApi_Vc_DeviceCameraUpgrade_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CameraUpgradeCmd( IN CONST EmMtVideoPort_Api emVideoIndex, IN CONST TMTCameraUpgrade_Api &tCameraUpgrade, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_GetIsCameraUpgradingReq
*
* @brief   获取摄像头是否正在升级
*
* @param    
*
* @note 结果通知: Ev_MtApi_CodecGetIsCameraUpgrading_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_GetIsCameraUpgradingReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID);



/**
* KdvMt_CameraVersionReq
*
* @brief   摄像头版本查询（仅Embed）
*
*@param     [in]   emVideoIndex 主流视频源索引，em1st表示第一路  em2nd表示第二路
* @param    [in]   dwSSID         MT会话ID 
* @return   u32    0：获取成功  其他错误码
*
* @note 结果通知：Ev_MtApi_Vc_DeviceCameraVersion_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CameraVersionReq( IN CONST EmCodecComponentIndex_Api emVideoIndex, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_FeccCameraSelectCmd
*
* @brief   选择控制摄像头
*
* @param    [in]   byCameraIndex  摄像头索引号
* @param    [in]   ptId           被遥控的终端ID
* @param    [in]   dwSSID         MT会话ID 
* @return   u32    0：成功        其他错误码
*
* @note 更新通知：
*/
//该接口不用暴露给UI层
//KdvMtAPI u32 KdvMtCALL KdvMt_FeccCameraSelectCmd( u8 byCameraIndex, const TMtId_Api * ptId = NULL, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
* KdvMt_FeccCameraFocusCmd
*
* @brief   摄像头聚焦命令
*
* @param    [in]   emVideoIndex 摄像头索引           
* @param    [in]   bNearFocus           
* @param    [in]   emAction  轮询操作
* @param    [in]   ptId  被遥控的终端ID
* @param    [in]   dwSSID         MT会话ID 
* @return   u32    0：成功        其他错误码
*
* @note 更新通知：
*/
KdvMtAPI u32 KdvMtCALL KdvMt_FeccCameraFocusCmd(  IN CONST EmCodecComponentIndex_Api emVideoIndex, IN CONST BOOL32 bNearFocus, IN CONST EmAction_Api emAction, IN CONST TMtId_Api * ptId = NULL, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
* KdvMt_FeccCameraAutoFocusCmd
*
* @brief   摄像头自动聚焦命令
*
* @param    [in]   emVideoIndex  摄像头索引
* @param    [in]   ptId           被遥控的终端ID
* @param    [in]   dwSSID         MT会话ID 
* @return   u32    0：成功        其他错误码
*
* @note 更新通知：
*/
KdvMtAPI u32 KdvMtCALL KdvMt_FeccCameraAutoFocusCmd( IN CONST EmCodecComponentIndex_Api emVideoIndex, IN CONST TMtId_Api * ptId = NULL, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_FeccCameraZoomCmd
*
* @brief   摄像视野命令
*
* @param    [in]   emVideoIndex       摄像头索引
* @param    [in]   bZoonmIn       TRUE= 放大 /FALSE=缩小
* @param    [in]   emAction       操作， emStart/emStop
* @param    [in]   ptId           被遥控的终端ID
* @param    [in]   dwSSID         MT会话ID 
* @return   u32    0：成功        其他错误码
*
* @note 更新通知：
*/
KdvMtAPI u32 KdvMtCALL KdvMt_FeccCameraZoomCmd(  IN CONST EmCodecComponentIndex_Api emVideoIndex, IN CONST BOOL32 bZoonmIn, IN CONST EmAction_Api emAction, IN CONST TMtId_Api * ptId = NULL, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_FeccCameraBrightCmd
*
* @brief   摄像亮度调节命令
*
* @param    [in]   emVideoIndex 摄像头索引
* @param    [in]   bLight         TRUE:增亮, FALSE:减暗
* @param    [in]   emAction       操作， emStart/emStop
* @param    [in]   ptId           被遥控的终端ID
* @param    [in]   dwSSID         MT会话ID 
* @return   u32    0：成功        其他错误码
*
* @note 更新通知：
*/
KdvMtAPI u32 KdvMtCALL KdvMt_FeccCameraBrightCmd(  IN CONST EmCodecComponentIndex_Api emVideoIndex, IN CONST BOOL32 bLight, IN CONST EmAction_Api emAction, IN CONST TMtId_Api * ptId = NULL, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
* KdvMt_FeccCameraPresetCmd
*
* @brief   预置位命令
*
* @param    [in]   emVideoIndex   摄像头索引
* @param    [in]   bSave          TRUE= 存储 FALSE=调用预置位
* @param    [in]   byIndex        摄像头索引
* @param    [in]   ptId           被遥控的终端ID
* @param    [in]   dwSSID         MT会话ID 
* @return   u32    0：成功        其他错误码
*
* @note 更新通知：
*/
KdvMtAPI u32 KdvMtCALL KdvMt_FeccCameraPresetByIdxCmd(  IN CONST EmCodecComponentIndex_Api emVideoIndex, IN CONST BOOL32 bSave, IN CONST u8 byIndex, IN CONST TMtId_Api * ptId = NULL, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_FeccCameraPresetCmd
*
* @brief   预置位命令
*
* @param    [in]   bSave          TRUE= 存储 FALSE=调用预置位
* @param    [in]   byIndex        摄像头索引
* @param    [in]   ptId           被遥控的终端ID
* @param    [in]   dwSSID         MT会话ID 
* @return   u32    0：成功        其他错误码
*
* @note 更新通知：
*/
KdvMtAPI u32 KdvMtCALL KdvMt_FeccCameraPresetCmd( IN CONST BOOL32 bSave, IN CONST u8 byIndex, IN CONST TMtId_Api * ptId = NULL, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_FeccCameraPantiltCmd
*
* @brief   摄像头移动命令
*
* @param    [in]   emVideoIndex 摄系统索引
* @param    [in]   emDirection    方向
* @param    [in]   emAction       操作
* @param    [in]   ptId           被遥控的终端ID
* @param    [in]   dwSSID         MT会话ID 
* @return   u32    0：成功        其他错误码
*
* @note 更新通知：Ev_MtApi_Vc_DeviceCameraPantiltErr_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_FeccCameraPantiltCmd(  IN CONST EmCodecComponentIndex_Api emVideoIndex, IN CONST EmDirection_Api emDirection, IN CONST EmAction_Api emAction, IN CONST TMtId_Api * ptId = NULL, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
* KdvMt_FeccVideoSourceSelCmd
*
* @brief   选择视频源

** @param    [in]  emComIndex     摄系统索引
* @param    [in]   byVideoIndex   视频源索引号
* @param    [in]   ptId           被遥控的终端ID
* @param    [in]   dwSSID         MT会话ID 
* @return   u32    0：成功        其他错误码
*
* @note 更新通l知：
*/
KdvMtAPI u32 KdvMtCALL KdvMt_FeccVideoSourceSelCmd( IN CONST EmCodecComponentIndex_Api emComIndex, u8 byVideoIndex, const TMtId_Api * ptId = NULL, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_CameraSetParamCmd
*
* @brief   设置摄像头图像参数命令，仅windows
*
* @param    [in]   tImgParam      图像参数
* @param    [in]   dwSSID         MT会话ID 
* @return   u32    0：成功        其他错误码
*
* @note 
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CameraSetParamCmd( IN CONST TImageParam_Api &tImgParam, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_CameraGetParamReq
*
* @brief   获取摄像头图像参数命令，仅windows
*
* @param    [in]   emImgParamType 图像参数类型
* @param    [in]   dwSSID         MT会话ID 
* @return   u32    0：成功        其他错误码
*
* @note Ev_MtApi_CodecGetCameraParam_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CameraGetParamReq( IN CONST EmImgParam_Api emImgParamType, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_CameraGetDefaultParamReq
*
* @brief   获取摄像头默认图像参数命令，仅windows
*
* @param    [in]   emImgParamType 图像参数类型
* @param    [in]   dwSSID         MT会话ID 
* @return   u32    0：成功        其他错误码
*
* @note Ev_MtApi_CodecGetDefaultCameraParam_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CameraGetDefaultParamReq( IN CONST EmImgParam_Api emImgParamType, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_CameraSetCtrlSite
*
* @brief   设置摄像头控制是远端，还是本地，存在ds中的 Rtkey
*
* @param    [in]   emSite         本地还是远端
* @param    [in]   dwSSID         MT会话ID 
* @return   u32    0：成功        其他错误码
*
* @note Ev_MtApi_Vc_SetCamCtrlSite_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CameraSetCtrlSite( IN CONST EmSite_Api emSite, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_CameraGetCtrlSite
*
* @brief   获取摄像头控制是远端，还是本地，底层存在ds中的运行时的 key
*
* @param    [out]  emSite         本地还是远端
* @param    [in]   dwSSID         MT会话ID 
* @return   u32    0：成功        其他错误码
*
* @note 
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CameraGetCtrlSite(  OUT EmSite_Api &emSite, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_CameraGetCtrlSiteReq
*
* @brief   获取摄像头控制是远端，还是本地的请求
*
* @param    [in]   dwSSID         MT会话ID 
* @return   u32    0：成功        其他错误码
*
* @note Ev_MtApi_Vc_GetCameraCtrlSiteRt_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CameraGetCtrlSiteReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_DeviceDMicUpgradeCmd
*
* @brief   数字mic升级
*
* @param    [in]   emUartNum      串口设备号
* @param    [in]   pchPath        路径
* @param    [in]   dwSSID         MT会话ID 
* @return   u32    0：成功        其他错误码
*
* @note 更新通知：Ev_MtApi_Vc_DeviceDMicUpgrade_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DeviceDMicUpgradeCmd( IN EmUartNum_Api emUartNum, IN s8 * pchPath, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_DeviceDMicVersionReq
*
* @brief   数字mic版本查询（仅embed）
*
* @param    [in]   emUartNum      串口设备号
* @param    [in]   dwSSID         MT会话ID 
* @return   u32    0：成功        其他错误码
*
* @note 更新通知：Ev_MtApi_Vc_DeviceDMicVersion_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DeviceDMicVersionReq( IN EmUartNum_Api emUartNum, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_DeviceWMicUpgradeCmd
*
* @brief   无线mic升级（仅embed）
*
* @param    [in]   emUartNum      串口设备号
* @param    [in]   pchPath        路径
* @param    [in]   dwSSID         MT会话ID 
* @return   u32    0：成功        其他错误码
*
* @note 更新通知：Ev_MtApi_Vc_DeviceWMicUpgrade_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DeviceWMicUpgradeCmd( IN EmUartNum_Api emUartNum, IN s8 * pchPath, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_DeviceWMicVersionReq
*
* @brief   无线mic版本查询（仅embed）
*
* @param    [in]   emUartNum      串口设备号
* @param    [in]   dwSSID         MT会话ID 
* @return   u32    0：成功        其他错误码
*
* @note 更新通知：Ev_MtApi_Vc_DeviceWMicVersion_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DeviceWMicVersionReq( IN EmUartNum_Api emUartNum, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_GetCameraTypeCapsetReq
*
* @brief  摄像头能力类型查询
*
* @param    [in]   dwSSID         MT会话ID 
* @return   u32    0：成功        其他错误码
* @note 更新通知：Ev_MtApi_Vc_DeviceCameraTypeCapset_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_GetCameraTypeCapsetReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_GetCameraTypeList
*
* @brief  获取硬终端支持的摄像头类型
*
* @param    [out]  tCameraList    摄像头列表
* @param    [in]   dwSSID         MT会话ID 
* @return   u32    0：成功        其他错误码
*/
KdvMtAPI u32 KdvMtCALL KdvMt_GetCameraTypeList( OUT TMTCameraTypeList_Api &tCameraList, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_ConfFxoMakeCallCmd
*
* @brief    Fxo呼叫
*
* @param    [s8*]  pchPeerNumber  对端号码
* @param    [in]   dwSSID         MT会话ID 
* @return   u32    0：成功        其他错误码
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfFxoMakeCallCmd( IN CONST s8 * pchPeerNumber, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
* KdvMt_ConfFxoAcceptCmd
*
* @brief    Fxo接受呼叫
*
* @param    [in]   dwSSID         MT会话ID 
* @return   u32    0：成功        其他错误码
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfFxoAcceptCmd( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
* KdvMt_ConfFxoRejectCmd
*
* @brief    Fxo拒绝接听
*
* @param    [in]   dwSSID         MT会话ID 
* @return   u32    0：成功        其他错误码
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfFxoRejectCmd( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
* KdvMt_ConfFxoHangupCmd
*
* @brief    Fxo挂断电话
*
* @param    [in]   dwSSID         MT会话ID 
* @return   u32    0：成功        其他错误码
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfFxoHangupCmd( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**以下是内置mc的功能，只有部分硬终端有此功能*/
/**
* KdvMt_McAdHocCmd
*
* @brief    点对点扩展多点会议请求
*
* @param    [in]   pszCalledInfo  扩展多点会议，被邀请的第三方终端
* @param    [in]   dwSSID         MT会话ID 
* @return   u32    0：成功        其他错误码
*/
KdvMtAPI u32 KdvMtCALL KdvMt_McAdHocCmd( IN CONST s8* pszCalledInfo, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_McInviteTerCmd
*
* @brief    Mcc邀请终端
*
* @param    [in]   pszCalledInfo  邀请终端
* @param    [in]   dwSSID         MT会话ID 
* @return   u32    0：成功        其他错误码
*/
KdvMtAPI u32 KdvMtCALL KdvMt_McInviteTerCmd( IN CONST s8* pszCalledInfo, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_McDropConfTerCmd
*
* @brief    Mcc挂断会议终端
*
* @param    [in]   tMtId          终端信息
* @param    [in]   dwSSID         MT会话ID 
* @return   u32    0：成功        其他错误码
*/
KdvMtAPI u32 KdvMtCALL KdvMt_McDropConfTerCmd( IN CONST TMtId_Api& tMtId , IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_McEndConfCmd
*
* @brief    mcc结束会议
*
* @param    [in]   dwSSID         MT会话ID 
* @return   u32    0：成功        其他错误码
*/
KdvMtAPI u32 KdvMtCALL KdvMt_McEndConfCmd( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_McCreateConfCmd
*
* @brief    mcc创建会议
*
* @param    [in]   aaszCalledInfo 与会终端
* @param    [in]   byCnt          与会终端个数 
* @param    [in]   dwSSID         MT会话ID 
* @return   u32    0：成功        其他错误码
*/
KdvMtAPI u32 KdvMtCALL KdvMt_McCreateConfCmd( IN CONST s8 aaszCalledInfo[][KMTAPI_MAX_MT_ALIAS_LEN+1], u8 byCnt, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
* KdvMt_McPollBroadCastCmd
*
* @brief    mcc会议轮询
*
* @param    [in]   bPoll          是否轮询
* @param    [in]   dwMsTime       轮询间隔时间(单位：ms)
* @param    [in]   dwSSID         MT会话ID 
* @return   u32    0：成功        其他错误码
*/
KdvMtAPI u32 KdvMtCALL KdvMt_McPollBroadCastCmd( IN CONST BOOL32 bPoll, IN CONST u32 dwMsTime = 0, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/////////白板会议命令
/**
* KdvMt_DataConfCreatedCmd
*
* @brief    白板会议创建后通知mcu mt->mcu   非标
*
* @param    [in]   pszConf_name   白板会议名称
* @param    [in]   pszConf_e164   会议e164
* @param    [in]   dwSSID         MT会话ID 
* @return   u32    0：成功        其他错误码
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DataConfCreatedNtfPeerCmd( IN CONST s8* pszConf_name, IN CONST s8* pszConf_e164, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_P2PJoinDataConfCmd
*
* @brief    白板会议创建后通知对端加入白板会议 mt->mt, 只用在点对点   非标
*
* @param    [in]   pszConf_name   白板会议名称
* @param    [in]   pszStr         字符串
* @param    [in]   dwSSID         MT会话ID 
* @return   u32    0：成功        其他错误码
*/
KdvMtAPI u32 KdvMtCALL KdvMt_P2PJoinDataConfCmd( IN CONST s8* pszConf_name, IN CONST s8* pszStr,  IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );




/**
* KdvMt_SnapshotReq
*
* @brief    拍摄快照请求 传输方向：mtsdk->mtservice
*
* @param    [in]   emCodecType   编解码类型
* @param    [in]   emCodecIdx   拍哪一路的快照
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    0：成功      其他错误码
* @note 更新通知：Ev_MtApi_Vc_CodecSnapshot_Rsp ,Ev_MtApi_Vc_CodecSnapshot_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_SnapshotReq( IN CONST EmCodecComponent_Api emCodecType, IN CONST EmCodecComponentIndex_Api emCodecIdx, 
	IN CONST SessionID dwSSID  = KMTAPI_DEF_SSID );

/**
* KdvMt_SnapshotQueryLatestFileReqq
*
* @brief  查询最近拍摄文件请求   传输方向：mtsdk->mtservice
*
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    0：成功      其他错误码
* @note 更新通知： Ev_MtApi_Vc_CodecSnapshotQueryLatestFile_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_SnapshotQueryLatestFileReq( IN CONST SessionID dwSSID  = KMTAPI_DEF_SSID );

/**
* KdvMt_FtpSnapshotCmd
*
* @brief    拍摄ftp快照请求 传输方向：mtervice->mtmp
*
* @param    [in]   emCodecType   编解码类型
* @param    [in]   emCodecIdx   拍哪一路的快照
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    0：成功      其他错误码
* @note 更新通知：Ev_MtApi_Vc_CodecFtpSnapshot_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_FtpSnapshotCmd( IN CONST EmCodecComponent_Api emCodecType, IN CONST EmCodecComponentIndex_Api emCodecIdx, 
	IN CONST SessionID dwSSID  = KMTAPI_DEF_SSID );


/**
* KdvMt_SnapshotQueryFileListReq
*
* @brief    查询快照文件列表信息请求 传输方向：mtervice->mtmp
*
* @param    [in]   dwSSID         MT会话ID 
* @return   u32    0：成功        其他错误码
* @note 响应消息：Ev_MtApi_Vc_CodecSnapshotQueryFileList_Rsp 
*/
KdvMtAPI u32 KdvMtCALL KdvMt_SnapshotQueryFileListReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID  );


/**
* KdvMt_SnapshotDelOneFileReq 
*
* @brief   删除一张快照请求 传输方向：mtervice->mtmp
*
* @param    [in]   tSnapshotFileInfo   文件信息
* @param    [in]   dwSSID         MT会话ID 
* @return   u32    0：成功        其他错误码
* @note 响应消息：Ev_MtApi_Vc_CodecSnapshotDelOneFile_Rsp ,Ev_MtApi_Vc_CodecSnapshotDelOneFile_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_SnapshotDelOneFileReq( IN CONST TSnapshotFileInfo_Api& tSnapshotFileInfo, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID);


/**
* KdvMt_SnapshotDelAllFileReq
*
* @brief    删除所有快照文件请求 传输方向：mtervice->mtmp
*
* @param    [in]   dwSSID         MT会话ID 
* @return   u32    0：成功        其他错误码
* @note 响应消息：Ev_MtApi_Vc_CodecSnapshotDelAllFile_Rsp ,Ev_MtApi_Vc_CodecSnapshotDelAllFile_Ntf 
*/
KdvMtAPI u32 KdvMtCALL KdvMt_SnapshotDelAllFileReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_SnapshotExportOneFileReq
*
* @brief    导出一张快照文件请求  传输方向：mtervice->mtmp
*
* @param    [in]   tSnapshotFileInfo   需要导出的文件信息
* @param    [in]   pchDstPath   存放导出文件的目标路径
* @param    [in]   dwSSID         MT会话ID 
* @return   u32    0：成功        其他错误码
* @note 响应消息：Ev_MtApi_Vc_CodecSnapshotExportOneFile_Rsp 
*/
KdvMtAPI u32 KdvMtCALL KdvMt_SnapshotExportOneFileReq( IN CONST TSnapshotFileInfo_Api& tSnapshotFileInfo, IN CONST s8 *pchDstPath, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_SnapshotExportAllFileReq
*
* @brief   导出所有快照文件请求 , 传输方向：mtervice->mtmp
*
* @param    [in]   pchDstPath   存放导出文件的目标路径
* @param    [in]   dwSSID         MT会话ID  
* @return   u32    0：成功        其他错误码
* @note 响应消息：Ev_MtApi_Vc_CodecSnapshotExportAllFile_Rsp 
*/
KdvMtAPI u32 KdvMtCALL KdvMt_SnapshotExportAllFileReq( IN CONST s8 *pchDstPath, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/*
* KdvMt_SetAddLogoIntoEncStreamCmd (仅win32)
* @brief    设置台标加入码流
*
* @param    [in]   bAddIntoStream    是否加入
* @param    [in]   tLogoParam          台标参数
* @param    [in]   dwSSID         MT会话ID 
* @return   u32    0：成功        其他错误码
*/
KdvMtAPI u32 KdvMtCALL KdvMt_SetAddLogoIntoEncStreamCmd( IN CONST BOOL32 bAddIntoStream, IN CONST TMtFullLogoParam_Api &tLogoParam, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/*
* KdvMt_SetMobilAddLogoIntoEncStreamCmd (mobil)
* @brief    设置台标加入码流
*
* @param    [in]   bAddIntoStream           是否加入
* @param    [in]   ptArrFullLogoParam       台标参数 数组[]
* @param    [in]   dwSSID         MT会话ID 
* @return   u32    0：成功        其他错误码
*/
KdvMtAPI u32 KdvMtCALL KdvMt_SetMobilAddLogoIntoEncStreamCmd( IN CONST BOOL32 bAddIntoStream, IN CONST TMtFullLogoParam_Api* ptArrFullLogoParam, u8 byCnt, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
 * KdvMt_StartSpareCloudRecordCmd
 * @brief       开始空闲云端录像， 空闲去呼叫平台的vrs
 *
 * @param    [in]   pszRecordInfo  ip/alias/e164  ip默认端口1720
 * @param    [in]   emPro  ip/alias/e164  ip默认端口1720
 * @param    [in]   wRate          呼叫码率
 * @param    [in]   dwSSID         MT会话ID 
 * @return    u32     0:成功      其他错误码
 */
KdvMtAPI u32 KdvMtCALL KdvMt_StartSpareCloudRecordCmd( IN CONST s8* pszRecordInfo, IN CONST u16 wRate, 
                                                      IN CONST EmConfProtocol_Api emPro =em323_Api,
                                                      IN CONST SessionID dwSSID = KMTAPI_DEF_SSID);//add by zwf


/**
 * KdvMt_StopSpareCloudRecordCmd
 * @brief       停止空闲云端录像
 *
 * @param       [in]    dwSSID      MT会话ID
 * @return      u32     0:成功      其他错误码
 */
KdvMtAPI u32 KdvMtCALL KdvMt_StopSpareCloudRecordCmd( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID);//add by zwf

/**
 * KdvMt_GetCurSpareCloudRecordState
 * @brief       获取空闲云端录像状态，当前是否在录像
 *
 * @param       [in]    dwSSID      MT会话ID
  * @param      [out]   bRecord     当前是否在录像
 * @return      u32     0:成功      其他错误码
 */
KdvMtAPI u32 KdvMtCALL KdvMt_GetCurSpareCloudRecordState( OUT TCloudRecordState_Api &tRecordState, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID);//add by zwf

/**
 * KdvMt_GetSpareCloudRecordStateReq
 * @brief       请求空闲云端录像状态
 *
 * @param       [in]    dwSSID      MT会话ID
 * @return      u32     0:成功      其他错误码
 */
KdvMtAPI u32 KdvMtCALL KdvMt_GetSpareCloudRecordStateReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID);




/*
* KdvMt_QueryCameraPresetPicReq
* @brief    查询预置位图片请求
*
* @param    [in]   emVideoIndex  主流视频源索引，em1st表示第一路  em2nd表示第二路
* @param    [in]   dwSSID         MT会话ID 
* @return   u32    0：成功        其他错误码
*/
KdvMtAPI u32 KdvMtCALL KdvMt_QueryCameraPresetPicReq( IN CONST EmCodecComponentIndex_Api emVideoIndex, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/*
* KdvMt_SetCallCap
* @brief    设置,更新，呼叫能力
*
* @param    [in]   tSendCallCap   发送编码能力
* @param    [in]   tRecvCallCap   接收解码能力
* @param    [in]   emPro          协议，指定323能力或者sip能力
* @param    [in]   dwSSID         MT会话ID 
* @return   u32    0：成功        其他错误码
*/
KdvMtAPI u32 KdvMtCALL KdvMt_SetCallCap( IN CONST TMtSendCap_Api &tSendCallCap,  IN CONST TMtRecvCap_Api &tRecvCallCap, 
	                                    IN CONST EmConfProtocol_Api emPro = em323_Api, 
										IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/*
* KdvMt_GetCurPollingMtReq
* @brief    查询当前正在轮询的终端请求  ui->sdk->mtservice->sdk
*
* @param    [in]   dwSSID         MT会话ID 
* @return   u32    0：成功        其他错误码
* @note 响应消息：Ev_MtApi_Vc_GetCurPollMt_Rsp 
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfGetCurPollingMtReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/*
* KdvMt_ConfGetDualStreamSenderReq
* @brief    获取当前双流发送方请求
*
* @param    [in]   dwSSID         MT会话ID 
* @return   u32    0：成功        其他错误码
* @note 响应消息：Ev_MtApi_Vc_GetDualStreamSender_Rsp 
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfGetDualStreamSenderReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
 * KdvMt_ConfGetDualStreamSenderMt
 * @brief       获取当前发送双流终端
                当多点会议中有终端发双流， 上层会收到Ev_MtApi_Vc_AssSndSream_Status_Ntf,Ev_MtApi_Vc_AssRcvSream_Status_Ntf，
				再调用KdvMt_ConfGetDualStreamSenderMt此接口拿当前的双流发送方
 *
 * @param      [out]   tMtId_Api     终端标识
 * @param       [in]    dwSSID      MT会话ID
 * @return      u32     0:成功      其他错误码
 */
KdvMtAPI u32 KdvMtCALL KdvMt_ConfGetDualStreamSenderMt( OUT TMtId_Api &tMtId_Api, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID);

/*
* KdvMt_SetCodecMonitorPicShotCmd
* @brief    开启/关闭监控图片拍摄功能
*
* @param    [in]   emCodecType   类型
* @param    [in]   emCodecId     具体哪一路
* @param    [in]   bOn           打开或关闭
* @param    [in]   nIndex        0或1
* @return   u32    0：成功       其他错误码
* @note 响应消息：Ev_MtApi_Vc_CodecMonitorPic_Ntf 
*/
KdvMtAPI u32 KdvMtCALL KdvMt_SetCodecMonitorPicShotCmd( IN CONST EmCodecComponent_Api emCodecType, IN CONST EmCodecComponentIndex_Api emCodecId, IN CONST BOOL32 bOn,IN CONST s32 nIndex, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/*
* KdvMt_GetCodecMonitorPicShotStatusReq
* @brief    查询监控图片拍摄功能是否开启
*
* @param    [in]   emCodecType 类型
* @param    [in]   emCodecId     具体哪一路
* @return   u32    0：成功        其他错误码
* @note 响应消息：Ev_MtApi_Vc_CodecMonitorPicStatus_Rsp 
*/
KdvMtAPI u32 KdvMtCALL KdvMt_GetCodecMonitorPicShotStatusReq( IN CONST EmCodecComponent_Api emCodecType, IN CONST EmCodecComponentIndex_Api emCodecId, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/*
* KdvMt_MtcRemoteCtrlCmd
* @brief    Mtc遥控命令接口
*
* @param    [in]   tInfo 按键信息
* @return   u32    0：成功        其他错误码
* @note 响应消息：Ev_MtApi_Vc_DeviceKeyCodeNtf 
*/
KdvMtAPI u32 KdvMtCALL KdvMt_MtcRemoteCtrlCmd( IN CONST TMTKeyPressInfo_Api tInfo, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/*
* KdvMt_MediaDecCallBackControlCmd
* @brief    仅（win32）
* @param    [in]   emCodecType 类型
* @param    [in]   emCodecId     具体哪一路
* @param    [in]   bOn           打开或关闭
* @return   u32    0：成功        其他错误码
* @note 响应消息： 
*/
KdvMtAPI u32 KdvMtCALL KdvMt_MediaDecCallBackControlCmd( IN CONST EmCodecComponent_Api emCodecType, IN CONST EmCodecComponentIndex_Api emCodecId, IN CONST BOOL32 bOn, IN CONST SessionID dwSSID  = KMTAPI_DEF_SSID );

/*
* KdvMt_SnapshotFileRenameReq
* @brief    快照文件重命名请求
*
* @param    [in]   tSrcInfo 修改前信息
* @param    [in]   tDstInfo 修改后信息
* @return   u32    0：成功        其他错误码
* @note 响应消息：Ev_MtApi_Vc_CodecSnapshotRename_Rsp    Ev_MtApi_Vc_CodecSnapshotRename_Ntf 
*/
KdvMtAPI u32 KdvMtCALL KdvMt_SnapshotFileRenameReq( IN CONST TSnapshotFileInfo_Api tSrcInfo, IN CONST TSnapshotFileInfo_Api tDstInfo, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/*
* KdvMt_StopExportAllSnapshotFilesCmd
* @brief    停止导出所有快照文件命令
*
* @return   u32    0：成功        其他错误码
* @note 响应消息：Ev_MtApi_Vc_CodecStopExportAllSnapshotFiles_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_StopExportAllSnapshotFilesCmd(IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_ConfGetTerCameroPosCmd
* 
* @brief   主席获取终端tmtid的预置位列表，用在多点，只有主席有权限，5.0平台支持，非标
*
* @param    [out]  tMtid        对端的当前的视频源
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    0：获取成功  其他错误码
*
* @note Ev_MtApi_Vc_TerGetTerCameroPos_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfGetTerCameroPosCmd( IN CONST TMtId_Api &tMtid, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/*
* KdvMt_CodecOsdSnapshotCmd
* @brief    OSD快照命令
*
* @return   u32    0：成功        其他错误码
* @note 响应消息：
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CodecOsdSnapshotCmd(IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/*
* KdvMt_ConfUseGKUSBCmd
* @brief    是否插入GK免授权的USB
*
* @param    [in]   bUseGkUsb    是否插入 
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    0：成功        其他错误码
* @note 响应消息：
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfUseGKUSBCmd( IN CONST BOOL32 bUseGkUsb, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/*
* KdvMt_CodecSetShowOsdCmd
* @brief    设置是否显示osd
*
* @return   u32    0：成功        其他错误码
* @note 响应消息：
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CodecSetShowOsdCmd(IN CONST BOOL32 bShow, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/*
* KdvMt_StartLocalRecordCmd
* @brief	开始本地录像, 仅硬终端
*
* @param    [in]	pszRecPathName  存放录像的路径名
* @param    [in]	dwSSID          MT会话ID 
* @return   u32		0：成功         其他错误码
*
* @note 响应消息：	Ev_MtApi_Vc_StartLocalRec_Ntf, Ev_MtApi_Vc_LocalRecStatus_Ntf, Ev_MtApi_Vc_RemainTimeLocalRec_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_StartLocalRecordCmd( IN CONST s8* pszRecPathName, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/*
* KdvMt_StopLocalRecordCmd
* @brief	停止本地录像, 仅硬终端
*
* @param    [in]	dwSSID       MT会话ID 
* @return   u32		0：成功      其他错误码
*
* @note 响应消息：Ev_MtApi_Vc_StopLocalRec_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_StopLocalRecordCmd( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/*
* KdvMt_PauseLocalRecordCmd
* @brief	暂停本地录像, 仅硬终端
*
* @param    [in]	dwSSID       MT会话ID 
* @return   u32		0：成功      其他错误码
*
* @note 响应消息：Ev_MtApi_Vc_PauseLocalRec_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_PauseLocalRecordCmd( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/*
* KdvMt_ContinueLocalRecordCmd
* @brief	继续本地录像, 仅硬终端
*
* @param    [in]	dwSSID       MT会话ID 
* @return   u32		0：成功      其他错误码
*
* @note 响应消息：Ev_MtApi_Vc_ContinueLocalRec_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ContinueLocalRecordCmd( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/*
* KdvMt_GetLocalRecStatusReq
* @brief	获取本地录像状态的请求(是否在录像中),仅硬终端
*
* @param    [in]	dwSSID       MT会话ID 
* @return   u32		0：成功      其他错误码
*
* @note 响应消息：Ev_MtApi_Vc_StartLocalRec_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_GetLocalRecStatusReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/*
* KdvMt_GetLocalRecStartTimeCmd
* @brief	获取本地录像开始时间的命令，仅硬终端
*
* @param    [in]	dwSSID       MT会话ID 
* @return   u32		0：成功      其他错误码
*
* @note 响应消息：Ev_MtApi_Vc_LocalRecStartTime_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_GetLocalRecStartTimeCmd( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/*
* KdvMt_CodecPicGetReq
* @brief	获取的监控图片, 仅硬终端
*
* @param    [in]	nIndex       nIndex 0/1
* @param    [in]	dwSSID       MT会话ID 
* @return   u32		0：成功      其他错误码
*
* @note 响应消息：Ev_MtApi_Vc_CodecPicGet_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CodecPicGetReq( IN CONST s32 nIndex,IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_ControlCameraOsd_Cmd
*
* @brief   终端控制摄像机osd操作（仅Embed）
*
*@param     [in]   emVideoIndex       主流视频源索引，em1st表示第一路  em2nd表示第二路
* @param    [in]   emCameraOsdType    osd的操作类型
* @param    [in]   dwSSID             MT会话ID 
* @return   u32    0：获取成功  其他错误码
*
* @note 更新通知：无
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ControlCameraOsdCmd( IN CONST EmCodecComponentIndex_Api emVideoIndex, IN CONST EmTerControlCameraOsdType_Api emCameraOsdType, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_NewVodStartPlayVodCmd
*
* @brief   开始点播命令
*
* @param    [in]   pszUrl       点播的VOD URL信息
* @param    [in]   bFalg        重复点播为TRUE，默认FALSE 
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 响应通知：Ev_MtApi_Vc_VODPlay_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_NewVodStartPlayVodCmd( IN CONST s8* pszUrl,IN CONST BOOL32 bFalg = FALSE , IN CONST SessionID dwSSID = KMTAPI_DEF_SSID ); 


/**
* KdvMt_NewVodStopPlayVodCmd
*
* @brief   停止点播命令
*
* @param    [in]   dwVodId      要停止的VOD点播源ID
* @param    [in]   bFalg        重复点播为TRUE，默认FALSE
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 响应通知：Ev_MtApi_Vc_VODOver_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_NewVodStopPlayVodCmd( IN CONST u32 dwVodId,IN CONST BOOL32 bFalg = FALSE,IN CONST SessionID dwSSID = KMTAPI_DEF_SSID ); 

/**
* KdvMt_ConfGetCallIdReq
*
* @brief   获取callid，用于白板会议
*
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 响应通知：Ev_MtApi_Vc_Callid_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfGetCallIdReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID ); 

/* KdvMt_OsdCtrlPcAssStreamCmd
* 
* @brief   通过osd来打开/关闭pc双流，暂时用于sky100，sky100不支持硬双流
*
* @param    [in]   bOpen       TRUE:开始 FALSE:停止
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 响应通知：
*/
KdvMtAPI u32 KdvMtCALL KdvMt_OsdCtrlPcAssStreamCmd( IN CONST BOOL32 bOpen, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/* KdvMt_SetSubMtListCmd
* 
* @brief   5.2平台开始支持是否订阅终端列表的方式， 不采用默认推终端列表， 如果界面需要，就订阅，不需要就取小订阅，
           会节省和平台之间不必要的数据交互   18.5.3by wwuhu 
*
* @param    [in]   bSub         TRUE:订阅 FALSE：不订阅
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    返回0，表示订阅成功， 返回1表示， 对端不支持订阅，底层一入会，会获取当前所有的类别， UI直接调用KdvMt_ConfGetConfMtMember获取列表
*
* @note 响应通知： 主席终端不需要订阅，非主席终端需要订阅，订阅后如果有新的终端加入退会， 平台会推送，否则平台不推送
                   UI可以先调KdvMt_ConfGetConfMtMember，获取当前的列表， 然后调用KdvMt_SetSubMtListCmd接口， 如果收到
                   Ev_MtApi_Vc_OnLineTerList_Ntf再更新终端列表

*/
KdvMtAPI u32 KdvMtCALL KdvMt_SetSubMtListCmd(IN CONST BOOL32 bSub, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_ConfGetCloseMainVidReq
*
* @brief   请求是否关闭主流能力
*
* @param    [in]   dwSSID      MT会话ID 
* @return   u32    0：获取成功  其他错误码
* @note 回复通知：Ev_MtApi_Vc_GetCloseMainVid_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ConfGetCloseMainVidReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**@}*/

/**@}*/
#endif //_MTAPI_VCAPI_H_
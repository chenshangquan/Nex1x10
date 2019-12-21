/*******************************************************************************//**
*@file          mtapi_dcsapi.h
*@brief         提供mtDcsapi对外接口
*
*@author        wangfeifei
*@version       5.0    
*@date          20150328
*@copyright     (c)1995-2015 Suzhou Keda Technology Co.,Ltd. All rights reserved
***********************************************************************************/
#ifndef _MTAPI_DCSAPI_H_
#define _MTAPI_DCSAPI_H_
/**@addtogroup api API接口
*@{
*/

/**@addtogroup dcsapi 电子白板API
*@{
*/

#include <string.h>
#include "mtapi_export.h"
#include "mtapi_typedef.h"
#include "mtapi_struct.h"


 

/**
* KdvMt_DCSIsInited
*
* @brief mtdcsapi是否进行过初始化
*
* @param	[in] void
* @return	BOOL32  TRUE ： 已初始化， FALSE：尚未初始化
* @note KdvMt_DCSInitalize, KdvMt_DCSUnInitalize
*/
KdvMtAPI BOOL32 KdvMtCALL KdvMt_DCSIsInited();



/**
* KdvMt_DCSInitalize
*
* @brief mtdcsapi模块初始化（这个的调用要在mtbaseapi调用的setnotify之后）
*
* @return	u32  0: 初始化成功， 非0: 初始化失败
* @note KdvMt_MGIsInited, KdvMt_MGUnInitalize
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DCSInitalize( );



/**
* KdvMt_DCSUnInitalize
*
* @brief mtdcsapi模块释放退出
*
* @param	[in] void
* @return	u32  0: 成功， 非0: 失败
* @note KdvMt_MGIsInited, KdvMt_MGInitalize
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DCSUnInitalize();


/**
* KdvMt_DCSSetNotify
*
* @brief  注册Observer(UI)通知回调(这个函数如果没有调用则使用mtbaseapi中的回调函数)
*
* @param    [in]   cbNotify  要注册的回调函数
* @return   void
* @note
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DCSSetNotify( IN NOTIFY_OBSERVER_CALLBACK cbNotify );


/**
* KdvMt_DCSLoginConnectCmd
*
* @brief  登录前序，需要先建链（建链完毕后，才能再调用登录KdvMt_DCSLoginSrvReq）
*
* @param	[in]	TDCSConnect_Api-->连接信息
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：Ev_MtApi_DcsLoginResult_Ntf
*/
//KdvMtAPI u32 KdvMtCALL KdvMt_DCSLoginConnectCmd( IN CONST TDCSConnect_Api& tConnect_Api, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_DCSConfConnectCmd
*
* @brief  会议操作前，需要先建链（建链完毕后，才能再入会等操作）
*
* @param	[in]	TDCSConnect_Api-->连接信息
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：Ev_MtApi_DcsConfResult_Ntf
*/
//KdvMtAPI u32 KdvMtCALL KdvMt_DCSConfConnectCmd( IN CONST TDCSConnect_Api& tConnect_Api, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_DCSLoginSrvReq
*
* @brief  连接电子白板服务器
*
* @param	[in]	TDCSRegInfo_Api-->终端信息
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：Ev_MtApi_DcsLoginSrv_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DCSLoginSrvReq( IN CONST TDCSRegInfo_Api& tRegInfo_Api, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_DCSLogoutReq
*
* @brief  登出电子白板服务器
*
* @param	[in]	无
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：Ev_MtApi_DcsLogout_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DCSLogoutReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
* KdvMt_DCSCreateConfReq
*
* @brief  建立会议中的电子白板
*
* @param	[in]	TDCSCreateConf_Api->会议结构
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：Ev_MtApi_DcsCreateConf_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DCSCreateConfReq( IN CONST TDCSCreateConf_Api& tConf_Api, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_DCSGetConfInfoReq
*
* @brief  获取电子白板会议中的信息（复用结构）
*
* @param	[in]	TDCSCreateConf_Api->会议结构
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：Ev_MtApi_DcsCreateConf_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DCSGetConfInfoReq( IN CONST SessionID dwSSID /*= KMTAPI_DEF_SSID*/ );

/**
* KdvMt_DCSGetConfAddrReq
*
* @brief  获取会议地址
*
* @param	[in]	s8*->会议E164号
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：Ev_MtApi_DcsGetConfAddr_Rsp
*/
//KdvMtAPI u32 KdvMtCALL KdvMt_DCSGetConfAddrReq( IN CONST s8 *pchConfE164, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_DCSJoinConfReq
*
* @brief  加入会议中的电子白板请求
*
* @param	[in]	s8*->会议E164号
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：Ev_MtApi_DcsJoinConf_Rsp
*/
//KdvMtAPI u32 KdvMtCALL KdvMt_DCSJoinConfReq( IN CONST s8 *pchConfE164, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
* KdvMt_DCSRejectJoinConfCmd
*
* @brief  当前终端拒绝入会
*
* @param	[in]	TDCSRejectJoinConf_Api->拒绝入会结构
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：无
*/
//KdvMtAPI u32 KdvMtCALL KdvMt_DCSRejectJoinConfCmd( IN CONST TDCSRejectJoinConf_Api& tRejectJoinConf_Api, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_DCSQuitConfReq
*
* @brief  退出会议中的电子白板请求
*
* @param	[in]	s8*->会议E164号
					u32->	0: 同时操作视频、数据，请携带0（视频会议也退出，白板会议也退出->为了解决，如果主动退出视频会议，白板会议服务器就不再呼叫该终端入会，下一次的时候）
							1: 只操作数据协作，请携带1（视频会议还在，只是推出白板会议）
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：Ev_MtApi_DcsQuitConf_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DCSQuitConfReq( IN CONST s8 *pchConfE164, IN CONST u32 dwForceFlag, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
* KdvMt_DCSReleaseConfReq
*
* @brief  结束会议中的电子白板请求
*
* @param	[in]	s8*->会议E164号
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：Ev_MtApi_DcsReleaseConf_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DCSReleaseConfReq( IN CONST s8 *pchConfE164, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_DCSAddMemberReq
*
* @brief  添加电子白板会议中人员请求
*
* @param	[in]	TDCSMemberInfo_Api->人员信息
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：Ev_MtApi_DcsAddMember_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DCSAddMemberReq( IN CONST TDCSMemberInfo_Api& tMemInfo_Api, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_DCSDelMemberReq
*
* @brief  删除电子白板会议中人员请求
*
* @param	[in]	TDCSMemberInfo_Api->人员信息
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：Ev_MtApi_DcsDelMember_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DCSDelMemberReq( IN CONST TDCSMemberInfo_Api& tMemInfo_Api, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_DCSSetConfInfoReq
*
* @brief   设置电子白板会议信息请求
*
* @param	[in]	TDCSConfInfo_Api->会议信息
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：Ev_MtApi_DcsSetConfInfo_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DCSSetConfInfoReq( IN CONST TDCSConfInfo_Api& tConfInfo_Api, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_DCSSetUserRoleReq
*
* @brief   设置电子白板人员角色请求
*
* @param	[in]	TDCSSetUserRole_Api->人员信息
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：Ev_MtApi_DcsSetUserRole_Ntf
*/
//KdvMtAPI u32 KdvMtCALL KdvMt_DCSSetUserRoleReq( IN CONST TDCSSetUserRole_Api& tUserRole_Api, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_DCSAddOperatorReq
*
* @brief   添加协作方
*
* @param	[in]	TDCSAdpOperator_Api->人员信息
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：Ev_MtApi_DcsAddOperator_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DCSAddOperatorReq( IN CONST TDCSOperator_Api& tAdpOperator_Api, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_DCSDelOperatorReq
*
* @brief   删除协作方
*
* @param	[in]	TDCSAdpOperator_Api->人员信息
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：Ev_MtApi_DcsDelOperator_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DCSDelOperatorReq( IN CONST TDCSOperator_Api& tAdpOperator_Api, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
* KdvMt_DCSApplyOperReq
*
* @brief    申请协作方请求
*
* @param	[in]	s8*->会议E164号
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：Ev_MtApi_DcsApplyOper_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DCSApplyOperReq( IN CONST s8 *pchConfE164, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
* KdvMt_DCSCancelOperReq
*
* @brief    取消协作方请求
*
* @param	[in]	s8*->会议E164号
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：Ev_MtApi_DcsCancelOper_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DCSCancelOperReq( IN CONST s8 *pchConfE164, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
* KdvMt_DCSGetUserListReq
*
* @brief    获取用户列表信息
*
* @param	[in]	s8*->会议E164号
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：Ev_MtApi_DcsGetUserList_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DCSGetUserListReq( IN CONST s8 *pchConfE164, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_DCSNewWhiteBoardReq
*
* @brief    新建一个白板请求
*
* @param	[in]	TDCSNewWhiteBoard_Api->新白板参数
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：Ev_MtApi_DcsNewWhiteBoard_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DCSNewWhiteBoardReq( IN CONST TDCSNewWhiteBoard_Api& tBoard_Api, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );




/**
* KdvMt_DCSDelWhiteBoardReq
*
* @brief    删除一个白板请求
*
* @param	[in]	s8*->会议E164号
			[in]	s8*->要获取的白板索引
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：Ev_MtApi_DcsDelWhiteBoard_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DCSDelWhiteBoardReq( IN CONST s8 *pchConfE164, IN CONST s8 *pchIndex, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_DCSDelAllWhiteBoardReq
*
* @brief    删除所有白板请求
*
* @param	[in]	s8*->会议E164号
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：Ev_MtApi_DcsDelAllWhiteBoard_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DCSDelAllWhiteBoardReq( IN CONST s8 *pchConfE164, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_DCSGetAllWhiteBoardReq
*
* @brief    获取所有白板请求
*
* @param	[in]	s8*->会议E164号
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：Ev_MtApi_DcsGetAllWhiteBoard_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DCSGetAllWhiteBoardReq( IN CONST s8 *pchConfE164, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_DCSGetWhiteBoardReq
*
* @brief    获取指定白板请求
*
* @param	[in]	s8*->会议E164号
			[in]	s8*->要获取的白板索引
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：Ev_MtApi_DcsGetWhiteBoard_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DCSGetWhiteBoardReq( IN CONST s8 *pchConfE164, IN CONST s8 *pchIndex, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_DCSGetCurWhiteBoardReq
*
* @brief    获取指定白板请求
*
* @param	[in]	s8*->会议E164号
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：Ev_MtApi_DcsGetCurWhiteBoard_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DCSGetCurWhiteBoardReq( IN CONST s8 *pchConfE164, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_DCSGetWhiteBoardReq
*
* @brief    切换白板请求
*
* @param	[in]	TDCSSwitchReq_Api->切换白板请求结构
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：Ev_MtApi_DcsSwitch_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DCSSwitchReq( IN CONST TDCSSwitchReq_Api& tSwitch_Api, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
* KdvMt_DCSOperPointCmd
*
* @brief    画点
*
* @param	[in]	TDCSWbPoint_Api->点结构
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：无
*/
//KdvMtAPI u32 KdvMtCALL KdvMt_DCSOperPointCmd( IN CONST TDCSWbPoint_Api& tPoint_Api, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
* KdvMt_DCSOperEntityCmd
*
* @brief    图元的基本信息：图元id和是否可擦除的标记操作
*
* @param	[in]	TDCSWbEntity_Api->图元的基本信息
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：无
*/
//KdvMtAPI u32 KdvMtCALL KdvMt_DCSOperEntityCmd( IN CONST TDCSWbEntity_Api& tEntity_Api, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_DCSOperLineCmd
*
* @brief    画线
*
* @param	[in]	TDCSWbLine_Api->线结构
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：无
*/
//KdvMtAPI u32 KdvMtCALL KdvMt_DCSOperLineCmd( IN CONST TDCSWbLine_Api& tLine_Api, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_DCSOperCircleCmd
*
* @brief    画圆
*
* @param	[in]	TDCSWbCircle_Api->画圆结构
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：无
*/
//KdvMtAPI u32 KdvMtCALL KdvMt_DCSOperCircleCmd( IN CONST TDCSWbCircle_Api& tCircle_Api, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
* KdvMt_DCSOperPencilCmd
*
* @brief    画铅笔
*
* @param	[in]	TDCSWbPencil_Api->铅笔结构
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：无
*/
//KdvMtAPI u32 KdvMtCALL KdvMt_DCSOperPencilCmd( IN CONST TDCSWbPencil_Api& tPencil_Api, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_DCSOperColorPenCmd
*
* @brief    画彩笔
*
* @param	[in]	TDCSWbColorPen_Api->彩笔结构
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：无
*/
//KdvMtAPI u32 KdvMtCALL KdvMt_DCSOperColorPenCmd( IN CONST TDCSWbColorPen_Api& tColorPen_Api, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
* KdvMt_DCSOperImageCmd
*
* @brief    图片图元
*
* @param	[in]	TDCSWbImage_Api->图片图元结构
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：无
*/
//KdvMtAPI u32 KdvMtCALL KdvMt_DCSOperImageCmd( IN CONST TDCSWbImage_Api& tImage_Api, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
* KdvMt_DCSOperLineOperInfoCmd
*
* @brief    线操作
*
* @param	[in]	TDCSOperReq_Api->操作白板相关信息
					TDCSWbLineOperInfo_Api->线操作
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：无
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DCSOperLineOperInfoCmd( IN CONST TDCSOperReq_Api& tOperReq_Api, IN CONST TDCSWbLineOperInfo_Api& tLineOperInfo_Api, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
* KdvMt_DCSOperCircleOperInfoCmd
*
* @brief    圆操作
*
* @param	[in]	TDCSOperReq_Api->操作白板相关信息
					TDCSWbCircleOperInfo_Api->圆操作
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：无
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DCSOperCircleOperInfoCmd( IN CONST TDCSOperReq_Api& tOperReq_Api, IN CONST TDCSWbCircleOperInfo_Api& tCircleOperInfo_Api, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
* KdvMt_DCSOperRectangleOperInfoCmd
*
* @brief    矩形操作
*
* @param	[in]	TDCSOperReq_Api->操作白板相关信息
					TDCSWbRectangleOperInfo_Api->矩形操作
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：无
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DCSOperRectangleOperInfoCmd( IN CONST TDCSOperReq_Api& tOperReq_Api, IN CONST TDCSWbRectangleOperInfo_Api& tRectangleOperInfo_Api, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_DCSOperCircleOperInfoCmd
*
* @brief    铅笔集操作
*
* @param	[in]	TDCSOperReq_Api->操作白板相关信息
					TDCSWbPencilOperInfo_Api->铅笔集操作
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：无
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DCSOperPencilOperInfoCmd( IN CONST TDCSOperReq_Api& tOperReq_Api, IN CONST TDCSWbPencilOperInfo_Api& tPencilOperInfo_Api, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
* KdvMt_DCSOperColorPenOperInfoCmd
*
* @brief    彩笔集操作
*
* @param	[in]	TDCSOperReq_Api->操作白板相关信息
					TDCSWbColorPenOperInfo_Api->彩笔集操作
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：无
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DCSOperColorPenOperInfoCmd( IN CONST TDCSOperReq_Api& tOperReq_Api, IN CONST TDCSWbColorPenOperInfo_Api& tColorPenOperInfo_Api, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_DCSOperImageOperInfoCmd
*
* @brief    图片图元集操作
*
* @param	[in]	TDCSOperReq_Api->操作白板相关信息
					TDCSWbImageOperInfo_Api->图片图元集操作
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：无
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DCSOperImageOperInfoCmd( IN CONST TDCSOperReq_Api& tOperReq_Api, IN CONST TDCSWbImageOperInfo_Api& tImageOperInfo_Api, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
* KdvMt_DCSOperTabPageIdInfoCmd
*
* @brief    标记当前操作文档的tab页和subpage
*
* @param	[in]	TDCSWbTabPageIdInfo_Api->标记当前操作文档的tab页和subpage操作
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：无
*/
//KdvMtAPI u32 KdvMtCALL KdvMt_DCSOperTabPageIdInfoCmd( IN CONST TDCSWbTabPageIdInfo_Api& tTabPageIdInfo_Api, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_DCSOperRemovePageIdInfoCmd
*
* @brief    删除tab页携带的信息
*
* @param	[in]	TDCSWbRemovePageIdInfo_Api->删除tab页携带的信息操作
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：无
*/
//KdvMtAPI u32 KdvMtCALL KdvMt_DCSOperRemovePageIdInfoCmd( IN CONST TDCSWbRemovePageIdInfo_Api& tRemovePageIdInfo_Api, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_DCSOperTabPageInfoCmd
*
* @brief    白板页信息，在创建白板、更新白板信息等时候使用
*
* @param	[in]	TDCSWbTabPageInfo_Api->白板页信息，在创建白板、更新白板信息等时候使用的结构
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：无
*/
//KdvMtAPI u32 KdvMtCALL KdvMt_DCSOperTabPageInfoCmd( IN CONST TDCSWbTabPageInfo_Api& tTabPageInfo_Api, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
* KdvMt_DCSOperAddSubPageInfoCmd
*
* @brief    白板中添加子页信息，打开文档时，根据文档的总页数在当前白板中添加多个子页
*
* @param	[in]	TDCSOperReq_Api->操作白板相关信息
					TDCSWbAddSubPageInfo_Api->白板中添加子页信息，打开文档时，根据文档的总页数在当前白板中添加多个子页用的结构
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：无
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DCSOperAddSubPageInfoCmd( IN CONST TDCSOperReq_Api& tOperReq_Api, IN CONST TDCSWbAddSubPageInfo_Api& tAddSubPageInfo_Api, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
* KdvMt_DCSOperSwitchPageInfoCmd
*
* @brief    切换白板页信息，切换白板页包括两种情况：
			 1)在当前白板中从一个子页切换到另一子页，即前后翻页，或者翻到指定的页面
			 2)切换到另一个白板中
*
* @param	[in]	TDCSWbSwitchPageInfo_Api->切换白板页信息的结构
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：无
*/
//KdvMtAPI u32 KdvMtCALL KdvMt_DCSOperSwitchPageInfoCmd( IN CONST TDCSWbSwitchPageInfo_Api& tSwitchPageInfo_Api, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_DCSOperReqPageImageCmd
*
* @brief    客户端给服务器发送请求目标页图片请求
* @param	[in]	TDCSOperReq_Api->操作白板相关信息
					TDCSWbReqPageImage_Api->客户端给服务器发送请求目标页图片请求结构
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：无
*/
//KdvMtAPI u32 KdvMtCALL KdvMt_DCSOperReqPageImageCmd( IN CONST TDCSOperReq_Api& tOperReq_Api, IN CONST TDCSWbReqPageImage_Api& tReqPageImage_Api, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
* KdvMt_DCSOperEraseOperInfoCmd
*
* @brief    矩形擦除
* @param	[in]	TDCSOperReq_Api->操作白板相关信息
					TDCSWbEraseOperInfo_Api->矩形擦除结构
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：无
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DCSOperEraseOperInfoCmd( IN CONST TDCSOperReq_Api& tOperReq_Api, IN CONST TDCSWbEraseOperInfo_Api& tEraseOperInfo_Api, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_DCSOperZoomInfoCmd
*
* @brief    放大/缩小、横向/纵向自适应
* @param	[in]	TDCSOperReq_Api->操作白板相关信息
					TDCSWbZoomInfo_Api->放大/缩小、横向/纵向自适应结构
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：无
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DCSOperZoomInfoCmd( IN CONST TDCSOperReq_Api& tOperReq_Api, IN CONST TDCSWbZoomInfo_Api& tZoomInfo_Api, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );




/**
* KdvMt_DCSSendImgFileInfoCmd
*
* @brief    发送图片文件的信息
* @param	[in]	TDCSOperReq_Api->操作白板相关信息
					TDCSWbSendImgFileInfo_Api->发送图片文件的信息
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：无
*/
//KdvMtAPI u32 KdvMtCALL KdvMt_DCSSendImgFileInfoCmd( IN CONST TDCSOperReq_Api& tOperReq_Api, IN CONST TDCSWbSendImgFileInfo_Api& tSendImgFileInfo_Api, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_DCSOperUndoCmd
*
* @brief    撤销
* @param	[in]	TDCSOperReq_Api->操作白板相关信息
					TDCSWbTabPageIdInfo_Api->撤销信息
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：无
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DCSOperUndoCmd( IN CONST TDCSOperReq_Api& tOperReq_Api, IN CONST TDCSWbTabPageIdInfo_Api& tTabPageIdInfo_Api, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_DCSOperRedoCmd
*
* @brief    重做
* @param	[in]	TDCSOperReq_Api->操作白板相关信息
					TDCSWbTabPageIdInfo_Api->重做信息
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：无
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DCSOperRedoCmd( IN CONST TDCSOperReq_Api& tOperReq_Api, IN CONST TDCSWbTabPageIdInfo_Api& tTabPageIdInfo_Api, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
* KdvMt_DCSOperRotateLeftCmd
*
* @brief   左旋转
* @param	[in]	TDCSOperReq_Api->操作白板相关信息
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：无
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DCSOperRotateLeftCmd( IN CONST TDCSOperReq_Api& tOperReq_Api, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_DCSOperRotateRightCmd
*
* @brief   右旋转
* @param	[in]	TDCSOperReq_Api->操作白板相关信息
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：无
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DCSOperRotateRightCmd( IN CONST TDCSOperReq_Api& tOperReq_Api, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_DCSOperClearScreenCmd
*
* @brief   清屏
* @param	[in]	TDCSOperReq_Api->操作白板相关信息
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：无
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DCSOperClearScreenCmd( IN CONST TDCSOperReq_Api& tOperReq_Api, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
* KdvMt_DCSOperScrollScreenCmd
*
* @brief   滚屏
* @param	[in]	TDCSOperReq_Api->操作白板相关信息
					TDCSScrollScreenInfo_Api->滚屏信息
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：无
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DCSOperScrollScreenCmd( IN CONST TDCSOperReq_Api& tOperReq_Api, IN CONST TDCSScrollScreenInfo_Api& tScrollScreenInfo_Api, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_DCSOperFullScreenCmd
*
* @brief   全屏显示
* @param	[in]	TDCSOperReq_Api->操作白板相关信息
					TDCSWbDisPlayInfo_Api->全屏信息
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：无
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DCSOperFullScreenCmd(IN CONST TDCSOperReq_Api& tOperReq_Api, IN CONST TDCSWbDisPlayInfo_Api& tDisPlayInfo_Api, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_DCSOper100ProportionScreenCmd
*
* @brief   100%比例显示
* @param	[in]	TDCSOperReq_Api->操作白板相关信息
					TDCSWbDisPlayInfo_Api->100%比例信息
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：无
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DCSOper100ProportionScreenCmd(IN CONST TDCSOperReq_Api& tOperReq_Api, IN CONST TDCSWbDisPlayInfo_Api& tDisPlayInfo_Api, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_DCSOperReginEraseCmd
*
* @brief    区域擦除
* @param	[in]	TDCSOperReq_Api->操作白板相关信息
					TDCSWbReginEraseOperInfo_Api->区域擦除
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：无
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DCSOperReginEraseCmd(IN CONST TDCSOperReq_Api& tOperReq_Api, IN CONST TDCSWbReginEraseOperInfo_Api& tReginEraseOperInfo_Api, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_DCSOperInsertPicCmd
*
* @brief    插入图片
* @param	[in]	TDCSOperReq_Api->操作白板相关信息
					TDCSWbInsertPicOperInfo_Api->插入图片
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：无
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DCSOperInsertPicCmd(IN CONST TDCSOperReq_Api& tOperReq_Api, IN CONST TDCSWbInsertPicOperInfo_Api& tInsertPicOperInfo_Api, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_DCSOperPitchPicZoomCmd
*
* @brief    选中图片缩放
* @param	[in]	TDCSOperReq_Api->操作白板相关信息
					TDCSWbPitchPicOperInfo_Api->选中图片缩放
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：无
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DCSOperPitchPicZoomCmd(IN CONST TDCSOperReq_Api& tOperReq_Api, IN CONST TDCSWbPitchPicOperInfo_Api& tPitchPicOperInfo_Api, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_DCSOperPitchPicRotateCmd
*
* @brief    选中图片旋转
* @param	[in]	TDCSOperReq_Api->操作白板相关信息
					TDCSWbPitchPicOperInfo_Api->选中图片旋转
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：无
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DCSOperPitchPicRotateCmd(IN CONST TDCSOperReq_Api& tOperReq_Api, IN CONST TDCSWbPitchPicOperInfo_Api& tPitchPicOperInfo_Api, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_DCSOperPitchPicDragCmd
*
* @brief    选中图片拖动
* @param	[in]	TDCSOperReq_Api->操作白板相关信息
					TDCSWbPitchPicOperInfo_Api->选中图片拖动
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：无
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DCSOperPitchPicDragCmd(IN CONST TDCSOperReq_Api& tOperReq_Api, IN CONST TDCSWbPitchPicOperInfo_Api& tPitchPicOperInfo_Api, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_DCSOperPitchPicDelCmd
*
* @brief    选中图片删除
* @param	[in]	TDCSOperReq_Api->操作白板相关信息
					TDCSWbPitchPicOperInfo_Api->选中图片删除
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：无
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DCSOperPitchPicDelCmd(IN CONST TDCSOperReq_Api& tOperReq_Api, IN CONST TDCSWbDelPicOperInfo_Api& tDelPicOperInfo_Api, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
* KdvMt_DCSDownloadImageReq
*
* @brief    下载图片地址请求
* @param	[in]	TDCSImageUrl_Api->请求图片信息
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：Ev_MtApi_DcsDownloadImage_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DCSDownloadImageReq( IN CONST TDCSImageUrl_Api& tImageUrl_Api, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_DCSUploadImageReq
*
* @brief    上传图片地址请求
* @param	[in]	TDCSImageUrl_Api->请求图片信息
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：Ev_MtApi_DcsUploadImage_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DCSUploadImageReq( IN CONST TDCSImageUrl_Api& tImageUrl_Api, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_DCSUploadFileCmd
*
* @brief   上传文件
* @param	[in]	pchUploadUrl_Api->文件URL
* @param	[in]	TDCSFileInfo_Api->文件信息
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：Ev_MtApi_DcsUploadFile_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DCSUploadFileCmd( IN CONST s8* pchUploadUrl_Api, IN CONST TDCSFileInfo_Api& tFileInfo_Api, CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_DCSDownloadFileReq
*
* @brief   下载文件
* @param	[in]	pchDownloadUrl_Api->文件URL
* @param	[in]	TDCSFileInfo_Api->文件信息
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：Ev_MtApi_DcsDownloadFile_Rsp
* @note		
* @note		如果是获取图元信息成功，后续还会发送指定图元对应的消息：
* @note		Ev_MtApi_DcsOperLineOperInfo_Ntf、Ev_MtApi_DcsOperCircleOperInfo_Ntf......
* @note		图元数据发送完毕则发送Ev_MtApi_DcsElementOperFinal_Ntf告知应用层。
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DCSDownloadFileReq( IN CONST s8* pchDownloadUrl_Api, IN CONST TDCSFileInfo_Api& tFileInfo_Api, CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_DCSRejectOperatorCmd
*
* @brief   拒绝申请协作方
* @param	[in]	TDCSOperator_Api->操作信息
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：无
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DCSRejectOperatorCmd( IN CONST TDCSOperator_Api& tOperator_Api, CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_DCSJoinConfDomainRsp
*
* @brief   加入会议时候，对会议地址的域名查询
* @param	[in]	TDCSConfAddr_Api->会议地址
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：无
*/
KdvMtAPI u32 KdvMtCALL KdvMt_DCSJoinConfDomainRsp( IN CONST TDCSConfAddr_Api& tConfAddr_Api, CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**@}*/

/**@}*/
#endif //_MTAPI_DCSAPI_H_
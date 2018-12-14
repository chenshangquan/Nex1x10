#if !defined(_MTSERVICE_API_H_)
#define _MTSERVICE_API_H_

#include "kdvtype.h"
#include "mtstruct.h"
#include "abstractins.h"
#include "enum.pb.h"

#ifdef __cplusplus
extern "C" {
#endif


/////////////////////下面接口给硬终端mtservice_hd 用


////下面回调接口中定义的事件枚举
enum emMtServiceCBEv
{
/**
  @brief     播放铃声
  bCallIn: BOOL32,  是否是呼入
  bPlay:   BOOL32,  true, 播放， false， 停止
  @endverbatim
*/
     emPlayRing,

/**
  @brief     唤醒终端
  @endverbatim
*/
	 emWakeupMt,

/**
  @brief    停止本地自环
  @endverbatim
*/
	emStopLocalLoop,

/**
  @brief    停止ribbon测试
  @endverbatim
*/
	emStopCodecRibbonTest,

/**
  @brief     注册失败
  @endverbatim
*/
	emRegisterFail,

/**
  @brief     重启启动aps
  @endverbatim
*/
	emRestartAps,

/*
  @brief    启动或者关闭E1定时器
  @param    bStart: BOOL32,  是否启动
  @endverbatim
*/
   emCheckE1BandWidthTimer,

/*
  @brief    协议改变
  @endverbatim
*/
   emProtocalChanged,

/*
  @brief    获取E1带宽

  wBandwith:  u16,  INOUT参数   获取的带宽
  dwDestIP:   u32,  IN参数      目的ip
  @endverbatim
*/

   emGetE1BandWidth,

/*
  @brief    会议已经挂断

  @endverbatim
*/

   emConfIsIdle,

   
   /*
  @brief    API平台登录成功
  @endverbatim
*/
   emMoPlatFormLoginSucc,

    /*
  @brief    视频源是否在切换状态
  @endverbatim
*/
   emGetVideoSourceIsSwitch,
};



enum emMtServiceCmdEv
{
/**
  @brief    设置协议栈标准非标,暂时只是针对323协议栈
  bStand:   BOOL32,  是否标准
  @endverbatim
*/
    emSetStack,

/**
  @brief    终端状态改变，发送到平台， 状态包括是否静哑音，音量，视频源列表等
  @endverbatim
*/
    emSndMtStatusToPeer,

/**
  @brief    终端视频源别名改变，发送到对端
  @endverbatim
*/
    emSndVideoSourceInfoToPeer,

/**
  @brief   摄像头预置位改变，发送到对端
  @endverbatim
*/
    emSndCamoroPosToPeer,

/**
  @brief   手动输入gk， sip， 代理的情况去注册
  @endverbatim
*/
    emRegParamWithManu,

/**
  @brief   手动输入gk， sip， 代理的情况去取消注册
  @endverbatim
*/
    emUnRegParamWithManu,

/**
  @brief   重启323协议栈，启动代理，本地ip,端口，或者serverip,端口改变，需要重启协议栈
  @endverbatim
*/
	emRebootH323stackIn,

/**
  @brief   e1带宽改变，通知会议， 调整码率
  wBandwith:   u16,  e1带宽
  @endverbatim
*/
	emE1BandwidthChange,

/**
  @brief   登陆云之后注册gk/sip
  @endverbatim
*/
	emRegH323SipAfterAps,

/**
  @brief   停止发空闲双流
  @endverbatim
*/
	emStopPlayStream,

/**
  @brief   取消H323 GK注册
  @endverbatim
*/
	emUnGkReg,
};




//回调函数  filter
/**----------------------------------------------------------------------
	* ExternMtMsgHandlerFilter_CallBack
	* 
	* @brief    外面消息过滤器，如果外面处理过， mtservice就不会再处理
	* 
	* @param	[in] pcMtMsg 订阅消息的具体消息
	* @param	[in] dwSrcId 订阅消息的appinstid
	* @param	[in] dwSrcNode 订阅消息的nodeid
	* @return	BOOL32 TRUE:已经处理了，不需要继续由其它处理这个消息， FALSE:需要由其它处理这个消息
	------------------------------------------------------------------------*/
MTCBB_API typedef BOOL32 (*HDMtMsgHandler_CallBack)(mtmsg::CMtMsg *pcMtMsg, u32 dwSrcId, u32 dwSrcNode);

/**----------------------------------------------------------------------
	* ExternCMessHandlerFilter_CallBack
	* 
	* @brief    外面消息过滤器，外部处理CMessage消息的回调函数（定时器消息）
	* 
	* @param	[in] pcMtMsg 订阅消息的具体消息
	* @param	[in] dwSrcId 订阅消息的appinstid
	* @param	[in] dwSrcNode 订阅消息的nodeid
	* @return	BOOL32 TRUE:已经处理了，不需要继续由其它处理这个消息， FALSE:需要由其它处理这个消息
	------------------------------------------------------------------------*/
MTCBB_API typedef BOOL32 (*HDOspMsgHandler_CallBack)(CMessage* const pcMsg);

/**----------------------------------------------------------------------
	* HdExecServiceCommnd
	* 
	* @brief    通用的回调, 外部模块需要对事件类型做处理
	* 
	* @param	[in]    emEvtType  cmd类型
	* @param	[inout] pBuf       buf指针
	* @param	[inout] nBufLen    buf大小
	* @return	void
	------------------------------------------------------------------------*/
MTCBB_API typedef void (*OnHdEvent_CallBack)(IN emMtServiceCBEv emEvtType, INOUT void* pBuf, INOUT u16 nBufLen);


typedef struct tagTMtService_CallBack
{
	HDMtMsgHandler_CallBack         cbMtmsgHandler;
	HDOspMsgHandler_CallBack        cbOspMsgHandler;
	OnHdEvent_CallBack              cbHdEvnt;

	tagTMtService_CallBack()
	{
		memset(this,0,sizeof(tagTMtService_CallBack) );
	}

}TMtService_CallBack, *PTMtService_CallBack;


/**----------------------------------------------------------------------
	* SetMtServiceCallBack
	* 
	* @brief    设置回调函数
	* 
	* @param	[in] tCallback 回调函数
	* @return	void
	------------------------------------------------------------------------*/
MTCBB_API void HdSetMtServiceCallBack( TMtService_CallBack *ptCallback );


/**----------------------------------------------------------------------
	* HdGetMtserviceIns
	* 
	* @brief    获取当前的CAbstractIns
	* 
	* @param	[in] tCallback 回调函数
	* @return	void
	------------------------------------------------------------------------*/
MTCBB_API CAbstractIns* HdGetMtserviceIns( );


/**----------------------------------------------------------------------
	* HdExecServiceCommnd
	* 
	* @brief    Hdservice执行cmd命令，调用mtservice的接口
	* 
	* @param	[in]    emEvtType  cmd类型
	* @param	[inout] pBuf       buf指针
	* @param	[inout] nBufLen    buf大小
	* @return	void
	------------------------------------------------------------------------*/
MTCBB_API void HdExecServiceCommnd( emMtServiceCmdEv emEvtType,INOUT void* pBuf = NULL, INOUT u16 wBufLen =0);







#ifdef __cplusplus
}
#endif

#endif // _MTSERVICE_API_H_
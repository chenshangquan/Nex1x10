/**===========================================================================
 * @file    $Id$
 * @brief   负责MtVncAPi 桌面共享配置数据和信令交互相关功能接口定义
 * @author  $Author$
 * @date    $Date$
 * @version  $Revision$ 
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note    
============================================================================*/

#ifndef _I_MTVNCCFG_H_
#define _I_MTVNCCFG_H_

#include "mtapi_typedef.h"
#include "mtapi_if.h"
#include "mtapi_event_vnc.h"


/**---------------------------------------------------------------------------
 * @class   Interface IMtCha
 * @brief   负责MtVncAPi 桌面共享配置数据和信令交互相关功能接口定义
 * @author  $Author$
 * @version 
 * @date    $Date::                      $
 * @note    
 ---------------------------------------------------------------------------*/

class IMtVncCfg : public IMtApiIF
{
public:
	//请求终端video辅流发送状态
	virtual u32 GetAssSndVidStatusReq() = 0;
	//请求终端video辅流接受状态
	virtual u32 GetAssRcvVidStatusReq() = 0;
	//pc桌面共享开始停止请求
	virtual u32 PcAssStreamReq( const TNetAddr_Api& tPcRtcp, const BOOL32 bStart ) = 0;
	virtual u32 PlayStream( const TNetAddr_Api& tPcRtcp, const BOOL32 bStart, 
		const EmCodecComponent_Api emCodecType, 
		const EmCodecComponentIndex_Api emVideoIndex ) = 0;
	//设置通道活动状态
	virtual u32 SetChanActive( const BOOL32 bActive ) = 0;

	//获取终端video辅流发送状态
	virtual TMtAssVidStatusList_Api GetAssSndVidStatus() = 0;
	//获取终端video辅流接受状态
	virtual TMtAssVidStatusList_Api GetAssRcvVidStatus() = 0;
	//获取PC流所有通道参数
	virtual TMTPcAssStreamChanParam_Api GetPcAssStreamChanParam() = 0;
};

#endif // _I_MTVNCCFG_H_
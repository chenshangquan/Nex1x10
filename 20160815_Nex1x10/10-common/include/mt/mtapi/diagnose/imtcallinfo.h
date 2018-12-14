/**===========================================================================
 * @file    $Id$
 * @brief   负责MtDiagnoseApi终端呼叫信息统计相关功能接口定义
 * @author  $Author$
 * @date    $Date$
 * @version  $Revision$ 
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note    
============================================================================*/

#ifndef _I_MTCALLINFO_H_
#define _I_MTCALLINFO_H_

#include "mtapi_typedef.h"
#include "mtapi_if.h"
#include "mtapi_event_diagnose.h"


/**---------------------------------------------------------------------------
 * @class   Interface IMtCallInfo
 * @brief   负责MtDiagnoseApi终端呼叫信息统计相关功能接口定义
 * @author  $Author$
 * @version 
 * @date    $Date::                      $
 * @note    
 ---------------------------------------------------------------------------*/
class IMtCallInfo: public IMtApiIF
{
public:
	//请求端口信息
	virtual u32    GetPortInfoReq(  ) = 0;
	//获取端口信息
	virtual TMTTotalUsedPort_Api GetPorInfo( ) = 0;

	//获取编解码、混音、合成、网络统计信息请求
	virtual BOOL32 GetCallStatisticsInfoReq( ) = 0;

	//获取编解码、混音、合成、网络统计信息
	virtual TMtCodecStatistic_Api GetCallStatisticsInfo() =0;
};

#endif // _I_MTCALLINFO_H_
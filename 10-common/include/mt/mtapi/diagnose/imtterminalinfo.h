/**===========================================================================
 * @file    $Id$
 * @brief   负责MtDiagnoseApi终端系统相关功能接口定义
 * @author  $Author$
 * @date    $Date$
 * @version  $Revision$ 
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note    
============================================================================*/

#ifndef _I_MTTERMINALINFO_H_
#define _I_MTTERMINALINFO_H_

#include "mtapi_typedef.h"
#include "mtapi_if.h"
#include "mtapi_event_diagnose.h"


/**---------------------------------------------------------------------------
 * @class   Interface IMtTerminalInfo
 * @brief   负责MtDiagnoseApi终端呼叫信息统计相关功能接口定义
 * @author  $Author$
 * @version 
 * @date    $Date::                      $
 * @note    
 ---------------------------------------------------------------------------*/
class IMtTerminalInfo: public IMtApiIF
{
public:
	//请求系统运行时间
	virtual u32 GetMtRunTimeReq(  ) = 0;

	//请求终端信息
	virtual u32 GetMtTerInfoReq(  ) = 0;
	//获取系统运行时间
	virtual u32 GetMtRunTime( ) = 0 ;
	//获取终端信息
	virtual TTerminalInfo_Api GetTerInfo( ) = 0;
public:

private:

};

#endif // _I_MTTERMINALINFO_H_
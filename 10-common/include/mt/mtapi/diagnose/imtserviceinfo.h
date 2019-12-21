/**===========================================================================
 * @file    $Id$
 * @brief   负责MtDiagnoseApi终端服务器信息统计相关功能接口定义
 * @author  $Author$
 * @date    $Date$
 * @version  $Revision$ 
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note    
============================================================================*/

#ifndef _I_MTSERVERINFO_H_
#define _I_MTSERVERINFO_H_

#include "mtapi_typedef.h"
#include "mtapi_if.h"
#include "mtapi_event_diagnose.h"


/**---------------------------------------------------------------------------
 * @class   Interface IMtServerInfo
 * @brief   负责MtDiagnoseApi终端服务器信息统计相关功能接口定义
 * @author  $Author$
 * @version 
 * @date    $Date::                      $
 * @note    
 ---------------------------------------------------------------------------*/
class IMtServerInfo: public IMtApiIF
{
public:
	//请求服务器信息
	virtual u32 GetServerInfoReq(  ) = 0;
	//获取服务器信息
	virtual TMTSrvInfoList_Api  GetServerInfo( ) = 0;

private:

};

#endif // _I_MTSERVERINFO_H_
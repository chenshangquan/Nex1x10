/**===========================================================================
 * @file    $Id$
 * @brief   负责终端通用功能的接口定义
 * @author  $Author$
 * @date    $Date$
 * @version  $Revision$ 
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note    
============================================================================*/

#ifndef _I_MTCOMMON_H_
#define _I_MTCOMMON_H_

#include "nvapi_typedef.h"
#include "nvapi_if.h"
#include "nvapi_event_base.h"




/**---------------------------------------------------------------------------
 * @class   Interface INvCommon
 * @brief   负责终端通用功能的接口定义
 * @author  $Author$
 * @version 
 * @date    $Date::                      $
 * @note    
 ---------------------------------------------------------------------------*/
class INvCommon : public INvApiIF
{
public:
	//通知正在使用的网络信息
	virtual u32 SendUsedNetInfoNtf( const nv::TNVNetUsedInfo& tNetUsedInfo ) = 0;
	//设置日志打印
	virtual u32 SetLogHintCmd( const nv::TString& tLog ) = 0;
public:

};

#endif // _I_MTCOMMON_H_
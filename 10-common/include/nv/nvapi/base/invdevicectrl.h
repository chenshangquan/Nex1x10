/**===========================================================================
 * @file    $Id$
 * @brief   负责终端视频接口定义
 * @author  $Author$
 * @date    $Date$
 * @version  $Revision$ 
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note    
============================================================================*/

#ifndef _I_NVDEVICECTRL_H_
#define _I_NVDEVICECTRL_H_

#include "nvapi_typedef.h"
#include "nvapi_if.h"
#include "nvapi_event_base.h"




/**---------------------------------------------------------------------------
 * @class   Interface INvDeviceCtrl
 * @brief   负责终端通用功能的接口定义
 * @author  $Author$
 * @version 
 * @date    $Date::                      $
 * @note    
 ---------------------------------------------------------------------------*/
class INvDeviceCtrl : public INvApiIF
{
public:
	virtual u32 SetTvBrightnessReq( IN CONST nv::TS32 &tScreentype, IN CONST nv::TU32 &tBrightness ) = 0;
	virtual u32 SetTvContrasteReq( IN CONST nv::TS32 &tScreentype, IN CONST nv::TU32 &tContraste ) = 0;
	virtual u32 SetTvSaturationReq( IN CONST nv::TS32 &tScreentype, IN CONST nv::TU32 &tSaturation ) = 0;
	virtual u32 SetTvClarityReq( IN CONST nv::TS32 &tScreentype, IN CONST nv::TU32 &tClarity ) = 0;
	virtual u32 SetTvColortempReq( IN CONST nv::TS32 &tScreentype, IN CONST nv::TS32 &tColortemp ) = 0;
	virtual u32 SetTvDisplayratioReq( IN CONST nv::TS32 &tScreentype, IN CONST nv::TS32 &tDisplayratio ) = 0;
	virtual u32 SetUsbLabelCmd(  ) = 0;
	virtual u32 SetTvSignalCmd( IN CONST nv::TS32 &tScreentype, IN CONST nv::TBOOL32 &tbOpen ) = 0;
	virtual u32 NvcSetTurnOffCmd( IN CONST nv::TBOOL32 &tbTurnOff ) = 0;
	virtual u32 StartShutdownCountReq(  ) = 0;
	virtual u32 AutoShutdownCmd(  ) = 0;
	virtual u32 SetSwbStateCmd( IN CONST nv::TS32 &tState) = 0;
public:

};

#endif // _I_NVDEVICECTRL_H_
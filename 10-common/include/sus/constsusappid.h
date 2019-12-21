
/*****************************************************************************
   模块名      : SUS
   文件名      : constsusappid.h
   相关文件    : 
   文件实现功能: SUS的APP ID定义
   作者        : 
   版本        : V1.0  Copyright(C) 2006-2007 KDC, All rights reserved.
-----------------------------------------------------------------------------
   修改记录:
   日  期      版本        修改人        修改内容
   2014/04/29  1.0                       创建
******************************************************************************/
#ifndef _CONST_SUS_APP_ID_H_
#define _CONST_SUS_APP_ID_H_

#include "kdvdef.h"

#define	  AID_DEV_CONSUS				(AID_CONNSUS_BGN)
#define   AID_SUC_CONMGRSSN				(AID_SUC_BGN)

#define   AID_SUSSRV_DEVSSN             (AID_SUS_BGN)		// SusSrv的dev会话应用
#define   AID_SUSSRV_CONMGRSSN          (AID_SUS_BGN+1)		// SusSrv的ConMgr会话应用
#define   AID_SUSSRV_CONNECTSA          (AID_SUS_BGN+2)		// SusSrv的ConSA会话
#define   AID_SUSSRV_CENTERCTRL         (AID_SUS_BGN+3)		// SusSrv的主控应用


#define   AID_SUSMGR_SRVSSN             (AID_SUS_BGN+4)		// SusMgr的SusSrv会话应用
#define   AID_SUSMGR_CONNECTSA          (AID_SUS_BGN+5)		// SusMgr的ConSA会话
#define   AID_SUSMGR_CENTERCTRL         (AID_SUS_BGN+6)		// SusMgr的主控应用


#endif	// _CONST_SUS_APP_ID_H_
// END FILE





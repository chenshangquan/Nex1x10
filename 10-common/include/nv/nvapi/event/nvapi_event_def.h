/*******************************************************************************//**
*@file          nvapi_event_def.h
*@brief         实现NVAPI给UI(观察者)的事件通知的分段定义
*
*@author        ruiyigen
*@version       5.0    
*@date          20150328
*@copyright     (c)1995-2015 Suzhou Keda Technology Co.,Ltd. All rights reserved
***********************************************************************************/
#ifndef _NVAPI_EVENT_DEF_H_
#define _NVAPI_EVENT_DEF_H_
/**@addtogroup event 事件
*@{
*/

/**@addtogroup defevent 事件ID范围定义
*@{
*/

#include "kdvtype.h"

/**NVAPI 给UI事件定义的起始值*/
#define EV_NVAPI_EVENT_BGN  1024

/**BaseSdk 基础BaseSdk*/
enum EmNvApiEvSeg
{
/**BaseSdk 基础BaseSdk*/
EVSEG_NVAPI_BASE_BGN          =  EV_NVAPI_EVENT_BGN,
EVSEG_NVAPI_BASE_END          = (EVSEG_NVAPI_BASE_BGN + 1000),

/**VideoConfSdk 会议控制*/
EVSEG_NVAPI_VC_BGN,
EVSEG_NVAPI_VC_END            = (EVSEG_NVAPI_VC_BGN + 1000),


/**nvvncsdk 桌面共享*/
EVSEG_NVAPI_VNC_BGN,
EVSEG_NVAPI_VNC_END           = (EVSEG_NVAPI_VNC_BGN + 1000),


/**nvmeetingmgrsdk 会议日程*/
EVSEG_NVAPI_MG_BGN,
EVSEG_NVAPI_MG_END            = (EVSEG_NVAPI_MG_BGN + 1000),

/**nvimsdk 即时聊天*/
EVSEG_NVAPI_IM_BGN,
EVSEG_NVAPI_IM_END            = (EVSEG_NVAPI_IM_BGN + 1000),

/**nvcontactmgrsdk 联系人管理*/
EVSEG_NVAPI_CM_BGN,
EVSEG_NVAPI_CM_END            = (EVSEG_NVAPI_CM_BGN + 1000),

/**nvdiagnosesdk 诊断*/
EVSEG_NVAPI_DIAGNOSE_BGN,
EVSEG_NVAPI_DIAGNOSE_END      = (EVSEG_NVAPI_DIAGNOSE_BGN + 1000),

/**quickshare sdk*/
EVSEG_NVAPI_QUICKSHARE_BGN,
EVSEG_NVAPI_QUICKSHARE_END      = (EVSEG_NVAPI_QUICKSHARE_BGN + 1000),
};

#define EV_UI_BGN(SEG) EV_##SEG##_BGN
#define EV_UI_END(SEG) EV_##SEG##_END

/**@}*/

/**@}*/
#endif //_NVAPI_EVENT_DEF_H_


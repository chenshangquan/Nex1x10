/*******************************************************************************//**
*@file          mtapi_event_def.h
*@brief         实现MTAPI给UI(观察者)的事件通知的分段定义
*
*@author        ruiyigen
*@version       5.0    
*@date          20150328
*@copyright     (c)1995-2015 Suzhou Keda Technology Co.,Ltd. All rights reserved
***********************************************************************************/
#ifndef _MTAPI_EVENT_DEF_H_
#define _MTAPI_EVENT_DEF_H_
/**@addtogroup event 事件
*@{
*/

/**@addtogroup defevent 事件ID范围定义
*@{
*/

#include "kdvtype.h"

/**MTAPI 给UI事件定义的起始值*/
#define EV_MTAPI_EVENT_BGN  1024

/**BaseSdk 基础BaseSdk*/
enum EmMtApiEvSeg
{
/**BaseSdk 基础BaseSdk*/
EVSEG_MTAPI_BASE_BGN          =  EV_MTAPI_EVENT_BGN,
EVSEG_MTAPI_BASE_END          = (EVSEG_MTAPI_BASE_BGN + 1000),

/**VideoConfSdk 会议控制*/
EVSEG_MTAPI_VC_BGN,
EVSEG_MTAPI_VC_END            = (EVSEG_MTAPI_VC_BGN + 1000),


/**mtvncsdk 桌面共享*/
EVSEG_MTAPI_VNC_BGN,
EVSEG_MTAPI_VNC_END           = (EVSEG_MTAPI_VNC_BGN + 1000),


/**mtmeetingmgrsdk 会议日程*/
EVSEG_MTAPI_MG_BGN,
EVSEG_MTAPI_MG_END            = (EVSEG_MTAPI_MG_BGN + 1000),

/**mtimsdk 即时聊天*/
EVSEG_MTAPI_IM_BGN,
EVSEG_MTAPI_IM_END            = (EVSEG_MTAPI_IM_BGN + 1000),

/**mtcontactmgrsdk 联系人管理*/
EVSEG_MTAPI_CM_BGN,
EVSEG_MTAPI_CM_END            = (EVSEG_MTAPI_CM_BGN + 1000),

/**mtdiagnosesdk 诊断*/
EVSEG_MTAPI_DIAGNOSE_BGN,
EVSEG_MTAPI_DIAGNOSE_END      = (EVSEG_MTAPI_DIAGNOSE_BGN + 1000),
EVSEG_MTAPI_DCS_BGN,
EVSEG_MTAPI_DCS_END            = (EVSEG_MTAPI_DCS_BGN + 1000)
};

#define EV_UI_BGN(SEG) EV_##SEG##_BGN
#define EV_UI_END(SEG) EV_##SEG##_END

/**@}*/

/**@}*/
#endif //_MTAPI_EVENT_DEF_H_


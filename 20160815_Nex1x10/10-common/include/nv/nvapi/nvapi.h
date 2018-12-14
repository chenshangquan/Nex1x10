/*******************************************************************************//**
*@file          nvapi.h
*@brief         提供nvapi对外的API接口
*
*@author        ruiyigen
*@version       5.0    
*@date          20150328
*@copyright     (c)1995-2015 Suzhou Keda Technology Co.,Ltd. All rights reserved
***********************************************************************************/
#ifndef _NVAPI_H_
#define _NVAPI_H_

/*!\mainpage 概述

 *nvsdk封装了终端功能，并为开发者提供了使用终端功能的API接口。

 *基于nvsdk，开发者可以开发一款自己的终端软件或者终端控制软件。


 *nvsdk的API接口按功能被组织到8个不同的模块中。

 *- @ref baseapi "nvbaseapi"：基础API模块，包括以下功能接口：网管、配置、用户账号管理、业务启停控制等。这个模块是必选的。

 *- @ref vcapi "nvvideoconfapi"：会议API模块，包括以下功能接口：呼叫、收发双流、会议控制、本地远端摄像头控制、快照、vrs点播等。这个模块是可选的。

 *- @ref imapi "nvimapi"：聊天API模块，包括以下功能接口：即时聊天、文件传输、讨论组等。这个模块式可选的。

 *- @ref cmapi "nvcontactmgrapi"：联系人API模块，包括以下功能接口：本地地址簿、云端共享地址簿、通话记录、组织架构等。这个模块是可选的。

 *- @ref dgapi "nvdiagnoseapi"：诊断API模块，包括以下功能接口：编解码统计获取、外设信息获取、终端信息获取、日志导出、抓包导出等。这个模块是可选的。

 *- @ref mgapi "nvmeetingmgrapi"：会管API模块，包括以下功能接口：增/删/改/获取个人模板，获取公共模板，获取推送的消息等。这个模块是可选的。

 *- @ref vncapi "nvvncapi"：客户端双流API模块，用于发送PC双流。这个模块是可选的。

 *- @ref kernelapi "nvkernelapi"：终端内核API模块，用于启动终端内核。当开发终端的时候这个模块是必需的，如果开发的是终端控制软件，则不需要使用该模块。
 */

/** @page getstart 从这里开始
 *  Text of the first section
 */


/**@addtogroup common 公用
*@{
*/

/**@addtogroup other 其他
*@{
*/

#include "kdvtype.h"

#include "nvapi_export.h"
#include "nvapi_typedef.h"
#include "nvapi_enum.h"
#include "nvapi_struct.h"
#include "nvapi_baseapi.h"
#include "nvapi_event_base.h"
#include "nvapi_vcapi.h"
#include "nvapi_event_vc.h"
#include "nvapi_cmapi.h"
#include "nvapi_event_cm.h"
#include "nvapi_imapi.h"
#include "nvapi_event_im.h"
#include "nvapi_mgapi.h"
#include "nvapi_event_mg.h"
#include "nvapi_vncapi.h"
#include "nvapi_event_vnc.h"
#include "nvapi_diagnoseapi.h"
#include "nvapi_event_diagnose.h"

/**@}*/

/**@}*/
#endif //_NVAPI_H_
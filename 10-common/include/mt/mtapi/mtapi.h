/*******************************************************************************//**
*@file          mtapi.h
*@brief         提供mtapi对外的API接口
*
*@author        ruiyigen
*@version       5.0    
*@date          20150328
*@copyright     (c)1995-2015 Suzhou Keda Technology Co.,Ltd. All rights reserved
***********************************************************************************/
#ifndef _MTAPI_H_
#define _MTAPI_H_

/*!\mainpage 概述

 *mtsdk封装了终端功能，并为开发者提供了使用终端功能的API接口。

 *基于mtsdk，开发者可以开发一款自己的终端软件或者终端控制软件。


 *mtsdk的API接口按功能被组织到8个不同的模块中。

 *- @ref baseapi "mtbaseapi"：基础API模块，包括以下功能接口：网管、配置、用户账号管理、业务启停控制等。这个模块是必选的。

 *- @ref vcapi "mtvideoconfapi"：会议API模块，包括以下功能接口：呼叫、收发双流、会议控制、本地远端摄像头控制、快照、vrs点播等。这个模块是可选的。

 *- @ref imapi "mtimapi"：聊天API模块，包括以下功能接口：即时聊天、文件传输、讨论组等。这个模块式可选的。

 *- @ref cmapi "mtcontactmgrapi"：联系人API模块，包括以下功能接口：本地地址簿、云端共享地址簿、通话记录、组织架构等。这个模块是可选的。

 *- @ref dgapi "mtdiagnoseapi"：诊断API模块，包括以下功能接口：编解码统计获取、外设信息获取、终端信息获取、日志导出、抓包导出等。这个模块是可选的。

 *- @ref mgapi "mtmeetingmgrapi"：会管API模块，包括以下功能接口：增/删/改/获取个人模板，获取公共模板，获取推送的消息等。这个模块是可选的。

 *- @ref vncapi "mtvncapi"：客户端双流API模块，用于发送PC双流。这个模块是可选的。

 *- @ref kernelapi "mtkernelapi"：终端内核API模块，用于启动终端内核。当开发终端的时候这个模块是必需的，如果开发的是终端控制软件，则不需要使用该模块。
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

#include "mtapi_export.h"
#include "mtapi_typedef.h"
#include "mtapi_enum.h"
#include "mtapi_struct.h"
#include "mtapi_baseapi.h"
#include "mtapi_event_base.h"
#include "mtapi_vcapi.h"
#include "mtapi_event_vc.h"
#include "mtapi_cmapi.h"
#include "mtapi_event_cm.h"
#include "mtapi_imapi.h"
#include "mtapi_event_im.h"
#include "mtapi_mgapi.h"
#include "mtapi_event_mg.h"
#include "mtapi_vncapi.h"
#include "mtapi_event_vnc.h"
#include "mtapi_diagnoseapi.h"
#include "mtapi_event_diagnose.h"

/**@}*/

/**@}*/
#endif //_MTAPI_H_
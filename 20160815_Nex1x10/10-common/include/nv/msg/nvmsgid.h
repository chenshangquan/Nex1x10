#ifndef _NVMSGID_H_
#define _NVMSGID_H_

#include "kdvtype.h"

//使用protocol buffer编码的消息，消息id与消息体编码在一块buffer中，对应CNvMsg，当使用OSP传送CNvMsg编码的buffer时，OspPost接口的event参数必须设置为Ev_NvOsp_ProtoBufMsg。
#define EV_NV_PBMSG_BGN 1000
enum EmNvProtoBufEvSegs
{
//系统控制消息段
EVSEG_SYSCTRL_BGN          = (EV_NV_PBMSG_BGN),
EVSEG_SYSCTRL_END          = (EVSEG_SYSCTRL_BGN + 100),

//设备控制消息段
EVSEG_DEVICE_BGN,
EVSEG_DEVICE_END           = (EVSEG_DEVICE_BGN + 500),

//系统升级消息段
EVSEG_UPGRADE_BGN,
EVSEG_UPGRADE_END          = (EVSEG_UPGRADE_BGN + 200),

//网络管理消息段
EVSEG_NETWORK_BGN,
EVSEG_NETWORK_END          = (EVSEG_NETWORK_BGN + 200),

//服务器登录消息段
EVSEG_LOGSERVER_BGN,
EVSEG_LOGSERVER_END        = (EVSEG_LOGSERVER_BGN + 200),

//MP各平台通用消息段
EVSEG_MPCOMMON_BGN,
EVSEG_MPCOMMON_END         = (EVSEG_MPCOMMON_BGN + 200),

//MP 硬终端平台(linux,android)消息段
EVSEG_MPEMBED_BGN,
EVSEG_MPEMBED_END          = (EVSEG_MPEMBED_BGN + 300),

//配置消息段（与Key对应）
EVSEG_CONFIG_BGN,
EVSEG_CONFIG_END        = (EVSEG_CONFIG_BGN + 2000),

//扩展配置消息段（包含一个/多个/部分配置）
EVSEG_CONFIG_EX_BGN,
EVSEG_CONFIG_EX_END     = (EVSEG_CONFIG_EX_BGN + 200),

//消息分发模块消息段
EVSEG_DISPATCH_BGN,
EVSEG_DISPATCH_END         = (EVSEG_DISPATCH_BGN + 100),

//终端客户端接入模块消息段
EVSEG_ACCESS_BGN,
EVSEG_ACCESS_END           = (EVSEG_ACCESS_BGN + 200),

//X500终端接入模块消息段
EVSEG_TERINTERFACE_BGN,
EVSEG_TERINTERFACE_END           = (EVSEG_TERINTERFACE_BGN + 200),

//系统升级服务器消息段
EVSEG_UPGRADESERVER_BGN,
EVSEG_UPGRADESERVER_END          = (EVSEG_UPGRADESERVER_BGN + 200),
//////////////////////////////////////////////////////////////////////////
// ————————————————华丽分割线————————————————//
//																	    //
//     以下是BLL消息段。用于sdk与nvservice间通讯，无关消息不得乱入         //
//////////////////////////////////////////////////////////////////////////
#define EV_NV_BLLPBMSG_BGN 0x00070000

//BLL系统控制消息段
EVSEG_BLL_SYSCTRL_BGN          = (EV_NV_BLLPBMSG_BGN),
EVSEG_BLL_SYSCTRL_END          = (EVSEG_BLL_SYSCTRL_BGN + 100),


//BLL设备控制消息段
EVSEG_BLL_DEVICE_BGN,
EVSEG_BLL_DEVICE_END           = (EVSEG_BLL_DEVICE_BGN + 500),

//BLL系统升级消息段
EVSEG_BLL_UPGRADE_BGN,
EVSEG_BLL_UPGRADE_END          = (EVSEG_BLL_UPGRADE_BGN + 200),

//BLL网络管理消息段
EVSEG_BLL_NETWORK_BGN,
EVSEG_BLL_NETWORK_END          = (EVSEG_BLL_NETWORK_BGN + 200),

//BLL服务器登录消息段
EVSEG_BLL_LOGSERVER_BGN,
EVSEG_BLL_LOGSERVER_END        = (EVSEG_BLL_LOGSERVER_BGN + 200),

//BLLMP各平台通用消息段
EVSEG_BLL_MPCOMMON_BGN,
EVSEG_BLL_MPCOMMON_END         = (EVSEG_BLL_MPCOMMON_BGN + 200),

//BLL MP 硬终端平台(linux,android)消息段
EVSEG_BLL_MPEMBED_BGN,
EVSEG_BLL_MPEMBED_END          = (EVSEG_BLL_MPEMBED_BGN + 300),

//BLL配置消息段（与Key对应）
EVSEG_BLL_CONFIG_BGN,
EVSEG_BLL_CONFIG_END        = (EVSEG_BLL_CONFIG_BGN + 2000),

//BLL 扩展配置消息段（包含一个/多个/部分配置）
EVSEG_BLL_CONFIG_EX_BGN,
EVSEG_BLL_CONFIG_EX_END     = (EVSEG_BLL_CONFIG_EX_BGN + 200),

//BLL终端客户端接入模块消息段
EVSEG_BLL_ACCESS_BGN,
EVSEG_BLL_ACCESS_END           = (EVSEG_BLL_ACCESS_BGN + 200),

//BLL misc消息段
EVSEG_BLL_MISC_BGN,
EVSEG_BLL_MISC_END             = (EVSEG_BLL_MISC_BGN + 500),


//BLL会议消息段
EVSEG_BLL_CONF_BGN,
EVSEG_BLL_CONF_END             = (EVSEG_BLL_CONF_BGN + 1000),

//BLL X500终端接入模块消息段
EVSEG_BLL_TERINTERFACE_BGN,
EVSEG_BLL_TERINTERFACE_END           = (EVSEG_BLL_TERINTERFACE_BGN + 200),

//BLL系统升级服务器消息段
EVSEG_BLL_UPGRADESERVER_BGN,
EVSEG_BLL_UPGRADESERVER_END          = (EVSEG_BLL_UPGRADESERVER_BGN + 200),
};

#define EV_BGN(SEG) EV_##SEG##_BGN
#define EV_END(SEG) EV_##SEG##_END

#define EV_BLL_BGN(SEG) EV_##SEG##_BLL_BGN
#define EV_BLL_END(SEG) EV_##SEG##_BLL_END


#if !defined(_MESSAGE_HELP_)
#define MESSAGE(m) m,
#define BODY(T, dscrpt)  //T:消息体类型 dscrpt:消息体描述
#endif

#endif
/*******************************************************************************//**
*@file          nvapi_baseapi.h
*@brief         提供nvbaseapi对外接口
*
*@author        ruiyigen
*@version       5.0    
*@date          20150328
*@copyright     (c)1995-2015 Suzhou Keda Technology Co.,Ltd. All rights reserved
***********************************************************************************/
#ifndef _NVAPI_BASEAPI_H_
#define _NVAPI_BASEAPI_H_
/**@addtogroup api API接口
*@{
*/

/**@addtogroup baseapi 基础API
*@{
*/

#include <string.h>
#include "nvapi_export.h"
#include "nvapi_typedef.h"
#include "nvapi_struct.h"
#include "nvstruct.pb.h"


/*******************************************************************************//**
*@brief         nvbaseapi是否进行过初始化
*
*
*@author        ruiyigen   
*@date          20150328
*@param         void
*@return        BOOL32  TRUE ： 已初始化， FALSE：尚未初始化
*@note          KdvNv_BSInitalize, KdvNv_BSUnInitalize
***********************************************************************************/
KdvNvAPI BOOL32 KdvNvCALL KdvNv_BSIsInited(); 

/*******************************************************************************//**
*@brief         nvbaseapi模块初始化（这个的调用要在nvbaseapi调用的setnotify之后）
*
*
*@author        ruiyigen   
*@date          20150328
*@param[in]     nv::TNVApiStartInfo: api启动信息
*@return        u32  0: 初始化成功， 非0: 初始化失败
*@note          KdvNv_BSIsInited, KdvNv_BSUnInitalize
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_BSInitalize( IN CONST nv::TNVApiStartInfo &tApiStartInfo,IN CONST BOOL32 bInitLog = FALSE, IN CONST u32 dwLogPort = 10000 );

/*******************************************************************************//**
*@brief         nvbaseapi模块释放退出
*
*
*@author        ruiyigen   
*@date          20150328
*@param[in]     void
*@return	    u32  0: 成功， 非0: 失败
*@note          KdvNv_BSIsInited,KdvNv_BSInitalize
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_BSUnInitalize();

/*******************************************************************************//**
*@brief         创建一个终端会话实例
*
*
*@author        ruiyigen   
*@date          20150328
*@param[out]    dwSSID			 返回创建的会话ID
*@param[in]     tConnectInfo     连接终端信息 
*@return	    u32  0: 创建成功， 非0: 创建失败
*@note          KdvNv_DestorySession
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_CreateSession( OUT SessionID& dwSSID, IN CONST nv::TNVUserConnectInfo &tConnectInfo );
/*******************************************************************************//**
*@brief         通过SessionID释放一个已创建的Session
*
*
*@author        ruiyigen   
*@date          20150328
*@param[in]     SessionID  会话ID
*@return        u32   返回释放结果
*@note          KdvNv_CreateSession
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_DestorySession( IN CONST SessionID dwSSID = KNVAPI_DEF_SSID ); 

/*******************************************************************************//**
*@brief         注册Observer(UI)通知回调(回调函数中响应消息处要与回调函数同步)
*               (这个函数如果没有调用则使用nvbaseapi中的回调函数)
*(注意：回调上去的参数不允许改变其值) 
*
*@author        ruiyigen   
*@date          20150328
*@param[in]     cbNotify  要注册的回调函数
*@return        void
*@note          
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_BSSetNotify( IN NOTIFY_NV_OBSERVER_CALLBACK cbNotify );

/*******************************************************************************//**
*@brief         通过终端IP查找已创建的Session
*
*
*@author        ruiyigen   
*@date          20150328
*@param[in]     tNvIp  要查找的终端IP
*@return        SessionID  返回对应的SessionID, 不存在为INVALID_SESSIONID
***********************************************************************************/
KdvNvAPI SessionID KdvNvCALL KdvNv_GetSessionByIp( IN CONST nv::TString &tNvIp );

/*******************************************************************************//**
*@brief         通过索引查找对应的SessionID
*
*
*@author        ruiyigen   
*@date          20150328
*@param[in]     dwIdx  会话列表索引
*@return        SessionID  返回对应的SessionID, 不存在为KNVAPI_INVALID_SESSIONID
***********************************************************************************/
KdvNvAPI SessionID KdvNvCALL KdvNv_GetSessionByIdx( IN CONST u32 dwIdx );

/*******************************************************************************//**
*@brief         获取最大支持的会话数量
*
*
*@author        ruiyigen   
*@date          20150328
*@param[in]     void
*@return        u16   返回最大支持的session数量
***********************************************************************************/
KdvNvAPI u16 KdvNvCALL KdvNv_GetMaxSessionCnt();

/*******************************************************************************//**
*@brief         获取已经存在的会话数量
*
*
*@author        ruiyigen   
*@date          20150328
*@param[in]     void
*@return        u16   返回已经存在的会话数量
***********************************************************************************/
KdvNvAPI u16 KdvNvCALL KdvNv_GetUsedSessionCnt();

/*******************************************************************************//**
*@brief         终端待机命令 (仅Embed)
*
*
*@author        ruiyigen   
*@date          20150328
*@param[in]     dwSSID  NV会话ID 
*@return        u32   请求命令发送结果
*@note          响应通知：Ev_NvApi_Base_CodecDspSleep_Rsp
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_NVSleepCmd( IN CONST SessionID dwSSID = KNVAPI_DEF_SSID );

/*******************************************************************************//**
*@brief         终端唤醒命令 (仅Embed)
*
*
*@author        ruiyigen   
*@date          20150328
*@param[in]     dwSSID  NV会话ID
*@return        u32   请求命令发送结果
*@note          响应通知：Ev_NvApi_Base_SleepState_Ntf
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_NVWakeupCmd( IN CONST SessionID dwSSID = KNVAPI_DEF_SSID );

/*******************************************************************************//**
*@brief         终端重启命令(仅Embed)
*
*
*@author        ruiyigen   
*@date          20150328
*@param[in]     dwSSID  NV会话ID
*@return        u32   请求命令发送结果
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_NVRebootCmd( IN CONST SessionID dwSSID = KNVAPI_DEF_SSID );

/*******************************************************************************//**
*@brief         恢复出厂命令(仅Embed)
*
*
*@author        ruiyigen   
*@date          20150328
*@param[in]     dwSSID  NV会话ID 
*@return        u32   请求命令发送结果
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_NVResetCmd( IN CONST SessionID dwSSID = KNVAPI_DEF_SSID );

/*******************************************************************************//**
*@brief         检测更新命令
*
*
*@author        ruiyigen   
*@date          20150328
*@param[in]     tInfo  NV升级检测的信息
*@param[in]     dwSSID  NV会话ID
*@return        u32   请求命令发送结果
*@note          响应通知：Ev_NvApi_Base_CheckUpgradeResult_Ntf，Ev_NvApi_Base_UpgradeVersionInfo_Ntf
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_NVCheckUpgradeCmd( IN CONST nv::TNVUpgradeClientInfo& tInfo, IN CONST SessionID dwSSID = KNVAPI_DEF_SSID );

/*******************************************************************************//**
*@brief         取消检测更新命令
*
*
*@author        ruiyigen   
*@date          20150328
*@param[in]     dwSSID  NV会话ID 
*@return        u32   请求命令发送结果
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_NvCancelUpgradeCmd( IN CONST SessionID dwSSID = KNVAPI_DEF_SSID );

/*******************************************************************************//**
*@brief         开始下载文件命令
*
*
*@author        ruiyigen   
*@date          20150328
*@param[in]     tSaveFilePath  下载存放文件路径
*@param[i]       dwVersionId 版本号
*@param[in]     dwSSID  NV会话ID
*@return        u32   请求命令发送结果
*@note          响应通知：Ev_NvApi_Base_UpgradeFileDownloadInfo_Ntf, Ev_NvApi_Base_UpgradeFileDownloadOk_Ntf
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_NVStartDownloadUpgradeFileCmd( IN CONST nv::TString &tSaveFilePath, IN CONST u32 dwVersionId = 0, IN CONST SessionID dwSSID = KNVAPI_DEF_SSID );

/*******************************************************************************//**
*@brief         取消下载文件命令
*
*
*@author        ruiyigen   
*@date          20150328
*@param[in]     dwSSID  NV会话ID 
*@return        u32   请求命令发送结果
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_NvCancelDownloadUpgradeFileCmd( IN CONST SessionID dwSSID = KNVAPI_DEF_SSID );

/*******************************************************************************//**
*@brief         开始升级命令(仅Embed)
*
*
*@author        ruiyigen   
*@date          20150328
*@param[in]     dwSSID  NV会话ID 
*@return        u32   请求命令发送结果
*@note          响应通知：Ev_NvApi_Base_UpgradeSysFileUpdateStatus_Ntf
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_NVStartUpgradeCmd( IN CONST EmNvUpgradeType_Api emUpgradeType, IN CONST SessionID dwSSID = KNVAPI_DEF_SSID );

/*******************************************************************************//**
*@brief        检查U盘升级包(仅Embed)
*
*@param[in]     tstrFilePath 升级包路径 
*@param[in]     dwSSID  NV会话ID 
*@return        u32   请求命令发送结果
*@note          响应通知：Ev_NvApi_Base_UsbUpgradeFileCheck_Rsp
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_NVUsbUpgradeFileCheckReq( IN CONST nv::TString &tstrFilePath, IN CONST SessionID dwSSID = KNVAPI_DEF_SSID );

/**
* KdvNv_UISynchronize_Cmd
* 
* @brief   界面同步命令
*
* @param    [in]   emReason     同步原因
* @param    [in]   dwSSID       NV会话ID 
* @return   u32    请求命令发送结果
*
* @note 响应通知:
*/
KdvNvAPI u32 KdvNvCALL KdvNv_UISynchronize_Cmd(IN CONST EmNvUISynchronizeReason_Api emReason /*= EmUISynchronizeReason_Api*/, IN CONST SessionID dwSSID /*= KNVAPI_DEF_SSID*/ );


/*******************************************************************************//**
*@brief         终端是否待机中(仅Embed)
*
*
*@author        ruiyigen   
*@date          20150328
*@param[out]    bSleep  BOOL32  TRUE：待机中， FALSE：非待机中
*@param[in]     dwSSID  NV会话ID 
*@return        u32  0：成功获取， 其他：错误码
*@note          更新通知：Ev_NvApi_Base_SleepState_Ntf
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_NVIsSleeped( OUT BOOL32& bSleep, IN CONST SessionID dwSSID = KNVAPI_DEF_SSID );

/*******************************************************************************//**
*@brief         获取待机倒计时剩余时间(分钟)(仅Embed)
*
*
*@author        ruiyigen   
*@date          20150328
*@param[out]    u16   剩余时间 
*@param[in]     dwSSID  NV会话ID
*@return        u32  0：成功获取， 其他：错误码
*@note          更新通知：Ev_NvApi_Base_SleepCountDown_Ntf
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_NVGetSleepRemainTime( OUT u16& wRemainTime, IN CONST SessionID dwSSID = KNVAPI_DEF_SSID );



/*******************************************************************************//**
*@brief         用户登录验证请求
*
*
*@author        WeiLong   
*@date          20150414
*@param[in]     tUserInfo  用户信息
*@param[in]     dwSSID  NV会话ID
*@return        u32  NV_SUCCESS:发送请求成功  其他：错误码
*@note          响应通知：Ev_NvApi_Base_NVCLogin_Rsp
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_NVLoginReq( IN CONST nv::TNVUserFullInfo& tUserInfo, IN CONST SessionID dwSSID = KNVAPI_DEF_SSID );

/*******************************************************************************//**
*@brief         用户注销命令
*
*
*@author        WeiLong   
*@date          20150414
*@param[in]     tUserName  用户名
*@param[in]     dwSSID  NV会话ID
*@return        u32  NV_SUCCESS:发送请求成功  其他：错误码
*@note          响应通知：Ev_NV_BLL_NVCLogOut_Ntf
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_NVLogoutCmd( IN CONST nv::TString& tUserName, IN CONST SessionID dwSSID = KNVAPI_DEF_SSID );

/*******************************************************************************//**
*@brief         添加终端用户请求(支持批量操作)
*
*
*@author        ruiyigen   
*@date          20150328
*@param[in]     tUserList  待处理的nv消息体
*@param[in]     dwSSID  NV会话ID
*@return        u32  NV_SUCCESS:发送请求成功  其他：错误码
*@note          响应通知：Ev_NvApi_Base_NVCAddUser_Rsp, Ev_NvApi_Base_NVCAddUser_Ntf
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_NVAddUserReq( IN CONST nv::TNVMultiUserFullInfo& tUserList, IN CONST SessionID dwSSID = KNVAPI_DEF_SSID ); 

/*******************************************************************************//**
*@brief         修改用户请求(支持批量操作)
*
*
*@author        ruiyigen   
*@date          20150328
*@param[in]     tUserList  待处理的nv消息体
*@param[in]     dwSSID  NV会话ID
*@return        u32  NV_SUCCESS:发送请求成功  其他：错误码
*@note          响应通知：Ev_NvApi_Base_NVCMUser_Rsp, Ev_NvApi_Base_NVCMUser_Ntf
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_NVModifyUserReq( IN CONST nv::TNVMultiUserFullInfo& tUserList, IN CONST SessionID dwSSID = KNVAPI_DEF_SSID );

/*******************************************************************************//**
*@brief         删除用户请求(支持批量操作)
*
*
*@author        ruiyigen   
*@date          20150328
*@param[in]     tMulUser  用户id
*@param[in]     dwSSID  NV会话ID 
*@return        u32  NV_SUCCESS:发送请求成功  其他：错误码
*@note          响应通知：Ev_NvApi_Base_NVCDUser_Rsp, Ev_NvApi_Base_NVCDUser_Ntf
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_NVDeleteUserReq( IN CONST nv::TMultiU32& tMulUser, IN CONST SessionID dwSSID = KNVAPI_DEF_SSID );

/*******************************************************************************//**
*@brief         用户信息列表请求
*
*
*@author        ruiyigen   
*@date          20150328
*@param[in]     void
*@param[out]    dwSSID  NV会话ID
*@return        u32  NV_SUCCESS:发送请求成功  其他：错误码
*@note          响应通知：Ev_NvApi_Base_NVCSUser_Rsp
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_NVGetUserListReq( IN SessionID dwSSID = KNVAPI_DEF_SSID );

/*******************************************************************************//**
*@brief         获取用户总数
*
*
*@author        ruiyigen   
*@date          20150328
*@param[out]    dwCount   用户信息
*@param[in]     dwSSID  NV会话ID
*@return        u32  0：成功获取， 其他：错误码
*@note          更新通知：Ev_NvApi_Base_NVCAddUser_Ntf, Ev_NvApi_Base_NVCDUser_Ntf, Ev_NvApi_Base_NVCSUser_Rsp
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_NVGetUserCount( OUT u32 &dwCount, IN CONST SessionID dwSSID = KNVAPI_DEF_SSID ); 

/*******************************************************************************//**
*@brief         获取指定索引的用户信息
*
*
*@author        ruiyigen   
*@date          20150328
*@param[in]     nIdx    要获取的用户索引信息
*@param[out]    tUser   用户信息
*@param[in]     dwSSID  NV会话ID
*@return        u32  0：成功获取， 其他：错误码
*@note          更新通知：Ev_NvApi_Base_NVCAddUser_Ntf, Ev_NvApi_Base_NVCMUser_Ntf, Ev_NvApi_Base_NVCDUser_Ntf, Ev_NvApi_Base_NVCSUser_Rsp
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_NVGetUserByIdx( CONST s32 nIdx, OUT nv::TNVUserFullInfo& tUser, IN CONST SessionID dwSSID = KNVAPI_DEF_SSID ); 

/*******************************************************************************//**
*@brief         获取指定用户ID的用户详细信息
*
*
*@author        ruiyigen   
*@date          20150328
*@param[in]     dwUserID    要获取的用户ID信息
*@param[out]    tUser   用户信息
*@param[in]     dwSSID  NV会话ID 
*@return        u32  0：成功获取， 其他：错误码
*@note          更新通知：Ev_NvApi_Base_NVCAddUser_Ntf, Ev_NvApi_Base_NVCMUser_Ntf, Ev_NvApi_Base_NVCDUser_Ntf, Ev_NvApi_Base_NVCSUser_Rsp
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_NVGetUserByUsrID( CONST u32 dwUserID, OUT nv::TNVUserFullInfo& tUser, IN CONST SessionID dwSSID = KNVAPI_DEF_SSID ); 

/*******************************************************************************//**
*@brief         通知正在使用的网络信息
*
*
*@author        ruiyigen   
*@date          20150328
*@param[in]     tNetUsedInfo   正在使用的网络信息
*@param[in]     dwSSID          NV会话ID 
*@return        u32  0：成功获取， 其他：错误码
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_SendUsedNetInfoNtf( IN CONST nv::TNVNetUsedInfo& tNetUsedInfo, IN CONST SessionID dwSSID = KNVAPI_DEF_SSID );

/**
*  KdvNv_SYSBindService 
* 
* @brief   绑定终端服务
* 
* @param    [in]  tMutSevsInfo       绑定终端服务信息
* @param    [in]  dwSSID             NV会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note KdvNv_SYSUnBindService
*/
KdvNvAPI u32 KdvNvCALL KdvNv_SYSBindService( IN CONST nv::TNVMutiTServiceInfo &tMutSevsInfo, IN CONST SessionID dwSSID = KNVAPI_DEF_SSID  );
/**
*  KdvNv_SYSUnBindService 
* 
* @brief   解绑终端服务
* 
* @param    [in]  tMultiAlias       解绑终端服务别名
* @param    [in]  dwSSID             NV会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note KdvNv_SYSBindService
*/
KdvNvAPI u32 KdvNvCALL KdvNv_SYSUnBindService( IN CONST nv::TMultiStr &tMultiAlias, IN CONST SessionID dwSSID = KNVAPI_DEF_SSID );
/**
*  KdvNv_SYSStartService 
* 
* @brief   开始终端服务
* 
* @param    [in]  tAlias        开始终端服务别名(用户管理：access, 网管：agent, 内置多点会议：mcservice, 其他：misc, 媒体编解码：nvmp, 平台http API：rest, 升级：upgrade, 点播：vod, 通话记录和本地地址簿：record, 聊天：im, 会议：nvpa)
* @param    [in]   dwSSID            NV会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note KdvNv_SYSStopService，结果通知Ev_NvApi_Base_SrvStartResult_Ntf
*/
KdvNvAPI u32 KdvNvCALL KdvNv_SYSStartService( IN CONST nv::TString& tAlias, IN CONST SessionID dwSSID = KNVAPI_DEF_SSID );
/**
*  KdvNv_SYSStopService 
* 
* @brief   停止终端服务
* 
* @param    [in]  tAlias,        开始终端服务别名
* @param    [in]   dwSSID            NV会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note KdvNv_SYSStartService，结果通知Ev_NvApi_Base_SrvEndtResult_Ntf
*/
KdvNvAPI u32 KdvNvCALL KdvNv_SYSStopService( IN CONST nv::TString& tAlias, IN CONST SessionID dwSSID = KNVAPI_DEF_SSID );
/**
*  KdvNv_SYSBindDefService 
* 
* @brief   绑定默认终端服务
* 
* @param    [in]   dwSSID            NV会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 
*/
KdvNvAPI u32 KdvNvCALL KdvNv_SYSBindDefService( IN CONST SessionID dwSSID = KNVAPI_DEF_SSID );
/**
*  KdvNv_SYSAddDefService 
* 
* @brief   增加默认终端服务
*
* @param    [in]   tMutSevsDefInfo            默认终端服务信息 
* @param    [in]   dwSSID                     NV会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note KdvNv_SYSMdDefService KdvNv_SYSDelDefService
*/
KdvNvAPI u32 KdvNvCALL KdvNv_SYSAddDefService( IN CONST nv::TNVMutiTServiceDefInfo &tMutSevsDefInfo, IN CONST SessionID dwSSID = KNVAPI_DEF_SSID );
/**
*  KdvNv_SYSMdDefService 
* 
* @brief   修改默认终端服务
*
* @param    [in]   tMutSevsDefInfo            默认终端服务信息 
* @param    [in]   dwSSID                     NV会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note KdvNv_SYSAddDefService KdvNv_SYSDelDefService
*/
KdvNvAPI u32 KdvNvCALL KdvNv_SYSMdDefService( IN CONST nv::TNVMutiTServiceDefInfo &tMutSevsDefInfo, IN CONST SessionID dwSSID = KNVAPI_DEF_SSID );
/**
*  KdvNv_SYSDelDefService 
* 
* @brief   删除默认终端服务
*
* @param    [in]   tAlias                默认终端服务别名
* @param    [in]   dwSSID                     NV会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note KdvNv_SYSAddDefService KdvNv_SYSMdDefService
*/
KdvNvAPI u32 KdvNvCALL KdvNv_SYSDelDefService( IN CONST nv::TString &tAlias, IN CONST SessionID dwSSID = KNVAPI_DEF_SSID );

/**
*  KdvNv_SetIsUsedFileLogon 
* 
* @brief   配置是否启用文件日志
*
* @param    [in]   bUsed       是否启用文件日志     
* @param    [in]   dwSSID                     NV会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_NvApi_Base_LogStatusCfg_Ntf
*/

KdvNvAPI u32 KdvNvCALL KdvNv_SetIsUsedFileLogon( BOOL32 bUsed, IN CONST SessionID dwSSID = KNVAPI_DEF_SSID );


/**
*  KdvNv_CFGIsUsedFileLogon 
* 
* @brief   获取是否启用文件日志
* 
* @param    [out]  bUsed       是否启用文件日志
* @param    [in]   dwSSID     NV会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_NvApi_Base_LogStatusCfg_Ntf, Ev_NvApi_Base_GetLogStatusCfg_Rsp
*/
KdvNvAPI u32 KdvNvCALL KdvNv_CFGIsUsedFileLogon( BOOL32 &bUsed, IN CONST SessionID dwSSID = KNVAPI_DEF_SSID );


/**
*  KdvNv_CFGGetTerminalNameCfgReq 
* 
* @brief    获取是否启用文件日志请求
* 
* @param    [in] dwSSID  NV会话ID 
* @return   u32  NV_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_NvApi_Base_GetLogStatusCfg_Rsp
*/
KdvNvAPI u32 KdvNvCALL KdvNv_GetIsUsedFileLogonReq( IN CONST SessionID dwSSID = KNVAPI_DEF_SSID );

/**
*  KdvNv_GetAssSndSreamStatusReq 
* 
* @brief    获取双流发送状态请求
* 
* @param    [in] dwSSID  NV会话ID 
* @return   u32  NV_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_NvApi_Base_AssSndSream_Status_Ntf
*/
KdvNvAPI u32 KdvNvCALL KdvNv_GetAssSndSreamStatusReq(  IN CONST SessionID dwSSID = KNVAPI_DEF_SSID );

/**
*  KdvNv_SetIP
* 
* @brief   配置IP
*
* @param    [in]   emNvIpType       IP类型    
* @param    [in]   pach             IP地址字符串  
* @param    [in]   dwSSID           NV会话ID 
* @return   BOOL32  1：成功设置    其他：错误码 
*
* @note 更新通知：Ev_NvApi_Base_TerIpCfg_Ntf ....
*/

KdvNvAPI BOOL32 KdvNvCALL KdvNv_SetIP( IN CONST EmNvIpType_Api emNvIpType, CONST s8 *pach ,  CONST SessionID dwSSI = KNVAPI_DEF_SSID );

/**
*  KdvNv_SetImixIP
* 
* @brief   配置IP
*  
* @param    [in]   TNVNetUsedInfo     
* @param    [in]   dwSSID           NV会话ID 
* @return   BOOL32  1：成功设置    其他：错误码 
*
* @note 更新通知： Ev_NvApi_Base_ImixIpCfg_Ntf....
*/

KdvNvAPI BOOL32 KdvNvCALL KdvNv_SetImixIP( CONST nv::TNVNetUsedInfo tNVNetInfo ,  CONST SessionID dwSSI = KNVAPI_DEF_SSID );

/**
*  KdvNv_GetIpReq 
* 
* @brief   获取IP
* @param    [in]   emNvIpType       IP类型    
* @param    [in]   dwSSID           NV会话ID 
* @return   BOOL32  1：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_NvApi_Base_GetTerIpCfg_Rsp ....
*/
KdvNvAPI BOOL32 KdvNvCALL KdvNv_GetIpReq( IN CONST EmNvIpType_Api emNvIpType, IN CONST SessionID dwSSID = KNVAPI_DEF_SSID );

/**
*  KdvNv_GetAssRcvSreamStatusReq 
* 
* @brief    获取双流接收状态请求
* 
* @param    [in] dwSSID  NV会话ID 
* @return   u32  NV_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_NvApi_Base_AssRcvSream_Status_Ntf
*/
KdvNvAPI u32 KdvNvCALL KdvNv_GetAssRcvSreamStatusReq(  IN CONST SessionID dwSSID = KNVAPI_DEF_SSID );

/**
*  KdvNv_GetCallLinkStateReq 
* 
* @brief    获取呼叫状态请求
* 
* @param    [in] dwSSID  NV会话ID 
* @return   u32  NV_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_NvApi_Base_CallLinkState_Ntf
*/
KdvNvAPI u32 KdvNvCALL KdvNv_GetCallLinkStateReq( IN CONST SessionID dwSSID = KNVAPI_DEF_SSID );

/**
*  KdvNv_GetMTCLoginStateReq
* 
* @brief    获取当前的登入终端状态请求
* 
* @param    [in] dwSSID  NV会话ID 
* @return   u32  NV_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_NvApi_Base_MTCLogin_Ntf
*/
KdvNvAPI u32 KdvNvCALL KdvNv_GetMTCLoginStateReq( IN CONST SessionID dwSSID = KNVAPI_DEF_SSID );

/**
*  KdvNv_CFGRestoreDefaultCfgInfo
* 
* @brief    恢复默认配置
* @param    [in] nv::TNVRestoreDefaultCfgInfo  NV会话ID
* @param    [in] dwSSID  NV会话ID 
* @return   u32  NV_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：
*/
KdvNvAPI u32 KdvNvCALL KdvNv_CFGRestoreDefaultCfgInfo( IN CONST  nv::TNVRestoreDefaultCfgInfo &tCfg, CONST SessionID dwSSID = KNVAPI_DEF_SSID );

/**
*  KdvNv_SetSysDataTimeReq
* 
* @brief 设置当前日期时间信息
*
* @param    [in]    nv::TNVTime       时间信息
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 响应：Ev_NVApi_SetSysDataTime_Ntf ,Ev_NVApi_SetSysDataTimeResult_Rsp
*/
KdvNvAPI u32 KdvNvCALL KdvNv_SetSysDataTimeReq( IN CONST  nv::TNVTime &tTime, CONST SessionID dwSSID = KNVAPI_DEF_SSID );


/**
*  KdvNv_GetTimeZoneReq 
* 
* @brief    获取时区请求
* 
* @param    [in] dwSSID  NV会话ID 
* @return   u32  NV_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_NvApi_Base_GetTimeZoneCfg_Rsp
*/
KdvNvAPI u32 KdvNvCALL KdvNv_GetTimeZoneReq( IN CONST SessionID dwSSID = KNVAPI_DEF_SSID );

/**
*  KdvNv_SetTimeZoneCmd 
* 
* @brief   设置时区
*
* @param    [in]   emTime       时区 
* @param    [in]   dwSSID                     NV会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_NvApi_Base_SetTimeZoneCfg_Ntf
*/

KdvNvAPI u32 KdvNvCALL KdvNv_SetTimeZoneCmd( IN CONST nv::EmNvTimeZone emTime, IN CONST SessionID dwSSID = KNVAPI_DEF_SSID );


/**
*  KdvNv_NVViewPicCmd 
* 
* @brief   切换画面命令
*
* @param    [in]   tPic       画面内容
* @param    [in]   dwSSID                     NV会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_NvApi_Base_ViewPic_Ntf
*/

KdvNvAPI u32 KdvNvCALL KdvNv_NVViewPicCmd( IN CONST nv::TS32& tPic, IN CONST SessionID dwSSID = KNVAPI_DEF_SSID );

/**
*  KdvNv_NVGetPicReq 
* 
* @brief   获取画面命令
*
* @param    [in]   dwSSID                     NV会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_NvApi_Base_GetPic_Rsp
*/

KdvNvAPI u32 KdvNvCALL KdvNv_NVGetPicReq(  IN CONST SessionID dwSSID = KNVAPI_DEF_SSID );


/**
*  KdvNv_SetScreenCfgCmd 
* 
* @brief   设置显示器配置
*
* @param    [in]   tScreen       显示器参数
* @param    [in]   dwSSID                     NV会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_NvApi_Base_SetScreenCfg_Ntf
*/

KdvNvAPI u32 KdvNvCALL KdvNv_SetScreenCfgCmd( IN CONST nv::TNVScreenParamList &tScreen, IN CONST SessionID dwSSID = KNVAPI_DEF_SSID );


/**
*  KdvNv_GetScreenCfgReq 
* 
* @brief    获取显示器参数请求
* 
* @param    [in] dwSSID  NV会话ID 
* @return   u32  NV_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_NvApi_Base_GetScreenCfg_Rsp
*/
KdvNvAPI u32 KdvNvCALL KdvNv_GetScreenCfgReq( IN CONST SessionID dwSSID = KNVAPI_DEF_SSID );


/**
*  KdvNv_NvQuickShareSendPCNameCmd 
* 
* @brief    发送计算机名称
* @param    [in] pach  计算机名称
* @param    [in] dwSSID  NV会话ID 
* @return   u32  NV_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_NvApi_Base_SendPCName_Ntf
*/
KdvNvAPI u32 KdvNvCALL KdvNv_NvQuickShareSendPCNameCmd(IN CONST s8 *pach, IN CONST s8 *pVision, IN CONST SessionID dwSSID);

/**
*  KdvNv_NvSendInputEventCmd 
* 
* @brief    发送触控信息
* @param    [in]   pach  计算机名称
* @param    [in] dwSSID  NV会话ID 
* @return   u32  NV_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_NvApi_Base_SendInputEvent_Ntf
*/
KdvNvAPI u32 KdvNvCALL KdvNv_NvSendInputEventCmd(IN CONST nv::TNVInputEvents &tInput, IN CONST SessionID dwSSID);

/**
*  KdvNv_NvSendDualAddrCmd 
* 
* @brief    发送
* @param    [in] tVidAddr  视频地址
* @param    [in] tAudAddr  音频地址
* @param    [in] dwSSID    NV会话ID 
* @return   u32  NV_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_NvApi_Base_SendQuickShareSendAddr_Ntf
*/
KdvNvAPI u32 KdvNvCALL KdvNv_NvSendQuickShareSendAddrCmd(IN CONST nv::TNVRtpRtcpPair &tVidAddr, IN CONST nv::TNVRtpRtcpPair &tAudAddr, IN CONST SessionID dwSSID );

/**
*  KdvNv_NvQuickShareViewPicStopCmd 
* 
* @brief    发送
* @param    [in] dwSSID    NV会话ID 
* @return   u32  NV_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_NvApi_Base_QuickShareViewPicStop_Ntf
*/
KdvNvAPI u32 KdvNvCALL KdvNv_NvQuickShareViewPicStopCmd(IN CONST SessionID dwSSID /* = KNVAPI_DEF_SSID */);

/**
*  KdvNv_NvQuickShareCheckUpgradeCmd 
* 
* @brief    发送
* @param    [in] dwSSID    NV会话ID 
* @return   u32  NV_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_NvApi_Base_UpdateSystem2QuickShare_Ntf
*/
KdvNvAPI u32 KdvNvCALL KdvNv_NvQuickShareCheckUpgradeCmd(IN CONST SessionID dwSSID /* = KNVAPI_DEF_SSID */);

/**
*  KdvNv_NvQuickShareViewPicCmd 
* 
* @brief    无线投屏主动切源
* @param    [in] dwSSID    NV会话ID 
* @return   u32  NV_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_NvApi_Base_QuickShareViewPic_Ntf
*/
KdvNvAPI u32 KdvNvCALL KdvNv_NvQuickShareViewPicCmd(IN CONST SessionID dwSSID);


/**
*  KdvNv_GetTerinfoRtReq 
* 
* @brief    获取终端版本信息
* 
* @param    [in] dwSSID  NV会话ID 
* @return   u32  NV_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_NvApi_Base_GetTerlInfoRt_Rsp
*/
KdvNvAPI u32 KdvNvCALL KdvNv_GetTerinfoRtReq( IN CONST SessionID dwSSID = KNVAPI_DEF_SSID );

/**
*  KdvNv_SetScreenNumCfgCmd 
* 
* @brief   设置显示器屏数
*
* @param    [in]   tScreen       显示器数目
* @param    [in]   dwSSID                     NV会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_NvApi_Base_SetScreenNumCfg_Ntf
*/

KdvNvAPI u32 KdvNvCALL KdvNv_SetScreenNumCfgCmd( IN CONST nv::TU32 &tScreen, IN CONST SessionID dwSSID = KNVAPI_DEF_SSID );

/**
*  KdvNv_SetBackstageUpgradeCfgCmd 
* 
* @brief   设置后台升级
*
* @param    [in]   tbCfg       是否支持后台升级
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_NvApi_Base_SetBackstageUpgradeCfg_Ntf
*/
KdvNvAPI u32 KdvNvCALL KdvNv_SetBackstageUpgradeCfgCmd( IN CONST nv::TBOOL32 &tbCfg, IN CONST SessionID dwSSID /*= DEFAULT_SSID*/ );

/**
*  KdvNv_GetScreenNumCfgReq 
* 
* @brief    获取显示器数量请求
* 
* @param    [in] dwSSID  NV会话ID 
* @return   u32  NV_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_NvApi_Base_GetScreenNumCfg_Rsp
*/
KdvNvAPI u32 KdvNvCALL KdvNv_GetScreenNumCfgReq( IN CONST SessionID dwSSID = KNVAPI_DEF_SSID );

/**
*  KdvNv_GetBackstageUpgradeCfgReq 
* 
* @brief    获取后台升级配置请求
* 
* @param    [in] dwSSID  NV会话ID 
* @return   u32  NV_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_NvApi_Base_GetBackstageUpgradeCfg_Rsp
*/
KdvNvAPI u32 KdvNvCALL KdvNv_GetBackstageUpgradeCfgReq( IN CONST SessionID dwSSID /*= KNVAPI_DEF_SSID*/ );

/**
*  KdvNv_SetTvBrightnessReq 
* 
* @brief   设置显示器亮度
*
* @param    [in]   tScreentype       显示器类型 枚举值统一使用nv::TS32来传输，该处实际为nv::EmNvScreenType
* @param    [in]   tBrightness       亮度
* @param    [in]   dwSSID                     NV会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_NvApi_Base_SetTvBrightness_Rsp
*/

KdvNvAPI u32 KdvNvCALL KdvNv_SetTvBrightnessReq( IN CONST nv::TS32 &tScreentype, IN CONST nv::TU32 &tBrightness, IN CONST SessionID dwSSID = KNVAPI_DEF_SSID );

/**
*  KdvNv_SetTvContrasteReq 
* 
* @brief   设置显示器对比度
*
* @param    [in]   tScreentype       显示器类型 枚举值统一使用nv::TS32来传输，该处实际为nv::EmNvScreenType
* @param    [in]   tContraste       对比度
* @param    [in]   dwSSID                     NV会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_NvApi_Base_SetTvContraste_Rsp
*/

KdvNvAPI u32 KdvNvCALL KdvNv_SetTvContrasteReq( IN CONST nv::TS32 &tScreentype, IN CONST nv::TU32 &tContraste, IN CONST SessionID dwSSID = KNVAPI_DEF_SSID );

/**
*  KdvNv_SetTvSaturationReq 
* 
* @brief   设置显示器饱和度
*
* @param    [in]   tScreentype       显示器类型 枚举值统一使用nv::TS32来传输，该处实际为nv::EmNvScreenType
* @param    [in]   tSaturation     饱和度
* @param    [in]   dwSSID                     NV会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_NvApi_Base_SetTvSaturation_Rsp
*/

KdvNvAPI u32 KdvNvCALL KdvNv_SetTvSaturationReq( IN CONST nv::TS32 &tScreentype, IN CONST nv::TU32 &tSaturation, IN CONST SessionID dwSSID = KNVAPI_DEF_SSID );

/**
*  KdvNv_SetTvClarityReq 
* 
* @brief   设置显示器清晰度
*
* @param    [in]   tScreentype       显示器类型 枚举值统一使用nv::TS32来传输，该处实际为nv::EmNvScreenType
* @param    [in]   tClarity       清晰度
* @param    [in]   dwSSID                     NV会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_NvApi_Base_SetTvClarity_Rsp
*/

KdvNvAPI u32 KdvNvCALL KdvNv_SetTvClarityReq( IN CONST nv::TS32 &tScreentype, IN CONST nv::TU32 &tClarity, IN CONST SessionID dwSSID = KNVAPI_DEF_SSID );



/**
*  KdvNv_SetTvColortempReq 
* 
* @brief   设置显示器色温
*
* @param    [in]   tScreentype       显示器类型 枚举值统一使用nv::TS32来传输，该处实际为nv::EmNvScreenType
* @param    [in]   tColortemp       色温 枚举值统一使用nv::TS32来传输，该处实际为nv::EmNvScreenColorTemperature
* @param    [in]   dwSSID                     NV会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_NvApi_Base_SetTvColortemp_Rsp
*/

KdvNvAPI u32 KdvNvCALL KdvNv_SetTvColortempReq( IN CONST nv::TS32 &tScreentype, IN CONST nv::TS32 &tColortemp, IN CONST SessionID dwSSID = KNVAPI_DEF_SSID );

/**
*  KdvNv_SetTvDisplayratioReq 
* 
* @brief   设置显示器显示比例
*
* @param    [in]   tScreentype       显示器类型 枚举值统一使用nv::TS32来传输，该处实际为nv::EmNvScreenType
* @param    [in]   tDisplayratio       显示比例 枚举值统一使用nv::TS32来传输，该处实际为nv::EmNvTvDisplayRatio
* @param    [in]   dwSSID                     NV会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_NvApi_Base_SetTvDisplayratio_Rsp
*/

KdvNvAPI u32 KdvNvCALL KdvNv_SetTvDisplayratioReq( IN CONST nv::TS32 &tScreentype, IN CONST nv::TS32 &tDisplayratio, IN CONST SessionID dwSSID = KNVAPI_DEF_SSID );

/**
*  KdvNv_NvGetNvmpVidSrcStatusReq 
* 
* @brief   查询视频源分辨率
* @param    [in] tbTest    是否诊断测试
* @param    [in] dwSSID    NV会话ID 
* @return   u32  NV_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_BLL_NV_NvmpVidSrcStatus_Rsp
*/
KdvNvAPI u32 KdvNvCALL KdvNv_NvGetNvmpVidSrcStatusReq(IN CONST nv::TBOOL32 tbTest, IN CONST SessionID dwSSID /* = KNVAPI_DEF_SSID */);


/**
*  KdvNv_VideoAssStreamCmd
* 
* @brief    开关双流
* 
* @param    [in] dwSSID  NV会话ID 
* @return   u32  NV_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_NV_BLL_AssSndSream_Status_Ntf
*/
KdvNvAPI u32 KdvNvCALL KdvNv_VideoAssStreamCmd( IN CONST nv::TBOOL32 tbStart, IN CONST SessionID dwSSID = KNVAPI_DEF_SSID );

/**
*  KdvNv_NvSetSharingOptionCmd
* 
* @brief    设置是否共享
* 
* @param    [in] dwSSID  NV会话ID 
* @return   u32  NV_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_NvApi_Base_SetIsSharing_Ntf
*/
KdvNvAPI u32 KdvNvCALL KdvNv_NvSetSharingOptionCmd( IN CONST nv::TBOOL32 tbcfg, IN CONST SessionID dwSSID = KNVAPI_DEF_SSID );

/**
*  KdvNv_GetCodecQuietReq 
* 
* @brief   获取静音状态
* @param    [in] dwSSID    NV会话ID 
* @return   u32  NV_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_NvApi_Base_GetIsSharing_Rsp
*/
KdvNvAPI u32 KdvNvCALL KdvNv_GetShaingOptionCfgReq(IN CONST SessionID dwSSID /* = KNVAPI_DEF_SSID */);

/**
	*  KdvNv_CodecQuietCmd
	* 
	* @brief    设置静音状态
	* @param    [in] tbQuit  TRUE 静音， FALSE非静音
	* @param    [in] dwSSID  NV会话ID 
	* @return   u32  NV_SUCCESS:发送请求成功  其他：错误码
	*
	* @note 响应通知：Ev_NvApi_Base_CodecQuiet_Rsp
	*/
KdvNvAPI u32 KdvNvCALL KdvNv_CodecQuietCmd(IN CONST nv::TBOOL32 tbQuit, IN CONST SessionID dwSSID = KNVAPI_DEF_SSID );


/**
*  KdvNv_GetCodecQuietReq 
* 
* @brief   获取静音状态
* @param    [in] dwSSID    NV会话ID 
* @return   u32  NV_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_NvApi_Base_CodecQuiet_Rsp
*/
KdvNvAPI u32 KdvNvCALL KdvNv_GetCodecQuietReq(IN CONST SessionID dwSSID /* = KNVAPI_DEF_SSID */);


/**
	*  KdvNv_CodecSetAudOutVolCmd
	* 
	* @brief    设置输出音量
	* @param    [in] tVol  音量
	* @param    [in] dwSSID  NV会话ID 
	* @return   u32  NV_SUCCESS:发送请求成功  其他：错误码
	*
	* @note 响应通知：Ev_NvApi_Base_CodecAudOutVol_Ntf
	*/
KdvNvAPI u32 KdvNvCALL KdvNv_CodecSetAudOutVolCmd(IN CONST nv::TU32 tVol, IN CONST SessionID dwSSID = KNVAPI_DEF_SSID );


/**
*  KdvNv_CodecGetAudOutVolReq 
* 
* @brief   获取输出音量
* @param    [in] dwSSID    NV会话ID 
* @return   u32  NV_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_NvApi_Base_CodecGetAudOutVol_Rsp
*/
KdvNvAPI u32 KdvNvCALL KdvNv_CodecGetAudOutVolReq(IN CONST SessionID dwSSID /* = KNVAPI_DEF_SSID */);


/**
*  KdvNv_GetImixVidSrcSignalRtReq 
* 
* @brief    获取视频信号请求
* 
* @param    [in] dwSSID  NV会话ID 
* @return   u32  NV_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_NV_BLL_GetImixVidSrcSignalRt_Rsp
*/
KdvNvAPI u32 KdvNvCALL KdvNv_GetImixVidSrcSignalRtReq( IN CONST SessionID dwSSID /*= KNVAPI_DEF_SSID*/ );

/**
*  KdvNv_NvSetFullScreenCmd 
* 
* @brief   设置全屏
* @param    [in] tbFull    TRUE 开 FALSE 关
* @param    [in] dwSSID    NV会话ID 
* @return   u32  NV_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_NvApi_Base_SetFullScreenCmd_Ntf
*/
KdvNvAPI u32 KdvNvCALL KdvNv_NvSetFullScreenCmd(IN CONST nv::TBOOL32 tbFull, IN CONST SessionID dwSSID /* = KNVAPI_DEF_SSID */);

/**
*  KdvNv_NvGetFullScreenReq 
* 
* @brief   获取全屏设置请求
* @param    [in] dwSSID    NV会话ID 
* @return   u32  NV_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_NvApi_Base_GetFullScreen_Rsp
*/
KdvNvAPI u32 KdvNvCALL KdvNv_NvGetFullScreenReq(IN CONST SessionID dwSSID /* = KNVAPI_DEF_SSID */);

/**
*  KdvNv_CodecSnapshotReq 
* 
* @brief   快照请求
* @param    [in] tSnapName    快照全路径名
* @param    [in] tCodeId   视频解码器编号
* @param    [in] dwSSID    NV会话ID 
* @return   u32  NV_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_NvApi_Base_CodecSnapshot_Rsp
*/
KdvNvAPI u32 KdvNvCALL KdvNv_CodecSnapshotReq(IN CONST nv::TString tSnapName, IN CONST nv::TS32 tCodeId, IN CONST SessionID dwSSID /* = KNVAPI_DEF_SSID */);


/*******************************************************************************//**
*@brief         是否关机回复
* KdvNv_NvTurnOffReq
*
* @param    [in] tbTurnOff   TRUE关机，FALSE 不关机
*@param[in]     dwSSID  NV会话ID 
*@return        u32  0：成功获取， 其他：错误码
*@note          更新通知：Ev_NvApi_Base_PowerTurnOff_Rsp
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_NvTurnOffReq( IN CONST nv::TBOOL32 tbTurnOff, IN CONST SessionID dwSSID = KNVAPI_DEF_SSID );

/*******************************************************************************//**
*@brief         获取音频输入信号
*
*@param[in]     dwSSID  NV会话ID 
*@return        u32  0：成功获取， 其他：错误码
*@note          更新通知：Ev_NvApi_Base_CodecGetAllAudInPower_Ntf
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_CodecGetAllAudInPowerCmd( IN CONST SessionID dwSSID = KNVAPI_DEF_SSID );

/*******************************************************************************//**
*@brief         播放铃声
*
* @param    [in] tbPlay   TRUE播放，FALSE关闭
*@param[in]     dwSSID  NV会话ID 
*@return        u32  0：成功获取， 其他：错误码
*@note          更新通知：
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_CodecRingPlayCmd( IN CONST nv::TBOOL32 tbPlay, IN CONST SessionID dwSSID = KNVAPI_DEF_SSID );

/*******************************************************************************//**
*@brief         设置HDMI开关，控制数据		
*
* @param    [in] tbUp   TRUE 3798数据不经过FPGA ，FALSE 3798数据可以经过FPGA
*@param[in]     dwSSID  NV会话ID 
*@return        u32  0：成功获取， 其他：错误码
*@note          更新通知：
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_SetHdmiSwitchCmd( IN CONST nv::TBOOL32 tbUp, IN CONST BOOL32 bOnly, IN CONST SessionID dwSSID = KNVAPI_DEF_SSID );

/*******************************************************************************//**
*@brief         无线投屏发送视频源信息给imix		
*
* @param    [in] tVidInfo   源信息，包含分辨率等信息
*@param[in]     dwSSID  NV会话ID 
*@return        u32  0：成功获取， 其他：错误码
*@note          更新通知：
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_QKSendVidSrcStatusCmd( IN CONST nv::TNvVidSrcInfo tVidInfo, IN CONST SessionID dwSSID = KNVAPI_DEF_SSID );

/*******************************************************************************//**
*@brief         设置解码播放图像的显示图层
*
* @param    [in] tbMini   TRUE:最小化  FALSE：最大化 
*@param[in]     dwSSID  NV会话ID 
*@return        u32  0：成功获取， 其他：错误码
*@note          更新通知：
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_SetShowRectCmd( IN CONST nv::TBOOL32 tbMini, IN CONST SessionID dwSSID = KNVAPI_DEF_SSID );

/*******************************************************************************//**
*@brief         手动呼叫选择
*
* @param    [in] tbAnswerCall   TRUE:接听  FALSE：拒绝 
*@param[in]     dwSSID  NV会话ID 
*@return        u32  0：成功获取， 其他：错误码
*@note          更新通知：
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_AnswerCallCmd( IN CONST nv::TBOOL32 tbAnswerCall, IN CONST SessionID dwSSID  = KNVAPI_DEF_SSID  );
/*******************************************************************************//**
*@brief         呼叫应答查询
*
* @param    [in]  
*@param[in]     dwSSID  NV会话ID 
*@return        u32  0：成功获取， 其他：错误码
*@note          更新通知：
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_GetAnswerCallMode( IN CONST SessionID dwSSID = KNVAPI_DEF_SSID );
/**@}*/

/**
*  KdvNv_GetHdmiSwitchCfgReq 
* 
* @brief    获取HDMI开关状态
* 
* @param    [in] dwSSID  NV会话ID 
* @return   u32  NV_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_NvApi_Base_GetHdmiSwitchCfg_Rsp
*/
KdvNvAPI u32 KdvNvCALL KdvNv_GetHdmiSwitchCfgReq( IN CONST SessionID dwSSID /*= KNVAPI_DEF_SSID*/ );

/**
*  KdvNv_GetMtSysDataTimeReq
* 
* @brief 获取终端当前日期时间信息
*
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 响应：Ev_NvApi_Base_GetMtSysDataTime_Rsp
*/
KdvNvAPI u32 KdvNvCALL KdvNv_GetMtSysDataTimeReq( CONST SessionID dwSSID = KNVAPI_DEF_SSID );

/**
*  KdvNv_GetMtSysTimeCfgReq
* 
* @brief 获取终端当前时间配置信息
*
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 响应：Ev_NvApi_Base_GetMtSysTimeCfg_Rsp
*/
KdvNvAPI u32 KdvNvCALL KdvNv_GetMtSysTimeCfgReq( CONST SessionID dwSSID = KNVAPI_DEF_SSID );
/*******************************************************************************//**
*@brief         ping包回应
*
* @param    [in] tbResult   TRUE:成功  FALSE：失败 
*@param[in]     dwSSID  NV会话ID 
*@return        u32  0：成功获取， 其他：错误码
*@note          更新通知：
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_SetPingTestRsp( IN CONST nv::TBOOL32 tbResult, IN CONST SessionID dwSSID  /*= KNVAPI_DEF_SSID*/  );

/**
*  KdvNv_GetVidResResizeModeCfgReq 
* 
* @brief    获取非1080分辨率时显示策略
* 
* @param    [in] dwSSID  NV会话ID 
* @return   u32  NV_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_NvApi_Base_GetVidResResizeModeCfg_Rsp
*/
KdvNvAPI u32 KdvNvCALL KdvNv_GetVidResResizeModeCfgReq( IN CONST SessionID dwSSID /*= KNVAPI_DEF_SSID*/ );

/**
*  KdvNv_SetVidResResizeModeCfgCmd 
* 
* @brief   设置非1080分辨率时显示策略
*
* @param    [in]   tMode       显示模式
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_NvApi_Base_SetVidResResizeModeCfg_Ntf
*/
KdvNvAPI u32 KdvNvCALL KdvNv_SetVidResResizeModeCfgCmd( IN CONST nv::TS32 tMode, IN CONST SessionID dwSSID /*= DEFAULT_SSID*/ );

/*******************************************************************************//**
*@brief        KdvNv_SetPrompt
*
*
*@author        
*@date          
* @param    [in]   tAlias       终端提示符
* @return   u32  0：成功获取， 其他：错误码    
*@note          
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_SetPrompt( IN CONST nv::TString& tAlias ); 

/**
*  KdvNv_GetSysDataTimeReq
* 
* @brief 获取当前日期时间信息
*
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 响应：Ev_NvApi_Base_GetSysDataTime_Rsp
*/
KdvNvAPI u32 KdvNvCALL KdvNv_GetSysDataTimeReq( CONST SessionID dwSSID = KNVAPI_DEF_SSID );

/**
*  KdvNv_SetOutclrspaceCmd 
* 
* @brief   设置yuv参数
*
* @param    [in]   tnYuv       
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：
*/
KdvNvAPI u32 KdvNvCALL KdvNv_SetOutclrspaceCmd( IN CONST nv::TS32 tnYuv, IN CONST SessionID dwSSID /*= DEFAULT_SSID*/ );

/**
*  KdvNv_SetIsMtDualLeftCfgCmd 
* 
* @brief   设置双流外接源左右屏配置
*
* @param    [in]   tbCfg       TRUE：左屏，FALSE：右屏
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_NvApi_Base_SetIsMtDualLeftCfg_Ntf
*/
KdvNvAPI u32 KdvNvCALL KdvNv_SetIsMtDualLeftCfgCmd( IN CONST nv::TBOOL32 tbCfg, IN CONST SessionID dwSSID /*= DEFAULT_SSID*/ );

/**
*  KdvNv_GetIsMtDualLeftCfgReq 
* 
* @brief    获取双流外接源左右屏配置
* 
* @param    [in] dwSSID  NV会话ID 
* @return   u32  NV_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_NvApi_Base_GetIsMtDualLeftCfg_Rsp
*/
KdvNvAPI u32 KdvNvCALL KdvNv_GetIsMtDualLeftCfgReq( IN CONST SessionID dwSSID /*= KNVAPI_DEF_SSID*/ );

/**
*  KdvNv_GetMtPicReq 
* 
* @brief    获取终端主视频显示画面
* 
* @param    [in] dwSSID  NV会话ID 
* @return   u32  NV_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_NvApi_Base_GetMtPic_Rsp
*/
KdvNvAPI u32 KdvNvCALL KdvNv_GetMtPicReq( IN CONST SessionID dwSSID /*= KNVAPI_DEF_SSID*/ );

/*******************************************************************************//**
*@brief         取消检测更新命令
*
*
*@author        ruiyigen   
*@date          20150328
*@param[in]     dwSSID  NV会话ID 
*@return        u32   请求命令发送结果
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_NvUpgradeQuickShareCmd( IN CONST SessionID dwSSID = KNVAPI_DEF_SSID );

/*******************************************************************************//**
*@brief         取消检测更新命令
*
*
*@author        ruiyigen   
*@date          20150328
*@param[in]     dwSSID  NV会话ID 
*@return        u32   请求命令发送结果
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_NvGetQuickShareVersionCmd( IN CONST SessionID dwSSID = KNVAPI_DEF_SSID );

/**
*  KdvNv_SetPlayZoomModeCmd 
* 
* @brief   设置播放设备的显示比例
*
* @param    [in]   tnZoom   EmNvZoomMode    
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_NvApi_Base_CodecSetPlayZoomMode_Ntf
*/
KdvNvAPI u32 KdvNvCALL KdvNv_SetPlayZoomModeCmd( IN CONST nv::TS32 tnZoom, IN CONST SessionID dwSSID /*= DEFAULT_SSID*/ );

/*******************************************************************************//**
*@brief         取消检测更新命令
*
*
*@author        ruiyigen   
*@date          20150328
*@param[in]     dwSSID  NV会话ID 
*@return        u32   请求命令发送结果
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_NvCancelUpgradeQuickShareCmd( IN CONST SessionID dwSSID = KNVAPI_DEF_SSID );

/*******************************************************************************//**
																				 
*  KdvNv_OpenFtpCmd 
*@brief         打开ftp
*
* @param    [in] tbOpen   TRUE:打开  FALSE：关闭 
*@param[in]     dwSSID  NV会话ID 
*@return        u32  0：成功获取， 其他：错误码
*@note          更新通知：
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_OpenFtpCmd(IN CONST nv::TBOOL32 tbOpen , IN CONST SessionID dwSSID  /*= KNVAPI_DEF_SSID*/  );

/**
*  KdvNv_GetPlayZoomModeReq 
* 
* @brief   获取播放设备的显示比例
*
* @param    [in]   tnZoom   EmNvZoomMode    
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_NvApi_Base_CodecGetPlayZoomMode_Rsp
*/
KdvNvAPI u32 KdvNvCALL KdvNv_GetPlayZoomModeReq( IN CONST SessionID dwSSID /*= DEFAULT_SSID*/ );


/**
*  KdvNv_SetVidFreezePrmCmd 
* 
* @brief   设置视频画面冰冻
*
* @param    [in]   tFree   nv::TNVVidFreezePrm    
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：
*/
KdvNvAPI u32 KdvNvCALL KdvNv_SetVidFreezePrmCmd( IN CONST nv::TNVVidFreezePrm tFree, IN CONST SessionID dwSSID /*= DEFAULT_SSID*/ );

/**
*  KdvNv_GetTerminalNameReq 
* 
* @brief   查询终端名字
*
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_NvApi_Base_GetTerminalName_Rsp Ev_NvApi_Base_SetTerminalName_Ntf
*/
KdvNvAPI u32 KdvNvCALL KdvNv_GetTerminalNameReq( IN CONST SessionID dwSSID /*= DEFAULT_SSID*/ );


/**
*  KdvNv_InquireHDMtStartSucess 
* 
* @brief   查询终端程序是否全部启动成功
*
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_NvApi_Base_InquireHDMtStartSucess_Rsp Ev_NvApi_Base_HDMtStartSucess_Ntf
*/
KdvNvAPI u32 KdvNvCALL KdvNv_InquireHDMtStartSucess( IN CONST SessionID dwSSID /*= DEFAULT_SSID*/ );

/**
*  KdvNv_SendLocalSmsCmd 
* 
* @brief   网呈IMIX通过该接口给终端发短消息(限制512字节)，终端接收短消息后显示在OSD上
@param    [in]   tSms   nv::TString 本地短消息 
*
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：
*/
KdvNvAPI u32 KdvNvCALL KdvNv_SendLocalSmsCmd( IN CONST nv::TString tSms, IN CONST SessionID dwSSID /*= DEFAULT_SSID*/ );

/**
*  KdvNv_SetUsbLabelCmd 
* 
* @brief   运行usblabel脚本
@param    [in]   
*
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：
*/
KdvNvAPI u32 KdvNvCALL KdvNv_SetUsbLabelCmd( IN CONST SessionID dwSSID /*= DEFAULT_SSID*/ );

/**
*  KdvNv_SetVidMiniVidCmd 
* 
* @brief   设置小图像
*
* @param    [in]   tInfo   nv::TNVMiniVidInfo    
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_NvApi_Base_SetMiniVidInfoRt_Ntf
*/
KdvNvAPI u32 KdvNvCALL KdvNv_SetVidMiniVidCmd( IN CONST nv::TNVMiniVidInfo tInfo, IN CONST SessionID dwSSID /*= DEFAULT_SSID*/ );


/**
*  KdvNv_GetMiniVidInfoReq 
* 
* @brief   获取小图像信息
*   
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_NvApi_Base_GetMiniVidInfoRt_Rsp
*/
KdvNvAPI u32 KdvNvCALL KdvNv_GetMiniVidInfoReq( IN CONST SessionID dwSSID /*= DEFAULT_SSID*/ );

/*******************************************************************************//**
*@brief         设置Nova
*
*
*@author        ruiyigen   
*@date          20150328
*@param[in]     dwSSID  NV会话ID 
*@return        u32   请求命令发送结果
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_NvSetNovaCmd( IN CONST SessionID dwSSID = KNVAPI_DEF_SSID );

/**
*  KdvNv_GetImixVerInfoRtReq 
* 
* @brief    获取版本信息
* 
* @param    [in] dwSSID  NV会话ID 
* @return   u32  NV_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_NvApi_Base_GetImixVerInfoRt_Rsp
*/
KdvNvAPI u32 KdvNvCALL KdvNv_GetImixVerInfoRtReq( IN CONST SessionID dwSSID /*= KNVAPI_DEF_SSID*/ );

/*******************************************************************************//**
 *@brief         删除APP包
*
* 
*@date          20150328
*@param[in]     dwSSID  NV会话ID 
*@return        u32   请求命令发送结果
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_NvDelAppCmd( IN CONST SessionID dwSSID = KNVAPI_DEF_SSID );

/**
*  KdvNv_SetTerNatCmd
* 
* @brief   设置终端NAT地址
@param    [in]   tNatIP   nv::TString NatIP地址
          [in]   tEnable  nv::TBOOL32 是否启用NAT
*
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_NvApi_Base_SetTerNatIpCfg_Rsp
*/
KdvNvAPI u32 KdvNvCALL KdvNv_SetTerNatCmd( IN CONST nv::TString tNatIP, IN CONST nv::TBOOL32 tbEnable, IN CONST SessionID dwSSID /*= KNVAPI_DEF_SSID*/ );

/**
*  KdvNv_GetVidFreezePrmReq 
* 
* @brief   视频冻结状态查询
*   
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_NvApi_Base_CodecGetVidFreezePrm_Rsp
*/
KdvNvAPI u32 KdvNvCALL KdvNv_GetVidFreezePrmReq( IN CONST SessionID dwSSID /*= DEFAULT_SSID*/ );

/**
*  KdvNv_SetTvSignalCmd 
* 
* @brief   打开关闭电视机无信号
*
* @param    [in]   tScreentype       显示器类型 枚举值统一使用nv::TS32来传输，该处实际为nv::EmNvScreenType
* @param    [in]   tbOpen       打开关闭电视机无信号
* @param    [in]   dwSSID                     NV会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_NvApi_Base_SetTvSignal_Ntf
*/

KdvNvAPI u32 KdvNvCALL KdvNv_SetTvSignalCmd( IN CONST nv::TS32 &tScreentype, IN CONST nv::TBOOL32 &tbOpen, IN CONST SessionID dwSSID = KNVAPI_DEF_SSID );

/*******************************************************************************//**
 *@brief         查询版本型号
*
* 
*@date          20150328
*@param[in]     dwSSID  NV会话ID 
*@return        u32   请求命令发送结果
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_NvGetImixModeReq( IN CONST SessionID dwSSID = KNVAPI_DEF_SSID );

/*******************************************************************************//**
*@brief         APP升级状态通知
* KdvNv_NvAppUpgradeStatusNtf
*
* @param    [in] bUpgrade   TRUE升级中，FALSE 没升级
*@param[in]     dwSSID  NV会话ID 
*@return        u32  0：成功获取， 其他：错误码
*@note          更新通知：
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_NvAppUpgradeStatusNtf( IN CONST nv::TBOOL32 bUpgrade, IN CONST SessionID dwSSID = KNVAPI_DEF_SSID );


/*******************************************************************************//**
*@brief         投屏器升级状态通知
* KdvNv_NvQkUpgradeStatusNtf
*
* @param    [in] bUpgrade   TRUE升级中，FALSE 没升级
*@param[in]     dwSSID  NV会话ID 
*@return        u32  0：成功获取， 其他：错误码
*@note          更新通知：
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_NvQkUpgradeStatusNtf( IN CONST nv::TBOOL32 bUpgrade, IN CONST SessionID dwSSID = KNVAPI_DEF_SSID );

/*******************************************************************************//**
*@brief         关机
* KdvNv_NvcSetTurnOffCmd
*
* @param    [in] tbTurnOff   TRUE关机，FALSE 不关机
*@param[in]     dwSSID  NV会话ID 
*@return        u32  0：成功获取， 其他：错误码
*@note          更新通知：
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_NvcSetTurnOffCmd( IN CONST nv::TBOOL32 &tbTurnOff, IN CONST SessionID dwSSID = KNVAPI_DEF_SSID );

/**
*  KdvNv_NotifyImixNexTransmitterStateCmd 
* 
* @brief   设置播放设备的显示比例
*    
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_NvApi_Base_CodecSetPlayZoomMode_Ntf
*/
KdvNvAPI u32 KdvNvCALL KdvNv_NotifyImixNexTransmitterStateCmd( IN CONST nv::TBOOL32 tbNtState, IN CONST SessionID dwSSID /*= DEFAULT_SSID*/ );

/*******************************************************************************//**
*@brief         打印日志
*
*
*@author           
*@date          
*@param[in]     tLog   日志信息
*@param[in]     dwSSID          NV会话ID 
*@return        u32  0：成功获取， 其他：错误码
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_SetLogHintCmd( IN CONST nv::TString& tLog, IN CONST SessionID dwSSID = KNVAPI_DEF_SSID );

/*******************************************************************************//**
*@brief         通知imix u盘状态
* KdvNv_NotifyImixUDiskState
*
* @param    [in] tdwInx   0：u盘1； 1：u盘2
* @param    [in] tbState  0：无源； 1：有源
*@param[in]     dwSSID  NV会话ID 
*@return        u32  0：成功获取， 其他：错误码
*@note          更新通知：
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_NotifyImixUDiskStateNty( IN CONST nv::TU32 tdwInx, IN CONST nv::TBOOL32 tbState, IN CONST SessionID dwSSID /* = KNVAPI_DEF_SSID */);

/*******************************************************************************//**
*@brief         后台清理动态源通知imix
* KdvNv_ClearSrcTypeStateCmd
*
* @param    [in] tSrcType   动态源类型：EmNvImixVidSrcType
*@param[in]     dwSSID  NV会话ID 
*@return        u32  0：成功获取， 其他：错误码
*@note          更新通知：
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_ClearSrcTypeStateCmd( IN CONST nv::TNVClearSrcType tSrcType, IN CONST SessionID dwSSID /* = KNVAPI_DEF_SSID */);

/*******************************************************************************//**
*@brief         DLNA源状态通知imix
* KdvNv_DLNASrcStateNty
*
* @param    [in] tIsHas   0：无源 1：有源
*@param[in]     dwSSID  NV会话ID 
*@return        u32  0：成功获取， 其他：错误码
*@note          更新通知：
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_DLNASrcStateNty( IN CONST nv::TBOOL32 tIsHas, IN CONST SessionID dwSSID /* = KNVAPI_DEF_SSID */);

/*******************************************************************************//**
*@brief         设置终端自动待机
* KdvNv_SetTerAutoSleepCmd
*
* @param    [in] TNVMtAutoSleepCfg   自动待机信息
*@param[in]     dwSSID  NV会话ID 
*@return        u32  0：成功获取， 其他：错误码
*@note          更新通知：Ev_NvApi_Base_SetTerAutoSleep_Nty
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_SetTerAutoSleepCmd( IN CONST nv::TNVMtAutoSleepCfg tAutoSleep, IN CONST SessionID dwSSID /*= KNVAPI_DEF_SSID*/ );

/*******************************************************************************//**
*@brief         查询终端自动待机
* KdvNv_GetTerAutoSleepReq
*
*@param[in]     dwSSID  NV会话ID 
*@return        u32  0：成功获取， 其他：错误码
*@note          更新通知：Ev_NvApi_Base_GetTerAutoSleep_Rsp
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_GetTerAutoSleepReq(IN CONST SessionID dwSSID /*= KNVAPI_DEF_SSID*/ );

/*******************************************************************************//**
*@brief         设置fpga画线
* KdvNv_DLNASrcStateNty
*
* @param    [in] tLineInfo   画线信息
*@param[in]     dwSSID  NV会话ID 
*@return        u32  0：成功获取， 其他：错误码
*@note          更新通知：
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_SetDrawLineCmd( IN CONST nv::TNVVidLineOverlap tLineInfo, IN CONST SessionID dwSSID /* = KNVAPI_DEF_SSID */);

/*******************************************************************************//**
*@brief         qk发送pc开始PPT命令
* KdvNv_DLNASrcStateNty
*
*@param[in]     dwSSID  NV会话ID 
*@return        u32  0：成功获取， 其他：错误码
*@note          更新通知：
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_NvQuickShareSendPCStartPPTCmd( IN CONST SessionID dwSSID);

/*******************************************************************************//**
*@brief         qk发送pc结束PPT命令
* KdvNv_DLNASrcStateNty
*
*@param[in]     dwSSID  NV会话ID 
*@return        u32  0：成功获取， 其他：错误码
*@note          更新通知：
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_NvQuickShareSendPCStopPPTCmd( IN CONST SessionID dwSSID);

/*******************************************************************************//**
*@brief         qk发送pc结束PPT命令
* KdvNv_DLNASrcStateNty
*
*@param[in]     dwSSID  NV会话ID 
*@return        u32  0：成功获取， 其他：错误码
*@note          更新通知：Ev_NvApi_Base_ImixSendToQKHeartBeat_Nty
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_NvQuickShareHeartBeatNty( IN CONST SessionID dwSSID);

/*******************************************************************************//**
*@brief         PPT翻页命令
* KdvNv_NvPPTPageTurningCmd
*
*@param[in]     dwSSID  NV会话ID 
*@return        u32  0：成功获取， 其他：错误码
*@note          更新通知：
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_PPTPageTurningCmd( IN CONST nv::TS32 tPageTurning ,IN CONST SessionID dwSSID);

/*******************************************************************************//**
*@brief         界面请求开始关机倒计时
* KdvNv_StartShutdownCountReq
*
*@param[in]     dwSSID  NV会话ID 
*@return        u32  0：成功获取， 其他：错误码
*@note          更新通知：Ev_NvApi_Base_StartShutdownCount_Rsp
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_StartShutdownCountReq( IN CONST SessionID dwSSID);

/*******************************************************************************//**
*@brief         界面整体下电命令
* KdvNv_StartShutdownCountReq
*
*@param[in]     dwSSID  NV会话ID 
*@return        u32  0：成功获取， 其他：错误码
*@note          更新通知：
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_AutoShutdownCmd( IN CONST SessionID dwSSID);

/*******************************************************************************//**
*@brief         qk请求版本信息
*
*@param[in]     dwSSID  NV会话ID 
*@return        u32  0：成功获取， 其他：错误码
*@note          更新通知：Ev_NvApi_Base_GetQkVersion_Rsp
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_NvGetQKVersionReq( IN CONST SessionID dwSSID);

/*******************************************************************************//**
*@brief         终端恢复出厂设置
*KdvNv_ResetTerCfgCmd
*@param[in]     tCfg 是否删除配置文件，TRUE:删除
*@param[in]     dwSSID  NV会话ID 
*@return        u32  0：成功获取， 其他：错误码
*@note          更新通知：
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_ResetTerCfgCmd(IN CONST nv::TBOOL32 tCfg, IN CONST SessionID dwSSID);

/*******************************************************************************//**
*@brief         设置终端时间配置
*KdvNv_SetTerTimeCfgCmd
*@param[in]     tCfg 时间配置信息
*@param[in]     dwSSID  NV会话ID 
*@return        u32  0：成功获取， 其他：错误码
*@note          更新通知：Ev_NvApi_Base_SetMtSysTimeCfg_Ntf
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_SetTerTimeCfgCmd(IN CONST nv::TNVCfgMtSystemTime tCfg, IN CONST SessionID dwSSID);

/*******************************************************************************//**
*@brief         设置终端时间数据
*KdvNv_SetTerSysTimeDataReq
*@param[in]     tTime 时间数据信息
*@param[in]     dwSSID  NV会话ID 
*@return        u32  0：成功获取， 其他：错误码
*@note          更新通知：Ev_NvApi_Base_SetMtSysDataTimeResult_Rsp
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_SetTerSysTimeDataReq(IN CONST nv::TNVTime tTime, IN CONST SessionID dwSSID);

/*******************************************************************************//**
*@brief         选看远程白板命令
*KdvNv_ViewWhiteBoardCmd
*@param[in]     tView：TRUE：选看
*@param[in]     dwSSID  NV会话ID 
*@return        u32  0：成功获取， 其他：错误码
*@note          更新通知：Ev_NvApi_Base_SetMtSysDataTimeResult_Rsp
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_ViewWhiteBoardCmd(IN CONST nv::TBOOL32 tView, IN CONST SessionID dwSSID);

/*******************************************************************************//**
*@brief         app升级是否成功通知
*KdvNv_ViewWhiteBoardCmd
*@param[in]     tIsSuc：TRUE：成功
*@param[in]     dwSSID  NV会话ID 
*@return        u32  0：成功获取， 其他：错误码
*@note          更新通知：Ev_NvApi_Base_SetMtSysDataTimeResult_Rsp
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_NvAppUpgradeIsSucNtf(IN CONST nv::TBOOL32 tIsSuc, IN CONST SessionID dwSSID);

/*******************************************************************************//**
*@brief         pad升级文件是否下载成功通知
*KdvNv_ViewWhiteBoardCmd
*@param[in]     tIsSuc：TRUE：成功
*@param[in]     dwSSID  NV会话ID 
*@return        u32  0：成功获取， 其他：错误码
*@note          更新通知：Ev_NvApi_Base_SetMtSysDataTimeResult_Rsp
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_NvPadIsDownSucNtf(IN CONST nv::TBOOL32 tIsSuc, IN CONST SessionID dwSSID);

/*******************************************************************************//**
*@brief         pad升级文件下载状态
*@param[in]     tIsSuc：TRUE：成功
*@param[in]     dwSSID  NV会话ID 
*@return        u32  0：成功获取， 其他：错误码
*@note          更新通知：Ev_NvApi_Base_SetMtSysDataTimeResult_Rsp
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_NvPadDownStateNtf(IN CONST nv::TBOOL32 tIsDown, IN CONST SessionID dwSSID);

/*******************************************************************************//**
*@brief         路由器升级文件是否下载成功通知
*KdvNv_ViewWhiteBoardCmd
*@param[in]     tIsSuc：TRUE：成功
*@param[in]     dwSSID  NV会话ID 
*@return        u32  0：成功获取， 其他：错误码
*@note          更新通知：Ev_NvApi_Base_SetMtSysDataTimeResult_Rsp
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_NvRouterIsDownSucNtf(IN CONST nv::TBOOL32 tIsSuc, IN CONST SessionID dwSSID);

/*******************************************************************************//**
*@brief         路由器升级文件下载状态
*@param[in]     tIsSuc：TRUE：成功
*@param[in]     dwSSID  NV会话ID 
*@return        u32  0：成功获取， 其他：错误码
*@note          更新通知：Ev_NvApi_Base_SetMtSysDataTimeResult_Rsp
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_NvRouterDownStateNtf(IN CONST nv::TBOOL32 tIsDown, IN CONST SessionID dwSSID);

/*******************************************************************************//**
*@brief         获取终端ip
*KdvNv_GetTerIpReq
*
*@param[in]     dwSSID  NV会话ID 
*@return        u32  0：成功获取， 其他：错误码
*@note          更新通知：Ev_NvApi_Base_GetTerIp_Rsp
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_GetTerIpReq( IN CONST SessionID dwSSID);

/*******************************************************************************//**
*@brief         获取终端硬件信息
*KdvNv_GetTerHWInfoCmd
*
*@param[in]     dwSSID  NV会话ID 
*@return        u32  0：成功获取， 其他：错误码
*@note          更新通知：Ev_NvApi_Base_GetTerHWInfo_Nty
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_GetTerHWInfoCmd( IN CONST SessionID dwSSID);

/*******************************************************************************//**
*@brief         设置终端播放本地音频
*KdvNv_SetTerLocalSoundPlayCmd
*
*@param[in]     dwSSID  NV会话ID 
*@return        u32  0：成功获取， 其他：错误码
*@note          更新通知：Ev_NvApi_Base_LocalSoundPlay_Nty
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_SetTerLocalSoundPlayCmd( IN CONST nv::TNVMtLocalSoundPaly tSoundPlay, IN CONST SessionID dwSSID);

/**
*  KdvNv_GetNvVerInfoReq 
* 
* @brief    获取版本信息
* 
* @param    [in] dwSSID  NV会话ID 
* @return   u32  NV_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_NvApi_Base_GetNvVerInfo_Rsp
*/
KdvNvAPI u32 KdvNvCALL KdvNv_GetNvVerInfoReq( IN CONST SessionID dwSSID /*= KNVAPI_DEF_SSID*/ );

/*******************************************************************************//**
*@brief         终端音频输出测试
*KdvNv_TerAudioOutPowerTestCmd
*
*@param[in]     dwSSID  NV会话ID 
*@return        u32  0：成功获取， 其他：错误码
*@note          更新通知：Ev_NvApi_Base_TerAudioOutPowerTest_Nty
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_TerAudioOutPowerTestCmd( IN CONST nv::TNVMtAudioTestCfg tCfg, IN CONST SessionID dwSSID);

/*******************************************************************************//**
*@brief         终端音频输入接口测试
*KdvNv_TerAudioInPowerTestCmd
*
*@param[in]     dwSSID  NV会话ID 
*@return        u32  0：成功获取， 其他：错误码
*@note          更新通知：Ev_NvApi_Base_TerAudioInPowerTest_Nty
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_TerAudioInPowerTestCmd( IN CONST nv::TNVMtAudioTestCfg tCfg, IN CONST SessionID dwSSID);

/*******************************************************************************//**
*@brief         终端音频输入接口状态查询请求
*KdvNv_TerAudioInputStateReq
*
*@param[in]     dwSSID  NV会话ID 
*@return        u32  0：成功获取， 其他：错误码
*@note          更新通知：Ev_NvApi_Base_TerAudioInputState_Rsp
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_TerAudioInputStateReq( IN CONST nv::TNVMtMutiAudInState tState, IN CONST SessionID dwSSID);

/*******************************************************************************//**
*@brief         获取登录APS所需要的参数请求
*KdvNv_GetLoginApsParamCfgReq
*
*@param[in]     dwSSID  NV会话ID 
*@return        u32  0：成功获取， 其他：错误码
*@note          更新通知：Ev_NvApi_Base_GetLoginApsParamCfg_Rsp
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_GetLoginApsParamCfgReq( IN CONST SessionID dwSSID);

/*******************************************************************************//**
*@brief         获取呼叫协议类型配置请求
*KdvNv_GetCallProtocolCfgReq
*
*@param[in]     dwSSID  NV会话ID 
*@return        u32  0：成功获取， 其他：错误码
*@note          更新通知：Ev_NvApi_Base_GetCallProtocolCfg_Rsp
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_GetCallProtocolCfgReq( IN CONST SessionID dwSSID);

/*******************************************************************************//**
*@brief         获取XAPList配置请求
*KdvNv_GetXAPListCfgReq
*
*@param[in]     dwSSID  NV会话ID 
*@return        u32  0：成功获取， 其他：错误码
*@note          更新通知：Ev_NvApi_Base_GetXAPListCfg_Rsp
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_GetXAPListCfgReq( IN CONST SessionID dwSSID);

/*******************************************************************************//**
*@brief         获取H323代理配置请求
*KdvNv_GetH323PxyCfgReq
*
*@param[in]     dwSSID  NV会话ID 
*@return        u32  0：成功获取， 其他：错误码
*@note          更新通知：Ev_NvApi_Base_GetH323PxyCfg_Rsp
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_GetH323PxyCfgReq( IN CONST SessionID dwSSID);

/*******************************************************************************//**
*@brief         请求获取手动设置的gk地址
*KdvNv_GetGKCfgReq
*
*@param[in]     dwSSID  NV会话ID 
*@return        u32  0：成功获取， 其他：错误码
*@note          更新通知：Ev_NvApi_Base_GetGKCfg_Rsp
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_GetGKCfgReq( IN CONST SessionID dwSSID);

/*******************************************************************************//**
*@brief         获取手动设置Sip服务器的配置
*KdvNv_GetManuSipSvrCfgReq
*
*@param[in]     dwSSID  NV会话ID 
*@return        u32  0：成功获取， 其他：错误码
*@note          更新通知：Ev_NvApi_Base_GetManuSipSvrCfg_Rsp
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_GetManuSipSvrCfgReq( IN CONST SessionID dwSSID);

/*******************************************************************************//**
*@brief         获取是否允许登陆平台服务请求
*KdvNv_GetLoginPlatformSrvCfgReq
*
*@param[in]     dwSSID  NV会话ID 
*@return        u32  0：成功获取， 其他：错误码
*@note          更新通知：Ev_NvApi_Base_GetLoginPlatformSrvCfg_Rsp
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_GetLoginPlatformSrvCfgReq( IN CONST SessionID dwSSID);

/*******************************************************************************//**
*@brief         获取是否强制设置H323协议类型请求
*KdvNv_GetForceH323StackCfgReq
*
*@param[in]     dwSSID  NV会话ID 
*@return        u32  0：成功获取， 其他：错误码
*@note          更新通知：Ev_NvApi_Base_GetForceH323StackCfg_Rsp
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_GetForceH323StackCfgReq( IN CONST SessionID dwSSID);

/*******************************************************************************//**
*@brief         查询账号详细信息请求
*KdvNv_GetAccountInfoReq
*
*@param[in]     dwSSID  NV会话ID
*@param[in]     tInfo  账号信息 
*@return        u32  0：成功获取， 其他：错误码
*@note          更新通知：Ev_NvApi_Base_GetAccountInfo_Rsp
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_GetAccountInfoReq( IN CONST nv::TNVMtAccountManager tInfo, IN CONST SessionID dwSSID);

/*******************************************************************************//**
*@brief         设置终端名称信息配置命令
*KdvNv_SetTerminalNameCfgCmd
*
*@param[in]     dwSSID  NV会话ID
*@param[in]     tInfo  终端名字信息 
*@return        u32  0：成功获取， 其他：错误码
*@note          更新通知：Ev_NvApi_Base_SetTerminalName_Ntf
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_SetTerminalNameCfgCmd( IN CONST nv::TNVTerminalName tInfo, IN CONST SessionID dwSSID);

/*******************************************************************************//**
*@brief         设置终端是否允许登录云平台
*KdvNv_SetTerLoginPlatformSrvCfgCmd
*
*@param[in]     dwSSID  NV会话ID
*@param[in]     tInfo   TRUE:允许，FALSE：不允许
*@return        u32  0：成功获取， 其他：错误码
*@note          更新通知：Ev_NvApi_Base_SetLoginPlatformSrvCfg_Ntf
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_SetTerLoginPlatformSrvCfgCmd( IN CONST nv::TBOOL32 tInfo, IN CONST SessionID dwSSID);

/*******************************************************************************//**
*@brief         设置登录APS所需要的参数
*KdvNv_SetLoginApsParamCfgCmd
*
*@param[in]     dwSSID  NV会话ID
*@param[in]     tInfo   APS所需要的参数
*@return        u32  0：成功获取， 其他：错误码
*@note          更新通知：Ev_NvApi_Base_ApsLoginResult_Ntf
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_SetLoginApsParamCfgCmd( IN CONST nv::TNVApsLoginParam  tInfo, IN CONST SessionID dwSSID);

/*******************************************************************************//**
*@brief         设置防网络拦截
*KdvNv_ForceSetH323StackCfgCmd
*
*@param[in]     dwSSID  NV会话ID
*@param[in]     tInfo   设置是否防网络拦截
*@return        u32  0：成功获取， 其他：错误码
*@note          更新通知：Ev_NvApi_Base_ForceSet323StackCfg_Ntf
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_ForceSetH323StackCfgCmd( IN CONST nv::TNVForceSetH323Stack  tInfo, IN CONST SessionID dwSSID);

/*******************************************************************************//**
*@brief         设置XAPList配置命令
*KdvNv_SetXAPListCfgCmd
*
*@param[in]     dwSSID  NV会话ID
*@param[in]     tInfo   XAPS信息
*@return        u32  0：成功获取， 其他：错误码
*@note          更新通知：Ev_NvApi_Base_SetXAPListCfg_Ntf
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_SetXAPListCfgCmd( IN CONST nv::TNVMtXAPSvrList  tInfo, IN CONST SessionID dwSSID);

/*******************************************************************************//**
*@brief         设置H323代理命令
*KdvNv_SetH323PxyCfgCmd
*
*@param[in]     dwSSID  NV会话ID
*@param[in]     tInfo   H323代理配置参数
*@return        u32  0：成功获取， 其他：错误码
*@note          更新通知：Ev_NvApi_Base_SetH323PxyCfg_Ntf
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_SetH323PxyCfgCmd( IN CONST nv::TNVH323PxyCfg  tInfo, IN CONST SessionID dwSSID);

/*******************************************************************************//**
*@brief         获取H460代理参数请求
*KdvNv_GetH460CfgReq
*
*@param[in]     dwSSID  NV会话ID
*@return        u32  0：成功获取， 其他：错误码
*@note          更新通知：Ev_NvApi_Base_GetH460Cfg_Rsp
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_GetH460CfgReq(  IN CONST SessionID dwSSID);

/*******************************************************************************//**
*@brief         设置H460代理命令
*KdvNv_SetH460CfgCmd
*
*@param[in]     dwSSID  NV会话ID
*@param[in]     tInfo   H460代理配置参数
*@return        u32  0：成功获取， 其他：错误码
*@note          更新通知：Ev_NvApi_Base_SetH460Cfg_Ntf
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_SetH460CfgCmd( IN CONST nv::TNVH460PxyCfg  tInfo, IN CONST SessionID dwSSID);

/*******************************************************************************//**
*@brief         注册Sip服务器配置命令
*KdvNv_SetSipSvrCfgCmd
*
*@param[in]     dwSSID  NV会话ID
*@param[in]     tInfo   Sip服务器配置参数
*@return        u32  0：成功获取， 其他：错误码
*@note          更新通知：Ev_NvApi_Base_SetSipSvrCfg_Ntf
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_SetSipSvrCfgCmd( IN CONST nv::TNVSipSrvCfg tInfo, IN CONST SessionID dwSSID);

/*******************************************************************************//**
*@brief         获取音频输入接口请求
*KdvNv_GetAudInPortListCfgReq
*
*@param[in]     dwSSID  NV会话ID
*@return        u32  0：成功获取， 其他：错误码
*@note          更新通知：Ev_NvApi_Base_GetAudInPortListCfg_Rsp
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_GetAudInPortListCfgReq(  IN CONST SessionID dwSSID);

/*******************************************************************************//**
*@brief         自动声音时延检测命令
*KdvNv_AutoAudioDelayCheckCmd
*
*@param[in]     dwSSID  NV会话ID
*@param[in]     tInfo   TRUE:开始检测 FALSE:停止检测
*@return        u32  0：成功获取， 其他：错误码
*@note          更新通知：
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_AutoAudioDelayCheckCmd( IN CONST nv::TBOOL32 tInfo, IN CONST SessionID dwSSID);

/*******************************************************************************//**
*@brief         获取终端呼叫码率请求
*KdvNv_GetCallBitRateCfgReq
*
*@param[in]     dwSSID  NV会话ID
*@return        u32  0：成功获取， 其他：错误码
*@note          更新通知：Ev_NvApi_Base_GetCallBitRateCfg_Rsp
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_GetCallBitRateCfgReq(  IN CONST SessionID dwSSID);

/*******************************************************************************//**
*@brief         设置终端呼叫码率命令
*KdvNv_SetCallBitRateCfgCmd
*
*@param[in]     dwSSID  NV会话ID
*@param[in]     tInfo   呼叫码率
*@return        u32  0：成功获取， 其他：错误码
*@note          更新通知：Ev_NvApi_Base_SetCallBitRateCfg_Ntf
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_SetCallBitRateCfgCmd( IN CONST nv::TU32 tInfo, IN CONST SessionID dwSSID);

/*******************************************************************************//**
*@brief         获取终端服务器登录状态请求
*KdvNv_GetSvrStateListReq
*
*@param[in]     dwSSID  NV会话ID
*@return        u32  0：成功获取， 其他：错误码
*@note          更新通知：Ev_NvApi_Base_GetSvrStateList_Rsp
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_GetSvrStateListReq(  IN CONST SessionID dwSSID);

/*******************************************************************************//**
*@brief         终端注册CSU服务器配置命令 (GK)
*KdvNv_SetCSUCfgCmd
*
*@param[in]     dwSSID  NV会话ID
*@return        u32  0：成功获取， 其他：错误码
*@note          更新通知：Ev_NvApi_Base_SetCSUCfg_Ntf, Ev_NvApi_Base_TerRegResult_Ntf
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_SetCSUCfgCmd(  IN CONST nv::TNVMtCSUAddr tInfo, IN CONST SessionID dwSSID);

/*******************************************************************************//**
*@brief         查询SDI接口数量请求
*KdvNv_GetTerSdiInOutReq
*
*@param[in]     dwSSID  NV会话ID
*@return        u32  0：成功获取， 其他：错误码
*@note          更新通知：Ev_NvApi_Base_GetTerSdiInOut_Rsp
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_GetTerSdiInOutReq(  IN CONST SessionID dwSSID);

/*******************************************************************************//**
*@brief         查询麦克风连接状态请求
*KdvNv_GetMicrophoneConnectStatusReq
*
*@param[in]     dwSSID  NV会话ID
*@return        u32  0：成功获取， 其他：错误码
*@note          更新通知：Ev_NvApi_Base_GetMicrophoneConnectStatus_Rsp
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_GetMicrophoneConnectStatusReq(  IN CONST SessionID dwSSID);

/*******************************************************************************//**
*@brief         获取第一路主视频输入端口请求
*KdvNv_GetPri1stVidInPortCfgReq
*
*@param[in]     dwSSID  NV会话ID
*@return        u32  0：成功获取， 其他：错误码
*@note          更新通知：Ev_NvApi_Base_GetPri1stVidInPortCfg_Rsp
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_GetPri1stVidInPortCfgReq(  IN CONST SessionID dwSSID);

/*******************************************************************************//**
*@brief         获取辅视频输入端口请求
*KdvNv_GetAssVidInPortCfgReq
*
*@param[in]     dwSSID  NV会话ID
*@return        u32  0：成功获取， 其他：错误码
*@note          更新通知：Ev_NvApi_Base_GetAssVidInPortCfg_Rsp
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_GetAssVidInPortCfgReq(  IN CONST SessionID dwSSID);

/*******************************************************************************//**
*@brief         获取第二路主辅视频输入端口请求
*KdvNv_GetPri2ndVidInPortCfgReq
*
*@param[in]     dwSSID  NV会话ID
*@return        u32  0：成功获取， 其他：错误码
*@note          更新通知：Ev_NvApi_Base_GetPri2ndVidInPortCfg_Rsp
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_GetPri2ndVidInPortCfgReq(  IN CONST SessionID dwSSID);

/*******************************************************************************//**
*@brief         设置音频输入接口
*KdvNv_SetAudInPortListCfgCmd
*
*@param[in]     dwSSID  NV会话ID
*@return        u32  0：成功获取， 其他：错误码
*@note          更新通知：Ev_NvApi_Base_SetAudInPortListCfg_Ntf
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_SetAudInPortListCfgCmd( IN CONST nv::TNVMtAudInPortList tInfo, IN CONST SessionID dwSSID);


/*******************************************************************************//**
*@brief         通知总开关待机关机(收到Ev_NvApi_Base_SwbKey_Nty消息时发送这条命令)
* KdvNv_SetSwbStateCmd
*
*@param[in]     tState 枚举值统一使用nv::TS32来传输，该处实际为nv::EmNvSwbState dwSSID  NV会话ID 
*@return        u32  0：成功获取， 其他：错误码
*@note          更新通知：
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_SetSwbStateCmd( IN CONST nv::TS32 &tState, IN CONST SessionID dwSSID);

/*******************************************************************************//**
*@brief         通知imix业务当前是否显示绿色弹窗
*KdvNv_NotifyIsShowGreenWin
*@param[in]     tShow：TRUE打开绿色弹窗
*@param[in]     dwSSID  NV会话ID 
*@return        u32  0：成功获取， 其他：错误码
*@note          更新通知：
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_NotifyIsShowGreenWin(IN CONST nv::TBOOL32 tShow, IN CONST SessionID dwSSID);

/*******************************************************************************//**
*@brief         退出批注命令
*KdvNv_LeaveSrceenDrawCmd
*@param[in]     dwSSID  NV会话ID 
*@return        u32  0：成功获取， 其他：错误码
*@note          更新通知：
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_LeaveSrceenDrawCmd( IN CONST SessionID dwSSID);

/*******************************************************************************//**
*@brief         获取配置文件中pad版本号请求
*KdvNv_NvGetPadVersionReq
*
*@param[in]     dwSSID  NV会话ID
*@return        u32  0：成功获取， 其他：错误码
*@note          更新通知：Ev_NvApi_Base_GetPadVersion_Rsp
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_NvGetPadVersionReq(  IN CONST SessionID dwSSID);

/*******************************************************************************//**
*@brief         imix走完设置向导后通知终端
*KdvNv_SetWizardResultCmd
*
*@param[in]     dwSSID  NV会话ID
*@return        u32  0：成功获取， 其他：错误码
*@note          
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_SetWizardResultCmd(  IN CONST SessionID dwSSID);

/*******************************************************************************//**
*@brief         获取终端是否注册Gk请求
*KdvNv_NvGetPadVersionReq
*
*@param[in]     dwSSID  NV会话ID
*@return        u32  0：成功获取， 其他：错误码
*@note          更新通知：Ev_NvApi_Base_GetGKRegistRt_Rsp
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_GetGKRegistRtReq(  IN CONST SessionID dwSSID);

/*******************************************************************************//**
*@brief         获取终端是否注册Sip请求
*KdvNv_NvGetPadVersionReq
*
*@param[in]     dwSSID  NV会话ID
*@return        u32  0：成功获取， 其他：错误码
*@note          更新通知：Ev_NvApi_Base_GetGKRegistRt_Rsp
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_GetSipRegistRtReq(  IN CONST SessionID dwSSID);

/*******************************************************************************//**
*@brief         通知imix路由器升级状态
*KdvNv_NvRouterUpgradeStateNty
*
*@param[in]     dwSSID  NV会话ID
*@return        u32  0：成功获取， 其他：错误码
*@note          更新通知：
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_NvRouterUpgradeStateNty( IN CONST nv::TBOOL32 bState,  IN CONST SessionID dwSSID);

/*******************************************************************************//**
*@brief         投屏器询问终端别名
*KdvNv_QkGetTerNameReq
*@param[in]     dwSSID  NV会话ID 
*@return        u32  0：成功获取， 其他：错误码
*@note          更新通知：Ev_NvApi_Base_QkGetTerName_Rsp
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_QkGetTerNameReq( IN CONST SessionID dwSSID);

/**
*  KdvNv_GetPlayZoomModeReq 
* 
* @brief   获取ftp状态
*   
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_NvApi_Base_GetFtpState_Rsp
*/
KdvNvAPI u32 KdvNvCALL KdvNv_GetFtpStateReq( IN CONST SessionID dwSSID /*= DEFAULT_SSID*/ );

/*******************************************************************************//**
*@brief         投屏器通知终端编码协商结果
*KdvNv_QkCodecConsultResultNty
*@param[in]     tbResult  结果
*@param[in]     dwSSID  NV会话ID 
*@return        u32  0：成功获取， 其他：错误码
*@note          更新通知：
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_QkCodecConsultResultNty(IN CONST nv::TBOOL32 tbResult, IN CONST SessionID dwSSID);

/*******************************************************************************//**
*@brief         投屏器通知终端编码分辨率设置结果
*KdvNv_QkCodecConsultResultNty
*@param[in]     tbResult  结果
*@param[in]     dwSSID  NV会话ID 
*@return        u32  0：成功获取， 其他：错误码
*@note          更新通知：
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_QkCodecResResultNty(IN CONST nv::TBOOL32 tbResult, IN CONST SessionID dwSSID);

/*******************************************************************************//**
*@brief         投屏器通知终端编码帧率设置结果
*KdvNv_QkCodecConsultResultNty
*@param[in]     tbResult  结果
*@param[in]     dwSSID  NV会话ID 
*@return        u32  0：成功获取， 其他：错误码
*@note          更新通知：
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_QkCodecFrameResultNty(IN CONST nv::TBOOL32 tbResult, IN CONST SessionID dwSSID);

/*******************************************************************************//**
*@brief         投屏器通知终端编码码率设置结果
*KdvNv_QkCodecConsultResultNty
*@param[in]     tbResult  结果
*@param[in]     dwSSID  NV会话ID 
*@return        u32  0：成功获取， 其他：错误码
*@note          更新通知：
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_QkCodecBitRateResultNty(IN CONST nv::TBOOL32 tbResult, IN CONST SessionID dwSSID);

/*******************************************************************************//**
*@brief         应用通知imix data文件夹清理结果
*KdvNv_NvClearDataFolderSucNty
*@param[in]     tbSuc  结果
*@param[in]     dwSSID  NV会话ID 
*@return        u32  0：成功获取， 其他：错误码
*@note          更新通知：
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_NvClearDataFolderSucNty(IN CONST nv::TBOOL32 tbSuc, IN CONST SessionID dwSSID);

/*******************************************************************************//**
*@brief         界面删除系统文件接口
*KdvNv_NvCancelFileCmd
*@param[in]     bFilePath  删除文件绝对路径
*@param[in]     dwSSID  NV会话ID 
*@return        u32  0：成功获取， 其他：错误码
*@note          更新通知：
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_NvCancelFileCmd(IN CONST nv::TString bFilePath, IN CONST SessionID dwSSID);

/*******************************************************************************//**
*@brief         界面查询imix登录终端状态
*KdvNv_GetNvIsConnectTerReq
*@param[in]     dwSSID  NV会话ID 
*@return        u32  0：成功获取， 其他：错误码
*@note          更新通知：Ev_NvApi_Base_NVConnectTer_Rsp
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_GetNvIsConnectTerReq( IN CONST SessionID dwSSID);

/*******************************************************************************//**
*@brief         设置是否开启功放
*KdvNv_SetAmplifierStatusCmd
*@param[in]     tbOpen  是否开启
*@param[in]     dwSSID  NV会话ID 
*@return        u32  0：成功获取， 其他：错误码
*@note          更新通知：Ev_NvApi_Base_SetAmplifierStatus_Nty
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_SetAmplifierStatusCmd(IN CONST nv::TBOOL32 tbOpen, IN CONST SessionID dwSSID);

/*******************************************************************************//**
*@brief         设置是否开启本地回显
*KdvNv_SetImixLocalEchoCmd
*@param[in]     tbOpen  是否开启
*@param[in]     dwSSID  NV会话ID 
*@return        u32  0：成功获取， 其他：错误码
*@note          更新通知：Ev_NvApi_Base_SetImixLocalEcho_Nty
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_SetImixLocalEchoCmd(IN CONST nv::TBOOL32 tbOpen, IN CONST SessionID dwSSID);

/*******************************************************************************//**
*@brief         获取imix版本是否与JD平台服务器版本一致
*KdvNv_GetNVVerIsSameAsJDServeReq
*@param[in]     dwSSID  NV会话ID 
*@return        u32  0：成功获取， 其他：错误码
*@note          更新通知：Ev_NvApi_Base_NVVerIsSameAsJDServer_Rsp
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_GetNVVerIsSameAsJDServeReq(IN CONST nv::TString tRouterVer, IN CONST SessionID dwSSID);

/*******************************************************************************//**
*@brief         设置imix版本从JD平台服务器下载版本
*KdvNv_SetNVIsUpgradeFromJDServerCmd
*@param[in]     dwSSID  NV会话ID 
*@return        u32  0：成功获取， 其他：错误码
*@note          更新通知：Ev_NvApi_Base_NVDownloadFromJDServer_Nty
                          Ev_NvApi_Base_NVDownloadResultFromJD_Nty
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_SetNVIsUpgradeFromJDServerCmd( IN CONST nv::TBOOL32 tUpgrade, IN CONST SessionID dwSSID);

/*******************************************************************************//**
*@brief         设置终端跳过设置向导静态图片
*KdvNv_SetSkipTerWizardCmd
*@param[in]     dwSSID  NV会话ID 
*@return        u32  0：成功获取， 其他：错误码
*@note          更新通知：
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_SetSkipTerWizardCmd( IN CONST SessionID dwSSID);
/*******************************************************************************//**
*@brief         获取imix序列号
*KdvNv_GetImixSerialNumReq
*@param[in]     dwSSID  NV会话ID 
*@return        u32  0：成功获取， 其他：错误码
*@note          更新通知：
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_GetImixSerialNumReq( IN CONST SessionID dwSSID);

/*******************************************************************************//**
*@brief         界面断开与sus服务器的连接
*KdvNv_NvImixDisconnectSusCmd
*@param[in]     dwSSID  NV会话ID 
*@return        u32  0：成功获取， 其他：错误码
*@note          更新通知：
***********************************************************************************/
KdvNvAPI u32 KdvNvCALL KdvNv_NvImixDisconnectSusCmd( IN CONST SessionID dwSSID);

#endif //_NVAPI_BASEAPI_H_

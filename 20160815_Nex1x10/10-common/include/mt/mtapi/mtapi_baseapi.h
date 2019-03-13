/*******************************************************************************//**
*@file          mtapi_baseapi.h
*@brief         提供mtbaseapi对外接口
*
*@author        ruiyigen
*@version       5.0    
*@date          20150328
*@copyright     (c)1995-2015 Suzhou Keda Technology Co.,Ltd. All rights reserved
***********************************************************************************/
#ifndef _MTAPI_BASEAPI_H_
#define _MTAPI_BASEAPI_H_
/**@addtogroup api API接口
*@{
*/

/**@addtogroup baseapi 基础API
*@{
*/

#include <string.h>
#include "mtapi_export.h"
#include "mtapi_typedef.h"
#include "mtapi_struct.h"


/*******************************************************************************//**
*@brief         mtbaseapi是否进行过初始化
*
*
*@author        ruiyigen   
*@date          20150328
*@param         void
*@return        BOOL32  TRUE ： 已初始化， FALSE：尚未初始化
*@note          KdvMt_BSInitalize, KdvMt_BSUnInitalize
***********************************************************************************/
KdvMtAPI BOOL32 KdvMtCALL KdvMt_BSIsInited(); 

/*******************************************************************************//**
*@brief         mtbaseapi模块初始化（这个的调用要在mtbaseapi调用的setnotify之后）
*
*
*@author        ruiyigen   
*@date          20150328
*@param[in]     emMode: emMtLocMode_Api: 非C/S模式，emMtRmtMode_Api：C/S模式
*@param[in]     bUniqueLogFile: 该参数仅当emMode为emMtRmtMode_Api时才有效.TRUE 本进程使用独有的日志文件；FALSE 使用远端进程的日志文件，即本进程的日志保存到远端进程的日志文件中
*@param[in]     pszClientTag: bUniqueLogFile为FALSE时有效. 进程/日志客户端标识，当使用远端进程的日志文件时，用来区分不同客户端。
*@return        u32  0: 初始化成功， 非0: 初始化失败
*@note          KdvMt_BSIsInited, KdvMt_BSUnInitalize
***********************************************************************************/
KdvMtAPI u32 KdvMtCALL KdvMt_BSInitalize( IN CONST EmMtApiMode_Api emMode = emMtLocMode_Api, IN CONST BOOL32 bUniqueLogFile = FALSE, IN CONST s8* pszClientTag = "" );

/*******************************************************************************//**
*@brief         mtbaseapi模块释放退出
*
*
*@author        ruiyigen   
*@date          20150328
*@param[in]     void
*@return	    u32  0: 成功， 非0: 失败
*@note          KdvMt_BSIsInited,KdvMt_BSInitalize
***********************************************************************************/
KdvMtAPI u32 KdvMtCALL KdvMt_BSUnInitalize();

/*******************************************************************************//**
*@brief         创建一个终端会话实例
*
*
*@author        wuhu   
*@date          20180412
*@param[out]    dwSSID      返回创建的会话ID
*@param[in]     ptParam     登录参数， 必须填， 参数中pwd为明文，emAppType 必须指定正确的值， 
                            如果是致邻，手机终端，验证方式为内部密码，如果验证失败，
							如果是mt类型， 会认为登录失败，消息不转发到mt中处理
							如果是mtc类型，会断开连接
*@return	    u32  0: 创建成功， 非0: 创建失败
*@note          和KdvMt_DestorySession对应，建立建立然后登陆终端
***********************************************************************************/
KdvMtAPI u32 KdvMtCALL KdvMt_CreateSession(OUT SessionID& dwSSID, TMtcLoginParam_Api* ptParam );

/*******************************************************************************//**
*@brief         通过SessionID释放一个已创建的Session
*
*
*@author        ruiyigen   
*@date          20150328
*@param[in]     SessionID  会话ID
*@return        u32   返回释放结果
*@note          和KdvMt_CreateSession2对应, 会断开连接
***********************************************************************************/
KdvMtAPI u32 KdvMtCALL KdvMt_DestorySession( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID ); 

/*******************************************************************************//**
*@brief         注册Observer(UI)通知回调(回调函数中响应消息处要与回调函数同步)
*               (这个函数如果没有调用则使用mtbaseapi中的回调函数)
*(注意：回调上去的参数不允许改变其值) 
*
*@author        ruiyigen   
*@date          20150328
*@param[in]     cbNotify  要注册的回调函数
*@return        void
*@note          
***********************************************************************************/
KdvMtAPI u32 KdvMtCALL KdvMt_BSSetNotify( IN NOTIFY_OBSERVER_CALLBACK cbNotify );


/*******************************************************************************//**
*@brief         获取最大支持的会话数量
*
*
*@author        ruiyigen   
*@date          20150328
*@param[in]     void
*@return        u16   返回最大支持的session数量
***********************************************************************************/
KdvMtAPI u16 KdvMtCALL KdvMt_GetMaxSessionCnt();

/*******************************************************************************//**
*@brief         获取已经存在的会话数量
*
*
*@author        ruiyigen   
*@date          20150328
*@param[in]     void
*@return        u16   返回已经存在的会话数量
***********************************************************************************/
KdvMtAPI u16 KdvMtCALL KdvMt_GetUsedSessionCnt();

/*******************************************************************************//**
*@brief         终端待机命令 (仅Embed)
*
*
*@author        ruiyigen   
*@date          20150328
*@param[in]     dwSSID  MT会话ID 
*@return        u32   请求命令发送结果
*@note          响应通知：Ev_MtApi_Base_CodecDspSleep_Rsp
***********************************************************************************/
KdvMtAPI u32 KdvMtCALL KdvMt_MTSleepCmd( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/*******************************************************************************//**
*@brief         终端唤醒命令 (仅Embed)
*
*
*@author        ruiyigen   
*@date          20150328
*@param[in]     dwSSID  MT会话ID
*@return        u32   请求命令发送结果
*@note          响应通知：Ev_MtApi_Base_SleepState_Ntf
***********************************************************************************/
KdvMtAPI u32 KdvMtCALL KdvMt_MTWakeupCmd( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/*******************************************************************************//**
*@brief         终端重启命令(仅Embed)
*
*
*@author        ruiyigen   
*@date          20150328
*@param[in]     dwSSID  MT会话ID
*@return        u32   请求命令发送结果
***********************************************************************************/
KdvMtAPI u32 KdvMtCALL KdvMt_MTRebootCmd( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/*******************************************************************************//**
*@brief         恢复出厂命令(仅Embed)
*
*
*@author        ruiyigen   
*@date          20150328
*@param[in]     bDelCfgFile 是否删除配置文件，包括mtcfg.db,呼叫记录和其他一些文件
*@param[in]     dwSSID  MT会话ID 
*@return        u32   请求命令发送结果
***********************************************************************************/
KdvMtAPI u32 KdvMtCALL KdvMt_MTResetCmd( IN CONST BOOL32 bDelCfgFile, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/*******************************************************************************//**
*@brief         检测更新命令
*
*
*@author        ruiyigen   
*@date          20150328
*@param[in]     tInfo  MT升级检测的信息
*@param[in]     dwSSID  MT会话ID
*@return        u32   请求命令发送结果
*@note          响应通知：Ev_MtApi_Base_CheckUpgradeResult_Ntf，Ev_MtApi_Base_UpgradeVersionInfo_Ntf
***********************************************************************************/
KdvMtAPI u32 KdvMtCALL KdvMt_MTCheckUpgradeCmd( IN CONST TMTUpgradeClientInfo_Api& tInfo, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/*******************************************************************************//**
*@brief         取消检测更新命令
*
*
*@author        ruiyigen   
*@date          20150328
*@param[in]     dwSSID  MT会话ID 
*@return        u32   请求命令发送结果
***********************************************************************************/
KdvMtAPI u32 KdvMtCALL KdvMt_MTCancelUpgradeCmd( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/*******************************************************************************//**
*@brief         开始下载文件命令
*
*
*@author        ruiyigen   
*@date          20150328
*@param[in]     pchSaveFilePath  下载存放文件路径
*@param[i]       dwVersionId 版本号
*@param[in]     dwSSID  MT会话ID
*@return        u32   请求命令发送结果
*@note          响应通知：Ev_MtApi_Base_UpgradeFileDownloadInfo_Ntf, Ev_MtApi_Base_UpgradeFileDownloadOk_Ntf
***********************************************************************************/
KdvMtAPI u32 KdvMtCALL KdvMt_MTStartDownloadUpgradeFileCmd( IN CONST s8* pchSaveFilePath, IN CONST u32 dwVersionId = 0, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/*******************************************************************************//**
*@brief         取消下载文件命令
*
*
*@author        ruiyigen   
*@date          20150328
*@param[in]     dwSSID  MT会话ID 
*@return        u32   请求命令发送结果
***********************************************************************************/
KdvMtAPI u32 KdvMtCALL KdvMt_MTCancelDownloadUpgradeFileCmd( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/*******************************************************************************//**
*@brief         开始升级命令(仅Embed)
*
*
*@author        ruiyigen   
*@date          20150328
*@param[in]     dwSSID  MT会话ID 
*@return        u32   请求命令发送结果
*@note          响应通知：Ev_MtApi_Base_UpgradeSysFileUpdateStatus_Ntf
***********************************************************************************/
KdvMtAPI u32 KdvMtCALL KdvMt_MTStartUpgradeCmd( IN CONST EmUpgradeType_Api emUpgradeType, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/*******************************************************************************//**
*@brief        检查U盘升级包(仅Embed)
*
*@param[in]     pchFilePath 升级包路径 
*@param[in]     dwSSID  MT会话ID 
*@return        u32   请求命令发送结果
*@note          响应通知：Ev_MtApi_Base_UsbUpgradeFileCheck_Rsp
***********************************************************************************/
KdvMtAPI u32 KdvMtCALL KdvMt_MTUsbUpgradeFileCheckReq( IN CONST s8 *pchFilePath, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_UISynchronize_Cmd
* 
* @brief   界面同步命令
*
* @param    [in]   emReason     同步原因
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 响应通知:
*/
KdvMtAPI u32 KdvMtCALL KdvMt_UISynchronize_Cmd(IN CONST EmUISynchronizeReason_Api emReason /*= EmUISynchronizeReason_Api*/, IN CONST SessionID dwSSID /*= KMTAPI_DEF_SSID*/ );

/*******************************************************************************//**
*@brief        目录结构查询(仅Embed)
*
*@param[in]     pchSrcPath  查询路径
*@param[in]     dwSSID  MT会话ID 
*
*@return        u32   请求命令发送结果
*@note          响应通知：Ev_MtApi_Base_InquirePathStructure_Rsp
***********************************************************************************/
KdvMtAPI u32 KdvMtCALL KdvMt_MTInquirePathStructureReq( IN CONST s8 *pchSrcPath, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/*******************************************************************************//**
*@brief         终端是否待机中(仅Embed)
*
*
*@author        ruiyigen   
*@date          20150328
*@param[out]    bSleep  BOOL32  TRUE：待机中， FALSE：非待机中
*@param[in]     dwSSID  MT会话ID 
*@return        u32  0：成功获取， 其他：错误码
*@note          更新通知：Ev_MtApi_Base_SleepState_Ntf
***********************************************************************************/
KdvMtAPI u32 KdvMtCALL KdvMt_MTIsSleeped( OUT BOOL32& bSleep, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/*******************************************************************************//**
*@brief         获取待机倒计时剩余时间(分钟)(仅Embed)
*
*
*@author        ruiyigen   
*@date          20150328
*@param[out]    u16   剩余时间 
*@param[in]     dwSSID  MT会话ID
*@return        u32  0：成功获取， 其他：错误码
*@note          更新通知：Ev_MtApi_Base_SleepCountDown_Ntf
***********************************************************************************/
KdvMtAPI u32 KdvMtCALL KdvMt_MTGetSleepRemainTime( OUT u16& wRemainTime, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/*******************************************************************************//**
*@brief         获取与终端匹配的SkyShare版本号(仅Embed)
*
*
*@author        ruiyigen   
*@date          20170830
*@param[in]     dwSSID  MT会话ID
*@return        u32  0：成功获取， 其他：错误码
*@note          响应消息：Ev_MtApi_Base_GetSkyShareVerRt_Rsp
***********************************************************************************/
KdvMtAPI u32 KdvMtCALL KdvMt_MTGetSkyShareVerReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/*******************************************************************************//**
*@brief         用户登录验证请求,只用于webmtc
*
 *
*@author        WeiLong   
*@date          20150414
*@param[in]     pchUsrName  用户名
*@param[in]     pchUsrPwd   密码（密文）
*@param[in]     emMtcType   终端类型
*@param[in]     dwSSID  MT会话ID
*@return        u32  MT_SUCCESS:发送请求成功  其他：错误码
*@note          响应通知：Ev_MtApi_Base_MTCLogin_Rsp
***********************************************************************************/
KdvMtAPI u32 KdvMtCALL KdvMt_WebMtcLoginReq( IN CONST s8* pchUsrName = "", IN CONST s8* pchUsrPwd = "",  IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/*******************************************************************************//**
*@brief         用户注销命令,只用于webmtc
*
*
*@author        WeiLong   
*@date          20150414
*@param[in]     pchUserName  用户名
*@param[in]     dwSSID  MT会话ID
*@return        u32  MT_SUCCESS:发送请求成功  其他：错误码
*@note          响应通知：Ev_MT_BLL_MTCLogOut_Ntf
***********************************************************************************/
KdvMtAPI u32 KdvMtCALL KdvMt_WebMtcLogoutCmd( IN CONST s8 *pchUserName, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/*******************************************************************************//**
*@brief         添加终端用户请求(支持批量操作)
*
*
*@author        ruiyigen   
*@date          20150328
*@param[in]     tUserList  待处理的mt消息体
*@param[in]     dwSSID  MT会话ID
*@return        u32  MT_SUCCESS:发送请求成功  其他：错误码
*@note          响应通知：Ev_MtApi_Base_MTCAddUser_Rsp, Ev_MtApi_Base_MTCAddUser_Ntf
***********************************************************************************/
KdvMtAPI u32 KdvMtCALL KdvMt_MTAddUserReq( IN CONST TMultiUserFullInfo_Api& tUserList, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID ); 

/*******************************************************************************//**
*@brief         修改用户请求(支持批量操作)
*
*
*@author        ruiyigen   
*@date          20150328
*@param[in]     tUserList  待处理的mt消息体
*@param[in]     dwSSID  MT会话ID
*@return        u32  MT_SUCCESS:发送请求成功  其他：错误码
*@note          响应通知：Ev_MtApi_Base_MTCMUser_Rsp, Ev_MtApi_Base_MTCMUser_Ntf
***********************************************************************************/
KdvMtAPI u32 KdvMtCALL KdvMt_MTModifyUserReq( IN CONST TMultiUserFullInfo_Api& tUserList, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/*******************************************************************************//**
*@brief         删除用户请求(支持批量操作)
*
*
*@author        ruiyigen   
*@date          20150328
*@param[in]     tUserId  用户id
*@param[in]     dwSSID  MT会话ID 
*@return        u32  MT_SUCCESS:发送请求成功  其他：错误码
*@note          响应通知：Ev_MtApi_Base_MTCDUser_Rsp, Ev_MtApi_Base_MTCDUser_Ntf
***********************************************************************************/
KdvMtAPI u32 KdvMtCALL KdvMt_MTDeleteUserReq( IN CONST TMTUsersId_Api tUserId, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/*******************************************************************************//**
*@brief         用户信息列表请求
*
*
*@author        ruiyigen   
*@date          20150328
*@param[in]     void
*@param[out]    dwSSID  MT会话ID
*@return        u32  MT_SUCCESS:发送请求成功  其他：错误码
*@note          响应通知：Ev_MtApi_Base_MTCSUser_Rsp
***********************************************************************************/
KdvMtAPI u32 KdvMtCALL KdvMt_MTGetUserListReq( IN SessionID dwSSID = KMTAPI_DEF_SSID );

/*******************************************************************************//**
*@brief         获取用户总数
*
*
*@author        ruiyigen   
*@date          20150328
*@param[out]    dwCount   用户信息
*@param[in]     dwSSID  MT会话ID
*@return        u32  0：成功获取， 其他：错误码
*@note          更新通知：Ev_MtApi_Base_MTCAddUser_Ntf, Ev_MtApi_Base_MTCDUser_Ntf, Ev_MtApi_Base_MTCSUser_Rsp
***********************************************************************************/
KdvMtAPI u32 KdvMtCALL KdvMt_MTGetUserCount( OUT u32 &dwCount, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID ); 

/*******************************************************************************//**
*@brief         获取指定索引的用户信息
*
*
*@author        ruiyigen   
*@date          20150328
*@param[in]     nIdx    要获取的用户索引信息
*@param[out]    tUser   用户信息
*@param[in]     dwSSID  MT会话ID
*@return        u32  0：成功获取， 其他：错误码
*@note          更新通知：Ev_MtApi_Base_MTCAddUser_Ntf, Ev_MtApi_Base_MTCMUser_Ntf, Ev_MtApi_Base_MTCDUser_Ntf, Ev_MtApi_Base_MTCSUser_Rsp
***********************************************************************************/
KdvMtAPI u32 KdvMtCALL KdvMt_MTGetUserByIdx( CONST s32 nIdx, OUT TUserFullInfo_Api& tUser, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID ); 

/*******************************************************************************//**
*@brief         获取指定用户ID的用户详细信息
*
*
*@author        ruiyigen   
*@date          20150328
*@param[in]     dwUserID    要获取的用户ID信息
*@param[out]    tUser   用户信息
*@param[in]     dwSSID  MT会话ID 
*@return        u32  0：成功获取， 其他：错误码
*@note          更新通知：Ev_MtApi_Base_MTCAddUser_Ntf, Ev_MtApi_Base_MTCMUser_Ntf, Ev_MtApi_Base_MTCDUser_Ntf, Ev_MtApi_Base_MTCSUser_Rsp
***********************************************************************************/
KdvMtAPI u32 KdvMtCALL KdvMt_MTGetUserByUsrID( CONST u32 dwUserID, OUT TUserFullInfo_Api& tUser, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID ); 

/*******************************************************************************//**
*@brief         通知正在使用的网络信息
*
*
*@author        ruiyigen   
*@date          20150328
*@param[in]     tNetUsedInfo    正在使用的网络信息
*@param[in]     dwSSID          MT会话ID 
*@return        u32  0：成功获取， 其他：错误码
***********************************************************************************/
KdvMtAPI u32 KdvMtCALL KdvMt_SendUsedNetInfoNtf( IN CONST TNetUsedInfo_Api& tNetUsedInfo,  IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/*******************************************************************************//**
*@brief         获取Qos配置请求
*
*
*@author        ruiyigen   
*@date          20150328
*@param[in]     dwSSID  MT会话ID
*@return        u32  MT_SUCCESS:发送请求成功  其他：错误码
*@note          响应通知：Ev_MtApi_Base_GetIPQoSCfg_Rsp
***********************************************************************************/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetIPQoSCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/*******************************************************************************//**
*@brief         获取MTU TCP/IP最大传输单元配置请求
*
*
*@author        ruiyigen   
*@date          20150328
*@param[in]     dwSSID  MT会话ID 
*@return        u32  MT_SUCCESS:发送请求成功  其他：错误码
*@note          响应通知：Ev_MtApi_Base_GetMTUCfg_Rsp
***********************************************************************************/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetMTUCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/*******************************************************************************//**
*@brief         获取NAT配置请求
*
*
*@author        ruiyigen   
*@date          20150328
*@param[in]     dwSSID  MT会话ID
*@return        u32  MT_SUCCESS:发送请求成功  其他：错误码
*@note          响应通知：Ev_MtApi_Base_GetNATCfg_Rsp
***********************************************************************************/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetNatCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/*******************************************************************************//**
*@brief         获取XAPList配置请求
*
*
*@author        ruiyigen   
*@date          20150328
*@param[in]     dwSSID  MT会话ID 
*@return        u32  MT_SUCCESS:发送请求成功  其他：错误码
*@note          响应通知：Ev_MtApi_Base_GetXAPListCfg_Rsp
***********************************************************************************/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetXAPListCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGGetCurXAPCfgReq 
* 
* @brief    获取当前使用的XAP服务器配置请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_GetCurXAPCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetCurXAPCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGGetAicameraCfgReq 
* 
* @brief    获取智能摄像机配置
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_GetAicameraCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetAicameraCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_CFGGetXNUCfgReq 
* 
* @brief    获取XNU服务器(XMPP登录)配置请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_GetXNURt_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetXNUCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGGetNSRtReq 
* 
* @brief    获取NS地址
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_GetNSRt_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetNSRtReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGGetCSUCfgReq 
* 
* @brief    获取CSU服务器配置请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_GetCSUCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetCSUCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_CFGGetSUSCfgReq 
* 
* @brief    获取SUS服务器配置请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_GetSUSCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetSUSCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGGetSusManuCfgReq 
* 
* @brief    获取SUS服务器手动配置请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_GetSusManuCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetSusManuCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGGetSNMPCfgReq 
* 
* @brief    获取网管服务器配置请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_GetNMSCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetSNMPCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGGetSNMPManuCfgReq 
* 
* @brief    获取网管服务器手动配置请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_GetNmsManuCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetSNMPManuCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGGetNTSCfgReq 
* 
* @brief    获取测速服务器配置请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_GetNTSCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetNTSCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGGetNtsManuCfgReq 
* 
* @brief    获取测速服务器手动配置请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_GetNtsManuCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetNtsManuCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGGetNTPCfgReq 
* 
* @brief    获取NTP服务器配置请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_GetNTPCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetNTPCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGGetNtpManuCfgReq 
* 
* @brief    获取NTP服务器手动配置请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_GetNtpManuCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetNtpManuCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGGetVODCfgReq 
* 
* @brief    获取VOD服务器配置请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_GetVODCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetVODCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_CFGGetVRSCfgReq 
* 
* @brief    获取VRS服务器配置请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_GetVRSCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetVRSCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_CFGGetStreamPlayerCfgReq 
* 
* @brief    获取StreamPlayer流媒体配置请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_GetStreamMediaCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetStreamPlayerCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGGetPlatformApiRtCfgReq 
* 
* @brief    获取API服务器地址
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_GetPlatformApiRt_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetPlatformApiRtCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGGetMicroBlogRtCfgReq 
* 
* @brief    获取微博服务器地址
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_GetMicroBlogRt_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetMicroBlogRtCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGGetSipSvrCfgReq 
* 
* @brief    获取Sip服务器配置请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_GetSipSvrCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetSipSvrCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );





/**
*  KdvMt_CFGGetSocks5PxyCfgReq 
* 
* @brief    获取Socket5代理配置请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_GetH323PxyCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetSocks5PxyCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_CFGGetSvrStateListReq 
* 
* @brief    获取服务器登录状态请求(RT)
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_GetSvrLoginStatusRt_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetSvrStateListReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_CFGGetUserPrevilegeReq 
* 
* @brief    获取Xap登录成功后获取的用户权限信息请求(RT)
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_GetUserPrevilegeRt_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetUserPrevilegeReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );




/**
*  KdvMt_CFGGetUserInfoFromApsRtReq 
* 
* @brief    获取登陆APS返回的用户信息请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_GetUserInfoFromApsRt_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetUserInfoFromApsRtReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );




/**
*  KdvMt_CFGGetH323CfgReq 
* 
* @brief    获取H323配置请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_GetH323Cfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetH323CfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_CFGGetSipCfgReq 
* 
* @brief    获取SIP配置请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_GetSipCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetSipCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGGetSmoothSendLevelCfgReq 
* 
* @brief    获取平滑发送等级请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_GetSmoothSendLevelCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetSmoothSendCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
*  KdvMt_CFGGetUseTelnetCfgReq 
* 
* @brief    获取telnet开关请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_GetUseTelnetCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetUseTelnetCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
*  KdvMt_CFGGetUseHTTPCfgReq 
* 
* @brief    获取Http开关请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_GetUseHTTPCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetUseHTTPCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );




/**
*  KdvMt_CFGGetUseFtpSrvCfgReq 
* 
* @brief    获取FTP开关请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_GetUseFtpCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetUseFtpSrvCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );




/**
*  KdvMt_CFGGetMCCfgReq 
* 
* @brief    获取内置MC配置请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_GetMCCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetMCCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );	



/**
*  KdvMt_CFGGetAudAnsCfgReq 
* 
* @brief    获取自动噪声增益配置请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_GetAnsCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetAudAnsCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_CFGGetAudAgcCfgReq 
* 
* @brief    获取自动增益控制配置请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_GetAgcCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetAudAgcCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGGetAudAecCfgReq 
* 
* @brief    获取自动回声抵消配置请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_GetAecCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetAudAecCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGGetAudVolInCfgReq 
* 
* @brief    获取音频输入音量配置请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_GetAudVolInCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetAudVolInCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
*  KdvMt_CFGGetAudVolOutCfgReq 
* 
* @brief    获取音频输出音量配置请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_GetAudVolOutCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetAudVolOutCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
*  KdvMt_CFGGetLostPackResendCfgReq 
* 
* @brief    获取丢包重传参数配置请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_GetLostPktResendCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetLostPackResendCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
*  KdvMt_CFGGetAudioPrecedenceCfgReq 
* 
* @brief    获取音质优先配置请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_GetAudioPrecedenceCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetAudioPrecedenceCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );




/**
*  KdvMt_CFGGetAudioPriorCfgReq 
* 
* @brief    获取音频优先请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_GetAudioPriorCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetAudioPriorCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
*  KdvMt_CFGGetPriVidPriorCfgReq 
* 
* @brief    获取主流优选请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_GetPriVidPriorCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetPriVidPriorCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
*  KdvMt_CFGGetPcAssVideoPriorCfgReq 
* 
* @brief    获取Pc辅流优请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_GetPcAssVidPriorCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetPcAssVideoPriorCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
*  KdvMt_CFGGetVidAssVideoPriorCfgReq 
* 
* @brief    获取Pc辅流优请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_GetVidAssVidPriorCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetVidAssVideoPriorCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
*  KdvMt_CFGGetCallInfoRtReq 
* 
* @brief    获取呼叫信息请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_GetCallInfoRt_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetCallInfoRtReq( IN CONST SessionID dwSSID /* = KMTAPI_DEF_SSID  */ );




/**
*  KdvMt_CFGGetChairmanOperateCfgReq 
* 
* @brief    获取主席操作配置请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_GetChrmanOperateCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetChairmanOperateCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
*  KdvMt_CFGGetShowConfStateCfgReq 
* 
* @brief    获取会议状态显示配置请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_GetShowConfStateCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetShowConfStateCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );




/**
*  KdvMt_CFGGetStaticPicCfReq 
* 
* @brief    获取发送静态图片配置请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_GetStaticPicCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetStaticPicCfReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID ) ;



/**
*  KdvMt_CFGGetTelephoneCfgReq 
* 
* @brief    获取启用电话功能配置请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_GetTelephoneCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetTelephoneCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
*  KdvMt_CFGGetAutoCallCfgReq 
* 
* @brief    获取自动呼叫配置请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_GetAutoCallCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetAutoCallCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
*  KdvMt_CFGGetAutoLoginCfgReq 
* 
* @brief    获取自动登录服务器配置请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_GetAutoLoginCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetAutoLoginCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_CFGGetAsymmetricNetCfgReq 
* 
* @brief    获取非对称网络配置请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_GetAsymmetricNetCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetAsymmetricNetCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
*  KdvMt_CFGGetIncomingCallFWCfgReq 
* 
* @brief    获取来电防火墙配置请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_GetUseCallFWCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetIncomingCallFWCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID ) ;



/**
*  KdvMt_CFGGetBandwidthCheckCfgReq 
* 
* @brief    获取当前是否启用带宽检测配置请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_GetBandWidthTestCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetBandwidthCheckCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
*  KdvMt_CFGSetMCRSParamCfgReq 
* 
* @brief    获取内置MC丢包重传参数配置请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_GetMCResendParamCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetMCRSParamCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_CFGGetAssStreamSrcAdjustCfgReq 
* 
* @brief    获取自动双流源配置请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_GetDualStramSrcAdjCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetAssStreamSrcAdjustCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
*  KdvMt_CFGGetCallProtocolCfgReq 
* 
* @brief    获取呼叫协议类型配置请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_GetCallProtocolCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetCallProtocolCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );




/**
*  KdvMt_CFGGetConfEncryptTypeCfgReq 
* 
* @brief    获取会议加密类型请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_GetEncryptTypeCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetConfEncryptTypeCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
*  KdvMt_CFGGetSipKeepAliveItrvlCfgReq 
* 
* @brief    获取Sip断链检测时间间隔配置请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_GetSipKeepAliveItrvlCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetSipKeepAliveItrvlCfgReq(  IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGGetKeepAliveItrvlCfgReq 
* 
* @brief    获取断链检测时间间隔配置请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_GetKeepAliveItrvlCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetKeepAliveItrvlCfgReq(  IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
*  KdvMt_CFGGetFecInfoCfgReq 
* 
* @brief    获取设置FEC配置请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_GetFECCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetFecInfoCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_CFGSetCallRateLevelCmd 
* 
* @brief    设置高中低档的会议码率配置命令(小于64任务是纯音频呼叫)
* 
* @param	[in] tCfg    高中低档的会议码率配置
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_SetCallRateLvCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetCallRateLevelCmd( IN CONST u32  dwCallRate, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_CFGGetFecInfoCfgReq 
* 
* @brief    获取高中低档的会议码率配置请求(小于64任务是纯音频呼叫)
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_GetCallRateLvCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetCallRateLevelReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
*  KdvMt_CFGGetVidBitRationCfgReq 
* 
* @brief    获取视频码率比例配置请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_GetVidBitRationCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetVidBitRationCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
*  KdvMt_CFGGetTerminalInfoReq 
* 
* @brief    获取终端版本信息配置请求(RT)
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_GetTerlInfoRt_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetTerminalInfoReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_CFGGetTerminalNameCfgReq 
* 
* @brief    获取终端名称信息配置请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_GetUserNameCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetTerminalNameCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
*  KdvMt_CFGGetTerminalNameCfgReq 
* 
* @brief    获取TCP/UDP起始端口配置信息请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_GetTcpUdpPortCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_GetUdpTcpBasePortCfgReq( CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
*  KdvMt_CFGGetTerminalNameCfgReq 
* 
* @brief    获取是否启用文件日志请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_GetLogStatusCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_GetIsUsedFileLogonReq(  CONST SessionID dwSSID = KMTAPI_DEF_SSID );




/**
*  KdvMt_CFGGetAnswerModeCfgReq 
* 
* @brief    获取应答模式请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_GetAnswerModeCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetAnswerModeCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGGetBandWidthReq 
* 
* @brief    获取自动带宽检测结果请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_BandwidthTestResult_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetBandWidthReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_CFGGetCallRateCfgReq 
* 
* @brief    获取呼叫码率
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_GetCallBitrateCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetCallBitRateCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_CFGGetAutoSendSharedContentCfgReq 
* 
* @brief    自动发送内容共享
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_GetAutoSendSharedContentCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetAutoSendSharedContentCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
*  KdvMt_CFGGetLoginPlatformSrvCfgReq 
* 
* @brief    是否允许登陆平台服务请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_GetLoginPlatformSrvCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetLoginPlatformSrvCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
*  KdvMt_CFGGetLoginTacticsCfgReq 
* 
* @brief    获取登录策略
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_GetSvrLoginTacticsCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetLoginTacticsCfgReq( IN CONST SessionID dwSSID );


/**
*  KdvMt_CFGGetVideoDecParamCfgReq 
* 
* @brief    获取解码参数
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_GetVideoDecParamCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetVideoDecParamCfgReq( IN CONST SessionID dwSSID );


/**
*  KdvMt_CFGGetIsSatelliteMTRtReq 
* 
* @brief    获取是否卫星终端配置
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_GetSatelliteCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetIsSatelliteMTRtReq( IN CONST SessionID dwSSID );


/**
*  KdvMt_CFGGetMCInfoRtReq 
* 
* @brief    获取MC配置
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_GetMCInfoRt_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetMCInfoRtReq( IN CONST SessionID dwSSID );

/**
*  KdvMt_CFGGetChanInfoRtReq 
* 
* @brief    获取通道信息配置
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_GetChanInfoRt_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetChanInfoRtReq( IN CONST SessionID dwSSID );


/**
*  KdvMt_CFGGetChrmanPollSchemesCfgReq 
* 
* @brief    获取主席轮询方案配置
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_GetChrmanPollSchemesCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetChrmanPollSchemesCfgReq( IN CONST SessionID dwSSID );

/**
*  KdvMt_CFGGetShowConfTimeCfgReq 
* 
* @brief    获取显示会议时间配置
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_GetShowConfTimeCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetShowConfTimeCfgReq( IN CONST SessionID dwSSID );

/**
*  KdvMt_CFGGetShowShortMsgInConfCfgReq 
* 
* @brief    获取会议中显示短消息配置
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_GetShowShortMsgInConfCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetShowShortMsgInConfCfgReq( IN CONST SessionID dwSSID );

/**
*  KdvMt_CFGGetShowAppTipsCfgReq 
* 
* @brief    获取显示申请提示配置
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_GetShowAppTipsCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetShowAppTipsCfgReq( IN CONST SessionID dwSSID );

/**
*  KdvMt_CFGGetFECCCfgReq 
* 
* @brief    获取远遥配置
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_GetFECCCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetFECCCfgReq( IN CONST SessionID dwSSID );

/**
*  KdvMt_CFGGetLoginPwdCfgReq 
* 
* @brief    获取登录密码配置
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_GetLoginPwdCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetLoginPwdCfgReq( IN CONST SessionID dwSSID );


/**
*  KdvMt_CFGGetEmailCfgReq 
* 
* @brief    获取Email配置
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_GetEmailCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetEmailCfgReq( IN CONST SessionID dwSSID );

/**
*  KdvMt_CFGGetSysUpgradeRtReq 
* 
* @brief    获取系统升级状态配置
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_GetSysUpgradeRt_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetSysUpgradeRtReq( IN CONST SessionID dwSSID );

/**
*  KdvMt_CFGGetConfUsedPortsRtReq 
* 
* @brief    获取会议使用的端口配置
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_GetConfUsedPortsRt_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetConfUsedPortsRtReq( IN CONST SessionID dwSSID );

/**
*  KdvMt_CFGGetMcUsedPortsRtReq 
* 
* @brief    获取MC使用的端口配置
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_GetMcUsedPortsRt_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetMcUsedPortsRtReq( IN CONST SessionID dwSSID );

/**
*  KdvMt_CFGGetVodUsedPortsRtReq 
* 
* @brief    获取点播使用的端口配置
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_GetVodUsedPortsRt_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetVodUsedPortsRtReq( IN CONST SessionID dwSSID );


/**
*  KdvMt_CFGGetImUsedPortsRtReq 
* 
* @brief    获取Im使用的端口配置
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_GetImUsedPortsRt_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetImUsedPortsRtReq( IN CONST SessionID dwSSID );

/**
*  KdvMt_CFGGetBandWidthCfgReq 
* 
* @brief    获取带宽
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_GetBandWidthRt_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetBandWidthCfgReq( IN CONST SessionID dwSSID );

/**
*  KdvMt_CFGGetSysCtrlSrvInfoRtReq 
* 
* @brief    获取系统控制映射表配置
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_GetSysCtrlSrvInfoRt_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetSysCtrlSrvInfoRtReq( IN CONST SessionID dwSSID );

/**
*  KdvMt_CFGGetSysCtrlSrvNumRtReq 
* 
* @brief    获取运行时映射表中模块个数配置
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_GetSysCtrlSrvNumRt_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetSysCtrlSrvNumRtReq( IN CONST SessionID dwSSID );

/**
*  KdvMt_CFGGetSysCtrlDefSrvInfoCfgReq 
* 
* @brief    获取默认启动映射表配置
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_GetSysCtrlDefSrvInfoCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetSysCtrlDefSrvInfoCfgReq( IN CONST SessionID dwSSID );



/**
*  KdvMt_CFGGetSysCtrlDefSrvNumCfgReq 
* 
* @brief    获取默认映射表中模块个数配置
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_GetSysCtrlDefSrvNumCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetSysCtrlDefSrvNumCfgReq( IN CONST SessionID dwSSID );





/**
*   KdvMt_CFGGetH460CfgReq
* 
* @brief    获取H460配置请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_GetH460Cfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetH460CfgReq( IN CONST SessionID dwSSID );

/**
*   KdvMt_CFGSetH460CfgCmd
* 
* @brief    设置H460配置
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_SetH460Cfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetH460CfgCmd( IN CONST TMtH460PxyCfg_Api &tCfg, IN CONST SessionID dwSSID );

/**
*    KdvMt_CFGGetH460Cfg  
* 
* @brief    获取H460配置
*
* @param    [out] tCfg	TMtH460PxyCfg_Api  MT会话ID 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetH460Cfg( OUT TMtH460PxyCfg_Api &tCfg, IN CONST SessionID dwSSID );

/**
*   KdvMt_CFGGetH323PxyCfgReq
* 
* @brief    获取H323代理配置请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_GetH323PxyCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetH323PxyCfgReq( IN CONST SessionID dwSSID );

/**
*   KdvMt_CFGSetH323PxyCfgCmd
* 
* @brief    H323代理设置
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_SetH323PxyCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetH323PxyCfgCmd( IN CONST TMtH323PxyCfg_Api &tCfg, IN CONST SessionID dwSSID );

/**
*   KdvMt_CFGGetH323PxyCfg
* 
* @brief    获取H323代理配置
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetH323PxyCfg( OUT TMtH323PxyCfg_Api &tCfg, IN CONST SessionID dwSSID );


/**
*   KdvMt_CFGGetMeetingCtrlSrvRtReq
* 
* @brief    获取会议服务器配置请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetMeetingCtrlSrvRtReq( IN CONST SessionID dwSSID );


/**
*   KdvMt_CFGGetMeetingCtrlSrvRt
* 
* @brief    获取会议服务器配置
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetMeetingCtrlSrvRt( OUT TMtMeetingSvrAddr_Api &tCfg, IN CONST SessionID dwSSID );




//硬终端产品线_start

/**
*  KdvMt_CFGGetHoriRollMsgCfgReq 
* 
* @brief    获取滚动短消息配置请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MT_GetHoriRollMsgCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetHoriRollMsgCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
*  KdvMt_CFGGetDCSCfgReq 
* 
* @brief    获取数据会议请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_GetDCSCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetDCSCfgReq(IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_CFGGetPriVidEncParamCfgReq 
* 
* @brief    获取主视频编码器参数请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_GetPriVidEncParamCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetPriVidEncParamCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
*  KdvMt_CFGGetAssVidEncParamCfgReq 
* 
* @brief    获取辅视频编码器参数请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_GetAssVidEncParamCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetAssVidEncParamCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
*  KdvMt_CFGGetVideoDecParamCfgReq 
* 
* @brief    获取视频解码器参数请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_GetVideoDecParamCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetVideoDecParamCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
*  KdvMt_CFGGetPlayAniSoundInIdleCfgReq 
* 
* @brief    获取会议中是否允许播放动画音效请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_GetPlayAniSoundInIdleCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetPlayAniSoundInIdleCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_CFGGetCodecVideoSrcCfgReq 
* 
* @brief    获取视频源请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_GetCodecVideoSrcCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetCodecVideoSrcCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
*  KdvMt_CFGGetShowSystimeTimeCfgReq 
* 
* @brief    获取显示系统时间请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_GetShowSystimeTimeCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetShowSystimeTimeCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
*  KdvMt_CFGGetIsH323StackStandRtReq 
* 
* @brief    获取323协议栈是否标准的( value: TBOOL32), 标准注册到1719，非标注册到1759请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_GetIsH323StackStandRt_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetIsH323StackStandRtReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
*  KdvMt_CFGGetH323CallingPortRtReq 
* 
* @brief    获取323协议栈侦听端口请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_GetH323CallingPortRt_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetH323CallingPortRtReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
*  KdvMt_CFGGetH264SvcCfgReq 
* 
* @brief    获取H.264 SVC请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_GetH264SvcCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetH264SvcCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );




/**
*  KdvMt_CFGGetLoadAdaptiveVideoCfgReq 
* 
* @brief    获取视频载荷自适应请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_GetLoadAdaptiveVideoCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetLoadAdaptiveVideoCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );




/**
*  KdvMt_CFGGetInnerMcAssVidCfgReq 
* 
* @brief    获取内置mc辅流参数设置请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_GetInnerMcAssVidCfgCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetInnerMcAssVidCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );




/**
*  KdvMt_CFGGetLoginIMRtReq 
* 
* @brief    获取登录IM所需要的参数请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_GetLoginIMParamCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetLoginIMParamCfgReq(  IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_CFGGetCallInRingRtReq 
* 
* @brief    获取播放呼入铃声请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_Hd_GetCallInRingRt_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetCallInRingRtReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );




/**
*  KdvMt_CFGGetCallOutRingRtReq 
* 
* @brief    获取播放呼出铃声请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_Hd_GetCallOutRingRt_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetCallOutRingRtReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );




/**
*  KdvMt_CFGGetKeyboardRingCfgReq 
* 
* @brief    获取播放按键音请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_Hd_GetKeyboardRingCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetKeyboardRingCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );




/**
*  KdvMt_CFGGetVGAImageAdjustCfgReq 
* 
* @brief    获取VGA图像调节请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_Hd_GetVGAImageAdjustCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetVGAImageAdjustCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );




/**
*  KdvMt_CFGGetVideoSrcTagCfgReq 
* 
* @brief    获取视频源标签请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_Hd_GetVideoSrcTagCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetVideoSrcTagCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
*  KdvMt_CFGGetSnapShotFtpCfgCfgReq 
* 
* @brief    获取快照FTP请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_Hd_GetSnapShotFtpCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetSnapShotFtpCfgCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_CFGGetVgaOutBrightCfgReq 
* 
* @brief    获取VGA输出亮度请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_Hd_GetVgaOutBrightCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetVgaOutBrightCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGGetVgaOutContrastCfgReq 
* 
* @brief    获取VGA输出对比度请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_Hd_GetVgaOutContrastCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetVgaOutContrastCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_CFGGetVgaOutSaturationCfgReq 
* 
* @brief    获取VGA输出饱和度请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_Hd_GetVgaOutSaturationCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetVgaOutSaturationCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_GetVidImgParamReq
*
* @brief    查询视频亮度、对比度、饱和度请求
*
* @param    [in]   emCodecType   编解码类型
* @param    [in]   emCodecIdx   哪一路
* @param    [in]   emMsgSrc    EmImgParam_Api
* @return   u32    0：成功      其他错误码
* @note 更新通知：Ev_MtApi_Base_Hd_GetVidImgParam_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_GetVidImgParamReq( IN CONST EmCodecComponent_Api emCodecType, IN CONST EmCodecComponentIndex_Api emCodecIdx, 
	IN CONST EmImgParam_Api emMsgSrc, IN CONST SessionID dwSSID  = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGGetPresetNameInfoCfgReq 
* 
* @brief    获取预置位名称设置请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_Hd_GetPresetNameInfoCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetPresetNameInfoCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**********用户设置**************/

/**
*  KdvMt_CFGGetHDDispModeCfgReq 
* 
* @brief    获取双流显示模式请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_Hd_GetDispModeCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetHDDispModeCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_CFGGetHDResOutputCfgReq 
* 
* @brief    获取视频输出制式请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_Hd_GetHDResOutputCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetHDResOutputCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_CFGGetIsHDAutoPIPCfgReq 
* 
* @brief    获取是否开启自动画中画请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_Hd_GetAutoPIPCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetIsHDAutoPIPCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_CFGGetHDCallInRingCfgReq 
* 
* @brief    获取呼入铃声请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_Hd_GetCallInRingCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetHDCallInRingCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_CFGGetHDCallOutRingCfgReq 
* 
* @brief    获取呼出铃声请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_Hd_GetCallOutRingCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetHDCallOutRingCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_CFGGetHDPresetBannerCfgReq 
* 
* @brief    获取当前使用的横幅id号请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_Hd_GetEnablePresetBannerCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetHDPresetBannerCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_CFGGetHDOsdBannerInfoCfgReq 
* 
* @brief    获取横幅配置请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_Hd_GetOsdBannerInfoCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetHDOsdBannerInfoCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGGetHDMtcBannerInfoCfgReq 
* 
* @brief    获取Mtc横幅配置请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_Hd_GetMtcBannerInfoCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetHDMtcBannerInfoCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_CFGGetHDLabelInfoCfgReq 
* 
* @brief    获取台标配置请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_Hd_GetLabelInfoCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetHDLabelInfoCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_CFGGetHDAutoSleepCfgReq 
* 
* @brief    获取自动待机配置请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_Hd_GetAutoSleepCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetHDAutoSleepCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_CFGGetHDSysTimeCfgReq 
* 
* @brief    获取时间配置请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_Hd_GetSysTimeCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetHDSysTimeCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**********管理员设置**********/

/**
*  KdvMt_CFGGetHDMicGainCfgReq 
* 
* @brief    获取麦克增益请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_Hd_GetMicGainCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetHDMicGainCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_CFGGetHDAecDebugCfgReq 
* 
* @brief    获取回声抵消自适应请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_Hd_GetAecDebugCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetHDAecDebugCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_CFGGetHDAudInPortListCfgReq 
* 
* @brief    获取音频输入接口请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_Hd_GetAudInPortListCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetHDAudInPortListCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_CFGGetHDAudOutPortListCfgReq 
* 
* @brief    获取音频输出接口请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_Hd_GetAudOutPortListCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetHDAudOutPortListCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_CFGGetHDPri1stVidInPortCfgReq 
* 
* @brief    获取第一路主视频输入端口请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_Hd_GetPri1stVidInPortCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetHDPri1stVidInPortCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
*  KdvMt_CFGGetHDPri2ndVidInPortCfgReq 
* 
* @brief    获取第二路主辅视频输入端口请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_Hd_GetPri2ndVidInPortCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetHDPri2ndVidInPortCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
*  KdvMt_CFGGetHDAssVidInPortCfgReq 
* 
* @brief    获取辅视频输入端口请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_Hd_GetAssVidInPortCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetHDAssVidInPortCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );




/**
*  KdvMt_CFGGetHDMultiVideoCfgReq 
* 
* @brief    获取多视或多流请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_Hd_GetMultiVideoCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetHDMultiVideoCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_CFGGetHDVideoMatrixSchemeListCfgReq 
* 
* @brief    获取视频矩阵请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_Hd_GetVideoMatrixSchemeCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetHDVideoMatrixSchemeListCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_CFGGetHDLastDisplayListCfgReq 
* 
* @brief    获取无图像显示策略请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_Hd_GetLastDisplayCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetHDLastDisplayListCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_CFGGetHDImageNoiseLevelCfgReq 
* 
* @brief    获取图像降噪等级请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_Hd_GetImageNoiseLevelCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetHDImageNoiseLevelCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_CFGGetHDImageEnhancementCfgReq 
* 
* @brief    获取图像增强开关请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_Hd_GetImageEnhancementCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetHDImageEnhancementCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_CFGGetHDPri1stDeformationTensileCfgReq 
* 
* @brief    获取第一路主视频变形拉伸(请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_Hd_GetPri1stDeformationTensileCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetHDPri1stDeformationTensileCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_CFGGetHDPri2ndDeformationTensileCfgReq 
* 
* @brief    获取第二路主视频变形拉伸请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_Hd_GetPri2ndDeformationTensileCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetHDPri2ndDeformationTensileCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_CFGGetHDAssDeformationTensileCfgReq 
* 
* @brief    获取辅视频变形拉伸请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_Hd_GetAssDeformationTensileCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetHDAssDeformationTensileCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_CFGGetHDPri1stGeometricScalingCfgReq 
* 
* @brief    获取第一路主视频等比缩放请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_Hd_GetPri1stGeometricScalingCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetHDPri1stGeometricScalingCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_CFGGetHDPri2ndGeometricScalingCfgReq 
* 
* @brief    获取第二路主视频等比缩放请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_Hd_GetPri2ndGeometricScalingCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetHDPri2ndGeometricScalingCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
*  KdvMt_CFGGetHDAssGeometricScalingCfgReq 
* 
* @brief    获取辅视频等比缩放请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_Hd_GetAssGeometricScalingCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetHDAssGeometricScalingCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
*  KdvMt_CFGGetHDEdgePixelCfgReq 
* 
* @brief    获取第一路主视频裁边像素请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_Hd_GetEdgePixelCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetHDEdgePixelCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );




/**
*  KdvMt_CFGGetHDCameraListCfgReq 
* 
* @brief    获取摄像机配置请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_Hd_GetCameraListCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetHDCameraListCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );




/**
*  KdvMt_CFGGetHDSerialCtrlCfgReq 
* 
* @brief    获取串口配置请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_Hd_GetSerialCtrlCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetHDSerialCtrlCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );





//网络设置相关
/**
* KdvMt_CFGGetRouteCfgListCfgReq
* 
* @brief    获取路由配置信息
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_Mtapi_Base_Hd_GetRouteCfgListCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetRouteCfgListCfgReq(IN CONST SessionID dwSSID = KMTAPI_DEF_SSID);



/**
*  KdvMt_CFGGetEthWorkModeListCfgReq 
* 
* @brief    获取以太网工作模式请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_Hd_GetEthWorkModeListCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetEthWorkModeListCfgReq(IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );





/**
*  KdvMt_CFGGetEthnetCfgReq 
* 
* @brief    获取以太网信息请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_Hd_GetEthnetCfgCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetEthnetCfgReq(IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );





/**
*  KdvMt_CFGGetEthPPPoECfgReq 
* 
* @brief    获取PPPoE拨号信息请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_Hd_GetEthPPPoECfgCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetEthPPPoECfgReq(IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );





/**
*  KdvMt_CFGGetWifiWorkModeCfgReq 
* 
* @brief    获取Wifi工作模式请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_Hd_GetWifiWorkModeCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetWifiWorkModeCfgReq(IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );




/**
*  KdvMt_CFGGetWifiApCfgReq 
* 
* @brief    获取Wifi-AP配置信息请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_Hd_GetWifiApCfgCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetWifiApCfgReq(IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );





/**
*  KdvMt_CFGGetWifiClientCfgReq 
* 
* @brief    获取Wifi作为client已连接后的配置信息请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_Hd_GetWifiClientCfgCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetWifiClientCfgReq(IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGGetE1CfgReq 
* 
* @brief    获取E1的配置信息请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_HD_GetE1CfgCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetE1CfgReq(IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGGetWifiCurConnectedInfoRtReq 
* 
* @brief    获取作为client连接后的详细信息请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_Hd_GetWifiCurConnectedInfoRt_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetWifiCurConnectedInfoRtReq(IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );




/**
*  KdvMt_CFGGetMobileDataWorkModeCfgReq 
* 
* @brief    获取移动数据3G/4G工作模式请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_Hd_GetMobileDataWorkModeCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetMobileDataWorkModeCfgReq(IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );





/**
*  KdvMt_CFGGetMobileDataConnectedInfoRtReq 
* 
* @brief    获取移动数据3G/4G连接后的详细信息请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_Hd_GetMobileDataConnectedInfoRt_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetMobileDataConnectedInfoRtReq(IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );





/**
*  KdvMt_CFGGetNetUsedInfoRtReq 
* 
* @brief    获取当前对外通讯的网络IP详细信息请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_Hd_GetNetUsedInfoRt_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetNetUsedInfoRtReq(IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGGetLoginApsParamCfgReq 
* 
* @brief    获取登录APS所需要的参数请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MTApi_Base_GetApsLoginParamCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetLoginApsParamCfgReq(  IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


//硬终端产品线_end

//by-lw-part-rmtdatashare end


//by-lw-part-datashare start




/**
*  KdvMt_CFGSetMCCfgCmd 
* 
* @brief    启用内置MC配置命令
* 
* @param	[in] tCfg    内置MC启用配置
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_SetMCCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetMCCfgCmd( IN CONST BOOL32 bEnable, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );




/**
*  KdvMt_CFGIsUsedMC 
* 
* @brief 是否启用内置MC
* 
* @param    [out]  bUseMC     TRUE: 启用 FALSE:未启用
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MtApi_Base_SetMCCfg_Ntf, Ev_MtApi_Base_GetMCCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGIsUsedMC( OUT BOOL32& bUseMC, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
*  KdvMt_CFGSetAudioPrecedenceCfgCmd 
* 
* @brief    设置音质优先配置命令
* 
* @param	[in] tCfg    音质优先配置
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_SetAudioPrecedenceCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetAudioPrecedenceCfgCmd( IN CONST BOOL32 bCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );




/**
*  KdvMt_CFGGetAudioPrecedence 
* 
* @brief 获取音质优先命令
* 
* @param    [out]  bUsedAudioPrecedence TRUE:启用 FALSE:未启用
* @param    [in]   dwSSID       MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MtApi_Base_AudioPrecedenceCfg_Ntf, Ev_MtApi_Base_GetAudioPrecedenceCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetAudioPrecedence( OUT BOOL32& emCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID ); 


// 设置音频优选 emMt_Cfg_AudioPrior
/**
*  KdvMt_CFGSetAudioPriorCfgCmd 
* 
* @brief 设置音频优选
* 
* @param    [in]   tCfg         音频优选
* @param    [in]   dwSSID       MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 响应通知：Ev_MtApi_Base_SetAudioPriorCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetAudioPriorCfgCmd( IN CONST TMTAudioPriorCfg_Api &tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



// 获取音频优先模式 emMt_Cfg_AudioPrior
/**
*  KdvMt_CFGGetAudioPriorCfg 
* 
* @brief 获取音频优先模式
* 
* @param    [out]  tCfg 音频优先
* @param    [in]   dwSSID       MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MtApi_Base_SetAudioPriorCfg_Ntf, Ev_MtApi_Base_GetAudioPriorCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetAudioPriorCfg( OUT TMTAudioPriorCfg_Api &tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID);


/**
*  KdvMt_CFGSetPriVidPriorCfgCmd 
* 
* @brief 设置主视频优选
* 
* @param    [in]   tCfg 主视频优选
* @param    [in]   dwSSID       MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 响应通知：Ev_MtApi_Base_SetPriVidPriorCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetPriVidPriorCfgCmd( IN CONST TMTPriVidPriorCfg_Api &tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_CFGGetPriVidPriorCfg 
* 
* @brief 获取主视频优选
* 
* @param    [out]  tCfg 主视频优选
* @param    [in]   dwSSID       MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MtApi_Base_SetPriVidPriorCfg_Ntf, Ev_MtApi_Base_GetPriVidPriorCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetPriVidPriorCfg( OUT TMTPriVidPriorCfg_Api &tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
*  KdvMt_CFGSetPcAssVideoPriorCfgCmd 
* 
* @brief 设置Pc辅视频优选
* 
* @param    [in]   tCfg 辅视频优选
* @param    [in]   dwSSID       MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 响应通知：Ev_MtApi_Base_SetPcAssVidPriorCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetPcAssVideoPriorCfgCmd( IN CONST TVidPriorParam_Api &tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
*  KdvMt_CFGGetPcAssVideoPriorCfg 
* 
* @brief 获取辅流优选
* 
* @param    [out]  tCfg 辅视频优选
* @param    [in]   dwSSID       MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MtApi_Base_SetPcAssVidPriorCfg_Ntf, Ev_MtApi_Base_GetPcAssVidPriorCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetPcAssVideoPriorCfg( OUT TVidPriorParam_Api &tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
*  KdvMt_CFGSetVidAssVideoPriorCfgCmd 
* 
* @brief 设置Vid辅视频优选
* 
* @param    [in]   tCfg 辅视频优选
* @param    [in]   dwSSID       MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 响应通知：Ev_MtApi_Base_SetVidAssVidPriorCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetVidAssVideoPriorCfgCmd( IN CONST TVidPriorParam_Api &tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
*  KdvMt_CFGGetVidAssVideoPriorCfg 
* 
* @brief 获取辅流优选
* 
* @param    [out]  tCfg 辅视频优选
* @param    [in]   dwSSID       MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MtApi_Base_SetVidAssVidPriorCfg_Ntf, Ev_MtApi_Base_GetVidAssVidPriorCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetVidAssVideoPriorCfg( OUT TVidPriorParam_Api &tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );




/**
*  KdvMt_CFGGetCallInfoRt 
* 
* @brief 获取呼叫信息
* 
* @param    [out]  tCfg 呼叫信息
* @param    [in]   dwSSID       MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：emMt_MtApi_SetCallInfoRt_Ntf, Ev_MtApi_GetCallInfoRt_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetCallInfoRt( OUT TMtCallLinkSate_Api &tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
*  KdvMt_CFGSetChairmanOperateCfgCmd 
* 
* @brief    设置主席操作配置命令
* 
* @param	[in] bEnable  是否启用主席操作配置
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_SetChrmanOperateCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetChairmanOperateCfgCmd( IN CONST BOOL32  bEnable, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );




/**
*  KdvMt_CFGIsUsedChairmanOptCtrl 
* 
* @brief 是否启用主席操作
* 
* @param    [out]  bUsedChairmanOpt TRUE:启用 FALSE:未启用
* @param    [in]   dwSSID       MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MtApi_Base_SetChrmanOperateCfg_Ntf, Ev_MtApi_Base_GetChrmanOperateCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGIsUsedChairmanOptCtrl( OUT BOOL32& bUsedChairmanOpt, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
*  KdvMt_CFGSetShowConfStateCfgCmd 
* 
* @brief    设置是否会议状态显示配置命令
* 
* @param	[in] bEnable  是否显示会议状态配置
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_SetShowConfStateCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetShowConfStateCfgCmd( IN CONST BOOL32  bEnable, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );




/**
*  KdvMt_CFGIsUsedShowConfState 
* 
* @brief 是否显示会议状态
* 
* @param    [out]  bUsedShowConfState TRUE:启用 FALSE:未启用
* @param    [in]   dwSSID       MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MtApi_Base_SetShowConfStateCfg_Ntf, Ev_MtApi_Base_GetShowConfStateCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGIsUsedShowConfState( OUT BOOL32& bUsedShowConfState, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
*  KdvMt_CFGSetStaticPicCfgCmd 
* 
* @brief    设置是否启用发送静态图片配置命令
* 
* @param	[in] bEnable     是否发送静态图片配置
* @param	[in] pszPicPath  图片路径和文件名，仅对windows有效
* @param    [in] dwSSID      MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_SetStaticPicCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetStaticPicCfgCmd( IN CONST BOOL32  bEnable, IN CONST s8 *pszPicPath, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );




/**
*  KdvMt_CFGIsUsedSendStaticPic 
* 
* @brief 是否启用发送静态图片
* 
* @param    [out]  bUsedSendStaticPic TRUE:启用 FALSE:未启用
* @param    [in]   dwSSID       MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MtApi_Base_SetStaticPicCfg_Ntf, Ev_MtApi_Base_GetStaticPicCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGIsUsedSendStaticPic( OUT BOOL32& bUsedSendStaticPic, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_CFGSetTelephoneCfgCmd 
* 
* @brief    设置是否启用电话功能配置命令
* 
* @param	[in] bEnable  是否启用电话功能配置
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_SetTelephoneCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetTelephoneCfgCmd( IN CONST BOOL32  bEnable, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );




/**
*  KdvMt_CFGIsUsedUsedTelphonc 
* 
* @brief 是否启用电话呼叫
* 
* @param    [out]  bUsedTelphonc TRUE:启用 FALSE:未启用
* @param    [in]   dwSSID       MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MtApi_Base_SetTelephoneCfg_Ntf, Ev_MtApi_Base_GetTelephoneCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGIsUsedUsedTelphonc( OUT BOOL32& bUsedTelphonc, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
*  KdvMt_CFGSetAutoLoginCfgCmd 
* 
* @brief    设置是否自动登录服务器配置命令
* 
* @param	[in] bEnable 是否自动登录服务器配
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_SetAutoLoginCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetAutoLoginCfgCmd( IN CONST BOOL32 bEnable, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );




/**
*  KdvMt_CFGIsAutoLogin 
* 
* @brief 是否启用自动登录服务器
* 
* @param    [out]  bIsAutoLogin   TRUE: 自动登录 FALSE:不自动登录
* @param    [in]   dwSSID         MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MtApi_Base_SetAutoLoginCfg_Ntf, Ev_MtApi_Base_GetAutoLoginCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGIsAutoLogin( OUT BOOL32& bIsAutoLogin, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID ); 



/**
*  KdvMt_CFGSetIncomingCallFWCfgCmd 
* 
* @brief    设置是否启用来电防火墙配置命令
* 
* @param	[in] bEnable 是否启用来电防火墙配置
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_SetUseCallFWCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetIncomingCallFWCfgCmd( IN CONST BOOL32 bEnable, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );




/**
*  KdvMt_CFGIsUsedCallFirewall 
* 
* @brief 是否启用来电防火墙
* 
* @param    [out]  bIsAutoLogin   TRUE:启用 FALSE:未启用
* @param    [in]   dwSSID         MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MtApi_Base_IsUseCallFWCfg_Ntf, Ev_MtApi_Base_GetIsUseCallFWCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGIsUsedCallFirewall( OUT BOOL32& bUseFW, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID ); 



/**
*  KdvMt_CFGSetBandwidthCheckCfgCmd 
* 
* @brief    设置当前是否启用带宽检测配置命令
* 
* @param	[in] bEnable 是否启用带宽检测配置
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_SetBandWidthTestCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetBandwidthCheckCfgCmd( IN CONST BOOL32 bEnable, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );




/**
*  KdvMt_CFGIsAutoBandwidthCheck 
* 
* @brief 是否启用自动带宽检测
* 
* @param    [out]  bAutoCheck   TRUE:启用 FALSE:未启用
* @param    [in]   dwSSID       MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MtApi_Base_IsUseBandwidthTestCfg_Ntf, Ev_MtApi_Base_GetIsUseBandwidthTestCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGIsAutoBandwidthCheck( OUT BOOL32& bAutoCheck, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID ); 



/**
*  KdvMt_CFGSetAssStreamSrcAdjustCfgCmd 
* 
* @brief    设置是否启用自动双流源配置命令
* 
* @param	[in] tCfg    是否启用自动双流源配置
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_SetDualStramSrcAdjCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetAssStreamSrcAdjustCfgCmd( IN CONST BOOL32 bEnable, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );




/**
*  KdvMt_CFGIsUsedAssStreamSrcAuto 
* 
* @brief 是否启用启动双流源
* 
* @param    [out]  bUsed      TRUE:启用 FALSE:未启用
* @param    [in]   dwSSID     MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MtApi_Base_DualStreamSrcAdjustCfg_Ntf, Ev_MtApi_Base_GetDualStreamSrcAdjustCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGIsUsedAssStreamSrcAuto( OUT BOOL32& bUsed, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID ); 




/**
*  KdvMt_CFGSetCallProtocolCfgCmd 
* 
* @brief    设置呼叫协议类型配置命令
* 
* @param	[in] emProtocol  呼叫协议类型配置
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_SetCallProtocolCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetCallProtocolCfgCmd( IN CONST EmConfProtocol_Api  emProtocol, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
*  KdvMt_CFGGetConfCallProtocol 
* 
* @brief 获取呼叫协议类型
* 
* @param    [out]  emProtocol   呼叫协议类型
* @param    [in]   dwSSID       MT会话ID 
* @return   u32  0：成功获取， 其他：错误码
*
* @note 更新通知：Ev_MtApi_Base_SetCallProtocolCfg_Ntf, Ev_MtApi_Base_GetCallProtocolCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetConfCallProtocol( OUT EmConfProtocol_Api& emProtocol, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID ); 


/**
*  KdvMt_CFGSetConfEncryptTypeCfgCmd 
* 
* @brief    设置加密类型命令
* 
* @param	[in] emEncrypt  加密类型
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_SetEncryptTypeCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetConfEncryptTypeCfgCmd( IN CONST EmEncryptArithmetic_Api emEncrypt, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_CFGGetConfEncryptTypeCfg 
* 
* @brief 获取会议加密类型
* 
* @param    [out]  emProtocol   加密类型
* @param    [in]   dwSSID       MT会话ID 
* @return   u32  0：成功获取， 其他：错误码
*
* @note 更新通知：Ev_MtApi_Base_SetEncryptTypeCfg_Ntf, Ev_MtApi_Base_GetEncryptTypeCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetConfEncryptTypeCfg( OUT EmEncryptArithmetic_Api& emEncrypt, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID ); 

 


/**
*  KdvMt_CFGSetAudVolInCfgCmd 
* 
* @brief    设置音频输入音量配置命令,音量的范围为[0,31],对应好上层的进度条
* 
* @param	[in] dwVolIn  输入音量配置
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_SetAudVolInCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetAudVolInCfgCmd( IN CONST u32 dwVolIn, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );




/**
*  KdvMt_CFGGetAudInVolCfg 
* 
* @brief 获取音频输入音量,音量的范围为[0,31],对应好上层的进度条
* 
* @param    [out]  dwAudInVol  音频输入音量
* @param    [in]   dwSSID     MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MtApi_Base_SetAudVolInCfg_Ntf, Ev_MtApi_Base_GetAudVolInCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetAudInVolCfg( OUT u32& dwAudInVol, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );




/**
*  KdvMt_CFGSetAudVolOutCfgCmd 
* 
* @brief    设置音频输出音量配置命令,音量的范围为[0,31],对应好上层的进度条
* 
* @param	[in] dwVolOut  输出音量配置
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_SetAudVolOutCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetAudVolOutCfgCmd( IN CONST u32 dwVolOut, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );




/**
*  KdvMt_CFGGetAudOutVolCfg 
* 
* @brief 获取音频输出音量,音量的范围为[0,31],对应好上层的进度条
* 
* @param    [out]  dwAudOutVol 音频输出音量
* @param    [in]   dwSSID     MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MtApi_Base_SetAudVolOutCfg_Ntf, Ev_MtApi_Base_GetAudVolOutCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetAudOutVolCfg( OUT u32& dwAudOutVol, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
*  KdvMt_CFGSetKeepAliveItrvlCfgCmd 
* 
* @brief    设置断链检测时间间隔配置(秒)
* 
* @param	[in] dwSec   断链检测时间间隔
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_SetKeepAliveItrvlCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetKeepAliveItrvlCfgCmd( IN CONST u32 dwSec, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );




/**
*  KdvMt_CFGGetKeepAliveIntervalCfg 
* 
* @brief 获取断链检测时间配置
* 
* @param    [out]  dwKeepAliveItrvl 断链检测时间配置
* @param    [in]   dwSSID     MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MtApi_Base_SetKeepAliveItrvlCfg_Ntf, Ev_MtApi_Base_GetKeepAliveItrvlCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetKeepAliveIntervalCfg( OUT u32& dwKeepAliveItrvl, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_CFGSetSipKeepAliveItrvlCfgCmd 
* 
* @brief    设置Sip断链检测时间间隔配置(秒)
* 
* @param	[in] dwSec   断链检测时间间隔
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_SetSipKeepAliveItrvlCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetSipKeepAliveItrvlCfgCmd( IN CONST u32 dwSec, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_CFGGetSipKeepAliveIntervalCfg 
* 
* @brief 获取Sip断链检测时间配置
* 
* @param    [out]  dwKeepAliveItrvl 断链检测时间配置
* @param    [in]   dwSSID     MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MtApi_Base_SetSipKeepAliveItrvlCfg_Ntf, Ev_MtApi_Base_GetSipKeepAliveItrvlCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetSipKeepAliveIntervalCfg( OUT u32& dwKeepAliveItrvl, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_CFGGetConfCallRate 
* 
* @brief 获取会议呼叫码率
* 
* @param    [out]  dwRate     会议呼叫码率
* @param    [in]   dwSSID     MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MtApi_Base_SetCallRateLvCfg_Ntf, Ev_MtApi_Base_GetCallRateLvCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetConfCallRate( OUT u32& dwRate, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID ); 



/**
*  KdvMt_CFGSetMTUCfgCmd 
* 
* @brief 设置MTU TCP/IP最大传输单元配置命令
* 
* @param	[in] dwMTU   传输单元配置值
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_SetMTUCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetMTUCfgCmd( IN CONST u32 dwMTU, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );




/**
*  KdvMt_CFGGetMTUCfg 
* 
* @brief 获取TCP/IP最大传输单元MTU
* 
* @param    [out]  dwMTU      最大传输单元MTU
* @param    [in]   dwSSID     MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MtApi_Base_SetMTUCfg_Ntf, Ev_MtApi_Base_GetMTUCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetMTUCfg( OUT u32& dwMTU, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_CFGRestoreDefaultCfgInfo 
* 
* @brief  配置还原默认值
* 
* @param    [in]  TMTRestoreDefaultCfgInfo_Api     还原默认值的信息
* @param    [in]   dwSSID     MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGRestoreDefaultCfgInfo( IN CONST TMTRestoreDefaultCfgInfo_Api &tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
*  KdvMt_CFGSetIPQoSCfgCmd 
* 
* @brief 设置Qos配置命令
* 
* @param	[in] tCfg    Qos配置信息
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_SetIPQoSCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetIPQoSCfgCmd( IN CONST TMTIPQoS_Api& tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
*  KdvMt_CFGGetIPQosCfg 
* 
* @brief   获取Qos配置信息
* 
* @param    [out]  tCfg       Qos配置信息
* @param    [in]   dwSSID     MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MtApi_Base_SetIPQoSCfg_Ntf, Ev_MtApi_Base_GetIPQoSCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetIPQosCfg( OUT TMTIPQoS_Api& tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID ); 




/**
*  KdvMt_CFGSetNatCfgCmd 
* 
* @brief 设置NAT配置命令
* 
* @param	[in] tCfg    NAT配置信息
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_SetNATCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetNatCfgCmd( IN CONST TMTNat_Api& tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
*  KdvMt_CFGGetNatCfg 
* 
* @brief   获取NAT配置
* 
* @param    [out]  tCfg      NAT配置
* @param    [in]   dwSSID     MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MtApi_Base_SetNATCfg_Ntf, Ev_MtApi_Base_GetNATCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetNatCfg( OUT TMTNat_Api& tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGGetCurVidCapDevCfg 
* 
* @brief   TL获取当前视频采集设备命令 (仅WIN32)
* 
* @param    [out]  tCfg       视频采集设备
* @param    [in]   dwSSID     MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetCurVidCapDevCfg( OUT TDevInfo_Api & tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGGetXMPPCfg 
* 
* @brief   获取XMPP登录配置
* 
* @param    [out]  tCfg       XMPP登录配置
* @param    [in]   dwSSID     MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MtApi_Base_GetXNURt_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetXMPPCfg( OUT TMtXMPPInfo_Api& tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGGetNSRtCfg 
* 
* @brief   获取NS IP
* 
* @param    [out]  tCfg       NS IP
* @param    [in]   dwSSID     MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MtApi_Base_GetNSRt_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetNSRtCfg( OUT TMtNSADDRInfo_Api& tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
*  KdvMt_CFGSetCSUCfgCmd 
* 
* @brief    注册CSU服务器配置命令 (GK)
* 
* @param	[in] tCfg    CSU服务器配置
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_SetCSUCfg_Ntf, Ev_MtApi_Vc_RegResult_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetCSUCfgCmd( IN CONST TMtCSUAddr_Api& tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
*  KdvMt_CFGGetCSUAdrCfg 
* 
* @brief   获取CSU地址配置
* 
* @param    [out]  tCfg       CSU地址配置
* @param    [in]   dwSSID     MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MtApi_Base_SetCSUCfg_Ntf, Ev_MtApi_Base_GetCSUCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetCSUAdrCfg( OUT TMtCSUAddr_Api& tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );




/**
*  KdvMt_CFGSetGKCfgCmd 
* 
* @brief    手动设置gk地址，底层只是保存在数据库中，不做其他处理，如果要注册，需要调用KdvMt_CFGSetCSUCfgCmd
* 
* @param	[in] tCfg    CSU服务器配置
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_SetGKCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetGKCfgCmd( IN CONST TMtCSUAddr_Api& tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
*  KdvMt_CFGGetGKCfg 
* 
* @brief    获取手动设置的gk地址
* 
* @param    [out]  tCfg       CSU地址配置
* @param    [in]   dwSSID     MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetGKCfg( OUT TMtCSUAddr_Api& tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_CFGGetGKCfgReq 
* 
* @brief   请求获取手动设置的gk地址
* 
* @param    [out]  tCfg       CSU地址配置
* @param    [in]   dwSSID     MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MtApi_Base_SetGKCfg_Ntf, Ev_MtApi_Base_GetGKCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetGKCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );




/**
*  KdvMt_CFGSetNTSCfgCmd 
* 
* @brief    设置测速服务器配置命令
* 
* @param	[in] tCfg    测速服务器配置
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_SetNTSCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetNTSCfgCmd( IN CONST TMtNTSAddr_Api& tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGSetNtsManuCfgCmd 
* 
* @brief    设置测速服务器手动配置命令
* 
* @param	[in] tCfg    测速服务器配置
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_SetNtsManuCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetNtsManuCfgCmd( IN CONST TMtNTSAddr_Api& tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGGetNTSAdrCfg 
* 
* @brief   获取测速服务器配置
* 
* @param    [out]  tCfg       测速服务器配置
* @param    [in]   dwSSID     MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MtApi_Base_SetNTSCfg_Ntf, Ev_MtApi_Base_GetNTSCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetNTSAdrCfg( OUT TMtNTSAddr_Api& tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGGetNtsManuAdrCfg 
* 
* @brief   获取测速服务器手动配置
* 
* @param    [out]  tCfg       测速服务器配置
* @param    [in]   dwSSID     MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MtApi_Base_SetNtsManuCfg_Ntf, Ev_MtApi_Base_GetNtsManuCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetNtsManuAdrCfg( OUT TMtNTSAddr_Api& tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGSetXAPListCfgCmd 
* 
* @brief 设置XAPList配置命令
* 
* @param	[in] tCfg    XAPList配置信息
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_SetXAPListCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetXAPListCfgCmd( IN CONST TMtXAPSvrList_Api& tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
*  KdvMt_CFGGetXAPSvrList 
* 
* @brief   获取XAP服务器列表
* 
* @param    [out]  tCfg      XAP服务器列表
* @param    [in]   dwSSID     MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MtApi_Base_SetXAPListCfg_Ntf, Ev_MtApi_Base_GetXAPListCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetXAPSvrList( OUT TMtXAPSvrList_Api& tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
*  KdvMt_CFGGetCurUsdXAPSvrRtCfg 
* 
* @brief   获取当前使用的XAP服务器信息
* 
* @param    [out]  tCfg      当前使用的XAP服务器信息
* @param    [in]   dwSSID     MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MtApi_Base_SetCurXAPCfg_Ntf, Ev_MtApi_Base_GetCurXAPCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetCurUsdXAPSvrRtCfg( OUT TMtAPSSvrAddr_Api& tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_CFGSetSUSCfgCmd 
* 
* @brief    设置SUS服务器配置命令
* 
* @param	[in] tCfg    SUS服务器配置
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_SetSUSCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetSUSCfgCmd( IN CONST TMTSUSAddr_Api& tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGSetSusManuCfgCmd 
* 
* @brief    设置SUS服务器手动配置命令
* 
* @param	[in] tCfg    SUS服务器配置
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_SetSusManuCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetSusManuCfgCmd( IN CONST TMTSUSAddr_Api& tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGGetSUSSvrCfg 
* 
* @brief   获取SUS升级服务器配置信息
* 
* @param    [out]  tCfg      SUS升级服务器配置信息
* @param    [in]   dwSSID     MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MtApi_Base_SetSUSCfg_Ntf, Ev_MtApi_Base_GetSUSCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetSUSSvrCfg( OUT TMTSUSAddr_Api& tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGGetSusManuSvrCfg 
* 
* @brief   获取SUS升级服务器手动配置信息
* 
* @param    [out]  tCfg      SUS升级服务器配置信息
* @param    [in]   dwSSID     MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MtApi_Base_SetSusManuCfg_Ntf, Ev_MtApi_Base_GetSusManuCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetSusManuSvrCfg( OUT TMTSUSAddr_Api& tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGSetSNMPCfgCmd 
* 
* @brief    设置网管服务器配置命令
* 
* @param	[in] tCfg    网管服务器配置
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_SetNMSCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetSNMPCfgCmd( IN CONST TMtNMAAddr_Api& tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGSetSNMPManuCfgCmd 
* 
* @brief    设置网管服务器手动配置命令
* 
* @param	[in] tCfg    网管服务器配置
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_SetNmsManuCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetSNMPManuCfgCmd( IN CONST TMtNMAAddr_Api& tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGGetNMSSvrCfg 
* 
* @brief   获取网管服务器配置信息
* 
* @param    [out]  tCfg      网管服务器配置信息
* @param    [in]   dwSSID     MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MtApi_Base_SetNMSCfg_Ntf, Ev_MtApi_Base_GetNMSCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetNMSSvrCfg( OUT TMtNMAAddr_Api& tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGGetNmsManuSvrCfg 
* 
* @brief   获取网管服务器手动配置信息
* 
* @param    [out]  tCfg      网管服务器配置信息
* @param    [in]   dwSSID     MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MtApi_Base_SetNmsManuCfg_Ntf, Ev_MtApi_Base_GetNmsManuCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetNmsManuSvrCfg( OUT TMtNMAAddr_Api& tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGSetNTPCfgCmd 
* 
* @brief    设置NTP服务器配置命令
* 
* @param	[in] tCfg    NTP服务器配置
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_SetNTPCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetNTPCfgCmd( IN CONST TMtNTPAddr_Api& tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGSetNtpManuCfgCmd 
* 
* @brief    设置NTP服务器手动配置命令
* 
* @param	[in] tCfg    NTP服务器配置
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_SetNtpManuCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetNtpManuCfgCmd( IN CONST TMtNTPAddr_Api& tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGGetNTPSvrCfg 
* 
* @brief   获取NTP服务器配置信息
* 
* @param    [out]  tCfg      NTP服务器配置信息
* @param    [in]   dwSSID     MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MtApi_Base_SetNTPCfg_Ntf, Ev_MtApi_Base_GetNTPCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetNTPSvrCfg( OUT TMtNTPAddr_Api& tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGGetNtpManuSvrCfg 
* 
* @brief   获取NTP服务器手动配置信息
* 
* @param    [out]  tCfg      NTP服务器配置信息
* @param    [in]   dwSSID     MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MtApi_Base_SetNtpManuCfg_Ntf, Ev_MtApi_Base_GetNtpManuCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetNtpManuSvrCfg( OUT TMtNTPAddr_Api& tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGSetVODCfgCmd 
* 
* @brief    设置VOD服务器配置命令
* 
* @param	[in] tCfg    VOD服务器配置
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_SetVODCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetVODCfgCmd( IN CONST TMtVODSvrCfg_Api& tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
*  KdvMt_CFGGetVODSvrCfg 
* 
* @brief   获取VOD服务器配置信息
* 
* @param    [out]  tCfg      VOD服务器配置信息
* @param    [in]   dwSSID     MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MtApi_Base_SetVODCfg_Ntf, Ev_MtApi_Base_GetVODCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetVODSvrCfg( OUT TMtVODSvrCfg_Api& tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGSetVRSCfgCmd 
* 
* @brief    设置VRS服务器配置命令
* 
* @param	[in] tCfg    VOD服务器配置
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_SetVRSCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetVRSCfgCmd( IN CONST TMtVRSSvrCfg_Api& tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_CFGGetVRSSvrCfg 
* 
* @brief   获取VRS服务器配置信息
* 
* @param    [out]  tCfg      VOD服务器配置信息
* @param    [in]   dwSSID     MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MtApi_Base_SetVODCfg_Ntf, Ev_MtApi_Base_GetVODCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetVRSSvrCfg( OUT TMtVRSSvrCfg_Api& tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_CFGSetStreamPlayerCfgCmd 
* 
* @brief    设置StreamPlayer流媒体配置命令
* 
* @param	[in] tCfg    StreamPlayer流媒体配置
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_SetStreamMediaCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetStreamPlayerCfgCmd( IN CONST TMTStreamMedia_Api& tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
*  KdvMt_CFGGetStreamPlayerCfg 
* 
* @brief   获取流媒体配置信息
* 
* @param    [out]  tCfg       流媒体配置信息
* @param    [in]   dwSSID     MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MtApi_Base_SetStreamMediaCfg_Ntf, Ev_MtApi_Base_GetStreamMediaCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetStreamPlayerCfg( OUT TMTStreamMedia_Api& tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_CFGGetPlatformApiRtCfg 
* 
* @brief   获取API服务器配置信息
* 
* @param    [out]  tCfg       API服务器信息
* @param    [in]   dwSSID     MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MtApi_Base_SetPlatformApiRt_Ntf, Ev_MtApi_Base_GetPlatformApiRt_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetPlatformApiRtCfg( OUT TMtPlatformApiAddr_Api& tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
*  KdvMt_CFGGetMicroBlogRtCfg 
* 
* @brief   获取微博服务器配置信息
* 
* @param    [out]  tCfg       微博服务器信息
* @param    [in]   dwSSID     MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MtApi_Base_SetMicroBlogRt_Ntf, Ev_MtApi_Base_GetMicroBlogRt_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetMicroBlogRtCfg( OUT TMtMicroBlogAddr_Api& tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGSetSipSvrCfgCmd 
* 
* @brief    注册Sip服务器配置命令
* 
* @param	[in] tCfg    Sip服务器配置
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_SetSipSvrCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetSipSvrCfgCmd( IN CONST TMtSipSvrAddr_Api& tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_CFGSetManuSipSvrCfgCmd 
* 
* @brief    手动设置Sip服务器配置命令，底层不注册，只是保存这个配置
* 
* @param	[in] tCfg    Sip服务器配置
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_SetSipSvrManuCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetManuSipSvrCfgCmd( IN CONST TMtSipSvrAddr_Api& tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_CFGGetManuSipSvrCfgCmd 
* 
* @brief    获取手动设置Sip服务器的配置，底层不注册，只是保存这个配置
* 
* @param	[in] tCfg    Sip服务器配置
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetManuSipSvrCfg( OUT TMtSipSvrAddr_Api& tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_CFGGetManuSipSvrCfgReq 
* 
* @brief    获取手动设置Sip服务器的配置，底层不注册，只是保存这个配置
* 
* @param	[in] tCfg    Sip服务器配置
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_SetSipSvrManuCfg_Ntf Ev_MtApi_Base_GetSipSvrManuCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetManuSipSvrCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
*  KdvMt_CFGGetSipSvrCfg 
* 
* @brief   获取Sip服务器配置信息
* 
* @param    [out]  tCfg       Sip服务器配置信息
* @param    [in]   dwSSID     MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MtApi_Base_SetSipSvrCfg_Ntf, Ev_MtApi_Base_GetSipSvrCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetSipSvrCfg( OUT TMtSipSvrAddr_Api& tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );




/**
*  KdvMt_CFGSetSocks5PxyCfgCmd 
* 
* @brief    设置Socket5代理配置命令
* 
* @param	[in] tCfg    Socket5代理配置
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_GetSocks5PxyCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetSocks5PxyCfgCmd( IN CONST TSocks5ProxyCfg_Api& tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
*  KdvMt_CFGGetSocks5ProxyCfg 
* 
* @brief  获取Socket5配置信息
* 
* @param    [out]  tCfg       Socket5配置信息
* @param    [in]   dwSSID     MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MtApi_Base_SetSocks5PxyCfg_Ntf, Ev_MtApi_Base_GetSocks5PxyCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetSocks5ProxyCfg( OUT TSocks5ProxyCfg_Api& tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_CFGGetSvrStateList 
* 
* @brief  获取终端服务器登录状态信息
* 
* @param    [out]  tCfg       终端服务器登录状态信息
* @param    [in]   dwSSID     MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MtApi_Base_SetSvrLoginStatusRt_Ntf, Ev_MtApi_Base_GetSvrLoginStatusRt_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetSvrStateList( OUT TMtSvrStateList_Api& tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_CFGGetUserPrevilegeCfg 
* 
* @brief  获取终端用户登录权限配置信息
* 
* @param    [out]  tCfg       终端用户登录权限配置信息
* @param    [in]   dwSSID     MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MtApi_Base_SetUserPrevilegeRt_Ntf, Ev_MtApi_Base_GetUserPrevilegeRt_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetUserPrevilegeCfg( OUT TMtUserPrevilege_Api& tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
*  KdvMt_CFGGetUserInfoFromApsRt 
* 
* @brief  获取登陆APS返回的用户信息
* 
* @param    [out]  tCfg       登陆APS返回的用户信息
* @param    [in]   dwSSID     MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MtApi_Base_SetUserInfoFromApsRt_Ntf, Ev_MtApi_Base_GetUserInfoFromApsRt_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetUserInfoFromApsRt( OUT TMTUserInfoFromAps_Api& tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
*  KdvMt_CFGSetH323CfgCmd 
* 
* @brief    设置H323配置命令
* 
* @param	[in] tCfg    H323配置
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_SetH323Cfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetH323CfgCmd( IN CONST TMtH323Cfg_Api& tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
*  KdvMt_CFGGetH323Cfg 
* 
* @brief  获取H323配置信息
* 
* @param    [out]  tCfg       H323配置信息
* @param    [in]   dwSSID     MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MtApi_Base_SetH323Cfg_Ntf, Ev_MtApi_Base_GetH323Cfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetH323Cfg( OUT TMtH323Cfg_Api& tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGSetSipCfgCmd 
* 
* @brief    设置SIP配置命令
* 
* @param	[in] tCfg    SIP配置
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_SetSipCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetSipCfgCmd( IN CONST TMtSipCfg_Api& tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_CFGGetSipCfg 
* 
* @brief  获取Sip配置信息
* 
* @param    [out]  tCfg       Sip配置信息
* @param    [in]   dwSSID     MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MtApi_Base_SetHSipCfg_Ntf, Ev_MtApi_Base_GetSipCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetSipCfg( OUT TMtSipCfg_Api& tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_CFGSetLostPackResendCfgCmd 
* 
* @brief    设置丢包重传参数配置命令
* 
* @param	[in] tCfg    丢包重传参数配置
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_SetLostPktResendCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetLostPackResendCfgCmd( IN CONST TPrsParam_Api& tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
*  KdvMt_CFGGetLostPackResendCfg 
* 
* @brief    获取丢包重传参数配置信息
* 
* @param    [out]  tCfg       丢包重传参数配置信息
* @param    [in]   dwSSID     MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MtApi_Base_SetLostPktResendCfg_Ntf, Ev_MtApi_Base_GetLostPktResendCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetLostPackResendCfg( OUT TPrsParam_Api& tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID ); 




/**
*  KdvMt_CFGSetAutoCallCfgCmd 
* 
* @brief    设置自动呼叫配置命令
* 
* @param	[in] tCfg    自动呼叫配置
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_SetAutoCallCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetAutoCallCfgCmd( IN CONST TMTAutoCall_Api& tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
*  KdvMt_CFGGetAutoCallCfg 
* 
* @brief   获取自动呼叫配置信息
* 
* @param    [out]  tCfg       自动呼叫配置信息
* @param    [in]   dwSSID     MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MtApi_Base_SetAutoCallCfg_Ntf, Ev_MtApi_Base_GetAutoCallCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetAutoCallCfg( OUT TMTAutoCall_Api& tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
*  KdvMt_CFGSetAsymmetricNetCfgCmd 
* 
* @brief    设置非对称网络配置命令
* 
* @param	[in] tCfg    非对称网络配置
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_SetAsymmetricNetCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetAsymmetricNetCfgCmd( IN CONST TAsymmetricNetInfo_Api& tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
*  KdvMt_CFGGetAsymmetricNetInfoCfg 
* 
* @brief   获取非对称网络配置信息
* 
* @param    [out]  tCfg       非对称网络配置信息
* @param    [in]   dwSSID     MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MtApi_Base_SetAsymmetricNetCfg_Ntf, Ev_MtApi_Base_GetAsymmetricNetCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetAsymmetricNetInfoCfg( OUT TAsymmetricNetInfo_Api& tCfg , IN CONST SessionID dwSSID = KMTAPI_DEF_SSID ); 


/**
*  KdvMt_CFGSetMCRSParamCfgCmd 
* 
* @brief    设置内置MC丢包重传参数配置命令
* 
* @param	[in] tCfg    内置MC丢包重传参数配置
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_SetMCResendParamCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetMCRSParamCfgCmd( IN CONST TMTMcRSParam_Api& tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
*  KdvMt_CFGGetMcRSParamCfg 
* 
* @brief   获取内置MC丢包重传参数配置信息
* 
* @param    [out]  tCfg       内置MC丢包重传参数配置信息
* @param    [in]   dwSSID     MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MtApi_Base_SetMCResendParamCfg_Ntf, Ev_MtApi_Base_GetMCResendParamCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetMcRSParamCfg( OUT TMTMcRSParam_Api& tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID ); 


/**
*  KdvMt_CFGSetFecInfoCfgCmd 
* 
* @brief    设置FEC配置命令
* 
* @param	[in] tCfg    FEC配置
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_SetFECCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetFecInfoCfgCmd( IN CONST TMTFecInfo_Api& tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );




/**
*  KdvMt_CFGGetFecInfoCfg 
* 
* @brief   获取FEC配置信息
* 
* @param    [out]  tCfg       FEC配置信息
* @param    [in]   dwSSID     MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MtApi_Base_SetFECCfg_Ntf, Ev_MtApi_Base_GetFECCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetFecInfoCfg( OUT TMTFecInfo_Api& tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID ); 


/**
*  KdvMt_CFGSetVidBitRationCfgCmd 
* 
* @brief    设置发送视频码率比例配置命令
* 
* @param	[in] tCfg    视频码率比例配置
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_SetVidBitRationCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetVidBitRationCfgCmd( IN CONST TVidBitRationCfg_Api& tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
*  KdvMt_CFGGetVidBitRationCfg 
* 
* @brief   获取视频发送比例配置信息
* 
* @param    [out]  tCfg       视频发送比例配置信息
* @param    [in]   dwSSID     MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MtApi_Base_SetVidBitRationCfg_Ntf, Ev_MtApi_Base_GetVidBitRationCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetVidBitRationCfg( OUT TVidBitRationCfg_Api& tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
*  KdvMt_CFGSetTerminalNameCfgCmd 
* 
* @brief    设置终端名称信息配置命令
* 
* @param	[in] tCfg    终端名称信息配置
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_SetUserNameCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetTerminalNameCfgCmd( IN CONST TMtTerminalName_Api& tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
*  KdvMt_CFGGetTerminalNameCfg 
* 
* @brief   获取终端名称配置信息
* 
* @param    [out]  tCfg       终端名称配置信息
* @param    [in]   dwSSID     MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MtApi_Base_SetUserNameCfg_Ntf, Ev_MtApi_Base_GetUserNameCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetTerminalNameCfg( OUT TMtTerminalName_Api& tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
*  KdvMt_CFGGetTerminalInfoCfg 
* 
* @brief   获取终端版本厂商相关信息
* 
* @param    [out]  tCfg       终端版本厂商相关信息
* @param    [in]   dwSSID     MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MtApi_Base_SetTerlInfoRt_Ntf, Ev_MtApi_Base_GetTerlInfoRt_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetTerminalInfoCfg( OUT TTerminalInfo_Api& tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );




/**
*  SetUdpTcpBasePortCfg 
* 
* @brief   设置TCP/UDP起始端口配置信息, 随机或者不随机都是从 wTcpBasePort，wUdpBasePort 分配端口 
* 
* @param    [in]  tCfg       TCP/UDP起始端口配置信息
* @param    [in]   dwSSID     MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MtApi_Base_TcpUdpPortCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_SetUdpTcpBasePortCfg( const TTcpUdpBasePortCfg_Api &tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );




/**
*  GetUdpTcpBasePortCfg 
* 
* @brief   获取TCP/UDP起始端口配置信息 随机或者不随机都是从 wTcpBasePort，wUdpBasePort 分配端口 
* 
* @param    [out]  tCfg       TCP/UDP起始端口配置信息
* @param    [in]   dwSSID     MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MtApi_Base_TcpUdpPortCfg_Ntf, Ev_MtApi_Base_GetTcpUdpPortCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_GetUdpTcpBasePortCfg( TTcpUdpBasePortCfg_Api &tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );





/**
*  SetIsUsedFileLogon 
* 
* @brief   配置是否启用文件日志,
* 
* @param    [in]  bUsed       是否启用文件日志, 这个接口请在调用接口KdvMt_CreateSession 之后设置， 并且可以切换
* @param    [in]   dwSSID     MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MtApi_Base_LogStatusCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_SetIsUsedFileLogon( BOOL32 bUsed, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );




/**
*  KdvMt_CFGIsUsedFileLogon 
* 
* @brief   获取是否启用文件日志
* 
* @param    [out]  bUsed       是否启用文件日志
* @param    [in]   dwSSID     MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MtApi_Base_LogStatusCfg_Ntf, Ev_MtApi_Base_GetLogStatusCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGIsUsedFileLogon( BOOL32 &bUsed, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );




/**
*  KdvMt_CFGSetAnswerModeCfgCmd 
* 
* @brief    设置应答模式配置命令
* 
* @param	[in] dwAnswerMode 应答模式配置
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_SetAnswerModeCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetAnswerModeCfgCmd( IN CONST EmAnswerMode_Api & emAnswerMode, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGGetAnswerModeCfg 
* 
* @brief   获取应答模式
* 
* @param    [out]  dwAnswerMode       应答模式
* @param    [in]   dwSSID     MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:Ev_MtApi_Base_SetAnswerModeCfg_Ntf, Ev_MtApi_Base_GetAnswerModeCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetAnswerModeCfg( OUT EmAnswerMode_Api & emAnswerMode, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_CFGSetCallBitRateCfgCmd 
* 
* @brief   设置呼叫码率，设置默认呼叫码率和三种常用的码率， 终端不关心， 只是保存数据
* 
* @param    [in]   tCallRate  呼叫码率
* @param    [in]   dwSSID     MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:Ev_MtApi_Base_SetCallBitrateCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetCallBitRateCfgCmd( IN CONST TMTCallBitRate_Api & tCallRate, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_CFGGetCallBitRateCfg 
* 
* @brief   获取呼叫码率
* 
* @param    [out]  tCallRate 呼叫码率
* @param    [in]   dwSSID     MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:Ev_MtApi_Base_SetCallBitrateCfg_Ntf, Ev_MtApi_Base_GetCallBitrateCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetCallBitRateCfg( OUT TMTCallBitRate_Api & tCallRate, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
*  KdvMt_CFGSetAutoSendSharedContentCfgCmd 
* 
* @brief   设置自动发送内容共享
* 
* @param    [in]   bAuto  是否自动
* @param    [in]   dwSSID     MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:Ev_MtApi_Base_SetAutoSendSharedContentCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetAutoSendSharedContentCfgCmd( IN CONST BOOL32 bAuto, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_CFGGetAutoSendSharedContentCfg 
* 
* @brief   获取自动发送内容共享
* 
* @param    [out]  tCallRate 呼叫码率
* @param    [in]   dwSSID     MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:Ev_MtApi_Base_SetAutoSendSharedContentCfg_Ntf, Ev_MtApi_Base_GetAutoSendSharedContentCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetAutoSendSharedContentCfg( OUT BOOL32 &bAuto, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



//是否允许登陆平台服务 emMt_Cfg_LoginPlatformSrv(value:TBOOL32)
/**
*  KdvMt_CFGSetLoginPlatformSrvCfgCmd 
* 
* @brief   设置是否允许登陆平台服务
* 
* @param    [in]  bLogin 是否允许登陆平台服务
* @param    [in]   dwSSID     MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:Ev_MtApi_Base_SetLoginPlatformSrvCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetLoginPlatformSrvCfgCmd( IN CONST BOOL32 bLogin, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID  );



/**
*  KdvMt_CFGGetLoginPlatformSrvCfg 
* 
* @brief   获取是否允许登陆平台服务
* 
* @param    [out]  bLogin 是否允许登陆平台服务
* @param    [in]   dwSSID     MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:Ev_MtApi_Base_SetLoginPlatformSrvCfg_Ntf, Ev_MtApi_Base_GetLoginPlatformSrvCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetLoginPlatformSrvCfg( OUT BOOL32 &bLogin, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_CFGSetSmoothSendLevelCfgCmd 
* 
* @brief   设置平滑发送等级
* 
* @param    [in]  emCfg 平滑发送等级
* @param    [in]   dwSSID     MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:Ev_MtApi_Base_SetSmoothSendCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetSmoothSendCfgCmd( IN CONST  u32 &dwSmoothSendLevel, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
*  KdvMt_CFGGetSmoothSendLevelCfg 
* 
* @brief   获取平滑发送等级
* 
* @param    [out]  emCfg 平滑发送等级 
* @param    [in]   dwSSID     MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:Ev_MtApi_Base_SetSmoothSendCfg_Ntf, Ev_MtApi_Base_GetSmoothSendCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetSmoothSendCfg( OUT u32 &dwSmoothSendLevel, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
*  KdvMt_CFGSetUseTelnetCfgCmd 
* 
* @brief   设置telnet开关(硬终端ssh )
* 
* @param    [in]  bUse telnet开关 
* @param    [in]   dwSSID     MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:Ev_MtApi_Base_SetUseTelnetCfg_Ntf
*/

KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetUseTelnetCfgCmd( IN CONST BOOL32 bUse, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
*  KdvMt_CFGGetUseTelnetCfg 
* 
* @brief   获取telnet开关
* 
* @param    [out]  bUse telnet开关 
* @param    [in]   dwSSID     MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:Ev_MtApi_Base_SetUseTelnetCfg_Ntf, Ev_MtApi_Base_GetUseTelnetCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetUseTelnetCfg( OUT BOOL32 &bUse, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
*  KdvMt_CFGSetUseHTTPCfgCmd 
* 
* @brief   设置Http开关
* 
* @param    [in]  bUse Http开关 
* @param    [in]   dwSSID     MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:Ev_MtApi_Base_SetUseHTTPCfg_Ntf
*/
//emMt_Cfg_UseHTTP,				///<使用Http开关 (value:TBOOL32)
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetUseHTTPCfgCmd( IN CONST BOOL32 bUse, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );




/**
*  KdvMt_CFGGetUseHTTPCfg 
* 
* @brief   获取Http开关
* 
* @param    [out]  bUse Http开关 
* @param    [in]   dwSSID     MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:Ev_MtApi_Base_SetUseHTTPCfg_Ntf, Ev_MtApi_Base_GetUseHTTPCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetUseHTTPCfg( OUT BOOL32 &bUse, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );




/**
*  KdvMt_CFGSetUseFtpCfgCmd 
* 
* @brief   设置FTP开关
* 
* @param    [in]  bUse FTP开关 
* @param    [in]   dwSSID     MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:Ev_MtApi_Base_SetUseFtpCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetUseFtpCfgCmd( IN CONST BOOL32 bUse, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
*  KdvMt_CFGGetUseFtpSrvCfg 
* 
* @brief   获取FTP开关
* 
* @param    [out]  bUse FTP开关 
* @param    [in]   dwSSID     MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:Ev_MtApi_Base_SetUseFtpCfg_Ntf, Ev_MtApi_Base_GetUseFtpCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetUseFtpSrvCfg( OUT BOOL32 &bUse, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
*  KdvMt_CFGSetLoginTacticsCfgCmd 
* 
* @brief   设置登录策略（暂时不用）
* 
* @param    [in]   tCfg  登录策略
* @param    [in]   dwSSID     MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:Ev_MtApi_Base_SetSvrLoginTacticsCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetLoginTacticsCfgCmd( IN CONST TMtLoginTacticsTable_Api& tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGGetLoginTacticsCfg 
* 
* @brief   获取登录策略（暂时不用）
* 
* @param    [out]  tCfg  登录策略
* @param    [in]   dwSSID     MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:	Ev_MtApi_Base_SetSvrLoginTacticsCfg_Ntf, Ev_MtApi_Base_GetSvrLoginTacticsCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetLoginTacticsCfg( OUT TMtLoginTacticsTable_Api& tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_CFGSetAudAnsCfgCmd 
* 
* @brief  设置自动噪音抑制
* 
* @param    [in]  bAns  是否开启自动噪声抑制
* @param    [in]   dwSSID     MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:	Ev_MtApi_Base_SetAnsCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetAudAnsCfgCmd( IN CONST BOOL32 bAns, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_CFGGetAudAnsCfg 
* 
* @brief   获取自动噪音抑制
* 
* @param    [out]  bAns  是否开启自动噪声抑制
* @param    [in]   dwSSID     MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:	Ev_MtApi_Base_SetAnsCfg_Ntf, Ev_MtApi_Base_GetAnsCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetAudAnsCfg( OUT BOOL32& bAns, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGSetAudAgcCfgCmd 
* 
* @brief  设置自动增益控制
* 
* @param    [in]  bAgc  是否开启自动增益控制
* @param    [in]   dwSSID     MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:	Ev_MtApi_Base_SetAgcCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetAudAgcCfgCmd( IN CONST BOOL32 bAgc, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_CFGGetAudAgcCfg 
* 
* @brief   获取自动增益控制
* 
* @param    [out]  bAgc  是否开启自动增益控制
* @param    [in]   dwSSID     MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:	Ev_MtApi_Base_SetAgcCfg_Ntf, Ev_MtApi_Base_GetAgcCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetAudAgcCfg( OUT BOOL32& bAgc, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGSetAudAecCfgCmd 
* 
* @brief  设置自动回声抵消
* 
* @param    [in]  tAec  AEC微调参数信息
* @param    [in]   dwSSID     MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:	Ev_MtApi_Base_SetAecCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetAudAecCfgCmd( IN CONST TAdjustAecParamCfg_Api & tAec, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_CFGGetAudAecCfg 
* 
* @brief   获取自动回声抵消
* 
* @param    [out]  tAec  AEC微调参数信息
* @param    [in]   dwSSID     MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:	Ev_MtApi_Base_SetAecCfg_Ntf, Ev_MtApi_Base_GetAecCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetAudAecCfg( OUT TAdjustAecParamCfg_Api & tAec, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGSetPlayAniSoundCfgCmd 
* 
* @brief  设置空闲状态是否播放动画音效
* 
* @param    [in]  bPlay  是否播放动画音效
* @param    [in]   dwSSID     MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:	Ev_MtApi_Base_SetPlayAniSoundInIdleCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetPlayAniSoundCfgCmd( IN CONST BOOL32 bPlay, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGGetPlayAniSoundCfg 
* 
* @brief   获取空闲状态是否播放动画音效
* 
* @param    [out]  bPlay  是否播放动画音效
* @param    [in]   dwSSID     MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:	Ev_MtApi_Base_SetPlayAniSoundInIdleCfg_Ntf, Ev_MtApi_Base_GetPlayAniSoundInIdleCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetPlayAniSoundCfg( OUT BOOL32 &bPlay, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_CFGSetVideoDecParamCfgCmd 
* 
* @brief  设置视频解码参数
* 
* @param    [in]   tCfg       视频解码参数
* @param    [in]   dwSSID     MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:	Ev_MtApi_Base_SetVideoDecParamCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetVideoDecParamCfgCmd( IN CONST TMTAllVideoDecoderParamCfg_Api & tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGGetVideoDecParamCfg 
* 
* @brief   获取视频解码参数
* 
* @param    [out]  tCfg       视频解码参数
* @param    [in]   dwSSID     MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:	Ev_MtApi_Base_SetVideoDecParamCfg_Ntf, Ev_MtApi_Base_GetVideoDecParamCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetVideoDecParamCfg( OUT TMTAllVideoDecoderParamCfg_Api& tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_CFGGetMCInfoRt 
* 
* @brief   获取MC信息
* 
* @param    [out]  tCfg       视频解码参数
* @param    [in]   dwSSID     MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:	Ev_MtApi_Base_SetMCInfoRt_Ntf, Ev_MtApi_Base_GetMCInfoRt_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetMCInfoRt( OUT TInnerMCRunInfo_Api & tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
*  KdvMt_CFGGetChanInfoRt 
* 
* @brief   获取通道信息
* 
* @param    [out]  tChanInfo  通道信息
* @param    [in]   dwSSID     MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:	Ev_MtApi_Base_GetChanInfoRt_Ntf, Ev_MtApi_Base_GetChanInfoRt_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetChanInfoRt( OUT TMutiChanDsInfo_Api & tChanInfo, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
*  KdvMt_CFGSetChrmanPollSchemesCfgCmd 
* 
* @brief  设置主席轮询方案
* 
* @param    [in]   Scheme     轮询方案
* @param    [in]   dwSSID     MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:	Ev_MtApi_Base_SetChrmanPollSchemesCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetChrmanPollSchemesCfgCmd( IN CONST TMTChrmanPollSchemeList_Api & Scheme, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGGetChrmanPollSchemesCfg 
* 
* @brief   获取主席轮询方案
* 
* @param    [out]  Scheme     轮询方案
* @param    [in]   dwSSID     MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:	Ev_MtApi_Base_SetChrmanPollSchemesCfg_Ntf, Ev_MtApi_Base_GetChrmanPollSchemesCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetChrmanPollSchemesCfg( OUT TMTChrmanPollSchemeList_Api & Scheme, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_CFGSetShowConfTimeCfgCmd 
* 
* @brief  设置显示会议时间
* 
* @param    [in]   bShow      是否显示会议时间
* @param    [in]   dwSSID     MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:	Ev_MtApi_Base_SetShowConfTimeCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetShowConfTimeCfgCmd( IN CONST BOOL32 bShow, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGGetShowConfTimeCfg 
* 
* @brief   获取显示会议时间
* 
* @param    [out]  bShow      是否显示会议时间
* @param    [in]   dwSSID     MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:	Ev_MtApi_Base_SetShowConfTimeCfg_Ntf, Ev_MtApi_Base_GetShowConfTimeCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetShowConfTimeCfg( OUT BOOL32 &bShow, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_CFGSetShowShortMsgInConfCfgCmd 
* 
* @brief  设置会议中是否显示短消息
* 
* @param    [in]   bShow      是否显示会议短消息
* @param    [in]   dwSSID     MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:	Ev_MtApi_Base_SetShowShortMsgInConfCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetShowShortMsgInConfCfgCmd( IN CONST BOOL32 bShow, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGGetShowShortMsgInConfCfg 
* 
* @brief   获取会议中是否显示短消息
* 
* @param    [out]  bShow      是否显示会议短消息
* @param    [in]   dwSSID     MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:	Ev_MtApi_Base_SetShowShortMsgInConfCfg_Ntf, Ev_MtApi_Base_GetShowShortMsgInConfCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetShowShortMsgInConfCfg( OUT BOOL32 &bShow, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGSetShowAppTipsCfgCmd 
* 
* @brief  设置显示申请信息
* 
* @param    [in]   bShow      是否显示
* @param    [in]   dwSSID     MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:	Ev_MtApi_Base_SetShowAppTipsCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetShowAppTipsCfgCmd( IN CONST BOOL32 bShow, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGGetShowAppTipsCfg 
* 
* @brief   获取显示申请信息
* 
* @param    [out]  bShow      是否显示
* @param    [in]   dwSSID     MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:	Ev_MtApi_Base_SetShowAppTipsCfg_Ntf, Ev_MtApi_Base_GetShowAppTipsCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetShowAppTipsCfg( OUT BOOL32 &bShow, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_CFGSetFECCCfgCmd 
* 
* @brief  设置是否允许远摇
* 
* @param    [in]   bAllow         是否允许
* @param    [in]   dwSSID     MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:	Ev_MtApi_Base_SetFECCCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetFECCCfgCmd( IN CONST BOOL32 bAllow, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGGetFECCCfg 
* 
* @brief   获取是否允许远摇
* 
* @param    [out]  bAllow         是否允许
* @param    [in]   dwSSID     MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:	Ev_MtApi_Base_SetFECCCfg_Ntf, Ev_MtApi_Base_GetFECCCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetFECCCfg( OUT BOOL32 &bAllow, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_CFGSetLoginPwdCfgCmd 
* 
* @brief  设置登录密码
* 
* @param    [in]   tCfg     密码
* @param    [in]   dwSSID     MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:	Ev_MtApi_Base_SetLoginPwdCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetLoginPwdCfgCmd( IN CONST TMtLoginPlatformPwdCfg_Api &tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGGetLoginPwdCfg 
* 
* @brief   获取登录密码
* 
* @param    [out]  tCfg     密码
* @param    [in]   dwSSID     MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:	Ev_MtApi_Base_SetLoginPwdCfg_Ntf, Ev_MtApi_Base_GetLoginPwdCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetLoginPwdCfg( OUT TMtLoginPlatformPwdCfg_Api &tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
*  KdvMt_CFGSetEmailCfgCmd 
* 
* @brief  设置Email
* 
* @param    [in]   achEmail         Email
* @param    [in]   dwSSID     MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:	Ev_MtApi_Base_SetEmailCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetEmailCfgCmd( IN CONST s8* pchCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGGetEmailCfg 
* 
* @brief   获取Email
* 
* @param    [out]  achEmail         Email
* @param    [in]   dwSSID     MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:	Ev_MtApi_Base_SetEmailCfg_Ntf, Ev_MtApi_Base_GetEmailCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetEmailCfg( OUT s8* pchEmail, u8 byCnt, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_CFGSetModelCfgCmd 
* 
* @brief  设置设备型号
* 
* @param    [in]   emModel    设备型号
* @param    [in]   dwSSID     MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:	Ev_MtApi_Base_SetModelCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetModelCfgCmd( IN CONST EmMtModel_Api & emModel, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGGetModelCfg 
* 
* @brief   获取设备型号
* 
* @param    [out]  emModel    设备型号
* @param    [in]   dwSSID     MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:	Ev_MtApi_Base_SetModelCfg_Ntf, Ev_MtApi_Base_GetModelCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetModelCfg( OUT EmMtModel_Api & emModel, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_CFGGetSysUpgradeRt 
* 
* @brief   获取系统升级状态
* 
* @param    [out]  bUpgrade   系统升级状态
* @param    [in]   dwSSID     MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:	Ev_MtApi_Base_SetSysUpgradeRt_Ntf, Ev_MtApi_Base_GetSysUpgradeRt_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetSysUpgradeRt( OUT BOOL32 & bUpgrade, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGGetConfUsedPortsRt 
* 
* @brief   获取会议使用的端口
* 
* @param    [out]  tPort         端口
* @param    [in]   dwSSID     MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:	Ev_MtApi_Base_SetConfUsedPortsRt_Ntf, Ev_MtApi_Base_GetConfUsedPortsRt_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetConfUsedPortsRt( OUT TMTUsedPortList_Api & tPort, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_CFGGetMcUsedPortsRt 
* 
* @brief   获取MC使用的端口
* 
* @param    [out]  tPort         端口
* @param    [in]   dwSSID     MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:	Ev_MtApi_Base_SetMcUsedPortsRt_Ntf, Ev_MtApi_Base_GetMcUsedPortsRt_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetMcUsedPortsRt( OUT TMTUsedPortList_Api & tPort, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGGetVodUsedPortsRt 
* 
* @brief   获取Vod使用的端口
* 
* @param    [out]  tPort         端口
* @param    [in]   dwSSID     MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:	Ev_MtApi_Base_SetVodUsedPortsRt_Ntf, Ev_MtApi_Base_GetVodUsedPortsRt_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetVodUsedPortsRt( OUT TMTUsedPortList_Api & tPort, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGGetImUsedPortsRt 
* 
* @brief   获取Im使用的端口
* 
* @param    [out]  tPort         端口
* @param    [in]   dwSSID     MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:	Ev_MtApi_Base_SetImUsedPortsRt_Ntf, Ev_MtApi_Base_GetImUsedPortsRt_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetImUsedPortsRt( OUT TMTUsedPortList_Api & tPort, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_CFGGetBandWidthCfg 
* 
* @brief   获取带宽
* 
* @param    [out]  tNetStatus  带宽
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:	Ev_MtApi_Base_SetBandWidthRt_Ntf, Ev_MtApi_Base_GetBandWidthRt_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetBandWidthCfg( OUT TMTNetStatus_Api & tNetStatus, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/*
*  KdvMt_CFGGetSysCtrlSrvInfoRt 
* 
* @brief   获取运行时映射表
* 
* @param    [out]  tSrvInfo   子系统信息
* @param    [in]   dwSSID     MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:	Ev_MtApi_Base_SetSysCtrlSrvInfoRt_Ntf, Ev_MtApi_Base_GetSysCtrlSrvInfoRt_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetSysCtrlSrvInfoRt( OUT TMutiTServiceInfoRtData_Api & tSrvInfo, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_CFGGetSysCtrlSrvNumRt 
* 
* @brief   获取子系统数量
* 
* @param    [out]  dwSrvNum    子系统数量
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:	Ev_MtApi_Base_SetSysCtrlSrvNumRt_Ntf, Ev_MtApi_Base_GetSysCtrlSrvNumRt_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetSysCtrlSrvNumRt( OUT u32 & dwSrvNum, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
*  KdvMt_CFGSetSysCtrlDefSrvInfoCfgCmd 
* 
* @brief   设置默认启动映射表
* 
* @param    [IN]  tDefSrvInfo  默认服务器信息
* @param    [in]   dwSSID       MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:	Ev_MtApi_Base_SetSysCtrlDefSrvInfoCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetSysCtrlDefSrvInfoCfgCmd( IN CONST TMutiTServiceDefInfo_Api& tDefSrvInfo, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
*  KdvMt_CFGGetSysCtrlDefSrvInfoCfg 
* 
* @brief   获取系统控制默认服务器信息
* 
* @param    [out]  tDefSrvInfo  默认服务器信息
* @param    [in]   dwSSID       MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:	Ev_MtApi_Base_SetSysCtrlDefSrvInfoCfg_Ntf, Ev_MtApi_Base_GetSysCtrlDefSrvInfoCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetSysCtrlDefSrvInfoCfg( OUT TMutiTServiceDefInfo_Api & tDefSrvInfo, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );




/**
*  KdvMt_CFGSetSysCtrlDefSrvNumCfgCmd 
* 
* @brief   设置默认映射表中模块个数
* 
* @param    [IN]   dwSrvNum        模块个数
* @param    [in]   dwSSID     MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:	Ev_MtApi_Base_SetSysCtrlDefSrvNumCfg_Ntf, Ev_MtApi_Base_GetSysCtrlDefSrvNumCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetSysCtrlDefSrvNumCfgCmd( IN CONST u32 dwSrvNum, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
*  KdvMt_CFGGetSysCtrlDefSrvNumCfg 
* 
* @brief   获取默认映射表中模块个数
* 
* @param    [out]  dwSrvNum        模块个数
* @param    [in]   dwSSID     MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:	Ev_MtApi_Base_SetSysCtrlDefSrvNumCfg_Ntf, Ev_MtApi_Base_GetSysCtrlDefSrvNumCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetSysCtrlDefSrvNumCfg( OUT u32 & dwSrvNum, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );




/**
*  KdvMt_CFGSetDCSCfgCmd 
* 
* @brief   设置数据会议
* 
* @param    [in]   tCfg        数据会议
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:	Ev_MtApi_Base_SetDCSCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetDCSCfgCmd( IN CONST TMtDCSSvrAddr_Api& tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_CFGGetDCSCfg 
* 
* @brief   获取数据会议
* 
* @param    [out]  tCfg        数据会议
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:	Ev_MtApi_Base_SetDCSCfg_Ntf, Ev_MtApi_Base_GetDCSCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetDCSCfg( OUT TMtDCSSvrAddr_Api& tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_CFGSetPriVidEncParamCfgCmd 
* 
* @brief   设置主视频编码器参数
* 
* @param    [out]  tCfg        主视频编码器参数
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:	Ev_MtApi_Base_SetPriVidEncParamCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetPriVidEncParamCfgCmd( IN CONST TMTAllVideoEncoderParamCfg_Api& tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
*  KdvMt_CFGGetPriVidEncParamCfg 
* 
* @brief   获取主视频编码器参数
* 
* @param    [out]  tCfg        主视频编码器参数
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:	Ev_MtApi_Base_SetPriVidEncParamCfg_Ntf, Ev_MtApi_Base_GetPriVidEncParamCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetPriVidEncParamCfg( OUT TMTAllVideoEncoderParamCfg_Api& tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
*  KdvMt_CFGSetAssVidEncParamCfgCmd 
* 
* @brief   设置辅视频编码器参数
* 
* @param    [out]  tCfg        辅视频编码器参数
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:	Ev_MtApi_Base_SetPriVidEncParamCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetAssVidEncParamCfgCmd( IN CONST TMTAllVideoEncoderParamCfg_Api& tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
*  KdvMt_CFGGetAssVidEncParamCfg 
* 
* @brief   获取辅视频编码器参数
* 
* @param    [out]  tCfg        辅视频编码器参数
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:	Ev_MtApi_Base_SetAssVidEncParamCfg_Ntf, Ev_MtApi_Base_GetAssVidEncParamCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetAssVidEncParamCfg( OUT TMTAllVideoEncoderParamCfg_Api& tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
*  KdvMt_CFGSetCodecVideoSrcCfgCmd 
* 
* @brief   设置视频源
* 
* @param    [out]  tCfg        视频源
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:	Ev_MtApi_Base_SetCodecVideoSrcCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetCodecVideoSrcCfgCmd( IN CONST TMTCodecVidSrcInfo_Api& tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
*  KdvMt_CFGGetCodecVideoSrcCfg 
* 
* @brief   获取视频源
* 
* @param    [out]  tCfg        视频源
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:	Ev_MtApi_Base_SetCodecVideoSrcCfg_Ntf, Ev_MtApi_Base_GetCodecVideoSrcCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetCodecVideoSrcCfg( OUT TMTCodecVidSrcInfo_Api &tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
*  KdvMt_CFGGetIsSatelliteMTRt 
* 
* @brief   是否是卫星终端， 从平台获取
* 
* @param    [out]  tCfg        是否是卫星终端
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:	Ev_MtApi_Base_SetIsSatelliteMTRt_Ntf, Ev_MtApi_Base_GetIsSatelliteMTRt_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetIsSatelliteMTRt( OUT TMTSatelliteFlag_Api &tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );




/**
*  KdvMt_CFGSetShowSystimeTimeCfgCmd 
* 
* @brief   设置显示系统时间
* 
* @param    [in]   bCfg        是否系统时间
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:	Ev_MtApi_Base_SetShowSystimeTimeCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetShowSystimeTimeCfgCmd( IN CONST BOOL32 bCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
*  KdvMt_CFGGetShowSystimeTimeCfg 
* 
* @brief   获取显示系统时间
* 
* @param    [out]  bCfg        是否系统时间
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:	Ev_MtApi_Base_SetShowSystimeTimeCfg_Ntf, Ev_MtApi_Base_GetShowSystimeTimeCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetShowSystimeTimeCfg( OUT BOOL32& bCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
*  KdvMt_CFGGetLoginIMRt 
* 
* @brief   获取登录IM所需要的参数
* 
* @param    [out]  tCfg        登录IM所需要的参数
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:	Ev_MtApi_Base_SetLoginIMRt_Ntf, Ev_MtApi_Base_GetLoginIMRt_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetLoginIMParamCfg( OUT TImUserLogin_Api &tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
*  KdvMt_CFGGetIsH323StackStandRt 
* 
* @brief   获取323协议栈是否标准的( value: TBOOL32), 标准注册到1719，非标注册到1759
* 
* @param    [out]  bCfg        323协议栈是否标准的( value: TBOOL32), 标准注册到1719，非标注册到1759
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:	Ev_MtApi_Base_SetIsH323StackStandRt_Ntf, Ev_MtApi_Base_GetIsH323StackStandRt_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetIsH323StackStandRt( OUT BOOL32 &bCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
*  KdvMt_CFGGetH323CallingPortRt 
* 
* @brief   获取323协议栈侦听端口
* 
* @param    [out]  wCfg        323协议栈侦听端口
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:	Ev_MtApi_Base_SetH323CallingPortRt_Ntf, Ev_MtApi_Base_GetH323CallingPortRt_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetH323CallingPortRt( OUT u16 &wCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
*  KdvMt_CFGSetH264SvcCfgCmd 
* 
* @brief   设置H.264 SVC
* 
* @param    [out]  bCfg        H.264 SVC
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:	Ev_MtApi_Base_SetH264SvcCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetH264SvcCfgCmd( IN CONST BOOL32 bCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
*  KdvMt_CFGGetH264SvcCfg 
* 
* @brief   获取H.264 SVC
* 
* @param    [out]  bCfg        H.264 SVC
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:	Ev_MtApi_Base_SetH264SvcCfg_Ntf, Ev_MtApi_Base_GetH264SvcCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetH264SvcCfg( OUT BOOL32 &bCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );




/**
*  KdvMt_CFGSetLoadAdaptiveVideoCfgCmd 
* 
* @brief   设置视频载荷自适应
* 
* @param    [in]   bCfg        视频载荷自适应
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:	Ev_MtApi_Base_SetLoadAdaptiveVideoCfg_Ntf, Ev_MtApi_Base_GetLoadAdaptiveVideoCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetLoadAdaptiveVideoCfgCmd( IN CONST BOOL32 bCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
*  KdvMt_CFGGetLoadAdaptiveVideoCfg 
* 
* @brief   获取视频载荷自适应
* 
* @param    [out]  bCfg        视频载荷自适应
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:	Ev_MtApi_Base_SetLoadAdaptiveVideoCfg_Ntf, Ev_MtApi_Base_GetLoadAdaptiveVideoCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetLoadAdaptiveVideoCfg( OUT BOOL32 &bCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );




/**
*  KdvMt_CFGSetInnerMcAssVidCfgCmd 
* 
* @brief   设置内置mc辅流参数设置
* 
* @param    [in]   tCfg        内置mc辅流参数设置
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:	Ev_MtApi_Base_SetInnerMcAssVidCfgCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetInnerMcAssVidCfgCmd( IN CONST TMTInnerMcAssVidCfg_Api& tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );




/**
*  KdvMt_CFGGetInnerMcAssVidCfg 
* 
* @brief   获取内置mc辅流参数设置
* 
* @param    [out]  tCfg        内置mc辅流参数设置
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:	Ev_MtApi_Base_SetInnerMcAssVidCfgCfg_Ntf, Ev_MtApi_Base_GetInnerMcAssVidCfgCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetInnerMcAssVidCfg( OUT TMTInnerMcAssVidCfg_Api &tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/********************硬终端产品Key开始********************/
/*******************************************************/


/**
*  KdvMt_CFGGetCallInRingRt 
* 
* @brief   获取播放呼入铃声
* 
* @param    [out]  dwtCfg      播放呼入铃声
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:	Ev_MtApi_Base_Hd_SetCallInRingRt_Ntf, Ev_MtApi_Base_Hd_GetCallInRingRt_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetCallInRingRt( OUT u32 &dwtCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_CFGGetCallOutRingRt 
* 
* @brief   获取播放呼出铃声
* 
* @param    [out]  dwtCfg      播放呼出铃声
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:	Ev_MtApi_Base_Hd_SetCallOutRingRt_Ntf, Ev_MtApi_Base_Hd_GetCallOutRingRt_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetCallOutRingRt( OUT u32 &dwCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
*  KdvMt_CFGSetKeyboardRingCfgCmd 
* 
* @brief   设置播放按键音
* 
* @param    [in]  dwtCfg      播放按键音
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:	Ev_MtApi_Base_Hd_SetKeyboardRingCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetKeyboardRingCfgCmd( IN CONST u32 dwCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
*  KdvMt_CFGGetKeyboardRingCfg 
* 
* @brief   获取播放按键音
* 
* @param    [out]  dwtCfg      播放按键音
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:	Ev_MtApi_Base_Hd_SetKeyboardRingCfg_Ntf, Ev_MtApi_Base_Hd_GetKeyboardRingCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetKeyboardRingCfg( OUT u32 &dwCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
*  KdvMt_CFGSetVGAImageAdjustCfgCmd 
* 
* @brief   设置VGA图像调节
* 
* @param    [in]   tCfg        VGA图像调节
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:	Ev_MtApi_Base_Hd_SetVGAImageAdjustCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetVGAImageAdjustCfgCmd( IN CONST TMTVgaImageAdjustCfg_Api& tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
*  KdvMt_CFGGetVGAImageAdjustCfg 
* 
* @brief   获取VGA图像调节
* 
* @param    [out]  tCfg        VGA图像调节
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:	Ev_MtApi_Base_Hd_SetVGAImageAdjustCfg_Ntf, Ev_MtApi_Base_Hd_GetVGAImageAdjustCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetVGAImageAdjustCfg( OUT TMTVgaImageAdjustCfg_Api &tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
*  KdvMt_CFGSetVideoSrcTagCfgCmd  (仅Embed)
* 
* @brief   设置视频源标签
* 
* @param    [in]   tCfg        视频源标签
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:	Ev_MtApi_Base_Hd_SetVideoSrcTagCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetVideoSrcTagCfgCmd( IN CONST TMTVideoSrcTagList_Api& tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
* KdvMt_SetVidImgParamCmd
*
* @brief    设置视频亮度、对比度、饱和度
*
* @param    [in]   emCodecType   编解码类型
* @param    [in]   emCodecIdx   哪一路
* @param    [in]   emMsgSrc    EmImgParam_Api(暂时可填emHue_Api、emContrast_Api、emSaturation_Api、emBright_Api，其它值无效)
* @param    [in]   nValue		参数值
* @return   u32    0：成功      其他错误码
* @note 更新通知： Ev_MtApi_Base_Hd_SetVidImgParam_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_SetVidImgParamCmd( IN CONST EmCodecComponent_Api emCodecType, IN CONST EmCodecComponentIndex_Api emCodecIdx, 
	IN CONST EmImgParam_Api emMsgSrc,IN CONST s32 nValue,IN CONST SessionID dwSSID  = KMTAPI_DEF_SSID );


/**
*  KdvMt_CFGGetVideoSrcTagCfg 
* 
* @brief   获取视频源标签
* 
* @param    [out]  tCfg        视频源标签
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:	Ev_MtApi_Base_Hd_SetVideoSrcTagCfg_Ntf, Ev_MtApi_Base_Hd_GetVideoSrcTagCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetVideoSrcTagCfg( OUT TMTVideoSrcTagList_Api &tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
*  KdvMt_CFGSetSnapShotFtpCfgCfgCmd ( 仅embed )
* 
* @brief   设置快照FTP
* 
* @param    [in]   tCfg        快照FTP 
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:	Ev_MtApi_Base_Hd_SetSnapShotFtpCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetSnapShotFtpCfgCfgCmd( IN CONST TMTSnapShotFtpCfg_Api& tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
*  KdvMt_CFGGetSnapShotFtpCfgCfg 
* 
* @brief   获取快照FTP
* 
* @param    [in]   tCfg        快照FTP 
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:	Ev_MtApi_Base_Hd_SetSnapShotFtpCfg_Ntf, Ev_MtApi_Base_Hd_GetSnapShotFtpCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetSnapShotFtpCfgCfg( OUT TMTSnapShotFtpCfg_Api &tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_CFGSetVgaOutBrightCfgCmd 
* 
* @brief   设置VGA输出亮度
* 
* @param    [in]   dwCfg        输出亮度
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:	Ev_MtApi_Base_Hd_SetVgaOutBrightCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetVgaOutBrightCfgCmd( IN CONST u32 dwCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGGetVgaOutBrightCfg 
* 
* @brief   获取VGA输出亮度
* 
* @param    [in]   dwCfg        输出亮度
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:	Ev_MtApi_Base_Hd_SetVgaOutBrightCfg_Ntf, Ev_MtApi_Base_Hd_GetVgaOutBrightCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetVgaOutBrightCfg( OUT u32 &dwCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_CFGSetVgaOutContrastCfgCmd 
* 
* @brief   设置VGA输出对比度
* 
* @param    [in]   dwCfg        输出对比度
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:	Ev_MtApi_Base_Hd_SetVgaOutContrastCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetVgaOutContrastCfgCmd( IN CONST u32 dwCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGSetVgaOutSaturationCfgCmd 
* 
* @brief   设置VGA输出饱和度
* 
* @param    [in]   dwCfg        输出饱和度
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:	Ev_MtApi_Base_Hd_SetVgaOutSaturationCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetVgaOutSaturationCfgCmd( IN CONST u32 dwCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGGetVgaOutSaturationCfg 
* 
* @brief   获取VGA输出饱和度
* 
* @param    [in]   dwCfg        输出饱和度
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:	
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetVgaOutSaturationCfg( OUT u32 &dwCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );
/**
*  KdvMt_CFGGetVgaOutContrastCfg 
* 
* @brief   获取VGA输出对比度
* 
* @param    [in]   dwCfg        输出对比度
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:	Ev_MtApi_Base_Hd_SetVgaOutContrastCfg_Ntf, Ev_MtApi_Base_Hd_GetVgaOutContrastCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetVgaOutContrastCfg( OUT u32 &dwCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_CFGSetSnapShotFtpCfgCfgCmd 
* 
* @brief   设置预置位名称设置
* 
* @param    [in]   tCfg        预置位名称
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:	Ev_MtApi_Base_Hd_SetPresetNameInfoCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetPresetNameInfoCfgCmd( IN CONST TAllMTPreSetNameInfoCfg_Api& tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
*  KdvMt_CFGGetPresetNameInfoCfg 
* 
* @brief   获取预置位名称设置
* 
* @param    [in]   tCfg        预置位名称
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:	Ev_MtApi_Base_Hd_SetPresetNameInfoCfg_Ntf, Ev_MtApi_Base_Hd_GetPresetNameInfoCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetPresetNameInfoCfg( OUT TAllMTPreSetNameInfoCfg_Api& tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );




//网络设置相关
/**
* KdvMt_CFGSetRouteCfgListCfgCmd
*
* @brief 设置路由配置信息
*
* 
* @param    [in]   tCfg        路由配置信息
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知: Ev_Mtapi_Base_Hd_SetRouteCfgListCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetRouteCfgListCfgCmd(IN CONST TRouteItemInfoList_Api &tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID);



/**
* KdvMt_CFGGetRouteCfgListCfg
*
* @brief 获取路由配置信息
*
* 
* @param    [in]   tCfg        路由配置信息
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知: Ev_Mtapi_Base_Hd_SetRouteCfgListCfg_Ntf, Ev_Mtapi_Base_Hd_GetRouteCfgListCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetRouteCfgListCfg(OUT TRouteItemInfoList_Api &tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID);



//< 以太网工作模式(value:TEthnetWorkModeList) emHD_Cfg_EthWorkModeList
/**
*  KdvMt_CFGSetEthWorkModeListCfgCmd 
* 
* @brief   设置以太网工作模式
* 
* @param    [in]   tCfg        以太网工作模式
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:	Ev_MtApi_Base_Hd_SetEthWorkModeListCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetEthWorkModeListCfgCmd( IN CONST TEthnetWorkModeList_Api& tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );




/**
*  KdvMt_CFGGetEthWorkModeListCfg 
* 
* @brief   获取以太网工作模式
* 
* @param    [in]   tCfg        以太网工作模式
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:	Ev_MtApi_Base_Hd_SetEthWorkModeListCfg_Ntf, Ev_MtApi_Base_Hd_GetEthWorkModeListCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetEthWorkModeListCfg( OUT TEthnetWorkModeList_Api& tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );





/**
*  KdvMt_CFGSetEthnetCfgCmd 
* 
* @brief   设置以太网信息
* 
* @param    [in]   tCfg        以太网信息
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:	Ev_MtApi_Base_Hd_SetEthnetCfgCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetEthnetCfgCmd( IN CONST TEthnetCfg_Api& tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
*  KdvMt_CFGGetEthnetCfg 
* 
* @brief   获取以太网信息
* 
* @param    [in]   tCfg        以太网信息
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:	Ev_MtApi_Base_Hd_SetEthnetCfgCfg_Ntf, Ev_MtApi_Base_Hd_GetEthnetCfgCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetEthnetCfg( OUT TEthnetCfg_Api& tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );





//< PPPoE拨号信息(value:TEthnetPPPoECfg) emHD_Cfg_EthPPPoECfg
/**
*  KdvMt_CFGSetEthPPPoECfgCmd 
* 
* @brief   设置PPPoE拨号信息
* 
* @param    [in]   tCfg        PPPoE拨号信息
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:	Ev_MtApi_Base_Hd_SetEthPPPoECfgCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetEthPPPoECfgCmd( IN CONST TEthnetPPPoECfg_Api& tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );




/**
*  KdvMt_CFGGetEthPPPoECfg 
* 
* @brief   获取PPPoE拨号信息
* 
* @param    [in]   tCfg        PPPoE拨号信息
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:	Ev_MtApi_Base_Hd_SetEthPPPoECfgCfg_Ntf, Ev_MtApi_Base_Hd_GetEthPPPoECfgCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetEthPPPoECfg( OUT TEthnetPPPoECfg_Api& tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );





/**
*  KdvMt_CFGSetWifiWorkModeCfgCmd 
* 
* @brief   设置Wifi工作模式
* 
* @param    [in]   tCfg        Wifi工作模式
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:	Ev_MtApi_Base_Hd_SetWifiWorkModeCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetWifiWorkModeCfgCmd( IN CONST TWifiWorkMode_Api& tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );




/**
*  KdvMt_CFGGetWifiWorkModeCfg 
* 
* @brief   获取Wifi工作模式
* 
* @param    [in]   tCfg        Wifi工作模式
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:	Ev_MtApi_Base_Hd_SetWifiWorkModeCfg_Ntf, Ev_MtApi_Base_Hd_GetWifiWorkModeCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetWifiWorkModeCfg( OUT TWifiWorkMode_Api& tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );





/**
*  KdvMt_CFGSetWifiApCfgCmd 
* 
* @brief   设置Wifi-AP配置信息
* 
* @param    [in]   tCfg        Wifi-AP配置信息
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:	Ev_MtApi_Base_Hd_SetWifiApCfgCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetWifiApCfgCmd( IN CONST TWifiApConfiguration_Api& tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );




/**
*  KdvMt_CFGGetWifiApCfg 
* 
* @brief   获取Wifi-AP配置信息
* 
* @param    [in]   tCfg        Wifi-AP配置信息
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:	Ev_MtApi_Base_Hd_SetWifiApCfgCfg_Ntf, Ev_MtApi_Base_Hd_GetWifiApCfgCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetWifiApCfg( OUT TWifiApConfiguration_Api& tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );






/**
*  KdvMt_CFGSetWifiClientCfgCmd 
* 
* @brief   设置Wifi作为client已连接后的配置信息
* 
* @param    [in]   tCfg        Wifi作为client已连接后的配置信息
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:	Ev_MtApi_Base_Hd_SetWifiClientCfgCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetWifiClientCfgCmd( IN CONST TWifiConfiguration_Api& tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );





/**
*  KdvMt_CFGGetWifiClientCfg 
* 
* @brief   获取Wifi作为client已连接后的配置信息
* 
* @param    [in]   tCfg        Wifi作为client已连接后的配置信息
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:	Ev_MtApi_Base_Hd_SetWifiClientCfgCfg_Ntf, Ev_MtApi_Base_Hd_GetWifiClientCfgCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetWifiClientCfg( OUT TWifiConfiguration_Api& tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_CFGSetE1CfgCmd 
* 
* @brief   设置E1配置信息
* 
* @param    [in]   tCfg        E1的配置信息
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:	Ev_MtApi_Base_HD_SetE1CfgCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetE1CfgCmd( IN CONST TE1Cfg_Api& tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_CFGGetE1Cfg 
* 
* @brief   获取E1配置信息
* 
* @param    [in]   tCfg        E1配置信息
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:	Ev_MtApi_Base_HD_SetE1CfgCfg_Ntf, Ev_MtApi_Base_HD_SetE1CfgCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetE1Cfg( OUT TE1Cfg_Api& tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_CFGGetWifiCurConnectedInfoRt 
* 
* @brief   获取Wifi作为client连接后的详细信息
* 
* @param    [in]   tCfg        Wifi作为client连接后的详细信息
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:	Ev_MtApi_Base_Hd_SetWifiCurConnectedInfoRt_Ntf, Ev_MtApi_Base_Hd_GetWifiCurConnectedInfoRt_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetWifiCurConnectedInfoRt( OUT TWifiCurDetailInfo_Api& tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );





//< 移动数据3G/4G工作模式 (value:TMobileDataWorkMode) emHD_Cfg_MobileDataWorkMode
/**
*  KdvMt_CFGSetMobileDataWorkModeCfgCmd 
* 
* @brief   设置移动数据3G/4G工作模式
* 
* @param    [in]   tCfg        移动数据3G/4G工作模式
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:	Ev_MtApi_Base_Hd_SetMobileDataWorkModeCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetMobileDataWorkModeCfgCmd( IN CONST TMobileDataWorkMode_Api& tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );






/**
*  KdvMt_CFGGetMobileDataWorkModeCfg 
* 
* @brief   获取移动数据3G/4G工作模式
* 
* @param    [in]   tCfg        移动数据3G/4G工作模式
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:	Ev_MtApi_Base_Hd_SetMobileDataWorkModeCfg_Ntf, Ev_MtApi_Base_Hd_GetMobileDataWorkModeCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetMobileDataWorkModeCfg( OUT TMobileDataWorkMode_Api& tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );






/**
*  KdvMt_CFGGetMobileDataConnectedInfoRt 
* 
* @brief   获取移动数据3G/4G连接后的详细信息
* 
* @param    [in]   tCfg        移动数据3G/4G连接后的详细信息
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:	Ev_MtApi_Base_Hd_SetMobileDataConnectedInfoRt_Ntf, Ev_MtApi_Base_Hd_GetMobileDataConnectedInfoRt_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetMobileDataConnectedInfoRt( OUT TMobileDataCurDetailInfo_Api& tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );






/**
*  KdvMt_CFGGetNetUsedInfoRt 
* 
* @brief   获取当前对外通讯的网络IP详细信息
* 
* @param    [in]   tCfg        当前对外通讯的网络IP详细信息
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:	Ev_MtApi_Base_Hd_SetNetUsedInfoCfg_Ntf, Ev_MtApi_Base_Hd_GetNetUsedInfoCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetNetUsedInfoRt( OUT TNetUsedInfo_Api& tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );





/**
*  KdvMt_CFGSetHoriRollMsgCfgCmd 
* 
* @brief    设置滚动短消息配置命令
* 
* @param	[in] tCfg      滚动短消息配置
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MT_HoriRollMsgCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetHoriRollMsgCfgCmd( IN CONST TRollMsgCfg_Api& tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
*  KdvMt_CFGGetRollMsgCfg 
* 
* @brief   获取滚动短消息配置信息
* 
* @param    [out]  tCfg       滚动短消息配置信息
* @param    [in]   dwSSID     MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MtApi_Base_HoriRollMsgCfg_Ntf, Ev_MtApi_Base_GetHoriRollMsgCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetRollMsgCfg( OUT TRollMsgCfg_Api& tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID ); 



/**********用户设置**************/

/**
*  KdvMt_CFGSetHDDispModeCfgCmd 
* 
* @brief 设置双流显示模式
* 
* @param    [IN CONST]  emDualMode   双流显示模式
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 响应通知：Ev_MtApi_Base_Hd_SetDispModeCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetHDDispModeCfgCmd( IN CONST EmDualVideoShowMode_Api emDualMode, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_CFGGetHDDispModeCfg 
* 
* @brief 获取双流显示模式
* 
* @param    [out]  emDualMode   双流显示模式
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MtApi_Base_Hd_SetDispModeCfg_Ntf, Ev_MtApi_Base_Hd_GetDispModeCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetHDDispModeCfg( OUT EmDualVideoShowMode_Api& emDualMode, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );




/**
*  KdvMt_CFGSetHDResOutputCfgCmd 
* 
* @brief 设置视频输出制式
* 
* @param    [IN CONST]  tVideoOutPortMd   视频输出制式
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 响应通知：Ev_MtApi_Base_Hd_SetHDResOutputCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetHDResOutputCfgCmd( IN CONST THDMTVideoOutPortMode_Api& tVideoOutPortMd, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_CFGGetHDResOutputCfg 
* 
* @brief 获取视频输出制式
* 
* @param    [out]  tVideoOutPortMd   视频输出制式
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MtApi_Base_Hd_SetHDResOutputCfg_Ntf, Ev_MtApi_Base_Hd_GetHDResOutputCfg_Rsp
*/
// 获取视频输出制式 emHD_Cfg_HDResOutput
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetHDResOutputCfg( OUT THDMTVideoOutPortMode_Api& tVideoOutPortMd, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_CFGSetIsHDAutoPIPCfgCmd 
* 
* @brief 设置是否开启自动画中画
* 
* @param    [IN CONST]  bAutoPip   是否开启自动画中画
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 响应通知：Ev_MtApi_Base_Hd_SetAutoPIPCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetIsHDAutoPIPCfgCmd( IN CONST BOOL32 bAutoPip, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_CFGIsHDAutoPIPCfg 
* 
* @brief 获取是否开启自动画中画
* 
* @param    [out]  bAutoPip   是否开启自动画中画
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MtApi_Base_Hd_SetAutoPIPCfg_Ntf, Ev_MtApi_Base_Hd_GetAutoPIPCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGIsHDAutoPIPCfg( OUT BOOL32& bAutoPip, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_CFGSetHDCallInRingCfgCmd 
* 
* @brief 设置呼入铃声
* 
* @param    [IN CONST]  dwCallInRing   呼入铃声
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 响应通知：Ev_MtApi_Base_Hd_SetCallInRingCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetHDCallInRingCfgCmd( IN CONST u32 dwCallInRing, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_CFGGetHDCallInRingCfg 
* 
* @brief 获取呼入铃声
* 
* @param    [out]  dwCallInRing   呼入铃声
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MtApi_Base_Hd_SetCallInRingCfg_Ntf, Ev_MtApi_Base_Hd_GetCallInRingCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetHDCallInRingCfg( OUT u32& dwCallInRing, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_CFGSetHDCallOutRingCfgCmd 
* 
* @brief 设置呼出铃声
* 
* @param    [IN CONST]  dwCallOutRing  呼出铃声
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 响应通知：Ev_MtApi_Base_Hd_SetCallOutRingCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetHDCallOutRingCfgCmd( IN CONST u32 dwCallOutRing, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_CFGGetHDCallOutRingCfg 
* 
* @brief 获取呼出铃声
* 
* @param    [out]  dwCallOutRing   呼出铃声
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MtApi_Base_Hd_SetCallOutRingCfg_Ntf, Ev_MtApi_Base_Hd_GetCallOutRingCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetHDCallOutRingCfg( OUT u32& dwCallOutRing, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
*  KdvMt_CFGSetHDPresetBannerCfgCmd 
* 
* @brief 设置当前使用的横幅id号
* 
* @param    [IN CONST]  tPresetBanner   当前使用的横幅id号
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 响应通知：Ev_MtApi_Base_Hd_SetEnablePresetBannerCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetHDPresetBannerCfgCmd( IN CONST THDMTEnablePresetBanner_Api& tPresetBanner, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_CFGGetHDPresetBannerCfg 
* 
* @brief 获取当前使用的横幅id号
* 
* @param    [out]  tPresetBanner   当前使用的横幅id号
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MtApi_Base_Hd_SetEnablePresetBannerCfg_Ntf, Ev_MtApi_Base_Hd_GetEnablePresetBannerCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetHDPresetBannerCfg( OUT THDMTEnablePresetBanner_Api& tPresetBanner, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_CFGSetHDOsdBannerInfoCfgCmd 
* 
* @brief 设置osd横幅配置
* 
* @param    [IN CONST]  tBannerInfo   横幅配置
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 响应通知：Ev_MtApi_Base_Hd_SetOsdBannerInfoCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetHDOsdBannerInfoCfgCmd( IN CONST THDMTBannerInfo_Api& tBannerInfo, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_CFGSetHDMtcBannerInfoCfgCmd 
* 
* @brief 设置mtc横幅配置
* 
* @param    [IN CONST]  tBannerInfo   横幅配置
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 响应通知：Ev_MtApi_Base_Hd_SetMtcBannerInfoCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetHDMtcBannerInfoCfgCmd( IN CONST THDMTBannerInfoList_Api& tBannerInfo, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_CFGGetHDOsdBannerInfoCfg 
* 
* @brief 获取横幅配置
* 
* @param    [out]  tBannerInfo   横幅配置
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：
*/
// 获取横幅配置 emHD_Cfg_OsdBannerInfo
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetHDOsdBannerInfoCfg( OUT THDMTBannerInfo_Api& tBannerInfo, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_CFGGetHDMtcBannerInfoCfg 
* 
* @brief 获取Mtc横幅配置
* 
* @param    [out]  tBannerInfo   横幅配置
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：
*/
// 获取横幅配置 emHD_Cfg_MtcBannerInfo
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetHDMtcBannerInfoCfg( OUT THDMTBannerInfoList_Api& tBannerInfo, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );




/**
*  KdvMt_CFGSetHDLabelInfoCfgCmd 
* 
* @brief 设置台标配置 
* 
* @param    [IN CONST]  tLabelInfo   台标配置 
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 响应通知：Ev_MtApi_Base_Hd_SetLabelInfoCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetHDLabelInfoCfgCmd( IN CONST THDMTLabelInfo_Api& tLabelInfo, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_CFGGetHDLabelInfoCfg 
* 
* @brief 获取台标配置 
* 
* @param    [out]  tLabelInfo   台标配置 
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MtApi_Base_Hd_SetLabelInfoCfg_Ntf, Ev_MtApi_Base_Hd_GetLabelInfoCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetHDLabelInfoCfg( OUT THDMTLabelInfo_Api& tLabelInfo, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_CFGSetHDAutoSleepCfgCmd 
* 
* @brief 设置自动待机配置
* 
* @param    [IN CONST]  tAutoSleep   自动待机配置
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 响应通知：Ev_MtApi_Base_Hd_SetAutoSleepCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetHDAutoSleepCfgCmd( IN CONST THDMTAutoSleep_Api& tAutoSleep, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_CFGGetHDAutoSleepCfg 
* 
* @brief 获取自动待机配置
* 
* @param    [out]  tAutoSleep   自动待机配置
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MtApi_Base_Hd_SetAutoSleepCfg_Ntf, Ev_MtApi_Base_Hd_GetAutoSleepCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetHDAutoSleepCfg( OUT THDMTAutoSleep_Api& tAutoSleep, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_CFGSetHDSysTimeCfgCmd 
* 
* @brief 设置时间配置
* 
* @param    [IN CONST]  tSystime   时间配置
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 响应通知：Ev_MtApi_Base_Hd_SetSysTimeCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetHDSysTimeCfgCmd( IN CONST THDMTCfgSystemTime_Api& tSystime, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_CFGGetHDSysTimeCfg 
* 
* @brief 获取时间配置
* 
* @param    [out]  tSystime   时间配置
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MtApi_Base_Hd_SetSysTimeCfg_Ntf, Ev_MtApi_Base_Hd_GetSysTimeCfg_Rsp
*/
// 获取时间配置 emHD_Cfg_SysTime
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetHDSysTimeCfg( OUT THDMTCfgSystemTime_Api& tSystime, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**********管理员设置**********/

/**
*  KdvMt_CFGSetHDMicGainCfgCmd 
* 
* @brief 设置麦克增益
* 
* @param    [IN CONST]  dwMicGain   麦克增益
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 响应通知：Ev_MtApi_Base_Hd_SetMicGainCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetHDMicGainCfgCmd( IN CONST u32 dwMicGain, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_CFGGetHDMicGainCfg 
* 
* @brief 获取麦克增益
* 
* @param    [out]  dwMicGain   TRUE: 麦克增益
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MtApi_Base_Hd_SetMicGainCfg_Ntf, Ev_MtApi_Base_Hd_GetMicGainCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetHDMicGainCfg( OUT u32& dwMicGain, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_CFGSetHDAecDebugCfgCmd 
* 
* @brief 设置回声抵消自适应
* 
* @param    [IN CONST]  dwAecDebug   回声抵消自适应级别
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 响应通知：Ev_MtApi_Base_Hd_SetAecDebugCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetHDAecDebugCfgCmd( IN CONST u32 dwAecDebug, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_CFGGetHDAecDebugCfg 
* 
* @brief 获取回声抵消自适应
* 
* @param    [out]  dwAecDebug   回声抵消自适应级别
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MtApi_Base_Hd_SetAecDebugCfg_Ntf, Ev_MtApi_Base_Hd_GetAecDebugCfg_Rsp
*/
// 获取回声抵消自适应 emHD_Cfg_AecDebug
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetHDAecDebugCfg( OUT u32& dwAecDebug, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_CFGSetHDAudInPortListCfgCmd 
* 
* @brief 设置音频输入接口
* 
* @param    [IN CONST]  tAudInPortList  主音频输入接口
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 响应通知：Ev_MtApi_Base_Hd_SetAudInPortListCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetHDAudInPortListCfgCmd( IN CONST TMTHDAudInPortList_Api& tAudInPortList, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_CFGGetHDAudInPortListCfg 
* 
* @brief 获取音频输入接口
* 
* @param    [out]  tAudInPortList   主音频输入接口
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MtApi_Base_Hd_SetAudInPortListCfg_Ntf, Ev_MtApi_Base_Hd_GetAudInPortListCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetHDAudInPortListCfg( OUT TMTHDAudInPortList_Api& tAudInPortList, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );




/**
*  KdvMt_CFGSetHDAudOutPortListCfgCmd 
* 
* @brief 设置音频输出接口
* 
* @param    [IN CONST]  tAudOutPortList   音频输出接口
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 响应通知：Ev_MtApi_Base_Hd_SetAudOutPortListCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetHDAudOutPortListCfgCmd( IN CONST THDMTHDAudOutPortList_Api& tAudOutPortList, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_CFGGetHDAudOutPortListCfg 
* 
* @brief 获取音频输出接口
* 
* @param    [out]  tAudOutPortList   音频输出接口
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MtApi_Base_Hd_SetAudOutPortListCfg_Ntf, Ev_MtApi_Base_Hd_GetAudOutPortListCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetHDAudOutPortListCfg( OUT THDMTHDAudOutPortList_Api& tAudOutPortList, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_CFGSetHDPri1stVidInPortCfgCmd 
* 
* @brief 设置第一路主视频输入端口
* 
* @param    [IN CONST]  tVidInPort   第一路主视频输入端口
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 响应通知：Ev_MtApi_Base_Hd_SetPri1stVidInPortCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetHDPri1stVidInPortCfgCmd( IN CONST THDMTHDVidInPort_Api& tVidInPort, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_CFGGetHDPri1stVidInPortCfg 
* 
* @brief 获取第一路主视频输入端口
* 
* @param    [out]  tVidInPort   第一路主视频输入端口
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MtApi_Base_Hd_SetPri1stVidInPortCfg_Ntf, Ev_MtApi_Base_Hd_GetPri1stVidInPortCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetHDPri1stVidInPortCfg( OUT THDMTHDVidInPort_Api& tVidInPort, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );




/**
*  KdvMt_CFGSetHDPri2ndVidInPortCfgCmd 
* 
* @brief 设置第二路主辅视频输入端口
* 
* @param    [IN CONST]  tVidInPort   第一路主视频输入端口
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 响应通知：Ev_MtApi_Base_Hd_SetPri2ndVidInPortCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetHDPri2ndVidInPortCfgCmd( IN CONST THDMTHDVidInPort_Api &tPort, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
*  KdvMt_CFGGetHDPri2ndVidInPortCfg 
* 
* @brief 获取第二路主辅视频输入端口
* 
* @param    [out]  tPort   第二路主辅视频输入端口
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MtApi_Base_Hd_SetPri2ndVidInPortCfg_Ntf, Ev_MtApi_Base_Hd_GetPri2ndVidInPortCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetHDPri2ndVidInPortCfg( OUT THDMTHDVidInPort_Api &tPort, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
*  KdvMt_CFGSetHDAssVidInPortCfgCmd 
* 
* @brief 设置辅视频输入端口
* 
* @param    [IN CONST]  tPort   辅视频输入端口
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 响应通知：Ev_MtApi_Base_Hd_SetAssVidInPortCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetHDAssVidInPortCfgCmd( IN CONST THDMTHDVidInPort_Api &tPort, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
*  KdvMt_CFGGetHDAssVidInPortCfg 
* 
* @brief 获取辅视频输入端口
* 
* @param    [out]  tPort   辅视频输入端口
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MtApi_Base_Hd_SetAssVidInPortCfg_Ntf, Ev_MtApi_Base_Hd_GetAssVidInPortCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetHDAssVidInPortCfg( OUT THDMTHDVidInPort_Api &tPort, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_CFGSetHDMultiVideoCfgCmd 
* 
* @brief 设置多视或多流
* 
* @param    [IN CONST]  tMultiVideo   多视或多流
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 响应通知：Ev_MtApi_Base_Hd_SetMultiVideoCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetHDMultiVideoCfgCmd( IN CONST TMTHDMultiVideo_Api& tMultiVideo, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_CFGGetHDMultiVideoCfg 
* 
* @brief 获取多视或多流
* 
* @param    [out]  tMultiVideo   多视或多流
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MtApi_Base_Hd_SetMultiVideoCfg_Ntf, Ev_MtApi_Base_Hd_GetMultiVideoCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetHDMultiVideoCfg( OUT TMTHDMultiVideo_Api& tMultiVideo, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
*  KdvMt_CFGSetHDVideoMatrixSchemeListCfgCmd 
* 
* @brief 设置视频矩阵
* 
* @param    [IN CONST]  tAllVidMatrixScheme   视频矩阵
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 响应通知：Ev_MtApi_Base_Hd_SetVideoMatrixSchemeCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetHDVideoMatrixSchemeListCfgCmd( IN CONST THDMTAllVideoMatrixScheme_Api& tAllVidMatrixScheme, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_CFGGetHDVideoMatrixSchemeListCfg 
* 
* @brief 获取视频矩阵
* 
* @param    [out]  tAllVidMatrixScheme   视频矩阵
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MtApi_Base_Hd_SetVideoMatrixSchemeCfg_Ntf, Ev_MtApi_Base_Hd_GetVideoMatrixSchemeCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetHDVideoMatrixSchemeListCfg( OUT THDMTAllVideoMatrixScheme_Api& tAllVidMatrixScheme, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
*  KdvMt_CFGSetHDLastDisplayListCfgCmd 
* 
* @brief 设置无图像显示策略
* 
* @param    [IN CONST]  tLastDisplay   无图像显示策略
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 响应通知：Ev_MtApi_Base_Hd_SetLastDisplayCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetHDLastDisplayListCfgCmd( IN CONST THDMTLastDisplay_Api& tLastDisplay, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_CFGGetHDLastDisplayListCfg 
* 
* @brief 获取无图像显示策略
* 
* @param    [out]  tLastDisplay   无图像显示策略
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MtApi_Base_Hd_SetLastDisplayCfg_Ntf, Ev_MtApi_Base_Hd_GetLastDisplayCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetHDLastDisplayListCfg( OUT THDMTLastDisplay_Api& tLastDisplay, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
*  KdvMt_CFGSetHDImageNoiseLevelCfgCmd 
* 
* @brief 设置图像降噪等级
* 
* @param    [IN CONST]  tImageNoise   图像降噪等级
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 响应通知：Ev_MtApi_Base_Hd_SetImageNoiseLevelCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetHDImageNoiseLevelCfgCmd( IN CONST THDMTImageNoise_Api& tImageNoise, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_CFGGetHDImageNoiseLevelCfg 
* 
* @brief 获取图像降噪等级
* 
* @param    [out]  tImageNoise  图像降噪等级
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MtApi_Base_Hd_SetImageNoiseLevelCfg_Ntf, Ev_MtApi_Base_Hd_GetImageNoiseLevelCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetHDImageNoiseLevelCfg( OUT THDMTImageNoise_Api& tImageNoise, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
*  KdvMt_CFGSetHDImageEnhancementCfgCmd 
* 
* @brief 设置图像增强开关
* 
* @param    [IN CONST]  bImageEnhancement   TRUE: 开 FALSE:关
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 响应通知：Ev_MtApi_Base_Hd_SetImageEnhancementCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetHDImageEnhancementCfgCmd( IN CONST BOOL32 bImageEnhancement, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_CFGGetHDImageEnhancementCfg 
* 
* @brief 获取图像增强开关
* 
* @param    [out]  bImageEnhancement   TRUE: 开 FALSE:关
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MtApi_Base_Hd_SetImageEnhancementCfg_Ntf, Ev_MtApi_Base_Hd_GetImageEnhancementCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetHDImageEnhancementCfg( OUT BOOL32& bImageEnhancement, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
*  KdvMt_CFGSetHDPri1stDeformationTensileCfgCmd 
* 
* @brief 设置第一路主视频变形拉伸(
* 
* @param    [IN CONST]  tCfg   第一路主视频变形拉伸
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 响应通知：Ev_MtApi_Base_Hd_SetPri1stDeformationTensileCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetHDPri1stDeformationTensileCfgCmd( IN CONST TMTHDImageDeformationTensile_Api &tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
*  KdvMt_CFGGetHDPri1stDeformationTensileCfg 
* 
* @brief 获取第一路主视频变形拉伸(
* 
* @param    [out]  tCfg   第一路主视频变形拉伸
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MtApi_Base_Hd_SetPri1stDeformationTensileCfg_Ntf, Ev_MtApi_Base_Hd_GetPri1stDeformationTensileCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetHDPri1stDeformationTensileCfg( OUT TMTHDImageDeformationTensile_Api &tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_CFGSetHDPri2ndDeformationTensileCfgCmd 
* 
* @brief 设置第二路主视频变形拉伸
* 
* @param    [IN CONST]  tCfg   第二路主视频变形拉伸
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 响应通知：Ev_MtApi_Base_Hd_SetPri2ndDeformationTensileCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetHDPri2ndDeformationTensileCfgCmd( IN CONST TMTHDImageDeformationTensile_Api &tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );




/**
*  KdvMt_CFGGetHDPri2ndDeformationTensileCfg 
* 
* @brief 获取第二路主视频变形拉伸
* 
* @param    [out]  tCfg   第二路主视频变形拉伸
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MtApi_Base_Hd_SetPri2ndDeformationTensileCfg_Ntf, Ev_MtApi_Base_Hd_GetPri2ndDeformationTensileCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetHDPri2ndDeformationTensileCfg( OUT TMTHDImageDeformationTensile_Api &tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
*  KdvMt_CFGSetHDAssDeformationTensileCfgCmd 
* 
* @brief 设置辅视频变形拉伸
* 
* @param    [IN CONST]  tCfg   辅视频变形拉伸
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 响应通知：Ev_MtApi_Base_Hd_SetAssDeformationTensileCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetHDAssDeformationTensileCfgCmd( IN CONST TMTHDImageDeformationTensile_Api &tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );




/**
*  KdvMt_CFGGetHDAssDeformationTensileCfg 
* 
* @brief 获取辅视频变形拉伸
* 
* @param    [out]  tCfg   辅视频变形拉伸
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MtApi_Base_Hd_SetAssDeformationTensileCfg_Ntf, Ev_MtApi_Base_Hd_GetAssDeformationTensileCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetHDAssDeformationTensileCfg( OUT TMTHDImageDeformationTensile_Api &tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
*  KdvMt_CFGSetHDPri1stGeometricScalingCfgCmd 
* 
* @brief 设置第一路主视频等比缩放
* 
* @param    [IN CONST]  tCfg   第一路主视频等比缩放
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 响应通知：Ev_MtApi_Base_Hd_SetPri1stGeometricScalingCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetHDPri1stGeometricScalingCfgCmd( IN CONST TMTHDImageGeometricScaling_Api &tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
*  KdvMt_CFGGetHDPri1stGeometricScalingCfg 
* 
* @brief 获取第一路主视频等比缩放
* 
* @param    [out]  tCfg   第一路主视频等比缩放
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MtApi_Base_Hd_SetPri1stGeometricScalingCfg_Ntf, Ev_MtApi_Base_Hd_GetPri1stGeometricScalingCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetHDPri1stGeometricScalingCfg( OUT TMTHDImageGeometricScaling_Api &tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_CFGSetHDPri2ndGeometricScalingCfgCmd 
* 
* @brief 设置第二路主视频等比缩放
* 
* @param    [IN CONST]  tCfg   第二路主视频等比缩放
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 响应通知：Ev_MtApi_Base_Hd_SetPri2ndGeometricScalingCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetHDPri2ndGeometricScalingCfgCmd( IN CONST TMTHDImageGeometricScaling_Api &tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
*  KdvMt_CFGGetHDPri2ndGeometricScalingCfg 
* 
* @brief 获取第二路主视频等比缩放
* 
* @param    [out]  tCfg   第二路主视频等比缩放
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MtApi_Base_Hd_SetPri2ndGeometricScalingCfg_Ntf, Ev_MtApi_Base_Hd_GetPri2ndGeometricScalingCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetHDPri2ndGeometricScalingCfg( OUT TMTHDImageGeometricScaling_Api &tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
*  KdvMt_CFGSetHDAssGeometricScalingCfgCmd 
* 
* @brief 设置辅视频等比缩放
* 
* @param    [IN CONST]  tCfg   辅视频等比缩放
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 响应通知：Ev_MtApi_Base_Hd_SetAssGeometricScalingCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetHDAssGeometricScalingCfgCmd( IN CONST TMTHDImageGeometricScaling_Api &tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
*  KdvMt_CFGGetHDAssGeometricScalingCfg 
* 
* @brief 获取辅视频等比缩放
* 
* @param    [out]  tCfg   辅视频等比缩放
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MtApi_Base_Hd_SetAssGeometricScalingCfg_Ntf, Ev_MtApi_Base_Hd_GetAssGeometricScalingCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetHDAssGeometricScalingCfg( OUT TMTHDImageGeometricScaling_Api &tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
*  KdvMt_CFGSetHDEdgePixelCfgCmd 
* 
* @brief 设置第一路主视频裁边像素
* 
* @param    [IN CONST]  tCfg   第一路主视频裁边像素
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 响应通知：Ev_MtApi_Base_Hd_SetEdgePixelCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetHDEdgePixelCfgCmd( IN CONST u32 dwCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
*  KdvMt_CFGGetHDEdgePixelCfg 
* 
* @brief 获取第一路主视频裁边像素
* 
* @param    [out]  tCfg   第一路主视频裁边像素
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MtApi_Base_Hd_SetEdgePixelCfg_Ntf, Ev_MtApi_Base_Hd_GetEdgePixelCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetHDEdgePixelCfg( OUT u32 &dwCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
*  KdvMt_CFGSetHDCameraListCfgCmd 
* 
* @brief 设置摄像机配置
* 
* @param    [IN CONST]  tCfg   摄像机配置
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 响应通知：Ev_MtApi_Base_Hd_SetCameraListCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetHDCameraListCfgCmd( IN CONST TMTHDCameraList_Api &tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );




/**
*  KdvMt_CFGGetHDCameraListCfg 
* 
* @brief 获取摄像机配置
* 
* @param    [out]  tCfg   摄像机配置
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MtApi_Base_Hd_SetCameraListCfg_Ntf, Ev_MtApi_Base_Hd_GetCameraListCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetHDCameraListCfg( OUT TMTHDCameraList_Api &tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
*  KdvMt_CFGSetHDSerialCtrlCfgCmd 
* 
* @brief 设置串口配置
* 
* @param    [IN CONST]  tCfg   串口配置
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 响应通知：Ev_MtApi_Base_Hd_SetSerialCtrlCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetHDSerialCtrlCfgCmd( IN CONST TMTHDSerialCtrl_Api &tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );




/**
*  KdvMt_CFGGetHDSerialCtrlCfg 
* 
* @brief 获取串口配置
* 
* @param    [out]  tCfg   串口配置
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MtApi_Base_Hd_SetSerialCtrlCfg_Ntf, Ev_MtApi_Base_Hd_GetSerialCtrlCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetHDSerialCtrlCfg( OUT TMTHDSerialCtrl_Api &tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGGetResizeModeCfgReq 
* 
* @brief 获取解码后加黑边、裁边与非等比的视频处理策略请求
* 
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MtApi_Base_Hd_GetResizeModeCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetHDResizeModeCfgReq(IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGSetHDResizeModeCfgCmd 
* 
* @brief 设置解码后加黑边、裁边与非等比的视频处理策略
* 
* @param    [in]   tCfg      处理策略 
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MtApi_Base_Hd_SetResizeModeCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetHDResizeModeCfgCmd(IN CONST TMTResizeMode_Api &tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGGetHDResizeModeCfg 
* 
* @brief 获取解码后加黑边、裁边与非等比的视频处理策略
* 
* @param    [out]   tCfg      处理策略 
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetHDResizeModeCfg( OUT TMTResizeMode_Api &tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/********************硬终端产品Key结束********************/

 
//by-lw-part-datashare end


//by-lw-part-mtsysctrl begin
/**
*  KdvMt_SYSBindService 
* 
* @brief   绑定终端服务
* 
* @param    [in]  tMutSevsInfo       绑定终端服务信息
* @param    [in]   dwSSID            MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note KdvMt_SYSUnBindService
*/
KdvMtAPI u32 KdvMtCALL KdvMt_SYSBindService( IN CONST TMutiTStartUpServiceInfo_Api &tMutSevsInfo, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID  );
/**
*  KdvMt_SYSUnBindService 
* 
* @brief   解绑终端服务
* 
* @param    [in]  aachSysAlias       解绑终端服务别名
* @param    [in]  wCnt               解绑终端服务别名个数
* @param    [in]  dwSSID             MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note KdvMt_SYSBindService
*/
KdvMtAPI u32 KdvMtCALL KdvMt_SYSUnBindService( IN s8 aachSysAlias[][KMTAPI_SYS_MAX_SYSNAME_LEN], IN CONST u16 wCnt, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );
/**
*  KdvMt_SYSStartService 
* 
* @brief   开始终端服务
* 
* @param    [in]  achSysAlias        开始终端服务别名(用户管理：access, 网管：agent, 内置多点会议：mcservice, 其他：misc, 媒体编解码：mtmp, 平台http API：rest, 升级：upgrade, 点播：vod, 通话记录和本地地址簿：record, 聊天：im, 会议：mtpa)
* @param    [in]   dwSSID            MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note KdvMt_SYSStopService，结果通知Ev_MtApi_Base_SrvStartResult_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_SYSStartService( IN s8 achSysAlias[KMTAPI_SYS_MAX_SYSNAME_LEN], IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );
/**
*  KdvMt_SYSStopService 
* 
* @brief   停止终端服务
* 
* @param    [in]  achSysAlias        开始终端服务别名
* @param    [in]   dwSSID            MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note KdvMt_SYSStartService，结果通知Ev_MtApi_Base_SrvEndtResult_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_SYSStopService( IN s8 achSysAlias[KMTAPI_SYS_MAX_SYSNAME_LEN], IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );
/**
*  KdvMt_SYSBindDefService 
* 
* @brief   绑定默认终端服务
* 
* @param    [in]   dwSSID            MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 
*/
KdvMtAPI u32 KdvMtCALL KdvMt_SYSBindDefService( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );
/**
*  KdvMt_SYSAddDefService 
* 
* @brief   增加默认终端服务
*
* @param    [in]   tMutSevsDefInfo            默认终端服务信息 
* @param    [in]   dwSSID                     MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note KdvMt_SYSMdDefService KdvMt_SYSDelDefService
*/
KdvMtAPI u32 KdvMtCALL KdvMt_SYSAddDefService( IN CONST TMutiTServiceDefInfo_Api &tMutSevsDefInfo, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );
/**
*  KdvMt_SYSMdDefService 
* 
* @brief   修改默认终端服务
*
* @param    [in]   tMutSevsDefInfo            默认终端服务信息 
* @param    [in]   dwSSID                     MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note KdvMt_SYSAddDefService KdvMt_SYSDelDefService
*/
KdvMtAPI u32 KdvMtCALL KdvMt_SYSMdDefService( IN CONST TMutiTServiceDefInfo_Api &tMutSevsDefInfo, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );
/**
*  KdvMt_SYSDelDefService 
* 
* @brief   删除默认终端服务
*
* @param    [in]   achSysAlias                默认终端服务别名
* @param    [in]   dwSSID                     MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note KdvMt_SYSAddDefService KdvMt_SYSMdDefService
*/
KdvMtAPI u32 KdvMtCALL KdvMt_SYSDelDefService( IN s8 achSysAlias[KMTAPI_SYS_MAX_SYSNAME_LEN], IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_LoginApsServerCmd 
* 
* @brief   登陆服务器命令
*
* @param    [in]   tLoginParam               登录参数
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 登陆服务器的响应消息 aps:	Ev_MtApi_Base_ApsLoginResult_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_LoginApsServerCmd( IN TMTApsLoginParam_Api tLoginParam,  IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_ModifyLoginPwdCmd 
* 
* @brief   修改登录平台的密码
*
* @param	[in] tInfo    修改登陆密码信息结构
*
* @return   u32  0：成功获取， 其他：错误码 
*
* @note
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ModifyLoginPwdCmd( IN CONST TMTModifyPwdInfo_Api tInfo,  IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_CFGGetHDMainPriDisplayRatioCfg 
* 
* @brief 获取主视频第一路显示比率
* 
* @param    [out]  tDisplayRatio   视频输出显示比例
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：, 
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetHDPri1stDisplayRatioCfg( OUT THDMTDisplayRatio_Api& tDisplayRatio, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_CFGGetHDMainPriDisplayRatioCfgReq 
* 
* @brief    获取主视频第一路显示比率请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_Hd_GetMainFstDisplayRatioCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetHDPri1stDisplayRatioCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGSetHDMainPriDisplayRatioCfgCmd 
* 
* @brief 设置主视频第一路显示比率
* 
* @param    [IN CONST]  tDisplayRatio   视频输出显示比例
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 响应通知：Ev_MtApi_Base_Hd_SetMainFstDisplayRatioCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetHDPri1stDisplayRatioCfgCmd( IN CONST THDMTDisplayRatio_Api& tDisplayRatio, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_CFGGetHDMainSecDisplayRatioCfg 
* 
* @brief 获取主视频第二路显示比率
* 
* @param    [out]  tDisplayRatio   视频输出显示比例
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知： 
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetHDPri2ndDisplayRatioCfg( OUT THDMTDisplayRatio_Api& tDisplayRatio, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_CFGGetHDMainSecDisplayRatioCfgReq 
* 
* @brief    获取主视频第二路显示比率请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_Hd_GetMainSecDisplayRatioCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetHDPri2ndDisplayRatioCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGSetHDMainSecDisplayRatioCfgCmd 
* 
* @brief 设置主视频第二路显示比率
* 
* @param    [IN CONST]  tDisplayRatio   视频输出显示比例
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 响应通知：Ev_MtApi_Base_Hd_SetMainSecDisplayRatioCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetHDPri2ndDisplayRatioCfgCmd( IN CONST THDMTDisplayRatio_Api& tDisplayRatio, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_CFGGetHDMainPriDisplayRatioCfg 
* 
* @brief 获取辅视频显示比率
* 
* @param    [out]  tDisplayRatio   视频输出显示比例
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetHDAssDisplayRatioCfg( OUT THDMTDisplayRatio_Api& tDisplayRatio, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_CFGGetHDMainPriDisplayRatioCfgReq 
* 
* @brief    获取辅视频显示比率请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MT_BLL_HD_GetAssDisplayRatioCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetHDAssDisplayRatioCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGSetHDMainPriDisplayRatioCfgCmd 
* 
* @brief 设置辅视频显示比率
* 
* @param    [IN CONST]  tDisplayRatio   视频输出显示比例
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 响应通知：Ev_MT_BLL_HD_SetAssDisplayRatioCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetHDAssDisplayRatioCfgCmd( IN CONST THDMTDisplayRatio_Api& tDisplayRatio, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_CFGSetLoginApsParamCfgCmd 
* 
* @brief    设置登录IM所需要的参数请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_GetLoginIMParamCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetLoginImParamCfgCmd(  IN CONST TImUserLogin_Api tLoginParam, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGSetLoginApsParamCfgCmd 
* 
* @brief    设置登录APS所需要的参数请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：
    Ev_MtApi_Base_ApsLoginResult_Ntf    // 登录aps返回的消息，该注释只针对硬终端
    Ev_MtApi_Vc_RegResult_Ntf                // 注册会议服务器返回的消息，如果登录aps失败，则不发送此消息，该注释只针对硬终端
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetLoginApsParamCfgCmd(  IN CONST TMTApsLoginParam_Api tLoginParam, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGGetLoginApsParamCfgCmd 
* 
* @brief    获取登录APS所需要的参数
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetLoginApsParamCfg(  OUT TMTApsLoginParam_Api &tLoginParam, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGSetNmsClientHWInfoCfgCmd 
* 
* @brief    登录Nms所需要的客户端硬件信息参数
*
* @param    [in] tNMSClientHWInfo  登录Nms所需要的客户端硬件信息参数
* @param    [in] dwSSID            MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetNmsClientHWInfoCfgCmd(  IN CONST TNMSClientHWInfo_Api tNMSClientHWInfo, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGSetLoginSusParamCfgCmd 
* 
* @brief    设置登录SUS所需要的参数请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetLoginSusParamCfgCmd(  IN CONST TMTUpgradeClientInfo_Api tLoginParam, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_LoginNmsServerCmd 
* 
* @brief   登陆网管服务器命令
*
* @param    [in]   tLoginParam               登录参数
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 登陆服务器的响应消息 	Ev_MtApi_Base_AgentLogInResult_Ntf	

*/
KdvMtAPI u32 KdvMtCALL KdvMt_LoginNmsServerCmd( IN TMtNMAAddr_Api tLoginParam,  IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_LogoutNmsServerCmd 
* 
* @brief   退出登陆网管服务器命令
*
* @param    [in]   tLoginParam               登录参数
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 登陆服务器的响应消息 		

*/
KdvMtAPI u32 KdvMtCALL KdvMt_LogoutNmsServerCmd( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_LogoutApsServerCmd 
* 
* @brief   退出登陆APS服务器命令
*
* @param    [in]   tLoginParam  登录参数
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 登陆服务器的响应消息 		

*/
KdvMtAPI u32 KdvMtCALL KdvMt_LogoutApsServerCmd( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_LoginPlatformAPIReq 
* 
* @brief   登录API服务器命令 (登录API服务器会同时登陆Weibo服务器和Meeting服务器)
*
* @param    [in]   tAPI    登录参数
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 登陆服务器的响应消息 Ev_MtApi_RestPlatformAPILogin_Rsp		

*/
KdvMtAPI u32 KdvMtCALL KdvMt_LoginPlatformAPIReq( TMTWeiboLogin_Api &tAPI, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_LogOutPlatformAPICmd 
* 
* @brief   登出API服务器命令 ()
*
* @return   u32  0：成功获取， 其他：错误码 
*
* @note		

*/
KdvMtAPI u32 KdvMtCALL KdvMt_LogOutPlatformAPICmd( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

//by-lw-part-mtsysctrl end


/**
*  KdvMt_PPPoEConnectCmd 
* 
* @brief PPPoE 拨号连接请求
* 
* @param    [in]   dwSSID       MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MtApi_PPPoE_LinkState_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_PPPoEConnectCmd( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );




/**
*  KdvMt_PPPoEDisConnectCmd 
* 
* @brief PPPoE 断开请求
* 
* @param    [in]   dwSSID       MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MtApi_PPPoE_LinkState_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_PPPoEDisConnectCmd( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
*  KdvMt_PPPoEGetLinkStateReq 
* 
* @brief PPPoE 连接状态查询请求
* 
* @param    [in]   dwSSID       MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 响应：Ev_MtApi_PPPoE_GetLinkState_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_PPPoEGetLinkStateReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_PPPoEGetStatisInfoReq 
* 
* @brief PPPoE 统计信息查询请求
* 
* @param    [in]   dwEthId      网卡id 
* @param    [in]   dwSSID       MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 响应：Ev_MtApi_PPPoE_GetStatisInfo_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_PPPoEGetStatisInfoReq( IN CONST u32 dwEthId, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_EthernetGetDHCPLeaseInfoReq 
* 
* @brief dhcp租约和状态信息查询请求
* 
* @param    [in]   dwEthId      网卡id 
* @param    [in]   dwSSID       MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 响应：Ev_MtApi_Ethernet_GetDHCPLeaseInfo_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_EthernetGetDHCPLeaseInfoReq( IN CONST u32 dwEthId, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_EthernetGetPreferredIpParamReq 
* 
* @brief 获取以太网首选IP参数
* 
* @param    [in]   dwEthId      网卡id 
* @param    [in]   dwSSID       MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 响应：Ev_MtApi_Ethernet_PreferredIpParam_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_EthernetGetPreferredIpParamReq( IN CONST u32 dwEthId, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_RouteGetAllRouteReq 
* 
* @brief 获取所有路由请求
* 
* @param    [in]   dwSSID       MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 响应：Ev_MtApi_ROUTE_GetAllRoute_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_RouteGetAllRouteReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_RouteAddRouteReq 
* 
* @brief 新增一条路由请求
*
* @param    [in]   tRouteInfo     新增路由信息
* @param    [in]   dwSSID       MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 响应：Ev_MtApi_ROUTE_AddRouteResult_Rsp,Ev_MtApi_ROUTE_AddRoute_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_RouteAddRouteReq(CONST TRouteItemInfo_Api  & tRouteInfo ,IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_RouteDelRouteReq 
* 
* @brief 删除一条路由请求
*
* @param    [in]   tRouteInfo      删除的路由信息
* @param    [in]   dwSSID       MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 响应：Ev_MtApi_ROUTE_DelRouteResult_Rsp,Ev_MtApi_ROUTE_DelRoute_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_RouteDelRouteReq(CONST TRouteItemInfo_Api &  tRouteInfo ,IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_RouteModifyRouteReq 
* 
* @brief 修改一条路由请求
*
* @param    [in]   tOldRouteInfo      要修改的路由信息
* @param    [in]   tNewRouteInfo      修改后的路由信息
* @param    [in]   dwSSID       MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 响应：Ev_MtApi_ROUTE_ModifyRouteResult_Rsp,Ev_MtApi_ROUTE_ModifyRoute_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_RouteModifyRouteReq(CONST TRouteItemInfo_Api &  tOldRouteInfo,CONST TRouteItemInfo_Api  & tNewRouteInfo ,IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_RouteGetDefaultRouteReq 
* 
* @brief 获取默认路由请求
* 
* @param    [in]   dwSSID       MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 响应：Ev_MtApi_Base_GetDefRoute_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_RouteGetDefaultRouteReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_GetSysDataTimeReq 
* 
* @brief  查询当前日期时间信息
* 
* @param    [in]   dwSSID       MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MTApi_GetSysDataTime_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_GetSysDataTimeReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_GetNTPSvrParamReq 
* 
* @brief 查询当前日期时间信息
* 
* @param    [in]   dwSSID       MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MTApi_GetNTPSvrParam_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_GetNTPSvrParamReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_SetSysDataTimeReq 
* 
* @brief 设置当前日期时间信息
*
* @param    [in]   tTime       时间信息
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 响应：Ev_MTApi_SetSysDataTime_Ntf ,Ev_MTApi_SetSysDataTimeResult_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_SetSysDataTimeReq(CONST TMTTime_Api  & tTime ,IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_SetNTPSvrParamReq 
* 
* @brief 设置NTP服务开启关闭状态
*
* @param    [in]   tNtpInfo     ntp信息
* @param    [in]   dwSSID       MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 响应：Ev_MTApi_SetNTPSvrParamResult_Rsp,Ev_MTApi_SetNTPSvrParam_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_SetNTPSvrParamReq(CONST TMTNTPInfo_Api  & tNtpInfo ,IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
*  KdvMt_GetSysDataTime 
* 
* @brief 当前日期时间信息 状态获取
*
* @param    [in]   tTime       时间信息
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 响应：,
*/
KdvMtAPI u32 KdvMtCALL KdvMt_GetSysDataTime( TMTTime_Api  & tTime ,IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_GetNTPSvrParam 
* 
* @brief 当前NTP服务开启状态获取
*
* @param    [in]   tNtpInfo     ntp信息
* @param    [in]   dwSSID       MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 响应：,
*/
KdvMtAPI u32 KdvMtCALL KdvMt_GetNTPSvrParam( TMTNTPInfo_Api  & tNtpInfo ,IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
*  KdvMt_WIFIStartScanReq 
* 
* @brief Wifi 热点扫描请求
* 
* @param    [in]   dwSSID       MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MtApi_WIFI_ScanResult_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_WIFIStartScanReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_WIFIGetWorkModeReq 
* 
* @brief Wifi 工作模式查询请求
* 
* @param    [in]   dwSSID       MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 响应：Ev_MtApi_WIFI_GetWorkMode_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_WIFIGetWorkModeReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_WIFIConnectCmd 
* 
* @brief Wifi 热点连接请求
*
* @param    [in]   tWifiParam   Wifi 连接参数
* @param    [in]   dwSSID       MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MtApi_WIFI_LinkState_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_WIFIConnectCmd( IN CONST TWifiConnParam_Api & tWifiParam, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_WIFIDisConnectCmd 
* 
* @brief Wifi 断开热点连接请求
* 
* @param    [in]   dwSSID       MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note Ev_MtApi_WIFI_LinkState_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_WIFIDisConnectCmd( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_WifiGetLinkStateReq 
* 
* @brief Wifi连接状态查询
* 
* @param    [in]   dwSSID       MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note Ev_MtApi_WIFI_LinkState_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_WifiGetLinkStateReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_WifiGetModClientPropertyReq 
* 
* @brief Wifi 获取当前连接的Wifi客户端属性请求
* 
* @param    [in]   dwSSID       MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note Ev_MtApi_WIFI_GetModClientProperty_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_WifiGetModClientPropertyReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_WifiGetWifiCurConnectedInfoReq 
* 
* @brief Wifi 获取当前连接的Wifi客户端详细信息请求
* 
* @param    [in]   dwSSID       MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note Ev_MtApi_WIFI_GetWifiCurConnectedInfo_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_WifiGetWifiCurConnectedInfoReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_GetCurWifiStatisInfoReq 
* 
* @brief Wifi 当前连接的Wifi统计信息查询请求
* 
* @param    [in]   dwSSID       MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MtApi_WIFI_GetCurWifiStatisInfo_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_GetCurWifiStatisInfoReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_MobileDataGetWorkModeReq 
* 
* @brief MobileData 工作模式信息查询请求
* 
* @param    [in]   dwSSID       MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MtApi_MOBILEDATA_GetWorkMode_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_MobileDataGetWorkModeReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_MobileDataGetDetailInfoReq 
* 
* @brief MobileData 查询移动数据连接后详细消息请求
* 
* @param    [in]   dwSSID       MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MtApi_MOBILEDATA_GetDetailInfo_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_MobileDataGetDetailInfoReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_MobileDataGetCurStatisInfoReq 
* 
* @brief MobileData 当前连接的移动数据统计信息查询请求
* 
* @param    [in]   dwSSID       MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MtApi_MOBILEDATA_GetCurStatisInfo_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_MobileDataGetCurStatisInfoReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_PingTestCmd 
* 
* @brief ping测试命令
* 
* @param    [in]   tPingTestParam  ping测试参数
* @param    [in]   dwSSID          MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MtApi_NET_PingTestResult_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_PingTestCmd(IN CONST TPingTestParam_Api &tPingTestParam, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_EthernetGetIpByDNSInfoReq 
* 
* @brief DNS查询IP
* 
* @param    [in]   TDNSNameToIpInfo_Api  DNS名称
* @param    [in]   dwSSID          MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MTApi_Ethernet_GetIpByDNSInfo_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_EthernetGetIpByDNSInfoReq(IN CONST TDNSNameToIpInfo_Api &tDnsName, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_GetPPPoELinkState 
* 
* @brief PPPoE 状态获取
*
* @param    [out]   tPPPoEInfo   PPPoE连接后详细信息
* @param    [in]   dwSSID       MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：
*/
KdvMtAPI u32 KdvMtCALL KdvMt_GetPPPoELinkState( OUT TPPPoEState_Api & tPPPoEInfo, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_GetWifiScanList 
* 
* @brief 获取热点扫描结果
* 
* @param    [out]  tWifiList    Wifi 扫描结果列表
* @param    [in]   dwSSID       MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：
*/
KdvMtAPI u32 KdvMtCALL KdvMt_GetWifiScanList( OUT TWifiScanResultList_Api & tWifiList, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_GetWifiCurDetailInfo 
* 
* @brief 当前连接状态
* 
* @param    [out]  tWifiList    当前Wifi连接的详细信息
* @param    [in]   dwSSID       MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：
*/
KdvMtAPI u32 KdvMtCALL KdvMt_GetWifiCurDetailInfo( OUT TWifiCurDetailInfo_Api & tCurWifiInfo, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_GetWifiStatisInfo 
* 
* @brief Wifi统计信息
* 
* @param    [out]  tWifiStatisInfo    当前Wifi连接的统计信息
* @param    [in]   dwSSID       MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：
*/
KdvMtAPI u32 KdvMtCALL KdvMt_GetWifiStatisInfo( OUT TWifiStatisInfo_Api & tWifiStatisInfo, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
*  KdvMt_ReportAgentMtPFMInfo 
* 
* @brief 上报终端设备性能
* 
* @param    [in]   tInfo_Api    终端设备性能
* @param    [in]   dwSSID       MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ReportAgentMtPFMInfo( IN CONST TMtPFMInfo_Api& tInfo_Api,  IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_AgentCrashLogReportCmd 
* 
* @brief 异常文件内容上报
* 
* @param    [in]   tCrashLog_Api    异常日志
* @param    [in]   dwSSID           MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 
*/
KdvMtAPI u32 KdvMtCALL KdvMt_AgentCrashLogReportCmd(IN CONST TExceptionFileReportData_Api &tCrashLog_Api,  IN CONST SessionID dwSSID = KMTAPI_DEF_SSID);

/**
*  KdvMt_AgentShoudConnectServersReportCmd 
* 
* @brief 需要连接的服务器上报
* 
* @param    [in]   aemServers    需要连接的服务器
* @param    [in]   wCount        aemServers数组的元素数目
* @param    [in]   dwSSID           MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 
*/
KdvMtAPI u32 KdvMtCALL KdvMt_AgentShoudConnectServersReportCmd(IN CONST EmServerType_Api aemServers[], IN CONST u16 wCount, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID);

/**
*  KdvMt_CfgSetMtWizardResultCfgCmd 
* 
* @brief 设置终端是否已走完设置向导
* 
* @param    [in]   bCfg               TRUE：已走完
* @param    [in]   dwSSID           MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MtApi_Base_SetHasWizardConfigedCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CfgSetMtWizardResultCfgCmd(IN CONST BOOL32 &bCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID);

/**
*  KdvMt_CfgGetMtWizardResultCfg 
* 
* @brief 查询终端是否已走完设置向导
* 
* @param    [out]   bCfg            TRUE：已走完
* @param    [in]   dwSSID           MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CfgGetMtWizardResultCfg(OUT BOOL32 &bCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID);

/**
*  KdvMt_CfgGetMtWizardResultCfgReq 
* 
* @brief 查询终端是否已走完设置向导请求
* 
* @param    [in]   dwSSID           MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MtApi_Base_SetHasWizardConfigedCfg_Ntf，Ev_MtApi_Base_GetHasWizardConfigedCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CfgGetMtWizardResultCfgReq(IN CONST SessionID dwSSID = KMTAPI_DEF_SSID);

/**
*  KdvMt_RtGetGKRegistRtReq 
* 
* @brief 查询终端是否已注册上GK
* 
* @param    [in]   dwSSID           MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MtApi_Base_GetIsGkRigistedRt_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_RtGetGKRegistRtReq(IN CONST SessionID dwSSID = KMTAPI_DEF_SSID);

/**
*  KdvMt_RtGetSipRegistRtReq 
* 
* @brief 查询终端是否已注册上Sip
* 
* @param    [in]   dwSSID           MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MtApi_Base_GetIsSipRigistedRt_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_RtGetSipRegistRtReq(IN CONST SessionID dwSSID = KMTAPI_DEF_SSID);

/**
*  KdvMt_RtGetDcsRegistRtReq 
* 
* @brief 查询终端是否已注册上Dsc
* 
* @param    [in]   dwSSID           MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MtApi_Base_GetIsDcsRigistedRt_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_RtGetDcsRegistRtReq(IN CONST SessionID dwSSID = KMTAPI_DEF_SSID);

/**
*  KdvMt_CfgSetFastCallListCfgCmd 
* 
* @brief 配置快速呼叫列表
* 
* @param    [in]   tFastCallList     呼叫列表
* @param    [in]   dwSSID           MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MtApi_Base_SetFastCallListCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CfgSetFastCallListCfgCmd(IN CONST TFastCallList_Api &tFastCallList, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID);

/**
*  KdvMt_CfgGetFastCallListCfg 
* 
* @brief 获取快速呼叫列表配置
* 
* @param    [out]   tFastCallList     呼叫列表
* @param    [in]   dwSSID           MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CfgGetFastCallListCfg(OUT TFastCallList_Api &tFastCallList, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID);

/**
*  KdvMt_CfgGetFastCallListCfgReq
* 
* @brief 获取快速呼叫列表配置请求
* 
* @param    [in]   dwSSID           MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MtApi_Base_GetFastCallListCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CfgGetFastCallListCfgReq(IN CONST SessionID dwSSID = KMTAPI_DEF_SSID);

/**
*  KdvMt_RtGetImLoginHandleReq
* 
* @brief 获取IM模块登录句柄请求
* 
* @param    [in]   dwSSID           MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MtApi_Base_GetIMHandleRt_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_RtGetImLoginHandleReq(IN CONST SessionID dwSSID = KMTAPI_DEF_SSID);

/**
*  KdvMt_CfgSetShowConfNameCfgCmd 
* 
* @brief 配置显示会议名称
* 
* @param    [in]   bShow            TRUE：显示
* @param    [in]   dwSSID           MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MtApi_Base_SetShowConfNameCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CfgSetShowConfNameCfgCmd(IN CONST BOOL32 &bShow, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID);

/**
*  KdvMt_CfgGetShowConfNameCfg 
* 
* @brief 获取是否显示会议名称配置
* 
* @param    [out]   bShow          是否显示
* @param    [in]   dwSSID           MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CfgGetShowConfNameCfg(OUT BOOL32 &bShow, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID);

/**
*  KdvMt_CfgGetShowConfNameCfgReq
* 
* @brief 获取是否显示会议名称配置请求
* 
* @param    [in]   dwSSID           MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MtApi_Base_GetShowConfNameCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CfgGetShowConfNameCfgReq(IN CONST SessionID dwSSID = KMTAPI_DEF_SSID);

/**
*  KdvMt_SetFtpTelnetAccountInfoReq
* 
* @brief 设置Ftp/Telnet账号信息
* 
* @param    [in]   tAccountInfo   账号信息 
* @param    [in]   dwSSID           MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MTApi_Base_SetFtpTelnetAccountInfo_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_SetFtpTelnetAccountInfoReq(IN CONST TMTFtpTelnetAccountInfo_Api tAccountInfo, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID);

/**
*  KdvMt_SetTelnetFtpUserInfoCfgCmd
* 
* @brief 设置Ftp/Telnet登录用户名、密码
* 
* @param    [in]   tAccountInfo   账号信息 
* @param    [in]   dwSSID           MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MTApi_Base_SetTelnetFtpUserInfoCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CfgSetTelnetFtpUserInfoCfgCmd(IN CONST TMTFtpTelnetAccountInfo_Api tAccountInfo, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID);

/**
*  KdvMt_GetTelnetFtpUserInfoCfg
* 
* @brief 获取Ftp/Telnet登录用户名、密码
* 
* @param    [in]   tAccountInfo   账号信息 
* @param    [in]   dwSSID           MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CfgGetTelnetFtpUserInfoCfg(OUT TMTFtpTelnetAccountInfo_Api &tAccountInfo, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID);

/**
*  KdvMt_GetTelnetFtpUserInfoCfgReq
* 
* @brief 获取Ftp/Telnet登录用户名、密码请求
* 
* @param    [in]   dwSSID           MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MTApi_Base_GetTelnetFtpUserInfoCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CfgGetTelnetFtpUserInfoCfgReq(IN CONST SessionID dwSSID = KMTAPI_DEF_SSID);

/**
*  KdvMt_GetRfMatchStateListCfgReq
* 
* @brief 获取终端射频配对状态列表
* 
* @param    [in]   dwSSID           MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MTApi_Base_GetRfMatchStateListCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_GetRfMatchStateListCfgReq(IN CONST SessionID dwSSID = KMTAPI_DEF_SSID);

/**
*  KdvMt_SetWIFIModClientPropertyCmd
* 
* @brief 设置当前连接的wifi配置
* 
* @param    [in]   tWifiConfig     wifi配置 
* @param    [in]   dwSSID           MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MTApi_Base_WIFI_ModClientProperty_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_SetWIFIModClientPropertyCmd(IN CONST TWifiConfiguration_Api tWifiConfig, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID);

/**
*  KdvMt_GetEthernetLinkStateReq
* 
* @brief 请求所有以太网卡的连接状态
* 
* @param    [in]   dwSSID           MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MTApi_Base_Ethernet_GetLinkState_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_GetEthernetLinkStateReq(IN CONST SessionID dwSSID = KMTAPI_DEF_SSID);

/**
*  KdvMt_CFGForceSetH323StackCfgCmd 
* 
* @brief    强制设置H323协议类型(标准/非标)命令 注：当自建终端登陆自荐平台时，界面设置enable为true时底下才会使用bstand的值
* 
* @param	[in] TForceSetH323Stack_Api [ enable true强制设置/false不设置 bstand  协议类型 true:标准 false:非标 ]
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_ForceSet323StackCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGForceSetH323StackCfgCmd( IN CONST TForceSetH323Stack_Api tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CfgGetForceH323StackCfgReq 
* 
* @brief    获取配置请求， 配置用来强制设置H323协议类型(标准/非标)命令 注：当自建终端登陆自荐平台时，界面设置enable为true时底下才会使用bstand的值
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_GetForceH323StackCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CfgGetForceH323StackCfgReq(IN CONST SessionID dwSSID = KMTAPI_DEF_SSID);


/**
*  KdvMt_CfgGetForceH323StackCfg 
* 
* @brief    获取配置， 配置用来强制设置H323协议类型(标准/非标)命令 注：当自建终端登陆自荐平台时，界面设置enable为true时底下才会使用bstand的值
* 
* @param    [in] dwSSID  MT会话ID，[out]TForceSetH323Stack_Api
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_ForceSet323StackCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CfgGetForceH323StackCfg( OUT TForceSetH323Stack_Api &tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGSetServerLoginPortCfgCmd 
* 
* @brief 设置服务器登录端口命令(目前只针对APS的登录端口)
* 
* @param	[in] TServerLoginPort_Api    端口号
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_SetServerLoginPortCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetServerLoginPortCfgCmd( IN CONST TServerLoginPort_Api &tPort, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGGetServerLoginPortCfgReq 
* 
* @brief 获取服务器登录端口请求(目前只针对APS的登录端口)
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_GetServerLoginPortCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetServerLoginPortCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGGetServerLoginPortCfg
* 
* @brief 获取服务器登录端口(目前只针对APS的登录端口)
* 
* @param    [out] TServerLoginPort_Api   端口号
* @param    [in]   dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetServerLoginPortCfg( OUT TServerLoginPort_Api &tPort, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGSetVideoOutTagCfgCmd  (仅Embed)
* 
* @brief   设置视频输出标签
* 
* @param    [in]   tCfg        视频输出标签
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:	Ev_MtApi_Base_Hd_SetVideoOutTagCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetVideoOutTagCfgCmd( IN CONST TMTVideoOutTagList_Api& tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGGetVideoOutTagCfgReq 
* 
* @brief    获取视频输出标签请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_Hd_GetVideoOutTagCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetVideoOutTagCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_CFGGetVideoOutTagCfg 
* 
* @brief   获取视频输出标签
* 
* @param    [out]  tCfg        视频输出标签
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:	Ev_MtApi_Base_Hd_SetVideoOutTagCfg_Ntf, Ev_MtApi_Base_Hd_GetVideoOutTagCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetVideoOutTagCfg( OUT TMTVideoOutTagList_Api &tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGSetSDIOneInOneOutOrTwoInCfgCmd  (仅Embed)
* 
* @brief   设置SDI一进一出或者两进(value: TU32)   Ev_MT_BLL_HD_SetSDIOneInOneOutOrTwoInCfg_Cmd
* 
* @param    [in]   u32        // 0：一进一出 1：两进
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:	Ev_MtApi_Base_Hd_SetSDIOneInOneOutOrTwoInCfg_Ntf 
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetSDIOneInOneOutOrTwoInCfgCmd( IN CONST u32& dwType, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGGetSDIOneInOneOutOrTwoInCfgReq 
* 
* @brief    获取SDI一进一出或者两进(value: TU32)
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_Hd_GetSDIOneInOneOutOrTwoInCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetSDIOneInOneOutOrTwoInCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_CFGGetSDIOneInOneOutOrTwoInCfg 
* 
* @brief   获取SDI一进一出或者两进(value: TU32)
* 
* @param    [out]  u32        // 0：一进一出 1：两进
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:	Ev_MtApi_Base_Hd_SetSDIOneInOneOutOrTwoInCfg_Ntf, Ev_MtApi_Base_Hd_GetSDIOneInOneOutOrTwoInCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetSDIOneInOneOutOrTwoInCfg( OUT u32& dwType, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGSetSerialListCfgCm 
* 
* @brief   设置串口列表
* 
* @param    [in]  tCfg        // 串口列表
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:	Ev_MtApi_Base_Hd_SetSerialListCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetSerialListCfgCmd( IN CONST TMTHDSerialList_Api &tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_CFGGetSerialListCfgReq 
* 
* @brief   获取串口列表
* 
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:	Ev_MtApi_Base_Hd_GetSerialListCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetSerialListCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGGetSerialListCfg
* 
* @brief   获取串口列表
* 
* @param    [out]  tCfg        // 串口列表
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:	Ev_MtApi_Base_Hd_GetSerialListCfg_Rsp,Ev_MtApi_Base_Hd_SetSerialListCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetSerialListCfg( OUT TMTHDSerialList_Api &tCfg,IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGSetTRtpSamePortCfgCmd 
* 
* @brief 设置是否端口复用
* 
* @param	[in] bSamePort    端口复用
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MT_BLL_SetTRtpSamePortCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetTRtpSamePortCfgCmd( IN BOOL32 &bSamePort, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGGetTRtpSamePortCfgReq 
* 
* @brief 获取是否端口复用
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MT_BLL_GetTRtpSamePortCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetTRtpSamePortCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGGetTRtpSamePortCfg
* 
* @brief 获取是否端口复用
* 
* @param    [out] bSamePort   端口复用
* @param    [in]   dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MT_BLL_GetTRtpSamePortCfg_Rsp,Ev_MT_BLL_SetTRtpSamePortCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetTRtpSamePortCfg( OUT BOOL32 &bSamePort, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGExportMtcfgFileReq
* 
* @brief 导出配置文件(mtcfg.db)请求
*
* @param    [in] pchExpPath	 这里导出路径包括 文件路径+文件名
* @param    [in] dwSSID      MT会话ID 
* @return   u32  0：成功, 其他：错误码 
*
* @note 响应通知：Ev_MtApi_Base_ExportMtcfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGExportMtcfgFileReq(IN CONST s8* pchExpPath, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGImportMtcfgFileReq
* 
* @brief 导入配置文件(mtcfg.db)请求
*
* @param    [in] pchImpPath	 配置文件导入路径
* @param	[in] bReboot	 导入成功后，是否立即重启
* @param    [in] dwSSID      MT会话ID 
* @return   u32  0：成功, 其他：错误码 
*
* @note 响应通知：Ev_MtApi_Base_ImportMtcfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGImportMtcfgFileReq(IN CONST s8* pchImpPath, IN CONST BOOL32 bReboot = FALSE, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*   KdvMt_CFGExportMtDbgcfgFileReq
* 
* @brief 导出debug文件(mtdbgcfg.json)请求
*
* @param    [in] pchExpPath	 这里导出路径包括 文件路径+文件名
* @param    [in] dwSSID      MT会话ID 
* @return   u32  0：成功, 其他：错误码 
*
* @note 响应通知：Ev_MtApi_Base_ExportMtDbgcfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGExportMtDbgcfgFileReq(IN CONST s8* pchExpPath, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGImportMtDbgcfgFileReq
* 
* @brief 导入debug文件(mtdbgcfg.json)请求
*
* @param    [in] pchImpPath	 debug文件导入路径
* @param	[in] bReboot	 导入成功后，是否立即重启
* @param    [in] dwSSID      MT会话ID 
* @return   u32  0：成功, 其他：错误码 
*
* @note 响应通知：Ev_MtApi_Base_ImportMtDbgcfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGImportMtDbgcfgFileReq(IN CONST s8* pchImpPath, IN CONST BOOL32 bReboot = FALSE, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGSetbEnableOccupy
* 
* @brief 设置是否开启会议强拆功能
* 
* @param    [in] bEnable   是否强拆
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_SetConfOccupyCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetbEnableOccupy( IN BOOL32 bEnable, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGSetIsUseIpcCfgCmd 
* 
* @brief 设置是否使用Ipc
* 
* @param	[in] bUseIpc    是否使用Ipc
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetIsUseIpcCfgCmd( IN BOOL32 bUseIpc, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGGetIsUseIpcCfg
* 
* @brief 获取是否使用Ipc
* 
* @param    [out] bUseIpc   是否使用Ipc
* @param    [in]   dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetIsUseIpcCfg( OUT BOOL32 &bUseIpc, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGSetVidDecTypeModeCfgCmd 
* 
* @brief 设置IPC的解码模式
* 
* @param	[in] emVidDecTypeMode   软解或者硬解
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetVidDecTypeModeCfgCmd( IN CONST EmVidDecTypeMode_Api emVidDecTypeMode, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID);


/**
*  KdvMt_CFGSetEnableIpwTypeCfgCmd
* 
* @brief    设置是否启用IPW连接方式
* @param	[in] bEnable  是否启用
* @param    [in] dwSSID   MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_SetEnableIpwType_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetEnableIpwTypeCfgCmd( IN CONST BOOL32 bEnable, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CfgGetEnableIpwTypeCfgReq 
* 
* @brief    获取是否启用了IPW连接方式的请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_GetEnableIpwType_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CfgGetEnableIpwTypeCfgReq(IN CONST SessionID dwSSID = KMTAPI_DEF_SSID);

/**
*  KdvMt_CfgGetEnableIpwTypeCfg
* 
* @brief    获取是否启用了IPW连接
* 
* @param    [in] dwSSID  MT会话ID，[out]TForceSetH323Stack_Api
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：no
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CfgGetEnableIpwTypeCfg( OUT BOOL32 &bEnable, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*KdvMt_SetCameraContrlExchangeCfgCmd
*
* @brief   设置摄像头正向反向
*
* @param    [in]   bDirection       TRUE= 正向 /FALSE=反向
* @param    [in]   dwSSID           MT会话ID 
* @return   u32    0：成功          其他错误码
*
* @note 更新通知：
*/
KdvMtAPI u32 KdvMtCALL KdvMt_SetCameraContrlExchangeCfgCmd( IN CONST BOOL32 bDirection, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*KdvMt_GetCameraContrlExchangeCfg
*
* @brief   获取摄像头正向反向
*
* @param    [out]   bDirection       TRUE= 正向 /FALSE=反向
* @param    [in]   dwSSID           MT会话ID 
* @return   u32    0：成功          其他错误码
*
* @note 更新通知：
*/
KdvMtAPI u32 KdvMtCALL KdvMt_GetCameraContrlExchangeCfg( OUT BOOL32 &bDirection, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*KdvMt_GetCameraContrlExchangeCfgReq
*
* @brief   获取摄像头正向反向
*
* @param    [in]   dwSSID           MT会话ID 
* @return   u32    0：成功          其他错误码
*
* @note 更新通知：
*/
KdvMtAPI u32 KdvMtCALL KdvMt_GetCameraContrlExchangeCfgReq(  IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*KdvMt_SetCameraHeadStandCfgCmd
*
* @brief   设置摄像头是否倒装
*
* @param    [in]   bHeadStand       TRUE= 倒装 /FALSE=不倒装
* @param    [in]   dwSSID           MT会话ID 
* @return   u32    0：成功          其他错误码
*
* @note 更新通知：Ev_MtApi_Base_SetCameraHeadStandCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_SetCameraHeadStandCfgCmd( IN CONST BOOL32 bHeadStand, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*KdvMt_GetCameraHeadStandCfg
*
* @brief   获取摄像头是否倒装
*
* @param    [out]   HeadStand       TRUE= 倒装 /FALSE=不倒装
* @param    [in]   dwSSID           MT会话ID 
* @return   u32    0：成功          其他错误码
*
* @note 更新通知：Ev_MtApi_Base_SetCameraHeadStandCfg_Ntf,Ev_MtApi_Base_GetCameraHeadStandCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_GetCameraHeadStandCfg( OUT BOOL32 &HeadStand, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*KdvMt_GetCameraHeadStandCfgReq
*
* @brief   摄像头是否倒装
*
* @param    [in]   dwSSID           MT会话ID 
* @return   u32    0：成功          其他错误码
*
* @note 更新通知：Ev_MtApi_Base_GetCameraHeadStandCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_GetCameraHeadStandCfgReq(  IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*KdvMt_GetWirelessScreen
*
* @brief   获取无线投屏配对状态
*
* @param    [out]  tCfg             无线投屏配对状态信息
* @param    [in]   dwSSID           MT会话ID 
* @return   u32    0：成功          其他错误码
*
* @note 更新通知：
*/
KdvMtAPI u32 KdvMtCALL KdvMt_GetWirelessScreen( OUT TWifiWirelessScreenInfo_Api &tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*KdvMt_SetWirelessScreenReq
*
* @brief   设置是否无线投屏配对
*
* @param    [in]   bStart           TRUE= 是 /FALSE= 否
* @param    [in]   dwSSID           MT会话ID 
* @return   u32    0：成功          其他错误码
*
* @note 更新通知：Ev_MTApi_Base_SetWirelessScreenStateChange_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_SetWirelessScreenCmd( IN BOOL32 bStart, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*KdvMt_GetWirelessScreenReq
*
* @brief   获取无线投屏配对的请求
*
* @param    [in]   dwSSID           MT会话ID 
* @return   u32    0：成功          其他错误码
*
* @note 更新通知：Ev_MTApi_Base_GetWirelessScreen_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_GetWirelessScreenReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGSetShowInOutConfCfgCmd 
* 
* @brief  设置是否显示与会方入会/离会的提示
* 
* @param    [in]   bShow      是否显示
* @param    [in]   dwSSID     MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:	Ev_MtApi_Base_SetShowInOutConfCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetShowInOutConfCfgCmd( IN CONST BOOL32 bShow, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGGetShowInOutConfCfgReq
* 
* @brief  获取是否显示与会方入会/离会提示的请求
* 
* @param    [in]   dwSSID     MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:	Ev_MtApi_Base_GetShowInOutConfCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetShowInOutConfCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGGetShowInOutConfCfg
* 
* @brief  获取是否显示与会方入会/离会的提示
* 
* @param    [out]  bShow      是否显示
* @param    [in]   dwSSID     MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:  no
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetShowInOutConfCfg( OUT BOOL32 &bShow, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_FtpTelnetSetLimitIpCfgCmd
* 
* @brief 设置ftp/telnet限定ip段配置信息
*
* @param    [in]   tIpInfo      ip段信息
* @param    [in]   dwSSID       MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 响应：Ev_MtApi_Base_FtpTelnet__SetLimitIpCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_FtpTelnetSetLimitIpCfgCmd( IN CONST TMtLimitIpInfoList_Api & tIpInfo, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_FtpTelnetAddLimitIp
* 
* @brief 新增一条ftp/telnet限定ip请求
*
* @param    [in]   tIpInfo      ip段信息
* @param    [in]   dwSSID       MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 响应：Ev_MtApi_Base_FtpTelnet_AddLimitIp_Rsp, Ev_MtApi_Base_FtpTelnet_AddLimitIp_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_FtpTelnetAddLimitIpReq( IN CONST TMtLimitIpInfo_Api & tIpInfo, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_FtpTelnetDelLimitIp
* 
* @brief 删除一条ftp/telnet限定ip请求
*
* @param    [in]   tIpInfo      ip段信息
* @param    [in]   dwSSID       MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 响应：Ev_MtApi_Base_FtpTelnet_DelLimitIp_Rsp, Ev_MtApi_Base_FtpTelnet_DelLimitIp_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_FtpTelnetDelLimitIpReq( IN CONST TMtLimitIpInfo_Api & tIpInfo, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_FtpTelnetModifyLimitIp
* 
* @brief 修改一条ftp/telnet限定ip请求
*
* @param    [in]   tOldIpInfo      要修改的ip信息
* @param    [in]   tNewIpInfo      修改后的ip信息
* @param    [in]   dwSSID       MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 响应：Ev_MtApi_Base_FtpTelnet_ModLimitIp_Rsp, Ev_MtApi_Base_FtpTelnet_ModLimitIp_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_FtpTelnetModifyLimitIpReq( IN CONST TMtLimitIpInfo_Api & tOldIpInfo, IN CONST TMtLimitIpInfo_Api & tNewIpInfo , IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_CFGGetFtpTelnetLimitIpListReq
* 
* @brief    获取ftp/telnet限定ip信息列表请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_Mtapi_Base_Hd_GetFtpTelnetLimitIpListCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetFtpTelnetLimitIpListCfgReq(IN CONST SessionID dwSSID = KMTAPI_DEF_SSID);

/**
*  KdvMt_CFGImportCACertCmd 
* 
* @brief   导入Ca证书命令
* 
* @param    [in]   pchCaCertFileName         导入证书路径
* @param    [in]   dwSSID                 MT会话ID 
* @return   u32  0：成功， 其他：错误码 
*
* @note 回复通知：no
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGImportCACertCmd( IN CONST s8* pchCaCertFileName, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGExportAllCACertReq
* 
* @brief   导出Ca证书请求
* 
* @param    [in]   pchCaCertFileName         导出证书路径
* @param    [in]   dwSSID                 MT会话ID 
* @return   u32  0：成功， 其他：错误码 
*
* @note 更新通知: Ev_MtApi_Base_ExportAllCACert_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGExportAllCACertReq( IN CONST s8* pchCaCertFileName, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGImportCACertCmd 
* 
* @brief   导入设备证书命令
* 
* @param    [in]   pchDeviceCertFileName         导入设备证书路径
* @param    [in]   dwSSID                     MT会话ID 
* @return   u32  0：成功， 其他：错误码 
*
* @note 回复通知：no
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGImportDeviceCertCmd( IN CONST s8* pchDeviceCertFileName, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGExportDeviceCertReq 
* 
* @brief   导出设备证书请求
* 
* @param    [in]   pchDeviceCertFileName         导出设备证书路径
* @param    [in]   dwSSID                     MT会话ID 
* @return   u32  0：成功， 其他：错误码 
*
* @note 更新通知: Ev_MtApi_Base_ExportDeviceCert_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGExportDeviceCertReq( IN CONST s8* pchDeviceCertFileName, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGCreateDeviceCertReq 
* 
* @brief   创建设备证书请求	  注意：若启用重新生成秘钥（即tReq.bResetPwd = TRUE)，重新生成秘钥的时间较长， 经测试为5s—14s不等，
*							        导致消息 Ev_MtApi_Base_CreateDeviceCert_Rsp 响应较慢，上层接收这个响应需要特殊处理。
*
* @param    [in]   tReq       证书信息
* @param    [in]   dwSSID     MT会话ID 
* @return   u32  0：成功， 其他：错误码 
*
* @note 更新通知: Ev_MtApi_Base_CreateDeviceCert_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGCreateDeviceCertReq( IN CONST TMtSecCreateCertReq_Api tReq, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGQueryCACertInfoReq 
* 
* @brief   查询Ca证书请求
* 
* @param    [in]   dwSSID                     MT会话ID 
* @return   u32  0：成功， 其他：错误码 
*
* @note 更新通知: Ev_MtApi_Base_QueryCACertInfo_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGQueryCACertInfoReq( IN CONST TMtSecCerId_Api tCerId, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGQueryDeviceCertInfoReq 
* 
* @brief   查询商密设备证书请求
* 
* @param    [in]   dwSecCertType         设备证书类型, 1:标准TLS, 2:国密签名，3:国密加密 
* @param    [in]   dwSSID                MT会话ID 
* @return   u32  0：成功， 其他：错误码 
*
* @note 更新通知: Ev_MtApi_Base_QueryDeviceCertInfo_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGQueryDeviceCertInfoReq( IN CONST u32 dwSecCertType, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGImportSignCertCmd 
* 
* @brief   导入签名证书命令
* 
* @param    [in]   pchSignCertFileName        导入签名证书路径
* @param    [in]   dwSSID                     MT会话ID 
* @return   u32  0：成功， 其他：错误码 
*
* @note 回复通知：no
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGImportSignCertCmd( IN CONST s8* pchSignCertFileName, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGImportEncPEMCertCmd 
* 
* @brief   导入加密证书命令  该加密证书文件不带私钥key pem格式文件
* 
* @param    [in]   pchEncCertFileName         导入加密证书路径
* @param    [in]   dwSSID                     MT会话ID 
* @return   u32  0：成功， 其他：错误码 
*
* @note 回复通知：no
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGImportEncPEMCertCmd( IN CONST s8* pchEncCertFileName, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGImportEncCertWithKeyCmd 
* 
* @brief   导入加密证书命令  该加密证书文件带私钥key pfx格式文件  该接口调整变成两个接口 KdvMt_CFGImportEncCertCmd  KdvMt_CFGImportKeyPairCmd
* 
* @param    [in]   pchEncCertFileName         导入加密证书路径
* @param    [in]   pchEncCertPwd              pfx文件的保护密码
* @param    [in]   dwSSID                     MT会话ID 
* @return   u32  0：成功， 其他：错误码 
*
* @note 回复通知：no
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGImportEncCertWithKeyCmd( IN CONST s8* pchEncCertFileName, IN CONST s8* pchEncCertPwd, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_ExportSignCertReq 
* 
* @brief   导出签名证书请求
* 
* @param    [in]   pchCertFileName         导出证书路径
* @param    [in]   dwSSID                  MT会话ID 
* @return   u32  0：成功， 其他：错误码 
*
* @note  更新通知： Ev_MtApi_Base_ExportSignCert_Rsp
*/

KdvMtAPI u32 KdvMtCALL KdvMt_ExportSignCertReq( IN CONST s8* pchCertFileName, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID ); 

/**
*  KdvMt_ExportEncCertReq
* 
* @brief    导出加密证书请求
* 
* @param    [in]   pchCertFileName        导出证书路径
* @param    [in]   dwSSID                 MT会话ID 
* @return   u32  0：成功， 其他：错误码 
*
* @note	 更新通知： Ev_MtApi_Base_ExportEncCert_Rsp 
*/

KdvMtAPI u32 KdvMtCALL KdvMt_ExportEncCertReq( IN CONST s8* pchCertFileName, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID ); 

/**
*  KdvMt_CfgGetIsBusiSecMtReq
* 
* @brief   获取是否为商密终端的请求
* 
* @param    [in]   dwSSID                     MT会话ID 
* @return   u32  0：成功， 其他：错误码 
*
* @note		Ev_MtApi_Base_GetIsBusiSecMt_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CfgGetIsBusiSecMtReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CfgGetIsBusiSecMtCfg
* 
* @brief   获取是否为商密终端
* 
* @param    [out]  bIsSecMt                   是否为商密终端
* @param    [in]   dwSSID                     MT会话ID 
* @return   u32  0：成功， 其他：错误码 
*
* @note	响应通知：无
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CfgGetIsBusiSecMtCfg( OUT BOOL32 &bIsSecMt, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGSetSipConnectCfgCmd
* 
* @brief    设置商密 sip连接配置
* @param	[in] tCfg  配置参数
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_SetSipConnectCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetSipConnectCfgCmd( IN CONST EmSipConnectType_Api tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGGetSipConnectCfgReq
* 
* @brief  获取商密 sip连接配置请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_GetSipConnectCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetSipConnectCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGGetSipConnectCfg
* 
* @brief  获取商密 sip连接配置
* 
* @param    [out]  tCfg    sip连接方式
* @param    [in]   dwSSID  MT会话ID 
* @return   u32    MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：无
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetSipConnectCfg( OUT EmSipConnectType_Api &tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGSetEnableStrongAutCmd
* 
* @brief    设置是否开启商密强认证命令
* @param	[in] tCfg  配置参数
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_SetEnableStrongAut_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetEnableStrongAutCmd( IN CONST BOOL32 bEnableAut, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGGetEnableStrongAutReq
* 
* @brief  获取是否开启商密强认证请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_GetEnableStrongAut_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetEnableStrongAutReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGGetEnableStrongAut
* 
* @brief  获取是否开启商密强认证
* 
* @param    [in]   BOOL32  认证
* @param    [in]   dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*q
* @note 响应通知：无
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetEnableStrongAut( OUT BOOL32 &bEnableAut, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGGetCACertIDListReq 
* 
* @brief   获取ca证书id列表请求
* 
* @param    [in]   dwSSID                 MT会话ID 
* @return   u32  0：成功， 其他：错误码 
*
* @note 更新通知: Ev_MtApi_Base_GetCACertIDList_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetCACertIDListReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGExportCACertByIDReq 
* 
* @brief   根据id导出Ca证书请求
* 
* @param    [in]   pchCaid				 证书id
* @param    [in]   pchCaCertFileName		 证书名称
* @param    [in]   dwSSID                MT会话ID 
* @return   u32  0：成功， 其他：错误码 
*
* @note 更新通知: Ev_MtApi_Base_ExportCACertByID_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGExportCACertByIDReq( IN CONST TMtSecCerId_Api tCerId, IN CONST s8* pchCaCertFileName, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGDeleteCACertByIDReq 
* 
* @brief   根据id删除Ca证书请求
* 
* @param    [in]   pchCaid				 证书id
* @param    [in]   dwSSID                MT会话ID 
* @return   u32  0：成功， 其他：错误码 
*
* @note 更新通知: Ev_MtApi_Base_DeleteCACertByID_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGDeleteCACertByIDReq( IN CONST TMtSecCerId_Api tCerId, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CfgGetLicenseIsValidReq
* 
* @brief   获取商密设备许可证是否合法的请求
* 
* @param    [in]   dwSSID                     MT会话ID 
* @return   u32  0：成功， 其他：错误码 
*
* @note		Ev_MtApi_Base_DeviceLicenseIsValidate_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CfgGetLicenseIsValidReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CfgGetLicenseIsValidCfg
* 
* @brief   获取商密设备许可证是否合法
* 
* @param    [out]  bIsValid                   是否可用
* @param    [in]   dwSSID                     MT会话ID 
* @return   u32  0：成功， 其他：错误码 
*
* @note	响应通知：无
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CfgGetLicenseIsValidCfg( OUT BOOL32 &bIsValid, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CfgSetbEnableTlsCertCmd
* 
* @brief   设置是否启用标准TLS设备证书的命令
* 
* @param    [in]   dwSSID                     MT会话ID 
* @return   u32  0：成功， 其他：错误码 
*
* @note		Ev_MtApi_Base_SetUseTlsCertCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CfgSetbEnableTlsCertCmd( IN CONST BOOL32 bEnable, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CfgGetbEnableTlsCertReq
* 
* @brief  获取是否启用标准TLS设备证书的请求
* 
* @param    [in]   dwSSID                     MT会话ID 
* @return   u32  0：成功， 其他：错误码 
*
* @note		Ev_MtApi_Base_GetUseTlsCertCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CfgGetbEnableTlsCertReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CfgGetbEnableTlsCertCfg
* 
* @brief  获取是否启用标准TLS设备证书
* 
* @param    [out]  bEnable    是否启用
* @param    [in]   dwSSID                     MT会话ID 
* @return   u32  0：成功， 其他：错误码 
*
* @note		no
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CfgGetbEnableTlsCertCfg( OUT BOOL32 &bEnable, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_CfgSetbEnableGMTlsCertCmd
* 
* @brief   设置是否启用国密TLS设备证书的命令
* 
* @param    [in]   dwSSID                     MT会话ID 
* @return   u32  0：成功， 其他：错误码 
*
* @note		Ev_MtApi_Base_SetUseGMTlsCertCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CfgSetbEnableGMTlsCertCmd( IN CONST BOOL32 bEnable, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CfgGetbEnableGMTlsCertReq
* 
* @brief  获取是否启用国密TLS设备证书的请求
* 
* @param    [in]   dwSSID                     MT会话ID 
* @return   u32  0：成功， 其他：错误码 
*
* @note		Ev_MtApi_Base_GetUseGMTlsCertCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CfgGetbEnableGMTlsCertReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CfgGetbEnableGMTlsCertCfg
* 
* @brief  获取是否启用国密TLS设备证书
* 
* @param    [out]  bEnable    是否启用
* @param    [in]   dwSSID                     MT会话ID 
* @return   u32  0：成功， 其他：错误码 
*
* @note		no
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CfgGetbEnableGMTlsCertCfg( OUT BOOL32 &bEnable, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_ResumeKedaCaCert_Cmd
* 
* @brief  恢复预置的科达Ca证书
* 
* @param    [in]   dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：无
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ResumeKedaCaCert_Cmd(IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_EnterDynamicPassword_Cmd
* 
* @brief  用户输入动态口令
* 
* @param    [out]  pchDynPwd     动态口令
* @param    [in]   dwSSID  MT会话ID 
* @return   u32    MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_StrongAuthEnd_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_EnterDynamicPassword_Cmd( IN CONST s8* pchDynPwd, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_CancelStrongAuth_Cmd
* 
* @brief  取消强认证
* 
* @param    [in]   dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_StrongAuthEnd_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CancelStrongAuth_Cmd(IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



///////////商密接口 end

/**
*  KdvMt_GetAssVideoPortStatusReq 
* 
* @brief   获取辅视频源是否有源请求( 仅x300/sky300使用, x700使用无效 )
* 
* @param    [in]   dwSSID                     MT会话ID 
* @return   u32  0：成功， 其他：错误码 
*
* @note		Ev_MtApi_Base_GetAssVideoPortStatus_Rsp 
*/
KdvMtAPI u32 KdvMtCALL KdvMt_GetAssVideoPortStatusReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_ChooseSerialUseCmd 
* 
* @brief   选择串口是否使用的命令 (给网呈用的)
* 
* @param    [in]   tInfo			串口信息
* @param    [in]   bIsUse		    是否使用
* @param    [in]   dwSSID           MT会话ID 
* @return   u32  0：成功， 其他：错误码 
*
* @note 更新通知: Ev_MtApi_Base_ChooseSerialUse_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ChooseSerialUseCmd( IN CONST TMTHDSerialCtrl_Api tInfo, IN CONST BOOL32 bIsUse, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_OperaterSerialCmd
* 
* @brief   通过串口读写信息 (给网呈用的)
* 
* @param    [in]   tParam		串口读写参数
* @param    [in]   dwSSID       MT会话ID 
* @return   u32  0：成功， 其他：错误码 
*
* @note 更新通知: Ev_MtApi_Base_OperaterSerial_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_OperaterSerialCmd( IN CONST TMtSerialOptParam_Api &tParam, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_CFGSetShowMtTimeCfgCmd
* 
* @brief  设置是否显示终端界面时间命令
* 
* @param    [in]   bShow      TRUE:显示   FALSE:隐藏
* @param    [in]   dwSSID     MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:	Ev_MtApi_Base_SetShowMtTimeCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetShowMtTimeCfgCmd( IN CONST BOOL32 bShow, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGGetShowMtTimeCfgReq
* 
* @brief  获取是否显示终端界面时间请求
* 
* @param    [in]   dwSSID     MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:	Ev_MtApi_Base_GetShowMtTimeCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetShowMtTimeCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGSetEnableHTTPSCfgCmd 
* 
* @brief 是否使用HTTPS与平台通信(目前只针对API服务器)
* 
* @param	[in] bEnable    是否使用；TRUE：使用， FALSE：不使用
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_SetEnableHTTPSCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetEnableHTTPSCfgCmd( IN CONST BOOL32 bEnable, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGGetEnableHTTPSCfg
* 
* @brief 是否使用HTTPS与平台通信(目前只针对API服务器)
* 
* @param    [out] bEnable   是否使用；TRUE：使用，FALSE：不使用
* @param    [in]   dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetEnableHTTPSCfg( OUT BOOL32 &bEnable, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_GetEnableHTTPSCfgReq
* 
* @brief 获取是否使用HTTPS请求(目前只针对API服务器)
* 
* @param    [in]   dwSSID           MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MtApi_Base_GetEnableHTTPSCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_GetEnableHTTPSCfgReq(IN CONST SessionID dwSSID = KMTAPI_DEF_SSID);

/**
*  KdvMt_CFGGetShowMtTimeCfg
* 
* @brief  获取是否显示终端界面时间
* 
* @param    [out]  bShow      是否显示
* @param    [in]   dwSSID     MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:  no
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetShowMtTimeCfg( OUT BOOL32 &bShow, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_CFGSetLoginStrategyCfgCmd
* 
* @brief  设置登录策略
* 
* @param    [in]   bShow      TRUE:显示   FALSE:隐藏
* @param    [in]   dwSSID     MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:	Ev_MtApi_Base_SetLoginStrategyCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetLoginStrategyCfgCmd( IN CONST TMTLoginStrategy_Api tLoginStrategy, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGGetLoginStrategyCfgReq
* 
* @brief  获取登录策略
* 
* @param    [in]   dwSSID     MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:	Ev_MtApi_Base_GetLoginStrategyCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetLoginStrategyCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGGetLoginStrategyCfg
* 
* @brief  获取登录策略
* 
* @param    [out]  bShow      是否显示
* @param    [in]   dwSSID     MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:  no
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetLoginStrategyCfg( OUT TMTLoginStrategy_Api &tLoginStrategy, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_SetSleepReaminTimeCmd
* 
* @brief  设置待机剩余时间命令（用于OSD与网呈IMIX的待机同步）
* 
* @param    [in]   wSleepRemainTime     待机剩余时间(秒), 注意:  wSleepRemainTime = 0，表示取消待机
* @param    [in]   dwSSID				MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 更新通知:  Ev_MtApi_Base_SetSleepReaminTime_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_SetSleepReaminTimeCmd( IN CONST u16 wSleepRemainTime, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_SendLocalSmsCmd
* 
* @brief  网呈IMIX通过该接口给终端发短消息(限制512字节)，终端接收短消息后显示在OSD上
*
* @param    [in]   pszLocSms    本地短消息
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 响应通知：Ev_MtApi_Base_SendLocalSms_Ntf
*/

KdvMtAPI u32 KdvMtCALL KdvMt_SendLocalSmsCmd( IN CONST s8 *pszLocSms, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGSetShowHomeButtonCfgCmd
* 
* @brief  设置是否显示终端界面Home按钮 (仅embed)
* 
* @param    [in]   bShow      TRUE:显示   FALSE:隐藏
* @param    [in]   dwSSID     MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 更新通知:	Ev_MtApi_Base_SetShowHomeButtonCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetShowHomeButtonCfgCmd( IN CONST BOOL32 bShow, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGGetShowHomeButtonCfgReq
* 
* @brief  获取是否显示终端界面Home按钮请求 (仅embed)
* 
* @param    [in]   dwSSID     MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 更新通知:	Ev_MtApi_Base_GetShowHomeButtonCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetShowHomeButtonCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGGetHomeButtonCfg
* 
* @brief  获取是否显示终端界面Home按钮 (仅embed)
* 
* @param    [out]  bShow      是否显示
* @param    [in]   dwSSID     MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:  no
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetHomeButtonCfg( OUT BOOL32 &bShow, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_PressHomeButtonCmd
* 
* @brief  终端osd按下Home按钮的命令
* 
* @param    [in]   dwSSID     MT会话ID 
* @return   u32    请求命令发送结果 
*
* @note 更新通知:  Ev_MtApi_Base_PressHomeButton_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_PressHomeButtonCmd( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
*  KdvMt_CfgSetShowAssVidInVmpCfgCmd
* 
* @brief  设置在画面合成中是否显示本地硬双流源命令（网呈用)
* 
* @param    [in]   bShow      TRUE:显示   FALSE:隐藏
* @param    [in]   dwSSID     MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 更新通知:	Ev_MtApi_Base_SetShowAssVidInVmpCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CfgSetShowAssVidInVmpCfgCmd( IN CONST BOOL32 bShow, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_CFGGetShowAssVidInVmpCfgReq
* 
* @brief  获取在画面合成中是否显示本地硬双流源请求
* 
* @param    [in]   dwSSID     MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 更新通知:	Ev_MtApi_Base_GetShowAssVidInVmpCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetShowAssVidInVmpCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGGetShowAssVidInVmpCfg
* 
* @brief   获取在画面合成中是否显示本地硬双流源
* 
* @param    [out]  bShow      是否显示
* @param    [in]   dwSSID     MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:  no
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetShowAssVidInVmpCfg( OUT BOOL32 &bShow, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CfgSetIMIXCtrlOsdFuncCfgCmd
* 
* @brief  设置IMIX控制OSD某些功能的命令（网呈用)
* 
* @param    [in]   tCfg       控制参数      
* @param    [in]   dwSSID     MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 更新通知:	Ev_MtApi_Base_SetIMIXCtrlOsdFuncCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CfgSetIMIXCtrlOsdFuncCfgCmd( IN CONST TMTOrder_Api tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_CFGGetIMIXCtrlOsdFuncCfgReq
* 
* @brief  获取IMIX控制OSD某些功能的请求
* 
* @param    [in]   dwSSID     MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 更新通知:	Ev_MtApi_Base_GetIMIXCtrlOsdFuncCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetIMIXCtrlOsdFuncCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGGetIMIXCtrlOsdFuncCfg
* 
* @brief   获取IMIX控制OSD某些功能
* 
* @param    [out]  bShow      是否显示
* @param    [in]   dwSSID     MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:  no
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetIMIXCtrlOsdFuncCfg( OUT TMTOrder_Api &tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CfgSetHttpsCertTypeCfgCmd
* 
* @brief  设置终端使用的证书的类型命令
* 
* @param    [in]   byCertType    0表示默认证书，1表示用户证书     
* @param    [in]   dwSSID     MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 更新通知:	Ev_MtApi_Base_SetHttpsCertTypeCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CfgSetHttpsCertTypeCfgCmd( IN CONST u8 byCertType, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_CFGGetHttpsCertTypeCfgReq
* 
* @brief  获取终端使用的证书的类型请求
* 
* @param    [in]   dwSSID     MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 更新通知:	Ev_MtApi_Base_GetHttpsCertTypeCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetHttpsCertTypeCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGGetHttpsCertTypeCfg
* 
* @brief   获取终端使用的证书的类型
* 
* @param    [out]  bShow      是否显示
* @param    [in]   dwSSID     MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:  no
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetHttpsCertTypeCfg( OUT u8 &byCertType, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGSetVidEncQcModeCfgCmd
* 
* @brief   设置视频编码质量控制类型命令（质量优先还是速度优先）
* 
* @param    [in]   emQcMode    
* @param    [in]   dwSSID     MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 更新通知:  Ev_MtApi_Base_SetVidEncQcModeCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetVidEncQcModeCfgCmd( IN CONST EmVideoQuality_Api emQcMode, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_CFGGetVidEncQcModeCfgReq
* 
* @brief  获取视频编码质量控制类型请求（质量优先还是速度优先）
* 
* @param    [in]   dwSSID     MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 更新通知:	Ev_MtApi_Base_GetVidEncQcModeCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetVidEncQcModeCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGGetVidEncQcModeCfg
* 
* @brief   获取视频编码质量控制类型（质量优先还是速度优先）
* 
* @param    [out]  emQcMode   质量类型
* @param    [in]   dwSSID     MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:  no
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetVidEncQcModeCfg( OUT EmVideoQuality_Api &emQcMode, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGGetIsSupportWirelessCfgReq 
* 
* @brief    获取终端是否支持无线功能的请求（RT）
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_GetIsSupportWirelessRt_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetIsSupportWirelessCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGGetIsSupportWirelessCfg
* 
* @brief    获取终端是否支持无线功能（RT）
* 
* @param    [in] bIsSupport     是否支持
* @param    [in] dwSSID			MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：no
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetIsSupportWirelessCfg( OUT BOOL32 &bIsSupport, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
*  KdvMt_GetSoftIntegritySelfTestReq
* 
* @brief  获取软件完整性自测试
* 
* @param    [in]   dwSSID  MT会话ID 
* @return   u32    MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_GetSoftIntegritySelfTest_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_GetSoftIntegritySelfTestReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_GmAndRandomNumSelfTestCmd
* 
* @brief  国密算法和随机数自测试
* 
* @param    [in]   dwSSID  MT会话ID 
* @return   u32    MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_GmAndRandomNumSelfTest_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_GmAndRandomNumSelfTestCmd( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_GetGmAndRandomNumSelfTestReq
* 
* @brief  获取国密算法和随机数自测试
* 
* @param    [in]   dwSSID  MT会话ID 
* @return   u32    MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_GetGmAndRandomNumSelfTest_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_GetGmAndRandomNumSelfTestReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_GetGmAndRandomNumSelfTest
* 
* @brief  获取国密算法和随机数自测试
* 
* @param    [out]  TGmAndRandomNumTest_Api  自测结果
* @param    [in]   dwSSID  MT会话ID 
* @return   u32    MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：
*/
KdvMtAPI u32 KdvMtCALL KdvMt_GetGmAndRandomNumSelfTest( OUT TGmAndRandomNumTest_Api &tGmAndRandomNumTest ,IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGImportEncCertCmd 
* 
* @brief   导入pfx格式加密证书命令 
* 
* @param    [in]   pchEncCertFileName         导入加密证书路径
* @param    [in]   dwSSID                     MT会话ID 
* @return   u32  0：成功， 其他：错误码 
*
* @note 回复通知：Ev_MtApi_Base_ImportSecCert_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGImportEncCertCmd( IN CONST s8* pchEncCertFileName, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGImportKeyPairCmd
* 
* @brief  导入加密证书密钥对
*
* @param    [in]   pchKeyPairFileName         导入密钥对路径
* @param    [in]   dwSSID  MT会话ID 
* @return   u32    MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_ImportSecCert_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGImportKeyPairCmd( IN CONST s8* pchKeyPairFileName, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_KeyPairConsistencySelfTestCmd
* 
* @brief  签名证书密钥对一致性自测试
* 
* @param    [in]   dwSSID  MT会话ID 
* @return   u32    MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_KeyPairConsistencySelfTest_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_KeyPairConsistencySelfTestCmd( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_GetKeyPairConsistencySelfTestReq
* 
* @brief  获取签名证书密钥对一致性自测试
* 
* @param    [in]   dwSSID  MT会话ID 
* @return   u32    MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_GetKeyPairConsistencySelfTest_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_GetKeyPairConsistencySelfTestReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_GetKeyPairConsistencySelfTest
* 
* @brief  获取签名证书密钥对一致性自测试,调用之前确保已经调用KdvMt_KeyPairConsistencySelfTestCmd否则不准确
* 
* @param    [out]  TGmAndRandomNumTest_Api  自测结果
* @param    [in]   dwSSID  MT会话ID 
* @return   u32    MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：无
*/
KdvMtAPI u32 KdvMtCALL KdvMt_GetKeyPairConsistencySelfTest(OUT EmSecErrorCode_Api &emErrcode ,IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_SetWifiHotForgetReq 
* 
* @brief Wifi 忘记网络请求
* 
* @param    [in]   dwHotspotId  wifi热点id 
* @param    [in]   dwSSID       MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 响应：Ev_MtApi_WIFI_SetHotForget_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_SetWifiHotForgetReq( IN CONST u32 dwHotspotId, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_CfgSetQtSettingCfgCmd
* 
* @brief  设置Qt登录配置
* 
* @param    [in]   tMtQtAddr    登录信息     
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 更新通知:	Ev_MtApi_Base_SetQtSettingCfg_Ntf   
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CfgSetQtSettingCfgCmd( IN CONST TMtQtAddr_Api tMtQtAddr, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_CFGGetQtSettingCfgReq
* 
* @brief  请求Qt登录配置
* 
* @param    [in]   dwSSID     MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 更新通知:	Ev_MtApi_Base_GetQtSettingCfgCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetQtSettingCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGGetQtSettingCfg
* 
* @brief    获取Qt登录配置
* 
* @param    [out]  tMtQtAddr      登录信息
* @param    [in]   dwSSID     MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:  no
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetQtSettingCfg( OUT TMtQtAddr_Api &tMtQtAddr, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
*  KdvMt_CfgSetQtKeyUpdateModeCfgCmd
* 
* @brief  设置密钥key更新策略配置
* 
* @param    [in]   tMtSecKeyUpdatePolicy    登录信息     
* @param    [in]   dwSSID       MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 更新通知:	Ev_MtApi_Base_SetQtKeyUpdateModeCfg_Ntf   
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CfgSetQtKeyUpdateModeCfgCmd( IN CONST TMtSecKeyUpdatePolicy_Api tMtSecKeyUpdatePolicy, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_CFGGetQtKeyUpdateModeCfgReq
* 
* @brief  请求密钥key更新策略配置
* 
* @param    [in]   dwSSID     MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 更新通知:	Ev_MtApi_Base_GetQtKeyUpdateModeCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetQtKeyUpdateModeCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGGetQtKeyUpdateModeCfg
* 
* @brief    获取密钥key更新策略配置
* 
* @param    [out]  tMtSecKeyUpdatePolicy      登录信息
* @param    [in]   dwSSID     MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:  no
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetQtKeyUpdateModeCfg( OUT TMtSecKeyUpdatePolicy_Api &tMtSecKeyUpdatePolicy, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_SecKeyAdapterCreateResCfg
* 
* @brief    获取Qt登录是否成功的配置
* 
* @param    [out]  TMtSecAdateCreatRes_Api  登录信息
* @param    [in]   dwSSID     MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:  no
*/
KdvMtAPI u32 KdvMtCALL KdvMt_SecKeyAdapterCreateResCfg( OUT TMtSecAdateCreatRes_Api &tMtSecAdateCreatRes, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_SecTestQTDeviceReq
* 
* @brief  拔插usb设备时，检测是否拔插量子设备u盾
* 
* @param    [in]   dwSSID  MT会话ID 
* @param    [in]   bIsPull  是否拔插uk   TRUE 是插uk 
* @return   u32    MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_SecTestQTDevice_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_SecTestQTDeviceReq( IN CONST BOOL32 bIsPull,IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGGetIdleAssStreamStatusRtCfgReq
* 
* @brief    请求会议空闲双流状态
* 
* @param    [in]   dwSSID     MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:  Ev_MtApi_Base_GetMtStreamStatusRt_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetIdleAssStreamStatusRtCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGGetIdleAssStreamStatusRtCfg
* 
* @brief    获取会议空闲双流状态
* @param    [out]  dwCodecType (EmCodecComponent_Api) 编码或解码第几路，注意：dwCodecType=20 表示双流停止
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:  no
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetIdleAssStreamStatusRtCfg( OUT s32 &dwCodecType, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_GetChannelLicenseRtReq
* 
* @brief    请求渠道终端license证书信息
* 
* @param    [in]   dwSSID     MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:  Ev_MtApi_Base_GetChannelLicenseRt_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_GetChannelLicenseRtReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_GetChannelLicenseRtCfg
* 
* @brief    获取渠道终端license证书信息
* @param    [out]  tInfo       
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:  no
*/
KdvMtAPI u32 KdvMtCALL KdvMt_GetChannelLicenseRtCfg( OUT TMtAgentLicenseInfo_Api &tInfo, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_UpdateChannelLicenseCmd
* 
* @brief    更新（获取）渠道终端license证书信息，UI将证书传输至 /config/agentlicense.key ，必须调用这个接口更新证书信息
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知: Ev_MtApi_Base_UpdateChannelLicense_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_UpdateChannelLicenseCmd( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_GetLoginDynamicPwdCmd
* 
* @brief    获取登录时的动态口令
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知: Ev_MtApi_Base_GetLoginDynamicPwd_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_GetLoginDynamicPwdCmd( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_GetDataConfDynamicPwdCmd
* 
* @brief    获取数据协作的动态口令
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知: Ev_MtApi_Base_GetDataConfDynamicPwd_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_GetDataConfDynamicPwdCmd( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CheckDataConfDynamicPwdCmd
* 
* @brief    校验数据协作动态口令的命令
* @param    [in]   pchDynPwd   待校验的动态口令
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知: Ev_MtApi_Base_CheckDataConfDynamicPwd_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CheckDataConfDynamicPwdCmd( IN CONST s8 *pchDynPwd, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CleanDataConfDynamicPwdCmd
* 
* @brief    清除动态口令
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知: Ev_MtApi_Base_CleanDataConfDynamicPwd_Ntf
*/

KdvMtAPI u32 KdvMtCALL KdvMt_CleanDataConfDynamicPwdCmd( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_GetMtVersionInfoReq
* 
* @brief    获取终端版本信息和连接到该终端的mtc信息，用于连接终端前调用，连接后勿用
* @param	[in]   pchMtIp     终端ip
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知: Ev_MtApi_Base_GetMtBaseInfo_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_GetMtVersionInfoReq( IN CONST s8* pchMtIp = "" );

/**
*  KdvMt_GetMtcInfoListReq
* 
* @brief    请求终端当前已连接的mtc信息列表
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知: Ev_MtApi_Base_GetMtcInfoList_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_GetMtcInfoListReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_MTGetSkyShareLoginState
* 
* @brief    获取skyshare登录状态
* @param    [out]  bSkyShareLoginState
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知: Ev_MtApi_Base_MTCSkyShareLoginState_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_MTGetSkyShareLoginState( OUT BOOL32 &bSkyShareLoginState, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID ); 


/**
*  KdvMt_MTGetSkyShareLoginStateReq
* 
* @brief    请求skyshare登录状态
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知: Ev_MtApi_Base_MTCSkyShareLoginState_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_MTGetSkyShareLoginStateReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID ); 

/**
*  KdvMt_CFGSetVGAImgOutAdjustCfgCmd 
* 
* @brief   设置VGA输出图像调节
* 
* @param    [in]   tCfg        VGA输出图像调节
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:	Ev_MtApi_Base_Hd_SetVGAImgOutAdjust_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetVGAImgOutAdjustCfgCmd( IN CONST TMTVgaImgOutAdjustCfg_Api& tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGGetVGAImgOutAdjustCfgReq 
* 
* @brief    获取VGA图像调节请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_Hd_GetVGAImgOutAdjust_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetVGAImgOutAdjustCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGGetVGAImgOutAdjustCfg 
* 
* @brief   获取VGA图像调节配置
* 
* @param    [out]  tCfg        VGA输出图像调节
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:	no
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetVGAImgOutAdjustCfg( OUT TMTVgaImgOutAdjustCfg_Api &tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_GetTrueRandBytes
* 
* @brief    获取真随机数，用在商密终端，UI需要用到真随机数的地方
            终端如果没有商密卡， 结果为 伪随机数

* @param	[in]   wBytesLen   需要的bytes 的长度
* @return   u32    0：成功获取， 其他：错误码 
*
* @note 更新通知: Ev_MtApi_Base_GetTrueRandBytes_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_GetTrueRandBytes( IN CONST u16 wBytesLen,IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMtCALL KdvMt_ResetSecKeyCmd
* 
* @brief    重置密钥命令 商密硬终端使用
* @param	[in] bKeepAccount  是否保留账号
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_ResetSecKey_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ResetSecKeyCmd( IN CONST BOOL32 bKeepAccount, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGSetInCameraVidStdCfgCmd 
* 
* @brief   设置内置摄像机采集制式
* 
* @param    [in]   tCfg        制式信息
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:	Ev_MtApi_Base_Hd_SetCameraVidStd_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetInCameraVidStdCfgCmd( IN CONST TCameraVidStd_Api tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGGetInCameraVidStdCfgReq 
* 
* @brief    获取内置摄像机采集制式请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_Hd_GetCameraVidStd_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetInCameraVidStdCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGGetInCameraVidStdCfg 
* 
* @brief   获取内置摄像机采集制式
* 
* @param    [out]  tCfg        制式信息
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知: no
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetInCameraVidStdCfg( OUT TCameraVidStd_Api &tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_AgentSetPackLogInfoCmd
* 
* @brief    设置网管上报日志的文件信息

* @param	[in]   tLogFileInfo   日志文件信息
* @param    [in]   dwSSID         MT会话ID 
* @return   u32    0：成功获取， 其他：错误码 
*
* @note 更新通知: Ev_MtApi_Base_Agent_SetPackLogInfo_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_AgentSetPackLogInfoCmd( IN CONST TAgentLogFileInfo_Api &tLogFileInfo, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_AgentPackFileStateReq
* 
* @brief    终端打包状态信息上报
* @param    [in]   tPackState 错误信息
* @param    [in]   dwSSID     MT会话ID 
* @return   u32    0：成功获取， 其他：错误码 
*
* @note 更新通知: Ev_MtApi_Base_Agent_PackFileState_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_AgentPackFileStateReq(IN CONST TAgentPackFileState_Api &tPackState, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_AgentStartUploadLogReq
* @param    [in]   dwSSID         MT会话ID  
* @brief    日志打包完成，通知网管上传日志

* @return   u32    0：成功获取， 其他：错误码 
*
* @note 更新通知: Ev_MtApi_Base_Agent_StartUploadLog_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_AgentStartUploadLogReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_AgentReportDevicePerformanceReq
* 
* @brief    上报终端设备性能(收到Ev_MtApi_Base_Agent_DevicePerformance_Ntf后，调用)
* @param    [in]   tPFMInfo   设备性能参数
* @param    [in]   dwSSID     MT会话ID 
* @return   u32    0：成功获取， 其他：错误码 
*
* @note 更新通知: Ev_MtApi_Base_Agent_ReportDevicePerformance_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_AgentReportDevicePerformanceReq( IN CONST TAgentDevicePFMInfo_Api &tPFMInfo, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGGetIsImixTerReq
* 
* @brief   获取是否为网呈终端的请求 
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_GetIsImixTer_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetIsImixTerReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGGetIsImixTer
* 
* @brief  获取是否为网呈终端（取缓存接口）
* 
* @param    [out] bImixTer   是/否
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：no
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetIsImixTerCfg( OUT BOOL32 &bImixTer, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_GetSkyMtcVerRtReq
* 
* @brief   获取skymtc的版本信息 请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_GetSkyMtcVer_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_GetSkyMtcVerRtReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_ResetOsdAdminPwd
* 
* @brief   在webmtc重置osd管理员密码
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_ResetOsdAdminPwd_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ResetOsdAdminPwdCmd( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_GetWebMtcLoginStateReq
* 
* @brief   获取webmtc (前端)登录状态的请求, 用于osd处理操作隔离
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_GetWebMtcLoginState_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_GetWebMtcLoginStateReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_GetWebMtcLoginState
* 
* @brief   获取webmtc (前端)登录状态, 用于osd处理操作隔离
* 
* @param    [out] bLogin，  是否登录成功
* @param    [in]  dwSSID    MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：no
*/
KdvMtAPI u32 KdvMtCALL KdvMt_GetWebMtcLoginState( OUT BOOL32 &bLogin, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_GetIsExportingNetCapRtReq
* 
* @brief    获取是否正在导出抓包的请求
* 
* @param    [in]   dwSSID     MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:  Ev_MtApi_GetIsExportingNetCap_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_GetIsExportingNetCapRtReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_GetIsExportingNetCapRtCfg
* 
* @brief    获取是否正在导出抓包
* 
* @param    [out]  bExport    TRUE:正在导出
* @param    [in]   dwSSID     MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知: no
*/
KdvMtAPI u32 KdvMtCALL KdvMt_GetIsExportingNetCapRtCfg( OUT BOOL32 &bExport, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CfgSetCameraLastPosCfgCmd
* 
* @brief  设置内置摄像机默认位置配置
* 
* @param    [in]   tCfg    位置信息     
* @param    [in]   dwSSID  MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 更新通知:	Ev_MtApi_Base_Hd_SetCameraLastPos_Ntf   
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CfgSetCameraLastPosCfgCmd( IN CONST TMtCameraLastPos_Api tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_CFGGetCameraLastPosCfgReq
* 
* @brief  请求内置摄像机默认位置配置
* 
* @param    [in]   dwSSID     MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 更新通知:	Ev_MtApi_Base_Hd_GetCameraLastPos_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetCameraLastPosCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGGetCameraLastPosCfg
* 
* @brief    获取内置摄像机默认位置配置
* 
* @param    [out]  tCfg      位置信息
* @param    [in]   dwSSID    MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:  no
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetCameraLastPosCfg( OUT TMtCameraLastPos_Api &tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_GetAPSPlatformInfo
* 
* @brief    获取登陆aps后，平台的信息
* 
* @param    [in]   dwSSID    MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:  Ev_MtApi_Base_GetAPSPlatformInfo_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_GetAPSPlatformInfoReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CfgSetShowLostPktCfgCmd
* 
* @brief  设置显示丢包闪电图标
* 
* @param    [in]   bShow    是否显示丢包图标     
* @param    [in]   dwSSID  MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 更新通知:	Ev_MtApi_Base_SetShowLostPkt_Ntf   
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CfgSetShowLostPktCfgCmd( IN CONST BOOL32 bShow, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_CFGGetShowLostPktCfgReq
* 
* @brief  请求显示丢包闪电图标配置
* 
* @param    [in]   dwSSID     MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 更新通知:	Ev_MtApi_Base_GetShowLostPkt_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetShowLostPktCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGGetShowLostPktCfg
* 
* @brief    获取显示丢包闪电图标
* 
* @param    [out]  bShow      是否显示丢包图标
* @param    [in]   dwSSID    MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:  no
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetShowLostPktCfg( OUT BOOL32 &bShow, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
*  KdvMt_CFGSetAiInfoCfgCmd 
* 
* @brief    设置ai信息配置
* 
* @param	[in] tCfg    ai配置
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_SetAiInfoCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetAiInfoCfgCmd( IN CONST TMtAiInfoCfg_Api& tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );



/**
*  KdvMt_CFGGetAiInfoCfg 
* 
* @brief    获取ai配置
* 
* @param    [out]  tCfg       ai配置
* @param    [in]   dwSSID     MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetAiInfoCfg( OUT TMtAiInfoCfg_Api& tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_CFGGetAiInfoCfgtReq
* 
* @brief  请求获取ai配置
* 
* @param    [in]   dwSSID     MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 更新通知:	Ev_MtApi_Base_GetAiInfoCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetAiInfoCfgtReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CfgSetUserLoginPwdTimeoutCfgCmd
* 
* @brief  设置用户登录密码过期时间
* 
* @param    [in]   dwTime    所设时间(单位：月)     
* @param    [in]   dwSSID  MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 更新通知:	Ev_MtApi_Base_SetUserLoginPwdTimeout_Ntf   
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CfgSetUserLoginPwdTimeoutCfgCmd( IN CONST u32 dwTime, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_CFGGetUserLoginPwdTimeoutCfgReq
* 
* @brief  请求用户登录密码过期时间
* 
* @param    [in]   dwSSID     MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 更新通知:	Ev_MtApi_Base_GetUserLoginPwdTimeout_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetUserLoginPwdTimeoutCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGGetUserLoginPwdTimeoutCfg
* 
* @brief    获取用户登录密码过期时间
* 
* @param    [out]  dwTime      用户登录密码过期时间(单位：月)
* @param    [in]   dwSSID    MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知:  no
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetUserLoginPwdTimeoutCfg( OUT u32 &dwTime, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_GetUserPwdRestTimeReq
* 
* @brief  请求用户登录密码到期时的剩余时间
* 
* @param    [in]   dwSSID     MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 更新通知:	Ev_MtApi_Base_GetUserPwdRestTime_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_GetUserPwdRestTimeReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_SetEnableSecureCfgCmd
* 
* @brief   设置是否启用商密功能的命令
* 
* @param    [in]  bEnable   是否启用
* @param    [in]  dwSSID    MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_SetEnableSecureCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_SetEnableSecureCfgCmd( IN CONST BOOL32 bEnable, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_GetEnableSecureCfgReq
* 
* @brief  获取是否启用商密功能的请求
* 
* @param    [in]  dwSSID    MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_GetEnableSecureCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_GetEnableSecureCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_GetEnableSecureCfg
* 
* @brief   获取是否启用商密功能
* 
* @param    [out] bEnable   是否启用
* @param    [in]  dwSSID    MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：no
*/
KdvMtAPI u32 KdvMtCALL KdvMt_GetEnableSecureCfg( OUT BOOL32 &bEnable, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_SetUserLoginUnLockCmd
* 
* @brief    osd解除用户登录锁定命令
* 
* @param    [in]   dwSSID    MT会话ID 
* @return   u32    请求命令发送结果 
*
* @note 更新通知:  Ev_MtApi_Base_SetUserLoginUnLock_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_SetUserLoginUnLockCmd( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_GetUserLoginLockStateReq
* 
* @brief    osd请求用户登录锁定状态
* 
* @param    [in]   dwSSID    MT会话ID 
* @return   u32    请求命令发送结果 
*
* @note 更新通知:  Ev_MtApi_Base_GetUserLoginLockState_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_GetUserLoginLockStateReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_GetUserLoginLockState
* 
* @brief   osd获取用户登录锁定状态
* 
* @param    [out] bLock，  登录是否锁定
* @param    [in]  dwSSID    MT会话ID 
* @return   u32  0：成功获取， 其他：错误码
*
* @note 响应通知：no
*/
KdvMtAPI u32 KdvMtCALL KdvMt_GetUserLoginLockState( OUT BOOL32 &bLock, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_SetShortCutKeyCfgCmd
* 
* @brief    osd设置快捷键配置命令
* 
* @param    [in]   dwSSID    MT会话ID 
* @return   u32    请求命令发送结果 
*
* @note 更新通知:  Ev_MtApi_Base_SetShortCutKeyCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_SetShortCutKeyCfgCmd( IN CONST TMtShortCutKeyList_Api tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_GetShortCutKeyCfgReq
* 
* @brief    osd请求快捷键配置
* 
* @param    [in]   dwSSID    MT会话ID 
* @return   u32    请求命令发送结果 
*
* @note 更新通知:  Ev_MtApi_Base_GetShortCutKeyCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_GetShortCutKeyCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_GetShortCutKeyCfg
* 
* @brief   osd获取快捷键配置
* 
* @param    [out] bLock，  登录是否锁定
* @param    [in]  dwSSID    MT会话ID 
* @return   u32  0：成功获取， 其他：错误码
*
* @note 响应通知：no
*/
KdvMtAPI u32 KdvMtCALL KdvMt_GetShortCutKeyCfg( OUT TMtShortCutKeyList_Api &tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_SetDeviceCameraSleepCmd
* 
* @brief   硬终端摄像机待机/唤醒命令 
* 
* @param    [in]   bSleep    TRUE: 待机, FALSE: 唤醒
* @param    [in]   dwSSID    MT会话ID      
* @return   u32    请求命令发送结果 
*
* @note 更新通知:  no
*/
KdvMtAPI u32 KdvMtCALL KdvMt_SetDeviceCameraSleepCmd( IN CONST BOOL32 bSleep,  IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_SetSkipWizardStaticImage
* 
* @brief   终端跳过设置向导静态图片的命令，网呈用
* 
* @param    [in]   bSkip    TRUE: 跳过静态图片
* @param    [in]   dwSSID    MT会话ID      
* @return   u32    请求命令发送结果 
*
* @note 更新通知:  Ev_MtApi_Base_SkipWizardStaticImage_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_SetSkipWizardStaticImageCmd( IN CONST BOOL32 bSkip,  IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_ResetAdminUserInfoCmd
* 
* @brief  osd重置管理员用户名和密码
*  
* @param    [in]   dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 更新通知:	Ev_MtApi_Base_ResetAdminUserInfo_Ntf   
*/
KdvMtAPI u32 KdvMtCALL KdvMt_ResetAdminUserInfoCmd( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CfgSetUseOspTelnetCfgCmd
* 
* @brief  设置是否启用OspTelnet调试功能
* 
* @param    [in]   bUse     是否启用   
* @param    [in]   dwSSID  MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 更新通知:	Ev_MtApi_Base_SetUseOspTelnet_Ntf   
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CfgSetUseOspTelnetCfgCmd( IN CONST BOOL32 bUse, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_CFGGetUseOspTelnetCfgReq
* 
* @brief  请求OspTelnet调试功能启用状态
* 
* @param    [in]   dwSSID     MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 更新通知:	Ev_MtApi_Base_GetUseOspTelnet_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetUseOspTelnetCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGSetCameraEnableDigZoomCfgCmd 
* 
* @brief 设置是否使能数字变焦控制
* 
* @param    [IN CONST]  bEnable   是否开启
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 响应通知：Ev_MtApi_Base_Hd_SetCameraEnableDigZoomCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetCameraEnableDigZoomCfgCmd( IN CONST BOOL32 bEnable, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGGetCameraEnableDigZoomCfg 
* 
* @brief 获取是否使能数字变焦控制
* 
* @param    [out]  bEnable   是否开启
* @param    [in]   dwSSID      MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：Ev_MtApi_Base_Hd_SetCameraEnableDigZoomCfg_Ntf, Ev_MtApi_Base_Hd_GetCameraEnableDigZoomCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetCameraEnableDigZoomCfg( OUT BOOL32& bEnable, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGGetCameraEnableDigZoomCfgReq 
* 
* @brief    获取是否使能数字变焦控制请求
* 
* @param    [in] dwSSID  MT会话ID 
* @return   u32  MT_SUCCESS:发送请求成功  其他：错误码
*
* @note 响应通知：Ev_MtApi_Base_Hd_GetCameraEnableDigZoomCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetCameraEnableDigZoomCfgReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
* KdvMt_CFGSetFunctionIconCfgCmd
* 
* @brief  设置功能图标是否显示
* 
* @param    [in]   bEnable     是否显示
* @param    [in]   dwSSID     MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 更新通知:	Ev_MtApi_Base_FunctionIconCfg_Ntf
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGSetFunctionIconCfgCmd( IN CONST TMtFunctionIcon_Api tCfg, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGGetFunctionIconCfgReq
* 
* @brief    请求功能图标显示配置
* 
* @param    [in]   dwSSID    MT会话ID 
* @return   u32    请求命令发送结果 
*
* @note 更新通知:  Ev_MtApi_Base_GetFunctionIconCfg_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetFunctionIconCfgReq( IN CONST EmFunctionIcon_Api emIconType, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**
*  KdvMt_CFGGetFunctionIconCfg
* 
* @brief   请求功能图标显示配置
* 
* @param    [out] TMTFunctionIcon_Api，相应图标的配置
* @param    [in]  dwSSID    MT会话ID 
* @return   u32  0：成功获取， 其他：错误码
*
* @note 响应通知：no
*/
KdvMtAPI u32 KdvMtCALL KdvMt_CFGGetFunctionIconCfg( OUT TMtFunctionIcon_Api &tCfg, IN CONST EmFunctionIcon_Api emIconType, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
*  KdvMt_GetAiLoadLicenseTestCfg 
* 
* @brief    获取导入ai证书是否成功
* 
* @param    [out]  bResult       ai配置
* @param    [in]   dwSSID     MT会话ID 
* @return   u32  0：成功获取， 其他：错误码 
*
* @note 更新通知：
*/
KdvMtAPI u32 KdvMtCALL KdvMt_GetAiLoadLicenseTestCfg( OUT BOOL32 &bResult, IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );


/**
* KdvMt_GetAiLoadLicenseTestReq
* 
* @brief  请求获取导入ai证书是否成功
* 
* @param    [in]   dwSSID     MT会话ID 
* @return   u32    请求命令发送结果
*
* @note 更新通知:	Ev_MtApi_Base_GetAiLoadLicenseTest_Rsp
*/
KdvMtAPI u32 KdvMtCALL KdvMt_GetAiLoadLicenseTestReq( IN CONST SessionID dwSSID = KMTAPI_DEF_SSID );

/**@}*/

/**@}*/
#endif //_MTAPI_BASEAPI_H_
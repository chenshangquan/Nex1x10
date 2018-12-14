#ifndef _NVBLLUPGRADEMSG_H_
#define _NVBLLUPGRADEMSG_H_

#include "nvmsgid.h"
#include "nvenum.pb.h"

#if !defined(_MESSAGE_HELP_)
enum EmBLLUpgradeMsg
{
    EV_BLL_BGN(UPGRADE) = EVSEG_BLL_UPGRADE_BGN,
#endif

	/*<<检测更新命令>>
	* ui -> upgrade
	*/
    MESSAGE(Ev_NV_BLL_CheckUpgrade_Cmd)
	BODY(TNVUpgradeClientInfo, nv_info) //需提供的终端信息


	/*<<取消检测更新命令>>
	* ui -> upgrade
	*/
    MESSAGE(Ev_NV_BLL_CancelCheckUpgrade_Cmd)


	/*<<检测更新结果通知>>
	* upgrade -> ui
	*/
    MESSAGE(Ev_NV_BLL_CheckUpgradeResult_Ntf)
	BODY(nv::TU32, errorcode) //错误码 NV_SUCCESS:成功
	                          //ERR_UPGRADE_CONNECT_SERVER_FAILED 连接服务器失败
							  //ERR_UPGRADE_UNKNOWN 未知错误
							  //...


	/*<<最新版本信息通知>>
	* upgrade -> ui
	*/
    MESSAGE(Ev_NV_BLL_UpgradeVersionInfo_Ntf)
	BODY(nv::TNVDevUpgrade, ver_info)

	/*<<最新版本后台已下载成功的通知>>
	* upgrade -> ui
	*/
    MESSAGE(Ev_NV_BLL_AutoLoadUpgradeFileOk_Ntf)
	BODY(nv::TNVUpgradeVersionInfoList, ver_info)
	/*<<开始下载文件命令>>
	* ui -> upgrade
	*/
    MESSAGE(Ev_NV_BLL_StartDownloadUpgradeFile_Cmd)
	BODY(nv::TString, path) //文件存放路径
	BODY(nv::TU32, verid)//指定的版本号


	/*<<取消下载文件命令>>
	* ui -> upgrade
	*/
    MESSAGE(Ev_NV_BLL_CancelDownloadUpgradeFile_Cmd)


	/*<<文件下载状态指示>>
	* upgrade -> ui
	*/
    MESSAGE(Ev_NV_BLL_UpgradeFileDownloadInfo_Ntf)
	BODY( TNVUpgradeDownloadInfo, info )	//下载进度信息


	/*<<文件下载完毕指示>>
	* upgrade -> ui
	*/
    MESSAGE(Ev_NV_BLL_UpgradeFileDownloadOk_Ntf)


	/*<<开始升级命令(硬终端)>>
	* ui -> upgrade
	*/
    MESSAGE(Ev_NV_BLL_StartUpgrade_Cmd)
    BODY(nv::TS32, upgrade_type)   //升级类型 nv::EmUpgradeType


	/*<<升级结果通知(硬终端)>>
	* upgrade -> ui
	*/
    MESSAGE(Ev_NV_BLL_UpgradeSysFileUpdateStatus_Ntf)
    BODY(nv::TS32, upgrade_notify)   //nv::EmUpgradeNotify

	/*<<升级包有哪些子包通知>>
	* upgrade -> ui
	*/
    MESSAGE(Ev_NV_BLL_UpgradePackageContent_Ntf)
    BODY(nv::TNVUpgradePackageContent, upgrade_package)

	/*<<升级异常时 升级包已下载 提醒是否安装通知>>
	* upgrade -> ui
	*/
    MESSAGE(Ev_NV_BLL_UpgradeExceptionPackageIsReady_Ntf)

	/*<<升级结束，重启之前通知UI(硬终端)>>
	* upgrade -> ui
	*/
    MESSAGE(Ev_NV_BLL_UpgradeFinishGoingToReboot_Ntf)

	/*************** >>>> 控制台升级消息定义 ****************/

	/*<<上传生产测试升级包请求(硬终端)>>
	* ui -> upgrade
	*/
    MESSAGE(Ev_NV_BLL_UploadUpgradeFile_Req)
	BODY(nv::TString, file_full_path) //升级包绝对路径


	/*<<上传生产测试升级包响应(硬终端)>>
	* ui -> upgrade
	*/
    MESSAGE(Ev_NV_BLL_UploadUpgradeFile_Rsp)
	BODY(nv::TBOOL32, is_permit) //是否允许上传


	/*<<上传生产测试升级包结果通知(硬终端)>>
	* ui -> upgrade
	*/
    MESSAGE(Ev_NV_BLL_UploadUpgradeFileResult_Ntf)
	BODY(nv::TBOOL32, is_sucess) //升级包上传是否成功


	/*<<开始生产测试升级包升级(硬终端)>>
	* ui -> upgrade
	*/
    MESSAGE(Ev_NV_BLL_StartProductTestUpgrade_Cmd)



    /*<<检查U盘升级包请求>>
    * 消息流向 : sdk -> service
    * 参数 ： file_path  升级包路径
	*/
    MESSAGE(Ev_NV_BLL_UsbUpgradeFileCheck_Req)
    BODY(nv::TString, file_path)

    /*<<检查U盘升级包响应>>
    * 消息流向 : service -> sdk
    * 参数 : file_found     是否找到升级包
    *        file_path      升级包路径
    *        upgrade_info   升级包信息
	*/
    MESSAGE(Ev_NV_BLL_UsbUpgradeFileCheck_Rsp)
    BODY(nv::TBOOL32, file_found)
    BODY(nv::TString, file_path)
    BODY(nv::TNVUpgradeVersionInfoList, upgrade_info)

    /*<<与服务器断链通知>>
    * 消息流向 : service -> sdk
	*/
    MESSAGE(Ev_NV_BLL_UpgradeDisconnectServer_Ntf)

	/*************** <<<<  **********************************/

	/*<<无最新版本信息通知>>
	* upgrade -> ui
	*/
    MESSAGE(Ev_NV_BLL_NoNewVersion_Ntf)	
	BODY(nv::TS32, ttype)
	/*<<最新版本信息通知>>
	* upgrade -> ui
	*/
    MESSAGE(Ev_NV_BLL_AutoUpgradeVersion_Ntf)
	BODY(nv::TNVDevUpgrade, ver_info)

	/*<<升级无线投屏器>>
	* ui -> upgrade
	*/
	MESSAGE(Ev_NV_BLL_UpgradeQuickShare_Cmd)

	/*<<请求无线投屏器版本>>
	* ui -> upgrade
	*/
	MESSAGE(Ev_NV_BLL_GetQuickShareVersion_Cmd)

	/*<<发送无线投屏器版本>>
	*  upgrade -> ui
	*/
	MESSAGE(Ev_NV_BLL_SendQuickShareVersion_Ntf)
	BODY(nv::TString, quickshare_version) 
	
	/*<<无线投屏版本下载进度>>
	*  upgrade -> ui
	*/
	MESSAGE(Ev_NV_BLL_QuickShareDownloadProgress_Ntf)
	BODY(nv::TU32, quickshare_downloadprogress)

	/*<<无线投屏升级结果>>
	*  upgrade -> ui
	*/
	MESSAGE(Ev_NV_BLL_QuickShareUpgradeResult_Ntf)
	BODY(nv::TBOOL32, is_upgradesucess)
	/*<<取消下载升级无线投屏器>>
	* ui -> upgrade
	*/
	MESSAGE(Ev_NV_BLL_CancelUpgradeQuickShare_Cmd)
	/*<<设置Nova>>
	* ui -> upgrade
	*/
	MESSAGE(Ev_NV_BLL_SetNova_Cmd)

	/*<<删除app>>
	* ui -> upgrade
	*/
	MESSAGE(Ev_NV_BLL_DelApp_Cmd)
	
	/*<<应用升级状态通知>>
	*BODY ：
	*sdk==>dispatch==>nvservice
	*/
	MESSAGE(Ev_NV_BLL_AppUpgradeStatus_Ntf)
	BODY(nv::TBOOL32, is_upgrade)
	
	/*<<投屏器升级状态通知>>
	*BODY ：
	*sdk==>dispatch==>nvservice
	*/
	MESSAGE(Ev_NV_BLL_QkUpgradeStatus_Ntf)
	BODY(nv::TBOOL32, is_upgrade)

	/*<<获取服务器中投屏器版本请求>>
	*BODY ：
	*sdk==>dispatch==>nvservice
	*/
	MESSAGE(Ev_NV_BLL_GetQkVersion_Req)

	/*<<获取服务器中投屏器版本请求>>
	*BODY ：qkversion:投屏器版本
	*nvservice==>dispatch==>sdk
	*/
	MESSAGE(Ev_NV_BLL_GetQkVersion_Rsp)
	BODY(nv::TString, qkversion)

	/*<<imix整体升级命令>>
	*BODY ：qkversion:投屏器版本
	*nvservice==>dispatch==>sdk
	*/
	MESSAGE(Ev_NV_BLL_StartUpgradeAll_Cmd)
	BODY(nv::TS32, upgrade_type)   //升级类型 nv::EmUpgradeType

	/*<<一键升级包有哪些子包通知>>
	* upgrade -> ui
	*/
    MESSAGE(Ev_NV_BLL_AllUpgradePackageContent_Ntf)
    BODY(nv::TNVAllUpgradePackageContent, upgrade_package)

	/*<<pad升级包下载状态>>
	* upgrade -> ui
	*/
    MESSAGE(Ev_NV_BLL_PadDownState_Ntf)
    BODY(nv::TBOOL32, upgrade_package)

	/*<<pad升级包下载是否成功>>
	* upgrade -> ui
	*/
    MESSAGE(Ev_NV_BLL_PadIsDownSuc_Ntf)
    BODY(nv::TBOOL32, upgrade_package)

	/*<<app升级是否成功>>
	* upgrade -> ui
	*/
    MESSAGE(Ev_NV_BLL_AppUpgradeIsSuc_Ntf)
    BODY(nv::TBOOL32, upgrade_package)

	/*<<通知界面升级路由器>>
	* upgrade -> ui
	*/
    MESSAGE(Ev_NV_BLL_StartUpgradeRouter_Ntf)

	/*<<路由器升级包下载状态>>
	* upgrade -> ui
	*/
    MESSAGE(Ev_NV_BLL_RouterDownState_Ntf)
    BODY(nv::TBOOL32, upgrade_package)

	/*<<路由器升级包下载是否成功>>
	* upgrade -> ui
	*/
    MESSAGE(Ev_NV_BLL_RouterIsDownSuc_Ntf)
    BODY(nv::TBOOL32, upgrade_package)

	/*<<获取服务器中pad版本请求>>
	*BODY ：
	*sdk==>dispatch==>nvupgrade
	*/
	MESSAGE(Ev_NV_BLL_GetPadVersion_Req)

	/*<<获取服务器中pad版本回应>>
	*BODY ：padversion:pad版本
	*nvupgrade==>dispatch==>sdk
	*/
	MESSAGE(Ev_NV_BLL_GetPadVersion_Rsp)
	BODY(nv::TString, padversion)

	/*<<路由器升级状态>>
	* upgrade -> ui
	*/
    MESSAGE(Ev_NV_BLL_RouterUpgradeState_Ntf)
    BODY(nv::TBOOL32, upgrade_state)

	/*<<应用是否清理data文件夹>>
	* upgrade -> ui
	*/
    MESSAGE(Ev_NV_BLL_NeedClearDataFolder_Cmd)
    BODY(nv::TBOOL32, tIsClear)

	/*<<应用清理data文件夹是否成功>>
	* upgrade -> ui
	*/
    MESSAGE(Ev_NV_BLL_ClearDataFolderSuc_Nty)
    BODY(nv::TBOOL32, tIsSuc)

	/*<<应用删除系统文件>>
	* upgrade -> ui
	*/
    MESSAGE(Ev_NV_BLL_CancelFile_Cmd)
    BODY(nv::TString, tstrFile)
	
#if !defined(_MESSAGE_HELP_)
    EV_BLL_END(UPGRADE) = EVSEG_BLL_UPGRADE_END
};
#endif

#define Is_BLL_Updrade_Msg(m) ((m) >= EV_BLL_BGN(UPGRADE) && (m) <= EV_BLL_END(UPGRADE))

#endif // _NVUPGRADEMSG_H_

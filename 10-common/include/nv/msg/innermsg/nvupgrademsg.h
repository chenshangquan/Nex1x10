#ifndef _NVUPGRADEMSG_H_
#define _NVUPGRADEMSG_H_

#include "nvmsgid.h"
#include "nvenum.pb.h"

#if !defined(_MESSAGE_HELP_)
enum EmUpgradeMsg
{
    EV_BGN(UPGRADE) = EVSEG_UPGRADE_BGN,
#endif

	/*<<检测更新命令>>
	* ui -> upgrade
	*/
    MESSAGE(Ev_NV_CheckUpgrade_Cmd)
	BODY(TNVUpgradeClientInfo, nv_info) //需提供的终端信息


	/*<<取消检测更新命令>>
	* ui -> upgrade
	*/
    MESSAGE(Ev_NV_CancelCheckUpgrade_Cmd)


	/*<<检测更新结果通知>>
	* upgrade -> ui
	*/
    MESSAGE(Ev_NV_CheckUpgradeResult_Ntf)
	BODY(nv::TU32, errorcode) //错误码 NV_SUCCESS:成功
	                          //ERR_UPGRADE_CONNECT_SERVER_FAILED 连接服务器失败
							  //ERR_UPGRADE_UNKNOWN 未知错误
							  //...


	/*<<最新版本信息通知>>
	* upgrade -> ui
	*/
    MESSAGE(Ev_NV_UpgradeVersionInfo_Ntf)
	BODY(TNVUpgradeVersionInfoList, ver_info)

	/*<<最新版本后台已下载成功的通知>>
	* upgrade -> ui
	*/
    MESSAGE(Ev_NV_AutoLoadUpgradeFileOk_Ntf)
	BODY(TNVUpgradeVersionInfoList, ver_info)

	/*<<开始下载文件命令>>
	* ui -> upgrade
	*/
    MESSAGE(Ev_NV_StartDownloadUpgradeFile_Cmd)
	BODY(nv::TString, path) //文件存放路径
	BODY(nv::TU32, verid)//指定的版本号

	/*<<取消下载文件命令>>
	* ui -> upgrade
	*/
    MESSAGE(Ev_NV_CancelDownloadUpgradeFile_Cmd)


	/*<<文件下载状态指示>>
	* upgrade -> ui
	*/
    MESSAGE(Ev_NV_UpgradeFileDownloadInfo_Ntf)
	BODY( TNVUpgradeDownloadInfo, info )	//下载进度信息


	/*<<文件下载完毕指示>>
	* upgrade -> ui
	*/
    MESSAGE(Ev_NV_UpgradeFileDownloadOk_Ntf)


	/*<<开始升级命令(硬终端)>>
	* ui -> upgrade
	*/
    MESSAGE(Ev_NV_StartUpgrade_Cmd)
    BODY(nv::TS32, upgrade_type)   //升级类型 nv::EmUpgradeType


	/*<<升级结果通知(硬终端)>>
	* upgrade -> ui
	*/
    MESSAGE(Ev_NV_UpgradeSysFileUpdateStatus_Ntf)
	BODY(nv::TS32, upgrade_notify)	//nv::EmUpgradeNotify

	/*<<终端是否终止升级文件下载(硬终端)>>
	* TRUE: 终止， FALSE：继续
	*/
    MESSAGE(Ev_NV_IsPausedDownload_Ntf)
	BODY(nv::TBOOL32, paused)

	/*************** >>>> 控制台升级消息定义 ****************/

	/*<<上传生产测试升级包请求(硬终端)>>
	* ui -> upgrade
	*/
    MESSAGE(Ev_NV_UploadUpgradeFile_Req)
	BODY(nv::TString, file_full_path) //升级包绝对路径


	/*<<上传生产测试升级包响应(硬终端)>>
	* ui -> upgrade
	*/
    MESSAGE(Ev_NV_UploadUpgradeFile_Rsp)
	BODY(nv::TBOOL32, is_permit) //是否允许上传


	/*<<上传生产测试升级包结果通知(硬终端)>>
	* ui -> upgrade
	*/
    MESSAGE(Ev_NV_UploadUpgradeFileResult_Ntf)
	BODY(nv::TBOOL32, is_sucess) //升级包上传是否成功


	/*<<开始生产测试升级包升级(硬终端)>>
	* ui -> upgrade
	*/
    MESSAGE(Ev_NV_StartProductTestUpgrade_Cmd)



    /*<<检查U盘升级包请求>>
	* 消息流向 : service -> upgrade
    * 参数 ： file_path  升级包路径
	*/
    MESSAGE(Ev_NV_UsbUpgradeFileCheck_Req)
    BODY(nv::TString, file_path)

    /*<<检查U盘升级包响应>>
    * 消息流向 : upgrade -> service
    * 参数 : file_found     是否找到升级包
    *        file_path      升级包路径
    *        upgrade_info   升级包信息
	*/
    MESSAGE(Ev_NV_UsbUpgradeFileCheck_Rsp)
    BODY(nv::TBOOL32, file_found)
    BODY(nv::TString, file_path)
    BODY(nv::TNVUpgradeVersionInfoList, upgrade_info)	

    /*<<与服务器断链通知>>
    * 消息流向 : upgrade -> service
	*/
    MESSAGE(Ev_NV_UpgradeDisconnectServer_Ntf)

    /*<<升级无线投屏器消息通知>>
    * 消息流向 : ui -> upgrade
	*/
    MESSAGE(Ev_NV_UpgradeQuickShare_Cmd)

    /*<<获取无线投屏器版本>>
    * 消息流向 : ui -> upgrade
	*/
    MESSAGE(Ev_NV_GetQuickShareVersion_Cmd)

    /*<<取消无线投屏下载升级>>
    * 消息流向 : ui -> upgrade
	*/
    MESSAGE(Ev_NV_CancelUpgradeQuickShare_Cmd)

	/*<<Power检查更新>>
    * 消息流向 : upgrade -> service
	*/
    MESSAGE(Ev_NV_UpgradePowerCheck_Cmd)
	/*************** <<<<  **********************************/

	/*<<删除app.zip包>>
    * 消息流向 : upgrade -> service
	*/
    MESSAGE(Ev_NV_DelAppZip_Cmd)
	/*************** <<<<  **********************************/

	/*************** <<<<  **********************************/

	/*<<获取User目录大小>>
    * 消息流向 : upgrade -> service
	*/
    MESSAGE(Ev_NV_GetUserSize_Cmd)
	/*************** <<<<  **********************************/

	/*<<开始整体升级命令(硬终端)>>
	* ui -> upgrade
	*/
    MESSAGE(Ev_NV_StartUpgradeAll_Cmd)
    BODY(nv::TS32, upgrade_type)   //升级类型 nv::EmUpgradeType

	/*<<app是否升级成功>>
	* ui -> upgrade
	*/
    MESSAGE(Ev_NV_AppUpgradeIsSuc_Nty)
    BODY(nv::TBOOL32, upgrade_type)   

	/*<<pad及路由器升级文件下载是否成功>>
	* ui -> upgrade
	*/
    MESSAGE(Ev_NV_PadAndRouterDownState_Nty)

	/*<<pad下载文件时断开连接通知>>
	* nvaccess -> upgrade
	*/
	MESSAGE(Ev_NV_PadDownDisconnect_Nty)
	BODY(nv::TU32, nodeid)

	/*<<路由器是否上传成功>>
	* ui -> upgrade
	*/
    MESSAGE(Ev_NV_RouterDownloadIsSuc_Nty)
    BODY(nv::TBOOL32, upgrade_type)

	/*<<路由器升级状态>>
	* ui -> upgrade
	*/
    MESSAGE(Ev_NV_RouterUpgradeState_Nty)
    BODY(nv::TBOOL32, upgrade_state)

	/*<<应用清理data文件成功与否通知>>
	* ui -> upgrade
	*/
    MESSAGE(Ev_NV_ClearDataFolderSuc_Nty)
    BODY(nv::TBOOL32, tbSuc)

	/*<<提供给界面删除系统文件的接口>>
	* ui -> upgrade
	*/
    MESSAGE(Ev_NV_CancelFile_Cmd)
    BODY(nv::TString, tFilePath)

	/*<<sus服务器连接状态>>
	* suc -> upgrade
	*/
    MESSAGE(Ev_NV_ConnectSus_State_Ntf)
    BODY(nv::TU32, tState)

	/*<<sus服务器版本比对信息>>
	* suc -> upgrade
	*/
    MESSAGE(Ev_NV_UpgradeModule_Ntf)
    BODY(nv::TBOOL32, tUpgrade)
	BODY(nv::TNVSusUpgradeModule, tModule)
	BODY(nv::TBOOL32, tLoadFile)

	/*<<sus服务器投屏器文件下载完成通知>>
	* suc -> upgrade
	*/
    MESSAGE(Ev_NV_LoadQKFileSuc_Ntf)

	/*<<断开sus服务器>>
	* suc -> upgrade
	*/
    MESSAGE(Ev_NV_ImixDisconnectSus_Cmd)

	/*<<获取到sus服务器信息通知>>
	* suc -> upgrade
	*/
    MESSAGE(Ev_NV_GetSusCfg_Nty)

	/*<<连接sus服务器命令>>
	* upgrade -> suc
	*/
    MESSAGE(Ev_NV_ConnectSus_Cmd)
	BODY(nv::TNVSUSAddr, tInfo)

	/*<<获取sus服务器中imix的版本>>
	* upgrade -> suc
	*/
    MESSAGE(Ev_NV_GetSusImixVer_Cmd)

	/*<<从sus服务器中下载文件>>
	* upgrade -> suc
	*/
    MESSAGE(Ev_NV_DownLoadFileFromSus_Cmd)
	BODY(nv::TString, tPath)
	BODY(nv::TString, tFile)

	/*<<从sus服务器中下载整包>>
	* upgrade -> suc
	*/
    MESSAGE(Ev_NV_DownLoadAllVerFromSus_Cmd)
	BODY(nv::TString, tPath)
	BODY(nv::TString, tFile)

	/*<<将imix当前版本信息发送给suc>>
	* upgrade -> suc
	*/
    MESSAGE(Ev_NV_CompareVerInfoWithSus_Cmd)
	BODY(nv::TNVImixAllVerInfo, tInfo)

	/*<<开始从sus服务器中下载模块文件>>
	* upgrade -> suc
	*/
    MESSAGE(Ev_NV_StartDownLoadModuleFile_Cmd)

	/*<<与sus服务器断开连接>>
	* upgrade -> suc
	*/
    MESSAGE(Ev_NV_DisConnecSus_Cmd)



#if !defined(_MESSAGE_HELP_)
    EV_END(UPGRADE) = EVSEG_UPGRADE_END
};
#endif

#define Is_Updrade_Msg(m) ((m) >= EV_BGN(UPGRADE) && (m) <= EV_END(UPGRADE))

#endif // _NVUPGRADEMSG_H_
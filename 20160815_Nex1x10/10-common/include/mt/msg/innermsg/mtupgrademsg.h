#ifndef _MTUPGRADEMSG_H_
#define _MTUPGRADEMSG_H_

#include "mtmsgid.h"
#include "enum.pb.h"

#if !defined(_MESSAGE_HELP_)
enum EmUpgradeMsg
{
    EV_BGN(UPGRADE) = EVSEG_UPGRADE_BGN,
#endif

	/*<<检测更新命令>>
	* ui -> upgrade
	*/
    MESSAGE(Ev_MT_CheckUpgrade_Cmd)
	BODY(TMTUpgradeClientInfo, mt_info) //需提供的终端信息


	/*<<取消检测更新命令>>
	* ui -> upgrade
	*/
    MESSAGE(Ev_MT_CancelCheckUpgrade_Cmd)


	/*<<检测更新结果通知>>
	* upgrade -> ui
	*/
    MESSAGE(Ev_MT_CheckUpgradeResult_Ntf)
	BODY(mt::TU32, errorcode) //错误码 MT_SUCCESS:成功
	                          //ERR_UPGRADE_CONNECT_SERVER_FAILED 连接服务器失败
							  //ERR_UPGRADE_UNKNOWN 未知错误
							  //...


	/*<<最新版本信息通知>>
	* upgrade -> ui
	*/
    MESSAGE(Ev_MT_UpgradeVersionInfo_Ntf)
	BODY(TMTUpgradeVersionInfoList, ver_info)

	/*<<最新版本后台已下载成功的通知>>
	* upgrade -> ui
	*/
    MESSAGE(Ev_MT_AutoLoadUpgradeFileOk_Ntf)
	BODY(TMTUpgradeVersionInfoList, ver_info)

	/*<<开始下载文件命令>>
	* ui -> upgrade
	*/
    MESSAGE(Ev_MT_StartDownloadUpgradeFile_Cmd)
	BODY(mt::TString, path) //文件存放路径
	BODY(mt::TU32, verid)//指定的版本号

	/*<<取消下载文件命令>>
	* ui -> upgrade
	*/
    MESSAGE(Ev_MT_CancelDownloadUpgradeFile_Cmd)


	/*<<文件下载状态指示>>
	* upgrade -> ui
	*/
    MESSAGE(Ev_MT_UpgradeFileDownloadInfo_Ntf)
	BODY( TMTUpgradeDownloadInfo, info )	//下载进度信息


	/*<<文件下载完毕指示>>
	* upgrade -> ui
	*/
    MESSAGE(Ev_MT_UpgradeFileDownloadOk_Ntf)


	/*<<开始升级命令(硬终端)>>
	* ui -> upgrade
	*/
    MESSAGE(Ev_MT_StartUpgrade_Cmd)
    BODY(mt::TS32, upgrade_type)   //升级类型 mt::EmUpgradeType


	/*<<升级结果通知(硬终端)>>
	* upgrade -> ui
	*/
    MESSAGE(Ev_MT_UpgradeSysFileUpdateStatus_Ntf)
	BODY(mt::TS32, upgrade_notify)	//mt::EmUpgradeNotify

	/*<<终端是否终止升级文件下载(硬终端)>>
	* TRUE: 终止， FALSE：继续
	*/
    MESSAGE(Ev_MT_IsPausedDownload_Ntf)
	BODY(mt::TBOOL32, paused)

	/*************** >>>> 控制台升级消息定义 ****************/

	/*<<上传生产测试升级包请求(硬终端)>>
	* ui -> upgrade
	*/
    MESSAGE(Ev_MT_UploadUpgradeFile_Req)
	BODY(mt::TString, file_full_path) //升级包绝对路径


	/*<<上传生产测试升级包响应(硬终端)>>
	* ui -> upgrade
	*/
    MESSAGE(Ev_MT_UploadUpgradeFile_Rsp)
	BODY(mt::TBOOL32, is_permit) //是否允许上传


	/*<<上传生产测试升级包结果通知(硬终端)>>
	* ui -> upgrade
	*/
    MESSAGE(Ev_MT_UploadUpgradeFileResult_Ntf)
	BODY(mt::TBOOL32, is_sucess) //升级包上传是否成功


	/*<<开始生产测试升级包升级(硬终端)>>
	* ui -> upgrade
	*/
    MESSAGE(Ev_MT_StartProductTestUpgrade_Cmd)



    /*<<检查U盘升级包请求>>
	* 消息流向 : service -> upgrade
    * 参数 ： file_path  升级包路径
	*/
    MESSAGE(Ev_MT_UsbUpgradeFileCheck_Req)
    BODY(mt::TString, file_path)

    /*<<检查U盘升级包响应>>
    * 消息流向 : upgrade -> service
    * 参数 : file_found     是否找到升级包
    *        file_path      升级包路径
    *        upgrade_info   升级包信息
	*/
    MESSAGE(Ev_MT_UsbUpgradeFileCheck_Rsp)
    BODY(mt::TBOOL32, file_found)
    BODY(mt::TString, file_path)
    BODY(mt::TMTUpgradeVersionInfoList, upgrade_info)	

    /*<<与服务器断链通知>>
    * 消息流向 : upgrade -> service
	*/
    MESSAGE(Ev_MT_UpgradeDisconnectServer_Ntf)

    /*<<升级异常退出，恢复后继续下载(硬终端)>>
	* mtservice -> upgrade
    * reason    上次异常退出原因
	*/
    MESSAGE(Ev_MT_ResumeUpgrade_Cmd)
    BODY( mt::TS32, reason )

	/*************** <<<<  **********************************/


#if !defined(_MESSAGE_HELP_)
    EV_END(UPGRADE) = EVSEG_UPGRADE_END
};
#endif

#define Is_Updrade_Msg(m) ((m) >= EV_BGN(UPGRADE) && (m) <= EV_END(UPGRADE))

#endif // _MTUPGRADEMSG_H_
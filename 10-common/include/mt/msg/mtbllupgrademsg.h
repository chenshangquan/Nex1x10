#ifndef _MTBLLUPGRADEMSG_H_
#define _MTBLLUPGRADEMSG_H_

#include "mtmsgid.h"
#include "enum.pb.h"

#if !defined(_MESSAGE_HELP_)
enum EmBLLUpgradeMsg
{
    EV_BLL_BGN(UPGRADE) = EVSEG_BLL_UPGRADE_BGN,
#endif

	/*<<检测更新命令>>
	* ui -> upgrade
	*/
    MESSAGE(Ev_MT_BLL_CheckUpgrade_Cmd)
	BODY(TMTUpgradeClientInfo, mt_info) //需提供的终端信息


	/*<<取消检测更新命令>>
	* ui -> upgrade
	*/
    MESSAGE(Ev_MT_BLL_CancelCheckUpgrade_Cmd)


	/*<<检测更新结果通知>>
	* upgrade -> ui
	*/
    MESSAGE(Ev_MT_BLL_CheckUpgradeResult_Ntf)
	BODY(mt::TU32, errorcode) //错误码 MT_SUCCESS:成功
	                          //ERR_UPGRADE_CONNECT_SERVER_FAILED 连接服务器失败
							  //ERR_UPGRADE_UNKNOWN 未知错误
							  //...


	/*<<最新版本信息通知>>
	* upgrade -> ui
	*/
    MESSAGE(Ev_MT_BLL_UpgradeVersionInfo_Ntf)
	BODY(TMTUpgradeVersionInfoList, ver_info)

	/*<<最新版本后台已下载成功的通知>>
	* upgrade -> ui
	*/
    MESSAGE(Ev_MT_BLL_AutoLoadUpgradeFileOk_Ntf)
	BODY(TMTUpgradeVersionInfoList, ver_info)
	/*<<开始下载文件命令>>
	* ui -> upgrade
	*/
    MESSAGE(Ev_MT_BLL_StartDownloadUpgradeFile_Cmd)
	BODY(mt::TString, path) //文件存放路径
	BODY(mt::TU32, verid)//指定的版本号


	/*<<取消下载文件命令>>
	* ui -> upgrade
	*/
    MESSAGE(Ev_MT_BLL_CancelDownloadUpgradeFile_Cmd)


	/*<<文件下载状态指示>>
	* upgrade -> ui
	*/
    MESSAGE(Ev_MT_BLL_UpgradeFileDownloadInfo_Ntf)
	BODY( TMTUpgradeDownloadInfo, info )	//下载进度信息


	/*<<文件下载完毕指示>>
	* upgrade -> ui
	*/
    MESSAGE(Ev_MT_BLL_UpgradeFileDownloadOk_Ntf)


	/*<<开始升级命令(硬终端)>>
	* ui -> upgrade
	*/
    MESSAGE(Ev_MT_BLL_StartUpgrade_Cmd)
    BODY(mt::TS32, upgrade_type)   //升级类型 mt::EmUpgradeType


	/*<<升级结果通知(硬终端)>>
	* upgrade -> ui
	*/
    MESSAGE(Ev_MT_BLL_UpgradeSysFileUpdateStatus_Ntf)
    BODY(mt::TS32, upgrade_notify)   //mt::EmUpgradeNotify



	/*************** >>>> 控制台升级消息定义 ****************/

	/*<<上传生产测试升级包请求(硬终端)>>
	* ui -> upgrade
	*/
    MESSAGE(Ev_MT_BLL_UploadUpgradeFile_Req)
	BODY(mt::TString, file_full_path) //升级包绝对路径


	/*<<上传生产测试升级包响应(硬终端)>>
	* ui -> upgrade
	*/
    MESSAGE(Ev_MT_BLL_UploadUpgradeFile_Rsp)
	BODY(mt::TBOOL32, is_permit) //是否允许上传


	/*<<上传生产测试升级包结果通知(硬终端)>>
	* ui -> upgrade
	*/
    MESSAGE(Ev_MT_BLL_UploadUpgradeFileResult_Ntf)
	BODY(mt::TBOOL32, is_sucess) //升级包上传是否成功


	/*<<开始生产测试升级包升级(硬终端)>>
	* ui -> upgrade
	*/
    MESSAGE(Ev_MT_BLL_StartProductTestUpgrade_Cmd)



    /*<<检查U盘升级包请求>>
    * 消息流向 : sdk -> service
    * 参数 ： file_path  升级包路径
	*/
    MESSAGE(Ev_MT_BLL_UsbUpgradeFileCheck_Req)
    BODY(mt::TString, file_path)

    /*<<检查U盘升级包响应>>
    * 消息流向 : service -> sdk
    * 参数 : file_found     是否找到升级包
    *        file_path      升级包路径
    *        upgrade_info   升级包信息
	*/
    MESSAGE(Ev_MT_BLL_UsbUpgradeFileCheck_Rsp)
    BODY(mt::TBOOL32, file_found)
    BODY(mt::TString, file_path)
    BODY(mt::TMTUpgradeVersionInfoList, upgrade_info)

    /*<<与服务器断链通知>>
    * 消息流向 : service -> sdk
	*/
    MESSAGE(Ev_MT_BLL_UpgradeDisconnectServer_Ntf)

	/*************** <<<<  **********************************/


#if !defined(_MESSAGE_HELP_)
    EV_BLL_END(UPGRADE) = EVSEG_BLL_UPGRADE_END
};
#endif

#define Is_BLL_Updrade_Msg(m) ((m) >= EV_BLL_BGN(UPGRADE) && (m) <= EV_BLL_END(UPGRADE))

#endif // _MTUPGRADEMSG_H_
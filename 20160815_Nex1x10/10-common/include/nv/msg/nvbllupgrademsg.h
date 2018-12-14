#ifndef _NVBLLUPGRADEMSG_H_
#define _NVBLLUPGRADEMSG_H_

#include "nvmsgid.h"
#include "nvenum.pb.h"

#if !defined(_MESSAGE_HELP_)
enum EmBLLUpgradeMsg
{
    EV_BLL_BGN(UPGRADE) = EVSEG_BLL_UPGRADE_BGN,
#endif

	/*<<����������>>
	* ui -> upgrade
	*/
    MESSAGE(Ev_NV_BLL_CheckUpgrade_Cmd)
	BODY(TNVUpgradeClientInfo, nv_info) //���ṩ���ն���Ϣ


	/*<<ȡ������������>>
	* ui -> upgrade
	*/
    MESSAGE(Ev_NV_BLL_CancelCheckUpgrade_Cmd)


	/*<<�����½��֪ͨ>>
	* upgrade -> ui
	*/
    MESSAGE(Ev_NV_BLL_CheckUpgradeResult_Ntf)
	BODY(nv::TU32, errorcode) //������ NV_SUCCESS:�ɹ�
	                          //ERR_UPGRADE_CONNECT_SERVER_FAILED ���ӷ�����ʧ��
							  //ERR_UPGRADE_UNKNOWN δ֪����
							  //...


	/*<<���°汾��Ϣ֪ͨ>>
	* upgrade -> ui
	*/
    MESSAGE(Ev_NV_BLL_UpgradeVersionInfo_Ntf)
	BODY(nv::TNVDevUpgrade, ver_info)

	/*<<���°汾��̨�����سɹ���֪ͨ>>
	* upgrade -> ui
	*/
    MESSAGE(Ev_NV_BLL_AutoLoadUpgradeFileOk_Ntf)
	BODY(nv::TNVUpgradeVersionInfoList, ver_info)
	/*<<��ʼ�����ļ�����>>
	* ui -> upgrade
	*/
    MESSAGE(Ev_NV_BLL_StartDownloadUpgradeFile_Cmd)
	BODY(nv::TString, path) //�ļ����·��
	BODY(nv::TU32, verid)//ָ���İ汾��


	/*<<ȡ�������ļ�����>>
	* ui -> upgrade
	*/
    MESSAGE(Ev_NV_BLL_CancelDownloadUpgradeFile_Cmd)


	/*<<�ļ�����״ָ̬ʾ>>
	* upgrade -> ui
	*/
    MESSAGE(Ev_NV_BLL_UpgradeFileDownloadInfo_Ntf)
	BODY( TNVUpgradeDownloadInfo, info )	//���ؽ�����Ϣ


	/*<<�ļ��������ָʾ>>
	* upgrade -> ui
	*/
    MESSAGE(Ev_NV_BLL_UpgradeFileDownloadOk_Ntf)


	/*<<��ʼ��������(Ӳ�ն�)>>
	* ui -> upgrade
	*/
    MESSAGE(Ev_NV_BLL_StartUpgrade_Cmd)
    BODY(nv::TS32, upgrade_type)   //�������� nv::EmUpgradeType


	/*<<�������֪ͨ(Ӳ�ն�)>>
	* upgrade -> ui
	*/
    MESSAGE(Ev_NV_BLL_UpgradeSysFileUpdateStatus_Ntf)
    BODY(nv::TS32, upgrade_notify)   //nv::EmUpgradeNotify

	/*<<����������Щ�Ӱ�֪ͨ>>
	* upgrade -> ui
	*/
    MESSAGE(Ev_NV_BLL_UpgradePackageContent_Ntf)
    BODY(nv::TNVUpgradePackageContent, upgrade_package)

	/*<<�����쳣ʱ ������������ �����Ƿ�װ֪ͨ>>
	* upgrade -> ui
	*/
    MESSAGE(Ev_NV_BLL_UpgradeExceptionPackageIsReady_Ntf)

	/*<<��������������֮ǰ֪ͨUI(Ӳ�ն�)>>
	* upgrade -> ui
	*/
    MESSAGE(Ev_NV_BLL_UpgradeFinishGoingToReboot_Ntf)

	/*************** >>>> ����̨������Ϣ���� ****************/

	/*<<�ϴ�������������������(Ӳ�ն�)>>
	* ui -> upgrade
	*/
    MESSAGE(Ev_NV_BLL_UploadUpgradeFile_Req)
	BODY(nv::TString, file_full_path) //����������·��


	/*<<�ϴ�����������������Ӧ(Ӳ�ն�)>>
	* ui -> upgrade
	*/
    MESSAGE(Ev_NV_BLL_UploadUpgradeFile_Rsp)
	BODY(nv::TBOOL32, is_permit) //�Ƿ������ϴ�


	/*<<�ϴ������������������֪ͨ(Ӳ�ն�)>>
	* ui -> upgrade
	*/
    MESSAGE(Ev_NV_BLL_UploadUpgradeFileResult_Ntf)
	BODY(nv::TBOOL32, is_sucess) //�������ϴ��Ƿ�ɹ�


	/*<<��ʼ������������������(Ӳ�ն�)>>
	* ui -> upgrade
	*/
    MESSAGE(Ev_NV_BLL_StartProductTestUpgrade_Cmd)



    /*<<���U������������>>
    * ��Ϣ���� : sdk -> service
    * ���� �� file_path  ������·��
	*/
    MESSAGE(Ev_NV_BLL_UsbUpgradeFileCheck_Req)
    BODY(nv::TString, file_path)

    /*<<���U����������Ӧ>>
    * ��Ϣ���� : service -> sdk
    * ���� : file_found     �Ƿ��ҵ�������
    *        file_path      ������·��
    *        upgrade_info   ��������Ϣ
	*/
    MESSAGE(Ev_NV_BLL_UsbUpgradeFileCheck_Rsp)
    BODY(nv::TBOOL32, file_found)
    BODY(nv::TString, file_path)
    BODY(nv::TNVUpgradeVersionInfoList, upgrade_info)

    /*<<�����������֪ͨ>>
    * ��Ϣ���� : service -> sdk
	*/
    MESSAGE(Ev_NV_BLL_UpgradeDisconnectServer_Ntf)

	/*************** <<<<  **********************************/

	/*<<�����°汾��Ϣ֪ͨ>>
	* upgrade -> ui
	*/
    MESSAGE(Ev_NV_BLL_NoNewVersion_Ntf)	
	BODY(nv::TS32, ttype)
	/*<<���°汾��Ϣ֪ͨ>>
	* upgrade -> ui
	*/
    MESSAGE(Ev_NV_BLL_AutoUpgradeVersion_Ntf)
	BODY(nv::TNVDevUpgrade, ver_info)

	/*<<��������Ͷ����>>
	* ui -> upgrade
	*/
	MESSAGE(Ev_NV_BLL_UpgradeQuickShare_Cmd)

	/*<<��������Ͷ�����汾>>
	* ui -> upgrade
	*/
	MESSAGE(Ev_NV_BLL_GetQuickShareVersion_Cmd)

	/*<<��������Ͷ�����汾>>
	*  upgrade -> ui
	*/
	MESSAGE(Ev_NV_BLL_SendQuickShareVersion_Ntf)
	BODY(nv::TString, quickshare_version) 
	
	/*<<����Ͷ���汾���ؽ���>>
	*  upgrade -> ui
	*/
	MESSAGE(Ev_NV_BLL_QuickShareDownloadProgress_Ntf)
	BODY(nv::TU32, quickshare_downloadprogress)

	/*<<����Ͷ���������>>
	*  upgrade -> ui
	*/
	MESSAGE(Ev_NV_BLL_QuickShareUpgradeResult_Ntf)
	BODY(nv::TBOOL32, is_upgradesucess)
	/*<<ȡ��������������Ͷ����>>
	* ui -> upgrade
	*/
	MESSAGE(Ev_NV_BLL_CancelUpgradeQuickShare_Cmd)
	/*<<����Nova>>
	* ui -> upgrade
	*/
	MESSAGE(Ev_NV_BLL_SetNova_Cmd)

	/*<<ɾ��app>>
	* ui -> upgrade
	*/
	MESSAGE(Ev_NV_BLL_DelApp_Cmd)
	
	/*<<Ӧ������״̬֪ͨ>>
	*BODY ��
	*sdk==>dispatch==>nvservice
	*/
	MESSAGE(Ev_NV_BLL_AppUpgradeStatus_Ntf)
	BODY(nv::TBOOL32, is_upgrade)
	
	/*<<Ͷ��������״̬֪ͨ>>
	*BODY ��
	*sdk==>dispatch==>nvservice
	*/
	MESSAGE(Ev_NV_BLL_QkUpgradeStatus_Ntf)
	BODY(nv::TBOOL32, is_upgrade)

	/*<<��ȡ��������Ͷ�����汾����>>
	*BODY ��
	*sdk==>dispatch==>nvservice
	*/
	MESSAGE(Ev_NV_BLL_GetQkVersion_Req)

	/*<<��ȡ��������Ͷ�����汾����>>
	*BODY ��qkversion:Ͷ�����汾
	*nvservice==>dispatch==>sdk
	*/
	MESSAGE(Ev_NV_BLL_GetQkVersion_Rsp)
	BODY(nv::TString, qkversion)

	/*<<imix������������>>
	*BODY ��qkversion:Ͷ�����汾
	*nvservice==>dispatch==>sdk
	*/
	MESSAGE(Ev_NV_BLL_StartUpgradeAll_Cmd)
	BODY(nv::TS32, upgrade_type)   //�������� nv::EmUpgradeType

	/*<<һ������������Щ�Ӱ�֪ͨ>>
	* upgrade -> ui
	*/
    MESSAGE(Ev_NV_BLL_AllUpgradePackageContent_Ntf)
    BODY(nv::TNVAllUpgradePackageContent, upgrade_package)

	/*<<pad����������״̬>>
	* upgrade -> ui
	*/
    MESSAGE(Ev_NV_BLL_PadDownState_Ntf)
    BODY(nv::TBOOL32, upgrade_package)

	/*<<pad�����������Ƿ�ɹ�>>
	* upgrade -> ui
	*/
    MESSAGE(Ev_NV_BLL_PadIsDownSuc_Ntf)
    BODY(nv::TBOOL32, upgrade_package)

	/*<<app�����Ƿ�ɹ�>>
	* upgrade -> ui
	*/
    MESSAGE(Ev_NV_BLL_AppUpgradeIsSuc_Ntf)
    BODY(nv::TBOOL32, upgrade_package)

	/*<<֪ͨ��������·����>>
	* upgrade -> ui
	*/
    MESSAGE(Ev_NV_BLL_StartUpgradeRouter_Ntf)

	/*<<·��������������״̬>>
	* upgrade -> ui
	*/
    MESSAGE(Ev_NV_BLL_RouterDownState_Ntf)
    BODY(nv::TBOOL32, upgrade_package)

	/*<<·���������������Ƿ�ɹ�>>
	* upgrade -> ui
	*/
    MESSAGE(Ev_NV_BLL_RouterIsDownSuc_Ntf)
    BODY(nv::TBOOL32, upgrade_package)

	/*<<��ȡ��������pad�汾����>>
	*BODY ��
	*sdk==>dispatch==>nvupgrade
	*/
	MESSAGE(Ev_NV_BLL_GetPadVersion_Req)

	/*<<��ȡ��������pad�汾��Ӧ>>
	*BODY ��padversion:pad�汾
	*nvupgrade==>dispatch==>sdk
	*/
	MESSAGE(Ev_NV_BLL_GetPadVersion_Rsp)
	BODY(nv::TString, padversion)

	/*<<·��������״̬>>
	* upgrade -> ui
	*/
    MESSAGE(Ev_NV_BLL_RouterUpgradeState_Ntf)
    BODY(nv::TBOOL32, upgrade_state)

	/*<<Ӧ���Ƿ�����data�ļ���>>
	* upgrade -> ui
	*/
    MESSAGE(Ev_NV_BLL_NeedClearDataFolder_Cmd)
    BODY(nv::TBOOL32, tIsClear)

	/*<<Ӧ������data�ļ����Ƿ�ɹ�>>
	* upgrade -> ui
	*/
    MESSAGE(Ev_NV_BLL_ClearDataFolderSuc_Nty)
    BODY(nv::TBOOL32, tIsSuc)

	/*<<Ӧ��ɾ��ϵͳ�ļ�>>
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

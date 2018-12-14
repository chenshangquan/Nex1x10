#ifndef _NVUPGRADEMSG_H_
#define _NVUPGRADEMSG_H_

#include "nvmsgid.h"
#include "nvenum.pb.h"

#if !defined(_MESSAGE_HELP_)
enum EmUpgradeMsg
{
    EV_BGN(UPGRADE) = EVSEG_UPGRADE_BGN,
#endif

	/*<<����������>>
	* ui -> upgrade
	*/
    MESSAGE(Ev_NV_CheckUpgrade_Cmd)
	BODY(TNVUpgradeClientInfo, nv_info) //���ṩ���ն���Ϣ


	/*<<ȡ������������>>
	* ui -> upgrade
	*/
    MESSAGE(Ev_NV_CancelCheckUpgrade_Cmd)


	/*<<�����½��֪ͨ>>
	* upgrade -> ui
	*/
    MESSAGE(Ev_NV_CheckUpgradeResult_Ntf)
	BODY(nv::TU32, errorcode) //������ NV_SUCCESS:�ɹ�
	                          //ERR_UPGRADE_CONNECT_SERVER_FAILED ���ӷ�����ʧ��
							  //ERR_UPGRADE_UNKNOWN δ֪����
							  //...


	/*<<���°汾��Ϣ֪ͨ>>
	* upgrade -> ui
	*/
    MESSAGE(Ev_NV_UpgradeVersionInfo_Ntf)
	BODY(TNVUpgradeVersionInfoList, ver_info)

	/*<<���°汾��̨�����سɹ���֪ͨ>>
	* upgrade -> ui
	*/
    MESSAGE(Ev_NV_AutoLoadUpgradeFileOk_Ntf)
	BODY(TNVUpgradeVersionInfoList, ver_info)

	/*<<��ʼ�����ļ�����>>
	* ui -> upgrade
	*/
    MESSAGE(Ev_NV_StartDownloadUpgradeFile_Cmd)
	BODY(nv::TString, path) //�ļ����·��
	BODY(nv::TU32, verid)//ָ���İ汾��

	/*<<ȡ�������ļ�����>>
	* ui -> upgrade
	*/
    MESSAGE(Ev_NV_CancelDownloadUpgradeFile_Cmd)


	/*<<�ļ�����״ָ̬ʾ>>
	* upgrade -> ui
	*/
    MESSAGE(Ev_NV_UpgradeFileDownloadInfo_Ntf)
	BODY( TNVUpgradeDownloadInfo, info )	//���ؽ�����Ϣ


	/*<<�ļ��������ָʾ>>
	* upgrade -> ui
	*/
    MESSAGE(Ev_NV_UpgradeFileDownloadOk_Ntf)


	/*<<��ʼ��������(Ӳ�ն�)>>
	* ui -> upgrade
	*/
    MESSAGE(Ev_NV_StartUpgrade_Cmd)
    BODY(nv::TS32, upgrade_type)   //�������� nv::EmUpgradeType


	/*<<�������֪ͨ(Ӳ�ն�)>>
	* upgrade -> ui
	*/
    MESSAGE(Ev_NV_UpgradeSysFileUpdateStatus_Ntf)
	BODY(nv::TS32, upgrade_notify)	//nv::EmUpgradeNotify

	/*<<�ն��Ƿ���ֹ�����ļ�����(Ӳ�ն�)>>
	* TRUE: ��ֹ�� FALSE������
	*/
    MESSAGE(Ev_NV_IsPausedDownload_Ntf)
	BODY(nv::TBOOL32, paused)

	/*************** >>>> ����̨������Ϣ���� ****************/

	/*<<�ϴ�������������������(Ӳ�ն�)>>
	* ui -> upgrade
	*/
    MESSAGE(Ev_NV_UploadUpgradeFile_Req)
	BODY(nv::TString, file_full_path) //����������·��


	/*<<�ϴ�����������������Ӧ(Ӳ�ն�)>>
	* ui -> upgrade
	*/
    MESSAGE(Ev_NV_UploadUpgradeFile_Rsp)
	BODY(nv::TBOOL32, is_permit) //�Ƿ������ϴ�


	/*<<�ϴ������������������֪ͨ(Ӳ�ն�)>>
	* ui -> upgrade
	*/
    MESSAGE(Ev_NV_UploadUpgradeFileResult_Ntf)
	BODY(nv::TBOOL32, is_sucess) //�������ϴ��Ƿ�ɹ�


	/*<<��ʼ������������������(Ӳ�ն�)>>
	* ui -> upgrade
	*/
    MESSAGE(Ev_NV_StartProductTestUpgrade_Cmd)



    /*<<���U������������>>
	* ��Ϣ���� : service -> upgrade
    * ���� �� file_path  ������·��
	*/
    MESSAGE(Ev_NV_UsbUpgradeFileCheck_Req)
    BODY(nv::TString, file_path)

    /*<<���U����������Ӧ>>
    * ��Ϣ���� : upgrade -> service
    * ���� : file_found     �Ƿ��ҵ�������
    *        file_path      ������·��
    *        upgrade_info   ��������Ϣ
	*/
    MESSAGE(Ev_NV_UsbUpgradeFileCheck_Rsp)
    BODY(nv::TBOOL32, file_found)
    BODY(nv::TString, file_path)
    BODY(nv::TNVUpgradeVersionInfoList, upgrade_info)	

    /*<<�����������֪ͨ>>
    * ��Ϣ���� : upgrade -> service
	*/
    MESSAGE(Ev_NV_UpgradeDisconnectServer_Ntf)

    /*<<��������Ͷ������Ϣ֪ͨ>>
    * ��Ϣ���� : ui -> upgrade
	*/
    MESSAGE(Ev_NV_UpgradeQuickShare_Cmd)

    /*<<��ȡ����Ͷ�����汾>>
    * ��Ϣ���� : ui -> upgrade
	*/
    MESSAGE(Ev_NV_GetQuickShareVersion_Cmd)

    /*<<ȡ������Ͷ����������>>
    * ��Ϣ���� : ui -> upgrade
	*/
    MESSAGE(Ev_NV_CancelUpgradeQuickShare_Cmd)

	/*<<Power������>>
    * ��Ϣ���� : upgrade -> service
	*/
    MESSAGE(Ev_NV_UpgradePowerCheck_Cmd)
	/*************** <<<<  **********************************/

	/*<<ɾ��app.zip��>>
    * ��Ϣ���� : upgrade -> service
	*/
    MESSAGE(Ev_NV_DelAppZip_Cmd)
	/*************** <<<<  **********************************/

	/*************** <<<<  **********************************/

	/*<<��ȡUserĿ¼��С>>
    * ��Ϣ���� : upgrade -> service
	*/
    MESSAGE(Ev_NV_GetUserSize_Cmd)
	/*************** <<<<  **********************************/

	/*<<��ʼ������������(Ӳ�ն�)>>
	* ui -> upgrade
	*/
    MESSAGE(Ev_NV_StartUpgradeAll_Cmd)
    BODY(nv::TS32, upgrade_type)   //�������� nv::EmUpgradeType

	/*<<app�Ƿ������ɹ�>>
	* ui -> upgrade
	*/
    MESSAGE(Ev_NV_AppUpgradeIsSuc_Nty)
    BODY(nv::TBOOL32, upgrade_type)   

	/*<<pad��·���������ļ������Ƿ�ɹ�>>
	* ui -> upgrade
	*/
    MESSAGE(Ev_NV_PadAndRouterDownState_Nty)

	/*<<pad�����ļ�ʱ�Ͽ�����֪ͨ>>
	* nvaccess -> upgrade
	*/
	MESSAGE(Ev_NV_PadDownDisconnect_Nty)
	BODY(nv::TU32, nodeid)

	/*<<·�����Ƿ��ϴ��ɹ�>>
	* ui -> upgrade
	*/
    MESSAGE(Ev_NV_RouterDownloadIsSuc_Nty)
    BODY(nv::TBOOL32, upgrade_type)

	/*<<·��������״̬>>
	* ui -> upgrade
	*/
    MESSAGE(Ev_NV_RouterUpgradeState_Nty)
    BODY(nv::TBOOL32, upgrade_state)

	/*<<Ӧ������data�ļ��ɹ����֪ͨ>>
	* ui -> upgrade
	*/
    MESSAGE(Ev_NV_ClearDataFolderSuc_Nty)
    BODY(nv::TBOOL32, tbSuc)

	/*<<�ṩ������ɾ��ϵͳ�ļ��Ľӿ�>>
	* ui -> upgrade
	*/
    MESSAGE(Ev_NV_CancelFile_Cmd)
    BODY(nv::TString, tFilePath)



#if !defined(_MESSAGE_HELP_)
    EV_END(UPGRADE) = EVSEG_UPGRADE_END
};
#endif

#define Is_Updrade_Msg(m) ((m) >= EV_BGN(UPGRADE) && (m) <= EV_END(UPGRADE))

#endif // _NVUPGRADEMSG_H_
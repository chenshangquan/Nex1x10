#ifndef _MTBLLUPGRADEMSG_H_
#define _MTBLLUPGRADEMSG_H_

#include "mtmsgid.h"
#include "enum.pb.h"

#if !defined(_MESSAGE_HELP_)
enum EmBLLUpgradeMsg
{
    EV_BLL_BGN(UPGRADE) = EVSEG_BLL_UPGRADE_BGN,
#endif

	/*<<����������>>
	* ui -> upgrade
	*/
    MESSAGE(Ev_MT_BLL_CheckUpgrade_Cmd)
	BODY(TMTUpgradeClientInfo, mt_info) //���ṩ���ն���Ϣ


	/*<<ȡ������������>>
	* ui -> upgrade
	*/
    MESSAGE(Ev_MT_BLL_CancelCheckUpgrade_Cmd)


	/*<<�����½��֪ͨ>>
	* upgrade -> ui
	*/
    MESSAGE(Ev_MT_BLL_CheckUpgradeResult_Ntf)
	BODY(mt::TU32, errorcode) //������ MT_SUCCESS:�ɹ�
	                          //ERR_UPGRADE_CONNECT_SERVER_FAILED ���ӷ�����ʧ��
							  //ERR_UPGRADE_UNKNOWN δ֪����
							  //...


	/*<<���°汾��Ϣ֪ͨ>>
	* upgrade -> ui
	*/
    MESSAGE(Ev_MT_BLL_UpgradeVersionInfo_Ntf)
	BODY(TMTUpgradeVersionInfoList, ver_info)

	/*<<���°汾��̨�����سɹ���֪ͨ>>
	* upgrade -> ui
	*/
    MESSAGE(Ev_MT_BLL_AutoLoadUpgradeFileOk_Ntf)
	BODY(TMTUpgradeVersionInfoList, ver_info)
	/*<<��ʼ�����ļ�����>>
	* ui -> upgrade
	*/
    MESSAGE(Ev_MT_BLL_StartDownloadUpgradeFile_Cmd)
	BODY(mt::TString, path) //�ļ����·��
	BODY(mt::TU32, verid)//ָ���İ汾��


	/*<<ȡ�������ļ�����>>
	* ui -> upgrade
	*/
    MESSAGE(Ev_MT_BLL_CancelDownloadUpgradeFile_Cmd)


	/*<<�ļ�����״ָ̬ʾ>>
	* upgrade -> ui
	*/
    MESSAGE(Ev_MT_BLL_UpgradeFileDownloadInfo_Ntf)
	BODY( TMTUpgradeDownloadInfo, info )	//���ؽ�����Ϣ


	/*<<�ļ��������ָʾ>>
	* upgrade -> ui
	*/
    MESSAGE(Ev_MT_BLL_UpgradeFileDownloadOk_Ntf)


	/*<<��ʼ��������(Ӳ�ն�)>>
	* ui -> upgrade
	*/
    MESSAGE(Ev_MT_BLL_StartUpgrade_Cmd)
    BODY(mt::TS32, upgrade_type)   //�������� mt::EmUpgradeType


	/*<<�������֪ͨ(Ӳ�ն�)>>
	* upgrade -> ui
	*/
    MESSAGE(Ev_MT_BLL_UpgradeSysFileUpdateStatus_Ntf)
    BODY(mt::TS32, upgrade_notify)   //mt::EmUpgradeNotify



	/*************** >>>> ����̨������Ϣ���� ****************/

	/*<<�ϴ�������������������(Ӳ�ն�)>>
	* ui -> upgrade
	*/
    MESSAGE(Ev_MT_BLL_UploadUpgradeFile_Req)
	BODY(mt::TString, file_full_path) //����������·��


	/*<<�ϴ�����������������Ӧ(Ӳ�ն�)>>
	* ui -> upgrade
	*/
    MESSAGE(Ev_MT_BLL_UploadUpgradeFile_Rsp)
	BODY(mt::TBOOL32, is_permit) //�Ƿ������ϴ�


	/*<<�ϴ������������������֪ͨ(Ӳ�ն�)>>
	* ui -> upgrade
	*/
    MESSAGE(Ev_MT_BLL_UploadUpgradeFileResult_Ntf)
	BODY(mt::TBOOL32, is_sucess) //�������ϴ��Ƿ�ɹ�


	/*<<��ʼ������������������(Ӳ�ն�)>>
	* ui -> upgrade
	*/
    MESSAGE(Ev_MT_BLL_StartProductTestUpgrade_Cmd)



    /*<<���U������������>>
    * ��Ϣ���� : sdk -> service
    * ���� �� file_path  ������·��
	*/
    MESSAGE(Ev_MT_BLL_UsbUpgradeFileCheck_Req)
    BODY(mt::TString, file_path)

    /*<<���U����������Ӧ>>
    * ��Ϣ���� : service -> sdk
    * ���� : file_found     �Ƿ��ҵ�������
    *        file_path      ������·��
    *        upgrade_info   ��������Ϣ
	*/
    MESSAGE(Ev_MT_BLL_UsbUpgradeFileCheck_Rsp)
    BODY(mt::TBOOL32, file_found)
    BODY(mt::TString, file_path)
    BODY(mt::TMTUpgradeVersionInfoList, upgrade_info)

    /*<<�����������֪ͨ>>
    * ��Ϣ���� : service -> sdk
	*/
    MESSAGE(Ev_MT_BLL_UpgradeDisconnectServer_Ntf)

	/*************** <<<<  **********************************/


#if !defined(_MESSAGE_HELP_)
    EV_BLL_END(UPGRADE) = EVSEG_BLL_UPGRADE_END
};
#endif

#define Is_BLL_Updrade_Msg(m) ((m) >= EV_BLL_BGN(UPGRADE) && (m) <= EV_BLL_END(UPGRADE))

#endif // _MTUPGRADEMSG_H_
#ifndef _MTUPGRADEMSG_H_
#define _MTUPGRADEMSG_H_

#include "mtmsgid.h"
#include "enum.pb.h"

#if !defined(_MESSAGE_HELP_)
enum EmUpgradeMsg
{
    EV_BGN(UPGRADE) = EVSEG_UPGRADE_BGN,
#endif

	/*<<����������>>
	* ui -> upgrade
	*/
    MESSAGE(Ev_MT_CheckUpgrade_Cmd)
	BODY(TMTUpgradeClientInfo, mt_info) //���ṩ���ն���Ϣ


	/*<<ȡ������������>>
	* ui -> upgrade
	*/
    MESSAGE(Ev_MT_CancelCheckUpgrade_Cmd)


	/*<<�����½��֪ͨ>>
	* upgrade -> ui
	*/
    MESSAGE(Ev_MT_CheckUpgradeResult_Ntf)
	BODY(mt::TU32, errorcode) //������ MT_SUCCESS:�ɹ�
	                          //ERR_UPGRADE_CONNECT_SERVER_FAILED ���ӷ�����ʧ��
							  //ERR_UPGRADE_UNKNOWN δ֪����
							  //...


	/*<<���°汾��Ϣ֪ͨ>>
	* upgrade -> ui
	*/
    MESSAGE(Ev_MT_UpgradeVersionInfo_Ntf)
	BODY(TMTUpgradeVersionInfoList, ver_info)

	/*<<���°汾��̨�����سɹ���֪ͨ>>
	* upgrade -> ui
	*/
    MESSAGE(Ev_MT_AutoLoadUpgradeFileOk_Ntf)
	BODY(TMTUpgradeVersionInfoList, ver_info)

	/*<<��ʼ�����ļ�����>>
	* ui -> upgrade
	*/
    MESSAGE(Ev_MT_StartDownloadUpgradeFile_Cmd)
	BODY(mt::TString, path) //�ļ����·��
	BODY(mt::TU32, verid)//ָ���İ汾��

	/*<<ȡ�������ļ�����>>
	* ui -> upgrade
	*/
    MESSAGE(Ev_MT_CancelDownloadUpgradeFile_Cmd)


	/*<<�ļ�����״ָ̬ʾ>>
	* upgrade -> ui
	*/
    MESSAGE(Ev_MT_UpgradeFileDownloadInfo_Ntf)
	BODY( TMTUpgradeDownloadInfo, info )	//���ؽ�����Ϣ


	/*<<�ļ��������ָʾ>>
	* upgrade -> ui
	*/
    MESSAGE(Ev_MT_UpgradeFileDownloadOk_Ntf)


	/*<<��ʼ��������(Ӳ�ն�)>>
	* ui -> upgrade
	*/
    MESSAGE(Ev_MT_StartUpgrade_Cmd)
    BODY(mt::TS32, upgrade_type)   //�������� mt::EmUpgradeType


	/*<<�������֪ͨ(Ӳ�ն�)>>
	* upgrade -> ui
	*/
    MESSAGE(Ev_MT_UpgradeSysFileUpdateStatus_Ntf)
	BODY(mt::TS32, upgrade_notify)	//mt::EmUpgradeNotify

	/*<<�ն��Ƿ���ֹ�����ļ�����(Ӳ�ն�)>>
	* TRUE: ��ֹ�� FALSE������
	*/
    MESSAGE(Ev_MT_IsPausedDownload_Ntf)
	BODY(mt::TBOOL32, paused)

	/*************** >>>> ����̨������Ϣ���� ****************/

	/*<<�ϴ�������������������(Ӳ�ն�)>>
	* ui -> upgrade
	*/
    MESSAGE(Ev_MT_UploadUpgradeFile_Req)
	BODY(mt::TString, file_full_path) //����������·��


	/*<<�ϴ�����������������Ӧ(Ӳ�ն�)>>
	* ui -> upgrade
	*/
    MESSAGE(Ev_MT_UploadUpgradeFile_Rsp)
	BODY(mt::TBOOL32, is_permit) //�Ƿ������ϴ�


	/*<<�ϴ������������������֪ͨ(Ӳ�ն�)>>
	* ui -> upgrade
	*/
    MESSAGE(Ev_MT_UploadUpgradeFileResult_Ntf)
	BODY(mt::TBOOL32, is_sucess) //�������ϴ��Ƿ�ɹ�


	/*<<��ʼ������������������(Ӳ�ն�)>>
	* ui -> upgrade
	*/
    MESSAGE(Ev_MT_StartProductTestUpgrade_Cmd)



    /*<<���U������������>>
	* ��Ϣ���� : service -> upgrade
    * ���� �� file_path  ������·��
	*/
    MESSAGE(Ev_MT_UsbUpgradeFileCheck_Req)
    BODY(mt::TString, file_path)

    /*<<���U����������Ӧ>>
    * ��Ϣ���� : upgrade -> service
    * ���� : file_found     �Ƿ��ҵ�������
    *        file_path      ������·��
    *        upgrade_info   ��������Ϣ
	*/
    MESSAGE(Ev_MT_UsbUpgradeFileCheck_Rsp)
    BODY(mt::TBOOL32, file_found)
    BODY(mt::TString, file_path)
    BODY(mt::TMTUpgradeVersionInfoList, upgrade_info)	

    /*<<�����������֪ͨ>>
    * ��Ϣ���� : upgrade -> service
	*/
    MESSAGE(Ev_MT_UpgradeDisconnectServer_Ntf)

    /*<<�����쳣�˳����ָ����������(Ӳ�ն�)>>
	* mtservice -> upgrade
    * reason    �ϴ��쳣�˳�ԭ��
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
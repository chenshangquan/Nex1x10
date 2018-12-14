#ifndef _MTBLLVODMSG_H_
#define _MTBLLVODMSG_H_

#include "mtmsgid.h"

#if !defined(_MESSAGE_HELP_)
enum EmBLLMtVodMsg
{
    EV_BLL_BGN(MTVOD) = EVSEG_BLL_MTVOD_BGN,
#endif//_MESSAGE_HELP_
	/*<<�㲥����>>
	*play_url �����ŵĵ�ַ
	*���䷽��ui->dispatch->vod
	* see Ev_MT_BLL_VODPlay_Ntf
	*/
	MESSAGE(Ev_MT_BLL_VODPlay_Cmd)
	BODY(mt::TString, play_url)

	/*<<�㲥���>>
	*play_url �����ŵĵ�ַ
	*error_codeID �����Ž��
	*���䷽��vod->dispatch->ui
	* see Ev_MT_BLL_VODPlay_Cmd
	*/
	MESSAGE(Ev_MT_BLL_VODPlay_Ntf)
	BODY(mt::TString, play_url)
	BODY(mt::TU32, error_codeID)

	/*<<�㲥����֪ͨ>>
	*vod_status:����״̬
	*���䷽��vod->dispatch->ui
	*/
	MESSAGE(Ev_MT_BLL_VODStatus_Ntf)
	BODY(mt::TVodPlayInfo, vod_status)

	/*<<��ȡ���е㲥����Ϣ>>
	*vod_id ���㲥Դ��ʶ
	*���䷽��ui->dispatch->vod
	* see Ev_MT_BLL_GetRunVODInfo_Rsp
	*/
	MESSAGE(Ev_MT_BLL_GetRunVODInfo_Req)

	/*<<�������е㲥����Ϣ>>
	*vod_infos �����еĵ㲥��Ϣ
	*���䷽��vod->dispatch->ui
	* see Ev_MT_BLL_GetRunVODInfo_Req
	*/
	MESSAGE(Ev_MT_BLL_GetRunVODInfo_Rsp)
	BODY(mt::TMultiVodPlayInfo, vod_infos)

	/*<<��ȡ�㲥Դ����Ϣ>>
	*vod_id ���㲥Դ��ʶ
	*���䷽��ui->dispatch->vod
	* see Ev_MT_BLL_GetVODInfo_Rsp
	*/
	MESSAGE(Ev_MT_BLL_GetVODInfo_Req)
	BODY(mt::TU32, vod_id)

	/*<<�㲥��ϢӦ��>>
	*vod_info:�㲥Դ��Ϣ
	*error_codeID �����
	*���䷽��vod->dispatch->ui
	* see Ev_MT_BLL_GetVODInfo_Req
	*/
	MESSAGE(Ev_MT_BLL_GetVODInfo_Rsp)
	BODY(mt::TVodPlayInfo, vod_info)
	BODY(mt::TU32, error_codeID)

	/*<<�㲥����>>
	*vod_id ��ֹͣ�㲥Դ�ı�ʶ
	*���䷽��ui->dispatch->vod
	* see Ev_MT_BLL_VODOver_Ntf
	*/
	MESSAGE(Ev_MT_BLL_VODOver_Cmd)
	BODY(mt::TU32, vod_id)

	/*<<�㲥�������>>
	*vod_id ��ֹͣ�㲥Դ�ı�ʶ
	*error_codeID �����Ž��
	*���䷽��vod->dispatch->ui
	* see Ev_MT_BLL_VODOver_Cmd
	*/
	MESSAGE(Ev_MT_BLL_VODOver_Ntf)
	BODY(mt::TU32, vod_id)
	BODY(mt::TU32, error_codeID)

    /*<<�㲥��ͣ>>
	*vod_id ����ͣ�㲥Դ�ı�ʶ
	*���䷽��ui->dispatch->vod
	* see Ev_MT_BLL_VODPause_Ntf
	*/
	MESSAGE(Ev_MT_BLL_VODPause_Cmd)
	BODY(mt::TU32, vod_id)

	/*<<�㲥��ͣ���>>
	*vod_id ��ֹͣ�㲥Դ�ı�ʶ
	*error_codeID �����Ž��
	*���䷽��vod->dispatch->ui
	* see Ev_MT_BLL_VODPause_Cmd
	*/
	MESSAGE(Ev_MT_BLL_VODPause_Ntf)
	BODY(mt::TU32, vod_id)
	BODY(mt::TU32, error_codeID)

	/*<<�ָ��㲥��ͣ>>
	*vod_id ���ָ���ͣ�㲥Դ�ı�ʶ
	*���䷽��ui->dispatch->vod
	* see Ev_MT_BLL_VODResume_Ntf
	*/
	MESSAGE(Ev_MT_BLL_VODResume_Cmd)
	BODY(mt::TU32, vod_id)

	/*<<�㲥��ͣ���>>
	*vod_id ��ֹͣ�㲥Դ�ı�ʶ
	*error_codeID �����Ž��
	*���䷽��vod->dispatch->ui
	* see Ev_MT_BLL_VODResume_Cmd
	*/
	MESSAGE(Ev_MT_BLL_VODResume_Ntf)
	BODY(mt::TU32, vod_id)
	BODY(mt::TU32, error_codeID)

	/*<<�ı�㲥����>>
	*vod_id ���㲥Դ�ı�ʶ
	*speed_scale ���������������ʵı���
	*���䷽��ui->dispatch->vod
	* see Ev_MT_BLL_VODChangeSpeed_Ntf
	*/
	MESSAGE(Ev_MT_BLL_VODChangeSpeed_Cmd)
	BODY(mt::TU32, vod_id)
	BODY(mt::TS8, speed_scale)

	/*<<�ı�㲥���ʽ��>>
	*vod_id ��ֹͣ�㲥Դ�ı�ʶ
	*error_codeID �����Ž��
	*���䷽��vod->dispatch->ui
	* see Ev_MT_BLL_VODChangeSpeed_Cmd
	*/
	MESSAGE(Ev_MT_BLL_VODChangeSpeed_Ntf)
	BODY(mt::TU32, vod_id)
	BODY(mt::TU32, error_codeID)

	/*<<�ı�㲥�Ľ���>>
	*vod_id ���㲥Դ�ı�ʶ
	*cur_time ����ǰ�Ĳ��Ž���
	*���䷽��ui->dispatch->vod
	* see Ev_MT_BLL_VODChangeProcess_Ntf
	*/
	MESSAGE(Ev_MT_BLL_VODChangeProcess_Cmd)
	BODY(mt::TU32, vod_id)
	BODY(mt::TU32, cur_time)

	/*<<�ı�㲥�Ľ��Ƚ��>>
	*vod_id ��ֹͣ�㲥Դ�ı�ʶ
	*error_codeID �����Ž��
	*���䷽��vod->dispatch->ui
	* see Ev_MT_BLL_VODChangeProcess_Cmd
	*/
	MESSAGE(Ev_MT_BLL_VODChangeProcess_Ntf)
	BODY(mt::TU32, vod_id)
	BODY(mt::TU32, error_codeID)
	BODY(mt::TU32, tStartTime)

	/*<<�㲥Դָ��������(��ʱ��֧��)>>
	*vod_id ���㲥Դ��ʶ
	*stream_id ���㲥Դָ������ʶ
	*���䷽��ui->dispatch->vod
	* see Ev_MT_BLL_VODStreamPlay_Ntf
	*/
	MESSAGE(Ev_MT_BLL_VODStreamPlay_Cmd)
	BODY(mt::TU32, vod_id)
	BODY(mt::TU8, stream_id)

	/*<<�㲥Դָ�������Ž��>>
	*vod_id ���㲥Դ�ı�ʶ
	*error_codeID �����Ž��
	*���䷽��vod->dispatch->ui
	* see Ev_MT_BLL_VODStreamPlay_Cmd
	*/
	MESSAGE(Ev_MT_BLL_VODStreamPlay_Ntf)
	BODY(mt::TU32, vod_id)
	BODY(mt::TU8, stream_id)
	BODY(mt::TU32, error_codeID)

	/*<<�㲥ָ��Դ����֪ͨ>>
	*vod_id:�㲥Դ��ʶ
	*stream_status:ָ��Դ״̬
	*���䷽��vod->dispatch->ui
	*/
	MESSAGE(Ev_MT_BLL_VODStreamStatus_Ntf)
	BODY(mt::TU32, vod_id)
	BODY(mt::TStreamInfo, stream_status)

	/*<<��ȡ�㲥Դ����Ϣ>>
	*vod_id ���㲥Դ��ʶ
	*stream_id ���㲥Դָ������ʶ
	*���䷽��ui->dispatch->vod
	* see Ev_MT_BLL_GetVODInfo_Rsp
	*/
	MESSAGE(Ev_MT_BLL_GetVODStreamInfo_Req)
	BODY(mt::TU32, vod_id)
	BODY(mt::TU8, stream_id)

	/*<<�㲥��ϢӦ��>>
	*vod_id:�㲥Դ��ʶ
	*stream_status:ָ��Դ״̬
	*error_codeID �����
	*���䷽��vod->dispatch->ui
	* see Ev_MT_BLL_GetVODInfo_Req
	*/
	MESSAGE(Ev_MT_BLL_GetVODStreamInfo_Rsp)
	BODY(mt::TU32, vod_id)
	BODY(mt::TStreamInfo, stream_info)
	BODY(mt::TU32, error_codeID)

	/*<<�㲥����(��ʱ��֧��(��ʱ��֧��))>>
	*vod_id ��ֹͣ�㲥Դ�ı�ʶ
	*stream_id ���㲥Դָ������ʶ
	*���䷽��ui->dispatch->vod
	* see Ev_MT_BLL_VODStreamOver_Ntf
	*/
	MESSAGE(Ev_MT_BLL_VODStreamOver_Cmd)
	BODY(mt::TU32, vod_id)
	BODY(mt::TU8, stream_id)

	/*<<�㲥�������(��ʱ��֧��)>>
	*vod_id ��ֹͣ�㲥Դ�ı�ʶ
	*error_codeID �����Ž��
	*���䷽��vod->dispatch->ui
	* see Ev_MT_BLL_VODStreamOver_Cmd
	*/
	MESSAGE(Ev_MT_BLL_VODStreamOver_Ntf)
	BODY(mt::TU32, vod_id)
	BODY(mt::TU8, stream_id)
	BODY(mt::TU32, error_codeID)

    /*<<�㲥��ͣ(��ʱ��֧��)>>
	*vod_id ����ͣ�㲥Դ�ı�ʶ
	*stream_id ���㲥Դָ������ʶ
	*���䷽��ui->dispatch->vod
	* see Ev_MT_BLL_VODStreamPause_Ntf
	*/
	MESSAGE(Ev_MT_BLL_VODStreamPause_Cmd)
	BODY(mt::TU32, vod_id)
	BODY(mt::TU8, stream_id)

	/*<<�㲥��ͣ(��ʱ��֧��)���>>
	*vod_id ��ֹͣ�㲥Դ�ı�ʶ
	*error_codeID �����Ž��
	*���䷽��vod->dispatch->ui
	* see Ev_MT_BLL_VODStreamPause_Cmd
	*/
	MESSAGE(Ev_MT_BLL_VODStreamPause_Ntf)
	BODY(mt::TU32, vod_id)
	BODY(mt::TU8, stream_id)
	BODY(mt::TU32, error_codeID)

	/*<<�ָ��㲥��ͣ(��ʱ��֧��)>>
	*vod_id ���ָ���ͣ�㲥Դ�ı�ʶ
	*stream_id ���㲥Դָ������ʶ
	*���䷽��ui->dispatch->vod
	* see Ev_MT_BLL_VODStreamResume_Ntf
	*/
	MESSAGE(Ev_MT_BLL_VODStreamResume_Cmd)
	BODY(mt::TU32, vod_id)
	BODY(mt::TU8, stream_id)

	/*<<�ָ��㲥��ͣ(��ʱ��֧��)���>>
	*vod_id ��ֹͣ�㲥Դ�ı�ʶ
	*error_codeID �����Ž��
	*���䷽��vod->dispatch->ui
	* see Ev_MT_BLL_VODStreamResume_Cmd
	*/
	MESSAGE(Ev_MT_BLL_VODStreamResume_Ntf)
	BODY(mt::TU32, vod_id)
	BODY(mt::TU8, stream_id)
	BODY(mt::TU32, error_codeID)

	/*<<�ı�㲥����(��ʱ��֧��)>>
	*vod_id ���㲥Դ�ı�ʶ
	*stream_id ���㲥Դָ������ʶ
	*speed_scale ���������������ʵı���
	*���䷽��ui->dispatch->vod
	* see Ev_MT_BLL_VODStreamChangeSpeed_Ntf
	*/
	MESSAGE(Ev_MT_BLL_VODStreamChangeSpeed_Cmd)
	BODY(mt::TU32, vod_id)
	BODY(mt::TU8, stream_id)
	BODY(mt::TS8, speed_scale)

	/*<<�ı�㲥����(��ʱ��֧��)���>>
	*vod_id ��ֹͣ�㲥Դ�ı�ʶ
	*error_codeID �����Ž��
	*���䷽��vod->dispatch->ui
	* see Ev_MT_BLL_VODStreamChangeSpeed_Cmd
	*/
	MESSAGE(Ev_MT_BLL_VODStreamChangeSpeed_Ntf)
	BODY(mt::TU32, vod_id)
	BODY(mt::TU8, stream_id)
	BODY(mt::TU32, error_codeID)

	/*<<�ı�㲥�Ľ���(��ʱ��֧��)>>
	*vod_id ���㲥Դ�ı�ʶ
	*stream_id ���㲥Դָ������ʶ
	*cur_time ����ǰ�Ĳ��Ž���
	*���䷽��ui->dispatch->vod
	* see Ev_MT_BLL_VODStreamChangeProcess_Ntf
	*/
	MESSAGE(Ev_MT_BLL_VODStreamChangeProcess_Cmd)
	BODY(mt::TU32, vod_id)
	BODY(mt::TU8, stream_id)
	BODY(mt::TU32, cur_time)

	/*<<�ı�㲥�Ľ���(��ʱ��֧��)���>>
	*vod_id ��ֹͣ�㲥Դ�ı�ʶ
	*error_codeID �����Ž��
	*���䷽��vod->dispatch->ui
	* see Ev_MT_BLL_VODStreamChangeProcess_Cmd
	*/
	MESSAGE(Ev_MT_BLL_VODStreamChangeProcess_Ntf)
	BODY(mt::TU32, vod_id)
	BODY(mt::TU8, stream_id)
	BODY(mt::TU32, error_codeID)

	


		/*����ԤԼֱ�����б�����
	*���䷽��ui->dispatch->vod
	���䷽��ui->dispatch->vod
	* see 
	*/
	MESSAGE(Ev_MT_BLL_VrsGetReserveRoomListInfo_Cmd)
// 	BODY(mt::TVrsGetReserveRoomListReq, TVrsGetReserveRoomListReq)
	
	/*����ԤԼֱ�����б�֪ͨ
	*TU32 ��������
	*TVrsRoomsCfg: ԤԼֱ�����б���Ϣ
	*���䷽��vod->dispatch->ui
	* see 
	*/
	MESSAGE(Ev_MT_BLL_VrsGetReserveRoomListInfo_Ntf)
	BODY(mt::TU32, errid)
	BODY(mt::TVrsRoomsCfg, TVrsRoomsCfg)

	/*����ԤԼֱ�����б����֪ͨ
	*/
	MESSAGE(Ev_MT_BLL_VrsGetReserveRoomListInfo_Fin_Ntf)

	/*����ֱ�����б�����
	*���䷽��ui->dispatch->vod
	���䷽��ui->dispatch->vod
	* see 
	*/
	MESSAGE(Ev_MT_BLL_VrsGetRoomListInfo_Cmd)

	
	/*����ֱ�����б�֪ͨ
	*TU32 ��������
	*TVrsRoomsState: ֱ�����б���Ϣ
	*���䷽��vod->dispatch->ui
	* see 
	*/
	MESSAGE(Ev_MT_BLL_VrsGetRoomListInfo_Ntf)
	BODY(mt::TU32, errid)
	BODY(mt::TVrsRoomsState, TVrsRoomsState)

	/*����ֱ�����б����֪ͨ*/
	MESSAGE(Ev_MT_BLL_VrsGetRoomListInfo_Fin_Ntf)

	/*����ĳһ�ļ����µĽ�Ŀ�б�����
	*���䷽��ui->dispatch->vod
	*TVrsGetPrgsReq���������
	���䷽��ui->dispatch->vod
	* see 
	*/
	MESSAGE(Ev_MT_BLL_VrsGetPrgsInfo_Cmd)
	BODY(mt::TVrsGetPrgsReq, TVrsGetPrgsReq)
	
	/*����ĳһ�ļ����µĽ�Ŀ�б�֪ͨ
	*TU32 ��������
	*TVrsPrgsBaseInfo: ��Ŀ�б������Ϣ
	*TVrsGetPrgsReq : ������Ϣ
	*���䷽��vod->dispatch->ui
	* see 
	*/
	MESSAGE(Ev_MT_BLL_VrsGetPrgsInfo_Ntf)
	BODY(mt::TU32, errid)
	BODY(mt::TVrsPrgsBaseInfo, TVrsPrgsBaseInfo)
	BODY(mt::TVrsGetPrgsReq, TVrsGetPrgsReq)

	/*����ĳһ�ļ����µĽ�Ŀ�б�֪ͨ
	*TU32 ��������
	*TVrsPrgsDetailInfo: ��Ŀ�б������Ϣ
	*TVrsGetPrgsReq : ������Ϣ
	*���䷽��vod->dispatch->ui
	* see 
	*/
	MESSAGE(Ev_MT_BLL_VrsGetPrgsDetailInfo_Ntf)
	BODY(mt::TU32, errid)
	BODY(mt::TVrsPrgsDetailInfo, TVrsPrgsDetailInfo)
	BODY(mt::TVrsGetPrgsReq, TVrsGetPrgsReq)

	/*����ĳһ�ļ����µĽ�Ŀ�б����֪ͨ*/
	MESSAGE(Ev_MT_BLL_VrsGetPrgsInfo_Fin_Ntf)

	/*�����ļ����б�����
	*���䷽��ui->dispatch->vod
	* see 
	*/
	MESSAGE(Ev_MT_BLL_VrsGetFolderInfo_Cmd)

	
	/*�����ļ����б�֪ͨ
	*TU32 ��������
	*TVrsFoldersInfo: �ļ����б�
	*���䷽��vod->dispatch->ui
	* see 
	*/
	MESSAGE(Ev_MT_BLL_VrsGetFolderInfo_Ntf)
	BODY(mt::TU32, errid)
	BODY(mt::TVrsFoldersInfo, TVrsFoldersInfo)
	
	/*�����ļ����б����֪ͨ*/
	MESSAGE(Ev_MT_BLL_VrsGetFolderInfo_Fin_Ntf)

		/*��¼VRSƽ̨����
	*TVrsLoginInfo ����¼�ṹ��
	*���䷽��ui->dispatch->vod
	* see 
	*/
	MESSAGE(Ev_MT_BLL_VrsLogin_Cmd)
	BODY(mt::TVrsLoginInfo, TVrsLoginInfo)
	
	/*��¼VRSƽ̨֪ͨ
	*TU32 ��������
	*���䷽��vod->dispatch->ui
	* see 
	*/
	MESSAGE(Ev_MT_BLL_VrsLogin_Ntf)
	BODY(mt::TU32, errid)
	
	/*ע��VRSƽ̨����
	*TVrsLoginInfo ����¼�ṹ��
	*���䷽��ui->dispatch->vod
	* see 
	*/
	MESSAGE(Ev_MT_BLL_VrsLogout_Cmd)
	
	/*ע��VRSƽ̨֪ͨ
	*TU32 ��������
	*���䷽��vod->dispatch->ui
	* see 
	*/
	MESSAGE(Ev_MT_BLL_VrsLogout_Ntf)
	BODY(mt::TU32, errid)
	
	/*Vrs��ȡ�೬ʱ����(���粻��)
	*TU32 ��������(���ֲ�ͬ�Ļ�ȡ�ӿ�)
	*���䷽��vod->dispatch->ui
	* see 
	*/
	MESSAGE(Ev_MT_BLL_VrsGetListTimerOut_Ntf)
	BODY(mt::TU32, errid)

		/*����ԤԼֱ�����б����� new
	*���䷽��ui->dispatch->vod
	���䷽��ui->dispatch->vod
	* see 
	*/
	MESSAGE(Ev_MT_BLL_VrsNewGetResRoomInfo_Cmd)
 	BODY(mt::TVrsGetReserveRoomListReq, TVrsGetReserveRoomListReq)
	
	/*����ԤԼֱ�����б�֪ͨ new
	*TU32 ��������
	*TVrsRoomsCfg: ԤԼֱ�����б���Ϣ
	*���䷽��vod->dispatch->ui
	* see 
	*/
	MESSAGE(Ev_MT_BLL_VrsNewGetResRoomInfo_Ntf)
	BODY(mt::TU32, errid)
	BODY(mt::TVrsRoomsCfg, TVrsRoomsCfg)

	/*����ԤԼֱ�����б����֪ͨ
	*/
	MESSAGE(Ev_MT_BLL_VrsNewGetResRoomInfo_Fin_Ntf)


#if !defined(_MESSAGE_HELP_)
    EV_BLL_END(MTVOD) = EVSEG_BLL_MTVOD_END
};
#endif//_MESSAGE_HELP_

#define Is_BLL_Vod_Msg(m) ((m) >= EV_BLL_BGN(MTVOD) && (m) <= EV_BLL_END(MTVOD))

#endif//_MTBLLVODMSG_H_
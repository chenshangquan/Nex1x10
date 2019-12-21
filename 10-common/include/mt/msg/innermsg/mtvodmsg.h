#ifndef _MTVODMSG_H_
#define _MTVODMSG_H_

#include "mtmsgid.h"

#if !defined(_MESSAGE_HELP_)
enum EmMtVodMsg
{
    EV_BGN(MTVOD) = EVSEG_MTVOD_BGN,
#endif//_MESSAGE_HELP_
	/*<<�㲥����>>
	*play_url �����ŵĵ�ַ
	*���䷽��ui->dispatch->vod
	* see Ev_MT_VODPlay_Ntf
	*/
	MESSAGE(Ev_MT_VODPlay_Cmd)
	BODY(mt::TString, play_url)

	/*<<�㲥���>>
	*play_url �����ŵĵ�ַ
	*error_codeID �����Ž��
	*���䷽��vod->dispatch->ui
	* see Ev_MT_VODPlay_Cmd
	*/
	MESSAGE(Ev_MT_VODPlay_Ntf)
	BODY(mt::TString, play_url)
	BODY(mt::TU32, error_codeID)

	/*<<�㲥����֪ͨ>>
	*vod_status:����״̬
	*���䷽��vod->dispatch->ui
	*/
	MESSAGE(Ev_MT_VODStatus_Ntf)
	BODY(mt::TVodPlayInfo, vod_status)

	/*<<��ȡ���е㲥����Ϣ>>
	*vod_id ���㲥Դ��ʶ
	*���䷽��ui->dispatch->vod
	* see Ev_MT_GetRunVODInfo_Rsp
	*/
	MESSAGE(Ev_MT_GetRunVODInfo_Req)

	/*<<�������е㲥����Ϣ>>
	*vod_infos �����еĵ㲥��Ϣ
	*���䷽��vod->dispatch->ui
	* see Ev_MT_GetRunVODInfo_Req
	*/
	MESSAGE(Ev_MT_GetRunVODInfo_Rsp)
	BODY(mt::TMultiVodPlayInfo, vod_infos)

	/*<<��ȡ�㲥Դ����Ϣ>>
	*vod_id ���㲥Դ��ʶ
	*���䷽��ui->dispatch->vod
	* see Ev_MT_GetVODInfo_Rsp
	*/
	MESSAGE(Ev_MT_GetVODInfo_Req)
	BODY(mt::TU32, vod_id)

	/*<<�㲥��ϢӦ��>>
	*vod_info:�㲥Դ��Ϣ
	*error_codeID �����
	*���䷽��vod->dispatch->ui
	* see Ev_MT_GetVODInfo_Req
	*/
	MESSAGE(Ev_MT_GetVODInfo_Rsp)
	BODY(mt::TVodPlayInfo, vod_info)
	BODY(mt::TU32, error_codeID)

	/*<<�㲥����>>
	*vod_id ��ֹͣ�㲥Դ�ı�ʶ
	*���䷽��ui->dispatch->vod
	* see Ev_MT_VODOver_Ntf
	*/
	MESSAGE(Ev_MT_VODOver_Cmd)
	BODY(mt::TU32, vod_id)

	/*<<�㲥�������>>
	*vod_id ��ֹͣ�㲥Դ�ı�ʶ
	*error_codeID �����Ž��
	*���䷽��vod->dispatch->ui
	* see Ev_MT_VODOver_Cmd
	*/
	MESSAGE(Ev_MT_VODOver_Ntf)
	BODY(mt::TU32, vod_id)
	BODY(mt::TU32, error_codeID)

    /*<<�㲥��ͣ>>
	*vod_id ����ͣ�㲥Դ�ı�ʶ
	*���䷽��ui->dispatch->vod
	* see Ev_MT_VODPause_Ntf
	*/
	MESSAGE(Ev_MT_VODPause_Cmd)
	BODY(mt::TU32, vod_id)

	/*<<�㲥��ͣ���>>
	*vod_id ��ֹͣ�㲥Դ�ı�ʶ
	*error_codeID �����Ž��
	*���䷽��vod->dispatch->ui
	* see Ev_MT_VODPause_Cmd
	*/
	MESSAGE(Ev_MT_VODPause_Ntf)
	BODY(mt::TU32, vod_id)
	BODY(mt::TU32, error_codeID)

	/*<<�ָ��㲥��ͣ>>
	*vod_id ���ָ���ͣ�㲥Դ�ı�ʶ
	*���䷽��ui->dispatch->vod
	* see Ev_MT_VODResume_Ntf
	*/
	MESSAGE(Ev_MT_VODResume_Cmd)
	BODY(mt::TU32, vod_id)

	/*<<�㲥��ͣ���>>
	*vod_id ��ֹͣ�㲥Դ�ı�ʶ
	*error_codeID �����Ž��
	*���䷽��vod->dispatch->ui
	* see Ev_MT_VODResume_Cmd
	*/
	MESSAGE(Ev_MT_VODResume_Ntf)
	BODY(mt::TU32, vod_id)
	BODY(mt::TU32, error_codeID)

	/*<<�ı�㲥����>>
	*vod_id ���㲥Դ�ı�ʶ
	*speed_scale ���������������ʵı���
	*���䷽��ui->dispatch->vod
	* see Ev_MT_VODChangeSpeed_Ntf
	*/
	MESSAGE(Ev_MT_VODChangeSpeed_Cmd)
	BODY(mt::TU32, vod_id)
	BODY(mt::TS8, speed_scale)

	/*<<�ı�㲥���ʽ��>>
	*vod_id ��ֹͣ�㲥Դ�ı�ʶ
	*error_codeID �����Ž��
	*���䷽��vod->dispatch->ui
	* see Ev_MT_VODChangeSpeed_Cmd
	*/
	MESSAGE(Ev_MT_VODChangeSpeed_Ntf)
	BODY(mt::TU32, vod_id)
	BODY(mt::TU32, error_codeID)

	/*<<�ı�㲥�Ľ���>>
	*vod_id ���㲥Դ�ı�ʶ
	*cur_time ����ǰ�Ĳ��Ž���
	*���䷽��ui->dispatch->vod
	* see Ev_MT_VODChangeProcess_Ntf
	*/
	MESSAGE(Ev_MT_VODChangeProcess_Cmd)
	BODY(mt::TU32, vod_id)
	BODY(mt::TU32, cur_time)

	/*<<�ı�㲥�Ľ��Ƚ��>>
	*vod_id ��ֹͣ�㲥Դ�ı�ʶ
	*error_codeID �����Ž��
	*���䷽��vod->dispatch->ui
	* see Ev_MT_VODChangeProcess_Cmd
	*/
	MESSAGE(Ev_MT_VODChangeProcess_Ntf)
	BODY(mt::TU32, vod_id)
	BODY(mt::TU32, error_codeID)
	BODY(mt::TU32, tStartTime)

	/*<<�㲥Դָ��������(��ʱ��֧��)>>
	*vod_id ���㲥Դ��ʶ
	*stream_id ���㲥Դָ������ʶ
	*���䷽��ui->dispatch->vod
	* see Ev_MT_VODStreamPlay_Ntf
	*/
	MESSAGE(Ev_MT_VODStreamPlay_Cmd)
	BODY(mt::TU32, vod_id)
	BODY(mt::TU8, stream_id)

	/*<<�㲥Դָ�������Ž��>>
	*vod_id ���㲥Դ�ı�ʶ
	*error_codeID �����Ž��
	*���䷽��vod->dispatch->ui
	* see Ev_MT_VODStreamPlay_Cmd
	*/
	MESSAGE(Ev_MT_VODStreamPlay_Ntf)
	BODY(mt::TU32, vod_id)
	BODY(mt::TU8, stream_id)
	BODY(mt::TU32, error_codeID)

	/*<<�㲥ָ��Դ����֪ͨ>>
	*vod_id:�㲥Դ��ʶ
	*stream_status:ָ��Դ��Ϣ
	*���䷽��vod->dispatch->ui
	*/
	MESSAGE(Ev_MT_VODStreamStatus_Ntf)
	BODY(mt::TU32, vod_id)
	BODY(mt::TStreamInfo, stream_status)
	
	/*<<�㲥ָ��Դָ������ʼ����>
	*vod_id:�㲥Դ��ʶ
	*stream_status:ָ��Դ״̬
	*rtp_local_addr:����rtp��ַ��Ϣ
	*rtcp_local_addr:����rtcp��ַ��Ϣ
	*rtp_remote_addr:Զ��rtp��ַ��Ϣ
	*rtcp_remote_addr:Զ��rtcp��ַ��Ϣ
	*���䷽��vod->dispatch->mtservice
	*/
	MESSAGE(Ev_MT_VODStreamStartRecieve_Cmd)
	BODY(mt::TU32, vod_id)
	BODY(mt::TStreamInfo, stream_status)
	BODY(mt::TNetAddr, rtp_local_addr)
	BODY(mt::TNetAddr, rtcp_local_addr)
	BODY(mt::TNetAddr, rtp_remote_addr)
	BODY(mt::TNetAddr, rtcp_remote_addr)

	/*vod_id:�㲥Դ��ʶ
	*stream_status:ָ��Դ״̬
	*���䷽��vod->dispatch->mtservice
	*/
	MESSAGE(Ev_MT_VODSwitchStream_Cmd)
	BODY(mt::TU32, vod_id)
	BODY(mt::TStreamInfo, stream_status)



	/*<<�㲥ָ��Դָ������������>
	*vod_id:�㲥Դ��ʶ
	*stream_status:ָ��Դ״̬
	*���䷽��vod->dispatch->mtservice
	*/
	MESSAGE(Ev_MT_VODStreamStopRecieve_Cmd)
	BODY(mt::TU32, vod_id)
	BODY(mt::TStreamInfo, stream_status)

	/*<<���е㲥������>
	*���䷽��mtservice->dispatch->vod
	*/
	MESSAGE(Ev_MT_AllVODOver_Cmd)

	/*<<��ȡ�㲥Դ����Ϣ>>
	*vod_id ���㲥Դ��ʶ
	*stream_id ���㲥Դָ������ʶ
	*���䷽��ui->dispatch->vod
	* see Ev_MT_GetVODInfo_Rsp
	*/
	MESSAGE(Ev_MT_GetVODStreamInfo_Req)
	BODY(mt::TU32, vod_id)
	BODY(mt::TU8, stream_id)

	/*<<�㲥��ϢӦ��>>
	*vod_id:�㲥Դ��ʶ
	*stream_status:ָ��Դ״̬
	*error_codeID �����
	*���䷽��vod->dispatch->ui
	* see Ev_MT_GetVODInfo_Req
	*/
	MESSAGE(Ev_MT_GetVODStreamInfo_Rsp)
	BODY(mt::TU32, vod_id)
	BODY(mt::TStreamInfo, stream_info)
	BODY(mt::TU32, error_codeID)

	/*<<�㲥����(��ʱ��֧��(��ʱ��֧��))>>
	*vod_id ��ֹͣ�㲥Դ�ı�ʶ
	*stream_id ���㲥Դָ������ʶ
	*���䷽��ui->dispatch->vod
	* see Ev_MT_VODStreamOver_Ntf
	*/
	MESSAGE(Ev_MT_VODStreamOver_Cmd)
	BODY(mt::TU32, vod_id)
	BODY(mt::TU8, stream_id)

	/*<<�㲥�������(��ʱ��֧��)>>
	*vod_id ��ֹͣ�㲥Դ�ı�ʶ
	*error_codeID �����Ž��
	*���䷽��vod->dispatch->ui
	* see Ev_MT_VODStreamOver_Cmd
	*/
	MESSAGE(Ev_MT_VODStreamOver_Ntf)
	BODY(mt::TU32, vod_id)
	BODY(mt::TU8, stream_id)
	BODY(mt::TU32, error_codeID)

    /*<<�㲥��ͣ(��ʱ��֧��)>>
	*vod_id ����ͣ�㲥Դ�ı�ʶ
	*stream_id ���㲥Դָ������ʶ
	*���䷽��ui->dispatch->vod
	* see Ev_MT_VODStreamPause_Ntf
	*/
	MESSAGE(Ev_MT_VODStreamPause_Cmd)
	BODY(mt::TU32, vod_id)
	BODY(mt::TU8, stream_id)

	/*<<�㲥��ͣ(��ʱ��֧��)���>>
	*vod_id ��ֹͣ�㲥Դ�ı�ʶ
	*error_codeID �����Ž��
	*���䷽��vod->dispatch->ui
	* see Ev_MT_VODStreamPause_Cmd
	*/
	MESSAGE(Ev_MT_VODStreamPause_Ntf)
	BODY(mt::TU32, vod_id)
	BODY(mt::TU8, stream_id)
	BODY(mt::TU32, error_codeID)

	/*<<�ָ��㲥��ͣ(��ʱ��֧��)>>
	*vod_id ���ָ���ͣ�㲥Դ�ı�ʶ
	*stream_id ���㲥Դָ������ʶ
	*���䷽��ui->dispatch->vod
	* see Ev_MT_VODStreamResume_Ntf
	*/
	MESSAGE(Ev_MT_VODStreamResume_Cmd)
	BODY(mt::TU32, vod_id)
	BODY(mt::TU8, stream_id)

	/*<<�ָ��㲥��ͣ(��ʱ��֧��)���>>
	*vod_id ��ֹͣ�㲥Դ�ı�ʶ
	*error_codeID �����Ž��
	*���䷽��vod->dispatch->ui
	* see Ev_MT_VODStreamResume_Cmd
	*/
	MESSAGE(Ev_MT_VODStreamResume_Ntf)
	BODY(mt::TU32, vod_id)
	BODY(mt::TU8, stream_id)
	BODY(mt::TU32, error_codeID)

	/*<<�ı�㲥����(��ʱ��֧��)>>
	*vod_id ���㲥Դ�ı�ʶ
	*stream_id ���㲥Դָ������ʶ
	*speed_scale ���������������ʵı���
	*���䷽��ui->dispatch->vod
	* see Ev_MT_VODStreamChangeSpeed_Ntf
	*/
	MESSAGE(Ev_MT_VODStreamChangeSpeed_Cmd)
	BODY(mt::TU32, vod_id)
	BODY(mt::TU8, stream_id)
	BODY(mt::TS8, speed_scale)

	/*<<�ı�㲥����(��ʱ��֧��)���>>
	*vod_id ��ֹͣ�㲥Դ�ı�ʶ
	*error_codeID �����Ž��
	*���䷽��vod->dispatch->ui
	* see Ev_MT_VODStreamChangeSpeed_Cmd
	*/
	MESSAGE(Ev_MT_VODStreamChangeSpeed_Ntf)
	BODY(mt::TU32, vod_id)
	BODY(mt::TU8, stream_id)
	BODY(mt::TU32, error_codeID)

	/*<<�ı�㲥�Ľ���(��ʱ��֧��)>>
	*vod_id ���㲥Դ�ı�ʶ
	*stream_id ���㲥Դָ������ʶ
	*cur_time ����ǰ�Ĳ��Ž���
	*���䷽��ui->dispatch->vod
	* see Ev_MT_VODStreamChangeProcess_Ntf
	*/
	MESSAGE(Ev_MT_VODStreamChangeProcess_Cmd)
	BODY(mt::TU32, vod_id)
	BODY(mt::TU8, stream_id)
	BODY(mt::TU32, cur_time)

	/*<<�ı�㲥�Ľ���(��ʱ��֧��)���>>
	*vod_id ��ֹͣ�㲥Դ�ı�ʶ
	*error_codeID �����Ž��
	*���䷽��vod->dispatch->ui
	* see Ev_MT_VODStreamChangeProcess_Cmd
	*/
	MESSAGE(Ev_MT_VODStreamChangeProcess_Ntf)
	BODY(mt::TU32, vod_id)
	BODY(mt::TU8, stream_id)
	BODY(mt::TU32, error_codeID)

	/*<<�յ�rtsp�ͻ��˵Ļص�������CMD_OPTIONS�����д����ڲ�ʹ��>>
	*vod_id ���㲥Դ�ı�ʶ
	*stream_id ���㲥Դָ������ʶ
	*result_code �����
	*���䷽��vod->dispatch->vod
	* see SendOptionsCommand
	*/
	MESSAGE(Ev_MT_RtspOptions_Cmd)
	BODY(mt::TU32, vod_id)
	BODY(mt::TU8, stream_id)
	BODY(mt::TS32, result_code)

	/*<<�յ�rtsp�ͻ��˵Ļص�������CMD_DESCRIBE�����д����ڲ�ʹ��>>
	*vod_id ���㲥Դ�ı�ʶ
	*stream_id ���㲥Դָ������ʶ
	*result_code �����
	*���䷽��vod->dispatch->vod
	* see SendDescribeCommand
	*/
	MESSAGE(Ev_MT_RtspDecribe_Cmd)
	BODY(mt::TU32, vod_id)
	BODY(mt::TU8, stream_id)
	BODY(mt::TS32, result_code)

	/*<<�յ�rtsp�ͻ��˵Ļص�������CMD_SETUP�����д����ڲ�ʹ��>>
	*vod_id ���㲥Դ�ı�ʶ
	*stream_id ���㲥Դָ������ʶ
	*result_code �����
	*���䷽��vod->dispatch->vod
	* see SendSetupCommand
	*/
	MESSAGE(Ev_MT_RtspSetup_Cmd)
	BODY(mt::TU32, vod_id)
	BODY(mt::TU8, stream_id)
	BODY(mt::TS32, result_code)

	/*<<�յ�rtsp�ͻ��˵Ļص�������CMD_PLAY�����д����ڲ�ʹ��>>
	*vod_id ���㲥Դ�ı�ʶ
	*stream_id ���㲥Դָ������ʶ
	*result_code �����
	*���䷽��vod->dispatch->vod
	* see SendPlayCommand
	*/
	MESSAGE(Ev_MT_RtspPlay_Cmd)
	BODY(mt::TU32, vod_id)
	BODY(mt::TU8, stream_id)
	BODY(mt::TS32, result_code)

	/*<<�յ�rtsp�ͻ��˵Ļص�������CMD_PAUSE�����д����ڲ�ʹ��>>
	*vod_id ���㲥Դ�ı�ʶ
	*stream_id ���㲥Դָ������ʶ
	*result_code �����
	*���䷽��vod->dispatch->vod
	* see SendPauseCommand
	*/
	MESSAGE(Ev_MT_RtspPause_Cmd)
	BODY(mt::TU32, vod_id)
	BODY(mt::TU8, stream_id)
	BODY(mt::TS32, result_code)

	/*<<�յ�rtsp�ͻ��˵Ļص�������CMD_ANNOUNCE�����д����ڲ�ʹ��>>
	*vod_id ���㲥Դ�ı�ʶ
	*stream_id ���㲥Դָ������ʶ
	*result_code �����
	*���䷽��vod->dispatch->vod
	* see SendAnnounceCommand(��������������)
	*/
	MESSAGE(Ev_MT_RtspAnnounce_Cmd)
	BODY(mt::TU32, vod_id)
	BODY(mt::TU8, stream_id)
	BODY(mt::TS32, result_code)

	/*<<�յ�rtsp�ͻ��˵Ļص�������CMD_TEARDOWN�����д����ڲ�ʹ��>>
	*vod_id ���㲥Դ�ı�ʶ
	*stream_id ���㲥Դָ������ʶ
	*result_code �����
	*���䷽��vod->dispatch->vod
	* see SendTeardownCommand
	*/
	MESSAGE(Ev_MT_RtspTearDown_Cmd)
	BODY(mt::TU32, vod_id)
	BODY(mt::TU8, stream_id)
	BODY(mt::TS32, result_code)

	/*<<�յ�rtsp�ͻ��˵Ļص�������CMD_SETPARAMETER�����д����ڲ�ʹ��>>
	*vod_id ���㲥Դ�ı�ʶ
	*stream_id ���㲥Դָ������ʶ
	*result_code �����
	*���䷽��vod->dispatch->vod
	* see SendSetParameterCommand
	*/
	MESSAGE(Ev_MT_RtspSetParameter_Cmd)
	BODY(mt::TU32, vod_id)
	BODY(mt::TU8, stream_id)
	BODY(mt::TS32, result_code)

	/*<<�յ�rtsp�ͻ��˵Ļص�������CMD_GETPARAMETER�����д����ڲ�ʹ��>>
	*vod_id ���㲥Դ�ı�ʶ
	*stream_id ���㲥Դָ������ʶ
	*result_code �����
	*���䷽��vod->dispatch->vod
	* see SendGetParameterCommand
	*/
	MESSAGE(Ev_MT_RtspGetParameter_Cmd)
	BODY(mt::TU32, vod_id)
	BODY(mt::TU8, stream_id)
	BODY(mt::TS32, result_code)

	/*<<�յ�rtsp�ͻ��˵Ļص�������CMD_DISCONNECT�����д����ڲ�ʹ��>>
	*vod_id ���㲥Դ�ı�ʶ
	*stream_id ���㲥Դָ������ʶ
	*result_code �����
	*���䷽��vod->dispatch->vod
	* see 
	*/
	MESSAGE(Ev_MT_RtspDisconnect_Cmd)
	BODY(mt::TU32, vod_id)
	BODY(mt::TU8, stream_id)
	BODY(mt::TS32, result_code)

    /*<<�յ�rtsp�ͻ��˵Ļص�������CMD_GET�����д����ڲ�ʹ��>>
	*vod_id ���㲥Դ�ı�ʶ
	*stream_id ���㲥Դָ������ʶ
	*result_code �����
	*���䷽��vod->dispatch->vod
	* see 
	*/
	MESSAGE(Ev_MT_RtspGet_Cmd)
	BODY(mt::TU32, vod_id)
	BODY(mt::TU8, stream_id)
	BODY(mt::TS32, result_code)

	/*<<�յ�rtsp�ͻ��˵Ļص�������CMD_POST�����д����ڲ�ʹ��>>
	*vod_id ���㲥Դ�ı�ʶ
	*stream_id ���㲥Դָ������ʶ
	*result_code �����
	*���䷽��vod->dispatch->vod
	* see 
	*/
	MESSAGE(Ev_MT_RtspPost_Cmd)
	BODY(mt::TU32, vod_id)
	BODY(mt::TU8, stream_id)
	BODY(mt::TS32, result_code)

	

	

	


	

		/*����ԤԼֱ�����б�����
	*���䷽��ui->dispatch->vod
	���䷽��ui->dispatch->vod
	* see 
	*/
	MESSAGE(Ev_MT_VrsGetReserveRoomListInfo_Cmd)
// 	BODY(mt::TVrsGetReserveRoomListReq, TVrsGetReserveRoomListReq)
	
	/*����ԤԼֱ�����б�֪ͨ
	*TU32 ��������
	*TVrsRoomsCfg: ԤԼֱ�����б���Ϣ
	*���䷽��vod->dispatch->ui
	* see 
	*/
	MESSAGE(Ev_MT_VrsGetReserveRoomListInfo_Ntf)
	BODY(mt::TU32, errid)
	BODY(mt::TVrsRoomsCfg, TVrsRoomsCfg)

	/*����ԤԼֱ�����б����֪ͨ
	*/
	MESSAGE(Ev_MT_VrsGetReserveRoomListInfo_Fin_Ntf)


	/*����ֱ�����б�����
	*���䷽��ui->dispatch->vod
	���䷽��ui->dispatch->vod
	* see 
	*/
	MESSAGE(Ev_MT_VrsGetRoomListInfo_Cmd)

	
	/*����ֱ�����б�֪ͨ
	*TU32 ��������
	*TVrsRoomsState: ֱ�����б���Ϣ
	*���䷽��vod->dispatch->ui
	* see 
	*/
	MESSAGE(Ev_MT_VrsGetRoomListInfo_Ntf)
	BODY(mt::TU32, errid)
	BODY(mt::TVrsRoomsState, TVrsRoomsState)

	/*����ֱ�����б����֪ͨ*/
	MESSAGE(Ev_MT_VrsGetRoomListInfo_Fin_Ntf)

	/*����ĳһ�ļ����µĽ�Ŀ�б�����
	*���䷽��ui->dispatch->vod
	*TVrsGetPrgsReq���������
	���䷽��ui->dispatch->vod
	* see 
	*/
	MESSAGE(Ev_MT_VrsGetPrgsInfo_Cmd)
	BODY(mt::TVrsGetPrgsReq, TVrsGetPrgsReq)
	
	/*����ĳһ�ļ����µĽ�Ŀ�б�֪ͨ
	*TU32 ��������
	*TVrsPrgsInfo: ��Ŀ�б������Ϣ
	*���䷽��vod->dispatch->ui
	* see 
	*/
	MESSAGE(Ev_MT_VrsGetPrgsInfo_Ntf)
	BODY(mt::TU32, errid)
	BODY(mt::TVrsPrgsBaseInfo, TVrsPrgsBaseInfo)
	BODY(mt::TVrsGetPrgsReq, TVrsGetPrgsReq)

	/*����ĳһ�ļ����µĽ�Ŀ�б�֪ͨ
	*TU32 ��������
	*TVrsPrgsDetailInfo: ��Ŀ�б������Ϣ
	*���䷽��vod->dispatch->ui
	* see 
	*/
	MESSAGE(Ev_MT_VrsGetPrgsDetailInfo_Ntf)
	BODY(mt::TU32, errid)
	BODY(mt::TVrsPrgsDetailInfo, TVrsPrgsDetailInfo)
	BODY(mt::TVrsGetPrgsReq, TVrsGetPrgsReq)

	/*����ĳһ�ļ����µĽ�Ŀ�б����֪ͨ*/
	MESSAGE(Ev_MT_VrsGetPrgsInfo_Fin_Ntf)

	/*�����ļ����б�����
	*���䷽��ui->dispatch->vod
	* see 
	*/
	MESSAGE(Ev_MT_VrsGetFolderInfo_Cmd)

	
	/*�����ļ����б�֪ͨ
	*TU32 ��������
	*TVrsFoldersInfo: �ļ����б�
	*���䷽��vod->dispatch->ui
	* see 
	*/
	MESSAGE(Ev_MT_VrsGetFolderInfo_Ntf)
	BODY(mt::TU32, errid)
	BODY(mt::TVrsFoldersInfo, TVrsFoldersInfo)
	
	/*�����ļ����б����֪ͨ*/
	MESSAGE(Ev_MT_VrsGetFolderInfo_Fin_Ntf)

		/*��¼VRSƽ̨����
	*TVrsLoginInfo ����¼�ṹ��
	*���䷽��ui->dispatch->vod
	* see 
	*/
	MESSAGE(Ev_MT_VrsLogin_Cmd)
	BODY(mt::TVrsLoginInfo, TVrsLoginInfo)
	
	/*��¼VRSƽ̨֪ͨ
	*TU32 ��������
	*���䷽��vod->dispatch->ui
	* see 
	*/
	MESSAGE(Ev_MT_VrsLogin_Ntf)
	BODY(mt::TU32, errid)

	/*Vrs��ȡ�೬ʱ����(���粻��)
	*TU32 ��������(���ֲ�ͬ�Ļ�ȡ�ӿ�)
	*���䷽��vod->dispatch->ui
	* see 
	*/
	MESSAGE(Ev_MT_VrsGetListTimerOut_Ntf)
	BODY(mt::TU32, errid)

#if !defined(_MESSAGE_HELP_)
    EV_END(MTVOD) = EVSEG_MTVOD_END
};
#endif//_MESSAGE_HELP_

#define Is_Vod_Msg(m) ((m) >= EV_BGN(MTVOD) && (m) <= EV_END(MTVOD))

#endif//_MTVODMSG_H_
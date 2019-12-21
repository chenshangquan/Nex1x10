#ifndef _H323MSG_H_
#define _H323MSG_H_

#include "mtmsgid.h"

#if !defined(_MESSAGE_HELP_)
enum EmMtH323Msg
{

	//������ϵͳ�õ������е���Ϣ������� ������Ҫ���֣�mtconfģ�飬 mth323�õ��ģ� ����mc�õ�����Ϣ��
	EV_BGN(H323) = EVSEG_H323_BGN,
#endif
	
	/*
    mth323--------------------->stackout  
	        Ev_H323_XXX_Cmd      
    mth323<--------------------stackin/stackout
            Ev_H323_XXXX_Ntf
	
	*/
	

	/*<< Э��ջ���� >>
	* ��Ϣ���� ��stackin ==> stackin
	*/
	MESSAGE( Ev_H323_StackRuning_Cmd )

	/*<< �����º��� >>
	* tHandle:  Э��ջ���
	* ��Ϣ���� ��mth323service ==> stackout
	*/
	MESSAGE( Ev_H323_NewCall_Cmd )
	BODY( mt::TH323StackHandle, tHandle)

	/*<< �����º��� >>
	* tHandle:    Э��ջ���
	* tCallParam��Э��ջ���в���
	* ��Ϣ���� ��mth323service ==> stackout
	*/
	MESSAGE( Ev_H323_MakeCall_Cmd )
	BODY( mt::TH323StackHandle, tHandle)
	BODY( mt::TBytes,  tCallParam)  //TCALLPARM


	/*<< �����º��� >>
	* tHandle:     Э��ջ���
	* hangup_reason���Ҷ�ԭ��
	* ��Ϣ���� ��mth323service ==> stackout
	*/
	MESSAGE( Ev_H323_HangupCall_Cmd )
	BODY( mt::TH323StackHandle, tHandle)
	BODY( mt::TU32,  hangup_reason)


	/*<< �����º��� >>
	* tHandle:     Э��ջ���
	* tCallParam�� Э��ջ���в���
	* ��Ϣ���� ��mth323service ==> stackout
	*/
	MESSAGE( Ev_H323_AcceptCall_Cmd )
	BODY( mt::TH323StackHandle, tHandle)
	BODY( mt::TBytes,  tCallParam) //TNODEINFO


	/*<< �º��е��� >>
	* tHandle:  Э��ջ���
	* ��Ϣ���� ��stackout/stackin==>mth323service
	*/
	MESSAGE( Ev_H323_NewCall_Ntf )
	BODY( mt::TH323StackHandle, tHandle)

	/*<< 460newcall >>
	* ���յ�sci��Ϣ�����ж���Ҫ��460call���Զˣ�������tcp���ӵ��Զˣ���������Ҫ��newcall, �����Զ�����setupʱ��������newcall����
	* tHandle:  Э��ջ���
	* ��Ϣ���� ��stackout/stackin==>mth323service
	*/
	MESSAGE( Ev_H323_460NewCall_Ntf )
	BODY( mt::TH323StackHandle, tHandle)


	/*<< callincoming >>
	* tHandle:  Э��ջ���
	* tCallParam: Э��ջ���в���
	* ��Ϣ���� ��stackout/stackin==>mth323service
	*/
	MESSAGE( Ev_H323_CallIncoming_Ntf)
	BODY( mt::TH323StackHandle, tHandle)
	BODY( mt::TBytes,   tCallParam) //TCALLPARM

	/*<< ����connected >>
	* tHandle:  Э��ջ���
	* tCallParam: Э��ջ���в���
	* ��Ϣ���� ��stackin==>mth323service
	*/
	MESSAGE( Ev_H323_CallConnected_Ntf)
	BODY( mt::TH323StackHandle, tHandle)
	BODY( mt::TBytes,  tCallParam) //TNODEINFO

	/*<< ����disconnected >>
	* tHandle:  Э��ջ���
	* tCallParam: ���в���
	* ��Ϣ���� ��stackout/stackin==>mth323service
	*/
	MESSAGE( Ev_H323_CallDisconnected_Ntf )
	BODY( mt::TH323StackHandle, tHandle)
	


	///ras���

	/*<< sci��Ϣ >>
	* tSciinfo: sci��Ϣ��
	* ��Ϣ���� ��stackout/stackin==>mth323service
	*/
	MESSAGE( Ev_H323_RasSci_Ntf)
	BODY( mt::TBytes, tSciinfo)    //TSCIINFO

	/*<< scr��Ϣ >>
	* tSciinfo: sci��Ϣ��
	* ��Ϣ���� ��stackout/stackin==>mth323service
	*/
	MESSAGE( Ev_H323_RasScr_Cmd)
	BODY( mt::TBytes, tScr)    //TSCIINFO



	/*<< ע������ >>
	* reg_info: ע���Ƿ�ɹ�
	* rcf_info  rcf_info
	* ��Ϣ���� ��stackout/stackin==>mth323service
	*/
	MESSAGE( Ev_H323_RasRrq_Req)
	BODY( mt::TBytes, tRrq )    //TRRQINFO
 	
	/*<< ע���� >>
	* tHandle:  Э��ջ���
	* reg_info: ע���Ƿ�ɹ�
	* rcf_info  rcf_info
	* ��Ϣ���� ��stackout/stackin==>mth323service
	*/
	MESSAGE( Ev_H323_RasGKState_Rsp )
	BODY(mt::TGkRegInfo, reg_info)
	BODY(mt::TMtRCFInfo, rcf_info)


	/*<< ucf֪ͨ >>
	* tHandle:  Э��ջ���
	* ��Ϣ���� ��stackout/stackin==>mth323service
	*/
	MESSAGE( Ev_H323_RasUCF_Ntf )
	BODY( mt::TH323StackHandle, tHandle )

	/*<< urj֪ͨ >>
	* tHandle:  Э��ջ���
	* ��Ϣ���� ��stackout/stackin==>mth323service
	*/
	MESSAGE( Ev_H323_RasURJ_Ntf )
	BODY( mt::TH323StackHandle, tHandle )

	/*<< Urq֪ͨ >>
	* tHandle:  Э��ջ���
	* ��Ϣ���� ��stackout/stackin==>mth323service
	*/
	MESSAGE( Ev_H323_RasUrq_Req ) 


	/*<< acf֪ͨ >>
	* tHandle:  Э��ջ���
	* acf_info: acf���
	* ��Ϣ���� ��stackout/stackin==>mth323service
	*/
	MESSAGE( Ev_H323_RasACF_Ntf )
	BODY( mt::TH323StackHandle, tHandle )
	BODY(mt::TMtACFInfo, acf_info)

	/*<< arj֪ͨ >>
	* tHandle:  Э��ջ���
	* acf_info: acf���
	* ��Ϣ���� ��stackout/stackin==>mth323service
	*/
	MESSAGE( Ev_H323_RasARJ_Ntf )
	BODY( mt::TH323StackHandle, tHandle )
	BODY(mt::TU32, failed_reason)
	
	/*<< drq֪ͨ >>
	* tHandle:  Э��ջ���
	* ��Ϣ���� ��stackout/stackin==>mth323service
	*/
	MESSAGE( Ev_H323_RasDRQ_Ntf )
	BODY( mt::TH323StackHandle, tHandle )
	
	/*<< ucf֪ͨ >>
	* tHandle:  Э��ջ���
	* ��Ϣ���� ��stackout/stackin==>mth323service
	*/
	MESSAGE( Ev_H323_RasDCF_Ntf )
	BODY( mt::TH323StackHandle, tHandle )

	

	/*<< arq���� >>
	* tHandle:  Э��ջ���
	* ��Ϣ���� ��stackout/stackin==>mth323service
	*/
	MESSAGE( Ev_H323_RasArq_Req) 


	/*<< drq֪ͨ >>
	* tHandle:  Э��ջ���
	* ��Ϣ���� ��stackout/stackin==>mth323service
	*/
	MESSAGE( Ev_H323_RasDrq_Req) 


	MESSAGE( Ev_H323_RasConfDetailInfo_Req )
	BODY( mt::TBytes,   tNSMinfo)   //TNSMINFO

	MESSAGE( Ev_H323_RasConfDetailInfo_Rsp )
	BODY( mt::TBytes,   tNSMinfo)   //TNSMINFO

	MESSAGE( Ev_H323_RasRoomNum_Req )
	BODY( mt::TBytes,   tNSMinfo)   //TNSMINFO

	MESSAGE( Ev_H323_RasRoomNum_Rsp )
	BODY( mt::TBytes,   tNSMinfo)   //TNSMINFO


	MESSAGE( Ev_H323_RasJoinConf_Req )
	BODY( mt::TBytes,        tNSMinfo)   //TNSMINFO
	
	MESSAGE( Ev_H323_RasJoinConf_Rsp )
	BODY( mt::TBytes,        tNSMinfo)   //TNSMINFO

	MESSAGE( Ev_H323_RasCreateConf_Req )
	BODY( mt::TBytes,        tNSMinfo)   //TNSMINFO

	MESSAGE( Ev_H323_RasCreateConf_Rsp )
	BODY( mt::TBytes,        tNSMinfo)   //TNSMINFO


	MESSAGE( Ev_H323_RasConfList_Req )
	BODY( mt::TBytes,        tNSMinfo)   //TNSMINFO

	MESSAGE( Ev_H323_RasConfList_Rsp )
	BODY( mt::TBytes,        tNSMinfo)   //TNSMINFO

	MESSAGE( Ev_H323_RasGKRegMtListInfo_Req )
	BODY( mt::TBytes,        tNSMinfo)   //TNSMINFO

	MESSAGE( Ev_H323_RasGKRegMtListInfo_Rsp )


	/* chan ��Ϣ*/
	//chan��ϢӦ����[Ev_H323_ChanBegin, Ev_H323_ChanEnd]
	MESSAGE( Ev_H323_ChanBegin)

	/*<< ������ͨ���������� >>
	* tHandle:  Э��ջ���
	* ��Ϣ���� ��stackin==>mth323service
	*/
	MESSAGE( Ev_H323_ChanIncomingNew_Ntf )
	BODY( mt::TH323StackHandle, tHandle )
	
	/*<< �´�������ͨ������ >>
	* tHandle:  Э��ջ���
	* ��Ϣ���� ��stackout<==mth323service
	*/
	MESSAGE( Ev_H323_ChanOutgoingNew_Cmd )
	BODY( mt::TH323StackHandle, tHandle )

	/*<< ������ͨ���������� >>
	* tHandle:  Э��ջ���
	* ��Ϣ���� ��stackout==>mth323service
	*/
	MESSAGE( Ev_H323_ChanOutgoingNew_Ntf )
	BODY( mt::TH323StackHandle, tHandle )

	/*<< ͨ������ >>
	* tHandle:  Э��ջ���
	* ��Ϣ���� ��stackout<==>mth323service
	*/
	MESSAGE( Ev_H323_ChanOpen_Req )
	BODY( mt::TH323StackHandle, tHandle )


	/*<< ͨ��Ӧ�� >>
	* tHandle:  Э��ջ���
	* ��Ϣ���� ��stackout<==>mth323service
	*/
	MESSAGE( Ev_H323_ChanOpenAck_Rsp )
	BODY( mt::TH323StackHandle, tHandle )

	/*<< ͨ��Ӧ��ܾ� >>
	* tHandle:  Э��ջ���
	* ��Ϣ���� ��stackout<==>mth323service
	*/
	MESSAGE( Ev_H323_ChanOpenReject_Rsp )
	BODY( mt::TH323StackHandle, tHandle )

	/*<< �ر�ͨ�� >>
	* tHandle:  Э��ջ���
	* ��Ϣ���� ��stackout<==>mth323service
	*/
	MESSAGE( Ev_H323_ChanClose_Cmd )
	BODY( mt::TH323StackHandle, tHandle )
	

	/*<< �������ͨ��״̬ >>
	* tHandle:  Э��ջ���
	* bActive:  ͨ��״̬
	* ��Ϣ���� ��stackout<==>mth323service
	*/
	MESSAGE( Ev_H323_ChanActive_Cmd )
	BODY( mt::TH323StackHandle, tHandle )
	BODY( mt::TBOOL32, bActive )

	/*<< ͼ��������� >>
	* tHandle:  Э��ջ���
	* ��Ϣ���� ��stackout<==>mth323service
	*/
	MESSAGE( Ev_H323_ChanVCU_Cmd )
	BODY( mt::TH323StackHandle, tHandle )

	/*<< ������������ >>
	* tHandle:  Э��ջ���
	* dwBitrate: ����
	* ��Ϣ���� ��stackout<==>mth323service
	*/
	MESSAGE( Ev_H323_ChanFlowCtrl_Cmd )
	BODY( mt::TH323StackHandle, tHandle )
	BODY( mt::TU16,           wBitrate )


	/*<< chan connected >>
	* tHandle:  Э��ջ���
	* ��Ϣ���� ��stackin==>mth323service
	*/
	MESSAGE( Ev_H323_ChanConnected_Ntf )
	BODY( mt::TH323StackHandle, tHandle )
	

	/*<< chan release>>
	* tHandle:  Э��ջ���
	* ��Ϣ���� ��stackin==>mth323service
	*/
	MESSAGE( Ev_H323_ChanRelease_Ntf )
	BODY( mt::TH323StackHandle, tHandle )


	/*<< ��ȡ��̬�غ� >>
	* tHandle:  Э��ջ���
	* ��Ϣ���� ��stackin==>mth323service
	*/
	MESSAGE( Ev_H323_ChanDynamicPayload_Ntf )
	BODY( mt::TH323StackHandle, tHandle )
	BODY( mt::TU8,           byDynamicPT)

	/*<<  ��ȡ����ͬ������ >>
	* tHandle:  Э��ջ���
	* ��Ϣ���� ��stackin==>mtH323service
	*/
	MESSAGE( Ev_H323_ChanEncryptSync_Ntf )
	BODY( mt::TH323StackHandle, tHandle )
	BODY( mt::TBytes,           tEncryptSync) //TEncryptSync

	/*<<  ��ȡ�߼�ͨ������ >>
	* tHandle:  Э��ջ���
	* ��Ϣ���� ��stackin==>mth323service
	*/
	MESSAGE( Ev_H323_ChanParam_Ntf)
	BODY( mt::TH323StackHandle, tHandle )
	BODY( mt::TBytes,           tEncryptSync) //TChanParam

	/*<< �õ��Զ�RTP��ַ     NETADDR >>
	* tHandle:  Э��ջ���
	* ��Ϣ���� ��stackin==>mth323service
	*/
	MESSAGE( Ev_H323_ChanSetRTPAddr_Ntf )
	BODY( mt::TH323StackHandle, tHandle )

	/*<< �õ��Զ�RTCP��ַ     NETADDR >>
	* tHandle:  Э��ջ���
	* ��Ϣ���� ��stackin==>mth323service
	*/
	MESSAGE( Ev_H323_ChanSetRTCPAddr_Ntf )
	BODY( mt::TH323StackHandle, tHandle )


	/*<< �õ�460�򶴵�ַ     NETADDR >>
	* tHandle:  Э��ջ���
	* ��Ϣ���� ��stackin==>mth323service
	*/
	MESSAGE( Ev_H323_ChanSetKeepAliveAddr_Ntf )
	BODY( mt::TH323StackHandle, tHandle )
	
	
	/*<< Զҡ���� >>*/
	MESSAGE( Ev_H323_ChanFecc_Cmd )
	BODY( mt::TH323StackHandle, tHandle )
	BODY( mt::TMtFeccMsg,  feccStruct )
	BODY( mt::TMtId  ,     tDstId )
	BODY( mt::TMtId  ,     tSrcId )

	MESSAGE(Ev_H323_ChanEnd)

	/*<< roundtrip���� >>
	* tHandle:  Э��ջ���
	* ��Ϣ���� ��stackout/stackin<==mth323service
	*/
	MESSAGE( Ev_H245_RoundTrip_Cmd )
	BODY( mt::TH323StackHandle, tHandle )
	BODY( mt::TU32,   dwroundtrip_delay)

	/*<< roundtrip�ظ� >>
	* tHandle:  Э��ջ���
	* ��Ϣ���� ��stackout/stackin==>mth323service
	*/
	MESSAGE( Ev_H245_RoundTrip_Ntf )
	BODY( mt::TH323StackHandle, tHandle )
	BODY( mt::TS32,   dwroundtrip_delay)

	/*<< 245������ >>
	* tHandle:  Э��ջ���
	* tcp_addr: ��ַ�����ֻ�����������ͨ��ʱ��д�ı��ص�ַ
	* ��Ϣ���� ��stackout/stackin==>mth323service
	*/
	MESSAGE( Ev_H245_TcpConnected_Ntf )
	BODY( mt::TH323StackHandle, tHandle )
	BODY( mt::TNetAddr,      tcp_addr)

	/*<< ���Ӿ������� >>
	* tHandle:  Э��ջ���
	* t_ramdom_value: ���Ӿ������ֵ
	* t_TerType:     �ն�����ֵ
	* ��Ϣ���� ��stackout/stackin==>mth323service
	*/
	MESSAGE( Ev_H245_MasterSlave_Cmd )
	BODY( mt::TH323StackHandle, tHandle )
	BODY( mt::TU32,        tTerType )
	BODY( mt::TU32,        tRamdom_value)


	/*<< ���Ӿ������ >>
	* tHandle:  Э��ջ���
	* tResult:  ���Ӿ������
	* ��Ϣ���� ��stackout/stackin==>mth323service
	*/
	MESSAGE( Ev_H245_MasterSlaveResult_Ntf )
	BODY( mt::TH323StackHandle, tHandle )
	BODY( mt::TU32,             tResult )
	
	/*<< ����ͨ����ģʽ >>
	* tHandle:  Э��ջ���
	* ��Ϣ���� ��stackout/stackin==>mth323service
	*/
	MESSAGE( Ev_H245_ChanEntryMode_Ntf )
	BODY( mt::TH323StackHandle, tHandle )
	
	/*<< ������ >>
	* tHandle:  Э��ջ���
	* ��Ϣ���� ��stackout/stackin<==>mth323service
	*/
	MESSAGE( Ev_H245_CapNotify_Cmd )
	BODY( mt::TH323StackHandle, tHandle )
    BODY( mt::TBytes, tCapset)	

	/*<< ������ͬ���ܾ� >>
	* tHandle:  Э��ջ���
	* bAccept:  �Ƿ�ͬ��
	* ��Ϣ���� ��stackout/stackin<==>mth323service
	*/
	MESSAGE( Ev_H245_CapCese_Cmd )
	BODY( mt::TH323StackHandle, tHandle )
	BODY( mt::TBOOL32,           bAccept)

	MESSAGE( Ev_H245_MccStart_Ntf )
	BODY( mt::TH323StackHandle, tHandle )

	/*<< �����ն��б� >>
	* tHandle:  Э��ջ���
	* ��Ϣ���� ��stackout<==mth323service
	*/
	MESSAGE( Ev_H245_TerList_Req )
	BODY( mt::TH323StackHandle, tHandle )

	/*<< �����ն��б� >>
	* tHandle:  Э��ջ���
	* terIdList: �б�list
	* ��Ϣ���� ��stackin==>mth323service
	*/
	MESSAGE( Ev_H245_TerList_Rsp)
	BODY( mt::TH323StackHandle, tHandle )
	BODY( mt::TBytes,        terIdList  )   //TTERLABEL

	
	/*<< �����ն��б� >>
	* tHandle:  Э��ջ���
	* ��Ϣ���� ��stackout<==mth323service
	*/
	MESSAGE( Ev_H245_OffLineTerList_Req )
	BODY( mt::TH323StackHandle, tHandle )

	/*<< �����ն��б� >>
	* tHandle:  Э��ջ���
	* terIdList: �б�list
	* ��Ϣ���� ��stackin==>mth323service
	*/
	MESSAGE( Ev_H245_OffLineTerList_Rsp)
	BODY( mt::TH323StackHandle, tHandle )
	BODY( mt::TBytes,        terIdList  )   //TTERLABEL


	/*<< mcu�����ն˱�� >>
	* tHandle:  Э��ջ���
	* terminalId:  �ն�id
	* ��Ϣ���� ��stackout/stackin<==>mth323service
	*/
	MESSAGE( Ev_H245_AssignTerId_Ntf)
	BODY( mt::TH323StackHandle, tHandle )
	BODY( mt::TBytes,       terminalId  )   //TTERLABEL


	MESSAGE( Ev_H239_Message_Cmd )
	BODY( mt::TH323StackHandle, tHandle )
	BODY( mt::TBytes,           t239Info)

	MESSAGE( Ev_H239_Message_Ntf )  
	BODY( mt::TH323StackHandle, tHandle )
	BODY( mt::TBytes,           t239Info)

	

	/*<< �ն�����ǰ�б������ն����� >>
	* tHandle:  Э��ջ���
	* ��Ϣ���� ��stackout<==mth323service
	*/
	MESSAGE( Ev_H245_TerGetAllTerName_Req )
	BODY( mt::TH323StackHandle, tHandle )

	/*<< mc�ظ���ǰ�б������ն����� >>
	* tHandle:  Э��ջ���
	* ��Ϣ���� ��stackout<==mth323service
	*/
	MESSAGE( Ev_H245_TerGetAllTerName_Rsp )
	BODY( mt::TH323StackHandle, tHandle )
	BODY( mt::TBytes,          pbyBuf)     //���TTERINFO tTerInfo

	/*<< mc����ǰ�ն����� >>
	* tHandle:  Э��ջ���
	* ��Ϣ���� ��stackin==>mth323service
	*/
	MESSAGE( Ev_H245_McGetTerName_Req )
	BODY( mt::TH323StackHandle, tHandle )

	/*<< �ն˻ظ�mc��ǰ������ >>
	* tHandle:  Э��ջ���
	* tbytes �����ն˵�����
	* ��Ϣ���� ��stackin==>mth323service
	*/
	MESSAGE( Ev_H245_McGetTerName_Rsp )
	BODY( mt::TH323StackHandle, tHandle )
	BODY( mt::TBytes,         tbytes)  //TTERINFO

	/*<< �ն�������һ���ն˵����� >>
	* tHandle:  Э��ջ���
	* tbytes �� TTERLABEL
	* ��Ϣ���� ��stackin==>mth323service
	*/
	MESSAGE(Ev_h245_TerGetOtherTerName_Req)
	BODY( mt::TH323StackHandle, tHandle )
	BODY( mt::TMtId,            tMtid)  

	/*<< mc��Ӧ ��һ���ն˵����� >>
	* tHandle:  Э��ջ���
	* tbytes �� TTERINFO
	* ��Ϣ���� ��stackin==>mth323service
	*/
	MESSAGE(Ev_h245_TerGetOtherTerName_Rsp)
	BODY( mt::TH323StackHandle, tHandle )
	BODY( mt::TBytes,            tbytes)  //TTERINFO


	/*<< �ն˼������ >>
	* tHandle:  Э��ջ���
	* tMtid �����ն�id
	* ��Ϣ���� ��stackin==>mth323service
	*/
	MESSAGE( Ev_H245_TerJoined_Ntf )
	BODY( mt::TH323StackHandle, tHandle )
	BODY( mt::TMtId,           tMtid)  //TTERLABEL


	/*<< �ն��뿪���� >>
	* tHandle:  Э��ջ���
	* tMtid �����ն�id
	* ��Ϣ���� ��stackin==>mth323service
	*/
	MESSAGE( Ev_H245_TerLeft_Ntf )
	BODY( mt::TH323StackHandle, tHandle )
	BODY( mt::TMtId,           tMtid)  //TTERLABEL


	/*<< ǿ���ն��˳� >>
	* tHandle:  Э��ջ���
	* tMtId �����ն�id
	* ��Ϣ���� ��stackout<==mth323service
	*/
	MESSAGE( Ev_H245_DropTer_Cmd )
	BODY( mt::TH323StackHandle, tHandle )
	BODY( mt::TMtId,            tMtid)  

	/*<< ǿ���ն��˳�ʧ�� >>
	* tHandle:  Э��ջ���
	*/
	MESSAGE( Ev_H245_DropTerReject_Ntf )
	BODY( mt::TH323StackHandle, tHandle )



	/*<< ǿ�ƽ������� >>
	* tHandle:  Э��ջ���
	*/
	MESSAGE( Ev_H245_EndConf_Cmd )
	BODY( mt::TH323StackHandle, tHandle )

	/*<<mc����������� >>
	* tHandle:  Э��ջ���
	*/
	MESSAGE( Ev_H245_Password_Req )
	BODY( mt::TH323StackHandle, tHandle )
	
	/*<<�ն˻ظ��������� >>
	* tHandle:  Э��ջ���
	* tbytes��  ��������
	*/
	MESSAGE( Ev_H245_Password_Rsp )
	BODY( mt::TH323StackHandle, tHandle )
	BODY( mt::TBytes,           tbytes)  //TPassRsp




	/*<< �ն����뷢�� mt<->mc>>
	*  �ն����룬mc�յ����붼�������Ϣ
	*/
	MESSAGE( Ev_H245_ApplyMcSpeak_Req )

	/*<< �ն����뷢�� mc->chair >>
	* note��  mcת��chair
	*/
	MESSAGE( Ev_H245_TerApplySpeak_Ntf )
	BODY( mt::TMtId,   tMtid)

	/*<< mc�ظ��Ƿ�ͬ�ⷢ�� mc->chair >>
	* bGranted: �Ƿ�ͬ��
	*/
	MESSAGE(Ev_H245_Broadcast_Rsp )
	BODY( mt::TBOOL32,   bGranted)

	/*<< ��ϯ����ָ������ chair -mc>>
	*/
	MESSAGE(Ev_H245_Broadcast_Req )
	BODY( mt::TMtId,   tMtid)

	/*<< ��ϯͬ�ⷢ��>>
	*/
	MESSAGE(Ev_H245_Broadcast_Cmd )
	BODY( mt::TMtId,   tMtid)

	/*<< ��ϯȡ������>>
	*/
	MESSAGE(Ev_H245_CancelBroadcast_Cmd )
	BODY( mt::TMtId,   tMtid)


	/*<< �㲥Դָʾmc<->mt >>
	*/
	MESSAGE(Ev_H245_SeenByAll_Ntf )


	/*<< ȡ���㲥Դָʾmc<->mt >>
	*/
	MESSAGE(Ev_H245_CancelSeenByAll_Ntf )

	/*<< ������λ��ָʾmc<->mt >>     ///�Ǳ��
	*/
	MESSAGE( Ev_h245_Speaker_Ntf )

	/*<< ��ƵԴmc<->mt >>
	*/
	MESSAGE( Ev_h245_YouAreSeeing_Ntf)
	

	/*<< �ն�������ϯ >>
	* tHandle:  Э��ջ���
	* ��Ϣ���� ��stackout<==mth323service
	*/
	MESSAGE( Ev_H245_MakeMeChair_Req )
	BODY( mt::TH323StackHandle, tHandle )

	/*<< �ն�������ϯӦ�� >>
	* tHandle:  Э��ջ���
	* tResult:  �Ƿ�ͬ��
	* ��Ϣ���� ��stackout<==mth323service
	*/
	MESSAGE( Ev_H245_MakeMeChair_Rsp )
	BODY( mt::TH323StackHandle, tHandle )
	BODY( mt::TBOOL32,          tResult )

	/*<< ������ϯ���� >>
	* tHandle:  Э��ջ���
	* ��Ϣ���� ��stackout<==mth323service
	*/
	MESSAGE( Ev_H245_WithdrawChair_Cmd )
	BODY( mt::TH323StackHandle, tHandle )

	/*<< ��ϯ����ָʾ >>
	*/
	MESSAGE( Ev_H245_WithdrawChair_Ntf )

	/*<< ���ն�������ϯ >>
	*/
	MESSAGE( Ev_H245_ChairApply_Ntf )
	

	/*<< �ն�����ǰ��ϯλ�� >>
	* tHandle:  Э��ջ���
	* ��Ϣ���� ��stackout<==mth323service
	*/
	MESSAGE( Ev_H245_WhoIsChair_Req )
	BODY( mt::TH323StackHandle, tHandle )

	/*<< mc�ظ���ǰ��ϯλ�� >>
	* tHandle:  Э��ջ���
	* ��Ϣ���� ��stackout<==mth323service
	*/
	MESSAGE( Ev_H245_Chair_Ntf )
	BODY( mt::TH323StackHandle, tHandle )
	BODY( mt::TBytes,          pbyBuf)     //TTERINFO tTerInfo

	/*<< ��ϯѡ�� >>*/
	MESSAGE( Ev_H245_SendThisTer_Cmd )
	BODY( mt::TH323StackHandle, tHandle )
	BODY( mt::TBytes,            pbyBuf)     //TTERLABEL

	/*<< ��ϯѡ��Ӧ�� >>*/
	MESSAGE( Ev_H245_SendThisTer_Rsp )
	BODY( mt::TH323StackHandle, tHandle )
	BODY( mt::TBOOL32,          bResult)     //bResult


	/*<< ��ϯȡ��ѡ�� >>*/
	MESSAGE( Ev_H245_CancelSendThisTer_Cmd )
	BODY( mt::TH323StackHandle, tHandle )

	/*<< ��ʾ��ѡ�� >>*/
	MESSAGE( Ev_H245_SeenByOther_Ntf )
	BODY( mt::TH323StackHandle, tHandle )

	/*<< ��ʾȡ����ѡ�� >>*/
	MESSAGE( Ev_H245_CancelSeenByOther_Ntf )
	BODY( mt::TH323StackHandle, tHandle )


	/////////////////////////////////////////�����ǷǱ��
	
	/*<< �ն�����廰mt->mc >>*/
	MESSAGE( Ev_H245_ChairTransfer_Req )
	BODY( mt::TH323StackHandle, tHandle )	
	

	/*<< �ն�����廰mt->mc >>*/
	MESSAGE( Ev_H245_ApplyChiemeIn_Req )
	BODY( mt::TH323StackHandle, tHandle )

	/*<< ���ն�����廰 mc->chair >>*/
	MESSAGE( Ev_H245_ApplyChimeIn_Ntf )
	BODY( mt::TH323StackHandle, tHandle )
	BODY( mt::TBytes,            tbytes)     //TTERLABEL


	/*<< ͬ��廰 chair->mc >>*/
	MESSAGE( Ev_H245_ChiemeIn_Cmd )
	BODY( mt::TH323StackHandle, tHandle )
	BODY( mt::TBytes,            tbytes)     //TTERLABEL

	/*<< �ն˲廰״̬ mc->ter >>*/
	MESSAGE( Ev_H245_ChimeInState_Ntf )
	BODY( mt::TH323StackHandle, tHandle )
	BODY( mt::TBytes,            tbytes)     //BOOL32

	/*<< �廰ʧ�� mc->ter >>*/
	MESSAGE( Ev_H245_ChimeFailed_Ntf )
	BODY( mt::TH323StackHandle, tHandle )


	/*<< �Ǳ���ϯѡ�� >>*/
	MESSAGE( Ev_H245_ChairView_Cmd )
	BODY( mt::TH323StackHandle, tHandle )
	BODY( mt::TBytes,            tbytes)     //TTERLABEL+mediaType
	
	/*<< �Ǳ���ϯѡ��ĳһ· >>*/
	MESSAGE( Ev_H245_ChairViewChan_Cmd )
	BODY( mt::TH323StackHandle, tHandle )
	BODY( mt::TBytes,            tbytes)     //

	/*<< �Ǳ���ϯȡ��ѡ��ĳһ· >>*/
	MESSAGE( Ev_H245_CancelChairViewChan_Cmd )
	BODY( mt::TH323StackHandle, tHandle )
	BODY( mt::TBytes,            tbytes)     //
	
	/*<< �Զ���ƵԴ������ʾ >>
	* tHandle:  Э��ջ���
	* alias:    �Զ�����
	* ��Ϣ���� ��stackout/stackin<==>mth323service
	*/
	MESSAGE( Ev_H245_PeerVideoAlias_Ntf )
	BODY( mt::TH323StackHandle, tHandle )
	BODY( mt::TBytes,           alias)

	/*<< �Զ�������ƵԴ���� >>
	* tHandle:  Э��ջ���
	* ��Ϣ���� ��stackout/stackin<==>mth323service
	*/
	MESSAGE( Ev_H245_VideoAlias_Req )
	BODY( mt::TH323StackHandle, tHandle )

	/*<< ��ƵԴ������Ӧ >>
	* tHandle:  Э��ջ���
	* ��Ϣ���� ��stackout/stackin<==>mth323service
	*/
	MESSAGE( Ev_H245_VideoAlias_Rsp )
	BODY( mt::TH323StackHandle, tHandle )
	

	/*<< ��ϯ����mc�Զ�������ƵԴ���� >>
	* tHandle:  Э��ջ���
	* ��Ϣ���� ��stackout/stackin<==>mth323service
	*/
	MESSAGE( Ev_H245_TerGetTerVideoAlias_Req )
	BODY( mt::TH323StackHandle, tHandle )

	/*<< mc�ظ���ϯ  >>
	* tHandle:  Э��ջ���
	* ��Ϣ���� ��stackout/stackin<==>mth323service
	*/
	MESSAGE( Ev_H245_TerGetTerVideoAlias_Rsp )
	BODY( mt::TH323StackHandle, tHandle )



	/*<< mc�����ն�״̬ >>
	* tHandle:  Э��ջ���
	* ��Ϣ���� ��stackout/stackin<==>mth323service
	*/
	MESSAGE( Ev_H245_McTerStatus_Req )
	BODY( mt::TH323StackHandle, tHandle )

	/*<< �ն�״̬��Ӧ >>
	* tHandle:  Э��ջ���
	* ��Ϣ���� ��stackout/stackin<==>mth323service
	*/
	MESSAGE( Ev_H245_McTerStatus_Rsp )
	BODY( mt::TH323StackHandle, tHandle )
	BODY( mt::TBytes,      tTerStatus)  //TTerStatus


	/*<< ��ϯ�����ն�״̬ >>
	*/
	MESSAGE( Ev_H245_TerGetTerStatus_Req )
	BODY( mt::TH323StackHandle, tHandle )
	BODY( mt::TBytes,      ter_id)  //TMtid
	
	/*<< mcӦ���ն�״̬ >>
	*/
	MESSAGE( Ev_H245_TerGetTerStatus_Rsp )
	BODY( mt::TH323StackHandle, tHandle )
	BODY( mt::TBytes,      ter_id)  //TMtid



	MESSAGE( Ev_H245_SMS_Ntf )
	BODY( mt::TH323StackHandle, tHandle )
	BODY( mt::TBytes,          pbyBuf)  

	/*<< ��ȡ������Ϣ���� >>
	*/
	MESSAGE( Ev_h245_ConfInfo_Req )

	/*<< ��ȡ������ϢӦ�� >>
	*/
	MESSAGE( Ev_h245_ConfInfo_Rsp )

	/*<< ��ȡ�򵥻�����Ϣ >>
	*/
	MESSAGE( Ev_h245_SimpleConfInfo_Ntf )

	/*<< �ն˴���֪ͨ >>
	*/
	MESSAGE( Ev_h245_terBandWidth_Ntf )

	/*���鼴������*/
	MESSAGE( Ev_h245_ConfWillEnd_Ntf )

	/*�����ӳ�����ʱ��*/
	MESSAGE( Ev_h245_ReqProlong_Req )

	/*Ӧ���ӳ�����ʱ��*/
	MESSAGE( Ev_h245_ReqProlong_Rsp )

	/*�����ն�*/
	MESSAGE( Ev_h245_ChairInviteTer_Req )
	
	/*�����ն�ʧ��*/
	MESSAGE( Ev_h245_ChairInviteFailed_Ntf )

	/*���鷢������*/
	MESSAGE( Ev_h245_ConfFailed_Ntf)

	/*���������ն�*/
	MESSAGE( Ev_h245_CallOfflineTer_Cmd)

	/*�޸Ļ�������*/
	MESSAGE( Ev_h245_ModifyConf_Req)

	/*�޸Ļ�������*/
	MESSAGE( Ev_h245_ModifyConf_Rsp)

	/*�Զ�����ָʾ*/
	MESSAGE( Ev_h245_PeerCapabilities_Ntf  )
	
	/*mcuָ֪ͨʾ*/
	MESSAGE( Ev_h245_McInfoTer_Ntf  )

	/*mcu�����ֱ���*/
	MESSAGE( Ev_h245_McAdjustRes_Ntf  )

	/*mcu����֡��*/
	MESSAGE( Ev_h245_McAdjustFps_Ntf  )

	/*mcu������һ·֡��*/
	MESSAGE( Ev_h245_McAdjustMainVideoFps_Ntf  )

	////////////����ϳɣ� ����

	/*<< ��ʼ�������� >>
	* ��Ϣ���� �� sdk==>dispatch==>conf
	*/
	MESSAGE( Ev_h245_StartVAC_Req )

	/*<< ��ʼ��������Ӧ�� >>
	*/
	MESSAGE( Ev_h245_StartVACResult_Ntf )



	/*<< ֹͣ�������� >>
	*/
	MESSAGE( Ev_h245_StopVAC_Req )

	/*<< ֹͣ����������� >>
	*/
	MESSAGE( Ev_h245_StopVACResult_Ntf )


	/*<< ��ʼ����ģʽ���� >>
	*/
	MESSAGE( Ev_h245_StartMix_Req )

	/*<< ��ʼ����ģʽ��� >>
	*/
	MESSAGE( Ev_h245_StartMixResult_Ntf )
	

	/*<< ֹͣ����ģʽ���� >>
	*/
	MESSAGE( Ev_h245_StopMix_Req )

	/*<< ֹͣ����ģʽ��� >>
	*/
	MESSAGE( Ev_h245_StopMixResult_Ntf )

	/*<< ��ʼ�Զ��໭��ϳ����� >>
	*/
	MESSAGE( Ev_h245_StartVMP_Req)

	/*<< ��ʼ�Զ��໭��ϳ�Ӧ�� >>
	*/
	MESSAGE( Ev_h245_StartVMPResult_Ntf )

	/*<< ��ʼ�Զ��໭��ϳ�Ӧ�� >>
	*/
	MESSAGE( Ev_h245_StartVMPResult_Rsp )


	/*<< ֹͣ�Զ��໭��ϳ����� >>
	*/
	MESSAGE( Ev_h245_StopVMP_Req)

	
	/*<< ֹͣ�Զ��໭��ϳ�Ӧ�� >>
	*/
	MESSAGE( Ev_h245_StopVMPResult_Ntf)

	/*<< ֹͣ�Զ��໭��ϳ�Ӧ�� >>
	*/
	MESSAGE( Ev_h245_StopVMPResult_Rsp )

	/*<< ���û���ϳɲ��� >>
	*/
	MESSAGE( Ev_h245_SetVMPParam_Req )     //ֻ��Կƴ��ն�

	/*<< ���û���ϳɲ���Ӧ�� >>
	*/
	MESSAGE( Ev_h245_SetVMPParamResult_Ntf)

	/*<< ���û���ϳɲ���Ӧ�� >>
	*/
	MESSAGE( Ev_h245_SetVMPParamResult_Rsp)

	/*<< ��ȡ����ϳɲ��� >>
	*/
	MESSAGE( Ev_h245_GetVMPParam_Cmd )

	/*<< ��ȡ����ϳɲ�����Ӧ >>
	*/
	MESSAGE( Ev_h245_GetVMPParamResult_Rsp )

	/*<< ������Ա֪ͨ >>
	*/
	MESSAGE( Ev_h245_DiscussParam_Ntf )

	/*<< �Ƴ�������Ա >>
	*/
	MESSAGE( Ev_h245_RemoveTerChimeIn_Cmd )
	
	/*<< ����cmd >>
	*/
	MESSAGE( Ev_h245_MakeTerMute_Cmd )
	
	/*<< ����cmd >>
	*/
	MESSAGE( Ev_h245_MakeTerQuiet_Cmd )


	/*<< �л�����ϳɷ�� >>
	* is_multipic:  �Ƿ�໭
	*/
	MESSAGE( Ev_h245_SwitchBroadCastStyle_Cmd )
	BODY(mt::TBOOL32, is_multipic)


	/*<< ����Է��Ƿ�ͬ��ǿ�� >>
	* body ��û��
	*/
	MESSAGE( Ev_h245_mtAskOccupyPermit_Req )

	/*<< �Է��ظ��Ƿ�ͬ��ǿ�� >>
	* body ��û��
	*/
	MESSAGE( Ev_h245_mtAskOccupyPermit_Rsp )
	
	/*<< ƽ̨�����鲥��ַ >>
	* TCHANMULTICAST �鲥��ַ
	*/
	MESSAGE( Ev_h245_SetChanMultiCastAddr_Cmd )
	BODY( TCHANMULTICAST, tChanAddr)

	/*
	�նˣ�������ϯMT��ѡ������ϳ�����
	*/
	MESSAGE( Ev_h245_mtSelectVmp_Req )
	BODY( mt::TBOOL32,  bStart)
	/*
	�նˣ�������ϯMT��ѡ������ϳ�����
	*/
	MESSAGE( Ev_h245_mtSelectVmp_Rsp )
	BODY( mt::TBOOL32,  bResult)

	/*
	��ϯ�ն�ǿ�ƿ�ʼ�㲥
	*/
	MESSAGE( Ev_h245_ForceBroadcast_Cmd )

	/*
	 �Ǳ������ն���Ϣ
	*/
	MESSAGE( Ev_H245_GetTerminalInfo_Cmd )

	/*
	 �Ǳ��ն���ϢӦ��
	*/
	MESSAGE( Ev_H245_GetTerminalInfo_Ntf )

	
	/*mcu�����ն˷�˫��*/
	MESSAGE( Ev_H245_McReqTerSendAss_Cmd)

	/*����ָʾ*/
	MESSAGE( Ev_H245_FlowCtrlIndition_Cmd)

	/*��ʼ����*/
	MESSAGE( Ev_h323_StartLoopBackTest_Req )

	/*ֹͣ����*/
	MESSAGE( Ev_h323_StopLoopBackTest_Req )

	MESSAGE( Ev_H323_LoopBackStatus_Ntf )

	////�����ӳ�
	MESSAGE( Ev_H245_ConfDelay_Ntf)

	///confinfo֪ͨ
	MESSAGE( Ev_H245_confInfo_Ntf )


	////////////////////5.0�����ģ���������ϳ����
	/////������������ϳɣ�����
	MESSAGE( Ev_H245_StartMtVmp_Req )

	/////������������ϳɻظ�
	MESSAGE( Ev_H245_StartMtVmp_Rsp )

	/////������������ϳ�֪ͨ
	MESSAGE( Ev_H245_StartMtVmp_Ntf )


	/////ֹͣ����ϳ�
	MESSAGE( Ev_H245_StopMtVmp_Req )

	/////ֹͣ��������ϳ�
	MESSAGE( Ev_H245_StopMtVmp_Rsp )

	/////ֹͣ��������ϳ�
	MESSAGE( Ev_H245_StopMtVmp_Ntf )


	/////�ı���������ϳ�
	MESSAGE( Ev_H245_ChangeMtVmp_Req )

	/////�ı���������ϳ�
	MESSAGE( Ev_H245_ChangeMtVmp_Rsp )

	/////�ı���������ϳ�
	MESSAGE( Ev_H245_ChangeMtVmp_Ntf )


	/*<<��ϯָ��vip�б� chair->mc >>
	* mt_id :  ָ���ն˵��б�
	* ��Ϣ���� ��sdk==>dispatch==>conf
	*/ 
	MESSAGE( Ev_H245_ChairSpecVip_Req ) //�Ǳ�
	
	/*<<mc��Ӧ��ϯָ��vip�б� chair<-mc >>
	* mt_id :  ָ���ն˵��б�
	* ��Ϣ���� ��sdk==>dispatch==>conf
	*/ 
	MESSAGE( Ev_H245_McRspChairVip_Rsp ) //�Ǳ�

	/*<<mc֪ͨ�ն˵�ǰvip�б� ter<-mc >>
	* mt_id :  ָ���ն˵��б�
	* ��Ϣ���� ��sdk==>dispatch==>conf
	*/ 
	MESSAGE( Ev_H245_McInfoTerVip_Ntf ) //�Ǳ�

	/////�װ���鴴��֪ͨ
	MESSAGE( Ev_H245_DataConfCreatedNtf_Cmd )
	BODY(mt::TString, conf_name) //�װ��������

	///����װ�������� ���ڵ�Ե�
	MESSAGE( Ev_H245_JoinDataConf_Cmd )
	BODY(mt::TString, conf_name) //�װ��������

	///�յ��Զ˵ļ���װ�������� ����mcu, ���߶Զ�
	MESSAGE( Ev_H245_JoinDataConf_Ntf )
	BODY(mt::TString, conf_name)  //�װ��������

    //��ϯָ���ն˷�˫��
    MESSAGE( Ev_H245_ChairSpecTerSendAss_Cmd )
    BODY(mt::TMtId, tMtId)

	//�ն�֪ͨƽ̨ͨ�����
	MESSAGE( Ev_H245_NotifyPeerLocAlias_Cmd )

	//fecc streamid 
	MESSAGE( Ev_H245_FeccStreamId_Cmd )

	////����dtmf����
	MESSAGE(Ev_H245_PasswordDtmf_Cmd)
	BODY(mt::TBytes, tDtmfPwd)

	///mc��������
	MESSAGE(Ev_H245_McSetAudioVolume_Cmd)
	BODY(mt::TBytes, tvol)


	///mc�����ն˵Ķ�����
	MESSAGE(Ev_H245_McReqTerLossRate_Req )


	///�ն˻ظ�mc �ն˵Ķ�����
	MESSAGE(Ev_H245_McReqTerLossRate_Rsp )
	BODY(mt::TBytes, tRsp)


	///fecc ��
	MESSAGE( Ev_H245_FeccHole_Cmd  )
    BODY(mt::TBytes, tvol)

	///�ն�������Ʒ��Ϣ֪ͨ
	MESSAGE( Ev_h245_MtAgentInfo_Ntf )

	///�Զ�������Ʒ��Ϣ֪ͨ
	MESSAGE( Ev_H245_PeerAgentInfo_Ntf )

	///mc�����ն�ʵʱ��Ϣ
	MESSAGE( Ev_H245_McGetMtRealtimeInfo_Cmd )
	BODY(mt::TBytes, tInfoType)

	//ƽ̨������֪ͨ�� 0-˽���� 1-������ 2-�����
	MESSAGE( Ev_H245_McuCloudType_Ntf )
	BODY(mt::TU32, dwCloudType)

#if !defined(_MESSAGE_HELP_)
	EV_END(H323) = EVSEG_H323_END
};
#endif

#define Is_MtH323_Msg(m) ((m) >= EV_BGN(H323) && (m) <= EV_END(H323))

#endif  //_H323MSG_H_
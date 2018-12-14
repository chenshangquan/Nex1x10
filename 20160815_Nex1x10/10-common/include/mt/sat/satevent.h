      /*****************************************************************************
   ģ����      : MT Core
   �ļ���      : MtEvent.h
   ����ļ�    : 
   �ļ�ʵ�ֹ���: �ն���Ϣ�ڲ�����
   ����        : �ƺ���
   �汾        : V3.0  Copyright(C); 2003 KDC, All rights reserved.
-----------------------------------------------------------------------------
   �޸ļ�¼:
   ��  ��      �汾        �޸���      �޸�����
   2003/08/16  3.0         �ƺ���      ����
   2003/08/20  3.0         �˻�		   ������Ϣ
******************************************************************************/
#ifndef _MTCORE_EVENT_DEF_H
#define _MTCORE_EVENT_DEF_H

#include "eventid.h"

//ҵ����Ϣ����
enum  MsgType 
{
	MT_SYS = 1,
	MT_INNER,
	MT_OUTER,
};

//ҵ������Ϣ����
enum MsgSubType 
{
	//�ڲ���Ϣ�ӿ�����
	INNER_CALL = 1,
	INNER_CHAN,
	INNER_CTRL,
	INNER_RAS,
	INNER_MISC,
	INNER_MC,
	INNER_SAT,

	//�ⲿ��Ϣ�ӿ�����
	OUTER_CONFCTRL,
	OUTER_MATRIX,
	OUTER_CAMERA,
	OUTER_CODEC,
	OUTER_CFG,
	OUTER_MISC,
	OUTER_VXUI,
	OUTER_WINUI
};

//ϵͳ��Ϣ�߽綨��
#define EV_MTSYS_BGN		EV_MT_BGN					//(29001)
#define EV_MTSYS_END		( EV_MTSYS_BGN + 50 ) 		//(29051)

//�ڲ���Ϣ�߽綨��
#define EV_INNER_BGN		EV_MTSYS_END				//(29051)
#define EV_INNER_END		( EV_INNER_BGN + 600 )		//(29551)

#define INNER_CALL_ENTRY	EV_INNER_BGN
#define INNER_CHAN_ENTRY	( INNER_CALL_ENTRY + 20 )	//(29071)
#define INNER_CTRL_ENTRY	( INNER_CHAN_ENTRY + 40 )	//(29111)
#define INNER_RAS_ENTRY		( INNER_CTRL_ENTRY + 150 )	//(29261)
#define INNER_MISC_ENTRY	( INNER_RAS_ENTRY  + 40 )	// 29301
#define INNER_MC_ENTRY		( INNER_MISC_ENTRY + 50 )	// 29351
#define INNER_SAT_ENTRY		( INNER_MC_ENTRY + 50 )		// 29401

//�ⲿ��Ϣ�߽綨��
#define EV_OUTER_BGN		EV_INNER_END				//(29451)
#define EV_OUTER_END		( EV_OUTER_BGN + 500 )		//(29951)

#define OUTER_CONF_ENTRY	EV_OUTER_BGN				// 29451
#define OUTER_MATR_ENTRY	( OUTER_CONF_ENTRY + 150 )	// 29601
#define OUTER_CAM_ENTRY		( OUTER_MATR_ENTRY + 30 )	// 29631
#define OUTER_CODEC_ENTRY	( OUTER_CAM_ENTRY  + 20 )	// 29651
#define OUTER_CFG_ENTRY		( OUTER_CODEC_ENTRY + 80 )	// 29731
#define OUTER_MISC_ENTRY	( OUTER_CFG_ENTRY  + 80 )	// 29811
#define OUTER_VXUI_ENTRY	( OUTER_MISC_ENTRY + 50 )	// 29861
#define OUTER_WINUI_ENTRY	( OUTER_VXUI_ENTRY + 50 )	// 29911

//��ʱ����Ϣ�߽綨��
#define EV_TIMER_BGN		EV_OUTER_END		        //29951
#define EV_TIMER_END		( EV_TIMER_BGN + 30 )       //29981

// ����ֱ��OSP��Ϣ����
#define EV_OUTEROSP_BGN		EV_TIMER_END                
#define EV_OUTEROSP_END		( EV_OUTEROSP_BGN + 50 )



//==========================================================================================
//									ϵͳ��Ϣ����
//==========================================================================================

// Ӧ�ö����ʼ����Ϣ(����RAS,��ҪӦ�þ������)
OSPEVENT (EV_SYS_INIT_CMD			, EV_MTSYS_BGN + 1);
// Ӧ�ö����ʼ�����ָʾ		| 1BYTE,MT_OK|MT_ERR
OSPEVENT (EV_SYS_INITRET_IND		, EV_MTSYS_BGN + 2);
// �ն���������					| NULL
OSPEVENT (EV_SYS_REBOOT_CMD			, EV_MTSYS_BGN + 3);
// ����UIע��ָʾ				| u32(vxWorks:app id,windows:window handle)
OSPEVENT (EV_SYS_UIREG_IND			, EV_MTSYS_BGN + 4);
// �տ�����ָʾ					| u32 nodeid + u32 insid
OSPEVENT (EV_SYS_MTCLOG_IND			, EV_MTSYS_BGN + 5);


// ����������					| NULL
OSPEVENT( EV_SYS_TASKALIVE_REQ		, EV_MTSYS_BGN + 26);
// ������Ӧ��					| NULL
OSPEVENT( EV_SYS_TASKALIVE_RSP		, EV_MTSYS_BGN + 27);

// E1��·״̬�ı�				| CDevStatus				| MT->AGENT
OSPEVENT( EV_AGT_E1LINE_IND		, EV_MTSYS_BGN + 31 );
// �ڴ�״̬�ı䣬				| 1BYTE(MT_OK:���� MT_ERR:�쳣)		| MT->AGENT
OSPEVENT( EV_AGT_MEMORY_IND		, EV_MTSYS_BGN + 32 );
// �ļ�ϵͳ״̬�ı�				| 1BYTE(MT_OK:���� MT_ERR:�쳣)		| MT->AGENT
OSPEVENT( EV_AGT_FILESYSTEM_IND	, EV_MTSYS_BGN + 33 );
// ����״̬�ı�					| CTaskStatus				| MT->AGENT
OSPEVENT( EV_AGT_TASK_IND		, EV_MTSYS_BGN + 34 );
// MAP״̬�ı�					| CMapStatus				| MT->AGENT
OSPEVENT( EV_AGT_MAP_IND		, EV_MTSYS_BGN + 35 );
// CCI״̬�ı�					| CCCIStatus				| MT->AGENT
OSPEVENT( EV_AGT_CCI_IND		, EV_MTSYS_BGN + 36 );
// ��̫��״̬					| CEthernetCardStatus		| MT->AGENT
OSPEVENT( EV_AGT_ETHERNET_IND	, EV_MTSYS_BGN + 37 );
// ý����״̬					| CMediaStreamStatus		| MT->AGENT
OSPEVENT( EV_AGT_MEDIASTREAM_IND, EV_MTSYS_BGN + 38 );
// �豸����״̬�ı�				| CEqpConnStatus			| MT->AGENT
OSPEVENT( EV_AGT_EQPCONNECT_IND	, EV_MTSYS_BGN + 39 );
// ��Ƶ�����״̬				| 1BYTE(MT_OK:���� MT_ERR:�쳣)		| MT->AGENT
OSPEVENT( EV_AGT_VIDEOSOURCE_IND, EV_MTSYS_BGN + 40 );
// ����״̬�ı�					| CFanStatus				| MT->AGENT
OSPEVENT( EV_AGT_FAN_IND		, EV_MTSYS_BGN + 41 );
// V35״̬�ı�					| 1BYTE(MT_OK: ����			| MT->AGENT
// MT_ERR:�쳣(bit0�ز����ʧ�� bit1�������ʧ��, bit2������ʧ��,bit3�����ն�δ����,bit4����δ׼����)
OSPEVENT( EV_AGT_V35_IND		, EV_MTSYS_BGN + 42 );

//����״̬֪ͨ                |TBrdMTLedStateDesc         | MT->AGENT
OSPEVENT( EV_AGT_PANELLED_IND		, EV_MTSYS_BGN + 43 );
//��·����֪ͨ                |4�ֽ�(����)         | guard->mt
OSPEVENT( EV_GUARD_CHANBW_IND		, EV_MTSYS_BGN + 44 );

// ���ɲ��Բ�ѯ��Ϣ				| 1BYTE						|
OSPEVENT( EV_SYS_INTTEST_CMD		, EV_MTSYS_BGN + 46 );


//==========================================================================================
//									�ڲ���Ϣ����
//==========================================================================================

//////////////////////////// ������Ϣ //////////////////////////////

// �º��о��֪ͨ			| NULL
OSPEVENT (EV_CALL_NEW_IND				 , INNER_CALL_ENTRY + 1);		
// �������					| TCALLPARAM
OSPEVENT (EV_CALL_MAKE_CMD				 , INNER_CALL_ENTRY + 2);		
// FACILITY					| TFACILITYINFO
OSPEVENT (EV_CALL_FACILITY_CMD			 , INNER_CALL_ENTRY + 3);		
// �ҶϺ���					| NULL
OSPEVENT (EV_CALL_HANGUP_CMD			 , INNER_CALL_ENTRY + 4);		
// ���е���					| TCALLPARAM
OSPEVENT (EV_CALL_INCOMING_IND			 , INNER_CALL_ENTRY + 5);		
// ���н���					| TNODEINFO
OSPEVENT (EV_CALL_CONNECTED_IND			 , INNER_CALL_ENTRY + 6);		
// ���жϿ�					| 1BYTE,�Ͽ�ԭ��
OSPEVENT (EV_CALL_DISCONNECTED_IND		 , INNER_CALL_ENTRY + 7);		
// ����Ӧ��					| TNODEINFO
OSPEVENT (EV_CALL_ANSWER_CMD			 , INNER_CALL_ENTRY + 8);

// �����ڲ�������Ϣ(MT->MC)	| NULL
OSPEVENT (EV_CALL_PASSINFO_IND			 , INNER_CALL_ENTRY + 11);


//////////////////////////// �ŵ���Ϣ //////////////////////////////

// ����ͨ��ģʽ				| NULL
OSPEVENT (EV_CHAN_ENTRYMODE_IND			 , INNER_CHAN_ENTRY + 1);		
// ���ŵ����				| NULL
OSPEVENT (EV_CHAN_INCOMINGNEW_IND		 , INNER_CHAN_ENTRY + 2);
// ���ŵ����				| TCHANPARAM
OSPEVENT (EV_CHAN_OUTGOINGNEW_IND		 , INNER_CHAN_ENTRY + 3);
// ���߼�ͨ������			| TCHANPARAM(Outgoing) | NULL(Incoming)
OSPEVENT (EV_CHAN_OPEN_REQ				 , INNER_CHAN_ENTRY + 4);
// ���߼�ͨ��Ӧ��			| TCHANPARAM
OSPEVENT (EV_CHAN_OPEN_RSP		  		 , INNER_CHAN_ENTRY + 5);
// �߼�ͨ���Ѿ���			| NULL
OSPEVENT (EV_CHAN_CONNECTED_IND			 , INNER_CHAN_ENTRY + 6);
// �ر��߼�ͨ������			| NULL
OSPEVENT (EV_CHAN_CLOSE_CMD				 , INNER_CHAN_ENTRY + 7);	
// �ͷ��߼�ͨ��ָʾ			| NULL
OSPEVENT (EV_CHAN_RELEASE_IND			 , INNER_CHAN_ENTRY + 8);	
// �ͷ��߼�ͨ������			| NULL
OSPEVENT (EV_CHAN_RELEASE_CMD			 , INNER_CHAN_ENTRY + 9);
// ����RTP��ַ				| TNETADDR
OSPEVENT (EV_CHAN_SETRTPADDR_IND		 , INNER_CHAN_ENTRY + 10);
// ����RTCP��ַ				| TNETADDR
OSPEVENT (EV_CHAN_SETRTCPADDR_IND		 , INNER_CHAN_ENTRY + 11);
// �߼�ͨ������ָʾ			| TCHANPARAM
OSPEVENT (EV_CHAN_PARAM_IND				 , INNER_CHAN_ENTRY + 12);
// ͼ�񶳽�����				| NULL
OSPEVENT (EV_CHAN_VCF_CMD				 , INNER_CHAN_ENTRY + 13);
// ͼ���������				| NULL
OSPEVENT (EV_CHAN_VCU_CMD				 , INNER_CHAN_ENTRY + 14);
// ������������				| BitRate(u16):kbps
OSPEVENT (EV_CHAN_FLOWCTRL_CMD			 , INNER_CHAN_ENTRY + 15);


//////////////////////////// ���������Ϣ //////////////////////////////

// h.245���ӽ���			| NULL
OSPEVENT (EV_CTRL_H245CONNECT_IND		 , INNER_CTRL_ENTRY + 1);
// ��������֪ͨ				| TCAP
OSPEVENT (EV_CTRL_CAPNOTIFY_IND			 , INNER_CTRL_ENTRY + 2);
// ��������Ӧ��				| 1BYTE,CapExchangeResult
OSPEVENT (EV_CTRL_CESE_RSP				 , INNER_CTRL_ENTRY + 3);
// ���Ӿ�����ʼ����			| terminalType(u32)+random number(u32)
OSPEVENT (EV_CTRL_MASTERSLAVE_CMD		 , INNER_CTRL_ENTRY + 4);
// ���Ӿ������ָʾ			| 1BYTE,MasterSlaveResult
OSPEVENT (EV_CTRL_MASTERSLAVE_IND		 , INNER_CTRL_ENTRY + 5);
// ����MC
OSPEVENT (EV_CTRL_MCACTIVE_IND			 , INNER_CTRL_ENTRY + 6);
// MCUҪ�������������		| NULL			mc->ter
OSPEVENT (EV_CTRL_H243PWD_REQ			 , INNER_CTRL_ENTRY + 7);
// MT�ش��������			| TTERLABEL + 1BYTE,password length (<= LEN_H243PWD) + password(char*)
OSPEVENT (EV_CTRL_H243PWD_RSP			 , INNER_CTRL_ENTRY + 8);

// ��ʼ������				| NULL
OSPEVENT (EV_CTRL_MCCSTART_CMD			 , INNER_CTRL_ENTRY + 10);
// ͨѶģʽ����				| TCOMMODEINFO
OSPEVENT (EV_CTRL_COMMODE_CMD			 , INNER_CTRL_ENTRY + 11);
// ����ͨѶģʽ				| NULL
OSPEVENT (EV_CTRL_COMMODE_REQ			 , INNER_CTRL_ENTRY + 12);
// �ش�ͨѶģʽ				| TCOMMODEINFO
OSPEVENT (EV_CTRL_COMMODE_RSP			 , INNER_CTRL_ENTRY + 13);
// MC��ַָʾ				| TNETADDR
OSPEVENT (EV_CTRL_MCLOCATION_IND		 , INNER_CTRL_ENTRY + 14);


// �����ն˱��				| TTERLABEL
OSPEVENT (EV_CTRL_ASSIGNTERNO_IND		 , INNER_CTRL_ENTRY + 16);
// �����ն��б�				| NULL
OSPEVENT (EV_CTRL_TERLIST_REQ			 , INNER_CTRL_ENTRY + 17);
// �ն��б�Ӧ��				| TTERLABEL����
OSPEVENT (EV_CTRL_TERLIST_RSP			 , INNER_CTRL_ENTRY + 18);
// MCҪ���ն���������		| NULL
OSPEVENT (EV_CTRL_ENTERNAME_REQ			 , INNER_CTRL_ENTRY + 19);
// �ն˻ش�MC����			| TTERINFO
OSPEVENT (EV_CTRL_ENTERNAME_RSP			 , INNER_CTRL_ENTRY + 20);
// �ն����������ն�����		| TTERLABEL
OSPEVENT (EV_CTRL_TERNAME_REQ			 , INNER_CTRL_ENTRY + 21);
// MC�ش������ն�����		| TTERINFO
OSPEVENT (EV_CTRL_TERNAME_RSP			 , INNER_CTRL_ENTRY + 22);
// �ն����������ն�����		| NULL
OSPEVENT (EV_CTRL_ALLNAME_REQ			 , INNER_CTRL_ENTRY + 23);
// MC�ش������ն�����		| TTERINFO����
OSPEVENT (EV_CTRL_ALLNAME_RSP			 , INNER_CTRL_ENTRY + 24);
// �ն˼������				| TTERLABEL
OSPEVENT (EV_CTRL_TERJOINED_IND			 , INNER_CTRL_ENTRY + 31);
// �ն��˳�����				| TTERLABEL
OSPEVENT (EV_CTRL_TERLEFT_IND			 , INNER_CTRL_ENTRY + 32);
// ���������ն�				| TTERLABEL
OSPEVENT (EV_CTRL_DROPTER_REQ			 , INNER_CTRL_ENTRY + 33);
//	�����ն�ʧ��ָʾ		| NULL
OSPEVENT (EV_CTRL_DROPTERREJECT_IND		 , INNER_CTRL_ENTRY + 34);

// ���˱�ѡ��				| NULL				| mc->ter
OSPEVENT (EV_CTRL_SEENBYOTHER_IND		 , INNER_CTRL_ENTRY + 36);
// ���˱�ȡ��ѡ��			| NULL				| mc->ter
OSPEVENT (EV_CTRL_CANCELSEENBYOTHER_IND	 , INNER_CTRL_ENTRY + 37);

// �㲥�ն�����				| TTERLABEL			| ter->mc
OSPEVENT (EV_CTRL_BROADCAST_CMD			 , INNER_CTRL_ENTRY + 41);
// �㲥�ն�����				| TTERLABEL			| ter->mc
OSPEVENT (EV_CTRL_BROADCAST_REQ			 , INNER_CTRL_ENTRY + 42);
// �㲥�ն�Ӧ��				| 1BYTE,CtrlResult
OSPEVENT (EV_CTRL_BROADCAST_RSP			 , INNER_CTRL_ENTRY + 43);
// ȡ���㲥�ն�����			| NULL
OSPEVENT (EV_CTRL_CANCELBROADCAST_CMD	 , INNER_CTRL_ENTRY + 44);

// ѡ���ն�����				| TTERLABEL
OSPEVENT (EV_CTRL_SENDTHISTER_CMD		 , INNER_CTRL_ENTRY + 46);
// ѡ���ն�����				| TTERLABEL
OSPEVENT (EV_CTRL_SENDTHISTER_REQ		 , INNER_CTRL_ENTRY + 47);
// ѡ���ն�Ӧ��				| 1BYTE,CtrlResult
OSPEVENT (EV_CTRL_SENDTHISTER_RSP		 , INNER_CTRL_ENTRY + 48);
// ȡ��ѡ���ն�����			| NULL
OSPEVENT (EV_CTRL_CANCELSENDTHISTER_CMD  , INNER_CTRL_ENTRY + 49);
// ��ϯѡ���ն�				| TTERLABEL + 1Byte(type_audio|type_video|type_av)
OSPEVENT (EV_CTRL_CHAIRVIEW_CMD			 , INNER_CTRL_ENTRY + 50);

// ���㲥ָʾ				| NULL
OSPEVENT (EV_CTRL_SEENBYALL_IND			 , INNER_CTRL_ENTRY + 51);	
// ȡ�����㲥ָʾ			| NULL
OSPEVENT (EV_CTRL_CANCELSEENBYALL_IND	 , INNER_CTRL_ENTRY + 52);
// ��ƵԴָʾ				| TTERLABEL
OSPEVENT (EV_CTRL_YOUARESEEING_IND		 , INNER_CTRL_ENTRY + 53);

// ���뷢������				| NULL
OSPEVENT (EV_CTRL_APPLYSPEAK_REQ		 , INNER_CTRL_ENTRY + 56);
// ���뷢��ָʾ				| TTERLABEL
OSPEVENT (EV_CTRL_APPLYSPEAK_IND		 , INNER_CTRL_ENTRY + 57);

// ��ϯ��������				| 1BYTE,CTRL_CHAIR_GRAB/CTRL_CHAIR_RELEASE
OSPEVENT (EV_CTRL_CHAIRTOKEN_REQ		 , INNER_CTRL_ENTRY + 58);
// ��ϯ����Ӧ��				| 1BYTE,
OSPEVENT (EV_CTRL_CHAIRTOKEN_RSP		 , INNER_CTRL_ENTRY + 59);
// ѯ��˭����ϯ				| NULL
OSPEVENT (EV_CTRL_WHOISCHAIR_REQ		 , INNER_CTRL_ENTRY + 60);
// �ش�˭����ϯ				| TTERLABEL
OSPEVENT (EV_CTRL_WHOISCHAIR_RSP		 , INNER_CTRL_ENTRY + 61);
// ������ϯָʾ				| NULL
OSPEVENT (EV_CTRL_WITHDRAWCHAIR_IND		 , INNER_CTRL_ENTRY + 62);
// ������ָʾ				| TTERLABEL
OSPEVENT (EV_CTRL_SPEAKER_IND			 , INNER_CTRL_ENTRY + 63);

// ������������				| NULL
OSPEVENT (EV_CTRL_DROPCONF_CMD			 , INNER_CTRL_ENTRY + 66);	
// ���Զ��Ƿ�Alive		| INT(���ʱ��ֵ,��λ:ms)
OSPEVENT (EV_CTRL_CHECKPEERALIVE_IND	 , INNER_CTRL_ENTRY + 71);	

///// �Զ�����Ϣ /////

// �����ն�������ϯ			| TTERLABEL
OSPEVENT (EV_CTRL_CHAIRAPPLY_IND		 , INNER_CTRL_ENTRY + 81);
// ��ϯ����ת��				| TTERLABEL
OSPEVENT (EV_CTRL_CHAIRTRANSFER_REQ		 , INNER_CTRL_ENTRY + 82);
// ��ϯ�����ն��������		| u32(IP)/E164����
OSPEVENT (EV_CTRL_CHAIRINVITE_REQ		 , INNER_CTRL_ENTRY + 83);
// ��ϯ�����ն����ʧ��		| u32(IP)
OSPEVENT (EV_CTRL_INVITEFAIL_IND		 , INNER_CTRL_ENTRY + 84);
// Զ�˾�������				| TTERLABEL(dst) + 1BYTE(turn_on/turn_off)
OSPEVENT (EV_CTRL_MAKETERQUIET_CMD		 , INNER_CTRL_ENTRY + 85);
// Զ����������				| TTERLABEL(dst) + 1BYTE(turn_on/turn_off)
OSPEVENT (EV_CTRL_MAKETERMUTE_CMD		 , INNER_CTRL_ENTRY + 86);
// ��ʼ��ѯ����				| ����(1Byte,�㲥/ѡ��) + ʱ����(1Byte) + �ն˸���(1Byte) + �б�(TTERLABEL����)
OSPEVENT (EV_CTRL_STARTPOLL_CMD 		 , INNER_CTRL_ENTRY + 87);
// ������ѯ����				| NULL
OSPEVENT (EV_CTRL_STOPPOLL_CMD			 , INNER_CTRL_ENTRY + 88);
// ��ͣ��ѯ����				| NULL
OSPEVENT (EV_CTRL_PAUSEPOLL_CMD			 , INNER_CTRL_ENTRY + 89);
// �ָ���ѯ����				| NULL
OSPEVENT (EV_CTRL_RESUMEPOLL_CMD		 , INNER_CTRL_ENTRY + 90);
// ��ѯ��ѯ����				| NULL
OSPEVENT (EV_CTRL_POLLPARAM_REQ			 , INNER_CTRL_ENTRY + 91);
// ��ѯ����Ӧ��				| ��û����ѯ + NULL
//							| ��������ѯ + ����(1Byte,�㲥/ѡ��) + ģʽ(1Byte,A/V/Both) + ʱ����(1Byte) + �ն˸���(1Byte) + �б�(TTERLABEL����)
OSPEVENT (EV_CTRL_POLLPARAM_RSP			 , INNER_CTRL_ENTRY + 92);
// ��ѯ״ָ̬ʾ				| 
OSPEVENT (EV_CTRL_POLLPARAM_IND			 , INNER_CTRL_ENTRY + 93);
// ��ϯ�ն����������ն˵��ն�״̬	|TTERLABEL
OSPEVENT (EV_CTRL_MTSTATUS_REQ			 , INNER_CTRL_ENTRY + 94);
// ���������ն˵��ն�״̬Ӧ��		|TTERLABEL + _TTERSTATUS
OSPEVENT (EV_CTRL_MTSTATUS_RSP			 , INNER_CTRL_ENTRY + 95);


// ���Ͷ���Ϣ				| TROLLMSG
OSPEVENT (EV_CTRL_SMS_IND				 , INNER_CTRL_ENTRY + 96);
// Զң����					| TTERLABEL(src) + TTERLABEL(dst) + TFeccStruct
OSPEVENT (EV_CTRL_FECC_CMD				 , INNER_CTRL_ENTRY + 97);
// �ն�״̬����				| NULL
OSPEVENT (EV_CTRL_TERSTATUS_REQ			 , INNER_CTRL_ENTRY + 98);
// �ն�״̬Ӧ��				| _TTERSTATUS
OSPEVENT (EV_CTRL_TERSTATUS_RSP			 , INNER_CTRL_ENTRY + 99);

// ������Ϣ����				| NULL					UI->MTCTRL
OSPEVENT (EV_CTRL_CONFINFO_REQ			 , INNER_CTRL_ENTRY + 101);
// ������ϢӦ��				| 
//													MTCTRL->UI
OSPEVENT (EV_CTRL_CONFINFO_RSP			 , INNER_CTRL_ENTRY + 102);
// ���鼴��������ʾ			| u16(��λ:����)		MTCTRL->UI
OSPEVENT (EV_CTRL_CONFWILLEND_IND		 , INNER_CTRL_ENTRY + 103);
// �����ӳ�����				| u16(��λ:����)		UI->MTCTRL
OSPEVENT (EV_CTRL_DELAYCONF_REQ			 , INNER_CTRL_ENTRY + 104);
// �����ӳ�Ӧ��				| 1BYTE	1:OK 0:FAIL		MTCTRL->UI
OSPEVENT (EV_CTRL_DELAYCONF_RSP			 , INNER_CTRL_ENTRY + 105);

// ������������				| 1BYTE(MT_START/MT_STOP)	| chair->MC
OSPEVENT (EV_CTRL_VAC_REQ				 , INNER_CTRL_ENTRY + 111);
// ��������Ӧ��				| 1BYTE(MT_START/MT_STOP) + 1BYTE(ctrl_granted/ctrl_denied)		| MC->chair
OSPEVENT (EV_CTRL_VAC_RSP				 , INNER_CTRL_ENTRY + 112);
// ����ģʽ����				| 1BYTE(MT_START)+1BYTE(����ն˸���)/1BYTE(MT_STOP)	| chair->MC
OSPEVENT (EV_CTRL_DISCUSS_REQ			 , INNER_CTRL_ENTRY + 113);
// ����ģʽӦ��				| 1BYTE(MT_START/MT_STOP) + 1BYTE(ctrl_granted/ctrl_denied)		| MC->chair
OSPEVENT (EV_CTRL_DISCUSS_RSP			 , INNER_CTRL_ENTRY + 114);
// ��Ƶ��������				| MT_START(1BYTE)+TVMPParam|MT_STOP(1BYTE)	| ter->MC(��ϯ�ſɷ�������)
OSPEVENT (EV_CTRL_VMP_REQ				 , INNER_CTRL_ENTRY + 115);
// ��Ƶ����Ӧ��				| 1BYTE(MT_START/MT_STOP) + 1BYTE(ctrl_granted/ctrl_denied)		| MC->ter
OSPEVENT (EV_CTRL_VMP_RSP				 , INNER_CTRL_ENTRY + 116);
// ������Ƶ���ϲ�������		| TVMPParam								| ter->MC(��ϯ�ſɷ�������)
OSPEVENT (EV_CTRL_VMPSETPARAM_REQ		 , INNER_CTRL_ENTRY + 117);
// ������Ƶ���ϲ���Ӧ��		| 1BYTE(ctrl_granted/ctrl_denied)		| MC->ter
OSPEVENT (EV_CTRL_VMPSETPARAM_RSP		 , INNER_CTRL_ENTRY + 118);
// ��ȡ��Ƶ���ϲ�������		| NULL									| ter->MC(��ϯ�ſɷ�������)
OSPEVENT (EV_CTRL_VMPGETPARAM_REQ		 , INNER_CTRL_ENTRY + 119);
// ��ȡ��Ƶ���ϲ���Ӧ��		| TVMPParam								| MC->ter
OSPEVENT (EV_CTRL_VMPGETPARAM_RSP		 , INNER_CTRL_ENTRY + 120);
// ��ƵԴָʾ				|��\0�������ַ���						| MC->ter
OSPEVENT (EV_CTRL_SRCNAME_IND			 , INNER_CTRL_ENTRY + 121);



/************************�� �� �� ��************************/

// ��ʼ�������				| <m,t>									| ter->MC
OSPEVENT (EV_CTRL_STARTMONITOR_REQ		 , INNER_CTRL_ENTRY + 126);
// ��ʼ���Ӧ��				| <m,t> + TIPADDR(���յ�ַ,���ʧ��ipΪ0)	| MC->ter
OSPEVENT (EV_CTRL_STARTMONITOR_RSP		 , INNER_CTRL_ENTRY + 127);
// ֹͣ�������				| <m,t>									| ter->MC
OSPEVENT (EV_CTRL_STOPMONITOR_CMD		 , INNER_CTRL_ENTRY + 128);

/************************�� �� �� ��************************/

// MCU�������ǰ����		| 1BYTE(MT_AUDIO|MT_VIDEO|MT_AV)		| MC->ter
OSPEVENT (EV_CTRL_MATRIXINFO_REQ		 , INNER_CTRL_ENTRY + 131);
// �ն��ϱ�����ǰ����		| 1BYTE(MT_AUDIO|MT_VIDEO|MT_AV) + _TMATRIXINFO(�����MT_AV��Ϊ����,A+V) | ter->MC
OSPEVENT (EV_CTRL_MATRIXINFO_IND		 , INNER_CTRL_ENTRY + 132);
// MCU�����ն˾�������		| 1BYTE(MT_AUDIO|MT_VIDEO|MT_AV) + _TMATRIXPORT(����˿�) + _TMATRIXPORT(����˿�) | MC->ter
OSPEVENT (EV_CTRL_MATRIXCFG_CMD			 , INNER_CTRL_ENTRY + 133);
// MCU������󷽰�			| 1BYTE(MT_AUDIO|MT_VIDEO|MT_AV)		| MC->ter
OSPEVENT (EV_CTRL_MATRIXSCHEME_REQ		 , INNER_CTRL_ENTRY + 134);
// �ն��ϱ����󷽰�			| TMATRIXSCHEME					| ter->MC
OSPEVENT (EV_CTRL_MATRIXSCHEM_IND		 , INNER_CTRL_ENTRY + 135);
// MCU���뷽��				| TMATRIXSCHEME					| MC->ter
OSPEVENT (EV_CTRL_LOADSCHEME_CMD			 , INNER_CTRL_ENTRY + 136);
// MCU���淽��				| TMATRIXSCHEME					| MC->ter
OSPEVENT (EV_CTRL_SAVESCHEME_CMD			 , INNER_CTRL_ENTRY + 137);
// MCU�����ն˾���ΪĬ��ֵ	| 1BYTE(MT_AUDIO|MT_VIDEO|MT_AV)		| MC->ter
OSPEVENT (EV_CTRL_DEFAULTCFG_CMD			 , INNER_CTRL_ENTRY + 138);


///////////////////////////// RAS��Ϣ ///////////////////////////////

// GKע������				| TALIASADDR(���˱���) + TNETADDR(GK��ַ)						| MTCTRL->STACKOUT
OSPEVENT ( EV_RAS_REG_REQ				 , INNER_RAS_ENTRY + 1);
// GKע������				| NULL									| STACKIN->MTCTRL
OSPEVENT ( EV_RAS_UNREG_REQ				 , INNER_RAS_ENTRY + 2);
// �ն���GK��״ָ̬ʾ		| 1BYTE(MT_OK:��ע�� MT_ERR:δע��)		| STACKIN->MTCTRL
OSPEVENT ( EV_RAS_STAT_IND				 , INNER_RAS_ENTRY + 3);
// GK��Ȩȷ��		| 4BYTE����ֵ		| STACKIN->MTCTRL
OSPEVENT ( EV_RAS_ACF_RSP				 , INNER_RAS_ENTRY + 4);


	
/////////////////////////////������Ϣ/////////////////////////////////





/////////////////////////////����MC��Ϣ//////////////////////////////

//����MC��Ϣ					| MC_ACTIVE/MC_INACTIVE		| MtCtrl -> MTMC   				 
OSPEVENT ( EV_MC_SETACTIVE_CMD				, 	INNER_MC_ENTRY + 1 );
//���û�������ģʽ				| MC_NEWCONF	MC_NEWCONF_ALWAYS/MC_NEWCONF_NEVER/MC_NEWCONF_ASK
//												| MtCtrl -> MTMC  
OSPEVENT ( EV_MC_NEWCONFMODE_CMD	, 			INNER_MC_ENTRY + 2 );
//�ϼ�������Ϣ֪ͨ	            | TMCRegConf	| MTCtrl->MTMC			 
OSPEVENT ( EV_MC_REGCONF_IND	, 				INNER_MC_ENTRY + 3 );
//����MC����RTP/RTCP�˿ں�		| TMCResetAddr  | MTMC->MtCtrl    
OSPEVENT ( EV_MC_RESETMEDIAADDR_CMD	,			INNER_MC_ENTRY + 4 );
// ��չ����֪ͨ					| NULL			| MtCtrl->MTMC
OSPEVENT ( EV_MC_HOCACTIVE_IND		,			INNER_MC_ENTRY + 5 );
// ��չ����״̬֪֪ͨͨ			| 1 BYTE(MC_CONF_NONE/MC_CONF_SUPER/MC_CONF_CASCADE)
//								| MTMC->MtCtrl
OSPEVENT ( EV_MC_HOCSTATUS_IND		,			INNER_MC_ENTRY + 6 );
// �������鿪ʼ����				|  TNETADDR(�Զ˵�ַ) | MTMC->MtCtrl
OSPEVENT ( EV_MC_CONFCASCADE_REQ	,			INNER_MC_ENTRY + 7 );
// ������������Ӧ��				| 1 BYTE(MT_ENABLE/MT_DISABLE)	| MtCtrl->MTMC
OSPEVENT ( EV_MC_CONFCASCADE_RSP	,			INNER_MC_ENTRY + 8 );

/*
// �����ն�						| _TDIALPARAM	| UI->MTMC
OSPEVENT (EV_MC_MAKECALL_CMD			 ,		INNER_MC_ENTRY + 5);
// ���е���						| _TDIALPARAM	| MTMC->UI
OSPEVENT (EV_MC_CALLINCOMING_IND		 ,		INNER_MC_ENTRY + 6);	
// ����Ӧ��						| NULL			| UI->MTMC
OSPEVENT (EV_MC_ANSWERCALL_CMD		 ,			INNER_MC_ENTRY + 7);
// ����״̬						| 1BYTE,CALL_LINKING(������)/CALL_LINKED(������)/CALL_UNLINK(���ӶϿ�)	| MTMC->UI
OSPEVENT (EV_MC_LINKSTATE_IND			 ,		INNER_MC_ENTRY + 8);
// �ҶϺ���						| NULL			| UI->MTMC
OSPEVENT (EV_MC_HANGUP_CMD			 ,			INNER_MC_ENTRY + 9);
*/


///////////////////////////////////////Sat�����Ϣ///////////////////////////////////////
//��ʼ��Э��ջ					| TSatInitParam				|mcu->ter 
OSPEVENT (EV_SAT_INITSTACK_IND			 ,			EV_OUTEROSP_BGN + 1);
//�����б���Ϣ֪ͨ				| TSatConfInfo�ṹ����		|mcu->ter
OSPEVENT (EV_SAT_CONFLIST_IND			 ,			EV_OUTEROSP_BGN + 2);
//�����֪ͨ					| 1 BYTE �������� 1= ������ 0=��Ե����		|mcu->ter
//OSPEVENT (EV_SAT_JIONCONF_IND			     ,		EV_OUTEROSP_BGN + 3);
//�˳�����֪ͨ					| 1 BYTE �˻�ԭ��			|mcu->ter
//OSPEVENT (EV_SAT_QUITCONF_IND			     ,		EV_OUTEROSP_BGN + 4);
//�ն��б�֪ͨ					| TSatMtInfo �ṹ����		|mcu->ter
OSPEVENT (EV_SAT_MTLIST_IND			     ,			EV_OUTEROSP_BGN + 5);
//�ն˳�Ϊ��ϯ֪ͨ				| NULL						|muc->ter
OSPEVENT (EV_SAT_SPECCHAIRMAN_IND			     ,	EV_OUTEROSP_BGN + 6);
//�ն��ͷ���ϯ֪ͨ				| NULL						|muc->ter
OSPEVENT (EV_SAT_CANCELCHAIRMAN_IND			     ,	EV_OUTEROSP_BGN + 7);
//���ն�Ϊ������֪ͨ			| NULL						|muc->ter
OSPEVENT ( EV_SAT_SPECSPEAKER_IND			     ,	EV_OUTEROSP_BGN + 8);
//���ն�ȡ��������֪ͨ			| NULL						|muc->ter
OSPEVENT ( EV_SAT_CANCELSPEAKER_IND			     ,	EV_OUTEROSP_BGN + 9);
//������Ƶ����					|TSatBitrate				|muc->ter
OSPEVENT ( EV_SAT_SETBITRATE_CMD			     ,	EV_OUTEROSP_BGN + 10);
//������Ϣ						|1BYTE 1=���� 0=ֹͣ����	|muc->ter
OSPEVENT ( EV_SAT_MUTE_CMD			     ,			EV_OUTEROSP_BGN + 11);
//������Ϣ						|1BYTE 1=���� 0=ֹͣ����	|muc->ter
OSPEVENT ( EV_SAT_QUIET_CMD			     ,			EV_OUTEROSP_BGN + 12);
//�ش�ͨ��״ָ̬ʾ��Ϣ			|1BYTE 1=��ȡ�ش�ͨ�� 0=û�лش�ͨ��	|muc->ter
OSPEVENT ( EV_SAT_UPLOAD_IND			     ,		EV_OUTEROSP_BGN + 13);
//�����ն�������ϯ				| �ն�ID TSatMtId			| mcu->ter
OSPEVENT ( EV_SAT_OTHERAPPLYCHAIR_CMD			  , EV_OUTEROSP_BGN + 14);
//�����ն����뷢��				| �ն�ID TSatMtId			| mcu->ter
OSPEVENT ( EV_SAT_OTHERAPPLYSPEAK_CMD			  , EV_OUTEROSP_BGN + 15);
//����������					| ����������(u8)(0: ����ָʾ) | ter->mcu
//OSPEVENT ( EV_SAT_JIONCONF_CMD			     ,		EV_OUTEROSP_BGN + 16);
//������ϯ						| NULL					| ter->mcu
OSPEVENT ( EV_SAT_APPLYCHAIRMAN_CMD		     ,		EV_OUTEROSP_BGN + 17);
//���뷢��						| NULL					| ter->mcu
OSPEVENT ( EV_SAT_APPLYSPEAKER_CMD			     ,	EV_OUTEROSP_BGN + 18);
//ָ��������					| �ն�ID(u16)			| ter->mcu
OSPEVENT ( EV_SAT_SPECSPEAKER_CMD			     ,	EV_OUTEROSP_BGN + 19);
//ȡ��������					| �ն�ID(u16)			| ter->mcu
OSPEVENT ( EV_SAT_CANCEALSPEAKER_CMD			  , EV_OUTEROSP_BGN + 20);
//ָ����ϯ						| �ն�ID(u16)			| ter->mcu
OSPEVENT ( EV_SAT_SPECCHAIRMAN_CMD			     ,	EV_OUTEROSP_BGN + 21);
//ȡ����ϯ						| NULL					| ter->mcu
OSPEVENT ( EV_SAT_CANCEALCHAIRMAN_CMD			  , EV_OUTEROSP_BGN + 22);
//����Ϣ֪ͨ					|TSatSMS        		| mcu->ter
OSPEVENT ( EV_SAT_SMS_IND   			     ,		EV_OUTEROSP_BGN + 23);
// �ؼ�֡����						|NULL					| mcu->ter
OSPEVENT ( EV_SAT_VIDEOUPDATE_CMD   			     ,	EV_OUTEROSP_BGN + 24);
//��������						|NULL					| ter->mcu
OSPEVENT ( EV_SAT_DROPCONF_CMD   			     ,	EV_OUTEROSP_BGN + 25);
//�ȴ�����Ӧ��ʱ				|NULL									| mcu->ter
OSPEVENT ( EV_SAT_WAITQUITCONFTIMEOUT_IND 				,EV_OUTEROSP_BGN + 26);

//��ǰ�ۿ���ƵԴ				|TSatMtId						| mcu->ter
OSPEVENT ( EV_SAT_YOUARESEEING_IND 			     ,	EV_OUTEROSP_BGN + 27);
//��ǰ������������ƵԴ			|TSatMtId						| mcu->ter
OSPEVENT ( EV_SAT_YOUARELISTENING_IND 			   ,EV_OUTEROSP_BGN + 28);
//ϵͳ��Կ						|����Ϊ16��u8����						| mcu->ter
OSPEVENT ( EV_SAT_SYSPWD_IND 						,EV_OUTEROSP_BGN + 29);
//Զң����						|TFeccCmd						        | mcu->ter
OSPEVENT ( EV_SAT_FECC_CMD 						    ,EV_OUTEROSP_BGN + 30);
//mcu��Ϣ����					|TSatConfStatus							| mcu->ter
OSPEVENT ( EV_SAT_CONFINFO_IND 						,EV_OUTEROSP_BGN + 31);
//�ն�ҵ��֪ͨ���ռ����������	|NULL									| mcu->ter		
OSPEVENT ( EV_SAT_ACCEPTCONFINVITE_IND 				,EV_OUTEROSP_BGN + 32);
//�ȴ�����Ӧ��ʱ				|NULL									| mcu->ter
OSPEVENT ( EV_SAT_WAITCALLTIMEOUT_IND 				,EV_OUTEROSP_BGN + 33);
//�ն˱���ָʾ					|��/0�������ַ���						| mcu->ter
OSPEVENT ( EV_SAT_MTNAME_IND 						,EV_OUTEROSP_BGN + 34);

//����ʵ������					|NULL						| ter->mcu
OSPEVENT ( EV_ENTITY_SAT_ONLINE_IND 						,EV_OUTEROSP_BGN + 35);

//����ʵ�����					|NULL						| ter->mcu
OSPEVENT ( EV_ENTITY_SAT_OFFLINE_IND 						,EV_OUTEROSP_BGN + 36);

//���÷��͵�ַ                  |
OSPEVENT(  EV_SAT_ENTITY_SETSENDADDR_CMD    				,EV_OUTEROSP_BGN + 37);

//���渴��״̬                  |u8(=0 ֹͣ 1=��ʼ)��TSatVMPStatus  | mcu->ter
OSPEVENT(  EV_SAT_VMPSTATUS_IND    				    ,EV_OUTEROSP_BGN + 38);


///////////////////////////////////////////////////////////////
//����ϵͳ���յ�MCU��������Ϣ֪ͨ |���Ƕ�����Ϣ
OSPEVENT(  EV_SAT_INNER_MCUMSG_IND    				,EV_OUTEROSP_BGN + 39);

//MT������֮�����ָʾ            |NULL
OSPEVENT(  EV_SAT_INNER_DISCONNECT_IND				,EV_OUTEROSP_BGN + 40);

//MCU ��ʼ����             |NULL
OSPEVENT(  EV_SAT_INNER_CONNECTED_IND				,EV_OUTEROSP_BGN + 41);

//��ʱ������Ϣ                    |NULL
OSPEVENT(  EV_SAT_INNER_SENDTIMER_IND				,EV_OUTEROSP_BGN + 42);

//������Ϣ���³�ʱ��Ϣ            |NULL
OSPEVENT(  EV_SAT_INNER_CONFINFOTIMEOUT_IND  		,EV_OUTEROSP_BGN + 43);

//��Ե�ȴ����ܺ��ж�ʱ��Ϣ      |NULL
OSPEVENT(  EV_SAT_P2P_WAITACCEPT_TIMER  	    	,EV_OUTEROSP_BGN + 44);

//��Ե�ROUNDTRIP ��ʱ��Ϣ      |NULL
OSPEVENT(  EV_SAT_P2P_ROUNDTRIP_TIMER  	    	,EV_OUTEROSP_BGN + 45);
 
//�ȴ���������鳬ʱ
OSPEVENT ( EV_SAT_INNER_WAITMCCTIMEOUT_IND		 ,EV_OUTEROSP_BGN + 46);

//�ȴ������Ե����ϳ�ʱ
OSPEVENT ( EV_SAT_INNER_WAITP2PCALLCOMPLETE_IND		 ,EV_OUTEROSP_BGN + 47);

//Modem ������
OSPEVENT ( EV_SAT_INNER_MODEMMANAGER_TIMER		 ,EV_OUTEROSP_BGN + 48);


//֪ͨ�ϲ�topo��Ϣָʾ            |TSatMtInfo����
OSPEVENT(  EV_SAT_TOPO_IND				    ,EV_OUTEROSP_BGN + 50);

//�����֪ͨ					| TSatConfFormat		|mcu->ter
OSPEVENT (EV_SAT_INCONF_IND			        ,EV_OUTEROSP_BGN + 51);

//����������					| ����������(u8)(0: ����ָʾ) | ter->mcu
OSPEVENT ( EV_SAT_APPLYJOINCONF_CMD		     ,EV_OUTEROSP_BGN + 52);

//ӵ�лش��ն��б�				| TSatMtList | mcu->ter
OSPEVENT ( EV_SAT_CANSENDMT_IND		         ,EV_OUTEROSP_BGN + 53);

//��������                      |TSatConfFormat+TSatMtList |ter->mcu
OSPEVENT ( EV_SAT_CREATECONF_CMD		     ,EV_OUTEROSP_BGN + 54);

//�˳���������                  |NULL        |ter->mcu
OSPEVENT ( EV_SAT_LEAVECONF_CMD		     ,EV_OUTEROSP_BGN + 55);

//�˳�����ָʾ                  |NULL        |ter->mcu
OSPEVENT ( EV_SAT_LEAVECONF_IND		     ,EV_OUTEROSP_BGN + 56);

//��������                      |NULL        |ter->mcu
OSPEVENT ( EV_SAT_QUITCONF_CMD		     ,EV_OUTEROSP_BGN + 57);

//�����ն��б�              		| TSatMtList | mcu->ter
OSPEVENT ( EV_SAT_CONFMTLIST_IND		         ,EV_OUTEROSP_BGN + 62);


//�(��ǩ��)�ն��б�				| TSatMtList | mcu->ter
OSPEVENT ( EV_SAT_ACTIVEMT_IND		         ,EV_OUTEROSP_BGN + 63);

//��Ե㷢�����
//                   -ITSatMtId  ���������ID
//                   +ITSatTransAddr �����߽��յ�ַ
//                   +TSatConfFormat ��Ե�����ʽ 
OSPEVENT ( EV_SAT_P2P_CALL_CMD		         ,EV_OUTEROSP_BGN + 64);

//��Ե���պ���
//                   -ITSatMtId  ���պ�����ID
//                   +ITSatTransAddr ���յ�ַ
OSPEVENT ( EV_SAT_P2P_ACCEPT_IND		     ,EV_OUTEROSP_BGN + 65);

//��Ե����ȷ�Ͻ���   |NULL
OSPEVENT ( EV_SAT_P2P_CALL_COMPLETE_IND		 ,EV_OUTEROSP_BGN + 66);

//��Ե�TROUNDTRIP     |NULL
OSPEVENT ( EV_SAT_P2P_ROUNDTRIP		 ,EV_OUTEROSP_BGN + 67);

//��Ե�������       |NULL
OSPEVENT ( EV_SAT_P2P_RELEASE_CMD		 ,EV_OUTEROSP_BGN + 68);


//���������鶨ʱ�����Ϣ      |NULL
OSPEVENT ( EV_SATH323ADP_CHECKCONFTIMER		 ,EV_OUTEROSP_BGN + 69);

//���渴��״̬                  |TSatVMPStatus  | mcu->ter
OSPEVENT(  EV_SAT_SETVMP_CMD    				    ,EV_OUTEROSP_BGN + 70);

//ǿ�ƹؼ�֡��ʱ��
OSPEVENT(  EV_SAT_IFRAME_TIMER    				    ,EV_OUTEROSP_BGN + 71);

//link setup��Ϣ��ʾ		|ITLinkSetup |satinterface->satadapter
OSPEVENT( EV_SAT_NOTIFY_LINKSETUP	,EV_OUTEROSP_BGN + 72);
//˫��
OSPEVENT( EV_SAT_OPEN_DUALCHAN	,EV_OUTEROSP_BGN + 73);

OSPEVENT( EV_SAT_OPEN_DUALCHAN_RSP , EV_OUTEROSP_BGN + 74);

OSPEVENT( EV_SAT_OPEN_DUALCHAN_TIMEOUT , EV_OUTEROSP_BGN + 75);

OSPEVENT( EV_SAT_DUAL_STREAM_IND , EV_OUTEROSP_BGN + 76 );

OSPEVENT( EV_SAT_SETVIDBITRATE_CMD , EV_OUTEROSP_BGN + 77 );

OSPEVENT( EV_SAT_SETAUDBITRATE_CMD , EV_OUTEROSP_BGN + 78 );

OSPEVENT( EV_SAT_MULTCHK_TIMER , EV_OUTEROSP_BGN + 79);

OSPEVENT( EV_SAT_ETHLINKCHK_TIMER , EV_OUTEROSP_BGN + 80);

OSPEVENT( EV_SAT_MTSTATUS_RSP , EV_OUTEROSP_BGN + 81);

//���м��IP��ַ�޸Ĺ���   
OSPEVENT( EV_SAT_CHANGEIP_TIMER , EV_OUTEROSP_BGN + 82);

//֪ͨmtsatinterface����֪��IP��ַ�Ѿ������޸�
OSPEVENT( EV_SAT_CHANGEIP_IND , EV_OUTEROSP_BGN + 83);

//����ֱ������ʱ�����������Ƿ�ͨ��ʱ��  
OSPEVENT( EV_SAT_LINK_SETUP_TIMER, EV_OUTEROSP_BGN + 84);

//����ֱ�����������粻֪ͨͨ  
OSPEVENT( EV_SAT_DISCONNETCT, EV_OUTEROSP_BGN + 85);

//�����ŷ���   
OSPEVENT( EV_SAT_VOICESPEAKE_IND, EV_OUTEROSP_BGN + 86 );

//֪ͨ�����ŷ���ֹͣ��ʧ��ʱ��
OSPEVENT( EV_SAT_VOICESPEAKE_TIMER, EV_OUTEROSP_BGN + 87);

//==========================================================================================
//									�ⲿ��Ϣ����
//==========================================================================================

///////////////////////////////���������Ϣ//////////////////////////////////

// �������					| _TDIALPARAM	| UI->MTCTRL
OSPEVENT (EV_CONF_MAKECALL_CMD			 , OUTER_CONF_ENTRY + 1);
// ���е���					| _TDIALPARAM(����320�ն�,û�в���)	| MTCTRL->UI 
OSPEVENT (EV_CONF_CALLINCOMING_IND		 , OUTER_CONF_ENTRY + 2);	
// ����Ӧ��					| NULL			| UI->MTCTRL
OSPEVENT (EV_CONF_ANSWERCALL_CMD		 , OUTER_CONF_ENTRY + 3);
// ����״̬					|				| MTCTRL->UI	
// ����˵��: ������:1BYTE,CALL_LINKING
//			 ������:1BYTE,CALL_LINKED + �Զ�����
//			 ���ӶϿ�:1BYTE,CALL_UNLINK 			
OSPEVENT (EV_CONF_LINKSTATE_IND			 , OUTER_CONF_ENTRY + 4);
// �ҶϺ���					| NULL			| UI->MTCTRL
OSPEVENT (EV_CONF_HANGUP_CMD			 , OUTER_CONF_ENTRY + 5);
// �ܾ��º���(�Ѿ��ں�����)	| NULL			| UI->MTCTRL
OSPEVENT (EV_CONF_REJECTCALL_CMD		 , OUTER_CONF_ENTRY + 6);
// ��չ��������				| NULL			| UI->MTCTRL
OSPEVENT (EV_CONF_ADHOC_CMD				 , OUTER_CONF_ENTRY + 7);
// ѡ������б�����			| _TCONFINFO����| MTCTRL->UI
OSPEVENT (EV_CONF_LISTCHOICE_REQ		 , OUTER_CONF_ENTRY + 8);
// ѡ������б�Ӧ��			| confId(16 BYTE)	| UI->MTCTRL
OSPEVENT (EV_CONF_LISTCHOICE_RSP		 , OUTER_CONF_ENTRY + 9);

// ��GK����ע������			| u32(GK IP��ַ,������)	| UI->MTCTRL
//OSPEVENT (EV_CONF_RASREG_REQ			 , OUTER_CONF_ENTRY + 11);
// ��GK����ע������			| NULL						| UI->MTCTRL
//OSPEVENT (EV_CONF_RASUNREG_REQ			 , OUTER_CONF_ENTRY + 12);
// �ն���GK��״ָ̬ʾ		| 1BYTE(MT_OK:��ע�� MT_ERR:δע��)	| STACKIN->MTCTRL
OSPEVENT (EV_CONF_RASSTAT_IND			 , OUTER_CONF_ENTRY + 13);

// ���ӽ��֪ͨ				| 1BYTE(MT_MASTER|MT_SLAVER) | MTCTRL->UI
OSPEVENT (EV_CONF_MSDE_IND				 , OUTER_CONF_ENTRY + 15);
// ������鿪ʼָʾ			| NULL			| MTCTRL->UI
OSPEVENT (EV_CONF_P2PSTART_IND			 , OUTER_CONF_ENTRY + 16);
// �����鿪ʼָʾ			| NULL			| MTCTRL->UI
OSPEVENT (EV_CONF_MCCSTART_IND			 , OUTER_CONF_ENTRY + 17);

// MCUҪ�������������		| NULL			| MTCTRL->UI
OSPEVENT (EV_CONF_H243PWD_REQ			 , OUTER_CONF_ENTRY + 18);
// MT�ش��������			| password(char*) ��󳤶�MT_PWD_LEN | MTCTRL->UI
OSPEVENT (EV_CONF_H243PWD_RSP			 , OUTER_CONF_ENTRY + 19);

// ���˱��ָʾ				| <m,t>			| MTCTRL->UI
OSPEVENT (EV_CONF_LABELASSIGN_IND		 , OUTER_CONF_ENTRY + 21);	
// �ն˼���					| <m,t>			| MTCTRL->UI
OSPEVENT (EV_CONF_TERJOINED_IND			 , OUTER_CONF_ENTRY + 22);	
// �ն��˳�					| <m,t>			| MTCTRL->UI
OSPEVENT (EV_CONF_TERLEFT_IND			 , OUTER_CONF_ENTRY + 23);	
// ǿ���ն��˳�				| <m,t>			| UI->MTCTRL
OSPEVENT (EV_CONF_DROPTER_CMD			 , OUTER_CONF_ENTRY + 24);	
// ǿ���ն��˳��ܾ�			| NULL			| MTCTRL->UI
OSPEVENT (EV_CONF_DROPREJECT_IND		 , OUTER_CONF_ENTRY + 25);	

// �ն��б����				| TMTINFO������	| MTCTRL->UI
OSPEVENT (EV_CONF_TERLIST_IND			 , OUTER_CONF_ENTRY + 26);	
// ���뷢������				| NULL			| UI->MTCTRL
OSPEVENT (EV_CONF_APPLYSPEAK_REQ		 , OUTER_CONF_ENTRY + 27);
// ���뷢��ָʾ				| <m,t>			| MTCTRL->UI
OSPEVENT (EV_CONF_APPLYSPEAK_IND		 , OUTER_CONF_ENTRY + 28);
// �㲥�ն�����(��ϯ)		| <m,t>			| UI->MTCTRL
OSPEVENT (EV_CONF_BROADCASTTER_CMD		 , OUTER_CONF_ENTRY + 29);
// ѡ���ն�����(��ϯ)		| <m,t>	+ 1Byte(MT_VIDEO|MT_AUDIO|MT_AV) | UI->MTCTRL
OSPEVENT (EV_CONF_VIEWTHSITER_CMD		 , OUTER_CONF_ENTRY + 30);
// ��ƵԴָʾ				| <m,t>			| MTCTRL->UI
OSPEVENT (EV_CONF_YOUARESEEING_IND		 , OUTER_CONF_ENTRY + 31);
// ���˱��㲥ָʾ			| ��			| MTCTRL->UI
OSPEVENT (EV_CONF_SEENBYALL_IND			 , OUTER_CONF_ENTRY + 32);
// ���˱�ȡ���㲥ָʾ		| ��			| MTCTRL->UI
OSPEVENT (EV_CONF_CANCELSEENBYALL_IND	 , OUTER_CONF_ENTRY + 33);
// �㲥�ն�����				| <m,t>			| UI->MTCTRL
OSPEVENT (EV_CONF_BROADCASTTER_REQ		 , OUTER_CONF_ENTRY + 34);
// �㲥�ն�Ӧ��				| 1BYTE(MT_OK:�ɹ� MT_ERR:ʧ��)	| MTCTRL->UI
OSPEVENT (EV_CONF_BROADCASTTER_RSP		 , OUTER_CONF_ENTRY + 35);
// ѡ���ն�����				| <m,t>			| UI->MTCTRL
OSPEVENT (EV_CONF_VIEWTHISTER_REQ		 , OUTER_CONF_ENTRY + 36);
// ѡ���ն�Ӧ��				| 1BYTE(MT_OK:�ɹ� MT_ERR:ʧ��)	| MTCTRL->UI
OSPEVENT (EV_CONF_VIEWTHISTER_RSP		 , OUTER_CONF_ENTRY + 37);
// ȡ��ѡ��					| NULL			| UI->MTCTRL
OSPEVENT (EV_CONF_STOPVIEWTHISTER_CMD	 , OUTER_CONF_ENTRY + 38);
// ȡ������					| NULL			| UI->MTCTRL
OSPEVENT (EV_CONF_STOPBROADCASTTER_CMD	 , OUTER_CONF_ENTRY + 39);
// �����ն��б�				| NULL			| UI->MTCTRL
OSPEVENT (EV_CONF_TERLIST_REQ			 , OUTER_CONF_ENTRY + 40);


// ��ѯ�ն�					| ����(1Byte,CTRL_POLL_VCB:�㲥/CTRL_POLL_VCS:ѡ��) + 
//							| ý������(1Byte,MT_AUDIO/MT_VIDEO/MT_AV) +
//							| ʱ����(1Byte) + 
//							| �ն˸���(1BYTE) + ��ѯ���ն��б�(<m,t>����)	| UI->MTCTRL
OSPEVENT (EV_CONF_STARTPOLL_CMD			 , OUTER_CONF_ENTRY + 41);
// ֹͣ��ѯ					| NULL			| UI->MTCTRL
OSPEVENT (EV_CONF_STOPPOLL_CMD			 , OUTER_CONF_ENTRY + 42);
// ��ͣ��ѯ����				| NULL
OSPEVENT (EV_CONF_PAUSEPOLL_CMD			 , OUTER_CONF_ENTRY + 43);
// �ָ���ѯ����				| NULL
OSPEVENT (EV_CONF_RESUMEPOLL_CMD		 , OUTER_CONF_ENTRY + 44);
// ��ѯ��ѯ����				| NULL			| UI->MTCTRL
OSPEVENT (EV_CONF_POLLPARAM_REQ			 , OUTER_CONF_ENTRY + 45);
// �ش���ѯ����				| �Ƿ�����ѯ(1BYTE) + <����ѯ: ��ѯ����(1BYTE) +��ʱ����(1BYTE) +���ն˸���(1BYTE) + ��ѯ�б�(<m,t>����)>	| MTCTRL->UI
OSPEVENT (EV_CONF_POLLPARAM_RSP			 , OUTER_CONF_ENTRY + 46);


// ������ϯ					| NULL			| UI->MTCTRL
OSPEVENT (EV_CONF_MAKEMECHAIR_REQ		 , OUTER_CONF_ENTRY + 51);	
// �ͷ���ϯ					| NULL			| UI->MTCTRL
OSPEVENT (EV_CONF_RELEASECHAIR_REQ		 , OUTER_CONF_ENTRY + 52);
// ��ϯ�������				| 1BYTE(MT_OK:�����ϯ MT_ERR:ʧȥ��ϯ)	| MTCTRL->UI
OSPEVENT (EV_CONF_CHAIR_RSP				 , OUTER_CONF_ENTRY + 53);
// ѯ����ϯ					| NULL			| UI->MTCTRL
OSPEVENT (EV_CONF_CHAIRLOCATION_REQ		 , OUTER_CONF_ENTRY + 54);
// ��ϯָʾ					| <m,t>			| MTCTRL->UI
OSPEVENT (EV_CONF_CHAIR_IND				 , OUTER_CONF_ENTRY + 55);
// ������ָʾ				| <m,t>			| MTCTRL->UI
OSPEVENT (EV_CONF_SPEAKER_IND			 , OUTER_CONF_ENTRY + 56);

// �����ն�������ϯ			| <m,t>			| MTCTRL->UI
OSPEVENT (EV_CONF_APPLYCHAIR_IND		 , OUTER_CONF_ENTRY + 61);
// ��ϯ����ת��				| <m,t> ��ʾҪת�Ƶ�Ŀ���ն�	| UI->MTCTRL
OSPEVENT (EV_CONF_CHAIRTRANSFER_REQ		 , OUTER_CONF_ENTRY + 62);
// ��ϯ�����������			| _TERADDR		| UI->MTCTRL
OSPEVENT (EV_CONF_CHAIRINVITE_REQ		 , OUTER_CONF_ENTRY + 63);
// ��ϯ�����ն�ʧ��			| _TERADDR		| MTCTRL->UI
OSPEVENT (EV_CONF_INVITEFAILED_IND		 , OUTER_CONF_ENTRY + 64);
// ��ϯԶ�˾���				| <m,t> + 1Byte(MT_ENABLE/MT_DISABLE)	| UI->MTCTRL
OSPEVENT (EV_CONF_REMOTEQUIET_CMD		 , OUTER_CONF_ENTRY + 65);
// ��ϯԶ������				| <m,t> + 1Byte(MT_ENABLE/MT_DISABLE)	| UI->MTCTRL
OSPEVENT (EV_CONF_REMOTEMUTE_CMD		 , OUTER_CONF_ENTRY + 66);
// ����Ϣָʾ				| TROLLMSG	| UI->MTCTRL,MTCTRL->UI
OSPEVENT (EV_CONF_SMS_IND				 , OUTER_CONF_ENTRY + 67);
// ��ϯ�ն����������ն˵��ն�״̬	|TMTLABEL
OSPEVENT (EV_CONF_MTSTATUS_REQ			 , OUTER_CONF_ENTRY + 68);
// ���������ն˵��ն�״̬Ӧ��		|TMTLABEL + _TTERSTATUS
OSPEVENT (EV_CONF_MTSTATUS_RSP			 , OUTER_CONF_ENTRY + 69);

// ������Ϣ����				| NULL			| UI->MTCTRL
OSPEVENT (EV_CONF_INFO_REQ				 , OUTER_CONF_ENTRY + 71);
// ������ϢӦ��				| ������Ϣ�ṹ,MCU�����ṹ˵��			| MTCTRL->UI
OSPEVENT (EV_CONF_INFO_RSP				 , OUTER_CONF_ENTRY + 72);
// ���鼴��������ʾ			| u16(��λ:����)	| MTCTRL->UI
OSPEVENT (EV_CONF_END_IND				 , OUTER_CONF_ENTRY + 73);
// �����ӳ�����				| u16(��λ:����)	| UI->MTCTRL
OSPEVENT (EV_CONF_DELAY_REQ				 , OUTER_CONF_ENTRY + 74);
// �����ӳ�Ӧ��				| 1BYTE(MT_OK:�ɹ� MT_ERR:ʧ��)			| MTCTRL->UI
OSPEVENT (EV_CONF_DELAY_RSP				 , OUTER_CONF_ENTRY + 75);

// ������������				| 1BYTE(MT_START/MT_STOP)				| UI->MTCTRL(��ϯ�ſɷ�������)
OSPEVENT (EV_CONF_VAC_REQ				 , OUTER_CONF_ENTRY + 76);
// ��������Ӧ��				| 1BYTE(MT_START/MT_STOP) + 1BYTE(MT_OK/MT_ERR)			| MTCTRL->UI
OSPEVENT (EV_CONF_VAC_RSP				 , OUTER_CONF_ENTRY + 77);
// ����ģʽ����				| 1BYTE(MT_START)+1BYTE(����ն˸���)/1BYTE(MT_STOP)	| UI->MTCTRL(��ϯ�ſɷ�������)
OSPEVENT (EV_CONF_DISCUSS_REQ			 , OUTER_CONF_ENTRY + 78);
// ����ģʽӦ��				| 1BYTE(MT_START/MT_STOP) + 1BYTE(MT_OK/MT_ERR)			| MTCTRL->UI
OSPEVENT (EV_CONF_DISCUSS_RSP			 , OUTER_CONF_ENTRY + 79);
// ��Ƶ��������				| MT_START(1BYTE)+TVMPParam|MT_STOP(1BYTE)	| UI->MTCTRL(��ϯ�ſɷ�������)
OSPEVENT (EV_CONF_VMP_REQ				 , OUTER_CONF_ENTRY + 80);
// ��Ƶ����Ӧ��				| 1BYTE(MT_START/MT_STOP) + 1BYTE(MT_OK/MT_ERR)			| MTCTRL->UI
OSPEVENT (EV_CONF_VMP_RSP				 , OUTER_CONF_ENTRY + 81);
// ������Ƶ���ϲ�������		| TVMPParam								| UI->MTCTRL(��ϯ�ſɷ�������)
OSPEVENT (EV_CONF_VMPSETPARAM_REQ		 , OUTER_CONF_ENTRY + 82);
// ������Ƶ���ϲ���Ӧ��		| 1BYTE(MT_OK/MT_ERR)					| MTCTRL->UI
OSPEVENT (EV_CONF_VMPSETPARAM_RSP		 , OUTER_CONF_ENTRY + 83);
// ��ȡ��Ƶ���ϲ�������		| NULL									| UI->MTCTRL(��ϯ�ſɷ�������)
OSPEVENT (EV_CONF_VMPGETPARAM_REQ		 , OUTER_CONF_ENTRY + 84);
// ��ȡ��Ƶ���ϲ���Ӧ��		| TVMPParam								| MTCTRL->UI
OSPEVENT (EV_CONF_VMPGETPARAM_RSP		 , OUTER_CONF_ENTRY + 85);
// ��ƵԴָʾ				|��\0�������ַ���						| MTCTRL->UI
OSPEVENT (EV_CONF_SRCNAME_IND			 , OUTER_CONF_ENTRY + 86);
// �ش�ͨ��ָʾ				|(u8)MT_ENABLE/MT_DISABLE				| MTCTRL->UI
OSPEVENT (EV_CONF_UPLOADCHAN_IND			 , OUTER_CONF_ENTRY + 87);
// �ն˱���ָʾ				|��/0�������ַ���						| MTCTRL->UI
OSPEVENT (EV_CONF_MTNAME_IND			 , OUTER_CONF_ENTRY + 88);


/************************�� �� �� ��************************/

// ��ʼ�������				| <m,t>									| UI->MTCTRL
OSPEVENT (EV_CONF_STARTMONITOR_REQ			 , OUTER_CONF_ENTRY + 91);
// ��ʼ���Ӧ��				| <m,t> + DWORD(ip,���ʧ��ipΪ0) + WORD(��Ƶ�˿ں�) + WORD(��Ƶ�˿ں�)	| MTCTRL->UI
OSPEVENT (EV_CONF_STARTMONITOR_RSP			 , OUTER_CONF_ENTRY + 92);
// ֹͣ�������				| <m,t>									| UI->MTCTRL
OSPEVENT (EV_CONF_STOPMONITOR_CMD			 , OUTER_CONF_ENTRY + 93);


// ��������					| NULL			| UI->MTCTRL
OSPEVENT (EV_CONF_END_CMD				 , OUTER_CONF_ENTRY + 120);


/*
////////�໭��///////////
//��ʼ��ʾ�໭������		| <m,t>
OSPEVENT (EV_CONF_PIPSTART_REQ			 , OUTER_CONF_ENTRY + 51);
//��ʼ��ʾ�໭��Ӧ��		| <m,t> + 1byte(granted/denied)
OSPEVENT (EV_CONF_PIPSTART_RSP			 , OUTER_CONF_ENTRY + 52);
//ֹͣ��ʾ�໭��			| <m,t>
OSPEVENT (EV_CONF_PIPSTOP_CMD			 , OUTER_CONF_ENTRY + 53);
//��ѯ�����ն�ѡ��������	| <m,t>
OSPEVENT (EV_CONF_PIPQUERY_REQ			 , OUTER_CONF_ENTRY + 54);
//��ѯ�����ն�ѡ����Ӧ��	| <m,t>(dest) + <m,t>(viewing)
OSPEVENT (EV_CONF_PIPQUERY_RSP			 , OUTER_CONF_ENTRY + 55);
*/

///////////////////////////////��Ƶ������Ϣ//////////////////////////////////

// ��ʼ����Ƶ����			| _TDEVCFG	| MTCTRL->DEVCTRL
OSPEVENT (EV_MATRIX_INIT_CMD	    , OUTER_MATR_ENTRY + 1);
// ����һ�����룭���		| 1BYTE(MT_AUDIO/MT_VIDEO/MT_AV) + ����˿�(1BYTE) + ����˿�(1BYTE) | MTCTRL->DEVCTRL
OSPEVENT (EV_MATRIX_LINKONE_CMD	    , OUTER_MATR_ENTRY + 2);
// �����������룭���		| 1BYTE(MT_AUDIO/MT_VIDEO/MT_AV) + �˿�����(num,1BYTE) + num������˿ڶ�Ӧ������˿�(num��BYTEs) | MTCTRL->DEVCTRL
OSPEVENT (EV_MATRIX_LINKALL_CMD	    , OUTER_MATR_ENTRY + 3);
// ����״ָ̬ʾ				| 1BYTE(MT_OK:���ӳɹ� MT_ERR:����ʧ��)	| DEVCTRL->MTCTRL
OSPEVENT (EV_MATRIX_STATUS_IND	    , OUTER_MATR_ENTRY + 4);
		
// ������󷽰�				| 1BYTE(MT_AUDIO/MT_VIDEO/MT_AV)+1BYTE,������(1~8) + ������('\0'�������ַ���)	| UI->MTCTRL
OSPEVENT (EV_MATRIX_SCHEMESAVE_CMD	, OUTER_MATR_ENTRY + 6);
// ɾ�����󷽰�				| 1BYTE,������(1~8)	| UI->MTCTRL
OSPEVENT (EV_MATRIX_SCHEMEDEL_CMD	, OUTER_MATR_ENTRY + 7);
// ���ؾ��󷽰�				| 1BYTE(MT_AUDIO/MT_VIDEO/MT_AV)+1BYTE,������(1~8) | UI->MTCTRL
OSPEVENT (EV_MATRIX_SCHEMELOAD_CMD	, OUTER_MATR_ENTRY + 8);
// ���󷽰�ָʾ				| TMATRIXSCHEME���� | MTCTRL->UI
OSPEVENT (EV_MATRIX_SCHEME_IND		, OUTER_MATR_ENTRY + 9);
// ���þ���˿�				| 1BYTE(MT_AUDIO/MT_VIDEO/MT_AV) + ����˿�(_TMATRIXPORT) + ����˿�(_TMATRIXPORT)	| UI->MTCTRL
OSPEVENT (EV_MATRIX_CFGPORT_CMD		, OUTER_MATR_ENTRY + 10);
// �ָ�Ĭ������				| 1BYTE(MT_AUDIO/MT_VIDEO/MT_AV)	| UI->MTCTRL
OSPEVENT (EV_MATRIX_LOADDEFAULT_CMD	, OUTER_MATR_ENTRY + 11);
// ѡ��һ·����Դ			| 1BYTE(MT_AUDIO/MT_VIDEO/MT_AV) + 1BYTE(��ʾѡ�񼸺�����ƵԴ��1~16)	| UI->MTCTRL
OSPEVENT (EV_MATRIX_SELECTINPUT_REQ , OUTER_MATR_ENTRY + 12);
// ��ǰ����������Ϣ����		| 1BYTE(MT_AUDIO/MT_VIDEO/MT_AV)	| UI->MTCTRL
OSPEVENT (EV_MATRIX_INFO_REQ	    , OUTER_MATR_ENTRY + 13);
// ��ǰ����������Ϣָʾ		| 1BYTE(MT_AUDIO/MT_VIDEO/MT_AV) + _TMATRIXINFO(��ΪBoth,_TMATRIXINFO����,A+V)	| MTCTRL->UI
OSPEVENT (EV_MATRIX_INFO_IND	    , OUTER_MATR_ENTRY + 14);
// ���о��󷽰�����			| TMATRIXSCHEME����					| MTCTRL->UI
OSPEVENT (EV_MATRIX_SCHEME_REQ	    , OUTER_MATR_ENTRY + 15);



///////////////////////////////����ͷ��Ϣ//////////////////////////////////

// ����ͷ��ʼ��				| ����ͷ����(1Byte) + _TDEVCFG����
OSPEVENT (EV_CAMERA_INIT_CMD		, OUTER_CAM_ENTRY + 1);
// ����ͷ״ָ̬ʾ			| 4 BYTE,1-4������ͷ������״̬(MT_OK/MT_ERR)
OSPEVENT (EV_CAMERA_STATUS_IND		, OUTER_CAM_ENTRY + 2);

// ����/Զ������ͷ�л�		| 1 BYTE(MT_LOCAL:����/MT_REMOTE:Զ��)
OSPEVENT (EV_CAMERA_SOURCE_CMD		, OUTER_CAM_ENTRY + 6);
// ѡ����ƵԴ����			| 1 BYTE,Video Source Number(1-4)
OSPEVENT (EV_CAMERA_SELECT_CMD		, OUTER_CAM_ENTRY + 7);

// ˵��:���µ�Direction�������MtConstDef.h������ͷ�ĳ�������(��CAMERA_PAN_LEFT)

// �ƶ�����					| 2 BYTE,Direction + Action(MT_START/MT_STOP)
OSPEVENT (EV_CAMERA_PANTILT_CMD		, OUTER_CAM_ENTRY + 8);		
// �۽�����					| 2 BYTE,Direction + Action(MT_START/MT_STOP)
OSPEVENT (EV_CAMERA_FOCUS_CMD		, OUTER_CAM_ENTRY + 9);
// ��Ұ����					| 2 BYTE,Direction + Action(MT_START/MT_STOP)
OSPEVENT (EV_CAMERA_ZOOM_CMD		, OUTER_CAM_ENTRY + 10);
// Ԥ��λ����				| 2 BYTE,Action(save/move) + preset No(1-16)
OSPEVENT (EV_CAMERA_PRESET_CMD		, OUTER_CAM_ENTRY + 11);
// ���ȵ�������				| 2 BYTE,Direction + Action(MT_START/MT_STOP)
OSPEVENT (EV_CAMERA_BRIGHT_CMD		, OUTER_CAM_ENTRY + 12);

///////////////////////////////������Ϣ//////////////////////////////////
// ���ô���                 | _TSERCFG | MTCTRL->DEVCTRL
OSPEVENT (EV_SERIES_SETCOM_CMD     , OUTER_CAM_ENTRY + 13);
// IRAY��������                 | Э������(u8)+��ַ(u8) | MTCTRL->DEVCTRL
OSPEVENT (EV_IRAY_START_CMD     , OUTER_CAM_ENTRY + 14);


///////////////////////////////Codec�����Ϣ//////////////////////////////////

// ��������������			| EncoderID	+ _TPCCODEC	| MTCTRL->CODEC
OSPEVENT (EV_ENCODE_CREATE_REQ		, OUTER_CODEC_ENTRY + 1);
// ����������Ӧ��			| EncoderID + Result(1BYTE,MT_OK:�ɹ� MT_ERR:ʧ��)	| CODEC->MTCTRL
OSPEVENT (EV_ENCODE_CREATE_RSP		, OUTER_CODEC_ENTRY + 2);
// ���ñ������				| EncoderID + MediaType(MT_AUDIO/MT_VIDEO/MT_AV) + _TAENCPARAM/_TVENCPARAM	| MTCTRL->CODEC
OSPEVENT (EV_ENCODE_SETPARAM_CMD	, OUTER_CODEC_ENTRY + 3);
// ��ʼ��������				| EncoderID + MediaType(MT_AUDIO/MT_VIDEO/MT_AV)	| MTCTRL->CODEC
OSPEVENT (EV_ENCODE_STARTENCODE_CMD , OUTER_CODEC_ENTRY + 4);
// ֹͣ��������				| EncoderID + MediaType(MT_AUDIO/MT_VIDEO/MT_AV) | MTCTRL->CODEC
OSPEVENT (EV_ENCODE_STOPENCODE_CMD	, OUTER_CODEC_ENTRY + 5);
// ��ʼ��������				| EncoderID + MediaType(MT_AUDIO/MT_VIDEO/MT_AV) + rtcp(TPROADDR) + rtp(TPROADDR)	| MTCTRL->CODEC
OSPEVENT (EV_ENCODE_STARTSEND_CMD	, OUTER_CODEC_ENTRY + 6);
// ֹͣ��������				| EncoderID + MediaType(MT_AUDIO/MT_VIDEO/MT_AV) + rtcp(TPROADDR) + rtp(TPROADDR)	| MTCTRL->CODEC
OSPEVENT (EV_ENCODE_STOPSEND_CMD	, OUTER_CODEC_ENTRY + 7);
// ���÷����ط�����			| EncoderID + _TSENDRTCFG
OSPEVENT (EV_ENCODE_SETRETRAN_CMD	, OUTER_CODEC_ENTRY + 8);
// ����ͼ����������			| EncoderID + _TIMAGEQUAL
OSPEVENT (EV_ENCODE_SETIMAGEQUAL_CMD	, OUTER_CODEC_ENTRY + 9);
// ��������					| 1BYTE(MT_ENABLE/MT_DISABLE)	| UI->MTCTRL
// ��������					| EncoderID + 1BYTE(MT_ENABLE/MT_DISABLE)	| MTCTRL->CODEC
OSPEVENT (EV_ENCODE_MUTE_CMD		, OUTER_CODEC_ENTRY + 10);
// ���ñ�������				| 1BYTE(vol)			| UI->MTCTRL
// ���ñ�������				| EncoderID + 1BYTE(vol)| MTCTRL->CODEC
OSPEVENT (EV_ENCODE_SETVOLUMN_CMD	, OUTER_CODEC_ENTRY + 11);

// ��������������			| 1BYTE,DecoderID	| MTCTRL->CODEC
OSPEVENT (EV_DECODE_CREATE_REQ		, OUTER_CODEC_ENTRY + 12);
// ����������Ӧ��			| DecoderID + Result(1BYTE,MT_OK:�ɹ� MT_ERR:ʧ��)	| CODEC->MTCTRL
OSPEVENT (EV_DECODE_CREATE_RSP		, OUTER_CODEC_ENTRY + 13);
// ���ý������				| DecoderID + MediaType(MT_AUDIO/MT_VIDEO/MT_AV)  + _TADECPARAM/_TVDECPARAM	| MTCTRL->CODEC
OSPEVENT (EV_DECODE_SETPARAM_CMD	, OUTER_CODEC_ENTRY + 14);
// ��ʼ��������				| 2BYTE,DecoderID + MediaType(MT_AUDIO/MT_VIDEO/MT_AV)	| MTCTRL->CODEC
OSPEVENT (EV_DECODE_STARTDECODE_CMD	, OUTER_CODEC_ENTRY + 15);
// ֹͣ��������				| 2BYTE,DecoderID + MediaType(MT_AUDIO/MT_VIDEO/MT_AV)	| MTCTRL->CODEC
OSPEVENT (EV_DECODE_STOPDECODE_CMD	, OUTER_CODEC_ENTRY + 16);
// ��ʼ��������				| DecoderID + MediaType(MT_AUDIO/MT_VIDEO/MT_AV) + rtcp(TPROADDR) + rtp(TPROADDR)	| MTCTRL->CODEC
OSPEVENT (EV_DECODE_STARTRECV_CMD	, OUTER_CODEC_ENTRY + 17);
// ֹͣ��������				| 2BYTE,DecoderID + MediaType(MT_AUDIO/MT_VIDEO/MT_AV)	| MTCTRL->CODEC
OSPEVENT (EV_DECODE_STOPRECV_CMD	, OUTER_CODEC_ENTRY + 18);
// ͼ�񶳽�					| 1BYTE,DecoderID				| MTCTRL->CODEC
OSPEVENT (EV_DECODE_FREEZE_CMD		, OUTER_CODEC_ENTRY + 19);
// ͼ�����					| 1BYTE,DecoderID				| MTCTRL->CODEC
OSPEVENT (EV_DECODE_UPDATE_CMD		, OUTER_CODEC_ENTRY + 20);
// ���ý����ش�����			| 1BYTE,DecoderID + _RECVRTCFG
OSPEVENT (EV_DECODE_SETRETRAN_CMD	, OUTER_CODEC_ENTRY + 21);

// ��������					| 1BYTE(MT_ENABLE/MT_DISABLE)	| UI->MTCTRL
// ��������					| 2BYTE,DecoderID + 1BYTE(MT_ENABLE/MT_DISABLE)	| MTCTRL->CODEC
OSPEVENT (EV_DECODE_QUIET_CMD		, OUTER_CODEC_ENTRY + 22);
// ��������					| 1BYTE(vol)	| UI->MTCTRL
// ��������					| 2BYTE,DecoderID + 1BYTE(vol)	| MTCTRL->CODEC
OSPEVENT (EV_DECODE_SETVOLUMN_CMD	, OUTER_CODEC_ENTRY + 23);
// �ڶ�·��Ƶ�Ľ�����IDָʾ | 1BYTE(Decoder ID) + 1BYTE(MT_START|MT_STOP)
OSPEVENT (EV_DECODE_DUALVIDEO_IND	, OUTER_CODEC_ENTRY + 24);
// ��ʼת������				| DecoderID + MediaType(MT_AUDIO/MT_VIDEO) + rtcp(TPROADDR) + rtp(TPROADDR)	| MTCTRL->CODEC
OSPEVENT (EV_DECODE_STARTFWD_CMD	, OUTER_CODEC_ENTRY + 25);
// ֹͣת������				| DecoderID + MediaType(MT_AUDIO/MT_VIDEO) + rtcp(TPROADDR) + rtp(TPROADDR)	| MTCTRL->CODEC
OSPEVENT (EV_DECODE_STOPFWD_CMD		, OUTER_CODEC_ENTRY + 26);
//���û�����������			| _TAEC							| MTCTRL->CODEC
OSPEVENT (EV_AEC_SETPARAM_CMD		, OUTER_CODEC_ENTRY + 27);
//������Ϣ����				| _TSNAPINFO	 | MTCTRL->CODEC
OSPEVENT( EV_OUT_SNAPSHOTINFO_REQ	, OUTER_CODEC_ENTRY + 28);
//������Ϣָʾ				| _TSNAPINFO	 | MTCTRL->MTC
OSPEVENT( EV_OUT_SNAPSHOTINFO_IND	, OUTER_CODEC_ENTRY + 29);
//�����������				| NULL			 | MTC->MTCTRL
OSPEVENT( EV_OUT_CLEARSNAP_CMD		,OUTER_CODEC_ENTRY + 30);
// �ϱ���Ƶ���������		|_TBITRATE	| codec->MTCTRL
OSPEVENT (EV_CODEC_BITRATE_IND		, OUTER_CODEC_ENTRY + 31);
// �ϱ�MAP״̬				|_TMAPSTATUS		| codec->MTCTRL
OSPEVENT (EV_CODEC_MAPSTATUS_IND	, OUTER_CODEC_ENTRY + 32);
// ���л�����(2�ֽ�:		| DecoderID + ��/�ر�/�ƶ�/�л�)
OSPEVENT (EV_CODEC_PIPOPT_CMD		, OUTER_CODEC_ENTRY + 33);
// Codecͳ����Ϣ����		|(1�ֽ� MT_ENABLE/MT_DISABLE)
OSPEVENT (EV_CODEC_STATISTIC_REQ	, OUTER_CODEC_ENTRY + 34);
// Codecͳ����Ϣ�ϱ�		|_TCODECSTATISTIC
OSPEVENT (EV_CODEC_STATISTIC_IND	, OUTER_CODEC_ENTRY + 35);
// ��Ƶ��������				|	(1�ֽ� MT_ENABLE/MT_DISABLE)
OSPEVENT (EV_CODEC_AUDIOPOWER_REQ	, OUTER_CODEC_ENTRY + 36);
// ��Ƶ�����ϱ�				|	_TAUDIOPOWER
OSPEVENT (EV_CODEC_AUDIOPOWER_IND	, OUTER_CODEC_ENTRY + 37);
// �������					|	ָ�����ȵ�����
OSPEVENT (EV_ENCODE_SYSPWD_CMD	, OUTER_CODEC_ENTRY + 38);
// ��Ƶ�����ϱ�				|	_TAUDIOPOWER
OSPEVENT (EV_DECODE_SYSPWD_CMD	, OUTER_CODEC_ENTRY + 39);
// �ϱ�����				   |������ID(1�ֽ�)	| codec->MTCTRL
OSPEVENT (EV_CODEC_LOSTPACK_IND			, OUTER_CODEC_ENTRY + 40);

// �����ֱ���
OSPEVENT (EV_CHANGE_VIDPARM_IND			, OUTER_CODEC_ENTRY + 41);

// ��ȡ�ڵ���������λ��
OSPEVENT (EV_GET_ROLLCALL_WAITPOS_IND			, OUTER_CODEC_ENTRY + 42);

// �����������
OSPEVENT (EV_ADJUST_ENCPARM_IND			, OUTER_CODEC_ENTRY + 43);


///////////////////////////////�ն�������Ϣ//////////////////////////////////

//������Ϣָʾ				| _TTERCFG						| MTCTRL->UI
OSPEVENT (EV_CFG_LOCALINFO_IND		, OUTER_CFG_ENTRY + 1);
//������������				| _TTERCFG						| UI->MTCTRL
OSPEVENT (EV_CFG_LOCALINFO_CMD		, OUTER_CFG_ENTRY + 2);
//�ָ���������Ĭ��ֵ		| NULL							| UI->MTCTRL
OSPEVENT (EV_CFG_LOCALINFODEF_CMD	, OUTER_CFG_ENTRY + 3);

//������Ϣָʾ				| _TNETCFG						| MTCTRL->UI
OSPEVENT (EV_CFG_NET_IND			, OUTER_CFG_ENTRY + 4);
//������������				| _TNETCFG						| UI->MTCTRL
OSPEVENT (EV_CFG_NET_CMD			, OUTER_CFG_ENTRY + 5);
//�ָ���������Ĭ��ֵ		| NULL							| UI->MTCTRL
OSPEVENT (EV_CFG_NETDEF_CMD			, OUTER_CFG_ENTRY + 6);


//��������ָʾ				| _TCALLCFG						| MTCTRL->UI
OSPEVENT (EV_CFG_CALL_IND			, OUTER_CFG_ENTRY + 7);
//������������				| _TCALLCFG						| UI->MTCTRL
OSPEVENT (EV_CFG_CALL_CMD			, OUTER_CFG_ENTRY + 8);
//�ָ���������Ĭ��ֵ		| NULL							| UI->MTCTRL
OSPEVENT (EV_CFG_CALLDEF_CMD		, OUTER_CFG_ENTRY + 9);

//��Ƶ����ָʾ				| Index(1�ֽ�) + _TVENCPARAM + _TVDECPARAM		| MTCTRL->UI
OSPEVENT (EV_CFG_VIDEO_IND			, OUTER_CFG_ENTRY + 10);
//��Ƶ��������				| Index(1�ֽ�) + _TVENCPARAM + _TVDECPARAM		| UI->MTCTRL
OSPEVENT (EV_CFG_VIDEO_CMD			, OUTER_CFG_ENTRY + 11);
//�ָ���Ƶ����Ĭ��ֵ		| Index(1�ֽ�)									| UI->MTCTRL
OSPEVENT (EV_CFG_VIDEODEF_CMD		, OUTER_CFG_ENTRY + 12);

//��Ƶ����ָʾ				| _TAENCPARAM + _TADECPARAM		| MTCTRL->UI
OSPEVENT (EV_CFG_AUDIO_IND			, OUTER_CFG_ENTRY + 13);
//��Ƶ��������				| _TAENCPARAM + _TADECPARAM		| UI->MTCTRL
OSPEVENT (EV_CFG_AUDIO_CMD			, OUTER_CFG_ENTRY + 14);
//�ָ���Ƶ����Ĭ��ֵ		| NULL							| UI->MTCTRL
OSPEVENT (EV_CFG_AUDIODEF_CMD		, OUTER_CFG_ENTRY + 15);

//����ͷ����ָʾ			| 1BYTE(����ͷ����,1~6) + _TDEVCFG����	| MTCTRL->UI
OSPEVENT (EV_CFG_CAMERA_IND			, OUTER_CFG_ENTRY + 16);
//����ͷ��������			| _TDEVCFG						| UI->MTCTRL
OSPEVENT (EV_CFG_CAMERA_CMD			, OUTER_CFG_ENTRY + 17);
//�ָ�����ͷ����Ĭ��ֵ		| NULL							| UI->MTCTRL
OSPEVENT (EV_CFG_CAMERADEF_CMD		, OUTER_CFG_ENTRY + 18);

//��������ָʾ				| _TDEVCFG						| MTCTRL->UI
OSPEVENT (EV_CFG_MATRIX_IND			, OUTER_CFG_ENTRY + 19);
//������������				| _TDEVCFG						| UI->MTCTRL
OSPEVENT (EV_CFG_MATRIX_CMD			, OUTER_CFG_ENTRY + 20);
//�ָ���������Ĭ��ֵ		| NULL							| UI->MTCTRL
OSPEVENT (EV_CFG_MATRIXDEF_CMD		, OUTER_CFG_ENTRY + 21);

//��ʾ����ָʾ				| _TOSDCFG						| MTCTRL->UI
OSPEVENT (EV_CFG_OSD_IND			, OUTER_CFG_ENTRY + 22);
//��ʾ��������				| _TOSDCFG						| UI->MTCTRL
OSPEVENT (EV_CFG_OSD_CMD			, OUTER_CFG_ENTRY + 23);
//�ָ���ʾ����Ĭ��ֵ		| NULL							| UI->MTCTRL
OSPEVENT (EV_CFG_OSDDEF_CMD			, OUTER_CFG_ENTRY + 24);

//pccodec����ָʾ			| _PCCODEC					    | MTCTRL->UI(Windows)
OSPEVENT( EV_CFG_PCCODEC_IND		, OUTER_CFG_ENTRY + 25);
//pccodec��������			| _PCCODEC						| UI->MTCTRL(Windows)
OSPEVENT( EV_CFG_PCCODEC_CMD		, OUTER_CFG_ENTRY + 26);
//�ָ�pccodec����Ĭ��ֵ		| NULL							| UI->MTCTRL(Windows)
OSPEVENT( EV_CFG_PCCODEDEF_CMD		, OUTER_CFG_ENTRY + 27);

//AEC����ָʾ				| _TAEC							| MTCTRL->UI
OSPEVENT( EV_CFG_AEC_IND			, OUTER_CFG_ENTRY + 31);
//AEC��������				| _TAEC							| UI->MTCTRL
OSPEVENT( EV_CFG_AEC_CMD			, OUTER_CFG_ENTRY + 32);
//�ָ�AECĬ������			| NULL							| UI->MTCTRL
OSPEVENT( EV_CFG_AECDEF_CMD			, OUTER_CFG_ENTRY + 33);

//�����ش�����ָʾ			| _TSENDRTCFG					| MTCTRL->UI
OSPEVENT( EV_CFG_SENDRT_IND			, OUTER_CFG_ENTRY + 34);
//�����ش���������			| _TSENDRTCFG					| UI->MTCTRL
OSPEVENT( EV_CFG_SENDRT_CMD			, OUTER_CFG_ENTRY + 35);
//�ָ������ش�Ĭ������		| NULL							| UI->MTCTRL
OSPEVENT( EV_CFG_SENDRTDEF_CMD		, OUTER_CFG_ENTRY + 36);

//�����ش�����ָʾ			| _TRECVRTCFG					| MTCTRL->UI
OSPEVENT( EV_CFG_RECVRT_IND			, OUTER_CFG_ENTRY + 37);
//�����ش���������			| _TRECVRTCFG					| UI->MTCTRL
OSPEVENT( EV_CFG_RECVRT_CMD			, OUTER_CFG_ENTRY + 38);
//�ָ������ش�Ĭ������		| NULL							| UI->MTCTRL
OSPEVENT( EV_CFG_RECVRTDEF_CMD		, OUTER_CFG_ENTRY + 39);
//broadcast panel��������	| _TPANELCFG					| UI->MTCTRL
OSPEVENT( EV_CFG_CONFPANEL_CMD		, OUTER_CFG_ENTRY + 40);
//broadcast panel������Ϣָʾ	| _TPANELCFG					| MTCTRL->UI
OSPEVENT( EV_CFG_CONFPANEL_IND		, OUTER_CFG_ENTRY + 41);


//��Ƶ�������ָʾ			| _TVOUT						| MTCTRL->UI
OSPEVENT (EV_CFG_VIDEOOUT_IND		, OUTER_CFG_ENTRY + 46);
//��Ƶ�����������			| _TVOUT						| UI->MTCTRL
OSPEVENT (EV_CFG_VIDEOOUT_CMD		, OUTER_CFG_ENTRY + 47);

//�ָ��������õ�Ĭ��ֵ		| NULL							| UI->MTCTRL
OSPEVENT (EV_CFG_RESUMEALL_CMD		, OUTER_CFG_ENTRY + 48);
//�������������Ϣ			| NULL							| UI->MTCTRL
OSPEVENT( EV_CFG_GETALL_REQ			, OUTER_CFG_ENTRY + 49);

// ͼ������ָʾ				|_TIMAGEQUAL
OSPEVENT (EV_CFG_IMAGEQUALITY_IND			, OUTER_CFG_ENTRY + 50);
// ͼ����������				|_TIMAGEQUAL
OSPEVENT (EV_CFG_IMAGEQUALITY_CMD			, OUTER_CFG_ENTRY + 51);
// ͼ�������ָ�Ĭ��ֵ		|_TIMAGEQUAL
OSPEVENT (EV_CFG_IMAGEQUALDEF_CMD			, OUTER_CFG_ENTRY + 52);

// SNMP����ָʾ				|_TSNMPCFG
OSPEVENT (EV_CFG_SNMPCFG_IND			, OUTER_CFG_ENTRY + 53);
// SNMP��������				|_TSNMPCFG
OSPEVENT (EV_CFG_SNMPCFG_CMD			, OUTER_CFG_ENTRY + 54);
// SNMP���ûָ�Ĭ��ֵ		|_TSNMPCFG
OSPEVENT (EV_CFG_SNMPCFGDEF_CMD			, OUTER_CFG_ENTRY + 55);

// ��������ָʾ					|_TSERCFG
OSPEVENT (EV_CFG_SERIAL_IND			, OUTER_CFG_ENTRY + 59);
// ������������					|_TSERCFG
OSPEVENT (EV_CFG_SERIAL_CMD			, OUTER_CFG_ENTRY + 60);
// �������ûָ�Ĭ��ֵ			|_TSERCFG
OSPEVENT (EV_CFG_SERIALDEF_CMD			, OUTER_CFG_ENTRY + 61);



// ���ñ����ʽ				| 1BYTE MediaType(MT_AUDIO/MT_VIDEO) + 1BYTE type
OSPEVENT( EV_CFG_SETTYPE_CMD			, OUTER_CFG_ENTRY + 70);
// ���ñ�������				| 2BYTE ����
OSPEVENT( EV_CFG_SETBITRATE_CMD			, OUTER_CFG_ENTRY + 71);


///////////////////////////////   ������Ϣ  //////////////////////////////////

//�ն���ʾ��Ϣ				| _TMTNOTE						| MTCTRL->UI
OSPEVENT (EV_OUT_MTNOTE_IND			, OUTER_MISC_ENTRY + 1);
//�ն�״̬��ѯ				| NULL							| UI->MTCTRL
OSPEVENT (EV_OUT_MTSTATUS_REQ		, OUTER_MISC_ENTRY + 2);
//�ն�״̬�ϱ�				| _TTERSTATUS					| MTCTRL->UI
OSPEVENT (EV_OUT_MTSTATUS_IND		, OUTER_MISC_ENTRY + 3);
//�����Ի�					| 2BYTE, MediaType(MT_AUDIO/MT_VIDEO/MT_AV) + Action(MT_START:��ʼ  MT_STOP:ֹͣ) | UI->MTCTRL
OSPEVENT (EV_OUT_INNERLOOP_CMD		, OUTER_MISC_ENTRY + 4);
//�⻷����					| 1BYTE(MT_START:��ʼ MT_STOP:ֹͣ)			| UI->MTCTRL
OSPEVENT (EV_OUT_OUTERLOOP_CMD		, OUTER_MISC_ENTRY + 5);
//������Ϣ					| '\0'�������ַ���				| MTCTRL->UI
OSPEVENT (EV_OUT_ROLLMSG_CMD	    , OUTER_MISC_ENTRY + 6);
//����OSD��־				| 1BYTE,��־��					| UI->MTCTRL
OSPEVENT (EV_OUT_HIDETAG_CMD	    , OUTER_MISC_ENTRY + 7);
//��ʾOSD��־				| 1BYTE,��־��					| UI->MTCTRL
OSPEVENT (EV_OUT_SHOWTAG_CMD		, OUTER_MISC_ENTRY + 8);
//����CodecManagerģ��      | NULL							| UI->MTCTRL
OSPEVENT( EV_CODEC_ENCAP_MODULE_START		, OUTER_MISC_ENTRY + 9 );
// Э��ջ��ʼ������ϱ�		| 1�ֽ� MT_OK/MT_ERR
OSPEVENT( EV_OUT_STACKINIT_IND		, OUTER_MISC_ENTRY + 10 );

// MTC����ʼ����ý����	| MTC->MTCTRL
// 1BYTE(����:MT_LOCAL Զ��:MT_REMOTE) + TIPADDR(��ƵRTP��ַ,��Ƶ�ڴ˻����ϵ���) 
OSPEVENT( EV_MTC_STARTRECV_CMD		, OUTER_MISC_ENTRY + 11);
// MTC����ֹͣ����ý����	| MTC->MTCTRL
// 1BYTE(����:MT_LOCAL Զ��:MT_REMOTE)
OSPEVENT( EV_MTC_STOPRECV_CMD		, OUTER_MISC_ENTRY + 12);

// MTC����ʼ���͵ڶ�·��Ƶ| NULL						 | MTC->MTCTRL
OSPEVENT( EV_MTC_DUALVIDEOSTART_REQ	, OUTER_MISC_ENTRY + 13);
// ˫��Ƶ����ʼӦ��			|							 | MCTRL->MTC
// �ɹ�:1BYTE(MT_OK) + TIPADDR(���������ĵ�ַ)	ʧ��:1BYTE(MT_ERR)
OSPEVENT( EV_MTC_DUALVIDEOSTART_RSP	, OUTER_MISC_ENTRY + 14);

// MTC����ֹͣ���͵ڶ�·��Ƶ| NULL						 | MTC->MTCTRL
OSPEVENT( EV_MTC_DUALVIDEOSTOP_REQ	, OUTER_MISC_ENTRY + 15);
// ˫��Ƶ��ֹͣӦ��			| 1BYTE(MT_OK/MT_ERR)		 | MCTRL->MTC
OSPEVENT( EV_MTC_DUALVIDEOSTOP_RSP	, OUTER_MISC_ENTRY + 16);
// ˫������״ָ̬ʾ			| 1BYTE(MT_ENABLE/MT_DISABLE)
OSPEVENT( EV_DUALVID_CONNECT_IND	, OUTER_MISC_ENTRY + 17);

//˫������������״̬֪ͨ    | 1BYTE(MT_ENABLE/MT_DIABLE) + TIPADDR(DualCodce���͵�RTCP��ַ) + TIPADDR(DualCodec������ʼ��ַ)	 
//							|  DEVCTRL->MTCTRL
OSPEVENT( EV_OUT_DUALENCCONNECT_IND	, OUTER_MISC_ENTRY + 18);
// ˫��Ƶ����������			| 1BYTE(MT_START|MT_STOP)	 | VxUI->MTCTRL
//							| 1BYTE(MT_START) + TIPADDR(��ƵRTP��ַ) | MTCTRL->DEVCTRL
//							| 1BYTE(MT_STOP)			 | MTCTRL->DEVCTRL
OSPEVENT( EV_OUT_DUALVIDEO_REQ	, OUTER_MISC_ENTRY + 19);
// ˫��Ƶ������Ӧ��			| 1BYTE(MT_OK|MT_ERR)		 | DEVCTRL->MTCTRL,MTCTRL->VxUI
OSPEVENT( EV_OUT_DUALVIDEO_RSP	, OUTER_MISC_ENTRY + 20);
//˫��Ƶ����������			| 1BYTE(MT_START/MT_STOP)	 | MTCTRL->DEVCTRL
OSPEVENT( EV_OUT_DUALVIDEORCV_CMD,OUTER_MISC_ENTRY + 21);
// ͼ�����( 1�ֽ�: MT_LOCAL/MT_REMOTE, 1�ֽ� ����:RESOLUTION_TEST/COLOR_TEST/GRAY_TEST/TEST_CLOSE )
OSPEVENT (EV_OUT_IMAGETEST_CMD			, OUTER_MISC_ENTRY + 22);
// ����С�����/�ر�(1�ֽ�:MT_ENABLE/MT_DISABLE)
OSPEVENT (EV_OUT_SMALLLOCAL_CMD			, OUTER_MISC_ENTRY + 23);
// ����С����ʹ��״̬�ϱ�(1�ֽ�:MT_ENABLE/MT_DISABLE)
OSPEVENT (EV_OUT_SMALLLOCAL_IND			, OUTER_MISC_ENTRY + 24);
// ϵͳԿ������					|NULL				|UI->MTCTRL
OSPEVENT (EV_OUT_SYSPWDGEN_CMD				, OUTER_MISC_ENTRY + 25);
// ϵͳԿ�ױ���					|1BYTE(MT_ENABLE/MT_DISABLE)				|UI->MTCTRL
OSPEVENT (EV_OUT_SYSPWDSAVE_CMD				, OUTER_MISC_ENTRY + 26);
// ��Կ����ָʾ					|8�ֽڵĹ�Կ		|MTCTRL->UI
OSPEVENT (EV_OUT_SYSPUBPWD_IND			, OUTER_MISC_ENTRY + 27);


 


////////////////////////// VxWorks UI �ڲ���Ϣ(50)  /////////////////////////////
//OSPEVENT (EV_VXUI_MSG_TYPE		, OUTER_VXUI_ENTRY + 1);

// ��������(1�ֽ�: ����)
OSPEVENT (EV_UI_KEYPRESS_IND			, OUTER_VXUI_ENTRY + 1);
// ��������(1�ֽ�: ����)
OSPEVENT (EV_UI_KEYRELEASE_IND			, OUTER_VXUI_ENTRY + 2);
// ����ҳ������Ϣ(1�ֽ�:����ҳID)
OSPEVENT (EV_UI_PROPERTY_UPDATE			, OUTER_VXUI_ENTRY + 3);
// ��������
OSPEVENT (EV_UICODEC_SNAPSHOT_CMD			, OUTER_VXUI_ENTRY + 4);
// ���ͱ�����Ƶ(1�ֽ�MT_ENABLE/MT_DISABLE)
OSPEVENT (EV_UICODEC_SENDLOCAL_CMD			, OUTER_VXUI_ENTRY + 5);
// �˵�������Ϣ
OSPEVENT (EV_MENU_RESET_CMD                 , OUTER_VXUI_ENTRY + 6);
// �û�����ͼƬ֪ͨ
OSPEVENT (EV_USERLBL_UPDATE_IND             , OUTER_VXUI_ENTRY + 7);
// �û�������ʱ��֪ͨ
OSPEVENT (EV_UISTARTUP_TIMER_IND            , OUTER_VXUI_ENTRY + 8);
// �Ի�ʹ��֪ͨ(1�ֽ�MT_ENABLE/MT_DISABLE)
OSPEVENT (EV_LOOP_TEST_IND                  , OUTER_VXUI_ENTRY + 9);

////////////////////////// Windows UI �ڲ���Ϣ(50) //////////////////////////////

//////////////////////////��ʱ����Ϣ����(100)///////////////////////////////////////

//��ѯ��ʱ��
OSPEVENT( TIMER_CTRL_POLLING		, EV_TIMER_BGN + 1 );
//TPS_ROUND_TRIP
OSPEVENT( TIMER_ROUND_TRIP			, EV_TIMER_BGN + 2 );
//TPS_GUARD
OSPEVENT( TIMER_GUARD				, EV_TIMER_BGN + 3 );
//���鿪ʼ��ⶨʱ��(TPS_CONFENTRY)
OSPEVENT( TIMER_CONFENTRY			, EV_TIMER_BGN + 4 );
//flowctrl��ʱ��					| hsChan
OSPEVENT( TIMER_FLOWCTRL				, EV_TIMER_BGN + 5 );
//h281�ط���ʱ��
OSPEVENT( TIMER_H281_CONTINUE		, EV_TIMER_BGN + 6 );
//��·�����ⶨʱ��
OSPEVENT( TIMER_CHANCHK_BANDWIDTH	, EV_TIMER_BGN + 7 );
//�����������
OSPEVENT( TIMER_COM_RECONNECT	    , EV_TIMER_BGN + 9 );	
//ǿ�ƹؼ�֡
OSPEVENT( TIMER_VIDEO_UPDATE        , EV_TIMER_BGN + 10 );   


//����������ʱ��(TPS_DEV_RECONNECT)
OSPEVENT( TIMER_CAMERA_RECONNECT	, EV_TIMER_BGN + 31 );
OSPEVENT( TIMER_MATRIX_RECONNECT	, EV_TIMER_BGN + 32 );
OSPEVENT( TIMER_SHOW_VOLUMNE		, EV_TIMER_BGN + 33 );	// ��ʾ����	
OSPEVENT( TIMER_SHOW_CODEC			, EV_TIMER_BGN + 34 );	// ��ʾcodecͳ����Ϣ
OSPEVENT( TIMER_VIDEO_BITRATE		, EV_TIMER_BGN + 35 );	// �ϱ����������
OSPEVENT( TIMER_QUICKPHOTO_TIP		, EV_TIMER_BGN + 36 );	// ����
OSPEVENT( TIMER_SMS_PAGETITLE		, EV_TIMER_BGN + 37 );	// 
OSPEVENT( TIMER_CONFEND_INS 		, EV_TIMER_BGN + 38 );
OSPEVENT( TIMER_INPUTPWD_DUR 		, EV_TIMER_BGN + 39 );
OSPEVENT( TIMER_MAP_STATUS	 		, EV_TIMER_BGN + 40 );	// map�쳣�澯
OSPEVENT( TIMER_AUDIO_POWER	 		, EV_TIMER_BGN + 41 );	// ��Ƶ�����ϱ�
OSPEVENT( TIMER_SNAPSHOT_INFO	 	, EV_TIMER_BGN + 42 );	// ������Ϣ�ϱ�
OSPEVENT( TIMER_HOTKEY_INFO	 	    , EV_TIMER_BGN + 43 );	// ��ʾͣ��ʱ��


// ֻ����OSP��Ϣ����
// MTC����ͼƬ�ļ�			| ͼƬ�ļ�			|MTCTRL->MTC
OSPEVENT( EV_MTC_LABELBMP_IND	, EV_OUTEROSP_BGN + 1 );


#endif


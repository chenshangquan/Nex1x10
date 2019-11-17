#ifndef _QUICKSHARE_H_
#define _QUICKSHARE_H_
///////////////////////////���hidͨ����Ϣ����/////////////////////////////////////////////
//��pcͨ�����
#define Ev_NV_StartProjecting_Ntf   		0x00  	/*��ʼͶ��*/
#define Ev_NV_StopProjecting_Cmd    		0x01  	/*ֹͣͶ��*/
#define Ev_NV_NetConnectStatus_Ntf  		0x03  	/*��������״̬���μ�em_NET_STATUSö��*/
#define Ev_NV_UserInfo_Cmd         			0x04   	/*����PC�û������μ�tagUserInfo�ṹ��*/
#define Ev_NV_UserInfo_Nty         			0x09	/*Ͷ�����յ��û����Ļظ� */
#define Ev_NV_KeepWidthHeight_Cmd   		0x05   	/*���ֿ�߱ȣ�1:����,0:�����֣�Ĭ�ϱ���*/
#define Ev_NV_ImaxRequstKeyFrame_Ntf		0x06	/*Imax����ؼ�֡*/
#define Ev_NV_ImaxStopPic_Ntf				0x07	/*Imax����ֹͣͶ��*/
#define Ev_NV_WidthHeightFrame_Cmd			0x13	/*�ֱ��ʺ�֡��*/
#define Ev_NV_RequestTerminalType_Ntf		0x15	/*quickshare����Զ�����(pc or imix)*/
#define Ev_NV_TerminalType_PC_Cmd			0x16	/*�Զ�������PC*/
#define Ev_NV_REQUSTPCNAME_Ntf				0x17	/*�����û���*/
#define Ev_NV_WidthHeightFrame_Ntf			0x19	/*�ظ���PC�ֱ��ʺ�֡��*/
#define Ev_NV_PCDisconnet_Cmd				0x20	/*PC����ʱ֪ͨͶ������Ϣ*/
#define Ev_NV_PCDisconnet_Ntf				0x21	/*PC����ʱ�ظ�PC��Ϣ*/
#define Ev_NV_BroadCastPPT_Cmd				0x22	/*PC����PPT��Ϣ֪ͨ*/
#define Ev_NV_BroadCastPPT_Ntf				0x23	/*PC����PPT�ظ�PC��Ϣ*/
//#define Ev_NV_PCStopBroadCastPPT_Cmd		0x24	/*PCֹͣ����PPT��Ϣ֪ͨ*/
#define Ev_NV_UpgradeQuickShare_Ntf			0x25	/*֪ͨPC��������Ͷ����*/
#define Ev_NV_SendPCHeatMsg_Ntf				0x26	/*����������Ϣ��PC*/
#define Ev_NV_SendPCHeatMsg_Cmd				0x27	/*PC�ظ�������Ϣ*/
#define Ev_NV_PCSendBusiness_Cmd			0x28	/*PC����ҵ����Ϣ*/
#define Ev_NV_PCSendBusiness_Ntf			0x29	/*ҵ��ظ�PC��Ϣ*/
#define Ev_NV_SendPCTerName_Ntf			    0x30	/*֪ͨPC�����ն˱���*/
#define Ev_Nv_NeedCodeConsult_Ntf           0x31    /*֪ͨPC������Ҫ����Э��*/
#define Ev_Nv_CodeFormat_Cmd                0x32    /*֪ͨPC��������Ƶ��������*/
#define Ev_Nv_CodeResolution_Cmd            0x33    /*֪ͨPC�������ֱ���*/
#define Ev_Nv_CodeFrameRate_Cmd             0x34    /*֪ͨPC�������֡��*/
#define Ev_Nv_CodeRate_Cmd                  0x35    /*֪ͨPC���������*/
#define Ev_Nv_QKPidType_Cmd                 0x36    /*֪ͨPC���浱ǰͶ��������*/
#define Ev_Nv_QKNotView_Cmd                 0x37    /*֪ͨPC���浱ǰͶ��������Ͷ���������ն˻����в���Ͷ����*/

//��Imax������
#define Ev_NV_RequstIPAndSSID_Req			0x08	/*quichshare����Imax����ip��ssid*/
#define Ev_NV_ImaxSendIP_Ntf				0x39	/*Imax����ip��quickshare*/
#define Ev_NV_ImaxSendSSID_Ntf				0x10	/*Imax��������·������Ϣ��quickshare*/
#define Ev_NV_RequstOpenWps_Req				0x11	/*quickshare������WPS����*/
#define Ev_NV_NotifyImaxWifiConnect_Req		0x12	/*quickshare����wifi���ӳɹ���Ϣ*/
#define Ev_NV_NotifyImaxWifiDisConnect_Ntf	0x14	/*quickshare����wifi����ʧ����Ϣ*/
#define Ev_NV_TerminalType_IMIX_Cmd			0x61	/*�Զ�������IMIX*/
#define Ev_NV_RequestUpdata_Req				0x18	/*quickshare��������*/
#define Ev_NV_StartUpdata_Ntf				0x62	/*quickshare��ʼ����*/
#define Ev_NV_NoNeedUpdata_Ntf				0x63	/*quickshare����Ҫ����*/
#define EV_NV_ImixSendWpsConnect_Rsp        0x64    /*imix�յ���Գɹ���ʧ�ܺ�Ļ�Ӧ��Ϣ*/
#define Ev_NV_SendDevLog_Req				0x65	/*quickshare����������log*/

////////////////////////////////////////////end/////////////////////////////////////////////

#define DEV_NAME                    "/dev/hidg0"  //�豸����
#define HID_MAX_READLENTH			2048
#define USERNAME_MAX_LENGTH         64
#define PC_SENDDATA_LENGTH			496
#define IMIX_CONTROLMSG_LENGTH		15

//#define SEND_TYPE_IMAX			4
#define SEND_TYPE_VIDEO 			8
#define SEND_TYPE_AUDIO				7
#define SEND_TYPE_CMD				6
#define SEND_TYPE_CMD_CHAR		    '6'

typedef enum em_NET_STATUS
{
	NET_STATUS_CONNECTING = 0x00,   //���ڵ�¼imix
	NET_STATUS_CONNECTED,           //������
	NET_STATUS_PROJECTING,          //����Ͷ��
	NET_STATUS_NET_DISCONNECTED,    //��wifi�������ӶϿ�
	NET_STATUS_NO_NETWORK,          //������
	NET_STATUS_NO_MATCH,            //Ͷ����wifiģ��δ�����ȵ㣬��ʾ���
	NET_STATUS_ENOUGHNUM,           //ImixͶ������
	NET_STATUS_RESETQUICKSHARE,     //���²��Ͷ����,�ж�Ϊ������ʱ֪ͨ����Ϣ
	NET_STATUS_TER_DISCONNECTED,    //�������ӵģ������ն˶Ͽ�����
	NET_STATUS_FIND_SSID_FAIL,      //�����ȵ�ʧ�ܣ�Ͷ����wifiģ���ѱ����ȵ㣬��δ�ҵ��ȵ㣩
	NET_STATUS_FIND_TER_FAIL,       //����wifi��δ���ҵ��ն�
	NET_STATUS_RECONNECTTER_FAIL,   //�������ӵģ������ն�ʧ��
}NET_STATUS;

typedef enum em_PPT_STATUS
{
	PPT_STATUS_START = 0x01,   		//��ʼ����ppt
	PPT_STATUS_START_NTF,         	//�ظ�PC��ʼ����ppt
	PPT_STATUS_STOP,           		//ֹͣ����ppt
	PPT_STATUS_STOP_NTF,			//�ظ�PCֹͣ����ppt
	PPT_STATUS_NEXTPAGE,         	//ppt������һҳ
	PPT_STATUS_RPEVIOUSPAGE,        //ppt������һҳ
}PPT_STATUS;

//��Ƶ��ʽ
typedef enum em_CodeVid_Format
{
	em_VID_FORMAT_H265 = 0x01,   		
	em_VID_FORMAT_H264,         	    
	em_VID_FORMAT_PROFILE,              
	em_VID_FORMAT_MPEG,			        
	em_VID_FORMAT_H263,         	
	em_VID_FORMAT_H263PLUS,       
	em_VID_FORMAT_H261,
}EmCodeVidFormat;

//��Ƶ��ʽ
typedef enum em_CodeAud_Format
{
	em_AUD_FORMAT_OPUS = 0x01,   		
	em_AUD_FORMAT_G711A,         	    
	em_AUD_FORMAT_G711U,              
	em_AUD_FORMAT_G719,			        
	em_AUD_FORMAT_G722,
	em_AUD_FORMAT_G7221,
	em_AUD_FORMAT_G728,     
	em_AUD_FORMAT_G729,
	em_AUD_FORMAT_MPEGAACLC,
	em_AUD_FORMAT_MPEGAACLD,
	em_AUD_FORMAT_MP3,
}EmCodeAudFormat;

//����ֱ���
typedef enum em_CodeRes_Type
{
	em_RES_TYPE_1080P1920x1080 = 0x01,   		
	em_RES_TYPE_WSXGA1440x900,         	    
	em_RES_TYPE_SXGA1280x1024,              
	em_RES_TYPE_1280x960,			        
	em_RES_TYPE_WXGA1366x768,
	em_RES_TYPE_WXGA1360x768,
	em_RES_TYPE_WXGA1280x800,     
	em_RES_TYPE_WXGA1280x768,
	em_RES_TYPE_720P1280x720,
	em_RES_TYPE_1280x600,
	em_RES_TYPE_XGA1024x768,
	em_RES_TYPE_SVGA800x600,
	em_RES_TYPE_CIF352x288,
}EmCodeResType;

typedef enum em_QK_Pid_Type
{
	em_NT30_Type = 0x01,
	em_NT30_MT_Type,
	em_Unknow_Type,
}EmQKPidType;

typedef enum em_QK_NotView_Reason
{
	em_MtEncryptConf_Reason = 0x01,   //�ն˼��ܻ���
	em_UnkownReason,

}EmQkNotViewReason;


typedef struct tagUserInfo
{
	s8 abyUserName[USERNAME_MAX_LENGTH];
	tagUserInfo()
	{
		memset(abyUserName, 0, USERNAME_MAX_LENGTH);
	}

}TUserInfo,*PTUserInfo;

typedef struct tagTimeInfo
{
	u16    m_dwYear;
	u16    m_dwMonth;
	u16	   m_dwDay;
	u16    m_dwHour;
	u16    m_dwMinute;
	u16    m_dwSecond;
}TTimeInfo;/*��Ev_NV_TerminalType_PC_Cmd����Ev_NV_TerminalType_IMIX_Cmd����*/

typedef struct tagFrameInfo
{
	u32    m_dwPCWidth;
	u32    m_dwPCHeight;
	u32    m_dwFrame;
	u16	   m_dwBitRate;
}TFrameInfo;

typedef struct tagTUSBData{
	u32      m_dwSeqID; //ѭ���ۼ�id

	u16      m_wSliceID;//ÿ֡���ݿ�ʼ=0 ÿ��һ���ۼ�
	u16      m_wSliceNum;//��Ϊ���ٰ�

	u32		 m_byDataSize;//��Ч���ݳ���
	u8       m_abyData[ PC_SENDDATA_LENGTH ];	//����Ƶ����
	
	//u32      m_dwCheckSum;//У��
}TUSBData;



#define STRUCT_FRAMEHDR_LENGTH sizeof(FRAMEHDR)
#define RECVVIDEOBUF_LENGTH 2000000
#define RECVAUDIOBUF_LENGTH 1000000
#define READBUF_LENGTH  64*1024

#endif

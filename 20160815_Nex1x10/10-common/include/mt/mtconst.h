#ifndef _MTCONST_H_
#define _MTCONST_H_

#include "kdvtype.h"
#include "kdvdef.h"

//app id ����
//���ָ���Ʒģ��ʹ�õķ�Χ
#define AID_PRODUCT_BGN     (u32)50
#define AID_PRODUCT_END     (u32)100

//���ģ��app id����
#define AID_MTSYSCTRL		(u32)(AID_MT_BGN + 1)     //ϵͳ����
#define AID_DATACONFCLIENT  (u32)(AID_MT_BGN + 2)     //���ݻ���ͻ���
#define AID_FTPDOWNLOAD     (u32)(AID_MT_BGN + 3)     //���ݻ����ļ�����
#define AID_MTMP            (u32)(AID_MT_BGN + 4)     //mtmpģ��

//////dispatch ��access ������Ϊ�˼��� access�ع�
#define AID_MTDISPATCH2     (u32)(AID_MT_BGN + 6)     //��Ϣ����ģ��
#define AID_MTDISPATCH      AID_MTDISPATCH2
#define AID_MTACCESS        (u32)(AID_MT_BGN + 5)     //�ն˿ͻ��˽���ģ��

#define AID_AGENT           (u32)(AID_MT_BGN + 7)     //����agent
#define AID_GUARD           (u32)(AID_MT_BGN + 8)     //����guard
#define AID_MTAPI           (u32)(AID_MT_BGN + 9)     //MTAPI
#define AID_MTPA            (u32)(AID_MT_BGN + 10)    //mtpaģ��
#define AID_SIPMODULE       (u32)(AID_MT_BGN + 11)    //Э���sipmoule,�ն�ָ��
#define AID_SIPSTACKIN      (u32)(AID_MT_BGN + 12)    //Э���sipstackout�� �ն�ָ��
#define AID_SIPSTACKOUT     (u32)(AID_MT_BGN + 13)    //Э���sipstackin, �ն�ָ��
#define AID_MTMC            (u32)(AID_MT_BGN + 14)    //����mcģ��
#define AID_MISC            (u32)(AID_MT_BGN + 15)    //Сҵ��ģ��
#define AID_MTH323SERVICE   (u32)(AID_MT_BGN + 16)    //mth323Service
#define AID_MTH323STACKOUT  (u32)(AID_MT_BGN + 17)    //mth323stakcout
#define AID_MTH323STACKIN   (u32)(AID_MT_BGN + 18)    //mth323stackin
#define AID_MTVOD           (u32)(AID_MT_BGN + 19)    //�㲥ģ��
#define AID_REST			(u32)(AID_MT_BGN + 20)    //restģ��
#define DONT_USE_ME 		122                       //��Ҫʹ��122�����Ѿ���OSP���ڲ�ʹ����
#define AID_IM				(u32)(AID_MT_BGN + 22)    //restģ��
#define AID_AGENTADP        (u32)(AID_MT_BGN + 23)    //���������
#define AID_UPGRADE         (u32)(AID_MT_BGN + 24)    //������ϵͳ
#define AID_CFGSRV	        (u32)(AID_MT_BGN + 25)    //���÷���
#define AID_MTMCSERVICE	    (u32)(AID_MT_BGN + 26)    //����mcģ��
#define AID_MTRECORD	    (u32)(AID_MT_BGN + 27)    //���ص�ַ��&���м�¼
#define AID_SATSERVICE	    (u32)(AID_MT_BGN + 28)    //sat service app
#define AID_SATSTACK	    (u32)(AID_MT_BGN + 29)    //sat stack app
#define AID_MTSERVICE		(u32)(AID_MT_BGN + 30)	  //mtserviceģ��
#define AID_MTNETMANAGER    (u32)(AID_MT_BGN + 31)    //�������
#define AID_XMPP_JINGLE     (u32)(AID_MT_BGN + 32)    //libjingle ҵ��APP

#define AID_MT_AUTOTEST     (u32)(AID_MT_BGN + 33)    //�ն�Ӳ���Զ�������Ӧ��ID
#define AID_MT_AUTOTESTCLIENT (u32)(AID_MT_BGN + 34)  //�ն�Ӳ���Զ����ն�Ӧ��ID 
#define AID_MT_PINGTEST (u32)(AID_MT_BGN + 35)		  //ping��������
#define AID_MTSEC           (u32)(AID_MT_BGN + 36)    //mtsecģ��
#define AID_MTDCS           (u32)(AID_MT_BGN + 37)    //mtdcsģ��
#define AID_MTKEYDRIVER     (u32)(AID_MT_BGN + 38)    //mtkeydriverģ��
#define AID_MTKEYDRIVER_OSD (u32)(AID_MT_BGN + 39)    //OSD��keydriverӦ��ID 
#define AID_MTAI            (u32)(AID_MT_BGN + 40)    //mtai 
#define AID_AICAMERA        (u32)(AID_MT_BGN + 41)    //mtaicamera app Id

// ��ϵͳ�������
#define MT_SYS_NUM_MAX		(u32)40

// �ַ�������
#define MT_STR_LEN_4		(u32)4
#define MT_STR_LEN_8		(u32)8
#define MT_STR_LEN_16		(u32)16
#define MT_STR_LEN_32		(u32)32
#define MT_STR_LEN_64		(u32)64
#define MT_STR_LEN_128		(u32)128
#define MT_STR_LEN_256		(u32)256
#define MT_STR_LEN_512		(u32)512
#define MT_STR_LEN_1024		(u32)1024
#define MT_STR_LEN_2048		(u32)2048
#define MT_STR_LEN_4096		(u32)4096
#define MT_STR_LEN_8192		(u32)8192
#define MT_STR_LEN_URI		    (u32)(128*1024)

#define MT_SIP_LEN_XML      (u32)10240
#define MT_MAX_SIP_UNCOMPRESS_XMLLEN (u32)(1024*100)

#define MT_MAX_NUM_5		(u32)5
#define MT_MAX_NUM_10		(u32)10
#define MT_MAX_NUM_15		(u32)15
#define MT_MAX_NUM_16		(u32)16
#define MT_MAX_NUM_20		(u32)20
#define MT_MAX_NUM_25		(u32)25
#define MT_MAX_NUM_30		(u32)30
#define MT_MAX_NUM_32       (u32)32
#define MT_MAX_NUM_40		(u32)40
#define MT_MAX_NUM_50		(u32)50
#define MT_MAX_NUM_100		(u32)100

#define MT_E164_LEN			(u32)13

#define MT_LEN_4K          (u32)(1 << 12)
#define MT_LEN_8K          (u32)(1 << 13)
#define MT_LEN_16K          (u32)(1 << 14)
#define MT_LEN_24K          (u32)(24 * 1024)
#define MT_LEN_32K          (u32)(1 << 15)

#ifndef MT_MAX_PATH
#define MT_MAX_PATH			(u16)256  /* �������·������ */
#endif

#define MT_DCS_POINT_MAX		5000
#define MT_DCS_CONF_USER_MAX	192
#define MT_DCS_WB_MAX			64

//��Чֵ����
#define INVALID_U8   (u8)(~0)
#define INVALID_U16  (u16)(~0)
#define INVALID_U32  (u32)(~0)
#define INVALID_S8   (s8)(~0)
#define INVALID_S16  (s16)(~0)
#define INVALID_S32  (s32)(~0)

//��ʾu32����ת���ַ������ռʮ���ֽ�
#define MT_U32_MAX_LEN 10

//�ն˺��Ľ��̼����˿�
#define MT_KERNEL_LISTEN_PORT (u16)60001

//�ն��ڲ�RPC�����������˿�
#define RPC_SERVER_PORT       (u16)8000

//<���ݹ�������������˿�
#define DSS_PORT              (u16)12581 

//================���̶���============
const u32 VENDOR_MICROSOFT_NETMEETING = 1;
const u32 VENDOR_KEDA = 2;
const u32 VENDOR_HUAWEI = 3;
const u32 VENDOR_POLYCOM = 4;
const u32 VENDOR_POLYCOM_MCU = 5;
const u32 VENDOR_TANDBERG = 6;
const u32 VENDOR_RADVISION = 7;
const u32 VENDOR_VCON = 8;
const u32 VENDOR_SONY = 9;
const u32 VENDOR_VTEL = 10;
const u32 VENDOR_ZTE = 11;
const u32 VENDOR_ZTE_MCU = 12;
const u32 VENDOR_CODIAN = 13;
const u32 VENDOR_AETHRA = 14;
const u32 VENDOR_CHAORAN = 15; //��Ȼ
const u32 VENDOR_AVCON  = 16; //��ƽ
const u32 VENDOR_DONJIN = 17; //����GW
const u32 VENDOR_CISCO = 18;
const u32 VENDOR_SMARTPHONE = 19;

const u32 VENDOR_UNKNOWN = 50;


//////confģ�鶨��ĳ���
#define MTCONF_MAX_BANDWIDTH        (u32)(8192)      ///������8M
#define MTCONF_MAX_BANDWIDTH_SKY100 (u32)(4096)      ///������4M
#define AUTO_ASSBANDWIDTH_RATE      (u32)30          ///auto��˫�������  /100 

#define MTCONF_RRQ_TIMETOLIVE       (u32)(20)          //������ע��ʱ��Ϊ60��,5s���ڲ���, �������õ�Э��ջ��λΪs����ms

#define MTCONF_UIAPPLYCHIEME_TIMEOUT  (u32)(30*1000)       // ����廰��ʱ����30��
#define MTCONF_UIAPPLYSPEAK_TIMEOUT   (u32)(30*1000)       // ���뷢�Զ�ʱ����30��
#define MTCONF_UIAPPLYCHAIR_TIMEOUT   (u32)(30*1000)       // ������ϯ��ʱ����30��
#define MTCONF_GetAllTerminal_TIMEOUT (u32)(10*1000)       // ��ȡ����ն��б���Ϣ��ʱ����10��
#define MTCONF_CONFLIST_TIMEOUT       (u32)(4*1000)        //��ȡ�����б�û���յ�������־����Ϊ��ʱ
#define MTCONF_CREATECONF_TIMEOUT     (u32)(20*1000)        //�������鳬ʱ20s�� ���յ�ƽ̨setupΪֹ
#define MTCONF_JOINCONF_TIMEOUT       (u32)(20*1000)        //�μӻ��鳬ʱ20s�� ���յ�ƽ̨setupΪֹ
#define GETBWE_STATUS_TIMEOUT         (u32)(5*1000)         //��̬�����⣬ÿ��5s,���һ��
#define PRI_VIDEO_OFF_TIMEOUT         (u32)(2*1000)         //���н����󣬳�ʱ�����Ƶͨ���շ�����û���������ϲ�

#define MTCONF_SECSTRONGATH_TIMEOUT   (u32)(2*60*1000)       //ǿ��֤��ʱʱ��
#define MTCONF_SECWAITCALL_TIMEOUT    (u32)(5*60*1000)       //�ȴ�ǿ��֤�������

//#define GKNONSTAND_PORT             (u32)1759        //GK�Ǳ������˿�
#define GKLISTENING_PORT              (u32)1719        //GK��׼ �����˿�
#define STAND_H323CALLING_PORT        (u32)1720        //h323��׼�����˿�
#define NONSTAND_H323CALLING_PORT     (u32)1760        //h323�Ǳ������˿�
#define NONSTAND_H323CALLING_PORT_END (u32)1780        //�ڷǱ�˿���[1760,1780]�˿����ҿ��еĶ˿�
#define SIPSTANDLISTENING_PORT        (u32)5060        //sip��׼�����˿�
#define SIPTLSLISTENING_PORT          (u32)5061        //sipTLS�����˿�

#define MTCONF_NAME                  "mtconf"      //����mtmsg��userdata�ֶΣ� ��ʾ�����Ϣ��mtconfģ�鴦��,�����ʽΪmtconf*handle(0*0)
#define MTMC_NAME                    "mtmc"        //����mtmsg��userdata�ֶΣ� ��ʾ�����Ϣ��mtmcģ�鴦��,�����ʽΪmtmc*handle(mchandle*otherhandle)
#define MTPA_NAME                    "mtpa"        //����mtmsg��userdata�ֶΣ� ��ʾ�����Ϣ��mtmaģ�鴦��,�����ʽΪmtpa*hande(pahandle*otherhandle)
#define MTH323_NAME                  "mth323"      
#define MTMCC_NAME                   "mtmcc"       //����mtmsg��userdata�ֶΣ� ��ʾ�����Ϣ��mtconfģ�鴦��,�����ʽΪmtmcc*handle(0*0)
#define MTVERSION50                  "MT-50"       //5.0�ն˵�version��Ϊ"MT-50"
#define MTH323PROXYPORTSIZE          (u32)40       //�����ڲ���ҪԤ��40���˿�


#define MTPA_CONFESTABLISH_TIMEOUT   (u32)(32*1000)       //��
#define MTPA_DISCONNECT_TIMEOUT      (u32)(20*1000)       //��
#define MTPA_TLSRENEGOTIATE_TIMEOUT  (u32)(3600*1000)      //��

#define MAX_MAINAUDIO_NUM            (u32)3    ///���������Ƶ���ͽ���ͨ����
#define MAX_MAINVIDEO_NUM            (u32)3    ///���������Ƶ���ͽ���ͨ����

#define MAX_MAINVIDEO_EMBED_FPS       (u32)60   ///Ӳ�ն��������֡�ʣ�ֻ���264,265
#define MAX_PCASSVIDEO_EMBED_FPS      (u32)5   ///Ӳ�ն�pc�������֡�ʣ�ֻ���264,265
#define MAX_VIDEOASSVIDEO_EMBED_FPS   (u32)60   ///Ӳ�ն�video������ ���֡�ʣ�ֻ���264,265
#define MAX_MAINVIDEO_TL_FPS          (u32)30   ///�����������֡�ʣ�ֻ���264,265
#define MAX_PCASSVIDEO_TL_FPS         (u32)15   ///����pc�������֡�ʣ�ֻ���264,265

////////����mc�궨��
#define MTMC_MAX_MTNUM              (u32)8                   //����mc�����ն���������mc�ն˱���
#define MTMC_MAX_MIXER_NUM          (u32)8                   //mc����������
#define MTMC_MAX_VMP_NUM            (u32)8                   //����ϳ�֧�ֵ��������
#define MTMC_MAX_STREAM_NUM         (u16)1                   //����֧�ֵ��������
#define MTMC_MCC_HANDLE             (u16)0                   //mcc��Ϊ�ն˵ľ����ʶ��
#define MTMC_LOCALMT_HANDLE         (u16)1                   //�����ն˵ľ����ʶ
#define MTMC_MCUID                  (u16)192                   //mcu�ı�ʶ��

const u32    MT_MAX_H323ALIAS_LEN       =   32;              // �ն˱�����󳤶�
const u32    MT_MAXLEN_SMSTEXT          =   1024*2;          //����Ϣ������󳤶�

#define AUDIO_BITRATE_DEFAULT        64           // ��Ƶ����Ĭ��ֵ, ����ϲ����õ�����С�ڵ��ڴ�ֵ����Ϊ����Ƶ����,��λΪkbps
#define AUDIO_BITRATE_128            128          //(384,768] ��Χ����Ƶ������
#define AUDIO_BITRATE_192            192          //(768,2048] �� ��2048, 8M]��Χ����Ƶ������        


//g7221���ʶ���
#define   MT_G7221_RATE_24           (u8)0x01
#define   MT_G7221_RATE_32           (u8)0x02
#define   MT_G7221_RATE_48           (u8)0x04
#define   MT_G7221_RATE_NONE         (u8)0x00

#define   MT_AAC_RATE                96      //lc/ld����


/*********************************************************/
/*         Opus��ʽ��Ƶ�����ʶ���(Kbps)                    */
/**********************************************************/
#define OPUS_MIN_BITRATE         (u16)8      //�������
#define OPUS_MAX_BITRATE_HD      (u16)56     //�����ն��������
#define OPUS_MAX_BITRATE_TL      (u16)32     //TL�������
#define OPUS_MAX_BITRATE_MOBILE  (u16)16     //�ƶ��ն��������



//��������������
#define MAX_VENC_NUM  (u8)8
#define MAX_VDEC_NUM  (u8)8
#define MAX_AENC_NUM  (u8)8
#define MAX_ADEC_NUM  (u8)8


//im���
#define  IM_MAX_ID_LEN                      64
#define  IM_MAX_ADDRESS_LEN                 32
#define  IM_MAX_PATH_LEN                    256
#define  IM_MAX_HEAD_PORTRAIT_LEN           4096        
#define  IM_MAX_SEND_PIC_COUNT              3    // ÿ�����ֻ�ܷ���3�Ž�ͼ
#define  IM_MAX_CHAT_ROOMNAME_LEN           32
#define  IM_ENTERPRISE_NAME_LEN             32
#define  IM_MAX_MT_TYPE                     8
#define  IM_MAX_CHATROOM_ID_LEN             128
#define  IM_MAX_ROSTER_ITEMS_PER_BATCH      20        
#define  IM_MAX_SID_LEN                     32
#define  IM_MAX_FILE_NAME_LEN               256
#define  IM_MAX_ROSTER_ITEMS_PER_BATCH      20        
#define  IM_MAX_SID_LEN                     32
#define  IM_MAX_FILE_NAME_LEN               256
#define  IM_MAX_FONT_FACE_LEN               32
#define  IM_MAX_CHATROOM_MEMBER_CACHE_ARRAY_SIZE  40
#define  IM_MAX_PERSISTENT_CHATROOM_ARRAY_SIZE    40
#define  IM_MAX_MEMBER_STATUS_CACHE_ARRAY_SIZE  10
#define  IM_MAX_RESOURCE_LEN                8
#define  IM_MAX_CHATROOM_SCREEN_CNT         16
#define  IM_MAX_CONTEXT_LEN                 36
#define  IM_MAX_BATCH_USERS_COUNT           64

#define  IM_SOCK5_ADDR_NAME_LEN             32
#define  IM_SOCK5_USERNAME_LEN              32
#define  IM_SOCK5_PASSWORD_LEN              32

#define  IM_CUSTOM_TYPE_SPLASH              1
#define  IM_MAX_CONFIG_KEY_LEN              32
#define  IM_MAX_CONFIG_VALUE_LEN            2048
#define  IM_MAX_CONFIG_ITEMS_PER_BATCH      4
#define  IM_MAX_SCREENED_CHATROOM_COUNT     32
#define  IM_MAX_MOID_LEN                    64

#define  WEIBO_MAX_UID_LEN                  64
#define  WEIBO_MAX_NAME_LEN                 64
#define  WEIBO_MAX_EMAIL_LEN                64
#define  WEIBO_MAX_MUGSHOT_LEN              64
#define  WEIBO_MAX_GROUP_NAME_LEN           64

#define  REST_COMMON_BUF_SIZE               64

#define  REST_ACCOUNT_INFO_BIT_INDEX_MOBILE   0x01
#define  REST_ACCOUNT_INFO_BIT_INDEX_EXT      0x02
#define  REST_ACCOUNT_INFO_BIT_INDEX_SEAT     0x04
#define  REST_ACCOUNT_INFO_BIT_INDEX_POSITION 0x08
#define  REST_ACCOUNT_INFO_BIT_INDEX_BRIEF    0x10
#define  REST_ACCOUNT_INFO_BIT_INDEX_SEX      0x20
#define  REST_ACCOUNT_INFO_BIT_INDEX_NAME     0x40

#define MT_MAX_MONITOR_GROUP_COUNT	20		//����豸�����20��
#define MT_MAX_MONITOR_DEVICE_COUNT 10		//�豸��Ϣ���10��

#define MAX_PERSONAL_TEMPLATE_LIST_NUM 4		// ��ȡ����ģ���б�ÿ��������
#define MAX_PUBLIC_TEMPLATE_LIST_NUM       10		// ��ȡ����ģ���б�ÿ��������
#define MAX_RECORD_MEMBER_NUM          8    //¼���б��Ա�������
#define MAX_CONF_TERMINAL_NUM          8    //�����ն��б�����Ա��

#define  MAX_PROXY_ADDR_LEN           64
#define  MAX_PROXY_USER_LEN           64
#define  MAX_PROXY_PWD_LEN            64

#define  REST_MAX_DATETIME_LEN            32
#define  MAX_XMPP_HANDLE_COUNT			1
#define  MAX_DELAY_CHAT_ROOM_INFO_COUNT 128

#define  MT_MAX_CALLRECORD_NUM	 300  // ���м�¼�������
#define  MT_MAX_LOCALROSTER_NUM  1000  // ���ص�ַ���������

#define MAX_PROXYSERVER_NAME_LEN  255         //�������ǽ��������󳤶�

#define		MAXLEN_GROUPINFO_LIST			(u32)20         //�û�����Ϣ�б���󳤶�
#define		MAX_QUERY_USERONLINE_NUM            5      // һ������ѯ��Ա������״̬����ͳһ�������10���Ѿ����������� 20130104  by zhouyanhua

//2. ���ݵ�ѹ����������
#define		DMS_DATA_COMPRESS_TYPE_UNDO		(u16)0			//û��ѹ��
#define		DMS_DATA_COMPRESS_TYPE_ZLIB		(u16)1			//Zlibѹ��

//3. ���ȵ���ض���
#define		MAXLEN_USER_SIGNATURE			(u16)512        //�û�����ǩ����󳤶�
#define		MAXLEN_GROUPNAME				(u16)64         //�û������󳤶�
#define		MAXLEN_MULTI_CHAT_NAME			(u16)64         //��������ĻỰ���Ƶ���󳤶�
#define		MAXLEN_U64STRING				(u16)20         //�û������󳤶�
#define		MAXLEN_DEPARTMENT_NAME			(u16)64         //�������Ƶ���󳤶�

#define		MAXLEN_SELFDEF_LIST				(u32)1          //�û��Զ�����Ϣ�б���󳤶�
#define		MAXLEN_GROUPINFO_LIST			(u32)20         //�û�����Ϣ�б���󳤶�
#define		MAXLEN_ONLINESTATE_LIST			(u32)20         //�û�״̬��Ϣ�б���󳤶�
#define		MAXLEN_USER_LIST				(u32)20         //�û��б���󳤶�
#define		MAXLEN_MEMBER_INFO_LIST			(u32)10         //�����б���󳤶�
#define		MAXLEN_DEVICEINFO_LIST			(u32)20         //�û��豸��Ϣ�б���󳤶�
#define		MAXLEN_DEPARTMENTINFO_LIST		(u32)20         //������Ϣ�б���󳤶�
#define		MAXLEN_EMPLOYEE_INFO_LIST		(u32)20         //Ա���б���󳤶�


#define		MAXLEN_SENDMESSAGE_BUF			(u32)(1600*2)   //������Ϣ���û����б���󳤶�
#define		INVALID_MULTICHAT_ID			(u32)0          //��Ч�Ķ�������ID

//4.�����û�������к�
#define		GROUPSN_INVALID                 (u64)0			//��Ч�������к�
#define		GROUPSN_TOPLEVEL_PARENT         (u64)0			//������ĸ������к�
#define		GROUPSN_UNGROUPING              (u64)1			//δ���� �����к�
#define		GROUPSN_BLACKLIST               (u64)2			//������ �����к�

#define		GEOUPSN_NORMAL_BENGIN           (u64)1001		//�����������ʼ���(ǰ������Ԥ��������ķ���)
#define		MEMBERSN_NORMAL_BENGIN          (u64)10001		//������Ա����ʼ���(ǰ������Ԥ��������ĳ�Ա)
#define		DEPARTMENTSN_NORMAL_BENGIN      (u64)10001		//�������ŵ���ʼ���(ǰ������Ԥ��������Ĳ���)
#define		EMPLOYEE_NORMAL_BENGIN			(u64)10001		//�������ŵ���ʼ���(ǰ������Ԥ���������Ա��)

//5.���ⲿ�ŵ����к�
#define		DEPARTMENTSN_TOPLEVEL_PARENT     (u64)0			//�������ŵĸ��������к�
#define     MAX_CHAT_MSG_LEN            1600    // ÿ������Ϣ���Ƴ���Ϊ1600���ֽ�
#define		MAX_CHAT_BYTE_LEN			4
#define     MT_MAX_TUI_DOMAINNAME_LEN	32
#define		MAX_DEVICE_STRLEN			32   // rest���豸�����ַ�����󳤶�
#define		HTTP_PROTOCOL               "http"
#define		HTTPS_PROTOCOL              "https"
#define     MT_MAXLEN_TELEPHONE         32            // ��ϵ�绰����󳤶�
#define		MAX_SAVE_PORTRAIT_PATH      256     // ����ͼ���·��
#define		MAX_QUARY_USER			    5           // һ������ѯ���û���ϸ��Ϣ����
#define		MAX_SAVE_PORTRAIT_FILENAME  64      // ����ͼ����ļ���
#define		MAX_DEPARTMENT_COUNT		200      // һ�ηְ�200��������Ϣ���ϲ�
#define		MAX_EMPLOYEE_COUNT		    100      // һ�ηְ�100��Ա����Ϣ���ϲ�
#define		MAX_USER_DETAIL_INFO		6      // ÿ�����POST���������ϸ��Ϣ����
#define		MT_MAX_COUNT				20
#define		MT_MAX_PARTICIPANT_NUM		10			//���������
#define		MAX_ADDRESS_NUM				20
#define     MAX_PATH                    260    //����·������

//6��tls��� �����
#define     TLS_CRYPTOKEY_LEN    46       
#define     SIP_CALLID_LEN       37       
#define     SIP_CALLID_STR       17       

#define		MT_DCS_MATRIXVALUE		9


const u32 MAX_PORT_VALUE = 65536;  //��65535��Ϊ 65536 ����Ϊ�˿�ʹ�÷�ΧΪ1 - 65535��һ��65535�˿ڱ�ռ���������

#endif
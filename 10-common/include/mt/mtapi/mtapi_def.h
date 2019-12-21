/*******************************************************************************//**
*@file          mtapi_def.h
*@brief         �ṩmtapi���еĳ�������
*
*@author        ruiyigen
*@version       5.0    
*@date          20150328
*@copyright     (c)1995-2015 Suzhou Keda Technology Co.,Ltd. All rights reserved
***********************************************************************************/
#ifndef _MTAPI_DEF_H_
#define _MTAPI_DEF_H_
/**@addtogroup common ����
*@{
*/

/**@addtogroup other ����
*@{
*/

#include "kdvtype.h"

#ifndef CONST
#  define CONST const
#endif

#ifndef IN
#  define IN
#endif

#ifndef OUT
#  define OUT
#endif

#ifndef INOUT
#  define INOUT
#endif

#ifndef OPTIONAL
#  define OPTIONAL
#endif
 
/** app id ���� */
/** ���ָ���Ʒģ��ʹ�õķ�Χ */
#define AID_PRODUCT_BGN     (u32)50
#define AID_PRODUCT_END     (u32)100

/** ���ģ��app id���� */
#define KMTAPI_AID_MTSYSCTRL	   (u32)102
#define KMTAPI_AID_MTMP            (u32)105    ///<mtmpģ��
#define KMTAPI_AID_MTDISPATCH      (u32)106    ///<��Ϣ����ģ��
#define KMTAPI_AID_MTACCESS        (u32)107    ///<�ն˿ͻ��˽���ģ��
#define KMTAPI_AID_AGENT           (u32)108    ///<����agent
#define KMTAPI_AID_GUARD           (u32)109    ///<����guard
#define KMTAPI_AID_MTAPI           (u32)110    ///<MTAPI
#define KMTAPI_AID_MTPA            (u32)111    ///<mtpaģ��
#define KMTAPI_AID_SIPMODULE       (u32)112    ///<Э���sipmoule,�ն�ָ��
#define KMTAPI_AID_SIPSTACKIN      (u32)113    ///<Э���sipstackout�� �ն�ָ��
#define KMTAPI_AID_SIPSTACKOUT     (u32)114    ///<Э���sipstackin, �ն�ָ��
#define KMTAPI_AID_MTMC            (u32)115    ///<����mcģ��
#define KMTAPI_AID_MISC            (u32)116    ///<Сҵ��ģ��
#define KMTAPI_AID_MTH323SERVICE   (u32)117    ///<mth323Service
#define KMTAPI_AID_MTH323STACKOUT  (u32)118    ///<mth323stakcout
#define KMTAPI_AID_MTH323STACKIN   (u32)119    ///<mth323stackin
#define KMTAPI_AID_MTVOD           (u32)120    ///<�㲥ģ��
#define KMTAPI_AID_REST			   (u32)121    ///<restģ��
#define KMTAPI_DONT_USE_ME 		   (u32)122    ///<��Ҫʹ��122�����Ѿ���OSP���ڲ�ʹ����
#define KMTAPI_AID_IM			   (u32)123    ///<IMģ��
#define KMTAPI_AID_AGENTADP        (u32)124    ///<���������
#define KMTAPI_AID_UPGRADE         (u32)125    ///<������ϵͳ
#define KMTAPI_AID_CFGSRV	       (u32)126    ///<���÷���
#define KMTAPI_AID_MTMCSERVICE	   (u32)127    ///<����mcģ��
#define KMTAPI_AID_MTRECORD	       (u32)128    ///<���ص�ַ��&���м�¼
#define KMTAPI_AID_SATSERVICE	   (u32)129    ///<sat service app
#define KMTAPI_AID_SATSTACK	       (u32)130    ///<sat stack app
#define KMTAPI_AID_MTSECURE	       (u32)137    ///<secureģ��
#define KMTAPI_AID_MTDCS           (u32)138    ///<mtdcsģ��


//////////////////////////////////////////////////////////////////////////
/** BUF���ȶ��� */     
//////////////////////////////////////////////////////////////////////////
#define    KMTAPI_BUF_16_LEN					  (u16)16
#define    KMTAPI_BUF_32_LEN					  (u16)32
#define    KMTAPI_BUF_64_LEN					  (u16)64
#define    KMTAPI_BUF_128_LEN				      (u16)128
#define    KMTAPI_BUF_256_LEN				      (u16)256
#define    KMTAPI_BUF_512_LEN					  (u16)512
#define    KMTAPI_BUF_1024_LEN				      (u16)1024
#define    KMTAPI_SSID_MAX_LEN					  (u16)96

//////////////////////////////////////////////////////////////////////////
/** ���ø������� */
//////////////////////////////////////////////////////////////////////////
#define    KMTAPI_COUNT_4					  (u16)4
#define    KMTAPI_COUNT_8					  (u16)8
#define    KMTAPI_COUNT_16					  (u16)16
#define    KMTAPI_COUNT_32					  (u16)32
#define    KMTAPI_COUNT_64					  (u16)64
#define    KMTAPI_COUNT_128				      (u16)128
#define    KMTAPI_COUNT_192				      (u16)192
#define    KMTAPI_COUNT_256				      (u16)256
#define    KMTAPI_COUNT_512					  (u16)512
#define    KMTAPI_COUNT_1024				  (u16)1024

#define    KMTAPI_COUNT_100				      (u16)100
#define    KMTAPI_KEEP_CALLING_NUM			  (u16)2 
#define    KMTAPI_MAX_NUM_5                     (u16)5
//////////////////////////////////////////////////////////////////////////

/** �����õ�SESSIONID */
#define  KMTAPI_INVALID_SESSIONID                (SessionID)0


/** mtapi����ն˿���ʵ������ */
#define  KMTAPI_MAX_INS_CNT                      (u16)128   

/** mtapi������MT ��session���� */
#define  KMTAPI_MAX_SESSION_CNT                  (KMTAPI_MAX_INS_CNT)


/** mtapi����dispatch����Ϣ��󳤶�3  */ 
#define  KMTAPI_MAX_MSGBUF_LEN                   ((32*1024))  //Byte

/** �ն�MTDispatch�����˿� */
#define  KMTAPI_MT_LISTEN_PORT                    (u16)60001

/** Ĭ�ϵĻ���������� */
#define  KMTAPI_DEF_CONF_CALLRATE                 (u16)512


/** ���Ķ˶������� */
#define  KMTAPI_MAX_APPLY_PORT_NUM                 (u16)10

/** �ն˵�¼�û����Ƴ��� */
#define  KMTAPI_MAX_USERNAME_LEN                   (u16)48

/** �ն˵�¼�û����볤�� */
#define  KMTAPI_MAX_USERPWD_LEN                    (u16)64

/** �ն˵�¼�û���ȫ���Ƴ��� */
#define  KMTAPI_MAX_FULL_USERNAME_LEN              (u16)64

/** �ն˵�¼�û�������Ϣ���� */
#define  KMTAPI_MAX_USER_DESCRIPTION_LEN           (u16)64

/** ����û��б���Ϣ */
#define  KMTAPI_MAX_MUTLIUSERINFO_NUM              (u16)32  

/** �����û���� */
#define KMTAPI_UM_ADMIN		                       (u16)0x01
#define KMTAPI_UM_OPERATOR		                   (u16)0x02


/** �豸���Ƴ��� */
#define  KMTAPI_MAX_MT_ALIAS_LEN                   (u16)128

/** �豸E164���� */
#define  KMTAPI_MAX_MT_E164_LEN                    (u16)32

/** �豸�ַ���IP���� */
#define  KMTAPI_MAX_MT_IP_LEN                      (u16)32

/** �豸GUID���� */
#define  KMTAPI_MAX_DEVICE_GUID_LEN                (u16)256

/** �豸���볤�� */
#define  KMTAPI_MAX_MT_PWD_LEN                     (u16)64

/** ����豸�б���� */
#define  KMTAPI_MAX_DEVICE_LIST_NUM                (u16)64

/** �������б���� */
#define  KMTAPI_MAX_SNAPSHOT_LIST_NUM                (u16)128

/** �ն˵�ProductID���� */
#define  KMTAPI_MAX_PRODUCT_ID_LEN                 (u16)64

/** �ն˵�Version ID���� */
#define  KMTAPI_MAX_VERSION_ID_LEN                 (u16)64

/** �ն˱��������� */
#define  KMTAPI_MAX_MT_ALIAS_NUM                   (u16)10

/** �������б����� */
#define  KMTAPI_MAX_CONFLIST_NUM                   (u16)500

/** �������ն˳�Ա���� */
#define  KMTAPI_MAX_CONF_MT_MEMBER_NUM             (u16)256

/** ������Vip�б����� */
#define  KMTAPI_MAX_CONF_MT_VIPLIST_NUM            (u16)30

/** �����鸨��·�� */
#define  KMTAPI_MAX_CONF_ASSVID_CHANNEL_NUM        (u16)3

/** ������������Ƶ·�� */
#define  KMTAPI_MAX_CONF_VID_CHANNEL_NUM           (u16)3

/** �����鸨��Ƶ·�� */
#define  KMTAPI_MAX_CONF_ASSAUD_CHANNEL_NUM        (u16)3

/** ����������Ƶ·�� */
#define  KMTAPI_MAX_CONF_AUD_CHANNEL_NUM           (u16)3


/** ��Ƶ����ӿ� */
#define  KMTAPI_MAX_VIDEO_PORT					   (u16)20

/** �����Ƶ�ӿ������б� */
#define  KMTAPI_MAX_VIDEO_CAP_LIST		           (u16)5
/** ���ͨ���� */
#define  KMTAPI_MAX_MULTI_CHANNEL_NUM              (u16)20

/** ����������� */
#define  KMTAPI_MAX_DOMAIN_NAME_LEN                (u16)128

/** ���MOID���� */
#define  KMTAPI_MAX_DOMAIN_MOID_LEN                (u16)64

/** ����ID����  */
#define  KMTAPI_MAX_CONF_ID_LEN 			       (u16)32   

/** �������Ƴ��� */
#define  KMTAPI_MAX_CONF_NAME_LEN                  (u16)128

/** ����E164���� */
#define  KMTAPI_MAX_CONF_E164_LEN                  (u16)32                     
 
/** ����Email���� */
#define  KMTAPI_MAX_EMAIL_LEN					   (u16)50

/** ������󳤶� */
#define  KMTAPI_MAXLEN_PASSWORD                    (u16)32		  

/** �����ѯ�ն���*/
#define  KMTAPI_MAX_POLL_NUM		               (u16)192    		

/* ��ϯ�����ѯ������*/
#define  KMTAPI_MAX_POLL_SCHEME                    (u16)5

/** ����ϳɳ�Ա���� */
#define  KMTAPI_MAX_VMP_MEMBER_NUM                 (u16)25

/** ��������Ա���� */
#define  KMTAPI_MAX_MIX_MEMBER_NUM                 (u16)192


/** �������ͷ���� */
#define  KMTAPI_MAX_CAMERA_NUM                     (u16)10

/** ����Ϣ����Ŀ�ĳ�Ա���ֵ */
#define  KMTAPI_MAX_SMSDST_NUM                     (u16)256

/** ����Ϣ������󳤶�*/
#define  KMTAPI_MAX_SMSTEXT_LEN                    (u16)4096       

/** �������������ݳ��� */
#define  KMTAPI_MAX_ENCRYPTKEY_LEN                 (u16)64 

/** ֱ���б������ */
#define  KMTAPI_MAX_DIRECTBROADCAST_CNT            (u16)50 

/** vrs�������ļ�������� */
#define  KMTAPI_MAX_VODFILE_CNT                    (u16)50 

/** vrs��������Ŀ����� */
#define  KMTAPI_MAX_VODPRG_CNT                     (u16)10 

/** vrs������ĳһ��Ŀ����ϸ��Ϣ����� */
#define  KMTAPI_MAX_VODDETAIL_CNT				   (u16)20

/** ��VOD�������ͨ��  */
#define  KMTAPI_MAX_VOD_STREAM_CHANNEL_NUM         (u16)5 

/** VOD���������·��  */
#define  KMTAPI_MAX_VOD_STREAM_NUM                 (u16)10 


/** �������ǽ��������󳤶� */
#define  KMTAPI_MAX_PROXYSERVER_NAME_LEN           (u16)255

/** ��·�����ļ������� */
#define  KMTAPI_MAX_PATH_FILE_NAME_LEN             (u16)256
 
/** Ĭ�ϵ�SessionID */
#define  KMTAPI_DEF_SSID                          (u16)1     
 
/** �豸�������Ƴ��� */
#define  KMTAPI_MAX_DEV_TYPE_NAME_LEN              (u16)64

#define KMTAPI_MAXLEN_SUS_E164LIST             (u32)(16*30)

#define KMTAPI_MAXLEN_SUS_MOIDLIST             (u32)(40*30)

/** �豸OEM��ʶ���� */
#define  KMTAPI_MAX_DEV_OEM_MARK_LEN               (u16)64

/** �豸����汾���� */
#define  KMTAPI_MAX_DEV_SOFT_VER_LEN               (u16)64

/** �豸����汾����˵������ */
#define  KMTAPI_MAX_VER_RELEASE_NOTES_LEN       (u16)(1024*2)

/**�绰���볤��*/
#define  KMTAPI_MAX_TELE_INFO_LEN               (u16)(32)

/** �豸��ע��Ϣ���� */
#define  KMTAPI_MAX_DEV_DESC_LEN                   (u16)128

/** �豸��ע������ */
#define  KMTAPI_MAX_DEV_MEMO_LEN                   (u16)128

/** �豸��ע��Ϣ���� */
#define  KMTAPI_MAX_UPGRATE_VER_LIST_NUM           (u16)10

/** XAP�������б���� */
#define  KMTAPI_MAX_XAP_LIST_NUM                   (u16)10

/** Eth DNS������ */
#define  KMTAPI_MAX_ETH_DNSLIST_NUM                (u16)2

/** StreamPlayer Channel ���Ƴ��� */
#define  KMTAPI_MAX_CHANNEL_NAME_LEN               (u16)32

/** StreamPlayer Channel ���볤�� */
#define  KMTAPI_MAX_CHANNEL_PWD_LEN                (u16)32

/** SvrStateList��������״̬����*/
#define  KMTAPI_MAX_SVRSTATE_LIST_NUM              (u16)20

/** �ն��ͺ� */
#define  KMTAPI_MAX_MT_TYPE_NAME_LEN               (u16)32

/** Ӳ���汾 */
#define  KMTAPI_MAX_MT_HARDWARE_VER_LEN            (u16)32

/** ����汾 */
#define  KMTAPI_MAX_MT_SOFTWARE_VER_LEN            (u16)32

/** ������Ϣ */
#define  KMTAPI_MAX_MT_OEM_NAME_LEN                (u16)64


/** ���·����Ŀ������Ӳ�նˣ� */
#define  KMTAPI_MAX_ROUTEITEM_CNT                  (u16)64
 
#define KMTAPI_FAST_CALL_LIST_CNT (u16)4

/** ftp/telnet����޶�10��ip���Σ�Ӳ�նˣ� */
#define  KMTAPI_MAX_FTPTELNET_LIMIT_IPITEM_CNT     (u16)10

///<added by ydwu 2014.06.17 begin
///<im���
#define  KMTAPI_IM_MAX_ID_LEN                      (u16)64
#define  KMTAPI_IM_MAX_ADDRESS_LEN                 (u16)32
#define  KMTAPI_IM_MAX_PATH_LEN                    (u16)1024
#define  KMTAPI_IM_SENDER_PATH_LEN				   (u16)1024
#define  KMTAPI_IM_RECV_PATH_LEN				   (u16)1024
#define  KMTAPI_IM_MAX_HEAD_PORTRAIT_LEN           (u16)4096        
#define  KMTAPI_IM_ENTERPRISE_NAME_LEN             (u16)32
#define  KMTAPI_IM_MAX_MT_TYPE                     (u16)7
#define  KMTAPI_IM_MAX_CHATROOM_ID_LEN             (u16)128
#define  KMTAPI_IM_MAX_ROSTER_ITEMS_PER_BATCH      (u16)20        
#define  KMTAPI_IM_MAX_SID_LEN                     (u16)32
#define  KMTAPI_IM_MAX_PERSISTENT_CHATROOM_NUM     (u16)40
#define  KMTAPI_IM_MAX_MEMBER_STATUS_CACHE_NUM     (u16)20
#define  KMTAPI_IM_MAX_RESOURCE_LEN                (u16)8
#define  KMTAPI_IM_MAX_CHATROOM_SCREEN_NUM         (u16)16
#define  KMTAPI_IM_MAX_BATCH_USERS_NUM             (u16)64

#define  KMTAPI_IM_SOCK5_ADDR_NAME_LEN             (u16)32
#define  KMTAPI_IM_SOCK5_USERNAME_LEN              (u16)32
#define  KMTAPI_IM_SOCK5_PASSWORD_LEN              (u16)32

#define  KMTAPI_IM_MAX_CONFIG_KEY_LEN              (u16)32
#define  KMTAPI_IM_MAX_CONFIG_VALUE_LEN            (u16)2048
#define  KMTAPI_IM_MAX_CONFIG_ITEMS_PER_BATCH      (u16)4

#define  KMTAPI_IM_REST_COMMON_BUF_LEN             (u16)64
#define	 KMTAPI_IM_MAX_GROUPINFO_LIST_LEN	       (u16)20            ///< �û�����Ϣ�б���󳤶�
#define	 KMTAPI_IM_MAX_QUERY_USERONLINE_NUM        (u16)5             ///< һ������ѯ��Ա������״̬����ͳһ�������10���Ѿ����������� 20130104  by zhouyanhua
#define	 KMTAPI_IM_MAX_GROUPNAME_LEN			   (u16)64            ///< �û������󳤶�
#define  KMTAPI_IM_MAX_MULTI_CHAT_NAME_LEN	       (u16)64            ///< ��������ĻỰ���Ƶ���󳤶�
#define	 KMTAPI_IM_MAX_U64STRING_LEN			   (u16)20            ///< �û������󳤶�
#define	 KMTAPI_IM_MAX_ONLINESTATE_LIST_NUM   	   (u16)20            ///< �û�״̬��Ϣ�б���󳤶�
#define	 KMTAPI_IM_MAX_USER_LIST_NUM			   (u16)20            ///< �û��б���󳤶�
#define	 KMTAPI_IM_MAX_SENDMESSAGE_BUF_LEN	       (u32)(1600*2 + 4)  ///< ������Ϣ���û����б���󳤶�

 
#define	 KMTAPI_MT_MAX_TELEPHONE_LEN               (u16)32            ///< ��ϵ�绰����󳤶�
#define	 KMTAPI_IM_MAX_WBPARSEKEDADEPT_NUM         (u16)5             ///< �������
#define	 KMTAPI_IM_MAX_BRIEF_LEN                   (u16)220           ///<  һ�仰������󳤶�   
#define	 KMTAPI_IM_MAX_CHATROOM_MEMBER_CACHE_ARRAY_SIZE (u16)40
///<added by ydwu 2014.06.17 end



//by-qwchan-part-mtmeetingctrl begin(ע�ͺ���һ�����)
/** MG: MeetingManager �����ճ̹��� */
#define KMTAPI_MG_MAX_MEETING_NAME_LEN			  (u16)64

#define	KMTAPI_MG_MAX_REGIONNAME_LEN			  (u16)50

#define KMTAPI_MG_MAX_SHORTROOMS_NUM 			  (u16)50

#define KMTAPI_MG_MAX_BRIEF						  (u16)1000

#define KMTAPI_MG_MAX_SHORTMEETINGS_NUM 		  (u16)50

#define KMTAPI_MG_MAX_ROOMS_NUM 		          (u16)50

#define KMTAPI_MG_MAX_ROOM_NAME_LEN  	          (u16)64

#define KMTAPI_MG_MAX_TEMPLATES_NUM 		      (u16)50
#define KMTAPI_MG_MAX_TEMPLATE_LIST_NUM 		      (u16)4
#define KMTAPI_MG_MAX_MEETING_PERSON_NUM 		  (u16)50

#define KMTAPI_MG_MAX_MEETING_REGION_NUM 		  (u16)50

#define KMTAPI_MG_MAX_ROOMS_LOCK_RESULT_NUM  	  (u16)50

#define KMTAPI_MG_MAX_MEETING_BRIEF_LEN			  (u16)1500

#define KMTAPI_MG_MAX_MEETING_ROOM_NUM		  (u16)1000

#define KMTAPI_MG_MAX_MEETING_SUBJECT_LEN		  (u16)100

#define KMTAPI_MG_MAX_MEETING_DATETIME_LEN		  (u16)32
 
#define KMTAPI_MG_MAX_PARTICIPANTNO_LEN			  (u16)20

#define KMTAPI_MG_MAX_MEETING_REGION_NAME_LEN	  (u16)64

#define KMTAPI_MG_MAX_MEETING_COMPANY_NAME_LEN	  (u16)64
 
/** ��������� */
#define KMTAPI_MG_MAX_PARTICIPANT_NUM			  (u16)500

#define KMTAPI_MG_MAX_MODIFY_PARTICIPANT_NUM			  (u16)500
 
#define KMTAPI_MG_MAX_COMMON_BUF_LEN			  (u16)64

/** �����������������20�� */
#define KMTAPI_MG_MAX_REGULAR_NUM				  (u16)20

#define KMTAPI_MG_MAX_ORGANIZER_LEN				  (u16)30

#define KMTAPI_MG_ORGANIZERMAIL_LEN				  (u16)50

#define KMTAPI_MG_MAX_TEMPLATE_ID_LEN			  (u16)20

#define KMTAPI_MG_MAX_REGIONS_NUM				  (u16)20

#define KMTAPI_MG_MAX_MT_NAME					  (u16)60
#define	KMTAPI_MG_MAX_MT_PHONE					  (u16)30
#define KMTAPI_MG_MAX_MT_REMARK					  (u16)100


#define KMTAPI_GM_NOTIFY_SIZE                     (u16)64 
#define KMTAPI_GM_MAX_SUBJECT			          (u16)100
#define KMTAPI_GM_MAX_DATETIME	                  (u16)20
#define KMTAPI_GM_MAX_MOID				          (u16)64
#define KMTAPI_GM_MAX_ORGANIZER		              (u16)30
#define KMTAPI_GM_MAX_ORGANIZERMAIL	              (u16)50
#define	KMTAPI_GM_MAX_PHONE			              (u16)30
#define KMTAPI_GM_MAX_MOBILE		              (u16)20
#define KMTAPI_GM_MAX_REGULAR_MEETING_COUNT (u16)5000

#define KMTAPI_GM_MAX_ROOM_NUM		              (u16)10		
#define KMTAPI_GM_MAX_E164				          (u16)16
#define KMTAPI_GM_MAX_TEMPLATEID		          (u16)20
#define KMTAPI_GM_MAX_TEMPLATENAME		          (u16)64
#define KMTAPI_GM_MAX_COMMON			          (u16)40


/**CM: ContactManager   ��ϵ�˹��� */
#define KMTAPI_CM_MAX_RECORD_NUM				  (u16)32

#define KMTAPI_CM_MAX_ROSTER_NUM				  (u16)32

#define KMTAPI_CM_MAX_GROUP_NUM					  (u16)32

#define KMTAPI_CM_MAX_TEMPLATE_ID_LEN             (u16)32

#define KMTAPI_CM_MAX_TEMPLATE_NAME_LEN           (u16)64

/** ��ַ�������Ƴ��� */
#define KMTAPI_CM_MAX_GROUP_NAME_LEN              (u16)64

//by-lw-part-mtsysctrl begin
#define KMTAPI_SYS_MAX_VER_LEN                    (u16)64
#define KMTAPI_SYS_MAX_SYSNAME_LEN                (u16)64
#define KMTAPI_SYS_MAX_STARTFUN_NAME_LEN          (u16)64
#define KMTAPI_SYS_MAX_STOPFUN_NAME_LEN           (u16)64
#define KMTAPI_SYS_MAX_MTSERVICE_NUM              (u16)64
//by-lw-part-mtsysctrl end

#define KMTAPI_MAX_PORT_NUM                        (u16)30   
#define KMTAPI_MAX_SERVER_NUM                      (u16)20 ///<�ն�ע���������������
#define KMTAPI_MAX_CHAN_NUM                        (u16)10
#define KMTAPI_MAX_PRE_SERVER_NUM                  (u16)3  ///<��¼�������ǰ�÷���������
#define KMTAPI_MAX_ENCODE_NUM                      (u16)5  ///<������������
#define KMTAPI_MAX_DECODE_NUM                      (u16)5  ///<������������
#define KMTAPI_MAX_APP_NUM                         (u16)45 ///<�����������ϵͳ����
#define KMTAPI_MAX_CODEC_NUM                       (u16)5  ///<�������������

#define KMTAPI_MAX_USER_NUM                        (u16)5  ///<����û�����
#define KMTAPI_MAX_ADDRESS_NUM                     (u16)20 ///<ÿ���ϴ�����ַ������

#define	KMTAPI_MAX_DEPARTMENT_COUNT		           (u16)200 ///< һ�ηְ�200��������Ϣ���ϲ�
#define	KMTAPI_MAX_USER_DETAIL_INFO		           (u16)6  ///< ÿ�����POST���������ϸ��Ϣ����
#define KMTAPI_MAX_EMPLOYEE_COUNT		           (u16)100 ///< һ�ηְ�100��Ա����Ϣ���ϲ�

#define KMTAPI_MAX_MONITOR_GROUP_COUNT	           (u16)20 ///<����豸�����20��
#define KMTAPI_MAX_MONITOR_DEVICE_COUNT            (u16)10 ///<�豸��Ϣ���10��
#define KMTAPI_MAX_COMMON                          (u16)40 
#define KMTAPI_MAX_REMARK                          (u16)100 

#define KMTAPI_MAX_CAMERA_PRESET_NUM			   (u16)128 ///<����ͷ���Ԥ��λ����

#define KMTAPI_MAX_CAMERA_TYPE_NUM                  (u16)64  ///< ���֧�ֵ�����ͷ���͸���

#define KMTAPI_MAX_AUDIO_IN_NUM                     (u16)16 ///<�����Ƶ����ӿ���
#define KMTAPI_MAX_AUDIO_OUT_NUM                    (u16)8  ///<�����Ƶ����ӿ���
#define KMTAPI_MAX_VIDSRC_NUM                       (u16)3  ///<�����ƵԴ����

#define KMTAPI_MAX_NET_DEST_NUM                     (u8)5   ///<���Զ�������ַ
 
#define KMTAPI_MAX_VIDEO_SRC_NUM                    (u8)16  ///<������ƵԴ��ǩ����
#define KMTAPI_MAX_VIDEO_OUT_NUM                    (u8)16  ///<������Ƶ�����ǩ����
#define KMTAPI_MAX_SERIAL_NUM                       (u8)16  ///<��󴮿���Ŀ
#define KMTAPI_MAX_FPGA_NUM                         (u8)16  ///<���FPGA����

#define  KMTAPI_REST_ACCOUNT_INFO_BIT_INDEX_MOBILE   0x01
#define  KMTAPI_REST_ACCOUNT_INFO_BIT_INDEX_EXT      0x02
#define  KMTAPI_REST_ACCOUNT_INFO_BIT_INDEX_SEAT     0x04
#define  KMTAPI_REST_ACCOUNT_INFO_BIT_INDEX_POSITION 0x08
#define  KMTAPI_REST_ACCOUNT_INFO_BIT_INDEX_BRIEF    0x10
#define  KMTAPI_REST_ACCOUNT_INFO_BIT_INDEX_SEX      0x20
#define  KMTAPI_REST_ACCOUNT_INFO_BIT_INDEX_NAME     0x40

#define KMTAPI_E1_USRNAME_LEN         20    ///<E1�û����Ƶ���󳤶�
#define KMTAPI_E1_USRPSW_LEN            6   ///<E1�û��������󳤶�
#define KMTAPI_E1_MAX_UNIT_NUM       4      ///<E1���������ĵ�Ԫ����
#define KMTAPI_E1_MAX_GROUP_NUM   4         ///<����E1�������

#define  KMTAPI_ROUTELIST_MAX_NUM   16       ///<����·�ɸ���
#define  KMTAPI_VIDSRC_MAX_NUM	20    //�����ƵԴ����

#define  KMTAPI_BANNER_INFO_LIST_MAX_NUM	4    //���������

#define  KMTAPI_USB_PARTITION_MAX_NUM 16 //USB��������
#define  KMTAPI_USB_INTERFACE_MAX_NUM 4 //USB�ӿ�������

////sec
#define  KMTAPI_SEC_CAID_LEN     20 //����caid�ĳ���
#define  KMTAPI_SEC_CAID_MAX_NUM 64 //����caid�ĸ���

///���Ӱװ�
#define	 KMTAPI_DCS_PIC_MAX			200
#define  KMTAPI_DCS_POINT_MAX                        3000
#define  KMTAPI_DCS_INVALID_MSG_SEQUENCE 0xFFFFFFFF

#define	 KMTAPI_DCS_MATRIXVALUE		9

//aiչʾ�����б���Ŀ
#define  KMTAPI_MAX_AISHOW_LIST_NUM              (u16)6
/**@}*/

/**@}*/
#endif //_MTAPI_DEF_H_
#ifndef _NVCONST_H_
#define _NVCONST_H_

#include "kdvtype.h"
#include "kdvdef.h"

//app id ����
//���ָ���Ʒģ��ʹ�õķ�Χ
#define AID_PRODUCT_BGN     (u32)50
#define AID_PRODUCT_END     (u32)100

//���ģ��app id����
#define AID_NVSYSCTRL			(u32)(AID_NV_BGN + 1)     //ϵͳ����
#define AID_NVMP				(u32)(AID_NV_BGN + 2)     //nvmpģ��
#define AID_NVDISPATCH			(u32)(AID_NV_BGN + 3)     //��Ϣ����ģ��
#define AID_NVACCESS			(u32)(AID_NV_BGN + 4)     //�ն˿ͻ��˽���ģ��
#define AID_NVAPI				(u32)(AID_NV_BGN + 5)     //NVAPI
#define AID_UPGRADE				(u32)(AID_NV_BGN + 6)    //������ϵͳ
#define AID_NVSERVICE			(u32)(AID_NV_BGN + 7)	  //nvserviceģ��
#define AID_CFGSRV				(u32)(AID_NV_BGN + 8)    //���÷���
#define AID_NV_PINGTEST			(u32)(AID_NV_BGN + 9)    //ping��������
#define AID_NV_TERINTERFACE	    (u32)(AID_NV_BGN + 10)    //X500�ն˽���ģ��
#define AID_NV_UPGRADESERVER	(u32)(AID_NV_BGN + 11)    //����������
#define AID_NV_UPGRADAPI	    (u32)(AID_NV_BGN + 12)    //����������api
#define AID_NV_QUICKSHARE	    (u32)(AID_NV_BGN + 13)    //���߹����豸
#define AID_NV_AUTOTESTCLIENT	(u32)(AID_NV_BGN + 14)    //�ն�Ӳ���Զ����ն�Ӧ��ID 
#define AID_NV_AUTOTEST	        (u32)(AID_NV_BGN + 15)    //�������Թ���ID
#define AID_NV_QUICKSHAREAPI	(u32)(AID_NV_BGN + 16)    //����Ͷ����api
#define AID_NVSUC               (u32)(AID_NV_BGN + 17)	  //����������ģ��


// ��ϵͳ�������
#define NV_SYS_NUM_MAX		(u32)40

// �ַ�������
#define NV_STR_LEN_4		(u32)4
#define NV_STR_LEN_8		(u32)8
#define NV_STR_LEN_16		(u32)16
#define NV_STR_LEN_32		(u32)32
#define NV_STR_LEN_64		(u32)64
#define NV_STR_LEN_128		(u32)128
#define NV_STR_LEN_256		(u32)256
#define NV_STR_LEN_512		(u32)512
#define NV_STR_LEN_1024		(u32)1024
#define NV_STR_LEN_2048		(u32)2048
#define NV_STR_LEN_4096		(u32)4096
#define NV_STR_LEN_8192		(u32)8192
#define NV_STR_LEN_URI		    (u32)(128*1024)

#define NV_SIP_LEN_XML      (u32)10240

#define NV_MAX_NUM_5		(u32)5
#define NV_MAX_NUM_10		(u32)10
#define NV_MAX_NUM_15		(u32)15
#define NV_MAX_NUM_20		(u32)20
#define NV_MAX_NUM_25		(u32)25
#define NV_MAX_NUM_30		(u32)30
#define NV_MAX_NUM_40		(u32)40
#define NV_MAX_NUM_50		(u32)50
#define NV_MAX_NUM_100		(u32)100

#define NV_E164_LEN			(u32)13

#define NV_LEN_4K          (u32)(1 << 12)
#define NV_LEN_8K          (u32)(1 << 13)
#define NV_LEN_16K          (u32)(1 << 14)
#define NV_LEN_24K          (u32)(24 * 1024)
#define NV_LEN_32K          (u32)(1 << 15)

#ifndef NV_MAX_PATH
#define NV_MAX_PATH			(u16)256  /* �������·������ */
#define IPNAME_CHAR_LEN      20
#endif

//��Чֵ����
#define INVALID_U8   (u8)(~0)
#define INVALID_U16  (u16)(~0)
#define INVALID_U32  (u32)(~0)
#define INVALID_S8   (s8)(~0)
#define INVALID_S16  (s16)(~0)
#define INVALID_S32  (s32)(~0)

//��ʾu32����ת���ַ������ռʮ���ֽ�
#define NV_U32_MAX_LEN 10

//�ն˺��Ľ��̼����˿�
#define NV_KERNEL_LISTEN_PORT (u16)60003

//�ն��ڲ�RPC�����������˿�
#define RPC_SERVER_PORT       (u16)8000

//���������������˿�
#define NV_UPGRADESERVICE_LISTEN_PORT (u16)60005

#define NVPA_NAME "nvpa" //����nvmsg��userdata�ֶΣ���ʾ�����Ϣ��nvpaģ�鴦�������ʽ

//<���ݹ�������������˿�
#define DSS_PORT              (u16)12581

//g7221���ʶ���
#define   NV_G7221_RATE_24           (u8)0x01
#define   NV_G7221_RATE_32           (u8)0x02
#define   NV_G7221_RATE_48           (u8)0x04
#define   NV_G7221_RATE_NONE         (u8)0x00

#define   NV_AAC_RATE                96      //lc/ld����

const u16 MAX_PORT_VALUE = (u16)0xFFFF;

#define  NV_IMIX_IFR_NAME					"eth0"
#define  NV_IMIX_PRODUCT_ID					"I-MIXTPS"
#define  NV_X500_PRODUCT_ID					"X500TPS"
#define  NV_PC_PRODUCT_ID					"PCTPS"
#define  NV_TOUCHMEETING_PAD_PRODUCT_ID		"TOUCHMEETINGPADTPS"
#define  NV_QK_PRODUCT_ID                   "QKTPS"
#define  NV_TARGET_DEVICE_NUM                10 //Ŀ���豸�����Ŀ
#define  NV_WVS_DEVICE_NUM                   8  //����Ͷ�������Ŀ

#define DEV_CFG_MAX_CFG 4    //�������õ������豸��Ŀ
#define NV_MAX_FILESRV_FILENAME_LEN  32       //�����ļ�������
#define NV_MAX_VERSION_INFO_LEN  1024       //���ĸ������ݳ���


#define MAX_DEVICEVER_LEN            38
#define MAX_DEVICE_NUM               20

#define RS_TV_TIMEOUT 100
#define MAX_TVVSSIG_LEN 6
#define MAX_POWERVSSIG_LEN 5
#define MAX_TVINPUT_LEN 6

#define VER_NVDF "nvdf-1.1.20161026" //�豸���ְ汾��

#define IMIX_TEL_USRNAME  "admin"
#define IMIX_TEL_PWD      "KedaKdv123"

#define TER_PWD  "Pwd_Change"//�ն�����

#define FREEZE_NO                             0 //�ⶳ
#define FREEZE_RIMIX_RSCALER                  144 //����imix����scaler��
#define FREEZE_RIMIX_RSCALER_WOPS             146 //����imix����scaler����opsд
#define FREEZE_RIMIX_RSCALER_ROPS             176 //����imix����scaler����ops��
#define FREEZE_RIMIX_RSCALER_WTER             148 //����imix����scaler�����ն�д
#define FREEZE_RIMIX_RSCALER_RTER             208 //����imix����scaler�����ն˶�
#define FREEZE_WALL                           240 //�������ж�
#define FREEZE_WRIMIX_RSCALER_WTER            149 //����imix��д��scaler�����ն�д  
#endif
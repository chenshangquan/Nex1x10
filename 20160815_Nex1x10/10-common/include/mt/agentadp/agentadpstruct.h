#if !defined(_AGENTADPSTRUCT_H_)
#define _AGENTADPSTRUCT_H_
#include "mtconst.h"

enum EmVideoType
{
    emPriomVideo  = 0, //����
    emSecondVideo = 1  //����
};

//�豸������Ϣ
typedef struct tagTDevNetInfo
{
	s8          achDevIp[MT_STR_LEN_16+1];       //IP
	s8          achDevDns[MT_STR_LEN_16+1];      //Dns
    s8          achSipProtocol[MT_STR_LEN_16+1];  //sip��·����
public:
	tagTDevNetInfo(){ memset(this, 0, sizeof(tagTDevNetInfo) );}
}TDevNetInfo;

//aps����Ϣ
typedef struct tagTApsAddr
{
	s8           achDomain[MT_STR_LEN_128+1];     //����
	s8           achIp[MT_STR_LEN_128+1];         //ip
public:
	tagTApsAddr(){ memset(this, 0, sizeof(tagTApsAddr) );}
}TApsAddr;

//�ն˻�����Ϣ
typedef struct tagTMtInfo
{
	TDevNetInfo  tNetInfo;                        // �豸������Ϣ
	TApsAddr     tApsAdrr;                        // aps��ַ��Ϣ�������鿴ʹ����Ӫ���Ƿ���ȷ��
	s8           achDevVer[MT_STR_LEN_128+1];     // �豸�汾��(������д)
	s8           achDevName[MT_STR_LEN_128+1];    // �豸����(������д)
	s8           achOEM[MT_STR_LEN_128+1];        // ����汾��oem��־
	s8           achOS[MT_STR_LEN_128+1];         // ����ϵͳ
	u8           byCpuNum;                        // cpu����
	s8           achCpuType[MT_STR_LEN_128+1];    // cpu�ͺ�
	u32          dwCpuFreq;                       // cpu��Ƶ(Mhz)
	u32          dwMemory;                        // �ڴ�����(M)
public:
	tagTMtInfo(){ memset(this, 0, sizeof(tagTMtInfo) );}
}TMtInfo;


//�豸ע����Ϣ
typedef struct tagTDevRegInfo
{
    s8           achSipAddrInfo[MT_STR_LEN_128+1];    // SIP��������ַ��Ϣ
    s8           achGkAddrInfo[MT_STR_LEN_128+1];    // GK��������ַ��Ϣ
	s8           achDevId[MT_STR_LEN_128+1];      // �豸moid(������д)
	s8           achDevType[MT_STR_LEN_128+1];    // �豸����(���豸���Ͷ���)(������д)
	TMtInfo      tMtInfo;                         // �ն˻�����Ϣ
public:
	tagTDevRegInfo(){ memset(this, 0, sizeof(tagTDevRegInfo) );}
}TDevRegInfo;

//����Ӧ�����ӵķ���������
typedef struct tagTConServiceTypes
{
	s8           aachServices[MT_STR_LEN_64][MT_STR_LEN_128+1];
	u8           byCnt;
public:
	tagTConServiceTypes(){ memset(this, 0, sizeof(tagTConServiceTypes) );}
}TConServiceTypes;

//���ӷ�����
typedef struct tagTConService
{
	s8          achService[MT_STR_LEN_128+1];
	s8          achIp[MT_STR_LEN_16+1];
public:
	tagTConService(){ memset(this, 0, sizeof(tagTConService) );}
}TConService;

//�����ϵķ�����
typedef struct tagTConServices
{
	TConService  atConSvrs[MT_STR_LEN_64];
	u8           byCnt;
public:
	tagTConServices(){ memset(this, 0, sizeof(tagTConServices) );}
}TConServices;

//�澯��Ϣ
typedef struct tagTAlarmInfo
{
	u32            dwCodeId;                          //�澯��
	BOOL32         bStatus;                           //TRUE��ʾ�澯��FALSE��ʾ�ָ�
	s8             achTime[MT_STR_LEN_32+1];          //��2014/05/08:12:08:08������ʱ��(GMT��׼)
public:
	tagTAlarmInfo(){ memset(this, 0, sizeof(tagTAlarmInfo) );}
}TAlarmInfo;

//��Ƶ����״̬
typedef struct tagTAudSendStatus
{
	u32            dwId;              //�ڼ�·��Ƶ��������
	u32            dwBitrate;         //������Ƶ���ʣ�Kbps
	u32            dwFormat;          //��Ƶ��ʽ����Ӧ��EmAudFormat
public:
	tagTAudSendStatus(){ memset(this, 0, sizeof(tagTAudSendStatus) );}
}TAudSendStatus;

//��Ƶ����״̬
typedef struct tagTAudRecStatus
{
	u32            dwId;              //�ڼ�·��Ƶ��������
	u32            dwPkTsLose;        //Ƶ����Ƶ��������
	u32            dwPkTsLoseRate;    //��Ƶ������
	u32            dwBitrate;         //������Ƶ���ʣ�Kbps
	u32            dwFormat;          //��Ƶ��ʽ����Ӧ��EmAudFormat
public:
	tagTAudRecStatus(){ memset(this, 0, sizeof(tagTAudRecStatus) );}
}TAudRecStatus;

//��Ƶ����״̬
typedef struct tagTVidSendStatus
{
	u32            dwId;              //�ڼ�·��Ƶ��������
	BOOL32         bIsReSouceExist;   //������ƵԴ
	u32            dwFrameRate;       //֡��
	u32            dwBitrate;         //��Ƶ�������ʣ�Kbps
	u32            dwFormat;          //��Ƶ��ʽ����Ӧ��EmVidFormat
    u32            dwResolution;      //�ֱ��� EmMtResolution 
public:
	tagTVidSendStatus(){ memset(this, 0, sizeof(tagTVidSendStatus) );}
}TVidSendStatus;

//��Ƶ����״̬
typedef struct tagTVidRecStatus
{
	u32            dwId;              //�ڼ�·��Ƶ��������
	u32            dwFrameRate;       //֡��
	u32            dwPkTsLose;        //��Ƶ��������
	u32            dwPkTsLoseRate;    //��Ƶ������
	u32            dwBitrate;         //��Ƶ�������ʣ�Kbps
	u32            dwFormat;          //��Ƶ��ʽ����Ӧ��EmVidFormat
    u32            dwResolution;      //�ֱ��� EmMtResolution 
public:
	tagTVidRecStatus(){ memset(this, 0, sizeof(tagTVidRecStatus) );}
}TVidRecStatus;

//˫����Ϣ
typedef struct tagTDoubleFlowInfo
{
    u32            dwFrameRate;       //֡��
    u32            dwResolution;      //�ֱ��� EmMtResolution 
public:
    tagTDoubleFlowInfo(){ memset(this, 0, sizeof(tagTDoubleFlowInfo) );}
}TDoubleFlowInfo;

//�ն˻�����Ϣ
typedef struct tagTConfInfo
{
	s8             achConfE164[MT_E164_LEN+1];             //����E164��(������д)������ǵ�Ե������д���з�e164���룩
	s8             achMtE164[MT_E164_LEN+1];               //�ն�E164��(������д)
	u32            dwBitrate;                              //��������
    BOOL32         bMute;                                  //�Ƿ���TRUE-�ǣ� FALSE-��
    BOOL32         bDumbness;                              //�Ƿ�����TRUE-�ǣ� FALSE-��
	u8             byConfState;                            //�ն�״̬����nmscommon.txt���豸����(������д)
	TAudSendStatus atAudSendStatus[MAX_AENC_NUM];          //��Ƶ����״̬
	u8             byAudSendCnt;                           //��Ƶ����״̬����
	TAudRecStatus  atAudRecStatus[MAX_ADEC_NUM];           //��Ƶ����״̬
	u8             byAudRecCnt;                            //��Ƶ����״̬����
	TVidSendStatus atPriVidSendStatus[MAX_VENC_NUM];       //����Ƶ����״̬
	u8             byPriVidSendCnt;                        //����Ƶ����״̬����
	TVidRecStatus  atPriVidRecStatus[MAX_VDEC_NUM];        //����Ƶ����״̬
	u8             byPriVidRecCnt;                         //����Ƶ����״̬����
	TVidSendStatus atAssVidSendStatus[MAX_VENC_NUM];       //����Ƶ����״̬
	u8             byAssVidSendCnt;                        //����Ƶ����״̬����
	TVidRecStatus  atAssVidRecStatus[MAX_VDEC_NUM];        //����Ƶ����״̬
	u8             byAssVidRecCnt;                         //����Ƶ����״̬����
    BOOL32         bDoubleFlow;                            //˫��״̬��TRUE����/FALSE�ر�
    TDoubleFlowInfo tDoubleFlowInfo;                       //˫����Ϣ
    u8             byEncryption;                           //�ն˼�������
public:
	tagTConfInfo(){ memset(this, 0, sizeof(tagTConfInfo) );}
}TConfInfo;

//�豸������Ϣ
typedef struct tagTPMFInfo
{
	u32            dwCpuUseRate;                           //cpuʹ�ðٷֱ�
	u32            dwDiskUseRate;                          //Ӳ��ʹ�ðٷֱ�
	u32            dwMenUseRate;                           //�ڴ�ʹ�ðٷֱ�
public:
	tagTPMFInfo(){ memset(this, 0, sizeof(tagTPMFInfo) );}
}TPMFInfo;

//����汾�Ƿ����Ƽ��汾
typedef struct tagTVerInfo
{
	BOOL32         bRecommand;                             //����汾�Ƿ����Ƽ��汾
public:
	tagTVerInfo(){ memset(this, 0, sizeof(tagTVerInfo) );}
}TVerInfo;

//�쳣��־��Ϣ
typedef struct tagTExceptFileInfo
{
    s8             achTime[MT_STR_LEN_32+1];               //��2014/05/08:12:08:08������ʱ��(GMT��׼)(������д)
	s8             achContent[MT_LEN_8K+1];                //������־����(������д)
	s8             achVer[MT_STR_LEN_32+1];                //�汾��
public:
	tagTExceptFileInfo(){ memset(this, 0, sizeof(tagTExceptFileInfo) );}
}TExceptFileInfo;

//�������
typedef struct tagTNMSNetBandwidth
{
	u32            dwBandwidth;                           //����, ��λKB/s
	u16            wDropRate;                             //�ô����Ӧ�Ķ�����, ��λǧ��֮��
public:
	tagTNMSNetBandwidth(){ memset(this, 0, sizeof(tagTNMSNetBandwidth) );}
}TNMSNetBandwidth;

//����״��
typedef struct tagTNMSNetStatus
{
	TNMSNetBandwidth  tSend;                                 //���ʹ���(����), ��λKB/s
	TNMSNetBandwidth  tRecv;                                 //���մ���(����), ��λKB/s
}TNMSNetStatus;

typedef struct tagTMTCpuMemStatus
{
    u32 m_dwCpuUseRate;
    u32 m_dwMemUseRate;
public:
    tagTMTCpuMemStatus(){ memset( this, 0, sizeof(tagTMTCpuMemStatus) );}
}TMTCpuMemStatus;

typedef struct tagTMTAgentMicStatus
{
    s8 achName[MT_STR_LEN_16+1];
    BOOL32 bExceptionStatus;
public:
    tagTMTAgentMicStatus(){ memset( this, 0, sizeof(tagTMTAgentMicStatus) );}
}TMTAgentMicStatus;

typedef struct tagTMTAgentVideoSource
{
    s8 achIndex[MT_STR_LEN_16+1]; // ��ƵԴ����
    EmVideoType emType;           
public:
    tagTMTAgentVideoSource(){ memset( this, 0, sizeof(tagTMTAgentVideoSource) );}
}TMTAgentVideoSource;

typedef struct tagTMTAgentNetStatis
{
    s8 achNetCardName[MT_STR_LEN_16+1];
    u32 dwSendFlowAmount;
    u32 dwRecvFlowAmount;
    u32 dwNetCardType;
public:
    tagTMTAgentNetStatis(){ memset( this, 0, sizeof(tagTMTAgentNetStatis) );}
}TMTAgentNetStatis;

typedef struct tagTMTAgentNetStatisList
{
    u32 dwNetListNum;
    TMTAgentNetStatis atNetStatis[MT_MAX_NUM_10];
public:
    tagTMTAgentNetStatisList(){ memset( this, 0, sizeof(tagTMTAgentNetStatisList) );}
}TMTAgentNetStatisList;

typedef struct tagTMTDevicePerformInfo
{
    s8  achSipAddrInfo[MT_STR_LEN_128+1];    // SIP��������ַ��Ϣ
    s8  achGkAddrInfo[MT_STR_LEN_128+1];    // GK��������ַ��Ϣ
    BOOL32 m_bExceptionTempStatus;
    TMTCpuMemStatus m_tCpuMemInfo;
    TMTAgentNetStatisList m_tNetStatis;
    u32 dwMicCount;
    TMTAgentMicStatus m_atMicDeviceInfo[MT_MAX_NUM_5];
    u32 dwSrcCount;
    TMTAgentVideoSource m_atVideoSource[MT_MAX_NUM_5];
public:
    tagTMTDevicePerformInfo(){ memset( this, 0, sizeof(tagTMTDevicePerformInfo) );}
}TMTDevicePerformInfo;

//��־��ץ��������Ϣ
typedef struct tagTComFileInfo
{
    s8           achDevId[MT_STR_LEN_64+1];                 // �豸moid(������д)
    s8           achDevType[MT_STR_LEN_64+1];               // �豸����(���豸���Ͷ���)(������д)
    s8           achFileServerUploadDir[MT_STR_LEN_256+1];  // �ļ��ϴ�·��
    s8           achKey[MT_STR_LEN_128+1];                   //collector�������key �ж������ϴ�Ȩ��
    u32          dwFileServerPort;                          // �ļ��������˿�
public:
    tagTComFileInfo(){ memset(this, 0, sizeof(tagTComFileInfo) );}
}TComFileInfo;

//ץ��
typedef struct tagTPackageCapture
{
    s8           achNetCard[MT_STR_LEN_16+1]; // Ҫ����ץ��������
    TComFileInfo tComFileInfo;                // ץ����Ϣ
public:
    tagTPackageCapture(){ memset(this, 0, sizeof(tagTPackageCapture) );}
}TPackageCapture;

//ץ��
typedef struct tagTLogFileInfo
{
    s8           achFileName[MT_STR_LEN_64+1]; // ��־�ļ���
    s8           achFilePath[MT_STR_LEN_128+1]; // ��־·��
public:
    tagTLogFileInfo(){ memset(this, 0, sizeof(tagTLogFileInfo) );}
}TLogFileInfo;

//����
typedef struct tagTVolume
{
    u32 dwInput;   //��������
    u32 dwOutput;  //�������
public:
    tagTVolume(){ memset(this, 0, sizeof(tagTVolume) );}
}TVolume;

//��Ƶ��Ƶ�ź�״̬
typedef struct tagTAudVidSignal
{
    s8 achType[MT_STR_LEN_16+1];
    BOOL32 bStatus; //True-������ false-�쳣
public:
    tagTAudVidSignal(){ memset(this, 0, sizeof(tagTAudVidSignal)); }
}TAudVidSignal;

typedef struct tagTAudVidStatus
{
    u8 byAudInCnt;
    TAudVidSignal atAudInputSign[MT_MAX_NUM_5];

    u8 byAudOutCnt;
    TAudVidSignal atAudOutputSign[MT_MAX_NUM_5];

    u8 byVidInCnt;
    TAudVidSignal atVidInputSign[MT_MAX_NUM_5];
public:
    tagTAudVidStatus(){ memset(this, 0, sizeof(tagTAudVidStatus)); }
}TAudVidStatus;

#endif // _AGENTADPSTRUCT_H_
#ifndef _NVMFGTEST_STRUCT_
#define _NVMFGTEST_STRUCT_

#include "nvospmsgid.h"

#define MT_MAX_E1UNIT_NUM 4
#define MT_MAX_DNS_STR_LENGTH 128

#define SERVER_IP_ONE "10.1.1.1"    //���Թ��ߵ�IP��ַ

#define SERVER_LISTEN_PORT 60010//�����˿�

// IMIX��������(����;A:��Ƶ��V:��Ƶ��TV��Ĭ��HDMI�ĵ��ӣ�OL��ʾ����,FR����ʾFPGA���ţ�XVGA:1024*768�ֱ��ʣ�����Ĭ��1080P)
enum EmNvAutoTestType 
{
    emTestTypeBegin,            //�������Ϳ�ʼ
	emTestMainPlayVideoToOut12TRS,//1
	emTestHM1InVideoToOut12TV,//2
	emTestHM2InVideoToTRS,//3
	emTestOPSInVideoToTRS,//4
	emTestRCAMainInAudioToTRS,//5
	emTestRS232,//6	
	emTestRJ11,	//7
	emTestTRRX9Ping,//8
	emTestUSB,//9
	emTestRTC,//10
	emTestLANPort,//11	
	emTestIFACE12Ping,//12
    emTestTypeEnd               //�������ͽ���
};


enum EmMTAutoTestType
{
	emMTAutoTestBegin = -1,
	emMTAutoTestReset,      // ����
	emMTAutoTestRestart,    // ����
	emMTAutoTestNextIp,     // ��һվIP
	emMTAutoTestEnd,
};

//��˷�����״̬
enum EmNvMicConnectStatus
{
	emNvMicConnectNULL,			//û����˷� �����ն�
	emNvMicConnectWired,		//ֻ��������� �����ն�
	emNvMicConnectWireless,		//ֻ��������� �����ն�
	emNvMicConnectAll			//���ߺ�������� �������ն�
};

typedef u32   u32_ip;


#pragma pack(1)
/************************************************************************/
/* �ն�Ӳ���Զ�������
/************************************************************************/
// ������Ϣͷ�ṹ
typedef struct tagTNvAutoTestMsg
{	
    // �汾�� 0x0100
    u16  m_wProtocolIdentifer;

    // �������
    EmNvAutoTestType m_emTestType;

    // ��ʼ���Ա�־λ��TRUE����ʼ���ԣ�FALSE��ֹͣ����
    BOOL32 m_bTestStart;

    // ��Ƶ����
    ////nv::EmVideoType m_emVideoType;

    // ��Ƶ�˿�
    ////nv::EmNvVideoPort m_emVideoPort;

    // ���Խ��: 0��ʧ��; 1���ɹ���
    BOOL32 m_bTestResult; 

    // ����ʧ��ԭ��:1, Ӳ�����Խ��ʧ��; 2, �������ڽ���;  
    // 3, ��֧�ָ������; 4,�ն�״̬����;5, ��������汾�Ŵ���; 
    // �������ӷ�����Ϣ
    u8 m_byErrorReason;

    //�绰����
    //s8 m_achPhoneNumber[32+1]; 

    //�ֻ�����
    //s8 m_achSubPhoneNumber[32+1]; 

    //E1 ������ַ
    u32_ip m_adwLocalIp[MT_MAX_E1UNIT_NUM];

    //E1 ping��ַ
   // s8 m_achDstIp[MT_MAX_E1UNIT_NUM][MT_MAX_DNS_STR_LENGTH];
	u32_ip m_adwDstIp[MT_MAX_E1UNIT_NUM];
public:
    tagTNvAutoTestMsg(){ memset( this ,0 ,sizeof( struct  tagTNvAutoTestMsg ) );}
}TNvAutoTestMsg, *PTNvAutoTestMsg;


// ���Խ�����Ϣ�ṹ
typedef struct tagTNvAutoTestFinishMsg
{	
	// ���Խ�����־
	BOOL32  m_bAutoTestFinish;	//TURE�����Խ����� FALSE��������һվ���Թ���IP��ַ����PC����IP��ַ��

	//��һվ���Թ���IP��ַ
	u32 m_dwNextIp;

	//�Ƿ�ָ��������ã��ָ�Ĭ��ֵ��
	BOOL32 m_bFactoryReset;

	//�Ƿ�����
	BOOL32 m_bNvReboot;

public:
	tagTNvAutoTestFinishMsg(){ memset( this ,0 ,sizeof( struct  tagTNvAutoTestFinishMsg ) );}
}TNvAutoTestFinishMsg, *PTNvAutoTestFinishMsg;


//ʱ��ṹ���¶���
typedef struct tagTNvKdvTime
{
	u16 		m_wYear;//��
	u8  		m_byMonth;//��
	u8  		m_byMDay;//��
	u8  		m_byHour;//ʱ
	u8  		m_byMinute;//��
	u8  		m_bySecond;//��
public:
	tagTNvKdvTime(){ memset ( this ,0 ,sizeof( struct tagTNvKdvTime) );}
}TNvKdvTime, *PTNvKdvTime;


/************************************************************************/
/* Auto Test����Ĭ��ֵ����                                               */
/************************************************************************/
typedef struct tagTAutoTestSetDefaultCfg
{
	EmMTAutoTestType emType;  // ��Ϣ����
	u32_ip           dwNextIp;// ��һվ���Թ��ߵ�IP��ַ(PC��IP)��emTypeΪemMTAutoTestNextIpʱ��Ч
public:
	tagTAutoTestSetDefaultCfg()
	{
		emType = emMTAutoTestBegin;
		dwNextIp = 0;
	}
}TAutoTestSetDefaultCfg,*PTAutoTestSetDefaultCfg;

#pragma pack()

#endif
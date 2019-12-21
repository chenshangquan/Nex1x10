#ifndef _NVMFGTEST_STRUCT_
#define _NVMFGTEST_STRUCT_

#include "nvospmsgid.h"

#define MT_MAX_E1UNIT_NUM 4
#define MT_MAX_DNS_STR_LENGTH 128

#define SERVER_IP_ONE "10.1.1.1"    //测试工具的IP地址

#define SERVER_LISTEN_PORT 60010//监听端口

// IMIX测试类型(其中;A:音频，V:视频，TV：默认HDMI的电视，OL表示叠加,FR：表示FPGA缩放，XVGA:1024*768分辨率，其他默认1080P)
enum EmNvAutoTestType 
{
    emTestTypeBegin,            //测试类型开始
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
    emTestTypeEnd               //测试类型结束
};


enum EmMTAutoTestType
{
	emMTAutoTestBegin = -1,
	emMTAutoTestReset,      // 重置
	emMTAutoTestRestart,    // 重启
	emMTAutoTestNextIp,     // 下一站IP
	emMTAutoTestEnd,
};

//麦克风连接状态
enum EmNvMicConnectStatus
{
	emNvMicConnectNULL,			//没有麦克风 连接终端
	emNvMicConnectWired,		//只有有线麦克 连接终端
	emNvMicConnectWireless,		//只有无线麦克 连接终端
	emNvMicConnectAll			//有线和无线麦克 都连接终端
};

typedef u32   u32_ip;


#pragma pack(1)
/************************************************************************/
/* 终端硬件自动化测试
/************************************************************************/
// 测试消息头结构
typedef struct tagTNvAutoTestMsg
{	
    // 版本号 0x0100
    u16  m_wProtocolIdentifer;

    // 测试类别
    EmNvAutoTestType m_emTestType;

    // 开始测试标志位：TRUE，开始测试；FALSE，停止测试
    BOOL32 m_bTestStart;

    // 视频类型
    ////nv::EmVideoType m_emVideoType;

    // 视频端口
    ////nv::EmNvVideoPort m_emVideoPort;

    // 测试结果: 0，失败; 1，成功。
    BOOL32 m_bTestResult; 

    // 测试失败原因:1, 硬件测试结果失败; 2, 测试正在进行;  
    // 3, 不支持该项测试; 4,终端状态错误;5, 测试软件版本号错误; 
    // 其它附加返回信息
    u8 m_byErrorReason;

    //电话号码
    //s8 m_achPhoneNumber[32+1]; 

    //分机号码
    //s8 m_achSubPhoneNumber[32+1]; 

    //E1 本机地址
    u32_ip m_adwLocalIp[MT_MAX_E1UNIT_NUM];

    //E1 ping地址
   // s8 m_achDstIp[MT_MAX_E1UNIT_NUM][MT_MAX_DNS_STR_LENGTH];
	u32_ip m_adwDstIp[MT_MAX_E1UNIT_NUM];
public:
    tagTNvAutoTestMsg(){ memset( this ,0 ,sizeof( struct  tagTNvAutoTestMsg ) );}
}TNvAutoTestMsg, *PTNvAutoTestMsg;


// 测试结束消息结构
typedef struct tagTNvAutoTestFinishMsg
{	
	// 测试结束标志
	BOOL32  m_bAutoTestFinish;	//TURE：测试结束； FALSE：配置下一站测试工具IP地址（即PC机的IP地址）

	//下一站测试工具IP地址
	u32 m_dwNextIp;

	//是否恢复出厂设置（恢复默认值）
	BOOL32 m_bFactoryReset;

	//是否重启
	BOOL32 m_bNvReboot;

public:
	tagTNvAutoTestFinishMsg(){ memset( this ,0 ,sizeof( struct  tagTNvAutoTestFinishMsg ) );}
}TNvAutoTestFinishMsg, *PTNvAutoTestFinishMsg;


//时间结构重新定义
typedef struct tagTNvKdvTime
{
	u16 		m_wYear;//年
	u8  		m_byMonth;//月
	u8  		m_byMDay;//日
	u8  		m_byHour;//时
	u8  		m_byMinute;//分
	u8  		m_bySecond;//秒
public:
	tagTNvKdvTime(){ memset ( this ,0 ,sizeof( struct tagTNvKdvTime) );}
}TNvKdvTime, *PTNvKdvTime;


/************************************************************************/
/* Auto Test设置默认值请求                                               */
/************************************************************************/
typedef struct tagTAutoTestSetDefaultCfg
{
	EmMTAutoTestType emType;  // 消息类型
	u32_ip           dwNextIp;// 下一站测试工具的IP地址(PC的IP)，emType为emMTAutoTestNextIp时有效
public:
	tagTAutoTestSetDefaultCfg()
	{
		emType = emMTAutoTestBegin;
		dwNextIp = 0;
	}
}TAutoTestSetDefaultCfg,*PTAutoTestSetDefaultCfg;

#pragma pack()

#endif
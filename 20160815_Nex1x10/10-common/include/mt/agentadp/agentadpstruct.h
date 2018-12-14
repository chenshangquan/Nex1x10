#if !defined(_AGENTADPSTRUCT_H_)
#define _AGENTADPSTRUCT_H_
#include "mtconst.h"

enum EmVideoType
{
    emPriomVideo  = 0, //主流
    emSecondVideo = 1  //辅流
};

//设备网络信息
typedef struct tagTDevNetInfo
{
	s8          achDevIp[MT_STR_LEN_16+1];       //IP
	s8          achDevDns[MT_STR_LEN_16+1];      //Dns
    s8          achSipProtocol[MT_STR_LEN_16+1];  //sip链路类型
public:
	tagTDevNetInfo(){ memset(this, 0, sizeof(tagTDevNetInfo) );}
}TDevNetInfo;

//aps的信息
typedef struct tagTApsAddr
{
	s8           achDomain[MT_STR_LEN_128+1];     //域名
	s8           achIp[MT_STR_LEN_128+1];         //ip
public:
	tagTApsAddr(){ memset(this, 0, sizeof(tagTApsAddr) );}
}TApsAddr;

//终端基本信息
typedef struct tagTMtInfo
{
	TDevNetInfo  tNetInfo;                        // 设备网络信息
	TApsAddr     tApsAdrr;                        // aps地址信息（用来查看使用运营商是否正确）
	s8           achDevVer[MT_STR_LEN_128+1];     // 设备版本号(必须填写)
	s8           achDevName[MT_STR_LEN_128+1];    // 设备名称(必须填写)
	s8           achOEM[MT_STR_LEN_128+1];        // 软件版本的oem标志
	s8           achOS[MT_STR_LEN_128+1];         // 操作系统
	u8           byCpuNum;                        // cpu核数
	s8           achCpuType[MT_STR_LEN_128+1];    // cpu型号
	u32          dwCpuFreq;                       // cpu主频(Mhz)
	u32          dwMemory;                        // 内存总量(M)
public:
	tagTMtInfo(){ memset(this, 0, sizeof(tagTMtInfo) );}
}TMtInfo;


//设备注册信息
typedef struct tagTDevRegInfo
{
    s8           achSipAddrInfo[MT_STR_LEN_128+1];    // SIP服务器地址信息
    s8           achGkAddrInfo[MT_STR_LEN_128+1];    // GK服务器地址信息
	s8           achDevId[MT_STR_LEN_128+1];      // 设备moid(必须填写)
	s8           achDevType[MT_STR_LEN_128+1];    // 设备类型(见设备类型定义)(必须填写)
	TMtInfo      tMtInfo;                         // 终端基本信息
public:
	tagTDevRegInfo(){ memset(this, 0, sizeof(tagTDevRegInfo) );}
}TDevRegInfo;

//所有应该链接的服务器类型
typedef struct tagTConServiceTypes
{
	s8           aachServices[MT_STR_LEN_64][MT_STR_LEN_128+1];
	u8           byCnt;
public:
	tagTConServiceTypes(){ memset(this, 0, sizeof(tagTConServiceTypes) );}
}TConServiceTypes;

//链接服务器
typedef struct tagTConService
{
	s8          achService[MT_STR_LEN_128+1];
	s8          achIp[MT_STR_LEN_16+1];
public:
	tagTConService(){ memset(this, 0, sizeof(tagTConService) );}
}TConService;

//链接上的服务器
typedef struct tagTConServices
{
	TConService  atConSvrs[MT_STR_LEN_64];
	u8           byCnt;
public:
	tagTConServices(){ memset(this, 0, sizeof(tagTConServices) );}
}TConServices;

//告警信息
typedef struct tagTAlarmInfo
{
	u32            dwCodeId;                          //告警码
	BOOL32         bStatus;                           //TRUE表示告警，FALSE表示恢复
	s8             achTime[MT_STR_LEN_32+1];          //“2014/05/08:12:08:08”北京时间(GMT标准)
public:
	tagTAlarmInfo(){ memset(this, 0, sizeof(tagTAlarmInfo) );}
}TAlarmInfo;

//音频发送状态
typedef struct tagTAudSendStatus
{
	u32            dwId;              //第几路音频发送码流
	u32            dwBitrate;         //上行音频码率，Kbps
	u32            dwFormat;          //音频格式，对应于EmAudFormat
public:
	tagTAudSendStatus(){ memset(this, 0, sizeof(tagTAudSendStatus) );}
}TAudSendStatus;

//音频接收状态
typedef struct tagTAudRecStatus
{
	u32            dwId;              //第几路音频发送码流
	u32            dwPkTsLose;        //频音音频丢包总数
	u32            dwPkTsLoseRate;    //音频丢包率
	u32            dwBitrate;         //下行音频码率，Kbps
	u32            dwFormat;          //音频格式，对应于EmAudFormat
public:
	tagTAudRecStatus(){ memset(this, 0, sizeof(tagTAudRecStatus) );}
}TAudRecStatus;

//视频发送状态
typedef struct tagTVidSendStatus
{
	u32            dwId;              //第几路音频发送码流
	BOOL32         bIsReSouceExist;   //有无视频源
	u32            dwFrameRate;       //帧率
	u32            dwBitrate;         //视频上行码率，Kbps
	u32            dwFormat;          //视频格式，对应于EmVidFormat
    u32            dwResolution;      //分辨率 EmMtResolution 
public:
	tagTVidSendStatus(){ memset(this, 0, sizeof(tagTVidSendStatus) );}
}TVidSendStatus;

//视频接收状态
typedef struct tagTVidRecStatus
{
	u32            dwId;              //第几路音频发送码流
	u32            dwFrameRate;       //帧率
	u32            dwPkTsLose;        //视频丢包总数
	u32            dwPkTsLoseRate;    //视频丢包率
	u32            dwBitrate;         //视频下行码率，Kbps
	u32            dwFormat;          //视频格式，对应于EmVidFormat
    u32            dwResolution;      //分辨率 EmMtResolution 
public:
	tagTVidRecStatus(){ memset(this, 0, sizeof(tagTVidRecStatus) );}
}TVidRecStatus;

//双流信息
typedef struct tagTDoubleFlowInfo
{
    u32            dwFrameRate;       //帧率
    u32            dwResolution;      //分辨率 EmMtResolution 
public:
    tagTDoubleFlowInfo(){ memset(this, 0, sizeof(tagTDoubleFlowInfo) );}
}TDoubleFlowInfo;

//终端会议信息
typedef struct tagTConfInfo
{
	s8             achConfE164[MT_E164_LEN+1];             //会议E164号(必须填写)（如果是点对点会议填写主叫方e164号码）
	s8             achMtE164[MT_E164_LEN+1];               //终端E164号(必须填写)
	u32            dwBitrate;                              //呼叫码率
    BOOL32         bMute;                                  //是否静音TRUE-是， FALSE-否
    BOOL32         bDumbness;                              //是否哑音TRUE-是， FALSE-否
	u8             byConfState;                            //终端状态，见nmscommon.txt中设备定义(必须填写)
	TAudSendStatus atAudSendStatus[MAX_AENC_NUM];          //音频发送状态
	u8             byAudSendCnt;                           //音频发送状态总数
	TAudRecStatus  atAudRecStatus[MAX_ADEC_NUM];           //音频接收状态
	u8             byAudRecCnt;                            //音频发送状态总数
	TVidSendStatus atPriVidSendStatus[MAX_VENC_NUM];       //主视频发送状态
	u8             byPriVidSendCnt;                        //主视频发送状态总数
	TVidRecStatus  atPriVidRecStatus[MAX_VDEC_NUM];        //主视频接收状态
	u8             byPriVidRecCnt;                         //主视频发送状态总数
	TVidSendStatus atAssVidSendStatus[MAX_VENC_NUM];       //辅视频发送状态
	u8             byAssVidSendCnt;                        //辅视频发送状态总数
	TVidRecStatus  atAssVidRecStatus[MAX_VDEC_NUM];        //辅视频接收状态
	u8             byAssVidRecCnt;                         //辅视频发送状态总数
    BOOL32         bDoubleFlow;                            //双流状态：TRUE开启/FALSE关闭
    TDoubleFlowInfo tDoubleFlowInfo;                       //双流信息
    u8             byEncryption;                           //终端加密类型
public:
	tagTConfInfo(){ memset(this, 0, sizeof(tagTConfInfo) );}
}TConfInfo;

//设备性能信息
typedef struct tagTPMFInfo
{
	u32            dwCpuUseRate;                           //cpu使用百分比
	u32            dwDiskUseRate;                          //硬盘使用百分比
	u32            dwMenUseRate;                           //内存使用百分比
public:
	tagTPMFInfo(){ memset(this, 0, sizeof(tagTPMFInfo) );}
}TPMFInfo;

//软件版本是否是推荐版本
typedef struct tagTVerInfo
{
	BOOL32         bRecommand;                             //软件版本是否是推荐版本
public:
	tagTVerInfo(){ memset(this, 0, sizeof(tagTVerInfo) );}
}TVerInfo;

//异常日志信息
typedef struct tagTExceptFileInfo
{
    s8             achTime[MT_STR_LEN_32+1];               //“2014/05/08:12:08:08”北京时间(GMT标准)(必须填写)
	s8             achContent[MT_LEN_8K+1];                //崩溃日志内容(必须填写)
	s8             achVer[MT_STR_LEN_32+1];                //版本号
public:
	tagTExceptFileInfo(){ memset(this, 0, sizeof(tagTExceptFileInfo) );}
}TExceptFileInfo;

//网络带宽
typedef struct tagTNMSNetBandwidth
{
	u32            dwBandwidth;                           //带宽, 单位KB/s
	u16            wDropRate;                             //该带宽对应的丢包率, 单位千分之几
public:
	tagTNMSNetBandwidth(){ memset(this, 0, sizeof(tagTNMSNetBandwidth) );}
}TNMSNetBandwidth;

//网络状况
typedef struct tagTNMSNetStatus
{
	TNMSNetBandwidth  tSend;                                 //发送带宽(上行), 单位KB/s
	TNMSNetBandwidth  tRecv;                                 //接收带宽(下行), 单位KB/s
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
    s8 achIndex[MT_STR_LEN_16+1]; // 视频源名称
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
    s8  achSipAddrInfo[MT_STR_LEN_128+1];    // SIP服务器地址信息
    s8  achGkAddrInfo[MT_STR_LEN_128+1];    // GK服务器地址信息
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

//日志，抓包公共信息
typedef struct tagTComFileInfo
{
    s8           achDevId[MT_STR_LEN_64+1];                 // 设备moid(必须填写)
    s8           achDevType[MT_STR_LEN_64+1];               // 设备类型(见设备类型定义)(必须填写)
    s8           achFileServerUploadDir[MT_STR_LEN_256+1];  // 文件上传路径
    s8           achKey[MT_STR_LEN_128+1];                   //collector根据这个key 判断有无上传权限
    u32          dwFileServerPort;                          // 文件服务器端口
public:
    tagTComFileInfo(){ memset(this, 0, sizeof(tagTComFileInfo) );}
}TComFileInfo;

//抓包
typedef struct tagTPackageCapture
{
    s8           achNetCard[MT_STR_LEN_16+1]; // 要进行抓包的网口
    TComFileInfo tComFileInfo;                // 抓包信息
public:
    tagTPackageCapture(){ memset(this, 0, sizeof(tagTPackageCapture) );}
}TPackageCapture;

//抓包
typedef struct tagTLogFileInfo
{
    s8           achFileName[MT_STR_LEN_64+1]; // 日志文件名
    s8           achFilePath[MT_STR_LEN_128+1]; // 日志路径
public:
    tagTLogFileInfo(){ memset(this, 0, sizeof(tagTLogFileInfo) );}
}TLogFileInfo;

//音量
typedef struct tagTVolume
{
    u32 dwInput;   //输入音量
    u32 dwOutput;  //输出音量
public:
    tagTVolume(){ memset(this, 0, sizeof(tagTVolume) );}
}TVolume;

//音频视频信号状态
typedef struct tagTAudVidSignal
{
    s8 achType[MT_STR_LEN_16+1];
    BOOL32 bStatus; //True-正常， false-异常
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
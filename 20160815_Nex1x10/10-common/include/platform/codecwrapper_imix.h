/*****************************************************************************
  模块名      : CodecHisi3798.a
  文件名      : codecwrapper_imix.h
  相关文件    : 
  文件实现功能: 
  作者        : 朱允荣
  版本        : V4.0  Copyright(C) 2007-2016 KDC, All rights reserved.
-----------------------------------------------------------------------------
修改记录:
日  期      版本        修改人      修改内容
******************************************************************************/
#ifndef _CODECWRAPPER_IMIX_H_
#define _CODECWRAPPER_IMIX_H_

#include "kdvtype.h"
#include "osp.h"

typedef void (*PASKIFRAMEPROC )(void* pContext);//请求KEY FRAME回调

typedef void (*PMediaSystemErrorCallBack )(void* pContext);//解码器遇到不可恢复异常报错回调，通知业务重启2018.04.11 add by wj 


//错误码
#define ERROR_CODE_BASE             30000             
#define CODEC_NO_ERROR              0//无错
enum
{
	AUDIO_MODE_MP3 = 4,
	AUDIO_MODE_PCMA = 5,
	AUDIO_MODE_PCMU,
	AUDIO_MODE_G723_6,
	AUDIO_MODE_G723_5,
	AUDIO_MODE_G728,
	AUDIO_MODE_G722,
	AUDIO_MODE_G729,
	AUDIO_MODE_G719,
	AUDIO_MODE_G7221,
	AUDIO_MODE_ADPCM,
	AUDIO_MODE_OPUS,
	AUDIO_MODE_AACLC_32,     //32K 双声道
	AUDIO_MODE_AACLC_32_M,   //32K 单声道
	AUDIO_MODE_AACLC_48,     //48K 双声道
	AUDIO_MODE_AACLC_48_M,   //48K 单声道
	AUDIO_MODE_AACLD_32,
	AUDIO_MODE_AACLD_32_M,
	AUDIO_MODE_AACLD_48,
	AUDIO_MODE_AACLD_48_M
};
//音频采样率索引
typedef enum 
{
    SAMPLE_RATE48000,     //采样率为48kHz的索引是0
    SAMPLE_RATE44100,     //采样率为44.1kHz的索引是1
    SAMPLE_RATE32000,     //采样率为32kHz的索引是2
    SAMPLE_RATE16000,     //采样率为16kHz的索引是3
    SAMPLE_RATE8000,       //采样率为8kHz的索引是4
    SAMPLE_RATE0          //采样率为0 的索引是5  相当于驱动静音
}enSampleRate;

enum enCodecErr
{
	Codec_Success = CODEC_NO_ERROR,

	Codec_Error_Base = ERROR_CODE_BASE,
	Codec_Error_Param,
	Codec_Error_CPUID,
	Codec_Error_Codec_NO_Create,
	Codec_Error_Audio_CapInstance,
	Codec_Error_Audio_PlyInstance,
	Codec_Error_CreateThread,
	Codec_Error_FastUpdateTooFast,
	Codec_Error_WriteToDSP,
	Codec_Error_CreateHPIChannel,
	Codec_Error_GetMem,
	Codec_Error_GetBMP,
	Codec_Error_SetZoomMode,
	Codec_Error_SetZorder,
	Codec_Error_SnapShotGetOutPutStdNull,
	Codec_Error_SnapShotError
};

typedef struct tagVidDecInit
{
	u32     dwIndex;						//0 - main decoder; 1 - aux decoder; 2 - dual view decoder
	u32     dwVidPort;						
	u32     dwPlayStd;						//video口制式，only decoder
	u32     dwReserve;						//保留参数，若适配功能带，则此处扩展参数(TAdapterInfo)
	
}TVidDecImix;

typedef struct tagCodecInit
{	
	u32     dwChnID;   // 0,1....
	u32     dwPlyPort; //采集端口
}TDecoder;

typedef struct tagVidFrameInfo
{
	BOOL32    m_bKeyFrame;    //频帧类型（I or P）
	u16       m_wVideoWidth;  //视频帧宽
	u16       m_wVideoHeight; //视频帧宽
}
TVidFrameInfo;

typedef struct tagFrameHeader
{
	u32     m_dwMediaType;    //码流类型
	u32     m_dwFrameID;      //帧标识，用于接收端
	u32     m_dwSSRC;         //同步源信息，用于接收端
	u8*     m_pData;          //音视频数据
	u32     m_dwDataSize;     //数据长度
	u32		m_dwFPS;		  //帧率
	u32     m_dwTimeStamp;    //时间戳
    union
    {
		TVidFrameInfo m_tVideoParam;
        u32           m_dwAudioMode;//音频模式
        BOOL32    m_bUseAudioLevel; //是否使用audio level
        BOOL32 	  m_bVadFlag; //是否为语音
	    u8		  m_byAudioLevel; // 音频能量级 0~127(-dBov)
    };
}
TFrameHeader, *PTFrameHeader;

/*解码器状态*/
typedef struct tagKdvDecStatus
{
	BOOL32	m_bDecStart;         /*是否开始解码*/	
	u32     m_dwAudioDecType;    /*解码类型*/
    u32     m_dwHeart;           /*解码线程心跳*/
	u32     m_dwPos;             /*解码线程位置*/
    u32     m_dwDecType;
}TKdvDecStatus;

/*解码器统计信息*/
typedef struct tagKdvDecStatis
{
	u16	   m_wFrameRate;           /*解码帧率*/
    u16    m_wLoseRatio;           /*丢失率,单位是%*/ 
	u32    m_dwRecvFrame;          /*收到的帧数*/
	u32    m_dwLoseFrame;          /*丢失的帧数*/		
	u32    m_dwPackError;          /*乱帧数*/ 
	u32    m_dwIndexLose;          /*序号丢帧*/
	u32    m_dwSizeLose;           /*大小丢帧*/
	u32    m_dwFullLose;           /*满丢帧*/	
	u16	   m_wBitRate;             /*视频解码码率*/
	u16    m_wAvrVideoBitRate;     /*1分钟内解码平均码率*/
	BOOL32 m_bVidCompellingIFrm;   /*视频强制请求I帧*/								  
	u32    m_dwDecdWidth;	       /*码流的宽*/
	u32    m_dwDecdHeight;         /*码流的高*/
}TKdvDecStatis;

typedef struct tagVidSrcInfo
{
    u16	    m_wWidth;                     /* 视频宽，像素为单位,为0表示无信号 */
    u16	    m_wHeight;                    /* 视频高，行为单位,为0表示无信号 */
    BOOL32  m_bProgressive;               /* 逐行或隔行，TRUE=逐行；FALSE=隔行 */
    u32     m_dwFrameRate;                /* 帧率，逐行时=场频，隔行时=场频/2，即60i=30P,为0表示无信号 */
}
TVidSrcInfo;


#define MAX_VID_PLAY_INTFACE 10
typedef struct tagVidPortInfo
{
  TVidSrcInfo m_tVidSrcInfo;	//视频制式
	u32         m_dwNumPort;
	union
	{
		u32			m_dwVidPort;	//视频端口		
		u32			m_dwVidPortList[MAX_VID_PLAY_INTFACE];	//视频端口			
		u32			m_dwNetraVpssVp;
	};
}
TVidPortInfo;

typedef struct tagAudSrcInfo
{
	BOOL32 bAudHdmi0; //AUDIF_HDMI(0)  i-mix hdmi音频
	BOOL32 bAudHdmi1; //AUDIF_HDMI(1)  为OPSTV 音频 a 
	BOOL32 bAudHdmi2; //AUDIF_HDMI(2)  为terminal 音频
	BOOL32 bAudHdmi3; //AUDIF_HDMI(3)  为OPSTV 音频 b 
	BOOL32 bAudHdmi4; //AUDIF_HDMI(4)  i-mix i2S音频
	BOOL32 bAudRca;   //AUDIF_RCA(0)   为RCA接口的音频
}TAudSrcInfo;

//无视频输出时播放策略
enum enPlayMode
{
	EN_PLAY_LAST = 0, //播放上一帧
	EN_PLAY_BLACK,    //黑色背景
	EN_PLAY_BMP,      //默认图片
	EN_PLAY_BMP_USER,  //用户定义图片
	EN_PLAY_ERROR
};

/*图象参数*/
enum
{
    VID_SCALE_BRIGHTNESS = 0, /* 设置亮度，  C | YPbPr */
    VID_SCALE_CONTRAST,       /* 设置对比度，C | YPbPr */
    VID_SCALE_HUE,            /* 设置色度，  C */
    VID_SCALE_SATURATION      /* 设置饱和度，C | YPbPr */
};

enum
{
	VID_OUTTYPE_ORIGIN = 0,	//原始比例播放
	VID_OUTTYPE_720P50,		//固定按 720p50输出
	VID_OUTTYPE_720P60,		//固定按 720p60输出
	VID_OUTTYPE_1080P24,	//固定按1080p24输出
	VID_OUTTYPE_1080P25,	//固定按1080p25输出
	VID_OUTTYPE_1080P30,	//固定按1080p30输出
	VID_OUTTYPE_1080P50,	//固定按1080p50输出
	VID_OUTTYPE_1080P60,	//固定按1080p60输出 
	VID_OUTTYPE_XGA60,	  //固定按XGA 60HZ输出 1024x768
	VID_OUTTYPE_SXGA60,	  //固定按SXGA 60HZ输出  1280x1024
	VID_OUTTYPE_WXGA1280x800_60,	  //固定按WXGA 60HZ输出 1280x800
	VID_OUTTYPE_WXGA1366x768_60,	  //固定按WXGA 60HZ输出 1360x768
	VID_OUTTYPE_WSXGA60,	  //固定按WSXGA 60HZ输出 1440x900
	VID_OUTTYPE_WSXGAPLUS60,	  //固定按SXGA+ 60HZ输出 1680x1050
	VID_OUTTYPE_2160P30,	//固定按2160P30输出 3860*2160
	VID_OUTTYPE_2160P60,	//固定按2160P60输出 3860*2160  
	//VID_OUTTYPE_WXGA1280x768_60,	  //固定按WXGA 60HZ输出 1280x768
};

enum enZoomMode
{
    EN_ZOOM_FILLBLACK = 0,//加黑边
    EN_ZOOM_CUT,//裁边
    EN_ZOOM_SCALE//不等比拉伸
};

//fpga用来在IMIX 上叠加小画面
typedef struct 
{
	u32 prohibit_start_x;
	u32 prohibit_start_y;
	u32 prohibit_end_x;
	u32 prohibit_end_y;
	u32 prohibit_start_x_2;
	u32 prohibit_start_y_2;
	u32 prohibit_end_x_2;
	u32 prohibit_end_y_2;
	u32 prohibit_start_x_3;
	u32 prohibit_start_y_3;
	u32 prohibit_end_x_3;
	u32 prohibit_end_y_3;
	u32 prohibit_start_x_4;
	u32 prohibit_start_y_4;
	u32 prohibit_end_x_4;
	u32 prohibit_end_y_4;
}TMcVidProhibitArea;

typedef struct 
{
	u32 flag; 		 //参数2/3代表2画面还是3画面合成 
	u32 start_x;
	u32 start_y;
	u32 height;
	u32 width;
	TMcVidProhibitArea tArea;
}TVidOverleyScreen;


/* 音频输入输出接口宏定义 */
#define AUDIO_HDMI0					0x00000001//HDMI0
#define AUDIO_C0					0x00000030//c端
#define AUDIO_35mm0					0x00100000//3.5mm0

API void CodecCmdReg();
API void FpgaCmdReg();

class CVideoDecoder;
class CAudioDecoder;

class CKdvVidDec
{
public:
	CKdvVidDec();
	~CKdvVidDec();
public:
	/************************************************************************/
	/* 函数名:    Create                                                    */  
	/* 函数参数:                                                            */
	/*            TNetraCodecInfo* pDec    解码器创建参数                   */
	/* 函数功能:  解码器创建												*/
	/************************************************************************/
    u16    Create(TVidDecImix* pDec);

	/************************************************************************/
	/* 函数名:      SetData                                                 */  
	/* 函数参数:                                                            */
	/*              TFrameHeader& tFrameInfo                                */
	/* 函数功能:	设置视频码流数据										*/
	/************************************************************************/
	u16    SetData(const TFrameHeader& tFrameInfo); 
	
	/************************************************************************/
	/* 函数名:      StartDec                                                */  
	/* 函数参数:                                                            */
	/*              无                                                      */
	/* 函数功能:	开始图像解码										    */
	/************************************************************************/
    u16    StartDec();

	/************************************************************************/
	/* 函数名:      StopDec                                                 */  
	/* 函数参数:                                                            */
	/*              无                                                      */
	/* 函数功能:	停止图像解码										    */
	/************************************************************************/
    u16    StopDec(); 

	/************************************************************************/
	/* 函数名:      GetDecoderStatus                                        */  
	/* 函数参数:                                                            */
	/*              TKdvDecStatus &tKdvDecStatus 见结构体说明               */
	/* 函数功能:	获取解码状态信息										*/
	/************************************************************************/
	u16    GetDecoderStatus(TKdvDecStatus &tKdvDecStatus);

	/************************************************************************/
	/* 函数名:      GetDecoderStatis                                        */  
	/* 函数参数:                                                            */
	/*              TKdvDecStatis &tKdvDecStatis 见结构体说明               */
	/* 函数功能:	获取解码器的统计信息									*/
	/************************************************************************/
	u16    GetDecoderStatis(TKdvDecStatis &tKdvDecStatis);		
  
	/************************************************************************/
	/* 函数名:      SetPlayScale                                            */  
	/* 函数参数:                                                            */
	/*               u16 wWidth  :显示宽比例，0为自动                       */
	/*               u16 wHeight :显示高比例，0为自动						*/
	/* 函数功能:	设置播放设备的显示比例									*/
	/*               播放制式为16:9,设置4:3后图像上下加黑边                 */
	/*               播放制式为4:3,设置16:9后图像左右加黑边                 */
	/************************************************************************/
    u16    SetPlayZoomMode(enZoomMode emZoomMode);
    
	/************************************************************************/
	/* 函数名:      SetVideoPlyInfo                                         */  
	/* 函数参数:                                                            */
	/*              dwOutType  播放制式， 默认空则维持原有制式	            */
	/* 函数功能:	设置解码播放口制式										*/
	/************************************************************************/   
    u16	   SetVideoPlyInfo( u32 dwOutType /*= VID_OUTTYPE_ORIGIN*/ );

	/************************************************************************/
	/* 函数名:      GetVideoPlyInfo                                         */  
	/* 函数参数:                                                            */
	/*              TVidSrcInfo& tInfo 见结构体说明         	            */
	/* 函数功能:	获取解码播放口制式										*/
	/************************************************************************/  
	u16    GetVideoPlyInfo(TVidSrcInfo& tInfo);   

	/************************************************************************/
	/* 函数名:     SnapShot                                                 */  
	/* 函数参数:                                                            */
	/*             s8* pFileName    文件的全路径                            */
	/* 函数功能:   保存一帧播放图像为jpeg文件								*/
	/************************************************************************/
	u16    SnapShot(s8* pFileName);

	/************************************************************************/
	/* 函数名:     RegAskIFrameCallBack                                      */  
	/* 函数参数:                                                             */
	/*           PASKIFRAMEPROC pFrameCallBackProc     请求I帧的回调函数    */
	/*           void* pContext    用户上下文         						*/
	/*			u32 dwRequestIDRIntervalms   回调间隔						*/
	/* 函数功能:	设置解码IDR帧回调										*/
	/************************************************************************/
	u16    RegAskIFrameCallBack(PASKIFRAMEPROC pFrameCallBackProc, void* pContext, u32 dwRequestIDRIntervalms);

	/************************************************************************/
	/* 函数名:     SetVidPlayPolicy                                          */  
	/* 函数参数:                                                             */
	/*           u32 dwTimeout     超时(ms)                                  */
	/*           u32 dwPlayType    无图像填充类型  目前只支持最后一帧和黑屏  */
	/* 函数功能:	设置解码播放无图像显示策略							     */
	/************************************************************************/
	u16    SetVidPlayPolicy(u32 dwTimeout = 5000, u32 dwPlayType = EN_PLAY_LAST);

	/************************************************************************/
	/* 函数名:     SetShowRect                                          */  
	/* 函数参数:                                                             */
	/*           BOOL32 minimize        TRUE:最小化  FALSE：最大化           */
	/* 函数功能:	设置解码播放图像的显示图层							     */
	/************************************************************************/
	u16    SetShowRect(BOOL32 bMinimize);

protected:
private:
	CVideoDecoder *m_pCodec;
};

class CKdvAudDec
{
public:
	CKdvAudDec();
	~CKdvAudDec();
public:
	u16	   CreateDecoder(TDecoder *pDecoer, u32 dwDevVersion);
	u16    GetDecoderStatus(TKdvDecStatus &tKdvDecStatus);/*获取解码器状态*/
    u16    GetDecoderStatis(TKdvDecStatis &tKdvDecStatis);/*获取解码器的统计信息*/	
    u16    SetData(const TFrameHeader& tFrameInfo); /*设置音频码流数据*/   
    u16    StartDec();/*开始声音解码*/	
    u16    StopDec(); /*停止声音解码*/	
	u16    SetAudOutPort(u32 dwAudPort);   //imix-c    不用
	u16    PlayRing(s8* pszFilePath = NULL);
	u16    StopRing();                      
protected:
private:
	CAudioDecoder *m_pCodec;
};

//接口FPGA设置
void InitEnv();

u16 RegMediaSystemErrorCallBack(PMediaSystemErrorCallBack pCallBack, void* pContext);

void GetVidOutPortType(u32 dwVidIntf, u32 &dwRealPortType, TVidSrcInfo& tStd);

/************************************************************************/
/* 函数名:     SetHdmiSwitch                                            */  
/* 函数参数:                                                            */     
/*                   BOOL32 bOn=1 两个开关同时拉高，3798数据不经过FPGA  */
/*                   BOOL32 bOn=0 两个开关同时拉低，3798数据可以经过FPGA*/
/* 函数功能:	设置HDMI开关，控制数据			            			*/
/************************************************************************/
u16 SetHdmiSwitch(BOOL32 bUp);

/************************************************************************/
/* 函数名:     GetHdmiSwitch                                            */  
/* 函数参数:                                                            */
/*                   BOOL32 bOn=1 两个开关同时拉高，3798数据不经过FPGA  */
/*                   BOOL32 bOn=0 两个开关同时拉低，3798数据可以经过FPGA*/
/* 函数功能:	获取HDMI开关状态，控制数据			            		*/
/************************************************************************/
u16 GetHdmiSwitch(BOOL32 &bUp);

/************************************************************************/
/* 函数名:     SetVidInPortStd                                    */  
/* 函数参数:                                                            */
/*             u32 dwIntf  物理输入接口宏                               */
/*                         VIDIF_DSP_VP(0, 0)  i-mix为非OSD             */
/*	                       VIDIF_OSD_VP(0, 0)  i-mix为OSD               */
/*	                       VIDIF_HDMI(0)  为OPSTV porta                 */
/*	                       VIDIF_HDMI(2)  为OPSTV portb                 */
/*	                       VIDIF_HDMI(1)  为terminal                    */
/*             u32 dwPortType                制式枚举                   */
/* 函数功能:	设置视频输入端口参数			            		    */
/************************************************************************/
u16 SetVidInPortStd(u32 dwSrcIntf, u32 dwPortType);


/************************************************************************/
/* 函数名:     SetAdStatus                                            */  
/* 函数参数:                                                            */
/*             u32 dwSrcIntf  物理输入接口宏                               */
/*                         VIDIF_DSP_VP(0, 0)  i-mix为非OSD             */
/*	                       VIDIF_OSD_VP(0, 0)  i-mix为OSD               */
/*	                       VIDIF_HDMI(0)  为OPSTV porta                 */
/*	                       VIDIF_HDMI(2)  为OPSTV portb                 */
/*	                       VIDIF_HDMI(1)  为terminal                    */
/*             BOOL32 bStart               是否开启dwIntf对应的芯片     */
/* 函数功能:	通过接口设置该接口对应的AD/DA芯片的启停      		    */
/*																		*/
/************************************************************************/
u16 SetAdStatus(u32 dwSrcIntf, BOOL32 bStart);

/************************************************************************/
/* 函数名:     ReSetAd                                            */  
/* 函数参数:                                                            */
/* u32 dwSrcIntf  为物理输入视频（source intf）接口，分为以下几种：*/
/*              VIDIF_DSP_VP(0, 0)  VIDIF_OSD_VP(0, 0)  都表示复位第一块7619芯片，接收hi3798芯片的那块            */
/*	           VIDIF_HDMI(0)   VIDIF_HDMI(2) 都表示复位第二块7619芯片，连着前面板和opstv的那块  */
/*	           VIDIF_HDMI(1)  复位第3块7619芯片，接收终端输入的那块*/
/* 函数功能: 通过接口设置该接口对应的AD/DA芯片的启停  	    */
/*																		                   */
/************************************************************************/
u16 ReSetAd(u32 dwSrcIntf);

/************************************************************************/
/* 函数名:     GetVidInPortInfo                                    */  
/* 函数参数:                                                            */
/*             u32 dwIntf  物理输入接口宏                               */
/*                         VIDIF_DSP_VP(0, 0)  i-mix为非OSD             */
/*	                       VIDIF_OSD_VP(0, 0)  i-mix为OSD               */
/*	                       VIDIF_HDMI(0)  为OPSTV porta                 */
/*	                       VIDIF_HDMI(2)  为OPSTV portb                 */
/*	                       VIDIF_HDMI(1)  为terminal                    */
/*             u32 &dwRealPortType     制式枚举                         */
/*             BOOL32 bVideoSignal     是否有信号对Porta/portb有效      */
/*                    TVidSrcInfoe     见结构体                         */
/* 函数功能:	设置视频输入端口参数			            		    */
/************************************************************************/
void GetVidInPortInfo(u32 dwSrcIntf, u32 &dwRealPortType, TVidSrcInfo& tStd, BOOL32 &bVideoSignal);
/************************************************************************/
/* 函数名:     SetVidOsdParam                                           */  
/* 函数参数:                                                            */
/*             u32 dwIntf  物理输出接口宏VIDIF_HDMI(0)或者VIDIF_HDMI(1) */
/*             TVidSrcInfo &tOsd0Std osd需要缩放后的宽高    			*/
/*             u32 dwTransVal 0-0xff 0：全透 255：不透明    			*/
/*             u32 dwTransKeyY 0x10-0xf0                        	    */
/*             BOOL32 bMid 居中                                	        */
/* 函数功能:	设置OSD缩放参数接口			            				*/
/************************************************************************/
u16 SetVidOsdParam(u32 dwVidPortType, u32 dwOsdPortType, u32 dwTransVal, u32 dwTransKeyY, BOOL32 bCutEnable, BOOL32 bMid);
/************************************************************************/
/* 函数名:     ConnectVidInft                                    */  
/* 函数参数:                                                            */
/*             u32 dwDstIntf                                            */
/*                      物理输出接口宏VIDIF_HDMI(0)或者VIDIF_HDMI(1)辅流*/
/*             u32 dwSrcIntf  物理输入接口宏                            */
/*                         VIDIF_DSP_VP(0, 0)  i-mix为非OSD             */
/*	                       VIDIF_OSD_VP(0, 0)  i-mix为OSD               */
/*	                       VIDIF_HDMI(0)  为OPSTV porta                 */
/*	                       VIDIF_HDMI(2)  为OPSTV portb                 */
/*	                       VIDIF_HDMI(1)  为terminal                    */
/*             BOOL32 bUpdateDstStdUsingSrcStd == TRUE 				    */
/*                               是否按源的制式更新目标接口的制式       */
/* 函数功能:	设置视频输入端口参数			            		    */
/************************************************************************/
u16  ConnectVidIntf(u32 dwDstIntf, u32 dwSrcIntf, BOOL32 bUpdateDstStdUsingSrcStd = TRUE);

/************************************************************************/
/* 函数名:     SnapShot                                                 */  
/* 函数参数:                                                            */
/*             u32 dwIntf  物理输出接口宏VIDIF_HDMI(0)或者VIDIF_HDMI(1) */
/*             s8* pFileName    文件的全路径                            */
/* 函数功能:   保存一帧播放图像为jpeg文件								*/
/************************************************************************/
u16  SnapShot(u32 dwIntf, s8* pFileName);

/************************************************************************/
/* 函数名:     SetAudioVolume                                           */  
/* 函数参数:                                                            */
/*             u32 dwIntf  物理输出接口宏                               */
/*                     AUDIF_HDMI(0)、AUDIF_HDMI(1)、AUDIF_JACK_3mm5(0) */
/*             u8 byVolume 范围：               			            */
/* 函数功能:	设置输出声音音量			            			    */
/************************************************************************/
u16 SetAudioVolume(u32 dwIntf, u8 byVolume );

/************************************************************************/
/* 函数名:     GetAudioVolume                                           */  
/* 函数参数:                                                            */
/*             u32 dwIntf  物理输出接口宏                               */
/*                     AUDIF_HDMI(0)、AUDIF_HDMI(1)、AUDIF_JACK_3mm5(0) */
/*             u8 byVolume 范围：               			            */
/* 函数功能:	设置输出声音音量			            			    */
/************************************************************************/
u16 GetAudioVolume(u32 dwIntf, u8 &pbyVolume );

/************************************************************************/
/* 函数名:     SetAudioMute                                             */  
/* 函数参数:                                                            */
/*             u32 dwIntf  物理输出接口宏
/*                     AUDIF_HDMI(0)、AUDIF_HDMI(1)、AUDIF_JACK_3mm5(0) */
/*             BOOL32 bMute 1：静音 0：取消静音               			*/
/* 函数功能:	设置输出声音静音			            			    */
/************************************************************************/
u16 SetAudioMute(u32 dwIntf, BOOL32 bMute);		

/************************************************************************
* 函数名:     SetAudioLimit
* 函数参数:
*             u32 dwIntf  物理输出接口宏
*                     AUDIF_HDMI(0)、AUDIF_HDMI(1)、AUDIF_JACK_3mm5(0)
*             u32 dwUpper  上限值
              u32 dwLower  下限值
* 函数功能:	设置输出给AIC3104音频数据大小的范围
************************************************************************/
u16 SetAudioLimit(u32 dwIntf, u32 dwUpper, u32 dwLower);

/************************************************************************/
/* 函数名:     SelAudMixIntf                                            */  
/* 函数参数:                                                            */
/*             u32 dwIntf1/dwIntf2  音频物理输入接口宏                  */
/*                         AUDIF_HDMI(0)  i-mix音频 hdmi音频            */
/*	                       AUDIF_HDMI(1)  为OPSTV 音频 a                */
/*	                       AUDIF_HDMI(2)  为terminal 音频               */
/*	                       AUDIF_HDMI(3)  为OPSTV 音频 b                */
/*                         AUDIF_HDMI(4)  i-mix i2s音频                 */
/*	                       AUDIF_RCA(0)   为RCA接口的音频               */
/* 函数功能:	选择进入混音器的两路输入音频            			    */
/************************************************************************/
u16 SelAudMixIntf(u32 dwIntf1, u32 dwIntf2);

/************************************************************************/
/* 函数名:     SetAudIntfSampleRate                                     */  
/* 函数参数:                                                            */
/*                      u32 dwIntf  音频物理输入接口宏                  */
/*                         AUDIF_HDMI(0)  i-mix音频 hdmi音频            */
/*	                       AUDIF_HDMI(1)  为OPSTV 音频 a                */
/*	                       AUDIF_HDMI(2)  为terminal 音频               */
/*	                       AUDIF_HDMI(3)  为OPSTV 音频 b                */
/*                         AUDIF_HDMI(4)  i-mix i2s音频                 */
/*	                       AUDIF_RCA(0)   为RCA接口的音频               */
/*                      enSampleRate emSampRate:                        */
/*                                            8K 16K 32K 44.1K 48K      */
/* 函数功能:	选择进入混音器的两路输入音频            			    */
/************************************************************************/
u16 SetAudIntfSampleRate(u32 dwIntf, enSampleRate emSampRate);

/************************************************************************/
/* 函数名:     SetAud0VolumPreMix                                       */  
/* 函数参数:                                                            */
/*                      u32 dwIntf  音频物理输入接口宏                  */
/*                         AUDIF_HDMI(0)  i-mix音频 hdmi音频            */
/*	                       AUDIF_HDMI(1)  为OPSTV 音频 a                */
/*	                       AUDIF_HDMI(2)  为terminal 音频               */
/*	                       AUDIF_HDMI(3)  为OPSTV 音频 b                */
/*                         AUDIF_HDMI(4)  i-mix i2s音频                 */
/*	                       AUDIF_RCA(0)   为RCA接口的音频               */
/*                      u32 dwMixerInputId 混音器两路输入Id分别是0和1   */
/*                      u8 byVolume                                     */
/* 函数功能:	设置混音前的audio音频源的音量            			    */
/************************************************************************/
u16 SetAudVolumPreMix(u32 dwIntf, u32 dwMixerInputId, u8 byVolume);

/************************************************************************/
/* 函数名:     SetAud0VolumPreMix                                       */  
/* 函数参数:                                                            */
/*                      u32 dwIntf  音频物理输入接口宏                  */
/*                         AUDIF_HDMI(0)  i-mix音频 hdmi音频            */
/*	                       AUDIF_HDMI(1)  为OPSTV 音频 a                */
/*	                       AUDIF_HDMI(2)  为terminal 音频               */
/*	                       AUDIF_HDMI(3)  为OPSTV 音频 b                */
/*                         AUDIF_HDMI(4)  i-mix i2s音频                 */
/*	                       AUDIF_RCA(0)   为RCA接口的音频               */
/*                      u32 dwMixerInputId 混音器两路输入Id分别是0和1   */
/*                      u8 byVolume                                     */
/* 函数功能:	获取混音前的audio音频源的音量            			    */
/************************************************************************/
u16 GetAudVolumPreMix(u32 dwIntf, u32 dwMixerInputId, u8 &pbyVolume);

/************************************************************************/
/* 函数名:     GetAudSrcInfo                                            */  
/* 函数参数:                                                            */
/*                      TAudSrcInfo  见结构体说明                       */
/* 函数功能:	获取audio音频源是否有信号                			    */
/************************************************************************/
u16 GetAudSrcInfo(TAudSrcInfo &tAudSrcInfo);

/************************************************************************/
/* 函数名:     ConnectAudInft                                           */  
/* 函数参数:                                                            */
/*             u32 dwDstIntf                                            */
/*                     AUDIF_HDMI(0)、AUDIF_HDMI(1)、AUDIF_JACK_3mm5(0) */
/*                   u32 dwSrcIntf  音频物理输入接口宏                  */
/*                         AUDIF_HDMI(0)  i-mix音频 hdmi音频            */
/*	                       AUDIF_HDMI(1)  为OPSTV 音频 a                */
/*	                       AUDIF_HDMI(2)  为terminal 音频               */
/*	                       AUDIF_HDMI(3)  为OPSTV 音频 b                */
/*                         AUDIF_HDMI(4)  i-mix i2s音频                 */
/*	                       AUDIF_RCA(0)   为RCA接口的音频               */
/* 函数功能:	连接音频输入输出接口			            		    */
/************************************************************************/
u16 ConnectAudInft(u32 dwDstIntf, u32 dwSrcIntf);

/************************************************************************/
/* 函数名:     SetOpsStatus                                             */  
/* 函数参数:                                                            */
/*             BOOL32 bOpen                                             */
/*                    TRUE:开 FALSE：关                                 */
/* 函数功能:   设置Ops开关          			            		    */
/************************************************************************/
u16 SetOpsStatus(BOOL32 bOpen);

/************************************************************************/
/* 函数名:     SetVidFreezePrm                                           */  
/* 函数参数:                                                            */
/*             u32 dwSrcIntf  物理输入接口宏                            */
/*                         VIDIF_DSP_VP(0, 0)  i-mix为非OSD             */
/*	                       VIDIF_OSD_VP(0, 0)  i-mix为OSD               */
/*	                       VIDIF_HDMI(0)  为OPSTV porta                 */
/*	                       VIDIF_HDMI(2)  为OPSTV portb                 */
/*	                       VIDIF_HDMI(1)  为terminal                    */
/*			 dwFreezeMode  0:解冻所有输入源						        */
/*						   1:冻结imix,  解冻OPUS TERMINAL			 	        */
/*						   2:解冻OPS,  冻结IMIX TERMINAL                                 */
/*						   3:冻结imix,oPS,解冻TERMINAL					*/
/*						   4:冻结TERMINAL,解冻imix,oPS					*/
/*						   5:冻结TERMINAL,imix,解冻oPS					*/
/*						   6:冻结TERMINAL,OPS 解冻imiX					*/
/*						   7:冻结所有输入源				             */
/*                         0x10:冻结IMIX读                               */
/*                         0x80:冻结scaler读                             */
/*                         0x90:冻结scaler读和IMIX读                     */
/* 函数功能: 设置视频冻结                 		               		    */
/************************************************************************/
u16 SetVidFreezePrm(u32 dwSrcIntf, u32 dwFreezeMode);

/************************************************************************/
/* 函数名:		SetVidPlyPortStd										 */  
/* 函数参数:															 */
/*				 u32 dwintf	  播放口 	VIDIF_HDMI(0)\ VIDIF_HDMI(1) 	 */
/*				 u32 dwOutType  播放制式， 例如VID_OUTTYPE_720P50	     */
/* 函数功能:	设置接口输出制式									     */
/************************************************************************/
u16 SetVidPlyPortStd(u32 dwintf, u32 dwOutType = VID_OUTTYPE_ORIGIN);

/************************************************************************/
/* 函数名:		StartFpgaScale(BOOL32 bStart)        					 */  
/* 函数参数:															 */
/*				 BOOL32 bStart	  是否开启缩放      					 */
/* 函数功能:	设置FPGA缩放，目前只针对IMIX							 */
/************************************************************************/
u16 StartFpgaScale(BOOL32 bStart);

/************************************************************************/
/* 函数名:		SetAmplifierStatus(BOOL32 bMute)        					 */  
/* 函数参数:															 */
/*				 BOOL32 bMute	  是否功放静音        					 */
/* 函数功能:	设置功放是否静音通过GPIO接口控制    	 */
/************************************************************************/
u16 SetAmplifierStatus(BOOL32 bMute);

/************************************************************************/
/* 函数名:		SetFpgaVidOverlay(BOOL32 bMute)        					  */  
/* 函数参数:															  */
/*				 u32 dwintf	  opstv/termina        					                        */
/*	                                              VIDIF_HDMI(0)  为OPSTV porta                                  */
/*	                                              VIDIF_HDMI(2)  为OPSTV portb                                  */
/*	                                              VIDIF_HDMI(1)  为terminal                                         */
/*                                                 TVidOverleyScreen tVidLittleProhibitScreen       */
/* 函数功能:	设置功放是否静音通过GPIO接口控制    	  */
/************************************************************************/
u16 SetFpgaVidOverlay(u32 dwintf, TVidOverleyScreen tVidLittleProhibitScreen);

/************************************************************************/
/* 函数名:		SetFpgaVidOverlayMode(BOOL32 bMute)        					             */  
/* 函数参数:															             */
/*				 u32 dwOutintf	  输出接口 VIDIF_HDMI(0)   / VIDIF_HDMI(1)  	      */
/*                          u32 dwMode   0: 3选1模式                                                                         */
/*     						   1:	2画面抠图模式						             */
/*     						   2:	2画面叠加模式						             */
/*     						   3:	3画面叠加模式						             */
/* 函数功能:	设置画面叠加  模式                                                           	      */
/************************************************************************/
u16 SetFpgaVidOverlayMode(u32 dwOutintf, u32 dwMode);

#endif

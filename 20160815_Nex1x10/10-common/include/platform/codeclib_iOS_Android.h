/* CodecLib.h - Codec API Header */ 

/* Copyright(C) 2001-2002 KDC, All rights reserved. 
说明:CODEC上层API封装函数
作者:胡昌威 魏治兵
修改人：李婧
*/

#ifndef __CODECLIB_H_
#define __CODECLIB_H_

#include "kdvdef.h"
#ifndef _KDVMEDIANET_0603_H_
#include "kdvmedianet.h"
#endif

/*=======================================常量、宏与结构的定义=================================*/

//模块版本信息和编译时间 及 依赖的库的版本和编译时间
API void kdvencoderver();
API void kdvdecoderver();

//模块帮助信息 及 依赖的库的帮助信息
API void kdvencoderhelp();
API void kdvdecoderhelp();

/*声音模式 mp3*/
#define	 AUDIO_MODE_WORST        (u8)0/*最差*/
#define	 AUDIO_MODE_BAD          (u8)1/*差  */
#define	 AUDIO_MODE_NORMAL       (u8)2/*一般*/
#define	 AUDIO_MODE_FINE         (u8)3/*好  */
#define	 AUDIO_MODE_BEST         (u8)4/*最好*/

//G.711
#define  AUDIO_MODE_PCMA         (u8)5//a law
#define  AUDIO_MODE_PCMU         (u8)6//u law 
//G.723
#define AUDIO_MODE_G723_6        (u8)7 
#define AUDIO_MODE_G723_5        (u8)8
//G.728
#define AUDIO_MODE_G728		 (u8)9 
//G.722
#define AUDIO_MODE_G722		 (u8)10 
//G.729
#define AUDIO_MODE_G729		 (u8)11 
//G.7221 24k
#define AUDIO_MODE_G7221_24		 (u8)12 
//adpcm
#define AUDIO_MODE_ADPCM		 (u8)13 

#define AUDIO_MODE_AACLC_32      (u8)14

#define AUDIO_MODE_AACLD_32      (u8)15

#define AUDIO_MODE_AACLC_32_SINGLE (u8)16

//G.7221 32K
#define AUDIO_MODE_G7221_32		(u8)17
//G.7221 48k
#define AUDIO_MODE_G7221_48		(u8)18

//iBLC
#define AUDIO_MODE_IBLC         (u8)19
//iSac
#define AUDIO_MODE_ISAC_16         (u8)20
#define AUDIO_MODE_ISAC_32         (u8)21
//OPUS
#define AUDIO_MODE_OPUS         (u8)22

#define  CTRL_AUDIO_ONLY          (u8)0x01 //音频采集
#define  CTRL_VIDEO_ONLY          (u8)0x02 //视频采集
#define  CTRL_AV_BOTH			  (u8)0x03 //（音频＋视频）

#define  AUDIO_MODE_ONLYDEC      (u8)0x01
#define  AUDIO_MODE_ONLYRCV      (u8)0x02
#define  AUDIO_MODE_PLAY         (u8)0x00                

#define  MAX_DECODER_NUM		 (u8)2   //最大解码器数目

#define  SOFT_DEC_ONLY           (u8)0x01
#define  HARD_DEC_ONLY           (u8)0x02
#define  SOFTHARD_DEC_BOTH       (u8)0x03 

/*========================================类的声明与定义======================================*/

/*视频丢包处理策略*/
enum VID_DROP_LEVEL 
{ 
    VID_DROP_PREFERRED_QUALITY = 0,    //质量优先，为等I帧策略
    VID_DROP_PREFERRED_FAST_SPEED = 1,    //速度优先快档，自恢复策略中丢包后只解不播的帧数为1秒钟
    VID_DROP_PREFERRED_MID_SPEED = 2,    //速度优先中档，自恢复策略中丢包后只解不播的帧数为2秒钟
    VID_DROP_PREFERRED_SLOW_SPEED = 3    //速度优先慢档，自恢复策略中丢包后只解不播的帧数为4秒钟
};

/*编码能力级别*/
#define VID_ENC_PROFILE_BASELINE  0   //基本等级，ENC_QUALITY_LEVEL_2
#define VID_ENC_PROFILE_MAINLINE  1   //主要等级，ENC_QUALITY_LEVEL_3
#define VID_ENC_PROFILE_HIGHLINE  2   //高阶等级，ENC_QUALITY_LEVEL_4

/*==================================错误码=======================*/
#define CODEC_NO_ERROR              (u16)0//无错
#define CODEC_ERROR_BASE            (u16)10000//
#define ERROR_CODEC_UNKNOWN	        (u16)10000//不知名的编解码器错误 
#define ERROR_CODEC_PARAM           (u16)(CODEC_ERROR_BASE + 1)//参数错误;  
#define ERROR_DEC_DRAW_HDC	        (u16)(CODEC_ERROR_BASE + 2)//解码器画图窗口DC错误
#define ERROR_DEC_DRAW_DIBOPEN      (u16)(CODEC_ERROR_BASE + 3)//解码器画图对象打开错误
#define ERROR_DEC_DRAW_DIBBEGIN     (u16)(CODEC_ERROR_BASE + 4)//解码器画图格式错误
#define ERROR_DEC_DRAW_CLEARWINDOW  (u16)(CODEC_ERROR_BASE + 5)//解码器清屏错误
#define ERROR_DEC_ICOPEN            (u16)(CODEC_ERROR_BASE + 6)//解码器打开解码驱动错误
#define ERROR_DEC_DECOMPRESSBEGIN   (u16)(CODEC_ERROR_BASE + 7)//解码器设置解码驱动格式错误
#define ERROR_DEC_SETTIMER          (u16)(CODEC_ERROR_BASE + 8)//解码器设置解码定时器错误
#define ERROR_DEC_NO_VIDEO          (u16)(CODEC_ERROR_BASE + 9)//解码器没有创建视频
#define ERROR_DEC_SOCKET_CALLBACK   (u16)(CODEC_ERROR_BASE + 10)//解码器设置网络事件回调错误
#define ERROR_DEC_SOCKET_CREATE     (u16)(CODEC_ERROR_BASE + 11)//解码器创建网络套接字错误
#define ERROR_DEC_NO_AUDIO          (u16)(CODEC_ERROR_BASE + 12)//解码器没有创建音频 
#define ERROR_DEC_WAVEOPEN          (u16)(CODEC_ERROR_BASE + 13)//解码器不能打开声卡*
#define ERROR_DEC_MIXEROPEN         (u16)(CODEC_ERROR_BASE + 14)//解码器不能打开声卡音量控制
#define ERROR_DEC_WAVEPREHEADER     (u16)(CODEC_ERROR_BASE + 15)//解码器不能设置音频播放头
#define ERROR_DEC_WAVEWRITE         (u16)(CODEC_ERROR_BASE + 16)//解码器不能向声卡写音频数据
#define ERROR_DEC_WAVE_ENCOPEN      (u16)(CODEC_ERROR_BASE + 17)//解码器不能打开音频解码器*
#define ERROR_DEC_WAVE_ENCPREHEADER (u16)(CODEC_ERROR_BASE + 18)//解码器不能设置音频解码头
#define ERROR_DEC_WAVE_ENCCONVERT   (u16)(CODEC_ERROR_BASE + 19)//解码器音频解码错误
#define ERROR_DEC_WAVESTART         (u16)(CODEC_ERROR_BASE + 20)//解码器开始音频播放错误
#define ERROR_DEC_WAVESTOP          (u16)(CODEC_ERROR_BASE + 21)//解码器停止音频播放错误
#define ERROR_DEC_MIXER_SETVOLUME   (u16)(CODEC_ERROR_BASE + 22)//解码器设置音量出错
#define ERROR_DEC_MIXER_GETVOLUME   (u16)(CODEC_ERROR_BASE + 23)//解码器获取音量出错
#define ERROR_DEC_MIXERMUTE         (u16)(CODEC_ERROR_BASE + 24)//解码器设置静音出错
#define ERROR_DEC_AUDIOOUT_EXIT     (u16)(CODEC_ERROR_BASE + 25)//解码器音频线程退出出错
#define ERROR_DEC_HARDCREATE        (u16)(CODEC_ERROR_BASE + 26)//解码器创建硬件解码器失败
#define ERROR_DEC_CREATE            (u16)(CODEC_ERROR_BASE + 27)//解码器创建出错 
#define ERROR_DEC_NEW               (u16)(CODEC_ERROR_BASE + 28)//对象生成出错
#define ERROR_DEC_SETAUDIO_ADDR     (u16)(CODEC_ERROR_BASE + 29)//解码器设置音频地址错误  
#define ERROR_DEC_AUDIO_LEN         (u16)(CODEC_ERROR_BASE + 30)//音频编解码的数据长度不正确
#define ERROR_DEC_NO_MASK           (u16)(CODEC_ERROR_BASE + 31)//既不是软件解码也不是硬件解码
#define ERROR_SOCKOBJ_NULL          (u16)(CODEC_ERROR_BASE + 32)//网络接收对象不存在
#define ERROR_DEC_NET_INVALIDPARAM  (u16)(CODEC_ERROR_BASE + 33)//无效的网络接收参数 
#define EROOR_DEC_NO_IMPLEMENT      (u16)(CODEC_ERROR_BASE + 34)//此功能还不支持 
#define ERROR_DEC_SETSTATE          (u16)(CODEC_ERROR_BASE + 35)//解码器设置解码驱动状态错误
#define ERROR_NO_AUDIO_DEV          (u16)(CODEC_ERROR_BASE + 36)//没有指定音频设备

#define ERROR_NO_VIDIO_RCV (u16)(CODEC_ERROR_BASE + 60) //没有视频接收对象
#define ERROR_NO_VIDIO_TRANS (u16)(CODEC_ERROR_BASE + 61) //没有视频转发对象
#define ERROR_NO_VIDIO_DEC (u16)(CODEC_ERROR_BASE + 62) //没有视频解码对象
#define ERROR_NO_VIDIO_OUT (u16)(CODEC_ERROR_BASE + 63) //没有视频输出对象
#define ERROR_NO_VIDIO_DCPLY (u16)(CODEC_ERROR_BASE + 64) //没有视频显卡解码对象

#define ERROR_NO_AUDIO_RCV (u16)(CODEC_ERROR_BASE + 70) //没有音频接收对象
#define ERROR_NO_AUDIO_TRANS (u16)(CODEC_ERROR_BASE + 71)//没有音频转发对象
#define ERROR_NO_AUDIO_DEC (u16)(CODEC_ERROR_BASE + 72) //没有音频解码对象
#define ERROR_NO_AUDIO_OUT (u16)(CODEC_ERROR_BASE + 73) //没有音频输出对象
#define ERROR_NO_AUDIO_DSPLY (u16)(CODEC_ERROR_BASE + 74) //没有音频输出设备控制对象

#define ERROR_ENC_CAPWIN            (u16)(CODEC_ERROR_BASE + 100)//编码器创建捕获窗口出错
#define ERROR_ENC_CAPDRIVER         (u16)(CODEC_ERROR_BASE + 101)//编码器没有发现捕获卡
#define ERROR_ENC_DIBOPEN           (u16)(CODEC_ERROR_BASE + 102)//编码器画图对象打开错误
#define ERROR_ENC_DRAWHDC           (u16)(CODEC_ERROR_BASE + 103)//编码器画图窗口打不开
#define ERROR_ENC_ICOPEN            (u16)(CODEC_ERROR_BASE + 104)//编码器编码对象打开出错
#define ERROR_ENC_DRAWPOS           (u16)(CODEC_ERROR_BASE + 105)//编码器得到画图位置出错
#define ERROR_ENC_DIBBEGIN          (u16)(CODEC_ERROR_BASE + 106)//编码器设置画图格式出错
#define ERROR_ENC_GET_VIDEOBMP      (u16)(CODEC_ERROR_BASE + 107)//编码器得到图像格式出错
#define ERROR_ENC_SET_VIDEOBMP      (u16)(CODEC_ERROR_BASE + 108)//编码器设置图像格式出错
#define ERROR_ENC_GET_CAPSET        (u16)(CODEC_ERROR_BASE + 109)//编码器得到捕获设置出错
#define ERROR_ENC_SET_CAPSET        (u16)(CODEC_ERROR_BASE + 110)//编码器设置捕获设置出错
#define ERROR_ENC_SET_AUDIOFORMATE  (u16)(CODEC_ERROR_BASE + 111)//编码器设置音频捕获格式出错
#define ERROR_ENC_STREAMOPEN        (u16)(CODEC_ERROR_BASE + 112)//编码器打开音频编码对象出错
#define ERROR_ENC_PREHEADER         (u16)(CODEC_ERROR_BASE + 113)//编码器准备音频编码头出错
#define ERROR_ENC_MIXEROPEN         (u16)(CODEC_ERROR_BASE + 114)//编码器创建控制音量对象出错
#define ERROR_ENC_MIXER_SETVOLUME   (u16)(CODEC_ERROR_BASE + 115)//编码器设置音量出错
#define ERROR_ENC_MIXER_GETVOLUME   (u16)(CODEC_ERROR_BASE + 116)//编码器得到音量出错
#define ERROR_ENC_ALREADY           (u16)(CODEC_ERROR_BASE + 117)//编码器状态已经存在
#define ERROR_ENC_STOPCAP           (u16)(CODEC_ERROR_BASE + 118)//编码器无法停止捕获
#define ERROR_ENC_SETSTATE          (u16)(CODEC_ERROR_BASE + 119)//编码器设置编码参数出错
#define ERROR_ENC_ENCBEGIN          (u16)(CODEC_ERROR_BASE + 120)//编码器设置编码帧格式
#define ERROR_ENC_SETTIMER          (u16)(CODEC_ERROR_BASE + 121)//编码器设置定时器出错
#define ERROR_ENC_STOPVIDEOENC      (u16)(CODEC_ERROR_BASE + 122)//编码起停止视频编码出错
#define ERROR_ENC_NO_SETPARAM       (u16)(CODEC_ERROR_BASE + 123)//编码器没有设置参数
#define ERROR_ENC_STOPAUDIOENC      (u16)(CODEC_ERROR_BASE + 124)//编码器音频编码出错
#define ERROR_ENC_CREATESOCK        (u16)(CODEC_ERROR_BASE + 125)//编码器设置当地地址出错
#define ERROR_ENC_STOPSENDVIDEO     (u16)(CODEC_ERROR_BASE + 126)//编码器停止发送视频出错
#define ERROR_ENC_STOPSENDAUDIO     (u16)(CODEC_ERROR_BASE + 127)//编码器停止发送音频出错
#define ERROR_ENC_AUDIOENC          (u16)(CODEC_ERROR_BASE + 128)//编码器音频转换错误
#define ERROR_ENC_NO_CREATE         (u16)(CODEC_ERROR_BASE + 129)//编码器创建不成功  
#define ERROR_ENC_SOCK_INIT         (u16)(CODEC_ERROR_BASE + 130)//编码器网络套接字不是2.2版
#define ERROR_ENC_STARTCAP          (u16)(CODEC_ERROR_BASE + 131)//编码器无法开始捕获
#define ERROR_ENC_CAP_WIDTH         (u16)(CODEC_ERROR_BASE + 132)//编码器捕获帧太宽
#define ERROR_DRAW_FORMATE          (u16)(CODEC_ERROR_BASE + 133)//画图格式不支持
#define ERROR_HARDENC_FORMATE       (u16)(CODEC_ERROR_BASE + 134)//硬件不支持的画图格式
#define ERROR_ENC_CAP_FORMATE       (u16)(CODEC_ERROR_BASE + 135)//采集格式和编码格式不匹配
#define ERROR_ENC_NEW               (u16)(CODEC_ERROR_BASE + 136)//对象生成出错
#define ERROR_ENC_INVALID_PARAM     (u16)(CODEC_ERROR_BASE + 137)//无效的参数
#define ERROR_ENC_CREATE_EVENT      (u16)(CODEC_ERROR_BASE + 138)//不能创建事件 
#define EROOR_ENC_NO_IMPLEMENT      (u16)(CODEC_ERROR_BASE + 139)//此功能还不支持 
#define ERROR_ENC_GETSTATE          (u16)(CODEC_ERROR_BASE + 140)//编码器得到编码参数出错
#define ERROR_DECENC_CREATE_THREAD  (u16)(CODEC_ERROR_BASE + 141)//不能创建线程

#define ERROR_ENC_CAP_DESKTOP_FORMAT    (u16)(CODEC_ERROR_BASE + 142)//要求的编码器桌面捕获格式还不支持
#define ERROR_ENC_CREATE_DESKTOP_MEMDC  (u16)(CODEC_ERROR_BASE + 143)//创建桌面内存dc失败
#define ERROR_ENC_CAP_DESKTOP_WIDTH     (u16)(CODEC_ERROR_BASE + 144)//编码器捕获桌面分辨率高于当前桌面实际分辨率
#define ERROR_ENC_CAP_DESKTOP_BITCOUNT  (u16)(CODEC_ERROR_BASE + 145)//编码器捕获桌面位深高于当前桌面实际位深
#define ERROR_ENC_INVILAD_FILE      (u16)(CODEC_ERROR_BASE + 146)//提供的文件无效
#define ERROR_ENC_OPERATE_FILE     (u16)(CODEC_ERROR_BASE + 147)//文件编码器对指定的文件操作失败

#define ERROR_SOCKET_RTP_PORT_OCCUPY    (u16)(CODEC_ERROR_BASE + 148)//设置网络参数时端口被占用
#define ERROR_SOCKET_RTCP_PORT_OCCUPY   (u16)(CODEC_ERROR_BASE + 149)//设置网络参数时端口被占用
#define ERROR_ENC_ENABLECRYPT           (u16)(CODEC_ERROR_BASE + 150)
#define ERROR_ENC_CRYPTCFGINIT          (u16)(CODEC_ERROR_BASE + 151)
#define ERROR_ENC_CRYPTCFGCIPHER        (u16)(CODEC_ERROR_BASE + 152)
#define ERROR_ENC_CRYPTCFGAUTH          (u16)(CODEC_ERROR_BASE + 153)
#define ERROR_ENC_CRYPTCFGMASTKEY       (u16)(CODEC_ERROR_BASE + 154)
#define ERROR_ENC_CRYPTCFGCIPHKEY       (u16)(CODEC_ERROR_BASE + 155)
#define ERROR_ENC_CRYPTCFGAUTHKEY       (u16)(CODEC_ERROR_BASE + 156)
#define ERROR_ENC_CRYPTCFGPKT           (u16)(CODEC_ERROR_BASE + 157)
#define ERROR_ENC_CRYPTCFGAUTHTAG       (u16)(CODEC_ERROR_BASE + 158)
#define ERROR_ENC_ENABLEFEC             (u16)(CODEC_ERROR_BASE + 159)
#define ERROR_DEC_ENABLECRYPT           (u16)(CODEC_ERROR_BASE + 160)
#define ERROR_DEC_CRYPTCFGINIT          (u16)(CODEC_ERROR_BASE + 161)
#define ERROR_DEC_CRYPTCFGCIPHER        (u16)(CODEC_ERROR_BASE + 162)
#define ERROR_DEC_CRYPTCFGAUTH          (u16)(CODEC_ERROR_BASE + 163)
#define ERROR_DEC_CRYPTCFGMASTKEY       (u16)(CODEC_ERROR_BASE + 164)
#define ERROR_DEC_CRYPTCFGCIPHKEY       (u16)(CODEC_ERROR_BASE + 165)
#define ERROR_DEC_CRYPTCFGAUTHKEY       (u16)(CODEC_ERROR_BASE + 166)
#define ERROR_DEC_CRYPTCFGPKT           (u16)(CODEC_ERROR_BASE + 167)
#define ERROR_DEC_CRYPTCFGAUTHTAG       (u16)(CODEC_ERROR_BASE + 168)
#define ERROR_DEC_REQUESTIDRFRAME		(u16)(CODEC_ERROR_BASE + 169)
#define ERROR_ENC_ENABLEFEC             (u16)(CODEC_ERROR_BASE + 170)
#define ERROR_DEC_ENABLEFEC             (u16)(CODEC_ERROR_BASE + 171)


//设备ID
enum DeviceID {
  Code_None = 0,
  Codec_iPhone = 1,
  Codec_iPad = 2,
  Codec_Android = 3,
  Codec_Error,
};

//视频采集类型
enum VidEncodeType
{
	vid_EncCamera = 0,
	vid_EncShare,
	InValid,
};

/*编码器参数*/
typedef struct Encoder
{  
	  DeviceID   m_dwDeviceid;    //当时使用的设备ID
	  VidEncodeType m_dwVidEncType;  //视频编码类型，音频编码时这个参数不使用
	  u32   m_dwRservered;      //保留字段	
}TEncoder;

/*视频编码参数*/
typedef struct VideoEncParam
{
	u8      m_byEncType;   /*图像编码类型*/
    u8      m_byRcMode;    /*图像压缩码率控制参数*/
    u16     m_byMaxKeyFrameInterval;/*I帧间最大P帧数目*/
    u8      m_byMaxQuant;  /*最大量化参数(1-31)*/
    u8      m_byMinQuant;  /*最小量化参数(1-31)*/
    u8      m_byReserved1; /*保留*/
    u8      m_byReserved2; /*保留*/
    u8      m_byReserved3; /*保留*/
    u16     m_wBitRate;    /*编码比特率(Kbps)*/
    u16     m_wReserved4;  /*保留*/		
	u32     m_dwSndNetBand;/*网络发送带宽(单位:Kbps,1K=1024)*/   
    u32     m_dwReserved5; /*保留*/
	u16     m_EncVideoWidth;//编码设置图像宽
	u16     m_EncVideoHeight;//编码设置图像高
	u8      m_byQcMode; /*图像质量码率控制参数,质量优先或者速度优先*/
    u8      m_byQI;
    u8      m_byQP;
    u32     m_dwReversed;
}TVideoEncParam;

/*编码器状态*/
typedef struct KdvEncStatus
{
	BOOL32 			m_bVideoSignal;			/*是否有视频信号*/
	BOOL32	        m_bVideoCapStart; /*是否开始视频捕获*/
	BOOL32			m_bAudioCapStart; /*是否开始音频捕获*/
	BOOL32			m_bVideoEncStart; /*是否开始视频编码*/
	BOOL32			m_bAudioEncStart; /*是否开始音频编码*/
	BOOL32			m_bNetSndVideoStart;/*是否开始视频发送*/
	BOOL32			m_bNetSndAudioStart;/*是否开始音频发送*/
	u32             m_dwVideoBufLen;  /*视频缓冲长度*/
	u32             m_dwAudioBufLen;  /*音频缓冲长度*/ 
	TVideoEncParam	m_tVideoEncParam; /*视频编码参数*/
	u8              m_byAudioEncParam;/*音频编码模式*/
	u8			    m_byAudEncMediaType; /*音频编码媒体类型*/	
	TMnetNetParam       m_tVideoSendAddr; /*视频发送地址*/
	TMnetNetParam       m_tAudioSendAddr; /*音频发送地址*/
	u32             m_dwSetEncParam; //设置硬件编码参数次数
	u32             m_dwVideoSend;   //已发送的视频包数
	u32             m_dwAudioSend;   //已发送的音频包数
	BOOL32			m_bReduceVideoEncRes;/*是否降低编码分辨率*/
	u32             m_dwReversed;
}TKdvEncStatus;

typedef struct MediaSDKEnvirVar
{
    u32 m_dwMediaSDKVer;     //当前MediaSDK版本号
    u32 m_dwMediaSDKInfo;    //当前MediaSDK的信息
    u32 m_dwOSVer;          //操作系统版本号
    u32 m_dwRservered;      //保留字段
}TMediaSDKEnvirVar;

/*编码器统计信息*/
typedef struct KdvEncStatis
{
    u8   m_byVideoFrameRate;/*视频帧率*/
    u32  m_dwVideoBitRate;  /*视频码流速度*/
    u32  m_dwAudioBitRate;  /*语音码流速度*/
    u32  m_dwVideoPackLose; /*视频丢帧数*/
    u32  m_dwVideoPackError;/*视频错帧数*/
    u32  m_dwAudioPackLose; /*语音丢帧数*/
    u32  m_dwAudioPackError;/*语音错帧数*/
	u32  m_wAvrVideoBitRate;   /*1分钟内视频编码平均码率*/
	u32	 m_wAvrAudioBitRate;   /*1分钟内语音编码平均码率*/
	u32  m_dwReversed;
}TKdvEncStatis;

//台标融入码流的相关信息设置
typedef struct tagTranspDColor
{
	u8 RColor;          //R背景
	u8 GColor;          //G背景
	u8 BColor;          //B背景	
	u8 u8Transparency;  //透明度(0表示全透明，255表示不透明，1~254表示部分透明)
}TTranspColor;

typedef struct tagAddLogoParam
{
	float fXPosRate;		//宽度比例，xpos = 底图宽*fXPosRate
	float fYPosRate;		//高度比例，ypos = 底图宽*fYPosRate
	u32   dwLogoBgWidth;	//参考底图的宽
	u32   dwLogoBgHeight;	//参考底图的高
	TTranspColor tBackBGDColor;    
}TAddLogoParam;

typedef struct
{
	s8     aszLogoBmpPath[256];	
	u32    dwLogoPathLen;
	TAddLogoParam tLogoParam;
}TFullLogoParam;
struct TEncoderRef;
struct TEncoderStatus;
class  CKdvEncImp;

class CKdvEncoder/**/
{
public:
    CKdvEncoder();
    virtual ~CKdvEncoder();
public:
 
    //初始化软件编码器
    u16    Create( const TEncoder *ptEncoder, u8 byCapType = CTRL_AV_BOTH );
	
	u16    StartCap( u8 byCapType = CTRL_AV_BOTH );//开始捕获
    u16    StopCap( u8 byCapType =  CTRL_AV_BOTH ); //停止捕获

    u16    SetAudioCapParam( u8 byMode );
    u16    SetVideoEncAddBlackBorder( BOOL32 bEnable );//bEnable, TRUE为加黑边处理方式，FALSE自适应屏幕

    u16    GetEncoderStatus( TKdvEncStatus &tKdvEncStatus );/*获取编码器状态*/ 		
    u16    GetEncoderStatis( TKdvEncStatis &tKdvEncStatis );/*获取编码器的统计信息*/

    u16    StartVideoCap();/*开始采集图像*/
    u16    StopVideoCap(); /*停止采集图像*/

    u16    SetVideoEncParam(const TVideoEncParam *ptVideoEncParam );/*设置视频编码参数*/
    u16    GetVideoEncParam(TVideoEncParam &tVideoEncParam );       /*得到视频编码参数*/
    u16    StartVideoEnc();/*开始压缩图像*/
    u16    StopVideoEnc(); /*停止压缩图像*/
    
    u16    SetFastUpata(BOOL32 bIsNeedProtect = TRUE);     /*请求IDR桢*/
    u16    SendStaticPicture(BOOL32 bSend, s8* pszFileName);  //发送静态图片     	

    u16    StartAudioCap();/*开始语音采集*/
    u16    StopAudioCap(); /*停止语音采集*/

    u16    SetAudioEncParam(u8 byAudioEncParam, 
                            u8 byMediaType,
                            u16 wAudioDuration = 30); /*设置语音压缩参数*/
    u16    GetAudioEncParam(u8 &byAudioEncParam, 
                            u8 *pbyMediaType = NULL,
                            u16 *pwAudioDuration = NULL);/*得到语音压缩参数*/

	u16    StartAudioEnc();/*开始压缩语音*/
    u16    StopAudioEnc(); /*停止压缩语音*/

    u16    SetBackStage(BOOL32 bBackStage);
    u16	   SetAudioMute(BOOL32 bMute); /*设置是否哑音*/	
    u16    GetAudioMute( BOOL32& bMute );     // 是否哑音

	//设置图像的网络重传参数
	u16    SetNetFeedbackVideoParam(BOOL32 bRepeatSnd = FALSE);
	u16    SetNetFeedbackAudioParam(BOOL32 bRepeatSnd = FALSE);
	
	//设置音频参数
	u16    SetAudioSendId(const char* EndPointId, u32 IdLen, u32 StreamId);
	u16    GetAudioSendId(char* EndPointId, u32* IdLen, u32* StreamId);
	u16    AudioSendEnableKeepAlive(BOOL32 enable, const TMnetNetParam *ptKeepAliveParam);
	
	//音频发送带宽限制，dwNetBand与 dwMaxBitRate任一值为零，则发送带宽不限制， ucFrameRate暂未使用，默认值为零
	u16    SetAudioSndBand(u32 dwNetBand, u32 dwMaxBitRate, u8 ucFrameRate = 0);   
	
	//设置视频参数
	u16    SetVideoSendId(const char* EndPointId, u32 IdLen, u32 StreamId);
	u16    GetVideoSendId(char* EndPointId, u32* IdLen, u32* StreamId);
	u16    VideoSendEnableKeepAlive(BOOL32 enable, const TMnetNetParam *ptKeepAliveParam);

	//该功能对音频设置多倍发送
	u16    SetNetAudioResend(s32 nSendSpan);

    u16    SetNetSndVideoParam(const TMnetNetParam *ptNetSndParam);/*设置图像的网络传送参数*/
    u16    SetNetSndAudioParam(const TMnetNetParam *ptNetSndParam);/*设置语音的网络传送参数*/
    u16    StartSendVideo(int  dwSSRC = 0);/*开始发送图像*/	
    u16    StopSendVideo(); /*停止发送图像*/
    u16    StartSendAudio(int  dwSSRC = 0);/*开始发送语音*/	
    u16    StopSendAudio(); /*停止发送语音*/   

    //视频动态载荷的PT值的设定
    u16 SetAudioActivePT(u8 byLocalActivePT, u8 byRemoteActivePT  = MEDIA_TYPE_NULL);
    	
    //音频动态载荷的PT值的设定
    u16 SetVideoActivePT(u8 byLocalActivePT,u8 byRemoteActivePT = MEDIA_TYPE_NULL );
    	
    //设置音频编码加密key字串、加密的载荷PT值 以及 解密模式 Aes or Des
    u16    SetAudEncryptKey( s8 *pszKeyBuf, u16 wKeySize, u8 byEncryptMode );
    	
    //设置视频编码加密key字串、加密的载荷PT值 以及 解密模式 Aes or Des
    u16    SetVidEncryptKey( s8 *pszKeyBuf, u16 wKeySize, u8 byEncryptMode ); 
    
	u16    SetReverseG7221c(BOOL32 bReverse);
	u16    SendAudioPack(u8* lpBuf, s32 nlen);
	
	//使能/关闭动态带宽检测
	u16 ResetBwe(BOOL32 bEnable, u32 dwMaxRate, u32 dwMinRate, u32 dwStartRate);
	//获取动态带宽检测结果,配套ResetBwe使用
	u16 GetBweStatus(u32* pNumber, TBweReceiver* pReceivers, u32* pRevision);
	//获取视频网络传输开销百分比
	u16 GetVidTransportOverhead(u8 *byPercent);

	u16	SetAddLogoIntoEncStream(TFullLogoParam *ptLogoSetting);

    void    GetLastError( u32 &dwErrorId );
        	
	
	//视频是否使用前向纠错
	u16    SetVidFecEnable(BOOL32 bEnableFec);
/*	//设置fec的切包长度
	u16    SetVidFecPackLen(u16 wPackLen);
	//是否帧内fec
	u16    SetVidFecIntraFrame(BOOL32 bIntraFrame);
	//设置fec算法 FEC_MODE_RAID5
	u16    SetVidFecMode(u8 byAlgorithm);
	//设置fec的x包数据包 + y包冗余包
	u16    SetVidFecXY(s32 nDataPackNum, s32 nCrcPackNum);
*/
	//音频是否使用前向纠错
	u16    SetAudFecEnable(BOOL32 bEnableFec);
	//设置fec的切包长度
/*	u16    SetAudFecPackLen(u16 wPackLen);
	//是否帧内fec
	u16    SetAudFecIntraFrame(BOOL32 bIntraFrame);
	//设置fec算法 FEC_MODE_RAID5
	u16    SetAudFecMode(u8 byAlgorithm);
	//设置fec的x包数据包 + y包冗余包
	u16    SetAudFecXY(s32 nDataPackNum, s32 nCrcPackNum);
*/	
	/**************Video*******************/
	//使能加密
	u16     SetVidEnableCrypt( BOOL32 bEnableCrypt, TMnetCryptCfg *ptMnetCryptCfg);
	//初始化加密配置结构体
	u16     SetVidMnetCryptCfgInit(TMnetCryptCfg* ptCfg, BOOL32 bsend);
	//设置加密用的加密算法
	u16     SetVidMnetCryptCfgSetCipherAlgorithm(TMnetCryptCfg* ptCfg, TMnetCryptDataType tDataType, TMnetCryptAlgoType tAlgorithm);
	//设置认证用的加密算法
	u16     SetVidMnetCryptCfgSetAuthAlgorithm(TMnetCryptCfg* ptCfg, TMnetCryptDataType tDataType, TMnetCryptAlgoType tAlgorithm);
	//设置秘钥类型和秘钥,本接口用于srtp
	u16     SetVidMnetCryptCfgSetMasterKey(TMnetCryptCfg* ptCfg, TMnetCryptDataType tDataType, TMnetCryptKeyType tKeyType, u16 wKeySize, 
		u8* byKey, TMnetCrypKeyLen tKeyLenAuch, TMnetCrypKeyLen tKeyLenCipher);
	//设置加密用的某个通道的加密秘钥长度,用于H235加密,目前仅支持rtp aes加密
	u16     SetVidMnetCryptCfgSetCipherKey(TMnetCryptCfg* ptCfg, TMnetCryptDataType tDataType, u16 wKeySize, u8* byKey);
	//设置加密用的某个通道的认证秘钥长度,用于H235,暂不支持认证
	u16     SetVidMnetCryptCfgSetAuthKey(TMnetCryptCfg* ptCfg, TMnetCryptDataType tDataType, u16 wKeySize, u8* byKey);
	//设置通道的pkt类型
	u16     SetVidMnetCryptCfgSetPkt(TMnetCryptCfg* ptCfg, TMnetCryptDataType tDataType, TMnetCryptPktType tPktType);
	//设置加密用的某个通道的认证tag长度,用于srtp
	u16		SetVidMnetCryptCfgSetAuthTag(TMnetCryptCfg* ptCfg, TMnetCryptDataType tDataType, TMnetCryptTagLen tTagLen);

	u16	    SetVidMnetKeyFrameRequestCallback(PKeyFrameRequestCallback pCallback, void *pContext);

	/**************Audio******************/
	//使能加密
	u16     SetAudEnableCrypt( BOOL32 bEnableCrypt, TMnetCryptCfg *ptMnetCryptCfg);
	//初始化加密配置结构体
	u16     SetAudMnetCryptCfgInit(TMnetCryptCfg* ptCfg, BOOL32 bsend);
	//设置加密用的加密算法
	u16     SetAudMnetCryptCfgSetCipherAlgorithm(TMnetCryptCfg* ptCfg, TMnetCryptDataType tDataType, TMnetCryptAlgoType tAlgorithm);
	//设置认证用的加密算法
	u16     SetAudMnetCryptCfgSetAuthAlgorithm(TMnetCryptCfg* ptCfg, TMnetCryptDataType tDataType, TMnetCryptAlgoType tAlgorithm);
	//设置秘钥类型和秘钥,本接口用于srtp
	u16     SetAudMnetCryptCfgSetMasterKey(TMnetCryptCfg* ptCfg, TMnetCryptDataType tDataType, TMnetCryptKeyType tKeyType, u16 wKeySize, 
		u8* byKey, TMnetCrypKeyLen tKeyLenAuch, TMnetCrypKeyLen tKeyLenCipher);
	//设置加密用的某个通道的加密秘钥长度,用于H235加密,目前仅支持rtp aes加密
	u16     SetAudMnetCryptCfgSetCipherKey(TMnetCryptCfg* ptCfg, TMnetCryptDataType tDataType, u16 wKeySize, u8* byKey);
	//设置加密用的某个通道的认证秘钥长度,用于H235,暂不支持认证
	u16     SetAudMnetCryptCfgSetAuthKey(TMnetCryptCfg* ptCfg, TMnetCryptDataType tDataType, u16 wKeySize, u8* byKey);
	//设置通道的pkt类型
	u16     SetAudMnetCryptCfgSetPkt(TMnetCryptCfg* ptCfg, TMnetCryptDataType tDataType, TMnetCryptPktType tPktType);
	//设置加密用的某个通道的认证tag长度,用于srtp
	u16		SetAudMnetCryptCfgSetAuthTag(TMnetCryptCfg* ptCfg, TMnetCryptDataType tDataType, TMnetCryptTagLen tTagLen);

private:
	s64    m_qwLastFastupdataTime;     //最近一次FastUpdata的时间

protected:
    CKdvEncImp     *m_pcKdvInterEnc;
    TEncoderRef     *m_ptRef;
    TEncoderStatus     *m_ptStatus;	
};

class CKdvVidDecCtrl;
class CKdvAudDecCtrl;
struct TDecoderRef;
struct TDecoderStatus;

/*解码器统计信息*/
typedef struct KdvDecStatis
{
	u8	  m_byVideoFrameRate;/*视频解码帧率*/
	u16	  m_wVideoBitRate;   /*视频解码码率*/
	u16	  m_wAudioBitRate;   /*语音解码码率*/
	u32   m_dwVideoRecvFrame;/*收到的视频帧数*/
	u32   m_dwAudioRecvFrame;/*收到的语音帧数*/
	u32   m_dwVideoLoseFrame;/*丢失的视频帧数*/
	u32   m_dwAudioLoseFrame;/*丢失的语音帧数*/
    u16   m_wVideoLoseRatio;//视频丢失率,单位是% 	
	u16   m_wAudioLoseRatio;//音频丢失率,单位是% 	
	u32   m_dwPackError;/*乱帧数*/ 
	u32   m_dwIndexLose;/*序号丢帧*/
	u32   m_dwSizeLose; /*大小丢帧*/
	u32   m_dwFullLose; /*满丢帧*/	
	u32   m_wAvrVideoBitRate;   /*1分钟内视频解码平均码率*/
	u32	  m_wAvrAudioBitRate;   /*1分钟内语音解码平均码率*/
	BOOL32 m_bVidCompellingIFrm;  /*视频强制请求I帧*/								  
	u32   m_dwDecdWidth;	/*码流的宽*/
	u32   m_dwDecdHeight;   /*码流的高*/
	u16   LastVideoBitRate; //上次统计的码率
    u32   GetDecoderStatisnum;//码率不变则该值递增
	u32	  m_dwVidPackLoseNum;//视频丢包数
    u16   m_wVidPhyPackLoseRatio;//重传前的视频丢包率
    u16   m_wVidPackLoseRatio;//重传后的视频丢包率
    u16   m_wAudPhyPackLoseRatio;//重传前的音频丢包率
	u16   m_wAudPackLoseRatio;//重传后的音频丢包率	
}TKdvDecStatis; 

/*解码器状态*/
typedef struct KdvDecStatus
{
	BOOL32	m_bVideoDecStart;/*是否开始视频解码*/
	BOOL32	m_bAudioDecStart;/*是否开始音频解码*/
	BOOL32	m_bRcvVideoStart;/*是否开始视频接收*/
	BOOL32	m_bRcvAudioStart;/*是否开始音频接收*/
	u32	m_dwAudioBufLen; /*音频播放缓冲长度*/
	u32	m_dwVideoBufLen; /*视频播放缓冲长度*/
	TMnetNetParam   m_tAudioRcvAddr;/*音频当地地址*/
	TMnetNetParam   m_tVideoRcvAddr;/*视频当地地址*/
	BOOL32	m_bAudioOutThread;/*是否声音播放线程存活*/
	u32   m_dwAudioDecType;     //音频解码类型
	u32   m_dwVideoDecType;     //视频解码类型
}TKdvDecStatus;

/*视频解码器参数*/
typedef struct VideoDecoder
{    
    DeviceID     m_dwDeviceid;    //当时使用的设备ID
	s32     m_nVideoPlayBufNum;     /*视频回放缓冲个数*/
	s32     m_nVideoStartPlayBufNum;/*视频开始回放缓冲个数*/
	//硬件解码部分
	u8      m_byMask;  //0x01软件解码,0x02硬件解码,0x03两者同时解码
    u32     m_dwReversed;
}TVideoDecoder;

/*音频解码器参数*/
typedef struct AudioDecoder
{
	DeviceID     m_dwDeviceid;    //当时使用的设备ID
	s32     m_nAudioPlayBufNum;/*音频播放缓冲数*/
	s32     m_nAudioStartPlayBufNum;/*音频开始播放缓冲数*/
    u8      m_byAudioMode;
    u32     m_dwRservered;      //保留字段
}TAudioDecoder;

typedef struct tagNetRSParam  //include medianet
{
    u16  m_wFirstTimeSpan;	  //第一个重传检测点
	u16  m_wSecondTimeSpan;  //第二个重传检测点
	u16  m_wThirdTimeSpan;   //第三个重传检测点
	u16  m_wRejectTimeSpan;  //过期丢弃的时间跨度
} TNetRSParam;

class CKdvDecoder
{
public:
    CKdvDecoder();
    virtual ~CKdvDecoder();
	
public:

    u16    CreateDecoder(const TVideoDecoder *ptVideoDecoder, const TAudioDecoder *ptAudioDecoder);/*初始化解码器*/	
    u16    GetDecoderStatus(TKdvDecStatus &tKdvDecStatus );/*获取解码器状态*/
    u16    GetDecoderStatis(TKdvDecStatis &tKdvDecStatis );/*获取解码器的统计信息*/	

    u16    StartVideoDec();/*开始图像解码*/
    u16    StopVideoDec(); /*停止图像解码*/
    
    u16    CleanScreen();  //将播放窗口置为黑屏
    
//	u16    StartVideoPlay(); /* 开始图像播放 */  未实现
//	u16    StopVideoPlay(); /* 停止图像播放 */   未实现
	
//	u16    SetAudioDecType(u8 byType,u32 dwAudioMode); //未实现,要切换音频解码格式，需要重新创建解码器
    u16    StartAudioDec();/*开始声音解码*/	
    u16    StopAudioDec(); /*停止声音解码*/	
    
    u16    SetAudioMute(BOOL32 bMute);/*设置静音*/          
    u16    GetAudioMute(BOOL32& bMute); //得到静音状态
    
	u16    SetBackStage(BOOL32 bBackStage);
    
    u16    StartRcvVideo();/*开始网络接收图像*/
    u16    StopRcvVideo(); /*停止网络接收图像*/
    u16    StartRcvAudio();/*开始网络接收声音*/	
    u16    StopRcvAudio(); /*停止网络接收声音*/	
    u16    SetVideoNetRcvParam(const TMnetNetParam *ptLocalNetParam );/*设置图像的网络接收参数*/
    u16    SetAudioNetRcvParam(const TMnetNetParam *ptLocalNetParam );/*设置语音的网络接收参数*/
    
	//设置音频参数
	u16    SetAudioRcvId(const char* EndPointId, u32 IdLen, u32 StreamId);
	u16    GetAudioRcvId(char* EndPointId, u32* IdLen, u32* StreamId);
	u16    AudioRcvEnableKeepAlive(BOOL32 enable, const TMnetNetParam *ptKeepAliveParam);
	
	//设置视频参数
	u16    SetVideoRcvId(const char* EndPointId, u32 IdLen, u32 StreamId);
	u16    GetVideoRcvId(char* EndPointId, u32* IdLen, u32* StreamId);
	u16    VideoRcvEnableKeepAlive(BOOL32 enable, const TMnetNetParam *ptKeepAliveParam);
	u16    SetMaxDelay(u8 ucPolicy, u32 dwSoftlimit, u32 dwHardlimit); //设置最大接收延迟及播放策略，单位ms，分为softlimit，hardlimit两种类型
	
	/*设置图像的网络重传参数*/
	u16    SetNetFeedbackVideoParam(BOOL32 bRepeatSnd = FALSE);
	u16    SetNetFeedbackAudioParam(BOOL32 bRepeatSnd = FALSE);          

	/*解码器发送两路码流，一路发往Map或者win32解码绘制，一路发往网络, 参数NULL,则关闭后一路，并作相应套节子释放*/
    u16    SetVidDecDblSend(const TMnetNetParam *ptNetSndVideoParam, u16 wBitRate = 4<<10);
    u16    SetAudDecDblSend(const TMnetNetParam *ptNetSndAudioParam);   

	//设置 H.263+/H.264 等动态视频载荷的 Playload值
	u16    SetVideoActivePT( u8 byRmtActivePT, u8 byRealPT );
	u16    SetVideoActivePT( const TMapSet *ptMapSet );

	//设置 视频解码key字串 以及 解密模式 Aes or Des
    u16    SetVidDecryptKey(s8 *pszKeyBuf, u16 wKeySize, u8 byDecryptMode); 

    //设置 动态音频载荷的 Playload值
	u16    SetAudioActivePT( u8 byRmtActivePT, u8 byRealPT );
	u16    SetAudioActivePT( const TMapSet *ptMapSet );

	//设置 音频解码key字串 以及 解密模式 Aes or Des
    u16    SetAudDecryptKey(s8 *pszKeyBuf, u16 wKeySize, u8 byDecryptMode); 

	/*设置视频丢包处理策略*/
	u16    SetVidDropPolicy(VID_DROP_LEVEL byDropPolicy);

    //得到Wrapper的版本和编译信息 bysize最好不小于128  [zhuyr][2/23/2005]
    //u16    GetWrapperVer(s8 *pszVerBuffer, u8 bySize);   //未实现

	//设置是否只解关键帧 TRUE为设置，FALSE为取消
	u16    SetOnlyKeyFrame(BOOL32 bKeyFrame);

	u16    SetAudioDecParam(u32 dwSamplePerSecond, u32 dwChannels,u32 dwAudioMode = 255);//音频解码参数设置
	u16    SetReverseG7221c(BOOL32 bReverse );//设置g7221c反转

	//视频是否使用前向纠错
	u16    SetVidFecEnable(BOOL32 bEnableFec);
	//音频是否使用前向纠错
	u16    SetAudFecEnable(BOOL32 bEnableFec);

	/***********Video**************/
	//使能加密
	u16     SetVidEnableCrypt( BOOL32 bEnableCrypt, TMnetCryptCfg *ptMnetCryptCfg);
	//初始化加密配置结构体
	u16     SetVidMnetCryptCfgInit(TMnetCryptCfg* ptCfg, BOOL32 bsend);
	//设置加密用的加密算法
	u16     SetVidMnetCryptCfgSetCipherAlgorithm(TMnetCryptCfg* ptCfg, TMnetCryptDataType tDataType, TMnetCryptAlgoType tAlgorithm);
	//设置认证用的加密算法
	u16     SetVidMnetCryptCfgSetAuthAlgorithm(TMnetCryptCfg* ptCfg, TMnetCryptDataType tDataType, TMnetCryptAlgoType tAlgorithm);
	//设置秘钥类型和秘钥,本接口用于srtp
	u16     SetVidMnetCryptCfgSetMasterKey(TMnetCryptCfg* ptCfg, TMnetCryptDataType tDataType, TMnetCryptKeyType tKeyType, u16 wKeySize, 
		u8* byKey, TMnetCrypKeyLen tKeyLenAuch, TMnetCrypKeyLen tKeyLenCipher);
	//设置加密用的某个通道的加密秘钥长度,用于H235加密,目前仅支持rtp aes加密
	u16     SetVidMnetCryptCfgSetCipherKey(TMnetCryptCfg* ptCfg, TMnetCryptDataType tDataType, u16 wKeySize, u8* byKey);
	//设置加密用的某个通道的认证秘钥长度,用于H235,暂不支持认证
	u16     SetVidMnetCryptCfgSetAuthKey(TMnetCryptCfg* ptCfg, TMnetCryptDataType tDataType, u16 wKeySize, u8* byKey);
	//设置通道的pkt类型
	u16     SetVidMnetCryptCfgSetPkt(TMnetCryptCfg* ptCfg, TMnetCryptDataType tDataType, TMnetCryptPktType tPktType);
	//设置加密用的某个通道的认证tag长度,用于srtp
	u16		SetVidMnetCryptCfgSetAuthTag(TMnetCryptCfg* ptCfg, TMnetCryptDataType tDataType, TMnetCryptTagLen tTagLen);

	u16     SetVidMnetRequestIDRFrame();

	u16     SetAudEnableCrypt(BOOL32 bEnableCrypt, TMnetCryptCfg *ptMnetCryptCfg);
	
	u16     SetAudMnetCryptCfgInit(TMnetCryptCfg* ptCfg, BOOL32 bsend);
	//设置加密用的加密算法
	u16     SetAudMnetCryptCfgSetCipherAlgorithm(TMnetCryptCfg* ptCfg, TMnetCryptDataType tDataType, TMnetCryptAlgoType tAlgorithm);
	//设置认证用的加密算法
	u16     SetAudMnetCryptCfgSetAuthAlgorithm(TMnetCryptCfg* ptCfg, TMnetCryptDataType tDataType, TMnetCryptAlgoType tAlgorithm);
	//设置秘钥类型和秘钥,本接口用于srtp
	u16     SetAudMnetCryptCfgSetMasterKey(TMnetCryptCfg* ptCfg, TMnetCryptDataType tDataType, TMnetCryptKeyType tKeyType, u16 wKeySize, 
		u8* byKey, TMnetCrypKeyLen tKeyLenAuch, TMnetCrypKeyLen tKeyLenCipher);
	//设置加密用的某个通道的加密秘钥长度,用于H235加密,目前仅支持rtp aes加密
	u16     SetAudMnetCryptCfgSetCipherKey(TMnetCryptCfg* ptCfg, TMnetCryptDataType tDataType, u16 wKeySize, u8* byKey);
	//设置加密用的某个通道的认证秘钥长度,用于H235,暂不支持认证
	u16     SetAudMnetCryptCfgSetAuthKey(TMnetCryptCfg* ptCfg, TMnetCryptDataType tDataType, u16 wKeySize, u8* byKey);
	//设置通道的pkt类型
	u16     SetAudMnetCryptCfgSetPkt(TMnetCryptCfg* ptCfg, TMnetCryptDataType tDataType, TMnetCryptPktType tPktType);
	//设置加密用的某个通道的认证tag长度,用于srtp
	u16		SetAudMnetCryptCfgSetAuthTag(TMnetCryptCfg* ptCfg, TMnetCryptDataType tDataType, TMnetCryptTagLen tTagLen);

    void   GetLastError( u32 &dwErrorId );

public:
    CKdvVidDecCtrl       *m_pcKdvVideoDec;//保留
    CKdvAudDecCtrl       *m_pcKdvAudioDec;//保留
    TDecoderRef	       *m_ptRef;   //保留
    TDecoderStatus     *m_ptStatus;//保留
    static TMediaSDKEnvirVar  m_tMediaSDKEnvirVar;//记录MediaSDK版本信息及当前的运行信息     
    u32 m_dwLastRcvFrameNum;
    u32 m_dwLastRcvPacketNum;
    u32 m_dwSpanRcvPacketNum;
    u32 m_dwLastLostPacketNum;
    u32 m_dwVidPackLoseNum;
    u32 m_dwVidPhyPackLoseNum;
    u32 m_dwLastLostPhyPacketNum;
    u32 m_dwAudPackLoseNum;
    u32 m_dwAudPhyPackLoseNum;
    u32 m_dwLastSec;
protected:
    u8		       m_byFlag;	
};

#endif /*__CODECLIB_H*/

















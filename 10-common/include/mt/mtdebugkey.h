#ifndef _MTDEBUGKEY_H_
#define _MTDEBUGKEY_H_

/*
加一个debug key 流程
 1. 在debugekey.h 中加个json格式，并加好默认值和注释， 好让外部人员知道怎么配置
 2. 在mtdskey.h 中加一个cfg_key， 加注释，表明是通用debug，还是只为某个产品所用
 3. 在debugcfg.h和debug.cpp中加实现类似于下面： 
    static void Default_TRtpSamePort( mt::TBOOL32 &tCommonDebug);
	static void Read_TRtpSamePort();
4. 在debucfg.cpp中的 ReadDebugCfg()接口中加read接口， 如果这个key 只为某个产品服务， 要区分宏
*/


/*
{
	"TRtpSamePort":       
	{
	   "comment": "收发端口是否复用,通用debug",
	   "bSame": false
	},
	"TAudioRemoveG719":   
	{
	  "comment": "是否音频去掉g719能力,通用debug",
	  "bRemove": false
	},
	"TAdaptiveVideo": 
	{
	   "comment": "是否视频载荷自适应,仅windows产品,x500是UI配置",
	   "bAdapt": false
	},
	"mtSecVidDecDynamicPayload":
	{  
	  "comment": "配置强解payload映射表,通用debug",
      "mtKeyRmtActivePT": 0,
	  "mtKeyRealPT": 0
	},
	"TForceRtpExStrip":      
	{
	   "comment": "通用debug, 强制去掉rtp包非标扩展头， 用在平台级联一个外厂商的平台，终端发包，科达平台纯转发到外平台， 需要去掉头",
	   "bEnable": false
	},
	"TEnableDsp6678Detect":      
	{
	   "comment": "终端是否启动265子卡，仅硬终端",
	   "bEnable": true
	},
	"TAudioRemoveLCLD":   
	{
	  "comment": "是否音频去掉lcld能力,通用debug",
	  "bRemove": false
	},
	"TEnableVidBitRateCtrl":  
	{
	"comment": "是否允许修改视频编码码率,通用debug",
	"bEnable": true
	},
	"TVideoSliceCount":
	{
	"comment": "视频包分包数,通用debug",
	"wSliceCount": 0
	},
	"TG711AudioDuration":  
	{
	"comment": "通用debug, 默认编码支持30ms",
	"wDuration": 30
	},
	"TAudioRemoveOPUS":   
	{
	  "comment": "是否音频去掉OPUS能力,通用debug",
	  "bRemove": false
	},
	"TEnableBfcpTwice":  
	{
	"comment": "是否两次bfcp交互，默认是false, 只用在主叫 和 被叫invite不带sdp的情况",
	"bEnable": false 
	},
	"TEnalbeRemoveMulAudFormats":
	{
	  "comment": "用于对通,711a=0, 711u=1,722=2,7231=3,728=4,729=5,mp3=6,721=7,7221c=8,719=9,lc=10,ld=11,opus=12",
	  "bEnable": false,
	  "emAuds":[8,5]
	},
	"mtSecImageSequenceNumberType":  
	{
	   "comment": "视频编码参数，图像序号类型,仅硬终端",
	   "mtKeyImageSequenceNumberType":0
	},
	"TSetRoundTripType":   
	{
	  "comment": "用于设置保活方式 0是设置启用协议RoundTrip,1不设置协议RoundTrip,启用业务通过有无码流保活,2不设置协议RoundTrip,通用debug",
	  "dwRoundTripType": 0
	},
	"TEnableKedaAacSampFreq32K":
	{
	   "comment": "是否科达终端aac采样率32K",
	   "bEnable": true
	},
	"TRegTimeout":
	{
	"comment": "通用debug， 注册超时时间默认15,单位为s,范围为[5-20]",
	"wTimeOut": 15
	},
	"TEnableAudioEncParam":
	{
	  "bEnable":true,
	  "emAudParamList":[
	  {"emAud":1,
	  "dwRate":1,
	  "wHeadFlag":1,
	  "wDuration":1
	  }
	  ]
	},
	"TAutoRas":
	{
	   "comment": "是否自动ras",
	   "bEnable":false
	},
	"TSipCallPort":
	{ 
	   "comment": "初始化sip监听端口",
	   "callport":5060,
	   "tlsport":5061
	},
	"mtAudDecDynamicPayload":
	{  
	  "comment": "配置强解音频payload映射表,通用debug",
      "mtKeyRmtActivePT": 0,
	  "mtKeyRealPT": 0
	},
	"TIsIgnoreSetBitrateZero":
	{
	"comment": "通用debug, 是否忽略码率为0的设置,暂时只处理音频",
	"bIgnore": true
	},
	"T323AdditionalConfig":
	{
	"comment": "通用debug, 323addtional配置, 注册md5类型和460呼叫类型， 有些外厂商不一样",
	"emRrqAuthAlgType": 0,
	"emFacilityReason": 5
	},
	"TKeyFrameInterval":
	{
	"comment": "通用debug,视频发送关键帧最短间隔时间，单位ms",
	"dwInterval": 0
	}
}
*/


#endif
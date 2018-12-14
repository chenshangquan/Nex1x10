#ifndef _NVDEBUGKEY_H_
#define _NVDEBUGKEY_H_

/*
加一个debug key 流程
 1. 在debugekey.h 中加个json格式，并加好默认值和注释， 好让外部人员知道怎么配置
 2. 在nvdskey.h 中加一个cfg_key， 加注释，表明是通用debug，还是只为某个产品所用
 3. 在debugcfg.h和debug.cpp中加实现类似于下面： 
    static void Default_TRtpSamePort( nv::TBOOL32 &tCommonDebug);
	static void Read_TRtpSamePort();
4. 在debucfg.cpp中的 ReadDebugCfg()接口中加read接口， 如果这个key 只为某个产品服务， 要区分宏
*/


/*
{
	"TRtpSamePort":        ///收发端口是否复用,通用debug
	{
	   "bSame": false
	},
	"TAudioRemoveG719":   //是否音频去掉g719能力,通用debug
	{
	  "bRemove": false
	},
	"TAdaptiveVideo":     //是否视频载荷自适应,仅windows产品
	{
	   "bAdapt": false
	},
	"nvSecVidDecDynamicPayload": //配置强解payload映射表,通用debug
	{
      "nvKeyRnvActivePT": 107,
	  "nvKeyRealPT": 106
	},
	"nvSecImageSequenceNumberType":   ///视频编码参数，图像序号类型,仅硬终端
	{
	"nvKeyImageSequenceNumberType":1
	},
	"TForceRtpExStrip":               //通用debug, 强制去掉rtp包非标扩展头， 用在平台级联一个外厂商的平台，终端发包，科达平台纯转发到外平台， 需要去掉头
	{
	"bEnable": false
    },
    "TEnableDsp6678Detect":               //终端是否启动265子卡，仅硬终端
    {
    "bEnable": true
    },
	"TAudioRemoveLCLD":   //是否音频去掉lcld能力,通用debug
	{
	"bRemove": false
	},
	"TAudioPrecedence":   //是否音频开启多倍发送,仅wins
	{
	"bEnable": true
	},
	"TForceSet323Stack":   //是否强制设置323协议栈为非标/标准,通用debug
	{
	"bEnable": false
	"bStand" : true
	}
}
*/


#endif
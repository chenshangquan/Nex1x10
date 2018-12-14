//由于EVSEG_NVOSPMSG_INNER_BGN是可以给所有模块使用，为了防止冲突凡是使用EVSEG_NVOSPMSG_INNER_BGN的头文件都使用_HD_INNER_OSPMSG_，确保模块之间不冲突
#ifndef _HD_NVMFGTEST_OSPMSG_
#define _HD_NVMFGTEST_OSPMSG_

#include "nvospmsgid.h"


enum EmNvMfgTestCommonMsgSegs
{
    //工具与mfgtest之间交互消息
    EVSEG_NVMFGTEST_COMMON_EVENT_BGN = EVSEG_NVOSPMSG_INNER_BGN,

    /*<<查询EEPROM信息(产品信息)>>
    *参    数 : TBrdInfo   板子信息
	*消息流向 : mt->工具
	* see EV_NVMFGTEST_PROD_INFO_RSP
	*/
    EV_NVMFGTEST_PROD_INFO_REQ,


    /*<<返回EEPROM信息(产品信息)>>
    *参    数 : TPrdInfo   产品信息
	*消息流向 : 工具->mt
	* see EV_NVMFGTEST_PROD_INFO_REQ
	*/
    EV_NVMFGTEST_PROD_INFO_RSP,


	/*<<终端加载e2prom信息完成后的通知消息>>
    *参    数 : 无
	*消息流向 : mt->工具(mt加载模式)
	*/
    EV_NVMFGTEST_UPDATE_E2PROM_SUCCESS_NTF,


    /*<<建立TCP连接后的Osp通知消息>>
	*
	*消息流向 : mt->工具(mt客户端模式)
	*参    数 :(u8)*32+(CLoginRequest)+(CDeviceInfo)
	*
    *消息流向 :工具->mt(mt服务器模式)
	*参    数 : 无
	*
	* see ev_CNPRODUCETESTLOGIN_ACK
	*/
    EV_NVMFGTEST_REGISTER_REQ,


    /*<<建立TCP连接后的Osp通知消息响应>>
    *
	*消息流向 : 工具->mt(mt客户端模式)
	*参    数 : 无	*
  
	* see ev_CNPRODUCETESTLOGIN_REQ
	*/
    EV_NVMFGTEST_REGISTER_RSP,

    /*<<终端信息通知>>
    *参    数 : TTerminalInfo 终端信息
	*消息流向 : mt->工具
	* see 
	*/
    EV_NVMFGTEST_TERMINAL_INFO,


    /*<<测试请求>>
    *参    数 : TNvAutoTestMsg  测试详细内容
	*消息流向 : 工具->mt
	* see EV_NVMFGTEST_TESTRESULT_NTF
	*/
    EV_NVMFGTEST_TEST_CMD,


    /*<<结果通知>>
    *参    数 : TNvAutoTestMsg  测试详细内容
	*消息流向 : mt->工具
	* see EV_NVMFGTEST_TEST_CMD
	*/
    EV_NVMFGTEST_TESTRESULT_NTF,

    /*<<wifi信号强度通知>>
    *参    数 : EmWifiSignalLevel  wifi信号强度
	*消息流向 : mt->工具
	* see 
	*/
    EV_NVMFGTEST_WIFI_SIGNAL_NTF,


	/*<<MIC连接状态通知>>
    *参    数 : EmNvMicConnectStatus
	*消息流向 : mt->工具
	* see 
	*/
    EV_NVMFGTEST_MIC_CONNECT_STATUS_NTF,

	/*<<测试完成通知>>
	*参    数 ： TNvAutoTestFinishMsg
	*消息流向 ： 工具->mt
	*/
	EV_NVMFGTEST_TESTFINISH_CMD,

	/*<<打开MIC射频通知>>
	*参    数 ： 无
	*消息流向 ： 工具->mt
	*/
	EV_NVMFGTEST_OPENMICHOTSPOT_CMD,

	/*<<无线麦克1配对成功通知>>
	*参    数 ： 无
	*消息流向 ： 工具<-mt
	*/
	EV_NVMFGTEST_WIRELESSCONNECT_NTF,
	  
	/*<<加载红外单片机命令>>
	*参    数 ： 
	*消息流向 ： 工具->mt
	*/
	EV_NVMFGTEST_PROGRAMFIRMWARE_CMD,

	/*<<加载红外单片机结果通知>>
	*参    数 ： BOOL32
	*消息流向 ： 工具->mt
	*/
	EV_NVMFGTEST_PROGRAMFIRMWARE_NTF,

	/*<<加载mic射频结果通知>>
	*参    数 ： BOOL32
	*消息流向 ： 工具->mt
	*/
	EV_NVMFGTEST_PROGRAMMIC_NTF,

	/*<<加载hdbaset结果通知>>
	*参    数 ： BOOL32
	*消息流向 ： 工具->mt
	*/
	EV_NVMFGTEST_PROGRAMHDBASET_NTF,


	/*<<同步PC时间命令>>
	*参    数 ： TNvKdvTime
	*消息流向 ： 工具->mt
	*/
	EV_NVMFGTEST_UPDATEPCTIME_CMD,

	/*<<同步PC时间结果通知>>
	*参    数 ： BOOL32
	*消息流向 ： 工具->mt
	*/
	EV_NVMFGTEST_UPDATEPCTIME_NTF,


    EVSEG_NVMFGTEST_COMMON_EVENT_END = (EVSEG_NVMFGTEST_COMMON_EVENT_BGN + 50),



    //工具内部 或 mfgtest内部 使用的消息
    EVSEG_NVMFGTEST_INNER_EVENT_BGN = EVSEG_NVMFGTEST_COMMON_EVENT_END,
    EVSEG_NVMFGTEST_INNER_EVENT_END = (EVSEG_NVMFGTEST_INNER_EVENT_BGN + 250),
};

#endif
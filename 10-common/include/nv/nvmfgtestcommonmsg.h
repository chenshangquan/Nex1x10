//����EVSEG_NVOSPMSG_INNER_BGN�ǿ��Ը�����ģ��ʹ�ã�Ϊ�˷�ֹ��ͻ����ʹ��EVSEG_NVOSPMSG_INNER_BGN��ͷ�ļ���ʹ��_HD_INNER_OSPMSG_��ȷ��ģ��֮�䲻��ͻ
#ifndef _HD_NVMFGTEST_OSPMSG_
#define _HD_NVMFGTEST_OSPMSG_

#include "nvospmsgid.h"


enum EmNvMfgTestCommonMsgSegs
{
    //������mfgtest֮�佻����Ϣ
    EVSEG_NVMFGTEST_COMMON_EVENT_BGN = EVSEG_NVOSPMSG_INNER_BGN,

    /*<<��ѯEEPROM��Ϣ(��Ʒ��Ϣ)>>
    *��    �� : TBrdInfo   ������Ϣ
	*��Ϣ���� : mt->����
	* see EV_NVMFGTEST_PROD_INFO_RSP
	*/
    EV_NVMFGTEST_PROD_INFO_REQ,


    /*<<����EEPROM��Ϣ(��Ʒ��Ϣ)>>
    *��    �� : TPrdInfo   ��Ʒ��Ϣ
	*��Ϣ���� : ����->mt
	* see EV_NVMFGTEST_PROD_INFO_REQ
	*/
    EV_NVMFGTEST_PROD_INFO_RSP,


	/*<<�ն˼���e2prom��Ϣ��ɺ��֪ͨ��Ϣ>>
    *��    �� : ��
	*��Ϣ���� : mt->����(mt����ģʽ)
	*/
    EV_NVMFGTEST_UPDATE_E2PROM_SUCCESS_NTF,


    /*<<����TCP���Ӻ��Osp֪ͨ��Ϣ>>
	*
	*��Ϣ���� : mt->����(mt�ͻ���ģʽ)
	*��    �� :(u8)*32+(CLoginRequest)+(CDeviceInfo)
	*
    *��Ϣ���� :����->mt(mt������ģʽ)
	*��    �� : ��
	*
	* see ev_CNPRODUCETESTLOGIN_ACK
	*/
    EV_NVMFGTEST_REGISTER_REQ,


    /*<<����TCP���Ӻ��Osp֪ͨ��Ϣ��Ӧ>>
    *
	*��Ϣ���� : ����->mt(mt�ͻ���ģʽ)
	*��    �� : ��	*
  
	* see ev_CNPRODUCETESTLOGIN_REQ
	*/
    EV_NVMFGTEST_REGISTER_RSP,

    /*<<�ն���Ϣ֪ͨ>>
    *��    �� : TTerminalInfo �ն���Ϣ
	*��Ϣ���� : mt->����
	* see 
	*/
    EV_NVMFGTEST_TERMINAL_INFO,


    /*<<��������>>
    *��    �� : TNvAutoTestMsg  ������ϸ����
	*��Ϣ���� : ����->mt
	* see EV_NVMFGTEST_TESTRESULT_NTF
	*/
    EV_NVMFGTEST_TEST_CMD,


    /*<<���֪ͨ>>
    *��    �� : TNvAutoTestMsg  ������ϸ����
	*��Ϣ���� : mt->����
	* see EV_NVMFGTEST_TEST_CMD
	*/
    EV_NVMFGTEST_TESTRESULT_NTF,

    /*<<wifi�ź�ǿ��֪ͨ>>
    *��    �� : EmWifiSignalLevel  wifi�ź�ǿ��
	*��Ϣ���� : mt->����
	* see 
	*/
    EV_NVMFGTEST_WIFI_SIGNAL_NTF,


	/*<<MIC����״̬֪ͨ>>
    *��    �� : EmNvMicConnectStatus
	*��Ϣ���� : mt->����
	* see 
	*/
    EV_NVMFGTEST_MIC_CONNECT_STATUS_NTF,

	/*<<�������֪ͨ>>
	*��    �� �� TNvAutoTestFinishMsg
	*��Ϣ���� �� ����->mt
	*/
	EV_NVMFGTEST_TESTFINISH_CMD,

	/*<<��MIC��Ƶ֪ͨ>>
	*��    �� �� ��
	*��Ϣ���� �� ����->mt
	*/
	EV_NVMFGTEST_OPENMICHOTSPOT_CMD,

	/*<<�������1��Գɹ�֪ͨ>>
	*��    �� �� ��
	*��Ϣ���� �� ����<-mt
	*/
	EV_NVMFGTEST_WIRELESSCONNECT_NTF,
	  
	/*<<���غ��ⵥƬ������>>
	*��    �� �� 
	*��Ϣ���� �� ����->mt
	*/
	EV_NVMFGTEST_PROGRAMFIRMWARE_CMD,

	/*<<���غ��ⵥƬ�����֪ͨ>>
	*��    �� �� BOOL32
	*��Ϣ���� �� ����->mt
	*/
	EV_NVMFGTEST_PROGRAMFIRMWARE_NTF,

	/*<<����mic��Ƶ���֪ͨ>>
	*��    �� �� BOOL32
	*��Ϣ���� �� ����->mt
	*/
	EV_NVMFGTEST_PROGRAMMIC_NTF,

	/*<<����hdbaset���֪ͨ>>
	*��    �� �� BOOL32
	*��Ϣ���� �� ����->mt
	*/
	EV_NVMFGTEST_PROGRAMHDBASET_NTF,


	/*<<ͬ��PCʱ������>>
	*��    �� �� TNvKdvTime
	*��Ϣ���� �� ����->mt
	*/
	EV_NVMFGTEST_UPDATEPCTIME_CMD,

	/*<<ͬ��PCʱ����֪ͨ>>
	*��    �� �� BOOL32
	*��Ϣ���� �� ����->mt
	*/
	EV_NVMFGTEST_UPDATEPCTIME_NTF,


    EVSEG_NVMFGTEST_COMMON_EVENT_END = (EVSEG_NVMFGTEST_COMMON_EVENT_BGN + 50),



    //�����ڲ� �� mfgtest�ڲ� ʹ�õ���Ϣ
    EVSEG_NVMFGTEST_INNER_EVENT_BGN = EVSEG_NVMFGTEST_COMMON_EVENT_END,
    EVSEG_NVMFGTEST_INNER_EVENT_END = (EVSEG_NVMFGTEST_INNER_EVENT_BGN + 250),
};

#endif
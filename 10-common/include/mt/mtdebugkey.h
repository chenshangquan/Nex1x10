#ifndef _MTDEBUGKEY_H_
#define _MTDEBUGKEY_H_

/*
��һ��debug key ����
 1. ��debugekey.h �мӸ�json��ʽ�����Ӻ�Ĭ��ֵ��ע�ͣ� �����ⲿ��Ա֪����ô����
 2. ��mtdskey.h �м�һ��cfg_key�� ��ע�ͣ�������ͨ��debug������ֻΪĳ����Ʒ����
 3. ��debugcfg.h��debug.cpp�м�ʵ�����������棺 
    static void Default_TRtpSamePort( mt::TBOOL32 &tCommonDebug);
	static void Read_TRtpSamePort();
4. ��debucfg.cpp�е� ReadDebugCfg()�ӿ��м�read�ӿڣ� ������key ֻΪĳ����Ʒ���� Ҫ���ֺ�
*/


/*
{
	"TRtpSamePort":       
	{
	   "comment": "�շ��˿��Ƿ���,ͨ��debug",
	   "bSame": false
	},
	"TAudioRemoveG719":   
	{
	  "comment": "�Ƿ���Ƶȥ��g719����,ͨ��debug",
	  "bRemove": false
	},
	"TAdaptiveVideo": 
	{
	   "comment": "�Ƿ���Ƶ�غ�����Ӧ,��windows��Ʒ,x500��UI����",
	   "bAdapt": false
	},
	"mtSecVidDecDynamicPayload":
	{  
	  "comment": "����ǿ��payloadӳ���,ͨ��debug",
      "mtKeyRmtActivePT": 0,
	  "mtKeyRealPT": 0
	},
	"TForceRtpExStrip":      
	{
	   "comment": "ͨ��debug, ǿ��ȥ��rtp���Ǳ���չͷ�� ����ƽ̨����һ���⳧�̵�ƽ̨���ն˷������ƴ�ƽ̨��ת������ƽ̨�� ��Ҫȥ��ͷ",
	   "bEnable": false
	},
	"TEnableDsp6678Detect":      
	{
	   "comment": "�ն��Ƿ�����265�ӿ�����Ӳ�ն�",
	   "bEnable": true
	},
	"TAudioRemoveLCLD":   
	{
	  "comment": "�Ƿ���Ƶȥ��lcld����,ͨ��debug",
	  "bRemove": false
	},
	"TEnableVidBitRateCtrl":  
	{
	"comment": "�Ƿ������޸���Ƶ��������,ͨ��debug",
	"bEnable": true
	},
	"TVideoSliceCount":
	{
	"comment": "��Ƶ���ְ���,ͨ��debug",
	"wSliceCount": 0
	},
	"TG711AudioDuration":  
	{
	"comment": "ͨ��debug, Ĭ�ϱ���֧��30ms",
	"wDuration": 30
	},
	"TAudioRemoveOPUS":   
	{
	  "comment": "�Ƿ���Ƶȥ��OPUS����,ͨ��debug",
	  "bRemove": false
	},
	"TEnableBfcpTwice":  
	{
	"comment": "�Ƿ�����bfcp������Ĭ����false, ֻ�������� �� ����invite����sdp�����",
	"bEnable": false 
	},
	"TEnalbeRemoveMulAudFormats":
	{
	  "comment": "���ڶ�ͨ,711a=0, 711u=1,722=2,7231=3,728=4,729=5,mp3=6,721=7,7221c=8,719=9,lc=10,ld=11,opus=12",
	  "bEnable": false,
	  "emAuds":[8,5]
	},
	"mtSecImageSequenceNumberType":  
	{
	   "comment": "��Ƶ���������ͼ���������,��Ӳ�ն�",
	   "mtKeyImageSequenceNumberType":0
	},
	"TSetRoundTripType":   
	{
	  "comment": "�������ñ��ʽ 0����������Э��RoundTrip,1������Э��RoundTrip,����ҵ��ͨ��������������,2������Э��RoundTrip,ͨ��debug",
	  "dwRoundTripType": 0
	},
	"TEnableKedaAacSampFreq32K":
	{
	   "comment": "�Ƿ�ƴ��ն�aac������32K",
	   "bEnable": true
	},
	"TRegTimeout":
	{
	"comment": "ͨ��debug�� ע�ᳬʱʱ��Ĭ��15,��λΪs,��ΧΪ[5-20]",
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
	   "comment": "�Ƿ��Զ�ras",
	   "bEnable":false
	},
	"TSipCallPort":
	{ 
	   "comment": "��ʼ��sip�����˿�",
	   "callport":5060,
	   "tlsport":5061
	},
	"mtAudDecDynamicPayload":
	{  
	  "comment": "����ǿ����Ƶpayloadӳ���,ͨ��debug",
      "mtKeyRmtActivePT": 0,
	  "mtKeyRealPT": 0
	},
	"TIsIgnoreSetBitrateZero":
	{
	"comment": "ͨ��debug, �Ƿ��������Ϊ0������,��ʱֻ������Ƶ",
	"bIgnore": true
	},
	"T323AdditionalConfig":
	{
	"comment": "ͨ��debug, 323addtional����, ע��md5���ͺ�460�������ͣ� ��Щ�⳧�̲�һ��",
	"emRrqAuthAlgType": 0,
	"emFacilityReason": 5
	},
	"TKeyFrameInterval":
	{
	"comment": "ͨ��debug,��Ƶ���͹ؼ�֡��̼��ʱ�䣬��λms",
	"dwInterval": 0
	}
}
*/


#endif
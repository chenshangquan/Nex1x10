#ifndef _NVDEBUGKEY_H_
#define _NVDEBUGKEY_H_

/*
��һ��debug key ����
 1. ��debugekey.h �мӸ�json��ʽ�����Ӻ�Ĭ��ֵ��ע�ͣ� �����ⲿ��Ա֪����ô����
 2. ��nvdskey.h �м�һ��cfg_key�� ��ע�ͣ�������ͨ��debug������ֻΪĳ����Ʒ����
 3. ��debugcfg.h��debug.cpp�м�ʵ�����������棺 
    static void Default_TRtpSamePort( nv::TBOOL32 &tCommonDebug);
	static void Read_TRtpSamePort();
4. ��debucfg.cpp�е� ReadDebugCfg()�ӿ��м�read�ӿڣ� ������key ֻΪĳ����Ʒ���� Ҫ���ֺ�
*/


/*
{
	"TRtpSamePort":        ///�շ��˿��Ƿ���,ͨ��debug
	{
	   "bSame": false
	},
	"TAudioRemoveG719":   //�Ƿ���Ƶȥ��g719����,ͨ��debug
	{
	  "bRemove": false
	},
	"TAdaptiveVideo":     //�Ƿ���Ƶ�غ�����Ӧ,��windows��Ʒ
	{
	   "bAdapt": false
	},
	"nvSecVidDecDynamicPayload": //����ǿ��payloadӳ���,ͨ��debug
	{
      "nvKeyRnvActivePT": 107,
	  "nvKeyRealPT": 106
	},
	"nvSecImageSequenceNumberType":   ///��Ƶ���������ͼ���������,��Ӳ�ն�
	{
	"nvKeyImageSequenceNumberType":1
	},
	"TForceRtpExStrip":               //ͨ��debug, ǿ��ȥ��rtp���Ǳ���չͷ�� ����ƽ̨����һ���⳧�̵�ƽ̨���ն˷������ƴ�ƽ̨��ת������ƽ̨�� ��Ҫȥ��ͷ
	{
	"bEnable": false
    },
    "TEnableDsp6678Detect":               //�ն��Ƿ�����265�ӿ�����Ӳ�ն�
    {
    "bEnable": true
    },
	"TAudioRemoveLCLD":   //�Ƿ���Ƶȥ��lcld����,ͨ��debug
	{
	"bRemove": false
	},
	"TAudioPrecedence":   //�Ƿ���Ƶ�����౶����,��wins
	{
	"bEnable": true
	},
	"TForceSet323Stack":   //�Ƿ�ǿ������323Э��ջΪ�Ǳ�/��׼,ͨ��debug
	{
	"bEnable": false
	"bStand" : true
	}
}
*/


#endif
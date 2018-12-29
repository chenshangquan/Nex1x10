/*******************************************************************************//**
*@file          mtapi_struct.h
*@brief         �ṩmtapi����Ľṹ�嶨��
*
*@author        ruiyigen
*@version       5.0    
*@date          20150328
*@copyright     (c)1995-2015 Suzhou Keda Technology Co.,Ltd. All rights reserved
***********************************************************************************/
#ifndef _MTAPI_STRUCT_H_
#define _MTAPI_STRUCT_H_
/**@addtogroup common ����
*@{
*/

/**@addtogroup struct �ṹ����
*@{
*/

#include <string.h> //linux�а���memset
#include "mtapi_enum.h"
#include "mtapi_def.h"


/** ������Ϣ */
typedef struct tagTMTNetBandWidth_Api 
{
	u32 dwBandWidth;		           ///< ����, ��λKB/s
	u32 dwDropRate;		               ///< �ô����Ӧ�Ķ�����, ��λǧ��֮�� 
public:
	tagTMTNetBandWidth_Api(){ memset( this, 0, sizeof( struct tagTMTNetBandWidth_Api ) ); }
}*PTMTNetBandWidth_Api, TMTNetBandWidth_Api;


/** ����״̬*/
typedef struct tagTMTNetStatus_Api
{
	BOOL32 bTimeout;					    ///< �˴δ������Ƿ�ʱ
	TMTNetBandWidth_Api tSendBandwidth;	    ///< ���ʹ���(����), ��λKB/s
	TMTNetBandWidth_Api tRecvBandWidth;	    ///< ���մ���(����), ��λKB/s 
public:
	tagTMTNetStatus_Api(){memset( this, 0, sizeof( struct tagTMTNetStatus_Api ) ); }
}*PTMTNetStatus_Api, TMTNetStatus_Api;

/** �û���Ϣ */
typedef struct tagTUserFullInfo_Api
{
	u32           dwUserID;                                  ///< �û�Ψһ��ʾ��
	s8            achUsrName[KMTAPI_MAX_USERNAME_LEN+1];     ///< �û���
	s8            achUsrPwd[KMTAPI_MAX_USERPWD_LEN+1];       ///< ���루�����ˣ�sm3������64�ֽڵ�16�����ַ�����md5������32�ֽڵ�16�����ַ���
	                                                         ///< 16�����ַ���ͳһСд��ʾ
	u32           dwRights;                                  ///< �û�Ȩ�ޣ�admin�û�����ͨ�û���
	s8            achFullUsrName[KMTAPI_MAX_FULL_USERNAME_LEN+1];///< �����û���
	s8            achUsrDesc[KMTAPI_MAX_USER_DESCRIPTION_LEN+1]; ///< �û�����
public:
	tagTUserFullInfo_Api(){ memset( this, 0, sizeof( struct tagTUserFullInfo_Api ) );}
}*PTUserFullInfo_Api, TUserFullInfo_Api;

/** ���û���Ϣ */
typedef struct tagTMultiUserFullInfo_Api
{
	TUserFullInfo_Api    arrTUserInfo[KMTAPI_MAX_MUTLIUSERINFO_NUM];     ///< �û���Ϣ
	u16                  byCnt;                                          ///< ʵ������
public:
	tagTMultiUserFullInfo_Api(){ memset( this, 0, sizeof( struct tagTMultiUserFullInfo_Api) ); }
}*PTMultiUserFullInfo_Api, TMultiUserFullInfo_Api;

/** �û�ID */
typedef struct tagTMTUsersId_Api
{
	u8  byCnt;                                                               ///< ʵ������
	u32 adwId[KMTAPI_MAX_MUTLIUSERINFO_NUM]; ///< �û�ID
public:
	tagTMTUsersId_Api() { memset( this, 0, sizeof( struct tagTMTUsersId_Api)); }
}*PTMTUsersId_Api, TMTUsersId_Api;

/** �û�������*/
typedef struct tagTUserReqResult_Api
{
	TUserFullInfo_Api    tUserInfo;                                 ///< �û���Ϣ
	u32                  dwUserReqRst;                              ///< ��Ӧ�û�������
public:
	tagTUserReqResult_Api(){ memset( this, 0, sizeof( struct tagTUserReqResult_Api ) ); }
}*PTUserReqResult_Api, TUserReqResult_Api;

/** ���û������� */
typedef struct tagTMultiUserReqResult_Api
{
	TUserReqResult_Api  arrMultUserReqRslt[KMTAPI_MAX_MUTLIUSERINFO_NUM]; ///< �û�������
	u8 byCnt;                                                             ///< ����
public:
	tagTMultiUserReqResult_Api(){memset( this, 0, sizeof( struct tagTMultiUserReqResult_Api ) ); }
}*PTMultiUserReqResult_Api, TMultiUserReqResult_Api;




/** AEC΢��������Ϣ */
typedef struct tagTAdjustAecParamCfg_Api
{
	BOOL32           bAuto;                             ///< �Ƿ��Զ�
	u32              dwVal;                             ///< �Զ�����΢��ֵ
	BOOL32           bEnable;							///<�Ƿ���AEC
	u32              dwManualVal;                       ///< �ֶ�����΢��ֵ

public:
	tagTAdjustAecParamCfg_Api(){ memset( this, 0, sizeof( struct tagTAdjustAecParamCfg_Api) ); }
}*PTAdjustAecParamCfg_Api,TAdjustAecParamCfg_Api;


/** �����ն�����Ƶ�豸�б� */
typedef struct tagTDevInfo_Api
{
	s8              achDevName[KMTAPI_MAX_MT_ALIAS_LEN+1];           ///< �豸���ƣ����ܻ��ظ�
	s8              achDevGuid[KMTAPI_MAX_DEVICE_GUID_LEN+1];        ///< �豸GUID������Ψһ��
public:
	tagTDevInfo_Api(){ memset( this, 0, sizeof(tagTDevInfo_Api) ); }
}*PTDevInfo_Api, TDevInfo_Api;

/** �豸�б���Ϣ */
typedef struct tagTDevInfoList_Api
{
	TDevInfo_Api        arrTDevInfo[KMTAPI_MAX_DEVICE_LIST_NUM]; ///< ����豸�б���Ϣ
	u8              byCnt;                                       ///< ʵ���б�����
public:
	tagTDevInfoList_Api(){ memset( this, 0, sizeof( struct tagTDevInfoList_Api) ); }
}*PTDevInfoList_Api, TDevInfoList_Api;



/** ��Ƶ�����״̬ */
typedef struct tagTMtVideoCodecStatus_Api
{
	BOOL32                  bRuning;           ///< �Ƿ��ڹ���
	EmVidFormat_Api         emFormat;          ///< ��Ƶ�����ʽ
	EmMtResolution_Api   emRes;                ///< ��Ƶ�����ʽ
	u16                     wBitrate;          ///< ��Ƶ��������(��λ:kbps)
	u16                     wAverageBitrate;   ///< ����Ƶ��ƽ��������(��λ:kbps)
	BOOL32                  IsEncrypt;         ///< ����Ƶ�����Ƿ����
	EmEncryptArithmetic_Api emArithmetic;	   ///< ���ӱ���ʹ�õļ����㷨	

public:
	tagTMtVideoCodecStatus_Api()
	{ 
		memset ( this ,0 ,sizeof( struct tagTMtVideoCodecStatus_Api) );
	}
}*PTMtVideoCodecStatus_Api,TMtVideoCodecStatus_Api ;


/** �ն˱�� */
typedef struct tagTMtId_Api
{
	u32         dwMcuId;                ///< mcu ����
	u32         dwTerId;                ///< �ն� ����
public:
	tagTMtId_Api(){ memset( this ,0 ,sizeof( struct tagTMtId_Api ) );	}

}*PTMtId_Api, TMtId_Api;

/** �ն˱���б� */
typedef struct tagTMtIdList_Api
{
	TMtId_Api  atList[KMTAPI_MAX_CONF_MT_MEMBER_NUM]; ///< �ն˱���б���Ϣ
	u32 dwCount;                                                                       ///< ʵ�ʸ���
public:
	tagTMtIdList_Api(){ memset( this ,0 ,sizeof( struct tagTMtIdList_Api ) );	}

}*PTMtIdList_Api, TMtIdList_Api;


/** ѡ���ն˲��� */
typedef struct tagTViewTerParam_Api
{
	TMtId_Api                  tTer;                             ///< �ն�
	EmMtMediaType_Api          emViewType;       ///< ��Ƶ/��Ƶ/����Ƶ
	BOOL32                     bViewAllChan;              ///< �Ƿ�ѡ������ն˵�����ͨ��
	EmCodecComponentIndex_Api  emChanIdx;  ///< �����,����ͨ��id
public:
	tagTViewTerParam_Api()
	{ 
		memset( this ,0 ,sizeof( struct tagTViewTerParam_Api ) );
		emViewType = emMediaAV_Api;
		bViewAllChan = TRUE;
		emChanIdx = em1st_Api; 
	}

}*PTViewTerParam_Api, TViewTerParam_Api;



/** ������Ϣ�б� */
typedef struct tagTCallInfoList_Api
{
	s8 aaCallInfoList[KMTAPI_COUNT_128][KMTAPI_MAX_MT_ALIAS_LEN+1]; ///< �б���Ϣ
	u8 byCnt;                                                                                                 ///< �б����
public:
	tagTCallInfoList_Api()
	{
		memset( aaCallInfoList, 0, sizeof(aaCallInfoList) );
		byCnt = 0;
	}
}*PTCallInfoList_Api, TCallInfoList_Api;


/** �������(net��ַ) */
typedef struct tagTNetAddr_Api
{
	EmIpAddrType_Api  emIpType;                          ///< IP��ַ����V4/V6
	u32           dwIp;                                               ///< IP��ַ(������)
	s8            achIpV6[KMTAPI_BUF_128_LEN+1];   ///< IPV6��Ϣ
	u32           dwPort;                                           ///< �˿�
public:
	tagTNetAddr_Api()
	{ 
		memset( this ,0 ,sizeof( struct tagTNetAddr_Api ) );	
		emIpType = emIpV4_Api;
	}
}*PTNetAddr_Api, TNetAddr_Api;


/** �ն˱�����Ϣ */
typedef struct tagTMtAlias_Api
{
	EmMtAliasType_Api emAliasType;                               ///< ��������
	s8            achAlias[KMTAPI_MAX_MT_ALIAS_LEN+1];  ///< ������Ϣ
public:
	tagTMtAlias_Api(){ memset( this ,0 ,sizeof( struct tagTMtAlias_Api ) );	}
}*PTMtAlias,TMtAlias_Api;

/** �ն˱����б� */
typedef struct tagTMultMtAlias_Api
{
	TMtAlias_Api      arrAlias[KMTAPI_MAX_MT_ALIAS_NUM];      ///< �Զ˱��������Զ��alias, e164
	u8                byCnt;                                                               ///< ʵ�ʱ�������
public:
	tagTMultMtAlias_Api(){ memset( this ,0 ,sizeof( struct tagTMultMtAlias_Api ) );	}
}*PTMultMtAlias_Api,TMultMtAlias_Api;



/** �ն˵�ַ */
typedef struct tagTMtAddr_Api
{
	EmMtAddrType_Api    emAddrType;			 	                 ///< ��ַ���� ip or alias or e164
	TNetAddr_Api		tIP;					                                 ///< �ն�IP��Ϣ 
	s8			    achAlias[KMTAPI_MAX_MT_ALIAS_LEN+1];    ///< �ն˱���
public:
	tagTMtAddr_Api(){memset( this ,0 ,sizeof( struct tagTMtAddr_Api));	}
}*PTMtAddr_Api,TMtAddr_Api;

/** ��ƵԴ��Ϣ */
typedef struct tagVideoSourceInfo_Api
{
	u8  byVideoPort;                                           ///< ��ƵԴ����
	s8  achPortName[ KMTAPI_BUF_128_LEN+1];  ///< ����
public:
	tagVideoSourceInfo_Api() { memset( this, 0, sizeof(tagVideoSourceInfo_Api) ); } 

}TVideoSourceInfo_Api;

/** ��ƵԴ�б���Ϣ */
typedef struct tagMultiVideoSourceInfo_Api
{
	TVideoSourceInfo_Api atVidSource[ KMTAPI_COUNT_32 ]; ///< �б���Ϣ
	u8 byCnt;                                                                          ///< �б����
public:
	tagMultiVideoSourceInfo_Api() { memset( this, 0, sizeof(tagMultiVideoSourceInfo_Api) ); } 
}TMultiVideoSourceInfo_Api;


typedef struct tagVideoAlias_Api 
{
	EmCodecComponent_Api         emType;                //��ƵԴ����
	EmCodecComponentIndex_Api    emIdx;                 //��ƵԴid
	TMultiVideoSourceInfo_Api    tMultiVideoSource;     //�����ƵԴ    

public:
	tagVideoAlias_Api() { memset( this, 0, sizeof(tagVideoAlias_Api) ); } 

}TVideoAlias_Api;

typedef struct tagMultiVideoAlias_Api
{
	TVideoAlias_Api  atVideoAlias[KMTAPI_MAX_ENCODE_NUM];
	u8 byCnt;

public:
	tagMultiVideoAlias_Api() { memset( this, 0, sizeof(tagMultiVideoAlias_Api) ); } 

}TMultiVideoAlias_Api;





/** ��ǰ��ƵԴ��Ϣ */
typedef struct tagTVideoInfo_Api
{
	EmCodecComponentIndex_Api  emChanIdx;    ///< ĳһ·
	u32      dwVideoSrc;                                         ///< ��ǰ�ı�����ƵԴ������ö�٣�����������
	BOOL32   bFeccEnable;                                    ///< �Ƿ�����Զҡ
	BOOL32   bHasVideo;                                      ///< �Ƿ�����ƵԴ

public:
	tagTVideoInfo_Api(){ memset ( this ,0 ,sizeof( struct tagTVideoInfo_Api )); }

}*PTVideoInfo_Api, TVideoInfo_Api;

/** ��ǰ��ƵԴ��Ϣ�б� */
typedef struct tagTMultiVideoInfo_Api
{
	TVideoInfo_Api  atVideoInfo[KMTAPI_COUNT_8];   ///< �б���Ϣ�����8��ͨ������������
	u32 dwCount;                                                        ///< �б����

public:
	tagTMultiVideoInfo_Api(){ memset ( this ,0 ,sizeof( struct tagTMultiVideoInfo_Api )); }

}*PTMultiVideoInfo_Api , TMultiVideoInfo_Api;

/** �ն�״̬����ƽ̨ȡ������ */
typedef struct tagTTerStatus_Api
{
	EmMtModel_Api  emMtModel;	              ///< �ն��ͺ�
	u8		byEncVol;				                         ///< ��ǰ��������(��λ:�ȼ�)
	u8		byDecVol;				                         ///< ��ǰ��������(��λ:�ȼ�)
	BOOL32	bIsMute;				                 ///< �Ƿ�����	
	BOOL32	bIsQuiet;				                ///< �Ƿ���	
	BOOL32	bMatrixStatus;			            ///< ���þ���״̬		(TRUE ok FALSE err)
	EmMtMediaType_Api  emViewedType; ///< ��ѡ������
	TMultiVideoInfo_Api tVideoInfoList;     ///< ��ƵԴ�б�

public:
	tagTTerStatus_Api(){ memset ( this ,0 ,sizeof( struct tagTTerStatus_Api ));}
}*PTTerStatus_Api, TTerStatus_Api;


/** �ն�״̬��Ϣ�ṹ */
typedef struct tagTMtEntityStatus_Api
{
	u32              dwMcuId;    ///< mcu ID
	u32              dwTerId;      ///< mt ID
	TTerStatus_Api   tStatus; ///< �����Ա�ն�״̬��Ϣ
public:
	tagTMtEntityStatus_Api(){ memset( this ,0 ,sizeof( struct tagTMtEntityStatus_Api ) );	}
}*PTMtEntityStatus_Api, TMtEntityStatus_Api;

/** �ն�״̬��Ϣ�б� */
typedef struct tagTMtEntityStatusList_Api
{
	TMtEntityStatus_Api   atMtEntityStatus[KMTAPI_MAX_CONF_MT_MEMBER_NUM]; ///< �б���Ϣ
	u32 dwCount;                                                                                                        ///< �б����
public:
	tagTMtEntityStatusList_Api(){ memset( this ,0 ,sizeof( struct tagTMtEntityStatusList_Api ) );	}
}TMtEntityStatusList_Api;


/** 5.0 �Ǳ� ras�ӻ���� */ 
typedef struct tagTMtJoinConfParam_Api
{
	u16     wCallRate;                                                          ///< ��������
	s8      achConfE164[KMTAPI_MAX_CONF_E164_LEN+1]; ///< �������
	s8      achConfPwd[KMTAPI_MAXLEN_PASSWORD+1];    ///< ��������
	s8      achConfName[KMTAPI_MAX_CONF_NAME_LEN+1]; ///< ��������
	BOOL32  bDialJoinConf;                                               ///< �Ƿ�绰���
	s8      achDialNum[KMTAPI_BUF_32_LEN+1];                ///< ����绰��ᣬ�绰����
	s8      achAiConfName[KMTAPI_MAX_CONF_NAME_LEN+1]; ///ai ��������ȥ���� ���� ��-���� ��_��, ����ת������
public:
	tagTMtJoinConfParam_Api()
	{
		wCallRate = 0;
		memset( achConfName, 0, sizeof(achConfName) );
		memset(achConfPwd, 0, sizeof(achConfPwd) );
		memset(achConfE164, 0, sizeof(achConfE164) );
		bDialJoinConf = FALSE;                           ///<Ĭ����Ƶ���
		memset(achDialNum, 0, sizeof(achDialNum) );
		memset(achAiConfName, 0, sizeof(achAiConfName) );
	}
}*PTMtJoinConfParam_Api, TMtJoinConfParam_Api;


/** setup����Ĳ���  �ϵ�ƽ̨����������gb2312��ʾ��64λ������ܱ�ʾ32�����֣�
����sdk����utf-8��ʾ��sdk���97���ֽ�֮�󶼱��ص��� ��ʱ����*/  

typedef struct tagTMtSetupCreatConfParam_Api
{
	EmMtAddrType_Api     emCallAddrType;                                            ///< ָ���º������ͣ� ip/alias/e164�� �п���ip�ͱ�������
	TNetAddr_Api         tCalledAddr;                                               ///< ���е�ַ
	TMultMtAlias_Api     tCalledAlias;                                              ///< ���б���
	TMtAddr_Api          atMtList[KMTAPI_MAX_CONF_MT_MEMBER_NUM];                   ///< �����ն��б�
	u16                  wMtMemberCnt;                                              ///< �����ն˸���
	u16                      wCallRate;                                              ///< ����ĺ�������(kbps)  
	s8                       achConfId[KMTAPI_MAX_CONF_ID_LEN+1];                    ///< ����ID
	s8                       achConfName[KMTAPI_MAX_CONF_NAME_LEN+1];                ///< ��������
	s8                       achConfNumber[KMTAPI_MAX_CONF_E164_LEN+1];              ///< �������
	s8                       achConfPwd[KMTAPI_MAXLEN_PASSWORD+1];                   ///< ��������
	BOOL32                   bIsNeedPwd;                                             ///< �Ƿ���Ҫ����
	u32                      dwConfDuration;		                                 //< �������ʱ��		
	BOOL32                   bIsAutoVmp;		  	                                 ///< �Ƿ��Զ�����ϳ�
	BOOL32                   bIsMix;	  		                                     ///< �Ƿ����
	EmEncryptArithmetic_Api  emEncType;                                              ///< �����㷨   
	EmVidFormat_Api       emVidFormat;		                                         ///< ������Ƶ��ʽ(VIDEO_H261��)
	EmMtResolution_Api    emResolution;		                                         ///< ������Ƶ�ֱ���(VIDEO_CIF��)
	EmVidFormat_Api       emAssVidFormat;		                                     ///< ������ʽ
	EmMtResolution_Api    emAssVidRes;	                                             ///< �����ֱ���
	u32	                  dwAssVidFps;		                                                     ///< ����֡�� 
	EmAudFormat_Api       emAudFormat;		                                         ///< ������Ƶ��ʽ(AUDIO_MP3��)
	EmAacChnlNum_Api      emChnl_num;                                               ///< �����lc,ld��������
	EmH264Profile_Api     emVidH264Profile;                                          //H264profile��ʽ  �����ʽ������video�ĸ�ʽ
public:	
	tagTMtSetupCreatConfParam_Api(){ memset( this ,0 ,sizeof( struct tagTMtSetupCreatConfParam_Api ) );	}
}*PTMtSetupCreateConfParam_Api, TMtSetupCreateConfParam_Api;

/** ����ʱ�� */
typedef struct tagTMTTime_Api
{
	u16 wYear;               ///< ���
	u8  byMonth;           ///< �·�
	u8  byDay;               ///< ����
	u8  byHour;             ///< Сʱ
	u8  byMinute;          ///< ����
	u8  bySecond;          ///< ��
	u16 wMicroSecond; ///< ΢��
public:
	tagTMTTime_Api(){ memset( this ,0 ,sizeof( struct tagTMTTime_Api ) );	}
}*PTMTTime_Api, TMTTime_Api;

/** �ն˵�ǰ����״̬,���к���״̬���ϱ�������� */
typedef struct tagTMtCallLinkSate_Api
{
	EmMtCallingType_Api   emCallingType;                              ///<��������
	EmMtCallState_Api     emCallState;                                ///< ����״̬
	EmConfProtocol_Api    emConfProtocol;                             ///< ����Э��
	BOOL32                bIsCaller;                                  ///< TRUE = ����  FALSE=����
	EmMtCallDisReason_Api emCallDisReason;                            ///< ���йҶ�ԭ��
	u32                   dwCallUpRate;                               ///< �ն��ڲ��������õ���С�Ŀ������е�����
	u32                   dwCallDownRate;                             ///< �ն��ڲ��������õ���С�Ŀ������е�����
	u32                   dwCallRate;                                 ///< ������ UI���õĺ�������, ������ ƽ̨���߶Զ˺��й���������     
	EmMtModel_Api         emPeerModel;                                ///<  �Զ˵��ͺţ�����⳧�̣�ƽ̨�������ݵ��ϵ��ն˲�Ʒ��ΪemModelBegin_Api
	u32                   dwPeerVendor;                               ///< �Զ˳���
	s8                    achPeerProductId[KMTAPI_BUF_32_LEN+1];      ///< �Զ�productid  
	EmEndpointType_Api    emEndpointType;                             ///< �Զ����ͣ�mt,����mcu 
	TNetAddr_Api		  tPeerAddr;   	                              ///< �Զ�IP��ַ(������)
	TMultMtAlias_Api      tPeerAlias;                                 ///< �Զ˱��������Զ��alias, e164
	TMTTime_Api           tConfEstablishedTime;                       ///< ����ɹ�������ʱ�䣬 �Ǹ�����ʱ��
	s8                    achPeerVersionId[KMTAPI_BUF_32_LEN+1];      ///< �Զ�VersionId
	BOOL32                bIsPeerStackAfter5p0;                       ///< �ж϶Զ��Ƿ���5.0
	EmSipConnectType_Api  emSipConnect;                               ///< sip��������
	BOOL32                bPeerSptSubMtlist;                          ///< �Զ��Ƿ�֧�ֶ����ն��б�
public:
	tagTMtCallLinkSate_Api(){ memset( this ,0 ,sizeof( struct tagTMtCallLinkSate_Api ) );	}
}*PTMtCallLinkSate_Api, TMtCallLinkSate_Api;

/** ������еĺ��в��� */
typedef struct tagTMtMissCallParam_Api
{
	u32                   dwCallRate;       ///< ��������
	TNetAddr_Api		  tPeerAddr;   ///< �Զ�IP��ַ(������)
	TMultMtAlias_Api      tPeerAlias; ///< �Զ˱��������Զ��alias, e164
public:
	tagTMtMissCallParam_Api(){ memset( this ,0 ,sizeof( struct tagTMtMissCallParam_Api ) );	}
}TMtMissCallParam_Api;

/** ͨ����Ϣ */
typedef struct tagTMtLoc_Api
{
	EmMtMediaDirection_Api      emDirect;                                   ///< ͨ������
	EmMtMediaType_Api           emMediatype;                              ///< ý������
	EmCodecComponentIndex_Api   emStream_id;                        ///< ͨ��id ��0��ʼ  
	s8                          achStream_Alias[KMTAPI_BUF_32_LEN+1] ; ///< ͨ������
public:
	tagTMtLoc_Api(){ memset( this ,0 ,sizeof( struct tagTMtLoc_Api ) );	}
}*PTMtLoc_Api, TMtLoc_Api;


/** ֻ���ڼ���gk����ȡ��ϵ���б��õ� */
typedef struct tagTMtDetialInfo_Api
{
	s8            achAlias[KMTAPI_MAX_MT_ALIAS_LEN+1]; ///< ������Ϣ
	s8            achE164[KMTAPI_MAX_MT_ALIAS_LEN+1]; ///< e164��Ϣ
public:
	tagTMtDetialInfo_Api(){ memset( this ,0 ,sizeof( struct tagTMtDetialInfo_Api ) );	}
}TMtDetialInfo_Api;

/** ��ϵ����Ϣ�б� */
typedef struct tagTMtDetialInfoList_Api
{
	TMtDetialInfo_Api atDetialMtInfo[KMTAPI_COUNT_512]; ///< �б���Ϣ
	s32 nCount;                                                                     ///< �б����
public:
	tagTMtDetialInfoList_Api(){ memset( this ,0 ,sizeof( struct tagTMtDetialInfoList_Api ) );	}
}TMtDetialInfoList_Api;


/** �ն���Ϣ�ṹ */
typedef struct tagTMTEntityInfo_Api
{
	TNetAddr_Api     tMtAddr;            ///< IP��ַ
	EmMtModel_Api    emModel;            ///< �ͺţ���ʱ�ײ�û��ʵ������ֶ� 
	TMultMtAlias_Api tMtAlias;	         ///< ���������Զ��alias, e164
	EmMtType_Api     emMtType;           ///< ����ն˵�����
	BOOL32           bAudOnly;		     ///< ����ն��Ƿ�ΪΪֻ������Ƶ���� 0-��ֻ������Ƶ(��Ƶ����Ƶ)��1-ֻ������Ƶ
	u32              dwMcuId;            ///< mcu ID
	u32              dwTerId;            ///< mt ID
	TMtLoc_Api atLoc[KMTAPI_MAX_CONF_VID_CHANNEL_NUM];  ///< ͨ�����,���ڶ���,һ·���������Ǵ��ֶ�, ��ʱ�ն�ֻ������ͨ��
	u8 byLocCount;                                                                         ///< ͨ������
public:
	tagTMTEntityInfo_Api(){ memset( this ,0 ,sizeof( struct tagTMTEntityInfo_Api ) );	}
}*PTMTEntityInfo_Api, TMTEntityInfo_Api;

/** �ն���Ϣ�б� */
typedef struct tagTMTEntityInfoList_Api
{
	TMTEntityInfo_Api atMtEntitiy[KMTAPI_MAX_CONF_MT_MEMBER_NUM]; ///< �б���Ϣ
	u32               dwCount;                                                                             ///< �б����
public:
	tagTMTEntityInfoList_Api(){ memset( this ,0 ,sizeof( struct tagTMTEntityInfoList_Api ) );	}
}TMTEntityInfoList_Api;

/** ����you are seeing�� ÿһ·��������ͨ����Ӧ����ƵԴ */
typedef struct tagTMTChanVidSrc_Api 
{
	EmCodecComponentIndex_Api  emChanIdx; ///< �������������һ·
	TMtId_Api                  tMtid;                          ///< �ն˱��
public:
	tagTMTChanVidSrc_Api(){ memset( this ,0 ,sizeof( struct tagTMTChanVidSrc_Api ) );	}
}*PTMTChanVidSrc_Api, TMTChanVidSrc_Api;

/** ����you are seeing�� ÿһ·��������ͨ����Ӧ����ƵԴ�б� */
typedef struct tagTMTChanVidSrcList_Api 
{
	TMTChanVidSrc_Api atList[KMTAPI_MAX_CONF_VID_CHANNEL_NUM]; ///< �б���Ϣ
	u8  byCount;                                                                                         ///< �б����
public:
	tagTMTChanVidSrcList_Api(){ memset( this ,0 ,sizeof( struct tagTMTChanVidSrcList_Api ) );	}
}*PTMTChanVidSrcList_Api, TMTChanVidSrcList_Api;


/** NTP��ʱ��������Ϣ */
typedef struct tagTMTNTPInfo_Api
{
	BOOL32 bUsedNtp;										                             ///< �Ƿ�ʹ��NTP������ true:���� false�����ã�
	s8     achDomainName[KMTAPI_MAX_DOMAIN_NAME_LEN+1]; ///< ���� OR IP  used_ntpΪtrue��Ч
	u32	   dwInterval;										                                  ///< ˢ�¼�� ms 
	u32 dwPort;                                                                                ///< �˿�
public:
	tagTMTNTPInfo_Api(){ memset( this, 0, sizeof( struct tagTMTNTPInfo_Api)); }
}*PTMTNTPInfo_Api, TMTNTPInfo_Api;

/** ���������Ϣ */
typedef struct tagTMtNewConfBaseInfo_Api
{
	s8  achConfName[KMTAPI_MAX_MT_ALIAS_LEN+1];               ///< ��������
	s8  achConfE164[KMTAPI_MAX_MT_E164_LEN+1];                ///< �������
	s8  achDomainGuid[KMTAPI_MAX_DEVICE_GUID_LEN+1];		  ///< guid
	s8  achDomainName[KMTAPI_MAX_DOMAIN_NAME_LEN+1];          ///< ����
	s8  achDomainMoId[KMTAPI_MAX_DOMAIN_MOID_LEN+1];          ///< ���MOID
public:
	tagTMtNewConfBaseInfo_Api(){ memset( this ,0 ,sizeof( struct tagTMtNewConfBaseInfo_Api ) );	}
}*PTMtNewConfBaseInfo_Api, TMtNewConfBaseInfo_Api;

/** ������ϸ��Ϣ */
typedef struct tagTMtConfDetailInfo_Api
{
	TMtNewConfBaseInfo_Api  tConfBaseInfo;	                                 ///< ������Ϣ
	u32   dwConfStyle;					                                     ///< 1-�ٿ��л��飬2-���л���, 3-ԤԼ����, 4-ģ��	
	s8    achShortNo[KMTAPI_MAX_MT_E164_LEN+1];                              ///< �̺�	
	EmEncryptArithmetic_Api   emEncryptMode;	                             ///< �������ģʽ: 0-������, 1-des����,2-aes����
	u32   dwBitrate;						                                 ///< ��������(��λ:Kbps,1K=1024)
	EmMtClarity_Api emConfResultion;                                         ///< ����ģʽ, ���壬���壬�Զ����
	EmMtResolution_Api   emVidResolution;	                                 ///< �ֱ��� VIDEO_FORMAT_AUTO, ...
	EmMtOpenMode_Api     emOpenMode;                                         ///< ����ģʽ
	BOOL32 bIsDiscussConf;					                                 ///< �Ƿ����ۻ���: 0-�������ۻ���(�ݽ�����) 1-���ۻ���	
	TMTTime_Api  tStartTime;					                             ///< ��ʼʱ��
	u32   dwDuration;						                                 ///< ����ʱ��(����)	
	s8    achMasterMtAlias[KMTAPI_MAX_MT_ALIAS_LEN+1];                       ///< �����˱����ַ���
	EmMtDualMode_Api   emAssStreamMode;		                                 ///< �����˫������ʽ: 0-������ 1-�����ն�
	BOOL32  bIsSatdcastMode;                                                 ///< �Ƿ����ǻ���
	BOOL32  bIsPublicConf;                                                   ///< �Ƿ񿪷Ż���������
	BOOL32  bPortMode;                                                       ///< �Ƿ��Ƕ˿ڻ���
	BOOL32  bConfNoDisturb;                                                  ///< �Ƿ������
	BOOL32  bNeedPwd;                                                        ///< �Ƿ��������
	u32		dwMeetingScale;													 ///< �����ģ,0���գ�1��4����Ƶ����,2��8����Ƶ����,3��������Ƶ����

public:
	tagTMtConfDetailInfo_Api(){ memset( this ,0 ,sizeof( struct tagTMtConfDetailInfo_Api ) );	}
}*PTMtConfDetailInfo_Api, TMtConfDetailInfo_Api;

/** �Զ�������Ϣ */
typedef struct tagTPeerCapabilityInfo_Api
{
	BOOL32 bMix;                  ///< ����
	BOOL32 bVAC;                 ///< ��������
	BOOL32 bCustomVMP;     ///< ���ƻ���ϳ�
	BOOL32 bAutoVMP;          ///< �Զ�����ϳ�
	BOOL32 bEndConf;            ///< ��������
	BOOL32 bInvateMt;            ///< �����ն�
	BOOL32 bDropMt;              ///< ɾ���ն�
	BOOL32 bSelSpeaker;         ///< ָ��/ȡ��������
	BOOL32 bSelChair;             ///< ָ��/������ϯ
	BOOL32 bSelSource;           ///< ѡ���ն�
	BOOL32 bFECC;                  ///< Զ������ͷң��
	BOOL32 bQuiet;                  ///< Զ�˾���
	BOOL32 bMute;                  ///< Զ������
	BOOL32 bConfReq;             ///< �������봦��
	BOOL32 bOnlineList;           ///< �����ն��б�
	BOOL32 bOfflineList;           ///< �����ն��б�
	BOOL32 bPicSwitch;            ///< �����л�
	BOOL32 bSelSpeakingUser; ///< ���� 
	BOOL32 bForceBroadcast;   ///< ǿ�ƹ㲥
public:
	tagTPeerCapabilityInfo_Api(){memset(this ,0 ,sizeof( struct tagTPeerCapabilityInfo_Api)); }
}*PTPeerCapabilityInfo_Api,TPeerCapabilityInfo_Api;

/** ����ϳɲ��� */
typedef struct tagTMtVmpItem_Api
{
	u32                         dwVmpItem_Idx;               ///< �ڻ���ϳ��е�λ��, ��Ҫ�������������±�  
	EmMtVMPMmbType_Api          emMmbType;  ///< ���type��emVMPMmbMCSspec_Api, ƽ̨�����tMtid�ֶ�;���type����emVMPMmbMCSspec_Api�� ƽ̨������tMtid�ֶ�
	TMtId_Api                   tMtid;                            ///< ����ϳɳ�Ա
	EmCodecComponentIndex_Api   emStream_id; ///< ͨ��id ��0��ʼ, ���ڶ����У�û�ж������Ժ���
public:
	tagTMtVmpItem_Api()
	{ 
		memset ( this ,0 ,sizeof( struct tagTMtVmpItem_Api) );
		emMmbType = emVMPMmbMCSspec_Api; 
	}
}*PTMtVmpItem_Api, TMtVmpItem_Api;

/** ��������ϳɲ��� */
typedef struct tagTMtCustomVmpParam_Api
{
	EmMtVmpMode_Api emVmpMode;                                                  ///< vmp��ʽ�� �Զ�����������ʽ
	EmMtVmpStyle_Api emStyle;                                                             ///< ����ϳɷ��
	TMtVmpItem_Api  atVmpItem[KMTAPI_MAX_VMP_MEMBER_NUM]; ///< ����ϳɳ�Ա
	u32  dwCount;                                                                                  ///< �ϳɳ�Ա�������
public:
	tagTMtCustomVmpParam_Api(){ memset ( this ,0 ,sizeof( struct tagTMtCustomVmpParam_Api) );}
}*PTMtCustomVmpParam_Api,TMtCustomVmpParam_Api ;

/** ���黭��ϳɲ��� */
typedef struct tagTMtVmpParam_Api
{
	EmMtVmpMode_Api emVmpMode; ///< vmp��ʽ�� �Զ�����������ʽ:���emVmpMode��emMt_VMP_MODE_AUTO_Api,emStyle Ҳ���Զ� emMt_VMP_STYLE_DYNAMIC;��� emVmpMode ��emMt_VMP_MODE_CTRL_Api��emStyle ѡ����ϳɷ��
	EmMtVmpStyle_Api emStyle;            ///< ����ϳɷ��	     
	BOOL32     bIsBroadcast;                  ///< �Ƿ�㲥
	BOOL32     bAddMmbAlias;              ///< �ϳ�ͼ���Ƿ���Ӻϳɳ�Ա����
	TMtVmpItem_Api  atVmpItem[KMTAPI_MAX_VMP_MEMBER_NUM]; ///< ����ϳɳ�Ա
	u32  dwCount;                                                                                  ///< �������
public:
	tagTMtVmpParam_Api()
	{ 
		memset ( this ,0 ,sizeof( struct tagTMtVmpParam_Api) );
		emVmpMode = emMt_VMP_MODE_AUTO_Api;
		emStyle = emMt_VMP_STYLE_DYNAMIC_Api;
	}
}*PTMtVmpParam_Api,TMtVmpParam_Api ;

/** ��ѯ��Ϣ */
typedef struct tagTMtPollInfo_Api
{
	EmMtMediaType_Api emMode; ///< ��ѯģʽ emMediaVide /emMediaAV 
	EmAction_Api      emStat;          ///< emStart/  emStop/  emPause ��ѯ״̬
	u16               wKeepTime;          ///< �ն���ѯ�ı���ʱ�� ��λ:��(s)
	u8			      byMtNum;		         ///< �μ���ѯ���ն˸���
	TMtId_Api	      arrTMtId[ KMTAPI_MAX_POLL_NUM ]; ///< �μ���ѯ���ն�
	u8                byPollSchemeId;                                    ///< ��ѯ����id, ����mtcͬ��  
public:
	tagTMtPollInfo_Api(){ memset ( this ,0 ,sizeof( struct tagTMtPollInfo_Api) );}
}*PTMtPollInfo_Api,TMtPollInfo_Api ;

/** ��ѯ���� */
typedef struct tagTMTChrmanPollScheme_Api
{
	s8 achName[KMTAPI_BUF_32_LEN+1]; ///< ��������
	TMtPollInfo_Api tPollInfo;                    ///< ��ѯ��Ϣ
public:
	tagTMTChrmanPollScheme_Api() { memset( this, 0, sizeof( struct tagTMTChrmanPollScheme_Api ));}
}*PTMTChrmanPollScheme_Api, TMTChrmanPollScheme_Api;

/** ��ѯ�����б� */
typedef struct tagTMTChrmanPollSchemeList_Api
{
	TMTChrmanPollScheme_Api atPollInfo[KMTAPI_MAX_POLL_SCHEME]; ///< �б���Ϣ
	u8 byCnt;                                                                                             ///< �б����
public:
	tagTMTChrmanPollSchemeList_Api() { memset( this, 0, sizeof( struct tagTMTChrmanPollSchemeList_Api ));}
}*PTMTChrmanPollSchemeList_Api, TMTChrmanPollSchemeList_Api;

/** �������� */ 
typedef struct tagTMtMixParam_Api
{
	EmMtMixType_Api  emDiscussMode;                                                ///< ������ʽ
	TMtId_Api        arrTMtMember[KMTAPI_MAX_MIX_MEMBER_NUM]; ///< ������Ա
	u8               byCnt;                                                                            ///< ʵ�ʸ���
public:
	tagTMtMixParam_Api(){ memset ( this ,0 ,sizeof( struct tagTMtMixParam_Api ) );}
}*PTMtMixParam_Api, TMtMixParam_Api;

/** ���������Ϣ */
typedef struct tagTMtConfInfo_Api
{
	TMTTime_Api        tStartTime;                                                     ///< ��ʼʱ�䣬����̨��0Ϊ������ʼ
	u16                wDuration;                                                            ///< ����ʱ��(����)��0��ʾ���Զ�ֹͣ
	u16                wBitRate;                                                               ///< ��������(��λ:Kbps,1K=1024)
	u16                wSecBitRate;                                                          ///< ˫�ٻ���ĵ�2����(��λ:Kbps,Ϊ0��ʾ�ǵ��ٻ���)
	EmMtResolution_Api emPriVideoResolution;                                ///< ����Ƶ��ʽ
	EmMtResolution_Api emAssVideoResolution;                                ///< ����Ƶ��ʽ
	u16                dwTalkHoldTime;                                                    ///< ��С���Գ���ʱ��(��λ:��)
	s8                 achConfPwd[KMTAPI_MAXLEN_PASSWORD+1];       ///< ��������
	s8                 achConfName[KMTAPI_MAX_CONF_NAME_LEN+1]; ///< ������
	s8                 achConfE164[KMTAPI_MAX_CONF_E164_LEN+1];      ///< �����E164����	
	TMtId_Api 	       tChairman;	                                                         ///< ��ϯ�նˣ�MCU��Ϊ0��ʾ����ϯ
	TMtId_Api	       tSpeaker;		                                                         ///< �����նˣ�MCU��Ϊ0��ʾ�޷�����
	TMtVmpParam_Api    tVmpParam;                                                ///< ��ǰ��Ƶ���ϲ���������Ƶ����ʱ��Ч
	TMtMixParam_Api    tMixParam;                                                   ///< ��������
	BOOL32             bIsSatdcastMode;                                                ///< �Ƿ�֧�����Ƿ�ɢ���飺0-��֧�֣�1-֧��
	EmMtOpenMode_Api   emOpenMode;                                         ///< ���鿪�ŷ�ʽ
	BOOL32             bOccupy_Vpu;                                                     ///< �Ƿ�ռ��ͼ������������ϳɺ����䣩����
	EmMtDualMode_Api   emDual_mode;                                           ///< ˫��ģʽ
	BOOL32             bAllInitDumb;                                                      ///< �ն������Ƿ��ʼ���� 0-������ 1-����
	BOOL32             bConfNoDisTurb;                                                ///< �����Ƿ��� �����ģʽ
	BOOL32             bPortMode;                                                        ///< �Ƿ��Ƕ˿�ģʽ����
	BOOL32             bForceBroadcast;                                                 ///<  �Ƿ���ǿ�ƹ㲥
	EmRecordState_Api  emRecord_mode;                                      ///< ¼��ģʽ��0-��¼�� 1-¼�� 2-¼����ͣ
public:
	tagTMtConfInfo_Api(){ memset ( this ,0 ,sizeof( struct tagTMtConfInfo_Api) );}
}*PTMtConfInfo_Api,TMtConfInfo_Api ;



/** ��confinfo */
typedef struct tagTMtSimpConfInfo_Api
{
	TMtId_Api  tSpeaker;                           ///< ������id
	TMtId_Api  tChairman;                         ///< ��ϯid
	EmMtMixType_Api   emDiscuss_mode ; ///< ������ʽ
	EmMtVmpMode_Api   emVmp_mode;  ///< vmp��ʽ�� �Զ�����������ʽ
public:
	tagTMtSimpConfInfo_Api(){ memset ( this ,0 ,sizeof( struct tagTMtSimpConfInfo_Api) );}
}*PTMtSimpConfInfo_Api, TMtSimpConfInfo_Api;


/** ���������Ϣ�� ����ƽ̨�������Ѿ������õĻ�����Ϣ */
typedef struct tagTMtConfNameInfo_Api  
{
	s8                 achConfName[KMTAPI_MAX_CONF_NAME_LEN+1]; ///< ������
	s8                 achConfE164[KMTAPI_MAX_CONF_E164_LEN+1];      ///< �����E164����
	u32			       dwMtNum;		                                                     ///< ����ն���
	u32			       dwRemainTime;			                                             ///< ����ʣ��ʱ��
	EmMtOpenMode_Api   emOpenMode;						                     ///< ���ŷ�ʽ
	EmMtClarity_Api    emConfClarity;			 		                                 ///< ����ģʽ
	TMTTime_Api	       tConfStartTime;	  						                     ///< ���鿪ʼʱ��
	BOOL32             bIsSatdcaseMode;                                                ///< �Ƿ�֧�����Ƿ�ɢ���飺0-��֧�֣�1-֧��
	BOOL32             bIsPublicConf;                                                      ///< �Ƿ�Ϊ���Ż��飺0-���ǣ�1-��
	BOOL32             bNeedPwd;                                                           ///<�Ƿ�Ϊ������飺0-���ǣ�1-��
public:
	tagTMtConfNameInfo_Api(){ memset ( this ,0 ,sizeof( struct tagTMtConfNameInfo_Api ) );}
}*PTMtConfNameInfo_Api,TMtConfNameInfo_Api;

/** �Ѵ����õĻ�����Ϣ�б� */
typedef struct tagTMtConfNameInfoList_Api 
{
	TMtConfNameInfo_Api arrConfNameInfo[KMTAPI_MAX_CONFLIST_NUM]; ///< �б���Ϣ
	u32 dwCount;                                                                                             ///< �б����
public:
	tagTMtConfNameInfoList_Api(){ memset ( this ,0 ,sizeof( struct tagTMtConfNameInfoList_Api ) );}
}TMtConfNameInfoList_Api;

/** ����Ϣ */
typedef struct tagTShortMsg_Api
{
	EmSMSType_Api         emType;                                            ///< ��Ϣ����
	TMtId_Api             tSrcMtId;                                                ///< ������Ϣ���ն�
	u8                    byDstNum;                                                  ///< ������Ϣ���ն˸���
	TMtId_Api             arrMtDst[KMTAPI_MAX_SMSDST_NUM]; ///< ������Ϣ���ն��б�
	EmRollMsgSpeed_Api    emSpeed;                                       ///< �ٶ� (1-5)
	u8                    byRollTimes;                                                ///< ��������
	s8                    achText[KMTAPI_MAX_SMSTEXT_LEN+1];    ///< ��Ϣ�ı�
public:
	tagTShortMsg_Api(){ memset ( this ,0 ,sizeof( struct tagTShortMsg_Api) );}
}*PTShortMsg_Api,TShortMsg_Api;

/** RTPRTCP����Ϣ*/ 
typedef struct tagTRtpRtcpPair_Api
{
	TNetAddr_Api tRtpAddr;   ///< RTP��ַ
	TNetAddr_Api tRtcpAddr; ///< RTCP��ַ
public:
	tagTRtpRtcpPair_Api(){ memset ( this ,0 ,sizeof( struct tagTRtpRtcpPair_Api) );}
}*PTRtpRtcpPair_Api, TRtpRtcpPair_Api;

/** ��Կ */
typedef struct tagTEncryptKey_Api
{
	u8 byLen;                                                           ///< ��Կ����
	u8 abyKey[KMTAPI_MAX_ENCRYPTKEY_LEN+1]; ///< ��Կ
public:
	tagTEncryptKey_Api(){ memset( this ,0 ,sizeof( struct  tagTEncryptKey_Api ) );}	
}*PTEncryptKey_Api,TEncryptKey_Api;

/** ��̬�غ� */
typedef struct tagTMTDynamicPayload_Api
{
	u32 dwKeyRmtActivePT; //Զ���������غ�ֵ
	u32 dwKeyRealPT;      //����ʵ���غ�ֵ
public:
	tagTMTDynamicPayload_Api() { memset ( this ,0 ,sizeof( struct tagTMTDynamicPayload_Api ) ); }
}*PTDynamicPayload_Api, TDynamicPayload_Api;

/** ����ͼ����� */
typedef struct tagTMTStreamParam_Api
{
	EmCodecComponent_Api emCodecType;       ///< ���ͱ�ʶ
	EmCodecComponentIndex_Api emCodecIdx; ///< id
	u8                byMediaType;                            ///< ý������
	u8                byPlayLoad;                               ///< ��̬�غ�
	TEncryptKey_Api   tEncryptKey;                      ///< ��Կ
	BOOL32            bIsg7221Reverse;                  ///< g7221�Ƿ�ת
	EmAacChnlNum_Api  emAacChanNum;        ///< aac������  
	EmAacSampFreq_Api emAacSampFreq;        ///< aac������
	u8                  byPayloadCnt;                //ý�����
	TDynamicPayload_Api atPayload[KMTAPI_COUNT_8];	 //ý������
	u32					dwLocRtpPort;
	u32					dwLocRtcpPort;
public:
	tagTMTStreamParam_Api(){ memset ( this ,0 ,sizeof( struct tagTMTStreamParam_Api ) );}
}*PTMTStreamParam_Api,TMTStreamParam_Api;

/** ��ƵԴ��Ϣ(��Embed) */
typedef struct tagTMTVidSrcItem_Api
{
	EmCodecComponentIndex_Api    emCodecIdx; ///< ��������ʶ
	EmVidPort_Api                emVidPort;                 ///< ��ƵԴ�˿�
	BOOL32                       bSignal;                         ///< �Ƿ����ź�
public:
	tagTMTVidSrcItem_Api(){ memset ( this ,0 ,sizeof( struct tagTMTVidSrcItem_Api ) );}
}*PTMTVidSrcItem_Api,TMTVidSrcItem_Api;


/** ������Ϣ */
typedef struct tagTStreamInfo_Api
{
	u32 dwStreamId;                                                ///< ������ʶ
	EmMtChanType_Api emStreamType;                  ///< ��������
	EmCodecComponentIndex_Api emBitStreamIdx; ///< ��Ӧ�ն˵ڼ�·����
	u32 dwBandWidth;                                             ///< kilobits-per-second,
	s32 nSpeedScale;                                                ///< ���� ������һ�����ʡ���������
	u32 dwStartTime;                                               ///< ��ʼʱ�䣬��λms
	u32 dwEndTime;                                                ///< ����ʱ�䣬��λms
	u32 dwCurTime;                                                ///< ��ǰʱ�䣬��λms
	u32 dwMediaType;                                            ///< ý�����ͣ��磺MEDIA_TYPE_H264��MEDIA_TYPE_G7221�ȣ�
	u32 dwVideoWidth;                                           ///< ��Ƶ��ֻ����Ƶʹ�ã�
	u32 dwVideoHeight;                                          ///< ��Ƶ����ֻ����Ƶʹ�ã�
	u32 dwVideoFps;                                               ///< ֡�ʣ�ֻ����Ƶʹ�ã�
	EmRtspStatus_Api emStatus;                              ///< ״̬
	BOOL32 bIsLiveBroadcast;                                  ///< �Ƿ�Ϊֱ��
public:
	tagTStreamInfo_Api(){ memset ( this ,0 ,sizeof( struct tagTStreamInfo_Api ) );}
}*PTStreamInfo_Api, TStreamInfo_Api;

/** vod��������¼��Ϣ */
typedef struct tagTVodLoginInfo_Api
{
	u32 dwIp;                                                   ///< IP��ַ(���)
	s8 achUserName[KMTAPI_BUF_64_LEN+1]; ///< �û���
	s8 achPassword[KMTAPI_BUF_64_LEN+1];   ///< ����
public:
	tagTVodLoginInfo_Api(){ memset ( this ,0 ,sizeof( struct tagTVodLoginInfo_Api ) );}
}*PTVodLoginInfo_Api, TVodLoginInfo_Api;

/** �ļ�����Ϣ */ 
typedef struct tagTVodFolderInfo_Api
{
	u32 dwFolderId;				                              ///< �ļ���ID
	s8 achFolderName[KMTAPI_BUF_128_LEN+1]; ///< �ļ�������
	u32	dwPrgCount;				                          ///< �ļ�����
public:
	tagTVodFolderInfo_Api(){ memset ( this ,0 ,sizeof( struct tagTVodFolderInfo_Api ) );}
}*PTVodFolderInfo_Api, TVodFolderInfo_Api;

/** �ļ�����Ϣ�б� */ 
typedef struct tagTVodFoldersInfo_Api
{
	TVodFolderInfo_Api atFolderInfo[KMTAPI_MAX_VODFILE_CNT]; ///< �б���Ϣ
	u32 dwCnt;                                                                                ///< �б����
public:
	tagTVodFoldersInfo_Api(){ memset ( this ,0 ,sizeof( struct tagTVodFoldersInfo_Api ) );}
}*PTVodFoldersInfo_Api,TVodFoldersInfo_Api;

/** vrsĳһ�ļ����µĽ�Ŀ�б�������Ϣ */ 
typedef struct tagTVodGetPrgsReq_Api
{
	u32	dwFolderId;		                       ///< �ļ���ID
	u32	dwPrgsPage;		                       ///< ÿ��ҳ����ʾ������Ŀ
	u32	dwPageId;			                   ///< ���������һҳ
	s8  achIncludeName[KMTAPI_BUF_128_LEN+1];  ///< �����ļ���
	u32 dwPrgTypeMask;                         ///< ����ĳ�ָ�ʽ���ļ�,0 ����,1��asf,2��MP4
	u32 dwStartTime;                           ///< ��ʼʱ��  ʱ���
	u32 dwEndTime;                             ///< ��ֹʱ��  ʱ���
public:
	tagTVodGetPrgsReq_Api(){ memset ( this ,0 ,sizeof( struct tagTVodGetPrgsReq_Api ) );}
}*PTVodGetPrgsReq_Api, TVodGetPrgsReq_Api;

/** vrsĳһ�ļ����²�ѯ¼���ļ���Ϣ */   //�ýṹ���ظ�,Ŀǰ����
typedef struct tagTVodSearchFilesReq_Api
{
	u32	dwFolderId;		                       ///< �ļ���ID
	u32	dwPrgsPage;		                       ///< ÿ��ҳ����ʾ������Ŀ
	u32	dwPageId;			                   ///< ���������һҳ
	s8  achIncludeName[KMTAPI_BUF_128_LEN+1];  ///< �����ļ���
public:
	tagTVodSearchFilesReq_Api(){ memset ( this ,0 ,sizeof( struct tagTVodSearchFilesReq_Api ) );}
}*PTVodSearchFilesReq_Api, TVodSearchFilesReq_Api;

/** ��Ŀ��ϸ��Ϣ */ 
typedef struct tagTVodPrgDetailInfo_Api
{
	u32 dwIp;				                                     ///< IP
	u32	dwPrgDuration;	                             ///< ��Ŀʱ�����룩
	u32	dwPrgIndex;		                                 ///< ��Ŀ����
	u32	dwPrgId;			                                 ///< ��ĿID
	s8 achPrgName[KMTAPI_BUF_128_LEN+1]; ///< ��Ŀ�ļ���
	u32	dwPrgSize;		                                  ///< ��Ŀ��С��BYTE��
	s8	achPrgType[KMTAPI_BUF_128_LEN+1];   ///< ��Ŀ�ļ���׺
	s8	achPath[KMTAPI_BUF_128_LEN+1];  	      ///< ��ŵ����·��
	u32 dwPrgsInfoIndex;                                 ///< ����������Ŀ��Ϣ���б��е�����
public:
	tagTVodPrgDetailInfo_Api() { memset( this, 0, sizeof( struct tagTVodPrgDetailInfo_Api ) ); }
}*PTVodPrgDetailInfo_Api, TVodPrgDetailInfo_Api;

/** ��Ŀ��ϸ��Ϣ�б� */
typedef struct tagTVodPrgsDetailInfo_Api
{
	TVodPrgDetailInfo_Api atPrgDetail[KMTAPI_MAX_VODDETAIL_CNT]; ///< ��Ŀ������Ϣ�б�
	u32 dwCnt;                                                                                       ///< ��Ŀ������Ϣ����
public:
	tagTVodPrgsDetailInfo_Api(){ memset ( this ,0 ,sizeof( struct tagTVodPrgsDetailInfo_Api ) );}
}*PTVodPrgsDetailInfo_Api, TVodPrgsDetailInfo_Api;

/** ��Ŀ������Ϣ */
typedef struct tagTVodPrgBaseInfo_Api
{
	u32 dwCreateTime;		                           ///< ��Ŀ����ʱ��
	u32 dwIssueTime;		                               ///< ��Ŀ����ʱ��
	s8	achPrgAlias[KMTAPI_BUF_128_LEN+1]; ///< ��Ŀ��ʾ����
	u32	dwPrgAllDuration;	                            ///< ��Ŀ��ʱ�����룩
	u32	dwPrgAllSize;		                            ///< ��Ŀ�ܴ�С
	s8	achPrgDesc[KMTAPI_BUF_512_LEN+1]; ///< ��Ŀ����
	u32	dwPrgId;                        			        ///< ��ĿID
	u32	dwPrgState;                         		        ///< ��Ŀ״̬
	s8  achStreamJsonPath[KMTAPI_BUF_128_LEN+1];             //< ��ĿԴ�����ļ�
public:
	tagTVodPrgBaseInfo_Api(){ memset ( this ,0 ,sizeof( struct tagTVodPrgBaseInfo_Api ) );}
}*PTVodPrgBaseInfo_Api, TVodPrgBaseInfo_Api;

/** ��Ŀ������Ϣ�б� */
typedef struct tagTVodPrgsBaseInfo_Api
{
	TVodPrgBaseInfo_Api atPrgBase[KMTAPI_MAX_VODPRG_CNT]; ///< �б���Ϣ
	u32 dwCnt;                                                                               ///< �б����
public:
	tagTVodPrgsBaseInfo_Api(){ memset ( this ,0 ,sizeof( struct tagTVodPrgsBaseInfo_Api ) );}
}*PTVodPrgsBaseInfo_Api, TVodPrgsBaseInfo_Api;

/** ֱ������Ϣ */ 
typedef struct tagTVodRoomState_Api
{
	u32	dwElapse;			                                      ///< ��Ŀ�Ѳ��ŵ�ʱ��
	s8 achLCastPoint[KMTAPI_BUF_128_LEN+1];   ///< ֱ����ַ
	u32	dwPrgId;			                                      ///< ��ĿID
	u32	dwRoomId;			                                  ///< ֱ����ID
	s8	achRoomName[KMTAPI_BUF_128_LEN+1]; ///< ֱ��������
	u32	dwUsrGrpId;		                                      ///< ֱ���������û���
	u32 dwLiveTime;                             // ��ʼ����ʱ��
	s8  achLiveStreamPath[KMTAPI_BUF_128_LEN+1];             // ֱ��Դ�����ļ�
	s8  achRoomIdStr[KMTAPI_BUF_128_LEN+1];   ///< ֱ����ID,�Ժ����ַ�����ʶ
public:
	tagTVodRoomState_Api(){ memset ( this ,0 ,sizeof( struct tagTVodRoomState_Api ) );}
}*PTVodRoomState_Api, TVodRoomState_Api;

/** ֱ���б���Ϣ */ 
typedef struct tagTVodRoomsState_Api
{
	TVodRoomState_Api atRoomstate[KMTAPI_MAX_DIRECTBROADCAST_CNT]; ///< �б���Ϣ
	u32 dwCnt;                                                                                                   ///< �б����
public:
	tagTVodRoomsState_Api(){ memset ( this ,0 ,sizeof( struct tagTVodRoomsState_Api ) );}
}*PTVodRoomsState_Api, TVodRoomsState_Api;

/** ԤԼֱ������Ϣ */ 
typedef struct tagTVodRoomCfg_Api
{
	u32	dwIp;				                                  ///< ������IP(���)
	s8 achPath[KMTAPI_BUF_128_LEN+1];		  ///< �ļ�·��
	s8 achPrgAlias[KMTAPI_BUF_128_LEN+1];   ///< ��Ŀ��ʾ����
	u32 dwPrgId;			                                  ///< ��ĿID
	s8 achPrgName[KMTAPI_BUF_128_LEN+1]; ///< ��Ŀ����
	u32 dwResTime;		                                  ///< ԤԼ����ʱ��
	u32	dwRoomId;			                              ///< ԤԼֱ���ҵ�ID
	u32 dwUsrGrpId;		                                  ///< ԤԼֱ���������û���ID
public:
	tagTVodRoomCfg_Api(){ memset ( this ,0 ,sizeof( struct tagTVodRoomCfg_Api ) );}
}*PTVodRoomCfg_Api, TVodRoomCfg_Api;

/** ԤԼֱ������Ϣ�б� */ 
typedef struct tagTVodRoomsCfg_Api
{
	TVodRoomCfg_Api atRoomcfg[KMTAPI_MAX_DIRECTBROADCAST_CNT]; ///< �б���Ϣ
	u32 dwCnt;                                                                                              ///< �б����
public:
	tagTVodRoomsCfg_Api()
	{
		dwCnt = 0;
	}
}*PTVodRoomsCfg_Api, TVodRoomsCfg_Api;

/** ��VOD������Ϣ */
typedef struct tagTVodPlayInfo_Api
{
	s8               achPlayUrl[KMTAPI_BUF_256_LEN+1];                                                 ///< �㲥��ַ
	u32              dwVodId;                                                                                          ///< �㲥��ַ��ʶ
	TStreamInfo_Api  arrTStreamInfo[KMTAPI_MAX_VOD_STREAM_CHANNEL_NUM]; ///< ����״̬
	u8               byCnt;                                                                                                ///< ����·��
	EmRtspStatus_Api emStatus;                                                                                 ///< ״̬
	BOOL32           bIsLiveBroadcast;                                                                           ///< �Ƿ�Ϊֱ��
public:
	tagTVodPlayInfo_Api(){ memset ( this ,0 ,sizeof( struct tagTVodPlayInfo_Api ) );}
}*PTVodPlayInfo_Api,TVodPlayInfo_Api;

/** ��VOD������Ϣ */
typedef struct tagTMultiVodPlayInfo_Api
{
	TVodPlayInfo_Api arrTVodInfo[KMTAPI_MAX_VOD_STREAM_NUM]; ///< VOD��Ϣ
	u8 byCnt;                                                                                         ///< ʵ��·��
public:
	tagTMultiVodPlayInfo_Api(){ memset ( this ,0 ,sizeof( struct tagTMultiVodPlayInfo_Api ) );}
}*PTMultiVodPlayInfo_Api,TMultiVodPlayInfo_Api;

/** ��Ƶ�㲥Դ��Ϣ */
typedef struct tagTMTVodStream_Api
{
	u32         dwVodId;      ///< vodid
	u32         dwStreamId; ///< vodid�µ�streamid
public:
	tagTMTVodStream_Api(){ memset ( this ,0 ,sizeof( struct tagTMTVodStream_Api ) );}
}*PTMTVodStream_Api,TMTVodStream_Api;

/** ��Ƶ�㲥Դ����Ϣ */
typedef struct tagTMTVodStreamInfo_Api
{
	u32         dwVodId;                 ///< vodid
	TStreamInfo_Api tStreamInfo; ///< stream��Ϣ
public:
	tagTMTVodStreamInfo_Api(){ memset ( this ,0 ,sizeof( struct tagTMTVodStreamInfo_Api ) );}
}*PTMTVodStreamInfo_Api,TMTVodStreamInfo_Api;

/** ̨��λ������ */
typedef struct tagTMTSymboPoint_Api
{
	u16 X; ///< X����
	u16 Y; ///< Y����
public:
	tagTMTSymboPoint_Api(){ memset( this ,0 ,sizeof( struct  tagTMTSymboPoint_Api ) );}
}*PTMTSymboPoint_Api,TMTSymboPoint_Api;

/** ��ʾ������Ϣ���ݽṹ���� */
typedef struct tagTMTOsdCfg_Api
{
	BOOL32  bIsAutoPip;                                       ///< �Ƿ������Զ����л�
	BOOL32  bIsShowConfLapse;                           ///< �Ƿ���ʾ����ʱ��
	BOOL32  bIsShowSysTime;                               ///< �Ƿ���ʾϵͳʱ��
	BOOL32  bIsShowState;                                   ///< �Ƿ���ʾ״̬��־
	EmLabelType_Api         emLabelType;               ///< ̨������
	TMTSymboPoint_Api       tLableCoordinate;      ///< �Զ���̨��λ��
	EmLabelPosType_Api      emLabelPosType;        ///< �ն˱���̨��λ��
	EmDualVideoShowMode_Api emDualMode;     ///< ˫����ʾ��ʽ
	EmDisplayRatio_Api      emPrimaryDisplayRatio; ///< ��һ·��ʾ����ģʽ
	EmDisplayRatio_Api      emSecondDisplayRatio; ///< �ڶ�·��ʾ����ģʽ
public:
	tagTMTOsdCfg_Api(){ memset( this ,0 ,sizeof( struct  tagTMTOsdCfg_Api ) );}
}*PTMTOsdCfg_Api, TMTOsdCfg_Api;

/** �ǶԳ�����֧�� */
typedef struct tagTAsymmetricNetInfo_Api
{
	BOOL32   bIsEnable;        ///< �Ƿ����ò��Գ�����
	u32      dwUplinkRate;     ///< �������ʣ���λkbps
	u32      dwDownlinkRate; ///< �������ʣ���λkbps
public:
	tagTAsymmetricNetInfo_Api(){ memset( this ,0 ,sizeof( struct tagTAsymmetricNetInfo_Api ) ); }
}*PTAsymmetricNetInfo_Api,TAsymmetricNetInfo_Api; 

/** mc�����ش����� */
typedef struct tagTMTMcRSParam_Api
{
	u32  dwFirstTimeSpan;      ///< ��һ���ش�����(ms)
	u32  dwSecondTimeSpan; ///< �ڶ����ش�����(ms)
	u32  dwThirdTimeSpan;    ///< �������ش�����(ms)
	u32  dwRejectTimeSpan;  ///< ���ڶ�����ʱ����(ms)
public:
	tagTMTMcRSParam_Api()
	{
		dwFirstTimeSpan  = 40;
		dwSecondTimeSpan = 2000;
		dwThirdTimeSpan  = 0;
		dwRejectTimeSpan = 0;
	}
}*PTMTMcRSParam_Api, TMTMcRSParam_Api;

/** FEC������Ϣ�ṹ */
typedef struct tagTMTFecInfo_Api
{
	BOOL32   bEnableFec;      ///< ��Ƶ�Ƿ�ʹ��ǰ�����
	u8       byAlgorithm;         ///< ����fec�㷨 0:NONE 1:RAID5 2:RAID6
	u16      wPackLen;            ///< ����fec���а�����
	BOOL32   bIntraFrame;     ///< �Ƿ�֡��fec
	u32      dwDataPackNum; ///< ����fec��x�����ݰ�
	u32      dwCrcPackNum;   ///< ����fec��y�������
public:
	tagTMTFecInfo_Api(){ memset( this, 0, sizeof( struct tagTMTFecInfo_Api ) ); }
}*PTMTFecInfo_Api,TMTFecInfo_Api;

/** QoS�������Ͷ�Ӧ�Ĳ��� */
typedef struct tagTMTQosParam_Api
{
	u32 dwSignalling;  ///< ����QOSֵ ��Χ
	u32 dwData;         ///< �����ŵ�����������ͷԶҡ��QOSֵ ��Χ
	u32 dwAudio;       ///< ����QOSֵ ��Χ
	u32 dwVideo;       ///< ��ƵQOSֵ ��Χ
public:
	tagTMTQosParam_Api(){ memset( this, 0, sizeof( struct tagTMTQosParam_Api ) ); }
}*PTMTQosParam_Api, TMTQosParam_Api;

/** QOS��Ϣ���ݽṹ */
typedef struct tagTMTIPQoS_Api
{
	EmQoS_Api       emType;                          ///< QoS��������
	EmTOS_Api       emTos;                             ///< ������֤����
	TMTQosParam_Api tDiffServiceParam;      ///< QOS���ͷ���Ϊ���ַ���ʱ��Ӧ�Ĳ���
	TMTQosParam_Api tIpPrecedenceParam;  ///< QOS���ͷ���ΪIP����ʱ��Ӧ�Ĳ���
public:
	tagTMTIPQoS_Api(){ memset( this ,0 ,sizeof( struct  tagTMTIPQoS_Api ) );}
}*PTMTIPQoS_Api, TMTIPQoS_Api; 

/** �����ش����� */
typedef struct tagTPrsParam_Api
{
	BOOL32 bEnable;                 ///< �Ƿ�����                  
	u32    dwFirstTimeSpan;       ///< ��һ���ش�����(ms)
	u32    dwSecondTimeSpan;  ///< �ڶ����ش�����(ms)
	u32    dwThirdTimeSpan;      ///< �������ش�����(ms)
	u32    dwRejectTimeSpan;     ///< ���ڶ�����ʱ����(ms)
	u32    dwSendBufTimeSpan; ///< ���ͻ���           default 1000
	BOOL32 bUseSmoothSend;  ///< ����ƽ������
public:
	tagTPrsParam_Api()
	{
		bEnable = FALSE;
		dwFirstTimeSpan  = 40;
		dwSecondTimeSpan = 2000;
		dwThirdTimeSpan  = 0;
		dwRejectTimeSpan = 0;
		dwSendBufTimeSpan = 1000;
		bUseSmoothSend = FALSE;
	}
}*PTPrsParam_Api,TPrsParam_Api;


/** ��Ƶ�������������� */
typedef struct tagTMTVideoEncoderParamCfg_Api
{
	EmCodecComponentIndex_Api emCodecIdx; ///< ��Ӧ����������
	u32 dwH265IKeyInterval;                                ///< H265�ؼ�֡���	
	u32 dwH265QualMaxValue;	                          ///< H265�����������
	u32 dwH265QualMinValue;	                          ///< H265��С��������
	u32 dwH264IKeyInterval;                                 ///< H264�ؼ�֡���	
	u32 dwH264QualMaxValue;	                           ///< H264�����������
	u32 dwH264QualMinValue;	                           ///< H264��С��������
	u32 dwKeyFrameInterval;	                               ///< ��H264 H265�ؼ�֡���
	u32 dwQualMinValue;                                     ///< ��H264 H265��С��������
	u32 dwQualMaxValue;		                               ///< ��H264 H265�����������
	u32 dwFrameRate1080p;	                               ///< 1080p�ֱ�����֡��, ��ѡ֡��
	u32 dwFrameRate720p;	                                   ///< 720p�ֱ�����֡��(��Ը����ն�)
    u32 dwFrameRateGT720p;                                ///< VGA��ʽ���ֱ��ʴ���720pʱ��֡��
    u32 dwFrameRateLT720p;                                 ///< VGA��ʽ���ֱ���С��720pʱ��֡��
	u32 dwFrameRate4k;	                               ///< 1080p�ֱ�����֡��, ��ѡ֡��
	BOOL32  bSkip;										///�Ƿ���֡ ����android �ƶ��� ����������
	float   fRatio;									///��֡���� ����android �ƶ��� ����������
public:
	tagTMTVideoEncoderParamCfg_Api(){ memset( this ,0 ,sizeof( struct  tagTMTVideoEncoderParamCfg_Api ) );}
}*PTMTVideoEncoderParamCfg_Api, TMTVideoEncoderParamCfg_Api;

/** ��Ƶ�������������� */
typedef struct tagTMTVideoDecoderParamCfg_Api
{
	EmCodecComponentIndex_Api emCodecIdx;     ///< ��Ӧ����������
	EmLostPackStrategy_Api    emLostPackStrategy; ///< �����������ָ�����
public:
	tagTMTVideoDecoderParamCfg_Api(){ memset( this ,0 ,sizeof( struct  tagTMTVideoDecoderParamCfg_Api ) );}
}*PTMTVideoDecoderParamCfg_Api,TMTVideoDecoderParamCfg_Api;

/** ��Ƶ��ѡ */
typedef struct tagTMTAudioPriorCfg_Api
{
	EmAudFormat_Api   emAudioFormat;         ///< ��Ƶ��ѡ��ʽ
	EmAacChnlNum_Api  emAacChannelNum; ///< AAC��ѡ����
	EmAacSampFreq_Api emAaSampFreq;       ///< AAC��ѡ��������
public:
	tagTMTAudioPriorCfg_Api(){ memset( this ,0 ,sizeof( struct  tagTMTAudioPriorCfg_Api ) );}
}*PTMTAudioPriorCfg_Api, TMTAudioPriorCfg_Api;

/** ��Ƶ��ѡ���� */
typedef struct tagTVidPriorParam_Api
{
	EmVidFormat_Api    emVideoFormat;   ///<��Ƶ��ѡЭ��
	EmMtResolution_Api emVideoRes;      ///<�ֱ�����ѡЭ��
public:
	tagTVidPriorParam_Api(){ memset( this ,0 ,sizeof( struct  tagTVidPriorParam_Api ) );}
}*PTVidPriorParam_Api, TVidPriorParam_Api;

/** ������ѡ���������ܴ��ڶ�·�����������飩 */
typedef struct tagTMTPriVideoPriorCfg_Api
{
	TVidPriorParam_Api atVideoPriorParam[KMTAPI_MAX_MULTI_CHANNEL_NUM];  ///< ���5����Ա
	u8 byCnt;                                                                                                             ///< ��������
public:
	tagTMTPriVideoPriorCfg_Api(){ memset( this ,0 ,sizeof( struct  tagTVidPriorParam_Api ) );}
}*PTMTPriVideoPriorCfg_Api, TMTPriVidPriorCfg_Api;

/** TCP/UDP��ʼ������Ϣ */
typedef struct tagTTcpUdpBasePortCfg_Api
{
	BOOL32     bAuto;          ///< �Ƿ���������˿�
	u16        wTcpBasePort;  ///< tcp��ʼ�˿�
	u16        wUdpBasePort; ///< udp��ʼ�˿�
public:
	tagTTcpUdpBasePortCfg_Api(){ memset( this ,0 ,sizeof( struct  tagTTcpUdpBasePortCfg_Api ) );}
}*PTTcpUdpBasePortCfg_Api,TTcpUdpBasePortCfg_Api;

/** ��������Ϣ������Ϣ */
typedef struct tagTRollMsgCfg_Api
{
	EmFontSize_Api  emSize;     ///< �����С
	EmFontColor_Api emColor; ///< ������ɫ
	EmFontColor_Api emBackGroundColor;///<������ɫ
public:
	tagTRollMsgCfg_Api(){ memset( this ,0 ,sizeof( struct  tagTRollMsgCfg_Api ) );}
}*PTRollMsgCfg_Api,TRollMsgCfg_Api;

/**  ��Ƶ������� */
typedef struct tagTVidEncParam_Api
{
	EmEncodeMode_Api emEncMode;      ///< ͼ��ѹ�����ʿ��Ʋ���
	EmVidFormat_Api  emVidFormat;        ///< ͼ���������
	u32              dwMaxKeyFrameInterval; ///< I֡�����P֡��Ŀ
	u32              dwMaxQuant;                  ///< �����������(1-31)
	u32              dwMinQuant;                  ///< ��С��������(1-31)
	u32              dwFrameRate;                 ///< ֡��(default:25)
	u32              dwBitrate;                       ///< ���������(Kbps)
	u32              dwH264Profile;               ///< ������������ 1:LV_QUALITY_PRIOR,2:LV_SPEED_PRIOR,3:LV_HPSINGLE_PRIOR,4:LV_HPMULTE_PRIOR
	u32              dwWidth;                       ///< ͼ�������
	u32              dwHeight;                      ///< ͼ�����߶�
public:
	tagTVidEncParam_Api(){ memset( this ,0 ,sizeof( struct  tagTVidEncParam_Api ) );}
}*PTVidEncParam_Api, TVidEncParam_Api;

////��ʱ����ipc
typedef struct tagTMTStreamChanParam_Api
{
	TVidEncParam_Api  tEncParam;   ///< ͨ���ı����ʽ
	TNetAddr_Api      tTransRtp;   ///< �ն���rtp��ַ
	u32               dwPayload;   ///< ������ payload
public:
	tagTMTStreamChanParam_Api() { memset( this ,0 ,sizeof( struct  tagTMTStreamChanParam_Api ) ); }

}*PTMTStreamChanParam_Api,TMTStreamChanParam_Api;


/** PC˫��ͨ������������Ϣ�ṹ */
typedef struct tagTMTPcAssStreamChanParam_Api 
{
	TNetAddr_Api       tTransRtp;      ///< mtת��rtp��ַ
	TNetAddr_Api       tTransRtcp;     ///< mtת��rtcp��ַ 
	TVidEncParam_Api   tEncParam; ///< ͨ���ı����ʽ
	u32                dwPlayLoad;         ///< ͨ��payload
	TEncryptKey_Api    tEncryptKey;  ///< ��������
public:
	tagTMTPcAssStreamChanParam_Api(){ memset( this ,0 ,sizeof( struct  tagTMTPcAssStreamChanParam_Api ) );}
}*PTMTPcAssStreamChanParam_Api,TMTPcAssStreamChanParam_Api;

/** PC���湲��ʱ�����Ͷ�PC����ز���:ϵͳ�ֱ���,���˵�ַ */
typedef struct tagTPCSysParam_Api
{
	u16                   wScrWidth;                               ///< ��Ļ��
	u16                   wScrHeight;                              ///< ��Ļ��
	u8                    byMaxH263CapSVGA;                ///< ��ȡH.263/SVGA�µ����׽����
	u8                    byMaxH263CapXGA;                  ///< ��ȡH.263/XGA�µ����׽����
	u8                    byMaxH264CapSVGA;                ///< ����H.264/SVGA�µ����׽����
	u8                    byMaxH264CapXGA;                   ///< ����H.264/XGA�µ����׽����
	u32                   dwMtAddr;                                 ///< Ŀ���ն˵�IP��Ϣ(������)
	EmMtResolution_Api emVidRes;                          ///< ��Ļ�ֱ���
	TNetAddr_Api          tPcNetAddr;                         ///< ���˵�ַ
	EmCodecComponent_Api  emCodecComponent; ///< ����뷢������
	EmMtVideoPort_Api     emMtVideoPort;               ///< ����Ƶ�˿�
public:
	tagTPCSysParam_Api()
	{ 
		memset( this ,0 , sizeof( struct  tagTPCSysParam_Api ) );
		emMtVideoPort    = /*emMtPC_Api*/emMtVidInvalid_Api;
		emCodecComponent = emVidMainEncoder_Api;
	}
}*PTPCSysParam_Api, TPCSysParam_Api;

/** ������ͳ����Ϣ */
typedef struct tagTCodecPackStat_Api
{
	u32    dwBitrate;             ///< ʵʱ����
	u32    dwAvrBitrate;        ///< ƽ������
	u32    dwLostPacks;         ///< ������
	u32    dwTotalPacks;        ///< �շ�����
	u32    dwFrames;             ///< �շ�֡��
	u32    dwLostFrameRate; ///< ��֡��(2��)%d 
public:
	tagTCodecPackStat_Api(){memset(this ,0 ,sizeof( struct tagTCodecPackStat_Api)); }
}*PTCodecPackStat_Api,TCodecPackStat_Api;

/** socket5������Ϣ */
typedef struct tagTMTOspSock5Proxy_Api
{
	u32 dwProxyIp;                                                                  ///< ����IP(������)
	u32 dwProxyPort;                                                               ///< ����˿�
	u32 dwAuthenNum;                                                           ///< ��֤����
	s8  achAuthenMethod[KMTAPI_BUF_128_LEN+1];               ///< ��֤����
	s8  achUserName[KMTAPI_IM_SOCK5_USERNAME_LEN+1]; ///< �û���
	s8  achPassword[KMTAPI_IM_SOCK5_PASSWORD_LEN+1];  ///< ����
public:
	tagTMTOspSock5Proxy_Api(){ memset( this ,0 ,sizeof( struct  tagTMTOspSock5Proxy_Api ) );}
}*PTMTOspSock5Proxy_Api, TMTOspSock5Proxy_Api;

/** ������������Ϣ */
typedef struct tagTMTSUSAddr_Api
{
	s8  achDomain[KMTAPI_MAX_DOMAIN_NAME_LEN+1];           ///< ����
	u32 dwIP;                                                                                 ///< ip (ʹ��������)
	u32 dwPort;
	BOOL32 bUseDefaultAddr;                                                        ///< ʹ��Ĭ�ϵ�ַ
	s8 achCustomDomain[KMTAPI_MAX_DOMAIN_NAME_LEN+1]; ///< �û��Զ�������
	u32 dwCustomIp;                                                                      ///<�û��Զ���ip
public:
	tagTMTSUSAddr_Api(){ memset( this ,0 ,sizeof( struct  tagTMTSUSAddr_Api ) );}
}*PTMTSUSAddr_Api,TMTSUSAddr_Api;

/** ����ʱ���ṩ��������������Ϣ */
typedef struct tagTMTUpgradeNetParam_Api
{
	u32    dwServerIp;                            ///< sus������IP (������)
	u32    dwPort;
	BOOL32 bUsedProxy;                       ///< �Ƿ����ô��������
	TMTOspSock5Proxy_Api tProxyInfo; ///< ���ô���Ļ� �����������Ϣ
	s8	achDomain[KMTAPI_MAX_DOMAIN_NAME_LEN+1];   ///< ����
public:
	tagTMTUpgradeNetParam_Api(){ memset( this ,0 ,sizeof( struct  tagTMTUpgradeNetParam_Api ) );}
}*PTMTUpgradeNetParam_Api,TMTUpgradeNetParam_Api;

/** ����ʱ���ṩ���豸��Ϣ */
typedef struct tagTMTUpgradeDeviceInfo_Api
{
	s8 achDevType[KMTAPI_MAX_DEV_TYPE_NAME_LEN+1];   ///< �豸����
	s8 achOemMark[KMTAPI_MAX_DEV_OEM_MARK_LEN+1]; ///< �豸OEM��ʶ
	s8 achE164[KMTAPI_MAX_MT_E164_LEN+1];                      ///< �豸164��ʶ
	s8 achCurSoftVer[KMTAPI_MAX_DEV_SOFT_VER_LEN+1];   ///< �豸Ŀǰ����汾
	u32 dwDevIp;                                                                     ///< �ն�IP (������)
public:
	tagTMTUpgradeDeviceInfo_Api(){ memset( this ,0 ,sizeof( struct  tagTMTUpgradeDeviceInfo_Api ) );}
}*PTMTUpgradeDeviceInfo_Api,TMTUpgradeDeviceInfo_Api;

/** ����ʱ���ṩ�������������Ϣ */
typedef struct tagTMTUpgradeClientInfo_Api
{
	TMTUpgradeNetParam_Api   tServerInfo;  ///< sus��������Ϣ
	TMTUpgradeDeviceInfo_Api tDevInfo;       ///< �豸��Ϣ
public:
	tagTMTUpgradeClientInfo_Api(){ memset( this ,0 ,sizeof( struct  tagTMTUpgradeClientInfo_Api ) );}
}*PTMTUpgradeClientInfo_Api,TMTUpgradeClientInfo_Api;

/** �����Ҷȷ�����Χ */
typedef struct tagTMTUpgradeGrayRange_Api
{
	s8 achMoidList[KMTAPI_MAXLEN_SUS_MOIDLIST+1]; ///< moid�б�
	s8 achE164List[KMTAPI_MAXLEN_SUS_E164LIST+1];    ///< e164�б�
public:
	tagTMTUpgradeGrayRange_Api() { memset( this, 0, sizeof(struct tagTMTUpgradeGrayRange_Api) ); }
}*PTMTUpgradeGrayRange_Api, TMTUpgradeGrayRange_Api;

/** ��������õ��ĵ����汾����Ϣ */
typedef struct tagTMTUpgradeVersionInfo_Api
{
	u32     dwVer_id ;   		                                                              ///< �汾Ψһ��ʶ
	s8      achOemMark[KMTAPI_MAX_DEV_OEM_MARK_LEN+1];     ///< �豸OEM��ʶ
	s8      achDevType[KMTAPI_MAX_DEV_TYPE_NAME_LEN+1];	      ///< �豸����
	EmUpgradeVerLevel_Api emUpgradeVerLevel;                            ///< ��������
	s8      achCurSoftVer[KMTAPI_MAX_DEV_SOFT_VER_LEN+1];       ///< �豸Ŀǰ����汾
	s8      achVerNotes[KMTAPI_MAX_VER_RELEASE_NOTES_LEN+1]; ///< �汾˵����Ϣ
	u32     dwSize;                                                                             ///< �汾��С
	s8      achFileName[KMTAPI_BUF_256_LEN + 1];                          ///< �ļ���
	EmUpgradeReleaseAttr_Api emUpgradeAttr;                               ///< ��������
	TMTUpgradeGrayRange_Api tGrayRange;                                   ///< �Ҷȷ�����Χ
public:
	tagTMTUpgradeVersionInfo_Api(){ memset( this ,0 ,sizeof( struct  tagTMTUpgradeVersionInfo_Api ) );}
}*PTMTUpgradeVersionInfo_Api,TMTUpgradeVersionInfo_Api;

/** ��������õ��İ汾�б� */
typedef struct tagTMTUpgradeVersionInfoList_Api
{
	TMTUpgradeVersionInfo_Api tVerList[KMTAPI_MAX_UPGRATE_VER_LIST_NUM]; ///< �汾�б�
	BOOL32 bNewestVersion;                                                                                  ///< �Ƿ�Ϊ���°汾
	u8  byCnt;                                                                                                          ///< �б����
public:
	tagTMTUpgradeVersionInfoList_Api(){ memset( this ,0 ,sizeof( struct  tagTMTUpgradeVersionInfoList_Api ) );}
}*PTMTUpgradeVersionInfoList_Api,TMTUpgradeVersionInfoList_Api;

/** ���������ؽ�����Ϣ */
typedef struct tagTMTUpgradeDownloadInfo_Api
{
	u32  dwErrcode;                                                                       ///< ������
	u32  dwTotalPercent;	                                                            ///< �ļ������ܽ���
	u32  dwCurPercent;	                                                                ///< ��ǰ�ļ������ؽ���
	s8   achCurFileName[KMTAPI_MAX_PATH_FILE_NAME_LEN+1]; ///< ��ǰ�������ص��ļ���
public:
	tagTMTUpgradeDownloadInfo_Api(){ memset( this ,0 ,sizeof( struct  tagTMTUpgradeDownloadInfo_Api ) );}
}*PTMTUpgradeDownloadInfo_Api, TMTUpgradeDownloadInfo_Api;

/** XNU������(XMPP��¼)���� */
typedef struct tagTMtXMPPInfo_Api
{
	s8  achDomain[KMTAPI_MAX_DOMAIN_NAME_LEN+1]; ///< ����
	u32 dwIp;                                                                       ///< ip (������)
	u32 dwPort;                                                                    ///< �˿�
	s8  achName[KMTAPI_MAX_USERNAME_LEN+1];            ///< �û���(jid)
	s8  achPassword[KMTAPI_MAX_USERPWD_LEN+1];         ///< ����
public:
	tagTMtXMPPInfo_Api(){ memset( this ,0 ,sizeof( struct  tagTMtXMPPInfo_Api ) );}
}*PTMtXMPPInfo_Api, TMtXMPPInfo_Api;

/** ��ȡNS��ַ (�¼�)*/
typedef struct tagTMtNSADDRInfo_Api
{
    s8  achDomain[KMTAPI_MAX_DOMAIN_NAME_LEN+1]; ///< ����
    u32 dwIp;                                    ///< ip (������)
    u32 dwPort;                                 ///< �˿�
    u32 dwTlsProt;                              ///tls
public:
    tagTMtNSADDRInfo_Api(){ memset( this ,0 ,sizeof( struct  tagTMtNSADDRInfo_Api ) );}
}TMtNSADDRInfo_Api, *PTMtNSADDRInfo_Api;


/** CSU������ */
typedef struct tagTMtCSUAddr_Api
{
	BOOL32 bUsedCSU;                             ///< �Ƿ�ʹ��CSU
	s8  achDomain[KMTAPI_MAX_DOMAIN_NAME_LEN+1]; ///< GK����
	u32 dwIp;                                    ///< GKIp (������)
	u32 dwPort;                                  ///< GK�˿ڣ� ��������׼��1720�� �Ǳ������ƽ̨���ص�ֵ
	s8 achNumber[KMTAPI_MAX_DOMAIN_NAME_LEN+1];  ///< ע��ʱʹ�õĺ���
	s8 achPassword[KMTAPI_MAX_USERPWD_LEN+1];    ///< ����
	u32 dwTimeToLive;                            ///< GK���ʱʱ�� ��λ(s)
	s8  achAuthName[KMTAPI_MAX_DOMAIN_NAME_LEN]; ///< ��֤����, ��д�������õ���֤����
public:
	tagTMtCSUAddr_Api(){ memset( this ,0 ,sizeof( struct  tagTMtCSUAddr_Api ) );}
}*PTMtCSUAddr_Api, TMtCSUAddr_Api;

/** ���ܷ�������ַ */
typedef struct tagTMtNMAAddr_Api
{
	u32 dwIp;                                                                       ///< ���ܷ�����Ip (������)
	s8  achDomain[KMTAPI_MAX_DOMAIN_NAME_LEN+1]; ///< ����	
	u32 dwPort;                                                                   ///< �˿�
public:
	tagTMtNMAAddr_Api(){ memset( this ,0 ,sizeof( struct  tagTMtNMAAddr_Api ) );}
}*PTMtNMAAddr_Api, TMtNMAAddr_Api;

/** ��¼Nms����Ҫ�Ŀͻ���Ӳ����Ϣ���� */ 
typedef struct tagTNMSClientHWInfo_Api 
{
	s8 achOS[KMTAPI_BUF_128_LEN + 1];          ///< ����ϵͳ
	s8 achCpuType[KMTAPI_BUF_128_LEN + 1]; ///< cpu�ͺ�
	u32 dwCpuFreq;                                          ///< cpu��Ƶ(Mhz)
	u32 dwMemory;                                          ///< �ڴ�����(M)
	u32 dwCpuNum;                                         ///< cpu����
public:
	tagTNMSClientHWInfo_Api(){ memset( this ,0 ,sizeof( struct  tagTNMSClientHWInfo_Api ) );}
}*PTNMSClientHWInfo_Api, TNMSClientHWInfo_Api;

/** NMS��¼��� */
typedef struct tagTNMSLogInResult_Api
{
	BOOL32  bLoginOk; ///<NMS��¼���
	u32		dwReason; ///<����¼ʧ�ܣ����ֶα�����ʧ��ԭ��
public:
	tagTNMSLogInResult_Api(){ memset( this ,0 ,sizeof( struct  tagTNMSLogInResult_Api ) );}
}*PTNMSLogInResult_Api, TNMSLogInResult_Api;

/** NTS���Է�������¼���� */
typedef struct tagTMtNTSAddr_Api
{
	s8  achDomain[KMTAPI_MAX_DOMAIN_NAME_LEN+1]; ///< ����
	u32 dwIp;                                                                      ///< Ip (������)
	u32 dwPort;
public:
	tagTMtNTSAddr_Api(){ memset( this ,0 ,sizeof( struct  tagTMtNTSAddr_Api ) );}
}*PTMtNTSAddr_Api, TMtNTSAddr_Api;

/** NAT��Ϣ���� */
typedef struct tagTMTNat_Api
{
	BOOL32   bEnable; ///< �Ƿ�����
	u32      dwIp;         ///< NAT Ip��ַ  (������)
public:
	tagTMTNat_Api(){ memset( this ,0 ,sizeof( struct  tagTMTNat_Api ) );}
}*PTMTNat_Api, TMTNat_Api;

/** XAP��¼���� */
typedef struct tagTMtXAPSvr_Api
{
	EmServerAddrType_Api emAddrType;                             ///< ��ַ����
	s8  achAlias[KMTAPI_BUF_64_LEN+1];                            ///< ����
	s8  achDomain[KMTAPI_MAX_DOMAIN_NAME_LEN+1]; ///< ����
	u32 dwIp;                                                                       ///< ip (������)
	BOOL32 bIsIpSvr;                             ///< �Ƿ���IP���͵�aps������
    u32 dwPort;                                  ///�˿ں�
public:
	tagTMtXAPSvr_Api(){ memset( this ,0 ,sizeof( struct  tagTMtXAPSvr_Api ) );}
}*PTMtXAPSvr_Api, TMtXAPSvr_Api;

/** APS��ַ��Ϣ */
typedef struct tagTMtAPSSvrAddr_Api
{
	s8  achDomain[KMTAPI_MAX_DOMAIN_NAME_LEN+1]; ///< ����
	u32 dwIp;                                                                       ///< ip (������)
    u32 dwPort;                                  ///< �˿ں�
public:
	tagTMtAPSSvrAddr_Api(){ memset( this ,0 ,sizeof( struct  tagTMtAPSSvrAddr_Api ) );}
}*PTMtAPSSvrAddr_Api, TMtAPSSvrAddr_Api;

/** XAP��¼���� �б�*/
typedef struct tagTMtXAPSvrList_Api
{
	BOOL32         bAutoSelect;							                          ///< �Ƿ��Զ�ѡ���������½
	u8             byCurIndex;                                                           ///< ��ǰ��Ч�ĵ�ַ����
	TMtXAPSvr_Api  arrMtXAPSvr[KMTAPI_MAX_XAP_LIST_NUM];  ///< XAP��¼�б�
	u8             byCnt;                                                                    ///< ʵ�ʸ���
public:
	tagTMtXAPSvrList_Api(){ memset( this ,0 ,sizeof( struct  tagTMtXAPSvrList_Api ) );}
}*PTMtXAPSvrList_Api, TMtXAPSvrList_Api;

/** NTP��¼���� */
typedef struct tagTMtNTPAddr_Api	
{
	s8  achDomain[KMTAPI_MAX_DOMAIN_NAME_LEN+1]; ///< ����
	u32 dwIp;                                                                       ///< ip (������)
	u32 dwPort;                                                                    ///< �˿�
public:
	tagTMtNTPAddr_Api(){ memset( this ,0 ,sizeof( struct  tagTMtNTPAddr_Api ) );}
}*PTMtNTPAddr_Api, TMtNTPAddr_Api;

/** VOD��������ַ */
typedef struct tagTMtVODSvrCfg_Api
{
	BOOL32 bEnable;                                                           ///< �Ƿ�����
	s8  achDomain[KMTAPI_MAX_DOMAIN_NAME_LEN+1]; ///< ����
	u32 dwIp;                                                                       ///< ip (������)
	u16 wPort;                                                                      ///< �˿�
	s8 achUsername[KMTAPI_MAX_USERNAME_LEN + 1];    ///< �û���
	s8 achPassword[KMTAPI_MAX_USERPWD_LEN + 1];       ///< ����
public:
	tagTMtVODSvrCfg_Api(){ memset( this ,0 ,sizeof( struct  tagTMtVODSvrCfg_Api ) );}
}*PTMtVODSvrCfg_Api, TMtVODSvrCfg_Api;

/** VRS��������ַ */
typedef struct tagTMtVRSSvrCfg_Api
{
	BOOL32 bEnable;                                    ///< �Ƿ�����
	BOOL32 bCustom;                                    ///< �Ƿ��Զ���  TRUE:�Զ��� FALSE �Զ�
	s8     achDomain[KMTAPI_MAX_DOMAIN_NAME_LEN+1];       ///< ��½ƽ̨�õ���vod��������ַ
	u32    dwIp;                                                                             ///< ip (������)
	s8     achCustomAddr[KMTAPI_MAX_DOMAIN_NAME_LEN+1]; ///< �Զ����������ַ(bCustomΪtrue��ʱ������)
	u32    dwPort;                                                                            ///< �˿�
	s8     achUsername[KMTAPI_MAX_FULL_USERNAME_LEN + 1];         ///< �û���
	s8     achPassword[KMTAPI_MAX_USERPWD_LEN + 1];             ///< ����
public:
	tagTMtVRSSvrCfg_Api(){ memset( this ,0 ,sizeof( struct  tagTMtVRSSvrCfg_Api ) );}
}*PTMtVRSSvrCfg_Api, TMtVRSSvrCfg_Api;

/** ��ý�� */
typedef struct tagTMTStreamMedia_Api
{
	BOOL32    bEnable;                                                                  ///< �Ƿ�����
	BOOL32    bForwardLocalVideo;                                               ///< �Ƿ�ת��������Ƶ
	u32       dwMultCastIP;                                                             ///< �鲥IP��ַ (������)
	u32       dwPort;                                                                        ///< �˿ں�
	u32       dwTTL;                                                                          ///< TTLֵ
	s8        achChnlName[KMTAPI_MAX_CHANNEL_NAME_LEN+1]; ///< Ƶ������
	s8        achPassword[KMTAPI_MAX_CHANNEL_PWD_LEN+1];     ///< ����
public:
	tagTMTStreamMedia_Api(){ memset( this ,0 ,sizeof( struct  tagTMTStreamMedia_Api ) );}
}*PTMTStreamMedia_Api, TMTStreamMedia_Api;

/** ƽ̨API��ַ */
typedef struct tagTMtPlatformApiAddr_Api
{
	s8  achDomain[KMTAPI_MAX_DOMAIN_NAME_LEN+1]; ///< ����
	u32 dwIp;                                                                       ///< ip (������)
public:
	tagTMtPlatformApiAddr_Api(){ memset( this ,0 ,sizeof( struct  tagTMtPlatformApiAddr_Api ) );}
}*PTMtPlatformApiAddr_Api, TMtPlatformApiAddr_Api;

/** ΢����ַ */
typedef struct tagTMtMicroBlogAddr_Api
{
	s8  achDomain[KMTAPI_MAX_DOMAIN_NAME_LEN+1]; ///< ����
	u32 dwIp;                                                                       ///< ip (������)
public:
	tagTMtMicroBlogAddr_Api(){ memset( this ,0 ,sizeof( struct  tagTMtMicroBlogAddr_Api ) );}
}*PTMtMicroBlogAddr_Api, TMtMicroBlogAddr_Api;

/** Sip���������� */
//��û����дdwIp����ֶ�ʱ���Ż����achPxyDomain sip�������������
typedef struct tagTMtSipSvrAddr_Api
{
	BOOL32 bEnable;										  ///< �Ƿ�ע��sip���������
	s8  achDomain[KMTAPI_MAX_DOMAIN_NAME_LEN+1];          ///< ����������
	u32 dwIp;                                             ///< sip ���������ip (������)
	u32 dwPort;                                           ///< �������˿�, ����ϲ�����Ϊ0�� �ײ�ΪĬ��ֵ5060
	s8  achPassword[KMTAPI_MAX_USERPWD_LEN+1];            ///< ע������
	u32 dwExpire;                                         ///< ����ʱ�䣬�ײ㱣��ʱ�䣬�����0�� �ײ�ΪĬ��ֵ20, ��λΪs
	s8  achValidateName[KMTAPI_MAX_DOMAIN_NAME_LEN+1];    ///< ��֤����, ע������ƣ� sipע��ֻ��ע��һ�����ƣ�����/e164��
	u32 dwHostPort;                                       ///< �����˿�, �������sipЭ��ջ�����˿ڣ���Ĭ��Ϊ5060
	s8  achAuthName[KMTAPI_MAX_DOMAIN_NAME_LEN];          ///< ��֤������
	u32 dwTlsPort;                                        ///< ������tls�˿�, ����ϲ�����Ϊ0�� �ײ�ΪĬ��ֵ5061
	u32 dwGtlsPort;                                       ///< ������gtls�˿�, ����ϲ�����Ϊ0�� �ײ�ΪĬ��ֵ5061
	s8  achPxyDomain[KMTAPI_MAX_DOMAIN_NAME_LEN+1];       ///< sip�������������
public:
	tagTMtSipSvrAddr_Api(){ memset( this ,0 ,sizeof( struct  tagTMtSipSvrAddr_Api ) );}
}*PTMtSipSvrAddr_Api, TMtSipSvrAddr_Api;

/** Sip�������� */
typedef struct tagTMtSipProxyCfg_Api
{
	s8  achDomain[KMTAPI_MAX_DOMAIN_NAME_LEN+1];  ///< ����������
	u32 dwIp;                                                                       ///< ������ip (������)
	u32 dwPort;                                                                   ///< �������˿�
public:
	tagTMtSipProxyCfg_Api(){ memset( this ,0 ,sizeof( struct  tagTMtSipProxyCfg_Api ) );}
}*PTMtSipProxyCfg_Api, TMtSipProxyCfg_Api;

/** H323������������� */
typedef struct tagTMtH323PxyCfg
{
	BOOL32 bEnable;								                            ///< �Ƿ�����
	u32 dwSrvIp;                                                                 ///< ������ip (������)
	u32 dwSrvPort;                                                              ///< �������˿�
	s8 achNumber[KMTAPI_MAX_DOMAIN_NAME_LEN+1]; ///< ע��ʱʹ�õĺ���
	s8 achPassword[KMTAPI_MAX_USERPWD_LEN+1];         ///< ����
public:
	tagTMtH323PxyCfg(){ memset( this ,0 ,sizeof( struct  tagTMtH323PxyCfg ) );}
}*PTMtH323PxyCfg_Api, TMtH323PxyCfg_Api;

/** Meeting���������� */
typedef struct tagTMtMeetingSvrAddr_Api
{
	s8  achDomain[KMTAPI_MAX_DOMAIN_NAME_LEN+1]; ///< ����������
	u32 dwIp;                                                                      ///< ������ip (������)
	u32 dwPort;
public:
	tagTMtMeetingSvrAddr_Api(){ memset( this ,0 ,sizeof( struct  tagTMtMeetingSvrAddr_Api ) );}
}*PTMtMeetingSvrAddr_Api, TMtMeetingSvrAddr_Api;

/** H460������������� */
typedef struct tagTMtH460PxyCfg
{
	BOOL32 bEnable;								                            ///< �Ƿ�����
	u32 dwSrvIp;                                                                 ///< ������ip (������)
	s8 achNumber[KMTAPI_MAX_DOMAIN_NAME_LEN+1]; ///< ע��ʱʹ�õĺ���
	s8 achPassword[KMTAPI_MAX_USERPWD_LEN+1];         ///< ����
public:
	tagTMtH460PxyCfg(){ memset( this ,0 ,sizeof( struct  tagTMtH460PxyCfg ) );}
}*PTMtH460PxyCfg_Api, TMtH460PxyCfg_Api;

/** socks5�������� */ 
typedef struct tagTSocks5ProxyCfg_Api
{
	TNetAddr_Api tServerAddr;                                                ///< socks5�����������ַ
	s8  achUserName[KMTAPI_MAX_DOMAIN_NAME_LEN+1]; ///< ����������
	s8  achPassword[KMTAPI_MAX_USERPWD_LEN+1];            ///< ����
public:
	tagTSocks5ProxyCfg_Api(){ memset( this ,0 ,sizeof( struct tagTSocks5ProxyCfg_Api ) );}
}*PTSocks5ProxyCfg_Api,TSocks5ProxyCfg_Api;

/** ������״̬�� */
typedef struct tagTMtSvrState_Api
{
	EmServerType_Api  emSvrType; ///< ����������
	EmServerState_Api emSvrState; ///< ״̬        
public:
	tagTMtSvrState_Api(){ memset( this ,0 ,sizeof( struct tagTMtSvrState_Api ) );}
}*PTMtSvrState_Api,TMtSvrState_Api;

/** ������״̬�� */
typedef struct tagTMtSvrStateList_Api
{
	TMtSvrState_Api arrSvrState[KMTAPI_MAX_SVRSTATE_LIST_NUM]; ///< ������״̬�б�
	u8              byCnt;                                                                         ///< ʵ�ʸ���
public:
	tagTMtSvrStateList_Api(){ memset( this ,0 ,sizeof( struct tagTMtSvrStateList_Api ) );}
}*PTMtSvrStateList_Api,TMtSvrStateList_Api;

/** Xap��¼�ɹ����ȡ���û�Ȩ����Ϣ */
typedef struct tagTMtUserPrevilege_Api
{
	BOOL32 bDefaultServiceDomainAdmin; ///< Ĭ�ϵķ��������
	BOOL32 bDefaultUserDomainAdmin;     ///< Ĭ�ϵ��û������
	BOOL32 bEnableBMC;     				         ///< BMCȨ��
	BOOL32 bEnableCall;     			             ///< ��ͨ�绰����
	BOOL32 bEnableDCS;     				         ///< DCSȨ��
	BOOL32 bEnableHD;     				        ///< ֧�ָ�����Ƶ����
	BOOL32 bEnableIncoming;     		        ///< ��ͨ���Ȩ��
	BOOL32 bEnableMeeting;     			    ///< ��ͨ�������
	BOOL32 bEnableMeetingSMS;     		    ///< ��ܶ���Ȩ��
	BOOL32 bEnableNM;     				        ///< NMȨ��
	BOOL32 bEnableOut;     				       ///< ��ͨ����Ȩ��
	BOOL32 bEnableRoam;     			       ///< ��ͨ����Ȩ��
	BOOL32 bEnableSatellite;     		          ///< ������·Ȩ��
	BOOL32 bEnableSatelliteP2P;     	      ///< ������·��Ե�
	BOOL32 bEnableUMC;     				      ///< UMCȨ��
	BOOL32 bEnableVRS;     				      ///< VRSȨ��
	BOOL32 bEnableWeibo;     			      ///< ��ͨ΢��
	BOOL32 bEnableAdmin;     			      ///< �������Ա
	BOOL32 bServiceDomainAdmin;     	  ///< ���������Ա
	BOOL32 bUserDomainAdmin;     		  ///< �û������Ա
	BOOL32 bWeiboAdmin;     			      ///< ΢������Ա
	BOOL32 bSelfBuilt; 					         ///< ƽ̨���ԣ��Ƿ��Խ�ƽ̨
	BOOL32 bPortMedia; 		                 ///< ƽ̨���ԣ��˿ڻ���
    BOOL32 bEnableAutoCreateMeeting;           /// ����Ȩ�� ����֧��ƽ̨5.2֮��汾��
public:
	tagTMtUserPrevilege_Api(){ memset( this ,0 ,sizeof( struct tagTMtUserPrevilege_Api ) );}
}*PTMtUserPrevilege_Api,TMtUserPrevilege_Api;

/** aps��¼��ȡ�����û���Ϣ */
typedef struct tagTMTUserInfoFromAps_Api
{
	s8 achE164[KMTAPI_MAX_MT_E164_LEN+1];            ///< E164
	s8 achEmail[KMTAPI_MAX_EMAIL_LEN+1];               ///< ����
	s8 achJid[KMTAPI_IM_MAX_ID_LEN + 1];                  ///< Jid
	s8 achMoid[KMTAPI_MAX_DOMAIN_MOID_LEN+1]; ///< Moid
	s8 achXmppPwd[KMTAPI_BUF_64_LEN + 1];              ///< XMPP����
	s8 achAccount[KMTAPI_BUF_128_LEN + 1];               ///< �Զ����˺�
    u32 dwRegMode;                                 // 1:ʹ��164��ע�ᣬ2ʹ��m_szMoidע��
    s8  achCTime[KMTAPI_BUF_16_LEN+1];             //�û�����ʱ���ʽ 20170908120506(������ʱ����)
    BOOL32 bIsGuest;                               //FALSE��ʾ��ͨ�û� TRUE��ʾ�����û� 
public:
	tagTMTUserInfoFromAps_Api(){ memset( this ,0 ,sizeof( struct tagTMTUserInfoFromAps_Api ) );}
}*PTMTUserInfoFromAps_Api, TMTUserInfoFromAps_Api;

/** H323���� */
typedef struct tagTMtH323Cfg_Api	
{
	BOOL32 bEnableH239; ///< h239��ʽ 
	u32    dwCallPriority;    ///< �������ȼ��� ����ǿ�� ���ﷶΧ��1-255
public:
	tagTMtH323Cfg_Api(){ memset( this ,0 ,sizeof( struct tagTMtH323Cfg_Api ) );}
}*PTMtH323Cfg_Api,TMtH323Cfg_Api;

/** ��Ƶѡ�� */
typedef struct tagTMTAudioOptions_Api
{
	BOOL32 bEnableAEC; ///< ��������
	BOOL32 bEnableAGC; ///< �Զ����油��
	BOOL32 bEnableANS; ///< ������������
public:
	tagTMTAudioOptions_Api(){ memset( this ,0 ,sizeof( struct tagTMTAudioOptions_Api ) );}
}*PTMTAudioOptions_Api,TMTAudioOptions_Api;

/** �Զ����� */
typedef struct tagTMTAutoCall_Api
{
	BOOL32  bIsAutoCallEnable;                                      ///< �Ƿ������Զ�����
	s8      achTerName[KMTAPI_MAX_MT_ALIAS_LEN+1]; ///< �Զ����е��ն���
	u32     dwCallRate;                                                     ///< �Զ���������
public:
	tagTMTAutoCall_Api(){ memset( this ,0 ,sizeof( struct tagTMTAutoCall_Api ) );}
}*PTMTAutoCall_Api,TMTAutoCall_Api;

/** ������Ƶͨ���������� */
typedef struct tagTVidBitRationCfg_Api
{
	EmVidRationStrategy_Api     emRationStrategy; ///< ���ԣ�����Ƶ���ȣ���������Ƶ���ȣ������Զ��壬����Զ���������Ĳ���
	u32    adwMainVidRation[KMTAPI_COUNT_8];   ///< ����Ƶÿ��ͨ���ı���
	u32    dwMainCount;                                        ///< ���ж��ٸ�����Ƶ
	u32    adwAssVidRation[KMTAPI_COUNT_8];     ///< ����Ƶÿ��ͨ���ı���
	u32    dwAssCount;                                           ///< ���ж��ٸ�����Ƶ
public:
	tagTVidBitRationCfg_Api(){ memset( this ,0 ,sizeof( struct tagTVidBitRationCfg_Api ) );}
}*PTVidBitRationCfg_Api ,TVidBitRationCfg_Api;

/** �ն����� */
typedef struct tagTMtTerminalName_Api
{
	s8 	    achE164[KMTAPI_MAX_MT_E164_LEN+1];     ///< �ն�E164����
	s8      achTerlAlias[KMTAPI_MAX_MT_ALIAS_LEN+1]; ///< �ն�����
public:
	tagTMtTerminalName_Api(){ memset( this ,0 ,sizeof( struct tagTMtTerminalName_Api ) );}
}*PTMtTerminalName_Api,TMtTerminalName_Api;

/** �ն���Ϣ */
typedef struct tagTTerminalInfo_Api
{
	EmMtModel_Api emMtModel;                                                               ///< �ն��ͺ�
	s8 	          achTypeName[KMTAPI_MAX_MT_TYPE_NAME_LEN+1];        ///< �ն��ͺ�����
	s8            achHardwareVer[KMTAPI_MAX_MT_HARDWARE_VER_LEN+1]; ///< Ӳ���汾
	s8            achSoftwareVer[KMTAPI_MAX_MT_SOFTWARE_VER_LEN+1];   ///< ����汾
	s8            achOEMName[KMTAPI_MAX_MT_OEM_NAME_LEN+1];           ///< ������Ϣ
	s8            achFPGA1Ver[KMTAPI_BUF_32_LEN+1];                                     ///< FPGA1�汾
	s8            achFPGA2Ver[KMTAPI_BUF_32_LEN+1];                                     ///< FPGA2�汾
	s8            achCPLDVer[KMTAPI_BUF_32_LEN+1];                                     ///< CPLD�汾
	s8            achSerialNum[KMTAPI_BUF_32_LEN+1];                                   ///< ���к�
    s8            achInfraredVer[KMTAPI_BUF_32_LEN+1];                                  ///< ���ⵥƬ���汾��
	s8            achFPGA3Ver[KMTAPI_BUF_32_LEN+1];                                     ///< FPGA3�汾
	s8            achFPGA4Ver[KMTAPI_BUF_32_LEN+1];                                     ///< FPGA4�汾
	s8			  achPTZVer[KMTAPI_BUF_32_LEN+1];                                       ///< PTZ�汾�ţ��� sky300֧��
public:
	tagTTerminalInfo_Api(){ memset( this ,0 ,sizeof( struct tagTTerminalInfo_Api ) );}
}*PTTerminalInfo_Api,TTerminalInfo_Api;


///////////////////////////////////////////////////////////////////////

//added by ydwu 2014.06.17 begin
/** �����ṹ�� */
typedef struct tagTImComm_Api
{
	u32 dwErrID;                                                ///< ����ID
	u32 dwHandle;                                             ///< �����
	u32 dwReserved;                                          ///< Ԥ����չ��
	s8  achReserved[ KMTAPI_BUF_256_LEN+1 ];	///< Ԥ����չ��
public:
	tagTImComm_Api() { memset( this, 0, sizeof(tagTImComm_Api) ); }
}*PTTImComm_Api, TImComm_Api;

/** �û���¼ */
typedef struct tagTImUserLogin_Api
{
	s8   achNO[ KMTAPI_IM_MAX_ID_LEN + 1];                                    ///< ��¼�ں�(��ʽΪ"�û���@����")
	s8   achUserPwd[KMTAPI_MAX_MT_PWD_LEN + 1];                        ///< ����
	s8   achStunAddr[KMTAPI_IM_MAX_ADDRESS_LEN + 1];                 ///< stun server ip address
	s8   achDefaultSaveDir[KMTAPI_IM_MAX_PATH_LEN + 1];               ///< default save directory
	s8   achEnterpriseName[KMTAPI_IM_ENTERPRISE_NAME_LEN + 1]; ///< ��ҵ����(���ڴ�����֯�ܹ�������)
	s8   achPicSaveDir[KMTAPI_IM_MAX_PATH_LEN + 1];                      ///< �����ͼ��·��(����·��)
	s8   achResource[KMTAPI_IM_MAX_RESOURCE_LEN + 1];                ///< ��Դ            
	s8   achSock5Username[KMTAPI_IM_SOCK5_USERNAME_LEN + 1]; ///< sock5�û���
	s8   achSock5Password[KMTAPI_IM_SOCK5_PASSWORD_LEN + 1];  ///< sock5����
	s8   achConfigPath[KMTAPI_IM_MAX_PATH_LEN + 1];                     ///< �����û����õ�·��
	s8   achSock5Addr[KMTAPI_IM_SOCK5_ADDR_NAME_LEN + 1];       ///< sock5��ַ
	u32 dwImIP;                                                                                   ///< ������ip��ַ
	u16 wPort;                                                                                      ///< �������˿�
	u16 wStunPort;                                                                               ///< stun port
	u16 wSock5Port;                                                                             ///< sock5�˿�
	u8  byPwdLen;                                                                                ///< ���볤��	
	BOOL32 bFileShareEnable;                                                             ///< �Ƿ�����xmpp�ļ�����
	BOOL32 bAudioCapability;                                                             ///< �Ƿ�����Ƶ����(Ӳ��)
	BOOL32 bVideoCapability;                                                             ///< �Ƿ�����Ƶ����(Ӳ��)
	BOOL32 bInstant;                                                                          ///< �Ƿ�������¼
	BOOL32 bUseSock5;                                                                      ///< �Ƿ�����sock5����
	BOOL32 bCompression;                                                                 ///< �Ƿ�ʹ��zlibѹ����	
public:
	tagTImUserLogin_Api() 
	{ 
		memset( this, 0, sizeof(tagTImUserLogin_Api) ); 
		bAudioCapability = TRUE;                             ///< Ĭ���ն˶�����Ƶ����Ƶ����
		bVideoCapability = TRUE;
		bInstant         = TRUE;
	}
}*PTImUserLogin_Api, TImUserLogin_Api;


/** �û��Զ�����Ϣ */
typedef struct tagTImSelfDefInfo_Api
{ 
	s8 achNO[ KMTAPI_IM_MAX_ID_LEN + 1];                            ///< �û�Ψһ��ʶ
	s8 achNickName[KMTAPI_MAX_DEV_TYPE_NAME_LEN + 1]; ///< �û��ǳ�	
	u16 wPictureIndex;						                                        ///< ����ͼ�����	
	BOOL32  bCustomePic;                                                         ///< �Ƿ�ʹ���Զ���ͷ��
public:
	tagTImSelfDefInfo_Api() { memset( this, 0, sizeof(tagTImSelfDefInfo_Api) ); }
}*PTImSelfDefInfo_Api, TImSelfDefInfo_Api;

/** �û��Զ���ͼƬ */
typedef struct tagTImSelfDefPic_Api
{
	u32   dwCustomPicSize;                                                                      ///< ʹ�õ��Զ���ͷ�����ݴ�С
	s8    abyCustomPicData[KMTAPI_IM_MAX_HEAD_PORTRAIT_LEN + 1]; ///< �Զ���ͷ������
public:
	tagTImSelfDefPic_Api() { memset( this, 0, sizeof(tagTImSelfDefPic_Api) ); }
}*PTImSelfDefPic_Api, TImSelfDefPic_Api;

/** ����Ϣ */
typedef struct tagTImGroupInfo_Api
{
	s8 achGroupSn[KMTAPI_IM_MAX_U64STRING_LEN + 1];           ///< �û������
	s8 achGroupName[KMTAPI_IM_MAX_GROUPNAME_LEN + 1];  ///< �û�������
	s8 achParentGroupSn[KMTAPI_IM_MAX_U64STRING_LEN + 1]; ///< �������
	u16 wGroupLevel;                                                                    ///< ��Ĳ㼶
public:
	tagTImGroupInfo_Api() { memset( this, 0, sizeof(tagTImGroupInfo_Api) ); }
}*PTImGroupInfo_Api, TImGroupInfo_Api;

/** ���б���Ϣ */
typedef struct tagTImGroupList_Api
{
	u32 dwArraySize;                                                                                ///< �б����
	TImGroupInfo_Api atArray[KMTAPI_IM_MAX_GROUPINFO_LIST_LEN]; ///< �б���Ϣ
public:
	tagTImGroupList_Api() { memset( this, 0, sizeof(tagTImGroupList_Api) ); }
}*PTImGroupList_Api, TImGroupList_Api;

/** ���к� */
typedef struct tagTImSn_Api 
{
	s8 achSn[KMTAPI_IM_MAX_U64STRING_LEN + 1];  ///<�����к�
public:
	tagTImSn_Api() { memset( this, 0, sizeof(tagTImSn_Api) ); }
}*PTImSn_Api, TImSn_Api;

/** �ƶ���Ա��Ϣ */
typedef struct tagTImMoveMember_Api
{
	s8 achMemberSn[KMTAPI_IM_MAX_U64STRING_LEN + 1];               ///< ��Ա���
	s8 achOldGroupSn[KMTAPI_IM_MAX_U64STRING_LEN + 1];             ///< �ϵ������к�
	s8 achNewGroupSn[KMTAPI_IM_MAX_U64STRING_LEN + 1];            ///< �µ������к�
public:
	tagTImMoveMember_Api() { memset( this, 0, sizeof(tagTImMoveMember_Api) ); }
}*PTImMoveMember_Api, TImMoveMember_Api;

/** �û�״̬ */
typedef struct tagTImUserState_Api
{
	s8 achNO[ KMTAPI_IM_MAX_ID_LEN + 1];	                     ///< �û�Ψһ��ʶ
	EmMtOnlineState_Api emState;                                     ///< �û�״̬
public:
	tagTImUserState_Api() 
	{ 
		memset( this, 0, sizeof(tagTImUserState_Api) ); 
		emState = EM_STATE_OFFLINE_Api;                            
	}
}*PTImUserState_Api, TImUserState_Api;

/** �����Լ���״̬ */
typedef struct tagTImSetUserState_Api
{
	s8 achNO[ KMTAPI_IM_MAX_ID_LEN + 1];                    ///< �û�Ψһ��ʶ
	EmMtOnlineState_Api emState;                                    ///< �û�״̬
	BOOL32            bStateValid;                                         ///< �û�״̬�Ƿ���Ч
	BOOL32            bGkConnected;                                   ///< �Ƿ�����GK
	BOOL32            bGkConnectedValid;                           ///< GK����״̬�Ƿ���Ч
public:
	tagTImSetUserState_Api() 
	{ 
		memset( this, 0, sizeof(tagTImSetUserState_Api) ); 
		emState            = EM_STATE_OFFLINE_Api;
		bGkConnected      = FALSE;                          ///< Ĭ��û������GK
		bStateValid       = TRUE;
		bGkConnectedValid = TRUE;
	}
}*PTImSetUserState_Api, TImSetUserState_Api;

/** �豸����״̬ */
typedef struct tagTDeviceOnlineState_Api
{
	s8 achNO[ KMTAPI_IM_MAX_ID_LEN + 1];	 ///< �û�Ψһ��ʶ
	EmMtImTerminalType_Api emDeviceType; ///< �豸����
	EmMtOnlineState_Api emState;                 ///< ����״̬
	EmMtOnlineState_Api emMaxState;          ///< ��߼�������״̬	
	BOOL32 bSelf;                                          ///< �Ƿ�����
	BOOL32 bFirst;                                         ///< �Ƿ��һ��״̬�ı�(�����һ�ε�¼��״̬�ı�)
	BOOL32 bFileShare;                                  ///< P2P�ļ���������
	BOOL32 bAudioCapability;                       ///< ��Ƶ����
	BOOL32 bVideoCapability;                       ///< ��Ƶ����
	BOOL32 bGkConnected;                          ///< ����GK��
	BOOL32 bMaxAudio;                               ///< ��Ƶ�ɺ���(������һ�ն˼�����GK������Ƶ����)
	BOOL32 bMaxVideo;                               ///< ��Ƶ�ɺ���(������һ�ն˼�����GK������Ƶ����)
	BOOL32 bLoginBeforeMe;                       ///< �Ƿ����Լ�֮ǰ��¼(������bFirstΪTRUE, ����ʱ����Բ���)
public:
	tagTDeviceOnlineState_Api() 
	{ 
		memset( this, 0, sizeof(tagTDeviceOnlineState_Api) ); 
		emState = EM_STATE_OFFLINE_Api;
		emMaxState = EM_STATE_OFFLINE_Api;
	}
}*PDeviceOnlineState_Api, TDeviceOnlineState_Api;

/** �û�״̬�б� */
typedef struct tagTImUserStateList_Api
{
	u32 dwArraySize;                                                                                   ///< �б����
	TImUserState_Api atArray[KMTAPI_IM_MAX_ONLINESTATE_LIST_NUM]; ///< �б���Ϣ
public:
	tagTImUserStateList_Api() { memset( this, 0, sizeof(tagTImUserStateList_Api) ); }
}*PTImUserStateList_Api, TImUserStateList_Api;

/** �û����ڵ��ն�״̬ */
typedef struct tagTSubState_Api
{
	EmMtImTerminalType_Api  emMtType; ///< �û����ڵ��ն�����
	EmMtOnlineState_Api     emMtState;    ///< �û��ڸ��ն������ϵ�״̬	
	BOOL32 bAudioCapability;                    ///< ��Ƶ����(Ӳ��)
	BOOL32 bVideoCapability;                    ///< ��Ƶ����(Ӳ��)
	BOOL32 bGkConnected;                       ///< �Ƿ�����GK	
public:
	tagTSubState_Api()
	{
		memset( this, 0, sizeof(tagTSubState_Api) );
		emMtState = EM_STATE_OFFLINE_Api;
		bAudioCapability = FALSE;
		bVideoCapability = FALSE;
		bGkConnected = FALSE;
	}
}*PTSubState_Api, TSubState_Api;

/** �û�״̬( ����4���ն����� ) */
typedef struct tagTImUserStateEx_Api
{
	s8                    achNO[ KMTAPI_IM_MAX_ID_LEN + 1];	      ///< �û�Ψһ��ʶ
	EmMtOnlineState_Api   emState;                                         ///< �û�״̬(���״̬)
	BOOL32                bMaxAudio;                                             ///< ������Ƶ������������GK
	BOOL32                bMaxVideo;                                             ///< ������Ƶ������������GK
	u32					  dwStateCount;                                           ///< ״̬����
	TSubState_Api         atMtState[KMTAPI_IM_MAX_MT_TYPE]; ///< tl, tp, td, ts״̬
public:
	tagTImUserStateEx_Api() 
	{ 
		memset( this, 0, sizeof(tagTImUserStateEx_Api) ); 
		emState = EM_STATE_OFFLINE_Api;
		bMaxAudio = FALSE;
		bMaxVideo = FALSE;
	}
}*PTImUserStateEx_Api, TImUserStateEx_Api;

/** �û�״̬�б�( �����ն����� ) */
typedef struct tagTImUserStateListEx_Api
{
	u32 dwArraySize;                                                                                      ///< �б����
	TImUserStateEx_Api atArray[KMTAPI_IM_MAX_ONLINESTATE_LIST_NUM]; ///< �б���Ϣ
public:
	tagTImUserStateListEx_Api() { memset( this, 0, sizeof(tagTImUserStateListEx_Api) ); }
}*PTImUserStateListEx_Api, TImUserStateListEx_Api;

/** ��Ե����������� */
typedef struct tagTImChatBuf_Api
{
	u16 wMsgLen;                                                                               ///< ��Ϣ����
	s8  achMsgBody[KMTAPI_IM_MAX_SENDMESSAGE_BUF_LEN + 1]; ///< ��Ϣ��
public:
	tagTImChatBuf_Api() { memset( this, 0, sizeof(tagTImChatBuf_Api) ); }
}*PTImChatBuf_Api, TImChatBuf_Api;

/** ��Ե�������Ϣ */
typedef struct tagTImP2PChatMessage_Api
{
	s8 achDstNO[ KMTAPI_IM_MAX_ID_LEN + 1];    ///< �û�Ψһ��ʶ
	s8 achSrcNO[ KMTAPI_IM_MAX_ID_LEN + 1];    ///< �û�Ψһ��ʶ
	EmMtImTerminalType_Api emImMtType;          ///< ��Ϣ�������ն�����
	u32  dwContextId;                                            ///< ������Ϣ�û��Զ�������
	TImChatBuf_Api tMessageBuf;                         ///< ��Ϣ��
    s8 achMsgID[KMTAPI_BUF_32_LEN+1];                           //��ϢId
public:
	tagTImP2PChatMessage_Api() { memset( this, 0, sizeof(tagTImP2PChatMessage_Api) ); }
}*PTImP2PChatMessage_Api, TImP2PChatMessage_Api;

/** ID */
typedef struct tagTImNO_Api
{
	s8 achNO[ KMTAPI_IM_MAX_ID_LEN + 1];       ///< ����id
public:
	tagTImNO_Api() { memset( this, 0, sizeof(tagTImNO_Api) ); }
}*PTImNO_Api, TImNO_Api;

/** ID�б� */
typedef struct tagTImNOList_Api
{
	u32 dwArraySize;                                                            ///< �б����
	TImNO_Api atArray[KMTAPI_IM_MAX_USER_LIST_NUM]; ///< �б���Ϣ
public:
	tagTImNOList_Api() { memset( this, 0, sizeof(tagTImNOList_Api) ); }
}*PTImNOList_Api, TImNOList_Api;


/** Room ID */
typedef struct tagTRoomId_Api
{
	s8 achRoomId[KMTAPI_IM_MAX_CHATROOM_ID_LEN + 1]; ///< RoomID
public:
	tagTRoomId_Api(){ memset( this, 0, sizeof(*this) ); }
}*PTRoomId_Api, TRoomId_Api;

/** ����������Ϣ�ṹ�� */
typedef struct tagTImMultiChatCreateInfo_Api
{
	s8 achChatName[KMTAPI_IM_MAX_MULTI_CHAT_NAME_LEN + 1]; ///< ��������Ự����(�ɲ���); 
	s8 achConfE164[KMTAPI_MAX_CONF_E164_LEN + 1];                      ///< �����E164�ţ���EmMultiChatTypeΪ��������ʱ��������
	s8 achRoomId[KMTAPI_IM_MAX_CHATROOM_ID_LEN + 1];             ///< Ⱥ���ҵ�ID(������һ������ȷ���Ƿ�Ϊ��ͬ��������)
	s8 achInviterNO[ KMTAPI_IM_MAX_ID_LEN + 1];                             ///< �����˵�ID
	u32 dwSessionID;                                                                            ///< �ỰID
	u32 dwClientID;                                                                              ///< �������˻Ựʱ���ͻ���ָ����Ψһ��־	
	BOOL32  bPersistent;                                                                      ///< �Ƿ�̶�Ⱥ
	BOOL32  bOwner;                                                                           ///< �Ƿ�Ⱥ�Ĵ����ˣ�
	EmMtMultiChatType_Api emMultiChatType;                                   ///< ��������Ự, ��ͨ���ͣ���������....
public:
	tagTImMultiChatCreateInfo_Api() 
	{ memset( this, 0, sizeof(tagTImMultiChatCreateInfo_Api) ); emMultiChatType = EM_MULTICHAT_NORMAL_Api; }
}*PTImMultiChatCreateInfo_Api, TImMultiChatCreateInfo_Api;

/** �����������ӳ�Ա�ṹ�� */
typedef struct tagTImMultiChatMemberInfo_Api
{
	u32 dwSessionID;
	TImNOList_Api tNOList;                  ///< Ҫ��ӵĶ�������ĳ�Ա  	
	TRoomId_Api tRoomId;                    ///< ��ѡ�ģ�room id
public:
	tagTImMultiChatMemberInfo_Api() { memset( this, 0, sizeof(tagTImMultiChatMemberInfo_Api) ); }
}*PTImMultiChatMemberInfo_Api, TImMultiChatMemberInfo_Api;

/** �����������ӳ�Ա�ṹ��Ex */
typedef struct tagTImMultiChatMemberInfoEx_Api
{
	u32   dwSessionID;
	s8    achNO[ KMTAPI_IM_MAX_ID_LEN + 1]; ///< ����id
	BOOL32  bOwner;                                        ///< �Ƿ������Ҵ�����
	BOOL32  bSelf;                                             ///< �Ƿ��Լ�
	EmMtImTerminalType_Api  emMtType;        ///< �ն�����
	EmMtOnlineState_Api     emState;               ///< �ն�״̬
	EmMtOnlineState_Api     emMaxState;        ///< ��߼�������״̬
	TRoomId_Api             tRoomId;
public:
	tagTImMultiChatMemberInfoEx_Api() { memset( this, 0, sizeof(tagTImMultiChatMemberInfoEx_Api) ); }
}*PTImMultiChatMemberInfoEx_Api, TImMultiChatMemberInfoEx_Api;

/** ����������Ϣ */
typedef struct tagTImMultiChatMessage_Api
{
	u32 dwSessionID;                                           ///< ��������ỰID
	u32        dwContextId;                                   ///< �û��Զ�������
	s8 achSrcNO[ KMTAPI_IM_MAX_ID_LEN + 1]; ///< ��ϢԴ
	EmMtImTerminalType_Api emImMtType;       ///< �ն�����
	TImChatBuf_Api tMessageBuf;                       ///< ��Ϣ��  
	TRoomId_Api    tRoomId;                               ///< ��ѡ��
    s8 achMsgID[KMTAPI_BUF_32_LEN+1];                        ///��ϢId
public:
	tagTImMultiChatMessage_Api() { memset( this, 0, sizeof( tagTImMultiChatMessage_Api)); }
}*PTImMultiChatMessage_Api, TImMultiChatMessage_Api;

/** �������췢��ͼƬ��Ψһ��־ */
typedef struct tagTMultiChatPicId_Api
{
	s8                      achNO[ KMTAPI_IM_MAX_ID_LEN + 1]; ///< �û�Ψһ��ʶ
	s8                      achSid[KMTAPI_IM_MAX_SID_LEN + 1]; ///< sid
	u32                     dwSessionID;                                       ///< ��������ỰID
	EmMtImTerminalType_Api  emDeviceType;                     ///< �豸����
	TRoomId_Api             tRoomId;                                       ///< ��ѡ��	
public:
	tagTMultiChatPicId_Api()
	{
		memset( this, 0, sizeof(*this) );
	}
}*PTTMultiChatPicId_Api, TMultiChatPicId_Api;

/** ����״̬���� */
typedef struct tagTDeviceOnlineStateCacheItem_Api
{
	u32 dwApp;                             ///< �����˺�
	TDeviceOnlineState_Api tStatus;        ///< ����״̬	
public:
	tagTDeviceOnlineStateCacheItem_Api()
	{
		dwApp = 0;
	}
}*PTDeviceOnlineStateCacheItem_Api, TDeviceOnlineStateCacheItem_Api;

/** ����״̬�����б� */
typedef struct tagTDeviceOnlineStateCacheList_Api
{
	u32                             dwArraySize;                                                                                           ///< �б��С
	TDeviceOnlineStateCacheItem_Api atArray[KMTAPI_IM_MAX_MEMBER_STATUS_CACHE_NUM+1]; ///< ����״̬�����б�
public:
	tagTDeviceOnlineStateCacheList_Api() { dwArraySize = 0; }
}*PTDeviceOnlineStateCacheList_Api, TDeviceOnlineStateCacheList_Api;

/** �ļ��������� */
typedef struct tagTImFileShareReq_Api
{
	s8     achDestNO[ KMTAPI_IM_MAX_ID_LEN + 1];     ///< �Զ˵�Im�˺�
	s8     achFilePath[KMTAPI_IM_SENDER_PATH_LEN + 1]; ///< �ļ�����·����
	u32    nFileType;                                                       ///< 0: �ļ��У�1���ļ���2��ͼƬ
	u32    dwFileSize;                                                      ///< �ļ���С(��λ���ֽ�)
	u32	   dwContextid;                                                 ///< �ϲ�Ӧ�����õ�������id
	BOOL32 bOverWrite;                                                 ///< ָ�����շ��Ƿ�Ҫ�������е�ͬ���ļ�
public:
	tagTImFileShareReq_Api() 
	{ 
		memset( this, 0, sizeof(tagTImFileShareReq_Api) ); 
		nFileType = 1;
	}
}*PTImFileShareReq_Api, TImFileShareReq_Api;

/** �ļ�����offer���� */
typedef struct tagTImFileShareOfferInfo_Api
{
	s8     achPeerNO[ KMTAPI_IM_MAX_ID_LEN + 1];       ///< �Զ˵�Im�˺�
	s8     achFileName[KMTAPI_IM_RECV_PATH_LEN + 1]; ///< �ļ���(����·��)
	u32    nFileType;                                                         ///< 0: �ļ��У�1���ļ���2��ͼƬ
	u32    dwFileSize;                                                        ///< �ļ���С(��λ���ֽ�)
	BOOL32 bSender;                                                       ///< �Լ��Ƿ��Ƿ�����
public:
	tagTImFileShareOfferInfo_Api() 
	{ 
		memset( this, 0, sizeof(tagTImFileShareOfferInfo_Api) ); 
		nFileType = 1;
	}
}*PTImFileShareOfferInfo_Api, TImFileShareOfferInfo_Api;

/** ���������ļ��������� */
typedef struct tagTImGroupChatFileShareReq_Api
{
	s8     achFilePath[KMTAPI_IM_SENDER_PATH_LEN + 1]; ///< �ļ�����·����
	u32    dwSessionID;                                                  ///< ��������id
	u32    nFileType;                                                       ///< 0: �ļ��У�1���ļ���2��ͼƬ
	u32    dwFileSize;                                                      ///< �ļ���С(��λ���ֽ�)
	u32		dwContextid;
	s8     achPicsessionid[ KMTAPI_BUF_32_LEN + 1 ];
	TRoomId_Api tRoomId;                                            ///< ��ѡ��
public:
	tagTImGroupChatFileShareReq_Api() { memset( this, 0, sizeof(*this) ); nFileType = 1; }
}*PTImGroupChatFileShareReq_Api, TImGroupChatFileShareReq_Api;

/** ��������Ϣ */
typedef struct tagTImChatRoomInfo_Api
{
	u32     dwSessionID;
	s8      achChatName[KMTAPI_IM_MAX_MULTI_CHAT_NAME_LEN + 1];
	TRoomId_Api tRoomId;
public:
	tagTImChatRoomInfo_Api()
	{
		memset( this, 0, sizeof(*this) );
	}
}*PTImChatRoomInfo_Api, TImChatRoomInfo_Api;

/** �ܾ��ṹ�� */
typedef struct tagTDeclineInfo_Api
{
	s8 achChatName[KMTAPI_IM_MAX_MULTI_CHAT_NAME_LEN + 1]; ///< ��������Ự����(�ɲ���); 
	s8 achRoomId[KMTAPI_IM_MAX_CHATROOM_ID_LEN + 1];             ///< Ⱥ���ҵ�ID(������һ������ȷ���Ƿ�Ϊ��ͬ��������)   
	s8 achDeclineNO[ KMTAPI_IM_MAX_ID_LEN + 1];                            ///< �ܾ��˵�ID
	EImDeclineReason_Api   emReason;                                                 ///< �ܾ���ԭ��
public:
	tagTDeclineInfo_Api() 
	{ memset( this, 0, sizeof(tagTDeclineInfo_Api) ); }
}*PTDeclineInfo_Api, TDeclineInfo_Api;

/** ���������Ա�б�(�ǽ�����������) */
typedef struct tagTImMultiChatRosterItem_Api
{
	s8      achNO[ KMTAPI_IM_MAX_ID_LEN + 1]; ///< ����id
	BOOL32  bOwner;                                          ///< �Ƿ������Ҵ�����
	BOOL32  bSelf;                                               ///< �Ƿ��Լ�
public:
	tagTImMultiChatRosterItem_Api() { memset( this, 0, sizeof(tagTImMultiChatRosterItem_Api) ); }
}*PTImMultiChatRosterItem_Api, TImMultiChatRosterItem_Api;

/** ��������RosterItem�б� */
typedef struct tagTImMultiChatRosterItemList_Api
{
	u32                            dwSessionId;                           
	u32                            dwArraySize;                              
	TImMultiChatRosterItem_Api     atArray[KMTAPI_IM_MAX_ROSTER_ITEMS_PER_BATCH];   
	TRoomId_Api                    tRoomId;

public:
	tagTImMultiChatRosterItemList_Api() { memset( this, 0, sizeof(tagTImMultiChatRosterItemList_Api) ); }
}*PTImMultiChatRosterItemList_Api, TImMultiChatRosterItemList_Api;

/** ����״̬ */
typedef struct tagTImCharState_Api
{
	s8 achPerrNO[ KMTAPI_IM_MAX_ID_LEN + 1]; ///< �Զ˵�Im�˺�
	EmMtImTerminalType_Api emImMtType;         ///< �ն�����
	EmImCharState_Api       emCharState;             ///< ����״̬
public:
	tagTImCharState_Api() 
	{ 
		memset( this, 0, sizeof(tagTImCharState_Api) ); 
	}
}*PTImCharState_Api, TImCharState_Api;

/** ���� */
typedef  struct  tagTImSplash_Api
{
	s8                     achPeerNO[ KMTAPI_IM_MAX_ID_LEN + 1];  ///< �Զ˵�Im�˺�
	EmMtImTerminalType_Api emImMtType;                              ///< �ն�����
	u32                    dwSplashType;                                            ///< ��������
public:
	tagTImSplash_Api( ) { memset( this, 0, sizeof(*this) ); }
}*PTImSplash_Api, TImSplash_Api;

/** �Զ��������� */
typedef struct tagTImCustomCfgItem_Api
{
	s8 achKey[KMTAPI_IM_MAX_CONFIG_KEY_LEN + 1];
	s8 achValue[KMTAPI_IM_MAX_CONFIG_VALUE_LEN + 1];	
public:
	tagTImCustomCfgItem_Api()
	{
		memset( this, 0, sizeof(*this) );
	}
}*PTImCustomCfgItem_Api, TImCustomCfgItem_Api;

/** �Զ������� */
typedef struct tagTImCustomCfg_Api
{
	TImCustomCfgItem_Api atItems[KMTAPI_IM_MAX_CONFIG_ITEMS_PER_BATCH];
	u32 dwItemsCnt;     ///< �����С
	BOOL32 bGet;        ///< �ǻ�ȡ��������
public:
	tagTImCustomCfg_Api()
	{
		dwItemsCnt = 0;
		bGet       = FALSE;
	}
}*PTImCustomCfg_Api, TImCustomCfg_Api;

/** �����Ƿ����������� */
typedef struct tagTImScreenChatroom_Api
{
	BOOL32  bScreen;                                      ///< �Ƿ�����( TRUE, ���Σ� FALSE, ȡ������ )
	s8    achRoomId[KMTAPI_IM_MAX_CHATROOM_ID_LEN + 1];   ///< ���ε��������room id(��session id)
public:
	tagTImScreenChatroom_Api()
	{
		memset( this, 0, sizeof(*this) );
	}
}*PTImScreenChatroom_Api, TImScreenChatroom_Api;

/*�������б�*/
typedef struct tagTImScreenedChatrooms_Api
{
	s8 aachRoomId[KMTAPI_BUF_32_LEN][KMTAPI_IM_MAX_CHATROOM_ID_LEN + 1];
	u8 byCnt;
public:
	tagTImScreenedChatrooms_Api()
	{
		memset( this, 0, sizeof(*this) );
	}
}*PTImScreenedChatrooms_Api, TImScreenedChatrooms_Api;

/** �����Ƿ�����������(��ʵ���Σ�������) */
typedef struct tagTImScreenChatroomR_Api
{
	BOOL32 bScreen;                                                                               ///< �Ƿ�����( TRUE, ���Σ� FALSE, ȡ������ )
	s8     aachRoomIds[KMTAPI_IM_MAX_CHATROOM_SCREEN_NUM][KMTAPI_IM_MAX_CHATROOM_ID_LEN + 1]; ///< ���ε��������room ids(��session ids)
	u32    dwCount;
public:
	tagTImScreenChatroomR_Api()
	{
		memset( this, 0, sizeof(*this) );
	}
}*PTImScreenChatroomR_Api, TImScreenChatroomR_Api;

/** ������Ϣ */
typedef struct tagTMTWbParseKedaDept_Api
{
	u32 dwDepartmentId;                                                ///< �硰51��
	s8  achDepartmentName[KMTAPI_BUF_128_LEN + 1]; ///< ���������硰���������
	s8  achFullPath[KMTAPI_BUF_1024_LEN+1];				  ///< ��������·��
	s8  achDeptPosition[KMTAPI_BUF_128_LEN+1];		      ///< ����ְλ

public:
	tagTMTWbParseKedaDept_Api(){ memset(this, 0, sizeof(tagTMTWbParseKedaDept_Api) ); }
}*PTMTWbParseKedaDept_Api, TMTWbParseKedaDept_Api;

/** ������Ϣ�б� */
typedef struct tagTMTWbParseKedaDepts_Api
{
	u32						dwDeptNum;					                 	         	                                                     ///< ������Ŀ��һ���˿���ͬʱ���ڶ�����ţ�
	TMTWbParseKedaDept_Api	atMtWbParseKedaDept[KMTAPI_IM_MAX_WBPARSEKEDADEPT_NUM];	 ///< ������ϸ��Ϣ
public:
	tagTMTWbParseKedaDepts_Api(){ memset(this, 0, sizeof(tagTMTWbParseKedaDepts_Api) ); }
}*PTMTWbParseKedaDepts_Api, TMTWbParseKedaDepts_Api;

/** �û���Ϣ���˽ṹ�����ֽ���Ϊ1411����OSP�������ÿ�δ�15�� */
typedef struct tagTMTWbParse_Keda_EntUser_Api
{
	s8 achMoid[KMTAPI_BUF_64_LEN + 1];                     ///< �˺�moid
	s8 achJid[KMTAPI_BUF_256_LEN + 1];                       ///< xmpp�˺�
	s8 achAccount[KMTAPI_BUF_128_LEN + 1];               ///< �Զ����˺�
	s8 achentMail[KMTAPI_BUF_128_LEN + 1];                ///< ����,΢����¼�˺�
	s8 achE164[KMTAPI_BUF_64_LEN + 1];                       ///< E164��
	s8 achMobileNum[KMTAPI_BUF_64_LEN + 1];            ///< ��ϵ�绰
	s8 achUserDomainMoid[KMTAPI_BUF_64_LEN + 1];    ///< ��ҵmoid
	s8 achUserDomainName[KMTAPI_BUF_128_LEN + 1]; ///< ��ҵ��
	s8 achDeviceGuid[KMTAPI_BUF_64_LEN + 1];		     ///< �ն�GUID
	s8 achNuServerID [KMTAPI_BUF_64_LEN + 1];		     ///< ����NU������ID
	s8 achDeviceType[KMTAPI_BUF_64_LEN + 1];		     ///< �ն�����
	BOOL32 bEnable;				                                         ///< ����/���ã�0/1
	BOOL32 bLimited;                                                     ///< �Ƿ�����
	s8 achentName[KMTAPI_BUF_128_LEN + 1];		  	    ///< ����
	s8 achBrief[KMTAPI_BUF_512_LEN + 1];     		        ///< һ�仰����
	s8 achJobNum[KMTAPI_BUF_64_LEN + 1];			        ///< �û����/����
	BOOL32 bMale;                                                        ///< �Ա�(1/0,��/Ů)
	s8 achextNum[KMTAPI_BUF_128_LEN + 1];               ///< �ֻ�
	s8 achSeat[KMTAPI_BUF_256_LEN + 1];				        ///< ��λ
	s8 achOfficeLocation[KMTAPI_BUF_512_LEN + 1];	    ///< �칫��ַ
	s8 achDateOfBirth[KMTAPI_BUF_64_LEN + 1];		    ///< ��������
	s8 achFax[KMTAPI_BUF_64_LEN + 1];				        ///< ����
	s8 achRestrictUsedOn[KMTAPI_BUF_256_LEN + 1];	///< E164�����Ƶ�¼���豸���ͣ��б�
	s8 achPortrait32[KMTAPI_BUF_256_LEN + 1];		        ///< 32λͷ��ʵ�ʵ�ַ
	s8 achPortrait40[KMTAPI_BUF_256_LEN + 1];  		    ///< 40λͷ��
	s8 achPortrait64[KMTAPI_BUF_256_LEN + 1];  		    ///< 64λͷ��
	s8 achPortrait128[KMTAPI_BUF_256_LEN + 1]; 		    ///< 128λͷ��
	s8 achPortrait256[KMTAPI_BUF_256_LEN + 1]; 		    ///< 128λͷ��
	BOOL32 bEnableWeibo;                                            ///< ΢��Ȩ��(0/1,û��/��)
	BOOL32 bEnableMeetingsms;                                   ///< ���ͻ�ܶ���Ȩ��(0/1,û��/��)
	BOOL32 bEnableMeeting;                                         ///< �������Ȩ��(0/1,û��/��)
	BOOL32 bEnableHD;                                                 ///< ����Ȩ��(0/1,û��/��)
    BOOL32 bEnableFullHD;                                           ///< ȫ����Ȩ��(0/1,û��/��)
    BOOL32 bEnableUltraHD;                                         ///< 4KȨ��(0/1,û��/��)
	BOOL32 bEnableCall;                                                ///< �绰����Ȩ��(0/1,û��/��)
	BOOL32 bEnableRoam;                                            ///< ����Ȩ��(0/1,û��/��)
	BOOL32 bEnableSatellite;                                         ///< ������·Ȩ��(0/1,û��/��) 
	BOOL32 bEnableSatellitep2p;                                   ///< ������·��Ե����Ȩ��(0/1,û��/��)
	BOOL32 bWeiboAdmin;   	                                       ///< ΢������ԱȨ��(0/1,û��/��)
	BOOL32 bMeetingAdmin;   	                                   ///< �������ԱȨ��(0/1,û��/��) 
	BOOL32 bEnableBMC;   	                                       ///< BMCȨ��(0/1,û��/��)  
	BOOL32 bEnableUMC;   	                                       ///< UMCȨ��(0/1,û��/��)
	BOOL32 bEnableDCS;                                              ///< DCSȨ��(0/1,û��/��)
	BOOL32 bEnableVRS;   	                                           ///< VRSȨ��(0/1,û��/��)
	BOOL32 bEnableNM;   		                                       ///< NMȨ��(0/1,û��/��)
	BOOL32 bEnableVenueMonitor;   	    	                   ///< �᳡���Ȩ��(0/1,û��/��)
	BOOL32 bDefaultUserDomainAdmin;   		               ///< Ĭ�ϵ��û������Ա(0/1,û��/��)
	BOOL32 bEnableOut;   		                                       ///< ����Ȩ��(0/1,û��/��)
	BOOL32 bEnableIncoming;                                      ///< ���Ȩ��(0/1,û��/��)
	BOOL32 bDCSAdmin;   		                                      ///< dcs����Ա(0/1,û��/��)
	BOOL32 bVRSAdmin;   		                                      ///< vrs����Ա(0/1,û��/��)
	BOOL32 bNMAdmin;   		                                      ///< nm����Ա(0/1,û��/��)
	BOOL32 bEnableVideo;   		                                  ///< VRS��Ȩ��(¼��)(0/1,û��/��)
	BOOL32 bEnableLive;   		                                      ///< VRS��Ȩ��(ֱ��)(0/1,û��/��)
	BOOL32 bEnablePlay;   		                                      ///< VRS��Ȩ��(����)(0/1,û��/��)
	BOOL32 bCMSApproval;   		                              ///< ��ܻ�������Ȩ��(0/1,û��/��)	
	BOOL32 bEditName;   		                              ///< �޸�����Ȩ��(0/1,û��/��)
    BOOL32 bEnableUnicat;                                   ///VRS��Ȩ��(�㲥)
    BOOL32 bEnableDownLoad;                                 ///VRS��Ȩ��(����)
	TMTWbParseKedaDepts_Api  tMtWbParseKedaDepts; ///< ���ڲ�����Ϣ
public:
	tagTMTWbParse_Keda_EntUser_Api() { memset( this, 0, sizeof(tagTMTWbParse_Keda_EntUser_Api) ); }
}*PTMTWbParse_Keda_EntUser_Api, TMTWbParse_Keda_EntUser_Api;

/** ��Ա��Ϣ */
typedef struct tagTImMemberInfo_Api
{
public:
	s8 achMemberSn[KMTAPI_IM_MAX_U64STRING_LEN + 1];     ///< ��Ա���к�
	s8 achGroupSn[KMTAPI_IM_MAX_U64STRING_LEN + 1];		 ///< ��Ա������������
	s8 achMemberNO[ KMTAPI_IM_MAX_ID_LEN + 1];                ///< ��Ա��Xmpp Jid��(�û���@����)
	s8 achMarkName[KMTAPI_MAX_DEV_TYPE_NAME_LEN + 1]; ///< ��Ա���� 
	EmMtMemberType_Api emMemberType;			                     ///< ��Ա����
	u16 wBitRate;                                                                        ///< ��������
	TMTWbParse_Keda_EntUser_Api tWeiboInfo;                         ///< ��ϵ��΢����Ϣ
	BOOL32  bNoQuery;                                                              ///< �Ƿ񲻲�Account	
public:
	tagTImMemberInfo_Api() { memset( this, 0, sizeof(tagTImMemberInfo_Api) ); }
}*PTImMemberInfo_Api, TImMemberInfo_Api;

/** ��Ա�б� */
typedef struct tagTImMemberList_Api
{
	u32 dwArraySize;                                                                                           ///< ��Ա����
	TImMemberInfo_Api atArray[KMTAPI_IM_MAX_QUERY_USERONLINE_NUM]; ///< ��Ա�б�
public:
	tagTImMemberList_Api() { memset( this, 0, sizeof(tagTImMemberList_Api) ); }
}*PTImMemberList_Api, TImMemberList_Api;

/** ���ѵ���ϸ��Ϣ */
typedef struct tagTImMemberFullInfo_Api
{
	TImMemberInfo_Api tMemberinfo;        ///< ���ѻ�����Ϣ 
	EmMtOnlineState_Api emMemberState; ///< ���ѵ�״̬��Ϣ
	BOOL32 bMaxAudio;                              ///< ������Ƶ������������GK
	BOOL32 bMaxVideo;                              ///< ������Ƶ������������GK
	u32			  dwStateCount;
	TSubState_Api atMtState[KMTAPI_IM_MAX_MT_TYPE]; ///< tl, tp, td, ts״̬
public:
	tagTImMemberFullInfo_Api() { memset( this, 0, sizeof(tagTImMemberFullInfo_Api) ); }
}*PTImMemberFullInfo_Api, TImMemberFullInfo_Api;

typedef struct tagTPersistentChatroomItem_Api
{
	s8 achRoomId[KMTAPI_IM_MAX_CHATROOM_ID_LEN + 1];           ///< �����ҵ�ID(������һ������ȷ���Ƿ�Ϊ��ͬ��������)
	s8 achChatName[KMTAPI_IM_MAX_MULTI_CHAT_NAME_LEN + 1];     ///< ����������

public:
	tagTPersistentChatroomItem_Api()
	{
		memset( this, 0, sizeof(*this) );
	}
}*PTPersistentChatroomItem_Api, TPersistentChatroomItem_Api;

/** ֪ͨ�ϴε�¼����Ĺ̶���������Ϣ��������뱣��������� */
typedef struct tagTPersistentChatroomList_Api
{
	u32                         dwArraySize;
	TPersistentChatroomItem_Api atArray[KMTAPI_IM_MAX_PERSISTENT_CHATROOM_NUM];

public:
	tagTPersistentChatroomList_Api() { dwArraySize = 0; }
}*PTPersistentChatroomList_Api, TPersistentChatroomList_Api;

/** ������ӵĵ�����Ա��Ϣ */
typedef struct tagTBatchAddContactsItem_Api
{
public:
	s8 achMemberNO[ KMTAPI_IM_MAX_ID_LEN + 1];	       ///< ��Ա��Xmpp Jid��(�û���@����)
	s8 achMarkName[KMTAPI_MAX_DEV_TYPE_NAME_LEN + 1];  ///< ��Ա���� 
	s8 achE164[KMTAPI_BUF_64_LEN + 1];                 ///< E164��
	EmMtMemberType_Api emMemberType;			 ///< ��Ա����
	u16 wBitRate;                                ///< ��������

public:
	tagTBatchAddContactsItem_Api() { memset( this, 0, sizeof(tagTBatchAddContactsItem_Api) ); }
}*PTBatchAddContactsItem_Api, TBatchAddContactsItem_Api;

/** ���������ϵ�˵�һ���� */
typedef struct tagTBatchAddContacts_Api
{
	TBatchAddContactsItem_Api atBatchContacts[KMTAPI_IM_MAX_BATCH_USERS_NUM];   ///< ������ӵ���ϵ��
	u32                       dwCount;                                          ///< ������ϵ�˵ĸ���
	s8                        achDestGroupSn[KMTAPI_IM_MAX_U64STRING_LEN + 1];  ///< ��ӵ��ĸ���

public:
	tagTBatchAddContacts_Api()
	{
		memset( this, 0, sizeof(*this) );
	}
}*PTBatchAddContacts_Api, TBatchAddContacts_Api;

/** ����ɾ����ϵ�� */
typedef struct tagTBatchDelContacts_Api
{
public:
	TImSn_Api atBatchContacts[KMTAPI_IM_MAX_BATCH_USERS_NUM]; ///< ����ɾ������ϵ��
	u32 dwCount;                                              ///< ������ϵ�˵ĸ���

public:
	tagTBatchDelContacts_Api() { memset( this, 0, sizeof(tagTBatchDelContacts_Api) ); }
}*PTBatchDelContacts_Api, TBatchDelContacts_Api;

/** �����ƶ���ϵ�� */
typedef struct tagTBatchMoveContacts_Api
{
public:
	TImSn_Api atBatchContacts[KMTAPI_IM_MAX_BATCH_USERS_NUM]; ///< �����ƶ�����ϵ��
	u32 dwCount;                                              ///< ������ϵ�˵ĸ���
	s8 achDestGroupSn[KMTAPI_IM_MAX_U64STRING_LEN + 1];       ///< �ƶ����ĸ���

public:
	tagTBatchMoveContacts_Api() { memset( this, 0, sizeof(tagTBatchMoveContacts_Api) ); }
}*PTBatchMoveContacts_Api, TBatchMoveContacts_Api;

/** ΢��������Ϣ�ṹ�� */
typedef struct tagTRestErrorInfo_Api
{
	s8 achErrorInfo[KMTAPI_BUF_256_LEN + 1];  ///< ��������
	EmAPIType_Api  emApiType;                 ///< ��Ӧ��api ����
	u32      dwErrorID;                       ///< ������
	u32      dwNackEventId;                   ///< ��Ӧ��nack event id
	u32      dwParamCount;
	u32      adwParams[4];                    ///< �����Ĳ���

public:
	tagTRestErrorInfo_Api(){ memset( this ,0 ,sizeof(tagTRestErrorInfo_Api) );}
}*PTRestErrorInfo_Api,TRestErrorInfo_Api;

/** �����û���Ϣ */
typedef struct tagTMTSearchUserInfo_Api
{
	EmMtOperateUserInfo_Api	emOperateUser;
	u32						dwXmppNo;
	TImMemberInfo_Api	    tImMemberInfo;
public:
	tagTMTSearchUserInfo_Api()
	{
		dwXmppNo = 0;
		emOperateUser = MT_OPERATE_USER_ADD_Api;
	}
}*PTMTSearchUserInfo_Api, TMTSearchUserInfo_Api;

/** ������Ϣ */
typedef struct tagTFriendConferenceInfo_Api
{
	s8 achPeerId[ KMTAPI_IM_MAX_ID_LEN + 1]; 
	s8 achConfE164[KMTAPI_MAX_CONF_E164_LEN + 1];         ///< ����E164��
	s8 achRoomId[KMTAPI_IM_MAX_CHATROOM_ID_LEN + 1];      ///< �����Ӧ��Im������id
	s8 achChatName[KMTAPI_IM_MAX_MULTI_CHAT_NAME_LEN + 1];///< ��������

	EmMtImTerminalType_Api emPeerType;                    ///< �����ն�����

	tagTFriendConferenceInfo_Api()
	{
		memset( this, 0, sizeof(*this) );
	}
}*PTFriendConferenceInfo_Api, TFriendConferenceInfo_Api;

/** �Զ��� */
typedef struct tagTImSelfDef_Api
{
	TImSelfDefInfo_Api tImSelfDefInfo_Api;
	TImSelfDefPic_Api tImSelfDefPic_Api;
public:
	tagTImSelfDef_Api() { memset( this, 0, sizeof(tagTImSelfDef_Api) ); }

}*PTImSelfDef_Api, TImSelfDef_Api;

/** �����ļ� */
typedef struct tagTImAcceptFile_Api
{
	BOOL32 bRecv;
	BOOL32 bSetSavePath;
	s8 achPath[KMTAPI_MAX_PATH_FILE_NAME_LEN + 1];

public:
	tagTImAcceptFile_Api() { memset( this, 0, sizeof(tagTImAcceptFile_Api) ); }
}*PTImAcceptFile_Api, TImAcceptFile_Api;

/** ������ͼƬ */
typedef struct tagTImChatroomPicture_Api
{
	TMultiChatPicId_Api tMultiChatPicId_Api;
	s8 achPath[KMTAPI_MAX_PATH_FILE_NAME_LEN + 1];
public:
	tagTImChatroomPicture_Api() { memset( this, 0, sizeof(tagTImChatroomPicture_Api) ); }

}*PTImChatroomPicture_Api, TImChatroomPicture_Api;

typedef struct tagTMTAccountManagerSystem_Api
{
	s8 achusername[ KMTAPI_IM_MAX_ID_LEN + 1];           ///< �˺ţ�������E164���������
	s8 achpassword[KMTAPI_BUF_64_LEN + 1];               ///< ����
	s8 achmobileNum[KMTAPI_MT_MAX_TELEPHONE_LEN + 1];    ///< ��ϵ�绰����ѡ
	s8 achextNum[KMTAPI_BUF_64_LEN + 1];             ///< �ֻ�����ѡ
	s8 achseat[KMTAPI_BUF_64_LEN + 1];               ///< ��λ�ţ���ѡ
	s8 achbrief[KMTAPI_IM_MAX_BRIEF_LEN + 1];        ///< һ�仰����, ֧��70�����֣���ѡ
	s8 achposition[KMTAPI_BUF_64_LEN + 1];           ///< ְλ����ѡ
	s8 achName[KMTAPI_IM_REST_COMMON_BUF_LEN + 1];   ///< ��������ѡ
	s8 achAPIAddr[KMTAPI_BUF_64_LEN + 1];			 ///< API��ַ
	s8 achEmail[KMTAPI_BUF_128_LEN + 1];			 ///< ����

	BOOL32 bMale;                                    ///< �Ա𣬿�ѡ
	BOOL32 bIsAdding;

	u32   dwBitMask;
	u32   dwContextId;                               ///< �û��Զ���Ĳ���
public:
	tagTMTAccountManagerSystem_Api() { memset( this, 0, sizeof(tagTMTAccountManagerSystem_Api) );  }
}*PTMTAccountManagerSystem_Api, TMTAccountManagerSystem_Api;

/** �ļ����� */
typedef struct tagTImFileShareProgress_Api
{
	s8     achCurFileName[KMTAPI_IM_RECV_PATH_LEN + 1];  ///< ��ǰ������ļ���(����·��)
	u32    dwPercent;                                   ///< �������0~100
	u32    dwTransferSize;                              ///< �Ѿ������С
	u32    dwTrasferRate;                               ///< ��������
public:
	tagTImFileShareProgress_Api() { memset( this, 0, sizeof(tagTImFileShareProgress_Api) ); }
}*PTImFileShareProgress_Api, TImFileShareProgress_Api;


typedef struct tagTChatroomMemberCacheItem_Api
{
	EmImBatchMsgType_Api emEventId; ///< �¼�id  
	u32 dwApp;                                         ///< �˺�id
	TImMultiChatMemberInfoEx_Api tInfo; ///< ����

public:
	tagTChatroomMemberCacheItem_Api()
	{
		dwApp     = 0;
	}
}*PTChatroomMemberCacheItem_Api, TChatroomMemberCacheItem_Api;

/** ����֪ͨ�������Ա��Ϣ */
typedef struct tagTChatroomMemberCacheList_Api
{
	u32 dwArraySize;
	TChatroomMemberCacheItem_Api atArray[KMTAPI_IM_MAX_CHATROOM_MEMBER_CACHE_ARRAY_SIZE];
public:
	tagTChatroomMemberCacheList_Api() { dwArraySize = 0; }
}*PTChatroomMemberCacheList_Api, TChatroomMemberCacheList_Api;
//added by ydwu 2014.06.17 end


//by-qwchan-part-mtmeetingctrl begin

typedef struct tagTMTCreateConfMember_Api
{
	s8	achName[ KMTAPI_BUF_128_LEN+1 ];        //ƽ̨���� �����һ�㶼�� 164�� �� ����
	s8	achAccount[ KMTAPI_BUF_64_LEN+1 ];      //ƽ̨�������һ�㶼��moid
	EmMtAddrType_Api emAccountType;             ///����
public:
	tagTMTCreateConfMember_Api(){memset( this, 0, sizeof(tagTMTCreateConfMember_Api) ); }
}*PTMTCreateConfMember_Api, TMTCreateConfMember_Api;

typedef struct tagTMTInviteMember_Api
{
    s8	achName[ KMTAPI_BUF_128_LEN+1 ];        //ƽ̨���� �����һ�㶼�� 164�� �� ����
    s8	achAccount[ KMTAPI_BUF_64_LEN+1 ];      //ƽ̨�������һ�㶼��moid
    EmMtAddrType_Api emAccountType;             //�ʺ�����
    EmConfProtocol_Api emProtocol;              //����Э�� 323 SIP
public:
    tagTMTInviteMember_Api(){memset( this, 0, sizeof(tagTMTInviteMember_Api) ); }
}*PTMTInviteMember_Api, TMTInviteMember_Api;

typedef struct tagTMTVideoFormatList_Api
{
	EmVidFormat_Api		emVideoFormat;
	EmH264Profile_Api	emVideoProfile;
	EmMtResolution_Api	emResolution;	
	u32					dwFrame;
	u32					dwRate;

public:
	tagTMTVideoFormatList_Api()
	{
		memset( this, 0, sizeof(tagTMTVideoFormatList_Api) ); 
		emVideoProfile = emBaseline_Api;
	}
}*PTMTVideoFormatList_Api, TMTVideoFormatList_Api;

typedef struct tagTMTAudioFormatList_Api
{
	EmAudFormat_Api		emAudioFormat;
	EmAacChnlNum_Api	emAaccnnlNum;

public:
	tagTMTAudioFormatList_Api(){memset( this, 0, sizeof(tagTMTAudioFormatList_Api) ); }
}*PTMTAudioFormatList_Api, TMTAudioFormatList_Api;

/** �������� */
typedef struct tagTMTCreateConfMultiCast_Api
{
	s8 achMulticastAddr[KMTAPI_BUF_64_LEN+1];    ///<��ַ
	BOOL32 bEnable;                              ///<�Ƿ񼤻�:1�ǣ�0��
	u32 dwPort;                                  ///<�˿�
public:
	tagTMTCreateConfMultiCast_Api() { memset( this, 0, sizeof(tagTMTCreateConfMultiCast_Api) ); }
}*PTMTCreateConfMultiCast_Api, TMTCreateConfMultiCast_Api;

typedef struct tagTMTConfPollInfo_Api
{
    BOOL32 bEnable;   ///<�Ƿ����ã�1��0��
    EmPollMode_Api emMode;  ///<��ѯģʽ 1-��ͼ����ѯ 3-����Ƶ��ѯ
    u32 dwNum;        ///<��ѯ������0���޴���ѯ
    u32 dwInterval;   ///<��ѯ���ʱ��(��)
    u32 dwMemberCount;///<��Ա����
    TMTCreateConfMember_Api atMemberList[KMTAPI_COUNT_100];///<��ѯ��Ա�б�
public:
    tagTMTConfPollInfo_Api() { memset( this, 0, sizeof(tagTMTConfPollInfo_Api) ); }
}*PTMTConfPollInfo_Api, TMTConfPollInfo_Api;
/** ����ϳɳ�Ա�б� */
typedef struct tagTMTTemplateVmpMember_Api
{
	s8 achName[KMTAPI_BUF_128_LEN+1];      ///<�˺�����
	s8	achAccount[ KMTAPI_BUF_64_LEN+1 ]; ///<�˺�
	EmMtAddrType_Api emAccountType;        ///<�ʺ�����
	EmMtVMPMmbType_Api emFollowType;       ///<��������
	u32 dwIndex;                                            ///<�ڻ����ϳ��е�λ��
    TMTConfPollInfo_Api tPoll;            ///<��ѯ����
public:
	tagTMTTemplateVmpMember_Api() { memset( this, 0, sizeof(tagTMTTemplateVmpMember_Api) ); }
}*PTMTTemplateVmpMember_Api, TMTTemplateVmpMember_Api;

/** ����ϳ����� */
typedef struct tagTMTCreateConfVmp_Api
{
	BOOL32 bEnable;          ///<�Ƿ�����
	EmMtVmpStyle_Api emStyle;///<���
	BOOL32 bVoiceHint;       ///<�Ƿ�ʶ��������Դ:1��0��
	BOOL32 bShowMTName;      ///<�Ƿ���ʾ������1��0��
	BOOL32 bIsBroadcast;     ///<�Ƿ�㲥

	u32 dwMemberCount;       ///<��Ա����
	TMTTemplateVmpMember_Api atMemberList[KMTAPI_COUNT_192];///<����ϳɳ�Ա�б�
public:
	tagTMTCreateConfVmp_Api() { memset( this, 0, sizeof(tagTMTCreateConfVmp_Api) ); }
}*PTMTCreateConfVmp_Api, TMTCreateConfVmp_Api;

/**��ѯ����  */
typedef struct tagTMTCreateConfPoll_Api
{
	BOOL32 bEnable;   ///<�Ƿ����ã�1��0��
	u32 dwNum;        ///<��ѯ������0���޴���ѯ
	u32 dwInterval;   ///<��ѯ���ʱ��(��)
	BOOL32 bSpeaker;  ///<�Ƿ���:1�ǣ�0��

	u32 dwMemberCount;///<��Ա����
	TMTCreateConfMember_Api atMemberList[KMTAPI_COUNT_192];///<��ѯ��Ա�б�
public:
	tagTMTCreateConfPoll_Api() { memset( this, 0, sizeof(tagTMTCreateConfPoll_Api) ); }
}*PTMTCreateConfPoll_Api, TMTCreateConfPoll_Api;

typedef struct tagTMTDualFormatList_Api
{
	u32		dwFrame;							    ///< ֡��
	EmMtResolution_Api emResolution;				///< �ֱ���
	EmVidFormat_Api	   emVideoFormat;				///< ��Ƶ��ʽ

public:
	tagTMTDualFormatList_Api(){ memset( this ,0 ,sizeof(tagTMTDualFormatList_Api) );}

}*PTMTDualFormatList_Api, TMTDualFormatList_Api;

typedef struct tagTMTCreateRecordRecord_Api
{
	BOOL32 bDoubleFlow;			    ///< �Ƿ�����˫����1�ǣ�0��
	BOOL32 bEnable;				    ///< �Ƿ�����¼�����ã�1�ǣ�0��
	BOOL32 bMain;					///< �Ƿ�����������1�ǣ�0��
	BOOL32 bPublish;				///< �Ƿ񷢲�¼��1�ǣ�0��
public:
	tagTMTCreateRecordRecord_Api(){ memset( this ,0 ,sizeof(tagTMTCreateRecordRecord_Api) );}

}*PTMTCreateRecordRecord_Api, TMTCreateRecordRecord_Api;

typedef struct tagTMTCreateConfSatellite_Api
{
	BOOL32 bEnable;				///< �Ƿ������������ã�1�ǣ�0��
	s8  achMulticastAddr[ KMTAPI_BUF_64_LEN+1 ];		///< ����IP��ַ
	u32 dwPort;					///< �˿�
	u32 dwReturnNum;			///< �ش���
public:
	tagTMTCreateConfSatellite_Api(){ memset( this ,0 ,sizeof(tagTMTCreateConfSatellite_Api) );}

}*PTMTCreateConfSatellite_Api, TMTCreateConfSatellite_Api;

typedef struct tagTMTVrsAlias_Api
{
	EmVrsAliasType_Api    emRecAliasType;         ///< ¼����������� 0-��ʼֵ�� 1-IP, 2-E164 ƽ̨�������ͻ�ȡ��Ӧ�ı�����Ϣ
	s8     achRecIpAddr[ KMTAPI_BUF_64_LEN+1 ];		///< ¼���ip
	s8	   achRecE164Addr[ KMTAPI_BUF_64_LEN+1 ];	///< ¼�������E164

public:
	tagTMTVrsAlias_Api(){ memset( this ,0 ,sizeof(tagTMTVrsAlias_Api) );}

}*PTMTVrsAlias_Api, TMTVrsAlias_Api;

typedef struct tagTMTCreateAutoRecAttrb_Api  
{
	BOOL32 bAutoRec;			   //�Ƿ���鿪���Զ�¼�� 0-��֧�� 1-֧��
	EmRecordPubMode_Api  emPublishMode; //0-������ 1-������������¼��ֱ����־ 2.-¼�����֮�󷢲�����¼��������־ 3-ֱ��+����
	BOOL32 bRecMainVideo;		   //�Ƿ�¼����ʽ����(��Ƶ+��Ƶ)
	BOOL32 bRecdStream;			   //�Ƿ�¼˫��(��˫��)
	TMTVrsAlias_Api tVrsAlias;	   //¼���������Ϣ

public:
	tagTMTCreateAutoRecAttrb_Api(){ memset( this ,0 ,sizeof(tagTMTCreateAutoRecAttrb_Api) );}

}*PTMTCreateAutoRecAttrb_Api, TMTCreateAutoRecAttrb_Api;


/**5.0 �Ǳ�ras����Ĳ���  */
typedef struct tagTMtCreateConfParam_Api
{
	s8				                achName[ KMTAPI_BUF_128_LEN+1 ];        ///<��������
	u32				                dwDuration;                             ///<�������ʱ��
	u32				                dwBitrate;                              ///<��������
	EmMtOpenMode_Api		        emMeetingSafe;                          ///<���鰲ȫmode
	s8								achPassword[ KMTAPI_BUF_32_LEN+1 ];     ///<�������룬���Ϊ0����ʾû�в���Ҫ����
	EmEncryptArithmetic_Api			emEncryptedType;                        ///<������ܷ�ʽ
	s8								achEncryptedKey[ KMTAPI_BUF_32_LEN+1 ]; ///<������Կ
	EmMeetingSafeType_Api		    emMeetingType;                          ///<�����Ƿ��� �˿ڻ���          
	EmClosedMeeting_Api             emClosedMeeting;                        ///<��������ţ�1������0�ر�
	EmVideoQuality_Api              emVideoQuality;                         ///<��Ƶ����,0���������ȣ�1���ٶ�����
	EmMtDualMode_Api                emDualMode;                             ///<˫��Ȩ��
	BOOL32                          bInitMute;                              ///<��ʼ��������1�ǣ�0��
	BOOL32							bPublicMeeting;                         ///<�Ƿ��ǹ���������

	/**����Ƶ��ʽ */
	u32						        dwVideoCount;
	TMTVideoFormatList_Api          atVideoFormatList[KMTAPI_COUNT_16];
	u32						        dwAudioCount;
	TMTAudioFormatList_Api          atAudioFormatList[KMTAPI_COUNT_16];
	u32                             dwDualCount;
	TMTDualFormatList_Api           atDualFormatList[KMTAPI_COUNT_8];      ///< ˫��Ƶ��ʽ�б�

	/**�λ��Ա�б� */
	u32						        dwMemberCount;
	TMTCreateConfMember_Api         atMembers[KMTAPI_COUNT_192];   ///< �λ��Ա�б�


	/**����,����ϳɲ��� */
	EmMtMixType_Api		    emMixMode;                             ///< ������ʽ ע:���ƻ�����������������ͬʱ�� 
	u32                     dwMixMemberCount;                      ///< ���ƻ��� ��Ա��
	TMTCreateConfMember_Api atMixMemberList[KMTAPI_COUNT_192];     ///< �ƶ�����ʱ�Ļ�����Ա�б�
	TMTCreateConfVmp_Api    tVmp;                                  ///< ����ϳ�����

	TMTCreateConfPoll_Api   tPoll;                                 ///< ��ѯ����
	u32                     dwVipCount;
	TMTCreateConfMember_Api atVipList[KMTAPI_COUNT_192];           ///< vip��Ա�б�


	TMTCreateConfMember_Api tSpeaker;   ///< ������
	TMTCreateConfMember_Api tAdmin;     ///< ����
	u32 dwCallTimes;                    ///< ���д���
	u32 dwCallInterval;                 ///< ���м��(��)
	BOOL32 bCallChase;                  ///< �Ƿ�׷����1�ǣ�0��
	BOOL32 bVoiceInspireEnable;         ///< �Ƿ������Լ�����1�ǣ�0��
	EmRestCascadeMode_Api emCascadeMode;///< ����ģʽ,0�򵥼�����1�ϲ�����
	BOOL32 bCascadeUpload;              ///< �Ƿ����ϴ�:1�ǣ�0��
	BOOL32 bCascadeReturn;              ///< �Ƿ����ش�:1�ǣ�0��
	u32 dwCascadeReturnPara;            ///< �����ش��������
	TMTCreateRecordRecord_Api      tRecord;                    ///< ¼������ 
	TMTCreateConfMultiCast_Api     tMultiCast;                 ///< ��������
	TMTCreateConfSatellite_Api	   tSatellite;                 ///<���ǻ�������
	u32 dwCallChaseMemberCount;
	TMTCreateConfMember_Api atCallChaseList[KMTAPI_COUNT_192]; ///< ׷��Ϊ��ʱ��׷����Ա�б�

	//new
	u32					   dwMixVacInterval ;                       //�����������ж�
	BOOL32 				   bOneReforming;                           //�Ƿ��һ����     
	s8					   achConfE164[ KMTAPI_BUF_32_LEN+1 ];      //����e164 ����ܵ�Ԥ�������
	u32					   dwMeetingScale;                          ///< �����ģ,0���գ�1��4����Ƶ����,2��8����Ƶ����,3��������Ƶ����


public:
	tagTMtCreateConfParam_Api(){memset( this, 0, sizeof(tagTMtCreateConfParam_Api) ); }

}*PTMtCreateConfParam_Api, TMtCreateConfParam_Api;

/**  ���ڸ���ģ��id��ȡ���� */
typedef struct tagTMTGetMixInfo_Api
{
	BOOL32			bEnable;			///< �Ƿ�������1���ǣ�0����
	EmMtMixType_Api emMode;		        ///< 0-��������1-���ۿ�ʼ��2-���ƻ���

	u32 dwMixMemberCount;
	TMTCreateConfMember_Api atMixMemberList[KMTAPI_COUNT_64]; ///< �����б�
public:
	tagTMTGetMixInfo_Api(){ memset( this ,0 ,sizeof(tagTMTGetMixInfo_Api) );}
}*PTMTGetMixInfo_Api, TMTGetMixInfo_Api;

/**����ģ������ */
typedef struct tagTMTPerTemplateInfo_Api
{
	u32				         dwTemplateid;
	s8				                achName[ KMTAPI_BUF_128_LEN+1 ];        ///<��������
	u32				                dwDuration;                             ///<�������ʱ��
	u32				                dwBitrate;                              ///<��������
	EmMtOpenMode_Api		        emMeetingSafe;                          ///<���鰲ȫmode
	s8								achPassword[ KMTAPI_BUF_32_LEN+1 ];     ///<�������룬���Ϊ0����ʾû�в���Ҫ����
	EmEncryptArithmetic_Api			emEncryptedType;                        ///<������ܷ�ʽ
	s8								achEncryptedKey[ KMTAPI_BUF_32_LEN+1 ]; ///<������Կ
	EmMeetingSafeType_Api		    emMeetingType;                          ///<�����Ƿ��� �˿ڻ���          
	EmClosedMeeting_Api             emClosedMeeting;                        ///<��������ţ�1������0�ر�
	EmVideoQuality_Api              emVideoQuality;                         ///<��Ƶ����,0���������ȣ�1���ٶ�����
	EmMtDualMode_Api                emDualMode;                             ///<˫��Ȩ��
	BOOL32                          bInitMute;                              ///< ��ʼ��������1�ǣ�0��
	BOOL32							bPublicMeeting;                   ///< �Ƿ��ǹ���������
    u32 dwMeetingScale;                                                   ///< �����ģ,0���գ�1��4����Ƶ����,2��8����Ƶ����,3��������Ƶ����
    u32 dwOneReforming;                                                 ///< ��һ����,0:�ر�; 1:����
    s8 achPresetedNumber[ KMTAPI_BUF_16_LEN ];        ///< Ԥ��������

	/**����Ƶ��ʽ */
	u32						        dwVideoCount;
	TMTVideoFormatList_Api          atVideoFormatList[KMTAPI_COUNT_16];
	u32						        dwAudioCount;
	TMTAudioFormatList_Api          atAudioFormatList[KMTAPI_COUNT_16];
	u32                             dwDualCount;
	TMTDualFormatList_Api           atDualFormatList[KMTAPI_COUNT_8];      ///< ˫��Ƶ��ʽ�б�

	/**�λ��Ա�б� */
	u32						        dwMemberCount;
	TMTCreateConfMember_Api         atMembers[KMTAPI_COUNT_256];   ///< �λ��Ա�б�


	/**����,����ϳɲ��� */
	TMTGetMixInfo_Api		    tMixInfo;                             ///< ���������Ϣ
	TMTCreateConfVmp_Api    tVmp;                                  ///< ����ϳ�����

	TMTCreateConfPoll_Api   tPoll;                                 ///< ��ѯ����
	u32                     dwVipCount;
	TMTCreateConfMember_Api atVipList[KMTAPI_COUNT_256];           ///< vip��Ա�б�


	TMTCreateConfMember_Api tSpeaker;   ///< ������
	TMTCreateConfMember_Api tAdmin;     ///< ����
	u32 dwCallTimes;                    ///< ���д���
	u32 dwCallInterval;                 ///< ���м��(��)
	BOOL32 bCallChase;                  ///< �Ƿ�׷����1�ǣ�0��
	BOOL32 bVoiceInspireEnable;         ///< �Ƿ������Լ�����1�ǣ�0��
    u32         dwVoiceInspireTime;         ///< �����������ж�
	EmRestCascadeMode_Api emCascadeMode;///< ����ģʽ,0�򵥼�����1�ϲ�����
	BOOL32 bCascadeUpload;              ///< �Ƿ����ϴ�:1�ǣ�0��
	BOOL32 bCascadeReturn;              ///< �Ƿ����ش�:1�ǣ�0��
	u32 dwCascadeReturnPara;            ///< �����ش��������
	TMTCreateRecordRecord_Api      tRecord;                    ///< ¼������ 
	TMTCreateConfMultiCast_Api     tMultiCast;                 ///< ��������
	TMTCreateConfSatellite_Api	   tSatellite;                 ///<���ǻ�������
	u32 dwCallChaseMemberCount;
	TMTCreateConfMember_Api atCallChaseList[KMTAPI_COUNT_128]; ///< ׷��Ϊ��ʱ��׷����Ա�б�
	BOOL32						bEncryptedAuth;                         ///< �Ƿ�˫����֤ 0-�ر� 1-����

public:
	tagTMTPerTemplateInfo_Api(){memset( this, 0, sizeof(tagTMTPerTemplateInfo_Api) ); }
}*PTMTPerTemplateInfo_Api, TMTPerTemplateInfo_Api;


typedef struct tagTMTPerTemplateSimpleInfo_Api
{
	u32		dwTemplateid;						///< ����ģ��ID
	s8		achName[ KMTAPI_BUF_128_LEN+1 ];    ///< ����
	u32		dwDuration;							///< ����ʱ����Ԥ��
	u32		dwBitrate;							///< ��������
	EmMtResolution_Api		emResolution;		///< ����ֱ��ʣ��������͵����ݲ��չ���ģ��

public:
	tagTMTPerTemplateSimpleInfo_Api(){memset( this, 0, sizeof(tagTMTPerTemplateSimpleInfo_Api) ); }
}*PTMTPerTemplateSimpleInfo_Api, TMTPerTemplateSimpleInfo_Api;


typedef struct tagTMTPerTemplateDetail_Api
{
	TMTPerTemplateSimpleInfo_Api tPersonalTemplate;
	u32							dwCount;
	TMTCreateConfMember_Api		atMembers[KMTAPI_COUNT_256];

public:
	tagTMTPerTemplateDetail_Api(){memset( this, 0, sizeof(tagTMTPerTemplateDetail_Api) ); }
}*PTMTPerTemplateDetail_Api, TMTPerTemplateDetail_Api;

typedef struct tagTMTPerTemplateList_Api
{
	u32							dwCount;
	TMTPerTemplateDetail_Api	atPerTemplateDetail[KMTAPI_MG_MAX_TEMPLATE_LIST_NUM];

public:
	tagTMTPerTemplateList_Api(){memset( this, 0, sizeof(tagTMTPerTemplateList_Api) ); }
}*PTMTPerTemplateList_Api, TMTPerTemplateList_Api;


/** ��������֪ͨ */
typedef struct tagTMTCreateMeetingNotify_Api
{
	u32		dwId;
	u32		dwNotifyMask;
	u32     dwTitleType;
public:
	tagTMTCreateMeetingNotify_Api(){memset( this, 0, sizeof(tagTMTCreateMeetingNotify_Api) ); }
}*PTMTCreateMeetingNotify_Api, TMTCreateMeetingNotify_Api;

/** �����б� */
typedef struct tagTMTMeetingList_Api
{
	s8			achStartDay[KMTAPI_MG_MAX_MEETING_DATETIME_LEN+1];	    ///< ���鿪ʼ����
	s8			achEndDay[KMTAPI_MG_MAX_MEETING_DATETIME_LEN+1];		///< �����������
	BOOL32		bIsConfirm;									///< �Ƿ�ȷ�ϲμ�
	u32			dwStart;									///< ����Ŀ�ʼ��
	u32			dwCount;									///< ��ȡ�Ļ�����
	u32			dwOrder;									///< ���鿪ʼʱ������0��������1������
public:
	tagTMTMeetingList_Api(){memset( this, 0, sizeof(tagTMTMeetingList_Api) ); }
}*PTMTMeetingList_Api, TMTMeetingList_Api;

/** TMTShortRoom_Api */
typedef struct tagTMTShortRoom_Api
{
	s32		nID;
	s8		achname[KMTAPI_MAX_CONF_NAME_LEN+1];
	s8		achRegionName[KMTAPI_MG_MAX_REGIONNAME_LEN+1];
public:
	tagTMTShortRoom_Api(){ memset( this ,0 ,sizeof(tagTMTShortRoom_Api) );}
}*PTMTShortRoom_Api,TMTShortRoom_Api;

/** TMTShortRooms_Api */
typedef struct tagTMTShortRooms_Api
{
	s32					nCount;
	TMTShortRoom_Api	atItems[KMTAPI_MG_MAX_SHORTROOMS_NUM];
public:
	tagTMTShortRooms_Api(){ memset( this ,0 ,sizeof(tagTMTShortRooms_Api) );}
}*PTMTShortRooms_Api,TMTShortRooms_Api;

/** TMTRoomIDs_Api */
typedef struct tagTMTRoomIDs_Api
{
	s32		nCount;
	s32		anItems[KMTAPI_MG_MAX_MEETING_ROOM_NUM];
public:
	tagTMTRoomIDs_Api(){ memset( this ,0 ,sizeof(tagTMTRoomIDs_Api) );}
}*PTMTRoomIDs_Api,TMTRoomIDs_Api;

/** TMTShortMeeting_Api */
typedef struct tagTMTShortMeeting_Api
{
	s32				nID;
	s8				achSubject[ KMTAPI_MG_MAX_MEETING_SUBJECT_LEN+1];
	s8				achStartTime[ KMTAPI_MG_MAX_MEETING_DATETIME_LEN+1];
	s8				achEndTime[ KMTAPI_MG_MAX_MEETING_DATETIME_LEN+1];
	s8				achOrganizerMoid[KMTAPI_MAX_DOMAIN_MOID_LEN+1];
	s32				nStatus;
	s32				nIsVideoMeeting;
	EmParticipatResponse_Api				emFeedbackStatus;
	s32				nRegularID;
	TMTRoomIDs_Api	tRoomIDs;
public:
	tagTMTShortMeeting_Api(){ memset( this ,0 ,sizeof(tagTMTShortMeeting_Api) );}
}*PTMTShortMeeting_Api,TMTShortMeeting_Api;

/** TMTShortMeetings_Api */
typedef struct tagTMTShortMeetings_Api
{
	u32					nCount;
	TMTShortMeeting_Api	atItems[KMTAPI_MG_MAX_SHORTMEETINGS_NUM];
public:
	tagTMTShortMeetings_Api(){ memset( this ,0 ,sizeof(tagTMTShortMeetings_Api) );}
}*PTMTShortMeetings_Api,TMTShortMeetings_Api;

/** TMTMeetingLists_Api */
typedef struct tagTMTMeetingLists_Api
{
	TMTShortRooms_Api      tRelatedRooms;
	TMTShortMeetings_Api   tMeetings;
public:
	tagTMTMeetingLists_Api(){ memset( this ,0 ,sizeof(tagTMTMeetingLists_Api) );}
}*PTMTMeetingLists_Api,TMTMeetingLists_Api;

typedef struct tagTMTParticipantInfo_Api
{
	s8		achMoId[KMTAPI_MAX_DOMAIN_MOID_LEN+1];
	s8      achEmail[KMTAPI_MAX_EMAIL_LEN+1];
	s8      achName[KMTAPI_MAX_CONF_NAME_LEN+1];
	s8      achParticipantNo[KMTAPI_MG_MAX_PARTICIPANTNO_LEN+1];
	EmParticipatResponse_Api     emParticipantResponse;
	u32     dwParticipantType;
public:
	tagTMTParticipantInfo_Api(){ memset( this, 0, sizeof(tagTMTParticipantInfo_Api) ); }
}*PTMTParticipantInfo_Api, TMTParticipantInfo_Api;

/** ����Id��ȡ������ϸ��Ϣ(��������Ϣ) */
typedef struct tagTMTConfInfoParticipants_Api
{
	u32						dwParticipantCount;
	s8						achConfE164[KMTAPI_MAX_MT_E164_LEN+1];
	u32						dwID;
	u8						byCnt;				///< �����˸���
	TMTParticipantInfo_Api	tMTParticipantInfo[KMTAPI_MG_MAX_PARTICIPANT_NUM];
public:
	tagTMTConfInfoParticipants_Api(){ memset( this ,0 ,sizeof(tagTMTConfInfoParticipants_Api) );}
}*PTMTConfInfoParticipants_Api,TMTConfInfoParticipants_Api;

/** ������Ԥ����Ϣ */
typedef struct tagTMTBookingInfo_Api
{
	u32		  dwMeetingRoomId;								            ///< ������ID
	s8		  achStartDay[KMTAPI_MG_MAX_MEETING_DATETIME_LEN+1];		///< ���鿪ʼʱ��
	s8		  achEndDay[KMTAPI_MG_MAX_MEETING_DATETIME_LEN+1];		    ///< �������ʱ��
	u32		  dwStart;										///< ����Ŀ�ʼ��
	u32		  dwCount;										///< ��ȡ�Ļ�����
	u32		  dwOrder;										///< ���鿪ʼʱ������, 0��������, 1������
public:
	tagTMTBookingInfo_Api(){ memset( this ,0 ,sizeof(tagTMTBookingInfo_Api) );}
}*PTMTBookingInfo_Api,TMTBookingInfo_Api;

/** ��ȡĳ�˵Ļ�����Ϣ */
typedef struct tagTMTMeetingListOfPerson_Api
{
	s8		achMoId[KMTAPI_MAX_DOMAIN_MOID_LEN+1];
	s8		achStartDay[KMTAPI_MG_MAX_MEETING_DATETIME_LEN+1];
	s8		achEndDay[KMTAPI_MG_MAX_MEETING_DATETIME_LEN+1];
	u32		dwStart;
	u32		dwCount;
	u32		dwOrder;
public:
	tagTMTMeetingListOfPerson_Api(){ memset( this ,0 ,sizeof(tagTMTMeetingListOfPerson_Api) );}
}*PTMTMeetingListOfPerson_Api,TMTMeetingListOfPerson_Api;

typedef struct tagTMTTemplateAccount_Api
{
    s8		achAccount[ KMTAPI_BUF_64_LEN+1 ];		///< �˺�
    EmMtAddrType_Api		emAccountType;			///< �˺�����
public:
    tagTMTTemplateAccount_Api(){ memset( this ,0 ,sizeof(tagTMTTemplateAccount_Api) );}

}*PTMTTemplateAccount_Api, TMTTemplateAccount_Api;

/**  ���ڴ����޸�ģ�� */
typedef struct tagTMTSetMixInfo_Api
{
    BOOL32			bEnable;			///< �Ƿ�������1���ǣ�0����
    EmMtMixType_Api emMode;		        ///< 0-��������1-���ۿ�ʼ��2-���ƻ���

    u32 dwMixMemberCount;
    TMTTemplateAccount_Api atMixMemberList[KMTAPI_COUNT_64]; ///<  �����б�
public:
    tagTMTSetMixInfo_Api(){ memset( this ,0 ,sizeof(tagTMTSetMixInfo_Api) );}
}*PTMTSetMixInfo_Api, TMTSetMixInfo_Api;

/** ������������� */
typedef struct tagTVMeetingParam_Api
{
    EmClosedMeeting_Api emClosedMeeting;                 ///< ��������ţ�1������0�ر�
    EmMtDualMode_Api    emDualmode;						///< ˫������
    s8							          achEncryptedkey[ KMTAPI_BUF_32_LEN+1 ];				///< AES����KEY
    EmEncryptArithmetic_Api		emEncryptedtype;    ///< �����������
    BOOL32						            bInitmute;                 ///< ��ʼ������  1�ǣ�0��
    EmMtOpenMode_Api	            emMeetingsafe;		 ///< ���鰲ȫ
    EmMeetingSafeType_Api	    emMeetingtype;	     ///< 1 �˿ڻ���   0 ��ͳý�����
    u32         dwMeetingScale;                                             ///< �����ģ,0���գ�1��4����Ƶ����,2��8����Ƶ����,3��������Ƶ����
    u32         dwOneReforming;                                           ///< ��һ����,0:�ر�; 1:����
    BOOL32 bVoiceInspireEnable;                                       ///< �Ƿ������Լ�����1�ǣ�0��
    u32         dwVoiceInspireTime;                                       ///< ���Լ������ж�
    s8	            achPassword[ KMTAPI_BUF_128_LEN+1 ];	    ///< ����
    BOOL32  bPublicmeeting;					                            ///< �Ƿ񹫹�������  1�ǣ�0��
    u32         dwVipNum;						                                ///< VIP�˺�����
    TMTTemplateAccount_Api		   atViplist[KMTAPI_COUNT_256];	    ///< VIP�˺�
    TMTCreateRecordRecord_Api   tRecord;     ///< ¼������ 
    TMTCreateConfSatellite_Api	   tSatellite;    ///< ���ǻ�������
    TMTTemplateAccount_Api		   tSpeaker;    ///< ������
    TMTTemplateAccount_Api		   tAdmin;      ///< ����
    u32                                             dwVFormatNum;
    TMTVideoFormatList_Api		   atVideoFormatList[KMTAPI_COUNT_16];
    u32                                             dwDualFormatNum;
    TMTDualFormatList_Api            atDualFormatList[KMTAPI_COUNT_8];
    u32                                             dwAFormatNum;
    TMTAudioFormatList_Api          atAudioFormatList[KMTAPI_COUNT_16];
    TMTSetMixInfo_Api				   tMixInfo;    ///< ��������
    TMTCreateConfVmp_Api           tVmp;        ///< ����ϳ�����
    TMTCreateConfPoll_Api             tPoll;         ///< ��ѯ����
public:
	tagTVMeetingParam_Api(){ memset( this ,0 ,sizeof(tagTVMeetingParam_Api) );}
}*PTVMeetingParam_Api,TVMeetingParam_Api;


/** �������� */
typedef struct tagTMTAddMeeting_Api
{
	s8					achSubject[KMTAPI_MG_MAX_MEETING_SUBJECT_LEN+1];
	s8					achDay[KMTAPI_MG_MAX_MEETING_DATETIME_LEN+1];
	s8					achStartShortTime[KMTAPI_MG_MAX_MEETING_DATETIME_LEN+1];
	s8					achEndShortTime[KMTAPI_MG_MAX_MEETING_DATETIME_LEN+1];

	u32                 dwRoomsCount;
	u32					adwRooms[KMTAPI_MG_MAX_ROOMS_NUM];
	s8					achPhone[KMTAPI_MT_MAX_TELEPHONE_LEN+1];
	s8					achMobile[KMTAPI_MT_MAX_TELEPHONE_LEN+1];
	u32					dwParticipantCnt;
	s8					achParticipants[KMTAPI_MG_MAX_PARTICIPANT_NUM][KMTAPI_MAX_DOMAIN_MOID_LEN+1];
	s8					achBrief[KMTAPI_MG_MAX_MEETING_BRIEF_LEN+1];
	u32					dwIsVideoMeeting;
	u32					dwIsAutoCall;
	s8					achTemplateId[KMTAPI_MG_MAX_TEMPLATE_ID_LEN+1];
	u32					dwVroomId;
	u32					dwNotifyType;
	s8					achMeetingFormKey[KMTAPI_MG_MAX_COMMON_BUF_LEN+1];
	BOOL32				bIsSendSMS;                                           ///< �Ƿ��Ͷ���
	TVMeetingParam_Api	tVMeetingParam;
public:
	tagTMTAddMeeting_Api(){ memset( this ,0 ,sizeof(tagTMTAddMeeting_Api) );}
}*PTMTAddMeeting_Api,TMTAddMeeting_Api;

/** �޸Ļ��� */
typedef struct tagTMTModifyMeeting_Api
{
	u32						dwMeetingId;
	s8						achSubject[KMTAPI_MG_MAX_MEETING_SUBJECT_LEN+1];
	s8						achDay[KMTAPI_MG_MAX_MEETING_DATETIME_LEN+1];
	s8						achStartShortTime[KMTAPI_MG_MAX_MEETING_DATETIME_LEN+1];
	s8						achEndShortTime[KMTAPI_MG_MAX_MEETING_DATETIME_LEN+1];

	u32                     dwRoomsCount;
	u32						adwRooms[KMTAPI_MG_MAX_ROOMS_NUM];
	s8						achPhone[KMTAPI_MT_MAX_TELEPHONE_LEN+1];
	s8						achMobile[KMTAPI_MT_MAX_TELEPHONE_LEN+1];
	u32						dwParticipantCnt;
	s8						achParticipants[KMTAPI_MG_MAX_MODIFY_PARTICIPANT_NUM][KMTAPI_MAX_DOMAIN_MOID_LEN+1];
	s8						achBrief[KMTAPI_MG_MAX_MEETING_BRIEF_LEN+1];
	u32						dwIsVideoMeeting;
	u32						dwIsAutoCall;
	s8						achTemplateId[KMTAPI_MG_MAX_TEMPLATE_ID_LEN+1];
	u32						dwVroomId;
	u32						dwNotifyType;
	s8						achMeetingFormKey[KMTAPI_MG_MAX_COMMON_BUF_LEN+1];
	BOOL32					bIsSendSMS;                                 ///< �Ƿ��Ͷ���
	TVMeetingParam_Api		tVMeetingParam;
public:
	tagTMTModifyMeeting_Api(){ memset( this ,0 ,sizeof(tagTMTModifyMeeting_Api) );}
}*PTMTModifyMeeting_Api,TMTModifyMeeting_Api;

/** ���鷴�� */
typedef struct tagTMTMeetingFeed_Api
{
	u32		dwMeetingId;
	u32		dwAccept;
	u32		dwJoinType;
	u32     dwReasonId;

	s8      achParticipateNo[KMTAPI_MG_MAX_COMMON_BUF_LEN+1];
public:
	tagTMTMeetingFeed_Api(){ memset( this ,0 ,sizeof(tagTMTMeetingFeed_Api) );}
}*PTMTMeetingFeed_Api,TMTMeetingFeed_Api;

/** ��ȡ���л����� */
typedef struct tagTMTQueryFreeRooms_Api
{
	u32		dwRoomsNum;
	u32		adwRooms[KMTAPI_MG_MAX_ROOMS_NUM];
	s8		achStartTime[KMTAPI_MG_MAX_MEETING_DATETIME_LEN+1];
	s8		achEndTime[KMTAPI_MG_MAX_MEETING_DATETIME_LEN+1];
	u32		dwStart;
	u32		dwCount;
	u32		dwOrder;
	u32		dwPeopleAdmint;
	u32		dwDeviceIdMask;
	u32		dwRegionNum;
	u32		adwRegionIds[KMTAPI_MG_MAX_REGIONS_NUM];
public:
	tagTMTQueryFreeRooms_Api(){ memset( this ,0 ,sizeof(tagTMTQueryFreeRooms_Api) );}
}*PTMTQueryFreeRooms_Api,TMTQueryFreeRooms_Api;

typedef struct tagTMTRoom_Api
{
	s32		nID;
	s32		nPeopleAdmit;
	s32		nDeviceMask;

	s8		achName[ KMTAPI_MAX_CONF_NAME_LEN+1 ];
	s8		achRegionName[ KMTAPI_MG_MAX_REGIONNAME_LEN+1 ];
	s8		achStartTime[  KMTAPI_MG_MAX_MEETING_DATETIME_LEN+1 ];
	s8		achEndTime[  KMTAPI_MG_MAX_MEETING_DATETIME_LEN+1 ];

public:
	tagTMTRoom_Api(){ memset( this ,0 ,sizeof(tagTMTRoom_Api) );}
}*PTMTRoom_Api,TMTRoom_Api;

typedef struct tagTMTRooms_Api
{
	s32				nCount;
	TMTRoom_Api		atItems[KMTAPI_MG_MAX_ROOMS_NUM];
public:
	tagTMTRooms_Api(){ memset( this ,0 ,sizeof(tagTMTRooms_Api) );}
}*PTMTRooms_Api,TMTRooms_Api;

typedef struct tagTMTRoomList_Api
{
	TMTRooms_Api		tRooms;
	u32					dwTotal;
public:
	tagTMTRoomList_Api(){ memset( this ,0 ,sizeof(tagTMTRoomList_Api) );}
}*PTMTRoomList_Api,TMTRoomList_Api;

/** ��ȡ�Ƽ������������ */
typedef struct tagTMTRecommendedVirtualRoom_Api
{
	s8		achStartTime[KMTAPI_MG_MAX_MEETING_DATETIME_LEN+1];
	s8		achEndTime[KMTAPI_MG_MAX_MEETING_DATETIME_LEN+1];
public:
	tagTMTRecommendedVirtualRoom_Api(){ memset( this ,0 ,sizeof(tagTMTRecommendedVirtualRoom_Api) );}
}*PTMTRecommendedVirtualRoom_Api,TMTRecommendedVirtualRoom_Api;

/** ��ȡ�����Ļ����� */
typedef struct tagTMTNormalRooms_Api
{
	u32		dwStart;
	u32		dwCount;
	u32		dwOrder;
public:
	tagTMTNormalRooms_Api(){ memset( this ,0 ,sizeof(tagTMTNormalRooms_Api) );}
}*PTMTNormalRooms_Api,TMTNormalRooms_Api;

typedef struct tagTMTNormalRoomList_Api
{
	u32						dwStart;
	u32						dwCount;
	TMTShortRooms_Api		tRooms;
public:
	tagTMTNormalRoomList_Api(){ memset( this ,0 ,sizeof(tagTMTNormalRoomList_Api) );}
}*PTMTNormalRoomList_Api,TMTNormalRoomList_Api;

/** ��������Ϣ */
typedef struct tagTMTRoomInfo_Api
{
	u32		dwId;
	s8		achName[KMTAPI_MAX_CONF_NAME_LEN+1];
	s8		achRegionName[KMTAPI_MG_MAX_REGIONNAME_LEN+1];
public:
	tagTMTRoomInfo_Api(){ memset( this ,0 ,sizeof(tagTMTRoomInfo_Api) );}
}*PTMTRoomInfo_Api,TMTRoomInfo_Api;

/** ������������������ */
typedef struct tagTMTRoomListByName_Api
{
	u32		dwStart;
	u32		dwCount;
	u32		dwOrder;
	s8		achName[KMTAPI_MG_MAX_MEETING_NAME_LEN+1];
public:
	tagTMTRoomListByName_Api(){ memset( this ,0 ,sizeof(tagTMTRoomListByName_Api) );}
}*PTMTRoomListByName_Api,TMTRoomListByName_Api;

/** ���ݻ�������Դ���������� */
typedef struct tagTMTQueryRooms_Api
{
	u32		dwStart;
	u32		dwCount;
	u32		dwOrder;
	u32		dwPeopleAdmit;
	u32		dwDeviceIdMask;
public:
	tagTMTQueryRooms_Api(){ memset( this ,0 ,sizeof(tagTMTQueryRooms_Api) );}
}*PTMTQueryRooms_Api,TMTQueryRooms_Api;


typedef struct tagTMTTemplate_Api
{
	s8      achTemplateID[KMTAPI_CM_MAX_TEMPLATE_ID_LEN+1];
	s8      achTemplateName[KMTAPI_CM_MAX_TEMPLATE_NAME_LEN+1];
public:
	tagTMTTemplate_Api(){ memset( this ,0 ,sizeof(tagTMTTemplate_Api) );}
}*PTMTTemplate_Api,TMTTemplate_Api;


typedef struct tagTMTTemplates_Api
{
	u32           			nCount;
	TMTTemplate_Api       	atItems[KMTAPI_MG_MAX_TEMPLATES_NUM];///< chqw:����Ľṹ������Ԫ����������ʱʹ��MT_MAX_COUNT����Ϊ�ն���Ӧ�Ķ���ֱ��ʹ��repeated��
public:
	tagTMTTemplates_Api(){ memset( this ,0 ,sizeof(tagTMTTemplates_Api) );}
}*PTMTTemplates_Api,TMTTemplates_Api;

typedef struct tagTMTTemplateList_Api
{
	TMTTemplates_Api	tTemplates;
public:
	tagTMTTemplateList_Api(){ memset( this ,0 ,sizeof(tagTMTTemplateList_Api) );}
}*PTMTTemplateList_Api,TMTTemplateList_Api;

typedef struct tagTMTPerson_Api
{
	s8				achMoId[KMTAPI_MAX_DOMAIN_MOID_LEN+1];
	s8				achEmail[KMTAPI_MAX_EMAIL_LEN+1];
	s8				achName[KMTAPI_MAX_MT_E164_LEN+1];
	s8				achParticipantNo[KMTAPI_MAX_DOMAIN_MOID_LEN+1];
	BOOL32   		bIsParticipant;
	u32				dwParticipantType;
public:
	tagTMTPerson_Api(){ memset( this ,0 ,sizeof(tagTMTPerson_Api) );}
}*PTMTPerson_Api,TMTPerson_Api;

typedef struct tagTMTPersons_Api
{
	u32					dwCount;
	TMTPerson_Api		atItems[KMTAPI_MG_MAX_MEETING_PERSON_NUM];
public:
	tagTMTPersons_Api(){ memset( this ,0 ,sizeof(tagTMTPersons_Api) );}
}*PTMTPersons_Api,TMTPersons_Api;

typedef struct tagTMTTemplateInfo_Api
{
	s8		achTemplateID[KMTAPI_CM_MAX_TEMPLATE_ID_LEN+1];
	s8		achTemplateName[KMTAPI_CM_MAX_TEMPLATE_NAME_LEN+1];
	s8		achTemplateResolution[KMTAPI_BUF_32_LEN+1];
	s8		achBandwidth[KMTAPI_BUF_32_LEN+1];
	TMTPersons_Api	tPersons;
public:
	tagTMTTemplateInfo_Api(){ memset( this ,0 ,sizeof(tagTMTTemplateInfo_Api) );}
}*PTMTTemplateInfo_Api,TMTTemplateInfo_Api;

/** ���������� */
typedef struct tagTMTLockRoom_Api
{
	s32     nRoomId;
	s8		achStartTime[KMTAPI_MG_MAX_MEETING_DATETIME_LEN+1];
	s8		achEndTime[KMTAPI_MG_MAX_MEETING_DATETIME_LEN+1];
public:
	tagTMTLockRoom_Api(){ memset( this ,0 ,sizeof(tagTMTLockRoom_Api) );}
}*PTMTLockRoom_Api,TMTLockRoom_Api;

typedef struct tagTListNotifyByMax_Api
{
	u32     dwId;                          ///<�����ָ��Ϣ��
	u32     dwMessageType;
public:
	tagTListNotifyByMax_Api(){ memset( this ,0 ,sizeof(tagTListNotifyByMax_Api) );}
}*PTListNotifyByMax_Api,TListNotifyByMax_Api;

typedef struct tagTIfExistLockByFormkey_Api
{
	s8       achFormkey[KMTAPI_MG_MAX_COMMON_BUF_LEN+1];
public:
	tagTIfExistLockByFormkey_Api(){ memset( this ,0 ,sizeof(tagTIfExistLockByFormkey_Api) );}
}*PTIfExistLockByFormkey_Api,TIfExistLockByFormkey_Api;

/** ��������Ļ���Id */
typedef struct tagTMTMeetingIDs_Api
{
	u32		dwCount;							        	///< ��������Ļ������
	u32		adwItems[KMTAPI_MG_MAX_REGULAR_NUM];			///< ����Id
public:
	tagTMTMeetingIDs_Api(){ memset( this ,0 ,sizeof(tagTMTMeetingIDs_Api) );}
}*PTMTMeetingIDs_Api,TMTMeetingIDs_Api;

/** ����Id��ȡ������Ϣ */
typedef struct tagTMTRegularInfo_Api
{
	u32							dwId;												 ///< ����Id
	s8							achSubject[ KMTAPI_MG_MAX_MEETING_SUBJECT_LEN+1];	 ///< ����
	s8							achStartTime[ KMTAPI_MG_MAX_MEETING_DATETIME_LEN+1]; ///< ��ʼʱ��
	s8							achEndTime[ KMTAPI_MG_MAX_MEETING_DATETIME_LEN+1];	 ///< ����ʱ��
	u32							dwStatus;										     ///< ����״̬
	s8							achOrganizer[KMTAPI_MG_MAX_ORGANIZER_LEN+1];		 ///< ��֯��
	s8							achOrganizerMail[KMTAPI_MG_ORGANIZERMAIL_LEN+1];	 ///< ��֯��email
	s8							achPhone[KMTAPI_MT_MAX_TELEPHONE_LEN+1];			 ///< ��֯�˵绰
	s8							achMobile[KMTAPI_MT_MAX_TELEPHONE_LEN+1];			 ///< ��֯���ֻ�
	s8							achBrief[KMTAPI_MG_MAX_MEETING_BRIEF_LEN+1];		 ///< ����
	u32							dwIsVideo;											 ///< �Ƿ�����Ƶ����
	s8							achStartDate[ KMTAPI_MG_MAX_MEETING_DATETIME_LEN+1]; ///< ��ʼ����
	s8							achEndDate[ KMTAPI_MG_MAX_MEETING_DATETIME_LEN+1];	 ///< ��������
	u32							dwRepeatType;										 ///< �ظ�����	
	u32							dwFrequency;										 ///< �ظ�Ƶ��
	s8							achWeekDays[KMTAPI_MG_MAX_COMMON_BUF_LEN+1];		 ///< �����ظ�����Ҫִ�е�ʱ���
	TMTMeetingIDs_Api			tMeetingIDs;

public:
	tagTMTRegularInfo_Api(){ memset( this ,0 ,sizeof(tagTMTRegularInfo_Api) );}
}*PTMTRegularInfo_Api,TMTRegularInfo_Api;

typedef struct tagTMeetingUnlock_Api
{
	s8        achMeetingFormKey[KMTAPI_MG_MAX_COMMON_BUF_LEN+1];

public:
	tagTMeetingUnlock_Api(){ memset( this ,0 ,sizeof(tagTMeetingUnlock_Api) );}
}*PTMeetingUnlock_Api,TMeetingUnlock_Api;

typedef struct tagTRegularFeed_Api
{
	u32				dwRegularId;
	u32				dwJoinType;
	u32				dwRejectReason;
	BOOL32			bAccept;
	s8				achParticipantNo[KMTAPI_MG_MAX_COMMON_BUF_LEN+1];

public:
	tagTRegularFeed_Api(){ memset( this ,0 ,sizeof(tagTRegularFeed_Api) );}
}*PTRegularFeed_Api,TRegularFeed_Api;

typedef struct tagTMTRegion_Api
{
	u32				dwId;
	s8		        achName[KMTAPI_MG_MAX_MEETING_REGION_NAME_LEN+1];

public:
	tagTMTRegion_Api(){ memset( this ,0 ,sizeof(tagTMTRegion_Api) );}
}*PTMTRegion_Api,TMTRegion_Api;

typedef struct tagTMTRegions_Api
{
	u32                     dwCount;
	TMTRegion_Api			atItems[KMTAPI_MG_MAX_MEETING_REGION_NUM];
	s8				        achCompanyId[KMTAPI_MG_MAX_MEETING_COMPANY_NAME_LEN+1];

public:
	tagTMTRegions_Api(){ memset( this ,0 ,sizeof(tagTMTRegions_Api) );}
}*PTMTRegions_Api,TMTRegions_Api;

typedef struct tagTMTLockRooms_Api
{
	s32			anRoomIds[KMTAPI_MG_MAX_ROOMS_NUM];
	u32			dwRoomIdsCnt;
	s8			achStartTime[KMTAPI_MG_MAX_MEETING_DATETIME_LEN+1];
	s8			achEndTime[KMTAPI_MG_MAX_MEETING_DATETIME_LEN+1];

public:
	tagTMTLockRooms_Api(){ memset( this ,0 ,sizeof(tagTMTLockRooms_Api) );}
}*PTMTLockRooms_Api,TMTLockRooms_Api;

typedef struct tagTMTRoomLockResultItem_Api
{
	u32					dwId;
	u32					dwResult;

	s8			        achName[KMTAPI_MG_MAX_ROOM_NAME_LEN+1];
public:
	tagTMTRoomLockResultItem_Api(){ memset( this ,0 ,sizeof(tagTMTRoomLockResultItem_Api) );}
}*PTMTRoomLockResultItem_Api,TMTRoomLockResultItem_Api;

typedef struct tagTMTRoomLockResultItems_Api
{
	u32								dwCount;
	u32								dwSuccess;
	s8						        achMeetingFormkey[KMTAPI_MG_MAX_ROOM_NAME_LEN+1];
	s8			                    achStartTime[KMTAPI_MG_MAX_MEETING_DATETIME_LEN+1];
	s8			                    achEndTime[KMTAPI_MG_MAX_MEETING_DATETIME_LEN+1];
	TMTRoomLockResultItem_Api		atItems[KMTAPI_MG_MAX_ROOMS_LOCK_RESULT_NUM];

public:
	tagTMTRoomLockResultItems_Api(){ memset( this ,0 ,sizeof(tagTMTRoomLockResultItems_Api) );}
}*PTMTRoomLockResultItems_Api,TMTRoomLockResultItems_Api;

typedef struct tagTMeetingNotify_Api
{
	EmRestMeetingNotifyType_Api     emNotifyType;
	s8								achMoId[KMTAPI_MAX_DOMAIN_MOID_LEN+1];
	u32								dwNotifyId;
	u32								dwNum;

public:
	tagTMeetingNotify_Api(){ memset( this ,0 ,sizeof(tagTMeetingNotify_Api) );}
}*PTMeetingNotify_Api,TMeetingNotify_Api;

typedef struct tagTAppClearNotify_Api
{
	s8        achNotifyType[KMTAPI_GM_NOTIFY_SIZE+1];
public:
	tagTAppClearNotify_Api(){ memset( this ,0 ,sizeof(tagTAppClearNotify_Api) );}
}*PTAppClearNotify_Api,TAppClearNotify_Api;

/** TRestErrorInfo_Api�ֶκ�u32�ֶν��(������Ϣ�л��õ�) */
typedef struct tagTMgErrKeyPair_Api
{
	TRestErrorInfo_Api		tErrInfo;			///< ������Ϣ
	u32						dwKey;				///< �����б�

public:
	tagTMgErrKeyPair_Api(){ memset( this ,0 ,sizeof(tagTMgErrKeyPair_Api) );}
}*PTMgErrKeyPair_Api,TMgErrKeyPair_Api;


typedef struct tagTMTGetPerTemplateList_Api
{
	u32 dwStart;			///< ����ģ��Ŀ�ʼ�У�Ĭ��Ϊ0�����ӷ��������������еĵڼ���ȡ���ݣ�0Ϊ��һ������
	u32 dwCount;			///< ��ȡ�ĸ���ģ������Ĭ��Ϊ10�����ڰ���start���ڵĺ�count�����ݣ��������Ϊ0��ʾ��ȡ���и���ģ��
	u32 dwOrder;			///< ���ݸ���ģ�������޸�ʱ������0��������1������Ĭ��Ϊ0

public:
	tagTMTGetPerTemplateList_Api(){ memset( this ,0 ,sizeof(tagTMTGetPerTemplateList_Api) );}
}*PTMTGetPerTemplateList_Api, TMTGetPerTemplateList_Api;

typedef struct tagTMTPerTemplate_Api
{
	TMTTemplateAccount_Api		tAdmin;							///< ����
	u32							dwBitrate;						///< ��������
	EmMtDualMode_Api			emDualmode;						///< ˫������
	u32							dwDuration;						///< ʱ��
	s8							achEncryptedkey[ KMTAPI_BUF_32_LEN+1 ];				///< AES����KEY
	EmEncryptArithmetic_Api		emEncryptedtype;				///< �����������
	BOOL32						bInitmute;						///< ��ʼ������  1�ǣ�0��
	EmMtOpenMode_Api	emMeetingsafe;					        ///< ���鰲ȫ
	EmMeetingSafeType_Api	emMeetingtype;				    	///< 1 �˿ڻ���   0 ��ͳý�����
	u32							dwMemberNum;					///< �λ�������
	TMTTemplateAccount_Api		atMembers[ KMTAPI_COUNT_256];	///< �λ���
	TMTSetMixInfo_Api				tMixInfo;						///< ��������
	s8							achName[ KMTAPI_BUF_128_LEN+1 ];						///< ģ������
	s8							achPassword[ KMTAPI_BUF_128_LEN+1 ];					///< ����
	BOOL32						bPublicmeeting;					///< �Ƿ񹫹�������  1�ǣ�0��
	EmMtResolution_Api			emResolution;					///< ����ֱ���
	TMTCreateRecordRecord_Api		tRecord;				    ///< ¼������ 
	TMTCreateConfSatellite_Api	tSatellite;				///< ���ǻ�������
	TMTTemplateAccount_Api		tSpeaker;				///< ������
    TMTCreateConfVmp_Api        tVmp;          ///< ����ϳ�����
	u32							dwTemplateid;			///< ID�ţ���ӵ�ʱ�򣬲���޸ĵ�ʱ���

	u32 dwVFormatNum;
	TMTVideoFormatList_Api			tVideoFormatList[KMTAPI_COUNT_16];

	u32 dwAFormatNum;
	TMTAudioFormatList_Api			tAudioFormatList[KMTAPI_COUNT_16];

	u32 dwDualFormatNum;
	TMTDualFormatList_Api			tDualFormatList[KMTAPI_COUNT_8];

	u32 dwVipNum;						///< VIP�˺�����
	TMTTemplateAccount_Api			atViplist[KMTAPI_COUNT_256];			///< VIP�˺�

	EmClosedMeeting_Api emClosedMeeting;                 ///< ��������ţ�1������0�ر�
    u32 dwMeetingScale;                                                   ///< �����ģ,0���գ�1��4����Ƶ����,2��8����Ƶ����,3��������Ƶ����
    u32 dwOneReforming;                                                 ///< ��һ����,0:�ر�; 1:����
    BOOL32 bVoiceInspireEnable;                                     ///< �Ƿ�����������
    u32 dwVoiceInspireTime;                                             ///< �����������ж�
public:
	tagTMTPerTemplate_Api()
	{ 
		memset( this ,0 ,sizeof(tagTMTPerTemplate_Api) );
		emMeetingsafe = emMt_Open_Api;
	}
}*PTMTPerTemplate_Api, TMTPerTemplate_Api;

/*************************************************************************************/
/* ��������� */


typedef struct tagTMTVConfMember_Api
{
	s8		achName[ KMTAPI_BUF_128_LEN+1 ];			///< ����
	s8		achAccount[ KMTAPI_BUF_128_LEN+1 ];			///< �ʺ�
	EmMtAddrType_Api	emAccountType;					///< �ʺ�����
	EmConfProtocol_Api	emProtocol;						///< ����Э��

public:
	tagTMTVConfMember_Api(){ memset( this ,0 ,sizeof(tagTMTVConfMember_Api) );}
}*PTMTVConfMember_Api, TMTVConfMember_Api;

typedef struct tagTMTCreateVConf_Api
{
	u32		dwVConfId;									///< ���������id
	s8		achVConfName[ KMTAPI_BUF_64_LEN+1] ;		///< ��������
	u32		dwDuration;									///< ����ʱ��(0Ϊ���û���)
	
	u32					dwMemberNum;
	TMTVConfMember_Api	atMember[ KMTAPI_COUNT_192+1 ];

public:
	tagTMTCreateVConf_Api(){ memset( this ,0 ,sizeof(tagTMTCreateVConf_Api) );}
}*PTMTCreateVConf_Api, TMTCreateVConf_Api;

typedef struct tagTMTVConfResult_Api
{
	BOOL32	bSuccess;									///< �Ƿ�ɹ�
	u32		dwErrorCode;								///< ������
	s8		achDescription[ KMTAPI_BUF_64_LEN +1 ];		///< �������
	s8		acTemplateId[ KMTAPI_BUF_64_LEN+1 ];		///< ģ��ID
public:
	tagTMTVConfResult_Api(){ memset( this ,0 ,sizeof(tagTMTVConfResult_Api) );}
}*PTMTVConfResult_Api, TMTVConfResult_Api;

typedef struct tagTMTVConfListReq_Api
{
	u32		dwCount;									///< ��ȡ�������������Ĭ��Ϊ10�����ڰ���start���ڵĺ�count�����ݣ��������Ϊ0��ʾ��ȡ�������������
	u32		dwOrder;									///< ������������ʱ������Ĭ��Ϊ0 	0-����	1-����
	u32		dwStart;									///< �������Ŀ�ʼ�У�Ĭ��Ϊ0�����ӷ��������������еĵڼ���ȡ���ݣ�0Ϊ��һ������

public:
	tagTMTVConfListReq_Api(){ memset( this ,0 ,sizeof(tagTMTVConfListReq_Api) );}
}*PTMTVConfListReq_Api, TMTVConfListReq_Api;

typedef struct tagTMTVConfInfo_Api
{
	s8		achConfId[ KMTAPI_GM_MAX_E164+1 ];				///< �������Ψһ��ʶ
	s8		achConfE164[ KMTAPI_GM_MAX_E164+1 ];			///< ����������
	s8		achVirualRoomName[ KMTAPI_BUF_64_LEN+1 ];		///< ������������� ����ַ����ȣ�64���ַ�
	s8		achConfName[ KMTAPI_BUF_64_LEN+1 ];				///< �������⣬���ʹ���е���������ң����������Ϊ��

	EmMtOpenMode_Api	emSafeConf;							///< ���鰲ȫ
	EmMtVConfStatus_Api		emConfStatus;						///< ����״̬
	EmMtMaxJoinMt_Api		emMaxJoinMt;						///< �������ն���

	s8		achEncryptedKey[ KMTAPI_BUF_16_LEN+1 ];			///< �������AES������Կ

	u32		dwBitrate;										///< ��������
	BOOL32	bExclusive;										///< �Ƿ���ר�������� 

	u32					dwExUsrNum;
	TMTVConfMember_Api	atExUser[ KMTAPI_COUNT_192+1 ];		///< ר����Ա�б�

	EmMtResolution_Api	emResolution;						///< �ֱ���

public:
	tagTMTVConfInfo_Api(){ memset( this ,0 ,sizeof(tagTMTVConfInfo_Api) );}
}*PTMTVConfInfo_Api, TMTVConfInfo_Api;

typedef struct tagTMTVConfList_Api
{
	u32		dwTotal;
	TMTVConfInfo_Api	atConfInfo[ KMTAPI_COUNT_4+1 ];

public:
	tagTMTVConfList_Api(){ memset( this ,0 ,sizeof(tagTMTVConfList_Api) );}
}*PTMTVConfList_Api, TMTVConfList_Api;

typedef struct tagTMTVConfResource_Api
{
	s8		achName[KMTAPI_BUF_128_LEN+1];
	EmMtResolution_Api		emResolution;
	EmMtMaxJoinMt_Api		emMaxJoinMt;
	u32		dwTotal;	///< ��Դ����
	u32		dwUsed;		///< ��Դ��ռ����
			
public:
	tagTMTVConfResource_Api(){ memset( this ,0 ,sizeof(tagTMTVConfResource_Api) );}
}*PTMTVConfResource_Api, TMTVConfResource_Api;

typedef struct tagTMTVConfResources_Api
{
	u32		dwNum;		
	TMTVConfResource_Api		atResource[ KMTAPI_COUNT_192+1 ];
	EmResourceType_Api			emResourceType;

public:
	tagTMTVConfResources_Api(){ memset( this ,0 ,sizeof(tagTMTVConfResources_Api) );}
}*PTMTVConfResources_Api, TMTVConfResources_Api;

typedef struct tagTMTVConfRecord_Api
{
	EmPublishMode_Api emPublishMode;                        ///< ����ģʽ
	EmRecordMode_Api  emRecordMode;                         ///< ¼��ģʽ
	BOOL32		bDoubleFlow;									///< �Ƿ����ݹ���¼��
	BOOL32		bAnonymous;									///< �Ƿ�֧�����½�ۿ�ֱ��
	
	s8			achVrsId[ KMTAPI_BUF_128_LEN +1 ];			///< VRS��moid

public:
	tagTMTVConfRecord_Api(){ memset( this ,0 ,sizeof(tagTMTVConfRecord_Api) );}
}*PTMTVConfRecord_Api, TMTVConfRecord_Api;

/**������������� */
typedef struct tagTMTVConfDetailInfo_Api
{
	s8				                achVirtualRoomName[ KMTAPI_BUF_128_LEN+1 ];        ///< �������������
	s8								achConfE164[ KMTAPI_GM_MAX_E164+1 ];
	u32				                dwDuration;                             ///< �������ʱ��(0�����û���)
	u32				                dwBitrate;                              ///< ��������

	u32						        dwVideoCount;
	TMTVideoFormatList_Api          atVideoFormatList[KMTAPI_COUNT_16];

	s8				            	achConfName[ KMTAPI_BUF_128_LEN+1 ];    ///< ��������
	EmMeetingSafeType_Api		    emMeetingType;                          ///< �����Ƿ��� �˿ڻ���
	EmMtOpenMode_Api		        emMeetingSafe;                          ///< ���鰲ȫmode

	EmMtVConfStatus_Api				emConfStatus;							///< ����״̬
	EmMtMaxJoinMt_Api				emMaxJoinMt;							///< �������ն��� 

	EmRestCascadeMode_Api emCascadeMode;///< ����ģʽ,0�򵥼�����1�ϲ�����
	BOOL32 bCascadeUpload;              ///< �Ƿ����ϴ�:1�ǣ�0��
	BOOL32 bCascadeReturn;              ///< �Ƿ����ش�:1�ǣ�0��
	u32 dwCascadeReturnPara;            ///< �����ش��������

	BOOL32                          bInitMute;                              ///< ��ʼ��������1�ǣ�0��
	BOOL32 							bMuteFilter;							///< �Ƿ���ȫ���������⣺1-������0-������

	TMTGetMixInfo_Api		    tMixInfo;                             		///< ���������Ϣ

	EmVmpMode_Api				emVmpMode; ///<����ϳ�ģʽ��1-���ָ��;2-�Զ�

//	TMTConfVMPInfo_Api			tVmp;                                  			///< ����ϳ�ģʽ

	TMTVConfRecord_Api      tRecord;                    					///< ¼������ 

	BOOL32 							bPreoccpuyResource; 					///< �Ƿ�Ԥռ��Դ 

	EmEncryptArithmetic_Api			emEncryptedType;                        ///< ������ܷ�ʽ
	s8								achEncryptedKey[ KMTAPI_BUF_32_LEN+1 ]; ///< ������Կ

	EmMtDualMode_Api                emDualMode;                             ///< ˫��Ȩ��

	EmAnswerMode_Api				emAnswerMode; 							///< ����ģʽ
	u32								dwCallTimes;							///< ���д���
	u32								dwCallInterval;							///< ���м��(��)
	BOOL32							bVoiceInspireEnable;					///< �Ƿ������Լ�����1�ǣ�0��
	u32								dwOneReforming;                         ///< ��һ����,0:�ر�; 1:����

	EmMtFecMode_Api					emFecMode;							///< FEC����
	BOOL32							bExclusive;							///< �Ƿ���ר�����������

	u32					dwExUsrNum;
	TMTVConfMember_Api	atExUser[ KMTAPI_COUNT_192+1 ];		///< ר����Ա�б�

public:
	tagTMTVConfDetailInfo_Api(){memset( this, 0, sizeof(tagTMTVConfDetailInfo_Api) ); }
}*PTMTVConfDetailInfo_Api, TMTVConfDetailInfo_Api;


/*************************************************************************************/
/* ������Ϣ */
typedef struct tagTMTConfMixInfo_Api
{
    EmMtMixType_Api emMode;                                   ///< 0-��������1-���ۿ�ʼ��2-���ƻ���
    u32 dwMixMemberCount;                                     ///< ��Ա����
    TMTCreateConfMember_Api atMixMemberList[KMTAPI_COUNT_64]; ///< �����б�
public:
    tagTMTConfMixInfo_Api(){ memset( this ,0 ,sizeof(tagTMTConfMixInfo_Api) );}
}*PTMTConfMixInfo_Api, TMTConfMixInfo_Api;

/* ������Ϣ ��Ҫ*/
typedef struct tagTMTConfMixBrief_Api
{
    EmMtMixType_Api emMode;                                   ///< 0-��������1-���ܻ�����2-���ƻ���
public:
    tagTMTConfMixBrief_Api(){ emMode = emMcuNoMix_Api; }
}*PTMTConfMixBrief_Api, TMTConfMixBrief_Api;

/*���ǻ�������*/
typedef struct tagTMTConfSatelliteInfo_Api
{
    s8  achMulticastAddr[ KMTAPI_BUF_64_LEN+1 ];    ///< ����IP��ַ
    u32 dwPort;                                     ///< �˿�
    u32 dwReturnNum;                                ///< �ش���
public:
    tagTMTConfSatelliteInfo_Api(){ memset( this ,0 ,sizeof(tagTMTConfSatelliteInfo_Api) );}
}*PTMTConfSatelliteInfo_Api, TMTConfSatelliteInfo_Api;

/* ¼������ */
typedef struct tagTMTConfRecordInfo_Api
{
    BOOL32 bDoubleFlow;			    ///< �Ƿ�����˫����1�ǣ�0��
    BOOL32 bMain;					///< �Ƿ�����������1�ǣ�0��
    BOOL32 bPublish;				///< �Ƿ񷢲�¼��1�ǣ�0��
public:
    tagTMTConfRecordInfo_Api(){ memset( this ,0 ,sizeof(tagTMTConfRecordInfo_Api) );}
}*PTMTConfRecordInfo_Api, TMTConfRecordInfo_Api;

/** �鲥���� */
typedef struct tagTMTConfMultiCastInfo_Api
{
    s8 achMulticastAddr[KMTAPI_BUF_64_LEN+1];    ///<��ַ
    u32 dwPort;                                  ///<�˿�
public:
    tagTMTConfMultiCastInfo_Api() { memset( this, 0, sizeof(tagTMTConfMultiCastInfo_Api) ); }
}*PTMTConfMultiCastInfo_Api, TMTConfMultiCastInfo_Api;

//����ϳɲ���(�����ṹ��)
typedef struct tagTMTNameStyle_Api
{
    u32 dwFontSize; ///̨�������С 0-С��1-�У�2-��
    u32 dwPosition; ///̨����ʾλ�ã�Ĭ��Ϊ1 0-���Ͻǣ�1-���½ǣ�2-���Ͻǣ�3-���½ǣ�4-�ײ��м䣻
    s8  achFontColor[KMTAPI_COUNT_32];  ///̨��������ԭɫ#RGB��ʽ��ʮ�����Ʊ�ʾ��Ĭ��Ϊ��#FFFFFF��ɫ
public:
    tagTMTNameStyle_Api() { memset( this, 0, sizeof(tagTMTNameStyle_Api) ); }
}*PTMTNameStyle_Api, TMTNameStyle_Api;

/** ����ϳ����� */
typedef struct tagTMTConfVMPInfo_Api
{
    BOOL32 bEnable;          ///<�Ƿ����ã�1��0��
    EmVmpMode_Api    emMode; ///<����ϳ�ģʽ��1-���ָ��;2-�Զ�
    EmMtVmpStyle_Api emStyle;///<���
    BOOL32 bVoiceHint;       ///<�Ƿ�ʶ��������Դ:1��0��
    BOOL32 bShowMTName;      ///<�Ƿ���ʾ������1��0��
    BOOL32 bIsBroadcast;     ///<�Ƿ�㲥
    u32 dwMemberCount;       ///<��Ա����
    TMTTemplateVmpMember_Api atMemberList[KMTAPI_MAX_VMP_MEMBER_NUM];///<����ϳɳ�Ա�б�
    TMTNameStyle_Api         atNameStyle;   ///����ϳ�̨�����
public:
    tagTMTConfVMPInfo_Api() { memset( this, 0, sizeof(tagTMTConfVMPInfo_Api) ); }
}*PTMTConfVMPInfo_Api, TMTConfVMPInfo_Api;

/** ����ϳ����� ��Ҫ*/
typedef struct tagTMTConfVMPBrief_Api
{
    BOOL32           bEnable;  ///<�Ƿ����ã�1��0��
    EmVmpMode_Api    emMode;   ///<����ϳ�ģʽ��1-���ָ��;2-�Զ�
public:
    tagTMTConfVMPBrief_Api() { bEnable = FALSE; emMode = emScreenVmp_Api; }
}*PTMTConfVMPBrief_Api, TMTConfVMPBrief_Api;

/**��ѯ����  */
/*typedef struct tagTMTConfPollInfo_Api
{
    BOOL32 bEnable;   ///<�Ƿ����ã�1��0��
    EmPollMode_Api emMode;  ///<��ѯģʽ 1-��ͼ����ѯ 3-����Ƶ��ѯ
    u32 dwNum;        ///<��ѯ������0���޴���ѯ
    u32 dwInterval;   ///<��ѯ���ʱ��(��)
    u32 dwMemberCount;///<��Ա����
    TMTCreateConfMember_Api atMemberList[KMTAPI_COUNT_192];///<��ѯ��Ա�б�
public:
    tagTMTConfPollInfo_Api() { memset( this, 0, sizeof(tagTMTConfPollInfo_Api) ); }
}*PTMTConfPollInfo_Api, TMTConfPollInfo_Api;
*/
/*¼������*/
typedef struct tagTMTRecordAttribute_Api
{
    EmPublishMode_Api emPublishMode;                        ///< ����ģʽ
    EmRecordMode_Api  emRecordMode;                         ///< ¼��ģʽ
    BOOL32            bAnonymous;                                   ///< �Ƿ�֧�����½�ۿ�ֱ�� FALSE-��֧�֣�TRUE-֧�֣�
    BOOL32            bDualStream;                          ///<�Ƿ����ݹ���¼��0-��1-�ǣ�(����)
    s8                achVrsId[KMTAPI_BUF_64_LEN+1];        ///VRS��moid
public:
    tagTMTRecordAttribute_Api() { memset( this, 0, sizeof(tagTMTRecordAttribute_Api) ); }
}*PTMTRecordAttribute_Api, TMTRecordAttribute_Api;
/*¼������ ��Ҫ*/
typedef struct tagTMTRecordAttributeBrief_Api
{
    EmRecordMode_Api  emRecordMode;                     ///< ¼��ģʽ
    s8                achVRSID[KMTAPI_BUF_64_LEN+1];	///< VRS��moid
public:
    tagTMTRecordAttributeBrief_Api() { memset( this, 0, sizeof(tagTMTRecordAttributeBrief_Api) ); }
}*PTMTRecordAttributeBrief_Api, TMTRecordAttributeBrief_Api;

typedef struct tagTMTDCSAttribute_Api
{
    EmDcsConfMode_Api emDCSMode;           ///< ����Э��ģʽ
public:
    tagTMTDCSAttribute_Api() { emDCSMode = emConfModeStop_Api; }
}*PTMTDCSAttribute_Api, TMTDCSAttribute_Api;

/*����ģ�� - ��Ӧ�µ�ƽ̨API*/
typedef struct tagTMTPeronalTemplate_Api
{
    s8						    achTemplateID[KMTAPI_BUF_128_LEN+1];	///< ID�ţ���ӵ�ʱ�򣬲���޸ĵ�ʱ���
    s8							achName[ KMTAPI_BUF_128_LEN+1 ];		///< ģ������
    u32							dwBitrate;						        ///< ��������
    EmClosedMeeting_Api         emCloseConf;                            ///< ��������ţ�1������0�ر�
    EmMtOpenMode_Api	        emSafeConf;					            ///< ���鰲ȫ

    s8							achPassword[ KMTAPI_BUF_128_LEN+1 ];    ///< ����
    EmEncryptArithmetic_Api		emEncryptedtype;                        ///< �����������
    EmMeetingSafeType_Api	    emMeetingtype;                          ///< 1 �˿ڻ���   0 ��ͳý�����
    u32                         dwCallTimes;                            ///<  ���д���
    u32                         dwCallInterval;                         ///<  ���м��(��)

    BOOL32						bInitmute;                              ///<  ��ʼ������  1�ǣ�0��
    BOOL32                      bInitSilence;                           ///< ��ʼ������1�ǣ�0��
    EmVideoQuality_Api          emVidoQuality;                          ///< ��Ƶ����,0���������ȣ�1���ٶ�����
    u32                         dwOneReforming;                         ///< ��һ����,0:�ر�; 1:����
    s8							achEncryptedkey[ KMTAPI_BUF_32_LEN+1 ]; ///< AES����KEY

    EmMtDualMode_Api			emDualmode;						        ///< ˫������
    BOOL32                      bVoiceActivityDetection;                ///< �Ƿ������Լ�����1�ǣ�0��
    u32                         dwVacinterval;                          ///< �����������ж�(s)��֧��5��15��30��60
    EmRestCascadeMode_Api       emCascadeMode;                          ///< ����ģʽ,0�򵥼�����1�ϲ�����
    BOOL32                      bCascadeUpload;                         ///< �Ƿ����ϴ�:1�ǣ�0��

    BOOL32                      bCascadeReturn;                         ///< �Ƿ����ش�:1�ǣ�0��
    u32                         dwCascadeReturnPara;                    ///< �����ش��������
    BOOL32						bPublicConf;                            ///< �Ƿ񹫹�������  1�ǣ�0��
    u32                         dwMaxJoinMt;                            ///< �������ն������������ģ,0���գ�4��4����Ƶ����,8��8����Ƶ����,192��������Ƶ���飩
    BOOL32                      bAutoEnd;                               ///< �Ƿ��Զ���᣺1�ǣ�0��

    BOOL32                      bPreoccpuyResouce;                      ///< Ԥռ��Դ 0-��Ԥռ 1-Ԥռ
    TMTCreateConfMember_Api     tSpeaker;                               ///< ������
    TMTCreateConfMember_Api     tChairman;                              ///< ��ϯ
    TMTConfMixInfo_Api          tMix;                                   ///< ������Ϣ

    u32                         dwVFormatNum;
    TMTVideoFormatList_Api      atVideoFormatList[KMTAPI_COUNT_16];     ///< ����Ƶ��ʽ�б�

    u32                         dwIMemberNum;
    TMTInviteMember_Api         atInviteMembers[ KMTAPI_COUNT_256];     ///< �λ��Ա

    TMTConfVMPInfo_Api          tVmp;                                   ///< ����ϳ�����
    
    u32                         dwVipNum;
    TMTCreateConfMember_Api     atViplist[KMTAPI_COUNT_256];            ///< VIP�˺�
    
    TMTConfPollInfo_Api       tPoll;                                    ///< ��ѯ����
	BOOL32						bEncryptedAuth;                         ///< �Ƿ�˫����֤ 0-�ر� 1-����
    EmCallMode_Api              emCallMode;                             ///< ����ģʽ��
    TMTRecordAttribute_Api      tRecordAttr;                            ///< ¼������
    TMTDCSAttribute_Api         tDCSAttr;                               ///< ����Э��
    EmMtFecMode_Api             emFecMode;                              ///< FEC����
    BOOL32                      bMuteFilter;                            ///�Ƿ���ȫ���������� 0-�����κ������⣻1-�Է��Է��͹������⣻
    BOOL32                      bDoubleFlow;                            ///��Ϊ�����˺������������ݹ���0-��1-�ǣ�
    u32                         dwDuration;                             ///����ʱ��
    TMTCreateConfMember_Api     atKeepCallingMembers[KMTAPI_COUNT_256]; ///׷����Ա����
    u32                         dwKeepCallNum;                          //׷����Ա����
public:
	tagTMTPeronalTemplate_Api()
	{ 
		memset( this ,0 ,sizeof(tagTMTPeronalTemplate_Api) );
        emSafeConf = emMt_Open_Api;
	}
}*PTMTPeronalTemplate_Api, TMTPeronalTemplate_Api;

/*�򵥸���ģ��-��Ӧ�µ�ƽ̨API*/
typedef struct tagTMTSimplePeronalTemplate_Api
{
    s8						    achTemplateID[KMTAPI_BUF_128_LEN+1];	///< ID�ţ���ӵ�ʱ�򣬲���޸ĵ�ʱ���
    s8							achName[ KMTAPI_BUF_128_LEN+1 ];		///< ģ������
    u32							dwBitrate;						        ///< ��������
    EmClosedMeeting_Api         emCloseConf;                            ///< ��������ţ�1������0�ر�
    
    EmMtOpenMode_Api	        emSafeConf;					            ///< ���鰲ȫ
    s8							achPassword[ KMTAPI_BUF_128_LEN+1 ];    ///< ����
    EmEncryptArithmetic_Api		emEncryptedtype;                        ///< �����������
    EmMeetingSafeType_Api	    emMeetingtype;                          ///< 1 �˿ڻ���   0 ��ͳý�����
    u32                         dwCallTimes;                            ///< ���д���
    
    u32                         dwCallInterval;                         ///< ���м��(��)
    BOOL32						bInitmute;                              ///< ��ʼ������  1�ǣ�0��
    BOOL32                      bInitSilence;                           ///< ��ʼ������1�ǣ�0��
    EmVideoQuality_Api          emVidoQuality;                          ///<��Ƶ����,0���������ȣ�1���ٶ�����
    
    u32                         dwOneReforming;                         ///< ��һ����,0:�ر�; 1:����
    s8							achEncryptedkey[ KMTAPI_BUF_32_LEN+1 ]; ///< AES����KEY
    EmMtDualMode_Api			emDualmode;						        ///< ˫������
    BOOL32                      bVoiceActivityDetection;                ///< �Ƿ������Լ�����1�ǣ�0��
    EmRestCascadeMode_Api       emCascadeMode;                          ///< ����ģʽ,0�򵥼�����1�ϲ�����
    
    BOOL32                      bCascadeUpload;                         ///< �Ƿ����ϴ�:1�ǣ�0��
    BOOL32                      bCascadeReturn;                         ///< �Ƿ����ش�:1�ǣ�0��
    u32                         dwCascadeReturnPara;                    ///< �����ش��������
    u32                         dwMaxJoinMt;                            ///< �������ն����������ģ,0���գ�4��4����Ƶ����,8��8����Ƶ����,192��������Ƶ���飩
    u32                         dwInviteNum;                            ///< ���������

    u32                         dwMixNum;                               ///< ������Ա����
    u32                         dwVmpNum;                               ///< ����ϳɳ�Ա����
    u32                         dwVipNum;                               ///< vip����
    u32                         dwPollNum;                              ///< ��ѯ��Ա����
    TMTCreateConfMember_Api     tSpeaker;                               ///< ������

    TMTCreateConfMember_Api     tChairman;                              ///< ��ϯ
    BOOL32						bPublicConf;                            ///< �Ƿ񹫹�������  1�ǣ�0��

    u32                         dwVFormatNum;
    TMTVideoFormatList_Api      atVideoFormatList[KMTAPI_COUNT_16];     ///< ����Ƶ��ʽ�б�
    EmCallMode_Api              emCallMode;                             ///< ����ģʽ 
    EmMtFecMode_Api             emFecMode;                              ///< FEC����
    BOOL32                      bMuteFilter;                            ///<�Ƿ���ȫ���������� 0-��������1-������
    BOOL32                      bDoubleFlow;                            ///<��Ϊ�����˺������������ݹ���0-��1-�ǣ�
    BOOL32                      bEncryptedAuth;                         ///<�ն�˫����֤ 0-�رգ�1-������
public:
    tagTMTSimplePeronalTemplate_Api()
    { 
        memset( this ,0 ,sizeof(tagTMTSimplePeronalTemplate_Api) );
        emSafeConf = emMt_Open_Api;
    }
}*PTMTSimplePeronalTemplate_Api, TMTSimplePeronalTemplate_Api;

/*����ģ���б��Ա*/
typedef struct tagTMTPersonalTemplateMember_Api
{
    s8						    achTemplateID[KMTAPI_BUF_128_LEN+1];	///< ID��
    s8							achName[ KMTAPI_BUF_128_LEN+1 ];		///< ģ������
    u32							dwBitrate;						        ///< ��������
    EmClosedMeeting_Api         emCloseConf;                            ///< ��������ţ�1������0�ر�
    EmMtOpenMode_Api	        emSafeConf;					            ///< ���鰲ȫ

    EmEncryptArithmetic_Api		emEncryptedtype;                        ///< �����������
    EmMeetingSafeType_Api	    emMeetingtype;                          ///< 1 �˿ڻ���   0 ��ͳý�����
    BOOL32						bInitmute;                              ///< ��ʼ������  1�ǣ�0��
    BOOL32                      bInitSilence;                           ///< ��ʼ������1�ǣ�0��
    EmVideoQuality_Api          emVidoQuality;                          ///< ��Ƶ����,0���������ȣ�1���ٶ�����

    u32                         dwOneReforming;                         ///< ��һ����,0:�ر�; 1:����
    s8							achEncryptedkey[ KMTAPI_BUF_32_LEN+1 ]; ///< AES����KEY
    EmMtDualMode_Api			emDualmode;						        ///< ˫������
    BOOL32                      bVoiceActivityDetection;                ///< �Ƿ������Լ�����1�ǣ�0��
    BOOL32						bPublicConf;                            ///< �Ƿ񹫹�������  1�ǣ�0�� 
    EmMtResolution_Api			emResolution;					        ///< ����ֱ���
    u32                         dwMaxJoinMt;                            ///< �������ն��� �������ģ,0���գ�4��4����Ƶ����,8��8����Ƶ����,192��������Ƶ���飩
	BOOL32						bEncryptedAuth;                         ///< �Ƿ�˫����֤ 0-�ر� 1-����
public:
    tagTMTPersonalTemplateMember_Api(){memset( this, 0, sizeof(tagTMTPersonalTemplateMember_Api) ); }
}*PTMTPersonalTemplateMember_Api, TMTPersonalTemplateMember_Api;

/*����ģ���б� */
typedef struct tagTMTPersonalTemplatesList_Api
{
    u32                             dwCount;
    TMTPersonalTemplateMember_Api	atPersonalTemplateMember[KMTAPI_MG_MAX_TEMPLATE_LIST_NUM];

public:
    tagTMTPersonalTemplatesList_Api(){memset( this, 0, sizeof(tagTMTPersonalTemplatesList_Api) ); }
}*PTMTPersonalTemplatesList_Api, TMTPersonalTemplatesList_Api;

/*����ģ�� ��Ӧ�µ�ƽ̨API*/
typedef struct tagTMTCommonTemplate_Api
{
    s8                          achTemplateID[KMTAPI_BUF_128_LEN+1];    ///< ����ģ������;����ӵ�ʱ�򣬲���޸ĵ�ʱ���
    s8							achName[ KMTAPI_BUF_128_LEN+1 ];		///< ģ������
    u32							dwBitrate;						        ///< ��������
    EmClosedMeeting_Api         emCloseConf;                            ///< ��������ţ�1������0�ر�
    EmMtOpenMode_Api	        emSafeConf;					            ///< ���鰲ȫ

    s8							achPassword[ KMTAPI_BUF_128_LEN+1 ];    ///< ����  (��ѯʱ������)
    EmEncryptArithmetic_Api		emEncryptedtype;                        ///< �����������
    EmMeetingSafeType_Api	    emMeetingtype;                          ///< 1 �˿ڻ���   0 ��ͳý�����
    BOOL32						bPublicConf;                            ///< �Ƿ񹫹�������  1�ǣ�0��
    u32                         dwCallTimes;                            ///< ���д���

    u32                         dwCallInterval;                         ///< ���м��(��)
    BOOL32						bInitmute;                              ///< ��ʼ������  1�ǣ�0��
    BOOL32                      bInitSilence;                           ///< ��ʼ������1�ǣ�0��
    EmVideoQuality_Api          emVidoQuality;                          ///< ��Ƶ����,0���������ȣ�1���ٶ�����
    u32                         dwOneReforming;                         ///< ��һ����,0:�ر�; 1:����

    s8							achEncryptedkey[ KMTAPI_BUF_32_LEN+1 ]; ///< AES����KEY
    EmMtDualMode_Api			emDualmode;						        ///< ˫������
    BOOL32                      bVoiceActivityDetection;                ///< �Ƿ������Լ�����1�ǣ�0��
    u32                         dwVacinterval;                          ///< �����������ж�(s)��֧��5��15��30��60
    EmRestCascadeMode_Api       emCascadeMode;                          ///< ����ģʽ,0�򵥼�����1�ϲ�����

    BOOL32                      bCascadeUpload;                         ///< �Ƿ����ϴ�:1�ǣ�0��
    BOOL32                      bCascadeReturn;                         ///< �Ƿ����ش�:1�ǣ�0��
    u32                         dwCascadeReturnPara;                    ///< �����ش��������
    u32                         dwMaxJoinMt;                            ///< �������ն��� �������ģ,0���գ�4��4����Ƶ����,8��8����Ƶ����,192��������Ƶ���飩
    BOOL32                      bAutoEnd;                               ///< �Ƿ��Զ���᣺1�ǣ�0�� 

    BOOL32                      bPreoccpuyResouce;                      ///< Ԥռ��Դ 0-��Ԥռ 1-Ԥռ 
    u32                         dwVFormatNum;
    TMTVideoFormatList_Api      atVideoFormatList[KMTAPI_COUNT_16];     ///< ����Ƶ��ʽ�б�
	BOOL32						bEncryptedAuth;                         ///< �Ƿ�˫����֤ 0-�ر� 1-����

    TMTDCSAttribute_Api         tDCSAttr;                               ///< ����Э��
    EmMtFecMode_Api             emFecMode;                              ///< FEC����
    TMTConfVMPBrief_Api         tVMP;                                   ///< ����ϳ�����
    TMTConfMixBrief_Api         tMIX;                                   ///< ��������
    BOOL32                      bDoubleFlow;                            ///< ��Ϊ�����˺������������ݹ���
    BOOL32                      bMuteFilter;                            ///�Ƿ���ȫ���������� 0-�����κ������⣻1-�Է��Է��͹������⣻
    u32                         dwDuration;                             ///����ʱ��,0�����û���
    EmCallMode_Api              emCallMode;                             ///< ����ģʽ��
    TMTRecordAttributeBrief_Api tRecordAttr;                            ///¼������ 
public:
    tagTMTCommonTemplate_Api()
    { 
        memset( this ,0 ,sizeof(tagTMTCommonTemplate_Api) );
        emSafeConf = emMt_Open_Api;
    }
}*PTMTCommonTemplate_Api, TMTCommonTemplate_Api;

/*��ȡ����ģ���б��Ա*/
typedef struct tagTMTCommonTemplateMember_Api
{
    s8							achTemplateID[KMTAPI_BUF_128_LEN+1];    ///< ID��
    s8							achName[ KMTAPI_BUF_128_LEN+1 ];		///< ģ������
    u32							dwBitrate;						        ///< ��������
    EmClosedMeeting_Api         emCloseConf;                            ///< ��������ţ�1������0�ر�

    EmMtOpenMode_Api	        emSafeConf;					            ///< ���鰲ȫ
    EmEncryptArithmetic_Api		emEncryptedtype;                        ///< �����������
    EmMeetingSafeType_Api	    emMeetingtype;                          ///< 1 �˿ڻ���   0 ��ͳý�����
    BOOL32						bInitmute;                              ///< ��ʼ������  1�ǣ�0��
    BOOL32                      bInitSilence;                           ///< ��ʼ������1�ǣ�0��

    EmVideoQuality_Api          emVidoQuality;                          ///< ��Ƶ����,0���������ȣ�1���ٶ�����
    u32                         dwOneReforming;                         ///< ��һ����,0:�ر�; 1:����
    s8							achEncryptedkey[ KMTAPI_BUF_32_LEN+1 ]; ///< AES����KEY
    EmMtDualMode_Api			emDualmode;						        ///< ˫������
    BOOL32                      bVoiceActivityDetection;                ///< �Ƿ������Լ�����1�ǣ�0��

    BOOL32						bPublicConf;                            ///< �Ƿ񹫹�������  1�ǣ�0�� 
    EmMtResolution_Api			emResolution;					        ///< ����ֱ���
    u32                         dwMaxJoinMt;                            ///< �������ն��� �������ģ,0���գ�4��4����Ƶ����,8��8����Ƶ����,192��������Ƶ���飩
	BOOL32						bEncryptedAuth;                         ///< �Ƿ�˫����֤ 0-�ر� 1-����	
public:
    tagTMTCommonTemplateMember_Api(){memset( this, 0, sizeof(tagTMTCommonTemplateMember_Api) ); }
}*PTMTCommonTemplateMember_Api, TMTCommonTemplateMember_Api;

/*����ģ���б� */
typedef struct tagTMTCommonTemplatesList_Api
{
    u32                             dwCount;
    TMTCommonTemplateMember_Api     atCommonTemplateMember[KMTAPI_MG_MAX_TEMPLATE_LIST_NUM];

public:
    tagTMTCommonTemplatesList_Api(){memset( this, 0, sizeof(tagTMTCommonTemplatesList_Api) ); }
}*PTMTCommonTemplatesList_Api, TMTCommonTemplatesList_Api;

/*���鷢����*/
typedef struct tagTMTConfInitiator_Api
{
    s8                  achName[ KMTAPI_BUF_128_LEN+1 ];             ///< ƽ̨���� �����һ�㶼�� 164�� �� ����
    s8                  achAccount[ KMTAPI_BUF_64_LEN+1 ];           ///< ƽ̨�������һ�㶼��moid
    EmMtAddrType_Api    emAccountType;                               ///< ����
    s8                  achTelephone[KMTAPI_MT_MAX_TELEPHONE_LEN+1]; ///< ����
    s8                  achMobile[KMTAPI_MT_MAX_TELEPHONE_LEN+1];    ///< �ֻ�

public:
    tagTMTConfInitiator_Api(){memset( this, 0, sizeof(tagTMTConfInitiator_Api) ); }
}*PTMTConfInitiator_Api, TMTConfInitiator_Api;

/*�����б�Ԫ�� ��Ӧ�µ�ƽ̨API*/
typedef struct tagTMTConferenceElement_Api
{
    s8							achName[ KMTAPI_BUF_128_LEN+1 ];		///< ģ������
    s8                          achConfID[KMTAPI_BUF_64_LEN+1];         ///< �����
    EmMeetingSafeType_Api	    emConfType;                             ///< 1 �˿ڻ���   0 ��ͳý�����
    s8                          achStartTime[KMTAPI_MG_MAX_MEETING_DATETIME_LEN+1]; ///< ���鿪ʼʱ��
    s8                          achEndTime[KMTAPI_MG_MAX_MEETING_DATETIME_LEN+1]; ///< �������ʱ��
    
    u32							dwDuration;						        ///< ʱ��
    u32							dwBitrate;						        ///< ��������
    EmClosedMeeting_Api         emCloseConf;                            ///< ��������ţ�1������0�ر�
    EmMtOpenMode_Api	        emSafeConf;					            ///< ���鰲ȫ
    EmEncryptArithmetic_Api		emEncryptedtype;                        ///< �����������

    s8							achPassword[ KMTAPI_BUF_128_LEN+1 ];    ///< ����----
    BOOL32						bInitmute;                              ///< ��ʼ������  1�ǣ�0��
    BOOL32                      bInitSilence;                           ///< ��ʼ������1�ǣ�0��
    EmVideoQuality_Api          emVidoQuality;                          ///< ��Ƶ����,0���������ȣ�1���ٶ�����
    u32                         dwOneReforming;                         ///< ��һ����,0:�ر�; 1:����--
    
    s8							achEncryptedkey[ KMTAPI_BUF_32_LEN+1 ]; ///< AES����KEY
    EmMtDualMode_Api			emDualmode;						        ///< ˫������
    BOOL32                      bVoiceActivityDetection;                ///< �Ƿ������Լ�����1�ǣ�0��
    BOOL32						bPublicConf;                            ///< �Ƿ񹫹�������  1�ǣ�0��
    u32                         dwInvitedMtNum;                         ///< �����ն�����---
    
    u32                         dwMaxJoinMt;                            ///< �������ն��� �������ģ,0���գ�4��4����Ƶ����,8��8����Ƶ����,192��������Ƶ���飩
    TMTConfInitiator_Api        tConfInitiator;                         ///< ���鷢����
	BOOL32						bEncryptedAuth;                         ///< �Ƿ�˫����֤ 0-�ر� 1-����

public:
    tagTMTConferenceElement_Api()
    { 
        memset( this ,0 ,sizeof(tagTMTConferenceElement_Api) );
        emSafeConf = emMt_Open_Api;
    }
}*PTMTConferenceElement_Api, TMTConferenceElement_Api;

/*ԤԼ�����б� */
typedef struct tagTMTBookConferenceList_Api
{
    u32                     dwTotal; //ԤԼ���������
    u32                     dwCount; //atBookConference ʵ������
    TMTConferenceElement_Api   atBookConference[KMTAPI_MG_MAX_TEMPLATE_LIST_NUM];

public:
    tagTMTBookConferenceList_Api(){memset( this, 0, sizeof(tagTMTBookConferenceList_Api) ); }
}*PTMTBookConferenceList_Api, TMTBookConferenceList_Api;

/*��ʱ�����б�Ԫ�� ��Ӧ�µ�ƽ̨API*/
typedef struct tagTMTInstantConfElement_Api
{
    s8							achName[ KMTAPI_BUF_128_LEN+1 ];		 ///< ģ������
    s8                          achVirtualRoomName[ KMTAPI_BUF_128_LEN+1 ]; ///< �������������
    s8                          achConfID[KMTAPI_BUF_64_LEN+1];         ///< �����
    BOOL32                      bVoiceInspireEnable;                    ///< �Ƿ������Լ�����1�ǣ�0��
    u32                         dwVacinterval;                          ///< �����������ж�(s)��֧��5��15��30��60, ������������ʱ��Ч
    EmMeetingSafeType_Api	    emConfType;                             ///< 1 �˿ڻ���   0 ��ͳý�����
    s8                          achStartTime[KMTAPI_MG_MAX_MEETING_DATETIME_LEN+1]; ///< ���鿪ʼʱ��

    s8                          achEndTime[KMTAPI_MG_MAX_MEETING_DATETIME_LEN+1]; ///< �������ʱ��
    u32							dwDuration;						        ///< ʱ��
    u32							dwBitrate;						        ///< ��������
    EmClosedMeeting_Api         emCloseConf;                            ///< ��������ţ�1������0�ر�
    EmMtOpenMode_Api	        emSafeConf;					            ///< ���鰲ȫ

    BOOL32                      bAutoEnd;                               ///< �Զ����(���������ն�ʱ�Զ����) 0-���Զ���� 1-�Զ����
    BOOL32                      bPreoccupyResource;                     ///< Ԥռ��Դ(����ʱ��Ԥռ����Ƶ������) 0-��Ԥռ 1-Ԥռ
    EmEncryptArithmetic_Api		emEncryptedtype;                        ///< �����������
    BOOL32						bInitmute;                              ///< ��ʼ������  1�ǣ�0��
    BOOL32                      bInitSilence;                           ///< ��ʼ������1�ǣ�0��

    EmVideoQuality_Api          emVidoQuality;                          ///< ��Ƶ����,0���������ȣ�1���ٶ�����
    s8							achEncryptedkey[ KMTAPI_BUF_32_LEN+1 ]; ///< AES����KEY
    EmMtDualMode_Api			emDualmode;						        ///< ˫������
    BOOL32						bPublicConf;                            ///< �Ƿ񹫹�������  TRUE�ǣ�FALSE��
    u32                         dwMaxJoinMt;                            ///< �������ն��� �������ģ,0���գ�4��4����Ƶ����,8��8����Ƶ����,192��������Ƶ���飩

    TMTConfInitiator_Api        tConfInitiator;                         ///< ���鷢����
    u32                         dwConfLevel;                            ///���鼶��1-255, ֵԽС, ����Խ��(������������������������ն�
    BOOL32                      bNeedPassword;                          ///�Ƿ���Ҫ����
    BOOL32                      bForceBroadcast;                        ///�Ƿ�ǿ�ƹ㲥 FALSE-��ǿ�ƹ㲥��TRUE-ǿ�ƹ㲥��
	BOOL32						bEncryptedAuth;                         ///< �Ƿ�˫����֤ 0-�ر� 1-����
    EmMtFecMode_Api             emFecMode;                              ///< FEC����
    BOOL32                      bDoubleFlow;                            ///��Ϊ�����˺������������ݹ��� 0-�� 1-�ǣ��¼ӣ�
    BOOL32                      bMuteFilter;                            ///ȫ���������⣬����Ϊ1ʱ����ִ��ȫ��������������ϯ�ͷ����˲��ᱻ��������ִ�е�����������ʱ���Ա����� 0-�� 1-�ǣ��¼ӣ�

public:
    tagTMTInstantConfElement_Api()
    { 
        memset( this ,0 ,sizeof(tagTMTInstantConfElement_Api) );
        emSafeConf = emMt_Open_Api;
    }
}*PTMTInstantConfElement_Api, TMTInstantConfElement_Api;

//��ȡ��ʱ�����б�����
typedef struct tagTMTGetIntanceConfList_Api
{
    u32     dwStart;      ///< ��ȡ����Ƶ�����б����ʼ����λ��, 0��ʾ��һ������, Ĭ��Ϊ0
    u32     dwCount;      ///< ��ȡ����Ƶ����ĸ���, ������start���ڵĺ�count������, 0�����ȡ���л���, Ĭ��Ϊ10
public:
    tagTMTGetIntanceConfList_Api(){memset( this, 0, sizeof(tagTMTGetIntanceConfList_Api) ); }
}*PTMTGetIntanceConfList_Api, TMTGetIntanceConfList_Api;

/*��ʱ�����б� */
typedef struct tagTMTInstantConferenceList_Api
{
    u32                         dwTotal;  //��ʱ���������
    u32                         dwCount;  //atInstantConf ʵ�ʲ�������
    TMTInstantConfElement_Api   atInstantConf[KMTAPI_MG_MAX_TEMPLATE_LIST_NUM];

public:
    tagTMTInstantConferenceList_Api(){memset( this, 0, sizeof(tagTMTInstantConferenceList_Api) ); }
}*PTMTInstantConferenceList_Api, TMTInstantConferenceList_Api;

/** ��ȡ�����б����� */
typedef struct tagTMTConditionOfConfList_Api
{
    s8      achStartTime[KMTAPI_MG_MAX_MEETING_DATETIME_LEN+1];  ///< ���鿪ʼ���ڣ������ʾ�ӷ�������ǰʱ�俪ʼ
    s8      achEndTime[KMTAPI_MG_MAX_MEETING_DATETIME_LEN+1];    ///< ����������ڣ������ʾ�ӿ�ʼʱ���Ժ������
    u32     dwStart;                                             ///< Ĭ��Ϊ0�����ӷ��������������еĵڼ���ȡ���ݣ�0Ϊ��һ������
    u32     dwCount;                                             ///< Ĭ��Ϊ10�����ڰ���start���ڵĺ�count�����ݣ��������Ϊ0��ʾ��ȡ����
    u32     dwOrder;                                             ///< 0��������1������Ĭ��Ϊ0
public:
    tagTMTConditionOfConfList_Api(){memset( this, 0, sizeof(tagTMTConditionOfConfList_Api) ); }
}*PTMTConditionOfConfList_Api, TMTConditionOfConfList_Api;

/*ԤԼ������Ϣ ��Ӧ�µ�ƽ̨API*/
typedef struct tagTMTBookConferenceInfo_Api
{
    s8							achName[ KMTAPI_BUF_128_LEN+1 ];		///< ��������
    s8                          achConfID[KMTAPI_BUF_64_LEN+1];         ///< �����
    EmMeetingSafeType_Api	    emConfType;                             ///< 1 �˿ڻ���   0 ��ͳý�����
    s8                          achStartTime[KMTAPI_MG_MAX_MEETING_DATETIME_LEN+1]; ///< ���鿪ʼʱ��
    s8                          achEndTime[KMTAPI_MG_MAX_MEETING_DATETIME_LEN+1];   ///< �������ʱ��

    u32							dwDuration;						        ///< ʱ��
    u32							dwBitrate;						        ///< ��������
    EmClosedMeeting_Api         emCloseConf;                            ///< ��������ţ�1������0�ر�
    EmMtOpenMode_Api	        emSafeConf;					            ///< ���鰲ȫ
    s8							achPassword[ KMTAPI_BUF_128_LEN+1 ];    ///< ����

    EmEncryptArithmetic_Api		emEncryptedtype;                        ///< �����������
    s8							achEncryptedkey[ KMTAPI_BUF_32_LEN+1 ]; ///< AES����KEY
    u32                         dwCallTimes;                            ///< ���д���
    u32                         dwCallInterval;                         ///< ���м��(��)
    BOOL32						bInitmute;                              ///< ��ʼ������  1�ǣ�0��

    BOOL32                      bInitSilence;                           ///< ��ʼ������1�ǣ�0��
    EmVideoQuality_Api          emVidoQuality;                          ///< ��Ƶ����,0���������ȣ�1���ٶ�����
    EmMtDualMode_Api			emDualmode;						        ///< ˫������
    BOOL32                      bVoiceActivityDetection;                ///< �Ƿ������Լ�����1�ǣ�0��
    EmRestCascadeMode_Api       emCascadeMode;                          ///< ����ģʽ,0�򵥼�����1�ϲ�����

    BOOL32                      bCascadeUpload;                         ///< �Ƿ����ϴ�:1�ǣ�0��
    BOOL32                      bCascadeReturn;                         ///< �Ƿ����ش�:1�ǣ�0��
    u32                         dwCascadeReturnPara;                    ///< �����ش��������
    BOOL32						bPublicConf;                            ///< �Ƿ񹫹�������  1�ǣ�0��
    BOOL32                      bVmpEnable;                             ///< �Ƿ��ںϳ� 1�� 0 ��

    BOOL32                      bMixEnable;                             ///< �Ƿ��ڻ��� 1�� 0��
    BOOL32                      bPollEnable;                            ///< �Ƿ�����ѯ 1�� 0��
    u32                         dwInvitedMtNum;                         ///< �����ն�����
    u32                         dwMaxJoinMt;                            ///< �������ն��� �������ģ,0���գ�4��4����Ƶ����,8��8����Ƶ����,192��������Ƶ���飩
    TMTConfInitiator_Api        tConfInitiator;                         ///< ���鷢����

    TMTCreateConfMember_Api     tSpeaker;                               ///< ������
    TMTCreateConfMember_Api     tChairman;                              ///< ������
    u32                         dwVFormatNum;
    TMTVideoFormatList_Api      atVideoFormatList[KMTAPI_COUNT_16];     ///< ����Ƶ��ʽ�б�

    u32                         dwOneReforming;                         ///< ��һ����,0:�ر�; 1:����
    BOOL32                      bAutoEnd;                               ///< �Ƿ��Զ���᣺1�ǣ�0�� 
    BOOL32                      bPreoccpuyResouce;                      ///< Ԥռ��Դ 0-��Ԥռ 1-Ԥռ 
	BOOL32						bEncryptedAuth;                         ///< �Ƿ�˫����֤ 0-�ر� 1-����
    EmMtFecMode_Api             emFecMode;                              ///< FEC����
    BOOL32                      bDoubleFlow;                            ///��Ϊ�����˺������������ݹ���
    BOOL32                      bMuteFilter;                             ///�Ƿ���ȫ����������
public:
    tagTMTBookConferenceInfo_Api()
    { 
        memset( this ,0 ,sizeof(tagTMTBookConferenceInfo_Api) );
        emSafeConf = emMt_Open_Api;
    }
}*PTMTBookConferenceInfo_Api, TMTBookConferenceInfo_Api;

/*��ʱ���� ��Ӧ�µ�ƽ̨API*/
typedef struct tagTMTInstantConference_Api
{
    s8							achName[ KMTAPI_BUF_128_LEN+1 ];		///< ��������
    u32							dwDuration;						        ///< ʱ��
    u32							dwBitrate;						        ///< ��������
    EmClosedMeeting_Api         emCloseConf;                            ///< ��������ţ�1������0�ر�
    EmMtOpenMode_Api	        emSafeConf;					            ///< ���鰲ȫ
   
    s8							achPassword[ KMTAPI_BUF_128_LEN+1 ];    ///< ����
    EmEncryptArithmetic_Api		emEncryptedtype;                        ///< �����������
    EmMeetingSafeType_Api	    emMeetingtype;                          ///< 1 �˿ڻ���   0 ��ͳý�����
    u32                         dwCallTimes;                            ///< ���д���
    u32                         dwCallInterval;                         ///< ���м��(��)

    BOOL32						bInitmute;                              ///< ��ʼ������  1�ǣ�0��
    BOOL32                      bInitSilence;                           ///< ��ʼ������1�ǣ�0��
    EmVideoQuality_Api          emVidoQuality;                          ///< ��Ƶ����,0���������ȣ�1���ٶ�����
    s8							achEncryptedkey[ KMTAPI_BUF_32_LEN+1 ]; ///< AES����KEY
    EmMtDualMode_Api			emDualmode;						        ///< ˫������
   
    BOOL32                      bVoiceActivityDetection;                ///< �Ƿ������Լ�����1�ǣ�0��
    u32                         dwVacinterval;                          ///< �����������ж�(s)��֧��5��15��30��60
    EmRestCascadeMode_Api       emCascadeMode;                          ///< ����ģʽ,0�򵥼�����1�ϲ�����
    BOOL32                      bCascadeUpload;                         ///< �Ƿ����ϴ�:1�ǣ�0��
    BOOL32                      bCascadeReturn;                         ///< �Ƿ����ش�:1�ǣ�0��
    u32                         dwCascadeReturnPara;                    ///< �����ش��������
    
    u32                         dwMaxJoinMt;                            ///< �������ն��� �������ģ,0���գ�4��4����Ƶ����,8��8����Ƶ����,192��������Ƶ���飩
    BOOL32                      bAutoEnd;                               ///< �Ƿ��Զ���᣺1�ǣ�0��
    BOOL32                      bPreoccpuyResouce;                      ///< Ԥռ��Դ 0-��Ԥռ 1-Ԥռ
    TMTCreateConfMember_Api     tSpeaker;                               ///< ������
    TMTCreateConfMember_Api     tChairman;                              ///< ������

    BOOL32						bPublicConf;                            ///< �Ƿ񹫹�������  1�ǣ�0��
    TMTConfMixInfo_Api          tMix;                                   ///< ������Ϣ

    u32                         dwVFormatNum;
    TMTVideoFormatList_Api      atVideoFormatList[KMTAPI_COUNT_16];     ///< ����Ƶ��ʽ�б�

    u32                         dwIMemberNum;
    TMTInviteMember_Api         atInviteMembers[ KMTAPI_COUNT_192];     ///< �λ��Ա

    TMTConfVMPInfo_Api          tVmp;                                   ///< ����ϳ�����

    u32                         dwVipNum;
    TMTCreateConfMember_Api     atViplist[KMTAPI_COUNT_192];            ///< VIP�˺�

    TMTConfPollInfo_Api         tPoll;                                  ///< ��ѯ����
	BOOL32						bEncryptedAuth;                         ///< �Ƿ�˫����֤ 0-�ر� 1-����
    EmCallMode_Api              emCallMode;                             ///< ����ģʽ 
    TMTRecordAttribute_Api      tRecordAttr;                            ///< ¼������
    TMTDCSAttribute_Api         tDCSAttr;                               ///< ����Э��
	EmVConfCreateType_Api		emVConfCreateType;						///< �������ͣ������������Ĭ�ϵ�ʵʱ����
	s8							achVConfId[KMTAPI_BUF_64_LEN+1];		///< ���� ���������ID���ᣨemVConfCreateType��emCreateVirtualConf_Api�� 
                                                                        ///< ���� ģ��ID���ᣨemVConfCreateType��emCreateConfByTemplate_Api��
    EmMtFecMode_Api             emFecMode;                              ///< FEC����
    BOOL32                      bDoubleFlow;                            ///<��Ϊ�����˺������������ݹ���Ĭ��Ϊ0,0-��1-�ǣ�
    BOOL32                      bMuteFilter;                             ///<�Ƿ���ȫ���������⣬Ĭ��Ϊ0,0-��������1-������
    TMTCreateConfMember_Api     atKeepCallingMembers[KMTAPI_KEEP_CALLING_NUM];  ///< ׷����Ա���� (�ݶ�2��)
    u32                         dwKeepCallingMemberNum;                  ///< ׷����Ա����
public:
    tagTMTInstantConference_Api()
    { 
        memset( this ,0 ,sizeof(tagTMTInstantConference_Api) );
        emSafeConf = emMt_Open_Api;
    }
}*PTMTInstantConference_Api, TMTInstantConference_Api;

/*��ʱ������Ϣ ��Ӧ�µ�ƽ̨API*/
typedef struct tagTMTInstantConferenceInfo_Api
{
    s8							achName[ KMTAPI_BUF_128_LEN+1 ];		///< ��������
    s8				            achVirtualRoomName[ KMTAPI_BUF_128_LEN+1 ];        ///< �������������
    s8                          achConfID[KMTAPI_BUF_64_LEN+1];         ///< �����
    EmMeetingSafeType_Api	    emConfType;                             ///< 1 �˿ڻ���   0 ��ͳý�����
    s8                          achStartTime[KMTAPI_MG_MAX_MEETING_DATETIME_LEN+1]; ///< ���鿪ʼʱ��
    s8                          achEndTime[KMTAPI_MG_MAX_MEETING_DATETIME_LEN+1];   ///< �������ʱ��

    u32							dwDuration;						        ///< ʱ��
    u32							dwBitrate;						        ///< ��������
    EmClosedMeeting_Api         emCloseConf;                            ///< ��������ţ�1������0�ر�
    EmMtOpenMode_Api	        emSafeConf;					            ///< ���鰲ȫ
    EmEncryptArithmetic_Api		emEncryptedtype;                        ///< �����������

    u32                         dwCallTimes;                            ///< ���д���
    u32                         dwCallInterval;                         ///< ���м��(��)
    BOOL32						bInitmute;                              ///< ��ʼ������  1�ǣ�0��
    BOOL32                      bInitSilence;                           ///< ��ʼ������1�ǣ�0��

    EmVideoQuality_Api          emVidoQuality;                          ///< ��Ƶ����,0���������ȣ�1���ٶ�����
    s8							achEncryptedkey[ KMTAPI_BUF_32_LEN+1 ]; ///< AES����KEY
    EmMtDualMode_Api			emDualmode;						        ///< ˫������
    BOOL32						bPublicConf;                            ///< �Ƿ񹫹�������  1�ǣ�0��
    BOOL32                      bAutoEnd;                               ///< �Ƿ��Զ���᣺1�ǣ�0��

    BOOL32                      bPreoccpuyResouce;                      ///< Ԥռ��Դ 0-��Ԥռ 1-Ԥռ
    u32                         dwMaxJoinMt;                            ///< �������ն��� �������ģ,0���գ�4��4����Ƶ����,8��8����Ƶ����,192��������Ƶ���飩
    BOOL32                      bVoiceInspireEnable;                    ///< �Ƿ������Լ�����1�ǣ�0��
    TMTConfInitiator_Api        tConfInitiator;                         ///< ���鷢����
    u32                         dwVFormatNum;
    TMTVideoFormatList_Api      atVideoFormatList[KMTAPI_COUNT_16];     ///< ����Ƶ��ʽ�б�
   
    BOOL32                      bVmpEnable;                             ///< �Ƿ��ںϳ� 1�� 0 ��
    BOOL32                      bMixEnable;                             ///< �Ƿ��ڻ��� 1�� 0��
    BOOL32                      bPollEnable;                            ///< �Ƿ�����ѯ 1�� 0��
    BOOL32                      bNeedPassword;                          ///< �Ƿ���Ҫ���� 1��,0��
    EmRestCascadeMode_Api       emCascadeMode;                          ///< ����ģʽ,0�򵥼�����1�ϲ�����

    BOOL32                      bCascadeUpload;                         ///< �Ƿ����ϴ�:1�ǣ�0��
    BOOL32                      bCascadeReturn;                         ///< �Ƿ����ش�:1�ǣ�0��
    u32                         dwCascadeReturnPara;                    ///< �����ش��������
    u32                         dwVacinterval;                          ///< �����������ж�(s)��֧��5��15��30��60, ������������ʱ��Ч
    u32                         dwConfLevel;                            ///< ���鼶��1-255, ֵԽС, ����Խ��(������������������������ն�)
	BOOL32						bEncryptedAuth;                         ///< �Ƿ�˫����֤ 0-�ر� 1-����
    BOOL32                      bForceBroadcast;                        ///< �Ƿ�ǿ�ƹ㲥 FALSE-��ǿ�ƹ㲥��TRUE-ǿ�ƹ㲥��
    EmCallMode_Api              emCallMode;                             ///< ����ģʽ
    EmMtFecMode_Api             emFecMode;                              ///< FEC����
    BOOL32                      bDoubleFlow;                            ///��Ϊ�����˺������������ݹ��� 0-�� 1-��
    BOOL32                      bMuteFilter;                            ///ȫ���������⣬����Ϊ1ʱ����ִ��ȫ��������������ϯ�ͷ����˲��ᱻ��������ִ�е�����������ʱ���Ա�����  0-��1-�ǣ�
public:
    tagTMTInstantConferenceInfo_Api()
    { 
        memset( this ,0 ,sizeof(tagTMTInstantConferenceInfo_Api) );
        emSafeConf = emMt_Open_Api;
    }
}*PTMTInstantConferenceInfo_Api, TMTInstantConferenceInfo_Api;

/*��ȡ����ģ���Ա��Ϣ-����*/
typedef struct tagTMTGetPerTemplateInfo_Api
{
    s8  achTemplateID[KMTAPI_BUF_128_LEN+1];	///< ģ��ID
    u32 dwStart;        ///<  Ĭ��Ϊ0�����ӷ��������������еĵڼ���ȡ���ݣ�0Ϊ��һ������
    u32 dwCount;        ///<  Ĭ��Ϊ10�����ڰ���start���ڵĺ�count�����ݣ��������Ϊ0��ʾ��ȡ����
    u32 dwOrder;        ///<  ����
public:
    tagTMTGetPerTemplateInfo_Api(){memset(this, 0, sizeof(tagTMTGetPerTemplateInfo_Api));}
}*PTMTGetPerTemplateInfo_Api, TMTGetPerTemplateInfo_Api;

/*����ģ��λ���Ա�б�*/
typedef struct tagTMTPerInviteMemberList_Api
{ 
    s8                          achTemplateID[KMTAPI_BUF_128_LEN+1];	///< ģ��ID
    u32                         dwCount;                                ///<  ��Ա��
    TMTInviteMember_Api         atInviteMembers[ KMTAPI_COUNT_256];     ///< �λ��Ա

public:
    tagTMTPerInviteMemberList_Api(){memset(this, 0, sizeof(tagTMTPerInviteMemberList_Api));}
}*PTMTPerInviteMemberList_Api, TMTPerInviteMemberList_Api;

/*����ģ�������Ϣ*/
typedef struct tagTMTGetPerMixInfo_Api
{ 
    s8                  achTemplateID[KMTAPI_BUF_128_LEN+1];    ///< ģ��ID
    TMTConfMixInfo_Api  tMix;                                   ///< ������Ϣ
public:
    tagTMTGetPerMixInfo_Api(){memset(this, 0, sizeof(tagTMTGetPerMixInfo_Api));}
}*PTMTGetPerMixInfo_Api, TMTGetPerMixInfo_Api;

/*����ģ��VMP��Ϣ*/
typedef struct tagTMTGetPerVMPInfo_Api
{ 
    s8	                    achTemplateID[KMTAPI_BUF_128_LEN+1];	///< ģ��ID
    TMTConfVMPInfo_Api      tVMP;                                   ///< ����ϳ�����
public:
    tagTMTGetPerVMPInfo_Api(){memset(this, 0, sizeof(tagTMTGetPerVMPInfo_Api));}
}*PTMTGetPerVMPInfo_Api, TMTGetPerVMPInfo_Api;

/*��ȡ����ģ����ѯ��Ϣ*/
typedef struct tagTMTGetPerPollInfo_Api
{ 
    s8	                    achTemplateID[KMTAPI_BUF_128_LEN+1];	///< ģ��ID
    TMTConfPollInfo_Api     tPoll;                                  ///< ����ѯ��Ϣ
public:
    tagTMTGetPerPollInfo_Api(){memset(this, 0, sizeof(tagTMTGetPerPollInfo_Api));}
}*PTMTGetPerPollInfo_Api, TMTGetPerPollInfo_Api;

/*��ȡ����ģ��vip*/
typedef struct tagTMTGetPerVIPInfo_Api
{ 
    s8	                    achTemplateID[KMTAPI_BUF_128_LEN+1];	///< ģ��ID
    u32                     dwCount;                                ///< ��Ա��
    TMTCreateConfMember_Api atVIP[KMTAPI_COUNT_256];                ///< VIP�˺�
public:
    tagTMTGetPerVIPInfo_Api(){memset(this, 0, sizeof(tagTMTGetPerVIPInfo_Api));}
}*PTMTGetPerVIPInfo_Api, TMTGetPerVIPInfo_Api;

/** ������Ϣ */
typedef struct tagTMTCommonConfInfo_Api
{
	u32		dwId;										///<֪ͨID
	s8		achReceiverMoId[KMTAPI_GM_MAX_MOID+1];		///<������MOID
	u32     dwMessgaeType;								///<֪ͨ����
	s8		achCompanyMoId[KMTAPI_GM_MAX_MOID+1];		///<������������˾moid
	s8		achCreateTime[KMTAPI_GM_MAX_DATETIME+1];	///<֪ͨ�ڷ������˴�����ʱ��
public: 
	tagTMTCommonConfInfo_Api(){ memset( this, 0, sizeof(tagTMTCommonConfInfo_Api) ); }
}*PTMTCommonConfInfo_Api, TMTCommonConfInfo_Api;


/** ������Ϣ */
typedef struct tagTGetNotifyById_Api
{
	TRestErrorInfo_Api	  tErrInfo;
	TMTCommonConfInfo_Api tConfInfo;

public: 
	tagTGetNotifyById_Api(){ memset( this, 0, sizeof(tagTGetNotifyById_Api) ); }
}*PTGetNotifyById_Api, TGetNotifyById_Api;

/** ����Id��ȡ������ϸ��Ϣ(Ԥռ�Ļ�����) */
typedef struct tagTMTConfInfoRooms_Api
{
	u32		dwRoomCount;
	TMTRoomInfo_Api atMTRoomInfo[KMTAPI_GM_MAX_ROOM_NUM];

public:
	tagTMTConfInfoRooms_Api(){ memset( this, 0, sizeof(tagTMTConfInfoRooms_Api) ); }
}*PTMTConfInfoRooms_Api, TMTConfInfoRooms_Api;


/** ������messgaeTypeΪ102 */
typedef struct tagTMTContentCreateMeeting_Api
{
	u32		dwMeetingId; ///<����ID
	s8			achSubject[KMTAPI_GM_MAX_SUBJECT+1]; ///<����
	s8			achStartTime[KMTAPI_GM_MAX_DATETIME+1];///<��ʼʱ��
	s8			achEndTime[KMTAPI_GM_MAX_DATETIME+1];			///<����ʱ��
	BOOL32 bIsVideoMeeting; ///<�Ƿ�����Ƶ����
	s8			achPhone[KMTAPI_GM_MAX_PHONE+1];				///<�ֻ�
	s8			achMobilePhone[KMTAPI_GM_MAX_MOBILE+1];			///<�绰
	s8			achOrganizer[KMTAPI_GM_MAX_ORGANIZER+1];		///<������
	s8			achOrganigerMoid[KMTAPI_GM_MAX_MOID+1];			///<������moid
	TMTConfInfoRooms_Api tMTConfInfoRooms;			     	///<��ռ������
public:
	tagTMTContentCreateMeeting_Api() { memset(this, 0, sizeof(tagTMTContentCreateMeeting_Api)); }
}*PTMTContentCreateMeeting_Api, TMTContentCreateMeeting_Api;

/** ������messgaeTypeΪ103 */
typedef struct tagTMTContentUpdateMeeting_Api
{
	u32   dwMeetingId; ///<����ID
	s8     achSubject[KMTAPI_GM_MAX_SUBJECT+1]; ///<����
	s8     achStartTime[KMTAPI_GM_MAX_DATETIME+1];///<��ʼʱ��
	s8		achEndTime[KMTAPI_GM_MAX_DATETIME+1];			///<����ʱ��
	s8		achOrganigerMoid[KMTAPI_GM_MAX_MOID+1];			///<������moid
	s8     achBrief[KMTAPI_MG_MAX_MEETING_BRIEF_LEN+1]; ///<�����Ҫ
	s8     achBeforeSubject[KMTAPI_GM_MAX_SUBJECT+1]; ///<�޸�ǰ������
	TMTConfInfoRooms_Api tMTConfInfoRooms;			     	///<��ռ������
public:
	tagTMTContentUpdateMeeting_Api() { memset(this, 0, sizeof(tagTMTContentUpdateMeeting_Api)); }
}*PTMTContentUpdateMeeting_Api, TMTContentUpdateMeeting_Api;


/** ������messgaeTypeΪ104��108��116 */
typedef struct tagTMTContentOutMeeting_Api
{
	u32   dwMeetingId; ///<����ID
	s8     achSubject[KMTAPI_GM_MAX_SUBJECT+1]; ///<����
	s8		achOrganigerMoid[KMTAPI_GM_MAX_MOID+1];			///<������moid
public:
	tagTMTContentOutMeeting_Api() { memset(this, 0, sizeof(tagTMTContentOutMeeting_Api)); }
}*PTMTContentOutMeeting_Api, TMTContentOutMeeting_Api;

/** ������messgaeTypeΪ110 */
typedef struct tagTMTContentNotStartMeeting_Api
{
	u32   dwMeetingId; ///<����ID
	s8     achSubject[KMTAPI_GM_MAX_SUBJECT+1]; ///<����
	s8     achStartTime[KMTAPI_GM_MAX_DATETIME+1];///<��ʼʱ��
	s8		achEndTime[KMTAPI_GM_MAX_DATETIME+1];			///<����ʱ��
	s8		achOrganigerMoid[KMTAPI_GM_MAX_MOID+1];			///<������moid
	TMTConfInfoRooms_Api tMTConfInfoRooms;			     	///<��ռ������
public:
	tagTMTContentNotStartMeeting_Api() { memset(this, 0, sizeof(tagTMTContentNotStartMeeting_Api)); }
}*PTMTContentNotStartMeeting_Api, TMTContentNotStartMeeting_Api;

/** ������messgaeTypeΪ111 */
typedef struct tagTMTContentDeadlineChanged_Api
{
	s8 achDeadline[KMTAPI_GM_MAX_DATETIME+1];///<���ڵ�Ԥ������
public:
	tagTMTContentDeadlineChanged_Api() { memset(this, 0, sizeof(tagTMTContentDeadlineChanged_Api)); }
}*PTMTContentDeadlineChanged_Api, TMTContentDeadlineChanged_Api;

/** ������messgaeTypeΪ105 */
typedef struct tagTMTContentRegularMeeting_Api
{
	u32 dwRegularId;
	s8		achOrganizerMoid[KMTAPI_GM_MAX_MOID+1];			///<������moid
	s8     achSubject[KMTAPI_GM_MAX_SUBJECT+1]; ///<����
	s8		achOrganizerMail[KMTAPI_MG_ORGANIZERMAIL_LEN+1]; ///<��֯��Email
	s8			achOrganizer[KMTAPI_GM_MAX_ORGANIZER+1];		///<������
	s8			achPhone[KMTAPI_GM_MAX_PHONE+1];				///<�ֻ�
	s8     achBrief[KMTAPI_MG_MAX_MEETING_BRIEF_LEN+1]; ///<�����Ҫ
	u32 dwStatus; ///<����״̬
	s8			achMobilePhone[KMTAPI_GM_MAX_MOBILE+1];			///<�绰
	BOOL32 bIsVideoMeeting; ///<�Ƿ�����Ƶ����
	s8     achStartTime[KMTAPI_GM_MAX_DATETIME+1];///<��ʼʱ��
	s8		achEndTime[KMTAPI_GM_MAX_DATETIME+1];			///<����ʱ��
	s8     achStartDate[KMTAPI_GM_MAX_DATETIME+1];///<��ʼ����
	u32 dwRepeatType; ///<�ظ�����
	u32 dwFrequency; ///<�ظ�Ƶ��
	s8     achWeekDays[KMTAPI_GM_MAX_DATETIME+1]; ///<�����ظ�����Ҫִ�е�ʱ���
	s8		achEndDate[KMTAPI_GM_MAX_DATETIME+1];			///<��������
	u32  adwMeetingId[KMTAPI_GM_MAX_REGULAR_MEETING_COUNT]; //����ID
	u16 wMeetingCount;
public:
	tagTMTContentRegularMeeting_Api() { memset(this, 0, sizeof(tagTMTContentRegularMeeting_Api)); }
}*PTMTContentRegularMeeting_Api, TMTContentRegularMeeting_Api;

/** ������messgaeTypeΪ106��107 */
typedef struct tagTMTContentRegularId_Api
{
	u32 dwRegularId;
public:
	tagTMTContentRegularId_Api() { memset(this, 0, sizeof(tagTMTContentRegularId_Api)); }
}*PTMTContentRegularId_Api, TMTContentRegularId_Api;

/** ������messgaeTypeΪ112 */
typedef struct tagTMTContentFeedback_Api
{
	u32   dwMeetingId; ///<�����Ļ���ID
	s8		achMoid[KMTAPI_GM_MAX_MOID+1];			///<�����˵�moid
	EmParticipatResponse_Api emIsParticipated; ///<�Ƿ�μ�
	u32 dwParticipateType; ///<��᷽ʽ
	u32 dwReasonId; ///<�ܾ�ԭ��
	BOOL32 bIsVideoMeeting; ///<�Ƿ�����Ƶ����
public:
	tagTMTContentFeedback_Api() { memset(this, 0, sizeof(tagTMTContentFeedback_Api)); }
}*PTMTContentFeedback_Api, TMTContentFeedback_Api;

/** ������messgaeTypeΪ113��114 */
typedef struct tagTMTContentRoomId_Api
{
	u32 dwRoomId;
public:
	tagTMTContentRoomId_Api() { memset(this, 0, sizeof(tagTMTContentRoomId_Api)); }
}*PTMTContentRoomId_Api, TMTContentRoomId_Api;

/** ������messgaeTypeΪ109 */
typedef struct tagTMTContentMeetingId_Api
{
	u32 dwMeetingId;
public:
	tagTMTContentMeetingId_Api() { memset(this, 0, sizeof(tagTMTContentMeetingId_Api)); }
}*PTMTContentMeetingId_Api, TMTContentMeetingId_Api;


/** 115��117��118��119 */
typedef struct tagTMTContentStartMeeting_Api
{
	u32   dwMeetingId; ///<����ID
	s8     achSubject[KMTAPI_GM_MAX_SUBJECT+1]; ///<����
	s8     achStartTime[KMTAPI_GM_MAX_DATETIME+1];///<��ʼʱ��
	s8		achEndTime[KMTAPI_GM_MAX_DATETIME+1];			///<����ʱ��
	s8		achOrganizerMoid[KMTAPI_GM_MAX_MOID+1];			///<������moid
public:
	tagTMTContentStartMeeting_Api() { memset(this, 0, sizeof(tagTMTContentStartMeeting_Api)); }
}*PTMTContentStartMeeting_Api, TMTContentStartMeeting_Api;


/**����ID��ȡ������ */
typedef struct tagTMTRoomInfoById_Api
{					
	u32		dwId;											///<������ID
	s8		achName[KMTAPI_MG_MAX_MT_NAME+1];				///<����������
	u32		dwPeopleAdmit;									///<��������������
	u32		dwArea;											///<���������
	s8		achPhone[KMTAPI_MG_MAX_MT_PHONE+1];				///<�����ҵ绰
	u32		dwHasVideo;										///<�Ƿ�����Ƶ����
	s8		achE164[KMTAPI_GM_MAX_E164+1];						
	s8		achDeviceAdmin[KMTAPI_MG_MAX_MT_NAME+1];		///<�豸����Ա
	s8		achAdminPhone[KMTAPI_MG_MAX_MT_PHONE+1];		///<�豸����Ա�绰
	s8		achRemark[KMTAPI_MG_MAX_MT_REMARK+1];			///<��ע
	u32		dwDeviceMask;									///<�豸����
public:
	tagTMTRoomInfoById_Api(){ memset( this, 0, sizeof(tagTMTRoomInfoById_Api) ); }
}*PTMTRoomInfoById_Api, TMTRoomInfoById_Api;
//by-qwchan-part-mtmeetingctrl end



//by-qwchan-part-mtlocalcontact begin

/**���м�¼ */
typedef struct tagTMTCallRecord_Api
{
	u32							dwSn;					///< Ψһ��ʶ����ʱ�����ɣ�
	EmMtCallRecordType_Api		emCallRecordType;   	///< ���룬������δ��
	EmMtCallType_Api			emCallType;				///< ��Ƶ���л�����Ƶ����
	s8					        achDescribe[KMTAPI_MAX_DEV_DESC_LEN+1];			///< ��Ŀ����
	EmConfMode_Api				emConfMode;										///< �������ͣ����/�Ƕ�㣩
	s8 				            achH323Id[KMTAPI_MAX_MT_ALIAS_LEN+1];           ///< H323ID
	EmMtAddrType_Api			emAddrType;				                        ///< ��E164�����ǵ绰������IP
	s8 				            achE164[KMTAPI_MAX_MT_E164_LEN+1];       	    ///< ��д��ӦE164
	s8 				            achIp[KMTAPI_MAX_MT_IP_LEN+1];       			///< ��д��ӦIP
	s8 				            achPhoneNumber[KMTAPI_MT_MAX_TELEPHONE_LEN+1];  ///< ��д��Ӧ�绰
	s8 				            achMemoname[KMTAPI_MAX_DEV_MEMO_LEN+1];         ///< ��д��ע��
	u32							dwRate;					                        ///< ����
	u32							dwTime; 			                        	///< ����ʱ��

public:
	tagTMTCallRecord_Api(){ memset( this ,0 ,sizeof(tagTMTCallRecord_Api) );}
}*PTMTCallRecord_Api,TMTCallRecord_Api;

typedef struct tagTMTRecordSearch_Api
{
	EmMtRecordSearchType_Api	emType;
	TMTCallRecord_Api			tRecord;

public:
	tagTMTRecordSearch_Api(){ memset( this ,0 ,sizeof(tagTMTRecordSearch_Api) );}
}*PTMTRecordSearch_Api,TMTRecordSearch_Api;

typedef struct tagTAddrBookGroupInfo_Api
{
	u32				dwGroupSn;						               ///< �û������
	s8		        achGroupName[KMTAPI_CM_MAX_GROUP_NAME_LEN+1];  ///< �û�������
	u32				dwParentGroupSn;  				               ///< �������
	u32				dwGroupLevel;					               ///< ��Ĳ㼶

public:
	tagTAddrBookGroupInfo_Api(){ memset( this ,0 ,sizeof(tagTAddrBookGroupInfo_Api) );}
}*PTAddrBookGroupInfo_Api,TAddrBookGroupInfo_Api;

typedef struct tagTAddrBookRosterInfo_Api
{
	u32					dwParentGroupSn;  			            ///< �������
	u32					dwSn;						            ///< ��ǰ��Ա��SN��
	s8			        achName[KMTAPI_BUF_128_LEN+1];		    ///< ��Ŀ����
	s8			        achH323Id[KMTAPI_MAX_MT_ALIAS_LEN+1];	///< H323ID
	s8			        achE164[KMTAPI_MAX_MT_E164_LEN+1];		///< E164
	s8			        achIp[KMTAPI_MAX_MT_IP_LEN+1];			///< IP
	u32					dwRate;						            ///< ����
	s8			        achDescribe[KMTAPI_MAX_DEV_DESC_LEN+1];	///< ��Ŀ����
	s8                  achTele[KMTAPI_MAX_TELE_INFO_LEN+1];    ///< �绰

public:
	tagTAddrBookRosterInfo_Api(){ memset( this ,0 ,sizeof(tagTAddrBookRosterInfo_Api) );}
}*PTAddrBookRosterInfo_Api,TAddrBookRosterInfo_Api;

typedef struct tagTMTRecordErrInfo_Api
{
	EmMtRecordErr_Api	emError;

public:
	tagTMTRecordErrInfo_Api(){ memset( this ,0 ,sizeof(tagTMTRecordErrInfo_Api) );}
}*PTMTRecordErrInfo_Api,TMTRecordErrInfo_Api;

typedef struct tagTMTCallRecordList_Api
{
	u8          byCnt;
	TMTCallRecord_Api			atRecord[KMTAPI_CM_MAX_RECORD_NUM];
public:
	tagTMTCallRecordList_Api(){ memset( this ,0 ,sizeof(tagTMTCallRecordList_Api) );}
}*PTMTCallRecordList_Api,TMTCallRecordList_Api;

typedef struct tagTRecordSearchInfoAndList_Api
{
	TMTRecordSearch_Api			tSearchInfo;						///< ��¼������Ϣ
	TMTCallRecordList_Api		tRecordList;						///< ��¼��������б�

public:
	tagTRecordSearchInfoAndList_Api(){ memset( this ,0 ,sizeof(tagTRecordSearchInfoAndList_Api) );}
}*PTRecordSearchInfoAndList_Api,TRecordSearchInfoAndList_Api;

typedef struct tagTAddrBookRosterList_Api
{
	u8		byCnt;
	TAddrBookRosterInfo_Api		atArray[KMTAPI_CM_MAX_ROSTER_NUM];

public:
	tagTAddrBookRosterList_Api(){ memset( this ,0 ,sizeof(tagTAddrBookRosterList_Api) );}
}*PTAddrBookRosterList_Api,TAddrBookRosterList_Api;

typedef struct tagTAddrBookGroupList_Api
{
	u8    byCnt;
	TAddrBookGroupInfo_Api		atArray[KMTAPI_CM_MAX_GROUP_NUM];

public:
	tagTAddrBookGroupList_Api(){ memset( this ,0 ,sizeof(tagTAddrBookGroupList_Api) );}
}*PTAddrBookGroupList_Api,TAddrBookGroupList_Api;

typedef struct tagTGroupAndRosterList_Api
{
	TAddrBookGroupList_Api			tGroupList;			///< ��������
	TAddrBookRosterList_Api			tRosterList;		///< ��������

public:
	tagTGroupAndRosterList_Api(){ memset( this ,0 ,sizeof(tagTGroupAndRosterList_Api) );}
}*PTGroupAndRosterList_Api,TGroupAndRosterList_Api;

typedef struct tagTAppGetAllNotifysAck_Api
{
	u32 dwNotifyCnt;
	EmRestNotifyType_Api emNotifyType;
public:
	tagTAppGetAllNotifysAck_Api(){ memset( this ,0 ,sizeof(tagTAppGetAllNotifysAck_Api) );}
}*PTAppGetAllNotifysAck_Api,TAppGetAllNotifysAck_Api;

typedef struct tagTAppGetAllNotifysAckList_Api
{
	u8 byListCnt;
	TAppGetAllNotifysAck_Api tNotifyList[KMTAPI_COUNT_8];
public:
	tagTAppGetAllNotifysAckList_Api() { memset( this, 0, sizeof(tagTAppGetAllNotifysAckList_Api) );}
}*PTAppGetAllNotifysAckList_Api, TAppGetAllNotifysAckList_Api;

/** ��Ƶ������Ϣ */
typedef struct tagTMTVideoConferenceInfo_Api
{
	u32		dwShortNO;
	u32		dwState;
	u32		dwIsAutoCall;
	s8		achE164[KMTAPI_GM_MAX_E164+1];
	s8		achTemplate_id[KMTAPI_GM_MAX_TEMPLATEID+1];
	s8		achTemplate_name[KMTAPI_GM_MAX_TEMPLATENAME+1];
	s8		achPassword[KMTAPI_GM_MAX_COMMON+1];
    EmMtOpenMode_Api		        emMeetingSafe;                          ///<���鰲ȫmode
    EmEncryptArithmetic_Api			emEncryptedType;                        ///<������ܷ�ʽ
    s8								achEncryptedKey[ KMTAPI_BUF_32_LEN+1 ]; ///<������Կ
    EmMeetingSafeType_Api		    emMeetingType;                          ///<�����Ƿ��� �˿ڻ���          
    EmClosedMeeting_Api             emClosedMeeting;                        ///<��������ţ�1������0�ر�
    EmVideoQuality_Api              emVideoQuality;                         ///<��Ƶ����,0���������ȣ�1���ٶ�����
    EmMtDualMode_Api                emDualMode;                             ///<˫��Ȩ��
    BOOL32                          bInitMute;                              ///< ��ʼ��������1�ǣ�0��
    BOOL32							bPublicMeeting;                   ///< �Ƿ��ǹ���������
    u32 dwMeetingScale;                                                   ///< �����ģ,0���գ�1��4����Ƶ����,2��8����Ƶ����,3��������Ƶ����
    u32 dwOneReforming;                                                 ///< ��һ����,0:�ر�; 1:����
    u32						        dwVideoCount;
    TMTVideoFormatList_Api          atVideoFormatList[KMTAPI_COUNT_16];
    u32						        dwAudioCount;
    TMTAudioFormatList_Api          atAudioFormatList[KMTAPI_COUNT_16];
    u32                             dwDualCount;
    TMTDualFormatList_Api           atDualFormatList[KMTAPI_COUNT_8];      ///< ˫��Ƶ��ʽ�б�
    TMTGetMixInfo_Api		    tMixInfo;                             ///< ���������Ϣ
    TMTCreateConfVmp_Api    tVmp;                                  ///< ����ϳ�����

    TMTCreateConfPoll_Api   tPoll;                                 ///< ��ѯ����
    u32                     dwVipCount;
    TMTCreateConfMember_Api atVipList[KMTAPI_COUNT_256];           ///< vip��Ա�б�


    TMTCreateConfMember_Api tSpeaker;   ///< ������
    TMTCreateConfMember_Api tAdmin;     ///< ����
    u32 dwCallTimes;                    ///< ���д���
    u32 dwCallInterval;                 ///< ���м��(��)
    BOOL32 bCallChase;                  ///< �Ƿ�׷����1�ǣ�0��
    BOOL32 bVoiceInspireEnable; ///< �Ƿ������Լ�����1�ǣ�0��
    u32 dwVoiceInspireTime;         ///< ���Լ������ж�
    EmRestCascadeMode_Api emCascadeMode;///< ����ģʽ,0�򵥼�����1�ϲ�����
    BOOL32 bCascadeUpload;              ///< �Ƿ����ϴ�:1�ǣ�0��
    BOOL32 bCascadeReturn;              ///< �Ƿ����ش�:1�ǣ�0��
    u32 dwCascadeReturnPara;            ///< �����ش��������
    TMTCreateRecordRecord_Api      tRecord;                    ///< ¼������ 
    TMTCreateConfMultiCast_Api     tMultiCast;                 ///< ��������
    TMTCreateConfSatellite_Api	   tSatellite;                 ///<���ǻ�������
    u32 dwCallChaseMemberCount;
    TMTCreateConfMember_Api atCallChaseList[KMTAPI_COUNT_128]; ///< ׷��Ϊ��ʱ��׷����Ա�б�

public:
	tagTMTVideoConferenceInfo_Api(){ memset( this, 0, sizeof(tagTMTVideoConferenceInfo_Api) ); }
}*PTMTVideoConferenceInfo_Api, TMTVideoConferenceInfo_Api;


/** ����Id��ȡ������ϸ��Ϣ(������Ϣ+��������Ϣ) */
typedef struct tagTMTConfInfoById_Api
{
	u32	dwId;										    	///<����ID
	u32	dwStatus;	
	u32	dwIsVideo;

	s8	achSubject[KMTAPI_GM_MAX_SUBJECT+1];				///<��������
	s8	achStartTime[KMTAPI_GM_MAX_DATETIME+1];				///<��ʼʱ��
	s8	achEndTime[KMTAPI_GM_MAX_DATETIME+1];				///<����ʱ��
	s8	achOrganizerMoid[KMTAPI_GM_MAX_MOID+1];
	s8	achOrganizer[KMTAPI_GM_MAX_ORGANIZER+1];
	s8	achOrganizerMail[KMTAPI_GM_MAX_ORGANIZERMAIL+1];
	s8	achPhone[KMTAPI_GM_MAX_PHONE+1];
	s8	achMobile[KMTAPI_GM_MAX_MOBILE+1];
	s8	achBrief[KMTAPI_MG_MAX_MEETING_BRIEF_LEN+1];

	TMTConfInfoRooms_Api tMTConfInfoRooms;
	TMTVideoConferenceInfo_Api tMTVideoConfInfo;

public:
	tagTMTConfInfoById_Api(){ memset( this, 0, sizeof(tagTMTConfInfoById_Api) ); }
}*PTMTConfInfoById_Api, TMTConfInfoById_Api;

typedef struct tagTRegularFeedAck_Api
{
	u32    dwRegularId;
	u32    dwJoinType;
	BOOL32 bAccept;

public:
	tagTRegularFeedAck_Api()	{ memset( this, 0, sizeof(*this) ); }
}*PTRegularFeedAck_Api, TRegularFeedAck_Api;

//by-qwchan-part-mtlocalcontact end

//by-lw-part-mtsysctrl begin
/** ��ϵͳ��Ϣ */
typedef struct tagTStartUpServiceInfo_Api
{
	u32 dwMtAid;			                                                        ///< ÿ����ϵͳ�����MTAID��
	s8  achPath[KMTAPI_MAX_PATH_FILE_NAME_LEN+1];			                        ///<  ��ϵͳ�������·��
	s8 achSysalias[KMTAPI_SYS_MAX_SYSNAME_LEN+1];			                        ///<  ��ϵͳ����
	EmMtSysStartMod_Api emStartmod;    		                                        ///<  ��ϵͳ������ʽ���̼߳���/���̼��أ�
	s8 achSrtfuncname[KMTAPI_SYS_MAX_STARTFUN_NAME_LEN+1];		                    ///<  ������������
	s8 achEndfuncname[KMTAPI_SYS_MAX_STOPFUN_NAME_LEN+1];		                    ///<  ������������
public:
	tagTStartUpServiceInfo_Api()	{ memset( this, 0, sizeof(*this) ); }

}*PTStartUpServiceInfo_Api, TStartUpServiceInfo_Api;

typedef struct tagTMutiTStartUpServiceInfo_Api
{
	tagTStartUpServiceInfo_Api    atSvcInfo[KMTAPI_SYS_MAX_MTSERVICE_NUM];        ///< ��ϵͳ��Ϣ
	u16                           byCnt;                                          ///< ��ϵͳ����
public:
	tagTMutiTStartUpServiceInfo_Api()	{ memset( this, 0, sizeof(*this) ); }
}*PTMutiTStartUpServiceInfo_Api, TMutiTStartUpServiceInfo_Api;

/** ����������Ϣ */
typedef struct  tagTSrvKeepLiveInfo_Api
{
	s8 achSysalias[KMTAPI_SYS_MAX_SYSNAME_LEN+1];
	u32 dwMtAid;
	u32 dwTime;
public:
	tagTSrvKeepLiveInfo_Api()	{ memset( this, 0, sizeof(*this) ); }
}*PTSrvKeepLiveInfo_Api, TSrvKeepLiveInfo_Api;


/** ������Ĭ��ӳ����е�һ����ϵͳ���� */
typedef struct tagTServiceDefInfo_Api
{
	u32 dwIndex;			                                                        ///<  ������
	s8 achPath[KMTAPI_MAX_PATH_FILE_NAME_LEN+1];			                        ///<  ��ϵͳ�������·��
	s8 achSysalias[KMTAPI_SYS_MAX_SYSNAME_LEN+1];			                        ///<  ��ϵͳ����
	EmMtSysStartMod_Api emStartmod;		                                            ///<  ��ϵͳ������ʽ���̼߳���/���̼��أ�
	s8 achSrtfuncname[KMTAPI_SYS_MAX_STARTFUN_NAME_LEN+1];		                    ///<  ������������
	s8 achEndfuncname[KMTAPI_SYS_MAX_STOPFUN_NAME_LEN+1];		                    ///<  ������������
public:
	tagTServiceDefInfo_Api()	{ memset( this, 0, sizeof(*this) ); }
}*PTServiceDefInfo_Api, TServiceDefInfo_Api;

/** ���������Ĭ��ӳ����е���ϵͳ�б� */
typedef struct tagTMutiTServiceDefInfo_Api
{
	TServiceDefInfo_Api    atSvcDefInfo[KMTAPI_SYS_MAX_MTSERVICE_NUM];        ///< ��ϵͳ��Ϣ
	u16                    byCnt;                                             ///< ��ϵͳ����
public:
	tagTMutiTServiceDefInfo_Api()	{ memset( this, 0, sizeof(*this) ); }
}*PTMutiTServiceDefInfo_Api, TMutiTServiceDefInfo_Api;

/**  ���ڽ��洫�������� */
typedef struct tagTMTInfo_Api
{
	u32		dwpid;
	u32		dwhid;
	s8		achname[KMTAPI_BUF_64_LEN+1];   ///< �ն�����
public:
	tagTMTInfo_Api()	{ memset( this, 0, sizeof(*this) ); }
}*PTMTInfo_Api, TMTInfo_Api;

typedef struct tagTMTUsedPort_Api
{
	u32 dwPort;
	s8  achName[KMTAPI_BUF_64_LEN+1];
public:
	tagTMTUsedPort_Api() { memset( this, 0, sizeof( *this)); }
}*PTMTUsedPort_Api, TMTUsedPort_Api;

typedef struct tagTMTUsedPortList_Api
{
	EmPortType_Api emPortType;
	TMTUsedPort_Api atTMTUsedPort[KMTAPI_MAX_PORT_NUM];
	u8 byCount;
public:
	tagTMTUsedPortList_Api() { memset( this, 0, sizeof( *this)); }
}*PTMTUsedPortList_Api, TMTUsedPortList_Api;


typedef struct tagTMTTotalUsedPort_Api
{
	TMTUsedPortList_Api atMTUsedPortList[emPortTypeEnd_Api];
	u8 byCount;

public:
	tagTMTTotalUsedPort_Api() { memset( this, 0, sizeof(*this)); }
}*PTMTTotalUsedPort_Api, TMTTotalUsedPort_Api;

typedef struct tagTMTSrvInfo_Api
{
	s8                 achName[KMTAPI_BUF_32_LEN+1];
	s8                 achDomain[KMTAPI_BUF_128_LEN+1];
	EmServerType_Api   emSrvType;
	u32                dwIP;
	EmServerState_Api  emState;
	BOOL32             bUsed;
public:
	tagTMTSrvInfo_Api() { memset( this, 0, sizeof(*this)); }
}*PTMTSrvInfo_Api,TMTSrvInfo_Api;

typedef struct tagTMTSrvInfoList_Api
{
	u8    byCnt ;  ///<ʵ�ʷ���������
	TMTSrvInfo_Api atServerList[KMTAPI_MAX_SERVER_NUM];
public:
	tagTMTSrvInfoList_Api() { memset( this, 0, sizeof(*this)); }
}*PTMTSrvInfoList_Api,TMTSrvInfoList_Api;

typedef struct tagTMtSvrType_Api
{
	u32 dwSqn;                     ///<���к�
	EmServerType_Api emSrvType;    ///<����������

public:
	tagTMtSvrType_Api() { memset( this, 0, sizeof(*this)); }

}TMtSvrType_Api;

typedef struct tagTMTServiceInfo_Api
{
	u32 dwIndex;			///< ������
	u32 dwMtaid;			///< ÿ����ϵͳ�����MTAID��
	s8  achPath[KMTAPI_MAX_PATH_FILE_NAME_LEN+1];			///<  ��ϵͳ�������·��
	s8  achSysAlias[KMTAPI_BUF_32_LEN+1];			        ///<  ��ϵͳ����
	EmMtSysStartMod_Api      emStartmod;		            ///<  ��ϵͳ������ʽ����̬�����/��̬�����/���̼��أ�
	s8 achSrtFuncName[KMTAPI_BUF_32_LEN+1+1];		        ///<  ������������
	s8 achEndFuncName[KMTAPI_BUF_32_LEN+1+1];	        	///<  ������������
	EmMtSysSrvState_Api      emSrvState;		            ///<  ��ϵͳ״̬������/�Ƿ��/����/ֹͣ/�쳣��
	EmMtSysKeepLiveState_Api emSrvLiveState;	            ///<  ��ϵͳ���״̬��׼������/���/�쳣��
	u32 dwDetectTime;			          ///<  ��ϵͳ�������Ƶ��
	u32 dwTimeStamp;			          ///<  ���ڼ��������ʱ���
	u32 dwDllHandler;		              ///<  ���ض�̬�ⴴ���ľ������������
	u32 dwProcesspId;          			  ///<  ���̺�
	s8  achVersion[KMTAPI_BUF_16_LEN+1];  ///<  �汾��
public:
	tagTMTServiceInfo_Api() { memset( this, 0, sizeof(*this)); }
}*PTMTServiceInfo_Api, TMTServiceInfo_Api; 

typedef struct tagTMutiTServiceInfoRtData_Api
{
	TMTServiceInfo_Api atSrvInfo[KMTAPI_MAX_APP_NUM];
	u8 byCnt;
public:
	tagTMutiTServiceInfoRtData_Api() { memset( this, 0, sizeof(*this)); }
}*PTMutiTServiceInfoRtData_Api,TMutiTServiceInfoRtData_Api;


/** һ��ͨ������Ϣ*/
typedef struct  tagTMTOneChanDSInfo_Api
{
	EmMtChanState_Api       emState;           ///<chan״̬
	EmMtChanType_Api        emChanType;        ///<ͨ������
	EmChanIndex_Api         emIndex;
	BOOL32                  bActive;                                   ///<active���Ƿ�active,  Ĭ�Ͽƴ��Ʒ�� �յ�conneceted��Ϣ�� chanactiveΪtrue
	s8                      abyEncryKey[KMTAPI_BUF_64_LEN+1];          ///<�Ƿ���ܣ�����Ϊ0 ��ʾ������
	EmAudFormat_Api         emAudFormat;          ///<��Ƶ��ʽ
	EmAacChnlNum_Api        emAacChnlNum;         ///<aac������

	EmMtVidLabel_Api        emVidLabel;           ///<label
	EmVidFormat_Api         emVidFormat;          ///<��ʽ
	EmMtResolution_Api      emVidResolution;      ///<�ֱ���
	u32                     dwFrame;              ///<֡��
	u32                     dwH264Profile;        ///<264profileֵ
	EmEncryptArithmetic_Api emEncrypt;            ///<��������
	u16                     wChanBitrate;         ///<ͨ������
public:
	tagTMTOneChanDSInfo_Api() { memset( this, 0, sizeof( *this )); }
}*PTMTOneChanDSInfo_Api, TMTOneChanDSInfo_Api;

/** ���е�ͨ����Ϣ*/
typedef struct tagTMutiChanDsInfo_Api
{
	u8 byCnt;
	TMTOneChanDSInfo_Api  atChanInfo[KMTAPI_MAX_MULTI_CHANNEL_NUM];
public:
	tagTMutiChanDsInfo_Api() { memset( this, 0, sizeof(*this)); }
}*PTMutiChanDsInfo_Api, TMutiChanDsInfo_Api;


//by-lw-part-mtsysctrl end

//by-lw-part-Ӳ�ն� begin

/** ��Ƶ�����ʽ��ֻ��Ӳ�ն�ʹ�ã�*/
typedef struct tagTHDMTVideoOutPortMode_Api
{
	EmHDVideoOutputMode_Api emFirst_priom_video_res;         ///<��һ·����Ƶvideo����ֱ���
	EmHDVideoOutputMode_Api emFirst_priom_vga_res;           ///<��һ·����Ƶvga����ֱ���
	EmHDVideoOutputMode_Api emSecond_priom_video_res;        ///<�ڶ�·����Ƶvideo����ֱ���
	EmHDVideoOutputMode_Api emSecond_priom_vga_res;          ///<�ڶ�·����Ƶvga����ֱ���
	EmHDVideoOutputMode_Api emAss_video_res;                 ///<����Ƶ����ֱ���
public:
	tagTHDMTVideoOutPortMode_Api()	{ memset( this, 0, sizeof(*this) ); }
}*PTHDMTVideoOutPortMode_Api, THDMTVideoOutPortMode_Api;

/** ��ǰʹ�õĺ��id��*/
typedef struct tagTHDMTEnablePresetBanner_Api
{
	u32 dwBannerIndex;     ///<��ǰʹ�õĺ��id��
	BOOL32 bEnable;        ///<�Ƿ����ô�id�ĺ��
public:
	tagTHDMTEnablePresetBanner_Api()	{ memset( this, 0, sizeof(*this) ); }
}*PTHDMTEnablePresetBanner_Api, THDMTEnablePresetBanner_Api;

/** ̨��ͺ�������ּ���ʽ*/
typedef struct tagTHDMTStringAndTextFormat_Api
{
	s8  achFacenametype[KMTAPI_BUF_16_LEN+1]; ///<��������
	s8  achTextcolor[KMTAPI_BUF_16_LEN+1];    ///<������ɫ
	s8  achTextsize[KMTAPI_BUF_16_LEN+1];     ///<�����С
	BOOL32 bTextBold;       ///<����
	BOOL32 bTextItalic ;    ///<б��
	BOOL32 bTextUnderline;  ///<�»���
	s8 achTextContent[KMTAPI_BUF_1024_LEN+1];   ///<��������
    BOOL32 bIsWrap; ///< �Զ�����
public:
	tagTHDMTStringAndTextFormat_Api()	{ memset( this, 0, sizeof(*this) ); }
}*PTHDMTStringAndTextFormat, THDMTStringAndTextFormat_Api;




/** ���*/
typedef struct tagTHDMTBannerInfo_Api
{
	BOOL32 bEnable;			                        ///< ʹ��(MT_ENABLE/MT_DISABLE)
	u32 dwUseType;				                    ///<ʹ������(0:���ֺ����1:�Զ���ͼƬ���)
	s8  achBkColor[KMTAPI_BUF_32_LEN+1];			///< ����ɫ
	EmHDTextAlign_Api emTextAlign;	                ///< ���ֶ���ģʽ(TEXT_ALIGN_LEFT/TEXT_ALIGN_CENTER/TEXT_ALIGN_RIGHT)
	EmHDRollMode_Api emRollMode;		            ///< ����ģʽ(ROLL_NOT_ROLL/ROLL_RIGHT_LEFT/ROLL_DOWN_UP)
	u32 dwTransParent;                              ///< ͸����
	EmHDRollSpeed_Api emRollSpeed;		            ///< �����ٶ�(ROLL_SPEED_SLOW/ROLL_SPEED_NORMAL/ROLL_SPEED_FAST/ROLL_SPEED_FASTER)
	u32 dwRollNum;			                        ///< ��������(0:��ʾ�����ƹ���,1~255:��ʾ�û�ָ���Ĺ�������)
	u32	dwStayTime;			                        ///< ͣ��ʱ��(0:��ʾ��ͣ��,1~255:��ʾ�û�ָ����ʱ��,��λ��)
	TMTSymboPoint_Api tBannerCoordinate;            ///<���λ������λ��
	u32	dwDisplayWidth;		                        ///< ��Ļ��ʾ����Ŀ�(������Ϊ��λ)
	u32 dwDisplayHeight;	                        ///< ��Ļ��ʾ����ĸ�(ָ�и�,������Ϊ��λ)
	u32 dwTextLineSpace;			                ///<�м�࣬Ĭ�ϵ����о࣬(0:����1.0��1:����1.5,�Դ�����)
	u32 dwTextDisplayRatio;                         ///<��ʾ����(�ٷֱ�,Ĭ��100)
	THDMTStringAndTextFormat_Api  atBannerContext[KMTAPI_COUNT_64]; ///<��ź������,�Լ����ָ�ʽ,ʹ��repeated������ÿһ�����ֶ��������ò�ͬ�Ĵ�С�����ָ�ʽ
	u8 byCnt;
	s8  achPictureName[KMTAPI_BUF_256_LEN+1];	    ///<ʹ��ͼƬʱ��ͼƬ������
	s8  achPresetBannerName[KMTAPI_BUF_128_LEN+1];	///<��������
	u32 dwPresetBannerIndex;	                    ///<����(��0��ʼ)
	u32 dwTextLineNum; ///<���ֺ����ʾ���ֵ�������Ĭ��1�У�
public:
	tagTHDMTBannerInfo_Api()	{ memset( this, 0, sizeof(*this) ); }
}*PTHDMTBannerInfo_Api, THDMTBannerInfo_Api;

/** ����б�*/
typedef struct tag_THDMTBannerInfoList_Api
{
	THDMTBannerInfo_Api atMtBannerInfoList[KMTAPI_BANNER_INFO_LIST_MAX_NUM];
	u8 byCnt;
public:
	tag_THDMTBannerInfoList_Api() { memset( this, 0, sizeof(*this));}
}*PTHDMTBannerInfoList_Api, THDMTBannerInfoList_Api;


/** ̨��*/
typedef struct tagTHDMTLabelInfo_Api
{
	EmLabelType_Api       emLabelType;      ///<̨������
	TMTSymboPoint_Api  tLableCoordinate;    ///< �Զ���̨��λ��
	EmLabelPosType_Api    emLabelPosType;   ///<�ն˱���̨��λ��
	THDMTStringAndTextFormat_Api atCustomLabelContent[KMTAPI_BUF_16_LEN]; ///<�Զ���̨������
	u8 byCnt;
	s8 achPicName[KMTAPI_BUF_128_LEN + 1];          //ʹ���Զ���ͼƬʱ��ͼƬ������
	s8 achAutoTextContent[KMTAPI_BUF_128_LEN + 1];  //�ն˱���̨������
public:
	tagTHDMTLabelInfo_Api()	{ memset( this, 0, sizeof(*this) ); }
}*TTHDMTLabelInfo_Api, THDMTLabelInfo_Api;

/** �Զ�����*/
typedef struct tagTHDMTAutoSleep_Api
{
	BOOL32 bEnable;             ///<�Ƿ����Զ���������
	u32  dwTimeOut;             ///<����ǰ�ȴ�ʱ��
	BOOL32 bAllowCall;			///<����ʱ�Ƿ��������
public:
	tagTHDMTAutoSleep_Api()	{ memset( this, 0, sizeof(*this) ); }
}*PTHDMTAutoSleep_Api, THDMTAutoSleep_Api;

/** ϵͳʱ��*/
typedef struct tagTHDMTCfgSystemTime_Api
{
	BOOL32 bSyncServer;                      ///< �Ƿ�ͬ��������ʱ��	
	EmTimeZone_Api emTimeZoneType;           ///<��ǰʱ��
public:
	tagTHDMTCfgSystemTime_Api()	{ memset( this, 0, sizeof(*this) ); }
}*PTHDMTCfgSystemTime_Api, THDMTCfgSystemTime_Api;

/** ��Ƶ����˿�*/
typedef struct tagTMTHDAudInPort_Api
{
	EmHDAudPortIn_Api aemAudInPortList[KMTAPI_BUF_32_LEN];            ///<��Ƶ����ӿ�
	u8 byCnt;
public:
	tagTMTHDAudInPort_Api()	{ memset( this, 0, sizeof(*this) ); }
}*PTMTHDAudInPort_Api, TMTHDAudInPort_Api;

/** ��Ƶ����˿�*/
typedef struct tagTMTHDAudInPortList_Api
{
	TMTHDAudInPort_Api tPriMicPortList;  ///<�������Ƶ����ӿ�
	TMTHDAudInPort_Api tLineInPortList;  ///<������Ƶ����ӿ�
	BOOL32 bIsAuxMic; ///<AUX_TRS3.5�Ƿ�Ϊmic
	BOOL32 bIsLineMic; ///<LINE_RCA�Ƿ�Ϊmic
public:
	tagTMTHDAudInPortList_Api()	{ memset( this, 0, sizeof(*this) ); }
}*PTMTHDAudInPortList_Api, TMTHDAudInPortList_Api;


typedef struct tagTMTHDVidInPortCap_Api
{
	EmHDVideoType_Api emVideoType; ///<��ƵԴ����
	EmMtVideoPort_Api atVideoPort[KMTAPI_MAX_VIDEO_PORT];  ///<��Ƶ����ӿ�
	u8                    byCnt;
public:
	tagTMTHDVidInPortCap_Api()	{ memset( this, 0, sizeof(*this) ); }
}*PTMTHDVidInPortCap_Api, TMTHDVidInPortCap_Api;

/**��Ƶ�ӿ������б�*/
typedef struct tagTMTHDVidInPortCapList_Api
{
	TMTHDVidInPortCap_Api atVideoCapList[KMTAPI_MAX_VIDEO_CAP_LIST];
	u8                    byCnt;
public:
	tagTMTHDVidInPortCapList_Api()	{ memset( this, 0, sizeof(*this) ); }
}*PTMTHDVidInPortCapList_Api, TMTHDVidInPortCapList_Api;


/**��Ƶ����˿�*/
typedef struct  tagTHDMTHDAudOutPortList_Api
{
	EmHDAudPortOut_Api aemAudOutPortList[KMTAPI_BUF_32_LEN]; ///<��Ƶ����ӿ�
	u8 byCnt;
public:
	tagTHDMTHDAudOutPortList_Api()	{ memset( this, 0, sizeof(*this) ); }
}*PTHDMTHDAudOutPortList_Api, THDMTHDAudOutPortList_Api;

/** ������Ƶ����˿�*/
typedef struct tagTHDMTHDVidInPort_Api
{
	EmHDVideoType_Api emVideoType;               ///<��ƵԴ����
	EmMtVideoPort_Api emVideoInPort;             ///<��Ƶ����ӿ�
public:
	tagTHDMTHDVidInPort_Api()	{ memset( this, 0, sizeof(*this) ); }
}*PTHDMTHDVidInPort_Api, THDMTHDVidInPort_Api;

/** ���ӻ����*/
typedef struct tagTMTHDMultiVideo_Api
{
	EmHDMultiVideoSwitch_Api emMVType;                             ///<������������
	EmHDMultiViewMP_Api emVMPType;                                 ///<���ӵĻ�����
	EmMtVideoPort_Api aemVideoInPortList[KMTAPI_BUF_32_LEN];       ///<��Ƶ����ӿ�,������
	u8 byCnt;
public:
	tagTMTHDMultiVideo_Api()	{ memset( this, 0, sizeof(*this) ); }
}*PTMTHDMultiVideo_Api, TMTHDMultiVideo_Api;

/** ��Ƶ�����ʾ����*/
typedef struct tagTHDMTDisplayRatio_Api
{
	EmHDVideoType_Api emVideoType;                                     ///<��Ƶ����
	EmDisplayRatio_Api emRatio;                                        ///<��Ƶ�����ʾ����
public:
	tagTHDMTDisplayRatio_Api()	{ memset( this, 0, sizeof(*this) ); }
}*PTHDMTDisplayRatio_Api, THDMTDisplayRatio_Api;

typedef struct tagTMTVidInPortMode_Api
{
	EmMtVideoPort_Api emVideoInPort;   ///<��Ƶ�����
	EmHDVideoPortMode_Api emInPortMode;	///<���������
public:
	tagTMTVidInPortMode_Api() { memset( this, 0, sizeof(*this)); }
}*PTMTVidInPortMode_Api, TMTVidInPortMode_Api;

typedef struct tagTMTVidOutPortMode_Api
{
	EmHDVideoOutPortType_Api emVideoOutPort; ///<��Ƶ�����
	EmHDVideoPortMode_Api emOutPortMode;	 ///<���������
public:
	tagTMTVidOutPortMode_Api() { memset(this, 0, sizeof(*this)); }
}*PTMTVidOutPortMode_Api, TMTVidOutPortMode_Api;

typedef struct tagTMTVideoOutPort2InPort_Api
{
	EmHDVideoOutPortType_Api emVideoOutPort; ///<��Ƶ�����
	EmHDVideoSourceType_Api emVideoOutType;	 ///<����ڶ�Ӧ�����������
public:
	tagTMTVideoOutPort2InPort_Api() { memset(this, 0, sizeof(*this));}
}*PTMTVideoOutPort2InPort_Api, TMTVideoOutPort2InPort_Api;

typedef struct tagTMTVideoMatrixScheme_Api
{
	u32 dwSchemeID;                         ///<����id
	s8	achSchemeName[KMTAPI_BUF_64_LEN+1]; ///<��������
	u8 byInPortCnt; 
	TMTVidInPortMode_Api atInPortMode[KMTAPI_BUF_32_LEN];           ///<��Ƶ�����ģʽ
	u8 byOutPortCnt; 
	TMTVidOutPortMode_Api atOutPortMode[KMTAPI_BUF_32_LEN];         ///<��Ƶ�����ģʽ
	u8 byOutPort2InPortCnt;
	TMTVideoOutPort2InPort_Api atOutPort2InPort[KMTAPI_BUF_32_LEN]; ///<����ӿڶ�Ӧ������ͼ��
public:
	tagTMTVideoMatrixScheme_Api() { memset( this, 0, sizeof(*this)); }
}*PTMTVideoMatrixScheme_Api, TMTVideoMatrixScheme_Api;

/** ������Ƶ����ģ��*/
typedef struct tagTHDMTAllVideoMatrixScheme_Api
{
	u32 dwSchemeID;                                                            ///<��ǰ���õľ���ģ��id
	TMTVideoMatrixScheme_Api atMatrixScheme[KMTAPI_BUF_256_LEN];               ///<���Ծ���ģ��
	u8 byCnt;                                                                  ///<ģ������
public:
	tagTHDMTAllVideoMatrixScheme_Api()	{ memset( this, 0, sizeof(*this) ); }
}*PTHDMTAllVideoMatrixScheme_Api, THDMTAllVideoMatrixScheme_Api;

/** ��ͼ����ʾ����*/
typedef struct tagTHDMTLastDisplay_Api
{
	EmHDLastDisplay_Api emLastDisplayType;                   ///<��ʾģʽ
	u32 dwWaitTimer;                                         ///<��ͼ����Եȴ�ʱ�䣨�룩
public:
	tagTHDMTLastDisplay_Api()	{ memset( this, 0, sizeof(*this) ); }
}*PTHDMTLastDisplay_Api, THDMTLastDisplay_Api;

/** ͼ����ȼ�*/
typedef struct tagTHDMTImageNoise_Api
{
	EmHDImageNoise_Api emNoiseLevel;                             ///<����ȼ�
public:
	tagTHDMTImageNoise_Api()	{ memset( this, 0, sizeof(*this) ); }
}*PTHDMTImageNoise_Api, THDMTImageNoise_Api;

/** ��Ƶ��������*/
typedef struct tagTMTHDImageDeformationTensile_Api
{
	EmCodecComponent_Api emCodecType;                                ///<��Ƶ����
	EmCodecComponentIndex_Api emCodecIndex; ///<��������
	u32 dwHoriNum; ///<ˮƽ���죬ȡ��16Ϊ��ֵ��������ֵ���ʾ�Ŵ�С�ڱ�ʾ��С
	u32 dwVertiNum; ///<��ֱ���죬ȡ��16Ϊ��ֵ��������ֵ���ʾ�Ŵ�С�ڱ�ʾ��С
public:
	tagTMTHDImageDeformationTensile_Api() { memset( this, 0, sizeof(*this)); }
}*PTMTHDImageDeformationTensile_Api, TMTHDImageDeformationTensile_Api;

/** ��Ƶ�ȱ�����*/
typedef struct tagTMTHDImageGeometricScaling_Api
{
	EmCodecComponent_Api emCodecType;                                ///<��Ƶ����
	EmCodecComponentIndex_Api emCodecIndex; ///<��������
	u32 dwNumber;                                                 ///<ȡһ����Ϊ��ֵ��������ֵ���ʾ�Ŵ�С�ڱ�ʾ��С
public:
	tagTMTHDImageGeometricScaling_Api() { memset( this, 0, sizeof(*this)); }
}*PTMTHDImageGeometricScaling_Api, TMTHDImageGeometricScaling_Api;

/** ���������*/
typedef struct tagTMTHDCameraCfg_Api
{
	EmMtVideoPort_Api emVideoPortIndex;
	s8 achCameraTypeName[KMTAPI_BUF_256_LEN+1];                   ///<���������(�����������ҵ�������ϱ��������ļ�Ĭ��Ϊͨ��)
	u32 dwAddress;                                                ///<�ջ���λ��
	u32 dwSpeed;                                                  ///<�ٶȣ��졢�С�����
	EmHDSerialType_Api emSerialType;                              ///<��������
	u32 dwIp;													  ///<���������IP
	u32 dwPort;													  ///<����������˿�
public:
	tagTMTHDCameraCfg_Api() { memset( this, 0, sizeof(*this)); }
}*PTMTHDCameraCfg_Api, TMTHDCameraCfg_Api;

/** ����������б�*/
typedef struct tagTMTHDCameraList_Api
{
	TMTHDCameraCfg_Api atCameralist[KMTAPI_BUF_32_LEN];            ///<���������
	u8 byCnt;
public:
	tagTMTHDCameraList_Api() { memset( this, 0, sizeof(*this)); }
}*PTMTHDCameraList_Api, TMTHDCameraList_Api;

/** ��������*/
typedef struct tagTMTHDSerialCtrl
{
	EmHDSerialType_Api emSerialType;                                ///<�������� 
	u32 dwBandRate;                                                 ///<������
	u32 dwByteSize;                                                 ///<����λ
	EmHDStopBits_Api emStopBits;                                    ///<ֹͣλ
	EmHDParityCheck_Api emParityCheck;                              ///<У���㷨
public:
	tagTMTHDSerialCtrl() { memset( this, 0, sizeof(*this)); }
}*PTMTHDSerialCtrl_Api, TMTHDSerialCtrl_Api;

typedef struct tagTMTHDSerialList_Api
{
	TMTHDSerialCtrl_Api atSeriallist[KMTAPI_BUF_32_LEN];            ///<����
	u8 byCnt;
public:
	tagTMTHDSerialList_Api() { memset( this, 0, sizeof(*this)); }
}*PTMTHDSerialList_Api, TMTHDSerialList_Api;



//by-lw-part-Ӳ�ն� end

typedef struct tagTMTBandWidthTest_Api
{
	BOOL32 bEnable;
	u32    dwUpWidth;
	u32    dwDownWidth;
public:
	tagTMTBandWidthTest_Api() { memset( this, 0, sizeof(*this)); }
}*PTMTBandWidthTest_Api, TMTBandWidthTest_Api;

typedef struct tagTMTCallBitRate_Api
{
	u32 dwRateCount;
	u32 adwRate[KMTAPI_BUF_16_LEN];
public:
	tagTMTCallBitRate_Api() { memset( this, 0, sizeof(*this)); }
}*PTMTCallBitRate_Api, TMTCallBitRate_Api;

/** ��¼����*/
typedef struct tagTMTLoginTactic_Api
{
	EmServerType_Api emSvrType;                             ///<����������
	EmServerType_Api aemPreSvrList[KMTAPI_MAX_DECODE_NUM];  ///<ǰ�÷������б�
	u8               byCnt;                                 ///<ǰ�÷������б���
	BOOL32           bUsed;
public:
	tagTMTLoginTactic_Api() { memset( this , 0, sizeof(*this)); }
}*PTMTLoginTactic_Api, TMTLoginTactic_Api;

typedef struct tagTMtLoginTacticsTable_Api
{
	u32					dwCount;
	TMTLoginTactic_Api atLoginTactic[emServerTypeEnd_Api];
public:
	tagTMtLoginTacticsTable_Api() { memset( this, 0, sizeof(*this)); }
}*PTMtLoginTacticsTable_Api, TMtLoginTacticsTable_Api;


typedef struct tagTMTAllVideoDecoderParamCfg_Api
{
	u32 dwDecodeNum;
	TMTVideoDecoderParamCfg_Api atDecodeParam[KMTAPI_MAX_DECODE_NUM];
public:
	tagTMTAllVideoDecoderParamCfg_Api() { memset( this, 0, sizeof(*this)); }
}*PTMTAllVideoDecoderParamCfg, TMTAllVideoDecoderParamCfg_Api;


typedef struct tagTMTSatelliteFlag_Api
{
	BOOL32  bSatelliteMt;       ///<�Ƿ��������ն�
	BOOL32  bP2PEnable;         ///<�����ն��Ƿ��е�Ե����Ȩ��
public:
	tagTMTSatelliteFlag_Api() { memset( this, 0, sizeof(*this)); }
}*PTMTSatelliteFlag_Api, TMTSatelliteFlag_Api;

typedef struct tagTMTAudioPower_Api
{
	EmCodecComponent_Api emStreamType;
	EmCodecComponentIndex_Api emStreamIdx;
	u32 dwPower;
public:
	tagTMTAudioPower_Api() { memset( this, 0, sizeof(*this)); }
}*PTMTAudioPower_Api, TMTAudioPower_Api;


/** ��½��ƽ̨����*/
typedef struct tagTMtLoginPlatformPwdCfg_Api
{
	BOOL32 bIsModifyEnable;                           ///<�Ƿ������޸�����
	s8 achPassword[KMTAPI_MAX_USERPWD_LEN+1];         ///<����
public:
	tagTMtLoginPlatformPwdCfg_Api() { memset( this, 0, sizeof(*this)); }
}*PTMtLoginPlatformPwdCfg_Api, TMtLoginPlatformPwdCfg_Api;

typedef struct tagTMtAudEncStatistic_Api
{
	EmCodecComponentIndex_Api emAudEncId; ///<��Ƶ������id
	u32                       dwEncRate;  ///<��������
	EmAudFormat_Api emAudEncType;         ///<��ƵЭ��
	BOOL32			bAudioEncStart;      ///<�Ƿ�ʼ��Ƶ����
	EmAacChnlNum_Api  emChnl_num;           ///< �����lc,ld��������


public:
	tagTMtAudEncStatistic_Api() { memset( this, 0, sizeof(*this)); }
}*PTMtAudEncStatistic_Api, TMtAudEncStatistic_Api;

typedef struct tagTMtAudDecStatistic_Api
{
	EmCodecComponentIndex_Api emAudDecId;  ///<��Ƶ������id
	u32                dwDecRate;          ///<��������
	u32                dwRecFrames;        ///<�յ���֡��
	u32                dwLostPackRatio;    ///<������, ָ���������ش������Ķ�����
	u32                dwPhysicalLostPackRatio; ///<�������ʣ�ָδ���������ش�����Ķ�����
	u32                dwLostPacks;        ///<��������
	EmAudFormat_Api emAudDecType;          ///<��ƵЭ��
	BOOL32			bAudioDecStart;		   ///<�Ƿ�ʼ��Ƶ����
	EmAacChnlNum_Api      emChnl_num;           ///< �����lc,ld��������
	EmAudFormat_Api emAudChanDecType;         ///<ͨ����ƵЭ��
public:
	tagTMtAudDecStatistic_Api() { memset( this, 0, sizeof(*this)); }
}*PTMtAudDecStatistic_Api, TMtAudDecStatistic_Api;

typedef struct tagTMtVidEncStatistic_Api
{
	EmCodecComponentIndex_Api emVidEncId;  ///<��Ƶ������id
	u32                dwEncBitrate;       ///<��������
	u32                dwFrameRate;        ///<����֡��
	u32                dwVidWidth;         ///<�������(�ֱ���)
	u32                dwVidHeight;        ///<�����߶�(�ֱ���)
	EmVidFormat_Api    emVidEncType;          ///<��ƵЭ��
	BOOL32			   bVideoEncStart;     ///<�Ƿ�ʼ��Ƶ����
	EmH264Profile_Api	emVideoProfile;			///<264profileֵ

public:
	tagTMtVidEncStatistic_Api() { memset( this, 0, sizeof(*this)); }
}*PTMtVidEncStatistic_Api, TMtVidEncStatistic_Api;


typedef struct tagTMtVidDecStatistic_Api
{
	EmCodecComponentIndex_Api emVidDecId;  ///<��Ƶ������id
	u32                dwDecBitrate;       ///<��������
	u32                dwRcvFrames;        ///<�յ���֡��	
	u32                dwLostPackRatio;    ///<������, ָ���������ش������Ķ�����
	u32                dwPhysicalLostPackRatio; ///<�������ʣ�ָδ���������ش�����Ķ�����
	u32                dwLostPacks;   ///<��������
	u32                dwFrameRate;   ///<����֡��
	u32                dwVidWidth;    ///<�������(�ֱ���)
	u32                dwVidHeight;   ///<�����߶�(�ֱ���)
	EmVidFormat_Api	emVidDecType;     ///<��ƵЭ��
	BOOL32			bVideoDecStart;	  ///<�Ƿ�ʼ��Ƶ����
	EmH264Profile_Api	emVideoProfile;			///<264profileֵ
public:
	tagTMtVidDecStatistic_Api() { memset( this, 0, sizeof(*this)); }
}*PTMtVidDecStatistic_Api, TMtVidDecStatistic_Api;

typedef struct tagTMtAudMixStatistic_Api
{
	EmCodecComponentIndex_Api emAudMixId;
public:
	tagTMtAudMixStatistic_Api() { memset( this, 0, sizeof(*this)); }
}*PTMtAudMixStatistic_Api, TMtAudMixStatistic_Api;

typedef struct tagTMtVidMixStatistic_Api
{
	EmCodecComponentIndex_Api emVidMixId;
public:
	tagTMtVidMixStatistic_Api() { memset( this, 0, sizeof(*this)); }
}*PTMtVidMixStatistic_Api, TMtVidMixStatistic_Api;

typedef struct tagTMtCodecStatistic_Api
{
	TMtAudEncStatistic_Api atMainAudEncStatic[KMTAPI_MAX_ENCODE_NUM];
	u8 byMainAudEncCount;
	TMtAudEncStatistic_Api atAssAudEncStatic[KMTAPI_MAX_ENCODE_NUM];
	u8 byAssAudEncCount;
	TMtAudDecStatistic_Api atMainAudDecStatic[KMTAPI_MAX_DECODE_NUM];
	u8 byMainAudDecCount;
	TMtAudDecStatistic_Api atAssAudDecStatic[KMTAPI_MAX_DECODE_NUM];
	u8 byAssAudDecCount;
	TMtVidEncStatistic_Api atMainVidEncStatic[KMTAPI_MAX_ENCODE_NUM];
	u8 byMainVidEncCount;
	TMtVidEncStatistic_Api atAssVidEncStatic[KMTAPI_MAX_ENCODE_NUM];
	u8 byAssVidEncCount;
	TMtVidDecStatistic_Api atMainVidDecStatic[KMTAPI_MAX_DECODE_NUM];
	u8 byMainVidDecCount;
	TMtVidDecStatistic_Api atAssVidDecStatic[KMTAPI_MAX_DECODE_NUM];
	u8 byAssVidDecCount;
	TMtAudMixStatistic_Api atMainAudMixStatic[KMTAPI_MAX_ENCODE_NUM];
	u8 byMainAudMixCount;
	TMtAudMixStatistic_Api atAssAudMixStatic[KMTAPI_MAX_ENCODE_NUM];
	u8 byAssAudMixCount;
	TMtVidMixStatistic_Api atMainVidMixStatic[KMTAPI_MAX_DECODE_NUM];
	u8 byMainVidMixCount;
	TMtVidMixStatistic_Api atAssVidMixStatic[KMTAPI_MAX_DECODE_NUM];
	u8 byAssVidMixCount;

public:
	tagTMtCodecStatistic_Api() { memset( this, 0, sizeof(*this)); }
}*PTMtCodecStatistic_Api, TMtCodecStatistic_Api;

/** DCS ��������ַ */
typedef struct tagTMtDCSSvrAddr_Api
{
	s8 achDomain[KMTAPI_MAX_DOMAIN_NAME_LEN+1];       ///<����
	u32 dwIp;                                         ///<ip
	BOOL32 bUseDefAddr;                               ///<�Ƿ�ʹ��Ĭ�ϵ�ַ
	s8 achCustomDomain[KMTAPI_MAX_DOMAIN_NAME_LEN+1]; ///<�û��Զ�������
	u32 dwCustomIp;                                   ///<�û��Զ���ip
	u32 dwPort;
public:
	tagTMtDCSSvrAddr_Api() { memset( this, 0, sizeof(*this)); }
}*PTMtDCSSvrAddr_Api, TMtDCSSvrAddr_Api;

/** ������Ƶ���������� */
typedef struct tagTMTAllVideoEncoderParamCfg_Api
{
	TMTVideoEncoderParamCfg_Api atParamArray[KMTAPI_MAX_MULTI_CHANNEL_NUM];           ///<����������
	u8 byCnt;                                                                         ///<����������
public:
	tagTMTAllVideoEncoderParamCfg_Api() { memset( this, 0, sizeof(*this)); }
}*PTMTAllVideoEncoderParamCfg_Api, TMTAllVideoEncoderParamCfg_Api;



typedef struct tagTMTCodecVidSrcInfo_Api
{
	EmCodecComponentIndex_Api emCodecCpIndex; ///<����������
	EmVidPort_Api emVidPort;                  ///<�˿�
public:
	tagTMTCodecVidSrcInfo_Api() { memset( this, 0, sizeof(*this)); }
}*PTMTCodecVidSrcInfo_Api, TMTCodecVidSrcInfo_Api;


/** ����mc������Ϣ */
typedef struct tagTInnerMCRunInfo_Api
{
	BOOL32 bMcIsExist;		       ///<�Ƿ��������mc����
	BOOL32 bMcIsActive;		       ///<����mc�Ƿ񼤻�
	BOOL32 bMcIsInconf;            ///<����mc�Ƿ����ڿ���
	u32 dwMcMemMaxNum;             ///<����mc֧�������Ŀ
public:
	tagTInnerMCRunInfo_Api() { memset( this, 0, sizeof(*this)); }
}*PTInnerMCRunInfo_Api, TInnerMCRunInfo_Api;


/** ����mc�������� */
typedef struct tagTMTInnerMcAssVidCfg_Api
{
	EmVidFormat_Api emAssVideoFormat;              ///<������ʽ
	EmMtResolution_Api emAssVideoRes;              ///<�����ֱ���
	u32 dwAssVideoFramerate;                       ///<����֡��
public:
	tagTMTInnerMcAssVidCfg_Api() { memset( this, 0, sizeof(*this)); }
}*PTMTInnerMcAssVidCfg_Api, TMTInnerMcAssVidCfg_Api;

/** VGAͼ����� */
typedef struct tagTMTVgaImageAdjustCfg_Api
{
	BOOL32 bVga1FilterState;                   ///<VGA1�˲�״̬
	u32 dwVga1PhaseClock; 	                   ///<VGA1��λʱ��
	s32 nVga1ImageOffset; 	                   ///<VGA1ͼ��ƫ��

	BOOL32 bVga2FilterState;                   ///<VGA1�˲�״̬
	u32 dwVga2PhaseClock; 	                   ///<VGA1��λʱ��
	s32 nVga2ImageOffset; 	                   ///<VGA1ͼ��ƫ��
public:
	tagTMTVgaImageAdjustCfg_Api() { memset( this, 0, sizeof(*this)); }
}*PTMTVgaImageAdjustCfg_Api, TMTVgaImageAdjustCfg_Api;

/** ��ƵԴ��ǩ */
typedef struct tagTMTVideoSrcTag_Api
{
	EmMtVideoPort_Api emVideoPortId;
	s8 achVideoPortTag[KMTAPI_BUF_128_LEN+1];
public:
	tagTMTVideoSrcTag_Api() { memset( this, 0, sizeof(*this)); }
}*PTMTVideoSrcTag_Api, TMTVideoSrcTag_Api;

typedef struct tagTMTVideoSrcTagList_Api
{
	u8 byCnt;
	TMTVideoSrcTag_Api atVidSrcTag[KMTAPI_MAX_VIDEO_SRC_NUM];
public:
	tagTMTVideoSrcTagList_Api() { memset( this, 0, sizeof(*this)); }
}*PTMTVideoSrcTagList_Api, TMTVideoSrcTagList_Api;
/** Ftp������Ϣ */
typedef struct tagTMTSnapShotFtpCfg_Api
{
	BOOL32 bIsEnable;                                    ///<�Ƿ����ÿ���FTP����
	u32 dwIpAddr;                                        ///<��ַ
	u32 dwPort;                                          ///<�˿�
	s8 achUploadPath[KMTAPI_MAX_PATH_FILE_NAME_LEN+1];   ///<�ϴ�·��
	s8 achUserName[KMTAPI_MAX_FULL_USERNAME_LEN+1];      ///<�û���
	s8 achPassWord[KMTAPI_MAXLEN_PASSWORD+1];            ///<����
public:
	tagTMTSnapShotFtpCfg_Api() { memset( this, 0, sizeof(*this)); }
}*PTMTSnapShotFtpCfg_Api, TMTSnapShotFtpCfg_Api;

/** �ָ�����Ĭ��ֵ��Ϣ */
typedef struct tagTMTRestoreDefaultCfgInfo_Api
{
	s8 aachKeyList[KMTAPI_COUNT_256][KMTAPI_BUF_64_LEN + 1];  ///<�ָ�Ĭ��ֵ��key�б�
	u32 dwCnt;
public:
	tagTMTRestoreDefaultCfgInfo_Api() { memset( this, 0, sizeof(*this)); }
}*PTMTRestoreDefaultCfgInfo_Api, TMTRestoreDefaultCfgInfo_Api;

/** ������ѯ*/
typedef struct tagTMTConditionQuery_Api
{
	s8  achEmail[KMTAPI_MAX_EMAIL_LEN+1];		        ///< �û��˺�emai
	s8  achE164[KMTAPI_MAX_MT_E164_LEN+1];			    ///< �û��˺�e164
	s8  achName[KMTAPI_MAX_MT_ALIAS_LEN+1];			    ///< �û���
	s8  achAccount[KMTAPI_MAX_MT_ALIAS_LEN+1];			///< �Զ����˺�
	s8  achMobilePhone[KMTAPI_MT_MAX_TELEPHONE_LEN+1];  ///< �û��ֻ�(��ҵ�ⲻ��Ҫ)
	u32 dwInEnt;			                            ///< ��ѯ��ҵ��Χ��0��ʾ��ҵ�⣬1��ʾ��ҵ��
	u32 dwStartRow;		                                ///< ��ʼ�����磺0����ʾ�ӵ�1����ʼ����10����ʾ�ӵ�11����ʼ������������
	u32 dwPageSize;		                                ///< �������������磺10
public:
	tagTMTConditionQuery_Api() { memset( this, 0, sizeof(*this)); }
}*PTMTConditionQuery_Api, TMTConditionQuery_Api;


typedef struct tagTMTQueryUser_Api
{
	u32 dwUserNum ;
	s8  aachUserNo[KMTAPI_MAX_USER_NUM][KMTAPI_MAX_MT_ALIAS_LEN+1];
public:
	tagTMTQueryUser_Api( ) { memset( this, 0, sizeof(*this)); }
}*PTMTQueryUser_Api, TMTQueryUser_Api;

/** �����û�ͷ��*/
typedef struct tagTMTQueryPortrait_Api
{
	EmMtPortrait_Api	emPortrait;
	s8    achPortraitStr[KMTAPI_BUF_128_LEN+1];
	s8	  achFileName[KMTAPI_BUF_64_LEN+1];
	u64	  dwRequestPointer;
public:
	tagTMTQueryPortrait_Api( ) { memset( this, 0, sizeof( *this )); }
}*PTMTQueryPortrait_Api, TMTQueryPortrait_Api;

/** �޸��û�ͷ��*/
typedef struct tagTMTModifyPortrait_Api
{
	u32   dwX1;
	u32   dwY1;
	u32   dwWidth;
	u32   dwHeith;
	u32   dwLen;
	s8    achPath[KMTAPI_BUF_256_LEN+1];
public:
	tagTMTModifyPortrait_Api( ) { memset( this, 0, sizeof( *this)); }
}*PTMTModifyPortrait_Api, TMTModifyPortrait_Api;

/** ���˽���*/
typedef struct tagTMTModifyBrief_Api
{
	s8 achUserName[KMTAPI_MAX_MT_ALIAS_LEN+1];
	s8 achBrief[KMTAPI_BUF_64_LEN+1];
public:
	tagTMTModifyBrief_Api() { memset( this, 0, sizeof( *this)); }
}*PTMTModifyBrief_Api, TMTModifyBrief_Api;

/** ����ģ�����ұ���ҵ��ϵ��*/
typedef struct tagTMTUserListByStr_Api 
{
	s8	achUserName[KMTAPI_MAX_MT_ALIAS_LEN+1];    ///< ��ѯ���˺ţ�������E164���������
	s8	achStr[KMTAPI_BUF_32_LEN+1];               ///< ģ��ƥ����ַ��������磺���
	u32 dwStartRow;                                ///< ��ʼ�У����磺0
	u32 dwPageSize;                                ///< �������������磺10
public:
	tagTMTUserListByStr_Api() { memset( this, 0, sizeof( *this )); }
}*PTMTUserListByStr_Api, TMTUserListByStr_Api;

/** ��ϵ����֤ģʽ*/
typedef struct tagTMTSetAuthMode_Api
{
	s8  achJid[KMTAPI_BUF_64_LEN+1];					///< �˺Ŷ�Ӧ��jid
	u32 dwAuthMode;					                    ///< �����ϵ����֤ģʽ��(0:������֤��1:����֤��2:�ܾ�����)
public:
	tagTMTSetAuthMode_Api() { memset( this, 0, sizeof( *this )); }
}*PTMTSetAuthMode_Api, TMTSetAuthMode_Api;

/** �������б�*/
typedef struct tagTMtSvrList_Api
{
	EmServerType_Api aemServerList[emServerTypeEnd_Api]; ///< �������б�
	u8				 byCnt;                              ///< �б��е�ʵ�ʸ���

	tagTMtSvrList_Api() { memset(this, 0, sizeof(tagTMtSvrList_Api)); }

}*PTMtSvrList_Api, TMtSvrList_Api;

/** APS��½����*/
typedef struct tagTMTApsLoginParam_Api
{
	s8 achUsername[KMTAPI_BUF_128_LEN+1]; ///< �û���
	s8 achPassword[KMTAPI_BUF_64_LEN+1]; ///< ��������
	s8 achSoftwareVer[KMTAPI_MAX_DEV_SOFT_VER_LEN+1];
	s8 achModelName[KMTAPI_MAX_MT_TYPE_NAME_LEN+1];
	s8 achOemInfo[KMTAPI_MAX_MT_OEM_NAME_LEN+1];
	s8 achMd5Password[KMTAPI_BUF_32_LEN+1];///< MD5��������,�������ü�������,�����������MD5����

	tagTMTApsLoginParam_Api() { memset(this, 0, sizeof(tagTMTApsLoginParam_Api)); }

}*PTMTApsLoginParam_Api, TMTApsLoginParam_Api;

typedef struct tagTMtApsLoginErrcode_Api
{
	BOOL32  bSucess;       ///<�Ƿ�ɹ� ��ʧ�� ͨ������Ĵ������ȡ������Ϣ
	u32		dwHttpErrcode; ///<http������ 200��ʾ���ӷ������ɹ� �����������ӷ�����ʧ��
	u32		dwApsErroce;   ///<bSucessΪFALSE http������Ϊ200������� ���������صĴ�����,�ο�EmLoginAPSErrorId_Api

	tagTMtApsLoginErrcode_Api() { memset(this, 0, sizeof(tagTMtApsLoginErrcode_Api)); }

}*PTMtApsLoginErrcode_Api, TMtApsLoginErrcode_Api;

/** �޸��˺�����*/
typedef struct tagTMTModifyPwd_Api
{
	s8 achUserName[KMTAPI_MAX_MT_ALIAS_LEN+1];    ///< �û��ʺţ�������E164�Ż�������
	s8 achOldPwd[KMTAPI_BUF_32_LEN+1];            ///< ������
	s8 achNewPwd[KMTAPI_BUF_32_LEN+1];		      ///< ������
	tagTMTModifyPwd_Api() { memset( this, 0, sizeof( tagTMTModifyPwd_Api) ); }
}*PTMTModifyPwd_Api, TMTModifyPwd_Api;

typedef struct tagTMTAddressBook_Api
{
	s8 achId[KMTAPI_BUF_64_LEN+1];				    ///<ID
	s8 achAccount[KMTAPI_BUF_128_LEN+1];
	s8 achName[KMTAPI_BUF_128_LEN+1];				///<name
	s8 achEmail[KMTAPI_BUF_64_LEN + 1];				///<�����ַ
	s8 achE164[KMTAPI_BUF_16_LEN+1];				///<��Ա��E164��
	s8 achMobilePhone[KMTAPI_BUF_32_LEN+1];			///<��Ա�ĵ绰���� 	
	s8 achExtNum[KMTAPI_BUF_64_LEN+1];				///<��չ����
	tagTMTAddressBook_Api( ) { memset( this, 0, sizeof( *this )); }
}*PTMTAddressBook_Api, TMTAddressBook_Api;

/** ��ַ����Ϣ*/
typedef struct tagTMTAddressBooks_Api
{
	u32 dwAddressNum;
	TMTAddressBook_Api atAddress[KMTAPI_MAX_ADDRESS_NUM];
	tagTMTAddressBooks_Api() { memset( this , 0, sizeof( *this )); }
}*PTMTAddressBooks_Api,TMTAddressBooks_Api;

/** ��ҳ��ѯ�û������ַ����Ϣ*/
typedef struct tagTMTAddressBooksForPage_Api
{
	u32 dwTotalNum; ///<��ַ������
	u32 dwAddressNum; ///<��ǰ��ѯ�ĸ���
	TMTAddressBook_Api atAddress[KMTAPI_MAX_ADDRESS_NUM];
	tagTMTAddressBooksForPage_Api() { memset( this , 0, sizeof( *this )); }
}*PTMTAddressBooksForPage_Api,TMTAddressBooksForPage_Api;

/** ������Ϣ*/
typedef struct tagTMTWbParse_Keda_Department_Api
{
	u32 dwDepartmentId;                                        
	s8	achDepartmentName[KMTAPI_BUF_64_LEN + 1];   
	u32	dwParentId;                                            
	s8	achLeaf[KMTAPI_BUF_64_LEN + 1];                       
    u32 dwSeqNumber;
public:
	tagTMTWbParse_Keda_Department_Api() { memset( this, 0, sizeof(tagTMTWbParse_Keda_Department_Api )); }
}*PTMTWbParse_Keda_Department_Api, TMTWbParse_Keda_Department_Api;

typedef struct tagTMTWbParse_Keda_Departments_Api
{
	u32 						dwDepartmentNum;           
	TMTWbParse_Keda_Department_Api 	atDepartment[KMTAPI_MAX_DEPARTMENT_COUNT]; 

public:
	tagTMTWbParse_Keda_Departments_Api() { memset( this, 0, sizeof(tagTMTWbParse_Keda_Departments_Api) ); }
}*PTMTWbParse_Keda_Departments_Api, TMTWbParse_Keda_Departments_Api;


typedef	struct tagTMTWbParse_Keda_EntUsers_Api
{
	u32	dwUserNum;
	TMTWbParse_Keda_EntUser_Api atEntUser[KMTAPI_MAX_USER_DETAIL_INFO];

public:
	tagTMTWbParse_Keda_EntUsers_Api(){ memset(this, 0, sizeof(tagTMTWbParse_Keda_EntUsers_Api) );}
}*PTMTWbParse_Keda_EntUsers_Api, TMTWbParse_Keda_EntUsers_Api;

typedef	struct tagTMTWBParse_Keda_QueryUsers_Api
{
	u32 					dwTotalCount;
	TMTWbParse_Keda_EntUsers_Api 	tUsers;
public:
	tagTMTWBParse_Keda_QueryUsers_Api() { memset( this, 0, sizeof( *this )); }
}*PTMTWBParse_Keda_QueryUsers_Api, TMTWBParse_Keda_QueryUsers_Api;

typedef	struct tagTMTWbParse_Keda_SearchUsers_Api
{
	u32	dwTotalCount;
	s8  achStr[KMTAPI_BUF_64_LEN+1];
	TMTWbParse_Keda_EntUsers_Api tEntUsers;
public:
	tagTMTWbParse_Keda_SearchUsers_Api(){ memset(this, 0, sizeof(tagTMTWbParse_Keda_SearchUsers_Api) );}
}*PTMTWbParse_Keda_SearchUsers_Api, TMTWbParse_Keda_SearchUsers_Api;

typedef struct tagTMTWbParse_Keda_UserProfile_Api
{
	s8 achUserId[KMTAPI_BUF_64_LEN+1];		 ///< �û�����id���硰124��
	s8 achJobTitle[KMTAPI_BUF_64_LEN+1];	 ///< ְλ���硰��Эʦ����
	s8 achLocation[KMTAPI_BUF_64_LEN+1];	 ///< λ�ã��硰3F-10L-04m��
	s8 achWorkPhone[KMTAPI_BUF_64_LEN+1];	 ///< �����绰���硰8484��
	s8 achMobilePhone[KMTAPI_BUF_64_LEN+1];  ///< �ƶ��绰���硰130xxxx8137��
public:
	tagTMTWbParse_Keda_UserProfile_Api() { memset(this, 0, sizeof(tagTMTWbParse_Keda_UserProfile_Api) ); }
}*PTMTWbParse_Keda_UserProfile_Api, TMTWbParse_Keda_UserProfile_Api;

typedef struct tagTMTWbParse_Keda_User_Api
{
	s8 achMoid[KMTAPI_BUF_64_LEN+1];				 ///< �˺�moid
	s8 achJid[KMTAPI_BUF_256_LEN+1];	             ///< xmpp�˺�
	s8 achAccount[KMTAPI_BUF_128_LEN+1];	         ///< �Զ����˺�
	s8 achEmail[KMTAPI_BUF_128_LEN+1];			     ///< �����ʼ����硰sunfei@kedacom.com��
	s8 achE164[KMTAPI_BUF_64_LEN+1];	             ///< E164
	s8 achMobile[KMTAPI_BUF_64_LEN+1];               ///< ��ϵ�绰
	s8 achDeviceType[KMTAPI_BUF_16_LEN+1];			 ///< �豸����
	s8 achName[KMTAPI_BUF_128_LEN+1];                ///< ΢���ǳƣ��ƴﶼΪʵ�����硰��ɡ���
	s8 achExtNum[KMTAPI_BUF_128_LEN+1];				 ///< �ֻ�
	s8 achSeat[KMTAPI_BUF_256_LEN+1];				 ///< ��λ��
	s8 achBrief[KMTAPI_BUF_512_LEN+1];			     ///< ���
	s8 achPortrait40[KMTAPI_BUF_256_LEN+1];	         ///< �û�ͷ��40���أ�
	s8 achPortrait64[KMTAPI_BUF_256_LEN+1];          ///< �û�ͷ��64���أ�
	s8 achPortrait128[KMTAPI_BUF_256_LEN+1];         ///< �û�ͷ��64���أ�
	u32 dwDepartmentID;								 ///< ����ID
public:
	tagTMTWbParse_Keda_User_Api() { memset(this, 0, sizeof(tagTMTWbParse_Keda_User_Api )); }
}*PTMTWbParse_Keda_User_Api, TMTWbParse_Keda_User_Api;

/////////////////////////////////////////////////////////////////////////
// ������֯�ܹ�
/////////////////////////////////////////////////////////////////////////
typedef struct tagTMTWbParse_Keda_departmentUsers_Api
{
	u32 dwUserNum;
	TMTWbParse_Keda_User_Api atUser[KMTAPI_MAX_EMPLOYEE_COUNT]; 

public:
	tagTMTWbParse_Keda_departmentUsers_Api() { memset( this, 0, sizeof(tagTMTWbParse_Keda_departmentUsers_Api) ); }
}*PTMTWbParse_Keda_departmentUsers_Api, TMTWbParse_Keda_departmentUsers_Api;



typedef struct tagTMTCameraUpgrade_Api
{
	EmEquipmentUpgrading_Api emCameraType;	            ///< ��������ͷ����
	BOOL32	bAction;	                                ///< ��ʼorֹͣ
	s8 achFileName[KMTAPI_MAX_PATH_FILE_NAME_LEN+1];    ///< �����ļ���·��

public:
	tagTMTCameraUpgrade_Api() { memset( this, 0, sizeof(tagTMTCameraUpgrade_Api) ); }
}*PTMTCameraUpgrade_Api, TMTCameraUpgrade_Api;

typedef struct tagTMTKeyPressInfo_Api
{
	BOOL32 bKeyDown;               ///<keydown or keyup
	u32 dwKeySource;               ///<������Դ��ң����������ʱ��д��2
	u32 dwKeyCode;                 ///<������ֵ���ο�EmRemoteScanCode_Api
	u32 dwKeyCount;                ///<��������
	EmKeyState_Api emKeyState;
public:
	tagTMTKeyPressInfo_Api() { memset( this, 0, sizeof(tagTMTKeyPressInfo_Api) ); }
}*PTMTKeyPressInfo_Api, TMTKeyPressInfo_Api;

/** Ethnet ��̫��ģʽ�б�*/
typedef struct tagTEthnetWorkModeList_Api
{
	EmEthnetWorkMode_Api  emCard1Workmode;     ///<(����1ģʽ) 0-�Զ�, 1-10Mȫ˫�� 2-10M��˫��,3-100Mȫ˫�� 4-100M��˫��,5-1000Mȫ˫�� 6-1000M��˫��
	EmEthnetWorkMode_Api  emCard2Workmode;     ///<(����2ģʽ) 0-�Զ�, 1-10Mȫ˫�� 2-10M��˫��,3-100Mȫ˫�� 4-100M��˫��,5-1000Mȫ˫�� 6-1000M��˫��
public:
	tagTEthnetWorkModeList_Api() { memset( this, 0, sizeof(tagTEthnetWorkModeList_Api) ); }
}*PTEthnetWorkModeList_Api, TEthnetWorkModeList_Api;


/** Ethnet ��̫��������Ϣ*/
typedef struct tagTEthnetCardInfo_Api
{ 
	BOOL32 bEnableIpDhcp;    ///<�Ƿ�DHCP��ȡIP	
	u32 dwStaticIp;          ///<IP��ַ���ֶ����䣩
	u32 dwStaticMask;        ///<��������	  
	u32 dwStaticGW;          ///<����        
	u32 dwDhcpIp;            ///<IP��ַ����̬���䣩
	u32 dwDhcpMask;          ///<��������	  
	u32 dwDhcpGW;            ///<����

	BOOL32 bEnableDnsDhcp;   ///<�Ƿ�DHCP��ȡDNS        
	u32 dwStaticDns;         ///<DNS ���ֶ����䣩
	u32 dwStaticDnsBackup;   ///<DNS����	
	u32 dwDhcpDns;           ///<DNS ����̬���䣩
	u32 dwDhcpDnsBackup;     ///<DNS����
public:
	tagTEthnetCardInfo_Api() { memset( this, 0, sizeof(tagTEthnetCardInfo_Api) ); }
}*PTEthnetCardInfo_Api, TEthnetCardInfo_Api;


/** Ethnet ��̫����Ϣ*/
typedef struct tagTEthnetCfg_Api
{
	EmEthInterfaceMode_Api emEthBackupMD;    ///<(EmEthInterfaceMode) 0-���ݣ�1-������
	u32 dwCurCardId;                         ///<����ID  0-����1  1-����2 
	TEthnetCardInfo_Api tEth1;               ///<����1 ������Ϣ
	TEthnetCardInfo_Api tEth2;               ///<����2 ������Ϣ
public:
	tagTEthnetCfg_Api() { memset( this, 0, sizeof(tagTEthnetCfg_Api) ); }
}*PTEthnetCfg_Api, TEthnetCfg_Api;


/** PPPoE������Ϣ*/
typedef struct tagTEthnetPPPoECfg_Api
{
	BOOL32 bEnable;                                    ///<�Ƿ�����PPPoE false-�رգ�true-����
	s8 achUserName[KMTAPI_BUF_64_LEN+1];               ///<�û���
	s8 achPassword[KMTAPI_BUF_64_LEN+1];               ///<����
	BOOL32 bAutoDial;                                  ///<���ŷ�ʽ true:�Զ� false:�ֶ�
public:
	tagTEthnetPPPoECfg_Api() { memset( this, 0, sizeof(tagTEthnetPPPoECfg_Api) ); }
}*PTEthnetPPPoECfg_Api, TEthnetPPPoECfg_Api;

/** PPPoE���Ӻ���ϸ��Ϣ*/
typedef struct tagTPPPoEState_Api
{
	EmPPPoELinkState_Api emState;               ///<����״̬
	u32 dwIp;                                   ///<��ǰIP��ַ
	u32 dwGateway;                              ///<����
	u32 dwDns;                                  ///<DNS 
	u32 dwDnsBackup;                            ///<DNS����
	EmPPPoELinkErrReason_Api emReason;          ///<ʧ��ԭ�� 
public:
	tagTPPPoEState_Api() { memset( this, 0, sizeof(tagTPPPoEState_Api) ); }
}*PTPPPoEState_Api, TPPPoEState_Api;


/** Wifi��ΪAP����ģʽʱ��AP����*/
typedef struct tagTWifiApConfiguration_Api
{
	s8 achSsid[KMTAPI_SSID_MAX_LEN+1];            ///<wifi-ap�ȵ�����
	EmWifiApKeyType_Api emCapabilities;         ///<��ȫ���������
	s8 achKey[KMTAPI_BUF_64_LEN+1];             ///<����ʱ������
	u32 dwDhcpStartIp;                          ///<DHCP��ʼIP
	u32 dwDhcpEndIp;                            ///<DHCP����IP
	u32 dwIp;                                   ///<�豸IP
	u32 dwMask;                                 ///<�豸��������
	EmWifiFrequencyBandType_Api emFrequencyBand; ///<wifiƵ��
public:
	tagTWifiApConfiguration_Api() { memset( this, 0, sizeof(tagTWifiApConfiguration_Api) ); }
}*PTWifiApConfiguration_Api, TWifiApConfiguration_Api;

/** Wifi����״̬�빤��ģʽ*/
typedef struct tagTWifiWorkMode_Api
{
	EmWifiWorkMode_Api       emWifiWKMD;  ///<Wifi����ģʽ����     
	TWifiApConfiguration_Api tWifiApCfg;  ///<��wifi_workmodeΪemWifiWorkModeWifiAp_Apiʱ,��Ч
public:
	tagTWifiWorkMode_Api() { memset( this, 0, sizeof(tagTWifiWorkMode_Api) ); }
}*PTWifiWorkMode_Api, TWifiWorkMode_Api;

/** Wifi��Ϊ�ͻ��˹���ģʽʱ������*/
typedef struct tagTWifiConfiguration_Api
{
	BOOL32 bEnableAutoConn;       ///<�Ƿ��Զ����ӣ�Ĭ�Ͽ���
	BOOL32 bEnableAutoIp;         ///<�Ƿ��Զ���ȡip,Ĭ�Ͽ���
	u32 dwIp;                     ///<IP��ַ
	u32 dwMask;                   ///<��������	  
	u32 dwGateway;                ///<����
public:
	tagTWifiConfiguration_Api() { memset( this, 0, sizeof(tagTWifiConfiguration_Api) ); }
}*PTWifiConfiguration_Api, TWifiConfiguration_Api;


/** Wifi ɨ������Ϣ*/
typedef struct tagTWifiScanResult_Api
{
	s8 achSsid[KMTAPI_SSID_MAX_LEN+1];        ///<wifi-ap�ȵ�����
	EmWifiKeyType_Api emKeyType;            ///<��������  
	EmWifiSignalLevel_Api emSignalLevel;    ///<�ź�ǿ��
	BOOL32 bIsSave;                         ///<���ر������ true-����ʹ�ù�  false-δʹ�ù�
	s32 nNetworkId;                         ///<��������ӱ�ʶ issaveΪtrueʱ��Ч
public:
	tagTWifiScanResult_Api() { memset( this, 0, sizeof(tagTWifiScanResult_Api) ); }
}*PTWifiScanResult_Api, TWifiScanResult_Api;


/** Wifi ɨ�����б�*/ 
typedef struct tagTWifiScanResultList_Api
{
	TWifiScanResult_Api atScanList[KMTAPI_BUF_32_LEN];      ///<wifiɨ���б�
	u8 byCnt;
public:
	tagTWifiScanResultList_Api() { memset( this, 0, sizeof(tagTWifiScanResultList_Api) ); }
}*PTWifiScanResultList_Api, TWifiScanResultList_Api;


/** ��ǰWifi���ӵ���ϸ��Ϣ*/
typedef struct tagTWifiCurDetailInfo_Api
{
	EmWifiLinkState_Api  emState;                ///<����״̬
	s32 nNetworkId;                              ///<��ǰ�õ�������ID��ʶ
	s8 achSsid[KMTAPI_SSID_MAX_LEN+1];             ///<wifi-ap�ȵ�����
	s8 achBSsid[KMTAPI_SSID_MAX_LEN+1];            ///<wifi-ap BSSID
	s8 achMacAddress[KMTAPI_BUF_64_LEN+1];       ///<��ǰAP��MAC
	u32 dwIp;                                    ///<��ǰIP��ַ
	u32 dwMask;                                  ///<��������	  
	u32 dwGateway;                               ///<����	
	EmWifiLinkErrReason_Api emReason;            ///<ʧ��ԭ�� 
public:
	tagTWifiCurDetailInfo_Api() { memset( this, 0, sizeof(tagTWifiCurDetailInfo_Api) ); }
}*PTWifiCurDetailInfo_Api, TWifiCurDetailInfo_Api;


/** ��ǰWifi���ӵ�ͳ����Ϣ*/
typedef struct tagTWifiStatisInfo_Api
{
	s8 achSsid[KMTAPI_SSID_MAX_LEN+1];            ///<wifi-ap�ȵ�����
	s32 nNetworkId;                             ///<��ǰ�õ�������ID��ʶ
	EmWifiSignalLevel_Api emSignalLevel;        ///<�ź�ǿ��
	u32 dwDownTotalBytes;                       ///<���������� Byte
	u32 dwUpTotalBytes;                         ///<���������� Byte
public:
	tagTWifiStatisInfo_Api() { memset( this, 0, sizeof(tagTWifiStatisInfo_Api) ); }
}*PTWifiStatisInfo_Api, TWifiStatisInfo_Api;



/** Wifi ���Ӳ���*/
typedef struct tagTWifiConnParam_Api
{
	BOOL32 bIsSave;                               ///<�����Ƿ񱣴���� true-����ʹ�ù�  false-δʹ�ù�
	s8 achSsid[KMTAPI_SSID_MAX_LEN+1];              ///<wifi-ap�ȵ����� (issaveΪfalseʱ��Ч)
	EmWifiKeyType_Api emKeyType;                  ///<�������� (issaveΪfalseʱ��Ч)       
	s8 achPassword[KMTAPI_BUF_64_LEN+1];          ///<��¼����,δ����Ϊ�� (issaveΪfalseʱ��Ч)
	s32 nNetworkId;                               ///<��������ӱ�ʶ (issaveΪtrueʱ��Ч)
public:
	tagTWifiConnParam_Api() { memset( this, 0, sizeof(tagTWifiConnParam_Api) ); }
}*PTWifiConnParam_Api, TWifiConnParam_Api;


/** MobileData ����*/
typedef struct tagTMobileDataWorkMode_Api
{
	BOOL32 bEnable;                             ///<0-�رգ� 1-����
public:
	tagTMobileDataWorkMode_Api() { memset( this, 0, sizeof(tagTMobileDataWorkMode_Api) ); }
}*PTMobileDataWorkMode_Api, TMobileDataWorkMode_Api;




/** MobileData ������Ϣ����*/
typedef struct tagTMobileDataCurDetailInfo_Api
{
	EmMobileDataLinkState_Api emState;                    ///<����״̬ 
	EmMobileDataNetType_Api   emNetType;                  ///<��Ӫ������
	EmMobileDataNetGenerationType_Api emGenerationType;   ///<�汾��Ϣ 
	s8 achSsid[KMTAPI_SSID_MAX_LEN+1];                      ///<���������
	u32 dwIp;                                             ///<��ǰIP��ַ
	s8 achConnTime[KMTAPI_BUF_64_LEN+1];                  ///<����ʱ��
	EmMobileDataLinkErrReason_Api emReason;               ///<ʧ��ԭ�� 
public:
	tagTMobileDataCurDetailInfo_Api() { memset( this, 0, sizeof(tagTMobileDataCurDetailInfo_Api) ); }
}*PTMobileDataCurDetailInfo_Api, TMobileDataCurDetailInfo_Api;


/** MobileData ͳ������*/
typedef struct tagTMobileDataStatisInfo_Api
{
	EmMobileDataLinkState_Api emSignalLevel;                ///<�ź�ǿ��
	u32 dwUpBandwidth;                                      ///<�ϴ�����Kbps
	u32 dwDownBandwidth;                                    ///<��������Kbps
	u32 dwUpBytes;                                          ///<�ϴ�������Byte
	u32 dwDownBytes;                                        ///<����������Byte
public:
	tagTMobileDataStatisInfo_Api() { memset( this, 0, sizeof(tagTMobileDataStatisInfo_Api) ); }
}*PTMobileDataStatisInfo_Api, TMobileDataStatisInfo_Api;


/** ����ͨѶIP��Ϣ*/
typedef struct tagTNetUsedInfo_Api
{		
	EmNetAdapterWorkType_Api emUsedType;   ///<��ǰʹ�õ��������� 
	u32 dwIp;                              ///<IP��ַ
	u32 dwMask;                            ///<��������	  
	u32 dwGateway;                         ///<����        	
	u32 dwDns;                             ///<DNS
	u32 dwDnsBackup;                       ///<DNS����
public:
	tagTNetUsedInfo_Api() { memset( this, 0, sizeof(tagTNetUsedInfo_Api) ); }
}*PTNetUsedInfo_Api, TNetUsedInfo_Api;


/** ����Ԥ��λ��������*/
typedef struct tagTMTPreSetNameInfo_Api
{
	u32 dwPresetIndex;                       ///<Ԥ��λ����
	s8 achPresetName[KMTAPI_BUF_64_LEN+1];   ///<Ԥ��λ����
public:
	tagTMTPreSetNameInfo_Api() { memset( this, 0, sizeof(tagTMTPreSetNameInfo_Api) ); }
}*PTMTPreSetNameInfo_Api, TMTPreSetNameInfo_Api;

/** ����Ԥ��λ��������*/
typedef struct tagTAllMTPreSetNameInfoCfg_Api
{
	u16 byPri1stPresetCnt;				///<��һ·����Ԥ��λʵ�ʴ�С
	TMTPreSetNameInfo_Api atPri1stPresetNameInfo[KMTAPI_MAX_CAMERA_PRESET_NUM];   ///<��һ·��������Ԥ��λ��Ϣ
    u16 byPri2ndPresetCnt;				///<�ڶ�·����Ԥ��λʵ�ʴ�С
    TMTPreSetNameInfo_Api atPri2ndPresetNameInfo[KMTAPI_MAX_CAMERA_PRESET_NUM];   ///<�ڶ�·��������Ԥ��λ��Ϣ
	u16 byPri3rdPresetCnt;				///<����·����Ԥ��λʵ�ʴ�С
	TMTPreSetNameInfo_Api atPri3rdPresetNameInfo[KMTAPI_MAX_CAMERA_PRESET_NUM];   ///<����·��������Ԥ��λ��Ϣ
public:
	tagTAllMTPreSetNameInfoCfg_Api() 
	{
		byPri1stPresetCnt = 0;
        byPri2ndPresetCnt = 0;
		byPri3rdPresetCnt = 0;
	}
}*PTAllMTPreSetNameInfoCfg_Api, TAllMTPreSetNameInfoCfg_Api;

/** ����豸����Ϣ*/
typedef struct tagTMTMonitorGroup_Api
{
	s8 achId[KMTAPI_BUF_64_LEN+1];
	s8 achGroupId[KMTAPI_BUF_64_LEN+1];
	s8 achGroupName[KMTAPI_BUF_64_LEN+1];
	s8 achParentId[KMTAPI_BUF_64_LEN+1];
	s8 achLeaf[KMTAPI_BUF_64_LEN+1];
public:
	tagTMTMonitorGroup_Api(){ memset( this, 0, sizeof(tagTMTMonitorGroup_Api) ); }
}*PTMTMonitorGroup_Api, TMTMonitorGroup_Api;

typedef struct tagTMTMonitorGroups_Api
{
	u32	dwGroupCount;
	TMTMonitorGroup_Api atMonitorGroup[KMTAPI_MAX_MONITOR_GROUP_COUNT];
public:
	tagTMTMonitorGroups_Api(){ memset( this, 0, sizeof(tagTMTMonitorGroups_Api) ); }
}*PTMTMonitorGroups_Api, TMTMonitorGroups_Api;

/** ����豸��Ϣ*/
typedef struct tagTMTMonitorDevice_Api
{
	s8	achGroupId[ KMTAPI_BUF_64_LEN+1 ];		///<��ǰ�豸�����豸���ID
	s8	achId[ KMTAPI_BUF_64_LEN+1 ];
	s8	achDeviceGUID[ KMTAPI_BUF_64_LEN+1 ];
	s8	achName[ KMTAPI_BUF_128_LEN+1 ];
	s8	achE164[ KMTAPI_MAX_MT_E164_LEN+1 ];
	s8	achDeviceType[ KMTAPI_BUF_128_LEN+1 ];
	s8	achDescription[ KMTAPI_BUF_256_LEN+1 ];
	s8  achNote[ KMTAPI_BUF_256_LEN+1 ];
public:
	tagTMTMonitorDevice_Api(){ memset( this, 0, sizeof(tagTMTMonitorDevice_Api) ); }
}*PTMTMonitorDevice_Api, TMTMonitorDevice_Api;

typedef struct tagTMTMonitorDevices_Api
{
	u32	dwDeviceCount;
	TMTMonitorDevice_Api atMonitorDevice[KMTAPI_MAX_MONITOR_DEVICE_COUNT];
public:
	tagTMTMonitorDevices_Api(){ memset( this, 0, sizeof(tagTMTMonitorDevices_Api) ); }
}*PTMTMonitorDevices_Api, TMTMonitorDevices_Api;

typedef struct tagTMTVersion_Api
{
	s8 abyVersion[KMTAPI_BUF_32_LEN+1];
public:
	tagTMTVersion_Api() { memset( this, 0, sizeof(tagTMTVersion_Api)); }
}*PTTMTVersion_Api, TMTVersion_Api;

/** �޸ĵ�½������Ϣ�ṹ*/
typedef struct tagTMTModifyPwdInfo_Api
{
	s8 achUserName[KMTAPI_MAX_USERNAME_LEN+1];
	s8 achOldPwd[KMTAPI_MAX_USERPWD_LEN+1];
	s8 achNewPwd[KMTAPI_MAX_USERPWD_LEN+1];

public:
	tagTMTModifyPwdInfo_Api() { memset( this, 0, sizeof(tagTMTModifyPwdInfo_Api)); }
}*PTMTModifyPwdInfo_Api, TMTModifyPwdInfo_Api;

/** ���������Ա����֪ͨ(���������������ʾ"ĳĳ����������")*/ 
typedef struct tagTMTImMultiChatAddMemberNtf_Api
{
	u32   dwSessionId;                   ///< ������id
	s8    achMail[KMTAPI_BUF_64_LEN+1];  ///<����id
	TRoomId_Api  tRoomId;
public:
	tagTMTImMultiChatAddMemberNtf_Api() { memset( this, 0, sizeof(tagTMTImMultiChatAddMemberNtf_Api)); }
}*PTMTImMultiChatAddMemberNtf_Api,TMTImMultiChatAddMemberNtf_Api;

typedef struct tagTMTWeiboLogin_Api
{
	s8 achUserName[KMTAPI_BUF_128_LEN+1];
	s8 achPassword[KMTAPI_MAX_USERPWD_LEN+1];
public:
	tagTMTWeiboLogin_Api() { memset( this, 0, sizeof(tagTMTWeiboLogin_Api)); }
}*PTMTWeiboLogin_Api, TMTWeiboLogin_Api;

typedef struct tagTMTSysHint_Api
{
	EmHintCode_Api emHintCode;             ///<��ʾ��
	s8 achExtraParam[KMTAPI_BUF_64_LEN+1]; ///<���Ӳ���
public:
	tagTMTSysHint_Api() { memset( this, 0, sizeof(tagTMTSysHint_Api)); }
}*PTMTSysHint_Api, TMTSysHint_Api;

typedef struct tagTRecordParam
{   /** ��windowsƽ̨*/
	s8     achFilePath[KMTAPI_BUF_256_LEN+1];  ///<¼���ļ����·��
	BOOL32 bLocal;                             ///<�Ƿ�¼����
	BOOL32 bHasAud;                            ///<�Ƿ����Ƶ
	BOOL32 bHasAuxVid;                         ///<�Ƿ��˫������bLocalΪtrueʱ��Ч
	s8     achFileName[KMTAPI_BUF_128_LEN+1];  ///<¼���ļ���
public:
	tagTRecordParam() { memset( this, 0, sizeof(tagTRecordParam)); }
}*PTRecordParam_Api, TRecordParam_Api;

typedef struct tagTRecordDiskAlarmLevel
{   /** ��windowsƽ̨*/
	s8  achPartName[KMTAPI_BUF_256_LEN+1];  ///<��������c:
	u32 dwAlarmLevel1;                      ///<һ���澯��ֵ����λM������20M
	u32 dwAlarmLevel2;                      ///<�����澯��ֵ����λM������10M
public:
	tagTRecordDiskAlarmLevel() { memset( this, 0, sizeof(tagTRecordDiskAlarmLevel)); }
}*PTRecordDiskAlarmLevel_Api, TRecordDiskAlarmLevel_Api;

typedef struct tagTMTCameraTypeInfo_Api
{
	s8   achName[KMTAPI_MAX_DEV_TYPE_NAME_LEN+1];///<����ͷ������
	u32  dwMaxAddr; 		                   	///<����ͷ����ֵַ
	u32  dwMaxSpeedLevel;	                    ///<����ͷ����ٶȼ��� 
public:
	tagTMTCameraTypeInfo_Api() { memset( this, 0, sizeof(tagTMTCameraTypeInfo_Api)); }
}*PTMTCameraTypeInfo_Api, TMTCameraTypeInfo_Api;

typedef struct tagTMTCameraTypeList_Api
{
	u8 byCnt;                                                           ///<ʵ�ʵ�����ͷ����
	TMTCameraTypeInfo_Api atCameraTypeList[KMTAPI_MAX_CAMERA_TYPE_NUM]; ///<��������ͷ����������
public:
	tagTMTCameraTypeList_Api() { memset( this, 0, sizeof(tagTMTCameraTypeList_Api)); }
}*PTMTCameraTypeList_Api, TMTCameraTypeList_Api;

typedef struct tagTMTMultiRes_Api
{
	EmMtResolution_Api aemRes[KMTAPI_BUF_32_LEN];
	u8 byCnt;
public:
	tagTMTMultiRes_Api() { memset( this, 0, sizeof(tagTMTMultiRes_Api)); }
}*PTMTMultiRes_Api, TMTMultiRes_Api;

/** ���ܸ澯*/
typedef struct tagTAlarmTrap_Api
{
	u32 dwAlarmCode;                         ///<�澯��
	u32 dwAlarmState;                        ///<�澯״̬	
	u32 dwThreshHoldVal;                     ///<��ǰ��ֵ
public:
	tagTAlarmTrap_Api() { memset( this, 0, sizeof(tagTAlarmTrap_Api)); }
}*PTAlarmTrap_Api, TAlarmTrap_Api;

/** cpu�ϱ�������Ϣ*/
typedef struct tagTCPUReportData_Api
{
	u32 dwTotalCpuUseage;                    ///<CPU����ʹ����
	u32 adwCpuCoreUseage[KMTAPI_BUF_64_LEN]; ///<CPUÿ���˵�ʹ����
	u8 byCnt;
	u32 dwMemUsage;                          ///<�ڴ�ʹ����
	BOOL32 bInConf;                          ///<�Ƿ��ڻ�����
	s8 achRptTime[KMTAPI_BUF_64_LEN+1];      ///<�ϱ�ʱ�� HH:MM:SS������ڶ�������ʱ��
public:
	tagTCPUReportData_Api() { memset( this, 0, sizeof(tagTCPUReportData_Api)); }
}*PTCPUReportData_Api, TCPUReportData_Api;

/** ��¼ʱ�ϱ�������Ϣ*/
typedef struct tagTLogInReportData_Api
{
	u32 dwMemSize;       ///<�����ڴ��С
	u32 dwUpBandWidth;   ///<���д���
	u32 dwDownBandWidth; ///<���д���
	u32 dwIp;      ///<�ն˵�IP
	u32 dwDnsIp;   ///<DNS��IP
	u32 dwXapIp;   ///<XAP������IP
	u32 dwCoreNum; ///<CPU����
	u32 dwCpuFreq; ///<CPU��Ƶ
	s8 achCpuType[KMTAPI_BUF_64_LEN+1]; ///<CPU�ͺ�
	s8 achVer[KMTAPI_BUF_64_LEN+1];     ///<�ն˰汾��
	s8 achRptTime[KMTAPI_BUF_64_LEN+1]; ///<�ϱ�ʱ�� HH:MM:SS������ڶ�������ʱ��
public:
	tagTLogInReportData_Api() { memset( this, 0, sizeof(tagTLogInReportData_Api)); }
}*PTLogInReportData_Api, TLogInReportData_Api;

/** ����仯ʱ�ϱ����ܵ���Ϣ*/
typedef struct tagTNetChangeReportData_Api
{
	u32 dwUpBandWidth;   ///<���д���
	u32 dwDownBandWidth; ///<���д���
	u32 dwIp;    ///<�ն˵�IP
	u32 dwDnsIp; ///<DNS��IP
	u32 dwXapIp; ///<XAP������IP
	s8 achRptTime[KMTAPI_BUF_64_LEN+1]; ///<�ϱ�ʱ�� 2014-06-16/09:57:50������ڶ�������ʱ��
public:
	tagTNetChangeReportData_Api() { memset( this, 0, sizeof(tagTNetChangeReportData_Api)); }
}*PTNetChangeReportData_Api, TNetChangeReportData_Api;

/** ���ʱ�ϱ����ܵ���Ϣ*/
typedef struct tagTEnterConfReportData_Api
{
	u32 dwCallRsate;   ///<��������
public:
	tagTEnterConfReportData_Api() { memset( this, 0, sizeof(tagTEnterConfReportData_Api)); }
}*PTEnterConfReportData_Api, TEnterConfReportData_Api;

/** �쳣�ļ��ϱ�����*/
typedef struct tagTExceptionFileReportData_Api
{
	s8  achCrashLog[KMTAPI_BUF_1024_LEN * 5]; ///<�쳣��־
	u16 wCrashLogLen;
	s8  achVer[KMTAPI_BUF_64_LEN + 1];        ///<�ն˰汾��
	s8  achRptTime[KMTAPI_BUF_64_LEN + 1];    ///<�ϱ�ʱ�� 2014-06-16/09:57:50������ڶ�������ʱ��
public:
	tagTExceptionFileReportData_Api() { memset( this, 0, sizeof(tagTExceptionFileReportData_Api)); }
}*PTExceptionFileReportData_Api, TExceptionFileReportData_Api;

typedef struct tagTNewUpgradeVersion_Api
{
	u32 dwLevel;
	s8  achSusIp[KMTAPI_BUF_64_LEN + 1];    ///<����������ip��ַ
	s8  achVer[KMTAPI_BUF_64_LEN + 1];      ///<�°汾�İ汾��
	s8  achOemStr[KMTAPI_BUF_64_LEN + 1];   ///<oem�ַ���
public:
	tagTNewUpgradeVersion_Api() { memset( this, 0, sizeof(tagTNewUpgradeVersion_Api));}
}*PTNewUpgradeVersion_Api, TNewUpgradeVersion_Api;

typedef struct tagTAudInputState_Api
{
	BOOL32 bUsed;                         ///<�Ƿ��������ź�
	EmHDAudPortIn_Api emAudInputType;     ///<����ӿ�����
public:
	tagTAudInputState_Api() { memset( this, 0, sizeof(tagTAudInputState_Api));}
}*PTAudInputState_Api, TAudInputState_Api;

typedef struct tagTMultiAudInputState_Api
{
	u8 byCnt;
	TAudInputState_Api atAudInputState[KMTAPI_MAX_AUDIO_IN_NUM];  ///<��Ƶ����ӿ�״̬
public:
	tagTMultiAudInputState_Api() { memset( this, 0, sizeof(tagTMultiAudInputState_Api)); }
}*PTMultiAudInputState_Api, TMultiAudInputState_Api;

typedef struct tagTAudOutputState_Api
{
	BOOL32 bUsed;                           ///<�Ƿ��������ź�
	EmHDAudPortOut_Api emAudOutputType;     ///<����ӿ�����
public:
	tagTAudOutputState_Api() { memset( this, 0, sizeof(tagTAudOutputState_Api)); }
}*PTAudOutputState_Api, TAudOutputState_Api;

typedef struct tagTMultiAudOutputState_Api
{
	u8 byCnt;
	TAudOutputState_Api atAudOutputState[KMTAPI_MAX_AUDIO_OUT_NUM];     ///<��Ƶ����ӿ�״̬
public:
	tagTMultiAudOutputState_Api() { memset( this, 0, sizeof(tagTMultiAudOutputState_Api)); }
}*PTMultiAudOutputState, TMultiAudOutputState_Api;

/** �ն˱�� */
typedef struct tagTAudOutVol_Api
{
	EmCodecComponent_Api        emCodecType;                ///< ����
	EmCodecComponentIndex_Api emCodecId; ///< Id
	u32         dwVol;                 ///< ����
public:
	tagTAudOutVol_Api(){ memset( this ,0 ,sizeof( struct tagTAudOutVol_Api ) );	}

}*PTAudOutVol_Api, TAudOutVol_Api;


/** ������� */
typedef struct tagTNetParam_Api {
	u8               byRemoteNum;                           ///<ʵ��Զ�˵�ַ����,���Ϳ���

	/** ���KMTAPI_MAX_NET_DEST_NUM��������ʱֻ֧��1�� */
	TRtpRtcpPair_Api tLocalNet;                             ///<���ص�ַ��
	TRtpRtcpPair_Api atRemoteNet[KMTAPI_MAX_NET_DEST_NUM];  ///<Զ�˵�ַ��

public:
	tagTNetParam_Api(){ memset( this ,0 ,sizeof( struct tagTNetParam_Api ) ); }
}*PTNetParam_Api, TNetParam_Api;

/** ������״̬(��windows˫��ʹ��) */
typedef struct tagTMtVncVidEncStatus_Api
{
	BOOL32 			    bVideoSignal;		  ///<�Ƿ�����Ƶ�ź�
	BOOL32	            bVideoCapStart;       ///<�Ƿ�ʼ��Ƶ����
	BOOL32			    bVideoEncStart;       ///<�Ƿ�ʼ��Ƶ����
	BOOL32			    bNetSndVideoStart;    ///<�Ƿ�ʼ��Ƶ����

	TVidEncParam_Api	tVideoEncParam;       ///<��Ƶ�������
	TNetParam_Api       tVideoSendAddr;       ///<��Ƶ���͵�ַ
	u32                 dwSetEncParam;        ///<����Ӳ�������������
	u32                 dwVideoSend;          ///<�ѷ��͵���Ƶ����
public:
	tagTMtVncVidEncStatus_Api() { memset( this, 0, sizeof(*this)); }
}*PTMtVncVidEncStatus_Api, TMtVncVidEncStatus_Api;

/** ������״̬(��windows˫��ʹ��) */
typedef struct tagTMtVncVidEncStatis_Api
{
	u8                  byVideoFrameRate;     ///<��Ƶ֡��
	u32                 dwVideoBitRate;       ///<��Ƶ�����ٶ�
	u32                 dwVideoPackLose;      ///<��Ƶ��֡��
	u32                 dwVideoPackError;     ///<��Ƶ��֡��
	u32                 dwAvrVideoBitRate;    ///<1��������Ƶ����ƽ������
public:
	tagTMtVncVidEncStatis_Api() { memset( this, 0, sizeof(*this)); }
}*PTMtVncVidEncStatis_Api, TMtVncVidEncStatis_Api;

/** FXO����״̬ */
typedef struct tagTFxoState_Api
{
	EmFxoState_Api emState;		          ///<Fxo״̬
public:
	tagTFxoState_Api(){ memset( this ,0 ,sizeof( struct tagTFxoState_Api ) );	}
}*PTFxoState_Api, TFxoState_Api;

/** �����ļ���Ϣ */
typedef struct tagTSnapshotFileInfo_Api
{
	s8 achFilePath[KMTAPI_BUF_64_LEN+1]; ///<�ļ�����·�� 
	s8 achFileName[KMTAPI_BUF_64_LEN+1]; ///<�ļ���
	TMTTime_Api  tFileCreateTime;         ///<�ļ�����ʱ��
public:
	tagTSnapshotFileInfo_Api(){ memset( this ,0 ,sizeof( struct tagTSnapshotFileInfo_Api ) );	}
}*PTSnapshotFileInfo_Api, TSnapshotFileInfo_Api;



typedef struct tagTSnapshotFileList_Api
{
	TSnapshotFileInfo_Api        arrTSnapshotFileInfo[KMTAPI_MAX_SNAPSHOT_LIST_NUM];  ///< ��������б���Ϣ
	u8              byCnt;                                                            ///< ʵ���б�����
public:
	tagTSnapshotFileList_Api(){ memset( this, 0, sizeof( struct tagTSnapshotFileList_Api) ); }
}*PTSnapshotFileList_Api, TSnapshotFileList_Api;


/** ͼ���������windowsƽ̨ */
typedef struct tagTImageParam_Api
{
	EmImgParam_Api emImgParamType;  ///< ͼ���������
	u32            dwVal;           ///< ����ֵ
	BOOL32         bAuto;           ///< �Ƿ��Զ�
public:
	tagTImageParam_Api(){ memset( this ,0 ,sizeof( struct tagTImageParam_Api ) );	}

}*PTImageParam_Api, TImageParam_Api;

/** ͼ��Ĭ�ϲ�������windowsƽ̨ */
typedef struct tagTDefaultImageParam_Api
{
	EmImgParam_Api emImgParamType;  ///< ͼ���������
	u32            dwMinVal;        ///< ������Сֵ
	u32            dwMaxVal;        ///< �������ֵ
	u32            dwDefVal;        ///< ����Ĭ��ֵ
	u32            dwStep;          ///< ��������ֵ
public:
	tagTDefaultImageParam_Api(){ memset( this ,0 ,sizeof( struct tagTDefaultImageParam_Api ) );	}

}*PTDefaultImageParam_Api, TDefaultImageParam_Api;

/** ping�����ѡ��*/
typedef struct tagTPingCmdOption_Api
{
	u32 dwPackSize;          ///< Ҫping�����ݱ��Ĵ�С�����ֽ�Ϊ��λ
	u32 dwTimeOut;           ///< ping�ĳ�ʱֵ������Ϊ��λ
	u32 dwTTL;               ///< TTLֵ
	u32 dwCount;             ///< PING�Ĵ���
public:
	tagTPingCmdOption_Api() { memset( this, 0, sizeof(tagTPingCmdOption_Api) ); }
}*PTPingCmdOption_Api, TPingCmdOption_Api;

/** ping�����ѡ��*/
typedef struct tagTPingTestParam_Api
{
	s8 achDstInfo[KMTAPI_BUF_32_LEN+1];                      ///< pingĿ��(ip/dns)
	TPingCmdOption_Api tPingOption;   ///< ping�����ѡ��
	u32 dwUserId;                     ///< ���ڱ�ʶ�����ߵ�UID����δʹ��
public:
	tagTPingTestParam_Api() { memset( this, 0, sizeof(tagTPingTestParam_Api) ); }
}*PTPingTestParam_Api, TPingTestParam_Api;

/** ping�Ľ��*/
typedef struct tagTPingResult_Api
{
	EmPingErrcode_Api emPingErrCode;
	u32 dwTTL;   
	u32 dwTripTime;
	u32 dwUserId;
	u32 dwErrType;
	u32 dwErrCode;
public:
	tagTPingResult_Api() { memset( this, 0, sizeof(tagTPingResult_Api) ); }
}*PTPingResult_Api, TPingResult_Api;

/** DNS��ѯIP */
typedef  struct tagTDNSNameToIpInfo_Api
{
	s8 achDnsName[KMTAPI_BUF_32_LEN+1];                //DNS����
public:
	tagTDNSNameToIpInfo_Api() { memset( this, 0, sizeof(tagTDNSNameToIpInfo_Api) ); }
}*PTDNSNameToIpInfo_Api, TDNSNameToIpInfo_Api;

/** DNS��ѯIP */
typedef struct tagTDNSNameToIpResult_Api
{
	s8 achDnsName[KMTAPI_BUF_32_LEN+1];                ///<DNS����
	u32 dwIp;                      ///<��ѯ����ip��ַ��������
	u32 dwErrorCode;              ///<�������
public:
	tagTDNSNameToIpResult_Api() { memset(this, 0, sizeof(tagTDNSNameToIpResult_Api) ); }
}*PTDNSNameToIpResult_Api, TDNSNameToIpResult_Api;

/** ip mac��ͻ��Ϣ*/
typedef struct tagTNetConfilictedInfo_Api
{
	EmNetConflictType_Api emConflictType;  ///< ��ͻ����
	s8  achMac[KMTAPI_BUF_256_LEN];        ///< ������ͻ�Ľӿڵĵ�ǰmac��ַ
	s8  achIp[KMTAPI_BUF_256_LEN];         ///< ������ͻ�Ľӿڵĵ�ǰip��ַ
public:
	tagTNetConfilictedInfo_Api() { memset( this, 0, sizeof(tagTNetConfilictedInfo_Api) ); }
}*PTNetConfilictedInfo_Api, TNetConfilictedInfo_Api;

/**  ethernet DHCP ״̬��Ϣ*/
typedef struct tagTDHCPStateInfo_Api
{	
	u32 dwState;
public:
	tagTDHCPStateInfo_Api() { memset( this, 0, sizeof(tagTDHCPStateInfo_Api) ); }
}*PTDHCPStateInfo_Api, TDHCPStateInfo_Api;

/**  ethernet DHCP ״̬��Ϣ*/
typedef struct tagTDHCPLeaseInfo_Api
{	
	u32 dwEthId;        ///< ��̫���ӿ�ID
	u32 dwIp;           ///< ip��ַ
	u32 dwMask;         ///< ����
	u32 dwGateway;      ///< ����
	u32 dwDuration;     ///< ����ʱ��
	u32 dwDnsNum;       ///< dns����
	u32 adwDnsServerList[KMTAPI_MAX_ETH_DNSLIST_NUM];  ///< dns�б� 
public:
	tagTDHCPLeaseInfo_Api() { memset( this, 0, sizeof(tagTDHCPLeaseInfo_Api) ); }
}*PTDHCPLeaseInfo_Api, TDHCPLeaseInfo_Api;

/** ����ethernet �ӿ���Ϣ*/
typedef struct tagTEthnetInterfaceParam_Api
{
	u32 dwIp;                            ///< IP��ַ(������)
	u32 dwMask;                          ///< ��������  (������)  
	s8  achMac[KMTAPI_BUF_256_LEN+1];    ///<  MAC��ַ
public:
	tagTEthnetInterfaceParam_Api() {memset( this, 0, sizeof(tagTEthnetInterfaceParam_Api) );}
}*PTEthnetInterfaceParam_Api, TEthnetInterfaceParam_Api;

/**  PPPoE ͳ����Ϣ*/
typedef struct tagTPPPoEStatis_Api
{	
	u32 dwLinkTime;       ///< ��·������ʱ��
	u32 dwLinkDowntimes;  ///< ��·�����Ĵ���ͳ��
	u32 dwNumPkgSent;     ///< �ܹ����͵����ݰ���--��������Э����Լ��ϲ�ҵ���������ݰ�/
	u32 dwNumPkgRecved;   ///< �ܹ����յ����ݰ���
	u32 dwNumBytesSent;   ///< �ܹ����͵��ֽ���
	u32 dwNumBytesRecved; ///< �ܹ����յ��ֽ���
public:
	tagTPPPoEStatis_Api() { memset( this, 0, sizeof(tagTPPPoEStatis_Api) ); }
}*PTPPPoEStatis_Api, TPPPoEStatis_Api;

/**  ·�ɱ����ò���*/
typedef struct tagTRouteItemInfo_Api
{	
	u32 dwInterface;    ///< ����ӿڣ���ʾ����·�ɾ����ĸ��ӿ�ת����ȥ
	u32 dwDstNetwork;   ///< ·�ɵ�Ŀ������
	u32 dwDstNetMask;   ///< ·�ɵ�Ŀ����������
	u32 dwGateway;      ///< ·������
	u32 dwPriority;     ///< ���ȼ���ֵԽ�ͱ�ʾ����·�����ȼ�Խ�ߣ�Ĭ��0�����255
public:
	tagTRouteItemInfo_Api() { memset( this, 0, sizeof(tagTRouteItemInfo_Api) ); }
}*PTRouteItemInfo_Api, TRouteItemInfo_Api;

/**  ·�ɱ����ò�������*/
typedef struct tagTRouteItemInfoList_Api
{	
	TRouteItemInfo_Api atRouteList[KMTAPI_MAX_ROUTEITEM_CNT]; ///< ·�ɱ���
	u32 dwCnt;                                                ///< ·�ɸ���
public:
	tagTRouteItemInfoList_Api() { memset( this, 0, sizeof(tagTRouteItemInfoList_Api) ); }
}*PTRouteItemInfoList_Api, TRouteItemInfoList_Api;

/** E1��Ԫ*/
typedef struct tagTE1Unit_Api
{
	u32 dwE1ID;
	u32 dwUsedFlag;       ///< ʹ�ñ�־,��1ʹ�ã����������Ч��0��ʹ�ã����������Ч
	u32 dwE1TSMask;       ///< E1ʱ϶����˵��,�����
	u32 dwProtocolType;   ///< �ӿ�Э���װ����, ����ǵ�E1���ӿ���ָ��PPP/HDLC������Ƕ�E1�������ӱ�����PPPЭ��
	u32 dwEchoInterval;   ///< echo����ʱ��������Ϊ��λ����Ч��Χ0-256����Ĭ��ֵ2����
	u32 dwEchoMaxRetry;   ///< echo����ط���������Ч��Χ0-256����Ĭ��ֵ5����
public:
	tagTE1Unit_Api() {memset(this, 0, sizeof(tagTE1Unit_Api));}
}*PTE1Unit_Api, TE1Unit_Api;

/** E1������Ϣ*/
typedef struct tagTE1Group_Api
{
	BOOL32 bEnable;                                    ///<�Ƿ�����
	u32 dwUnitNum;                                     ///<ʹ��E1��Ԫ����
	u32 dwIsBind;                                      ///<�Ƿ��
	u32 dwGroupID;                                     ///<����
	u32 dwIpAddr;                                      ///<ip��ַ��������
	u32 dwMask;                                        ///<���룬������ 
	u32 dwAuthType;                                    ///<PPP���ӵ���֤����PAP/CHAP,Ĭ����MP_AUTHENTICATION_PAP
	u32 dwFragMinPackageLen;                           ///<��С��Ƭ�������ֽ�Ϊ��λ����Χ20~1500��Ĭ����20
	s8   achServerUsrName[KMTAPI_E1_USRNAME_LEN+1];    ///<������û����ƣ�������֤�Զ˵�����
	s8   achServerUsrPwd[KMTAPI_E1_USRPSW_LEN+1];      ///<������û����룬������֤�Զ˵�����
	s8   achClientUsrName[KMTAPI_E1_USRNAME_LEN+1];    ///<�ͻ����û����ƣ��������Զ���֤
	s8   achClientUsrPwd[KMTAPI_E1_USRPSW_LEN+1];      ///<�ͻ����û����룬�������Զ���֤
	TE1Unit_Api atE1UnitList[KMTAPI_E1_MAX_UNIT_NUM];  ///<ÿ���������serialͬ���ӿ���·����
public:
	tagTE1Group_Api() {memset(this, 0, sizeof(tagTE1Group_Api));}
}*PTE1Group_Api, TE1Group_Api;

/** E1������Ϣ*/
typedef struct tagTE1Cfg_Api
{
	BOOL32 bEncrypt; ///< �Ƿ����
	u32 dwClockType; ///< ʱ������

	u32 dwGroupCount;
	TE1Group_Api atE1GroupList[KMTAPI_E1_MAX_GROUP_NUM];///< ���з�����Ϣ
public:
	tagTE1Cfg_Api() {memset( this, 0, sizeof(tagTE1Cfg_Api) );}
}*PTE1Cfg_Api, TE1Cfg_Api;


typedef struct tagTMTGetPubTemplateList_Api
{
	u32 dwStart;  ///<  ����ģ��Ŀ�ʼ�У�Ĭ��Ϊ0�����ӷ��������������еĵڼ���ȡ���ݣ�0Ϊ��һ������
	u32 dwCount;  ///<  ��ȡ�Ĺ���ģ������Ĭ��Ϊ10�����ڰ���start���ڵĺ�count�����ݣ��������Ϊ0��ʾ��ȡ���й���ģ��
	u32 dwOrder;  ///<  ���ݹ���ģ��Ĵ���ʱ������0��������1������Ĭ��Ϊ0
public:
	tagTMTGetPubTemplateList_Api(){memset(this, 0, sizeof(tagTMTGetPubTemplateList_Api));}
}*PTMTGetPubTemplateList_Api, TMTGetPubTemplateList_Api;

typedef struct tagTMTPubTemplateSimpleInfo_Api
{
	s8 achTemplateKey[KMTAPI_BUF_128_LEN+1];           ///<  ����ģ��Ψһ��ʶ-E164��
	s8 achName[KMTAPI_BUF_128_LEN+1];                  ///<  ����ģ������
	u32 dwDuration;                                    ///<  ����ʱ��
	u32 dwBitrate;                                     ///<  ��������
	EmMtResolution_Api		emResolution;		       ///<  ����ֱ���
public:
	tagTMTPubTemplateSimpleInfo_Api(){memset(this, 0, sizeof(tagTMTPubTemplateSimpleInfo_Api));}
}*PTMTPubTemplateSimpleInfo_Api, TMTPubTemplateSimpleInfo_Api;

typedef struct tagTMTPubTemplateList_Api
{
	u32 dwCount;	
	TMTPubTemplateSimpleInfo_Api atPubTemplateSimpleInfo[KMTAPI_COUNT_16];
public:
	tagTMTPubTemplateList_Api(){memset( this, 0, sizeof(tagTMTPubTemplateList_Api) );}
}*PTMTPubTemplateList_Api, TMTPubTemplateList_Api;

typedef struct tagTMTPubTemplateInfo_Api
{
	s8 achTemplateKey[KMTAPI_BUF_128_LEN+1];       ///<  ����ģ��Ψһ��ʶ-E164��
	s8 achName[KMTAPI_BUF_128_LEN+1];              ///<  ����ģ������
	u32 dwDuration;                                ///<  ����ʱ��
	u32 dwBitrate;                                 ///<  ��������
	EmMtOpenMode_Api emMeetingSafe;                ///< ���鰲ȫ
	s8	achPassword[ KMTAPI_BUF_32_LEN+1 ];        ///< ��������
	EmEncryptArithmetic_Api emEncryptedType;       ///< �����������
	s8	achEncryptedKey[ KMTAPI_BUF_32_LEN+1 ];    ///< �������Key
	EmMeetingSafeType_Api emMeetingType;           ///< ��������
	TMTCreateConfSatellite_Api				tSatellite;    ///< ���ǻ�������
	BOOL32 bPublicMeeting;                                 ///< �Ƿ񹫹������ң�1�ǣ�0��
	EmMtMixType_Api emMixMode;                             ///< ����ģʽ

	u32						dwVideoCount;
	TMTVideoFormatList_Api atVideoFormatList[KMTAPI_COUNT_16]; ///<����Ƶ��ʽ�б�

	u32						dwAudioCount;
	TMTAudioFormatList_Api atAudioFormatList[KMTAPI_COUNT_16]; ///<��Ƶ��ʽ��ʽ�б�

	u32 dwCallTimes;     ///< ���д���
	u32 dwCallInterval;  ///< ���м��(��)
	BOOL32 bInitMute;    ///< ��ʼ��������1�ǣ�0��
	EmVideoQuality_Api emVideoQuality;     ///< ��Ƶ����,0���������ȣ�1���ٶ�����
	EmMtDualMode_Api emDualMode;           ///< ˫��Ȩ�ޡ�0�����Ի᳡��1������᳡;
	BOOL32 bVoiceInspireEnable;            ///< �Ƿ������Լ�����1�ǣ�0��
    u32 dwVoiceInspireTime;                    ///< ���Լ������ж�
	EmRestCascadeMode_Api emCascadeMode;   ///< ����ģʽ,0�򵥼�����1�ϲ�����
	BOOL32 bCascadeUpload;                 ///< �Ƿ����ϴ�:1�ǣ�0��
	BOOL32 bCascadeReturn;                 ///< �Ƿ����ش�:1�ǣ�0��
	u32 dwCascadeReturnPara;               ///< �����ش��������
    u32 dwMeetingScale;                        ///< �����ģ,0���գ�1��4����Ƶ����,2��8����Ƶ����,3��������Ƶ����
    BOOL32 bOneReforming;                 ///< ��һ����,0:�ر�; 1:����
	TMTCreateRecordRecord_Api tRecord;     ///< ¼������
	TMTCreateConfMultiCast_Api tMultiCast; ///< ��������

	u32 dwDualCount;
	TMTDualFormatList_Api atDualFormatList[KMTAPI_COUNT_8];///<˫����ʽ�б�

	EmClosedMeeting_Api emClosedMeeting;                   ///< ��������ţ�1������0�ر�
public:
	tagTMTPubTemplateInfo_Api(){memset( this, 0, sizeof(tagTMTPubTemplateInfo_Api) );}
}*PTMTPubTemplateInfo_Api, TMTPubTemplateInfo_Api;

typedef struct tagTMTPubTemplate_Api
{
	s8 achName[KMTAPI_BUF_128_LEN+1];        ///<  ����ģ������
	EmMeetingSafeType_Api emMeetingType;     ///< ��������
	u32 dwBitrate;                           ///< ��������
	EmMtResolution_Api emResolution;         ///< �ֱ���
	EmMtOpenMode_Api emMeetingSafe;          ///< ���鰲ȫ
	EmEncryptArithmetic_Api emEncryptedType; ///< �����������
	s8	achEncryptedKey[ KMTAPI_BUF_32_LEN+1 ];   ///< �������Key
	EmMtDualMode_Api emDualMode;                  ///< ˫��Ȩ��
	u32 dwDuration;                               ///< ʱ�������ӣ�
	EmMtMixType_Api emMixMode;                    ///< ����ģʽ
	TMTCreateConfSatellite_Api tSatellite;        ///<  ���ǻ�������
	BOOL32 bPublicMeeting;                        ///< �Ƿ񹫹������ң�1�ǣ�0��

	u32 dwVideoCount;
	TMTVideoFormatList_Api atVideoFormatList[KMTAPI_COUNT_16]; ///<����Ƶ��ʽ�б�

	u32 dwAudioCount;
	TMTAudioFormatList_Api atAudioFormatList[KMTAPI_COUNT_16]; ///<��Ƶ��ʽ��ʽ�б�

	u32 dwDualCount;
	TMTDualFormatList_Api atDualFormatList[KMTAPI_COUNT_8];

	EmClosedMeeting_Api emClosedMeeting;        ///< ��������ţ�1������0�ر�
	BOOL32						bEncryptedAuth;                         ///< �Ƿ�˫����֤ 0-�ر� 1-����
public:
	tagTMTPubTemplate_Api(){memset( this, 0, sizeof(tagTMTPubTemplate_Api) );}
}*PTMTPubTemplate_Api, TMTPubTemplate_Api;

typedef struct tagTMTCpuAndMemState_Api
{
	u32 dwCpuIdlePercent;///< CPU���аٷֱȣ�0��100
	u32 dwMemTotalSize;  ///< �����ڴ��С(KByte)
	u32 dwMemAllocSize;  ///< ��ʹ���ڴ�(KBytes)
	u32 dwMemFreeSize;   ///< �����ڴ�(KBytes)
public:
	tagTMTCpuAndMemState_Api(){memset( this, 0, sizeof(tagTMTCpuAndMemState_Api) );}
}*PTMTCpuAndMemState_Api, TMTCpuAndMemState_Api;

/** ̨�����������������Ϣ���� */
typedef struct tagTMtTranspDColor_Api
{
	u32 dwRColor;          ///<R����
	u32 dwGColor;          ///<G����
	u32 dwBColor;          ///<B����	
	u32 dwTransparency;    ///<͸����(0��ʾȫ͸����255��ʾ��͸����1~254��ʾ����͸��)
public:
	tagTMtTranspDColor_Api() { memset( this, 0, sizeof(tagTMtTranspDColor_Api) ); }
}*PTMtTranspDColor_Api, TMtTranspDColor_Api;

typedef struct tagTMtAddLogoParam_Api
{
	float fXPosRate;		    ///<��ȱ�����xpos = ��ͼ��*fXPosRate
	float fYPosRate;		    ///<�߶ȱ�����ypos = ��ͼ��*fYPosRate
	u32 dwLogobgWidth;	        ///<�ο���ͼ�Ŀ�
	u32 dwLogobgHeight;	        ///<�ο���ͼ�ĸ�	
	TMtTranspDColor_Api tBackBGDColor;    
public:
	tagTMtAddLogoParam_Api() { memset( this, 0, sizeof(tagTMtAddLogoParam_Api) ); }
}*PTMtAddLogoParam_Api, TMtAddLogoParam_Api;

typedef struct tagTMtFullLogoParam_Api
{
	s8  achBmpPath[KMTAPI_MAX_PATH_FILE_NAME_LEN+1];	///<ͼƬ�ļ���ַ
	TMtAddLogoParam_Api tLogoParam;
public:
	tagTMtFullLogoParam_Api() { memset( this, 0, sizeof(tagTMtFullLogoParam_Api) ); }
}*PTMtFullLogoParam_Api, TMtFullLogoParam_Api;

typedef struct tagTMtFullLogoParamList_Api
{
	TMtFullLogoParam_Api atLogoParamList[KMTAPI_MAX_CONF_MT_MEMBER_NUM];
	u32 dwCount;
public:
	tagTMtFullLogoParamList_Api() { memset( this, 0, sizeof(tagTMtFullLogoParamList_Api) ); }
}*PTMtFullLogoParamList_Api, TMtFullLogoParamList_Api;


typedef struct tagTMTCameraPresetPicList_Api
{
	s8 aachPresetPicName[KMTAPI_COUNT_128][KMTAPI_BUF_64_LEN + 1]; ///<Ԥ��λͼƬ����
	u32 dwPresetPicCnt;///<Ԥ��λͼƬ����
public:
	tagTMTCameraPresetPicList_Api() { memset( this, 0, sizeof(tagTMTCameraPresetPicList_Api) ); }
}*PTMTCameraPresetPicList_Api, TMTCameraPresetPicList_Api;


/** cometd��Ϣ��ʽ */
typedef struct tagTMTCometdMessage_Api
{
	EmRestMeetingNotifyType_Api emNotifyType; ///<��Ϣ����
	u32 dwNotifyId;                                              ///<֪ͨid
	u32 dwNum;                                                   ///<��Ϣ����
public:
	tagTMTCometdMessage_Api() { memset( this, 0, sizeof(tagTMTCometdMessage_Api) ); }
}*PTMTCometdMessage_Api, TMTCometdMessage_Api;

/** cometd��Ϣ�б� */
typedef struct tagTMTCometdMessageList_Api
{
	TMTCometdMessage_Api atCometdMessageList[KMTAPI_COUNT_32]; ///<��Ϣ�б�
	u32 dwListNum;											  ///<�б����
public:
	tagTMTCometdMessageList_Api() { memset( this, 0, sizeof(tagTMTCometdMessageList_Api) ); }
}*PTMTCometdMessageList_Api, TMTCometdMessageList_Api;

/** Sip���� */
typedef struct tagTMtSipCfg_Api
{ 
	BOOL32 bEnableBfcp;
public:
	tagTMtSipCfg_Api() { memset( this, 0, sizeof(struct tagTMtSipCfg_Api) ); }
}*PTMtSipCfg_Api, TMtSipCfg_Api;

/** �ն��豸���� */
typedef struct tagTMtPFMInfo_Api
{ 
	u32 dwCpuUseRate;        ///<cpuʹ�ðٷֱ�
	u32 dwDiskUseRate;       ///<Ӳ��ʹ�ðٷֱ�
	u32 dwMemUseRate;        ///<�ڴ�ʹ�ðٷֱ�
public:
	tagTMtPFMInfo_Api() { memset( this, 0, sizeof(struct tagTMtPFMInfo_Api) ); }
}*PTMtPFMInfo_Api, TMtPFMInfo_Api;

typedef struct tagTMtVidSrcInfo_Api
{
	EmCodecComponent_Api emCodecType;	///<��Ƶ�ɼ�����
	EmCodecComponentIndex_Api emCodecId;	///< ��Ƶ�ɼ���� 
	u32 dwVideoWidth;	///< ��Ƶ������Ϊ��λ,Ϊ0��ʾ���ź� 
	u32 dwVideoHeight;	///< ��Ƶ�ߣ���Ϊ��λ,Ϊ0��ʾ���ź�
	BOOL32 bVideoProgressive;	///< ���л���У�TRUE=���У�FALSE=����
	u32 dwFrameRate;	///< ֡�ʣ�����ʱ=��Ƶ������ʱ=��Ƶ/2����60i=30P,Ϊ0��ʾ���ź�
public:
	tagTMtVidSrcInfo_Api() { memset( this, 0, sizeof(tagTMtVidSrcInfo_Api) ); }
}*PTMtVidSrcInfo_Api, TMtVidSrcInfo_Api;

typedef struct tagTMtVidSrcInfoList_Api
{
	u8 byCnt;
	TMtVidSrcInfo_Api atInfoList[KMTAPI_VIDSRC_MAX_NUM]; ///<��ƵԴ��Ϣ
public:
	tagTMtVidSrcInfoList_Api() { memset( this, 0, sizeof(tagTMtVidSrcInfoList_Api) ); }
}*PTMtVidSrcInfoList_Api, TMtVidSrcInfoList_Api;

typedef struct tagUpgradeFileInfo_Api
{
	BOOL32 bIsFound; ///<�Ƿ��ҵ�������
	s8 achFilePath[KMTAPI_BUF_128_LEN+1]; ///<������·��
public:
	tagUpgradeFileInfo_Api() { memset( this, 0, sizeof(tagUpgradeFileInfo_Api) ); }
}UpgradeFileInfo_Api, *PUpgradeFileInfo_Api;

/** U����Ϣ */
typedef struct tagTMTUsbPartition_Api
{
	s8 achPath[KMTAPI_BUF_32_LEN+1];           ///<�������ص�·��
	s8 achName[KMTAPI_BUF_32_LEN+1];           ///<����������
	u32 dwTotalSpace;         ///<�����ܴ�СKB
	u32 dwAvailableSpace;     ///<����ʣ��ռ�KB
}*PTMTUsbPartition_Api, TMTUsbPartition_Api;

typedef struct tagTMTUsbInfo_Api
{
	u32 dwUsbId; ///<ID
	BOOL32 bIsUsed; ///<�Ƿ���U�̲���
	u8 byCnt;
	TMTUsbPartition_Api atPartition[KMTAPI_USB_PARTITION_MAX_NUM]; ///<U�̹��ظ�Ŀ¼
public:
	tagTMTUsbInfo_Api() { memset( this, 0, sizeof(tagTMTUsbInfo_Api) ); }
}*PTMTUsbInfo_Api, TMTUsbInfo_Api;

typedef struct tagTMTUsbStatus_Api
{
	u8 byCnt;
	TMTUsbInfo_Api atUsbInfo[KMTAPI_USB_INTERFACE_MAX_NUM];
public:
	tagTMTUsbStatus_Api() { memset( this, 0, sizeof(tagTMTUsbStatus_Api) ); }
}*PTMTUsbStatus_Api, TMTUsbStatus_Api;

typedef struct tagTMTPathStructureUnit_Api
{
	EmSystemFileType_Api emFileType; ///<�Ƿ�Ϊ�ļ���
	s8 achFilePath[KMTAPI_BUF_128_LEN+1];
public:
	tagTMTPathStructureUnit_Api() { memset( this, 0, sizeof(tagTMTPathStructureUnit_Api) ); }
}*PTMTPathStructureUnit_Api, TMTPathStructureUnit_Api;

typedef struct tagTMTPathStructureDetail_Api
{
	u32 dwCnt;
	TMTPathStructureUnit_Api atPathUint[KMTAPI_COUNT_512];
public:
	tagTMTPathStructureDetail_Api() { memset( this, 0, sizeof(tagTMTPathStructureDetail_Api) ); }
}*PTMTPathStructureDetail_Api, TMTPathStructureDetail_Api;

typedef struct tagTMtVidInPortResInfo_Api
{
	EmMtVideoPort_Api emVideoPort; ///<��ƵԴ�˿�
	u32                           dwVideoWidth; ///<��Ƶ������Ϊ��λ,Ϊ0��ʾ���ź�
	u32                           dwVideoHeight; ///<��Ƶ�ߣ���Ϊ��λ,Ϊ0��ʾ���ź�
	BOOL32                    bVideoProgressive; ///<���л���У�TRUE=���У�FALSE=����
	u32                           dwFrameRate; ///<֡�ʣ�����ʱ=��Ƶ������ʱ=��Ƶ/2����60i=30P,Ϊ0��ʾ���ź�
public:
	tagTMtVidInPortResInfo_Api() { memset( this, 0, sizeof(tagTMtVidInPortResInfo_Api) ); }
}*PTMtVidInPortResInfo_Api, TMtVidInPortResInfo_Api;

typedef struct tagTMtVidInPortResInfoList_Api
{
	u32 dwCount;
	TMtVidInPortResInfo_Api atVidInPortStatus[KMTAPI_COUNT_32]; ///<��ƵԴ��Ϣ
public:
	tagTMtVidInPortResInfoList_Api() { memset( this, 0, sizeof(tagTMtVidInPortResInfoList_Api) ); }
}*PTMtVidInPortResInfoList_Api, TMtVidInPortResInfoList_Api;


typedef struct tagTMTResizeMode_Api
{
	EmResizeMode_Api emResizeMode; ///<����������
public:
	tagTMTResizeMode_Api() { memset( this, 0, sizeof(tagTMTResizeMode_Api) ); }
}*PTMTResizeMode_Api, TMTResizeMode_Api;


/** ��������� */

typedef struct tagTVidDes_Api
{
	EmMtResolution_Api  emRes;         ///<�ֱ���
	u32                 dwMpi;         ///<֡�� ����� ��ʽ��264,265�� ����ȥ����ʵ�ʵ�fps�� ���򣬴���ȥ���� 30���� ʵ�ʵ�֡��
	u32                 dwMax_BitRate; ///<֧���������
public:
	tagTVidDes_Api() { memset( this, 0, sizeof(tagTVidDes_Api) ); }
}*PTVidDes_Api, TVidDes_Api;

typedef struct tagTVidFormatCap_Api
{
	EmVidFormat_Api             emFormat;
	TVidDes_Api                 atItem[KMTAPI_COUNT_16];
	u32 dwItemCount;
	EmH264Profile_Api           emH264Profile; ///<264 profile
	EmH264AdditionalModes_Api   emH264Modes;   ///<264 svc mode
	EmH265Profile_Api           emH265Profile; ///<265 profile

public:
	tagTVidFormatCap_Api() { memset( this, 0, sizeof(tagTVidFormatCap_Api) ); }
}*PTVidFormatCap_Api, TVidFormatCap_Api;

/** һ·��Ƶͨ�������� */
typedef struct tagTVidCapList_Api         
{	
	TVidFormatCap_Api atVidList[KMTAPI_COUNT_16];
	u32 dwCount;
	EmMtVidLabel_Api   emVidLab;  ///<��ʱֻ��Է��͸�������������video������pc����

public:
	tagTVidCapList_Api() { memset( this, 0, sizeof(tagTVidCapList_Api) ); }

}*PTVidCapList_Api, TVidCapList_Api;


typedef struct tagTAudDes_Api
{
	EmAudFormat_Api   emFormat;
	u32               dwPack_time;  
	EmAacChnlNum_Api  emChnl_num;      ///<ֻ���lc, ld
public:
	tagTAudDes_Api() 
	{ 
		memset( this, 0, sizeof(tagTAudDes_Api) );
		dwPack_time = 30;
		emChnl_num = emCnNumCust_Api;
	}
}*PTAudDes_Api, TAudDes_Api;

/** һ·��Ƶͨ�������� */
typedef struct tagTAudCapList_Api         
{	
	TAudDes_Api atAudList[KMTAPI_COUNT_16];
	u32 dwCount;
public:
	tagTAudCapList_Api() { memset( this, 0, sizeof(tagTAudCapList_Api) ); }

}*PTAudCapList_Api, TAudCapList_Api;

typedef struct tagTMtSendCap_Api
{
	TAudCapList_Api  atMain_aud_send_cap[KMTAPI_MAX_CONF_AUD_CHANNEL_NUM];     ///<��·��������
	TVidCapList_Api  atMain_vid_send_cap[KMTAPI_MAX_CONF_VID_CHANNEL_NUM];     
	TAudCapList_Api  atAss_aud_send_cap[KMTAPI_MAX_CONF_ASSAUD_CHANNEL_NUM];
	TVidCapList_Api  atAss_vid_send_cap[KMTAPI_MAX_CONF_ASSVID_CHANNEL_NUM];
	u32 dwMainAudSndCount;
	u32 dwMainVidSndCount;
	u32 dwAssAudSndCount;
	u32 dwAssVidSndCount;

public:
	tagTMtSendCap_Api() { memset( this, 0, sizeof(tagTMtSendCap_Api) ); }
}*PTMtSendCap_Api, TMtSendCap_Api;


typedef struct tagTMtRecvCap_Api
{
	TAudCapList_Api  atMain_aud_recv_cap[KMTAPI_MAX_CONF_AUD_CHANNEL_NUM];     ///<��·��������
	TVidCapList_Api  atMain_vid_recv_cap[KMTAPI_MAX_CONF_VID_CHANNEL_NUM];     
	TAudCapList_Api  atAss_aud_recv_cap[KMTAPI_MAX_CONF_ASSAUD_CHANNEL_NUM];
	TVidCapList_Api  atAss_vid_recv_cap[KMTAPI_MAX_CONF_ASSVID_CHANNEL_NUM];
	u32 dwMainAudRcvCount;
	u32 dwMainVidRcvCount;
	u32 dwAssAudRcvCount;
	u32 dwAssVidRcvCount;

public:
	tagTMtRecvCap_Api() { memset( this, 0, sizeof(tagTMtRecvCap_Api) ); }

}*PTMtRecvCap_Api, TMtRecvCap_Api;


typedef struct tagTCloudRecordState
{
	BOOL32             bCloudRecord;
	TMTTime_Api        tStartRecordTime;    ///<  ��ʼ¼��ʱ�䣬 �Ǹ�����ʱ��

public:
	tagTCloudRecordState() { memset( this, 0, sizeof(tagTCloudRecordState) ); }

}*PTCloudRecordState_Api, TCloudRecordState_Api;

/** ���ٺ�����Ϣ*/
typedef struct tagTFastCall_Api
{
	u32 dwCallRate;			                                                  ///< ��������(kbps)
	EmMtAddrType_Api   emCallType;	                                 ///< ���з�ʽ(ip, e164, alias)
	u32 dwPeerAddr;			                                                ///< �Զ�IP��ַ(������)
	s8 achPeerE164[KMTAPI_MAX_MT_E164_LEN+1];			///< �Զ�E164��
	s8 achPeerAlias[KMTAPI_MAX_MT_ALIAS_LEN+1];		    ///< �Զ˱���
public:
	tagTFastCall_Api() {memset(this, 0, sizeof(tagTFastCall_Api));}
}*PTFastCall_Api, TFastCall_Api;

/** ���ٺ�������*/
typedef struct tagTFastCallList_Api
{
	u32 dwListCnt;                                                                      ///< ���ٺ��������б�
	TFastCall_Api atFastCallList[KMTAPI_FAST_CALL_LIST_CNT];		///< ���ٺ��������б�
public:
	tagTFastCallList_Api() {memset(this, 0, sizeof(tagTFastCallList_Api));}
}*PTFastCallList_Api, TFastCallList_Api;

/** Ev_MtApi_Diagnose_FileExistCheck_Rsp��Ϣ�� */
typedef struct tagTFileCheckRspBody_Api
{
	BOOL32 bExist;
	u32 dwFileSize;
	s8 achFullPathName[KMTAPI_BUF_256_LEN+1];
public:
	tagTFileCheckRspBody_Api() {memset(this, 0, sizeof(tagTFileCheckRspBody_Api));}
}*PTFileCheckRspBody_Api, TFileCheckRspBody_Api;

/** FTP/TELNET ��¼��Ϣ*/
typedef struct tagTMTFtpTelnetAccountInfo_Api
{
	s8 achUserName[KMTAPI_BUF_32_LEN+1];    ///< �û���
	s8 achPassword[KMTAPI_BUF_32_LEN+1];     ///< ����
public:
	tagTMTFtpTelnetAccountInfo_Api() { memset(this, 0, sizeof(tagTMTFtpTelnetAccountInfo_Api) ); }
}*PTMTFtpTelnetAccountInfo_Api, TMTFtpTelnetAccountInfo_Api;

/** �������״̬��Ϣ*/
typedef struct tagTMTMicStatus_Api
{
	u32 dwMicId;   ///< ���id���ο�EmMicDevId_Api
	u32 dwStatus;  ///< ״̬
public:
	tagTMTMicStatus_Api() { memset(this, 0, sizeof(tagTMTMicStatus_Api) ); }
}*PTMTMicStatus_Api, TMTMicStatus_Api;

/** ȫ�������״̬��Ϣ*/
typedef struct tagTMTAllMicStatus_Api
{
	TMTMicStatus_Api atMicStatus[KMTAPI_COUNT_16];
	u32 dwCnt;
public:
	tagTMTAllMicStatus_Api() { memset(this, 0, sizeof(tagTMTAllMicStatus_Api) ); }
}*PTMTAllMicStatus_Api, TMTAllMicStatus_Api;

typedef struct tagMtcBaseInfo_Api
{
	s8                      achIp[KMTAPI_BUF_32_LEN+1];			//mtc��ip
	EmClientAppType_Api     emAppType;							//�ͻ�������
	EmAuthType_Api          emAuthType;							//��֤��ʽ
	s8                      achUserName[KMTAPI_BUF_32_LEN+1];	//�û���

	tagMtcBaseInfo_Api()
	{
		achIp[0]=0;
		emAppType = emClientAppMTCEnd_Api;
		emAuthType = emAuthEnd_Api;
		achUserName[0]=0;
	}

}*PTMtcBaseInfo_Api, TMtcBaseInfo_Api;

/**  �ն˵�¼�������Ϣ��ṹ*/
typedef struct tagTMTLoginMtResult_Api
{
	BOOL32             bLogin;                                                    ///< ��¼���(TRUE:�ɹ� FALSE:ʧ��)
	TMtcBaseInfo_Api   tLoginParam;                                               ///< ��¼��
	BOOL32             bKickOther;                                                ///< �Ƿ���ռ������
	TMtcBaseInfo_Api   tKickee;                                                   ///< ����ռ�˵Ļ�����Ϣ

	BOOL32             bNameExist;                                                ///< ��½���Ƿ����
	u32                dwLoginErrCnt;                                             ///< ��½ʧ�ܴ���
	u32                dwLoginTime;                                               ///< ���������ʧ���Ѿ����˶೤ʱ��

	u32				   dwMaxLoginCnt;											  ///< ����¼����,������������ͱ�����һ����ʱ��
	u32				   dwMaxLockTime;											  ///< �������ʱ��
	
	EmMtcLoginFailReason_Api emFailReason;										  ///< �����¼�ɹ�����������ԭ��
public:
	tagTMTLoginMtResult_Api() { memset(this, 0, sizeof(tagTMTLoginMtResult_Api)); }
}*PTMTLoginMtResult_Api, TMTLoginMtResult_Api;

/**  �ն���Ƶ�����״̬*/
typedef struct tagTMTRfMatchState_Api
{
	EmMicDevId_Api emMicId;     ///< ���ID
	BOOL32              bMatched;   ///< �Ƿ������
	u32                     dwMatchId; ///< ���ID
public:
	tagTMTRfMatchState_Api() { memset(this, 0, sizeof(tagTMTRfMatchState_Api)); }
}*PTMTRfMatchState_Api, TMTRfMatchState_Api;

/**  �ն���Ƶ�����״̬�б�*/
typedef struct tagTMTRfMatchStateList_Api
{
	u32 dwCnt;
	TMTRfMatchState_Api atStateList[KMTAPI_COUNT_16];
public:
	tagTMTRfMatchStateList_Api() { memset(this, 0, sizeof(tagTMTRfMatchStateList_Api)); }
}*PTMTRfMatchStateList_Api, TMTRfMatchStateList_Api;

/** ץ���ļ���Ϣ*/
typedef struct tagTNetCapFileInfo_Api
{
	s8    achFileName[KMTAPI_BUF_64_LEN+1]; ///< �ļ���
	u32 dwFileSize;                                               ///< �ļ���С
public:
	tagTNetCapFileInfo_Api() { memset(this, 0, sizeof(tagTNetCapFileInfo_Api));}
}*PTNetCapFileInfo_Api, TNetCapFileInfo_Api;

/** ץ���ļ���Ϣ�б�*/
typedef struct tagTNetCapFileList_Api
{
	s8                               achFilePath[KMTAPI_BUF_64_LEN+1]; ///< �ļ�·��
	u8                               byFileCnt;                                              ///< �ļ�����
	TNetCapFileInfo_Api atFileList[KMTAPI_COUNT_8];              ///< �ļ��б�
public:
	tagTNetCapFileList_Api() { memset(this, 0, sizeof(tagTNetCapFileList_Api)); }
}*PTNetCapFileList_Api, TNetCapFileList_Api;

/** ��˰汾��Ϣ*/
typedef struct tagTMicVersionInfo_Api
{
	u32 dwMicId;                                                 ///< ���id���ο�EmMicDevId_Api
	s8    achVersion[KMTAPI_BUF_256_LEN+1]; ///< �汾��
public:
	tagTMicVersionInfo_Api() { memset(this, 0, sizeof(tagTMicVersionInfo_Api)); }
}*PTMicVersionInfo_Api, TMicVersionInfo_Api;

/** ��˰汾��Ϣ�б�*/
typedef struct tagTMicVersionList_Api
{
	u8 byCnt;                                                                              ///< �б����
	TMicVersionInfo_Api atVersionList[KMTAPI_COUNT_16]; ///< �汾��Ϣ�б�
public:
	tagTMicVersionList_Api() { memset(this, 0, sizeof(tagTMicVersionList_Api)); }
}*PTMicVersionList_Api, TMicVersionList_Api;

/** ��¼���������Ӳ��Խ��*/
typedef struct tagTServerTestResult_Api
{
	u32         dwUserId;      ///< �ο�EmPingUserId_Api
	BOOL32 bResult;         ///< ���Խ��
public:
	tagTServerTestResult_Api() { memset(this, 0, sizeof(tagTServerTestResult_Api)); }
}*PTServerTestResult_Api, TServerTestResult_Api;

/** ��˷�����״̬*/
typedef struct tagTMicUpgradeState_Api
{
    u32 dwMicId;      ///< ���id(�ο�EmMicDevId_Api)
    u32 dwState;       ///< ״̬(�ο�EmMicUpgradeState_Api)
    u32 dwProgress; ///< ����(dwStateΪemUploading_Apiʱ��Ч)
public:
    tagTMicUpgradeState_Api() { memset(this, 0, sizeof(tagTMicUpgradeState_Api)); }
}*PTMicUpgradeState_Api, TMicUpgradeState_Api;

/** ��˷�����״̬�б�*/
typedef struct tagTMicUpgradeStateList_Api
{
    u8 dwCnt;                                                                          ///< ����
    TMicUpgradeState_Api atStateList[KMTAPI_COUNT_8]; ///< ״̬�б�
public:
    tagTMicUpgradeStateList_Api() { memset(this, 0, sizeof(tagTMicUpgradeStateList_Api)); }
}*PTMicUpgradeStateList_Api, TMicUpgradeStateList_Api;

/** ��˷簲װ״̬*/
typedef struct tagTMicInstall_Api
{
    u32 dwMicId; ///< ���id(�ο�EmMicDevId_Api)
    u32 dwState; ///< �Ƿ�װ(0:����װ 1:��װ)
public:
    tagTMicInstall_Api() { memset(this, 0, sizeof(tagTMicInstall_Api)); }
}*PTMicInstall_Api, TMicInstall_Api;

/** ��˷簲װ״̬�б�*/
typedef struct tagTMicInstallList_Api
{
    u32 dwCnt;                                                             ///< ����
    TMicInstall_Api atInstallList[KMTAPI_COUNT_8]; ///< ��װ�б�
public:
    tagTMicInstallList_Api() { memset(this, 0, sizeof(tagTMicInstallList_Api)); }
}*PTMicInstallList_Api, TMicInstallList_Api;

/** �Ƿ�ǿ������H323Э��ջΪ�Ǳ�/��׼*/
typedef struct tagTForceSetH323Stack_Api
{
	BOOL32 bEnable;         ///< �Ƿ�ǿ������
	BOOL32 bStand;          ///< TRUE:��׼ FALSE:�Ǳ�
public:
	tagTForceSetH323Stack_Api() { memset(this, 0, sizeof(tagTForceSetH323Stack_Api)); }
}*PTForceSetH323Stack_Api, TForceSetH323Stack_Api;

/** ��Ƶ�����ǩ */
typedef struct tagTMTVideoOutTag_Api
{
	EmHDVideoOutPortType_Api emVideoPortId;
	s8 achVideoPortTag[KMTAPI_BUF_128_LEN+1];
public:
	tagTMTVideoOutTag_Api() { memset( this, 0, sizeof(*this)); }
}*PTMTVideoOutTag_Api, TMTVideoOutTag_Api;

typedef struct tagTMTVideoOutTagList_Api
{
	u8 byCnt;
	TMTVideoOutTag_Api atVidOutTag[KMTAPI_MAX_VIDEO_OUT_NUM];
public:
	tagTMTVideoOutTagList_Api() { memset( this, 0, sizeof(*this)); }
}*PTMTVideoOutTagList_Api, TMTVideoOutTagList_Api;

typedef struct tagTMTFpgaVersionList_Api
{
	u8 byCnt;
	u32 atFpgaVersion[KMTAPI_MAX_VIDEO_OUT_NUM];
public:
	tagTMTFpgaVersionList_Api() { memset( this, 0, sizeof(*this)); }
}*PTMTFpgaVersionList_Api, TMTFpgaVersionList_Api;

typedef struct tagTMTEndPointInfo_Api
{
	s8	achId[KMTAPI_BUF_32_LEN+1];		//�ն˵�id, ��ǰ��֧��e164��
	u32 dwIdLen;						//�ն�id�ĳ���
	u32 dwStreamId;						//��id
public:
	tagTMTEndPointInfo_Api() { memset( this, 0, sizeof(*this) ); }
}*PTMTEndPointInfo_Api, TMTEndPointInfo_Api;

typedef struct tagTMTNatTraversalInfo_Api
{
	BOOL32		  bEnable;		//�Ƿ�����nat��Խ
	TNetParam_Api tNetParam;	//��ַ��Ϣ
public:
	tagTMTNatTraversalInfo_Api() { memset( this, 0, sizeof(*this) ); }
}*PTMTNatTraversalInfo_Api, TMTNatTraversalInfo_Api;

/** vrsԤԼֱ�����б�������Ϣ */ 
typedef struct tagTVodGetResRoomReq_Api
{
	u32	dwNums1Page;		                       ///< ÿ��ҳ����ʾ������Ŀ
	u32	dwPageId;			                   ///< ���������һҳ
	s8  achIncludeName[KMTAPI_BUF_128_LEN+1];  ///< �����ļ���
public:
	tagTVodGetResRoomReq_Api(){ memset ( this ,0 ,sizeof( struct tagTVodGetResRoomReq_Api ) );}
}*PTVodGetResRoomReq_Api, TVodGetResRoomReq_Api;

/** ԤԼֱ������Ϣ */ 
typedef struct tagTVodResRoomDetail_Api
{
	s8 achConfName[KMTAPI_BUF_128_LEN+1];                     ///< ��Ŀ����
	s8 achStartTime[KMTAPI_BUF_128_LEN+1];                    ///< ԤԼ����ʱ��
public:
	tagTVodResRoomDetail_Api(){ memset ( this ,0 ,sizeof( struct tagTVodResRoomDetail_Api ) );}
}*PTVodResRoomDetail_Api, TVodResRoomDetail_Api;

/** ԤԼֱ������Ϣ�б� */ 
typedef struct tagTVodResRoomsDetail_Api
{
	TVodResRoomDetail_Api atRoomDetail[KMTAPI_MAX_DIRECTBROADCAST_CNT]; ///< �б���Ϣ
	u32 dwCnt;      ///< �б����
                                                                                        
public:
	tagTVodResRoomsDetail_Api()
	{
		dwCnt = 0;
	}
}*PTVodResRoomsDetail_Api, TVodResRoomsDetail_Api;

/**  ��Ƶ������� */
typedef struct tagTAudEncParam_Api
{
	EmAudFormat_Api   emAudFormat;
	EmAacChnlNum_Api  emAacChnlNum;		//���ֶ�aud_format����emAMpegAACLC��emAMpegAACLDʱ����Ч
	EmAacSampFreq_Api emAacSampFreq;    //���ֶ�aud_format����emAMpegAACLC��emAMpegAACLDʱ����Ч
	u32				  dwAacRate;		//���ֶ�aud_format����emAMpegAACLC��emAMpegAACLDʱ����Ч
	u32				  dwG7221Rate; 	    //���ֶ�aud_format����emAG7221ʱ����Ч
public:
	tagTAudEncParam_Api(){ memset( this ,0 ,sizeof( struct  tagTAudEncParam_Api ) );}
}*PTAudEncParam_Api, TAudEncParam_Api;


/** ����Ͷ��״̬��Ϣ */
typedef struct TagTWifiWirelessScreenInfo_Api	
{
	EmWirelessScreenState_Api  	   emWirelessScreenState;       //�Ƿ���������Ͷ�� true:���� false������
	u32 					       dwWirelessScreenDeviceNum;	//����Ͷ������豸����
	EmWirelessScreenErrReason_Api  emWirelessScreenErrReason;	//����Ͷ��ʧ�ܴ�����
public:
	TagTWifiWirelessScreenInfo_Api(){ memset( this, 0, sizeof( struct TagTWifiWirelessScreenInfo_Api )); }
}*PTWifiWirelessScreenInfo_Api,TWifiWirelessScreenInfo_Api;

/** ���������ļ�����Ӧ��Ϣ */
typedef struct tagTImportMtcfgInfo_Api
{
	EmFileExImErr_Api	emImportErr;  //���������ļ��Ĵ�����
	EmMtModel_Api		emFileModel;  //�����ļ��ͺ�                                                          
	EmMtModel_Api		emMtModel;	  //�ն��ͺ�
public:
	tagTImportMtcfgInfo_Api(){ memset( this, 0, sizeof(struct tagTImportMtcfgInfo_Api) ); }
}*PTImportMtcfgInfo_Api, TImportMtcfgInfo_Api;

/**  Ӳ�ն˱���¼��״̬��������Ϣ */
typedef struct tagTMTVidRecErrInfo_Api
{
	u32							dwChanIdx;		//ͨ����
	EmVideoRecordErrorNum_Api	emErrNum;
public:
	tagTMTVidRecErrInfo_Api(){ memset( this, 0, sizeof(struct tagTMTVidRecErrInfo_Api) ); }
}*PTMTVidRecErrInfo_Api, TMTVidRecErrInfo_Api;

//�������
typedef struct tagTMtSecCertDistinctName_Api
{
	s8 achCountryName[KMTAPI_BUF_64_LEN+1];			// ���ң����й�"CN"�������裬�̶�2���ַ����Ҵ���
	s8 achStateOrProvinceName[KMTAPI_BUF_64_LEN+1];	// �ݻ�ʡ����ѡ
	s8 achLocalityName[KMTAPI_BUF_64_LEN+1];			// ���У���ѡ
	s8 achOrganizationName[KMTAPI_BUF_64_LEN+1];		// ��֯���繫˾��������
	s8 achOrganizationUnitName[KMTAPI_BUF_64_LEN+1];	// ��֯��Ԫ���粿�ţ�����ѡ
	s8 achCommonName[KMTAPI_BUF_64_LEN+1];			// ͨ��������������IP��ַ���û�����������
	s8 achSerialNumber[KMTAPI_BUF_64_LEN+1];			// �豸���к�
	s8 achEmailAddress[KMTAPI_BUF_64_LEN+1];			// Email��ַ
public:
	tagTMtSecCertDistinctName_Api(){ memset( this ,0 ,sizeof( struct tagTMtSecCertDistinctName_Api ) ); }
}*PTMtSecCertDistinctName_Api, TMtSecCertDistinctName_Api;

typedef struct tagTMtSecCertValidity_Api
{           
	s8 achNotTimeBefore[KMTAPI_BUF_256_LEN+1];	///< ��ʼʱ�䣬��ʽΪ��yymmddhhmmssZ������Z��ʾ�������α�׼ʱ��
	s8 achNotTimeAfter[KMTAPI_BUF_256_LEN+1];	///< ����ʱ�䣬��ʽΪ��yymmddhhmmssZ������Z��ʾ�������α�׼ʱ��
public:
	tagTMtSecCertValidity_Api() { memset( this, 0, sizeof(*this)); }
}*PTMtSecCertValidity_Api, TMtSecCertValidity_Api;

/** ����֤��ID */
typedef struct tagTMtSecCerId_Api
{
	u8 byLen;                               ///< ID����
	u8 abyId[KMTAPI_SEC_CAID_LEN+1];		///< ID
public:
	tagTMtSecCerId_Api(){ memset( this, 0, sizeof( struct  tagTMtSecCerId_Api ) ); }	
}*PTMtSecCerId_Api, TMtSecCerId_Api;

typedef struct tagTMtSecCertInfo_Api
{
	s32 nVersion;										   // ֤��汾��0��ʾV1��2��ʾV3
	s8 achSerialNumber[KMTAPI_BUF_256_LEN+1];              ///< ���кų��ȣ�HEX��ʽ��һ���20�ֽ�
	s8 achSignAlg[KMTAPI_BUF_256_LEN+1];                   ///< ǩ���㷨���ַ�����
	TMtSecCertDistinctName_Api   tSecCertDistinctName;     ///< ǩ������Ϣ
	TMtSecCertValidity_Api       tSecCertValidity;         ///< ��Ч��
	TMtSecCertDistinctName_Api   tSecCertUsrName;          ///< ʹ������Ϣ
	EmSecCertFormat_Api          emFormat;				   // ֤���ʽ���μ�TSecCertFormat
	s8 achPubKeyAlg[KMTAPI_BUF_32_LEN+1];			          ///< ��Կ�㷨���ַ�����
	TMtSecCerId_Api              tSecCaId;                ////ָ��id
public:
	tagTMtSecCertInfo_Api() { memset( this, 0, sizeof(*this)); }
}*PTMtSecCertInfo_Api, TMtSecCertInfo_Api;

/* ���� ���˻�Զ���֤��� */
typedef struct tagTMTSecDynPwdCerRet_Api
{
	BOOL32 bLocal;	//�Ƿ�Ϊ����
	BOOL32 bCerRet;	//�Ƿ���֤ͨ��
public:
	tagTMTSecDynPwdCerRet_Api(){ memset( this, 0, sizeof(struct tagTMTSecDynPwdCerRet_Api) ); }
}*PTMTSecDynPwdCerRet_Api, TMTSecDynPwdCerRet_Api;

/* ����ƵԴ��״̬��Ϣ */
typedef struct tagTMTAssVidPortStatus_Api
{
	s32		nVgaState;		//Vga�Ƿ���� 1:���� 0:δ���� 
	s32     nHdmiState;		//Hdmi�Ƿ����1:���� 0:δ����
public:
	tagTMTAssVidPortStatus_Api(){ memset( this, 0, sizeof(struct tagTMTAssVidPortStatus_Api) ); }
}*PTMTAssVidPortStatus_Api, TMTAssVidPortStatus_Api;

/** ����֤��ID�б� */
typedef struct tagTMtCertIDList_Api
{
	u8				byCount;
	TMtSecCerId_Api	atIdList[KMTAPI_SEC_CAID_MAX_NUM];
public:
	tagTMtCertIDList_Api(){ memset( this ,0 ,sizeof( struct tagTMtCertIDList_Api ) );	}
}*PTMtCertIDList_Api, TMtCertIDList_Api;

//����¼���ն˳�Ա
typedef struct tagTMTRecordMembers_Api
{
    s8 achMtID[KMTAPI_BUF_64_LEN+1];    //�ն�ID
public:
    tagTMTRecordMembers_Api() { memset(this, 0, sizeof(struct tagTMTRecordMembers_Api)); }
}*PTMTRecordMembers_Api, TMTRecordMembers_Api;

///����¼��
typedef struct tagTMTStartRecord_Api
{
    s8 achConfID[KMTAPI_BUF_16_LEN+1];                      ///< ����ID
    s8 achVideoName[KMTAPI_BUF_128_LEN+1];                  ///< ¼�񱣴���ļ�����
    EmRecordType_Api  emRecordType;                         ///< ¼������
    EmPublishMode_Api emPublishMode;                        ///< ����ģʽ
    EmRecordMode_Api  emRecordMode;                         ///< ¼��ģʽ
    BOOL32    bAnonymous;                                   ///< �Ƿ�֧�����½�ۿ�ֱ�� FALSE-��֧�֣�TRUE-֧�֣�
    BOOL32    bMainStream;                                  ///< �Ƿ�¼����ʽ��������Ƶ+��Ƶ�� FALSE-��TRUE-�ǣ�
    BOOL32    bDualStream;                                  ///< �Ƿ�¼˫������˫���� FALSE-��TRUE-�ǣ�

    u16       wRecordMemberCnt;                             ///< atRecordMembers�����С
    s8 achVrsId[KMTAPI_BUF_128_LEN+1];                      ///vrs��id��Ϣ,����ָ��¼���vrs(����ӵ��ֶ�)
    TMTRecordMembers_Api atRecordMembers[KMTAPI_COUNT_64];  ///< ����¼���ն�����
public:
    tagTMTStartRecord_Api() { memset(this, 0, sizeof(struct tagTMTStartRecord_Api)); }
}*PTMTStartRecord_Api, TMTStartRecord_Api;

//ֹͣ¼��
typedef struct tagTMTStopRecord_Api
{
    s8      achConfID[KMTAPI_BUF_16_LEN+1];                  ///< ����ID
    s8      achRecordID[KMTAPI_BUF_32_LEN+1];                ///< ¼��id
    EmRecordMode_Api   emRecordMode;                         ///< ¼��ģʽ
public:
    tagTMTStopRecord_Api() { memset(this, 0, sizeof(struct tagTMTStopRecord_Api)); }
}*PTMTStopRecord_Api, TMTStopRecord_Api;

///¼��״̬��Ϣ
typedef struct tagTMTRecordStateInfo_Api
{
    s8 achVideoName[KMTAPI_BUF_128_LEN+1];                  ///< ¼�񱣴���ļ�����
    EmRecordType_Api  emRecordType;                         ///< ¼������
    EmRecordState_Api emRecordState;                        ///< ¼��״̬
    EmPublishMode_Api emPublishMode;                        ///< ����ģʽ
    EmRecordMode_Api  emRecordMode;                         ///< ¼��ģʽ

    BOOL32    bAnonymous;                                   ///< �Ƿ�֧�����½�ۿ�ֱ�� FALSE-��֧�֣�TRUE-֧�֣�
    BOOL32    bMainStream;                                  ///< �Ƿ�¼����ʽ��������Ƶ+��Ƶ�� FALSE-��TRUE-�ǣ�
    BOOL32    bDualStream;                                  ///< �Ƿ�¼˫������˫���� FALSE-��TRUE-�ǣ�
    u32       dwCurrentProgress;                            ///< ��ǰ¼�����, ��λΪ: ��

    u16       wRecordMemberCnt;                             ///< atRecordMembers�����С
    TMTRecordMembers_Api atRecordMembers[KMTAPI_COUNT_64];  ///< ����¼���ն�����
public:
    tagTMTRecordStateInfo_Api() { memset(this, 0, sizeof(struct tagTMTRecordStateInfo_Api)); }
}*PTMTRecordStateInfo_Api, TMTRecordStateInfo_Api;

//�޸�¼��״̬
typedef struct tagTMTModifyRecordState_Api
{
    s8      achConfID[KMTAPI_BUF_16_LEN+1];                  ///< ����ID
    s8      achRecordID[KMTAPI_BUF_32_LEN+1];                ///< ¼��id
    EmRecordCmd_Api    emRecordCmd;                          ///< ¼�����ָ��
    EmRecordMode_Api   emRecordMode;                         ///< ¼��ģʽ
public:
    tagTMTModifyRecordState_Api() { memset(this, 0, sizeof(struct tagTMTModifyRecordState_Api)); }
}*PTMTModifyRecordState_Api, TMTModifyRecordState_Api;

///¼���б��Ա
typedef struct tagTMTRecordListMember_Api
{
    s8 achRecordID[KMTAPI_BUF_32_LEN+1];                    ///< ¼��id
    s8 achVideoName[KMTAPI_BUF_128_LEN+1];                  ///< ¼�񱣴���ļ�����
    EmRecordType_Api  emRecordType;                         ///< ¼������
    EmRecordState_Api emRecordState;                        ///< ¼��״̬
    EmPublishMode_Api emPublishMode;                        ///< ����ģʽ
    EmRecordMode_Api  emRecordMode;                         ///< ¼��ģʽ

    BOOL32    bAnonymous;                                   ///< �Ƿ�֧�����½�ۿ�ֱ�� FALSE-��֧�֣�TRUE-֧�֣�
    BOOL32    bMainStream;                                  ///< �Ƿ�¼����ʽ��������Ƶ+��Ƶ�� FALSE-��TRUE-�ǣ�
    BOOL32    bDualStream;                                  ///< �Ƿ�¼˫������˫���� FALSE-��TRUE-�ǣ�
    u32       dwCurrentProgress;                            ///< ��ǰ¼�����, ��λΪ: ��

    u16       wRecordMemberCnt;                             ///< atRecordMembers�����С
    TMTRecordMembers_Api atRecordMembers[KMTAPI_COUNT_64];  ///< ����¼���ն�����
public:
    tagTMTRecordListMember_Api() { memset(this, 0, sizeof(struct tagTMTRecordListMember_Api)); }
}*PTMTRecordListMember_Api, TMTRecordListMember_Api;

///¼����Ϣ�б�
typedef struct tagTMTRecordList_Api
{
    u32       dwRecordMemberCnt;                                  ///< atRecordListMember�����С
    TMTRecordListMember_Api atRecordListMember[KMTAPI_COUNT_8];   ///< ¼���б��Ա
public:
    tagTMTRecordList_Api() { memset(this, 0, sizeof(struct tagTMTRecordList_Api)); }
}*PTMTRecordList_Api, TMTRecordList_Api;

///�����ն���Ϣ
typedef struct tagTMTConfTerminalInfo_Api
{
    s8                 achAlias[KMTAPI_BUF_128_LEN+1];     ///< �ն˱���
    s8                 achMtID[KMTAPI_BUF_32_LEN+1];       ///< �ն�ID
    s8                 achE164[KMTAPI_MAX_MT_E164_LEN+1];  ///< �ն�E164��
    s8                 achIP[KMTAPI_BUF_16_LEN+1];         ///< �ն�IP
    u32                dwBitrate;                          ///< ��������

    BOOL32             bOnline;                            ///< �Ƿ����� TRUE-���ߣ�FALSE-������
    BOOL32             bSilence;                           ///< TRUE-������FALSE-������
    BOOL32             bMute;                              ///< TRUE-������FALSE-������
    BOOL32             bDual;                              ///< �Ƿ��ڷ���˫��; TRUE-�ǣ�FALSE-��
    BOOL32             bMix;                               ///< �Ƿ��ڻ���; TRUE-�ǣ�FALSE-��

    BOOL32             bVMP;                               ///< �Ƿ��ںϳ�; TRUE-�ǣ�FALSE-��
    BOOL32             bInspection;                        ///< �Ƿ���ѡ��; TRUE-�ǣ�FALSE-��
    BOOL32             bRecord;                            ///< �Ƿ���¼��; TRUE-�ǣ�FALSE-��
    BOOL32             bPoll;                              ///< �Ƿ�����ѯ; TRUE-�ǣ�FALSE-��
    BOOL32             bUpload;                            ///< �Ƿ����ϴ�; TRUE-�ǣ�FALSE-��

    EmMtType_Api       emMtType;                           ///< �ն�����
    EmCallMode_Api     emCallMode;                         ///< ����ģʽ 
    EmConfProtocol_Api emProtocol;                         ///< ����Э��

public:
    tagTMTConfTerminalInfo_Api() { memset(this, 0, sizeof(struct tagTMTConfTerminalInfo_Api)); }
}*PTMTConfTerminalInfo_Api, TMTConfTerminalInfo_Api;

///�����ն��б�
typedef struct tagTMTConfTerminalList_Api
{
    u32       dwCount;                                            ///< atConfTerminalList�����С
    TMTConfTerminalInfo_Api atConfTerminalList[KMTAPI_COUNT_8];   ///< �����ն���Ϣ�б��Ա
public:
    tagTMTConfTerminalList_Api() { memset(this, 0, sizeof(struct tagTMTConfTerminalList_Api)); }
}*PTMTConfTerminalList_Api, TMTConfTerminalList_Api;

/** ����ץ��״̬��Ϣ */
typedef struct tagTMtNetCapStateInfo_Api
{
	u32			dwState;  //0:�����ɹ�, 1:ץ��ֹͣ, 2:����ʧ��, 3:�ռ䲻��, 4:�ļ�������, 5:·��������, 6:�������� 
	TMTTime_Api	tCurTime;
public:
	tagTMtNetCapStateInfo_Api(){ memset( this ,0 ,sizeof( struct tagTMtNetCapStateInfo_Api ) );	}
}*PTMtNetCapStateInfo_Api, TMtNetCapStateInfo_Api;

/** ��ǰץ��״̬��Ϣ */
typedef struct tagTMtCurCapStatusInfo_Api
{
	u32			dwState;	// 1:����ץ��  0:û��ץ��
	TMTTime_Api	tStartTime;	// ץ����ʼʱ��
	u32			dwLastTime;	// �ϴ�ץ��ʱ�䣨��λ�����룩
	u32			dwStartTime; //��ʼץ��ʱ�䣨�°汾ʹ�� ��λ���룩						
public:
	tagTMtCurCapStatusInfo_Api(){ memset( this ,0 ,sizeof( struct tagTMtCurCapStatusInfo_Api ) ); }
}*PTMtCurCapStatusInfo_Api, TMtCurCapStatusInfo_Api;

/** �����豸֤����Ϣ(��׼�����) */
typedef struct tagTMtSecDevCertInfo_Api
{
	u32				   dwDevCertType;	// �豸֤������, 1:��׼TLS, 2:����ǩ����3:���ܼ��� 
	TMtSecCertInfo_Api tCertInfo;		// ֤����Ϣ
public:
	tagTMtSecDevCertInfo_Api() { memset( this, 0, sizeof(*this)); }
}*PTMtSecDevCertInfo_Api, TMtSecDevCertInfo_Api;

/** �޶�ip����Ϣ */
typedef struct tagTMtLimitIpInfo_Api
{
	//EmLimitIpType_Api	emLimitType;	//ip�޶�����
	u32  				dwStartIp;		//��ʼip
	u32  				dwEndIp;		//��ֹip
public:
	tagTMtLimitIpInfo_Api(){ memset( this ,0 ,sizeof( struct tagTMtLimitIpInfo_Api ) );	}
}*PTMtLimitIpInfo_Api, TMtLimitIpInfo_Api;

/** �޶�ip�����б� */
typedef struct tagTMtLimitIpInfoList_Api
{
	BOOL32				bEnable;		//0-�رգ� 1-����
	EmLimitIpType_Api	emLimitType;	//ip�޶�����
	TMtLimitIpInfo_Api  atIpItemInfo[KMTAPI_MAX_FTPTELNET_LIMIT_IPITEM_CNT];
	u32					dwCnt;
public:
	tagTMtLimitIpInfoList_Api(){ memset( this ,0 ,sizeof( struct tagTMtLimitIpInfoList_Api ) );	}
}*PTMtLimitIpInfoList_Api, TMtLimitIpInfoList_Api;

/** ������ʹ�õĴ��ڶ�д�ṹ�� */
typedef struct tagTMtSerialOptParam_Api
{
	s32		nSerialType;	   //��������
	s32     nOperateType;	   //��������
	u32     dwListenTime;	   //����ʱ��(����)
	u8		byLen;             //ָ�����
	u8      abyOrder[ KMTAPI_BUF_128_LEN + 1 ];   //����ָ��
public:
	tagTMtSerialOptParam_Api(){ memset( this ,0 ,sizeof( struct tagTMtSerialOptParam_Api ) ); }
}*PTMtSerialOptParam_Api, TMtSerialOptParam_Api;

/** ������ʹ�� ѡ�񴮿�ʹ�õĻظ���Ϣ */
typedef struct tagTMtChooseSerialUse_Api
{
	TMTHDSerialCtrl_Api		tSerialInfo;	   //������Ϣ
	BOOL32					bIsUse;			   //�����Ƿ�ʹ��
	s32						nRet;              //������
public:
	tagTMtChooseSerialUse_Api(){ memset( this ,0 ,sizeof( struct tagTMtChooseSerialUse_Api ) ); }
}*PTMtChooseSerialUse_Api, TMtChooseSerialUse_Api;

/** �����豸֤����Ϣ */
typedef struct tagTMtSecCreateCertReq_Api
{
	BOOL32  bSignCert;	//�Ƿ�Ϊǩ��֤�� �����豸֤��-->False ����ǩ��֤��-->True
	BOOL32  bResetPwd;	//�Ƿ�Ϊ����������Կ
	s8      achDeviceCertFileName[ KMTAPI_BUF_256_LEN + 1 ];
	TMtSecCertDistinctName_Api tSecCertDetail;
public:
	tagTMtSecCreateCertReq_Api(){ memset( this ,0 ,sizeof( struct tagTMtSecCreateCertReq_Api ) ); }
}*PTMtSecCreateCertReq_Api, TMtSecCreateCertReq_Api;

///Vrs��½�ɹ������û���Ϣ
typedef struct tagTMTVrsUserInfo_Api
{
	s8                 achToken[KMTAPI_BUF_64_LEN+1];     ///< token
	s8                 achUserDomainMoid[KMTAPI_BUF_32_LEN+1];     ///< userdomainmoid
	s8                 achUserMoid[KMTAPI_BUF_32_LEN+1];     ///< usermoid
public:
	tagTMTVrsUserInfo_Api() { memset(this, 0, sizeof(struct tagTMTVrsUserInfo_Api)); }
}*PTMTVrsUserInfo_Api, TMTVrsUserInfo_Api;

///��½���Խṹ
typedef struct tagTMTLoginStrategy_Api
{
	u32                dwLoginCount;   //��¼����(3 -- 10 ��)
	u32                dwWaitTime;     //���һ�ε�¼ʧ����Ҫ�ȴ�ʱ��(3 -- 10 ����)
public:
	tagTMTLoginStrategy_Api() { memset(this, 0, sizeof(struct tagTMTLoginStrategy_Api)); }
}*PTMTLoginStrategy_Api, TMTLoginStrategy_Api;






//////////////////////////////////////////////////////////////////////////
// �����ǵ��Ӱװ�ṹ��

typedef struct tagTDCSRegInfo_Api
{
	s8					achIp[KMTAPI_BUF_128_LEN+1];
	u32					dwPort;
	EmDcsType_Api		emMtType;

	tagTDCSRegInfo_Api() { memset(this, 0, sizeof(tagTDCSRegInfo_Api)); }

}*PTDCSRegInfo_Api, TDCSRegInfo_Api;



typedef struct tagTDCSResult_Api
{
	BOOL32		bSucces;
	u32			dwErrorCode;
	s8			achConfE164[KMTAPI_BUF_64_LEN+1];

	tagTDCSResult_Api() { memset(this, 0, sizeof(tagTDCSResult_Api)); }

}*PTDCSResult_Api, TDCSResult_Api;


typedef struct tagTDCSSetConfInfoResult_Api
{
	BOOL32     	bSucces;
	u32			dwErrorCode;

	s8			achConfE164[KMTAPI_BUF_64_LEN+1];
	s8			achConfName[KMTAPI_BUF_256_LEN+1];
	EmDcsConfMode_Api	emConfMode;
	EmDcsConfType_Api	emConfType;

	tagTDCSSetConfInfoResult_Api() { memset(this, 0, sizeof(tagTDCSSetConfInfoResult_Api)); }

}*PTDCSSetConfInfoResult_Api, TDCSSetConfInfoResult_Api;

typedef struct tagTDCSBoardResult_Api
{
	BOOL32     	bSucces;
	u32			dwErrorCode;

	s8			achConfE164[KMTAPI_BUF_64_LEN+1];
	s8  		achTabId[KMTAPI_BUF_64_LEN+1];
	u32			dwPageId;

	tagTDCSBoardResult_Api() { memset(this, 0, sizeof(tagTDCSBoardResult_Api)); }

}*PTDCSBoardResult_Api, TDCSBoardResult_Api;

//��¼APS������������û�������
typedef struct tagTDCSApsLoginParam_Api
{
	s8 achUsername[KMTAPI_BUF_128_LEN+1]; ///< �û���
	s8 achPassword[KMTAPI_BUF_64_LEN+1]; ///< ��������

	tagTDCSApsLoginParam_Api() { memset(this, 0, sizeof(tagTDCSApsLoginParam_Api)); }

}*PTDCSApsLoginParam_Api, TDCSApsLoginParam_Api;

typedef struct tagTDCSOperReq_Api
{
	s8			 achConfE164[KMTAPI_BUF_64_LEN+1];
	s8  		 achTabId[KMTAPI_BUF_64_LEN+1];
	u32			 dwWbPageid;

	tagTDCSOperReq_Api() { memset(this, 0, sizeof(tagTDCSOperReq_Api)); }

}*PTDCSOperReq_Api, TDCSOperReq_Api;

typedef struct tagTDCSFileInfo_Api
{
	s8		achFilePathName[KMTAPI_BUF_512_LEN+1];
	s8		achWbPicentityId[KMTAPI_BUF_64_LEN+1];			// �����ͼƬ�������pic id������Ϊ��
	s8		achTabid[KMTAPI_BUF_64_LEN+1];
    BOOL32 bElementCacheFile; ///< �Ƿ�ΪͼԪ�����ļ�
    u32 dwFileSize;

	tagTDCSFileInfo_Api() { memset( this, 0, sizeof( tagTDCSFileInfo_Api ) ); }

}*PTDCSFileInfo_Api, TDCSFileInfo_Api;


typedef struct tagTDCSConfUserInfo_Api
{
	s8			 achE164[KMTAPI_MAX_MT_E164_LEN+1];
	s8			 achName[KMTAPI_BUF_256_LEN+1];     			// ֻ���������᷽��ɾ����᷽�õ�
	EmDcsType_Api emMttype;
//	EmDcsRole_Api emRole;         		// ֻ���ڻ��������Ч
	BOOL32		 bOnline; 			// ��ʱֻ�ڻ�ȡ�����Ա�б�����Ч
	BOOL32		 bIsOper;
	BOOL32		 bIsConfAdmin;

	tagTDCSConfUserInfo_Api() { memset(this, 0, sizeof(tagTDCSConfUserInfo_Api)); }

}*PTDCSConfUserInfo_Api, TDCSConfUserInfo_Api;

typedef struct tagTDCSCreateConf_Api
{
	EmDcsConfType_Api	 emConfType;
	s8					 achConfE164[KMTAPI_BUF_64_LEN+1];
	s8					 achConfName[KMTAPI_BUF_128_LEN+1];
	EmDcsConfMode_Api	 emConfMode;

	u32					 dwListNum;
	TDCSConfUserInfo_Api	 atUserList[KMTAPI_COUNT_192+1];

	s8					achConfAdminE164[KMTAPI_MAX_MT_E164_LEN+1];
	EmDcsType_Api		emAdminMtType;

	tagTDCSCreateConf_Api() { memset(this, 0, sizeof(tagTDCSCreateConf_Api)); }

}*PTDCSCreateConf_Api, TDCSCreateConf_Api;

typedef struct tagTDCSConfAddr_Api
{
	s8		 achIp[KMTAPI_BUF_64_LEN+1];
	s8		 achDomain[KMTAPI_BUF_256_LEN+1];
	u32		 dwPort;

	tagTDCSConfAddr_Api() { memset(this, 0, sizeof(tagTDCSConfAddr_Api)); }

}*PTDCSConfAddr_Api, TDCSConfAddr_Api;

typedef struct tagTDCSCreateConfResult_Api
{
	s8		 achConfE164[KMTAPI_BUF_64_LEN+1];
	s8		 achConfName[KMTAPI_BUF_128_LEN+1];
	BOOL32	 bSuccess;
	u32		 dwErrorCode;

	EmDcsConfMode_Api	emConfMode;
	EmDcsConfType_Api	emConfType; 

	TDCSConfAddr_Api    tConfAddr;

	BOOL32	 bCreator;  ///< �Լ��Ƿ���������ݻ���Ĵ�����

	tagTDCSCreateConfResult_Api() { memset(this, 0, sizeof(tagTDCSCreateConfResult_Api)); }

}*PTDCSCreateConfResult_Api, TDCSCreateConfResult_Api;

typedef struct tagTDCSInviteUsr_Api
{
	s8			 achConfE164[KMTAPI_BUF_64_LEN+1];
//	s8			 achConfName[KMTAPI_BUF_128_LEN+1];
	TDCSConfAddr_Api     tConfAddr;

	tagTDCSInviteUsr_Api() { memset(this, 0, sizeof(tagTDCSInviteUsr_Api)); }

}*PTDCSInviteUsr_Api, TDCSInviteUsr_Api;

typedef struct tagTDCSJoinConfResult_Api
{
	s8		 achConfE164[KMTAPI_BUF_64_LEN+1];
	s8		 achConfName[KMTAPI_BUF_128_LEN+1];
	EmDcsConfMode_Api	emConfMode;
	EmDcsConfType_Api	emConfType;
	BOOL32	 bSuccess;
	u32 	 dwErrorCode;
	//EmDcsRole_Api	 emRole;
	BOOL32	 bIsOper;
	BOOL32   bIsConfAdmin;

	tagTDCSJoinConfResult_Api() { memset(this, 0, sizeof(tagTDCSJoinConfResult_Api)); }

}*PTDCSJoinConfResult_Api, TDCSJoinConfResult_Api;

typedef struct tagTDCSRejectJoinConf_Api
{
	s8 									achConfE164[KMTAPI_BUF_64_LEN+1];
	EmDcsRejectJoinConfCode_Api  		emReason;

	tagTDCSRejectJoinConf_Api() { memset(this, 0, sizeof(tagTDCSRejectJoinConf_Api)); }

}*PTDCSRejectJoinConf_Api, TDCSRejectJoinConf_Api;

typedef struct tagTDCSMemberInfo_Api
{
	s8					 achConfE164[KMTAPI_BUF_64_LEN+1];

	u32					 dwListNum;
	TDCSConfUserInfo_Api	 atUserList[KMTAPI_COUNT_192+1];

	tagTDCSMemberInfo_Api() { memset(this, 0, sizeof(tagTDCSMemberInfo_Api)); }

}*PTDCSMemberInfo_Api, TDCSMemberInfo_Api;

typedef struct tagTDCSConfInfo_Api
{
	s8	 achConfE164[KMTAPI_BUF_64_LEN+1];
	s8	 achConfName[KMTAPI_BUF_128_LEN+1];
	EmDcsConfMode_Api		 emConfMode;
	EmDcsConfType_Api		 emConfType;

	tagTDCSConfInfo_Api() { memset(this, 0, sizeof(tagTDCSConfInfo_Api)); }

}*PTDCSConfInfo_Api, TDCSConfInfo_Api;


typedef struct tagTDCSOperator_Api
{
	s8		achConfE164[KMTAPI_BUF_64_LEN+1];

	u32							dwListNum;
	TDCSConfUserInfo_Api		atOperList[KMTAPI_COUNT_192+1];

	tagTDCSOperator_Api() { memset(this, 0, sizeof(tagTDCSOperator_Api)); }
}*PTDCSOperator_Api, TDCSOperator_Api;

// typedef struct tagTDCSSetUserRole_Api
// {
// 	s8			 achConfE164[KMTAPI_BUF_64_LEN+1];
// 
// 	u32			 dwListNum;
// 	TDCSConfUserInfo_Api	 atUserList[KMTAPI_COUNT_192+1];   // ������Ҫ��д�û���ɫ
// 
// 	tagTDCSSetUserRole_Api() { memset(this, 0, sizeof(tagTDCSSetUserRole_Api)); }
// 
// }*PTDCSSetUserRole_Api, TDCSSetUserRole_Api;

typedef struct tagTDCSGetUserList_Api
{
	u32				 dwListNum;
	TDCSConfUserInfo_Api atUserList[KMTAPI_COUNT_192+1];   // �������û���ɫ�Լ�����״̬

	tagTDCSGetUserList_Api() { memset(this, 0, sizeof(tagTDCSGetUserList_Api)); }

}*PTDCSGetUserList_Api, TDCSGetUserList_Api;

typedef struct tagTDCSBoardInfo_Api
{
	s8				 achWbName[KMTAPI_BUF_256_LEN+1];
	EmDcsWbMode_Api	 emWbMode;
	u32 			 dwWbPageNum;
	u32				 dwWbCreateTime;		// ƽ̨�ɹ���Ӧ��ƽ̨��д
	s8  			 achTabId[KMTAPI_BUF_64_LEN+1];			// �ն���д
//	s8				 achImagePath[KMTAPI_BUF_512_LEN+1];			// ƽ̨�ɹ���Ӧ��ƽ̨��д
//	s8				 achElementPath[KMTAPI_BUF_512_LEN+1];		// ƽ̨�ɹ���Ӧ��ƽ̨��д
	u32 			 dwPageId;				
	u32				 dwWbSerialNumber;		// �װ����кţ���������ǰװ崴�����

	s8					achWbCreatorE164[KMTAPI_MAX_MT_E164_LEN+1];
	u32					dwWbWidth;
	u32					dwWbHeight;
	s8					achElementUrl[KMTAPI_BUF_512_LEN+1];
	s8					achDownloadUrl[KMTAPI_BUF_512_LEN+1];
	s8					achUploadUrl[KMTAPI_BUF_512_LEN+1];
//	u32					dwInconvert;

	u32					dwWbAnonyId;			// ƽ̨�ɹ���Ӧ��ƽ̨��д�������ڰװ�ģʽ��

	tagTDCSBoardInfo_Api() { memset(this, 0, sizeof(tagTDCSBoardInfo_Api)); }

}*PTDCSBoardInfo_Api, TDCSBoardInfo_Api;

typedef struct tagTDCSNewWhiteBoard_Api
{
	s8				 achConfE164[KMTAPI_BUF_64_LEN+1];
	TDCSBoardInfo_Api tBoardinfo;

	tagTDCSNewWhiteBoard_Api() { memset(this, 0, sizeof(tagTDCSNewWhiteBoard_Api)); }

}*PTDCSNewWhiteBoard_Api, TDCSNewWhiteBoard_Api;

typedef struct tagTDCSGetAllBoard_Api
{
	s8				 achConfE164[KMTAPI_BUF_64_LEN+1];

	u32				 dwBoardNum;
	TDCSBoardInfo_Api atBoardInfo[KMTAPI_COUNT_64+1];

	tagTDCSGetAllBoard_Api() { memset(this, 0, sizeof(tagTDCSGetAllBoard_Api)); }

}*PTDCSGetAllBoard_Api, TDCSGetAllBoard_Api;

typedef struct tagTDCSSwitchReq_Api
{
	s8		 achConfE164[KMTAPI_BUF_64_LEN+1];
	s8  	achTabId[KMTAPI_BUF_64_LEN+1];
	u32 	 dwWbPageId;

	tagTDCSSwitchReq_Api() { memset(this, 0, sizeof(tagTDCSSwitchReq_Api)); }

}*PTDCSSwitchReq_Api, TDCSSwitchReq_Api;

typedef struct tagTDCSUserInfo_Api
{
	s8		 achConfE164[KMTAPI_BUF_64_LEN+1];
	s8		 achConfName[KMTAPI_BUF_128_LEN+1];
	TDCSConfUserInfo_Api	 tUserInfo;

	tagTDCSUserInfo_Api() { memset(this, 0, sizeof(tagTDCSUserInfo_Api)); }

}*PTDCSUserInfo_Api, TDCSUserInfo_Api;


typedef struct tagTDCSUserInfos_Api
{
	s8 			 achConfE164[KMTAPI_BUF_64_LEN+1];
	s8 			 achConfName[KMTAPI_BUF_128_LEN+1];

	u32					 dwListNum;
	TDCSConfUserInfo_Api	 atUserInfoList[KMTAPI_COUNT_192+1];

	tagTDCSUserInfos_Api() { memset(this, 0, sizeof(tagTDCSUserInfos_Api)); }

}*PTDCSUserInfos_Api, TDCSUserInfos_Api;


typedef struct tagTDCSUserRole_Api
{
	s8 					 achConfE164[KMTAPI_BUF_64_LEN+1];

	u32					 dwListNum;
	TDCSConfUserInfo_Api	 atUserInfoList[KMTAPI_COUNT_192+1];

	tagTDCSUserRole_Api() { memset(this, 0, sizeof(tagTDCSUserRole_Api)); }

}*PTDCSUserRole_Api, TDCSUserRole_Api;


typedef struct tagTDCSOperContent_Api
{
	EmDcsOper_Api	emOper;
	u32				dwMsgId;
	s8				achTabId[KMTAPI_BUF_64_LEN+1];
	u32				dwWbPageId;
	u32				dwMsgSequence;
	s8				achConfE164[KMTAPI_BUF_64_LEN+1];
	s8				achFromE164[KMTAPI_BUF_64_LEN+1];

	BOOL32			bCacheElement;			// �Ƿ��Ƿ����������ͼԪ

	tagTDCSOperContent_Api() { memset(this, 0, sizeof(tagTDCSOperContent_Api)); }

}*PTDCSOperContent_Api, TDCSOperContent_Api;

typedef struct tagTDCSWbPoint_Api
{
	s32	 nPosx;
	s32	 nPosy;

	tagTDCSWbPoint_Api() { memset(this, 0, sizeof(tagTDCSWbPoint_Api)); }

}*PTDCSWbPoint_Api, TDCSWbPoint_Api;

typedef struct tagTDCSWbEntity_Api
{
	s8	 achEntityId[KMTAPI_BUF_64_LEN+1];    // ����ʹ��GUID����д
	BOOL32 bLock;

	tagTDCSWbEntity_Api() { memset(this, 0, sizeof(tagTDCSWbEntity_Api)); }

}*PTDCSWbEntity_Api, TDCSWbEntity_Api;


typedef struct tagTDCSWbLine_Api
{
	TDCSWbEntity_Api	 tEntity;     // ������Ϣ
	TDCSWbPoint_Api 	 tBeginPt;    // �������
	TDCSWbPoint_Api 	 tEndPt;      // �ն�����
	u32				 dwLineWidth;	// �߿�
	u32 			 dwRgb;        // ��ɫ

	tagTDCSWbLine_Api() { memset(this, 0, sizeof(tagTDCSWbLine_Api)); }

}*PTDCSWbLine_Api, TDCSWbLine_Api;

typedef struct tagTDCSWbCircle_Api
{
	TDCSWbEntity_Api  tEntity;         // ������Ϣ
	TDCSWbPoint_Api  tBeginPt;        // �������
	TDCSWbPoint_Api  tEndPt;          // �ն�����
	u32			 dwLineWidth;		 // �߿�
	u32 		 dwRgb;           // ��ɫ

	tagTDCSWbCircle_Api() { memset(this, 0, sizeof(tagTDCSWbCircle_Api)); }

}*PTDCSWbCircle_Api, TDCSWbCircle_Api;

typedef struct tagTDCSWbRectangle_Api
{
	TDCSWbEntity_Api  tEntity;         // ������Ϣ
	TDCSWbPoint_Api  tBeginPt;        // �������
	TDCSWbPoint_Api  tEndPt;          // �ն�����
	u32			 dwLineWidth;		 // �߿�
	u32 		 dwRgb;           // ��ɫ

	tagTDCSWbRectangle_Api() { memset(this, 0, sizeof(tagTDCSWbRectangle_Api)); }

}*PTDCSWbRectangle_Api, TDCSWbRectangle_Api;

// Ǧ��ͼԪ�ࣨ�����ߣ�
typedef struct tagTDCSWbPencil_Api
{
	TDCSWbEntity_Api  tEntity;      // ������Ϣ

	u32				 dwPointNum;
	TDCSWbPoint_Api 	 atPList[KMTAPI_DCS_POINT_MAX+1]; 		 // ���ߵ���Ϣ�б�

	u32				 dwLineWidth;	 // �߿�
	u32 			 dwRgb;          // ��ɫ 

	tagTDCSWbPencil_Api() { memset(this, 0, sizeof(tagTDCSWbPencil_Api)); }

}*PTDCSWbPencil_Api, TDCSWbPencil_Api;

// �ʱ�ͼԪ�ࣨ����ɫ���ߣ�
typedef struct tagTDCSWbColorPen_Api
{
	TDCSWbEntity_Api  tEntity;                // ������Ϣ

	u32				 dwColorPenNum;
	TDCSWbPoint_Api	 atCPList[KMTAPI_DCS_POINT_MAX+1];                  // ���ߵ���Ϣ�б� 
	u32				 dwLineWidth;	           // �߿�
	u32 			 dwRgb;     

	tagTDCSWbColorPen_Api() { memset(this, 0, sizeof(tagTDCSWbColorPen_Api)); }

}*PTDCSWbColorPen_Api, TDCSWbColorPen_Api;

// ͼƬͼԪ��
typedef struct tagTDCSWbImage_Api
{
	TDCSWbEntity_Api	tEntity;				// ������Ϣ
	TDCSWbPoint_Api 	tBoardPt;				// �߽�������Ͻ�����
	u32 				dwWidth;				// �߽���ο��
	u32 				dwHeight;				// �߽���ο��
	EmDcsWbImageState_Api 					emNetworkstate;			// ����״̬��Ϣ
	s8 					achFileName[KMTAPI_BUF_256_LEN+1];          // �ļ�����utf8���룩
	BOOL32				bBkImg;					// �Ƿ��ĵ���ͼ

	tagTDCSWbImage_Api() { memset(this, 0, sizeof(tagTDCSWbImage_Api)); }

}*PTDCSWbImage_Api, TDCSWbImage_Api;

// �߻�ͼ������ϸ��Ϣ���Ѿ��װ�����У�ÿ����һ�ζ�Ӧ�Ĳ�����Ϣ��
typedef struct tagTDCSWbLineOperInfo_Api
{
	s8  			 achTabId[KMTAPI_BUF_64_LEN+1];            // �װ�tab id��guid��
	u32 			 dwSubPageId;        // ��ҳ��id
	TDCSWbLine_Api 	 tLine;             // �߲�����Ϣ

	tagTDCSWbLineOperInfo_Api() { memset(this, 0, sizeof(tagTDCSWbLineOperInfo_Api)); }

}*PTDCSWbLineOperInfo_Api, TDCSWbLineOperInfo_Api;

// Բ��ͼ������ϸ��Ϣ���Ѿ��װ�����У�ÿ����һ�ζ�Ӧ�Ĳ�����Ϣ��
typedef struct tagTDCSWbCircleOperInfo_Api
{
	s8  			 achTabId[KMTAPI_BUF_64_LEN+1];            // �װ�tab id��guid��
	u32 			 dwSubPageId;        // ��ҳ��id
	TDCSWbCircle_Api  tCircle;           // Բ������Ϣ

	tagTDCSWbCircleOperInfo_Api() { memset(this, 0, sizeof(tagTDCSWbCircleOperInfo_Api)); }

}*PTDCSWbCircleOperInfo_Api, TDCSWbCircleOperInfo_Api;

// ���λ�ͼ������ϸ��Ϣ���Ѿ��װ�����У�ÿ����һ�ζ�Ӧ�Ĳ�����Ϣ��
typedef struct tagTDCSWbRectangleOperInfo_Api
{
	s8  			 achTabId[KMTAPI_BUF_64_LEN+1];            // �װ�tab id��guid��
	u32 			 dwSubPageId;        // ��ҳ��id
	TDCSWbRectangle_Api  tRectangle;           // ���β�����Ϣ

	tagTDCSWbRectangleOperInfo_Api() { memset(this, 0, sizeof(tagTDCSWbRectangleOperInfo_Api)); }

}*PTDCSWbRectangleOperInfo_Api, TDCSWbRectangleOperInfo_Api;



// Ǧ�ʻ�ͼ������ϸ��Ϣ���Ѿ��װ�����У�ÿ����һ�ζ�Ӧ�Ĳ�����Ϣ��
typedef struct tagTDCSWbPencilOperInfo_Api
{
	s8  			 achTabId[KMTAPI_BUF_64_LEN+1];            // �װ�tab id��guid��
	u32 			 dwSubPageId;        // ��ҳ��id
	TDCSWbPencil_Api  tPencil;           // Ǧ�ʲ�����Ϣ

	tagTDCSWbPencilOperInfo_Api() { memset(this, 0, sizeof(tagTDCSWbPencilOperInfo_Api)); }

}*PTDCSWbPencilOperInfo_Api, TDCSWbPencilOperInfo_Api;

// �ʱʻ�ͼ������ϸ��Ϣ���Ѿ��װ�����У�ÿ����һ�ζ�Ӧ�Ĳ�����Ϣ��
typedef struct tagTDCSWbColorPenOperInfo_Api
{
	s8  			 achTabId[KMTAPI_BUF_64_LEN+1];            // �װ�tab id��guid��
	u32 			 dwSubPageId;        // ��ҳ��id
	TDCSWbColorPen_Api	 tColorPen;         // �ʱʲ�����Ϣ

	tagTDCSWbColorPenOperInfo_Api() { memset(this, 0, sizeof(tagTDCSWbColorPenOperInfo_Api)); }

}*PTDCSWbColorPenOperInfo_Api, TDCSWbColorPenOperInfo_Api;

typedef struct tagTDCSWbImageOperInfo_Api
{
	s8				 achTabId[KMTAPI_BUF_64_LEN+1];                // �װ�tab id��guid��
	u32				 dwSubPageId;            // ��ҳ��id
	TDCSWbImage_Api	 tImage;            	// ͼƬͼԪ������Ϣ

	tagTDCSWbImageOperInfo_Api() { memset(this, 0, sizeof(tagTDCSWbImageOperInfo_Api)); }

}*PTDCSWbImageOperInfo_Api, TDCSWbImageOperInfo_Api;

// ��ǵ�ǰ�����ĵ���tabҳ��subpage
typedef struct tagTDCSWbTabPageIdInfo_Api
{
	s8 	 achTabId[KMTAPI_BUF_64_LEN+1];    		// �װ�tab id��guid��
	u32  dwSubPageId;   	// ��ҳid

	tagTDCSWbTabPageIdInfo_Api() { memset(this, 0, sizeof(tagTDCSWbTabPageIdInfo_Api)); }

}*PTDCSWbTabPageIdInfo_Api, TDCSWbTabPageIdInfo_Api;

typedef struct tagTDCSScrollScreenInfo_Api
{
	s8 			achTabId[KMTAPI_BUF_64_LEN+1]; 		//tab�װ�ҳ
	u32			dwSubPageId;						//��ҳID
	TDCSWbPoint_Api			tPoint;		//��������Ŀ�������

	tagTDCSScrollScreenInfo_Api() { memset(this, 0, sizeof(tagTDCSScrollScreenInfo_Api)); }
}*PTDCSScrollScreenInfo_Api, TDCSScrollScreenInfo_Api;

// ɾ��tabҳЯ������Ϣ
// typedef struct tagTDCSWbRemovePageIdInfo_Api
// {
// 	s8 	 achTabId[KMTAPI_BUF_256_LEN+1];   			// �װ�tab id��guid��
// 	s8 	 achNextTabPageId[KMTAPI_BUF_256_LEN+1];   	// ��һ��tab�װ�ҳid
// 
// 	tagTDCSWbRemovePageIdInfo_Api() { memset(this, 0, sizeof(tagTDCSWbRemovePageIdInfo_Api)); }
// 
// }*PTDCSWbRemovePageIdInfo_Api, TDCSWbRemovePageIdInfo_Api;


// �װ�ҳ��Ϣ���ڴ����װ塢���°װ���Ϣ��ʱ��ʹ��
// typedef struct tagTDCSWbTabPageInfo_Api
// {
// 	s8 	 achTabId[KMTAPI_BUF_256_LEN+1];             		// �װ�tab id��guid�����ɴ���������
// 	u32  dwSubPageCount;         	// ��ҳҳ�������ĵ�ģʽ��ҳ��Ϊ1
// 	u32  dwMode;                 	// �װ�ģʽ���װ���ĵ�
// 	s8 	 achName[KMTAPI_BUF_256_LEN+1];           		// �װ����ƣ�m_bAnoymousΪtrueʱ������Ϊ�գ�utf8���룩
// 	u32  dwAnoymousTabIndex;    	// ������Tabҳ����������û���趨�װ����Ƶİװ壬���������ƵĹ��������硰�½��װ�3������������������
// 	u32  dwCanvasWidth;          	// �������(�ĵ����𷽵���Ļ���)
// 	u32  dwCanvasHeight;         	// �����߶�(�ĵ����𷽵���Ļ�߶�)
// 	u32	 dwOwnerIndex;           	// �ðװ�TABҳ�ĵ������ڷ������ϵ�userindex���ɷ�������䣬����֪ͨ�ͻ��˸��£�����ĵ������˳����飬��Ҫ��ע���µ�ҳ��Ϊ�����뿪״̬
// 	u32  dwTime;                	// ����ʱ���ʶ���ɷ�������䣬����֪֪ͨ�ͻ��˸��£����ڱ�ʶ�װ崴�����Ⱥ�ʱ�䣬�´����ķ�������ߣ�
// 	BOOL32 bInconvert;         	// office�ĵ��Ƿ���ת����
// 
// 	tagTDCSWbTabPageInfo_Api() { memset(this, 0, sizeof(tagTDCSWbTabPageInfo_Api)); }
// 
// }*PTDCSWbTabPageInfo_Api, TDCSWbTabPageInfo_Api;

// �װ��������ҳ��Ϣ�����ĵ�ʱ�������ĵ�����ҳ���ڵ�ǰ�װ�����Ӷ����ҳ
typedef struct tagTDCSWbAddSubPageInfo_Api
{
	s8 	 achTabId[KMTAPI_BUF_64_LEN+1];             // �װ�tab id��guid��
	u32  dwSubPageCount;       // ��ҳ���������򿪵��ĵ�����ҳ��

	tagTDCSWbAddSubPageInfo_Api() { memset(this, 0, sizeof(tagTDCSWbAddSubPageInfo_Api)); }

}*PTDCSWbAddSubPageInfo_Api, TDCSWbAddSubPageInfo_Api;


// �л��װ�ҳ��Ϣ���л��װ�ҳ�������������
// 1)�ڵ�ǰ�װ��д�һ����ҳ�л�����һ��ҳ����ǰ��ҳ�����߷���ָ����ҳ�棻
// 2)�л�����һ���װ���
// typedef struct tagTDCSWbSwitchPageInfo_Api
// {
// 	s8 	 achTabId[KMTAPI_BUF_64_LEN+1];             // �װ�tab id��guid��
// 	u32  dwSubPageId;              // ��ҳid
// 
// 	tagTDCSWbSwitchPageInfo_Api() { memset(this, 0, sizeof(tagTDCSWbSwitchPageInfo_Api)); }
// 
// }*PTDCSWbSwitchPageInfo_Api, TDCSWbSwitchPageInfo_Api;

// �ͻ��˸���������������Ŀ��ҳͼƬ����
// typedef struct tagTDCSWbReqPageImage_Api
// {
// 	s8 	 achImgId[KMTAPI_BUF_256_LEN+1];         // �����ͼƬͼԪid��guid��
// 	s8 	 achTabId[KMTAPI_BUF_64_LEN+1];         // �װ�tab id��guid��
// 	u32  dwSubPageId;        // ��ǰ��ҳid
// 	u32  dwOwnerIndex;       // �ðװ�ҳ�ĵ������ڷ������ϵ�userindex���������յ��������Ҫ����index��Ӧ������������
// 
// 	tagTDCSWbReqPageImage_Api() { memset(this, 0, sizeof(tagTDCSWbReqPageImage_Api)); }
// 
// }*PTDCSWbReqPageImage_Api, TDCSWbReqPageImage_Api;

// ���β���
typedef struct tagTDCSWbEraseOperInfo_Api
{
	s8 				achTabId[KMTAPI_BUF_64_LEN+1];            // �װ�tab id��guid��
	u32				dwSubPageId;	
	TDCSWbPoint_Api	 tBeginPt;          // ���β�������Ŀ�ʼ���꣨�˲������β���ʹ�ã�
	TDCSWbPoint_Api	 tEndPt;            // ���β�������Ľ������꣨�˲������β���ʹ�ã�

	BOOL32			bNexVision;				// �Ƿ��������ն�

	tagTDCSWbEraseOperInfo_Api() { memset(this, 0, sizeof(tagTDCSWbEraseOperInfo_Api)); }

}*PTDCSWbEraseOperInfo_Api, TDCSWbEraseOperInfo_Api;

// �Ŵ�/��С������/��������Ӧ
typedef struct tagTDCSWbZoomInfo_Api
{
	s8 	 achTabId[KMTAPI_BUF_64_LEN+1];       // �װ�tab id��guid��
	u32  dwZoom;           // ��ǰҳ���ű�����ȡ�ٷ��ƣ�����100.0����Ӧ100%

	tagTDCSWbZoomInfo_Api() { memset(this, 0, sizeof(tagTDCSWbZoomInfo_Api)); }

}*PTDCSWbZoomInfo_Api, TDCSWbZoomInfo_Api;



// ȫ����ʾ/100������ʾ
typedef struct tagTDCSWbDisPlayInfo_Api
{
	s8 				achTabId[KMTAPI_BUF_64_LEN+1];		//tab�װ�ҳ
	u32				dwSubPageId;		//��ҳID
	s8				aachMatrixValue[ KMTAPI_DCS_MATRIXVALUE+1 ][KMTAPI_BUF_32_LEN+1];		

	tagTDCSWbDisPlayInfo_Api() { memset(this, 0, sizeof(tagTDCSWbDisPlayInfo_Api)); }

}*PTDCSWbDisPlayInfo_Api, TDCSWbDisPlayInfo_Api;


// ������β���
typedef struct tagTDCSWbReginEraseOperInfo_Api
{
	s8 					achTabId[KMTAPI_BUF_64_LEN+1];            // �װ�tab id��guid��
	u32 				dwSubPageId;   	// ��ҳid
	s8					achGraphsId[KMTAPI_BUF_128_LEN+1];		// ͼԪID
	u32					dwEraseWidth;
	u32					dwEraseHeight;

	u32					dwPointCount;
	TDCSWbPoint_Api		atPoint[KMTAPI_DCS_POINT_MAX+1];

	tagTDCSWbReginEraseOperInfo_Api() { memset(this, 0, sizeof(tagTDCSWbReginEraseOperInfo_Api)); }

}*PTDCSWbReginEraseOperInfo_Api, TDCSWbReginEraseOperInfo_Api;

//����ͼƬ
typedef struct tagTDCSWbInsertPicOperInfo_Api
{
	s8 					achTabId[KMTAPI_BUF_64_LEN+1];            // �װ�tab id��guid��
	u32 				dwSubPageId;   	// ��ҳid
	s8					achImgId[KMTAPI_BUF_128_LEN+1];		// ͼԪID
	u32					dwImgWidth;
	u32					dwImgHeight;
	TDCSWbPoint_Api		tPoint;
	s8					achPicName[KMTAPI_BUF_128_LEN+1];

	s8					aachMatrixValue[ KMTAPI_DCS_MATRIXVALUE+1 ][KMTAPI_BUF_32_LEN+1];

	tagTDCSWbInsertPicOperInfo_Api() { memset(this, 0, sizeof(tagTDCSWbInsertPicOperInfo_Api)); }

}*PTDCSWbInsertPicOperInfo_Api, TDCSWbInsertPicOperInfo_Api;


typedef struct tagTDCSWbGraphsInfo_Api
{
	s8					achGraphsId[KMTAPI_BUF_128_LEN+1];		// ͼԪID
	s8					aachMatrixValue[ KMTAPI_DCS_MATRIXVALUE+1 ][KMTAPI_BUF_32_LEN+1];

	tagTDCSWbGraphsInfo_Api() { memset(this, 0, sizeof(tagTDCSWbGraphsInfo_Api)); }
}*PTDCSWbGraphsInfo_Api, TDCSWbGraphsInfo_Api;

// ѡ��ͼƬ��׼�����в�����
typedef struct tagTDCSWbPitchPicOperInfo_Api
{
	s8 					achTabId[KMTAPI_BUF_64_LEN+1];            // �װ�tab id��guid��
	u32 				dwSubPageId;   	// ��ҳid

	u32					dwGraphsCount;
	TDCSWbGraphsInfo_Api	atGraphsInfo[KMTAPI_DCS_PIC_MAX+1];

	tagTDCSWbPitchPicOperInfo_Api() { memset(this, 0, sizeof(tagTDCSWbPitchPicOperInfo_Api)); }

}*PTDCSWbPitchPicOperInfo_Api, TDCSWbPitchPicOperInfo_Api;


// ѡ��ɾ��ͼƬ
typedef struct tagTDCSWbDelPicOperInfo_Api
{
	s8 					achTabId[KMTAPI_BUF_64_LEN+1];            // �װ�tab id��guid��
	u32 				dwSubPageId;   	// ��ҳid

	u32					dwGraphsCount;
	s8					achGraphsId[KMTAPI_DCS_POINT_MAX+1][KMTAPI_BUF_128_LEN+1];

	tagTDCSWbDelPicOperInfo_Api() { memset(this, 0, sizeof(tagTDCSWbDelPicOperInfo_Api)); }

}*PTDCSWbDelPicOperInfo_Api, TDCSWbDelPicOperInfo_Api;













// ����ͼƬ�ļ�����Ϣ
// typedef struct tagTDCSWbSendImgFileInfo_Api
// {
// 	u32	 dwFileSize;          // �ļ���С
// 	s8 	 achFileId[KMTAPI_BUF_128_LEN+1];       // ͼƬ�ļ�id����ͼƬͼԪid��
// 	s8 	 achFileName[KMTAPI_BUF_512_LEN+1];    // �ļ�����·����utf8���룩
// 
// 	tagTDCSWbSendImgFileInfo_Api() { memset(this, 0, sizeof(tagTDCSWbSendImgFileInfo_Api)); }
// 
// }*PTDCSWbSendImgFileInfo_Api, TDCSWbSendImgFileInfo_Api;

typedef struct tagTDCSOperNtf_Api
{
	EmDcsOper_Api emOper;
	u32 		 dwMsgId;
	s8			achTabId[KMTAPI_BUF_64_LEN+1];
	u32 		 dwWbPageId;

	tagTDCSOperNtf_Api() { memset(this, 0, sizeof(tagTDCSOperNtf_Api)); }

}*PTDCSOperNtf_Api, TDCSOperNtf_Api;

typedef struct tagTDCSConnectResult_Api
{
	BOOL32 		bSuccess;
	EmDcsConnectErrCode_Api		emErrorCode;

	tagTDCSConnectResult_Api() { memset(this, 0, sizeof(tagTDCSConnectResult_Api)); }

}*PTDCSConnectResult_Api, TDCSConnectResult_Api;


typedef struct tagTDCSImageUrl_Api
{
	s8			achConfE164[KMTAPI_BUF_64_LEN+1];
	s8			achTabId[KMTAPI_BUF_64_LEN+1];
	u32			dwPageId;
	s8			achPicUrl[KMTAPI_BUF_256_LEN+1];
	s8			achWbPicentityId[KMTAPI_BUF_64_LEN+1];		// ͼƬID

	tagTDCSImageUrl_Api() { memset(this, 0, sizeof(tagTDCSImageUrl_Api)); }

}*PTDCSImageUrl_Api, TDCSImageUrl_Api;

typedef struct tagTDCSFileLoadResult_Api
{
    BOOL32		bSuccess;
    BOOL32		bElementFile;
    s8          achFilePathName[KMTAPI_BUF_512_LEN+1];
	s8			achWbPicentityId[KMTAPI_BUF_64_LEN+1];
	s8			achTabid[KMTAPI_BUF_64_LEN+1];

    tagTDCSFileLoadResult_Api() { memset( this, 0, sizeof( tagTDCSFileLoadResult_Api ) ); }

}*PTDCSFileLoadResult_Api, TDCSFileLoadResult_Api;

//�û�����Ϣ
typedef struct tagTMTUserDomainInfo_Api
{
    s8  achMoid[KMTAPI_BUF_64_LEN + 1];         ///< �û���moid
    s8  achName[KMTAPI_BUF_128_LEN + 1];        ///< �û�������
    s8  achGroupName[KMTAPI_BUF_128_LEN + 1];   ///< ��������
    s8  achParentId[KMTAPI_BUF_64_LEN+1];       ///< ���û����moid����ֵ������
    u32 dwVersion;                              ///< �汾��

    tagTMTUserDomainInfo_Api() { memset( this, 0, sizeof( tagTMTUserDomainInfo_Api ) ); }

}*PTMTUserDomainInfo_Api, TMTUserDomainInfo_Api;

typedef struct tagTMTUserDomains_Api
{
    u32 dwCount;                                           ///< atUserDomain�����������
    TMTUserDomainInfo_Api atUserDomain[KMTAPI_COUNT_16];   ///< �û�����Ϣ

    tagTMTUserDomains_Api() { memset( this, 0, sizeof( tagTMTUserDomains_Api ) ); }

}*PTMTUserDomains_Api, TMTUserDomains_Api;

//�û�������Ϣ
typedef struct tagTMTUserDomainDepartmentInfo_Api
{
    s8      achMoid[KMTAPI_BUF_64_LEN + 1];             ///< ����moid
    u32     dwDepartmentId;                             ///< ����ID
    s8      achDepartmentName[KMTAPI_BUF_128_LEN + 1];  ///< ��������
    u32     dwParentId;                                 ///< ���ڵ�Ĳ���ID
    BOOL32  bLeaf;                                      ///< �Ƿ����ӽڵ㣺ture��û�У�false����

    tagTMTUserDomainDepartmentInfo_Api() { memset( this, 0, sizeof( tagTMTUserDomainDepartmentInfo_Api ) ); }

}*PTMTUserDomainDepartmentInfo_Api, TMTUserDomainDepartmentInfo_Api;

//�û�������Ϣ����
typedef struct tagTMTUserDomainDepartments_Api
{
    u32 dwCount;                                                     ///< atUserDomainDept�����������
    TMTUserDomainDepartmentInfo_Api atUserDomainDept[KMTAPI_COUNT_16];   ///< �û�������Ϣ

    tagTMTUserDomainDepartments_Api() { memset( this, 0, sizeof( tagTMTUserDomainDepartments_Api ) ); }

}*PTMTUserDomainDepartments_Api, TMTUserDomainDepartments_Api;

/** ����ָ�� */
typedef struct tagTMTOrder_Api
{
	u8	byCount;							//ָ�����
	u8  abyOrder[ KMTAPI_BUF_128_LEN + 1 ]; //ָ������  
public:
	tagTMTOrder_Api(){ memset( this ,0 ,sizeof( struct tagTMTOrder_Api ) ); }
}*PTMTOrder_Api, TMTOrder_Api;

/*���Ź���Ⱥ��*/
typedef struct tagTMTPublicGroupInfo_Api
{
    s8  achMoid[KMTAPI_BUF_64_LEN+1];				   ///< Ⱥ��moid
    s8  achName[KMTAPI_BUF_128_LEN+1];                 ///< Ⱥ������
    s8  achParentMoid[KMTAPI_BUF_64_LEN+1];			   ///< ��Ⱥ��moid
public:
    tagTMTPublicGroupInfo_Api() { memset( this, 0, sizeof(tagTMTPublicGroupInfo_Api) ); }
}*PTMTPublicGroupInfo_Api, TMTPublicGroupInfo_Api;

/*���Ź���Ⱥ��*/
typedef struct tagTMTPublicGroups_Api
{
    u32 dwGroupNum;                                          //�˺���Ϣ ����ʵ������
    TMTPublicGroupInfo_Api atGroupInfo[KMTAPI_COUNT_16];     //�˺���Ϣ
public:
    tagTMTPublicGroups_Api() { memset( this, 0, sizeof(tagTMTPublicGroups_Api) ); }
}*PTMTPublicGroups_Api, TMTPublicGroups_Api;

/*���Ź���Ⱥ����Ա��Ϣ*/
typedef struct tagMTPublicGroupUserInfo_Api
{
    s8 achMoid[KMTAPI_BUF_64_LEN+1];				 ///< �˺�moid
    s8 achJid[KMTAPI_BUF_256_LEN+1];	             ///< xmpp�˺�
    s8 achAccount[KMTAPI_BUF_128_LEN+1];	         ///< �Զ����˺�
    s8 achEmail[KMTAPI_BUF_128_LEN+1];			     ///< �����ʼ����硰sunfei@kedacom.com��
    s8 achE164[KMTAPI_BUF_64_LEN+1];	             ///< E164
    s8 achMobile[KMTAPI_BUF_64_LEN+1];               ///< ��ϵ�绰
    s8 achName[KMTAPI_BUF_128_LEN+1];                ///< ����
    s8 achGroupMoid[KMTAPI_BUF_64_LEN+1];		     ///< Ⱥ��moid
    s8 achExtNum[KMTAPI_BUF_128_LEN+1];				 ///< �ֻ�
    s8 achSeat[KMTAPI_BUF_256_LEN+1];				 ///< ��λ��
    s8 achBrief[KMTAPI_BUF_512_LEN+1];			     ///< ���
    s8 achPortrait40[KMTAPI_BUF_256_LEN+1];	         ///< �û�ͷ��40���أ�
    s8 achPortrait64[KMTAPI_BUF_256_LEN+1];          ///< �û�ͷ��64���أ�
    s8 achPortrait128[KMTAPI_BUF_256_LEN+1];         ///< �û�ͷ��64���أ�
public:
    tagMTPublicGroupUserInfo_Api() { memset(this, 0, sizeof(tagMTPublicGroupUserInfo_Api )); }
}*PTMTPublicGroupUserInfo_Api, TMTPublicGroupUserInfo_Api;

/*���Ź���Ⱥ��������Ա��Ϣ*/
typedef struct tagTMTPublicGroupUsers_Api
{
    u32 dwUserNum;                                          //��Ա��Ϣ,����ʵ������
    TMTPublicGroupUserInfo_Api atUserInfo[KMTAPI_COUNT_16]; //��Ա��Ϣ
public:
    tagTMTPublicGroupUsers_Api() { memset( this, 0, sizeof(tagTMTPublicGroupUsers_Api) ); }
}*PTMTPublicGroupUsers_Api, TMTPublicGroupUsers_Api;


typedef struct tagTMTPushSrvReq_Api
{
	s8 		achUserName[KMTAPI_BUF_64_LEN+1];		///< �û���
	s8		achPassword[KMTAPI_BUF_64_LEN+1];		///< ����
	s8		achVersion[KMTAPI_BUF_64_LEN+1];		///< �汾��
	s8		achUserMoid[KMTAPI_BUF_64_LEN+1];		///< �û�moid
	s8		achE164[KMTAPI_MAX_MT_E164_LEN+1]; 		///< E164
	s8		achMtType[KMTAPI_BUF_64_LEN+1];			///< �ƶ��ն����ͣ�PHONE/PAD��
	s8		achAliDeviceId[KMTAPI_BUF_64_LEN+1];	///< �����Ʒ�����豸��ʶ���ն����Ӱ����Ʒ������������Ƹ��ն��豸�����Ψһ��ʶ������֪ͨʱʹ�ã�
	s8		achAliAppkey[KMTAPI_BUF_64_LEN+1];		///< ����������Ӧ�õ�AppKey������֪ͨʱʹ��
	s8		achMtsysType[KMTAPI_BUF_64_LEN+1];		///< �ƶ��ն�ʹ�õĲ���ϵͳ��ANDROID��IOS��
	s8		achMtsyslan[KMTAPI_BUF_64_LEN+1];		///< �ƶ��ն�ʹ�õĲ���ϵͳ���ԣ�CHINESE��ENGLISH��
	s8		achDeviceId[KMTAPI_BUF_64_LEN+1];		///< �豸��ʶ����ͬ��alideviceid����ͬ��UPU�����ն���deviceid��
	u32		dwSrvIp;								///< ���ͷ�����IP
	s8		achJid[KMTAPI_BUF_64_LEN+1];			///< JID
public:
    tagTMTPushSrvReq_Api() { memset( this, 0, sizeof(tagTMTPushSrvReq_Api) ); }
	
}*PTMTPushSrvReq_Api, TMTPushSrvReq_Api;


typedef struct tagTMTPushSrvResult_Api
{
	BOOL32 	bSuccess;
	u32 	dwErrCode; 
	
public:
    tagTMTPushSrvResult_Api() { memset( this, 0, sizeof(tagTMTPushSrvResult_Api) ); }
	
}*PTMTPushSrvResult_Api, TMTPushSrvResult_Api;

/* ISP ͼ������Ϣ */
typedef struct tagTMTIspImgNFInfo_Api 
{
	EmNFType_Api emType;	//��������
	u8			 byValue;	//����ֵ
public:
	tagTMTIspImgNFInfo_Api() { memset( this, 0, sizeof(struct tagTMTIspImgNFInfo_Api) ); }
}*PTMTIspImgNFInfo_Api, TMTIspImgNFInfo_Api;

/* ISP ͼ�������Ϣ����ʱΪһ��u8�ֶΣ��Ժ������չ */
typedef struct tagTMTIspImgSharpnessInfo_Api 
{
	u8			 byValue;	//���ֵ
public:
	tagTMTIspImgSharpnessInfo_Api() { memset( this, 0, sizeof(struct tagTMTIspImgSharpnessInfo_Api) ); }
}*PTMTIspImgSharpnessInfo_Api, TMTIspImgSharpnessInfo_Api;

/* ISP ͼ���ع��������� */
typedef struct tagTMTIspImgExposureGain_Api
{
	EmExposureGainType_Api	emType;	//��������
	EmExposureGain_Api      emGain; //����ֵ
public:
	tagTMTIspImgExposureGain_Api() { memset( this, 0, sizeof(struct tagTMTIspImgExposureGain_Api) ); }
}*PTMTIspImgExposureGain_Api, TMTIspImgExposureGain_Api;

/* ISP ͼ���ƽ����������,�����ֶ�ģʽ */
typedef struct tagTMTIspImgWBAGainInfo_Api
{
	EmWBAGainType_Api	emType;	//��������
	u32					dwGain; //����ֵ
public:
	tagTMTIspImgWBAGainInfo_Api() { memset( this, 0, sizeof(struct tagTMTIspImgWBAGainInfo_Api) ); }
}*PTMTIspImgWBAGainInfo_Api, TMTIspImgWBAGainInfo_Api;



typedef struct tagGmTestResult_Api
{
	EmEncryptArithmetic_Api emEncrypt;
	s32 	    dwErrorCode;   //0 ����ɹ�  ����������ʧ��
	tagGmTestResult_Api() { memset(this, 0, sizeof(tagGmTestResult_Api)); }

}*PTtagGmTestResult_Api, TGmTestResult_Api;

// �����Բ����Լ�������Բ��Խ��
typedef struct tagGmAndRandomNumTest_Api
{
	u32      dwListNum;
	TGmTestResult_Api  atGmTestResult[KMTAPI_COUNT_8 + 1];

	s32  dwRandomNumTestResult;
	tagGmAndRandomNumTest_Api() { memset(this, 0, sizeof(tagGmAndRandomNumTest_Api)); }

}*PTGmAndRandomNumTest_Api, TGmAndRandomNumTest_Api;

typedef struct tagTDcsCacheElementParseResult_Api
{
    s8 achTabId[KMTAPI_BUF_64_LEN+1]; ///< ��ҳ���ڵİװ�id
    u32 dwMsgSequence;                           ///< ���һ��ͼԪ�����
    BOOL32 bParseSuccess;                        ///< �����ɹ�
    tagTDcsCacheElementParseResult_Api() { memset( this, 0, sizeof( tagTDcsCacheElementParseResult_Api ) ); }
}*PTDcsCacheElementParseResult_Api, TDcsCacheElementParseResult_Api;


typedef struct tagTMtQtAddr_Api
{ 
	BOOL32  bEnable;
	s8      achQtIp[KMTAPI_BUF_32_LEN+1];         //qt ip 
	u32     dwQtPort;                             //qt port 
	s8      achQtUserName[KMTAPI_BUF_128_LEN+1];  //qt �û���
	s8      achQtPassword[KMTAPI_BUF_128_LEN+1];  //qt ����
	tagTMtQtAddr_Api() { memset( this, 0, sizeof( tagTMtQtAddr_Api ) ); }
}*PTMtQtAddr_Api, TMtQtAddr_Api;

typedef struct TagTMtSecKeyUpdatePolicy_Api
{
	EmSecKeyUpdateMode_Api   emSecKeyUpdateMode;   //��ʱ�������Կ���ǰ�����������Կ
	u32               dwKeyUpdatePeriod;   //�೤����һ��(s)
	u32               dwKeyUpdatePackCnt;   //���ٰ�����һ��
	TagTMtSecKeyUpdatePolicy_Api() { memset( this, 0, sizeof( TagTMtSecKeyUpdatePolicy_Api ) ); }
}*PTMtSecKeyUpdatePolicy_Api,TMtSecKeyUpdatePolicy_Api;

//�����ͼ��ģʽ
typedef struct tagTMtCameraImgInfo_Api
{
	EmCameraImgMode_Api emImgMode;
public:
	tagTMtCameraImgInfo_Api() { memset( this, 0, sizeof(struct tagTMtCameraImgInfo_Api) ); }
}*PTMtCameraImgInfo_Api, TMtCameraImgInfo_Api;

//�������������ģʽ�ķ�����Ϣ
typedef struct tagTMtCameraSceneModeInfo_Api
{
	u32						dwVidIdx;		//�����No
	EmCameraSceneMode_Api	emSceneMode;	//����ģʽ
	u32						dwRet;			//���
public:
	tagTMtCameraSceneModeInfo_Api() { memset( this, 0, sizeof(struct tagTMtCameraSceneModeInfo_Api) ); }
}*PTMtCameraSceneModeInfo_Api, TMtCameraSceneModeInfo_Api;

// ���������ģʽ����
typedef struct tagTMtCameraSceneModeCapList_Api
{
	u32 dwVidIdx;						//��������
	u8	byCnt;							// �������� 
	u8	abySceneList[KMTAPI_COUNT_16];	// EmCameraSceneMode_Api
public:
	tagTMtCameraSceneModeCapList_Api() { memset( this, 0, sizeof(struct tagTMtCameraSceneModeCapList_Api) ); }
}*PTMtCameraSceneModeCapList_Api, TMtCameraSceneModeCapList_Api;

//�����ն˵�license֤����Ϣ
typedef struct tagTMtAgentLicenseInfo_Api
{
	EmLicenseKeyCheckValue_Api emCheckValue;	//֤����֤���
	EmVersionType_Api          emVerType;		//�汾����
	EmMtModel_Api			   emMtModel;		//�豸�ͺ�
	BOOL32					   bChannelAccess;	//������Ȩ
	BOOL32					   bHybridcloudAccess;	//����Ƶ�¼��Ȩ
	BOOL32					   bPubliccloudAccess;	//�����Ƶ�½��Ȩ
	s8			achMtDeviceId[KMTAPI_BUF_128_LEN];  //�豸���к�
	s8			achUserType[KMTAPI_BUF_128_LEN];            //�û�����
	s8			achContractNode[KMTAPI_BUF_128_LEN];        //��ͬ��
	s8			achCustomerName[KMTAPI_BUF_128_LEN];        //�ͻ�����
	s8			achCustomerAddress[KMTAPI_BUF_128_LEN];     //�ͻ���ַ
	s8			achSerler[KMTAPI_BUF_128_LEN];				//������Ա
	s8			achDescription[KMTAPI_BUF_128_LEN];			//��ע

public:
	tagTMtAgentLicenseInfo_Api() { memset( this, 0, sizeof(struct tagTMtAgentLicenseInfo_Api) ); }
}*PTMtAgentLicenseInfo_Api, TMtAgentLicenseInfo_Api;

/** VGA���ͼ����� */	
typedef struct tagTMTVgaImgOutAdjustCfg_Api
{
	s32 nVga1ImgOffset; 	   ///<VGA1ͼ��ƫ��
	s32 nVga2ImgOffset; 	   ///<VGA2ͼ��ƫ��
public:
	tagTMTVgaImgOutAdjustCfg_Api() { memset( this, 0, sizeof(*this)); }
}*PTMTVgaImgOutAdjustCfg_Api, TMTVgaImgOutAdjustCfg_Api;

typedef struct tagTMtcLoginParam_Api
{
	EmClientAppType_Api   emAppType;
	EmAuthType_Api        emAuthMode;
	s8                    achUsrName[KMTAPI_BUF_32_LEN+1];  
	s8                    achPwd[KMTAPI_BUF_64_LEN+1];
	s8                    achMtIp[KMTAPI_BUF_32_LEN+1];
	u16                   wMtListenPort;
public:
	tagTMtcLoginParam_Api()
	{
		memset( this, 0, sizeof(struct tagTMtcLoginParam_Api) );
		
		emAuthMode = emAuthEnd_Api;
		emAppType = emClientAppMTCEnd_Api;
		wMtListenPort = KMTAPI_MT_LISTEN_PORT;
	}

}*PTMtcLoginParam_Api,TMtcLoginParam_Api;

//Mtc��Ϣ�б�
typedef struct tagTMtcBaseInfoList_Api 
{
	TMtcBaseInfo_Api atMtcList[KMTAPI_COUNT_16];
	u8				 byCnt;
public:
	tagTMtcBaseInfoList_Api() { memset( this, 0, sizeof(struct tagTMtcBaseInfoList_Api) ); }
}*PTMtcBaseInfoList_Api, TMtcBaseInfoList_Api;

////�ն˰汾��Ϣ
typedef struct tagTMtVersionInfo_Api
{
	s8              achMtIp[KMTAPI_BUF_128_LEN+1];      //�ն�ip
	s8				achVersion[KMTAPI_BUF_128_LEN+1];   ///�ն˰汾 
	EmMtModel_Api	emModel;						    ///�ն��ͺ�
	BOOL32			bIsSupportSec;					    ///�Ƿ�֧������ 
	
	TMtcBaseInfoList_Api tMtcList;						//mtc��Ϣ�б�
public:
	tagTMtVersionInfo_Api() { memset( this, 0, sizeof(struct tagTMtVersionInfo_Api) ); }
}*PTMtVersionInfo_Api, TMtVersionInfo_Api;


typedef struct tagTServerLoginPort
{
    u32 dwHttpPort;      //httpЭ��˿�
    u32 dwHttpsPort;     //httpsЭ��˿�
    tagTServerLoginPort()
	{ 
		dwHttpPort  = 60080;
		dwHttpsPort = 60090;
	}
}*PTServerLoinPort, TServerLoginPort_Api;

// ����������ɼ���ʽ
typedef struct tagTCameraVidStd_Api
{
	EmCameraVidStd_Api emVidType;    
	s8                 achVidName[128+1];    
	tagTCameraVidStd_Api(){ memset(this, 0, sizeof(tagTCameraVidStd_Api)); }
}*PTCameraVidStd_Api, TCameraVidStd_Api;


//srtp�����ϱ�
typedef struct TagTMtSrtpCrypto_Api
{
	EmSrtpCryptoType_Api emSrtpCryptoType;    ///��Կ����
	EmSrtpAuthType_Api emSrtpAuthType;        ///��Կ����
	u32 dwSrtpTag;                            ///tagֵ
	s8  achCryptoKey[KMTAPI_BUF_64_LEN+1];    ///��Կkeyֵ
	s8  achCryptoKeyId[KMTAPI_BUF_64_LEN+1];  ///˽Կkeyid
	u32 dwCryptoKeyIdLen;                     ///keyid����
	s8  achBkRtcpCryptoKey[KMTAPI_BUF_64_LEN+1]; //bkrtcp key 

	TagTMtSrtpCrypto_Api(){ memset(this,0,sizeof(TagTMtSrtpCrypto_Api)); }
}*PTMtSrtpCrypto_Api,TMtSrtpCrypto_Api;

typedef struct tagTAgentLogFileInfo_Api
{
    s8  achFileName[KMTAPI_BUF_64_LEN+1];  //ѹ���ļ�����
    s8  achFilePath[KMTAPI_BUF_128_LEN+1]; //�ļ�·����б�ܽ�β��/xxx/xxx/��
    tagTAgentLogFileInfo_Api(){ memset(this, 0, sizeof(tagTAgentLogFileInfo_Api)); }
}*PTAgentLogFileInfo_Api, TAgentLogFileInfo_Api;

//Ͷ����״̬��Ϣ
typedef struct tagTMtQkState_Api
{
	u32             dwQkId;		//Ͷ�������
	EmQkState_Api	emState;    //״̬
	s8				achPcName[KMTAPI_BUF_128_LEN+1];   //Pc����
	s8				achQkVer[KMTAPI_BUF_128_LEN+1];    //�汾
	tagTMtQkState_Api(){ memset( this,0,sizeof(tagTMtQkState_Api) ); }
}*PTMtQkState_Api, TMtQkState_Api;

typedef struct tagTAgentPackFileState_Api
{
    EmAgentPackFileState_Api emPackState;
public:
    tagTAgentPackFileState_Api(){ memset(this, 0, sizeof(tagTAgentPackFileState_Api)); }
}*PTAgentPackFileState_Api, TAgentPackFileState_Api;

//�Ƿ�β�����uk���ؽ��
typedef struct TagTMtQtUk_Api
{	u16    wRes;                      ///1��ʾ���ڣ� 0��ʾ������
	BOOL32 bPull;                     ///�Ƿ���uk 1��ʾ��uk
	TagTMtQtUk_Api(){ memset(this,0,sizeof(TagTMtQtUk_Api)); }
}*PTMtQtUk_Api,TMtQtUk_Api;

//��˷�״̬
typedef struct tagTAgentMicStatus_Api
{
	s8     achName[KMTAPI_BUF_16_LEN+1]; //��˷�����
	BOOL32 bStatus;         //��˷�״̬��TRUE-������FALSE-�쳣
public:
	tagTAgentMicStatus_Api(){ memset( this, 0, sizeof(tagTAgentMicStatus_Api) );}
}*PTAgentMicStatus_Api, TAgentMicStatus_Api;

//������״̬
typedef struct tagTAgentLoudspeakerStatus_Api
{
	s8     achName[KMTAPI_BUF_16_LEN+1]; //����������
	BOOL32 bStatus;                      //������״̬��TRUE-������FALSE-�쳣
public:
	tagTAgentLoudspeakerStatus_Api(){ memset( this, 0, sizeof(tagTAgentLoudspeakerStatus_Api) );}
}*PTAgentLoudspeakerStatus_Api, TAgentLoudspeakerStatus_Api;

//�����ܣ��ն������Ϣ
typedef struct tagTAgentDevicePFMInfo_Api
{
	u32 dwCpuUseRate;      //cpuʹ�ðٷֱ�
	u32 dwMicNum;   //��˷�atMicDeviceInfo�����С
	TAgentMicStatus_Api atMicDeviceInfo[KMTAPI_MAX_NUM_5]; //��˷�״̬
	u32 dwLoudspeakerNum; //������atLoudspeakerInfo�����С
	TAgentLoudspeakerStatus_Api atLoudspeakerInfo[KMTAPI_MAX_NUM_5]; //������״̬
public:
	tagTAgentDevicePFMInfo_Api(){ memset(this, 0, sizeof(tagTAgentDevicePFMInfo_Api)); }
}*PTAgentDevicePFMInfo_Api, TAgentDevicePFMInfo_Api;

typedef struct TagTMtSecAdateCreatRes_Api
{
	s8      achQtServerSockPath[KMTAPI_BUF_128_LEN+1];  
	BOOL32  bSuccess;
	u16     wTestQtDeviceRes;
	TagTMtSecAdateCreatRes_Api() { memset( this, 0, sizeof( TagTMtSecAdateCreatRes_Api ) ); }
}*PTMtSecAdateCreatRes_Api,TMtSecAdateCreatRes_Api;

//����ӵ�ɾ�����Ӱװ�ʱ֪ͨ��᷽ʱʹ��
typedef struct tagTDCSDelWhiteBoardInfo_Api
{
    s8					achConfE164[KMTAPI_BUF_64_LEN+1];
    s8                  achTabId[KMTAPI_BUF_64_LEN+1];
    s8                  achFromE164[KMTAPI_BUF_64_LEN+1];	
    tagTDCSDelWhiteBoardInfo_Api() { memset(this, 0, sizeof(tagTDCSDelWhiteBoardInfo_Api)); }

}*PTDCSDelWhiteBoardInfo_Api, TDCSDelWhiteBoardInfo_Api;

typedef struct tagTPlatformInfo_Api
{
    s8      achVersion[KMTAPI_BUF_32_LEN+1];    //ƽ̨�汾��
    u32     dwIP;                               //��ǰ��¼��ƽ̨IP
    EmResourceType_Api emResourceType;
    tagTPlatformInfo_Api() { memset(this, 0, sizeof(tagTPlatformInfo_Api)); }
}*PTPlatformInfo, TPlatformInfo_Api;

/** һ·����״̬ */
typedef struct tagTAssVidStatus_Api
{
	EmMtChanState_Api   emChanState;     ///< TRUE, ��ǰ�ն��и����� FLASE, ��ǰû�и���
	EmMtVidLabel_Api    emVidLab;        ///< ������vid��ǩ
	BOOL32              bActive;         ///< ��ͨ��Ϊ����ͨ�����Ż��õ�,��ʶ���ͷ��Ƿ񼤻�ͨ��
	TMtcBaseInfo_Api    tPcAssSrc;       ///< ��˫��Դ

public:
	tagTAssVidStatus_Api()
	{ 
		emChanState = emChanIdle_Api;
		emVidLab    = emVidLabBegin_Api;
		bActive     = FALSE;
	}
}*PTAssVidStatus_Api, TAssVidStatus_Api;

/** ��ǰ�ĸ���Ƶ�������,��ʱ�õ�һ· */
typedef struct tagTMtAssVidStatusList_Api
{
	TAssVidStatus_Api  arrTAssVidStatus[KMTAPI_MAX_CONF_ASSVID_CHANNEL_NUM];  ///< ��·����״̬(����or����)
	u8                 byCnt;                                                                                                    ///< ʵ��·��
public:
	tagTMtAssVidStatusList_Api(){ byCnt = 0; }
}*PTMtAssVidStatusList_Api, TMtAssVidStatusList_Api;


typedef struct tagTMtShowAndPlayAud_Api
{
	s8 achShowAud[KMTAPI_BUF_256_LEN+1];    ///< aiҪչʾ����Ƶ����
	s8 achPlayAud[KMTAPI_BUF_256_LEN+1];     ///< aiҪ���ŵ���Ƶ
public:
	tagTMtShowAndPlayAud_Api(){ memset( this, 0, sizeof(tagTMtShowAndPlayAud_Api) );}
}*PTMtShowAndPlayAud_Api, TMtShowAndPlayAud_Api;


typedef struct tagTMtAiJoinConfInfo_Api
{
	TMtShowAndPlayAud_Api tShowAndPlayAud;
	TMtJoinConfParam_Api atJoinConfParam[KMTAPI_MAX_AISHOW_LIST_NUM];
	u8  byCnt;
public:
	tagTMtAiJoinConfInfo_Api(){ memset( this, 0, sizeof(tagTMtAiJoinConfInfo_Api) );}
}*PTMtAiJoinConfInfo_Api, TMtAiJoinConfInfo_Api;

typedef struct tagTMtInviteInfo_Api
{
	s8      achInviteE164[KMTAPI_MAX_CONF_E164_LEN+1]; ///< ����
	s8      achInviteName[KMTAPI_MAX_CONF_NAME_LEN+1];    ///< ����
	s8      achInviteIp[KMTAPI_BUF_32_LEN+1]; ///< ip
	EmAiContactType_Api emAiContactType;   //��ϵ������
public:
	tagTMtInviteInfo_Api(){ memset( this, 0, sizeof(tagTMtInviteInfo_Api) );}
}*PTMtInviteInfo_Api, TMtInviteInfo_Api;


typedef struct tagTMtAiInviteParam_Api
{
	TMtShowAndPlayAud_Api tShowAndPlayAud;
	TMtInviteInfo_Api atInviteInfo[KMTAPI_MAX_AISHOW_LIST_NUM];
	u8  byCnt;
public:
	tagTMtAiInviteParam_Api(){ memset( this, 0, sizeof(tagTMtAiInviteParam_Api) );}
}*PTMtAiInviteParam_Api, TMtAiInviteParam_Api;


typedef struct tagTMtAiSelectParam_Api
{
	TMtShowAndPlayAud_Api tShowAndPlayAud;
	EmAiActionState_Api emAiActionState;
	u32  dwIndex; 
public:
	tagTMtAiSelectParam_Api(){ memset( this, 0, sizeof(tagTMtAiSelectParam_Api) );}
}*PTMtAiSelectParam_Api, TMtAiSelectParam_Api;

typedef struct tagTMtAiAssParam_Api
{
	TMtShowAndPlayAud_Api tShowAndPlayAud;
	EmAiAssState_Api emAiAssState; 
public:
	tagTMtAiAssParam_Api(){ memset( this, 0, sizeof(tagTMtAiAssParam_Api) );}
}*PTMtAiAssParam_Api, TMtAiAssParam_Api;


typedef struct tagTMtAiSureOrNotParam_Api
{
	TMtShowAndPlayAud_Api tShowAndPlayAud;
	EmAiActionState_Api emAiActionState;
	BOOL32  bSure; 
public:
	tagTMtAiSureOrNotParam_Api(){ memset( this, 0, sizeof(tagTMtAiSureOrNotParam_Api) );}
}*PTMtAiSureOrNotParam_Api, TMtAiSureOrNotParam_Api;

typedef struct tagTMtAiVoiceParam_Api
{
	TMtShowAndPlayAud_Api tShowAndPlayAud;
	BOOL32  bUp;                   //�����ǵ�С 
public:
	tagTMtAiVoiceParam_Api(){ memset( this, 0, sizeof(tagTMtAiVoiceParam_Api) );}
}*PTMtAiVoiceParam_Api, TMtAiVoiceParam_Api;

typedef struct tagTMtAiSelectViewParam_Api
{
	TMtShowAndPlayAud_Api tShowAndPlayAud;
	BOOL32 bExist;
	TMtId_Api tMtId; 
	BOOL32 bSelectView;
public:
	tagTMtAiSelectViewParam_Api(){ memset( this, 0, sizeof(tagTMtAiSelectViewParam_Api) );}
}*PTMtAiSelectViewParam_Api, TMtAiSelectViewParam_Api;


typedef struct tagTMtCameraLastPos_Api
{
	BOOL32		bUse;					////<�Ƿ������ϴιػ�ǰλ��.�����ˣ�����仯
	s32			nPosX;					////<x����
	s32			nPosY;					////<y����
	s32			nType;					////<0�ϴιػ�ǰλ�� 1Ĭ��λ�� 2��һ��Ԥ��λ
public:
	tagTMtCameraLastPos_Api(){ memset( this, 0, sizeof(tagTMtCameraLastPos_Api) );}
}*PTMtCameraLastPos_Api, TMtCameraLastPos_Api;



/** ai��Ϣ���� */
typedef struct tagTMtAiInfoCfg_Api
{
	BOOL32 bUsedVoiceAide;             ///< �Ƿ�ʹ����������
	BOOL32 bUsedCountOfPeople;         ///< �Ƿ�ʹ������ͳ��
	BOOL32 bUsedFaceSign;              ///< �Ƿ�ʹ������ǩ��
	BOOL32 bUsedElectNameplate;        ///< �Ƿ�ʹ�õ�������
public:
	tagTMtAiInfoCfg_Api(){ memset( this ,0 ,sizeof( struct  tagTMtAiInfoCfg_Api ) );}
}*PTMtAiInfoCfg_Api, TMtAiInfoCfg_Api;

///<�Ӵ������Ƕ�����й�AICameraģ��Ľṹ��
typedef struct tagTMtHDCameraAiCfg_Api
{
	u32  dwVideoIndex;							 ///<����
	u32  dwIp;									///<�������IP��ַ
	u32  dwPort;							    ///<���Ӷ˿�
public:
	tagTMtHDCameraAiCfg_Api(){ memset( this ,0 ,sizeof( struct  tagTMtHDCameraAiCfg_Api ) );}
}*PTMtHDCameraAiCfg_Api, TMtHDCameraAiCfg_Api;

/** �����AI�����б� */
typedef struct tagTMtHDCameraAiList_Api
{
	u32					 dwCameraAiNum;
	TMtHDCameraAiCfg_Api atAiCameraList[KMTAPI_BUF_32_LEN+1]; 
public:
	tagTMtHDCameraAiList_Api(){ memset( this ,0 ,sizeof( struct  tagTMtHDCameraAiList_Api ) );}
}*PTMtHDCameraAiList_Api, TMtHDCameraAiList_Api;

///<����ͳ��
typedef struct tagTMtPeopleCountingResult_Api
{
	u32					 dwVideoIndex; //<����
	u32					 dwPeopleNum; //<����ͳ�ƽ��
public:
	tagTMtPeopleCountingResult_Api(){ memset( this ,0 ,sizeof( struct  tagTMtPeopleCountingResult_Api ) );}
}*PTMtPeopleCountingResult_Api, TMtPeopleCountingResult_Api;

///<������Ϣ
typedef struct tagTMtFaceCheckInInfo_Api
{
	s8					 achName[KMTAPI_BUF_32_LEN+1]; ///<����
	s8					 achTime[KMTAPI_BUF_32_LEN+1]; ///<ʱ��
	s8					 achPosition[KMTAPI_BUF_32_LEN+1];///<Ա��ְλ
public:
	tagTMtFaceCheckInInfo_Api(){ memset( this ,0 ,sizeof( struct  tagTMtFaceCheckInInfo_Api ) );}
}*PTMtFaceCheckInInfo_Api, TMtFaceCheckInInfo_Api;

///<����ǩ��֪ͨ��Ϣ
typedef struct tagTMtFaceCheckInList_Api
{
	u32					 dwVideoIndex; ///<����
	u32					 dwFaceCheckNum; ///<����ǩ������
	TMtFaceCheckInInfo_Api atFaceCheckInfoList[KMTAPI_BUF_32_LEN+1]; ///<����ǩ��֪ͨ��Ϣ�б�
public:
	tagTMtFaceCheckInList_Api(){ memset( this ,0 ,sizeof( struct  tagTMtFaceCheckInList_Api ) );}
}*PTMtFaceCheckInList_Api, TMtFaceCheckInList_Api;

//osd��ݼ�����
typedef struct tagTMtShortCutKey_Api
{
	EmShortCutKeyType_Api emKeyType;	////< ��ݼ�����
	EmShortCutKeyFuc_Api  emKeyFuc;		////< ��ݼ�����
public:
	tagTMtShortCutKey_Api(){ memset( this, 0, sizeof(tagTMtShortCutKey_Api) );}
}*PTMtTMtShortCutKey_Api, TMtShortCutKey_Api;

typedef struct tagTMtShortCutKeyList_Api
{
	TMtShortCutKey_Api atShortCutKey[KMTAPI_COUNT_4];
	u8 byCnt;
public:
	tagTMtShortCutKeyList_Api(){ memset( this, 0, sizeof(tagTMtShortCutKeyList_Api) );}
}*PTMtShortCutKeyList_Api, TMtShortCutKeyList_Api;


/**@}*/

/**@}*/
#endif //!_MTAPI_STRUCT_H_

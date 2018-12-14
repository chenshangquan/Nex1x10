/*******************************************************************************//**
*@file          mtapi_event_dcs.h
*@brief         ʵ��MTAPI MtDcsSdk ��UI(�۲���)�¼�֪ͨ�Ķ���
*
*@author        wangfeifei
*@version       5.0    
*@date          20150328
*@copyright     (c)1995-2015 Suzhou Keda Technology Co.,Ltd. All rights reserved
***********************************************************************************/
#ifndef _MTAPI_EVENT_DCS_H_
#define _MTAPI_EVENT_DCS_H_
/**@addtogroup event �¼���ص�
*@{
*/

/**@addtogroup dcsevent ���Ӱװ��¼�
*@{
*/

#include "mtapi_event_def.h"

enum EmMtApiDCSEv
{
	EV_UI_BGN(MTAPI_DCS)  = EVSEG_MTAPI_DCS_BGN,

	
/**
  @brief    ��¼���Ӱװ��������Ӧ
  
	MainBuf(#TDCSResult_Api) \n
	Json��ʽ���£�
	{
		"bSucces" : true,
		"dwErrorCode" : 0,
		"achConfE164" : ""
	}
*/
	Ev_MtApi_DcsLoginSrv_Rsp,

	
/**
  @brief    �ǳ����Ӱװ��������Ӧ
  
	MainBuf(#TDCSResult_Api) \n
	Json��ʽ���£�
		{
		"bSucces" : true,
		"dwErrorCode" : 0,
		"achConfE164" : ""
	}
*/
	Ev_MtApi_DcsLogout_Rsp,

/**
  @brief    ���������е��Ӱװ���Ӧ
  
	MainBuf(#TDCSCreateConfResult_Api) \n
	Json��ʽ���£�
	{
		"achConfE164" : "",
		"achConfName" : "",
		"bSuccess" : true,
		"dwErrorCode" : 0,
		"emConfMode" : 0,
		"emConfType" : 0,
		"tConfAddr" : {
			"achIp" : "",
			"achDomain" : "",
			"dwPort" : 0
		}
	}
*/
	Ev_MtApi_DcsCreateConf_Rsp,



/**
  @brief    ��ȡ���Ӱװ������Ϣ������������ṹ��
  
	MainBuf(#TDCSCreateConfResult_Api) \n
	Json��ʽ���£�
	{
		"achConfE164" : "",
		"achConfName" : "",
		"bSuccess" : true,
		"dwErrorCode" : 0,
		"emConfMode" : 0,
		"emConfType" : 0,
		"tConfAddr" : {
			"achIp" : "",
			"achDomain" : "",
			"dwPort" : 0
		}
	}
*/
	Ev_MtApi_DcsGetConfInfo_Rsp, 
	
/**
  @brief    ��ȡ���Ӱװ������Ϣ������������ṹ��
  
	MainBuf(#TDCSCreateConfResult_Api) \n
	Json��ʽ���£�
	{
		"achConfE164" : "",
		"achConfName" : "",
		"bSuccess" : true,
		"dwErrorCode" : 0,
		"emConfMode" : 0,
		"emConfType" : 0,
		"tConfAddr" : {
			"achIp" : "",
			"achDomain" : "",
			"dwPort" : 0
		}
	}
*/
	Ev_MtApi_DcsGetConfInfo_Ntf, 	
/**
  @brief    �����û�
  
	MainBuf(#TDCSInviteUsr_Api) \n
	Json��ʽ���£�
	{
		"achConfE164" : "",
		"tConfAddr" : {
			"achIp" : "",
			"achDomain" : "",
			"dwPort" : 0	
		}
	}
*/
//	Ev_MtApi_DcsInviteUser_Cmd,
	
/**
  @brief    ��ȡ�����ַ������Ӧ
  
	MainBuf(#TDCSResult_Api) \n
	SubBuf(#TDCSConfAddr_Api)  ���ɹ��ŷ���
	Json��ʽ���£�
	{
		"MainParam":
		{
			"bSucces" : true,
			"dwErrorCode" : 0,
			"achConfE164" : ""
		}
		"AssParam":
		{
			"achIp" : "",
			"achDomain" : "",
			"dwPort" : 0	
		}
	}
*/
//	Ev_MtApi_DcsGetConfAddr_Rsp,


/**
  @brief    ������Ӱװ������Ӧ
  
	MainBuf(#TDCSJoinConfResult_Api) \n
	Json��ʽ���£�
	{
		"achConfE164" : "',
		"achConfName" : "",
		"emConfMode" : 0,
		"emConfType" : 0,
		"bSuccess" : false;
		"dwErrorCode" : 0,
		"bIsOper" : false;
		"bIsConfAdmin" : false
	}
*/	
//	Ev_MtApi_DcsJoinConf_Rsp,
	

/**
  @brief    �˳����Ӱװ������Ӧ
  
	MainBuf(#TDCSResult_Api) \n
	Json��ʽ���£�
	{
		"bSucces" : true,
		"dwErrorCode" : 0,
		"achConfE164" : ""
	}
*/	
	Ev_MtApi_DcsQuitConf_Rsp,
	
/**
  @brief    �������Ӱװ������Ӧ
  
	MainBuf(#TDCSResult_Api) \n
	Json��ʽ���£�
	{
		"bSucces" : true,
		"dwErrorCode" : 0,
		"achConfE164" : ""
	}
*/	
	Ev_MtApi_DcsReleaseConf_Rsp,
	
	
/**
  @brief    ��ӳ�Ա��Ӧ
  
	MainBuf(#TDCSResult_Api) \n
	Json��ʽ���£�
	{
		"bSucces" : true,
		"dwErrorCode" : 0,
		"achConfE164" : ""
	}
*/	
	Ev_MtApi_DcsAddMember_Rsp,
	
	
/**
  @brief    ɾ����Ա��Ӧ
  
	MainBuf(#TDCSResult_Api) \n
	Json��ʽ���£�
	{
		"bSucces" : true,
		"dwErrorCode" : 0,
		"achConfE164" : ""
	}
*/	
	Ev_MtApi_DcsDelMember_Rsp,
	
/**
  @brief    ���û�����Ϣ��Ӧ
  
	MainBuf(#TDCSSetConfInfoResult_Api) \n
	Json��ʽ���£�
	{
		"bSucces" : false;
		"dwErrorCode" : 0,
		"achConfE164" : "",
		"achConfName" : "",
		"emConfMode" : 0,
		"emConfType" : 0
	}
*/
	Ev_MtApi_DcsSetConfInfo_Rsp,
	
	
/**
  @brief    ���ó�Ա��ɫ��Ϣ֪ͨ
  
	MainBuf(#TDCSResult_Api) \n
	Json��ʽ���£�
	{
		"bSucces" : true,
		"dwErrorCode" : 0,
		"achConfE164" : ""
	}
*/
//	Ev_MtApi_DcsSetUserRole_Ntf,

/**
  @brief    ���Э������Ӧ
  
	MainBuf(#TDCSResult_Api) \n
	Json��ʽ���£�
	{
		"bSucces" : true,
		"dwErrorCode" : 0,
		"achConfE164" : ""
	}
*/
	Ev_MtApi_DcsAddOperator_Rsp,


/**
  @brief    ɾ��Э������Ӧ
  
	MainBuf(#TDCSResult_Api) \n
	Json��ʽ���£�
	{
		"bSucces" : true,
		"dwErrorCode" : 0,
		"achConfE164" : ""
	}
*/
	Ev_MtApi_DcsDelOperator_Rsp,

/**
  @brief    ����Э������Ӧ
  
	MainBuf(#TDCSResult_Api) \n
	Json��ʽ���£�
	{
		"bSucces" : true,
		"dwErrorCode" : 0,
		"achConfE164" : ""
	}
*/
	Ev_MtApi_DcsApplyOper_Rsp,
	
	
/**
  @brief    ȡ��Э������Ӧ
  
	MainBuf(#TDCSResult_Api) \n
	Json��ʽ���£�
	{
		"bSucces" : true,
		"dwErrorCode" : 0,
		"achConfE164" : ""
	}
*/
	Ev_MtApi_DcsCancelOper_Rsp,
	
	
/**
  @brief    ��ȡ�û��б�֪ͨ
  
	MainBuf(#TDCSResult_Api) \n
	SubBuf(#TDCSGetUserList_Api)  ���ɹ��ŷ���
	Json��ʽ���£�
	{
		"MainParam":
		{
			"bSucces" : true,
			"dwErrorCode" : 0,
			"achConfE164" : ""
		}
		"AssParam":
		{
			"dwListNum" : 0,
			"atUserList" : [
				"achE164" : "",
				"achName" : "",
				"emMttype" : 0,
				"bOnline" : false;
				"bIsOper" : false;
				"bIsConfAdmin" : false
			]
		}
	}
*/
	Ev_MtApi_DcsGetUserList_Rsp,
	
	
	
/**
  @brief    �����װ�֪ͨ
  
	MainBuf(#TDCSBoardResult_Api) \n
	SubBuf(#TDCSBoardInfo_Api)  ���ɹ��ŷ���
	Json��ʽ���£�
	{
		"MainParam":
		{
			"bSucces" : false;
			"dwErrorCode" : 0,
			"achConfE164" : "",
			"achTabId" : "",
			"dwPageId" : 0
		}
		"AssParam":
		{
			"achWbName" : "",
			"emWbMode" : 0,
			"dwWbPageNum" : 0,
			"dwWbCreateTime" : 0,
			"achTabId" : "",
			"dwPageId" : 0,
			"achWbCreatorE164" : "",
			"dwWbWidth" : 0,
			"dwWbHeight" : 0,
			"achElementUrl" : "",
			"achDownloadUrl" : "",
			"achUploadUrl" : "",
			"dwWbAnonyId" : 0
		}
	}
*/
	Ev_MtApi_DcsNewWhiteBoard_Rsp,

	
/**
  @brief    ɾ���װ�֪ͨ
  
	MainBuf(#TDCSBoardResult_Api) \n
	Json��ʽ���£�
	{
		"bSucces" : false;
		"dwErrorCode" : 0,
		"achConfE164" : "",
		"achTabId" : "",
		"dwPageId" : 0
	}
*/
	Ev_MtApi_DcsDelWhiteBoard_Rsp,
	

/**
  @brief    ɾ�����аװ�֪ͨ
  
	MainBuf(#TDCSBoardResult_Api) \n
	Json��ʽ���£�
	{
		"bSucces" : false;
		"dwErrorCode" : 0,
		"achConfE164" : "",
		"achTabId" : "",
		"dwPageId" : 0
	}
*/
	Ev_MtApi_DcsDelAllWhiteBoard_Rsp,

/**
  @brief    ��ȡ���аװ�֪ͨ
  
	MainBuf(#TDCSResult_Api) \n
	SubBuf(#TDCSGetAllBoard_Api)  ���ɹ��ŷ���
	Json��ʽ���£�
	{
		"MainParam":
		{
			"bSucces" : true,
			"dwErrorCode" : 0,
			"achConfE164" : ""
		}
		"AssParam":
		{
			"achConfE164" : "",
			"dwBoardNum" : 0,
			"atBoardInfo" : [
				"achWbName" : "",
				"emWbMode" : 0,
				"dwWbPageNum" : 0,
				"dwWbCreateTime" : 0,
				"achTabId" : "",
				"dwPageId" : 0,
				"achWbCreatorE164" : "",
				"dwWbWidth" : 0,
				"dwWbHeight" : 0,
				"achElementUrl" : "",
				"achDownloadUrl" : "",
				"achUploadUrl" : "",
				"dwWbAnonyId" : 0				
			]
		}
	}
*/
	Ev_MtApi_DcsGetAllWhiteBoard_Rsp,
	
	
/**
  @brief    ��ȡָ���װ�֪ͨ
  
	MainBuf(#TDCSBoardResult_Api) \n
	SubBuf(#TDCSBoardInfo_Api)  ���ɹ��ŷ���
	Json��ʽ���£�
	{
		"MainParam":
		{
			"bSucces" : false;
			"dwErrorCode" : 0,
			"achConfE164" : "",
			"achTabId" : "",
			"dwPageId" : 0
		}
		"AssParam":
		{
			"achWbName" : "",
			"emWbMode" : 0,
			"dwWbPageNum" : 0,
			"dwWbCreateTime" : 0,
			"achTabId" : "",
			"dwPageId" : 0,
			"achWbCreatorE164" : "",
			"dwWbWidth" : 0,
			"dwWbHeight" : 0,
			"achElementUrl" : "",
			"achDownloadUrl" : "",
			"achUploadUrl" : "",
			"dwWbAnonyId" : 0			
		}
	}
*/
	Ev_MtApi_DcsGetWhiteBoard_Rsp,
	
/**
  @brief    ��ȡ��ǰ�װ�֪ͨ
  
	MainBuf(#TDCSBoardResult_Api) \n
	SubBuf(#TDCSBoardInfo_Api)  ���ɹ��ŷ���
	Json��ʽ���£�
	{
		"MainParam":
		{
			"bSucces" : false;
			"dwErrorCode" : 0,
			"achConfE164" : "",
			"achTabId" : "",
			"dwPageId" : 0
		}
		"AssParam":
		{
			"achWbName" : "",
			"emWbMode" : 0,
			"dwWbPageNum" : 0,
			"dwWbCreateTime" : 0,
			"achTabId" : "",
			"dwPageId" : 0,
			"achWbCreatorE164" : "",
			"dwWbWidth" : 0,
			"dwWbHeight" : 0,
			"achElementUrl" : "",
			"achDownloadUrl" : "",
			"achUploadUrl" : "",
			"dwWbAnonyId" : 0			
		}
	}
*/
	Ev_MtApi_DcsGetCurWhiteBoard_Rsp,	
/**
  @brief    �л��װ���֪ͨ
  
	MainBuf(#TDCSBoardResult_Api) \n
	SubBuf(#TDCSBoardInfo_Api)  ���ɹ��ŷ���
	Json��ʽ���£�
	{
		"MainParam":
		{		
			"bSucces" : false;
			"dwErrorCode" : 0,
			"achConfE164" : "",
			"achTabId" : "",
			"dwPageId" : 0
		}
		"AssParam":
		{
			"achWbName" : "",
			"emWbMode" : 0,
			"dwWbPageNum" : 0,
			"dwWbCreateTime" : 0,
			"achTabId" : "",
			"dwPageId" : 0,
			"achWbCreatorE164" : "",
			"dwWbWidth" : 0,
			"dwWbHeight" : 0,
			"achElementUrl" : "",
			"achDownloadUrl" : "",
			"achUploadUrl" : "",
			"dwWbAnonyId" : 0
		}
	}
*/
	Ev_MtApi_DcsSwitch_Rsp,
	
	
/**
  @brief    ��Ա�������֪ͨ
  
	MainBuf(#TDCSUserInfo_Api) \n
	Json��ʽ���£�
	{
		"achConfE164" : "",
		"achConfName" : "",
		"tUserInfo" : {
			"achE164" : "",
			"achName" : "",
			"emMttype" : 0,
			"bOnline" : false,
			"bIsOper" : false,
			"bIsConfAdmin" : false
		}
	}
*/
	Ev_MtApi_DcsUserJoinConf_Ntf,
	
	
/**
  @brief    ��Ա�˳�����֪ͨ
  
	MainBuf(#TDCSUserInfo_Api) \n
	Json��ʽ���£�
	{
		"achConfE164" : "",
		"achConfName" : "",
		"tUserInfo" : {
			"achE164" : "",
			"achName" : "",
			"emMttype" : 0,
			"bOnline" : false,
			"bIsOper" : false,
			"bIsConfAdmin" : false
		}
	}
*/
	Ev_MtApi_DcsUserQuitConf_Ntf,
	
	
/**
  @brief    ��Ա��������֪ͨ
  
	MainBuf(#s8*, KMTAPI_BUF_64_LEN) \n
	Json��ʽ���£�
	{
		"strConfE164" : ""
	}
*/
	Ev_MtApi_DcsReleaseConf_Ntf,
	
	
	
/**
  @brief    ����û�ʧ��֪ͨ
  
	MainBuf(#TDCSUserInfos_Api) \n
	Json��ʽ���£�
	{
		"achConfE164" : "",
		"achConfName" : "",
		"dwListNum" : 0,
		"atUserInfoList": [
			"achE164" : "",
			"achName" : "",
			"emMttype" : 0,
			"bOnline" : false,
			"bIsOper" : false,
			"bIsConfAdmin" : false
		]
	}
*/
	Ev_MtApi_DcsAddUserFail_Ntf,
	
	
/**
  @brief    ɾ���û�ʧ��֪ͨ
  
	MainBuf(#TDCSUserInfos_Api) \n
	Json��ʽ���£�
	{
		"achConfE164" : "",
		"achConfName" : "",
		"dwListNum" : 0,
		"atUserInfoList": [
			"achE164" : "",
			"achName" : "",
			"emMttype" : 0,
			"bOnline" : false,
			"bIsOper" : false,
			"bIsConfAdmin" : false
		]
	}
*/
	Ev_MtApi_DcsDelUserFail_Ntf,
	
	
/**
  @brief    ���»�����Ϣ֪ͨ
  
	MainBuf(#TDCSConfInfo_Api) \n
	Json��ʽ���£�
	{
		"achConfE164" : "",
		"achConfName" : "",
		"emConfMode" : 0,
		"emConfType" : 0
	}
*/
	Ev_MtApi_DcsUpdateConfInfo_Ntf,
	
/**
  @brief    �����û���ɫ��Ϣ֪ͨ
  
	MainBuf(#TDCSUserRole_Api) \n
	Json��ʽ���£�
	{
		"achConfE164" : "",
		"dwListNum" : 0,
		"atUserInfoList" : [
			"achE164" : "",
			"achName" : "",
			"emMttype" : 0,
			"bOnline" : false,
			"bIsOper" : false,
			"bIsConfAdmin" : false
		]
	}
*/
//	Ev_MtApi_DcsUpdateUserRole_Ntf,
	
	
/**
  @brief    �����û���ɫʧ��֪ͨ
  
	MainBuf(#TDCSUserRole_Api) \n
	Json��ʽ���£�
*/
//	Ev_MtApi_DcsSetUserRoleFail_Ntf,
	
	
/**
  @brief    ��Ա����Э��Ȩ֪ͨ
  
	MainBuf(#TDCSUserInfo_Api) \n
	Json��ʽ���£�
	{
		"achConfE164" : "",
		"achConfName" : "",
		"tUserInfo" : {
			"achE164" : "",
			"achName" : "",
			"emMttype" : 0,
			"bOnline" : false,
			"bIsOper" : false,
			"bIsConfAdmin" : false
		}
	}
*/
	Ev_MtApi_DcsUserApplyOper_Ntf,
	

/**
  @brief    ����Э��Ȩ֪ͨ
  
	MainBuf(#s8, KMTAPI_BUF_64_LEN) \n
	Json��ʽ���£�
	{
		"strConfE164" : ""
	}
*/
//	Ev_MtApi_DcsSpecOper_Ntf,
	
	
/**
  @brief    ��Աȡ��Э��Ȩ֪ͨ
  
	MainBuf(#s8, KMTAPI_BUF_64_LEN) \n
	Json��ʽ���£�
	{
		"strConfE164" : ""
	}
*/
//	Ev_MtApi_DcsCancelOper_Ntf,
	

/**
  @brief    ��Ա�����°װ�֪ͨ
  
	MainBuf(#TDCSBoardInfo_Api) \n
	Json��ʽ���£�
	{
		"achWbName" : "",
		"emWbMode" : 0,
		"dwWbPageNum" : 0,
		"dwWbCreateTime" : 0,
		"achTabId" : "",
		"dwPageId" : 0,
		"achWbCreatorE164" : "",
		"dwWbWidth" : 0,
		"dwWbHeight" : 0,
		"achElementUrl" : "",
		"achDownloadUrl" : "",
		"achUploadUrl" : "",
		"dwWbAnonyId" : 0
	}
*/
	Ev_MtApi_DcsNewWhiteBoard_Ntf,
	


/**
  @brief    ��Աɾ���װ�֪ͨ
  

  MainBuf(#TDCSDelWhiteBoardInfo_Api) \n
  Json��ʽ���£�
  {
  "strConfE164" : ""
  "strIndex" : ""
  "strFromE164":""
  }
*/
	Ev_MtApi_DcsDelWhiteBoard_Ntf,
	
/**
  @brief    ��Աɾ�����аװ�֪ͨ
  
  MainBuf(#TDCSDelWhiteBoardInfo_Api) \n
  Json��ʽ���£�
  {
  "strConfE164" : ""
  "strFromE164" : ""
  }
*/
	Ev_MtApi_DcsDelAllWhiteBoard_Ntf,

/**
  @brief    ����֪ͨ
  
	MainBuf(#TDCSWbPoint_Api) \n
	Json��ʽ���£�
*/
//	Ev_MtApi_DcsOperPoint_Ntf,
	
	
/**
  @brief    ͼԪ��ʾ֪ͨ
  
	MainBuf(#TDCSWbEntity_Api) \n
	Json��ʽ���£�
*/
//	Ev_MtApi_DcsOperEntity_Ntf,
	
	
/**
  @brief    ����֪ͨ
  
	MainBuf(#TDCSWbLine_Api) \n
	Json��ʽ���£�
*/
//	Ev_MtApi_DcsOperLine_Ntf,
	
	
/**
  @brief    ��Բ֪ͨ
  
	MainBuf(#TDCSWbCircle_Api) \n
	Json��ʽ���£�
*/
//	Ev_MtApi_DcsOperCircle_Ntf,
	
	
/**
  @brief    ��Ǧ��֪ͨ
  
	MainBuf(#TDCSWbPencil_Api) \n
	Json��ʽ���£�
*/
//	Ev_MtApi_DcsOperPencil_Ntf,


/**
  @brief    ���ʱ�֪ͨ
  
	MainBuf(#TDCSWbColorPen_Api) \n
	Json��ʽ���£�
*/
//	Ev_MtApi_DcsOperColorPen_Ntf,
	
	
/**
  @brief    ͼԪ֪ͨ
  
	MainBuf(#TDCSWbImage_Api) \n
	Json��ʽ���£�
*/
//	Ev_MtApi_DcsOperImage_Ntf,
	
	
/**
  @brief    ���߼�֪ͨ
  
	MainBuf(#TDCSOperContent_Api) \n
	SubBuf(#TDCSWbLineOperInfo_Api) \n
	Json��ʽ���£�
	{
		"MainParam":
		{
			"emOper" : 0,
			"dwMsgId" : 0,
			"achTabId" : "",
			"dwWbPageId" : 0,
			"dwMsgSequence" : 0,
			"achConfE164" : "",
            "bCacheElement" : false
		},
		"AssParam":
		{
			"achTabId" : "",
			"dwSubPageId" : 0,
			"tLine" : {
				"tEntity" : {
					"achEntityId" : "",
					"bLock" : false
				},
				"tBeginPt" : {
					"dwPosx" : 0,
					"dwPosy" : 0
				},
				"tEndPt" : {
					"dwPosx" : 0,
					"dwPosy" : 0
				},
				"dwLineWidth" : 0,
				"dwRgb" : 0				
			}
		}
	}
*/
	Ev_MtApi_DcsOperLineOperInfo_Ntf,
	
	
/**
  @brief    ��Բ��֪ͨ
  
	MainBuf(#TDCSOperContent_Api) \n
	SubBuf(#TDCSWbCircleOperInfo_Api) \n
	Json��ʽ���£�
	{
		"MainParam":
		{
			"emOper" : 0,
			"dwMsgId" : 0,
			"achTabId" : "",
			"dwWbPageId" : 0,
			"dwMsgSequence" : 0,
            "achConfE164" : "",
            "bCacheElement" : false
		},
		"AssParam":
		{
			"achTabId" : "",
			"dwSubPageId" : 0,
			"tCircle" : {
				"tEntity" : {
					"achEntityId" : "",
					"bLock" : false
				},
				"tBeginPt" : {
					"dwPosx" : 0,
					"dwPosy" : 0
				},
				"tEndPt" : {
					"dwPosx" : 0,
					"dwPosy" : 0
				},
				"dwLineWidth" : 0,
				"dwRgb" : 0				
			}
		}
	}
*/
	Ev_MtApi_DcsOperCircleOperInfo_Ntf,
	
	
/**
  @brief    ��Բ��֪ͨ
  
	MainBuf(#TDCSOperContent_Api) \n
	SubBuf(#TDCSWbRectangleOperInfo_Api) \n
	Json��ʽ���£�
	{
		"MainParam":
		{
			"emOper" : 0,
			"dwMsgId" : 0,
			"achTabId" : "",
			"dwWbPageId" : 0,
			"dwMsgSequence" : 0,
            "achConfE164" : "",
            "bCacheElement" : false
		},
		"AssParam":
		{
			"achTabId" : "",
			"dwSubPageId" : 0,
			"tRectangle" : {
				"tEntity" : {
					"achEntityId" : "",
					"bLock" : false
				},
				"tBeginPt" : {
					"dwPosx" : 0,
					"dwPosy" : 0
				},
				"tEndPt" : {
					"dwPosx" : 0,
					"dwPosy" : 0
				},
				"dwLineWidth" : 0,
				"dwRgb" : 0				
			}
		}
	}
*/
	Ev_MtApi_DcsOperRectangleOperInfo_Ntf,


/**
  @brief    ��Ǧ�ʼ�֪ͨ
  
	MainBuf(#TDCSOperContent_Api) \n
	SubBuf(#TDCSWbPencilOperInfo_Api) \n
	Json��ʽ���£�
	{
		"MainParam":
		{
			"emOper" : 0,
			"dwMsgId" : 0,
			"achTabId" : "",
			"dwWbPageId" : 0,
			"dwMsgSequence" : 0,
            "achConfE164" : "",
            "bCacheElement" : false
		},
		"AssParam":
		{
			"achTabId" : "",
			"dwSubPageId" : 0,
			"tPencil" : {
				"tEntity" : {
					"achEntityId" : "",
					"bLock" : false
				},
				"dwPointNum" : 0,
				"atPList" : [
					"dwPosx" : 0,
					"dwPosy" : 0
				],
				"dwLineWidth" : 0,
				"dwRgb" : 0				
			}
		}
	}
*/
	Ev_MtApi_DcsOperPencilOperInfo_Ntf,
	
	
/**
  @brief    ���ʱʼ�֪ͨ
  
	MainBuf(#TDCSOperContent_Api) \n
	SubBuf(#TDCSWbColorPenOperInfo_Api) \n
	Json��ʽ���£�
		{
		"MainParam":
		{
			"emOper" : 0,
			"dwMsgId" : 0,
			"achTabId" : "",
			"dwWbPageId" : 0,
			"dwMsgSequence" : 0,
            "achConfE164" : "",
            "bCacheElement" : false
		},
		"AssParam":
		{
			"achTabId" : "",
			"dwSubPageId" : 0,
			"tColorPen" : {
				"tEntity" : {
					"achEntityId" : "",
					"bLock" : false
				},
				"dwColorPenNum" : 0,
				"atCPList" : [
					"dwPosx" : 0,
					"dwPosy" : 0
				],
				"dwLineWidth" : 0,
				"dwRgb" : 0
			}
		}
	}
*/
	Ev_MtApi_DcsOperColorPenOperInfo_Ntf,
	
	
/**
  @brief    ��ͼԪ��֪ͨ
  
	MainBuf(#TDCSOperContent_Api) \n
	SubBuf(#TDCSWbImageOperInfo_Api) \n
	Json��ʽ���£�
	{
		"MainParam":
		{
			"emOper" : 0,
			"dwMsgId" : 0,
			"achTabId" : "",
			"dwWbPageId" : 0,
			"dwMsgSequence" : 0,
            "achConfE164" : "",
            "bCacheElement" : false
		},
		"AssParam":
		{
			"achTabId" : "",
			"dwSubPageId" : 0,
			"tImage" : {
				"tEntity" : {
					"achEntityId" : "",
					"bLock" : false;
				},
				"tBoardPt" : {
					"dwPosx" : 0,
					"dwPosy" : 0
				},
				"dwWidth" : 0,
				"dwHeight" : 0,
				"emNetworkstate" : 0,
				"achFileName" : "",
				"bBkImg" : false
			}
		}
	}
*/
	Ev_MtApi_DcsOperImageOperInfo_Ntf,
	
	
/**
  @brief    ��ǵ�ǰ�����ĵ���tabҳ��subpage֪ͨ
  
	MainBuf(#TDCSWbTabPageIdInfo_Api) \n
	Json��ʽ���£�
*/
//	Ev_MtApi_DcsOperTabPageIdInfo_Ntf,
	
	
/**
  @brief    ɾ��tabҳЯ������Ϣ
  
	MainBuf(#TDCSWbRemovePageIdInfo_Api) \n
	Json��ʽ���£�
*/
//	Ev_MtApi_DcsOperRemovePageIdInfo_Ntf,
	
	
/**
  @brief    �װ�ҳ��Ϣ���ڴ����װ塢���°װ���Ϣ��ʱ��ʹ��
  
	MainBuf(#TDCSWbTabPageInfo_Api) \n
	Json��ʽ���£�
*/
//	Ev_MtApi_DcsOperTabPageInfo_Ntf,
	
	
/**
  @brief    �װ��������ҳ��Ϣ�����ĵ�ʱ�������ĵ�����ҳ���ڵ�ǰ�װ�����Ӷ����ҳ
  
	MainBuf(#TDCSOperContent_Api) \n
	SubBuf(#TDCSWbAddSubPageInfo_Api) \n
	Json��ʽ���£�
	{
		"MainParam":
		{
			"emOper" : 0,
			"dwMsgId" : 0,
			"achTabId" : "",
			"dwWbPageId" : 0,
			"dwMsgSequence" : 0,
            "achConfE164" : "",
            "bCacheElement" : false
		},
		"AssParam":
		{
			"achTabId" : "",
			"dwSubPageCount" : 0
		}
	}
*/
	Ev_MtApi_DcsOperAddSubPageInfo_Ntf,
	
	
/**
  @brief    �л��װ�ҳ��Ϣ
			�л��װ�ҳ�������������
				1)�ڵ�ǰ�װ��д�һ����ҳ�л�����һ��ҳ����ǰ��ҳ�����߷���ָ����ҳ�棻
				2)�л�����һ���װ���
  
	MainBuf(#TDCSWbSwitchPageInfo_Api) \n
	Json��ʽ���£�
*/	
//	Ev_MtApi_DcsOperSwitchPageInfo_Ntf,
	
	
	
/**
  @brief    �ͻ��˸���������������Ŀ��ҳͼƬ
  
	MainBuf(#TDCSWbReqPageImage_Api) \n
	Json��ʽ���£�
*/
//	Ev_MtApi_DcsOperReqPageImage_Ntf,
	
	
/**
  @brief    ���β���
  
	MainBuf(#TDCSOperContent_Api) \n
	SubBuf(#TDCSWbEraseOperInfo_Api) \n
	Json��ʽ���£�
	{
		"MainParam":
		{
			"emOper" : 0,
			"dwMsgId" : 0,
			"achTabId" : "",
			"dwWbPageId" : 0,
			"dwMsgSequence" : 0,
            "achConfE164" : "",
            "bCacheElement" : false
		},
		"AssParam":
		{
			"achTabId" : "",
			"dwSubPageId" : 0,
			"tBeginPt" : {
				"dwPosx" : 0,
				"dwPosy" : 0
			},
			"tEndPt" : {
				"dwPosx" : 0,
				"dwPosy" : 0
			}
		}
	}
*/
	Ev_MtApi_DcsOperEraseOperInfo_Ntf,
	
	
	
/**
  @brief    �Ŵ�/��С������/��������Ӧ
  
	MainBuf(#TDCSOperContent_Api) \n
	SubBuf(#TDCSWbZoomInfo_Api) \n
	Json��ʽ���£�
	{
		"MainParam":
		{
			"emOper" : 0,
			"dwMsgId" : 0,
			"achTabId" : "",
			"dwWbPageId" : 0,
			"dwMsgSequence" : 0,
            "achConfE164" : "",
            "bCacheElement" : false
		},
		"AssParam":
		{
			"achTabId" : "",
			"dwZoom" : 0
		}
	}
*/
	Ev_MtApi_DcsOperZoomInfo_Ntf,
	
	
/**
  @brief    ����ͼƬ�ļ�����Ϣ
  
	MainBuf(#TDCSOperContent_Api) \n
	SubBuf(#TDCSWbSendImgFileInfo_Api) \n
	Json��ʽ���£�
		{
		"MainParam":
		{
			"emOper" : 0,
			"dwMsgId" : 0,
			"achTabId" : "",
			"dwWbPageId" : 0,
			"dwMsgSequence" : 0,
            "achConfE164" : "",
            "bCacheElement" : false
		},
		"AssParam":
		{
			"dwFileSize" : 0,
			"achFileId" : "",
			"achFileName" : ""
		}
	}
*/
//	Ev_MtApi_DcsOperSendImgFileInfo_Ntf,

/**
  @brief    ����Undo֪ͨ
  
	MainBuf(#TDCSOperContent_Api) \n
	SubBuf(#TDCSWbTabPageIdInfo_Api) \n
	Json��ʽ���£�
	{
		"MainParam":
		{
			"emOper" : 0,
			"dwMsgId" : 0,
			"achTabId" : "",
			"dwWbPageId" : 0,
			"dwMsgSequence" : 0,
            "achConfE164" : "",
            "bCacheElement" : false
		},
		"AssParam":
		{
			"achTabId" : "",
			"dwSubPageId" : 0
		}
	}
*/
	Ev_MtApi_DcsOperUndo_Ntf,

/**
  @brief    ����Redo֪ͨ
  
	MainBuf(#TDCSOperContent_Api) \n
	SubBuf(#TDCSWbTabPageIdInfo_Api) \n
	Json��ʽ���£�
	{
		"MainParam":
		{
			"emOper" : 0,
			"dwMsgId" : 0,
			"achTabId" : "",
			"dwWbPageId" : 0,
			"dwMsgSequence" : 0,
            "achConfE164" : "",
            "bCacheElement" : false
		},
		"AssParam":
		{
			"achTabId" : "",
			"dwSubPageId" : 0
		}
	}
*/
	Ev_MtApi_DcsOperRedo_Ntf,

/**
  @brief    ����ת֪ͨ
  
	MainBuf(#TDCSOperContent_Api) \n
	Json��ʽ���£�
	{
		"emOper" : 0,
		"dwMsgId" : 0,
		"achTabId" : "",
		"dwWbPageId" : 0,
		"dwMsgSequence" : 0,
        "achConfE164" : "",
        "bCacheElement" : false
	}
*/
	Ev_MtApi_DcsOperRotateLeft_Ntf,

/**
  @brief    ����ת֪ͨ
  
	MainBuf(#TDCSOperContent_Api) \n
	Json��ʽ���£�
	{
		"emOper" : 0,
		"dwMsgId" : 0,
		"achTabId" : "",
		"dwWbPageId" : 0,
		"dwMsgSequence" : 0,
        "achConfE164" : "",
        "bCacheElement" : false
	}
*/
	Ev_MtApi_DcsOperRotateRight_Ntf,


/**
  @brief    ����֪ͨ
	MainBuf(#TDCSOperContent_Api) \n

	Json��ʽ���£�
	{
		"emOper" : 0,
		"dwMsgId" : 0,
		"achTabId" : "",
		"dwWbPageId" : 0,
		"dwMsgSequence" : 0,
        "achConfE164" : "",
        "bCacheElement" : false
	}
*/
	Ev_MtApi_DcsOperClearScreen_Ntf,


/**
  @brief    ������������֪ͨ
  
	MainBuf(#TDCSOperContent_Api) \n
	SubBuf(#TDCSScrollScreenInfo_Api) \n
	Json��ʽ���£�
	{
		"MainParam":
		{
			"emOper" : 0,
			"dwMsgId" : 0,
			"achTabId" : "",
			"dwWbPageId" : 0,
			"dwMsgSequence" : 0,
            "achConfE164" : "",
            "bCacheElement" : false
		},
		"AssParam":
		{
			"achTabId" : "",
			"dwSubPageId" : 0,
			"tPoint" : {
				"dwPosx" : 0,
				"dwPosy" : 0
			}
		}
	}
*/
	Ev_MtApi_DcsOperScrollScreen_Ntf,

/**
  @brief    ȫ����ʾ
  
	MainBuf(#TDCSOperContent_Api) \n
	SubBuf(#TDCSWbDisPlayInfo_Api) \n
	Json��ʽ���£�
	{
		"MainParam":
		{
		},
		"AssParam":
		{
		}
	}
*/
	Ev_MtApi_DcsOperFullScreen_Ntf,


/**
  @brief    100%������ʾ
  
	MainBuf(#TDCSOperContent_Api) \n
	SubBuf(#TDCSWbDisPlayInfo_Api) \n
	Json��ʽ���£�
	{
		"MainParam":
		{
		},
		"AssParam":
		{
		}
	}
*/
	Ev_MtApi_DcsOper100ProportionScreen_Ntf, 


/**
  @brief    �������
  
	MainBuf(#TDCSOperContent_Api) \n
	SubBuf(#TDCSWbReginEraseOperInfo_Api) \n
	Json��ʽ���£�
	{
		"MainParam":
		{
		},
		"AssParam":
		{
		}
	}
*/

	Ev_MtApi_DcsOperReginErase_Ntf,
	
/**
  @brief    ����ͼƬ
  
	MainBuf(#TDCSOperContent_Api) \n
	SubBuf(#TDCSWbInsertPicOperInfo_Api) \n
	Json��ʽ���£�
	{
		"MainParam":
		{
		},
		"AssParam":
		{
		}
	}
*/
	Ev_MtApi_DcsOperInsertPic_Ntf, 


/**
  @brief    ѡ��ͼƬ����
  
	MainBuf(#TDCSOperContent_Api) \n
	SubBuf(#TDCSWbPitchPicOperInfo_Api) \n
	Json��ʽ���£�
	{
		"MainParam":
		{
		},
		"AssParam":
		{
		}
	}
*/
	Ev_MtApi_DcsOperPitchPicZoom_Ntf, 


/**
  @brief    ѡ��ͼƬ��ת
  
	MainBuf(#TDCSOperContent_Api) \n
	SubBuf(#TDCSWbPitchPicOperInfo_Api) \n
	Json��ʽ���£�
	{
		"MainParam":
		{
		},
		"AssParam":
		{
		}
	}
*/
	Ev_MtApi_DcsOperPitchPicRotate_Ntf, 


/**
  @brief    ѡ��ͼƬ�϶�
  
	MainBuf(#TDCSOperContent_Api) \n
	SubBuf(#TDCSWbPitchPicOperInfo_Api) \n
	Json��ʽ���£�
	{
		"MainParam":
		{
		},
		"AssParam":
		{
		}
	}
*/
	Ev_MtApi_DcsOperPitchPicDrag_Ntf, 


/**
  @brief    ѡ��ͼƬɾ��
  
	MainBuf(#TDCSOperContent_Api) \n
	SubBuf(#TDCSWbDelPicOperInfo_Api) \n
	Json��ʽ���£�
	{
		"MainParam":
		{
		},
		"AssParam":
		{
		}
	}
*/
	Ev_MtApi_DcsOperPitchPicDel_Ntf, 


/**
  @brief    ���߼���Ӧ
    
	MainBuf(#TDCSOperContent_Api) \n
	SubBuf(#TDCSWbLineOperInfo_Api) \n
	Json��ʽ���£�
	{
		"MainParam":
		{
			"emOper" : 0,
			"dwMsgId" : 0,
			"achTabId" : "",
			"dwWbPageId" : 0,
			"dwMsgSequence" : 0,
            "achConfE164" : "",
            "bCacheElement" : false
		},
		"AssParam":
		{
			"achTabId" : "",
			"dwSubPageId" : 0,
			"tLine" : {
				"tEntity" : {
					"achEntityId" : "",
					"bLock" : false
				},
				"tBeginPt" : {
					"dwPosx" : 0,
					"dwPosy" : 0
				},
				"tEndPt" : {
					"dwPosx" : 0,
					"dwPosy" : 0
				},
				"dwLineWidth" : 0,
				"dwRgb" : 0				
			}
		}
	}
*/
	Ev_MtApi_DcsOperLineOperInfo_Rsp,
	
	
/**
  @brief    ��Բ����Ӧ
  
	MainBuf(#TDCSOperContent_Api) \n
	SubBuf(#TDCSWbCircleOperInfo_Api) \n
	Json��ʽ���£�
	{
		"MainParam":
		{
			"emOper" : 0,
			"dwMsgId" : 0,
			"achTabId" : "",
			"dwWbPageId" : 0,
			"dwMsgSequence" : 0,
            "achConfE164" : "",
            "bCacheElement" : false
		},
		"AssParam":
		{
			"achTabId" : "",
			"dwSubPageId" : 0,
			"tCircle" : {
				"tEntity" : {
					"achEntityId" : "",
					"bLock" : false
				},
				"tBeginPt" : {
					"dwPosx" : 0,
					"dwPosy" : 0
				},
				"tEndPt" : {
					"dwPosx" : 0,
					"dwPosy" : 0
				},
				"dwLineWidth" : 0,
				"dwRgb" : 0				
			}
		}
	}
*/
	Ev_MtApi_DcsOperCircleOperInfo_Rsp,
	
	
/**
  @brief    ��Ǧ�ʼ���Ӧ
  
	MainBuf(#TDCSOperContent_Api) \n
	SubBuf(#TDCSWbPencilOperInfo_Api) \n
	Json��ʽ���£�
	{
		"MainParam":
		{
			"emOper" : 0,
			"dwMsgId" : 0,
			"achTabId" : "",
			"dwWbPageId" : 0,
			"dwMsgSequence" : 0,
            "achConfE164" : "",
            "bCacheElement" : false
		},
		"AssParam":
		{
			"achTabId" : "",
			"dwSubPageId" : 0,
			"tPencil" : {
				"tEntity" : {
					"achEntityId" : "",
					"bLock" : false
				},
				"dwPointNum" : 0,
				"atPList" : [
					"dwPosx" : 0,
					"dwPosy" : 0
				],
				"dwLineWidth" : 0,
				"dwRgb" : 0				
			}
		}
	}
*/
	Ev_MtApi_DcsOperPencilOperInfo_Rsp,
	
	
/**
  @brief    ���ʱʼ���Ӧ
  
	MainBuf(#TDCSOperContent_Api) \n
	SubBuf(#TDCSWbColorPenOperInfo_Api) \n
	Json��ʽ���£�
	{
		"MainParam":
		{
			"emOper" : 0,
			"dwMsgId" : 0,
			"achTabId" : "",
			"dwWbPageId" : 0,
			"dwMsgSequence" : 0,
            "achConfE164" : "",
            "bCacheElement" : false
		},
		"AssParam":
		{
			"achTabId" : "",
			"dwSubPageId" : 0,
			"tColorPen" : {
				"tEntity" : {
					"achEntityId" : "",
					"bLock" : false
				},
				"dwColorPenNum" : 0,
				"atCPList" : [
					"dwPosx" : 0,
					"dwPosy" : 0
				],
				"dwLineWidth" : 0,
				"dwRgb" : 0
			}
		}
	}
*/
	Ev_MtApi_DcsOperColorPenOperInfo_Rsp,
	
		
/**
  @brief    �����μ���Ӧ
  
	MainBuf(#TDCSOperContent_Api) \n
	SubBuf(#TDCSWbRectangleOperInfo_Api) \n
	Json��ʽ���£�
	{
		"MainParam":
		{
			"emOper" : 0,
			"dwMsgId" : 0,
			"achTabId" : "",
			"dwWbPageId" : 0,
			"dwMsgSequence" : 0,
            "achConfE164" : "",
            "bCacheElement" : false
		},
		"AssParam":
		{
			"achTabId" : "",
			"dwSubPageId" : 0,
			"tRectangle" : {
				"tEntity" : {
					"achEntityId" : "",
					"bLock" : false
				},
				"tBeginPt" : {
					"dwPosx" : 0,
					"dwPosy" : 0
				},
				"tEndPt" : {
					"dwPosx" : 0,
					"dwPosy" : 0
				},
				"dwLineWidth" : 0,
				"dwRgb" : 0				
			}
		}
	}
*/
	Ev_MtApi_DcsOperRectangleOperInfo_Rsp,

/**

  @brief    ��ͼԪ����Ӧ
  
	MainBuf(#TDCSOperContent_Api) \n
	SubBuf(#TDCSWbImageOperInfo_Api) \n
	Json��ʽ���£�
	{
		"MainParam":
		{
			"emOper" : 0,
			"dwMsgId" : 0,
			"achTabId" : "",
			"dwWbPageId" : 0,
			"dwMsgSequence" : 0,
            "achConfE164" : "",
            "bCacheElement" : false
		},
		"AssParam":
		{
			"achTabId" : "",
			"dwSubPageId" : 0,
			"tImage" : {
				"tEntity" : {
					"achEntityId" : "",
					"bLock" : false;
				},
				"tBoardPt" : {
					"dwPosx" : 0,
					"dwPosy" : 0
				},
				"dwWidth" : 0,
				"dwHeight" : 0,
				"emNetworkstate" : 0,
				"achFileName" : "",
				"bBkImg" : false
			}
		}
	}
*/
	Ev_MtApi_DcsOperImageOperInfo_Rsp,
	
	
/**
  @brief    ��ǵ�ǰ�����ĵ���tabҳ��subpage֪ͨ��Ӧ
  
	MainBuf(#TDCSWbTabPageIdInfo_Api) \n
	Json��ʽ���£�
*/
//	Ev_MtApi_DcsOperTabPageIdInfo_Rsp,
	
	
/**
  @brief    ɾ��tabҳЯ������Ϣ��Ӧ
  
	MainBuf(#TDCSWbRemovePageIdInfo_Api) \n
	Json��ʽ���£�
*/
//	Ev_MtApi_DcsOperRemovePageIdInfo_Rsp,
	
	
/**
  @brief    �װ�ҳ��Ϣ���ڴ����װ塢���°װ���Ϣ��ʱ��ʹ��
  
	MainBuf(#TDCSWbTabPageInfo_Api) \n
	Json��ʽ���£�
*/
//	Ev_MtApi_DcsOperTabPageInfo_Rsp,
	
	
/**
  @brief    �װ��������ҳ��Ϣ�����ĵ�ʱ�������ĵ�����ҳ���ڵ�ǰ�װ�����Ӷ����ҳ��Ӧ
  
	MainBuf(#TDCSOperContent_Api) \n
	SubBuf(#TDCSWbAddSubPageInfo_Api) \n
	Json��ʽ���£�
	{
		"MainParam":
		{
			"emOper" : 0,
			"dwMsgId" : 0,
			"achTabId" : "",
			"dwWbPageId" : 0,
			"dwMsgSequence" : 0,
            "achConfE164" : "",
            "bCacheElement" : false
		},
		"AssParam":
		{
			"achTabId" : "",
			"dwSubPageCount" : 0
		}		
	}
*/
	Ev_MtApi_DcsOperAddSubPageInfo_Rsp,
	
	
/**
  @brief    �л��װ�ҳ��Ϣ��Ӧ
			�л��װ�ҳ�������������
				1)�ڵ�ǰ�װ��д�һ����ҳ�л�����һ��ҳ����ǰ��ҳ�����߷���ָ����ҳ�棻
				2)�л�����һ���װ���
  
	MainBuf(#TDCSWbSwitchPageInfo_Api) \n
	Json��ʽ���£�
*/	
//	Ev_MtApi_DcsOperSwitchPageInfo_Rsp,
	
	
	
/**
  @brief    �ͻ��˸���������������Ŀ��ҳͼƬ��Ӧ
  
	MainBuf(#TDCSWbReqPageImage_Api) \n
	Json��ʽ���£�
*/
//	Ev_MtApi_DcsOperReqPageImage_Rsp,
	
	
/**
  @brief    ���β�����Ӧ
  
	MainBuf(#TDCSOperContent_Api) \n
	SubBuf(#TDCSWbEraseOperInfo_Api) \n
	Json��ʽ���£�
	{
		"MainParam":
		{
			"emOper" : 0,
			"dwMsgId" : 0,
			"achTabId" : "",
			"dwWbPageId" : 0,
			"dwMsgSequence" : 0,
            "achConfE164" : "",
            "bCacheElement" : false
		},
		"AssParam":
		{
			"achTabId" : "",
			"dwSubPageId" : 0,
			"tBeginPt" : {
				"dwPosx" : 0,
				"dwPosy" : 0
			},
			"tEndPt" : {
				"dwPosx" : 0,
				"dwPosy" : 0
			}
		}
	}
*/
	Ev_MtApi_DcsOperEraseOperInfo_Rsp,
	
	
	
/**
  @brief    �Ŵ�/��С������/��������Ӧ��Ӧ
  
	MainBuf(#TDCSOperContent_Api) \n
	SubBuf(#TDCSWbZoomInfo_Api) \n
	Json��ʽ���£�
	{
		"MainParam":
		{
			"emOper" : 0,
			"dwMsgId" : 0,
			"achTabId" : "",
			"dwWbPageId" : 0,
			"dwMsgSequence" : 0,
            "achConfE164" : "",
            "bCacheElement" : false
		},
		"AssParam":
		{
			"achTabId" : "",
			"dwZoom" : 0
		}
	}
*/
	Ev_MtApi_DcsOperZoomInfo_Rsp,
	
	
/**
  @brief    ����ͼƬ�ļ�����Ϣ��Ӧ
  
	MainBuf(#TDCSOperContent_Api) \n
	SubBuf(#TDCSWbSendImgFileInfo_Api) \n
	Json��ʽ���£�
	{
		"MainParam":
		{
			"emOper" : 0,
			"dwMsgId" : 0,
			"achTabId" : "",
			"dwWbPageId" : 0,
			"dwMsgSequence" : 0,
            "achConfE164" : "",
            "bCacheElement" : false
		},
		"AssParam":
		{
			"dwFileSize" : 0,
			"achFileId" : "",
			"achFileName" : ""
		}
	}
*/
//	Ev_MtApi_DcsOperSendImgFileInfo_Rsp,

/**
  @brief    ����Undo��Ӧ
  
	MainBuf(#TDCSOperContent_Api) \n
	SubBuf(#TDCSWbTabPageIdInfo_Api) \n
	Json��ʽ���£�
	{
		"MainParam":
		{
			"emOper" : 0,
			"dwMsgId" : 0,
			"achTabId" : "",
			"dwWbPageId" : 0,
			"dwMsgSequence" : 0,
            "achConfE164" : "",
            "bCacheElement" : false
		},
		"AssParam":
		{
			"achTabId" : "",
			"dwSubPageId" : 0
		}
	}
*/
	Ev_MtApi_DcsOperUndo_Rsp,

/**
  @brief    ����Redo��Ӧ
  
	MainBuf(#TDCSOperContent_Api) \n
	SubBuf(#TDCSWbTabPageIdInfo_Api) \n
	Json��ʽ���£�
	{
		"MainParam":
		{
			"emOper" : 0,
			"dwMsgId" : 0,
			"achTabId" : "",
			"dwWbPageId" : 0,
			"dwMsgSequence" : 0,
            "achConfE164" : "",
            "bCacheElement" : false
		},
		"AssParam":
		{
			"achTabId" : "",
			"dwSubPageId" : 0
		}
	}
*/
	Ev_MtApi_DcsOperRedo_Rsp,

/**
  @brief    ����ת��Ӧ
  
	MainBuf(#TDCSOperContent_Api) \n
	Json��ʽ���£�
	{
		"emOper" : 0,
		"dwMsgId" : 0,
		"achTabId" : "",
		"dwWbPageId" : 0,
		"dwMsgSequence" : 0,
        "achConfE164" : "",
        "bCacheElement" : false
	}
*/
	Ev_MtApi_DcsOperRotateLeft_Rsp,

/**
  @brief    ����ת��Ӧ
  
	MainBuf(#TDCSOperContent_Api) \n
	Json��ʽ���£�
	{
		"emOper" : 0,
		"dwMsgId" : 0,
		"achTabId" : "",
		"dwWbPageId" : 0,
		"dwMsgSequence" : 0,
        "achConfE164" : "",
        "bCacheElement" : false
	}
*/
	Ev_MtApi_DcsOperRotateRight_Rsp,


/**
  @brief    ������Ӧ
	MainBuf(#TDCSOperContent_Api) \n
	Json��ʽ���£�
	{
		"emOper" : 0,
		"dwMsgId" : 0,
		"achTabId" : "",
		"dwWbPageId" : 0,
		"dwMsgSequence" : 0,
        "achConfE164" : "",
        "bCacheElement" : false
	}
*/
	Ev_MtApi_DcsOperClearScreen_Rsp,


/**
  @brief    ��������������Ӧ
  
	MainBuf(#TDCSOperContent_Api) \n
	SubBuf(#TDCSScrollScreenInfo_Api) \n
	Json��ʽ���£�
	{
		"MainParam":
		{
			"emOper" : 0,
			"dwMsgId" : 0,
			"achTabId" : "",
			"dwWbPageId" : 0,
			"dwMsgSequence" : 0,
            "achConfE164" : "",
            "bCacheElement" : false
		},
		"AssParam":
		{
			"achTabId" : "",
			"dwSubPageId" : 0,
			"tPoint" : {
				"dwPosx" : 0,
				"dwPosy" : 0
			}
		}
	}
*/
	Ev_MtApi_DcsOperScrollScreen_Rsp,



/**
  @brief    ��������������Ӧ
  
	MainBuf(#TDCSOperContent_Api) \n
	SubBuf(#TDCSWbDisPlayInfo_Api) \n
	Json��ʽ���£�
	{
		"MainParam":
		{
			"emOper" : 0,
			"dwMsgId" : 0,
			"achTabId" : "",
			"dwWbPageId" : 0,
			"dwMsgSequence" : 0,
            "achConfE164" : "",
            "bCacheElement" : false		
		},
		"AssParam":
		{
			"achTabId" : "",
			"dwSubPageId" : 0,
			"afMatrixValue" : [
			0,0,0,0,0,0,0,0,0]
		}
	}
*/
	Ev_MtApi_DcsOperFullScreen_Rsp,


/**
  @brief    ��������������Ӧ
  
	MainBuf(#TDCSOperContent_Api) \n
	SubBuf(#TDCSWbDisPlayInfo_Api) \n
	Json��ʽ���£�
	{
		"MainParam":
		{
			"emOper" : 0,
			"dwMsgId" : 0,
			"achTabId" : "",
			"dwWbPageId" : 0,
			"dwMsgSequence" : 0,
            "achConfE164" : "",
            "bCacheElement" : false		
		},
		"AssParam":
		{
			"achTabId" : "",
			"dwSubPageId" : 0,
			"afMatrixValue" : [
			0,0,0,0,0,0,0,0,0]
		}
	}
*/
	Ev_MtApi_DcsOper100ProportionScreen_Rsp, 


/**
  @brief    ��������������Ӧ
  
	MainBuf(#TDCSOperContent_Api) \n
	SubBuf(#TDCSWbReginEraseOperInfo_Api) \n
	Json��ʽ���£�
	{
		"MainParam":
		{
		},
		"AssParam":
		{
		}
	}
*/
	Ev_MtApi_DcsOperReginErase_Rsp,
	
/**
  @brief    ��������������Ӧ
  
	MainBuf(#TDCSOperContent_Api) \n
	SubBuf(#TDCSWbInsertPicOperInfo_Api) \n
	Json��ʽ���£�
	{
		"MainParam":
		{
		},
		"AssParam":
		{
		}
	}
*/
	Ev_MtApi_DcsOperInsertPic_Rsp, 


/**
  @brief    ��������������Ӧ
  
	MainBuf(#TDCSOperContent_Api) \n
	SubBuf(#TDCSWbPitchPicOperInfo_Api) \n
	Json��ʽ���£�
	{
		"MainParam":
		{
		},
		"AssParam":
		{
		}
	}
*/
	Ev_MtApi_DcsOperPitchPicZoom_Rsp, 


/**
  @brief    ��������������Ӧ
  
	MainBuf(#TDCSOperContent_Api) \n
	SubBuf(#TDCSWbPitchPicOperInfo_Api) \n
	Json��ʽ���£�
	{
		"MainParam":
		{
		},
		"AssParam":
		{
		}
	}
*/
	Ev_MtApi_DcsOperPitchPicRotate_Rsp, 


/**
  @brief    ��������������Ӧ
  
	MainBuf(#TDCSOperContent_Api) \n
	SubBuf(#TDCSWbPitchPicOperInfo_Api) \n
	Json��ʽ���£�
	{
		"MainParam":
		{
		},
		"AssParam":
		{
		}
	}
*/
	Ev_MtApi_DcsOperPitchPicDrag_Rsp, 


/**
  @brief    ��������������Ӧ
  
	MainBuf(#TDCSOperContent_Api) \n
	SubBuf(#TDCSWbDelPicOperInfo_Api) \n
	Json��ʽ���£�
	{
		"MainParam":
		{
		},
		"AssParam":
		{
		}
	}
*/
	Ev_MtApi_DcsOperPitchPicDel_Rsp, 

/**
  @brief    ��Ա�л��װ�֪ͨ
  
	MainBuf(#TDCSBoardInfo_Api) \n
	Json��ʽ���£�
	{
		"achWbName" : "",
		"emWbMode" : 0,
		"dwWbPageNum" : 0,
		"dwWbCreateTime" : 0,
		"achTabId" : "",
		"dwPageId" : 0,
		"achWbCreatorE164" : "",
		"dwWbWidth" : 0,
		"dwWbHeight" : 0,
		"achElementUrl" : "",
		"achDownloadUrl" : "",
		"achUploadUrl" : "",
		"dwWbAnonyId" : 0
	}
*/	
	Ev_MtApi_DcsSwitch_Ntf,

/**
  @brief    ���Э����֪ͨ

	MainBuf(#TDCSUserInfos_Api) \n
	Json��ʽ���£�
	{
		"achConfE164" : "",
		"achConfName" : "",
		"dwListNum" : 0,
		"atUserInfoList": [
			"achE164" : "",
			"achName" : "",
			"emMttype" : 0,
			"bOnline" : false,
			"bIsOper" : false,
			"bIsConfAdmin" : false
		]		
	}
*/
	Ev_MtApi_DcsAddOperator_Ntf,

/**
  @brief    ɾ��Э����֪ͨ

	MainBuf(#TDCSUserInfos_Api) \n
	Json��ʽ���£�
	{
		"achConfE164" : "",
		"achConfName" : "",
		"dwListNum" : 0,
		"atUserInfoList": [
			"achE164" : "",
			"achName" : "",
			"emMttype" : 0,
			"bOnline" : false,
			"bIsOper" : false,
			"bIsConfAdmin" : false
		]
	}
*/
	Ev_MtApi_DcsDelOperator_Ntf,

/**
  @brief    ��ȡ��ǰ�װ�֪ͨ

	MainBuf(#TDCSBoardInfo_Api) \n
	Json��ʽ���£�
	{
		"achWbName" : "",
		"emWbMode" : 0,
		"dwWbPageNum" : 0,
		"dwWbCreateTime" : 0,
		"achTabId" : "",
		"dwPageId" : 0,
		"achWbCreatorE164" : "",
		"dwWbWidth" : 0,
		"dwWbHeight" : 0,
		"achElementUrl" : "",
		"achDownloadUrl" : "",
		"achUploadUrl" : "",
		"dwWbAnonyId" : 0
	}
*/
	Ev_MtApi_DcsCurrentWhiteBoard_Ntf,

/**
  @brief    ��¼���Ӱװ���·���֪ͨ
  
	MainBuf(#TDCSConnectResult_Api) \n
	Json��ʽ���£�
	{
		"bSuccess" : false;
		"emErrorCode" : 0
	}
*/
	Ev_MtApi_DcsLoginResult_Ntf,

/**
  @brief    ������Ӱװ���·���֪ͨ
  
	MainBuf(#TDCSConnectResult_Api) \n
	Json��ʽ���£�
	{
		"bSuccess" : false;
		"emErrorCode" : 0		
	}
*/
	Ev_MtApi_DcsConfResult_Ntf,

	/**
  @brief    ��ȡ����ͼƬ��ַ��Ӧ
  
	MainBuf(#TDCSResult_Api) \n
	SubBuf(#TDCSImageUrl_Api)  ���ɹ��ŷ���
	Json��ʽ���£�
	{
		"bSucces" : 0,
		"dwErrorCode" : 0,
		"achConfE164" : ""
		"achWbPicentityId" : ""
	}
*/
	Ev_MtApi_DcsDownloadImage_Rsp,


	/**
  @brief    ����ͼƬ֪ͨ
  
	MainBuf(#TDCSImageUrl_Api) \n
	Json��ʽ���£�
	{
		"bSucces" : 0,
		"dwErrorCode" : 0,
		"achConfE164" : ""
		"achWbPicentityId" : ""
	}
*/
	Ev_MtApi_DcsDownloadImage_Ntf, 


	/**
  @brief    �ϴ�ͼƬ֪ͨ
  
	MainBuf(#TDCSImageUrl_Api) \n
	Json��ʽ���£�
	{
		"bSucces" : 0,
		"dwErrorCode" : 0,
		"achConfE164" : ""
		"achWbPicentityId" : ""
	}
*/
	Ev_MtApi_DcsUploadImage_Ntf,


	/**
  @brief    ��ȡ�ϴ�ͼƬ��ַ��Ӧ
  
	MainBuf(#TDCSResult_Api) \n
	SubBuf(#TDCSImageUrl_Api)  ���ɹ��ŷ���
	Json��ʽ���£�
	{
		"bSucces" : 0,
		"dwErrorCode" : 0,
		"achConfE164" : ""
		"achWbPicentityId" : ""
	}
*/
	Ev_MtApi_DcsUploadImage_Rsp,
	/**
  @brief    �ϴ��ļ�֪ͨ
  
	MainBuf(#TDCSFileLoadResult_Api) \n
	Json��ʽ���£�
	{
		"bSuccess" : false;
		"bElementFile" : false;
		"achFilePathName" : ""
		"achWbPicentityId" : ""
		"achTabid" : ""
	}
*/
	Ev_MtApi_DcsUploadFile_Ntf,


	/**
  @brief    �����ļ���Ӧ
  
	MainBuf(#TDCSFileLoadResult_Api) \n
	Json��ʽ���£�
	{
		"bSuccess" : false;
		"bElementFile" : false;
		"achFilePathName" : ""
		"achWbPicentityId" : ""
		"achTabid" : ""
	}
*/
	Ev_MtApi_DcsDownloadFile_Rsp,

	/**
  @brief    �ӷ�������ȡ���Ļ���ͼԪ��������ʼ����֪ͨ
  
  MainBuf(#s8*) \n
  SubBuf(#u32) \n
  Json��ʽ���£�
  {
      "MainParam" :
      {
        "basetype" : "",
      },
      "AssParam":
      {
        "basetype" : 0,
      }
  }
*/
	Ev_MtApi_DcsElementOperBegin_Ntf,

	/**
  @brief    �ӷ�������ȡ���Ļ���ͼԪ�������������֪ͨ
  
  MainBuf(#TDcsCacheElementParseResult_Api) \n
  Json��ʽ���£�
  {
    "achTabId" : "",
    "dwMsgSequence": 0,
    "bParseSuccess":false
  }
*/
	Ev_MtApi_DcsElementOperFinal_Ntf,


	/**
  @brief    �ܾ�����Э����֪ͨ
  
	MainBuf(#TDCSUserInfo_Api) \n
	Json��ʽ���£�
	{
		"achConfE164" : "",
		"achConfName" : "",
		"tUserInfo" : {
			"achE164" : "",
			"achName" : "",
			"emMttype" : 0,
			"bOnline" : false,
			"bIsOper" : false,
			"bIsConfAdmin" : false
		}
	}
*/
	Ev_MtApi_DcsRejectOper_Ntf,

	
	/**
  @brief   �Ҷ�֪ͨ
  
	MainBuf(#s8*) \n
	Json��ʽ���£�
	{
		basetype: ""    // ����E164��
	}

*/
	Ev_MtApi_DcsDropConfCall_Ntf,


/**
  @brief   �������еģ������ַ������ѯ
  
	MainBuf(#TDCSConfAddr_Api) \n
	Json��ʽ���£�
	{
		"achIp" : "",
		"achDomain" : "",
		"dwPort" : 0		
	}

*/
	Ev_MtApi_DcsJoinConfDomain_Req,
	/**
  @brief    ��ԭ����Ա֪ͨ: ȡ������Ա֪ͨ
  
	MainBuf(#s8*) \n
	Json��ʽ���£�
	{
		str: ""
	}
*/
//	Ev_MtApi_DcsCancelManager_Ntf,

/**
  @brief    ���¹���Ա֪ͨ: ��Ϊ����Ա֪ͨ
  
	MainBuf(#s8*) \n
	Json��ʽ���£�
	{
		str: ""
	}
*/
//	Ev_MtApi_DcsSpecManager_Ntf,

    EV_UI_END(MTAPI_DCS) = EVSEG_MTAPI_BASE_END
};

#define Is_MtApiDCS_Msg(m) ((m) >= EV_UI_BGN(MTAPI_DCS) && (m) <= EV_UI_END(MTAPI_DCS))

/**@}*/

/**@}*/
#endif // _MTAPI_EVENT_DCS_H_

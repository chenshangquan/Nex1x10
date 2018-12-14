/*******************************************************************************//**
*@file          mtapi_event_dcs.h
*@brief         实现MTAPI MtDcsSdk 给UI(观察者)事件通知的定义
*
*@author        wangfeifei
*@version       5.0    
*@date          20150328
*@copyright     (c)1995-2015 Suzhou Keda Technology Co.,Ltd. All rights reserved
***********************************************************************************/
#ifndef _MTAPI_EVENT_DCS_H_
#define _MTAPI_EVENT_DCS_H_
/**@addtogroup event 事件与回调
*@{
*/

/**@addtogroup dcsevent 电子白板事件
*@{
*/

#include "mtapi_event_def.h"

enum EmMtApiDCSEv
{
	EV_UI_BGN(MTAPI_DCS)  = EVSEG_MTAPI_DCS_BGN,

	
/**
  @brief    登录电子白板服务器响应
  
	MainBuf(#TDCSResult_Api) \n
	Json格式如下：
	{
		"bSucces" : true,
		"dwErrorCode" : 0,
		"achConfE164" : ""
	}
*/
	Ev_MtApi_DcsLoginSrv_Rsp,

	
/**
  @brief    登出电子白板服务器响应
  
	MainBuf(#TDCSResult_Api) \n
	Json格式如下：
		{
		"bSucces" : true,
		"dwErrorCode" : 0,
		"achConfE164" : ""
	}
*/
	Ev_MtApi_DcsLogout_Rsp,

/**
  @brief    创建会议中电子白板响应
  
	MainBuf(#TDCSCreateConfResult_Api) \n
	Json格式如下：
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
  @brief    获取电子白板会议信息（复用了这个结构）
  
	MainBuf(#TDCSCreateConfResult_Api) \n
	Json格式如下：
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
  @brief    获取电子白板会议信息（复用了这个结构）
  
	MainBuf(#TDCSCreateConfResult_Api) \n
	Json格式如下：
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
  @brief    邀请用户
  
	MainBuf(#TDCSInviteUsr_Api) \n
	Json格式如下：
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
  @brief    获取会议地址请求响应
  
	MainBuf(#TDCSResult_Api) \n
	SubBuf(#TDCSConfAddr_Api)  （成功才发）
	Json格式如下：
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
  @brief    加入电子白板会议响应
  
	MainBuf(#TDCSJoinConfResult_Api) \n
	Json格式如下：
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
  @brief    退出电子白板会议响应
  
	MainBuf(#TDCSResult_Api) \n
	Json格式如下：
	{
		"bSucces" : true,
		"dwErrorCode" : 0,
		"achConfE164" : ""
	}
*/	
	Ev_MtApi_DcsQuitConf_Rsp,
	
/**
  @brief    结束电子白板会议响应
  
	MainBuf(#TDCSResult_Api) \n
	Json格式如下：
	{
		"bSucces" : true,
		"dwErrorCode" : 0,
		"achConfE164" : ""
	}
*/	
	Ev_MtApi_DcsReleaseConf_Rsp,
	
	
/**
  @brief    添加成员响应
  
	MainBuf(#TDCSResult_Api) \n
	Json格式如下：
	{
		"bSucces" : true,
		"dwErrorCode" : 0,
		"achConfE164" : ""
	}
*/	
	Ev_MtApi_DcsAddMember_Rsp,
	
	
/**
  @brief    删除成员响应
  
	MainBuf(#TDCSResult_Api) \n
	Json格式如下：
	{
		"bSucces" : true,
		"dwErrorCode" : 0,
		"achConfE164" : ""
	}
*/	
	Ev_MtApi_DcsDelMember_Rsp,
	
/**
  @brief    设置会议信息响应
  
	MainBuf(#TDCSSetConfInfoResult_Api) \n
	Json格式如下：
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
  @brief    设置成员角色信息通知
  
	MainBuf(#TDCSResult_Api) \n
	Json格式如下：
	{
		"bSucces" : true,
		"dwErrorCode" : 0,
		"achConfE164" : ""
	}
*/
//	Ev_MtApi_DcsSetUserRole_Ntf,

/**
  @brief    添加协作方响应
  
	MainBuf(#TDCSResult_Api) \n
	Json格式如下：
	{
		"bSucces" : true,
		"dwErrorCode" : 0,
		"achConfE164" : ""
	}
*/
	Ev_MtApi_DcsAddOperator_Rsp,


/**
  @brief    删除协作方响应
  
	MainBuf(#TDCSResult_Api) \n
	Json格式如下：
	{
		"bSucces" : true,
		"dwErrorCode" : 0,
		"achConfE164" : ""
	}
*/
	Ev_MtApi_DcsDelOperator_Rsp,

/**
  @brief    申请协作方响应
  
	MainBuf(#TDCSResult_Api) \n
	Json格式如下：
	{
		"bSucces" : true,
		"dwErrorCode" : 0,
		"achConfE164" : ""
	}
*/
	Ev_MtApi_DcsApplyOper_Rsp,
	
	
/**
  @brief    取消协作方响应
  
	MainBuf(#TDCSResult_Api) \n
	Json格式如下：
	{
		"bSucces" : true,
		"dwErrorCode" : 0,
		"achConfE164" : ""
	}
*/
	Ev_MtApi_DcsCancelOper_Rsp,
	
	
/**
  @brief    获取用户列表通知
  
	MainBuf(#TDCSResult_Api) \n
	SubBuf(#TDCSGetUserList_Api)  （成功才发）
	Json格式如下：
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
  @brief    创建白板通知
  
	MainBuf(#TDCSBoardResult_Api) \n
	SubBuf(#TDCSBoardInfo_Api)  （成功才发）
	Json格式如下：
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
  @brief    删除白板通知
  
	MainBuf(#TDCSBoardResult_Api) \n
	Json格式如下：
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
  @brief    删除所有白板通知
  
	MainBuf(#TDCSBoardResult_Api) \n
	Json格式如下：
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
  @brief    获取所有白板通知
  
	MainBuf(#TDCSResult_Api) \n
	SubBuf(#TDCSGetAllBoard_Api)  （成功才发）
	Json格式如下：
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
  @brief    获取指定白板通知
  
	MainBuf(#TDCSBoardResult_Api) \n
	SubBuf(#TDCSBoardInfo_Api)  （成功才发）
	Json格式如下：
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
  @brief    获取当前白板通知
  
	MainBuf(#TDCSBoardResult_Api) \n
	SubBuf(#TDCSBoardInfo_Api)  （成功才发）
	Json格式如下：
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
  @brief    切换白板结果通知
  
	MainBuf(#TDCSBoardResult_Api) \n
	SubBuf(#TDCSBoardInfo_Api)  （成功才发）
	Json格式如下：
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
  @brief    成员加入会议通知
  
	MainBuf(#TDCSUserInfo_Api) \n
	Json格式如下：
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
  @brief    成员退出会议通知
  
	MainBuf(#TDCSUserInfo_Api) \n
	Json格式如下：
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
  @brief    成员结束会议通知
  
	MainBuf(#s8*, KMTAPI_BUF_64_LEN) \n
	Json格式如下：
	{
		"strConfE164" : ""
	}
*/
	Ev_MtApi_DcsReleaseConf_Ntf,
	
	
	
/**
  @brief    添加用户失败通知
  
	MainBuf(#TDCSUserInfos_Api) \n
	Json格式如下：
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
  @brief    删除用户失败通知
  
	MainBuf(#TDCSUserInfos_Api) \n
	Json格式如下：
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
  @brief    更新会议信息通知
  
	MainBuf(#TDCSConfInfo_Api) \n
	Json格式如下：
	{
		"achConfE164" : "",
		"achConfName" : "",
		"emConfMode" : 0,
		"emConfType" : 0
	}
*/
	Ev_MtApi_DcsUpdateConfInfo_Ntf,
	
/**
  @brief    更新用户角色信息通知
  
	MainBuf(#TDCSUserRole_Api) \n
	Json格式如下：
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
  @brief    设置用户角色失败通知
  
	MainBuf(#TDCSUserRole_Api) \n
	Json格式如下：
*/
//	Ev_MtApi_DcsSetUserRoleFail_Ntf,
	
	
/**
  @brief    成员申请协作权通知
  
	MainBuf(#TDCSUserInfo_Api) \n
	Json格式如下：
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
  @brief    开启协作权通知
  
	MainBuf(#s8, KMTAPI_BUF_64_LEN) \n
	Json格式如下：
	{
		"strConfE164" : ""
	}
*/
//	Ev_MtApi_DcsSpecOper_Ntf,
	
	
/**
  @brief    成员取消协作权通知
  
	MainBuf(#s8, KMTAPI_BUF_64_LEN) \n
	Json格式如下：
	{
		"strConfE164" : ""
	}
*/
//	Ev_MtApi_DcsCancelOper_Ntf,
	

/**
  @brief    成员创建新白板通知
  
	MainBuf(#TDCSBoardInfo_Api) \n
	Json格式如下：
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
  @brief    成员删除白板通知
  

  MainBuf(#TDCSDelWhiteBoardInfo_Api) \n
  Json格式如下：
  {
  "strConfE164" : ""
  "strIndex" : ""
  "strFromE164":""
  }
*/
	Ev_MtApi_DcsDelWhiteBoard_Ntf,
	
/**
  @brief    成员删除所有白板通知
  
  MainBuf(#TDCSDelWhiteBoardInfo_Api) \n
  Json格式如下：
  {
  "strConfE164" : ""
  "strFromE164" : ""
  }
*/
	Ev_MtApi_DcsDelAllWhiteBoard_Ntf,

/**
  @brief    画点通知
  
	MainBuf(#TDCSWbPoint_Api) \n
	Json格式如下：
*/
//	Ev_MtApi_DcsOperPoint_Ntf,
	
	
/**
  @brief    图元标示通知
  
	MainBuf(#TDCSWbEntity_Api) \n
	Json格式如下：
*/
//	Ev_MtApi_DcsOperEntity_Ntf,
	
	
/**
  @brief    画线通知
  
	MainBuf(#TDCSWbLine_Api) \n
	Json格式如下：
*/
//	Ev_MtApi_DcsOperLine_Ntf,
	
	
/**
  @brief    画圆通知
  
	MainBuf(#TDCSWbCircle_Api) \n
	Json格式如下：
*/
//	Ev_MtApi_DcsOperCircle_Ntf,
	
	
/**
  @brief    画铅笔通知
  
	MainBuf(#TDCSWbPencil_Api) \n
	Json格式如下：
*/
//	Ev_MtApi_DcsOperPencil_Ntf,


/**
  @brief    画彩笔通知
  
	MainBuf(#TDCSWbColorPen_Api) \n
	Json格式如下：
*/
//	Ev_MtApi_DcsOperColorPen_Ntf,
	
	
/**
  @brief    图元通知
  
	MainBuf(#TDCSWbImage_Api) \n
	Json格式如下：
*/
//	Ev_MtApi_DcsOperImage_Ntf,
	
	
/**
  @brief    画线集通知
  
	MainBuf(#TDCSOperContent_Api) \n
	SubBuf(#TDCSWbLineOperInfo_Api) \n
	Json格式如下：
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
  @brief    画圆集通知
  
	MainBuf(#TDCSOperContent_Api) \n
	SubBuf(#TDCSWbCircleOperInfo_Api) \n
	Json格式如下：
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
  @brief    画圆集通知
  
	MainBuf(#TDCSOperContent_Api) \n
	SubBuf(#TDCSWbRectangleOperInfo_Api) \n
	Json格式如下：
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
  @brief    画铅笔集通知
  
	MainBuf(#TDCSOperContent_Api) \n
	SubBuf(#TDCSWbPencilOperInfo_Api) \n
	Json格式如下：
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
  @brief    画彩笔集通知
  
	MainBuf(#TDCSOperContent_Api) \n
	SubBuf(#TDCSWbColorPenOperInfo_Api) \n
	Json格式如下：
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
  @brief    画图元集通知
  
	MainBuf(#TDCSOperContent_Api) \n
	SubBuf(#TDCSWbImageOperInfo_Api) \n
	Json格式如下：
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
  @brief    标记当前操作文档的tab页和subpage通知
  
	MainBuf(#TDCSWbTabPageIdInfo_Api) \n
	Json格式如下：
*/
//	Ev_MtApi_DcsOperTabPageIdInfo_Ntf,
	
	
/**
  @brief    删除tab页携带的信息
  
	MainBuf(#TDCSWbRemovePageIdInfo_Api) \n
	Json格式如下：
*/
//	Ev_MtApi_DcsOperRemovePageIdInfo_Ntf,
	
	
/**
  @brief    白板页信息，在创建白板、更新白板信息等时候使用
  
	MainBuf(#TDCSWbTabPageInfo_Api) \n
	Json格式如下：
*/
//	Ev_MtApi_DcsOperTabPageInfo_Ntf,
	
	
/**
  @brief    白板中添加子页信息，打开文档时，根据文档的总页数在当前白板中添加多个子页
  
	MainBuf(#TDCSOperContent_Api) \n
	SubBuf(#TDCSWbAddSubPageInfo_Api) \n
	Json格式如下：
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
  @brief    切换白板页信息
			切换白板页包括两种情况：
				1)在当前白板中从一个子页切换到另一子页，即前后翻页，或者翻到指定的页面；
				2)切换到另一个白板中
  
	MainBuf(#TDCSWbSwitchPageInfo_Api) \n
	Json格式如下：
*/	
//	Ev_MtApi_DcsOperSwitchPageInfo_Ntf,
	
	
	
/**
  @brief    客户端给服务器发送请求目标页图片
  
	MainBuf(#TDCSWbReqPageImage_Api) \n
	Json格式如下：
*/
//	Ev_MtApi_DcsOperReqPageImage_Ntf,
	
	
/**
  @brief    矩形擦除
  
	MainBuf(#TDCSOperContent_Api) \n
	SubBuf(#TDCSWbEraseOperInfo_Api) \n
	Json格式如下：
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
  @brief    放大/缩小、横向/纵向自适应
  
	MainBuf(#TDCSOperContent_Api) \n
	SubBuf(#TDCSWbZoomInfo_Api) \n
	Json格式如下：
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
  @brief    发送图片文件的信息
  
	MainBuf(#TDCSOperContent_Api) \n
	SubBuf(#TDCSWbSendImgFileInfo_Api) \n
	Json格式如下：
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
  @brief    步骤Undo通知
  
	MainBuf(#TDCSOperContent_Api) \n
	SubBuf(#TDCSWbTabPageIdInfo_Api) \n
	Json格式如下：
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
  @brief    步骤Redo通知
  
	MainBuf(#TDCSOperContent_Api) \n
	SubBuf(#TDCSWbTabPageIdInfo_Api) \n
	Json格式如下：
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
  @brief    左旋转通知
  
	MainBuf(#TDCSOperContent_Api) \n
	Json格式如下：
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
  @brief    右旋转通知
  
	MainBuf(#TDCSOperContent_Api) \n
	Json格式如下：
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
  @brief    清屏通知
	MainBuf(#TDCSOperContent_Api) \n

	Json格式如下：
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
  @brief    滚动条滚动屏通知
  
	MainBuf(#TDCSOperContent_Api) \n
	SubBuf(#TDCSScrollScreenInfo_Api) \n
	Json格式如下：
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
  @brief    全屏显示
  
	MainBuf(#TDCSOperContent_Api) \n
	SubBuf(#TDCSWbDisPlayInfo_Api) \n
	Json格式如下：
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
  @brief    100%比例显示
  
	MainBuf(#TDCSOperContent_Api) \n
	SubBuf(#TDCSWbDisPlayInfo_Api) \n
	Json格式如下：
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
  @brief    区域擦除
  
	MainBuf(#TDCSOperContent_Api) \n
	SubBuf(#TDCSWbReginEraseOperInfo_Api) \n
	Json格式如下：
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
  @brief    插入图片
  
	MainBuf(#TDCSOperContent_Api) \n
	SubBuf(#TDCSWbInsertPicOperInfo_Api) \n
	Json格式如下：
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
  @brief    选中图片缩放
  
	MainBuf(#TDCSOperContent_Api) \n
	SubBuf(#TDCSWbPitchPicOperInfo_Api) \n
	Json格式如下：
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
  @brief    选中图片旋转
  
	MainBuf(#TDCSOperContent_Api) \n
	SubBuf(#TDCSWbPitchPicOperInfo_Api) \n
	Json格式如下：
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
  @brief    选中图片拖动
  
	MainBuf(#TDCSOperContent_Api) \n
	SubBuf(#TDCSWbPitchPicOperInfo_Api) \n
	Json格式如下：
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
  @brief    选中图片删除
  
	MainBuf(#TDCSOperContent_Api) \n
	SubBuf(#TDCSWbDelPicOperInfo_Api) \n
	Json格式如下：
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
  @brief    画线集响应
    
	MainBuf(#TDCSOperContent_Api) \n
	SubBuf(#TDCSWbLineOperInfo_Api) \n
	Json格式如下：
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
  @brief    画圆集响应
  
	MainBuf(#TDCSOperContent_Api) \n
	SubBuf(#TDCSWbCircleOperInfo_Api) \n
	Json格式如下：
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
  @brief    画铅笔集响应
  
	MainBuf(#TDCSOperContent_Api) \n
	SubBuf(#TDCSWbPencilOperInfo_Api) \n
	Json格式如下：
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
  @brief    画彩笔集响应
  
	MainBuf(#TDCSOperContent_Api) \n
	SubBuf(#TDCSWbColorPenOperInfo_Api) \n
	Json格式如下：
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
  @brief    画矩形集响应
  
	MainBuf(#TDCSOperContent_Api) \n
	SubBuf(#TDCSWbRectangleOperInfo_Api) \n
	Json格式如下：
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

  @brief    画图元集响应
  
	MainBuf(#TDCSOperContent_Api) \n
	SubBuf(#TDCSWbImageOperInfo_Api) \n
	Json格式如下：
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
  @brief    标记当前操作文档的tab页和subpage通知响应
  
	MainBuf(#TDCSWbTabPageIdInfo_Api) \n
	Json格式如下：
*/
//	Ev_MtApi_DcsOperTabPageIdInfo_Rsp,
	
	
/**
  @brief    删除tab页携带的信息响应
  
	MainBuf(#TDCSWbRemovePageIdInfo_Api) \n
	Json格式如下：
*/
//	Ev_MtApi_DcsOperRemovePageIdInfo_Rsp,
	
	
/**
  @brief    白板页信息，在创建白板、更新白板信息等时候使用
  
	MainBuf(#TDCSWbTabPageInfo_Api) \n
	Json格式如下：
*/
//	Ev_MtApi_DcsOperTabPageInfo_Rsp,
	
	
/**
  @brief    白板中添加子页信息，打开文档时，根据文档的总页数在当前白板中添加多个子页响应
  
	MainBuf(#TDCSOperContent_Api) \n
	SubBuf(#TDCSWbAddSubPageInfo_Api) \n
	Json格式如下：
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
  @brief    切换白板页信息响应
			切换白板页包括两种情况：
				1)在当前白板中从一个子页切换到另一子页，即前后翻页，或者翻到指定的页面；
				2)切换到另一个白板中
  
	MainBuf(#TDCSWbSwitchPageInfo_Api) \n
	Json格式如下：
*/	
//	Ev_MtApi_DcsOperSwitchPageInfo_Rsp,
	
	
	
/**
  @brief    客户端给服务器发送请求目标页图片响应
  
	MainBuf(#TDCSWbReqPageImage_Api) \n
	Json格式如下：
*/
//	Ev_MtApi_DcsOperReqPageImage_Rsp,
	
	
/**
  @brief    矩形擦除响应
  
	MainBuf(#TDCSOperContent_Api) \n
	SubBuf(#TDCSWbEraseOperInfo_Api) \n
	Json格式如下：
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
  @brief    放大/缩小、横向/纵向自适应响应
  
	MainBuf(#TDCSOperContent_Api) \n
	SubBuf(#TDCSWbZoomInfo_Api) \n
	Json格式如下：
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
  @brief    发送图片文件的信息响应
  
	MainBuf(#TDCSOperContent_Api) \n
	SubBuf(#TDCSWbSendImgFileInfo_Api) \n
	Json格式如下：
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
  @brief    步骤Undo响应
  
	MainBuf(#TDCSOperContent_Api) \n
	SubBuf(#TDCSWbTabPageIdInfo_Api) \n
	Json格式如下：
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
  @brief    步骤Redo响应
  
	MainBuf(#TDCSOperContent_Api) \n
	SubBuf(#TDCSWbTabPageIdInfo_Api) \n
	Json格式如下：
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
  @brief    左旋转响应
  
	MainBuf(#TDCSOperContent_Api) \n
	Json格式如下：
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
  @brief    右旋转响应
  
	MainBuf(#TDCSOperContent_Api) \n
	Json格式如下：
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
  @brief    清屏响应
	MainBuf(#TDCSOperContent_Api) \n
	Json格式如下：
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
  @brief    滚动条滚动屏响应
  
	MainBuf(#TDCSOperContent_Api) \n
	SubBuf(#TDCSScrollScreenInfo_Api) \n
	Json格式如下：
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
  @brief    滚动条滚动屏响应
  
	MainBuf(#TDCSOperContent_Api) \n
	SubBuf(#TDCSWbDisPlayInfo_Api) \n
	Json格式如下：
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
  @brief    滚动条滚动屏响应
  
	MainBuf(#TDCSOperContent_Api) \n
	SubBuf(#TDCSWbDisPlayInfo_Api) \n
	Json格式如下：
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
  @brief    滚动条滚动屏响应
  
	MainBuf(#TDCSOperContent_Api) \n
	SubBuf(#TDCSWbReginEraseOperInfo_Api) \n
	Json格式如下：
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
  @brief    滚动条滚动屏响应
  
	MainBuf(#TDCSOperContent_Api) \n
	SubBuf(#TDCSWbInsertPicOperInfo_Api) \n
	Json格式如下：
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
  @brief    滚动条滚动屏响应
  
	MainBuf(#TDCSOperContent_Api) \n
	SubBuf(#TDCSWbPitchPicOperInfo_Api) \n
	Json格式如下：
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
  @brief    滚动条滚动屏响应
  
	MainBuf(#TDCSOperContent_Api) \n
	SubBuf(#TDCSWbPitchPicOperInfo_Api) \n
	Json格式如下：
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
  @brief    滚动条滚动屏响应
  
	MainBuf(#TDCSOperContent_Api) \n
	SubBuf(#TDCSWbPitchPicOperInfo_Api) \n
	Json格式如下：
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
  @brief    滚动条滚动屏响应
  
	MainBuf(#TDCSOperContent_Api) \n
	SubBuf(#TDCSWbDelPicOperInfo_Api) \n
	Json格式如下：
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
  @brief    成员切换白板通知
  
	MainBuf(#TDCSBoardInfo_Api) \n
	Json格式如下：
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
  @brief    添加协作方通知

	MainBuf(#TDCSUserInfos_Api) \n
	Json格式如下：
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
  @brief    删除协作方通知

	MainBuf(#TDCSUserInfos_Api) \n
	Json格式如下：
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
  @brief    获取当前白板通知

	MainBuf(#TDCSBoardInfo_Api) \n
	Json格式如下：
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
  @brief    登录电子白板链路结果通知
  
	MainBuf(#TDCSConnectResult_Api) \n
	Json格式如下：
	{
		"bSuccess" : false;
		"emErrorCode" : 0
	}
*/
	Ev_MtApi_DcsLoginResult_Ntf,

/**
  @brief    会议电子白板链路结果通知
  
	MainBuf(#TDCSConnectResult_Api) \n
	Json格式如下：
	{
		"bSuccess" : false;
		"emErrorCode" : 0		
	}
*/
	Ev_MtApi_DcsConfResult_Ntf,

	/**
  @brief    获取下载图片地址响应
  
	MainBuf(#TDCSResult_Api) \n
	SubBuf(#TDCSImageUrl_Api)  （成功才发）
	Json格式如下：
	{
		"bSucces" : 0,
		"dwErrorCode" : 0,
		"achConfE164" : ""
		"achWbPicentityId" : ""
	}
*/
	Ev_MtApi_DcsDownloadImage_Rsp,


	/**
  @brief    下载图片通知
  
	MainBuf(#TDCSImageUrl_Api) \n
	Json格式如下：
	{
		"bSucces" : 0,
		"dwErrorCode" : 0,
		"achConfE164" : ""
		"achWbPicentityId" : ""
	}
*/
	Ev_MtApi_DcsDownloadImage_Ntf, 


	/**
  @brief    上传图片通知
  
	MainBuf(#TDCSImageUrl_Api) \n
	Json格式如下：
	{
		"bSucces" : 0,
		"dwErrorCode" : 0,
		"achConfE164" : ""
		"achWbPicentityId" : ""
	}
*/
	Ev_MtApi_DcsUploadImage_Ntf,


	/**
  @brief    获取上传图片地址响应
  
	MainBuf(#TDCSResult_Api) \n
	SubBuf(#TDCSImageUrl_Api)  （成功才发）
	Json格式如下：
	{
		"bSucces" : 0,
		"dwErrorCode" : 0,
		"achConfE164" : ""
		"achWbPicentityId" : ""
	}
*/
	Ev_MtApi_DcsUploadImage_Rsp,
	/**
  @brief    上传文件通知
  
	MainBuf(#TDCSFileLoadResult_Api) \n
	Json格式如下：
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
  @brief    下载文件响应
  
	MainBuf(#TDCSFileLoadResult_Api) \n
	Json格式如下：
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
  @brief    从服务器获取到的缓存图元操作，开始发送通知
  
  MainBuf(#s8*) \n
  SubBuf(#u32) \n
  Json格式如下：
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
  @brief    从服务器获取到的缓存图元操作，发送完毕通知
  
  MainBuf(#TDcsCacheElementParseResult_Api) \n
  Json格式如下：
  {
    "achTabId" : "",
    "dwMsgSequence": 0,
    "bParseSuccess":false
  }
*/
	Ev_MtApi_DcsElementOperFinal_Ntf,


	/**
  @brief    拒绝申请协作方通知
  
	MainBuf(#TDCSUserInfo_Api) \n
	Json格式如下：
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
  @brief   挂断通知
  
	MainBuf(#s8*) \n
	Json格式如下：
	{
		basetype: ""    // 会议E164号
	}

*/
	Ev_MtApi_DcsDropConfCall_Ntf,


/**
  @brief   入会过程中的，会议地址域名查询
  
	MainBuf(#TDCSConfAddr_Api) \n
	Json格式如下：
	{
		"achIp" : "",
		"achDomain" : "",
		"dwPort" : 0		
	}

*/
	Ev_MtApi_DcsJoinConfDomain_Req,
	/**
  @brief    向原管理员通知: 取消管理员通知
  
	MainBuf(#s8*) \n
	Json格式如下：
	{
		str: ""
	}
*/
//	Ev_MtApi_DcsCancelManager_Ntf,

/**
  @brief    向新管理员通知: 成为管理员通知
  
	MainBuf(#s8*) \n
	Json格式如下：
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

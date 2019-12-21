
#ifndef _CAMERA_API_H_
#define _CAMERA_API_H_

#include "osp.h"
#include "camera_dmsg.h"
#include "camera_struct.h"
#include <stdio.h>
#include <iostream>

using namespace std;

//回掉函数和注册回掉函数的定义 
typedef  u32 (*NOTIFY_DEVICE_CALLBACK) (u32 dwEvent, u8 *pbyMainBuf, u32 dwMainBufLen, u8 *pbySubBuf , u32 dwSubBufLen); //回掉函数的函数指针定义

//NOTIFY_DEVICE_CALLBACK g_cbCamNotify;

 //<注册回调函数定义
API u32 CamSetDeviceNotify( NOTIFY_DEVICE_CALLBACK  cbNotify); //注册回调函数定义
//<发送给device消息实现
API u32 PostToDevice(u32 dwEvent, u8* pbyMainBuf,  u32 dwMainSize, u8* pbySubBuf = NULL, u32 dwSubSize = 0 ); 

/**
* CamAddCameraCmd
*
* @brief 添加摄像机通知消息
*
* @param	[in]	tAddCamera-->摄像机信息（Id，ip port）
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：Ev_AICamera_AddCamera_Ntf+ TMtCameraInfo /摄像机连接失败时返回 Ev_AICamera_AddCamera_Ntf + 参数bRet(0)
*/ 
API u32 CamAddCameraCmd( TMtAddCamera &tAddCamera );

/**
* CamDeleteCameraCmd
*
* @brief 删除摄像机
*
* @param	[in]	TMtCameraCtrl-->摄像机信息（Id）
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：Ev_AICamera_DeleteCamera_Ntf + 参数bRet(bool值0表示失败 1表示成功)
*/ 
API u32 CamDeleteCameraCmd( TMtCameraCtrl &tCameraCtrl );

/**
* CamOpenPeopleCountCmd
*
* @brief 开启人数统计命令
*
* @param	[in]	TMtCameraCtrl-->摄像机信息（Id）
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：Ev_AICamera_PeopleCountingState_Ntf + TMtPeopleCountingState///<人数统计状态通知
*					  Ev_AICamera_PeopleCountingResult_Ntf + TMtPeopleCountingResult///<人数统计结果通知					  
*/ 
API u32 CamOpenPeopleCountCmd( TMtCameraCtrl &tCameraCtrl ); 

/**
* CamClosePeopleCountCmd
*
* @brief 关闭人数统计命令
*
* @param	[in]	TMtCameraCtrl-->摄像机信息（Id）
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：Ev_AICamera_PeopleCountingState_Ntf + TMtPeopleCountingState ///<人数统计状态通知					  
*/ 
API u32 CamClosePeopleCountCmd( TMtCameraCtrl &tCameraCtrl ); 

/**
* CamOpenFaceCheckInCmd
*
* @brief 开启人脸签到
*
* @param	[in]	TMtCameraCtrl-->摄像机信息（Id）
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：Ev_AICamera_FaceCheckInState_Ntf +TMtFaceCheckInState ///<人脸签到状态通知 
*					  Ev_AICamera_FaceCheckInInfo_Ntf + TMtFaceCheckInInfos ///<人脸签到信息通知		  
*/ 
API u32 CamOpenFaceCheckInCmd( TMtCameraCtrl &tCameraCtrl );

/**
* CamCloseFaceCheckInCmd
*
* @brief 关闭人脸签到
*
* @param	[in]	TMtCameraCtrl-->摄像机信息（Id）
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：Ev_AICamera_FaceCheckInState_Ntf +TMtFaceCheckInState///<人脸签到状态通知 			  
*/ 
API u32 CamCloseFaceCheckInCmd( TMtCameraCtrl &tCameraCtrl );

/**
* CamOpenElectronicNamePlateCmd
*
* @brief 开启电子铭牌
*
* @param	[in]	TMtCameraCtrl-->摄像机信息（Id）
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：Ev_AICamera_ElectronicNamePlateState_Ntf + TMtElectronicNamePlateState ///<通知电子铭牌状态			  
*/ 
API u32 CamOpenElectronicNamePlateCmd( TMtCameraCtrl &tCameraCtrl );

/**
* CamCloseElectronicNamePlateCmd
*
* @brief   关闭电子铭牌
*
* @param	[in]	TMtCameraCtrl-->摄像机信息（Id）
* @return	u32		0：成功;	其它：错误码	
* @note		响应消息：Ev_AICamera_ElectronicNamePlateState_Ntf + TMtElectronicNamePlateState ///<通知电子铭牌状态			  
*/ 
API u32 CamCloseElectronicNamePlateCmd( TMtCameraCtrl &tCameraCtrl );



#endif
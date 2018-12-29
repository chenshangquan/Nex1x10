
#ifndef _CAMERA_API_H_
#define _CAMERA_API_H_

#include "osp.h"
#include "camera_dmsg.h"
#include "camera_struct.h"
#include <stdio.h>
#include <iostream>

using namespace std;

//�ص�������ע��ص������Ķ��� 
typedef  u32 (*NOTIFY_DEVICE_CALLBACK) (u32 dwEvent, u8 *pbyMainBuf, u32 dwMainBufLen, u8 *pbySubBuf , u32 dwSubBufLen); //�ص������ĺ���ָ�붨��

//NOTIFY_DEVICE_CALLBACK g_cbCamNotify;

 //<ע��ص���������
API u32 CamSetDeviceNotify( NOTIFY_DEVICE_CALLBACK  cbNotify); //ע��ص���������
//<���͸�device��Ϣʵ��
API u32 PostToDevice(u32 dwEvent, u8* pbyMainBuf,  u32 dwMainSize, u8* pbySubBuf = NULL, u32 dwSubSize = 0 ); 

/**
* CamAddCameraCmd
*
* @brief ��������֪ͨ��Ϣ
*
* @param	[in]	tAddCamera-->�������Ϣ��Id��ip port��
* @return	u32		0���ɹ�;	������������	
* @note		��Ӧ��Ϣ��Ev_AICamera_AddCamera_Ntf+ TMtCameraInfo /���������ʧ��ʱ���� Ev_AICamera_AddCamera_Ntf + ����bRet(0)
*/ 
API u32 CamAddCameraCmd( TMtAddCamera &tAddCamera );

/**
* CamDeleteCameraCmd
*
* @brief ɾ�������
*
* @param	[in]	TMtCameraCtrl-->�������Ϣ��Id��
* @return	u32		0���ɹ�;	������������	
* @note		��Ӧ��Ϣ��Ev_AICamera_DeleteCamera_Ntf + ����bRet(boolֵ0��ʾʧ�� 1��ʾ�ɹ�)
*/ 
API u32 CamDeleteCameraCmd( TMtCameraCtrl &tCameraCtrl );

/**
* CamOpenPeopleCountCmd
*
* @brief ��������ͳ������
*
* @param	[in]	TMtCameraCtrl-->�������Ϣ��Id��
* @return	u32		0���ɹ�;	������������	
* @note		��Ӧ��Ϣ��Ev_AICamera_PeopleCountingState_Ntf + TMtPeopleCountingState///<����ͳ��״̬֪ͨ
*					  Ev_AICamera_PeopleCountingResult_Ntf + TMtPeopleCountingResult///<����ͳ�ƽ��֪ͨ					  
*/ 
API u32 CamOpenPeopleCountCmd( TMtCameraCtrl &tCameraCtrl ); 

/**
* CamClosePeopleCountCmd
*
* @brief �ر�����ͳ������
*
* @param	[in]	TMtCameraCtrl-->�������Ϣ��Id��
* @return	u32		0���ɹ�;	������������	
* @note		��Ӧ��Ϣ��Ev_AICamera_PeopleCountingState_Ntf + TMtPeopleCountingState ///<����ͳ��״̬֪ͨ					  
*/ 
API u32 CamClosePeopleCountCmd( TMtCameraCtrl &tCameraCtrl ); 

/**
* CamOpenFaceCheckInCmd
*
* @brief ��������ǩ��
*
* @param	[in]	TMtCameraCtrl-->�������Ϣ��Id��
* @return	u32		0���ɹ�;	������������	
* @note		��Ӧ��Ϣ��Ev_AICamera_FaceCheckInState_Ntf +TMtFaceCheckInState ///<����ǩ��״̬֪ͨ 
*					  Ev_AICamera_FaceCheckInInfo_Ntf + TMtFaceCheckInInfos ///<����ǩ����Ϣ֪ͨ		  
*/ 
API u32 CamOpenFaceCheckInCmd( TMtCameraCtrl &tCameraCtrl );

/**
* CamCloseFaceCheckInCmd
*
* @brief �ر�����ǩ��
*
* @param	[in]	TMtCameraCtrl-->�������Ϣ��Id��
* @return	u32		0���ɹ�;	������������	
* @note		��Ӧ��Ϣ��Ev_AICamera_FaceCheckInState_Ntf +TMtFaceCheckInState///<����ǩ��״̬֪ͨ 			  
*/ 
API u32 CamCloseFaceCheckInCmd( TMtCameraCtrl &tCameraCtrl );

/**
* CamOpenElectronicNamePlateCmd
*
* @brief ������������
*
* @param	[in]	TMtCameraCtrl-->�������Ϣ��Id��
* @return	u32		0���ɹ�;	������������	
* @note		��Ӧ��Ϣ��Ev_AICamera_ElectronicNamePlateState_Ntf + TMtElectronicNamePlateState ///<֪ͨ��������״̬			  
*/ 
API u32 CamOpenElectronicNamePlateCmd( TMtCameraCtrl &tCameraCtrl );

/**
* CamCloseElectronicNamePlateCmd
*
* @brief   �رյ�������
*
* @param	[in]	TMtCameraCtrl-->�������Ϣ��Id��
* @return	u32		0���ɹ�;	������������	
* @note		��Ӧ��Ϣ��Ev_AICamera_ElectronicNamePlateState_Ntf + TMtElectronicNamePlateState ///<֪ͨ��������״̬			  
*/ 
API u32 CamCloseElectronicNamePlateCmd( TMtCameraCtrl &tCameraCtrl );



#endif
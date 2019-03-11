#ifndef _CAMERA_STRUCT_H_
#define _CAMERA_STRUCT_H_
//#include "kdvdef.h"
#include "kdvtype.h"
#include <string.h>
#define CAMERA_MAX_ID_LEN (u32)32  //<�ݶ�32
#define CAMERA_MAX_NUM (u32)20  //һ������ǩ�����20����
#define CMAERA_MAX_POSITION_LEN (u32)256 //<Ա��ְλ������ֽ���
#define AICAMERA_INSTANCE_ID 1 

#define CAMERA_APP_NO 0x40 //�����app Id
#define CAMERA_RECONNECT_TIME 30*1000  // 30��
#define CAMERA_NULL "null"
/*��������ʱ��Ҫdevice���ݵ���Ϣ*/
///<EV_AICAMERA_AddCamera_Cmd

typedef struct tagTMtAddCamera
{
	u32 dwIp;                                         ///< ���������ip (������)
	u32 dwPort;                                       ///< ����������Ķ˿�
	s8  achCameraID[CAMERA_MAX_ID_LEN+1];       ///<  ���������Id����Ϊ�������Ψһ��ʶ��
public:
	tagTMtAddCamera(){ memset( this ,0 ,sizeof( struct  tagTMtAddCamera ) );}
}*PTMtAddCamera, TMtAddCamera;

/*�������Ϣ֪ͨ��device����Ϣ��֪ͨ��ȥ��*/
///<Ev_AICamera_AddCamera_Ntf
typedef struct tagTMtCameraInfo
{
	s8  	achCameraID[CAMERA_MAX_ID_LEN+1];       ///<  ���������Id����Ϊ�������Ψһ��ʶ��
	s8  	achCameraname[CAMERA_MAX_ID_LEN+1];     ///<���������
	s8  	achCameraModel[CAMERA_MAX_ID_LEN+1];     ///<������ͺ�
	BOOL32  bSupportPeopleCounting;      			     ///<�Ƿ�֧������ͳ�ƹ���
	BOOL32  bSupportElectronicNameplate; 			     ///<�Ƿ�֧�ֵ������ƹ���
	BOOL32  bSupportFaceCheckIn;        			         ///<�Ƿ�֧������ǩ������
public:
	tagTMtCameraInfo(){ memset( this ,0 ,sizeof( struct  tagTMtCameraInfo ) );}
}*PTMtCameraInfo, TMtCameraInfo;

/*ǩ������Ϣ*/
typedef struct tagTMtCheckInInfo
{
    s8 achName[CAMERA_MAX_ID_LEN+1]; ///<ǩ��������
	s8 achTime[CAMERA_MAX_ID_LEN+1]; ///<ǩ��ʱ�� (ǩ��ʱ�����)
	s8 achPosition[CMAERA_MAX_POSITION_LEN+1];///<Ա��ְλ
public:
	tagTMtCheckInInfo(){ memset( this ,0 ,sizeof( struct  tagTMtCheckInInfo ) );}
}*PTMtCheckInInfo, TMtCheckInInfo;

/*����ǩ����Ϣ֪ͨ��device����Ϣ��֪ͨ��ȥ��*/
///<Ev_AICamera_FaceCheckInInfo_Ntf
typedef struct tagTMtFaceCheckInInfos
{
	u32 dwNum;			///<����
	s8  achCameraID[CAMERA_MAX_ID_LEN+1];       ///<  ���������Id����Ϊ�������Ψһ��ʶ��
	TMtCheckInInfo  atFaceCheckInInfos[CAMERA_MAX_NUM+1]; ///<�ݶ�20һ��֪ͨǩ������Ϣ�����飨��ࣩ
public:
	tagTMtFaceCheckInInfos(){ memset( this ,0 ,sizeof( struct  tagTMtFaceCheckInInfos ) );}
}*PTMtFaceCheckInInfos, TMtFaceCheckInInfos;

/*֪ͨ����ǩ��״̬*/
///< Ev_AICamera_FaceCheckInState_Ntf
typedef struct tagTMtFaceCheckInState
{
	s8  achCameraID[CAMERA_MAX_ID_LEN+1];       ///<  ���������Id����Ϊ�������Ψһ��ʶ��
	BOOL32 bOpen; ///<true ������false �رգ��������ƣ���Ӧcamera.proto�ļ��е�on�ֶ�
public:
	tagTMtFaceCheckInState(){ memset( this ,0 ,sizeof( struct  tagTMtFaceCheckInState ) );}	
}*PTMtFaceCheckInState, TMtFaceCheckInState;

/*֪ͨ��������״̬*/
///< Ev_AICamera_ElectronicNamePlateState_Ntf
typedef struct tagTMtElectronicNamePlateState
{
	s8  achCameraID[CAMERA_MAX_ID_LEN+1];       ///<  ���������Id����Ϊ�������Ψһ��ʶ��
	BOOL32 bOpen; ///<true ������false �رգ��������ƣ���Ӧcamera.proto�ļ��е�on�ֶ�
public:
	tagTMtElectronicNamePlateState(){ memset( this ,0 ,sizeof( struct  tagTMtElectronicNamePlateState ) );}	
}*PTMtElectronicNamePlateState, TMtElectronicNamePlateState;

/*֪ͨǩ�������������*/
///< Ev_AICamera_PeopleCountingResult_Ntf
typedef struct tagTMtPeopleCountingResult
{
	s8  achCameraID[CAMERA_MAX_ID_LEN+1];       ///<  ���������Id����Ϊ�������Ψһ��ʶ��
	u32 dwPeopleNum; ///<��⵽��ǩ������
public:
	tagTMtPeopleCountingResult(){ memset( this ,0 ,sizeof( struct  tagTMtPeopleCountingResult ) );}
}*PTMtPeopleCountingResult, TMtPeopleCountingResult;

/*֪ͨ����ͳ��״̬*/
///< Ev_AICamera_PeopleCountingState_Ntf
typedef struct tagTMtPeopleCountingState
{
	s8  achCameraID[CAMERA_MAX_ID_LEN+1];       ///<  ���������Id����Ϊ�������Ψһ��ʶ��
	BOOL32 bOpen; ///<true ������false �رգ��������ƣ���Ӧcamera.proto�ļ��е�on�ֶ�
public:
	tagTMtPeopleCountingState(){ memset( this ,0 ,sizeof( struct  tagTMtPeopleCountingState ) );}	
}*PTMtPeopleCountingState, TMtPeopleCountingState;

/*�˽ӿ�����device��������Ŀ��Ƶĸ�������
���£�
 Ev_AICamera_OpenPeopleCounting_Cmd��������ͳ��
 Ev_AICamera_ClosePeopleCounting_Cmd�ر�����ͳ��
 Ev_AICamera_OpenElectronicNamePlate_Cmd������������
 Ev_AICamera_CloseElectronicNamePlate_Cmd�رյ�������
 Ev_AICamera_OpenFaceCheckIn_Cmd��������ǩ��
 Ev_AICamera_CloseFaceCheckIn_Cmd�ر�����ǩ��
*/
typedef struct tagTMtCameraCtrl
{
	s8  achCameraID[CAMERA_MAX_ID_LEN+1];       ///<  ���������Id����Ϊ�������Ψһ��ʶ��
public:
	tagTMtCameraCtrl(){ memset( this ,0 ,sizeof( struct  tagTMtCameraCtrl ) );}	
}*PTMtCameraCtrl, TMtCameraCtrl;


#endif

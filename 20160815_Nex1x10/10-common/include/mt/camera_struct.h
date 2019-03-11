#ifndef _CAMERA_STRUCT_H_
#define _CAMERA_STRUCT_H_
//#include "kdvdef.h"
#include "kdvtype.h"
#include <string.h>
#define CAMERA_MAX_ID_LEN (u32)32  //<暂定32
#define CAMERA_MAX_NUM (u32)20  //一次人脸签到最多20个人
#define CMAERA_MAX_POSITION_LEN (u32)256 //<员工职位的最大字节数
#define AICAMERA_INSTANCE_ID 1 

#define CAMERA_APP_NO 0x40 //摄像机app Id
#define CAMERA_RECONNECT_TIME 30*1000  // 30秒
#define CAMERA_NULL "null"
/*添加摄像机时需要device传递的信息*/
///<EV_AICAMERA_AddCamera_Cmd

typedef struct tagTMtAddCamera
{
	u32 dwIp;                                         ///< 智能摄像机ip (网络序)
	u32 dwPort;                                       ///< 智能摄像机的端口
	s8  achCameraID[CAMERA_MAX_ID_LEN+1];       ///<  智能摄像机Id（作为摄像机的唯一标识）
public:
	tagTMtAddCamera(){ memset( this ,0 ,sizeof( struct  tagTMtAddCamera ) );}
}*PTMtAddCamera, TMtAddCamera;

/*摄像机信息通知给device的信息（通知上去）*/
///<Ev_AICamera_AddCamera_Ntf
typedef struct tagTMtCameraInfo
{
	s8  	achCameraID[CAMERA_MAX_ID_LEN+1];       ///<  智能摄像机Id（作为摄像机的唯一标识）
	s8  	achCameraname[CAMERA_MAX_ID_LEN+1];     ///<摄像机名称
	s8  	achCameraModel[CAMERA_MAX_ID_LEN+1];     ///<摄像机型号
	BOOL32  bSupportPeopleCounting;      			     ///<是否支持人数统计功能
	BOOL32  bSupportElectronicNameplate; 			     ///<是否支持电子铭牌功能
	BOOL32  bSupportFaceCheckIn;        			         ///<是否支持人脸签到功能
public:
	tagTMtCameraInfo(){ memset( this ,0 ,sizeof( struct  tagTMtCameraInfo ) );}
}*PTMtCameraInfo, TMtCameraInfo;

/*签到人信息*/
typedef struct tagTMtCheckInInfo
{
    s8 achName[CAMERA_MAX_ID_LEN+1]; ///<签到人姓名
	s8 achTime[CAMERA_MAX_ID_LEN+1]; ///<签到时间 (签到时间待定)
	s8 achPosition[CMAERA_MAX_POSITION_LEN+1];///<员工职位
public:
	tagTMtCheckInInfo(){ memset( this ,0 ,sizeof( struct  tagTMtCheckInInfo ) );}
}*PTMtCheckInInfo, TMtCheckInInfo;

/*人脸签到信息通知给device的信息（通知上去）*/
///<Ev_AICamera_FaceCheckInInfo_Ntf
typedef struct tagTMtFaceCheckInInfos
{
	u32 dwNum;			///<个数
	s8  achCameraID[CAMERA_MAX_ID_LEN+1];       ///<  智能摄像机Id（作为摄像机的唯一标识）
	TMtCheckInInfo  atFaceCheckInInfos[CAMERA_MAX_NUM+1]; ///<暂定20一次通知签到人信息的数组（最多）
public:
	tagTMtFaceCheckInInfos(){ memset( this ,0 ,sizeof( struct  tagTMtFaceCheckInInfos ) );}
}*PTMtFaceCheckInInfos, TMtFaceCheckInInfos;

/*通知人脸签到状态*/
///< Ev_AICamera_FaceCheckInState_Ntf
typedef struct tagTMtFaceCheckInState
{
	s8  achCameraID[CAMERA_MAX_ID_LEN+1];       ///<  智能摄像机Id（作为摄像机的唯一标识）
	BOOL32 bOpen; ///<true 开启，false 关闭（电子名牌）对应camera.proto文件中的on字段
public:
	tagTMtFaceCheckInState(){ memset( this ,0 ,sizeof( struct  tagTMtFaceCheckInState ) );}	
}*PTMtFaceCheckInState, TMtFaceCheckInState;

/*通知电子名牌状态*/
///< Ev_AICamera_ElectronicNamePlateState_Ntf
typedef struct tagTMtElectronicNamePlateState
{
	s8  achCameraID[CAMERA_MAX_ID_LEN+1];       ///<  智能摄像机Id（作为摄像机的唯一标识）
	BOOL32 bOpen; ///<true 开启，false 关闭（电子名牌）对应camera.proto文件中的on字段
public:
	tagTMtElectronicNamePlateState(){ memset( this ,0 ,sizeof( struct  tagTMtElectronicNamePlateState ) );}	
}*PTMtElectronicNamePlateState, TMtElectronicNamePlateState;

/*通知签到的人数检测结果*/
///< Ev_AICamera_PeopleCountingResult_Ntf
typedef struct tagTMtPeopleCountingResult
{
	s8  achCameraID[CAMERA_MAX_ID_LEN+1];       ///<  智能摄像机Id（作为摄像机的唯一标识）
	u32 dwPeopleNum; ///<检测到的签到人数
public:
	tagTMtPeopleCountingResult(){ memset( this ,0 ,sizeof( struct  tagTMtPeopleCountingResult ) );}
}*PTMtPeopleCountingResult, TMtPeopleCountingResult;

/*通知人数统计状态*/
///< Ev_AICamera_PeopleCountingState_Ntf
typedef struct tagTMtPeopleCountingState
{
	s8  achCameraID[CAMERA_MAX_ID_LEN+1];       ///<  智能摄像机Id（作为摄像机的唯一标识）
	BOOL32 bOpen; ///<true 开启，false 关闭（电子名牌）对应camera.proto文件中的on字段
public:
	tagTMtPeopleCountingState(){ memset( this ,0 ,sizeof( struct  tagTMtPeopleCountingState ) );}	
}*PTMtPeopleCountingState, TMtPeopleCountingState;

/*此接口用于device对摄像机的控制的各种命令
如下：
 Ev_AICamera_OpenPeopleCounting_Cmd开启人数统计
 Ev_AICamera_ClosePeopleCounting_Cmd关闭人数统计
 Ev_AICamera_OpenElectronicNamePlate_Cmd开启电子铭牌
 Ev_AICamera_CloseElectronicNamePlate_Cmd关闭电子铭牌
 Ev_AICamera_OpenFaceCheckIn_Cmd开启人脸签到
 Ev_AICamera_CloseFaceCheckIn_Cmd关闭人脸签到
*/
typedef struct tagTMtCameraCtrl
{
	s8  achCameraID[CAMERA_MAX_ID_LEN+1];       ///<  智能摄像机Id（作为摄像机的唯一标识）
public:
	tagTMtCameraCtrl(){ memset( this ,0 ,sizeof( struct  tagTMtCameraCtrl ) );}	
}*PTMtCameraCtrl, TMtCameraCtrl;


#endif

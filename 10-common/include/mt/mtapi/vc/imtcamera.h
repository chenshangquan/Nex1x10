/**===========================================================================
 * @file    $Id$
 * @brief   负责终端摄像机相关控制接口定义
 * @author  $Author$
 * @date    $Date$
 * @version  $Revision$ 
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note    
============================================================================*/

#ifndef _I_MTCAMERA_H_
#define _I_MTCAMERA_H_

#include "mtapi_typedef.h"
#include "mtapi_if.h"
#include "mtapi_event_vc.h"


/**---------------------------------------------------------------------------
 * @class   Interface IMtCamera
 * @brief   负责终端摄像机相关控制接口定义
 * @author  $Author$
 * @version 
 * @date    $Date::                      $
 * @note    
 ---------------------------------------------------------------------------*/

class IMtCamera : public IMtApiIF
{
static	TMtId_Api tDefaultId;
public:
	//摄像头选择
	virtual u32 CameraSelectCmd( EmCodecComponentIndex_Api emVideoIndex, u8 byIndex ) = 0;
	//摄像头预置位操作
	virtual u32 CameraPresetReq( EmCodecComponentIndex_Api emVideoIndex, BOOL32 bSava, u8 byIndex ) = 0;
	//获取当前码流对应预置位请求
	virtual u32 GetCurCodecPresetIndexReq( EmCodecComponentIndex_Api emVideoIndex) = 0;
	//摄像头方位调节
	virtual u32 CameraPantiltCmd( EmCodecComponentIndex_Api emVideoIndex, EmDirection_Api emDir, EmAction_Api emAction ) = 0;
	//摄像头焦距调节
	virtual u32 CameraFocusCmd( EmCodecComponentIndex_Api emVideoIndex, BOOL32 bFar, EmAction_Api emAction ) = 0;
	//摄像头自动聚焦
	virtual u32 CameraAutoFocusCmd(EmCodecComponentIndex_Api emVideoIndex) = 0;
	//摄像头视野调节
	virtual u32 CameraZoomCmd( EmCodecComponentIndex_Api emVideoIndex, BOOL32 bZoomOut, EmAction_Api emAction ) = 0;
	//摄像头亮度调节
	virtual u32 CameraBrightCmd( EmCodecComponentIndex_Api emVideoIndex, BOOL32 bBrightenUp, EmAction_Api emAction ) = 0;
	//摄像头背光补偿
	virtual u32 CameraBackLightCmd( EmCodecComponentIndex_Api emVideoIndex, BOOL32 bOn ) = 0;
	//摄像头升级
	virtual u32 CameraUpgradeCmd( EmMtVideoPort_Api emVideoIndex, const TMTCameraUpgrade_Api &tCameraUpgrade ) = 0;
	//获取摄像头是否正在升级
	virtual u32 GetIsCameraUpgradingReq() = 0;
	//摄像头版本查询
	virtual u32 CameraVersionReq(EmCodecComponentIndex_Api emVideoIndex) = 0;	
	//选择控制射像头
	virtual u32  FeccCameraSelectCmd( const TMtId_Api * ptId , u8 byCameraIndex ) = 0;
	//摄像头聚焦命令
	virtual u32  FeccCameraFocusCmd( const EmCodecComponentIndex_Api emVideoIndex, const TMtId_Api * ptId, BOOL32 bNearFocus, EmAction_Api emAction ) = 0;
	//摄像头自动聚焦命令
	virtual u32  FeccCameraAutoFocusCmd( const EmCodecComponentIndex_Api emVideoIndex, const TMtId_Api * ptId ) = 0;
	//摄像视野命令
	virtual u32  FeccCameraZoomCmd( const EmCodecComponentIndex_Api emVideoIndex, const TMtId_Api * ptId, BOOL32 bZoonmIn, EmAction_Api emAction ) = 0;
	//摄像亮度调节命令
	virtual u32  FeccCameraBrightCmd( const EmCodecComponentIndex_Api emVideoIndex, const TMtId_Api * ptId, BOOL32 bLight, EmAction_Api emAction ) = 0;
	//预置位命令
	virtual u32  FeccCameraPresetByIdxCmd( const EmCodecComponentIndex_Api emVideoIndex, const TMtId_Api * ptId, BOOL32 bSave, u8 byIndex ) = 0;
	//预置位命令
	virtual u32  FeccCameraPresetCmd( const TMtId_Api * ptId, BOOL32 bSave, u8 byIndex ) = 0;
	//摄像头移动命令 >>
	virtual u32  FeccCameraPantiltCmd( const EmCodecComponentIndex_Api emVideoIndex, const TMtId_Api * ptId, EmDirection_Api emDirection, EmAction_Api emAction ) = 0;
	//选择视频源
	virtual u32  FeccVideoSourceSelCmd( const EmCodecComponentIndex_Api emComIndex, const TMtId_Api * ptId, u8 byVideoIndex ) = 0;
	//摄像头能力类型查询
	virtual u32 GetCameraTypeCapsetReq() = 0;
	//获取硬终端支持的摄像头类型
	virtual TMTCameraTypeList_Api GetCameraTypeList() =0;

	//设置摄像头图像参数命令，仅windows
	virtual u32  CameraSetParamCmd( const TImageParam_Api &tImgParam ) = 0;
	//获取摄像头图像参数命令，仅windows
	virtual u32  CameraGetParamReq( const EmImgParam_Api emImgParamType ) = 0;
	//获取摄像头默认图像参数命令，仅windows
	virtual u32  CameraGetDefaultParamReq( const EmImgParam_Api emImgParamType ) = 0;
	//查询预置位图片请求
	virtual u32 QueryCameraPresetPicReq(const EmCodecComponentIndex_Api emVideoIndex) = 0;
	//设置摄像头本地还是远端操作
	virtual u32 SetCameraSite(const EmSite_Api emSite) = 0;
	virtual EmSite_Api GetCameraSite() = 0;
	virtual u32 CameraGetCtrlSiteReq() = 0;
	virtual u32 ControlCameraOsdCmd(const EmCodecComponentIndex_Api emVideoIndex,const EmTerControlCameraOsdType_Api emCameraOsdType ) = 0;
};

#endif // _I_MTCAMERA_H_
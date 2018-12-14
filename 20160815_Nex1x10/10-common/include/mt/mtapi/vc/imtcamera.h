/**===========================================================================
 * @file    $Id$
 * @brief   �����ն��������ؿ��ƽӿڶ���
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
 * @brief   �����ն��������ؿ��ƽӿڶ���
 * @author  $Author$
 * @version 
 * @date    $Date::                      $
 * @note    
 ---------------------------------------------------------------------------*/

class IMtCamera : public IMtApiIF
{
static	TMtId_Api tDefaultId;
public:
	//����ͷѡ��
	virtual u32 CameraSelectCmd( EmCodecComponentIndex_Api emVideoIndex, u8 byIndex ) = 0;
	//����ͷԤ��λ����
	virtual u32 CameraPresetReq( EmCodecComponentIndex_Api emVideoIndex, BOOL32 bSava, u8 byIndex ) = 0;
	//��ȡ��ǰ������ӦԤ��λ����
	virtual u32 GetCurCodecPresetIndexReq( EmCodecComponentIndex_Api emVideoIndex) = 0;
	//����ͷ��λ����
	virtual u32 CameraPantiltCmd( EmCodecComponentIndex_Api emVideoIndex, EmDirection_Api emDir, EmAction_Api emAction ) = 0;
	//����ͷ�������
	virtual u32 CameraFocusCmd( EmCodecComponentIndex_Api emVideoIndex, BOOL32 bFar, EmAction_Api emAction ) = 0;
	//����ͷ�Զ��۽�
	virtual u32 CameraAutoFocusCmd(EmCodecComponentIndex_Api emVideoIndex) = 0;
	//����ͷ��Ұ����
	virtual u32 CameraZoomCmd( EmCodecComponentIndex_Api emVideoIndex, BOOL32 bZoomOut, EmAction_Api emAction ) = 0;
	//����ͷ���ȵ���
	virtual u32 CameraBrightCmd( EmCodecComponentIndex_Api emVideoIndex, BOOL32 bBrightenUp, EmAction_Api emAction ) = 0;
	//����ͷ���ⲹ��
	virtual u32 CameraBackLightCmd( EmCodecComponentIndex_Api emVideoIndex, BOOL32 bOn ) = 0;
	//����ͷ����
	virtual u32 CameraUpgradeCmd( EmMtVideoPort_Api emVideoIndex, const TMTCameraUpgrade_Api &tCameraUpgrade ) = 0;
	//��ȡ����ͷ�Ƿ���������
	virtual u32 GetIsCameraUpgradingReq() = 0;
	//����ͷ�汾��ѯ
	virtual u32 CameraVersionReq(EmCodecComponentIndex_Api emVideoIndex) = 0;	
	//ѡ���������ͷ
	virtual u32  FeccCameraSelectCmd( const TMtId_Api * ptId , u8 byCameraIndex ) = 0;
	//����ͷ�۽�����
	virtual u32  FeccCameraFocusCmd( const EmCodecComponentIndex_Api emVideoIndex, const TMtId_Api * ptId, BOOL32 bNearFocus, EmAction_Api emAction ) = 0;
	//����ͷ�Զ��۽�����
	virtual u32  FeccCameraAutoFocusCmd( const EmCodecComponentIndex_Api emVideoIndex, const TMtId_Api * ptId ) = 0;
	//������Ұ����
	virtual u32  FeccCameraZoomCmd( const EmCodecComponentIndex_Api emVideoIndex, const TMtId_Api * ptId, BOOL32 bZoonmIn, EmAction_Api emAction ) = 0;
	//�������ȵ�������
	virtual u32  FeccCameraBrightCmd( const EmCodecComponentIndex_Api emVideoIndex, const TMtId_Api * ptId, BOOL32 bLight, EmAction_Api emAction ) = 0;
	//Ԥ��λ����
	virtual u32  FeccCameraPresetByIdxCmd( const EmCodecComponentIndex_Api emVideoIndex, const TMtId_Api * ptId, BOOL32 bSave, u8 byIndex ) = 0;
	//Ԥ��λ����
	virtual u32  FeccCameraPresetCmd( const TMtId_Api * ptId, BOOL32 bSave, u8 byIndex ) = 0;
	//����ͷ�ƶ����� >>
	virtual u32  FeccCameraPantiltCmd( const EmCodecComponentIndex_Api emVideoIndex, const TMtId_Api * ptId, EmDirection_Api emDirection, EmAction_Api emAction ) = 0;
	//ѡ����ƵԴ
	virtual u32  FeccVideoSourceSelCmd( const EmCodecComponentIndex_Api emComIndex, const TMtId_Api * ptId, u8 byVideoIndex ) = 0;
	//����ͷ�������Ͳ�ѯ
	virtual u32 GetCameraTypeCapsetReq() = 0;
	//��ȡӲ�ն�֧�ֵ�����ͷ����
	virtual TMTCameraTypeList_Api GetCameraTypeList() =0;

	//��������ͷͼ����������windows
	virtual u32  CameraSetParamCmd( const TImageParam_Api &tImgParam ) = 0;
	//��ȡ����ͷͼ����������windows
	virtual u32  CameraGetParamReq( const EmImgParam_Api emImgParamType ) = 0;
	//��ȡ����ͷĬ��ͼ����������windows
	virtual u32  CameraGetDefaultParamReq( const EmImgParam_Api emImgParamType ) = 0;
	//��ѯԤ��λͼƬ����
	virtual u32 QueryCameraPresetPicReq(const EmCodecComponentIndex_Api emVideoIndex) = 0;
	//��������ͷ���ػ���Զ�˲���
	virtual u32 SetCameraSite(const EmSite_Api emSite) = 0;
	virtual EmSite_Api GetCameraSite() = 0;
	virtual u32 CameraGetCtrlSiteReq() = 0;
	virtual u32 ControlCameraOsdCmd(const EmCodecComponentIndex_Api emVideoIndex,const EmTerControlCameraOsdType_Api emCameraOsdType ) = 0;
};

#endif // _I_MTCAMERA_H_
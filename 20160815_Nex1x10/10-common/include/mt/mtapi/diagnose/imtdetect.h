/**===========================================================================
 * @file    $Id$
 * @brief   ����MtBaseApi�ն���Ͽ�����ع��ܽӿڶ���
 * @author  $Author$
 * @date    $Date$
 * @version  $Revision$ 
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note    
============================================================================*/

#ifndef _I_MTDETECT_H_
#define _I_MTDETECT_H_

#include "mtapi_typedef.h"
#include "mtapi_if.h"
#include "mtapi_event_base.h"
#include "mtapi_event_diagnose.h"


/**---------------------------------------------------------------------------
 * @class   Interface IMtDetect
 * @brief   ����MMtBaseApi�ն�ץ������־�Լ���������Ͽ�����ع��ܽӿڶ���
 * @author  $Author$
 * @version 
 * @date    $Date::                      $
 * @note    
 ---------------------------------------------------------------------------*/

class IMtDetect : public IMtApiIF
{
public:
	//����ץ������
	virtual u32 StartNetCaptureCmd() = 0;
	//ֹͣץ������
	virtual u32 StopNetCaptureCmd() = 0;
	//����ץ���ļ�����
	virtual u32 ExportNetCaptureReq(IN CONST s8 *pchExportPath) = 0;
	//������־�ļ�����
	virtual u32 ExportLogReq(IN CONST s8 *pchExportPath) = 0;
	//����������
	virtual u32 BandwidthCheckCmd(u32 dwIp) = 0;
    virtual u32 SetOsdSnapshotBrowseStateCmd(BOOL32 bBrowse) = 0;
    virtual u32 SetSyncTooltipBoxCmd(IN CONST s8 *pchUserId) = 0;
    virtual u32 GetNetCapFileListReq() = 0;
    virtual u32 DeleteNetCapFileCmd() = 0;
    virtual u32 ResetUserFileimgCmd(u32 dwFileType) = 0;
    virtual u32 GetNetCapStatusReq() = 0;
    virtual u32 ServerLinkTestCmd(BOOL32 bStart) = 0;
    virtual u32 ThreadDetectRegCmd(TMTServiceInfo_Api tInfo) = 0;
    virtual u32 ThreadDetectUpdateCmd(u32 dwAppId) = 0;

	//��ȡdebug�ļ��Ƿ���ڵ�����
	virtual u32 GetIsDbgCfgExistReq() = 0;
	//��ȡ��˷���Ϣ
	virtual u32 GetMicrophoneInfoReq() = 0;
	//���������Ϣ�ļ�����
	virtual u32 ExportDiagInfoFileCmd(IN CONST s8 *pchExportPath) = 0;
	virtual u32 GetPacketDurationTimeReq() = 0;
	virtual u32 ElectricFanCmd(IN CONST BOOL32 bElectricFan) = 0;
	virtual u32 GetElectricFanTimeReq() = 0;

public:
	//��ȡץ��״̬��Ϣ
	virtual TMtNetCapStateInfo_Api GetNetCaptureState() = 0;
	//��ȡ��������
	virtual TMTNetStatus_Api GetBandwidthTestResult() = 0;
	//��ȡ��ǰץ����Ϣ
	virtual TMtCurCapStatusInfo_Api GetCutCapStatusInfo() = 0;
private:


};

#endif // _I_MTDETECT_H_
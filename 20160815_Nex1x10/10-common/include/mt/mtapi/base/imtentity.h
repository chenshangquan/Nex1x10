/**===========================================================================
 * @file    $Id$
 * @brief   �����ն�����������ܿ��ƵĽӿڶ���
 * @author  $Author$
 * @date    $Date$
 * @version  $Revision$ 
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note    
============================================================================*/

#ifndef _I_MTENTITY_H_
#define _I_MTENTITY_H_

#include "mtapi_typedef.h"
#include "mtapi_if.h"
#include "mtapi_event_base.h"


/**---------------------------------------------------------------------------
 * @class   Interface IMtEntity
 * @brief   �����ն�����������ܿ��ƵĽӿڶ���
 * @author  $Author$
 * @version 
 * @date    $Date::                      $
 * @note    
 ---------------------------------------------------------------------------*/

class IMtEntity : public IMtApiIF
{
public:
	//�ն˴������� (��Embed)
	virtual u32 MtSleepCmd() = 0;
	//�ն˻������� (��Embed)
	virtual u32 MtWakeupCmd() = 0;
	//�ն���������
	virtual u32 MtRebootCmd() = 0;
	//�ָ���������
	virtual u32 MtResetCmd( const BOOL32 bDelCfgFile ) = 0;
 
	//����������
	virtual u32 CheckUpgradeCmd( const TMTUpgradeClientInfo_Api& tInfo ) = 0;
	//ȡ������������
	virtual u32 CancelCheckUpgradeCmd( ) = 0;
	//��ʼ�����ļ�����
	virtual u32 StartDownloadUpgradeFileCmd( const s8* pchSaveFilePath, const u32 dwVerId ) = 0;
	//ȡ�������ļ�����
	virtual u32 CancelDownloadUpgradeFileCmd() = 0;
	//��ʼ��������
	virtual u32 StartUpgradeCmd(EmUpgradeType_Api emUpgradeType) = 0;

	virtual u32 UsbUpgradeFileCheckReq(const s8 *pchFilePath) = 0;


public:
	//�Ƿ����(��Embed)
	virtual BOOL32 IsSleeped() = 0;
	//��ȡ��������ʱʣ��ʱ��(��Embed)
	virtual u16 GetSleepReaminTime() = 0;
    virtual u32 GetSkyShareVerReq() = 0;
	virtual u32 GetSkyMtcVerRtReq() = 0;
	virtual u32 ResetOsdAdminPwdCmd() = 0;
	virtual u32 SetDeviceCameraSleepCmd( const BOOL32 bSleep ) = 0;

	//����ͬ������
	virtual u32 UISynchronize_Cmd( const EmUISynchronizeReason_Api emReason ) = 0 ;

private:

};

#endif // _I_MTENTITY1_H_
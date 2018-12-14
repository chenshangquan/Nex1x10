/**===========================================================================
 * @file    $Id$
 * @brief   �����ն�����������ܿ��ƵĽӿڶ���
 * @author  $Author$
 * @date    $Date$
 * @version  $Revision$ 
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note    
============================================================================*/

#ifndef _I_NVENTITY_H_
#define _I_NVENTITY_H_

#include "nvapi_typedef.h"
#include "nvapi_if.h"
#include "nvapi_event_base.h"


/**---------------------------------------------------------------------------
 * @class   Interface INvEntity
 * @brief   �����ն�����������ܿ��ƵĽӿڶ���
 * @author  $Author$
 * @version 
 * @date    $Date::                      $
 * @note    
 ---------------------------------------------------------------------------*/

class INvEntity : public INvApiIF
{
public:
	//�ն˴������� (��Embed)
	virtual u32 NvSleepCmd() = 0;
	//�ն˻������� (��Embed)
	virtual u32 NvWakeupCmd() = 0;
	//�ն���������
	virtual u32 NvRebootCmd() = 0;
	//�ָ���������
	virtual u32 NvResetCmd() = 0;
 
	//����������
	virtual u32 CheckUpgradeCmd( const nv::TNVUpgradeClientInfo& tInfo ) = 0;
	//ȡ������������
	virtual u32 CancelCheckUpgradeCmd( ) = 0;
	//��ʼ�����ļ�����
	virtual u32 StartDownloadUpgradeFileCmd( const nv::TString &tSaveFilePath, const u32 dwVerId ) = 0;
	//ȡ�������ļ�����
	virtual u32 CancelDownloadUpgradeFileCmd() = 0;
	//��ʼ��������
	virtual u32 StartUpgradeCmd(EmNvUpgradeType_Api emUpgradeType) = 0;
	virtual u32 UsbUpgradeFileCheckReq(const nv::TString &tstrFilePath) = 0;
	//�ػ��ظ�
	virtual u32 NvTurnOffReq(const nv::TBOOL32 btTurnOff) = 0;
	//App����״̬֪ͨ
	virtual u32 NvAppUpgradeStatusNtf(const nv::TBOOL32 bUpgrade) = 0;
	//Ͷ��������״̬֪ͨ
	virtual u32 NvQkUpgradeStatusNtf(const nv::TBOOL32 bUpgrade) = 0;

	//����Ͷ����������
	virtual u32 UpgradeQuickShareCmd( ) = 0;
	//��ȡ����Ͷ�����汾
	virtual u32 GetQuickShareVersionCmd( ) = 0;
	virtual u32 CancelUpgradeQuickShareCmd( ) = 0;
	virtual u32 SetNovaCmd() = 0;
	virtual u32 DelAppZip() = 0;
	virtual u32 GetImixMode() = 0;
	virtual u32 GetQKVersionReq() = 0;
	virtual u32 NvAppUpgradeIsSucNtf(const nv::TBOOL32 bUpgrade) = 0;
	virtual u32 NvPadIsDownSucNtf(const nv::TBOOL32 bUpgrade) = 0;
	virtual u32 NvPadDownStateNtf(const nv::TBOOL32 bUpgrade) = 0;
	virtual u32 NvRouterIsDownSucNtf(const nv::TBOOL32 bUpgrade) = 0;
	virtual u32 NvRouterDownStateNtf(const nv::TBOOL32 bUpgrade) = 0;
	virtual u32 GetPadVersionReq() = 0;
	virtual u32 NvRouterUpgradeStateNty(const nv::TBOOL32 bState) = 0;
	//virtual u32 NvClearDataFolderSucNty(const nv::TBOOL32 bState) = 0;
	//virtual u32 NvCancelFileCmd(const nv::TString tFile) = 0;
public:
	//�Ƿ����(��Embed)
	virtual BOOL32 IsSleeped() = 0;
	//��ȡ��������ʱʣ��ʱ��(��Embed)
	virtual u16 GetSleepReaminTime() = 0;

	//����ͬ������
	virtual u32 UISynchronize_Cmd( const EmNvUISynchronizeReason_Api emReason ) = 0 ;

private:

};

#endif // _I_NVENTITY1_H_
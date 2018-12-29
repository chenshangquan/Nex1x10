/**===========================================================================
 * @file    $Id$
 * @brief   �������ݹ���������ع��ܽӿڶ���
 * @author  $Author$
 * @date    $Date$
 * @version  $Revision$ 
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note    
============================================================================*/

#ifndef _I_NVRNVDATSHARE_H_
#define _I_NVRNVDATSHARE_H_

#include "nvapi_typedef.h"
#include "nvapi_if.h"
#include "nvapi_event_base.h"
#include "invdatashare.h"


/**---------------------------------------------------------------------------
 * @class   Interface INvConfig
 * @brief   �����ն˻�������������ع��ܽӿڶ���
 * @author  $Author$
 * @version 
 * @date    $Date::                      $
 * @note    
 ---------------------------------------------------------------------------*/

class INvRnvDataShare : public INvDataShare
{
public:
	// ��ȡ�Ƿ������ļ���־����
	virtual u32 GetIsUsedFileLogonReq()=0;
	virtual BOOL32 GetIpReq(const EmNvIpType_Api )=0;                       //��ȡIp����
	//��ȡʱ��
	virtual u32 GetTimeZoneReq()=0;
	//��ȡ��ʾ������
	virtual u32 GetScreenCfgReq()=0;
	//��ȡ�ն˰汾��Ϣ����
	virtual u32 GetTerinfoRtReq()=0;
	//��ȡ��ʾ����Ŀ
	virtual u32 GetScreenNumCfgReq()=0;
    //��ȡ��̨������������
	virtual u32 GetBackstageUpgradeCfgReq()=0;
	//��ȡ��Ƶ�ź�����
	virtual u32 GetImixVidSrcSignalRtReq()=0;
	//��ȡHDMI����״̬
	virtual u32 GetHdmiSwitchCfgReq()=0;
	//��ȡ��1080�ֱ���ʱ��ʾ����
	virtual u32 GetVidResResizeModeCfgReq() = 0;
	//��ȡ˫�����Դ����������
	virtual u32 GetIsMtDualLeftCfgReq() = 0;
	//��ȡ�汾��Ϣ
	virtual u32 GetImixVerInfoRtReq() = 0;
	//��ȡnv�汾��ǰ��Ϣ
	virtual u32 GetNvVerInfoReq() = 0;
	//��ȡimix�汾�Ƿ���JDƽ̨�汾һ��
	virtual u32 GetNVVerIsSameAsJDServeReq(IN CONST nv::TString tRouterVer) = 0;
	//����imix�Ƿ��JDƽ̨���ذ汾
	virtual u32 SetNVIsUpgradeFromJDServerCmd(IN CONST nv::TBOOL32 tUpgrade) = 0;
private:

};

#endif // _I_NVRNVDATSHARE_H_

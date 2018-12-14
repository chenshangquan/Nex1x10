/**===========================================================================
 * @file    $Id$
 * @brief   �����ն������������ݲ����Ľӿڶ���
 * @author  $Author$
 * @date    $Date$
 * @version  $Revision$ 
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note    
============================================================================*/

#ifndef _I_NVDATASHARE_H_
#define _I_NVDATASHARE_H_

#include "nvapi_typedef.h"
#include "nvapi_if.h"


/**---------------------------------------------------------------------------
 * @class   Interface INvEntity
 * @brief   �����ն������������ݲ����Ľӿڶ���
 * @author  $Author$
 * @version 
 * @date    $Date::                      $
 * @note    
 ---------------------------------------------------------------------------*/

class INvDataShare : public INvApiIF
{
public:
	//��ԭĬ��ֵ
	virtual u32 RestoreDefaultCfgInfo( const nv::TNVRestoreDefaultCfgInfo &tCfg );
	// �����Ƿ������ļ���־ emNv_Cfg_Log
	virtual u32 SetIsUsedFileLogon( BOOL32 bUsed );

	virtual BOOL32 SetIp(const EmNvIpType_Api, const s8 *);    //����Ip
	virtual BOOL32 SetImixIp(const nv::TNVNetUsedInfo tNvNetInfoCfg);                     //����Imix Ip

	// ��ȡ�Ƿ������ļ���־ emNv_Cfg_Log
	virtual BOOL32 IsUsedFileLogon()=0;
	//����ʱ��
	virtual u32 SetTimeZoneCmd( const nv::EmNvTimeZone emCfg );
	//������ʾ������
	virtual u32 SetScreenCmd( const nv::TNVScreenParamList tCfg );
	//������ʾ������
	virtual u32 SetScreenNumCmd( const nv::TU32 tCfg );
	//��̨��������
	virtual u32 SetBackstageUpgradeCmd(const nv::TBOOL32 tbCfg);
	//���÷�1080�ֱ���ʱ��ʾ����
	virtual u32 SetVidResResizeModeCfgCmd(const nv::TS32 tMode);
	//����˫�����Դ����������
	virtual u32 SetIsMtDualLeftCfgCmd(const nv::TBOOL32 tbCfg);
	
protected:
	virtual void BuildMsgMap();
	// �����ļ���־��������֪ͨ
	BOOL32 OnLogStatusCfg_Ntf( nvmsg::CNvMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	BOOL32 OnIpCfg_Ntf( nvmsg::CNvMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	BOOL32 OnSetTimeZoneCfg_Ntf( nvmsg::CNvMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	BOOL32 OnSetScreenCfg_Ntf( nvmsg::CNvMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	BOOL32 OnSetTerlInfoRt_Ntf( nvmsg::CNvMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	BOOL32 OnSetScreenNumCfg_Ntf( nvmsg::CNvMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	BOOL32 OnSetBackstageUpgradeCfg_Ntf( nvmsg::CNvMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	BOOL32 OnImixVidSrcSignalRt_Ntf( nvmsg::CNvMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	BOOL32 OnSysUpgradeRt_Ntf( nvmsg::CNvMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	BOOL32 OnSetHdmiSwitchCfg_Ntf( nvmsg::CNvMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	BOOL32 OnSetVidResResizeModeCfg_Ntf( nvmsg::CNvMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
	BOOL32 OnSetIsMtDualLeftCfg_Ntf( nvmsg::CNvMsg *pcMsg, u32 dwSrcId, u32 dwSrcNode );
};

#endif // _I_NVDATASHARE_H_

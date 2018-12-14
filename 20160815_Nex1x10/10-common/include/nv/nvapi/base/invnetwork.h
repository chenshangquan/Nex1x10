/**===========================================================================
 * @file    $Id$
 * @brief   ����NvBaseApi�ն�������ع��ܽӿڶ���
 * @author  $Author$
 * @date    $Date$
 * @version  $Revision$ 
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note    
============================================================================*/

#ifndef _I_NVNETWORK_H_
#define _I_NVNETWORK_H_

#include "nvapi_typedef.h"
#include "nvapi_if.h"


/**---------------------------------------------------------------------------
 * @class   Interface INvNetwork
 * @brief   ����NvBaseApi�ն�������ع��ܽӿڶ���
 * @author  $Author$
 * @version 
 * @date    $Date::                      $
 * @note    
 ---------------------------------------------------------------------------*/
class INvNetwork: public INvApiIF
{
public:
	//���õ�ǰ����ʱ����Ϣ
	virtual u32 SetSysDataTimeReq(const  nv::TNVTime &tTime) = 0;
	//��ȡ�ն˵�ǰ����ʱ����Ϣ
	virtual u32 GetMtSysDataTimeReq() = 0;
	//��ȡ�ն˵�ǰʱ��������Ϣ
	virtual u32 GetMtSysTimeCfgReq() = 0;
	//ping����Ӧ
	virtual u32 SetPingTestRsp(const nv::TBOOL32 tResult) = 0;
	//��ȡ��ǰ����ʱ����Ϣ
	virtual u32 GetSysDataTimeReq() = 0;
	//��ftp
	virtual u32 OpenFtpCmd( const nv::TBOOL32 tbOpen) = 0;

	//��ȡftp״̬
	virtual u32 GetFtpStateReq() = 0;

};

#endif // _I_NVNETWORK_H_
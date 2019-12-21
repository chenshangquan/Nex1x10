/**===========================================================================
 * @file    $Id$
 * @brief   ����NVSession�Ĺ��ܽӿڶ��壬һ��NV(NV���Ӷ�Ӧһ��Session)
 * @author  $Author$
 * @date    $Date$
 * @version  $Revision$ 
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note    
============================================================================*/

#ifndef _I_NVBASEFSET_H_
#define _I_NVBASEFSET_H_


#include "nvapi_typedef.h"
#include "nvapi_invfset.h"




/**---------------------------------------------------------------------------
 * @class   Interface INvBaseFSet
 * @brief   ����NV�Ự���ӵ���ع��ܵĽӿڶ���,һ��Session����һ��NV
 * @author  $Author$
 * @version 
 * @date    $Date::                      $
 * @note    
 ---------------------------------------------------------------------------*/
class INvBaseFSet : public INvFSet 
{
public:
	virtual u32      ConnectNv( const nv::TNVUserConnectInfo &tConnectInfo, BOOL32 bIsLocalMode = TRUE ) = 0;
	virtual u32      DisConnectNv( const EmNvApiMode_Api emMode = emNvLocMode_Api ) = 0;
	virtual nvstring GetNvIPAddress() const = 0;
	virtual BOOL32   IsIdle()  = 0;
	virtual BOOL32   FakeLogined( BOOL32 bLogined ) = 0;

protected:
	INvBaseFSet( const void* pContext )
		:INvFSet(pContext)
	{

	}
};

#endif // _I_NVBASEFSET_H_
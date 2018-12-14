/**===========================================================================
 * @file    $Id$
 * @brief   ����MTSession�Ĺ��ܽӿڶ��壬һ��MT(MT���Ӷ�Ӧһ��Session)
 * @author  $Author$
 * @date    $Date$
 * @version  $Revision$ 
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note    
============================================================================*/

#ifndef _I_MTBASEFSET_H_
#define _I_MTBASEFSET_H_


#include "mtapi_typedef.h"
#include "mtapi_imtfset.h"




/**---------------------------------------------------------------------------
 * @class   Interface IMtBaseFSet
 * @brief   ����MT�Ự���ӵ���ع��ܵĽӿڶ���,һ��Session����һ��MT
 * @author  $Author$
 * @version 
 * @date    $Date::                      $
 * @note    
 ---------------------------------------------------------------------------*/
class IMtBaseFSet : public IMtFSet 
{
public:
	virtual u32      ConnectMt( TMtcLoginParam_Api * ptParam ) = 0;
	virtual u32      DisConnectMt( const EmMtApiMode_Api emMode = emMtLocMode_Api ) = 0;
	virtual mtstring GetMtIPAddress() const = 0;
	virtual BOOL32   IsIdle()  = 0;
	virtual BOOL32   IsLogin() = 0;

	virtual void     HandShakeReq() = 0;
	virtual void     SetLoginParam(TMtcLoginParam_Api* ptParam)=0;
	virtual u32      GetMtVersionReq() = 0;

protected:
	IMtBaseFSet( const void* pContext )
		:IMtFSet(pContext)
	{

	}
};

#endif // _I_MTBASEFSET_H_
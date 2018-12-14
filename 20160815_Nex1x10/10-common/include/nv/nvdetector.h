/**===========================================================================
 * @file    nvdetector.h
 * @brief   
 * @author  sam
 * @date    
 * @version  
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note
============================================================================*/

#ifndef	_NVDETECTOR_H_
#define _NVDETECTOR_H_

#include "osp.h"
#include "kdvtype.h"
#include "nvstruct.h"
#include "nvmacro.h"
#include "kdvdevtrack.h"

#define DETECTOR_NAME "detector"

struct TDTDevNetParam
{
	u32 dwNetMask;
	TDTDevAddr tAddr;
};

struct TMACAddr 
{
    u8 abyFields[DT_LEN_MACADDR];

    TMACAddr()
    {
        memset(this, 0, sizeof(TMACAddr));
    }
};

struct TIPInfo
{
	u8 abyIpFields[4*4];
	u8 abyIPMaskFields[4*4];
	TIPInfo()
	{
		memset(this,0, sizeof(TIPInfo));
	}
};

struct TDevItem
{
    u8 abyDevMacAddr[DT_LEN_MACADDR];// 设备MAC地址
    TDTDevInfo tDevInfo;// 基本信息
    
    TDevItem()
    {
        memset(this, 0, sizeof(TDevItem));
    }
};

typedef u32 (*GETTERMINALIP_CALLBACK)(TNVDfServiceParam_API *ptDfParam);

extern "C"
{
	/**----------------------------------------------------------------------
	* NvStartBroadcastClient
	* 
	* @brief   启动设备查找客户端
	* @param	TNVDfClientParam_API
	* @return  BOOL32 TRUE:成功启动， FALSE:启动失败
	------------------------------------------------------------------------*/
	NVCBB_API BOOL32 NvStartBroadcastClient(const s8 *pachIfrName/*TNVDfClientParam_API &tDfStartParam*/ );

	/**----------------------------------------------------------------------
	* NvClientAskServerAddr
	* 
	* @brief   是否查找服务器地址
	* @param	BOOL32
	* @return  BOOL32 TRUE:成功启动， FALSE:启动失败
	------------------------------------------------------------------------*/
	NVCBB_API BOOL32 NvClientAskServerAddr(BOOL32 bIsRefresh, const s8 *pIfrName/*u32 dwMsgBodySize, u8* pMsgBodyBuf, BOOL32 bisBroadcast, u32 devip*/);
	
	/**----------------------------------------------------------------------
	* NvStopBroadcastClient
	* 
	* @brief   关闭设备查找客户端
	* @return  BOOL32 TRUE:成功启动， FALSE:启动失败
	------------------------------------------------------------------------*/
	NVCBB_API BOOL32 NvStopBroadcastClient();
	
	
	/**----------------------------------------------------------------------
	* NvSetTerminalIpCallBack
	* 
	* @brief   设置ip地址回调函数
	* @return  BOOL32 TRUE:成功启动， FALSE:启动失败
	------------------------------------------------------------------------*/
	NVCBB_API BOOL32 NvSetTerminalIpCallBack( GETTERMINALIP_CALLBACK pbIpAddr );
};
/*nvdetector线程启动*/
//API BOOL32 nvDetectorStart(TMdlStartParam &tMdlStartParam);
/*nvdetector线程退出*/
//API BOOL32 nvDetectorStop();
#endif


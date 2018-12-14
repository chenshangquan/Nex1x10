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
    u8 abyDevMacAddr[DT_LEN_MACADDR];// �豸MAC��ַ
    TDTDevInfo tDevInfo;// ������Ϣ
    
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
	* @brief   �����豸���ҿͻ���
	* @param	TNVDfClientParam_API
	* @return  BOOL32 TRUE:�ɹ������� FALSE:����ʧ��
	------------------------------------------------------------------------*/
	NVCBB_API BOOL32 NvStartBroadcastClient(const s8 *pachIfrName/*TNVDfClientParam_API &tDfStartParam*/ );

	/**----------------------------------------------------------------------
	* NvClientAskServerAddr
	* 
	* @brief   �Ƿ���ҷ�������ַ
	* @param	BOOL32
	* @return  BOOL32 TRUE:�ɹ������� FALSE:����ʧ��
	------------------------------------------------------------------------*/
	NVCBB_API BOOL32 NvClientAskServerAddr(BOOL32 bIsRefresh, const s8 *pIfrName/*u32 dwMsgBodySize, u8* pMsgBodyBuf, BOOL32 bisBroadcast, u32 devip*/);
	
	/**----------------------------------------------------------------------
	* NvStopBroadcastClient
	* 
	* @brief   �ر��豸���ҿͻ���
	* @return  BOOL32 TRUE:�ɹ������� FALSE:����ʧ��
	------------------------------------------------------------------------*/
	NVCBB_API BOOL32 NvStopBroadcastClient();
	
	
	/**----------------------------------------------------------------------
	* NvSetTerminalIpCallBack
	* 
	* @brief   ����ip��ַ�ص�����
	* @return  BOOL32 TRUE:�ɹ������� FALSE:����ʧ��
	------------------------------------------------------------------------*/
	NVCBB_API BOOL32 NvSetTerminalIpCallBack( GETTERMINALIP_CALLBACK pbIpAddr );
};
/*nvdetector�߳�����*/
//API BOOL32 nvDetectorStart(TMdlStartParam &tMdlStartParam);
/*nvdetector�߳��˳�*/
//API BOOL32 nvDetectorStop();
#endif


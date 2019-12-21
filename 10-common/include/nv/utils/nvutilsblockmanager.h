/*---------------------------------------------------------------------------*/
/*
 * @file    $Id$
 * @brief   �߳�������ѯ�ӿڷ�װ
 * @author  �Ĵ���
 * @date    $Date$
 * @version  $Revision$
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * 
 */
/*---------------------------------------------------------------------------*/


#ifndef _NVBLOCKMANAGER_H_
#define _NVBLOCKMANAGER_H_

#include "kdvtype.h"
#include "nvmacro.h"
/******************************************************************************
* @namespace    NVUTILS
******************************************************************************/
namespace NVUTILS {


class NVCBB_API CRegBlockInfo
{
public:
	CRegBlockInfo();
	~CRegBlockInfo();

public:

	/*!**********************************************************
	* 
	* @brief   ע�������ӿ���Ϣ
	*
	* @param   [in] pchInterfaceInfo:  �ýӿڵ���ϸ������Ϣ
	*
	* @return  NV_SUCCESS: �ɹ�  
			   NV_FAILED:  ʧ��
	*************************************************************/
	u32 RegBlockInfo(s8 *pchInterfaceInfo, ...);


	/*!**********************************************************
	* 
	* @brief   ע�������ӿ���Ϣ (δ�ֶ����õĻ����ڱ�������ʱִ��)
	*
	* @param   [in] ��
	* 
	* @return  NV_SUCCESS: �ɹ�  
			   NV_FAILED:  ʧ��
	*************************************************************/
	u32 UnRegBlockInfo();

private:
	s32 m_nBlockId;
	BOOL32 m_bReged;
};


/*!**********************************************************
* @fn      u32 BlkRegTskIdName(u32 dwThreadId, const s8 *pchTskName)
* @brief   ע������ID�����ƵĹ�����Ϣ
* @param   [in] dwThreadId:  �߳�ID
* @param   [in] pchTskName:   APP����
* @return  NV_SUCCESS: �ɹ�  
           NV_FAILED: ʧ��
*************************************************************/
u32 BlkRegTskIdName(u32 dwThreadId, const s8 *pchTskName);


typedef s32 (*PRINTFUNC)(const char *szFormat, ...);

/*!**********************************************************
* @fn      void BlkSetPrintFunc(PRINTFUNC pfPrintFunc);
* @brief   �����߳�������Ϣ��ӡ�ӿ�
* @param   [in] ��ӡ�ӿں���ָ��
* @return  ��
*************************************************************/
NVCBB_API void BlkSetPrintFunc(PRINTFUNC pfPrintFunc);


/*!**********************************************************
* @fn      u32 BlkGetBlockInfo(s8 achBuf[], u32 dwLen, u32 &dwOutLen)
* @brief   ��ȡ��ǰ�߳�������Ϣ
* @param   [in] achBuf:    ��Ϣ������  
* @param   [in] dwLen:     ����������
* @param   [in] dwOutLen:  ��ȡ����Ϣ��ʵ�ʳ���
* @return  NV_SUCCESS: �ɹ�  
           NV_FAILED: ʧ��
*************************************************************/
u32 BlkGetBlockInfo(s8 achBuf[], u32 dwLen, u32 &dwOutLen);


/*!**********************************************************
* @fn      void BlkShowBlockInfo()
* @brief   ����ָ���Ĵ�ӡ�����ӿڴ�ӡ���߳�������Ϣ
* @return  ��
*************************************************************/
NVCBB_API void BlkShowBlockInfo();

}



#endif //_NVBLOCKMANAGER_H_
/*---------------------------------------------------------------------------*/
/*
 * @file    $Id$
 * @brief   ip��ַ��ع��ú���
 * @author  �Ĵ���
 * @date    $Date$
 * @version  $Revision$
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * 
 */
/*---------------------------------------------------------------------------*/
#ifndef _NVUTILSIPSTRING_
#define _NVUTILSIPSTRING_
#include "kdvtype.h"
#include "nvutilstype.h"
#include "nvmacro.h"

/******************************************************************************
* @namespace    NVUTILS
******************************************************************************/
namespace NVUTILS {



/*!**********************************************************
* 
* @brief    IP��ַת��Ϊ�ַ���
*           �ַ�������utf-8����
* @param    [in] dwIP  <�����ֽ���>
* @param    [out] pchOutIpv4Str ת����õ���IP��ַ 
* @return   NV_SUCCESS:�ɹ� 
            ����:ʧ��
*************************************************************/
NVCBB_API u32 nvTransIPv4ToString(u32 dwIP, s8 *pchOutIpv4Str);


/*!**********************************************************
* 
* @brief    u32������IP��ַת��Ϊ�ַ���
*           �ַ�������utf-8����
* @param    [in] dwIP  <�����ֽ���>
* @param    [out] pchOutIpv4Str ת����õ���IP��ַ 
* @return   NV_SUCCESS:�ɹ� 
            ����:ʧ��
*************************************************************/
NVCBB_API u32 nvTransIPv4BigEndianToString(u32 dwIP, s8 *pchOutIpv4Str);


/*!**********************************************************
* 
* @brief    ��IPv4�ַ���ת����u32��ʽ
* @param    [in]  pchIPAddr: Ҫת����IP�ַ���
* @param    [out] dwIP:   <�����ֽ���>    
* @return   NV_SUCCESS:�ɹ� 
			����:ʧ��
*************************************************************/
NVCBB_API u32 nvGetIPv4FromString(const s8 *pchIPv4Addr, u32 &dwIP);



/*!**********************************************************
* 
* @brief    ��IPv4�ַ���ת����u32�������ʽ
* @param    [in]  pchIPAddr: Ҫת����IP�ַ���
* @param    [out] dwIP:   <�����ֽ���>    
* @return   NV_SUCCESS:�ɹ� 
			����:ʧ��
*************************************************************/
NVCBB_API u32 nvGetIPv4BigEndianFromString(const s8 *pchIPv4Addr, u32 &dwIP);



/*!**********************************************************
*
* @brief   �ж�IPv4��ַ�Ƿ�Ϸ�
* @param   [in] pchIPAddr
* @return  TRUE: �Ϸ� 
           FALSE: ���Ϸ�
*************************************************************/
NVCBB_API BOOL32 nvIsValidIPv4(const s8 *pchIPv4Addr);


/*!**********************************************************
*
* @brief   �ж�IPv4��ַ�Ƿ�Ϸ�
* @param   [in] dwIPv4Addr
* @return  TRUE: �Ϸ� 
           FALSE: ���Ϸ�
*************************************************************/
NVCBB_API BOOL32 nvIsValidIPv4(u32 dwIPv4Addr);


/*!**********************************************************
* 
* @brief   �ж�IPv6��ַ�Ƿ�Ϸ�
* @param   [in] pchIPv6Addr
* @return  TRUE: �Ϸ� 
           FALSE: ���Ϸ�
*************************************************************/
NVCBB_API BOOL32 nvIsValidIPv6(const s8 *pchIPv6Addr);


/*!**********************************************************
*
* @brief   �ж�IPv4��ַ�Ƿ����鲥��ַ
* @param   [in] pchIPv4Addr IP��ַ�ַ��� <�����ֽ���>
* @return  TRUE: ���鲥��ַ 
           FALSE:���鲥��ַ
*************************************************************/
NVCBB_API BOOL32 nvIsMulticastIpv4Addr(const s8 *pchIPv4Addr);


/*!**********************************************************
* 
* @brief   �ж�IPv6��ַ�Ƿ����鲥��ַ
* @param   [in] pchIPv6Addr IP��ַ�ַ��� <�����ֽ���>
* @return  TRUE: ���鲥��ַ 
           FALSE:���鲥��ַ
*************************************************************/
NVCBB_API BOOL32 nvIsMulticastIpv6Addr(const s8 *pchIPv6Addr);


/*!**********************************************************
* 
* @brief   �ж�IPv4��ַ�Ƿ����鲥��ַ 
* @param   [in] dwIPv4  IP��ַ <�����ֽ���>
* @return  TRUE: ���鲥��ַ 
           FALSE:���鲥��ַ
*************************************************************/
NVCBB_API BOOL32 nvIsMulticastIPv4Addr(u32 dwIPv4);



/*!**********************************************************
* 
* @brief   �ж�IPv4��ַ�Ƿ��ǹ㲥��ַ 
* @param   [in] pchIPv4Addr  IP��ַ <�����ֽ���>
* @return  TRUE: �ǹ㲥��ַ 
           FALSE:�ǹ㲥��ַ
*************************************************************/
NVCBB_API BOOL32 nvIsBroadcastIPv4Addr(const s8 *pchIPv4Addr, const s8 *pchSubMask);



/*!**********************************************************
* 
* @brief   �ж�IPv4��ַ�Ƿ��ǹ㲥��ַ 
* @param   [in] dwIPv4  IP��ַ <�����ֽ���>
* @return  TRUE: �ǹ㲥��ַ 
           FALSE:�ǹ㲥��ַ
*************************************************************/
NVCBB_API BOOL32 nvIsBroadcastIPv4Addr(u32 dwIPv4, u32 dwIPv4Mask);



/*!**********************************************************
* 
* @brief   �ж�IPv6��ַ�Ƿ����β���ַ 
* @param   [in] dwIP  IP��ַ <�����ֽ���>
* @return  TRUE: ���β���ַ 
           FALSE:���β���ַ
*************************************************************/
NVCBB_API BOOL32 nvIsAnycastIPv6Addr(const s8 *pchIPv6Addr);



/*!**********************************************************
*
* @brief   ���Ipv4���������Ƿ�Ϸ�
* @param   [in] dwIpv4Addr  IP��ַ  <�����ֽ���>
* @param   [in] dwMask      Ҫ������������
* @return  TRUE:�Ϸ� FALSE:���Ϸ�
*************************************************************/
NVCBB_API BOOL32 nvIsValidIpv4SubMask(const u32 dwIpv4Addr, const u32 dwMask);


/*!**********************************************************
* 
* @brief   ͨ��IPv4��ַ��ȡ��������
* @param   [in] dwIpAddr  IP��ַ
* @return  u32 ��������
*************************************************************/
NVCBB_API u32 nvGetIpv4SubMask(const u32 dwIpv4Addr);


/*!**********************************************************
*
* @brief   ���ж��ַ������ǺϷ���E164����
* @param   [in] pchE164Num E164��
* @return  TRUE:�Ϸ� FALSE:���Ϸ�
*************************************************************/
NVCBB_API BOOL32 nvIsValidE164(const s8 *pchE164Num);


/*!**********************************************************
* 
* @brief   �ж��ַ����ĵ�ַ����
* @param   [in] pchAddr ��ַ�ַ���
* @param   [in] dwLen   �ַ�������
* @return  emIPAddr: IP��ַ 
           emE164:   E164�� 
           emH323id: H323ID
		   emEmail:  
		   emDial:	 �绰 
*************************************************************/
NVCBB_API EmAddrType nvGetAddrType(const s8 *pchAddr, u32 dwLen);


/*!**********************************************************
*
* @brief   ����ת�ַ���
* @param   [in] nVal Ҫת����ֵ
* @param   [in] pchOutBuf �洢ת����Ľ��
* @param   [in] nRadix Ҫת���Ľ���
* @return  ָ��ת������ַ���ָ��
*************************************************************/
NVCBB_API s8 *nv_itoa(s32 nVal, s8 *pchOutBuf, s32 nRadix = 10); 

}


#endif


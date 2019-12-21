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
#ifndef _MTUTILSIPSTRING_
#define _MTUTILSIPSTRING_
#include "kdvtype.h"
#include "mtutilstype.h"
#include "mtmacro.h"

/******************************************************************************
* @namespace    MTUTILS
******************************************************************************/
namespace MTUTILS {



/*!**********************************************************
* 
* @brief    IP��ַת��Ϊ�ַ���
*           �ַ�������utf-8����
* @param    [in] dwIP  <�����ֽ���>
* @param    [out] pchOutIpv4Str ת����õ���IP��ַ 
* @return   MT_SUCCESS:�ɹ� 
            ����:ʧ��
*************************************************************/
MTCBB_API u32 mtTransIPv4ToString(u32 dwIP, s8 *pchOutIpv4Str);


/*!**********************************************************
* 
* @brief    u32������IP��ַת��Ϊ�ַ���
*           �ַ�������utf-8����
* @param    [in] dwIP  <�����ֽ���>
* @param    [out] pchOutIpv4Str ת����õ���IP��ַ 
* @return   MT_SUCCESS:�ɹ� 
            ����:ʧ��
*************************************************************/
MTCBB_API u32 mtTransIPv4BigEndianToString(u32 dwIP, s8 *pchOutIpv4Str);


/*!**********************************************************
* 
* @brief    ��IPv4�ַ���ת����u32��ʽ
* @param    [in]  pchIPAddr: Ҫת����IP�ַ���
* @param    [out] dwIP:   <�����ֽ���>    
* @return   MT_SUCCESS:�ɹ� 
			����:ʧ��
*************************************************************/
MTCBB_API u32 mtGetIPv4FromString(const s8 *pchIPv4Addr, u32 &dwIP);



/*!**********************************************************
* 
* @brief    ��IPv4�ַ���ת����u32�������ʽ
* @param    [in]  pchIPAddr: Ҫת����IP�ַ���
* @param    [out] dwIP:   <�����ֽ���>    
* @return   MT_SUCCESS:�ɹ� 
			����:ʧ��
*************************************************************/
MTCBB_API u32 mtGetIPv4BigEndianFromString(const s8 *pchIPv4Addr, u32 &dwIP);



/*!**********************************************************
*
* @brief   �ж�IPv4��ַ�Ƿ�Ϸ�
* @param   [in] pchIPAddr
* @return  TRUE: �Ϸ� 
           FALSE: ���Ϸ�
*************************************************************/
MTCBB_API BOOL32 mtIsValidIPv4(const s8 *pchIPv4Addr);


/*!**********************************************************
*
* @brief   �ж�IPv4��ַ�Ƿ�Ϸ�
* @param   [in] dwIPv4Addr
* @return  TRUE: �Ϸ� 
           FALSE: ���Ϸ�
*************************************************************/
MTCBB_API BOOL32 mtIsValidIPv4(u32 dwIPv4Addr);


/*!**********************************************************
* 
* @brief   �ж�IPv6��ַ�Ƿ�Ϸ�
* @param   [in] pchIPv6Addr
* @return  TRUE: �Ϸ� 
           FALSE: ���Ϸ�
*************************************************************/
MTCBB_API BOOL32 mtIsValidIPv6(const s8 *pchIPv6Addr);


/*!**********************************************************
*
* @brief   �ж�IPv4��ַ�Ƿ����鲥��ַ
* @param   [in] pchIPv4Addr IP��ַ�ַ��� <�����ֽ���>
* @return  TRUE: ���鲥��ַ 
           FALSE:���鲥��ַ
*************************************************************/
MTCBB_API BOOL32 mtIsMulticastIpv4Addr(const s8 *pchIPv4Addr);


/*!**********************************************************
* 
* @brief   �ж�IPv6��ַ�Ƿ����鲥��ַ
* @param   [in] pchIPv6Addr IP��ַ�ַ��� <�����ֽ���>
* @return  TRUE: ���鲥��ַ 
           FALSE:���鲥��ַ
*************************************************************/
MTCBB_API BOOL32 mtIsMulticastIpv6Addr(const s8 *pchIPv6Addr);


/*!**********************************************************
* 
* @brief   �ж�IPv4��ַ�Ƿ����鲥��ַ 
* @param   [in] dwIPv4  IP��ַ <�����ֽ���>
* @return  TRUE: ���鲥��ַ 
           FALSE:���鲥��ַ
*************************************************************/
MTCBB_API BOOL32 mtIsMulticastIPv4Addr(u32 dwIPv4);



/*!**********************************************************
* 
* @brief   �ж�IPv4��ַ�Ƿ��ǹ㲥��ַ 
* @param   [in] pchIPv4Addr  IP��ַ <�����ֽ���>
* @return  TRUE: �ǹ㲥��ַ 
           FALSE:�ǹ㲥��ַ
*************************************************************/
MTCBB_API BOOL32 mtIsBroadcastIPv4Addr(const s8 *pchIPv4Addr, const s8 *pchSubMask);



/*!**********************************************************
* 
* @brief   �ж�IPv4��ַ�Ƿ��ǹ㲥��ַ 
* @param   [in] dwIPv4  IP��ַ <�����ֽ���>
* @return  TRUE: �ǹ㲥��ַ 
           FALSE:�ǹ㲥��ַ
*************************************************************/
MTCBB_API BOOL32 mtIsBroadcastIPv4Addr(u32 dwIPv4, u32 dwIPv4Mask);



/*!**********************************************************
* 
* @brief   �ж�IPv6��ַ�Ƿ����β���ַ 
* @param   [in] dwIP  IP��ַ <�����ֽ���>
* @return  TRUE: ���β���ַ 
           FALSE:���β���ַ
*************************************************************/
MTCBB_API BOOL32 mtIsAnycastIPv6Addr(const s8 *pchIPv6Addr);



/*!**********************************************************
*
* @brief   ���Ipv4���������Ƿ�Ϸ�
* @param   [in] dwIpv4Addr  IP��ַ  <�����ֽ���>
* @param   [in] dwMask      Ҫ������������
* @return  TRUE:�Ϸ� FALSE:���Ϸ�
*************************************************************/
MTCBB_API BOOL32 mtIsValidIpv4SubMask(const u32 dwIpv4Addr, const u32 dwMask);


/*!**********************************************************
* 
* @brief   ͨ��IPv4��ַ��ȡ��������
* @param   [in] dwIpAddr  IP��ַ
* @return  u32 ��������
*************************************************************/
MTCBB_API u32 mtGetIpv4SubMask(const u32 dwIpv4Addr);


/*!**********************************************************
*
* @brief   ���ж��ַ������ǺϷ���E164����
* @param   [in] pchE164Num E164��
* @return  TRUE:�Ϸ� FALSE:���Ϸ�
*************************************************************/
MTCBB_API BOOL32 mtIsValidE164(const s8 *pchE164Num);


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
MTCBB_API EmAddrType mtGetAddrType(const s8 *pchAddr, u32 dwLen);


/*!**********************************************************
*
* @brief   ����ת�ַ���
* @param   [in] nVal Ҫת����ֵ
* @param   [in] pchOutBuf �洢ת����Ľ��
* @param   [in] nRadix Ҫת���Ľ���
* @return  ָ��ת������ַ���ָ��
*************************************************************/
MTCBB_API s8 *mt_itoa(s32 nVal, s8 *pchOutBuf, s32 nRadix = 10); 


/*!**********************************************************
*
* @brief   �ж��Ƿ�Ϊ�Ϸ���ip��e164����ʽ: 192.168.1.1#0512110000009�� Լ����#Ϊ�ָ���, ip��e164ͬʱ��Ч��Ϊ�Ϸ���
* @param   [in]  pszString
* @param   [out] achIP
* @param   [in]  wIPLen
* @param   [out] achE164
* @param   [in]  wE164Len
* @return  TRUE: �Ϸ� 
           FALSE: ���Ϸ�
*************************************************************/
MTCBB_API BOOL32 IsValidIPAndE164( const s8 *pszString, s8 achIP[], u16 wIPLen, s8 achE164[], u16 wE164Len );

}


#endif


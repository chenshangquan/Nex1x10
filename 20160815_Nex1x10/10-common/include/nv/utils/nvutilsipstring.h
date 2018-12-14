/*---------------------------------------------------------------------------*/
/*
 * @file    $Id$
 * @brief   ip地址相关公用函数
 * @author  瞿戴沣
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
* @brief    IP地址转换为字符串
*           字符串请用utf-8编码
* @param    [in] dwIP  <本机字节序>
* @param    [out] pchOutIpv4Str 转换后得到的IP地址 
* @return   NV_SUCCESS:成功 
            其他:失败
*************************************************************/
NVCBB_API u32 nvTransIPv4ToString(u32 dwIP, s8 *pchOutIpv4Str);


/*!**********************************************************
* 
* @brief    u32网络序IP地址转换为字符串
*           字符串请用utf-8编码
* @param    [in] dwIP  <网络字节序>
* @param    [out] pchOutIpv4Str 转换后得到的IP地址 
* @return   NV_SUCCESS:成功 
            其他:失败
*************************************************************/
NVCBB_API u32 nvTransIPv4BigEndianToString(u32 dwIP, s8 *pchOutIpv4Str);


/*!**********************************************************
* 
* @brief    将IPv4字符串转换成u32形式
* @param    [in]  pchIPAddr: 要转换的IP字符串
* @param    [out] dwIP:   <本机字节序>    
* @return   NV_SUCCESS:成功 
			其他:失败
*************************************************************/
NVCBB_API u32 nvGetIPv4FromString(const s8 *pchIPv4Addr, u32 &dwIP);



/*!**********************************************************
* 
* @brief    将IPv4字符串转换成u32大端序形式
* @param    [in]  pchIPAddr: 要转换的IP字符串
* @param    [out] dwIP:   <网络字节序>    
* @return   NV_SUCCESS:成功 
			其他:失败
*************************************************************/
NVCBB_API u32 nvGetIPv4BigEndianFromString(const s8 *pchIPv4Addr, u32 &dwIP);



/*!**********************************************************
*
* @brief   判断IPv4地址是否合法
* @param   [in] pchIPAddr
* @return  TRUE: 合法 
           FALSE: 不合法
*************************************************************/
NVCBB_API BOOL32 nvIsValidIPv4(const s8 *pchIPv4Addr);


/*!**********************************************************
*
* @brief   判断IPv4地址是否合法
* @param   [in] dwIPv4Addr
* @return  TRUE: 合法 
           FALSE: 不合法
*************************************************************/
NVCBB_API BOOL32 nvIsValidIPv4(u32 dwIPv4Addr);


/*!**********************************************************
* 
* @brief   判断IPv6地址是否合法
* @param   [in] pchIPv6Addr
* @return  TRUE: 合法 
           FALSE: 不合法
*************************************************************/
NVCBB_API BOOL32 nvIsValidIPv6(const s8 *pchIPv6Addr);


/*!**********************************************************
*
* @brief   判断IPv4地址是否是组播地址
* @param   [in] pchIPv4Addr IP地址字符串 <本机字节序>
* @return  TRUE: 是组播地址 
           FALSE:非组播地址
*************************************************************/
NVCBB_API BOOL32 nvIsMulticastIpv4Addr(const s8 *pchIPv4Addr);


/*!**********************************************************
* 
* @brief   判断IPv6地址是否是组播地址
* @param   [in] pchIPv6Addr IP地址字符串 <本机字节序>
* @return  TRUE: 是组播地址 
           FALSE:非组播地址
*************************************************************/
NVCBB_API BOOL32 nvIsMulticastIpv6Addr(const s8 *pchIPv6Addr);


/*!**********************************************************
* 
* @brief   判断IPv4地址是否是组播地址 
* @param   [in] dwIPv4  IP地址 <本机字节序>
* @return  TRUE: 是组播地址 
           FALSE:非组播地址
*************************************************************/
NVCBB_API BOOL32 nvIsMulticastIPv4Addr(u32 dwIPv4);



/*!**********************************************************
* 
* @brief   判断IPv4地址是否是广播地址 
* @param   [in] pchIPv4Addr  IP地址 <本机字节序>
* @return  TRUE: 是广播地址 
           FALSE:非广播地址
*************************************************************/
NVCBB_API BOOL32 nvIsBroadcastIPv4Addr(const s8 *pchIPv4Addr, const s8 *pchSubMask);



/*!**********************************************************
* 
* @brief   判断IPv4地址是否是广播地址 
* @param   [in] dwIPv4  IP地址 <本机字节序>
* @return  TRUE: 是广播地址 
           FALSE:非广播地址
*************************************************************/
NVCBB_API BOOL32 nvIsBroadcastIPv4Addr(u32 dwIPv4, u32 dwIPv4Mask);



/*!**********************************************************
* 
* @brief   判断IPv6地址是否是任播地址 
* @param   [in] dwIP  IP地址 <本机字节序>
* @return  TRUE: 是任播地址 
           FALSE:非任播地址
*************************************************************/
NVCBB_API BOOL32 nvIsAnycastIPv6Addr(const s8 *pchIPv6Addr);



/*!**********************************************************
*
* @brief   检测Ipv4子网掩码是否合法
* @param   [in] dwIpv4Addr  IP地址  <本机字节序>
* @param   [in] dwMask      要检测的子网掩码
* @return  TRUE:合法 FALSE:不合法
*************************************************************/
NVCBB_API BOOL32 nvIsValidIpv4SubMask(const u32 dwIpv4Addr, const u32 dwMask);


/*!**********************************************************
* 
* @brief   通过IPv4地址获取子网掩码
* @param   [in] dwIpAddr  IP地址
* @return  u32 子网掩码
*************************************************************/
NVCBB_API u32 nvGetIpv4SubMask(const u32 dwIpv4Addr);


/*!**********************************************************
*
* @brief   是判断字符串否是合法的E164号码
* @param   [in] pchE164Num E164号
* @return  TRUE:合法 FALSE:不合法
*************************************************************/
NVCBB_API BOOL32 nvIsValidE164(const s8 *pchE164Num);


/*!**********************************************************
* 
* @brief   判断字符串的地址类型
* @param   [in] pchAddr 地址字符串
* @param   [in] dwLen   字符串长度
* @return  emIPAddr: IP地址 
           emE164:   E164号 
           emH323id: H323ID
		   emEmail:  
		   emDial:	 电话 
*************************************************************/
NVCBB_API EmAddrType nvGetAddrType(const s8 *pchAddr, u32 dwLen);


/*!**********************************************************
*
* @brief   整型转字符串
* @param   [in] nVal 要转换的值
* @param   [in] pchOutBuf 存储转换后的结果
* @param   [in] nRadix 要转换的进制
* @return  指向转换后的字符串指针
*************************************************************/
NVCBB_API s8 *nv_itoa(s32 nVal, s8 *pchOutBuf, s32 nRadix = 10); 

}


#endif


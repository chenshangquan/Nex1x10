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
* @brief    IP地址转换为字符串
*           字符串请用utf-8编码
* @param    [in] dwIP  <本机字节序>
* @param    [out] pchOutIpv4Str 转换后得到的IP地址 
* @return   MT_SUCCESS:成功 
            其他:失败
*************************************************************/
MTCBB_API u32 mtTransIPv4ToString(u32 dwIP, s8 *pchOutIpv4Str);


/*!**********************************************************
* 
* @brief    u32网络序IP地址转换为字符串
*           字符串请用utf-8编码
* @param    [in] dwIP  <网络字节序>
* @param    [out] pchOutIpv4Str 转换后得到的IP地址 
* @return   MT_SUCCESS:成功 
            其他:失败
*************************************************************/
MTCBB_API u32 mtTransIPv4BigEndianToString(u32 dwIP, s8 *pchOutIpv4Str);


/*!**********************************************************
* 
* @brief    将IPv4字符串转换成u32形式
* @param    [in]  pchIPAddr: 要转换的IP字符串
* @param    [out] dwIP:   <本机字节序>    
* @return   MT_SUCCESS:成功 
			其他:失败
*************************************************************/
MTCBB_API u32 mtGetIPv4FromString(const s8 *pchIPv4Addr, u32 &dwIP);



/*!**********************************************************
* 
* @brief    将IPv4字符串转换成u32大端序形式
* @param    [in]  pchIPAddr: 要转换的IP字符串
* @param    [out] dwIP:   <网络字节序>    
* @return   MT_SUCCESS:成功 
			其他:失败
*************************************************************/
MTCBB_API u32 mtGetIPv4BigEndianFromString(const s8 *pchIPv4Addr, u32 &dwIP);



/*!**********************************************************
*
* @brief   判断IPv4地址是否合法
* @param   [in] pchIPAddr
* @return  TRUE: 合法 
           FALSE: 不合法
*************************************************************/
MTCBB_API BOOL32 mtIsValidIPv4(const s8 *pchIPv4Addr);


/*!**********************************************************
*
* @brief   判断IPv4地址是否合法
* @param   [in] dwIPv4Addr
* @return  TRUE: 合法 
           FALSE: 不合法
*************************************************************/
MTCBB_API BOOL32 mtIsValidIPv4(u32 dwIPv4Addr);


/*!**********************************************************
* 
* @brief   判断IPv6地址是否合法
* @param   [in] pchIPv6Addr
* @return  TRUE: 合法 
           FALSE: 不合法
*************************************************************/
MTCBB_API BOOL32 mtIsValidIPv6(const s8 *pchIPv6Addr);


/*!**********************************************************
*
* @brief   判断IPv4地址是否是组播地址
* @param   [in] pchIPv4Addr IP地址字符串 <本机字节序>
* @return  TRUE: 是组播地址 
           FALSE:非组播地址
*************************************************************/
MTCBB_API BOOL32 mtIsMulticastIpv4Addr(const s8 *pchIPv4Addr);


/*!**********************************************************
* 
* @brief   判断IPv6地址是否是组播地址
* @param   [in] pchIPv6Addr IP地址字符串 <本机字节序>
* @return  TRUE: 是组播地址 
           FALSE:非组播地址
*************************************************************/
MTCBB_API BOOL32 mtIsMulticastIpv6Addr(const s8 *pchIPv6Addr);


/*!**********************************************************
* 
* @brief   判断IPv4地址是否是组播地址 
* @param   [in] dwIPv4  IP地址 <本机字节序>
* @return  TRUE: 是组播地址 
           FALSE:非组播地址
*************************************************************/
MTCBB_API BOOL32 mtIsMulticastIPv4Addr(u32 dwIPv4);



/*!**********************************************************
* 
* @brief   判断IPv4地址是否是广播地址 
* @param   [in] pchIPv4Addr  IP地址 <本机字节序>
* @return  TRUE: 是广播地址 
           FALSE:非广播地址
*************************************************************/
MTCBB_API BOOL32 mtIsBroadcastIPv4Addr(const s8 *pchIPv4Addr, const s8 *pchSubMask);



/*!**********************************************************
* 
* @brief   判断IPv4地址是否是广播地址 
* @param   [in] dwIPv4  IP地址 <本机字节序>
* @return  TRUE: 是广播地址 
           FALSE:非广播地址
*************************************************************/
MTCBB_API BOOL32 mtIsBroadcastIPv4Addr(u32 dwIPv4, u32 dwIPv4Mask);



/*!**********************************************************
* 
* @brief   判断IPv6地址是否是任播地址 
* @param   [in] dwIP  IP地址 <本机字节序>
* @return  TRUE: 是任播地址 
           FALSE:非任播地址
*************************************************************/
MTCBB_API BOOL32 mtIsAnycastIPv6Addr(const s8 *pchIPv6Addr);



/*!**********************************************************
*
* @brief   检测Ipv4子网掩码是否合法
* @param   [in] dwIpv4Addr  IP地址  <本机字节序>
* @param   [in] dwMask      要检测的子网掩码
* @return  TRUE:合法 FALSE:不合法
*************************************************************/
MTCBB_API BOOL32 mtIsValidIpv4SubMask(const u32 dwIpv4Addr, const u32 dwMask);


/*!**********************************************************
* 
* @brief   通过IPv4地址获取子网掩码
* @param   [in] dwIpAddr  IP地址
* @return  u32 子网掩码
*************************************************************/
MTCBB_API u32 mtGetIpv4SubMask(const u32 dwIpv4Addr);


/*!**********************************************************
*
* @brief   是判断字符串否是合法的E164号码
* @param   [in] pchE164Num E164号
* @return  TRUE:合法 FALSE:不合法
*************************************************************/
MTCBB_API BOOL32 mtIsValidE164(const s8 *pchE164Num);


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
MTCBB_API EmAddrType mtGetAddrType(const s8 *pchAddr, u32 dwLen);


/*!**********************************************************
*
* @brief   整型转字符串
* @param   [in] nVal 要转换的值
* @param   [in] pchOutBuf 存储转换后的结果
* @param   [in] nRadix 要转换的进制
* @return  指向转换后的字符串指针
*************************************************************/
MTCBB_API s8 *mt_itoa(s32 nVal, s8 *pchOutBuf, s32 nRadix = 10); 


/*!**********************************************************
*
* @brief   判断是否为合法的ip和e164，格式: 192.168.1.1#0512110000009， 约定以#为分隔符, ip和e164同时有效才为合法的
* @param   [in]  pszString
* @param   [out] achIP
* @param   [in]  wIPLen
* @param   [out] achE164
* @param   [in]  wE164Len
* @return  TRUE: 合法 
           FALSE: 不合法
*************************************************************/
MTCBB_API BOOL32 IsValidIPAndE164( const s8 *pszString, s8 achIP[], u16 wIPLen, s8 achE164[], u16 wE164Len );

}


#endif


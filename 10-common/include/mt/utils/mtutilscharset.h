/*---------------------------------------------------------------------------*/
/*
 * @file    $Id$
 * @brief   字符编码转换接口
 * @author  瞿戴沣
 * @date    $Date$
 * @version  $Revision$
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * 
 */
/*---------------------------------------------------------------------------*/

#ifndef _MTCHARSET_H_
#define _MTCHARSET_H_

#include <stddef.h> //包含size_t 
#include "kdvtype.h"
#include "mtutilstype.h"
#include "mtmacro.h"

/******************************************************************************
* @namespace    MTUTILS
******************************************************************************/
namespace MTUTILS {

/** **********************************************************
* 
* @brief   Utf8字符串转Gb2312	
* @note    可调用此函数两次，第一次pchStrOut传入NULL 通过dwOutLen来获取所需要分配的缓冲区大小
* 
* @param   [in] pchStrIn:   源字符串
* @param   [in] dwBufLen:输出缓冲区长度
* @param   [out] pchStrOut: 转换后的字符串缓冲区
* @param   [out] dwOutLen:  编码转换后字符串实际长度
* @return  MT_SUCCESS:        成功 
           MT_FAILED: 失败
*************************************************************/
MTCBB_API u32 mtUtf8ToGb2312(const s8 *pchStrIn, s8 *pchStrOut, u32 dwBufLen, u32 &dwOutLen);



/** **********************************************************
* 
* @brief   Gb2312编码字符串转Utf8编码
* @note    可调用此函数两次，第一次pchStrOut传入NULL 通过dwOutLen来获取所需要分配的缓冲区大小
*
* @param   [in] pchStrIn:源字符串
* @param   [in] dwBufLen:输出缓冲区长度
* @param   [out] pchStrOut:转换后的字符串
* @param   [out] dwOutLen:  编码转换后字符串实际长度
* @return  MT_SUCCESS:        成功 
*          MT_FAILED: 失败
*************************************************************/
MTCBB_API u32 mtGb2312ToUtf8(const s8 *pchStrIn, s8 *pchStrOut, u32 dwBufLen, u32 &dwOutLen);



/** **********************************************************
* 
* @brief   Unicode编码的字符串转成Utf8编码字符串
* @note    可调用此函数两次，第一次pchStrOut传入NULL 通过dwOutLen来获取所需要分配的缓冲区大小
*		
* @param   [in] pchStrIn:源字符串
* @param   [in] dwBufLen:输出缓冲区长度
* @param   [out] pchStrOut:转换后的字符串
* @param   [out] dwOutLen:  编码转换后字符串实际长度
* @param   [in ] dwInLen: pchStrIn的长度， Unicodew无法判断"\0"
* @return  MT_SUCCESS:        成功
*		   ERR_MTCBB_BUF_NOTENOUGH: 输出缓冲区大小不足 请重新分配不小于dwOutLen的缓冲区
*          MT_FAILED: 失败
*************************************************************/
MTCBB_API u32 mtUnicodeToUtf8(const s8 *pchStrIn, s8 *pchStrOut, u32 dwBufLen, u32 &dwOutLen, u32 dwInLen);



/*!**********************************************************
* 
* @brief   Utf8编码的字符串转成Unicode编码字符串
* @note    可调用此函数两次，第一次pchStrOut传入NULL 通过dwOutLen来获取所需要分配的缓冲区大小
*		
* @param   [in] pchStrIn:源字符串
* @param   [in] dwBufLen:输出缓冲区长度
* @param   [out] pchStrOut:转换后的字符串
* @param   [out] dwOutLen:  编码转换后字符串实际长度
* @return  MT_SUCCESS:        成功 
*          MT_FAILED: 失败
*************************************************************/
MTCBB_API u32 mtUtf8ToUnicode(const s8 *pchStrIn, s8 *pchStrOut, u32 dwBufLen, u32 &dwOutLen);



/*!**********************************************************
* 
* @brief   Gb2312编码的字符串转成Unicode编码字符串
* @note    可调用此函数两次，第一次pchStrOut传入NULL 通过dwOutLen来获取所需要分配的缓冲区大小
*		
* @param   [in] pchStrIn:源字符串
* @param   [in] dwBufLen:输出缓冲区长度
* @param   [out] pchStrOut:转换后的字符串
* @param   [out] dwOutLen:  编码转换后字符串实际长度
* @return  MT_SUCCESS:        成功 
*          MT_FAILED: 失败
*************************************************************/
MTCBB_API u32 mtGb2312ToUnicode(const s8 *pchStrIn, s8 *pchStrOut, u32 dwBufLen, u32 &dwOutLen);



/*!**********************************************************
* 
* @brief   Unicode编码的字符串转成Gb2312编码字符串
* @note    可调用此函数两次，第一次pchStrOut传入NULL 通过dwOutLen来获取所需要分配的缓冲区大小
*		
* @param   [in] pchStrIn:源字符串
* @param   [in] dwBufLen:输出缓冲区长度
* @param   [out] pchStrOut:转换后的字符串
* @param   [out] dwOutLen:  编码转换后字符串实际长度
* @param   [in ] dwInLen: pchStrIn的长度， unicode无法通过strlen判断长度
* @return  MT_SUCCESS:        成功 
*          MT_FAILED: 失败
*************************************************************/
MTCBB_API u32 mtUnicodeToGb2312(const s8 *pchStrIn, s8 *pchStrOut, u32 dwBufLen, u32 &dwOutLen, u32 dwInLen);


/*!**********************************************************
* 
* @brief   guidVal转换成字符串格式
* @note    可调用此函数两次，第一次pchStrOut传入NULL 通过dwOutLen来获取所需要分配的缓冲区大小
*		
* @param   [in] pbyGuidVal:   源字符串
* @param   [in] dwGuidValLen: 源字符串长度， 一般为16字节
* @param   [out] pchStrOut:   转换后的字符串
* @param   [in ] dwBufLen:    pchStrOut字符串长度
* @return  MT_SUCCESS:        成功 
*          MT_FAILED: 失败
*************************************************************/
MTCBB_API u32 mtGuidValToString( const u8 *pbyGuidVal, u32 dwGuidValLen, s8* pchStrOut, u32 dwBufLen );

/*!**********************************************************
* 
* @brief   拷贝utf8字符串，同时去掉最后的不全的utf8
* @note    
*		
* @param   [in] pchSrcStr:          源字符串
* @param   [inout] pchDstStr:       目的字符串
* @param   [in ] dwDstStrLen:    目的字符串长度,sizeof dst数组的长度
* @return  MT_SUCCESS:        成功 
*          MT_FAILED:         失败
*************************************************************/
MTCBB_API u32 mtCopyUtf8WithCutOffEndInvalidChar( const s8* pchSrcStr, s8 *pchDstStr, u32 dwDstStrLen );


/*!**********************************************************
* 
* @brief   是否是有效的utf8(暂时只是用在displayname, 不能保证完全正确，暂时是按照utf8的编码格则来判断)
* @note    
*		
* @param    [in] pchSrcStr:          源字符串
* @return   TRUE:        有效
*           FALSE:       无效
*************************************************************/
MTCBB_API BOOL32 IsValidUtf8Char( const s8* pchSrcStr );




}




#endif //_MTCHARSET_H_
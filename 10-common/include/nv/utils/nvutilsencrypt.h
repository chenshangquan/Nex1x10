/*---------------------------------------------------------------------------*/
/*
 * @file    $Id$
 * @brief   字符串/文件加密解密、校验公用函数
 * @author  瞿戴沣
 * @date    $Date$
 * @version  $Revision$
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * 
 */
/*---------------------------------------------------------------------------*/

#ifndef _NVENCRYPT_H_
#define _NVENCRYPT_H_

#include "kdvtype.h"
#include "nvutilstype.h"
#include "nvmacro.h"
#include "string.h"
#include "stdio.h"

/******************************************************************************
* @namespace    NVUTILS
******************************************************************************/
namespace NVUTILS {



/*!**********************************************************
* 
* @brief   为字符串生成4位CRC校验码
* @param   [in] pbyBuf:          要校验的数据
* @param   [in] dwDataLen:       要校验的数据长度
* @param   [out] byOutCheckSum:  生成的CRC4校验码
* @return  NV_SUCCESS:        成功 
*          NV_FAILED: 失败
*************************************************************/
NVCBB_API u32 nvGenCrc4Checksum(const u8 *pbyBuf, u32 dwDataLen, u8 &byOutCheckSum);


/*!**********************************************************
* 
* @brief   为字符串生成16位CRC校验码
* @param   [in] pbyBuf:         要校验的数据
* @param   [in] dwDataLen:      要校验的数据长度
* @param   [out] wOutChecksum:  生成的CRC16校验码
* @return  NV_SUCCESS:        成功 
*          NV_FAILED: 失败
*************************************************************/
NVCBB_API u32 nvGenCrc16Checksum(const u8 *pbyBuf, u32 dwDataLen, u16 &wOutChecksum);


/*!**********************************************************
* 
* @brief   为字符串生成32位CRC校验码
* @param   [in] pbyBuf:          要校验的数据
* @param   [in] dwDataLen:       要校验的数据长度
* @param   [out] dwOutChecksum:  生成的CRC32校验码
* @return  NV_SUCCESS:        成功 
           NV_FAILED: 失败
*************************************************************/
NVCBB_API u32 nvGenCrc32Checksum(const u8 *pbyBuf, u32 dwDataLen, u32 &dwOutChecksum);


/*!**********************************************************
* 
* @brief   为文件生成32位CRC校验码
* @param   [in] pchFileName:文件路径
* @param   [out] dwOutChecksum:  生成的CRC32校验码
* @return  NV_SUCCESS:        成功 
           NV_FAILED: 失败
*************************************************************/
NVCBB_API u32 nvGenCrc32Checksum(const s8 *pchFileName, u32 &dwOutChecksum);


/*!**********************************************************
* 
* @brief   为字符串生成32 MD5 Code
* @param   [in]  pbyBuf:源数据
* @param   [in]  dwLen:  源数据长度
* @param   [out] achOut:生成的32字节MD5校验码
* @return  NV_SUCCESS:        成功 
           NV_FAILED: 失败
*************************************************************/
NVCBB_API u32 nvGenMD5Code(const s8 *pchBuf, u32 dwLen, s8 achOut[32]);


/*!**********************************************************
* 
* @brief   为文件生成MD5 Code
* @param   [in]  pchFileName: 文件路径
* @param   [out] achOut:      生成的32字节MD5校验码
* @return  NV_SUCCESS:        成功 
           NV_FAILED: 失败
*************************************************************/
NVCBB_API u32 nvGenMD5Code(const s8 *pchFileName, s8 achOut[32]);


/*!**********************************************************
* 
* @brief   对输入的字符串计算哈希校验值
* @param   [in] pcStrIn:       输入字符串
* @param   [in] emHashType:  计算使用的哈希函数类型
* @param   [out] dwHashValue: 生成的哈希校验值
* @return  NV_SUCCESS:        成功 
           NV_FAILED: 失败
*************************************************************/
NVCBB_API u32 nvHash(const s8 *pcStrIn, u32 &dwHashValue, EMHashType emHashType = emSDBMHash);


/*!**********************************************************
* 
* @brief   对字符串进行base64编码
* @param   [in]  pcStrIn:     要编码的字符串
* @param   [in]  dwInSize: 编码前字符串长度
* @param   [out] pcStrOut:    编码后的字符串
* @return  编码后的字符串长度
*************************************************************/
NVCBB_API size_t b64_encode(const s8* pcStrIn, size_t dwInSize, s8* pcStrOut); //linux编译问题，暂时屏蔽


/*!**********************************************************
* 
* @brief   对字符串进行base64解码
* @param   [in]  pcStrIn:     要解码的字符串
* @param   [in]  dwInSize: 解码前字符串长度
* @param   [out] pcStrOut:    解码后的字符串
* @return  解码后的字符串长度
*************************************************************/
NVCBB_API size_t b64_decode(const s8* pcStrIn, size_t dwInSize, s8* pcStrOut);//linux编译问题，暂时屏蔽


}




#endif //_NVENCRYPT_H_
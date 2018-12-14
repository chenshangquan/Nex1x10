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

#ifndef _MTENCRYPT_H_
#define _MTENCRYPT_H_

#include <stddef.h>
#include "kdvtype.h"
#include "mtutilstype.h"
#include "mtmacro.h"


/******************************************************************************
* @namespace    MTUTILS
******************************************************************************/
namespace MTUTILS {



/*!**********************************************************
* 
* @brief   为字符串生成4位CRC校验码
* @param   [in] pbyBuf:          要校验的数据
* @param   [in] dwDataLen:       要校验的数据长度
* @param   [out] byOutCheckSum:  生成的CRC4校验码
* @return  MT_SUCCESS:        成功 
*          MT_FAILED: 失败
*************************************************************/
MTCBB_API u32 mtGenCrc4Checksum(const u8 *pbyBuf, u32 dwDataLen, u8 &byOutCheckSum);


/*!**********************************************************
* 
* @brief   为字符串生成16位CRC校验码
* @param   [in] pbyBuf:         要校验的数据
* @param   [in] dwDataLen:      要校验的数据长度
* @param   [out] wOutChecksum:  生成的CRC16校验码
* @return  MT_SUCCESS:        成功 
*          MT_FAILED: 失败
*************************************************************/
MTCBB_API u32 mtGenCrc16Checksum(const u8 *pbyBuf, u32 dwDataLen, u16 &wOutChecksum);


/*!**********************************************************
* 
* @brief   为字符串生成32位CRC校验码
* @param   [in] pbyBuf:          要校验的数据
* @param   [in] dwDataLen:       要校验的数据长度
* @param   [out] dwOutChecksum:  生成的CRC32校验码
* @return  MT_SUCCESS:        成功 
           MT_FAILED: 失败
*************************************************************/
MTCBB_API u32 mtGenCrc32Checksum(const u8 *pbyBuf, u32 dwDataLen, u32 &dwOutChecksum);


/*!**********************************************************
* 
* @brief   为文件生成32位CRC校验码
* @param   [in] pchFileName:文件路径
* @param   [out] dwOutChecksum:  生成的CRC32校验码
* @return  MT_SUCCESS:        成功 
           MT_FAILED: 失败
*************************************************************/
MTCBB_API u32 mtGenCrc32Checksum(const s8 *pchFileName, u32 &dwOutChecksum);


/*!**********************************************************
* 
* @brief   为字符串生成32 MD5 Code
* @param   [in]  pbyBuf:源数据
* @param   [in]  dwLen:  源数据长度
* @param   [out] achOut:生成的32字节MD5校验码
* @return  MT_SUCCESS:        成功 
           MT_FAILED: 失败
*************************************************************/
MTCBB_API u32 mtGenMD5Code(const s8 *pchBuf, u32 dwLen, s8 achOut[32]);


/*!**********************************************************
* 
* @brief   为文件生成MD5 Code
* @param   [in]  pchFileName: 文件路径
* @param   [out] achOut:      生成的32字节MD5校验码
* @return  MT_SUCCESS:        成功 
           MT_FAILED: 失败
*************************************************************/
MTCBB_API u32 mtGenMD5Code(const s8 *pchFileName, s8 achOut[32]);


/*!**********************************************************
* 
* @brief   对输入的字符串计算哈希校验值
* @param   [in] pcStrIn:       输入字符串
* @param   [in] emHashType:  计算使用的哈希函数类型
* @param   [out] dwHashValue: 生成的哈希校验值
* @return  MT_SUCCESS:        成功 
           MT_FAILED: 失败
*************************************************************/
MTCBB_API u32 mtHash(const s8 *pcStrIn, u32 &dwHashValue, EMHashType emHashType = emSDBMHash);


/*!**********************************************************
* 
* @brief   对字符串进行base64编码
* @param   [in]  pcStrIn:     要编码的字符串
* @param   [in]  dwInSize: 编码前字符串长度
* @param   [out] pcStrOut:    编码后的字符串
* @return  编码后的字符串长度
*************************************************************/
MTCBB_API size_t b64_encode(const s8* pcStrIn, size_t dwInSize, s8* pcStrOut);


/*!**********************************************************
* 
* @brief   对字符串进行base64解码
* @param   [in]  pcStrIn:     要解码的字符串
* @param   [in]  dwInSize: 解码前字符串长度
* @param   [out] pcStrOut:    解码后的字符串
* @return  解码后的字符串长度
*************************************************************/
MTCBB_API size_t b64_decode(const s8* pcStrIn, size_t dwInSize, s8* pcStrOut);

MTCBB_API BOOL32 mtGetU8To16Str(u8 *pchIn,u32 dwInLen,s8 *pchOut,u32 dwOutLen);
MTCBB_API BOOL32 mtGet16strToU8(s8 *pchIn,u32 dwInLen,u8 *pchOut,u32 dwOutLen);

MTCBB_API BOOL32 mtGenSM3Code(const s8 *pchBuf, u32 dwLen, u8 *pchOut,u32 &dwOutLen);

MTCBB_API BOOL32 mtGenSM4Code(const u8* pSM4Key,const u8 *pchBuf, s32 nLen, u8 *pchOut,s32 &nOutLen,BOOL32 bEnc);
MTCBB_API BOOL32 mtGenSM4CodeNoPad(const u8* pSM4Key,const u8 *pchBuf, s32 nLen, u8 *pchOut,s32 &nOutLen,BOOL32 bEnc);
MTCBB_API BOOL32 mtGenAes256Code( const u8* pAes256Key,const u8 *pchBuf, s32 nLen, u8 *pchOut,s32 &nOutLen,BOOL32 bEnc);

/////公私钥加密 
MTCBB_API BOOL32 mtGetSm2PubPriKey( u8 *pchPubOut, s32 &nOutPubLen, u8 *pchPriOut, s32 &nOutPriLen );
MTCBB_API BOOL32 mtGetRsaPubPriKey( u8 *pchPubOut, s32 &nOutPubLen, u8 *pchPriOut,  s32 &nOutPriLen );


MTCBB_API BOOL32 DecSm2Code( u8 *pchPriKey, s32 nPriLen,  u8 * pInBuf, u32 dwInLen, u8 *pOutBuf, u32 &dwOutLen );
MTCBB_API BOOL32 EncSm2Code( u8 *pchPubKey, s32 nPubLen, u8 * pInBuf, u32 dwInLen, u8 *pOutBuf, u32 &dwOutLen );


MTCBB_API BOOL32 DecRsaCode( u8 *pchPriKey, s32 nPriLen,  u8 * pInBuf, u32 dwInLen, u8 *pOutBuf, u32 &dwOutLen );
MTCBB_API BOOL32 EncRsaCode( u8 *pchPubKey, s32 nPubLen, u8 * pInBuf, u32 dwInLen, u8 *pOutBuf, u32 &dwOutLen );


/////计算hash值： sm3(sm3(pwd):nonce:cnonce) 或者
/////             md5(md5(pwd):nonce:cnonce) 
MTCBB_API BOOL32  CalcDigPwd( u32 dwType, u8 *pPwd, u32 dwPwdLen, u8 *pNonce, u32 dwNonceLen, u8 *pCnonce, u32 dwCNonceLen, u8 *pOut, u32 &dwOutLen );


}




#endif //_MTENCRYPT_H_
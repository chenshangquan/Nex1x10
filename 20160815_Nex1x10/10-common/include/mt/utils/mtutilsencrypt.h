/*---------------------------------------------------------------------------*/
/*
 * @file    $Id$
 * @brief   �ַ���/�ļ����ܽ��ܡ�У�鹫�ú���
 * @author  �Ĵ���
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
* @brief   Ϊ�ַ�������4λCRCУ����
* @param   [in] pbyBuf:          ҪУ�������
* @param   [in] dwDataLen:       ҪУ������ݳ���
* @param   [out] byOutCheckSum:  ���ɵ�CRC4У����
* @return  MT_SUCCESS:        �ɹ� 
*          MT_FAILED: ʧ��
*************************************************************/
MTCBB_API u32 mtGenCrc4Checksum(const u8 *pbyBuf, u32 dwDataLen, u8 &byOutCheckSum);


/*!**********************************************************
* 
* @brief   Ϊ�ַ�������16λCRCУ����
* @param   [in] pbyBuf:         ҪУ�������
* @param   [in] dwDataLen:      ҪУ������ݳ���
* @param   [out] wOutChecksum:  ���ɵ�CRC16У����
* @return  MT_SUCCESS:        �ɹ� 
*          MT_FAILED: ʧ��
*************************************************************/
MTCBB_API u32 mtGenCrc16Checksum(const u8 *pbyBuf, u32 dwDataLen, u16 &wOutChecksum);


/*!**********************************************************
* 
* @brief   Ϊ�ַ�������32λCRCУ����
* @param   [in] pbyBuf:          ҪУ�������
* @param   [in] dwDataLen:       ҪУ������ݳ���
* @param   [out] dwOutChecksum:  ���ɵ�CRC32У����
* @return  MT_SUCCESS:        �ɹ� 
           MT_FAILED: ʧ��
*************************************************************/
MTCBB_API u32 mtGenCrc32Checksum(const u8 *pbyBuf, u32 dwDataLen, u32 &dwOutChecksum);


/*!**********************************************************
* 
* @brief   Ϊ�ļ�����32λCRCУ����
* @param   [in] pchFileName:�ļ�·��
* @param   [out] dwOutChecksum:  ���ɵ�CRC32У����
* @return  MT_SUCCESS:        �ɹ� 
           MT_FAILED: ʧ��
*************************************************************/
MTCBB_API u32 mtGenCrc32Checksum(const s8 *pchFileName, u32 &dwOutChecksum);


/*!**********************************************************
* 
* @brief   Ϊ�ַ�������32 MD5 Code
* @param   [in]  pbyBuf:Դ����
* @param   [in]  dwLen:  Դ���ݳ���
* @param   [out] achOut:���ɵ�32�ֽ�MD5У����
* @return  MT_SUCCESS:        �ɹ� 
           MT_FAILED: ʧ��
*************************************************************/
MTCBB_API u32 mtGenMD5Code(const s8 *pchBuf, u32 dwLen, s8 achOut[32]);


/*!**********************************************************
* 
* @brief   Ϊ�ļ�����MD5 Code
* @param   [in]  pchFileName: �ļ�·��
* @param   [out] achOut:      ���ɵ�32�ֽ�MD5У����
* @return  MT_SUCCESS:        �ɹ� 
           MT_FAILED: ʧ��
*************************************************************/
MTCBB_API u32 mtGenMD5Code(const s8 *pchFileName, s8 achOut[32]);


/*!**********************************************************
* 
* @brief   ��������ַ��������ϣУ��ֵ
* @param   [in] pcStrIn:       �����ַ���
* @param   [in] emHashType:  ����ʹ�õĹ�ϣ��������
* @param   [out] dwHashValue: ���ɵĹ�ϣУ��ֵ
* @return  MT_SUCCESS:        �ɹ� 
           MT_FAILED: ʧ��
*************************************************************/
MTCBB_API u32 mtHash(const s8 *pcStrIn, u32 &dwHashValue, EMHashType emHashType = emSDBMHash);


/*!**********************************************************
* 
* @brief   ���ַ�������base64����
* @param   [in]  pcStrIn:     Ҫ������ַ���
* @param   [in]  dwInSize: ����ǰ�ַ�������
* @param   [out] pcStrOut:    �������ַ���
* @return  �������ַ�������
*************************************************************/
MTCBB_API size_t b64_encode(const s8* pcStrIn, size_t dwInSize, s8* pcStrOut);


/*!**********************************************************
* 
* @brief   ���ַ�������base64����
* @param   [in]  pcStrIn:     Ҫ������ַ���
* @param   [in]  dwInSize: ����ǰ�ַ�������
* @param   [out] pcStrOut:    �������ַ���
* @return  �������ַ�������
*************************************************************/
MTCBB_API size_t b64_decode(const s8* pcStrIn, size_t dwInSize, s8* pcStrOut);

MTCBB_API BOOL32 mtGetU8To16Str(u8 *pchIn,u32 dwInLen,s8 *pchOut,u32 dwOutLen);
MTCBB_API BOOL32 mtGet16strToU8(s8 *pchIn,u32 dwInLen,u8 *pchOut,u32 dwOutLen);

MTCBB_API BOOL32 mtGenSM3Code(const s8 *pchBuf, u32 dwLen, u8 *pchOut,u32 &dwOutLen);

MTCBB_API BOOL32 mtGenSM4Code(const u8* pSM4Key,const u8 *pchBuf, s32 nLen, u8 *pchOut,s32 &nOutLen,BOOL32 bEnc);
MTCBB_API BOOL32 mtGenSM4CodeNoPad(const u8* pSM4Key,const u8 *pchBuf, s32 nLen, u8 *pchOut,s32 &nOutLen,BOOL32 bEnc);
MTCBB_API BOOL32 mtGenAes256Code( const u8* pAes256Key,const u8 *pchBuf, s32 nLen, u8 *pchOut,s32 &nOutLen,BOOL32 bEnc);

/////��˽Կ���� 
MTCBB_API BOOL32 mtGetSm2PubPriKey( u8 *pchPubOut, s32 &nOutPubLen, u8 *pchPriOut, s32 &nOutPriLen );
MTCBB_API BOOL32 mtGetRsaPubPriKey( u8 *pchPubOut, s32 &nOutPubLen, u8 *pchPriOut,  s32 &nOutPriLen );


MTCBB_API BOOL32 DecSm2Code( u8 *pchPriKey, s32 nPriLen,  u8 * pInBuf, u32 dwInLen, u8 *pOutBuf, u32 &dwOutLen );
MTCBB_API BOOL32 EncSm2Code( u8 *pchPubKey, s32 nPubLen, u8 * pInBuf, u32 dwInLen, u8 *pOutBuf, u32 &dwOutLen );


MTCBB_API BOOL32 DecRsaCode( u8 *pchPriKey, s32 nPriLen,  u8 * pInBuf, u32 dwInLen, u8 *pOutBuf, u32 &dwOutLen );
MTCBB_API BOOL32 EncRsaCode( u8 *pchPubKey, s32 nPubLen, u8 * pInBuf, u32 dwInLen, u8 *pOutBuf, u32 &dwOutLen );


/////����hashֵ�� sm3(sm3(pwd):nonce:cnonce) ����
/////             md5(md5(pwd):nonce:cnonce) 
MTCBB_API BOOL32  CalcDigPwd( u32 dwType, u8 *pPwd, u32 dwPwdLen, u8 *pNonce, u32 dwNonceLen, u8 *pCnonce, u32 dwCNonceLen, u8 *pOut, u32 &dwOutLen );


}




#endif //_MTENCRYPT_H_
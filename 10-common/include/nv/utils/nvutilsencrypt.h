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
* @brief   Ϊ�ַ�������4λCRCУ����
* @param   [in] pbyBuf:          ҪУ�������
* @param   [in] dwDataLen:       ҪУ������ݳ���
* @param   [out] byOutCheckSum:  ���ɵ�CRC4У����
* @return  NV_SUCCESS:        �ɹ� 
*          NV_FAILED: ʧ��
*************************************************************/
NVCBB_API u32 nvGenCrc4Checksum(const u8 *pbyBuf, u32 dwDataLen, u8 &byOutCheckSum);


/*!**********************************************************
* 
* @brief   Ϊ�ַ�������16λCRCУ����
* @param   [in] pbyBuf:         ҪУ�������
* @param   [in] dwDataLen:      ҪУ������ݳ���
* @param   [out] wOutChecksum:  ���ɵ�CRC16У����
* @return  NV_SUCCESS:        �ɹ� 
*          NV_FAILED: ʧ��
*************************************************************/
NVCBB_API u32 nvGenCrc16Checksum(const u8 *pbyBuf, u32 dwDataLen, u16 &wOutChecksum);


/*!**********************************************************
* 
* @brief   Ϊ�ַ�������32λCRCУ����
* @param   [in] pbyBuf:          ҪУ�������
* @param   [in] dwDataLen:       ҪУ������ݳ���
* @param   [out] dwOutChecksum:  ���ɵ�CRC32У����
* @return  NV_SUCCESS:        �ɹ� 
           NV_FAILED: ʧ��
*************************************************************/
NVCBB_API u32 nvGenCrc32Checksum(const u8 *pbyBuf, u32 dwDataLen, u32 &dwOutChecksum);


/*!**********************************************************
* 
* @brief   Ϊ�ļ�����32λCRCУ����
* @param   [in] pchFileName:�ļ�·��
* @param   [out] dwOutChecksum:  ���ɵ�CRC32У����
* @return  NV_SUCCESS:        �ɹ� 
           NV_FAILED: ʧ��
*************************************************************/
NVCBB_API u32 nvGenCrc32Checksum(const s8 *pchFileName, u32 &dwOutChecksum);


/*!**********************************************************
* 
* @brief   Ϊ�ַ�������32 MD5 Code
* @param   [in]  pbyBuf:Դ����
* @param   [in]  dwLen:  Դ���ݳ���
* @param   [out] achOut:���ɵ�32�ֽ�MD5У����
* @return  NV_SUCCESS:        �ɹ� 
           NV_FAILED: ʧ��
*************************************************************/
NVCBB_API u32 nvGenMD5Code(const s8 *pchBuf, u32 dwLen, s8 achOut[32]);


/*!**********************************************************
* 
* @brief   Ϊ�ļ�����MD5 Code
* @param   [in]  pchFileName: �ļ�·��
* @param   [out] achOut:      ���ɵ�32�ֽ�MD5У����
* @return  NV_SUCCESS:        �ɹ� 
           NV_FAILED: ʧ��
*************************************************************/
NVCBB_API u32 nvGenMD5Code(const s8 *pchFileName, s8 achOut[32]);


/*!**********************************************************
* 
* @brief   ��������ַ��������ϣУ��ֵ
* @param   [in] pcStrIn:       �����ַ���
* @param   [in] emHashType:  ����ʹ�õĹ�ϣ��������
* @param   [out] dwHashValue: ���ɵĹ�ϣУ��ֵ
* @return  NV_SUCCESS:        �ɹ� 
           NV_FAILED: ʧ��
*************************************************************/
NVCBB_API u32 nvHash(const s8 *pcStrIn, u32 &dwHashValue, EMHashType emHashType = emSDBMHash);


/*!**********************************************************
* 
* @brief   ���ַ�������base64����
* @param   [in]  pcStrIn:     Ҫ������ַ���
* @param   [in]  dwInSize: ����ǰ�ַ�������
* @param   [out] pcStrOut:    �������ַ���
* @return  �������ַ�������
*************************************************************/
NVCBB_API size_t b64_encode(const s8* pcStrIn, size_t dwInSize, s8* pcStrOut); //linux�������⣬��ʱ����


/*!**********************************************************
* 
* @brief   ���ַ�������base64����
* @param   [in]  pcStrIn:     Ҫ������ַ���
* @param   [in]  dwInSize: ����ǰ�ַ�������
* @param   [out] pcStrOut:    �������ַ���
* @return  �������ַ�������
*************************************************************/
NVCBB_API size_t b64_decode(const s8* pcStrIn, size_t dwInSize, s8* pcStrOut);//linux�������⣬��ʱ����


}




#endif //_NVENCRYPT_H_
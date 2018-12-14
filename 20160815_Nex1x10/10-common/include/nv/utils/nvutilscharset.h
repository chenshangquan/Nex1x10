/*---------------------------------------------------------------------------*/
/*
 * @file    $Id$
 * @brief   �ַ�����ת���ӿ�
 * @author  �Ĵ���
 * @date    $Date$
 * @version  $Revision$
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * 
 */
/*---------------------------------------------------------------------------*/

#ifndef _NVCHARSET_H_
#define _NVCHARSET_H_

#include "kdvtype.h"
#include "nvutilstype.h"
#include "nvmacro.h"

/******************************************************************************
* @namespace    NVUTILS
******************************************************************************/
namespace NVUTILS {

/** **********************************************************
* 
* @brief   Utf8�ַ���תGb2312	
* @note    �ɵ��ô˺������Σ���һ��pchStrOut����NULL ͨ��dwOutLen����ȡ����Ҫ����Ļ�������С
* 
* @param   [in] pchStrIn:   Դ�ַ���
* @param   [in] dwBufLen:�������������
* @param   [out] pchStrOut: ת������ַ���������
* @param   [out] dwOutLen:  ����ת�����ַ���ʵ�ʳ���
* @return  NV_SUCCESS:        �ɹ� 
           NV_FAILED: ʧ��
*************************************************************/
NVCBB_API u32 nvUtf8ToGb2312(const s8 *pchStrIn, s8 *pchStrOut, u32 dwBufLen, u32 &dwOutLen);



/** **********************************************************
* 
* @brief   Gb2312�����ַ���תUtf8����
* @note    �ɵ��ô˺������Σ���һ��pchStrOut����NULL ͨ��dwOutLen����ȡ����Ҫ����Ļ�������С
*
* @param   [in] pchStrIn:Դ�ַ���
* @param   [in] dwBufLen:�������������
* @param   [out] pchStrOut:ת������ַ���
* @param   [out] dwOutLen:  ����ת�����ַ���ʵ�ʳ���
* @return  NV_SUCCESS:        �ɹ� 
*          NV_FAILED: ʧ��
*************************************************************/
NVCBB_API u32 nvGb2312ToUtf8(const s8 *pchStrIn, s8 *pchStrOut, u32 dwBufLen, u32 &dwOutLen);



/** **********************************************************
* 
* @brief   Unicode������ַ���ת��Utf8�����ַ���
* @note    �ɵ��ô˺������Σ���һ��pchStrOut����NULL ͨ��dwOutLen����ȡ����Ҫ����Ļ�������С
*		
* @param   [in] pchStrIn:Դ�ַ���
* @param   [in] dwBufLen:�������������
* @param   [out] pchStrOut:ת������ַ���
* @param   [out] dwOutLen:  ����ת�����ַ���ʵ�ʳ���
* @return  NV_SUCCESS:        �ɹ�
*		   ERR_NVCBB_BUF_NOTENOUGH: �����������С���� �����·��䲻С��dwOutLen�Ļ�����
*          NV_FAILED: ʧ��
*************************************************************/
NVCBB_API u32 nvUnicodeToUtf8(const s8 *pchStrIn, s8 *pchStrOut, u32 dwBufLen, u32 &dwOutLen);



/*!**********************************************************
* 
* @brief   Utf8������ַ���ת��Unicode�����ַ���
* @note    �ɵ��ô˺������Σ���һ��pchStrOut����NULL ͨ��dwOutLen����ȡ����Ҫ����Ļ�������С
*		
* @param   [in] pchStrIn:Դ�ַ���
* @param   [in] dwBufLen:�������������
* @param   [out] pchStrOut:ת������ַ���
* @param   [out] dwOutLen:  ����ת�����ַ���ʵ�ʳ���
* @return  NV_SUCCESS:        �ɹ� 
*          NV_FAILED: ʧ��
*************************************************************/
NVCBB_API u32 nvUtf8ToUnicode(const s8 *pchStrIn, s8 *pchStrOut, u32 dwBufLen, u32 &dwOutLen);



/*!**********************************************************
* 
* @brief   Gb2312������ַ���ת��Unicode�����ַ���
* @note    �ɵ��ô˺������Σ���һ��pchStrOut����NULL ͨ��dwOutLen����ȡ����Ҫ����Ļ�������С
*		
* @param   [in] pchStrIn:Դ�ַ���
* @param   [in] dwBufLen:�������������
* @param   [out] pchStrOut:ת������ַ���
* @param   [out] dwOutLen:  ����ת�����ַ���ʵ�ʳ���
* @return  NV_SUCCESS:        �ɹ� 
*          NV_FAILED: ʧ��
*************************************************************/
NVCBB_API u32 nvGb2312ToUnicode(const s8 *pchStrIn, s8 *pchStrOut, u32 dwBufLen, u32 &dwOutLen);



/*!**********************************************************
* 
* @brief   Unicode������ַ���ת��Gb2312�����ַ���
* @note    �ɵ��ô˺������Σ���һ��pchStrOut����NULL ͨ��dwOutLen����ȡ����Ҫ����Ļ�������С
*		
* @param   [in] pchStrIn:Դ�ַ���
* @param   [in] dwBufLen:�������������
* @param   [out] pchStrOut:ת������ַ���
* @param   [out] dwOutLen:  ����ת�����ַ���ʵ�ʳ���
* @param   [in ] dwInLen: pchStrIn�ĳ��ȣ� unicode�޷�ͨ��strlen�жϳ���
* @return  NV_SUCCESS:        �ɹ� 
*          NV_FAILED: ʧ��
*************************************************************/
NVCBB_API u32 nvUnicodeToGb2312(const s8 *pchStrIn, s8 *pchStrOut, u32 dwBufLen, u32 &dwOutLen, u32 dwInLen);


/*!**********************************************************
* 
* @brief   guidValת�����ַ�����ʽ
* @note    �ɵ��ô˺������Σ���һ��pchStrOut����NULL ͨ��dwOutLen����ȡ����Ҫ����Ļ�������С
*		
* @param   [in] pbyGuidVal:   Դ�ַ���
* @param   [in] dwGuidValLen: Դ�ַ������ȣ� һ��Ϊ16�ֽ�
* @param   [out] pchStrOut:   ת������ַ���
* @param   [in ] dwBufLen:    pchStrOut�ַ�������
* @return  NV_SUCCESS:        �ɹ� 
*          NV_FAILED: ʧ��
*************************************************************/
NVCBB_API u32 nvGuidValToString( const u8 *pbyGuidVal, u32 dwGuidValLen, s8* pchStrOut, u32 dwBufLen );

/*!**********************************************************
* 
* @brief   ����utf8�ַ�����ͬʱȥ�����Ĳ�ȫ��utf8
* @note    
*		
* @param   [in] pchSrcStr:          Դ�ַ���
* @param   [inout] pchDstStr:       Ŀ���ַ���
* @param   [in ] dwDstStrLen:    Ŀ���ַ�������,sizeof dst����ĳ���
* @return  NV_SUCCESS:        �ɹ� 
*          NV_FAILED:         ʧ��
*************************************************************/
NVCBB_API u32 nvCopyUtf8WithCutOffEndInvalidChar( const s8* pchSrcStr, s8 *pchDstStr, u32 dwDstStrLen );


/*!**********************************************************
* 
* @brief   �Ƿ�����Ч��utf8(��ʱֻ������displayname, ���ܱ�֤��ȫ��ȷ����ʱ�ǰ���utf8�ı���������ж�)
* @note    
*		
* @param    [in] pchSrcStr:          Դ�ַ���
* @return   TRUE:        ��Ч
*           FALSE:       ��Ч
*************************************************************/
NVCBB_API BOOL32 IsValidUtf8Char( const s8* pchSrcStr );

NVCBB_API BOOL32 nvGetOpen();
NVCBB_API BOOL32 nvSetOpen(BOOL32 bOpen);

NVCBB_API BOOL32 nvGetCheck();
NVCBB_API BOOL32 nvSetCheck(BOOL32 bCheck);



}




#endif //_NVCHARSET_H_
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

#ifndef _MTCHARSET_H_
#define _MTCHARSET_H_

#include <stddef.h> //����size_t 
#include "kdvtype.h"
#include "mtutilstype.h"
#include "mtmacro.h"

/******************************************************************************
* @namespace    MTUTILS
******************************************************************************/
namespace MTUTILS {

/** **********************************************************
* 
* @brief   Utf8�ַ���תGb2312	
* @note    �ɵ��ô˺������Σ���һ��pchStrOut����NULL ͨ��dwOutLen����ȡ����Ҫ����Ļ�������С
* 
* @param   [in] pchStrIn:   Դ�ַ���
* @param   [in] dwBufLen:�������������
* @param   [out] pchStrOut: ת������ַ���������
* @param   [out] dwOutLen:  ����ת�����ַ���ʵ�ʳ���
* @return  MT_SUCCESS:        �ɹ� 
           MT_FAILED: ʧ��
*************************************************************/
MTCBB_API u32 mtUtf8ToGb2312(const s8 *pchStrIn, s8 *pchStrOut, u32 dwBufLen, u32 &dwOutLen);



/** **********************************************************
* 
* @brief   Gb2312�����ַ���תUtf8����
* @note    �ɵ��ô˺������Σ���һ��pchStrOut����NULL ͨ��dwOutLen����ȡ����Ҫ����Ļ�������С
*
* @param   [in] pchStrIn:Դ�ַ���
* @param   [in] dwBufLen:�������������
* @param   [out] pchStrOut:ת������ַ���
* @param   [out] dwOutLen:  ����ת�����ַ���ʵ�ʳ���
* @return  MT_SUCCESS:        �ɹ� 
*          MT_FAILED: ʧ��
*************************************************************/
MTCBB_API u32 mtGb2312ToUtf8(const s8 *pchStrIn, s8 *pchStrOut, u32 dwBufLen, u32 &dwOutLen);



/** **********************************************************
* 
* @brief   Unicode������ַ���ת��Utf8�����ַ���
* @note    �ɵ��ô˺������Σ���һ��pchStrOut����NULL ͨ��dwOutLen����ȡ����Ҫ����Ļ�������С
*		
* @param   [in] pchStrIn:Դ�ַ���
* @param   [in] dwBufLen:�������������
* @param   [out] pchStrOut:ת������ַ���
* @param   [out] dwOutLen:  ����ת�����ַ���ʵ�ʳ���
* @param   [in ] dwInLen: pchStrIn�ĳ��ȣ� Unicodew�޷��ж�"\0"
* @return  MT_SUCCESS:        �ɹ�
*		   ERR_MTCBB_BUF_NOTENOUGH: �����������С���� �����·��䲻С��dwOutLen�Ļ�����
*          MT_FAILED: ʧ��
*************************************************************/
MTCBB_API u32 mtUnicodeToUtf8(const s8 *pchStrIn, s8 *pchStrOut, u32 dwBufLen, u32 &dwOutLen, u32 dwInLen);



/*!**********************************************************
* 
* @brief   Utf8������ַ���ת��Unicode�����ַ���
* @note    �ɵ��ô˺������Σ���һ��pchStrOut����NULL ͨ��dwOutLen����ȡ����Ҫ����Ļ�������С
*		
* @param   [in] pchStrIn:Դ�ַ���
* @param   [in] dwBufLen:�������������
* @param   [out] pchStrOut:ת������ַ���
* @param   [out] dwOutLen:  ����ת�����ַ���ʵ�ʳ���
* @return  MT_SUCCESS:        �ɹ� 
*          MT_FAILED: ʧ��
*************************************************************/
MTCBB_API u32 mtUtf8ToUnicode(const s8 *pchStrIn, s8 *pchStrOut, u32 dwBufLen, u32 &dwOutLen);



/*!**********************************************************
* 
* @brief   Gb2312������ַ���ת��Unicode�����ַ���
* @note    �ɵ��ô˺������Σ���һ��pchStrOut����NULL ͨ��dwOutLen����ȡ����Ҫ����Ļ�������С
*		
* @param   [in] pchStrIn:Դ�ַ���
* @param   [in] dwBufLen:�������������
* @param   [out] pchStrOut:ת������ַ���
* @param   [out] dwOutLen:  ����ת�����ַ���ʵ�ʳ���
* @return  MT_SUCCESS:        �ɹ� 
*          MT_FAILED: ʧ��
*************************************************************/
MTCBB_API u32 mtGb2312ToUnicode(const s8 *pchStrIn, s8 *pchStrOut, u32 dwBufLen, u32 &dwOutLen);



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
* @return  MT_SUCCESS:        �ɹ� 
*          MT_FAILED: ʧ��
*************************************************************/
MTCBB_API u32 mtUnicodeToGb2312(const s8 *pchStrIn, s8 *pchStrOut, u32 dwBufLen, u32 &dwOutLen, u32 dwInLen);


/*!**********************************************************
* 
* @brief   guidValת�����ַ�����ʽ
* @note    �ɵ��ô˺������Σ���һ��pchStrOut����NULL ͨ��dwOutLen����ȡ����Ҫ����Ļ�������С
*		
* @param   [in] pbyGuidVal:   Դ�ַ���
* @param   [in] dwGuidValLen: Դ�ַ������ȣ� һ��Ϊ16�ֽ�
* @param   [out] pchStrOut:   ת������ַ���
* @param   [in ] dwBufLen:    pchStrOut�ַ�������
* @return  MT_SUCCESS:        �ɹ� 
*          MT_FAILED: ʧ��
*************************************************************/
MTCBB_API u32 mtGuidValToString( const u8 *pbyGuidVal, u32 dwGuidValLen, s8* pchStrOut, u32 dwBufLen );

/*!**********************************************************
* 
* @brief   ����utf8�ַ�����ͬʱȥ�����Ĳ�ȫ��utf8
* @note    
*		
* @param   [in] pchSrcStr:          Դ�ַ���
* @param   [inout] pchDstStr:       Ŀ���ַ���
* @param   [in ] dwDstStrLen:    Ŀ���ַ�������,sizeof dst����ĳ���
* @return  MT_SUCCESS:        �ɹ� 
*          MT_FAILED:         ʧ��
*************************************************************/
MTCBB_API u32 mtCopyUtf8WithCutOffEndInvalidChar( const s8* pchSrcStr, s8 *pchDstStr, u32 dwDstStrLen );


/*!**********************************************************
* 
* @brief   �Ƿ�����Ч��utf8(��ʱֻ������displayname, ���ܱ�֤��ȫ��ȷ����ʱ�ǰ���utf8�ı���������ж�)
* @note    
*		
* @param    [in] pchSrcStr:          Դ�ַ���
* @return   TRUE:        ��Ч
*           FALSE:       ��Ч
*************************************************************/
MTCBB_API BOOL32 IsValidUtf8Char( const s8* pchSrcStr );




}




#endif //_MTCHARSET_H_
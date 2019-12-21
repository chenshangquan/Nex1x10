/*---------------------------------------------------------------------------*/
/*
 * @file    $Id$
 * @brief   ���ú���
 * @author  �Ĵ���
 * @date    $Date$
 * @version  $Revision$
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * 
 */
/*---------------------------------------------------------------------------*/
#ifndef _MTUTILSCOMMON_H_
#define _MTUTILSCOMMON_H_
#include "kdvtype.h"
#include "osp.h"
#include "limits.h"
#include "mtmacro.h"
#include "mterrcode_global.h"

/******************************************************************************
* @namespace    MTUTILS
******************************************************************************/
namespace MTUTILS {


/*!**********************************************************
* @fn      u32 mtStringToLower(s8 *pchString)
* @brief   ���ַ���ת��Сд��
* @param   [in] pchString:Ҫת�����ַ���
* @return  MT_SUCCESS:�ɹ� 
           MT_FAILED:ʧ��
*************************************************************/
MTCBB_API u32 mtStringToLower(s8 *pchString);


/*!**********************************************************
* @fn      u32 mtStringToUpper(s8 *pchString)
* @brief   ���ַ���ת�ɴ�д��
* @param   [in] pchString:Ҫת�����ַ���
* @return  MT_SUCCESS:�ɹ� 
           MT_FAILED:ʧ��
*************************************************************/
MTCBB_API u32 mtStringToUpper(s8 *pchString);


/*!**********************************************************
* @fn      u32 mtReplaceChar(s8 *pchString, const s8 chSrc, const s8 chDst)
* @brief   ���ַ���pchString�е��ַ�chSrc�滻Ϊ�ַ�chDst
* @param   [in] pchString:Ҫ�������ַ���
* @param   [in] chSrc:    Ҫ�滻���ַ�
* @param   [in] chDst:    �滻����ַ�
* @return  MT_SUCCESS:�ɹ� 
*          MT_FAILED:ʧ��
*************************************************************/
MTCBB_API u32 mtReplaceChar(s8 *pchString, const s8 chSrc, const s8 chDst);



template <typename T>
/*!**********************************************************
* 
* @brief   ����ĳ�������ı���λ
* @param   [in] tNum:  Ҫ���õ���
* @param   [in] byBit: �ڼ�λ��1��ʼ��
* @param   [in] bSet:  ��1/��0
* @return  MT_SUCCESS:        �ɹ� 
*          MT_FAILED: ʧ��
*************************************************************/
MTCBB_API u32 mtSetBitState(T *ptNum, u8 byBit, BOOL32 bSet)
{
	if (byBit > 8 * sizeof(*ptNum))
	{
		return MT_FAILED;
	}

	T tTmpVal = 1 << (byBit - 1);

	if (bSet)
	{
		*ptNum |= tTmpVal;
	}
	else
	{
		*ptNum &= (~tTmpVal);
	}

	return MT_SUCCESS;
}


template <typename T>
/*!**********************************************************
* 
* @brief   �ж�������ĳһλ�Ƿ���1
* @param   [in] tNum:  Ҫ�жϵ���
* @param   [in] byBit: �ڼ�λ��1��ʼ��
* @return  TRUE:  ��λΪ1 
*          FALSE: ��λΪ0
*************************************************************/
MTCBB_API BOOL32 mtIsBitSet(T tNum, u8 byBit)
{
	T byTmp = (tNum >> (byBit - 1)) & 0x01;

	return (1 == byTmp);
}



template <class T>
/*!**********************************************************
* @fn      T SAFE_CAST(T &t, u8 *pbyBuf)
* @brief   �ڴ濽����ֵ
* @return  ��ֵ��ı���
*************************************************************/
MTCBB_API T SAFE_CAST(T &t, u8 *pbyBuf)
{
	if (NULL == pbyBuf) return t;
	memcpy(&t, pbyBuf, sizeof(T));
	return t;
}


/*!**********************************************************
* 
* @brief   ��������
* @param   [in]  dwMaxRange: ��������Χ
* @param   [out] dwRandNum:  �õ��������
* @return  ��õ������
*************************************************************/
MTCBB_API u32 mtGetRandNum(u32 dwMaxRange);

MTCBB_API BOOL32 mtGetRandBytes(u8 *pOut, u32 &dwOutlen);

MTCBB_API u32 mtGetCallid( s8 *pchGuid );

MTCBB_API u32 mtGetGuid( u8 *pchGuid, u32 dwGuidLen );

template <typename T>
/*!**********************************************************
* 
* @brief   ��ӡ���ֵ�ʮ�����Ʊ�ʾ
* @param   [in]  val Ҫ��ӡ������
*
* @return   ��
*          
*************************************************************/
MTCBB_API void mtPrintHex(T val)
{
	printf("0x%x\n", val);
	OspPrintf(TRUE, FALSE, "0x%x\n", val);
}


template <typename T>
/*!**********************************************************
* 
* @brief   ��ӡ���ֵĶ����Ʊ�ʾ
* @param   [in]  val Ҫ��ӡ������
*
* @return  ��
*          
*************************************************************/
MTCBB_API void mtPrintBinary(T val)
{
	s32 nBitCount = sizeof(val) * 8;
	for (s32 i = nBitCount - 1; i >= 0; i--)
	{
		printf("%d", 0x01 & (val >> i));
		OspPrintf(TRUE, FALSE, "%d", 0x01 & (val >> i));
	}

	printf("\n");
	OspPrintf(TRUE, FALSE, "\n");
}


template <typename T>
/*!**********************************************************
*
* @brief   �����ɸ����е���Сֵ(Ҫ�ȽϵĲ����봫����ͬ����)
* @param   [in]  dwArgsNum Ҫ�ȽϵĲ�������
* @param   [in]  val1      Ҫ�Ƚϵĵ�һ��ֵ
* @param   [in]  ...       �ɱ������Ҫ�Ƚϵľ���ֵ
*
* @return  ������Сֵ
*          
*************************************************************/
MTCBB_API T Min(s32 nArgsNum, T val1, ...)
{
	if (nArgsNum <= 0)
	{
		return 0;
	}

	T valMin = val1;
	va_list arg_ptr;
	va_start(arg_ptr, nArgsNum);

	while (nArgsNum--)
	{
		T nTmpVal = va_arg(arg_ptr, T);
		if (valMin > nTmpVal)
		{
			valMin = nTmpVal;
		}
	}

	va_end(arg_ptr); //lint --e(438)

	return valMin;
}


template <typename T>
/*!**********************************************************
*
* @brief   �����ɸ����е����ֵ(Ҫ�ȽϵĲ����봫����ͬ����)
* @param   [in]  dwArgsNum Ҫ�ȽϵĲ�������
* @param   [in]  val1      Ҫ�Ƚϵĵ�һ��ֵ
* @param   [in]  ...       �ɱ������Ҫ�Ƚϵľ���ֵ
*
* @return  ������Сֵ
*          
*************************************************************/
MTCBB_API T Max(s32 nArgsNum, T val1, ...)
{
	if (nArgsNum <= 0)
	{
		return 0;
	}

	T valMax = val1;
	va_list arg_ptr;
	va_start(arg_ptr, nArgsNum);

	while (nArgsNum--)
	{
		T dwTmpVal = va_arg(arg_ptr, T);
		if (valMax < dwTmpVal)
		{
			valMax = dwTmpVal;
		}
	}

	va_end(arg_ptr); //lint --e(438)

	return valMax;
}

}
#endif //_MTUTILSCOMMON_H_
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
#ifndef _NVUTILSCOMMON_H_
#define _NVUTILSCOMMON_H_
#include "kdvtype.h"
#include "osp.h"
#include "limits.h"
#include "nvmacro.h"
#include "nverrcode_global.h"
#include "nvlock.h"

/******************************************************************************
* @namespace    NVUTILS
******************************************************************************/
namespace NVUTILS {


/*!**********************************************************
* @fn      u32 nvStringToLower(s8 *pchString)
* @brief   ���ַ���ת��Сд��
* @param   [in] pchString:Ҫת�����ַ���
* @return  NV_SUCCESS:�ɹ� 
           NV_FAILED:ʧ��
*************************************************************/
NVCBB_API u32 nvStringToLower(s8 *pchString);


/*!**********************************************************
* @fn      u32 nvStringToUpper(s8 *pchString)
* @brief   ���ַ���ת�ɴ�д��
* @param   [in] pchString:Ҫת�����ַ���
* @return  NV_SUCCESS:�ɹ� 
           NV_FAILED:ʧ��
*************************************************************/
NVCBB_API u32 nvStringToUpper(s8 *pchString);


/*!**********************************************************
* @fn      u32 nvReplaceChar(s8 *pchString, const s8 chSrc, const s8 chDst)
* @brief   ���ַ���pchString�е��ַ�chSrc�滻Ϊ�ַ�chDst
* @param   [in] pchString:Ҫ�������ַ���
* @param   [in] chSrc:    Ҫ�滻���ַ�
* @param   [in] chDst:    �滻����ַ�
* @return  NV_SUCCESS:�ɹ� 
*          NV_FAILED:ʧ��
*************************************************************/
NVCBB_API u32 nvReplaceChar(s8 *pchString, const s8 chSrc, const s8 chDst);

NVCBB_API SEMHANDLE GetQkLock();
NVCBB_API BOOL32 QkSemBCreate();
NVCBB_API void QkSemTakeByTime();
NVCBB_API void QkSemGive();
//add by youjx 2018.5.14
NVCBB_API SEMHANDLE GetPadLock();
NVCBB_API BOOL32 PadSemBCreate();
NVCBB_API void PadSemTakeByTime();
NVCBB_API void PadSemGive();
//add end
template <typename T>
/*!**********************************************************
* 
* @brief   ����ĳ�������ı���λ
* @param   [in] tNum:  Ҫ���õ���
* @param   [in] byBit: �ڼ�λ��1��ʼ��
* @param   [in] bSet:  ��1/��0
* @return  NV_SUCCESS:        �ɹ� 
*          NV_FAILED: ʧ��
*************************************************************/
NVCBB_API u32 nvSetBitState(T *ptNum, u8 byBit, BOOL32 bSet)
{
	if (byBit > 8 * sizeof(*ptNum))
	{
		return NV_FAILED;
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

	return NV_SUCCESS;
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
NVCBB_API BOOL32 nvIsBitSet(T tNum, u8 byBit)
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
NVCBB_API T SAFE_CAST(T &t, u8 *pbyBuf)
{
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
NVCBB_API u32 nvGetRandNum(u32 dwMaxRange);


template <typename T>
/*!**********************************************************
* 
* @brief   ��ӡ���ֵ�ʮ�����Ʊ�ʾ
* @param   [in]  val Ҫ��ӡ������
*
* @return   ��
*          
*************************************************************/
NVCBB_API void nvPrintHex(T val)
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
NVCBB_API void nvPrintBinary(T val)
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
NVCBB_API T Min(s32 nArgsNum, T val1, ...)
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
NVCBB_API T Max(s32 nArgsNum, T val1, ...)
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
#endif //_NVUTILSCOMMON_H_
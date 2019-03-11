/*---------------------------------------------------------------------------*/
/*
 * @file    $Id$
 * @brief   公用函数
 * @author  瞿戴沣
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
* @brief   将字符串转成小写化
* @param   [in] pchString:要转换的字符串
* @return  MT_SUCCESS:成功 
           MT_FAILED:失败
*************************************************************/
MTCBB_API u32 mtStringToLower(s8 *pchString);


/*!**********************************************************
* @fn      u32 mtStringToUpper(s8 *pchString)
* @brief   将字符串转成大写化
* @param   [in] pchString:要转换的字符串
* @return  MT_SUCCESS:成功 
           MT_FAILED:失败
*************************************************************/
MTCBB_API u32 mtStringToUpper(s8 *pchString);


/*!**********************************************************
* @fn      u32 mtReplaceChar(s8 *pchString, const s8 chSrc, const s8 chDst)
* @brief   将字符串pchString中的字符chSrc替换为字符chDst
* @param   [in] pchString:要操作的字符串
* @param   [in] chSrc:    要替换的字符
* @param   [in] chDst:    替换后的字符
* @return  MT_SUCCESS:成功 
*          MT_FAILED:失败
*************************************************************/
MTCBB_API u32 mtReplaceChar(s8 *pchString, const s8 chSrc, const s8 chDst);



template <typename T>
/*!**********************************************************
* 
* @brief   设置某整形数的比特位
* @param   [in] tNum:  要设置的数
* @param   [in] byBit: 第几位（1起始）
* @param   [in] bSet:  置1/清0
* @return  MT_SUCCESS:        成功 
*          MT_FAILED: 失败
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
* @brief   判断整数的某一位是否被置1
* @param   [in] tNum:  要判断的数
* @param   [in] byBit: 第几位（1起始）
* @return  TRUE:  该位为1 
*          FALSE: 该位为0
*************************************************************/
MTCBB_API BOOL32 mtIsBitSet(T tNum, u8 byBit)
{
	T byTmp = (tNum >> (byBit - 1)) & 0x01;

	return (1 == byTmp);
}



template <class T>
/*!**********************************************************
* @fn      T SAFE_CAST(T &t, u8 *pbyBuf)
* @brief   内存拷贝赋值
* @return  赋值后的变量
*************************************************************/
MTCBB_API T SAFE_CAST(T &t, u8 *pbyBuf)
{
	if (NULL == pbyBuf) return t;
	memcpy(&t, pbyBuf, sizeof(T));
	return t;
}


/*!**********************************************************
* 
* @brief   获得随机数
* @param   [in]  dwMaxRange: 随机数最大范围
* @param   [out] dwRandNum:  得到的随机数
* @return  获得的随机数
*************************************************************/
MTCBB_API u32 mtGetRandNum(u32 dwMaxRange);

MTCBB_API BOOL32 mtGetRandBytes(u8 *pOut, u32 &dwOutlen);

MTCBB_API u32 mtGetCallid( s8 *pchGuid );

MTCBB_API u32 mtGetGuid( u8 *pchGuid, u32 dwGuidLen );

template <typename T>
/*!**********************************************************
* 
* @brief   打印数字的十六进制表示
* @param   [in]  val 要打印的数字
*
* @return   无
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
* @brief   打印数字的二进制表示
* @param   [in]  val 要打印的数字
*
* @return  无
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
* @brief   求若干个数中的最小值(要比较的参数请传入相同类型)
* @param   [in]  dwArgsNum 要比较的参数个数
* @param   [in]  val1      要比较的第一个值
* @param   [in]  ...       可变参数，要比较的具体值
*
* @return  返回最小值
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
* @brief   求若干个数中的最大值(要比较的参数请传入相同类型)
* @param   [in]  dwArgsNum 要比较的参数个数
* @param   [in]  val1      要比较的第一个值
* @param   [in]  ...       可变参数，要比较的具体值
*
* @return  返回最小值
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
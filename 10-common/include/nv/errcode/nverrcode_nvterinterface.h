/**===========================================================================
 * @file    $Id$
 * @brief   ����NVTERINTERFACEҵ��ģ��Ĵ����붨��
 * @author  $Author$
 * @date    $Date $
 * @version  $Revision$
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note
============================================================================*/

#ifndef _NVERRORCODE_NVTERINTERFACE_H_
#define _NVERRORCODE_NVTERINTERFACE_H_
#include "kdvtype.h"

/////////////////////////////////////////////////BEGIN DEFINE/////////////////////////////////////////////////

/**
 *@brief ���������(10���Ʊ�ʾ)
 *	 99                   99                    9             9999
 *	ģ��        +      ��ҵ�����      +     ����ȼ�    +   ��������
 *(2λ/100��)        ��2λ/100����          ��1λ/10����     (4λ/10000��)
 */

/** NVACCESSҵ��ģ�����ҵ��ģ��ID����, ������ҵ����ඨ��ֻ������׷�� */
enum EM_ERR_SUBMOD_NVTERINTERFACE
{
    emErrSubModNvTerinterface_Base = 0,              ///< NvTerinterface������ҵ��ģ��
};

//////////////////////////////////////////////////////////// Base //////////////////////////////////////////////////////////////////////////////////////
/** NvTerinterfaceҵ��ģ����������붨�� */


/////////////////////////////////////////////////END DEFINE/////////////////////////////////////////////////

#endif // _NVTERINTERFACE_H_
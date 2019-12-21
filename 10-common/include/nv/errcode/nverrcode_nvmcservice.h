/**===========================================================================
 * @file    $Id$
 * @brief   ����NvMcserviceҵ��ģ��Ĵ����붨��
 * @author  $Author$
 * @date    $Date $
 * @version  $Revision$
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note
============================================================================*/

#ifndef _NVERRORCODE_NVMCSERVICE_H_
#define _NVERRORCODE_NVMCSERVICE_H_
#include "kdvtype.h"

/////////////////////////////////////////////////BEGIN DEFINE/////////////////////////////////////////////////

/**
 *@brief ���������(10���Ʊ�ʾ)
 *	 99                   99                    9             9999
 *	ģ��        +      ��ҵ�����      +     ����ȼ�    +   ��������
 *(2λ/100��)        ��2λ/100����          ��1λ/10����     (4λ/10000��)
 */

/** NVACCESSҵ��ģ�����ҵ��ģ��ID����, ������ҵ����ඨ��ֻ������׷�� */
enum EM_ERR_SUBMOD_NVMCSERVICE
{
    emErrSubModNvMcservice_Base = 0,              ///< nvmcservice������ҵ��ģ��
};

//////////////////////////////////////////////////////////// Base //////////////////////////////////////////////////////////////////////////////////////
/** nvmcserviceҵ��ģ����������붨�� */
enum EmNvMcErrorId
{
	ERR_NVMCSERVICE_BASE_NOTPERMIT_ADHOT = 1,                                             ///< �������Ե���չ�ɶ��
	ERR_NVMCSERVICE_BASE_HAS_ADHOT,                                                       ///< �Ѿ��Ƕ�������
	ERR_NVMCSERVICE_BASE_HASNOT_RESOURCE,                                                 ///< û����Դ�������е�endpoint���Ƿǿ���״̬
	ERR_NVMCSERVICE_BASE_CALLING_FAILED,
};

/////////////////////////////////////////////////END DEFINE/////////////////////////////////////////////////

#endif // _NVERRORCODE_NVMCSERVICE_H_
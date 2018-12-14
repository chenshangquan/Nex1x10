/**===========================================================================
 * @file    $Id$
 * @brief   ����MtMcserviceҵ��ģ��Ĵ����붨��
 * @author  $Author$
 * @date    $Date $
 * @version  $Revision$
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note
============================================================================*/

#ifndef _MTERRORCODE_MTMCSERVICE_H_
#define _MTERRORCODE_MTMCSERVICE_H_
#include "kdvtype.h"

/////////////////////////////////////////////////BEGIN DEFINE/////////////////////////////////////////////////

/**
 *@brief ���������(10���Ʊ�ʾ)
 *	 99                   99                    9             9999
 *	ģ��        +      ��ҵ�����      +     ����ȼ�    +   ��������
 *(2λ/100��)        ��2λ/100����          ��1λ/10����     (4λ/10000��)
 */

/** MTACCESSҵ��ģ�����ҵ��ģ��ID����, ������ҵ����ඨ��ֻ������׷�� */
enum EM_ERR_SUBMOD_MTMCSERVICE
{
    emErrSubModMtMcservice_Base = 0,              ///< mtmcservice������ҵ��ģ��
};

//////////////////////////////////////////////////////////// Base //////////////////////////////////////////////////////////////////////////////////////
/** mtmcserviceҵ��ģ����������붨�� */
enum EmMtMcErrorId
{
	ERR_MTMCSERVICE_BASE_NOTPERMIT_ADHOT = 1,                                             ///< �������Ե���չ�ɶ��
	ERR_MTMCSERVICE_BASE_HAS_ADHOT,                                                       ///< �Ѿ��Ƕ�������
	ERR_MTMCSERVICE_BASE_HASNOT_RESOURCE,                                                 ///< û����Դ�������е�endpoint���Ƿǿ���״̬
	ERR_MTMCSERVICE_BASE_CALLING_FAILED,
};

/////////////////////////////////////////////////END DEFINE/////////////////////////////////////////////////

#endif // _MTERRORCODE_MTMCSERVICE_H_
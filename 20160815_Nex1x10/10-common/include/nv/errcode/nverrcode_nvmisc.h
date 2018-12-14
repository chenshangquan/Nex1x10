/**===========================================================================
 * @file    $Id$
 * @brief   Сҵ��ģ������붨��
 * @author  �Ĵ���
 * @date    $Date $
 * @version  $Revision$
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note
============================================================================*/

#ifndef _NVERRORCODE_NVMISC_H_
#define _NVERRORCODE_NVMISC_H_
#include "kdvtype.h"

/////////////////////////////////////////////////BEGIN DEFINE/////////////////////////////////////////////////

/**
 *@brief ���������(10���Ʊ�ʾ)
 *	 99                   99                    9             9999
 *	ģ��        +      ��ҵ�����      +     ����ȼ�    +   ��������
 *(2λ/100��)        ��2λ/100����          ��1λ/10����     (4λ/10000��)
 */

/** nvutils��������ģ��ID����, ������ҵ����ඨ��ֻ������׷�� */
enum EM_ERR_SUBMOD_Misc
{
    emErrSubModMisc = 0,        ///< �ն˴�������ģ��
};


/** nvutilsģ������붨�� */
enum EmErrcodeUtils
{
  ERR_NVMISC_DISK_OUTOF_SPACE,                ///< ���̿ռ䲻��
  ERR_NVMISC_NETCAPTURE_STOP,                 ///< ץ��ֹͣ
  ERR_NVMISC_CREATPROCESS_FAILED,             ///< ��������ʧ��
  ERR_NVMISC_FILE_NOT_EXIST,                  ///< �ļ�������
  ERR_NVMISC_FILE_EXPORT_FAILED,              ///< �����ļ�ʧ��
  ERR_NVMISC_PATH_NOT_EXIST,                  ///< ·��������
  ERR_NVMISC_PROCESS_IS_RUNNING,              ///< ��������
};



/////////////////////////////////////////////////END DEFINE/////////////////////////////////////////////////

#endif // _NVERRORCODE_NVUTILS_H_
/**===========================================================================
 * @file    $Id$
 * @brief   Сҵ��ģ������붨��
 * @author  �Ĵ���
 * @date    $Date $
 * @version  $Revision$
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note
============================================================================*/

#ifndef _MTERRORCODE_MTMISC_H_
#define _MTERRORCODE_MTMISC_H_
#include "kdvtype.h"

/////////////////////////////////////////////////BEGIN DEFINE/////////////////////////////////////////////////

/**
 *@brief ���������(10���Ʊ�ʾ)
 *	 99                   99                    9             9999
 *	ģ��        +      ��ҵ�����      +     ����ȼ�    +   ��������
 *(2λ/100��)        ��2λ/100����          ��1λ/10����     (4λ/10000��)
 */

/** mtutils��������ģ��ID����, ������ҵ����ඨ��ֻ������׷�� */
enum EM_ERR_SUBMOD_Misc
{
    emErrSubModMisc = 0,        ///< �ն˴�������ģ��
};


/** mtutilsģ������붨�� */
enum EmErrcodeUtils
{
  ERR_MTMISC_DISK_OUTOF_SPACE,                ///< ���̿ռ䲻��
  ERR_MTMISC_NETCAPTURE_STOP,                 ///< ץ��ֹͣ
  ERR_MTMISC_CREATPROCESS_FAILED,             ///< ��������ʧ��
  ERR_MTMISC_FILE_NOT_EXIST,                  ///< �ļ�������
  ERR_MTMISC_FILE_EXPORT_FAILED,              ///< �����ļ�ʧ��
  ERR_MTMISC_PATH_NOT_EXIST,                  ///< ·��������
  ERR_MTMISC_PROCESS_IS_RUNNING,              ///< ��������
};



/////////////////////////////////////////////////END DEFINE/////////////////////////////////////////////////

#endif // _MTERRORCODE_MTUTILS_H_
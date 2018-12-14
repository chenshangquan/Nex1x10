/**===========================================================================
 * @file    $Id$
 * @brief   �����ն˹��ú�����������붨��
 * @author  $Author$
 * @date    $Date $
 * @version  $Revision$
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note
============================================================================*/

#ifndef _NVERRORCODE_NVUTILS_H_
#define _NVERRORCODE_NVUTILS_H_
#include "kdvtype.h"

/////////////////////////////////////////////////BEGIN DEFINE/////////////////////////////////////////////////

/**
 *@brief ���������(10���Ʊ�ʾ)
 *	 99                   99                    9             9999
 *	ģ��        +      ��ҵ�����      +     ����ȼ�    +   ��������
 *(2λ/100��)        ��2λ/100����          ��1λ/10����     (4λ/10000��)
 */

/** nvutils��������ģ��ID����, ������ҵ����ඨ��ֻ������׷�� */
enum EM_ERR_SUBMOD_UTILS
{
    emErrSubModUtils = 0,        ///< �ն˴�������ģ��
};


/** nvutilsģ������붨�� */
enum EmNvUtilsErrCode
{
	 ERR_NVUTILS_PATH_EXIST,    ///< �ļ�/�ļ��в�����
	 ERR_NVUTILS_BUF_NOTENOUGH,	///< ����������
	 ERR_NVUTILS_UNKOUWN_CHAR,	///< δ֪�ַ�  

	 ERR_NVUTILS_MALLOC_FAIL,   ///< malloc�ڴ����ʧ��
	 ERR_NVUTILS_INVALID_IP,    ///< �Ƿ�IP��ַ
	 ERR_NVUTILS_FILE_NOT_EXIST, ///< �ļ�������

	 ERR_NVUTILS_INSTALL_EXCEPTION_FAIL, ///< ��װ�쳣����ʧ��
	 ERR_NVUTILS_INVALID_POINTER,        ///< �Ƿ�ָ��
	 ERR_NVUTILS_INVALID_PATH,           ///< �Ƿ�·��
	 ERR_NVUTILS_REG_EXPMODULE_FAIL,     ///< ģ��ע��ʧ��
};


/////////////////////////////////////////////////END DEFINE/////////////////////////////////////////////////

#endif // _NVERRORCODE_NVUTILS_H_
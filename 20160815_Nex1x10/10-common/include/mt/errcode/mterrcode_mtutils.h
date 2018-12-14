/**===========================================================================
 * @file    $Id$
 * @brief   �����ն˹��ú�����������붨��
 * @author  $Author$
 * @date    $Date $
 * @version  $Revision$
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note
============================================================================*/

#ifndef _MTERRORCODE_MTUTILS_H_
#define _MTERRORCODE_MTUTILS_H_
#include "kdvtype.h"

/////////////////////////////////////////////////BEGIN DEFINE/////////////////////////////////////////////////

/**
 *@brief ���������(10���Ʊ�ʾ)
 *	 99                   99                    9             9999
 *	ģ��        +      ��ҵ�����      +     ����ȼ�    +   ��������
 *(2λ/100��)        ��2λ/100����          ��1λ/10����     (4λ/10000��)
 */

/** mtutils��������ģ��ID����, ������ҵ����ඨ��ֻ������׷�� */
enum EM_ERR_SUBMOD_UTILS
{
    emErrSubModUtils = 0,        ///< �ն˴�������ģ��
};


/** mtutilsģ������붨�� */
enum EmMtUtilsErrCode
{
	 ERR_MTUTILS_PATH_EXIST,    ///< �ļ�/�ļ��в�����
	 ERR_MTUTILS_BUF_NOTENOUGH,	///< ����������
	 ERR_MTUTILS_UNKOUWN_CHAR,	///< δ֪�ַ�  

	 ERR_MTUTILS_MALLOC_FAIL,   ///< malloc�ڴ����ʧ��
	 ERR_MTUTILS_INVALID_IP,    ///< �Ƿ�IP��ַ
	 ERR_MTUTILS_FILE_NOT_EXIST, ///< �ļ�������

	 ERR_MTUTILS_INSTALL_EXCEPTION_FAIL, ///< ��װ�쳣����ʧ��
	 ERR_MTUTILS_INVALID_POINTER,        ///< �Ƿ�ָ��
	 ERR_MTUTILS_INVALID_PATH,           ///< �Ƿ�·��
	 ERR_MTUTILS_REG_EXPMODULE_FAIL,     ///< ģ��ע��ʧ��
};


/////////////////////////////////////////////////END DEFINE/////////////////////////////////////////////////

#endif // _MTERRORCODE_MTUTILS_H_
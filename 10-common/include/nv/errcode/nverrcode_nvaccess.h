/**===========================================================================
 * @file    $Id$
 * @brief   ����NVACCESSҵ��ģ��Ĵ����붨��
 * @author  $Author$
 * @date    $Date $
 * @version  $Revision$
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note
============================================================================*/

#ifndef _NVERRORCODE_NVACCESS_H_
#define _NVERRORCODE_NVACCESS_H_
#include "kdvtype.h"

/////////////////////////////////////////////////BEGIN DEFINE/////////////////////////////////////////////////

/**
 *@brief ���������(10���Ʊ�ʾ)
 *	 99                   99                    9             9999
 *	ģ��        +      ��ҵ�����      +     ����ȼ�    +   ��������
 *(2λ/100��)        ��2λ/100����          ��1λ/10����     (4λ/10000��)
 */

/** NVACCESSҵ��ģ�����ҵ��ģ��ID����, ������ҵ����ඨ��ֻ������׷�� */
enum EM_ERR_SUBMOD_NVACCESS
{
    emErrSubModNvAccess_Base = 0,              ///< nvaccess������ҵ��ģ��
};

//////////////////////////////////////////////////////////// Base //////////////////////////////////////////////////////////////////////////////////////
/** nvaccessҵ��ģ����������붨�� */
enum EmNvAccessErrorId
{
	ERR_NVACCESS_BASE_USER_ERR = 1,                                                                                   ///< �û������Ϸ�
	ERR_NVACCESS_BASE_PSW_ERR,                                                                                        ///< �������
	ERR_NVACCESS_BASE_ACTOR_NOTMATCH,                                                                                 ///< �˺�û�иù���Ȩ�ޣ�������ָ�����¼��ʱ��ֻ��admin��������ɾ�����û�����
	ERR_NVACCESS_BASE_USER_DUPLICATE,                                                                                 ///< �ظ��˺�
	ERR_NVACCESS_BASE_USER_NOTEXIST,                                                                                  ///< �˺Ų�����
	ERR_NVACCESS_BASE_NOT_ENOUGHMEM,                                                                                  ///< �û���������û�����
	ERR_NVACCESS_BASE_ACTOR_ONLY,                                                                                     ///< ���������ʱû��ʹ�ã�
	ERR_NVACCESS_BASE_OPERATE_NOTPERMIT,                                                                              ///< û�в���Ȩ�ޣ�������ָ�����¼ֻ��admin�����޸��û�Ȩ��Ϊadmin������¼adminȨ�޲����޸ģ�
	ERR_NVACCESS_BASE_MULTILOGIN,                                                                                     ///< �ظ���¼����ʱû��ʹ�ã�
};

/////////////////////////////////////////////////END DEFINE/////////////////////////////////////////////////

#endif // _NVERRORCODE_NVACCESS_H_
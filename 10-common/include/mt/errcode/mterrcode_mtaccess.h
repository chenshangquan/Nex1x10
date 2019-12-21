/**===========================================================================
 * @file    $Id$
 * @brief   ����MTACCESSҵ��ģ��Ĵ����붨��
 * @author  $Author$
 * @date    $Date $
 * @version  $Revision$
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note
============================================================================*/

#ifndef _MTERRORCODE_MTACCESS_H_
#define _MTERRORCODE_MTACCESS_H_
#include "kdvtype.h"

/////////////////////////////////////////////////BEGIN DEFINE/////////////////////////////////////////////////

/**
 *@brief ���������(10���Ʊ�ʾ)
 *	 99                   99                    9             9999
 *	ģ��        +      ��ҵ�����      +     ����ȼ�    +   ��������
 *(2λ/100��)        ��2λ/100����          ��1λ/10����     (4λ/10000��)
 */

/** MTACCESSҵ��ģ�����ҵ��ģ��ID����, ������ҵ����ඨ��ֻ������׷�� */
enum EM_ERR_SUBMOD_MTACCESS
{
    emErrSubModMtAccess_Base = 0,              ///< mtaccess������ҵ��ģ��
};

//////////////////////////////////////////////////////////// Base //////////////////////////////////////////////////////////////////////////////////////
/** mtaccessҵ��ģ����������붨�� */
enum EmMtAccessErrorId
{
	ERR_MTACCESS_BASE_USER_ERR = 1,                                                                                   ///< �û������Ϸ�
	ERR_MTACCESS_BASE_PSW_ERR,                                                                                        ///< �������
	ERR_MTACCESS_BASE_ACTOR_NOTMATCH,                                                                                 ///< �˺�û�иù���Ȩ�ޣ�������ָ�����¼��ʱ��ֻ��admin��������ɾ�����û�����
	ERR_MTACCESS_BASE_USER_DUPLICATE,                                                                                 ///< �ظ��˺�
	ERR_MTACCESS_BASE_USER_NOTEXIST,                                                                                  ///< �˺Ų�����
	ERR_MTACCESS_BASE_NOT_ENOUGHMEM,                                                                                  ///< �û���������û�����
	ERR_MTACCESS_BASE_ACTOR_ONLY,                                                                                     ///< ���������ʱû��ʹ�ã�
	ERR_MTACCESS_BASE_OPERATE_NOTPERMIT,                                                                              ///< û�в���Ȩ�ޣ�������ָ�����¼ֻ��admin�����޸��û�Ȩ��Ϊadmin������¼adminȨ�޲����޸ģ�
	ERR_MTACCESS_BASE_MULTILOGIN,                                                                                     ///< �ظ���¼����ʱû��ʹ�ã�
};

/////////////////////////////////////////////////END DEFINE/////////////////////////////////////////////////

#endif // _MTERRORCODE_MTACCESS_H_
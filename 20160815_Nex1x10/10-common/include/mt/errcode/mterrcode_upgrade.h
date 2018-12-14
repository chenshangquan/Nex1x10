/**===========================================================================
 * @file    $Id$
 * @brief   ������ϵͳ�����붨��
 * @author  $Author$
 * @date    $Date $
 * @version  $Revision$
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note
============================================================================*/

#ifndef _MTERRORCODE_MTUPGRADE_H_
#define _MTERRORCODE_MTUPGRADE_H_
#include "kdvtype.h"

/////////////////////////////////////////////////BEGIN DEFINE/////////////////////////////////////////////////

/**
 *@brief ���������(10���Ʊ�ʾ)
 *	 99                   99                    9             9999
 *	ģ��        +      ��ҵ�����      +     ����ȼ�    +   ��������
 *(2λ/100��)        ��2λ/100����          ��1λ/10����     (4λ/10000��)
 */

/** ������ϵͳ��������ģ��ID����, ������ҵ����ඨ��ֻ������׷�� */
enum EM_ERR_SUBMOD_UPGRADE
{
    emErrSubModUpgrade = 0,        ///< �ն˴�������ģ��
};


/** ������ϵͳģ������붨�� */
enum EmMtUpgradeErrCode
{
	ERR_UPGRADE_UNKNOWN,                  ///< δ֪����
	ERR_UPGRADE_INVALID_FILE,	          ///< �Ƿ��ļ�
	ERR_UPGRADE_INVALID_PATH,	          ///< �Ƿ�·��
	ERR_UPGRADE_INVALID_SN,	              ///< �Ƿ��汾���к�
	ERR_UPGRADE_CONNECT_SERVER_FAILED,    ///< ���ӷ�����ʧ��
	ERR_UPGRADE_SYS_BACKUP_FAILED,		  ///< ϵͳ����ʧ��
	ERR_UPGRADE_SYS_MOUNTAPPBAK_FAILED,	  ///< ����APP��������ʧ��
	ERR_UPGRADE_FILE_CHECK_FAILED,		  ///< �ļ�У��ʧ��
	ERR_UPGRADE_WHOLEUPGRADE_FAILED,	  ///< ��������ʧ��
	ERR_UPGRADE_IOS_UPGRADE_FAILED,		  ///< IOS����ʧ��
	ERR_UPGRADE_FPGA_UPGRADE_FAILED,	  ///< fpga����ʧ��
	ERR_UPGRADE_DISK_SPACE_NOT_ENOUGH,	  ///< ���̿ռ䲻��
	ERR_UPGRADE_MAX_SERVICE_SESSION_ERR, //�������Ѵ������������
	ERR_UPGRADE_TIMEOUT,  //������ʱ
	ERR_UPGRADE_NOT_PREPARED_NOW_ERR,  //��������δ�������
	ERR_UPGRADE_FILE_NOT_EXIST_ERR, //ָ���ļ�������
	ERR_UPGRADE_DEV_NOT_EXIST_ERR, //���������޴��豸�İ汾
	ERR_UPGRADE_OEMREMARK_NOT_MATCH,  //OEM��ʶ��ƥ��
    ERR_UPGRADE_DNS_ERR,                 ///��������ʧ��
};


/////////////////////////////////////////////////END DEFINE/////////////////////////////////////////////////

#endif // _MTERRORCODE_MTUPGRADE_H_
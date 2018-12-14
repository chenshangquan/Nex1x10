/**===========================================================================
 * @file    $Id$
 * @brief   ����MTDATASHAREҵ��ģ��Ĵ����붨��
 * @author  Ǯ��
 * @date    $Date $
 * @version  $Revision$
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note
============================================================================*/

#ifndef _MTERRORCODE_MTSVRLOGIN_H_
#define _MTERRORCODE_MTSVRLOGIN_H_
#include "kdvtype.h"
#include "mterrcode_api.h"
#include "mterrcode_def.h"
/////////////////////////////////////////////////BEGIN DEFINE/////////////////////////////////////////////////

/**
 *@brief ���������(10���Ʊ�ʾ)
 *	 99                   99                    9             9999
 *	ģ��        +      ��ҵ�����      +     ����ȼ�    +   ��������
 *(2λ/100��)        ��2λ/100����          ��1λ/10����     (4λ/10000��)
 */

/** MTSVRLOGINҵ��ģ�����ҵ��ģ��ID����, ������ҵ����ඨ��ֻ������׷�� */
enum EM_ERR_SUBMOD_MTSVRLOGIN
{
    emErrSubModCtrl = 0,         ///< ��������¼����
	emErrSubModDns,              ///< ��������¼��������
	emErrSubModXap,              ///< ��������¼xap
};
//////////////////////////////////////////////////////////// Base //////////////////////////////////////////////////////////////////////////////////////
/** ��������¼���ƻ��������붨�� */
enum EmSvrLoginCtrlErrorId
{
	ERR_SvrLoginCtrl_None = 0,
	ERR_OverwriteValidIp,
	ERR_IpValid,
	ERR_TranslateDomain,
	ERR_NoSvrAddr,
	ERR_SvrTypeInvalid,
	ERR_DomainTranslateFail,
	ERR_CBCheckAddrMissing,
	ERR_SvrLoginCtrl_End,
};
/** ��������¼�����������������붨�� */
enum EmSvrLoginDnsErrorId
{

};
/** ��������¼xap��¼���������붨�� */
enum EmSvrLoginXapErrorId
{
	ERR_SvrLoginXap_None = 0,
	ERR_StateUnmatch,
	ERR_NewIpExist,
	ERR_SvrLoginXap_End
};



/////////////////////////////////////////////////END DEFINE/////////////////////////////////////////////////

#endif // _MTERRORCODE_MTSVRLOGIN_H_
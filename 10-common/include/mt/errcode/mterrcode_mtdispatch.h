/**===========================================================================
 * @file    $Id$
 * @brief   ����MTDISPATCHҵ��ģ��Ĵ����붨��
 * @author  longwei
 * @date    $Date $
 * @version  $Revision$
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note
============================================================================*/

#ifndef _MTERRORCODE_MTDISPATCH_H_
#define _MTERRORCODE_MTDISPATCH_H_
#include "kdvtype.h"

/////////////////////////////////////////////////BEGIN DEFINE/////////////////////////////////////////////////

/**
 *@brief ���������(10���Ʊ�ʾ)
 *	 99                   99                    9             9999
 *	ģ��        +      ��ҵ�����      +     ����ȼ�    +   ��������
 *(2λ/100��)        ��2λ/100����          ��1λ/10����     (4λ/10000��)
 */

/** MTDISPATCHҵ��ģ�����ҵ��ģ��ID����, ������ҵ����ඨ��ֻ������׷�� */
enum EM_ERR_SUBMOD_MTDISPATCH
{
    emErrSubModMtDispatch_Base = 0,              ///< mtdispatch������ҵ��ģ��
};

//////////////////////////////////////////////////////////// Base //////////////////////////////////////////////////////////////////////////////////////
/** mtdispatchҵ��ģ����������붨�� */
enum EmMtDispatchErrorId
{
	ERR_MTDISPATCH_BASE_CHECKSUBSMSGID_SUCCESS = 1,                                                                                  ///< У��������Ϣ���ݽṹ�ɹ�
	ERR_MTDISPATCH_BASE_CHECKSUBSMSGID_NOMSG,                                                                                        ///< У��������Ϣ���ݽṹʧ�ܣ���Ϊ������Ϣ���ݽṹ��û����Ϣ��
	ERR_MTDISPATCH_BASE_CHECKSUBSMSGID_ERRORMSGSEG,                                                                                  ///< У��������Ϣ���ݽṹʧ�ܣ���Ϊ������Ϣ���ݽṹ����Ϣ�β��Ϸ�
	ERR_MTDISPATCH_BASE_SUBSUNIT_NULL,                                                                                               ///< ���ĵ�ԪΪNULL
	ERR_MTDISPATCH_BASE_SUBS_SUCCESS,                                                                                                ///< ��Ϣ���ĳɹ�
	ERR_MTDISPATCH_BASE_DISPATCH_SUCCESS,                                                                                            ///< ��Ϣ�ַ��ɹ�
	ERR_MTDISPATCH_BASE_DISPATCH_NULL,                                                                                               ///< ��Ϣ�ַ���ΪNULL
	ERR_MTDISPATCH_BASE_DISPATCH_NOTTDEAL,                                                                                           ///< ��Ϣ�ַ������ַܷ�������Ϣ
	ERR_MTDISPATCH_BASE_MTMSG_NULL,                                                                                                  ///< �����CMtMsg*ΪNULL
	ERR_MTDISPATCH_BASE_OSPMSG_NULL,                                                                                                 ///< �����CMessage*ΪNULL
	ERR_MTDISPATCH_BASE_ENCODEMSG_FAILED,                                                                                            ///< �����CMtMsg����ʧ��
	ERR_MTDISPATCH_BASE_POSTMSG_FAILED,                                                                                              ///< OSP������Ϣʧ��
	ERR_MTDISPATCH_BASE_GETSUBSMSGSESSION_SUCCESS,                                                                                   ///< ��ȡ�����߳ɹ�
	ERR_MTDISPATCH_BASE_DISPATCH_FAILED,                                                                                             ///< ��Ϣ�ַ�ʧ��
};

/////////////////////////////////////////////////END DEFINE/////////////////////////////////////////////////

#endif // _MTERRORCODE_MTDISPATCH_H_
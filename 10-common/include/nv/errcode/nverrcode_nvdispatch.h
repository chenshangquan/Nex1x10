/**===========================================================================
 * @file    $Id$
 * @brief   ����NVDISPATCHҵ��ģ��Ĵ����붨��
 * @author  longwei
 * @date    $Date $
 * @version  $Revision$
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note
============================================================================*/

#ifndef _NVERRORCODE_NVDISPATCH_H_
#define _NVERRORCODE_NVDISPATCH_H_
#include "kdvtype.h"

/////////////////////////////////////////////////BEGIN DEFINE/////////////////////////////////////////////////

/**
 *@brief ���������(10���Ʊ�ʾ)
 *	 99                   99                    9             9999
 *	ģ��        +      ��ҵ�����      +     ����ȼ�    +   ��������
 *(2λ/100��)        ��2λ/100����          ��1λ/10����     (4λ/10000��)
 */

/** NVDISPATCHҵ��ģ�����ҵ��ģ��ID����, ������ҵ����ඨ��ֻ������׷�� */
enum EM_ERR_SUBMOD_NVDISPATCH
{
    emErrSubModNvDispatch_Base = 0,              ///< nvdispatch������ҵ��ģ��
};

//////////////////////////////////////////////////////////// Base //////////////////////////////////////////////////////////////////////////////////////
/** nvdispatchҵ��ģ����������붨�� */
enum EmNvDispatchErrorId
{
	ERR_NVDISPATCH_BASE_CHECKSUBSMSGID_SUCCESS = 1,                                                                                  ///< У��������Ϣ���ݽṹ�ɹ�
	ERR_NVDISPATCH_BASE_CHECKSUBSMSGID_NOMSG,                                                                                        ///< У��������Ϣ���ݽṹʧ�ܣ���Ϊ������Ϣ���ݽṹ��û����Ϣ��
	ERR_NVDISPATCH_BASE_CHECKSUBSMSGID_ERRORMSGSEG,                                                                                  ///< У��������Ϣ���ݽṹʧ�ܣ���Ϊ������Ϣ���ݽṹ����Ϣ�β��Ϸ�
	ERR_NVDISPATCH_BASE_SUBSUNIT_NULL,                                                                                               ///< ���ĵ�ԪΪNULL
	ERR_NVDISPATCH_BASE_SUBS_SUCCESS,                                                                                                ///< ��Ϣ���ĳɹ�
	ERR_NVDISPATCH_BASE_DISPATCH_SUCCESS,                                                                                            ///< ��Ϣ�ַ��ɹ�
	ERR_NVDISPATCH_BASE_DISPATCH_NULL,                                                                                               ///< ��Ϣ�ַ���ΪNULL
	ERR_NVDISPATCH_BASE_DISPATCH_NOTTDEAL,                                                                                           ///< ��Ϣ�ַ������ַܷ�������Ϣ
	ERR_NVDISPATCH_BASE_NVMSG_NULL,                                                                                                  ///< �����CNvMsg*ΪNULL
	ERR_NVDISPATCH_BASE_OSPMSG_NULL,                                                                                                 ///< �����CMessage*ΪNULL
	ERR_NVDISPATCH_BASE_ENCODEMSG_FAILED,                                                                                            ///< �����CNvMsg����ʧ��
	ERR_NVDISPATCH_BASE_POSTMSG_FAILED,                                                                                              ///< OSP������Ϣʧ��
	ERR_NVDISPATCH_BASE_GETSUBSMSGSESSION_SUCCESS,                                                                                   ///< ��ȡ�����߳ɹ�
	ERR_NVDISPATCH_BASE_DISPATCH_FAILED,                                                                                             ///< ��Ϣ�ַ�ʧ��
};

/////////////////////////////////////////////////END DEFINE/////////////////////////////////////////////////

#endif // _NVERRORCODE_NVDISPATCH_H_
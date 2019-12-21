/**===========================================================================
 * @file    $Id$
 * @brief   ����NVSDKҵ��ģ��Ĵ����붨��
 * @author  $Author$
 * @date    $Date $
 * @version  $Revision$
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note
============================================================================*/

#ifndef _NVERRORCODE_NVSDK_H_
#define _NVERRORCODE_NVSDK_H_
#include "kdvtype.h"

/////////////////////////////////////////////////BEGIN DEFINE/////////////////////////////////////////////////

/**
 *@brief ���������(10���Ʊ�ʾ)
 *	 99                   99                    9             9999
 *	ģ��        +      ��ҵ�����      +     ����ȼ�    +   ��������
 *(2λ/100��)        ��2λ/100����          ��1λ/10����     (4λ/10000��)
 */

/** NVSDKҵ��ģ�����ҵ��ģ��ID����, ������ҵ����ඨ��ֻ������׷�� */
enum EM_ERR_SUBMOD_NVSDK
{
    emErrSubModNvSdk_BaseSdk = 0,              ///< nvbasesdk��ҵ��ģ��
    emErrSubModNvSdk_ConfCtrl,                 ///< nvconfctrlsdk��ҵ��ģ��
	emErrSubModNvSdk_Pcdv,                     ///< nvpcdvsdk��ҵ��ģ��
	emErrSubModNvSdk_MediaCtrl,                ///< nvmediactrlsdk��ҵ��ģ��
	emErrSubModNvSdk_MeetingMgr,               ///< nvmeetingmgrsdk��ҵ��ģ��
	emErrSubModNvSdk_IM,                       ///< nvimsdk��ҵ��ģ��
	emErrSubModNvSdk_DataConf,                 ///< nvdataconfsdk��ҵ��ģ��
	emErrSubModNvSdk_CloudAddr,                ///< nvcloudaddrsdk��ҵ��ģ��
	emErrSubModNvSdk_Diagnose,                 ///< nvdiagnosesdk��ҵ��ģ��
};

//////////////////////////////////////////////////////////// BaseSdk //////////////////////////////////////////////////////////////////////////////////////
/** nvsdk֮nvbasesdk��ҵ��ģ������붨�� */
#define  ERR_NVSDK_BASESDK_NO_INITIALIZE                               (u32)1                                             ///< BASESDKδ��ʼ��
#define  ERR_NVSDK_BASESDK_NO_LOGIN                                    (u32)2                                             ///< ��δ��¼���ն�(C/Sģʽ)


//////////////////////////////////////////////////////////// ConfCtrl ////////////////////////////////////////////////////////////////////////////////////
/** nvsdk֮confctrl��ҵ��ģ������붨�� */
#define  ERR_NVSDK_CONFCTRL_INVALID_E164                               (u32)1                                             ///< �����õ�E164����



//////////////////////////////////////////////////////////// PCDV ////////////////////////////////////////////////////////////////////////////////////////
/** nvsdk֮pcdv��ҵ��ģ������붨�� */
#define  ERR_NVSDK_PCDV_INVALID_IP                                     (u32)1                                                  ///< �����õ��ն�IP


//////////////////////////////////////////////////////////// MediaCtrl ///////////////////////////////////////////////////////////////////////////////////
/** nvsdk֮MediaCtrl��ҵ��ģ������붨�� */
#define  ERR_NVSDK_MEDIACTRL_CREATE_DECODER_FAILED                     (u32)1                                                  ///< ����������ʧ��


//////////////////////////////////////////////////////////// MeetingMgr //////////////////////////////////////////////////////////////////////////////////
/** nvsdk֮MeetingMgr��ҵ��ģ������붨�� */
#define  ERR_NVSDK_MEDIACTRL_CREATE_DECODER_FAILED                     (u32)1                                                  ///< ����������ʧ��



////////////////////////////////////////////////////////////     IM    //////////////////////////////////////////////////////////////////////////////////
/** nvsdk֮IM��ҵ��ģ������붨�� */
#define  ERR_NVSDK_IM_LOGIN_FAILED                                     (u32)1                                                  ///< IM��¼ʧ��



////////////////////////////////////////////////////////////  DataConf //////////////////////////////////////////////////////////////////////////////////
/** nvsdk֮DataConf��ҵ��ģ������붨�� */
#define  ERR_NVSDK_DATACONF_LOGIN_FAILED                               (u32)1                                                  ///< ���ݹ����¼ʧ��



////////////////////////////////////////////////////////////  CloudAddr //////////////////////////////////////////////////////////////////////////////////
/** nvsdk֮CloudAddr��ҵ��ģ������붨�� */
#define  ERR_NVSDK_CLOUDEADDR_SERVER_DISCONNECT                         (u32)1                                                 ///< �ƶ���ϵ�˷������Ͽ�


////////////////////////////////////////////////////////////  Diagnose //////////////////////////////////////////////////////////////////////////////////
/** nvsdk֮Diagnose��ҵ��ģ������붨�� */
#define  ERR_NVSDK_DIAGNOSE_NO_DATA                                     (u32)1                                                 ///< ���������




/////////////////////////////////////////////////END DEFINE/////////////////////////////////////////////////

#endif // _NVERRORCODE_NVSDK_H_
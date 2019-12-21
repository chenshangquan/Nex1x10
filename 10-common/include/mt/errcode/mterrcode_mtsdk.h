/**===========================================================================
 * @file    $Id$
 * @brief   ����MTSDKҵ��ģ��Ĵ����붨��
 * @author  $Author$
 * @date    $Date $
 * @version  $Revision$
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note
============================================================================*/

#ifndef _MTERRORCODE_MTSDK_H_
#define _MTERRORCODE_MTSDK_H_
#include "kdvtype.h"

/////////////////////////////////////////////////BEGIN DEFINE/////////////////////////////////////////////////

/**
 *@brief ���������(10���Ʊ�ʾ)
 *	 99                   99                    9             9999
 *	ģ��        +      ��ҵ�����      +     ����ȼ�    +   ��������
 *(2λ/100��)        ��2λ/100����          ��1λ/10����     (4λ/10000��)
 */

/** MTSDKҵ��ģ�����ҵ��ģ��ID����, ������ҵ����ඨ��ֻ������׷�� */
enum EM_ERR_SUBMOD_MTSDK
{
    emErrSubModMtSdk_BaseSdk = 0,              ///< mtbasesdk��ҵ��ģ��
    emErrSubModMtSdk_ConfCtrl,                 ///< mtconfctrlsdk��ҵ��ģ��
	emErrSubModMtSdk_Pcdv,                     ///< mtpcdvsdk��ҵ��ģ��
	emErrSubModMtSdk_MediaCtrl,                ///< mtmediactrlsdk��ҵ��ģ��
	emErrSubModMtSdk_MeetingMgr,               ///< mtmeetingmgrsdk��ҵ��ģ��
	emErrSubModMtSdk_IM,                       ///< mtimsdk��ҵ��ģ��
	emErrSubModMtSdk_DataConf,                 ///< mtdataconfsdk��ҵ��ģ��
	emErrSubModMtSdk_CloudAddr,                ///< mtcloudaddrsdk��ҵ��ģ��
	emErrSubModMtSdk_Diagnose,                 ///< mtdiagnosesdk��ҵ��ģ��
};

//////////////////////////////////////////////////////////// BaseSdk //////////////////////////////////////////////////////////////////////////////////////
/** mtsdk֮mtbasesdk��ҵ��ģ������붨�� */
#define  ERR_MTSDK_BASESDK_NO_INITIALIZE                               (u32)1                                             ///< BASESDKδ��ʼ��
#define  ERR_MTSDK_BASESDK_NO_LOGIN                                    (u32)2                                             ///< ��δ��¼���ն�(C/Sģʽ)


//////////////////////////////////////////////////////////// ConfCtrl ////////////////////////////////////////////////////////////////////////////////////
/** mtsdk֮confctrl��ҵ��ģ������붨�� */
#define  ERR_MTSDK_CONFCTRL_INVALID_E164                               (u32)1                                             ///< �����õ�E164����



//////////////////////////////////////////////////////////// PCDV ////////////////////////////////////////////////////////////////////////////////////////
/** mtsdk֮pcdv��ҵ��ģ������붨�� */
#define  ERR_MTSDK_PCDV_INVALID_IP                                     (u32)1                                                  ///< �����õ��ն�IP


//////////////////////////////////////////////////////////// MediaCtrl ///////////////////////////////////////////////////////////////////////////////////
/** mtsdk֮MediaCtrl��ҵ��ģ������붨�� */
#define  ERR_MTSDK_MEDIACTRL_CREATE_DECODER_FAILED                     (u32)1                                                  ///< ����������ʧ��


//////////////////////////////////////////////////////////// MeetingMgr //////////////////////////////////////////////////////////////////////////////////
/** mtsdk֮MeetingMgr��ҵ��ģ������붨�� */
#define  ERR_MTSDK_MEDIACTRL_CREATE_DECODER_FAILED                     (u32)1                                                  ///< ����������ʧ��



////////////////////////////////////////////////////////////     IM    //////////////////////////////////////////////////////////////////////////////////
/** mtsdk֮IM��ҵ��ģ������붨�� */
#define  ERR_MTSDK_IM_LOGIN_FAILED                                     (u32)1                                                  ///< IM��¼ʧ��



////////////////////////////////////////////////////////////  DataConf //////////////////////////////////////////////////////////////////////////////////
/** mtsdk֮DataConf��ҵ��ģ������붨�� */
#define  ERR_MTSDK_DATACONF_LOGIN_FAILED                               (u32)1                                                  ///< ���ݹ����¼ʧ��



////////////////////////////////////////////////////////////  CloudAddr //////////////////////////////////////////////////////////////////////////////////
/** mtsdk֮CloudAddr��ҵ��ģ������붨�� */
#define  ERR_MTSDK_CLOUDEADDR_SERVER_DISCONNECT                         (u32)1                                                 ///< �ƶ���ϵ�˷������Ͽ�


////////////////////////////////////////////////////////////  Diagnose //////////////////////////////////////////////////////////////////////////////////
/** mtsdk֮Diagnose��ҵ��ģ������붨�� */
#define  ERR_MTSDK_DIAGNOSE_NO_DATA                                     (u32)1                                                 ///< ���������




/////////////////////////////////////////////////END DEFINE/////////////////////////////////////////////////

#endif // _MTERRORCODE_MTSDK_H_
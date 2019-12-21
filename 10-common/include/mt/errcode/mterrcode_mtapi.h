/**===========================================================================
 * @file    $Id$
 * @brief   ����MTAPIҵ��ģ��Ĵ����붨��
 * @author  $Author$
 * @date    $Date $
 * @version  $Revision$
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note
============================================================================*/

#ifndef _MTERRORCODE_MTAPI_H_
#define _MTERRORCODE_MTAPI_H_
#include "kdvtype.h"

/////////////////////////////////////////////////BEGIN DEFINE/////////////////////////////////////////////////

/**
 *@brief ���������(10���Ʊ�ʾ)
 *	 99                   99                    9             9999
 *	ģ��        +      ��ҵ�����      +     ����ȼ�    +   ��������
 *(2λ/100��)        ��2λ/100����          ��1λ/10����     (4λ/10000��)
 */

/** MTAPIҵ��ģ�����ҵ��ģ��ID����, ������ҵ����ඨ��ֻ������׷�� */
enum EM_ERR_SUBMOD_MTAPI
{
    emErrSubModMtApi_BaseSdk = 1,              ///< mtbasesdk��ҵ��ģ��
    emErrSubModMtApi_VideoConf,                ///< mtvideoconfsdk��ҵ��ģ��
	emErrSubModMtApi_Vnc,                      ///< mtvncsdk��ҵ��ģ��
	emErrSubModMtApi_MeetingMgr,               ///< mtmeetingmgrsdk��ҵ��ģ��
	emErrSubModMtApi_IM,                       ///< mtimsdk��ҵ��ģ��
	emErrSubModMtApi_DataConf,                 ///< mtdataconfsdk��ҵ��ģ��
	emErrSubModMtApi_ContactMgr,               ///< mtContactMgrsdk��ҵ��ģ��
	emErrSubModMtApi_Diagnose,                 ///< mtDiagnose��ҵ��ģ��
	emErrSubModMtApi_ErrCode,                  ///< mterrcode��������ҵ��ģ��
	emErrSubModMtApi_Dcs,					   ///< mtdcs���Ӱװ���ҵ��ģ��
};

//////////////////////////////////////////////////////////// BaseSdk ////////////////////////////////////////////////////////////////////////////////////
/** mtapi֮mtbasesdk��ҵ��ģ������붨�� */
enum EM_MTAPI_BS
{   
	ERR_MTAPI_BS_NO_INITIALIZE = 1,                         ///< BASESDKδ��ʼ��
	ERR_MTAPI_BS_EXISTED_SESSION,                           ///< �Ѿ����ڵ�SessionID
	ERR_MTAPI_BS_NO_AVAILABLE_SESSION,                      ///< û�п��õĻỰ��
	ERR_MTAPI_BS_ALREADY_CONNECTED,                         ///< �Ѿ�����
	ERR_MTAPI_BS_CONNECT_FAILED,                            ///< ����ʧ�ܣ��Զ˲��ɴ�
	ERR_MTAPI_BS_NO_CONNECT,                                ///< ��δ����
	ERR_MTAPI_BS_LOGINMSG_ENCODING_FAILED,                  ///< ��¼��Ϣ����ʧ��
	ERR_MTAPI_BS_LOGINMSG_SENDING_FAILED,                   ///< ��¼��Ϣ����ʧ��
	ERR_MTAPI_BS_DISPMSG_ENCODING_FAILED,                   ///< ���͸�Dispatch��Ϣ����ʧ��
	ERR_MTAPI_BS_DISPMSG_SENDING_FAILED,                    ///< ���͸�Dispatch��Ϣ����ʧ��
	ERR_MTAPI_BS_USER_LOGININFO_INCORRECT,                  ///< ���͸�Dispatch��Ϣ����ʧ��
	ERR_MTAPI_BS_PARAM_NULL_POINTER,                        ///< ������ָ���쳣
	ERR_MTAPI_BS_CREATE_CONNECT_FAILED,                     ///< ��������ʧ��
	ERR_MTAPI_BS_CREATE_CONNECT_OBJ_FAILED,                 ///< �����������Ӷ���ʧ��
}; 

//////////////////////////////////////////////////////////// VideoConf///////////////////////////////////////////////////////////////////////////////////
/** mtapi֮confctrl��ҵ��ģ������붨�� */
enum EM_MTAPI_VC
{   
	ERR_MTAPI_VC_NO_INITIALIZE = 1,                         ///< VideoConfSDKδ��ʼ��
	ERR_MTAPI_VC_INVALID_E164,                              ///< �����õ�E164����
	ERR_MTAPI_VC_PARAM_NULL_POINTER,                        ///< ������ָ���쳣
	ERR_MTAPI_VC_MEMORY_NOT_ENOUGH,                         ///< �ռ䲻��
	ERR_MTAPI_VC_IDX_OUTOFRANG,                             ///< Խ������

};

//////////////////////////////////////////////////////////// VideoConf///////////////////////////////////////////////////////////////////////////////////
/** mtapi֮diagnose��ҵ��ģ������붨�� */
enum EM_MTAPI_DIAGNOSE
{   
	ERR_MTAPI_DIAGNOSE_NO_INITIALIZE = 1,                         ///< DiagnoseSDKδ��ʼ��
	ERR_MTAPI_DIAGNOSE_PARAM_NULL_POINTER,                        ///< ������ָ���쳣
	ERR_MTAPI_DIAGNOSE_MEMORY_NOT_ENOUGH,                         ///< �ռ䲻��
	ERR_MTAPI_DIAGNOSE_IDX_OUTOFRANG,                             ///< Խ������

};



//////////////////////////////////////////////////////////// VNC ////////////////////////////////////////////////////////////////////////////////////////
/** mtapi֮VNC��ҵ��ģ������붨�� */
enum EM_MTAPI_VNC
{   
	ERR_MTAPI_VNC_NO_INITIALIZE = 1,                         ///< MTVNC���湲��SDKδ��ʼ��
	ERR_MTAPI_VNC_INVALID_IP,                                ///< �����õ��ն�IP
};

 

//////////////////////////////////////////////////////////// MeetingMgr //////////////////////////////////////////////////////////////////////////////////
/** mtapi֮MeetingMgr��ҵ��ģ������붨�� */
enum EM_MTAPI_MG
{   
	ERR_MTAPI_MG_NO_INITIALIZE = 1,                         ///< MeetingMgrSDKδ��ʼ��
	ERR_MTAPI_MG_LOGIN_FAILED,                              ///< ��ܵ�¼ʧ��
};


////////////////////////////////////////////////////////////     IM    //////////////////////////////////////////////////////////////////////////////////
/** mtapi֮IM��ҵ��ģ������붨�� */
enum EM_MTAPI_IM
{   
	ERR_MTAPI_IM_NO_INITIALIZE = 1,                         ///< IMSDKδ��ʼ��
	ERR_MTAPI_IM_LOGIN_FAILED,                              ///< IM��¼ʧ��
};


////////////////////////////////////////////////////////////  DataConf //////////////////////////////////////////////////////////////////////////////////
/** mtapi֮DataConf��ҵ��ģ������붨�� */
enum EM_MTAPI_DC
{   
	ERR_MTAPI_DC_NO_INITIALIZE = 1,                        ///< DataConfSDKδ��ʼ��
	ERR_MTAPI_DC_LOGIN_FAILED,                             ///< ���ݹ����¼ʧ��
};


////////////////////////////////////////////////////////////  ContactMgr /////////////////////////////////////////////////////////////////////////////////
/** mtapi֮ContactMgr��ҵ��ģ������붨�� */
enum EM_MTAPI_CM
{   
	ERR_MTAPI_CM_NO_INITIALIZE = 1,                        ///< ContactMgrSDKδ��ʼ��
	ERR_MTAPI_CM_SERVER_DISCONNECT,                        ///< �ƶ���ϵ�˷������Ͽ�
};



////////////////////////////////////////////////////////////  ErrCode //////////////////////////////////////////////////////////////////////////////////
/** mtapi֮mterrcode��������ҵ��ģ�� */
enum EM_MTAPI_ERRCODE
{   
	ERR_MTAPI_ERRCODE_XMLFILENAME_ISEMPTY = 1,               ///< ָ�����ļ���Ϊ��
	ERR_MTAPI_ERRCODE_XMLFILE_ISNOT_EXIST,                   ///< ָ�����ļ�������
	ERR_MTAPI_ERRCODE_CREATE_XMLDOC_FAILED,                  ///< ����XML Doc Parse����ʧ��
	ERR_MTAPI_ERRCODE_CREATE_XMLDOC_EXCEPTION,               ///< ����XML Doc Parse����ʧ��
	ERR_MTAPI_ERRCODE_LOAD_XMLDOC_FAILED,                    ///< Xml Doc Parse����ָ����XMLʧ��
	ERR_MTAPI_ERRCODE_SAVE_ERRDESCBUF_NOT_ENOUGH,            ///< �洢������������Ϣ��buf����
	ERR_MTAPI_ERRCODE_NOT_CREATE_XMLDOC_PARSE,               ///< ���ܻ�ȡ����������Ϣ��δ����XMLDoc��������
	ERR_MTAPI_ERRCODE_NOT_EXIST,                             ///< �����ڵĴ�����
	ERR_MTAPI_ERRCODE_GET_ERRDESC_FAILED,                    ///< ��ȡ������������Ϣʧ��
	ERR_MTAPI_ERRCODE_XMLNODE_NOT_EXIST,                     ///< �����������ļ�XMLȱ�ٽڵ�
};

////////////////////////////////////////////////////////////     DCS    //////////////////////////////////////////////////////////////////////////////////
/** mtapi֮DCS��ҵ��ģ������붨�� */
enum EM_MTAPI_DCS
{   
	ERR_MTAPI_DCS_NO_INITIALIZE = 1,                         ///< DCSSDKδ��ʼ��
	ERR_MTAPI_DCS_LOGIN_FAILED,                              ///< DCS��¼ʧ��
};

/////////////////////////////////////////////////END DEFINE/////////////////////////////////////////////////

#endif // _MTERRORCODE_MTAPI_H_
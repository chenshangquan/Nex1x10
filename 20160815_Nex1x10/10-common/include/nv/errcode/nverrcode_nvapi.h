/**===========================================================================
 * @file    $Id$
 * @brief   ����NVAPIҵ��ģ��Ĵ����붨��
 * @author  $Author$
 * @date    $Date $
 * @version  $Revision$
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note
============================================================================*/

#ifndef _NVERRORCODE_NVAPI_H_
#define _NVERRORCODE_NVAPI_H_
#include "kdvtype.h"

/////////////////////////////////////////////////BEGIN DEFINE/////////////////////////////////////////////////

/**
 *@brief ���������(10���Ʊ�ʾ)
 *	 99                   99                    9             9999
 *	ģ��        +      ��ҵ�����      +     ����ȼ�    +   ��������
 *(2λ/100��)        ��2λ/100����          ��1λ/10����     (4λ/10000��)
 */

/** NVAPIҵ��ģ�����ҵ��ģ��ID����, ������ҵ����ඨ��ֻ������׷�� */
enum EM_ERR_SUBMOD_NVAPI
{
    emErrSubModNvApi_BaseSdk = 1,              ///< nvbasesdk��ҵ��ģ��
    emErrSubModNvApi_VideoConf,                ///< nvvideoconfsdk��ҵ��ģ��
	emErrSubModNvApi_Vnc,                      ///< nvvncsdk��ҵ��ģ��
	emErrSubModNvApi_MeetingMgr,               ///< nvmeetingmgrsdk��ҵ��ģ��
	emErrSubModNvApi_IM,                       ///< nvimsdk��ҵ��ģ��
	emErrSubModNvApi_DataConf,                 ///< nvdataconfsdk��ҵ��ģ��
	emErrSubModNvApi_ContactMgr,               ///< nvContactMgrsdk��ҵ��ģ��
	emErrSubModNvApi_Diagnose,                 ///< nvDiagnose��ҵ��ģ��
	emErrSubModNvApi_ErrCode,                  ///< nverrcode��������ҵ��ģ��
};

//////////////////////////////////////////////////////////// BaseSdk ////////////////////////////////////////////////////////////////////////////////////
/** nvapi֮nvbasesdk��ҵ��ģ������붨�� */
enum EM_NVAPI_BS
{   
	ERR_NVAPI_BS_NO_INITIALIZE = 1,                         ///< BASESDKδ��ʼ��
	ERR_NVAPI_BS_EXISTED_SESSION,                           ///< �Ѿ����ڵ�SessionID
	ERR_NVAPI_BS_NO_AVAILABLE_SESSION,                      ///< û�п��õĻỰ��
	ERR_NVAPI_BS_ALREADY_CONNECTED,                         ///< �Ѿ�����
	ERR_NVAPI_BS_CONNECT_FAILED,                            ///< ����ʧ�ܣ��Զ˲��ɴ�
	ERR_NVAPI_BS_NO_CONNECT,                                ///< ��δ����
	ERR_NVAPI_BS_LOGINMSG_ENCODING_FAILED,                  ///< ��¼��Ϣ����ʧ��
	ERR_NVAPI_BS_LOGINMSG_SENDING_FAILED,                   ///< ��¼��Ϣ����ʧ��
	ERR_NVAPI_BS_DISPMSG_ENCODING_FAILED,                   ///< ���͸�Dispatch��Ϣ����ʧ��
	ERR_NVAPI_BS_DISPMSG_SENDING_FAILED,                    ///< ���͸�Dispatch��Ϣ����ʧ��
	ERR_NVAPI_BS_USER_LOGININFO_INCORRECT,                  ///< ���͸�Dispatch��Ϣ����ʧ��
	ERR_NVAPI_BS_PARAM_NULL_POINTER,                        ///< ������ָ���쳣
	ERR_NVAPI_BS_CREATE_CONNECT_FAILED,                     ///< ��������ʧ��
	ERR_NVAPI_BS_CREATE_CONNECT_OBJ_FAILED,                 ///< �����������Ӷ���ʧ��
}; 

//////////////////////////////////////////////////////////// VideoConf///////////////////////////////////////////////////////////////////////////////////
/** nvapi֮confctrl��ҵ��ģ������붨�� */
enum EM_NVAPI_VC
{   
	ERR_NVAPI_VC_NO_INITIALIZE = 1,                         ///< VideoConfSDKδ��ʼ��
	ERR_NVAPI_VC_INVALID_E164,                              ///< �����õ�E164����
	ERR_NVAPI_VC_PARAM_NULL_POINTER,                        ///< ������ָ���쳣
	ERR_NVAPI_VC_MEMORY_NOT_ENOUGH,                         ///< �ռ䲻��
	ERR_NVAPI_VC_IDX_OUTOFRANG,                             ///< Խ������

};

//////////////////////////////////////////////////////////// VideoConf///////////////////////////////////////////////////////////////////////////////////
/** nvapi֮diagnose��ҵ��ģ������붨�� */
enum EM_NVAPI_DIAGNOSE
{   
	ERR_NVAPI_DIAGNOSE_NO_INITIALIZE = 1,                         ///< DiagnoseSDKδ��ʼ��
	ERR_NVAPI_DIAGNOSE_PARAM_NULL_POINTER,                        ///< ������ָ���쳣
	ERR_NVAPI_DIAGNOSE_MEMORY_NOT_ENOUGH,                         ///< �ռ䲻��
	ERR_NVAPI_DIAGNOSE_IDX_OUTOFRANG,                             ///< Խ������

};



//////////////////////////////////////////////////////////// VNC ////////////////////////////////////////////////////////////////////////////////////////
/** nvapi֮VNC��ҵ��ģ������붨�� */
enum EM_NVAPI_VNC
{   
	ERR_NVAPI_VNC_NO_INITIALIZE = 1,                         ///< NVVNC���湲��SDKδ��ʼ��
	ERR_NVAPI_VNC_INVALID_IP,                                ///< �����õ��ն�IP
};

 

//////////////////////////////////////////////////////////// MeetingMgr //////////////////////////////////////////////////////////////////////////////////
/** nvapi֮MeetingMgr��ҵ��ģ������붨�� */
enum EM_NVAPI_MG
{   
	ERR_NVAPI_MG_NO_INITIALIZE = 1,                         ///< MeetingMgrSDKδ��ʼ��
	ERR_NVAPI_MG_LOGIN_FAILED,                              ///< ��ܵ�¼ʧ��
};


////////////////////////////////////////////////////////////     IM    //////////////////////////////////////////////////////////////////////////////////
/** nvapi֮IM��ҵ��ģ������붨�� */
enum EM_NVAPI_IM
{   
	ERR_NVAPI_IM_NO_INITIALIZE = 1,                         ///< IMSDKδ��ʼ��
	ERR_NVAPI_IM_LOGIN_FAILED,                              ///< IM��¼ʧ��
};


////////////////////////////////////////////////////////////  DataConf //////////////////////////////////////////////////////////////////////////////////
/** nvapi֮DataConf��ҵ��ģ������붨�� */
enum EM_NVAPI_DC
{   
	ERR_NVAPI_DC_NO_INITIALIZE = 1,                        ///< DataConfSDKδ��ʼ��
	ERR_NVAPI_DC_LOGIN_FAILED,                             ///< ���ݹ����¼ʧ��
};


////////////////////////////////////////////////////////////  ContactMgr /////////////////////////////////////////////////////////////////////////////////
/** nvapi֮ContactMgr��ҵ��ģ������붨�� */
enum EM_NVAPI_CM
{   
	ERR_NVAPI_CM_NO_INITIALIZE = 1,                        ///< ContactMgrSDKδ��ʼ��
	ERR_NVAPI_CM_SERVER_DISCONNECT,                        ///< �ƶ���ϵ�˷������Ͽ�
};



////////////////////////////////////////////////////////////  ErrCode //////////////////////////////////////////////////////////////////////////////////
/** nvapi֮nverrcode��������ҵ��ģ�� */
enum EM_NVAPI_ERRCODE
{   
	ERR_NVAPI_ERRCODE_XMLFILENAME_ISEMPTY = 1,               ///< ָ�����ļ���Ϊ��
	ERR_NVAPI_ERRCODE_XMLFILE_ISNOT_EXIST,                   ///< ָ�����ļ�������
	ERR_NVAPI_ERRCODE_CREATE_XMLDOC_FAILED,                  ///< ����XML Doc Parse����ʧ��
	ERR_NVAPI_ERRCODE_CREATE_XMLDOC_EXCEPTION,               ///< ����XML Doc Parse����ʧ��
	ERR_NVAPI_ERRCODE_LOAD_XMLDOC_FAILED,                    ///< Xml Doc Parse����ָ����XMLʧ��
	ERR_NVAPI_ERRCODE_SAVE_ERRDESCBUF_NOT_ENOUGH,            ///< �洢������������Ϣ��buf����
	ERR_NVAPI_ERRCODE_NOT_CREATE_XMLDOC_PARSE,               ///< ���ܻ�ȡ����������Ϣ��δ����XMLDoc��������
	ERR_NVAPI_ERRCODE_NOT_EXIST,                             ///< �����ڵĴ�����
	ERR_NVAPI_ERRCODE_GET_ERRDESC_FAILED,                    ///< ��ȡ������������Ϣʧ��
	ERR_NVAPI_ERRCODE_XMLNODE_NOT_EXIST,                     ///< �����������ļ�XMLȱ�ٽڵ�
};

/////////////////////////////////////////////////END DEFINE/////////////////////////////////////////////////

#endif // _NVERRORCODE_NVAPI_H_
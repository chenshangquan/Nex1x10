/**===========================================================================
 * @file    $Id$
 * @brief   ����NVVODҵ��ģ��Ĵ����붨��
 * @author  $Author$
 * @date    $Date $
 * @version  $Revision$
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note
============================================================================*/

#ifndef _NVERRORCODE_NVVOD_H_
#define _NVERRORCODE_NVVOD_H_
#include "kdvtype.h"

/////////////////////////////////////////////////BEGIN DEFINE/////////////////////////////////////////////////

/**
 *@brief ���������(10���Ʊ�ʾ)
 *	 99                   99                    9             9999
 *	ģ��        +      ��ҵ�����      +     ����ȼ�    +   ��������
 *(2λ/100��)        ��2λ/100����          ��1λ/10����     (4λ/10000��)
 */

/** NVVODҵ��ģ�����ҵ��ģ��ID����, ������ҵ����ඨ��ֻ������׷�� */
enum EM_ERR_SUBMOD_NVVOD
{
    emErrSubModNvVod_Base = 0,              ///< nvvod������ҵ��ģ��
};

//////////////////////////////////////////////////////////// Base //////////////////////////////////////////////////////////////////////////////////////
/** nvvodҵ��ģ����������붨�� */
enum EmNvVodErrorId
{
	ERR_NVVODBASE_POINT_NULL = 1,            //ָ��ΪNULL
	ERR_NVVODBASE_STATE_ERROR,               //״̬����
	ERR_NVVODBASE_ALLOWMEM_FAILED,           //�ڴ����ʧ��
	ERR_NVVODBASE_RTSPCLIENTID_INVALID,      //rtspclientID����Ч
	ERR_NVVODBASE_PARSEURL_FAILED,           //����URLʧ��
	ERR_NVVODBASE_CONNSEVER_FAILED,          //���ӷ�����ʧ��
	ERR_NVVODBASE_CLIENTPORT_INVALID,        //�ͻ��˶˿ں���Ч
	ERR_NVVODBASE_SESSIONID_INVALID,         //sessionID��Ч
	ERR_NVVODBASE_SEND_FAILED,               //����ʧ��
	ERR_NVVODBASE_CREATEPROCESS_FAILED,      //�����߳�ʧ��
	ERR_NVVODBASE_NO_MEMORY,                 //�����ڴ�ʧ�ܣ����ڴ�
    ERR_NVVODBASE_PARAM_INVALID,	         //�����Ƿ�
    ERR_NVVODBASE_STREAMNUM_INVALID,         //����Ų���
    ERR_NVVODBASE_ALLOCCODECNETINFO_FAILED,  //��������������Ϣʧ��
    ERR_NVVODBASE_VOD_NOT_EXIST,             //��Ӧ��VODԴ������
    ERR_NVVODBASE_STREAM_NOT_EXIST,          //��Ӧ��StreamԴ������
	ERR_NVVODBASE_LIVEBROADCAST_HAVENOT_FUN, //ֱ���������@������
	ERR_NVVODBASE_INCONF,                    //���ڻ�����
    ERR_NVVODBASE_HTTP = 99,	             //http����
    ERR_NVVODBASE_CONTINUE,                  //"100" ; Continue
    ERR_NVVODBASE_CREATED ,                  //"201" ; Created
    ERR_NVVODBASE_LOWSPACE,                  //"250" ; Low on Storage Space
    ERR_NVVODBASE_MULTCHOICES,               //"300" ; Multiple Choices
    ERR_NVVODBASE_MOVEDPER,                  //"301" ; Moved Permanently
    ERR_NVVODBASE_MOVEDTEMP,                 //"302" ; Moved Temporarily
    ERR_NVVODBASE_SEEOTHER,                  //"303" ; See Other
    ERR_NVVODBASE_NOTMOD,                    //"304" ; Not Modified
    ERR_NVVODBASE_USERPROXY,                 //"305" ; Use Proxy
    ERR_NVVODBASE_BADREQUEST,                //"400" ; Bad Request
    ERR_NVVODBASE_UNAUTHORIZED,              //"401" ; Unauthorized
    ERR_NVVODBASE_PAYMENTREQ,                //"402" ; Payment Required
    ERR_NVVODBASE_FORBIDDEN,                 //"403" ; Forbidden
    ERR_NVVODBASE_NOTFIND,                   //"404" ; Not Found
    ERR_NVVODBASE_METHODNOTALLOWED,          //"405" ; Method Not Allowed
    ERR_NVVODBASE_NOTACCEPT,                 //"406" ; Not Acceptable
    ERR_NVVODBASE_PROXYAUTHREQ,              //"407" ; Proxy Authentication Required
    ERR_NVVODBASE_REQTIMEOUT,                //"408" ; Request Time-out
    ERR_NVVODBASE_GONE,                      //"410" ; Gone
    ERR_NVVODBASE_LENGTHREQ,                 //"411" ; Length Required
    ERR_NVVODBASE_PRECONDITIONFAILED,        //"412" ; Precondition Failed
    ERR_NVVODBASE_REQENTITYTOOLARGE,         //"413" ; Request Entity Too Large
    ERR_NVVODBASE_REQURITOOLARGE,            //"414" ; Request-URI Too Large
    ERR_NVVODBASE_UNSURPORTEDMEDIATYPE,      //"415" ; Unsupported Media Type
    ERR_NVVODBASE_PARAMETERNOTUNDER,         //"451" ; Parameter Not Understood
    ERR_NVVODBASE_CONFERENCENOTFIND,         //"452" ; Conference Not Found
    ERR_NVVODBASE_NOTENOUGH_BANDWIDTH,       //"453" ; Not Enough Bandwidth
    ERR_NVVODBASE_SESSION_NOTFIND,           //"454" ; Session Not Found
    ERR_NVVODBASE_METHOD_NOTVALID,           //"455" ; Method Not Valid in This State
    ERR_NVVODBASE_HF_NOTVALID,               //"456" ; Header Field Not Valid for Resource
    ERR_NVVODBASE_INVALIDRANGE,              //"457" ; Invalid Range
    ERR_NVVODBASE_PARAM_ISREADONLY,          //"458" ; Parameter Is Read-Only
    ERR_NVVODBASE_AO_NOTALLOWED,             //"459" ; Aggregate operation not allowed
    ERR_NVVODBASE_ONLYAO_ALLOWED,            //"460" ; Only aggregate operation allowed
    ERR_NVVODBASE_UNSURP_TRANSPORT,          //"461" ; Unsupported transport
    ERR_NVVODBASE_DEST_UNREACH,              //"462" ; Destination unreachable
    ERR_NVVODBASE_INTERNAL_SERROR,           //"500" ; Internal Server Error
    ERR_NVVODBASE_NOT_IMPLEMENTED,           //"501" ; Not Implemented
    ERR_NVVODBASE_BAD_GATEWAY,               //"502" ; Bad Gateway
    ERR_NVVODBASE_SERVICE_UNAVAILABLE,       //"503" ; Service Unavailable
    ERR_NVVODBASE_GATEWAY_TIMEOUT,           //"504" ; Gateway Time-out
    ERR_NVVODBASE_RTSPVERSION_NOTSUP,        //"505" ; RTSP Version not supported
    ERR_NVVODBASE_OPTION,                    //"551" ; Option
};

/////////////////////////////////////////////////END DEFINE/////////////////////////////////////////////////

#endif // _NVERRORCODE_NVVOD_H_
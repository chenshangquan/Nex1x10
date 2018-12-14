/**===========================================================================
 * @file    $Id$
 * @brief   ����MTVODҵ��ģ��Ĵ����붨��
 * @author  $Author$
 * @date    $Date $
 * @version  $Revision$
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note
============================================================================*/

#ifndef _MTERRORCODE_MTVOD_H_
#define _MTERRORCODE_MTVOD_H_
#include "kdvtype.h"

/////////////////////////////////////////////////BEGIN DEFINE/////////////////////////////////////////////////

/**
 *@brief ���������(10���Ʊ�ʾ)
 *	 99                   99                    9             9999
 *	ģ��        +      ��ҵ�����      +     ����ȼ�    +   ��������
 *(2λ/100��)        ��2λ/100����          ��1λ/10����     (4λ/10000��)
 */

/** MTVODҵ��ģ�����ҵ��ģ��ID����, ������ҵ����ඨ��ֻ������׷�� */
enum EM_ERR_SUBMOD_MTVOD
{
    emErrSubModMtVod_Base = 0,              ///< mtvod������ҵ��ģ��
};

//////////////////////////////////////////////////////////// Base //////////////////////////////////////////////////////////////////////////////////////
/** mtvodҵ��ģ����������붨�� */
enum EmMtVodErrorId
{
	ERR_MTVODBASE_POINT_NULL = 1,            //ָ��ΪNULL
	ERR_MTVODBASE_STATE_ERROR,               //״̬����
	ERR_MTVODBASE_ALLOWMEM_FAILED,           //�ڴ����ʧ��
	ERR_MTVODBASE_RTSPCLIENTID_INVALID,      //rtspclientID����Ч
	ERR_MTVODBASE_PARSEURL_FAILED,           //����URLʧ��
	ERR_MTVODBASE_CONNSEVER_FAILED,          //���ӷ�����ʧ��
	ERR_MTVODBASE_CLIENTPORT_INVALID,        //�ͻ��˶˿ں���Ч
	ERR_MTVODBASE_SESSIONID_INVALID,         //sessionID��Ч
	ERR_MTVODBASE_SEND_FAILED,               //����ʧ��
	ERR_MTVODBASE_CREATEPROCESS_FAILED,      //�����߳�ʧ��
	ERR_MTVODBASE_NO_MEMORY,                 //�����ڴ�ʧ�ܣ����ڴ�
    ERR_MTVODBASE_PARAM_INVALID,	         //�����Ƿ�
    ERR_MTVODBASE_STREAMNUM_INVALID,         //����Ų���
    ERR_MTVODBASE_ALLOCCODECNETINFO_FAILED,  //��������������Ϣʧ��
    ERR_MTVODBASE_VOD_NOT_EXIST,             //��Ӧ��VODԴ������
    ERR_MTVODBASE_STREAM_NOT_EXIST,          //��Ӧ��StreamԴ������
	ERR_MTVODBASE_LIVEBROADCAST_HAVENOT_FUN, //ֱ���������@������
	ERR_MTVODBASE_INCONF,                    //���ڻ�����
    ERR_MTVODBASE_HTTP = 99,	             //http����
    ERR_MTVODBASE_CONTINUE,                  //"100" ; Continue
    ERR_MTVODBASE_CREATED ,                  //"201" ; Created
    ERR_MTVODBASE_LOWSPACE,                  //"250" ; Low on Storage Space
    ERR_MTVODBASE_MULTCHOICES,               //"300" ; Multiple Choices
    ERR_MTVODBASE_MOVEDPER,                  //"301" ; Moved Permanently
    ERR_MTVODBASE_MOVEDTEMP,                 //"302" ; Moved Temporarily
    ERR_MTVODBASE_SEEOTHER,                  //"303" ; See Other
    ERR_MTVODBASE_NOTMOD,                    //"304" ; Not Modified
    ERR_MTVODBASE_USERPROXY,                 //"305" ; Use Proxy
    ERR_MTVODBASE_BADREQUEST,                //"400" ; Bad Request
    ERR_MTVODBASE_UNAUTHORIZED,              //"401" ; Unauthorized
    ERR_MTVODBASE_PAYMENTREQ,                //"402" ; Payment Required
    ERR_MTVODBASE_FORBIDDEN,                 //"403" ; Forbidden
    ERR_MTVODBASE_NOTFIND,                   //"404" ; Not Found
    ERR_MTVODBASE_METHODNOTALLOWED,          //"405" ; Method Not Allowed
    ERR_MTVODBASE_NOTACCEPT,                 //"406" ; Not Acceptable
    ERR_MTVODBASE_PROXYAUTHREQ,              //"407" ; Proxy Authentication Required
    ERR_MTVODBASE_REQTIMEOUT,                //"408" ; Request Time-out
    ERR_MTVODBASE_GONE,                      //"410" ; Gone
    ERR_MTVODBASE_LENGTHREQ,                 //"411" ; Length Required
    ERR_MTVODBASE_PRECONDITIONFAILED,        //"412" ; Precondition Failed
    ERR_MTVODBASE_REQENTITYTOOLARGE,         //"413" ; Request Entity Too Large
    ERR_MTVODBASE_REQURITOOLARGE,            //"414" ; Request-URI Too Large
    ERR_MTVODBASE_UNSURPORTEDMEDIATYPE,      //"415" ; Unsupported Media Type
    ERR_MTVODBASE_PARAMETERNOTUNDER,         //"451" ; Parameter Not Understood
    ERR_MTVODBASE_CONFERENCENOTFIND,         //"452" ; Conference Not Found
    ERR_MTVODBASE_NOTENOUGH_BANDWIDTH,       //"453" ; Not Enough Bandwidth
    ERR_MTVODBASE_SESSION_NOTFIND,           //"454" ; Session Not Found
    ERR_MTVODBASE_METHOD_NOTVALID,           //"455" ; Method Not Valid in This State
    ERR_MTVODBASE_HF_NOTVALID,               //"456" ; Header Field Not Valid for Resource
    ERR_MTVODBASE_INVALIDRANGE,              //"457" ; Invalid Range
    ERR_MTVODBASE_PARAM_ISREADONLY,          //"458" ; Parameter Is Read-Only
    ERR_MTVODBASE_AO_NOTALLOWED,             //"459" ; Aggregate operation not allowed
    ERR_MTVODBASE_ONLYAO_ALLOWED,            //"460" ; Only aggregate operation allowed
    ERR_MTVODBASE_UNSURP_TRANSPORT,          //"461" ; Unsupported transport
    ERR_MTVODBASE_DEST_UNREACH,              //"462" ; Destination unreachable
    ERR_MTVODBASE_INTERNAL_SERROR,           //"500" ; Internal Server Error
    ERR_MTVODBASE_NOT_IMPLEMENTED,           //"501" ; Not Implemented
    ERR_MTVODBASE_BAD_GATEWAY,               //"502" ; Bad Gateway
    ERR_MTVODBASE_SERVICE_UNAVAILABLE,       //"503" ; Service Unavailable
    ERR_MTVODBASE_GATEWAY_TIMEOUT,           //"504" ; Gateway Time-out
    ERR_MTVODBASE_RTSPVERSION_NOTSUP,        //"505" ; RTSP Version not supported
    ERR_MTVODBASE_OPTION,                    //"551" ; Option
};

/////////////////////////////////////////////////END DEFINE/////////////////////////////////////////////////

#endif // _MTERRORCODE_MTVOD_H_
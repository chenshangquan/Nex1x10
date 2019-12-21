/**===========================================================================
 * @file    $Id$
 * @brief   负责NVVOD业务模块的错误码定义
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
 *@brief 错误码规则(10进制表示)
 *	 99                   99                    9             9999
 *	模块        +      子业务分类      +     错误等级    +   分配数量
 *(2位/100个)        （2位/100个）          （1位/10个）     (4位/10000个)
 */

/** NVVOD业务模块的子业务模块ID定义, 新增子业务分类定义只能往后追加 */
enum EM_ERR_SUBMOD_NVVOD
{
    emErrSubModNvVod_Base = 0,              ///< nvvod基础子业务模块
};

//////////////////////////////////////////////////////////// Base //////////////////////////////////////////////////////////////////////////////////////
/** nvvod业务模块基本错误码定义 */
enum EmNvVodErrorId
{
	ERR_NVVODBASE_POINT_NULL = 1,            //指针为NULL
	ERR_NVVODBASE_STATE_ERROR,               //状态错误
	ERR_NVVODBASE_ALLOWMEM_FAILED,           //内存分配失败
	ERR_NVVODBASE_RTSPCLIENTID_INVALID,      //rtspclientID号无效
	ERR_NVVODBASE_PARSEURL_FAILED,           //解析URL失败
	ERR_NVVODBASE_CONNSEVER_FAILED,          //连接服务器失败
	ERR_NVVODBASE_CLIENTPORT_INVALID,        //客户端端口号无效
	ERR_NVVODBASE_SESSIONID_INVALID,         //sessionID无效
	ERR_NVVODBASE_SEND_FAILED,               //发送失败
	ERR_NVVODBASE_CREATEPROCESS_FAILED,      //创建线程失败
	ERR_NVVODBASE_NO_MEMORY,                 //分配内存失败，无内存
    ERR_NVVODBASE_PARAM_INVALID,	         //参数非法
    ERR_NVVODBASE_STREAMNUM_INVALID,         //流序号不对
    ERR_NVVODBASE_ALLOCCODECNETINFO_FAILED,  //分配编解码网络信息失败
    ERR_NVVODBASE_VOD_NOT_EXIST,             //对应的VOD源不存在
    ERR_NVVODBASE_STREAM_NOT_EXIST,          //对应的Stream源不存在
	ERR_NVVODBASE_LIVEBROADCAST_HAVENOT_FUN, //直播不存在這個功能
	ERR_NVVODBASE_INCONF,                    //正在会议中
    ERR_NVVODBASE_HTTP = 99,	             //http错误
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
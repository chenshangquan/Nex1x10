/**===========================================================================
 * @file    $Id$
 * @brief   负责MTAPI业务模块的错误码定义
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
 *@brief 错误码规则(10进制表示)
 *	 99                   99                    9             9999
 *	模块        +      子业务分类      +     错误等级    +   分配数量
 *(2位/100个)        （2位/100个）          （1位/10个）     (4位/10000个)
 */

/** MTAPI业务模块的子业务模块ID定义, 新增子业务分类定义只能往后追加 */
enum EM_ERR_SUBMOD_MTAPI
{
    emErrSubModMtApi_BaseSdk = 1,              ///< mtbasesdk子业务模块
    emErrSubModMtApi_VideoConf,                ///< mtvideoconfsdk子业务模块
	emErrSubModMtApi_Vnc,                      ///< mtvncsdk子业务模块
	emErrSubModMtApi_MeetingMgr,               ///< mtmeetingmgrsdk子业务模块
	emErrSubModMtApi_IM,                       ///< mtimsdk子业务模块
	emErrSubModMtApi_DataConf,                 ///< mtdataconfsdk子业务模块
	emErrSubModMtApi_ContactMgr,               ///< mtContactMgrsdk子业务模块
	emErrSubModMtApi_Diagnose,                 ///< mtDiagnose子业务模块
	emErrSubModMtApi_ErrCode,                  ///< mterrcode错误码子业务模块
	emErrSubModMtApi_Dcs,					   ///< mtdcs电子白板子业务模块
};

//////////////////////////////////////////////////////////// BaseSdk ////////////////////////////////////////////////////////////////////////////////////
/** mtapi之mtbasesdk子业务模块错误码定义 */
enum EM_MTAPI_BS
{   
	ERR_MTAPI_BS_NO_INITIALIZE = 1,                         ///< BASESDK未初始化
	ERR_MTAPI_BS_EXISTED_SESSION,                           ///< 已经存在的SessionID
	ERR_MTAPI_BS_NO_AVAILABLE_SESSION,                      ///< 没有可用的会话了
	ERR_MTAPI_BS_ALREADY_CONNECTED,                         ///< 已经连接
	ERR_MTAPI_BS_CONNECT_FAILED,                            ///< 连接失败，对端不可达
	ERR_MTAPI_BS_NO_CONNECT,                                ///< 尚未连接
	ERR_MTAPI_BS_LOGINMSG_ENCODING_FAILED,                  ///< 登录消息编码失败
	ERR_MTAPI_BS_LOGINMSG_SENDING_FAILED,                   ///< 登录消息发送失败
	ERR_MTAPI_BS_DISPMSG_ENCODING_FAILED,                   ///< 发送给Dispatch消息编码失败
	ERR_MTAPI_BS_DISPMSG_SENDING_FAILED,                    ///< 发送给Dispatch消息发送失败
	ERR_MTAPI_BS_USER_LOGININFO_INCORRECT,                  ///< 发送给Dispatch消息发送失败
	ERR_MTAPI_BS_PARAM_NULL_POINTER,                        ///< 参数空指针异常
	ERR_MTAPI_BS_CREATE_CONNECT_FAILED,                     ///< 网络连接失败
	ERR_MTAPI_BS_CREATE_CONNECT_OBJ_FAILED,                 ///< 创建网络连接对象失败
}; 

//////////////////////////////////////////////////////////// VideoConf///////////////////////////////////////////////////////////////////////////////////
/** mtapi之confctrl子业务模块错误码定义 */
enum EM_MTAPI_VC
{   
	ERR_MTAPI_VC_NO_INITIALIZE = 1,                         ///< VideoConfSDK未初始化
	ERR_MTAPI_VC_INVALID_E164,                              ///< 不可用的E164号码
	ERR_MTAPI_VC_PARAM_NULL_POINTER,                        ///< 参数空指针异常
	ERR_MTAPI_VC_MEMORY_NOT_ENOUGH,                         ///< 空间不足
	ERR_MTAPI_VC_IDX_OUTOFRANG,                             ///< 越界请求

};

//////////////////////////////////////////////////////////// VideoConf///////////////////////////////////////////////////////////////////////////////////
/** mtapi之diagnose子业务模块错误码定义 */
enum EM_MTAPI_DIAGNOSE
{   
	ERR_MTAPI_DIAGNOSE_NO_INITIALIZE = 1,                         ///< DiagnoseSDK未初始化
	ERR_MTAPI_DIAGNOSE_PARAM_NULL_POINTER,                        ///< 参数空指针异常
	ERR_MTAPI_DIAGNOSE_MEMORY_NOT_ENOUGH,                         ///< 空间不足
	ERR_MTAPI_DIAGNOSE_IDX_OUTOFRANG,                             ///< 越界请求

};



//////////////////////////////////////////////////////////// VNC ////////////////////////////////////////////////////////////////////////////////////////
/** mtapi之VNC子业务模块错误码定义 */
enum EM_MTAPI_VNC
{   
	ERR_MTAPI_VNC_NO_INITIALIZE = 1,                         ///< MTVNC桌面共享SDK未初始化
	ERR_MTAPI_VNC_INVALID_IP,                                ///< 不可用的终端IP
};

 

//////////////////////////////////////////////////////////// MeetingMgr //////////////////////////////////////////////////////////////////////////////////
/** mtapi之MeetingMgr子业务模块错误码定义 */
enum EM_MTAPI_MG
{   
	ERR_MTAPI_MG_NO_INITIALIZE = 1,                         ///< MeetingMgrSDK未初始化
	ERR_MTAPI_MG_LOGIN_FAILED,                              ///< 会管登录失败
};


////////////////////////////////////////////////////////////     IM    //////////////////////////////////////////////////////////////////////////////////
/** mtapi之IM子业务模块错误码定义 */
enum EM_MTAPI_IM
{   
	ERR_MTAPI_IM_NO_INITIALIZE = 1,                         ///< IMSDK未初始化
	ERR_MTAPI_IM_LOGIN_FAILED,                              ///< IM登录失败
};


////////////////////////////////////////////////////////////  DataConf //////////////////////////////////////////////////////////////////////////////////
/** mtapi之DataConf子业务模块错误码定义 */
enum EM_MTAPI_DC
{   
	ERR_MTAPI_DC_NO_INITIALIZE = 1,                        ///< DataConfSDK未初始化
	ERR_MTAPI_DC_LOGIN_FAILED,                             ///< 数据共享登录失败
};


////////////////////////////////////////////////////////////  ContactMgr /////////////////////////////////////////////////////////////////////////////////
/** mtapi之ContactMgr子业务模块错误码定义 */
enum EM_MTAPI_CM
{   
	ERR_MTAPI_CM_NO_INITIALIZE = 1,                        ///< ContactMgrSDK未初始化
	ERR_MTAPI_CM_SERVER_DISCONNECT,                        ///< 云端联系人服务器断开
};



////////////////////////////////////////////////////////////  ErrCode //////////////////////////////////////////////////////////////////////////////////
/** mtapi之mterrcode错误码子业务模块 */
enum EM_MTAPI_ERRCODE
{   
	ERR_MTAPI_ERRCODE_XMLFILENAME_ISEMPTY = 1,               ///< 指定的文件名为空
	ERR_MTAPI_ERRCODE_XMLFILE_ISNOT_EXIST,                   ///< 指定的文件不存在
	ERR_MTAPI_ERRCODE_CREATE_XMLDOC_FAILED,                  ///< 创建XML Doc Parse对象失败
	ERR_MTAPI_ERRCODE_CREATE_XMLDOC_EXCEPTION,               ///< 创建XML Doc Parse对象失败
	ERR_MTAPI_ERRCODE_LOAD_XMLDOC_FAILED,                    ///< Xml Doc Parse加载指定的XML失败
	ERR_MTAPI_ERRCODE_SAVE_ERRDESCBUF_NOT_ENOUGH,            ///< 存储错误码描述信息的buf不足
	ERR_MTAPI_ERRCODE_NOT_CREATE_XMLDOC_PARSE,               ///< 不能获取错误描述信息，未创建XMLDoc分析对象
	ERR_MTAPI_ERRCODE_NOT_EXIST,                             ///< 不存在的错误码
	ERR_MTAPI_ERRCODE_GET_ERRDESC_FAILED,                    ///< 获取错误码描述信息失败
	ERR_MTAPI_ERRCODE_XMLNODE_NOT_EXIST,                     ///< 错误码描述文件XML缺少节点
};

////////////////////////////////////////////////////////////     DCS    //////////////////////////////////////////////////////////////////////////////////
/** mtapi之DCS子业务模块错误码定义 */
enum EM_MTAPI_DCS
{   
	ERR_MTAPI_DCS_NO_INITIALIZE = 1,                         ///< DCSSDK未初始化
	ERR_MTAPI_DCS_LOGIN_FAILED,                              ///< DCS登录失败
};

/////////////////////////////////////////////////END DEFINE/////////////////////////////////////////////////

#endif // _MTERRORCODE_MTAPI_H_
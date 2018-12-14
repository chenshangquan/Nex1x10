/**===========================================================================
 * @file    $Id$
 * @brief   负责NVAPI业务模块的错误码定义
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
 *@brief 错误码规则(10进制表示)
 *	 99                   99                    9             9999
 *	模块        +      子业务分类      +     错误等级    +   分配数量
 *(2位/100个)        （2位/100个）          （1位/10个）     (4位/10000个)
 */

/** NVAPI业务模块的子业务模块ID定义, 新增子业务分类定义只能往后追加 */
enum EM_ERR_SUBMOD_NVAPI
{
    emErrSubModNvApi_BaseSdk = 1,              ///< nvbasesdk子业务模块
    emErrSubModNvApi_VideoConf,                ///< nvvideoconfsdk子业务模块
	emErrSubModNvApi_Vnc,                      ///< nvvncsdk子业务模块
	emErrSubModNvApi_MeetingMgr,               ///< nvmeetingmgrsdk子业务模块
	emErrSubModNvApi_IM,                       ///< nvimsdk子业务模块
	emErrSubModNvApi_DataConf,                 ///< nvdataconfsdk子业务模块
	emErrSubModNvApi_ContactMgr,               ///< nvContactMgrsdk子业务模块
	emErrSubModNvApi_Diagnose,                 ///< nvDiagnose子业务模块
	emErrSubModNvApi_ErrCode,                  ///< nverrcode错误码子业务模块
};

//////////////////////////////////////////////////////////// BaseSdk ////////////////////////////////////////////////////////////////////////////////////
/** nvapi之nvbasesdk子业务模块错误码定义 */
enum EM_NVAPI_BS
{   
	ERR_NVAPI_BS_NO_INITIALIZE = 1,                         ///< BASESDK未初始化
	ERR_NVAPI_BS_EXISTED_SESSION,                           ///< 已经存在的SessionID
	ERR_NVAPI_BS_NO_AVAILABLE_SESSION,                      ///< 没有可用的会话了
	ERR_NVAPI_BS_ALREADY_CONNECTED,                         ///< 已经连接
	ERR_NVAPI_BS_CONNECT_FAILED,                            ///< 连接失败，对端不可达
	ERR_NVAPI_BS_NO_CONNECT,                                ///< 尚未连接
	ERR_NVAPI_BS_LOGINMSG_ENCODING_FAILED,                  ///< 登录消息编码失败
	ERR_NVAPI_BS_LOGINMSG_SENDING_FAILED,                   ///< 登录消息发送失败
	ERR_NVAPI_BS_DISPMSG_ENCODING_FAILED,                   ///< 发送给Dispatch消息编码失败
	ERR_NVAPI_BS_DISPMSG_SENDING_FAILED,                    ///< 发送给Dispatch消息发送失败
	ERR_NVAPI_BS_USER_LOGININFO_INCORRECT,                  ///< 发送给Dispatch消息发送失败
	ERR_NVAPI_BS_PARAM_NULL_POINTER,                        ///< 参数空指针异常
	ERR_NVAPI_BS_CREATE_CONNECT_FAILED,                     ///< 网络连接失败
	ERR_NVAPI_BS_CREATE_CONNECT_OBJ_FAILED,                 ///< 创建网络连接对象失败
}; 

//////////////////////////////////////////////////////////// VideoConf///////////////////////////////////////////////////////////////////////////////////
/** nvapi之confctrl子业务模块错误码定义 */
enum EM_NVAPI_VC
{   
	ERR_NVAPI_VC_NO_INITIALIZE = 1,                         ///< VideoConfSDK未初始化
	ERR_NVAPI_VC_INVALID_E164,                              ///< 不可用的E164号码
	ERR_NVAPI_VC_PARAM_NULL_POINTER,                        ///< 参数空指针异常
	ERR_NVAPI_VC_MEMORY_NOT_ENOUGH,                         ///< 空间不足
	ERR_NVAPI_VC_IDX_OUTOFRANG,                             ///< 越界请求

};

//////////////////////////////////////////////////////////// VideoConf///////////////////////////////////////////////////////////////////////////////////
/** nvapi之diagnose子业务模块错误码定义 */
enum EM_NVAPI_DIAGNOSE
{   
	ERR_NVAPI_DIAGNOSE_NO_INITIALIZE = 1,                         ///< DiagnoseSDK未初始化
	ERR_NVAPI_DIAGNOSE_PARAM_NULL_POINTER,                        ///< 参数空指针异常
	ERR_NVAPI_DIAGNOSE_MEMORY_NOT_ENOUGH,                         ///< 空间不足
	ERR_NVAPI_DIAGNOSE_IDX_OUTOFRANG,                             ///< 越界请求

};



//////////////////////////////////////////////////////////// VNC ////////////////////////////////////////////////////////////////////////////////////////
/** nvapi之VNC子业务模块错误码定义 */
enum EM_NVAPI_VNC
{   
	ERR_NVAPI_VNC_NO_INITIALIZE = 1,                         ///< NVVNC桌面共享SDK未初始化
	ERR_NVAPI_VNC_INVALID_IP,                                ///< 不可用的终端IP
};

 

//////////////////////////////////////////////////////////// MeetingMgr //////////////////////////////////////////////////////////////////////////////////
/** nvapi之MeetingMgr子业务模块错误码定义 */
enum EM_NVAPI_MG
{   
	ERR_NVAPI_MG_NO_INITIALIZE = 1,                         ///< MeetingMgrSDK未初始化
	ERR_NVAPI_MG_LOGIN_FAILED,                              ///< 会管登录失败
};


////////////////////////////////////////////////////////////     IM    //////////////////////////////////////////////////////////////////////////////////
/** nvapi之IM子业务模块错误码定义 */
enum EM_NVAPI_IM
{   
	ERR_NVAPI_IM_NO_INITIALIZE = 1,                         ///< IMSDK未初始化
	ERR_NVAPI_IM_LOGIN_FAILED,                              ///< IM登录失败
};


////////////////////////////////////////////////////////////  DataConf //////////////////////////////////////////////////////////////////////////////////
/** nvapi之DataConf子业务模块错误码定义 */
enum EM_NVAPI_DC
{   
	ERR_NVAPI_DC_NO_INITIALIZE = 1,                        ///< DataConfSDK未初始化
	ERR_NVAPI_DC_LOGIN_FAILED,                             ///< 数据共享登录失败
};


////////////////////////////////////////////////////////////  ContactMgr /////////////////////////////////////////////////////////////////////////////////
/** nvapi之ContactMgr子业务模块错误码定义 */
enum EM_NVAPI_CM
{   
	ERR_NVAPI_CM_NO_INITIALIZE = 1,                        ///< ContactMgrSDK未初始化
	ERR_NVAPI_CM_SERVER_DISCONNECT,                        ///< 云端联系人服务器断开
};



////////////////////////////////////////////////////////////  ErrCode //////////////////////////////////////////////////////////////////////////////////
/** nvapi之nverrcode错误码子业务模块 */
enum EM_NVAPI_ERRCODE
{   
	ERR_NVAPI_ERRCODE_XMLFILENAME_ISEMPTY = 1,               ///< 指定的文件名为空
	ERR_NVAPI_ERRCODE_XMLFILE_ISNOT_EXIST,                   ///< 指定的文件不存在
	ERR_NVAPI_ERRCODE_CREATE_XMLDOC_FAILED,                  ///< 创建XML Doc Parse对象失败
	ERR_NVAPI_ERRCODE_CREATE_XMLDOC_EXCEPTION,               ///< 创建XML Doc Parse对象失败
	ERR_NVAPI_ERRCODE_LOAD_XMLDOC_FAILED,                    ///< Xml Doc Parse加载指定的XML失败
	ERR_NVAPI_ERRCODE_SAVE_ERRDESCBUF_NOT_ENOUGH,            ///< 存储错误码描述信息的buf不足
	ERR_NVAPI_ERRCODE_NOT_CREATE_XMLDOC_PARSE,               ///< 不能获取错误描述信息，未创建XMLDoc分析对象
	ERR_NVAPI_ERRCODE_NOT_EXIST,                             ///< 不存在的错误码
	ERR_NVAPI_ERRCODE_GET_ERRDESC_FAILED,                    ///< 获取错误码描述信息失败
	ERR_NVAPI_ERRCODE_XMLNODE_NOT_EXIST,                     ///< 错误码描述文件XML缺少节点
};

/////////////////////////////////////////////////END DEFINE/////////////////////////////////////////////////

#endif // _NVERRORCODE_NVAPI_H_
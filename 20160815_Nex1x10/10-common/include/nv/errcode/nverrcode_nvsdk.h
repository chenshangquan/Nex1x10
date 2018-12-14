/**===========================================================================
 * @file    $Id$
 * @brief   负责NVSDK业务模块的错误码定义
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
 *@brief 错误码规则(10进制表示)
 *	 99                   99                    9             9999
 *	模块        +      子业务分类      +     错误等级    +   分配数量
 *(2位/100个)        （2位/100个）          （1位/10个）     (4位/10000个)
 */

/** NVSDK业务模块的子业务模块ID定义, 新增子业务分类定义只能往后追加 */
enum EM_ERR_SUBMOD_NVSDK
{
    emErrSubModNvSdk_BaseSdk = 0,              ///< nvbasesdk子业务模块
    emErrSubModNvSdk_ConfCtrl,                 ///< nvconfctrlsdk子业务模块
	emErrSubModNvSdk_Pcdv,                     ///< nvpcdvsdk子业务模块
	emErrSubModNvSdk_MediaCtrl,                ///< nvmediactrlsdk子业务模块
	emErrSubModNvSdk_MeetingMgr,               ///< nvmeetingmgrsdk子业务模块
	emErrSubModNvSdk_IM,                       ///< nvimsdk子业务模块
	emErrSubModNvSdk_DataConf,                 ///< nvdataconfsdk子业务模块
	emErrSubModNvSdk_CloudAddr,                ///< nvcloudaddrsdk子业务模块
	emErrSubModNvSdk_Diagnose,                 ///< nvdiagnosesdk子业务模块
};

//////////////////////////////////////////////////////////// BaseSdk //////////////////////////////////////////////////////////////////////////////////////
/** nvsdk之nvbasesdk子业务模块错误码定义 */
#define  ERR_NVSDK_BASESDK_NO_INITIALIZE                               (u32)1                                             ///< BASESDK未初始化
#define  ERR_NVSDK_BASESDK_NO_LOGIN                                    (u32)2                                             ///< 尚未登录到终端(C/S模式)


//////////////////////////////////////////////////////////// ConfCtrl ////////////////////////////////////////////////////////////////////////////////////
/** nvsdk之confctrl子业务模块错误码定义 */
#define  ERR_NVSDK_CONFCTRL_INVALID_E164                               (u32)1                                             ///< 不可用的E164号码



//////////////////////////////////////////////////////////// PCDV ////////////////////////////////////////////////////////////////////////////////////////
/** nvsdk之pcdv子业务模块错误码定义 */
#define  ERR_NVSDK_PCDV_INVALID_IP                                     (u32)1                                                  ///< 不可用的终端IP


//////////////////////////////////////////////////////////// MediaCtrl ///////////////////////////////////////////////////////////////////////////////////
/** nvsdk之MediaCtrl子业务模块错误码定义 */
#define  ERR_NVSDK_MEDIACTRL_CREATE_DECODER_FAILED                     (u32)1                                                  ///< 创建解码器失败


//////////////////////////////////////////////////////////// MeetingMgr //////////////////////////////////////////////////////////////////////////////////
/** nvsdk之MeetingMgr子业务模块错误码定义 */
#define  ERR_NVSDK_MEDIACTRL_CREATE_DECODER_FAILED                     (u32)1                                                  ///< 创建解码器失败



////////////////////////////////////////////////////////////     IM    //////////////////////////////////////////////////////////////////////////////////
/** nvsdk之IM子业务模块错误码定义 */
#define  ERR_NVSDK_IM_LOGIN_FAILED                                     (u32)1                                                  ///< IM登录失败



////////////////////////////////////////////////////////////  DataConf //////////////////////////////////////////////////////////////////////////////////
/** nvsdk之DataConf子业务模块错误码定义 */
#define  ERR_NVSDK_DATACONF_LOGIN_FAILED                               (u32)1                                                  ///< 数据共享登录失败



////////////////////////////////////////////////////////////  CloudAddr //////////////////////////////////////////////////////////////////////////////////
/** nvsdk之CloudAddr子业务模块错误码定义 */
#define  ERR_NVSDK_CLOUDEADDR_SERVER_DISCONNECT                         (u32)1                                                 ///< 云端联系人服务器断开


////////////////////////////////////////////////////////////  Diagnose //////////////////////////////////////////////////////////////////////////////////
/** nvsdk之Diagnose子业务模块错误码定义 */
#define  ERR_NVSDK_DIAGNOSE_NO_DATA                                     (u32)1                                                 ///< 无诊断数据




/////////////////////////////////////////////////END DEFINE/////////////////////////////////////////////////

#endif // _NVERRORCODE_NVSDK_H_
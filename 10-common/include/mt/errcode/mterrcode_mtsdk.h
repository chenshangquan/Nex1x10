/**===========================================================================
 * @file    $Id$
 * @brief   负责MTSDK业务模块的错误码定义
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
 *@brief 错误码规则(10进制表示)
 *	 99                   99                    9             9999
 *	模块        +      子业务分类      +     错误等级    +   分配数量
 *(2位/100个)        （2位/100个）          （1位/10个）     (4位/10000个)
 */

/** MTSDK业务模块的子业务模块ID定义, 新增子业务分类定义只能往后追加 */
enum EM_ERR_SUBMOD_MTSDK
{
    emErrSubModMtSdk_BaseSdk = 0,              ///< mtbasesdk子业务模块
    emErrSubModMtSdk_ConfCtrl,                 ///< mtconfctrlsdk子业务模块
	emErrSubModMtSdk_Pcdv,                     ///< mtpcdvsdk子业务模块
	emErrSubModMtSdk_MediaCtrl,                ///< mtmediactrlsdk子业务模块
	emErrSubModMtSdk_MeetingMgr,               ///< mtmeetingmgrsdk子业务模块
	emErrSubModMtSdk_IM,                       ///< mtimsdk子业务模块
	emErrSubModMtSdk_DataConf,                 ///< mtdataconfsdk子业务模块
	emErrSubModMtSdk_CloudAddr,                ///< mtcloudaddrsdk子业务模块
	emErrSubModMtSdk_Diagnose,                 ///< mtdiagnosesdk子业务模块
};

//////////////////////////////////////////////////////////// BaseSdk //////////////////////////////////////////////////////////////////////////////////////
/** mtsdk之mtbasesdk子业务模块错误码定义 */
#define  ERR_MTSDK_BASESDK_NO_INITIALIZE                               (u32)1                                             ///< BASESDK未初始化
#define  ERR_MTSDK_BASESDK_NO_LOGIN                                    (u32)2                                             ///< 尚未登录到终端(C/S模式)


//////////////////////////////////////////////////////////// ConfCtrl ////////////////////////////////////////////////////////////////////////////////////
/** mtsdk之confctrl子业务模块错误码定义 */
#define  ERR_MTSDK_CONFCTRL_INVALID_E164                               (u32)1                                             ///< 不可用的E164号码



//////////////////////////////////////////////////////////// PCDV ////////////////////////////////////////////////////////////////////////////////////////
/** mtsdk之pcdv子业务模块错误码定义 */
#define  ERR_MTSDK_PCDV_INVALID_IP                                     (u32)1                                                  ///< 不可用的终端IP


//////////////////////////////////////////////////////////// MediaCtrl ///////////////////////////////////////////////////////////////////////////////////
/** mtsdk之MediaCtrl子业务模块错误码定义 */
#define  ERR_MTSDK_MEDIACTRL_CREATE_DECODER_FAILED                     (u32)1                                                  ///< 创建解码器失败


//////////////////////////////////////////////////////////// MeetingMgr //////////////////////////////////////////////////////////////////////////////////
/** mtsdk之MeetingMgr子业务模块错误码定义 */
#define  ERR_MTSDK_MEDIACTRL_CREATE_DECODER_FAILED                     (u32)1                                                  ///< 创建解码器失败



////////////////////////////////////////////////////////////     IM    //////////////////////////////////////////////////////////////////////////////////
/** mtsdk之IM子业务模块错误码定义 */
#define  ERR_MTSDK_IM_LOGIN_FAILED                                     (u32)1                                                  ///< IM登录失败



////////////////////////////////////////////////////////////  DataConf //////////////////////////////////////////////////////////////////////////////////
/** mtsdk之DataConf子业务模块错误码定义 */
#define  ERR_MTSDK_DATACONF_LOGIN_FAILED                               (u32)1                                                  ///< 数据共享登录失败



////////////////////////////////////////////////////////////  CloudAddr //////////////////////////////////////////////////////////////////////////////////
/** mtsdk之CloudAddr子业务模块错误码定义 */
#define  ERR_MTSDK_CLOUDEADDR_SERVER_DISCONNECT                         (u32)1                                                 ///< 云端联系人服务器断开


////////////////////////////////////////////////////////////  Diagnose //////////////////////////////////////////////////////////////////////////////////
/** mtsdk之Diagnose子业务模块错误码定义 */
#define  ERR_MTSDK_DIAGNOSE_NO_DATA                                     (u32)1                                                 ///< 无诊断数据




/////////////////////////////////////////////////END DEFINE/////////////////////////////////////////////////

#endif // _MTERRORCODE_MTSDK_H_
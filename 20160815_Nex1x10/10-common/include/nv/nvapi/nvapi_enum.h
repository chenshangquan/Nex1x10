/*******************************************************************************//**
*@file          nvapi_enum.h
*@brief         提供nvapi所有的枚举定义
*
*@author        ruiyigen
*@version       5.0    
*@date          20150328
*@copyright     (c)1995-2015 Suzhou Keda Technology Co.,Ltd. All rights reserved
***********************************************************************************/
#ifndef _NVAPI_ENUM_H_
#define _NVAPI_ENUM_H_
/**@addtogroup common 公用
*@{
*/

/**@addtogroup enum 枚举定义
*@{
*/

#include "kdvtype.h"

/** nvapi使用方式 */
enum EmNvApiMode_Api
{
	emNvLocMode_Api = 0,       ///< 本地模式(终端)
	emNvRnvMode_Api,           ///< 远程模式(终控)
};

/**控制类型 */
// enum EmNvNvcType_Api
// {
// 	emUnkownT_Api = 0,         ///< 表示未知类型
// 	emNvcT_Api,                ///< nvc类型终端客户端
// 	emPcdvT_Api,               ///< pc流类型终端客户端
// 	emNctT_Api,                ///< 服务器配置类型终端客户端
// };

/** 数据的操作分类 */
enum EmNvDataOptType_Api
{
	emNvDataOptTypeNone_Api = 0,  ///< 修改操作
	emNvDataOptTypeAdd_Api,       ///< 添加操作
	emNvDataOptTypeDel_Api,       ///< 删除操作
	emNvDataOptTypeMod_Api,       ///< 修改操作
	emNvDataOptTypeInit_Api,      ///< 初始化操作
};


/** 升级类型 */
enum EmNvUpgradeType_Api
{
	emNvSusUpgrade_Api = 1,   ///<远端升级
	emNvLocalUpgrade_Api,     ///<本地升级
	emNvNvcUpgrade_Api,       ///<使用Nvc升级
};

/** 同步原因 */
enum EmNvUISynchronizeReason_Api
{
	emNvSynchronize_Upgrade_Api = 0,			   ///< 升级
	emNvSynchronize_BeginDspSleep_Api,	   ///< 开始待机倒计时
	emNvSynchronize_CancelDspSleeep_Api,     ///< 取消待机倒计时
    emNvSynchronize_RecountAutoSleepTime_Api, ///< 重新计算待机时间
};

/**IP类型**/
enum  EmNvIpType_Api
{
	emNvTerIp   = 0,       //终端
	emNvImixIp,            //I_MIX
	emNvLogSerIp,          //日志服务器
	emNvEmialSerIp,        //邮件服务器
};

/**选看投屏器失败原因**/
enum EmNvViewQkReason_Api
{
	emNvViewQk_Success         = 0,
	emNvViewQk_NoSignal        = 1,
	emNvViewQk_Offline         = 2,
	emNvViewQk_UnknowReason    = 3,
	emNvViewQk_NotViewed       = 4,
	emNvViewQk_OverFormat      = 5,       //分辨率过大
	emNvViewQk_IsSame          = 6,
	emNvViewQk_CodeConsultFail = 7,       //编码协商失败
};

/**投屏器ppt翻页控制**/
enum EmNvQkPPTPageTurn_Api
{
	emNvQkPPT_Invalid         = 0,        
	emNvQkPPT_PageUp          = 1,       //ppt上翻
	emNvQkPPT_PageDown        = 2,       //ppt下翻
	emNvQkPPT_Stop            = 3,       //ppt停止
};

/**投屏器播放设备显示比例**/
enum EmNvQkZoomMode_Api
{
	Em_QK_ZOOM_FILLBLACK = 0,//加黑边
	Em_Qk_ZOOM_CUT,//裁边
	Em_Qk_ZOOM_SCALE//不等比拉伸
};

/**投屏器视频格式**/
enum EmNvQkVidFormat_Api
{
	emQkVidFormat_Start_Api     = 0,
	emQkVidFormat_H265_Api      = 1,
	emQkVidFormat_H264_Api      = 2,
	emQkVidFormat_PROFILE_Api   = 3,
	emQkVidFormat_MPEG_Api      = 4,
	emQkVidFormat_H263_Api      = 5,
	emQkVidFormat_H263PLUS_Api  = 6,
	emQkVidFormat_H261_Api      = 7,
	emQkVidFormat_End_Api       = 8,
};

/**投屏器音频格式**/
enum EmNvQkAudFormat_Api
{
	emQkAudFormat_Start_Api          = 0,
	emQkAudFormat_OPUS_Api           = 1,
	emQkAudFormat_G711A_Api          = 2,
	emQkAudFormat_G711U_Api          = 3,
	emQkAudFormat_G719_Api           = 4,
	emQkAudFormat_G722_Api           = 5,
	emQkAudFormat_G7221_Api          = 6,
	emQkAudFormat_G728_Api           = 7,
	emQkAudFormat_G729_Api           = 8,
	emQkAudFormat_MPEGAACLC_Api      = 9,
	emQkAudFormat_MPEGAACLD_Api      = 10,
	emQkAudFormat_MP3_Api            = 11,
	emQkAudFormat_End_Api            = 12,
};

/**投屏器分辨率**/
enum EmNvQkCodeRes_Api
{
	emQkRes_Start_Api                   = 0,
	emQkRes_1080P_1920x1080_Api         = 1,
	emQkRes_WSXGA_1440x900_Api          = 2,
	emQkRes_SXGA_1280x1024_Api          = 3,
	emQkRes_1280x960_Api                = 4,
	emQkRes_WXGA_1366x768_Api           = 5,
	emQkRes_WXGA_1360x768_Api           = 6,
	emQkRes_WXGA_1280x800_Api           = 7,
	emQkRes_WXGA_1280x768_Api           = 8,
	emQkRes_720P_1280x720_Api           = 9,
	emQkRes_1280x600_Api                = 10,
	emQkRes_XGA_1024x768_Api            = 11,
	emQkRes_SVGA_800x600_Api            = 12,
	emQkRes_End_Api                     = 13,
};
/**@}*/

/**@}*/
#endif //_NVAPI_ENUM_H_
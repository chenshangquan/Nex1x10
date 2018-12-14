/**===========================================================================
 * @file    mtvodmodel.h
 * @brief   
 1、登录；（restapi实现）
 2、获取点播列表；（restapi实现）
 3、注销；（restapi实现）


 4、播放点播列表中视频源；
 5、暂停点播列表中视频源；
 6、恢复点播列表中的视频源；
 7、改变播放速度；
 8、改变点播进度；
 9、停止播放；
 10、告之播放进度；（不支持，vod组由界面做的，这个rtsp应该支持）
 11、对指定视频源做上面操作（暂时只能进行播放和停止操作）

 * @author  longwei
 * @date    
 * @version  
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note
============================================================================*/
#ifndef _MTVODMODEL_H_
#define _MTVODMODEL_H_
#include "kdvtype.h"
#include "mtstruct.h"

extern "C"
{
/**----------------------------------------------------------------------
* MtVodStart
* 
* @brief   终端点播模块启动接口
* 
* @param   [in] tMdlStartparam 启动参数
* @return  BOOL32 TRUE:成功启动， FALSE:启动失败
* @see     MtVodStop()
------------------------------------------------------------------------*/
MTCBB_API BOOL32 MtVodStart(TMdlStartParam &tMdlStartparam);

/**----------------------------------------------------------------------
* MtVodStop
* 
* @brief   点播模块退出接口
* 
* @param   void
* @return  BOOL32 TRUE:成功退出， FALSE:退出失败
* @see     MtVodStart()
------------------------------------------------------------------------*/
MTCBB_API BOOL32 MtVodStop();

};


#endif \\ _MTVODMODEL_H_
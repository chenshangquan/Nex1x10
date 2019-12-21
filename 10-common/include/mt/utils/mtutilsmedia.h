#if 0 //attention 此部分接口已经挪到mtcbbcommon模块中

/*---------------------------------------------------------------------------*/
/*
 * @file    $Id$
 * @brief   音视频相关公用函数
 * @author  瞿戴沣
 * @date    $Date$
 * @version  $Revision$
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * 
 */
/*---------------------------------------------------------------------------*/

#ifndef _MTUTILS_MEDIA_H
#define _MTUTILS_MEDIA_H

#include "kdvtype.h"
#include "enum.pb.h"
#include "mtmacro.h"

namespace MTUTILS
{

/*!**********************************************************
* 
* @brief   根据视频分辨率得到宽高
* @param   [in] emRes:     视频分辨率
* @param   [out] dwWidth:  得到宽度
* @param   [out] dwHeight: 得到高度
* @return  MT_SUCCESS: 成功
*          MT_FAILED: 失败
*************************************************************/
MTCBB_API u32 mtGetVideoWidthHeight(mt::EmMtResolution emRes, u32 &dwWidth, u32 &dwHeight);


/*!**********************************************************
* 
* @brief   根据视频分辨率得到宽高
* @param   [in] emRes:     视频分辨率
* @param   [in] dwLen:     缓冲区大小
* @param   [out] 宽高字符串 如1280*720
* @return  MT_SUCCESS: 成功
*          MT_FAILED: 失败
*************************************************************/
MTCBB_API u32 mtGetVideoWidthHeight(mt::EmMtResolution emRes, s8 *pchStrOut, u32 dwLen);


/*!**********************************************************
* 
* @brief   根据宽高得到分辨率
* @param   [in]  dwWidth:  宽度
* @param   [in]  dwHeight: 高度
* @param   [out] emRes:    得到的视频分辨率
* @return  MT_SUCCESS: 成功
*          MT_FAILED: 失败
*************************************************************/
MTCBB_API u32 mtGetVideoRes(u32 dwWidth, u32 dwHeight, mt::EmMtResolution &emRes);


/*!**********************************************************
* 
* @brief   根据音频格式获取其码率
* @param   [in]  emAudioFormat:		音频格式
* @param   [out] wAudioBitrate:		得到的音频码率
* @return  MT_SUCCESS: 成功
*          MT_FAILED:  失败
*************************************************************/
MTCBB_API u32 mtGetAudioBitrate(mt::EmAudFormat emAudioFormat, u16 &wAudioBitrate);



/*!**********************************************************
* 
* @brief   根据音频格式获取其载荷类型
* @param   [in]  emAudFormat:		音频格式
*
* @return  成功:对应的载荷类型
*          失败:MEDIA_TYPE_NULL
*************************************************************/
MTCBB_API u8 mtGetAudioPayloadByFormat( mt::EmAudFormat emAudFormat );



/*!**********************************************************
* 
* @brief   根据视频格式获取其载荷类型
* @param   [in]  emFormat:		视频格式
*
* @return  成功:对应的载荷类型
*          失败:MEDIA_TYPE_NULL
*************************************************************/
MTCBB_API u8 mtGetVedioPayloadByFormat( mt::EmVidFormat emFormat );



/*!**********************************************************
* 
* @brief   根据载荷类型获取音频格式
* @param   [in]  byMediaType:		载荷类型
*
* @return  成功:对应的音频格式
*          失败:emAudEnd
*************************************************************/
MTCBB_API mt::EmAudFormat mtGetAudFormatByPayload( u8 byMediaType );



/*!**********************************************************
* 
* @brief   根据载荷类型获取视频格式
* @param   [in]  byMediaType:		载荷类型
*
* @return  成功:对应的视频格式
*          失败:emVEnd
*************************************************************/
MTCBB_API mt::EmVidFormat mtGetVedioFormatByPayload( u8 byPayload );


/*!**********************************************************
* 
* @brief   根据视频格式得到vccommon中视频格式定义
* @param   [in]  emVidResd:		视频格式
*
* @return  成功:对应的视频格式
*          失败:VIDEO_FORMAT_INVALID
*************************************************************/
MTCBB_API u8 mtMapMtVidFormatToVcCommonFormat( mt::EmMtResolution emVidResd );


/*!**********************************************************
* 
* @brief   根据vccommon中视频格式定义得到终端视频格式
* @param   [in]  byRes:		vccommon中视频格式
*
* @return  成功:对应的视频格式
*          失败:emMtVResEnd
*************************************************************/
MTCBB_API mt::EmMtResolution mtMapVcComToMtVideoRes(u8 byRes);

}


#endif	//_MTUTILS_MEDIA_H

#endif // if 0
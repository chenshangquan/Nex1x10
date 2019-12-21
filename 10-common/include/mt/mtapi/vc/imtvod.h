/**===========================================================================
 * @file    $Id$
 * @brief   负责MtVideoConfApi终端视频点/直播控制相关功能接口定义
 * @author  $Author$
 * @date    $Date$
 * @version  $Revision$ 
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note    
============================================================================*/

#ifndef _I_MTVOD_H_
#define _I_MTVOD_H_

#include "mtapi_typedef.h"
#include "mtapi_if.h"
#include "mtapi_event_vc.h"


/**---------------------------------------------------------------------------
 * @class   Interface IMtVod
 * @brief   负责MtVideoConfApi终端视频点/直播控制相关功能接口定义
 * @author  $Author$
 * @version 
 * @date    $Date::                      $
 * @note    
 ---------------------------------------------------------------------------*/

class IMtVod : public IMtApiIF
{
public:
	//登录VRS平台请求
	virtual u32 VrsLoginCmd( const TVodLoginInfo_Api *ptVrsLoginInfo ) = 0;
	//请求文件夹列表
	virtual u32 VrsGetFolderInfoCmd(  ) = 0;
	//请求某一文件夹下的节目列表
	virtual u32 VrsGetPrgsInfoCmd( const TVodGetPrgsReq_Api *ptVrsGetPrgsReq ) = 0;
	//请求查询某一文件夹下的文件
	virtual u32 VrsSearchFilesInfoCmd( const TVodSearchFilesReq_Api ptVrsSearchFilesReq ) = 0;
	//请求直播室列表
	virtual u32 VrsGetRoomListInfoCmd( ) = 0;
	//请求预约直播室列表
	virtual u32 VrsGetReserveRoomListInfoCmd(/* const TVodGetReserveRoomListReq_Api *ptVrsGetReserveRoomListReq */) = 0;
	virtual u32 VrsNewGetResRoomListInfoCmd(const TVodGetResRoomReq_Api tVrsGetReserveRoomListReq ) = 0;

	//开始点播命令
	virtual u32 StartPlayVodCmd( const s8* pszUrl ) = 0;
	//新的开始点播命令
	virtual u32 NewStartPlayVodCmd( const s8* pszUrl,const BOOL32 bFalg ) = 0;
	//获取当前已点播的点播信息
	virtual u32 GetRunVodInfoReq() = 0;
	//获取点播源的信息请求
	virtual u32 GetVodInfoReq( const u32 dwVodId ) = 0;
	//停止点播命令
	virtual u32 StopPlayVodCmd( const u32 dwVodId ) = 0;
	//新的停止点播命令
	virtual u32 NewStopPlayVodCmd( const u32 dwVodId,const BOOL32 bFlag ) = 0;
	//暂停点播命令
	virtual u32 PausePlayVodCmd( const u32 dwVodId ) = 0;
	//恢复点播命令
	virtual u32 ResumePlayVodCmd( const u32 dwVodId ) = 0;
	//改变点播速率
	virtual u32 ChangeVodSpeedCmd( const u32 dwVodId, const s8 chSpeedScale ) = 0;
	//改变点播进度
	virtual u32 ChangeVodProcessCmd( const u32 dwVodId, const u32 dwTime ) = 0;
	//点播源指定流播放
	virtual u32 StartPlayVodStreamCmd( const u32 dwVodId, const u8 byStremId ) = 0;
    //获取点播源信息
	virtual u32 GetVodStreamInfoReq( const u32 dwVodId, const u8 byStremId ) = 0;
	//停止点播源指定流播放
	virtual u32 StopPlayVodStreamCmd( const u32 dwVodId, const u8 byStremId ) = 0;

public:
	//获取点播播放状态
	virtual TVodPlayInfo_Api GetVodPlayInfo()  = 0;
	//获取运行中的点播信息
	virtual TMultiVodPlayInfo_Api GetRuningMultVodPlayInfo()  = 0;

};

#endif // _I_MTVOD_H_
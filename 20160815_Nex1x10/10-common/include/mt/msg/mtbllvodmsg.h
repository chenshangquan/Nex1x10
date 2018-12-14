#ifndef _MTBLLVODMSG_H_
#define _MTBLLVODMSG_H_

#include "mtmsgid.h"

#if !defined(_MESSAGE_HELP_)
enum EmBLLMtVodMsg
{
    EV_BLL_BGN(MTVOD) = EVSEG_BLL_MTVOD_BGN,
#endif//_MESSAGE_HELP_
	/*<<点播播放>>
	*play_url ：播放的地址
	*传输方向：ui->dispatch->vod
	* see Ev_MT_BLL_VODPlay_Ntf
	*/
	MESSAGE(Ev_MT_BLL_VODPlay_Cmd)
	BODY(mt::TString, play_url)

	/*<<点播结果>>
	*play_url ：播放的地址
	*error_codeID ：播放结果
	*传输方向：vod->dispatch->ui
	* see Ev_MT_BLL_VODPlay_Cmd
	*/
	MESSAGE(Ev_MT_BLL_VODPlay_Ntf)
	BODY(mt::TString, play_url)
	BODY(mt::TU32, error_codeID)

	/*<<点播播放通知>>
	*vod_status:播放状态
	*传输方向：vod->dispatch->ui
	*/
	MESSAGE(Ev_MT_BLL_VODStatus_Ntf)
	BODY(mt::TVodPlayInfo, vod_status)

	/*<<获取运行点播的信息>>
	*vod_id ：点播源标识
	*传输方向：ui->dispatch->vod
	* see Ev_MT_BLL_GetRunVODInfo_Rsp
	*/
	MESSAGE(Ev_MT_BLL_GetRunVODInfo_Req)

	/*<<返回运行点播的信息>>
	*vod_infos ：运行的点播信息
	*传输方向：vod->dispatch->ui
	* see Ev_MT_BLL_GetRunVODInfo_Req
	*/
	MESSAGE(Ev_MT_BLL_GetRunVODInfo_Rsp)
	BODY(mt::TMultiVodPlayInfo, vod_infos)

	/*<<获取点播源的信息>>
	*vod_id ：点播源标识
	*传输方向：ui->dispatch->vod
	* see Ev_MT_BLL_GetVODInfo_Rsp
	*/
	MESSAGE(Ev_MT_BLL_GetVODInfo_Req)
	BODY(mt::TU32, vod_id)

	/*<<点播信息应答>>
	*vod_info:点播源信息
	*error_codeID ：结果
	*传输方向：vod->dispatch->ui
	* see Ev_MT_BLL_GetVODInfo_Req
	*/
	MESSAGE(Ev_MT_BLL_GetVODInfo_Rsp)
	BODY(mt::TVodPlayInfo, vod_info)
	BODY(mt::TU32, error_codeID)

	/*<<点播结束>>
	*vod_id ：停止点播源的标识
	*传输方向：ui->dispatch->vod
	* see Ev_MT_BLL_VODOver_Ntf
	*/
	MESSAGE(Ev_MT_BLL_VODOver_Cmd)
	BODY(mt::TU32, vod_id)

	/*<<点播结束结果>>
	*vod_id ：停止点播源的标识
	*error_codeID ：播放结果
	*传输方向：vod->dispatch->ui
	* see Ev_MT_BLL_VODOver_Cmd
	*/
	MESSAGE(Ev_MT_BLL_VODOver_Ntf)
	BODY(mt::TU32, vod_id)
	BODY(mt::TU32, error_codeID)

    /*<<点播暂停>>
	*vod_id ：暂停点播源的标识
	*传输方向：ui->dispatch->vod
	* see Ev_MT_BLL_VODPause_Ntf
	*/
	MESSAGE(Ev_MT_BLL_VODPause_Cmd)
	BODY(mt::TU32, vod_id)

	/*<<点播暂停结果>>
	*vod_id ：停止点播源的标识
	*error_codeID ：播放结果
	*传输方向：vod->dispatch->ui
	* see Ev_MT_BLL_VODPause_Cmd
	*/
	MESSAGE(Ev_MT_BLL_VODPause_Ntf)
	BODY(mt::TU32, vod_id)
	BODY(mt::TU32, error_codeID)

	/*<<恢复点播暂停>>
	*vod_id ：恢复暂停点播源的标识
	*传输方向：ui->dispatch->vod
	* see Ev_MT_BLL_VODResume_Ntf
	*/
	MESSAGE(Ev_MT_BLL_VODResume_Cmd)
	BODY(mt::TU32, vod_id)

	/*<<点播暂停结果>>
	*vod_id ：停止点播源的标识
	*error_codeID ：播放结果
	*传输方向：vod->dispatch->ui
	* see Ev_MT_BLL_VODResume_Cmd
	*/
	MESSAGE(Ev_MT_BLL_VODResume_Ntf)
	BODY(mt::TU32, vod_id)
	BODY(mt::TU32, error_codeID)

	/*<<改变点播速率>>
	*vod_id ：点播源的标识
	*speed_scale ：速率是正常速率的倍数
	*传输方向：ui->dispatch->vod
	* see Ev_MT_BLL_VODChangeSpeed_Ntf
	*/
	MESSAGE(Ev_MT_BLL_VODChangeSpeed_Cmd)
	BODY(mt::TU32, vod_id)
	BODY(mt::TS8, speed_scale)

	/*<<改变点播速率结果>>
	*vod_id ：停止点播源的标识
	*error_codeID ：播放结果
	*传输方向：vod->dispatch->ui
	* see Ev_MT_BLL_VODChangeSpeed_Cmd
	*/
	MESSAGE(Ev_MT_BLL_VODChangeSpeed_Ntf)
	BODY(mt::TU32, vod_id)
	BODY(mt::TU32, error_codeID)

	/*<<改变点播的进度>>
	*vod_id ：点播源的标识
	*cur_time ：当前的播放进度
	*传输方向：ui->dispatch->vod
	* see Ev_MT_BLL_VODChangeProcess_Ntf
	*/
	MESSAGE(Ev_MT_BLL_VODChangeProcess_Cmd)
	BODY(mt::TU32, vod_id)
	BODY(mt::TU32, cur_time)

	/*<<改变点播的进度结果>>
	*vod_id ：停止点播源的标识
	*error_codeID ：播放结果
	*传输方向：vod->dispatch->ui
	* see Ev_MT_BLL_VODChangeProcess_Cmd
	*/
	MESSAGE(Ev_MT_BLL_VODChangeProcess_Ntf)
	BODY(mt::TU32, vod_id)
	BODY(mt::TU32, error_codeID)
	BODY(mt::TU32, tStartTime)

	/*<<点播源指定流播放(暂时不支持)>>
	*vod_id ：点播源标识
	*stream_id ：点播源指定流标识
	*传输方向：ui->dispatch->vod
	* see Ev_MT_BLL_VODStreamPlay_Ntf
	*/
	MESSAGE(Ev_MT_BLL_VODStreamPlay_Cmd)
	BODY(mt::TU32, vod_id)
	BODY(mt::TU8, stream_id)

	/*<<点播源指定流播放结果>>
	*vod_id ：点播源的标识
	*error_codeID ：播放结果
	*传输方向：vod->dispatch->ui
	* see Ev_MT_BLL_VODStreamPlay_Cmd
	*/
	MESSAGE(Ev_MT_BLL_VODStreamPlay_Ntf)
	BODY(mt::TU32, vod_id)
	BODY(mt::TU8, stream_id)
	BODY(mt::TU32, error_codeID)

	/*<<点播指定源播放通知>>
	*vod_id:点播源标识
	*stream_status:指定源状态
	*传输方向：vod->dispatch->ui
	*/
	MESSAGE(Ev_MT_BLL_VODStreamStatus_Ntf)
	BODY(mt::TU32, vod_id)
	BODY(mt::TStreamInfo, stream_status)

	/*<<获取点播源的信息>>
	*vod_id ：点播源标识
	*stream_id ：点播源指定流标识
	*传输方向：ui->dispatch->vod
	* see Ev_MT_BLL_GetVODInfo_Rsp
	*/
	MESSAGE(Ev_MT_BLL_GetVODStreamInfo_Req)
	BODY(mt::TU32, vod_id)
	BODY(mt::TU8, stream_id)

	/*<<点播信息应答>>
	*vod_id:点播源标识
	*stream_status:指定源状态
	*error_codeID ：结果
	*传输方向：vod->dispatch->ui
	* see Ev_MT_BLL_GetVODInfo_Req
	*/
	MESSAGE(Ev_MT_BLL_GetVODStreamInfo_Rsp)
	BODY(mt::TU32, vod_id)
	BODY(mt::TStreamInfo, stream_info)
	BODY(mt::TU32, error_codeID)

	/*<<点播结束(暂时不支持(暂时不支持))>>
	*vod_id ：停止点播源的标识
	*stream_id ：点播源指定流标识
	*传输方向：ui->dispatch->vod
	* see Ev_MT_BLL_VODStreamOver_Ntf
	*/
	MESSAGE(Ev_MT_BLL_VODStreamOver_Cmd)
	BODY(mt::TU32, vod_id)
	BODY(mt::TU8, stream_id)

	/*<<点播结束结果(暂时不支持)>>
	*vod_id ：停止点播源的标识
	*error_codeID ：播放结果
	*传输方向：vod->dispatch->ui
	* see Ev_MT_BLL_VODStreamOver_Cmd
	*/
	MESSAGE(Ev_MT_BLL_VODStreamOver_Ntf)
	BODY(mt::TU32, vod_id)
	BODY(mt::TU8, stream_id)
	BODY(mt::TU32, error_codeID)

    /*<<点播暂停(暂时不支持)>>
	*vod_id ：暂停点播源的标识
	*stream_id ：点播源指定流标识
	*传输方向：ui->dispatch->vod
	* see Ev_MT_BLL_VODStreamPause_Ntf
	*/
	MESSAGE(Ev_MT_BLL_VODStreamPause_Cmd)
	BODY(mt::TU32, vod_id)
	BODY(mt::TU8, stream_id)

	/*<<点播暂停(暂时不支持)结果>>
	*vod_id ：停止点播源的标识
	*error_codeID ：播放结果
	*传输方向：vod->dispatch->ui
	* see Ev_MT_BLL_VODStreamPause_Cmd
	*/
	MESSAGE(Ev_MT_BLL_VODStreamPause_Ntf)
	BODY(mt::TU32, vod_id)
	BODY(mt::TU8, stream_id)
	BODY(mt::TU32, error_codeID)

	/*<<恢复点播暂停(暂时不支持)>>
	*vod_id ：恢复暂停点播源的标识
	*stream_id ：点播源指定流标识
	*传输方向：ui->dispatch->vod
	* see Ev_MT_BLL_VODStreamResume_Ntf
	*/
	MESSAGE(Ev_MT_BLL_VODStreamResume_Cmd)
	BODY(mt::TU32, vod_id)
	BODY(mt::TU8, stream_id)

	/*<<恢复点播暂停(暂时不支持)结果>>
	*vod_id ：停止点播源的标识
	*error_codeID ：播放结果
	*传输方向：vod->dispatch->ui
	* see Ev_MT_BLL_VODStreamResume_Cmd
	*/
	MESSAGE(Ev_MT_BLL_VODStreamResume_Ntf)
	BODY(mt::TU32, vod_id)
	BODY(mt::TU8, stream_id)
	BODY(mt::TU32, error_codeID)

	/*<<改变点播速率(暂时不支持)>>
	*vod_id ：点播源的标识
	*stream_id ：点播源指定流标识
	*speed_scale ：速率是正常速率的倍数
	*传输方向：ui->dispatch->vod
	* see Ev_MT_BLL_VODStreamChangeSpeed_Ntf
	*/
	MESSAGE(Ev_MT_BLL_VODStreamChangeSpeed_Cmd)
	BODY(mt::TU32, vod_id)
	BODY(mt::TU8, stream_id)
	BODY(mt::TS8, speed_scale)

	/*<<改变点播速率(暂时不支持)结果>>
	*vod_id ：停止点播源的标识
	*error_codeID ：播放结果
	*传输方向：vod->dispatch->ui
	* see Ev_MT_BLL_VODStreamChangeSpeed_Cmd
	*/
	MESSAGE(Ev_MT_BLL_VODStreamChangeSpeed_Ntf)
	BODY(mt::TU32, vod_id)
	BODY(mt::TU8, stream_id)
	BODY(mt::TU32, error_codeID)

	/*<<改变点播的进度(暂时不支持)>>
	*vod_id ：点播源的标识
	*stream_id ：点播源指定流标识
	*cur_time ：当前的播放进度
	*传输方向：ui->dispatch->vod
	* see Ev_MT_BLL_VODStreamChangeProcess_Ntf
	*/
	MESSAGE(Ev_MT_BLL_VODStreamChangeProcess_Cmd)
	BODY(mt::TU32, vod_id)
	BODY(mt::TU8, stream_id)
	BODY(mt::TU32, cur_time)

	/*<<改变点播的进度(暂时不支持)结果>>
	*vod_id ：停止点播源的标识
	*error_codeID ：播放结果
	*传输方向：vod->dispatch->ui
	* see Ev_MT_BLL_VODStreamChangeProcess_Cmd
	*/
	MESSAGE(Ev_MT_BLL_VODStreamChangeProcess_Ntf)
	BODY(mt::TU32, vod_id)
	BODY(mt::TU8, stream_id)
	BODY(mt::TU32, error_codeID)

	


		/*请求预约直播室列表命令
	*传输方向：ui->dispatch->vod
	传输方向：ui->dispatch->vod
	* see 
	*/
	MESSAGE(Ev_MT_BLL_VrsGetReserveRoomListInfo_Cmd)
// 	BODY(mt::TVrsGetReserveRoomListReq, TVrsGetReserveRoomListReq)
	
	/*请求预约直播室列表通知
	*TU32 ：错误码
	*TVrsRoomsCfg: 预约直播室列表信息
	*传输方向：vod->dispatch->ui
	* see 
	*/
	MESSAGE(Ev_MT_BLL_VrsGetReserveRoomListInfo_Ntf)
	BODY(mt::TU32, errid)
	BODY(mt::TVrsRoomsCfg, TVrsRoomsCfg)

	/*请求预约直播室列表结束通知
	*/
	MESSAGE(Ev_MT_BLL_VrsGetReserveRoomListInfo_Fin_Ntf)

	/*请求直播室列表命令
	*传输方向：ui->dispatch->vod
	传输方向：ui->dispatch->vod
	* see 
	*/
	MESSAGE(Ev_MT_BLL_VrsGetRoomListInfo_Cmd)

	
	/*请求直播室列表通知
	*TU32 ：错误码
	*TVrsRoomsState: 直播室列表信息
	*传输方向：vod->dispatch->ui
	* see 
	*/
	MESSAGE(Ev_MT_BLL_VrsGetRoomListInfo_Ntf)
	BODY(mt::TU32, errid)
	BODY(mt::TVrsRoomsState, TVrsRoomsState)

	/*请求直播室列表结束通知*/
	MESSAGE(Ev_MT_BLL_VrsGetRoomListInfo_Fin_Ntf)

	/*请求某一文件夹下的节目列表命令
	*传输方向：ui->dispatch->vod
	*TVrsGetPrgsReq：请求参数
	传输方向：ui->dispatch->vod
	* see 
	*/
	MESSAGE(Ev_MT_BLL_VrsGetPrgsInfo_Cmd)
	BODY(mt::TVrsGetPrgsReq, TVrsGetPrgsReq)
	
	/*请求某一文件夹下的节目列表通知
	*TU32 ：错误码
	*TVrsPrgsBaseInfo: 节目列表基本信息
	*TVrsGetPrgsReq : 请求信息
	*传输方向：vod->dispatch->ui
	* see 
	*/
	MESSAGE(Ev_MT_BLL_VrsGetPrgsInfo_Ntf)
	BODY(mt::TU32, errid)
	BODY(mt::TVrsPrgsBaseInfo, TVrsPrgsBaseInfo)
	BODY(mt::TVrsGetPrgsReq, TVrsGetPrgsReq)

	/*请求某一文件夹下的节目列表通知
	*TU32 ：错误码
	*TVrsPrgsDetailInfo: 节目列表具体信息
	*TVrsGetPrgsReq : 请求信息
	*传输方向：vod->dispatch->ui
	* see 
	*/
	MESSAGE(Ev_MT_BLL_VrsGetPrgsDetailInfo_Ntf)
	BODY(mt::TU32, errid)
	BODY(mt::TVrsPrgsDetailInfo, TVrsPrgsDetailInfo)
	BODY(mt::TVrsGetPrgsReq, TVrsGetPrgsReq)

	/*请求某一文件夹下的节目列表结束通知*/
	MESSAGE(Ev_MT_BLL_VrsGetPrgsInfo_Fin_Ntf)

	/*请求文件夹列表命令
	*传输方向：ui->dispatch->vod
	* see 
	*/
	MESSAGE(Ev_MT_BLL_VrsGetFolderInfo_Cmd)

	
	/*请求文件夹列表通知
	*TU32 ：错误码
	*TVrsFoldersInfo: 文件夹列表
	*传输方向：vod->dispatch->ui
	* see 
	*/
	MESSAGE(Ev_MT_BLL_VrsGetFolderInfo_Ntf)
	BODY(mt::TU32, errid)
	BODY(mt::TVrsFoldersInfo, TVrsFoldersInfo)
	
	/*请求文件夹列表结束通知*/
	MESSAGE(Ev_MT_BLL_VrsGetFolderInfo_Fin_Ntf)

		/*登录VRS平台命令
	*TVrsLoginInfo ：登录结构体
	*传输方向：ui->dispatch->vod
	* see 
	*/
	MESSAGE(Ev_MT_BLL_VrsLogin_Cmd)
	BODY(mt::TVrsLoginInfo, TVrsLoginInfo)
	
	/*登录VRS平台通知
	*TU32 ：错误码
	*传输方向：vod->dispatch->ui
	* see 
	*/
	MESSAGE(Ev_MT_BLL_VrsLogin_Ntf)
	BODY(mt::TU32, errid)
	
	/*注销VRS平台命令
	*TVrsLoginInfo ：登录结构体
	*传输方向：ui->dispatch->vod
	* see 
	*/
	MESSAGE(Ev_MT_BLL_VrsLogout_Cmd)
	
	/*注销VRS平台通知
	*TU32 ：错误码
	*传输方向：vod->dispatch->ui
	* see 
	*/
	MESSAGE(Ev_MT_BLL_VrsLogout_Ntf)
	BODY(mt::TU32, errid)
	
	/*Vrs获取类超时返回(网络不好)
	*TU32 ：错误码(区分不同的获取接口)
	*传输方向：vod->dispatch->ui
	* see 
	*/
	MESSAGE(Ev_MT_BLL_VrsGetListTimerOut_Ntf)
	BODY(mt::TU32, errid)

		/*请求预约直播室列表命令 new
	*传输方向：ui->dispatch->vod
	传输方向：ui->dispatch->vod
	* see 
	*/
	MESSAGE(Ev_MT_BLL_VrsNewGetResRoomInfo_Cmd)
 	BODY(mt::TVrsGetReserveRoomListReq, TVrsGetReserveRoomListReq)
	
	/*请求预约直播室列表通知 new
	*TU32 ：错误码
	*TVrsRoomsCfg: 预约直播室列表信息
	*传输方向：vod->dispatch->ui
	* see 
	*/
	MESSAGE(Ev_MT_BLL_VrsNewGetResRoomInfo_Ntf)
	BODY(mt::TU32, errid)
	BODY(mt::TVrsRoomsCfg, TVrsRoomsCfg)

	/*请求预约直播室列表结束通知
	*/
	MESSAGE(Ev_MT_BLL_VrsNewGetResRoomInfo_Fin_Ntf)


#if !defined(_MESSAGE_HELP_)
    EV_BLL_END(MTVOD) = EVSEG_BLL_MTVOD_END
};
#endif//_MESSAGE_HELP_

#define Is_BLL_Vod_Msg(m) ((m) >= EV_BLL_BGN(MTVOD) && (m) <= EV_BLL_END(MTVOD))

#endif//_MTBLLVODMSG_H_
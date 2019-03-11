#ifndef _MTBLLDEVICEMSG_H_
#define _MTBLLDEVICEMSG_H_

#include "mtmsgid.h"

#if !defined(_MESSAGE_HELP_)
enum EmBLLMtDeviceMsg
{
    EV_BLL_BGN(DEVICE) = EVSEG_BLL_DEVICE_BGN,
#endif

	/*********************************摄像头相关消息Begin***************************************/

    /*<<摄像头选择>>
    *vid_idx : EmCodecComponentIndex  em1st表示第一路  em2nd表示第二路
    *vid_port : EmMtVideoPort
	*消息流向 : sdk==>dispatch==>deivce
	*/
    MESSAGE(Ev_MT_BLL_DeviceCameraSelect_Cmd)
    BODY(mt::TU32, vid_idx)
    BODY(mt::TU8, vid_port)

	/*<<摄像头待机\唤醒>>
    *opt : TRUE表示待机 FALSE表示唤醒
	*消息流向 : sdk==>dispatch==>deivce
	*/
    MESSAGE(Ev_MT_BLL_DeviceCameraPower_Cmd)
    BODY(mt::TBOOL32, opt)

    /*<<摄像头预置位操作命令>>
    *vid_idx : EmCodecComponentIndex  em1st表示第一路  em2nd表示第二路
	*opt : TRUE表示保存 FALSE表示调用
    *index : 当前操作的预置位索引
	*消息流向 : sdk==>dispatch==>mtservice
	*see Ev_MT_BLL_DeviceCameraPreset_Rsp
	*/
    MESSAGE(Ev_MT_BLL_DeviceCameraPreset_Req)
    BODY(mt::TU32, vid_idx)
	BODY(mt::TBOOL32, opt)
    BODY(mt::TU8, index)

    /*<<摄像头预置位操作响应,收到此消息表示操作结束,结束不表示一定操作成功>>
    *vid_idx : EmCodecComponentIndex  em1st表示第一路  em2nd表示第二路
	*opt : TRUE表示保存 FALSE表示调用
	*index : 当前操作的预置位索引
	*消息流向 : mtservice==>dispatch==>sdk
	*see Ev_MT_BLL_DeviceCameraPreset_Req
	*/
    MESSAGE(Ev_MT_BLL_DeviceCameraPreset_Rsp)
    BODY(mt::TU32, vid_idx)
	BODY(mt::TBOOL32, opt)
	BODY(mt::TU8, index)
    BODY(mt::TBOOL32, sucess)

    /*<<查询预置位图片请求>>
    *vid_idx : EmCodecComponentIndex  em1st表示第一路  em2nd表示第二路
	*消息流向 : sdk==>dispatch==>mtservice
	*see Ev_MT_BLL_DeviceQueryCameraPresetPic_Rsp
	*/
    MESSAGE(Ev_MT_BLL_DeviceQueryCameraPresetPic_Req)
    BODY(mt::TU32, vid_idx)

    /*<<查询预置位图片响应>>
    *vid_idx : EmCodecComponentIndex  em1st表示第一路  em2nd表示第二路
	*TMTCameraPresetPicList : 当前操作的预置位索引
	*消息流向 : mtservice==>dispatch==>sdk
	*see Ev_MT_BLL_DeviceQueryCameraPresetPic_Req
	*/
    MESSAGE(Ev_MT_BLL_DeviceQueryCameraPresetPic_Rsp)
    BODY(mt::TU32, vid_idx)
	BODY(mt::TMTCameraPresetPicList, pic_name)

    /*<<摄像头方位调节>>
    *vid_idx : EmCodecComponentIndex  em1st表示第一路  em2nd表示第二路
	*direction : EmDirection
    *action : EmAction
	*消息流向 : sdk==>dispatch==>deivce
	*/
    MESSAGE(Ev_MT_BLL_DeviceCameraPantilt_Cmd)
    BODY(mt::TU32, vid_idx)
	BODY(mt::TS32, direction) //枚举值统一使用mt::TS32来传输，该处实际为mt::EmDirection
    BODY(mt::TS32, action)   //枚举值统一使用mt::TS32来传输，该处实际为mt::EmAction

    /*<<摄像头焦距调节>>
    *vid_idx : EmCodecComponentIndex  em1st表示第一路  em2nd表示第二路
	*opt : TRUE表示远距 FALSE表示近距
    *action : EmAction
	*消息流向 : sdk==>dispatch==>deivce
	*/
    MESSAGE(Ev_MT_BLL_DeviceCameraFocus_Cmd)
    BODY(mt::TU32, vid_idx)
	BODY(mt::TBOOL32, opt)
    BODY(mt::TS32, action) //枚举值统一使用mt::TS32来传输，该处实际为mt::EmAction

    /*<<摄像头自动聚焦>>
    *vid_idx : EmCodecComponentIndex  em1st表示第一路  em2nd表示第二路
	*消息流向 : sdk==>dispatch==>deivce
	*/
    MESSAGE(Ev_MT_BLL_DeviceCameraAutoFocus_Cmd)
    BODY(mt::TU32, vid_idx)

    /*<<摄像头视野调节>>
    *vid_idx : EmCodecComponentIndex  em1st表示第一路  em2nd表示第二路
	*opt : TRUE表示远视 FALSE表示近视
    *action : EmAction
	*消息流向 : sdk==>dispatch==>deivce
	*/
    MESSAGE(Ev_MT_BLL_DeviceCameraZoom_Cmd)
    BODY(mt::TU32, vid_idx)
	BODY(mt::TBOOL32, opt)  
    BODY(mt::TS32, action) //枚举值统一使用mt::TS32来传输，该处实际为mt::EmAction

    /*<<摄像头亮度调节>>
    *vid_idx : EmCodecComponentIndex  em1st表示第一路  em2nd表示第二路
	*opt : TRUE表示增大 FLASE表示减小
    *action : EmAction
	*消息流向 : sdk==>dispatch==>deivce
	*/
    MESSAGE(Ev_MT_BLL_DeviceCameraBright_Cmd)
    BODY(mt::TU32, vid_idx)
	BODY(mt::TBOOL32, opt)
    BODY(mt::TS32, action) //枚举值统一使用mt::TS32来传输，该处实际为mt::EmAction

    /*<<摄像头背光补偿>>
    *vid_idx : EmCodecComponentIndex  em1st表示第一路  em2nd表示第二路
    *on : TRUE表示开启 FALSE表示关闭
	*消息流向 : sdk==>dispatch==>deivce
	*/
    MESSAGE(Ev_MT_BLL_DeviceCameraBackLight_Cmd)
    BODY(mt::TU32, vid_idx)
    BODY(mt::TBOOL32, on)

    /*<<摄像头升级>>
    *vid_idx : EmMtVideoPort  接入摄像机的视频源接口
	*camera_type : 升级摄像头类型
	*action : TRUE表示开始 FLASE表示停止
	*file_name : 升级文件名路径
	*消息流向 : sdk==>dispatch==>deivce
	*/
    MESSAGE(Ev_MT_BLL_DeviceCameraUpgrade_Cmd)
    BODY(mt::TU32, vid_idx)
	BODY(mt::TMTCameraUpgrade, camera_upgrade)

    /*<<摄像头升级>>
    *vid_idx : EmMtVideoPort  接入摄像机的视频源接口
	*type : EmEquipmentUpgrading
	*result : TRUE表示成功 FALSE表示失败
	*消息流向 : device==>dispatch==>sdk
	*/
    MESSAGE(Ev_MT_BLL_DeviceCameraUpgrade_Ntf)
    BODY(mt::TU32, vid_idx)
	BODY(mt::TS32, type) //枚举值统一使用mt::TS32来传输，该处实际为mt::EmEquipmentUpgrading
	BODY(mt::TS32, error)//枚举值统一使用mt::TS32来传输，该处实际为mt::EmCameraUpgradeErrCode

    /*<<摄像头版本查询>>
    *vid_idx : EmCodecComponentIndex  em1st表示第一路  em2nd表示第二路
    *vid_type : 0表示第一路  1表示第二路
	*消息流向 : sdk==>dispatch==>deivce
	*/
    MESSAGE(Ev_MT_BLL_DeviceCameraVersion_Req)
    BODY(mt::TU32, vid_idx)

    /*<<摄像头版本查询>>
    *vid_idx : EmCodecComponentIndex  em1st表示第一路  em2nd表示第二路
	*camera_ver_info : 摄像头版本信息
	*消息流向 : device==>dispatch==>sdk
	*/
    MESSAGE(Ev_MT_BLL_DeviceCameraVersion_Rsp)
    BODY(mt::TU32, vid_idx)
	BODY(mt::TString, camera_ver_info)
	
	/*<<摄像头亮度查询>>
    *vid_idx : EmCodecComponentIndex  em1st表示第一路  em2nd表示第二路
	*消息流向 : sdk==>dispatch==>mtservice
	*/
    MESSAGE(Ev_MT_BLL_DeviceCameraBright_Req)
    BODY(mt::TU32, vid_idx)

    /*<<摄像头亮度查询响应>>
    *vid_idx : EmCodecComponentIndex  em1st表示第一路  em2nd表示第二路
	*camera_bright : 摄像头亮度信息
	*消息流向 : mtservice==>dispatch==>sdk
	*/
    MESSAGE(Ev_MT_BLL_DeviceCameraBright_Rsp)
    BODY(mt::TU32, vid_idx)
	BODY(mt::TU32, camera_bright)

    /*<<摄像头能力类型查询>>
	*消息流向 : sdk==>dispatch==>service
    *see : Ev_MT_BLL_DeviceCameraTypeCapset_Rsp
	*/
	MESSAGE(Ev_MT_BLL_DeviceGetCameraTypeCapset_Req)


    /*<<摄像头能力类型上报>>
	*camera_type_list : 所有支持的摄像头能力类型查询结果
	*消息流向 : service==>dispatch==>sdk
    *see : Ev_MT_BLL_DeviceCameraTypeCapset_Req
	*/
	MESSAGE(Ev_MT_BLL_DeviceGetCameraTypeCapset_Rsp)
	BODY(mt::TMTCameraTypeList, camera_type_list)



	/*<<摄像头能力类型上报>>
	*camera_type_list : 所有支持的摄像头能力类型上报
	*消息流向 : service==>dispatch==>sdk
	*/
	MESSAGE(Ev_MT_BLL_DeviceCameraTypeCapset_Ntf)
	BODY(mt::TMTCameraTypeList, camera_type_list)

   /*********************************摄像头相关消息End***************************************/

   
   
   /*********************************遥控器相关消息Begin************************************/

   /*<<遥控器按键通知>>
   *key_type : TRUE表示keyup  FALSE表示keydown
   *key_source : 按键来源
   *key_code : 按键键值
   *key_count : 按键次数
   *消息流向 : device==>dispatch==>sdk
   */
   MESSAGE(Ev_MT_BLL_DeviceKeyCodeNtf)
   BODY(mt::TMTKeyPressInfo, key_press_info)

   /*<<实体遥控器按键通知(网呈使用)>>
   *key_type : TRUE表示keyup  FALSE表示keydown
   *key_source : 按键来源
   *key_code : 按键键值
   *key_count : 按键次数
   *消息流向 : device==>dispatch==>sdk
   */
   MESSAGE(Ev_MT_BLL_EntityDeviceKeyCodeNtf)
   BODY(mt::TMTKeyPressInfo, key_press_info)
   
   /*********************************遥控器相关消息End************************************/



    /*<<数字mic升级>>
	*uart_num : 串口设备号
	*path : 升级文件路径
	*消息流向 : sdk==>dispatch==>device
	*/
    MESSAGE(Ev_MT_BLL_DeviceDMicUpgrade_Cmd)
	BODY(mt::TS32, uart_num)							//枚举值统一使用mt::TS32来传输，该处实际为mt::EmUartNum
	BODY(mt::TString, path)

	/*<<数字mic升级>>
	*uart_num : 串口设备号
	*result : 升级结果 TRUE表示升级成功
	*消息流向 : deivce==>dispatch==>sdk
	*/
	MESSAGE(Ev_MT_BLL_DeviceDMicUpgrade_Ntf)
	BODY(mt::TS32, uart_num)						//枚举值统一使用mt::TS32来传输，该处实际为mt::EmUartNum
	BODY(mt::TBOOL32, result)

	/*<<数字mic版本查询>>
	*uart_num : 串口设备号
	*消息流向 : sdk==>dispatch==>device
	*/
	MESSAGE(Ev_MT_BLL_DeviceDMicVersion_Req)
	BODY(mt::TS32, uart_num)						//枚举值统一使用mt::TS32来传输，该处实际为mt::EmUartNum

	/*<<数字mic版本查询>>
	*uart_num : 串口设备号
	*ver : 版本号
	*消息流向 : device==>dispatch==>sdk
	*/
	MESSAGE(Ev_MT_BLL_DeviceDMicVersion_Rsp)
	BODY(mt::TS32, uart_num)						//枚举值统一使用mt::TS32来传输，该处实际为mt::EmUartNum
	BODY(mt::TString, ver)

	/*<<无线mic升级>>
	*uart_num : 串口设备号
	*path : 升级文件路径
	*消息流向 : sdk==>dispatch==>device
	*/
    MESSAGE(Ev_MT_BLL_DeviceWMicUpgrade_Cmd)
	BODY(mt::TS32, uart_num)
	BODY(mt::TString, path)

	/*<<无线mic升级>>
	*uart_num : 串口设备号
	*result : 升级结果 TRUE表示升级成功
	*消息流向 : deivce==>dispatch==>sdk
	*/
	MESSAGE(Ev_MT_BLL_DeviceWMicUpgrade_Ntf)
	BODY(mt::TS32, uart_num)
	BODY(mt::TBOOL32, result)

	/*<<无线mic版本查询>>
	*uart_num : 串口设备号
	*消息流向 : sdk==>dispatch==>device
	*/
	MESSAGE(Ev_MT_BLL_DeviceWMicVersion_Req)
	BODY(mt::TS32, uart_num)

	/*<<无线mic版本查询>>
	*uart_num : 串口设备号
	*ver : 版本号
	*消息流向 : device==>dispatch==>sdk
	*/
	MESSAGE(Ev_MT_BLL_DeviceWMicVersion_Rsp)
	BODY(mt::TS32, uart_num)
	BODY(mt::TString, ver)

	/*<<查询cpu和内存使用情况命令>>
	*消息流向 : mtsdk->mtservice
	* see Ev_MT_BLL_DeviceDetectCpuAndMem_Rsp
	*/
	MESSAGE(Ev_MT_BLL_DeviceDetectCpuAndMem_Req)

	/*<<查询cpu和内存使用情况响应>>
	*cpu : cpu使用率
	*memory : 内存使用情况
	*消息流向 : mtservice->mtsdk
	* see Ev_MT_BLL_DeviceDetectCpuAndMem_Req
	*/
	MESSAGE(Ev_MT_BLL_DeviceDetectCpuAndMem_Rsp)
	BODY(mt::TMTCpuAndMemState, cpuandmemsts)


    /*------生产测试--------*/
    /*<<串口生产测试请求>>
    *serial_type : 串口种类
	*消息流向 : mfgtest->service
	* see Ev_MT_BLL_DeviceSerialTest_Rsp
	*/
    MESSAGE(Ev_MT_BLL_DeviceSerialTest_Req)
    BODY(mt::TS32, serial_type)

	/*<<串口关闭命令>>
    *serial_type : 串口种类
	*消息流向 : mtservice==>device
	* see
	*/
	MESSAGE(Ev_MT_BLL_CloseSerialCom_Cmd)
	BODY(mt::TS32, serial_type)

    /*<<查询cpu和内存使用情况响应>>
	*result : 测试结果
	*serial_type : 串口种类
	*消息流向 : service->mfgtest
	* see Ev_MT_BLL_DeviceSerialTest_Req
	*/
    MESSAGE(Ev_MT_BLL_DeviceSerialTest_Rsp)
    BODY(mt::TBOOL32, result)
    BODY(mt::TS32, serial_type)

    /*<<遥控器生产测试开始或结束通知>>
    *install : 打开或关闭
	*消息流向 : mfgtest->service
	* see Ev_MT_BLL_DeviceRemoteCtrlTest_Ntf
	*/
    MESSAGE(Ev_MT_BLL_DeviceRemoteCtrlTest_Cmd)
    BODY(mt::TBOOL32, install)

    /*<<遥控器生产测试键值返回>>
	*result : 测试结果
	*scan_code : 键值
	*消息流向 : service->mfgtest
	* see Ev_MT_BLL_DeviceRemoteCtrlTest_Cmd
	*/
    MESSAGE(Ev_MT_BLL_DeviceRemoteCtrlTest_Ntf)
    BODY(mt::TBOOL32, result)
    BODY(mt::TU8, scan_code)

	/*<<遥控器版本号上报>>
	*byRemoteCtrlVersion : 遥控器版本号
	*消息流向 : misc==>ui
	*/
    MESSAGE(Ev_MT_BLL_DeviceRemoteCtrlVersion_Ntf)
    BODY(mt::TString, byRemoteCtrlVersion)


	////设置当前控制摄像头的远端还是本地
	MESSAGE( Ev_MT_BLL_DeviceCameraCtrlSite_Cmd )
	BODY(mt::TU32, tSite)

	////设置当前控制摄像头的远端还是本地
	MESSAGE( Ev_MT_BLL_DeviceCameraCtrlSite_Ntf )
	BODY(mt::TU32, tSite)


	/*<<按键通知>>
	* ui -> misc
	*/
    MESSAGE(Ev_MT_BLL_UserOperation_Ntf)
	BODY(mt::TBOOL32, is_key_power_press)	//是否待机键


	/*<<向ui发送待机倒计时通知>>
	* misc -> ui
	*/
	MESSAGE(Ev_MT_BLL_SleepCountDown_Ntf)
	BODY(mt::TS32, count_down)	//倒计时时间

	/*<<通知终端待机状态>>
	* misc -> ui
	*/
	MESSAGE(Ev_MT_BLL_SleepState_Ntf)
	BODY(mt::TS32, EmMtSleepState)	//待机状态

	/*<<向ui发送重置系统通知>>
	* misc -> ui
	*/
	MESSAGE(Ev_MT_BLL_OqcResetSystem_Ntf)

	/*<<重启终端>>
	* ui -> misc
	*/
	MESSAGE(Ev_MT_BLL_RebootSystem_Cmd)

	

	/*<<手动设置系统时间>>
	* ui -> misc
	*/
	MESSAGE(Ev_MT_BLL_SetSystemTime_Cmd)
	BODY(mt::TMTTime, time)				//要设置的时间


	/*<<系统恢复出厂设置>>
	*is_oqc : true表示需要删除配置, false表示不需要删除配置
	* ui -> misc
	*/
	MESSAGE(Ev_MT_BLL_ResetSystem_Cmd)
	BODY(mt::TBOOL32, is_oqc)
	
	/*<<系统恢复出厂设置>>
	*is_oqc : true表示需要删除配置, false表示不需要删除配置
	* service -> sdk
	*/
	MESSAGE(Ev_MT_BLL_ResetSystem_Ntf)
	BODY(mt::TBOOL32, is_oqc)

	/*<<开启式抓包命令>>
	* ui -> misc
	*/
	MESSAGE(Ev_MT_BLL_StartNetCapture_Cmd)
    BODY(mt::TU32, capture_nettype)  //抓包网口选择 EmNetAdapterWorkType

	/*<<停止抓包命令>>
	* ui -> misc
	*/
	MESSAGE(Ev_MT_BLL_StopNetCapture_Cmd)

	/*<<获取当前抓包状态>>
	* ui-> service
	*/
	MESSAGE(Ev_MT_BLL_GetCurCapStatus_Req)

	/*<<获取当前抓包状态回应>>
	* ui <- service
	*/
	MESSAGE(Ev_MT_BLL_GetCurCapStatus_Rsp)
	BODY(mt::TU32, capture_state)	 // 1:正在抓包  0:没有抓包
	BODY(mt::TMTTime, curtime)		 // 抓包开始时间
	BODY(mt::TU32, lastCaptime)		 // 上次抓包时间（单位：秒）
    BODY(mt::TU32, startcaptime)     // 上次抓包时间（新版本使用 单位：秒）

	/*<<抓包状态通知>>
	* misc -> ui
	*/
	MESSAGE(Ev_MT_BLL_NetCaptureState_Ntf)
	BODY(mt::TU32, capture_state)	 // MT_SUCCESS:正在抓包  MT_FAILED:开启抓包失败
	BODY(mt::TMTTime, curtime)		 // 抓包开始时间
	BODY(mt::TU32, lastCaptime)		 // 上次抓包时间（单位：秒）

	/*<<抓包文件列表查询>>
	* ui -> service
	*/
	MESSAGE(Ev_MT_BLL_GetNetCapFileList_Req)

	/*<<删除抓包文件>>
	* ui -> misc
	*/
	MESSAGE(Ev_MT_BLL_DeleteNetCapFile_Cmd)

    /*<<删除抓包文件>>
	* service_hd -> ui
	*/
	MESSAGE(Ev_MT_BLL_DeleteNetCapFile_Ntf)
    BODY(mt::TU32, result)

	/*<<抓包文件列表查询响应>>
	* ui -> service
	*/
	MESSAGE(Ev_MT_BLL_GetNetCapFileList_Rsp)
	BODY(mt::TNetCapFileList, netcaplist)	//抓包文件列表

	/*<<导出抓包文件请求>>
	* ui -> misc
	*/
	MESSAGE(Ev_MT_BLL_ExportNetCapture_Req)
	BODY(mt::TString, export_file_path)	//文件导出路径

	/*<<导出抓包文件进度通知>>
	* ui -> misc
	*/
	MESSAGE(Ev_MT_BLL_ExportNetCaptureProgress_Ntf)
	BODY(mt::TU32, percent)	//整体百分比


	/*<<导出抓包文件响应>>
	* misc -> ui
	*/
	MESSAGE(Ev_MT_BLL_ExportNetCapture_Rsp)
	BODY(mt::TU32, is_ok)	//MT_SUCCESS:成功
							//ERR_MTMISC_DISK_OUTOF_SPACE 空间不足
							//ERR_MTMISC_FILE_NOT_EXIST  文件不存在
	
	/*<<获取当前抓包持续时间>>
	* ui-> service
	*/
	MESSAGE(Ev_MT_BLL_GetPacketDurationTime_Req)

	/*<<回复当前抓包持续时间>>
	* service-> ui
	*/
	MESSAGE(Ev_MT_BLL_GetPacketDurationTime_Rsp)
	BODY(mt::TU32, durationTime )		 // 抓包持续时间


	/*<<导出日志请求>>
	* ui -> misc
	*/
	MESSAGE(Ev_MT_BLL_ExportLog_Req)
	BODY(mt::TString, export_file_path)	//文件导出路径

	/*<<导出日志进度通知>>
	* ui -> misc
	*/
	MESSAGE(Ev_MT_BLL_ExportLogProgress_Ntf)
	BODY(mt::TU32, percent)	//整体百分比


	/*<<导出日志响应>>
	* misc -> ui
	*/
	MESSAGE(Ev_MT_BLL_ExportLog_Rsp)
	BODY(mt::TU32, is_ok)	
    //MT_SUCCESS:成功
	//ERR_MTMISC_DISK_OUTOF_SPACE 空间不足
	//ERR_MTMISC_PATH_NOT_EXIST 导出路径不存在
	//ERR_MTMISC_FILE_NOT_EXIST 日志文件不存在
	//...




    /*<<检查文件请求>>
    * 消息流向 : sdk -> service
    * 参数 : file_path   查找起始目录
    * 参数 : file_name   查找文件名
    * 参数 : is_recurse  是否查找所有子目录
    * see : Ev_MT_BLL_FileExistCheck_Rsp
	*/
    MESSAGE(Ev_MT_BLL_FileExistCheck_Req)
    BODY(mt::TString, file_path)
    BODY(mt::TString, file_name)
    BODY(mt::TBOOL32, is_recurse)

    /*<<检查文件响应>>
    * 消息流向 : service -> sdk
    * 参数 : is_exist        所查文件是否存在
    * 参数 : file_full_path  所查文件全路径(包含文件名)
    * 参数 : file_size       所查文件大小
    * see : Ev_MT_BLL_FileExistCheck_Req
	*/
    MESSAGE(Ev_MT_BLL_FileExistCheck_Rsp)
    BODY(mt::TBOOL32, is_exist)
    BODY(mt::TString, file_full_path)
    BODY(mt::TU32, file_size)



    /*<<导出地址簿请求>>
    * 消息流向 : sdk -> service
    * 参数 : dst_path    导出目标路径
    * see : Ev_MT_BLL_AddrBookExport_Rsp
	*/
    MESSAGE(Ev_MT_BLL_AddrBookExport_Req)
    BODY(mt::TString, dst_path)

    /*<<检查文件响应>>
    * 消息流向 : service -> sdk
    * 参数 : err_code      是否成功 mt::EmFileCopyErr
    * see : Ev_MT_BLL_AddrBookExport_Req
	*/
    MESSAGE(Ev_MT_BLL_AddrBookExport_Rsp)
    BODY(mt::TS32, err_code)

    /*<<导出地址簿百分比>>
    * 消息流向 : service -> sdk
    * 参数 : progress      百分比
    * see : Ev_MT_BLL_AddrBookExport_Req
	*/
    MESSAGE(Ev_MT_BLL_AddrBookExportProgress_Ntf)
    BODY(mt::TU32, progress)



    /*<<导入地址簿请求>>
    * 消息流向 : sdk -> service
    * 参数 : dst_path    导入源路径(带文件名)
    * see : Ev_MT_BLL_AddrBookImport_Rsp
	*/
    MESSAGE(Ev_MT_BLL_AddrBookImport_Req)
    BODY(mt::TString, src_path)


    /*<<导入地址簿响应>>
    * 消息流向 : service -> sdk
    * 参数 : err_code      是否成功 mt::EmFileCopyErr
    * see : Ev_MT_BLL_AddrBookImport_Req
	*/
    MESSAGE(Ev_MT_BLL_AddrBookImport_Rsp)
    BODY(mt::TS32, err_code)

    /*<<导入地址簿百分比>>
    * 消息流向 : service -> sdk
    * 参数 : progress      百分比
    * see : Ev_MT_BLL_AddrBookExport_Req
	*/
    MESSAGE(Ev_MT_BLL_AddrBookImportProgress_Ntf)
    BODY(mt::TU32, progress)

	/*<终端反控摄像机>>
    * 消息流向 : sdk -> service
    * 参数 : vid_idx : EmCodecComponentIndex  em1st表示第一路  em2nd表示第二路
	* 参数 : osd_type ：EmTerControlCameraOsdType 对osd的操作类型
	*/
    MESSAGE(Ev_MT_BLL_TerminalControlCameraOsd_Cmd)
    BODY(mt::TU32, vid_idx)
	BODY(mt::TU32, osd_type)
	
    /*<<导入麦克风升级文件请求>>
    * 消息流向 : sdk -> service
    * 参数 : dst_path    导入源路径(带文件名)
    * see : Ev_MT_BLL_MicUpgradeFileImport_Rsp
    *       Ev_MT_BLL_MicUpgradeFileImportProgress_Ntf
	*/
    MESSAGE(Ev_MT_BLL_MicUpgradeFileImport_Req)
    BODY(mt::TString, src_path)


    /*<<导入麦克风升级文件响应>>
    * 消息流向 : service -> sdk
    * 参数 : err_code      是否成功 mt::EmFileCopyErr
    * see : Ev_MT_BLL_MicUpgradeFileImport_Req
	*/
    MESSAGE(Ev_MT_BLL_MicUpgradeFileImport_Rsp)
    BODY(mt::TS32, err_code)

    /*<<导入麦克风升级文件百分比>>
    * 消息流向 : service -> sdk
    * 参数 : progress      百分比
    * see : Ev_MT_BLL_MicUpgradeFileImport_Req
	*/
    MESSAGE(Ev_MT_BLL_MicUpgradeFileImportProgress_Ntf)
    BODY(mt::TU32, progress)








    /*<<目录结构查询请求>>
	* 消息流向 : sdk -> service
    * 参    数 : src_path   查询路径
    * see : Ev_MT_BLL_InquirePathStructure_Rsp
	*/
    MESSAGE(Ev_MT_BLL_InquirePathStructure_Req)
    BODY(mt::TString, src_path)

    /*<<目录结构查询响应>>
	* 消息流向 : service -> sdk
    * 参数 : src_path           查询路径
    *        path_detail_list   路径内容
    * see : Ev_MT_BLL_InquirePathStructure_Req
	*/
    MESSAGE(Ev_MT_BLL_InquirePathStructure_Rsp)
    BODY(mt::TString, src_path)
    BODY(mt::TMTPathStructureDetail, path_detail_list)

	/*<<EPLD/CPLD版本查询>>
	*消息流向 : sdk==>dispatch==>service
	*/
	MESSAGE(Ev_MT_BLL_PldVersion_Req)

	/*<<EPLD/CPLD版本查询>>
	*ver : 版本号
	*消息流向 : service==>dispatch==>sdk
	*/
	MESSAGE(Ev_MT_BLL_PldVersion_Rsp)
	BODY(mt::TU32, pld_ver)

	/*<<FPGA版本查询>>
	*消息流向 : sdk==>dispatch==>service
	*/
	MESSAGE(Ev_MT_BLL_FpgaVersion_Req)

	/*<<FPGA版本查询>>
	*ver : 版本号
	*消息流向 : service==>dispatch==>sdk
	*/
	MESSAGE(Ev_MT_BLL_FpgaVersion_Rsp)
	BODY(mt::TU32, fpga1_ver)
	BODY(mt::TU32, fpga2_ver)

	/*<<查询终端程序是否全部启动成功请求>>
	* 消息流向 : service -> mtmanage
    * see : Ev_MT_InquireHDMtStartSucess_Rsp
	*/
    MESSAGE(Ev_MT_BLL_InquireHDMtStartSucess_Req)

	/*<<查询终端程序是否全部启动成功响应>>
	* 消息流向 : mtmanage -> service
	* 参数 : sucess       成功/失败
    * see : Ev_MT_InquireHDMtStartSucess_Req
	*/
    MESSAGE(Ev_MT_BLL_InquireHDMtStartSucess_Rsp)
    BODY(mt::TBOOL32, sucess)

	/*<<终端程序全部启动成功通知>>
	* 消息流向 : mtmanage -> service
    * see : 
	*/
    MESSAGE(Ev_MT_BLL_HDMtStartSucess_Ntf)

	/*<<麦克风连接状态请求>>
	*消息流向 : sdk==>dispatch==>service
	*/
	MESSAGE(Ev_MT_BLL_MicrophoneConnectStatus_Req)

	/*<<麦克风连接状态应答>>
	*消息流向 : service==>dispatch==>sdk
	*/
	MESSAGE(Ev_MT_BLL_MicrophoneConnectStatus_Rsp)
	BODY(mt::TMTMicInfo, ConnectStatus)

	/*<<麦克风连接状态上报>>
	*消息流向 : service==>dispatch==>sdk
	*/
	MESSAGE(Ev_MT_BLL_MicrophoneConnectStatus_Ntf)
	BODY(mt::TMTMicInfo, ConnectStatus)

	/*<<麦克风无线电量请求>>
	*消息流向 : sdk==>dispatch==>service
	*/
	MESSAGE(Ev_MT_BLL_MicrophoneBatteryLevel_Req)

	/*<<麦克风无线电量应答>>
	*消息流向 : service==>dispatch==>sdk
	*/
	MESSAGE(Ev_MT_BLL_MicrophoneBatteryLevel_Rsp)
	BODY(mt::TMTMicInfo, BatteryLevel)

	/*<<麦克风无线电量上报>>
	*消息流向 : service==>dispatch==>sdk
	*/
	MESSAGE(Ev_MT_BLL_MicrophoneBatteryLevel_Ntf)
	BODY(mt::TMTMicInfo, BatteryLevel)

	/*<<无线麦克风电量过低（低于一格）上报>>
	*消息流向 : device==>dispatch==>sdk
	*/
	MESSAGE(Ev_MT_BLL_WirelessMicrophoneBatteryLow_Ntf)
	BODY(mt::TBOOL32, IsLow)

	/*<<通知/user/fileimg中的版本包已更新>>
	*消息流向 : service==>dispatch==>device
	*fileType: 需要重置的版本包 1: wind3d.bin.tar ; 2: skyshare_setup.tar
	*/
	MESSAGE(Ev_MT_BLL_ResetUserFileimg_Cmd)
	BODY(mt::TU32, fileType)

	/*<<麦克风升级状态请求>>
	*消息流向 : sdk==>dispatch==>service
	*/
	MESSAGE(Ev_MT_BLL_MicrophoneState_Req)

	/*<<麦克风升级状态应答(mt::TMicUpgradeStateList)>>
	*消息流向 : service==>dispatch==>sdk
	*/
	MESSAGE(Ev_MT_BLL_MicrophoneState_Rsp)
	BODY(mt::TMicUpgradeStateList, state)

	/*<<麦克风升级状态上报(mt::TMicUpgradeStateList)>>
	*消息流向 : service==>dispatch==>sdk
	*/
	MESSAGE(Ev_MT_BLL_MicrophoneState_Ntf)
	BODY(mt::TMicUpgradeStateList, state)

	/*<<麦克风上传命令(废弃)>>
	*消息流向 : service==>dispatch==>sdk
	*/
	MESSAGE(Ev_MT_BLL_MicrophoneUpload_Cmd)

	/*<<麦克风上传进度上报(废弃)>>
	*消息流向 : service==>dispatch==>sdk
	*/
	MESSAGE(Ev_MT_BLL_MicrophoneUpload_Ntf)
	BODY(mt::TU32, progress)

	/*<<麦克风安装命令(mt::TMicInstallList)>>
	*消息流向 : sdk==>dispatch==>service
	*/
	MESSAGE(Ev_MT_BLL_MicrophoneInstall_Cmd)
	BODY(mt::TMicInstallList, install)

	/*<<麦克风更新包上传状态请求(废弃)>>
	*消息流向 : sdk==>dispatch==>service
	*/
	MESSAGE(Ev_MT_BLL_MicrophoneVersionStatus_Req)

	/*<<麦克风更新包上传状态应答(废弃)>>
	*消息流向 : service==>dispatch==>sdk
	*/
	MESSAGE(Ev_MT_BLL_MicrophoneVersionStatus_Rsp)
	BODY(mt::TMTMicInfo, VersionStatus)

	/*<<麦克风更新包上传状态上报(废弃)>>
	*消息流向 : service==>dispatch==>sdk
	*/
	MESSAGE(Ev_MT_BLL_MicrophoneVersionStatus_Ntf)
	BODY(mt::TMTMicInfo, VersionStatus)

	/*<<麦克风升级命令(废弃)>>
	*消息流向 : sdk==>dispatch==>service
	*/
	MESSAGE(Ev_MT_BLL_MicrophoneUpgrade_Cmd)
	BODY(mt::TMTMicInfo, IsUpgrade)

	/*<<麦克风升级上报(废弃)>>
	*消息流向 : service==>dispatch==>sdk
	*/
	MESSAGE(Ev_MT_BLL_MicrophoneUpgrade_Ntf)
	BODY(mt::TMTMicInfo, UpgradeState)

	/*<<开启射频热点请求>>
	*消息流向 : sdk==>dispatch==>service
	*/
	MESSAGE(Ev_MT_BLL_OpenHotspot_Req)
	BODY(mt::TMTMicInfo, IsOpenHotspot)

	/*<<开启射频热点应答>>
	*消息流向 : service==>dispatch==>sdk
	*/
	MESSAGE(Ev_MT_BLL_OpenHotspot_Rsp)
	BODY(mt::TMTMicInfo, HotspotState)

	/*<<射频状态请求>>
	*消息流向 : sdk==>dispatch==>service
	*/
	MESSAGE(Ev_MT_BLL_Hotspot_State_Req)

	/*<<射频状态应答>>
	*消息流向 : service==>dispatch==>sdk
	*/
	MESSAGE(Ev_MT_BLL_Hotspot_State_Rsp)
	BODY(mt::TMTMicInfo, HotspotState)

	/*<<麦克风版本信息查询>>
	*消息流向 : sdk==>dispatch==>service
	*/
	MESSAGE(Ev_MT_BLL_MicrophoneInfo_Req)

	/*<<麦克风版本信息应答>>
	*消息流向 : service==>dispatch==>sdk
	*/
	MESSAGE(Ev_MT_BLL_MicrophoneInfo_Rsp)
	BODY(mt::TMicVersionList, VerInfo)

	/*<<麦克风版本信息上报>>
	*消息流向 : service==>dispatch==>sdk
	*/
	MESSAGE(Ev_MT_BLL_MicrophoneInfo_Ntf)
	BODY(mt::TMicVersionList, VerInfo)

	/*<<终端保存的麦克风版本信息查询>>
	*消息流向 : service==>dispatch==>deivce
	*/
    MESSAGE(Ev_MT_BLL_TermKeepMicrophoneInfo_Req)
	BODY( NULL , NULL )

	/*<<终端保存的麦克风版本信息查询>>
	*消息流向 : service==>dispatch==>deivce
	*/
    MESSAGE(Ev_MT_BLL_TermKeepMicrophoneInfo_Rsp)
	BODY( mt::TString , tstrTermKeepMicVer )

    /*<<查询设备含有E1模块数量请求>>
	*BODY ：    
	*传输方向：sdk->dispatch->mtservice
	* see Ev_MT_BLL_GetE1ModuleNum_Rsp
	*/
	MESSAGE(Ev_MT_BLL_GetE1ModuleNum_Req)

    /*<<x500设备，查询设备含有E1模块数量>>
	*E1Num : 0-不包含，4-包含；
	*消息流向 : mtservice==>dispatch==>sdk
	*/
	MESSAGE(Ev_MT_BLL_GetE1ModuleNum_Rsp)
	BODY(mt::TU32, E1Num)

    /*<<进入或退出生产测试>>
	* mtservice==>dispatch==>sdk
	*/
    MESSAGE(Ev_MT_BLL_MfgTestRegisterInOrOut_Ntf)
	BODY(mt::TBOOL32, register_state)	//是否登录

	/*<<Isp降噪请求>>
	*EmNFMode     :
	消息流向 : sdk==>dispatch==>mtservice
	*/
	MESSAGE(Ev_MT_BLL_IspImgInf_Noise_Req)

	/*<<Isp降噪应答>>
	*EmNFMode     :
	消息流向 : sdk<==dispatch<==mtservice
	*/
	MESSAGE(Ev_MT_BLL_IspImgInf_Noise_Rsp)
	BODY(mt::TU32, EmNFMode)

	/*<<Isp降噪设置>>
	*EmNFMode     :
	消息流向 : sdk==>dispatch==>mtservice
	*/
	MESSAGE(Ev_MT_BLL_IspImgInf_Noise_Cmd)
	BODY(mt::TU32, EmNFMode)

	/*<<Isp降噪上报>>
	*EmNFMode     :
	消息流向 : sdk<==dispatch<==mtservice
	*/
	MESSAGE(Ev_MT_BLL_IspImgInf_Noise_Ntf)
	BODY(mt::TU32, EmNFMode)

	
	/*<<Ispxd降噪请求>>
	*EmNFType     :降噪类型：0:2D; 1:3D
	消息流向 : sdk==>dispatch==>mtservice
	*/
	MESSAGE(Ev_MT_BLL_IspImgInf_xdNoise_Req)
	BODY(mt::TU32, EmNFType)

	/*<<Ispxd降噪应答>>
	*EmNFType     :
	*value：0-10：降噪等级
	消息流向 : sdk<==dispatch<==mtservice
	*/
	MESSAGE(Ev_MT_BLL_IspImgInf_xdNoise_Rsp)
	BODY(mt::TU32, EmNFType)
	BODY(mt::TU32, value)

	/*<<Ispxd降噪设置>>
	*EmNFType     :
	*value：0-10：降噪等级
	*vid_idx : EmCodecComponentIndex  em1st表示第一路  em2nd表示第二路
	消息流向 : sdk==>dispatch==>mtservice
	*/
	MESSAGE(Ev_MT_BLL_IspImgInf_xdNoise_Cmd)
	BODY(mt::TU32, EmNFType)
	BODY(mt::TU32, value)
	BODY(mt::TU32, vid_idx)

	/*<<Ispxd降噪上报>>
	*EmNFType     :
	*value：0-10：降噪等级
	*vid_idx : EmCodecComponentIndex  em1st表示第一路  em2nd表示第二路
    *reslt : 0成功，其他失败
	消息流向 : sdk<==dispatch<==mtservice
	*/
	MESSAGE(Ev_MT_BLL_IspImgInf_xdNoise_Ntf)
	BODY(mt::TU32, EmNFType)
	BODY(mt::TU32, value)
	BODY(mt::TU32, vid_idx)
    BODY(mt::TU32, result)

	/*<<Isp锐度请求>>
	*EmGeneralLevel     :
	消息流向 : sdk==>dispatch==>mtservice
	*/
	MESSAGE(Ev_MT_BLL_IspImgInf_Sharpness_Req)

	/*<<Isp锐度应答>>
	*EmGeneralLevel     :
	消息流向 : sdk<==dispatch<==mtservice
	*/
	MESSAGE(Ev_MT_BLL_IspImgInf_Sharpness_Rsp)
	BODY(mt::TU32, EmGeneralLevel)

	/*<<Isp锐度设置>>
	*EmGeneralLevel     :
	消息流向 : sdk==>dispatch==>mtservice
	*/
	MESSAGE(Ev_MT_BLL_IspImgInf_Sharpness_Cmd)
	BODY(mt::TU32, EmGeneralLevel)

	/*<<Isp锐度上报>>
	*EmGeneralLevel     :
	消息流向 : sdk<==dispatch<==mtservice
	*/
	MESSAGE(Ev_MT_BLL_IspImgInf_Sharpness_Ntf)
	BODY(mt::TU32, EmGeneralLevel)

	/*<<Isp锐度请求v2>>
	消息流向 : sdk==>dispatch==>mtservice
	*/
	MESSAGE(Ev_MT_BLL_IspImgInf_SharpnessV2_Req)

	/*<<Isp锐度应答v2>>
	*value：0-10     :等级
	消息流向 : sdk<==dispatch<==mtservice
	*/
	MESSAGE(Ev_MT_BLL_IspImgInf_SharpnessV2_Rsp)
	BODY(mt::TU32, value)

	/*<<Isp锐度设置v2>>
	*value：0-10     :
	*vid_idx : EmCodecComponentIndex  em1st表示第一路  em2nd表示第二路
	消息流向 : sdk==>dispatch==>mtservice
	*/
	MESSAGE(Ev_MT_BLL_IspImgInf_SharpnessV2_Cmd)
	BODY(mt::TU32, value)
	BODY(mt::TU32, vid_idx)

	/*<<Isp锐度上报v2>>
	*value：0-10     :
	*vid_idx : EmCodecComponentIndex  em1st表示第一路  em2nd表示第二路
    *result : 0成功，其他失败
	消息流向 : sdk<==dispatch<==mtservice
	*/
	MESSAGE(Ev_MT_BLL_IspImgInf_SharpnessV2_Ntf)
	BODY(mt::TU32, value)
	BODY(mt::TU32, vid_idx)
    BODY(mt::TU32, result)

	/*<<isp曝光增益请求>>
	*EmExposureModeGainType     :0:auto;1:manual
	消息流向 : sdk==>dispatch==>mtservice
	*/
	MESSAGE(Ev_MT_BLL_IspImgInf_ExposureGain_Req)
	BODY(mt::TU32, EmExposureModeGainType)

	/*<<Isp曝光增益应答>>
	*EmExposureModeGainType     :0:auto;1:manual
	*EmExposureModeGainRestrict：0-10
	消息流向 : sdk<==dispatch<==mtservice
	*/
	MESSAGE(Ev_MT_BLL_IspImgInf_ExposureGain_Rsp)
	BODY(mt::TU32, EmExposureModeGainType)
	BODY(mt::TU32, EmExposureModeGainRestrict)

	/*<<Isp曝光增益设置>>
	*EmExposureModeGainType     :0:auto;1:manual
	*EmExposureModeGainRestrict：0-10
	*vid_idx : EmCodecComponentIndex  em1st表示第一路  em2nd表示第二路
	消息流向 : sdk==>dispatch==>mtservice
	*/
	MESSAGE(Ev_MT_BLL_IspImgInf_ExposureGain_Cmd)
	BODY(mt::TU32, EmExposureModeGainType)
	BODY(mt::TU32, EmExposureModeGainRestrict)
	BODY(mt::TU32, vid_idx)

	/*<<Isp曝光增益上报>>
	*EmExposureModeGainType     :0:auto;1:manual
	*EmExposureModeGainRestrict：0-10
	*vid_idx : EmCodecComponentIndex  em1st表示第一路  em2nd表示第二路
    *result : 0成功，其他失败
	消息流向 : sdk<==dispatch<==mtservice
	*/
	MESSAGE(Ev_MT_BLL_IspImgInf_ExposureGain_Ntf)
	BODY(mt::TU32, EmExposureModeGainType)
	BODY(mt::TU32, EmExposureModeGainRestrict)
	BODY(mt::TU32, vid_idx)
    BODY(mt::TU32, result)

	/*<<isp白平衡手动模式增益请求>>
	*EMWBAModeGainType     :0:红;1:蓝
	消息流向 : sdk==>dispatch==>mtservice
	*/
	MESSAGE(Ev_MT_BLL_IspImgInf_WhiteBalanceGain_Req)
	BODY(mt::TU32, EMWBAModeGainType)

	/*<<Isp白平衡手动模式增益应答>>
	*EmExposureModeGainType     :0:红;1:蓝
	*：value：0-255
	消息流向 : sdk<==dispatch<==mtservice
	*/
	MESSAGE(Ev_MT_BLL_IspImgInf_WhiteBalanceGain_Rsp)
	BODY(mt::TU32, EMWBAModeGainType)
	BODY(mt::TU32, value)

	/*<<Isp白平衡手动模式增益设置>>
	*EmExposureModeGainType     :0:红;1:蓝
	*value：0-255
	*vid_idx : EmCodecComponentIndex  em1st表示第一路  em2nd表示第二路
	消息流向 : sdk==>dispatch==>mtservice
	*/
	MESSAGE(Ev_MT_BLL_IspImgInf_WhiteBalanceGain_Cmd)
	BODY(mt::TU32, EMWBAModeGainType)
	BODY(mt::TU32, value)
	BODY(mt::TU32, vid_idx)

	/*<<Isp白平衡手动模式增益上报>>
	*EmExposureModeGainType     :0:红;1:蓝
	*value：0-255
	*vid_idx : EmCodecComponentIndex  em1st表示第一路  em2nd表示第二路
    *result : 0成功，其他失败
	消息流向 : sdk<==dispatch<==mtservice
	*/
	MESSAGE(Ev_MT_BLL_IspImgInf_WhiteBalanceGain_Ntf)
	BODY(mt::TU32, EMWBAModeGainType)
	BODY(mt::TU32, value)
	BODY(mt::TU32, vid_idx)
    BODY(mt::TU32, result)

	//
	/*<<isp伽马请求>>
	消息流向 : sdk==>dispatch==>mtservice
	*/
	MESSAGE(Ev_MT_BLL_IspImgInf_Gamma_Req)

	/*<<Isp伽马应答>>
	*：value：0-4
	消息流向 : sdk<==dispatch<==mtservice
	*/
	MESSAGE(Ev_MT_BLL_IspImgInf_Gamma_Rsp)
	BODY(mt::TU32, value)

	/*<<Isp伽马设置>>
	*value：0-4
	消息流向 : sdk==>dispatch==>mtservice
	*/
	MESSAGE(Ev_MT_BLL_IspImgInf_Gamma_Cmd)
	BODY(mt::TU32, value)
	BODY(mt::TU32, vid_idx)

	/*<<Isp伽马上报>>
	*value：0-10
	消息流向 : sdk<==dispatch<==mtservice
	*/
	MESSAGE(Ev_MT_BLL_IspImgInf_Gamma_Ntf)
	BODY(mt::TU32, value)
	BODY(mt::TU32, vid_idx)
    BODY(mt::TU32, result)

	/*<<isp数字去雾请求>>
	消息流向 : sdk==>dispatch==>mtservice
	*/
	MESSAGE(Ev_MT_BLL_IspImgInf_Defog_Req)

	/*<<Isp数字去雾应答>>
	*：value：0-10
	消息流向 : sdk<==dispatch<==mtservice
	*/
	MESSAGE(Ev_MT_BLL_IspImgInf_Defog_Rsp)
	BODY(mt::TU32, value)

	/*<<Isp数字去雾设置>>
	*value：0-10
	消息流向 : sdk==>dispatch==>mtservice
	*/
	MESSAGE(Ev_MT_BLL_IspImgInf_Defog_Cmd)
	BODY(mt::TU32, value)

	/*<<Isp数字去雾上报>>
	*value：0-10
	消息流向 : sdk<==dispatch<==mtservice
	*/
	MESSAGE(Ev_MT_BLL_IspImgInf_Defog_Ntf)
	BODY(mt::TU32, value)

	/*<<isp数字宽动态开关请求>>
	消息流向 : sdk==>dispatch==>mtservice
	*/
	MESSAGE(Ev_MT_BLL_IspImgInf_DigDynSwitch_Req)

	/*<<Isp数字宽动态开关应答>>
	*：value：0：关;1:开
	消息流向 : sdk<==dispatch<==mtservice
	*/
	MESSAGE(Ev_MT_BLL_IspImgInf_DigDynSwitch_Rsp)
	BODY(mt::TBOOL32, value)

	/*<<Isp数字宽动态开关设置>>
	*value：0：关;1:开
	消息流向 : sdk==>dispatch==>mtservice
	*/
	MESSAGE(Ev_MT_BLL_IspImgInf_DigDynSwitch_Cmd)
	BODY(mt::TBOOL32, value)

	/*<<Isp数字宽动态开关上报>>
	*value：0：关;1:开
	消息流向 : sdk<==dispatch<==mtservice
	*/
	MESSAGE(Ev_MT_BLL_IspImgInf_DigDynSwitch_Ntf)
	BODY(mt::TBOOL32, value)

	/*<<isp数字宽动态等级请求>>
	消息流向 : sdk==>dispatch==>mtservice
	*/
	MESSAGE(Ev_MT_BLL_IspImgInf_DigDynLevel_Req)

	/*<<Isp数字宽动态等级应答>>
	*：value：0：0-100
	消息流向 : sdk<==dispatch<==mtservice
	*/
	MESSAGE(Ev_MT_BLL_IspImgInf_DigDynLevel_Rsp)
	BODY(mt::TU32, value)

	/*<<Isp数字宽动态等级设置>>
	*value：0：0-100
	消息流向 : sdk==>dispatch==>mtservice
	*/
	MESSAGE(Ev_MT_BLL_IspImgInf_DigDynLevel_Cmd)
	BODY(mt::TU32, value)

	/*<<Isp数字宽动态等级上报>>
	*value：0：0-100
	消息流向 : sdk<==dispatch<==mtservice
	*/
	MESSAGE(Ev_MT_BLL_IspImgInf_DigDynLevel_Ntf)
	BODY(mt::TU32, value)
	//

	/*<<isp背光补偿开关请求>>
	消息流向 : sdk==>dispatch==>mtservice
	*/
	MESSAGE(Ev_MT_BLL_IspImgInf_BackLightSwitch_Req)

	/*<<Isp背光补偿开关应答>>
	*：value：0：关;1:开
	消息流向 : sdk<==dispatch<==mtservice
	*/
	MESSAGE(Ev_MT_BLL_IspImgInf_BackLightSwitch_Rsp)
	BODY(mt::TBOOL32, value)

	/*<<Isp背光补偿开关设置>>
	*value：0：关;1:开
	消息流向 : sdk==>dispatch==>mtservice
	*/
	MESSAGE(Ev_MT_BLL_IspImgInf_BackLightSwitch_Cmd)
	BODY(mt::TBOOL32, value)

	/*<<Isp背光补偿开关上报>>
	*value：0：关;1:开
	消息流向 : sdk<==dispatch<==mtservice
	*/
	MESSAGE(Ev_MT_BLL_IspImgInf_BackLightSwitch_Ntf)
	BODY(mt::TBOOL32, value)

	/*<<isp背光补偿等级请求>>
	消息流向 : sdk==>dispatch==>mtservice
	*/
	MESSAGE(Ev_MT_BLL_IspImgInf_BackLightLevel_Req)

	/*<<Isp背光补偿等级应答>>
	*：value：0：0-15
	消息流向 : sdk<==dispatch<==mtservice
	*/
	MESSAGE(Ev_MT_BLL_IspImgInf_BackLightLevel_Rsp)
	BODY(mt::TU32, value)

	/*<<Isp背光补偿等级设置>>
	*value：0：0-15
	消息流向 : sdk==>dispatch==>mtservice
	*/
	MESSAGE(Ev_MT_BLL_IspImgInf_BackLightLevel_Cmd)
	BODY(mt::TU32, value)

	/*<<Isp背光补偿等级上报>>
	*value：0：0-15
	消息流向 : sdk<==dispatch<==mtservice
	*/
	MESSAGE(Ev_MT_BLL_IspImgInf_BackLightLevel_Ntf)
	BODY(mt::TU32, value)

	/*<<Isp感光度请求>>
	*EmISO      :
	消息流向 : sdk==>dispatch==>mtservice
	*/
	MESSAGE(Ev_MT_BLL_IspImgInf_ISO_Req)

	/*<<Isp感光度应答>>
	*EmISO      :
	消息流向 : sdk<==dispatch<==mtservice
	*/
	MESSAGE(Ev_MT_BLL_IspImgInf_ISO_Rsp)
	BODY(mt::TU32, EmISO)

	/*<<Isp感光度设置>>
	*EmISO      :
	消息流向 : sdk==>dispatch==>mtservice
	*/
	MESSAGE(Ev_MT_BLL_IspImgInf_ISO_Cmd)
	BODY(mt::TU32, EmISO)

	/*<<Isp感光度上报>>
	*EmISO      :
	消息流向 : sdk<==dispatch<==mtservice
	*/
	MESSAGE(Ev_MT_BLL_IspImgInf_ISO_Ntf)
	BODY(mt::TU32, EmISO)

	/*<<Isp曝光模式请求>>
	*EmExposureMode      :
	消息流向 : sdk==>dispatch==>mtservice
	*/
	MESSAGE(Ev_MT_BLL_IspImgInf_ExposureMode_Req)

	/*<<Isp曝光模式应答>>
	*EmExposureMode      :
	消息流向 : sdk<==dispatch<==mtservice
	*/
	MESSAGE(Ev_MT_BLL_IspImgInf_ExposureMode_Rsp)
	BODY(mt::TU32, EmExposureMode)

	/*<<Isp曝光模式设置>>
	*EmExposureMode      :
    *vid_idx : EmCodecComponentIndex  em1st表示第一路  em2nd表示第二路
	消息流向 : sdk==>dispatch==>mtservice
	*/
	MESSAGE(Ev_MT_BLL_IspImgInf_ExposureMode_Cmd)
	BODY(mt::TU32, EmExposureMode)
    BODY(mt::TU32, vid_idx)

	/*<<Isp曝光模式上报>>
	*EmExposureMode      :
    *vid_idx : EmCodecComponentIndex  em1st表示第一路  em2nd表示第二路
    *result
	消息流向 : sdk<==dispatch<==mtservice
	*/
	MESSAGE(Ev_MT_BLL_IspImgInf_ExposureMode_Ntf)
	BODY(mt::TU32, EmExposureMode)
    BODY(mt::TU32, vid_idx)
    BODY(mt::TU32, result)

    /*<<图像模式设置>>
    *vid_idx : EmCodecComponentIndex  em1st表示第一路  em2nd表示第二路
	*EmImgMode      :
	消息流向 : sdk==>dispatch==>mtservice
	*/
	MESSAGE(Ev_MT_BLL_HD_SetCameraImgMode_Cmd)
	BODY(mt::TU32, EmImgMode)
    BODY(mt::TU32, vid_idx)

	/*<<图像模式上报>>
	*EmImgMode      :
    *vid_idx : EmCodecComponentIndex  em1st表示第一路  em2nd表示第二路
    *result
	消息流向 : sdk<==dispatch<==mtservice
	*/
	MESSAGE(Ev_MT_BLL_HD_SetCameraImgMode_Ntf)
	BODY(mt::TU32, EmImgMode)
    BODY(mt::TU32, vid_idx)
    BODY(mt::TU32, result)

    /*<<人物优先设置>>
	*EmPerson      :
    *vid_idx : EmCodecComponentIndex  em1st表示第一路  em2nd表示第二路
	消息流向 : sdk==>dispatch==>mtservice
	*/
	MESSAGE(Ev_MT_BLL_HD_SetCameraPersonFirst_Cmd)
	BODY(mt::TU32, EmPerson)
    BODY(mt::TU32, vid_idx)

	/*<<人物优先上报>>
	*EmPerson      :
    *vid_idx : EmCodecComponentIndex  em1st表示第一路  em2nd表示第二路
    *result
	消息流向 : sdk<==dispatch<==mtservice
	*/
	MESSAGE(Ev_MT_BLL_HD_SetCameraPersonFirst_Ntf)
	BODY(mt::TU32, EmPerson)
    BODY(mt::TU32, vid_idx)
    BODY(mt::TU32, result)

    /*<<摄像机亮度直接设置>>
	*value      : 0-100
    *vid_idx : EmCodecComponentIndex  em1st表示第一路  em2nd表示第二路
	消息流向 : sdk==>dispatch==>mtservice
	*/
	MESSAGE(Ev_MT_BLL_HD_DeviceCameraBrightDirectSet_Cmd)
	BODY(mt::TU32, value)
    BODY(mt::TU32, vid_idx)

	/*<<摄像机亮度直接设置上报>>
	*value      : 0-100
    *vid_idx : EmCodecComponentIndex  em1st表示第一路  em2nd表示第二路
	消息流向 : sdk<==dispatch<==mtservice
	*/
	MESSAGE(Ev_MT_BLL_HD_DeviceCameraBrightDirectSet_Ntf)
	BODY(mt::TU32, value)
    BODY(mt::TU32, vid_idx)

	/*<<Isp光圈大小请求>>
	*EmAperture      :
	消息流向 : sdk==>dispatch==>mtservice
	*/
	MESSAGE(Ev_MT_BLL_IspImgInf_Aperture_Req)

	/*<<Isp光圈大小应答>>
	*EmAperture      :
	消息流向 : sdk<==dispatch<==mtservice
	*/
	MESSAGE(Ev_MT_BLL_IspImgInf_Aperture_Rsp)
	BODY(mt::TU32, EmAperture)

	/*<<Isp光圈大小设置>>
	*EmAperture      :
	*vid_idx : EmCodecComponentIndex  em1st表示第一路  em2nd表示第二路
	消息流向 : sdk==>dispatch==>mtservice
	*/
	MESSAGE(Ev_MT_BLL_IspImgInf_Aperture_Cmd)
	BODY(mt::TU32, EmAperture)
	BODY(mt::TU32, vid_idx)

	/*<<Isp光圈大小上报>>
	*EmAperture      :
	*vid_idx : EmCodecComponentIndex  em1st表示第一路  em2nd表示第二路
    *result : 0成功，其他失败
	消息流向 : sdk<==dispatch<==mtservice
	*/
	MESSAGE(Ev_MT_BLL_IspImgInf_Aperture_Ntf)
	BODY(mt::TU32, EmAperture)
	BODY(mt::TU32, vid_idx)
    BODY(mt::TU32, result)

	/*<<Isp快门速度请求>>
	*EmAperture      :
	消息流向 : sdk==>dispatch==>mtservice
	*/
	MESSAGE(Ev_MT_BLL_IspImgInf_Shutter_Req)

	/*<<Isp快门速度应答>>
	*EmAperture      :
	消息流向 : sdk<==dispatch<==mtservice
	*/
	MESSAGE(Ev_MT_BLL_IspImgInf_Shutter_Rsp)
	BODY(mt::TU32, EmShutterLevel)

	/*<<Isp快门速度设置>>
	*EmAperture      :
	*vid_idx : EmCodecComponentIndex  em1st表示第一路  em2nd表示第二路
	消息流向 : sdk==>dispatch==>mtservice
	*/
	MESSAGE(Ev_MT_BLL_IspImgInf_Shutter_Cmd)
	BODY(mt::TU32, EmShutterLevel)
	BODY(mt::TU32, vid_idx)

	/*<<Isp快门速度上报>>
	*EmAperture      :
	*vid_idx : EmCodecComponentIndex  em1st表示第一路  em2nd表示第二路
    *result : 0成功，其他失败
	消息流向 : sdk<==dispatch<==mtservice
	*/
	MESSAGE(Ev_MT_BLL_IspImgInf_Shutter_Ntf)
	BODY(mt::TU32, EmShutterLevel)
	BODY(mt::TU32, vid_idx)
    BODY(mt::TU32, result)

	/*<<设置Isp亮度>>
	*曝光为自动模式亮度调节才生效，曝光为手动模式下亮度调节无效
	*EmBrightnessDirection:
	消息流向 : sdk==>dispatch==>mtservice
	*/
	MESSAGE(Ev_MT_BLL_IspImgInf_Brightnesss_Cmd)
	BODY(mt::TU32, EmBrightnessDirection)

	/*<<Isp白平衡请求>>
	*EmWBAMode      :
	消息流向 : sdk==>dispatch==>mtservice
	*/
	MESSAGE(Ev_MT_BLL_IspImgInf_WhiteBalance_Req)
	BODY(mt::TU32, EmWBAMode)

	/*<<Isp白平衡应答>>
	*EmWBAMode      :
	消息流向 : sdk<==dispatch<==mtservice
	*/
	MESSAGE(Ev_MT_BLL_IspImgInf_WhiteBalance_Rsp)
	BODY(mt::TU32, EmWBAMode)

	/*<<Isp白平衡设置>>
	*EmWBAMode      :
	*vid_idx : EmCodecComponentIndex  em1st表示第一路  em2nd表示第二路
	消息流向 : sdk==>dispatch==>mtservice
	*/
	MESSAGE(Ev_MT_BLL_IspImgInf_WhiteBalance_Cmd)
	BODY(mt::TU32, EmWBAMode)
	BODY(mt::TU32, vid_idx)

	/*<<Isp白平衡上报>>
	*EmWBAMode      :
	*vid_idx : EmCodecComponentIndex  em1st表示第一路  em2nd表示第二路
    *result : 0成功，其他失败
	消息流向 : sdk<==dispatch<==mtservice
	*/
	MESSAGE(Ev_MT_BLL_IspImgInf_WhiteBalance_Ntf)
	BODY(mt::TU32, EmWBAMode)
	BODY(mt::TU32, vid_idx)
    BODY(mt::TU32, result)

        /*<<选择串口供网呈使用>>
	* sdk -> service_hd
	*/
	MESSAGE(Ev_MT_BLL_ChooseSerialUse_Cmd)
	BODY(mt::TMTHDSerialCtrl, serial_use)	//串口配置
    BODY(mt::TBOOL32, serial_use)	//是否使用

	/*<<选择串口供网呈使用响应>>
	* service_hd -> sdk
	*/
	MESSAGE(Ev_MT_BLL_ChooseSerialUse_Ntf)
    BODY(mt::TMTHDSerialCtrl, serial_use)	//串口配置
    BODY(mt::TBOOL32, serial_use)	//是否使用
    BODY(mt::TS32, result)    //处理结果

    /*<<选择串口供网呈使用>>
	* sdk -> service_hd
	*/
	MESSAGE(Ev_MT_BLL_OperaterSerial_Cmd)
    BODY(mt::TSerialOptParam, serial_info)	//读写信息

	/*<<选择串口供网呈使用响应>>
	* service_hd -> sdk
	*/
	MESSAGE(Ev_MT_BLL_OperaterSerial_Ntf)
    BODY(mt::TSerialOptParam, serial_info)	//读写信息
    BODY(mt::TS32, result)    //处理结果

	/*<<更新detectserver的配置>>
	消息流向 : sdk==>dispatch==>mtservice_hd
	*/
	MESSAGE(Ev_MT_BLL_UpdateDetectserverCfg_Cmd)
	
	/*<<摄像机操作异常响应>>
	* service_hd -> sdk
	*/
	MESSAGE(Ev_MT_BLL_DeviceCameraOptError_Ntf)
    BODY(mt::TU32, vid_idx)   //摄像机No
    BODY(mt::TU32, result)    //通知类型
	
	/*<<摄像机场景模式能力获取>>
	* service_hd -> device
	*/
	MESSAGE(Ev_MT_BLL_DeviceCameraSceneMode_Req)
    BODY(mt::TU32, vid_idx)   //摄像机No
	
	/*<<摄像机场景模式能力获取响应>>
	* device -> service_hd
	*/
	MESSAGE(Ev_MT_BLL_DeviceCameraSceneMode_Rsp)
    BODY(mt::TU32, vid_idx)   //摄像机No
	BODY(mt::TCameraSceneModeCapList, scenecap)   //场景模式能力
	
	/*<<摄像机场景模式能力设置>>
	* service_hd -> device
	*/
	MESSAGE(Ev_MT_BLL_DeviceCameraSceneMode_Cmd)
    BODY(mt::TU32, vid_idx)   //摄像机No
	BODY(mt::TU32, EmCameraSceneMode)   //场景模式
	
	/*<<摄像机场景模式能力设置响应>>
	* device -> service_hd
	*/
	MESSAGE(Ev_MT_BLL_DeviceCameraSceneMode_Ntf)
    BODY(mt::TU32, vid_idx)   //摄像机No
	BODY(mt::TU32, EmCameraSceneMode)   //场景模式
	BODY(mt::TU32, result)   //结果
	
	/*<<网口流量请求>>
	*消息流向 : sdk==>dispatch==>service
	*/
    MESSAGE(Ev_MT_BLL_DeviceNetCardStatis_Req)

    /*<<网口流量回应>>
    *NetCardStatisList : mt::TNetCardStatisList  网口流量信息
	*消息流向 : service==>dispatch==>sdk
	*/
    MESSAGE(Ev_MT_BLL_DeviceNetCardStatis_Rsp)
    BODY(mt::TNetCardStatisList, NetCardStatisList)
	
	/*<<导出诊断信息文件请求>>
	* sdk -> service
	*/
	MESSAGE(Ev_MT_BLL_ExportDiagInfo_Cmd)
	BODY(mt::TString, export_file_path)	//文件导出路径

	/*<<导出诊断信息文件进度通知>>
	* service -> sdk
	*/
	MESSAGE(Ev_MT_BLL_ExportDiagInfoProgress_Ntf)
	BODY(mt::TU32, percent)	//整体百分比


	/*<<导出诊断信息文件响应>>
	* service -> sdk
	*/
	MESSAGE(Ev_MT_BLL_ExportDiagInfo_Ntf)
	BODY(mt::TU32, is_ok)	//MT_SUCCESS:成功
							//ERR_MTMISC_DISK_OUTOF_SPACE 空间不足
							//ERR_MTMISC_FILE_NOT_EXIST  文件不存在
	BODY(mt::TString, export_file_path)	//文件导出路径

	/*<<摄像机控制方式通知>>
	* service_hd -> sdk
	*/
	MESSAGE(Ev_MT_BLL_DeviceCameraCtrlType_Ntf)
    BODY(mt::TU32, EmCameraCtrlType)    //通知类型

    /*<<除雾>>
	* service_hd <- sdk
	*/
    MESSAGE(Ev_MT_BLL_ElectricFan_Cmd)
    BODY(mt::TBOOL32, tBOOL32)

    /*<<除雾>>
	* service_hd -> sdk
	*/
    MESSAGE(Ev_MT_BLL_ElectricFan_Ntf)
    BODY(mt::TBOOL32, tBOOL32)

    /*<<除雾时间>>
	* service_hd <- sdk
	*/
    MESSAGE(Ev_MT_BLL_GetElectricFanTime_Req)

    /*<<除雾时间>>
	* service_hd -> sdk
	*/
    MESSAGE(Ev_MT_BLL_GetElectricFanTime_Rsp)
    BODY(mt::TU32, value)
	
	/*<<设置智能摄像机配置>>
	* service_hd <- sdk
	*/
	MESSAGE(Ev_MT_BLL_SetAiCamera_Cmd)
	BODY(mt::TMTHDCameraAiList, value)
	
	/*<<设置智能摄像机配置>>
	* service_hd -> sdk
	*/
	MESSAGE(Ev_MT_BLL_SetAiCamera_Ntf)
	
	/*<<人数统计>>
	* service_hd -> sdk
	*/
	MESSAGE(Ev_MT_BLL_PeopleCountingResult_Ntf)
	BODY(mt::TU32, tCamIdx)
	BODY(mt::TU32, value)
	
	/*<<人脸签到>>
	* service_hd -> sdk
	*/
	MESSAGE(Ev_MT_BLL_FaceCheckInInfo_Ntf)
	BODY(mt::TU32, tCamIdx)
	BODY(mt::TMTFaceCheckInList, value)

	 /*<<清理升级包存储空间的命令>>
	* device <- sdk
	*/
    MESSAGE(Ev_MT_BLL_UploadZip_Cmd)

    /*<<清理升级包存储空间的通知>>
	* device -> sdk
	*/
    MESSAGE(Ev_MT_BLL_UploadZip_Ntf)

#if !defined(_MESSAGE_HELP_)
    EV_BLL_END(DEVICE) = EVSEG_BLL_DEVICE_END
};
#endif

#define Is_BLL_Device_Msg(m) ((m) >= EV_BLL_BGN(DEVICE) && (m) <= EV_BLL_END(DEVICE))

#endif
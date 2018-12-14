#ifndef _MTDEVICEMSG_H_
#define _MTDEVICEMSG_H_

#include "mtmsgid.h"

#if !defined(_MESSAGE_HELP_)
enum EmMtDeviceMsg
{
    EV_BGN(DEVICE) = EVSEG_DEVICE_BGN,
#endif
	/*********************************摄像头相关消息Begin***************************************/

	/*<<摄像头参数配置>>
    *TMTHDCameraList : 摄像头参数配置
	*消息流向 : service==>mtdeivce
	*/
	MESSAGE(Ev_MT_DeviceSetCameraList_Cmd)
	BODY(mt::TMTHDCameraList, camera_list)

    /*<<摄像头句柄配置>>
    *vid_idx : EmCodecComponentIndex  em1st表示第一路  em2nd表示第二路
	*camera_idx : 摄像头编号
    *camera_handle : 摄像头串口操作句柄
	*消息流向 : mtdeivce内部线程使用
	*/
    MESSAGE(Ev_MT_DeviceSetCameraHandle_Cmd)
    BODY(mt::TU32, vid_idx)
	BODY(mt::TU8, camera_idx)
	BODY(mt::TU32, camera_handle)

    /*<<摄像头选择>>
    *vid_idx : EmCodecComponentIndex  em1st表示第一路  em2nd表示第二路  em3rd表示第二路
	*vid_port : EmMtVideoPort
	*消息流向 : service==>dispatch==>deivce
	*/
    MESSAGE(Ev_MT_DeviceCameraSelect_Cmd)
    BODY(mt::TU32, vid_idx)
	BODY(mt::TU32, vid_port)

    /*<<摄像头待机\唤醒>>
    *opt : TRUE表示待机 FALSE表示唤醒
	*消息流向 : service==>dispatch==>deivce
	*/
    MESSAGE(Ev_MT_DeviceCameraPower_Cmd)
	BODY(mt::TBOOL32, opt)

	/*<<摄像机关机>>
	*消息流向 : device==>dispatch==>deivce
	*/
    MESSAGE(Ev_MT_DevicePowerOff_Cmd)

    /*<<摄像头预置位操作>>
    *vid_idx : EmCodecComponentIndex  em1st表示第一路  em2nd表示第二路
	*opt : TRUE表示保存 FALSE表示调用
    *index : 当前操作的预置位索引
	*消息流向 : service==>dispatch==>deivce
	*/
    MESSAGE(Ev_MT_DeviceCameraPreset_Req)
    BODY(mt::TU32, vid_idx)
	BODY(mt::TBOOL32, opt)
	BODY(mt::TU8, index)

    /*<<摄像头预置位操作响应,收到此消息表示操作结束,结束不表示一定操作成功>>
    *vid_idx : EmCodecComponentIndex  em1st表示第一路  em2nd表示第二路
	*opt : TRUE表示保存 FALSE表示调用
    *index : 当前操作的预置位索引
	*消息流向 : mtdevice==>dispatch==>mtservice
	*/
    MESSAGE(Ev_MT_DeviceCameraPreset_Rsp)
    BODY(mt::TU32, vid_idx)
	BODY(mt::TBOOL32, opt)
    BODY(mt::TU8, index)
	BODY(mt::TBOOL32, sucess)

    /*<<查询预置位图片请求>>
    *vid_idx : EmCodecComponentIndex  em1st表示第一路  em2nd表示第二路
	*消息流向 : mtservice==>dispatch==>mtdevice
	*see Ev_MT_DeviceQueryCameraPresetPic_Rsp
	*/
    MESSAGE(Ev_MT_DeviceQueryCameraPresetPic_Req)
    BODY(mt::TU32, vid_idx)

    /*<<查询预置位图片响应>>
    *vid_idx : EmCodecComponentIndex  em1st表示第一路  em2nd表示第二路
	*TMTCameraPresetPicList : 当前操作的预置位索引
	*消息流向 : mtdevice==>dispatch==>mtservice
	*see Ev_MT_DeviceQueryCameraPresetPic_Req
	*/
    MESSAGE(Ev_MT_DeviceQueryCameraPresetPic_Rsp)
    BODY(mt::TU32, vid_idx)
	BODY(mt::TMTCameraPresetPicList, pic_name)

    /*<<摄像头方位调节>>
    *vid_idx : EmCodecComponentIndex  em1st表示第一路  em2nd表示第二路
	*direction : EmDirection
    *action : EmAction
	*消息流向 : service==>dispatch==>deivce
	*/
    MESSAGE(Ev_MT_DeviceCameraPantilt_Cmd)
    BODY(mt::TU32, vid_idx)
	BODY(mt::TS32, direction) //枚举值统一使用mt::TS32来传输，该处实际为mt::EmDirection
	BODY(mt::TS32, action)   //枚举值统一使用mt::TS32来传输，该处实际为mt::EmAction

    /*<<摄像头焦距调节>>
    *vid_idx : EmCodecComponentIndex  em1st表示第一路  em2nd表示第二路
	*opt : TRUE表示远距 FALSE表示近距
    *action : EmAction
	*消息流向 : service==>dispatch==>deivce
	*/
    MESSAGE(Ev_MT_DeviceCameraFocus_Cmd)
    BODY(mt::TU32, vid_idx)
	BODY(mt::TBOOL32, opt)
	BODY(mt::TS32, action) //枚举值统一使用mt::TS32来传输，该处实际为mt::EmAction

	/*<<摄像头自动聚焦>>
    *vid_idx : EmCodecComponentIndex  em1st表示第一路  em2nd表示第二路
	*消息流向 : service==>dispatch==>deivce
	*/
    MESSAGE(Ev_MT_DeviceCameraAutoFocus_Cmd)
    BODY(mt::TU32, vid_idx)

    /*<<摄像头视野调节>>
    *vid_idx : EmCodecComponentIndex  em1st表示第一路  em2nd表示第二路
	*opt : TRUE表示远视 FALSE表示近视
    *action : EmAction
	*消息流向 : service==>dispatch==>deivce
	*/
    MESSAGE(Ev_MT_DeviceCameraZoom_Cmd)
    BODY(mt::TU32, vid_idx)
	BODY(mt::TBOOL32, opt)  
	BODY(mt::TS32, action) //枚举值统一使用mt::TS32来传输，该处实际为mt::EmAction

    /*<<摄像头亮度调节>>
    *vid_idx : EmCodecComponentIndex  em1st表示第一路  em2nd表示第二路
	*opt : TRUE表示增大 FLASE表示减小
    *action : EmAction
	*消息流向 : service==>dispatch==>deivce
	*/
    MESSAGE(Ev_MT_DeviceCameraBright_Cmd)
    BODY(mt::TU32, vid_idx)
	BODY(mt::TBOOL32, opt)
	BODY(mt::TS32, action) //枚举值统一使用mt::TS32来传输，该处实际为mt::EmAction
	
	/*<<摄像头亮度调节>>
    *vid_idx : EmCodecComponentIndex  em1st表示第一路  em2nd表示第二路
	*value : 设置的亮度值
	*消息流向 : service==>dispatch==>deivce
	*/
    MESSAGE(Ev_MT_DeviceCameraBrightDirectSet_Cmd)
    BODY(mt::TU32, vid_idx)
	BODY(mt::TU32, value)  // 设置的值

    /*<<摄像头亮度调节回应>>
    *vid_idx : EmCodecComponentIndex  em1st表示第一路  em2nd表示第二路
	*value : 设置的亮度值
	*消息流向 : deivce==>dispatch==>service
	*/
    MESSAGE(Ev_MT_DeviceCameraBrightDirectSet_Ntf)
    BODY(mt::TU32, vid_idx)
	BODY(mt::TU32, value)  // 设置的值
    BODY(mt::TU32, result)

    /*<<摄像头背光补偿>>
    *vid_idx : EmCodecComponentIndex  em1st表示第一路  em2nd表示第二路
    *on : TRUE表示开启 FALSE表示关闭
	*消息流向 : service==>dispatch==>deivce
	*/
    MESSAGE(Ev_MT_DeviceCameraBackLight_Cmd)
    BODY(mt::TU32, vid_idx)
	BODY(mt::TBOOL32, on)

    /*<<摄像头升级>>
    *vid_idx : EmMtVideoPort  接入摄像机的视频源接口
	*camera_type : 升级摄像头类型
	*action : TRUE表示开始 FLASE表示停止
	*file_name : 升级文件名路径
	*消息流向 : service==>dispatch==>deivce
	*/
    MESSAGE(Ev_MT_DeviceCameraUpgrade_Cmd)
    BODY(mt::TU32, vid_idx)
	BODY(mt::TMTCameraUpgrade, camera_upgrade)

    /*<<摄像头升级>>
    *vid_idx : EmMtVideoPort  接入摄像机的视频源接口
	*type : EmEquipmentUpgrading
	*result : TRUE表示成功 FALSE表示失败
	*消息流向 : device==>dispatch==>service
	*/
    MESSAGE(Ev_MT_DeviceCameraUpgrade_Ntf)
    BODY(mt::TU32, vid_idx)
	BODY(mt::TS32, type) //枚举值统一使用mt::TS32来传输，该处实际为mt::EmEquipmentUpgrading
	BODY(mt::TS32, error)//枚举值统一使用mt::TS32来传输，该处实际为mt::EmCameraUpgradeErrCode

	/*<<摄像头版本查询>>
    *vid_idx : EmCodecComponentIndex  em1st表示第一路  em2nd表示第二路
	*消息流向 : service==>dispatch==>deivce
	*/
    MESSAGE(Ev_MT_DeviceCameraVersion_Req)
    BODY(mt::TU32, vid_idx)

    /*<<摄像头版本查询>>
    *vid_idx : EmCodecComponentIndex  em1st表示第一路  em2nd表示第二路
	*camera_ver_info : 摄像头版本信息
	*消息流向 : device==>dispatch==>service
	*/
    MESSAGE(Ev_MT_DeviceCameraVersion_Rsp)
    BODY(mt::TU32, vid_idx)
	BODY(mt::TString, camera_ver_info)


    /*<<摄像头能力类型查询>>
	*消息流向 : service==>dispatch==>device
    *see : Ev_MT_DeviceCameraTypeCapset_Rsp
	*/
	MESSAGE(Ev_MT_DeviceGetCameraTypeCapset_Req)


    /*<<摄像头能力类型上报>>
	*camera_type_list : 所有支持的摄像头能力类型查询结果
	*消息流向 : device==>dispatch==>service
    *see : Ev_MT_DeviceCameraTypeCapset_Req
	*/
	MESSAGE(Ev_MT_DeviceGetCameraTypeCapset_Rsp)
	BODY(mt::TMTCameraTypeList, camera_type_list)


	/*<<摄像头能力类型上报>>
	*camera_type_list : 所有支持的摄像头能力类型上报
	*消息流向 : device==>dispatch==>service
	*/
	MESSAGE(Ev_MT_DeviceCameraTypeCapset_Ntf)
	BODY(mt::TMTCameraTypeList, camera_type_list)

	/*<<摄像头操作状态>>
	*opt_idx : 操作的类型编号
	*opt_state : 操作的状态
	*消息流向 : mtdevice内部线程使用
	*/
	MESSAGE(Ev_MT_DeviceCameraOpt_Ntf)
	BODY(mt::TU8, opt_idx)
	BODY(mt::TBOOL32, opt_state)

    /*<<摄像机类型检测>>
	*消息流向 : deivce==>camera
	*/
    MESSAGE(Ev_MT_DeviceCameraTypeCheck_Cmd)

   /*********************************摄像头相关消息End***************************************/



   /*********************************遥控器相关消息Begin************************************/

   /*<<遥控器按键通知>>
   *key_type : TRUE表示keyup  FALSE表示keydown
   *key_source : 按键来源
   *key_code : 按键键值
   *key_count : 按键次数
   *消息流向 : device==>dispatch==>service
   */
   MESSAGE(Ev_MT_DeviceKeyCodeNtf)
   BODY(mt::TMTKeyPressInfo, key_press_info)

   /*<<实体遥控器按键通知(网呈使用)>>
   *key_type : TRUE表示keyup  FALSE表示keydown
   *key_source : 按键来源
   *key_code : 按键键值
   *key_count : 按键次数
   *消息流向 : device==>dispatch==>service
   */
   MESSAGE(Ev_MT_EntityDeviceKeyCodeNtf)
   BODY(mt::TMTKeyPressInfo, key_press_info)
   
   /*********************************遥控器相关消息End************************************/

   	/*<<串口配置参数>>
	*uart_cfg : 串口配置信息
	*消息流向 : service==>mtdevice
	*/
	MESSAGE(Ev_MT_DeviceSerialCtrlCfg_Cmd)
	BODY(mt::TMTHDSerialCtrl, uart_cfg)

   	/*<<数字mic升级>>
	*uart_num : 串口设备号
	*path : 升级文件路径
	*消息流向 : service==>dispatch==>device
	*/
    MESSAGE(Ev_MT_DeviceDMicUpgrade_Cmd)
	BODY(mt::TS32, uart_num)					//枚举值统一使用mt::TS32来传输，该处实际为mt::EmUartNum
	BODY(mt::TString, path)

	/*<<数字mic升级>>
	*uart_num : 串口设备号
	*result : 升级结果 TRUE表示升级成功
	*消息流向 : deivce==>dispatch==>service
	*/
	MESSAGE(Ev_MT_DeviceDMicUpgrade_Ntf)
	BODY(mt::TS32, uart_num)				   //枚举值统一使用mt::TS32来传输，该处实际为mt::EmUartNum
	BODY(mt::TBOOL32, result)

	/*<<数字mic版本查询>>
	*uart_num : 串口设备号
	*消息流向 : service==>dispatch==>device
	*/
	MESSAGE(Ev_MT_DeviceDMicVersion_Req)
	BODY(mt::TS32, uart_num)				  //枚举值统一使用mt::TS32来传输，该处实际为mt::EmUartNum

	/*<<数字mic版本查询>>
	*uart_num : 串口设备号
	*ver : 版本号
	*消息流向 : device==>dispatch==>service
	*/
	MESSAGE(Ev_MT_DeviceDMicVersion_Rsp)
	BODY(mt::TS32, uart_num)				 //枚举值统一使用mt::TS32来传输，该处实际为mt::EmUartNum
	BODY(mt::TString, ver)

	/*<<无线mic升级>>
	*uart_num : 串口设备号
	*path : 升级文件路径
	*消息流向 : service==>dispatch==>device
	*/
    MESSAGE(Ev_MT_DeviceWMicUpgrade_Cmd)
	BODY(mt::TS32, uart_num)
	BODY(mt::TString, path)

	/*<<无线mic升级>>
	*uart_num : 串口设备号
	*result : 升级结果 TRUE表示升级成功
	*消息流向 : deivce==>dispatch==>service
	*/
	MESSAGE(Ev_MT_DeviceWMicUpgrade_Ntf)
	BODY(mt::TS32, uart_num)
	BODY(mt::TBOOL32, result)

	/*<<无线mic版本查询>>
	*uart_num : 串口设备号
	*消息流向 : service==>dispatch==>device
	*/
	MESSAGE(Ev_MT_DeviceWMicVersion_Req)
	BODY(mt::TS32, uart_num)

	/*<<无线mic版本查询>>
	*uart_num : 串口设备号
	*ver : 版本号
	*消息流向 : device==>dispatch==>service
	*/
	MESSAGE(Ev_MT_DeviceWMicVersion_Rsp)
	BODY(mt::TS32, uart_num)
	BODY(mt::TString, ver)

	/*<<串口码值上报消息>>
	*uart_type : 串口类型
	*code : 单字节码值
	*消息流向 : deivce内部
	*/
	MESSAGE(Ev_MT_DeviceSerialRecvByte_Ntf)
	BODY(mt::TU8, uart_type)
	BODY(mt::TU8, code)

	/*<<串口空值上报消息>>
	*uart_type : 串口类型
	*消息流向 : deivce内部
	*/
	MESSAGE(Ev_MT_DeviceSerialRecvNone_Ntf)
	BODY(mt::TU8, uart_type)

	/*<<查询cpu和内存使用情况命令>>
	*消息流向 : service==>device
	* see Ev_MT_DeviceDetectCpuAndMem_Rsp
	*/
	MESSAGE(Ev_MT_DeviceDetectCpuAndMem_Req)

	/*<<查询cpu和内存使用情况响应>>
	*cpuandmemsts : cpu和内存使用情况
	*消息流向 : device==>service
	* see Ev_MT_DeviceDetectCpuAndMem_Req
	*/
	MESSAGE(Ev_MT_DeviceDetectCpuAndMem_Rsp)
	BODY(mt::TMTCpuAndMemState, cpuandmemsts)


    /*------生产测试--------*/
    /*<<串口生产测试请求>>
    *serial_type : 串口种类
	*消息流向 : service==>device
	* see Ev_MT_DeviceSerialTest_Rsp
	*/
	MESSAGE(Ev_MT_DeviceSerialTest_Req)
	BODY(mt::TS32, serial_type)

	/*<<串口关闭命令>>
    *serial_type : 串口种类
	*消息流向 : mtservice==>device
	* see
	*/
	MESSAGE(Ev_MT_CloseSerialCom_Cmd)
	BODY(mt::TS32, serial_type)


    /*<<查询cpu和内存使用情况响应>>
	*result : 测试结果
	*serial_type : 串口种类
	*消息流向 : device==>service
	* see Ev_MT_DeviceSerialTest_Req
	*/
    MESSAGE(Ev_MT_DeviceSerialTest_Rsp)
    BODY(mt::TBOOL32, result)
    BODY(mt::TS32, serial_type)

    /*<<遥控器生产测试开始或结束通知>>
    *install : 打开或关闭
	*消息流向 : service==>device
	* see Ev_MT_DeviceRemoteCtrlTest_Ntf
	*/
    MESSAGE(Ev_MT_DeviceRemoteCtrlTest_Cmd)
    BODY(mt::TBOOL32, install)

    /*<<遥控器生产测试键值返回>>
	*result : 测试结果
	*scan_code : 键值
	*消息流向 : device==>service
	* see Ev_MT_DeviceRemoteCtrlTest_Cmd
	*/
    MESSAGE(Ev_MT_DeviceRemoteCtrlTest_Ntf)
    BODY(mt::TBOOL32, result)
    BODY(mt::TU8, scan_code)

	/*<<遥控器版本号上报>>
	*byRemoteCtrlVersion : 遥控器版本号
	*消息流向 : misc==>ui
	*/
    MESSAGE(Ev_MT_DeviceRemoteCtrlVersion_Ntf)
    BODY(mt::TString, byRemoteCtrlVersion)


	/*<<按键通知>>
	* ui -> misc
	*/
    MESSAGE(Ev_MT_UserOperation_Ntf)
	BODY(mt::TBOOL32, is_key_power_press)	//是否待机键


	/*<<向ui发送待机倒计时通知>>
	* misc -> ui
	*/
	MESSAGE(Ev_MT_SleepCountDown_Ntf)
	BODY(mt::TS32, count_down)	//倒计时时间

	/*<<通知终端待机状态>>
	* misc -> ui
	*/
	MESSAGE(Ev_MT_SleepState_Ntf)
	BODY(mt::TS32, EmMtSleepState)	//待机状态

	/*<<向ui发送重置系统通知>>
	* misc -> ui
	*/
	MESSAGE(Ev_MT_OqcResetSystem_Ntf)

	/*<<重启终端>>
	* ui -> misc
	*/
	MESSAGE(Ev_MT_RebootSystem_Cmd)
	

	/*<<手动设置系统时间>>
	* ui -> misc
	*/
	MESSAGE(Ev_MT_SetSystemTime_Cmd)
	BODY(mt::TMTTime, time)				//要设置的时间


	/*<<系统恢复出厂设置>>
    *is_oqc : true表示需要删除配置, false表示不需要删除配置
	* ui -> misc
	*/
	MESSAGE(Ev_MT_ResetSystem_Cmd)
	BODY(mt::TBOOL32, is_oqc)

	/*<<开启式抓包命令>>
	* ui -> misc
	*/
	MESSAGE(Ev_MT_StartNetCapture_Cmd)
    BODY(mt::TU32, capture_nettype)  //抓包网口选择 EmNetAdapterWorkType

	/*<<停止抓包命令>>
	* ui -> misc
	*/
	MESSAGE(Ev_MT_StopNetCapture_Cmd)

	/*<<获取当前抓包状态>>
	* service -> misc
	*/
	MESSAGE(Ev_MT_GetCurCapStatus_Req)

	/*<<获取当前抓包状态响应>>
	* service <- misc
	*/
	MESSAGE(Ev_MT_GetCurCapStatus_Rsp)
	BODY(mt::TU32, capture_state)	 // 1:正在抓包  0:没有抓包
	BODY(mt::TMTTime, curtime)		 // 抓包开始时间(老版本使用)
	BODY(mt::TU32, lastCaptime)		 // 上次抓包时间（单位：秒）
    BODY(mt::TU32, startcaptime)     // 上次抓包时间（新版本使用 单位：秒）

	/*<<抓包状态通知>>
	* misc -> ui
	*/
	MESSAGE(Ev_MT_NetCaptureState_Ntf)
	BODY(mt::TU32, capture_state)	 // MT_SUCCESS:正在抓包  MT_FAILED:开启抓包失败
	BODY(mt::TMTTime, curtime)		 // 抓包开始时间
	BODY(mt::TU32, lastCaptime)		 // 上次抓包时间（单位：毫秒）

	/*<<抓包文件列表查询>>
	* service -> device
	*/
	MESSAGE(Ev_MT_GetNetCapFileList_Req)

	/*<<抓包文件列表查询>>
	* device -> service
	*/
	MESSAGE(Ev_MT_GetNetCapFileList_Rsp)
	BODY(mt::TNetCapFileList, netcaplist)	//抓包文件列表

	/*<<删除抓包文件>>
	* service -> device
	*/
	MESSAGE(Ev_MT_DeleteNetCapFile_Cmd)

    /*<<删除抓包文件>>
	* device -> service_hd
	*/
	MESSAGE(Ev_MT_DeleteNetCapFile_Ntf)
    BODY(mt::TU32, result)

	/*<<导出抓包文件请求>>
	* ui -> misc
	*/
	MESSAGE(Ev_MT_ExportNetCapture_Req)
	BODY(mt::TString, export_file_path)	//文件导出路径

	/*<<导出抓包文件进度通知>>
	* ui -> misc
	*/
	MESSAGE(Ev_MT_ExportNetCaptureProgress_Ntf)
	BODY(mt::TU32, percent)	//整体百分比


	/*<<导出抓包文件响应>>
	* misc -> ui
	*/
	MESSAGE(Ev_MT_ExportNetCapture_Rsp)
	BODY(mt::TU32, is_ok)	//MT_SUCCESS:成功
							//ERR_MTMISC_DISK_OUTOF_SPACE 空间不足
							//ERR_MTMISC_FILE_NOT_EXIST  文件不存在

	/*<<获取当前抓包状态>>
	* service -> misc
	*/
	MESSAGE(Ev_MT_GetPacketDurationTime_Req)

	/*<<获取当前抓包状态响应>>
	* service <- misc
	*/
	MESSAGE(Ev_MT_GetPacketDurationTime_Rsp)
	BODY(mt::TU32, DurationTime )	 // 抓包持续时间

	/*<<导出日志请求>>
	* ui -> misc
	*/
	MESSAGE(Ev_MT_ExportLog_Req)
	BODY(mt::TString, export_file_path)	//文件导出路径

	/*<<导出日志进度通知>>
	* ui -> misc
	*/
	MESSAGE(Ev_MT_ExportLogProgress_Ntf)
	BODY(mt::TU32, percent)	//整体百分比


	/*<<导出日志响应>>
	* misc -> ui
	*/
	MESSAGE(Ev_MT_ExportLog_Rsp)
	BODY(mt::TU32, is_ok)	
    //MT_SUCCESS:成功
    //ERR_MTMISC_DISK_OUTOF_SPACE 空间不足
    //ERR_MTMISC_PATH_NOT_EXIST 导出路径不存在
    //ERR_MTMISC_FILE_NOT_EXIST 日志文件不存在
    //...



    /*<<检查文件请求>>
    * 消息流向 : service -> device
    * 参数 : file_path   查找起始目录
    * 参数 : file_name   查找文件名
    * 参数 : is_recurse  是否查找所有子目录
    * see : Ev_MT_FileExistCheck_Rsp
	*/
    MESSAGE(Ev_MT_FileExistCheck_Req)
    BODY(mt::TString, file_path)
    BODY(mt::TString, file_name)
    BODY(mt::TBOOL32, is_recurse)

    /*<<检查文件响应>>
    * 消息流向 : device -> service
    * 参数 : is_exist        所查文件是否存在
    * 参数 : file_full_path  所查文件全路径(包含文件名)
    * 参数 : file_size       所查文件大小
    * see : Ev_MT_FileExistCheck_Req
	*/
    MESSAGE(Ev_MT_FileExistCheck_Rsp)
    BODY(mt::TBOOL32, is_exist)
    BODY(mt::TString, file_full_path)
    BODY(mt::TU32, file_size)



    /*<<导出地址簿请求>>
    * 消息流向 : service -> device
    * 参数 : dst_path    导出目标路径
    * see : Ev_MT_AddrBookExport_Rsp
	*/
    MESSAGE(Ev_MT_AddrBookExport_Req)
    BODY(mt::TString, dst_path)

    /*<<检查文件响应>>
    * 消息流向 : device -> service
    * 参数 : err_code      是否成功 mt::EmFileCopyErr
    * see : Ev_MT_AddrBookExport_Req
	*/
    MESSAGE(Ev_MT_AddrBookExport_Rsp)
    BODY(mt::TS32, err_code)

    /*<<导出地址簿百分比>>
    * 消息流向 : device -> service
    * 参数 : progress      百分比
    * see : Ev_MT_AddrBookExport_Req
	*/
    MESSAGE(Ev_MT_AddrBookExportProgress_Ntf)
    BODY(mt::TU32, progress)



    /*<<导入地址簿请求>>
    * 消息流向 : service -> device
    * 参数 : dst_path    导入源路径(带文件名)
    * see : Ev_MT_AddrBookImport_Rsp
	*/
    MESSAGE(Ev_MT_AddrBookImport_Req)
    BODY(mt::TString, src_path)


    /*<<导入地址簿响应>>
    * 消息流向 : device -> service
    * 参数 : err_code      是否成功 mt::EmFileCopyErr
    * see : Ev_MT_AddrBookImport_Req
	*/
    MESSAGE(Ev_MT_AddrBookImport_Rsp)
    BODY(mt::TS32, err_code)

    /*<<导入地址簿百分比>>
    * 消息流向 : device -> service
    * 参数 : progress      百分比
    * see : Ev_MT_AddrBookExport_Req
	*/
    MESSAGE(Ev_MT_AddrBookImportProgress_Ntf)
    BODY(mt::TU32, progress)




    /*<<导入地址簿请求>>
    * 消息流向 : service -> device
    * 参数 : dst_path    导入源路径(带文件名)
    * see : Ev_MT_MicUpgradeFileImport_Rsp
    *       Ev_MT_MicUpgradeFileImportProgress_Ntf
	*/
    MESSAGE(Ev_MT_MicUpgradeFileImport_Req)
    BODY(mt::TString, src_path)


    /*<<导入地址簿响应>>
    * 消息流向 : device -> service
    * 参数 : err_code      是否成功 mt::EmFileCopyErr
    * see : Ev_MT_MicUpgradeFileImport_Req
	*/
    MESSAGE(Ev_MT_MicUpgradeFileImport_Rsp)
    BODY(mt::TS32, err_code)

    /*<<导入地址簿百分比>>
    * 消息流向 : device -> service
    * 参数 : progress      百分比
    * see : Ev_MT_MicUpgradeFileImport_Req
	*/
    MESSAGE(Ev_MT_MicUpgradeFileImportProgress_Ntf)
    BODY(mt::TU32, progress)

    /*<<目录结构查询请求>>
	* 消息流向 : service -> device
    * 参    数 : src_path   查询路径
    * see : Ev_MT_InquirePathStructure_Rsp
	*/
    MESSAGE(Ev_MT_InquirePathStructure_Req)
    BODY(mt::TString, src_path)

    /*<<目录结构查询响应>>
	* 消息流向 : device -> service
    * 参数 : src_path           查询路径
    *        path_detail_list   路径内容
    * see : Ev_MT_InquirePathStructure_Req
	*/
    MESSAGE(Ev_MT_InquirePathStructure_Rsp)
    BODY(mt::TString, src_path)
    BODY(mt::TMTPathStructureDetail, path_detail_list)

	/*<<查询终端程序是否全部启动成功请求>>
	* 消息流向 : service -> mtmanage
    * see : Ev_MT_InquireHDMtStartSucess_Rsp
	*/
    MESSAGE(Ev_MT_InquireHDMtStartSucess_Req)

	/*<<查询终端程序是否全部启动成功响应>>
	* 消息流向 : mtmanage -> service
	* 参数 : sucess       成功/失败
    * see : Ev_MT_InquireHDMtStartSucess_Req
	*/
    MESSAGE(Ev_MT_InquireHDMtStartSucess_Rsp)
    BODY(mt::TBOOL32, sucess)

	/*<<终端程序全部启动成功通知>>
	* 消息流向 : mtmanage -> service
    * see : 
	*/
    MESSAGE(Ev_MT_HDMtStartSucess_Ntf)

    /*********************************麦克风相关消息Beg***************************************/

	/*<<麦克风连接状态请求>>
	*消息流向 : service==>dispatch==>deivce
	*/
    MESSAGE(Ev_MT_MicrophoneConnectStatus_Req)

	/*<<麦克风连接状态应答>>
	*消息流向 : service==>dispatch==>deivce
	*/
    MESSAGE(Ev_MT_MicrophoneConnectStatus_Rsp)
	BODY(mt::TMTMicInfo, ConnectStatus)

	/*<<麦克风连接状态上报>>
	*消息流向 : service==>dispatch==>deivce
	*/
    MESSAGE(Ev_MT_MicrophoneConnectStatus_Ntf)
	BODY(mt::TMTMicInfo, ConnectStatus)

	/*<<麦克风无线电量请求>>
	*消息流向 : service==>dispatch==>deivce
	*/
    MESSAGE(Ev_MT_MicrophoneBatteryLevel_Req)

	/*<<麦克风无线电量应答>>
	*消息流向 : service<==dispatch<==deivce
	*/
    MESSAGE(Ev_MT_MicrophoneBatteryLevel_Rsp)
	BODY(mt::TMTMicInfo, BatteryLevel)

	/*<<麦克风无线电量上报>>
	*消息流向 : service==>dispatch==>deivce
	*/
    MESSAGE(Ev_MT_MicrophoneBatteryLevel_Ntf)
	BODY(mt::TMTMicInfo, BatteryLevel)

	/*<<无线麦克风电量过低（低于一格）上报>>
	*消息流向 : device==>dispatch==>service
	*/
	MESSAGE(Ev_MT_WirelessMicrophoneBatteryLow_Ntf)
	BODY(mt::TBOOL32, IsLow)

	/*<<麦克风无线信号请求>>
	*消息流向 : service==>dispatch==>deivce
	*/
	MESSAGE(Ev_MT_MicrophoneWirelessSignal_Req)

	/*<<麦克风无线信号应答>>
	*消息流向 : service==>dispatch==>deivce
	*/
	MESSAGE(Ev_MT_MicrophoneWirelessSignal_Rsp)

	/*<<麦克风无线信号上报>>
	*消息流向 : service==>dispatch==>deivce
	*/
	MESSAGE(Ev_MT_MicrophoneWirelessSignal_Ntf)

	/*<<通知/user/fileimg中的版本包已更新>>
	*消息流向 : service==>dispatch==>device
	*fileType: 需要重置的版本包 1: wind3d.bin.tar ; 2: skyshare_setup.tar
	*/
	MESSAGE(Ev_MT_ResetUserFileimg_Cmd)
	BODY(mt::TU32, fileType)

	/*<<麦克风升级状态请求>>
	*消息流向 : sdk==>dispatch==>service
	*/
	MESSAGE(Ev_MT_MicrophoneState_Req)

	/*<<麦克风升级状态应答(mt::TMicUpgradeStateList)>>
	*消息流向 : service==>dispatch==>sdk
	*/
	MESSAGE(Ev_MT_MicrophoneState_Rsp)
	BODY(mt::TMicUpgradeStateList, state)

	/*<<麦克风升级状态上报(mt::TMicUpgradeStateList)>>
	*消息流向 : service==>dispatch==>sdk
	*/
	MESSAGE(Ev_MT_MicrophoneState_Ntf)
	BODY(mt::TMicUpgradeStateList, state)

	/*<<麦克风上传命令(废弃)>>
	*消息流向 : service==>dispatch==>sdk
	*/
	MESSAGE(Ev_MT_MicrophoneUpload_Cmd)

	/*<<麦克风上传进度上报(废弃)>>
	*消息流向 : service==>dispatch==>sdk
	*/
	MESSAGE(Ev_MT_MicrophoneUpload_Ntf)
	BODY(mt::TU32, progress)

	/*<<麦克风安装命令(mt::TMicInstallList)>>
	*消息流向 : sdk==>dispatch==>service
	*/
	MESSAGE(Ev_MT_MicrophoneInstall_Cmd)
	BODY(mt::TMicInstallList, install)

	/*<<麦克风更新包上传状态请求(废弃)>>
	*消息流向 : service==>dispatch==>deivce
	*/
    MESSAGE(Ev_MT_MicrophoneVersionStatus_Req)

	/*<<麦克风更新包上传状态应答(废弃)>>
	*消息流向 : service<==dispatch<==deivce
	*/
    MESSAGE(Ev_MT_MicrophoneVersionStatus_Rsp)
	BODY(mt::TMTMicInfo, VersionStatus)

	/*<<麦克风更新包上传状态上报(废弃)>>
	*消息流向 : service<==dispatch<==deivce
	*/
    MESSAGE(Ev_MT_MicrophoneVersionStatus_Ntf)
	BODY(mt::TMTMicInfo, VersionStatus)

	/*<<麦克风升级命令(废弃)>>
	*消息流向 : service==>dispatch==>deivce
	*/
    MESSAGE(Ev_MT_MicrophoneUpgrade_Cmd)
	BODY(mt::TMTMicInfo, IsUpgrade)

	/*<<麦克风升级上报(废弃)>>
	*消息流向 : deivce==>dispatch==>service
	*/
    MESSAGE(Ev_MT_MicrophoneUpgrade_Ntf)
	BODY(mt::TMTMicInfo, UpgradeState)

	/*<<麦克风哑音状态请求>>
	*消息流向 : service==>dispatch==>deivce
	*/
    MESSAGE(Ev_MT_MicrophoneMute_Req)

	/*<<麦克风哑音状态应答>>
	*消息流向 : service==>dispatch==>deivce
	*/
    MESSAGE(Ev_MT_MicrophoneMute_Rsp)

	/*<<麦克风哑音设置>>
	*消息流向 : service==>dispatch==>deivce
	*/
    MESSAGE(Ev_MT_MicrophoneMute_Cmd)

	/*<<麦克风哑音状态上报>>
	*消息流向 : service<==dispatch<==deivce
	*/
    MESSAGE(Ev_MT_MicrophoneMute_Ntf)

    /*<<麦克风版本信息查询>>
	*消息流向 : service==>dispatch==>deivce
	*/
    MESSAGE(Ev_MT_MicrophoneInfo_Req)

    /*<<麦克风版本信息应答>>
	*消息流向 : device==>dispatch==>service
	*/
    MESSAGE(Ev_MT_MicrophoneInfo_Rsp)
	BODY(mt::TMicVersionList, VerInfo)

	/*<<麦克风版本信息上报>>
	*消息流向 : device==>dispatch==>service
	*/
    MESSAGE(Ev_MT_MicrophoneInfo_Ntf)
	BODY(mt::TMicVersionList, VerInfo)

	/*<<终端保存的麦克风版本信息查询>>
	*消息流向 : service==>dispatch==>deivce
	*/
    MESSAGE(Ev_MT_TermKeepMicrophoneInfo_Req)
	BODY( NULL , NULL )

	/*<<终端保存的麦克风版本信息查询>>
	*消息流向 : service==>dispatch==>deivce
	*/
    MESSAGE(Ev_MT_TermKeepMicrophoneInfo_Rsp)
	BODY( mt::TString , tStrTermKeepMicVer )

	/*<<开启射频热点请求>>
	*消息流向 : service==>dispatch==>deivce
	*/
    MESSAGE(Ev_MT_OpenHotspot_Req)
	BODY(mt::TMTMicInfo, IsOpenHotspot)

	/*<<开启射频热点应答>>
	*消息流向 : service==>dispatch==>deivce
	*/
    MESSAGE(Ev_MT_OpenHotspot_Rsp)
	BODY(mt::TMTMicInfo, HotspotState)

	/*<<射频状态请求>>
	*消息流向 : service==>dispatch==>deivce
	*/
    MESSAGE(Ev_MT_Hotspot_State_Req)

    /*<<射频状态应答>>
	*消息流向 : device==>dispatch==>service
	*/
    MESSAGE(Ev_MT_Hotspot_State_Rsp)
	BODY(mt::TMTMicInfo, HotspotState)

	/*<<数字麦USB测试请求>>
	*消息流向 : dispatch==>deivce
	*/
    MESSAGE(Ev_MT_MicrophoneUsbTest_Cmd)

    /*<<数字麦USB测试应答>>
	*消息流向 : device==>dispatch
	*/
    MESSAGE(Ev_MT_MicrophoneUsbTest_Ntf)
	BODY(mt::TMTMicInfo, IsUsbOk)

	/*<<射频匹配状态上报>>
	*消息流向 : device==>dispatch
	*/
	MESSAGE(Ev_MT_RfMatchStateListCfg_Ntf)
	BODY(mt::TMTRfMatchStateList, MatchState)

    /*********************************麦克风相关消息End***************************************/

	/*<<进入或退出生产测试>>
	* register_state : 是否登录
	* mtmfgtest==>dispatch==>mtservice
	*/
	MESSAGE(Ev_MT_MfgTestRegisterInOrOut_Ntf)
	BODY(mt::TBOOL32, register_state)

	/*<<Visca调试命令>>
	*SerialType   : 串口类型EmSerialType
	*ViscaCommand : 发送命令
	*消息流向 : AID_DEVICECTRL==>AID_CAMERACTRL
	*/
	MESSAGE(Ev_MT_ViscaCommand_Cmd)
	BODY(mt::TU32, SerialType)
	BODY(mt::TString, ViscaCommand)

	/*<<设置摄像机图像模式>>
	*value  :  EmImgMode
    *vid_idx : EmCodecComponentIndex  em1st表示第一路  em2nd表示第二路
	消息流向 : mtservice==>dispatch==>mtdevice
	*/
	MESSAGE(Ev_MT_ImgMode_Cmd)
	BODY(mt::TU32, EmImgMode)
    BODY(mt::TU32, vid_idx)
	
	/*<<设置摄像机图像模式结果>>
	*value  :  EmImgMode
    *vid_idx : EmCodecComponentIndex  em1st表示第一路  em2nd表示第二路
    *value  :  result
	消息流向 : mtdevice==>dispatch==>mtservice
	*/
	MESSAGE(Ev_MT_ImgMode_Ntf)
	BODY(mt::TU32, EmImgMode)
    BODY(mt::TU32, vid_idx)
    BODY(mt::TU32, result)

	/*<<设置摄像机人物优先>>
	*value  :  BOOL32
    *vid_idx : EmCodecComponentIndex  em1st表示第一路  em2nd表示第二路
	消息流向 : mtservice==>dispatch==>mtdevice
	*/
	MESSAGE(Ev_MT_PersonFirst_Cmd)
	BODY(mt::TBOOL32, BOOL32)
    BODY(mt::TU32, vid_idx)
	
	/*<<设置摄像机人物优先响应>>
	*value  :  BOOL32
    *vid_idx : EmCodecComponentIndex  em1st表示第一路  em2nd表示第二路
    *value  :  result
	消息流向 : mtdevice==>dispatch==>mtservice
	*/
	MESSAGE(Ev_MT_PersonFirst_Ntf)
	BODY(mt::TBOOL32, BOOL32)
    BODY(mt::TU32, vid_idx)
    BODY(mt::TU32, result)

	/*<<设置Isp降噪>>
	*EmNFType     :
	*value  :  0-10
	*vid_idx : EmCodecComponentIndex  em1st表示第一路  em2nd表示第二路
	消息流向 : mtservice==>dispatch==>mtmpapp
	*/
	MESSAGE(Ev_MT_IspImgInf_Noise_Cmd)
	BODY(mt::TU32, EmNFType)
	BODY(mt::TU32, value)
	BODY(mt::TU32, vid_idx)
	
	/*<<设置Isp降噪>>
	*EmNFType     :
	*value  :  0-10
	消息流向 : mtservice==>dispatch==>mtmpapp
	*/
	MESSAGE(Ev_MT_IspImgInf_Noise_Ntf)
	BODY(mt::TU32, EmNFType)
	BODY(mt::TU32, value)
    BODY(mt::TU32, vid_idx)
    BODY(mt::TU32, result)

	/*<<设置Isp锐度>>
	*value     :0-10
	*vid_idx : EmCodecComponentIndex  em1st表示第一路  em2nd表示第二路
	消息流向 : mtservice==>dispatch==>mtmpapp
	*/
	MESSAGE(Ev_MT_IspImgInf_Sharpness_Cmd)
	BODY(mt::TU32, value)
	BODY(mt::TU32, vid_idx)
	
	/*<<设置Isp锐度>>
	*value     :0-10
    *vid_idx : EmCodecComponentIndex  em1st表示第一路  em2nd表示第二路
    *result  : 0成功
	消息流向 : mtmpapp==>dispatch==>mtservice
	*/
	MESSAGE(Ev_MT_IspImgInf_Sharpness_Ntf)
	BODY(mt::TU32, value)
    BODY(mt::TU32, vid_idx)
    BODY(mt::TU32, result)

	/*<<设置Isp曝光增益>>
	*EmExposureModeGainType     :0:auto;1:manual
	*value     :0-10
	*vid_idx : EmCodecComponentIndex  em1st表示第一路  em2nd表示第二路
	消息流向 : mtservice==>dispatch==>mtmpapp
	*/
	MESSAGE(Ev_MT_IspImgInf_ExposureModeGain_Cmd)
	BODY(mt::TU32, EmExposureModeGainType)
	BODY(mt::TU32, value)
	BODY(mt::TU32, vid_idx)
	
	/*<<设置Isp曝光增益>>
	*EmExposureModeGainType     :0:auto;1:manual
	*value     :0-10
    *vid_idx : EmCodecComponentIndex  em1st表示第一路  em2nd表示第二路
    *result : 0成功，其他失败
	消息流向 : mtmpapp==>dispatch==>mtservice
	*/
	MESSAGE(Ev_MT_IspImgInf_ExposureModeGain_Ntf)
	BODY(mt::TU32, EmExposureModeGainType)
	BODY(mt::TU32, value)
    BODY(mt::TU32, vid_idx)
    BODY(mt::TU32, result)

	/*<<设置Isp白平衡增益>>
	*EmExposureModeGainType     :0:红;1:蓝
	*value     :0-255
	*vid_idx : EmCodecComponentIndex  em1st表示第一路  em2nd表示第二路
	消息流向 : mtservice==>dispatch==>mtmpapp
	*/
	MESSAGE(Ev_MT_IspImgInf_WhiteBalanceGain_Cmd)
	BODY(mt::TU32, EMWBAModeGainType)
	BODY(mt::TU32, value)
	BODY(mt::TU32, vid_idx)
	
	/*<<设置Isp白平衡增益相应>>
	*EmExposureModeGainType     :0:红;1:蓝
	*value     :0-255
    *vid_idx : EmCodecComponentIndex  em1st表示第一路  em2nd表示第二路
    *result : 0成功，其他失败
	消息流向 : mtmpapp==>dispatch==>mtservice
	*/
	MESSAGE(Ev_MT_IspImgInf_WhiteBalanceGain_Ntf)
	BODY(mt::TU32, EMWBAModeGainType)
	BODY(mt::TU32, value)
    BODY(mt::TU32, vid_idx)
    BODY(mt::TU32, result)

	/*<<设置Isp背光补偿开关>>
	*value     :0:关;1:开
	消息流向 : mtservice==>dispatch==>mtmpapp
	*/
	MESSAGE(Ev_MT_IspImgInf_BackLightSwitch_Cmd)
	BODY(mt::TBOOL32, value)

	/*<<设置Isp背光补偿等级>>
	*：value：0：0-15
	消息流向 : mtservice==>dispatch==>mtmpapp
	*/
	MESSAGE(Ev_MT_IspImgInf_BackLightLevel_Cmd)
	BODY(mt::TU32, value)

	/*<<设置Isp感光度>>
	*EmISO      :
	消息流向 : mtservice==>dispatch==>mtmpapp
	*/
	MESSAGE(Ev_MT_IspImgInf_ISO_Cmd)
	BODY(mt::TU32, EmISO)

	/*<<设置Isp曝光模式>>
	*EmExposureMode      :
    *vid_idx : EmCodecComponentIndex  em1st表示第一路  em2nd表示第二路
	消息流向 : mtservice==>dispatch==>mtmpapp
	*/
	MESSAGE(Ev_MT_IspImgInf_ExposureMode_Cmd)
	BODY(mt::TU32, EmExposureMode)
    BODY(mt::TU32, vid_idx)
	
	/*<<设置Isp曝光相应>>
	*EmExposureMode      :
    *vid_idx : EmCodecComponentIndex  em1st表示第一路  em2nd表示第二路
    result
	消息流向 : mtmpapp==>dispatch==>mtservice
	*/
	MESSAGE(Ev_MT_IspImgInf_ExposureMode_Ntf)
	BODY(mt::TU32, EmExposureMode)
    BODY(mt::TU32, vid_idx)
    BODY(mt::TU32, result)

	/*<<设置Isp光圈大小>>
	*EmAperture      :
	*vid_idx : EmCodecComponentIndex  em1st表示第一路  em2nd表示第二路
	消息流向 : mtservice==>dispatch==>mtmpapp
	*/
	MESSAGE(Ev_MT_IspImgInf_Aperture_Cmd)
	BODY(mt::TU32, EmAperture)
	BODY(mt::TU32, vid_idx)
	
	/*<<设置Isp光圈大小>>
	*EmAperture      :
    *vid_idx : EmCodecComponentIndex  em1st表示第一路  em2nd表示第二路
    *result : 0成功，其他失败
	消息流向 : mtservice==>dispatch==>mtmpapp
	*/
	MESSAGE(Ev_MT_IspImgInf_Aperture_Ntf)
	BODY(mt::TU32, EmAperture)
    BODY(mt::TU32, vid_idx)
    BODY(mt::TU32, result)

	/*<<设置Isp快门速度>>
	*EmAperture      :
	*vid_idx : EmCodecComponentIndex  em1st表示第一路  em2nd表示第二路
	消息流向 : mtservice==>dispatch==>mtmpapp
	*/
	MESSAGE(Ev_MT_IspImgInf_Shutter_Cmd)
	BODY(mt::TU32, EmShutterLevel)
	BODY(mt::TU32, vid_idx)
	
    /*<<设置Isp快门速度>>
	*EmAperture      :
    *vid_idx : EmCodecComponentIndex  em1st表示第一路  em2nd表示第二路
    *result : 0成功，其他失败
	消息流向 : mtmpapp==>dispatch==>mtservice
	*/
	MESSAGE(Ev_MT_IspImgInf_Shutter_Ntf)
	BODY(mt::TU32, EmShutterLevel)
    BODY(mt::TU32, vid_idx)
    BODY(mt::TU32, result)

	/*<<设置Isp亮度>>
	*曝光为自动模式亮度调节才生效，曝光为手动模式下亮度调节无效
	*EmBrightnessDirection:
	消息流向 : mtservice==>dispatch==>mtmpapp
	*/
	MESSAGE(Ev_MT_IspImgInf_Brightnesss_Cmd)
	BODY(mt::TU32, EmBrightnessDirection)

	/*<<设置Isp背光度>>
	*自动背光，或者关闭
	*EmBrightnessDirection:
	消息流向 : mtdevice==>dispatch==>mtmpapp
	*/
	MESSAGE(Ev_MT_IspImgInf_BackLight_Cmd)
	BODY(mt::TBOOL32, bAuto)

	/*<<设置Isp白平衡>>
	*EmWBAMode      :
	*vid_idx : EmCodecComponentIndex  em1st表示第一路  em2nd表示第二路
	消息流向 : mtservice==>dispatch==>mtmpapp
	*/
	MESSAGE(Ev_MT_IspImgInf_WhiteBalance_Cmd)
	BODY(mt::TU32, EmWBAMode)
	BODY(mt::TU32, vid_idx)
	
	/*<<设置Isp白平衡响应>>
	*EmWBAMode      :
    *vid_idx : EmCodecComponentIndex  em1st表示第一路  em2nd表示第二路
    *result : 0成功，其他失败
	消息流向 : mtmpapp==>dispatch==>mtservice
	*/
	MESSAGE(Ev_MT_IspImgInf_WhiteBalance_Ntf)
	BODY(mt::TU32, EmWBAMode)
    BODY(mt::TU32, vid_idx)
    BODY(mt::TU32, result)

	/*<<设置Isp图像参数>>
	*emInterface : Isp图像接口EmIspImgInterface
	*dwReason    : 0 失败；1 成功
	消息流向 : mtservice<==dispatch<==mtmpapp
	*/
	MESSAGE(Ev_MT_IspImgInf_Ntf)
	BODY(mt::TU32, EmIspImgInf)
	BODY(mt::TU32, dwReason)

	/*<<设置Isp图像亮度>>
	消息流向 : mtservice==>dispatch==>mtmpapp
	*/
	MESSAGE(Ev_MT_IspSetBrightImgParam_Cmd)
	BODY(mt::TU32, dwValue)

	/*<<设置Isp图像色调>>
	消息流向 : mtservice==>dispatch==>mtmpapp
	*/
	MESSAGE(Ev_MT_IspSetHueImgParam_Cmd)
	BODY(mt::TU32, dwValue)

	/*<<设置Isp图像对比度>>
	消息流向 : mtservice==>dispatch==>mtmpapp
	*/
	MESSAGE(Ev_MT_IspSetContrastImgParam_Cmd)
	BODY(mt::TU32, EmImgParam)
	BODY(mt::TU32, dwValue)

	/*<<设置Isp图像饱和度>>
	消息流向 : mtservice==>dispatch==>mtmpapp
	*/
	MESSAGE(Ev_MT_IspSetSaturationImgParam_Cmd)
	BODY(mt::TU32, EmImgParam)
	BODY(mt::TU32, dwValue)

	/*<<设置Isp图像伽马>>
	消息流向 : mtservice==>dispatch==>mtmpapp
	*/
	MESSAGE(Ev_MT_IspSetGammmaImgParam_Cmd)
	BODY(mt::TU32, dwValue)
	BODY(mt::TU32, vid_idx)
	
	/*<<设置Isp图像伽马>>
	消息流向 : mtmpapp==>dispatch==>mtservice
	*/
	MESSAGE(Ev_MT_IspSetGammmaImgParam_Ntf)
	BODY(mt::TU32, dwValue)
	BODY(mt::TU32, vid_idx)
	BODY(mt::TU32, result)

	/*<<设置Isp图像数字去雾>>
	消息流向 : mtservice==>dispatch==>mtmpapp
	*/
	MESSAGE(Ev_MT_IspSetDefogImgParam_Cmd)
	BODY(mt::TU32, dwValue)

	/*<<设置Isp图像数字宽动态开关>>
	消息流向 : mtservice==>dispatch==>mtmpapp
	*/
	MESSAGE(Ev_MT_IspSetDigDynSwitchImgParam_Cmd)
	BODY(mt::TBOOL32, dwValue)

	/*<<设置Isp图像数字宽动态等级>>
	消息流向 : mtservice==>dispatch==>mtmpapp
	*/
	MESSAGE(Ev_MT_IspSetDigDynLevelParam_Cmd)
	BODY(mt::TU32, dwValue)

	/*<<动作控制相关>>
	*EmWBAMode      :
	消息流向 : mtdevice==>mtmpapp
	*/
	MESSAGE(Ev_MT_IspImgAction_Cmd)
	BODY(mt::TU32, EmIspActionType)
	BODY(mt::TU32, dwValue)

	/*<<设置机芯制式>>
	*dwValue      :
	消息流向 : mtdevice==>mtmpapp
	*/
	MESSAGE(Ev_SetCameraVidStd_Cmd)
	BODY(mt::TU32, EmCameraVidStd)

	/*<<摄像机老化测试>>
	*dwValue      :
	消息流向 : mtdevice ==> mtdevice
	*/
	MESSAGE(Ev_MT_DeviceCameraAgingTestCmd)
	BODY(mt::TBOOL32, bStart)


    /*<<导出诊断信息文件请求>>
	* ui -> misc
	*/
	MESSAGE(Ev_MT_ExportDiagInfo_Cmd)
	BODY(mt::TString, export_file_path)	//文件导出路径

	/*<<导出诊断信息文件进度通知>>
	* ui -> misc
	*/
	MESSAGE(Ev_MT_ExportDiagInfoProgress_Ntf)
	BODY(mt::TU32, percent)	//整体百分比


	/*<<导出诊断信息文件响应>>
	* misc -> ui
	*/
	MESSAGE(Ev_MT_ExportDiagInfo_Ntf)
	BODY(mt::TU32, is_ok)	//MT_SUCCESS:成功
							//ERR_MTMISC_DISK_OUTOF_SPACE 空间不足
							//ERR_MTMISC_FILE_NOT_EXIST  文件不存在
	BODY(mt::TString, export_file_path)	//文件导出路径

    /*<<导出诊断信息文件>>
	* ui -> misc
	*/
	MESSAGE(Ev_MT_DiagInfoGet_Cmd)
	BODY(mt::TU32, data_type)	//诊断消息类型
    BODY(mt::TString, export_file_path)	//文件导出路径

	/*<<导出诊断信息文件响应>>
	* misc -> ui
	*/
	MESSAGE(Ev_MT_DiagInfoGet_Ntf)
	BODY(mt::TU32, data_type)  //诊断消息类型
    BODY(mt::TString, export_file_path)	//文件导出路径
    BODY(mt::TU32, result)    //处理结果

    /*<<选择串口供网呈使用>>
	* service -> device
	*/
	MESSAGE(Ev_MT_ChooseSerialUse_Cmd)
	BODY(mt::TMTHDSerialCtrl, serial_use)	//串口配置
    BODY(mt::TBOOL32, serial_use)	//是否使用

	/*<<选择串口供网呈使用响应>>
	* device -> service
	*/
	MESSAGE(Ev_MT_ChooseSerialUse_Ntf)
    BODY(mt::TMTHDSerialCtrl, serial_use)	//串口配置
    BODY(mt::TBOOL32, serial_use)	//是否使用
    BODY(mt::TS32, result)    //处理结果

        /*<<选择串口供网呈使用>>
	* service -> device
	*/
	MESSAGE(Ev_MT_OperaterSerial_Cmd)
    BODY(mt::TSerialOptParam, serial_info)	//读写信息

	/*<<选择串口供网呈使用响应>>
	* device -> service
	*/
	MESSAGE(Ev_MT_OperaterSerial_Ntf)
    BODY(mt::TSerialOptParam, serial_info)	//读写信息
    BODY(mt::TS32, result)    //处理结果

	/*<<生产测试内置摄像机PTZ测试>>
	消息流向 : service -> device
	*/
    MESSAGE(Ev_MT_DeviceCameraPTZTestCmd)
	BODY(mt::TBOOL32, bStart)				//TRUE: 开始 FLASE: 结束

	/*<<生产测试内置摄像机预置位测试>>
	消息流向 : service -> device
	*/
    MESSAGE(Ev_MT_DeviceCameraPresetTestCmd)
	BODY(mt::TBOOL32, bStart)				//TRUE: 开始 FLASE: 结束

    /*<<软件完整性自测试请求>>
	消息流向 : service_hd -> device
	*/
    MESSAGE(Ev_MT_HD_GetSoftIntegritySelfTest_Req)

    /*<<软件完整性自测试回应>>
	消息流向 : device -> service_hd
	*/
    MESSAGE(Ev_MT_HD_GetSoftIntegritySelfTest_Rsp)
	BODY(mt::TU32, dwresult)				//0: 成功 1: 失败
	
	/*<<摄像机操作异常响应>>
	* device -> service_hd
	*/
	MESSAGE(Ev_MT_DeviceCameraOptError_Ntf)
    BODY(mt::TU32, vid_idx)   //摄像机No
    BODY(mt::TU32, EmCameraErrorType)    //通知类型
	
	/*<<摄像机场景模式能力获取>>
	* service_hd -> device
	*/
	MESSAGE(Ev_MT_DeviceCameraSceneMode_Req)
    BODY(mt::TU32, vid_idx)   //摄像机No
	
	/*<<摄像机场景模式能力获取响应>>
	* device -> service_hd
	*/
	MESSAGE(Ev_MT_DeviceCameraSceneMode_Rsp)
    BODY(mt::TU32, vid_idx)   //摄像机No
	BODY(mt::TCameraSceneModeCapList, scenecap)   //场景模式能力
	
	/*<<摄像机场景模式能力设置>>
	* service_hd -> device
	*/
	MESSAGE(Ev_MT_DeviceCameraSceneMode_Cmd)
    BODY(mt::TU32, vid_idx)   //摄像机No
	BODY(mt::TU32, EmCameraSceneMode)   //场景模式
	
	/*<<摄像机场景模式能力设置响应>>
	* device -> service_hd
	*/
	MESSAGE(Ev_MT_DeviceCameraSceneMode_Ntf)
    BODY(mt::TU32, vid_idx)   //摄像机No
	BODY(mt::TU32, EmCameraSceneMode)   //场景模式
	BODY(mt::TU32, result)   //结果
	
	/*<<摄像机e2prom升级>>
	* service_hd -> device
	*/
	MESSAGE(Ev_MT_DeviceCameraE2promUpgrade_Cmd)
    BODY(mt::TU32, vid_idx)   //摄像机No
	
	/*<<摄像机e2prom升级响应>>
	* device -> service_hd
	*/
	MESSAGE(Ev_MT_DeviceCameraE2promUpgrade_Ntf)
    BODY(mt::TU32, vid_idx)   //摄像机No
	BODY(mt::TU32, result)   //结果
	
	/*<<摄像头升级包名称获取>>
    *vid_idx : EmMtVideoPort  接入摄像机的视频源接口
	*camera_type : 升级摄像头类型
	*消息流向 : service==>dispatch==>deivce
	*/
    MESSAGE(Ev_MT_DeviceCameraUpgradePack_Req)
    BODY(mt::TU32, EmMtVideoPort)

    /*<<摄像头升级包名称获取>>
    *vid_idx : EmMtVideoPort  接入摄像机的视频源接口
	*packname: 升级包名称
	*消息流向 : device==>dispatch==>service
	*/
    MESSAGE(Ev_MT_DeviceCameraUpgradePack_Rsp)
    BODY(mt::TU32, EmMtVideoPort)
	BODY(mt::TString, packname)
	
	/*<<网口流量请求>>
	*消息流向 : service==>dispatch==>deivce
	*/
    MESSAGE(Ev_MT_DeviceNetCardStatis_Req)

    /*<<网口流量回应>>
    *NetCardStatisList : mt::TNetCardStatisList  网口流量信息
	*消息流向 : device==>dispatch==>service
	*/
    MESSAGE(Ev_MT_DeviceNetCardStatis_Rsp)
    BODY(mt::TNetCardStatisList, NetCardStatisList)
	
	/*<<网口流量回应>>
    *NetCardStatisList : mt::TNetCardStatisList  网口流量信息
	*消息流向 : net==>dispatch==>device
	*/
    MESSAGE(Ev_MT_DeviceNetCardStatis_Ntf)
    BODY(mt::TNetCardStatisList, NetCardStatisList)
	
	/*<<网口流量开始计算请求>>
	*消息流向 : device==>dispatch==>net
	*interval : 计算间隔多久回调1次
	*/
    MESSAGE(Ev_MT_DeviceNetCardStatisCalcStart_Req)
	BODY(mt::TU32, interval)

    /*<<网口流量回应>>
	*消息流向 : net==>dispatch==>device
	*interval : 计算间隔多久回调1次
	*result   : 结果
	*/
    MESSAGE(Ev_MT_DeviceNetCardStatisCalcStart_Rsp)
    BODY(mt::TU32, interval)
	BODY(mt::TU32, result)
	
	/*<<网口流量结束计算请求>>
	*消息流向 : device==>dispatch==>net
	*/
    MESSAGE(Ev_MT_DeviceNetCardStatisCalcStop_Req)

    /*<<网口流量回应>>
	*消息流向 : net==>dispatch==>device
	*result   : 结果
	*/
    MESSAGE(Ev_MT_DeviceNetCardStatisCalcStop_Rsp)
	BODY(mt::TU32, result)
	
	/*<<创建485串口读线程>>
	*消息流向 : camera==>dispatch==>device
    *point   : 485串口指针
	*/
    MESSAGE(Ev_MT_DeviceRs485Create_Cmd)
    BODY(mt::TU32, point)

    /*<<sky300内置摄像机采集图像获取>>
	*消息流向 : device==>dispatch==>camera
    *vididx   : 摄像机NO
	*/
    MESSAGE(Ev_HD_GetCameraPic_Cmd)
    BODY(mt::TU32, vididx)

#if !defined(_MESSAGE_HELP_)
    EV_END(DEVICE) = EVSEG_DEVICE_END
};
#endif

#define Is_Device_Msg(m) ((m) >= EV_BGN(DEVICE) && (m) <= EV_END(DEVICE))

#endif
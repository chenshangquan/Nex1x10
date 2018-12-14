#ifndef _MTDEVICEMSG_H_
#define _MTDEVICEMSG_H_

#include "mtmsgid.h"

#if !defined(_MESSAGE_HELP_)
enum EmMtDeviceMsg
{
    EV_BGN(DEVICE) = EVSEG_DEVICE_BGN,
#endif
	/*********************************����ͷ�����ϢBegin***************************************/

	/*<<����ͷ��������>>
    *TMTHDCameraList : ����ͷ��������
	*��Ϣ���� : service==>mtdeivce
	*/
	MESSAGE(Ev_MT_DeviceSetCameraList_Cmd)
	BODY(mt::TMTHDCameraList, camera_list)

    /*<<����ͷ�������>>
    *vid_idx : EmCodecComponentIndex  em1st��ʾ��һ·  em2nd��ʾ�ڶ�·
	*camera_idx : ����ͷ���
    *camera_handle : ����ͷ���ڲ������
	*��Ϣ���� : mtdeivce�ڲ��߳�ʹ��
	*/
    MESSAGE(Ev_MT_DeviceSetCameraHandle_Cmd)
    BODY(mt::TU32, vid_idx)
	BODY(mt::TU8, camera_idx)
	BODY(mt::TU32, camera_handle)

    /*<<����ͷѡ��>>
    *vid_idx : EmCodecComponentIndex  em1st��ʾ��һ·  em2nd��ʾ�ڶ�·  em3rd��ʾ�ڶ�·
	*vid_port : EmMtVideoPort
	*��Ϣ���� : service==>dispatch==>deivce
	*/
    MESSAGE(Ev_MT_DeviceCameraSelect_Cmd)
    BODY(mt::TU32, vid_idx)
	BODY(mt::TU32, vid_port)

    /*<<����ͷ����\����>>
    *opt : TRUE��ʾ���� FALSE��ʾ����
	*��Ϣ���� : service==>dispatch==>deivce
	*/
    MESSAGE(Ev_MT_DeviceCameraPower_Cmd)
	BODY(mt::TBOOL32, opt)

	/*<<������ػ�>>
	*��Ϣ���� : device==>dispatch==>deivce
	*/
    MESSAGE(Ev_MT_DevicePowerOff_Cmd)

    /*<<����ͷԤ��λ����>>
    *vid_idx : EmCodecComponentIndex  em1st��ʾ��һ·  em2nd��ʾ�ڶ�·
	*opt : TRUE��ʾ���� FALSE��ʾ����
    *index : ��ǰ������Ԥ��λ����
	*��Ϣ���� : service==>dispatch==>deivce
	*/
    MESSAGE(Ev_MT_DeviceCameraPreset_Req)
    BODY(mt::TU32, vid_idx)
	BODY(mt::TBOOL32, opt)
	BODY(mt::TU8, index)

    /*<<����ͷԤ��λ������Ӧ,�յ�����Ϣ��ʾ��������,��������ʾһ�������ɹ�>>
    *vid_idx : EmCodecComponentIndex  em1st��ʾ��һ·  em2nd��ʾ�ڶ�·
	*opt : TRUE��ʾ���� FALSE��ʾ����
    *index : ��ǰ������Ԥ��λ����
	*��Ϣ���� : mtdevice==>dispatch==>mtservice
	*/
    MESSAGE(Ev_MT_DeviceCameraPreset_Rsp)
    BODY(mt::TU32, vid_idx)
	BODY(mt::TBOOL32, opt)
    BODY(mt::TU8, index)
	BODY(mt::TBOOL32, sucess)

    /*<<��ѯԤ��λͼƬ����>>
    *vid_idx : EmCodecComponentIndex  em1st��ʾ��һ·  em2nd��ʾ�ڶ�·
	*��Ϣ���� : mtservice==>dispatch==>mtdevice
	*see Ev_MT_DeviceQueryCameraPresetPic_Rsp
	*/
    MESSAGE(Ev_MT_DeviceQueryCameraPresetPic_Req)
    BODY(mt::TU32, vid_idx)

    /*<<��ѯԤ��λͼƬ��Ӧ>>
    *vid_idx : EmCodecComponentIndex  em1st��ʾ��һ·  em2nd��ʾ�ڶ�·
	*TMTCameraPresetPicList : ��ǰ������Ԥ��λ����
	*��Ϣ���� : mtdevice==>dispatch==>mtservice
	*see Ev_MT_DeviceQueryCameraPresetPic_Req
	*/
    MESSAGE(Ev_MT_DeviceQueryCameraPresetPic_Rsp)
    BODY(mt::TU32, vid_idx)
	BODY(mt::TMTCameraPresetPicList, pic_name)

    /*<<����ͷ��λ����>>
    *vid_idx : EmCodecComponentIndex  em1st��ʾ��һ·  em2nd��ʾ�ڶ�·
	*direction : EmDirection
    *action : EmAction
	*��Ϣ���� : service==>dispatch==>deivce
	*/
    MESSAGE(Ev_MT_DeviceCameraPantilt_Cmd)
    BODY(mt::TU32, vid_idx)
	BODY(mt::TS32, direction) //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmDirection
	BODY(mt::TS32, action)   //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmAction

    /*<<����ͷ�������>>
    *vid_idx : EmCodecComponentIndex  em1st��ʾ��һ·  em2nd��ʾ�ڶ�·
	*opt : TRUE��ʾԶ�� FALSE��ʾ����
    *action : EmAction
	*��Ϣ���� : service==>dispatch==>deivce
	*/
    MESSAGE(Ev_MT_DeviceCameraFocus_Cmd)
    BODY(mt::TU32, vid_idx)
	BODY(mt::TBOOL32, opt)
	BODY(mt::TS32, action) //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmAction

	/*<<����ͷ�Զ��۽�>>
    *vid_idx : EmCodecComponentIndex  em1st��ʾ��һ·  em2nd��ʾ�ڶ�·
	*��Ϣ���� : service==>dispatch==>deivce
	*/
    MESSAGE(Ev_MT_DeviceCameraAutoFocus_Cmd)
    BODY(mt::TU32, vid_idx)

    /*<<����ͷ��Ұ����>>
    *vid_idx : EmCodecComponentIndex  em1st��ʾ��һ·  em2nd��ʾ�ڶ�·
	*opt : TRUE��ʾԶ�� FALSE��ʾ����
    *action : EmAction
	*��Ϣ���� : service==>dispatch==>deivce
	*/
    MESSAGE(Ev_MT_DeviceCameraZoom_Cmd)
    BODY(mt::TU32, vid_idx)
	BODY(mt::TBOOL32, opt)  
	BODY(mt::TS32, action) //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmAction

    /*<<����ͷ���ȵ���>>
    *vid_idx : EmCodecComponentIndex  em1st��ʾ��һ·  em2nd��ʾ�ڶ�·
	*opt : TRUE��ʾ���� FLASE��ʾ��С
    *action : EmAction
	*��Ϣ���� : service==>dispatch==>deivce
	*/
    MESSAGE(Ev_MT_DeviceCameraBright_Cmd)
    BODY(mt::TU32, vid_idx)
	BODY(mt::TBOOL32, opt)
	BODY(mt::TS32, action) //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmAction
	
	/*<<����ͷ���ȵ���>>
    *vid_idx : EmCodecComponentIndex  em1st��ʾ��һ·  em2nd��ʾ�ڶ�·
	*value : ���õ�����ֵ
	*��Ϣ���� : service==>dispatch==>deivce
	*/
    MESSAGE(Ev_MT_DeviceCameraBrightDirectSet_Cmd)
    BODY(mt::TU32, vid_idx)
	BODY(mt::TU32, value)  // ���õ�ֵ

    /*<<����ͷ���ȵ��ڻ�Ӧ>>
    *vid_idx : EmCodecComponentIndex  em1st��ʾ��һ·  em2nd��ʾ�ڶ�·
	*value : ���õ�����ֵ
	*��Ϣ���� : deivce==>dispatch==>service
	*/
    MESSAGE(Ev_MT_DeviceCameraBrightDirectSet_Ntf)
    BODY(mt::TU32, vid_idx)
	BODY(mt::TU32, value)  // ���õ�ֵ
    BODY(mt::TU32, result)

    /*<<����ͷ���ⲹ��>>
    *vid_idx : EmCodecComponentIndex  em1st��ʾ��һ·  em2nd��ʾ�ڶ�·
    *on : TRUE��ʾ���� FALSE��ʾ�ر�
	*��Ϣ���� : service==>dispatch==>deivce
	*/
    MESSAGE(Ev_MT_DeviceCameraBackLight_Cmd)
    BODY(mt::TU32, vid_idx)
	BODY(mt::TBOOL32, on)

    /*<<����ͷ����>>
    *vid_idx : EmMtVideoPort  �������������ƵԴ�ӿ�
	*camera_type : ��������ͷ����
	*action : TRUE��ʾ��ʼ FLASE��ʾֹͣ
	*file_name : �����ļ���·��
	*��Ϣ���� : service==>dispatch==>deivce
	*/
    MESSAGE(Ev_MT_DeviceCameraUpgrade_Cmd)
    BODY(mt::TU32, vid_idx)
	BODY(mt::TMTCameraUpgrade, camera_upgrade)

    /*<<����ͷ����>>
    *vid_idx : EmMtVideoPort  �������������ƵԴ�ӿ�
	*type : EmEquipmentUpgrading
	*result : TRUE��ʾ�ɹ� FALSE��ʾʧ��
	*��Ϣ���� : device==>dispatch==>service
	*/
    MESSAGE(Ev_MT_DeviceCameraUpgrade_Ntf)
    BODY(mt::TU32, vid_idx)
	BODY(mt::TS32, type) //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmEquipmentUpgrading
	BODY(mt::TS32, error)//ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCameraUpgradeErrCode

	/*<<����ͷ�汾��ѯ>>
    *vid_idx : EmCodecComponentIndex  em1st��ʾ��һ·  em2nd��ʾ�ڶ�·
	*��Ϣ���� : service==>dispatch==>deivce
	*/
    MESSAGE(Ev_MT_DeviceCameraVersion_Req)
    BODY(mt::TU32, vid_idx)

    /*<<����ͷ�汾��ѯ>>
    *vid_idx : EmCodecComponentIndex  em1st��ʾ��һ·  em2nd��ʾ�ڶ�·
	*camera_ver_info : ����ͷ�汾��Ϣ
	*��Ϣ���� : device==>dispatch==>service
	*/
    MESSAGE(Ev_MT_DeviceCameraVersion_Rsp)
    BODY(mt::TU32, vid_idx)
	BODY(mt::TString, camera_ver_info)


    /*<<����ͷ�������Ͳ�ѯ>>
	*��Ϣ���� : service==>dispatch==>device
    *see : Ev_MT_DeviceCameraTypeCapset_Rsp
	*/
	MESSAGE(Ev_MT_DeviceGetCameraTypeCapset_Req)


    /*<<����ͷ���������ϱ�>>
	*camera_type_list : ����֧�ֵ�����ͷ�������Ͳ�ѯ���
	*��Ϣ���� : device==>dispatch==>service
    *see : Ev_MT_DeviceCameraTypeCapset_Req
	*/
	MESSAGE(Ev_MT_DeviceGetCameraTypeCapset_Rsp)
	BODY(mt::TMTCameraTypeList, camera_type_list)


	/*<<����ͷ���������ϱ�>>
	*camera_type_list : ����֧�ֵ�����ͷ���������ϱ�
	*��Ϣ���� : device==>dispatch==>service
	*/
	MESSAGE(Ev_MT_DeviceCameraTypeCapset_Ntf)
	BODY(mt::TMTCameraTypeList, camera_type_list)

	/*<<����ͷ����״̬>>
	*opt_idx : ���������ͱ��
	*opt_state : ������״̬
	*��Ϣ���� : mtdevice�ڲ��߳�ʹ��
	*/
	MESSAGE(Ev_MT_DeviceCameraOpt_Ntf)
	BODY(mt::TU8, opt_idx)
	BODY(mt::TBOOL32, opt_state)

    /*<<��������ͼ��>>
	*��Ϣ���� : deivce==>camera
	*/
    MESSAGE(Ev_MT_DeviceCameraTypeCheck_Cmd)

   /*********************************����ͷ�����ϢEnd***************************************/



   /*********************************ң���������ϢBegin************************************/

   /*<<ң��������֪ͨ>>
   *key_type : TRUE��ʾkeyup  FALSE��ʾkeydown
   *key_source : ������Դ
   *key_code : ������ֵ
   *key_count : ��������
   *��Ϣ���� : device==>dispatch==>service
   */
   MESSAGE(Ev_MT_DeviceKeyCodeNtf)
   BODY(mt::TMTKeyPressInfo, key_press_info)

   /*<<ʵ��ң��������֪ͨ(����ʹ��)>>
   *key_type : TRUE��ʾkeyup  FALSE��ʾkeydown
   *key_source : ������Դ
   *key_code : ������ֵ
   *key_count : ��������
   *��Ϣ���� : device==>dispatch==>service
   */
   MESSAGE(Ev_MT_EntityDeviceKeyCodeNtf)
   BODY(mt::TMTKeyPressInfo, key_press_info)
   
   /*********************************ң���������ϢEnd************************************/

   	/*<<�������ò���>>
	*uart_cfg : ����������Ϣ
	*��Ϣ���� : service==>mtdevice
	*/
	MESSAGE(Ev_MT_DeviceSerialCtrlCfg_Cmd)
	BODY(mt::TMTHDSerialCtrl, uart_cfg)

   	/*<<����mic����>>
	*uart_num : �����豸��
	*path : �����ļ�·��
	*��Ϣ���� : service==>dispatch==>device
	*/
    MESSAGE(Ev_MT_DeviceDMicUpgrade_Cmd)
	BODY(mt::TS32, uart_num)					//ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmUartNum
	BODY(mt::TString, path)

	/*<<����mic����>>
	*uart_num : �����豸��
	*result : ������� TRUE��ʾ�����ɹ�
	*��Ϣ���� : deivce==>dispatch==>service
	*/
	MESSAGE(Ev_MT_DeviceDMicUpgrade_Ntf)
	BODY(mt::TS32, uart_num)				   //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmUartNum
	BODY(mt::TBOOL32, result)

	/*<<����mic�汾��ѯ>>
	*uart_num : �����豸��
	*��Ϣ���� : service==>dispatch==>device
	*/
	MESSAGE(Ev_MT_DeviceDMicVersion_Req)
	BODY(mt::TS32, uart_num)				  //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmUartNum

	/*<<����mic�汾��ѯ>>
	*uart_num : �����豸��
	*ver : �汾��
	*��Ϣ���� : device==>dispatch==>service
	*/
	MESSAGE(Ev_MT_DeviceDMicVersion_Rsp)
	BODY(mt::TS32, uart_num)				 //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmUartNum
	BODY(mt::TString, ver)

	/*<<����mic����>>
	*uart_num : �����豸��
	*path : �����ļ�·��
	*��Ϣ���� : service==>dispatch==>device
	*/
    MESSAGE(Ev_MT_DeviceWMicUpgrade_Cmd)
	BODY(mt::TS32, uart_num)
	BODY(mt::TString, path)

	/*<<����mic����>>
	*uart_num : �����豸��
	*result : ������� TRUE��ʾ�����ɹ�
	*��Ϣ���� : deivce==>dispatch==>service
	*/
	MESSAGE(Ev_MT_DeviceWMicUpgrade_Ntf)
	BODY(mt::TS32, uart_num)
	BODY(mt::TBOOL32, result)

	/*<<����mic�汾��ѯ>>
	*uart_num : �����豸��
	*��Ϣ���� : service==>dispatch==>device
	*/
	MESSAGE(Ev_MT_DeviceWMicVersion_Req)
	BODY(mt::TS32, uart_num)

	/*<<����mic�汾��ѯ>>
	*uart_num : �����豸��
	*ver : �汾��
	*��Ϣ���� : device==>dispatch==>service
	*/
	MESSAGE(Ev_MT_DeviceWMicVersion_Rsp)
	BODY(mt::TS32, uart_num)
	BODY(mt::TString, ver)

	/*<<������ֵ�ϱ���Ϣ>>
	*uart_type : ��������
	*code : ���ֽ���ֵ
	*��Ϣ���� : deivce�ڲ�
	*/
	MESSAGE(Ev_MT_DeviceSerialRecvByte_Ntf)
	BODY(mt::TU8, uart_type)
	BODY(mt::TU8, code)

	/*<<���ڿ�ֵ�ϱ���Ϣ>>
	*uart_type : ��������
	*��Ϣ���� : deivce�ڲ�
	*/
	MESSAGE(Ev_MT_DeviceSerialRecvNone_Ntf)
	BODY(mt::TU8, uart_type)

	/*<<��ѯcpu���ڴ�ʹ���������>>
	*��Ϣ���� : service==>device
	* see Ev_MT_DeviceDetectCpuAndMem_Rsp
	*/
	MESSAGE(Ev_MT_DeviceDetectCpuAndMem_Req)

	/*<<��ѯcpu���ڴ�ʹ�������Ӧ>>
	*cpuandmemsts : cpu���ڴ�ʹ�����
	*��Ϣ���� : device==>service
	* see Ev_MT_DeviceDetectCpuAndMem_Req
	*/
	MESSAGE(Ev_MT_DeviceDetectCpuAndMem_Rsp)
	BODY(mt::TMTCpuAndMemState, cpuandmemsts)


    /*------��������--------*/
    /*<<����������������>>
    *serial_type : ��������
	*��Ϣ���� : service==>device
	* see Ev_MT_DeviceSerialTest_Rsp
	*/
	MESSAGE(Ev_MT_DeviceSerialTest_Req)
	BODY(mt::TS32, serial_type)

	/*<<���ڹر�����>>
    *serial_type : ��������
	*��Ϣ���� : mtservice==>device
	* see
	*/
	MESSAGE(Ev_MT_CloseSerialCom_Cmd)
	BODY(mt::TS32, serial_type)


    /*<<��ѯcpu���ڴ�ʹ�������Ӧ>>
	*result : ���Խ��
	*serial_type : ��������
	*��Ϣ���� : device==>service
	* see Ev_MT_DeviceSerialTest_Req
	*/
    MESSAGE(Ev_MT_DeviceSerialTest_Rsp)
    BODY(mt::TBOOL32, result)
    BODY(mt::TS32, serial_type)

    /*<<ң�����������Կ�ʼ�����֪ͨ>>
    *install : �򿪻�ر�
	*��Ϣ���� : service==>device
	* see Ev_MT_DeviceRemoteCtrlTest_Ntf
	*/
    MESSAGE(Ev_MT_DeviceRemoteCtrlTest_Cmd)
    BODY(mt::TBOOL32, install)

    /*<<ң�����������Լ�ֵ����>>
	*result : ���Խ��
	*scan_code : ��ֵ
	*��Ϣ���� : device==>service
	* see Ev_MT_DeviceRemoteCtrlTest_Cmd
	*/
    MESSAGE(Ev_MT_DeviceRemoteCtrlTest_Ntf)
    BODY(mt::TBOOL32, result)
    BODY(mt::TU8, scan_code)

	/*<<ң�����汾���ϱ�>>
	*byRemoteCtrlVersion : ң�����汾��
	*��Ϣ���� : misc==>ui
	*/
    MESSAGE(Ev_MT_DeviceRemoteCtrlVersion_Ntf)
    BODY(mt::TString, byRemoteCtrlVersion)


	/*<<����֪ͨ>>
	* ui -> misc
	*/
    MESSAGE(Ev_MT_UserOperation_Ntf)
	BODY(mt::TBOOL32, is_key_power_press)	//�Ƿ������


	/*<<��ui���ʹ�������ʱ֪ͨ>>
	* misc -> ui
	*/
	MESSAGE(Ev_MT_SleepCountDown_Ntf)
	BODY(mt::TS32, count_down)	//����ʱʱ��

	/*<<֪ͨ�ն˴���״̬>>
	* misc -> ui
	*/
	MESSAGE(Ev_MT_SleepState_Ntf)
	BODY(mt::TS32, EmMtSleepState)	//����״̬

	/*<<��ui��������ϵͳ֪ͨ>>
	* misc -> ui
	*/
	MESSAGE(Ev_MT_OqcResetSystem_Ntf)

	/*<<�����ն�>>
	* ui -> misc
	*/
	MESSAGE(Ev_MT_RebootSystem_Cmd)
	

	/*<<�ֶ�����ϵͳʱ��>>
	* ui -> misc
	*/
	MESSAGE(Ev_MT_SetSystemTime_Cmd)
	BODY(mt::TMTTime, time)				//Ҫ���õ�ʱ��


	/*<<ϵͳ�ָ���������>>
    *is_oqc : true��ʾ��Ҫɾ������, false��ʾ����Ҫɾ������
	* ui -> misc
	*/
	MESSAGE(Ev_MT_ResetSystem_Cmd)
	BODY(mt::TBOOL32, is_oqc)

	/*<<����ʽץ������>>
	* ui -> misc
	*/
	MESSAGE(Ev_MT_StartNetCapture_Cmd)
    BODY(mt::TU32, capture_nettype)  //ץ������ѡ�� EmNetAdapterWorkType

	/*<<ֹͣץ������>>
	* ui -> misc
	*/
	MESSAGE(Ev_MT_StopNetCapture_Cmd)

	/*<<��ȡ��ǰץ��״̬>>
	* service -> misc
	*/
	MESSAGE(Ev_MT_GetCurCapStatus_Req)

	/*<<��ȡ��ǰץ��״̬��Ӧ>>
	* service <- misc
	*/
	MESSAGE(Ev_MT_GetCurCapStatus_Rsp)
	BODY(mt::TU32, capture_state)	 // 1:����ץ��  0:û��ץ��
	BODY(mt::TMTTime, curtime)		 // ץ����ʼʱ��(�ϰ汾ʹ��)
	BODY(mt::TU32, lastCaptime)		 // �ϴ�ץ��ʱ�䣨��λ���룩
    BODY(mt::TU32, startcaptime)     // �ϴ�ץ��ʱ�䣨�°汾ʹ�� ��λ���룩

	/*<<ץ��״̬֪ͨ>>
	* misc -> ui
	*/
	MESSAGE(Ev_MT_NetCaptureState_Ntf)
	BODY(mt::TU32, capture_state)	 // MT_SUCCESS:����ץ��  MT_FAILED:����ץ��ʧ��
	BODY(mt::TMTTime, curtime)		 // ץ����ʼʱ��
	BODY(mt::TU32, lastCaptime)		 // �ϴ�ץ��ʱ�䣨��λ�����룩

	/*<<ץ���ļ��б��ѯ>>
	* service -> device
	*/
	MESSAGE(Ev_MT_GetNetCapFileList_Req)

	/*<<ץ���ļ��б��ѯ>>
	* device -> service
	*/
	MESSAGE(Ev_MT_GetNetCapFileList_Rsp)
	BODY(mt::TNetCapFileList, netcaplist)	//ץ���ļ��б�

	/*<<ɾ��ץ���ļ�>>
	* service -> device
	*/
	MESSAGE(Ev_MT_DeleteNetCapFile_Cmd)

    /*<<ɾ��ץ���ļ�>>
	* device -> service_hd
	*/
	MESSAGE(Ev_MT_DeleteNetCapFile_Ntf)
    BODY(mt::TU32, result)

	/*<<����ץ���ļ�����>>
	* ui -> misc
	*/
	MESSAGE(Ev_MT_ExportNetCapture_Req)
	BODY(mt::TString, export_file_path)	//�ļ�����·��

	/*<<����ץ���ļ�����֪ͨ>>
	* ui -> misc
	*/
	MESSAGE(Ev_MT_ExportNetCaptureProgress_Ntf)
	BODY(mt::TU32, percent)	//����ٷֱ�


	/*<<����ץ���ļ���Ӧ>>
	* misc -> ui
	*/
	MESSAGE(Ev_MT_ExportNetCapture_Rsp)
	BODY(mt::TU32, is_ok)	//MT_SUCCESS:�ɹ�
							//ERR_MTMISC_DISK_OUTOF_SPACE �ռ䲻��
							//ERR_MTMISC_FILE_NOT_EXIST  �ļ�������

	/*<<��ȡ��ǰץ��״̬>>
	* service -> misc
	*/
	MESSAGE(Ev_MT_GetPacketDurationTime_Req)

	/*<<��ȡ��ǰץ��״̬��Ӧ>>
	* service <- misc
	*/
	MESSAGE(Ev_MT_GetPacketDurationTime_Rsp)
	BODY(mt::TU32, DurationTime )	 // ץ������ʱ��

	/*<<������־����>>
	* ui -> misc
	*/
	MESSAGE(Ev_MT_ExportLog_Req)
	BODY(mt::TString, export_file_path)	//�ļ�����·��

	/*<<������־����֪ͨ>>
	* ui -> misc
	*/
	MESSAGE(Ev_MT_ExportLogProgress_Ntf)
	BODY(mt::TU32, percent)	//����ٷֱ�


	/*<<������־��Ӧ>>
	* misc -> ui
	*/
	MESSAGE(Ev_MT_ExportLog_Rsp)
	BODY(mt::TU32, is_ok)	
    //MT_SUCCESS:�ɹ�
    //ERR_MTMISC_DISK_OUTOF_SPACE �ռ䲻��
    //ERR_MTMISC_PATH_NOT_EXIST ����·��������
    //ERR_MTMISC_FILE_NOT_EXIST ��־�ļ�������
    //...



    /*<<����ļ�����>>
    * ��Ϣ���� : service -> device
    * ���� : file_path   ������ʼĿ¼
    * ���� : file_name   �����ļ���
    * ���� : is_recurse  �Ƿ����������Ŀ¼
    * see : Ev_MT_FileExistCheck_Rsp
	*/
    MESSAGE(Ev_MT_FileExistCheck_Req)
    BODY(mt::TString, file_path)
    BODY(mt::TString, file_name)
    BODY(mt::TBOOL32, is_recurse)

    /*<<����ļ���Ӧ>>
    * ��Ϣ���� : device -> service
    * ���� : is_exist        �����ļ��Ƿ����
    * ���� : file_full_path  �����ļ�ȫ·��(�����ļ���)
    * ���� : file_size       �����ļ���С
    * see : Ev_MT_FileExistCheck_Req
	*/
    MESSAGE(Ev_MT_FileExistCheck_Rsp)
    BODY(mt::TBOOL32, is_exist)
    BODY(mt::TString, file_full_path)
    BODY(mt::TU32, file_size)



    /*<<������ַ������>>
    * ��Ϣ���� : service -> device
    * ���� : dst_path    ����Ŀ��·��
    * see : Ev_MT_AddrBookExport_Rsp
	*/
    MESSAGE(Ev_MT_AddrBookExport_Req)
    BODY(mt::TString, dst_path)

    /*<<����ļ���Ӧ>>
    * ��Ϣ���� : device -> service
    * ���� : err_code      �Ƿ�ɹ� mt::EmFileCopyErr
    * see : Ev_MT_AddrBookExport_Req
	*/
    MESSAGE(Ev_MT_AddrBookExport_Rsp)
    BODY(mt::TS32, err_code)

    /*<<������ַ���ٷֱ�>>
    * ��Ϣ���� : device -> service
    * ���� : progress      �ٷֱ�
    * see : Ev_MT_AddrBookExport_Req
	*/
    MESSAGE(Ev_MT_AddrBookExportProgress_Ntf)
    BODY(mt::TU32, progress)



    /*<<�����ַ������>>
    * ��Ϣ���� : service -> device
    * ���� : dst_path    ����Դ·��(���ļ���)
    * see : Ev_MT_AddrBookImport_Rsp
	*/
    MESSAGE(Ev_MT_AddrBookImport_Req)
    BODY(mt::TString, src_path)


    /*<<�����ַ����Ӧ>>
    * ��Ϣ���� : device -> service
    * ���� : err_code      �Ƿ�ɹ� mt::EmFileCopyErr
    * see : Ev_MT_AddrBookImport_Req
	*/
    MESSAGE(Ev_MT_AddrBookImport_Rsp)
    BODY(mt::TS32, err_code)

    /*<<�����ַ���ٷֱ�>>
    * ��Ϣ���� : device -> service
    * ���� : progress      �ٷֱ�
    * see : Ev_MT_AddrBookExport_Req
	*/
    MESSAGE(Ev_MT_AddrBookImportProgress_Ntf)
    BODY(mt::TU32, progress)




    /*<<�����ַ������>>
    * ��Ϣ���� : service -> device
    * ���� : dst_path    ����Դ·��(���ļ���)
    * see : Ev_MT_MicUpgradeFileImport_Rsp
    *       Ev_MT_MicUpgradeFileImportProgress_Ntf
	*/
    MESSAGE(Ev_MT_MicUpgradeFileImport_Req)
    BODY(mt::TString, src_path)


    /*<<�����ַ����Ӧ>>
    * ��Ϣ���� : device -> service
    * ���� : err_code      �Ƿ�ɹ� mt::EmFileCopyErr
    * see : Ev_MT_MicUpgradeFileImport_Req
	*/
    MESSAGE(Ev_MT_MicUpgradeFileImport_Rsp)
    BODY(mt::TS32, err_code)

    /*<<�����ַ���ٷֱ�>>
    * ��Ϣ���� : device -> service
    * ���� : progress      �ٷֱ�
    * see : Ev_MT_MicUpgradeFileImport_Req
	*/
    MESSAGE(Ev_MT_MicUpgradeFileImportProgress_Ntf)
    BODY(mt::TU32, progress)

    /*<<Ŀ¼�ṹ��ѯ����>>
	* ��Ϣ���� : service -> device
    * ��    �� : src_path   ��ѯ·��
    * see : Ev_MT_InquirePathStructure_Rsp
	*/
    MESSAGE(Ev_MT_InquirePathStructure_Req)
    BODY(mt::TString, src_path)

    /*<<Ŀ¼�ṹ��ѯ��Ӧ>>
	* ��Ϣ���� : device -> service
    * ���� : src_path           ��ѯ·��
    *        path_detail_list   ·������
    * see : Ev_MT_InquirePathStructure_Req
	*/
    MESSAGE(Ev_MT_InquirePathStructure_Rsp)
    BODY(mt::TString, src_path)
    BODY(mt::TMTPathStructureDetail, path_detail_list)

	/*<<��ѯ�ն˳����Ƿ�ȫ�������ɹ�����>>
	* ��Ϣ���� : service -> mtmanage
    * see : Ev_MT_InquireHDMtStartSucess_Rsp
	*/
    MESSAGE(Ev_MT_InquireHDMtStartSucess_Req)

	/*<<��ѯ�ն˳����Ƿ�ȫ�������ɹ���Ӧ>>
	* ��Ϣ���� : mtmanage -> service
	* ���� : sucess       �ɹ�/ʧ��
    * see : Ev_MT_InquireHDMtStartSucess_Req
	*/
    MESSAGE(Ev_MT_InquireHDMtStartSucess_Rsp)
    BODY(mt::TBOOL32, sucess)

	/*<<�ն˳���ȫ�������ɹ�֪ͨ>>
	* ��Ϣ���� : mtmanage -> service
    * see : 
	*/
    MESSAGE(Ev_MT_HDMtStartSucess_Ntf)

    /*********************************��˷������ϢBeg***************************************/

	/*<<��˷�����״̬����>>
	*��Ϣ���� : service==>dispatch==>deivce
	*/
    MESSAGE(Ev_MT_MicrophoneConnectStatus_Req)

	/*<<��˷�����״̬Ӧ��>>
	*��Ϣ���� : service==>dispatch==>deivce
	*/
    MESSAGE(Ev_MT_MicrophoneConnectStatus_Rsp)
	BODY(mt::TMTMicInfo, ConnectStatus)

	/*<<��˷�����״̬�ϱ�>>
	*��Ϣ���� : service==>dispatch==>deivce
	*/
    MESSAGE(Ev_MT_MicrophoneConnectStatus_Ntf)
	BODY(mt::TMTMicInfo, ConnectStatus)

	/*<<��˷����ߵ�������>>
	*��Ϣ���� : service==>dispatch==>deivce
	*/
    MESSAGE(Ev_MT_MicrophoneBatteryLevel_Req)

	/*<<��˷����ߵ���Ӧ��>>
	*��Ϣ���� : service<==dispatch<==deivce
	*/
    MESSAGE(Ev_MT_MicrophoneBatteryLevel_Rsp)
	BODY(mt::TMTMicInfo, BatteryLevel)

	/*<<��˷����ߵ����ϱ�>>
	*��Ϣ���� : service==>dispatch==>deivce
	*/
    MESSAGE(Ev_MT_MicrophoneBatteryLevel_Ntf)
	BODY(mt::TMTMicInfo, BatteryLevel)

	/*<<������˷�������ͣ�����һ���ϱ�>>
	*��Ϣ���� : device==>dispatch==>service
	*/
	MESSAGE(Ev_MT_WirelessMicrophoneBatteryLow_Ntf)
	BODY(mt::TBOOL32, IsLow)

	/*<<��˷������ź�����>>
	*��Ϣ���� : service==>dispatch==>deivce
	*/
	MESSAGE(Ev_MT_MicrophoneWirelessSignal_Req)

	/*<<��˷������ź�Ӧ��>>
	*��Ϣ���� : service==>dispatch==>deivce
	*/
	MESSAGE(Ev_MT_MicrophoneWirelessSignal_Rsp)

	/*<<��˷������ź��ϱ�>>
	*��Ϣ���� : service==>dispatch==>deivce
	*/
	MESSAGE(Ev_MT_MicrophoneWirelessSignal_Ntf)

	/*<<֪ͨ/user/fileimg�еİ汾���Ѹ���>>
	*��Ϣ���� : service==>dispatch==>device
	*fileType: ��Ҫ���õİ汾�� 1: wind3d.bin.tar ; 2: skyshare_setup.tar
	*/
	MESSAGE(Ev_MT_ResetUserFileimg_Cmd)
	BODY(mt::TU32, fileType)

	/*<<��˷�����״̬����>>
	*��Ϣ���� : sdk==>dispatch==>service
	*/
	MESSAGE(Ev_MT_MicrophoneState_Req)

	/*<<��˷�����״̬Ӧ��(mt::TMicUpgradeStateList)>>
	*��Ϣ���� : service==>dispatch==>sdk
	*/
	MESSAGE(Ev_MT_MicrophoneState_Rsp)
	BODY(mt::TMicUpgradeStateList, state)

	/*<<��˷�����״̬�ϱ�(mt::TMicUpgradeStateList)>>
	*��Ϣ���� : service==>dispatch==>sdk
	*/
	MESSAGE(Ev_MT_MicrophoneState_Ntf)
	BODY(mt::TMicUpgradeStateList, state)

	/*<<��˷��ϴ�����(����)>>
	*��Ϣ���� : service==>dispatch==>sdk
	*/
	MESSAGE(Ev_MT_MicrophoneUpload_Cmd)

	/*<<��˷��ϴ������ϱ�(����)>>
	*��Ϣ���� : service==>dispatch==>sdk
	*/
	MESSAGE(Ev_MT_MicrophoneUpload_Ntf)
	BODY(mt::TU32, progress)

	/*<<��˷簲װ����(mt::TMicInstallList)>>
	*��Ϣ���� : sdk==>dispatch==>service
	*/
	MESSAGE(Ev_MT_MicrophoneInstall_Cmd)
	BODY(mt::TMicInstallList, install)

	/*<<��˷���°��ϴ�״̬����(����)>>
	*��Ϣ���� : service==>dispatch==>deivce
	*/
    MESSAGE(Ev_MT_MicrophoneVersionStatus_Req)

	/*<<��˷���°��ϴ�״̬Ӧ��(����)>>
	*��Ϣ���� : service<==dispatch<==deivce
	*/
    MESSAGE(Ev_MT_MicrophoneVersionStatus_Rsp)
	BODY(mt::TMTMicInfo, VersionStatus)

	/*<<��˷���°��ϴ�״̬�ϱ�(����)>>
	*��Ϣ���� : service<==dispatch<==deivce
	*/
    MESSAGE(Ev_MT_MicrophoneVersionStatus_Ntf)
	BODY(mt::TMTMicInfo, VersionStatus)

	/*<<��˷���������(����)>>
	*��Ϣ���� : service==>dispatch==>deivce
	*/
    MESSAGE(Ev_MT_MicrophoneUpgrade_Cmd)
	BODY(mt::TMTMicInfo, IsUpgrade)

	/*<<��˷������ϱ�(����)>>
	*��Ϣ���� : deivce==>dispatch==>service
	*/
    MESSAGE(Ev_MT_MicrophoneUpgrade_Ntf)
	BODY(mt::TMTMicInfo, UpgradeState)

	/*<<��˷�����״̬����>>
	*��Ϣ���� : service==>dispatch==>deivce
	*/
    MESSAGE(Ev_MT_MicrophoneMute_Req)

	/*<<��˷�����״̬Ӧ��>>
	*��Ϣ���� : service==>dispatch==>deivce
	*/
    MESSAGE(Ev_MT_MicrophoneMute_Rsp)

	/*<<��˷���������>>
	*��Ϣ���� : service==>dispatch==>deivce
	*/
    MESSAGE(Ev_MT_MicrophoneMute_Cmd)

	/*<<��˷�����״̬�ϱ�>>
	*��Ϣ���� : service<==dispatch<==deivce
	*/
    MESSAGE(Ev_MT_MicrophoneMute_Ntf)

    /*<<��˷�汾��Ϣ��ѯ>>
	*��Ϣ���� : service==>dispatch==>deivce
	*/
    MESSAGE(Ev_MT_MicrophoneInfo_Req)

    /*<<��˷�汾��ϢӦ��>>
	*��Ϣ���� : device==>dispatch==>service
	*/
    MESSAGE(Ev_MT_MicrophoneInfo_Rsp)
	BODY(mt::TMicVersionList, VerInfo)

	/*<<��˷�汾��Ϣ�ϱ�>>
	*��Ϣ���� : device==>dispatch==>service
	*/
    MESSAGE(Ev_MT_MicrophoneInfo_Ntf)
	BODY(mt::TMicVersionList, VerInfo)

	/*<<�ն˱������˷�汾��Ϣ��ѯ>>
	*��Ϣ���� : service==>dispatch==>deivce
	*/
    MESSAGE(Ev_MT_TermKeepMicrophoneInfo_Req)
	BODY( NULL , NULL )

	/*<<�ն˱������˷�汾��Ϣ��ѯ>>
	*��Ϣ���� : service==>dispatch==>deivce
	*/
    MESSAGE(Ev_MT_TermKeepMicrophoneInfo_Rsp)
	BODY( mt::TString , tStrTermKeepMicVer )

	/*<<������Ƶ�ȵ�����>>
	*��Ϣ���� : service==>dispatch==>deivce
	*/
    MESSAGE(Ev_MT_OpenHotspot_Req)
	BODY(mt::TMTMicInfo, IsOpenHotspot)

	/*<<������Ƶ�ȵ�Ӧ��>>
	*��Ϣ���� : service==>dispatch==>deivce
	*/
    MESSAGE(Ev_MT_OpenHotspot_Rsp)
	BODY(mt::TMTMicInfo, HotspotState)

	/*<<��Ƶ״̬����>>
	*��Ϣ���� : service==>dispatch==>deivce
	*/
    MESSAGE(Ev_MT_Hotspot_State_Req)

    /*<<��Ƶ״̬Ӧ��>>
	*��Ϣ���� : device==>dispatch==>service
	*/
    MESSAGE(Ev_MT_Hotspot_State_Rsp)
	BODY(mt::TMTMicInfo, HotspotState)

	/*<<������USB��������>>
	*��Ϣ���� : dispatch==>deivce
	*/
    MESSAGE(Ev_MT_MicrophoneUsbTest_Cmd)

    /*<<������USB����Ӧ��>>
	*��Ϣ���� : device==>dispatch
	*/
    MESSAGE(Ev_MT_MicrophoneUsbTest_Ntf)
	BODY(mt::TMTMicInfo, IsUsbOk)

	/*<<��Ƶƥ��״̬�ϱ�>>
	*��Ϣ���� : device==>dispatch
	*/
	MESSAGE(Ev_MT_RfMatchStateListCfg_Ntf)
	BODY(mt::TMTRfMatchStateList, MatchState)

    /*********************************��˷������ϢEnd***************************************/

	/*<<������˳���������>>
	* register_state : �Ƿ��¼
	* mtmfgtest==>dispatch==>mtservice
	*/
	MESSAGE(Ev_MT_MfgTestRegisterInOrOut_Ntf)
	BODY(mt::TBOOL32, register_state)

	/*<<Visca��������>>
	*SerialType   : ��������EmSerialType
	*ViscaCommand : ��������
	*��Ϣ���� : AID_DEVICECTRL==>AID_CAMERACTRL
	*/
	MESSAGE(Ev_MT_ViscaCommand_Cmd)
	BODY(mt::TU32, SerialType)
	BODY(mt::TString, ViscaCommand)

	/*<<���������ͼ��ģʽ>>
	*value  :  EmImgMode
    *vid_idx : EmCodecComponentIndex  em1st��ʾ��һ·  em2nd��ʾ�ڶ�·
	��Ϣ���� : mtservice==>dispatch==>mtdevice
	*/
	MESSAGE(Ev_MT_ImgMode_Cmd)
	BODY(mt::TU32, EmImgMode)
    BODY(mt::TU32, vid_idx)
	
	/*<<���������ͼ��ģʽ���>>
	*value  :  EmImgMode
    *vid_idx : EmCodecComponentIndex  em1st��ʾ��һ·  em2nd��ʾ�ڶ�·
    *value  :  result
	��Ϣ���� : mtdevice==>dispatch==>mtservice
	*/
	MESSAGE(Ev_MT_ImgMode_Ntf)
	BODY(mt::TU32, EmImgMode)
    BODY(mt::TU32, vid_idx)
    BODY(mt::TU32, result)

	/*<<�����������������>>
	*value  :  BOOL32
    *vid_idx : EmCodecComponentIndex  em1st��ʾ��һ·  em2nd��ʾ�ڶ�·
	��Ϣ���� : mtservice==>dispatch==>mtdevice
	*/
	MESSAGE(Ev_MT_PersonFirst_Cmd)
	BODY(mt::TBOOL32, BOOL32)
    BODY(mt::TU32, vid_idx)
	
	/*<<�������������������Ӧ>>
	*value  :  BOOL32
    *vid_idx : EmCodecComponentIndex  em1st��ʾ��һ·  em2nd��ʾ�ڶ�·
    *value  :  result
	��Ϣ���� : mtdevice==>dispatch==>mtservice
	*/
	MESSAGE(Ev_MT_PersonFirst_Ntf)
	BODY(mt::TBOOL32, BOOL32)
    BODY(mt::TU32, vid_idx)
    BODY(mt::TU32, result)

	/*<<����Isp����>>
	*EmNFType     :
	*value  :  0-10
	*vid_idx : EmCodecComponentIndex  em1st��ʾ��һ·  em2nd��ʾ�ڶ�·
	��Ϣ���� : mtservice==>dispatch==>mtmpapp
	*/
	MESSAGE(Ev_MT_IspImgInf_Noise_Cmd)
	BODY(mt::TU32, EmNFType)
	BODY(mt::TU32, value)
	BODY(mt::TU32, vid_idx)
	
	/*<<����Isp����>>
	*EmNFType     :
	*value  :  0-10
	��Ϣ���� : mtservice==>dispatch==>mtmpapp
	*/
	MESSAGE(Ev_MT_IspImgInf_Noise_Ntf)
	BODY(mt::TU32, EmNFType)
	BODY(mt::TU32, value)
    BODY(mt::TU32, vid_idx)
    BODY(mt::TU32, result)

	/*<<����Isp���>>
	*value     :0-10
	*vid_idx : EmCodecComponentIndex  em1st��ʾ��һ·  em2nd��ʾ�ڶ�·
	��Ϣ���� : mtservice==>dispatch==>mtmpapp
	*/
	MESSAGE(Ev_MT_IspImgInf_Sharpness_Cmd)
	BODY(mt::TU32, value)
	BODY(mt::TU32, vid_idx)
	
	/*<<����Isp���>>
	*value     :0-10
    *vid_idx : EmCodecComponentIndex  em1st��ʾ��һ·  em2nd��ʾ�ڶ�·
    *result  : 0�ɹ�
	��Ϣ���� : mtmpapp==>dispatch==>mtservice
	*/
	MESSAGE(Ev_MT_IspImgInf_Sharpness_Ntf)
	BODY(mt::TU32, value)
    BODY(mt::TU32, vid_idx)
    BODY(mt::TU32, result)

	/*<<����Isp�ع�����>>
	*EmExposureModeGainType     :0:auto;1:manual
	*value     :0-10
	*vid_idx : EmCodecComponentIndex  em1st��ʾ��һ·  em2nd��ʾ�ڶ�·
	��Ϣ���� : mtservice==>dispatch==>mtmpapp
	*/
	MESSAGE(Ev_MT_IspImgInf_ExposureModeGain_Cmd)
	BODY(mt::TU32, EmExposureModeGainType)
	BODY(mt::TU32, value)
	BODY(mt::TU32, vid_idx)
	
	/*<<����Isp�ع�����>>
	*EmExposureModeGainType     :0:auto;1:manual
	*value     :0-10
    *vid_idx : EmCodecComponentIndex  em1st��ʾ��һ·  em2nd��ʾ�ڶ�·
    *result : 0�ɹ�������ʧ��
	��Ϣ���� : mtmpapp==>dispatch==>mtservice
	*/
	MESSAGE(Ev_MT_IspImgInf_ExposureModeGain_Ntf)
	BODY(mt::TU32, EmExposureModeGainType)
	BODY(mt::TU32, value)
    BODY(mt::TU32, vid_idx)
    BODY(mt::TU32, result)

	/*<<����Isp��ƽ������>>
	*EmExposureModeGainType     :0:��;1:��
	*value     :0-255
	*vid_idx : EmCodecComponentIndex  em1st��ʾ��һ·  em2nd��ʾ�ڶ�·
	��Ϣ���� : mtservice==>dispatch==>mtmpapp
	*/
	MESSAGE(Ev_MT_IspImgInf_WhiteBalanceGain_Cmd)
	BODY(mt::TU32, EMWBAModeGainType)
	BODY(mt::TU32, value)
	BODY(mt::TU32, vid_idx)
	
	/*<<����Isp��ƽ��������Ӧ>>
	*EmExposureModeGainType     :0:��;1:��
	*value     :0-255
    *vid_idx : EmCodecComponentIndex  em1st��ʾ��һ·  em2nd��ʾ�ڶ�·
    *result : 0�ɹ�������ʧ��
	��Ϣ���� : mtmpapp==>dispatch==>mtservice
	*/
	MESSAGE(Ev_MT_IspImgInf_WhiteBalanceGain_Ntf)
	BODY(mt::TU32, EMWBAModeGainType)
	BODY(mt::TU32, value)
    BODY(mt::TU32, vid_idx)
    BODY(mt::TU32, result)

	/*<<����Isp���ⲹ������>>
	*value     :0:��;1:��
	��Ϣ���� : mtservice==>dispatch==>mtmpapp
	*/
	MESSAGE(Ev_MT_IspImgInf_BackLightSwitch_Cmd)
	BODY(mt::TBOOL32, value)

	/*<<����Isp���ⲹ���ȼ�>>
	*��value��0��0-15
	��Ϣ���� : mtservice==>dispatch==>mtmpapp
	*/
	MESSAGE(Ev_MT_IspImgInf_BackLightLevel_Cmd)
	BODY(mt::TU32, value)

	/*<<����Isp�й��>>
	*EmISO      :
	��Ϣ���� : mtservice==>dispatch==>mtmpapp
	*/
	MESSAGE(Ev_MT_IspImgInf_ISO_Cmd)
	BODY(mt::TU32, EmISO)

	/*<<����Isp�ع�ģʽ>>
	*EmExposureMode      :
    *vid_idx : EmCodecComponentIndex  em1st��ʾ��һ·  em2nd��ʾ�ڶ�·
	��Ϣ���� : mtservice==>dispatch==>mtmpapp
	*/
	MESSAGE(Ev_MT_IspImgInf_ExposureMode_Cmd)
	BODY(mt::TU32, EmExposureMode)
    BODY(mt::TU32, vid_idx)
	
	/*<<����Isp�ع���Ӧ>>
	*EmExposureMode      :
    *vid_idx : EmCodecComponentIndex  em1st��ʾ��һ·  em2nd��ʾ�ڶ�·
    result
	��Ϣ���� : mtmpapp==>dispatch==>mtservice
	*/
	MESSAGE(Ev_MT_IspImgInf_ExposureMode_Ntf)
	BODY(mt::TU32, EmExposureMode)
    BODY(mt::TU32, vid_idx)
    BODY(mt::TU32, result)

	/*<<����Isp��Ȧ��С>>
	*EmAperture      :
	*vid_idx : EmCodecComponentIndex  em1st��ʾ��һ·  em2nd��ʾ�ڶ�·
	��Ϣ���� : mtservice==>dispatch==>mtmpapp
	*/
	MESSAGE(Ev_MT_IspImgInf_Aperture_Cmd)
	BODY(mt::TU32, EmAperture)
	BODY(mt::TU32, vid_idx)
	
	/*<<����Isp��Ȧ��С>>
	*EmAperture      :
    *vid_idx : EmCodecComponentIndex  em1st��ʾ��һ·  em2nd��ʾ�ڶ�·
    *result : 0�ɹ�������ʧ��
	��Ϣ���� : mtservice==>dispatch==>mtmpapp
	*/
	MESSAGE(Ev_MT_IspImgInf_Aperture_Ntf)
	BODY(mt::TU32, EmAperture)
    BODY(mt::TU32, vid_idx)
    BODY(mt::TU32, result)

	/*<<����Isp�����ٶ�>>
	*EmAperture      :
	*vid_idx : EmCodecComponentIndex  em1st��ʾ��һ·  em2nd��ʾ�ڶ�·
	��Ϣ���� : mtservice==>dispatch==>mtmpapp
	*/
	MESSAGE(Ev_MT_IspImgInf_Shutter_Cmd)
	BODY(mt::TU32, EmShutterLevel)
	BODY(mt::TU32, vid_idx)
	
    /*<<����Isp�����ٶ�>>
	*EmAperture      :
    *vid_idx : EmCodecComponentIndex  em1st��ʾ��һ·  em2nd��ʾ�ڶ�·
    *result : 0�ɹ�������ʧ��
	��Ϣ���� : mtmpapp==>dispatch==>mtservice
	*/
	MESSAGE(Ev_MT_IspImgInf_Shutter_Ntf)
	BODY(mt::TU32, EmShutterLevel)
    BODY(mt::TU32, vid_idx)
    BODY(mt::TU32, result)

	/*<<����Isp����>>
	*�ع�Ϊ�Զ�ģʽ���ȵ��ڲ���Ч���ع�Ϊ�ֶ�ģʽ�����ȵ�����Ч
	*EmBrightnessDirection:
	��Ϣ���� : mtservice==>dispatch==>mtmpapp
	*/
	MESSAGE(Ev_MT_IspImgInf_Brightnesss_Cmd)
	BODY(mt::TU32, EmBrightnessDirection)

	/*<<����Isp�����>>
	*�Զ����⣬���߹ر�
	*EmBrightnessDirection:
	��Ϣ���� : mtdevice==>dispatch==>mtmpapp
	*/
	MESSAGE(Ev_MT_IspImgInf_BackLight_Cmd)
	BODY(mt::TBOOL32, bAuto)

	/*<<����Isp��ƽ��>>
	*EmWBAMode      :
	*vid_idx : EmCodecComponentIndex  em1st��ʾ��һ·  em2nd��ʾ�ڶ�·
	��Ϣ���� : mtservice==>dispatch==>mtmpapp
	*/
	MESSAGE(Ev_MT_IspImgInf_WhiteBalance_Cmd)
	BODY(mt::TU32, EmWBAMode)
	BODY(mt::TU32, vid_idx)
	
	/*<<����Isp��ƽ����Ӧ>>
	*EmWBAMode      :
    *vid_idx : EmCodecComponentIndex  em1st��ʾ��һ·  em2nd��ʾ�ڶ�·
    *result : 0�ɹ�������ʧ��
	��Ϣ���� : mtmpapp==>dispatch==>mtservice
	*/
	MESSAGE(Ev_MT_IspImgInf_WhiteBalance_Ntf)
	BODY(mt::TU32, EmWBAMode)
    BODY(mt::TU32, vid_idx)
    BODY(mt::TU32, result)

	/*<<����Ispͼ�����>>
	*emInterface : Ispͼ��ӿ�EmIspImgInterface
	*dwReason    : 0 ʧ�ܣ�1 �ɹ�
	��Ϣ���� : mtservice<==dispatch<==mtmpapp
	*/
	MESSAGE(Ev_MT_IspImgInf_Ntf)
	BODY(mt::TU32, EmIspImgInf)
	BODY(mt::TU32, dwReason)

	/*<<����Ispͼ������>>
	��Ϣ���� : mtservice==>dispatch==>mtmpapp
	*/
	MESSAGE(Ev_MT_IspSetBrightImgParam_Cmd)
	BODY(mt::TU32, dwValue)

	/*<<����Ispͼ��ɫ��>>
	��Ϣ���� : mtservice==>dispatch==>mtmpapp
	*/
	MESSAGE(Ev_MT_IspSetHueImgParam_Cmd)
	BODY(mt::TU32, dwValue)

	/*<<����Ispͼ��Աȶ�>>
	��Ϣ���� : mtservice==>dispatch==>mtmpapp
	*/
	MESSAGE(Ev_MT_IspSetContrastImgParam_Cmd)
	BODY(mt::TU32, EmImgParam)
	BODY(mt::TU32, dwValue)

	/*<<����Ispͼ�񱥺Ͷ�>>
	��Ϣ���� : mtservice==>dispatch==>mtmpapp
	*/
	MESSAGE(Ev_MT_IspSetSaturationImgParam_Cmd)
	BODY(mt::TU32, EmImgParam)
	BODY(mt::TU32, dwValue)

	/*<<����Ispͼ��٤��>>
	��Ϣ���� : mtservice==>dispatch==>mtmpapp
	*/
	MESSAGE(Ev_MT_IspSetGammmaImgParam_Cmd)
	BODY(mt::TU32, dwValue)
	BODY(mt::TU32, vid_idx)
	
	/*<<����Ispͼ��٤��>>
	��Ϣ���� : mtmpapp==>dispatch==>mtservice
	*/
	MESSAGE(Ev_MT_IspSetGammmaImgParam_Ntf)
	BODY(mt::TU32, dwValue)
	BODY(mt::TU32, vid_idx)
	BODY(mt::TU32, result)

	/*<<����Ispͼ������ȥ��>>
	��Ϣ���� : mtservice==>dispatch==>mtmpapp
	*/
	MESSAGE(Ev_MT_IspSetDefogImgParam_Cmd)
	BODY(mt::TU32, dwValue)

	/*<<����Ispͼ�����ֿ�̬����>>
	��Ϣ���� : mtservice==>dispatch==>mtmpapp
	*/
	MESSAGE(Ev_MT_IspSetDigDynSwitchImgParam_Cmd)
	BODY(mt::TBOOL32, dwValue)

	/*<<����Ispͼ�����ֿ�̬�ȼ�>>
	��Ϣ���� : mtservice==>dispatch==>mtmpapp
	*/
	MESSAGE(Ev_MT_IspSetDigDynLevelParam_Cmd)
	BODY(mt::TU32, dwValue)

	/*<<�����������>>
	*EmWBAMode      :
	��Ϣ���� : mtdevice==>mtmpapp
	*/
	MESSAGE(Ev_MT_IspImgAction_Cmd)
	BODY(mt::TU32, EmIspActionType)
	BODY(mt::TU32, dwValue)

	/*<<���û�о��ʽ>>
	*dwValue      :
	��Ϣ���� : mtdevice==>mtmpapp
	*/
	MESSAGE(Ev_SetCameraVidStd_Cmd)
	BODY(mt::TU32, EmCameraVidStd)

	/*<<������ϻ�����>>
	*dwValue      :
	��Ϣ���� : mtdevice ==> mtdevice
	*/
	MESSAGE(Ev_MT_DeviceCameraAgingTestCmd)
	BODY(mt::TBOOL32, bStart)


    /*<<���������Ϣ�ļ�����>>
	* ui -> misc
	*/
	MESSAGE(Ev_MT_ExportDiagInfo_Cmd)
	BODY(mt::TString, export_file_path)	//�ļ�����·��

	/*<<���������Ϣ�ļ�����֪ͨ>>
	* ui -> misc
	*/
	MESSAGE(Ev_MT_ExportDiagInfoProgress_Ntf)
	BODY(mt::TU32, percent)	//����ٷֱ�


	/*<<���������Ϣ�ļ���Ӧ>>
	* misc -> ui
	*/
	MESSAGE(Ev_MT_ExportDiagInfo_Ntf)
	BODY(mt::TU32, is_ok)	//MT_SUCCESS:�ɹ�
							//ERR_MTMISC_DISK_OUTOF_SPACE �ռ䲻��
							//ERR_MTMISC_FILE_NOT_EXIST  �ļ�������
	BODY(mt::TString, export_file_path)	//�ļ�����·��

    /*<<���������Ϣ�ļ�>>
	* ui -> misc
	*/
	MESSAGE(Ev_MT_DiagInfoGet_Cmd)
	BODY(mt::TU32, data_type)	//�����Ϣ����
    BODY(mt::TString, export_file_path)	//�ļ�����·��

	/*<<���������Ϣ�ļ���Ӧ>>
	* misc -> ui
	*/
	MESSAGE(Ev_MT_DiagInfoGet_Ntf)
	BODY(mt::TU32, data_type)  //�����Ϣ����
    BODY(mt::TString, export_file_path)	//�ļ�����·��
    BODY(mt::TU32, result)    //������

    /*<<ѡ�񴮿ڹ�����ʹ��>>
	* service -> device
	*/
	MESSAGE(Ev_MT_ChooseSerialUse_Cmd)
	BODY(mt::TMTHDSerialCtrl, serial_use)	//��������
    BODY(mt::TBOOL32, serial_use)	//�Ƿ�ʹ��

	/*<<ѡ�񴮿ڹ�����ʹ����Ӧ>>
	* device -> service
	*/
	MESSAGE(Ev_MT_ChooseSerialUse_Ntf)
    BODY(mt::TMTHDSerialCtrl, serial_use)	//��������
    BODY(mt::TBOOL32, serial_use)	//�Ƿ�ʹ��
    BODY(mt::TS32, result)    //������

        /*<<ѡ�񴮿ڹ�����ʹ��>>
	* service -> device
	*/
	MESSAGE(Ev_MT_OperaterSerial_Cmd)
    BODY(mt::TSerialOptParam, serial_info)	//��д��Ϣ

	/*<<ѡ�񴮿ڹ�����ʹ����Ӧ>>
	* device -> service
	*/
	MESSAGE(Ev_MT_OperaterSerial_Ntf)
    BODY(mt::TSerialOptParam, serial_info)	//��д��Ϣ
    BODY(mt::TS32, result)    //������

	/*<<�����������������PTZ����>>
	��Ϣ���� : service -> device
	*/
    MESSAGE(Ev_MT_DeviceCameraPTZTestCmd)
	BODY(mt::TBOOL32, bStart)				//TRUE: ��ʼ FLASE: ����

	/*<<�����������������Ԥ��λ����>>
	��Ϣ���� : service -> device
	*/
    MESSAGE(Ev_MT_DeviceCameraPresetTestCmd)
	BODY(mt::TBOOL32, bStart)				//TRUE: ��ʼ FLASE: ����

    /*<<����������Բ�������>>
	��Ϣ���� : service_hd -> device
	*/
    MESSAGE(Ev_MT_HD_GetSoftIntegritySelfTest_Req)

    /*<<����������Բ��Ի�Ӧ>>
	��Ϣ���� : device -> service_hd
	*/
    MESSAGE(Ev_MT_HD_GetSoftIntegritySelfTest_Rsp)
	BODY(mt::TU32, dwresult)				//0: �ɹ� 1: ʧ��
	
	/*<<����������쳣��Ӧ>>
	* device -> service_hd
	*/
	MESSAGE(Ev_MT_DeviceCameraOptError_Ntf)
    BODY(mt::TU32, vid_idx)   //�����No
    BODY(mt::TU32, EmCameraErrorType)    //֪ͨ����
	
	/*<<���������ģʽ������ȡ>>
	* service_hd -> device
	*/
	MESSAGE(Ev_MT_DeviceCameraSceneMode_Req)
    BODY(mt::TU32, vid_idx)   //�����No
	
	/*<<���������ģʽ������ȡ��Ӧ>>
	* device -> service_hd
	*/
	MESSAGE(Ev_MT_DeviceCameraSceneMode_Rsp)
    BODY(mt::TU32, vid_idx)   //�����No
	BODY(mt::TCameraSceneModeCapList, scenecap)   //����ģʽ����
	
	/*<<���������ģʽ��������>>
	* service_hd -> device
	*/
	MESSAGE(Ev_MT_DeviceCameraSceneMode_Cmd)
    BODY(mt::TU32, vid_idx)   //�����No
	BODY(mt::TU32, EmCameraSceneMode)   //����ģʽ
	
	/*<<���������ģʽ����������Ӧ>>
	* device -> service_hd
	*/
	MESSAGE(Ev_MT_DeviceCameraSceneMode_Ntf)
    BODY(mt::TU32, vid_idx)   //�����No
	BODY(mt::TU32, EmCameraSceneMode)   //����ģʽ
	BODY(mt::TU32, result)   //���
	
	/*<<�����e2prom����>>
	* service_hd -> device
	*/
	MESSAGE(Ev_MT_DeviceCameraE2promUpgrade_Cmd)
    BODY(mt::TU32, vid_idx)   //�����No
	
	/*<<�����e2prom������Ӧ>>
	* device -> service_hd
	*/
	MESSAGE(Ev_MT_DeviceCameraE2promUpgrade_Ntf)
    BODY(mt::TU32, vid_idx)   //�����No
	BODY(mt::TU32, result)   //���
	
	/*<<����ͷ���������ƻ�ȡ>>
    *vid_idx : EmMtVideoPort  �������������ƵԴ�ӿ�
	*camera_type : ��������ͷ����
	*��Ϣ���� : service==>dispatch==>deivce
	*/
    MESSAGE(Ev_MT_DeviceCameraUpgradePack_Req)
    BODY(mt::TU32, EmMtVideoPort)

    /*<<����ͷ���������ƻ�ȡ>>
    *vid_idx : EmMtVideoPort  �������������ƵԴ�ӿ�
	*packname: ����������
	*��Ϣ���� : device==>dispatch==>service
	*/
    MESSAGE(Ev_MT_DeviceCameraUpgradePack_Rsp)
    BODY(mt::TU32, EmMtVideoPort)
	BODY(mt::TString, packname)
	
	/*<<������������>>
	*��Ϣ���� : service==>dispatch==>deivce
	*/
    MESSAGE(Ev_MT_DeviceNetCardStatis_Req)

    /*<<����������Ӧ>>
    *NetCardStatisList : mt::TNetCardStatisList  ����������Ϣ
	*��Ϣ���� : device==>dispatch==>service
	*/
    MESSAGE(Ev_MT_DeviceNetCardStatis_Rsp)
    BODY(mt::TNetCardStatisList, NetCardStatisList)
	
	/*<<����������Ӧ>>
    *NetCardStatisList : mt::TNetCardStatisList  ����������Ϣ
	*��Ϣ���� : net==>dispatch==>device
	*/
    MESSAGE(Ev_MT_DeviceNetCardStatis_Ntf)
    BODY(mt::TNetCardStatisList, NetCardStatisList)
	
	/*<<����������ʼ��������>>
	*��Ϣ���� : device==>dispatch==>net
	*interval : ��������ûص�1��
	*/
    MESSAGE(Ev_MT_DeviceNetCardStatisCalcStart_Req)
	BODY(mt::TU32, interval)

    /*<<����������Ӧ>>
	*��Ϣ���� : net==>dispatch==>device
	*interval : ��������ûص�1��
	*result   : ���
	*/
    MESSAGE(Ev_MT_DeviceNetCardStatisCalcStart_Rsp)
    BODY(mt::TU32, interval)
	BODY(mt::TU32, result)
	
	/*<<��������������������>>
	*��Ϣ���� : device==>dispatch==>net
	*/
    MESSAGE(Ev_MT_DeviceNetCardStatisCalcStop_Req)

    /*<<����������Ӧ>>
	*��Ϣ���� : net==>dispatch==>device
	*result   : ���
	*/
    MESSAGE(Ev_MT_DeviceNetCardStatisCalcStop_Rsp)
	BODY(mt::TU32, result)
	
	/*<<����485���ڶ��߳�>>
	*��Ϣ���� : camera==>dispatch==>device
    *point   : 485����ָ��
	*/
    MESSAGE(Ev_MT_DeviceRs485Create_Cmd)
    BODY(mt::TU32, point)

    /*<<sky300����������ɼ�ͼ���ȡ>>
	*��Ϣ���� : device==>dispatch==>camera
    *vididx   : �����NO
	*/
    MESSAGE(Ev_HD_GetCameraPic_Cmd)
    BODY(mt::TU32, vididx)

#if !defined(_MESSAGE_HELP_)
    EV_END(DEVICE) = EVSEG_DEVICE_END
};
#endif

#define Is_Device_Msg(m) ((m) >= EV_BGN(DEVICE) && (m) <= EV_END(DEVICE))

#endif
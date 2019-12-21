#ifndef _MTBLLDEVICEMSG_H_
#define _MTBLLDEVICEMSG_H_

#include "mtmsgid.h"

#if !defined(_MESSAGE_HELP_)
enum EmBLLMtDeviceMsg
{
    EV_BLL_BGN(DEVICE) = EVSEG_BLL_DEVICE_BGN,
#endif

	/*********************************����ͷ�����ϢBegin***************************************/

    /*<<����ͷѡ��>>
    *vid_idx : EmCodecComponentIndex  em1st��ʾ��һ·  em2nd��ʾ�ڶ�·
    *vid_port : EmMtVideoPort
	*��Ϣ���� : sdk==>dispatch==>deivce
	*/
    MESSAGE(Ev_MT_BLL_DeviceCameraSelect_Cmd)
    BODY(mt::TU32, vid_idx)
    BODY(mt::TU8, vid_port)

	/*<<����ͷ����\����>>
    *opt : TRUE��ʾ���� FALSE��ʾ����
	*��Ϣ���� : sdk==>dispatch==>deivce
	*/
    MESSAGE(Ev_MT_BLL_DeviceCameraPower_Cmd)
    BODY(mt::TBOOL32, opt)

    /*<<����ͷԤ��λ��������>>
    *vid_idx : EmCodecComponentIndex  em1st��ʾ��һ·  em2nd��ʾ�ڶ�·
	*opt : TRUE��ʾ���� FALSE��ʾ����
    *index : ��ǰ������Ԥ��λ����
	*��Ϣ���� : sdk==>dispatch==>mtservice
	*see Ev_MT_BLL_DeviceCameraPreset_Rsp
	*/
    MESSAGE(Ev_MT_BLL_DeviceCameraPreset_Req)
    BODY(mt::TU32, vid_idx)
	BODY(mt::TBOOL32, opt)
    BODY(mt::TU8, index)

    /*<<����ͷԤ��λ������Ӧ,�յ�����Ϣ��ʾ��������,��������ʾһ�������ɹ�>>
    *vid_idx : EmCodecComponentIndex  em1st��ʾ��һ·  em2nd��ʾ�ڶ�·
	*opt : TRUE��ʾ���� FALSE��ʾ����
	*index : ��ǰ������Ԥ��λ����
	*��Ϣ���� : mtservice==>dispatch==>sdk
	*see Ev_MT_BLL_DeviceCameraPreset_Req
	*/
    MESSAGE(Ev_MT_BLL_DeviceCameraPreset_Rsp)
    BODY(mt::TU32, vid_idx)
	BODY(mt::TBOOL32, opt)
	BODY(mt::TU8, index)
    BODY(mt::TBOOL32, sucess)

    /*<<��ѯԤ��λͼƬ����>>
    *vid_idx : EmCodecComponentIndex  em1st��ʾ��һ·  em2nd��ʾ�ڶ�·
	*��Ϣ���� : sdk==>dispatch==>mtservice
	*see Ev_MT_BLL_DeviceQueryCameraPresetPic_Rsp
	*/
    MESSAGE(Ev_MT_BLL_DeviceQueryCameraPresetPic_Req)
    BODY(mt::TU32, vid_idx)

    /*<<��ѯԤ��λͼƬ��Ӧ>>
    *vid_idx : EmCodecComponentIndex  em1st��ʾ��һ·  em2nd��ʾ�ڶ�·
	*TMTCameraPresetPicList : ��ǰ������Ԥ��λ����
	*��Ϣ���� : mtservice==>dispatch==>sdk
	*see Ev_MT_BLL_DeviceQueryCameraPresetPic_Req
	*/
    MESSAGE(Ev_MT_BLL_DeviceQueryCameraPresetPic_Rsp)
    BODY(mt::TU32, vid_idx)
	BODY(mt::TMTCameraPresetPicList, pic_name)

    /*<<����ͷ��λ����>>
    *vid_idx : EmCodecComponentIndex  em1st��ʾ��һ·  em2nd��ʾ�ڶ�·
	*direction : EmDirection
    *action : EmAction
	*��Ϣ���� : sdk==>dispatch==>deivce
	*/
    MESSAGE(Ev_MT_BLL_DeviceCameraPantilt_Cmd)
    BODY(mt::TU32, vid_idx)
	BODY(mt::TS32, direction) //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmDirection
    BODY(mt::TS32, action)   //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmAction

    /*<<����ͷ�������>>
    *vid_idx : EmCodecComponentIndex  em1st��ʾ��һ·  em2nd��ʾ�ڶ�·
	*opt : TRUE��ʾԶ�� FALSE��ʾ����
    *action : EmAction
	*��Ϣ���� : sdk==>dispatch==>deivce
	*/
    MESSAGE(Ev_MT_BLL_DeviceCameraFocus_Cmd)
    BODY(mt::TU32, vid_idx)
	BODY(mt::TBOOL32, opt)
    BODY(mt::TS32, action) //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmAction

    /*<<����ͷ�Զ��۽�>>
    *vid_idx : EmCodecComponentIndex  em1st��ʾ��һ·  em2nd��ʾ�ڶ�·
	*��Ϣ���� : sdk==>dispatch==>deivce
	*/
    MESSAGE(Ev_MT_BLL_DeviceCameraAutoFocus_Cmd)
    BODY(mt::TU32, vid_idx)

    /*<<����ͷ��Ұ����>>
    *vid_idx : EmCodecComponentIndex  em1st��ʾ��һ·  em2nd��ʾ�ڶ�·
	*opt : TRUE��ʾԶ�� FALSE��ʾ����
    *action : EmAction
	*��Ϣ���� : sdk==>dispatch==>deivce
	*/
    MESSAGE(Ev_MT_BLL_DeviceCameraZoom_Cmd)
    BODY(mt::TU32, vid_idx)
	BODY(mt::TBOOL32, opt)  
    BODY(mt::TS32, action) //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmAction

    /*<<����ͷ���ȵ���>>
    *vid_idx : EmCodecComponentIndex  em1st��ʾ��һ·  em2nd��ʾ�ڶ�·
	*opt : TRUE��ʾ���� FLASE��ʾ��С
    *action : EmAction
	*��Ϣ���� : sdk==>dispatch==>deivce
	*/
    MESSAGE(Ev_MT_BLL_DeviceCameraBright_Cmd)
    BODY(mt::TU32, vid_idx)
	BODY(mt::TBOOL32, opt)
    BODY(mt::TS32, action) //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmAction

    /*<<����ͷ���ⲹ��>>
    *vid_idx : EmCodecComponentIndex  em1st��ʾ��һ·  em2nd��ʾ�ڶ�·
    *on : TRUE��ʾ���� FALSE��ʾ�ر�
	*��Ϣ���� : sdk==>dispatch==>deivce
	*/
    MESSAGE(Ev_MT_BLL_DeviceCameraBackLight_Cmd)
    BODY(mt::TU32, vid_idx)
    BODY(mt::TBOOL32, on)

    /*<<����ͷ����>>
    *vid_idx : EmMtVideoPort  �������������ƵԴ�ӿ�
	*camera_type : ��������ͷ����
	*action : TRUE��ʾ��ʼ FLASE��ʾֹͣ
	*file_name : �����ļ���·��
	*��Ϣ���� : sdk==>dispatch==>deivce
	*/
    MESSAGE(Ev_MT_BLL_DeviceCameraUpgrade_Cmd)
    BODY(mt::TU32, vid_idx)
	BODY(mt::TMTCameraUpgrade, camera_upgrade)

    /*<<����ͷ����>>
    *vid_idx : EmMtVideoPort  �������������ƵԴ�ӿ�
	*type : EmEquipmentUpgrading
	*result : TRUE��ʾ�ɹ� FALSE��ʾʧ��
	*��Ϣ���� : device==>dispatch==>sdk
	*/
    MESSAGE(Ev_MT_BLL_DeviceCameraUpgrade_Ntf)
    BODY(mt::TU32, vid_idx)
	BODY(mt::TS32, type) //ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmEquipmentUpgrading
	BODY(mt::TS32, error)//ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmCameraUpgradeErrCode

    /*<<����ͷ�汾��ѯ>>
    *vid_idx : EmCodecComponentIndex  em1st��ʾ��һ·  em2nd��ʾ�ڶ�·
    *vid_type : 0��ʾ��һ·  1��ʾ�ڶ�·
	*��Ϣ���� : sdk==>dispatch==>deivce
	*/
    MESSAGE(Ev_MT_BLL_DeviceCameraVersion_Req)
    BODY(mt::TU32, vid_idx)

    /*<<����ͷ�汾��ѯ>>
    *vid_idx : EmCodecComponentIndex  em1st��ʾ��һ·  em2nd��ʾ�ڶ�·
	*camera_ver_info : ����ͷ�汾��Ϣ
	*��Ϣ���� : device==>dispatch==>sdk
	*/
    MESSAGE(Ev_MT_BLL_DeviceCameraVersion_Rsp)
    BODY(mt::TU32, vid_idx)
	BODY(mt::TString, camera_ver_info)
	
	/*<<����ͷ���Ȳ�ѯ>>
    *vid_idx : EmCodecComponentIndex  em1st��ʾ��һ·  em2nd��ʾ�ڶ�·
	*��Ϣ���� : sdk==>dispatch==>mtservice
	*/
    MESSAGE(Ev_MT_BLL_DeviceCameraBright_Req)
    BODY(mt::TU32, vid_idx)

    /*<<����ͷ���Ȳ�ѯ��Ӧ>>
    *vid_idx : EmCodecComponentIndex  em1st��ʾ��һ·  em2nd��ʾ�ڶ�·
	*camera_bright : ����ͷ������Ϣ
	*��Ϣ���� : mtservice==>dispatch==>sdk
	*/
    MESSAGE(Ev_MT_BLL_DeviceCameraBright_Rsp)
    BODY(mt::TU32, vid_idx)
	BODY(mt::TU32, camera_bright)

    /*<<����ͷ�������Ͳ�ѯ>>
	*��Ϣ���� : sdk==>dispatch==>service
    *see : Ev_MT_BLL_DeviceCameraTypeCapset_Rsp
	*/
	MESSAGE(Ev_MT_BLL_DeviceGetCameraTypeCapset_Req)


    /*<<����ͷ���������ϱ�>>
	*camera_type_list : ����֧�ֵ�����ͷ�������Ͳ�ѯ���
	*��Ϣ���� : service==>dispatch==>sdk
    *see : Ev_MT_BLL_DeviceCameraTypeCapset_Req
	*/
	MESSAGE(Ev_MT_BLL_DeviceGetCameraTypeCapset_Rsp)
	BODY(mt::TMTCameraTypeList, camera_type_list)



	/*<<����ͷ���������ϱ�>>
	*camera_type_list : ����֧�ֵ�����ͷ���������ϱ�
	*��Ϣ���� : service==>dispatch==>sdk
	*/
	MESSAGE(Ev_MT_BLL_DeviceCameraTypeCapset_Ntf)
	BODY(mt::TMTCameraTypeList, camera_type_list)

   /*********************************����ͷ�����ϢEnd***************************************/

   
   
   /*********************************ң���������ϢBegin************************************/

   /*<<ң��������֪ͨ>>
   *key_type : TRUE��ʾkeyup  FALSE��ʾkeydown
   *key_source : ������Դ
   *key_code : ������ֵ
   *key_count : ��������
   *��Ϣ���� : device==>dispatch==>sdk
   */
   MESSAGE(Ev_MT_BLL_DeviceKeyCodeNtf)
   BODY(mt::TMTKeyPressInfo, key_press_info)

   /*<<ʵ��ң��������֪ͨ(����ʹ��)>>
   *key_type : TRUE��ʾkeyup  FALSE��ʾkeydown
   *key_source : ������Դ
   *key_code : ������ֵ
   *key_count : ��������
   *��Ϣ���� : device==>dispatch==>sdk
   */
   MESSAGE(Ev_MT_BLL_EntityDeviceKeyCodeNtf)
   BODY(mt::TMTKeyPressInfo, key_press_info)
   
   /*********************************ң���������ϢEnd************************************/



    /*<<����mic����>>
	*uart_num : �����豸��
	*path : �����ļ�·��
	*��Ϣ���� : sdk==>dispatch==>device
	*/
    MESSAGE(Ev_MT_BLL_DeviceDMicUpgrade_Cmd)
	BODY(mt::TS32, uart_num)							//ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmUartNum
	BODY(mt::TString, path)

	/*<<����mic����>>
	*uart_num : �����豸��
	*result : ������� TRUE��ʾ�����ɹ�
	*��Ϣ���� : deivce==>dispatch==>sdk
	*/
	MESSAGE(Ev_MT_BLL_DeviceDMicUpgrade_Ntf)
	BODY(mt::TS32, uart_num)						//ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmUartNum
	BODY(mt::TBOOL32, result)

	/*<<����mic�汾��ѯ>>
	*uart_num : �����豸��
	*��Ϣ���� : sdk==>dispatch==>device
	*/
	MESSAGE(Ev_MT_BLL_DeviceDMicVersion_Req)
	BODY(mt::TS32, uart_num)						//ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmUartNum

	/*<<����mic�汾��ѯ>>
	*uart_num : �����豸��
	*ver : �汾��
	*��Ϣ���� : device==>dispatch==>sdk
	*/
	MESSAGE(Ev_MT_BLL_DeviceDMicVersion_Rsp)
	BODY(mt::TS32, uart_num)						//ö��ֵͳһʹ��mt::TS32�����䣬�ô�ʵ��Ϊmt::EmUartNum
	BODY(mt::TString, ver)

	/*<<����mic����>>
	*uart_num : �����豸��
	*path : �����ļ�·��
	*��Ϣ���� : sdk==>dispatch==>device
	*/
    MESSAGE(Ev_MT_BLL_DeviceWMicUpgrade_Cmd)
	BODY(mt::TS32, uart_num)
	BODY(mt::TString, path)

	/*<<����mic����>>
	*uart_num : �����豸��
	*result : ������� TRUE��ʾ�����ɹ�
	*��Ϣ���� : deivce==>dispatch==>sdk
	*/
	MESSAGE(Ev_MT_BLL_DeviceWMicUpgrade_Ntf)
	BODY(mt::TS32, uart_num)
	BODY(mt::TBOOL32, result)

	/*<<����mic�汾��ѯ>>
	*uart_num : �����豸��
	*��Ϣ���� : sdk==>dispatch==>device
	*/
	MESSAGE(Ev_MT_BLL_DeviceWMicVersion_Req)
	BODY(mt::TS32, uart_num)

	/*<<����mic�汾��ѯ>>
	*uart_num : �����豸��
	*ver : �汾��
	*��Ϣ���� : device==>dispatch==>sdk
	*/
	MESSAGE(Ev_MT_BLL_DeviceWMicVersion_Rsp)
	BODY(mt::TS32, uart_num)
	BODY(mt::TString, ver)

	/*<<��ѯcpu���ڴ�ʹ���������>>
	*��Ϣ���� : mtsdk->mtservice
	* see Ev_MT_BLL_DeviceDetectCpuAndMem_Rsp
	*/
	MESSAGE(Ev_MT_BLL_DeviceDetectCpuAndMem_Req)

	/*<<��ѯcpu���ڴ�ʹ�������Ӧ>>
	*cpu : cpuʹ����
	*memory : �ڴ�ʹ�����
	*��Ϣ���� : mtservice->mtsdk
	* see Ev_MT_BLL_DeviceDetectCpuAndMem_Req
	*/
	MESSAGE(Ev_MT_BLL_DeviceDetectCpuAndMem_Rsp)
	BODY(mt::TMTCpuAndMemState, cpuandmemsts)


    /*------��������--------*/
    /*<<����������������>>
    *serial_type : ��������
	*��Ϣ���� : mfgtest->service
	* see Ev_MT_BLL_DeviceSerialTest_Rsp
	*/
    MESSAGE(Ev_MT_BLL_DeviceSerialTest_Req)
    BODY(mt::TS32, serial_type)

	/*<<���ڹر�����>>
    *serial_type : ��������
	*��Ϣ���� : mtservice==>device
	* see
	*/
	MESSAGE(Ev_MT_BLL_CloseSerialCom_Cmd)
	BODY(mt::TS32, serial_type)

    /*<<��ѯcpu���ڴ�ʹ�������Ӧ>>
	*result : ���Խ��
	*serial_type : ��������
	*��Ϣ���� : service->mfgtest
	* see Ev_MT_BLL_DeviceSerialTest_Req
	*/
    MESSAGE(Ev_MT_BLL_DeviceSerialTest_Rsp)
    BODY(mt::TBOOL32, result)
    BODY(mt::TS32, serial_type)

    /*<<ң�����������Կ�ʼ�����֪ͨ>>
    *install : �򿪻�ر�
	*��Ϣ���� : mfgtest->service
	* see Ev_MT_BLL_DeviceRemoteCtrlTest_Ntf
	*/
    MESSAGE(Ev_MT_BLL_DeviceRemoteCtrlTest_Cmd)
    BODY(mt::TBOOL32, install)

    /*<<ң�����������Լ�ֵ����>>
	*result : ���Խ��
	*scan_code : ��ֵ
	*��Ϣ���� : service->mfgtest
	* see Ev_MT_BLL_DeviceRemoteCtrlTest_Cmd
	*/
    MESSAGE(Ev_MT_BLL_DeviceRemoteCtrlTest_Ntf)
    BODY(mt::TBOOL32, result)
    BODY(mt::TU8, scan_code)

	/*<<ң�����汾���ϱ�>>
	*byRemoteCtrlVersion : ң�����汾��
	*��Ϣ���� : misc==>ui
	*/
    MESSAGE(Ev_MT_BLL_DeviceRemoteCtrlVersion_Ntf)
    BODY(mt::TString, byRemoteCtrlVersion)


	////���õ�ǰ��������ͷ��Զ�˻��Ǳ���
	MESSAGE( Ev_MT_BLL_DeviceCameraCtrlSite_Cmd )
	BODY(mt::TU32, tSite)

	////���õ�ǰ��������ͷ��Զ�˻��Ǳ���
	MESSAGE( Ev_MT_BLL_DeviceCameraCtrlSite_Ntf )
	BODY(mt::TU32, tSite)


	/*<<����֪ͨ>>
	* ui -> misc
	*/
    MESSAGE(Ev_MT_BLL_UserOperation_Ntf)
	BODY(mt::TBOOL32, is_key_power_press)	//�Ƿ������


	/*<<��ui���ʹ�������ʱ֪ͨ>>
	* misc -> ui
	*/
	MESSAGE(Ev_MT_BLL_SleepCountDown_Ntf)
	BODY(mt::TS32, count_down)	//����ʱʱ��

	/*<<֪ͨ�ն˴���״̬>>
	* misc -> ui
	*/
	MESSAGE(Ev_MT_BLL_SleepState_Ntf)
	BODY(mt::TS32, EmMtSleepState)	//����״̬

	/*<<��ui��������ϵͳ֪ͨ>>
	* misc -> ui
	*/
	MESSAGE(Ev_MT_BLL_OqcResetSystem_Ntf)

	/*<<�����ն�>>
	* ui -> misc
	*/
	MESSAGE(Ev_MT_BLL_RebootSystem_Cmd)

	

	/*<<�ֶ�����ϵͳʱ��>>
	* ui -> misc
	*/
	MESSAGE(Ev_MT_BLL_SetSystemTime_Cmd)
	BODY(mt::TMTTime, time)				//Ҫ���õ�ʱ��


	/*<<ϵͳ�ָ���������>>
	*is_oqc : true��ʾ��Ҫɾ������, false��ʾ����Ҫɾ������
	* ui -> misc
	*/
	MESSAGE(Ev_MT_BLL_ResetSystem_Cmd)
	BODY(mt::TBOOL32, is_oqc)
	
	/*<<ϵͳ�ָ���������>>
	*is_oqc : true��ʾ��Ҫɾ������, false��ʾ����Ҫɾ������
	* service -> sdk
	*/
	MESSAGE(Ev_MT_BLL_ResetSystem_Ntf)
	BODY(mt::TBOOL32, is_oqc)

	/*<<����ʽץ������>>
	* ui -> misc
	*/
	MESSAGE(Ev_MT_BLL_StartNetCapture_Cmd)
    BODY(mt::TU32, capture_nettype)  //ץ������ѡ�� EmNetAdapterWorkType

	/*<<ֹͣץ������>>
	* ui -> misc
	*/
	MESSAGE(Ev_MT_BLL_StopNetCapture_Cmd)

	/*<<��ȡ��ǰץ��״̬>>
	* ui-> service
	*/
	MESSAGE(Ev_MT_BLL_GetCurCapStatus_Req)

	/*<<��ȡ��ǰץ��״̬��Ӧ>>
	* ui <- service
	*/
	MESSAGE(Ev_MT_BLL_GetCurCapStatus_Rsp)
	BODY(mt::TU32, capture_state)	 // 1:����ץ��  0:û��ץ��
	BODY(mt::TMTTime, curtime)		 // ץ����ʼʱ��
	BODY(mt::TU32, lastCaptime)		 // �ϴ�ץ��ʱ�䣨��λ���룩
    BODY(mt::TU32, startcaptime)     // �ϴ�ץ��ʱ�䣨�°汾ʹ�� ��λ���룩

	/*<<ץ��״̬֪ͨ>>
	* misc -> ui
	*/
	MESSAGE(Ev_MT_BLL_NetCaptureState_Ntf)
	BODY(mt::TU32, capture_state)	 // MT_SUCCESS:����ץ��  MT_FAILED:����ץ��ʧ��
	BODY(mt::TMTTime, curtime)		 // ץ����ʼʱ��
	BODY(mt::TU32, lastCaptime)		 // �ϴ�ץ��ʱ�䣨��λ���룩

	/*<<ץ���ļ��б��ѯ>>
	* ui -> service
	*/
	MESSAGE(Ev_MT_BLL_GetNetCapFileList_Req)

	/*<<ɾ��ץ���ļ�>>
	* ui -> misc
	*/
	MESSAGE(Ev_MT_BLL_DeleteNetCapFile_Cmd)

    /*<<ɾ��ץ���ļ�>>
	* service_hd -> ui
	*/
	MESSAGE(Ev_MT_BLL_DeleteNetCapFile_Ntf)
    BODY(mt::TU32, result)

	/*<<ץ���ļ��б��ѯ��Ӧ>>
	* ui -> service
	*/
	MESSAGE(Ev_MT_BLL_GetNetCapFileList_Rsp)
	BODY(mt::TNetCapFileList, netcaplist)	//ץ���ļ��б�

	/*<<����ץ���ļ�����>>
	* ui -> misc
	*/
	MESSAGE(Ev_MT_BLL_ExportNetCapture_Req)
	BODY(mt::TString, export_file_path)	//�ļ�����·��

	/*<<����ץ���ļ�����֪ͨ>>
	* ui -> misc
	*/
	MESSAGE(Ev_MT_BLL_ExportNetCaptureProgress_Ntf)
	BODY(mt::TU32, percent)	//����ٷֱ�


	/*<<����ץ���ļ���Ӧ>>
	* misc -> ui
	*/
	MESSAGE(Ev_MT_BLL_ExportNetCapture_Rsp)
	BODY(mt::TU32, is_ok)	//MT_SUCCESS:�ɹ�
							//ERR_MTMISC_DISK_OUTOF_SPACE �ռ䲻��
							//ERR_MTMISC_FILE_NOT_EXIST  �ļ�������
	
	/*<<��ȡ��ǰץ������ʱ��>>
	* ui-> service
	*/
	MESSAGE(Ev_MT_BLL_GetPacketDurationTime_Req)

	/*<<�ظ���ǰץ������ʱ��>>
	* service-> ui
	*/
	MESSAGE(Ev_MT_BLL_GetPacketDurationTime_Rsp)
	BODY(mt::TU32, durationTime )		 // ץ������ʱ��


	/*<<������־����>>
	* ui -> misc
	*/
	MESSAGE(Ev_MT_BLL_ExportLog_Req)
	BODY(mt::TString, export_file_path)	//�ļ�����·��

	/*<<������־����֪ͨ>>
	* ui -> misc
	*/
	MESSAGE(Ev_MT_BLL_ExportLogProgress_Ntf)
	BODY(mt::TU32, percent)	//����ٷֱ�


	/*<<������־��Ӧ>>
	* misc -> ui
	*/
	MESSAGE(Ev_MT_BLL_ExportLog_Rsp)
	BODY(mt::TU32, is_ok)	
    //MT_SUCCESS:�ɹ�
	//ERR_MTMISC_DISK_OUTOF_SPACE �ռ䲻��
	//ERR_MTMISC_PATH_NOT_EXIST ����·��������
	//ERR_MTMISC_FILE_NOT_EXIST ��־�ļ�������
	//...




    /*<<����ļ�����>>
    * ��Ϣ���� : sdk -> service
    * ���� : file_path   ������ʼĿ¼
    * ���� : file_name   �����ļ���
    * ���� : is_recurse  �Ƿ����������Ŀ¼
    * see : Ev_MT_BLL_FileExistCheck_Rsp
	*/
    MESSAGE(Ev_MT_BLL_FileExistCheck_Req)
    BODY(mt::TString, file_path)
    BODY(mt::TString, file_name)
    BODY(mt::TBOOL32, is_recurse)

    /*<<����ļ���Ӧ>>
    * ��Ϣ���� : service -> sdk
    * ���� : is_exist        �����ļ��Ƿ����
    * ���� : file_full_path  �����ļ�ȫ·��(�����ļ���)
    * ���� : file_size       �����ļ���С
    * see : Ev_MT_BLL_FileExistCheck_Req
	*/
    MESSAGE(Ev_MT_BLL_FileExistCheck_Rsp)
    BODY(mt::TBOOL32, is_exist)
    BODY(mt::TString, file_full_path)
    BODY(mt::TU32, file_size)



    /*<<������ַ������>>
    * ��Ϣ���� : sdk -> service
    * ���� : dst_path    ����Ŀ��·��
    * see : Ev_MT_BLL_AddrBookExport_Rsp
	*/
    MESSAGE(Ev_MT_BLL_AddrBookExport_Req)
    BODY(mt::TString, dst_path)

    /*<<����ļ���Ӧ>>
    * ��Ϣ���� : service -> sdk
    * ���� : err_code      �Ƿ�ɹ� mt::EmFileCopyErr
    * see : Ev_MT_BLL_AddrBookExport_Req
	*/
    MESSAGE(Ev_MT_BLL_AddrBookExport_Rsp)
    BODY(mt::TS32, err_code)

    /*<<������ַ���ٷֱ�>>
    * ��Ϣ���� : service -> sdk
    * ���� : progress      �ٷֱ�
    * see : Ev_MT_BLL_AddrBookExport_Req
	*/
    MESSAGE(Ev_MT_BLL_AddrBookExportProgress_Ntf)
    BODY(mt::TU32, progress)



    /*<<�����ַ������>>
    * ��Ϣ���� : sdk -> service
    * ���� : dst_path    ����Դ·��(���ļ���)
    * see : Ev_MT_BLL_AddrBookImport_Rsp
	*/
    MESSAGE(Ev_MT_BLL_AddrBookImport_Req)
    BODY(mt::TString, src_path)


    /*<<�����ַ����Ӧ>>
    * ��Ϣ���� : service -> sdk
    * ���� : err_code      �Ƿ�ɹ� mt::EmFileCopyErr
    * see : Ev_MT_BLL_AddrBookImport_Req
	*/
    MESSAGE(Ev_MT_BLL_AddrBookImport_Rsp)
    BODY(mt::TS32, err_code)

    /*<<�����ַ���ٷֱ�>>
    * ��Ϣ���� : service -> sdk
    * ���� : progress      �ٷֱ�
    * see : Ev_MT_BLL_AddrBookExport_Req
	*/
    MESSAGE(Ev_MT_BLL_AddrBookImportProgress_Ntf)
    BODY(mt::TU32, progress)

	/*<�ն˷��������>>
    * ��Ϣ���� : sdk -> service
    * ���� : vid_idx : EmCodecComponentIndex  em1st��ʾ��һ·  em2nd��ʾ�ڶ�·
	* ���� : osd_type ��EmTerControlCameraOsdType ��osd�Ĳ�������
	*/
    MESSAGE(Ev_MT_BLL_TerminalControlCameraOsd_Cmd)
    BODY(mt::TU32, vid_idx)
	BODY(mt::TU32, osd_type)
	
    /*<<������˷������ļ�����>>
    * ��Ϣ���� : sdk -> service
    * ���� : dst_path    ����Դ·��(���ļ���)
    * see : Ev_MT_BLL_MicUpgradeFileImport_Rsp
    *       Ev_MT_BLL_MicUpgradeFileImportProgress_Ntf
	*/
    MESSAGE(Ev_MT_BLL_MicUpgradeFileImport_Req)
    BODY(mt::TString, src_path)


    /*<<������˷������ļ���Ӧ>>
    * ��Ϣ���� : service -> sdk
    * ���� : err_code      �Ƿ�ɹ� mt::EmFileCopyErr
    * see : Ev_MT_BLL_MicUpgradeFileImport_Req
	*/
    MESSAGE(Ev_MT_BLL_MicUpgradeFileImport_Rsp)
    BODY(mt::TS32, err_code)

    /*<<������˷������ļ��ٷֱ�>>
    * ��Ϣ���� : service -> sdk
    * ���� : progress      �ٷֱ�
    * see : Ev_MT_BLL_MicUpgradeFileImport_Req
	*/
    MESSAGE(Ev_MT_BLL_MicUpgradeFileImportProgress_Ntf)
    BODY(mt::TU32, progress)








    /*<<Ŀ¼�ṹ��ѯ����>>
	* ��Ϣ���� : sdk -> service
    * ��    �� : src_path   ��ѯ·��
    * see : Ev_MT_BLL_InquirePathStructure_Rsp
	*/
    MESSAGE(Ev_MT_BLL_InquirePathStructure_Req)
    BODY(mt::TString, src_path)

    /*<<Ŀ¼�ṹ��ѯ��Ӧ>>
	* ��Ϣ���� : service -> sdk
    * ���� : src_path           ��ѯ·��
    *        path_detail_list   ·������
    * see : Ev_MT_BLL_InquirePathStructure_Req
	*/
    MESSAGE(Ev_MT_BLL_InquirePathStructure_Rsp)
    BODY(mt::TString, src_path)
    BODY(mt::TMTPathStructureDetail, path_detail_list)

	/*<<EPLD/CPLD�汾��ѯ>>
	*��Ϣ���� : sdk==>dispatch==>service
	*/
	MESSAGE(Ev_MT_BLL_PldVersion_Req)

	/*<<EPLD/CPLD�汾��ѯ>>
	*ver : �汾��
	*��Ϣ���� : service==>dispatch==>sdk
	*/
	MESSAGE(Ev_MT_BLL_PldVersion_Rsp)
	BODY(mt::TU32, pld_ver)

	/*<<FPGA�汾��ѯ>>
	*��Ϣ���� : sdk==>dispatch==>service
	*/
	MESSAGE(Ev_MT_BLL_FpgaVersion_Req)

	/*<<FPGA�汾��ѯ>>
	*ver : �汾��
	*��Ϣ���� : service==>dispatch==>sdk
	*/
	MESSAGE(Ev_MT_BLL_FpgaVersion_Rsp)
	BODY(mt::TU32, fpga1_ver)
	BODY(mt::TU32, fpga2_ver)

	/*<<��ѯ�ն˳����Ƿ�ȫ�������ɹ�����>>
	* ��Ϣ���� : service -> mtmanage
    * see : Ev_MT_InquireHDMtStartSucess_Rsp
	*/
    MESSAGE(Ev_MT_BLL_InquireHDMtStartSucess_Req)

	/*<<��ѯ�ն˳����Ƿ�ȫ�������ɹ���Ӧ>>
	* ��Ϣ���� : mtmanage -> service
	* ���� : sucess       �ɹ�/ʧ��
    * see : Ev_MT_InquireHDMtStartSucess_Req
	*/
    MESSAGE(Ev_MT_BLL_InquireHDMtStartSucess_Rsp)
    BODY(mt::TBOOL32, sucess)

	/*<<�ն˳���ȫ�������ɹ�֪ͨ>>
	* ��Ϣ���� : mtmanage -> service
    * see : 
	*/
    MESSAGE(Ev_MT_BLL_HDMtStartSucess_Ntf)

	/*<<��˷�����״̬����>>
	*��Ϣ���� : sdk==>dispatch==>service
	*/
	MESSAGE(Ev_MT_BLL_MicrophoneConnectStatus_Req)

	/*<<��˷�����״̬Ӧ��>>
	*��Ϣ���� : service==>dispatch==>sdk
	*/
	MESSAGE(Ev_MT_BLL_MicrophoneConnectStatus_Rsp)
	BODY(mt::TMTMicInfo, ConnectStatus)

	/*<<��˷�����״̬�ϱ�>>
	*��Ϣ���� : service==>dispatch==>sdk
	*/
	MESSAGE(Ev_MT_BLL_MicrophoneConnectStatus_Ntf)
	BODY(mt::TMTMicInfo, ConnectStatus)

	/*<<��˷����ߵ�������>>
	*��Ϣ���� : sdk==>dispatch==>service
	*/
	MESSAGE(Ev_MT_BLL_MicrophoneBatteryLevel_Req)

	/*<<��˷����ߵ���Ӧ��>>
	*��Ϣ���� : service==>dispatch==>sdk
	*/
	MESSAGE(Ev_MT_BLL_MicrophoneBatteryLevel_Rsp)
	BODY(mt::TMTMicInfo, BatteryLevel)

	/*<<��˷����ߵ����ϱ�>>
	*��Ϣ���� : service==>dispatch==>sdk
	*/
	MESSAGE(Ev_MT_BLL_MicrophoneBatteryLevel_Ntf)
	BODY(mt::TMTMicInfo, BatteryLevel)

	/*<<������˷�������ͣ�����һ���ϱ�>>
	*��Ϣ���� : device==>dispatch==>sdk
	*/
	MESSAGE(Ev_MT_BLL_WirelessMicrophoneBatteryLow_Ntf)
	BODY(mt::TBOOL32, IsLow)

	/*<<֪ͨ/user/fileimg�еİ汾���Ѹ���>>
	*��Ϣ���� : service==>dispatch==>device
	*fileType: ��Ҫ���õİ汾�� 1: wind3d.bin.tar ; 2: skyshare_setup.tar
	*/
	MESSAGE(Ev_MT_BLL_ResetUserFileimg_Cmd)
	BODY(mt::TU32, fileType)

	/*<<��˷�����״̬����>>
	*��Ϣ���� : sdk==>dispatch==>service
	*/
	MESSAGE(Ev_MT_BLL_MicrophoneState_Req)

	/*<<��˷�����״̬Ӧ��(mt::TMicUpgradeStateList)>>
	*��Ϣ���� : service==>dispatch==>sdk
	*/
	MESSAGE(Ev_MT_BLL_MicrophoneState_Rsp)
	BODY(mt::TMicUpgradeStateList, state)

	/*<<��˷�����״̬�ϱ�(mt::TMicUpgradeStateList)>>
	*��Ϣ���� : service==>dispatch==>sdk
	*/
	MESSAGE(Ev_MT_BLL_MicrophoneState_Ntf)
	BODY(mt::TMicUpgradeStateList, state)

	/*<<��˷��ϴ�����(����)>>
	*��Ϣ���� : service==>dispatch==>sdk
	*/
	MESSAGE(Ev_MT_BLL_MicrophoneUpload_Cmd)

	/*<<��˷��ϴ������ϱ�(����)>>
	*��Ϣ���� : service==>dispatch==>sdk
	*/
	MESSAGE(Ev_MT_BLL_MicrophoneUpload_Ntf)
	BODY(mt::TU32, progress)

	/*<<��˷簲װ����(mt::TMicInstallList)>>
	*��Ϣ���� : sdk==>dispatch==>service
	*/
	MESSAGE(Ev_MT_BLL_MicrophoneInstall_Cmd)
	BODY(mt::TMicInstallList, install)

	/*<<��˷���°��ϴ�״̬����(����)>>
	*��Ϣ���� : sdk==>dispatch==>service
	*/
	MESSAGE(Ev_MT_BLL_MicrophoneVersionStatus_Req)

	/*<<��˷���°��ϴ�״̬Ӧ��(����)>>
	*��Ϣ���� : service==>dispatch==>sdk
	*/
	MESSAGE(Ev_MT_BLL_MicrophoneVersionStatus_Rsp)
	BODY(mt::TMTMicInfo, VersionStatus)

	/*<<��˷���°��ϴ�״̬�ϱ�(����)>>
	*��Ϣ���� : service==>dispatch==>sdk
	*/
	MESSAGE(Ev_MT_BLL_MicrophoneVersionStatus_Ntf)
	BODY(mt::TMTMicInfo, VersionStatus)

	/*<<��˷���������(����)>>
	*��Ϣ���� : sdk==>dispatch==>service
	*/
	MESSAGE(Ev_MT_BLL_MicrophoneUpgrade_Cmd)
	BODY(mt::TMTMicInfo, IsUpgrade)

	/*<<��˷������ϱ�(����)>>
	*��Ϣ���� : service==>dispatch==>sdk
	*/
	MESSAGE(Ev_MT_BLL_MicrophoneUpgrade_Ntf)
	BODY(mt::TMTMicInfo, UpgradeState)

	/*<<������Ƶ�ȵ�����>>
	*��Ϣ���� : sdk==>dispatch==>service
	*/
	MESSAGE(Ev_MT_BLL_OpenHotspot_Req)
	BODY(mt::TMTMicInfo, IsOpenHotspot)

	/*<<������Ƶ�ȵ�Ӧ��>>
	*��Ϣ���� : service==>dispatch==>sdk
	*/
	MESSAGE(Ev_MT_BLL_OpenHotspot_Rsp)
	BODY(mt::TMTMicInfo, HotspotState)

	/*<<��Ƶ״̬����>>
	*��Ϣ���� : sdk==>dispatch==>service
	*/
	MESSAGE(Ev_MT_BLL_Hotspot_State_Req)

	/*<<��Ƶ״̬Ӧ��>>
	*��Ϣ���� : service==>dispatch==>sdk
	*/
	MESSAGE(Ev_MT_BLL_Hotspot_State_Rsp)
	BODY(mt::TMTMicInfo, HotspotState)

	/*<<��˷�汾��Ϣ��ѯ>>
	*��Ϣ���� : sdk==>dispatch==>service
	*/
	MESSAGE(Ev_MT_BLL_MicrophoneInfo_Req)

	/*<<��˷�汾��ϢӦ��>>
	*��Ϣ���� : service==>dispatch==>sdk
	*/
	MESSAGE(Ev_MT_BLL_MicrophoneInfo_Rsp)
	BODY(mt::TMicVersionList, VerInfo)

	/*<<��˷�汾��Ϣ�ϱ�>>
	*��Ϣ���� : service==>dispatch==>sdk
	*/
	MESSAGE(Ev_MT_BLL_MicrophoneInfo_Ntf)
	BODY(mt::TMicVersionList, VerInfo)

	/*<<�ն˱������˷�汾��Ϣ��ѯ>>
	*��Ϣ���� : service==>dispatch==>deivce
	*/
    MESSAGE(Ev_MT_BLL_TermKeepMicrophoneInfo_Req)
	BODY( NULL , NULL )

	/*<<�ն˱������˷�汾��Ϣ��ѯ>>
	*��Ϣ���� : service==>dispatch==>deivce
	*/
    MESSAGE(Ev_MT_BLL_TermKeepMicrophoneInfo_Rsp)
	BODY( mt::TString , tstrTermKeepMicVer )

    /*<<��ѯ�豸����E1ģ����������>>
	*BODY ��    
	*���䷽��sdk->dispatch->mtservice
	* see Ev_MT_BLL_GetE1ModuleNum_Rsp
	*/
	MESSAGE(Ev_MT_BLL_GetE1ModuleNum_Req)

    /*<<x500�豸����ѯ�豸����E1ģ������>>
	*E1Num : 0-��������4-������
	*��Ϣ���� : mtservice==>dispatch==>sdk
	*/
	MESSAGE(Ev_MT_BLL_GetE1ModuleNum_Rsp)
	BODY(mt::TU32, E1Num)

    /*<<������˳���������>>
	* mtservice==>dispatch==>sdk
	*/
    MESSAGE(Ev_MT_BLL_MfgTestRegisterInOrOut_Ntf)
	BODY(mt::TBOOL32, register_state)	//�Ƿ��¼

	/*<<Isp��������>>
	*EmNFMode     :
	��Ϣ���� : sdk==>dispatch==>mtservice
	*/
	MESSAGE(Ev_MT_BLL_IspImgInf_Noise_Req)

	/*<<Isp����Ӧ��>>
	*EmNFMode     :
	��Ϣ���� : sdk<==dispatch<==mtservice
	*/
	MESSAGE(Ev_MT_BLL_IspImgInf_Noise_Rsp)
	BODY(mt::TU32, EmNFMode)

	/*<<Isp��������>>
	*EmNFMode     :
	��Ϣ���� : sdk==>dispatch==>mtservice
	*/
	MESSAGE(Ev_MT_BLL_IspImgInf_Noise_Cmd)
	BODY(mt::TU32, EmNFMode)

	/*<<Isp�����ϱ�>>
	*EmNFMode     :
	��Ϣ���� : sdk<==dispatch<==mtservice
	*/
	MESSAGE(Ev_MT_BLL_IspImgInf_Noise_Ntf)
	BODY(mt::TU32, EmNFMode)

	
	/*<<Ispxd��������>>
	*EmNFType     :�������ͣ�0:2D; 1:3D
	��Ϣ���� : sdk==>dispatch==>mtservice
	*/
	MESSAGE(Ev_MT_BLL_IspImgInf_xdNoise_Req)
	BODY(mt::TU32, EmNFType)

	/*<<Ispxd����Ӧ��>>
	*EmNFType     :
	*value��0-10������ȼ�
	��Ϣ���� : sdk<==dispatch<==mtservice
	*/
	MESSAGE(Ev_MT_BLL_IspImgInf_xdNoise_Rsp)
	BODY(mt::TU32, EmNFType)
	BODY(mt::TU32, value)

	/*<<Ispxd��������>>
	*EmNFType     :
	*value��0-10������ȼ�
	*vid_idx : EmCodecComponentIndex  em1st��ʾ��һ·  em2nd��ʾ�ڶ�·
	��Ϣ���� : sdk==>dispatch==>mtservice
	*/
	MESSAGE(Ev_MT_BLL_IspImgInf_xdNoise_Cmd)
	BODY(mt::TU32, EmNFType)
	BODY(mt::TU32, value)
	BODY(mt::TU32, vid_idx)

	/*<<Ispxd�����ϱ�>>
	*EmNFType     :
	*value��0-10������ȼ�
	*vid_idx : EmCodecComponentIndex  em1st��ʾ��һ·  em2nd��ʾ�ڶ�·
    *reslt : 0�ɹ�������ʧ��
	��Ϣ���� : sdk<==dispatch<==mtservice
	*/
	MESSAGE(Ev_MT_BLL_IspImgInf_xdNoise_Ntf)
	BODY(mt::TU32, EmNFType)
	BODY(mt::TU32, value)
	BODY(mt::TU32, vid_idx)
    BODY(mt::TU32, result)

	/*<<Isp�������>>
	*EmGeneralLevel     :
	��Ϣ���� : sdk==>dispatch==>mtservice
	*/
	MESSAGE(Ev_MT_BLL_IspImgInf_Sharpness_Req)

	/*<<Isp���Ӧ��>>
	*EmGeneralLevel     :
	��Ϣ���� : sdk<==dispatch<==mtservice
	*/
	MESSAGE(Ev_MT_BLL_IspImgInf_Sharpness_Rsp)
	BODY(mt::TU32, EmGeneralLevel)

	/*<<Isp�������>>
	*EmGeneralLevel     :
	��Ϣ���� : sdk==>dispatch==>mtservice
	*/
	MESSAGE(Ev_MT_BLL_IspImgInf_Sharpness_Cmd)
	BODY(mt::TU32, EmGeneralLevel)

	/*<<Isp����ϱ�>>
	*EmGeneralLevel     :
	��Ϣ���� : sdk<==dispatch<==mtservice
	*/
	MESSAGE(Ev_MT_BLL_IspImgInf_Sharpness_Ntf)
	BODY(mt::TU32, EmGeneralLevel)

	/*<<Isp�������v2>>
	��Ϣ���� : sdk==>dispatch==>mtservice
	*/
	MESSAGE(Ev_MT_BLL_IspImgInf_SharpnessV2_Req)

	/*<<Isp���Ӧ��v2>>
	*value��0-10     :�ȼ�
	��Ϣ���� : sdk<==dispatch<==mtservice
	*/
	MESSAGE(Ev_MT_BLL_IspImgInf_SharpnessV2_Rsp)
	BODY(mt::TU32, value)

	/*<<Isp�������v2>>
	*value��0-10     :
	*vid_idx : EmCodecComponentIndex  em1st��ʾ��һ·  em2nd��ʾ�ڶ�·
	��Ϣ���� : sdk==>dispatch==>mtservice
	*/
	MESSAGE(Ev_MT_BLL_IspImgInf_SharpnessV2_Cmd)
	BODY(mt::TU32, value)
	BODY(mt::TU32, vid_idx)

	/*<<Isp����ϱ�v2>>
	*value��0-10     :
	*vid_idx : EmCodecComponentIndex  em1st��ʾ��һ·  em2nd��ʾ�ڶ�·
    *result : 0�ɹ�������ʧ��
	��Ϣ���� : sdk<==dispatch<==mtservice
	*/
	MESSAGE(Ev_MT_BLL_IspImgInf_SharpnessV2_Ntf)
	BODY(mt::TU32, value)
	BODY(mt::TU32, vid_idx)
    BODY(mt::TU32, result)

	/*<<isp�ع���������>>
	*EmExposureModeGainType     :0:auto;1:manual
	��Ϣ���� : sdk==>dispatch==>mtservice
	*/
	MESSAGE(Ev_MT_BLL_IspImgInf_ExposureGain_Req)
	BODY(mt::TU32, EmExposureModeGainType)

	/*<<Isp�ع�����Ӧ��>>
	*EmExposureModeGainType     :0:auto;1:manual
	*EmExposureModeGainRestrict��0-10
	��Ϣ���� : sdk<==dispatch<==mtservice
	*/
	MESSAGE(Ev_MT_BLL_IspImgInf_ExposureGain_Rsp)
	BODY(mt::TU32, EmExposureModeGainType)
	BODY(mt::TU32, EmExposureModeGainRestrict)

	/*<<Isp�ع���������>>
	*EmExposureModeGainType     :0:auto;1:manual
	*EmExposureModeGainRestrict��0-10
	*vid_idx : EmCodecComponentIndex  em1st��ʾ��һ·  em2nd��ʾ�ڶ�·
	��Ϣ���� : sdk==>dispatch==>mtservice
	*/
	MESSAGE(Ev_MT_BLL_IspImgInf_ExposureGain_Cmd)
	BODY(mt::TU32, EmExposureModeGainType)
	BODY(mt::TU32, EmExposureModeGainRestrict)
	BODY(mt::TU32, vid_idx)

	/*<<Isp�ع������ϱ�>>
	*EmExposureModeGainType     :0:auto;1:manual
	*EmExposureModeGainRestrict��0-10
	*vid_idx : EmCodecComponentIndex  em1st��ʾ��һ·  em2nd��ʾ�ڶ�·
    *result : 0�ɹ�������ʧ��
	��Ϣ���� : sdk<==dispatch<==mtservice
	*/
	MESSAGE(Ev_MT_BLL_IspImgInf_ExposureGain_Ntf)
	BODY(mt::TU32, EmExposureModeGainType)
	BODY(mt::TU32, EmExposureModeGainRestrict)
	BODY(mt::TU32, vid_idx)
    BODY(mt::TU32, result)

	/*<<isp��ƽ���ֶ�ģʽ��������>>
	*EMWBAModeGainType     :0:��;1:��
	��Ϣ���� : sdk==>dispatch==>mtservice
	*/
	MESSAGE(Ev_MT_BLL_IspImgInf_WhiteBalanceGain_Req)
	BODY(mt::TU32, EMWBAModeGainType)

	/*<<Isp��ƽ���ֶ�ģʽ����Ӧ��>>
	*EmExposureModeGainType     :0:��;1:��
	*��value��0-255
	��Ϣ���� : sdk<==dispatch<==mtservice
	*/
	MESSAGE(Ev_MT_BLL_IspImgInf_WhiteBalanceGain_Rsp)
	BODY(mt::TU32, EMWBAModeGainType)
	BODY(mt::TU32, value)

	/*<<Isp��ƽ���ֶ�ģʽ��������>>
	*EmExposureModeGainType     :0:��;1:��
	*value��0-255
	*vid_idx : EmCodecComponentIndex  em1st��ʾ��һ·  em2nd��ʾ�ڶ�·
	��Ϣ���� : sdk==>dispatch==>mtservice
	*/
	MESSAGE(Ev_MT_BLL_IspImgInf_WhiteBalanceGain_Cmd)
	BODY(mt::TU32, EMWBAModeGainType)
	BODY(mt::TU32, value)
	BODY(mt::TU32, vid_idx)

	/*<<Isp��ƽ���ֶ�ģʽ�����ϱ�>>
	*EmExposureModeGainType     :0:��;1:��
	*value��0-255
	*vid_idx : EmCodecComponentIndex  em1st��ʾ��һ·  em2nd��ʾ�ڶ�·
    *result : 0�ɹ�������ʧ��
	��Ϣ���� : sdk<==dispatch<==mtservice
	*/
	MESSAGE(Ev_MT_BLL_IspImgInf_WhiteBalanceGain_Ntf)
	BODY(mt::TU32, EMWBAModeGainType)
	BODY(mt::TU32, value)
	BODY(mt::TU32, vid_idx)
    BODY(mt::TU32, result)

	//
	/*<<isp٤������>>
	��Ϣ���� : sdk==>dispatch==>mtservice
	*/
	MESSAGE(Ev_MT_BLL_IspImgInf_Gamma_Req)

	/*<<Isp٤��Ӧ��>>
	*��value��0-4
	��Ϣ���� : sdk<==dispatch<==mtservice
	*/
	MESSAGE(Ev_MT_BLL_IspImgInf_Gamma_Rsp)
	BODY(mt::TU32, value)

	/*<<Isp٤������>>
	*value��0-4
	��Ϣ���� : sdk==>dispatch==>mtservice
	*/
	MESSAGE(Ev_MT_BLL_IspImgInf_Gamma_Cmd)
	BODY(mt::TU32, value)
	BODY(mt::TU32, vid_idx)

	/*<<Isp٤���ϱ�>>
	*value��0-10
	��Ϣ���� : sdk<==dispatch<==mtservice
	*/
	MESSAGE(Ev_MT_BLL_IspImgInf_Gamma_Ntf)
	BODY(mt::TU32, value)
	BODY(mt::TU32, vid_idx)
    BODY(mt::TU32, result)

	/*<<isp����ȥ������>>
	��Ϣ���� : sdk==>dispatch==>mtservice
	*/
	MESSAGE(Ev_MT_BLL_IspImgInf_Defog_Req)

	/*<<Isp����ȥ��Ӧ��>>
	*��value��0-10
	��Ϣ���� : sdk<==dispatch<==mtservice
	*/
	MESSAGE(Ev_MT_BLL_IspImgInf_Defog_Rsp)
	BODY(mt::TU32, value)

	/*<<Isp����ȥ������>>
	*value��0-10
	��Ϣ���� : sdk==>dispatch==>mtservice
	*/
	MESSAGE(Ev_MT_BLL_IspImgInf_Defog_Cmd)
	BODY(mt::TU32, value)

	/*<<Isp����ȥ���ϱ�>>
	*value��0-10
	��Ϣ���� : sdk<==dispatch<==mtservice
	*/
	MESSAGE(Ev_MT_BLL_IspImgInf_Defog_Ntf)
	BODY(mt::TU32, value)

	/*<<isp���ֿ�̬��������>>
	��Ϣ���� : sdk==>dispatch==>mtservice
	*/
	MESSAGE(Ev_MT_BLL_IspImgInf_DigDynSwitch_Req)

	/*<<Isp���ֿ�̬����Ӧ��>>
	*��value��0����;1:��
	��Ϣ���� : sdk<==dispatch<==mtservice
	*/
	MESSAGE(Ev_MT_BLL_IspImgInf_DigDynSwitch_Rsp)
	BODY(mt::TBOOL32, value)

	/*<<Isp���ֿ�̬��������>>
	*value��0����;1:��
	��Ϣ���� : sdk==>dispatch==>mtservice
	*/
	MESSAGE(Ev_MT_BLL_IspImgInf_DigDynSwitch_Cmd)
	BODY(mt::TBOOL32, value)

	/*<<Isp���ֿ�̬�����ϱ�>>
	*value��0����;1:��
	��Ϣ���� : sdk<==dispatch<==mtservice
	*/
	MESSAGE(Ev_MT_BLL_IspImgInf_DigDynSwitch_Ntf)
	BODY(mt::TBOOL32, value)

	/*<<isp���ֿ�̬�ȼ�����>>
	��Ϣ���� : sdk==>dispatch==>mtservice
	*/
	MESSAGE(Ev_MT_BLL_IspImgInf_DigDynLevel_Req)

	/*<<Isp���ֿ�̬�ȼ�Ӧ��>>
	*��value��0��0-100
	��Ϣ���� : sdk<==dispatch<==mtservice
	*/
	MESSAGE(Ev_MT_BLL_IspImgInf_DigDynLevel_Rsp)
	BODY(mt::TU32, value)

	/*<<Isp���ֿ�̬�ȼ�����>>
	*value��0��0-100
	��Ϣ���� : sdk==>dispatch==>mtservice
	*/
	MESSAGE(Ev_MT_BLL_IspImgInf_DigDynLevel_Cmd)
	BODY(mt::TU32, value)

	/*<<Isp���ֿ�̬�ȼ��ϱ�>>
	*value��0��0-100
	��Ϣ���� : sdk<==dispatch<==mtservice
	*/
	MESSAGE(Ev_MT_BLL_IspImgInf_DigDynLevel_Ntf)
	BODY(mt::TU32, value)
	//

	/*<<isp���ⲹ����������>>
	��Ϣ���� : sdk==>dispatch==>mtservice
	*/
	MESSAGE(Ev_MT_BLL_IspImgInf_BackLightSwitch_Req)

	/*<<Isp���ⲹ������Ӧ��>>
	*��value��0����;1:��
	��Ϣ���� : sdk<==dispatch<==mtservice
	*/
	MESSAGE(Ev_MT_BLL_IspImgInf_BackLightSwitch_Rsp)
	BODY(mt::TBOOL32, value)

	/*<<Isp���ⲹ����������>>
	*value��0����;1:��
	��Ϣ���� : sdk==>dispatch==>mtservice
	*/
	MESSAGE(Ev_MT_BLL_IspImgInf_BackLightSwitch_Cmd)
	BODY(mt::TBOOL32, value)

	/*<<Isp���ⲹ�������ϱ�>>
	*value��0����;1:��
	��Ϣ���� : sdk<==dispatch<==mtservice
	*/
	MESSAGE(Ev_MT_BLL_IspImgInf_BackLightSwitch_Ntf)
	BODY(mt::TBOOL32, value)

	/*<<isp���ⲹ���ȼ�����>>
	��Ϣ���� : sdk==>dispatch==>mtservice
	*/
	MESSAGE(Ev_MT_BLL_IspImgInf_BackLightLevel_Req)

	/*<<Isp���ⲹ���ȼ�Ӧ��>>
	*��value��0��0-15
	��Ϣ���� : sdk<==dispatch<==mtservice
	*/
	MESSAGE(Ev_MT_BLL_IspImgInf_BackLightLevel_Rsp)
	BODY(mt::TU32, value)

	/*<<Isp���ⲹ���ȼ�����>>
	*value��0��0-15
	��Ϣ���� : sdk==>dispatch==>mtservice
	*/
	MESSAGE(Ev_MT_BLL_IspImgInf_BackLightLevel_Cmd)
	BODY(mt::TU32, value)

	/*<<Isp���ⲹ���ȼ��ϱ�>>
	*value��0��0-15
	��Ϣ���� : sdk<==dispatch<==mtservice
	*/
	MESSAGE(Ev_MT_BLL_IspImgInf_BackLightLevel_Ntf)
	BODY(mt::TU32, value)

	/*<<Isp�й������>>
	*EmISO      :
	��Ϣ���� : sdk==>dispatch==>mtservice
	*/
	MESSAGE(Ev_MT_BLL_IspImgInf_ISO_Req)

	/*<<Isp�й��Ӧ��>>
	*EmISO      :
	��Ϣ���� : sdk<==dispatch<==mtservice
	*/
	MESSAGE(Ev_MT_BLL_IspImgInf_ISO_Rsp)
	BODY(mt::TU32, EmISO)

	/*<<Isp�й������>>
	*EmISO      :
	��Ϣ���� : sdk==>dispatch==>mtservice
	*/
	MESSAGE(Ev_MT_BLL_IspImgInf_ISO_Cmd)
	BODY(mt::TU32, EmISO)

	/*<<Isp�й���ϱ�>>
	*EmISO      :
	��Ϣ���� : sdk<==dispatch<==mtservice
	*/
	MESSAGE(Ev_MT_BLL_IspImgInf_ISO_Ntf)
	BODY(mt::TU32, EmISO)

	/*<<Isp�ع�ģʽ����>>
	*EmExposureMode      :
	��Ϣ���� : sdk==>dispatch==>mtservice
	*/
	MESSAGE(Ev_MT_BLL_IspImgInf_ExposureMode_Req)

	/*<<Isp�ع�ģʽӦ��>>
	*EmExposureMode      :
	��Ϣ���� : sdk<==dispatch<==mtservice
	*/
	MESSAGE(Ev_MT_BLL_IspImgInf_ExposureMode_Rsp)
	BODY(mt::TU32, EmExposureMode)

	/*<<Isp�ع�ģʽ����>>
	*EmExposureMode      :
    *vid_idx : EmCodecComponentIndex  em1st��ʾ��һ·  em2nd��ʾ�ڶ�·
	��Ϣ���� : sdk==>dispatch==>mtservice
	*/
	MESSAGE(Ev_MT_BLL_IspImgInf_ExposureMode_Cmd)
	BODY(mt::TU32, EmExposureMode)
    BODY(mt::TU32, vid_idx)

	/*<<Isp�ع�ģʽ�ϱ�>>
	*EmExposureMode      :
    *vid_idx : EmCodecComponentIndex  em1st��ʾ��һ·  em2nd��ʾ�ڶ�·
    *result
	��Ϣ���� : sdk<==dispatch<==mtservice
	*/
	MESSAGE(Ev_MT_BLL_IspImgInf_ExposureMode_Ntf)
	BODY(mt::TU32, EmExposureMode)
    BODY(mt::TU32, vid_idx)
    BODY(mt::TU32, result)

    /*<<ͼ��ģʽ����>>
    *vid_idx : EmCodecComponentIndex  em1st��ʾ��һ·  em2nd��ʾ�ڶ�·
	*EmImgMode      :
	��Ϣ���� : sdk==>dispatch==>mtservice
	*/
	MESSAGE(Ev_MT_BLL_HD_SetCameraImgMode_Cmd)
	BODY(mt::TU32, EmImgMode)
    BODY(mt::TU32, vid_idx)

	/*<<ͼ��ģʽ�ϱ�>>
	*EmImgMode      :
    *vid_idx : EmCodecComponentIndex  em1st��ʾ��һ·  em2nd��ʾ�ڶ�·
    *result
	��Ϣ���� : sdk<==dispatch<==mtservice
	*/
	MESSAGE(Ev_MT_BLL_HD_SetCameraImgMode_Ntf)
	BODY(mt::TU32, EmImgMode)
    BODY(mt::TU32, vid_idx)
    BODY(mt::TU32, result)

    /*<<������������>>
	*EmPerson      :
    *vid_idx : EmCodecComponentIndex  em1st��ʾ��һ·  em2nd��ʾ�ڶ�·
	��Ϣ���� : sdk==>dispatch==>mtservice
	*/
	MESSAGE(Ev_MT_BLL_HD_SetCameraPersonFirst_Cmd)
	BODY(mt::TU32, EmPerson)
    BODY(mt::TU32, vid_idx)

	/*<<���������ϱ�>>
	*EmPerson      :
    *vid_idx : EmCodecComponentIndex  em1st��ʾ��һ·  em2nd��ʾ�ڶ�·
    *result
	��Ϣ���� : sdk<==dispatch<==mtservice
	*/
	MESSAGE(Ev_MT_BLL_HD_SetCameraPersonFirst_Ntf)
	BODY(mt::TU32, EmPerson)
    BODY(mt::TU32, vid_idx)
    BODY(mt::TU32, result)

    /*<<���������ֱ������>>
	*value      : 0-100
    *vid_idx : EmCodecComponentIndex  em1st��ʾ��һ·  em2nd��ʾ�ڶ�·
	��Ϣ���� : sdk==>dispatch==>mtservice
	*/
	MESSAGE(Ev_MT_BLL_HD_DeviceCameraBrightDirectSet_Cmd)
	BODY(mt::TU32, value)
    BODY(mt::TU32, vid_idx)

	/*<<���������ֱ�������ϱ�>>
	*value      : 0-100
    *vid_idx : EmCodecComponentIndex  em1st��ʾ��һ·  em2nd��ʾ�ڶ�·
	��Ϣ���� : sdk<==dispatch<==mtservice
	*/
	MESSAGE(Ev_MT_BLL_HD_DeviceCameraBrightDirectSet_Ntf)
	BODY(mt::TU32, value)
    BODY(mt::TU32, vid_idx)

	/*<<Isp��Ȧ��С����>>
	*EmAperture      :
	��Ϣ���� : sdk==>dispatch==>mtservice
	*/
	MESSAGE(Ev_MT_BLL_IspImgInf_Aperture_Req)

	/*<<Isp��Ȧ��СӦ��>>
	*EmAperture      :
	��Ϣ���� : sdk<==dispatch<==mtservice
	*/
	MESSAGE(Ev_MT_BLL_IspImgInf_Aperture_Rsp)
	BODY(mt::TU32, EmAperture)

	/*<<Isp��Ȧ��С����>>
	*EmAperture      :
	*vid_idx : EmCodecComponentIndex  em1st��ʾ��һ·  em2nd��ʾ�ڶ�·
	��Ϣ���� : sdk==>dispatch==>mtservice
	*/
	MESSAGE(Ev_MT_BLL_IspImgInf_Aperture_Cmd)
	BODY(mt::TU32, EmAperture)
	BODY(mt::TU32, vid_idx)

	/*<<Isp��Ȧ��С�ϱ�>>
	*EmAperture      :
	*vid_idx : EmCodecComponentIndex  em1st��ʾ��һ·  em2nd��ʾ�ڶ�·
    *result : 0�ɹ�������ʧ��
	��Ϣ���� : sdk<==dispatch<==mtservice
	*/
	MESSAGE(Ev_MT_BLL_IspImgInf_Aperture_Ntf)
	BODY(mt::TU32, EmAperture)
	BODY(mt::TU32, vid_idx)
    BODY(mt::TU32, result)

	/*<<Isp�����ٶ�����>>
	*EmAperture      :
	��Ϣ���� : sdk==>dispatch==>mtservice
	*/
	MESSAGE(Ev_MT_BLL_IspImgInf_Shutter_Req)

	/*<<Isp�����ٶ�Ӧ��>>
	*EmAperture      :
	��Ϣ���� : sdk<==dispatch<==mtservice
	*/
	MESSAGE(Ev_MT_BLL_IspImgInf_Shutter_Rsp)
	BODY(mt::TU32, EmShutterLevel)

	/*<<Isp�����ٶ�����>>
	*EmAperture      :
	*vid_idx : EmCodecComponentIndex  em1st��ʾ��һ·  em2nd��ʾ�ڶ�·
	��Ϣ���� : sdk==>dispatch==>mtservice
	*/
	MESSAGE(Ev_MT_BLL_IspImgInf_Shutter_Cmd)
	BODY(mt::TU32, EmShutterLevel)
	BODY(mt::TU32, vid_idx)

	/*<<Isp�����ٶ��ϱ�>>
	*EmAperture      :
	*vid_idx : EmCodecComponentIndex  em1st��ʾ��һ·  em2nd��ʾ�ڶ�·
    *result : 0�ɹ�������ʧ��
	��Ϣ���� : sdk<==dispatch<==mtservice
	*/
	MESSAGE(Ev_MT_BLL_IspImgInf_Shutter_Ntf)
	BODY(mt::TU32, EmShutterLevel)
	BODY(mt::TU32, vid_idx)
    BODY(mt::TU32, result)

	/*<<����Isp����>>
	*�ع�Ϊ�Զ�ģʽ���ȵ��ڲ���Ч���ع�Ϊ�ֶ�ģʽ�����ȵ�����Ч
	*EmBrightnessDirection:
	��Ϣ���� : sdk==>dispatch==>mtservice
	*/
	MESSAGE(Ev_MT_BLL_IspImgInf_Brightnesss_Cmd)
	BODY(mt::TU32, EmBrightnessDirection)

	/*<<Isp��ƽ������>>
	*EmWBAMode      :
	��Ϣ���� : sdk==>dispatch==>mtservice
	*/
	MESSAGE(Ev_MT_BLL_IspImgInf_WhiteBalance_Req)
	BODY(mt::TU32, EmWBAMode)

	/*<<Isp��ƽ��Ӧ��>>
	*EmWBAMode      :
	��Ϣ���� : sdk<==dispatch<==mtservice
	*/
	MESSAGE(Ev_MT_BLL_IspImgInf_WhiteBalance_Rsp)
	BODY(mt::TU32, EmWBAMode)

	/*<<Isp��ƽ������>>
	*EmWBAMode      :
	*vid_idx : EmCodecComponentIndex  em1st��ʾ��һ·  em2nd��ʾ�ڶ�·
	��Ϣ���� : sdk==>dispatch==>mtservice
	*/
	MESSAGE(Ev_MT_BLL_IspImgInf_WhiteBalance_Cmd)
	BODY(mt::TU32, EmWBAMode)
	BODY(mt::TU32, vid_idx)

	/*<<Isp��ƽ���ϱ�>>
	*EmWBAMode      :
	*vid_idx : EmCodecComponentIndex  em1st��ʾ��һ·  em2nd��ʾ�ڶ�·
    *result : 0�ɹ�������ʧ��
	��Ϣ���� : sdk<==dispatch<==mtservice
	*/
	MESSAGE(Ev_MT_BLL_IspImgInf_WhiteBalance_Ntf)
	BODY(mt::TU32, EmWBAMode)
	BODY(mt::TU32, vid_idx)
    BODY(mt::TU32, result)

        /*<<ѡ�񴮿ڹ�����ʹ��>>
	* sdk -> service_hd
	*/
	MESSAGE(Ev_MT_BLL_ChooseSerialUse_Cmd)
	BODY(mt::TMTHDSerialCtrl, serial_use)	//��������
    BODY(mt::TBOOL32, serial_use)	//�Ƿ�ʹ��

	/*<<ѡ�񴮿ڹ�����ʹ����Ӧ>>
	* service_hd -> sdk
	*/
	MESSAGE(Ev_MT_BLL_ChooseSerialUse_Ntf)
    BODY(mt::TMTHDSerialCtrl, serial_use)	//��������
    BODY(mt::TBOOL32, serial_use)	//�Ƿ�ʹ��
    BODY(mt::TS32, result)    //������

    /*<<ѡ�񴮿ڹ�����ʹ��>>
	* sdk -> service_hd
	*/
	MESSAGE(Ev_MT_BLL_OperaterSerial_Cmd)
    BODY(mt::TSerialOptParam, serial_info)	//��д��Ϣ

	/*<<ѡ�񴮿ڹ�����ʹ����Ӧ>>
	* service_hd -> sdk
	*/
	MESSAGE(Ev_MT_BLL_OperaterSerial_Ntf)
    BODY(mt::TSerialOptParam, serial_info)	//��д��Ϣ
    BODY(mt::TS32, result)    //������

	/*<<����detectserver������>>
	��Ϣ���� : sdk==>dispatch==>mtservice_hd
	*/
	MESSAGE(Ev_MT_BLL_UpdateDetectserverCfg_Cmd)
	
	/*<<����������쳣��Ӧ>>
	* service_hd -> sdk
	*/
	MESSAGE(Ev_MT_BLL_DeviceCameraOptError_Ntf)
    BODY(mt::TU32, vid_idx)   //�����No
    BODY(mt::TU32, result)    //֪ͨ����
	
	/*<<���������ģʽ������ȡ>>
	* service_hd -> device
	*/
	MESSAGE(Ev_MT_BLL_DeviceCameraSceneMode_Req)
    BODY(mt::TU32, vid_idx)   //�����No
	
	/*<<���������ģʽ������ȡ��Ӧ>>
	* device -> service_hd
	*/
	MESSAGE(Ev_MT_BLL_DeviceCameraSceneMode_Rsp)
    BODY(mt::TU32, vid_idx)   //�����No
	BODY(mt::TCameraSceneModeCapList, scenecap)   //����ģʽ����
	
	/*<<���������ģʽ��������>>
	* service_hd -> device
	*/
	MESSAGE(Ev_MT_BLL_DeviceCameraSceneMode_Cmd)
    BODY(mt::TU32, vid_idx)   //�����No
	BODY(mt::TU32, EmCameraSceneMode)   //����ģʽ
	
	/*<<���������ģʽ����������Ӧ>>
	* device -> service_hd
	*/
	MESSAGE(Ev_MT_BLL_DeviceCameraSceneMode_Ntf)
    BODY(mt::TU32, vid_idx)   //�����No
	BODY(mt::TU32, EmCameraSceneMode)   //����ģʽ
	BODY(mt::TU32, result)   //���
	
	/*<<������������>>
	*��Ϣ���� : sdk==>dispatch==>service
	*/
    MESSAGE(Ev_MT_BLL_DeviceNetCardStatis_Req)

    /*<<����������Ӧ>>
    *NetCardStatisList : mt::TNetCardStatisList  ����������Ϣ
	*��Ϣ���� : service==>dispatch==>sdk
	*/
    MESSAGE(Ev_MT_BLL_DeviceNetCardStatis_Rsp)
    BODY(mt::TNetCardStatisList, NetCardStatisList)
	
	/*<<���������Ϣ�ļ�����>>
	* sdk -> service
	*/
	MESSAGE(Ev_MT_BLL_ExportDiagInfo_Cmd)
	BODY(mt::TString, export_file_path)	//�ļ�����·��

	/*<<���������Ϣ�ļ�����֪ͨ>>
	* service -> sdk
	*/
	MESSAGE(Ev_MT_BLL_ExportDiagInfoProgress_Ntf)
	BODY(mt::TU32, percent)	//����ٷֱ�


	/*<<���������Ϣ�ļ���Ӧ>>
	* service -> sdk
	*/
	MESSAGE(Ev_MT_BLL_ExportDiagInfo_Ntf)
	BODY(mt::TU32, is_ok)	//MT_SUCCESS:�ɹ�
							//ERR_MTMISC_DISK_OUTOF_SPACE �ռ䲻��
							//ERR_MTMISC_FILE_NOT_EXIST  �ļ�������
	BODY(mt::TString, export_file_path)	//�ļ�����·��

	/*<<��������Ʒ�ʽ֪ͨ>>
	* service_hd -> sdk
	*/
	MESSAGE(Ev_MT_BLL_DeviceCameraCtrlType_Ntf)
    BODY(mt::TU32, EmCameraCtrlType)    //֪ͨ����

    /*<<����>>
	* service_hd <- sdk
	*/
    MESSAGE(Ev_MT_BLL_ElectricFan_Cmd)
    BODY(mt::TBOOL32, tBOOL32)

    /*<<����>>
	* service_hd -> sdk
	*/
    MESSAGE(Ev_MT_BLL_ElectricFan_Ntf)
    BODY(mt::TBOOL32, tBOOL32)

    /*<<����ʱ��>>
	* service_hd <- sdk
	*/
    MESSAGE(Ev_MT_BLL_GetElectricFanTime_Req)

    /*<<����ʱ��>>
	* service_hd -> sdk
	*/
    MESSAGE(Ev_MT_BLL_GetElectricFanTime_Rsp)
    BODY(mt::TU32, value)
	
	/*<<�����������������>>
	* service_hd <- sdk
	*/
	MESSAGE(Ev_MT_BLL_SetAiCamera_Cmd)
	BODY(mt::TMTHDCameraAiList, value)
	
	/*<<�����������������>>
	* service_hd -> sdk
	*/
	MESSAGE(Ev_MT_BLL_SetAiCamera_Ntf)
	
	/*<<����ͳ��>>
	* service_hd -> sdk
	*/
	MESSAGE(Ev_MT_BLL_PeopleCountingResult_Ntf)
	BODY(mt::TU32, tCamIdx)
	BODY(mt::TU32, value)
	
	/*<<����ǩ��>>
	* service_hd -> sdk
	*/
	MESSAGE(Ev_MT_BLL_FaceCheckInInfo_Ntf)
	BODY(mt::TU32, tCamIdx)
	BODY(mt::TMTFaceCheckInList, value)

	 /*<<�����������洢�ռ������>>
	* device <- sdk
	*/
    MESSAGE(Ev_MT_BLL_UploadZip_Cmd)

    /*<<�����������洢�ռ��֪ͨ>>
	* device -> sdk
	*/
    MESSAGE(Ev_MT_BLL_UploadZip_Ntf)

#if !defined(_MESSAGE_HELP_)
    EV_BLL_END(DEVICE) = EVSEG_BLL_DEVICE_END
};
#endif

#define Is_BLL_Device_Msg(m) ((m) >= EV_BLL_BGN(DEVICE) && (m) <= EV_BLL_END(DEVICE))

#endif
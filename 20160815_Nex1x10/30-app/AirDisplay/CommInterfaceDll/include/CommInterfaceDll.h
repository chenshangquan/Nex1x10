/**  
 *@ dll˵����usb hid �豸ͨѶ
 *@ ����: dyy
 *@ ʱ��: 2017-2-21
 */
#ifndef COMMINTERFACE_H
#define COMMINTERFACE_H

//ע�����Ǹ���̬��
#define HID_API extern "C" __declspec(dllexport)

#include "osp.h"
#include <Windows.h>
#include <SetupAPI.h>
#include <BaseTyps.h>
#include "usbdi.h"
#include <initguid.h>
#include <stdio.h>
#include <devguid.h>
#include "dbt.h"
#include "quickshare.h"
#include "print.h"

extern "C"
{
#include "hidsdi.h"
}

#define USB_VID               0x2dcc   // todo �����豸ʵ��ֵ��
#define USB_PID               0x8130   // todo �����豸ʵ��ֵ��


#define LENTH_OUT_BUFFER      2048     //����Ƶ���buf��С�������������buf��С��
#define LENTH_IN_BUFFER       64       //���ڽ��յ�buf

#define LENTH_OUT_BUFFER_CMD  (66-1)   //����д��ʹ�õ�buf
#define LENTH_IN_BUFFER_CMD   6        //�������ʹ�õ�buf

#define PACKET_SIZE           512      //һ����С
#define MAX_BUFFER_NUM        4096     //��󻺳������Լ2M����
#define MAX_STORE_NUM         5000     //���ѻ�������Լ2M����

typedef enum emHID_TYPE
{
	HID_TYPE_VIDEO = 0,               //��Ƶ����ʹ��
    HID_TYPE_AUDIO,                   //��Ƶ����ʹ��
	HID_TYPE_CMD,                     //����
	//HID_TYPE_RC,                      //����

	HID_TYPE_NUM
}HID_TYPE;

#define HID_COL_VIDEO         "col06"  //��Ƶ����ʹ��
#define HID_COL_AUDIO         "col05"  //��Ƶ����ʹ��
#define HID_COL_CMD           "col04"  //����
#define HID_COL_RC            "col03"  //����

typedef enum emDATA_TYPE
{
	DATA_TYPE_VIDEO = 0,   //��Ƶ
	DATA_TYPE_AUDIO,       //��Ƶ
	DATA_TYPE_CMD,         //���������ص��������ʾ
	//DATA_TYPE_RC,          //����
}DATA_TYPE;

typedef struct tagHidDevice
{
	HANDLE     hndHidDevice;            //Handle for hid device
	int        nOverlapped;             //open way
	UINT       uGetReportTimeout;       //Timeout for GetReport requests
	UINT       uSetReportTimeout;       //Timeout for SetReport requests
	OVERLAPPED oRead;                   //Asynchronous I/O structure
	OVERLAPPED oWrite;                  //Asynchronous I/O structure
	WORD       wInReportBufferLength;   //Maximum length of InReport's
	WORD       wOutReportBufferLength;  //Maximum length of OutReport's
	tagHidDevice()
	{
		hndHidDevice = NULL;
		nOverlapped = 0;
		uGetReportTimeout = 500;
		uSetReportTimeout = 1;
		memset(&oRead, 0, sizeof(oRead));
		memset(&oWrite, 0, sizeof(oWrite));
		wInReportBufferLength = 0;
		wOutReportBufferLength = 0;
	}
}THidDevice,*PHidDecive;


/*=============================================================================
�� �� ��:HID_OpenDevice
��    ��:��HID�豸
��    ��:ptHidDevice���Զ���ṹ�壬overlapped���򿪷�ʽ��1�첽��0ͬ��,emType:���ͣ��ж�����һ��hid
ע    ��:��
�� �� ֵ:bool��true�򿪳ɹ���false��ʧ��
=============================================================================*/
HID_API bool HID_OpenDevice(THidDevice *ptHidDevice, int overlapped, HID_TYPE emType);

/*=============================================================================
�� �� ��:HID_CloseDevice
��    ��:�ر�HID�豸
��    ��:ptHidDevice���Զ���ṹ��
ע    ��:��
�� �� ֵ:��
=============================================================================*/
HID_API void HID_CloseDevice(THidDevice *ptHidDevice);

/*=============================================================================
�� �� ��:HID_SendData2Device
��    ��:�������ݵ�hid�豸��ʹ�ö˵�2
��    ��:ptHidDevice���Զ���ṹ�壬writeBuffer��Ҫд���buf��������2048��dwSize����������С�����ͻ�������С��HidP_GetCaps��ȡ��DATA_TYPE��������������
ע    ��:��
�� �� ֵ:bool,true���ͳɹ���false����ʧ��
=============================================================================*/
HID_API bool HID_SendData2Device(THidDevice *ptHidDevice, BYTE* writeBuffer, DWORD dwSize, DATA_TYPE emType);

/*=============================================================================
�� �� ��:HID_SendDataToDevice
��    ��:�������ݵ�hid�豸��������Type
��    ��:ptHidDevice���Զ���ṹ�壬writeBuffer��Ҫд���buf��������2048,DATA_TYPE��������������
ע    ��:��
�� �� ֵ:DWORD,���ͳɹ�0������ʧ�ܴ�����
��    ��:xcr
=============================================================================*/
HID_API DWORD HID_SendDataToDevice(THidDevice *ptHidDevice, BYTE* writeBuffer, DATA_TYPE emType);

/*=============================================================================
�� �� ��:HID_RecvData4Device
��    ��:��hid�豸��������
��    ��:ptHidDevice���Զ���ṹ�壬readBuffer��Ҫ��ȡ��buf��������64��dwSize�����뱨���С�����ջ�������С��HidP_GetCaps��ȡ��DATA_TYPE��������������
ע    ��:��
�� �� ֵ:bool,true���ճɹ���false����ʧ��
=============================================================================*/
HID_API bool HID_RecvData4Device(THidDevice *ptHidDevice, BYTE* readBuffer, UINT dwSize, DATA_TYPE emType);

/*=============================================================================
�� �� ��:HID_RegisterDeviceNotification
��    ��:ע���豸״̬�ı�֪ͨ�Ĵ���
��    ��:hWnd��ע��Ĵ��ھ����diNotifyHandle��HDEVNOTIFY�ṹ��ָ��
ע    ��:��
�� �� ֵ:bool,trueע��ɹ���falseע��ʧ��
=============================================================================*/
HID_API bool HID_RegisterDeviceNotification(HWND hWnd, HDEVNOTIFY* diNotifyHandle);

/*=============================================================================
�� �� ��:HID_UnRegisterDeviceNotification
��    ��:��ע���豸״̬�ı�֪ͨ�Ĵ���
��    ��:diNotifyHandle��HDEVNOTIFY�ṹ��ָ��
ע    ��:��
�� �� ֵ:bool,true��ע��ɹ���false��ע��ʧ��
=============================================================================*/
HID_API bool HID_UnRegisterDeviceNotification(HDEVNOTIFY* diNotifyHandle);

/*=============================================================================
�� �� ��:HID_IsDeviceConnected
��    ��:�ж��豸�Ƿ���Ȼ����
��    ��:ptHidDevice��THidDevice�ṹ��ָ��
ע    ��:��
�� �� ֵ:bool,true���ӣ�falseδ����
=============================================================================*/
HID_API bool HID_IsDeviceConnected(THidDevice *ptHidDevice);

#endif
/**  
 *@ dll说明：usb hid 设备通讯
 *@ 作者: dyy
 *@ 时间: 2017-2-21
 */
#ifndef COMMINTERFACE_H
#define COMMINTERFACE_H

//注意这是个静态库
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

#define USB_VID               0x2dcc   // todo 根据设备实际值定
#define USB_PID               0x8130   // todo 根据设备实际值定


#define LENTH_OUT_BUFFER      2048     //音视频输出buf大小，根据输出报告buf大小定
#define LENTH_IN_BUFFER       64       //用于接收的buf

#define LENTH_OUT_BUFFER_CMD  (66-1)   //命令写入使用的buf
#define LENTH_IN_BUFFER_CMD   6        //命令接收使用的buf

#define PACKET_SIZE           512      //一包大小
#define MAX_BUFFER_NUM        4096     //最大缓冲包数，约2M数据
#define MAX_STORE_NUM         5000     //最大堆积包数，约2M数据

typedef enum emHID_TYPE
{
	HID_TYPE_VIDEO = 0,               //视频码流使用
    HID_TYPE_AUDIO,                   //音频码流使用
	HID_TYPE_CMD,                     //命令
	//HID_TYPE_RC,                      //反控

	HID_TYPE_NUM
}HID_TYPE;

#define HID_COL_VIDEO         "col06"  //视频码流使用
#define HID_COL_AUDIO         "col05"  //音频码流使用
#define HID_COL_CMD           "col04"  //命令
#define HID_COL_RC            "col03"  //反控

typedef enum emDATA_TYPE
{
	DATA_TYPE_VIDEO = 0,   //视频
	DATA_TYPE_AUDIO,       //音频
	DATA_TYPE_CMD,         //网络控制相关的用命令表示
	//DATA_TYPE_RC,          //反控
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
函 数 名:HID_OpenDevice
功    能:打开HID设备
参    数:ptHidDevice：自定义结构体，overlapped：打开方式，1异步，0同步,emType:类型，判断用哪一个hid
注    意:无
返 回 值:bool，true打开成功，false打开失败
=============================================================================*/
HID_API bool HID_OpenDevice(THidDevice *ptHidDevice, int overlapped, HID_TYPE emType);

/*=============================================================================
函 数 名:HID_CloseDevice
功    能:关闭HID设备
参    数:ptHidDevice：自定义结构体
注    意:无
返 回 值:无
=============================================================================*/
HID_API void HID_CloseDevice(THidDevice *ptHidDevice);

/*=============================================================================
函 数 名:HID_SendData2Device
功    能:发送数据到hid设备，使用端点2
参    数:ptHidDevice：自定义结构体，writeBuffer：要写入的buf，不超过2048；dwSize：输出报告大小即发送缓冲区大小，HidP_GetCaps获取；DATA_TYPE：发送数据类型
注    意:无
返 回 值:bool,true发送成功，false发送失败
=============================================================================*/
HID_API bool HID_SendData2Device(THidDevice *ptHidDevice, BYTE* writeBuffer, DWORD dwSize, DATA_TYPE emType);

/*=============================================================================
函 数 名:HID_SendDataToDevice
功    能:发送数据到hid设备，不区分Type
参    数:ptHidDevice：自定义结构体，writeBuffer：要写入的buf，不超过2048,DATA_TYPE：发送数据类型
注    意:无
返 回 值:DWORD,发送成功0，发送失败错误码
作    者:xcr
=============================================================================*/
HID_API DWORD HID_SendDataToDevice(THidDevice *ptHidDevice, BYTE* writeBuffer, DATA_TYPE emType);

/*=============================================================================
函 数 名:HID_RecvData4Device
功    能:从hid设备接收数据
参    数:ptHidDevice：自定义结构体，readBuffer：要读取的buf，不超过64；dwSize：输入报告大小即接收缓冲区大小，HidP_GetCaps获取；DATA_TYPE：接收数据类型
注    意:无
返 回 值:bool,true接收成功，false结束失败
=============================================================================*/
HID_API bool HID_RecvData4Device(THidDevice *ptHidDevice, BYTE* readBuffer, UINT dwSize, DATA_TYPE emType);

/*=============================================================================
函 数 名:HID_RegisterDeviceNotification
功    能:注册设备状态改变通知的窗口
参    数:hWnd：注册的窗口句柄，diNotifyHandle：HDEVNOTIFY结构体指针
注    意:无
返 回 值:bool,true注册成功，false注册失败
=============================================================================*/
HID_API bool HID_RegisterDeviceNotification(HWND hWnd, HDEVNOTIFY* diNotifyHandle);

/*=============================================================================
函 数 名:HID_UnRegisterDeviceNotification
功    能:反注册设备状态改变通知的窗口
参    数:diNotifyHandle：HDEVNOTIFY结构体指针
注    意:无
返 回 值:bool,true反注册成功，false反注册失败
=============================================================================*/
HID_API bool HID_UnRegisterDeviceNotification(HDEVNOTIFY* diNotifyHandle);

/*=============================================================================
函 数 名:HID_IsDeviceConnected
功    能:判断设备是否仍然连接
参    数:ptHidDevice：THidDevice结构体指针
注    意:无
返 回 值:bool,true连接，false未连接
=============================================================================*/
HID_API bool HID_IsDeviceConnected(THidDevice *ptHidDevice);

#endif
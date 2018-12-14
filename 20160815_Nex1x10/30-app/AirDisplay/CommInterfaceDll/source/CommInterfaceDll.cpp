#include "CommInterfaceDll.h"
#include <iostream>
using namespace std;

#include <tchar.h>
#include <atlconv.h>
#include <atlexcept.h>
using namespace ATL;

#pragma comment (lib, "Setupapi.lib")
#pragma comment(lib,"hid.lib")
#pragma comment(lib,"comctl32.lib")

	

bool HID_OpenDevice(THidDevice *ptHidDevice, int overlapped, HID_TYPE emType)
{
	if (!ptHidDevice)
	{
		return false;
	}

	HANDLE   hidHandle;
	GUID     hidGuid;

	HidD_GetHidGuid(&hidGuid);

	HDEVINFO hDevInfo = SetupDiGetClassDevs(
		&hidGuid,
		NULL,
		NULL,
		(DIGCF_PRESENT | DIGCF_DEVICEINTERFACE)); 
	if (hDevInfo == INVALID_HANDLE_VALUE)
	{
		return false;
	}

	SP_DEVICE_INTERFACE_DATA devInfoData;
	devInfoData.cbSize = sizeof (SP_DEVICE_INTERFACE_DATA);
	int deviceNo = 0;

	SetLastError(NO_ERROR);

	//用于统计符合要求Hid设备数
	//static int nCount = 0;

	bool bFind = false;
	while (GetLastError() != ERROR_NO_MORE_ITEMS)
	{
		if (SetupDiEnumInterfaceDevice (hDevInfo,
			0, 
			&hidGuid,
			deviceNo,
			&devInfoData))
		{
			ULONG requiredLength = 0;
			SetupDiGetInterfaceDeviceDetail(hDevInfo,
				&devInfoData,
				NULL, 
				0,
				&requiredLength,
				NULL);

			PSP_INTERFACE_DEVICE_DETAIL_DATA devDetail = 
				(SP_INTERFACE_DEVICE_DETAIL_DATA*) malloc (requiredLength);
			devDetail->cbSize = sizeof(SP_INTERFACE_DEVICE_DETAIL_DATA);

			if(!SetupDiGetInterfaceDeviceDetail(hDevInfo,
				&devInfoData,
				devDetail,
				requiredLength,
				NULL,
				NULL)) 
			{
				free(devDetail);
				++deviceNo;
				continue;
			}

			if (overlapped)
			{
				hidHandle = CreateFile(devDetail->DevicePath,
					GENERIC_READ | GENERIC_WRITE,
					FILE_SHARE_READ | FILE_SHARE_WRITE,
					NULL, 
					OPEN_EXISTING, 
					FILE_FLAG_OVERLAPPED,
					NULL);
			}
			else
			{
				hidHandle = CreateFile(devDetail->DevicePath,
					GENERIC_READ | GENERIC_WRITE,
					FILE_SHARE_READ | FILE_SHARE_WRITE,
					NULL, 
					OPEN_EXISTING, 
					0,
					NULL);
			}

			if (hidHandle==INVALID_HANDLE_VALUE)
			{
				free(devDetail);
				++deviceNo;
				continue;
			}

			//保存设备路径
			WCHAR achDevPath[MAX_PATH] = {0};
			lstrcpy(achDevPath, devDetail->DevicePath);
			
			free(devDetail);

			_HIDD_ATTRIBUTES hidAttributes;
			if(!HidD_GetAttributes(hidHandle, &hidAttributes))
			{
				CloseHandle(hidHandle);
				++deviceNo;
				continue;
			}

			if (USB_VID == hidAttributes.VendorID 
				&& USB_PID == hidAttributes.ProductID)
			{
				string strDevPath = CW2A(achDevPath);
				
				switch (emType)
				{
				case HID_TYPE_VIDEO:
					{
						int nPos = strDevPath.find(HID_COL_VIDEO);
						if (nPos != string::npos )
						{
							bFind = true;
						}
					}
					break;
				case HID_TYPE_AUDIO:
					{
						int nPos = strDevPath.find(HID_COL_AUDIO);
						if (nPos != string::npos )
						{
							bFind = true;
						}
					}
					break;
				case HID_TYPE_CMD:
					{
						int nPos = strDevPath.find(HID_COL_CMD);
						if (nPos != string::npos )
						{
							bFind = true;
						}
					}
					break;
				/*case HID_TYPE_RC:
					{
						int nPos = strDevPath.find(HID_COL_RC);
						if (nPos != string::npos )
						{
							bFind = true;
						}
					}
					break;*/
				default:
					break;
				}

				if (bFind)
				{
					break;
				}
				else
				{
					CloseHandle(hidHandle);
					++deviceNo;
				}
				
				/*nCount++;		
				PRINTMSG("\n-nCount:%d\n",nCount);*/
			}
			else
			{
				CloseHandle(hidHandle);
				++deviceNo;
			}
		}
	}

	SetupDiDestroyDeviceInfoList(hDevInfo);


	if (!bFind)
	{
		return false;
	}

	//获取信息
	ptHidDevice->hndHidDevice =  hidHandle;
	ptHidDevice->nOverlapped = overlapped;
	if (overlapped)
	{
		ptHidDevice->oRead.hEvent = CreateEvent(NULL, FALSE, FALSE, NULL);
		ptHidDevice->oWrite.hEvent = CreateEvent(NULL, FALSE, FALSE, NULL);
	}
	
    PHIDP_PREPARSED_DATA preparsedData;
	if (HidD_GetPreparsedData(hidHandle, &preparsedData))
	{
		HIDP_CAPS capabilities;
		//获得保存设备能力信息的缓冲器句柄
		if (HidP_GetCaps(preparsedData, &capabilities))
		{
			// 获得设备的保存能力
			if (capabilities.InputReportByteLength)
			{
				ptHidDevice->wInReportBufferLength = capabilities.InputReportByteLength;
			}

			if (capabilities.OutputReportByteLength)
			{
				ptHidDevice->wOutReportBufferLength = capabilities.OutputReportByteLength;
			}
		}            

		//释放
		HidD_FreePreparsedData(preparsedData);
	}
	return true;
}

bool HID_RecvData4Device(THidDevice *ptHidDevice, BYTE* readBuffer, UINT dwSize, DATA_TYPE emType)
{
	if (!ptHidDevice)
	{
		return false;
	}

	if (!ptHidDevice->hndHidDevice || !readBuffer)
	{
		return false;
	}
	
	
	DWORD dwReadBytes = 0;
	BYTE ReadReportBuffer[LENTH_IN_BUFFER];
	memset(ReadReportBuffer, 0x00, sizeof(ReadReportBuffer));

	/*switch (emType)
	{
	case DATA_TYPE_CMD:
		ReadReportBuffer[0] = SEND_TYPE_CMD;
		break;
	default:
		break;
	}*/

	//异步
	if (ptHidDevice->nOverlapped)
	{
		if (!ReadFile(ptHidDevice->hndHidDevice, ReadReportBuffer, ptHidDevice->wInReportBufferLength, &dwReadBytes, &ptHidDevice->oRead)) //读取设备发给主机的数据)
		{
			DWORD error = GetLastError();
			//PRINTMSG("\nReadFile：GetLastError：%d", error);
			// If the read fails, see if it is because IO is pending
			if (error == ERROR_IO_PENDING)
			{
				// If there is still data to read, wait on the event object based on uGetReportTimeout
				DWORD waitStatus = WaitForSingleObject(ptHidDevice->oRead.hEvent, ptHidDevice->uGetReportTimeout);
				// If the object is signaled, then get the overlapped result, the read succeeded
				// Otherwise determine if the error was a timeout, or another error
				if (waitStatus == WAIT_OBJECT_0)
				{      
					//读到进这里 --说明:异步读，错误码为ERROR_IO_PENDING且信号变为有信号即为读到
					GetOverlappedResult(ptHidDevice->hndHidDevice, &ptHidDevice->oRead, &dwReadBytes, FALSE); 
					
					//实际读到字节数，处理拔掉的异常处理
					if (dwReadBytes <= 0)
					{
						return false;
					}

					if ( DATA_TYPE_CMD == emType && ReadReportBuffer[0] != SEND_TYPE_CMD)
					{
						return false;
					}

					//打印读取信息
					if (CPrint::GetPrintLevel() > PRT_TYPE_OFF)
					{
						SYSTEMTIME st;
						GetLocalTime(&st);
						PRINTMSG_NOLOG( "\r\nTIME:%02d:%02d:%02d\r\n", st.wHour,st.wMinute,st.wSecond );
						PRINTMSG_NOLOG("\r\n异步ReadFile--dwReadBytes:%d\r\n",dwReadBytes);
						for(int i=0;i<LENTH_IN_BUFFER;i++)
						{
							PRINTMSG_NOLOG("%x",ReadReportBuffer[i]);
						}
						PRINTMSG_NOLOG("\r\nend-----------\r\n");
					}
				}
				else if (waitStatus == WAIT_TIMEOUT)
				{
					//PRINTMSG("\nHID_RecvData4Device:waitStatus = WAIT_TIMEOUT\n");
					CancelIo(ptHidDevice->hndHidDevice);
					return false;
				}
				else
				{
					//PRINTMSG("\nHID_RecvData4Device:HID_DEVICE_TRANSFER_FAILED\n");
					CancelIo(ptHidDevice->hndHidDevice);
					return false;
				}                    
			}
			else
			{
				//PRINTMSG("\r\nHID_RecvData4Device:HID_DEVICE_TRANSFER_FAILED----\r\n");
				return false;
			}

		}
	}
	else //同步
	{
		if(!ReadFile(ptHidDevice->hndHidDevice, ReadReportBuffer, ptHidDevice->wInReportBufferLength, &dwReadBytes, NULL))
		{
			DWORD error = GetLastError();
			PRINTMSG("\r\nReadFile：GetLastError：%d,HID_RecvData4Device同步接收失败", error);
			return false;
		} 
		//打印读取信息
		if (CPrint::GetPrintLevel() > PRT_TYPE_OFF)
		{
			PRINTMSG_NOLOG("\r\n同步ReadFile--dwReadBytes:%d\r\n",dwReadBytes);
			for(int i=0;i<LENTH_IN_BUFFER;i++)
			{
				PRINTMSG_NOLOG("%x",ReadReportBuffer[i]);
			}
			PRINTMSG_NOLOG("\r\nend-----------\r\n");
		}
		
	}

	memcpy(readBuffer, ReadReportBuffer+1, dwSize);

	return true;
}

 bool HID_SendData2Device(THidDevice *ptHidDevice, BYTE* writeBuffer, DWORD dwSize, DATA_TYPE emType)
 {
	 if (!ptHidDevice)
	 {
		 return false;
	 }

	 if (!ptHidDevice->hndHidDevice || !writeBuffer)
	 {
		 return false;
	 }
	 
 	DWORD dwWriteBytes = 0;
 	BYTE WriteReportBuffer[LENTH_OUT_BUFFER];
 	memset(WriteReportBuffer, 0x00, sizeof(WriteReportBuffer));
 
	//根据类型使用不同的报告ID
	switch (emType)
	{
	case DATA_TYPE_VIDEO:
		WriteReportBuffer[0] = SEND_TYPE_VIDEO;
		break;
	case DATA_TYPE_AUDIO:
		WriteReportBuffer[0] = SEND_TYPE_AUDIO;
		break;
	case DATA_TYPE_CMD:
		WriteReportBuffer[0] = SEND_TYPE_CMD;
		break;
	default:
		break;
	}
	
	memcpy(WriteReportBuffer+1, writeBuffer, dwSize);
 
	//异步
	if (ptHidDevice->nOverlapped)
	{
		if (!WriteFile(ptHidDevice->hndHidDevice, WriteReportBuffer, ptHidDevice->wOutReportBufferLength, &dwWriteBytes, &ptHidDevice->oWrite)) //写入数据到设备
		{
			//异步WriteFile返回FALSE且错误码为ERROR_IO_PENDING，事件变为有信号状态认为是传输完成
			DWORD error = GetLastError();
			if (error == ERROR_IO_PENDING)
			{
				//HidD_FlushQueue(ptHidDevice->hndHidDevice);//新加的

				DWORD waitStatus;

				//If there is still data to be written, wait on the event for some seconds
				waitStatus = WaitForSingleObject(ptHidDevice->oWrite.hEvent, ptHidDevice->uSetReportTimeout);

				// If the object is signaled, then get the overlapped result, the write succeeded
				// Otherwise determine if the error was a timeout, or another error
				if (waitStatus == WAIT_OBJECT_0)
				{
					GetOverlappedResult(ptHidDevice->hndHidDevice, &ptHidDevice->oWrite, &dwWriteBytes, FALSE);
				}
				else if (waitStatus == WAIT_TIMEOUT)
				{
					//PRINTMSG("\nHID_SendData2Device:waitStatus = WAIT_TIMEOUT\n");
					CancelIo(ptHidDevice->hndHidDevice);
					return false;
				}
				else
				{
					/*PRINTMSG("\nHID_SendData2Device:HID_DEVICE_TRANSFER_FAILED\n");*/
					CancelIo(ptHidDevice->hndHidDevice);
					return false;
				}

			}
			else
			{
				//PRINTMSG("\r\nWriteFile：GetLastError：%d,HID_SendData2Device:HID_DEVICE_TRANSFER_FAILED", error);
				return false;
			}
		}
	}
	else  //同步
	{
		if( !WriteFile(ptHidDevice->hndHidDevice, WriteReportBuffer, ptHidDevice->wOutReportBufferLength, &dwWriteBytes, NULL) )
		{
			DWORD error = GetLastError();
			PRINTMSG("\r\nWriteFile：GetLastError：%d,HID_SendData2Device同步发送失败", error);
			return false;
		}
    }


    return true;
 }


DWORD HID_SendDataToDevice( THidDevice *ptHidDevice, BYTE* writeBuffer, DATA_TYPE emType )
{
    if (!ptHidDevice)
    {
        return -1;
    }

    if (!ptHidDevice->hndHidDevice || !writeBuffer)
    {
        return -1;
    }
	 
 	DWORD dwWriteBytes = 0;

	//异步
	if (ptHidDevice->nOverlapped)
	{
		if (!WriteFile(ptHidDevice->hndHidDevice, writeBuffer, ptHidDevice->wOutReportBufferLength, &dwWriteBytes, &ptHidDevice->oWrite)) //写入数据到设备
		{
			//异步WriteFile返回FALSE且错误码为ERROR_IO_PENDING，事件变为有信号状态认为是传输完成
			DWORD error = GetLastError();
			if (error == ERROR_IO_PENDING)
			{
				DWORD waitStatus;

				//If there is still data to be written, wait on the event for some seconds
				waitStatus = WaitForSingleObject(ptHidDevice->oWrite.hEvent, ptHidDevice->uSetReportTimeout);

				// If the object is signaled, then get the overlapped result, the write succeeded
				// Otherwise determine if the error was a timeout, or another error
				if (waitStatus == WAIT_OBJECT_0)
				{
					GetOverlappedResult(ptHidDevice->hndHidDevice, &ptHidDevice->oWrite, &dwWriteBytes, FALSE);
				}
				else if (waitStatus == WAIT_TIMEOUT)
				{
					CancelIo(ptHidDevice->hndHidDevice);
					return error;
				}
				else
				{
					CancelIo(ptHidDevice->hndHidDevice);
					return error;
				}
			}
			else
			{
				PRINTMSG("\r\nWriteFile：GetLastError：%d,HID_SendDataToDevice:HID_DEVICE_TRANSFER_FAILED", error);
				return error;
			}
		}
	}
	else  //同步
	{
		if( !WriteFile(ptHidDevice->hndHidDevice, writeBuffer, ptHidDevice->wOutReportBufferLength, &dwWriteBytes, NULL) )
		{
			DWORD error = GetLastError();
			if ( DATA_TYPE_VIDEO == emType && CPrint::IsPrintVideo())
			{				
				PRINTMSG("VIEDO:WriteFile：GetLastError：%d,HID_SendDataToDevice同步发送失败\r\n", error);
			}
		
			if ( DATA_TYPE_AUDIO == emType && CPrint::IsPrintAudio() )
			{
				PRINTMSG("AUDIO:WriteFile：GetLastError：%d,HID_SendDataToDevice同步发送失败\r\n", error);
			}
			return error;
		}
    }

    return 0;
}



 void HID_CloseDevice(THidDevice *ptHidDevice)
 {
	 if (!ptHidDevice)
	 {
		 return;
	 }

	 if (ptHidDevice->hndHidDevice)
	 {
		 CloseHandle(ptHidDevice->hndHidDevice);
		 ptHidDevice->hndHidDevice = NULL;
		 
		 if (ptHidDevice->nOverlapped)
		 {
			 ResetEvent(ptHidDevice->oRead.hEvent);
			 ResetEvent(ptHidDevice->oWrite.hEvent);
			 CloseHandle(ptHidDevice->oRead.hEvent);
			 CloseHandle(ptHidDevice->oWrite.hEvent);
		 }
	 }
 }

 HID_API bool HID_RegisterDeviceNotification( HWND hWnd, HDEVNOTIFY* diNotifyHandle )
 {
	 bool bRst = false;

	 DEV_BROADCAST_DEVICEINTERFACE broadcastInterface;

	 broadcastInterface.dbcc_size = sizeof(DEV_BROADCAST_DEVICEINTERFACE);
	 broadcastInterface.dbcc_devicetype = DBT_DEVTYP_DEVICEINTERFACE;
	 HidD_GetHidGuid(&broadcastInterface.dbcc_classguid);

	 *diNotifyHandle = RegisterDeviceNotification(hWnd, &broadcastInterface, DEVICE_NOTIFY_WINDOW_HANDLE);

	 if (diNotifyHandle)
	 {
		 bRst = true;
	 }

	 return bRst;
 }

 HID_API bool HID_UnRegisterDeviceNotification( HDEVNOTIFY* diNotifyHandle )
 {
	 bool bRst = false;
	 if(UnregisterDeviceNotification(*diNotifyHandle))
	 {
		 bRst = true;
	 }

	 return bRst;
 }

 HID_API bool HID_IsDeviceConnected( THidDevice *ptHidDevice )
 {
	 _HIDD_ATTRIBUTES hidDeviceAttributes;
	 bool bRst = false;

	 // User HID attributes with HID handle of the HID device to check if device is still connected
	 if (HidD_GetAttributes(ptHidDevice->hndHidDevice, &hidDeviceAttributes))
	 {
		 bRst = true;        // Returns true if device is still connected
	 }
	 
	 return bRst;
 }

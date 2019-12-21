/*******************************************************************************//**
*@file          nvapi_struct.h
*@brief         提供nvapi对外的结构体定义
*
*@author        ruiyigen
*@version       5.0    
*@date          20150328
*@copyright     (c)1995-2015 Suzhou Keda Technology Co.,Ltd. All rights reserved
***********************************************************************************/
#ifndef _NVAPI_STRUCT_H_
#define _NVAPI_STRUCT_H_
/**@addtogroup common 公用
*@{
*/

/**@addtogroup struct 结构定义
*@{
*/

#include "nvapi_enum.h"
#include "nvapi_def.h"

/** 无线投屏usb消息指令*/
typedef struct tagTNVQKUsbInput_Api
{
	s8  achValue[KNVAPI_BUF_64_LEN];               ///<给到无线投屏usb的数据
public:
	tagTNVQKUsbInput_Api()	{ memset( this, 0, sizeof(*this) ); }
}*PTNVQKUsbInput_Api, TNVQKUsbInput_Api;
/**@}*/

/** 无线投屏源信息*/
typedef struct tagTNVQKVidSrcSignal_Api
{
	u32 dwIndex;                                  //投屏器序号,值为0时非投屏器
	BOOL32 bIsHasSrc;                             //是否有源
	s8 achVidName[KNVAPI_BUF_64_LEN];             //无线投屏pcname
	s8 achQkVer[KNVAPI_BUF_64_LEN];               //无线投屏版本
public:
	tagTNVQKVidSrcSignal_Api()	{ memset( this, 0, sizeof(*this) ); }
}*PTNVQKVidSrcSignal_Api, TNVQKVidSrcSignal_Api;

/** 无线投屏反控指令*/
typedef struct tagTNVQKControlEvent_Api
{
	u32 dwValue[KNVAPI_BUF_64_LEN];               ///<给到无线投屏usb的数据
	u32 dwCnt;                                  ///<数据个数
public:
	tagTNVQKControlEvent_Api()	{ memset( this, 0, sizeof(*this) ); }
}*PTNVQKControlEvent_Api, TNVQKControlEvent_Api;

/** 视频源信息*/
typedef struct tagTNVQKVidSrcInfo_Api
{
	u32 dwVideoWidth;                           //视频宽，像素为单位,为0表示无信号
	u32 dwVideoHeight;                         // 视频高，行为单位,为0表示无信号
	u32 dwFrameRate;                           // 帧率，逐行时=场频，隔行时=场频/2，即60i=30P,为0表示无信号
public:
	tagTNVQKVidSrcInfo_Api() {memset( this, 0, sizeof(*this) );}
}*PTNVQKVidSrcInfo_Api, TNVQKVidSrcInfo_Api;

/** 无线投屏编码参数*/
typedef struct tagTNVQKCodeParam_Api
{
	u8                  byVidFormat;              //视频格式
	u8                  byAudFormat;              //音频格式
	EmNvQkCodeRes_Api   emRes;                    //分辨率
	u32                 dwFrameRate;              //帧率(最高30帧)
	u32                 dwBitRate;                //码率(64K ~ 8192K)
public:
	tagTNVQKCodeParam_Api()	{ memset( this, 0, sizeof(*this) ); }
}*PTNVQKCodeParam_Api, TNVQKCodeParam_Api;

/** 无线投屏升级版本信息*/
typedef struct tagTNVQKUpgradeInfo_Api
{
	BOOL32    bHasQkUpgradeFile;                                 //无线投屏器是否有升级包
	s8        achQkUpgradeVer[KNVAPI_BUF_64_LEN];               //无线投屏升级版本
public:
	tagTNVQKUpgradeInfo_Api()	{ memset( this, 0, sizeof(*this) ); }
}*PTNVQKUpgradeInfo_Api, TNVQKUpgradeInfo_Api;
/**@}*/

/**@}*/
#endif //!_NVAPI_STRUCT_H_
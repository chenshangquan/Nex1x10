#ifndef _NVSTRUCT_H_
#define _NVSTRUCT_H_

#include "kdvtype.h"
#include "nvconst.h"
#include "osp.h"

//模块启动参数
typedef struct tagTMdlStartParam
{
	BOOL32 bSingleProcess; //是否独立进程方式加载，主要用于决定是否需要OSP建链。对于系统控制模块启动的方式填FALSE，独立进程方式填TRUE
	u32    dwAidParam;     //模块辅助参数
public:
	tagTMdlStartParam()
	{
		bSingleProcess = FALSE;
		dwAidParam = 0;
	}
} TMdlStartParam, *PTMdlStartParam;

typedef struct tagTNVDfTagProductId_API
{	
	s8              achTagProductId[NV_STR_LEN_64];		//目标设备的产品名称
	BOOL32          bFound;
public:
	tagTNVDfTagProductId_API(){ memset( this, 0, sizeof(struct tagTNVDfTagProductId_API) ); }
}TNVDfTagProductId_API,*PTNVDfTagProductId_API;

//设备发现参数
typedef struct tagTNVDfClientParam_API
{	
	s8						achVersionId[NV_STR_LEN_64];		//设备发现协议版本号
	s8						achProductId[NV_STR_LEN_64];				//产品名称
	TNVDfTagProductId_API 	tTagProductId[NV_TARGET_DEVICE_NUM];
	u8              		byTagDeviceNum;  //目标设备数目
	s8						achIfrName[NV_STR_LEN_64];//网络接口名字
public:
	tagTNVDfClientParam_API(){ memset( this, 0, sizeof(struct tagTNVDfClientParam_API) ); }
}TNVDfClientParam_API,*PTNVDfClientParam_API;

//设备发现参数
typedef struct tagTNVDfServiceParam_API
{	
	s8		achVersionId[NV_STR_LEN_64];//设备发现协议版本号
	s8		achProductId[NV_STR_LEN_64];//产品名称
	s8 		achDevieIP[NV_STR_LEN_64];  //设备ip
public:
	tagTNVDfServiceParam_API(){ memset( this, 0, sizeof(struct tagTNVDfServiceParam_API) ); }
}TNVDfServiceParam_API,*PTNVDfServiceParam_API;

#endif// _NVSTRUCT_H_
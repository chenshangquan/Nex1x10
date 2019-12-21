#ifndef _NVSTRUCT_H_
#define _NVSTRUCT_H_

#include "kdvtype.h"
#include "nvconst.h"
#include "osp.h"

//ģ����������
typedef struct tagTMdlStartParam
{
	BOOL32 bSingleProcess; //�Ƿ�������̷�ʽ���أ���Ҫ���ھ����Ƿ���ҪOSP����������ϵͳ����ģ�������ķ�ʽ��FALSE���������̷�ʽ��TRUE
	u32    dwAidParam;     //ģ�鸨������
public:
	tagTMdlStartParam()
	{
		bSingleProcess = FALSE;
		dwAidParam = 0;
	}
} TMdlStartParam, *PTMdlStartParam;

typedef struct tagTNVDfTagProductId_API
{	
	s8              achTagProductId[NV_STR_LEN_64];		//Ŀ���豸�Ĳ�Ʒ����
	BOOL32          bFound;
public:
	tagTNVDfTagProductId_API(){ memset( this, 0, sizeof(struct tagTNVDfTagProductId_API) ); }
}TNVDfTagProductId_API,*PTNVDfTagProductId_API;

//�豸���ֲ���
typedef struct tagTNVDfClientParam_API
{	
	s8						achVersionId[NV_STR_LEN_64];		//�豸����Э��汾��
	s8						achProductId[NV_STR_LEN_64];				//��Ʒ����
	TNVDfTagProductId_API 	tTagProductId[NV_TARGET_DEVICE_NUM];
	u8              		byTagDeviceNum;  //Ŀ���豸��Ŀ
	s8						achIfrName[NV_STR_LEN_64];//����ӿ�����
public:
	tagTNVDfClientParam_API(){ memset( this, 0, sizeof(struct tagTNVDfClientParam_API) ); }
}TNVDfClientParam_API,*PTNVDfClientParam_API;

//�豸���ֲ���
typedef struct tagTNVDfServiceParam_API
{	
	s8		achVersionId[NV_STR_LEN_64];//�豸����Э��汾��
	s8		achProductId[NV_STR_LEN_64];//��Ʒ����
	s8 		achDevieIP[NV_STR_LEN_64];  //�豸ip
public:
	tagTNVDfServiceParam_API(){ memset( this, 0, sizeof(struct tagTNVDfServiceParam_API) ); }
}TNVDfServiceParam_API,*PTNVDfServiceParam_API;

#endif// _NVSTRUCT_H_
#ifndef _MT_MTAIADAPTER_H_
#define _MT_MTAIADAPTER_H_

#include "kdvtype.h"
#include "mtconst.h"
#include <string.h>

typedef s32 (*MtAiAdapter_Callback)(void *pUserdata, s32 nType, s8 *pData, s32 nLen);

typedef struct tagTMtAiAdatperInitCfg
{
	s8 achProductId[MT_STR_LEN_64+1];
	s8 achProfileFilePath[MT_STR_LEN_64+1];
	
	tagTMtAiAdatperInitCfg()
	{
		memset(this, 0, sizeof(tagTMtAiAdatperInitCfg) );
	}
}TMtAiAdatperInitCfg;

typedef struct tagTMtWakeupCfg
{
	s8 achResBinPath[MT_STR_LEN_64+1];
	MtAiAdapter_Callback  cbCallback;
	void* pUserData;

	tagTMtWakeupCfg()
	{
		memset(this, 0, sizeof(tagTMtWakeupCfg) );
	}
}TMtWakeupCfg;


typedef struct tagTMtWakeupParam 
{

	s8 achWakeupPinyin[MT_STR_LEN_64+1];
	s8 achThresh[MT_STR_LEN_16+1]; ///0-1֮��

	tagTMtWakeupParam()
	{
		memset(this, 0, sizeof(tagTMtWakeupParam) );
	}
}TMtWakeupParam;



typedef struct tagTMtVadCfg
{
	s8 achResBinPath[MT_STR_LEN_64+1];    //vad��Դ��ַ����ѡ
	u16 wPauseTime;                    //ͣ�ٶ೤ʱ�䣬��Ϊvad��������λms����ѡ
	MtAiAdapter_Callback  cbCallback;  //�ص��������᷵��json��binary�������͵����ݣ�����json������Ƶ�Ŀ�ʼ�ͽ���״̬��binaryΪvad����֮���
	void* pUserData;

	tagTMtVadCfg()
	{
		memset(this, 0, sizeof(tagTMtVadCfg) );
		wPauseTime = 500;
	}
}TMtVadCfg;


typedef struct tagTMtAsrCfg
{
	s8 achGramResBinPath[MT_STR_LEN_64+1];    //�﷨������Դ·������ѡ
	s8 achOutputPath[MT_STR_LEN_64+1];    //���ɵ��﷨�ļ�·������ѡ
	s8 achXbnfFile[MT_STR_LEN_64+1];      ///xbnf��ʽ��˵���ļ�
	s8 achAsrResBinPath[MT_STR_LEN_64+1]; //ʶ����Դ�ļ�����ѡ

	MtAiAdapter_Callback  cbCallback;  //�ص��������᷵��json��binary�������͵����ݣ�����json������Ƶ�Ŀ�ʼ�ͽ���״̬��binaryΪvad����֮���
	void* pUserData;

	tagTMtAsrCfg()
	{
		memset(this, 0, sizeof(tagTMtAsrCfg) );
	}
}TMtAsrCfg;

typedef struct tagTMtCnttsCfg
{
	s8 achResBinPath[MT_STR_LEN_64+1];    //vad��Դ��ַ����ѡ
	s8 achDictPath[MT_STR_LEN_64+1];
	MtAiAdapter_Callback  cbCallback;  //�ص��������᷵��json��binary�������͵����ݣ�����json������Ƶ�Ŀ�ʼ�ͽ���״̬��binaryΪvad����֮���
	void* pUserData;

	tagTMtCnttsCfg()
	{
		memset(this, 0, sizeof(tagTMtCnttsCfg) );
	}
}TMtCnttsCfg;


#ifdef WIN32
#define  SNPRINTF           _snprintf
#else
#define  SNPRINTF           snprintf
#endif


s32 InitMtAiadapter( TMtAiAdatperInitCfg *pCfg); ////��ʼ����
void* InitWakeup(TMtWakeupCfg *ptCfg);
void* InitVad(TMtVadCfg *ptCfg);
void* InitCntts(TMtCnttsCfg *ptCfg); 
void* InitAsr(TMtAsrCfg *ptCfg); 
void* ReinitAsr(TMtAsrCfg *ptCfg, void* pAsr); ///

s32 DeleteAsr(void *pAsr);
s32 DeteteVad(void* pVad);
s32 DeleteWakeup( void *pWakeup);
s32 DeleteCntts(void *pCntts);
void ReleaseAiadapter();

s32 StartWakeup(void *pWakeup, TMtWakeupParam *ptWakeupParam);
s32 FeedWakeup(void *pWakeup, u8* pbyData, u32 dwLen);
s32 StopWakeup(void *pWakeup);

s32 StartVad(void *pVad);
s32 FeedVad(void *pVad,u8* pbyData, u32 dwLen );
s32 StopVad(void *pVad);

s32 StartCntts(void *pCntts);
s32 FeedCntts(void *pCntts, u8* pbyData);
s32 StopCntts(void *pCntts);

s32 StartAsr(void *pAsr);
s32 FeedAsr(void *pAsr, u8* pbyData, u32 dwLen );
s32 StopAsr(void *pAsr);


#endif 
#ifndef _MT_MTAIADAPTER_H_
#define _MT_MTAIADAPTER_H_

#include "kdvtype.h"
#include <string.h>

#define MT_STR_LEN_64		(u32)64
#define MT_STR_LEN_16		(u32)16


typedef s32 (*MtAiAdapter_Callback)(void *pUserdata, s32 nType, s8 *pData, s32 nLen);

typedef struct tagTMtAiAdatperInitCfg
{
	s8 achProductId[MT_STR_LEN_64+1];       // "278576968"
	s8 achProfileFilePath[MT_STR_LEN_64+1]; // ��дauthkey.txt·��
	
	tagTMtAiAdatperInitCfg()
	{
		memset(this, 0, sizeof(tagTMtAiAdatperInitCfg) );
	}
}TMtAiAdatperInitCfg;

typedef struct tagTMtWakeupCfg
{
	s8 achResBinPath[MT_STR_LEN_64+1];  //��д wakeup.bin�ļ�·��
	MtAiAdapter_Callback  cbCallback;   //�ص��������лص�����Ϊ���ѣ��ص������Ȳ�����(��ʵ����Ҳ�����ζȣ���ʱ����)
	void* pUserData;                    //������

	tagTMtWakeupCfg()
	{
		memset(this, 0, sizeof(tagTMtWakeupCfg) );
	}
}TMtWakeupCfg;


typedef struct tagTMtWakeupParam 
{

	s8 achWakeupPinyin[MT_STR_LEN_64+1];//���� ni hao xiao ke
	s8 achThresh[MT_STR_LEN_16+1]; ///0-1֮�䣬ֵԽС��Խ���׻���
	s8 achMajor[MT_STR_LEN_16+1];  // һ����д 1
	tagTMtWakeupParam()
	{
		memset(this, 0, sizeof(tagTMtWakeupParam) );
	}
}TMtWakeupParam;



typedef struct tagTMtVadCfg
{
	s8 achResBinPath[MT_STR_LEN_64+1];    //��д vad.bin�ļ�·������ѡ
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
	s8 achGramResBinPath[MT_STR_LEN_64+1];    //��д gramebnfc.bin�ļ�·������ѡ
	s8 achOutputPath[MT_STR_LEN_64+1];    //��дҪ���� gramoutput.bin�ļ�·��(�ļ������Լ�����)����ѡ
	s8 achXbnfFile[MT_STR_LEN_64+1];      ///��д gram.xbnf�ļ�·��
	s8 achAsrResBinPath[MT_STR_LEN_64+1]; //��д asrebnfr.bin�ļ�·������ѡ

	MtAiAdapter_Callback  cbCallback;  //�ص��������᷵��json��binary�������͵����ݣ�����json�ɽ�������Ϊ��binaryΪ��Ƶ����
	void* pUserData;

	tagTMtAsrCfg()
	{
		memset(this, 0, sizeof(tagTMtAsrCfg) );
	}
}TMtAsrCfg;

//cntts�����ϳɣ�Ŀǰ�ɲ���
typedef struct tagTMtCnttsCfg
{
	s8 achResBinPath[MT_STR_LEN_64+1];    //��дzhilingf.bin�ļ�·������ѡ
	s8 achDictPath[MT_STR_LEN_64+1];      //��дsent_dict.db�ļ�·��, ��ѡ
	MtAiAdapter_Callback  cbCallback;  //�ص��������᷵��json��binary�������͵����ݣ�binaryΪ�ϳ���������pcm��ʽ
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
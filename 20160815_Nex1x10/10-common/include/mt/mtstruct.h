#ifndef _MTSTRUCT_H_
#define _MTSTRUCT_H_

#include "kdvtype.h"
#include "mtconst.h"

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

#endif// _MTSTRUCT_H_
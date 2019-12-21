#ifndef _MTSTRUCT_H_
#define _MTSTRUCT_H_

#include "kdvtype.h"
#include "mtconst.h"

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

#endif// _MTSTRUCT_H_
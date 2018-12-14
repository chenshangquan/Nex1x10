#ifndef _NVDSCOMMON_H_
#define _NVDSCOMMON_H_
#include "kdvtype.h"
#include "nvmacro.h"

#define USE_STRING_KEY

#if defined(USE_STRING_KEY) //ʹ��std string��Ϊkey����
  typedef std::string KEY;
#else
  typedef int KEY;
#endif // USE_STRING_KEY

NVCBB_API void InitNvDsc( u16 wDssPort );

//���ݹ�������붨��
#define DSE_OK    u32(0)
#define DSE_ERROR u32(1)
#define DSE_BUF   u32(2) //<��������С
#define DSE_NODE  u32(3) //SetDataû�п��е�node�ɷ���
#define DSE_SIZE  u32(4) //SetDataҪ������ݴ�С̫��
#define DSE_KEY   u32(5) //GetDataҪ���key������

#endif // _NVDSCOMMON_H_
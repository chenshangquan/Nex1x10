#ifndef _NVDSCOMMON_H_
#define _NVDSCOMMON_H_
#include "kdvtype.h"
#include "nvmacro.h"

#define USE_STRING_KEY

#if defined(USE_STRING_KEY) //使用std string作为key类型
  typedef std::string KEY;
#else
  typedef int KEY;
#endif // USE_STRING_KEY

NVCBB_API void InitNvDsc( u16 wDssPort );

//数据共享错误码定义
#define DSE_OK    u32(0)
#define DSE_ERROR u32(1)
#define DSE_BUF   u32(2) //<缓冲区过小
#define DSE_NODE  u32(3) //SetData没有空闲的node可分配
#define DSE_SIZE  u32(4) //SetData要求的数据大小太大
#define DSE_KEY   u32(5) //GetData要求的key不存在

#endif // _NVDSCOMMON_H_
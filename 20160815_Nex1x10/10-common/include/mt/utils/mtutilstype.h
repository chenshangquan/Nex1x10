#ifndef _MTUTILSTYPE_H_
#define _MTUTILSTYPE_H_
#include "kdvtype.h"

namespace MTUTILS {

enum EmMtOSType
{
	emAndroid,
	emIOS,
	emLinux,
	emWindows,
	emUnknownOs,
};

//哈希函数类型
enum EMHashType
{
	emHashNone = 0,
	emSDBMHash,
	emELFHash,
	emHashEnd = 5
};

//地址类型
enum EmAddrType
{
	emAddrTypeIP      = 0,
	emAddrTypeE164    = 1,
	emAddrTypeAlias   = 2,
	emAddrTypeDialNum = 3,
	emAddrTypeSipUri  = 4
};

/** 时间结构 */
typedef struct tagTDateTime 
{
	u32 dwYear;
	u32 dwMonth;
	u32 dwDay;
	u32 dwHour;
	u32 dwMinute;
	u32 dwSecond;
	u32 dwMicrosecond;
} TDateTime, *PTTDateTime;

} // namespace MTUTILS


#endif
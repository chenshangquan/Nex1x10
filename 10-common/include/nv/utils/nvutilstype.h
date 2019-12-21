#ifndef _NVUTILSTYPE_H_
#define _NVUTILSTYPE_H_
#include "kdvtype.h"

namespace NVUTILS {

enum EmNvOSType
{
	emAndroid,
	emIOS,
	emLinux,
	emWindows,
	emUnknownOs,
};

//��ϣ��������
enum EMHashType
{
	emHashNone = 0,
	emSDBMHash,
	emELFHash,
	emHashEnd = 5
};

//��ַ����
enum EmAddrType
{
	emAddrTypeIP      = 0,
	emAddrTypeE164    = 1,
	emAddrTypeAlias   = 2,
	emAddrTypeDialNum = 3,
	emAddrTypeSipUri  = 4
};

/** ʱ��ṹ */
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

} // namespace NVUTILS


#endif
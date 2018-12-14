/*****************************************************************************
模块�?     : ProtocolCommonPublic
文件�?     : protocolcommonpublic.h
相关文件    : �?
文件实现功能: 协议组对外公共组�?
作�?       : 
版本        : V1.0  Copyright(C) 2014 KDC, All rights reserved.
-----------------------------------------------------------------------------
修改记录:
�? �?     版本        修改�?     修改内容
2014/12/24  1.0         洪元      Create
******************************************************************************/

#ifndef _PROTOCOL_COMMON_PUBLIC_H_
#define _PROTOCOL_COMMON_PUBLIC_H_

#include <string.h>
#include <kdvtype.h>

///////////////////////////////////////////////////////////
// private type definition for protocol components (for 64-bit support)
///////////////////////////////////////////////////////////
typedef void* MemId;

#ifndef IN
	#define IN
#endif//!IN
#ifndef OUT
	#define OUT
#endif//!OUT
#ifndef INOUT
	#define INOUT
#endif

#if (defined(WIN32) || defined(_WIN32) ) && !defined(_PROTO_STATICLIB_)
	// for Microsoft c++
	#define PROTO_EXTERN_API	extern "C"	__declspec(dllexport)
	#ifndef _PROTO_LIB_
		#define PROTO_API		__declspec(dllexport)
	#else
		#define PROTO_API		__declspec(dllimport)
	#endif
	#define PROTO_CALLBACK		__cdecl
#else
	// for gcc
	#define PROTO_EXTERN_API	extern "C"
	#define PROTO_API
	#define PROTO_CALLBACK
#endif  // _MSC_VER

///////////////////////////////////////////////////////////
// common macro definitions
///////////////////////////////////////////////////////////
#ifndef MEMCPY_CAST
    #define MEMCPY_CAST(dst, src, len) memcpy(static_cast<void*>(dst), static_cast<const void*>(src), len)
#endif

#ifndef MEMMOVE_CAST
	#define MEMMOVE_CAST(dst, src, len) memmove(static_cast<void*>(dst), static_cast<const void*>(src), len)
#endif

#ifndef MEMSET_CAST
   #define MEMSET_CAST(dst, val, len)  memset(static_cast<void*>(dst), val, len)
#endif

#ifndef MEMCMP_CAST
	#define MEMCMP_CAST(val1, val2, len) memcmp(static_cast<const void*>(val1), static_cast<const void*>(val2), len)
#endif

#ifndef STRCMP_CAST
    #define STRCMP_CAST(val1, val2)  strcmp(static_cast<const char*>(val1), static_cast<const char*>(val2))
#endif

#ifndef SAFE_DELETE
	#define SAFE_DELETE(p)		{ if(p) { delete (p); (p)=NULL; } }
#endif
#ifndef SAFE_DELETE_ARRAY
	#define SAFE_DELETE_ARRAY(p){ if(p) { delete[] (p); (p)=NULL; } }
#endif

//���뼶��sleep
#if defined(WIN32) || defined(_WIN32)
#define SLEEPMS(x) Sleep(x)
#elif defined(_UNIX_) || defined(_LINUX_)
#include <unistd.h>
#define SLEEPMS(x) usleep(((x)*1000))
#else
#define SLEEPMS(x)
#endif

//be used to print
#define IPFORMAT      "%d.%d.%d.%d"
#define u32ToIP(ip)   (u8)(ntohl(ip)>>24), (u8)(ntohl(ip)>>16), (u8)(ntohl(ip)>>8), (u8)ntohl(ip)

///////////////////////////////////////////////////////////
// common inline C++ functions
///////////////////////////////////////////////////////////
template <class T>
inline const T& Maximum(const T& a, const T&b)
{
    return a < b ? b : a;
}

template <class T>
//lint -e{1413}
inline const T Minimum(const T a, const T b)
{
    return a > b ? b : a;
}

template < class T >
T SAFE_COPY( T &t, u8 *pbyP )
{
	if (NULL == pbyP) return t;
	memcpy( &t, pbyP, sizeof( T ) );
	return t;
}

/*lint -e843 */
/*lint -e438 */

//add callback function for print
typedef void (*ALL_LOG_CALlBACK)(const s8* pchbuf, u32 dwLen);

#endif

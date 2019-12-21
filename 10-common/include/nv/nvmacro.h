#if !defined(_NVMACRO_H_)
#define _NVMACRO_H_

#ifdef _MSC_VER
#  define NVCBB_API  __declspec(dllexport)
#else
#  define NVCBB_API
#endif  // _MSC_VER

#ifndef NULL
#  ifdef __cplusplus
#    define NULL    0
#  else
#    define NULL    ((void *)0)
#  endif
#endif

#ifndef IN
#  define IN
#endif

#ifndef OUT
#  define OUT
#endif

#ifndef INOUT
#  define INOUT
#endif

#define OFFSET_OF(s, m) (u32)((u32)&(((s*)0x1000)->m) - 0x1000)

#define COUNT_OF(array) (sizeof(array) / sizeof(array[0]))

#define SIZE_OF_MEMBER(s, m) (u32)(sizeof((((s*)0x1000)->m)))

/*lint -emacro(717, ZERO_STRUCT)*/
#define ZERO_STRUCT(t) \
do \
{ \
	memset((void*)(&(t)), 0, sizeof((t))); \
} while (0)

/*lint -emacro(717, ZERO_ARRAY)*/
#define ZERO_ARRAY(a) \
do \
{ \
	memset(a, 0, sizeof((a))); \
} while (0)

/*lint -emacro(717, ZERO_BUF)*/
#define ZERO_BUF(p, wlen) \
do \
{ \
	if ((NULL != (p)) && ((wlen) !=0)) \
	{ \
	    memset((p), 0, (wlen)); \
	} \
} while (0)

/*lint -emacro(717, SAFE_FREE)*/
#define SAFE_FREE(p) \
do \
{ \
	if ((p) != NULL) \
	{ \
	    free((p)); \
	    (p) = NULL; \
	} \
} while (0)

/*lint -emacro(717, SAFE_DELETE)*/
#define SAFE_DELETE(p) \
do \
{ \
	if ((p) != NULL) \
	{ \
        delete (p); \
        (p) = NULL; \
	} \
} while (0)

/*lint -emacro(717, SAFE_DELETE_ARRAY)*/
#define SAFE_DELETE_ARRAY(p) \
do \
{ \
	if ((p) != NULL) \
	{ \
        delete [](p); \
        (p) = NULL; \
	} \
} while (0)

/**----------------------------------------------------------------------
* SAFE_STRCPY
* 
* @brief   安全复制字符串，旨在防止目标数组溢出, 
           用时要非常小心， dst只能为数组，不能为指针，否则sizeof(dst)只会拷贝4个字节
* 
* @param   [inout] dst 目标字符数组地址
* @param   [in]    src 源字符串指针
------------------------------------------------------------------------*/
/*lint -emacro(717, SAFE_STRCPY)*/
#define SAFE_STRCPY(dst, src)\
do \
{\
	strncpy(dst, src, sizeof(dst));\
	dst[sizeof(dst) - 1] = '\0';\
} while (0)

/**----------------------------------------------------------------------
* SAFE_MEMCPY
* 
* @brief   安全拷贝函数
* 
* @param   [inout] pDst 目标内存的地址
* @param   [in]    dwDstSize 目标内存的大小
* @param   [in]    pSrc 源内存的地址
* @param   [in]    dwSrcSize 源内存的大小
------------------------------------------------------------------------*/
/*lint -emacro(717, SAFE_MEMCPY)*/
#define SAFE_MEMCPY(pDst, dwDstSize, pSrc, dwSrcSize)\
do \
{\
	if (NULL== (pDst) || NULL == (pSrc) || (dwDstSize) <= 0 || (dwSrcSize) <= 0)\
	{\
        nvPrintf("SAFE_MEMCPY Invalid Param(pDst:%0x,dwDstSize:%d,pSrc:%0x,dwSrcSize:%d)(%s:(%d))!", pDst, dwDstSize, pSrc, dwSrcSize, __FILE__, __LINE__);  \
	}\
	else\
	{\
        if ((dwDstSize) < (dwSrcSize))\
		{\
            memcpy((void*)(pDst), (void*)(pSrc), (dwDstSize));\
            nvPrintf("SAFE_MEMCPY dwDstSize(%d) < dwSrcSize(%d) (%s:(%d))!", dwDstSize, dwSrcSize, __FILE__, __LINE__);\
		}\
		else\
		{\
            memcpy((void*)(pDst), (void*)(pSrc), (dwSrcSize));\
		}\
	}\
} while (0)

#define SAFE_SEM_DEL(shSem) \
{ \
	if ( shSem ) \
	{ \
	::OspSemDelete(shSem); \
	shSem = NULL; \
	} \
} \

//按李洪强建议增加关闭文件宏,参数p为FILE*类型，指向一个fopen打开的文件
/*lint -emacro(717, SAFE_CLOSE_FILE)*/
#define SAFE_CLOSE_FILE(p) \
do \
{ \
	if ((p) != NULL) \
	{ \
        fclose((p)); \
        (p) = NULL; \
	} \
} while (0)

#ifndef MIN
#define MIN(a, b) ((a) > (b) ? (b) : (a))
#endif

#ifndef MAX
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#endif

#ifndef ABS
#define ABS(x) (((x) < 0) ? -(x) : (x))
#endif

#if defined(_LINUX_)
#    define nvRegCommand(fun) OspRegCommand(#fun, (void*)fun, "")
#else
#    define nvRegCommand(fun) 
#endif // _LINUX_

/*lint -emacro(717, CHECK_POINTER)*/
#define CHECK_POINTER(p, r) \
do \
{ \
	if (NULL == (p)) \
	{ \
        return (r); \
	} \
} while (0)

/*lint -emacro(717, VOID_CHECK_POINTER)*/
#define VOID_CHECK_POINTER(p) \
do \
{ \
	if (NULL == (p)) \
	{ \
        return; \
	} \
} while (0)

/*lint -emacro(717, BOOL_CHECK_POINTER)*/
#define BOOL_CHECK_POINTER(p) \
do \
{ \
	if (NULL == (p)) \
	{ \
	    return FALSE; \
	} \
} while (0)

#define LOWORD16(l)      ((u16)(l))
#define HIWORD16(l)      ((u16)(((u32)(l) >> 16) & 0xFFFF))
#define MAKEDWORD(l, h)  ((u32)(((u16)(l)) | ((u32)((u16)(h))) << 16))

#if defined(_WIN32_P_)
#  define snprintf     _snprintf   
#  define vsnprintf    _vsnprintf
#  define strncasecmp  _strnicmp
#endif // _WIN32_P_


#define IPFORMAT      "%d.%d.%d.%d"
#define u32ToIP(ip)   (u8)(ntohl(ip)>>24), (u8)(ntohl(ip)>>16), (u8)(ntohl(ip)>>8), (u8)ntohl(ip)

//按李洪强建议增加单例宏
/*lint -emacro(717, NEW_SINGLETON_OBJ)*/
#define NEW_SINGLETON_OBJ(p, CLASS) \
do \
{ \
	if (NULL == (p)) \
	{ \
        (p) = new CLASS; \
	} \
} while (0)

//按李洪强建议增加单例宏,可变参数
/*lint -emacro(717, NEW_SINGLETON_OBJ_WITHPARAM)*/
#define NEW_SINGLETON_OBJ_WITHPARAM(p, CLASS, ...) \
do \
{ \
	if (NULL == (p)) \
	{ \
        (p) = new CLASS(__VA_ARGS__); \
	} \
} while (0)

//避免编译告警：warning C4800: 'BOOL32' : forcing value to bool 'true' or 'false' (performance warning)
#define BOOL32TOBOOL(value) ((value) != FALSE)


/**bool转BOOL32*/
#define BOOLToBOOL32(bVal) ((false==bVal)? FALSE : TRUE)

#define ADDR_ANY                INADDR_ANY

#define INFINITE            0xFFFFFFFF  // Infinite timeout

#endif // _NVMACRO_H_
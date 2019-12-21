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
* @brief   ��ȫ�����ַ�����ּ�ڷ�ֹĿ���������, 
           ��ʱҪ�ǳ�С�ģ� dstֻ��Ϊ���飬����Ϊָ�룬����sizeof(dst)ֻ�´��4���ֽ�
* 
* @param   [inout] dst Ŀ���ַ������ַ
* @param   [in]    src Դ�ַ���ָ��
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
* @brief   ��ȫ��������
* 
* @param   [inout] pDst Ŀ���ڴ�ĵ�ַ
* @param   [in]    dwDstSize Ŀ���ڴ�Ĵ�С
* @param   [in]    pSrc Դ�ڴ�ĵ�ַ
* @param   [in]    dwSrcSize Դ�ڴ�Ĵ�С
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

//�����ǿ�������ӹر��ļ���,����pΪFILE*���ͣ�ָ��һ��fopen�򿪵��ļ�
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

//�����ǿ�������ӵ�����
/*lint -emacro(717, NEW_SINGLETON_OBJ)*/
#define NEW_SINGLETON_OBJ(p, CLASS) \
do \
{ \
	if (NULL == (p)) \
	{ \
        (p) = new CLASS; \
	} \
} while (0)

//�����ǿ�������ӵ�����,�ɱ����
/*lint -emacro(717, NEW_SINGLETON_OBJ_WITHPARAM)*/
#define NEW_SINGLETON_OBJ_WITHPARAM(p, CLASS, ...) \
do \
{ \
	if (NULL == (p)) \
	{ \
        (p) = new CLASS(__VA_ARGS__); \
	} \
} while (0)

//�������澯��warning C4800: 'BOOL32' : forcing value to bool 'true' or 'false' (performance warning)
#define BOOL32TOBOOL(value) ((value) != FALSE)


/**boolתBOOL32*/
#define BOOLToBOOL32(bVal) ((false==bVal)? FALSE : TRUE)

#define ADDR_ANY                INADDR_ANY

#define INFINITE            0xFFFFFFFF  // Infinite timeout

#endif // _NVMACRO_H_
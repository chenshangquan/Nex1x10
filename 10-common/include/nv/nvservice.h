#if !defined(_NVSERVICE_H_)
#define _NVSERVICE_H_

#include "kdvtype.h"
#include "nvstruct.h"



#ifdef __cplusplus
extern "C" {
#endif

//回调函数
/**----------------------------------------------------------------------
	* ExternHandler
	* 
	* @brief    外部处理消息的回调函数
	* 
	* @param	[in] pcNvMsg 订阅消息的具体消息
	* @param	[in] dwSrcId 订阅消息的appinstid
	* @param	[in] dwSrcNode 订阅消息的nodeid
	* @return	BOOL32 TRUE:已经处理了，不需要继续由其它处理这个消息， FALSE:需要由其它处理这个消息
	------------------------------------------------------------------------*/
NVCBB_API typedef BOOL32 (ExternHandler)(nvmsg::CNvMsg *pcNvMsg, u32 dwSrcId, u32 dwSrcNode);

/**----------------------------------------------------------------------
	* RegisterExternHandler
	* 
	* @brief    注册外部消息处理的回调函数
	* 
	* @param	[in] pcNvMsg 订阅消息的具体消息
	* @param	[in] dwSrcId 订阅消息的appinstid
	* @param	[in] dwSrcNode 订阅消息的nodeid
	* @return	void
	------------------------------------------------------------------------*/
NVCBB_API void RegisterExternHandler( ExternHandler *pfHandle );


NVCBB_API BOOL32 NvServiceStart(TMdlStartParam &tMdlStartParam);

NVCBB_API BOOL32 NvServiceStop();


#ifdef __cplusplus
}
#endif

#endif // _NVSERVICE_H_
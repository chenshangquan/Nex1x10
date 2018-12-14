#ifndef _NV_CBBCOMMON_H_ 
#define _NV_CBBCOMMON_H_
#include "nvstruct.pb.h"
#include "nvdskey.h"
#include "kdvtype.h"
#include "nvmacro.h"
#include "nvenum.pb.h"
#include "nvconst.h"

/*---------------------------------------------------------------------------*/
/**
 * @brief 初始化默认配置
 *
 * @param	[in] 无
 *
 * @return	无
 * @note    
 */
/*---------------------------------------------------------------------------*/
NVCBB_API void nvInitDefaultCfg();

/*---------------------------------------------------------------------------*/
/**
 * @brief 根据key获取对应的默认配置值
 *
 * @param	[in] emKey  配置key
 * @param	[in] pvData ProtocolBuffer类对象	
 *
 * @return	TRUE: 成功  FALSE:失败
 */
/*---------------------------------------------------------------------------*/
NVCBB_API BOOL32 nvGetDefaultCfg(std::string strKey, google::protobuf::Message *pvData);

/*---------------------------------------------------------------------------*/
/**
 * @brief 根据key获取对应的默认配置值
 *
 * @param	[in] emKey  配置key
 * @param	[in] pvData ProtocolBuffer类对象	
 *
 * @return	TRUE: 成功  FALSE:失败
 * @note   pvData传入NULL 内部会动态分配key所对应的ProtocolBuffer类对象并写入默认值
 */
/*---------------------------------------------------------------------------*/
NVCBB_API BOOL32 nvGetDefaultCfg(std::string strKey, google::protobuf::Message **pvData);

/*---------------------------------------------------------------------------*/
/**
*
* @brief   获取数据路径
* @param   [in]  emPathType    要获取路径的类型
* @param   [out] pchOutBuf     得到的路径
* @param   [in]  dwBufSize     缓冲区长度
*
* @return  TRUE:成功 
           FALSE: 失败
*/
/*---------------------------------------------------------------------------*/
NVCBB_API BOOL32 nvGetDirPath(nv::EmNvPathType emPathType, s8 *pchOutBuf, u32 dwBufSize);

/*---------------------------------------------------------------------------*/
/**
* @brief   获取数据文件路径
* @param   [in]  emPathType    要获取的文件的类型
* @param   [out] pchOutBuf     得到的路径
* @param   [in]  dwBufSize     缓冲区长度
*
* @return  TRUE:成功 
           FALSE: 失败
*/
/*---------------------------------------------------------------------------*/
NVCBB_API BOOL32 nvGetFilePath(nv::EmNvFile emFileType, s8 *pchOutBuf, u32 dwBufSize);

/**----------------------------------------------------------------------
	* InstallSystemPath
	* 
	* @brief    系统时调用，预先创建好需要的目录
	* 
	* @param	
	* @return	BOOL32 TRUE:成功处理， FALSE:处理失败
	------------------------------------------------------------------------*/
NVCBB_API BOOL32 InstallSystemPath();

/*---------------------------------------------------------------------------*/
/**
* @brief   设置系统路径前缀
* @param   [in]  pszPathPrefix    路径前缀，utf8编码
*
* @return  无
*/
/*---------------------------------------------------------------------------*/
NVCBB_API void nvSetSysWorkPathPrefix(const s8* pszPathPrefix);

/*---------------------------------------------------------------------------*/
/**
* @brief   获取系统路径前缀
* @param   [in]  pchOutBuf    路径前缀，utf8编码
*
* @return  无
*/
/*---------------------------------------------------------------------------*/
NVCBB_API BOOL32 nvGetSysWorkPathPrefix(s8 *pchOutBuf, u32 dwBufSize);

/**----------------------------------------------------------------------
	* NvStrToMsgSession
	* 
	* @brief    str的格式是dwAppInstID*dwNodeID；u32转化成字符串最多十个字符进行表示，所以字符串大小最大为10+1+10=21
	* 
	* @param	[in] str 要转换的str字符串
	* @param	[out] dwNodeID str要解析出来的nodeid
	* @param	[out] dwInstAppID 要解析出来的instappid
	* @return	BOOL32 TRUE:成功处理， FALSE:处理失败
	------------------------------------------------------------------------*/
NVCBB_API BOOL32 NvStrToMsgSession( const std::string &str, u32 &dwNodeID, u32 &dwInstAppID );

/**----------------------------------------------------------------------
	* NvMsgSessionToStr
	* 
	* @brief    把appinstid以及nodeid转换成str的格式是dwAppInstID*dwNodeID；u32转化成字符串最多十个字符进行表示，所以字符串大小最大为10+1+10=21
	* 
	* @param	[in] dwNodeID 要合成str的nodeid部分
	* @param	[in] dwInstAppID 要合成str的instappid部分
	* @param	[out] str 要转换成str的字符串结果
	* @return	BOOL32 TRUE:成功处理， FALSE:处理失败
	------------------------------------------------------------------------*/
NVCBB_API BOOL32 NvMsgSessionToStr( u32 dwNodeID, u32 dwInstAppID, std::string &str );

typedef void (*NV_PAUDIOPCMCALLBACK)(u8 *pBuf, s32 nSize, u32 dwSampleRate, u32 dwBitWidth, u32 dwChannel, u32 dwContext);

typedef void (*NV_PVIDEOI420CALLBACK)(u8* pData, s32 nData, s16 nWidth, s16 nHeight, u32 dwContext);


/*!**********************************************************
* 
* @brief   设置视频解码器帧回调函数
* @param   [in]  pAudioCallBack:   回调函数指针
* @return   
*         
*************************************************************/
NVCBB_API void nvSetAudioDecPCMCallBack(const NV_PAUDIOPCMCALLBACK  pAudioCallBack);

/*!**********************************************************
* 
* @brief   获取视频解码器帧回调函数
* @param  
* @return    ： 回调函数指针
*         
*************************************************************/
NVCBB_API NV_PAUDIOPCMCALLBACK nvGetAudioDecPCMCallBack();

/*!**********************************************************
* 
* @brief   设置音频解码器帧回调函数
* @param   [in]  pVideoI420CallBack:   回调函数指针
* @return   
*         
*************************************************************/
NVCBB_API void nvSetVideoDecI420CallBack(const NV_PVIDEOI420CALLBACK  pVideoI420CallBack);


/*!**********************************************************
* 
* @brief   获取音频解码器帧回调函数
* @param   
* @return   ： 回调函数指针
*         
*************************************************************/
NVCBB_API NV_PVIDEOI420CALLBACK nvGetVideoDecI420CallBack();

NVCBB_API void nvMakeHandleString( const s8 *pchModuleInfo, u32 dwHandle1, u32 dwHandle2, std::string &strOutString );

#endif //_NV_DEFAULTCONFIG_H_
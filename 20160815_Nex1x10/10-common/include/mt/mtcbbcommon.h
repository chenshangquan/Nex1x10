#ifndef _MT_CBBCOMMON_H_ 
#define _MT_CBBCOMMON_H_
#include "struct.pb.h"
#include "mtdskey.h"
#include "kdvtype.h"
#include "mtmacro.h"
#include "enum.pb.h"
#include "mtconst.h"

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
MTCBB_API void mtInitDefaultCfg();

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
MTCBB_API BOOL32 mtGetDefaultCfg(std::string strKey, google::protobuf::Message *pvData);

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
MTCBB_API BOOL32 mtGetDefaultCfg(std::string strKey, google::protobuf::Message **pvData);

/*---------------------------------------------------------------------------*/
/**
 * @brief 判断当前终端是不是手机终端
 *
 * @param	
 * @param		
 *
 * @return	TRUE: 是手机终端  FALSE:不是
 * @note   
 */
/*---------------------------------------------------------------------------*/
MTCBB_API BOOL32 IsCusModelPhoneMt();

/*---------------------------------------------------------------------------*/
/**
 * @brief 判断当前终端是不是商密终端（软终端使用）
 *
 * @param	
 * @param		
 *
 * @return	TRUE: 是  FALSE:不是
 * @note   
 */
/*---------------------------------------------------------------------------*/
MTCBB_API BOOL32 IsBusiSecSoftMt();

// 是否商密硬终端
MTCBB_API BOOL32 IsBusiSecHardMt();


MTCBB_API const s8* GetModelName(mt::EmMtModel emModel);

/*!**********************************************************
*
* @brief   获取终端型号
* @param   [in]  void
*
* @return  返回当前终端型号
*          
*************************************************************/
MTCBB_API mt::EmMtModel GetMtModel();

/*!**********************************************************
*
* @brief   获取是否给网呈使用的终端
* @param   [in]  void
*
* @return  返回是否给网呈使用的终端
*          
*************************************************************/
MTCBB_API BOOL32 GetIsIMIXTerl();

/*!**********************************************************
*
* @brief   判断当前型号是否是自建的
* @param   [in]  void
*
* @return  返回当前终端型号
*          
*************************************************************/
MTCBB_API BOOL32 IsCusModelSelfBuild();

/*!**********************************************************
*
* @brief   根据型号获取productid， versionid
* @param   [out]  strProduct, strVersionId
*
* @return  返回当前终端型号
*          
*************************************************************/
MTCBB_API void GetProductIdAndVersionId(std::string &strProduct, std::string &strVersionId);

/*!**********************************************************
*
* @brief   根据型号获取主流最大路数， 辅流最大路数
* @param   [out]  dwMaxMainNum, dwMaxAssNum
*
* @return  返回当前终端主流最大路数， 辅流最大路数
*          
*************************************************************/
MTCBB_API void GetMainVideoNumAndAssVideoNum(u32 &dwMaxMainNum, u32 &dwMaxAssNum);

/*!**********************************************************
*
* @brief   走老的代理，需要兼容老的gk, 根据型号获取productid， versionid
* @param   [out]  strProduct, strVersionId
*
* @return  返回当前终端型号
*          
*************************************************************/
MTCBB_API void GetPxyProductIdAndVersionId(std::string &strProduct, std::string &strVersionId);


/*!**********************************************************
*
* @brief   根据对端的productid获取当前的型号，外厂商，或者老的不兼容的型号都是emModelBegin
* @param   [in]  pchProduct 
* 
* @return  返回型号
*          
*************************************************************/
MTCBB_API mt::EmMtModel GetModelFromProductid( const s8* pchProduct );

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
MTCBB_API BOOL32 mtGetDirPath(mt::EmMtPathType emPathType, s8 *pchOutBuf, u32 dwBufSize);

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
MTCBB_API BOOL32 mtGetFilePath(mt::EmMtFile emFileType, s8 *pchOutBuf, u32 dwBufSize);

/**----------------------------------------------------------------------
	* InstallSystemPath
	* 
	* @brief    系统时调用，预先创建好需要的目录
	* 
	* @param	
	* @return	BOOL32 TRUE:成功处理， FALSE:处理失败
	------------------------------------------------------------------------*/
MTCBB_API BOOL32 InstallSystemPath();

/*---------------------------------------------------------------------------*/
/**
* @brief   设置系统路径前缀
* @param   [in]  pszPathPrefix    路径前缀，utf8编码
*
* @return  无
*/
/*---------------------------------------------------------------------------*/
MTCBB_API void mtSetSysWorkPathPrefix(const s8* pszPathPrefix);

/*---------------------------------------------------------------------------*/
/**
* @brief   获取系统路径前缀
* @param   [in]  pchOutBuf    路径前缀，utf8编码
*
* @return  无
*/
/*---------------------------------------------------------------------------*/
MTCBB_API BOOL32 mtGetSysWorkPathPrefix(s8 *pchOutBuf, u32 dwBufSize);
/*!**********************************************************
*
* @brief   提供给mc/conf/pa的句柄合成为字符串的接口
* @param   [in] pcModuleInfo 模块信息
* @param   [in] dwHandle1 句柄1
* @param   [in] dwHandle2 句柄2
* @param   [in] strOutString  构造的句柄 (如： mc-123-567)
* @return  TRUE:成功  FALSE:失败
*************************************************************/
MTCBB_API BOOL32 mtMakeHandleString(const s8 *pchModuleInfo, u32 dwHandle1, u32 dwHandle2, std::string &strOutString);

/*!**********************************************************
*
* @brief   提供给mc/conf/pa的根据mtMakeHandleString得到的字符串解析句柄
* @param   [in] strHandleString: 要解析的信息
* @param   [in] pchModuleInfoBuf: 模块信息
* @param   [out] wHighWord: 得到的句柄1
* @param   [out] wLowWord:  得到的句柄2
* @return  TRUE:    strHandleString中包含字符串pchModuleInfoBuf
           FALSE:   strHandleString中不包含字符串pchModuleInfoBuf
*************************************************************/
MTCBB_API BOOL32 mtGetHandleFromString(std::string strHandleString, const s8 *pchModuleInfo, u32 &dwHighWord, u32 &dwLowWord);

/**----------------------------------------------------------------------
	* MtStrToMsgSession
	* 
	* @brief    str的格式是dwAppInstID*dwNodeID；u32转化成字符串最多十个字符进行表示，所以字符串大小最大为10+1+10=21
	* 
	* @param	[in] str 要转换的str字符串
	* @param	[out] dwNodeID str要解析出来的nodeid
	* @param	[out] dwInstAppID 要解析出来的instappid
	* @return	BOOL32 TRUE:成功处理， FALSE:处理失败
	------------------------------------------------------------------------*/
MTCBB_API BOOL32 MtStrToMsgSession( const std::string &str, u32 &dwNodeID, u32 &dwInstAppID );

/**----------------------------------------------------------------------
	* MtMsgSessionToStr
	* 
	* @brief    把appinstid以及nodeid转换成str的格式是dwAppInstID*dwNodeID；u32转化成字符串最多十个字符进行表示，所以字符串大小最大为10+1+10=21
	* 
	* @param	[in] dwNodeID 要合成str的nodeid部分
	* @param	[in] dwInstAppID 要合成str的instappid部分
	* @param	[out] str 要转换成str的字符串结果
	* @return	BOOL32 TRUE:成功处理， FALSE:处理失败
	------------------------------------------------------------------------*/
MTCBB_API BOOL32 MtMsgSessionToStr( u32 dwNodeID, u32 dwInstAppID, std::string &str );

/*---------------------------------------------------------------------------*/
/**mtGetAddrType
*
* @brief   判断地址类型
* @param   [in]  pchAddr   地址字符串
* @param   [in]  dwLen     pchAddr的长度
*
* @return  地址类型
*/
/*---------------------------------------------------------------------------*/
MTCBB_API mt::EmMtAddrType mtGetAddrType(const s8 *pchAddr, u32 dwLen);

/*!**********************************************************
* 
* @brief   根据视频分辨率得到宽高
* @param   [in] emRes:     视频分辨率
* @param   [out] dwWidth:  得到宽度
* @param   [out] dwHeight: 得到高度
* @return  MT_SUCCESS: 成功
*          MT_FAILED: 失败
*************************************************************/
MTCBB_API u32 mtGetVideoWidthHeight(mt::EmMtResolution emRes, u32 &dwWidth, u32 &dwHeight);

/*!**********************************************************
* 
* @brief   根据视频分辨率得到宽高
* @param   [in] emRes:     视频分辨率
* @param   [in] dwLen:     缓冲区大小
* @param   [out] 宽高字符串 如1280*720
* @return  MT_SUCCESS: 成功
*          MT_FAILED: 失败
*************************************************************/
MTCBB_API u32 mtGetVideoWidthHeight(mt::EmMtResolution emRes, s8 *pchStrOut, u32 dwLen);

/*!**********************************************************
* 
* @brief   根据宽高得到分辨率
* @param   [in]  dwWidth:  宽度
* @param   [in]  dwHeight: 高度
* @param   [out] emRes:    得到的视频分辨率
* @return  MT_SUCCESS: 成功
*          MT_FAILED: 失败
*************************************************************/
MTCBB_API u32 mtGetVideoRes(u32 dwWidth, u32 dwHeight, mt::EmMtResolution &emRes);

/*!**********************************************************
* 
* @brief   根据音频格式获取其码率
* @param   [in]  emAudioFormat:		音频格式
* @param   [out] wAudioBitrate:		得到的音频码率
* @return  MT_SUCCESS: 成功
*          MT_FAILED:  失败
*************************************************************/
MTCBB_API u32 mtGetAudioBitrate(mt::EmAudFormat emAudioFormat, u16 &wAudioBitrate);

/*!**********************************************************
* 
* @brief   根据音频格式获取其载荷类型
* @param   [in]  emAudFormat:		音频格式
*
* @return  成功:对应的载荷类型
*          失败:MEDIA_TYPE_NULL
*************************************************************/
MTCBB_API u8 mtGetAudioPayloadByFormat( mt::EmAudFormat emAudFormat );

/*!**********************************************************
* 
* @brief   根据视频格式获取其载荷类型
* @param   [in]  emFormat:		视频格式
*
* @return  成功:对应的载荷类型
*          失败:MEDIA_TYPE_NULL
*************************************************************/
MTCBB_API u8 mtGetVedioPayloadByFormat( mt::EmVidFormat emFormat );

/*!**********************************************************
* 
* @brief   根据载荷类型获取音频格式
* @param   [in]  byMediaType:		载荷类型
*
* @return  成功:对应的音频格式
*          失败:emAudEnd
*************************************************************/
MTCBB_API mt::EmAudFormat mtGetAudFormatByPayload( u8 byMediaType );

/*!**********************************************************
* 
* @brief   根据载荷类型获取视频格式
* @param   [in]  byMediaType:		载荷类型
*
* @return  成功:对应的视频格式
*          失败:emVEnd
*************************************************************/
MTCBB_API mt::EmVidFormat mtGetVedioFormatByPayload( u8 byPayload );

/*!**********************************************************
* 
* @brief   根据视频格式得到vccommon中视频格式定义
* @param   [in]  emVidResd:		视频格式
*
* @return  成功:对应的视频格式
*          失败:VIDEO_FORMAT_INVALID
*************************************************************/
MTCBB_API u8 mtMapMtToVcComVidRes( mt::EmMtResolution emVidResd );

/*!**********************************************************
* 
* @brief   根据vccommon中视频格式定义得到终端视频格式
* @param   [in]  byRes:		vccommon中视频格式
*
* @return  成功:对应的视频格式
*          失败:emMtVResEnd
*************************************************************/
MTCBB_API mt::EmMtResolution mtMapVcComToMtVideoRes(u8 byRes);

/*!**********************************************************
* 
* @brief   根据  摄像头操作定义的方向得到协议栈操作的ptfz方向枚举
* @param   [in]  emDirection:		摄像头操作定义的方向
*
* @return  成功:对应的视频格式
*          失败:emMtVResEnd
*************************************************************/
MTCBB_API mt::EmFeccPTFZRequest mtGetFeccPTFZFromMtDirection( mt::EmDirection emDirection );

/*!**********************************************************
* 
* @brief   根据  协议栈操作的ptfz方向枚举得到摄像头操作定义的方向
* @param   [in]  emPTFZ:		协议栈操作的ptfz方向枚举
*
* @return  成功:对应的视频格式
*          失败:emMtVResEnd
*************************************************************/
MTCBB_API mt::EmDirection  mtGetMtDirectionFromPTFZ( mt::EmFeccPTFZRequest emPTFZ );


/*!**********************************************************
* 
* @brief   根据  通道的type 获取code的type
* @param   [in]  emChanType:		通道的type
* @note    转换只针对音视频的转换，fecc, 音视频混音器不处理
* @return  成功: 对应的code的type
*          失败:emMtVResEnd
*************************************************************/
MTCBB_API mt::EmCodecComponent mtGetCodecTypeFromChan( mt::EmMtChanType emChanType );

/*!**********************************************************
* 
* @brief   根据  codec的type 获取通道的type
* @param   [in]  emChanType:		通道的type
*
* @return  成功: 对应的code的type
*          失败:emChanTypeEnd
*************************************************************/
MTCBB_API mt::EmMtChanType     mtGetChanTypeFromCodec( mt::EmCodecComponent emCodecType );

/*!**********************************************************
* 
* @brief   根据  内部的vidsrc的枚举获取远摇用到的 index
* @param   [in]  emPort:  内部枚举
*
* @return  成功: 远摇用到的 index
*          失败: INVALID_U32
*************************************************************/
MTCBB_API u32  mtGetFarCtrIdxFromInnerVidSrc( mt::EmMtVideoPort emPort,mt::EmCodecComponent emCodecType, mt::EmCodecComponentIndex emIdx );

/*!**********************************************************
* 
* @brief   根据  远摇用到的 index获取内部的枚举
* @param   [in]  emPort:  内部枚举
*
* @return  成功: 远摇用到的 index
*          失败: mt::emMtVidInvalid
*************************************************************/
MTCBB_API mt::EmMtVideoPort mtGetInnerVidSrcFromFarCtrlIdx( u32 dwIdx, mt::EmCodecComponent emCodecType, mt::EmCodecComponentIndex emIdx);

/*!**********************************************************
* 
* @brief   根据  code类型和索引获取 某一路 终端内部视频源与远遥id的对应关系列表
* @param   [in]  emType:  codec 类型
*          [in]  emIdx:   索引
           
		   [out] 某一路的对应关系
* @return  成功: TRUE 
*          失败: FALSE
*************************************************************/
MTCBB_API BOOL32 mtGetFarCtrlIdGroupBaseCodeTypeAndId( mt::TMTVidSrc2FarCtrlIdGroup &tGroup, mt::EmCodecComponent emType, mt::EmCodecComponentIndex emIdx );

/*!**********************************************************
* 
* @brief   根据是windows还是嵌入式获取当前的帧率，只针对264， 265
* @param   [in]  emChanType:   通道类型
           [in]  emLabel:      双流类型
		   
* @return  最大帧率 
*         
*************************************************************/
MTCBB_API u32 mtGetMaxFpsBasePlatForm( mt::EmMtChanType emChanType, mt::EmMtVidLabel emLabel );


/*!**********************************************************
* 
* @brief   根据chan 通道类型获取port string类型
* @param   [in]  emChanType:   通道类型
           [in]  emLabel:      双流类型
		   
* @return  最大帧率 
*         
*************************************************************/
MTCBB_API u32  mtGetPortStringFromChanType( mt::EmMtChanType emChanType, std::string &strPort);


/*!**********************************************************
* 
* @brief   根据versionid值判断,对端是不是5.0终端
* @param   [in]  emChanType:   通道类型
           [in]  emLabel:      双流类型
		   
* @return  最大帧率 
*         
*************************************************************/
MTCBB_API BOOL32  JudgeMtb5p0BaseVersionId( s8 *pchVersionId );


/*!**********************************************************
* 
* @brief   根据versionid值判断,对端是不是5.0平台
* @param   [in]  emChanType:   通道类型
           [in]  emLabel:      双流类型
		   
* @return  最大帧率 
*         
*************************************************************/
MTCBB_API BOOL32  JudgeMcub5p0BaseVersionId( s8 *pchVersionId ); 

/*!**********************************************************
* 
* @brief   从wBeginPort 到 wEndPort中找可用的323监听端口
* @param   [in]  emChanType:   通道类型
           [in]  emLabel:      双流类型
		   
* @return  最大帧率 
*         
*************************************************************/
MTCBB_API u16    MtGetH323CallingPortFromRange( u16 wBeginPort, u16 wEndPort ) ;



typedef void (*MT_PAUDIOPCMCALLBACK)(u8 *pBuf, s32 nSize, u32 dwSampleRate, u32 dwBitWidth, u32 dwChannel, u32 dwContext);

typedef void (*MT_PVIDEOI420CALLBACK)(u8* pData, s32 nData, s16 nWidth, s16 nHeight, u32 dwContext);


/*!**********************************************************
* 
* @brief   设置视频解码器帧回调函数
* @param   [in]  pAudioCallBack:   回调函数指针
* @return   
*         
*************************************************************/
MTCBB_API void mtSetAudioDecPCMCallBack(const MT_PAUDIOPCMCALLBACK  pAudioCallBack);

/*!**********************************************************
* 
* @brief   获取视频解码器帧回调函数
* @param  
* @return    ： 回调函数指针
*         
*************************************************************/
MTCBB_API MT_PAUDIOPCMCALLBACK mtGetAudioDecPCMCallBack();

/*!**********************************************************
* 
* @brief   设置音频解码器帧回调函数
* @param   [in]  pVideoI420CallBack:   回调函数指针
* @return   
*         
*************************************************************/
MTCBB_API void mtSetVideoDecI420CallBack(const MT_PVIDEOI420CALLBACK  pVideoI420CallBack);


/*!**********************************************************
* 
* @brief   获取音频解码器帧回调函数
* @param   
* @return   ： 回调函数指针
*         
*************************************************************/
MTCBB_API MT_PVIDEOI420CALLBACK mtGetVideoDecI420CallBack();

/*---------------------------------------------------------------------------*/
/**
* @brief   获取文件路径中的文件名
* @param   [in]  pchFilePath     文件路径，包括 文件路径前缀+文件名
* @param   [in]  dwPathLen       文件路径长度
* @param   [out] pchOutFileName  文件名
*
* @return  TRUE:成功 
           FALSE: 失败
*/
/*---------------------------------------------------------------------------*/
MTCBB_API BOOL32 mtGetFileName(const s8 *pchFilePath, u32 dwPathLen, s8 *pchOutFileName);

/*---------------------------------------------------------------------------*/
/**
* @brief   获取文件路径中的路径前缀
* @param   [in]  pchFilePath       文件路径，包括 文件路径前缀+文件名
* @param   [in]  dwPathLen         文件路径长度
* @param   [out] pchOutPathPrefix  文件路径前缀
*
* @return  TRUE:成功 
           FALSE: 失败
*/
/*---------------------------------------------------------------------------*/
MTCBB_API BOOL32 mtGetFilePathPrefix(const s8 *pchFilePath, u32 dwPathLen, s8 *pchOutPathPrefix);

/*---------------------------------------------------------------------------*/
/**
* @brief 是否要发送渠道产品非标信令的终端  
*
* @param	
* @param		
*
* @return	TRUE: 是  FALSE:否
* @note   
*/
/*---------------------------------------------------------------------------*/
MTCBB_API BOOL32 IsSendAgentInfoMt();


MTCBB_API BOOL32 IsSky100Mt();

#endif //_MT_DEFAULTCONFIG_H_
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
 * @brief ��ʼ��Ĭ������
 *
 * @param	[in] ��
 *
 * @return	��
 * @note    
 */
/*---------------------------------------------------------------------------*/
MTCBB_API void mtInitDefaultCfg();

/*---------------------------------------------------------------------------*/
/**
 * @brief ����key��ȡ��Ӧ��Ĭ������ֵ
 *
 * @param	[in] emKey  ����key
 * @param	[in] pvData ProtocolBuffer�����	
 *
 * @return	TRUE: �ɹ�  FALSE:ʧ��
 */
/*---------------------------------------------------------------------------*/
MTCBB_API BOOL32 mtGetDefaultCfg(std::string strKey, google::protobuf::Message *pvData);

/*---------------------------------------------------------------------------*/
/**
 * @brief ����key��ȡ��Ӧ��Ĭ������ֵ
 *
 * @param	[in] emKey  ����key
 * @param	[in] pvData ProtocolBuffer�����	
 *
 * @return	TRUE: �ɹ�  FALSE:ʧ��
 * @note   pvData����NULL �ڲ��ᶯ̬����key����Ӧ��ProtocolBuffer�����д��Ĭ��ֵ
 */
/*---------------------------------------------------------------------------*/
MTCBB_API BOOL32 mtGetDefaultCfg(std::string strKey, google::protobuf::Message **pvData);

/*---------------------------------------------------------------------------*/
/**
 * @brief �жϵ�ǰ�ն��ǲ����ֻ��ն�
 *
 * @param	
 * @param		
 *
 * @return	TRUE: ���ֻ��ն�  FALSE:����
 * @note   
 */
/*---------------------------------------------------------------------------*/
MTCBB_API BOOL32 IsCusModelPhoneMt();

/*---------------------------------------------------------------------------*/
/**
 * @brief �жϵ�ǰ�ն��ǲ��������նˣ����ն�ʹ�ã�
 *
 * @param	
 * @param		
 *
 * @return	TRUE: ��  FALSE:����
 * @note   
 */
/*---------------------------------------------------------------------------*/
MTCBB_API BOOL32 IsBusiSecSoftMt();

// �Ƿ�����Ӳ�ն�
MTCBB_API BOOL32 IsBusiSecHardMt();


MTCBB_API const s8* GetModelName(mt::EmMtModel emModel);

/*!**********************************************************
*
* @brief   ��ȡ�ն��ͺ�
* @param   [in]  void
*
* @return  ���ص�ǰ�ն��ͺ�
*          
*************************************************************/
MTCBB_API mt::EmMtModel GetMtModel();

/*!**********************************************************
*
* @brief   ��ȡ�Ƿ������ʹ�õ��ն�
* @param   [in]  void
*
* @return  �����Ƿ������ʹ�õ��ն�
*          
*************************************************************/
MTCBB_API BOOL32 GetIsIMIXTerl();

/*!**********************************************************
*
* @brief   �жϵ�ǰ�ͺ��Ƿ����Խ���
* @param   [in]  void
*
* @return  ���ص�ǰ�ն��ͺ�
*          
*************************************************************/
MTCBB_API BOOL32 IsCusModelSelfBuild();

/*!**********************************************************
*
* @brief   �����ͺŻ�ȡproductid�� versionid
* @param   [out]  strProduct, strVersionId
*
* @return  ���ص�ǰ�ն��ͺ�
*          
*************************************************************/
MTCBB_API void GetProductIdAndVersionId(std::string &strProduct, std::string &strVersionId);

/*!**********************************************************
*
* @brief   �����ͺŻ�ȡ�������·���� �������·��
* @param   [out]  dwMaxMainNum, dwMaxAssNum
*
* @return  ���ص�ǰ�ն��������·���� �������·��
*          
*************************************************************/
MTCBB_API void GetMainVideoNumAndAssVideoNum(u32 &dwMaxMainNum, u32 &dwMaxAssNum);

/*!**********************************************************
*
* @brief   ���ϵĴ�����Ҫ�����ϵ�gk, �����ͺŻ�ȡproductid�� versionid
* @param   [out]  strProduct, strVersionId
*
* @return  ���ص�ǰ�ն��ͺ�
*          
*************************************************************/
MTCBB_API void GetPxyProductIdAndVersionId(std::string &strProduct, std::string &strVersionId);


/*!**********************************************************
*
* @brief   ���ݶԶ˵�productid��ȡ��ǰ���ͺţ��⳧�̣������ϵĲ����ݵ��ͺŶ���emModelBegin
* @param   [in]  pchProduct 
* 
* @return  �����ͺ�
*          
*************************************************************/
MTCBB_API mt::EmMtModel GetModelFromProductid( const s8* pchProduct );

/*---------------------------------------------------------------------------*/
/**
*
* @brief   ��ȡ����·��
* @param   [in]  emPathType    Ҫ��ȡ·��������
* @param   [out] pchOutBuf     �õ���·��
* @param   [in]  dwBufSize     ����������
*
* @return  TRUE:�ɹ� 
           FALSE: ʧ��
*/
/*---------------------------------------------------------------------------*/
MTCBB_API BOOL32 mtGetDirPath(mt::EmMtPathType emPathType, s8 *pchOutBuf, u32 dwBufSize);

/*---------------------------------------------------------------------------*/
/**
* @brief   ��ȡ�����ļ�·��
* @param   [in]  emPathType    Ҫ��ȡ���ļ�������
* @param   [out] pchOutBuf     �õ���·��
* @param   [in]  dwBufSize     ����������
*
* @return  TRUE:�ɹ� 
           FALSE: ʧ��
*/
/*---------------------------------------------------------------------------*/
MTCBB_API BOOL32 mtGetFilePath(mt::EmMtFile emFileType, s8 *pchOutBuf, u32 dwBufSize);

/**----------------------------------------------------------------------
	* InstallSystemPath
	* 
	* @brief    ϵͳʱ���ã�Ԥ�ȴ�������Ҫ��Ŀ¼
	* 
	* @param	
	* @return	BOOL32 TRUE:�ɹ����� FALSE:����ʧ��
	------------------------------------------------------------------------*/
MTCBB_API BOOL32 InstallSystemPath();

/*---------------------------------------------------------------------------*/
/**
* @brief   ����ϵͳ·��ǰ׺
* @param   [in]  pszPathPrefix    ·��ǰ׺��utf8����
*
* @return  ��
*/
/*---------------------------------------------------------------------------*/
MTCBB_API void mtSetSysWorkPathPrefix(const s8* pszPathPrefix);

/*---------------------------------------------------------------------------*/
/**
* @brief   ��ȡϵͳ·��ǰ׺
* @param   [in]  pchOutBuf    ·��ǰ׺��utf8����
*
* @return  ��
*/
/*---------------------------------------------------------------------------*/
MTCBB_API BOOL32 mtGetSysWorkPathPrefix(s8 *pchOutBuf, u32 dwBufSize);
/*!**********************************************************
*
* @brief   �ṩ��mc/conf/pa�ľ���ϳ�Ϊ�ַ����Ľӿ�
* @param   [in] pcModuleInfo ģ����Ϣ
* @param   [in] dwHandle1 ���1
* @param   [in] dwHandle2 ���2
* @param   [in] strOutString  ����ľ�� (�磺 mc-123-567)
* @return  TRUE:�ɹ�  FALSE:ʧ��
*************************************************************/
MTCBB_API BOOL32 mtMakeHandleString(const s8 *pchModuleInfo, u32 dwHandle1, u32 dwHandle2, std::string &strOutString);

/*!**********************************************************
*
* @brief   �ṩ��mc/conf/pa�ĸ���mtMakeHandleString�õ����ַ����������
* @param   [in] strHandleString: Ҫ��������Ϣ
* @param   [in] pchModuleInfoBuf: ģ����Ϣ
* @param   [out] wHighWord: �õ��ľ��1
* @param   [out] wLowWord:  �õ��ľ��2
* @return  TRUE:    strHandleString�а����ַ���pchModuleInfoBuf
           FALSE:   strHandleString�в������ַ���pchModuleInfoBuf
*************************************************************/
MTCBB_API BOOL32 mtGetHandleFromString(std::string strHandleString, const s8 *pchModuleInfo, u32 &dwHighWord, u32 &dwLowWord);

/**----------------------------------------------------------------------
	* MtStrToMsgSession
	* 
	* @brief    str�ĸ�ʽ��dwAppInstID*dwNodeID��u32ת�����ַ������ʮ���ַ����б�ʾ�������ַ�����С���Ϊ10+1+10=21
	* 
	* @param	[in] str Ҫת����str�ַ���
	* @param	[out] dwNodeID strҪ����������nodeid
	* @param	[out] dwInstAppID Ҫ����������instappid
	* @return	BOOL32 TRUE:�ɹ����� FALSE:����ʧ��
	------------------------------------------------------------------------*/
MTCBB_API BOOL32 MtStrToMsgSession( const std::string &str, u32 &dwNodeID, u32 &dwInstAppID );

/**----------------------------------------------------------------------
	* MtMsgSessionToStr
	* 
	* @brief    ��appinstid�Լ�nodeidת����str�ĸ�ʽ��dwAppInstID*dwNodeID��u32ת�����ַ������ʮ���ַ����б�ʾ�������ַ�����С���Ϊ10+1+10=21
	* 
	* @param	[in] dwNodeID Ҫ�ϳ�str��nodeid����
	* @param	[in] dwInstAppID Ҫ�ϳ�str��instappid����
	* @param	[out] str Ҫת����str���ַ������
	* @return	BOOL32 TRUE:�ɹ����� FALSE:����ʧ��
	------------------------------------------------------------------------*/
MTCBB_API BOOL32 MtMsgSessionToStr( u32 dwNodeID, u32 dwInstAppID, std::string &str );

/*---------------------------------------------------------------------------*/
/**mtGetAddrType
*
* @brief   �жϵ�ַ����
* @param   [in]  pchAddr   ��ַ�ַ���
* @param   [in]  dwLen     pchAddr�ĳ���
*
* @return  ��ַ����
*/
/*---------------------------------------------------------------------------*/
MTCBB_API mt::EmMtAddrType mtGetAddrType(const s8 *pchAddr, u32 dwLen);

/*!**********************************************************
* 
* @brief   ������Ƶ�ֱ��ʵõ����
* @param   [in] emRes:     ��Ƶ�ֱ���
* @param   [out] dwWidth:  �õ����
* @param   [out] dwHeight: �õ��߶�
* @return  MT_SUCCESS: �ɹ�
*          MT_FAILED: ʧ��
*************************************************************/
MTCBB_API u32 mtGetVideoWidthHeight(mt::EmMtResolution emRes, u32 &dwWidth, u32 &dwHeight);

/*!**********************************************************
* 
* @brief   ������Ƶ�ֱ��ʵõ����
* @param   [in] emRes:     ��Ƶ�ֱ���
* @param   [in] dwLen:     ��������С
* @param   [out] ����ַ��� ��1280*720
* @return  MT_SUCCESS: �ɹ�
*          MT_FAILED: ʧ��
*************************************************************/
MTCBB_API u32 mtGetVideoWidthHeight(mt::EmMtResolution emRes, s8 *pchStrOut, u32 dwLen);

/*!**********************************************************
* 
* @brief   ���ݿ�ߵõ��ֱ���
* @param   [in]  dwWidth:  ���
* @param   [in]  dwHeight: �߶�
* @param   [out] emRes:    �õ�����Ƶ�ֱ���
* @return  MT_SUCCESS: �ɹ�
*          MT_FAILED: ʧ��
*************************************************************/
MTCBB_API u32 mtGetVideoRes(u32 dwWidth, u32 dwHeight, mt::EmMtResolution &emRes);

/*!**********************************************************
* 
* @brief   ������Ƶ��ʽ��ȡ������
* @param   [in]  emAudioFormat:		��Ƶ��ʽ
* @param   [out] wAudioBitrate:		�õ�����Ƶ����
* @return  MT_SUCCESS: �ɹ�
*          MT_FAILED:  ʧ��
*************************************************************/
MTCBB_API u32 mtGetAudioBitrate(mt::EmAudFormat emAudioFormat, u16 &wAudioBitrate);

/*!**********************************************************
* 
* @brief   ������Ƶ��ʽ��ȡ���غ�����
* @param   [in]  emAudFormat:		��Ƶ��ʽ
*
* @return  �ɹ�:��Ӧ���غ�����
*          ʧ��:MEDIA_TYPE_NULL
*************************************************************/
MTCBB_API u8 mtGetAudioPayloadByFormat( mt::EmAudFormat emAudFormat );

/*!**********************************************************
* 
* @brief   ������Ƶ��ʽ��ȡ���غ�����
* @param   [in]  emFormat:		��Ƶ��ʽ
*
* @return  �ɹ�:��Ӧ���غ�����
*          ʧ��:MEDIA_TYPE_NULL
*************************************************************/
MTCBB_API u8 mtGetVedioPayloadByFormat( mt::EmVidFormat emFormat );

/*!**********************************************************
* 
* @brief   �����غ����ͻ�ȡ��Ƶ��ʽ
* @param   [in]  byMediaType:		�غ�����
*
* @return  �ɹ�:��Ӧ����Ƶ��ʽ
*          ʧ��:emAudEnd
*************************************************************/
MTCBB_API mt::EmAudFormat mtGetAudFormatByPayload( u8 byMediaType );

/*!**********************************************************
* 
* @brief   �����غ����ͻ�ȡ��Ƶ��ʽ
* @param   [in]  byMediaType:		�غ�����
*
* @return  �ɹ�:��Ӧ����Ƶ��ʽ
*          ʧ��:emVEnd
*************************************************************/
MTCBB_API mt::EmVidFormat mtGetVedioFormatByPayload( u8 byPayload );

/*!**********************************************************
* 
* @brief   ������Ƶ��ʽ�õ�vccommon����Ƶ��ʽ����
* @param   [in]  emVidResd:		��Ƶ��ʽ
*
* @return  �ɹ�:��Ӧ����Ƶ��ʽ
*          ʧ��:VIDEO_FORMAT_INVALID
*************************************************************/
MTCBB_API u8 mtMapMtToVcComVidRes( mt::EmMtResolution emVidResd );

/*!**********************************************************
* 
* @brief   ����vccommon����Ƶ��ʽ����õ��ն���Ƶ��ʽ
* @param   [in]  byRes:		vccommon����Ƶ��ʽ
*
* @return  �ɹ�:��Ӧ����Ƶ��ʽ
*          ʧ��:emMtVResEnd
*************************************************************/
MTCBB_API mt::EmMtResolution mtMapVcComToMtVideoRes(u8 byRes);

/*!**********************************************************
* 
* @brief   ����  ����ͷ��������ķ���õ�Э��ջ������ptfz����ö��
* @param   [in]  emDirection:		����ͷ��������ķ���
*
* @return  �ɹ�:��Ӧ����Ƶ��ʽ
*          ʧ��:emMtVResEnd
*************************************************************/
MTCBB_API mt::EmFeccPTFZRequest mtGetFeccPTFZFromMtDirection( mt::EmDirection emDirection );

/*!**********************************************************
* 
* @brief   ����  Э��ջ������ptfz����ö�ٵõ�����ͷ��������ķ���
* @param   [in]  emPTFZ:		Э��ջ������ptfz����ö��
*
* @return  �ɹ�:��Ӧ����Ƶ��ʽ
*          ʧ��:emMtVResEnd
*************************************************************/
MTCBB_API mt::EmDirection  mtGetMtDirectionFromPTFZ( mt::EmFeccPTFZRequest emPTFZ );


/*!**********************************************************
* 
* @brief   ����  ͨ����type ��ȡcode��type
* @param   [in]  emChanType:		ͨ����type
* @note    ת��ֻ�������Ƶ��ת����fecc, ����Ƶ������������
* @return  �ɹ�: ��Ӧ��code��type
*          ʧ��:emMtVResEnd
*************************************************************/
MTCBB_API mt::EmCodecComponent mtGetCodecTypeFromChan( mt::EmMtChanType emChanType );

/*!**********************************************************
* 
* @brief   ����  codec��type ��ȡͨ����type
* @param   [in]  emChanType:		ͨ����type
*
* @return  �ɹ�: ��Ӧ��code��type
*          ʧ��:emChanTypeEnd
*************************************************************/
MTCBB_API mt::EmMtChanType     mtGetChanTypeFromCodec( mt::EmCodecComponent emCodecType );

/*!**********************************************************
* 
* @brief   ����  �ڲ���vidsrc��ö�ٻ�ȡԶҡ�õ��� index
* @param   [in]  emPort:  �ڲ�ö��
*
* @return  �ɹ�: Զҡ�õ��� index
*          ʧ��: INVALID_U32
*************************************************************/
MTCBB_API u32  mtGetFarCtrIdxFromInnerVidSrc( mt::EmMtVideoPort emPort,mt::EmCodecComponent emCodecType, mt::EmCodecComponentIndex emIdx );

/*!**********************************************************
* 
* @brief   ����  Զҡ�õ��� index��ȡ�ڲ���ö��
* @param   [in]  emPort:  �ڲ�ö��
*
* @return  �ɹ�: Զҡ�õ��� index
*          ʧ��: mt::emMtVidInvalid
*************************************************************/
MTCBB_API mt::EmMtVideoPort mtGetInnerVidSrcFromFarCtrlIdx( u32 dwIdx, mt::EmCodecComponent emCodecType, mt::EmCodecComponentIndex emIdx);

/*!**********************************************************
* 
* @brief   ����  code���ͺ�������ȡ ĳһ· �ն��ڲ���ƵԴ��Զңid�Ķ�Ӧ��ϵ�б�
* @param   [in]  emType:  codec ����
*          [in]  emIdx:   ����
           
		   [out] ĳһ·�Ķ�Ӧ��ϵ
* @return  �ɹ�: TRUE 
*          ʧ��: FALSE
*************************************************************/
MTCBB_API BOOL32 mtGetFarCtrlIdGroupBaseCodeTypeAndId( mt::TMTVidSrc2FarCtrlIdGroup &tGroup, mt::EmCodecComponent emType, mt::EmCodecComponentIndex emIdx );

/*!**********************************************************
* 
* @brief   ������windows����Ƕ��ʽ��ȡ��ǰ��֡�ʣ�ֻ���264�� 265
* @param   [in]  emChanType:   ͨ������
           [in]  emLabel:      ˫������
		   
* @return  ���֡�� 
*         
*************************************************************/
MTCBB_API u32 mtGetMaxFpsBasePlatForm( mt::EmMtChanType emChanType, mt::EmMtVidLabel emLabel );


/*!**********************************************************
* 
* @brief   ����chan ͨ�����ͻ�ȡport string����
* @param   [in]  emChanType:   ͨ������
           [in]  emLabel:      ˫������
		   
* @return  ���֡�� 
*         
*************************************************************/
MTCBB_API u32  mtGetPortStringFromChanType( mt::EmMtChanType emChanType, std::string &strPort);


/*!**********************************************************
* 
* @brief   ����versionidֵ�ж�,�Զ��ǲ���5.0�ն�
* @param   [in]  emChanType:   ͨ������
           [in]  emLabel:      ˫������
		   
* @return  ���֡�� 
*         
*************************************************************/
MTCBB_API BOOL32  JudgeMtb5p0BaseVersionId( s8 *pchVersionId );


/*!**********************************************************
* 
* @brief   ����versionidֵ�ж�,�Զ��ǲ���5.0ƽ̨
* @param   [in]  emChanType:   ͨ������
           [in]  emLabel:      ˫������
		   
* @return  ���֡�� 
*         
*************************************************************/
MTCBB_API BOOL32  JudgeMcub5p0BaseVersionId( s8 *pchVersionId ); 

/*!**********************************************************
* 
* @brief   ��wBeginPort �� wEndPort���ҿ��õ�323�����˿�
* @param   [in]  emChanType:   ͨ������
           [in]  emLabel:      ˫������
		   
* @return  ���֡�� 
*         
*************************************************************/
MTCBB_API u16    MtGetH323CallingPortFromRange( u16 wBeginPort, u16 wEndPort ) ;



typedef void (*MT_PAUDIOPCMCALLBACK)(u8 *pBuf, s32 nSize, u32 dwSampleRate, u32 dwBitWidth, u32 dwChannel, u32 dwContext);

typedef void (*MT_PVIDEOI420CALLBACK)(u8* pData, s32 nData, s16 nWidth, s16 nHeight, u32 dwContext);


/*!**********************************************************
* 
* @brief   ������Ƶ������֡�ص�����
* @param   [in]  pAudioCallBack:   �ص�����ָ��
* @return   
*         
*************************************************************/
MTCBB_API void mtSetAudioDecPCMCallBack(const MT_PAUDIOPCMCALLBACK  pAudioCallBack);

/*!**********************************************************
* 
* @brief   ��ȡ��Ƶ������֡�ص�����
* @param  
* @return    �� �ص�����ָ��
*         
*************************************************************/
MTCBB_API MT_PAUDIOPCMCALLBACK mtGetAudioDecPCMCallBack();

/*!**********************************************************
* 
* @brief   ������Ƶ������֡�ص�����
* @param   [in]  pVideoI420CallBack:   �ص�����ָ��
* @return   
*         
*************************************************************/
MTCBB_API void mtSetVideoDecI420CallBack(const MT_PVIDEOI420CALLBACK  pVideoI420CallBack);


/*!**********************************************************
* 
* @brief   ��ȡ��Ƶ������֡�ص�����
* @param   
* @return   �� �ص�����ָ��
*         
*************************************************************/
MTCBB_API MT_PVIDEOI420CALLBACK mtGetVideoDecI420CallBack();

/*---------------------------------------------------------------------------*/
/**
* @brief   ��ȡ�ļ�·���е��ļ���
* @param   [in]  pchFilePath     �ļ�·�������� �ļ�·��ǰ׺+�ļ���
* @param   [in]  dwPathLen       �ļ�·������
* @param   [out] pchOutFileName  �ļ���
*
* @return  TRUE:�ɹ� 
           FALSE: ʧ��
*/
/*---------------------------------------------------------------------------*/
MTCBB_API BOOL32 mtGetFileName(const s8 *pchFilePath, u32 dwPathLen, s8 *pchOutFileName);

/*---------------------------------------------------------------------------*/
/**
* @brief   ��ȡ�ļ�·���е�·��ǰ׺
* @param   [in]  pchFilePath       �ļ�·�������� �ļ�·��ǰ׺+�ļ���
* @param   [in]  dwPathLen         �ļ�·������
* @param   [out] pchOutPathPrefix  �ļ�·��ǰ׺
*
* @return  TRUE:�ɹ� 
           FALSE: ʧ��
*/
/*---------------------------------------------------------------------------*/
MTCBB_API BOOL32 mtGetFilePathPrefix(const s8 *pchFilePath, u32 dwPathLen, s8 *pchOutPathPrefix);

/*---------------------------------------------------------------------------*/
/**
* @brief �Ƿ�Ҫ����������Ʒ�Ǳ�������ն�  
*
* @param	
* @param		
*
* @return	TRUE: ��  FALSE:��
* @note   
*/
/*---------------------------------------------------------------------------*/
MTCBB_API BOOL32 IsSendAgentInfoMt();


MTCBB_API BOOL32 IsSky100Mt();

#endif //_MT_DEFAULTCONFIG_H_
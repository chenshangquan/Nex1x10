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
 * @brief ��ʼ��Ĭ������
 *
 * @param	[in] ��
 *
 * @return	��
 * @note    
 */
/*---------------------------------------------------------------------------*/
NVCBB_API void nvInitDefaultCfg();

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
NVCBB_API BOOL32 nvGetDefaultCfg(std::string strKey, google::protobuf::Message *pvData);

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
NVCBB_API BOOL32 nvGetDefaultCfg(std::string strKey, google::protobuf::Message **pvData);

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
NVCBB_API BOOL32 nvGetDirPath(nv::EmNvPathType emPathType, s8 *pchOutBuf, u32 dwBufSize);

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
NVCBB_API BOOL32 nvGetFilePath(nv::EmNvFile emFileType, s8 *pchOutBuf, u32 dwBufSize);

/**----------------------------------------------------------------------
	* InstallSystemPath
	* 
	* @brief    ϵͳʱ���ã�Ԥ�ȴ�������Ҫ��Ŀ¼
	* 
	* @param	
	* @return	BOOL32 TRUE:�ɹ����� FALSE:����ʧ��
	------------------------------------------------------------------------*/
NVCBB_API BOOL32 InstallSystemPath();

/*---------------------------------------------------------------------------*/
/**
* @brief   ����ϵͳ·��ǰ׺
* @param   [in]  pszPathPrefix    ·��ǰ׺��utf8����
*
* @return  ��
*/
/*---------------------------------------------------------------------------*/
NVCBB_API void nvSetSysWorkPathPrefix(const s8* pszPathPrefix);

/*---------------------------------------------------------------------------*/
/**
* @brief   ��ȡϵͳ·��ǰ׺
* @param   [in]  pchOutBuf    ·��ǰ׺��utf8����
*
* @return  ��
*/
/*---------------------------------------------------------------------------*/
NVCBB_API BOOL32 nvGetSysWorkPathPrefix(s8 *pchOutBuf, u32 dwBufSize);

/**----------------------------------------------------------------------
	* NvStrToMsgSession
	* 
	* @brief    str�ĸ�ʽ��dwAppInstID*dwNodeID��u32ת�����ַ������ʮ���ַ����б�ʾ�������ַ�����С���Ϊ10+1+10=21
	* 
	* @param	[in] str Ҫת����str�ַ���
	* @param	[out] dwNodeID strҪ����������nodeid
	* @param	[out] dwInstAppID Ҫ����������instappid
	* @return	BOOL32 TRUE:�ɹ����� FALSE:����ʧ��
	------------------------------------------------------------------------*/
NVCBB_API BOOL32 NvStrToMsgSession( const std::string &str, u32 &dwNodeID, u32 &dwInstAppID );

/**----------------------------------------------------------------------
	* NvMsgSessionToStr
	* 
	* @brief    ��appinstid�Լ�nodeidת����str�ĸ�ʽ��dwAppInstID*dwNodeID��u32ת�����ַ������ʮ���ַ����б�ʾ�������ַ�����С���Ϊ10+1+10=21
	* 
	* @param	[in] dwNodeID Ҫ�ϳ�str��nodeid����
	* @param	[in] dwInstAppID Ҫ�ϳ�str��instappid����
	* @param	[out] str Ҫת����str���ַ������
	* @return	BOOL32 TRUE:�ɹ����� FALSE:����ʧ��
	------------------------------------------------------------------------*/
NVCBB_API BOOL32 NvMsgSessionToStr( u32 dwNodeID, u32 dwInstAppID, std::string &str );

typedef void (*NV_PAUDIOPCMCALLBACK)(u8 *pBuf, s32 nSize, u32 dwSampleRate, u32 dwBitWidth, u32 dwChannel, u32 dwContext);

typedef void (*NV_PVIDEOI420CALLBACK)(u8* pData, s32 nData, s16 nWidth, s16 nHeight, u32 dwContext);


/*!**********************************************************
* 
* @brief   ������Ƶ������֡�ص�����
* @param   [in]  pAudioCallBack:   �ص�����ָ��
* @return   
*         
*************************************************************/
NVCBB_API void nvSetAudioDecPCMCallBack(const NV_PAUDIOPCMCALLBACK  pAudioCallBack);

/*!**********************************************************
* 
* @brief   ��ȡ��Ƶ������֡�ص�����
* @param  
* @return    �� �ص�����ָ��
*         
*************************************************************/
NVCBB_API NV_PAUDIOPCMCALLBACK nvGetAudioDecPCMCallBack();

/*!**********************************************************
* 
* @brief   ������Ƶ������֡�ص�����
* @param   [in]  pVideoI420CallBack:   �ص�����ָ��
* @return   
*         
*************************************************************/
NVCBB_API void nvSetVideoDecI420CallBack(const NV_PVIDEOI420CALLBACK  pVideoI420CallBack);


/*!**********************************************************
* 
* @brief   ��ȡ��Ƶ������֡�ص�����
* @param   
* @return   �� �ص�����ָ��
*         
*************************************************************/
NVCBB_API NV_PVIDEOI420CALLBACK nvGetVideoDecI420CallBack();

NVCBB_API void nvMakeHandleString( const s8 *pchModuleInfo, u32 dwHandle1, u32 dwHandle2, std::string &strOutString );

#endif //_NV_DEFAULTCONFIG_H_
#if 0 //attention �˲��ֽӿ��Ѿ�Ų��mtcbbcommonģ����

/*---------------------------------------------------------------------------*/
/*
 * @file    $Id$
 * @brief   ����Ƶ��ع��ú���
 * @author  �Ĵ���
 * @date    $Date$
 * @version  $Revision$
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * 
 */
/*---------------------------------------------------------------------------*/

#ifndef _MTUTILS_MEDIA_H
#define _MTUTILS_MEDIA_H

#include "kdvtype.h"
#include "enum.pb.h"
#include "mtmacro.h"

namespace MTUTILS
{

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
MTCBB_API u8 mtMapMtVidFormatToVcCommonFormat( mt::EmMtResolution emVidResd );


/*!**********************************************************
* 
* @brief   ����vccommon����Ƶ��ʽ����õ��ն���Ƶ��ʽ
* @param   [in]  byRes:		vccommon����Ƶ��ʽ
*
* @return  �ɹ�:��Ӧ����Ƶ��ʽ
*          ʧ��:emMtVResEnd
*************************************************************/
MTCBB_API mt::EmMtResolution mtMapVcComToMtVideoRes(u8 byRes);

}


#endif	//_MTUTILS_MEDIA_H

#endif // if 0
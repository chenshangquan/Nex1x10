#if 0 //attention �˲��ֽӿ��Ѿ�Ų��nvcbbcommonģ����

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

#ifndef _NVUTILS_MEDIA_H
#define _NVUTILS_MEDIA_H

#include "kdvtype.h"
#include "nvenum.pb.h"
#include "nvmacro.h"

namespace NVUTILS
{

/*!**********************************************************
* 
* @brief   ������Ƶ�ֱ��ʵõ����
* @param   [in] emRes:     ��Ƶ�ֱ���
* @param   [out] dwWidth:  �õ����
* @param   [out] dwHeight: �õ��߶�
* @return  NV_SUCCESS: �ɹ�
*          NV_FAILED: ʧ��
*************************************************************/
NVCBB_API u32 nvGetVideoWidthHeight(nv::EmNvResolution emRes, u32 &dwWidth, u32 &dwHeight);


/*!**********************************************************
* 
* @brief   ������Ƶ�ֱ��ʵõ����
* @param   [in] emRes:     ��Ƶ�ֱ���
* @param   [in] dwLen:     ��������С
* @param   [out] ����ַ��� ��1280*720
* @return  NV_SUCCESS: �ɹ�
*          NV_FAILED: ʧ��
*************************************************************/
NVCBB_API u32 nvGetVideoWidthHeight(nv::EmNvResolution emRes, s8 *pchStrOut, u32 dwLen);


/*!**********************************************************
* 
* @brief   ���ݿ�ߵõ��ֱ���
* @param   [in]  dwWidth:  ���
* @param   [in]  dwHeight: �߶�
* @param   [out] emRes:    �õ�����Ƶ�ֱ���
* @return  NV_SUCCESS: �ɹ�
*          NV_FAILED: ʧ��
*************************************************************/
NVCBB_API u32 nvGetVideoRes(u32 dwWidth, u32 dwHeight, nv::EmNvResolution &emRes);


/*!**********************************************************
* 
* @brief   ������Ƶ��ʽ��ȡ������
* @param   [in]  emAudioFormat:		��Ƶ��ʽ
* @param   [out] wAudioBitrate:		�õ�����Ƶ����
* @return  NV_SUCCESS: �ɹ�
*          NV_FAILED:  ʧ��
*************************************************************/
NVCBB_API u32 nvGetAudioBitrate(nv::EmAudFormat emAudioFormat, u16 &wAudioBitrate);



/*!**********************************************************
* 
* @brief   ������Ƶ��ʽ��ȡ���غ�����
* @param   [in]  emAudFormat:		��Ƶ��ʽ
*
* @return  �ɹ�:��Ӧ���غ�����
*          ʧ��:MEDIA_TYPE_NULL
*************************************************************/
NVCBB_API u8 nvGetAudioPayloadByFormat( nv::EmAudFormat emAudFormat );



/*!**********************************************************
* 
* @brief   ������Ƶ��ʽ��ȡ���غ�����
* @param   [in]  emFormat:		��Ƶ��ʽ
*
* @return  �ɹ�:��Ӧ���غ�����
*          ʧ��:MEDIA_TYPE_NULL
*************************************************************/
NVCBB_API u8 nvGetVedioPayloadByFormat( nv::EmVidFormat emFormat );



/*!**********************************************************
* 
* @brief   �����غ����ͻ�ȡ��Ƶ��ʽ
* @param   [in]  byMediaType:		�غ�����
*
* @return  �ɹ�:��Ӧ����Ƶ��ʽ
*          ʧ��:emAudEnd
*************************************************************/
NVCBB_API nv::EmAudFormat nvGetAudFormatByPayload( u8 byMediaType );



/*!**********************************************************
* 
* @brief   �����غ����ͻ�ȡ��Ƶ��ʽ
* @param   [in]  byMediaType:		�غ�����
*
* @return  �ɹ�:��Ӧ����Ƶ��ʽ
*          ʧ��:emVEnd
*************************************************************/
NVCBB_API nv::EmVidFormat nvGetVedioFormatByPayload( u8 byPayload );


/*!**********************************************************
* 
* @brief   ������Ƶ��ʽ�õ�vccommon����Ƶ��ʽ����
* @param   [in]  emVidResd:		��Ƶ��ʽ
*
* @return  �ɹ�:��Ӧ����Ƶ��ʽ
*          ʧ��:VIDEO_FORMAT_INVALID
*************************************************************/
NVCBB_API u8 nvMapNvVidFormatToVcCommonFormat( nv::EmNvResolution emVidResd );


/*!**********************************************************
* 
* @brief   ����vccommon����Ƶ��ʽ����õ��ն���Ƶ��ʽ
* @param   [in]  byRes:		vccommon����Ƶ��ʽ
*
* @return  �ɹ�:��Ӧ����Ƶ��ʽ
*          ʧ��:emNvVResEnd
*************************************************************/
NVCBB_API nv::EmNvResolution nvMapVcComToNvVideoRes(u8 byRes);

}


#endif	//_NVUTILS_MEDIA_H

#endif // if 0
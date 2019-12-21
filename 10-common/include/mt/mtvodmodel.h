/**===========================================================================
 * @file    mtvodmodel.h
 * @brief   
 1����¼����restapiʵ�֣�
 2����ȡ�㲥�б���restapiʵ�֣�
 3��ע������restapiʵ�֣�


 4�����ŵ㲥�б�����ƵԴ��
 5����ͣ�㲥�б�����ƵԴ��
 6���ָ��㲥�б��е���ƵԴ��
 7���ı䲥���ٶȣ�
 8���ı�㲥���ȣ�
 9��ֹͣ���ţ�
 10����֮���Ž��ȣ�����֧�֣�vod���ɽ������ģ����rtspӦ��֧�֣�
 11����ָ����ƵԴ�������������ʱֻ�ܽ��в��ź�ֹͣ������

 * @author  longwei
 * @date    
 * @version  
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note
============================================================================*/
#ifndef _MTVODMODEL_H_
#define _MTVODMODEL_H_
#include "kdvtype.h"
#include "mtstruct.h"

extern "C"
{
/**----------------------------------------------------------------------
* MtVodStart
* 
* @brief   �ն˵㲥ģ�������ӿ�
* 
* @param   [in] tMdlStartparam ��������
* @return  BOOL32 TRUE:�ɹ������� FALSE:����ʧ��
* @see     MtVodStop()
------------------------------------------------------------------------*/
MTCBB_API BOOL32 MtVodStart(TMdlStartParam &tMdlStartparam);

/**----------------------------------------------------------------------
* MtVodStop
* 
* @brief   �㲥ģ���˳��ӿ�
* 
* @param   void
* @return  BOOL32 TRUE:�ɹ��˳��� FALSE:�˳�ʧ��
* @see     MtVodStart()
------------------------------------------------------------------------*/
MTCBB_API BOOL32 MtVodStop();

};


#endif \\ _MTVODMODEL_H_
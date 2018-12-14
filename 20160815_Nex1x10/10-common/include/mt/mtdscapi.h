#ifndef _MTDSCAPI_H_
#define _MTDSCAPI_H_
#include "mtdsc.h"

/*********************************************************/
/*******************��չ�ӿڣ�data�ı�Ϊprotomsg��************/
/*********************************************************/
#include <google/protobuf/message.h>

/*!**********************************************************
*
* @brief   ��ȡ���ݹ����е���������
* @param   [in]   emKey    ������������
* @param   [out]  ptBufOut ���ص���������
*
* @return  DSE_OK:�ɹ�  DSE_ERROR:ʧ��
*          
*************************************************************/
MTCBB_API u32 mtDscGetData(KEY emKey, google::protobuf::Message *ptBufOut);


/*!**********************************************************
*
* @brief   �������ݹ����е���������
* @param   [in]  emKey  ������������
* @param   [in]  ptData Ҫ�洢����������
*
* @return  DSE_OK:�ɹ�  DSE_ERROR:ʧ��
*          
*************************************************************/
MTCBB_API u32 mtDscSetData(KEY emKey, google::protobuf::Message *ptData);

#endif // _MTDSCAPI_H_
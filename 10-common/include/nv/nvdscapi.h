#ifndef _NVDSCAPI_H_
#define _NVDSCAPI_H_
#include "nvdsc.h"

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
NVCBB_API u32 nvDscGetData(KEY emKey, google::protobuf::Message *ptBufOut);


/*!**********************************************************
*
* @brief   �������ݹ����е���������
* @param   [in]  emKey  ������������
* @param   [in]  ptData Ҫ�洢����������
*
* @return  DSE_OK:�ɹ�  DSE_ERROR:ʧ��
*          
*************************************************************/
NVCBB_API u32 nvDscSetData(KEY emKey, google::protobuf::Message *ptData);

#endif // _NVDSCAPI_H_
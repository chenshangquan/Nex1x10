/**===========================================================================
 * 
 * @brief   �˿����rpc�ӿ�ͷ�ļ�
 * @author  qudaifeng
 * @date    
 * @version  
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note
============================================================================*/
#ifndef _NVPORT_RPC_API_H_
#define _NVPORT_RPC_API_H_
#include "kdvtype.h"
#include "nvstruct.pb.h"
#include "nvmacro.h"
#include "nvport.pb.h"

/*=============================================================================================
������   : RPC_GetPort
����     : ����strKey��ȡ��صĶ˿�
����     : strKey [IN] �˿ڵ�key��������portkey.h��
����     : tPort  [OUT] key��Ӧ�Ķ˿�
����ֵ   : BOOL32 TRUE�ɹ� FALSEʧ��
=============================================================================================*/
NVCBB_API BOOL32 RPC_GetPort(std::string strKey, nv::port::TPort &tPort);

#endif  //_NVPORT_RPC_API_H_
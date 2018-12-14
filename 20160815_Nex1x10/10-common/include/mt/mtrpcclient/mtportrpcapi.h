/**===========================================================================
 * 
 * @brief   �˿����rpc�ӿ�ͷ�ļ�
 * @author  qudaifeng
 * @date    
 * @version  
 * (c)1998-2014 Suzhou Keda Technology Co.,Ltd. All rights reserved
 * @note
============================================================================*/
#ifndef _MTPORT_RPC_API_H_
#define _MTPORT_RPC_API_H_
#include "kdvtype.h"
#include "struct.pb.h"
#include "mtmacro.h"
#include "port.pb.h"

/*=============================================================================================
������   : RPC_GetPort
����     : ����strKey��ȡ��صĶ˿�
����     : strKey [IN] �˿ڵ�key��������portkey.h��
����     : tPort  [OUT] key��Ӧ�Ķ˿�
����ֵ   : BOOL32 TRUE�ɹ� FALSEʧ��
=============================================================================================*/
MTCBB_API BOOL32 RPC_GetPort(std::string strKey, mt::port::TPort &tPort);

#endif  //_MTPORT_RPC_API_H_
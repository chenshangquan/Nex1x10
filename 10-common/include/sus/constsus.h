
/*****************************************************************************
   ģ����      : 
   �ļ���      : constsus.h
   ����ļ�    : 
   �ļ�ʵ�ֹ���: SUS֮����Ҫ�õ���һЩ����
   ����        : 
   �汾        : V1.0  Copyright(C) 2006-2007 KDC, All rights reserved.
-----------------------------------------------------------------------------
   �޸ļ�¼:
   ��  ��      �汾        �޸���      �޸�����
   2014/04/21  1.0				       ����
******************************************************************************/


#ifndef _CONST_SUS_COMMON_H_
#define _CONST_SUS_COMMON_H_

// sus�����˿�
#define SUSSRV_LISTEN_PORT              (u16)63000  
#define SUSMGR_LISTEN_PORT              (u16)63001  

#define MAXNUM_DB_CONNECT               (u32)6  //���ݿ�������

//����汾��������󳤶�
#define MAXLEN_SUS_SOFTVER			    (u32)(64)
#define MAXLEN_SUS_RELEASE_NOTES        (u32)(1024)
#define MAXLEN_SUS_FILENAME			    (u32)(256)
#define MAXLEN_SUS_E164LIST             (u32)(16*30)
#define MAXLEN_SUS_MOIDLIST             (u32)(40*30)

#define MAXLEN_SUS_IP_ADDR			    (u16)(32)
#define MAXLEN_SUS_DEV_NAME			    (u32)(64)
#define MAXLEN_SUS_E164NO			    (u32)(13)
#define MAXLEN_SUS_MODULE_NAME			(u32)(128)


#define MAXNUM_SUS_DEVVER				(u32)5
#define MAXNUM_SUS_DEVLOG				(u32)20
#define MAXNUM_SUS_MOID					(u16)50


#endif // _CONST_SUS_COMMON_H_
// END FILE




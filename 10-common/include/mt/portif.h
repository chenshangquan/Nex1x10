/*=============================================================================================
ģ����   : mtport
�ļ���   : portif.h
����     : mtportģ�����Ľӿ�ͷ�ļ�
����     : ruiyigen
��Ȩ     : <Copyright(C) 2003-2015 Suzhou Keda Technology Co., Ltd. All rights reserved.>
=============================================================================================*/
#ifndef _PORTIF_H_
#define _PORTIF_H_
#include <string>
#include "port.pb.h"
#include "kdvtype.h"
#include "mtmacro.h"

namespace PORT
{
    /*=============================================================================================
    ������   : Init
    ����     : ��ʼ��mtport
    ����     : bRandum       [IN] TRUE ����ͬһ��key��GetPort�õ��˿�ֵ��� FALSE�õ��Ķ˿�ֵ�̶�
    ����     : wTcpStartPort [IN] tcp����ʼ�˿�
    ����     : wUdpStartPort [IN] udp����ʼ�˿�
    ����ֵ   : BOOL32 TRUE�ɹ� FALSEʧ��
    =============================================================================================*/
	MTCBB_API BOOL32 Init(BOOL32 bRandum, u16 wTcpStartPort, u16 wUdpStartPort);

    /*=============================================================================================
    ������   : GetPort
    ����     : ��ȡstrKey��Ӧ�Ķ˿�
    ����     : strKey [IN] �˿ڵ�key��������portkey.h��
    ����     : tPort  [OUT] key��Ӧ�Ķ˿�
    ����ֵ   : BOOL32 TRUE�ɹ� FALSEʧ��
    =============================================================================================*/
	MTCBB_API BOOL32 GetPort(std::string strKey, mt::port::TPort &tPort);
}


#endif // _PORTIF_H_
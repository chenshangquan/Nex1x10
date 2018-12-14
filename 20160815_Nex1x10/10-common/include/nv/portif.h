/*=============================================================================================
ģ����   : nvport
�ļ���   : portif.h
����     : nvportģ�����Ľӿ�ͷ�ļ�
����     : ruiyigen
��Ȩ     : <Copyright(C) 2003-2015 Suzhou Keda Technology Co., Ltd. All rights reserved.>
=============================================================================================*/
#ifndef _PORTIF_H_
#define _PORTIF_H_
#include <string>
#include "nvport.pb.h"
#include "kdvtype.h"
#include "nvmacro.h"

namespace PORT
{
    /*=============================================================================================
    ������   : Init
    ����     : ��ʼ��nvport
    ����     : bRandum       [IN] TRUE ����ͬһ��key��GetPort�õ��˿�ֵ��� FALSE�õ��Ķ˿�ֵ�̶�
    ����     : wTcpStartPort [IN] tcp����ʼ�˿�
    ����     : wUdpStartPort [IN] udp����ʼ�˿�
    ����ֵ   : BOOL32 TRUE�ɹ� FALSEʧ��
    =============================================================================================*/
	NVCBB_API BOOL32 Init(BOOL32 bRandum, u16 wTcpStartPort, u16 wUdpStartPort);

    /*=============================================================================================
    ������   : GetPort
    ����     : ��ȡstrKey��Ӧ�Ķ˿�
    ����     : strKey [IN] �˿ڵ�key��������portkey.h��
    ����     : tPort  [OUT] key��Ӧ�Ķ˿�
    ����ֵ   : BOOL32 TRUE�ɹ� FALSEʧ��
    =============================================================================================*/
	NVCBB_API BOOL32 GetPort(std::string strKey, nv::port::TPort &tPort);
}


#endif // _PORTIF_H_
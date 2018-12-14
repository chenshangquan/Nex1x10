/*=============================================================================================
ģ����   : nvport
�ļ���   : portkey.h
����     : ����˿ڵ�key
����     : ruiyigen
��Ȩ     : <Copyright(C) 2003-2015 Suzhou Keda Technology Co., Ltd. All rights reserved.>
=============================================================================================*/
#ifndef _PORTKEY_H_
#define _PORTKEY_H_
#include <string>
#ifndef BUILD_PORT_MAP
#define ADD_PORT(strKey, wTcpCount, wUdpCount) const std::string strKey = #strKey
#endif
/*  ��������������� �����õ��Ķ˿�    */
ADD_PORT(PORTS_QuickShareRecvAud, 0, 2);
ADD_PORT(PORTS_QuickShareRecvVid, 0, 2);

/*nvmp ý�� �����õ��Ķ˿�,����Ķ˿� ��Ҫ������nvmp�ڲ�ת���õ��Ķ˿ڣ�
  ��ʱ�ֻ���û�õ�forward
*/
ADD_PORT(PORTS_QuickShareDecAud_Forward, 0, 4);
ADD_PORT(PORTS_QuickShareDecVid_Forward, 0, 4);




#ifndef BUILD_PORT_MAP
#undef ADD_PORT
#endif

#endif // _PORTKEY_H_
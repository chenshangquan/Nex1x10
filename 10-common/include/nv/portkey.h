/*=============================================================================================
模块名   : nvport
文件名   : portkey.h
功能     : 定义端口的key
作者     : ruiyigen
版权     : <Copyright(C) 2003-2015 Suzhou Keda Technology Co., Ltd. All rights reserved.>
=============================================================================================*/
#ifndef _PORTKEY_H_
#define _PORTKEY_H_
#include <string>
#ifndef BUILD_PORT_MAP
#define ADD_PORT(strKey, wTcpCount, wUdpCount) const std::string strKey = #strKey
#endif
/*  会议信令交互过程中 申请用到的端口    */
ADD_PORT(PORTS_QuickShareRecvAud, 0, 2);
ADD_PORT(PORTS_QuickShareRecvVid, 0, 2);

/*nvmp 媒控 申请用到的端口,下面的端口 主要是用在nvmp内部转发用到的端口，
  暂时手机端没用到forward
*/
ADD_PORT(PORTS_QuickShareDecAud_Forward, 0, 4);
ADD_PORT(PORTS_QuickShareDecVid_Forward, 0, 4);




#ifndef BUILD_PORT_MAP
#undef ADD_PORT
#endif

#endif // _PORTKEY_H_
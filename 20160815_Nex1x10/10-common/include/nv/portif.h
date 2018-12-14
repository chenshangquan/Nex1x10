/*=============================================================================================
模块名   : nvport
文件名   : portif.h
功能     : nvport模块对外的接口头文件
作者     : ruiyigen
版权     : <Copyright(C) 2003-2015 Suzhou Keda Technology Co., Ltd. All rights reserved.>
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
    函数名   : Init
    功能     : 初始化nvport
    参数     : bRandum       [IN] TRUE 对于同一个key，GetPort得到端口值随机 FALSE得到的端口值固定
    参数     : wTcpStartPort [IN] tcp的起始端口
    参数     : wUdpStartPort [IN] udp的起始端口
    返回值   : BOOL32 TRUE成功 FALSE失败
    =============================================================================================*/
	NVCBB_API BOOL32 Init(BOOL32 bRandum, u16 wTcpStartPort, u16 wUdpStartPort);

    /*=============================================================================================
    函数名   : GetPort
    功能     : 获取strKey对应的端口
    参数     : strKey [IN] 端口的key，定义在portkey.h中
    参数     : tPort  [OUT] key对应的端口
    返回值   : BOOL32 TRUE成功 FALSE失败
    =============================================================================================*/
	NVCBB_API BOOL32 GetPort(std::string strKey, nv::port::TPort &tPort);
}


#endif // _PORTIF_H_